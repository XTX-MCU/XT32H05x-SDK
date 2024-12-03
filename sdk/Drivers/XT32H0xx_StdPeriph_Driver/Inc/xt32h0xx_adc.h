/**
  ******************************************************************************
  * @file    xt32h0xx_adc.h
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file contains all the functions prototypes for the ADC firmware 
  *          library
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_ADC_H
#define __XT32H0XX_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/* Exported types ------------------------------------------------------------*/

#if defined(XT32H0xxB)
#else
/** @defgroup ADC_Exported_Types ADC Exported Types
  * @{
  */
/** 
  * @brief  ADC Init structure definition
  */
  
typedef struct
{
  uint32_t Convert_Mode;                    /*!< convert mode.
                                                 This parameter can be a value of @ref ADC_Convert */

  uint32_t Trigger_Source;                  /*!< Selects the external trigger Source */

  uint32_t Trigger_Mode;                    /*!< Defines the external trigger edge */

  uint32_t Sequence_Direct;                 /*!< Sequence direct */

  uint32_t Sequence_Group;                  /*!< Sequence group */

}ADC_InitTypeDef;
/**
  * @}
  */
#endif /* XT32H0xxB */

/* Exported constants --------------------------------------------------------*/
/** @defgroup ADC_Exported_Contants ADC Exported Constants
  * @{
  */

#if defined(XT32H0xxB)
/** @defgroup ADC_EC_CONTROL_MODE ADC control mode
  * @{
  */
#define ADC_CONTROL_MODE_MANUAL        (0)                                             /*!< ADC manual mode */
#define ADC_CONTROL_MODE_AUTO          (MDU_ADCCFG_ADCC_EN)                            /*!< ADC auto mode */

#define IS_ADC_CONTROL_MODE(MODE) (((MODE) == ADC_CONTROL_MODE_MANUAL)  || \
                                   ((MODE) == ADC_CONTROL_MODE_AUTO))
/** 
  * @}
  */

/** @defgroup ADC_EC_OUTPUT_ALIGNMENT ADC output alignment
  * @{
  */
#define ADC_OUTPUT_AGLIN_LSB         (0)                                              /*!< ADC output alignment LSB */
#define ADC_OUTPUT_AGLIN_MSB         (MDU_ADCCFG_ADCOUTALIGN)                         /*!< ADC output alignment MSB */

#define IS_ADC_DATAALIGN(MODE)    (((MODE) == ADC_OUTPUT_AGLIN_LSB)  || \
                                   ((MODE) == ADC_OUTPUT_AGLIN_MSB))
/** 
  * @}
  */

/** @defgroup ADC_EC_RESOLUTION ADC conversion resolution
  * @{
  */
#define ADC_RESOLUTION_8B              (0)
#define ADC_RESOLUTION_10B             (MDU_ADCCFG_ADCDATAW_0)
#define ADC_RESOLUTION_12B             (MDU_ADCCFG_ADCDATAW_1)

#define IS_ADC_DATARESOLUTION(MODE)    (((MODE) == ADC_RESOLUTION_8B)  || \
                                        ((MODE) == ADC_RESOLUTION_10B)  || \
                                        ((MODE) == ADC_RESOLUTION_12B))
/** 
  * @}
  */

/** @defgroup ADC_EC_Interrupt_Polarity  ADC interrupt polarity
  * @{
  */
#define ADC_INT_POLARITY_HIGH       (0)                                               /*!< ADC interrupt high level */
#define ADC_INT_POLARITY_LOW        (1)                                               /*!< ADC interrupt low level */

#define IS_ADC_INT_POLARITY(POL)    (((POL) == ADC_INT_POLARITY_HIGH)  || \
                                     ((POL) == ADC_INT_POLARITY_LOW))
/**
  * @}
  */

/** @defgroup ADC_EC_Interrupt_Enable  ADC interrupts enable
  * @{
  */
#define ADC_INT_ENABLE_INJGRP_EOC   (MDU_MDUCFG_INJ_EOC_EN)                           /*!< ADC injection group interrupt EOC enable */
#define ADC_INT_ENABLE_INJGRP_EOS   (MDU_MDUCFG_INJ_EOS_EN)                           /*!< ADC injection group interrupt EOS enable */
#define ADC_INT_ENABLE_REGGRP_EOC   (MDU_MDUCFG_REG_EOC_EN)                           /*!< ADC regular group interrupt EOC enable */
#define ADC_INT_ENABLE_REGGRP_EOS   (MDU_MDUCFG_REG_EOS_EN)                           /*!< ADC regular group interrupt EOS enable */

