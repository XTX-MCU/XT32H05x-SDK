/**
  ******************************************************************************
  * @file    leddriver_FJ5161BH.c
  * @author  Software Team
  * @brief   
  *          
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "leddriver_FJ5161BH.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup LEDDRIVER_FJ5161BH
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
/** @defgroup LEDDRIVER_FJ5161BH_Private_Defines Private Defines
  * @{
  */ 
#define COMMON_MAX                        (8)    /*Board XB003123 have total 8 COMMON, COMMON_MAX<= LED_COM_MAX_NUM*/
#define SEGMENT_MAX                       (9)    /*LED Segment FJ5161BH have 1 com + total 8 segments, in this example, scan matrax need 9 sengments*/

#define SCREEN_BUFF_WSIZE                 (128)  /*128 Words*/
#define DEMO_EXAMPLE_BRIGHT               (120)  /*ranges 0 to 255 */

#define ONOFF_1FRAME_DATALEN_DEFAULT      (4)    /*This is a fixed value,Bright mode max is 5 words, OnOff mode is 4 words max*/
#define BRT_COMF_WDATALEN_DEFAULT         (5)    /*This is a fixed value,Bright mode max is 5 words, OnOff mode is 4 words max*/

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/


/* External variables --------------------------------------------------------*/
/** @addtogroup IT_External_Variables
  * @{
  */
extern LED_HandleTypeDef hled1;
/**
  * @}
  */
	
/** @addtogroup LEDDriver_FJ5161BH_Private_Variables
  * @{
  */
/* Private Variables ------------------------------------------------------------*/
static uint32_t aScrnBuf[SCREEN_BUFF_WSIZE]; 
static uint32_t u4Scrn_FrameWDataLen = BRT_COMF_WDATALEN_DEFAULT; 
static uint32_t u4Scrn_FrameTotal = 2; 
static uint8_t u1Scrn_UpdateFrameIdx = 0; 
static uint8_t u1Scrn_CurrFrameIdx = 0;  /*Display buffer area index*/
static uint8_t u1Drv_CurrFrameIdx = 0;   /*Display buffer area index*/
static uint8_t u1BuffReflashing_flag = FALSE;

/** 
  * @brief mapping segment to 7-segment digit per common
  * each number.
  */
static const uint16_t aSegCom_patternlib[COMMON_MAX] = 
{
  //seg8-7-6-5-4-3-2-1-0
  0b0111111110,       /* Com0 */
  0b0111111101,       /* Com1 */
  0b0111111011,       /* Com2 */
  0b0111110111,       /* Com3 */
  0b0111101111,       /* Com4 */
  0b0111011111,       /* Com5 */
  0b0110111111,       /* Com6 */
  0b0101111111,       /* Com7 */
};

/** 
  * @brief aCharacterCode_lib indicate which segments must be illuminated to display
  * each number.
  */
