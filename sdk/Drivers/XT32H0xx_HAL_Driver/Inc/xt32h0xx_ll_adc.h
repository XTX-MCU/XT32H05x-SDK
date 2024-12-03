/**
  ******************************************************************************
  * @file    xt32h0xx_ll_adc.h
  * @author  Software Team
  * @brief   Header file of MDU ADC LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_ADC_H
#define XT32H0xx_LL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (MDU)

/** @defgroup ADC_LL ADC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Types ADC Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ADC_LL_ES_INIT ADC Exported Init structure
  * @{
  */
/**
  * @brief  Structure definition of some features of ADC instance.
  */
typedef struct
{
#if (defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW))
  uint32_t Delay;                       /*!< Set ADC delay.
                                             This parameter can be a value of 0 t 0x1F

                                             This feature can be modified afterwards using unitary function @ref LL_ADC_SetDelay(). */
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */
#if defined(XT32H0xxB)
#endif /* XT32H0xxB */
} LL_ADC_InitTypeDef;
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */
/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Constants ADC Exported Constants
  * @{
  */

/** @defgroup ADC_LL_EC_POWER ADC power control
  * @{
  */
#define LL_ADC_POWERON                 (0UL             )   /*!< DAC power on */
#define LL_ADC_POWERDOWN               (MDU_PDCTRL_ADCPD)   /*!< DAC power down */
/**
  * @}
  */

#if defined(XT32H0xxB)
/** @defgroup ADC_LL_EC_ADC_Channel ADC channel
  * @{
  */
#define LL_ADC_CHANNEL_1               (0)                 /* sync sampling channel*/
#define LL_ADC_CHANNEL_2               (1)                 /* sync sampling channel*/
#define LL_ADC_CHANNEL_3               (2)                 /* sync sampling channel*/
#define LL_ADC_CHANNEL_4               (3)                 /* sync sampling channel*/
#define LL_ADC_CHANNEL_5               (4)                 /* single-end channel*/
#define LL_ADC_CHANNEL_6               (5)                 /* single-end channel*/
#define LL_ADC_CHANNEL_7               (6)                 /* single-end channel*/
#define LL_ADC_CHANNEL_8               (7)                 /* single-end channel*/
#define LL_ADC_CHANNEL_9               (8)                 /* single-end channel*/
#define LL_ADC_CHANNEL_10              (9)                 /* single-end channel*/
#define LL_ADC_CHANNEL_11              (10)                /* single-end channel*/
#define LL_ADC_CHANNEL_12              (11)                /* single-end channel*/
#define LL_ADC_CHANNEL_13              (12)                /* single-end channel*/
#define LL_ADC_CHANNEL_14              (13)                /* single-end channel*/
#define LL_ADC_CHANNEL_15              (14)                /* single-end channel*/
#define LL_ADC_CHANNEL_16              (15)                /* single-end channel*/
#define LL_ADC_CHANNEL_17              (16)                /* single-end channel*/
#define LL_ADC_CHANNEL_18              (17)                /* single-end channel*/
#define LL_ADC_CHANNEL_19              (18)                /* single-end channel*/
#define LL_ADC_CHANNEL_20              (19)                /* single-end channel*/
#define LL_ADC_CHANNEL_21              (20)                /* single-end channel*/
#define LL_ADC_CHANNEL_22              (21)                /* single-end channel*/
#define LL_ADC_CHANNEL_23              (22)                /* single-end channel*/
#define LL_ADC_CHANNEL_24              (23)                /* single-end channel*/
#define LL_ADC_CHANNEL_25              (24)                /* single-end channel*/
#define LL_ADC_CHANNEL_26              (25)                /* single-end channel*/
#define LL_ADC_CHANNEL_27              (26)                /* single-end channel*/
#define LL_ADC_CHANNEL_28              (27)                /* single-end channel*/
#define LL_ADC_CHANNEL_29              (28)                /* single-end channel*/
#define LL_ADC_CHANNEL_30              (29)                /* single-end channel*/
#define LL_ADC_CHANNEL_31              (30)                /* single-end channel*/
#define LL_ADC_CHANNEL_32              (31)                /* single-end channel*/
#define LL_ADC_CHANNEL_33              (32)                /* single-end channel*/
#define LL_ADC_CHANNEL_34              (33)                /* single-end channel*/
#define LL_ADC_CHANNEL_35              (34)                /* single-end channel*/
#define LL_ADC_CHANNEL_36              (35)                /* single-end channel*/
#define LL_ADC_CHANNEL_37              (36)                /* single-end channel*/
#define LL_ADC_CHANNEL_38              (37)                /* single-end channel*/
#define LL_ADC_CHANNEL_39              (38)                /* single-end channel*/
#define LL_ADC_CHANNEL_40              (39)                /* single-end channel*/
#define LL_ADC_CHANNEL_41              (40)                /* single-end channel*/
#define LL_ADC_CHANNEL_42              (41)                /* single-end channel*/
#define LL_ADC_CHANNEL_43              (42)                /* single-end channel*/
#define LL_ADC_CHANNEL_44              (43)                /* single-end channel*/
#define LL_ADC_CHANNEL_45              (44)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_46              (45)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_47              (46)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_48              (47)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_49              (48)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_50              (49)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_51              (50)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_52              (51)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_53              (52)                /* single-end channel no-used */
#define LL_ADC_CHANNEL_VBG             (53)                /* single-end channel*/
#define LL_ADC_CHANNEL_VTS             (54)                /* single-end channel*/
#define LL_ADC_CHANNEL_VBS             (55)                /* single-end channel*/
#define LL_ADC_CHANNEL_P2AVDD          (56)                /* single-end channel*/
#define LL_ADC_CHANNEL_P3AVDD          (57)                /* single-end channel*/
#define LL_ADC_CHANNEL_P4AVDD          (58)                /* single-end channel*/
#define LL_ADC_CHANNEL_P5AVDD          (59)                /* single-end channel*/
#define LL_ADC_CHANNEL_P6AVDD          (60)                /* single-end channel*/
#define LL_ADC_CHANNEL_P7AVDD          (61)                /* single-end channel*/
#define LL_ADC_CHANNEL_P8AVDD          (62)                /* single-end channel*/
#define LL_ADC_CHANNEL_64              (63)                /* reserved */
/**
  * @}
  */
#else
/** @defgroup ADC_LL_EC_ADC_Channel ADC channel for manual mode
  * @{
  */
#define LL_ADC_CHANNEL_0               (0)  
#define LL_ADC_CHANNEL_1               (MDU_ADCCFG_CHSLCT_0)  
#define LL_ADC_CHANNEL_2               (MDU_ADCCFG_CHSLCT_1)  
#define LL_ADC_CHANNEL_3               (MDU_ADCCFG_CHSLCT_1 | MDU_ADCCFG_CHSLCT_0)  
#define LL_ADC_CHANNEL_4               (MDU_ADCCFG_CHSLCT_2)  
#define LL_ADC_CHANNEL_5               (MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_0)  
#define LL_ADC_CHANNEL_6               (MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_1)  
#define LL_ADC_CHANNEL_7               (MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_1 | MDU_ADCCFG_CHSLCT_0)  
#define LL_ADC_CHANNEL_8               (MDU_ADCCFG_CHSLCT_3)  
#define LL_ADC_CHANNEL_9               (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_0)  
#define LL_ADC_CHANNEL_10              (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_1)  
#define LL_ADC_CHANNEL_11              (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_1 | MDU_ADCCFG_CHSLCT_0)  
#define LL_ADC_CHANNEL_12              (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_2)  
#define LL_ADC_CHANNEL_13              (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_0)  
#define LL_ADC_CHANNEL_14              (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_1)  
#define LL_ADC_CHANNEL_15              (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_1 | MDU_ADCCFG_CHSLCT_0)  
/**
  * @}
  */

/** @defgroup ADC_LL_EC_internal source  ADC internal source
  * @{
  */
#define LL_ADC_SRC_EXTERNAL            (0)                                              /*!< ADC external source */
#define LL_ADC_SRC_INTERNAL            (MDU_ADCCFG_ITSLCT_0)                            /*!< ADC internal source */
/**
  * @}
  */
#endif /* XT32H0xxB */

#if defined(XT32H0xxAMPW)
/** @defgroup ADC_LL_EC_RESOLUTION  ADC resolution
  * @{
  */
#define LL_ADC_RESOLUTION_8B           (0)                                              /*!< ADC external source */
#define LL_ADC_RESOLUTION_10B          (MDU_ADCCFG_RESCFG_0)                            /*!< ADC internal source */
#define LL_ADC_RESOLUTION_12B          (MDU_ADCCFG_RESCFG_1)                            /*!< ADC internal source */
/**
  * @}
  */
#endif /* XT32H0xxAMPW */

#if defined(XT32H0xxB)
/** @defgroup ADC_LL_EC_RESOLUTION ADC conversion resolution
  * @{
  */
#define LL_ADC_RESOLUTION_8B              (0)
#define LL_ADC_RESOLUTION_10B             (MDU_ADCCFG_ADCDATAW_0)
#define LL_ADC_RESOLUTION_12B             (MDU_ADCCFG_ADCDATAW_1)
/** 
  * @}
  */
#endif /* XT32H0xxB */


#if defined(XT32H0xxB)
/** @defgroup ADC_LL_EC_ADC_Trigger Source ADC trigger source
  * @{
  */
#define LL_ADC_TRGSRC_NONE             (0)
#define LL_ADC_TRGSRC_TIMA1_CH4        (1)
#define LL_ADC_TRGSRC_TIMA1_TRGO2      (2)
#define LL_ADC_TRGSRC_TIMA2_CH4        (3)
#define LL_ADC_TRGSRC_TIMA2_TRGO2      (4)
#define LL_ADC_TRGSRC_TIMG1_CH4        (5)
#define LL_ADC_TRGSRC_TIMG1_TRGO2      (6)
#define LL_ADC_TRGSRC_TIMG2_CH4        (7)
#define LL_ADC_TRGSRC_TIMG2_TRGO2      (8)
#define LL_ADC_TRGSRC_TIMG3_CH4        (9)
#define LL_ADC_TRGSRC_TIMG3_TRGO2      (10)
#define LL_ADC_TRGSRC_TIMG4_CH4        (11)
#define LL_ADC_TRGSRC_TIMG4_TRGO2      (12)
#define LL_ADC_TRGSRC_TIMB11           (13)
#define LL_ADC_TRGSRC_EXTERNAL         (14)
#define LL_ADC_TRGSRC_SOFTWARE         (15)
/**
  * @}
  */
#else
/** @defgroup ADC_LL_EC_ADC_Trigger Source ADC trigger source
  * @{
  */
#define LL_ADC_TRGSRC_SOFTWARE         (0)
#define LL_ADC_TRGSRC_TIMA_CH4         (MDU_ADCCTRL_TRGISRC_0)
#define LL_ADC_TRGSRC_TIMA_TRGO2       (MDU_ADCCTRL_TRGISRC_1)
#define LL_ADC_TRGSRC_TIMG_TRGO        (MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
#define LL_ADC_TRGSRC_TIMB11           (MDU_ADCCTRL_TRGISRC_3)
#define LL_ADC_TRGSRC_TIMB12           (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_0)
#define LL_ADC_TRGSRC_TIMB13           (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_1)
#define LL_ADC_TRGSRC_TIMB14           (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
#define LL_ADC_TRGSRC_TIMB21           (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2)
#define LL_ADC_TRGSRC_TIMB22           (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_0)
#define LL_ADC_TRGSRC_TIMB23           (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_1)
#define LL_ADC_TRGSRC_TIMB24           (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
/**
  * @}
  */

#endif /*XT32H0xxB*/

#if defined(XT32H0xxB)
/** @defgroup ADC_LL_EC_TRIGGER_MODE  ADC trigger edge
  * @{
  */
#define LL_ADC_TRIGGEREDGE_NONE        (0)                                               /*!< ADC no trigger */
#define LL_ADC_TRIGGEREDGE_RISING      (1)                                               /*!< ADC trigger edge rising  */
#define LL_ADC_TRIGGEREDGE_FALLING     (2)                                               /*!< ADC trigger edge falling */
#define LL_ADC_TRIGGEREDGE_BOTH        (3)                                               /*!< ADC trigger edge both */
/**
  * @}
  */
#else
/** @defgroup ADC_LL_EC_TRIGGER_MODE  ADC trigger edge
  * @{
  */
#define LL_ADC_TRIGGEREDGE_NONE        (0)                                                /*!< ADC trigger edge none    */
#define LL_ADC_TRIGGEREDGE_RISING      (MDU_ADCCTRL_RISEEDGE)                             /*!< ADC trigger edge rising  */
#define LL_ADC_TRIGGEREDGE_FALLING     (MDU_ADCCTRL_FALLEDGE)                             /*!< ADC trigger edge falling */
#define LL_ADC_TRIGGEREDGE_BOTH        (MDU_ADCCTRL_RISEEDGE | MDU_ADCCTRL_FALLEDGE)      /*!< ADC trigger edge both */
/**
  * @}
  */

#endif /* XT32H0xxB */

#if defined(XT32H0xxB)
/** @defgroup ADC_LL_EC_conversion_mode scan mode for regular group 
  * @{
  */
#define LL_ADC_CONVERT_SINGLESCAN          (0)  
#define LL_ADC_CONVERT_CONTINUOUSSCAN      (MDU_REGGRP_TRGCFG_REGGRP_OPMODE_0)  
#define LL_ADC_CONVERT_DISCONTINUOUSSCAN   (MDU_REGGRP_TRGCFG_REGGRP_OPMODE_1)  
/**
  * @}
  */
#else
/** @defgroup ADC_LL_EC_conversion_mode mode 
  * @{
  */
#define LL_ADC_CONVERT_SINGLECH_SINGLE          (0)  
#define LL_ADC_CONVERT_SINGLECH_CONTINUOUS      (MDU_ADCCTRL_CONV_MODE_0)  
#define LL_ADC_CONVERT_MULTCH_SINGLE            (MDU_ADCCTRL_CONV_MODE_1)  
/**
  * @}
  */

/** @defgroup ADC_LL_EC_SEQ_conversion_direct sequence 
  * @{
  */
#define LL_ADC_CONVERT_INCREMENT       (0)  
#define LL_ADC_CONVERT_DECREMENT       (MDU_ADCCTRL_CH_MODE)  
/**
  * @}
  */
#endif /*XT32H0xxB*/

#if defined(XT32H0xxB)
/** @defgroup ADC_LL_EC_Injection_Groupt_Interrupt_polarity  ADC injection group interrupt polarity
  * @{
  */
#define LL_ADC_INJGRP_INT_POL_HIGH     (0)                                                /*!< ADC injection group interrupt high level */
#define LL_ADC_INJGRP_INT_POL_LOW      (MDU_MDUCFG_INJ_INT_POL)                           /*!< ADC injection group interrupt low level */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Regular_Groupt_Interrupt_polarity  ADC regular group interrupt polarity
  * @{
  */
#define LL_ADC_REGGRP_INT_POL_HIGH     (0)                                                /*!< ADC regular group interrupt high level */
#define LL_ADC_REGGRP_INT_POL_LOW      (MDU_MDUCFG_REG_INT_POL)                           /*!< ADC regular group interrupt low level */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Interrupt_Enable  ADC interrupts enable
  * @{
  */
#define LL_ADC_INT_ENABLE_INJGRP_EOC   (MDU_MDUCFG_INJ_EOC_EN)                           /*!< ADC injection group interrupt EOC enable */
#define LL_ADC_INT_ENABLE_INJGRP_EOS   (MDU_MDUCFG_INJ_EOS_EN)                           /*!< ADC injection group interrupt EOS enable */
#define LL_ADC_INT_ENABLE_REGGRP_EOC   (MDU_MDUCFG_REG_EOC_EN)                           /*!< ADC regular group interrupt EOC enable */
#define LL_ADC_INT_ENABLE_REGGRP_EOS   (MDU_MDUCFG_REG_EOS_EN)                           /*!< ADC regular group interrupt EOS enable */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Interrupt_flag  ADC interrupt flag
  * @{
  */
#define LL_ADC_FLAG_INJCH_EOC_1        (MDU_INT_STATUS_EOC_INJ_CH_1)                     /*!< ADC injection Channel 1 EOC flag */
#define LL_ADC_FLAG_INJCH_EOC_2        (MDU_INT_STATUS_EOC_INJ_CH_2)                     /*!< ADC injection Channel 2 EOC flag */
#define LL_ADC_FLAG_INJCH_EOC_3        (MDU_INT_STATUS_EOC_INJ_CH_3)                     /*!< ADC injection Channel 3 EOC flag */
#define LL_ADC_FLAG_INJCH_EOC_4        (MDU_INT_STATUS_EOC_INJ_CH_4)                     /*!< ADC injection Channel 4 EOC flag */
#define LL_ADC_FLAG_INJGRP_EOS         (MDU_INT_STATUS_EOS_INJ)                          /*!< ADC injection group EOS flag */
#define LL_ADC_FLAG_REGGRP_EOS         (MDU_INT_STATUS_EOS_REG)                          /*!< ADC regular group EOC flag */
#define LL_ADC_FLAG_INJCH_AWD_1        (MDU_INT_STATUS_AWD_INJ_CH_1)                     /*!< ADC injection Channel 1 AWD flag */
#define LL_ADC_FLAG_INJCH_AWD_2        (MDU_INT_STATUS_AWD_INJ_CH_2)                     /*!< ADC injection Channel 2 AWD flag */
#define LL_ADC_FLAG_INJCH_AWD_3        (MDU_INT_STATUS_AWD_INJ_CH_3)                     /*!< ADC injection Channel 3 AWD flag */
#define LL_ADC_FLAG_INJCH_AWD_4        (MDU_INT_STATUS_AWD_INJ_CH_4)                     /*!< ADC injection Channel 4 AWD flag */
#define LL_ADC_FLAG_INJCH_OW_1         (MDU_INT_STATUS_OW_INJ_CH_1)                      /*!< ADC injection channel 1 OverWrite flag */
#define LL_ADC_FLAG_INJCH_OW_2         (MDU_INT_STATUS_OW_INJ_CH_2)                      /*!< ADC injection channel 2 OverWrite flag */
#define LL_ADC_FLAG_INJCH_OW_3         (MDU_INT_STATUS_OW_INJ_CH_3)                      /*!< ADC injection channel 3 OverWrite flag */
#define LL_ADC_FLAG_INJCH_OW_4         (MDU_INT_STATUS_OW_INJ_CH_4)                      /*!< ADC injection channel 4 OverWrite flag */
#define LL_ADC_FLAG_INJGRP_OW          (MDU_INT_STATUS_OW_INJ_GRP)                       /*!< ADC injection group OverWrite flag */
#define LL_ADC_FLAG_REGGRP_OW          (MDU_INT_STATUS_OW_REG_GRP)                       /*!< ADC regular group OverWrite flag */

#define LL_ADC_FLAG_REGCH_EOC_1        (MDU_INT_STATUS_EOC_REG_CH_1)                     /*!< ADC regular Channel 1 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_2        (MDU_INT_STATUS_EOC_REG_CH_2)                     /*!< ADC regular Channel 2 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_3        (MDU_INT_STATUS_EOC_REG_CH_3)                     /*!< ADC regular Channel 3 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_4        (MDU_INT_STATUS_EOC_REG_CH_4)                     /*!< ADC regular Channel 4 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_5        (MDU_INT_STATUS_EOC_REG_CH_5)                     /*!< ADC regular Channel 5 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_6        (MDU_INT_STATUS_EOC_REG_CH_6)                     /*!< ADC regular Channel 6 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_7        (MDU_INT_STATUS_EOC_REG_CH_7)                     /*!< ADC regular Channel 7 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_8        (MDU_INT_STATUS_EOC_REG_CH_8)                     /*!< ADC regular Channel 8 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_9        (MDU_INT_STATUS_EOC_REG_CH_9)                     /*!< ADC regular Channel 9 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_10       (MDU_INT_STATUS_EOC_REG_CH_10)                    /*!< ADC regular Channel 10 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_11       (MDU_INT_STATUS_EOC_REG_CH_11)                    /*!< ADC regular Channel 11 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_12       (MDU_INT_STATUS_EOC_REG_CH_12)                    /*!< ADC regular Channel 12 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_13       (MDU_INT_STATUS_EOC_REG_CH_13)                    /*!< ADC regular Channel 13 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_14       (MDU_INT_STATUS_EOC_REG_CH_14)                    /*!< ADC regular Channel 14 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_15       (MDU_INT_STATUS_EOC_REG_CH_15)                    /*!< ADC regular Channel 15 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_16       (MDU_INT_STATUS_EOC_REG_CH_16)                    /*!< ADC regular Channel 16 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_17       (MDU_INT_STATUS_EOC_REG_CH_17)                    /*!< ADC regular Channel 17 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_18       (MDU_INT_STATUS_EOC_REG_CH_18)                    /*!< ADC regular Channel 18 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_19       (MDU_INT_STATUS_EOC_REG_CH_19)                    /*!< ADC regular Channel 19 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_20       (MDU_INT_STATUS_EOC_REG_CH_20)                    /*!< ADC regular Channel 20 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_21       (MDU_INT_STATUS_EOC_REG_CH_21)                    /*!< ADC regular Channel 21 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_22       (MDU_INT_STATUS_EOC_REG_CH_22)                    /*!< ADC regular Channel 22 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_23       (MDU_INT_STATUS_EOC_REG_CH_23)                    /*!< ADC regular Channel 23 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_24       (MDU_INT_STATUS_EOC_REG_CH_24)                    /*!< ADC regular Channel 24 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_25       (MDU_INT_STATUS_EOC_REG_CH_25)                    /*!< ADC regular Channel 25 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_26       (MDU_INT_STATUS_EOC_REG_CH_26)                    /*!< ADC regular Channel 26 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_27       (MDU_INT_STATUS_EOC_REG_CH_27)                    /*!< ADC regular Channel 27 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_28       (MDU_INT_STATUS_EOC_REG_CH_28)                    /*!< ADC regular Channel 28 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_29       (MDU_INT_STATUS_EOC_REG_CH_29)                    /*!< ADC regular Channel 29 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_30       (MDU_INT_STATUS_EOC_REG_CH_30)                    /*!< ADC regular Channel 30 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_31       (MDU_INT_STATUS_EOC_REG_CH_31)                    /*!< ADC regular Channel 31 EOC flag */
#define LL_ADC_FLAG_REGCH_EOC_32       (MDU_INT_STATUS_EOC_REG_CH_32)                    /*!< ADC regular Channel 32 EOC flag */

#define LL_ADC_FLAG_REGCH_OW_1         (MDU_INT_STATUS_OW_REG_CH_1)                      /*!< ADC regular Channel 1 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_2         (MDU_INT_STATUS_OW_REG_CH_2)                      /*!< ADC regular Channel 2 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_3         (MDU_INT_STATUS_OW_REG_CH_3)                      /*!< ADC regular Channel 3 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_4         (MDU_INT_STATUS_OW_REG_CH_4)                      /*!< ADC regular Channel 4 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_5         (MDU_INT_STATUS_OW_REG_CH_5)                      /*!< ADC regular Channel 5 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_6         (MDU_INT_STATUS_OW_REG_CH_6)                      /*!< ADC regular Channel 6 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_7         (MDU_INT_STATUS_OW_REG_CH_7)                      /*!< ADC regular Channel 7 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_8         (MDU_INT_STATUS_OW_REG_CH_8)                      /*!< ADC regular Channel 8 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_9         (MDU_INT_STATUS_OW_REG_CH_9)                      /*!< ADC regular Channel 9 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_10        (MDU_INT_STATUS_OW_REG_CH_10)                     /*!< ADC regular Channel 10 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_11        (MDU_INT_STATUS_OW_REG_CH_11)                     /*!< ADC regular Channel 11 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_12        (MDU_INT_STATUS_OW_REG_CH_12)                     /*!< ADC regular Channel 12 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_13        (MDU_INT_STATUS_OW_REG_CH_13)                     /*!< ADC regular Channel 13 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_14        (MDU_INT_STATUS_OW_REG_CH_14)                     /*!< ADC regular Channel 14 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_15        (MDU_INT_STATUS_OW_REG_CH_15)                     /*!< ADC regular Channel 15 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_16        (MDU_INT_STATUS_OW_REG_CH_16)                     /*!< ADC regular Channel 16 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_17        (MDU_INT_STATUS_OW_REG_CH_17)                     /*!< ADC regular Channel 17 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_18        (MDU_INT_STATUS_OW_REG_CH_18)                     /*!< ADC regular Channel 18 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_19        (MDU_INT_STATUS_OW_REG_CH_19)                     /*!< ADC regular Channel 19 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_20        (MDU_INT_STATUS_OW_REG_CH_20)                     /*!< ADC regular Channel 20 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_21        (MDU_INT_STATUS_OW_REG_CH_21)                     /*!< ADC regular Channel 21 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_22        (MDU_INT_STATUS_OW_REG_CH_22)                     /*!< ADC regular Channel 22 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_23        (MDU_INT_STATUS_OW_REG_CH_23)                     /*!< ADC regular Channel 23 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_24        (MDU_INT_STATUS_OW_REG_CH_24)                     /*!< ADC regular Channel 24 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_25        (MDU_INT_STATUS_OW_REG_CH_25)                     /*!< ADC regular Channel 25 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_26        (MDU_INT_STATUS_OW_REG_CH_26)                     /*!< ADC regular Channel 26 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_27        (MDU_INT_STATUS_OW_REG_CH_27)                     /*!< ADC regular Channel 27 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_28        (MDU_INT_STATUS_OW_REG_CH_28)                     /*!< ADC regular Channel 28 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_29        (MDU_INT_STATUS_OW_REG_CH_29)                     /*!< ADC regular Channel 29 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_30        (MDU_INT_STATUS_OW_REG_CH_30)                     /*!< ADC regular Channel 30 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_31        (MDU_INT_STATUS_OW_REG_CH_31)                     /*!< ADC regular Channel 31 OverWrite flag */
#define LL_ADC_FLAG_REGCH_OW_32        (MDU_INT_STATUS_OW_REG_CH_32)                     /*!< ADC regular Channel 32 OverWrite flag */

#define LL_ADC_FLAG_REGCH_AWD_1        (MDU_INT_STATUS_AWD_REG_CH_0)                     /*!< ADC regular Channel 1 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_2        (MDU_INT_STATUS_AWD_REG_CH_1)                     /*!< ADC regular Channel 2 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_3        (MDU_INT_STATUS_AWD_REG_CH_2)                     /*!< ADC regular Channel 3 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_4        (MDU_INT_STATUS_AWD_REG_CH_3)                     /*!< ADC regular Channel 4 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_5        (MDU_INT_STATUS_AWD_REG_CH_4)                     /*!< ADC regular Channel 5 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_6        (MDU_INT_STATUS_AWD_REG_CH_5)                     /*!< ADC regular Channel 6 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_7        (MDU_INT_STATUS_AWD_REG_CH_6)                     /*!< ADC regular Channel 7 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_8        (MDU_INT_STATUS_AWD_REG_CH_7)                     /*!< ADC regular Channel 8 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_9        (MDU_INT_STATUS_AWD_REG_CH_8)                     /*!< ADC regular Channel 9 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_10       (MDU_INT_STATUS_AWD_REG_CH_9)                     /*!< ADC regular Channel 10 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_11       (MDU_INT_STATUS_AWD_REG_CH_10)                    /*!< ADC regular Channel 11 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_12       (MDU_INT_STATUS_AWD_REG_CH_11)                    /*!< ADC regular Channel 12 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_13       (MDU_INT_STATUS_AWD_REG_CH_12)                    /*!< ADC regular Channel 13 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_14       (MDU_INT_STATUS_AWD_REG_CH_13)                    /*!< ADC regular Channel 14 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_15       (MDU_INT_STATUS_AWD_REG_CH_14)                    /*!< ADC regular Channel 15 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_16       (MDU_INT_STATUS_AWD_REG_CH_15)                    /*!< ADC regular Channel 16 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_17       (MDU_INT_STATUS_AWD_REG_CH_16)                    /*!< ADC regular Channel 17 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_18       (MDU_INT_STATUS_AWD_REG_CH_17)                    /*!< ADC regular Channel 18 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_19       (MDU_INT_STATUS_AWD_REG_CH_18)                    /*!< ADC regular Channel 19 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_20       (MDU_INT_STATUS_AWD_REG_CH_19)                    /*!< ADC regular Channel 20 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_21       (MDU_INT_STATUS_AWD_REG_CH_20)                    /*!< ADC regular Channel 21 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_22       (MDU_INT_STATUS_AWD_REG_CH_21)                    /*!< ADC regular Channel 22 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_23       (MDU_INT_STATUS_AWD_REG_CH_22)                    /*!< ADC regular Channel 23 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_24       (MDU_INT_STATUS_AWD_REG_CH_23)                    /*!< ADC regular Channel 24 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_25       (MDU_INT_STATUS_AWD_REG_CH_24)                    /*!< ADC regular Channel 25 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_26       (MDU_INT_STATUS_AWD_REG_CH_25)                    /*!< ADC regular Channel 26 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_27       (MDU_INT_STATUS_AWD_REG_CH_26)                    /*!< ADC regular Channel 27 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_28       (MDU_INT_STATUS_AWD_REG_CH_27)                    /*!< ADC regular Channel 28 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_29       (MDU_INT_STATUS_AWD_REG_CH_28)                    /*!< ADC regular Channel 29 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_30       (MDU_INT_STATUS_AWD_REG_CH_29)                    /*!< ADC regular Channel 30 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_31       (MDU_INT_STATUS_AWD_REG_CH_30)                    /*!< ADC regular Channel 31 AWD flag */
#define LL_ADC_FLAG_REGCH_AWD_32       (MDU_INT_STATUS_AWD_REG_CH_31)                    /*!< ADC regular Channel 32 AWD flag */
/**
  * @}
  */


/** @defgroup ADC_LL_EC_Injection_Channel_index  ADC injection channle index
  * @{
  */
#define LL_ADC_INJCH_1                 (0)                                               /*!< ADC injection channel 1 index */
#define LL_ADC_INJCH_2                 (1)                                               /*!< ADC injection channel 2 index */
#define LL_ADC_INJCH_3                 (2)                                               /*!< ADC injection channel 3 index */
#define LL_ADC_INJCH_4                 (3)                                               /*!< ADC injection channel 4 index */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Injection_Group_index  ADC injection group index
  * @{
  */
#define LL_ADC_INJGRP_1                (0)                                               /*!< ADC injection group 1 index */
#define LL_ADC_INJGRP_2                (1)                                               /*!< ADC injection group 2 index */
#define LL_ADC_INJGRP_3                (2)                                               /*!< ADC injection group 3 index */
#define LL_ADC_INJGRP_4                (3)                                               /*!< ADC injection group 4 index */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Injection_Group_Number  ADC injection group number
  * @{
  */
#define LL_ADC_INJGRP_NUMBER_1         (MDU_INJGRP_TRG_INJGRP_SGRP_NUM_0)                                               /*!< ADC injection group number 1 */
#define LL_ADC_INJGRP_NUMBER_2         (MDU_INJGRP_TRG_INJGRP_SGRP_NUM_1)                                               /*!< ADC injection group number 2 */
#define LL_ADC_INJGRP_NUMBER_3         (MDU_INJGRP_TRG_INJGRP_SGRP_NUM_1|MDU_INJGRP_TRG_INJGRP_SGRP_NUM_0)              /*!< ADC injection group number 3 */
#define LL_ADC_INJGRP_NUMBER_4         (MDU_INJGRP_TRG_INJGRP_SGRP_NUM_2)                                               /*!< ADC injection group number 4 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Regular_Group_index  ADC regular group index
  * @{
  */
#define LL_ADC_REGGRP_1                (0)                                               /*!< ADC regular group 1 index */
#define LL_ADC_REGGRP_2                (1)                                               /*!< ADC regular group 2 index */
#define LL_ADC_REGGRP_3                (2)                                               /*!< ADC regular group 3 index */
#define LL_ADC_REGGRP_4                (3)                                               /*!< ADC regular group 4 index */
#define LL_ADC_REGGRP_5                (4)                                               /*!< ADC regular group 5 index */
#define LL_ADC_REGGRP_6                (5)                                               /*!< ADC regular group 6 index */
#define LL_ADC_REGGRP_7                (6)                                               /*!< ADC regular group 7 index */
#define LL_ADC_REGGRP_8                (7)                                               /*!< ADC regular group 8 index */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Regular_Channel_Index  ADC Regular channle index
  * @{
  */
#define LL_ADC_REGCH_1                     (0)                               /*!< ADC regular channel 1 */
#define LL_ADC_REGCH_2                     (1)                               /*!< ADC regular channel 2 */
#define LL_ADC_REGCH_3                     (2)                               /*!< ADC regular channel 3 */
#define LL_ADC_REGCH_4                     (3)                               /*!< ADC regular channel 4 */
#define LL_ADC_REGCH_5                     (4)                               /*!< ADC regular channel 5 */
#define LL_ADC_REGCH_6                     (5)                               /*!< ADC regular channel 6 */
#define LL_ADC_REGCH_7                     (6)                               /*!< ADC regular channel 7 */
#define LL_ADC_REGCH_8                     (7)                               /*!< ADC regular channel 8 */
#define LL_ADC_REGCH_9                     (8)                               /*!< ADC regular channel 9 */
#define LL_ADC_REGCH_10                    (9)                               /*!< ADC regular channel 10 */
#define LL_ADC_REGCH_11                    (10)                              /*!< ADC regular channel 11 */
#define LL_ADC_REGCH_12                    (11)                              /*!< ADC regular channel 12 */
#define LL_ADC_REGCH_13                    (12)                              /*!< ADC regular channel 13 */
#define LL_ADC_REGCH_14                    (13)                              /*!< ADC regular channel 14 */
#define LL_ADC_REGCH_15                    (14)                              /*!< ADC regular channel 15 */
#define LL_ADC_REGCH_16                    (15)                              /*!< ADC regular channel 16 */
#define LL_ADC_REGCH_17                    (16)                              /*!< ADC regular channel 17 */
#define LL_ADC_REGCH_18                    (17)                              /*!< ADC regular channel 18 */
#define LL_ADC_REGCH_19                    (18)                              /*!< ADC regular channel 19 */
#define LL_ADC_REGCH_20                    (19)                              /*!< ADC regular channel 20 */
#define LL_ADC_REGCH_21                    (20)                              /*!< ADC regular channel 21 */
#define LL_ADC_REGCH_22                    (21)                              /*!< ADC regular channel 22 */
#define LL_ADC_REGCH_23                    (22)                              /*!< ADC regular channel 23 */
#define LL_ADC_REGCH_24                    (23)                              /*!< ADC regular channel 24 */
#define LL_ADC_REGCH_25                    (24)                              /*!< ADC regular channel 25 */
#define LL_ADC_REGCH_26                    (25)                              /*!< ADC regular channel 26 */
#define LL_ADC_REGCH_27                    (26)                              /*!< ADC regular channel 27 */
#define LL_ADC_REGCH_28                    (27)                              /*!< ADC regular channel 28 */
#define LL_ADC_REGCH_29                    (28)                              /*!< ADC regular channel 29 */
#define LL_ADC_REGCH_30                    (29)                              /*!< ADC regular channel 30 */
#define LL_ADC_REGCH_31                    (30)                              /*!< ADC regular channel 31 */
#define LL_ADC_REGCH_32                    (31)                              /*!< ADC regular channel 32 */

/*** @defgroup ADC_LL_EC_Regular_Channel_map  ADC Regular channle map
  * @{
  */
#define LL_ADC_REGCH_MAP_1                 (0x00000001UL << 0)                               /*!< ADC regular channel 1 */
#define LL_ADC_REGCH_MAP_2                 (0x00000001UL << 1)                               /*!< ADC regular channel 2 */
#define LL_ADC_REGCH_MAP_3                 (0x00000001UL << 2)                               /*!< ADC regular channel 3 */
#define LL_ADC_REGCH_MAP_4                 (0x00000001UL << 3)                               /*!< ADC regular channel 4 */
#define LL_ADC_REGCH_MAP_5                 (0x00000001UL << 4)                               /*!< ADC regular channel 5 */
#define LL_ADC_REGCH_MAP_6                 (0x00000001UL << 5)                               /*!< ADC regular channel 6 */
#define LL_ADC_REGCH_MAP_7                 (0x00000001UL << 6)                               /*!< ADC regular channel 7 */
#define LL_ADC_REGCH_MAP_8                 (0x00000001UL << 7)                               /*!< ADC regular channel 8 */
#define LL_ADC_REGCH_MAP_9                 (0x00000001UL << 8)                               /*!< ADC regular channel 9 */
#define LL_ADC_REGCH_MAP_10                (0x00000001UL << 9)                               /*!< ADC regular channel 10 */
#define LL_ADC_REGCH_MAP_11                (0x00000001UL << 10)                              /*!< ADC regular channel 11 */
#define LL_ADC_REGCH_MAP_12                (0x00000001UL << 11)                              /*!< ADC regular channel 12 */
#define LL_ADC_REGCH_MAP_13                (0x00000001UL << 12)                              /*!< ADC regular channel 13 */
#define LL_ADC_REGCH_MAP_14                (0x00000001UL << 13)                              /*!< ADC regular channel 14 */
#define LL_ADC_REGCH_MAP_15                (0x00000001UL << 14)                              /*!< ADC regular channel 15 */
#define LL_ADC_REGCH_MAP_16                (0x00000001UL << 15)                              /*!< ADC regular channel 16 */
#define LL_ADC_REGCH_MAP_17                (0x00000001UL << 16)                              /*!< ADC regular channel 17 */
#define LL_ADC_REGCH_MAP_18                (0x00000001UL << 17)                              /*!< ADC regular channel 18 */
#define LL_ADC_REGCH_MAP_19                (0x00000001UL << 18)                              /*!< ADC regular channel 19 */
#define LL_ADC_REGCH_MAP_20                (0x00000001UL << 19)                              /*!< ADC regular channel 20 */
#define LL_ADC_REGCH_MAP_21                (0x00000001UL << 20)                              /*!< ADC regular channel 21 */
#define LL_ADC_REGCH_MAP_22                (0x00000001UL << 21)                              /*!< ADC regular channel 22 */
#define LL_ADC_REGCH_MAP_23                (0x00000001UL << 22)                              /*!< ADC regular channel 23 */
#define LL_ADC_REGCH_MAP_24                (0x00000001UL << 23)                              /*!< ADC regular channel 24 */
#define LL_ADC_REGCH_MAP_25                (0x00000001UL << 24)                              /*!< ADC regular channel 25 */
#define LL_ADC_REGCH_MAP_26                (0x00000001UL << 25)                              /*!< ADC regular channel 26 */
#define LL_ADC_REGCH_MAP_27                (0x00000001UL << 26)                              /*!< ADC regular channel 27 */
#define LL_ADC_REGCH_MAP_28                (0x00000001UL << 27)                              /*!< ADC regular channel 28 */
#define LL_ADC_REGCH_MAP_29                (0x00000001UL << 28)                              /*!< ADC regular channel 29 */
#define LL_ADC_REGCH_MAP_30                (0x00000001UL << 29)                              /*!< ADC regular channel 30 */
#define LL_ADC_REGCH_MAP_31                (0x00000001UL << 30)                              /*!< ADC regular channel 31 */
#define LL_ADC_REGCH_MAP_32                (0x00000001UL << 31)                              /*!< ADC regular channel 32 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Regular_Group_index  ADC regular group index
  * @{
  */
#define LL_ADC_REGGRP_1                (0)                                               /*!< ADC regular group 1 index */
#define LL_ADC_REGGRP_2                (1)                                               /*!< ADC regular group 2 index */
#define LL_ADC_REGGRP_3                (2)                                               /*!< ADC regular group 3 index */
#define LL_ADC_REGGRP_4                (3)                                               /*!< ADC regular group 4 index */
#define LL_ADC_REGGRP_5                (4)                                               /*!< ADC regular group 5 index */
#define LL_ADC_REGGRP_6                (5)                                               /*!< ADC regular group 6 index */
#define LL_ADC_REGGRP_7                (6)                                               /*!< ADC regular group 7 index */
#define LL_ADC_REGGRP_8                (7)                                               /*!< ADC regular group 8 index */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Regular_Group_Number  ADC regular group number
  * @{
  */
#define LL_ADC_REGGRP_NUMBER_1         (MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_0)                                               /*!< ADC regular group number 1 */
#define LL_ADC_REGGRP_NUMBER_2         (MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_1)                                               /*!< ADC regular group number 2 */
#define LL_ADC_REGGRP_NUMBER_3         (MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_1|MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_0)           /*!< ADC regular group number 3 */
#define LL_ADC_REGGRP_NUMBER_4         (MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_2)                                               /*!< ADC regular group number 4 */
#define LL_ADC_REGGRP_NUMBER_5         (MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_2|MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_0)           /*!< ADC regular group number 5 */
#define LL_ADC_REGGRP_NUMBER_6         (MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_2|MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_1)           /*!< ADC regular group number 6 */
#define LL_ADC_REGGRP_NUMBER_7         (MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_2|MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_1|MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_0)      /*!< ADC regular group number 7 */
#define LL_ADC_REGGRP_NUMBER_8         (MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_3)                                               /*!< ADC regular group number 8 */
/**
  * @}
  */
#else 
/** @defgroup ADC_LL_EC_SEQ_conversion_group sequence 
  * @{
  */
#define LL_ADC_GROUP_CH_0              (MDU_ADCCTRL_GCHIND_0)
#define LL_ADC_GROUP_CH_1              (MDU_ADCCTRL_GCHIND_1)
#define LL_ADC_GROUP_CH_2              (MDU_ADCCTRL_GCHIND_2)
#define LL_ADC_GROUP_CH_3              (MDU_ADCCTRL_GCHIND_3)
#define LL_ADC_GROUP_CH_4              (MDU_ADCCTRL_GCHIND_4)
#define LL_ADC_GROUP_CH_5              (MDU_ADCCTRL_GCHIND_5)
#define LL_ADC_GROUP_CH_6              (MDU_ADCCTRL_GCHIND_6)
#define LL_ADC_GROUP_CH_7              (MDU_ADCCTRL_GCHIND_7)
#define LL_ADC_GROUP_CH_8              (MDU_ADCCTRL_GCHIND_8)
#define LL_ADC_GROUP_CH_9              (MDU_ADCCTRL_GCHIND_9)
#define LL_ADC_GROUP_CH_10             (MDU_ADCCTRL_GCHIND_10)
#define LL_ADC_GROUP_CH_11             (MDU_ADCCTRL_GCHIND_11)
#define LL_ADC_GROUP_CH_12             (MDU_ADCCTRL_GCHIND_12)
#define LL_ADC_GROUP_CH_13             (MDU_ADCCTRL_GCHIND_13)
#define LL_ADC_GROUP_CH_14             (MDU_ADCCTRL_GCHIND_14)
#define LL_ADC_GROUP_CH_15             (MDU_ADCCTRL_GCHIND_15)
/**
  * @}
  */
#endif /* XT32H0xxB */

#if defined(XT32H0xxB)
/** @defgroup ADC_LL_EC_OUTPUT_ALIGNMENT ADC output alignment
  * @{
  */
#define LL_ADC_OUTPUT_AGLIN_LSB         (0)                                              /*!< ADC output alignment LSB */
#define LL_ADC_OUTPUT_AGLIN_MSB         (MDU_ADCCFG_ADCOUTALIGN)                         /*!< ADC output alignment MSB */
/** 
  * @}
  */

/** @defgroup ADC_LL_EC_Channel_AWD_Index  ADC channel analog watch dog index
  * @{
  */
#define LL_ADC_AWD_1                   (0)                                               /*!< ADC injection channel AWD index 0 */
#define LL_ADC_AWD_2                   (1)                                               /*!< ADC injection channel AWD index 1 */
#define LL_ADC_AWD_3                   (2)                                               /*!< ADC injection channel AWD index 2 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_Channel_AWD_Id  ADC  channel analog watch dog id
  * @{
  */
#define LL_ADC_AWD_ID_NONE             (0)                                               /*!< ADC injection channel AWD none */
#define LL_ADC_AWD_ID_1                (1)                                               /*!< ADC injection channel AWD id 1 */
#define LL_ADC_AWD_ID_2                (2)                                               /*!< ADC injection channel AWD id 2 */
#define LL_ADC_AWD_ID_3                (3)                                               /*!< ADC injection channel AWD id 3 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_AWD_Mode  ADC channel analog watch dog monitor mode
  * @{
  */
#define LL_ADC_AWD_MODE_NONE           (0)                                               /*!< ADC AWD none */
#define LL_ADC_AWD_MODE_LOW            (MDU_AWD_CR_CFG_1_0)                              /*!< ADC AWD output when the vaule is less than low threshold */
#define LL_ADC_AWD_MODE_HIGH           (MDU_AWD_CR_CFG_1_1)                              /*!< ADC AWD output when the vaule is in [low threshold, high threshold] */
#define LL_ADC_AWD_MODE_MID            (MDU_AWD_CR_CFG_1_1|MDU_AWD_CR_CFG_1_0)           /*!< ADC AWD output when the vaule is greater than high threshold */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_CONTROL_MODE ADC control mode
  * @{
  */
#define LL_ADC_CONTROL_MODE_MANUAL        (0)                                             /*!< ADC manual mode */
#define LL_ADC_CONTROL_MODE_AUTO          (MDU_ADCCFG_ADCC_EN)                            /*!< ADC auto mode */
/** 
  * @}
  */

/** @defgroup ADC_LL_EC_MANU_SAMPLEPULSE_ENABLE ADC PFA sample pulse enable for manual mode
  * @{
  */
#define LL_ADC_MANU_SAMPLE_PULSE_DISABLE (0)                                              /*!< ADC PGA sample pulse disable */
#define LL_ADC_MANU_SAMPLE_PULSE_ENABLE  (MDU_ADCCFG_MSAMPEN)                             /*!< ADC PGA sample pulse enable */
/** 
  * @}
  */

/** @defgroup ADC_LL_EC_MANU_CONV_MODE ADC conversion mode for manual mode
  * @{
  */
#define LL_ADC_MANU_CONV_MODE_CONTINUOUS  (0)                                             /*!< ADC manual conversion mode - continuous conversion */
#define LL_ADC_MANU_CONV_MODE_SINGLE      (MDU_ADCCFG_MCONVMODE)                          /*!< ADC manual conversion mode - single conversion */
/** 
  * @}
  */

/** @defgroup ADC_LL_EC_MANU_CHANNEL ADC channel for manual mode
  * @{
  */
#define LL_ADC_MANU_CHANNEL_0             (0)                                             /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_1             (MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_2             (MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_3             (MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_4             (MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_5             (MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_6             (MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_7             (MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_8             (MDU_ADCCFG_MCHSLCT_3)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_9             (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_10            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_11            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_12            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_13            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_14            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_15            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_16            (MDU_ADCCFG_MCHSLCT_4)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_17            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_18            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_19            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_20            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_21            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_22            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_23            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_24            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_25            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_26            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_27            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_28            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_29            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_30            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_31            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_32            (MDU_ADCCFG_MCHSLCT_5)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_33            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_34            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_35            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_36            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_37            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_38            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_39            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_40            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_41            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_42            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_43            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_44            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_45            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_46            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_47            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_48            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_49            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_50            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_51            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_52            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_53            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_54            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_55            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_56            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_57            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_58            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_59            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_60            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_61            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_62            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define LL_ADC_MANU_CHANNEL_63            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */

/** 
  * @}
  */
#endif /* XT32H0xxB */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Macros ADC Exported Macros
  * @{
  */

/** @defgroup ADC_LL_EM_WRITE_READ Common write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in ADC register
  * @param  __INSTANCE__ ADC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register

  */
#define LL_ADC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in ADC register
  * @param  __INSTANCE__ ADC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_ADC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup ADC_LL_EM_HELPER_MACRO ADC helper macro
  * @{
  */
#if defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW)
/**
  * @brief  Helper macro to get ADC channel in literal format LL_ADC_GROUP_CH_x
  *         from number in decimal format.
  * @note   Example:
  *           __LL_ADC_DECIMAL_NB_TO_CHANNEL(4)
  *           will return a data equivalent to "LL_ADC_GROUP_CH_4".
  * @param  __DECIMAL_NB__ Value between Min_Data=0 and Max_Data=15
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_0
  */
//#define __LL_ADC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                         \
//  (((__DECIMAL_NB__) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS) |                 \
//   (ADC_CHSELR_CHSEL0 << (__DECIMAL_NB__)))

#define __LL_ADC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                         \
  ((0x01UL << (__DECIMAL_NB__)) << (MDU_ADCCTRL_GCHIND_Pos))
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Functions ADC Exported Functions
  * @{
  */

/** @defgroup ADC_LL_EF_Power_Management ADC power management
  * @{
  */
/**
  * @brief  Function to configure power on
  * @rmtoll MDU_PDCTRL      ADCPD               LL_MDU_ADC_PowerOn
  */
__STATIC_INLINE void LL_MDU_ADC_PowerOn(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_ADCPD);
}

/**
  * @brief  Function to configure power down
  * @rmtoll MDU_PDCTRL      ADCPD               LL_MDU_ADC_PowerDown
  */
__STATIC_INLINE void LL_MDU_ADC_PowerDown(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_ADCPD);
}

/**
  * @}
  */

/** @defgroup MDU_LL_EF_ADC_Managment ADC manage
  * @{
  */
#if defined(XT32H0xxBMPW)
/**
  * @brief ADC Set temperature sensor trim.
  * @param Trim the value is 0 to 0x7

  */
__STATIC_INLINE void LL_MDU_ADC_SetTSTrim(uint32_t Trim)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_TS_TRIM, ((Trim) << MDU_ADCCFG_TS_TRIM_Pos));
}

/**
  * @brief ADC Get temperature sensor trim.
  * @retval the value is 0 to 0x7
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetTSTrim(void)
{
  return (uint32_t)((READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_TS_TRIM)) >> MDU_ADCCFG_TS_TRIM_Pos);
}

/**
  * @brief ADC Set Dtune.
  * @param Tune the value is 0 to 0x3

  */
__STATIC_INLINE void LL_MDU_ADC_SetDTune(uint32_t Tune)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_ADCDTUNE, ((Tune) << MDU_ADCCFG_ADCDTUNE_Pos));
}

/**
  * @brief ADC Get Dtune.
  * @retval the value is 0 to 0x3
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetDTune(void)
{
  return (uint32_t) ((READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_ADCDTUNE)) >> MDU_ADCCFG_ADCDTUNE_Pos);
}
#endif /* XT32H0xxBMPW */

/**
  * @brief ADC Set AMP Gain.
  * @param Gain the value is 0 to 0x3

  */
__STATIC_INLINE void LL_MDU_ADC_SetAmpGain(uint32_t Gain)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_AMPGAIN, ((Gain) << MDU_ADCCFG_AMPGAIN_Pos));
}

/**
  * @brief ADC Get APMP Gain.
  * @retval the value is 0 to 0x3
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetAmpGain(void)
{
  return (uint32_t) ((READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_AMPGAIN)) >> MDU_ADCCFG_AMPGAIN_Pos);
}

/**
  * @brief ADC Set PGA Miller.
  * @param Pga the value is 0 to 0x3
  * @param Miller the value is 0 to 0x3

  */
__STATIC_INLINE void LL_MDU_ADC_SetPgaMiller(uint32_t Pga, uint32_t Miller)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_PGAMILLER1 << (Pga << 1) , ((Miller) << (MDU_ADCCFG_PGAMILLER1_Pos+(Pga<<1))));
}

/**
  * @brief ADC Get PGA Miller.
  * @param Pga the value is 0 to 0x3
  * @retval the value is 0 to 0x3
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetPgaMiller(uint32_t Pga)
{
  return (uint32_t)((READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_PGAMILLER1 << (Pga << 1) )) >> (MDU_ADCCFG_PGAMILLER1_Pos+(Pga<<1)));
}

/**
  * @brief ADC Set AMP Miller.
  * @param Miller the value is 0 to 1

  */
__STATIC_INLINE void LL_MDU_ADC_SetAmpMiller(uint32_t Miller)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_AMPMILLER, ((Miller) << MDU_ADCCFG_AMPMILLER_Pos));
}

/**
  * @brief ADC Get APMP Miller.
  * @retval the value is 0 to 1
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetAmpMiller(void)
{
  return (uint32_t)((READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_AMPMILLER)) >> MDU_ADCCFG_AMPMILLER_Pos);
}

/**
  * @brief ADC Set TSample.
  * @param Sample the value is 0 to 3

  */
__STATIC_INLINE void LL_MDU_ADC_SetTSample(uint32_t Sample)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_ADCTSAMPLE, ((Sample) << MDU_ADCCFG_ADCTSAMPLE_Pos));
}

/**
  * @brief ADC Get APMP TSample.
  * @retval the value is 0 to 3
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetTSample(void)
{
  return (uint32_t) ((READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_ADCTSAMPLE)) >> MDU_ADCCFG_ADCTSAMPLE_Pos);
}

#if defined(XT32H0xxB)
/**
  * @brief ADC Set data alignment.ADC_RESOLUTION_8B
  * @param Align This parameter can one of the following values: 
  *        @arg @ref LL_ADC_OUTPUT_AGLIN_LSB
  *        @arg @ref LL_ADC_OUTPUT_AGLIN_MSB

  */
__STATIC_INLINE void LL_MDU_ADC_SetDataAlign(uint32_t Align)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_ADCOUTALIGN, Align);
}

