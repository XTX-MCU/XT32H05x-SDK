/**
  ******************************************************************************
  * @file    xt32h0xx_ll_rcc.h
  * @author  Software Team
  * @brief   Header file of RCC LL module.
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The LL RCC driver contains a set of generic APIs that can be
    used by user:
      (+) Access to ICG registers
      (+) Access to AON registers

  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_RCC_H
#define XT32H0xx_LL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if (defined(ICG) || defined(RST) || defined(AON)) 

/** @defgroup RCC_LL RCC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup RCC_LL_Private_Variables RCC Private Variables
  * @{
  */


/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_Private_Macros RCC Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_Exported_Types RCC Exported Types
  * @{
  */

/** @defgroup LL_ES_CLOCK_FREQ Clocks Frequency Structure
  * @{
  */

/**
  * @brief  RCC Clocks Frequency Structure
  */
typedef struct
{
  uint32_t SYSCLK_Frequency;        /*!< SYSCLK clock frequency */
  uint32_t HCLK_Frequency;          /*!< HCLK clock frequency */
  uint32_t PCLK_Frequency;          /*!< PCLK clock frequency */
} LL_RCC_ClocksTypeDef;

/**
  * @}
  */

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Constants RCC Exported Constants
  * @{
  */

/** @defgroup RCC_LL_EC_OSC_VALUES Oscillator Values adaptation
  * @brief    Defines used to adapt values of different oscillators
  * @note     These values could be modified in the user environment according to
  *           HW set-up.
  * @{
  */
#ifndef  HSE_VALUE
#define HSE_VALUE                      (48000000U)  /*!< Value of XTAL Oscillator in Hz */
#endif
#ifndef  HSI_VALUE
#define HSI_VALUE                      (16000000U)  /*!< Value of RC Oscillator in Hz   */
#endif
#ifndef  LSE_VALUE
#define LSE_VALUE                      (32768U)     /*!< Value of XTAL Oscillator in Hz */
#endif
#ifndef  LSI_VALUE
#define LSI_VALUE                      (32768U)     /*!< Value of RC Oscillator in Hz   */
#endif
/**
  * @}
  */

/** @defgroup RCC_LL_EC_HCLK_SOURCE HCLK Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_HCLK_SRC_HSI            (0UL)                                               /*!< 16MHz RC Oscillator   */
#define LL_RCC_HCLK_SRC_HSE            (ICG_CLK_CTL_HCLKSRC_0)                             /*!< 48MHz XTAL Oscillator */
#define LL_RCC_HCLK_SRC_PLL            (ICG_CLK_CTL_HCLKSRC_1)                             /*!< MCU PLL output */
#define LL_RCC_HCLK_SRC_LS             (ICG_CLK_CTL_HCLKSRC_0 | ICG_CLK_CTL_HCLKSRC_1)     /*!< 32KHz */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_WDTW_SOURCE HCLK Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_WDTW_SRC_PCLK           (0UL)                                   /*!< 16MHz RC Oscillator   */
#define LL_RCC_WDTW_SRC_HCLK           (ICG_CLK_CTL_WDTWSRC_0)                 /*!< 48MHz XTAL Oscillator */
#define LL_RCC_WDTW_SRC_PLL            (ICG_CLK_CTL_WDTWSRC_1)                 /*!< MCU PLL output */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_BR_SOURCE BR Baudrate Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_BR_SRC_HSI              (0UL)                                   /*!< 16MHz RC Oscillator   */
#define LL_RCC_BR_SRC_HSE              (ICG_CLK_CTL_BRSRC_0)                   /*!< 48MHz XTAL Oscillator */
#define LL_RCC_BR_SRC_PLL              (ICG_CLK_CTL_BRSRC_1)                   /*!< MCU PLL Output */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_TIMER_B1_SOURCE HCLK Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_TIMB1_SRC_HSI           (0UL)                                   /*!< 16MHz RC Oscillator   */
#define LL_RCC_TIMB1_SRC_HSE           (ICG_CLK_CTL_TMRB1SRC_0)                /*!< 48MHz XTAL Oscillator */
#define LL_RCC_TIMB1_SRC_PLL           (ICG_CLK_CTL_TMRB1SRC_1)                /*!< MCU PLL output */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_I2C_SOURCE I2C Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_I2C_SRC_HSI             (0UL)                                   /*!< 16MHz RC Oscillator   */
#define LL_RCC_I2C_SRC_HSE             (ICG_CLK_CTL_I2CSRC_0)                  /*!< 48MHz XTAL Oscillator */
#define LL_RCC_I2C_SRC_PLL             (ICG_CLK_CTL_I2CSRC_1)                  /*!< MCU PLL Output */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_TIMER_B2_SOURCE HCLK Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_TIMB2_SRC_HSI           (0UL)                                   /*!< 16MHz RC Oscillator   */
#define LL_RCC_TIMB2_SRC_HSE           (ICG_CLK_CTL_TMRB2SRC_0)                /*!< 48MHz XTAL Oscillator */
#define LL_RCC_TIMB2_SRC_PLL           (ICG_CLK_CTL_TMRB2SRC_1)                /*!< MCU PLL output */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_GPIO_SOURCE GPIO Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_GPIO_SRC_HSI            (0UL)                                   /*!< 16MHz RC Oscillator   */
#define LL_RCC_GPIO_SRC_HSE            (ICG_CLK_CTL_GPIOSRC_0)                 /*!< 48MHz XTAL Oscillator */
#define LL_RCC_GPIO_SRC_PLL            (ICG_CLK_CTL_GPIOSRC_1)                 /*!< MCU PLL Output */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_Timer_SOURCE Timer Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_TIMAG_SRC_PCLK          (0UL)                                   /*!< PCLK   */
#define LL_RCC_TIMAG_SRC_HCLK          (ICG_CLK_CTL_TMRAGSRC_0)                  /*!< HCLK */
#define LL_RCC_TIMAG_SRC_PLL           (ICG_CLK_CTL_TMRAGSRC_1)                  /*!< MCU PLL Output */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_ADC_SOURCE ADC Source Defines
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_ADC_SRC_HSI             (0UL)                                   /*!< PCLK   */
#define LL_RCC_ADC_SRC_HSE             (ICG_CLK_CTL_ADCSRC_0)                  /*!< HCLK */
#define LL_RCC_ADC_SRC_PLL             (ICG_CLK_CTL_ADCSRC_1)                  /*!< MCU PLL Output */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_HS_RC High Speed RC Oscillator enable control
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_HSI_ENABLE              (0UL)                                   /*!< High Speed RC Oscillator disable  */
#define LL_RCC_HSI_DISABLE             (ICG_CLK_CTL_HSRC)                      /*!< High Speed RC Oscillator enable   */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_HS_XTAL High Speed XTAL Oscillator enable control
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_HSE_ENABLE              (0UL)                                           /*!< High Speed XTAL Oscillator disable  */
#define LL_RCC_HSE_DISABLE             (ICG_CLK_CTL_HSXTAL | ICG_CLK_CTL_HSXTALOUT)    /*!< High Speed XTAL Oscillator enable   */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_PLL PLL enable control
  * @brief    HCLK source 
  * @{
  */
#define LL_RCC_PLL_ENABLE              (0UL)                                   /*!< MCU_PLL disable  */
#define LL_RCC_PLL_DISABLE             (ICG_CLK_CTL_PLL)                       /*!< MCU_PLL enable   */
/**
  * @}
  */

/** @defgroup RCC_LL_EC_32K_SOURCE LS clock source
  * @brief    32K source 
  * @{
  */
#define LL_RCC_SOURCE_LSI              (0UL)                                           /*!< 32K RC */
#define LL_RCC_SOURCE_LSE              (AON_CFG_32KCLKSRC_0)                           /*!< 32K XTAL */
#define LL_RCC_SOURCE_LSI1             (AON_CFG_32KCLKSRC_1)                           /*!< 32K RC */
#define LL_RCC_SOURCE_LSI2             (AON_CFG_32KCLKSRC_0 | AON_CFG_32KCLKSRC_1)     /*!< 32K RC */
/**
  * @}
  */
	
/** @defgroup RCC_LL_EC_PLL_SOURCE PLL clock source
  * @brief    32K source 
  * @{
  */
#define LL_RCC_PLL_SRC_HSI             (0UL)	
#define LL_RCC_PLL_SRC_HSE             (ICG_PLL_CLKSRC)	
/**
  * @}
  */

/** @defgroup RCC_PLLN_Clock_Divider PLLN Feedback Divider
  * @{
  */
#if defined(XT32H0xxAMPW) 
#define LL_RCC_PLLN_DIV_FREQ_98M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_96M       ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_94M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_92M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_90M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_88M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_86M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_84M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_82M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_80M       ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_78M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_76M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_74M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_72M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_70M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_68M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_66M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_64M       ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_62M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_60M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_58M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_56M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_54M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_52M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_50M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_49M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_48M       ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_47M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_46M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_45M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_44M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_43M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_42M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_41M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_40M       ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_39M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_38M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_37M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_36M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_35M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_34M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_33M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_32M       ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_31M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_30M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_29M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_28M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_27M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_26M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_25M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_24M       ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_23M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_22M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_21M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_20M       ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_19M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_18M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_17M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_16M       ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_15M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_14M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_13M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define LL_RCC_PLLN_DIV_FREQ_12M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define LL_RCC_PLLN_DIV_FREQ_99M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_98M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_97M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_96M       ( ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_95M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_94M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_93M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_92M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_91M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_90M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_89M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_88M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_87M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_86M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_85M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_84M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_83M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_82M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_81M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_80M       ( ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_79M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_78M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_77M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_76M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_75M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_74M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_73M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_72M       ( ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_71M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define LL_RCC_PLLN_DIV_FREQ_70M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define LL_RCC_PLLN_DIV_FREQ_69M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 )
#define LL_RCC_PLLN_DIV_FREQ_68M       ( ICG_PLL_FBDIV_2 )
#define LL_RCC_PLLN_DIV_FREQ_67M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 )
#define LL_RCC_PLLN_DIV_FREQ_66M       ( ICG_PLL_FBDIV_1 )
#define LL_RCC_PLLN_DIV_FREQ_65M       ( ICG_PLL_FBDIV_0 )
#define LL_RCC_PLLN_DIV_FREQ_64M       ( ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_62M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_60M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_58M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_56M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_54M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_52M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_50M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_49M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_48M       ( ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_47M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_46M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_45M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_44M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_43M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_42M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_41M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_40M       ( ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_39M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_38M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_37M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_36M       ( ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_35M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define LL_RCC_PLLN_DIV_FREQ_34M       ( ICG_PLL_FBDIV_2 )
#define LL_RCC_PLLN_DIV_FREQ_33M       ( ICG_PLL_FBDIV_1 )
#define LL_RCC_PLLN_DIV_FREQ_32M       ( ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_31M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_30M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_29M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_28M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_27M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_26M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_25M       ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_24M       ( ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_23M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_22M       ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_21M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_20M       ( ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_19M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_18M       ( ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_17M       ( ICG_PLL_FBDIV_2 )
#define LL_RCC_PLLN_DIV_FREQ_16M       ( ICG_PLL_FBDIV_5 )
#define LL_RCC_PLLN_DIV_FREQ_15M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_14M       ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define LL_RCC_PLLN_DIV_FREQ_13M       ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_12M       ( ICG_PLL_FBDIV_3 )
#define LL_RCC_PLLN_DIV_FREQ_11M       ( ICG_PLL_FBDIV_1 )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @}
  */

/** @defgroup RCC_PLLM_Clock_Divider PLLM Pre-divider
  * @{
  */
#if defined(XT32H0xxAMPW) 
#define LL_RCC_PLLM_DIV2               (ICG_PLL_PREDIV_3)                                                              /*!< PLLM division factor = 2  */
#define LL_RCC_PLLM_DIV4               (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2)                                           /*!< PLLM division factor = 4  */
#define LL_RCC_PLLM_DIV8               (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                        /*!< PLLM division factor = 8  */
#define LL_RCC_PLLM_DIV12              (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_0)                        /*!< PLLM division factor = 12  */
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define LL_RCC_PLLM_DIV1               (0)                                                                             /*!< PLLM division factor = 1  */
#define LL_RCC_PLLM_DIV2               (ICG_PLL_PREDIV_1)                                                              /*!< PLLM division factor = 2  */
#define LL_RCC_PLLM_DIV3               (ICG_PLL_PREDIV_0)                                                              /*!< PLLM division factor = 3  */
#define LL_RCC_PLLM_DIV4               (ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                                           /*!< PLLM division factor = 4  */
#define LL_RCC_PLLM_DIV6               (ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)                                           /*!< PLLM division factor = 6  */
#define LL_RCC_PLLM_DIV8               (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                        /*!< PLLM division factor = 8  */
#define LL_RCC_PLLM_DIV12              (ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)                        /*!< PLLM division factor = 12 */
#define LL_RCC_PLLM_DIV24              (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)     /*!< PLLM division factor = 24 */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @}
  */

/** @defgroup RCC_PLLR_Clock_Divider PLLR Post Divider
  * @{
  */
#if defined(XT32H0xxAMPW) 
#define LL_RCC_PLLR_DIV4               (ICG_PLL_POSTDIV_1)                                                             /*!< PLLR division factor = 4  */
#define LL_RCC_PLLR_DIV6               (ICG_PLL_POSTDIV_0)                                                             /*!< PLLR division factor = 6  */
#define LL_RCC_PLLR_DIV8               (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                                         /*!< PLLR division factor = 8  */
#define LL_RCC_PLLR_DIV12              (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1)                                         /*!< PLLR division factor = 12 */
#define LL_RCC_PLLR_DIV16              (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3)                     /*!< PLLR division factor = 16 */
#define LL_RCC_PLLR_DIV24              (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                     /*!< PLLR division factor = 24 */
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define LL_RCC_PLLR_DIV4               (0)                                                                             /*!< PLLR division factor = 4  */
#define LL_RCC_PLLR_DIV6               (ICG_PLL_POSTDIV_0)                                                             /*!< PLLR division factor = 6  */
#define LL_RCC_PLLR_DIV8               (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                                         /*!< PLLR division factor = 8  */
#define LL_RCC_PLLR_DIV12              (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1)                                         /*!< PLLR division factor = 12 */
#define LL_RCC_PLLR_DIV16              (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3)                     /*!< PLLR division factor = 16 */
#define LL_RCC_PLLR_DIV24              (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                     /*!< PLLR division factor = 24 */
#define LL_RCC_PLLR_DIV48              (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3) /*!< PLLR division factor = 48 */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */ 

#if defined(XT32H0xxAMPW)
#define LL_RCC_PLLR_DIV_FREQ_98M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_96M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_94M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_92M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_90M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_88M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_86M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_84M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_82M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_80M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_78M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_76M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_74M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_72M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_70M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_68M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_66M       ( ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_64M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_62M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_60M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_58M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_56M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_54M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_52M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_50M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_49M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_48M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_47M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_46M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_45M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_44M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_43M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_42M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_41M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_40M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_39M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_38M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_37M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_36M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_35M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_34M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_33M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_32M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_31M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_30M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_29M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_28M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_27M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_26M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_25M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_24M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_23M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_22M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_21M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_20M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_19M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_18M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_17M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_16M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_15M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_14M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_13M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_12M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define LL_RCC_PLLR_DIV_FREQ_99M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_98M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_97M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_96M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_95M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_94M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_93M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_92M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_91M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_90M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_89M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_88M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_87M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_86M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_85M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_84M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_83M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_82M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_81M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_80M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_79M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_78M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_77M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_76M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_75M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_74M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_73M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_72M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_71M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_70M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_69M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_68M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_67M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_66M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_65M       ( 0 )
#define LL_RCC_PLLR_DIV_FREQ_64M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_62M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_60M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_58M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_56M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_54M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_52M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_50M       ( ICG_PLL_POSTDIV_0 )
#define LL_RCC_PLLR_DIV_FREQ_49M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_48M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_47M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_46M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_45M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_44M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_43M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_42M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_41M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_40M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_39M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_38M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_37M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_36M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_35M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_34M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_33M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_32M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_31M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_30M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_29M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_28M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_27M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_26M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_25M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define LL_RCC_PLLR_DIV_FREQ_24M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_23M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_22M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_21M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_20M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_19M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_18M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_17M       ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define LL_RCC_PLLR_DIV_FREQ_16M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_15M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_14M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_13M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_12M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define LL_RCC_PLLR_DIV_FREQ_11M       ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */ 
/**
  * @}
  */

/** @defgroup RCC_LL_EC_VCOCAL_COMP_VL Vl hysteresis
  * @{
  */
#define LL_RCC_VCOCAL_COMP_VL_HYSTERESIS_NO        (0UL)
#define LL_RCC_VCOCAL_COMP_VL_HYSTERESIS_MIN       (ICG_VCOCAL_COMPVL_0)
#define LL_RCC_VCOCAL_COMP_VL_HYSTERESIS_MAX       (ICG_VCOCAL_COMPVL_1 | ICG_VCOCAL_COMPVL_0)
/**
  * @}
  */

/** @defgroup RCC_LL_EC_VCOCAL_COMP_VH Vh hysteresis
  * @{
  */
#define LL_RCC_VCOCAL_COMP_VH_HYSTERESIS_NO        (0UL)
#define LL_RCC_VCOCAL_COMP_VH_HYSTERESIS_MIN       (ICG_VCOCAL_COMPVH_0)
#define LL_RCC_VCOCAL_COMP_VH_HYSTERESIS_MAX       (ICG_VCOCAL_COMPVH_1 | ICG_VCOCAL_COMPVH_0)
/**
  * @}
  */

/** @defgroup RCC_LL_EC_VCOCAL_PLL_Stable_time PLL stable time
  * @{
  */
#define LL_RCC_VCOCAL_PLL_STABLE_32MS      (0UL)
#define LL_RCC_VCOCAL_PLL_STABLE_48MS      (ICG_VCOCAL_STB_TM_0)
#define LL_RCC_VCOCAL_PLL_STABLE_64MS      (ICG_VCOCAL_STB_TM_1)
#define LL_RCC_VCOCAL_PLL_STABLE_96MS      (ICG_VCOCAL_STB_TM_1 | ICG_VCOCAL_STB_TM_0)
#define LL_RCC_VCOCAL_PLL_STABLE_128MS     (ICG_VCOCAL_STB_TM_2)
#define LL_RCC_VCOCAL_PLL_STABLE_160MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_0)
#define LL_RCC_VCOCAL_PLL_STABLE_192MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_1)
#define LL_RCC_VCOCAL_PLL_STABLE_256MS     (ICG_VCOCAL_STB_TM_2 | ICG_VCOCAL_STB_TM_1 | ICG_VCOCAL_STB_TM_0)
/**
  * @}
  */

/** @defgroup RCC_LL_EC_VCOCAL_Calibration_time Calibration time
  * @{
  */
#define LL_RCC_VCOCAL_CALIBRATE_CNTG      (0UL)
#define LL_RCC_VCOCAL_CALIBRATE_ONE       (ICG_VCOCAL_CAL_ITVL_0)
#define LL_RCC_VCOCAL_CALIBRATE_10MS      (ICG_VCOCAL_CAL_ITVL_1)
#define LL_RCC_VCOCAL_CALIBRATE_100MS     (ICG_VCOCAL_CAL_ITVL_1 | ICG_VCOCAL_CAL_ITVL_0)
#define LL_RCC_VCOCAL_CALIBRATE_500MS     (ICG_VCOCAL_CAL_ITVL_2)
#define LL_RCC_VCOCAL_CALIBRATE_1S        (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_0)
#define LL_RCC_VCOCAL_CALIBRATE_5S        (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_1)
#define LL_RCC_VCOCAL_CALIBRATE_10S       (ICG_VCOCAL_CAL_ITVL_2 | ICG_VCOCAL_CAL_ITVL_1 | ICG_VCOCAL_CAL_ITVL_0)
/**
  * @}
  */

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
/** @defgroup RCC_LL_EC_HSI MODE 
  * @brief    HSI MODE 
  * @{
  */
#define LL_RCC_HSI_NORMAL              (0UL)                                   /*!< HSI normal mode     */
#define LL_RCC_HSI_CALIB               (ICG_CLK_CTL_PLL)                       /*!< HSI calibrate mode  */
/**
  * @}
  */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */ 

/** @defgroup RCC_LL_EC_Timer_Clock_Source Timer clock source
  * @{
  */
#if defined(XT32H0xxB)	
#define LL_RCC_TIMERS_INTERNAL_CLOCK       (0)

#define LL_RCC_TIMB11_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_0)
#define LL_RCC_TIMB12_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_1)
#define LL_RCC_TIMB13_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_2)
#define LL_RCC_TIMB14_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_3)
#define LL_RCC_TIMB21_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_4)
#define LL_RCC_TIMB22_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_5)
#define LL_RCC_TIMB23_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_6)
#define LL_RCC_TIMB24_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_7)

#define LL_RCC_TIMA1_CH1IN                  (ICG_TMXC_ATM1SRC_CH_0)
#define LL_RCC_TIMA1_CH2IN                  (ICG_TMXC_ATM1SRC_CH_1)
#define LL_RCC_TIMA1_CH3IN                  (ICG_TMXC_ATM1SRC_CH_2)
#define LL_RCC_TIMA1_CH4IN                  (ICG_TMXC_ATM1SRC_CH_3)
#define LL_RCC_TIMA1_ETR                    (ICG_TMXC_ATM1SRC_CH_4)

#define LL_RCC_TIMA2_CH1IN                  (ICG_TMXC_ATM2SRC_CH_0)
#define LL_RCC_TIMA2_CH2IN                  (ICG_TMXC_ATM2SRC_CH_1)
#define LL_RCC_TIMA2_CH3IN                  (ICG_TMXC_ATM2SRC_CH_2)
#define LL_RCC_TIMA2_CH4IN                  (ICG_TMXC_ATM2SRC_CH_3)
#define LL_RCC_TIMA2_ETR                    (ICG_TMXC_ATM2SRC_CH_4)

#define LL_RCC_TIMG1_CH1IN                  (ICG_TMXC_GTM1SRC_CH_0)
#define LL_RCC_TIMG1_CH2IN                  (ICG_TMXC_GTM1SRC_CH_1)
#define LL_RCC_TIMG1_CH3IN                  (ICG_TMXC_GTM1SRC_CH_2)
#define LL_RCC_TIMG1_CH4IN                  (ICG_TMXC_GTM1SRC_CH_3)
#define LL_RCC_TIMG1_ETR                    (ICG_TMXC_GTM1SRC_CH_4)

#define LL_RCC_TIMG2_CH1IN                  (ICG_TMXC_GTM2SRC_CH_0)
#define LL_RCC_TIMG2_CH2IN                  (ICG_TMXC_GTM2SRC_CH_1)
#define LL_RCC_TIMG2_CH3IN                  (ICG_TMXC_GTM2SRC_CH_2)
#define LL_RCC_TIMG2_CH4IN                  (ICG_TMXC_GTM2SRC_CH_3)
#define LL_RCC_TIMG2_ETR                    (ICG_TMXC_GTM2SRC_CH_4)

#define LL_RCC_TIMG3_CH1IN                  (ICG_TMXC_GTM3SRC_CH_0)
#define LL_RCC_TIMG3_CH2IN                  (ICG_TMXC_GTM3SRC_CH_1)
#define LL_RCC_TIMG3_CH3IN                  (ICG_TMXC_GTM3SRC_CH_2)
#define LL_RCC_TIMG3_CH4IN                  (ICG_TMXC_GTM3SRC_CH_3)
#define LL_RCC_TIMG3_ETR                    (ICG_TMXC_GTM3SRC_CH_4)

#define LL_RCC_TIMG4_CH1IN                  (ICG_TMXC_GTM4SRC_CH_0)
#define LL_RCC_TIMG4_CH2IN                  (ICG_TMXC_GTM4SRC_CH_1)
#define LL_RCC_TIMG4_CH3IN                  (ICG_TMXC_GTM4SRC_CH_2)
#define LL_RCC_TIMG4_CH4IN                  (ICG_TMXC_GTM4SRC_CH_3)
#define LL_RCC_TIMG4_ETR                    (ICG_TMXC_GTM4SRC_CH_4)
#else
#define LL_RCC_TIMERS_INTERNAL_CLOCK       (0)

#define LL_RCC_TIMB11_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_0)
#define LL_RCC_TIMB12_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_1)
#define LL_RCC_TIMB13_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_2)
#define LL_RCC_TIMB14_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_3)
#define LL_RCC_TIMB21_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_4)
#define LL_RCC_TIMB22_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_5)
#define LL_RCC_TIMB23_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_6)
#define LL_RCC_TIMB24_EXTERNAL_CLOCK       (ICG_TMXC_BTMSRC_7)

#define LL_RCC_TIMG_CH1IN                  (ICG_TMXC_GTMSRC_0)
#define LL_RCC_TIMG_CH2IN                  (ICG_TMXC_GTMSRC_1)
#define LL_RCC_TIMG_CH3IN                  (ICG_TMXC_GTMSRC_2)
#define LL_RCC_TIMG_CH4IN                  (ICG_TMXC_GTMSRC_3)
#define LL_RCC_TIMG_ETR                    (ICG_TMXC_GTMSRC_4)

#define LL_RCC_TIMA_CH1IN                  (ICG_TMXC_ATMSRC_0)
#define LL_RCC_TIMA_CH2IN                  (ICG_TMXC_ATMSRC_1)
#define LL_RCC_TIMA_CH3IN                  (ICG_TMXC_ATMSRC_2)
#define LL_RCC_TIMA_CH4IN                  (ICG_TMXC_ATMSRC_3)
#define LL_RCC_TIMA_ETR                    (ICG_TMXC_ATMSRC_4)
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @defgroup RCC_LS_Clock_Source LS clock source
  * @{
  */
#define LL_RCC_LS_SOURCE_LSI               (0)
#define LL_RCC_LS_SOURCE_LSE               (AON_CFG_32KCLKSRC_0)
/**
  * @}
  */

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
/** @defgroup RCC_LSI_Mode LSI mode
  * @{
  */
#define LL_RCC_LSI_MODE_NORMAL         (0)
#define LL_RCC_LSI_MODE_CALIB          (AON_CLKCTRL_32K_CAL)
/**
  * @}
  */

/** @defgroup RCC_LSI_Sleep_Mode Sleep mode
  * @{
  */
#define LL_RCC_DEEPSLEEP_EXTWAKEUP_DISABLE         (0)
#define LL_RCC_DEEPSLEEP_EXTWAKEUP_ENABLE          (AON_DEEPSLEEP_CTRL_EXT_WAKEUP)
/**
  * @}
  */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Macros RCC Exported Macros
  * @{
  */

/** @defgroup RCC_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in RCC register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_ICG_WriteReg(__REG__, __VALUE__) WRITE_REG((ICG->__REG__), (__VALUE__))

/**
  * @brief  Read a value in RCC register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_ICG_ReadReg(__REG__) READ_REG(ICG->__REG__)

/**
  * @brief  Write a value in RCC register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_RST_WriteReg(__REG__, __VALUE__) WRITE_REG((RST->__REG__), (__VALUE__))

/**
  * @brief  Read a value in RCC register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_RST_ReadReg(__REG__) READ_REG(RST->__REG__)

/**
  * @brief  Write a value in RCC register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_AON_WriteReg(__REG__, __VALUE__) WRITE_REG((AON->__REG__), (__VALUE__))

/**
  * @brief  Read a value in RCC register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_AON_ReadReg(__REG__) READ_REG(AON->__REG__)
/**
  * @}
  */

/** @defgroup RCC_LL_EM_CALC_FREQ Calculate frequencies
  * @{
  */

/**
  * @brief  Helper macro to calculate PLLN setting
  * @param  __PLLN__ N value
  * @retval PLLN dividor value
  */
#if defined(XT32H0xxAMPW)  
#define __LL_RCC_PLLN_VALUE(__PLLN__)   (((__PLLN__) == 0) ? 1 : ((__PLLN__) >> ICG_PLL_FBDIV_Pos))
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define __LL_RCC_PLLN_VALUE(__PLLN__)   (((__PLLN__) == 0) ? 1 : (((__PLLN__) >> ICG_PLL_FBDIV_Pos)+64))
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @brief  Helper macro to calculate PLLM setting
  * @param  __PLLM__ M value 
  * @retval PLLN divider value
  */
#if defined(XT32H0xxAMPW)
#define __LL_RCC_PLLM_VALUE(__PLLM__)   (((__PLLM__) == LL_RCC_PLLM_DIV2) ? 2 : \
                                         ((__PLLM__) == LL_RCC_PLLM_DIV4) ? 4 : \
                                         ((__PLLM__) == LL_RCC_PLLM_DIV8) ? 8 : \
                                         12) 
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define __LL_RCC_PLLM_VALUE(__PLLM__)   (((__PLLM__) == LL_RCC_PLLM_DIV1) ? 1 : \
                                         ((__PLLM__) == LL_RCC_PLLM_DIV2) ? 2 : \
                                         ((__PLLM__) == LL_RCC_PLLM_DIV3) ? 3 : \
                                         ((__PLLM__) == LL_RCC_PLLM_DIV4) ? 4 : \
                                         ((__PLLM__) == LL_RCC_PLLM_DIV6) ? 6 : \
                                         ((__PLLM__) == LL_RCC_PLLM_DIV8) ? 8 : \
                                         ((__PLLM__) == LL_RCC_PLLM_DIV12) ? 12 : \
                                         24) 
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @brief  Helper macro to calculate PLLR setting
  * @param  __PLLR__ R value 
  * @retval PLLN divider value
  */
#if defined(XT32H0xxAMPW)
#define __LL_RCC_PLLR_VALUE(__PLLR__)  (((__PLLR__) == LL_RCC_PLLR_DIV4) ? 4 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV6) ? 6 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV8) ? 8 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV12) ? 12 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV16) ? 16 : \
                                        24) 
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define __LL_RCC_PLLR_VALUE(__PLLR__)  (((__PLLR__) == LL_RCC_PLLR_DIV4) ? 4 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV6) ? 6 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV8) ? 8 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV12) ? 12 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV16) ? 16 : \
                                        ((__PLLR__) == LL_RCC_PLLR_DIV24) ? 24 : \
                                        48) 
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @brief  Helper macro to calculate the PLLCLK frequency on system domain
  * @param  __INPUTFREQ__ PLL Input frequency (based on HSE/HSI)
  * @param  __PLLM__ Pre-divider
  * @param  __PLLN__ Feedback divider
  * @param  __PLLR__ Post divider
  * @retval PLL clock frequency (in Hz)
  */
