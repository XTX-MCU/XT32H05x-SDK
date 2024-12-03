/**
  ******************************************************************************
  * @file    xt32h0xx_ll_ictl.h
  * @author  Software Team
  * @brief   Header file of interrupt controller LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_ICTL_H
#define XT32H0xx_LL_ICTL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (ICTL)

/** @defgroup ICTL_LL ICTL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/

/* Private Macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ICTL_LL_Private_Macros ICTL Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/
/* Exported types ------------------------------------------------------------*/
/** @defgroup ICTL_LL_Exported_Types ICTL Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ICTL_LL_ES_INIT ICTL Exported Init structure
  * @{
  */
typedef struct
{

  uint32_t Irq_0_31;           /*!< Specifies the IRQ to be enabled or disabled for Lines in range 0 to 31
                                     This parameter can be any combination of @ref ICTL_LL_EC_IRQ */
  uint32_t Irq_32_63;          /*!< Specifies the IRQ lines to be enabled or disabled for Lines in range 32 to 63
                                     This parameter can be any combination of @ref ICTL_LL_EC_IRQ */

  uint32_t Fiq_0_7;           /*!< Specifies the FIQ lines to be enabled or disabled for Lines in range 0 to 7
                                     This parameter can be any combination of @ref ICTL_LL_EC_FIQ */

  FunctionalState LineCommand;  /*!< Specifies the new state of the selected ICTL lines.
                                     This parameter can be set either to ENABLE or DISABLE */

} LL_ICTL_InitTypeDef;

