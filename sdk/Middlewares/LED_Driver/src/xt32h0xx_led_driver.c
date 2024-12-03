/**
  ******************************************************************************
  * @file    xt32h0xx_led_driver.c
  * @author  Software Team
  * @brief   This file provides set of firmware functions to manage:
  *          -LED buffer
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */ 
  
/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "xt32h0xx_led_driver.h"
#include "xt32h0xx_hal_led.h"

/** @addtogroup MW
  * @{
  */ 

/** @addtogroup XT32H0xx_LED_DRIVER
  * @{
  */   

/** @defgroup XT32H0xx_LED_DRIVER_Private_Defines Private Defines
  * @{
  */ 
#define SCREEN_BUFSIZE                 (128)

#define SEGMENT_MAX                    (9)
#define COMMON_MAX                     (8)

#define LED_USE_DMA                    (1)
#define LED_USE_DMA_REQUEST            (1)

/**
  * @}
  */ 

/** @defgroup XT32H0xx_LED_DRIVER_Private_Variables Private Variables
  * @{
  */ 
/** 
  * @brief digitCodeMap indicate which segments must be illuminated to display
  * each number.
  */
static const uint8_t digitCodeMap[] = {
  // PGFEDCBA  Segments      7-segment map:
  0b00111111, // 0   '0'          AAA
  0b00000110, // 1   '1'         F   B
  0b01011011, // 2   '2'         F   B
  0b01001111, // 3   '3'          GGG
  0b01100110, // 4   '4'         E   C
  0b01101101, // 5   '5'         E   C
  0b01111101, // 6   '6'          DDD     P
  0b00000111, // 7   '7'
  0b01111111, // 8   '8'
  0b01101111, // 9   '9'
  0b01110111, // 65  'A'
  0b01111100, // 66  'b'
  0b00111001, // 67  'C'
  0b01011110, // 68  'd'
  0b01111001, // 69  'E'
  0b01110001, // 70  'F'
  0b00111101, // 71  'G'
  0b01110110, // 72  'H'
  0b00110000, // 73  'I'
  0b00001110, // 74  'J'
  0b01110110, // 75  'K'  Same as 'H'
  0b00111000, // 76  'L'
  0b00000000, // 77  'M'  NO DISPLAY
  0b01010100, // 78  'n'
  0b00111111, // 79  'O'
  0b01110011, // 80  'P'
  0b01100111, // 81  'q'
  0b01010000, // 82  'r'
  0b01101101, // 83  'S'
  0b01111000, // 84  't'
  0b00111110, // 85  'U'
  0b00111110, // 86  'V'  Same as 'U'
  0b00000000, // 87  'W'  NO DISPLAY
  0b01110110, // 88  'X'  Same as 'H'
  0b01101110, // 89  'y'
  0b01011011, // 90  'Z'  Same as '2'
  0b00000000, // 32  ' '  BLANK
  0b01000000, // 45  '-'  DASH
  0b10000000, // 46  '.'  PERIOD
  0b01100011, // 42  '*'  DEGREE ..
  0b00001000, // 95  '_'  UNDERSCORE
};

/** 
  * @brief mapping segment to 7-segment digit per common
  * each number.
  */
static const uint16_t segs[COMMON_MAX] = 
{
  0b0111111110,
  0b0111111101,
  0b0111111011,
  0b0111110111,
  0b0111101111,
  0b0111011111,
  0b0110111111,
  0b0101111111,
};

/** 
  * @brief Screen buffer
  * 
  */
static uint32_t ScrBuf[SCREEN_BUFSIZE];   
static uint32_t ScrBufFrameNum = 2;
static uint32_t ScrBufFrameRefreshMask[4] = {0, 0, 0, 0};
static uint32_t ScrBufFrameSize = 5;
/** 
  * @brief Screen buffer frame updated index and count
  * 
  */
static uint32_t UpdateFrameIdx = 0;
static uint32_t UpdateFrameCount = 0;

/**
  * @brief Display buffer frame need to refresh
  * 
  */
static uint32_t RefreshFramePattern[4] = {0, 0, 0, 0};   //2 frames

/** 
  * @brief Display buffer refreshed frame index
  * 
  */
static uint32_t RefreshedFrame = 0;

/** 
  * @brief Display buffer is refreshing flag
  * 
  */
static uint32_t Refreshing = 1;

#if (LED_USE_DMA_REQUEST == 0)
static uint32_t RefreshingCount = 0;
#endif

/** 
  * @brief Display Handler
  * 
  */
LED_HandleTypeDef hled1;
DMA_HandleTypeDef hleddma;

/**
  * @}
  */ 

/** @defgroup XT32H0xx_LED_DRIVER_Private_Functions Private Functions
  * @{
  */
uint32_t GetDigitCodeIdx(uint8_t Ch);  

void WriteScreen(uint32_t Com, uint32_t Seg, uint32_t Data);
void DrawText(uint8_t Com, uint8_t Ch, uint32_t Bright, uint32_t Mode);
void DrawDot(uint8_t Com, uint8_t Seg, uint32_t Bright);

uint32_t CalculateTransferAddress(uint32_t* pSrc, uint32_t* pDst);
void TransferCompleted(void);

void CreateFrameMask(uint32_t FrameNum);

void WriteBuff(uint32_t Com, uint32_t Seg, uint32_t Data);
void DrawTextDirect(uint8_t Com, uint8_t Ch, uint32_t Bright, uint32_t Mode);
void DrawDotDirect(uint8_t Com, uint8_t Seg, uint32_t Bright);
/**
  * @}
  */ 

/** @addtogroup xt32h0xx_LED_DRIVER_Exported_Functions
  * @{
  */ 
/** @addtogroup XT32H0XX_LED_DRIVER_Exported_Functions_Group1
  * @{
  */
/**
  * @brief  Initialize LED.
  * @param  None
  * @retval None
  */
