/**
  ******************************************************************************
  * @file    xt32h0xx_padi.c
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of PADI 
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
#include "xt32h0xx_padi.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup PADI PADI
  * @brief PADI driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup PADI_Exported_Functions PADI Exported Functions
  * @{
  */

/**
  * @brief  Initialize PAD.
  * @param  PADI_InitStruct Initial strcut
  */
void PADI_Init(PADI_InitTypeDef *PADI_InitStruct)
{
  uint32_t tempr;
  uint32_t pos;
  uint32_t range;

  uint32_t pullup = PADI_InitStruct->Pull & PADI_PULLUP;
  uint32_t pulldown = ( PADI_InitStruct->Pull & PADI_PULLDOWN ) >> 1;

  uint32_t* padcfg;

  /*configure*/
  range = ((PADI_InitStruct->Pad >> 3) & 0x7);
  pos =  (PADI_InitStruct->Pad & 0x7) << 2;
  padcfg = ((uint32_t*)&(PADI->PORTMUX_CFG_1)) + range;

  tempr = *padcfg;
  tempr &= (uint32_t)~((uint32_t)(0xFUL << pos));
  tempr |= (uint32_t)(PADI_InitStruct->Alternate);
  *padcfg = tempr;

  /*pull and driver strength*/
  range = ( PADI_InitStruct->Pad & 0x20 ) >> 5;
  pos =  PADI_InitStruct->Pad & 0x1F;
  
  /*pull up*/
  padcfg = ((uint32_t*)&(PADI->IO_PULLUP_CFG_1)) + range;
  tempr = *padcfg;
  tempr &= (uint32_t)~((uint32_t)(1UL << pos));
  tempr |= (uint32_t)(pullup << pos);
  *padcfg = tempr;
  /*pull down*/
  padcfg = ((uint32_t*)&(PADI->IO_PULLDW_CFG_1)) + range;
  tempr = *padcfg;
  tempr &= (uint32_t)~((uint32_t)(1UL << pos));
  tempr |= (uint32_t)(pulldown << pos);
  *padcfg = tempr;

  /*driver strength*/
  padcfg = ((uint32_t*)&(PADI->IO_DS_CFG_1)) + range;
  tempr = *padcfg;
  tempr &= (uint32_t)~((uint32_t)(1UL << pos));
  tempr |= (uint32_t)(PADI_InitStruct->DriveStrength << pos);
  *padcfg = tempr;
}

/**
  * @brief  Initialize PAD struct.
  * @param  PADI_InitStruct Initial struct
  */
void PADI_StructInit(PADI_InitTypeDef *PADI_InitStruct) 
{
  PADI_InitStruct->Pad = 0;
  PADI_InitStruct->Pull = PADI_PULLNONE; 
  PADI_InitStruct->Alternate = PADI_CFG_0;
  PADI_InitStruct->DriveStrength = PADI_DS_LOW;
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