#define __LL_RCC_CALC_PLLCLK_FREQ(__INPUTFREQ__, __PLLM__, __PLLN__, __PLLR__)   \
  ((__INPUTFREQ__) * (__LL_RCC_PLLN_VALUE(__PLLN__)) / \
   (__LL_RCC_PLLM_VALUE(__PLLM__)) / \
   (__LL_RCC_PLLR_VALUE(__PLLR__)))

/**
  * @brief  Helper macro to calculate the HCLK frequency
  * @param  __CLKFREQ__ Source frequency (based on HSE/HSI/PLLCLK)
  * @param  __AHBPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval HCLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_SYSCLK_FREQ(__CLKFREQ__,__AHBPRESCALER__)  \
  ((__CLKFREQ__) / ((__AHBPRESCALER__ > 0) ? __AHBPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the HCLK frequency
  * @param  __CLKFREQ__ Source frequency (based on HSE/HSI/PLLCLK)
  * @param  __AHBPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval HCLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_HCLK_FREQ(__CLKFREQ__,__AHBPRESCALER__)  \
  ((__CLKFREQ__) / ((__AHBPRESCALER__ > 0) ? __AHBPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the PCLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __APBPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval PCLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_PCLK_FREQ(__CLKFREQ__, __APBPRESCALER__)  \
  ((__CLKFREQ__) / ((__APBPRESCALER__ > 0) ? __APBPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the DMA CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __DMACLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval DMA CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_DMACLK_FREQ(__CLKFREQ__, __DMACLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__DMACLKPRESCALER__ > 0) ? __DMACLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __BRCLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_BRCLK_FREQ(__CLKFREQ__, __BRCLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__BRCLKPRESCALER__ > 0) ? __BRCLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __I2C0CLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_I2C1CLK_FREQ(__CLKFREQ__, __I2C0CLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__I2C0CLKPRESCALER__ > 0) ? __I2C0CLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __I2C1CLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_I2C2CLK_FREQ(__CLKFREQ__, __I2C1CLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__I2C1CLKPRESCALER__ > 0) ? __I2C1CLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __GPIOCLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_GPIOCLK_FREQ(__CLKFREQ__, __GPIOCLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__GPIOCLKPRESCALER__ > 0) ? __GPIOCLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the ADC CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __ADCCLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_ADCCLK_FREQ(__CLKFREQ__, __ADCCLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__ADCCLKPRESCALER__ > 0) ? __ADCCLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __TIMAGCLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_TIMAGCLK_FREQ(__CLKFREQ__, __TIMAGCLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__TIMAGCLKPRESCALER__ > 0) ? __TIMAGCLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __TIMB1CLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_TIMB1CLK_FREQ(__CLKFREQ__, __TIMB1CLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__TIMB1CLKPRESCALER__ > 0) ? __TIMB1CLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __TIMB2CLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_TIMB2CLK_FREQ(__CLKFREQ__, __TIMB2CLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__TIMB2CLKPRESCALER__ > 0) ? __TIMB2CLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __WDTWCLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_WDTWCLK_FREQ(__CLKFREQ__, __WDTWCLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__WDTWCLKPRESCALER__ > 0) ? __WDTWCLKPRESCALER__ : 1))

/**
  * @brief  Helper macro to calculate the BR CLK frequency (ABP1)
  * @param  __CLKFREQ__ Source frequency
  * @param  __RTCCLKPRESCALER__ This parameter can be between 1 to 2^32-1
  * @retval Baudrate CLK clock frequency (in Hz)
  */