void             LED_DRV_Init(LED_DRV_InitTypeDef* pLedp)
{
  uint32_t tmp;
  int i;
	
#if (LED_USE_DMA)
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
	
	hleddma.Init.Direction = DMA_MEMORY_TO_PERIPH_FC_DMAC;
  hleddma.Init.SrcInc = DMA_SINC_INCREMENT;
  hleddma.Init.DstInc = DMA_DINC_INCREMENT;
  hleddma.Init.SrcDataSize = DMA_SDATAALIGN_WORD;
  hleddma.Init.DstDataSize = DMA_DDATAALIGN_WORD;
  hleddma.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
  hleddma.Init.DstBurstSize = DMA_DST_MSIZE_1;
  hleddma.Init.Mode = DMA_SGLBLK;
  hleddma.Instance = (pLedp->DmaChannelIndex == 0) ? DMA1_Channel0 : \
	                   (pLedp->DmaChannelIndex == 1) ? DMA1_Channel1 : \
	                   (pLedp->DmaChannelIndex == 2) ? DMA1_Channel2 : \
	                   (pLedp->DmaChannelIndex == 3) ? DMA1_Channel3 : \
	                   (pLedp->DmaChannelIndex == 4) ? DMA1_Channel4 : \
	                   (pLedp->DmaChannelIndex == 5) ? DMA1_Channel5 : \
	                   (pLedp->DmaChannelIndex == 6) ? DMA1_Channel6 : DMA1_Channel7;
	hleddma.ChannelIndex = pLedp->DmaChannelIndex;
  hleddma.DMAAux = DMAAUX1;
  HAL_DMA_Init(&hleddma);
	
	HAL_DMA_RegisterCallback(&hleddma,HAL_DMA_XFER_BLOCK_CB_ID, LED_DRV_DMA_Block_IRQHandler);
#if (LED_USE_DMA_REQUEST == 0)	
	HAL_DMA_RegisterCallback(&hleddma,HAL_DMA_XFER_DSTTRAN_CB_ID, LED_DRV_DMA_DstTran_IRQHandler);
#endif	
#endif

  hled1.Init.ComEnable = pLedp->ComEnable;
  hled1.Init.SegEnable = pLedp->SegEnable;                 
  hled1.Init.Scan_Feq = pLedp->Scan_Feq;                   /*!< @frames per second. i.g. 30,60,100,120 
                                          divider = SCLK / frame period / Scan_Feq */

  hled1.Init.Display_Mode = pLedp->Display_Mode;                /*!< LED display mode @ref LED_Display_MODE */

  hled1.Init.Dead_Time = pLedp->Dead_Time;                  /*!< COM period = 256+dead time, frame period = COM_Period * ComScanNumber */

  hled1.Init.Current_Bias = pLedp->Current_Bias;               /*!< Current bias tune */
  hled1.Init.Bright_Step = pLedp->Bright_Step;                /*!< Brightness step */
  for(i=0; i<9; i++)
    hled1.Init.SegBright_Max[i] = pLedp->SegBright_Max[i];                /*!< Segment brightness maximum */

  hled1.Init.pScreen_Buffer = &(ScrBuf[0]);            /*!< A pointer to screen buffer */

#if (LED_USE_DMA)
	HAL_LED_LinkDMA(&hled1, &hleddma);
#if (LED_USE_DMA_REQUEST)
  HAL_LED_DMAHSIFConfig(&hled1, &hleddma, 0, 3);
#endif	
#else	
  hled1.hdma = NULL;
#endif
  hled1.Instance = LED;
	
	HAL_LED_AnaOn(&hled1);
	
	//HAL_Delay(1);  // Must > 10us
	for(i=0; i<480; i++)
	{
		__NOP();
	}

  HAL_LED_Init(&hled1);

  
  if(hled1.Init.Display_Mode == LED_RMODE_ONOFF)
  {
		tmp = HAL_LED_GetComIdxMax(hled1.Init.ComEnable);

    ScrBufFrameSize = ( tmp >> 1) + (tmp & 0x01);
		if(tmp == 0) ScrBufFrameSize = 1;
    ScrBufFrameNum = 128/ScrBufFrameSize;
		
		CreateFrameMask(ScrBufFrameNum);

		MODIFY_REG(hled1.Instance->MODE, LED_MODE_DN|LED_MODE_BFN,  (ScrBufFrameSize << LED_MODE_DN_Pos)|((ScrBufFrameNum-1) << LED_MODE_BFN_Pos));
	  MODIFY_REG(hled1.Instance->MODE, LED_MODE_ALAST, ((ScrBufFrameSize*ScrBufFrameNum-1)<<LED_MODE_ALAST_Pos));

  }
  else
  {
		tmp = HAL_LED_GetComNumber(hled1.Init.ComEnable);

    ScrBufFrameSize = (tmp*5);
    ScrBufFrameNum = 128/ScrBufFrameSize;
		
		CreateFrameMask(ScrBufFrameNum);

		MODIFY_REG(hled1.Instance->MODE, LED_MODE_BFN,  ((ScrBufFrameNum-1) << LED_MODE_BFN_Pos));
	  MODIFY_REG(hled1.Instance->MODE, LED_MODE_ALAST, ((ScrBufFrameSize*ScrBufFrameNum-1)<<LED_MODE_ALAST_Pos));

  }

#if (LED_USE_DMA)	
	Refreshing = 0;
#else
	Refreshing = 0;
#endif	
	memset(RefreshFramePattern, 0, 16);
	
#if (LED_USE_DMA_REQUEST)	
	__HAL_LED_DMAREQ_ENABLE(&hled1, LED_DMAREQ_FDE);
#endif
	
#if (LED_USE_DMA)	
  HAL_NVIC_SetPriority(DMA1_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(DMA1_IRQn);
#endif

	/* Configure ICTL and enable ICTL */  
	CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_LED_MASK);
	SET_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_LED_MASK);
	
	/* config sim */
	CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQCFG_LED_MASK);
	
}

