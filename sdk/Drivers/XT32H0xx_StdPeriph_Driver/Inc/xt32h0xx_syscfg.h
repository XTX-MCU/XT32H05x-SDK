/**
  ******************************************************************************
  * @file    xt32h0xx_syscfg.h
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file contains all the functions prototypes for the SYSCFG firmware 
  *          library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/*!< Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_SYSCFG_H
#define __XT32H0XX_SYSCFG_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup SYSCFG
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup SYSCFG_Exported_Constants System Exported Constants
  * @{
  */ 
  
/** @defgroup SYSCFG_SRAM System SRAM Mode
  * @{
  */ 
#define SYS_SRAM_MODE_LIGHTSLEEP       (1UL)
#define SYS_SRAM_MODE_DEEPSLEEP        (2UL)
#define SYS_SRAM_MODE_SHUTDWON         (4UL)

#define IS_SYS_SRAM_MODE(MODE)         (((MODE) == SYS_SRAM_MODE_LIGHTSLEEP) || \
                                        ((MODE) == SYS_SRAM_MODE_DEEPSLEEP) || \
                                        ((MODE) == SYS_SRAM_MODE_SHUTDWON)) 
/**
  * @}
  */
/** @defgroup SYSCFG_SPI System SPI Mode
  * @{
  */ 
#define SYS_SPI2_MODE_SLAVE            (0)
#define SYS_SPI2_MODE_MASTER           (SYSCFG_SYS_CFG_SPI1_MODE)
#define SYS_SPI2_MODE_SLAVE            (0)
#define SYS_SPI2_MODE_MASTER           (SYSCFG_SYS_CFG_SPI2_MODE)

#define IS_SYS_SPI_MODE(MODE)          (((MODE) == SYS_SPI2_MODE_SLAVE) || \
                                        ((MODE) == SYS_SPI2_MODE_MASTER) || \
                                        ((MODE) == SYS_SPI2_MODE_SLAVE) || \
                                        ((MODE) == SYS_SPI2_MODE_MASTER)) 

#define SYS_GET_SPIMODE_MASK(MODE)     ((((MODE) == SYS_SPI2_MODE_SLAVE) || ((MODE) == SYS_SPI2_MODE_MASTER)) ? \
                                       SYS_SPI2_MODE_MASTER : SYS_SPI2_MODE_MASTER)
/**
  * @}
  */

/** @defgroup SYSCFG_UART System UART Mode
  * @{
  */ 
#define SYS_UART1_MODE_UART            (0)
#define SYS_UART1_MODE_IRDA            (SYSCFG_SYS_CFG_UART1_MODE)
#define SYS_UART2_MODE_UART            (0)
#define SYS_UART2_MODE_IRDA            (SYSCFG_SYS_CFG_UART2_MODE)
#define SYS_UART3_MODE_UART            (0)
#define SYS_UART3_MODE_IRDA            (SYSCFG_SYS_CFG_UART3_MODE)
#define SYS_UART4_MODE_UART            (0)
#define SYS_UART4_MODE_IRDA            (SYSCFG_SYS_CFG_UART4_MODE)

#define IS_SYS_UART_MODE(MODE)         (((MODE) == SYS_UART1_MODE_UART) || \
                                        ((MODE) == SYS_UART1_MODE_IRDA) || \
                                        ((MODE) == SYS_UART2_MODE_UART) || \
                                        ((MODE) == SYS_UART2_MODE_IRDA) || \
                                        ((MODE) == SYS_UART3_MODE_UART) || \
                                        ((MODE) == SYS_UART4_MODE_IRDA) || \
                                        ((MODE) == SYS_UART4_MODE_UART) || \
                                        ((MODE) == SYS_UART4_MODE_IRDA)) 

#define SYS_GET_UARTMODE_MASK(MODE)     ((((MODE) == SYS_UART1_MODE_UART) || ((MODE) == SYS_UART1_MODE_IRDA)) ? SYS_UART1_MODE_IRDA : \
                                        (((MODE) == SYS_UART2_MODE_UART) || ((MODE) == SYS_UART2_MODE_IRDA)) ? SYS_UART2_MODE_IRDA : \
                                        (((MODE) == SYS_UART3_MODE_UART) || ((MODE) == SYS_UART3_MODE_IRDA)) ? SYS_UART3_MODE_IRDA : \
                                       SYS_UART4_MODE_IRDA)