#define IS_ADC_INT_ENABLE(INT)    (((INT) == ADC_INT_ENABLE_INJGRP_EOC)  || \
                                   ((INT) == ADC_INT_ENABLE_INJGRP_EOS)  || \
                                   ((INT) == ADC_INT_ENABLE_REGGRP_EOC)  || \
                                   ((INT) == ADC_INT_ENABLE_REGGRP_EOS))
/**
  * @}
  */

/** @defgroup ADC_EC_Reset_Dalay  ADC reset delay
  * @{
  */
#define IS_ADC_RESET_DELAY(DELAY)    (((DELAY) >= 0)  && ((DELAY) <= 0xF))
/**
  * @}
  */

/** @defgroup ADC_EC_Reset_Pulse  ADC reset pulse width
  * @{
  */
#define IS_ADC_RESET_PULSE(WIDTH)    (((WIDTH) >= 0)  && ((WIDTH) <= 0xF))
/**
  * @}
  */

/** @defgroup ADC_PGA_PRESAMPLING_MODE  ADC PGA pre-dampling Mode
  * @{
  */
#define ADC_PRESAMPLING_MODE_SAME       (0)                                           /*!< use same pre-sample cycle numbers from MDU_CFG */
#define ADC_PRESAMPLING_MODE_DEDICATED  (MDU_MDUCFG_SEL_PGA_CTRL)                     /*!< use dedicated pre-sample cycle numbers in inj_group_define_x */

#define IS_ADC_SAMPLING_MODEE(MODE)    (((MODE) == ADC_PRESAMPLING_MODE_SAME)  || \
                                        ((MODE) == ADC_PRESAMPLING_MODE_DEDICATED))
/**
  * @}
  */

/** @defgroup ADC_EC_PGASAMPLING_CYCLES  ADC PGA sampling cycles
  * @{
  */
#define IS_ADC_SAMPLING_CYCLES(CYCLES)    (((CYCLES) >= 0)  && ((CYCLES) <= 0x3F))
/**
  * @}
  */

/** @defgroup ADC_EC_DISCHARGE_CYCLES  ADC discharge cycles
  * @{
  */
#define IS_ADC_DISCHARGE_CYCLES(CYCLES)    (((CYCLES) >= 0)  && ((CYCLES) <= 0xFF))
/**
  * @}
  */

/** @defgroup ADC_EC_conversion_mode scan mode for regular group 
  * @{
  */
#define ADC_CONVERT_SINGLESCAN          (0)  
#define ADC_CONVERT_CONTINUOUSSCAN      (MDU_REGGRP_TRGCFG_REGGRP_OPMODE_0)  
#define ADC_CONVERT_DISCONTINUOUSSCAN   (MDU_REGGRP_TRGCFG_REGGRP_OPMODE_1)  
/**
  * @}
  */

/** @defgroup ADC_EC_ADC_Trigger Source ADC trigger source
  * @{
  */
#define ADC_TRGSRC_NONE             (0)
#define ADC_TRGSRC_TIMA1_CH4        (1)
#define ADC_TRGSRC_TIMA1_TRGO2      (2)
#define ADC_TRGSRC_TIMA2_CH4        (3)
#define ADC_TRGSRC_TIMA2_TRGO2      (4)
#define ADC_TRGSRC_TIMG1_CH4        (5)
#define ADC_TRGSRC_TIMG1_TRGO2      (6)
#define ADC_TRGSRC_TIMG2_CH4        (7)
#define ADC_TRGSRC_TIMG2_TRGO2      (8)
#define ADC_TRGSRC_TIMG3_CH4        (9)
#define ADC_TRGSRC_TIMG3_TRGO2      (10)
#define ADC_TRGSRC_TIMG4_CH4        (11)
#define ADC_TRGSRC_TIMG4_TRGO2      (12)
#define ADC_TRGSRC_EXTERNAL         (13)
#define ADC_TRGSRC_TIMB11           (14)
#define ADC_TRGSRC_SOFTWARE         (15)