/**
  * @brief ADC Get data alignmentry.
  * @retval data alignment
  *        @arg @ref LL_ADC_OUTPUT_AGLIN_LSB
  *        @arg @ref LL_ADC_OUTPUT_AGLIN_MSB
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetDataAlign(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_ADCOUTALIGN));
}

/**
  * @brief ADC Set resolution.
  * @param Resolution This parameter can one of the following values:
  *        @arg @ref LL_ADC_RESOLUTION_8B
  *        @arg @ref LL_ADC_RESOLUTION_10B
  *        @arg @ref LL_ADC_RESOLUTION_12B

  */
__STATIC_INLINE void LL_MDU_ADC_SetResolution(uint32_t Resolution) 
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_ADCDATAW, Resolution);
}

/**
  * @brief ADC Get resolution.
  * @retval resolution
  *        @arg @ref LL_ADC_RESOLUTION_8B
  *        @arg @ref LL_ADC_RESOLUTION_10B
  *        @arg @ref LL_ADC_RESOLUTION_12B
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetResolution(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_ADCDATAW));
}

/**
  * @brief ADC Set PGA sampling clock pulse enable/disable for manual mode.
  * @param Mode This parameter can one of the following values:
  *        @arg @ref LL_ADC_MANU_SAMPLE_PULSE_DISABLE
  *        @arg @ref LL_ADC_MANU_SAMPLE_PULSE_ENABLE

  */