static const uint8_t aSegMap_CodeFontlib[] = {
  //ABCDEFGP  Segments 7-segment map:
  0b11111100, /* 0*/  // 30--'0'     AAA
  0b01100000, /* 1*/  // 31--'1'    F   B
  0b11011010, /* 2*/  // 32--'2'    F   B
  0b11110010, /* 3*/  // 33--'3'     GGG
  0b01100110, /* 4*/  // 34--'4'    E   C
  0b10110110, /* 5*/  // 35--'5'    E   C
  0b10111110, /* 6*/  // 36--'6'     DDD     P
  0b11100000, /* 7*/  // 37--'7' 
  0b11111110, /* 8*/  // 38--'8' 
  0b11110110, /* 9*/  // 39--'9' 
  0b11101110, /*10*/  // 65--'A' 
  0b00111110, /*11*/  // 66--'b' 
  0b10011100, /*12*/  // 67--'C' 
  0b01111010, /*13*/  // 68--'d' 
  0b10011110, /*14*/  // 69--'E' 
  0b10001110, /*15*/  // 70--'F' 
  0b10111100, /*16*/  // 71--'G' 
  0b01101110, /*17*/  // 72--'H' 
  0b00001100, /*18*/  // 73--'I' 
  0b01110000, /*19*/  // 74--'J' 
  0b01101110, /*20*/  // 75--'K' Same as 'H'
  0b00011100, /*21*/  // 76--'L' 
  0b00000000, /*22*/  // 77--'M' NO DISPLAY
  0b00101010, /*23*/  // 78--'n' 
  0b11111100, /*24*/  // 79--'O' 
  0b11001110, /*25*/  // 80--'P' 
  0b11100110, /*26*/  // 81--'q' 
  0b00001010, /*27*/  // 82--'r' 
  0b10110110, /*28*/  // 83--'S' 
  0b00011110, /*29*/  // 84--'t' 
  0b01111100, /*30*/  // 85--'U' 
  0b01111100, /*31*/  // 86--'V' Same as 'U'
  0b00000000, /*32*/  // 87--'W' NO DISPLAY
  0b01101110, /*33*/  // 88--'X' Same as 'H'
  0b01110110, /*34*/  // 89--'y' 
  0b11011010, /*35*/  // 90--'Z' Same as '2'
  0b00000000, /*36*/  // 32--' ' BLANK
  0b00000010, /*37*/  // 45--'-' DASH
  0b00000001, /*38*/  // 46--'.' PERIOD
  0b11000110, /*39*/  // 42--'*' DEGREE ..
  0b10000000, /*40*/  // 94--'^' RS		
  0b00010000, /*41*/  // 95--'_' UNDERSCORE
};


/**
  * @}
  */


/** @addtogroup LEDDriver_FJ5161BH_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static uint32_t XTMW_GetFontIdx(uint8_t Ch);
static void XTMW_ScrnAllFrames_Update(uint32_t *buff);
static void XTMW_Scrn_DrawNewFrame(void);
static void XTMW_WriteBuff(LED_ComTypeDef Comid, uint32_t Seg, uint32_t Data);
static void XTMW_WriteScreen(LED_ComTypeDef Comid, uint32_t Seg, uint32_t Data);
static void XTMW_DrawTextDirect(LED_ComTypeDef Comid, uint8_t Ch, uint32_t Bright, uint32_t Mode);
static void XTMW_DrawText(uint8_t Comid, uint8_t Ch, uint32_t Bright, uint32_t Mode);
/* Private user code ---------------------------------------------------------*/

/**
  * @brief  Get 7-segment display pattern.
  * @param  Ch chacater
  * @retval uint32_t display pattern
  */
static uint32_t XTMW_GetFontIdx(uint8_t Ch)
{
  uint32_t res = 0;

  if((Ch >= '0') && (Ch<='9'))
  {
    res = Ch - '0';
  }
  else if((Ch >= 'A') && (Ch<='Z'))
  {
    res = Ch - 'A' + 10;
  }
  else if((Ch >= 'a') && (Ch<='z'))
  {
    res = Ch - 'a' + 10;
  }
  else if(Ch == '-')
  {
    res = 37;
  }
  else if(Ch == '.')
  {
    res = 38;
  }
  else if(Ch == '*')
  {
    res = 39;
  }
	else if(Ch == '^')
  {
    res = 40;
  }
  else if(Ch == '_')
  {
    res = 41;
  }  
	else //if(Ch == ' ')
  {
    res = 36;
  }

  return res;
}


/**
  * @brief  Calculate source address and destination address to refresh display buffer.
  * @param  pSrc a pointer to source address
  * @param  pDst a pointer to destination address
  * @retval uint32_t Status (0: Succeed, other: Error)
  */
