/**
  ******************************************************************************
  * @file    xt32h0xx_hal_rcc.h
  * @author  Software Team
   * @brief   Header file of RCC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_RCC_H
#define XT32H0xx_HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"
#include "xt32h0xx_ll_rcc.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/* Private constants ---------------------------------------------------------*/
/** @addtogroup RCC_Private_Constants 
  * @{
  */
#define RCC_CLOCKTYPE_ALL              (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK)  /*!< All clocktype to configure */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup RCC_Private_Macros RCC Private Macros
  * @{
  */  
#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__)                                 \
  (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                           || \
   (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE) || \
   (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI) || \
   (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI) || \
   (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE))

#define IS_RCC_HSE(__HSE__)  (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON))

#define IS_RCC_LSE(__LSE__)  (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON))

#define IS_RCC_HSI(__HSI__)  (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON))

#define IS_RCC_LSI(__LSI__)  (((__HSI__) == RCC_LSI_OFF) || ((__HSI__) == RCC_LSI_ON))

#define IS_RCC_PLLN_VALUE(__VALUE__) ((0 <= (__VALUE__)) && ((__VALUE__) <= 127))

#define IS_RCC_PLLM_VALUE(__VALUE__) ((2 <= (__VALUE__)) && ((__VALUE__) <= 12))

#define IS_RCC_PLLR_VALUE(__VALUE__) ((4 <= (__VALUE__)) && ((__VALUE__) <= 24))

#define IS_RCC_CLOCKTYPE(__CLK__)  ((((__CLK__)\
                                      & RCC_CLOCKTYPE_ALL) != 0x00UL) && (((__CLK__) & ~RCC_CLOCKTYPE_ALL) == 0x00UL))

#if defined(XT32H0xxAMPW)
#define IS_RCC_PLLM(__VALUE__) (((__VALUE__) == RCC_PLLM_DIV2) || \
                                ((__VALUE__) == RCC_PLLM_DIV4) || \
                                ((__VALUE__) == RCC_PLLM_DIV8) || \
                                ((__VALUE__) == RCC_PLLM_DIV12))
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define IS_RCC_PLLM(__VALUE__) (((__VALUE__) == RCC_PLLM_DIV1) || \
                                ((__VALUE__) == RCC_PLLM_DIV2) || \
                                ((__VALUE__) == RCC_PLLM_DIV3) || \
                                ((__VALUE__) == RCC_PLLM_DIV4) || \
                                ((__VALUE__) == RCC_PLLM_DIV6) || \
                                ((__VALUE__) == RCC_PLLM_DIV8) || \
                                ((__VALUE__) == RCC_PLLM_DIV12) || \
                                ((__VALUE__) == RCC_PLLM_DIV24))
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

#if defined(XT32H0xxAMPW)
#define IS_RCC_PLLR(__VALUE__) (((__VALUE__) == RCC_PLLR_DIV4) || \
                                ((__VALUE__) == RCC_PLLR_DIV6) || \
                                ((__VALUE__) == RCC_PLLR_DIV8) || \
                                ((__VALUE__) == RCC_PLLR_DIV12) || \
                                ((__VALUE__) == RCC_PLLR_DIV16) || \
                                ((__VALUE__) == RCC_PLLR_DIV24))
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define IS_RCC_PLLR(__VALUE__) (((__VALUE__) == RCC_PLLR_DIV4) || \
                                ((__VALUE__) == RCC_PLLR_DIV6) || \
                                ((__VALUE__) == RCC_PLLR_DIV8) || \
                                ((__VALUE__) == RCC_PLLR_DIV12) || \
                                ((__VALUE__) == RCC_PLLR_DIV16) || \
                                ((__VALUE__) == RCC_PLLR_DIV24) || \
                                ((__VALUE__) == RCC_PLLR_DIV48))
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

#if defined(XT32H0xxAMPW)
#define IS_RCC_PLLN(__VALUE__) (((__VALUE__) == RCC_PLLN_DIV_FREQ_98M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_96M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_94M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_92M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_90M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_88M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_86M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_84M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_82M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_80M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_78M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_76M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_74M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_72M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_70M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_68M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_66M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_64M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_62M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_60M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_58M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_56M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_54M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_52M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_50M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_49M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_48M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_47M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_46M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_45M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_44M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_43M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_42M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_41M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_40M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_39M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_38M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_37M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_36M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_35M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_34M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_33M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_32M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_31M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_30M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_29M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_28M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_27M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_26M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_25M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_24M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_23M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_22M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_21M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_20M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_19M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_18M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_17M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_16M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_15M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_14M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_13M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_12M))
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define IS_RCC_PLLN(__VALUE__) (((__VALUE__) == RCC_PLLN_DIV_FREQ_99M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_98M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_97M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_96M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_95M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_94M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_93M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_92M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_91M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_90M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_89M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_88M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_87M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_86M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_85M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_84M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_83M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_82M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_81M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_80M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_79M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_78M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_77M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_76M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_75M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_74M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_73M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_72M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_71M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_70M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_69M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_68M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_67M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_66M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_65M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_64M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_62M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_60M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_58M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_56M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_54M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_52M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_50M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_49M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_48M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_47M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_46M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_45M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_44M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_43M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_42M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_41M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_40M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_39M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_38M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_37M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_36M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_35M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_34M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_33M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_32M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_31M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_30M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_29M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_28M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_27M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_26M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_25M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_24M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_23M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_22M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_21M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_20M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_19M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_18M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_17M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_16M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_15M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_14M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_13M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_12M) || \
                                ((__VALUE__) == RCC_PLLN_DIV_FREQ_11M))
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

#define IS_RCC_HCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_HCLKSOURCE_HSI) || \
                                       ((__SOURCE__) == RCC_HCLKSOURCE_HSE) || \
                                       ((__SOURCE__) == RCC_HCLKSOURCE_PLL) || \
                                       ((__SOURCE__) == RCC_HCLKSOURCE_LS))
																			 
#define IS_RCC_HCLK(__DIV__) ((0UL <= (__DIV__)) && ((__DIV__) <= 0xFFFFFFFFUL))
#define IS_RCC_PCLK(__DIV__) ((0UL <= (__DIV__)) && ((__DIV__) <= 0xFFFFFFFFUL))

#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
  ((((__SELECTION__) & RCC_PERIPHCLK_BR)     == RCC_PERIPHCLK_BR)  || \
   (((__SELECTION__) & RCC_PERIPHCLK_I2C)    == RCC_PERIPHCLK_I2C)    || \
   (((__SELECTION__) & RCC_PERIPHCLK_I2S)    == RCC_PERIPHCLK_I2S)    || \
   (((__SELECTION__) & RCC_PERIPHCLK_ADC)     == RCC_PERIPHCLK_ADC)     || \
   (((__SELECTION__) & RCC_PERIPHCLK_RTC)     == RCC_PERIPHCLK_RTC)     || \
   (((__SELECTION__) & RCC_PERIPHCLK_TIMA)    == RCC_PERIPHCLK_TIMA)    || \
   (((__SELECTION__) & RCC_PERIPHCLK_GPIO)    == RCC_PERIPHCLK_GPIO))

#define IS_RCC_I2CCLKSOURCE(__SOURCE__)   \
  (((__SOURCE__) == RCC_I2CCLKSOURCE_HSI)   || \
   ((__SOURCE__) == RCC_I2CCLKSOURCE_HSE)  || \
   ((__SOURCE__) == RCC_I2CCLKSOURCE_PLL))

#define IS_RCC_ADCCLKSOURCE(__SOURCE__)  \
  (((__SOURCE__) == RCC_ADCCLKSOURCE_HSI)  || \
   ((__SOURCE__) == RCC_ADCCLKSOURCE_HSE)  || \
   ((__SOURCE__) == RCC_ADCCLKSOURCE_PLL))

#define IS_RCC_BRCLKSOURCE(__SOURCE__)  \
  (((__SOURCE__) == RCC_BRCLKSOURCE_HSI)  || \
   ((__SOURCE__) == RCC_BRCLKSOURCE_HSE)  || \
   ((__SOURCE__) == RCC_BRCLKSOURCE_PLL))

#define IS_RCC_RTCCLKSOURCE(__SOURCE__)  \
  (((__SOURCE__) == RCC_LSCLOCKSOURCE_LSI)  || \
   ((__SOURCE__) == RCC_LSCLOCKSOURCE_LSE))

#define IS_RCC_WDTWCLKSOURCE(__SOURCE__)  \
  (((__SOURCE__) == RCC_WDTWCLKSOURCE_HSI)  || \
   ((__SOURCE__) == RCC_WDTWCLKSOURCE_HSE)  || \
   ((__SOURCE__) == RCC_WDTWCLKSOURCE_PLL))

#define IS_RCC_TIMB1CLKSOURCE(__SOURCE__)  \
  (((__SOURCE__) == RCC_TIMB1CLKSOURCE_HSI)  || \
   ((__SOURCE__) == RCC_TIMB1CLKSOURCE_HSE)  || \
   ((__SOURCE__) == RCC_TIMB1CLKSOURCE_PLL))

#define IS_RCC_TIMB2CLKSOURCE(__SOURCE__)  \
  (((__SOURCE__) == RCC_TIMB2CLKSOURCE_HSI)  || \
   ((__SOURCE__) == RCC_TIMB2CLKSOURCE_HSE)  || \
   ((__SOURCE__) == RCC_TIMB2CLKSOURCE_PLL))

#define IS_RCC_GPIOCLKSOURCE(__SOURCE__)  \
  (((__SOURCE__) == RCC_GPIOCLKSOURCE_HSI)  || \
   ((__SOURCE__) == RCC_GPIOCLKSOURCE_HSE)  || \
   ((__SOURCE__) == RCC_GPIOCLKSOURCE_PLL))