#define IS_ADC_TRGSRC(SOURCE)     (((SOURCE) == ADC_TRGSRC_NONE)         || \
                                   ((SOURCE) == ADC_TRGSRC_TIMA1_CH4)    || \
                                   ((SOURCE) == ADC_TRGSRC_TIMA1_TRGO2)  || \
                                   ((SOURCE) == ADC_TRGSRC_TIMA2_CH4)    || \
                                   ((SOURCE) == ADC_TRGSRC_TIMA2_TRGO2)  || \
                                   ((SOURCE) == ADC_TRGSRC_TIMG1_CH4)    || \
                                   ((SOURCE) == ADC_TRGSRC_TIMG1_TRGO2)  || \
                                   ((SOURCE) == ADC_TRGSRC_TIMG2_CH4)    || \
                                   ((SOURCE) == ADC_TRGSRC_TIMG2_TRGO2)  || \
                                   ((SOURCE) == ADC_TRGSRC_TIMG3_CH4)    || \
                                   ((SOURCE) == ADC_TRGSRC_TIMG3_TRGO2)  || \
                                   ((SOURCE) == ADC_TRGSRC_TIMG4_CH4)    || \
                                   ((SOURCE) == ADC_TRGSRC_TIMG4_TRGO2)  || \
                                   ((SOURCE) == ADC_TRGSRC_EXTERNAL)     || \
                                   ((SOURCE) == ADC_TRGSRC_TIMB11)       || \
                                   ((SOURCE) == ADC_TRGSRC_SOFTWARE))
/**
  * @}
  */

/** @defgroup ADC_EC_TRIGGER_MODE  ADC trigger edge
  * @{
  */
#define ADC_TRIGGEREDGE_NONE        (0)                                               /*!< ADC no trigger */
#define ADC_TRIGGEREDGE_RISING      (1)                                               /*!< ADC trigger edge rising  */
#define ADC_TRIGGEREDGE_FALLING     (2)                                               /*!< ADC trigger edge falling */
#define ADC_TRIGGEREDGE_BOTH        (3)                                               /*!< ADC trigger edge both */

#define IS_ADC_TRIGGER_MODE(MODE)    (((MODE) == ADC_TRIGGEREDGE_NONE)     || \
                                      ((MODE) == ADC_TRIGGEREDGE_RISING)   || \
                                      ((MODE) == ADC_TRIGGEREDGE_FALLING)  || \
                                      ((MODE) == ADC_TRIGGEREDGE_BOTH))
/**
  * @}
  */

/** @defgroup ADC_EC_CORE_CONV_MODE ADC core conversion mode
  * @{
  */
#define ADC_CORE_CONV_MODE_CONTINUOUS  (0)                                             /*!< ADC manual conversion mode - continuous conversion */
#define ADC_CORE_CONV_MODE_SINGLE      (MDU_ADCCFG_MCONVMODE)                          /*!< ADC manual conversion mode - single conversion */
/** 
  * @}
  */

/** @defgroup ADC_EC_ADC_Channel ADC channel
  * @{
  */