/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup ICTL_LL_Exported_Constants ICTL Exported Constants
  * @{
  */

/** @defgroup ICTL_LL_EC_IRQ IRQ
  * @{
  */
#define LL_ICTL_IRQ_0                  (0x00000001UL)                          /*!< Extended irq 0 */
#define LL_ICTL_IRQ_1                  (0x00000002UL)                          /*!< Extended irq 1 */
#define LL_ICTL_IRQ_2                  (0x00000004UL)                          /*!< Extended irq 2 */
#define LL_ICTL_IRQ_3                  (0x00000008UL)                          /*!< Extended irq 3 */
#define LL_ICTL_IRQ_4                  (0x00000010UL)                          /*!< Extended irq 4 */
#define LL_ICTL_IRQ_5                  (0x00000020UL)                          /*!< Extended irq 5 */
#define LL_ICTL_IRQ_6                  (0x00000040UL)                          /*!< Extended irq 6 */
#define LL_ICTL_IRQ_7                  (0x00000080UL)                          /*!< Extended irq 7 */
#define LL_ICTL_IRQ_8                  (0x00000100UL)                          /*!< Extended irq 8 */
#define LL_ICTL_IRQ_9                  (0x00000200UL)                          /*!< Extended irq 9 */
#define LL_ICTL_IRQ_10                 (0x00000400UL)                          /*!< Extended irq 10 */
#define LL_ICTL_IRQ_11                 (0x00000800UL)                          /*!< Extended irq 11 */
#define LL_ICTL_IRQ_12                 (0x00001000UL)                          /*!< Extended irq 12 */
#define LL_ICTL_IRQ_13                 (0x00002000UL)                          /*!< Extended irq 13 */
#define LL_ICTL_IRQ_14                 (0x00004000UL)                          /*!< Extended irq 14 */
#define LL_ICTL_IRQ_15                 (0x00008000UL)                          /*!< Extended irq 15 */
#define LL_ICTL_IRQ_16                 (0x00010000UL)                          /*!< Extended irq 16 */
#define LL_ICTL_IRQ_17                 (0x00020000UL)                          /*!< Extended irq 17 */
#define LL_ICTL_IRQ_18                 (0x00040000UL)                          /*!< Extended irq 18 */
#define LL_ICTL_IRQ_19                 (0x00080000UL)                          /*!< Extended irq 19 */
#define LL_ICTL_IRQ_20                 (0x00100000UL)                          /*!< Extended irq 20 */
#define LL_ICTL_IRQ_21                 (0x00200000UL)                          /*!< Extended irq 21 */
#define LL_ICTL_IRQ_22                 (0x00400000UL)                          /*!< Extended irq 22 */
#define LL_ICTL_IRQ_23                 (0x00800000UL)                          /*!< Extended irq 23 */
#define LL_ICTL_IRQ_24                 (0x01000000UL)                          /*!< Extended irq 24 */
#define LL_ICTL_IRQ_25                 (0x02000000UL)                          /*!< Extended irq 25 */
#define LL_ICTL_IRQ_26                 (0x04000000UL)                          /*!< Extended irq 26 */
#define LL_ICTL_IRQ_27                 (0x08000000UL)                          /*!< Extended irq 27 */
#define LL_ICTL_IRQ_28                 (0x10000000UL)                          /*!< Extended irq 28 */
#define LL_ICTL_IRQ_29                 (0x20000000UL)                          /*!< Extended irq 29 */
#define LL_ICTL_IRQ_30                 (0x40000000UL)                          /*!< Extended irq 30 */
#define LL_ICTL_IRQ_31                 (0x80000000UL)                          /*!< Extended irq 31 */

#define LL_ICTL_IRQ_32                 (0x00000001UL)                          /*!< Extended irq 32 */
#define LL_ICTL_IRQ_33                 (0x00000002UL)                          /*!< Extended irq 33 */
#define LL_ICTL_IRQ_34                 (0x00000004UL)                          /*!< Extended irq 34 */
#define LL_ICTL_IRQ_35                 (0x00000008UL)                          /*!< Extended irq 35 */
#define LL_ICTL_IRQ_36                 (0x00000010UL)                          /*!< Extended irq 36 */
#define LL_ICTL_IRQ_37                 (0x00000020UL)                          /*!< Extended irq 37 */
#define LL_ICTL_IRQ_38                 (0x00000040UL)                          /*!< Extended irq 38 */
#define LL_ICTL_IRQ_39                 (0x00000080UL)                          /*!< Extended irq 39 */
#define LL_ICTL_IRQ_40                 (0x00000100UL)                          /*!< Extended irq 40 */
#define LL_ICTL_IRQ_41                 (0x00000200UL)                          /*!< Extended irq 41 */
#define LL_ICTL_IRQ_42                 (0x00000400UL)                          /*!< Extended irq 42 */
#define LL_ICTL_IRQ_43                 (0x00000800UL)                          /*!< Extended irq 43 */
#define LL_ICTL_IRQ_44                 (0x00001000UL)                          /*!< Extended irq 44 */
#define LL_ICTL_IRQ_45                 (0x00002000UL)                          /*!< Extended irq 45 */
#define LL_ICTL_IRQ_46                 (0x00004000UL)                          /*!< Extended irq 46 */
#define LL_ICTL_IRQ_47                 (0x00008000UL)                          /*!< Extended irq 47 */
#define LL_ICTL_IRQ_48                 (0x00010000UL)                          /*!< Extended irq 48 */
#define LL_ICTL_IRQ_49                 (0x00020000UL)                          /*!< Extended irq 49 */
#define LL_ICTL_IRQ_50                 (0x00040000UL)                          /*!< Extended irq 50 */
#define LL_ICTL_IRQ_51                 (0x00080000UL)                          /*!< Extended irq 51 */
#define LL_ICTL_IRQ_52                 (0x00100000UL)                          /*!< Extended irq 52 */
#define LL_ICTL_IRQ_53                 (0x00200000UL)                          /*!< Extended irq 53 */
#define LL_ICTL_IRQ_54                 (0x00400000UL)                          /*!< Extended irq 54 */
#define LL_ICTL_IRQ_55                 (0x00800000UL)                          /*!< Extended irq 55 */
#define LL_ICTL_IRQ_56                 (0x01000000UL)                          /*!< Extended irq 56 */
#define LL_ICTL_IRQ_57                 (0x02000000UL)                          /*!< Extended irq 57 */
#define LL_ICTL_IRQ_58                 (0x04000000UL)                          /*!< Extended irq 58 */
#define LL_ICTL_IRQ_59                 (0x08000000UL)                          /*!< Extended irq 59 */
#define LL_ICTL_IRQ_60                 (0x10000000UL)                          /*!< Extended irq 60 */
#define LL_ICTL_IRQ_61                 (0x20000000UL)                          /*!< Extended irq 61 */
#define LL_ICTL_IRQ_62                 (0x40000000UL)                          /*!< Extended irq 62 */
#define LL_ICTL_IRQ_63                 (0x80000000UL)                          /*!< Extended irq 63 */

#define LL_ICTL_IRQ(__IDX__)           ((__IDX__< 32 ) ? (0x00000001UL << (__IDX__)) : (0x00000001UL << (__IDX__ - 32)))  /*!< Extended IRQ x */

#define LL_ICTL_IRQ_ALL                (0xFFFFFFFFU)                           /*!< All Extended irq */

#if defined(USE_FULL_LL_DRIVER)
#define LL_ICTL_IRQ_NONE               (0x00000000U)                           /*!< None Extended irq */
#endif /*USE_FULL_LL_DRIVER*/

/**
  * @}
  */

/** @defgroup ICTL_LL_EC_FIQ FIQ
  * @{
  */
#define LL_ICTL_FIQ_0                  (0x00000001UL)                          /*!< Extended fiq 0 */
#define LL_ICTL_FIQ_1                  (0x00000002UL)                          /*!< Extended fiq 1 */
#define LL_ICTL_FIQ_2                  (0x00000004UL)                          /*!< Extended fiq 2 */
#define LL_ICTL_FIQ_3                  (0x00000008UL)                          /*!< Extended fiq 3 */
#define LL_ICTL_FIQ_4                  (0x00000010UL)                          /*!< Extended fiq 4 */
#define LL_ICTL_FIQ_5                  (0x00000020UL)                          /*!< Extended fiq 5 */
#define LL_ICTL_FIQ_6                  (0x00000040UL)                          /*!< Extended fiq 6 */
#define LL_ICTL_FIQ_7                  (0x00000080UL)                          /*!< Extended fiq 7 */

#define LL_ICTL_FIQ(__IDX__)           (0x00000001UL << (__IDX__))             /*!< Extended fiq x */

#define LL_ICTL_FIQ_ALL                (0x000000FFU)                           /*!< All Extended fiq */

#if defined(USE_FULL_LL_DRIVER)
#define LL_ICTL_FIQ_NONE               (0x00000000U)                           /*!< None Extended fiq */
#endif /*USE_FULL_LL_DRIVER*/

/**
  * @}
  */

/** @defgroup ICTL_LL_EC_IRQ_MAPPING IRQ MAPPING
  * @{
  */
/* Congiure 0 */  
#define LL_ICTL_I2C1_GCALL             (LL_ICTL_IRQ_0 )                        /*!< I2C 1 General Call   */
#define LL_ICTL_I2C1_RXF               (LL_ICTL_IRQ_1 )                        /*!< I2C 1 Rx Full        */
#define LL_ICTL_I2C1_RDQ               (LL_ICTL_IRQ_2 )                        /*!< I2C 1 RD Req         */
#define LL_ICTL_I2C1_STRTD             (LL_ICTL_IRQ_3 )                        /*!< I2C 1 Start Detect   */
#define LL_ICTL_I2C1_RESTRTD           (LL_ICTL_IRQ_4 )                        /*!< I2C 1 Restart Detect */
#define LL_ICTL_I2C1_STOPD             (LL_ICTL_IRQ_5 )                        /*!< I2C 1 Stop Detect    */
#define LL_ICTL_I2C1_ACT               (LL_ICTL_IRQ_6 )                        /*!< I2C 1 Activity       */
#define LL_ICTL_I2C1_TXE               (LL_ICTL_IRQ_7 )                        /*!< I2C 1 Tx Empty       */
#define LL_ICTL_I2C1_TXABRT            (LL_ICTL_IRQ_8 )                        /*!< I2C 1 Tx Abort       */
#define LL_ICTL_I2C1_TXO               (LL_ICTL_IRQ_9 )                        /*!< I2C 1 Tx Over        */
#define LL_ICTL_I2C1_RXDONE            (LL_ICTL_IRQ_10)                        /*!< I2C 1 Rx Done        */
#define LL_ICTL_I2C1_RXU               (LL_ICTL_IRQ_11)                        /*!< I2C 1 Rx Underflow   */
#define LL_ICTL_I2C1_RXO               (LL_ICTL_IRQ_12)                        /*!< I2C 1 Rx Over        */

#define LL_ICTL_IRQCFG_I2C1_MASK       (LL_ICTL_I2C1_GCALL   | \
                                        LL_ICTL_I2C1_RXF     | \
                                        LL_ICTL_I2C1_RDQ     | \
                                        LL_ICTL_I2C1_STRTD   | \
                                        LL_ICTL_I2C1_RESTRTD | \
                                        LL_ICTL_I2C1_STOPD   | \
                                        LL_ICTL_I2C1_ACT     | \
                                        LL_ICTL_I2C1_TXE     | \
                                        LL_ICTL_I2C1_TXABRT  | \
                                        LL_ICTL_I2C1_TXO     | \
                                        LL_ICTL_I2C1_RXDONE  | \
                                        LL_ICTL_I2C1_RXU     | \
                                        LL_ICTL_I2C1_RXO     )

