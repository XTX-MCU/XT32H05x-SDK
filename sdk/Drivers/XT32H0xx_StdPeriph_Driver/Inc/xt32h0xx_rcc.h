/**
  ******************************************************************************
  * @file    xt32h0xx_rcc.h
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file contains all the functions prototypes for the RCC 
  *          firmware library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_RCC_H
#define __XT32H0XX_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup RCC_Exported_Constants RCC Exported Constants
  * @{
  */

/** @defgroup RCC_LL_EC_OSC_VALUES Oscillator Values adaptation
  * @brief    Defines used to adapt values of different oscillators
  * @note     These values could be modified in the user environment according to
  *           HW set-up.
  * @{
  */
#ifndef  HSE_VALUE
#define HSE_VALUE                      (48000000U)                             /*!< Value of XTAL Oscillator in Hz */
#endif
#ifndef  HSI_VALUE
#define HSI_VALUE                      (16000000U)                             /*!< Value of RC Oscillator in Hz   */
#endif
#ifndef  LSE_VALUE
#define LSE_VALUE                      (32768U)                                /*!< Value of XTAL Oscillator in Hz */
#endif
#ifndef  LSI_VALUE
#define LSI_VALUE                      (32768U)                                /*!< Value of RC Oscillator in Hz   */
#endif
/**
  * @}
  */

/** @defgroup RCC_HSI_configuration RCC HSI Configurations
  * @{
  */

#define RCC_HSI_OFF                    (ICG_CLK_CTL_HSRC)  
#define RCC_HSI_ON                     (0x00000000U)

#define IS_RCC_HSI(HSI) (((HSI) == RCC_HSI_OFF) || ((HSI) == RCC_HSI_ON))
/**
  * @}
  */ 

/** @defgroup RCC_HSE_configuration RCC HSE Configurations
  * @{
  */

#define RCC_HSE_OFF                    (ICG_CLK_CTL_HSXTAL | ICG_CLK_CTL_HSXTALOUT) 
#define RCC_HSE_ON                     (0x00000000)

#define IS_RCC_HSE(HSE) (((HSE) == RCC_HSE_OFF) || ((HSE) == RCC_HSE_ON))
/**
  * @}
  */ 
 
/** @defgroup RCC_PLL_configuration RCC PLL Configurations
  * @{
  */
#define RCC_PLL_OFF                    (ICG_CLK_CTL_PLL)  
#define RCC_PLL_ON                     (0x00000000U)

#define IS_RCC_PLL(PLL) (((PLL) == RCC_PLL_OFF) || ((PLL) == RCC_PLL_ON))
/**
  * @}
  */ 

/** @defgroup RCC_PLL_Clock_Source RCC PLL Clock Source
  * @{
  */

#define RCC_PLLSOURCE_HSI              (0)
#define RCC_PLLSOURCE_HSE              (ICG_PLL_CLKSRC) 

#define IS_RCC_PLL_SOURCE(SOURCE) (((SOURCE) == RCC_PLLSOURCE_HSI) || ((SOURCE) == RCC_PLLSOURCE_HSE))
/**
  * @}
  */ 

/** @defgroup RCC_PLLN_Clock_Divider PLLN Feedback Divider
  * @{
  */