#define ADC_CHANNEL_1               (0)                 /* sync sampling channel*/
#define ADC_CHANNEL_2               (1)                 /* sync sampling channel*/
#define ADC_CHANNEL_3               (2)                 /* sync sampling channel*/
#define ADC_CHANNEL_4               (3)                 /* sync sampling channel*/
#define ADC_CHANNEL_5               (4)                 /* single-end channel*/
#define ADC_CHANNEL_6               (5)                 /* single-end channel*/
#define ADC_CHANNEL_7               (6)                 /* single-end channel*/
#define ADC_CHANNEL_8               (7)                 /* single-end channel*/
#define ADC_CHANNEL_9               (8)                 /* single-end channel*/
#define ADC_CHANNEL_10              (9)                 /* single-end channel*/
#define ADC_CHANNEL_11              (10)                /* single-end channel*/
#define ADC_CHANNEL_12              (11)                /* single-end channel*/
#define ADC_CHANNEL_13              (12)                /* single-end channel*/
#define ADC_CHANNEL_14              (13)                /* single-end channel*/
#define ADC_CHANNEL_15              (14)                /* single-end channel*/
#define ADC_CHANNEL_16              (15)                /* single-end channel*/
#define ADC_CHANNEL_17              (16)                /* single-end channel*/
#define ADC_CHANNEL_18              (17)                /* single-end channel*/
#define ADC_CHANNEL_19              (18)                /* single-end channel*/
#define ADC_CHANNEL_20              (19)                /* single-end channel*/
#define ADC_CHANNEL_21              (20)                /* single-end channel*/
#define ADC_CHANNEL_22              (21)                /* single-end channel*/
#define ADC_CHANNEL_23              (22)                /* single-end channel*/
#define ADC_CHANNEL_24              (23)                /* single-end channel*/
#define ADC_CHANNEL_25              (24)                /* single-end channel*/
#define ADC_CHANNEL_26              (25)                /* single-end channel*/
#define ADC_CHANNEL_27              (26)                /* single-end channel*/
#define ADC_CHANNEL_28              (27)                /* single-end channel*/
#define ADC_CHANNEL_29              (28)                /* single-end channel*/
#define ADC_CHANNEL_30              (29)                /* single-end channel*/
#define ADC_CHANNEL_31              (30)                /* single-end channel*/
#define ADC_CHANNEL_32              (31)                /* single-end channel*/
#define ADC_CHANNEL_33              (32)                /* single-end channel*/
#define ADC_CHANNEL_34              (33)                /* single-end channel*/
#define ADC_CHANNEL_35              (34)                /* single-end channel*/
#define ADC_CHANNEL_36              (35)                /* single-end channel*/
#define ADC_CHANNEL_37              (36)                /* single-end channel*/
#define ADC_CHANNEL_38              (37)                /* single-end channel*/
#define ADC_CHANNEL_39              (38)                /* single-end channel*/
#define ADC_CHANNEL_40              (39)                /* single-end channel*/
#define ADC_CHANNEL_41              (40)                /* single-end channel*/
#define ADC_CHANNEL_42              (41)                /* single-end channel*/
#define ADC_CHANNEL_43              (42)                /* single-end channel*/
#define ADC_CHANNEL_44              (43)                /* single-end channel*/
#define ADC_CHANNEL_45              (44)                /* single-end channel*/
#define ADC_CHANNEL_46              (45)                /* single-end channel*/
#define ADC_CHANNEL_47              (46)                /* single-end channel*/
#define ADC_CHANNEL_48              (47)                /* single-end channel*/
#define ADC_CHANNEL_49              (48)                /* single-end channel*/
#define ADC_CHANNEL_50              (49)                /* single-end channel*/
#define ADC_CHANNEL_51              (50)                /* single-end channel*/
#define ADC_CHANNEL_52              (51)                /* single-end channel*/
#define ADC_CHANNEL_53              (52)                /* single-end channel*/
#define ADC_CHANNEL_VBG             (53)                /* single-end channel*/
#define ADC_CHANNEL_VTS             (54)                /* single-end channel*/
#define ADC_CHANNEL_VBS             (55)                /* single-end channel*/
#define ADC_CHANNEL_P2AVDD          (56)                /* single-end channel*/
#define ADC_CHANNEL_P3AVDD          (57)                /* single-end channel*/
#define ADC_CHANNEL_P4AVDD          (58)                /* single-end channel*/
#define ADC_CHANNEL_P5AVDD          (59)                /* single-end channel*/
#define ADC_CHANNEL_P6AVDD          (60)                /* single-end channel*/
#define ADC_CHANNEL_P7AVDD          (61)                /* single-end channel*/
#define ADC_CHANNEL_P8AVDD          (62)                /* single-end channel*/
#define ADC_CHANNEL_64              (63)                /* reserved */

#define IS_ADC_ADC_CHANNEL(CHANNEL)    (((CHANNEL) >= ADC_CHANNEL_1)  && ((CHANNEL) <= ADC_CHANNEL_64))
/**
  * @}
  */

/** @defgroup ADC_EC_INJGRP_NUMBER  ADC injection group number
  * @{
  */
#define IS_ADC_INJGRP_NUMBER(NUMBER)    (((NUMBER) >= 0)  && ((NUMBER) <= 4))
/**
  * @}
  */

/** @defgroup ADC_EC_INJGRP_ID  ADC injection group identification
  * @{
  */
#define ADC_INJGRP_ID_NONE          (0)                                               /*!< ADC injection group ID none */
#define ADC_INJGRP_ID_1             (1)                      /*!< ADC injection group ID 1 */
#define ADC_INJGRP_ID_2             (2)                      /*!< ADC injection group ID 2 */
#define ADC_INJGRP_ID_3             (3)                      /*!< ADC injection group ID 3 */
#define ADC_INJGRP_ID_4             (4)                      /*!< ADC injection group ID 4 */

#define IS_ADC_INJGRP_ID(ID)         (((ID) == ADC_INJGRP_ID_NONE)  || \
                                      ((ID) == ADC_INJGRP_ID_1)     || \
                                      ((ID) == ADC_INJGRP_ID_2)     || \
                                      ((ID) == ADC_INJGRP_ID_3)     || \
                                      ((ID) == ADC_INJGRP_ID_4))