/**
  * @}
  */

/** @defgroup SYSCFG_BOOT_Mode System Boot Mode 
  * @{
  */ 
#define SYS_BOOT_MODE_FLASH            (0)
#define SYS_BOOT_MODE_ROM              (SYSCFG_SYS_CFG_BOOT_MODE_0)
#define SYS_BOOT_MODE_SRAM             (SYSCFG_SYS_CFG_BOOT_MODE_1)

#define IS_SYS_BOOT_MODE(MODE)         (((MODE) == SYS_BOOT_MODE_FLASH) || \
                                        ((MODE) == SYS_BOOT_MODE_ROM) || \
                                        ((MODE) == SYS_BOOT_MODE_SRAM)) 
/**
  * @}
  */

/** @defgroup SYSCFG_BOOT_Control System Boot Control 
  * @{
  */ 
#define SYS_BOOT_CTRL_HW               (0)
#define SYS_BOOT_CTRL_SW               (SYSCFG_SYS_CFG_BOOTCTRL)

#define IS_SYS_BOOT_CTRL(CTRL)         (((CTRL) == SYS_BOOT_CTRL_HW) || \
                                        ((CTRL) == SYS_BOOT_CTRL_SW)) 
/**
  * @}
  */

/** @defgroup SYSCFG_FLASH DMA System Flash DMA Access 
  * @{
  */ 
#define SYS_FLASH_DMA_DISABLE          (0)
#define SYS_FLASH_DMA_ENABLE           (SYSCFG_SYS_CFG_FLASHDMA)

#define IS_SYS_FLASH_DMA_EN(STAT)      (((STAT) == SYS_FLASH_DMA_DISABLE) || \
                                        ((STAT) == SYS_FLASH_DMA_ENABLE)) 
/**
  * @}
  */

/** @defgroup SYSCFG_ICTL_Config System ICTL Configure
  * @{
  */ 
#define SYS_ICTL_CFG_I2C1              (0)
#define SYS_ICTL_CFG_SPI1              (0)
#define SYS_ICTL_CFG_SPI2              (0)
#define SYS_ICTL_CFG_ADC               (0)
#define SYS_ICTL_CFG_I2C2              (0)
#define SYS_ICTL_CFG_GPIOA             (1)

#define IS_SYS_ICTL_CFG(CFG)           (((CFG) == SYS_ICTL_CFG_I2C1) || \
                                        ((CFG) == SYS_ICTL_CFG_SPI1) || \
                                        ((CFG) == SYS_ICTL_CFG_SPI2) || \
                                        ((CFG) == SYS_ICTL_CFG_ADC)  || \
                                        ((CFG) == SYS_ICTL_CFG_I2C2) || \
                                        ((CFG) == SYS_ICTL_CFG_GPIOA))
/**
  * @}
  */

/** @defgroup SYSCFG_DMA_HS_IF DMA handshaking interface config
  * @{
  */ 