uint32_t CalculateTransferAddress(uint32_t* pSrc, uint32_t* pDst)
{
    uint32_t c_fr = 0;
    uint32_t c_update_fr = 0;

    uint32_t src_fr = 0;

    uint32_t src_addr = 0;
    uint32_t dst_addr = 0;

    /* calculate source frame */
    src_addr = (u1Scrn_CurrFrameIdx)*u4Scrn_FrameWDataLen*4;

    /* calculate destination frame*/
    /* get current display frame */
    c_fr = __HAL_LED_GET_DISPLAY_FRAME_INDEX(&hled1);

    if(c_fr < (u4Scrn_FrameTotal - 1))
    {
        c_update_fr = c_fr + 1;
    }
    else
    {
        c_update_fr = 0;
    }

    /* calculate display frame address */
    dst_addr = c_update_fr*u4Scrn_FrameWDataLen*4;

    *pSrc = src_addr;
    *pDst = dst_addr;

    return 0;
}


/**
  * @brief  Copy screen frame to display frame by CPU.
  * @param  None
  * @retval None
  */
static void XTMW_Display_FrameBuff_Refresh(void)
{
    uint32_t src_addr = 0;
    uint32_t dst_addr = 0;

    if(CalculateTransferAddress(&src_addr, &dst_addr))
    {
        return;
    }

    src_addr = (uint32_t)(&aScrnBuf[0])+src_addr;
    dst_addr = (uint32_t)&(LED->BUFF[0]) + dst_addr;
    /*refresh*/
    memcpy((uint32_t*)dst_addr, (uint32_t*)src_addr, u4Scrn_FrameWDataLen*4);

    /*update Update frame and refresh pattern */
    //TransferCompleted();
}

/**
  * @brief  Copy screen frame to display frame by DMA.
  * @param  None
  * @retval None
  */
static void XTMW_Display_FrameBuff_Refresh_DMA(void)
{
  uint32_t src_addr, dst_addr;

  if(CalculateTransferAddress(&src_addr, &dst_addr))
  {
    return;
  }

	src_addr = (uint32_t)(&aScrnBuf[0])+src_addr;
	dst_addr = (uint32_t)&(LED->BUFF[0]) + dst_addr;

  HAL_DMA_Start_IT(hled1.hdma, src_addr, dst_addr, u4Scrn_FrameWDataLen);

  u1BuffReflashing_flag = TRUE;
}

/**
  * @brief  Increase new screen frame number.
  * @param  None
  * @retval None
  */
static void XTMW_Scrn_DrawNewFrame(void)
{	
	  u1Scrn_CurrFrameIdx = u1Scrn_UpdateFrameIdx;
    if(u1Scrn_UpdateFrameIdx < (u4Scrn_FrameTotal-1))
    {
        u1Scrn_UpdateFrameIdx++;
    }
    else{
        u1Scrn_UpdateFrameIdx = 0;
    }
    return;
}
/**
  * @brief  Update display buffer to sync with screen buffer.
  * @param  None
  * @retval None
  */
static void XTMW_ScrnAllFrames_Update(uint32_t *buff)
{
    /* Copy screen buffer to display buffer */
    memcpy((uint32_t*)&(hled1.Instance->BUFF[0]), buff, SCREEN_BUFF_WSIZE*4);
}

/**
  * @brief  Display in screen buffer.
  * @param  Com common index
  * @param  Seg Segment index
  * @param  Data Segment data, 
  * @retval None
  */
