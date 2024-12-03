/**
  ******************************************************************************
  * @file    xt32h0xx_led.c
  * @author  Software Team
  * @date    29 November 2022
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_led.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */
/** @defgroup LED LED
  * @brief LED driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup LED_Private_Functions LED Private Functions
  * @{
  */
/**
  * @brief  calculate the number of COM.
  * @param  ComEn COM enable
  * @retval uint32_t unmber of COM
  */
uint32_t LED_GetComNumber(uint32_t ComEn)
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
  * @brief  Compute COMx matched index in display buffer.
  * @param  ComPattern 
  * @param  ComIdx COM index (0-7)
  * @retval buffer COM matched index
  */
uint32_t LED_GetBufferComIndex(uint32_t ComPattern, uint32_t ComIdx)
{
  uint32_t res = 1;
  uint32_t mask = 1;

  int i;
  for(i=0; i<ComIdx; i++)
  {
    if(mask & ComPattern)
    {
      res++;
    }
    mask <<= 1;
  }

  return (res-1);
}

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup LED_Exported_Functions LED Exported Functions
  * @{
  */

/**
  * @brief  LED initialization.
  * @param  LED_InitStruct
  */
void LED_Init(LED_InitTypeDef* LED_InitStruct)
{
  uint32_t tmp = RCC_GetPCLKClock() / ((LED_GetComNumber(LED_InitStruct->ComEnable))*(256+LED_InitStruct->DeadTime)) / LED_InitStruct->ScanFeq;
  
  LED->CFG &= (uint32_t)(~(LED_CFG_PSC|LED_CFG_DTW));
  LED->CFG |= (tmp|(LED_InitStruct->DeadTime << LED_CFG_DTW_Pos));

  LED->CTRL &= (uint32_t)(~(LED_CTRL_SE|LED_CTRL_CE|LED_CTRL_ITRIM));
  LED->CTRL |= (LED_InitStruct->ComEnable|LED_InitStruct->SegEnable|LED_InitStruct->CurrentBias);

  LED->MODE &= (uint32_t)(~(LED_MODE_DMD|LED_MODE_RMD|LED_MODE_BRTS));
  LED->MODE |= (LED_InitStruct->DisplayMode | (LED_InitStruct->BrightStep <<LED_MODE_BRTS_Pos));
}

/**
  * @brief  LED struct init.
  * @param  LED_InitStruct
  */
void LED_StructInit(LED_InitTypeDef* LED_InitStruct)
{
  LED_InitStruct->ComEnable    = LED_COMALL;
  LED_InitStruct->SegEnable    = LED_SEGALL;
  LED_InitStruct->ScanFeq      = 60;
  LED_InitStruct->DisplayMode  = LED_MODE_RMD;   /* Brightness mode */
  LED_InitStruct->DeadTime     = 2;
  LED_InitStruct->CurrentBias  = 0;
  LED_InitStruct->BrightStep   = 16;
}

/**
  * @brief  LED ser ananlog command.
  * @param  Cmd
  */
void LED_AnalogCmd(uint32_t Cmd)
{
  if (Cmd != DISABLE)
  {
    LED->CTRL |= LED_CTRL_ON;
  }
  else
  {
    LED->CTRL &= (uint32_t)(~(LED_CTRL_ON));
  }
}

/**
  * @brief  LED set command.
  * @param  Cmd
  */
void LED_Cmd(uint32_t Cmd)
{
  if (Cmd != DISABLE)
  {
    LED->EG |= LED_EG_UG;
    //enable interrupt
    LED->CTRL |= LED_CTRL_FIE;
    LED->CTRL |= (LED_CTRL_LEDEN); 
  }
  else
  {
    LED->CTRL &= ~(LED_CTRL_FIE);
    LED->CTRL &= ~(LED_CTRL_LEDEN); 
  }
}

/**
  * @brief  LED Set Frame buffer size.
  * @param  Size
  */
void LED_SetFrameBufferSize(uint32_t Size)
{
  LED->MODE &= (uint32_t)(~(LED_MODE_ALAST));
  LED->MODE |= (Size-1);
}

/**
  * @brief  LED Set running mode.
  * @param  Mode Operation mode
  *         This parameter van be one of the following values:
  *         @arg @ref LED_DMODE_NORMAL 
  *         @arg @ref LED_DMODE_DIMMING 
  * @param  Step Dimming step
  *         This parameter van be one of the following values:
  *         @arg @ref LED_DIMMING_STEP_16 
  *         @arg @ref LED_DIMMING_STEP_8 
  *         @arg @ref LED_DIMMING_STEP_4 
  *         @arg @ref LED_DIMMING_STEP_2 
  *         @arg @ref LED_DIMMING_STEP_1 
  * @param  Interpolator Dimming interpolator
  *         This parameter van be one of [0, 255]
  */
void LED_SetRunningMode(uint32_t Mode, uint32_t Step, uint32_t Interpolator)
{
  LED->MODE &= (~(LED_MODE_DMD|LED_MODE_DIMS));
  LED->MODE |= Mode|Step;
  LED->CFG &=(~(LED_CFG_IFN));
  LED->CFG |= (Interpolator << LED_CFG_IFN_Pos);
}

/**
  * @brief  LED set maximum bright.
  * @param  Brights Bright maximum value
  *         This parameter van be one of [0, 31]
  */
void LED_SetMaximumBright(uint32_t* Brights)
{
  LED->BRG1 = (*Brights) +
              (*(Brights+1) << LED_BRG_BRT2_Pos) +
              (*(Brights+2) << LED_BRG_BRT3_Pos) +
              (*(Brights+3) << LED_BRG_BRT4_Pos);
  LED->BRG2 = (*(Brights+4)) +
              (*(Brights+5) << LED_BRG_BRT6_Pos) +
              (*(Brights+6) << LED_BRG_BRT7_Pos) +
              (*(Brights+7) << LED_BRG_BRT8_Pos);
  LED->BRG3 = (*(Brights+8));
} 

/**
  * @brief  LED Set node.
  * @param  FrameIdx
  *         This parameter van be one of [0, 40]
  * @param  ComIdx
  *         This parameter van be one of [0, 7]
  * @param  SegIdx
  *         This parameter van be one of [0, 8]
  * @param  Bright
  *         This parameter van be one of [0, 31] for bright mode or [0, 1] for om-off mode
  */
void LED_SetNode(uint32_t FrameIdx, uint32_t ComIdx, uint32_t SegIdx, uint32_t Bright)
{
  uint32_t frameoffset;
  uint32_t comoffset;
  uint32_t segoffset;

  uint32_t* pDisplayBufHdr = (uint32_t*)&(LED->BUFF[0]);  //display buffer start
  uint32_t* pDisplayBuf = pDisplayBufHdr;

  uint32_t tmp;

  uint32_t mode = (LED->MODE & LED_MODE_RMD);
  uint32_t bcomidx = LED_GetBufferComIndex(LED->CTRL & LED_CTRL_CE, ComIdx);
  uint32_t comnumber = LED_GetComNumber(LED->CTRL & LED_CTRL_CE);

  if(mode == LED_RMODE_BRIGHT)
  {
    frameoffset = FrameIdx*(comnumber*5);
    comoffset = bcomidx*5;
    segoffset = SegIdx>>1;
    
    pDisplayBuf = pDisplayBufHdr + (frameoffset + comoffset + segoffset)*4;
    tmp = *(pDisplayBuf);
    tmp &= ~(0xFFFF << (16*(SegIdx&0x01)));
    tmp |= (Bright << (16*(SegIdx&0x01)));
    *pDisplayBuf = tmp;
  }
  else
  {
    frameoffset = FrameIdx * ((ComIdx >> 1) + (ComIdx & 1));
    comoffset = ComIdx >> 1;
    segoffset = 1 << SegIdx;

    pDisplayBuf = pDisplayBufHdr + (frameoffset + comoffset)*4;
    tmp = *pDisplayBuf;
    tmp &= ~(segoffset << (16*(ComIdx&0x01)));
    tmp |= ((Bright) << (16*(ComIdx&0x01)));
    *pDisplayBuf = tmp;
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