#if defined(XT32H0xxAMPW)
#define RCC_PLLN_DIV_FREQ_98M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_96M          ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_94M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_92M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_90M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_88M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_86M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_84M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_82M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_80M          ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_78M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_76M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_74M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_72M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_70M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_68M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_66M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_64M          ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_62M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_60M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_58M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_56M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_54M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_52M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_50M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_49M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_48M          ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_47M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_46M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_45M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_44M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_43M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_42M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_41M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_40M          ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_39M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_38M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_37M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_36M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_35M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_34M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_33M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_32M          ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_31M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_30M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_29M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_28M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_27M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_26M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_25M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_24M          ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_23M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_22M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_21M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_20M          ( ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_19M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_18M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_17M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_16M          ( ICG_PLL_FBDIV_5 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_15M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_14M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_13M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#define RCC_PLLN_DIV_FREQ_12M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_6 )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define RCC_PLLN_DIV_FREQ_99M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_98M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_97M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_96M          ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_95M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_94M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_93M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_92M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_91M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_90M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_89M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_88M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_87M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_86M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_85M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_84M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_83M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_82M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_81M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_80M          ( ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_79M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_78M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_77M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_76M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_75M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_74M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_73M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_72M          ( ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_71M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_70M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_69M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_68M          ( ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_67M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 )
#define RCC_PLLN_DIV_FREQ_66M          ( ICG_PLL_FBDIV_1 )
#define RCC_PLLN_DIV_FREQ_65M          ( ICG_PLL_FBDIV_0 )
#define RCC_PLLN_DIV_FREQ_64M          ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_62M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_60M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_58M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_56M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_54M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_52M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_50M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_49M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_48M          ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_47M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_46M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_45M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_44M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_43M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_42M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_41M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_40M          ( ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_39M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_38M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_37M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_36M          ( ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_35M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_34M          ( ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_33M          ( ICG_PLL_FBDIV_1 )
#define RCC_PLLN_DIV_FREQ_32M          ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_31M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_30M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_29M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_28M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_27M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_26M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_25M          ( ICG_PLL_FBDIV_0 | ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_24M          ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_23M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_22M          ( ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_21M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_20M          ( ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_19M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_18M          ( ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_17M          ( ICG_PLL_FBDIV_2 )
#define RCC_PLLN_DIV_FREQ_16M          ( ICG_PLL_FBDIV_5 )
#define RCC_PLLN_DIV_FREQ_15M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_3 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_14M          ( ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_4 )
#define RCC_PLLN_DIV_FREQ_13M          ( ICG_PLL_FBDIV_1 | ICG_PLL_FBDIV_2 | ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_12M          ( ICG_PLL_FBDIV_3 )
#define RCC_PLLN_DIV_FREQ_11M          ( ICG_PLL_FBDIV_1 )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */

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
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */
/**
  * @}
  */

/** @defgroup RCC_PLLM_Clock_Divider PLLM Pre-divider
  * @{
  */
#if defined(XT32H0xxAMPW) 
#define RCC_PLLM_DIV2                  (ICG_PLL_PREDIV_3)                                                              /*!< PLLM division factor = 2  */
#define RCC_PLLM_DIV4                  (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2)                                           /*!< PLLM division factor = 4  */
#define RCC_PLLM_DIV8                  (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                        /*!< PLLM division factor = 8  */
#define RCC_PLLM_DIV12                 (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_0)                        /*!< PLLM division factor = 12 */
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define RCC_PLLM_DIV1                  (0)                                                                             /*!< PLLM division factor = 1  */
#define RCC_PLLM_DIV2                  (ICG_PLL_PREDIV_1)                                                              /*!< PLLM division factor = 2  */
#define RCC_PLLM_DIV3                  (ICG_PLL_PREDIV_0)                                                              /*!< PLLM division factor = 3  */
#define RCC_PLLM_DIV4                  (ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                                           /*!< PLLM division factor = 4  */
#define RCC_PLLM_DIV6                  (ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)                                           /*!< PLLM division factor = 6  */
#define RCC_PLLM_DIV8                  (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1)                        /*!< PLLM division factor = 9  */
#define RCC_PLLM_DIV12                 (ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)                        /*!< PLLM division factor = 12 */
#define RCC_PLLM_DIV24                 (ICG_PLL_PREDIV_3 | ICG_PLL_PREDIV_2 | ICG_PLL_PREDIV_1 | ICG_PLL_PREDIV_0)     /*!< PLLM division factor = 24 */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */

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
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */

/**
  * @}
  */

/** @defgroup RCC_PLLR_Clock_Divider PLLR Post-Divider
  * @{
  */