#define IS_RCC_TIMAGCLKSOURCE(__SOURCE__)  \
  (((__SOURCE__) == RCC_TIMAGCLKSOURCE_PCLK)  || \
   ((__SOURCE__) == RCC_TIMAGCLKSOURCE_HCLK)  || \
   ((__SOURCE__) == RCC_TIMAGCLKSOURCE_PLL))
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup RCC_Exported_Types RCC Exported Types
  * @{
  */

/**
  * @brief  RCC PLL configuration structure definition
  */
typedef struct
{
  uint32_t PLLState;   /*!< The new state of the PLL.
                            This parameter can be a value of @ref RCC_MCU_PLL_Status                      */

  uint32_t PLLSource;  /*!< RCC_PLLSource: PLL entry clock source.
                            This parameter must be a value of @ref RCC_PLL_Clock_Source               */

  uint32_t PLLM;       /*!< PLLM: Division factor for PLL VCO input clock.
                            This parameter must be a value of @ref RCC_PLLM_Clock_Divider                  */

  uint32_t PLLN;       /*!< PLLN: Multiplication factor for PLL VCO output clock.
                            This parameter must be a number between Min_Data = 8 and Max_Data = 86    */

  uint32_t PLLR;       /*!< PLLR: PLL Division for the main system clock.
                            User have to set the PLLR parameter correctly to not exceed max frequency 64MHZ.
                            This parameter must be a value of @ref RCC_PLLR_Clock_Divider             */

} RCC_PLLInitTypeDef;

/**
  * @brief  RCC Internal/External Oscillator (HSE, HSI, LSE and LSI) configuration structure definition
  */
typedef struct
{
  uint32_t OscillatorType;       /*!< The oscillators to be configured.
                                      This parameter can be a value of @ref RCC_Oscillator_Type                   */

  uint32_t HSEState;             /*!< The new state of the HSE.
                                      This parameter can be a value of @ref RCC_HSE_Status                        */

  uint32_t LSEState;             /*!< The new state of the LSE.
                                      This parameter can be a value of @ref RCC_LSE_Status                        */

  uint32_t HSIState;             /*!< The new state of the HSI.
                                      This parameter can be a value of @ref RCC_HSI_Status                        */

  uint32_t LSIState;             /*!< The new state of the LSI.
                                      This parameter can be a value of @ref RCC_LSI_Status                        */

  RCC_PLLInitTypeDef PLL;        /*!< Main PLL structure parameters                                               */

} RCC_OscInitTypeDef;

/**
  * @brief  RCC System, AHB and APB buses clock configuration structure definition
  */
typedef struct
{
  uint32_t ClockType;            /*!< The clock to be configured.
                                       This parameter can be a combination of @ref RCC_System_Clock_Type      */

  uint32_t SYSCLKSource;         /*!< The clock source used as system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_HCLK_Source    */

  uint32_t AHBCLKDivider;        /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of [0, 0xFFFFFFFF]       */

  uint32_t APBCLKDivider;        /*!< The APB clock (PCLK) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of [0, 0xFFFFFFFF] */


} RCC_ClkInitTypeDef;

/**
  * @brief  RCC extended clocks structure definition
  */
typedef struct
{
  uint32_t PeriphClockSelection;       /*!< The HClock to be configured.
                                        This parameter can be a value of @ref RCC_HCLK_Source */

  uint32_t BrClockSelection;           /*!< Specifies UART clock source.
                                        This parameter can be a value of @ref RCC_HCLK_Source */

  uint32_t I2cClockSelection;          /*!< Specifies I2C clock source
                                        This parameter can be a value of @ref RCC_I2C_Clock_Source */

  uint32_t AdcClockSelection;          /*!< Specifies ADC interface clock source
                                        This parameter can be a value of @ref RCC_ADC_Clock_Source */

  uint32_t TimerClockSelection;        /*!< Specifies Timer Clock clock source
                                         This parameter can be a value of @ref RCC_TIMAG_Clock_Source */

  uint32_t BaseTimer1ClockSelection;   /*!< Specifies Basic Timer Clock clock source
                                         This parameter can be a value of @ref RCC_TIMB1_Clock_Source */

  uint32_t BaseTimer2ClockSelection;   /*!< Specifies Basic Timer Clock clock source
                                         This parameter can be a value of @ref RCC_TIMB2_Clock_Source */

  uint32_t GpioClockSelection;         /*!< Specifies GPIO Clock clock source
                                         This parameter can be a value of @ref RCC_GPIO_Clock_Source */

  uint32_t RtcClockSelection;          /*!< Specifies RTC clock source.
                                        This parameter can be a value of @ref RCC_LS_Source */
  
	uint32_t WdtwClockSelection;         /*!< Specifies Watchdog Timer interface clock source
                                        This parameter can be a value of @ref RCC_WDTW_Clock_Source */
} RCC_PeriphCLKInitTypeDef;

/**
  * @brief  RCC System, deep sleep configuration structure definition
  */
typedef struct
{
  uint32_t ExternalWakeup;       /*!< External wakeup enable.
                                       This parameter can be one of @ref RCC_DeepSleep_External_Wakeup    */

  uint32_t TimerCount;           /*!< The deep sleep time.
                                       This parameter can be one of 1 to 0xFFFFFFFF       */

} RCC_DeepSleepInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @addtogroup RCC_Exported_Constants RCC Exported Constants
  * @{
  */
/** @defgroup RCC_System_Clock_Type System Clock Type
  * @{
  */
#define RCC_CLOCKTYPE_SYSCLK           (0x00000001U)  /*!< SYSCLK to configure */
#define RCC_CLOCKTYPE_HCLK             (0x00000002U)  /*!< HCLK to configure */
#define RCC_CLOCKTYPE_PCLK             (0x00000004U)  /*!< PCLK to configure */
/**
  * @}
  */

/** @defgroup RCC_Oscillator_Type Oscillator Type
  * @{
  */
#define RCC_OSCILLATORTYPE_NONE        (0x00000000U)  /*!< Oscillator configuration unchanged */
#define RCC_OSCILLATORTYPE_HSE         (0x00000001U)  /*!< HSXTAL to configure */
#define RCC_OSCILLATORTYPE_HSI         (0x00000002U)  /*!< HSRC to configure */
#define RCC_OSCILLATORTYPE_LSE         (0x00000004U)  /*!< LSXTAL to configure */
#define RCC_OSCILLATORTYPE_LSI         (0x00000008U)  /*!< LSRC to configure */
/**
  * @}
  */


/** @addtogroup RCC_MCU_PLL_Status PLL status
  * @{
  */
#define RCC_PLL_OFF                    (ICG_CLK_CTL_PLL)  
#define RCC_PLL_ON                     (0x00000000U)
/**
  * @}
  */

/** @addtogroup RCC_HSE_Status HSE Status
  * @{
  */
#define RCC_HSE_OFF                    (ICG_CLK_CTL_HSXTAL | ICG_CLK_CTL_HSXTALOUT) 
#define RCC_HSE_ON                     (0x00000000)
/**
  * @}
  */

/** @addtogroup RCC_HSE_Ouput_Status HSE Output Status
  * @{
  */
#define RCC_HSXTALOUT_DISABLE          (ICG_CLK_CTL_HSXTALOUT)  
#define RCC_HSXTALOUT_ENABLE           (0x00000000)
/**
  * @}
  */

/** @addtogroup RCC_HSI_Status HSI Status
  * @{
  */
#define RCC_HSI_OFF                    (ICG_CLK_CTL_HSRC)  
#define RCC_HSI_ON                     (0x00000000U)
/**
  * @}
  */

/** @addtogroup RCC_CLOCK_SOURCE
  * @{
  */
#define RCC_CLOCKSOURCE_HSI            (0x00000000U)  
#define RCC_CLOCKSOURCE_HSE            (0x00000001U)  
#define RCC_CLOCKSOURCE_PLL            (0x00000002U)  
#define RCC_CLOCKSOURCE_LS             (0x00000003U)  
/**
  * @}
  */

/** @addtogroup RCC_CLOCK_32K_SOURCE
  * @{
  */
#define RCC_LSCLOCKSOURCE_LSI          (0x00000000U)  
#define RCC_LSCLOCKSOURCE_LSE          (0x00000001U)  
/**
  * @}
  */

/** @defgroup RCC_PLL_Clock_Source PLL Clock Source
  * @{
  */
#define RCC_PLLSOURCE_HSI              (0)                          /*!< HSI clock selected as PLL entry clock source */
#define RCC_PLLSOURCE_HSE              (ICG_PLL_CLKSRC)             /*!< HSE clock selected as PLL entry clock source */
/**
  * @}
  */

/** @defgroup RCC_PLLN_Clock_Divider PLLN Feedback Divider
  * @{
  */
#if defined(XT32H0xxAMPW)
#define RCC_PLLN_DIV_FREQ_98M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_97M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_96M           ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_95M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_94M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_93M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_92M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_91M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_90M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_89M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_88M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_87M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_86M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_85M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_84M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_83M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_82M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_81M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_80M           ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_79M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_78M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_77M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_76M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_75M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_74M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_73M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_72M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_71M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_70M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_69M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_68M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
//#define RCC_PLLN_DIV_FREQ_67M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_66M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_64M           ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_62M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_60M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_58M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_56M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_54M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_52M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_50M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_49M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_48M           ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_47M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_46M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_45M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_44M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_43M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_42M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_41M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_40M           ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_39M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_38M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_37M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_36M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_35M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_34M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_33M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_32M           ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_31M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_30M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_29M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_28M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_27M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_26M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_25M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_24M           ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_23M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_22M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_21M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_20M           ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_19M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_18M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_17M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_16M           ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_15M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_14M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_13M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_12M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define RCC_PLLN_DIV_FREQ_99M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_98M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_97M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_96M           ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_95M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_94M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_93M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_92M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_91M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_90M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_89M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_88M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_87M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_86M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_85M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_84M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_83M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_82M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_81M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_80M           ( ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_79M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_78M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_77M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_76M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_75M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_74M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_73M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_72M           ( ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_71M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_70M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_69M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_68M           ( ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_67M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 )
#define RCC_PLLN_DIV_FREQ_66M           ( ICG_PLL_FBDIV_1 )
#define RCC_PLLN_DIV_FREQ_65M           ( ICG_PLL_FBDIV_0 )
#define RCC_PLLN_DIV_FREQ_64M           ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_62M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_60M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_58M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_56M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_54M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_52M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_50M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_49M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_48M           ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_47M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_46M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_45M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_44M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_43M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_42M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_41M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_40M           ( ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_39M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_38M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_37M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_36M           ( ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_35M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_34M           ( ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_33M           ( ICG_PLL_FBDIV_1 )
#define RCC_PLLN_DIV_FREQ_32M           ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_31M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_30M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_29M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_28M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_27M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_26M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_25M           ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_24M           ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_23M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_22M           ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_21M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_20M           ( ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_19M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_18M           ( ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_17M           ( ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_16M           ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_15M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_14M           ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_13M           ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_12M           ( ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_11M           ( ICG_PLL_FBDIV_1 )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @}
  */

/** @defgroup RCC_PLLM_Clock_Divider PLLM Pre-divider
  * @{
  */
#if defined(XT32H0xxAMPW) 
#define RCC_PLLM_DIV2                  (ICG_PLL_PREDIV_3)                                                               /*!< PLLM division factor = 1  */
#define RCC_PLLM_DIV4                  (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2)                                                               /*!< PLLM division factor = 2  */
#define RCC_PLLM_DIV8                  (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                                            /*!< PLLM division factor = 3  */
#define RCC_PLLM_DIV12                 (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_0)                                                               /*!< PLLM division factor = 4  */
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define RCC_PLLM_DIV1                  (0)                                                               /*!< PLLM division factor = 1  */
#define RCC_PLLM_DIV2                  (ICG_PLL_PREDIV_1)                                                               /*!< PLLM division factor = 1  */
#define RCC_PLLM_DIV3                  (ICG_PLL_PREDIV_0)                                                               /*!< PLLM division factor = 1  */
#define RCC_PLLM_DIV4                  (ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                                                               /*!< PLLM division factor = 2  */
#define RCC_PLLM_DIV6                  (ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)                                                               /*!< PLLM division factor = 2  */
#define RCC_PLLM_DIV8                  (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                                            /*!< PLLM division factor = 3  */
#define RCC_PLLM_DIV12                 (ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)                                                               /*!< PLLM division factor = 4  */
#define RCC_PLLM_DIV24                 (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)                                                               /*!< PLLM division factor = 4  */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

/* alias */
#define RCC_PLLM_DIV_HSI      RCC_PLLM_DIV4
#define RCC_PLLM_DIV_HSE_48M  RCC_PLLM_DIV12
#define RCC_PLLM_DIV_HSE_32M  RCC_PLLM_DIV8
#define RCC_PLLM_DIV_HSE_24M  RCC_PLLM_DIV6
#define RCC_PLLM_DIV_HSE_16M  RCC_PLLM_DIV4
#define RCC_PLLM_DIV_HSE_12M  RCC_PLLM_DIV3
#define RCC_PLLM_DIV_HSE_8M   RCC_PLLM_DIV2
#define RCC_PLLM_DIV_HSE_4M   RCC_PLLM_DIV1

/**
  * @}
  */

/** @defgroup RCC_PLLR_Clock_Divider PLLR Post Divider
  * @{
  */
#if defined(XT32H0xxAMPW)
#define RCC_PLLR_DIV4                  (ICG_PLL_POSTDIV_1)                                                               /*!< PLLM division factor = 1  */
#define RCC_PLLR_DIV6                  (ICG_PLL_POSTDIV_0)                                                               /*!< PLLM division factor = 2  */
#define RCC_PLLR_DIV8                  (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                                            /*!< PLLM division factor = 3  */
#define RCC_PLLR_DIV12                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1)                                                               /*!< PLLM division factor = 4  */
#define RCC_PLLR_DIV16                 (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3)                                                               /*!< PLLM division factor = 4  */
#define RCC_PLLR_DIV24                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                                                               /*!< PLLM division factor = 4  */
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define RCC_PLLR_DIV4                  (0)                                                               /*!< PLLM division factor = 1  */
#define RCC_PLLR_DIV6                  (ICG_PLL_POSTDIV_0)                                                               /*!< PLLM division factor = 2  */
#define RCC_PLLR_DIV8                  (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                                            /*!< PLLM division factor = 3  */
#define RCC_PLLR_DIV12                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1)                                                               /*!< PLLM division factor = 4  */
#define RCC_PLLR_DIV16                 (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3)                                                               /*!< PLLM division factor = 4  */
#define RCC_PLLR_DIV24                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                                                               /*!< PLLM division factor = 4  */
#define RCC_PLLR_DIV48                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3)                                                               /*!< PLLM division factor = 4  */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

#if defined(XT32H0xxAMPW)	
#define RCC_PLLR_DIV_FREQ_98M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_97M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_96M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_95M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_94M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_93M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_92M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_91M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_90M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_89M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_88M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_87M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_86M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_85M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_84M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_83M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_82M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_81M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_80M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_79M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_78M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_77M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_76M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_75M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_74M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_73M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_72M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_71M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_70M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_69M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_68M           ( ICG_PLL_POSTDIV_1 )
//#define RCC_PLLR_DIV_FREQ_67M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_66M           ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_64M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_62M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_60M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_58M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_56M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_54M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_52M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_50M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_49M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_48M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_47M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_46M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_45M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_44M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_43M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_42M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_41M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_40M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_39M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_38M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_37M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_36M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_35M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_34M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_33M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_32M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_31M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_30M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_29M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_28M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_27M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_26M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_25M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_24M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_23M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_22M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_21M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_20M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_19M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_18M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_17M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_16M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_15M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_14M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_13M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_12M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define RCC_PLLR_DIV_FREQ_99M           ( 0 )
#define RCC_PLLR_DIV_FREQ_98M           ( 0 )
#define RCC_PLLR_DIV_FREQ_97M           ( 0 )
#define RCC_PLLR_DIV_FREQ_96M           ( 0 )
#define RCC_PLLR_DIV_FREQ_95M           ( 0 )
#define RCC_PLLR_DIV_FREQ_94M           ( 0 )
#define RCC_PLLR_DIV_FREQ_93M           ( 0 )
#define RCC_PLLR_DIV_FREQ_92M           ( 0 )
#define RCC_PLLR_DIV_FREQ_91M           ( 0 )
#define RCC_PLLR_DIV_FREQ_90M           ( 0 )
#define RCC_PLLR_DIV_FREQ_89M           ( 0 )
#define RCC_PLLR_DIV_FREQ_88M           ( 0 )
#define RCC_PLLR_DIV_FREQ_87M           ( 0 )
#define RCC_PLLR_DIV_FREQ_86M           ( 0 )
#define RCC_PLLR_DIV_FREQ_85M           ( 0 )
#define RCC_PLLR_DIV_FREQ_84M           ( 0 )
#define RCC_PLLR_DIV_FREQ_83M           ( 0 )
#define RCC_PLLR_DIV_FREQ_82M           ( 0 )
#define RCC_PLLR_DIV_FREQ_81M           ( 0 )
#define RCC_PLLR_DIV_FREQ_80M           ( 0 )
#define RCC_PLLR_DIV_FREQ_79M           ( 0 )
#define RCC_PLLR_DIV_FREQ_78M           ( 0 )
#define RCC_PLLR_DIV_FREQ_77M           ( 0 )
#define RCC_PLLR_DIV_FREQ_76M           ( 0 )
#define RCC_PLLR_DIV_FREQ_75M           ( 0 )
#define RCC_PLLR_DIV_FREQ_74M           ( 0 )
#define RCC_PLLR_DIV_FREQ_73M           ( 0 )
#define RCC_PLLR_DIV_FREQ_72M           ( 0 )
#define RCC_PLLR_DIV_FREQ_71M           ( 0 )
#define RCC_PLLR_DIV_FREQ_70M           ( 0 )
#define RCC_PLLR_DIV_FREQ_69M           ( 0 )
#define RCC_PLLR_DIV_FREQ_68M           ( 0 )
#define RCC_PLLR_DIV_FREQ_67M           ( 0 )
#define RCC_PLLR_DIV_FREQ_66M           ( 0 )
#define RCC_PLLR_DIV_FREQ_65M           ( 0 )
#define RCC_PLLR_DIV_FREQ_64M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_62M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_60M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_58M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_56M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_54M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_52M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_50M           ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_49M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_48M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_47M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_46M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_45M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_44M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_43M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_42M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_41M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_40M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_39M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_38M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_37M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_36M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_35M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_34M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_33M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_32M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_31M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_30M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_29M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_28M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_27M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_26M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_25M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_24M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_23M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_22M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_21M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_20M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_19M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_18M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_17M           ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_16M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_15M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_14M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_13M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_12M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_11M           ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @}
  */


/** @defgroup RCC_VCOCAL_COMP_VL hysteresis
  * @{
  */
#define RCC_VCOCAL_COMP_VL_HYSTERESIS_NO       (0UL)
#define RCC_VCOCAL_COMP_VL_HYSTERESIS_MIN      (ICG_VCOCAL_COMPVL_0)
#define RCC_VCOCAL_COMP_VL_HYSTERESIS_MAX      (ICG_VCOCAL_COMPVL_1 | ICG_VCOCAL_COMPVL_0)
/**
  * @}
  */

/** @defgroup RCC_VCOCAL_COMP_VH Comparator Voltage Hysteresis
  * @{
  */
#define RCC_VCOCAL_COMP_VH_HYSTERESIS_NO       (0UL)
#define RCC_VCOCAL_COMP_VH_HYSTERESIS_MIN      (ICG_VCOCAL_COMPVH_0)
#define RCC_VCOCAL_COMP_VH_HYSTERESIS_MAX      (ICG_VCOCAL_COMPVH_1 | ICG_VCOCAL_COMPVH_0)
/**
  * @}
  */

/** @defgroup RCC_VCOCAL_IN_LOW_Range VCO input low range
  * @{
  */
#define RCC_VCOCAL_IN_RANGE_LOW_P20VDD        (0UL)
#define RCC_VCOCAL_IN_RANGE_LOW_P22VDD        (ICG_VCOCAL_IN_L_RNG_0)
#define RCC_VCOCAL_IN_RANGE_LOW_P24VDD        (ICG_VCOCAL_IN_L_RNG_1)
#define RCC_VCOCAL_IN_RANGE_LOW_P26VDD        (ICG_VCOCAL_IN_L_RNG_1 | ICG_VCOCAL_IN_L_RNG_0)
#define RCC_VCOCAL_IN_RANGE_LOW_P28VDD        (ICG_VCOCAL_IN_L_RNG_2)
#define RCC_VCOCAL_IN_RANGE_LOW_P30VDD        (ICG_VCOCAL_IN_L_RNG_2 | ICG_VCOCAL_IN_L_RNG_0)
#define RCC_VCOCAL_IN_RANGE_LOW_P32VDD        (ICG_VCOCAL_IN_L_RNG_2 | ICG_VCOCAL_IN_L_RNG_1)
#define RCC_VCOCAL_IN_RANGE_LOW_P34VDD        (ICG_VCOCAL_IN_L_RNG_2 | ICG_VCOCAL_IN_L_RNG_1 | ICG_VCOCAL_IN_L_RNG_0)
/**
  * @}
  */

/** @defgroup RCC_VCOCAL_IN_HIGH_Range VCO input high range
  * @{
  */
#define RCC_VCOCAL_IN_RANGE_HIGH_P66VDD       (0UL)
#define RCC_VCOCAL_IN_RANGE_HIGH_P68VDD       (ICG_VCOCAL_IN_HL_RNG_0)
#define RCC_VCOCAL_IN_RANGE_HIGH_P70VDD       (ICG_VCOCAL_IN_HL_RNG_1)
#define RCC_VCOCAL_IN_RANGE_HIGH_P72VDD       (ICG_VCOCAL_IN_HL_RNG_1 | ICG_VCOCAL_IN_H_RNG_0)
#define RCC_VCOCAL_IN_RANGE_HIGH_P74VDD       (ICG_VCOCAL_IN_HL_RNG_2)
#define RCC_VCOCAL_IN_RANGE_HIGH_P76VDD       (ICG_VCOCAL_IN_HL_RNG_2 | ICG_VCOCAL_IN_HL_RNG_0)
#define RCC_VCOCAL_IN_RANGE_HIGH_P78VDD       (ICG_VCOCAL_IN_HL_RNG_2 | ICG_VCOCAL_IN_HL_RNG_1)
#define RCC_VCOCAL_IN_RANGE_HIGH_P80VDD       (ICG_VCOCAL_IN_HL_RNG_2 | ICG_VCOCAL_IN_HL_RNG_1 | ICG_VCOCAL_IN_H_RNG_0)
/**
  * @}
  */

/** @defgroup RCC_VCOCAL_PLL_Stable_Time PLL Stable Time
  * @{
  */
#define RCC_VCOCAL_PLL_STABLE_32MS      (0UL)
#define RCC_VCOCAL_PLL_STABLE_48MS      (ICG_VCOCAL_STB_TM_0)
#define RCC_VCOCAL_PLL_STABLE_64MS      (ICG_VCOCAL_STB_TM_1)
#define RCC_VCOCAL_PLL_STABLE_96MS      (ICG_VCOCAL_STB_TM_1 | ICG_VCOCAL_STB_TM_0)
#define RCC_VCOCAL_PLL_STABLE_128MS     (ICG_VCOCAL_STB_TM_2)
#define RCC_VCOCAL_PLL_STABLE_160MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_0)
#define RCC_VCOCAL_PLL_STABLE_192MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_1)
#define RCC_VCOCAL_PLL_STABLE_256MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_1 | ICG_VCOCAL_STB_TM_0)
/**
  * @}
  */

/** @defgroup RCC_VCOCAL_Calibration_Time Calibration Time
  * @{
  */
#define RCC_VCOCAL_CALIBRATE_CNTG      (0UL)
#define RCC_VCOCAL_CALIBRATE_ONE       (ICG_VCOCAL_CAL_ITVL_0)
#define RCC_VCOCAL_CALIBRATE_10MS      (ICG_VCOCAL_CAL_ITVL_1)
#define RCC_VCOCAL_CALIBRATE_100MS     (ICG_VCOCAL_CAL_ITVL_1 | ICG_VCOCAL_CAL_ITVL_0)
#define RCC_VCOCAL_CALIBRATE_500MS     (ICG_VCOCAL_CAL_ITVL_2)
#define RCC_VCOCAL_CALIBRATE_1S        (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_0)
#define RCC_VCOCAL_CALIBRATE_5S        (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_1)
#define RCC_VCOCAL_CALIBRATE_10S       (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_1 | ICG_VCOCAL_CAL_ITVL_0)
/**
  * @}
  */

/** @defgroup RCC_Timer_Clock_Source Timer External Clock Source
  * @{
  */
#if defined(XT32H0xxB)
#define RCC_TIMERS_INTERNAL_CLOCK        (0)

#define RCC_TIMB11_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_0)
#define RCC_TIMB12_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_1)
#define RCC_TIMB13_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_2)
#define RCC_TIMB14_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_3)
#define RCC_TIMB21_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_4)
#define RCC_TIMB22_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_5)
#define RCC_TIMB23_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_6)
#define RCC_TIMB24_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_7)

#define RCC_TIMA1_CH1IN                  (ICG_TMXC_ATM1SRC_CH_0)
#define RCC_TIMA1_CH2IN                  (ICG_TMXC_ATM1SRC_CH_1)
#define RCC_TIMA1_CH3IN                  (ICG_TMXC_ATM1SRC_CH_2)
#define RCC_TIMA1_CH4IN                  (ICG_TMXC_ATM1SRC_CH_3)
#define RCC_TIMA1_ETR                    (ICG_TMXC_ATM1SRC_CH_4)

#define RCC_TIMA2_CH1IN                  (ICG_TMXC_ATM2SRC_CH_0)
#define RCC_TIMA2_CH2IN                  (ICG_TMXC_ATM2SRC_CH_1)
#define RCC_TIMA2_CH3IN                  (ICG_TMXC_ATM2SRC_CH_2)
#define RCC_TIMA2_CH4IN                  (ICG_TMXC_ATM2SRC_CH_3)
#define RCC_TIMA2_ETR                    (ICG_TMXC_ATM2SRC_CH_4)

#define RCC_TIMG1_CH1IN                  (ICG_TMXC_GTM1SRC_CH_0)
#define RCC_TIMG1_CH2IN                  (ICG_TMXC_GTM1SRC_CH_1)
#define RCC_TIMG1_CH3IN                  (ICG_TMXC_GTM1SRC_CH_2)
#define RCC_TIMG1_CH4IN                  (ICG_TMXC_GTM1SRC_CH_3)
#define RCC_TIMG1_ETR                    (ICG_TMXC_GTM1SRC_CH_4)

#define RCC_TIMG2_CH1IN                  (ICG_TMXC_GTM2SRC_CH_0)
#define RCC_TIMG2_CH2IN                  (ICG_TMXC_GTM2SRC_CH_1)
#define RCC_TIMG2_CH3IN                  (ICG_TMXC_GTM2SRC_CH_2)
#define RCC_TIMG2_CH4IN                  (ICG_TMXC_GTM2SRC_CH_3)
#define RCC_TIMG2_ETR                    (ICG_TMXC_GTM2SRC_CH_4)

#define RCC_TIMG3_CH1IN                  (ICG_TMXC_GTM3SRC_CH_0)
#define RCC_TIMG3_CH2IN                  (ICG_TMXC_GTM3SRC_CH_1)
#define RCC_TIMG3_CH3IN                  (ICG_TMXC_GTM3SRC_CH_2)
#define RCC_TIMG3_CH4IN                  (ICG_TMXC_GTM3SRC_CH_3)
#define RCC_TIMG3_ETR                    (ICG_TMXC_GTM3SRC_CH_4)

#define RCC_TIMG4_CH1IN                  (ICG_TMXC_GTM4SRC_CH_0)
#define RCC_TIMG4_CH2IN                  (ICG_TMXC_GTM4SRC_CH_1)
#define RCC_TIMG4_CH3IN                  (ICG_TMXC_GTM4SRC_CH_2)
#define RCC_TIMG4_CH4IN                  (ICG_TMXC_GTM4SRC_CH_3)
#define RCC_TIMG4_ETR                    (ICG_TMXC_GTM4SRC_CH_4)

#else 
#define RCC_TIMERS_INTERNAL_CLOCK        (0)

#define RCC_TIMB11_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_0)
#define RCC_TIMB12_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_1)
#define RCC_TIMB13_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_2)
#define RCC_TIMB14_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_3)
#define RCC_TIMB21_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_4)
#define RCC_TIMB22_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_5)
#define RCC_TIMB23_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_6)
#define RCC_TIMB24_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_7)

#define RCC_TIMG_CH1IN                   (ICG_TMXC_GTMSRC_CH_0)
#define RCC_TIMG_CH2IN                   (ICG_TMXC_GTMSRC_CH_1)
#define RCC_TIMG_CH3IN                   (ICG_TMXC_GTMSRC_CH_2)
#define RCC_TIMG_CH4IN                   (ICG_TMXC_GTMSRC_CH_3)
#define RCC_TIMG_ETR                     (ICG_TMXC_GTMSRC_CH_4)

#define RCC_TIMA_CH1IN                   (ICG_TMXC_ATMSRC_CH_0)
#define RCC_TIMA_CH2IN                   (ICG_TMXC_ATMSRC_CH_1)
#define RCC_TIMA_CH3IN                   (ICG_TMXC_ATMSRC_CH_2)
#define RCC_TIMA_CH4IN                   (ICG_TMXC_ATMSRC_CH_3)
#define RCC_TIMA_ETR                     (ICG_TMXC_ATMSRC_CH_4)
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @addtogroup RCC_LSI_Status LSI Status
  * @{
  */
#define RCC_LSI_OFF                    (AON_CLKCTRL_32KRC_PD)  
#define RCC_LSI_ON                     (0x00000000U)
/**
  * @}
  */

/** @addtogroup RCC_LSE_Status LSE Status
  * @{
  */
#define RCC_LSE_OFF                    (AON_CLKCTRL_32KXTAL_PD)  
#define RCC_LSE_ON                     (0x00000000U)
/**
  * @}
  */

/** @addtogroup RCC_LS_Source LS Source
  * @{
  */
#define RCC_LSSRC_LSI                  (0x0UL)
#define RCC_LSSRC_LSE                  (AON_CFG_32KCLKSRC_0)
/**
  * @}
  */

/** @defgroup RCC_Periph_Clock_Selection Periph Clock Selection
  * @{
  */
#define RCC_PERIPHCLK_BR               (0x00000001U)
#define RCC_PERIPHCLK_I2C1             (0x00000010U)
#define RCC_PERIPHCLK_I2C2             (0x00000020U)
#define RCC_PERIPHCLK_ADC              (0x00001000U)
#define RCC_PERIPHCLK_RTC              (0x00010000U)
#define RCC_PERIPHCLK_TIMAG            (0x00100000U)
#define RCC_PERIPHCLK_TIMB1            (0x00200000U)
#define RCC_PERIPHCLK_TIMB2            (0x00400000U)
#define RCC_PERIPHCLK_GPIO             (0x01000000U)
#define RCC_PERIPHCLK_WDTW             (0x10000000U)
/**
  * @}
  */

/** @defgroup RCC_SYSCLK_Source RCC System Clock Source
  * @{
  */
#define RCC_SYSCLKSOURCE_HSI          (0x00000000U)                                    /*!< HSI clock selected as System clock */
#define RCC_SYSCLKSOURCE_HSE          (ICG_CLK_CTL_HCLKSRC_0)                          /*!< HSE clock selected as System clock */
#define RCC_SYSCLKSOURCE_PLL          (ICG_CLK_CTL_HCLKSRC_1)                          /*!< PLL clock selected as System clock */
#define RCC_SYSCLKSOURCE_LS           (ICG_CLK_CTL_HCLKSRC_0| ICG_CLK_CTL_HCLKSRC_1)   /*!< LS clock selected as System clock */
/**
  * @}
  */

/** @defgroup RCC_HCLK_Source RCC HClock Source
  * @{
  */
#define RCC_HCLKSOURCE_HSI            (0x00000000U)                                    /*!< HSI clock selected as AHB clock */
#define RCC_HCLKSOURCE_HSE            (ICG_CLK_CTL_HCLKSRC_0)                          /*!< HSE clock selected as AHB clock */
#define RCC_HCLKSOURCE_PLL            (ICG_CLK_CTL_HCLKSRC_1)                          /*!< PLL clock selected as AHB clock */
#define RCC_HCLKSOURCE_LS             (ICG_CLK_CTL_HCLKSRC_0| ICG_CLK_CTL_HCLKSRC_1)   /*!< LS clock selected as AHB clock */
/**
  * @}
  */

/** @defgroup RCC_BR_Clock_Source RCC BR Clock Source
  * @{
  */
#define RCC_BRCLKSOURCE_HSI            (0x00000000U)                                   /*!< HSI clock selected as Baudrate clock */
#define RCC_BRCLKSOURCE_HSE            (ICG_CLK_CTL_BRSRC_0)                           /*!< HSE clock selected as Baudrate clock */
#define RCC_BRCLKSOURCE_PLL            (ICG_CLK_CTL_BRSRC_1)                           /*!< PLL clock selected as Baudrate clock */
/**
  * @}
  */

/** @defgroup RCC_I2C_Clock_Source RCC I2C Clock Source
  * @{
  */
#define RCC_I2CCLKSOURCE_HSI           (0x00000000U)                                   /*!< HSI clock selected as I2C clock */
#define RCC_I2CCLKSOURCE_HSE           (ICG_CLK_CTL_I2CSRC_0)                          /*!< HSE clock selected as I2C clock */
#define RCC_I2CCLKSOURCE_PLL           (ICG_CLK_CTL_I2CSRC_1)                          /*!< PLL clock selected as I2C clock */
/**
  * @}
  */

/** @defgroup RCC_GPIO_Clock_Source RCC GPIO Clock Source
  * @{
  */
#define RCC_GPIOCLKSOURCE_HSI          (0x00000000U)                                   /*!< HSI clock selected as GPIO clock */
#define RCC_GPIOCLKSOURCE_HSE          (ICG_CLK_CTL_GPIOSRC_0)                         /*!< HSE clock selected as GPIO clock */
#define RCC_GPIOCLKSOURCE_PLL          (ICG_CLK_CTL_GPIOSRC_1)                         /*!< PLL clock selected as GPIO clock */
/**
  * @}
  */

/** @defgroup RCC_TIMAG_Clock_Source RCC TIMER Advance/General Clock Source
  * @{
  */
#define RCC_TIMAGCLKSOURCE_PCLK        (0x00000000U)                                   /*!< APB clock selected as TIMA/TIMG clock */
#define RCC_TIMAGCLKSOURCE_HCLK        (ICG_CLK_CTL_TMRAGSRC_0)                        /*!< AHB clock selected as TIMA/TIMG clock */
#define RCC_TIMAGCLKSOURCE_PLL         (ICG_CLK_CTL_TMRAGSRC_1)                        /*!< PLL clock selected as TIMA/TIMG clock */
/**
  * @}
  */

/** @defgroup RCC_TIMB1_Clock_Source RCC TIMER Basic 1 Clock Source
  * @{
  */
#define RCC_TIMB1CLKSOURCE_PCLK        (0x00000000U)                                   /*!< HSI clock selected as TIMB1x clock */
#define RCC_TIMB1CLKSOURCE_HCLK        (ICG_CLK_CTL_TMRB1SRC_0)                        /*!< HSE clock selected as TIMB1x clock */
#define RCC_TIMB1CLKSOURCE_PLL         (ICG_CLK_CTL_TMRB1SRC_1)                        /*!< PLL clock selected as TIMB1x clock */
/**
  * @}
  */

/** @defgroup RCC_TIMB2_Clock_Source RCC TIMER Basic 2 Clock Source
  * @{
  */
#define RCC_TIMB2CLKSOURCE_PCLK        (0x00000000U)                                   /*!< HSI clock selected as TIMB2x clock */
#define RCC_TIMB2CLKSOURCE_HCLK        (ICG_CLK_CTL_TMRB2SRC_0)                        /*!< HSE clock selected as TIMB2x clock */
#define RCC_TIMB2CLKSOURCE_PLL         (ICG_CLK_CTL_TMRB2SRC_1)                        /*!< PLL clock selected as TIMB2x clock */
/**
  * @}
  */

/** @defgroup RCC_WDTW_Clock_Source RCC Watchdog windows Clock Source
  * @{
  */
#define RCC_WDTWCLKSOURCE_PCLK         (0x00000000U)                                   /*!< HSI clock selected as WDTW clock */
#define RCC_WDTWCLKSOURCE_HCLK         (ICG_CLK_CTL_WDTWSRC_0)                         /*!< HSE clock selected as WDTW clock */
#define RCC_WDTWCLKSOURCE_PLL          (ICG_CLK_CTL_WDTWSRC_1)                         /*!< PLL clock selected as WDTW clock */
/**
  * @}
  */

/** @defgroup RCC_ADC_Clock_Source RCC ADC Clock Source
  * @{
  */
#define RCC_ADCCLKSOURCE_PCLK          (0x00000000U)                                   /*!< HSI clock selected as ADC clock */
#define RCC_ADCCLKSOURCE_HCLK          (ICG_CLK_CTL_ADCSRC_0)                          /*!< HSE clock selected as ADC clock */
#define RCC_ADCCLKSOURCE_PLL           (ICG_CLK_CTL_ADCSRC_1)                          /*!< PLL clock selected as ADC clock */
/**
  * @}
  */

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA)  || defined(XT32H0xxB)) 
/** @defgroup RCC_RCOSC_MODE RCC OSC Normal/Calibrate mode
  * @{
  */
#define RCC_RCOSC_NORMAL               (0x00000000U)                           /*!< Calibrate RC (16M) disable */
#define RCC_RCOSC_CALIB                (ICG_RC16M_CTRL_CALI)                   /*!< Calibrate RC (16M) enable */
/**
  * @}
  */

/** @defgroup RCC_LSI_MODE RCC LSI Normal/Calibrate mode
  * @{
  */
#define RCC_LSI_NORMAL                 (0x00000000U)                           /*!< Calibrate RC (32K) disable */
#define RCC_LSI_CALIB                  (AON_CLKCTRL_32K_CAL)                   /*!< Calibrate RC (32K) enable */
/**
  * @}
  */

/** @defgroup RCC_DeepSleep_Mode Deep Sleep Mode
  * @{
  */
#define RCC_DEEPSLEEP_MODE_NORMAL      (0x00000000U)                           /*!< Deepsleep disable */
#define RCC_DEEPSLEEP_MODE_SLEEP       (AON_DEEPSLEEP_CTRL_MODE)               /*!< Deepsleep enable */
/**
  * @}
  */

/** @defgroup RCC_DeepSleep_External_Wakeup Deep Sleep External Wakeup
  * @{
  */
#define RCC_DEEPSLEEP_EXTWAKEUP_DISABLE      (0x00000000U)                     /*!< Deepsleep external wakeup disable */
#define RCC_DEEPSLEEP_EXTWAKEUP_ENABLE       (AON_DEEPSLEEP_CTRL_EXT_WAKEUP)   /*!< Deepsleep external wakeup enable */
/**
  * @}
  */
#endif /*XT32H0xxB*/
/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/

/** @defgroup RCC_Exported_Macros RCC Exported Macros
  * @{
  */

/** @addtogroup RCC_HSXTAL_I_TUNE
  * @param __VAL__ specifies tune value 
  *        This param __VAL__ can be one between 0 to 0xF
  * @{
  */
#define __HAL_RCC_SET_HSE_ITUNE(__VAL__) MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_ITUNE, __VAL__)
/**
  * @}
  */

/** @addtogroup RCC_HSXTAL_CAP_TUNE
  * @param __VAL__ specifies tune value 
  *        This param __VAL__ can be one between 0 to 0xF
  * @{
  */
#define __HAL_RCC_SET_HSE_CAPTUNE(__VAL__) MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_CTUNE, __VAL__)
/**
  * @}
  */

/** @addtogroup RCC_HSXTAL_CRES disable/enable
  * @{
  */
#define __HAL_RCC_HSE_CRES_ENABLE()  SET_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_CRES)
#define __HAL_RCC_HSE_CRES_DISABLE() CLEAR_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_CRES)
/**
  * @}
  */

/** @addtogroup RCC_RCOSC_CFG
  * @param __VAL__ specifies tune value 
  *        This param __VAL__ can be one between 0 to 0x7F
  * @{
  */
#define __HAL_RCC_SET_HSI_CRES(__VAL__) MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CRES, __VAL__)
#define __HAL_RCC_SET_HSI_CCAP(__VAL__) MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CCAP, __VAL__)
#define __HAL_RCC_SET_HSI_CCOMP(__VAL__) MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CCOMP, __VAL__)
#define __HAL_RCC_SET_HSI_CBIAS(__VAL__) MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CBIAS, __VAL__)
/**
  * @}
  */

/** @addtogroup RCC_VCO_CFG
  * @param __VAL__ specifies tune value 
  *        This param __VAL__ can be one between 0 to 0x7F
  * @{
  */
#define __HAL_RCC_SET_VCO_CAP(__VAL__) MODIFY_REG(ICG->PLL_DIV, ICG_PLL_VCOCAP, __VAL__)
#define __HAL_RCC_SET_VCO_BIAS(__VAL__) MODIFY_REG(ICG->PLL_DIV, ICG_PLL_VCOBIAS, __VAL__)
/**
  * @}
  */

/** @addtogroup RCC_RB_CFG
  * @param __VAL__ specifies tune value 
  *        This param __VAL__ can be one between 0 to 0x7F
  * @{
  */
#define __HAL_RCC_SET_RB_FBDIV(__VAL__) MODIFY_REG(ICG->PLL_DIV, ICG_PLL_FBDIV, __VAL__)
#define __HAL_RCC_SET_RB_POSTDIV(__VAL__) MODIFY_REG(ICG->PLL_DIV, ICG_PLL_POSTDIV, __VAL__)
/**
  * @}
  */

/** @addtogroup RCC_Clock_Configuration
  * @{
  */
#define __HAL_RCC_HSE_ENABLE()     MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT, 0)	

#define __HAL_RCC_HSE_DISABLE()    MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT, ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT)

#define __HAL_RCC_HSI_ENABLE()        CLEAR_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSRC)

#define __HAL_RCC_HSI_DISABLE()       SET_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSRC)

/**
  * @brief  Enable PLL clock output (ICG, CLK_CFG, ICG_CLK_CTL_PLL)
  */
#define __HAL_RCC_PLL_ENABLE()         CLEAR_BIT(ICG->CLK_CFG, ICG_CLK_CTL_PLL)

/**
  * @brief  Disable PLL clock output (ICG, CLK_CFG, ICG_CLK_CTL_PLL)
  */
#define __HAL_RCC_PLL_DISABLE()        SET_BIT(ICG->CLK_CFG, ICG_CLK_CTL_PLL)

/**
  * @brief  Macro to configure the External High Speed oscillator (HSE).
  * @param  __STATE__  specifies the new state of the HSE.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_HSE_OFF  Turn OFF the HSE oscillator.
  *            @arg @ref RCC_HSE_ON  Turn ON the HSE oscillator.
  */
#define __HAL_RCC_HSE_CONFIG(__STATE__)  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL | ICG_CLK_CTL_HSXTALOUT, __STATE__)
	
#define __HAL_RCC_HSE_GET_STATE()  READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL | ICG_CLK_CTL_HSXTALOUT)        

/**
  * @brief  Macro to configure the Internal High Speed oscillator (HSI).
  * @param  __STATE__  specifies the new state of the HSI.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_HSI_OFF  Turn OFF the HSI oscillator.
  *            @arg @ref RCC_HSI_ON  Turn ON the HSI oscillator.
  */
#define __HAL_RCC_HSI_CONFIG(__STATE__)  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSRC, __STATE__)        

#define __HAL_RCC_HSI_GET_STATE()  READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSRC)        

/**
  * @brief  Macro to configure the PLL.
  * @param  __STATE__  specifies the new state of the PLL.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_PLL_OFF  Turn OFF PLL.
  *            @arg @ref RCC_PLL_ON  Turn ON PLL.
  */
#define __HAL_RCC_PLL_SET_STATE(__STATE__)  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_PLL, __STATE__)        

#define __HAL_RCC_PLL_GET_STATE()  READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_PLL)        

/** @brief  Macro to configure the PLL multiplication factor.
  * @note   This function must be used only when the main PLL is disabled.
  * @param  __PLLM__  specifies the division factor for PLL VCO input clock
  *         This parameter must be a value of RCC_PLLM_Clock_Divider.
  * @note   You have to set the PLLM parameter correctly to ensure that the VCO input
  *         frequency ranges from 4 to 16 MHz. It is recommended to select a frequency
  *         of 16 MHz to limit PLL jitter.
  *
  */
#define __HAL_RCC_PLL_PLLM_CONFIG(__PLLM__) \
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_PREDIV, (__PLLM__))