#define SYS_DMA_HS_IF_IDX_0_UART1_TX           (0)
#define SYS_DMA_HS_IF_CFG_0_UART1_TX           (0)
#define SYS_DMA_HS_IF_MSK_0_UART1_TX           (0x00000003UL)
#define SYS_DMA_HS_IF_IDX_0_UART1_RX           (1)
#define SYS_DMA_HS_IF_CFG_0_UART1_RX           (0)
#define SYS_DMA_HS_IF_MSK_0_UART1_RX           (0x0000000CUL)
#define SYS_DMA_HS_IF_IDX_0_UART2_TX           (2)
#define SYS_DMA_HS_IF_CFG_0_UART2_TX           (0)
#define SYS_DMA_HS_IF_MSK_0_UART2_TX           (0x00000030UL)
#define SYS_DMA_HS_IF_IDX_0_UART2_RX           (3)
#define SYS_DMA_HS_IF_CFG_0_UART2_RX           (0)
#define SYS_DMA_HS_IF_MSK_0_UART2_RX           (0x000000C0UL)
#define SYS_DMA_HS_IF_IDX_0_TIMA_COMB          (4)
#define SYS_DMA_HS_IF_CFG_0_TIMA_COMB          (0)
#define SYS_DMA_HS_IF_MSK_0_TIMA_COMB          (0x00000300UL)
#define SYS_DMA_HS_IF_IDX_0_ADC_EOS            (5)
#define SYS_DMA_HS_IF_CFG_0_ADC_EOS            (0)
#define SYS_DMA_HS_IF_MSK_0_ADC_EOS            (0x00000C00UL)
#define SYS_DMA_HS_IF_IDX_0_I2C1_TX            (8)
#define SYS_DMA_HS_IF_CFG_0_I2C1_TX            (0)
#define SYS_DMA_HS_IF_MSK_0_I2C1_TX            (0x00030000UL)
#define SYS_DMA_HS_IF_IDX_0_I2C1_RX            (9)
#define SYS_DMA_HS_IF_CFG_0_I2C1_RX            (0)
#define SYS_DMA_HS_IF_MSK_0_I2C1_RX            (0x000C0000UL)
#define SYS_DMA_HS_IF_IDX_0_SPI1_TX            (12)
#define SYS_DMA_HS_IF_CFG_0_SPI1_TX            (0)
#define SYS_DMA_HS_IF_MSK_0_SPI1_TX            (0x03000000UL)
#define SYS_DMA_HS_IF_IDX_0_SPI1_RX            (13)
#define SYS_DMA_HS_IF_CFG_0_SPI1_RX            (0)
#define SYS_DMA_HS_IF_MSK_0_SPI1_RX            (0x0C000000UL)
#define SYS_DMA_HS_IF_IDX_0_SPI2_TX            (14)
#define SYS_DMA_HS_IF_CFG_0_SPI2_TX            (0)
#define SYS_DMA_HS_IF_MSK_0_SPI2_TX            (0x30000000UL)
#define SYS_DMA_HS_IF_IDX_0_SPI2_RX            (15)
#define SYS_DMA_HS_IF_CFG_0_SPI2_RX            (0)
#define SYS_DMA_HS_IF_MSK_0_SPI2_RX            (0xC0000000UL)

#define SYS_DMA_HS_IF_IDX_1_I2C1_TX            (0)
#define SYS_DMA_HS_IF_CFG_1_I2C1_TX            (1)
#define SYS_DMA_HS_IF_MSK_1_I2C1_TX            (0x00000003UL)
#define SYS_DMA_HS_IF_IDX_1_I2C1_RX            (1)
#define SYS_DMA_HS_IF_CFG_1_I2C1_RX            (1)
#define SYS_DMA_HS_IF_MSK_1_I2C1_RX            (0x0000000CUL)
#define SYS_DMA_HS_IF_IDX_1_UART3_TX           (4)
#define SYS_DMA_HS_IF_CFG_1_UART3_TX           (1)
#define SYS_DMA_HS_IF_MSK_1_UART3_TX           (0x00000300UL)
#define SYS_DMA_HS_IF_IDX_1_UART3_RX           (5)
#define SYS_DMA_HS_IF_CFG_1_UART3_RX           (1)
#define SYS_DMA_HS_IF_MSK_1_UART3_RX           (0x00000C00UL)
#define SYS_DMA_HS_IF_IDX_1_UART4_TX           (6)
#define SYS_DMA_HS_IF_CFG_1_UART4_TX           (1)
#define SYS_DMA_HS_IF_MSK_1_UART4_TX           (0x00003000UL)
#define SYS_DMA_HS_IF_IDX_1_UART4_RX           (7)
#define SYS_DMA_HS_IF_CFG_1_UART4_RX           (1)
#define SYS_DMA_HS_IF_MSK_1_UART4_RX           (0x0000C000UL)
#define SYS_DMA_HS_IF_IDX_1_SPI1_TX            (8)
#define SYS_DMA_HS_IF_CFG_1_SPI1_TX            (1)
#define SYS_DMA_HS_IF_MSK_1_SPI1_TX            (0x00030000UL)
#define SYS_DMA_HS_IF_IDX_1_SPI1_RX            (9)
#define SYS_DMA_HS_IF_CFG_1_SPI1_RX            (1)
#define SYS_DMA_HS_IF_MSK_1_SPI1_RX            (0x000C0000UL)
#define SYS_DMA_HS_IF_IDX_1_I2C2_TX            (10)
#define SYS_DMA_HS_IF_CFG_1_I2C2_TX            (1)
#define SYS_DMA_HS_IF_MSK_1_I2C2_TX            (0x00300000UL)
#define SYS_DMA_HS_IF_IDX_1_I2C2_RX            (11)
#define SYS_DMA_HS_IF_CFG_1_I2C2_RX            (1)
#define SYS_DMA_HS_IF_MSK_1_I2C2_RX            (0x00C00000UL)
#define SYS_DMA_HS_IF_IDX_1_UART3A_TX          (12)
#define SYS_DMA_HS_IF_CFG_1_UART3A_TX          (1)
#define SYS_DMA_HS_IF_MSK_1_UART3A_TX          (0x03000000UL)
#define SYS_DMA_HS_IF_IDX_1_UART3A_RX          (13)
#define SYS_DMA_HS_IF_CFG_1_UART3A_RX          (1)
#define SYS_DMA_HS_IF_MSK_1_UART3A_RX          (0x0C000000UL)
#define SYS_DMA_HS_IF_IDX_1_I2C1A_TX           (14)
#define SYS_DMA_HS_IF_CFG_1_I2C1A_TX           (1)
#define SYS_DMA_HS_IF_MSK_1_I2C1A_TX           (0x30000000UL)
#define SYS_DMA_HS_IF_IDX_1_I2C1A_RX           (15)
#define SYS_DMA_HS_IF_CFG_1_I2C1A_RX           (1)
#define SYS_DMA_HS_IF_MSK_1_I2C1A_RX           (0xC0000000UL)