__STATIC_INLINE void LL_MDU_ADC_SetPGASampling(uint32_t Mode) 
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_MSAMPEN, Mode);
}

/**
  * @brief ADC GetPGA sampling clock pulse enable/disable for manual mode.
  * @retval Mode
  *        @arg @ref LL_ADC_MANU_SAMPLE_PULSE_DISABLE
  *        @arg @ref LL_ADC_MANU_SAMPLE_PULSE_ENABLE
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetPGASampling(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_MSAMPEN));
}

/**
  * @brief ADC Set ADC Core Conversion mode
  * @param Mode This parameter can one of the following values:
  *        @arg @ref LL_ADC_MANU_CONV_MODE_CONTINUOUS
  *        @arg @ref LL_ADC_MANU_CONV_MODE_SINGLE    

  */
__STATIC_INLINE void LL_MDU_ADC_SetCoreCoversionMode(uint32_t Mode) 
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_MCONVMODE, Mode);
}

/**
  * @brief ADC GetPGA ADC Core Conversion mode
  * @retval Mode
  *        @arg @ref LL_ADC_MANU_CONV_MODE_CONTINUOUS
  *        @arg @ref LL_ADC_MANU_CONV_MODE_SINGLE    
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetCoreCoversionMode(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_MCONVMODE));
}

/**
  * @brief ADC Set mode
  * @param Mode This parameter can one of the following values:
  *        @arg @ref LL_ADC_CONTROL_MODE_MANUAL
  *        @arg @ref LL_ADC_CONTROL_MODE_AUTO  

  */