#define LL_ICTL_SPI1_MST               (LL_ICTL_IRQ_13)                        /*!< SPI 1 MST            */
#define LL_ICTL_SPI1_RXU               (LL_ICTL_IRQ_14)                        /*!< SPI 1 Rx Under       */
#define LL_ICTL_SPI1_RXO               (LL_ICTL_IRQ_15)                        /*!< SPI 1 Rx Over        */
#define LL_ICTL_SPI1_RXF               (LL_ICTL_IRQ_16)                        /*!< SPI 1 Rx Full        */
#define LL_ICTL_SPI1_TXO               (LL_ICTL_IRQ_17)                        /*!< SPI 1 Tx Over        */
#define LL_ICTL_SPI1_TXE               (LL_ICTL_IRQ_18)                        /*!< SPI 1 Tx Empty       */

#define LL_ICTL_IRQCFG_SPI1_MASK       (LL_ICTL_SPI1_MST | \
                                        LL_ICTL_SPI1_RXU | \
                                        LL_ICTL_SPI1_RXO | \
                                        LL_ICTL_SPI1_RXF | \
                                        LL_ICTL_SPI1_TXO | \
                                        LL_ICTL_SPI1_TXE )


#define LL_ICTL_SPI2_MST               (LL_ICTL_IRQ_19)                        /*!< SPI 2 MST            */
#define LL_ICTL_SPI2_RXU               (LL_ICTL_IRQ_20)                        /*!< SPI 2 Rx Under       */
#define LL_ICTL_SPI2_RXO               (LL_ICTL_IRQ_21)                        /*!< SPI 2 Rx Over        */
#define LL_ICTL_SPI2_RXF               (LL_ICTL_IRQ_22)                        /*!< SPI 2 Rx Full        */
#define LL_ICTL_SPI2_TXO               (LL_ICTL_IRQ_23)                        /*!< SPI 2 Tx Over        */
#define LL_ICTL_SPI2_TXE               (LL_ICTL_IRQ_24)                        /*!< SPI 2 Tx Empty       */

#define LL_ICTL_IRQCFG_SPI2_MASK       (LL_ICTL_SPI2_MST | \
                                        LL_ICTL_SPI2_RXU | \
                                        LL_ICTL_SPI2_RXO | \
                                        LL_ICTL_SPI2_RXF | \
                                        LL_ICTL_SPI2_TXO | \
                                        LL_ICTL_SPI2_TXE )

#if ((defined(XT32H0xxAMPW)) || (defined(XT32H0xxBMPW)))
#define LL_ICTL_ADC_EOS                (LL_ICTL_IRQ_26)                        /*!< ADC EOS              */

#define LL_ICTL_IRQCFG_ADC_EOS_MASK    (LL_ICTL_ADC_EOS)
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */

#define LL_ICTL_UART1_AUTODET          (LL_ICTL_IRQ_28)                        /*!< UART1 auto baudrate detect */
#define LL_ICTL_UART2_AUTODET          (LL_ICTL_IRQ_29)                        /*!< UART2 auto baudrate detect */
#define LL_ICTL_UART3_AUTODET          (LL_ICTL_IRQ_30)                        /*!< UART3 auto baudrate detect */
#define LL_ICTL_UART4_AUTODET          (LL_ICTL_IRQ_31)                        /*!< UART4 auto baudrate detect */

#define LL_ICTL_IRQCFG_UART_AUTODET_MASK   (LL_ICTL_UART1_AUTODET | \
                                            LL_ICTL_UART2_AUTODET | \
                                            LL_ICTL_UART3_AUTODET | \
                                            LL_ICTL_UART4_AUTODET )

#define LL_ICTL_I2C2_GCALL             (LL_ICTL_IRQ_33)                        /*!< I2C 2 General Call   */
#define LL_ICTL_I2C2_RXF               (LL_ICTL_IRQ_34)                        /*!< I2C 2 Rx Full        */
#define LL_ICTL_I2C2_RDQ               (LL_ICTL_IRQ_35)                        /*!< I2C 2 RD Req         */
#define LL_ICTL_I2C2_STRTD             (LL_ICTL_IRQ_36)                        /*!< I2C 2 Start Detect   */
#define LL_ICTL_I2C2_RESTRTD           (LL_ICTL_IRQ_37)                        /*!< I2C 2 Restart Detect */
#define LL_ICTL_I2C2_STOPD             (LL_ICTL_IRQ_38)                        /*!< I2C 2 Stop Detect    */
#define LL_ICTL_I2C2_ACT               (LL_ICTL_IRQ_39)                        /*!< I2C 2 Activity       */
#define LL_ICTL_I2C2_TXE               (LL_ICTL_IRQ_40)                        /*!< I2C 2 Tx Empty       */
#define LL_ICTL_I2C2_TXABRT            (LL_ICTL_IRQ_41)                        /*!< I2C 2 Tx Abort       */
#define LL_ICTL_I2C2_TXO               (LL_ICTL_IRQ_42)                        /*!< I2C 2 Tx Over        */
#define LL_ICTL_I2C2_RXDONE            (LL_ICTL_IRQ_43)                        /*!< I2C 2 Rx Done        */
#define LL_ICTL_I2C2_RXU               (LL_ICTL_IRQ_44)                        /*!< I2C 2 Rx Underflow   */
#define LL_ICTL_I2C2_RXO               (LL_ICTL_IRQ_45)                        /*!< I2C 2 Rx Over        */

#define LL_ICTL_IRQCFG_I2C2_MASK       (LL_ICTL_I2C2_GCALL   | \
                                        LL_ICTL_I2C2_RXF     | \
                                        LL_ICTL_I2C2_RDQ     | \
                                        LL_ICTL_I2C2_STRTD   | \
                                        LL_ICTL_I2C2_RESTRTD | \
                                        LL_ICTL_I2C2_STOPD   | \
                                        LL_ICTL_I2C2_ACT     | \
                                        LL_ICTL_I2C2_TXE     | \
                                        LL_ICTL_I2C2_TXABRT  | \
                                        LL_ICTL_I2C2_TXO     | \
                                        LL_ICTL_I2C2_RXDONE  | \
                                        LL_ICTL_I2C2_RXU     | \
                                        LL_ICTL_I2C2_RXO     )

#if (defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW)) 
#define LL_ICTL_OCOMP_1                (LL_ICTL_IRQ_52)
#define LL_ICTL_OCOMP_2                (LL_ICTL_IRQ_53)
#define LL_ICTL_OCOMP_3                (LL_ICTL_IRQ_54)
#define LL_ICTL_OCOMP_4                (LL_ICTL_IRQ_55)
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */

#if (defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW)) 
#define LL_ICTL_IRQCFG_OCOMP_MASK      (LL_ICTL_OCOMP_1 | \
                                        LL_ICTL_OCOMP_2 | \
                                        LL_ICTL_OCOMP_3 | \
                                        LL_ICTL_OCOMP_4 )
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */                                       

#define LL_ICTL_LED_PRD                (LL_ICTL_IRQ_56)                        /*!< LED PRD              */
#define LL_ICTL_LED_COM                (LL_ICTL_IRQ_57)                        /*!< LED COM              */
#define LL_ICTL_LED_FRM                (LL_ICTL_IRQ_58)                        /*!< LED FRM              */
#define LL_ICTL_LED_UDT                (LL_ICTL_IRQ_59)                        /*!< LED UDT              */