#define __HAL_RCC_PLL_GET_PLLM() \
 (READ_BIT(ICG->PLL_DIV, ICG_PLL_FBDIV))

#if defined(XT32H0xxAMPW)
#define __HAL_RCC_PLL_GET_PLLM_VALUE() \
  ((READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV2) ? 2 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV4) ? 4 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV8) ? 8 : \
   12 )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define __HAL_RCC_PLL_GET_PLLM_VALUE() \
  ((READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV1) ? 1 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV2) ? 2 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV3) ? 3 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV4) ? 4 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV6) ? 6 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV8) ? 8 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV) == RCC_PLLM_DIV12) ? 12 : \
   24 )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

/** @brief  Macro to configure the PLL multiplication factor.
  * @note   This function must be used only when the main PLL is disabled.
  * @param  __PLLN__  specifies the division factor for PLL VCO input clock
  *         This parameter must be a value of RCC_PLLM_Clock_Divider.
  * @note   You have to set the PLLM parameter correctly to ensure that the VCO input
  *         frequency ranges from 4 to 16 MHz. It is recommended to select a frequency
  *         of 16 MHz to limit PLL jitter.
  *
  */
#define __HAL_RCC_PLL_PLLN_CONFIG(__PLLN__) \
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_FBDIV, (__PLLN__))