__STATIC_INLINE void LL_MDU_ADC_SetMode(uint32_t Mode) 
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_ADCC_EN, Mode);
}

/**
  * @brief ADC Get mode
  * @retval Mode
  *        @arg @ref LL_ADC_CONTROL_MODE_MANUAL
  *        @arg @ref LL_ADC_CONTROL_MODE_AUTO  
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetMode(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_ADCC_EN));
}

/**
  * @brief ADC Set ADC channel in manual mode
  * @param Channel This parameter can one of the following values:
  *        @arg @ref LL_ADC_CHANNEL_1     
  *        @arg @ref LL_ADC_CHANNEL_2     
  *        @arg @ref LL_ADC_CHANNEL_3     
  *        @arg @ref LL_ADC_CHANNEL_4     
  *        @arg @ref LL_ADC_CHANNEL_5     
  *        @arg @ref LL_ADC_CHANNEL_6     
  *        @arg @ref LL_ADC_CHANNEL_7     
  *        @arg @ref LL_ADC_CHANNEL_8     
  *        @arg @ref LL_ADC_CHANNEL_9     
  *        @arg @ref LL_ADC_CHANNEL_10    
  *        @arg @ref LL_ADC_CHANNEL_11    
  *        @arg @ref LL_ADC_CHANNEL_12    
  *        @arg @ref LL_ADC_CHANNEL_13    
  *        @arg @ref LL_ADC_CHANNEL_14    
  *        @arg @ref LL_ADC_CHANNEL_15    
  *        @arg @ref LL_ADC_CHANNEL_16    
  *        @arg @ref LL_ADC_CHANNEL_17    
  *        @arg @ref LL_ADC_CHANNEL_18    
  *        @arg @ref LL_ADC_CHANNEL_19    
  *        @arg @ref LL_ADC_CHANNEL_20    
  *        @arg @ref LL_ADC_CHANNEL_21    
  *        @arg @ref LL_ADC_CHANNEL_22    
  *        @arg @ref LL_ADC_CHANNEL_23    
  *        @arg @ref LL_ADC_CHANNEL_24    
  *        @arg @ref LL_ADC_CHANNEL_25    
  *        @arg @ref LL_ADC_CHANNEL_26    
  *        @arg @ref LL_ADC_CHANNEL_27    
  *        @arg @ref LL_ADC_CHANNEL_28    
  *        @arg @ref LL_ADC_CHANNEL_29    
  *        @arg @ref LL_ADC_CHANNEL_30    
  *        @arg @ref LL_ADC_CHANNEL_31    
  *        @arg @ref LL_ADC_CHANNEL_32    
  *        @arg @ref LL_ADC_CHANNEL_33    
  *        @arg @ref LL_ADC_CHANNEL_34    
  *        @arg @ref LL_ADC_CHANNEL_35    
  *        @arg @ref LL_ADC_CHANNEL_36    
  *        @arg @ref LL_ADC_CHANNEL_37    
  *        @arg @ref LL_ADC_CHANNEL_38    
  *        @arg @ref LL_ADC_CHANNEL_39    
  *        @arg @ref LL_ADC_CHANNEL_40    
  *        @arg @ref LL_ADC_CHANNEL_41    
  *        @arg @ref LL_ADC_CHANNEL_42    
  *        @arg @ref LL_ADC_CHANNEL_43    
  *        @arg @ref LL_ADC_CHANNEL_44    
  *        @arg @ref LL_ADC_CHANNEL_45    
  *        @arg @ref LL_ADC_CHANNEL_46    
  *        @arg @ref LL_ADC_CHANNEL_47    
  *        @arg @ref LL_ADC_CHANNEL_48    
  *        @arg @ref LL_ADC_CHANNEL_49    
  *        @arg @ref LL_ADC_CHANNEL_50    
  *        @arg @ref LL_ADC_CHANNEL_51    
  *        @arg @ref LL_ADC_CHANNEL_52    
  *        @arg @ref LL_ADC_CHANNEL_53     
  *        @arg @ref LL_ADC_CHANNEL_VBG   
  *        @arg @ref LL_ADC_CHANNEL_VTS   
  *        @arg @ref LL_ADC_CHANNEL_VBS   
  *        @arg @ref LL_ADC_CHANNEL_P2AVDD
  *        @arg @ref LL_ADC_CHANNEL_P2AVDD
  *        @arg @ref LL_ADC_CHANNEL_P3AVDD
  *        @arg @ref LL_ADC_CHANNEL_P4AVDD
  *        @arg @ref LL_ADC_CHANNEL_P5AVDD
  *        @arg @ref LL_ADC_CHANNEL_P6AVDD
  *        @arg @ref LL_ADC_CHANNEL_P7AVDD
  *        @arg @ref LL_ADC_CHANNEL_64    

  */
__STATIC_INLINE void LL_MDU_ADC_ManualSetChannel(uint32_t Channel) 
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_MCHSLCT, Channel);
}

/**
  * @brief ADC Get ADC channel in manual mode
  * @retval Channel
  *        @arg @ref LL_ADC_CHANNEL_1     
  *        @arg @ref LL_ADC_CHANNEL_2     
  *        @arg @ref LL_ADC_CHANNEL_3     
  *        @arg @ref LL_ADC_CHANNEL_4     
  *        @arg @ref LL_ADC_CHANNEL_5     
  *        @arg @ref LL_ADC_CHANNEL_6     
  *        @arg @ref LL_ADC_CHANNEL_7     
  *        @arg @ref LL_ADC_CHANNEL_8     
  *        @arg @ref LL_ADC_CHANNEL_9     
  *        @arg @ref LL_ADC_CHANNEL_10    
  *        @arg @ref LL_ADC_CHANNEL_11    
  *        @arg @ref LL_ADC_CHANNEL_12    
  *        @arg @ref LL_ADC_CHANNEL_13    
  *        @arg @ref LL_ADC_CHANNEL_14    
  *        @arg @ref LL_ADC_CHANNEL_15    
  *        @arg @ref LL_ADC_CHANNEL_16    
  *        @arg @ref LL_ADC_CHANNEL_17    
  *        @arg @ref LL_ADC_CHANNEL_18    
  *        @arg @ref LL_ADC_CHANNEL_19    
  *        @arg @ref LL_ADC_CHANNEL_20    
  *        @arg @ref LL_ADC_CHANNEL_21    
  *        @arg @ref LL_ADC_CHANNEL_22    
  *        @arg @ref LL_ADC_CHANNEL_23    
  *        @arg @ref LL_ADC_CHANNEL_24    
  *        @arg @ref LL_ADC_CHANNEL_25    
  *        @arg @ref LL_ADC_CHANNEL_26    
  *        @arg @ref LL_ADC_CHANNEL_27    
  *        @arg @ref LL_ADC_CHANNEL_28    
  *        @arg @ref LL_ADC_CHANNEL_29    
  *        @arg @ref LL_ADC_CHANNEL_30    
  *        @arg @ref LL_ADC_CHANNEL_31    
  *        @arg @ref LL_ADC_CHANNEL_32    
  *        @arg @ref LL_ADC_CHANNEL_33    
  *        @arg @ref LL_ADC_CHANNEL_34    
  *        @arg @ref LL_ADC_CHANNEL_35    
  *        @arg @ref LL_ADC_CHANNEL_36    
  *        @arg @ref LL_ADC_CHANNEL_37    
  *        @arg @ref LL_ADC_CHANNEL_38    
  *        @arg @ref LL_ADC_CHANNEL_39    
  *        @arg @ref LL_ADC_CHANNEL_40    
  *        @arg @ref LL_ADC_CHANNEL_41    
  *        @arg @ref LL_ADC_CHANNEL_42    
  *        @arg @ref LL_ADC_CHANNEL_43    
  *        @arg @ref LL_ADC_CHANNEL_44    
  *        @arg @ref LL_ADC_CHANNEL_45    
  *        @arg @ref LL_ADC_CHANNEL_46    
  *        @arg @ref LL_ADC_CHANNEL_47    
  *        @arg @ref LL_ADC_CHANNEL_48    
  *        @arg @ref LL_ADC_CHANNEL_49    
  *        @arg @ref LL_ADC_CHANNEL_50    
  *        @arg @ref LL_ADC_CHANNEL_51    
  *        @arg @ref LL_ADC_CHANNEL_52    
  *        @arg @ref LL_ADC_CHANNEL_53     
  *        @arg @ref LL_ADC_CHANNEL_VBG   
  *        @arg @ref LL_ADC_CHANNEL_VTS   
  *        @arg @ref LL_ADC_CHANNEL_VBS   
  *        @arg @ref LL_ADC_CHANNEL_P2AVDD
  *        @arg @ref LL_ADC_CHANNEL_P2AVDD
  *        @arg @ref LL_ADC_CHANNEL_P3AVDD
  *        @arg @ref LL_ADC_CHANNEL_P4AVDD
  *        @arg @ref LL_ADC_CHANNEL_P5AVDD
  *        @arg @ref LL_ADC_CHANNEL_P6AVDD
  *        @arg @ref LL_ADC_CHANNEL_P7AVDD
  *        @arg @ref LL_ADC_CHANNEL_64    
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetManualChannel(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_MCHSLCT));
}

#endif /* XT32H0xxB */

/**
  * @brief ADC Set reset Delay after start.
  * @param Delay reset delay 0 to 0xF

  */
__STATIC_INLINE void LL_MDU_ADC_SetDelay(uint32_t Delay)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_RSTBDLY, (Delay << MDU_ADCCFG_RSTBDLY_Pos));
}

/**
  * @brief ADC Get reset Delay after syary.
  * @retval reset delay 0 to 0xF
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetDelay(void)
{
  return (uint32_t)((READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_RSTBDLY)) >> MDU_ADCCFG_RSTBDLY_Pos);
}

#if defined(XT32H0xxAMPW)
/**
  * @brief ADC Set resolution.
  * @param Resolution This parameter can one of the following values:
  *        @arg @ref ADC_RESOLUTION_8B
  *        @arg @ref ADC_RESOLUTION_10B
  *        @arg @ref ADC_RESOLUTION_12B

  */
__STATIC_INLINE void LL_MDU_ADC_SetResolution(uint32_t Resolution) 
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_RESCFG, Resolution);
}

/**
  * @brief ADC Get resolution.
  * @retval resolution
  *        @arg @ref ADC_RESOLUTION_8B
  *        @arg @ref ADC_RESOLUTION_10B
  *        @arg @ref ADC_RESOLUTION_12B
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetResolution(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_RESCFG));
}

#endif /* XT32H0xxAMPW */

#if defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW)
/**
  * @brief ADC Set Channel.
  * @param Channel ADC channel 
  *        @arg @ref ADC_CHANNEL_0
  *        @arg @ref ADC_CHANNEL_1
  *        @arg @ref ADC_CHANNEL_2
  *        @arg @ref ADC_CHANNEL_3
  *        @arg @ref ADC_CHANNEL_4
  *        @arg @ref ADC_CHANNEL_5
  *        @arg @ref ADC_CHANNEL_6
  *        @arg @ref ADC_CHANNEL_7
  *        @arg @ref ADC_CHANNEL_8
  *        @arg @ref ADC_CHANNEL_9
  *        @arg @ref ADC_CHANNEL_10
  *        @arg @ref ADC_CHANNEL_11
  *        @arg @ref ADC_CHANNEL_12
  *        @arg @ref ADC_CHANNEL_13
  *        @arg @ref ADC_CHANNEL_14 
  *        @arg @ref ADC_CHANNEL_15 |
  *        @arg @ref ADC_CHANNEL_EXT
  *        @arg @ref ADC_CHANNEL_VBG
  *        @arg @ref ADC_CHANNEL_VTS
  *        @arg @ref ADC_CHANNEL_VBS

  */
__STATIC_INLINE void LL_MDU_ADC_SetChannel(uint32_t Channel)
{
  MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_ICHSLCT | MDU_ADCCFG_CHSLCT, Channel);
}

/**
  * @brief ADC Get Channel.
  * @retval ADC channel 
  *        @arg @ref ADC_CHANNEL_0
  *        @arg @ref ADC_CHANNEL_1
  *        @arg @ref ADC_CHANNEL_2
  *        @arg @ref ADC_CHANNEL_3
  *        @arg @ref ADC_CHANNEL_4
  *        @arg @ref ADC_CHANNEL_5
  *        @arg @ref ADC_CHANNEL_6
  *        @arg @ref ADC_CHANNEL_7
  *        @arg @ref ADC_CHANNEL_8
  *        @arg @ref ADC_CHANNEL_9
  *        @arg @ref ADC_CHANNEL_10
  *        @arg @ref ADC_CHANNEL_11
  *        @arg @ref ADC_CHANNEL_12
  *        @arg @ref ADC_CHANNEL_13
  *        @arg @ref ADC_CHANNEL_14
  *        @arg @ref ADC_CHANNEL_15 |
  *        @arg @ref ADC_CHANNEL_EXT
  *        @arg @ref ADC_CHANNEL_VBG
  *        @arg @ref ADC_CHANNEL_VTS
  *        @arg @ref ADC_CHANNEL_VBS
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetChannel(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_ICHSLCT | MDU_ADCCFG_CHSLCT));
}

/**
  * @brief ADC Set Channel source.
  * @param Source ADC source 
  *        @arg @ref LL_ADC_SRC_EXTERNAL
  *        @arg @ref LL_ADC_SRC_INTERNAL

  */
__STATIC_INLINE void LL_MDU_ADC_SetChannelSource(uint32_t Source)
{
  (MODIFY_REG((MDU->ADC_CFG), MDU_ADCCFG_ICHSLCT, Source));
}

/**
  * @brief ADC Get Channel source.
  * @retval ADC Source 
  *        @arg @ref LL_ADC_SRC_EXTERNAL
  *        @arg @ref LL_ADC_SRC_INTERNAL
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetChannelSource(void)
{
  return (uint32_t)(READ_BIT(MDU->ADC_CFG, MDU_ADCCFG_ICHSLCT));
}

/**
  * @brief  Function to get ADC EOS flag
  * @rmtoll MDU_ADC_RESULT      EOS               LL_MDU_ADC_GetEOC
  * @retval  Return value can be SET or RESET 
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetEOS(void)
{
  return (uint32_t)((READ_BIT(MDU->ADC_STATUS, MDU_ADCST_EOS)) ? SET : RESET);
}

/**
  * @brief  Function to get ADC EOC flag
  * @rmtoll MDU_ADC_RESULT      EOC               LL_MDU_ADC_GetEOC
  * @retval  Return value can be SET or RESET 
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetEOC(void)
{
  return (uint32_t)((READ_BIT(MDU->ADC_RESULTS, MDU_ADC_EOC)) ? SET : RESET);
}

/**
  * @brief  Function to ADC output data
  * @rmtoll MDU_ADC_STATUS      Output Data               LL_MDU_ADC_GetOutputData
  * @retval Return value can be ont between 0 to 0xFFF
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetOutputData(void)
{
  return (uint32_t)READ_BIT(MDU->ADC_RESULTS, MDU_ADC_OUTPUT_DATA);
}

/**
  * @brief  Function to configure ADC convert sequence
  * @rmtoll MDU_ADC_CTRL      GROUP_CH               LL_MDU_ADC_SetDataGroup
  * @param  Group This parameter can combine of the following values:
  *         @arg @ref LL_ADC_GROUP_CH_0
  *         @arg @ref LL_ADC_GROUP_CH_1
  *         @arg @ref LL_ADC_GROUP_CH_2
  *         @arg @ref LL_ADC_GROUP_CH_3
  *         @arg @ref LL_ADC_GROUP_CH_4
  *         @arg @ref LL_ADC_GROUP_CH_5
  *         @arg @ref LL_ADC_GROUP_CH_6
  *         @arg @ref LL_ADC_GROUP_CH_7
  *         @arg @ref LL_ADC_GROUP_CH_8
  *         @arg @ref LL_ADC_GROUP_CH_9
  *         @arg @ref LL_ADC_GROUP_CH_10
  *         @arg @ref LL_ADC_GROUP_CH_11
  *         @arg @ref LL_ADC_GROUP_CH_12
  *         @arg @ref LL_ADC_GROUP_CH_13
  *         @arg @ref LL_ADC_GROUP_CH_14
  *         @arg @ref LL_ADC_GROUP_CH_15

  */
__STATIC_INLINE void LL_MDU_ADC_SetDataGroup(uint32_t Group)
{
  MODIFY_REG(MDU->ADC_CTRL, MDU_ADCCTRL_GCHIND, Group);
}

/**
  * @brief  Function to configure ADC PGA sampling width
  * @rmtoll MDU_ADC_CTRL      PGA_WD               LL_MDU_ADC_SetPGASamplingWidth
  * @param  Width This parameter can one of between 0 to 15

  */
__STATIC_INLINE void LL_MDU_ADC_SetPGASamplingWidth(uint32_t Width)
{
  MODIFY_REG(MDU->ADC_CTRL, MDU_ADCCTRL_PGASMPW, (Width << MDU_ADCCTRL_PGASMPW_Pos));
}

/**
  * @brief  Function to reset ADC
  * @rmtoll MDU_ADC_CTRL      ADC_RST               LL_MDU_ADC_Reset

  */
__STATIC_INLINE void LL_MDU_ADC_Reset(void)
{
  CLEAR_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_RST);
}

/**
  * @brief  Function to release reset ADC
  * @rmtoll MDU_ADC_CTRL      ADC_RST               LL_MDU_ADC_Reset

  */
__STATIC_INLINE void LL_MDU_ADC_ReleaseReset(void)
{
  SET_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_RST);
}

/**
  * @brief  Function to configure ADC scan direct
  * @rmtoll MDU_ADC_CTRL      SCAN_DIR               LL_MDU_ADC_SetScanDirect
  * @param  Dir This parameter can one of the following values:
  *         @arg @ref LL_ADC_CONVERT_INCREMENT
  *         @arg @ref LL_ADC_CONVERT_DECREMENT

  */
__STATIC_INLINE void LL_MDU_ADC_SetScanDirect(uint32_t Dir)
{
  MODIFY_REG(MDU->ADC_CTRL, MDU_ADCCTRL_CH_MODE, Dir);
}

/**
  * @brief  Function to configure ADC operation mode
  * @rmtoll MDU_ADC_CTRL      ADC_MODE               LL_MDU_ADC_SetConvertMode
  * @param  Mode This parameter can one of the following values:
  *         @arg @ref LL_ADC_CONVERT_SINGLECH_SINGLE
  *         @arg @ref LL_ADC_CONVERT_SINGLECH_CONTINUOUS
  *         @arg @ref LL_ADC_CONVERT_MULTCH_SINGLE

  */
