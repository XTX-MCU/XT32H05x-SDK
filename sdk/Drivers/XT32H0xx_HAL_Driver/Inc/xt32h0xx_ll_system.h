/**
  ******************************************************************************
  * @file    xt32h0xx_ll_system.h
  * @author  Software Team
  * @brief   Header file of SYSTEM LL module.
  @verbatim
  ==============================================================================
                     ##### How to use this driver #####
  ==============================================================================
    [..]
    The LL SYSTEM driver contains a set of generic APIs that can be
    used by user:
      (+) Some of the FLASH features need to be handled in the SYSTEM file.
      (+) Access to SYSCFG registers

  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_SYSTEM_H
#define XT32H0xx_LL_SYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

//#if defined (FLASH) || defined (SYSCFG) 

/** @defgroup SYSTEM_LL SYSTEM
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Private_Constants SYSTEM Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Exported_Constants SYSTEM Exported Constants
  * @{
  */

/** @defgroup SYSTEM_LL_EC_REMAP System Memort Remap
  * @{
  */
#define LL_SYSCFG_REMAP_FLASH          (0x00000000U)                           /*!< Main Flash memory mapped at 0x00000000 */
#define LL_SYSCFG_REMAP_ROM            (SYSCFG_SYS_CFG_BOOT_MODE_0)            /*!< System Flash memory mapped at 0x00000000 */
#define LL_SYSCFG_REMAP_SRAM           (SYSCFG_SYS_CFG_BOOT_MODE_1)            /*!< Embedded SRAM mapped at 0x00000000 */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_SRAM System SRAM
  * @{
  */
#define LL_SRAM_BANK_0                 (0)  
#define LL_SRAM_BANK_1                 (1)  
#define LL_SRAM_BANK_2                 (2)  
#define LL_SRAM_BANK_3                 (3)  

#define LL_SRAM_TEST1_DISABLE          (0x00000000U)                           /*!< bypass self-timed circuit disable */
#define LL_SRAM_TEST1_ENABLE           (SYSCFG_SRAM_CFG_TEST1)                 /*!< bypass self-timed circuit enable */
   
#define LL_SRAM_INTERNAL_RM            (0x00000000U)                           /*!< Internal RM */
#define LL_SRAM_EXTERNAL_EM            (SYSCFG_SRAM_CFG_RME)                   /*!< External RM */

#define LL_SRAM_RW_MARGIN_0            (0)
#define LL_SRAM_RW_MARGIN_1            (SYSCFG_SRAM_CFG_RM_0)
#define LL_SRAM_RW_MARGIN_2            (SYSCFG_SRAM_CFG_RM_1)
#define LL_SRAM_RW_MARGIN_3            (SYSCFG_SRAM_CFG_RM_1|SYSCFG_SRAM_CFG_RM_0)

#define LL_SRAM_TEST_P_0               (0)
#define LL_SRAM_TEST_P_1               (SYSCFG_SRAM_CFG_RM_2)
#define LL_SRAM_TEST_P_2               (SYSCFG_SRAM_CFG_RM_3)
#define LL_SRAM_TEST_P_3               (SYSCFG_SRAM_CFG_RM_3|SYSCFG_SRAM_CFG_RM_2)

#define LL_SRAM_WL_0                   (0)
#define LL_SRAM_WL_1                   (SYSCFG_SRAM_CFG_RA_0)
#define LL_SRAM_WL_2                   (SYSCFG_SRAM_CFG_RA_1)
#define LL_SRAM_WL_3                   (SYSCFG_SRAM_CFG_RA_1|SYSCFG_SRAM_CFG_RA_0)

#define LL_SRAM_NV_0                   (0)
#define LL_SRAM_NV_1                   (SYSCFG_SRAM_CFG_WA_0)
#define LL_SRAM_NV_2                   (SYSCFG_SRAM_CFG_WA_1)
#define LL_SRAM_NV_3                   (SYSCFG_SRAM_CFG_WA_1|SYSCFG_SRAM_CFG_WA_0)

#define LL_SRAM_WA_DISABLE             (0)
#define LL_SRAM_WA_ENABLE              (SYSCFG_SRAM_CFG_WA_2)

#define LL_SRAM_MODE_LIGHTSLEEP        (1UL)
#define LL_SRAM_MODE_DEEPSLEEP         (2UL)
#define LL_SRAM_MODE_SHUTDWON          (4UL)

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_SPI System SPI Mode
  * @{
  */
#define LL_SPI_1_MODE_SLAVE            (0)  
#define LL_SPI_1_MODE_MASTER           (SYSCFG_SYS_CFG_SPI1_MODE)  

#define LL_SPI_2_MODE_SLAVE            (0)  
#define LL_SPI_2_MODE_MASTER           (SYSCFG_SYS_CFG_SPI2_MODE)  
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_IRQ System IRQ Configure
  * @{
  */
#define   LL_IRQ_CFG_1                 (0)  
#define   LL_IRQ_CFG_2                 (1)  
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_SOFTWARE_RESET System Software Reset
  * @{
  */
#define LL_SWRST_RESET                 (0)
#define LL_SWRST_UART0                 (SYSCFG_RST_CFG_UART1)
#define LL_SWRST_UART1                 (SYSCFG_RST_CFG_UART2)
#define LL_SWRST_UART2                 (SYSCFG_RST_CFG_UART3)
#define LL_SWRST_UART3                 (SYSCFG_RST_CFG_UART4)
#define LL_SWRST_I2C0                  (SYSCFG_RST_CFG_I2C1)
#define LL_SWRST_I2C1                  (SYSCFG_RST_CFG_I2C2)
#define LL_SWRST_TIMB11                (SYSCFG_RST_CFG_TIMB11)
#define LL_SWRST_TIMB12                (SYSCFG_RST_CFG_TIMB12)
#define LL_SWRST_TIMB13                (SYSCFG_RST_CFG_TIMB13)
#define LL_SWRST_TIMB14                (SYSCFG_RST_CFG_TIMB14)
#define LL_SWRST_TIMB21                (SYSCFG_RST_CFG_TIMB21)
#define LL_SWRST_TIMB22                (SYSCFG_RST_CFG_TIMB22)
#define LL_SWRST_TIMB23                (SYSCFG_RST_CFG_TIMB23)
#define LL_SWRST_TIMB24                (SYSCFG_RST_CFG_TIMB24)
#define LL_SWRST_SPI0                  (SYSCFG_RST_CFG_SPI1)
#define LL_SWRST_SPI1                  (SYSCFG_RST_CFG_SPI2)
#define LL_SWRST_GPIO                  (SYSCFG_RST_CFG_GPIO)
#define LL_SWRST_TIMA1                 (SYSCFG_RST_CFG_TIMA1)
#define LL_SWRST_TIMA2                 (SYSCFG_RST_CFG_TIMA2)
#define LL_SWRST_TIMG1                 (SYSCFG_RST_CFG_TIMG1)
#define LL_SWRST_TIMG2                 (SYSCFG_RST_CFG_TIMG2)
#define LL_SWRST_TIMG3                 (SYSCFG_RST_CFG_TIMG3)
#define LL_SWRST_TIMG4                 (SYSCFG_RST_CFG_TIMG4)

/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_EPWM_BRK_ECC System PWM ECC Break
  * @{
  */
#define LL_PWMBRK_ECC_DISABLE          (0x00000000U)                           /*!< ePWM break ECC error disable */
#define LL_PWMBRK_ECC_ENABLE           (SYSCFG_TACFG_ECCERR)                   /*!< ePWM break ECC error enable */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_EPWM_BRK_PARCHK System parity Check Break
  * @{
  */
#define LL_PWMBRK_PARCHK_DISABLE       (0x00000000U)                           /*!< ePWM break parity error disable */
#define LL_PWMBRK_PARCHK_ENABLE        (SYSCFG_TACFG_PARCHK)                   /*!< ePWM break parity error enable */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_EPWM_BRK_VOLDET System Power Volatge Detect Break
  * @{
  */
#define LL_PWMBRK_VOLDET_DISABLE       (0x00000000U)                           /*!< ePWM break voltage detector disable */
#define LL_PWMBRK_VOLDET_ENABLE        (SYSCFG_TACFG_VOLDET)                   /*!< ePWM breakvoltage detector enable */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_EPWM_BRK_LKE System Lockup Break
  * @{
  */
#define LL_PWMBRK_LOCKUP_DISABLE       (0x00000000U)                           /*!< ePWM break CPU core lockup disable */
#define LL_PWMBRK_LOCKUP_ENABLE        (SYSCFG_TACFG_LKE)                      /*!< ePWM break  CPU core lockup enable */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_GPIO_AUX System GPIO AUX
  * @{
  */
#define LL_GPIO_AUXGROUP_A             (0)  
#define LL_GPIO_AUXGROUP_B             (1)  
#define LL_GPIO_AUXGROUP_C             (2)  
#define LL_GPIO_AUXGROUP_D             (3)  

#define LL_GPIO_AUX_INPUT              (0)
#define LL_GPIO_AUX_OUTPUT             (1)

#if defined(XT32H0xxB)
#define LL_GPIO_A_PIN_0_IN_F               (0x00000001UL)
#define LL_GPIO_A_PIN_1_IN_F               (0x00000002UL)
#define LL_GPIO_A_PIN_2_IN_F               (0x00000004UL)
#define LL_GPIO_A_PIN_3_IN_F               (0x00000008UL)
#define LL_GPIO_A_PIN_4_IN_F               (0x00000010UL)
#define LL_GPIO_A_PIN_5_IN_F               (0x00000020UL)
#define LL_GPIO_A_PIN_6_IN_F               (0x00000040UL)
#define LL_GPIO_A_PIN_7_IN_F               (0x00000080UL)
#define LL_GPIO_A_PIN_8_IN_F               (0x00000100UL)
#define LL_GPIO_A_PIN_9_IN_F               (0x00000200UL)
#define LL_GPIO_A_PIN_10_IN_F              (0x00000400UL)
#define LL_GPIO_A_PIN_11_IN_F              (0x00000800UL)
#define LL_GPIO_A_PIN_12_IN_F              (0x00001000UL)
#define LL_GPIO_A_PIN_13_IN_F              (0x00002000UL)
#define LL_GPIO_A_PIN_14_IN_F              (0x00004000UL)
#define LL_GPIO_A_PIN_15_IN_F              (0x00008000UL)
#define LL_GPIO_A_PIN_16_IN_F              (0x00010000UL)
#define LL_GPIO_A_PIN_17_IN_F              (0x00020000UL)
#define LL_GPIO_A_PIN_18_IN_F              (0x00040000UL)
#define LL_GPIO_A_PIN_19_IN_F              (0x00080000UL)
#define LL_GPIO_A_PIN_20_IN_F              (0x00100000UL)
#define LL_GPIO_A_PIN_21_IN_F              (0x00200000UL)
#define LL_GPIO_A_PIN_22_IN_F              (0x00400000UL)
#define LL_GPIO_A_PIN_23_IN_F              (0x00800000UL)
#define LL_GPIO_A_PIN_24_IN_F              (0x01000000UL)
#define LL_GPIO_A_PIN_25_IN_F              (0x02000000UL)
#define LL_GPIO_A_PIN_26_IN_F              (0x04000000UL)
#define LL_GPIO_A_PIN_27_IN_F              (0x08000000UL)
#define LL_GPIO_A_PIN_28_IN_F              (0x10000000UL)
#define LL_GPIO_A_PIN_29_IN_F              (0x20000000UL)
#define LL_GPIO_A_PIN_30_IN_F              (0x40000000UL)
#define LL_GPIO_A_PIN_31_IN_F              (0x80000000UL)

#define LL_GPIO_B_PIN_0_IN_EXCLK_TIMB11    (0x00000001UL)
#define LL_GPIO_B_PIN_1_IN_TIMA2_BRKIN2    (0x00000002UL)
#define LL_GPIO_B_PIN_2_IN_TIMG2_ETR       (0x00000004UL)
#define LL_GPIO_B_PIN_3_IN_TIMA2_BRKIN     (0x00000008UL)
#define LL_GPIO_B_PIN_4_IN_TIMA2_CH4IN     (0x00000010UL)
#define LL_GPIO_B_PIN_5_IN_EXCLK_TIMB22    (0x00000020UL)
#define LL_GPIO_B_PIN_6_IN_EXCLK_TIMB23    (0x00000040UL)
#define LL_GPIO_B_PIN_7_IN_F               (0x00000080UL)
#define LL_GPIO_B_PIN_8_IN_EXCLK_TIMB12    (0x00000100UL)
#define LL_GPIO_B_PIN_9_IN_EXCLK_TIMB11    (0x00000200UL)
#define LL_GPIO_B_PIN_10_IN_EXCLK_TIMB22   (0x00000400UL)
#define LL_GPIO_B_PIN_11_IN_EXCLK_TIMB21   (0x00000800UL)
#define LL_GPIO_B_PIN_12_IN_EXCLK_TIMB14   (0x00001000UL)
#define LL_GPIO_B_PIN_13_IN_EXCLK_TIMB13   (0x00002000UL)
#define LL_GPIO_B_PIN_14_IN_EXCLK_TIMB12   (0x00004000UL)
#define LL_GPIO_B_PIN_15_IN_TIMA1_CH2IN    (0x00008000UL)
#define LL_GPIO_B_PIN_16_IN_TIMG_CH2IN     (0x00010000UL)
#define LL_GPIO_B_PIN_17_IN_F              (0x00020000UL)
#define LL_GPIO_B_PIN_18_IN_TIMG_CH1IN     (0x00040000UL)
#define LL_GPIO_B_PIN_19_IN_F              (0x00080000UL)
#define LL_GPIO_B_PIN_20_IN_F              (0x00100000UL)
#define LL_GPIO_B_PIN_21_IN_F              (0x00200000UL)
#define LL_GPIO_B_PIN_22_IN_TIMG_CH3IN     (0x00400000UL)
#define LL_GPIO_B_PIN_23_IN_TIMG_ETR       (0x00800000UL)
#define LL_GPIO_B_PIN_24_IN_TIMA1_ETR      (0x01000000UL)
#define LL_GPIO_B_PIN_25_IN_EXCLK_TIMB14   (0x02000000UL)
#define LL_GPIO_B_PIN_26_IN_F              (0x04000000UL)
#define LL_GPIO_B_PIN_27_IN_F              (0x08000000UL)
#define LL_GPIO_B_PIN_28_IN_F              (0x10000000UL)
#define LL_GPIO_B_PIN_29_IN_F              (0x20000000UL)
#define LL_GPIO_B_PIN_30_IN_F              (0x40000000UL)
#define LL_GPIO_B_PIN_31_IN_F              (0x80000000UL)

#define LL_GPIO_C_PIN_0_IN_TIMA1_BRKIN2    (0x00000001UL)
#define LL_GPIO_C_PIN_1_IN_TIMG4_CH1IN     (0x00000002UL)
#define LL_GPIO_C_PIN_2_IN_F               (0x00000004UL)
#define LL_GPIO_C_PIN_3_IN_TIMA2_CH3IN     (0x00000008UL)
#define LL_GPIO_C_PIN_4_IN_F               (0x00000010UL)
#define LL_GPIO_C_PIN_5_IN_F               (0x00000020UL)
#define LL_GPIO_C_PIN_6_IN_F               (0x00000040UL)
#define LL_GPIO_C_PIN_7_IN_F               (0x00000080UL)
#define LL_GPIO_C_PIN_8_IN_TIMG1_ETR       (0x00000100UL)
#define LL_GPIO_C_PIN_9_IN_TIMA1_BRKIN     (0x00000200UL)
#define LL_GPIO_C_PIN_10_IN_F              (0x00000400UL)
#define LL_GPIO_C_PIN_11_IN_F              (0x00000800UL)
#define LL_GPIO_C_PIN_12_IN_F              (0x00001000UL)
#define LL_GPIO_C_PIN_13_IN_F              (0x00002000UL)
#define LL_GPIO_C_PIN_14_IN_F              (0x00004000UL)
#define LL_GPIO_C_PIN_15_IN_F              (0x00008000UL)
#define LL_GPIO_C_PIN_16_IN_TIMA1_CH1IN    (0x00010000UL)
#define LL_GPIO_C_PIN_17_IN_F              (0x00020000UL)
#define LL_GPIO_C_PIN_18_IN_TIMA1_CH2IN    (0x00040000UL)
#define LL_GPIO_C_PIN_19_IN_F              (0x00080000UL)
#define LL_GPIO_C_PIN_20_IN_F              (0x00100000UL)
#define LL_GPIO_C_PIN_21_IN_F              (0x00200000UL)
#define LL_GPIO_C_PIN_22_IN_F              (0x00400000UL)
#define LL_GPIO_C_PIN_23_IN_F              (0x00800000UL)
#define LL_GPIO_C_PIN_24_IN_EXTTRG         (0x01000000UL)
#define LL_GPIO_C_PIN_25_IN_TIMG2_CH4IN    (0x02000000UL)
#define LL_GPIO_C_PIN_26_IN_F              (0x04000000UL)
#define LL_GPIO_C_PIN_27_IN_TIMG2_CH1IN    (0x08000000UL)
#define LL_GPIO_C_PIN_28_IN_TIMG4_CH2IN    (0x10000000UL)
#define LL_GPIO_C_PIN_29_IN_TIMG3_CH2IN    (0x20000000UL)
#define LL_GPIO_C_PIN_30_IN_TIMG2_ETR      (0x40000000UL)
#define LL_GPIO_C_PIN_31_IN_TIMG2_CH2IN    (0x80000000UL)

#define LL_GPIO_D_PIN_0_IN_TIMA1_ETR       (0x00000001UL)
#define LL_GPIO_D_PIN_1_IN_F               (0x00000002UL)
#define LL_GPIO_D_PIN_2_IN_F               (0x00000004UL)
#define LL_GPIO_D_PIN_3_IN_F               (0x00000008UL)
#define LL_GPIO_D_PIN_4_IN_F               (0x00000010UL)
#define LL_GPIO_D_PIN_5_IN_F               (0x00000020UL)
#define LL_GPIO_D_PIN_6_IN_F               (0x00000040UL)
#define LL_GPIO_D_PIN_7_IN_F               (0x00000080UL)
#define LL_GPIO_D_PIN_8_IN_TIMG1_CH2IN     (0x00000100UL)
#define LL_GPIO_D_PIN_9_IN_F               (0x00000200UL)
#define LL_GPIO_D_PIN_10_IN_F              (0x00000400UL)
#define LL_GPIO_D_PIN_11_IN_F              (0x00000800UL)
#define LL_GPIO_D_PIN_12_IN_F              (0x00001000UL)
#define LL_GPIO_D_PIN_13_IN_F              (0x00002000UL)
#define LL_GPIO_D_PIN_14_IN_F              (0x00004000UL)
#define LL_GPIO_D_PIN_15_IN_TIMA1_CH3IN    (0x00008000UL)
#define LL_GPIO_D_PIN_16_IN_TIMG1_CH3IN    (0x00010000UL)
#define LL_GPIO_D_PIN_17_IN_TIMA2_ETR      (0x00020000UL)
#define LL_GPIO_D_PIN_18_IN_F              (0x00040000UL)
#define LL_GPIO_D_PIN_19_IN_F              (0x00080000UL)
#define LL_GPIO_D_PIN_20_IN_F              (0x00100000UL)
#define LL_GPIO_D_PIN_21_IN_F              (0x00200000UL)
#define LL_GPIO_D_PIN_22_IN_TIMG1_CH1IN    (0x00400000UL)
#define LL_GPIO_D_PIN_23_IN_TIMA1_CH4IN    (0x00800000UL)
#define LL_GPIO_D_PIN_24_IN_F              (0x01000000UL)
#define LL_GPIO_D_PIN_25_IN_F              (0x02000000UL)
#define LL_GPIO_D_PIN_26_IN_F              (0x04000000UL)
#define LL_GPIO_D_PIN_27_IN_F              (0x08000000UL)
#define LL_GPIO_D_PIN_28_IN_F              (0x10000000UL)
#define LL_GPIO_D_PIN_29_IN_F              (0x20000000UL)
#define LL_GPIO_D_PIN_30_IN_F              (0x40000000UL)
#define LL_GPIO_D_PIN_31_IN_F              (0x80000000UL)

#define LL_GPIO_A_PIN_0_OUT_F              (0x00000001UL)
#define LL_GPIO_A_PIN_1_OUT_F              (0x00000002UL)
#define LL_GPIO_A_PIN_2_OUT_F              (0x00000004UL)
#define LL_GPIO_A_PIN_3_OUT_F              (0x00000008UL)
#define LL_GPIO_A_PIN_4_OUT_F              (0x00000010UL)
#define LL_GPIO_A_PIN_5_OUT_F              (0x00000020UL)
#define LL_GPIO_A_PIN_6_OUT_F              (0x00000040UL)
#define LL_GPIO_A_PIN_7_OUT_F              (0x00000080UL)
#define LL_GPIO_A_PIN_8_OUT_F              (0x00000100UL)
#define LL_GPIO_A_PIN_9_OUT_F              (0x00000200UL)
#define LL_GPIO_A_PIN_10_OUT_F             (0x00000400UL)
#define LL_GPIO_A_PIN_11_OUT_F             (0x00000800UL)
#define LL_GPIO_A_PIN_12_OUT_F             (0x00001000UL)
#define LL_GPIO_A_PIN_13_OUT_F             (0x00002000UL)
#define LL_GPIO_A_PIN_14_OUT_F             (0x00004000UL)
#define LL_GPIO_A_PIN_15_OUT_F             (0x00008000UL)
#define LL_GPIO_A_PIN_16_OUT_F             (0x00010000UL)
#define LL_GPIO_A_PIN_17_OUT_F             (0x00020000UL)
#define LL_GPIO_A_PIN_18_OUT_F             (0x00040000UL)
#define LL_GPIO_A_PIN_19_OUT_F             (0x00080000UL)
#define LL_GPIO_A_PIN_20_OUT_F             (0x00100000UL)
#define LL_GPIO_A_PIN_21_OUT_F             (0x00200000UL)
#define LL_GPIO_A_PIN_22_OUT_F             (0x00400000UL)
#define LL_GPIO_A_PIN_23_OUT_F             (0x00800000UL)
#define LL_GPIO_A_PIN_24_OUT_F             (0x01000000UL)
#define LL_GPIO_A_PIN_25_OUT_F             (0x02000000UL)
#define LL_GPIO_A_PIN_26_OUT_F             (0x04000000UL)
#define LL_GPIO_A_PIN_27_OUT_F             (0x08000000UL)
#define LL_GPIO_A_PIN_28_OUT_F             (0x10000000UL)
#define LL_GPIO_A_PIN_29_OUT_F             (0x20000000UL)
#define LL_GPIO_A_PIN_30_OUT_F             (0x40000000UL)
#define LL_GPIO_A_PIN_31_OUT_F             (0x80000000UL)

#define LL_GPIO_B_PIN_0_OUT_TIMA1_CH1ON    (0x00000001UL)
#define LL_GPIO_B_PIN_1_OUT_TIMA1_CH1O     (0x00000002UL)
#define LL_GPIO_B_PIN_2_OUT_TIMG2_CH3ON    (0x00000004UL)
#define LL_GPIO_B_PIN_3_OUT_TIMG2_CH2ON    (0x00000008UL)
#define LL_GPIO_B_PIN_4_OUT_TIMA2_CH4O     (0x00000010UL)
#define LL_GPIO_B_PIN_5_OUT_TIMB22         (0x00000020UL)
#define LL_GPIO_B_PIN_6_OUT_TIMB23         (0x00000040UL)
#define LL_GPIO_B_PIN_7_OUT_F              (0x00000080UL)
#define LL_GPIO_B_PIN_8_OUT_TIMB12         (0x00000100UL)
#define LL_GPIO_B_PIN_9_OUT_TIMB11         (0x00000200UL)
#define LL_GPIO_B_PIN_10_OUT_TIMB22        (0x00000400UL)
#define LL_GPIO_B_PIN_11_OUT_TIMA1_CH1ON   (0x00000800UL)
#define LL_GPIO_B_PIN_12_OUT_TIMA1_CH1O    (0x00001000UL)
#define LL_GPIO_B_PIN_13_OUT_TIMB13        (0x00002000UL)
#define LL_GPIO_B_PIN_14_OUT_TIMA1_CH2ON   (0x00004000UL)
#define LL_GPIO_B_PIN_15_OUT_TIMA1_CH2O    (0x00008000UL)
#define LL_GPIO_B_PIN_16_OUT_TIMA1_CH2ON   (0x00010000UL)
#define LL_GPIO_B_PIN_17_OUT_TIMA1_CH2O    (0x00020000UL)
#define LL_GPIO_B_PIN_18_OUT_TIMA1_CH3ON   (0x00040000UL)
#define LL_GPIO_B_PIN_19_OUT_TIMA1_CH3O    (0x00080000UL)
#define LL_GPIO_B_PIN_20_OUT_F             (0x00100000UL)
#define LL_GPIO_B_PIN_21_OUT_F             (0x00200000UL)
#define LL_GPIO_B_PIN_22_OUT_TIMG_CH3N     (0x00400000UL)
#define LL_GPIO_B_PIN_23_OUT_TIMG_CH3P     (0x00800000UL)
#define LL_GPIO_B_PIN_24_OUT_TIMA1_CH3O    (0x01000000UL)
#define LL_GPIO_B_PIN_25_OUT_TIMB14        (0x02000000UL)
#define LL_GPIO_B_PIN_26_OUT_TIMA1_CH1O    (0x04000000UL)
#define LL_GPIO_B_PIN_27_OUT_F             (0x08000000UL)
#define LL_GPIO_B_PIN_28_OUT_F             (0x10000000UL)
#define LL_GPIO_B_PIN_29_OUT_F             (0x20000000UL)
#define LL_GPIO_B_PIN_30_OUT_F             (0x40000000UL)
#define LL_GPIO_B_PIN_31_OUT_F             (0x80000000UL)

#define LL_GPIO_C_PIN_0_OUT_F              (0x00000001UL)
#define LL_GPIO_C_PIN_1_OUT_TIMB24         (0x00000002UL)
#define LL_GPIO_C_PIN_2_OUT_TIMB21         (0x00000004UL)
#define LL_GPIO_C_PIN_3_OUT_F              (0x00000008UL)
#define LL_GPIO_C_PIN_4_OUT_TIMG4_CH1O     (0x00000010UL)
#define LL_GPIO_C_PIN_5_OUT_TIMG4_CH1ON    (0x00000020UL)
#define LL_GPIO_C_PIN_6_OUT_F              (0x00000040UL)
#define LL_GPIO_C_PIN_7_OUT_F              (0x00000080UL)
#define LL_GPIO_C_PIN_8_OUT_TIMA1_CH3ON    (0x00000100UL)
#define LL_GPIO_C_PIN_9_OUT_TIMG1_CH1ON    (0x00000200UL)
#define LL_GPIO_C_PIN_10_OUT_F             (0x00000400UL)
#define LL_GPIO_C_PIN_11_OUT_F             (0x00000800UL)
#define LL_GPIO_C_PIN_12_OUT_F             (0x00001000UL)
#define LL_GPIO_C_PIN_13_OUT_F             (0x00002000UL)
#define LL_GPIO_C_PIN_14_OUT_F             (0x00004000UL)
#define LL_GPIO_C_PIN_15_OUT_F             (0x00008000UL)
#define LL_GPIO_C_PIN_16_OUT_TIMA1_CH1ON   (0x00010000UL)
#define LL_GPIO_C_PIN_17_OUT_TIMA1_CH2O    (0x00020000UL)
#define LL_GPIO_C_PIN_18_OUT_TIMA1_CH2ON   (0x00040000UL)
#define LL_GPIO_C_PIN_19_OUT_TIMA2_BRK     (0x00080000UL)
#define LL_GPIO_C_PIN_20_OUT_F             (0x00100000UL)
#define LL_GPIO_C_PIN_21_OUT_F             (0x00200000UL)
#define LL_GPIO_C_PIN_22_OUT_F             (0x00400000UL)
#define LL_GPIO_C_PIN_23_OUT_F             (0x00800000UL)
#define LL_GPIO_C_PIN_24_OUT_F             (0x01000000UL)
#define LL_GPIO_C_PIN_25_OUT_TIMG2_CH4O    (0x02000000UL)
#define LL_GPIO_C_PIN_26_OUT_TIMG2_CH1ON   (0x04000000UL)
#define LL_GPIO_C_PIN_27_OUT_TIMG2_CH1O    (0x08000000UL)
#define LL_GPIO_C_PIN_28_OUT_TIMG4_CH2O    (0x10000000UL)
#define LL_GPIO_C_PIN_29_OUT_TIMG3_CH2O    (0x20000000UL)
#define LL_GPIO_C_PIN_30_OUT_TIMG2_CH3O    (0x40000000UL)
#define LL_GPIO_C_PIN_31_OUT_TIMG2_CH2O    (0x80000000UL)

#define LL_GPIO_D_PIN_0_OUT_F              (0x00000001UL)
#define LL_GPIO_D_PIN_1_OUT_F              (0x00000002UL)
#define LL_GPIO_D_PIN_2_OUT_F              (0x00000004UL)
#define LL_GPIO_D_PIN_3_OUT_F              (0x00000008UL)
#define LL_GPIO_D_PIN_4_OUT_F              (0x00000010UL)
#define LL_GPIO_D_PIN_5_OUT_F              (0x00000020UL)
#define LL_GPIO_D_PIN_6_OUT_F              (0x00000040UL)
#define LL_GPIO_D_PIN_7_OUT_F              (0x00000080UL)
#define LL_GPIO_D_PIN_8_OUT_TIMG1_CH2O     (0x00000100UL)
#define LL_GPIO_D_PIN_9_OUT_F              (0x00000200UL)
#define LL_GPIO_D_PIN_10_OUT_F             (0x00000400UL)
#define LL_GPIO_D_PIN_11_OUT_F             (0x00000800UL)
#define LL_GPIO_D_PIN_12_OUT_F             (0x00001000UL)
#define LL_GPIO_D_PIN_13_OUT_F             (0x00002000UL)
#define LL_GPIO_D_PIN_14_OUT_F             (0x00004000UL)
#define LL_GPIO_D_PIN_15_OUT_TIMA1_CH3ON   (0x00008000UL)
#define LL_GPIO_D_PIN_16_OUT_TIMG1_CH3O    (0x00010000UL)
#define LL_GPIO_D_PIN_17_OUT_F             (0x00020000UL)
#define LL_GPIO_D_PIN_18_OUT_F             (0x00040000UL)
#define LL_GPIO_D_PIN_19_OUT_F             (0x00080000UL)
#define LL_GPIO_D_PIN_20_OUT_F             (0x00100000UL)
#define LL_GPIO_D_PIN_21_OUT_F             (0x00200000UL)
#define LL_GPIO_D_PIN_22_OUT_TIMG1_CH1O    (0x00400000UL)
#define LL_GPIO_D_PIN_23_OUT_TIMA1_CH4O    (0x00800000UL)
#define LL_GPIO_D_PIN_24_OUT_F             (0x01000000UL)
#define LL_GPIO_D_PIN_25_OUT_F             (0x02000000UL)
#define LL_GPIO_D_PIN_26_OUT_F             (0x04000000UL)
#define LL_GPIO_D_PIN_27_OUT_F             (0x08000000UL)
#define LL_GPIO_D_PIN_28_OUT_F             (0x10000000UL)
#define LL_GPIO_D_PIN_29_OUT_F             (0x20000000UL)
#define LL_GPIO_D_PIN_30_OUT_F             (0x40000000UL)
#define LL_GPIO_D_PIN_31_OUT_F             (0x80000000UL)
#else
#define LL_GPIO_A_PIN_0_IN_F               (0x00000001UL)
#define LL_GPIO_A_PIN_1_IN_F               (0x00000002UL)
#define LL_GPIO_A_PIN_2_IN_F               (0x00000004UL)
#define LL_GPIO_A_PIN_3_IN_F               (0x00000008UL)
#define LL_GPIO_A_PIN_4_IN_F               (0x00000010UL)
#define LL_GPIO_A_PIN_5_IN_F               (0x00000020UL)
#define LL_GPIO_A_PIN_6_IN_F               (0x00000040UL)
#define LL_GPIO_A_PIN_7_IN_F               (0x00000080UL)
#define LL_GPIO_A_PIN_8_IN_F               (0x00000100UL)
#define LL_GPIO_A_PIN_9_IN_F               (0x00000200UL)
#define LL_GPIO_A_PIN_10_IN_F              (0x00000400UL)
#define LL_GPIO_A_PIN_11_IN_F              (0x00000800UL)
#define LL_GPIO_A_PIN_12_IN_F              (0x00001000UL)
#define LL_GPIO_A_PIN_13_IN_F              (0x00002000UL)
#define LL_GPIO_A_PIN_14_IN_F              (0x00004000UL)
#define LL_GPIO_A_PIN_15_IN_F              (0x00008000UL)
#define LL_GPIO_A_PIN_16_IN_F              (0x00010000UL)
#define LL_GPIO_A_PIN_17_IN_F              (0x00020000UL)
#define LL_GPIO_A_PIN_18_IN_F              (0x00040000UL)
#define LL_GPIO_A_PIN_19_IN_F              (0x00080000UL)
#define LL_GPIO_A_PIN_20_IN_F              (0x00100000UL)
#define LL_GPIO_A_PIN_21_IN_F              (0x00200000UL)
#define LL_GPIO_A_PIN_22_IN_F              (0x00400000UL)
#define LL_GPIO_A_PIN_23_IN_F              (0x00800000UL)
#define LL_GPIO_A_PIN_24_IN_F              (0x01000000UL)
#define LL_GPIO_A_PIN_25_IN_F              (0x02000000UL)
#define LL_GPIO_A_PIN_26_IN_F              (0x04000000UL)
#define LL_GPIO_A_PIN_27_IN_F              (0x08000000UL)
#define LL_GPIO_A_PIN_28_IN_F              (0x10000000UL)
#define LL_GPIO_A_PIN_29_IN_F              (0x20000000UL)
#define LL_GPIO_A_PIN_30_IN_F              (0x40000000UL)
#define LL_GPIO_A_PIN_31_IN_F              (0x80000000UL)

#define LL_GPIO_B_PIN_0_IN_EXCLK_TIMB11    (0x00000001UL)
#define LL_GPIO_B_PIN_1_IN_F               (0x00000002UL)
#define LL_GPIO_B_PIN_2_IN_F               (0x00000004UL)
#define LL_GPIO_B_PIN_3_IN_F               (0x00000008UL)
#define LL_GPIO_B_PIN_4_IN_F               (0x00000010UL)
#define LL_GPIO_B_PIN_5_IN_EXCLK_TIMB22    (0x00000020UL)
#define LL_GPIO_B_PIN_6_IN_EXCLK_TIMB23    (0x00000040UL)
#define LL_GPIO_B_PIN_7_IN_F               (0x00000080UL)
#define LL_GPIO_B_PIN_8_IN_EXCLK_TIMB24    (0x00000100UL)
#define LL_GPIO_B_PIN_9_IN_EXCLK_TIMB23    (0x00000200UL)
#define LL_GPIO_B_PIN_10_IN_EXCLK_TIMB22   (0x00000400UL)
#define LL_GPIO_B_PIN_11_IN_EXCLK_TIMB21   (0x00000800UL)
#define LL_GPIO_B_PIN_12_IN_EXCLK_TIMB14   (0x00001000UL)
#define LL_GPIO_B_PIN_13_IN_EXCLK_TIMB13   (0x00002000UL)
#define LL_GPIO_B_PIN_14_IN_EXCLK_TIMB12   (0x00004000UL)
#define LL_GPIO_B_PIN_15_IN_TIMG_CH4IN     (0x00008000UL)
#define LL_GPIO_B_PIN_16_IN_TIMG_CH2IN     (0x00010000UL)
#define LL_GPIO_B_PIN_17_IN_F              (0x00020000UL)
#define LL_GPIO_B_PIN_18_IN_TIMG_CH1IN     (0x00040000UL)
#define LL_GPIO_B_PIN_19_IN_F              (0x00080000UL)
#define LL_GPIO_B_PIN_20_IN_F              (0x00100000UL)
#define LL_GPIO_B_PIN_21_IN_F              (0x00200000UL)
#define LL_GPIO_B_PIN_22_IN_TIMG_CH3IN     (0x00400000UL)
#define LL_GPIO_B_PIN_23_IN_TIMG_ETR       (0x00800000UL)
#define LL_GPIO_B_PIN_24_IN_TIMA_ETR       (0x01000000UL)
#define LL_GPIO_B_PIN_25_IN_EXCLK_TIMB14   (0x02000000UL)
#define LL_GPIO_B_PIN_26_IN_F              (0x04000000UL)
#define LL_GPIO_B_PIN_27_IN_F              (0x08000000UL)
#define LL_GPIO_B_PIN_28_IN_F              (0x10000000UL)
#define LL_GPIO_B_PIN_29_IN_F              (0x20000000UL)
#define LL_GPIO_B_PIN_30_IN_F              (0x40000000UL)
#define LL_GPIO_B_PIN_31_IN_F              (0x80000000UL)

#define LL_GPIO_C_PIN_0_IN_TIMA_BKIN2      (0x00000001UL)
#define LL_GPIO_C_PIN_1_IN_EXCLK_TIMB24    (0x00000002UL)
#define LL_GPIO_C_PIN_2_IN_EXCLK_TIMB21    (0x00000004UL)
#define LL_GPIO_C_PIN_3_IN_F               (0x00000008UL)
#define LL_GPIO_C_PIN_4_IN_F               (0x00000010UL)
#define LL_GPIO_C_PIN_5_IN_F               (0x00000020UL)
#define LL_GPIO_C_PIN_6_IN_F               (0x00000040UL)
#define LL_GPIO_C_PIN_7_IN_F               (0x00000080UL)
#define LL_GPIO_C_PIN_8_IN_F               (0x00000100UL)
#define LL_GPIO_C_PIN_9_IN_TIMA_CH3IN      (0x00000200UL)
#define LL_GPIO_C_PIN_10_IN_F              (0x00000400UL)
#define LL_GPIO_C_PIN_11_IN_F              (0x00000800UL)
#define LL_GPIO_C_PIN_12_IN_F              (0x00001000UL)
#define LL_GPIO_C_PIN_13_IN_F              (0x00002000UL)
#define LL_GPIO_C_PIN_14_IN_F              (0x00004000UL)
#define LL_GPIO_C_PIN_15_IN_F              (0x00008000UL)
#define LL_GPIO_C_PIN_16_IN_TIMA_CH1IN     (0x00010000UL)
#define LL_GPIO_C_PIN_17_IN_F              (0x00020000UL)
#define LL_GPIO_C_PIN_18_IN_TIMA_CH2IN     (0x00040000UL)
#define LL_GPIO_C_PIN_19_IN_F              (0x00080000UL)
#define LL_GPIO_C_PIN_20_IN_F              (0x00100000UL)
#define LL_GPIO_C_PIN_21_IN_F              (0x00200000UL)
#define LL_GPIO_C_PIN_22_IN_F              (0x00400000UL)
#define LL_GPIO_C_PIN_23_IN_F              (0x00800000UL)
#define LL_GPIO_C_PIN_24_IN_F              (0x01000000UL)
#define LL_GPIO_C_PIN_25_IN_F              (0x02000000UL)
#define LL_GPIO_C_PIN_26_IN_F              (0x04000000UL)
#define LL_GPIO_C_PIN_27_IN_F              (0x08000000UL)
#define LL_GPIO_C_PIN_28_IN_F              (0x10000000UL)
#define LL_GPIO_C_PIN_29_IN_F              (0x20000000UL)
#define LL_GPIO_C_PIN_30_IN_F              (0x40000000UL)
#define LL_GPIO_C_PIN_31_IN_F              (0x80000000UL)

#define LL_GPIO_D_PIN_0_IN_TIMA_BKIN       (0x00000001UL)
#define LL_GPIO_D_PIN_1_IN_F               (0x00000002UL)
#define LL_GPIO_D_PIN_2_IN_F               (0x00000004UL)
#define LL_GPIO_D_PIN_3_IN_F               (0x00000008UL)
#define LL_GPIO_D_PIN_4_IN_F               (0x00000010UL)
#define LL_GPIO_D_PIN_5_IN_F               (0x00000020UL)
#define LL_GPIO_D_PIN_6_IN_F               (0x00000040UL)
#define LL_GPIO_D_PIN_7_IN_F               (0x00000080UL)
#define LL_GPIO_D_PIN_8_IN_F               (0x00000100UL)
#define LL_GPIO_D_PIN_9_IN_F               (0x00000200UL)
#define LL_GPIO_D_PIN_10_IN_F              (0x00000400UL)
#define LL_GPIO_D_PIN_11_IN_F              (0x00000800UL)
#define LL_GPIO_D_PIN_12_IN_F              (0x00001000UL)
#define LL_GPIO_D_PIN_13_IN_F              (0x00002000UL)
#define LL_GPIO_D_PIN_14_IN_F              (0x00004000UL)
#define LL_GPIO_D_PIN_15_IN_TIMA_CH4IN     (0x00008000UL)
#define LL_GPIO_D_PIN_16_IN_F              (0x00010000UL)
#define LL_GPIO_D_PIN_17_IN_F              (0x00020000UL)
#define LL_GPIO_D_PIN_18_IN_F              (0x00040000UL)
#define LL_GPIO_D_PIN_19_IN_F              (0x00080000UL)
#define LL_GPIO_D_PIN_20_IN_F              (0x00100000UL)
#define LL_GPIO_D_PIN_21_IN_F              (0x00200000UL)
#define LL_GPIO_D_PIN_22_IN_F              (0x00400000UL)
#define LL_GPIO_D_PIN_23_IN_F              (0x00800000UL)
#define LL_GPIO_D_PIN_24_IN_F              (0x01000000UL)
#define LL_GPIO_D_PIN_25_IN_F              (0x02000000UL)
#define LL_GPIO_D_PIN_26_IN_F              (0x04000000UL)
#define LL_GPIO_D_PIN_27_IN_F              (0x08000000UL)
#define LL_GPIO_D_PIN_28_IN_F              (0x10000000UL)
#define LL_GPIO_D_PIN_29_IN_F              (0x20000000UL)
#define LL_GPIO_D_PIN_30_IN_F              (0x40000000UL)
#define LL_GPIO_D_PIN_31_IN_F              (0x80000000UL)

#define LL_GPIO_A_PIN_0_OUT_F              (0x00000001UL)
#define LL_GPIO_A_PIN_1_OUT_F              (0x00000002UL)
#define LL_GPIO_A_PIN_2_OUT_F              (0x00000004UL)
#define LL_GPIO_A_PIN_3_OUT_F              (0x00000008UL)
#define LL_GPIO_A_PIN_4_OUT_F              (0x00000010UL)
#define LL_GPIO_A_PIN_5_OUT_F              (0x00000020UL)
#define LL_GPIO_A_PIN_6_OUT_F              (0x00000040UL)
#define LL_GPIO_A_PIN_7_OUT_F              (0x00000080UL)
#define LL_GPIO_A_PIN_8_OUT_F              (0x00000100UL)
#define LL_GPIO_A_PIN_9_OUT_F              (0x00000200UL)
#define LL_GPIO_A_PIN_10_OUT_F             (0x00000400UL)
#define LL_GPIO_A_PIN_11_OUT_F             (0x00000800UL)
#define LL_GPIO_A_PIN_12_OUT_F             (0x00001000UL)
#define LL_GPIO_A_PIN_13_OUT_F             (0x00002000UL)
#define LL_GPIO_A_PIN_14_OUT_F             (0x00004000UL)
#define LL_GPIO_A_PIN_15_OUT_F             (0x00008000UL)
#define LL_GPIO_A_PIN_16_OUT_F             (0x00010000UL)
#define LL_GPIO_A_PIN_17_OUT_F             (0x00020000UL)
#define LL_GPIO_A_PIN_18_OUT_F             (0x00040000UL)
#define LL_GPIO_A_PIN_19_OUT_F             (0x00080000UL)
#define LL_GPIO_A_PIN_20_OUT_F             (0x00100000UL)
#define LL_GPIO_A_PIN_21_OUT_F             (0x00200000UL)
#define LL_GPIO_A_PIN_22_OUT_F             (0x00400000UL)
#define LL_GPIO_A_PIN_23_OUT_F             (0x00800000UL)
#define LL_GPIO_A_PIN_24_OUT_F             (0x01000000UL)
#define LL_GPIO_A_PIN_25_OUT_F             (0x02000000UL)
#define LL_GPIO_A_PIN_26_OUT_F             (0x04000000UL)
#define LL_GPIO_A_PIN_27_OUT_F             (0x08000000UL)
#define LL_GPIO_A_PIN_28_OUT_F             (0x10000000UL)
#define LL_GPIO_A_PIN_29_OUT_F             (0x20000000UL)
#define LL_GPIO_A_PIN_30_OUT_F             (0x40000000UL)
#define LL_GPIO_A_PIN_31_OUT_F             (0x80000000UL)

#define LL_GPIO_B_PIN_0_OUT_F              (0x00000001UL)
#define LL_GPIO_B_PIN_1_OUT_TIMB11         (0x00000002UL)
#define LL_GPIO_B_PIN_2_OUT_F              (0x00000004UL)
#define LL_GPIO_B_PIN_3_OUT_F              (0x00000008UL)
#define LL_GPIO_B_PIN_4_OUT_F              (0x00000010UL)
#define LL_GPIO_B_PIN_5_OUT_TIMB22         (0x00000020UL)
#define LL_GPIO_B_PIN_6_OUT_TIMB23         (0x00000040UL)
#define LL_GPIO_B_PIN_7_OUT_F              (0x00000080UL)
#define LL_GPIO_B_PIN_8_OUT_TIMB24         (0x00000100UL)
#define LL_GPIO_B_PIN_9_OUT_TIMB23         (0x00000200UL)
#define LL_GPIO_B_PIN_10_OUT_TIMB22        (0x00000400UL)
#define LL_GPIO_B_PIN_11_OUT_TIMB21        (0x00000800UL)
#define LL_GPIO_B_PIN_12_OUT_TIMB14        (0x00001000UL)
#define LL_GPIO_B_PIN_13_OUT_TIMB13        (0x00002000UL)
#define LL_GPIO_B_PIN_14_OUT_TIMB12        (0x00004000UL)
#define LL_GPIO_B_PIN_15_OUT_TIMG_CH4      (0x00008000UL)
#define LL_GPIO_B_PIN_16_OUT_TIMG_CH2N     (0x00010000UL)
#define LL_GPIO_B_PIN_17_OUT_TIMG_CH2P     (0x00020000UL)
#define LL_GPIO_B_PIN_18_OUT_TIMG_CH1N     (0x00040000UL)
#define LL_GPIO_B_PIN_19_OUT_TIMG_CH1P     (0x00080000UL)
#define LL_GPIO_B_PIN_20_OUT_F             (0x00100000UL)
#define LL_GPIO_B_PIN_21_OUT_F             (0x00200000UL)
#define LL_GPIO_B_PIN_22_OUT_TIMG_CH3N     (0x00400000UL)
#define LL_GPIO_B_PIN_23_OUT_TIMG_CH3P     (0x00800000UL)
#define LL_GPIO_B_PIN_24_OUT_F             (0x01000000UL)
#define LL_GPIO_B_PIN_25_OUT_TIMB14        (0x02000000UL)
#define LL_GPIO_B_PIN_26_OUT_TIMA_CH1O     (0x04000000UL)
#define LL_GPIO_B_PIN_27_OUT_F             (0x08000000UL)
#define LL_GPIO_B_PIN_28_OUT_F             (0x10000000UL)
#define LL_GPIO_B_PIN_29_OUT_F             (0x20000000UL)
#define LL_GPIO_B_PIN_30_OUT_F             (0x40000000UL)
#define LL_GPIO_B_PIN_31_OUT_F             (0x80000000UL)

#define LL_GPIO_C_PIN_0_OUT_F              (0x00000001UL)
#define LL_GPIO_C_PIN_1_OUT_TIMB24         (0x00000002UL)
#define LL_GPIO_C_PIN_2_OUT_TIMB21         (0x00000004UL)
#define LL_GPIO_C_PIN_3_OUT_F              (0x00000008UL)
#define LL_GPIO_C_PIN_4_OUT_F              (0x00000010UL)
#define LL_GPIO_C_PIN_5_OUT_F              (0x00000020UL)
#define LL_GPIO_C_PIN_6_OUT_F              (0x00000040UL)
#define LL_GPIO_C_PIN_7_OUT_F              (0x00000080UL)
#define LL_GPIO_C_PIN_8_OUT_TIMA_CH3O      (0x00000100UL)
#define LL_GPIO_C_PIN_9_OUT_TIMA_CH3ON     (0x00000200UL)
#define LL_GPIO_C_PIN_10_OUT_F             (0x00000400UL)
#define LL_GPIO_C_PIN_11_OUT_F             (0x00000800UL)
#define LL_GPIO_C_PIN_12_OUT_F             (0x00001000UL)
#define LL_GPIO_C_PIN_13_OUT_F             (0x00002000UL)
#define LL_GPIO_C_PIN_14_OUT_F             (0x00004000UL)
#define LL_GPIO_C_PIN_15_OUT_F             (0x00008000UL)
#define LL_GPIO_C_PIN_16_OUT_TIMA_CH1ON    (0x00010000UL)
#define LL_GPIO_C_PIN_17_OUT_TIMA_CH2O     (0x00020000UL)
#define LL_GPIO_C_PIN_18_OUT_TIMA_CH2ON    (0x00040000UL)
#define LL_GPIO_C_PIN_19_OUT_F             (0x00080000UL)
#define LL_GPIO_C_PIN_20_OUT_F             (0x00100000UL)
#define LL_GPIO_C_PIN_21_OUT_F             (0x00200000UL)
#define LL_GPIO_C_PIN_22_OUT_F             (0x00400000UL)
#define LL_GPIO_C_PIN_23_OUT_F             (0x00800000UL)
#define LL_GPIO_C_PIN_24_OUT_F             (0x01000000UL)
#define LL_GPIO_C_PIN_25_OUT_TIMA_BKOUT    (0x02000000UL)
#define LL_GPIO_C_PIN_26_OUT_TIMA_BKOUT2   (0x04000000UL)
#define LL_GPIO_C_PIN_27_OUT_F             (0x08000000UL)
#define LL_GPIO_C_PIN_28_OUT_F             (0x10000000UL)
#define LL_GPIO_C_PIN_29_OUT_F             (0x20000000UL)
#define LL_GPIO_C_PIN_30_OUT_F             (0x40000000UL)
#define LL_GPIO_C_PIN_31_OUT_F             (0x80000000UL)

#define LL_GPIO_D_PIN_0_OUT_F              (0x00000001UL)
#define LL_GPIO_D_PIN_1_OUT_F              (0x00000002UL)
#define LL_GPIO_D_PIN_2_OUT_F              (0x00000004UL)
#define LL_GPIO_D_PIN_3_OUT_F              (0x00000008UL)
#define LL_GPIO_D_PIN_4_OUT_F              (0x00000010UL)
#define LL_GPIO_D_PIN_5_OUT_F              (0x00000020UL)
#define LL_GPIO_D_PIN_6_OUT_F              (0x00000040UL)
#define LL_GPIO_D_PIN_7_OUT_F              (0x00000080UL)
#define LL_GPIO_D_PIN_8_OUT_F              (0x00000100UL)
#define LL_GPIO_D_PIN_9_OUT_F              (0x00000200UL)
#define LL_GPIO_D_PIN_10_OUT_F             (0x00000400UL)
#define LL_GPIO_D_PIN_11_OUT_F             (0x00000800UL)
#define LL_GPIO_D_PIN_12_OUT_F             (0x00001000UL)
#define LL_GPIO_D_PIN_13_OUT_F             (0x00002000UL)
#define LL_GPIO_D_PIN_14_OUT_F             (0x00004000UL)
#define LL_GPIO_D_PIN_15_OUT_TIMA_CH4O     (0x00008000UL)
#define LL_GPIO_D_PIN_16_OUT_F             (0x00010000UL)
#define LL_GPIO_D_PIN_17_OUT_F             (0x00020000UL)
#define LL_GPIO_D_PIN_18_OUT_F             (0x00040000UL)
#define LL_GPIO_D_PIN_19_OUT_F             (0x00080000UL)
#define LL_GPIO_D_PIN_20_OUT_F             (0x00100000UL)
#define LL_GPIO_D_PIN_21_OUT_F             (0x00200000UL)
#define LL_GPIO_D_PIN_22_OUT_F             (0x00400000UL)
#define LL_GPIO_D_PIN_23_OUT_F             (0x00800000UL)
#define LL_GPIO_D_PIN_24_OUT_F             (0x01000000UL)
#define LL_GPIO_D_PIN_25_OUT_F             (0x02000000UL)
#define LL_GPIO_D_PIN_26_OUT_F             (0x04000000UL)
#define LL_GPIO_D_PIN_27_OUT_F             (0x08000000UL)
#define LL_GPIO_D_PIN_28_OUT_F             (0x10000000UL)
#define LL_GPIO_D_PIN_29_OUT_F             (0x20000000UL)
#define LL_GPIO_D_PIN_30_OUT_F             (0x40000000UL)
#define LL_GPIO_D_PIN_31_OUT_F             (0x80000000UL)
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_DMA_HSIF_CFG System DMA Handshaking Interface Configure
  * @{
  */
#define   LL_DMA_SHIF_CFG_0            (0)  
#define   LL_DMA_SHIF_CFG_1            (1)  
#define   LL_DMA_SHIF_CFG_2            (2)  
#define   LL_DMA_SHIF_CFG_3            (3)  
#if defined(XT32H0xxB)
#define   LL_DMA_SHIF_CFG_4            (4)  
#define   LL_DMA_SHIF_CFG_8            (8)  
#define   LL_DMA_SHIF_CFG_12           (12)  
#define   LL_DMA_SHIF_CFG_13           (13)  
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_DMA_HSIF_IDX System DMA Handshaking Interface Index
  * @{
  */
#define   LL_DMA_SHIF_INDEX_0          (0)  
#define   LL_DMA_SHIF_INDEX_1          (1)  
#define   LL_DMA_SHIF_INDEX_2          (2)  
#define   LL_DMA_SHIF_INDEX_3          (3)  
#define   LL_DMA_SHIF_INDEX_4          (4)  
#define   LL_DMA_SHIF_INDEX_5          (5)  
#define   LL_DMA_SHIF_INDEX_6          (6)  
#define   LL_DMA_SHIF_INDEX_7          (7)  
#define   LL_DMA_SHIF_INDEX_8          (8)  
#define   LL_DMA_SHIF_INDEX_9          (9)  
#define   LL_DMA_SHIF_INDEX_10         (10)  
#define   LL_DMA_SHIF_INDEX_11         (11)  
#define   LL_DMA_SHIF_INDEX_12         (12)  
#define   LL_DMA_SHIF_INDEX_13         (13)  
#define   LL_DMA_SHIF_INDEX_14         (14)  
#define   LL_DMA_SHIF_INDEX_15         (15)  
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_DMA_HSIF_Assign System DMA Handshaking Interface Assign
  * @{
  */
#if defined(XT32H0xxB)
#define   LL_DMA_SHIF_CFG_0_INDEX_UART1_TX      (0)
#define   LL_DMA_SHIF_CFG_0_INDEX_UART1_RX      (1)
#define   LL_DMA_SHIF_CFG_0_INDEX_UART2_TX      (2)
#define   LL_DMA_SHIF_CFG_0_INDEX_UART2_RX      (3)
#define   LL_DMA_SHIF_CFG_0_INDEX_ADC_EOS_INJ   (6)
#define   LL_DMA_SHIF_CFG_0_INDEX_ADC_EOS_REG   (7)
#define   LL_DMA_SHIF_CFG_0_INDEX_I2C1_TX       (8)
#define   LL_DMA_SHIF_CFG_0_INDEX_I2C1_RX       (9)
#define   LL_DMA_SHIF_CFG_0_INDEX_SPI2_TX       (10)
#define   LL_DMA_SHIF_CFG_0_INDEX_SPI2_RX       (11)
#define   LL_DMA_SHIF_CFG_0_INDEX_SPI1_TX       (12)
#define   LL_DMA_SHIF_CFG_0_INDEX_SPI1_RX       (13)
#define   LL_DMA_SHIF_CFG_0_INDEX_SPI2A_TX      (14)
#define   LL_DMA_SHIF_CFG_0_INDEX_SPI2A_RX      (15)

#define   LL_DMA_SHIF_CFG_0_CFG_UART1_TX        (0)
#define   LL_DMA_SHIF_CFG_0_CFG_UART1_RX        (0)
#define   LL_DMA_SHIF_CFG_0_CFG_UART2_TX        (0)
#define   LL_DMA_SHIF_CFG_0_CFG_UART2_RX        (0)
#define   LL_DMA_SHIF_CFG_0_CFG_ADC_EOS_INJ     (0)
#define   LL_DMA_SHIF_CFG_0_CFG_ADC_EOS_REG     (0)
#define   LL_DMA_SHIF_CFG_0_CFG_I2C1_TX         (0)
#define   LL_DMA_SHIF_CFG_0_CFG_I2C1_RX         (0)
#define   LL_DMA_SHIF_CFG_0_CFG_SPI2_TX         (0)
#define   LL_DMA_SHIF_CFG_0_CFG_SPI2_RX         (0)
#define   LL_DMA_SHIF_CFG_0_CFG_SPI1_TX         (0)
#define   LL_DMA_SHIF_CFG_0_CFG_SPI1_RX         (0)
#define   LL_DMA_SHIF_CFG_0_CFG_SPI2A_TX        (0)
#define   LL_DMA_SHIF_CFG_0_CFG_SPI2A_RX        (0)

#define   LL_DMA_SHIF_CFG_1_INDEX_I2C1_TX       (0)
#define   LL_DMA_SHIF_CFG_1_INDEX_I2C1_RX       (1)
#define   LL_DMA_SHIF_CFG_1_INDEX_UART3_TX      (4)
#define   LL_DMA_SHIF_CFG_1_INDEX_UART3_RX      (5)
#define   LL_DMA_SHIF_CFG_1_INDEX_UART4_TX      (6)
#define   LL_DMA_SHIF_CFG_1_INDEX_UART4_RX      (7)
#define   LL_DMA_SHIF_CFG_1_INDEX_SPI1_TX       (8)
#define   LL_DMA_SHIF_CFG_1_INDEX_SPI1_RX       (9)
#define   LL_DMA_SHIF_CFG_1_INDEX_I2C2_TX       (10)
#define   LL_DMA_SHIF_CFG_1_INDEX_I2C2_RX       (11)
#define   LL_DMA_SHIF_CFG_1_INDEX_UART3A_TX     (12)
#define   LL_DMA_SHIF_CFG_1_INDEX_UART3A_RX     (13)
#define   LL_DMA_SHIF_CFG_1_INDEX_I2C1A_TX      (14)
#define   LL_DMA_SHIF_CFG_1_INDEX_I2C1A_RX      (15)

#define   LL_DMA_SHIF_CFG_1_CFG_I2C1_TX         (1)
#define   LL_DMA_SHIF_CFG_1_CFG_I2C1_RX         (1)
#define   LL_DMA_SHIF_CFG_1_CFG_UART3_TX        (1)
#define   LL_DMA_SHIF_CFG_1_CFG_UART3_RX        (1)
#define   LL_DMA_SHIF_CFG_1_CFG_UART4_TX        (1)
#define   LL_DMA_SHIF_CFG_1_CFG_UART4_RX        (1)
#define   LL_DMA_SHIF_CFG_1_CFG_SPI1_TX         (1)
#define   LL_DMA_SHIF_CFG_1_CFG_SPI1_RX         (1)
#define   LL_DMA_SHIF_CFG_1_CFG_I2C2_TX         (1)
#define   LL_DMA_SHIF_CFG_1_CFG_I2C2_RX         (1)
#define   LL_DMA_SHIF_CFG_1_CFG_UART3_TX        (1)
#define   LL_DMA_SHIF_CFG_1_CFG_UART3_RX        (1)
#define   LL_DMA_SHIF_CFG_1_CFG_I2C1A_TX        (1)
#define   LL_DMA_SHIF_CFG_1_CFG_I2C1A_RX        (1)

#define   LL_DMA_SHIF_CFG_2_INDEX_SPI1_TX       (0)
#define   LL_DMA_SHIF_CFG_2_INDEX_SPI1_RX       (1)
#define   LL_DMA_SHIF_CFG_2_INDEX_TIMA1_TRG     (2)
#define   LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC1     (6)
#define   LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC4     (7)
#define   LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC2     (8)
#define   LL_DMA_SHIF_CFG_2_INDEX_TIMA1_CC3     (9)
#define   LL_DMA_SHIF_CFG_2_INDEX_TIMA1_UDT     (12)
#define   LL_DMA_SHIF_CFG_2_INDEX_UART2_TX      (14)
#define   LL_DMA_SHIF_CFG_2_INDEX_UART2_RX      (15)

#define   LL_DMA_SHIF_CFG_2_CFG_SPI1_TX         (2)
#define   LL_DMA_SHIF_CFG_2_CFG_SPI1_RX         (2)
#define   LL_DMA_SHIF_CFG_2_CFG_TIMA1_TRG       (2)
#define   LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC1       (2)
#define   LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC4       (2)
#define   LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC2       (2)
#define   LL_DMA_SHIF_CFG_2_CFG_TIMA1_CC3       (2)
#define   LL_DMA_SHIF_CFG_2_CFG_TIMA1_UDT       (2)
#define   LL_DMA_SHIF_CFG_2_CFG_UART2_TX        (2)
#define   LL_DMA_SHIF_CFG_2_CFG_UART2_RX        (2)

#define   LL_DMA_SHIF_CFG_3_INDEX_LED_FRM       (0)
#define   LL_DMA_SHIF_CFG_3_INDEX_LED_UDT       (1)
#define   LL_DMA_SHIF_CFG_3_INDEX_LED_COM       (2)
#define   LL_DMA_SHIF_CFG_3_INDEX_TIMG1_TRG     (3)
#define   LL_DMA_SHIF_CFG_3_INDEX_TIMG1_UDT     (11)
#define   LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC2     (12)
#define   LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC3     (13)
#define   LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC1     (14)
#define   LL_DMA_SHIF_CFG_3_INDEX_TIMG1_CC4     (15)

#define   LL_DMA_SHIF_CFG_3_CFG_LED_FRM         (3)
#define   LL_DMA_SHIF_CFG_3_CFG_LED_UDT         (3)
#define   LL_DMA_SHIF_CFG_3_CFG_LED_COM         (3)
#define   LL_DMA_SHIF_CFG_3_CFG_TIMG1_TRG       (3)
#define   LL_DMA_SHIF_CFG_3_CFG_TIMG1_UDT       (3)
#define   LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC2       (3)
#define   LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC3       (3)
#define   LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC1       (3)
#define   LL_DMA_SHIF_CFG_3_CFG_TIMG1_CC4       (3)

#define   LL_DMA_SHIF_CFG_4_INDEX_TIMA2_TRG     (1)
#define   LL_DMA_SHIF_CFG_4_INDEX_SPI2_TX       (2)
#define   LL_DMA_SHIF_CFG_4_INDEX_SPI2_RX       (3)
#define   LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC1     (8)
#define   LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC4     (9)
#define   LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC2     (10)
#define   LL_DMA_SHIF_CFG_4_INDEX_TIMA2_CC3     (11)
#define   LL_DMA_SHIF_CFG_4_INDEX_TIMA2_UDT     (14)

#define   LL_DMA_SHIF_CFG_4_CFG_TIMA2_TRG       (4)
#define   LL_DMA_SHIF_CFG_4_CFG_SPI2_TX         (4)
#define   LL_DMA_SHIF_CFG_4_CFG_SPI2_RX         (4)
#define   LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC1       (4)
#define   LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC4       (4)
#define   LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC2       (4)
#define   LL_DMA_SHIF_CFG_4_CFG_TIMA2_CC3       (4)
#define   LL_DMA_SHIF_CFG_4_CFG_TIMA2_UDT       (4)

#define   LL_DMA_SHIF_CFG_8_INDEX_TIMG2_TRG     (3)
#define   LL_DMA_SHIF_CFG_8_INDEX_TIMG2_UDT     (10)
#define   LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC1     (12)
#define   LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC4     (13)
#define   LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC2     (14)
#define   LL_DMA_SHIF_CFG_8_INDEX_TIMG2_CC3     (15)

#define   LL_DMA_SHIF_CFG_8_CFG_TIMG2_TRG       (8)
#define   LL_DMA_SHIF_CFG_8_CFG_TIMG2_UDT       (8)
#define   LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC1       (8)
#define   LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC4       (8)
#define   LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC2       (8)
#define   LL_DMA_SHIF_CFG_8_CFG_TIMG2_CC3       (8)

#define   LL_DMA_SHIF_CFG_12_INDEX_TIMG3_TRG    (0)
#define   LL_DMA_SHIF_CFG_12_INDEX_TIMG3_UDT    (2)
#define   LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC1    (4)
#define   LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC4    (5)
#define   LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC2    (6)
#define   LL_DMA_SHIF_CFG_12_INDEX_TIMG3_CC3    (7)
#define   LL_DMA_SHIF_CFG_12_INDEX_UART4_TX     (10)
#define   LL_DMA_SHIF_CFG_12_INDEX_UART4_RX     (11)

#define   LL_DMA_SHIF_CFG_12_CFG_TIMG3_TRG      (12)
#define   LL_DMA_SHIF_CFG_12_CFG_TIMG3_UDT      (12)
#define   LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC1      (12)
#define   LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC4      (12)
#define   LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC2      (12)
#define   LL_DMA_SHIF_CFG_12_CFG_TIMG3_CC3      (12)
#define   LL_DMA_SHIF_CFG_12_CFG_UART4_TX       (12)
#define   LL_DMA_SHIF_CFG_12_CFG_UART4_RX       (12)

#define   LL_DMA_SHIF_CFG_13_INDEX_TIMG4_TRG    (1)
#define   LL_DMA_SHIF_CFG_13_INDEX_TIMG4_UDT    (3)
#define   LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC1    (10)
#define   LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC4    (11)
#define   LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC2    (12)
#define   LL_DMA_SHIF_CFG_13_INDEX_TIMG4_CC3    (13)

#define   LL_DMA_SHIF_CFG_13_CFG_TIMG4_TRG      (13)
#define   LL_DMA_SHIF_CFG_13_CFG_TIMG4_UDT      (13)
#define   LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC1      (13)
#define   LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC4      (13)
#define   LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC2      (13)
#define   LL_DMA_SHIF_CFG_13_CFG_TIMG4_CC3      (13)
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_AFC_INT_ENABLE System AFC Interrupt Enable
  * @{
  */
#define   LL_AFC_INT_ENABLE_LOOP       (SYSCFG_AFCCTRL_ALIE)  
#define   LL_AFC_INT_ENABLE_NORMAL     (SYSCFG_AFCCTRL_ANIE)  
#define   LL_AFC_INT_ENABLE_ERROR      (SYSCFG_AFCCTRL_AEIE)  
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_AFC_INT_FLAG System AFC Interrupt Flag
  * @{
  */
#define   LL_AFC_INT_FLAG_LOOP         (SYSCFG_AFCRES_ALIF)  
#define   LL_AFC_INT_FLAG_NORMAL       (SYSCFG_AFCRES_ANIF)  
#define   LL_AFC_INT_FLAG_ERROR        (SYSCFG_AFCRES_AEIF)  
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_AFC_Calibrate System AFC Calibrate
  * @{
  */
#define LL_AFC_CLKSRC_32K              (0)  
#define LL_AFC_CLKSRC_16M              (SYSCFG_AFCCTRL_CBCLKS)  

/**
  * @}
  */

#if defined(XT32H0xxB)
/** @defgroup SYSTEM_LL_EC_TIMAG_ID  System Advanced Timers and General Timers Index 
  * @{
  */
#define LL_TIM_TIMA1_ID                (0)  
#define LL_TIM_TIMA2_ID                (1)  
#define LL_TIM_TIMG1_ID                (2)  
#define LL_TIM_TIMG2_ID                (3)  
#define LL_TIM_TIMG3_ID                (4)  
#define LL_TIM_TIMG4_ID                (5)  
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_TIMAG_INPUT_SRC  System Advanced Timers and General Timers Input Sources 
  * @{
  */
#define LL_TIM_IMX_SRC_TIMA1           (0)  
#define LL_TIM_IMX_SRC_TIMA2           (1)  
#define LL_TIM_IMX_SRC_TIMG1           (2)  
#define LL_TIM_IMX_SRC_TIMG2           (3)  
#define LL_TIM_IMX_SRC_TIMG3           (4)  
#define LL_TIM_IMX_SRC_TIMG4           (5)  
#define LL_TIM_IMX_SRC_NONE            (6)  
/**
  * @}
  */
/** @defgroup SYSTEM_LL_EC_TIMAG_IC_ID  System Advanced Timers and General Timers Input Channel Index 
  * @{
  */
#define LL_TIM_IC_CH1_ID                (0)  
#define LL_TIM_IC_CH2_ID                (1)  
#define LL_TIM_IC_CH3_ID                (2)  
#define LL_TIM_IC_CH4_ID                (3)  
#define LL_TIM_IC_ETR_ID                (4)  
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_TIMAG_OUTPUT_CH_ID  System Advanced Timers and General Timers Output Configure Channel Index
  * @{
  */
#define LL_TIM_OC_CH1_ID                (0)  
#define LL_TIM_OC_CH2_ID                (1)  
/**
  * @}
  */

/** @defgroup SYSTEM_LL_EC_TIMAG_OUTPUT_CFG  System Advanced Timers and General Timers Output Configure Complementary or Single-ended 
  * @{
  */
#define LL_TIM_OC_COMPLEMENTARY        (0)  
#define LL_TIM_OC_SINGLE_ENDED         (1)  
/**
  * @}
  */

#endif /* XT32H0xxB */
/**
  * @}
  */
/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup SYSTEM_LL_Exported_Functions SYSTEM Exported Functions
  * @{
  */
#if 0
/** @defgroup SYSTEM_LL_Exported_Functions_Group1 Sram
  * @{
  */
/**
  * @brief  Set SRAM bank RME
  * @rmtoll SYSCFG.SRAM_CFG_x  bypass          LL_SYS_SetSRAMRME
  * @param  Bank the parameter can be one of 0 to 3
  * @param  Mode the parameter can be one of the follow values:
  *         @arg @ref LL_SRAM_RM_INTERNAL
  *         @arg @ref LL_SRAM_RM_EXTERNAL
  */
__STATIC_INLINE void LL_SYS_SetSRAMRME(uint32_t Bank, uint32_t Mode)
{
  switch(Bank)
  {
    case LL_SRAM_BANK_0:
      MODIFY_REG(SYSCFG->SRAM_CFG_1, SYSCFG_SRAM_CFG_RME, Mode);
      break;
    case LL_SRAM_BANK_1:
      MODIFY_REG(SYSCFG->SRAM_CFG_2, SYSCFG_SRAM_CFG_RME, Mode);
      break;
    case LL_SRAM_BANK_2:
      MODIFY_REG(SYSCFG->SRAM_CFG_3, SYSCFG_SRAM_CFG_RME, Mode);
      break;
    case LL_SRAM_BANK_3:
      MODIFY_REG(SYSCFG->SRAM_CFG_4, SYSCFG_SRAM_CFG_RME, Mode);
      break;
    default:
    break;
  }
}

/**
  * @brief  Get SRAM bank RME
  * @rmtoll SYSCFG.SRAM_CFG_x  bypass          LL_SYS_GetSRAMRME
  * @param  Bank the parameter can be one of 0 to 3
  * @retval  Mode the parameter can be one of the follow values:
  *         @arg @ref LL_SRAM_TEST1_DISABLE
  *         @arg @ref LL_SRAM_TEST1_ENABLE
  */
__STATIC_INLINE uint32_t LL_SYS_GetSRAMRME(uint32_t Bank)
{
  uint32_t val = 0;
  switch(Bank)
  {
    case LL_SRAM_BANK_0:
      val = (uint32_t) (READ_BIT(SYSCFG->SRAM_CFG_1, SYSCFG_SRAM_CFG_RME));
      break;
    case LL_SRAM_BANK_1:
      val = (uint32_t) (READ_BIT(SYSCFG->SRAM_CFG_2, SYSCFG_SRAM_CFG_RME));
      break;
    case LL_SRAM_BANK_2:
      val = (uint32_t) (READ_BIT(SYSCFG->SRAM_CFG_3, SYSCFG_SRAM_CFG_RME));
      break;
    case LL_SRAM_BANK_3:
      val = (uint32_t) (READ_BIT(SYSCFG->SRAM_CFG_4, SYSCFG_SRAM_CFG_RME));
      break;
    default:
      break;
  }
	return val;
}


/**
  * @brief  Set SRAM bank bypass self-timed circuit
  * @rmtoll SYSCFG.SRAM_CFG_x  bypass          LL_SYS_SetSRAMTest1
  * @param  Bank the parameter can be one of 0 to 3
  * @param  Mode the parameter can be one of the follow values:
  *         @arg @ref LL_SRAM_TEST1_DISABLE
  *         @arg @ref LL_SRAM_TEST1_ENABLE
  */
__STATIC_INLINE void LL_SYS_SetSRAMTest1(uint32_t Bank, uint32_t Mode)
{
  switch(Bank)
  {
    case LL_SRAM_BANK_0:
      MODIFY_REG(SYSCFG->SRAM_CFG_1, SYSCFG_SRAM_CFG_TEST1, Mode);
      break;
    case LL_SRAM_BANK_1:
      MODIFY_REG(SYSCFG->SRAM_CFG_2, SYSCFG_SRAM_CFG_TEST1, Mode);
      break;
    case LL_SRAM_BANK_2:
      MODIFY_REG(SYSCFG->SRAM_CFG_3, SYSCFG_SRAM_CFG_TEST1, Mode);
      break;
    case LL_SRAM_BANK_3:
      MODIFY_REG(SYSCFG->SRAM_CFG_4, SYSCFG_SRAM_CFG_TEST1, Mode);
      break;
    default:
    break;
  }
}

/**
  * @brief  Get SRAM bank bypass self-timed circuit
  * @rmtoll SYSCFG.SRAM_CFG_x  bypass          LL_SYS_SetSRAMTest1
  * @param  Bank the parameter can be one of 0 to 3
  * @retval  Mode the parameter can be one of the follow values:
  *         @arg @ref LL_SRAM_TEST1_DISABLE
  *         @arg @ref LL_SRAM_TEST1_ENABLE
  */
__STATIC_INLINE uint32_t LL_SYS_GetSRAMTest1(uint32_t Bank)
{
  uint32_t val = 0;
  switch(Bank)
  {
    case LL_SRAM_BANK_0:
      val = (uint32_t) (READ_BIT(SYSCFG->SRAM_CFG_1, SYSCFG_SRAM_CFG_TEST1));
      break;
    case LL_SRAM_BANK_1:
      val = (uint32_t) (READ_BIT(SYSCFG->SRAM_CFG_2, SYSCFG_SRAM_CFG_TEST1));
      break;
    case LL_SRAM_BANK_2:
      val = (uint32_t) (READ_BIT(SYSCFG->SRAM_CFG_3, SYSCFG_SRAM_CFG_TEST1));
      break;
    case LL_SRAM_BANK_3:
      val = (uint32_t) (READ_BIT(SYSCFG->SRAM_CFG_4, SYSCFG_SRAM_CFG_TEST1));
      break;
    default:
      break;
  }
	return val;
}

/**
  * @brief  Set SRAM mode
  * @rmtoll SYSCFG.SRAM_CFG_PD  mode          LL_SYS_SetSRAMMode
  * @param  Bank the parameter can be one of 0 to 3
  * @param  Mode the parameter can be one of the follow values:
  *         @arg @ref LL_SRAM_MODE_LIGHTSLEEP
  *         @arg @ref LL_SRAM_MODE_DEEPSLEEP
  *         @arg @ref LL_SRAM_MODE_SHUTDOWN
  */
__STATIC_INLINE void LL_SYS_SetSRAMMode(uint32_t Bank, uint32_t Mode)
{
  MODIFY_REG(SYSCFG->SRAM_CFG_PD, (0x7UL << (Bank << 8)), (Mode << (Bank << 8)));
}

/**
  * @brief  Get SRAM mode
  * @rmtoll SYSCFG.SRAM_CFG_PD  mode          LL_SYS_GetSRAMMode
  * @param  Bank the parameter can be one of 0 to 3
  * @retval  Return value can be one of the follow values:
  *         @arg @ref LL_SRAM_MODE_LIGHTSLEEP
  *         @arg @ref LL_SRAM_MODE_DEEPSLEEP
  *         @arg @ref LL_SRAM_MODE_SHUTDOWN
  */
__STATIC_INLINE uint32_t LL_SYS_GetSRAMMode(uint32_t Bank)
{
  return (uint32_t)(READ_BIT(SYSCFG->SRAM_CFG_PD, (0x7UL << (Bank << 8))) >> (Bank << 8));
}
/**
  * @}
  */
#endif //0
/** @defgroup SYSTEM_LL_Exported_Functions_Group2 System SPI Functions
  * @{
  */
/**
  * @brief  Set SPI1 mode
  * @rmtoll SYSCFG.SYS_CFG  SPI_mode          LL_SYS_SetSPI1Mode
  * @param  Mode the parameter can be ont of the follow values:
  *         @arg @ref LL_SPI_1_MODE_SLAVE
  *         @arg @ref LL_SPI_1_MODE_MASTER
  */
__STATIC_INLINE void LL_SYS_SetSPI1Mode(uint32_t Mode)
{
  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_MODE, Mode);
}

/**
  * @brief  Get SPI1 mode
  * @rmtoll SYSCFG.SYS_CFG  SPI_mode          LL_SYS_GetSPI1Mode
  * @retval  Return value can be ont of the follow values:
  *         @arg @ref LL_SPI_1_MODE_SLAVE
  *         @arg @ref LL_SPI_1_MODE_MASTER
  */
__STATIC_INLINE uint32_t LL_SYS_GetSPI1Mode(uint32_t Mode)
{
  return (uint32_t)(READ_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_MODE));
}

/**
  * @brief  Set SPI2 mode
  * @rmtoll SYSCFG.SYS_CFG  SPI_mode          LL_SYS_SetSPI2Mode
  * @param  Mode the parameter can be ont of the follow values:
  *         @arg @ref LL_SPI_2_MODE_SLAVE
  *         @arg @ref LL_SPI_2_MODE_MASTER
  */
__STATIC_INLINE void LL_SYS_SetSPI2Mode(uint32_t Mode)
{
  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_MODE, Mode);
}

/**
  * @brief  Get SPI2 mode
  * @rmtoll SYSCFG.SYS_CFG  SPI_mode          LL_SYS_GetSPI2Mode
  * @retval  Return value can be ont of the follow values:
  *         @arg @ref LL_SPI_2_MODE_SLAVE
  *         @arg @ref LL_SPI_2_MODE_MASTER
  */
__STATIC_INLINE uint32_t LL_SYS_GetSPI2Mode(uint32_t Mode)
{
  return (uint32_t)(READ_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_MODE));
}
/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group3 System Uart Functions
  * @{
  */
/**
  * @brief  Set UART1 mode
  * @rmtoll SYSCFG.SYS_CFG  UART1_mode          LL_SYS_SetUART1Mode
  */
__STATIC_INLINE void LL_SYS_SetUART1Mode(void)
{
  CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART1_MODE);
}

/**
  * @brief  Set UART2 mode
  * @rmtoll SYSCFG.SYS_CFG  UART2_mode          LL_SYS_SetUART2Mode
  */
__STATIC_INLINE void LL_SYS_SetUART2Mode(void)
{
  CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART2_MODE);
}

/**
  * @brief  Set UART3 mode
  * @rmtoll SYSCFG.SYS_CFG  UART3_mode          LL_SYS_SetUART3Mode
  */
__STATIC_INLINE void LL_SYS_SetUART3Mode(void)
{
  CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART3_MODE);
}

/**
  * @brief  Set UART4 mode
  * @rmtoll SYSCFG.SYS_CFG  UART4_mode          LL_SYS_SetUART4Mode
  */
__STATIC_INLINE void LL_SYS_SetUART4Mode(void)
{
  CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART4_MODE);
}

/**
  * @brief  Set IrDA1 mode
  * @rmtoll SYSCFG.SYS_CFG  UART1_mode          LL_SYS_SetIrDA1Mode
  */
__STATIC_INLINE void LL_SYS_SetIrDA1Mode(void)
{
  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART1_MODE);
}

/**
  * @brief  Set IrDA2 mode
  * @rmtoll SYSCFG.SYS_CFG  UART2_mode          LL_SYS_SetIrDA2Mode
  */
__STATIC_INLINE void LL_SYS_SetIrDA2Mode(void)
{
  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART2_MODE);
}

/**
  * @brief  Set IrDA3 mode
  * @rmtoll SYSCFG.SYS_CFG  UART3_mode          LL_SYS_SetIrDA3Mode
  */
__STATIC_INLINE void LL_SYS_SetIrDA3Mode(void)
{
  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART3_MODE);
}

/**
  * @brief  Set IrDA4 mode
  * @rmtoll SYSCFG.SYS_CFG  UART4_mode          LL_SYS_SetIrDA4Mode
  */
__STATIC_INLINE void LL_SYS_SetIrDA4Mode(void)
{
  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART4_MODE);
}

/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group4 System ICTL Functions
  * @{
  */
/**
  * @brief  ICTL set pin configuration
  * @rmtoll SYSCFG.IRQ_CFG  pin          LL_ICTL_SetPinSelect
  * @param  Pin the parameter can be one of 0 to 63
  * @param  Cfg the parameter can be ont of the follow values:
  *         @arg @ref LL_IRQ_CFG_1
  *         @arg @ref LL_IRQ_CFG_2
  */
__STATIC_INLINE void LL_ICTL_SetPinSelect(uint32_t Pin, uint32_t Cfg)
{
  if(Pin < 32)
  {
    MODIFY_REG(SYSCFG->IRQ_CFG_1, (0x1UL << Pin), (Cfg << Pin));
  }
  else if(Pin < 64)
  {
    MODIFY_REG(SYSCFG->IRQ_CFG_2, (0x1UL << (Pin - 32)), (Cfg << (Pin - 32)));
  }
  else
  {

  }
}

/**
  * @brief  ICTL get pin configuration
  * @rmtoll SYSCFG.IRQ_CFG  pin          LL_ICTL_GetPinSelect
  * @param  Pin the parameter can be one of 0 to 63
  * @retval  Return value can be ont of the follow values:
  *         @arg @ref LL_IRQ_CFG_1
  *         @arg @ref LL_IRQ_CFG_2
  */
__STATIC_INLINE uint32_t LL_ICTL_GetPinSelect(uint32_t Pin)
{
  if(Pin < 32)
  {
    return (uint32_t)(READ_BIT(SYSCFG->IRQ_CFG_1, (0x1UL << Pin)) ? LL_IRQ_CFG_2 : LL_IRQ_CFG_1);
  }
  else if(Pin < 64)
  {
    return (uint32_t)(READ_BIT(SYSCFG->IRQ_CFG_2, (0x1UL << (Pin - 32))) ? LL_IRQ_CFG_2 : LL_IRQ_CFG_1);
  }
  else
  {
    return LL_IRQ_CFG_1;
  }
}

/**
  * @brief  ICTL set multiple pins configuration
  * @rmtoll SYSCFG.IRQ_CFG  pin          LL_ICTL_SetPinSelect
  * @param  PinRange the parameter can be one of 0x0 to 0x1 
  * @param  PinMask the parameter can be combined of 0x1 to 0x80000000 
  * @param  PinCfg the parameter can be combined of 0x1 to 0x80000000 
  */
__STATIC_INLINE void LL_ICTL_SetMultiPinsSelect(uint32_t PinRange, uint32_t PinMask, uint32_t PinCfg)
{
  if(PinRange < 1)
  {
    MODIFY_REG(SYSCFG->IRQ_CFG_1, (PinMask), (PinCfg));
  }
  else 
  {
    MODIFY_REG(SYSCFG->IRQ_CFG_2, (PinMask), (PinCfg));
  }
}

/**
  * @brief  ICTL get multiple pins configuration
  * @rmtoll SYSCFG.IRQ_CFG  pin          LL_ICTL_GetPinSelect
  * @param  PinRange the parameter can be one of 0x0 to 0x1 
  * @param  PinMask the parameter can be combined of 0x1 to 0x80000000 
  * @retval PinCfg the parameter can be combined of 0x1 to 0x80000000 
  */
__STATIC_INLINE uint32_t LL_ICTL_GetMultiPinsSelect(uint32_t PinRange, uint32_t PinMask)
{
  if(PinRange < 1)
  {
    return (uint32_t)(READ_BIT(SYSCFG->IRQ_CFG_1, (PinMask)));
  }
  else
  {
    return (uint32_t)(READ_BIT(SYSCFG->IRQ_CFG_2, (PinMask)));
  }
}

/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group5 System DMA Functions
  * @{
  */
/**
  * @brief  DMA set hardware handshaking Interface configuration
  * @rmtoll SYSCFG.DMA_CFG  ch          LL_DMA_SetHWHSIFSelect
  * @param  Mask
  *       @ref SYSTEM_LL_EC_DMA_HSIF_Assign
  * @param  Cfg 
  *       @ref SYSTEM_LL_EC_DMA_HSIF_Assign
  */
__STATIC_INLINE void LL_DMA_SetHWHSIFSelect(uint32_t Mask, uint32_t Cfg)
{
  MODIFY_REG(SYSCFG->DMA_CFG, Mask, Cfg);
}

/**
  * @brief  DMA Get hardware handshaking interface configuration
  * @rmtoll SYSCFG.DMA_CFG  ch          LL_DMA_GetHWHSIFSelect
  * @param  Mask 
  *       @ref SYSTEM_LL_EC_DMA_HSIF_Assign
  * @retval  Mask value 
  */
__STATIC_INLINE uint32_t LL_DMA_GetHWHSIFSelect(uint32_t Mask)
{
  return (uint32_t)(READ_BIT(SYSCFG->DMA_CFG, Mask));
}

/**
  * @brief  DMA set hardware handshaking Interface configuration
  * @rmtoll SYSCFG.DMA_CFG  ch          LL_DMA_SetHWHSIFSelect
  * @param  Index
  *        @arg @ref LL_DMA_SHIF_INDEX_0          
  *        @arg @ref LL_DMA_SHIF_INDEX_1          
  *        @arg @ref LL_DMA_SHIF_INDEX_2          
  *        @arg @ref LL_DMA_SHIF_INDEX_3          
  *        @arg @ref LL_DMA_SHIF_INDEX_4          
  *        @arg @ref LL_DMA_SHIF_INDEX_5          
  *        @arg @ref LL_DMA_SHIF_INDEX_6          
  *        @arg @ref LL_DMA_SHIF_INDEX_7          
  *        @arg @ref LL_DMA_SHIF_INDEX_8          
  *        @arg @ref LL_DMA_SHIF_INDEX_9          
  *        @arg @ref LL_DMA_SHIF_INDEX_10          
  *        @arg @ref LL_DMA_SHIF_INDEX_11          
  *        @arg @ref LL_DMA_SHIF_INDEX_12          
  *        @arg @ref LL_DMA_SHIF_INDEX_13          
  *        @arg @ref LL_DMA_SHIF_INDEX_14          
  *        @arg @ref LL_DMA_SHIF_INDEX_15          
  * @param  Cfg 
  *        @arg @ref LL_DMA_SHIF_CFG_0
  *        @arg @ref LL_DMA_SHIF_CFG_1
  *        @arg @ref LL_DMA_SHIF_CFG_2
  *        @arg @ref LL_DMA_SHIF_CFG_3
  * @if (XT32H0xxB)
  *        @arg @ref LL_DMA_SHIF_CFG_5
  *        @arg @ref LL_DMA_SHIF_CFG_6
  *        @arg @ref LL_DMA_SHIF_CFG_7
  *        @arg @ref LL_DMA_SHIF_CFG_8
  * @endif
  */
__STATIC_INLINE void LL_DMA_SetHWHSIFSelectByIndex(uint32_t Index, uint32_t Cfg)
{
  MODIFY_REG(SYSCFG->DMA_CFG, 0x03UL << (Index << 1), Cfg << (Index << 1));
}

/**
  * @brief  DMA Get hardware handshaking interface configuration
  * @rmtoll SYSCFG.DMA_CFG  ch          LL_DMA_GetHWHSIFSelect
  * @param  Index 
  *        @arg @ref LL_DMA_SHIF_INDEX_0          
  *        @arg @ref LL_DMA_SHIF_INDEX_1          
  *        @arg @ref LL_DMA_SHIF_INDEX_2          
  *        @arg @ref LL_DMA_SHIF_INDEX_3          
  *        @arg @ref LL_DMA_SHIF_INDEX_4          
  *        @arg @ref LL_DMA_SHIF_INDEX_5          
  *        @arg @ref LL_DMA_SHIF_INDEX_6          
  *        @arg @ref LL_DMA_SHIF_INDEX_7          
  *        @arg @ref LL_DMA_SHIF_INDEX_8          
  *        @arg @ref LL_DMA_SHIF_INDEX_9          
  *        @arg @ref LL_DMA_SHIF_INDEX_10          
  *        @arg @ref LL_DMA_SHIF_INDEX_11          
  *        @arg @ref LL_DMA_SHIF_INDEX_12          
  *        @arg @ref LL_DMA_SHIF_INDEX_13          
  *        @arg @ref LL_DMA_SHIF_INDEX_14          
  *        @arg @ref LL_DMA_SHIF_INDEX_15          
  * @retval  Return value 
  *        @arg @ref LL_DMA_SHIF_CFG_0
  *        @arg @ref LL_DMA_SHIF_CFG_1
  *        @arg @ref LL_DMA_SHIF_CFG_2
  *        @arg @ref LL_DMA_SHIF_CFG_3
  * @if (XT32H0xxB)
  *        @arg @ref LL_DMA_SHIF_CFG_5
  *        @arg @ref LL_DMA_SHIF_CFG_6
  *        @arg @ref LL_DMA_SHIF_CFG_7
  *        @arg @ref LL_DMA_SHIF_CFG_8
  * @endif
  */
__STATIC_INLINE uint32_t LL_DMA_GetHWHSIFSelectByIndex(uint32_t Index)
{
  return (uint32_t)(READ_BIT(SYSCFG->DMA_CFG, 0x03UL << (Index << 1)) >> (Index << 1));
}
/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group6 System WDT Functions
  * @{
  */
/**
  * @brief  Reset WDTW
  * @rmtoll SYSCFG.WDT_CFG  CFG_RST          LL_WDTW_Reset
  */
__STATIC_INLINE void LL_WDTW_Reset(void)
{
  CLEAR_BIT(SYSCFG->WDT_CFG, SYSCFG_WDTW_CFG_RST);
}

/**
  * @brief  Release Reset WDTW
  * @rmtoll SYSCFG.WDT_CFG  CFG_RST          LL_WDTW_ResetRelease
  */
__STATIC_INLINE void LL_WDTW_ResetRelease(void)
{
  SET_BIT(SYSCFG->WDT_CFG, SYSCFG_WDTW_CFG_RST);
}

/**
  * @brief  WDTW testmode
  * @rmtoll SYSCFG.WDT_CFG  CFG_SP          LL_WDTW_TestMode
  */
__STATIC_INLINE void LL_WDTW_TestMode(void)
{
  SET_BIT(SYSCFG->WDT_CFG, SYSCFG_WDTW_CFG_SPD);
}

/**
  * @brief  WDTW normal mode
  * @rmtoll SYSCFG.WDT_CFG  CFG_SP          LL_WDTW_NormalMode
  */
__STATIC_INLINE void LL_WDTW_NormalMode(void)
{
  CLEAR_BIT(SYSCFG->WDT_CFG, SYSCFG_WDTW_CFG_SPD);
}

/**
  * @brief  WDTW enable external clock
  * @rmtoll SYSCFG.WDT_CFG  CFG_En          LL_WDTW_EnableExternalClock
  */
__STATIC_INLINE void LL_WDTW_EnableExternalClock(void)
{
  SET_BIT(SYSCFG->WDT_CFG, SYSCFG_WDTW_CFG_EXTCLK);
}

/**
  * @brief  WDTW disable external clock
  * @rmtoll SYSCFG.WDT_CFG  CFG_En          LL_WDTW_DisableExternalClock
  */
__STATIC_INLINE void LL_WDTW_DisableExternalClock(void)
{
  CLEAR_BIT(SYSCFG->WDT_CFG, SYSCFG_WDTW_CFG_EXTCLK);
}
/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group7 System Software Reset Functions
  * @{
  */
/**
  * @brief  Reset
  * @rmtoll SYSCFG.SW_RST_CFG   Bit          LL_Reset
  * @param  Line this parameter can be one of the follow values:
  *         @arg @ref LL_SWRST_UART0                 
  *         @arg @ref LL_SWRST_UART1                 
  *         @arg @ref LL_SWRST_UART2                 
  *         @arg @ref LL_SWRST_UART3                 
  *         @arg @ref LL_SWRST_I2C0                  
  *         @arg @ref LL_SWRST_I2C1                  
  *         @arg @ref LL_SWRST_TIMB11                
  *         @arg @ref LL_SWRST_TIMB12                
  *         @arg @ref LL_SWRST_TIMB13                
  *         @arg @ref LL_SWRST_TIMB14                
  *         @arg @ref LL_SWRST_TIMB21                
  *         @arg @ref LL_SWRST_TIMB22                
  *         @arg @ref LL_SWRST_TIMB23                
  *         @arg @ref LL_SWRST_TIMB24                
  *         @arg @ref LL_SWRST_SPI0                  
  *         @arg @ref LL_SWRST_SPI1                  
  *         @arg @ref LL_SWRST_GPIO                  
  *         @arg @ref LL_SWRST_TIMA1                 
  *         @arg @ref LL_SWRST_TIMA2                 
  *         @arg @ref LL_SWRST_TIMG1                 
  *         @arg @ref LL_SWRST_TIMG2                 
  *         @arg @ref LL_SWRST_TIMG3                 
  *         @arg @ref LL_SWRST_TIMG4                 
  */
__STATIC_INLINE void LL_Reset(uint32_t Line)
{
  CLEAR_BIT(SYSCFG->SW_RST_CFG, Line);
}

/**
  * @brief  Reset release
  * @rmtoll SYSCFG.SW_RST_CFG   Bit          LL_ResetRelease
  * @param  Line this parameter can be one of the follow values:
  *         @arg @ref LL_SWRST_UART0                 
  *         @arg @ref LL_SWRST_UART1                 
  *         @arg @ref LL_SWRST_UART2                 
  *         @arg @ref LL_SWRST_UART3                 
  *         @arg @ref LL_SWRST_I2C0                  
  *         @arg @ref LL_SWRST_I2C1                  
  *         @arg @ref LL_SWRST_TIMB11                
  *         @arg @ref LL_SWRST_TIMB12                
  *         @arg @ref LL_SWRST_TIMB13                
  *         @arg @ref LL_SWRST_TIMB14                
  *         @arg @ref LL_SWRST_TIMB21                
  *         @arg @ref LL_SWRST_TIMB22                
  *         @arg @ref LL_SWRST_TIMB23                
  *         @arg @ref LL_SWRST_TIMB24                
  *         @arg @ref LL_SWRST_SPI0                  
  *         @arg @ref LL_SWRST_SPI1                  
  *         @arg @ref LL_SWRST_GPIO                  
  *         @arg @ref LL_SWRST_TIMA1                 
  *         @arg @ref LL_SWRST_TIMA2                 
  *         @arg @ref LL_SWRST_TIMG1                 
  *         @arg @ref LL_SWRST_TIMG2                 
  *         @arg @ref LL_SWRST_TIMG3                 
  *         @arg @ref LL_SWRST_TIMG4                 
  */
__STATIC_INLINE void LL_ResetRelease(uint32_t Line)
{
  SET_BIT(SYSCFG->SW_RST_CFG, Line);
}
/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group8 System Advanced Timer Functions
  * @{
  */

/**
  * @brief  Enable ePWM break source ECC
  * @rmtoll SYSCFG.TIMER_ADV_CFG  ECCERR          LL_PWMBRK_ECCERR_Enable
  */
__STATIC_INLINE void LL_PWMBRK_ECCERR_Enable(void)
{
  SET_BIT(SYSCFG->TIMER_ADV_CFG, SYSCFG_TACFG_ECCERR);
}

/**
  * @brief  Disable ePWM break source ECC
  * @rmtoll SYSCFG.TIMER_ADV_CFG  ECCERR          LL_PWMBRK_ECCERR_Disable
  */
__STATIC_INLINE void LL_PWMBRK_ECCERR_Disable(void)
{
  CLEAR_BIT(SYSCFG->TIMER_ADV_CFG, SYSCFG_TACFG_ECCERR);
}

/**
  * @brief  Enable ePWM break source parity
  * @rmtoll SYSCFG.TIMER_ADV_CFG  PARCHK          LL_PWMBRK_Parity_Enable
  */
__STATIC_INLINE void LL_PWMBRK_Parity_Enable(void)
{
  SET_BIT(SYSCFG->TIMER_ADV_CFG, SYSCFG_TACFG_PARCHK);
}

/**
  * @brief  Disable ePWM break source parity
  * @rmtoll SYSCFG.TIMER_ADV_CFG  PARCHK          LL_PWMBRK_Parity_Disable
  */
__STATIC_INLINE void LL_PWMBRK_Parity_Disable(void)
{
  CLEAR_BIT(SYSCFG->TIMER_ADV_CFG, SYSCFG_TACFG_PARCHK);
}

/**
  * @brief  Enable ePWM break source voltage detector
  * @rmtoll SYSCFG.TIMER_ADV_CFG  VOLDET          LL_PWMBRK_VolDet_Enable
  */
__STATIC_INLINE void LL_PWMBRK_VolDet_Enable(void)
{
  SET_BIT(SYSCFG->TIMER_ADV_CFG, SYSCFG_TACFG_VOLDET);
}

/**
  * @brief  Disable ePWM break source voltage detector
  * @rmtoll SYSCFG.TIMER_ADV_CFG  VOLDET          LL_PWMBRK_VolDet_Disable
  */
__STATIC_INLINE void LL_PWMBRK_VolDet_Disable(void)
{
  CLEAR_BIT(SYSCFG->TIMER_ADV_CFG, SYSCFG_TACFG_VOLDET);
}

/**
  * @brief  Enable ePWM break source CPU core lockup
  * @rmtoll SYSCFG.TIMER_ADV_CFG  LKE          LL_PWMBRK_Lockup_Enable
  */
__STATIC_INLINE void LL_PWMBRK_Lockup_Enable(void)
{
  SET_BIT(SYSCFG->TIMER_ADV_CFG, SYSCFG_TACFG_LKE);
}

/**
  * @brief  Disable ePWM break source CPU core lockup
  * @rmtoll SYSCFG.TIMER_ADV_CFG  LKE          LL_PWMBRK_Lockup_Disable
  */
__STATIC_INLINE void LL_PWMBRK_Lockup_Disable(void)
{
  CLEAR_BIT(SYSCFG->TIMER_ADV_CFG, SYSCFG_TACFG_LKE);
}

/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group9 System GPIO AUX Functions
  * @{
  */
/**
  * @brief  Set GPIO Aux
  * @rmtoll SYSCFG.GPIO_AUX_x   Pinx         LL_GPIO_AUX_SetPin
  * @param  Group This parameter can be one of the follow values:
  *         @arg @ref LL_GPIO_AUXGROUP_A
  *         @arg @ref LL_GPIO_AUXGROUP_B
  *         @arg @ref LL_GPIO_AUXGROUP_C
  *         @arg @ref LL_GPIO_AUXGROUP_D
  * @param  Pin This parameter can be one of 0x00000001 to 0x80000000 (32)
  * @param  Status This parameter can be one of the follow values:
  *         @arg @ref LL_GPIO_AUX_INPUT
  *         @arg @ref LL_GPIO_AUX_OUTPUT
  */
__STATIC_INLINE void LL_GPIO_AUX_SetPin(uint32_t Group, uint32_t Pin, uint32_t Status)
{
  uint32_t pos = 0;
  uint32_t mask = 0x00000001UL;

  while(pos<32)
  {
    if(Pin & mask) break;
    pos++;
    mask <<= 1;
  }

  switch(Group)
  {
    case LL_GPIO_AUXGROUP_A:
      MODIFY_REG(SYSCFG->GPIO_ENAUX_A, Pin, (Status << pos));
      break;
    case LL_GPIO_AUXGROUP_B:
      MODIFY_REG(SYSCFG->GPIO_ENAUX_B, Pin, (Status << pos));
      break;
    case LL_GPIO_AUXGROUP_C:
      MODIFY_REG(SYSCFG->GPIO_ENAUX_C, Pin, (Status << pos));
      break;
    case LL_GPIO_AUXGROUP_D:
      MODIFY_REG(SYSCFG->GPIO_ENAUX_D, Pin, (Status << pos));
      break;
    default:
      break;
  }
}

/**
  * @brief  Get GPIO Aux
  * @rmtoll SYSCFG.GPIO_AUX_x   Pinx         LL_GPIO_AUX_GetPin
  * @param  Group This parameter can be one of the follow values:
  *         @arg @ref LL_GPIO_AUXGROUP_A
  *         @arg @ref LL_GPIO_AUXGROUP_B
  *         @arg @ref LL_GPIO_AUXGROUP_C
  *         @arg @ref LL_GPIO_AUXGROUP_D
  * @param  Pin This parameter can be one of 0x00000001 to 0x80000000 (32)
  * @retval  Status can be one of the follow values:
  *         @arg @ref LL_GPIO_AUX_INPUT
  *         @arg @ref LL_GPIO_AUX_OUTPUT
  */
__STATIC_INLINE uint32_t LL_GPIO_AUX_GetPin(uint32_t Group, uint32_t Pin)
{
  uint32_t val = 0;
  switch(Group)
  {
    case LL_GPIO_AUXGROUP_A:
      val = (uint32_t)(READ_BIT(SYSCFG->GPIO_ENAUX_A, Pin) ? LL_GPIO_AUX_OUTPUT : LL_GPIO_AUX_INPUT );
      break;
    case LL_GPIO_AUXGROUP_B:
      val = (uint32_t)(READ_BIT(SYSCFG->GPIO_ENAUX_B, Pin) ? LL_GPIO_AUX_OUTPUT : LL_GPIO_AUX_INPUT );
      break;
    case LL_GPIO_AUXGROUP_C:
      val = (uint32_t)(READ_BIT(SYSCFG->GPIO_ENAUX_C, Pin) ? LL_GPIO_AUX_OUTPUT : LL_GPIO_AUX_INPUT );
      break;
    case LL_GPIO_AUXGROUP_D:
      val = (uint32_t)(READ_BIT(SYSCFG->GPIO_ENAUX_D, Pin) ? LL_GPIO_AUX_OUTPUT : LL_GPIO_AUX_INPUT );
      break;
    default:
      break;
  }
	return val;
}
/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group10 System UID Functions
  * @{
  */
/**
  * @brief  Get UID 0
  * @rmtoll SYSCFG.UID_REG_1   UID0         LL_UID_GetUID0
  * @retval UID0
  */
__STATIC_INLINE uint32_t LL_UID_GetUID0(void)
{
  return (uint32_t)(READ_REG(SYSCFG->UID_REG_1));
}

/**
  * @brief  Get UID 1
  * @rmtoll SYSCFG.UID_REG_2   UID1         LL_UID_GetUID1
  * @retval UID1
  */
__STATIC_INLINE uint32_t LL_UID_GetUID1(void)
{
  return (uint32_t)(READ_REG(SYSCFG->UID_REG_2));
}

/**
  * @brief  Get UID 2
  * @rmtoll SYSCFG.UID_REG_3   UID2         LL_UID_GetUID2
  * @retval UID2
  */
__STATIC_INLINE uint32_t LL_UID_GetUID2(void)
{
  return (uint32_t)(READ_REG(SYSCFG->UID_REG_3));
}
/**
  * @}
  */

/** @defgroup SYSTEM_LL_Exported_Functions_Group11 System AFC Functions
  * @{
  */
#if defined(XT32H0xxA)
/**
  * @brief  AFC enable
  * @rmtoll SYSCFG.AFC_CTRL   AFCEN         LL_AFC_Enable
  */
__STATIC_INLINE void LL_AFC_Enable(void)
{
  SET_BIT(SYSCFG->AFC_CTRL, SYSCFG_AFCCTRL_AFCEN);
}

/**
  * @brief  AFC disable
  * @rmtoll SYSCFG.AFC_CTRL   AFCEN         LL_AFC_Disable
  */
__STATIC_INLINE void LL_AFC_Disable(void)
{
  CLEAR_BIT(SYSCFG->AFC_CTRL, SYSCFG_AFCCTRL_AFCEN);
}

/**
  * @brief  AFC Bypass enable
  * @rmtoll SYSCFG.AFC_CTRL   AFCBYS         LL_AFC_BypassEnable
  */
__STATIC_INLINE void LL_AFC_BypassEnable(void)
{
  SET_BIT(SYSCFG->AFC_CTRL, SYSCFG_AFCCTRL_AFCBYS);
}

/**
  * @brief  AFC Bypass enable
  * @rmtoll SYSCFG.AFC_CTRL   AFCBYS         LL_AFC_BypassDisable
  */
__STATIC_INLINE void LL_AFC_BypassDisable(void)
{
  CLEAR_BIT(SYSCFG->AFC_CTRL, SYSCFG_AFCCTRL_AFCBYS);
}

/**
  * @brief  AFC interrupt enable
  * @rmtoll SYSCFG.AFC_CTRL   AxIE         LL_AFC_InterruptEnable
  * @param IntEable the value is combined of the following list:
  *       @arg @ref  LL_AFC_INT_ENABLE_LOOP       
  *       @arg @ref  LL_AFC_INT_ENABLE_NORMAL     
  *       @arg @ref  LL_AFC_INT_ENABLE_ERROR      
  */
__STATIC_INLINE void LL_AFC_InterruptEnable(uint32_t IntEable)
{
  SET_BIT(SYSCFG->AFC_CTRL, IntEable);
}

/**
  * @brief  AFC interrupt enable
  * @rmtoll SYSCFG.AFC_CTRL   AxIE         LL_AFC_InterruptDisable
  * @param IntEable the value is combined of the following list:
  *       @arg @ref  LL_AFC_INT_ENABLE_LOOP       
  *       @arg @ref  LL_AFC_INT_ENABLE_NORMAL     
  *       @arg @ref  LL_AFC_INT_ENABLE_ERROR      
  */
__STATIC_INLINE void LL_AFC_InterruptDisable(uint32_t IntEable)
{
  CLEAR_BIT(SYSCFG->AFC_CTRL, IntEable);
}


/**
  * @brief  Set AFC calibrate clock
  * @rmtoll SYSCFG.AFC_CTRL   CBCLKS         LL_AFC_SetCalibrateClock
  * @param Clock the value is one of the following list:
  *       @arg @ref  LL_AFC_CLKSRC_32K       
  *       @arg @ref  LL_AFC_CLKSRC_16M     
  */
__STATIC_INLINE void LL_AFC_SetCalibrateClock(uint32_t Clock)
{
  MODIFY_REG(SYSCFG->AFC_CTRL, SYSCFG_AFCCTRL_CBCLKS, Clock);
}

/**
  * @brief  Set AFC different
  * @rmtoll SYSCFG.AFC_CTRL   DIFFCNT         LL_AFC_SetDifferent
  * @param Diff 
  */
__STATIC_INLINE void LL_AFC_SetDifferent(uint32_t Diff)
{
  MODIFY_REG(SYSCFG->AFC_CTRL, SYSCFG_AFCCTRL_DIFFCNT, Diff << SYSCFG_AFCCTRL_DIFFCNT_Pos);
}

/**
  * @brief  Set AFC refernce
  * @rmtoll SYSCFG.AFC_CTRL   DIFFCNT         LL_AFC_SetReference
  * @param Ref 
  */
__STATIC_INLINE void LL_AFC_SetReference(uint32_t Ref)
{
  MODIFY_REG(SYSCFG->AFC_CTRL, SYSCFG_AFCCTRL_RFCNT, Ref << SYSCFG_AFCCTRL_RFCNT_Pos);
}

/**
  * @brief  Set AFC Initial
  * @rmtoll SYSCFG.AFC_CFG   CBADJ         LL_AFC_SetInital
  * @param Initial 
  */
__STATIC_INLINE void LL_AFC_SetInital(uint32_t Initial)
{
  MODIFY_REG(SYSCFG->AFC_CFG, SYSCFG_AFCCFG_CBADJ, Initial << SYSCFG_AFCCFG_CBADJ_Pos);
}

/**
  * @brief  Set AFC Standard
  * @rmtoll SYSCFG.AFC_CFG   STDCNT         LL_AFC_SetStandard
  * @param Standard 
  */
__STATIC_INLINE void LL_AFC_SetStandard(uint32_t Standard)
{
  MODIFY_REG(SYSCFG->AFC_CFG, SYSCFG_AFCCFG_STDCNT, Standard << SYSCFG_AFCCFG_STDCNT_Pos);
}

/**
  * @brief  AFC Get interrupt flag
  * @rmtoll SYSCFG.AFC_RES   AxIF         LL_AFC_GetInterruptFlag
  * @param Flag the value is combined of the following list:
  *       @arg @ref  LL_AFC_INT_FLAG_LOOP       
  *       @arg @ref  LL_AFC_INT_FLAG_NORMAL     
  *       @arg @ref  LL_AFC_INT_FLAG_ERROR      
  * @retval status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_AFC_GetInterrupt(uint32_t Flag)
{
  return (uint32_t)(READ_BIT(SYSCFG->AFC_RES, Flag)? SET : RESET);
}

/**
  * @brief  AFC Clear interrupt
  * @rmtoll SYSCFG.AFC_RES   AxIF         LL_AFC_ClearInterrupt
  * @param Flag the value is combined of the following list:
  *       @arg @ref  LL_AFC_INT_FLAG_LOOP       
  *       @arg @ref  LL_AFC_INT_FLAG_NORMAL     
  *       @arg @ref  LL_AFC_INT_FLAG_ERROR      
  */
__STATIC_INLINE void LL_AFC_ClearInterrupt(uint32_t Flag)
{
  CLEAR_BIT(SYSCFG->AFC_RES, Flag);
}

/**
  * @brief  AFC Set reference clock divider
  * @rmtoll SYSCFG.AFC_RES   RFDIV         LL_AFC_SetRefDiv
  * @param Div
  */
__STATIC_INLINE void LL_AFC_SetRefDiv(uint32_t Div)
{
  MODIFY_REG(SYSCFG->AFC_RES, SYSCFG_AFCRES_RFDIV, Div << SYSCFG_AFCRES_RFDIV_Pos);
}

/**
  * @brief  AFC Get CalibarteResult
  * @rmtoll SYSCFG.AFC_RES   ADJRES         LL_AFC_GetCalibrateResult
  * @retval result 
  */
__STATIC_INLINE uint32_t LL_AFC_GetCalibrateResult(void)
{
  return (uint32_t)(READ_BIT(SYSCFG->AFC_RES, SYSCFG_AFCRES_ADJRES));
}
#endif

#if defined(XT32H0xxB)
/**
  * @brief  Set adv timers anf general timers input source
  * @rmtoll    SYSCFG.TIM_xx_IMX         LL_TIM_SetInputSource
  * @param TimerId
  *        This value is one of the following values
  *        @arg @ref LL_TIM_TIMA1_ID           (0)  
  *        @arg @ref LL_TIM_TIMA2_ID           (1)  
  *        @arg @ref LL_TIM_TIMG1_ID           (2)  
  *        @arg @ref LL_TIM_TIMG2_ID           (3)  
  *        @arg @ref LL_TIM_TIMG3_ID           (4)  
  *        @arg @ref LL_TIM_TIMG4_ID           (5)  
  * @param ChId
  *        This value is one of the following values
  *        @arg @ref LL_TIM_IC_CH1_ID                (0)  
  *        @arg @ref LL_TIM_IC_CH2_ID                (1)  
  *        @arg @ref LL_TIM_IC_CH3_ID                (2)  
  *        @arg @ref LL_TIM_IC_CH4_ID                (3)  
  *        @arg @ref LL_TIM_IC_ETR_ID                (4)  
  * @param Source
  *        This value is one of the following values
  *        @arg @ref LL_TIM_IMX_SRC_TIMA1           (0)  
  *        @arg @ref LL_TIM_IMX_SRC_TIMA2           (1)  
  *        @arg @ref LL_TIM_IMX_SRC_TIMG1           (2)  
  *        @arg @ref LL_TIM_IMX_SRC_TIMG2           (3)  
  *        @arg @ref LL_TIM_IMX_SRC_TIMG3           (4)  
  *        @arg @ref LL_TIM_IMX_SRC_TIMG4           (5)  
  *        @arg @ref LL_TIM_IMX_SRC_NONE            (6)  
  */
__STATIC_INLINE void LL_TIM_SetInputSource(uint32_t TimerId, uint32_t ChId,uint32_t Source)
{
  uint32_t *preg = (uint32_t *)(&(SYSCFG->TIM_A1_IMX))+TimerId;
  uint32_t pos = SYSCFG_TIMA1IMX_CH_1_Pos + (ChId << 2);
  MODIFY_REG(*preg, SYSCFG_TIMA1IMX_CH_1 << pos, Source << pos);
}


/**
  * @brief  Set adv timers and general timers output mode 
  * @rmtoll    SYSCFG.TIM_xx_IMX         LL_TIM_SetInputSource
  * @param TimerId
  *        This value is one of the following values
  *        @arg @ref LL_TIM_TIMA1_ID           (0)  
  *        @arg @ref LL_TIM_TIMA2_ID           (1)  
  *        @arg @ref LL_TIM_TIMG1_ID           (2)  
  *        @arg @ref LL_TIM_TIMG2_ID           (3)  
  *        @arg @ref LL_TIM_TIMG3_ID           (4)  
  *        @arg @ref LL_TIM_TIMG4_ID           (5)  
  * @param ChId
  *        This value is one of the following values
  *        @arg @ref LL_TIM_OC_CH1_ID                (0)  
  *        @arg @ref LL_TIM_OC_CH2_ID                (1)  
  * @param Config
  *        This value is one of the following values
  *        @arg @ref LL_TIM_OC_COMPLEMENTARY           (0)  
  *        @arg @ref LL_TIM_OC_SINGLE_ENDED           (1)  
  */
__STATIC_INLINE void LL_TIM_SetOutputConfig(uint32_t TimerId, uint32_t ChId,uint32_t Config)
{
  uint32_t pos = SYSCFG_TIMCMSOC_TIMA1_CH1_OS_Pos + (TimerId << 1) + ChId;
  MODIFY_REG(SYSCFG->TIM_CMS_OC, SYSCFG_TIMCMSOC_TIMA1_CH1_OS << pos, Config << pos);
}

#endif /* XT32H0xxB */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

//#endif /* defined (FLASH) || defined (SYSCFG) || defined (DBG) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_SYSTEM_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