#define LL_ICTL_IRQCFG_LED_MASK        (LL_ICTL_LED_PRD | \
                                        LL_ICTL_LED_COM | \
                                        LL_ICTL_LED_FRM | \
                                        LL_ICTL_LED_UDT )

#define LL_ICTL_AFC_NORM               (LL_ICTL_IRQ_60)                        /*!< AFC Normal           */
#define LL_ICTL_AFC_LOOP               (LL_ICTL_IRQ_61)                        /*!< AFC Loop             */
#define LL_ICTL_AFC_ERR                (LL_ICTL_IRQ_62)                        /*!< AFC Error            */

#define LL_ICTL_IRQCFG_AFC_MASK        (LL_ICTL_AFC_NORM | \
                                        LL_ICTL_AFC_LOOP | \
                                        LL_ICTL_AFC_ERR  )

#define LL_ICTL_CTSU2HOST              (LL_ICTL_IRQ_63)                        /*!< CTSU to Host         */

#define LL_ICTL_IRQCFG_CTSU_MASK       (LL_ICTL_CTSU2HOST)

/* Congiure 1 */  
#define LL_ICTL_GPIO_0                 (LL_ICTL_IRQ_32)                        /*!< GPIO 0               */
#define LL_ICTL_GPIO_1                 (LL_ICTL_IRQ_33)                        /*!< GPIO 1               */
#define LL_ICTL_GPIO_2                 (LL_ICTL_IRQ_34)                        /*!< GPIO 2               */
#define LL_ICTL_GPIO_3                 (LL_ICTL_IRQ_35)                        /*!< GPIO 3               */
#define LL_ICTL_GPIO_4                 (LL_ICTL_IRQ_36)                        /*!< GPIO 4               */
#define LL_ICTL_GPIO_5                 (LL_ICTL_IRQ_37)                        /*!< GPIO 5               */
#define LL_ICTL_GPIO_6                 (LL_ICTL_IRQ_38)                        /*!< GPIO 6               */
#define LL_ICTL_GPIO_7                 (LL_ICTL_IRQ_39)                        /*!< GPIO 7               */
#define LL_ICTL_GPIO_8                 (LL_ICTL_IRQ_40)                        /*!< GPIO 8               */
#define LL_ICTL_GPIO_9                 (LL_ICTL_IRQ_41)                        /*!< GPIO 9               */
#define LL_ICTL_GPIO_10                (LL_ICTL_IRQ_42)                        /*!< GPIO 10              */
#define LL_ICTL_GPIO_11                (LL_ICTL_IRQ_43)                        /*!< GPIO 11              */
#define LL_ICTL_GPIO_12                (LL_ICTL_IRQ_44)                        /*!< GPIO 12              */
#define LL_ICTL_GPIO_13                (LL_ICTL_IRQ_45)                        /*!< GPIO 13              */
#define LL_ICTL_GPIO_14                (LL_ICTL_IRQ_46)                        /*!< GPIO 14              */
#define LL_ICTL_GPIO_15                (LL_ICTL_IRQ_47)                        /*!< GPIO 15              */
#define LL_ICTL_GPIO_16                (LL_ICTL_IRQ_48)                        /*!< GPIO 16              */
#define LL_ICTL_GPIO_17                (LL_ICTL_IRQ_49)                        /*!< GPIO 17              */
#define LL_ICTL_GPIO_18                (LL_ICTL_IRQ_50)                        /*!< GPIO 18              */
#define LL_ICTL_GPIO_19                (LL_ICTL_IRQ_51)                        /*!< GPIO 19              */
#define LL_ICTL_GPIO_20                (LL_ICTL_IRQ_52)                        /*!< GPIO 20              */
#define LL_ICTL_GPIO_21                (LL_ICTL_IRQ_53)                        /*!< GPIO 21              */
#define LL_ICTL_GPIO_22                (LL_ICTL_IRQ_54)                        /*!< GPIO 22              */
#define LL_ICTL_GPIO_23                (LL_ICTL_IRQ_55)                        /*!< GPIO 23              */
#define LL_ICTL_GPIO_24                (LL_ICTL_IRQ_56)                        /*!< GPIO 24              */
#define LL_ICTL_GPIO_25                (LL_ICTL_IRQ_57)                        /*!< GPIO 25              */
#define LL_ICTL_GPIO_26                (LL_ICTL_IRQ_58)                        /*!< GPIO 26              */
#define LL_ICTL_GPIO_27                (LL_ICTL_IRQ_59)                        /*!< GPIO 27              */
#define LL_ICTL_GPIO_28                (LL_ICTL_IRQ_60)                        /*!< GPIO 28              */
#define LL_ICTL_GPIO_29                (LL_ICTL_IRQ_61)                        /*!< GPIO 29              */
#define LL_ICTL_GPIO_30                (LL_ICTL_IRQ_62)                        /*!< GPIO 30              */
#define LL_ICTL_GPIO_31                (LL_ICTL_IRQ_63)                        /*!< GPIO 31              */

/**
  * @}
  */

/** @defgroup ICTL_LL_EC_IRQ_MAPPING IRQ MAPPING
  * @{
  */
/* Congiure 0 */  
#define LL_ICTL_SYSCFG_I2C1_GCALL      (LL_IRQ_CFG_1)                          /*!< I2C 1 General Call   */
#define LL_ICTL_SYSCFG_I2C1_RXF        (LL_IRQ_CFG_1)                          /*!< I2C 1 Rx Full        */
#define LL_ICTL_SYSCFG_I2C1_RDQ        (LL_IRQ_CFG_1)                          /*!< I2C 1 RD Req         */
#define LL_ICTL_SYSCFG_I2C1_STRTD      (LL_IRQ_CFG_1)                          /*!< I2C 1 Start Detect   */
#define LL_ICTL_SYSCFG_I2C1_RESTRTD    (LL_IRQ_CFG_1)                          /*!< I2C 1 Restart Detect */
#define LL_ICTL_SYSCFG_I2C1_STOPD      (LL_IRQ_CFG_1)                          /*!< I2C 1 Stop Detect    */
#define LL_ICTL_SYSCFG_I2C1_ACT        (LL_IRQ_CFG_1)                          /*!< I2C 1 Activity       */
#define LL_ICTL_SYSCFG_I2C1_TXE        (LL_IRQ_CFG_1)                          /*!< I2C 1 Tx Empty       */
#define LL_ICTL_SYSCFG_I2C1_TXABRT     (LL_IRQ_CFG_1)                          /*!< I2C 1 Tx Abort       */
#define LL_ICTL_SYSCFG_I2C1_TXO        (LL_IRQ_CFG_1)                          /*!< I2C 1 Tx Over        */
#define LL_ICTL_SYSCFG_I2C1_RXDONE     (LL_IRQ_CFG_1)                          /*!< I2C 1 Rx Done        */
#define LL_ICTL_SYSCFG_I2C1_RXU        (LL_IRQ_CFG_1)                          /*!< I2C 1 Rx Underflow   */
#define LL_ICTL_SYSCFG_I2C1_RXO        (LL_IRQ_CFG_1)                          /*!< I2C 1 Rx Over        */