#define SYS_DMA_HS_IF_IDX_2_SPI1_TX            (0)
#define SYS_DMA_HS_IF_CFG_2_SPI1_TX            (2)
#define SYS_DMA_HS_IF_MSK_2_SPI1_TX            (0x00000003UL)
#define SYS_DMA_HS_IF_IDX_2_SPI1_RX            (1)
#define SYS_DMA_HS_IF_CFG_2_SPI1_RX            (2)
#define SYS_DMA_HS_IF_MSK_2_SPI1_RX            (0x0000000CUL)
#define SYS_DMA_HS_IF_IDX_2_TIMA_TRGCOM        (2)
#define SYS_DMA_HS_IF_CFG_2_TIMA_TRGCOM        (2)
#define SYS_DMA_HS_IF_MSK_2_TIMA_TRGCOM        (0x00000030UL)
#define SYS_DMA_HS_IF_IDX_2_TIMA_CC1           (4)
#define SYS_DMA_HS_IF_CFG_2_TIMA_CC1           (2)
#define SYS_DMA_HS_IF_MSK_2_TIMA_CC1           (0x00000300UL)
#define SYS_DMA_HS_IF_IDX_2_TIMA_CC2           (6)
#define SYS_DMA_HS_IF_CFG_2_TIMA_CC2           (2)
#define SYS_DMA_HS_IF_MSK_2_TIMA_CC2           (0x00003000UL)
#define SYS_DMA_HS_IF_IDX_2_TIMA_CC3           (8)
#define SYS_DMA_HS_IF_CFG_2_TIMA_CC3           (2)
#define SYS_DMA_HS_IF_MSK_2_TIMA_CC3           (0x00030000UL)
#define SYS_DMA_HS_IF_IDX_2_TIMA_CC4           (10)
#define SYS_DMA_HS_IF_CFG_2_TIMA_CC4           (2)
#define SYS_DMA_HS_IF_MSK_2_TIMA_CC4           (0x00300000UL)
#define SYS_DMA_HS_IF_IDX_2_TIMA_UDT           (12)
#define SYS_DMA_HS_IF_CFG_2_TIMA_UDT           (2)
#define SYS_DMA_HS_IF_MSK_2_TIMA_UDT           (0x03000000UL)
#define SYS_DMA_HS_IF_IDX_2_UART2_TX           (14)
#define SYS_DMA_HS_IF_CFG_2_UART2_TX           (2)
#define SYS_DMA_HS_IF_MSK_2_UART2_TX           (0x30000000UL)
#define SYS_DMA_HS_IF_IDX_2_UART2_RX           (15)
#define SYS_DMA_HS_IF_CFG_2_UART2_RX           (2)
#define SYS_DMA_HS_IF_MSK_2_UART2_RX           (0xC0000000UL)