#define __LL_RCC_CALC_RTCCLK_FREQ(__CLKFREQ__, __RTCCLKPRESCALER__)  \
  ((__CLKFREQ__) / ((__RTCCLKPRESCALER__ > 0) ? __RTCCLKPRESCALER__ : 1))
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Functions RCC Exported Functions
  * @{
  */

/** @defgroup RCC_LL_Exported_Functions_Group1 Clock enable/disable
  * @{
  */

/**
  * @brief  Enable the PLL 
  * @rmtoll HCLK_SEL           PLL         LL_RCC_HCLKSEL_EnablePLL
  */
__STATIC_INLINE void LL_RCC_PLL_Enable(void)
{
  CLEAR_BIT(ICG->CLK_CFG, ICG_CLK_CTL_PLL);
}

/**
  * @brief  Disable the PLL 
  * @rmtoll HCLK_SEL           PLL         LL_RCC_HCLKSEL_DisablePLL
  */
__STATIC_INLINE void LL_RCC_PLL_Disable(void)
{
  SET_BIT(ICG->CLK_CFG, ICG_CLK_CTL_PLL);
}

/**
  * @brief  Enable the HS XTAL 
  * @rmtoll HCLK_SEL           XTAL         LL_RCC_HCLKSEL_EnableXTAL
  */
__STATIC_INLINE void LL_RCC_HSE_Enable(void)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT, 0);
}

