/**
  ******************************************************************************
  * @file    xt32h0xx_rtc.c
  * @author  Software Team
  * @date    23 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of RTCr 
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
#include "xt32h0xx_rtc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup RTC RTC
  * @brief RTC driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup RTC_Exported_Functions RTC Exported Functions
  * @{
  */

/** @defgroup RTC_Exported_Functions_Group1 Configuration functions
 *  @brief   Configuration functions 
 *
@verbatim
 ===============================================================================
                     ##### RTC configuration functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Deinitializes RTC peripheral registers to their default reset values.
  */
void RTC_DeInit(void)
{
  RTC->CCR &= (uint32_t)~((uint32_t)RTC_CCR_EN);
}

/**
  * @brief  Set match value for counter.
  * @param  RTC_MatchValue:
  */
void RTC_SetMatchValue( uint32_t RTC_MatchValue)
{
 RTC->CMR = (uint32_t)RTC_MatchValue;
}

/**
  * @brief  Set load value for counter.
  * @param  RTC_LoadValue:
  */
void RTC_SetLoadValue( uint32_t RTC_LoadValue)
{
 RTC->CLR = (uint32_t)RTC_LoadValue;
}

/**
  * @brief  Enable RTC wrap.
  */
void RTC_EnableWrap(void)
{
  RTC->CCR |= (uint32_t)RTC_CCR_WEN;
}

/**
  * @brief  Disable RTC wrap.
  */
void RTC_DisableWrap(void)
{
  RTC->CCR &= (uint32_t)~((uint32_t)RTC_CCR_WEN);
}

/**
  * @}
  */

/** @defgroup RTC_Exported_Functions_Group2 RTC operation functions
 *  @brief   RTC operation functions
 *
@verbatim
 ===============================================================================
                     ##### RTC opertaion functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief Timer enable.
  */
void RTC_Enable(void)
{
  RTC->CCR |= (uint32_t)RTC_CCR_EN;
}

/**
  * @brief Timer disable.
  */
void RTC_Disable(void)
{
  RTC->CCR &= (uint32_t)~((uint32_t)RTC_CCR_EN);
}

/**
  * @brief  Get timer current counter value
  * @retval 32-bit Value
  */
uint32_t RTC_GetCurrentValue(void)
{
  return (RTC->CCVR);
}

/**
  * @}
  */

/** @defgroup RTC_Exported_Functions_Group3 RTC interrupt management functions
 *  @brief   RTCR interrupt management functions
 *
@verbatim
 ===============================================================================
                     ##### RTC interrupt management functions #####
 ===============================================================================

@endverbatim
  * @{
  */
/**
  * @brief Enable interrupt.
  */
void RTC_EnableIT(void)
{
  RTC->CCR |= (uint32_t)RTC_CCR_IEN;
}

/**
  * @brief Disable interrupt.
  */
void RTC_DisableIT(void)
{
  RTC->CCR &= (uint32_t)~((uint32_t)RTC_CCR_IEN);
}

/**
  * @brief Mask interrupt.
  */
void RTC_MaskIT(void)
{
  RTC->CCR |= (uint32_t)RTC_CCR_MASK;
}

/**
  * @brief Unmask  interrupt.
  */
void RTC_UnmaskIT(void)
{
  RTC->CCR &= (uint32_t)~((uint32_t)RTC_CCR_MASK);
}

/**
  * @brief Clear interrupt.
  * @retval 0
  */
uint32_t RTC_ClearIT(void)
{
  return (uint32_t) RTC->EOI; 
}

/**
  * @brief Get  interrupt flag.
  * @retval flag 1 or 0
  */
uint32_t RTC_GetITFlag(void)
{
  return (uint32_t) RTC->STAT; 
}

/**
  * @brief Get timer interrupt status.
  * @retval flag  
  */
uint32_t RTC_GetITStatus(void)
{
  return (uint32_t)RTC->RSTAT; 
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

