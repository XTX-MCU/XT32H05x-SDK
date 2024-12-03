
/**
  ******************************************************************************
  * @file    xt32h0xxb_hal_padi.h
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
#ifndef XT32H0xxB_HAL_PADI_H
#define XT32H0xxB_HAL_PADI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/** @addtogroup XT32H0xxB_HAL_Driver
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

    /******************* IO 62 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO62_CH3N                                          (0UL)
#define PADI_IDX_IO62_CH3N                                          (61)
/*********** CFG 1 ***********/
#define PADI_CFG_IO62_PB29                                          (PADI_IOCFG_IO_62_0)
#define PADI_IDX_IO62_PB29                                          (61)
/*********** CFG 2 ***********/
#define PADI_CFG_IO62_PC5                                           (PADI_IOCFG_IO_62_1)
#define PADI_IDX_IO62_PC5                                           (61)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO62_GTOUT4_CH1_N                                  (PADI_IOCFG_IO_62_1)
#define PADI_IDX_IO62_GTOUT4_CH1_N                                  (61)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO62_GPIO_HIZ                                      (PADI_IOCFG_IO_62_2 | PADI_IOCFG_IO_62_1 | PADI_IOCFG_IO_62_0)
#define PADI_IDX_IO62_GPIO_HIZ                                      (61)
/*********** CFG 8 ***********/
#define PADI_CFG_IO62_CH18                                          (PADI_IOCFG_IO_62_3)
#define PADI_IDX_IO62_CH18                                          (61)
/******************* IO 1 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO1_PC20                                           (PADI_IOCFG_IO_1_0)
#define PADI_IDX_IO1_PC20                                           (0)
/*********** CFG 2 ***********/
#define PADI_CFG_IO1_PD0                                            (PADI_IOCFG_IO_1_1)
#define PADI_IDX_IO1_PD0                                            (0)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO1_ATIN1_ETR                                      (PADI_IOCFG_IO_1_1)
#define PADI_IDX_IO1_ATIN1_ETR                                      (0)
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO1_UART1_TX                                       (PADI_IOCFG_IO_1_1 | PADI_IOCFG_IO_1_0)
#define PADI_IDX_IO1_UART1_TX                                       (0)
/*********** CFG 4 ***********/
#define PADI_CFG_IO1_ATIN1_BRKIN1                                   (PADI_IOCFG_IO_1_2)
#define PADI_IDX_IO1_ATIN1_BRKIN1                                   (0)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO1_PB30                                           (PADI_IOCFG_IO_1_2 | PADI_IOCFG_IO_1_1)
#define PADI_IDX_IO1_PB30                                           (0)
/*********** CFG 7 ***********/
#define PADI_CFG_IO1_LED0                                           (PADI_IOCFG_IO_1_2 | PADI_IOCFG_IO_1_1 | PADI_IOCFG_IO_1_0)
#define PADI_IDX_IO1_LED0                                           (0)
/*********** CFG 8 ***********/
#define PADI_CFG_IO1_CH10                                           (PADI_IOCFG_IO_1_3)
#define PADI_IDX_IO1_CH10                                           (0)
/******************* IO 2 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO2_PD9                                            (PADI_IOCFG_IO_2_0)
#define PADI_IDX_IO2_PD9                                            (1)
/*********** CFG 2 ***********/
#define PADI_CFG_IO2_PC3                                            (PADI_IOCFG_IO_2_1)
#define PADI_IDX_IO2_PC3                                            (1)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO2_ATIN2_CH3                                      (PADI_IOCFG_IO_2_1)
#define PADI_IDX_IO2_ATIN2_CH3                                      (1)
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO2_ATOUT2_CH3_P                                   (PADI_IOCFG_IO_2_2 | PADI_IOCFG_IO_2_0)
#define PADI_IDX_IO2_ATOUT2_CH3_P                                   (1)
/*********** CFG 6 ***********/
#define PADI_CFG_IO2_PB31                                           (PADI_IOCFG_IO_2_2 | PADI_IOCFG_IO_2_1)
#define PADI_IDX_IO2_PB31                                           (1)
/*********** CFG 7 ***********/
#define PADI_CFG_IO2_GPIO_HIZ                                       (PADI_IOCFG_IO_2_2 | PADI_IOCFG_IO_2_1 | PADI_IOCFG_IO_2_0)
#define PADI_IDX_IO2_GPIO_HIZ                                       (1)
/*********** CFG 8 ***********/
#define PADI_CFG_IO2_CH35                                           (PADI_IOCFG_IO_2_3)
#define PADI_IDX_IO2_CH35                                           (1)
/******************* IO 3 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO3_PD7                                            (PADI_IOCFG_IO_3_0)
#define PADI_IDX_IO3_PD7                                            (2)
/*********** CFG 2 ***********/
#define PADI_CFG_IO3_PC2                                            (PADI_IOCFG_IO_3_1)
#define PADI_IDX_IO3_PC2                                            (2)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO3_BTOUT21                                        (PADI_IOCFG_IO_3_1)
#define PADI_IDX_IO3_BTOUT21                                        (2)
/*********** CFG 3 ***********/
#define PADI_CFG_IO3_UART1_CTS                                      (PADI_IOCFG_IO_3_1 | PADI_IOCFG_IO_3_0)
#define PADI_IDX_IO3_UART1_CTS                                      (2)
/*********** CFG 4 ***********/
#define PADI_CFG_IO3_BTIN21                                         (PADI_IOCFG_IO_3_2)
#define PADI_IDX_IO3_BTIN21                                         (2)
/*********** CFG 5 ***********/
#define PADI_CFG_IO3_ATOUT2_CH3_N                                   (PADI_IOCFG_IO_3_2 | PADI_IOCFG_IO_3_0)
#define PADI_IDX_IO3_ATOUT2_CH3_N                                   (2)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO3_GPIO_HIZ                                       (PADI_IOCFG_IO_3_2 | PADI_IOCFG_IO_3_1 | PADI_IOCFG_IO_3_0)
#define PADI_IDX_IO3_GPIO_HIZ                                       (2)
/*********** CFG 8 ***********/
/******************* IO 4 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO4_CTSU_SN_30                                     (0UL)
#define PADI_IDX_IO4_CTSU_SN_30                                     (3)
/*********** CFG 1 ***********/
#define PADI_CFG_IO4_PD6                                            (PADI_IOCFG_IO_4_0)
#define PADI_IDX_IO4_PD6                                            (3)
/*********** CFG 2 ***********/
#define PADI_CFG_IO4_PC1                                            (PADI_IOCFG_IO_4_1)
#define PADI_IDX_IO4_PC1                                            (3)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO4_GTIN4_CH1                                      (PADI_IOCFG_IO_4_1)
#define PADI_IDX_IO4_GTIN4_CH1                                      (3)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO4_BTOUT24                                        (PADI_IOCFG_IO_4_1)
#define PADI_IDX_IO4_BTOUT24                                        (3)
/*********** CFG 3 ***********/
#define PADI_CFG_IO4_UART1_RTS                                      (PADI_IOCFG_IO_4_1 | PADI_IOCFG_IO_4_0)
#define PADI_IDX_IO4_UART1_RTS                                      (3)
/*********** CFG 4 ***********/
#define PADI_CFG_IO4_BTIN24                                         (PADI_IOCFG_IO_4_2)
#define PADI_IDX_IO4_BTIN24                                         (3)
/*********** CFG 5 ***********/
#define PADI_CFG_IO4_GTOUT4_CH1_P                                   (PADI_IOCFG_IO_4_2 | PADI_IOCFG_IO_4_0)
#define PADI_IDX_IO4_GTOUT4_CH1_P                                   (3)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO4_GPIO_HIZ                                       (PADI_IOCFG_IO_4_2 | PADI_IOCFG_IO_4_1 | PADI_IOCFG_IO_4_0)
#define PADI_IDX_IO4_GPIO_HIZ                                       (3)
/*********** CFG 8 ***********/
/******************* IO 5 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO5_CTSU_SN_29                                     (0UL)
#define PADI_IDX_IO5_CTSU_SN_29                                     (4)
/*********** CFG 1 ***********/
#define PADI_CFG_IO5_PD5                                            (PADI_IOCFG_IO_5_0)
#define PADI_IDX_IO5_PD5                                            (4)
/*********** CFG 2 ***********/
#define PADI_CFG_IO5_PC0                                            (PADI_IOCFG_IO_5_1)
#define PADI_IDX_IO5_PC0                                            (4)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO5_ATIN1_BRKIN2                                   (PADI_IOCFG_IO_5_1)
#define PADI_IDX_IO5_ATIN1_BRKIN2                                   (4)
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO5_UART1_RX                                       (PADI_IOCFG_IO_5_1 | PADI_IOCFG_IO_5_0)
#define PADI_IDX_IO5_UART1_RX                                       (4)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO5_ATOUT1_CH3_P                                   (PADI_IOCFG_IO_5_2 | PADI_IOCFG_IO_5_0)
#define PADI_IDX_IO5_ATOUT1_CH3_P                                   (4)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO5_LED1                                           (PADI_IOCFG_IO_5_2 | PADI_IOCFG_IO_5_1 | PADI_IOCFG_IO_5_0)
#define PADI_IDX_IO5_LED1                                           (4)
/*********** CFG 8 ***********/
/******************* IO 6 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO6_RSTb                                           (PADI_IOCFG_IO_6_0)
#define PADI_IDX_IO6_RSTb                                           (5)
/*********** CFG 2 ***********/
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
/*********** CFG 8 ***********/
/******************* IO 7 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO7_XO_HS                                          (0UL)
#define PADI_IDX_IO7_XO_HS                                          (6)
/*********** CFG 1 ***********/
#define PADI_CFG_IO7_PC21                                           (PADI_IOCFG_IO_7_0)
#define PADI_IDX_IO7_PC21                                           (6)
/*********** CFG 2 ***********/
#define PADI_CFG_IO7_PD4                                            (PADI_IOCFG_IO_7_1)
#define PADI_IDX_IO7_PD4                                            (6)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO7_EXTCLKS                                        (PADI_IOCFG_IO_7_1 | PADI_IOCFG_IO_7_0)
#define PADI_IDX_IO7_EXTCLKS                                        (6)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO7_GPIO_HIZ                                       (PADI_IOCFG_IO_7_2 | PADI_IOCFG_IO_7_1 | PADI_IOCFG_IO_7_0)
#define PADI_IDX_IO7_GPIO_HIZ                                       (6)
/*********** CFG 8 ***********/
/******************* IO 8 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO8_XI_HS                                          (0UL)
#define PADI_IDX_IO8_XI_HS                                          (7)
/*********** CFG 1 ***********/
#define PADI_CFG_IO8_PC22                                           (PADI_IOCFG_IO_8_0)
#define PADI_IDX_IO8_PC22                                           (7)
/*********** CFG 2 ***********/
#define PADI_CFG_IO8_PD3                                            (PADI_IOCFG_IO_8_1)
#define PADI_IDX_IO8_PD3                                            (7)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO8_GPIO_HIZ                                       (PADI_IOCFG_IO_8_2 | PADI_IOCFG_IO_8_1 | PADI_IOCFG_IO_8_0)
#define PADI_IDX_IO8_GPIO_HIZ                                       (7)
/*********** CFG 8 ***********/
/******************* IO 9 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO9_CTSU_SN_28                                     (0UL)
#define PADI_IDX_IO9_CTSU_SN_28                                     (8)
/*********** CFG 1 ***********/
#define PADI_CFG_IO9_PA0                                            (PADI_IOCFG_IO_9_0)
#define PADI_IDX_IO9_PA0                                            (8)
/*********** CFG 2 ***********/
#define PADI_CFG_IO9_PD15                                           (PADI_IOCFG_IO_9_1)
#define PADI_IDX_IO9_PD15                                           (8)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO9_ATIN1_CH3                                      (PADI_IOCFG_IO_9_1)
#define PADI_IDX_IO9_ATIN1_CH3                                      (8)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO9_ATOUT1_CH3_N                                   (PADI_IOCFG_IO_9_1)
#define PADI_IDX_IO9_ATOUT1_CH3_N                                   (8)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO9_LED2                                           (PADI_IOCFG_IO_9_2 | PADI_IOCFG_IO_9_1 | PADI_IOCFG_IO_9_0)
#define PADI_IDX_IO9_LED2                                           (8)
/*********** CFG 8 ***********/
/******************* IO 10 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO10_CTSU_SN_27                                    (0UL)
#define PADI_IDX_IO10_CTSU_SN_27                                    (9)
/*********** CFG 1 ***********/
#define PADI_CFG_IO10_PC23                                          (PADI_IOCFG_IO_10_0)
#define PADI_IDX_IO10_PC23                                          (9)
/*********** CFG 2 ***********/
#define PADI_CFG_IO10_PB26                                          (PADI_IOCFG_IO_10_1)
#define PADI_IDX_IO10_PB26                                          (9)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO10_nmi_wakeup                                    (PADI_IOCFG_IO_10_1)
#define PADI_IDX_IO10_nmi_wakeup                                    (9)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO10_ATOUT1_CH1_P                                  (PADI_IOCFG_IO_10_1)
#define PADI_IDX_IO10_ATOUT1_CH1_P                                  (9)
/*********** CFG 3 ***********/
#define PADI_CFG_IO10_SPI2_SS                                       (PADI_IOCFG_IO_10_1 | PADI_IOCFG_IO_10_0)
#define PADI_IDX_IO10_SPI2_SS                                       (9)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO10_LED3                                          (PADI_IOCFG_IO_10_2 | PADI_IOCFG_IO_10_1 | PADI_IOCFG_IO_10_0)
#define PADI_IDX_IO10_LED3                                          (9)
/*********** CFG 8 ***********/
/******************* IO 11 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO11_XO_LS                                         (0UL)
#define PADI_IDX_IO11_XO_LS                                         (10)
/*********** CFG 1 ***********/
#define PADI_CFG_IO11_PD10                                          (PADI_IOCFG_IO_11_0)
#define PADI_IDX_IO11_PD10                                          (10)
/*********** CFG 2 ***********/
#define PADI_CFG_IO11_PD2                                           (PADI_IOCFG_IO_11_1)
#define PADI_IDX_IO11_PD2                                           (10)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO11_EXTCLK                                        (PADI_IOCFG_IO_11_1 | PADI_IOCFG_IO_11_0)
#define PADI_IDX_IO11_EXTCLK                                        (10)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO11_PC14                                          (PADI_IOCFG_IO_11_2 | PADI_IOCFG_IO_11_1)
#define PADI_IDX_IO11_PC14                                          (10)
/*********** CFG 7 ***********/
#define PADI_CFG_IO11_GPIO_HIZ                                      (PADI_IOCFG_IO_11_2 | PADI_IOCFG_IO_11_1 | PADI_IOCFG_IO_11_0)
#define PADI_IDX_IO11_GPIO_HIZ                                      (10)
/*********** CFG 8 ***********/
/******************* IO 12 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO12_XI_LS                                         (0UL)
#define PADI_IDX_IO12_XI_LS                                         (11)
/*********** CFG 1 ***********/
#define PADI_CFG_IO12_PD11                                          (PADI_IOCFG_IO_12_0)
#define PADI_IDX_IO12_PD11                                          (11)
/*********** CFG 2 ***********/
#define PADI_CFG_IO12_PD1                                           (PADI_IOCFG_IO_12_1)
#define PADI_IDX_IO12_PD1                                           (11)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO12_PC15                                          (PADI_IOCFG_IO_12_2 | PADI_IOCFG_IO_12_1)
#define PADI_IDX_IO12_PC15                                          (11)
/*********** CFG 7 ***********/
#define PADI_CFG_IO12_GPIO_HIZ                                      (PADI_IOCFG_IO_12_2 | PADI_IOCFG_IO_12_1 | PADI_IOCFG_IO_12_0)
#define PADI_IDX_IO12_GPIO_HIZ                                      (11)
/*********** CFG 8 ***********/
/******************* IO 13 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO13_CTSU_SN_26                                    (0UL)
#define PADI_IDX_IO13_CTSU_SN_26                                    (12)
/*********** CFG 1 ***********/
#define PADI_CFG_IO13_PD12                                          (PADI_IOCFG_IO_13_0)
#define PADI_IDX_IO13_PD12                                          (12)
/*********** CFG 2 ***********/
#define PADI_CFG_IO13_PC16                                          (PADI_IOCFG_IO_13_1)
#define PADI_IDX_IO13_PC16                                          (12)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO13_ATIN1_CH1                                     (PADI_IOCFG_IO_13_1)
#define PADI_IDX_IO13_ATIN1_CH1                                     (12)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO13_ATOUT1_CH1_N                                  (PADI_IOCFG_IO_13_1)
#define PADI_IDX_IO13_ATOUT1_CH1_N                                  (12)
/*********** CFG 3 ***********/
#define PADI_CFG_IO13_SPI2_SCK                                      (PADI_IOCFG_IO_13_1 | PADI_IOCFG_IO_13_0)
#define PADI_IDX_IO13_SPI2_SCK                                      (12)
/*********** CFG 4 ***********/
#define PADI_CFG_IO13_I2C1_SCK                                      (PADI_IOCFG_IO_13_2)
#define PADI_IDX_IO13_I2C1_SCK                                      (12)
/*********** CFG 5 ***********/
#define PADI_CFG_IO13_UART2_TX                                      (PADI_IOCFG_IO_13_2 | PADI_IOCFG_IO_13_0)
#define PADI_IDX_IO13_UART2_TX                                      (12)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO13_LED4                                          (PADI_IOCFG_IO_13_2 | PADI_IOCFG_IO_13_1 | PADI_IOCFG_IO_13_0)
#define PADI_IDX_IO13_LED4                                          (12)
/*********** CFG 8 ***********/
#define PADI_CFG_IO13_CH34                                          (PADI_IOCFG_IO_13_3)
#define PADI_IDX_IO13_CH34                                          (12)
/******************* IO 14 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO14_CTSU_SN_25                                    (0UL)
#define PADI_IDX_IO14_CTSU_SN_25                                    (13)
/*********** CFG 1 ***********/
#define PADI_CFG_IO14_PD13                                          (PADI_IOCFG_IO_14_0)
#define PADI_IDX_IO14_PD13                                          (13)
/*********** CFG 2 ***********/
#define PADI_CFG_IO14_PC17                                          (PADI_IOCFG_IO_14_1)
#define PADI_IDX_IO14_PC17                                          (13)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO14_ATOUT1_CH2_P                                  (PADI_IOCFG_IO_14_1)
#define PADI_IDX_IO14_ATOUT1_CH2_P                                  (13)
/*********** CFG 3 ***********/
#define PADI_CFG_IO14_SPI2_TXD                                      (PADI_IOCFG_IO_14_1 | PADI_IOCFG_IO_14_0)
#define PADI_IDX_IO14_SPI2_TXD                                      (13)
/*********** CFG 4 ***********/
#define PADI_CFG_IO14_I2C1_SDA                                      (PADI_IOCFG_IO_14_2)
#define PADI_IDX_IO14_I2C1_SDA                                      (13)
/*********** CFG 5 ***********/
#define PADI_CFG_IO14_UART2_RX                                      (PADI_IOCFG_IO_14_2 | PADI_IOCFG_IO_14_0)
#define PADI_IDX_IO14_UART2_RX                                      (13)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO14_LED5                                          (PADI_IOCFG_IO_14_2 | PADI_IOCFG_IO_14_1 | PADI_IOCFG_IO_14_0)
#define PADI_IDX_IO14_LED5                                          (13)
/*********** CFG 8 ***********/
#define PADI_CFG_IO14_CH33                                          (PADI_IOCFG_IO_14_3)
#define PADI_IDX_IO14_CH33                                          (13)
/******************* IO 15 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO15_CTSU_SN_24                                    (0UL)
#define PADI_IDX_IO15_CTSU_SN_24                                    (14)
/*********** CFG 1 ***********/
#define PADI_CFG_IO15_PD14                                          (PADI_IOCFG_IO_15_0)
#define PADI_IDX_IO15_PD14                                          (14)
/*********** CFG 2 ***********/
#define PADI_CFG_IO15_PC18                                          (PADI_IOCFG_IO_15_1)
#define PADI_IDX_IO15_PC18                                          (14)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO15_ATIN1_CH2                                     (PADI_IOCFG_IO_15_1)
#define PADI_IDX_IO15_ATIN1_CH2                                     (14)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO15_ATOUT1_CH2_N                                  (PADI_IOCFG_IO_15_1)
#define PADI_IDX_IO15_ATOUT1_CH2_N                                  (14)
/*********** CFG 3 ***********/
#define PADI_CFG_IO15_SPI2_RXD                                      (PADI_IOCFG_IO_15_1 | PADI_IOCFG_IO_15_0)
#define PADI_IDX_IO15_SPI2_RXD                                      (14)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO15_UART2_CTS                                     (PADI_IOCFG_IO_15_2 | PADI_IOCFG_IO_15_0)
#define PADI_IDX_IO15_UART2_CTS                                     (14)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO15_LED6                                          (PADI_IOCFG_IO_15_2 | PADI_IOCFG_IO_15_1 | PADI_IOCFG_IO_15_0)
#define PADI_IDX_IO15_LED6                                          (14)
/*********** CFG 8 ***********/
#define PADI_CFG_IO15_CH32                                          (PADI_IOCFG_IO_15_3)
#define PADI_IDX_IO15_CH32                                          (14)
/******************* IO 16 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO16_CTSU_SN_23                                    (0UL)
#define PADI_IDX_IO16_CTSU_SN_23                                    (15)
/*********** CFG 1 ***********/
#define PADI_CFG_IO16_PB26                                          (PADI_IOCFG_IO_16_0)
#define PADI_IDX_IO16_PB26                                          (15)
/*********** CFG 2 ***********/
#define PADI_CFG_IO16_PC19                                          (PADI_IOCFG_IO_16_1)
#define PADI_IDX_IO16_PC19                                          (15)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO16_ATOUT2_BRKOUT1                                (PADI_IOCFG_IO_16_1)
#define PADI_IDX_IO16_ATOUT2_BRKOUT1                                (15)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO16_UART2_RTS                                     (PADI_IOCFG_IO_16_2 | PADI_IOCFG_IO_16_0)
#define PADI_IDX_IO16_UART2_RTS                                     (15)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO16_GPIO_HIZ                                      (PADI_IOCFG_IO_16_2 | PADI_IOCFG_IO_16_1 | PADI_IOCFG_IO_16_0)
#define PADI_IDX_IO16_GPIO_HIZ                                      (15)
/*********** CFG 8 ***********/
#define PADI_CFG_IO16_CH31                                          (PADI_IOCFG_IO_16_3)
#define PADI_IDX_IO16_CH31                                          (15)
/******************* IO 17 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO17_CTSU_SN_22                                    (0UL)
#define PADI_IDX_IO17_CTSU_SN_22                                    (16)
/*********** CFG 1 ***********/
#define PADI_CFG_IO17_PA4                                           (PADI_IOCFG_IO_17_0)
#define PADI_IDX_IO17_PA4                                           (16)
/*********** CFG 2 ***********/
#define PADI_CFG_IO17_PB25                                          (PADI_IOCFG_IO_17_1)
#define PADI_IDX_IO17_PB25                                          (16)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO17_BTIN14                                        (PADI_IOCFG_IO_17_1)
#define PADI_IDX_IO17_BTIN14                                        (16)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO17_BTOUT14                                       (PADI_IOCFG_IO_17_1)
#define PADI_IDX_IO17_BTOUT14                                       (16)
/*********** CFG 3 ***********/
#define PADI_CFG_IO17_SWDIO                                         (PADI_IOCFG_IO_17_1 | PADI_IOCFG_IO_17_0)
#define PADI_IDX_IO17_SWDIO                                         (16)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO17_LED7                                          (PADI_IOCFG_IO_17_2 | PADI_IOCFG_IO_17_1 | PADI_IOCFG_IO_17_0)
#define PADI_IDX_IO17_LED7                                          (16)
/*********** CFG 8 ***********/
#define PADI_CFG_IO17_CH43                                          (PADI_IOCFG_IO_17_3)
#define PADI_IDX_IO17_CH43                                          (16)
/******************* IO 18 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO18_PA11                                          (PADI_IOCFG_IO_18_0)
#define PADI_IDX_IO18_PA11                                          (17)
/*********** CFG 2 ***********/
#define PADI_CFG_IO18_PC31                                          (PADI_IOCFG_IO_18_1)
#define PADI_IDX_IO18_PC31                                          (17)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO18_GTIN2_CH2                                     (PADI_IOCFG_IO_18_1)
#define PADI_IDX_IO18_GTIN2_CH2                                     (17)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO18_GTOUT2_CH2_P                                  (PADI_IOCFG_IO_18_1)
#define PADI_IDX_IO18_GTOUT2_CH2_P                                  (17)
/*********** CFG 3 ***********/
#define PADI_CFG_IO18_UART2_TX                                      (PADI_IOCFG_IO_18_1 | PADI_IOCFG_IO_18_0)
#define PADI_IDX_IO18_UART2_TX                                      (17)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO18_ATOUT2_CH1_P                                  (PADI_IOCFG_IO_18_2 | PADI_IOCFG_IO_18_0)
#define PADI_IDX_IO18_ATOUT2_CH1_P                                  (17)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO18_GPIO_HIZ                                      (PADI_IOCFG_IO_18_2 | PADI_IOCFG_IO_18_1 | PADI_IOCFG_IO_18_0)
#define PADI_IDX_IO18_GPIO_HIZ                                      (17)
/*********** CFG 8 ***********/
#define PADI_CFG_IO18_CH36                                          (PADI_IOCFG_IO_18_3)
#define PADI_IDX_IO18_CH36                                          (17)
/******************* IO 19 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO19_PA10                                          (PADI_IOCFG_IO_19_0)
#define PADI_IDX_IO19_PA10                                          (18)
/*********** CFG 2 ***********/
#define PADI_CFG_IO19_PC30                                          (PADI_IOCFG_IO_19_1)
#define PADI_IDX_IO19_PC30                                          (18)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO19_GTIN2_ETR                                     (PADI_IOCFG_IO_19_1)
#define PADI_IDX_IO19_GTIN2_ETR                                     (18)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO19_GTOUT2_CH3_P                                  (PADI_IOCFG_IO_19_1)
#define PADI_IDX_IO19_GTOUT2_CH3_P                                  (18)
/*********** CFG 3 ***********/
#define PADI_CFG_IO19_UART2_RX                                      (PADI_IOCFG_IO_19_1 | PADI_IOCFG_IO_19_0)
#define PADI_IDX_IO19_UART2_RX                                      (18)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO19_ATOUT2_CH1_N                                  (PADI_IOCFG_IO_19_2 | PADI_IOCFG_IO_19_0)
#define PADI_IDX_IO19_ATOUT2_CH1_N                                  (18)
/*********** CFG 6 ***********/
#define PADI_CFG_IO19_GTOUT2_CH2_N                                  (PADI_IOCFG_IO_19_2 | PADI_IOCFG_IO_19_1)
#define PADI_IDX_IO19_GTOUT2_CH2_N                                  (18)
/*********** CFG 7 ***********/
#define PADI_CFG_IO19_GPIO_HIZ                                      (PADI_IOCFG_IO_19_2 | PADI_IOCFG_IO_19_1 | PADI_IOCFG_IO_19_0)
#define PADI_IDX_IO19_GPIO_HIZ                                      (18)
/*********** CFG 8 ***********/
#define PADI_CFG_IO19_CH37                                          (PADI_IOCFG_IO_19_3)
#define PADI_IDX_IO19_CH37                                          (18)
/******************* IO 20 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO20_CTSU_SN_21                                    (0UL)
#define PADI_IDX_IO20_CTSU_SN_21                                    (19)
/*********** CFG 1 ***********/
#define PADI_CFG_IO20_PA9                                           (PADI_IOCFG_IO_20_0)
#define PADI_IDX_IO20_PA9                                           (19)
/*********** CFG 2 ***********/
#define PADI_CFG_IO20_PC29                                          (PADI_IOCFG_IO_20_1)
#define PADI_IDX_IO20_PC29                                          (19)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO20_GTIN3_CH2                                     (PADI_IOCFG_IO_20_1)
#define PADI_IDX_IO20_GTIN3_CH2                                     (19)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO20_GTOUT3_CH2_P                                  (PADI_IOCFG_IO_20_1)
#define PADI_IDX_IO20_GTOUT3_CH2_P                                  (19)
/*********** CFG 3 ***********/
#define PADI_CFG_IO20_I2C2_SCK                                      (PADI_IOCFG_IO_20_1 | PADI_IOCFG_IO_20_0)
#define PADI_IDX_IO20_I2C2_SCK                                      (19)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO20_ATOUT2_CH2_P                                  (PADI_IOCFG_IO_20_2 | PADI_IOCFG_IO_20_0)
#define PADI_IDX_IO20_ATOUT2_CH2_P                                  (19)
/*********** CFG 6 ***********/
#define PADI_CFG_IO20_PD31                                          (PADI_IOCFG_IO_20_2 | PADI_IOCFG_IO_20_1)
#define PADI_IDX_IO20_PD31                                          (19)
/*********** CFG 7 ***********/
#define PADI_CFG_IO20_GPIO_HIZ                                      (PADI_IOCFG_IO_20_2 | PADI_IOCFG_IO_20_1 | PADI_IOCFG_IO_20_0)
#define PADI_IDX_IO20_GPIO_HIZ                                      (19)
/*********** CFG 8 ***********/
#define PADI_CFG_IO20_CH11                                          (PADI_IOCFG_IO_20_3)
#define PADI_IDX_IO20_CH11                                          (19)
/******************* IO 21 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO21_CTSU_SN_20                                    (0UL)
#define PADI_IDX_IO21_CTSU_SN_20                                    (20)
/*********** CFG 1 ***********/
#define PADI_CFG_IO21_PA8                                           (PADI_IOCFG_IO_21_0)
#define PADI_IDX_IO21_PA8                                           (20)
/*********** CFG 2 ***********/
#define PADI_CFG_IO21_PC28                                          (PADI_IOCFG_IO_21_1)
#define PADI_IDX_IO21_PC28                                          (20)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO21_GTIN4_CH2                                     (PADI_IOCFG_IO_21_1)
#define PADI_IDX_IO21_GTIN4_CH2                                     (20)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO21_GTOUT4_CH2_P                                  (PADI_IOCFG_IO_21_1)
#define PADI_IDX_IO21_GTOUT4_CH2_P                                  (20)
/*********** CFG 3 ***********/
#define PADI_CFG_IO21_I2C2_SDA                                      (PADI_IOCFG_IO_21_1 | PADI_IOCFG_IO_21_0)
#define PADI_IDX_IO21_I2C2_SDA                                      (20)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO21_ATOUT2_CH2_N                                  (PADI_IOCFG_IO_21_2 | PADI_IOCFG_IO_21_0)
#define PADI_IDX_IO21_ATOUT2_CH2_N                                  (20)
/*********** CFG 6 ***********/
#define PADI_CFG_IO21_PD30                                          (PADI_IOCFG_IO_21_2 | PADI_IOCFG_IO_21_1)
#define PADI_IDX_IO21_PD30                                          (20)
/*********** CFG 7 ***********/
#define PADI_CFG_IO21_GPIO_HIZ                                      (PADI_IOCFG_IO_21_2 | PADI_IOCFG_IO_21_1 | PADI_IOCFG_IO_21_0)
#define PADI_IDX_IO21_GPIO_HIZ                                      (20)
/*********** CFG 8 ***********/
#define PADI_CFG_IO21_CH9                                           (PADI_IOCFG_IO_21_3)
#define PADI_IDX_IO21_CH9                                           (20)
/******************* IO 22 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO22_CTSU_SN_19                                    (0UL)
#define PADI_IDX_IO22_CTSU_SN_19                                    (21)
/*********** CFG 1 ***********/
#define PADI_CFG_IO22_PD29                                          (PADI_IOCFG_IO_22_0)
#define PADI_IDX_IO22_PD29                                          (21)
/*********** CFG 2 ***********/
#define PADI_CFG_IO22_PC27                                          (PADI_IOCFG_IO_22_1)
#define PADI_IDX_IO22_PC27                                          (21)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO22_GTIN2_CH1                                     (PADI_IOCFG_IO_22_1)
#define PADI_IDX_IO22_GTIN2_CH1                                     (21)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO22_GTOUT2_CH1_P                                  (PADI_IOCFG_IO_22_1)
#define PADI_IDX_IO22_GTOUT2_CH1_P                                  (21)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO22_SPI1_SS                                       (PADI_IOCFG_IO_22_2 | PADI_IOCFG_IO_22_1)
#define PADI_IDX_IO22_SPI1_SS                                       (21)
/*********** CFG 7 ***********/
#define PADI_CFG_IO22_GPIO_HIZ                                      (PADI_IOCFG_IO_22_2 | PADI_IOCFG_IO_22_1 | PADI_IOCFG_IO_22_0)
#define PADI_IDX_IO22_GPIO_HIZ                                      (21)
/*********** CFG 8 ***********/
#define PADI_CFG_IO22_CH28                                          (PADI_IOCFG_IO_22_3)
#define PADI_IDX_IO22_CH28                                          (21)
/******************* IO 23 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO23_CTSU_SN_18                                    (0UL)
#define PADI_IDX_IO23_CTSU_SN_18                                    (22)
/*********** CFG 1 ***********/
#define PADI_CFG_IO23_PD28                                          (PADI_IOCFG_IO_23_0)
#define PADI_IDX_IO23_PD28                                          (22)
/*********** CFG 2 ***********/
#define PADI_CFG_IO23_PC26                                          (PADI_IOCFG_IO_23_1)
#define PADI_IDX_IO23_PC26                                          (22)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO23_GTOUT2_CH1_N                                  (PADI_IOCFG_IO_23_1)
#define PADI_IDX_IO23_GTOUT2_CH1_N                                  (22)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO23_ATOUT1_BRKOUT2                                (PADI_IOCFG_IO_23_2 | PADI_IOCFG_IO_23_0)
#define PADI_IDX_IO23_ATOUT1_BRKOUT2                                (22)
/*********** CFG 6 ***********/
#define PADI_CFG_IO23_SPI1_TXD                                      (PADI_IOCFG_IO_23_2 | PADI_IOCFG_IO_23_1)
#define PADI_IDX_IO23_SPI1_TXD                                      (22)
/*********** CFG 7 ***********/
#define PADI_CFG_IO23_GPIO_HIZ                                      (PADI_IOCFG_IO_23_2 | PADI_IOCFG_IO_23_1 | PADI_IOCFG_IO_23_0)
#define PADI_IDX_IO23_GPIO_HIZ                                      (22)
/*********** CFG 8 ***********/
#define PADI_CFG_IO23_CH29                                          (PADI_IOCFG_IO_23_3)
#define PADI_IDX_IO23_CH29                                          (22)
/******************* IO 24 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO24_CTSU_SN_17                                    (0UL)
#define PADI_IDX_IO24_CTSU_SN_17                                    (23)
/*********** CFG 1 ***********/
#define PADI_CFG_IO24_PD27                                          (PADI_IOCFG_IO_24_0)
#define PADI_IDX_IO24_PD27                                          (23)
/*********** CFG 2 ***********/
#define PADI_CFG_IO24_PC25                                          (PADI_IOCFG_IO_24_1)
#define PADI_IDX_IO24_PC25                                          (23)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO24_GTIN2_CH4                                     (PADI_IOCFG_IO_24_1)
#define PADI_IDX_IO24_GTIN2_CH4                                     (23)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO24_GTOUT2_CH4                                    (PADI_IOCFG_IO_24_1)
#define PADI_IDX_IO24_GTOUT2_CH4                                    (23)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO24_ATOUT1_BRKOUT1                                (PADI_IOCFG_IO_24_2 | PADI_IOCFG_IO_24_0)
#define PADI_IDX_IO24_ATOUT1_BRKOUT1                                (23)
/*********** CFG 6 ***********/
#define PADI_CFG_IO24_SPI1_RXD                                      (PADI_IOCFG_IO_24_2 | PADI_IOCFG_IO_24_1)
#define PADI_IDX_IO24_SPI1_RXD                                      (23)
/*********** CFG 7 ***********/
#define PADI_CFG_IO24_GPIO_HIZ                                      (PADI_IOCFG_IO_24_2 | PADI_IOCFG_IO_24_1 | PADI_IOCFG_IO_24_0)
#define PADI_IDX_IO24_GPIO_HIZ                                      (23)
/*********** CFG 8 ***********/
#define PADI_CFG_IO24_CH30                                          (PADI_IOCFG_IO_24_3)
#define PADI_IDX_IO24_CH30                                          (23)
/******************* IO 25 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO25_CTSU_SN_16                                    (0UL)
#define PADI_IDX_IO25_CTSU_SN_16                                    (24)
/*********** CFG 1 ***********/
#define PADI_CFG_IO25_PD26                                          (PADI_IOCFG_IO_25_0)
#define PADI_IDX_IO25_PD26                                          (24)
/*********** CFG 2 ***********/
#define PADI_CFG_IO25_PC24                                          (PADI_IOCFG_IO_25_1)
#define PADI_IDX_IO25_PC24                                          (24)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO25_SWCLK                                         (PADI_IOCFG_IO_25_1 | PADI_IOCFG_IO_25_0)
#define PADI_IDX_IO25_SWCLK                                         (24)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO25_PB7                                           (PADI_IOCFG_IO_25_2 | PADI_IOCFG_IO_25_0)
#define PADI_IDX_IO25_PB7                                           (24)
/*********** CFG 6 ***********/
#define PADI_CFG_IO25_SPI1_SCK                                      (PADI_IOCFG_IO_25_2 | PADI_IOCFG_IO_25_1)
#define PADI_IDX_IO25_SPI1_SCK                                      (24)
/*********** CFG 7 ***********/
#define PADI_CFG_IO25_LED8                                          (PADI_IOCFG_IO_25_2 | PADI_IOCFG_IO_25_1 | PADI_IOCFG_IO_25_0)
#define PADI_IDX_IO25_LED8                                          (24)
/*********** CFG 8 ***********/
#define PADI_CFG_IO25_CH38                                          (PADI_IOCFG_IO_25_3)
#define PADI_IDX_IO25_CH38                                          (24)
/******************* IO 26 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO26_CH2P                                          (0UL)
#define PADI_IDX_IO26_CH2P                                          (25)
/*********** CFG 1 ***********/
#define PADI_CFG_IO26_PD25                                          (PADI_IOCFG_IO_26_0)
#define PADI_IDX_IO26_PD25                                          (25)
/*********** CFG 2 ***********/
#define PADI_CFG_IO26_PB6                                           (PADI_IOCFG_IO_26_1)
#define PADI_IDX_IO26_PB6                                           (25)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO26_BTIN23                                        (PADI_IOCFG_IO_26_1)
#define PADI_IDX_IO26_BTIN23                                        (25)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO26_BTOUT23                                       (PADI_IOCFG_IO_26_1)
#define PADI_IDX_IO26_BTOUT23                                       (25)
/*********** CFG 3 ***********/
#define PADI_CFG_IO26_SWDIO                                         (PADI_IOCFG_IO_26_1 | PADI_IOCFG_IO_26_0)
#define PADI_IDX_IO26_SWDIO                                         (25)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO26_GPIO_HIZ                                      (PADI_IOCFG_IO_26_2 | PADI_IOCFG_IO_26_1 | PADI_IOCFG_IO_26_0)
#define PADI_IDX_IO26_GPIO_HIZ                                      (25)
/*********** CFG 8 ***********/
#define PADI_CFG_IO26_CH17                                          (PADI_IOCFG_IO_26_3)
#define PADI_IDX_IO26_CH17                                          (25)
/******************* IO 27 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO27_CH2N                                          (0UL)
#define PADI_IDX_IO27_CH2N                                          (26)
/*********** CFG 1 ***********/
#define PADI_CFG_IO27_PD24                                          (PADI_IOCFG_IO_27_0)
#define PADI_IDX_IO27_PD24                                          (26)
/*********** CFG 2 ***********/
#define PADI_CFG_IO27_PB5                                           (PADI_IOCFG_IO_27_1)
#define PADI_IDX_IO27_PB5                                           (26)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO27_BTIN22                                        (PADI_IOCFG_IO_27_1)
#define PADI_IDX_IO27_BTIN22                                        (26)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO27_BTOUT22                                       (PADI_IOCFG_IO_27_1)
#define PADI_IDX_IO27_BTOUT22                                       (26)
/*********** CFG 3 ***********/
#define PADI_CFG_IO27_SWCLK                                         (PADI_IOCFG_IO_27_1 | PADI_IOCFG_IO_27_0)
#define PADI_IDX_IO27_SWCLK                                         (26)
/*********** CFG 4 ***********/
#define PADI_CFG_IO27_ATOUT2_BRKOUT2                                (PADI_IOCFG_IO_27_2)
#define PADI_IDX_IO27_ATOUT2_BRKOUT2                                (26)
/*********** CFG 5 ***********/
#define PADI_CFG_IO27_PC6                                           (PADI_IOCFG_IO_27_2 | PADI_IOCFG_IO_27_0)
#define PADI_IDX_IO27_PC6                                           (26)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO27_GPIO_HIZ                                      (PADI_IOCFG_IO_27_2 | PADI_IOCFG_IO_27_1 | PADI_IOCFG_IO_27_0)
#define PADI_IDX_IO27_GPIO_HIZ                                      (26)
/*********** CFG 8 ***********/
#define PADI_CFG_IO27_CH16                                          (PADI_IOCFG_IO_27_3)
#define PADI_IDX_IO27_CH16                                          (26)
/******************* IO 28 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO28_CTSU_SN_15                                    (0UL)
#define PADI_IDX_IO28_CTSU_SN_15                                    (27)
/*********** CFG 1 ***********/
#define PADI_CFG_IO28_PA3                                           (PADI_IOCFG_IO_28_0)
#define PADI_IDX_IO28_PA3                                           (27)
/*********** CFG 2 ***********/
#define PADI_CFG_IO28_PB24                                          (PADI_IOCFG_IO_28_1)
#define PADI_IDX_IO28_PB24                                          (27)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO28_ATIN1_ETR                                     (PADI_IOCFG_IO_28_1)
#define PADI_IDX_IO28_ATIN1_ETR                                     (27)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO28_ATOUT1_CH3_P                                  (PADI_IOCFG_IO_28_1)
#define PADI_IDX_IO28_ATOUT1_CH3_P                                  (27)
/*********** CFG 3 ***********/
#define PADI_CFG_IO28_I2C1_SCK                                      (PADI_IOCFG_IO_28_1 | PADI_IOCFG_IO_28_0)
#define PADI_IDX_IO28_I2C1_SCK                                      (27)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO28_PC7                                           (PADI_IOCFG_IO_28_2 | PADI_IOCFG_IO_28_0)
#define PADI_IDX_IO28_PC7                                           (27)
/*********** CFG 6 ***********/
#define PADI_CFG_IO28_SPI1_RXD                                      (PADI_IOCFG_IO_28_2 | PADI_IOCFG_IO_28_1)
#define PADI_IDX_IO28_SPI1_RXD                                      (27)
/*********** CFG 7 ***********/
#define PADI_CFG_IO28_GPIO_HIZ                                      (PADI_IOCFG_IO_28_2 | PADI_IOCFG_IO_28_1 | PADI_IOCFG_IO_28_0)
#define PADI_IDX_IO28_GPIO_HIZ                                      (27)
/*********** CFG 8 ***********/
#define PADI_CFG_IO28_COMP1_P                                       (PADI_IOCFG_IO_28_3)
#define PADI_IDX_IO28_COMP1_P                                       (27)
/******************* IO 29 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO29_CTSU_SN_14                                    (0UL)
#define PADI_IDX_IO29_CTSU_SN_14                                    (28)
/*********** CFG 1 ***********/
#define PADI_CFG_IO29_PA1                                           (PADI_IOCFG_IO_29_0)
#define PADI_IDX_IO29_PA1                                           (28)
/*********** CFG 2 ***********/
#define PADI_CFG_IO29_PC8                                           (PADI_IOCFG_IO_29_1)
#define PADI_IDX_IO29_PC8                                           (28)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO29_GTIN1_ETR                                     (PADI_IOCFG_IO_29_1)
#define PADI_IDX_IO29_GTIN1_ETR                                     (28)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO29_ATOUT1_CH3_N                                  (PADI_IOCFG_IO_29_1)
#define PADI_IDX_IO29_ATOUT1_CH3_N                                  (28)
/*********** CFG 3 ***********/
#define PADI_CFG_IO29_I2C1_SDA                                      (PADI_IOCFG_IO_29_1 | PADI_IOCFG_IO_29_0)
#define PADI_IDX_IO29_I2C1_SDA                                      (28)
/*********** CFG 4 ***********/
#define PADI_CFG_IO29_SWDIO                                         (PADI_IOCFG_IO_29_2)
#define PADI_IDX_IO29_SWDIO                                         (28)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO29_SPI1_TXD                                      (PADI_IOCFG_IO_29_2 | PADI_IOCFG_IO_29_1)
#define PADI_IDX_IO29_SPI1_TXD                                      (28)
/*********** CFG 7 ***********/
#define PADI_CFG_IO29_GPIO_HIZ                                      (PADI_IOCFG_IO_29_2 | PADI_IOCFG_IO_29_1 | PADI_IOCFG_IO_29_0)
#define PADI_IDX_IO29_GPIO_HIZ                                      (28)
/*********** CFG 8 ***********/
#define PADI_CFG_IO29_COMP1_N                                       (PADI_IOCFG_IO_29_3)
#define PADI_IDX_IO29_COMP1_N                                       (28)
/******************* IO 30 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO30_DACOUT0                                       (0UL)
#define PADI_IDX_IO30_DACOUT0                                       (29)
/*********** CFG 1 ***********/
#define PADI_CFG_IO30_PA2                                           (PADI_IOCFG_IO_30_0)
#define PADI_IDX_IO30_PA2                                           (29)
/*********** CFG 2 ***********/
#define PADI_CFG_IO30_PC9                                           (PADI_IOCFG_IO_30_1)
#define PADI_IDX_IO30_PC9                                           (29)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO30_ATIN1_BRKIN1                                  (PADI_IOCFG_IO_30_1)
#define PADI_IDX_IO30_ATIN1_BRKIN1                                  (29)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO30_GTOUT1_CH1_N                                  (PADI_IOCFG_IO_30_1)
#define PADI_IDX_IO30_GTOUT1_CH1_N                                  (29)
/*********** CFG 3 ***********/
#define PADI_CFG_IO30_O_COMP1                                       (PADI_IOCFG_IO_30_1 | PADI_IOCFG_IO_30_0)
#define PADI_IDX_IO30_O_COMP1                                       (29)
/*********** CFG 4 ***********/
#define PADI_CFG_IO30_SWCLK                                         (PADI_IOCFG_IO_30_2)
#define PADI_IDX_IO30_SWCLK                                         (29)
/*********** CFG 5 ***********/
#define PADI_CFG_IO30_PROBE_OCLK                                    (PADI_IOCFG_IO_30_2 | PADI_IOCFG_IO_30_0)
#define PADI_IDX_IO30_PROBE_OCLK                                    (29)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO30_GPIO_HIZ                                      (PADI_IOCFG_IO_30_2 | PADI_IOCFG_IO_30_1 | PADI_IOCFG_IO_30_0)
#define PADI_IDX_IO30_GPIO_HIZ                                      (29)
/*********** CFG 8 ***********/
#define PADI_CFG_IO30_CH6                                           (PADI_IOCFG_IO_30_3)
#define PADI_IDX_IO30_CH6                                           (29)
/******************* IO 31 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO31_CH1P                                          (0UL)
#define PADI_IDX_IO31_CH1P                                          (30)
/*********** CFG 1 ***********/
#define PADI_CFG_IO31_PA10                                          (PADI_IOCFG_IO_31_0)
#define PADI_IDX_IO31_PA10                                          (30)
/*********** CFG 2 ***********/
#define PADI_CFG_IO31_PC10                                          (PADI_IOCFG_IO_31_1)
#define PADI_IDX_IO31_PC10                                          (30)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO31_GPIO_HIZ                                      (PADI_IOCFG_IO_31_2 | PADI_IOCFG_IO_31_1 | PADI_IOCFG_IO_31_0)
#define PADI_IDX_IO31_GPIO_HIZ                                      (30)
/*********** CFG 8 ***********/
#define PADI_CFG_IO31_CH15                                          (PADI_IOCFG_IO_31_3)
#define PADI_IDX_IO31_CH15                                          (30)
/******************* IO 32 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO32_CH1N                                          (0UL)
#define PADI_IDX_IO32_CH1N                                          (31)
/*********** CFG 1 ***********/
#define PADI_CFG_IO32_PA11                                          (PADI_IOCFG_IO_32_0)
#define PADI_IDX_IO32_PA11                                          (31)
/*********** CFG 2 ***********/
#define PADI_CFG_IO32_PC11                                          (PADI_IOCFG_IO_32_1)
#define PADI_IDX_IO32_PC11                                          (31)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO32_GPIO_HIZ                                      (PADI_IOCFG_IO_32_2 | PADI_IOCFG_IO_32_1 | PADI_IOCFG_IO_32_0)
#define PADI_IDX_IO32_GPIO_HIZ                                      (31)
/*********** CFG 8 ***********/
#define PADI_CFG_IO32_CH14                                          (PADI_IOCFG_IO_32_3)
#define PADI_IDX_IO32_CH14                                          (31)
/******************* IO 33 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO33_CH0P                                          (0UL)
#define PADI_IDX_IO33_CH0P                                          (32)
/*********** CFG 1 ***********/
#define PADI_CFG_IO33_PB27                                          (PADI_IOCFG_IO_33_0)
#define PADI_IDX_IO33_PB27                                          (32)
/*********** CFG 2 ***********/
#define PADI_CFG_IO33_PC12                                          (PADI_IOCFG_IO_33_1)
#define PADI_IDX_IO33_PC12                                          (32)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO33_GPIO_HIZ                                      (PADI_IOCFG_IO_33_2 | PADI_IOCFG_IO_33_1 | PADI_IOCFG_IO_33_0)
#define PADI_IDX_IO33_GPIO_HIZ                                      (32)
/*********** CFG 8 ***********/
#define PADI_CFG_IO33_CH13                                          (PADI_IOCFG_IO_33_3)
#define PADI_IDX_IO33_CH13                                          (32)
/******************* IO 34 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO34_CH0N                                          (0UL)
#define PADI_IDX_IO34_CH0N                                          (33)
/*********** CFG 1 ***********/
#define PADI_CFG_IO34_PD21                                          (PADI_IOCFG_IO_34_0)
#define PADI_IDX_IO34_PD21                                          (33)
/*********** CFG 2 ***********/
#define PADI_CFG_IO34_PC13                                          (PADI_IOCFG_IO_34_1)
#define PADI_IDX_IO34_PC13                                          (33)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
#define PADI_CFG_IO34_SPI1_SCK                                      (PADI_IOCFG_IO_34_1 | PADI_IOCFG_IO_34_0)
#define PADI_IDX_IO34_SPI1_SCK                                      (33)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO34_GPIO_HIZ                                      (PADI_IOCFG_IO_34_2 | PADI_IOCFG_IO_34_1 | PADI_IOCFG_IO_34_0)
#define PADI_IDX_IO34_GPIO_HIZ                                      (33)
/*********** CFG 8 ***********/
#define PADI_CFG_IO34_CH12                                          (PADI_IOCFG_IO_34_3)
#define PADI_IDX_IO34_CH12                                          (33)
/******************* IO 35 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO35_CTSU_SN_13                                    (0UL)
#define PADI_IDX_IO35_CTSU_SN_13                                    (34)
/*********** CFG 1 ***********/
#define PADI_CFG_IO35_PD20                                          (PADI_IOCFG_IO_35_0)
#define PADI_IDX_IO35_PD20                                          (34)
/*********** CFG 2 ***********/
#define PADI_CFG_IO35_PB15                                          (PADI_IOCFG_IO_35_1)
#define PADI_IDX_IO35_PB15                                          (34)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO35_ATIN1_CH2                                     (PADI_IOCFG_IO_35_1)
#define PADI_IDX_IO35_ATIN1_CH2                                     (34)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO35_ATOUT1_CH2_P                                  (PADI_IOCFG_IO_35_1)
#define PADI_IDX_IO35_ATOUT1_CH2_P                                  (34)
/*********** CFG 3 ***********/
#define PADI_CFG_IO35_UART3_TX                                      (PADI_IOCFG_IO_35_1 | PADI_IOCFG_IO_35_0)
#define PADI_IDX_IO35_UART3_TX                                      (34)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO35_FLASH_JTAG_TMS                                (PADI_IOCFG_IO_35_2 | PADI_IOCFG_IO_35_0)
#define PADI_IDX_IO35_FLASH_JTAG_TMS                                (34)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO35_GPIO_HIZ                                      (PADI_IOCFG_IO_35_2 | PADI_IOCFG_IO_35_1 | PADI_IOCFG_IO_35_0)
#define PADI_IDX_IO35_GPIO_HIZ                                      (34)
/*********** CFG 8 ***********/
#define PADI_CFG_IO35_COMP2_P                                       (PADI_IOCFG_IO_35_3)
#define PADI_IDX_IO35_COMP2_P                                       (34)
/******************* IO 36 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO36_CTSU_SN_12                                    (0UL)
#define PADI_IDX_IO36_CTSU_SN_12                                    (35)
/*********** CFG 1 ***********/
#define PADI_CFG_IO36_PA5                                           (PADI_IOCFG_IO_36_0)
#define PADI_IDX_IO36_PA5                                           (35)
/*********** CFG 2 ***********/
#define PADI_CFG_IO36_PB14                                          (PADI_IOCFG_IO_36_1)
#define PADI_IDX_IO36_PB14                                          (35)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO36_BTIN12                                        (PADI_IOCFG_IO_36_1)
#define PADI_IDX_IO36_BTIN12                                        (35)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO36_ATOUT1_CH2_N                                  (PADI_IOCFG_IO_36_1)
#define PADI_IDX_IO36_ATOUT1_CH2_N                                  (35)
/*********** CFG 3 ***********/
#define PADI_CFG_IO36_UART3_RX                                      (PADI_IOCFG_IO_36_1 | PADI_IOCFG_IO_36_0)
#define PADI_IDX_IO36_UART3_RX                                      (35)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO36_FLASH_JTAG_TCK                                (PADI_IOCFG_IO_36_2 | PADI_IOCFG_IO_36_0)
#define PADI_IDX_IO36_FLASH_JTAG_TCK                                (35)
/*********** CFG 6 ***********/
#define PADI_CFG_IO36_SPI2_SS                                       (PADI_IOCFG_IO_36_2 | PADI_IOCFG_IO_36_1)
#define PADI_IDX_IO36_SPI2_SS                                       (35)
/*********** CFG 7 ***********/
#define PADI_CFG_IO36_GPIO_HIZ                                      (PADI_IOCFG_IO_36_2 | PADI_IOCFG_IO_36_1 | PADI_IOCFG_IO_36_0)
#define PADI_IDX_IO36_GPIO_HIZ                                      (35)
/*********** CFG 8 ***********/
#define PADI_CFG_IO36_COMP2_N                                       (PADI_IOCFG_IO_36_3)
#define PADI_IDX_IO36_COMP2_N                                       (35)
/******************* IO 37 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO37_PA31                                          (PADI_IOCFG_IO_37_0)
#define PADI_IDX_IO37_PA31                                          (36)
/*********** CFG 2 ***********/
#define PADI_CFG_IO37_PB13                                          (PADI_IOCFG_IO_37_1)
#define PADI_IDX_IO37_PB13                                          (36)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO37_BTIN13                                        (PADI_IOCFG_IO_37_1)
#define PADI_IDX_IO37_BTIN13                                        (36)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO37_BTOUT13                                       (PADI_IOCFG_IO_37_1)
#define PADI_IDX_IO37_BTOUT13                                       (36)
/*********** CFG 3 ***********/
#define PADI_CFG_IO37_O_COMP2                                       (PADI_IOCFG_IO_37_1 | PADI_IOCFG_IO_37_0)
#define PADI_IDX_IO37_O_COMP2                                       (36)
/*********** CFG 4 ***********/
#define PADI_CFG_IO37_GTIN1_ETR                                     (PADI_IOCFG_IO_37_2)
#define PADI_IDX_IO37_GTIN1_ETR                                     (36)
/*********** CFG 5 ***********/
#define PADI_CFG_IO37_I2C2_SCK                                      (PADI_IOCFG_IO_37_2 | PADI_IOCFG_IO_37_0)
#define PADI_IDX_IO37_I2C2_SCK                                      (36)
/*********** CFG 6 ***********/
#define PADI_CFG_IO37_SWCLK_BOOT0                                   (PADI_IOCFG_IO_37_2 | PADI_IOCFG_IO_37_1)
#define PADI_IDX_IO37_SWCLK_BOOT0                                   (36)
/*********** CFG 7 ***********/
/*********** CFG 8 ***********/
#define PADI_CFG_IO37_CH5                                           (PADI_IOCFG_IO_37_3)
#define PADI_IDX_IO37_CH5                                           (36)
/******************* IO 38 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO38_CTSU_SN_11                                    (0UL)
#define PADI_IDX_IO38_CTSU_SN_11                                    (37)
/*********** CFG 1 ***********/
#define PADI_CFG_IO38_PD19                                          (PADI_IOCFG_IO_38_0)
#define PADI_IDX_IO38_PD19                                          (37)
/*********** CFG 2 ***********/
#define PADI_CFG_IO38_PB12                                          (PADI_IOCFG_IO_38_1)
#define PADI_IDX_IO38_PB12                                          (37)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO38_BTIN14                                        (PADI_IOCFG_IO_38_1)
#define PADI_IDX_IO38_BTIN14                                        (37)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO38_ATOUT1_CH1_P                                  (PADI_IOCFG_IO_38_1)
#define PADI_IDX_IO38_ATOUT1_CH1_P                                  (37)
/*********** CFG 3 ***********/
#define PADI_CFG_IO38_UART2_RX                                      (PADI_IOCFG_IO_38_1 | PADI_IOCFG_IO_38_0)
#define PADI_IDX_IO38_UART2_RX                                      (37)
/*********** CFG 4 ***********/
#define PADI_CFG_IO38_I2C1_SCK                                      (PADI_IOCFG_IO_38_2)
#define PADI_IDX_IO38_I2C1_SCK                                      (37)
/*********** CFG 5 ***********/
#define PADI_CFG_IO38_I2C2_SDA                                      (PADI_IOCFG_IO_38_2 | PADI_IOCFG_IO_38_0)
#define PADI_IDX_IO38_I2C2_SDA                                      (37)
/*********** CFG 6 ***********/
#define PADI_CFG_IO38_SPI2_RXD                                      (PADI_IOCFG_IO_38_2 | PADI_IOCFG_IO_38_1)
#define PADI_IDX_IO38_SPI2_RXD                                      (37)
/*********** CFG 7 ***********/
#define PADI_CFG_IO38_GPIO_HIZ                                      (PADI_IOCFG_IO_38_2 | PADI_IOCFG_IO_38_1 | PADI_IOCFG_IO_38_0)
#define PADI_IDX_IO38_GPIO_HIZ                                      (37)
/*********** CFG 8 ***********/
#define PADI_CFG_IO38_COMP3_P                                       (PADI_IOCFG_IO_38_3)
#define PADI_IDX_IO38_COMP3_P                                       (37)
/******************* IO 39 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO39_CTSU_SN_10                                    (0UL)
#define PADI_IDX_IO39_CTSU_SN_10                                    (38)
/*********** CFG 1 ***********/
#define PADI_CFG_IO39_PD18                                          (PADI_IOCFG_IO_39_0)
#define PADI_IDX_IO39_PD18                                          (38)
/*********** CFG 2 ***********/
#define PADI_CFG_IO39_PB11                                          (PADI_IOCFG_IO_39_1)
#define PADI_IDX_IO39_PB11                                          (38)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO39_BTIN21                                        (PADI_IOCFG_IO_39_1)
#define PADI_IDX_IO39_BTIN21                                        (38)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO39_ATOUT1_CH1_N                                  (PADI_IOCFG_IO_39_1)
#define PADI_IDX_IO39_ATOUT1_CH1_N                                  (38)
/*********** CFG 3 ***********/
#define PADI_CFG_IO39_UART2_TX                                      (PADI_IOCFG_IO_39_1 | PADI_IOCFG_IO_39_0)
#define PADI_IDX_IO39_UART2_TX                                      (38)
/*********** CFG 4 ***********/
#define PADI_CFG_IO39_I2C1_SDA                                      (PADI_IOCFG_IO_39_2)
#define PADI_IDX_IO39_I2C1_SDA                                      (38)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO39_SPI2_TXD                                      (PADI_IOCFG_IO_39_2 | PADI_IOCFG_IO_39_1)
#define PADI_IDX_IO39_SPI2_TXD                                      (38)
/*********** CFG 7 ***********/
#define PADI_CFG_IO39_GPIO_HIZ                                      (PADI_IOCFG_IO_39_2 | PADI_IOCFG_IO_39_1 | PADI_IOCFG_IO_39_0)
#define PADI_IDX_IO39_GPIO_HIZ                                      (38)
/*********** CFG 8 ***********/
#define PADI_CFG_IO39_COMP3_N                                       (PADI_IOCFG_IO_39_3)
#define PADI_IDX_IO39_COMP3_N                                       (38)
/******************* IO 40 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO40_DACOUT1                                       (0UL)
#define PADI_IDX_IO40_DACOUT1                                       (39)
/*********** CFG 1 ***********/
#define PADI_CFG_IO40_PA30                                          (PADI_IOCFG_IO_40_0)
#define PADI_IDX_IO40_PA30                                          (39)
/*********** CFG 2 ***********/
#define PADI_CFG_IO40_PB10                                          (PADI_IOCFG_IO_40_1)
#define PADI_IDX_IO40_PB10                                          (39)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO40_BTIN22                                        (PADI_IOCFG_IO_40_1)
#define PADI_IDX_IO40_BTIN22                                        (39)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO40_BTOUT22                                       (PADI_IOCFG_IO_40_1)
#define PADI_IDX_IO40_BTOUT22                                       (39)
/*********** CFG 3 ***********/
#define PADI_CFG_IO40_SPI1_TXD                                      (PADI_IOCFG_IO_40_1 | PADI_IOCFG_IO_40_0)
#define PADI_IDX_IO40_SPI1_TXD                                      (39)
/*********** CFG 4 ***********/
#define PADI_CFG_IO40_O_COMP3                                       (PADI_IOCFG_IO_40_2)
#define PADI_IDX_IO40_O_COMP3                                       (39)
/*********** CFG 5 ***********/
#define PADI_CFG_IO40_UART3_TX                                      (PADI_IOCFG_IO_40_2 | PADI_IOCFG_IO_40_0)
#define PADI_IDX_IO40_UART3_TX                                      (39)
/*********** CFG 6 ***********/
#define PADI_CFG_IO40_SWDIO                                         (PADI_IOCFG_IO_40_2 | PADI_IOCFG_IO_40_1)
#define PADI_IDX_IO40_SWDIO                                         (39)
/*********** CFG 7 ***********/
#define PADI_CFG_IO40_GPIO_HIZ                                      (PADI_IOCFG_IO_40_2 | PADI_IOCFG_IO_40_1 | PADI_IOCFG_IO_40_0)
#define PADI_IDX_IO40_GPIO_HIZ                                      (39)
/*********** CFG 8 ***********/
#define PADI_CFG_IO40_CH4                                           (PADI_IOCFG_IO_40_3)
#define PADI_IDX_IO40_CH4                                           (39)
/******************* IO 41 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO41_CH3N_COMP4_N_CTSU_SN_9                        (0UL)
#define PADI_IDX_IO41_CH3N_COMP4_N_CTSU_SN_9                        (40)
/*********** CFG 1 ***********/
#define PADI_CFG_IO41_PA29                                          (PADI_IOCFG_IO_41_0)
#define PADI_IDX_IO41_PA29                                          (40)
/*********** CFG 2 ***********/
#define PADI_CFG_IO41_PB9                                           (PADI_IOCFG_IO_41_1)
#define PADI_IDX_IO41_PB9                                           (40)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO41_BTIN11                                        (PADI_IOCFG_IO_41_1)
#define PADI_IDX_IO41_BTIN11                                        (40)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO41_BTOUT11                                       (PADI_IOCFG_IO_41_1)
#define PADI_IDX_IO41_BTOUT11                                       (40)
/*********** CFG 3 ***********/
#define PADI_CFG_IO41_SPI1_RXD                                      (PADI_IOCFG_IO_41_1 | PADI_IOCFG_IO_41_0)
#define PADI_IDX_IO41_SPI1_RXD                                      (40)
/*********** CFG 4 ***********/
#define PADI_CFG_IO41_I2C2_SDA                                      (PADI_IOCFG_IO_41_2)
#define PADI_IDX_IO41_I2C2_SDA                                      (40)
/*********** CFG 5 ***********/
#define PADI_CFG_IO41_UART3_RX                                      (PADI_IOCFG_IO_41_2 | PADI_IOCFG_IO_41_0)
#define PADI_IDX_IO41_UART3_RX                                      (40)
/*********** CFG 6 ***********/
#define PADI_CFG_IO41_SPI2_SCK_BOOT1                                (PADI_IOCFG_IO_41_2 | PADI_IOCFG_IO_41_1)
#define PADI_IDX_IO41_SPI2_SCK_BOOT1                                (40)
/*********** CFG 7 ***********/
/*********** CFG 8 ***********/
#define PADI_CFG_IO41_CH27                                          (PADI_IOCFG_IO_41_3)
#define PADI_IDX_IO41_CH27                                          (40)
/******************* IO 42 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO42_CH3P_COMP4_P                                  (0UL)
#define PADI_IDX_IO42_CH3P_COMP4_P                                  (41)
/*********** CFG 1 ***********/
#define PADI_CFG_IO42_PA28                                          (PADI_IOCFG_IO_42_0)
#define PADI_IDX_IO42_PA28                                          (41)
/*********** CFG 2 ***********/
#define PADI_CFG_IO42_PB8                                           (PADI_IOCFG_IO_42_1)
#define PADI_IDX_IO42_PB8                                           (41)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO42_BTIN12                                        (PADI_IOCFG_IO_42_1)
#define PADI_IDX_IO42_BTIN12                                        (41)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO42_BTOUT12                                       (PADI_IOCFG_IO_42_1)
#define PADI_IDX_IO42_BTOUT12                                       (41)
/*********** CFG 3 ***********/
#define PADI_CFG_IO42_SPI1_SCK                                      (PADI_IOCFG_IO_42_1 | PADI_IOCFG_IO_42_0)
#define PADI_IDX_IO42_SPI1_SCK                                      (41)
/*********** CFG 4 ***********/
#define PADI_CFG_IO42_I2C2_SCK                                      (PADI_IOCFG_IO_42_2)
#define PADI_IDX_IO42_I2C2_SCK                                      (41)
/*********** CFG 5 ***********/
#define PADI_CFG_IO42_FLASH_JTAG_TDI                                (PADI_IOCFG_IO_42_2 | PADI_IOCFG_IO_42_0)
#define PADI_IDX_IO42_FLASH_JTAG_TDI                                (41)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO42_GPIO_HIZ                                      (PADI_IOCFG_IO_42_2 | PADI_IOCFG_IO_42_1 | PADI_IOCFG_IO_42_0)
#define PADI_IDX_IO42_GPIO_HIZ                                      (41)
/*********** CFG 8 ***********/
#define PADI_CFG_IO42_CH3                                           (PADI_IOCFG_IO_42_3)
#define PADI_IDX_IO42_CH3                                           (41)
/******************* IO 43 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO43_CTSU_SN_8                                     (0UL)
#define PADI_IDX_IO43_CTSU_SN_8                                     (42)
/*********** CFG 1 ***********/
#define PADI_CFG_IO43_PA27                                          (PADI_IOCFG_IO_43_0)
#define PADI_IDX_IO43_PA27                                          (42)
/*********** CFG 2 ***********/
#define PADI_CFG_IO43_PD22                                          (PADI_IOCFG_IO_43_1)
#define PADI_IDX_IO43_PD22                                          (42)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO43_GTIN1_CH1                                     (PADI_IOCFG_IO_43_1)
#define PADI_IDX_IO43_GTIN1_CH1                                     (42)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO43_GTOUT1_CH1_P                                  (PADI_IOCFG_IO_43_1)
#define PADI_IDX_IO43_GTOUT1_CH1_P                                  (42)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO43_GPIO_HIZ                                      (PADI_IOCFG_IO_43_2 | PADI_IOCFG_IO_43_1 | PADI_IOCFG_IO_43_0)
#define PADI_IDX_IO43_GPIO_HIZ                                      (42)
/*********** CFG 8 ***********/
#define PADI_CFG_IO43_CH39                                          (PADI_IOCFG_IO_43_3)
#define PADI_IDX_IO43_CH39                                          (42)
/******************* IO 44 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO44_CTSU_CAP                                      (0UL)
#define PADI_IDX_IO44_CTSU_CAP                                      (43)
/*********** CFG 1 ***********/
#define PADI_CFG_IO44_PA26                                          (PADI_IOCFG_IO_44_0)
#define PADI_IDX_IO44_PA26                                          (43)
/*********** CFG 2 ***********/
#define PADI_CFG_IO44_PD23                                          (PADI_IOCFG_IO_44_1)
#define PADI_IDX_IO44_PD23                                          (43)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO44_ATIN1_CH4                                     (PADI_IOCFG_IO_44_1)
#define PADI_IDX_IO44_ATIN1_CH4                                     (43)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO44_ATOUT1_CH4                                    (PADI_IOCFG_IO_44_1)
#define PADI_IDX_IO44_ATOUT1_CH4                                    (43)
/*********** CFG 3 ***********/
#define PADI_CFG_IO44_SPI1_SS                                       (PADI_IOCFG_IO_44_1 | PADI_IOCFG_IO_44_0)
#define PADI_IDX_IO44_SPI1_SS                                       (43)
/*********** CFG 4 ***********/
#define PADI_CFG_IO44_O_COMP4                                       (PADI_IOCFG_IO_44_2)
#define PADI_IDX_IO44_O_COMP4                                       (43)
/*********** CFG 5 ***********/
#define PADI_CFG_IO44_FLASH_JTAG_TDO                                (PADI_IOCFG_IO_44_2 | PADI_IOCFG_IO_44_0)
#define PADI_IDX_IO44_FLASH_JTAG_TDO                                (43)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO44_GPIO_HIZ                                      (PADI_IOCFG_IO_44_2 | PADI_IOCFG_IO_44_1 | PADI_IOCFG_IO_44_0)
#define PADI_IDX_IO44_GPIO_HIZ                                      (43)
/*********** CFG 8 ***********/
#define PADI_CFG_IO44_CH40                                          (PADI_IOCFG_IO_44_3)
#define PADI_IDX_IO44_CH40                                          (43)
/******************* IO 45 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO45_CH0P_CH20                                     (0UL)
#define PADI_IDX_IO45_CH0P_CH20                                     (44)
/*********** CFG 1 ***********/
#define PADI_CFG_IO45_PA25                                          (PADI_IOCFG_IO_45_0)
#define PADI_IDX_IO45_PA25                                          (44)
/*********** CFG 2 ***********/
#define PADI_CFG_IO45_PB23                                          (PADI_IOCFG_IO_45_1)
#define PADI_IDX_IO45_PB23                                          (44)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO45_GTOUT1_CH4                                    (PADI_IOCFG_IO_45_2 | PADI_IOCFG_IO_45_0)
#define PADI_IDX_IO45_GTOUT1_CH4                                    (44)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO45_GPIO_HIZ                                      (PADI_IOCFG_IO_45_2 | PADI_IOCFG_IO_45_1 | PADI_IOCFG_IO_45_0)
#define PADI_IDX_IO45_GPIO_HIZ                                      (44)
/*********** CFG 8 ***********/
#define PADI_CFG_IO45_CTSU_SN_7                                     (PADI_IOCFG_IO_45_3)
#define PADI_IDX_IO45_CTSU_SN_7                                     (44)
/******************* IO 46 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO46_CH1P_CH21                                     (0UL)
#define PADI_IDX_IO46_CH1P_CH21                                     (45)
/*********** CFG 1 ***********/
#define PADI_CFG_IO46_PA24                                          (PADI_IOCFG_IO_46_0)
#define PADI_IDX_IO46_PA24                                          (45)
/*********** CFG 2 ***********/
#define PADI_CFG_IO46_PB22                                          (PADI_IOCFG_IO_46_1)
#define PADI_IDX_IO46_PB22                                          (45)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO46_GTOUT2_CH2_P                                  (PADI_IOCFG_IO_46_2 | PADI_IOCFG_IO_46_0)
#define PADI_IDX_IO46_GTOUT2_CH2_P                                  (45)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO46_GPIO_HIZ                                      (PADI_IOCFG_IO_46_2 | PADI_IOCFG_IO_46_1 | PADI_IOCFG_IO_46_0)
#define PADI_IDX_IO46_GPIO_HIZ                                      (45)
/*********** CFG 8 ***********/
#define PADI_CFG_IO46_CTSU_SN_6                                     (PADI_IOCFG_IO_46_3)
#define PADI_IDX_IO46_CTSU_SN_6                                     (45)
/******************* IO 47 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO47_CH2P_CH22                                     (0UL)
#define PADI_IDX_IO47_CH2P_CH22                                     (46)
/*********** CFG 1 ***********/
#define PADI_CFG_IO47_PA23                                          (PADI_IOCFG_IO_47_0)
#define PADI_IDX_IO47_PA23                                          (46)
/*********** CFG 2 ***********/
#define PADI_CFG_IO47_PB21                                          (PADI_IOCFG_IO_47_1)
#define PADI_IDX_IO47_PB21                                          (46)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO47_GTOUT3_CH1_P                                  (PADI_IOCFG_IO_47_2 | PADI_IOCFG_IO_47_0)
#define PADI_IDX_IO47_GTOUT3_CH1_P                                  (46)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO47_GPIO_HIZ                                      (PADI_IOCFG_IO_47_2 | PADI_IOCFG_IO_47_1 | PADI_IOCFG_IO_47_0)
#define PADI_IDX_IO47_GPIO_HIZ                                      (46)
/*********** CFG 8 ***********/
#define PADI_CFG_IO47_CTSU_SN_5                                     (PADI_IOCFG_IO_47_3)
#define PADI_IDX_IO47_CTSU_SN_5                                     (46)
/******************* IO 48 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO48_CH3P_CH23                                     (0UL)
#define PADI_IDX_IO48_CH3P_CH23                                     (47)
/*********** CFG 1 ***********/
#define PADI_CFG_IO48_PA22                                          (PADI_IOCFG_IO_48_0)
#define PADI_IDX_IO48_PA22                                          (47)
/*********** CFG 2 ***********/
#define PADI_CFG_IO48_PB20                                          (PADI_IOCFG_IO_48_1)
#define PADI_IDX_IO48_PB20                                          (47)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
#define PADI_CFG_IO48_GTOUT3_CH1_N                                  (PADI_IOCFG_IO_48_2 | PADI_IOCFG_IO_48_0)
#define PADI_IDX_IO48_GTOUT3_CH1_N                                  (47)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO48_GPIO_HIZ                                      (PADI_IOCFG_IO_48_2 | PADI_IOCFG_IO_48_1 | PADI_IOCFG_IO_48_0)
#define PADI_IDX_IO48_GPIO_HIZ                                      (47)
/*********** CFG 8 ***********/
#define PADI_CFG_IO48_CTSU_SN_4                                     (PADI_IOCFG_IO_48_3)
#define PADI_IDX_IO48_CTSU_SN_4                                     (47)
/******************* IO 49 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO49_CH1N_CTSU_SN_1                                (0UL)
#define PADI_IDX_IO49_CH1N_CTSU_SN_1                                (48)
/*********** CFG 1 ***********/
#define PADI_CFG_IO49_PA21                                          (PADI_IOCFG_IO_49_0)
#define PADI_IDX_IO49_PA21                                          (48)
/*********** CFG 2 ***********/
#define PADI_CFG_IO49_PB19                                          (PADI_IOCFG_IO_49_1)
#define PADI_IDX_IO49_PB19                                          (48)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO49_ATOUT1_CH3_P                                  (PADI_IOCFG_IO_49_1)
#define PADI_IDX_IO49_ATOUT1_CH3_P                                  (48)
/*********** CFG 3 ***********/
#define PADI_CFG_IO49_I2C1_SCK                                      (PADI_IOCFG_IO_49_1 | PADI_IOCFG_IO_49_0)
#define PADI_IDX_IO49_I2C1_SCK                                      (48)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO49_GPIO_HIZ                                      (PADI_IOCFG_IO_49_2 | PADI_IOCFG_IO_49_1 | PADI_IOCFG_IO_49_0)
#define PADI_IDX_IO49_GPIO_HIZ                                      (48)
/*********** CFG 8 ***********/
#define PADI_CFG_IO49_CH25                                          (PADI_IOCFG_IO_49_3)
#define PADI_IDX_IO49_CH25                                          (48)
/******************* IO 50 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO50_CH1P                                          (0UL)
#define PADI_IDX_IO50_CH1P                                          (49)
/*********** CFG 1 ***********/
#define PADI_CFG_IO50_PA20                                          (PADI_IOCFG_IO_50_0)
#define PADI_IDX_IO50_PA20                                          (49)
/*********** CFG 2 ***********/
#define PADI_CFG_IO50_PB18                                          (PADI_IOCFG_IO_50_1)
#define PADI_IDX_IO50_PB18                                          (49)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO50_ATOUT1_CH3_N                                  (PADI_IOCFG_IO_50_1)
#define PADI_IDX_IO50_ATOUT1_CH3_N                                  (49)
/*********** CFG 3 ***********/
#define PADI_CFG_IO50_I2C1_SDA                                      (PADI_IOCFG_IO_50_1 | PADI_IOCFG_IO_50_0)
#define PADI_IDX_IO50_I2C1_SDA                                      (49)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO50_GPIO_HIZ                                      (PADI_IOCFG_IO_50_2 | PADI_IOCFG_IO_50_1 | PADI_IOCFG_IO_50_0)
#define PADI_IDX_IO50_GPIO_HIZ                                      (49)
/*********** CFG 8 ***********/
#define PADI_CFG_IO50_CH1                                           (PADI_IOCFG_IO_50_3)
#define PADI_IDX_IO50_CH1                                           (49)
/******************* IO 51 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO51_CH0N_CTSU_SN_0                                (0UL)
#define PADI_IDX_IO51_CH0N_CTSU_SN_0                                (50)
/*********** CFG 1 ***********/
#define PADI_CFG_IO51_PA19                                          (PADI_IOCFG_IO_51_0)
#define PADI_IDX_IO51_PA19                                          (50)
/*********** CFG 2 ***********/
#define PADI_CFG_IO51_PB17                                          (PADI_IOCFG_IO_51_1)
#define PADI_IDX_IO51_PB17                                          (50)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO51_ATOUT1_CH2_P                                  (PADI_IOCFG_IO_51_1)
#define PADI_IDX_IO51_ATOUT1_CH2_P                                  (50)
/*********** CFG 3 ***********/
#define PADI_CFG_IO51_VREFP                                         (PADI_IOCFG_IO_51_1 | PADI_IOCFG_IO_51_0)
#define PADI_IDX_IO51_VREFP                                         (50)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO51_GPIO_HIZ                                      (PADI_IOCFG_IO_51_2 | PADI_IOCFG_IO_51_1 | PADI_IOCFG_IO_51_0)
#define PADI_IDX_IO51_GPIO_HIZ                                      (50)
/*********** CFG 8 ***********/
#define PADI_CFG_IO51_CH24                                          (PADI_IOCFG_IO_51_3)
#define PADI_IDX_IO51_CH24                                          (50)
/******************* IO 52 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO52_CH0P                                          (0UL)
#define PADI_IDX_IO52_CH0P                                          (51)
/*********** CFG 1 ***********/
#define PADI_CFG_IO52_PA18                                          (PADI_IOCFG_IO_52_0)
#define PADI_IDX_IO52_PA18                                          (51)
/*********** CFG 2 ***********/
#define PADI_CFG_IO52_PB16                                          (PADI_IOCFG_IO_52_1)
#define PADI_IDX_IO52_PB16                                          (51)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO52_ATOUT1_CH2_N                                  (PADI_IOCFG_IO_52_1)
#define PADI_IDX_IO52_ATOUT1_CH2_N                                  (51)
/*********** CFG 3 ***********/
#define PADI_CFG_IO52_VREFM                                         (PADI_IOCFG_IO_52_1 | PADI_IOCFG_IO_52_0)
#define PADI_IDX_IO52_VREFM                                         (51)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO52_GPIO_HIZ                                      (PADI_IOCFG_IO_52_2 | PADI_IOCFG_IO_52_1 | PADI_IOCFG_IO_52_0)
#define PADI_IDX_IO52_GPIO_HIZ                                      (51)
/*********** CFG 8 ***********/
#define PADI_CFG_IO52_CH0                                           (PADI_IOCFG_IO_52_3)
#define PADI_IDX_IO52_CH0                                           (51)
/******************* IO 53 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO53_CTSU_SN_3                                     (0UL)
#define PADI_IDX_IO53_CTSU_SN_3                                     (52)
/*********** CFG 1 ***********/
#define PADI_CFG_IO53_PA17                                          (PADI_IOCFG_IO_53_0)
#define PADI_IDX_IO53_PA17                                          (52)
/*********** CFG 2 ***********/
#define PADI_CFG_IO53_PD8                                           (PADI_IOCFG_IO_53_1)
#define PADI_IDX_IO53_PD8                                           (52)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO53_GTIN1_CH2                                     (PADI_IOCFG_IO_53_1)
#define PADI_IDX_IO53_GTIN1_CH2                                     (52)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO53_GTOUT1_CH2_P                                  (PADI_IOCFG_IO_53_1)
#define PADI_IDX_IO53_GTOUT1_CH2_P                                  (52)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
#define PADI_CFG_IO53_SPI1_SS                                       (PADI_IOCFG_IO_53_2)
#define PADI_IDX_IO53_SPI1_SS                                       (52)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO53_GTOUT2_CH2_P                                  (PADI_IOCFG_IO_53_2 | PADI_IOCFG_IO_53_1)
#define PADI_IDX_IO53_GTOUT2_CH2_P                                  (52)
/*********** CFG 7 ***********/
#define PADI_CFG_IO53_GPIO_HIZ                                      (PADI_IOCFG_IO_53_2 | PADI_IOCFG_IO_53_1 | PADI_IOCFG_IO_53_0)
#define PADI_IDX_IO53_GPIO_HIZ                                      (52)
/*********** CFG 8 ***********/
#define PADI_CFG_IO53_CH8                                           (PADI_IOCFG_IO_53_3)
#define PADI_IDX_IO53_CH8                                           (52)
/******************* IO 54 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO54_PGA_OUT_0                                     (0UL)
#define PADI_IDX_IO54_PGA_OUT_0                                     (53)
/*********** CFG 1 ***********/
#define PADI_CFG_IO54_PA16                                          (PADI_IOCFG_IO_54_0)
#define PADI_IDX_IO54_PA16                                          (53)
/*********** CFG 2 ***********/
#define PADI_CFG_IO54_PB4                                           (PADI_IOCFG_IO_54_1)
#define PADI_IDX_IO54_PB4                                           (53)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO54_ATIN2_CH4                                     (PADI_IOCFG_IO_54_1)
#define PADI_IDX_IO54_ATIN2_CH4                                     (53)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO54_ATOUT2_CH4                                    (PADI_IOCFG_IO_54_1)
#define PADI_IDX_IO54_ATOUT2_CH4                                    (53)
/*********** CFG 3 ***********/
#define PADI_CFG_IO54_I2C1_SCK                                      (PADI_IOCFG_IO_54_1 | PADI_IOCFG_IO_54_0)
#define PADI_IDX_IO54_I2C1_SCK                                      (53)
/*********** CFG 4 ***********/
#define PADI_CFG_IO54_SPI1_SCK                                      (PADI_IOCFG_IO_54_2)
#define PADI_IDX_IO54_SPI1_SCK                                      (53)
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO54_GPIO_HIZ                                      (PADI_IOCFG_IO_54_2 | PADI_IOCFG_IO_54_1 | PADI_IOCFG_IO_54_0)
#define PADI_IDX_IO54_GPIO_HIZ                                      (53)
/*********** CFG 8 ***********/
/******************* IO 55 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO55_PGA_OUT_1                                     (0UL)
#define PADI_IDX_IO55_PGA_OUT_1                                     (54)
/*********** CFG 1 ***********/
#define PADI_CFG_IO55_PA15                                          (PADI_IOCFG_IO_55_0)
#define PADI_IDX_IO55_PA15                                          (54)
/*********** CFG 2 ***********/
#define PADI_CFG_IO55_PB3                                           (PADI_IOCFG_IO_55_1)
#define PADI_IDX_IO55_PB3                                           (54)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO55_ATIN2_BRKIN1                                  (PADI_IOCFG_IO_55_1)
#define PADI_IDX_IO55_ATIN2_BRKIN1                                  (54)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO55_GTOUT2_CH2_N                                  (PADI_IOCFG_IO_55_1)
#define PADI_IDX_IO55_GTOUT2_CH2_N                                  (54)
/*********** CFG 3 ***********/
#define PADI_CFG_IO55_I2C1_SDA                                      (PADI_IOCFG_IO_55_1 | PADI_IOCFG_IO_55_0)
#define PADI_IDX_IO55_I2C1_SDA                                      (54)
/*********** CFG 4 ***********/
#define PADI_CFG_IO55_SPI1_RXD                                      (PADI_IOCFG_IO_55_2)
#define PADI_IDX_IO55_SPI1_RXD                                      (54)
/*********** CFG 5 ***********/
#define PADI_CFG_IO55_UART4_RX                                      (PADI_IOCFG_IO_55_2 | PADI_IOCFG_IO_55_0)
#define PADI_IDX_IO55_UART4_RX                                      (54)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO55_GPIO_HIZ                                      (PADI_IOCFG_IO_55_2 | PADI_IOCFG_IO_55_1 | PADI_IOCFG_IO_55_0)
#define PADI_IDX_IO55_GPIO_HIZ                                      (54)
/*********** CFG 8 ***********/
/******************* IO 56 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO56_PA14                                          (PADI_IOCFG_IO_56_0)
#define PADI_IDX_IO56_PA14                                          (55)
/*********** CFG 2 ***********/
#define PADI_CFG_IO56_PB2                                           (PADI_IOCFG_IO_56_1)
#define PADI_IDX_IO56_PB2                                           (55)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO56_GTIN2_ETR                                     (PADI_IOCFG_IO_56_1)
#define PADI_IDX_IO56_GTIN2_ETR                                     (55)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO56_GTOUT2_CH3_N                                  (PADI_IOCFG_IO_56_1)
#define PADI_IDX_IO56_GTOUT2_CH3_N                                  (55)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
#define PADI_CFG_IO56_SPI1_TXD                                      (PADI_IOCFG_IO_56_2)
#define PADI_IDX_IO56_SPI1_TXD                                      (55)
/*********** CFG 5 ***********/
#define PADI_CFG_IO56_UART4_TX                                      (PADI_IOCFG_IO_56_2 | PADI_IOCFG_IO_56_0)
#define PADI_IDX_IO56_UART4_TX                                      (55)
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO56_GPIO_HIZ                                      (PADI_IOCFG_IO_56_2 | PADI_IOCFG_IO_56_1 | PADI_IOCFG_IO_56_0)
#define PADI_IDX_IO56_GPIO_HIZ                                      (55)
/*********** CFG 8 ***********/
#define PADI_CFG_IO56_CH41                                          (PADI_IOCFG_IO_56_3)
#define PADI_IDX_IO56_CH41                                          (55)
/******************* IO 57 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO57_CH2N_CTSU_SN_31                               (0UL)
#define PADI_IDX_IO57_CH2N_CTSU_SN_31                               (56)
/*********** CFG 1 ***********/
#define PADI_CFG_IO57_PA13                                          (PADI_IOCFG_IO_57_0)
#define PADI_IDX_IO57_PA13                                          (56)
/*********** CFG 2 ***********/
#define PADI_CFG_IO57_PB1                                           (PADI_IOCFG_IO_57_1)
#define PADI_IDX_IO57_PB1                                           (56)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO57_ATIN2_BRKIN2                                  (PADI_IOCFG_IO_57_1)
#define PADI_IDX_IO57_ATIN2_BRKIN2                                  (56)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO57_ATOUT1_CH1_P                                  (PADI_IOCFG_IO_57_1)
#define PADI_IDX_IO57_ATOUT1_CH1_P                                  (56)
/*********** CFG 3 ***********/
#define PADI_CFG_IO57_UART4_RX                                      (PADI_IOCFG_IO_57_1 | PADI_IOCFG_IO_57_0)
#define PADI_IDX_IO57_UART4_RX                                      (56)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO57_vcoclk_test                                   (PADI_IOCFG_IO_57_2 | PADI_IOCFG_IO_57_1)
#define PADI_IDX_IO57_vcoclk_test                                   (56)
/*********** CFG 7 ***********/
#define PADI_CFG_IO57_GPIO_HIZ                                      (PADI_IOCFG_IO_57_2 | PADI_IOCFG_IO_57_1 | PADI_IOCFG_IO_57_0)
#define PADI_IDX_IO57_GPIO_HIZ                                      (56)
/*********** CFG 8 ***********/
#define PADI_CFG_IO57_CH26                                          (PADI_IOCFG_IO_57_3)
#define PADI_IDX_IO57_CH26                                          (56)
/******************* IO 58 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO58_CH2P                                          (0UL)
#define PADI_IDX_IO58_CH2P                                          (57)
/*********** CFG 1 ***********/
#define PADI_CFG_IO58_PA12                                          (PADI_IOCFG_IO_58_0)
#define PADI_IDX_IO58_PA12                                          (57)
/*********** CFG 2 ***********/
#define PADI_CFG_IO58_PB0                                           (PADI_IOCFG_IO_58_1)
#define PADI_IDX_IO58_PB0                                           (57)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO58_ATOUT1_CH1_N                                  (PADI_IOCFG_IO_58_1)
#define PADI_IDX_IO58_ATOUT1_CH1_N                                  (57)
/*********** CFG 3 ***********/
#define PADI_CFG_IO58_UART4_TX                                      (PADI_IOCFG_IO_58_1 | PADI_IOCFG_IO_58_0)
#define PADI_IDX_IO58_UART4_TX                                      (57)
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO58_rcclk_test                                    (PADI_IOCFG_IO_58_2 | PADI_IOCFG_IO_58_1)
#define PADI_IDX_IO58_rcclk_test                                    (57)
/*********** CFG 7 ***********/
#define PADI_CFG_IO58_GPIO_HIZ                                      (PADI_IOCFG_IO_58_2 | PADI_IOCFG_IO_58_1 | PADI_IOCFG_IO_58_0)
#define PADI_IDX_IO58_GPIO_HIZ                                      (57)
/*********** CFG 8 ***********/
#define PADI_CFG_IO58_CH2                                           (PADI_IOCFG_IO_58_3)
#define PADI_IDX_IO58_CH2                                           (57)
/******************* IO 59 *******************/
/*********** CFG 0 ***********/
/*********** CFG 1 ***********/
#define PADI_CFG_IO59_PA7                                           (PADI_IOCFG_IO_59_0)
#define PADI_IDX_IO59_PA7                                           (58)
/*********** CFG 2 ***********/
#define PADI_CFG_IO59_PD17                                          (PADI_IOCFG_IO_59_1)
#define PADI_IDX_IO59_PD17                                          (58)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO59_ATIN2_ETR                                     (PADI_IOCFG_IO_59_1)
#define PADI_IDX_IO59_ATIN2_ETR                                     (58)
/*********** CFG 2 SUB 2 *****/
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO59_GPIO_HIZ                                      (PADI_IOCFG_IO_59_2 | PADI_IOCFG_IO_59_1 | PADI_IOCFG_IO_59_0)
#define PADI_IDX_IO59_GPIO_HIZ                                      (58)
/*********** CFG 8 ***********/
#define PADI_CFG_IO59_CH42                                          (PADI_IOCFG_IO_59_3)
#define PADI_IDX_IO59_CH42                                          (58)
/******************* IO 60 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO60_CTSU_SN_2                                     (0UL)
#define PADI_IDX_IO60_CTSU_SN_2                                     (59)
/*********** CFG 1 ***********/
#define PADI_CFG_IO60_PA6                                           (PADI_IOCFG_IO_60_0)
#define PADI_IDX_IO60_PA6                                           (59)
/*********** CFG 2 ***********/
#define PADI_CFG_IO60_PD16                                          (PADI_IOCFG_IO_60_1)
#define PADI_IDX_IO60_PD16                                          (59)
/*********** CFG 2 SUB 1 *****/
#define PADI_CFG_IO60_GTIN1_CH3                                     (PADI_IOCFG_IO_60_1)
#define PADI_IDX_IO60_GTIN1_CH3                                     (59)
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO60_GTOUT1_CH3_P                                  (PADI_IOCFG_IO_60_1)
#define PADI_IDX_IO60_GTOUT1_CH3_P                                  (59)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
#define PADI_CFG_IO60_GTOUT2_CH2_N                                  (PADI_IOCFG_IO_60_2 | PADI_IOCFG_IO_60_1)
#define PADI_IDX_IO60_GTOUT2_CH2_N                                  (59)
/*********** CFG 7 ***********/
#define PADI_CFG_IO60_GPIO_HIZ                                      (PADI_IOCFG_IO_60_2 | PADI_IOCFG_IO_60_1 | PADI_IOCFG_IO_60_0)
#define PADI_IDX_IO60_GPIO_HIZ                                      (59)
/*********** CFG 8 ***********/
#define PADI_CFG_IO60_CH7                                           (PADI_IOCFG_IO_60_3)
#define PADI_IDX_IO60_CH7                                           (59)
/******************* IO 61 *******************/
/*********** CFG 0 ***********/
#define PADI_CFG_IO61_CH3P                                          (0UL)
#define PADI_IDX_IO61_CH3P                                          (60)
/*********** CFG 1 ***********/
#define PADI_CFG_IO61_PB28                                          (PADI_IOCFG_IO_61_0)
#define PADI_IDX_IO61_PB28                                          (60)
/*********** CFG 2 ***********/
#define PADI_CFG_IO61_PC4                                           (PADI_IOCFG_IO_61_1)
#define PADI_IDX_IO61_PC4                                           (60)
/*********** CFG 2 SUB 1 *****/
/*********** CFG 2 SUB 2 *****/
#define PADI_CFG_IO61_GTOUT4_CH1_P                                  (PADI_IOCFG_IO_61_1)
#define PADI_IDX_IO61_GTOUT4_CH1_P                                  (60)
/*********** CFG 3 ***********/
/*********** CFG 4 ***********/
/*********** CFG 5 ***********/
/*********** CFG 6 ***********/
/*********** CFG 7 ***********/
#define PADI_CFG_IO61_GPIO_HIZ                                      (PADI_IOCFG_IO_61_2 | PADI_IOCFG_IO_61_1 | PADI_IOCFG_IO_61_0)
#define PADI_IDX_IO61_GPIO_HIZ                                      (60)
/*********** CFG 8 ***********/
#define PADI_CFG_IO61_CH19                                          (PADI_IOCFG_IO_61_3)
#define PADI_IDX_IO61_CH19                                          (60)

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

#endif /* XT32H0xxB_HAL_PADI_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