#if defined(XT32H0xxAMPW)
#define RCC_PLLR_DIV4                  (ICG_PLL_POSTDIV_1)                                                             /*!< PLLR division factor = 4  */
#define RCC_PLLR_DIV6                  (ICG_PLL_POSTDIV_0)                                                             /*!< PLLR division factor = 6  */
#define RCC_PLLR_DIV8                  (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                                         /*!< PLLR division factor = 8  */
#define RCC_PLLR_DIV12                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1)                                         /*!< PLLR division factor = 12 */
#define RCC_PLLR_DIV16                 (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3)                     /*!< PLLR division factor = 16 */
#define RCC_PLLR_DIV24                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                     /*!< PLLR division factor = 24 */
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define RCC_PLLR_DIV4                  (0)                                                                             /*!< PLLR division factor = 4  */
#define RCC_PLLR_DIV6                  (ICG_PLL_POSTDIV_0)                                                             /*!< PLLR division factor = 6  */
#define RCC_PLLR_DIV8                  (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                                         /*!< PLLR division factor = 8  */
#define RCC_PLLR_DIV12                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1)                                         /*!< PLLR division factor = 12 */
#define RCC_PLLR_DIV16                 (ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3)                     /*!< PLLR division factor = 16 */
#define RCC_PLLR_DIV24                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2)                     /*!< PLLR division factor = 24 */
#define RCC_PLLR_DIV48                 (ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3) /*!< PLLR division factor = 48 */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */

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
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */

/**
  * @}
  */

/** @defgroup RCC_PLLR_Clock_Divider_Alias PLLR Post Divider Alias
  * @{
  */
#if defined(XT32H0xxAMPW)	
#define RCC_PLLR_DIV_FREQ_98M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_96M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_94M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_92M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_90M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_88M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_86M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_84M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_82M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_80M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_78M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_76M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_74M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_72M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_70M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_68M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_66M          ( ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_64M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_62M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_60M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_58M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_56M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_54M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_52M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_50M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_49M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_48M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_47M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_46M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_45M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_44M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_43M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_42M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_41M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_40M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_39M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_38M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_37M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_36M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_35M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_34M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_33M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_32M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_31M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_30M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_29M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_28M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_27M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_26M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_25M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_24M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_23M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_22M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_21M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_20M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_19M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_18M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_17M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_16M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_15M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_14M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_13M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_12M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define RCC_PLLR_DIV_FREQ_99M          ( 0 )
#define RCC_PLLR_DIV_FREQ_98M          ( 0 )
#define RCC_PLLR_DIV_FREQ_97M          ( 0 )
#define RCC_PLLR_DIV_FREQ_96M          ( 0 )
#define RCC_PLLR_DIV_FREQ_95M          ( 0 )
#define RCC_PLLR_DIV_FREQ_94M          ( 0 )
#define RCC_PLLR_DIV_FREQ_93M          ( 0 )
#define RCC_PLLR_DIV_FREQ_92M          ( 0 )
#define RCC_PLLR_DIV_FREQ_91M          ( 0 )
#define RCC_PLLR_DIV_FREQ_90M          ( 0 )
#define RCC_PLLR_DIV_FREQ_89M          ( 0 )
#define RCC_PLLR_DIV_FREQ_88M          ( 0 )
#define RCC_PLLR_DIV_FREQ_87M          ( 0 )
#define RCC_PLLR_DIV_FREQ_86M          ( 0 )
#define RCC_PLLR_DIV_FREQ_85M          ( 0 )
#define RCC_PLLR_DIV_FREQ_84M          ( 0 )
#define RCC_PLLR_DIV_FREQ_83M          ( 0 )
#define RCC_PLLR_DIV_FREQ_82M          ( 0 )
#define RCC_PLLR_DIV_FREQ_81M          ( 0 )
#define RCC_PLLR_DIV_FREQ_80M          ( 0 )
#define RCC_PLLR_DIV_FREQ_79M          ( 0 )
#define RCC_PLLR_DIV_FREQ_78M          ( 0 )
#define RCC_PLLR_DIV_FREQ_77M          ( 0 )
#define RCC_PLLR_DIV_FREQ_76M          ( 0 )
#define RCC_PLLR_DIV_FREQ_75M          ( 0 )
#define RCC_PLLR_DIV_FREQ_74M          ( 0 )
#define RCC_PLLR_DIV_FREQ_73M          ( 0 )
#define RCC_PLLR_DIV_FREQ_72M          ( 0 )
#define RCC_PLLR_DIV_FREQ_71M          ( 0 )
#define RCC_PLLR_DIV_FREQ_70M          ( 0 )
#define RCC_PLLR_DIV_FREQ_69M          ( 0 )
#define RCC_PLLR_DIV_FREQ_68M          ( 0 )
#define RCC_PLLR_DIV_FREQ_67M          ( 0 )
#define RCC_PLLR_DIV_FREQ_66M          ( 0 )
#define RCC_PLLR_DIV_FREQ_65M          ( 0 )
#define RCC_PLLR_DIV_FREQ_64M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_62M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_60M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_58M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_56M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_54M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_52M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_50M          ( ICG_PLL_POSTDIV_0 )
#define RCC_PLLR_DIV_FREQ_49M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_48M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_47M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_46M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_45M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_44M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_43M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_42M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_41M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_40M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_39M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_38M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_37M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_36M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_35M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_34M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_33M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_32M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_31M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_30M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_29M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_28M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_27M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_26M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_25M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 )
#define RCC_PLLR_DIV_FREQ_24M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_23M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_22M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_21M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_20M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_19M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_18M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_17M          ( ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 | ICG_PLL_POSTDIV_3 )
#define RCC_PLLR_DIV_FREQ_16M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_15M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_14M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_13M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_12M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#define RCC_PLLR_DIV_FREQ_11M          ( ICG_PLL_POSTDIV_0 | ICG_PLL_POSTDIV_1 | ICG_PLL_POSTDIV_2 )
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source RCC System Clock Source
  * @{
  */

#define RCC_SYSCLKSOURCE_HSI           (0x00000000U)                                   /*!< HSI selected as system clock */
#define RCC_SYSCLKSOURCE_HSE           (ICG_CLK_CTL_HCLKSRC_0)                         /*!< HSE selected as system clock */
#define RCC_SYSCLKSOURCE_PLL           (ICG_CLK_CTL_HCLKSRC_1)                         /*!< PLL selected as system clock */
#define RCC_SYSCLKSOURCE_LS            (ICG_CLK_CTL_HCLKSRC_0| ICG_CLK_CTL_HCLKSRC_1)  /*!< LS clock selected as system clock */

#define IS_RCC_SYSCLK_SOURCE(SOURCE) (((SOURCE) == RCC_SYSCLKSOURCE_HSI) || \
                                      ((SOURCE) == RCC_SYSCLKSOURCE_HSE) || \
                                      ((SOURCE) == RCC_SYSCLKSOURCE_PLL) || \
                                      ((SOURCE) == RCC_SYSCLKSOURCE_LS))