/**
  * @brief  Disable the XTAL 
  * @rmtoll HCLK_SEL           XTAL         LL_RCC_HCLKSEL_DisableXTAL
  */
__STATIC_INLINE void LL_RCC_HSE_Disable(void)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT, ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT);
}

/**
  * @brief  Enable the RC 
  * @rmtoll HCLK_SEL           RC         LL_RCC_HCLKSEL_EnableRC
  */
__STATIC_INLINE void LL_RCC_HSI_Enable(void)
{
  CLEAR_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSRC);
}

/**
  * @brief  Disable the RC 
  * @rmtoll HCLK_SEL           RC         LL_RCC_HCLKSEL_DisableRC
  */
__STATIC_INLINE void LL_RCC_HSI_Disable(void)
{
  SET_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSRC);
}
/**
  * @}
  */

/** @defgroup RCC_LL_Exported_Functions_Group2 Clock source
  * @{
  */
/**
  * @brief  Get ADC clock source
  * @rmtoll CLK_CFG           ADCSRC      LL_RCC_SetADCCLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_ADC_SRC_HSI
  *         @arg @ref LL_RCC_ADC_SRC_HSE
  *         @arg @ref LL_RCC_ADC_SRC_PLL
  */
__STATIC_INLINE void LL_RCC_SetADCCLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_ADCSRC, Src);
}

/**
  * @brief  Get ADC clock source
  * @rmtoll CLK_CFG           ADCSRC      LL_RCC_GetADCCLKSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_ADC_SRC_HSI
  *         @arg @ref LL_RCC_ADC_SRC_HSE
  *         @arg @ref LL_RCC_ADC_SRC_PLL
  */
__STATIC_INLINE uint32_t LL_RCC_GetADCCLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_ADCSRC);
}

/**
  * @brief  set Timer clock source
  * @rmtoll HCLK_SEL           TMRAGSRC      LL_RCC_SetTimerAGCLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_TIMAG_SRC_PCLK
  *         @arg @ref LL_RCC_TIMAG_SRC_HCLK
  *         @arg @ref LL_RCC_TIMAG_SRC_PLL 
  */
__STATIC_INLINE void LL_RCC_SetTimerAGCLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_TMRAGSRC, Src);
}

/**
  * @brief  set Timer clock source
  * @rmtoll HCLK_SEL           TMRAGSRC      LL_RCC_GetTimerAGCLKSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_TIMAG_SRC_PCLK
  *         @arg @ref LL_RCC_TIMAG_SRC_HCLK
  *         @arg @ref LL_RCC_TIMAG_SRC_PLL 
  */
__STATIC_INLINE uint32_t LL_RCC_GetTimerAGCLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_TMRAGSRC);
}

/**
  * @brief  set Timer clock source
  * @rmtoll HCLK_SEL           TMRB1SRC      LL_RCC_SetTimerB1CLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_TIMB1_SRC_HSI
  *         @arg @ref LL_RCC_TIMB1_SRC_HSE
  *         @arg @ref LL_RCC_TIMB1_SRC_PLL
  */
__STATIC_INLINE void LL_RCC_SetTimerB1CLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_TMRB1SRC, Src);
}

/**
  * @brief  set Timer clock source
  * @rmtoll HCLK_SEL           TMRB1SRC      LL_RCC_GetTimerB1CLKSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_TIMB1_SRC_HSI
  *         @arg @ref LL_RCC_TIMB1_SRC_HSE
  *         @arg @ref LL_RCC_TIMB1_SRC_PLL
  */
__STATIC_INLINE uint32_t LL_RCC_GetTimerB1CLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_TMRB1SRC);
}

/**
  * @brief  set Timer clock source
  * @rmtoll HCLK_SEL           TMRB2SRC      LL_RCC_SetTimerB2CLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_TIMB2_SRC_HSI
  *         @arg @ref LL_RCC_TIMB2_SRC_HSE
  *         @arg @ref LL_RCC_TIMB2_SRC_PLL
  */
__STATIC_INLINE void LL_RCC_SetTimerB2CLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_TMRB2SRC, Src);
}

/**
  * @brief  set Timer clock source
  * @rmtoll HCLK_SEL           TMRB2SRC      LL_RCC_GetTimerB2CLKSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_TIMB2_SRC_HSI
  *         @arg @ref LL_RCC_TIMB2_SRC_HSE
  *         @arg @ref LL_RCC_TIMB2_SRC_PLL
  */
__STATIC_INLINE uint32_t LL_RCC_GetTimerB2CLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_TMRB2SRC);
}

/**
  * @brief  set Timer clock source
  * @rmtoll HCLK_SEL           WDTWSRC      LL_RCC_SetWDTWCLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_WDTW_SRC_PCLK
  *         @arg @ref LL_RCC_WDTW_SRC_HCLK
  *         @arg @ref LL_RCC_WDTW_SRC_PLL 
  */
__STATIC_INLINE void LL_RCC_SetWDTWCLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_WDTWSRC, Src);
}

/**
  * @brief  set Timer clock source
  * @rmtoll HCLK_SEL           WDTWSRC      LL_RCC_GetWDTWCLKSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_WDTW_SRC_PCLK
  *         @arg @ref LL_RCC_WDTW_SRC_HCLK
  *         @arg @ref LL_RCC_WDTW_SRC_PLL 
  */
__STATIC_INLINE uint32_t LL_RCC_GetWDTWCLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_WDTWSRC);
}

/**
  * @brief  set GPIO clock source
  * @rmtoll HCLK_SEL           GPIOSRC      LL_RCC_SetGPIOCLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_GPIO_SRC_HSI
  *         @arg @ref LL_RCC_GPIO_SRC_HSE
  *         @arg @ref LL_RCC_GPIO_SRC_PLL
  */
__STATIC_INLINE void LL_RCC_SetGPIOCLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_GPIOSRC, Src);
}

/**
  * @brief  set GPIO clock source
  * @rmtoll HCLK_SEL           GPIOSRC      LL_RCC_GetGPIOCLKSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_GPIO_SRC_HSI
  *         @arg @ref LL_RCC_GPIO_SRC_HSE
  *         @arg @ref LL_RCC_GPIO_SRC_PLL
  */
__STATIC_INLINE uint32_t LL_RCC_GetGPIOCLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_GPIOSRC);
}

/**
  * @brief  set I2C clock source
  * @rmtoll HCLK_SEL           I2CSRC      LL_RCC_SetI2CCLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_I2C_SRC_HSI
  *         @arg @ref LL_RCC_I2C_SRC_HSE
  *         @arg @ref LL_RCC_I2C_SRC_PLL
  */
__STATIC_INLINE void LL_RCC_SetI2CCLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_I2CSRC, Src);
}

/**
  * @brief  set I2C clock source
  * @rmtoll HCLK_SEL           I2CSRC      LL_RCC_GetI2CCLKSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_I2C_SRC_HSI
  *         @arg @ref LL_RCC_I2C_SRC_HSE
  *         @arg @ref LL_RCC_I2C_SRC_PLL
  */
__STATIC_INLINE uint32_t LL_RCC_GetI2CCLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_I2CSRC);
}

/**
  * @brief  set BR clock source
  * @rmtoll HCLK_SEL           BRSRC      LL_RCC_SetBRCLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_BR_SRC_HSI
  *         @arg @ref LL_RCC_BR_SRC_HSE
  *         @arg @ref LL_RCC_BR_SRC_PLL
  */
__STATIC_INLINE void LL_RCC_SetBRCLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_BRSRC, Src);
}

/**
  * @brief  set BR clock source
  * @rmtoll HCLK_SEL           BRSRC      LL_RCC_GetBRCLKSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_BR_SRC_HSI
  *         @arg @ref LL_RCC_BR_SRC_HSE
  *         @arg @ref LL_RCC_BR_SRC_PLL
  */
__STATIC_INLINE uint32_t LL_RCC_GetBRCLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_BRSRC);
}

/**
  * @brief  set HCLK clock source
  * @rmtoll HCLK_SEL           HCLKSRC      LL_RCC_SetHCLKSrc
  * @param Src This parameter can be one of the following values:
  *        @arg @ref LL_RCC_HCLK_SRC_HSI
  *        @arg @ref LL_RCC_HCLK_SRC_HSE
  *        @arg @ref LL_RCC_HCLK_SRC_PLL
  *        @arg @ref LL_RCC_HCLK_SRC_LS 
  */
__STATIC_INLINE void LL_RCC_SetHCLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC, Src);
}

/**
  * @brief  set BR clock source
  * @rmtoll HCLK_SEL           HCLKSRC      LL_RCC_GetHCLKSrc
  * @retval This parameter can be one of the following values:
  *        @arg @ref LL_RCC_HCLK_SRC_HSI
  *        @arg @ref LL_RCC_HCLK_SRC_HSE
  *        @arg @ref LL_RCC_HCLK_SRC_PLL
  *        @arg @ref LL_RCC_HCLK_SRC_LS 
  */
__STATIC_INLINE uint32_t LL_RCC_GetHCLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC);
}

/**
  * @brief  set PCLK clock source
  * @rmtoll HCLK_SEL           HCLKSRC      LL_RCC_SetPCLKSrc
  * @param Src This parameter can be one of the following values:
  *        @arg @ref LL_RCC_HCLK_SRC_HSI
  *        @arg @ref LL_RCC_HCLK_SRC_HSE
  *        @arg @ref LL_RCC_HCLK_SRC_PLL
  *        @arg @ref LL_RCC_HCLK_SRC_LS 
  */
__STATIC_INLINE void LL_RCC_SetPCLKSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC, Src);
}

/**
  * @brief  set PCLK clock source
  * @rmtoll HCLK_SEL           HCLKSRC      LL_RCC_GetPCLKSrc
  * @retval This parameter can be one of the following values:
  *        @arg @ref LL_RCC_HCLK_SRC_HSI
  *        @arg @ref LL_RCC_HCLK_SRC_HSE
  *        @arg @ref LL_RCC_HCLK_SRC_PLL
  *        @arg @ref LL_RCC_HCLK_SRC_LS 
  */
__STATIC_INLINE uint32_t LL_RCC_GetPCLKSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC);
}

/**
  * @brief  set System clock source
  * @rmtoll HCLK_SEL           HCLKSRC      LL_RCC_SetSysClkSrc
  * @param Src This parameter can be one of the following values:
  *        @arg @ref LL_RCC_HCLK_SRC_HSI
  *        @arg @ref LL_RCC_HCLK_SRC_HSE
  *        @arg @ref LL_RCC_HCLK_SRC_PLL
  *        @arg @ref LL_RCC_HCLK_SRC_LS 
  */
__STATIC_INLINE void LL_RCC_SetSysClkSrc(uint32_t Src)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC, Src);
}

/**
  * @brief  set system clock source
  * @rmtoll HCLK_SEL           HCLKSRC      LL_RCC_GetSysClkSrc
  * @retval This parameter can be one of the following values:
  *        @arg @ref LL_RCC_HCLK_SRC_HSI
  *        @arg @ref LL_RCC_HCLK_SRC_HSE
  *        @arg @ref LL_RCC_HCLK_SRC_PLL
  *        @arg @ref LL_RCC_HCLK_SRC_LS 
  */
__STATIC_INLINE uint32_t LL_RCC_GetSysClkSrc(void)
{
  return READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HCLKSRC);
}

/**
  * @brief  set System clock source
  * @rmtoll HCLK_SEL           HCLKSRC      LL_RCC_SetHCLKSrc
  * @param Src This parameter can be one of the following values:
  *         @arg @ref LL_RCC_PLL_SRC_HSI
  *         @arg @ref LL_RCC_PLL_SRC_HSE
  */
