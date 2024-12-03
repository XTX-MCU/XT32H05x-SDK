/**
  ******************************************************************************
  * @file    xt32h0xx_timr.c
  * @author  Software Team
  * @date    23 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of basic timer 
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
#include "xt32h0xx_timr.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup TIMR TIMR
  * @brief TIMR driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup TIMR_Exported_Functions Basic Timer Exported Functions
  * @{
  */

/** @defgroup TIMR_Exported_Functions_Group1 Configuration  functions
 *  @brief   Configuration functions 
 *
@verbatim
 ===============================================================================
                     ##### TIMR configuration functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Deinitializes TIMR peripheral registers to their default reset values.
  */
void TIMR_DeInit(TIMR_TypeDef *TIMx)
{
  TIMx->CR &= (uint32_t)~((uint32_t)TIMR_CR_EN);
}

/**
  * @brief  Set load value for counter.
  * @param  TIMx
  * @param  TIMR_LoadValue:
  */
void TIMR_SetLoadValue(TIMR_TypeDef *TIMx, uint32_t TIMR_LoadValue)
{
  TIMx->LC = (uint32_t)TIMR_LoadValue;
}

/**
  * @brief  Set timer mode.
  * @param  TIMx
  * @param  TIMR_Mode:
  */
void TIMR_SetMode(TIMR_TypeDef *TIMx, uint32_t TIMR_Mode)
{
  uint32_t tempr = TIMx->CR;

  tempr &= (uint32_t)~((uint32_t)TIMR_CR_MODE);
  tempr |= (uint32_t)TIMR_Mode;

  TIMx->CR = tempr;
}

/**
  * @}
  */

/** @defgroup TIMR_Exported_Functions_Group2 TIMR operation functions
 *  @brief   TIMR operation functions
 *
@verbatim
 ===============================================================================
                     ##### TIMR opertaion functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief Timer enable.
  * @param TIMx 
  */
void TIMR_Enable(TIMR_TypeDef *TIMx)
{
  TIMx->CR |= (uint32_t)TIMR_CR_EN;
}

/**
  * @brief Timer disable.
  * @param TIMx 
  */
void TIMR_Disable(TIMR_TypeDef *TIMx)
{
  TIMx->CR &= (uint32_t)~((uint32_t)TIMR_CR_EN);
}

/**
  * @brief Timer start.
  * @param TIMx 
  */
void TIMR_Start(TIMR_TypeDef *TIMx)
{
  TIMx->CR |= (uint32_t)TIMR_CR_EN;
}

/**
  * @brief Timer stop.
  * @param TIMx 
  */
void TIMR_Stop(TIMR_TypeDef *TIMx)
{
  TIMx->CR &= (uint32_t)~((uint32_t)TIMR_CR_EN);
}

/**
  * @brief  Get timer current counter value
  * @param  TIMx:
  * @retval 32-bit Value
  */
uint32_t TIMR_GetCurrentValue(TIMR_TypeDef *TIMx)
{
  return (TIMx->CV);
}

/**
  * @}
  */

/** @defgroup TIMR_Exported_Functions_Group3 TIMR interrupt management functions
 *  @brief   TIMR interrupt management functions
 *
@verbatim
 ===============================================================================
                     ##### TIMR interrupt management functions #####
 ===============================================================================

@endverbatim
  * @{
  */
/**
  * @brief Mask time interrupt.
  * @param TIMx 
  */
void TIMR_MaskIT(TIMR_TypeDef *TIMx)
{
  TIMx->CR |= (uint32_t)TIMR_CR_IM;
}

/**
  * @brief Unmask time interrupt.
  * @param TIMx 
  */
void TIMR_UnmaskIT(TIMR_TypeDef *TIMx)
{
  TIMx->CR &= (uint32_t)~((uint32_t)TIMR_CR_IM);
}

/**
  * @brief Clear timer interrupt.
  * @param TIMx 
  * @retval 0
  */
uint32_t TIMR_ClearIT(TIMR_TypeDef *TIMx)
{
  return (uint32_t) TIMx->EOI; 
}

/**
  * @brief Get timer interrupt flag.
  * @param TIMx 
  * @retval flag 1 or 0
  */
uint32_t TIMR_GetITGlag(TIMR_TypeDef *TIMx)
{
  return (uint32_t) TIMx->STAT; 
}

/**
  * @brief Get timer channel interrupt flag.
  * @param TIMx 
  * @retval flag  CHANNEL_x
  */
uint32_t TIMR_GetChannleFlag(TIMR_TypeDef *TIMx)
{
  return (uint32_t)((TIMR_GET_TIMRSYS(TIMx))->STAT & TIMR_GET_TIMRCHANNEL(TIMx));
}

/**
  * @brief Get timer channel interrupt status without masked.
  * @param TIMx 
  * @retval flag CHANNEL_x
  */
uint32_t TIMR_GetChannleStatus(TIMR_TypeDef *TIMx)
{
  return (uint32_t)((TIMR_GET_TIMRSYS(TIMx))->RSTAT & TIMR_GET_TIMRCHANNEL(TIMx));
}

/**
  * @brief Clear timer channel interrupt flag.
  * @param TIMx 
  * @retval 0
  */
uint32_t TIMR_ClearChannleAllFlag(TIMR_TypeDef *TIMx)
{
  return (uint32_t)(TIMR_GET_TIMRSYS(TIMx))->EOI;
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

/**
  * @}
  */

