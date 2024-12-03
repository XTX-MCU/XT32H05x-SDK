/**
  ******************************************************************************
  * @file    xt32h0xx_hal_led.c
  * @author  Software Team
  * @brief   LED HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of LED (LED) peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
//#include <string.h>
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup LED LED
  * @brief LED HAL module driver.
  * @{
  */

#ifdef HAL_LED_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup  LED_Private_Macros LED Private Macros
  * @{
  */

#define IS_LED_MODE(MODE)              (((MODE) == LED_MODE_SIMPLE)     || \
                                        ((MODE) == LED_MODE_BRIGHTNESS))

/**
  * @}
  */
/* Private variables ---------------------------------------------------------*/
/** @defgroup  LED_Private_Variables LED Private Variables
  * @{
  */
//static const uint32_t aSegStrt[4][LED_SEG_MAX_NUM-1] = {
//  {0, 255,  1, 254,   2, 253,   3, 252},
//  {0, 255, 64, 192,   1, 254,  65, 191},
//  {0, 255, 64, 192, 128, 128,   1, 254},
//  {0, 255, 64, 192, 128, 128, 192,  64}
//};

static const uint32_t aSegStrt[4][LED_SEG_MAX_NUM-1] = {
  {0, 255, 0, 255, 0, 255, 0, 255},
  {0, 255, 0, 255, 0, 255, 0, 255},
  {0, 255, 0, 255, 0, 255, 0, 255},
  {0, 255, 0, 255, 0, 255, 0, 255}
};
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup LED_Private_Functions LED Private Functions
  * @{
  */
static uint32_t LED_SegStartPositionCalc(LED_HandleTypeDef *hled, uint32_t Com_Idx, uint32_t Seg_Idx, uint32_t Seg_Wd);

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @addtogroup LED_Exported_Functions LED Exported Functions
  * @{
  */

/** @addtogroup LED_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions.
  *
@verbatim
 ===============================================================================
            ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Initialize the LED according to the specified parameters
          in the LED_InitTypeDef and create the associated handle
      (+) DeInitialize the LED peripheral
      (+) Initialize the LED MSP (MCU Specific Package)
      (+) DeInitialize the LED MSP

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the LED according to the specified
  *         parameters in the LED_InitTypeDef and create the associated handle.
  * @param  hled LED handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LED_Init(LED_HandleTypeDef *hled)
{
//  int i;

  uint32_t tmp = 0;

  uint32_t frame, frame_size;


  /* Check the LED handle allocation */
  if (hled == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_LED_ALL_INSTANCE(hled->Instance));

  if (hled->State == HAL_LED_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hled->Lock = HAL_UNLOCKED;
#if (USE_HAL_LED_REGISTER_CALLBACKS == 1U)
    /* Init the LED Callback settings */
    hled->TfrCpltCallback       = HAL_LED_TfrCpltCallback;       /* Legacy weak TxCpltCallback       */
    hled->ErrorCallback        = HAL_LED_ErrorCallback;        /* Legacy weak ErrorCallback        */
    hled->AbortCpltCallback    = HAL_LED_AbortCpltCallback;    /* Legacy weak AbortCpltCallback    */

    if (hled->MspInitCallback == NULL)
    {
      hled->MspInitCallback = HAL_SPI_MspInit; /* Legacy weak MspInit  */
    }

    /* Init the low level hardware : GPIO, CLOCK, NVIC... */
    hled->MspInitCallback(hspi);
#else
    /* Init the low level hardware */
    HAL_LED_MspInit(hled);
#endif    
  }

  hled->State = HAL_LED_STATE_BUSY;

  /* Configure prescaler & dead time */
  tmp = HAL_RCC_GetPCLKFreq() / (HAL_LED_GetComNumber(hled->Init.ComEnable) * (256+hled->Init.Dead_Time)) / hled->Init.Scan_Feq;
  MODIFY_REG(hled->Instance->CFG, LED_CFG_PSC|LED_CFG_DTW, tmp|(hled->Init.Dead_Time << LED_CFG_DTW_Pos));

  /* SEG COM enable*/
  MODIFY_REG(hled->Instance->CTRL, LED_CTRL_SE|LED_CTRL_CE, (hled->Init.ComEnable | hled->Init.SegEnable));

  /* current bias */
  MODIFY_REG(hled->Instance->CTRL, LED_CTRL_ITRIM, hled->Init.Current_Bias << LED_CTRL_ITRIM_Pos);

  /* Configure run mode & display mode, brightness step */
  MODIFY_REG(hled->Instance->MODE, LED_MODE_DMD|LED_MODE_RMD|LED_MODE_BRTS, 
             hled->Init.Display_Mode | (hled->Init.Bright_Step << LED_MODE_BRTS_Pos));

  /* Configure display buffer*/
  
  if(hled->Init.Display_Mode == LED_RMODE_ONOFF)
  {
		tmp = HAL_LED_GetComIdxMax(hled->Init.ComEnable);
    frame_size = ( tmp >> 1) + (tmp & 0x01);
		if(tmp == 0) frame_size = 1;
    frame = 128/frame_size;
  }
  else
  {
		tmp = HAL_LED_GetComNumber(hled->Init.ComEnable);
    frame_size = (tmp*5);
    frame = 128/frame_size;
  }
  MODIFY_REG(hled->Instance->MODE, LED_MODE_ALAST, ((frame*frame_size-1)<<LED_MODE_ALAST_Pos));

  /* Configure DMA*/
  if(hled->hdma != NULL)
  {
//    HAL_DMA_Start_IT(hled->hdma, (uint32_t)hled->Init.pScreen_Buffer, (uint32_t)&(hled->Instance->BUFF[0]), 8 /*(uint32_t)frame_size*/);

    //SET_BIT(hled->Instance->CTRL, LED_CTRL_FDE);
  }

  /* initial display buffer */
  //memcpy((uint32_t*)&(hled->Instance->BUFF[0]), (uint32_t*)hled->Init.pScreen_Buffer, frame*frame_size);
	
	if(hled->Init.pScreen_Buffer != 0)
	{
		hled->pShadow = hled->Init.pScreen_Buffer;
	}

  /* config SEG brightness maximum */
  hled->Instance->BRG1 = (hled->Init.SegBright_Max[3] << LED_BRG_BRT3_Pos) +
                         (hled->Init.SegBright_Max[2] << LED_BRG_BRT2_Pos) +
                         (hled->Init.SegBright_Max[1] << LED_BRG_BRT1_Pos) +
                         hled->Init.SegBright_Max[0];
  hled->Instance->BRG2 = (hled->Init.SegBright_Max[7] << LED_BRG_BRT7_Pos) +
                         (hled->Init.SegBright_Max[6] << LED_BRG_BRT6_Pos) +
                         (hled->Init.SegBright_Max[5] << LED_BRG_BRT5_Pos) +
                         hled->Init.SegBright_Max[4];
  hled->Instance->BRG3 = hled->Init.SegBright_Max[8];

  /* Enable interrupt*/
  SET_BIT(hled->Instance->CTRL, LED_CTRL_FIE);

  /* Change LED peripheral state */
  hled->State = HAL_LED_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  DeInitialize the LED peripheral.
  * @param  hled LED handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LED_DeInit(LED_HandleTypeDef *hled)
{
  /* Check the LED handle allocation */
  if (hled == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_LED_ALL_INSTANCE(hled->Instance));

  /* Check the LED peripheral state */
  if (hled->State == HAL_LED_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Change LED peripheral state */
  hled->State = HAL_LED_STATE_BUSY;

//  /* Reset LED calculation unit */
//  __HAL_LED_RESET(hcrc);
  /* LED off */
	CLEAR_BIT(hled->Instance->CTRL, LED_CTRL_FIE);
	READ_REG(hled->Instance->STATUS);
	
	hled->pShadow = 0;
  
#if (USE_HAL_LED_REGISTER_CALLBACKS == 1U)
    /* DeInit the LED Callback settings */
    if (hled->MspDeInitCallback == NULL)
    {
      hled->MspDeInitCallback = HAL_LED_MspDeInit; /* Legacy weak MspInit  */
    }

    /* DeInit the low level hardware : GPIO, CLOCK, NVIC... */
    hled->MspDeInitCallback(hspi);
#else
  /* DeInit the low level hardware */
  HAL_LED_MspDeInit(hled);
#endif
  /* Change LED peripheral state */
  hled->State = HAL_LED_STATE_RESET;

  /* Process unlocked */
  __HAL_UNLOCK(hled);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Configure LED DMA handshaking interface.
  * @param  hled LED handle
  * @param  hdma DMA handle
  * @param  dmaif DMA handshaking interface
  * @param  dmaifcfg DMA handshaking interface configure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LED_DMAHSIFConfig(LED_HandleTypeDef *hled, DMA_HandleTypeDef *hdma, 
                                         uint32_t dmaif, uint32_t dmaifcfg)
{
	uint32_t mask = 0;
	if(hled == NULL) return HAL_ERROR;
	
	if(hdma != NULL)
	{
		mask = 3UL << (dmaif<<1);
		SYSCFG->DMA_CFG &= ~(mask);   
		SYSCFG->DMA_CFG |= ((dmaifcfg & 0x3) << (dmaif<<1));
#if defined(XT32H0xxB)    
		SYSCFG->DMA_CFG_2 &= ~(mask);   
		SYSCFG->DMA_CFG_2 |= (((dmaifcfg & 0xC) >>2) << (dmaif<<1));
#endif /* XT32H0xxB */

    hdma->Instance->CFG_L &= ~(DMA_CH_CHCFG_DSTHSPOL|DMA_CH_CHCFG_DSTHS);  //DST_HS_POL = 0; HS_SEL_DST = 0
	  hdma->Instance->CFG_H &= ~(DMA_CH_CHCFG_DSTPER);
    hdma->Instance->CFG_H |= (dmaif << DMA_CH_CHCFG_DSTPER_Pos); 
	}

	return HAL_OK;
}

/**
  * @brief  link LED DMA.
  * @param  hled LED handle
  * @param  hdma DMA handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LED_LinkDMA(LED_HandleTypeDef *hled, DMA_HandleTypeDef *hdma)
{
	if(hled == NULL) return HAL_ERROR;
	
	if(hdma != NULL)
	{
    hled->hdma = hdma;
		hdma->Parent = hled;
	}

	return HAL_OK;
}

/**
  * @brief  Initializes the LED MSP.
  * @param  hled LED handle
  */
__weak void HAL_LED_MspInit(LED_HandleTypeDef *hled)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hled);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LED_MspInit can be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the LED MSP.
  * @param  hled LED handle
  */
__weak void HAL_LED_MspDeInit(LED_HandleTypeDef *hled)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hled);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LED_MspDeInit can be implemented in the user file
   */
}

/**
  * @brief  LED analog on.
  * @param  hled LED handle
  */
void HAL_LED_AnaOn(LED_HandleTypeDef *hled)
{
	SET_BIT(hled->Instance->CTRL, LED_CTRL_ON);
}

/**
  * @brief  LED analog off.
  * @param  hled LED handle
  */
void HAL_LED_AnaOff(LED_HandleTypeDef *hled)
{
	CLEAR_BIT(hled->Instance->CTRL, LED_CTRL_ON);
}

#if (USE_HAL_LED_REGISTER_CALLBACKS == 1)
/**
  * @brief  LED register call back.
  * @param  hled LED handle
  * @param  CallbackID callback ID
  * @param  pCallback  call function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LED_RegisterCallback(LED_HandleTypeDef *hled, HAL_LED_CallbackIDTypeDef CallbackID,
                                            pLED_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
 //   hled->ErrorCode |= HAL_LED_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hled);

  if (HAL_LED_STATE_READY == hled->State)
  {
    switch (CallbackID)
    {
      case HAL_LED_TFR_COMPLETE_CB_ID :
        hled->TfrCpltCallback = pCallback;
        break;

      case HAL_LED_ERROR_CB_ID :
        hled->ErrorCallback = pCallback;
        break;

      case HAL_LED_ABORT_CB_ID :
        hled->AbortCpltCallback = pCallback;
        break;

      case HAL_LED_MSPINIT_CB_ID :
        hled->MspInitCallback = pCallback;
        break;

      case HAL_LED_MSPDEINIT_CB_ID :
        hled->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        //SET_BIT(hled->ErrorCode, HAL_LED_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_LED_STATE_RESET == hled->State)
  {
    switch (CallbackID)
    {
      case HAL_LED_MSPINIT_CB_ID :
        hled->MspInitCallback = pCallback;
        break;

      case HAL_LED_MSPDEINIT_CB_ID :
        hled->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        SET_BIT(hled->ErrorCode, HAL_LED_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    //SET_BIT(hled->ErrorCode, HAL_LED_ERROR_INVALID_CALLBACK);

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hled);
  return status;
}

/**
  * @brief  LED unregister call back.
  * @param  hled LED handle
  * @param  CallbackID callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_LED_UnRegisterCallback(LED_HandleTypeDef *hled, HAL_LED_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hled);

  if (HAL_LED_STATE_READY == hled->State)
  {
    switch (CallbackID)
    {
      case HAL_LED_TFR_COMPLETE_CB_ID :
        hled->TfrCpltCallback = HAL_LED_TfrCpltCallback;             /* Legacy weak TfrCpltCallback       */
        break;

      case HAL_LED_ERROR_CB_ID :
        hled->ErrorCallback = HAL_LED_ErrorCallback;               /* Legacy weak ErrorCallback        */
        break;

      case HAL_LED_ABORT_CB_ID :
        hled->AbortCpltCallback = HAL_LED_AbortCpltCallback;       /* Legacy weak AbortCpltCallback    */
        break;

      case HAL_LED_MSPINIT_CB_ID :
        hled->MspInitCallback = HAL_LED_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_LED_MSPDEINIT_CB_ID :
        hled->MspDeInitCallback = HAL_LED_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        //SET_BIT(hled->ErrorCode, HAL_LED_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_LED_STATE_RESET == hled->State)
  {
    switch (CallbackID)
    {
      case HAL_LED_MSPINIT_CB_ID :
        hled->MspInitCallback = HAL_LED_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_LED_MSPDEINIT_CB_ID :
        hled->MspDeInitCallback = HAL_LED_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        //SET_BIT(hled->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    //SET_BIT(hled->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hspi);
  return status;
}

#endif /* USE_HAL_LED_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup LED_Exported_Functions_Group2 Peripheral Control functions
  *  @brief    management functions.
  *
  * @{
  */

/**
  * @brief  LED on.
  * @param  hled LED handle
  */
void HAL_LED_On(LED_HandleTypeDef *hled)
{
  hled->Instance->EG |= (uint32_t)(LED_EG_UG);
  hled->Instance->CTRL |= (uint32_t)(LED_CTRL_LEDEN);
}

/**
  * @brief  LED off.
  * @param  hled LED handle
  */
void HAL_LED_Off(LED_HandleTypeDef *hled)
{
  hled->Instance->CTRL &= (uint32_t)~LED_CTRL_LEDEN;
}

/**
  * @brief  Set LED operation mode.
  * @param  hled LED handle
  * @param  Mode LED operation mode. the value is one of the following list
  *         @arg @ref LED_DMODE_NORMAL
  *         @arg @ref LED_DMODE_DIMMING
  * @param  Step LED dimming step
  *         @arg @ref LED_DIMMING_STEP_16
  *         @arg @ref LED_DIMMING_STEP_8
  *         @arg @ref LED_DIMMING_STEP_4
  *         @arg @ref LED_DIMMING_STEP_2
  *         @arg @ref LED_DIMMING_STEP_1
  * @param  Interpolator LED interpolator
  */
void HAL_LED_SetRunningMode(LED_HandleTypeDef *hled, uint32_t Mode, uint32_t Step, uint32_t Interpolator)
{
  MODIFY_REG(hled->Instance->MODE, LED_MODE_DMD|LED_MODE_DIMS, Mode|Step);
  MODIFY_REG(hled->Instance->CFG, LED_CFG_IFN, Interpolator << LED_CFG_IFN_Pos);
}

/**
  * @brief  LED on.
  * @param  hled LED handle
  * @param  SegIdx segment index
  * @param  Step brightness change step (0,1,2,4,8)
  * @param  Count brightness count (maximum, count to maximum)
  */
void HAL_LED_SetSegMaxBright(LED_HandleTypeDef *hled, uint32_t SegIdx, uint32_t Step, uint32_t Count)
{
  uint32_t* pReg = (uint32_t*)(&(hled->Instance->BRG1) + ((SegIdx >> 2) << 2));
  uint32_t pos = (SegIdx & 0x03 << 8);
  *pReg &= ~(0x000000FF<<pos);
  *pReg |= (Count<<pos);
  MODIFY_REG(hled->Instance->MODE, LED_MODE_BRTS, Step);
 }

/**
  * @brief  Compute COMx matched index in display buffer.
  * @param  hled LED handle
  * @param  ComIdx COM index (0-7)
  * @retval buffer COM matched index
  */
uint32_t HAL_LED_GetBufferComIndex(LED_HandleTypeDef *hled, uint32_t ComIdx)
{
  uint32_t res = 1;
  uint32_t mask = 1;

  int i;
  for(i=0; i<ComIdx; i++)
  {
    if(mask & hled->Init.ComEnable)
    {
      res++;
    }
    mask <<= 1;
  }

  return (res-1);
}

/**
  * @brief  Compute segment data in FIFO format.
  * @param  hled LED handle
  * @param  FrameIdx frame index in display buffer
  * @param  ComIdx COM index (0-7)
  * @param  SegIdx Segment index (0-8)
  * @param  Data Segment data
  */
void HAL_LED_SetNode(LED_HandleTypeDef *hled, uint32_t FrameIdx, uint32_t ComIdx, uint32_t SegIdx, uint32_t Data)
{
  uint32_t frameoffset;
  uint32_t comoffset;
  uint32_t segoffset;

  uint32_t* pDisplayBufHdr = (uint32_t*)&(hled->Instance->BUFF[0]);  //display buffer start
  uint32_t* pDisplayBuf = pDisplayBufHdr;
	
	uint32_t* pShadowBuf = hled->pShadow;

  uint32_t tmp;

  uint32_t mode = hled->Init.Display_Mode;
  uint32_t bcomidx = HAL_LED_GetBufferComIndex(hled, ComIdx);
  uint32_t comnumber = HAL_LED_GetComNumber(hled->Init.ComEnable);
	
	if(pShadowBuf == 0)
	{
		return; //no shadow buffer 
	}

  if(mode == LED_RMODE_BRIGHT)
  {
    frameoffset = FrameIdx*(comnumber*5);
    comoffset = bcomidx*5;
    segoffset = SegIdx>>1;
    
    pDisplayBuf = pDisplayBufHdr + (frameoffset + comoffset + segoffset);
		pShadowBuf = hled->pShadow + (frameoffset + comoffset + segoffset);
    tmp = *(pShadowBuf);
    tmp &= ~(0xFFFF << (16*(SegIdx&0x01)));
    tmp |= (Data << (16*(SegIdx&0x01)));
    *pDisplayBuf = tmp;
		*pShadowBuf = tmp;
  }
  else
  {
    frameoffset = FrameIdx * ((ComIdx >> 1) + (ComIdx & 1));
    comoffset = ComIdx >> 1;
    segoffset = 1 << SegIdx;

    pDisplayBuf = pDisplayBufHdr + (frameoffset + comoffset);
		pShadowBuf = hled->pShadow + (frameoffset + comoffset);
    tmp = *pShadowBuf;
    tmp &= ~(segoffset << (16*(ComIdx&0x01)));
    tmp |= ((Data) << (16*(ComIdx&0x01)));
    *pDisplayBuf = tmp;
		*pShadowBuf = tmp;
  }
}

/**
  * @brief  Compute segment data in FIFO format.
  * @param  hled LED handle
  * @param  ComIdx COM index (0-7)
  * @param  SegIdx Segment index (0-8)
  * @param  SegWd Segment data (brighthness or on-off)
  * @retval uint32_t Segment data in FIFO format (start_position (8bits)| stop_position (8bits) or seg_onoff)
  */
uint32_t HAL_LED_PackSegData(LED_HandleTypeDef *hled, uint32_t ComIdx, uint32_t SegIdx, uint32_t SegWd)
{
  uint32_t start;
  uint32_t res = (uint32_t) SegWd;
	
	uint32_t BrightnessCount = hled->Init.SegBright_Max[SegIdx]/hled->Init.Bright_Step + 1;
	
	if(res == 0) return res;

  if (hled->Init.Display_Mode == LED_RMODE_BRIGHT)
  {
    start = LED_SegStartPositionCalc(hled, ComIdx, SegIdx, res);
	res = start + res - BrightnessCount;  /* stop position */
    res = (start << 8)|res; /* start_position | stop_position */
  }
  else
  {
    res = (SegWd << SegIdx);
  }

  return res;
}

/**
  * @brief  calculate the number of COM.
  * @param  ComEn COM enable
  * @retval uint32_t unmber of COM
  */
uint32_t HAL_LED_GetComNumber(uint32_t ComEn)
{
  uint32_t cnt = 0;
  uint32_t tmp = ComEn;

  while(tmp)
  {
    if(tmp & 0x01) cnt++;
    tmp >>= 1;
  }

  return cnt;
}

/**
  * @brief  calculate the max index of COM enable.
  * @param  ComEn COM enable
  * @retval uint32_t the max index of COM
  */
uint32_t HAL_LED_GetComIdxMax(uint32_t ComEn)
{
  uint32_t cnt = 0;
  uint32_t tmp = ComEn;
	
	uint32_t mask = (uint32_t) ((uint32_t) 0x01 << (LED_COM_MAX_NUM - 1));

  while(tmp)
  {
    if(tmp & mask) break;
		cnt++;
    mask >>= 1;
  }

  return (LED_COM_MAX_NUM - cnt - 1);
}

/**
  * @}
  */

/** @addtogroup LED_Exported_Functions_Group3 Peripheral State functions
  *  @brief    Peripheral State functions.
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State functions #####
 ===============================================================================
    [..]
    This subsection permits to get in run-time the status of the peripheral.

@endverbatim
  * @{
  */

/**
  * @brief  Return the LED handle state.
  * @param  hled LED handle
  * @retval HAL state
  */
HAL_LED_StateTypeDef HAL_LED_GetState(LED_HandleTypeDef *hled)
{
  /* Return LED handle state */
  return hled->State;
}

/**
  * @}
  */

/** @addtogroup LED_Exported_Functions_Group4
  *  @brief   IRQ_handler and callbacks functions.
  *
  * @{
  */
/**
  * @brief  Led IRQ handler.
  * @param  hled LED handle
  */
__weak void HAL_LED_IRQHandler(LED_HandleTypeDef *hled)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hled);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LED_IRQHandler can be implemented in the user file
   */
}

/**
  * @brief  Led frame completed call back.
  * @param  hled LED handle
  */
__weak void HAL_LED_TfrTxCpltCallback(LED_HandleTypeDef *hled)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hled);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LED_TfrTxCpltCallback can be implemented in the user file
   */
}