#define LL_ICTL_SYSCFG_SPI1_MST        (LL_IRQ_CFG_1)                          /*!< SPI 1 MST            */
#define LL_ICTL_SYSCFG_SPI1_RXU        (LL_IRQ_CFG_1)                          /*!< SPI 1 Rx Under       */
#define LL_ICTL_SYSCFG_SPI1_RXO        (LL_IRQ_CFG_1)                          /*!< SPI 1 Rx Over        */
#define LL_ICTL_SYSCFG_SPI1_RXF        (LL_IRQ_CFG_1)                          /*!< SPI 1 Rx Full        */
#define LL_ICTL_SYSCFG_SPI1_TXO        (LL_IRQ_CFG_1)                          /*!< SPI 1 Tx Over        */
#define LL_ICTL_SYSCFG_SPI1_TXE        (LL_IRQ_CFG_1)                          /*!< SPI 1 Tx Empty       */

#define LL_ICTL_SYSCFG_SPI2_MST        (LL_IRQ_CFG_1)                          /*!< SPI 2 MST            */
#define LL_ICTL_SYSCFG_SPI2_RXU        (LL_IRQ_CFG_1)                          /*!< SPI 2 Rx Under       */
#define LL_ICTL_SYSCFG_SPI2_RXO        (LL_IRQ_CFG_1)                          /*!< SPI 2 Rx Over        */
#define LL_ICTL_SYSCFG_SPI2_RXF        (LL_IRQ_CFG_1)                          /*!< SPI 2 Rx Full        */
#define LL_ICTL_SYSCFG_SPI2_TXO        (LL_IRQ_CFG_1)                          /*!< SPI 2 Tx Over        */
#define LL_ICTL_SYSCFG_SPI2_TXE        (LL_IRQ_CFG_1)                          /*!< SPI 2 Tx Empty       */

#if ((defined(XT32H0xxAMPW)) || (defined(XT32H0xxBMPW)))
#define LL_ICTL_SYSCFG_ADC_EOS         (LL_IRQ_CFG_1)                          /*!< ADC EOS              */
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */

#define LL_ICTL_SYSCFG_I2C2_GCALL      (LL_IRQ_CFG_1)                          /*!< I2C 2 General Call   */
#define LL_ICTL_SYSCFG_I2C2_RXF        (LL_IRQ_CFG_1)                          /*!< I2C 2 Rx Full        */
#define LL_ICTL_SYSCFG_I2C2_RDQ        (LL_IRQ_CFG_1)                          /*!< I2C 2 RD Req         */
#define LL_ICTL_SYSCFG_I2C2_STRTD      (LL_IRQ_CFG_1)                          /*!< I2C 2 Start Detect   */
#define LL_ICTL_SYSCFG_I2C2_RESTRTD    (LL_IRQ_CFG_1)                          /*!< I2C 2 Restart Detect */
#define LL_ICTL_SYSCFG_I2C2_STOPD      (LL_IRQ_CFG_1)                          /*!< I2C 2 Stop Detect    */
#define LL_ICTL_SYSCFG_I2C2_ACT        (LL_IRQ_CFG_1)                          /*!< I2C 2 Activity       */
#define LL_ICTL_SYSCFG_I2C2_TXE        (LL_IRQ_CFG_1)                          /*!< I2C 2 Tx Empty       */
#define LL_ICTL_SYSCFG_I2C2_TXABRT     (LL_IRQ_CFG_1)                          /*!< I2C 2 Tx Abort       */
#define LL_ICTL_SYSCFG_I2C2_TXO        (LL_IRQ_CFG_1)                          /*!< I2C 2 Tx Over        */
#define LL_ICTL_SYSCFG_I2C2_RXDONE     (LL_IRQ_CFG_1)                          /*!< I2C 2 Rx Done        */
#define LL_ICTL_SYSCFG_I2C2_RXU        (LL_IRQ_CFG_1)                          /*!< I2C 2 Rx Underflow   */
#define LL_ICTL_SYSCFG_I2C2_RXO        (LL_IRQ_CFG_1)                          /*!< I2C 2 Rx Over        */

#define LL_ICTL_SYSCFG_UART1_AUTODET   (LL_IRQ_CFG_1)                          /*!< UART1 autbaudrate detect */
#define LL_ICTL_SYSCFG_UART2_AUTODET   (LL_IRQ_CFG_1)                          /*!< UART2 autbaudrate detect */
#define LL_ICTL_SYSCFG_UART3_AUTODET   (LL_IRQ_CFG_1)                          /*!< UART3 autbaudrate detect */
#define LL_ICTL_SYSCFG_UART4_AUTODET   (LL_IRQ_CFG_1)                          /*!< UART4 autbaudrate detect */

#if (defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW))
#define LL_ICTL_SYSCFG_OCOMP_1         (LL_IRQ_CFG_1)                          /*!< COMP output 1        */
#define LL_ICTL_SYSCFG_OCOMP_2         (LL_IRQ_CFG_1)                          /*!< COMP output 2        */
#define LL_ICTL_SYSCFG_OCOMP_3         (LL_IRQ_CFG_1)                          /*!< COMP output 3        */
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */
#define LL_ICTL_SYSCFG_OCOMP_4         (LL_IRQ_CFG_1)                          /*!< COMP output 4        */

#define LL_ICTL_SYSCFG_LED_PRD         (LL_IRQ_CFG_1)                          /*!< LED PRD              */
#define LL_ICTL_SYSCFG_LED_COM         (LL_IRQ_CFG_1)                          /*!< LED COM              */
#define LL_ICTL_SYSCFG_LED_FRM         (LL_IRQ_CFG_1)                          /*!< LED FRM              */
#define LL_ICTL_SYSCFG_LED_UDT         (LL_IRQ_CFG_1)                          /*!< LED UDT              */

#define LL_ICTL_SYSCFG_AFC_NORM        (LL_IRQ_CFG_1)                          /*!< AFC normal           */
#define LL_ICTL_SYSCFG_AFC_LOOP        (LL_IRQ_CFG_1)                          /*!< AFC loop             */
#define LL_ICTL_SYSCFG_AFC_ERR         (LL_IRQ_CFG_1)                          /*!< AFC error            */

#define LL_ICTL_SYSCFG_CTSU2HOST       (LL_IRQ_CFG_1)                          /*!< CTSU to Host         */