/**
  * @}
  */

/** @defgroup ADC_EC_INJGRP_CHANNEL  ADC injection group channel
  * @{
  */
#define IS_ADC_INJGRP_CHANNEL(CHANNEL)    (((CHANNEL) >= 0)  && ((CHANNEL) <= 3))
/**
  * @}
  */

/** @defgroup ADC_EC_REGGRP_NUMBER  ADC regular group number
  * @{
  */
#define IS_ADC_REGGRP_NUMBER(NUMBER)    (((NUMBER) >= 0)  && ((NUMBER) <= 8))
/**
  * @}
  */

/** @defgroup ADC_EC_REGGRP_ID  ADC regular group identification
  * @{
  */
#define ADC_REGGRP_ID_NONE          (0)                                               /*!< ADC injection group ID none */
#define ADC_REGGRP_ID_1             (1)                      /*!< ADC regular group ID 1 */
#define ADC_REGGRP_ID_2             (2)                      /*!< ADC regular group ID 2 */
#define ADC_REGGRP_ID_3             (3)                      /*!< ADC regular group ID 3 */
#define ADC_REGGRP_ID_4             (4)                      /*!< ADC regular group ID 4 */
#define ADC_REGGRP_ID_5             (5)                      /*!< ADC regular group ID 5 */
#define ADC_REGGRP_ID_6             (6)                      /*!< ADC regular group ID 6 */
#define ADC_REGGRP_ID_7             (7)                      /*!< ADC regular group ID 7 */
#define ADC_REGGRP_ID_8             (8)                      /*!< ADC regular group ID 8 */

#define IS_ADC_REGGRP_ID(ID)         (((ID) == ADC_REGGRP_ID_NONE)  || \
                                      ((ID) == ADC_REGGRP_ID_1)     || \
                                      ((ID) == ADC_REGGRP_ID_2)     || \
                                      ((ID) == ADC_REGGRP_ID_3)     || \
                                      ((ID) == ADC_REGGRP_ID_4)     || \
                                      ((ID) == ADC_REGGRP_ID_5)     || \
                                      ((ID) == ADC_REGGRP_ID_6)     || \
                                      ((ID) == ADC_REGGRP_ID_7)     || \
                                      ((ID) == ADC_REGGRP_ID_8))
/**
  * @}
  */

/** @defgroup ADC_EC_REGGRP_CHANNEL  ADC regular group channel
  * @{
  */
#define IS_ADC_REGGRP_CHANNEL(CHANNEL)    (((CHANNEL) >= 0)  && ((CHANNEL) <= 31))
/**
  * @}
  */

/** @defgroup ADC_EC_AWD_ID  ADC  channel analog watch dog identification
  * @{
  */
#define ADC_AWD_ID_NONE             (0)                                               /*!< ADC injection channel AWD none */
#define ADC_AWD_ID_1                (1)                                               /*!< ADC injection channel AWD id 1 */
#define ADC_AWD_ID_2                (2)                                               /*!< ADC injection channel AWD id 2 */
#define ADC_AWD_ID_3                (3)                                               /*!< ADC injection channel AWD id 3 */

#define IS_ADC_AWD_ID(ID)         (((ID) == ADC_AWD_ID_NONE)  || \
                                   ((ID) == ADC_AWD_ID_1)     || \
                                   ((ID) == ADC_AWD_ID_2)     || \
                                   ((ID) == ADC_AWD_ID_3))
/**
  * @}
  */

/** @defgroup ADC_EC_AWD_Mode  ADC channel analog watch dog monitor mode
  * @{
  */
#define ADC_AWD_MODE_NONE           (0)                                               /*!< ADC AWD none */
#define ADC_AWD_MODE_LOW            (MDU_AWD_CR_CFG_1_0)                              /*!< ADC AWD output when the vaule is less than low threshold */
#define ADC_AWD_MODE_HIGH           (MDU_AWD_CR_CFG_1_1)                              /*!< ADC AWD output when the vaule is in [low threshold, high threshold] */
#define ADC_AWD_MODE_MID            (MDU_AWD_CR_CFG_1_1|MDU_AWD_CR_CFG_1_0)           /*!< ADC AWD output when the vaule is greater than high threshold */