static void XTMW_WriteBuff(LED_ComTypeDef comid, uint32_t Seg, uint32_t Data)
{
    if (hled1.Init.Display_Mode == LED_RMODE_BRIGHT)
    {
        uint32_t framebase = u1Scrn_UpdateFrameIdx*(u4Scrn_FrameWDataLen);
        uint32_t comoffset = HAL_LED_GetBufferComIndex(&hled1, comid)*BRT_COMF_WDATALEN_DEFAULT;   /* a COM is assigned 5 word buffer, it is fixed space for a com buffer in bright mode*/
        uint32_t segoffset = Seg>>1;                                   /*two segments occupy a word buff*/
		    
        uint32_t segvalue = LED->BUFF[framebase + comoffset + segoffset];
        segvalue &= ~(0xFFFF << (16*(Seg&0x01)));                      /*Seg1/3/5/7:[32:16], Seg0/2/4/6/8:[16:0]*/ 
        segvalue |= (Data << (16*(Seg&0x01)));                         /*the data should be 0 or 255*/
        LED->BUFF[framebase + comoffset + segoffset] = segvalue;
    }
    else
    {
        uint32_t framebase = u1Scrn_UpdateFrameIdx*(u4Scrn_FrameWDataLen);
        uint32_t compos = HAL_LED_GetBufferComIndex(&hled1, comid);	     /*the positon index of the com in frame*/	
        uint32_t comoffset = compos >> 1;                              /*two coms occupy a word buff*/
        uint32_t segoffset = 1 << Seg;
		    
        uint32_t  segvalue = LED->BUFF[framebase + comoffset];
        segvalue &= ~(segoffset << (16*(compos&0x01)));          /*Com1/3/5/7:[25:16], com0/2/4/6:[8:0]*/ 
        if(Data > 0)
        segvalue |= (segoffset << (16*(comid&0x01)));                  /*the data should be 0 or 1*/ 
		    
        LED->BUFF[framebase + comoffset] = segvalue;
    }
}

/**
  * @brief  Display in screen buffer.
  * @param  Com common index
  * @param  Seg Segment index
  * @param  Data Segment data
  * @retval None
  */
static void XTMW_WriteScreen(LED_ComTypeDef Comid, uint32_t Seg, uint32_t Data)
{
    if (hled1.Init.Display_Mode == LED_RMODE_BRIGHT)
    {
        uint32_t framebase = u1Scrn_UpdateFrameIdx*(u4Scrn_FrameWDataLen);
        uint32_t comoffset = HAL_LED_GetBufferComIndex(&hled1, Comid)*BRT_COMF_WDATALEN_DEFAULT;  /* a COM is assigned 5 word buffer, it is fixed space for a com buffer in bright mode*/
        uint32_t segoffset = Seg>>1;                                      /*two segments occupy a word buff*/
        
        uint32_t segvalue = aScrnBuf[framebase + comoffset + segoffset];
        segvalue &= ~(0xFFFF << (16*(Seg&0x01)));                       /*Seg1/3/5/7:[32:16], Seg0/2/4/6/8:[16:0]*/ 
        segvalue |= (Data << (16*(Seg&0x01)));                          /*the data should be 0 or 255*/
        aScrnBuf[framebase + comoffset + segoffset] = segvalue;
    }
    else
    {
        uint32_t comid = HAL_LED_GetBufferComIndex(&hled1, Comid);
        uint32_t framebase = u1Scrn_UpdateFrameIdx*(u4Scrn_FrameWDataLen);
        uint32_t comoffset = comid >> 1;                            /*two coms occupy a word buff*/
        uint32_t segoffset = 1 << Seg;
        
        uint32_t segvalue = aScrnBuf[framebase + comoffset];
        segvalue &= ~(segoffset << (16*(comid&0x01)));               /*Com1/3/5/7:[25:16], com0/2/4/6:[8:0]*/ 
        if(Data > 0)
        segvalue |= ((segoffset)  << (16*(comid&0x01)));                  /*the data should be 0 or 1*/ 
        aScrnBuf[framebase + comoffset] = segvalue;
    }
}


/**
  * @brief  Dispaly character with 7-segment in LED->BUFF.
  * @param  Com common index
  * @param  Ch character
  * @param  Bright Display brightness
  * @retval None
  */
static void XTMW_DrawTextDirect(LED_ComTypeDef Comid, uint8_t Ch, uint32_t Bright, uint32_t Mode)
{
    uint16_t segpattern = aSegCom_patternlib[Comid];                                  
    uint8_t segctrl = aSegMap_CodeFontlib[XTMW_GetFontIdx(Ch)];
    
    uint16_t mask = 0x01;
    uint8_t i = 0;
    
    for(i=0; i<SEGMENT_MAX; i++)
    { 
        if(segpattern & (((uint32_t)0x01UL)<<i))
        {
            if (segctrl & mask)
            {
                XTMW_WriteBuff(Comid, i, HAL_LED_PackSegData(&hled1, Comid, i, Bright));
            }
            else
            {
                if(Mode == LED_TEXT_MODE_REWRITE)
                {
                    XTMW_WriteBuff(Comid, i, HAL_LED_PackSegData(&hled1, Comid, i, 0));
                }
            }
            mask <<= 1; 
        }
    }
}