/* Congiure 1 */  
#define LL_ICTL_SYSCFG_GPIO_0          (LL_IRQ_CFG_2)                          /*!< GPIO 0               */
#define LL_ICTL_SYSCFG_GPIO_1          (LL_IRQ_CFG_2)                          /*!< GPIO 1               */
#define LL_ICTL_SYSCFG_GPIO_2          (LL_IRQ_CFG_2)                          /*!< GPIO 2               */
#define LL_ICTL_SYSCFG_GPIO_3          (LL_IRQ_CFG_2)                          /*!< GPIO 3               */
#define LL_ICTL_SYSCFG_GPIO_4          (LL_IRQ_CFG_2)                          /*!< GPIO 4               */
#define LL_ICTL_SYSCFG_GPIO_5          (LL_IRQ_CFG_2)                          /*!< GPIO 5               */
#define LL_ICTL_SYSCFG_GPIO_6          (LL_IRQ_CFG_2)                          /*!< GPIO 6               */
#define LL_ICTL_SYSCFG_GPIO_7          (LL_IRQ_CFG_2)                          /*!< GPIO 7               */
#define LL_ICTL_SYSCFG_GPIO_8          (LL_IRQ_CFG_2)                          /*!< GPIO 8               */
#define LL_ICTL_SYSCFG_GPIO_9          (LL_IRQ_CFG_2)                          /*!< GPIO 9               */
#define LL_ICTL_SYSCFG_GPIO_10         (LL_IRQ_CFG_2)                          /*!< GPIO 10              */
#define LL_ICTL_SYSCFG_GPIO_11         (LL_IRQ_CFG_2)                          /*!< GPIO 11              */
#define LL_ICTL_SYSCFG_GPIO_12         (LL_IRQ_CFG_2)                          /*!< GPIO 12              */
#define LL_ICTL_SYSCFG_GPIO_13         (LL_IRQ_CFG_2)                          /*!< GPIO 13              */
#define LL_ICTL_SYSCFG_GPIO_14         (LL_IRQ_CFG_2)                          /*!< GPIO 14              */
#define LL_ICTL_SYSCFG_GPIO_15         (LL_IRQ_CFG_2)                          /*!< GPIO 15              */
#define LL_ICTL_SYSCFG_GPIO_16         (LL_IRQ_CFG_2)                          /*!< GPIO 16              */
#define LL_ICTL_SYSCFG_GPIO_17         (LL_IRQ_CFG_2)                          /*!< GPIO 17              */
#define LL_ICTL_SYSCFG_GPIO_18         (LL_IRQ_CFG_2)                          /*!< GPIO 18              */
#define LL_ICTL_SYSCFG_GPIO_19         (LL_IRQ_CFG_2)                          /*!< GPIO 19              */
#define LL_ICTL_SYSCFG_GPIO_20         (LL_IRQ_CFG_2)                          /*!< GPIO 20              */
#define LL_ICTL_SYSCFG_GPIO_21         (LL_IRQ_CFG_2)                          /*!< GPIO 21              */
#define LL_ICTL_SYSCFG_GPIO_22         (LL_IRQ_CFG_2)                          /*!< GPIO 22              */
#define LL_ICTL_SYSCFG_GPIO_23         (LL_IRQ_CFG_2)                          /*!< GPIO 23              */
#define LL_ICTL_SYSCFG_GPIO_24         (LL_IRQ_CFG_2)                          /*!< GPIO 24              */
#define LL_ICTL_SYSCFG_GPIO_25         (LL_IRQ_CFG_2)                          /*!< GPIO 25              */
#define LL_ICTL_SYSCFG_GPIO_26         (LL_IRQ_CFG_2)                          /*!< GPIO 26              */
#define LL_ICTL_SYSCFG_GPIO_27         (LL_IRQ_CFG_2)                          /*!< GPIO 27              */
#define LL_ICTL_SYSCFG_GPIO_28         (LL_IRQ_CFG_2)                          /*!< GPIO 28              */
#define LL_ICTL_SYSCFG_GPIO_29         (LL_IRQ_CFG_2)                          /*!< GPIO 29              */
#define LL_ICTL_SYSCFG_GPIO_30         (LL_IRQ_CFG_2)                          /*!< GPIO 30              */
#define LL_ICTL_SYSCFG_GPIO_31         (LL_IRQ_CFG_2)                          /*!< GPIO 31              */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup ICTL_LL_Exported_Macros ICTL Exported Macros
  * @{
  */

/** @defgroup ICTL_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in ICTL register
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_ICTL_WriteReg(__REG__, __VALUE__) WRITE_REG(ICTL->__REG__, (__VALUE__))

/**
  * @brief  Read a value in ICTL register
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_ICTL_ReadReg(__REG__) READ_REG(ICTL->__REG__)
/**
  * @}
  */


/**
  * @}
  */



/* Exported functions --------------------------------------------------------*/
/** @defgroup ICTL_LL_Exported_Functions ICTL Exported Functions
 * @{
 */
/** @defgroup ICTL_LL_Exported_Functions_Group1 IT_Management
  * @{
  */

/**
  * @brief  Enable Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTEN_L         IRQx           LL_ICTL_EnableIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_EnableIRQ_0_31(uint32_t Irq)
{
  SET_BIT(ICTL->IRQINTENL, Irq);
}

/**
  * @brief  Enable Interrupt request for Lines in range 32 to 63
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTEN_H         IRQx           LL_ICTL_EnableIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_EnableIRQ_32_63(uint32_t Irq)
{
  SET_BIT(ICTL->IRQINTENH, Irq);
}

/**
  * @brief  Disable Irq Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTEN_L         IRQx           LL_ICTL_DisableIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_DisableIRQ_0_31(uint32_t Irq)
{
  CLEAR_BIT(ICTL->IRQINTENL, Irq);
}

/**
  * @brief  Disable Irq Interrupt request for Lines in range 32 to 63
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTEN_H         IRQx           LL_ICTL_DisableIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_DisableIRQ_32_63(uint32_t Irq)
{
  CLEAR_BIT(ICTL->IRQINTENH, Irq);
}

/**
  * @brief  Indicate if ExtiLine Interrupt request is enabled for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTEN_L         IRQx           LL_ICTL_IsEnabledIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ICTL_IsEnabledIRQ_0_31(uint32_t Irq)
{
  return ((READ_BIT(ICTL->IRQINTENL, Irq) == (Irq)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate if ExtiLine Interrupt request is enabled for Lines in range 32 to 63
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  * @rmtoll IRQ_INTEN_H         IRQx           LL_ICTL_IsEnabledIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ICTL_IsEnabledIRQ_32_63(uint32_t Irq)
{
  return ((READ_BIT(ICTL->IRQINTENH, Irq) == (Irq)) ? 1UL : 0UL);
}

/**
  * @brief  Mask Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTMASK_L         IRQx           LL_ICTL_MaskIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_MaskIRQ_0_31(uint32_t Irq)
{
  SET_BIT(ICTL->IRQINTMASKL, Irq);
}

/**
  * @brief  Mask Interrupt request for Lines in range 32 to 63
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTMASKN_H         IRQx           LL_ICTL_MaskIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_MaskIRQ_32_63(uint32_t Irq)
{
  SET_BIT(ICTL->IRQINTMASKH, Irq);
}

/**
  * @brief  Unmask Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTMASK_L         IRQx           LL_ICTL_UnmaskIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_UnmaskIRQ_0_31(uint32_t Irq)
{
  CLEAR_BIT(ICTL->IRQINTMASKL, Irq);
}

/**
  * @brief  Unmask Interrupt request for Lines in range 32 to 63
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTMASKN_H         IRQx           LL_ICTL_UnmaskIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_UnmaskIRQ_32_63(uint32_t Irq)
{
  CLEAR_BIT(ICTL->IRQINTMASKH, Irq);
}

/**
  * @brief  Check Interrupt request for Lines in range 0 to 31 is masked
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTMASK_L         IRQx           LL_ICTL_IsMaskedIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_IsMaskedIRQ_0_31(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQINTMASKL, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Check Interrupt request for Lines in range 32 to 63 is masked
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTMASKN_H         IRQx           LL_ICTL_IsMaskedIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_ICTL_IsMaskedIRQ_32_63(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQINTMASKH, Irq) == Irq) ? 1UL : 0UL);
}


/**
  * @brief  Software trigger Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTFORCE_L         IRQx           LL_ICTL_SoftwareTriggerIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_SoftwareTriggerIRQ_0_31(uint32_t Irq)
{
  SET_BIT(ICTL->IRQINTFORCEL, Irq);
}

/**
  * @brief  Software trigger Interrupt request for Lines in range 32 to 63
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTFORCE_H         IRQx           LL_ICTL_SoftwareTriggerIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_SoftwareTriggerIRQ_32_63(uint32_t Irq)
{
  SET_BIT(ICTL->IRQINTFORCEH, Irq);
}

/**
  * @brief  Clear Software Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTFORCE_L         IRQx           LL_ICTL_ClearSoftwareIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_ClearSoftwareIRQ_0_31(uint32_t Irq)
{
  CLEAR_BIT(ICTL->IRQINTFORCEL, Irq);
}

/**
  * @brief  Clear software Interrupt request for Lines in range 32 to 63
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTFORCE_H         IRQx           LL_ICTL_ClearSoftwareIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_ClearSoftwareIRQ_32_63(uint32_t Irq)
{
  CLEAR_BIT(ICTL->IRQINTFORCEH, Irq);
}

/**
  * @brief  Check Software Interrupt request for Lines in range 0 to 31 is actived
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTFORCE_L         IRQx           LL_ICTL_IsActivedSoftwareIRQ_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_IsActivedSoftwareIRQ_0_31(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQINTFORCEL, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Check Software Interrupt request for Lines in range 32 to 63 is actived
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_INTFORCE_H         IRQx           LL_ICTL_IsActivedSoftwareIRQ_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_ICTL_IsActivedSoftwareIRQ_32_63(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQINTFORCEH, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Get Interrupt hardware request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_RAWSTATUS_L         IRQx           LL_ICTL_GetIRQSource_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetIRQSource_0_31(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQRAWSTATUSL, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Get hardware Interrupt request for Lines in range 32 to 63 
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_RAWSTATUS_H         IRQx           LL_ICTL_GetIRQSource_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetIRQSource_32_63(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQRAWSTATUSH, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Get enabled Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_STATUS_L         IRQx           LL_ICTL_GetEnabledIRQStatus_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetEnabledIRQStatus_0_31(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQSTATUSL, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Get enabled Interrupt request for Lines in range 32 to 63 
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_STATUS_H         IRQx           LL_ICTL_GetEnabledIRQStatus_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetEnabledIRQStatus_32_63(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQSTATUSH, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Get masked Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_MASKSTATUS_L         IRQx           LL_ICTL_GetMaskedIRQStatus_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetMaskedIRQStatus_0_31(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQMASKSTATUSL, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Get masked Interrupt request for Lines in range 32 to 63 
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_MASKSTATUS_H         IRQx           LL_ICTL_GetMaskedIRQStatus_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetMaskedIRQStatus_32_63(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQMASKSTATUSH, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Get final Interrupt request for Lines in range 0 to 31
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_FINALSTATUS_L         IRQx           LL_ICTL_GetFinalIRQStatus_0_31
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_0
  *         @arg @ref LL_ICTL_IRQ_1
  *         @arg @ref LL_ICTL_IRQ_2
  *         @arg @ref LL_ICTL_IRQ_3
  *         @arg @ref LL_ICTL_IRQ_4
  *         @arg @ref LL_ICTL_IRQ_5
  *         @arg @ref LL_ICTL_IRQ_6
  *         @arg @ref LL_ICTL_IRQ_7
  *         @arg @ref LL_ICTL_IRQ_8
  *         @arg @ref LL_ICTL_IRQ_9
  *         @arg @ref LL_ICTL_IRQ_10
  *         @arg @ref LL_ICTL_IRQ_11
  *         @arg @ref LL_ICTL_IRQ_12
  *         @arg @ref LL_ICTL_IRQ_13
  *         @arg @ref LL_ICTL_IRQ_14
  *         @arg @ref LL_ICTL_IRQ_15
  *         @arg @ref LL_ICTL_IRQ_16
  *         @arg @ref LL_ICTL_IRQ_17
  *         @arg @ref LL_ICTL_IRQ_18
  *         @arg @ref LL_ICTL_IRQ_19
  *         @arg @ref LL_ICTL_IRQ_21
  *         @arg @ref LL_ICTL_IRQ_23
  *         @arg @ref LL_ICTL_IRQ_25
  *         @arg @ref LL_ICTL_IRQ_26
  *         @arg @ref LL_ICTL_IRQ_27
  *         @arg @ref LL_ICTL_IRQ_28
  *         @arg @ref LL_ICTL_IRQ_29
  *         @arg @ref LL_ICTL_IRQ_30
  *         @arg @ref LL_ICTL_IRQ_31
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetFinalIRQStatus_0_31(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQFINALSTATUSL, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Get final Interrupt request for Lines in range 32 to 63 
  * @note The reset value for the direct lines (lines 32 & 33)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll IRQ_FINALSTATUS_H         IRQx           LL_ICTL_GetFinalIRQStatus_32_63
  * @param  Irq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_IRQ_32
  *         @arg @ref LL_ICTL_IRQ_33
  *         @arg @ref LL_ICTL_IRQ_34
  *         @arg @ref LL_ICTL_IRQ_35
  *         @arg @ref LL_ICTL_IRQ_36
  *         @arg @ref LL_ICTL_IRQ_37
  *         @arg @ref LL_ICTL_IRQ_38
  *         @arg @ref LL_ICTL_IRQ_39
  *         @arg @ref LL_ICTL_IRQ_40
  *         @arg @ref LL_ICTL_IRQ_41
  *         @arg @ref LL_ICTL_IRQ_42
  *         @arg @ref LL_ICTL_IRQ_43
  *         @arg @ref LL_ICTL_IRQ_44
  *         @arg @ref LL_ICTL_IRQ_45
  *         @arg @ref LL_ICTL_IRQ_46
  *         @arg @ref LL_ICTL_IRQ_47
  *         @arg @ref LL_ICTL_IRQ_48
  *         @arg @ref LL_ICTL_IRQ_49
  *         @arg @ref LL_ICTL_IRQ_50
  *         @arg @ref LL_ICTL_IRQ_51
  *         @arg @ref LL_ICTL_IRQ_52
  *         @arg @ref LL_ICTL_IRQ_53
  *         @arg @ref LL_ICTL_IRQ_54
  *         @arg @ref LL_ICTL_IRQ_55
  *         @arg @ref LL_ICTL_IRQ_56
  *         @arg @ref LL_ICTL_IRQ_57
  *         @arg @ref LL_ICTL_IRQ_58
  *         @arg @ref LL_ICTL_IRQ_59
  *         @arg @ref LL_ICTL_IRQ_60
  *         @arg @ref LL_ICTL_IRQ_61
  *         @arg @ref LL_ICTL_IRQ_62
  *         @arg @ref LL_ICTL_IRQ_63
  *         @arg @ref LL_ICTL_IRQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetFinalIRQStatus_32_63(uint32_t Irq)
{
  return (uint32_t)((READ_BIT(ICTL->IRQFINALSTATUSH, Irq) == Irq) ? 1UL : 0UL);
}

/**
  * @brief  Enable Fast Interrupt request for Lines 
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTEN         FIQx           LL_ICTL_EnableFIQ
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_EnableFIQ(uint32_t Fiq)
{
  SET_BIT(ICTL->FIQINTEN, Fiq);
}

/**
  * @brief  Disable Fast Interrupt request for Lines 
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTEN         FIQx           LL_ICTL_DisableFIQ
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_DisableFIQ(uint32_t Fiq)
{
  CLEAR_BIT(ICTL->FIQINTEN, Fiq);
}

/**
  * @brief  Cleck Fast Interrupt request for Lines is enabled
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTEN         FIQx           LL_ICTL_IsEnabledFIQ
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_IsEnabledFIQ(uint32_t Fiq)
{
  return (uint32_t)((READ_BIT(ICTL->FIQINTEN, Fiq) == Fiq) ? 1UL : 0UL);
}

/**
  * @brief  Mask Fast Interrupt request for Lines 
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTMASK         FIQx           LL_ICTL_MaskFIQ
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_MaskFIQ(uint32_t Fiq)
{
  SET_BIT(ICTL->FIQINTMASK, Fiq);
}

/**
  * @brief  Unmask Fast Interrupt request for Lines 
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTMASK         FIQx           LL_ICTL_UnmaskFIQ
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_UnmaskFIQ(uint32_t Fiq)
{
  CLEAR_BIT(ICTL->FIQINTMASK, Fiq);
}

/**
  * @brief  Cleck Fast Interrupt request for Lines is enabled
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTMASK         FIQx           LL_ICTL_IsMaskedFIQ
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_IsMaskedFIQ(uint32_t Fiq)
{
  return (uint32_t)((READ_BIT(ICTL->FIQINTMASK, Fiq) == Fiq) ? 1UL : 0UL);
}

/**
  * @brief  Trigger software Fast Interrupt request for Lines 
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTFORCE         FIQx           LL_ICTL_SoftwareFIQTrigger
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_SoftwareFIQTrigger(uint32_t Fiq)
{
  SET_BIT(ICTL->FIQINTFORCE, Fiq);
}

/**
  * @brief  Clear software Fast Interrupt request for Lines trigger
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTFORCE         FIQx           LL_ICTL_ClearSoftwareFIQ
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  */
__STATIC_INLINE void LL_ICTL_ClearSoftwareFIQ(uint32_t Fiq)
{
  CLEAR_BIT(ICTL->FIQINTFORCE, Fiq);
}

/**
  * @brief  Cleck Fast Interrupt request for Lines is triggered
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_INTFORCE         FIQx           LL_ICTL_IsActivedSoftwareFIQ
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_IsActivedSoftwareFIQ(uint32_t Fiq)
{
  return (uint32_t)((READ_BIT(ICTL->FIQINTFORCE, Fiq) == Fiq) ? 1UL : 0UL);
}

/**
  * @brief  Get Fast Interrupt request for Lines hardware source
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_RAWSTATUS         FIQx           LL_ICTL_GetFIQSource
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetFIQSource(uint32_t Fiq)
{
  return (uint32_t)((READ_BIT(ICTL->FIQRAWSTATUS, Fiq) == Fiq) ? 1UL : 0UL);
}

/**
  * @brief  Get Fast Interrupt request for Lines status
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_STATUS         FIQx           LL_ICTL_GetEnabledFIQStatus
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetEnabledFIQStatus(uint32_t Fiq)
{
  return (uint32_t)((READ_BIT(ICTL->FIQSTATUS, Fiq) == Fiq) ? 1UL : 0UL);
}

/**
  * @brief  Get final Fast Interrupt request for Lines status
  * @note The reset value for the direct or internal lines (see RM)
  *       is set to 1 in order to enable the interrupt by default.
  *       Bits are set automatically at Power on.
  * @rmtoll FIQ_FINALSTATUS         FIQx           LL_ICTL_GetFinalFIQStatus
  * @param  Fiq This parameter can be one of the following values:
  *         @arg @ref LL_ICTL_FIQ_0
  *         @arg @ref LL_ICTL_FIQ_1
  *         @arg @ref LL_ICTL_FIQ_2
  *         @arg @ref LL_ICTL_FIQ_3
  *         @arg @ref LL_ICTL_FIQ_4
  *         @arg @ref LL_ICTL_FIQ_5
  *         @arg @ref LL_ICTL_FIQ_6
  *         @arg @ref LL_ICTL_FIQ_7
  *         @arg @ref LL_ICTL_FIQ_ALL
  * @note   Please check each device line mapping for ICTL Line availability
  * @retval Status (0 or 1)
  */
__STATIC_INLINE uint32_t LL_ICTL_GetFinalFIQStatus(uint32_t Fiq)
{
  return (uint32_t)((READ_BIT(ICTL->FIQFINALSTATUS, Fiq) == Fiq) ? 1UL : 0UL);
}
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ICTL_LL_Exported_Functions_Group2 Initialization and de-initialization functions
  * @{
  */

uint32_t LL_ICTL_Init(LL_ICTL_InitTypeDef *ICTL_InitStruct);
uint32_t LL_ICTL_DeInit(void);
void LL_ICTL_StructInit(LL_ICTL_InitTypeDef *ICTL_InitStruct);


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

#endif /* ICTL */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_ICTL_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