#define IS_ADC_AWD_MODE(MODE)         (((MODE) == ADC_AWD_MODE_NONE)  || \
                                       ((MODE) == ADC_AWD_MODE_LOW)   || \
                                       ((MODE) == ADC_AWD_MODE_MID)   || \
                                       ((MODE) == ADC_AWD_MODE_HIGH))
/**
  * @}
  */

/** @defgroup ADC_EC_AWD_Threshold  ADC AWD threshold
  * @{
  */
#define IS_ADC_AWD_THRESHOLD(THRESHOLD)    (((THRESHOLD) >= 0)  && ((THRESHOLD) <= 0xFFF))
/**
  * @}
  */

#else
/** @defgroup ADC_EC_Trigger_Source source  Adc trigger source 
  * @{
  */
#define ADC_TRGSRC_SOFTWARE     (0)
#define ADC_TRGSRC_TIMA_CH4     (MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMA_TRGO2   (MDU_ADCCTRL_TRGISRC_1)
#define ADC_TRGSRC_TIMG_TRGO    (MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMB11       (MDU_ADCCTRL_TRGISRC_3)
#define ADC_TRGSRC_TIMB12       (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMB13       (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_1)
#define ADC_TRGSRC_TIMB14       (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMB21       (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2)
#define ADC_TRGSRC_TIMB22       (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMB23       (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_1)
#define ADC_TRGSRC_TIMB24       (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)

#define IS_ADC_TRGSRC(SOURCE) (((SOURCE) == ADC_TRGSRC_SOFTWARE)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMA_CH4)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMA_TRGO2)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMG_TRGO)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMB11)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMB12)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMB13)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMB14)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMB21)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMB22)  || \
                               ((SOURCE) == ADC_TRGSRC_TIMB23) || \
                               ((SOURCE) == ADC_TRGSRC_TIMB24))
/**
  * @}
  */

/** @defgroup ADC_EC_conversion_mode mode 
  * @{
  */
#define ADC_CONVERT_SINGLECH_SINGLE          (0)  
#define ADC_CONVERT_SINGLECH_CONTINUOUS      (MDU_ADCCTRL_CONV_MODE_0)  
#define ADC_CONVERT_MULTCH_SINGLE            (MDU_ADCCTRL_CONV_MODE_1)  

#define IS_ADC_CONVERT(MODE) (((MODE) == ADC_CONVERT_SINGLECH_SINGLE)  || \
                              ((MODE) == ADC_CONVERT_SINGLECH_CONTINUOUS)  || \
                              ((MODE) == ADC_CONVERT_MULTCH_SINGLE))
/**
  * @}
  */

/** @defgroup ADC_EC_SEQ_conversion_direct sequence 
  * @{
  */
#define ADC_CONVERT_INCREMENT              (0)  
#define ADC_CONVERT_DECREMENT              (MDU_ADCCTRL_CH_MODE)  

#define IS_ADC_CONVERT_DIR(DIRECT) (((DIRECT) == ADC_CONVERT_INCREMENT)  || \
                                    ((DIRECT) == ADC_CONVERT_DECREMENT))
/**
  * @}
  */

/** @defgroup ADC_EC_TRIGGER_MODE  ADC trigger edge
  * @{
  */
#define ADC_TRIGGEREDGE_NONE               (0)                                                /*!< ADC trigger edge none    */
#define ADC_TRIGGEREDGE_RISING             (MDU_ADCCTRL_RISEEDGE)                             /*!< ADC trigger edge rising  */
#define ADC_TRIGGEREDGE_FALLING            (MDU_ADCCTRL_FALLEDGE)                             /*!< ADC trigger edge falling */
#define ADC_TRIGGEREDGE_BOTH               (MDU_ADCCTRL_RISEEDGE | MDU_ADCCTRL_FALLEDGE)      /*!< ADC trigger edge both */

#define IS_ADC_TRG_MODE(MODE) (((MODE) == ADC_TRIGGEREDGE_NONE)  || \
                               ((MODE) == ADC_TRIGGEREDGE_RISING)  || \
                               ((MODE) == ADC_TRIGGEREDGE_FALLING)  || \
                               ((MODE) == ADC_TRIGGEREDGE_BOTH))
/**
  * @}
  */

/** @defgroup ADC_EC_SEQ_conversion_group sequence 
  * @{
  */