#define SYS_DMA_HS_IF_IDX_3_TIMG_TRGCOM        (2)
#define SYS_DMA_HS_IF_CFG_3_TIMG_TRGCOM        (3)
#define SYS_DMA_HS_IF_MSK_3_TIMG_TRGCOM        (0x00000030UL)
#define SYS_DMA_HS_IF_IDX_3_TIMG_CC1           (4)
#define SYS_DMA_HS_IF_CFG_3_TIMG_CC1           (3)
#define SYS_DMA_HS_IF_MSK_3_TIMG_CC1           (0x00000300UL)
#define SYS_DMA_HS_IF_IDX_3_TIMG_CC2           (6)
#define SYS_DMA_HS_IF_CFG_3_TIMG_CC2           (3)
#define SYS_DMA_HS_IF_MSK_3_TIMG_CC2           (0x00003000UL)
#define SYS_DMA_HS_IF_IDX_3_TIMG_CC3           (8)
#define SYS_DMA_HS_IF_CFG_3_TIMG_CC3           (3)
#define SYS_DMA_HS_IF_MSK_3_TIMG_CC3           (0x00030000UL)
#define SYS_DMA_HS_IF_IDX_3_TIMG_CC4           (10)
#define SYS_DMA_HS_IF_CFG_3_TIMG_CC4           (3)
#define SYS_DMA_HS_IF_MSK_3_TIMG_CC4           (0x00300000UL)
#define SYS_DMA_HS_IF_IDX_3_TIMG_UDT           (12)
#define SYS_DMA_HS_IF_CFG_3_TIMG_UDT           (3)
#define SYS_DMA_HS_IF_MSK_3_TIMG_UDT           (0x03000000UL)
#define SYS_DMA_HS_IF_IDX_3_TIMG_COMB          (14)
#define SYS_DMA_HS_IF_CFG_3_TIMG_COMB          (3)
#define SYS_DMA_HS_IF_MSK_3_TIMG_COMB          (0x30000000UL)
/**
  * @}
  */

/** @defgroup SYSCFG_SW_Reset System Software Reset
  * @{
  */ 
#define SYS_SWRST_RESET                (0)
#define SYS_SWRST_UART1                (SYSCFG_RST_CFG_UART1)
#define SYS_SWRST_UART2                (SYSCFG_RST_CFG_UART2)
#define SYS_SWRST_UART3                (SYSCFG_RST_CFG_UART3)
#define SYS_SWRST_UART4                (SYSCFG_RST_CFG_UART4)
#define SYS_SWRST_I2C1                 (SYSCFG_RST_CFG_I2C1)
#define SYS_SWRST_I2C2                 (SYSCFG_RST_CFG_I2C2)
#define SYS_SWRST_TIMB11               (SYSCFG_RST_CFG_TIMB11)
#define SYS_SWRST_TIMB12               (SYSCFG_RST_CFG_TIMB12)
#define SYS_SWRST_TIMB13               (SYSCFG_RST_CFG_TIMB13)
#define SYS_SWRST_TIMB14               (SYSCFG_RST_CFG_TIMB14)
#define SYS_SWRST_TIMB21               (SYSCFG_RST_CFG_TIMB21)
#define SYS_SWRST_TIMB22               (SYSCFG_RST_CFG_TIMB22)
#define SYS_SWRST_TIMB23               (SYSCFG_RST_CFG_TIMB23)
#define SYS_SWRST_TIMB24               (SYSCFG_RST_CFG_TIMB24)
#define SYS_SWRST_SPI1                 (SYSCFG_RST_CFG_SPI1)
#define SYS_SWRST_SPI2                 (SYSCFG_RST_CFG_SPI2)
#define SYS_SWRST_GPIO                 (SYSCFG_RST_CFG_GPIO)
#define SYS_SWRST_TIMA1                (SYSCFG_RST_CFG_TIMA1)
#define SYS_SWRST_TIMG1                (SYSCFG_RST_CFG_TIMG1)
#define SYS_SWRST_TIMA2                (SYSCFG_RST_CFG_TIMA2)
#define SYS_SWRST_TIMG2                (SYSCFG_RST_CFG_TIMG2)
#define SYS_SWRST_TIMG3                (SYSCFG_RST_CFG_TIMG3)
#define SYS_SWRST_TIMG4                (SYSCFG_RST_CFG_TIMG4)
  
