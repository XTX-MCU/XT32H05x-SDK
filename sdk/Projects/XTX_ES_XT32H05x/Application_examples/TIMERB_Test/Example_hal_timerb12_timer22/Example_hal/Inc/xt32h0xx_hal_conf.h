/**
  ******************************************************************************
  * @file    xt32h0xx_hal_conf.h
  * @author  Software Team
  * @brief   HAL configuration template file.
  *          This file should be copied to the application folder and renamed
  *          to xt32h0xx_hal_conf.h.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech. 
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_CONF_H
#define XT32H0xx_HAL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup System_Config
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @addtogroup System_Config_Exported_Constants
  * @{
  */
/* ########################## Module Selection ############################## */
/**
  * @brief This is the list of modules to be used in the HAL driver
  */
#define HAL_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_PADI_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_ICTL_MODULE_ENABLED
//#define HAL_FLASH_MODULE_ENABLED
//#define HAL_CRC_MODULE_ENABLED
//#define HAL_I2C_MODULE_ENABLED
//#define HAL_LED_MODULE_ENABLED
//#define HAL_RTC_MODULE_ENABLED
//#define HAL_SPI_MODULE_ENABLED
//#define HAL_UART_MODULE_ENABLED
//#define HAL_WDT_MODULE_ENABLED
#define HAL_TIMR_MODULE_ENABLED
/* ########################## Register Callbacks selection ############################## */
/**
  * @brief This is the list of modules where register callback can be used
  */
#define USE_HAL_ADC_REGISTER_CALLBACKS        0u
#define USE_HAL_CMP_REGISTER_CALLBACKS        0u
#define USE_HAL_DAC_REGISTER_CALLBACKS        0u
#define USE_HAL_I2C_REGISTER_CALLBACKS        0u
#define USE_HAL_IRDA_REGISTER_CALLBACKS       0u
#define USE_HAL_RTC_REGISTER_CALLBACKS        0u
#define USE_HAL_SPI_REGISTER_CALLBACKS        0u
#define USE_HAL_TIM_REGISTER_CALLBACKS        0u
#define USE_HAL_TIMR_REGISTER_CALLBACKS       0u
#define USE_HAL_UART_REGISTER_CALLBACKS       0u
#define USE_HAL_WDT_REGISTER_CALLBACKS        0u

/* ########################## Oscillator Values adaptation ####################*/
/**
  * @brief Adjust the value of External High Speed oscillator (HSE) used in your application.
  *        This value is used by the RCC HAL module to compute the system frequency
  *        (when HSE is used as system clock source, directly or through the PLL).
  */
#if !defined  (HSE_VALUE)
#define HSE_VALUE    (48000000UL)            /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSE_STARTUP_TIMEOUT)
#define HSE_STARTUP_TIMEOUT    (100UL)      /*!< Time out for HSE start up, in ms */
#endif /* HSE_STARTUP_TIMEOUT */

/**
  * @brief Internal High Speed oscillator (HSI) value.
  *        This value is used by the RCC HAL module to compute the system frequency
  *        (when HSI is used as system clock source, directly or through the PLL).
  */
#if !defined  (HSI_VALUE)
#define HSI_VALUE    (16000000UL)           /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

/**
  * @brief Internal Low Speed oscillator (LSI) value.
  */
#if !defined  (LSI_VALUE)
#define LSI_VALUE  (32768UL)                /*!< LSI Typical Value in Hz*/
#endif /* LSI_VALUE */                      /*!< Value of the Internal Low Speed oscillator in Hz
The real value may vary depending on the variations
in voltage and temperature.*/
/**
  * @brief External Low Speed oscillator (LSE) value.
  *        This value is used by the UART, RTC HAL module to compute the system frequency
  */
#if !defined  (LSE_VALUE)
#define LSE_VALUE    (32768UL)              /*!< Value of the External oscillator in Hz*/
#endif /* LSE_VALUE */

#if !defined (LSE_STARTUP_TIMEOUT)
#define LSE_STARTUP_TIMEOUT    (5000UL)     /*!< Time out for LSE start up, in ms */
#endif /* LSE_STARTUP_TIMEOUT */

/* Tip: To avoid modifying this file each time you need to use different HSE,
   ===  you can define the HSE value in your toolchain compiler preprocessor. */