/**
  * @brief  Initialize LED for direct display.
  * @param  None
  * @retval None
  */
void             LED_DRV_DirectInit(LED_DRV_InitTypeDef* pLedp)
{
  uint32_t tmp;
  int i;

  hled1.Init.ComEnable = pLedp->ComEnable;
  hled1.Init.SegEnable = pLedp->SegEnable;                 
  hled1.Init.Scan_Feq = pLedp->Scan_Feq;                   /*!< @frames per second. i.g. 30,60,100,120 
                                          divider = SCLK / frame period / Scan_Feq */

  hled1.Init.Display_Mode = pLedp->Display_Mode;                /*!< LED display mode @ref LED_Display_MODE */

  hled1.Init.Dead_Time = pLedp->Dead_Time;                  /*!< COM period = 256+dead time, frame period = COM_Period * ComScanNumber */

  hled1.Init.Current_Bias = pLedp->Current_Bias;               /*!< Current bias tune */
  hled1.Init.Bright_Step = pLedp->Bright_Step;                /*!< Brightness step */
  for(i=0; i<9; i++)
    hled1.Init.SegBright_Max[i] = pLedp->SegBright_Max[i];                /*!< Segment brightness maximum */

  hled1.Init.pScreen_Buffer = &(ScrBuf[0]);            /*!< A pointer to screen buffer */

  hled1.Instance = LED;
	
	HAL_LED_AnaOn(&hled1);
	
	//HAL_Delay(1);  // Must > 10us
	for(i=0; i<480; i++)
	{
		__NOP();
	}

  HAL_LED_Init(&hled1);

  
  if(hled1.Init.Display_Mode == LED_RMODE_ONOFF)
  {
		tmp = HAL_LED_GetComIdxMax(hled1.Init.ComEnable);

    ScrBufFrameSize = ( tmp >> 1) + (tmp & 0x01);
		if(tmp == 0) ScrBufFrameSize = 1;
    ScrBufFrameNum = 1; //128/ScrBufFrameSize;
		
		//CreateFrameMask(ScrBufFrameNum);

		MODIFY_REG(hled1.Instance->MODE, LED_MODE_DN|LED_MODE_BFN,  (ScrBufFrameSize << LED_MODE_DN_Pos)|((ScrBufFrameNum-1) << LED_MODE_BFN_Pos));
	  MODIFY_REG(hled1.Instance->MODE, LED_MODE_ALAST, ((ScrBufFrameSize*ScrBufFrameNum-1)<<LED_MODE_ALAST_Pos));

  }
  else
  {
		tmp = HAL_LED_GetComNumber(hled1.Init.ComEnable);

    ScrBufFrameSize = (tmp*5);
    ScrBufFrameNum = 1; //128/ScrBufFrameSize;
		
		//CreateFrameMask(ScrBufFrameNum);

		MODIFY_REG(hled1.Instance->MODE, LED_MODE_BFN,  ((ScrBufFrameNum-1) << LED_MODE_BFN_Pos));
	  MODIFY_REG(hled1.Instance->MODE, LED_MODE_ALAST, ((ScrBufFrameSize*ScrBufFrameNum-1)<<LED_MODE_ALAST_Pos));

  }

	//clear display
	memset((uint32_t*)&(hled1.Instance->BUFF[0]), 0, 128*4);
	
	/* Configure ICTL and disalbe ICTL */  
	SET_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_LED_MASK);
	CLEAR_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_LED_MASK);
}
/**
  * @brief  Uninitialize LED.
  * @param  None
  * @retval None
  */
void             LED_DRV_DeInit(void)
{
	HAL_LED_DeInit(&hled1);
}

/**
  * @brief  LED on.
  * @param  None
  * @retval None
  */
void             LED_DRV_On(void)
{
  HAL_LED_On(&hled1);
}

/**
  * @brief  LED off.
  * @param  None
  * @retval None
  */
void             LED_DRV_Off(void)
{
  HAL_LED_Off(&hled1);
}

/**
  * @brief  LED dimming.
  * @param  None
  * @retval None
  */
void             LED_DRV_Dimming(uint32_t Step, uint32_t Intpol)
{
  HAL_LED_SetRunningMode(&hled1, LED_DMODE_DIMMING, Step, Intpol);
}

/**
  * @brief  LED blink.
  * @param  None
  * @retval None
  */
void             LED_DRV_Blink(void)
{
  HAL_LED_SetRunningMode(&hled1, LED_DMODE_DIMMING, LED_DIMMING_STEP_1, 2);
}

/**
  * @brief  LED normal.
  * @param  None
  * @retval None
  */
void             LED_DRV_Normal(void)
{
  HAL_LED_SetRunningMode(&hled1, LED_DMODE_NORMAL, 0, 0);
}

/**
  * @brief  LED onoff mode.
  * @param  None
  * @retval None
  */
void             LED_DRV_SetOnOFFMode(void)
{
	uint32_t tmp;
	
  hled1.Init.Display_Mode = LED_RMODE_ONOFF;                /*!< LED display mode */

  MODIFY_REG(hled1.Instance->MODE, LED_MODE_RMD,   hled1.Init.Display_Mode);
	
  tmp = HAL_LED_GetComIdxMax(hled1.Init.ComEnable);

  ScrBufFrameSize = ( tmp >> 1) + (tmp & 0x01);
	if(tmp == 0) ScrBufFrameSize = 1;
  ScrBufFrameNum = 128/ScrBufFrameSize;

  CreateFrameMask(ScrBufFrameNum);
	
	MODIFY_REG(hled1.Instance->MODE, LED_MODE_DN | LED_MODE_BFN | LED_MODE_ALAST,  
	(ScrBufFrameSize << LED_MODE_DN_Pos) | ((ScrBufFrameNum - 1) << LED_MODE_BFN_Pos) | ((ScrBufFrameNum*ScrBufFrameSize - 1) << LED_MODE_ALAST_Pos));
	
  LED_DRV_ClearAllFrames();
	
#if (LED_USE_DMA)	
	Refreshing = 0;
#else
	Refreshing = 0;
#endif	
	memset(RefreshFramePattern, 0, 16);
}
	
