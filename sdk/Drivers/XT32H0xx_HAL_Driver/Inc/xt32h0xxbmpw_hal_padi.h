
/**
  ******************************************************************************
  * @file    xt32h0xxbmpw_hal_padi.h
  * @author  Software Team
  * @brief   Header file of PADI HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xxBMPW_HAL_PADI_H
#define XT32H0xxBMPW_HAL_PADI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/** @addtogroup XT32H0xxBMPW_HAL_Driver
  * @{
  */

/** @addtogroup PADI 
  * @brief PADI HAL module driver
  * @{
  */

/* Exported constants --------------------------------------------------------*/
/** @addtogroup PADI_Exported_Constants
  * @{
  */

/** @addtogroup PADI_define PADI definition
  * @{
  */

    /******************* PAD 1 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO1_ADCIN_10_LED_SEG_COM_0                        (0UL)
#define PADI_IDX_IO1_ADCIN_10_LED_SEG_COM_0                        (0)
/*********** CFG 1 ***********/
#define PADI_CFG_IO1_PC20                                          (PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO1_PC20                                          (0)
/*********** CFG 2 ***********/
#define PADI_CFG_IO1_PD0                                           (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO1_PD0                                           (0)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO1_ATI_BRK1                                      (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO1_ATI_BRK1                                      (0)
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO1_UART1_TX                                      (PADI_PINCFG_PIN_0_1 | PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO1_UART1_TX                                      (0)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 2 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO2_PD9                                           (PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO2_PD9                                           (1)
/*********** CFG 2 ***********/
#define PADI_CFG_IO2_PC3                                           (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO2_PC3                                           (1)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 3 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO3_PD7                                           (PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO3_PD7                                           (2)
/*********** CFG 2 ***********/
#define PADI_CFG_IO3_PC2                                           (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO3_PC2                                           (2)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO3_BTI04                                         (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO3_BTI04                                         (2)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO3_BTO04                                         (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO3_BTO04                                         (2)
/*********** CFG 3 ***********/
#define PADI_CFG_IO3_UART1_CTS                                     (PADI_PINCFG_PIN_2_1 | PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO3_UART1_CTS                                     (2)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 4 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO4_CTSU_SN_29                                    (0UL)
#define PADI_IDX_IO4_CTSU_SN_29                                    (3)
/*********** CFG 1 ***********/
#define PADI_CFG_IO4_PD6                                           (PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO4_PD6                                           (3)
/*********** CFG 2 ***********/
#define PADI_CFG_IO4_PC1                                           (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO4_PC1                                           (3)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO4_BTI07                                         (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO4_BTI07                                         (3)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO4_BTO07                                         (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO4_BTO07                                         (3)
/*********** CFG 3 ***********/
#define PADI_CFG_IO4_UART1_RTS                                     (PADI_PINCFG_PIN_3_1 | PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO4_UART1_RTS                                     (3)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 5 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO5_CTSU_SN_28_LED_SEG_COM_1                      (0UL)
#define PADI_IDX_IO5_CTSU_SN_28_LED_SEG_COM_1                      (4)
/*********** CFG 1 ***********/
#define PADI_CFG_IO5_PD5                                           (PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO5_PD5                                           (4)
/*********** CFG 2 ***********/
#define PADI_CFG_IO5_PC0                                           (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO5_PC0                                           (4)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO5_ATI_BRK2                                      (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO5_ATI_BRK2                                      (4)
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO5_UART1_RX                                      (PADI_PINCFG_PIN_4_1 | PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO5_UART1_RX                                      (4)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 6 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO6_RSTb                                          (PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO6_RSTb                                          (5)
/*********** CFG 2 ***********/
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 7 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO7_XO_HS                                         (0UL)
#define PADI_IDX_IO7_XO_HS                                         (6)
/*********** CFG 1 ***********/
#define PADI_CFG_IO7_PC21                                          (PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO7_PC21                                          (6)
/*********** CFG 2 ***********/
#define PADI_CFG_IO7_PD4                                           (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO7_PD4                                           (6)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO7_EXTCLK                                        (PADI_PINCFG_PIN_6_1 | PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO7_EXTCLK                                        (6)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 8 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO8_XI_HS                                         (0UL)
#define PADI_IDX_IO8_XI_HS                                         (7)
/*********** CFG 1 ***********/
#define PADI_CFG_IO8_PC22                                          (PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO8_PC22                                          (7)
/*********** CFG 2 ***********/
#define PADI_CFG_IO8_PD3                                           (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO8_PD3                                           (7)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 9 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO9_CTSU_SN_27_LED_SEG_COM_2                      (0UL)
#define PADI_IDX_IO9_CTSU_SN_27_LED_SEG_COM_2                      (8)
/*********** CFG 1 ***********/
#define PADI_CFG_IO9_PA0                                           (PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO9_PA0                                           (8)
/*********** CFG 2 ***********/
#define PADI_CFG_IO9_PD15                                          (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO9_PD15                                          (8)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO9_ATIN14                                         (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO9_ATIN14                                         (8)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO9_ATOUT14                                         (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO9_ATOUT14                                         (8)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
#define PADI_CFG_IO9_BOOT0                                         (PADI_PINCFG_PIN_0_2)
#define PADI_IDX_IO9_BOOT0                                         (8)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 10 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO10_CTSU_SN_26_LED_SEG_COM_3                     (0UL)
#define PADI_IDX_IO10_CTSU_SN_26_LED_SEG_COM_3                     (9)
/*********** CFG 1 ***********/
#define PADI_CFG_IO10_PC23                                         (PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO10_PC23                                         (9)
/*********** CFG 2 ***********/
#define PADI_CFG_IO10_PB26                                         (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO10_PB26                                         (9)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO10_nmi_wakeup                                   (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO10_nmi_wakeup                                   (9)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO10_ATOUT11P                                       (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO10_ATOUT11P                                       (9)
/*********** CFG 3 ***********/
#define PADI_CFG_IO10_SPI2_SS                                      (PADI_PINCFG_PIN_1_1 | PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO10_SPI2_SS                                      (9)
/*********** CFG 4 ***********/
#define PADI_CFG_IO10_BOOT1                                        (PADI_PINCFG_PIN_1_2)
#define PADI_IDX_IO10_BOOT1                                        (9)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 11 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO11_XO_LS                                        (0UL)
#define PADI_IDX_IO11_XO_LS                                        (10)
/*********** CFG 1 ***********/
#define PADI_CFG_IO11_PD10                                         (PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO11_PD10                                         (10)
/*********** CFG 2 ***********/
#define PADI_CFG_IO11_PD2                                          (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO11_PD2                                          (10)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 12 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO12_XI_LS                                        (0UL)
#define PADI_IDX_IO12_XI_LS                                        (11)
/*********** CFG 1 ***********/
#define PADI_CFG_IO12_PD11                                         (PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO12_PD11                                         (11)
/*********** CFG 2 ***********/
#define PADI_CFG_IO12_PD1                                          (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO12_PD1                                          (11)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 13 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO13_CTSU_SN_25_LED_SEG_COM_4                     (0UL)
#define PADI_IDX_IO13_CTSU_SN_25_LED_SEG_COM_4                     (12)
/*********** CFG 1 ***********/
#define PADI_CFG_IO13_PD12                                         (PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO13_PD12                                         (12)
/*********** CFG 2 ***********/
#define PADI_CFG_IO13_PC16                                         (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO13_PC16                                         (12)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO13_ATIN11                                        (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO13_ATIN11                                        (12)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO13_ATOUT11N                                       (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO13_ATOUT11N                                       (12)
/*********** CFG 3 ***********/
#define PADI_CFG_IO13_SPI2_SCK                                     (PADI_PINCFG_PIN_4_1 | PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO13_SPI2_SCK                                     (12)
/*********** CFG 4 ***********/
#define PADI_CFG_IO13_I2C1_SCK                                     (PADI_PINCFG_PIN_4_2)
#define PADI_IDX_IO13_I2C1_SCK                                     (12)
/*********** CFG 5 ***********/
#define PADI_CFG_IO13_UART2_TX                                     (PADI_PINCFG_PIN_4_2 | PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO13_UART2_TX                                     (12)
/*********** CFG 6 ***********/
/******************* PAD 14 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO14_CTSU_SN_24_LED_SEG_COM_5                     (0UL)
#define PADI_IDX_IO14_CTSU_SN_24_LED_SEG_COM_5                     (13)
/*********** CFG 1 ***********/
#define PADI_CFG_IO14_PD13                                         (PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO14_PD13                                         (13)
/*********** CFG 2 ***********/
#define PADI_CFG_IO14_PC17                                         (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO14_PC17                                         (13)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO14_ATOUT12P                                       (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO14_ATOUT12P                                       (13)
/*********** CFG 3 ***********/
#define PADI_CFG_IO14_SPI2_TXD                                     (PADI_PINCFG_PIN_5_1 | PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO14_SPI2_TXD                                     (13)
/*********** CFG 4 ***********/
#define PADI_CFG_IO14_I2C1_SDA                                     (PADI_PINCFG_PIN_5_2)
#define PADI_IDX_IO14_I2C1_SDA                                     (13)
/*********** CFG 5 ***********/
#define PADI_CFG_IO14_UART2_RX                                     (PADI_PINCFG_PIN_5_2 | PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO14_UART2_RX                                     (13)
/*********** CFG 6 ***********/
/******************* PAD 15 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO15_CTSU_SN_23_LED_SEG_COM_6                     (0UL)
#define PADI_IDX_IO15_CTSU_SN_23_LED_SEG_COM_6                     (14)
/*********** CFG 1 ***********/
#define PADI_CFG_IO15_PD14                                         (PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO15_PD14                                         (14)
/*********** CFG 2 ***********/
#define PADI_CFG_IO15_PC18                                         (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO15_PC18                                         (14)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO15_ATIN12                                        (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO15_ATIN12                                        (14)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO15_ATOUT12N                                       (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO15_ATOUT12N                                       (14)
/*********** CFG 3 ***********/
#define PADI_CFG_IO15_SPI2_RXD                                     (PADI_PINCFG_PIN_6_1 | PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO15_SPI2_RXD                                     (14)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO15_UART2_CTS                                    (PADI_PINCFG_PIN_6_2 | PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO15_UART2_CTS                                    (14)
/*********** CFG 6 ***********/
/******************* PAD 16 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO16_CTSU_SN_22                                   (0UL)
#define PADI_IDX_IO16_CTSU_SN_22                                   (15)
/*********** CFG 1 ***********/
#define PADI_CFG_IO16_PB26                                         (PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO16_PB26                                         (15)
/*********** CFG 2 ***********/
#define PADI_CFG_IO16_PC19                                         (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO16_PC19                                         (15)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO16_UART2_RTS                                    (PADI_PINCFG_PIN_7_2 | PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO16_UART2_RTS                                    (15)
/*********** CFG 6 ***********/
/******************* PAD 17 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO17_CTSU_SN_21_LED_SEG_COM_7                     (0UL)
#define PADI_IDX_IO17_CTSU_SN_21_LED_SEG_COM_7                     (16)
/*********** CFG 1 ***********/
#define PADI_CFG_IO17_PA4                                          (PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO17_PA4                                          (16)
/*********** CFG 2 ***********/
#define PADI_CFG_IO17_PB25                                         (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO17_PB25                                         (16)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO17_BTI03                                        (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO17_BTI03                                        (16)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO17_BTO03                                        (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO17_BTO03                                        (16)
/*********** CFG 3 ***********/
#define PADI_CFG_IO17_SWDIO                                        (PADI_PINCFG_PIN_0_1 | PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO17_SWDIO                                        (16)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 18 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO18_PA11                                         (PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO18_PA11                                         (17)
/*********** CFG 2 ***********/
#define PADI_CFG_IO18_PC31                                         (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO18_PC31                                         (17)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO18_UART2_TX                                     (PADI_PINCFG_PIN_1_1 | PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO18_UART2_TX                                     (17)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 19 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO19_PA10                                         (PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO19_PA10                                         (18)
/*********** CFG 2 ***********/
#define PADI_CFG_IO19_PC30                                         (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO19_PC30                                         (18)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO19_UART2_RX                                     (PADI_PINCFG_PIN_2_1 | PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO19_UART2_RX                                     (18)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 20 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO20_ADCIN_11                                     (0UL)
#define PADI_IDX_IO20_ADCIN_11                                     (19)
/*********** CFG 1 ***********/
#define PADI_CFG_IO20_PA9                                          (PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO20_PA9                                          (19)
/*********** CFG 2 ***********/
#define PADI_CFG_IO20_PC29                                         (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO20_PC29                                         (19)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO20_I2C1_SCK                                     (PADI_PINCFG_PIN_3_1 | PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO20_I2C1_SCK                                     (19)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 21 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO21_ADCIN_9                                      (0UL)
#define PADI_IDX_IO21_ADCIN_9                                      (20)
/*********** CFG 1 ***********/
#define PADI_CFG_IO21_PA8                                          (PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO21_PA8                                          (20)
/*********** CFG 2 ***********/
#define PADI_CFG_IO21_PC28                                         (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO21_PC28                                         (20)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO21_I2C1_SDA                                     (PADI_PINCFG_PIN_4_1 | PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO21_I2C1_SDA                                     (20)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 22 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO22_CTSU_SN_20                                   (0UL)
#define PADI_IDX_IO22_CTSU_SN_20                                   (21)
/*********** CFG 1 ***********/
#define PADI_CFG_IO22_PD29                                         (PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO22_PD29                                         (21)
/*********** CFG 2 ***********/
#define PADI_CFG_IO22_PC27                                         (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO22_PC27                                         (21)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO22_SPI1_SS                                      (PADI_PINCFG_PIN_5_2 | PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO22_SPI1_SS                                      (21)
/******************* PAD 23 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO23_CTSU_SN_19                                   (0UL)
#define PADI_IDX_IO23_CTSU_SN_19                                   (22)
/*********** CFG 1 ***********/
#define PADI_CFG_IO23_PD28                                         (PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO23_PD28                                         (22)
/*********** CFG 2 ***********/
#define PADI_CFG_IO23_PC26                                         (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO23_PC26                                         (22)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO23_ATO_BRK2                                     (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO23_ATO_BRK2                                     (22)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO23_SPI1_TXD                                     (PADI_PINCFG_PIN_6_2 | PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO23_SPI1_TXD                                     (22)
/******************* PAD 24 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO24_CTSU_SN_18                                   (0UL)
#define PADI_IDX_IO24_CTSU_SN_18                                   (23)
/*********** CFG 1 ***********/
#define PADI_CFG_IO24_PD27                                         (PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO24_PD27                                         (23)
/*********** CFG 2 ***********/
#define PADI_CFG_IO24_PC25                                         (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO24_PC25                                         (23)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO24_ATO_BRK1                                     (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO24_ATO_BRK1                                     (23)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO24_SPI1_RXD                                     (PADI_PINCFG_PIN_7_2 | PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO24_SPI1_RXD                                     (23)
/******************* PAD 25 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO25_CTSU_SN_17_LED_SEG_8                         (0UL)
#define PADI_IDX_IO25_CTSU_SN_17_LED_SEG_8                         (24)
/*********** CFG 1 ***********/
#define PADI_CFG_IO25_PD26                                         (PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO25_PD26                                         (24)
/*********** CFG 2 ***********/
#define PADI_CFG_IO25_PC24                                         (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO25_PC24                                         (24)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO25_SWCLK                                        (PADI_PINCFG_PIN_0_1 | PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO25_SWCLK                                        (24)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO25_SPI1_SCK                                     (PADI_PINCFG_PIN_0_2 | PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO25_SPI1_SCK                                     (24)
/******************* PAD 26 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO26_PD25                                         (PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO26_PD25                                         (25)
/*********** CFG 2 ***********/
#define PADI_CFG_IO26_PB6                                          (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO26_PB6                                          (25)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO26_BTI05                                        (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO26_BTI05                                        (25)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO26_BTO05                                        (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO26_BTO05                                        (25)
/*********** CFG 3 ***********/
#define PADI_CFG_IO26_SWDIO                                        (PADI_PINCFG_PIN_1_1 | PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO26_SWDIO                                        (25)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 27 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO27_PD24                                         (PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO27_PD24                                         (26)
/*********** CFG 2 ***********/
#define PADI_CFG_IO27_PB5                                          (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO27_PB5                                          (26)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO27_BTI04                                        (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO27_BTI04                                        (26)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO27_BTO04                                        (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO27_BTO04                                        (26)
/*********** CFG 3 ***********/
#define PADI_CFG_IO27_SWCLK                                        (PADI_PINCFG_PIN_2_1 | PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO27_SWCLK                                        (26)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 28 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO28_CTSU_SN_16_COMP0_P                           (0UL)
#define PADI_IDX_IO28_CTSU_SN_16_COMP0_P                           (27)
/*********** CFG 1 ***********/
#define PADI_CFG_IO28_PA3                                          (PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO28_PA3                                          (27)
/*********** CFG 2 ***********/
#define PADI_CFG_IO28_PB24                                         (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO28_PB24                                         (27)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO28_ATI_ETR                                      (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO28_ATI_ETR                                      (27)
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO28_I2C1_SCK                                     (PADI_PINCFG_PIN_3_1 | PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO28_I2C1_SCK                                     (27)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 29 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO29_CTSU_SN_15_COMP0_N                           (0UL)
#define PADI_IDX_IO29_CTSU_SN_15_COMP0_N                           (28)
/*********** CFG 1 ***********/
#define PADI_CFG_IO29_PA1                                          (PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO29_PA1                                          (28)
/*********** CFG 2 ***********/
#define PADI_CFG_IO29_PC8                                          (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO29_PC8                                          (28)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO29_ATOUT13P                                       (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO29_ATOUT13P                                       (28)
/*********** CFG 3 ***********/
#define PADI_CFG_IO29_I2C1_SDA                                     (PADI_PINCFG_PIN_4_1 | PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO29_I2C1_SDA                                     (28)
/*********** CFG 4 ***********/
#define PADI_CFG_IO29_SWDIO                                        (PADI_PINCFG_PIN_4_2)
#define PADI_IDX_IO29_SWDIO                                        (28)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 30 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO30_ADCIN_6                                      (0UL)
#define PADI_IDX_IO30_ADCIN_6                                      (29)
/*********** CFG 1 ***********/
#define PADI_CFG_IO30_PA2                                          (PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO30_PA2                                          (29)
/*********** CFG 2 ***********/
#define PADI_CFG_IO30_PC9                                          (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO30_PC9                                          (29)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO30_ATIN13                                        (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO30_ATIN13                                        (29)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO30_ATOUT13N                                       (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO30_ATOUT13N                                       (29)
/*********** CFG 3 ***********/
#define PADI_CFG_IO30_O_COMP0                                      (PADI_PINCFG_PIN_5_1 | PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO30_O_COMP0                                      (29)
/*********** CFG 4 ***********/
#define PADI_CFG_IO30_SWCLK                                        (PADI_PINCFG_PIN_5_2)
#define PADI_IDX_IO30_SWCLK                                        (29)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 31 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO31_ADCIN_15                                     (0UL)
#define PADI_IDX_IO31_ADCIN_15                                     (30)
/*********** CFG 1 ***********/
#define PADI_CFG_IO31_PA10                                         (PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO31_PA10                                         (30)
/*********** CFG 2 ***********/
#define PADI_CFG_IO31_PC10                                         (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO31_PC10                                         (30)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 32 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO32_ADCIN_14                                     (0UL)
#define PADI_IDX_IO32_ADCIN_14                                     (31)
/*********** CFG 1 ***********/
#define PADI_CFG_IO32_PA11                                         (PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO32_PA11                                         (31)
/*********** CFG 2 ***********/
#define PADI_CFG_IO32_PC11                                         (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO32_PC11                                         (31)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 33 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO33_ADCIN_13                                     (0UL)
#define PADI_IDX_IO33_ADCIN_13                                     (32)
/*********** CFG 1 ***********/
#define PADI_CFG_IO33_PB27                                         (PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO33_PB27                                         (32)
/*********** CFG 2 ***********/
#define PADI_CFG_IO33_PC12                                         (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO33_PC12                                         (32)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 34 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO34_ADCIN_12                                     (0UL)
#define PADI_IDX_IO34_ADCIN_12                                     (33)
/*********** CFG 1 ***********/
#define PADI_CFG_IO34_PD21                                         (PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO34_PD21                                         (33)
/*********** CFG 2 ***********/
#define PADI_CFG_IO34_PC13                                         (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO34_PC13                                         (33)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO34_SPI1_SCK                                     (PADI_PINCFG_PIN_1_1 | PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO34_SPI1_SCK                                     (33)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 35 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO35_CTSU_SN_14_COMP1_P                           (0UL)
#define PADI_IDX_IO35_CTSU_SN_14_COMP1_P                           (34)
/*********** CFG 1 ***********/
#define PADI_CFG_IO35_PD20                                         (PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO35_PD20                                         (34)
/*********** CFG 2 ***********/
#define PADI_CFG_IO35_PB15                                         (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO35_PB15                                         (34)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO35_GTIN14                                        (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO35_GTIN14                                        (34)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO35_GTOUT14                                        (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO35_GTOUT14                                        (34)
/*********** CFG 3 ***********/
#define PADI_CFG_IO35_UART3_TX                                     (PADI_PINCFG_PIN_2_1 | PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO35_UART3_TX                                     (34)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 36 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO36_CTSU_SN_13_COMP1_N                           (0UL)
#define PADI_IDX_IO36_CTSU_SN_13_COMP1_N                           (35)
/*********** CFG 1 ***********/
#define PADI_CFG_IO36_PA5                                          (PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO36_PA5                                          (35)
/*********** CFG 2 ***********/
#define PADI_CFG_IO36_PB14                                         (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO36_PB14                                         (35)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO36_BTI01                                        (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO36_BTI01                                        (35)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO36_BTO01                                        (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO36_BTO01                                        (35)
/*********** CFG 3 ***********/
#define PADI_CFG_IO36_UART3_RX                                     (PADI_PINCFG_PIN_3_1 | PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO36_UART3_RX                                     (35)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO36_SPI2_SS                                      (PADI_PINCFG_PIN_3_2 | PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO36_SPI2_SS                                      (35)
/******************* PAD 37 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO37_ADCIN_5                                      (0UL)
#define PADI_IDX_IO37_ADCIN_5                                      (36)
/*********** CFG 1 ***********/
#define PADI_CFG_IO37_PA31                                         (PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO37_PA31                                         (36)
/*********** CFG 2 ***********/
#define PADI_CFG_IO37_PB13                                         (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO37_PB13                                         (36)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO37_BTI02                                        (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO37_BTI02                                        (36)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO37_BTO02                                        (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO37_BTO02                                        (36)
/*********** CFG 3 ***********/
#define PADI_CFG_IO37_O_COMP1                                      (PADI_PINCFG_PIN_4_1 | PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO37_O_COMP1                                      (36)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO37_I2C2_SCK                                     (PADI_PINCFG_PIN_4_2 | PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO37_I2C2_SCK                                     (36)
/*********** CFG 6 ***********/
#define PADI_CFG_IO37_SPI2_SCK                                     (PADI_PINCFG_PIN_4_2 | PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO37_SPI2_SCK                                     (36)
/******************* PAD 38 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO38_CTSU_SN_12_COMP2_P                           (0UL)
#define PADI_IDX_IO38_CTSU_SN_12_COMP2_P                           (37)
/*********** CFG 1 ***********/
#define PADI_CFG_IO38_PD19                                         (PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO38_PD19                                         (37)
/*********** CFG 2 ***********/
#define PADI_CFG_IO38_PB12                                         (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO38_PB12                                         (37)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO38_BTI03                                        (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO38_BTI03                                        (37)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO38_BTO03                                        (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO38_BTO03                                        (37)
/*********** CFG 3 ***********/
#define PADI_CFG_IO38_UART2_RX                                     (PADI_PINCFG_PIN_5_1 | PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO38_UART2_RX                                     (37)
/*********** CFG 4 ***********/
#define PADI_CFG_IO38_I2C1_SCK                                     (PADI_PINCFG_PIN_5_2)
#define PADI_IDX_IO38_I2C1_SCK                                     (37)
/*********** CFG 5 ***********/
#define PADI_CFG_IO38_I2C2_SDA                                     (PADI_PINCFG_PIN_5_2 | PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO38_I2C2_SDA                                     (37)
/*********** CFG 6 ***********/
#define PADI_CFG_IO38_SPI2_RXD                                     (PADI_PINCFG_PIN_5_2 | PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO38_SPI2_RXD                                     (37)
/******************* PAD 39 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO39_CTSU_SN_11_COMP2_N                           (0UL)
#define PADI_IDX_IO39_CTSU_SN_11_COMP2_N                           (38)
/*********** CFG 1 ***********/
#define PADI_CFG_IO39_PD18                                         (PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO39_PD18                                         (38)
/*********** CFG 2 ***********/
#define PADI_CFG_IO39_PB11                                         (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO39_PB11                                         (38)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO39_BTI04                                        (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO39_BTI04                                        (38)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO39_BTO04                                        (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO39_BTO04                                        (38)
/*********** CFG 3 ***********/
#define PADI_CFG_IO39_UART2_TX                                     (PADI_PINCFG_PIN_6_1 | PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO39_UART2_TX                                     (38)
/*********** CFG 4 ***********/
#define PADI_CFG_IO39_I2C1_SDA                                     (PADI_PINCFG_PIN_6_2)
#define PADI_IDX_IO39_I2C1_SDA                                     (38)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO39_SPI2_TXD                                     (PADI_PINCFG_PIN_6_2 | PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO39_SPI2_TXD                                     (38)
/******************* PAD 40 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO40_ADCIN_4                                      (0UL)
#define PADI_IDX_IO40_ADCIN_4                                      (39)
/*********** CFG 1 ***********/
#define PADI_CFG_IO40_PA30                                         (PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO40_PA30                                         (39)
/*********** CFG 2 ***********/
#define PADI_CFG_IO40_PB10                                         (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO40_PB10                                         (39)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO40_BTI05                                        (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO40_BTI05                                        (39)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO40_BTO05                                        (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO40_BTO05                                        (39)
/*********** CFG 3 ***********/
#define PADI_CFG_IO40_SPI1_TXD                                     (PADI_PINCFG_PIN_7_1 | PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO40_SPI1_TXD                                     (39)
/*********** CFG 4 ***********/
#define PADI_CFG_IO40_O_COMP2                                      (PADI_PINCFG_PIN_7_2)
#define PADI_IDX_IO40_O_COMP2                                      (39)
/*********** CFG 5 ***********/
#define PADI_CFG_IO40_UART3_TX                                     (PADI_PINCFG_PIN_7_2 | PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO40_UART3_TX                                     (39)
/*********** CFG 6 ***********/
#define PADI_CFG_IO40_SWDIO                                        (PADI_PINCFG_PIN_7_2 | PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO40_SWDIO                                        (39)
/******************* PAD 41 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO41_CTSU_SN_10_ADCIN_3N                          (0UL)
#define PADI_IDX_IO41_CTSU_SN_10_ADCIN_3N                          (40)
/*********** CFG 1 ***********/
#define PADI_CFG_IO41_PA29                                         (PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO41_PA29                                         (40)
/*********** CFG 2 ***********/
#define PADI_CFG_IO41_PB9                                          (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO41_PB9                                          (40)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO41_BTI06                                        (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO41_BTI06                                        (40)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO41_BTO06                                        (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO41_BTO06                                        (40)
/*********** CFG 3 ***********/
#define PADI_CFG_IO41_SPI1_RXD                                     (PADI_PINCFG_PIN_0_1 | PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO41_SPI1_RXD                                     (40)
/*********** CFG 4 ***********/
#define PADI_CFG_IO41_I2C2_SDA                                     (PADI_PINCFG_PIN_0_2)
#define PADI_IDX_IO41_I2C2_SDA                                     (40)
/*********** CFG 5 ***********/
#define PADI_CFG_IO41_UART3_RX                                     (PADI_PINCFG_PIN_0_2 | PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO41_UART3_RX                                     (40)
/*********** CFG 6 ***********/
#define PADI_CFG_IO41_SWCLK                                        (PADI_PINCFG_PIN_0_2 | PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO41_SWCLK                                        (40)
/******************* PAD 42 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO42_CTSU_SN_9_ADCIN_3P                           (0UL)
#define PADI_IDX_IO42_CTSU_SN_9_ADCIN_3P                           (41)
/*********** CFG 1 ***********/
#define PADI_CFG_IO42_PA28                                         (PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO42_PA28                                         (41)
/*********** CFG 2 ***********/
#define PADI_CFG_IO42_PB8                                          (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO42_PB8                                          (41)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO42_BTI07                                        (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO42_BTI07                                        (41)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO42_BTO07                                        (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO42_BTO07                                        (41)
/*********** CFG 3 ***********/
#define PADI_CFG_IO42_SPI1_SCK                                     (PADI_PINCFG_PIN_1_1 | PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO42_SPI1_SCK                                     (41)
/*********** CFG 4 ***********/
#define PADI_CFG_IO42_I2C2_SCK                                     (PADI_PINCFG_PIN_1_2)
#define PADI_IDX_IO42_I2C2_SCK                                     (41)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 43 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO43_CTSU_SN_8                                    (0UL)
#define PADI_IDX_IO43_CTSU_SN_8                                    (42)
/*********** CFG 1 ***********/
#define PADI_CFG_IO43_PA27                                         (PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO43_PA27                                         (42)
/*********** CFG 2 ***********/
#define PADI_CFG_IO43_PD22                                         (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO43_PD22                                         (42)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
#define PADI_CFG_IO43_O_COMP3                                      (PADI_PINCFG_PIN_2_2)
#define PADI_IDX_IO43_O_COMP3                                      (42)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 44 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO44_CTSU_CAP                                     (0UL)
#define PADI_IDX_IO44_CTSU_CAP                                     (43)
/*********** CFG 1 ***********/
#define PADI_CFG_IO44_PA26                                         (PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO44_PA26                                         (43)
/*********** CFG 2 ***********/
#define PADI_CFG_IO44_PD23                                         (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO44_PD23                                         (43)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO44_SPI1_SS                                      (PADI_PINCFG_PIN_3_1 | PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO44_SPI1_SS                                      (43)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 45 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO45_CTSU_SN_7_COMP3_P                            (0UL)
#define PADI_IDX_IO45_CTSU_SN_7_COMP3_P                            (44)
/*********** CFG 1 ***********/
#define PADI_CFG_IO45_PA25                                         (PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO45_PA25                                         (44)
/*********** CFG 2 ***********/
#define PADI_CFG_IO45_PB23                                         (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO45_PB23                                         (44)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO45_GTI_ETR                                      (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO45_GTI_ETR                                      (44)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO45_GTOUT13P                                       (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO45_GTOUT13P                                       (44)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO45_FLASH_JTAG_TMS                               (PADI_PINCFG_PIN_4_2 | PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO45_FLASH_JTAG_TMS                               (44)
/******************* PAD 46 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO46_CTSU_SN_6_COMP3_N                            (0UL)
#define PADI_IDX_IO46_CTSU_SN_6_COMP3_N                            (45)
/*********** CFG 1 ***********/
#define PADI_CFG_IO46_PA24                                         (PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO46_PA24                                         (45)
/*********** CFG 2 ***********/
#define PADI_CFG_IO46_PB22                                         (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO46_PB22                                         (45)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO46_GTIN13                                        (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO46_GTIN13                                        (45)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO46_GTOUT13N                                       (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO46_GTOUT13N                                       (45)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO46_FLASH_JTAG_TCK                               (PADI_PINCFG_PIN_5_2 | PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO46_FLASH_JTAG_TCK                               (45)
/******************* PAD 47 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO47_CTSU_SN_5                                    (0UL)
#define PADI_IDX_IO47_CTSU_SN_5                                    (46)
/*********** CFG 1 ***********/
#define PADI_CFG_IO47_PA23                                         (PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO47_PA23                                         (46)
/*********** CFG 2 ***********/
#define PADI_CFG_IO47_PB21                                         (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO47_PB21                                         (46)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO47_FLASH_JTAG_TDI                               (PADI_PINCFG_PIN_6_2 | PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO47_FLASH_JTAG_TDI                               (46)
/******************* PAD 48 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO48_CTSU_SN_4                                    (0UL)
#define PADI_IDX_IO48_CTSU_SN_4                                    (47)
/*********** CFG 1 ***********/
#define PADI_CFG_IO48_PA22                                         (PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO48_PA22                                         (47)
/*********** CFG 2 ***********/
#define PADI_CFG_IO48_PB20                                         (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO48_PB20                                         (47)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO48_FLASH_JTAG_TDO                               (PADI_PINCFG_PIN_7_2 | PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO48_FLASH_JTAG_TDO                               (47)
/******************* PAD 49 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO49_CTSU_SN_3_ADCIN_1N                           (0UL)
#define PADI_IDX_IO49_CTSU_SN_3_ADCIN_1N                           (48)
/*********** CFG 1 ***********/
#define PADI_CFG_IO49_PA21                                         (PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO49_PA21                                         (48)
/*********** CFG 2 ***********/
#define PADI_CFG_IO49_PB19                                         (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO49_PB19                                         (48)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO49_GTOUT11P                                       (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO49_GTOUT11P                                       (48)
/*********** CFG 3 ***********/
#define PADI_CFG_IO49_I2C1_SCK                                     (PADI_PINCFG_PIN_0_1 | PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO49_I2C1_SCK                                     (48)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 50 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO50_CTSU_SN_2_ADCIN_1P                           (0UL)
#define PADI_IDX_IO50_CTSU_SN_2_ADCIN_1P                           (49)
/*********** CFG 1 ***********/
#define PADI_CFG_IO50_PA20                                         (PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO50_PA20                                         (49)
/*********** CFG 2 ***********/
#define PADI_CFG_IO50_PB18                                         (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO50_PB18                                         (49)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO50_GTIN11                                        (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO50_GTIN11                                        (49)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO50_GTOUT11N                                       (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO50_GTOUT11N                                       (49)
/*********** CFG 3 ***********/
#define PADI_CFG_IO50_I2C1_SDA                                     (PADI_PINCFG_PIN_1_1 | PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO50_I2C1_SDA                                     (49)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 51 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO51_CTSU_SN_1_ADCIN_0N                           (0UL)
#define PADI_IDX_IO51_CTSU_SN_1_ADCIN_0N                           (50)
/*********** CFG 1 ***********/
#define PADI_CFG_IO51_PA19                                         (PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO51_PA19                                         (50)
/*********** CFG 2 ***********/
#define PADI_CFG_IO51_PB17                                         (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO51_PB17                                         (50)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO51_GTOUT12P                                       (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO51_GTOUT12P                                       (50)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 52 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO52_CTSU_SN_0_ADCIN_0P                           (0UL)
#define PADI_IDX_IO52_CTSU_SN_0_ADCIN_0P                           (51)
/*********** CFG 1 ***********/
#define PADI_CFG_IO52_PA18                                         (PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO52_PA18                                         (51)
/*********** CFG 2 ***********/
#define PADI_CFG_IO52_PB16                                         (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO52_PB16                                         (51)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO52_GTIN12                                        (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO52_GTIN12                                        (51)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO52_GTOUT12N                                       (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO52_GTOUT12N                                       (51)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 53 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO53_ADCIN_8                                      (0UL)
#define PADI_IDX_IO53_ADCIN_8                                      (52)
/*********** CFG 1 ***********/
#define PADI_CFG_IO53_PA17                                         (PADI_PINCFG_PIN_4_0)
#define PADI_IDX_IO53_PA17                                         (52)
/*********** CFG 2 ***********/
#define PADI_CFG_IO53_PD8                                          (PADI_PINCFG_PIN_4_1)
#define PADI_IDX_IO53_PD8                                          (52)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
#define PADI_CFG_IO53_SPI1_SS                                      (PADI_PINCFG_PIN_4_2)
#define PADI_IDX_IO53_SPI1_SS                                      (52)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 54 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO54_PGA_OUT_0                                    (0UL)
#define PADI_IDX_IO54_PGA_OUT_0                                    (53)
/*********** CFG 1 ***********/
#define PADI_CFG_IO54_PA16                                         (PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO54_PA16                                         (53)
/*********** CFG 2 ***********/
#define PADI_CFG_IO54_PB4                                          (PADI_PINCFG_PIN_5_1)
#define PADI_IDX_IO54_PB4                                          (53)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO54_I2C1_SCK                                     (PADI_PINCFG_PIN_5_1 | PADI_PINCFG_PIN_5_0)
#define PADI_IDX_IO54_I2C1_SCK                                     (53)
/*********** CFG 4 ***********/
#define PADI_CFG_IO54_SPI1_SCK                                     (PADI_PINCFG_PIN_5_2)
#define PADI_IDX_IO54_SPI1_SCK                                     (53)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 55 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO55_PGA_OUT_1                                    (0UL)
#define PADI_IDX_IO55_PGA_OUT_1                                    (54)
/*********** CFG 1 ***********/
#define PADI_CFG_IO55_PA15                                         (PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO55_PA15                                         (54)
/*********** CFG 2 ***********/
#define PADI_CFG_IO55_PB3                                          (PADI_PINCFG_PIN_6_1)
#define PADI_IDX_IO55_PB3                                          (54)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO55_I2C1_SDA                                     (PADI_PINCFG_PIN_6_1 | PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO55_I2C1_SDA                                     (54)
/*********** CFG 4 ***********/
#define PADI_CFG_IO55_SPI1_RXD                                     (PADI_PINCFG_PIN_6_2)
#define PADI_IDX_IO55_SPI1_RXD                                     (54)
/*********** CFG 5 ***********/
#define PADI_CFG_IO55_UART4_RX                                     (PADI_PINCFG_PIN_6_2 | PADI_PINCFG_PIN_6_0)
#define PADI_IDX_IO55_UART4_RX                                     (54)
/*********** CFG 6 ***********/
/******************* PAD 56 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO56_PA14                                         (PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO56_PA14                                         (55)
/*********** CFG 2 ***********/
#define PADI_CFG_IO56_PB2                                          (PADI_PINCFG_PIN_7_1)
#define PADI_IDX_IO56_PB2                                          (55)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
#define PADI_CFG_IO56_SPI1_TXD                                     (PADI_PINCFG_PIN_7_2)
#define PADI_IDX_IO56_SPI1_TXD                                     (55)
/*********** CFG 5 ***********/
#define PADI_CFG_IO56_UART4_TX                                     (PADI_PINCFG_PIN_7_2 | PADI_PINCFG_PIN_7_0)
#define PADI_IDX_IO56_UART4_TX                                     (55)
/*********** CFG 6 ***********/
/******************* PAD 57 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO57_CTSU_SN_31_ADCIN_2N                          (0UL)
#define PADI_IDX_IO57_CTSU_SN_31_ADCIN_2N                          (56)
/*********** CFG 1 ***********/
#define PADI_CFG_IO57_PA13                                         (PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO57_PA13                                         (56)
/*********** CFG 2 ***********/
#define PADI_CFG_IO57_PB1                                          (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO57_PB1                                          (56)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO57_BTO00                                        (PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO57_BTO00                                        (56)
/*********** CFG 3 ***********/
#define PADI_CFG_IO57_UART4_RX                                     (PADI_PINCFG_PIN_0_1 | PADI_PINCFG_PIN_0_0)
#define PADI_IDX_IO57_UART4_RX                                     (56)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO57_vcoclk_test                                  (PADI_PINCFG_PIN_0_2 | PADI_PINCFG_PIN_0_1)
#define PADI_IDX_IO57_vcoclk_test                                  (56)
/******************* PAD 58 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO58_CTSU_SN_30_ADCIN_2P                          (0UL)
#define PADI_IDX_IO58_CTSU_SN_30_ADCIN_2P                          (57)
/*********** CFG 1 ***********/
#define PADI_CFG_IO58_PA12                                         (PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO58_PA12                                         (57)
/*********** CFG 2 ***********/
#define PADI_CFG_IO58_PB0                                          (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO58_PB0                                          (57)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO58_BTI00                                        (PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO58_BTI00                                        (57)
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO58_UART4_TX                                     (PADI_PINCFG_PIN_1_1 | PADI_PINCFG_PIN_1_0)
#define PADI_IDX_IO58_UART4_TX                                     (57)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO58_rcclk_test                                   (PADI_PINCFG_PIN_1_2 | PADI_PINCFG_PIN_1_1)
#define PADI_IDX_IO58_rcclk_test                                   (57)
/******************* PAD 59 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO59_PA7                                          (PADI_PINCFG_PIN_2_0)
#define PADI_IDX_IO59_PA7                                          (58)
/*********** CFG 2 ***********/
#define PADI_CFG_IO59_PD17                                         (PADI_PINCFG_PIN_2_1)
#define PADI_IDX_IO59_PD17                                         (58)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/******************* PAD 60 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO60_ADCIN_7                                      (0UL)
#define PADI_IDX_IO60_ADCIN_7                                      (59)
/*********** CFG 1 ***********/
#define PADI_CFG_IO60_PA6                                          (PADI_PINCFG_PIN_3_0)
#define PADI_IDX_IO60_PA6                                          (59)
/*********** CFG 2 ***********/
#define PADI_CFG_IO60_PD16                                         (PADI_PINCFG_PIN_3_1)
#define PADI_IDX_IO60_PD16                                         (59)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/


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

#endif /* XT32H0xxBMPW_HAL_PADI_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