#define __HAL_RCC_PLL_GET_PLLN() \
 ((READ_BIT(ICG->PLL_DIV, ICG_PLL_FBDIV) > 0) ? READ_BIT(ICG->PLL_DIV, ICG_PLL_FBDIV) : (1UL << ICG_PLL_FBDIV_Pos))

#if defined(XT32H0xxAMPW) 
#define __HAL_RCC_PLL_GET_PLLN_VALUE() \
 ((READ_BIT(ICG->PLL_DIV, ICG_PLL_FBDIV) > 0) ? (READ_BIT(ICG->PLL_DIV, ICG_PLL_FBDIV) >> ICG_PLL_FBDIV_Pos) : 1UL )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define __HAL_RCC_PLL_GET_PLLN_VALUE() \
 ((READ_BIT(ICG->PLL_DIV, ICG_PLL_FBDIV) > 0) ? ((READ_BIT(ICG->PLL_DIV, ICG_PLL_FBDIV) >> ICG_PLL_FBDIV_Pos) + 64) : 1UL )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

/** @brief  Macro to configure the PLL multiplication factor.
  * @note   This function must be used only when the main PLL is disabled.
  * @param  __PLLR__  specifies the division factor for PLL VCO input clock
  *         This parameter must be a value of RCC_PLLM_Clock_Divider.
  * @note   You have to set the PLLM parameter correctly to ensure that the VCO input
  *         frequency ranges from 4 to 16 MHz. It is recommended to select a frequency
  *         of 16 MHz to limit PLL jitter.
  *
  */
#define __HAL_RCC_PLL_PLLR_CONFIG(__PLLR__) \
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_POSTDIV, (__PLLR__))

#define __HAL_RCC_PLL_GET_PLLR() \
  ((READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) > 0) ? READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) : (1UL < ICG_PLL_POSTDIV_Pos) )

#if defined(XT32H0xxAMPW)
#define __HAL_RCC_PLL_GET_PLLR_VALUE() \
  ((READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV4) ? 4 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV6) ? 6 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV8) ? 8 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV12) ? 12 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV16) ? 16 : \
   24 )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define __HAL_RCC_PLL_GET_PLLR_VALUE() \
  ((READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV4) ? 4 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV6) ? 6 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV8) ? 8 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV12) ? 12 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV16) ? 16 : \
   (READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV) == RCC_PLLR_DIV24) ? 24 : \
   48 )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

/**
  * @brief  Macro to configure the main PLL clock source, multiplication and division factors.
  * @note   This function must be used only when the main PLL is disabled.
  *
  * @param  __PLLM__  specifies the division factor for PLL VCO input clock.
  *         This parameter must be a value of RCC_PLLM_Clock_Divider.
  * @note   You have to set the PLLM parameter correctly to ensure that the VCO input
  *         frequency ranges from 4 to 16 MHz. It is recommended to select a frequency
  *         of 16 MHz to limit PLL jitter.
  *
  * @param  __PLLN__  specifies the multiplication factor for PLL VCO output clock.
  *         This parameter must be a number between 8 and 86.
  * @note   You have to set the PLLN parameter correctly to ensure that the VCO
  *         output frequency is between 64 and 344 MHz.
  *
  * @param  __PLLR__  specifies the division factor for the main system clock.
  *         This parameter must be a value of @ref RCC_PLLR_Clock_Divider
  * @note   You have to set the PLL parameters correctly to not exceed 64MHZ.
  */
#define __HAL_RCC_PLL_CONFIG(__PLLM__, __PLLN__, __PLLR__ ) \
  MODIFY_REG(ICG->PLL_DIV, \
             (ICG_PLL_PREDIV | ICG_PLL_FBDIV | ICG_PLL_POSTDIV),   \
             ((__PLLN__) | (__PLLM__) | (__PLLR__)))


/** @brief  Macro to configure the PLL clock source.
  * @note   This function must be used only when the main PLL is disabled.
  * @param  __PLLSOURCE__  specifies the PLL entry clock source.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_PLLSOURCE_HSI  HSI oscillator clock selected as PLL clock entry
  *            @arg @ref RCC_PLLSOURCE_HSE  HSE oscillator clock selected as PLL clock entry
  *
  */
#define __HAL_RCC_PLL_PLLSOURCE_CONFIG(__PLLSOURCE__) \
  MODIFY_REG(ICG->PLL_LFCFG_CTRL, ICG_PLL_CLKSRC, (__PLLSOURCE__))

/** @brief  Macro to get the oscillator used as PLL clock source.
  * @retval The oscillator used as PLL clock source. The returned value can be one
  *         of the following:
  *              @arg @ref RCC_PLLSOURCE_HSI HSI oscillator is used as PLL clock source.
  *              @arg @ref RCC_PLLSOURCE_HSE HSE oscillator is used as PLL clock source.
  */
#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)READ_BIT(ICG->PLL_LFCFG_CTRL, ICG_PLL_CLKSRC))

/**
  * @}
  */

/** @addtogroup RCC_PLL_CFG & CTRL
  * @{
  */

/** @brief  Macro to reset feedback divider.
  *
  */
#define __HAL_RCC_PLLN_RESET()            (CLEAR_BIT(ICG->PLL_DIV, ICG_PLL_RBFBDIV))
#define __HAL_RCC_PLLN_RELEASE_RESET()    (SET_BIT(ICG->PLL_DIV, ICG_PLL_RBFBDIV))

/** @brief  Macro to reset post divider.
  *
  */
#define __HAL_RCC_PLLR_RESET()            (CLEAR_BIT(ICG->PLL_DIV, ICG_PLL_RBPOSTDIV))
#define __HAL_RCC_PLLR_RELEASE_RESET()    (SET_BIT(ICG->PLL_DIV, ICG_PLL_RBPOSTDIV))

/** @brief  Macro to vco bias control.
  *
  */

/** @brief  Macro to set vco cap array.
  *
  */
#define __HAL_RCC_SET_VCOCAP(__CAP__)     (MODIFY_REG(ICG->PLL_DIV, ICG_PLL_VCOCAP, ( (__CAP__) << ICG_PLL_VCOCAP_Pos)))

/** @brief  Macro to power down charge pump
  *
  */
#define __HAL_RCC_CHARGE_PUMP_POWERON()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_CP))
#define __HAL_RCC_CHARGE_PUMP_POWERDOWN()    (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_CP))
#define __HAL_RCC_CHARGE_PUMP_ISPOWERON()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_CP) ? RESET : SET)

/** @brief  Macro to power down VCO
  *
  */