/**
  * @brief  Led error call back.
  * @param  hled LED handle
  */
__weak void HAL_LED_ErrorCallback(LED_HandleTypeDef *hled)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hled);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LED_ErrorCallback can be implemented in the user file
   */
}

/**
  * @brief  Led abort completed call back.
  * @param  hled LED handle
  */
__weak void HAL_LED_AbortCpltCallback(LED_HandleTypeDef *hled)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hled);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_LED_AbortCpltCallback can be implemented in the user file
   */
}
/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup LED_Private_Functions
  * @{
  */

/**
  * @brief  calculate start position of segment pulse in .
  *         Specific data handling to optimize processing time.
  * @param  hled LED handle
  * @param  Com_Idx COM index
  * @param  Seg_Idx SEG index
  * @param  Seg_Wd SEG pulse width
  * @retval uint32_t start position of SEG pulse
  */
static uint32_t LED_SegStartPositionCalc(LED_HandleTypeDef *hled, uint32_t Com_Idx, uint32_t Seg_Idx, uint32_t Seg_Wd)
{
  uint32_t rng, idx;

  uint32_t res = 0;

  if(Seg_Wd >= 192)
  {
    rng = 0;
  }
  else if(Seg_Wd >= 128)
  {
    rng = 1;
  }
  else if(Seg_Wd >= 64)
  {
    rng = 2;
  }
  else
  {
    rng = 3;
  }

  if(Seg_Idx < Com_Idx)
  {
    idx = Seg_Idx;
  }
  else
  {
    idx = Seg_Idx - 1;
  }

  if(idx & 0x01)
  {
    res = aSegStrt[rng][idx] - Seg_Wd;
  }
  else
  {
    res = aSegStrt[rng][idx];
  }

  return res;
}

/**
  * @}
  */

#endif /* HAL_LED_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