__STATIC_INLINE void LL_MDU_ADC_SetConvertMode(uint32_t Mode)
{
  MODIFY_REG(MDU->ADC_CTRL, MDU_ADCCTRL_CONV_MODE, Mode);
}

/**
  * @brief  Function to ADC start
  * @rmtoll MDU_ADC_CTRL      ADC_START               LL_MDU_ADC_Start

  */
__STATIC_INLINE void LL_MDU_ADC_Start(void)
{
  SET_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_SEQ_STRT);
}

/**
  * @brief  Function to ADC stop
  * @rmtoll MDU_ADC_CTRL      ADC_START               LL_MDU_ADC_Stop

  */
__STATIC_INLINE void LL_MDU_ADC_Stop(void)
{
  CLEAR_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_SEQ_STRT);
}

/**
  * @brief  Function to ADC force software trigger to high
  * @rmtoll MDU_ADC_CTRL      ADC_SW_TRG               LL_MDU_ADC_SoftwareTriggerForceHigh

  */
__STATIC_INLINE void LL_MDU_ADC_SoftwareTriggerForceHigh(void)
{
  SET_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_SWTRG);
}

/**
  * @brief  Function to ADC force software trigger to low
  * @rmtoll MDU_ADC_CTRL      ADC_SW_TRG               LL_MDU_ADC_SoftwareTriggerForceLow

  */
__STATIC_INLINE void LL_MDU_ADC_SoftwareTriggerForceLow(void)
{
  CLEAR_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_SWTRG);
}

/**
  * @brief  Function to configure ADC trigger edge
  * @rmtoll MDU_ADC_CTRL      ADC_SW_TRG               LL_MDU_ADC_SetTriggerEdge
  * @param  Edge This parameter can one of the following values:
  *         @arg @ref LL_ADC_TRIGGEREDGE_NONE
  *         @arg @ref LL_ADC_TRIGGEREDGE_RISING
  *         @arg @ref LL_ADC_TRIGGEREDGE_FALLING
  *         @arg @ref LL_ADC_TRIGGEREDGE_BOTH

  */
__STATIC_INLINE void LL_MDU_ADC_SetTriggerEdge(uint32_t Edge)
{
  MODIFY_REG(MDU->ADC_CTRL, MDU_ADCCTRL_FALLEDGE|MDU_ADCCTRL_RISEEDGE, Edge);
}

/**
  * @brief  Function to configure ADC trigger source
  * @rmtoll MDU_ADC_CTRL      ADC_SW_TRG               LL_MDU_ADC_SetTriggerEdge
  * @param  Source This parameter can one of the following values:
  *         @arg @ref LL_ADC_TRGSRC_SOFTWARE
  *         @arg @ref LL_ADC_TRGSRC_TIMA_CH4
  *         @arg @ref LL_ADC_TRGSRC_TIMA_TRGO2
  *         @arg @ref LL_ADC_TRGSRC_TIMG_TRGO
  *         @arg @ref LL_ADC_TRGSRC_TIMB11
  *         @arg @ref LL_ADC_TRGSRC_TIMB12
  *         @arg @ref LL_ADC_TRGSRC_TIMB13
  *         @arg @ref LL_ADC_TRGSRC_TIMB14
  *         @arg @ref LL_ADC_TRGSRC_TIMB21
  *         @arg @ref LL_ADC_TRGSRC_TIMB22
  *         @arg @ref LL_ADC_TRGSRC_TIMB23
  *         @arg @ref LL_ADC_TRGSRC_TIMB24

  */
__STATIC_INLINE void LL_MDU_ADC_SetTriggerSource(uint32_t Source)
{
  MODIFY_REG(MDU->ADC_CTRL, MDU_ADCCTRL_TRGISRC, Source);
}

/**
  * @brief  Function to get ADC sequence conversion result
  * @rmtoll MDU_ADC_RESULT_CHx      CHx_OUT_DATA               LL_MDU_ADC_GetGroupResult
  * @param  Channel This parameter can one of between 0 to 15
  * @retval Return value can be ont between 0 to 0x7FF
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetGroupResult(uint32_t Channel)
{
  return (uint32_t)*((volatile uint32_t*)&(MDU->ADC_RESULTS_CH0)+Channel);
}

/**
  * @brief  Function to Check ADC is enabled
  * @rmtoll ADC_CTRL      MDU_ADCCTRL_SEQ_STRT               LL_MDU_ADC_IsEnabled\n
  * @rmtoll ADC_CTRL      MDU_ADCCTRL_RST                    LL_MDU_ADC_IsEnabled
  * @retval Return value can be ont SET or RESET
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_IsEnabled(void)
{
  return (uint32_t)(((READ_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_RST)) && (READ_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_SEQ_STRT))) ? SET : RESET);
}

/**
  * @brief  Function to Set ADC enable
  * @rmtoll ADC_CTRL      MDU_ADCCTRL_SEQ_STRT               LL_MDU_ADC_Enable\n
  * @rmtoll ADC_CTRL      MDU_ADCCTRL_RST                    LL_MDU_ADC_Enable

  */
__STATIC_INLINE void LL_MDU_ADC_Enable(void)
{
  SET_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_SEQ_STRT);
  SET_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_RST);
}
#endif /* defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW) */

#if defined(XT32H0xxB)
/**
  * @brief  Function to Set ADC injection group EOS DMA enable
  * @rmtoll DMA_CFG      MDU_ADCDMACFG_INJ_DMA_EN               LL_MDU_ADC_InjectionGroupDMAEnable\n

  */
__STATIC_INLINE void LL_MDU_ADC_InjectionGroupDMAEnable(void)
{
  SET_BIT(MDU->DMA_CFG, MDU_ADCDMACFG_INJ_DMA_EN);
}

/**
  * @brief  Function to Set ADC injection group EOS DMA Disable
  * @rmtoll DMA_CFG      MDU_ADCDMACFG_INJ_DMA_EN               LL_MDU_ADC_InjectionGroupDMADisable\n

  */
__STATIC_INLINE void LL_MDU_ADC_InjectionGroupDMADisable(void)
{
  CLEAR_BIT(MDU->DMA_CFG, MDU_ADCDMACFG_INJ_DMA_EN);
}

/**
  * @brief  Function to Set ADC regular group EOS DMA enable
  * @rmtoll DMA_CFG      MDU_ADCDMACFG_REG_DMA_EN               LL_MDU_ADC_RegularGroupDMAEnable\n

  */
__STATIC_INLINE void LL_MDU_ADC_RegularGroupDMAEnable(void)
{
  SET_BIT(MDU->DMA_CFG, MDU_ADCDMACFG_REG_DMA_EN);
}

/**
  * @brief  Function to Set ADC regular group EOS DMA Disable
  * @rmtoll DMA_CFG      MDU_ADCDMACFG_REG_DMA_EN               LL_MDU_ADC_RegularGroupDMADisable\n

  */
__STATIC_INLINE void LL_MDU_ADC_RegularGroupDMADisable(void)
{
  CLEAR_BIT(MDU->DMA_CFG, MDU_ADCDMACFG_REG_DMA_EN);
}

/**
  * @brief  Function to Set ADC discharge cycles
  * @rmtoll MDU_CFG      MDU_MDUCFG_DSCH_PHS               LL_MDU_ADC_SetDischargeCycles\n
  * @param  Cycles the cycles of the discharge phase 
  *         This value is one between 0 to 0xFF

  */
__STATIC_INLINE void LL_MDU_ADC_SetDischargeCycles(uint32_t Cycles)
{
  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_DSCH_PHS, Cycles);
}

/**
  * @brief  Function to Set ADC discharge enable
  * @rmtoll MDU_CFG      MDU_MDUCFG_DSCH_EN               LL_MDU_ADC_DischargeEnable\n

  */
__STATIC_INLINE void LL_MDU_ADC_DischargeEnable(void)
{
  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_DSCH_EN);
}

/**
  * @brief  Function to Set ADC discharge disable
  * @rmtoll MDU_CFG      MDU_MDUCFG_DSCH_EN               LL_MDU_ADC_DischargeDisable\n

  */
__STATIC_INLINE void LL_MDU_ADC_DischargeDisable(void)
{
  CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_DSCH_EN);
}

/**
  * @brief  Function to Set ADC injection group enable
  * @rmtoll MDU_CFG      MDU_MDUCFG_INJ_GRP_EN               LL_MDU_ADC_InjectionGroupEnable\n

  */
__STATIC_INLINE void LL_MDU_ADC_InjectionGroupEnable(void)
{
  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_INJ_GRP_EN);
}

/**
  * @brief  Function to Set ADC injection group disable
  * @rmtoll MDU_CFG      MDU_MDUCFG_INJ_GRP_EN               LL_MDU_ADC_InjectionGroupDisable\n

  */
__STATIC_INLINE void LL_MDU_ADC_InjectionGroupDisable(void)
{
  CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_INJ_GRP_EN);
}

/**
  * @brief  Function to Set ADC regular group enable
  * @rmtoll MDU_CFG      MDU_MDUCFG_REG_GRP_EN               LL_MDU_ADC_RegularGroupEnable\n

  */
__STATIC_INLINE void LL_MDU_ADC_RegularGroupEnable(void)
{
  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_REG_GRP_EN);
}

/**
  * @brief  Function to Set ADC regular group disable
  * @rmtoll MDU_CFG      MDU_MDUCFG_REG_GRP_EN               LL_MDU_ADC_RegularGroupDisable\n

  */
__STATIC_INLINE void LL_MDU_ADC_RegularGroupDisable(void)
{
  CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_REG_GRP_EN);
}

/**
  * @brief  Function to Set ADC injection channels pre-sampling in same mode
  * @rmtoll MDU_CFG      MDU_MDUCFG_SEL_PGA_CTRL               LL_MDU_ADC_InjectionChannelPresamplingSame\n

  */
__STATIC_INLINE void LL_MDU_ADC_InjectionChannelPresamplingSame(void)
{
  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_SEL_PGA_CTRL);
}

/**
  * @brief  Function to Set ADC injection channels pre-sampling in individual mode
  * @rmtoll MDU_CFG      MDU_MDUCFG_SEL_PGA_CTRL               LL_MDU_ADC_InjectionChannelPresamplingIndividual\n

  */
__STATIC_INLINE void LL_MDU_ADC_InjectionChannelPresamplingIndividual(void)
{
  CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_SEL_PGA_CTRL);
}

/**
  * @brief  Function to Set ADC Start
  * @rmtoll MDU_CFG      MDU_MDUCFG_ADC_START_EN               LL_MDU_ADC_Start\n

  */
__STATIC_INLINE void LL_MDU_ADC_Start(void)
{
  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_START_EN);
}

/**
  * @brief  Function to Set ADC Stop
  * @rmtoll MDU_CFG      MDU_MDUCFG_ADC_START_EN               LL_MDU_ADC_Stop\n

  */
__STATIC_INLINE void LL_MDU_ADC_Stop(void)
{
  CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_START_EN);
}

/**
  * @brief  Function to Set ADC reset
  * @rmtoll MDU_CFG      MDU_MDUCFG_ADC_RST               LL_MDU_ADC_Reset\n

  */
__STATIC_INLINE void LL_MDU_ADC_Reset(void)
{
  CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_RST);
}

/**
  * @brief  Function to release ADC reset
  * @rmtoll MDU_CFG      MDU_MDUCFG_ADC_RST               LL_MDU_ADC_ReleaseReset\n

  */
__STATIC_INLINE void LL_MDU_ADC_ReleaseReset(void)
{
  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_RST);
}

/**
  * @brief  Function to set ADC soft trigger to 1
  * @rmtoll MDU_CFG      MDU_MDUCFG_ADC_SFTRG               LL_MDU_ADC_SoftTriggerForceHigh\n

  */
__STATIC_INLINE void LL_MDU_ADC_SoftTriggerForceHigh(void)
{
  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_SFTRG);
}

/**
  * @brief  Function to release ADC soft trigger to 0
  * @rmtoll MDU_CFG      MDU_MDUCFG_ADC_SFTRG               LL_MDU_ADC_SoftTriggerForceLow\n

  */
__STATIC_INLINE void LL_MDU_ADC_SoftTriggerForceLow(void)
{
  CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_SFTRG);
}

/**
  * @brief  Function to set ADC enable
  * @rmtoll MDU_CFG      MDU_MDUCFG_ADC_EN               LL_MDU_ADC_Enable\n

  */
__STATIC_INLINE void LL_MDU_ADC_Enable(void)
{
  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_EN);
}

/**
  * @brief  Function to set ADC disable
  * @rmtoll MDU_CFG      MDU_MDUCFG_ADC_EN               LL_MDU_ADC_Disable\n

  */
__STATIC_INLINE void LL_MDU_ADC_Disable(void)
{
  CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_EN);
}

/**
  * @brief  Function to set ADC cycles of the PGA presampling in regular group conversion
  * @rmtoll MDU_CFG      MDU_MDUCFG_SYNC_PHS               LL_MDU_ADC_SetPresampleingCycles\n
  * @param  Cycles the cycles of the PGA presampling
  *         This value is the one between 0 to 0xFF

  */
__STATIC_INLINE void LL_MDU_ADC_SetPresampleingCycles(uint32_t Cycles)
{
  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_SYNC_PHS, (Cycles << MDU_MDUCFG_SYNC_PHS_Pos));
}

/**
  * @brief  Function to set ADC reset pulse width
  * @rmtoll MDU_CFG      MDU_MDUCFG_SYNC_PHS               LL_MDU_ADC_SetResetPulseWidth\n
  * @param  Cycles the cycles of the PGA presampling
  *         This value is the one between 1 to 4

  */
__STATIC_INLINE void LL_MDU_ADC_SetResetPulseWidth(uint32_t Cycles)
{
  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_RSTB_CYC, ((Cycles-1) << MDU_MDUCFG_RSTB_CYC_Pos));
}

/**
  * @brief  Function to set ADC injection interrupt polarity
  * @rmtoll MDU_CFG      MDU_MDUCFG_INJ_INT_POL               LL_MDU_ADC_SetInjectionInterruptPolarity\n
  * @param  Polarity injection interrupt polarity
  *         This value is the one of the following values
  *         @arg @ref LL_ADC_INJGRP_INT_POL_HIGH
  *         @arg @ref LL_ADC_INJGRP_INT_POL_LOW

  */
__STATIC_INLINE void LL_MDU_ADC_SetInjectionInterruptPolarity(uint32_t Polarity)
{
  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_INJ_INT_POL, Polarity);
}

/**
  * @brief  Function to set ADC regular interrupt polarity
  * @rmtoll MDU_CFG      MDU_MDUCFG_REG_INT_POL               LL_MDU_ADC_SetRegularInterruptPolarity\n
  * @param  Polarity regular interrupt polarity
  *         This value is the one of the following values
  *         @arg @ref LL_ADC_REGGRP_INT_POL_HIGH
  *         @arg @ref LL_ADC_REGGRP_INT_POL_LOW

  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularInterruptPolarity(uint32_t Polarity)
{
  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_REG_INT_POL, Polarity);
}

/**
  * @brief  Function to set ADC interrupts enable
  * @rmtoll MDU_CFG      MDU_MDUCFG_INJ_EOC_EN               LL_MDU_ADC_SetInterruptsEnable
  * @rmtoll MDU_CFG      MDU_MDUCFG_INJ_EOS_EN               LL_MDU_ADC_SetInterruptsEnable
  * @rmtoll MDU_CFG      MDU_MDUCFG_REG_EOC_EN               LL_MDU_ADC_SetInterruptsEnable
  * @rmtoll MDU_CFG      MDU_MDUCFG_REG_EOS_EN               LL_MDU_ADC_SetInterruptsEnable\n
  * @param  Interrupts interrupts
  *         This value is combined of the following values
  *         @arg @ref LL_ADC_INT_ENABLE_INJGRP_EOC
  *         @arg @ref LL_ADC_INT_ENABLE_INJGRP_EOS
  *         @arg @ref LL_ADC_INT_ENABLE_REGGRP_EOC
  *         @arg @ref LL_ADC_INT_ENABLE_REGGRP_EOS

  */
__STATIC_INLINE void LL_MDU_ADC_SetInterruptsEnable(uint32_t Interrupts)
{
  SET_BIT(MDU->MDU_CFG,Interrupts);
}

/**
  * @brief  Function to set ADC interrupts disable
  * @rmtoll MDU_CFG      MDU_MDUCFG_INJ_EOC_EN               LL_MDU_ADC_SetInterruptsDisable
  * @rmtoll MDU_CFG      MDU_MDUCFG_INJ_EOS_EN               LL_MDU_ADC_SetInterruptsDisable
  * @rmtoll MDU_CFG      MDU_MDUCFG_REG_EOC_EN               LL_MDU_ADC_SetInterruptsDisable
  * @rmtoll MDU_CFG      MDU_MDUCFG_REG_EOS_EN               LL_MDU_ADC_SetInterruptsDisable\n
  * @param  Interrupts interrupts
  *         This value is combined of the following values
  *         @arg @ref LL_ADC_INT_ENABLE_INJGRP_EOC
  *         @arg @ref LL_ADC_INT_ENABLE_INJGRP_EOS
  *         @arg @ref LL_ADC_INT_ENABLE_REGGRP_EOC
  *         @arg @ref LL_ADC_INT_ENABLE_REGGRP_EOS

  */
__STATIC_INLINE void LL_MDU_ADC_SetInterruptsDisable(uint32_t Interrupts)
{
  CLEAR_BIT(MDU->MDU_CFG,Interrupts);
}

/**
  * @brief  Function to set ADC injection group trigger sources
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_TRGSRC_1               LL_MDU_ADC_SetInjectionGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_TRGSRC_2               LL_MDU_ADC_SetInjectionGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_TRGSRC_3               LL_MDU_ADC_SetInjectionGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_TRGSRC_4               LL_MDU_ADC_SetInjectionGroupTriggerSource\n
  * @param  GroupIndex injection group index
  *         This value is onr of the following values
  *         @arg @ref LL_ADC_INJGRP_1
  *         @arg @ref LL_ADC_INJGRP_2
  *         @arg @ref LL_ADC_INJGRP_3
  *         @arg @ref LL_ADC_INJGRP_4
  * @param  TriggerSource trigger source
  *         This value is one of the following values
  *         @arg @ref LL_ADC_TRGSRC_NONE             (0)
  *         @arg @ref LL_ADC_TRGSRC_TIMA1_CH4        (1)
  *         @arg @ref LL_ADC_TRGSRC_TIMA1_TRGO2      (2)
  *         @arg @ref LL_ADC_TRGSRC_TIMA2_CH4        (3)
  *         @arg @ref LL_ADC_TRGSRC_TIMA2_TRGO2      (4)
  *         @arg @ref LL_ADC_TRGSRC_TIMG1_CH4        (5)
  *         @arg @ref LL_ADC_TRGSRC_TIMG1_TRGO2      (6)
  *         @arg @ref LL_ADC_TRGSRC_TIMG2_CH4        (7)
  *         @arg @ref LL_ADC_TRGSRC_TIMG2_TRGO2      (8)
  *         @arg @ref LL_ADC_TRGSRC_TIMG3_CH4        (9)
  *         @arg @ref LL_ADC_TRGSRC_TIMG3_TRGO2      (10)
  *         @arg @ref LL_ADC_TRGSRC_TIMG4_CH4        (11)
  *         @arg @ref LL_ADC_TRGSRC_TIMG4_TRGO2      (12)
  *         @arg @ref LL_ADC_TRGSRC_TIMB11           (13)
  *         @arg @ref LL_ADC_TRGSRC_EXTERNAL         (14)
  *         @arg @ref LL_ADC_TRGSRC_SOFTWARE         (15)

  */