__STATIC_INLINE void LL_RCC_SetPLLClkSrc(uint32_t Src)
{
  MODIFY_REG(ICG->PLL_LFCFG_CTRL, ICG_PLL_CLKSRC, Src);
}

/**
  * @brief  set system clock source
  * @rmtoll HCLK_SEL           PLL_CLKSRC      LL_RCC_GetPLLClkSrc
  * @retval This parameter can be one of the following values:
  *         @arg @ref LL_RCC_PLL_SRC_HSI
  *         @arg @ref LL_RCC_PLL_SRC_HSE
  */
__STATIC_INLINE uint32_t LL_RCC_GetPLLClkSrc(void)
{
  return READ_BIT(ICG->PLL_LFCFG_CTRL, ICG_PLL_CLKSRC);
}

/**
  * @}
  */

/** @defgroup RCC_LL_Exported_Functions_Group3 PLL clock divisor
  * @{
  */
/**
  * @brief  Set PLL divider 
  * @rmtoll PLL_DIV           N         LL_RCC_SetPLLDiv\n
  * @rmtoll PLL_DIV           M         LL_RCC_SetPLLDiv\n
  * @rmtoll PLL_DIV           R         LL_RCC_SetPLLDiv
  * @param M Pre-divider 
  *          This parameters can be one of the following values: 
  *          @arg LL_RCC_PLLM_DIV_x
  * @param N Feedback divider
  *          This parameters can be one of the following values: 
  *          @arg LL_RCC_PLLN_DIV_x    (x = 1 to 63)
  * @param R Post divider 
  *          This parameters can be one of the following values: 
  *          @arg LL_RCC_PLLR_DIV_x
  */
__STATIC_INLINE void LL_RCC_SetPLLDiv(uint32_t M, uint32_t N, uint32_t R)
{
  uint32_t tmp = M|N|R;
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_PREDIV | ICG_PLL_FBDIV | ICG_PLL_POSTDIV, tmp);
}

/**
  * @brief  Set PLL M divider 
  * @rmtoll PLL_DIV           M         LL_RCC_SETPLLM
  * @param M pre-divider
  *          This parameters can be one of the following values: 
  *          @arg LL_RCC_PLLM_DIV_x
  */
__STATIC_INLINE void LL_RCC_SetPLLM(uint32_t M)
{
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_PREDIV, M);
}

/**
  * @brief  Set PLL N divider 
  * @rmtoll PLL_DIV           N         LL_RCC_SETPLLN
  * @param N feedback divider
  *          This parameters can be one of the following values: 
  *          @arg LL_RCC_PLLN_DIV_x    (x = 1 to 63)
  */
__STATIC_INLINE void LL_RCC_SetPLLN(uint32_t N)
{
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_FBDIV, N);
}

/**
  * @brief  Set PLL R divider 
  * @rmtoll PLL_DIV           M         LL_RCC_SETPLLR
  * @param R post divider
  *          This parameters can be one of the following values: 
  *          @arg LL_RCC_PLLR_DIV_x
  */
__STATIC_INLINE void LL_RCC_SetPLLR(uint32_t R)
{
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_POSTDIV, R);
}

/**
  * @brief  Get PLL M divider 
  * @rmtoll PLL_DIV           M         LL_RCC_GeTPLLM
  * @retval the return value can be one of the follow values:
  *          @arg LL_RCC_PLLM_DIV_x
  */
__STATIC_INLINE uint32_t LL_RCC_GetPLLM(void)
{
  return (READ_BIT(ICG->PLL_DIV, ICG_PLL_PREDIV));
}

/**
  * @brief  Get PLL N divider 
  * @rmtoll PLL_DIV           N         LL_RCC_GetPLLN
  * @retval the return value can be one of the follow values:
  *          @arg LL_RCC_PLLN_DIV_x    (x = 1 to 63)
  */
__STATIC_INLINE uint32_t LL_RCC_GetPLLN(void)
{
  return (READ_BIT(ICG->PLL_DIV, ICG_PLL_FBDIV)) ;
}

/**
  * @brief  Get PLL R divider 
  * @rmtoll PLL_DIV           R         LL_RCC_GETPLLR
  * @retval the return value can be one of the follow values:
  *          @arg LL_RCC_PLLR_DIV_x
  */
__STATIC_INLINE uint32_t LL_RCC_GetPLLR(void)
{
  return ((READ_BIT(ICG->PLL_DIV, ICG_PLL_POSTDIV)));
}

/**
  * @}
  */

/** @defgroup RCC_LL_Exported_Functions_Group4 clock divisor
  * @{
  */
/**
  * @brief  Set HCLK divider 
  * @rmtoll HCLK_DIV           DIV         LL_RCC_SetHCLKDiv
  * @param Div HCLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetHCLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->HCLK_DIV, Div);
}

/**
  * @brief  Get HCLK divider 
  * @rmtoll HCLK_DIV           DIV         LL_RCC_GetHCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetHCLKDiv(void)
{
  return READ_REG(ICG->HCLK_DIV);
}

/**
  * @brief  Set PCLK divider 
  * @rmtoll PCLK_DIV           DIV         LL_RCC_SetPCLKDiv
  * @param Div HCLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetPCLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->PCLK_DIV, Div);
}

/**
  * @brief  Get PCLK divider 
  * @rmtoll PCLK_DIV           DIV         LL_RCC_GetPCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetPCLKDiv(void)
{
  return READ_REG(ICG->PCLK_DIV);
}

/**
  * @brief  Set DMA CLK divider 
  * @rmtoll DMA_CLK_DIV           DIV         LL_RCC_SetDMACLKDiv
  * @param Div DMA CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetDMACLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->DMA_CLK_DIV, Div);
}

/**
  * @brief  Get DMA CLK divider 
  * @rmtoll DMA_CLK_DIV           DIV         LL_RCC_GetDMACLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetDMACLKDiv(void)
{
  return READ_REG(ICG->DMA_CLK_DIV);
}

/**
  * @brief  Set BR CLK divider 
  * @rmtoll BR_CLK_DIV           DIV         LL_RCC_SetBRCLKDiv
  * @param Div BR CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetBRCLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->BR_CLK_DIV, Div);
}

/**
  * @brief  Get BR CLK divider 
  * @rmtoll BR_CLK_DIV           DIV         LL_RCC_GetBRCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetBRCLKDiv(void)
{
  return READ_REG(ICG->BR_CLK_DIV);
}

/**
  * @brief  Set I2C1 CLK divider 
  * @rmtoll I2C1_CLK_DIV           DIV         LL_RCC_SetI2C0CLKDiv
  * @param Div I2C1 CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetI2C1CLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->I2C1_CLK_DIV, Div);
}

/**
  * @brief  Get I2C1 CLK divider 
  * @rmtoll I2C1_CLK_DIV           DIV         LL_RCC_GetI2C0CLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetI2C1CLKDiv(void)
{
  return READ_REG(ICG->I2C1_CLK_DIV);
}

/**
  * @brief  Set I2C2 CLK divider 
  * @rmtoll I2C2_CLK_DIV           DIV         LL_RCC_SetI2C1CLKDiv
  * @param Div I2C2 CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetI2C2CLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->I2C2_CLK_DIV, Div);
}

/**
  * @brief  Get I2C2 CLK divider 
  * @rmtoll I2C2_CLK_DIV           DIV         LL_RCC_GetI2C1CLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetI2C2CLKDiv(void)
{
  return READ_REG(ICG->I2C2_CLK_DIV);
}

/**
  * @brief  Set GPIO CLK divider 
  * @rmtoll GPIO_CLK_DIV           DIV         LL_RCC_SetGPIOCLKDiv
  * @param Div GPIO CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetGPIOCLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->GPIO_CLK_DIV, Div);
}

/**
  * @brief  Get GPIO CLK divider 
  * @rmtoll GPIO_CLK_DIV           DIV         LL_RCC_GetGPIOCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetGPIOCLKDiv(void)
{
  return READ_REG(ICG->GPIO_CLK_DIV);
}

/**
  * @brief  Set Timer CLK divider 
  * @rmtoll GPIO_CLK_DIV           DIV         LL_RCC_SetGPIOCLKDiv
  * @param Div GPIO CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetTIMAGCLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->TIMER_ADV_CLK_DIV, Div);
}

/**
  * @brief  Get Timer CLK divider 
  * @rmtoll GPIO_CLK_DIV           DIV         LL_RCC_GetGPIOCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetTIMAGCLKDiv(void)
{
  return READ_REG(ICG->TIMER_ADV_CLK_DIV);
}

/**
  * @brief  Set Timer CLK divider 
  * @rmtoll TIMER_B1_CLK_DIV           DIV         LL_RCC_SetGPIOCLKDiv
  * @param Div GPIO CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetTIMB1CLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->TIMER_B1_CLK_DIV, Div);
}

/**
  * @brief  Get Timer CLK divider 
  * @rmtoll TIMER_B1_CLK_DIV           DIV         LL_RCC_GetGPIOCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetTIMB1CLKDiv(void)
{
  return READ_REG(ICG->TIMER_B1_CLK_DIV);
}

/**
  * @brief  Set Timer CLK divider 
  * @rmtoll TIMER_B2_CLK_DIV           DIV         LL_RCC_SetGPIOCLKDiv
  * @param Div GPIO CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetTIMB2CLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->TIMER_B2_CLK_DIV, Div);
}

/**
  * @brief  Get Timer CLK divider 
  * @rmtoll TIMER_B2_CLK_DIV           DIV         LL_RCC_GetGPIOCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetTIMB2CLKDiv(void)
{
  return READ_REG(ICG->TIMER_B2_CLK_DIV);
}

/**
  * @brief  Set WDTW CLK divider 
  * @rmtoll GPIO_CLK_DIV           DIV         LL_RCC_SetGPIOCLKDiv
  * @param Div GPIO CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetWDTWCLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->WDT_W_CLK_DIV, Div);
}

/**
  * @brief  Get WDTW CLK divider 
  * @rmtoll GPIO_CLK_DIV           DIV         LL_RCC_GetGPIOCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetWDTWCLKDiv(void)
{
  return READ_REG(ICG->WDT_W_CLK_DIV);
}

/**
  * @brief  Set ADC CLK divider 
  * @rmtoll ADC_CLK_DIV           DIV         LL_RCC_SetADCCLKDiv
  * @param Div ADC CLK divider (0 to 0xFFFFFFFF)
  */
__STATIC_INLINE void LL_RCC_SetADCCLKDiv(uint32_t Div)
{
  WRITE_REG(ICG->ADC_CLK_DIV, Div);
}

/**
  * @brief  Get ADC CLK divider 
  * @rmtoll ADC_CLK_DIV           DIV         LL_RCC_GetADCCLKDiv
  * @retval the return value is between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetADCCLKDiv(void)
{
  return READ_REG(ICG->ADC_CLK_DIV);
}

#if defined(XT32H0xxAMPW)
/**
  * @brief  Set RCOSC Bias 
  * @rmtoll ICG.RC16M_CTRL           CBIAS         LL_RCC_SetRCBias
  * @param Bias
  *        the parameter value is between 0 to 0x7
  */
__STATIC_INLINE void LL_RCC_SetRCBias(uint32_t Bias)
{
  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CBIAS, (Bias << ICG_RC16M_CTRL_CBIAS_Pos)) ;
}

/**
  * @brief  Get RCOSC Bias 
  * @rmtoll ICG.RC16M_CTRL           CBIAS         LL_RCC_GetRCBias
  * @retval the return value is between 0 to 7
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCBias(void)
{
  return (READ_BIT(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CBIAS) >> ICG_RC16M_CTRL_CBIAS_Pos) ;
}

/**
  * @brief  Set RCOSC Comp 
  * @rmtoll ICG.RC16M_CTRL           CCOMP         LL_RCC_SetRCComp
  * @param Comp
  *        the parameter value is between 0 to 0x7
  */