/**
  * @}
  */

/** @defgroup RCC_AHB_Clock_Source RCC AHB Clock Source
  * @{
  */

#define RCC_HCLKSOURCE_HSI             (0x00000000U)                                   /*!< HSI selected as HCLK clock */
#define RCC_HCLKSOURCE_HSE             (ICG_CLK_CTL_HCLKSRC_0)                         /*!< HSE selected as HCLK clock */
#define RCC_HCLKSOURCE_PLL             (ICG_CLK_CTL_HCLKSRC_1)                         /*!< PLL selected as HCLK clock */
#define RCC_HCLKSOURCE_LS              (ICG_CLK_CTL_HCLKSRC_0| ICG_CLK_CTL_HCLKSRC_1)  /*!< LS selected as HCLK clock */
#define IS_RCC_HCLK_SOURCE(HCLK) (((HCLK) == RCC_HCLKSOURCE_HSI) || \
                                  ((HCLK) == RCC_HCLKSOURCE_HSE) || \
                                  ((HCLK) == RCC_HCLKSOURCE_PLL) || \
                                  ((HCLK) == RCC_HCLKSOURCE_LS))
/**
  * @}
  */ 

/** @defgroup RCC_APB_Clock_Source RCC APB Clock Source
  * @{
  */

#define RCC_PCLKSOURCE_HSI             (0x00000000U)                                   /*!< HSI selected as PCLK clock */     
#define RCC_PCLKSOURCE_HSE             (ICG_CLK_CTL_HCLKSRC_0)                         /*!< HSE selected as PCLK clock */     
#define RCC_PCLKSOURCE_PLL             (ICG_CLK_CTL_HCLKSRC_1)                         /*!< PLL selected as PCLK clock */     
#define RCC_PCLKSOURCE_LS              (ICG_CLK_CTL_HCLKSRC_0| ICG_CLK_CTL_HCLKSRC_1)  /*!< LS selected as PCLK clock */     
#define IS_RCC_PCLK_SOURCE(PCLK) (((PCLK) == RCC_PCLKSOURCE_HSI) || \
                                  ((PCLK) == RCC_PCLKSOURCE_HSE) || \
                                  ((PCLK) == RCC_PCLKSOURCE_PLL) || \
                                  ((PCLK) == RCC_PCLKSOURCE_LS))