#define ADC_GROUP_CH_0                   (MDU_ADCCTRL_GCHIND_0)
#define ADC_GROUP_CH_1                   (MDU_ADCCTRL_GCHIND_1)
#define ADC_GROUP_CH_2                   (MDU_ADCCTRL_GCHIND_2)
#define ADC_GROUP_CH_3                   (MDU_ADCCTRL_GCHIND_3)
#define ADC_GROUP_CH_4                   (MDU_ADCCTRL_GCHIND_4)
#define ADC_GROUP_CH_5                   (MDU_ADCCTRL_GCHIND_5)
#define ADC_GROUP_CH_6                   (MDU_ADCCTRL_GCHIND_6)
#define ADC_GROUP_CH_7                   (MDU_ADCCTRL_GCHIND_7)
#define ADC_GROUP_CH_8                   (MDU_ADCCTRL_GCHIND_8)
#define ADC_GROUP_CH_9                   (MDU_ADCCTRL_GCHIND_9)
#define ADC_GROUP_CH_10                  (MDU_ADCCTRL_GCHIND_10)
#define ADC_GROUP_CH_11                  (MDU_ADCCTRL_GCHIND_11)
#define ADC_GROUP_CH_12                  (MDU_ADCCTRL_GCHIND_12)
#define ADC_GROUP_CH_13                  (MDU_ADCCTRL_GCHIND_13)
#define ADC_GROUP_CH_14                  (MDU_ADCCTRL_GCHIND_14)
#define ADC_GROUP_CH_15                  (MDU_ADCCTRL_GCHIND_15)

#define IS_ADC_GROUP_CHANNEL(CHANNEL) (((CHANNEL) & ADC_GROUP_CH_0)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_1)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_2)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_3)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_4)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_5)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_6)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_7)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_8)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_9)  || \
                                       ((CHANNEL) & ADC_GROUP_CH_10) || \
                                       ((CHANNEL) & ADC_GROUP_CH_11) || \
                                       ((CHANNEL) & ADC_GROUP_CH_12) || \
                                       ((CHANNEL) & ADC_GROUP_CH_13) || \
                                       ((CHANNEL) & ADC_GROUP_CH_14) || \
                                       ((CHANNEL) & ADC_GROUP_CH_15))
/**
  * @}
  */

/** @defgroup ADC_EC_Channel_Source Channel Source 
  * @{
  */
#define ADC_CHANNEL_EXTERNAL           (0) 
#define ADC_CHANNEL_INTERBAL           (MDU_ADCCFG_ICHSLCT_0) 

#define IS_ADC_CHANNNELSOURCE(SOURCE)   (((SOURCE) == ADC_CHANNEL_EXTERNAL)  || \
                                         ((SOURCE) == ADC_CHANNEL_INTERBAL))
/**
  * @}
  */

#if defined(XT32H0xxAMPW)
/** @defgroup ADC_EC_Resolution Resolution 
  * @{
  */
#define ADC_RESOLUTION_8B              (0)
#define ADC_RESOLUTION_10B             (MDU_ADCCFG_RESCFG_0)
#define ADC_RESOLUTION_12B             (MDU_ADCCFG_RESCFG_1)

#define IS_ADC_RESOLUTION(RESOLUTION)    (((RESOLUTION) == ADC_RESOLUTION_8B)  || \
                                          ((RESOLUTION) == ADC_RESOLUTION_10B)  || \
                                          ((RESOLUTION) == ADC_RESOLUTION_12B))

/**
  * @}
  */
#endif
#endif /* XT32H0xxB */


/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
/** @addtogroup ADC_Exported_Functions
  * @{
  */

/** @addtogroup ADC_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */
/*  Function used to set the ADC configuration to the default reset state *****/
void ADC_DeInit(void);