#define __HAL_RCC_VCO_POWERON()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCO))
#define __HAL_RCC_VCO_POWERDOWN()    (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCO))
#define __HAL_RCC_VCO_ISPOWERON()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCO) ? RESET : SET)

/** @brief  Macro to power down pfd
  *
  */
#define __HAL_RCC_PFD_POWERON()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_PDF))
#define __HAL_RCC_PFD_POWERDOWN()    (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_PDF))
#define __HAL_RCC_PFD_ISPOWERON()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_PDF) ? RESET : SET)

/** @brief  Macro to power down vcocal
  *
  */
#define __HAL_RCC_VCOCAL_POWERON()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOCAL))
#define __HAL_RCC_VCOCAL_POWERDOWN()    (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOCAL))
#define __HAL_RCC_VCOCAL_ISPOWERON()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOCAL) ? RESET : SET)

/** @brief  Macro to power down vcocal buffer
  *
  */
#define __HAL_RCC_VCOBUF_POWERON()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOBUF))
#define __HAL_RCC_VCOBUF_POWERDOWN()    (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOBUF))
#define __HAL_RCC_VCOBUF_ISPOWERON()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOBUF) ? RESET : SET)

/** @brief  Macro to power down vcocal buffer
  *
  */
#define __HAL_RCC_VCOCOMP_POWERON()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOCOMP))
#define __HAL_RCC_VCOCOMP_POWERDOWN()    (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOCOMP))
#define __HAL_RCC_VCOCOMP_ISPOWERON()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PD_VCOCOMP) ? RESET : SET)

/** @brief  Macro to vcocal enable
  *
  */
#define __HAL_RCC_VCOCAL_DISABLE()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCOCAL_EN))
#define __HAL_RCC_VCOCAL_ENABLE()       (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCOCAL_EN))
#define __HAL_RCC_VCOCAL_ISENABLED()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCOCAL_EN) ? SET : RESET)

/** @brief  Macro to vcocal autoload
  *
  */
#define __HAL_RCC_VCOCAL_AUTOLOAD_DISABLE()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCOCAL_AUTOB))
#define __HAL_RCC_VCOCAL_AUTOLOAD_ENABLE()       (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCOCAL_AUTOB))
#define __HAL_RCC_VCOCAL_AUTOLOAD_ISENABLED()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCOCAL_AUTOB) ? SET : RESET)

/** @brief  Macro to vco test
  *
  */
#define __HAL_RCC_VCOTST_DISABLE()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCTST_EN))
#define __HAL_RCC_VCOTST_ENABLE()       (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCTST_EN))
#define __HAL_RCC_VCOTST_ISENABLED()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCTST_EN) ? SET : RESET)

/** @brief  Macro to pll clock test
  *
  */
#define __HAL_RCC_PLLCLKTST_DISABLE()      (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PLLCLKTST_EN))
#define __HAL_RCC_PLLCLKTST_ENABLE()       (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PLLCLKTST_EN))
#define __HAL_RCC_PLLCLKTST_ISENABLED()    (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PLLCLKTST_EN) ? SET : RESET)

/** @brief  Macro to pll loopfilter control
  *
  */
#define __HAL_RCC_SET_IF_CTRL(__IF__)      (MODIFY_REG(ICG->PLL_LTCFG_CTRL, ICG_PLL_IF_CTRL, ((__IF__) << ICG_PLL_IF_CTRL_Pos)))
#define __HAL_RCC_GET_IF_CTRL()            ((uint32_t)(READ_BIT(ICG->PLL_LTCFG_CTRL, ICG_PLL_IF_CTRL)))

/** @brief  Macro to pfd control
  *
  */
#define __HAL_RCC_SET_PFDSRC(__SRC__)     (MODIFY_REG(ICG->PLL_LTCFG_CTRL, ICG_PLL_PDF_SLCT, ((__SRC__) << ICG_PLL_PDF_SLCT_Pos)))
#define __HAL_RCC_GET_PFDSRC()            ((uint32_t)(READ_BIT(ICG->PLL_LTCFG_CTRL, ICG_PLL_PDF_SLCT)))

/** @brief  Macro to sw_var_ctrl
  *
  */
#define __HAL_RCC_SW_VAR_DISABLE()        (CLAER_BIT(ICG->PLL_PD_CTRL, ICG_PLL_SW_VAR_CTRL))
#define __HAL_RCC_SW_VAR_ENABLE()         (SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_SW_VAR_CTRL))
#define __HAL_RCC_SW_VAR_ISENABLED()      (READ_BIT(ICG->PLL_PD_CTRL, ICG_PLL_SW_VAR_CTRL) ? SET : RESET)

/** @brief  Macro to comp vl hysteresis
  *
  * @param __HYS__
  *        This parameter can be one of the following values:
  *        @arg @ref RCC_VCOCAL_COMP_VL_HYSTERESIS_NO       
  *        @arg @ref RCC_VCOCAL_COMP_VL_HYSTERESIS_MIN      
  *        @arg @ref RCC_VCOCAL_COMP_VL_HYSTERESIS_MAX      
  *
  */
#define __HAL_RCC_SET_VCOCAL_COMP_VL(__HYS__)       (MODIFY_REG(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_COMPVL, (__HYS__)))
#define __HAL_RCC_GET_VCOCAL_COMP_VL()              ((uint32_t)(READ_BIT(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_COMPVL)))

/** @brief  Macro to comp vh hysteresis
  *
  * @param __HYS__
  *        This parameter can be one of the following values:
  *        @arg @ref RCC_VCOCAL_COMP_VH_HYSTERESIS_NO       
  *        @arg @ref RCC_VCOCAL_COMP_VH_HYSTERESIS_MIN      
  *        @arg @ref RCC_VCOCAL_COMP_VH_HYSTERESIS_MAX      
  *
  */
#define __HAL_RCC_SET_VCOCAL_COMP_VH(__HYS__)       (MODIFY_REG(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_COMPVH, (__HYS__)))
#define __HAL_RCC_GET_VCOCAL_COMP_VH()              ((uint32_t)(READ_BIT(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_COMPVH)))

/** @brief  Macro to comp vcoin_low_range
  *
  * @param __VLT__
  *        This parameter can be one of the following values:
  *        @arg @ref RCC_VCOCAL_IN_RANGE_LOW_P20VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_LOW_P22VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_LOW_P24VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_LOW_P26VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_LOW_P28VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_LOW_P30VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_LOW_P32VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_LOW_P34VDD
  *
  */
#define __HAL_RCC_SET_VCOCAL_IN_LOW_RNG(__VLT__)    (MODIFY_REG(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_IN_L_RNG, (__VLT__)))
#define __HAL_RCC_GET_VCOCAL_IN_LOW_RNG()           ((uint32_t)(READ_BIT(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_IN_L_RNG)))

/** @brief  Macro to comp vcoin_high_range
  *
  * @param __VLT__
  *        This parameter can be one of the following values:
  *        @arg @ref RCC_VCOCAL_IN_RANGE_HIGH_P66VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_HIGH_P68VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_HIGH_P70VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_HIGH_P72VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_HIGH_P74VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_HIGH_P76VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_HIGH_P78VDD
  *        @arg @ref RCC_VCOCAL_IN_RANGE_HIGH_P80VDD
  *
  */
#define __HAL_RCC_SET_VCOCAL_IN_HIGH_RNG(__VLT__)   (MODIFY_REG(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_IN_H_RNG, (__VLT__)))
#define __HAL_RCC_GET_VCOCAL_IN_HIGH_RNG()          ((uint32_t)(READ_BIT(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_IN_H_RNG)))

/** @brief  Macro to vcocal initial value
  * @param  __VAL__ 
  *         This parameter is be [0, 0x7F]
  *
  */
#define __HAL_RCC_SET_VCOCAL_INIT_VALUE(__VAL__)   (MODIFY_REG(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_INI_VAL, (__VAL__) << ICG_VCOCAL_INI_VAL_Pos))
#define __HAL_RCC_GET_VCOCAL_INIT_VALUE()          ((uint32_t)(READ_BIT(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_INI_VAL)) >> ICG_VCOCAL_INI_VAL_Pos)

/** @brief  Macro to pll stable time
  *
  * @param __TM__
  *        This parameter can be one of the following values:
  *        @arg @ref RCC_VCOCAL_PLL_STABLE_32MS      (0UL)
  *        @arg @ref RCC_VCOCAL_PLL_STABLE_48MS      (ICG_VCOCAL_STB_TM_0)
  *        @arg @ref RCC_VCOCAL_PLL_STABLE_64MS      (ICG_VCOCAL_STB_TM_1)
  *        @arg @ref RCC_VCOCAL_PLL_STABLE_96MS      (ICG_VCOCAL_STB_TM_1 | ICG_VCOCAL_STB_TM_0)
  *        @arg @ref RCC_VCOCAL_PLL_STABLE_128MS     (ICG_VCOCAL_STB_TM_2)
  *        @arg @ref RCC_VCOCAL_PLL_STABLE_160MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_0)
  *        @arg @ref RCC_VCOCAL_PLL_STABLE_192MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_1)
  *        @arg @ref RCC_VCOCAL_PLL_STABLE_256MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_1 | ICG_VCOCAL_STB_TM_0)
  *
  */
#define __HAL_RCC_SET_VCOCAL_PLL_STABLET_TIME(__TM__)        (MODIFY_REG(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_STB_TM, (__TM__)))
#define __HAL_RCC_GET_VCOCAL_PLL_STABLET_TIME()              ((uint32_t)(READ_BIT(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_STB_TM)))

/** @brief  Macro to vco calibrate interval
  *
  * @param __TM__
  *        This parameter can be one of the following values:
  *        @arg @ref RCC_VCOCAL_CALIBRATE_CNTG      (0UL)
  *        @arg @ref RCC_VCOCAL_CALIBRATE_ONE       (ICG_VCOCAL_CAL_ITVL_0)
  *        @arg @ref RCC_VCOCAL_CALIBRATE_10MS      (ICG_VCOCAL_CAL_ITVL_1)
  *        @arg @ref RCC_VCOCAL_CALIBRATE_100MS     (ICG_VCOCAL_CAL_ITVL_1 | ICG_VCOCAL_CAL_ITVL_0)
  *        @arg @ref RCC_VCOCAL_CALIBRATE_500MS     (ICG_VCOCAL_CAL_ITVL_2)
  *        @arg @ref RCC_VCOCAL_CALIBRATE_1S        (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_0)
  *        @arg @ref RCC_VCOCAL_CALIBRATE_5S        (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_1)
  *        @arg @ref RCC_VCOCAL_CALIBRATE_10S       (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_1 | ICG_VCOCAL_CAL_ITVL_0)
  *
  */
#define __HAL_RCC_SET_VCOCAL_CALIBRATE_INTERVAL(__TM__)        (MODIFY_REG(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_CAL_ITVL, (__TM__)))
#define __HAL_RCC_GET_VCOCAL_CALIBRATE_INTERVAL()              ((uint32_t)(READ_BIT(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_CAL_ITVL)))

/** @brief  Macro to iref out current
  *
  *
  */
#define __HAL_RCC_SET_IREF_OUT_CURRENT(__VAL__)   (MODIFY_REG(ICG->PLL_IREF_CTRL, ICG_IREF_OCCTRL, (__VAL__)))
#define __HAL_RCC_GET_IREF_OUT_CURRENT()          ((uint32_t)(READ_BIT(ICG->PLL_IREF_CTRL, ICG_IREF_OCCTRL)))

/** @brief  Macro to iref out current
  *
  *
  */
#define __HAL_RCC_SET_IREF(__VAL__)   (MODIFY_REG(ICG->PLL_IREF_CTRL, ICG_IREF_CTRL, (__VAL__)))
#define __HAL_RCC_GET_IREF()          ((uint32_t)(READ_BIT(ICG->PLL_IREF_CTRL, ICG_IREF_CTRL)))

/** @brief  Macro to iref cap out
  *
  *
  */
#define __HAL_RCC_SET_IREF_CAPOUT(__VAL__)   (MODIFY_REG(ICG->PLL_IREF_CTRL, ICG_IREF_VCOCAP_WR, (__VAL__)))
#define __HAL_RCC_GET_IREF_CAPOUT()          ((uint32_t)(READ_BIT(ICG->PLL_IREF_CTRL, ICG_IREF_VCOCAP_RD)))

/**
  * @}
  */

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB)) 

/** @addtogroup RCC_RCOSC
  * @{
  */

/** @brief  Set RCOSC mode
  * @param __MODE__
  *       @arg RCC_RCOSC_NORMAL
  *       @arg RCC_RCOSC_CALIB
  */
#define __HAL_RCC_SET_RCOSC_MODE(__MODE__) MODIFY_REG(ICG->RC16M_CTRL,ICG_RC16M_CTRL_CALI, __MODE__)

/** @brief  Set RCOSC control code
  * @param __CODE__
  */
#define __HAL_RCC_SET_RCOSC_CODE(__CODE__) MODIFY_REG(ICG->RC16M_CTRL,ICG_RC16M_CTRL_CRES, __CODE__)

/**
  * @}
  */

#endif /* XT32H0xxBMPW || XT32H0xxA || defined(XT32H0xxB */

/** @addtogroup RCC_RTC_CFG
  * @param __DIV__ specifies tune value 
  *        This param __DIV__ can be one between 0 to 0xFFFFFFFF
  * @{
  */
#define __HAL_RCC_SET_RTC_REFCLK_DIV(__DIV__) WRITE_REG(AON->RTC_REFCLK_DIV, __DIV__)
/**
  * @}
  */

/** @addtogroup RCC_RTC_CFG
  * @retval __DIV__ specifies tune value 
  *        This param __DIV__ can be one between 0 to 0xFFFFFFFF
  * @{
  */
#define __HAL_RCC_GET_RTC_REFCLK_DIV() (uint32_t)(READ_REG(AON->RTC_REFCLK_DIV) ? READ_REG(AON->RTC_REFCLK_DIV) : 1)
/**
  * @}
  */


/** @addtogroup RCC_CLK_TUNE
  * @param __VAL__ specifies tune value 
  *        This param __VAL__ can be one between 0 to 0xFFFFFFFF
  * @{
  */
#define __HAL_RCC_LSE_ENABLE()  CLEAR_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_PD)
#define __HAL_RCC_LSE_DISABLE()  SET_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_PD)

#define __HAL_RCC_LSI_ENABLE()  CLEAR_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_PD)
#define __HAL_RCC_LSI_DISABLE()  SET_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_PD)

/**
  * @brief  Macro to configure the External Low Speed oscillator (LSE).
  * @param  __STATE__  specifies the new state of the LSE.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_LSE_OFF  Turn OFF the LSE oscillator.
  *            @arg @ref RCC_LSE_ON  Turn ON the LSE oscillator.
  */
#define __HAL_RCC_LSE_CONFIG(__STATE__)  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_PD, __STATE__)        

#define __HAL_RCC_LSE_GET_STATE()  READ_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_PD)        

/**
  * @brief  Macro to configure the Internal Low Speed oscillator (LSI).
  * @param  __STATE__  specifies the new state of the LSI.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_LSI_OFF  Turn OFF the LSI oscillator.
  *            @arg @ref RCC_LSI_ON  Turn ON the LSI oscillator.
  */
#define __HAL_RCC_LSI_CONFIG(__STATE__)  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_PD, __STATE__)        

#define __HAL_RCC_LSI_GET_STATE()  READ_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_PD)        

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB)) 
/**
  * @brief  Macro to Internal Low Speed oscillator operate mode.
  * @param  __MODE__  specifies the new mode of the LSI.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_LSI_NORMAL  LSI oscillator work in normal mode.
  *            @arg @ref RCC_LSI_CALIB   LSI oscillator work in calibrate mode.
  */