__STATIC_INLINE void LL_MDU_ADC_SetInjectionGroupTriggerSource(uint32_t GroupIndex, uint32_t TriggerSource)
{
  MODIFY_REG(MDU->INJGRP_TRG, (MDU_INJGRP_TRG_INJGRP_TRGSRC_1 << (GroupIndex << 2)), (TriggerSource << (GroupIndex << 2)));
}

/**
  * @brief  Function to set ADC injection group trigger mode
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_TRGCFG_1               LL_MDU_ADC_SetInterruptsDisable
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_TRGCFG_2               LL_MDU_ADC_SetInterruptsDisable
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_TRGCFG_3               LL_MDU_ADC_SetInterruptsDisable
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_TRGCFG_4               LL_MDU_ADC_SetInterruptsDisable\n
  * @param  GroupIndex injection group index
  *         This value is onr of the following values
  *         @arg @ref LL_ADC_INJGRP_1
  *         @arg @ref LL_ADC_INJGRP_2
  *         @arg @ref LL_ADC_INJGRP_3
  *         @arg @ref LL_ADC_INJGRP_4
  * @param  TriggerMode trigger mode
  *         This value is one of the following values
  *         @arg @ref LL_ADC_TRIGGEREDGE_NONE
  *         @arg @ref LL_ADC_TRIGGEREDGE_RISING 
  *         @arg @ref LL_ADC_TRIGGEREDGE_FALLING
  *         @arg @ref LL_ADC_TRIGGEREDGE_BOTH   

  */
__STATIC_INLINE void LL_MDU_ADC_SetInjectionGroupTriggerMode(uint32_t GroupIndex, uint32_t TriggerMode)
{
  MODIFY_REG(MDU->INJGRP_TRG, (MDU_INJGRP_TRG_INJGRP_TRGCFG_1 << (GroupIndex << 1)), ((TriggerMode << MDU_INJGRP_TRG_INJGRP_TRGCFG_1_Pos) << (GroupIndex << 1)));
}

/**
  * @brief  Function to set ADC injection group number
  * @rmtoll MDU_CFG      MDU_INJGRP_TRG_INJGRP_SGRP_NUM               LL_MDU_ADC_SetInjectionGroupNumber\n
  * @param  GroupNumber injection group number
  *         This value is onr of the following values
  *         @arg @ref LL_ADC_INJGRP_NUMBER_1
  *         @arg @ref LL_ADC_INJGRP_NUMBER_2
  *         @arg @ref LL_ADC_INJGRP_NUMBER_3
  *         @arg @ref LL_ADC_INJGRP_NUMBER_4

  */
__STATIC_INLINE void LL_MDU_ADC_SetInjectionGroupNumber(uint32_t GroupNumber)
{
  MODIFY_REG(MDU->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_SGRP_NUM, GroupNumber);
}

/**
  * @brief  Function to set ADC regular group trigger sources
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_REGGRP_TRGSRC_1               LL_MDU_ADC_SetRegularGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_REGGRP_TRGSRC_2               LL_MDU_ADC_SetRegularGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_REGGRP_TRGSRC_3               LL_MDU_ADC_SetRegularGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_REGGRP_TRGSRC_4               LL_MDU_ADC_SetRegularGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_REGGRP_TRGSRC_5               LL_MDU_ADC_SetRegularGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_REGGRP_TRGSRC_6               LL_MDU_ADC_SetRegularGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_REGGRP_TRGSRC_7               LL_MDU_ADC_SetRegularGroupTriggerSource
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_REGGRP_TRGSRC_8               LL_MDU_ADC_SetRegularGroupTriggerSource\n
  * @param  GroupIndex regular group index
  *         This value is onr of the following values
  *         @arg @ref LL_ADC_REGGRP_1
  *         @arg @ref LL_ADC_REGGRP_2
  *         @arg @ref LL_ADC_REGGRP_3
  *         @arg @ref LL_ADC_REGGRP_4
  *         @arg @ref LL_ADC_REGGRP_5
  *         @arg @ref LL_ADC_REGGRP_6
  *         @arg @ref LL_ADC_REGGRP_7
  *         @arg @ref LL_ADC_REGGRP_8
  * @param  TriggerSource trigger source
  *         This value is one of the following values
  *         @arg @ref LL_ADC_TRGSRC_NONE             (0)
  *         @arg @ref LL_ADC_TRGSRC_TIMA1_CH4        (1)
  *         @arg @ref LL_ADC_TRGSRC_TIMA1_TRGO2      (2)
  *         @arg @ref LL_ADC_TRGSRC_TIMA2_CH4        (3)
  *         @arg @ref LL_ADC_TRGSRC_TIMA2_TRGO2      (4)
  *         @arg @ref LL_ADC_TRGSRC_TIMG1_CH4        (5)
  *         @arg @ref LL_ADC_TRGSRC_TIMG1_TRGO2      (6)
  *         @arg @ref LL_ADC_TRGSRC_TIMG2_CH4        (7)
  *         @arg @ref LL_ADC_TRGSRC_TIMG2_TRGO2      (8)
  *         @arg @ref LL_ADC_TRGSRC_TIMG3_CH4        (9)
  *         @arg @ref LL_ADC_TRGSRC_TIMG3_TRGO2      (10)
  *         @arg @ref LL_ADC_TRGSRC_TIMG4_CH4        (11)
  *         @arg @ref LL_ADC_TRGSRC_TIMG4_TRGO2      (12)
  *         @arg @ref LL_ADC_TRGSRC_TIMB11           (13)
  *         @arg @ref LL_ADC_TRGSRC_EXTERNAL         (14)
  *         @arg @ref LL_ADC_TRGSRC_SOFTWARE         (15)

  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularGroupTriggerSource(uint32_t GroupIndex, uint32_t TriggerSource)
{
  MODIFY_REG(MDU->REGGRP_TRG, (MDU_REGGRP_TRG_REGGRP_TRGSRC_1 << (GroupIndex << 2)), (TriggerSource << (GroupIndex << 2)));
}

/**
  * @brief  Function to set ADC regular group number
  * @rmtoll MDU_CFG      MDU_REGGRP_TRG_INJGRP_SGRP_NUM               LL_MDU_ADC_SetRegularGroupNumber\n
  * @param  GroupNumber regular group number
  *         This value is onr of the following values
  *         @arg @ref LL_ADC_REGGRP_NUMBER_1
  *         @arg @ref LL_ADC_REGGRP_NUMBER_2
  *         @arg @ref LL_ADC_REGGRP_NUMBER_3
  *         @arg @ref LL_ADC_REGGRP_NUMBER_4
  *         @arg @ref LL_ADC_REGGRP_NUMBER_5
  *         @arg @ref LL_ADC_REGGRP_NUMBER_6
  *         @arg @ref LL_ADC_REGGRP_NUMBER_7
  *         @arg @ref LL_ADC_REGGRP_NUMBER_8

  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularGroupNumber(uint32_t GroupNumber)
{
  MODIFY_REG(MDU->REGGRP_TRGCFG, MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM, GroupNumber);
}

/**
  * @brief  Function to set ADC regular group trigger mode
  * @rmtoll MDU_CFG      MDU_REGGRP_TRGCFG_REGGRP_CFG_1               LL_MDU_ADC_SetRegularGroupTriggerMode
  * @rmtoll MDU_CFG      MDU_REGGRP_TRGCFG_REGGRP_CFG_2               LL_MDU_ADC_SetRegularGroupTriggerMode
  * @rmtoll MDU_CFG      MDU_REGGRP_TRGCFG_REGGRP_CFG_3               LL_MDU_ADC_SetRegularGroupTriggerMode
  * @rmtoll MDU_CFG      MDU_REGGRP_TRGCFG_REGGRP_CFG_4               LL_MDU_ADC_SetRegularGroupTriggerMode
  * @rmtoll MDU_CFG      MDU_REGGRP_TRGCFG_REGGRP_CFG_5               LL_MDU_ADC_SetRegularGroupTriggerMode
  * @rmtoll MDU_CFG      MDU_REGGRP_TRGCFG_REGGRP_CFG_6               LL_MDU_ADC_SetRegularGroupTriggerMode
  * @rmtoll MDU_CFG      MDU_REGGRP_TRGCFG_REGGRP_CFG_7               LL_MDU_ADC_SetRegularGroupTriggerMode
  * @rmtoll MDU_CFG      MDU_REGGRP_TRGCFG_REGGRP_CFG_8               LL_MDU_ADC_SetRegularGroupTriggerMode\n
  * @param  GroupIndex injection group index
  *         This value is onr of the following values
  *         @arg @ref LL_ADC_REGGRP_1
  *         @arg @ref LL_ADC_REGGRP_2
  *         @arg @ref LL_ADC_REGGRP_3
  *         @arg @ref LL_ADC_REGGRP_4
  *         @arg @ref LL_ADC_REGGRP_5
  *         @arg @ref LL_ADC_REGGRP_6
  *         @arg @ref LL_ADC_REGGRP_7
  *         @arg @ref LL_ADC_REGGRP_8
  * @param  TriggerMode trigger mode
  *         This value is one of the following values
  *         @arg @ref LL_ADC_TRIGGEREDGE_NONE
  *         @arg @ref LL_ADC_TRIGGEREDGE_RISING 
  *         @arg @ref LL_ADC_TRIGGEREDGE_FALLING
  *         @arg @ref LL_ADC_TRIGGEREDGE_BOTH   

  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularGroupTriggerMode(uint32_t GroupIndex, uint32_t TriggerMode)
{
  MODIFY_REG(MDU->REGGRP_TRGCFG, (MDU_REGGRP_TRGCFG_REGGRP_CFG_1 << (GroupIndex << 1)), ((TriggerMode << MDU_REGGRP_TRGCFG_REGGRP_CFG_1_Pos) << (GroupIndex << 1)));
}

/**
  * @brief  Function to set ADC regular group continuous scan start
  * @rmtoll REGGRP_TRGCFG      MDU_REGGRP_TRGCFG_REGGRP_CS_START               LL_MDU_ADC_SetRegularGroupContinuousScanStart\n

  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularGroupContinuousScanStart(void)
{
  SET_BIT(MDU->REGGRP_TRGCFG, MDU_REGGRP_TRGCFG_REGGRP_CS_START);
}

/**
  * @brief  Function to set ADC regular group continuous scan stop
  * @rmtoll REGGRP_TRGCFG      MDU_REGGRP_TRGCFG_REGGRP_CS_START               LL_MDU_ADC_SetRegularGroupContinuousScanStop\n

  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularGroupContinuousScanStop(void)
{
  CLEAR_BIT(MDU->REGGRP_TRGCFG, MDU_REGGRP_TRGCFG_REGGRP_CS_START);
}

/**
  * @brief  Function to set ADC regular group scan mode
  * @rmtoll REGGRP_TRGCFG      MDU_REGGRP_TRGCFG_REGGRP_OPMODE               LL_MDU_ADC_SetRegularGroupScanMode\n
  * @param  Mode regular group scan mode
  *         This value is one of the following values
  *         @arg @ref LL_ADC_CONVERT_SINGLESCAN
  *         @arg @ref LL_ADC_CONVERT_CONTINUOUSSCAN
  *         @arg @ref LL_ADC_CONVERT_DISCONTINUOUSSCAN

  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularGroupScanMode(uint32_t Mode)
{
  MODIFY_REG(MDU->REGGRP_TRGCFG, MDU_REGGRP_TRGCFG_REGGRP_OPMODE, Mode);
}

/**
  * @brief  Function to set ADC injection channel to injection group
  * @rmtoll INJGRP_CHCR_1      MDU_INJGRP_CHCR_GRP_ID_1               LL_MDU_ADC_SetInjectionChanneltoGroup
  * @rmtoll INJGRP_CHCR_2      MDU_INJGRP_CHCR_GRP_ID_2               LL_MDU_ADC_SetInjectionChanneltoGroup
  * @rmtoll INJGRP_CHCR_3      MDU_INJGRP_CHCR_GRP_ID_3               LL_MDU_ADC_SetInjectionChanneltoGroup
  * @rmtoll INJGRP_CHCR_4      MDU_INJGRP_CHCR_GRP_ID_4               LL_MDU_ADC_SetInjectionChanneltoGroup\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  * @param  GroupId injection group 
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJGRP_1
  *         @arg @ref LL_ADC_INJGRP_2
  *         @arg @ref LL_ADC_INJGRP_3
  *         @arg @ref LL_ADC_INJGRP_4

  */
