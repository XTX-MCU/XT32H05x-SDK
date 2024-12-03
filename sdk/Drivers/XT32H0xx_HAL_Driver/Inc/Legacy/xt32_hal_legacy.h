/**
  ******************************************************************************
  * @file    xt32_hal_legacy.h
  * @author  Software Team
  * @brief   This file contains aliases definition for the HAL constants
  *          macros and functions maintained for legacy purpose.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32_HAL_LEGACY
#define XT32_HAL_LEGACY

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup HAL_CORTEX_Aliased_Defines HAL CORTEX Aliased Defines maintained for legacy purpose
  * @{
  */
#define __HAL_CORTEX_SYSTICKCLK_CONFIG HAL_SYSTICK_CLKSourceConfig
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Defines HAL TIM Aliased Defines maintained for legacy purpose
  * @{
  */
#define CCER_CCxE_MASK                   TIM_CCER_CCxE_MASK
#define CCER_CCxNE_MASK                  TIM_CCER_CCxNE_MASK

#define TIM_DMABase_CR1                  TIM_DMABASE_CR1
#define TIM_DMABase_CR2                  TIM_DMABASE_CR2
#define TIM_DMABase_SMCR                 TIM_DMABASE_SMCR
#define TIM_DMABase_DIER                 TIM_DMABASE_DIER
#define TIM_DMABase_SR                   TIM_DMABASE_SR
#define TIM_DMABase_EGR                  TIM_DMABASE_EGR
#define TIM_DMABase_CCMR1                TIM_DMABASE_CCMR1
#define TIM_DMABase_CCMR2                TIM_DMABASE_CCMR2
#define TIM_DMABase_CCER                 TIM_DMABASE_CCER
#define TIM_DMABase_CNT                  TIM_DMABASE_CNT
#define TIM_DMABase_PSC                  TIM_DMABASE_PSC
#define TIM_DMABase_ARR                  TIM_DMABASE_ARR
#define TIM_DMABase_RCR                  TIM_DMABASE_RCR
#define TIM_DMABase_CCR1                 TIM_DMABASE_CCR1
#define TIM_DMABase_CCR2                 TIM_DMABASE_CCR2
#define TIM_DMABase_CCR3                 TIM_DMABASE_CCR3
#define TIM_DMABase_CCR4                 TIM_DMABASE_CCR4
#define TIM_DMABase_BDTR                 TIM_DMABASE_BDTR
#define TIM_DMABase_DCR                  TIM_DMABASE_DCR
#define TIM_DMABase_DMAR                 TIM_DMABASE_DMAR
#define TIM_DMABase_OR1                  TIM_DMABASE_OR1
#define TIM_DMABase_CCMR3                TIM_DMABASE_CCMR3
#define TIM_DMABase_CCR5                 TIM_DMABASE_CCR5
#define TIM_DMABase_CCR6                 TIM_DMABASE_CCR6
#define TIM_DMABase_OR2                  TIM_DMABASE_OR2
#define TIM_DMABase_OR3                  TIM_DMABASE_OR3
#define TIM_DMABase_OR                   TIM_DMABASE_OR

#define TIM_EventSource_Update           TIM_EVENTSOURCE_UPDATE
#define TIM_EventSource_CC1              TIM_EVENTSOURCE_CC1
#define TIM_EventSource_CC2              TIM_EVENTSOURCE_CC2
#define TIM_EventSource_CC3              TIM_EVENTSOURCE_CC3
#define TIM_EventSource_CC4              TIM_EVENTSOURCE_CC4
#define TIM_EventSource_COM              TIM_EVENTSOURCE_COM
#define TIM_EventSource_Trigger          TIM_EVENTSOURCE_TRIGGER
#define TIM_EventSource_Break            TIM_EVENTSOURCE_BREAK
#define TIM_EventSource_Break2           TIM_EVENTSOURCE_BREAK2

#define TIM_DMABurstLength_1Transfer     TIM_DMABURSTLENGTH_1TRANSFER
#define TIM_DMABurstLength_2Transfers    TIM_DMABURSTLENGTH_2TRANSFERS
#define TIM_DMABurstLength_3Transfers    TIM_DMABURSTLENGTH_3TRANSFERS
#define TIM_DMABurstLength_4Transfers    TIM_DMABURSTLENGTH_4TRANSFERS
#define TIM_DMABurstLength_5Transfers    TIM_DMABURSTLENGTH_5TRANSFERS
#define TIM_DMABurstLength_6Transfers    TIM_DMABURSTLENGTH_6TRANSFERS
#define TIM_DMABurstLength_7Transfers    TIM_DMABURSTLENGTH_7TRANSFERS
#define TIM_DMABurstLength_8Transfers    TIM_DMABURSTLENGTH_8TRANSFERS
#define TIM_DMABurstLength_9Transfers    TIM_DMABURSTLENGTH_9TRANSFERS
#define TIM_DMABurstLength_10Transfers   TIM_DMABURSTLENGTH_10TRANSFERS
#define TIM_DMABurstLength_11Transfers   TIM_DMABURSTLENGTH_11TRANSFERS
#define TIM_DMABurstLength_12Transfers   TIM_DMABURSTLENGTH_12TRANSFERS
#define TIM_DMABurstLength_13Transfers   TIM_DMABURSTLENGTH_13TRANSFERS
#define TIM_DMABurstLength_14Transfers   TIM_DMABURSTLENGTH_14TRANSFERS
#define TIM_DMABurstLength_15Transfers   TIM_DMABURSTLENGTH_15TRANSFERS
#define TIM_DMABurstLength_16Transfers   TIM_DMABURSTLENGTH_16TRANSFERS
#define TIM_DMABurstLength_17Transfers   TIM_DMABURSTLENGTH_17TRANSFERS
#define TIM_DMABurstLength_18Transfers   TIM_DMABURSTLENGTH_18TRANSFERS

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup HAL_TIM_Aliased_Functions HAL TIM Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_TIM_DMADelayPulseCplt                       TIM_DMADelayPulseCplt
#define HAL_TIM_DMAError                                TIM_DMAError
#define HAL_TIM_DMACaptureCplt                          TIM_DMACaptureCplt
#define HAL_TIMEx_DMACommutationCplt                    TIMEx_DMACommutationCplt
#define HAL_TIM_SlaveConfigSynchronization              HAL_TIM_SlaveConfigSynchro
#define HAL_TIM_SlaveConfigSynchronization_IT           HAL_TIM_SlaveConfigSynchro_IT
#define HAL_TIMEx_CommutationCallback                   HAL_TIMEx_CommutCallback
#define HAL_TIMEx_ConfigCommutationEvent                HAL_TIMEx_ConfigCommutEvent
#define HAL_TIMEx_ConfigCommutationEvent_IT             HAL_TIMEx_ConfigCommutEvent_IT
#define HAL_TIMEx_ConfigCommutationEvent_DMA            HAL_TIMEx_ConfigCommutEvent_DMA
/**
  * @}
  */

/* Exported macros ------------------------------------------------------------*/

/** @defgroup HAL_TIM_Aliased_Macros HAL TIM Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_TIM_SetICPrescalerValue   TIM_SET_ICPRESCALERVALUE
#define __HAL_TIM_ResetICPrescalerValue TIM_RESET_ICPRESCALERVALUE

#define TIM_GET_ITSTATUS                __HAL_TIM_GET_IT_SOURCE
#define TIM_GET_CLEAR_IT                __HAL_TIM_CLEAR_IT

#define __HAL_TIM_GET_ITSTATUS          __HAL_TIM_GET_IT_SOURCE

#define __HAL_TIM_DIRECTION_STATUS      __HAL_TIM_IS_TIM_COUNTING_DOWN
#define __HAL_TIM_PRESCALER             __HAL_TIM_SET_PRESCALER
#define __HAL_TIM_SetCounter            __HAL_TIM_SET_COUNTER
#define __HAL_TIM_GetCounter            __HAL_TIM_GET_COUNTER
#define __HAL_TIM_SetAutoreload         __HAL_TIM_SET_AUTORELOAD
#define __HAL_TIM_GetAutoreload         __HAL_TIM_GET_AUTORELOAD
#define __HAL_TIM_SetClockDivision      __HAL_TIM_SET_CLOCKDIVISION
#define __HAL_TIM_GetClockDivision      __HAL_TIM_GET_CLOCKDIVISION
#define __HAL_TIM_SetICPrescaler        __HAL_TIM_SET_ICPRESCALER
#define __HAL_TIM_GetICPrescaler        __HAL_TIM_GET_ICPRESCALER
#define __HAL_TIM_SetCompare            __HAL_TIM_SET_COMPARE
#define __HAL_TIM_GetCompare            __HAL_TIM_GET_COMPARE

#define TIM_BREAKINPUTSOURCE_DFSDM  TIM_BREAKINPUTSOURCE_DFSDM1
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32_HAL_LEGACY */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