#define __HAL_RCC_LSI_SET_MODE(__MODE__)  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32K_CAL, (__MODE__))        

#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @brief  Macro to configure LS source.
  * @param  __SOURCE__  specifies the new state of the LSI.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_LSSRC_LSI 
  *            @arg @ref RCC_LSSRC_LSE 
  */
#define __HAL_RCC_SET_LS_SOURCE(__SOURCE__) (MODIFY_REG(AON->AON_CFG, AON_CFG_32KCLKSRC, (__SOURCE__)))
#define __HAL_RCC_GET_LS_SOURCE()           ((uint32_t)READ_BIT(AON->AON_CFG, AON_CFG_32KCLKSRC))

#define __HAL_RCC_SET_LSE_ITUNE(__VAL__) MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_ITUNE, ((__VAL__) << AON_CLKCTRL_32KXTAL_ITUNE_Pos))
#define __HAL_RCC_SET_LSE_CTUNE(__VAL__) MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_CAPTUNE, ((__VAL__) << AON_CLKCTRL_32KXTAL_CAPTUNE_Pos))
#define __HAL_RCC_SET_LSI_RTUNE(__VAL__) MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_RESTUNE, ((__VAL__) << AON_CLKCTRL_32KRC_RESTUNE_Pos))
/**
  * @}
  */

/** @addtogroup RCC_LDO_CFG
  * @param __VAL__ specifies tune value 
  *        This param __DIV__ can be one between 0 to 0xFFFFFFFF
  * @{
  */
#define __HAL_RCC_DVDD_ENABLE() CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_CORE_PD)  
#define __HAL_RCC_DVDD_DISABLE() SET_BIT(AON->LDO_CFG, AON_LDO_CFG_CORE_PD)  

#define __HAL_RCC_AVDD_ENABLE() CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_ANALOG_PD)  
#define __HAL_RCC_AVDD_DISABLE() SET_BIT(AON->LDO_CFG, AON_LDO_CFG_ANALOG_PD)  

#define __HAL_RCC_HVDD_ENABLE() CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_IO_PD)  
#define __HAL_RCC_HVDD_DISABLE() SET_BIT(AON->LDO_CFG, AON_LDO_CFG_IO_PD)  

#define __HAL_RCC_VOLDET_ENABLE() CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_VOLDET_PD)  
#define __HAL_RCC_VOLDET_DISABLE() SET_BIT(AON->LDO_CFG, AON_LDO_CFG_VOLDET_PD)  

#define __HAL_RCC_SET_DVDD_OUTPUT(__VAL__) MODIFY_REG(AON->LDO_CFG, AON_LDO_CFG_CORE_OTUNE, ((__VAL__)<<AON_LDO_CFG_CORE_OTUNE_Pos))

#define __HAL_RCC_SET_AVDD_OUTPUT(__VAL__) MODIFY_REG(AON->LDO_CFG, AON_LDO_CFG_ANALOG_OTUNE, ((__VAL__)<<AON_LDO_CFG_ANALOG_OTUNE_Pos))

#define __HAL_RCC_SET_HVDD_OUTPUT(__VAL__) MODIFY_REG(AON->LDO_CFG, AON_LDO_CFG_IO_OTUNE, ((__VAL__)<<AON_LDO_CFG_IO_OTUNE_Pos))

#define __HAL_RCC_SET_VOLDET_TRG(__VAL__) MODIFY_REG(AON->LDO_CFG, AON_LDO_CFG_VOLFET_TRG, ((__VAL__)<<AON_LDO_CFG_VOLFET_TRG_Pos))
/**
  * @}
  */

/** @addtogroup RCC_IVREF_CFG_1p8v
  * @param __IDX__ specifies tune index 
  * @param __VAL__ specifies tune value 
  *        This param __VAL__ can be one between 0 to 0xF
  * @{
  */
#define __HAL_RCC_SET_IVREF_0P8V(__IDX__, __VAL__)  ((__IDX__ == 1) ? MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_VTUNE_1, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_1_Pos )) : \
                                                     (__IDX__ == 2) ? MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_VTUNE_2, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_2_Pos )) : \
                                                     (__IDX__ == 3) ? MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_VTUNE_3, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_3_Pos )) : \
                                                     (__IDX__ == 4) ? MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_VTUNE_4, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_4_Pos )) : \
                                                     (__IDX__ == 5) ? MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_VTUNE_5, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_5_Pos )) : \
                                                     (__IDX__ == 6) ? MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_VTUNE_6, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_6_Pos )) : \
                                                     (__IDX__ == 7) ? MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_VTUNE_7, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_7_Pos )) : \
                                                     (__IDX__ == 8) ? MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_VTUNE_8, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_8_Pos )) : \
                                                     (__IDX__ == 9) ? MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_VTUNE_9, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_9_Pos )) : \
                                                     (__IDX__ == 10) ? MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_VTUNE_10, ((__VAL__)< AON_IVREF_CFG_1_VTUNE_10_Pos )) : \
                                                    )

#define __HAL_RCC_SET_IVREF_2UA(__IDX__, __VAL__)   ((__IDX__ == 1) ? MODIFY_REG(AON->IVREF_CFG_2, AON_IVREF_CFG_2_ITUNE_1, ((__VAL__)< AON_IVREF_CFG_2_ITUNE_1_Pos )) : \
                                                     (__IDX__ == 2) ? MODIFY_REG(AON->IVREF_CFG_2, AON_IVREF_CFG_2_ITUNE_2, ((__VAL__)< AON_IVREF_CFG_2_ITUNE_2_Pos )) : \
                                                     (__IDX__ == 3) ? MODIFY_REG(AON->IVREF_CFG_2, AON_IVREF_CFG_2_ITUNE_3, ((__VAL__)< AON_IVREF_CFG_2_ITUNE_3_Pos )) : \
                                                     (__IDX__ == 4) ? MODIFY_REG(AON->IVREF_CFG_2, AON_IVREF_CFG_2_ITUNE_4, ((__VAL__)< AON_IVREF_CFG_2_ITUNE_4_Pos )) : \
                                                     (__IDX__ == 5) ? MODIFY_REG(AON->IVREF_CFG_2, AON_IVREF_CFG_2_ITUNE_5, ((__VAL__)< AON_IVREF_CFG_2_ITUNE_5_Pos )) : \
                                                     (__IDX__ == 6) ? MODIFY_REG(AON->IVREF_CFG_2, AON_IVREF_CFG_2_ITUNE_6, ((__VAL__)< AON_IVREF_CFG_2_ITUNE_6_Pos )) : \
                                                     (__IDX__ == 7) ? MODIFY_REG(AON->IVREF_CFG_2, AON_IVREF_CFG_2_ITUNE_7, ((__VAL__)< AON_IVREF_CFG_2_ITUNE_7_Pos )) : \
                                                     (__IDX__ == 8) ? MODIFY_REG(AON->IVREF_CFG_2, AON_IVREF_CFG_2_ITUNE_8, ((__VAL__)< AON_IVREF_CFG_2_ITUNE_8_Pos )) : \
                                                     (__IDX__ == 9) ? MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_ITUNE_9, ((__VAL__)< AON_IVREF_CFG_3_ITUNE_9_Pos )) : \
                                                     (__IDX__ == 10) ? MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_ITUNE_10, ((__VAL__)< AON_IVREF_CFG_3_ITUNE_10_Pos )() : \
                                                    ))

#define __HAL_RCC_SET_IVREF_1P22V(__VAL__)   MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_VTUNE_1P22, ((__VAL__)< AON_IVREF_CFG_3_VTUNE_1P22_Pos ))

#define __HAL_RCC_SET_IVREF_1P0V(__VAL__)   MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_VTUNE_1P0, ((__VAL__)< AON_IVREF_CFG_3_VTUNE_1P0_Pos ))
/**
  * @}
  */

/** @addtogroup RCC_Deep_sleep_time
  * @param __TM__ specifies time 
  * @{
  */
#define __HAL_RCC_SET_DEEPSLEEP_TIME(__TM__)   (WRITE_REG(AON->DEEPSLEEP_TIME, (__TM__)))  
#define __HAL_RCC_GET_DEEPSLEEP_TIME()         (READ_REG(AON->DEEPSLEEP_TIME))  
/**
  * @}
  */

/** @addtogroup RCC_Deep_sleep_mode
  * @{
  */
#define __HAL_RCC_DEEPSLEEP_ENABLE()         (SET_BIT(AON->DEEPSLEEP_CTRL, AON_DEEPSLEEP_CTRL_MODE))  
#define __HAL_RCC_DEEPSLEEP_DISABLE()        (CLEAR_BIT(AON->DEEPSLEEP_CTRL, AON_DEEPSLEEP_CTRL_MODE))  
#define __HAL_RCC_DEEPSLEEP_ISENABLED()      (READ_BIT(AON->DEEPSLEEP_CTRL, AON_DEEPSLEEP_CTRL_MODE) ? SET : RESET)  
/**
  * @}
  */


/** @addtogroup RCC_Peripheral_CLK_Enable
  *  
  *       
  * @{
  */
#define __HAL_RCC_SYSCFG_CLK_ENABLE()   __NOP(); 
#define __HAL_RCC_PWR_CLK_ENABLE()      __NOP(); 
#define __HAL_RCC_GPIO_CLK_ENABLE()     __NOP(); 
#define __HAL_RCC_TIMA_CLK_ENABLE()     __NOP(); 
#define __HAL_RCC_I2C1_CLK_ENABLE()     __NOP(); 
#define __HAL_RCC_I2C2_CLK_ENABLE()     __NOP(); 
#define __HAL_RCC_SPI1_CLK_ENABLE()     __NOP(); 
#define __HAL_RCC_DMA1_CLK_ENABLE()     __NOP(); 
#define __HAL_RCC_I2S1_CLK_ENABLE()     __NOP(); 
#define __HAL_RCC_RTC_CLK_ENABLE()      __NOP(); 
#define __HAL_RCC_ADC_CLK_ENABLE()      __NOP(); 
#define __HAL_RCC_BR_CLK_ENABLE()       __NOP(); 

#define __HAL_RCC_SYSCFG_CLK_DISABLE()   __NOP(); 
#define __HAL_RCC_PWR_CLK_DISABLE()      __NOP(); 
#define __HAL_RCC_GPIO_CLK_DISABLE()     __NOP(); 
#define __HAL_RCC_TIMA_CLK_DISABLE()     __NOP(); 
#define __HAL_RCC_I2C1_CLK_DISABLE()     __NOP(); 
#define __HAL_RCC_I2C2_CLK_DISABLE()     __NOP(); 
#define __HAL_RCC_SPI1_CLK_DISABLE()     __NOP(); 
#define __HAL_RCC_DMA1_CLK_DISABLE()     __NOP(); 
#define __HAL_RCC_I2S1_CLK_DISABLE()     __NOP(); 
#define __HAL_RCC_RTC_CLK_DISABLE()      __NOP(); 
#define __HAL_RCC_ADC_CLK_DISABLE()      __NOP(); 
#define __HAL_RCC_BR_CLK_DISABLE()       __NOP(); 


#define __HAL_RCC_UART1_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_UART1);
#define __HAL_RCC_UART1_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_UART1); 
#define __HAL_RCC_UART2_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_UART2);
#define __HAL_RCC_UART2_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_UART2); 
#define __HAL_RCC_UART3_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_UART3);
#define __HAL_RCC_UART3_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_UART3); 
#define __HAL_RCC_UART4_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_UART4);
#define __HAL_RCC_UART4_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_UART4); 

#define __HAL_RCC_I2C1_FORCE_RESET()      CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_I2C1);
#define __HAL_RCC_I2C1_RELEASE_RESET()    SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_I2C1); 
#define __HAL_RCC_I2C2_FORCE_RESET()      CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_I2C2);
#define __HAL_RCC_I2C2_RELEASE_RESET()    SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_I2C2); 

#define __HAL_RCC_TIMB11_FORCE_RESET()    CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB11);
#define __HAL_RCC_TIMB11_RELEASE_RESET()  SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB11); 
#define __HAL_RCC_TIMB12_FORCE_RESET()    CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB12);
#define __HAL_RCC_TIMB12_RELEASE_RESET()  SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB12); 
#define __HAL_RCC_TIMB13_FORCE_RESET()    CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB13);
#define __HAL_RCC_TIMB13_RELEASE_RESET()  SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB13); 
#define __HAL_RCC_TIMB14_FORCE_RESET()    CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB14);
#define __HAL_RCC_TIMB14_RELEASE_RESET()  SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB14); 

#define __HAL_RCC_TIMB21_FORCE_RESET()    CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB21);
#define __HAL_RCC_TIMB21_RELEASE_RESET()  SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB21); 
#define __HAL_RCC_TIMB22_FORCE_RESET()    CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB22);
#define __HAL_RCC_TIMB22_RELEASE_RESET()  SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB22); 
#define __HAL_RCC_TIMB23_FORCE_RESET()    CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB23);
#define __HAL_RCC_TIMB23_RELEASE_RESET()  SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB23); 
#define __HAL_RCC_TIMB24_FORCE_RESET()    CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB24);
#define __HAL_RCC_TIMB24_RELEASE_RESET()  SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMB24); 

#define __HAL_RCC_SPI1_FORCE_RESET()      CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_SPI1);
#define __HAL_RCC_SPI1_RELEASE_RESET()    SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_SPI1); 
#define __HAL_RCC_SPI2_FORCE_RESET()      CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_SPI2);
#define __HAL_RCC_SPI2_RELEASE_RESET()    SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_SPI2); 

#define __HAL_RCC_GPIO_FORCE_RESET()      CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_GPIO);
#define __HAL_RCC_GPIO_RELEASE_RESET()    SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_GPIO); 

#define __HAL_RCC_TIMA1_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMA1);
#define __HAL_RCC_TIMA1_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMA1); 

#define __HAL_RCC_TIMA2_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMA2);
#define __HAL_RCC_TIMA2_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMA2); 

#define __HAL_RCC_TIMG1_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMG1);
#define __HAL_RCC_TIMG1_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMG1); 

#define __HAL_RCC_TIMG2_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMG2);
#define __HAL_RCC_TIMG2_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMG2); 

#define __HAL_RCC_TIMG3_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMG3);
#define __HAL_RCC_TIMG3_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMG3); 

#define __HAL_RCC_TIMG4_FORCE_RESET()     CLEAR_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMG4);
#define __HAL_RCC_TIMG4_RELEASE_RESET()   SET_BIT(SYSCFG->SW_RST_CFG, SYSCFG_RST_CFG_TIMG4); 
/**
  * @}
  */

/** @addtogroup RCC_Clock_DIVIDER_CFG
  * @param __DIV__ specifies the divider 
  *        This param __DIV__ can be one between 0 to 0xFFFFFFFF
  * @{
  */
#define __HAL_RCC_SET_HCLK_DIV(__DIV__)           WRITE_REG(ICG->HCLK_DIV, __DIV__)     
#define __HAL_RCC_SET_PCLK_DIV(__DIV__)           WRITE_REG(ICG->PCLK_DIV, __DIV__)     
#define __HAL_RCC_SET_DMA_CLK_DIV(__DIV__)        WRITE_REG(ICG->DMA_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_BR_CLK_DIV(__DIV__)         WRITE_REG(ICG->BR_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_I2C1_CLK_DIV(__DIV__)       WRITE_REG(ICG->I2C1_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_I2C2_CLK_DIV(__DIV__)       WRITE_REG(ICG->I2C2_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_GPIO_CLK_DIV(__DIV__)       WRITE_REG(ICG->GPIO_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_TIMER_ADV_CLK_DIV(__DIV__)  WRITE_REG(ICG->TIMER_ADV_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_TIMER_B1_CLK_DIV(__DIV__)   WRITE_REG(ICG->TIMER_B1_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_TIMER_B2_CLK_DIV(__DIV__)   WRITE_REG(ICG->TIMER_B2_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_WDT_W_CLK_DIV(__DIV__)      WRITE_REG(ICG->WDT_W_CLK_DIV, __DIV__)     
#define __HAL_RCC_SET_ADC_CLK_DIV(__DIV__)        WRITE_REG(ICG->ADC_CLK_DIV, __DIV__)     