__STATIC_INLINE void LL_RCC_SetRCComp(uint32_t Comp)
{
  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CCOMP, (Comp << ICG_RC16M_CTRL_CCOMP_Pos)) ;
}

/**
  * @brief  Get RCOSC Comp 
  * @rmtoll ICG.RC16M_CTRL           CCOMP         LL_RCC_GetRCComp
  * @retval the return value is between 0 to 0x7
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCComp(void)
{
  return (READ_BIT(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CCOMP) >> ICG_RC16M_CTRL_CCOMP_Pos) ;
}

/**
  * @brief  Set RCOSC Cap 
  * @rmtoll ICG.RC16M_CTRL           CCAP         LL_RCC_SetRCCap
  * @param Cap
  *        the parameter value is between 0 to 0x7F
  */
__STATIC_INLINE void LL_RCC_SetRCCap(uint32_t Cap)
{
  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CCAP, (Cap << ICG_RC16M_CTRL_CCAP_Pos)) ;
}

/**
  * @brief  Get RCOSC Cap 
  * @rmtoll ICG.RC16M_CTRL           CCAP         LL_RCC_GetRCCap
  * @retval the return value is between 0 to 0x7F
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCCap(void)
{
  return (READ_BIT(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CCAP) >> ICG_RC16M_CTRL_CCAP_Pos) ;
}

/**
  * @brief  Set RCOSC Res 
  * @rmtoll ICG.RC16M_CTRL           CRES         LL_RCC_SetRCRes
  * @param Res
  *        the parameter value is between 0 to 0x7F
  */
__STATIC_INLINE void LL_RCC_SetRCRes(uint32_t Res)
{
  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CRES, (Res << ICG_RC16M_CTRL_CRES_Pos)) ;
}

/**
  * @brief  Get RCOSC Res 
  * @rmtoll ICG.RC16M_CTRL           CRES         LL_RCC_GetRCRes
  * @retval the return value is between 0 to 0x7F
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCRes(void)
{
  return (READ_BIT(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CRES) >> ICG_RC16M_CTRL_CRES_Pos) ;
}

#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
/**
  * @brief  Set RCOSC Comp 
  * @rmtoll ICG.RC16M_CTRL           CCOMP         LL_RCC_SetRCComp
  * @param Comp
  *        the parameter value is between 0 to 0x7
  */
__STATIC_INLINE void LL_RCC_SetRCComp(uint32_t Comp)
{
  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_COMP_ISEL, (Comp << ICG_RC16M_CTRL_COMP_ISEL_Pos)) ;
}

/**
  * @brief  Get RCOSC Comp 
  * @rmtoll ICG.RC16M_CTRL           CCOMP         LL_RCC_GetRCComp
  * @retval the return value is between 0 to 0x7
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCComp(void)
{
  return (READ_BIT(ICG->RC16M_CTRL, ICG_RC16M_CTRL_COMP_ISEL) >> ICG_RC16M_CTRL_COMP_ISEL_Pos) ;
}

/**
  * @brief  Set RCOSC Cap 
  * @rmtoll ICG.RC16M_CTRL           OPAM         LL_RCC_SetRCOpam
  * @param Opam
  *        the parameter value is between 0 to 0x7F
  */
__STATIC_INLINE void LL_RCC_SetRCOpam(uint32_t Opam)
{
  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_OPAM_ISEL, (Opam << ICG_RC16M_CTRL_OPAM_ISEL_Pos)) ;
}

/**
  * @brief  Get RCOSC Cap 
  * @rmtoll ICG.RC16M_CTRL           OPAM         LL_RCC_GetRCOpam
  * @retval the return value is between 0 to 0x7F
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCOpam(void)
{
  return (READ_BIT(ICG->RC16M_CTRL, ICG_RC16M_CTRL_OPAM_ISEL) >> ICG_RC16M_CTRL_OPAM_ISEL_Pos) ;
}

/**
  * @brief  Set RCOSC Res 
  * @rmtoll ICG.RC16M_CTRL           CRES         LL_RCC_SetRCRes
  * @param Res
  *        the parameter value is between 0 to 0xFF
  */
__STATIC_INLINE void LL_RCC_SetRCRes(uint32_t Res)
{
  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CRES, (Res << ICG_RC16M_CTRL_CRES_Pos)) ;
}

/**
  * @brief  Get RCOSC Res 
  * @rmtoll ICG.RC16M_CTRL           CRES         LL_RCC_GetRCRes
  * @retval the return value is between 0 to 0xFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetRCRes(void)
{
  return (READ_BIT(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CRES) >> ICG_RC16M_CTRL_CRES_Pos) ;
}

/**
  * @brief  Set RCOSC Mode 
  * @rmtoll ICG.RC16M_CTRL           CALIB         LL_RCC_SetHSIMode
  * @param Mode
  *        the parameter value can be one of the following values:
  *        @arg @ref LL_RCC_HSI_NORMAL
  *        @arg @ref LL_RCC_HSI_CALIB 
  */
__STATIC_INLINE void LL_RCC_SetHSIMode(uint32_t Mode)
{
  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CALI, Mode);
}
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

/**
  * @brief  Set HSXTAL I tune 
  * @rmtoll ICG.CLK_CFG           ITUNE         LL_RCC_SetHSXTALITune
  * @param Tune
  *        the parameter value is between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetHSXTALITune(uint32_t Tune)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_ITUNE, (Tune << ICG_CLK_CTL_HSXTAL_ITUNE_Pos)) ;
}

/**
  * @brief  Get HSXTAL I tune 
  * @rmtoll ICG.CLK_CFG           ITUNE         LL_RCC_GetHSXTALITune
  * @retval the return value is between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetHSXTALITune(void)
{
  return (READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_ITUNE) >> ICG_CLK_CTL_HSXTAL_ITUNE_Pos) ;
}

/**
  * @brief  Set HSXTAL Cap tune 
  * @rmtoll ICG.CLK_CFG           CAPTUNE         LL_RCC_SetHSXTALCapTune
  * @param Tune
  *        the parameter value is between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetHSXTALCapTune(uint32_t Tune)
{
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_CTUNE, (Tune << ICG_CLK_CTL_HSXTAL_CTUNE_Pos)) ;
}

/**
  * @brief  Get HSXTAL Cap tune 
  * @rmtoll ICG.CLK_CFG           CAPTUNE         LL_RCC_GetHSXTALCapTune
  * @retval the return value is between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetHSXTALCapTune(void)
{
  return (READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_CTUNE) >> ICG_CLK_CTL_HSXTAL_CTUNE_Pos) ;
}

/**
  * @brief  HSXTAL res enable 
  * @rmtoll ICG.CLK_CFG           RES         LL_RCC_HSXTALResEnable
  */
__STATIC_INLINE void LL_RCC_HSXTALResEnable(void)
{
  SET_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_CRES);
}

/**
  * @brief  HSXTAL res disable 
  * @rmtoll ICG.CLK_CFG           RES         LL_RCC_HSXTALResDisable
  */
__STATIC_INLINE void LL_RCC_HSXTALResDisable(void)
{
  CLEAR_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL_CRES);
}

/**
  * @brief  Set VCO Bias 
  * @rmtoll ICG.PLL_DIV           VCOBIAS         LL_RCC_SetVCOBias
  * @param Bias
  *        the parameter value is between 0 to 0xFF
  */
__STATIC_INLINE void LL_RCC_SetVCOBias(uint32_t Bias)
{
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_VCOBIAS, (Bias << ICG_PLL_VCOBIAS_Pos)) ;
}

/**
  * @brief  Get VCO Bias 
  * @rmtoll ICG.PLL_DIV           VCOBIAS         LL_RCC_GetVCOBias
  * @retval the return value is between 0 to 0xFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetVCOBias(void)
{
  return (READ_BIT(ICG->PLL_DIV, ICG_PLL_VCOBIAS) >> ICG_PLL_VCOBIAS_Pos) ;
}

/**
  * @brief  Set VCO Cap 
  * @rmtoll ICG.PLL_DIV           VCOCAP         LL_RCC_SetVCOCap
  * @param Cap
  *        the parameter value is between 0 to 0x3
  */
__STATIC_INLINE void LL_RCC_SetVCOCap(uint32_t Cap)
{
  MODIFY_REG(ICG->PLL_DIV, ICG_PLL_VCOCAP, (Cap << ICG_PLL_VCOCAP_Pos)) ;
}

/**
  * @brief  Get VCO Cap 
  * @rmtoll ICG.PLL_DIV           VCOCAP         LL_RCC_GetVCOCap
  * @retval the return value is between 0 to 0x3
  */
__STATIC_INLINE uint32_t LL_RCC_GetVCOCap(void)
{
  return (READ_BIT(ICG->PLL_DIV, ICG_PLL_VCOCAP) >> ICG_PLL_VCOCAP_Pos) ;
}

/**
  * @brief  PLL RB_FB div enable 
  * @rmtoll ICG.PLL_DIV           RB_FBDIV         LL_RCC_PLLRbFbDivEnable
  */
__STATIC_INLINE void LL_RCC_PLLRbFbDivEnable(void)
{
  SET_BIT(ICG->PLL_DIV, ICG_PLL_RBFBDIV);
}

/**
  * @brief  PLL RB_FB div disable 
  * @rmtoll ICG.PLL_DIV           RB_FBDIV         LL_RCC_PLLRbFbDivDisable
  */
__STATIC_INLINE void LL_RCC_PLLRbFbDivDisable(void)
{
  CLEAR_BIT(ICG->PLL_DIV, ICG_PLL_RBFBDIV);
}

/**
  * @brief  PLL RB_POST div enable 
  * @rmtoll ICG.PLL_DIV           RB_POSTDIV         LL_RCC_PLLRbPostDivEnable
  */
__STATIC_INLINE void LL_RCC_PLLRbPostDivEnable(void)
{
  SET_BIT(ICG->PLL_DIV, ICG_PLL_RBPOSTDIV);
}

/**
  * @brief  PLL RB_POST div disable 
  * @rmtoll ICG.PLL_DIV           RB_POSTDIV         LL_RCC_PLLRbPostDivDisable
  */
__STATIC_INLINE void LL_RCC_PLLRbPostDivDisable(void)
{
  CLEAR_BIT(ICG->PLL_DIV, ICG_PLL_RBPOSTDIV);
}

#if defined(XT32H0xxB)
/**
  * @brief  Set timer input (external clock or aux input) 
  * @rmtoll ICG.TIMER_EXCLK_EN           status         LL_RCC_SetTimerInput
  * @param Timer
  * @param Status 0: internal clock 1: Aux input
  */
__STATIC_INLINE void LL_RCC_SetBasicTimerInput(uint32_t Timer, uint32_t Status)
{
  if(Status == LL_RCC_TIMERS_INTERNAL_CLOCK)
  {
    CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, Timer);
  }
  else
  {
    SET_BIT(ICG->TIMER_EXCLK_EN_1, Timer);
  }
}

/**
  * @brief  Get timer input (external clock or aux input) 
  * @rmtoll ICG.TIMER_EXCLK_EN           status         LL_RCC_GetTimerInput
  * @param Timer
  * @retval Status 0: internal clock 1: Aux input
  */
__STATIC_INLINE uint32_t LL_RCC_GetBasicTimerInput(uint32_t Timer)
{
  return (uint32_t)(READ_BIT(ICG->TIMER_EXCLK_EN_1, Timer) ? SET : RESET);
}

/**
  * @brief  Set timer input (external clock or aux input) 
  * @rmtoll ICG.TIMER_EXCLK_EN           status         LL_RCC_SetTimerInput
  * @param Timer
  * @param Status 0: internal clock 1: Aux input
  */