/**
  * @brief  LED bright mode.
  * @param  None
  * @retval None
  */
void             LED_DRV_SetBrightMode(void)
{
	uint32_t tmp; 
	
  hled1.Init.Display_Mode = LED_RMODE_BRIGHT;                /*!< LED display mode */
                                            
  MODIFY_REG(hled1.Instance->MODE, LED_MODE_RMD,   hled1.Init.Display_Mode);  

  tmp = HAL_LED_GetComNumber(hled1.Init.ComEnable);

  ScrBufFrameSize = (tmp*5);
  ScrBufFrameNum = 128/ScrBufFrameSize;

  CreateFrameMask(ScrBufFrameNum);
	
	MODIFY_REG(hled1.Instance->MODE, LED_MODE_BFN | LED_MODE_ALAST,  
	((ScrBufFrameNum - 1) << LED_MODE_BFN_Pos) | ((ScrBufFrameNum*ScrBufFrameSize - 1) << LED_MODE_ALAST_Pos));


	LED_DRV_ClearAllFrames();
	
#if (LED_USE_DMA)	
	Refreshing = 0;
#else
	Refreshing = 0;
#endif	
	memset(RefreshFramePattern, 0, 16);
}

/**
  * @brief  Dispaly text.
  * @param  Led specify LED
  * @param  Ch text
  * @param  Bright brightness
  * @retval None
  */
void             LED_DRV_DisplayText(uint32_t Led, uint8_t Ch, uint32_t Bright, uint32_t Mode)
{
  DrawText(Led, Ch, Bright, Mode);
}

/**
  * @brief  Dispaly dot.
  * @param  Led specify LED
  * @param  Com
  * @param  Seg 
  * @param  Bright brightness
  * @retval None
  */
void             LED_DRV_DisplayNode(uint32_t Com, uint32_t Seg, uint32_t Bright)
{
  DrawDot(Com, Seg, Bright);
}

/**
  * @brief  Dispaly text directly to buffer.
  * @param  Led specify LED
  * @param  Ch text
  * @param  Bright brightness
  * @retval None
  */
void             LED_DRV_DisplayTextDirect(uint32_t Led, uint8_t Ch, uint32_t Bright, uint32_t Mode)
{
  DrawTextDirect(Led, Ch, Bright, Mode);
}

/**
  * @brief  Dispaly dot directly to buffer.
  * @param  Led specify LED
  * @param  Com
  * @param  Seg 
  * @param  Bright brightness
  * @retval None
  */
void             LED_DRV_DisplayNodeDirect(uint32_t Com, uint32_t Seg, uint32_t Bright)
{
  DrawDotDirect(Com, Seg, Bright);
}
/**
  * @}
  */

/** @addtogroup XT32H0XX_LED_DRIVER_Exported_Functions_Group2
  * @{
  */
/**
  * @brief  Increase new screen frame number.
  * @param  None
  * @retval None
  */
void LED_DRV_DrawNewFrame(void)
{
	if(UpdateFrameCount < ScrBufFrameNum)
	{
		UpdateFrameCount++;
	}
	
  if(UpdateFrameIdx < ScrBufFrameNum - 1)
  {
    UpdateFrameIdx++;
  }
  else{
    UpdateFrameIdx = 0;
  }
}

/**
  * @brief  Initialize display buffer to sync with screen buffer.
  * @param  None
  * @retval None
  */
void LED_DRV_InitAllFrames(void)
{
  /* Copy screen buffer to display buffer */
  memcpy((uint32_t*)&(hled1.Instance->BUFF[0]), (uint32_t*)ScrBuf, SCREEN_BUFSIZE*4);
}

/**
  * @brief  Clear screen buffer.
  * @param  None
  * @retval None
  */
void LED_DRV_ClearAllScreens(void)
{
	memset(ScrBuf, 0x00, SCREEN_BUFSIZE*4);
	//memset(ScrBuf, 0xFF, SCREEN_BUFSIZE*4);
	//LED_DRV_InitAllFrames();
}

/**
  * @brief  Clear display buffer to sync with screen buffer.
  * @param  None
  * @retval None
  */
void LED_DRV_ClearAllFrames(void)
{
	memset(ScrBuf, 0x00, SCREEN_BUFSIZE*4);
	//memset(ScrBuf, 0xFF, SCREEN_BUFSIZE*4);
	LED_DRV_InitAllFrames();
}

void LED_DRV_OnFrames(void)
{
	//memset(ScrBuf, 0x00, SCREEN_BUFSIZE*4);
	memset(&(LED->BUFF[0]), 0xFF, SCREEN_BUFSIZE*4);
	//LED_DRV_InitAllFrames();
}

/**
  * @brief  reset screen buffer count & index.
  * @param  None
  * @retval None
  */
void LED_DRV_ResetScreenBuffer(void)
{
  UpdateFrameIdx = 0;
  UpdateFrameCount = 0;
}
/**
  * @brief  Copy screen frame to display frame by CPU.
  * @param  None
  * @retval None
  */
void LED_DRV_RefreshFrame(void)
{
  uint32_t src_addr, dst_addr;

  if(CalculateTransferAddress(&src_addr, &dst_addr))
  {
    return;
  }

	src_addr = (uint32_t)(&ScrBuf[0])+src_addr;
	dst_addr = (uint32_t)&(LED->BUFF[0]) + dst_addr;
  /*refresh*/
  memcpy((uint32_t*)dst_addr, (uint32_t*)src_addr, ScrBufFrameSize*4);

  /*update Update frame and refresh pattern */
  TransferCompleted();
}