#define __HAL_RCC_GET_HCLK_DIV()                  ((READ_REG(ICG->HCLK_DIV)      > 0) ? READ_REG(ICG->HCLK_DIV) : 1)
#define __HAL_RCC_GET_PCLK_DIV()                  ((READ_REG(ICG->PCLK_DIV)      > 0) ? READ_REG(ICG->PCLK_DIV) : 1)
#define __HAL_RCC_GET_DMA_CLK_DIV()               ((READ_REG(ICG->DMA_CLK_DIV)   > 0) ? READ_REG(ICG->DMA_CLK_DIV) : 1)   
#define __HAL_RCC_GET_BR_CLK_DIV()                ((READ_REG(ICG->BR_CLK_DIV)    > 0) ? READ_REG(ICG->BR_CLK_DIV) : 1)  
#define __HAL_RCC_GET_I2C1_CLK_DIV()              ((READ_REG(ICG->I2C1_CLK_DIV)  > 0) ? READ_REG(ICG->I2C1_CLK_DIV) : 1)    
#define __HAL_RCC_GET_I2C2_CLK_DIV()              ((READ_REG(ICG->I2C2_CLK_DIV)  > 0) ? READ_REG(ICG->I2C2_CLK_DIV) : 1)    
#define __HAL_RCC_GET_GPIO_CLK_DIV()              ((READ_REG(ICG->GPIO_CLK_DIV)  > 0) ? READ_REG(ICG->GPIO_CLK_DIV) : 1)    
#define __HAL_RCC_GET_TIMER_ADV_CLK_DIV()         ((READ_REG(ICG->TIMER_ADV_CLK_DIV) > 0) ? READ_REG(ICG->TIMER_ADV_CLK_DIV) : 1)     
#define __HAL_RCC_GET_TIMER_B1_CLK_DIV()          ((READ_REG(ICG->TIMER_B1_CLK_DIV) > 0) ? READ_REG(ICG->TIMER_B1_CLK_DIV) : 1)     
#define __HAL_RCC_GET_TIMER_B2_CLK_DIV()          ((READ_REG(ICG->TIMER_B2_CLK_DIV) > 0) ? READ_REG(ICG->TIMER_B2_CLK_DIV) : 1)     
#define __HAL_RCC_GET_WDT_W_CLK_DIV()             ((READ_REG(ICG->WDT_W_CLK_DIV) > 0) ? READ_REG(ICG->WDT_W_CLK_DIV) : 1)     
#define __HAL_RCC_GET_ADC_CLK_DIV()               ((READ_REG(ICG->ADC_CLK_DIV) > 0) ? READ_REG(ICG->ADC_CLK_DIV) : 1)     
/**
  * @}
  */

#if defined(XT32H0xxB)
/** @addtogroup RCC_Timer_Input_Cfg
  * @param __Timer__ specifies the timer input 
  *        This parameter can be one of the follow values:
  *        @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMA1_CH1IN     
  *        @arg @ref RCC_TIMA1_CH2IN                   
  *        @arg @ref RCC_TIMA1_CH3IN                   
  *        @arg @ref RCC_TIMA1_CH4IN                   
  *        @arg @ref RCC_TIMA1_ETR                     
  *        @arg @ref RCC_TIMA2_CH1IN     
  *        @arg @ref RCC_TIMA2_CH2IN                   
  *        @arg @ref RCC_TIMA2_CH3IN                   
  *        @arg @ref RCC_TIMA2_CH4IN                   
  *        @arg @ref RCC_TIMA2_ETR                     
  *        @arg @ref RCC_TIMG1_CH1IN     
  *        @arg @ref RCC_TIMG1_CH2IN                   
  *        @arg @ref RCC_TIMG1_CH3IN                   
  *        @arg @ref RCC_TIMG1_CH4IN                   
  *        @arg @ref RCC_TIMG1_ETR                     
  *        @arg @ref RCC_TIMG2_CH1IN     
  *        @arg @ref RCC_TIMG2_CH2IN                   
  *        @arg @ref RCC_TIMG2_CH3IN                   
  *        @arg @ref RCC_TIMG2_CH4IN                   
  *        @arg @ref RCC_TIMG2_ETR                     
  *        @arg @ref RCC_TIMG3_CH1IN     
  *        @arg @ref RCC_TIMG3_CH2IN                   
  *        @arg @ref RCC_TIMG3_CH3IN                   
  *        @arg @ref RCC_TIMG3_CH4IN                   
  *        @arg @ref RCC_TIMG3_ETR                     
  *        @arg @ref RCC_TIMG4_CH1IN     
  *        @arg @ref RCC_TIMG4_CH2IN                   
  *        @arg @ref RCC_TIMG4_CH3IN                   
  *        @arg @ref RCC_TIMG4_CH4IN                   
  *        @arg @ref RCC_TIMG4_ETR                     
  * @{
  */
#define __HAL_RCC_SET_TIMER_INTERNAL_CLOCK(__TIMER__)      (((__TIMER__) == RCC_TIMB11_EXTERNAL_CLOCK) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB12_EXTERNAL_CLOCK) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB13_EXTERNAL_CLOCK) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB14_EXTERNAL_CLOCK) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB21_EXTERNAL_CLOCK) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB22_EXTERNAL_CLOCK) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB23_EXTERNAL_CLOCK) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB24_EXTERNAL_CLOCK) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_CH1IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_CH2IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_CH3IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_CH4IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_ETR) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_CH1IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_CH2IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_CH3IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_CH4IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_ETR) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_CH1IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_CH2IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_CH3IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_CH4IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_ETR) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_CH1IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_CH2IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_CH3IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_CH4IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_ETR) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_CH1IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_CH2IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_CH3IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_CH4IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_ETR) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_CH1IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_CH2IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_CH3IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_CH4IN) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_ETR) ? ((CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   __NOP() )
/**
  * @}
  */
#else
/** @addtogroup RCC_Timer_Input_Cfg
  * @param __Timer__ specifies the timer input 
  *        This parameter can be one of the follow values:
  *        @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMG_CH1IN     
  *        @arg @ref RCC_TIMG_CH2IN                   
  *        @arg @ref RCC_TIMG_CH3IN                   
  *        @arg @ref RCC_TIMG_CH4IN                   
  *        @arg @ref RCC_TIMG_ETR                     
  *        @arg @ref RCC_TIMA_CH1IN     
  *        @arg @ref RCC_TIMA_CH2IN                   
  *        @arg @ref RCC_TIMA_CH3IN                   
  *        @arg @ref RCC_TIMA_CH4IN                   
  *        @arg @ref RCC_TIMA_ETR                     
  * @{
  */
#define __HAL_RCC_SET_TIMER_INTERNAL_CLOCK(__TIMER__)      (CLEAR_BIT(ICG->TIMER_EXCLK_EN, __TIMER__))
/**
  * @}
  */
#endif /* XT32H0xxB */

#if defined(XT32H0xxB)
/** @addtogroup RCC_Timer_Input_Cfg
  * @param __Timer__ specifies the timer input 
  *        This parameter can be one of the follow values:
  *        @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMA1_CH1IN     
  *        @arg @ref RCC_TIMA1_CH2IN                   
  *        @arg @ref RCC_TIMA1_CH3IN                   
  *        @arg @ref RCC_TIMA1_CH4IN                   
  *        @arg @ref RCC_TIMA1_ETR                     
  *        @arg @ref RCC_TIMA2_CH1IN     
  *        @arg @ref RCC_TIMA2_CH2IN                   
  *        @arg @ref RCC_TIMA2_CH3IN                   
  *        @arg @ref RCC_TIMA2_CH4IN                   
  *        @arg @ref RCC_TIMA2_ETR                     
  *        @arg @ref RCC_TIMG1_CH1IN     
  *        @arg @ref RCC_TIMG1_CH2IN                   
  *        @arg @ref RCC_TIMG1_CH3IN                   
  *        @arg @ref RCC_TIMG1_CH4IN                   
  *        @arg @ref RCC_TIMG1_ETR                     
  *        @arg @ref RCC_TIMG2_CH1IN     
  *        @arg @ref RCC_TIMG2_CH2IN                   
  *        @arg @ref RCC_TIMG2_CH3IN                   
  *        @arg @ref RCC_TIMG2_CH4IN                   
  *        @arg @ref RCC_TIMG2_ETR                     
  *        @arg @ref RCC_TIMG3_CH1IN     
  *        @arg @ref RCC_TIMG3_CH2IN                   
  *        @arg @ref RCC_TIMG3_CH3IN                   
  *        @arg @ref RCC_TIMG3_CH4IN                   
  *        @arg @ref RCC_TIMG3_ETR                     
  *        @arg @ref RCC_TIMG4_CH1IN     
  *        @arg @ref RCC_TIMG4_CH2IN                   
  *        @arg @ref RCC_TIMG4_CH3IN                   
  *        @arg @ref RCC_TIMG4_CH4IN                   
  *        @arg @ref RCC_TIMG4_ETR                     
  * @{
  */
#define __HAL_RCC_SET_TIMER_INPUT(__TIMER__)      (((__TIMER__) == RCC_TIMB11_EXTERNAL_CLOCK) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB12_EXTERNAL_CLOCK) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB13_EXTERNAL_CLOCK) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB14_EXTERNAL_CLOCK) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB21_EXTERNAL_CLOCK) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB22_EXTERNAL_CLOCK) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB23_EXTERNAL_CLOCK) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMB24_EXTERNAL_CLOCK) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_CH1IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_CH2IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_CH3IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_CH4IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA1_ETR) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_CH1IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_CH2IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_CH3IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_CH4IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMA2_ETR) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_CH1IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_CH2IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_CH3IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_CH4IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG1_ETR) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_CH1IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_CH2IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_CH3IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_CH4IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG2_ETR) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_CH1IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_CH2IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_CH3IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_CH4IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG3_ETR) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_CH1IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_CH2IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_CH3IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_CH4IN) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   ((__TIMER__) == RCC_TIMG4_ETR) ? ((SET_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ) : \
                                                   __NOP() )
/**
  * @}
  */
#else 
/** @addtogroup RCC_Timer_Input_Cfg
  * @param __Timer__ specifies the timer input 
  *        This parameter can be one of the follow values:
  *        @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMG_CH1IN     
  *        @arg @ref RCC_TIMG_CH2IN                   
  *        @arg @ref RCC_TIMG_CH3IN                   
  *        @arg @ref RCC_TIMG_CH4IN                   
  *        @arg @ref RCC_TIMG_ETR                     
  *        @arg @ref RCC_TIMA_CH1IN     
  *        @arg @ref RCC_TIMA_CH2IN                   
  *        @arg @ref RCC_TIMA_CH3IN                   
  *        @arg @ref RCC_TIMA_CH4IN                   
  *        @arg @ref RCC_TIMA_ETR                     
  * @{
  */
#define __HAL_RCC_SET_TIMER_INPUT(__TIMER__)      (SET_BIT(ICG->TIMER_EXCLK_EN, __TIMER__))
/**
  * @}
  */
#endif /* XT32H0xxB */

#if defined(XT32H0xxB)
/** @addtogroup RCC_Timer_Input_Cfg
  * @param __Timer__ specifies the timer input 
  *        This parameter can be one of the follow values:
  *        @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMA1_CH1IN     
  *        @arg @ref RCC_TIMA1_CH2IN                   
  *        @arg @ref RCC_TIMA1_CH3IN                   
  *        @arg @ref RCC_TIMA1_CH4IN                   
  *        @arg @ref RCC_TIMA1_ETR                     
  *        @arg @ref RCC_TIMA2_CH1IN     
  *        @arg @ref RCC_TIMA2_CH2IN                   
  *        @arg @ref RCC_TIMA2_CH3IN                   
  *        @arg @ref RCC_TIMA2_CH4IN                   
  *        @arg @ref RCC_TIMA2_ETR                     
  *        @arg @ref RCC_TIMG1_CH1IN     
  *        @arg @ref RCC_TIMG1_CH2IN                   
  *        @arg @ref RCC_TIMG1_CH3IN                   
  *        @arg @ref RCC_TIMG1_CH4IN                   
  *        @arg @ref RCC_TIMG1_ETR                     
  *        @arg @ref RCC_TIMG2_CH1IN     
  *        @arg @ref RCC_TIMG2_CH2IN                   
  *        @arg @ref RCC_TIMG2_CH3IN                   
  *        @arg @ref RCC_TIMG2_CH4IN                   
  *        @arg @ref RCC_TIMG2_ETR                     
  *        @arg @ref RCC_TIMG3_CH1IN     
  *        @arg @ref RCC_TIMG3_CH2IN                   
  *        @arg @ref RCC_TIMG3_CH3IN                   
  *        @arg @ref RCC_TIMG3_CH4IN                   
  *        @arg @ref RCC_TIMG3_ETR                     
  *        @arg @ref RCC_TIMG4_CH1IN     
  *        @arg @ref RCC_TIMG4_CH2IN                   
  *        @arg @ref RCC_TIMG4_CH3IN                   
  *        @arg @ref RCC_TIMG4_CH4IN                   
  *        @arg @ref RCC_TIMG4_ETR                     
  * @retval Status SET: input RESET: internal clock
  * @{
  */
#define __HAL_RCC_TIMER_INPUT_ISENABLED(__TIMER__)      (((__TIMER__) == RCC_TIMB11_EXTERNAL_CLOCK) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMB12_EXTERNAL_CLOCK) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMB13_EXTERNAL_CLOCK) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMB14_EXTERNAL_CLOCK) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMB21_EXTERNAL_CLOCK) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMB22_EXTERNAL_CLOCK) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMB23_EXTERNAL_CLOCK) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMB24_EXTERNAL_CLOCK) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA1_CH1IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA1_CH2IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA1_CH3IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA1_CH4IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA1_ETR) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA2_CH1IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA2_CH2IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA2_CH3IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA2_CH4IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMA2_ETR) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_1, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG1_CH1IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG1_CH2IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG1_CH3IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG1_CH4IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG1_ETR) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG2_CH1IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG2_CH2IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG2_CH3IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG2_CH4IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG2_ETR) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG3_CH1IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG3_CH2IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG3_CH3IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG3_CH4IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG3_ETR) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG4_CH1IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG4_CH2IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG4_CH3IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG4_CH4IN) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         ((__TIMER__) == RCC_TIMG4_ETR) ? ((READ_BIT(ICG->TIMER_EXCLK_EN_2, __TIMER__)) ? SET : RESET) : \
                                                         RESET )
/**
  * @}
  */
#else
/** @addtogroup RCC_Timer_Input_Cfg
  * @param __Timer__ specifies the timer input 
  *        This parameter can be one of the follow values:
  *        @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        
  *        @arg @ref RCC_TIMG_CH1IN     
  *        @arg @ref RCC_TIMG_CH2IN                   
  *        @arg @ref RCC_TIMG_CH3IN                   
  *        @arg @ref RCC_TIMG_CH4IN                   
  *        @arg @ref RCC_TIMG_ETR                     
  *        @arg @ref RCC_TIMA_CH1IN     
  *        @arg @ref RCC_TIMA_CH2IN                   
  *        @arg @ref RCC_TIMA_CH3IN                   
  *        @arg @ref RCC_TIMA_CH4IN                   
  *        @arg @ref RCC_TIMA_ETR                     
  * @retval Status SET: input RESET: internal clock
  * @{
  */