/* Initialization and Configuration functions *********************************/ 
void ADC_Init(ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
/**
  * @}
  */ 

/** @addtogroup ADC_Exported_Functions_Group2
  * @brief    Operation functions
  * @{
  */
void ADC_Reset(void);
void ADC_ResetRelease(void);

void ADC_PowerOn(void);
void ADC_PowerDown(void);


#if defined(XT32H0xxAMPW)
void ADC_SetResolution(uint32_t Resolution);
#endif

#if defined(XT32H0xxB)
void ADC_SetMode(uint32_t Mode);

void ADC_SetDataAlignment(uint32_t Align);

void ADC_SetResolution(uint32_t Resolution);

void ADC_EnableInjectionDMA(void);
void ADC_DisableInjectionDMA(void);

void ADC_EnableRegularDMA(void);
void ADC_DisableRegularDMA(void);

void ADC_EnableInterrupts(uint32_t Interrupts);
void ADC_DisableInterrupts(uint32_t Interrupts);
void ADC_SetInjectionInterruptsPolarity(uint32_t Polarity);
void ADC_SetRegularInterruptsPolarity(uint32_t Polarity);

void ADC_SetResetDelay(uint32_t Delay);
void ADC_SetResetPulse(uint32_t Cycles);

void ADC_SetPGAPresamplingMode(uint32_t Mode);
void ADC_SetSamePGAPresamplingCycles(uint32_t Cycles);

void ADC_EnableDischargePhase(void);
void ADC_DisableDischargePhase(void);
void ADC_SetDischargePhaseCycles(uint32_t Cycles);

void ADC_EnableControler(void);
void ADC_DisableControler(void);

void ADC_SoftwareTriggerForeceHigh(void);
void ADC_SoftwareTriggerForeceLow(void);

void ADC_Start(void);
void ADC_Stop(void);


/* injection group */
void ADC_EnableInjectionGroup(void);
void ADC_DisableInjectionGroup(void);
void ADC_SetInjectionGroupNumber(uint32_t Number);

void ADC_InjectionGroupTriggerConfig(uint32_t Group, uint32_t Source, uint32_t Mode);
void ADC_InjectionChannelConfig(uint32_t Channel, uint32_t Group, uint32_t ADCChannel, uint32_t SamplingCycles, uint32_t Awd);

uint32_t ADC_GetInjectionEOCFlag(uint32_t Channel);
uint32_t ADC_GetInjectionEOSFlag(void);
uint32_t ADC_GetInjectionAWDFlag(uint32_t Channel);
uint32_t ADC_GetInjectionOWFlag(uint32_t Channel);

uint32_t ADC_GetCompFlag(uint32_t Comp);

void ADC_ClearInjectionEOCFlag(uint32_t Channel);
void ADC_ClearInjectionEOSFlag(void);
void ADC_ClearInjectionAWDFlag(uint32_t Channel);
void ADC_ClearInjectionOWFlag(uint32_t Channel);

void ADC_ClearCompFlag(uint32_t Comp);

/* regular group */
void ADC_EnableRegularGroup(void);
void ADC_DisableRegularGroup(void);
void ADC_SetRegularGroupNumber(uint32_t Number);

void ADC_SetRegularOperationMode(uint32_t Mode);
void ADC_RegularGroupTriggerConfig(uint32_t Group, uint32_t Source, uint32_t Mode);
void ADC_SetAllRegularChannelMap(uint32_t Map);
void ADC_SetGroupRegularChannelMap(uint32_t Group, uint32_t Map);
void ADC_RegularChannelConfig(uint32_t Channel, uint32_t ADCChannel, uint32_t Awd);

void ADC_RegularGroupContinuousConversionStart(void);
void ADC_RegularGroupContinuousConversionStop(void);

uint32_t ADC_GetRegularEOCFlag(uint32_t Channel);
uint32_t ADC_GetRegularEOSFlag(void);
uint32_t ADC_GetRegularAWDFlag(uint32_t Channel);
uint32_t ADC_GetRegularOWFlag(uint32_t Channel);

void ADC_ClearRegularEOCFlag(uint32_t Channel);
void ADC_ClearRegularEOSFlag(void);
void ADC_ClearRegularAWDFlag(uint32_t Channel);
void ADC_ClearRegularOWFlag(uint32_t Channel);

/* Awd */
void ADC_AwdConfig(uint32_t Awd, uint32_t ThresholdLow, uint32_t ThresholdHigh, uint32_t Mode);

/* manual mode operations */
void ADC_EnablePGASamplingPulseInManualMode(void);
void ADC_DisablePGASamplingPulseInManualMode(void);

void ADC_SetCoreConversionMode(uint32_t Mode);
void ADC_SetCoreChannelInManualMode(uint32_t Channel);

/* calibrate */
void ADC_Calibration(void);
void ADC_CalibrationEnable(void);
void ADC_CalibrationDisable(void);
#else

void ADC_Start(void);

void ADC_ClearEOC(void);

void ADC_SetResetDelay(uint32_t Delay);
void ADC_SetChannelSource(uint32_t Source);

void ADC_SetConversionMode(uint32_t Mode);
void ADC_SetTriggerMode(uint32_t Source, uint32_t Mode);
void ADC_SetGroup(uint32_t Group, uint32_t ScanDir);

#endif

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

#endif /*__XT32H0XX_ADC_H */