/**
  * @}
  */
  
/** @defgroup RCC_ADC_Clock_Source RCC ADC Clock Source
  * @{
  */
#define RCC_ADCCLKSOURCE_PCLK          (0x00000000U)                           /*!< PCLK selected as ADC clock */
#define RCC_ADCCLKSOURCE_HCLK          (ICG_CLK_CTL_ADCSRC_0)                  /*!< HCLK selected as ADC clock */
#define RCC_ADCCLKSOURCE_PLL           (ICG_CLK_CTL_ADCSRC_1)                  /*!< PLL selected as ADC clock */

#define IS_RCC_ADCCLK(ADCCLK) (((ADCCLK) == RCC_ADCCLKSOURCE_PCLK) || ((ADCCLK) == RCC_ADCCLKSOURCE_HCLK) || \
                               ((ADCCLK) == RCC_ADCCLKSOURCE_PLL))
/**
  * @}
  */

/** @defgroup RCC_TIMAG_Clock_Source RCC Adv. Timer & Gen. Timer Clock Source
  * @{
  */
#define RCC_TIMAGCLKSOURCE_PCLK        (0x00000000U)                           /*!< PCLK selected as Advance Timer and Genernal Timer clock */
#define RCC_TIMAGCLKSOURCE_HCLK        (ICG_CLK_CTL_TMRAGSRC_0)                  /*!< HCLK selected as Advance Timer and Genernal Timer clock */
#define RCC_TIMAGCLKSOURCE_PLL         (ICG_CLK_CTL_TMRAGSRC_1)                  /*!< PLL selected as Advance Timer and Genernal Timer clock */

#define IS_RCC_TIMAGCLK(CLK) (((CLK) == RCC_TIMAGCLKSOURCE_PCLK) || ((CLK) == RCC_TIMAGCLKSOURCE_HCLK) || \
                              ((CLK) == RCC_TIMAGCLKSOURCE_PLL))
/**
  * @}
  */

/** @defgroup RCC_GPIO_Clock_Source RCC GPIO Debounce Clock Source
  * @{
  */
#define RCC_GPIOCLKSOURCE_HSI          (0x00000000U)                           /*!< HSI selected as GPIO debounce clock */
#define RCC_GPIOCLKSOURCE_HSE          (ICG_CLK_CTL_GPIOSRC_0)                 /*!< HSE selected as GPIO debounce clock */
#define RCC_GPIOCLKSOURCE_PLL          (ICG_CLK_CTL_GPIOSRC_1)                 /*!< PLL selected as GPIO debounce clock */

#define IS_RCC_GPIOCLK(CLK)  (((CLK) == RCC_GPIOCLKSOURCE_HSI) || ((CLK) == RCC_GPIOCLKSOURCE_HSE) || \
                              ((CLK) == RCC_GPIOCLKSOURCE_PLL))
/**
  * @}
  */

/** @defgroup RCC_TIMER_Clock_Source RCC TIMER Clock Source
  * @{
  */
#define RCC_TIMB2CLKSOURCE_HSI         (0x00000000U)                           /*!< HSI selected as Basic Timer 2x clock */
#define RCC_TIMB2CLKSOURCE_HSE         (ICG_CLK_CTL_TMRB2SRC_0)                /*!< HSE selected as Basic Timer 2x clock */
#define RCC_TIMB2CLKSOURCE_PLL         (ICG_CLK_CTL_TMRB2SRC_1)                /*!< PLL selected as Basic Timer 2x clock */

#define IS_RCC_TIMB2CLK(CLK)  (((CLK) == RCC_TIMB2CLKSOURCE_HSI) || ((CLK) == RCC_TIMB2CLKSOURCE_HSE) || \
                               ((CLK) == RCC_TIMB2CLKSOURCE_PLL))
/**
  * @}
  */