/**
  * @brief  Dispaly character with 7-segment.
  * @param  Com common index
  * @param  Ch character
  * @param  Bright Display brightness
  * @retval None
  */
static void XTMW_DrawText(LED_ComTypeDef Com, uint8_t Ch, uint32_t Bright, uint32_t Mode)
{
    uint16_t segpattern = aSegCom_patternlib[Com];
    uint8_t segctrl  = aSegMap_CodeFontlib[XTMW_GetFontIdx(Ch)];
    uint8_t i = 0;
    uint16_t mask = 0x01;	
    
    for(i=0; i<SEGMENT_MAX; i++)
    { 
        if(segpattern & (((uint32_t)0x01UL)<<i))
        {
            if ((segctrl & mask))
            {
                XTMW_WriteScreen(Com, i, HAL_LED_PackSegData(&hled1, Com, i, Bright));
            }
            else  if(Mode == LED_TEXT_MODE_REWRITE)
            {
                XTMW_WriteScreen(Com, i, HAL_LED_PackSegData(&hled1, Com, i, 0));
            }
            mask <<= 1; 
        }
    }
    return;
}


/**
* @brief  the display style of Bright mode: LED dimming.
  * @param  None
  * @retval None
  */
static void XTMW_LEDBrtDisplay_Dimming(uint32_t Step, uint32_t Intpol)
{
    HAL_LED_SetRunningMode(&hled1, LED_DMODE_DIMMING, Step, Intpol);
}

/**
* @brief  the display style of Bright mode: LED blink.
  * @param  None
  * @retval None
  */
static void XTMW_LEDBrtDisplay_Blink(void)
{
    HAL_LED_SetRunningMode(&hled1, LED_DMODE_DIMMING, LED_DIMMING_STEP_1, 2);
}

/**
* @brief  the display style of Bright mode: LED normal.
  * @param  None
  * @retval None
  */
static void XTMW_LEDBrtDisplay_Normal(void)
{
    HAL_LED_SetRunningMode(&hled1, LED_DMODE_NORMAL, 0, 0);
}


/**
  * @}
  */

/** @addtogroup LEDDriver_FJ5161BH_Exported_Functions
  * @{
  */

/**
  * @brief  Clear display buffer to sync with screen buffer.
  * @param  None
  * @retval None
  */
void XT_LED_ScreenAllFrames_Clear(void)
{
    u1Scrn_UpdateFrameIdx = 0;
    memset(aScrnBuf, 0x00, SCREEN_BUFF_WSIZE*4);
    XTMW_ScrnAllFrames_Update(&aScrnBuf[0]);
}

/**
  * @brief  Clear display buffer to sync with screen buffer.
  * @param  None
  * @retval None
  */
void XT_LED_ScreenAllFrames_Turnon(void)
{
    u1Scrn_UpdateFrameIdx = 0;
    memset(aScrnBuf, 0xFF, SCREEN_BUFF_WSIZE*4);
    XTMW_ScrnAllFrames_Update(&aScrnBuf[0]);
}

/**
* @brief  Running mode: LED onoff mode.
  * @param  None
  * @retval None
  */