#define IS_SYS_SWRST(RST)          (((RST) == SYS_SWRST_UART1) || \
                                    ((RST) == SYS_SWRST_UART2) || \
                                    ((RST) == SYS_SWRST_UART3) || \
                                    ((RST) == SYS_SWRST_UART4) || \
                                    ((RST) == SYS_SWRST_I2C1) || \
                                    ((RST) == SYS_SWRST_I2C2) || \
                                    ((RST) == SYS_SWRST_TIMB11) || \
                                    ((RST) == SYS_SWRST_TIMB12) || \
                                    ((RST) == SYS_SWRST_TIMB13) || \
                                    ((RST) == SYS_SWRST_TIMB14) || \
                                    ((RST) == SYS_SWRST_TIMB21) || \
                                    ((RST) == SYS_SWRST_TIMB22) || \
                                    ((RST) == SYS_SWRST_TIMB23) || \
                                    ((RST) == SYS_SWRST_TIMB24) || \
                                    ((RST) == SYS_SWRST_SPI1) || \
                                    ((RST) == SYS_SWRST_SPI2) || \
                                    ((RST) == SYS_SWRST_GPIO) || \
                                    ((RST) == SYS_SWRST_TIMA1) || \
                                    ((RST) == SYS_SWRST_TIMA2) || \
                                    ((RST) == SYS_SWRST_TIMG1) || \
                                    ((RST) == SYS_SWRST_TIMG2) || \
                                    ((RST) == SYS_SWRST_TIMG3) || \
                                    ((RST) == SYS_SWRST_TIMG4))

/**
  * @}
  */

/** @defgroup SYSCFG_TIMA_BRKSYSSRC System Adv. Timer System Break Source
  * @{
  */ 
#define SYS_TIMA_BRKSYSSRC_ECC         (SYSCFG_TACFG_ECCERR) 
#define SYS_TIMA_BRKSYSSRC_PARCHK      (SYSCFG_TACFG_PARCHK) 
#define SYS_TIMA_BRKSYSSRC_VOLDET      (SYSCFG_TACFG_VOLDET) 
#define SYS_TIMA_BRKSYSSRC_LKE         (SYSCFG_TACFG_LKE) 

#define IS_SYS_TIMA_BRKSYSSRC(SOURCE) (((SOURCE) == SYS_TIMA_BRKSYSSRC_ECC)  || \
                                       ((SOURCE) == SYS_TIMA_BRKSYSSRC_PARCHK) || \
                                       ((SOURCE) == SYS_TIMA_BRKSYSSRC_VOLDET)  || \
                                       ((SOURCE) == SYS_TIMA_BRKSYSSRC_LKE))


/**
  * @}
  */

/** @defgroup SYSCFG_GPIO_AUX System GPIO Aux
  * @{
  */
#define SYS_GPIO_AUXGROUP_A            (0)  
#define SYS_GPIO_AUXGROUP_B            (1)  
#define SYS_GPIO_AUXGROUP_C            (2)  
#define SYS_GPIO_AUXGROUP_D            (3)  

#define SYS_GPIO_AUX_INPUT             (0)
#define SYS_GPIO_AUX_OUTPUT            (1)

#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB11          (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB11           (0x00000001UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB11        (0)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB22          (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB22           (0x00000020UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB22        (5)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB23          (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB23           (0x00000040UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB23        (6)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB24          (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB24           (0x00000100UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB24        (8)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB23A         (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB23A          (0x00000200UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB23A       (9)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB22A         (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB22A          (0x00000400UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB22A       (10)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB21          (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB21           (0x00000800UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB21        (11)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB14          (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB14           (0x00001000UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB14        (12)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB13          (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB13           (0x00002000UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB13        (13)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB12          (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB12           (0x00004000UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB12        (14)
#define SYS_GPIO_AUX_IN_PORT_TIMG_CH4              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_TIMG_CH4               (0x00008000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMG_CH4            (15)
#define SYS_GPIO_AUX_IN_PORT_TIMG_CH2              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_TIMG_CH2               (0x00010000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMG_CH2            (16)
#define SYS_GPIO_AUX_IN_PORT_TIMG_CH1              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_TIMG_CH1               (0x00040000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMG_CH1            (18)
#define SYS_GPIO_AUX_IN_PORT_TIMG_CH3              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_TIMG_CH3               (0x00400000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMG_CH3            (22)
#define SYS_GPIO_AUX_IN_PORT_TIMG_ETR              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_TIMG_ETR               (0x00800000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMG_ETR            (23)
#define SYS_GPIO_AUX_IN_PORT_TIMA_ETR              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_TIMA_ETR               (0x01000000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMA_ETR            (24)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB14A         (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB14A          (0x02000000UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB14A       (25)