__STATIC_INLINE void LL_RCC_SetAdvancedTimerInput(uint32_t Timer, uint32_t Status)
{
  if(Status == LL_RCC_TIMERS_INTERNAL_CLOCK)
  {
    CLEAR_BIT(ICG->TIMER_EXCLK_EN_1, Timer);
  }
  else
  {
    SET_BIT(ICG->TIMER_EXCLK_EN_1, Timer);
  }
}

/**
  * @brief  Get timer input (external clock or aux input) 
  * @rmtoll ICG.TIMER_EXCLK_EN           status         LL_RCC_GetTimerInput
  * @param Timer
  * @retval Status 0: internal clock 1: Aux input
  */
__STATIC_INLINE uint32_t LL_RCC_GetAdvancedTimerInput(uint32_t Timer)
{
  return (uint32_t)(READ_BIT(ICG->TIMER_EXCLK_EN_1, Timer) ? SET : RESET);
}

/**
  * @brief  Set timer input (external clock or aux input) 
  * @rmtoll ICG.TIMER_EXCLK_EN           status         LL_RCC_SetTimerInput
  * @param Timer
  * @param Status 0: internal clock 1: Aux input
  */
__STATIC_INLINE void LL_RCC_SetGeneralTimerInput(uint32_t Timer, uint32_t Status)
{
  if(Status == LL_RCC_TIMERS_INTERNAL_CLOCK)
  {
    CLEAR_BIT(ICG->TIMER_EXCLK_EN_2, Timer);
  }
  else
  {
    SET_BIT(ICG->TIMER_EXCLK_EN_2, Timer);
  }
}

/**
  * @brief  Get timer input (external clock or aux input) 
  * @rmtoll ICG.TIMER_EXCLK_EN           status         LL_RCC_GetTimerInput
  * @param Timer
  * @retval Status 0: internal clock 1: Aux input
  */
__STATIC_INLINE uint32_t LL_RCC_GetGeneralTimerInput(uint32_t Timer)
{
  return (uint32_t)(READ_BIT(ICG->TIMER_EXCLK_EN_2, Timer) ? SET : RESET);
}
#else
/**
  * @brief  Set timer input (external clock or aux input) 
  * @rmtoll ICG.TIMER_EXCLK_EN           status         LL_RCC_SetTimerInput
  * @param Timer
  * @param Status 0: internal clock 1: Aux input
  */
__STATIC_INLINE void LL_RCC_SetTimerInput(uint32_t Timer, uint32_t Status)
{
  if(Status == LL_RCC_TIMERS_INTERNAL_CLOCK)
  {
    CLEAR_BIT(ICG->TIMER_EXCLK_EN, Timer);
  }
  else
  {
    SET_BIT(ICG->TIMER_EXCLK_EN, Timer);
  }
}

/**
  * @brief  Get timer input (external clock or aux input) 
  * @rmtoll ICG.TIMER_EXCLK_EN           status         LL_RCC_GetTimerInput
  * @param Timer
  * @retval Status 0: internal clock 1: Aux input
  */
__STATIC_INLINE uint32_t LL_RCC_GetTimerInput(uint32_t Timer)
{
  return (uint32_t)(READ_BIT(ICG->TIMER_EXCLK_EN, Timer) ? SET : RESET);
}
#endif /*XT32H0xxB*/
/**
  * @brief  Set LS clock source 
  * @rmtoll AON.AON_CFG           LSSRC         LL_RCC_SetLSClockSource
  * @param Src clock source
  *        The parameter can be on of the following values:
  *        @arg @ref LL_RCC_LS_SOURCE_LSI 
  *        @arg @ref LL_RCC_LS_SOURCE_LSE 
  */
__STATIC_INLINE void LL_RCC_SetLSClockSource(uint32_t Src)
{
  MODIFY_REG(AON->AON_CFG, AON_CFG_32KCLKSRC, Src);
}

/**
  * @brief  Get LS clock source 
  * @rmtoll AON.AON_CFG           LSSRC         LL_RCC_GetLSClockSource
  * @retval the return value can be one of the following value: 
  *        @arg @ref LL_RCC_LS_SOURCE_LSI 
  *        @arg @ref LL_RCC_LS_SOURCE_LSE 
  */
__STATIC_INLINE uint32_t LL_RCC_GetLSClockSource(void)
{
  return (READ_BIT(AON->AON_CFG, AON_CFG_32KCLKSRC) );
}

/**
  * @brief  Reset RTC 
  * @rmtoll AON.AON_CFG           RTCRST         LL_RCC_RTCReset
  */
__STATIC_INLINE void LL_RCC_RTCReset(void)
{
  CLEAR_BIT(AON->AON_CFG, AON_CFG_RTCRST);
}

/**
  * @brief  Release Reset RTC 
  * @rmtoll AON.AON_CFG           RTCRST         LL_RCC_RTCResetRelease
  */
__STATIC_INLINE void LL_RCC_RTCResetRelease(void)
{
  SET_BIT(AON->AON_CFG, AON_CFG_RTCRST);
}

/**
  * @brief  enable independent WDT 
  * @rmtoll AON.AON_CFG           WDTI_EN         LL_RCC_EnableWDTI
  */
__STATIC_INLINE void LL_RCC_EnableWDTI(void)
{
  SET_BIT(AON->AON_CFG, AON_CFG_WDTI_EN);
}

/**
  * @brief  disable independent WDT 
  * @rmtoll AON.AON_CFG           WDTI_EN         LL_RCC_DisableWDTI
  */
__STATIC_INLINE void LL_RCC_DisableWDTI(void)
{
  CLEAR_BIT(AON->AON_CFG, AON_CFG_WDTI_EN);
}

/**
  * @brief  test independent WDT 
  * @rmtoll AON.AON_CFG           WDTI_SPD         LL_RCC_WDTITestMode
  */
__STATIC_INLINE void LL_RCC_WDTITestMode(void)
{
  SET_BIT(AON->AON_CFG, AON_CFG_WDTI_SPD);
}

/**
  * @brief  normal independent WDT 
  * @rmtoll AON.AON_CFG           WDTI_SPD         LL_RCC_WDTINormal
  */
__STATIC_INLINE void LL_RCC_WDTINormal(void)
{
  CLEAR_BIT(AON->AON_CFG, AON_CFG_WDTI_SPD);
}

/**
  * @brief  Set RTC reference clock divider 
  * @rmtoll AON.RTC_REFCLK_DIV           DIV         LL_RCC_SetRTCRefClkDiv
  * @param Div clock source
  *        The parameter can be between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE void LL_RCC_SetRTCRefClkDiv(uint32_t Div)
{
  WRITE_REG(AON->RTC_REFCLK_DIV, Div);
}

/**
  * @brief  Get RTC reference clock divider 
  * @rmtoll AON.RTC_REFCLK_DIV           DIV         LL_RCC_GetRTCRefClkDiv
  * @retval The return value can be between 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_RCC_GetRTCRefClkDiv(void)
{
  return READ_REG(AON->RTC_REFCLK_DIV);
}

/**
  * @brief  32K RCOSC enable 
  * @rmtoll AON.AON_CLK_CTRL           RCOSCEN         LL_RCC_LSRCEnable
  */
__STATIC_INLINE void LL_RCC_LSI_Enable(void)
{
  CLEAR_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_PD);
}

/**
  * @brief  32K RCOSC disable 
  * @rmtoll AON.AON_CLK_CTRL           RCOSCEN         LL_RCC_LSRCDisable
  */
__STATIC_INLINE void LL_RCC_LSI_Disable(void)
{
  SET_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_PD);
}

/**
  * @brief  32K XTAL enable 
  * @rmtoll AON.AON_CLK_CTRL           XTALEN         LL_RCC_LSXTALEnable
  */
__STATIC_INLINE void LL_RCC_LSE_Enable(void)
{
  CLEAR_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_PD);
}

/**
  * @brief  32K XTAL disable 
  * @rmtoll AON.AON_CLK_CTRL           XTALEN         LL_RCC_LSXTALDisable
  */
__STATIC_INLINE void LL_RCC_LSE_Disable(void)
{
  SET_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_PD);
}

/**
  * @brief  32K XTAL i tune 
  * @rmtoll AON.AON_CLK_CTRL           XTALITUNE         LL_RCC_SetLSXTALITune
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetLSXTALITune(uint32_t Val)
{
  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_ITUNE, Val << AON_CLKCTRL_32KXTAL_ITUNE_Pos);
}

/**
  * @brief  32K XTAL i tune 
  * @rmtoll AON.AON_CLK_CTRL           XTALITUNE         LL_RCC_GetLSXTALITune
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetLSXTALITune(void)
{
  return (READ_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_ITUNE) >> AON_CLKCTRL_32KXTAL_ITUNE_Pos);
}

/**
  * @brief  32K XTAL cap tune 
  * @rmtoll AON.AON_CLK_CTRL           XTALCAPTUNE         LL_RCC_SetLSXTALCapTune
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetLSXTALCapTune(uint32_t Val)
{
  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_CAPTUNE, Val << AON_CLKCTRL_32KXTAL_CAPTUNE_Pos);
}

/**
  * @brief  32K XTAL Cap tune 
  * @rmtoll AON.AON_CLK_CTRL           XTALCAPTUNE         LL_RCC_GetLSXTALCapTune
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetLSXTALCapTune(void)
{
  return (READ_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KXTAL_CAPTUNE) >> AON_CLKCTRL_32KXTAL_CAPTUNE_Pos);
}

/**
  * @brief  32K RX res tune 
  * @rmtoll AON.AON_CLK_CTRL           RCRESTUNE         LL_RCC_SetLSRCResTune
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetLSRCResTune(uint32_t Val)
{
  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_RESTUNE, Val << AON_CLKCTRL_32KRC_RESTUNE_Pos);
}

/**
  * @brief  32K RC res tune 
  * @rmtoll AON.AON_CLK_CTRL           RCRESTUNE         LL_RCC_GetLSRCResTune
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetLSRCResTune(void)
{
  return (READ_BIT(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_RESTUNE) >> AON_CLKCTRL_32KRC_RESTUNE_Pos);
}

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
/**
  * @brief  Set LSI mode 
  * @rmtoll AON.AON_CLK_CTRL           LSI_CALI         LL_RCC_SetLSRCResTune
  * @param Mode 
  *        The parameter can be one of the following value:
  *        @arg @ref LL_RCC_LSI_MODE_NORMAL
  *        @arg @ref LL_RCC_LSI_MODE_CALIB
  */
__STATIC_INLINE void LL_RCC_SetLSIMode(uint32_t Mode)
{
  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32K_CAL, Mode);
}
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

/**
  * @brief  IVref power on 
  * @rmtoll AON.LDO_CFG           IVREF_PD         LL_RCC_IVrefEnable
  */
__STATIC_INLINE void LL_RCC_IVrefEnable(void)
{
  CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_IVREF_PD);
}

/**
  * @brief  LDO Core disable 
  * @rmtoll AON.LDO_CFG           IVREF_PD         LL_RCC_IVrefDisable
  */
__STATIC_INLINE void LL_RCC_IVrefDisable(void)
{
  SET_BIT(AON->LDO_CFG, AON_LDO_CFG_IVREF_PD);
}

/**
  * @brief  LDO Core enable 
  * @rmtoll AON.LDO_CFG           XTALEN         LL_RCC_LDOCoreEnable
  */
__STATIC_INLINE void LL_RCC_DVDDEnable(void)
{
  CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_CORE_PD);
}

/**
  * @brief  LDO Core disable 
  * @rmtoll AON.LDO_CFG           XTALEN         LL_RCC_LDOCoreDisable
  */
__STATIC_INLINE void LL_RCC_DVDDDisable(void)
{
  SET_BIT(AON->LDO_CFG, AON_LDO_CFG_CORE_PD);
}

/**
  * @brief  LDO Analog enable 
  * @rmtoll AON.LDO_CFG           XTALEN         LL_RCC_LDOAnalogEnable
  */
__STATIC_INLINE void LL_RCC_AVDDEnable(void)
{
  CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_ANALOG_PD);
}