/**
  * @brief  Copy screen frame to display frame by DMA.
  * @param  None
  * @retval None
  */
void LED_DRV_RefreshFrame_DMA(void)
{
  uint32_t src_addr, dst_addr;

  if(CalculateTransferAddress(&src_addr, &dst_addr))
  {
    return;
  }

	src_addr = (uint32_t)(&ScrBuf[0])+src_addr;
	dst_addr = (uint32_t)&(LED->BUFF[0]) + dst_addr;

  HAL_DMA_Start_IT(hled1.hdma, src_addr, dst_addr, ScrBufFrameSize);

  Refreshing = 1;
}

/**
  * @brief  refreshed display frame by DMA.
  * @param  None
  * @retval None
  */
void LED_DRV_BlockCompleted_DMA(void)
{
  TransferCompleted();
}

/**
  * @brief  DMA block completed ISR for screen/display buffer mamagement.
  * @param  None
  * @retval None
  */
void LED_DRV_DMA_Block_IRQHandler(DMA_HandleTypeDef *hdma)
{
#if (LED_USE_DMA)	
  Refreshing = 0;
  HAL_DMA_Abort_IT(hled1.hdma);
  LED_DRV_BlockCompleted_DMA();
#endif	
}

void LED_DRV_DMA_DstTran_IRQHandler(DMA_HandleTypeDef *hdma)
{
#if (LED_USE_DMA_REQUEST == 0)	
	if((Refreshing)&&(RefreshingCount<ScrBufFrameSize))
	{
		DMAAUX1->SGLREQDST |= 0x202;
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		DMAAUX1->REQDST|= 0x202;

		__NOP();
		__NOP();
		__NOP();
		__NOP();
		
		RefreshingCount++;
	}
#endif	
}
/**
  * @brief  LED frame displayed ISR for screen/display buffer mamagement.
  * @param  None
  * @retval None
  */
void LED_DRV_FrameClpt_IRQHandler(void)
{
#if (LED_USE_DMA)	
  if(Refreshing)
  {
    HAL_DMA_Abort_IT(hled1.hdma);
    Refreshing = 0;
  }

  LED_DRV_RefreshFrame_DMA();
	
#if (LED_USE_DMA_REQUEST == 0)  
	if(Refreshing)
	{
		DMAAUX1->SGLREQDST |= 0x202;
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		DMAAUX1->REQDST |= 0x202;

		__NOP();
		__NOP();
		__NOP();
		__NOP();
		
		RefreshingCount = 1;
	}
#else
  if(Refreshing == 0)
	{
		//clear request
	}
#endif	
#else
	LED_DRV_RefreshFrame();
#endif	
}

/**
  * @brief  LED frame displayed ISR for screen/display buffer mamagement.
  * @param  None
  * @retval None
  */
void LED_DRV_FramePreRead_IRQHandler(void)
{
#if (LED_USE_DMA)	
  if(Refreshing)
  {
    HAL_DMA_Abort_IT(hled1.hdma);
    Refreshing = 0;
  }
#endif	
}

void LED_DRV_IRQHandler()
{
	uint32_t flag = LED->STATUS;

	CLEAR_BIT(hled1.Instance->CTRL, LED_CTRL_FIE);
 	READ_REG(hled1.Instance->STATUS);
	
	if(flag & LED_FLAG_FIF)
	{
		LED_DRV_FrameClpt_IRQHandler();
	}
//#if (LED_USE_DMA)
//	if(__HAL_LED_CHECK_FLAG(flag, LED_FLAG_PIF))
//	{
//		LED_DRV_FramePreRead_IRQHandler();
//	}
//#endif	
	SET_BIT(hled1.Instance->CTRL, LED_CTRL_FIE);
  READ_REG(hled1.Instance->STATUS);
}
/**
  * @}
  */

/** @addtogroup XT32H0XX_LED_DRIVER_Exported_Functions_Group3
  * @{
  */
/**
  * @brief  Iterate COMx.
  * @param  None
  * @retval None
  */