/** @defgroup RCC_I2C_Clock_Source RCC I2C Clock Source
  * @{
  */
#define RCC_I2CCLKSOURCE_HSI           (0x00000000U)                           /*!< HSI selected as I2C 1 clock */
#define RCC_I2CCLKSOURCE_HSE           (ICG_CLK_CTL_I2CSRC_0)                  /*!< HSE selected as I2C 1 clock */
#define RCC_I2CCLKSOURCE_PLL           (ICG_CLK_CTL_I2CSRC_1)                  /*!< PLL selected as I2C 1 clock */

#define IS_RCC_I2CCLK(CLK) (((CLK) == RCC_I2CCLKSOURCE_HSI) || ((CLK) == RCC_I2CCLKSOURCE_HSE) || \
                            ((CLK) == RCC_I2CCLKSOURCE_PLL))

/**
  * @}
  */

/** @defgroup RCC_TIMER_B_Clock_Source RCC Basic TIMER 1 Clock Source
  * @{
  */
#define RCC_TIMB1CLKSOURCE_HSI         (0x00000000U)                           /*!< HSI selected as Basic Timer 1x clock */
#define RCC_TIMB1CLKSOURCE_HSE         (ICG_CLK_CTL_TMRB1SRC_0)                /*!< HSE selected as Basic Timer 1x clock */
#define RCC_TIMB1CLKSOURCE_PLL         (ICG_CLK_CTL_TMRB1SRC_1)                /*!< PLL selected as Basic Timer 1x clock */

#define IS_RCC_TIMB1CLK(CLK)  (((CLK) == RCC_TIMB1CLKSOURCE_HSI) || ((CLK) == RCC_TIMB1CLKSOURCE_HSE) || \
                               ((CLK) == RCC_TIMB1CLKSOURCE_PLL))
/**
  * @}
  */

/** @defgroup RCC_BR_Clock_Source RCC baud rate (UART & SPI) Clock Source
  * @{
  */
#define RCC_BRCLKSOURCE_HSI            (0x00000000U)                           /*!< HSI selected as Baudrate clock */
#define RCC_BRCLKSOURCE_HSE            (ICG_CLK_CTL_BRSRC_0)                   /*!< HSE selected as Baudrate clock */
#define RCC_BRCLKSOURCE_PLL            (ICG_CLK_CTL_BRSRC_1)                   /*!< PLL selected as Baudrate clock */

#define IS_RCC_BRCLK(CLK)     (((CLK) == RCC_BRCLKSOURCE_HSI) || ((CLK) == RCC_BRCLKSOURCE_HSE) || \
                               ((CLK) == RCC_BRCLKSOURCE_PLL))
/**
  * @}
  */

/** @defgroup RCC_WDTW_Clock_Source RCC Windows Clock Source Clock Source
  * @{
  */
#define RCC_WDTWCLKSOURCE_HSI          (0x00000000U)                           /*!< HSI selected as Window WDT clock */
#define RCC_WDTWCLKSOURCE_HSE          (ICG_CLK_CTL_WDTWSRC_0)                 /*!< HSE selected as Window WDT clock */
#define RCC_WDTWCLKSOURCE_PLL          (ICG_CLK_CTL_WDTWSRC_1)                 /*!< PLL selected as Window WDT clock */

#define IS_RCC_WDTWCLK(CLK)     (((CLK) == RCC_WDTWCLKSOURCE_HSI) || ((CLK) == RCC_WDTWCLKSOURCE_HSE) || \
                                 ((CLK) == RCC_WDTWCLKSOURCE_PLL))
/**
  * @}
  */

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
/** @addtogroup RCC_HSI_Mode
  * @{
  */
#define RCC_HSI_NORMAL                 (0x00000000U)  
#define RCC_HSI_CALIB                  (ICG_RC16M_CTRL_CALI)
#define IS_RCC_HSI_MODE(MODE) (((MODE) == RCC_HSI_NORMAL) || ((LSI) == RCC_HSI_CALIB))
/**
  * @}
  */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */

/** @addtogroup RCC_LSI_Enable
  * @{
  */