__STATIC_INLINE void LL_MDU_ADC_SetInjectionChanneltoGroup(uint32_t ChannelIndex, uint32_t GroupIndex)
{
  switch(ChannelIndex)
  {
    case LL_ADC_INJCH_1:
      MODIFY_REG(MDU->INJGRP_CHCR_1, MDU_INJGRP_CHCR_GRP_ID_1, GroupIndex+1);
      break;
    case LL_ADC_INJCH_2:
      MODIFY_REG(MDU->INJGRP_CHCR_2, MDU_INJGRP_CHCR_GRP_ID_2, GroupIndex+1);
      break;
    case LL_ADC_INJCH_3:
      MODIFY_REG(MDU->INJGRP_CHCR_3, MDU_INJGRP_CHCR_GRP_ID_3, GroupIndex+1);
      break;
    case LL_ADC_INJCH_4:
      MODIFY_REG(MDU->INJGRP_CHCR_4, MDU_INJGRP_CHCR_GRP_ID_4, GroupIndex+1);
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to set ADC channel to injection channel
  * @rmtoll INJGRP_CHCR_1      MDU_INJGRP_CHCR_ADCCH_ID_1               LL_MDU_ADC_SetADCChanneltoInjectionChannel
  * @rmtoll INJGRP_CHCR_2      MDU_INJGRP_CHCR_ADCCH_ID_2               LL_MDU_ADC_SetADCChanneltoInjectionChannel
  * @rmtoll INJGRP_CHCR_3      MDU_INJGRP_CHCR_ADCCH_ID_3               LL_MDU_ADC_SetADCChanneltoInjectionChannel
  * @rmtoll INJGRP_CHCR_4      MDU_INJGRP_CHCR_ADCCH_ID_4               LL_MDU_ADC_SetADCChanneltoInjectionChannel\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  * @param  AdcChannelIndex ADC channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_CHANNEL_1                              
  *         @arg @ref LL_ADC_CHANNEL_2                              
  *         @arg @ref LL_ADC_CHANNEL_3                              
  *         @arg @ref LL_ADC_CHANNEL_4                              
  *         @arg @ref LL_ADC_CHANNEL_5                              
  *         @arg @ref LL_ADC_CHANNEL_6                              
  *         @arg @ref LL_ADC_CHANNEL_7                              
  *         @arg @ref LL_ADC_CHANNEL_8                              
  *         @arg @ref LL_ADC_CHANNEL_9                              
  *         @arg @ref LL_ADC_CHANNEL_10                             
  *         @arg @ref LL_ADC_CHANNEL_11                             
  *         @arg @ref LL_ADC_CHANNEL_12                             
  *         @arg @ref LL_ADC_CHANNEL_13                             
  *         @arg @ref LL_ADC_CHANNEL_14                             
  *         @arg @ref LL_ADC_CHANNEL_15                             
  *         @arg @ref LL_ADC_CHANNEL_16                             
  *         @arg @ref LL_ADC_CHANNEL_17                             
  *         @arg @ref LL_ADC_CHANNEL_18                             
  *         @arg @ref LL_ADC_CHANNEL_19                             
  *         @arg @ref LL_ADC_CHANNEL_20                             
  *         @arg @ref LL_ADC_CHANNEL_21                             
  *         @arg @ref LL_ADC_CHANNEL_22                             
  *         @arg @ref LL_ADC_CHANNEL_23                             
  *         @arg @ref LL_ADC_CHANNEL_24                             
  *         @arg @ref LL_ADC_CHANNEL_25                             
  *         @arg @ref LL_ADC_CHANNEL_26                             
  *         @arg @ref LL_ADC_CHANNEL_27                             
  *         @arg @ref LL_ADC_CHANNEL_28                             
  *         @arg @ref LL_ADC_CHANNEL_29                             
  *         @arg @ref LL_ADC_CHANNEL_30                             
  *         @arg @ref LL_ADC_CHANNEL_31                             
  *         @arg @ref LL_ADC_CHANNEL_32                             
  *         @arg @ref LL_ADC_CHANNEL_33                             
  *         @arg @ref LL_ADC_CHANNEL_34                             
  *         @arg @ref LL_ADC_CHANNEL_35                             
  *         @arg @ref LL_ADC_CHANNEL_36                             
  *         @arg @ref LL_ADC_CHANNEL_37                             
  *         @arg @ref LL_ADC_CHANNEL_38                             
  *         @arg @ref LL_ADC_CHANNEL_39                             
  *         @arg @ref LL_ADC_CHANNEL_40                             
  *         @arg @ref LL_ADC_CHANNEL_41                             
  *         @arg @ref LL_ADC_CHANNEL_42                             
  *         @arg @ref LL_ADC_CHANNEL_43                             
  *         @arg @ref LL_ADC_CHANNEL_44                             
  *         @arg @ref LL_ADC_CHANNEL_45                             
  *         @arg @ref LL_ADC_CHANNEL_46                             
  *         @arg @ref LL_ADC_CHANNEL_47                             
  *         @arg @ref LL_ADC_CHANNEL_48                             
  *         @arg @ref LL_ADC_CHANNEL_49                             
  *         @arg @ref LL_ADC_CHANNEL_50                             
  *         @arg @ref LL_ADC_CHANNEL_51                             
  *         @arg @ref LL_ADC_CHANNEL_52                             
  *         @arg @ref LL_ADC_CHANNEL_53                              
  *         @arg @ref LL_ADC_CHANNEL_VBG                            
  *         @arg @ref LL_ADC_CHANNEL_VTS                            
  *         @arg @ref LL_ADC_CHANNEL_VBS                            
  *         @arg @ref LL_ADC_CHANNEL_P2AVDD                         
  *         @arg @ref LL_ADC_CHANNEL_P3AVDD                         
  *         @arg @ref LL_ADC_CHANNEL_P4AVDD                         
  *         @arg @ref LL_ADC_CHANNEL_P5AVDD                         
  *         @arg @ref LL_ADC_CHANNEL_P6AVDD                         
  *         @arg @ref LL_ADC_CHANNEL_P7AVDD                         
  *         @arg @ref LL_ADC_CHANNEL_P8AVDD                         
  *         @arg @ref LL_ADC_CHANNEL_64                             
  */
__STATIC_INLINE void LL_MDU_ADC_SetADCChanneltoInjectionChannel(uint32_t ChannelIndex, uint32_t AdcChannelIndex)
{
  switch(ChannelIndex)
  {
    case LL_ADC_INJCH_1:
      MODIFY_REG(MDU->INJGRP_CHCR_1, MDU_INJGRP_CHCR_ADCCH_ID_1, AdcChannelIndex << MDU_INJGRP_CHCR_ADCCH_ID_1_Pos);
      break;
    case LL_ADC_INJCH_2:
      MODIFY_REG(MDU->INJGRP_CHCR_2, MDU_INJGRP_CHCR_ADCCH_ID_2, AdcChannelIndex << MDU_INJGRP_CHCR_ADCCH_ID_2_Pos);
      break;
    case LL_ADC_INJCH_3:
      MODIFY_REG(MDU->INJGRP_CHCR_3, MDU_INJGRP_CHCR_ADCCH_ID_3, AdcChannelIndex << MDU_INJGRP_CHCR_ADCCH_ID_3_Pos);
      break;
    case LL_ADC_INJCH_4:
      MODIFY_REG(MDU->INJGRP_CHCR_4, MDU_INJGRP_CHCR_ADCCH_ID_4, AdcChannelIndex << MDU_INJGRP_CHCR_ADCCH_ID_4_Pos);
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to set ADC injection channel sampling cycles
  * @rmtoll INJGRP_CHCR_1      MDU_INJGRP_CHCR_SMP_CYC_1               LL_MDU_ADC_SetInjectionChannelSamplingCycles
  * @rmtoll INJGRP_CHCR_2      MDU_INJGRP_CHCR_SMP_CYC_2               LL_MDU_ADC_SetInjectionChannelSamplingCycles
  * @rmtoll INJGRP_CHCR_3      MDU_INJGRP_CHCR_SMP_CYC_3               LL_MDU_ADC_SetInjectionChannelSamplingCycles
  * @rmtoll INJGRP_CHCR_4      MDU_INJGRP_CHCR_SMP_CYC_4               LL_MDU_ADC_SetInjectionChannelSamplingCycles\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  * @param  Cycles sampling cycles (n+1)
  *         This value is one between 0 to 0xFF

  */
__STATIC_INLINE void LL_MDU_ADC_SetInjectionChannelSamplingCycles(uint32_t ChannelIndex, uint32_t Cycles)
{
  switch(ChannelIndex)
  {
    case LL_ADC_INJCH_1:
      MODIFY_REG(MDU->INJGRP_CHCR_1, MDU_INJGRP_CHCR_SMP_CYC_1, Cycles << MDU_INJGRP_CHCR_SMP_CYC_1_Pos);
      break;
    case LL_ADC_INJCH_2:
      MODIFY_REG(MDU->INJGRP_CHCR_2, MDU_INJGRP_CHCR_SMP_CYC_2, Cycles << MDU_INJGRP_CHCR_SMP_CYC_2_Pos);
      break;
    case LL_ADC_INJCH_3:
      MODIFY_REG(MDU->INJGRP_CHCR_3, MDU_INJGRP_CHCR_SMP_CYC_3, Cycles << MDU_INJGRP_CHCR_SMP_CYC_3_Pos);
      break;
    case LL_ADC_INJCH_4:
      MODIFY_REG(MDU->INJGRP_CHCR_4, MDU_INJGRP_CHCR_SMP_CYC_4, Cycles << MDU_INJGRP_CHCR_SMP_CYC_4_Pos);
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to set ADC injection channel AWD
  * @rmtoll INJGRP_CHCR_1      MDU_INJGRP_CHCR_AWD_ID_1               LL_MDU_ADC_SetInjectionChannelAWD
  * @rmtoll INJGRP_CHCR_2      MDU_INJGRP_CHCR_AWD_ID_2               LL_MDU_ADC_SetInjectionChannelAWD
  * @rmtoll INJGRP_CHCR_3      MDU_INJGRP_CHCR_AWD_ID_3               LL_MDU_ADC_SetInjectionChannelAWD
  * @rmtoll INJGRP_CHCR_4      MDU_INJGRP_CHCR_AWD_ID_4               LL_MDU_ADC_SetInjectionChannelAWD\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  * @param  AwdId AWD ID
  *         This value is one of the following values
  *         @arg @ref LL_ADC_AWD_ID_NONE
  *         @arg @ref LL_ADC_AWD_ID_1
  *         @arg @ref LL_ADC_AWD_ID_2
  *         @arg @ref LL_ADC_AWD_ID_3

  */
__STATIC_INLINE void LL_MDU_ADC_SetInjectionChannelAWD(uint32_t ChannelIndex, uint32_t AwdId)
{
  switch(ChannelIndex)
  {
    case LL_ADC_INJCH_1:
      MODIFY_REG(MDU->INJGRP_CHCR_1, MDU_INJGRP_CHCR_AWD_ID_1, AwdId << MDU_INJGRP_CHCR_AWD_ID_1_Pos);
      break;
    case LL_ADC_INJCH_2:
      MODIFY_REG(MDU->INJGRP_CHCR_2, MDU_INJGRP_CHCR_AWD_ID_2, AwdId << MDU_INJGRP_CHCR_AWD_ID_2_Pos);
      break;
    case LL_ADC_INJCH_3:
      MODIFY_REG(MDU->INJGRP_CHCR_3, MDU_INJGRP_CHCR_AWD_ID_3, AwdId << MDU_INJGRP_CHCR_AWD_ID_3_Pos);
      break;
    case LL_ADC_INJCH_4:
      MODIFY_REG(MDU->INJGRP_CHCR_4, MDU_INJGRP_CHCR_AWD_ID_4, AwdId << MDU_INJGRP_CHCR_AWD_ID_4_Pos);
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to set ADC regular channel to regular group
  * @rmtoll REGGRP_CHMAP      REGGRP_CHMAP               LL_MDU_ADC_SetRegularGroupChannelMap\n
  * @param  Map regular channel map
  *         This value is combined of the following values
  *         @arg @ref LL_ADC_REGCH_MAP_1                 
  *         @arg @ref LL_ADC_REGCH_MAP_2                 
  *         @arg @ref LL_ADC_REGCH_MAP_3                 
  *         @arg @ref LL_ADC_REGCH_MAP_4                 
  *         @arg @ref LL_ADC_REGCH_MAP_5                 
  *         @arg @ref LL_ADC_REGCH_MAP_6                 
  *         @arg @ref LL_ADC_REGCH_MAP_7                 
  *         @arg @ref LL_ADC_REGCH_MAP_8                 
  *         @arg @ref LL_ADC_REGCH_MAP_9                 
  *         @arg @ref LL_ADC_REGCH_MAP_10                
  *         @arg @ref LL_ADC_REGCH_MAP_11                
  *         @arg @ref LL_ADC_REGCH_MAP_12                
  *         @arg @ref LL_ADC_REGCH_MAP_13                
  *         @arg @ref LL_ADC_REGCH_MAP_14                
  *         @arg @ref LL_ADC_REGCH_MAP_15                
  *         @arg @ref LL_ADC_REGCH_MAP_16                
  *         @arg @ref LL_ADC_REGCH_MAP_17                
  *         @arg @ref LL_ADC_REGCH_MAP_18                
  *         @arg @ref LL_ADC_REGCH_MAP_19                
  *         @arg @ref LL_ADC_REGCH_MAP_20                
  *         @arg @ref LL_ADC_REGCH_MAP_21                
  *         @arg @ref LL_ADC_REGCH_MAP_22                
  *         @arg @ref LL_ADC_REGCH_MAP_23                
  *         @arg @ref LL_ADC_REGCH_MAP_24                
  *         @arg @ref LL_ADC_REGCH_MAP_25                
  *         @arg @ref LL_ADC_REGCH_MAP_26                
  *         @arg @ref LL_ADC_REGCH_MAP_27                
  *         @arg @ref LL_ADC_REGCH_MAP_28                
  *         @arg @ref LL_ADC_REGCH_MAP_29                
  *         @arg @ref LL_ADC_REGCH_MAP_30                
  *         @arg @ref LL_ADC_REGCH_MAP_31                
  *         @arg @ref LL_ADC_REGCH_MAP_32                

  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularGroupChannelMap(uint32_t Map)
{
  MDU->REGGRP_CHMAP = Map;
}

/**
  * @brief  Function to set ADC regular channel to discontinuous regular group
  * @rmtoll REGGRP_SGRP_CHMAP_1      REGGRP_CHMAP               LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap\n
  * @rmtoll REGGRP_SGRP_CHMAP_2      REGGRP_CHMAP               LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap\n
  * @rmtoll REGGRP_SGRP_CHMAP_3      REGGRP_CHMAP               LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap\n
  * @rmtoll REGGRP_SGRP_CHMAP_4      REGGRP_CHMAP               LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap\n
  * @rmtoll REGGRP_SGRP_CHMAP_5      REGGRP_CHMAP               LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap\n
  * @rmtoll REGGRP_SGRP_CHMAP_6      REGGRP_CHMAP               LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap\n
  * @rmtoll REGGRP_SGRP_CHMAP_7      REGGRP_CHMAP               LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap\n
  * @rmtoll REGGRP_SGRP_CHMAP_8      REGGRP_CHMAP               LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap\n
  * @param  GroupIndex regular group index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGGRP_1
  *         @arg @ref LL_ADC_REGGRP_2
  *         @arg @ref LL_ADC_REGGRP_3
  *         @arg @ref LL_ADC_REGGRP_4
  *         @arg @ref LL_ADC_REGGRP_5
  *         @arg @ref LL_ADC_REGGRP_6
  *         @arg @ref LL_ADC_REGGRP_7
  *         @arg @ref LL_ADC_REGGRP_8
  * @param  Map regular channel map
  *         This value is combined of the following values
  *         @arg @ref LL_ADC_REGCH_MAP_1                 
  *         @arg @ref LL_ADC_REGCH_MAP_2                 
  *         @arg @ref LL_ADC_REGCH_MAP_3                 
  *         @arg @ref LL_ADC_REGCH_MAP_4                 
  *         @arg @ref LL_ADC_REGCH_MAP_5                 
  *         @arg @ref LL_ADC_REGCH_MAP_6                 
  *         @arg @ref LL_ADC_REGCH_MAP_7                 
  *         @arg @ref LL_ADC_REGCH_MAP_8                 
  *         @arg @ref LL_ADC_REGCH_MAP_9                 
  *         @arg @ref LL_ADC_REGCH_MAP_10                
  *         @arg @ref LL_ADC_REGCH_MAP_11                
  *         @arg @ref LL_ADC_REGCH_MAP_12                
  *         @arg @ref LL_ADC_REGCH_MAP_13                
  *         @arg @ref LL_ADC_REGCH_MAP_14                
  *         @arg @ref LL_ADC_REGCH_MAP_15                
  *         @arg @ref LL_ADC_REGCH_MAP_16                
  *         @arg @ref LL_ADC_REGCH_MAP_17                
  *         @arg @ref LL_ADC_REGCH_MAP_18                
  *         @arg @ref LL_ADC_REGCH_MAP_19                
  *         @arg @ref LL_ADC_REGCH_MAP_20                
  *         @arg @ref LL_ADC_REGCH_MAP_21                
  *         @arg @ref LL_ADC_REGCH_MAP_22                
  *         @arg @ref LL_ADC_REGCH_MAP_23                
  *         @arg @ref LL_ADC_REGCH_MAP_24                
  *         @arg @ref LL_ADC_REGCH_MAP_25                
  *         @arg @ref LL_ADC_REGCH_MAP_26                
  *         @arg @ref LL_ADC_REGCH_MAP_27                
  *         @arg @ref LL_ADC_REGCH_MAP_28                
  *         @arg @ref LL_ADC_REGCH_MAP_29                
  *         @arg @ref LL_ADC_REGCH_MAP_30                
  *         @arg @ref LL_ADC_REGCH_MAP_31                
  *         @arg @ref LL_ADC_REGCH_MAP_32                

  */
__STATIC_INLINE void LL_MDU_ADC_SetDiscontinuousRegularGroupChannelMap(uint32_t GroupIndex, uint32_t Map)
{
  switch(GroupIndex)
  {
    case LL_ADC_REGGRP_1:
      MDU->REGGRP_SGRP_CHMAP_1 = Map;
      break;
    case LL_ADC_REGGRP_2:
      MDU->REGGRP_SGRP_CHMAP_2 = Map;
      break;
    case LL_ADC_REGGRP_3:
      MDU->REGGRP_SGRP_CHMAP_3 = Map;
      break;
    case LL_ADC_REGGRP_4:
      MDU->REGGRP_SGRP_CHMAP_4 = Map;
      break;
    case LL_ADC_REGGRP_5:
      MDU->REGGRP_SGRP_CHMAP_5 = Map;
      break;
    case LL_ADC_REGGRP_6:
      MDU->REGGRP_SGRP_CHMAP_6 = Map;
      break;
    case LL_ADC_REGGRP_7:
      MDU->REGGRP_SGRP_CHMAP_7 = Map;
      break;
    case LL_ADC_REGGRP_8:
      MDU->REGGRP_SGRP_CHMAP_8 = Map;
      break;
    default :
      break;
  }
}

/**
  * @brief  Function to set ADC regular channel to discontinuous regular group
  * @rmtoll REGGRP_CHCR_1      MDU_REGGRP_CHCR_ADC_CHID_x               LL_MDU_ADC_SetADCChanneltoRegularChannel\n
  * @rmtoll REGGRP_CHCR_2      MDU_REGGRP_CHCR_ADC_CHID_x               LL_MDU_ADC_SetADCChanneltoRegularChannel
  * @rmtoll REGGRP_CHCR_3      MDU_REGGRP_CHCR_ADC_CHID_x               LL_MDU_ADC_SetADCChanneltoRegularChannel
  * @rmtoll REGGRP_CHCR_4      MDU_REGGRP_CHCR_ADC_CHID_x               LL_MDU_ADC_SetADCChanneltoRegularChannel
  * @rmtoll REGGRP_CHCR_5      MDU_REGGRP_CHCR_ADC_CHID_x               LL_MDU_ADC_SetADCChanneltoRegularChannel
  * @rmtoll REGGRP_CHCR_6      MDU_REGGRP_CHCR_ADC_CHID_x               LL_MDU_ADC_SetADCChanneltoRegularChannel
  * @rmtoll REGGRP_CHCR_7      MDU_REGGRP_CHCR_ADC_CHID_x               LL_MDU_ADC_SetADCChanneltoRegularChannel
  * @rmtoll REGGRP_CHCR_8      MDU_REGGRP_CHCR_ADC_CHID_x               LL_MDU_ADC_SetADCChanneltoRegularChannel
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              
  * @param  AdcChannelIndex ADC channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_CHANNEL_1                               
  *         @arg @ref LL_ADC_CHANNEL_2                               
  *         @arg @ref LL_ADC_CHANNEL_3                               
  *         @arg @ref LL_ADC_CHANNEL_4                               
  *         @arg @ref LL_ADC_CHANNEL_5                               
  *         @arg @ref LL_ADC_CHANNEL_6                               
  *         @arg @ref LL_ADC_CHANNEL_7                               
  *         @arg @ref LL_ADC_CHANNEL_8                               
  *         @arg @ref LL_ADC_CHANNEL_9                               
  *         @arg @ref LL_ADC_CHANNEL_10                              
  *         @arg @ref LL_ADC_CHANNEL_11                              
  *         @arg @ref LL_ADC_CHANNEL_12                              
  *         @arg @ref LL_ADC_CHANNEL_13                              
  *         @arg @ref LL_ADC_CHANNEL_14                              
  *         @arg @ref LL_ADC_CHANNEL_15                              
  *         @arg @ref LL_ADC_CHANNEL_16                              
  *         @arg @ref LL_ADC_CHANNEL_17                              
  *         @arg @ref LL_ADC_CHANNEL_18                              
  *         @arg @ref LL_ADC_CHANNEL_19                              
  *         @arg @ref LL_ADC_CHANNEL_20                              
  *         @arg @ref LL_ADC_CHANNEL_21                              
  *         @arg @ref LL_ADC_CHANNEL_22                              
  *         @arg @ref LL_ADC_CHANNEL_23                              
  *         @arg @ref LL_ADC_CHANNEL_24                              
  *         @arg @ref LL_ADC_CHANNEL_25                              
  *         @arg @ref LL_ADC_CHANNEL_26                              
  *         @arg @ref LL_ADC_CHANNEL_27                              
  *         @arg @ref LL_ADC_CHANNEL_28                              
  *         @arg @ref LL_ADC_CHANNEL_29                              
  *         @arg @ref LL_ADC_CHANNEL_30                              
  *         @arg @ref LL_ADC_CHANNEL_31                              
  *         @arg @ref LL_ADC_CHANNEL_32                              
  *         @arg @ref LL_ADC_CHANNEL_33                              
  *         @arg @ref LL_ADC_CHANNEL_34                              
  *         @arg @ref LL_ADC_CHANNEL_35                              
  *         @arg @ref LL_ADC_CHANNEL_36                              
  *         @arg @ref LL_ADC_CHANNEL_37                              
  *         @arg @ref LL_ADC_CHANNEL_38                              
  *         @arg @ref LL_ADC_CHANNEL_39                              
  *         @arg @ref LL_ADC_CHANNEL_40                              
  *         @arg @ref LL_ADC_CHANNEL_41                              
  *         @arg @ref LL_ADC_CHANNEL_42                              
  *         @arg @ref LL_ADC_CHANNEL_43                              
  *         @arg @ref LL_ADC_CHANNEL_44                              
  *         @arg @ref LL_ADC_CHANNEL_45                              
  *         @arg @ref LL_ADC_CHANNEL_46                              
  *         @arg @ref LL_ADC_CHANNEL_47                              
  *         @arg @ref LL_ADC_CHANNEL_48                              
  *         @arg @ref LL_ADC_CHANNEL_49                              
  *         @arg @ref LL_ADC_CHANNEL_50                              
  *         @arg @ref LL_ADC_CHANNEL_51                              
  *         @arg @ref LL_ADC_CHANNEL_52                              
  *         @arg @ref LL_ADC_CHANNEL_53                               
  *         @arg @ref LL_ADC_CHANNEL_VBG                             
  *         @arg @ref LL_ADC_CHANNEL_VTS                             
  *         @arg @ref LL_ADC_CHANNEL_VBS                             
  *         @arg @ref LL_ADC_CHANNEL_P2AVDD                          
  *         @arg @ref LL_ADC_CHANNEL_P3AVDD                          
  *         @arg @ref LL_ADC_CHANNEL_P4AVDD                          
  *         @arg @ref LL_ADC_CHANNEL_P5AVDD                          
  *         @arg @ref LL_ADC_CHANNEL_P6AVDD                          
  *         @arg @ref LL_ADC_CHANNEL_P7AVDD                          
  *         @arg @ref LL_ADC_CHANNEL_P8AVDD                          
  *         @arg @ref LL_ADC_CHANNEL_64                              
  */
__STATIC_INLINE void LL_MDU_ADC_SetADCChanneltoRegularChannel(uint32_t ChannelIndex, uint32_t AdcChannelIndex)
{
  uint32_t * preg = (uint32_t*)&(MDU->REGGRP_CHCR_1);
  uint32_t offset = ChannelIndex >> 2;
  uint32_t pos = (ChannelIndex & 0x3) << 3;

  MODIFY_REG(*(preg + offset), MDU_REGGRP_CHCR_ADC_CHID_1 << pos, AdcChannelIndex << pos);
}

/**
  * @brief  Function to set ADC regular channel to discontinuous regular group
  * @rmtoll REGGRP_CHCR_1      MDU_REGGRP_CHCR_AWD_ID_x               LL_MDU_ADC_SetRegularChannelAWD\n
  * @rmtoll REGGRP_CHCR_2      MDU_REGGRP_CHCR_AWD_ID_x               LL_MDU_ADC_SetRegularChannelAWD
  * @rmtoll REGGRP_CHCR_3      MDU_REGGRP_CHCR_AWD_ID_x               LL_MDU_ADC_SetRegularChannelAWD
  * @rmtoll REGGRP_CHCR_4      MDU_REGGRP_CHCR_AWD_ID_x               LL_MDU_ADC_SetRegularChannelAWD
  * @rmtoll REGGRP_CHCR_5      MDU_REGGRP_CHCR_AWD_ID_x               LL_MDU_ADC_SetRegularChannelAWD
  * @rmtoll REGGRP_CHCR_6      MDU_REGGRP_CHCR_AWD_ID_x               LL_MDU_ADC_SetRegularChannelAWD
  * @rmtoll REGGRP_CHCR_7      MDU_REGGRP_CHCR_AWD_ID_x               LL_MDU_ADC_SetRegularChannelAWD
  * @rmtoll REGGRP_CHCR_8      MDU_REGGRP_CHCR_AWD_ID_x               LL_MDU_ADC_SetRegularChannelAWD
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              
  * @param  AWDId AWD ID
  *         This value is one of the following values
  *         @arg @ref LL_ADC_AWD_ID_NONE
  *         @arg @ref LL_ADC_AWD_ID_1
  *         @arg @ref LL_ADC_AWD_ID_2
  *         @arg @ref LL_ADC_AWD_ID_3
  */
__STATIC_INLINE void LL_MDU_ADC_SetRegularChannelAWD(uint32_t ChannelIndex, uint32_t AWDId)
{
  uint32_t * preg = (uint32_t*)&(MDU->REGGRP_CHCR_1);
  uint32_t offset = ChannelIndex >> 2;
  uint32_t pos = (ChannelIndex & 0x3) << (3 + MDU_REGGRP_CHCR_AWD_ID_1_Pos);

  MODIFY_REG(*(preg + offset), MDU_REGGRP_CHCR_AWD_ID_1 << pos, AWDId << pos);
}

/**
  * @brief  Function to get ADC injection group EOS flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_GetInjectionGroupEOSFlag\n
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetInjectionGroupEOSFlag(void)
{
  return (uint32_t)((READ_REG(MDU->INT_STATUS_1) & (LL_ADC_FLAG_INJGRP_EOS)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC injection group EOS flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_ClearInjectionGroupEOSFlag\n
  */
__STATIC_INLINE void LL_MDU_ADC_ClearInjectionGroupEOSFlag(void)
{
  CLEAR_BIT(MDU->INT_STATUS_1, LL_ADC_FLAG_INJGRP_EOS);
}

/**
  * @brief  Function to get ADC injection group OverWrite flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_GetInjectionGroupOWFlag\n
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetInjectionGroupOWFlag(void)
{
  return (uint32_t)((READ_REG(MDU->INT_STATUS_1) & (LL_ADC_FLAG_INJGRP_OW)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC injection group OverWrite flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_ClearInjectionGroupOWFlag\n
  */
__STATIC_INLINE void LL_MDU_ADC_ClearInjectionGroupOWFlag(void)
{
  CLEAR_BIT(MDU->INT_STATUS_1, LL_ADC_FLAG_INJGRP_OW);
}

/**
  * @brief  Function to get ADC regular group EOS flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_GetRegularGroupEOSFlag\n
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetRegularGroupEOSFlag(void)
{
  return (uint32_t)((READ_REG(MDU->INT_STATUS_1) & (LL_ADC_FLAG_REGGRP_EOS)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC regular group EOS flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_ClearRegularGroupEOSFlag\n

  */
__STATIC_INLINE void LL_MDU_ADC_ClearRegularGroupEOSFlag(void)
{
  CLEAR_BIT(MDU->INT_STATUS_1, LL_ADC_FLAG_REGGRP_EOS);
}

/**
  * @brief  Function to get ADC regular group OverWrite flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_GetRegularGroupOWFlag\n
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetRegularGroupOWFlag(void)
{
  return (uint32_t)((READ_REG(MDU->INT_STATUS_1) & (LL_ADC_FLAG_REGGRP_OW)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC regular group OverWrite flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_ClearRegularGroupOWFlag\n

  */
__STATIC_INLINE void LL_MDU_ADC_ClearRegularGroupOWFlag(void)
{
  CLEAR_BIT(MDU->INT_STATUS_1, LL_ADC_FLAG_REGGRP_OW);
}

/**
  * @brief  Function to get ADC injection channle EOC flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_GetInjectionChannelEOCFlag\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetInjectionChannelEOCFlag(uint32_t ChannelIndex)
{
  return (uint32_t)((READ_REG(MDU->INT_STATUS_1) & (LL_ADC_FLAG_INJCH_EOC_1 << ChannelIndex)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC injection channle EOC flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_ClearInjectionChannelEOCFlag\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  */
__STATIC_INLINE void LL_MDU_ADC_ClearInjectionChannelEOCFlag(uint32_t ChannelIndex)
{
  CLEAR_BIT(MDU->INT_STATUS_1, (LL_ADC_FLAG_INJCH_EOC_1 << ChannelIndex));
}

/**
  * @brief  Function to get ADC injection channel OW flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_GetInjectionChannelOWFlag\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetInjectionChannelOWFlag(uint32_t ChannelIndex)
{
  return (uint32_t)((READ_REG(MDU->INT_STATUS_1) & (LL_ADC_FLAG_INJCH_OW_1 << ChannelIndex)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC injection channel OW flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_ClearInjectionChannelOWFlag\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  */
__STATIC_INLINE void LL_MDU_ADC_ClearInjectionChannelOWFlag(uint32_t ChannelIndex)
{
  CLEAR_BIT(MDU->INT_STATUS_1, (LL_ADC_FLAG_INJCH_OW_1 << ChannelIndex));
}

/**
  * @brief  Function to get ADC injection channel AWD flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_GetInjectionChannelAWDFlag\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetInjectionChannelAWDFlag(uint32_t ChannelIndex)
{
  return (uint32_t)((READ_REG(MDU->INT_STATUS_1) & (LL_ADC_FLAG_INJCH_AWD_1 << ChannelIndex)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC injection channel AWD flag
  * @rmtoll INT_STATUS_1                     LL_MDU_ADC_ClearInjectionChannelAWDFlag\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  */
__STATIC_INLINE void LL_MDU_ADC_ClearInjectionChannelAWDFlag(uint32_t ChannelIndex)
{
  CLEAR_BIT(MDU->INT_STATUS_1, (LL_ADC_FLAG_INJCH_AWD_1 << ChannelIndex));
}

/**
  * @brief  Function to get ADC regular channle EOC flag
  * @rmtoll INT_STATUS_2                     LL_MDU_ADC_GetRegularChannelEOCFlag\n
  * @rmtoll INT_STATUS_3                     LL_MDU_ADC_GetRegularChannelEOCFlag
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetRegularChannelEOCFlag(uint32_t ChannelIndex)
{
  uint32_t * preg = (uint32_t*)&(MDU->INT_STATUS_2);
  uint32_t offset = ChannelIndex >> 4;
  uint32_t pos = ChannelIndex & 0xF;
  return (uint32_t)((READ_REG(*(preg + offset)) & (LL_ADC_FLAG_REGCH_EOC_1 << pos)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC regular channle EOC flag
  * @rmtoll INT_STATUS_2                     LL_MDU_ADC_ClearRegularChannelEOCFlag\n
  * @rmtoll INT_STATUS_3                     LL_MDU_ADC_ClearRegularChannelEOCFlag
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              
  */
__STATIC_INLINE void LL_MDU_ADC_ClearRegularChannelEOCFlag(uint32_t ChannelIndex)
{
  uint32_t * preg = (uint32_t*)&(MDU->INT_STATUS_2);
  uint32_t offset = ChannelIndex >> 4;
  uint32_t pos = ChannelIndex & 0xF;
  CLEAR_BIT(*(preg + offset), (LL_ADC_FLAG_REGCH_EOC_1 << pos));
}

/**
  * @brief  Function to get ADC regular channel OW flag
  * @rmtoll INT_STATUS_2                     LL_MDU_ADC_GetRegularChannelOWFlag\n
  * @rmtoll INT_STATUS_3                     LL_MDU_ADC_GetRegularChannelOWFlag
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetRegularChannelOWFlag(uint32_t ChannelIndex)
{
  uint32_t * preg = (uint32_t*)&(MDU->INT_STATUS_2);
  uint32_t offset = ChannelIndex >> 4;
  uint32_t pos = ChannelIndex & 0xF;

  return (uint32_t)((READ_REG(*(preg + offset)) & (LL_ADC_FLAG_REGCH_OW_1 << pos)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC regular channel OW flag
  * @rmtoll INT_STATUS_2                     LL_MDU_ADC_ClearRegularChannelOWFlag\n
  * @rmtoll INT_STATUS_3                     LL_MDU_ADC_ClearRegularChannelOWFlag
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              

  */
__STATIC_INLINE void LL_MDU_ADC_ClearRegularChannelOWFlag(uint32_t ChannelIndex)
{
  uint32_t * preg = (uint32_t*)&(MDU->INT_STATUS_2);
  uint32_t offset = ChannelIndex >> 4;
  uint32_t pos = ChannelIndex & 0xF;

  CLEAR_BIT(*(preg + offset), (LL_ADC_FLAG_REGCH_OW_1 << pos));
}

/**
  * @brief  Function to get ADC regular channle AWD flag
  * @rmtoll INT_STATUS_4                     LL_MDU_ADC_GetRegularChannelAWDFlag\n
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              
  * @retval Status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetRegularChannelAWDFlag(uint32_t ChannelIndex)
{
  return (uint32_t)((READ_REG(MDU->INT_STATUS_4) & (LL_ADC_FLAG_REGCH_AWD_1 << ChannelIndex)) ? SET : RESET);
}

/**
  * @brief  Function to clear ADC regular channle AWD flag
  * @rmtoll INT_STATUS_4                     LL_MDU_ADC_ClearRegularChannelAWDFlag\n
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              

  */
__STATIC_INLINE void LL_MDU_ADC_ClearRegularChannelAWDFlag(uint32_t ChannelIndex)
{
  CLEAR_BIT(MDU->INT_STATUS_4, (LL_ADC_FLAG_REGCH_AWD_1 << ChannelIndex));
}

/**
  * @brief  Function to get ADC injection channel result
  * @rmtoll INJ_RESULTS_x                     LL_MDU_ADC_GetInjectionChannelResult\n
  * @param  ChannelIndex injection channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_INJCH_1
  *         @arg @ref LL_ADC_INJCH_2
  *         @arg @ref LL_ADC_INJCH_3
  *         @arg @ref LL_ADC_INJCH_4
  * @retval result (16 bits)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetInjectionChannelResult(uint32_t ChannelIndex)
{
  uint32_t * preg = (uint32_t*)&(MDU->INJ_RESULTS_1);
  uint32_t offset = ChannelIndex >> 1;
  uint32_t pos = ChannelIndex & 0x1;

  return (uint32_t)((READ_REG(*(preg + offset)) & (MDU_INJ_RESULT_CH_1 << (pos << 4))) >> (pos << 4));
}

/**
  * @brief  Function to get ADC regular channel result
  * @rmtoll REG_RESULTS_x                     LL_MDU_ADC_GetRegularChannelResult\n
  * @param  ChannelIndex regular channel index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_REGCH_1                     (0)                               
  *         @arg @ref LL_ADC_REGCH_2                     (1)                               
  *         @arg @ref LL_ADC_REGCH_3                     (2)                               
  *         @arg @ref LL_ADC_REGCH_4                     (3)                               
  *         @arg @ref LL_ADC_REGCH_5                     (4)                               
  *         @arg @ref LL_ADC_REGCH_6                     (5)                               
  *         @arg @ref LL_ADC_REGCH_7                     (6)                               
  *         @arg @ref LL_ADC_REGCH_8                     (7)                               
  *         @arg @ref LL_ADC_REGCH_9                     (8)                               
  *         @arg @ref LL_ADC_REGCH_10                    (9)                               
  *         @arg @ref LL_ADC_REGCH_11                    (10)                              
  *         @arg @ref LL_ADC_REGCH_12                    (11)                              
  *         @arg @ref LL_ADC_REGCH_13                    (12)                              
  *         @arg @ref LL_ADC_REGCH_14                    (13)                              
  *         @arg @ref LL_ADC_REGCH_15                    (14)                              
  *         @arg @ref LL_ADC_REGCH_16                    (15)                              
  *         @arg @ref LL_ADC_REGCH_17                    (16)                              
  *         @arg @ref LL_ADC_REGCH_18                    (17)                              
  *         @arg @ref LL_ADC_REGCH_19                    (18)                              
  *         @arg @ref LL_ADC_REGCH_20                    (19)                              
  *         @arg @ref LL_ADC_REGCH_21                    (20)                              
  *         @arg @ref LL_ADC_REGCH_22                    (21)                              
  *         @arg @ref LL_ADC_REGCH_23                    (22)                              
  *         @arg @ref LL_ADC_REGCH_24                    (23)                              
  *         @arg @ref LL_ADC_REGCH_25                    (24)                              
  *         @arg @ref LL_ADC_REGCH_26                    (25)                              
  *         @arg @ref LL_ADC_REGCH_27                    (26)                              
  *         @arg @ref LL_ADC_REGCH_28                    (27)                              
  *         @arg @ref LL_ADC_REGCH_29                    (28)                              
  *         @arg @ref LL_ADC_REGCH_30                    (29)                              
  *         @arg @ref LL_ADC_REGCH_31                    (30)                              
  *         @arg @ref LL_ADC_REGCH_32                    (31)                              
  * @retval result (16 bits)
  */
__STATIC_INLINE uint32_t LL_MDU_ADC_GetRegularChannelResult(uint32_t ChannelIndex)
{
  uint32_t * preg = (uint32_t*)&(MDU->REG_RESULTS_1);
  uint32_t offset = ChannelIndex >> 1;
  uint32_t pos = ChannelIndex & 0x1;

  return (uint32_t)((READ_REG(*(preg + offset)) & (MDU_REG_RESULT_CH_1 << (pos << 4))) >> (pos << 4));
}

/**
  * @brief  Function to set ADC AWD low threshold
  * @rmtoll AWD_CR_x                     LL_MDU_ADC_SetAWDLowThreshold\n
  * @param  AwdIndex AWD index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_AWD_1
  *         @arg @ref LL_ADC_AWD_2
  *         @arg @ref LL_ADC_AWD_3
  * @param  Threshold AWD low threshold
  *         This value is onr between 0 to 0xFFF

  */
__STATIC_INLINE void LL_MDU_ADC_SetAWDLowThreshold(uint32_t AwdIndex, uint32_t Threshold)
{
  uint32_t * preg = (uint32_t*)&(MDU->AWD_CR_1);
  uint32_t offset = AwdIndex;

  MODIFY_REG((*(preg + offset)), MDU_AWD_CR_THR_LOW_1, Threshold << MDU_AWD_CR_THR_LOW_1_Pos);
}

/**
  * @brief  Function to set ADC AWD high threshold
  * @rmtoll AWD_CR_x                     LL_MDU_ADC_SetAWDHighThreshold\n
  * @param  AwdIndex AWD index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_AWD_1
  *         @arg @ref LL_ADC_AWD_2
  *         @arg @ref LL_ADC_AWD_3
  * @param  Threshold AWD high threshold
  *         This value is one between 0 to 0xFFF

  */
__STATIC_INLINE void LL_MDU_ADC_SetAWDHighThreshold(uint32_t AwdIndex, uint32_t Threshold)
{
  uint32_t * preg = (uint32_t*)&(MDU->AWD_CR_1);
  uint32_t offset = AwdIndex;

  MODIFY_REG((*(preg + offset)), MDU_AWD_CR_THR_HIGH_1, Threshold << MDU_AWD_CR_THR_HIGH_1_Pos);
}

/**
  * @brief  Function to set ADC AWD monitor zone
  * @rmtoll AWD_CR_x                     LL_MDU_ADC_SetAWDHighThreshold\n
  * @param  AwdIndex AWD index
  *         This value is one of the following values
  *         @arg @ref LL_ADC_AWD_1
  *         @arg @ref LL_ADC_AWD_2
  *         @arg @ref LL_ADC_AWD_3
  * @param  Mode AWD monitor mode
  *         This value is one of the following values
  *         @arg @ref LL_ADC_AWD_MODE_NONE
  *         @arg @ref LL_ADC_AWD_MODE_LOW
  *         @arg @ref LL_ADC_AWD_MODE_MID
  *         @arg @ref LL_ADC_AWD_MODE_HIGH

  */
__STATIC_INLINE void LL_MDU_ADC_SetAWDMonitorMode(uint32_t AwdIndex, uint32_t Mode)
{
  uint32_t * preg = (uint32_t*)&(MDU->AWD_CR_1);
  uint32_t offset = AwdIndex;

  MODIFY_REG((*(preg + offset)), MDU_AWD_CR_CFG_1, Mode << MDU_AWD_CR_CFG_1_Pos);
}

#endif /* XT32H0xxB */
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ADC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

/* De-initialization of ADC instance */
ErrorStatus LL_ADC_DeInit(MDU_TypeDef *ADCx);

/* Initialization of some features of ADC instance */
ErrorStatus LL_ADC_Init(MDU_TypeDef *ADCx, LL_ADC_InitTypeDef *pADC_InitStruct);
void        LL_ADC_StructInit(LL_ADC_InitTypeDef *pADC_InitStruct);

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

#endif /* MDU */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif /* XT32H0xx_LL_ADC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