void LED_Test_CaseCom(void)
{
  uint32_t tmp;
  int i;
	uint32_t comx = 1;
	
	int j=0;
	uint32_t mask = 1;
	
	uint32_t wait_changed = 0;
	uint32_t wait_count = 0;
	uint32_t wait = 1;
	
#if (LED_USE_DMA)
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
	
#if (LED_USE_DMA_REQUEST)
	/* DMA request*/
	SYSCFG->DMA_CFG &= (0xFFFFFFFCUL);  //HW request interface 0 frame request cfg3
	SYSCFG->DMA_CFG |= (0x00000003UL);  //cfg3 
	
	/* HW handshaking */
	DMA1_Channel1->CFG_L &= ~(DMA_CH_CHCFG_SRCHSPOL|DMA_CH_CHCFG_DSTHSPOL|DMA_CH_CHCFG_DSTHS|DMA_CH_CHCFG_SRCHS);  //SRC_HS_POL = 0, DST_HS_POL = 0; HS_SEL_SRC = 0, HS_SEL_DST = 0
	DMA1_Channel1->CFG_H &= ~(DMA_CH_CHCFG_SRCPER|DMA_CH_CHCFG_DSTPER);
  DMA1_Channel1->CFG_H |= (0x00000000UL << DMA_CH_CHCFG_DSTPER_Pos); 
#endif	
	
  hleddma.Init.Direction = DMA_MEMORY_TO_PERIPH_FC_DMAC;
  hleddma.Init.SrcInc = DMA_SINC_INCREMENT;
  hleddma.Init.DstInc = DMA_DINC_INCREMENT;
  hleddma.Init.SrcDataSize = DMA_SDATAALIGN_WORD;
  hleddma.Init.DstDataSize = DMA_DDATAALIGN_WORD;
  hleddma.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
  hleddma.Init.DstBurstSize = DMA_DST_MSIZE_1;
  hleddma.Init.Mode = DMA_SGLBLK;
  hleddma.Instance = DMA1_Channel1;
	hleddma.ChannelIndex = 1;
  hleddma.DMAAux = DMAAUX1;
  HAL_DMA_Init(&hleddma);
	
	HAL_DMA_RegisterCallback(&hleddma,HAL_DMA_XFER_BLOCK_CB_ID, LED_DRV_DMA_Block_IRQHandler);
#if (LED_USE_DMA_REQUEST == 0)	
	HAL_DMA_RegisterCallback(&hleddma,HAL_DMA_XFER_DSTTRAN_CB_ID, LED_DRV_DMA_DstTran_IRQHandler);
#endif	
#endif

#if (LED_USE_DMA_REQUEST)	
	SET_BIT(LED->CTRL, LED_CTRL_FDE);
#endif
	
#if (LED_USE_DMA)	
  HAL_NVIC_SetPriority(DMA1_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(DMA1_IRQn);
#endif

	/* Configure ICTL and enable ICTL */  
	CLEAR_BIT(ICTL->IRQINTMASKH, 0x0F000000UL);
	SET_BIT(ICTL->IRQINTENH, 0x0F000000UL);
	
	/* config sim */
	CLEAR_BIT(SYSCFG->IRQ_CFG_2, 0x0F000000UL);
	
	HAL_NVIC_SetPriority(ICTL_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(ICTL_IRQn);

  hled1.Init.SegEnable = LED_ENABLE_SEG0 | LED_ENABLE_SEG1 | LED_ENABLE_SEG2 | LED_ENABLE_SEG3
                       | LED_ENABLE_SEG4 | LED_ENABLE_SEG5 | LED_ENABLE_SEG6 | LED_ENABLE_SEG7
                       | LED_ENABLE_SEG8;                 
  hled1.Init.Scan_Feq = 600;                   /*!< @frames per second. i.g. 30,60,100,120 
                                          divider = SCLK / frame period / Scan_Feq */

  hled1.Init.Display_Mode = LED_RMODE_BRIGHT;                /*!< LED display mode @ref LED_Display_MODE */
  //hled1.Init.Display_Mode = LED_RMODE_ONOFF;                /*!< LED display mode */
                                            

  hled1.Init.Dead_Time = 2;                  /*!< COM period = 256+dead time, frame period = COM_Period * ComScanNumber */

  hled1.Init.Current_Bias = 4;               /*!< Current bias tune */
  hled1.Init.Bright_Step = 2;                /*!< Brightness step */
  for(i=0; i<9; i++)
    hled1.Init.SegBright_Max[i] = 1;                /*!< Segment brightness maximum */

  hled1.Init.pScreen_Buffer = &(ScrBuf[0]);            /*!< A pointer to screen buffer */

#if (LED_USE_DMA)
  hled1.hdma = &(hleddma);
#else	
  hled1.hdma = NULL;
#endif
  hled1.Instance = LED;

  HAL_LED_AnaOn(&hled1);
	
//  HAL_Delay(1);  // Must > 10us
	for(i=0; i<48; i++)
	{
		__NOP();
	}

while(1)
{
  for(comx = 0xFF; comx >= 1; comx--)
	{
    hled1.Init.ComEnable = comx;

    HAL_LED_Init(&hled1);
  
		if(hled1.Init.Display_Mode == LED_RMODE_ONOFF)
		{
			tmp = HAL_LED_GetComIdxMax(hled1.Init.ComEnable);

			ScrBufFrameSize = ( tmp >> 1) + (tmp & 0x01);
			if(tmp == 0) ScrBufFrameSize = 1;
			ScrBufFrameNum = 128/ScrBufFrameSize;
			
			CreateFrameMask(ScrBufFrameNum);

			MODIFY_REG(hled1.Instance->MODE, LED_MODE_DN|LED_MODE_BFN,  (ScrBufFrameSize << LED_MODE_DN_Pos)|((ScrBufFrameNum-1) << LED_MODE_BFN_Pos));
		  MODIFY_REG(hled1.Instance->MODE, LED_MODE_ALAST, ((ScrBufFrameSize*ScrBufFrameNum-1)<<LED_MODE_ALAST_Pos));

		}
		else
		{
			tmp = HAL_LED_GetComNumber(hled1.Init.ComEnable);

			ScrBufFrameSize = (tmp*5);
			ScrBufFrameNum = 128/ScrBufFrameSize;
			
			CreateFrameMask(ScrBufFrameNum);

			MODIFY_REG(hled1.Instance->MODE, LED_MODE_BFN,  ((ScrBufFrameNum-1) << LED_MODE_BFN_Pos));
		  MODIFY_REG(hled1.Instance->MODE, LED_MODE_ALAST, ((ScrBufFrameSize*ScrBufFrameNum-1)<<LED_MODE_ALAST_Pos));

		}
		
		LED_DRV_ResetScreenBuffer();

	  SET_BIT(hled1.Instance->CTRL, LED_CTRL_FIE);
  	READ_REG(hled1.Instance->STATUS);

#if (LED_USE_DMA_REQUEST)	
	SET_BIT(LED->CTRL, LED_CTRL_FDE);
#endif
		
		Refreshing = 0;

		memset(RefreshFramePattern, 0, 16);
	
	
		LED_DRV_ClearAllFrames();
		LED_DRV_Normal();
			
		LED_DRV_On();
	
		mask = 1;
		for(j=0; j<8; j++)
		{
			if(mask & comx)
			{
			  LED_DRV_DisplayText(j, '8', 120, LED_TEXT_MODE_REWRITE);
			  LED_DRV_DisplayNode(j, 8, 180);
			}
			mask <<= 1;
		}
    LED_DRV_DrawNewFrame();	
		
		//for(j=0; j<100000; j++)
		//{
		//	__nop();
		//}
		wait_count = 0;
		wait_changed = 0;
		wait = 1;
		while(wait)
		{
			__NOP();
			if((__HAL_LED_GET_DISPLAY_FRAME_INDEX(&hled1) == 2) && (wait_changed == 0))
			{
				wait_count++;
				wait_changed = 1;
			}
			
			if((__HAL_LED_GET_DISPLAY_FRAME_INDEX(&hled1) != 2) && (wait_changed == 1))
			{
				wait_changed = 0;
			}
			
			if(wait_count >= 2)
			{
				wait_count = 0;
				wait = 0;
			}
		}
		
		CLEAR_BIT(hled1.Instance->CTRL, LED_CTRL_FIE);
  	READ_REG(hled1.Instance->STATUS);

		CLEAR_BIT(hled1.Instance->CTRL, LED_CTRL_FDE);
		
		LED_DRV_Off();
		
		while(LED->DEBUG & LED_DEBUG_FSM)
		{
			__NOP();
		}
		
		//HAL_DMA_Abort_IT(hled1.hdma);
		
		LED_DRV_DeInit();

  }
}	
}
/**
  * @}
  */ 

/**
  * @}
  */

/** @addtogroup XT32H0xx_LED_DRIVER_Private_Functions
  * @{
  */

/**
  * @brief  Get 7-segment display pattern.
  * @param  Ch chacater
  * @retval uint32_t display pattern
  */
uint32_t GetDigitCodeIdx(uint8_t Ch)
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
  else if(Ch == ' ')
  {
    res = 36;
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
  else if(Ch == '_')
  {
    res = 40;
  }

  return res;
}

/**
  * @brief  Display in screen buffer.
  * @param  Com common index
  * @param  Seg Segment index
  * @param  Data Segment data
  * @retval None
  */
void WriteScreen(uint32_t Com, uint32_t Seg, uint32_t Data)
{
  if (hled1.Init.Display_Mode == LED_RMODE_BRIGHT)
  {
    uint32_t framebase = UpdateFrameIdx*(ScrBufFrameSize);
    uint32_t comoffset = HAL_LED_GetBufferComIndex(&hled1, Com)*5;
    uint32_t segoffset = Seg>>1;
  
    uint32_t tmp = ScrBuf[framebase + comoffset + segoffset];
    tmp &= ~(0xFFFF << (16*(Seg&0x01)));
    tmp |= (Data << (16*(Seg&0x01)));
    ScrBuf[framebase + comoffset + segoffset] = tmp;
  }
  else
  {
		uint32_t comidx = HAL_LED_GetBufferComIndex(&hled1, Com);
    uint32_t framebase = UpdateFrameIdx*(ScrBufFrameSize);
    uint32_t comoffset = comidx >> 1;
    uint32_t segoffset = 1 << Seg;
  
    uint32_t tmp = ScrBuf[framebase + comoffset];
    tmp &= ~(segoffset << (16*(comidx&0x01)));
    tmp |= ((Data)  << (16*(comidx&0x01)));
    ScrBuf[framebase + comoffset] = tmp;
  }
}

/**
  * @brief  Dispaly character with 7-segment.
  * @param  Com common index
  * @param  Ch character
  * @param  Bright Display brightness
  * @retval None
  */
void DrawText(uint8_t Com, uint8_t Ch, uint32_t Bright, uint32_t Mode)
{
  uint16_t segpattern = segs[Com];
  uint8_t mapping =  digitCodeMap[GetDigitCodeIdx(Ch)];
  int i = 0;
  uint16_t mask = 1;
	
	uint8_t temp = mapping;
#if 0	//FJ5161BH
	mapping = 0;
	for(i=0; i<8; i++)
	{
		mapping += ((temp & 0x1)<<(7-i));
		temp >>= 1;
	}
#else //5161BS
#endif 
  for(i=0; i<SEGMENT_MAX; i++)
  { 
    if(segpattern & (((uint32_t)0x01UL)<<i))
    {
      if (mapping & mask)
      {
        WriteScreen(Com, i, HAL_LED_PackSegData(&hled1, Com, i, Bright));
      }
			else
			{
				if(Mode == LED_TEXT_MODE_REWRITE)
				{
				    WriteScreen(Com, i, HAL_LED_PackSegData(&hled1, Com, i, 0));
				}
			}
      mask <<= 1; 
    }
  }
}

/**
  * @brief  Dispaly dot.
  * @param  Com common index
  * @param  Seg segment index
  * @param  Bright Display brightness
  * @retval None
  */
void DrawDot(uint8_t Com, uint8_t Seg, uint32_t Bright)
{
  WriteScreen(Com, Seg, HAL_LED_PackSegData(&hled1, Com, Seg, Bright));
}

/**
  * @brief  Dispaly character with 7-segment in LED->BUFF.
  * @param  Com common index
  * @param  Ch character
  * @param  Bright Display brightness
  * @retval None
  */
void DrawTextDirect(uint8_t Com, uint8_t Ch, uint32_t Bright, uint32_t Mode)
{
  uint16_t segpattern = segs[Com];
  uint8_t mapping =  digitCodeMap[GetDigitCodeIdx(Ch)];
  int i = 0;
  uint16_t mask = 1;
#if 0	//FJ5161BH	
	uint8_t temp = mapping;
	mapping = 0;
	for(i=0; i<8; i++)
	{
		mapping += ((temp & 0x1)<<(7-i));
		temp >>= 1;
	}
#else  //5161BS
#endif	
  for(i=0; i<SEGMENT_MAX; i++)
  { 
    if(segpattern & (((uint32_t)0x01UL)<<i))
    {
      if (mapping & mask)
      {
        WriteBuff(Com, i, HAL_LED_PackSegData(&hled1, Com, i, Bright));
      }
			else
			{
				if(Mode == LED_TEXT_MODE_REWRITE)
				{
				    WriteBuff(Com, i, HAL_LED_PackSegData(&hled1, Com, i, 0));
				}
			}
      mask <<= 1; 
    }
  }
}

/**
  * @brief  Dispaly dot in LED->BUFF.
  * @param  Com common index
  * @param  Seg segment index
  * @param  Bright Display brightness
  * @retval None
  */
void DrawDotDirect(uint8_t Com, uint8_t Seg, uint32_t Bright)
{
	WriteBuff(Com, Seg, HAL_LED_PackSegData(&hled1, Com, Seg, Bright));
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
  if(UpdateFrameCount > 0)
  {
    //new screen
    if(UpdateFrameIdx >= UpdateFrameCount)
    {
      src_fr = UpdateFrameIdx- UpdateFrameCount;
    }
    else
    {
      src_fr = ScrBufFrameNum + UpdateFrameIdx - UpdateFrameCount;
    }

    memcpy(RefreshFramePattern, ScrBufFrameRefreshMask, 16);
  }
  else 
  {
    if(RefreshFramePattern[0] || RefreshFramePattern[1] || RefreshFramePattern[2] || RefreshFramePattern[3])
    {
      //refresh used screen 
      if(UpdateFrameIdx)
      {
        src_fr = UpdateFrameIdx -1;
      }
      else
      {
        src_fr = ScrBufFrameNum - 1;
      }
    }
    else
    {
      return 1;
    }
  }

  src_addr = src_fr*ScrBufFrameSize*4;

  /* calculate destination frame*/
  /* get current display frame */
  c_fr = __HAL_LED_GET_DISPLAY_FRAME_INDEX(&hled1);
	//c_fr = c_fr % ScrBufFrameNum;
	
  if(c_fr < ScrBufFrameNum - 1)
  {
    c_update_fr = c_fr + 1;
  }
  else
  {
    c_update_fr = 0;
  }

  if(UpdateFrameCount == 0)
  {
    //check refresh pattern
		uint32_t pidx = (c_update_fr >> 5);
		uint32_t ppos = (c_update_fr - (pidx << 5));
    if ((((uint32_t)0x01UL << ppos) & RefreshFramePattern[pidx]) == 0) 
    {
      //no display refresh
      return 2;
    }
  }

  /* calculate display frame address */
  dst_addr = c_update_fr*ScrBufFrameSize*4;

  RefreshedFrame = c_update_fr;
  *pSrc = src_addr;
  *pDst = dst_addr;

  return 0;
}

/**
  * @brief  Update screen buffer adn display buffer refresh infomation.
  * @param  None
  * @retval None
  */
void TransferCompleted(void)
{
	uint32_t pidx = (RefreshedFrame >> 5);
	uint32_t ppos = (RefreshedFrame - (pidx << 5));

  /*update Update frame and refresh pattern */
  if(UpdateFrameCount) 
	{
		UpdateFrameCount = UpdateFrameCount-1;
	}
  if(RefreshFramePattern[pidx]) 
	{
		RefreshFramePattern[pidx] &= (~((uint32_t)0x01UL << ppos));
	}
}

/**
  * @brief  Update screen buffer adn display buffer refresh infomation.
  * @param  None
  * @retval None
  */
void CreateFrameMask(uint32_t FrameNum)
{
	uint32_t i = (FrameNum >> 5);
	
	int j = 0;
	
	for(j = 0; j < 4; j++)
	{
		if(j < i)
		{
			ScrBufFrameRefreshMask[j] = 0xFFFFFFFF;
		}
		else if(j == i)
		{
			ScrBufFrameRefreshMask[j] = (((uint32_t)0x01UL << (FrameNum - (i << 5))) - 1);
		}
		else
		{
			ScrBufFrameRefreshMask[j] = 0;
		}
	}
}

/**
  * @brief  Display in screen buffer.
  * @param  Com common index
  * @param  Seg Segment index
  * @param  Data Segment data
  * @retval None
  */
void WriteBuff(uint32_t Com, uint32_t Seg, uint32_t Data)
{
  if (hled1.Init.Display_Mode == LED_RMODE_BRIGHT)
  {
    uint32_t framebase = UpdateFrameIdx*(ScrBufFrameSize);
    uint32_t comoffset = HAL_LED_GetBufferComIndex(&hled1, Com)*5;
    uint32_t segoffset = Seg>>1;
  
    uint32_t tmp = *(hled1.Init.pScreen_Buffer+(framebase + comoffset + segoffset));  //LED->BUFF[framebase + comoffset + segoffset];
    tmp &= ~(0xFFFF << (16*(Seg&0x01)));
    tmp |= (Data << (16*(Seg&0x01)));
    LED->BUFF[framebase + comoffset + segoffset] = tmp;
		*(hled1.Init.pScreen_Buffer+(framebase + comoffset + segoffset)) = tmp;
  }
  else
  {
	  uint32_t comidx = HAL_LED_GetBufferComIndex(&hled1, Com);
    uint32_t framebase = UpdateFrameIdx*(ScrBufFrameSize);
    uint32_t comoffset = comidx >> 1;
    uint32_t segoffset = 1 << Seg;
  
    uint32_t tmp = *(hled1.Init.pScreen_Buffer+(framebase + comoffset));  //LED->BUFF[framebase + comoffset];
    tmp &= ~(segoffset << (16*(comidx&0x01)));
    tmp |= ((Data)  << (16*(comidx&0x01)));
    LED->BUFF[framebase + comoffset] = tmp;
		*(hled1.Init.pScreen_Buffer+(framebase + comoffset)) = tmp;
  }
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