#define RCC_LSI_OFF                    (AON_CLKCTRL_32KRC_PD)  
#define RCC_LSI_ON                     (0x00000000U)
#define IS_RCC_LSI(LSI) (((LSI) == RCC_LSI_OFF) || ((LSI) == RCC_LSI_ON))
/**
  * @}
  */

/** @defgroup RCC_LSE_Configuration RCC LSE Configuration
  * @{
  */

#define RCC_LSE_OFF                    (AON_CLKCTRL_32KXTAL_PD)  
#define RCC_LSE_ON                     (0x00000000U)
#define IS_RCC_LSE(LSE) (((LSE) == RCC_LSE_OFF) || ((LSE) == RCC_LSE_ON))
/**
  * @}
  */

/** @addtogroup RCC_LS_Source RCC LS Source
  * @{
  */
#define RCC_LSSRC_LSI                  (0x0UL)
#define RCC_LSSRC_LSE                  (AON_CFG_32KCLKSRC_0)
#define IS_RCC_LSCLK(CLK) (((CLK) == RCC_LSSRC_LSI) || ((CLK) == RCC_LSSRC_LSE))
/**
  * @}
  */

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
/** @addtogroup RCC_LSI_Mode RCC LSI Mode
  * @{
  */
#define RCC_LSI_NORMAL                 (0x00000000U)  
#define RCC_LSI_CALIB                  (AON_CLKCTRL_32K_CAL)
#define IS_RCC_LSI_MODE(MODE) (((MODE) == RCC_LSI_NORMAL) || ((MODE) == RCC_LSI_CALIB))
/**
  * @}
  */
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */ 

#if defined(XT32H0xxB)
/** @addtogroup RCC_DeepSleep_External_Wakeup RCC DeepSleep External Wakeup
  * @{
  */
#define RCC_DEEPSLEEP_EXTWAKRUP_DISABLE    (0x00000000U)  
#define RCC_DEEPSLEEP_EXTWAKRUP_ENABLE     (AON_DEEPSLEEP_CTRL_EXT_WAKEUP)
#define IS_RCC_DEEPSLEEP_EXTWAKEUP(MODE) (((MODE) == RCC_DEEPSLEEP_EXTWAKRUP_DISABLE) || ((MODE) == RCC_DEEPSLEEP_EXTWAKRUP_ENABLE))
/**
  * @}
  */
#endif /* XT32H0xxB */

/** @defgroup RCC_Timer_External_Clock_Source RCC Timer External Clock Source
  * @{
  */
#define RCC_TIMERS_INTERNAL_CLOCK      (0)

#define RCC_TIMB11_EXTERNAL_CLOCK      (ICG_TMXC_BTMSRC_0)
#define RCC_TIMB12_EXTERNAL_CLOCK      (ICG_TMXC_BTMSRC_1)
#define RCC_TIMB13_EXTERNAL_CLOCK      (ICG_TMXC_BTMSRC_2)
#define RCC_TIMB14_EXTERNAL_CLOCK      (ICG_TMXC_BTMSRC_3)
#define RCC_TIMB21_EXTERNAL_CLOCK      (ICG_TMXC_BTMSRC_4)
#define RCC_TIMB22_EXTERNAL_CLOCK      (ICG_TMXC_BTMSRC_5)
#define RCC_TIMB23_EXTERNAL_CLOCK      (ICG_TMXC_BTMSRC_6)
#define RCC_TIMB24_EXTERNAL_CLOCK      (ICG_TMXC_BTMSRC_7)

#define RCC_TIMG_CH1IN                 (ICG_TMXC_GTMSRC_0)
#define RCC_TIMG_CH2IN                 (ICG_TMXC_GTMSRC_1)
#define RCC_TIMG_CH3IN                 (ICG_TMXC_GTMSRC_2)
#define RCC_TIMG_CH4IN                 (ICG_TMXC_GTMSRC_3)
#define RCC_TIMG_ETR                   (ICG_TMXC_GTMSRC_4)