#define SYS_GPIO_AUX_OUT_PORT_TIMB11               (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB11                (0x00000002UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB11             (1)
#define SYS_GPIO_AUX_OUT_PORT_TIMB22               (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB22                (0x00000020UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB22             (5)
#define SYS_GPIO_AUX_OUT_PORT_TIMB23               (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB23                (0x00000040UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB23             (6)
#define SYS_GPIO_AUX_OUT_PORT_TIMB24               (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB24                (0x00000100UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB24             (8)
#define SYS_GPIO_AUX_OUT_PORT_TIMB23A              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB23A               (0x00000200UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB23A            (9)
#define SYS_GPIO_AUX_OUT_PORT_TIMB22A              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB22A               (0x00000400UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB22A            (10)
#define SYS_GPIO_AUX_OUT_PORT_TIMB21               (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB21                (0x00000800UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB21             (11)
#define SYS_GPIO_AUX_OUT_PORT_TIMB14               (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB14                (0x00001000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB14             (12)
#define SYS_GPIO_AUX_OUT_PORT_TIMB13               (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB13                (0x00002000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB13             (13)
#define SYS_GPIO_AUX_OUT_PORT_TIMB12               (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB12                (0x00004000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB12             (14)
#define SYS_GPIO_AUX_OUT_PORT_TIMG_CH4             (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMG_CH4              (0x00008000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMG_CH4           (15)
#define SYS_GPIO_AUX_OUT_PORT_TIMG_CH2N            (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMG_CH2N             (0x00010000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMG_CH2N          (16)
#define SYS_GPIO_AUX_OUT_PORT_TIMG_CH2P            (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMG_CH2P             (0x00020000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMG_CH2P          (17)
#define SYS_GPIO_AUX_OUT_PORT_TIMG_CH1N            (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMG_CH1N             (0x00040000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMG_CH1N          (18)
#define SYS_GPIO_AUX_OUT_PORT_TIMG_CH1P            (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMG_CH1P             (0x00080000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMG_CH1P          (19)
#define SYS_GPIO_AUX_OUT_PORT_TIMG_CH3N            (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMG_CH3N             (0x00400000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMG_CH3N          (22)
#define SYS_GPIO_AUX_OUT_PORT_TIMG_CH3P            (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMG_CH3P             (0x00800000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMG_CH3P          (23)
#define SYS_GPIO_AUX_OUT_PORT_TIMB14A              (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMB14A               (0x02000000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB14A            (25)
#define SYS_GPIO_AUX_OUT_PORT_TIMA_CH1P            (SYS_GPIO_AUXGROUP_B)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_CH1P             (0x04000000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_CH1P          (26)

#define SYS_GPIO_AUX_IN_PORT_TIMA_BRKIN2           (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_IN_PIN_TIMA_BRKIN2            (0x00000001UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMA_BRKIN2         (0)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB24A         (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB24A          (0x00000002UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB24A       (1)
#define SYS_GPIO_AUX_IN_PORT_EXCLK_TIMB21A         (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_IN_PIN_EXCLK_TIMB21A          (0x00000004UL)
#define SYS_GPIO_AUX_IN_PINIDX_EXCLK_TIMB21A       (2)
#define SYS_GPIO_AUX_IN_PORT_TIMA_CH3              (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_IN_PIN_TIMA_CH3               (0x00000200UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMA_CH3            (9)
#define SYS_GPIO_AUX_IN_PORT_TIMA_CH1              (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_IN_PIN_TIMA_CH1               (0x00010000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMA_CH1            (16)
#define SYS_GPIO_AUX_IN_PORT_TIMA_CH2              (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_IN_PIN_TIMA_CH2               (0x00040000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMA_CH2            (18)