#define __HAL_RCC_TIMER_INPUT_ISENABLED(__TIMER__)      ((READ_BIT(ICG->TIMER_EXCLK_EN, __TIMER__)) ? SET : RESET)
/**
  * @}
  */
#endif /* XT32H0xxB */

/** @defgroup RCC_Clock_Macros RCC Clock Macros
  * @{
  */
/** @brief  Macro to configure the HCLK.
  *
  * @param  __HCLK_CLKSOURCE__  specifies the Hclock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_HCLKSOURCE_HSI 
  *            @arg @ref RCC_HCLKSOURCE_HSE 
  *            @arg @ref RCC_HCLKSOURCE_PLL 
  *            @arg @ref RCC_HCLKSOURCE_LS  
  */
#define __HAL_RCC_SYSCLK_CONFIG(__HCLK_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC, (uint32_t)(__HCLK_CLKSOURCE__))

/** @brief  Macro to get the HCLK clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_HCLKSOURCE_HSI 
  *            @arg @ref RCC_HCLKSOURCE_HSE 
  *            @arg @ref RCC_HCLKSOURCE_PLL 
  *            @arg @ref RCC_HCLKSOURCE_LS  
  */
#define __HAL_RCC_GET_SYSCLK_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC)))

/** @brief  Macro to configure the HCLK.
  *
  * @param  __HCLK_CLKSOURCE__  specifies the Hclock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_HCLKSOURCE_HSI 
  *            @arg @ref RCC_HCLKSOURCE_HSE 
  *            @arg @ref RCC_HCLKSOURCE_PLL 
  *            @arg @ref RCC_HCLKSOURCE_LS  
  */
#define __HAL_RCC_HCLK_CONFIG(__HCLK_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC, (uint32_t)(__HCLK_CLKSOURCE__))

/** @brief  Macro to get the HCLK clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_HCLKSOURCE_HSI 
  *            @arg @ref RCC_HCLKSOURCE_HSE 
  *            @arg @ref RCC_HCLKSOURCE_PLL 
  *            @arg @ref RCC_HCLKSOURCE_LS  
  */
#define __HAL_RCC_GET_HCLK_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC)))

/** @brief  Macro to configure the UART.
  *
  * @param  __BR_CLKSOURCE__  specifies the UART clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_BRCLKSOURCE_HSI
  *            @arg @ref RCC_BRCLKSOURCE_HSE
  *            @arg @ref RCC_BRCLKSOURCE_PLL
  */
#define __HAL_RCC_BR_CONFIG(__BR_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_BRSRC, (uint32_t)(__BR_CLKSOURCE__))

/** @brief  Macro to get the UART clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_BRCLKSOURCE_HSI
  *            @arg @ref RCC_BRCLKSOURCE_HSE
  *            @arg @ref RCC_BRCLKSOURCE_PLL
  */
#define __HAL_RCC_GET_BR_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_BRSRC)))
 
/** @brief  Macro to configure the I2C.
  *
  * @param  __I2C_CLKSOURCE__  specifies the I2C clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_I2CCLKSOURCE_HSI  
  *            @arg @ref RCC_I2CCLKSOURCE_HSE  
  *            @arg @ref RCC_I2CCLKSOURCE_PLL  
  */
#define __HAL_RCC_I2C_CONFIG(__I2C_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_I2CSRC, (uint32_t)(__I2C_CLKSOURCE__))

/** @brief  Macro to get the I2C clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_I2CCLKSOURCE_HSI  
  *            @arg @ref RCC_I2CCLKSOURCE_HSE  
  *            @arg @ref RCC_I2CCLKSOURCE_PLL  
  */
#define __HAL_RCC_GET_I2C_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_I2CSRC)))

/** @brief  Macro to configure the GPIO.
  *
  * @param  __GPIO_CLKSOURCE__  specifies the GPIO clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_GPIOCLKSOURCE_HSI  
  *            @arg @ref RCC_GPIOCLKSOURCE_HSE  
  *            @arg @ref RCC_GPIOCLKSOURCE_PLL  
  */
#define __HAL_RCC_GPIO_CONFIG(__GPIO_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_GPIOSRC, (uint32_t)(__GPIO_CLKSOURCE__))

/** @brief  Macro to get the GPIO clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_GPIOCLKSOURCE_HSI  
  *            @arg @ref RCC_GPIOCLKSOURCE_HSE  
  *            @arg @ref RCC_GPIOCLKSOURCE_PLL  
  */
#define __HAL_RCC_GET_GPIO_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_GPIOSRC)))

/** @brief  Macro to configure the Timer.
  *
  * @param  __TIMER_CLKSOURCE__  specifies the Timer clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_TIMAGCLKSOURCE_PCLK  
  *            @arg @ref RCC_TIMAGCLKSOURCE_HCLK  
  *            @arg @ref RCC_TIMAGCLKSOURCE_PLL   
  */
#define __HAL_RCC_TIMAG_CONFIG(__TIMER_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_TMRAGSRC, (uint32_t)(__TIMER_CLKSOURCE__))

/** @brief  Macro to get the TIMER clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_TIMAGCLKSOURCE_PCLK  
  *            @arg @ref RCC_TIMAGCLKSOURCE_HCLK  
  *            @arg @ref RCC_TIMAGCLKSOURCE_PLL   
  */
#define __HAL_RCC_GET_TIMAG_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_TMRAGSRC)))

/** @brief  Macro to configure the Timer.
  *
  * @param  __TIMER_CLKSOURCE__  specifies the Timer clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_TIMB1CLKSOURCE_PCLK  
  *            @arg @ref RCC_TIMB1CLKSOURCE_HCLK  
  *            @arg @ref RCC_TIMB1CLKSOURCE_PLL   
  */
#define __HAL_RCC_TIMB1_CONFIG(__TIMER_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_TMRB1SRC, (uint32_t)(__TIMER_CLKSOURCE__))

/** @brief  Macro to get the TIMER clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_TIMB1CLKSOURCE_PCLK  
  *            @arg @ref RCC_TIMB1CLKSOURCE_HCLK  
  *            @arg @ref RCC_TIMB1CLKSOURCE_PLL   
  */
#define __HAL_RCC_GET_TIMB1_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_TMRB1SRC)))

/** @brief  Macro to configure the Timer.
  *
  * @param  __TIMER_CLKSOURCE__  specifies the Timer clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_TIMB2CLKSOURCE_PCLK  
  *            @arg @ref RCC_TIMB2CLKSOURCE_HCLK  
  *            @arg @ref RCC_TIMB2CLKSOURCE_PLL   
  */
#define __HAL_RCC_TIMB2_CONFIG(__TIMER_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_TMRB2SRC, (uint32_t)(__TIMER_CLKSOURCE__))

/** @brief  Macro to get the TIMER clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_TIMB2CLKSOURCE_PCLK  
  *            @arg @ref RCC_TIMB2CLKSOURCE_HCLK  
  *            @arg @ref RCC_TIMB2CLKSOURCE_PLL   
  */
#define __HAL_RCC_GET_TIMB2_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_TMRB2SRC)))

/** @brief  Macro to configure the Timer.
  *
  * @param  __TIMER_CLKSOURCE__  specifies the Timer clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_WDTWCLKSOURCE_PCLK
  *            @arg @ref RCC_WDTWCLKSOURCE_HCLK
  *            @arg @ref RCC_WDTWCLKSOURCE_PLL 
  */
#define __HAL_RCC_WDTW_CONFIG(__TIMER_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_WDTWSRC, (uint32_t)(__TIMER_CLKSOURCE__))

/** @brief  Macro to get the TIMER clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_WDTWCLKSOURCE_PCLK
  *            @arg @ref RCC_WDTWCLKSOURCE_HCLK
  *            @arg @ref RCC_WDTWCLKSOURCE_PLL 
  */
#define __HAL_RCC_GET_WDTW_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_WDTWSRC)))

/** @brief  Macro to configure the ADC.
  *
  * @param  __ADC_CLKSOURCE__  specifies the Timer clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_ADCCLKSOURCE_PCLK
  *            @arg @ref RCC_ADCCLKSOURCE_HCLK
  *            @arg @ref RCC_ADCCLKSOURCE_PLL 
  */
#define __HAL_RCC_ADC_CONFIG(__ADC_CLKSOURCE__) \
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_ADCSRC, (uint32_t)(__ADC_CLKSOURCE__))

/** @brief  Macro to get the TIMER clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_ADCCLKSOURCE_PCLK  
  *            @arg @ref RCC_ADCCLKSOURCE_HCLK  
  *            @arg @ref RCC_ADCCLKSOURCE_PLL   
  */
#define __HAL_RCC_GET_ADC_SOURCE() ((uint32_t)(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_ADCSRC)))

#if defined(XT32H0xxB)
#else
/** @brief  Macro to enable the Timers internal clock.
  *
  * @param  __TIMER__  specifies the Timer clock.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_0)
  *            @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_1)
  *            @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_2)
  *            @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_3)
  *            @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_4)
  *            @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_5)
  *            @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_6)
  *            @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_7)
  *            @arg @ref RCC_TIMG_CH1IN                   (ICG_TMXC_GTMSRC_0)
  *            @arg @ref RCC_TIMG_CH2IN                   (ICG_TMXC_GTMSRC_1)
  *            @arg @ref RCC_TIMG_CH3IN                   (ICG_TMXC_GTMSRC_2)
  *            @arg @ref RCC_TIMG_CH4IN                   (ICG_TMXC_GTMSRC_3)
  *            @arg @ref RCC_TIMG_EGR                     (ICG_TMXC_GTMSRC_4)
  *            @arg @ref RCC_TIMA_CH1IN                   (ICG_TMXC_ATMSRC_0)
  *            @arg @ref RCC_TIMA_CH2IN                   (ICG_TMXC_ATMSRC_1)
  *            @arg @ref RCC_TIMA_CH3IN                   (ICG_TMXC_ATMSRC_2)
  *            @arg @ref RCC_TIMA_CH4IN                   (ICG_TMXC_ATMSRC_3)
  *            @arg @ref RCC_TIMA_EGR                     (ICG_TMXC_ATMSRC_4)
  */
#define __HAL_RCC_INTERNALCLOCK_ENABLE(__TIMER__) \
  CLEAR_BIT(ICG->TIMER_EXCLK_EN, (uint32_t)(__TIMER__))

/** @brief  Macro to enable the Timers external input.
  *
  * @param  __TIMER__  specifies the Timer clock.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_0)
  *            @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_1)
  *            @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_2)
  *            @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_3)
  *            @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_4)
  *            @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_5)
  *            @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_6)
  *            @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_7)
  *            @arg @ref RCC_TIMG_CH1IN                   (ICG_TMXC_GTMSRC_0)
  *            @arg @ref RCC_TIMG_CH2IN                   (ICG_TMXC_GTMSRC_1)
  *            @arg @ref RCC_TIMG_CH3IN                   (ICG_TMXC_GTMSRC_2)
  *            @arg @ref RCC_TIMG_CH4IN                   (ICG_TMXC_GTMSRC_3)
  *            @arg @ref RCC_TIMG_EGR                     (ICG_TMXC_GTMSRC_4)
  *            @arg @ref RCC_TIMA_CH1IN                   (ICG_TMXC_ATMSRC_0)
  *            @arg @ref RCC_TIMA_CH2IN                   (ICG_TMXC_ATMSRC_1)
  *            @arg @ref RCC_TIMA_CH3IN                   (ICG_TMXC_ATMSRC_2)
  *            @arg @ref RCC_TIMA_CH4IN                   (ICG_TMXC_ATMSRC_3)
  *            @arg @ref RCC_TIMA_EGR                     (ICG_TMXC_ATMSRC_4)
  */
#define __HAL_RCC_EXTERNALCLOCK_ENABLE(__TIMER__) \
  SET_BIT(ICG->TIMER_EXCLK_EN, (uint32_t)(__TIMER__))

/** @brief  Macro to get the Timers input status.
  *
  * @param  __TIMER__  specifies the Timer clock.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_TIMB11_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_0)
  *            @arg @ref RCC_TIMB12_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_1)
  *            @arg @ref RCC_TIMB13_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_2)
  *            @arg @ref RCC_TIMB14_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_3)
  *            @arg @ref RCC_TIMB21_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_4)
  *            @arg @ref RCC_TIMB22_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_5)
  *            @arg @ref RCC_TIMB23_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_6)
  *            @arg @ref RCC_TIMB24_EXTERNAL_CLOCK        (ICG_TMXC_BTMSRC_7)
  *            @arg @ref RCC_TIMG_CH1IN                   (ICG_TMXC_GTMSRC_0)
  *            @arg @ref RCC_TIMG_CH2IN                   (ICG_TMXC_GTMSRC_1)
  *            @arg @ref RCC_TIMG_CH3IN                   (ICG_TMXC_GTMSRC_2)
  *            @arg @ref RCC_TIMG_CH4IN                   (ICG_TMXC_GTMSRC_3)
  *            @arg @ref RCC_TIMG_EGR                     (ICG_TMXC_GTMSRC_4)
  *            @arg @ref RCC_TIMA_CH1IN                   (ICG_TMXC_ATMSRC_0)
  *            @arg @ref RCC_TIMA_CH2IN                   (ICG_TMXC_ATMSRC_1)
  *            @arg @ref RCC_TIMA_CH3IN                   (ICG_TMXC_ATMSRC_2)
  *            @arg @ref RCC_TIMA_CH4IN                   (ICG_TMXC_ATMSRC_3)
  *            @arg @ref RCC_TIMA_EGR                     (ICG_TMXC_ATMSRC_4)
  */
#define __HAL_RCC_EXTERNALCLOCK_STATUS(__TIMER__) \
  ((READ_BIT(ICG->TIMER_EXCLK_EN, (uint32_t)(__TIMER__))) ? SET : RESET)
#endif /*XT32H0xxB*/
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCC_Exported_Functions
  * @{
  */
/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */
uint32_t HAL_RCC_GetSysClockFreq(void);	
uint32_t HAL_RCC_GetHCLKFreq(void);
uint32_t HAL_RCC_GetPCLKFreq(void);
uint32_t HAL_RCC_GetPLLClockFreq(void);

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group2
  * @{
  */

/* Initialization and de-initialization functions  ******************************/
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);

void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency);

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group3
  * @{
  */

HAL_StatusTypeDef HAL_RCC_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void              HAL_RCC_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t          HAL_RCC_GetPeriphCLKFreq(uint32_t PeriphClk);

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group4
  * @{
  */
#if defined(XT32H0xxAMPW)   
HAL_StatusTypeDef HAL_RCC_HSITuneStart(void);
HAL_StatusTypeDef HAL_RCC_HSICoarseTuning(uint32_t Code);
HAL_StatusTypeDef HAL_RCC_HSIFineTuning(uint32_t Code);

HAL_StatusTypeDef HAL_RCC_LSITuneStart(void);
HAL_StatusTypeDef HAL_RCC_LSITuning(uint32_t Code);

HAL_StatusTypeDef HAL_RCC_PLLTuneStart(void);
HAL_StatusTypeDef HAL_RCC_PLLTuning(uint32_t LFCode, uint32_t IRefCode);
#endif /* XT32H0xxAMPW */  

#if defined(XT32H0xxB) 
HAL_StatusTypeDef HAL_RCC_DeepSleepConfig(RCC_DeepSleepInitTypeDef *pConfig);  
void              HAL_RCC_DeepSleepStart(void);
#endif /* XT32H0xxB */  
/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group5
  * @{
  */

HAL_StatusTypeDef HAL_RCC_ChangePLLClk(RCC_PLLInitTypeDef  *PllClk);

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

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_HAL_RCC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