#define RCC_TIMA_CH1IN                 (ICG_TMXC_ATMSRC_0)
#define RCC_TIMA_CH2IN                 (ICG_TMXC_ATMSRC_1)
#define RCC_TIMA_CH3IN                 (ICG_TMXC_ATMSRC_2)
#define RCC_TIMA_CH4IN                 (ICG_TMXC_ATMSRC_3)
#define RCC_TIMA_ETR                   (ICG_TMXC_ATMSRC_4)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup RCC_Exported_Functions
  * @{
  */

/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */
/* Function used to set the RCC clock configuration to the default reset state */
void RCC_DeInit(void);

/* Internal/external clocks, PLL, CSS and MCO configuration functions *********/
void RCC_HSIConfig(uint32_t RCC_HSI);
void RCC_HSEConfig(uint32_t RCC_HSE);
void RCC_PLLConfig(uint32_t RCC_PLL,
                   uint32_t RCC_PLLSource,
                   uint32_t RCC_PLLM, uint32_t RCC_PLLN, uint32_t RCC_PLLR);
uint32_t RCC_GetPLLClock(void);

void RCC_LSIConfig(uint32_t RCC_LSI);
void RCC_LSEConfig(uint32_t RCC_LSE);

void RCC_SetSYSCLKSource(uint32_t Source);
void RCC_SetHCLKSource(uint32_t Source);
void RCC_SetPCLKSource(uint32_t Source);
void RCC_SetSYSCLKDivider(uint32_t Divider);
void RCC_SetHCLKDivider(uint32_t Divider);
void RCC_SetPCLKDivider(uint32_t Divider);
uint32_t RCC_GetSYSCLKClock(void);
uint32_t RCC_GetHCLKClock(void);
uint32_t RCC_GetPCLKClock(void);

void RCC_SetADCCLKSource(uint32_t Source);
void RCC_SetADCCLKDivider(uint32_t Divider);
uint32_t RCC_GetADCCLKClock(void);

void RCC_SetTIMAGCLKSource(uint32_t Source);
void RCC_SetTIMAGCLKDivider(uint32_t Divider);
uint32_t RCC_GetTIMAGCLKClock(void);

void RCC_SetGPIOCLKSource(uint32_t Source);
void RCC_SetGPIOCLKDivider(uint32_t Divider);
uint32_t RCC_GetGPIOCLKClock(void);

void RCC_SetTIMB2CLKSource(uint32_t Source);
void RCC_SetTIMB2CLKDivider(uint32_t Divider);
uint32_t RCC_GetTIMB2CLKClock(void);

void RCC_SetI2CCLKSource(uint32_t Source);
void RCC_SetI2C1CLKDivider(uint32_t Divider);
void RCC_SetI2C2CLKDivider(uint32_t Divider);
uint32_t RCC_GetI2C1CLKClock(void);
uint32_t RCC_GetI2C2CLKClock(void);

void RCC_SetTIMB1CLKSource(uint32_t Source);
void RCC_SetTIMB1CLKDivider(uint32_t Divider);
uint32_t RCC_GetTIMB1CLKClock(void);

void RCC_SetBRCLKSource(uint32_t Source);
void RCC_SetBRCLKDivider(uint32_t Divider);
uint32_t RCC_GetBRCLKClock(void);

void RCC_SetWDTWCLKSource(uint32_t Source);
void RCC_SetWDTWCLKDivider(uint32_t Divider);
uint32_t RCC_GetWDTWCLKClock(void);

void RCC_SetDMACLKDivider(uint32_t Divider);
uint32_t RCC_GetDMACLKClock(void);

void RCC_SetTIMAExternalClock(uint32_t ClkSrc);
void RCC_SetTIMGExternalClock(uint32_t ClkSrc);
void RCC_SetTIMBExternalClock(uint32_t ClkSrc);

void RCC_SetRTCCLKSource(uint32_t Source);
void RCC_SetRTCCLKDivider(uint32_t Divider);
uint32_t RCC_GetRTCCLKClock(void);

void RCC_SetDeepSleepTime(uint32_t Clk);
#if defined(XT32H0xxB)
void RCC_DeepSleep(uint32_t ExtWakeup);
#else
void RCC_DeepSleep(void);
#endif /* XT32H0xxB */

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
void RCC_SetHSIMode(uint32_t Mode);
void RCC_SetHSICode(uint32_t Code);
void RCC_SetLSIMode(uint32_t Mode);
void RCC_SetLSICode(uint32_t Code);
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0XXB */

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

#endif /* __XT32H0XX_RCC_H */