#define SYS_GPIO_AUX_OUT_PORT_TIMB24A              (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMB24A               (0x00000002UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB24A            (1)
#define SYS_GPIO_AUX_OUT_PORT_TIMB21A              (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMB21A               (0x00000004UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMB21A            (2)
#define SYS_GPIO_AUX_OUT_PORT_TIMA_CH3P            (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_CH3P             (0x00000100UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_CH3P          (8)
#define SYS_GPIO_AUX_OUT_PORT_TIMA_CH3N            (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_CH3N             (0x00000200UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_CH3N          (9)
#define SYS_GPIO_AUX_OUT_PORT_TIMA_CH1N            (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_CH1N             (0x00010000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_CH1N          (16)
#define SYS_GPIO_AUX_OUT_PORT_TIMA_CH2P            (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_CH2P             (0x00020000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_CH2P          (17)
#define SYS_GPIO_AUX_OUT_PORT_TIMA_CH2N            (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_CH2N             (0x00040000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_CH2N          (18)
#define SYS_GPIO_AUX_OUT_PORT_TIMA_BRKOUT          (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_BRKOUT           (0x02000000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_BRKOUT        (25)
#define SYS_GPIO_AUX_OUT_PORT_TIMA_BRKOUT2         (SYS_GPIO_AUXGROUP_C)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_BRKOUT2          (0x04000000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_BRKOUT2       (26)

#define SYS_GPIO_AUX_IN_PORT_TIMA_BRKIN            (SYS_GPIO_AUXGROUP_D)
#define SYS_GPIO_AUX_IN_PIN_TIMA_BRKIN             (0x00000001UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMA_BRKIN          (0)
#define SYS_GPIO_AUX_IN_PORT_TIMA_CH4              (SYS_GPIO_AUXGROUP_D)
#define SYS_GPIO_AUX_IN_PIN_TIMA_CH4               (0x00008000UL)
#define SYS_GPIO_AUX_IN_PINIDX_TIMA_CH4            (15)

#define SYS_GPIO_AUX_OUT_PORT_TIMA_CH4             (SYS_GPIO_AUXGROUP_D)
#define SYS_GPIO_AUX_OUT_PIN_TIMA_CH4              (0x00008000UL)
#define SYS_GPIO_AUX_OUT_PINIDX_TIMA_CH4           (15)

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup SYSCFG_Exported_Functions
  * @{
  */

/** @addtogroup SYSCFG_Exported_Functions_Group1
  * @{
  */
/* SYSCFG configuration functions *********************************************/ 
void SYSCFG_MemoryRemapConfig(uint32_t SYSCFG_MemoryRemap);
void SYSCFG_MemoryRemapHW(void);

void SYSCFG_EnableFlashDMA(void);
void SYSCFG_DisableFlashDMA(void);

void SYSCFG_SetUARTMode(uint32_t SYSCFG_UARTMode);

void SYSCFG_SetSPIMode(uint32_t SYSCFG_SPIMode);

void SYSCFG_ICTLConfig(uint32_t ICTL_lines, uint32_t ICTL_Range, uint32_t SYSCFG_ICTLCfg);

void SYSCFG_DMAHSConfig(uint32_t SYSCFG_DMAHSIdx,uint32_t SYSCFG_DMAHSCfg);

void SYSCFG_EnableWDTWExternalClock(void);
void SYSCFG_DisableWDTWExternalClock(void);
void SYSCFG_WDTWReset(void);
void SYSCFG_WDTWResetRelease(void);

void SYSCFG_PeripheralReset(uint32_t SYSCFG_Reset);
void SYSCFG_PeripheralResetRelease(uint32_t SYSCFG_Reset);

void SYSCFG_TIMASysBreakEnable(uint32_t SYSCFG_SysBreak);
void SYSCFG_TIMASysBreakDisable(uint32_t SYSCFG_SysBreak);

void SYSCFG_SetGPIOOutAux(uint32_t Port, uint32_t Pin);
void SYSCFG_SetGPIOInAux(uint32_t Port, uint32_t Pin);

void SYSCFG_GetUID(Uint32_t * pUID);
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

#endif /*__XT32H0XX_SYSCFG_H */