/* ########################### System Configuration ######################### */
/**
  * @brief This is the HAL system configuration section
  */
#define  VDD_VALUE                    (3300UL) /*!< Value of VDD in mv */
#define  TICK_INT_PRIORITY            ((1UL<<__NVIC_PRIO_BITS) - 1UL) /*!< tick interrupt priority */
#define  USE_RTOS                     0U
#define  PREFETCH_ENABLE              0 //1U
#define  INSTRUCTION_CACHE_ENABLE     1U

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */
/**
  * @}
  */

/* Includes ------------------------------------------------------------------*/
/** @addtogroup System_Config_Includes
  * @{
  */
/**
  * @brief Include modules header file
  */
#ifdef HAL_CORTEX_MODULE_ENABLED
#include "xt32h0xx_hal_cortex.h"
#endif /* HAL_CORTEX_MODULE_ENABLED */

#ifdef HAL_CRC_MODULE_ENABLED
#include "xt32h0xx_hal_crc.h"
#endif /* HAL_CRC_MODULE_ENABLED */

#ifdef HAL_DIV_MODULE_ENABLED
#include "xt32h0xx_hal_div.h"
#endif /* HAL_DIV_MODULE_ENABLED */

#ifdef HAL_DMA_MODULE_ENABLED
#include "xt32h0xx_hal_dma.h"
#endif /* HAL_DMA_MODULE_ENABLED */

#ifdef HAL_FLASH_MODULE_ENABLED
#include "xt32h0xx_hal_flash.h"
#endif /* HAL_FLASH_MODULE_ENABLED */

#ifdef HAL_GPIO_MODULE_ENABLED
#include "xt32h0xx_hal_gpio.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef HAL_I2C_MODULE_ENABLED
#include "xt32h0xx_hal_i2c.h"
#endif /* HAL_I2C_MODULE_ENABLED */

#ifdef HAL_ICTL_MODULE_ENABLED
#include "xt32h0xx_hal_ictl.h"
#endif /* HAL_ICTL_MODULE_ENABLED */

#ifdef HAL_LED_MODULE_ENABLED
#include "xt32h0xx_hal_led.h"
#endif /* HAL_LED_MODULE_ENABLED */

#ifdef HAL_MDU_MODULE_ENABLED
#include "xt32h0xx_hal_adc.h"
#include "xt32h0xx_hal_comp.h"
#include "xt32h0xx_hal_dac.h"
#include "xt32h0xx_hal_pga.h"
#endif /* HAL_MDU_MODULE_ENABLED */

#ifdef HAL_PADI_MODULE_ENABLED
#include "xt32h0xx_hal_padi.h"
#endif /* HAL_PADI_MODULE_ENABLED */

#ifdef HAL_RCC_MODULE_ENABLED
#include "xt32h0xx_hal_rcc.h"
#endif /* HAL_RCC_MODULE_ENABLED */

#ifdef HAL_RTC_MODULE_ENABLED
#include "xt32h0xx_hal_rtc.h"
#endif /* HAL_RTC_MODULE_ENABLED */

#ifdef HAL_SPI_MODULE_ENABLED
#include "xt32h0xx_hal_spi.h"
#endif /* HAL_SPI_MODULE_ENABLED */

#ifdef HAL_TIM_MODULE_ENABLED
#include "xt32h0xx_hal_tim.h"
#endif /* HAL_TIM_MODULE_ENABLED */

#ifdef HAL_TIMR_MODULE_ENABLED
#include "xt32h0xx_hal_timr.h"
#endif /* HAL_TIMR_MODULE_ENABLED */

#ifdef HAL_TSU_MODULE_ENABLED
#include "xt32h0xx_hal_tsu.h"
#endif /* HAL_TSU_MODULE_ENABLED */

#ifdef HAL_UART_MODULE_ENABLED
#include "xt32h0xx_hal_uart.h"
#endif /* HAL_UART_MODULE_ENABLED */

#ifdef HAL_WDT_MODULE_ENABLED
#include "xt32h0xx_hal_wdt.h"
#endif /* HAL_WDT_MODULE_ENABLED */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @addtogroup System_Config_Exported_Macros
  * @{
  */
#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for functions parameters check.
  * @param  expr If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed.
  *         If expr is true, it returns no value.
  * @retval None
  */
#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */
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

#endif /* XT32H0xx_HAL_CONF_H */


/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