/**
  * @brief  LDO Ananlog disable 
  * @rmtoll AON.LDO_CFG           XTALEN         LL_RCC_LDOAnalogDisable
  */
__STATIC_INLINE void LL_RCC_AVDDDisable(void)
{
  SET_BIT(AON->LDO_CFG, AON_LDO_CFG_ANALOG_PD);
}

/**
  * @brief  LDO IO enable 
  * @rmtoll AON.LDO_CFG           XTALEN         LL_RCC_LDOIOEnable
  */
__STATIC_INLINE void LL_RCC_HVDDEnable(void)
{
  CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_IO_PD);
}

/**
  * @brief  LDO IO disable 
  * @rmtoll AON.LDO_CFG           XTALEN         LL_RCC_LDOIODisable
  */
__STATIC_INLINE void LL_RCC_HVDDDisable(void)
{
  SET_BIT(AON->LDO_CFG, AON_LDO_CFG_IO_PD);
}

/**
  * @brief  Voltage detector enable 
  * @rmtoll AON.LDO_CFG           XTALEN         LL_RCC_LDOVolDetEnable
  */
__STATIC_INLINE void LL_RCC_VolDetEnable(void)
{
  CLEAR_BIT(AON->LDO_CFG, AON_LDO_CFG_VOLDET_PD);
}

/**
  * @brief  Voltage detector disable 
  * @rmtoll AON.LDO_CFG           XTALEN         LL_RCC_LDOVolDetDisable
  */
__STATIC_INLINE void LL_RCC_VolDetDisable(void)
{
  SET_BIT(AON->LDO_CFG, AON_LDO_CFG_VOLDET_PD);
}

/**
  * @brief  Set LDO core output voltage tune 
  * @rmtoll AON.LDO_CFG           RCRESTUNE         LL_RCC_SetLDOCoreTune
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetDVDDTune(uint32_t Val)
{
  MODIFY_REG(AON->LDO_CFG, AON_LDO_CFG_CORE_OTUNE, Val << AON_LDO_CFG_CORE_OTUNE_Pos);
}

/**
  * @brief  Get LDO core output voltage tune 
  * @rmtoll AON.LDO_CFG           RCRESTUNE         LL_RCC_GetLDOCoreTune
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetDVDDTune(void)
{
  return (READ_BIT(AON->LDO_CFG, AON_LDO_CFG_CORE_OTUNE) >> AON_LDO_CFG_CORE_OTUNE_Pos);
}

/**
  * @brief  Set LDO analog output voltage tune 
  * @rmtoll AON.LDO_CFG           RCRESTUNE         LL_RCC_SetLDOAnalogTune
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetAVDDTune(uint32_t Val)
{
  MODIFY_REG(AON->LDO_CFG, AON_LDO_CFG_ANALOG_OTUNE, Val << AON_LDO_CFG_ANALOG_OTUNE_Pos);
}

/**
  * @brief  Get LDO analog output voltage tune 
  * @rmtoll AON.LDO_CFG           RCRESTUNE         LL_RCC_GetLDOAnalogTune
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetAVDDTune(void)
{
  return (READ_BIT(AON->LDO_CFG, AON_LDO_CFG_ANALOG_OTUNE) >> AON_LDO_CFG_ANALOG_OTUNE_Pos);
}

/**
  * @brief  Set LDO io output voltage tune 
  * @rmtoll AON.LDO_CFG           RCRESTUNE         LL_RCC_SetLDOIOTune
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetHVDDTune(uint32_t Val)
{
  MODIFY_REG(AON->LDO_CFG, AON_LDO_CFG_IO_OTUNE, Val << AON_LDO_CFG_IO_OTUNE_Pos);
}

/**
  * @brief  Get LDO io output voltage tune 
  * @rmtoll AON.LDO_CFG           RCRESTUNE         LL_RCC_GetLDOIOTune
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetHVDDTune(void)
{
  return (READ_BIT(AON->LDO_CFG, AON_LDO_CFG_IO_OTUNE) >> AON_LDO_CFG_IO_OTUNE_Pos);
}

/**
  * @brief  Set LDO voltage detector trigger point 
  * @rmtoll AON.LDO_CFG           RCRESTUNE         LL_RCC_SetLDOVolDetTrg
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetVolDetTrg(uint32_t Val)
{
  MODIFY_REG(AON->LDO_CFG, AON_LDO_CFG_VOLDET_TRG, Val << AON_LDO_CFG_VOLDET_TRG_Pos);
}

/**
  * @brief  Get LDO voltage detector trigger point 
  * @rmtoll AON.LDO_CFG           RCRESTUNE         LL_RCC_GetLDOVolDetTrg
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetVolDetTrg(void)
{
  return (READ_BIT(AON->LDO_CFG, AON_LDO_CFG_VOLDET_TRG) >> AON_LDO_CFG_VOLDET_TRG_Pos);
}

#if defined(XT32H0xxB)
/**
  * @brief  Set PVD reference voltage 
  * @rmtoll AON.IVREF_CFG_1           AON_IVREF_CFG_1_PVD_REF         LL_RCC_SetPVDRefVol
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetPVDRefVol(uint32_t Val)
{
  MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_PVD_REF, Val << AON_IVREF_CFG_1_PVD_REF_Pos);
}

/**
  * @brief  Get PVD reference voltage 
  * @rmtoll AON.IVREF_CFG_1           AON_IVREF_CFG_1_PVD_REF         LL_RCC_GetPVDRefVol
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetPVDRefVol(void)
{
  return (READ_BIT(AON->IVREF_CFG_1, AON_IVREF_CFG_1_PVD_REF) >> AON_IVREF_CFG_1_PVD_REF_Pos);
}

/**
  * @brief  Set LED reference voltage 
  * @rmtoll AON.IVREF_CFG_1           AON_IVREF_CFG_1_LED_REF         LL_RCC_SetLEDRefVol
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetLEDRefVol(uint32_t Val)
{
  MODIFY_REG(AON->IVREF_CFG_1, AON_IVREF_CFG_1_LED_REF, Val << AON_IVREF_CFG_1_LED_REF_Pos);
}

/**
  * @brief  Get LED reference voltage 
  * @rmtoll AON.IVREF_CFG_1           AON_IVREF_CFG_1_LED_REF         LL_RCC_GetLEDRefVol
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetLEDRefVol(void)
{
  return (READ_BIT(AON->IVREF_CFG_1, AON_IVREF_CFG_1_LED_REF) >> AON_IVREF_CFG_1_LED_REF_Pos);
}

/**
  * @brief  Set TSU reference voltage 
  * @rmtoll AON.IVREF_CFG_3           AON_IVREF_CFG_3_TSU_REF         LL_RCC_SetTSURefVol
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetTSURefVol(uint32_t Val)
{
  MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_TSU_REF, Val << AON_IVREF_CFG_3_TSU_REF_Pos);
}

/**
  * @brief  Get TSU reference voltage 
  * @rmtoll AON.IVREF_CFG_3           AON_IVREF_CFG_3_TSU_REF         LL_RCC_GetTSURefVol
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetTSURefVol(void)
{
  return (READ_BIT(AON->IVREF_CFG_3, AON_IVREF_CFG_3_TSU_REF) >> AON_IVREF_CFG_3_TSU_REF_Pos);
}

/**
  * @brief  Set HSI reference voltage 
  * @rmtoll AON.IVREF_CFG_3           AON_IVREF_CFG_3_HSI_REF         LL_RCC_SetHSIRefVol
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetHSIRefVol(uint32_t Val)
{
  MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_HSI_REF, Val << AON_IVREF_CFG_3_HSI_REF_Pos);
}

/**
  * @brief  Get HSI reference voltage 
  * @rmtoll AON.IVREF_CFG_3           AON_IVREF_CFG_3_HSI_REF         LL_RCC_GetHSIRefVol
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetHSIRefVol(void)
{
  return (READ_BIT(AON->IVREF_CFG_3, AON_IVREF_CFG_3_HSI_REF) >> AON_IVREF_CFG_3_HSI_REF_Pos);
}

/**
  * @brief  Set LDO bias current 
  * @rmtoll AON.IVREF_CFG_3           AON_IVREF_CFG_3_LDO_BIAS         LL_RCC_SetLDOBiasCurrent
  * @param Val 
  *        The parameter can be between 0 to 0xF
  */
__STATIC_INLINE void LL_RCC_SetLDOBiasCurrent(uint32_t Val)
{
  MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_LDO_BIAS, Val << AON_IVREF_CFG_3_LDO_BIAS_Pos);
}

/**
  * @brief  Get LDO bias current 
  * @rmtoll AON.IVREF_CFG_3           AON_IVREF_CFG_3_LDO_BIAS         LL_RCC_GetLDOBiasCurrent
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetLDOBiasCurrent(void)
{
  return (READ_BIT(AON->IVREF_CFG_3, AON_IVREF_CFG_3_LDO_BIAS) >> AON_IVREF_CFG_3_LDO_BIAS_Pos);
}


/**
  * @brief  Enable deep sleep mode 
  * @rmtoll AON.DEEPSLEEP_CTRL           AON_DEEPSLEEP_CTRL_MODE         LL_RCC_DeepSleepEnable
  * @param Wakeup 
  *        The parameter can be one of the the following value:
  *        @arg @ref LL_RCC_DEEPSLEEP_EXTWAKEUP_DISABLE
  *        @arg @ref LL_RCC_DEEPSLEEP_EXTWAKEUP_ENABLE
  */
__STATIC_INLINE void LL_RCC_DeepSleepEnable(uint32_t Wakeup)
{
  AON->DEEPSLEEP_CTRL = AON_DEEPSLEEP_CTRL_MODE|Wakeup;
}

/**
  * @brief  Set deep sleep time 
  * @rmtoll AON.DEEPSLEEP_TIME           AON_DEEPSLEEP_TIME_TIME         LL_RCC_SetDeepSleepTime
  * @param Count 
  *        The parameter can be one of 1 to 0xFFFFFFFF
  */
__STATIC_INLINE void LL_RCC_SetDeepSleepTime(uint32_t Count)
{
  AON->DEEPSLEEP_TIME = Count;
}

/**
  * @brief  Get deep sleep time
  * @rmtoll AON.DEEPSLEEP_TIME           AON_DEEPSLEEP_TIME_TIME         LL_RCC_GetDeepSleepTime
  * @retval the return value can be between 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_RCC_GetDeepSleepTime(void)
{
  return (uint32_t)(AON->DEEPSLEEP_TIME);
}

#endif /* XT32H0xxB */

/**
  * @}
  */


#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_Exported_Functions_Group5 De-initialization function
  * @{
  */
ErrorStatus LL_RCC_DeInit(void);
/**
  * @}
  */

/** @defgroup RCC_LL_Exported_Functions_Group6 Get system and peripherals clocks frequency functions
  * @{
  */
void        LL_RCC_GetSystemClocksFreq(LL_RCC_ClocksTypeDef* RCC_Clocks);

uint32_t    LL_RCC_GetDMAClockFreq(void);

uint32_t    LL_RCC_GetGPIOClockFreq(void);
uint32_t    LL_RCC_GetBRClockFreq(void);
uint32_t    LL_RCC_GetI2C1ClockFreq(void);
uint32_t    LL_RCC_GetI2C2ClockFreq(void);

uint32_t    LL_RCC_GetADCClockFreq(void);
//uint32_t    LL_RCC_GetI2SClockFreq(uint32_t I2SxSource);
uint32_t    LL_RCC_GetTIMAGClockFreq(void);
uint32_t    LL_RCC_GetTIMB1ClockFreq(void);
uint32_t    LL_RCC_GetTIMB2ClockFreq(void);
uint32_t    LL_RCC_GetWDTWClockFreq(void);

uint32_t    LL_RCC_GetRTCClockFreq(void);
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* RCC */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_RCC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