void XT_LED_Rmode_SetOnOFFMode(void)
{
    uint32_t tmp;

    hled1.Init.Display_Mode = LED_RMODE_ONOFF;                /*!< LED display mode */
    __HAL_LED_SET_RUNMODE_ONOFF(&hled1);

    tmp = HAL_LED_GetComIdxMax(hled1.Init.ComEnable);         /* Buffer can only be assigned from 0 to the max selected-com index*/

    u4Scrn_FrameWDataLen = ( tmp >> 1) + (tmp & 0x01);            /*two coms occupy a word*/
    if(tmp == 0) u4Scrn_FrameWDataLen = 1;
    u4Scrn_FrameTotal = SCREEN_BUFF_WSIZE/u4Scrn_FrameWDataLen;     /*the number of frames in screen buffer*/

    __HAL_LED_SET_DATANUMBERINFRAME_ONOFFMODE(&hled1, u4Scrn_FrameWDataLen);
    __HAL_LED_SET_FRAMENUMINBUFFER(&hled1, (u4Scrn_FrameTotal));
    __HAL_LED_SET_DSIPLAYBUFFER_ENDP(&hled1, (u4Scrn_FrameTotal*u4Scrn_FrameWDataLen - 1));

    XT_LED_ScreenAllFrames_Clear();
}

	
/**
* @brief  Running mode: LED bright mode.
  * @param  None
  * @retval None
  */
void XT_LED_Rmode_SetBrightMode(void)
{
    uint32_t com_total; 

    hled1.Init.Display_Mode = LED_RMODE_BRIGHT;                   /*!< LED display mode */ 
    __HAL_LED_SET_RUNMODE_DUTY(&hled1);

    com_total = HAL_LED_GetComNumber(hled1.Init.ComEnable);       /* the unenabled COM does not occupy data space. a COM is assigned fixed 5 word buffer*/

    u4Scrn_FrameWDataLen = (com_total*BRT_COMF_WDATALEN_DEFAULT);                          /* a COM is assigned 5 word buffer, it is fixed space for a com buffer*/
    u4Scrn_FrameTotal    = SCREEN_BUFF_WSIZE/u4Scrn_FrameWDataLen;    /*the number of frames in screen buffer*/

    __HAL_LED_SET_FRAMENUMINBUFFER(&hled1, (u4Scrn_FrameTotal));
    __HAL_LED_SET_DSIPLAYBUFFER_ENDP(&hled1, (u4Scrn_FrameTotal*u4Scrn_FrameWDataLen - 1));

    XT_LED_ScreenAllFrames_Clear();
}


/**
  * @brief  Dispaly a character.
  * @param  Led specify LED
  * @param  Ch text
  * @param  Bright brightness
  * @retval None
  */
void XT_LED_DisplayChar(LED_ComTypeDef comid, uint8_t Ch, uint32_t Bright, uint32_t Mode)
{
    XTMW_DrawText(comid, Ch, Bright, Mode);
}

/**
  * @brief  Dispaly string.
  * @param  showstr
  * @retval None
  */
void XT_LED_DisplayStr(uint8_t* showstr)
{
    uint8_t i = 0;

    for(i=0;i<COMMON_MAX ; i++)
    {			
        XTMW_DrawText(i, showstr[i], DEMO_EXAMPLE_BRIGHT, LED_TEXT_MODE_REWRITE);		
    }	
    XTMW_Scrn_DrawNewFrame(); 
}

/**
  * @brief  Dispaly Refresh.
  * @param  showstr
  * @retval None
  */
void XT_LED_DisplayRefresh(void)
{
    XTMW_Scrn_DrawNewFrame(); 
}


/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_LED_DmaCpltCB(void)
{
  /* USER CODE */
  u1BuffReflashing_flag = 0;
	return;
}

/**
  * @brief  LED frame displayed ISR for screen/display buffer mamagement.
  * @param  None
  * @retval None
  */
void XT_LED_FrameClpt_IRQHandler(void)
{
#if defined(LED_USE_DMA)	
  if(u1BuffReflashing_flag)
  {
    HAL_DMA_Abort_IT(hled1.hdma);
    u1BuffReflashing_flag = 0;
  }
  XTMW_Display_FrameBuff_Refresh_DMA();	 	
#else
	XTMW_Display_FrameBuff_Refresh();
#endif	
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
