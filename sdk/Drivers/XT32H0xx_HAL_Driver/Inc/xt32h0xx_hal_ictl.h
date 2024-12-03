/**
  ******************************************************************************
  * @file    xt32h0xx_hal_ictl.h
  * @author  Software Team
  * @brief   Header file of ICTL HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_ICTL_H
#define XT32H0xx_HAL_ICTL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup ICTL ICTL
  * @brief ICTL HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup ICTL_Exported_Types ICTL Exported Types
  * @{
  */

/**
  * @brief  ICTL Handle structure definition
  */
typedef struct
{
  uint32_t Line;                    /*!<  Line number */
  void (* ISRCallback)(void);       /*!<  ISR callback */
} ICTL_HandleTypeDef;

/**
  * @brief  ICTL Configuration structure definition
  */
typedef struct
{
  uint32_t Line;      /*!< The Ictl line to be configured. This parameter
                           can be a value of @ref ICTL_Line */
  uint32_t IsMasked;  /*!< The Ictl line to be masked. This parameter
                           can be a value of @ref ICTL_Mask */
} ICTL_ConfigTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup ICTL_Exported_Constants ICTL Exported Constants
  * @{
  */

/** @defgroup ICTL_Line  ICTL Line
  * @{
  */
//#define ICTL_I2C0_GCALL_IRQ                (ICTL_DIRECT   | ICTL_IRQ1 | 0x00u)     /*!< I2C0 General Call   */
//#define ICTL_I2C0_RXF                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x01u)     /*!< I2C0 Rx Full        */
//#define ICTL_I2C0_RDQ                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x02u)     /*!< I2C0 RD Req         */
//#define ICTL_I2C0_STRTD                    (ICTL_DIRECT   | ICTL_IRQ1 | 0x03u)     /*!< I2C0 Start Detect   */
//#define ICTL_I2C0_RESTRTD                  (ICTL_DIRECT   | ICTL_IRQ1 | 0x04u)     /*!< I2C0 Restart Detect */
//#define ICTL_I2C0_STOPD                    (ICTL_DIRECT   | ICTL_IRQ1 | 0x05u)     /*!< I2C0 Stop Detect    */
//#define ICTL_I2C0_ACT                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x06u)     /*!< I2C0 Activity       */
//#define ICTL_I2C0_TXE                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x07u)     /*!< I2C0 Tx Empty       */
//#define ICTL_I2C0_TXABRT                   (ICTL_DIRECT   | ICTL_IRQ1 | 0x08u)     /*!< I2C0 Tx Abort       */
//#define ICTL_I2C0_TXO                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x09u)     /*!< I2C0 Tx Over        */
//#define ICTL_I2C0_RXDONE                   (ICTL_DIRECT   | ICTL_IRQ1 | 0x0Au)     /*!< I2C0 Rx Done        */
//#define ICTL_I2C0_RXU                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x0Bu)     /*!< I2C0 Rx Under       */
//#define ICTL_I2C0_RXO                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x0Cu)     /*!< I2C0 Rx Over        */
//#define ICTL_SPI0_MST                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x0Du)     /*!< SPI0 MST            */
//#define ICTL_SPI0_RXU                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x0Eu)     /*!< SPI0 Rx Under       */
//#define ICTL_SPI0_RXO                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x0Fu)     /*!< SPI0 Rx Over        */
//#define ICTL_SPI0_RXF                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x10u)     /*!< SPI0 Rx Full        */
//#define ICTL_SPI0_TXO                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x11u)     /*!< SPI0 Tx Over        */
//#define ICTL_SPI0_TXE                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x12u)     /*!< SPI0 Tx Empty       */
//#define ICTL_SPI1_MST                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x13u)     /*!< SPI1 MST            */
//#define ICTL_SPI1_RXU                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x14u)     /*!< SPI1 Rx Under       */
//#define ICTL_SPI1_RXO                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x15u)     /*!< SPI1 Rx Over        */
//#define ICTL_SPI1_RXF                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x16u)     /*!< SPI1 Rx Full        */
//#define ICTL_SPI1_TXO                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x17u)     /*!< SPI1 Tx Over        */
//#define ICTL_SPI1_TXE                      (ICTL_DIRECT   | ICTL_IRQ1 | 0x18u)     /*!< SPI1 Tx Empty       */
//#define ICTL_IRQ_25                        (ICTL_DIRECT   | ICTL_IRQ1 | 0x19u)     /*!< No used             */
//#if ((defined(XT32H0xxAMPW)) || (defined(XT32H0xxBMPW)))
//#define ICTL_ADC_EOS                       (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Au)     /*!< ADC_EOS             */
//#else
//#define ICTL_IRQ_26                        (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Au)     /*!< No used             */
//#endif
//#define ICTL_IRQ_27                        (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Bu)     /*!< No used             */
//#define ICTL_UART1_AD                      (ICTL_CONFIG   | ICTL_IRQ1 | 0x1Cu)     /*!< UART1 auto detect   */
//#define ICTL_UART2_AD                      (ICTL_CONFIG   | ICTL_IRQ1 | 0x1Du)     /*!< UART2 auto detect   */
//#define ICTL_UART3_AD                      (ICTL_CONFIG   | ICTL_IRQ1 | 0x1Eu)     /*!< UART3 auto detect   */
//#define ICTL_UART4_AD                      (ICTL_CONFIG   | ICTL_IRQ1 | 0x1Fu)     /*!< UART4 auto detect   */

//#if defined(XT32H0xxB)
//#define ICTL_TIMB_11                       (ICTL_DIRECT   | ICTL_IRQ1 | 0x19u)     /*!< Basic Timer 11      */
//#define ICTL_TIMB_12                       (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Au)     /*!< Basic Timer 12      */
//#define ICTL_TIMB_13                       (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Bu)     /*!< Basic Timer 13      */
//#define ICTL_TIMB_14                       (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Cu)     /*!< Basic Timer 14      */
//#define ICTL_TIMB_21                       (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Du)     /*!< Basic Timer 21      */
//#define ICTL_TIMB_22                       (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Eu)     /*!< Basic Timer 22      */
//#define ICTL_TIMB_23                       (ICTL_DIRECT   | ICTL_IRQ1 | 0x1Fu)     /*!< Basic Timer 23      */
//#define ICTL_TIMB_24                       (ICTL_DIRECT   | ICTL_IRQ2 | 0x00u)     /*!< Basic Timer 24      */
//#endif /* XT32H0xxB */ 

//#define ICTL_IRQ_32                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x00u)     /*!< No Used             */
//#define ICTL_I2C1_GCALL_IRQ                (ICTL_DIRECT   | ICTL_IRQ2 | 0x01u)     /*!< I2C1 General Call   */
//#define ICTL_I2C1_RXF                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x02u)     /*!< I2C1 Rx Full        */
//#define ICTL_I2C1_RDQ                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x03u)     /*!< I2C1 RD Req         */
//#define ICTL_I2C1_STRTD                    (ICTL_DIRECT   | ICTL_IRQ2 | 0x04u)     /*!< I2C1 Start Detect   */
//#define ICTL_I2C1_RESTRTD                  (ICTL_DIRECT   | ICTL_IRQ2 | 0x05u)     /*!< I2C1 Restart Detect */
//#define ICTL_I2C1_STOPD                    (ICTL_DIRECT   | ICTL_IRQ2 | 0x06u)     /*!< I2C1 Stop Detect    */
//#define ICTL_I2C1_ACT                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x07u)     /*!< I2C1 Activity       */
//#define ICTL_I2C1_TXE                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x08u)     /*!< I2C1 Tx Empty       */
//#define ICTL_I2C1_TXABRT                   (ICTL_DIRECT   | ICTL_IRQ2 | 0x09u)     /*!< I2C1 Tx Abort       */
//#define ICTL_I2C1_TXO                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x0Au)     /*!< I2C1 Tx Over        */
//#define ICTL_I2C1_RXDONE                   (ICTL_DIRECT   | ICTL_IRQ2 | 0x0Bu)     /*!< I2C1 Rx Done        */
//#define ICTL_I2C1_RXU                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x0Cu)     /*!< I2C1 Rx Under       */
//#define ICTL_I2C1_RXO                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x0Du)     /*!< I2C1 Rx Over        */
//#define ICTL_IRQ_46                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x0Eu)     /*!< No used             */
//#define ICTL_IRQ_47                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x0Fu)     /*!< No used             */
//#if defined(XT32H0xxB)
//#define ICTL_IRQ_INJ_EOC                   (ICTL_DIRECT   | ICTL_IRQ2 | 0x10u)     /*!< No used             */
//#define ICTL_IRQ_INJ_EOS                   (ICTL_DIRECT   | ICTL_IRQ2 | 0x11u)     /*!< No used             */
//#define ICTL_IRQ_REG_EOC                   (ICTL_DIRECT   | ICTL_IRQ2 | 0x12u)     /*!< No used             */
//#define ICTL_IRQ_REG_EOS                   (ICTL_DIRECT   | ICTL_IRQ2 | 0x13u)     /*!< No used             */
//#define ICTL_IRQ_INJ_AWD                   (ICTL_DIRECT   | ICTL_IRQ2 | 0x14u)     /*!< No used             */
//#define ICTL_IRQ_REG_AWD                   (ICTL_DIRECT   | ICTL_IRQ2 | 0x15u)     /*!< No used             */
//#define ICTL_IRQ_54                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x16u)     /*!< No used             */
//#else
//#define ICTL_IRQ_48                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x10u)     /*!< No used             */
//#define ICTL_IRQ_49                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x11u)     /*!< No used             */
//#define ICTL_IRQ_50                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x12u)     /*!< No used             */
//#define ICTL_IRQ_51                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x13u)     /*!< No used             */
//#if (defined(XT32H0xxAMPW) || (defined(XT32H0xxBMPW)))
//#define ICTL_IRQ_OCOMP1                    (ICTL_DIRECT   | ICTL_IRQ2 | 0x14u)     /*!< Comp output 1       */
//#define ICTL_IRQ_OCOMP2                    (ICTL_DIRECT   | ICTL_IRQ2 | 0x15u)     /*!< Comp output 2       */
//#define ICTL_IRQ_OCOMP3                    (ICTL_DIRECT   | ICTL_IRQ2 | 0x16u)     /*!< Comp output 3       */
//#else
//#define ICTL_IRQ_52                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x14u)     /*!< No used             */
//#define ICTL_IRQ_53                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x15u)     /*!< No used             */
//#define ICTL_IRQ_54                        (ICTL_DIRECT   | ICTL_IRQ2 | 0x16u)     /*!< No used             */
//#endif /* XT32H0xxAMPW || XT32H0xxBMPW */
//#endif /* XT32H0xxB */
//#define ICTL_IRQ_OCOMP4                    (ICTL_DIRECT   | ICTL_IRQ2 | 0x17u)     /*!< Comp output 4       */
//#define ICTL_LED_PRD                       (ICTL_DIRECT   | ICTL_IRQ2 | 0x18u)     /*!< LED PRD             */
//#define ICTL_LED_COM                       (ICTL_DIRECT   | ICTL_IRQ2 | 0x19u)     /*!< LED COM             */
//#define ICTL_LED_FRM                       (ICTL_DIRECT   | ICTL_IRQ2 | 0x1Au)     /*!< LED FRM             */
//#define ICTL_LED_UDT                       (ICTL_DIRECT   | ICTL_IRQ2 | 0x1Bu)     /*!< LED UDT             */
//#define ICTL_AFC_NORM                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x1Cu)     /*!< AFC normal          */
//#define ICTL_AFC_LOOP                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x1Du)     /*!< AFC Loop            */
//#define ICTL_AFC_ERR                       (ICTL_DIRECT   | ICTL_IRQ2 | 0x1Eu)     /*!< AFC error           */
//#define ICTL_CTSM_C2H                      (ICTL_DIRECT   | ICTL_IRQ2 | 0x1Fu)     /*!< CTSM ctsm to host   */

//#define ICTL_GPIO_0                        (ICTL_GPIO     | ICTL_IRQ2 | 0x00u)     /*!< GPIOA 00           */
//#define ICTL_GPIO_1                        (ICTL_GPIO     | ICTL_IRQ2 | 0x01u)     /*!< GPIOA 01           */
//#define ICTL_GPIO_2                        (ICTL_GPIO     | ICTL_IRQ2 | 0x02u)     /*!< GPIOA 02           */
//#define ICTL_GPIO_3                        (ICTL_GPIO     | ICTL_IRQ2 | 0x03u)     /*!< GPIOA 03           */
//#define ICTL_GPIO_4                        (ICTL_GPIO     | ICTL_IRQ2 | 0x04u)     /*!< GPIOA 04           */
//#define ICTL_GPIO_5                        (ICTL_GPIO     | ICTL_IRQ2 | 0x05u)     /*!< GPIOA 05           */
//#define ICTL_GPIO_6                        (ICTL_GPIO     | ICTL_IRQ2 | 0x06u)     /*!< GPIOA 06           */
//#define ICTL_GPIO_7                        (ICTL_GPIO     | ICTL_IRQ2 | 0x07u)     /*!< GPIOA 07           */
//#define ICTL_GPIO_8                        (ICTL_GPIO     | ICTL_IRQ2 | 0x08u)     /*!< GPIOA 08           */
//#define ICTL_GPIO_9                        (ICTL_GPIO     | ICTL_IRQ2 | 0x09u)     /*!< GPIOA 09           */
//#define ICTL_GPIO_10                       (ICTL_GPIO     | ICTL_IRQ2 | 0x0Au)     /*!< GPIOA 10           */
//#define ICTL_GPIO_11                       (ICTL_GPIO     | ICTL_IRQ2 | 0x0Bu)     /*!< GPIOA 11           */
//#define ICTL_GPIO_12                       (ICTL_GPIO     | ICTL_IRQ2 | 0x0Cu)     /*!< GPIOA 12           */
//#define ICTL_GPIO_13                       (ICTL_GPIO     | ICTL_IRQ2 | 0x0Du)     /*!< GPIOA 13           */
//#define ICTL_GPIO_14                       (ICTL_GPIO     | ICTL_IRQ2 | 0x0Eu)     /*!< GPIOA 14           */
//#define ICTL_GPIO_15                       (ICTL_GPIO     | ICTL_IRQ2 | 0x0Fu)     /*!< GPIOA 15           */
//#define ICTL_GPIO_16                       (ICTL_GPIO     | ICTL_IRQ2 | 0x10u)     /*!< GPIOA 16           */
//#define ICTL_GPIO_17                       (ICTL_GPIO     | ICTL_IRQ2 | 0x11u)     /*!< GPIOA 17           */
//#define ICTL_GPIO_18                       (ICTL_GPIO     | ICTL_IRQ2 | 0x12u)     /*!< GPIOA 18           */
//#define ICTL_GPIO_19                       (ICTL_GPIO     | ICTL_IRQ2 | 0x13u)     /*!< GPIOA 19           */
//#define ICTL_GPIO_20                       (ICTL_GPIO     | ICTL_IRQ2 | 0x14u)     /*!< GPIOA 20           */
//#define ICTL_GPIO_21                       (ICTL_GPIO     | ICTL_IRQ2 | 0x15u)     /*!< GPIOA 21           */
//#define ICTL_GPIO_22                       (ICTL_GPIO     | ICTL_IRQ2 | 0x16u)     /*!< GPIOA 22           */
//#define ICTL_GPIO_23                       (ICTL_GPIO     | ICTL_IRQ2 | 0x17u)     /*!< GPIOA 23           */
//#define ICTL_GPIO_24                       (ICTL_GPIO     | ICTL_IRQ2 | 0x18u)     /*!< GPIOA 24           */
//#define ICTL_GPIO_25                       (ICTL_GPIO     | ICTL_IRQ2 | 0x19u)     /*!< GPIOA 25           */
//#define ICTL_GPIO_26                       (ICTL_GPIO     | ICTL_IRQ2 | 0x1Au)     /*!< GPIOA 26           */
//#define ICTL_GPIO_27                       (ICTL_GPIO     | ICTL_IRQ2 | 0x1Bu)     /*!< GPIOA 27           */
//#define ICTL_GPIO_28                       (ICTL_GPIO     | ICTL_IRQ2 | 0x1Cu)     /*!< GPIOA 28           */
//#define ICTL_GPIO_29                       (ICTL_GPIO     | ICTL_IRQ2 | 0x1Du)     /*!< GPIOA 29           */
//#define ICTL_GPIO_30                       (ICTL_GPIO     | ICTL_IRQ2 | 0x1Eu)     /*!< GPIOA 30           */
//#define ICTL_GPIO_31                       (ICTL_GPIO     | ICTL_IRQ2 | 0x1Fu)     /*!< GPIOA 31           */

#define ICTL_FIQ_0                         (ICTL_DIRECT   | ICTL_FIQ  | 0x00u)
#define ICTL_FIQ_1                         (ICTL_DIRECT   | ICTL_FIQ  | 0x01u)
#define ICTL_FIQ_2                         (ICTL_DIRECT   | ICTL_FIQ  | 0x02u)
#define ICTL_FIQ_3                         (ICTL_DIRECT   | ICTL_FIQ  | 0x03u)
//#define ICTL_FIQ_4                         (ICTL_DIRECT   | ICTL_FIQ  | 0x04u)
//#define ICTL_FIQ_5                         (ICTL_DIRECT   | ICTL_FIQ  | 0x05u)
//#define ICTL_FIQ_6                         (ICTL_DIRECT   | ICTL_FIQ  | 0x06u)
//#define ICTL_FIQ_7                         (ICTL_DIRECT   | ICTL_FIQ  | 0x07u)


#define ICTL_IRQ_I2C1_GCALL                (0x00000001UL)
#define ICTL_IRQ_I2C1_RXF                  (0x00000002UL)
#define ICTL_IRQ_I2C1_RDR                  (0x00000004UL)
#define ICTL_IRQ_I2C1_STRTD                (0x00000008UL)
#define ICTL_IRQ_I2C1_RSTRTD               (0x00000010UL)
#define ICTL_IRQ_I2C1_STPD                 (0x00000020UL)
#define ICTL_IRQ_I2C1_ACT                  (0x00000040UL)
#define ICTL_IRQ_I2C1_TXE                  (0x00000080UL)
#define ICTL_IRQ_I2C1_TXABRT               (0x00000100UL)
#define ICTL_IRQ_I2C1_TXO                  (0x00000200UL)
#define ICTL_IRQ_I2C1_RXD                  (0x00000400UL)
#define ICTL_IRQ_I2C1_RXU                  (0x00000800UL)
#define ICTL_IRQ_I2C1_RXO                  (0x00001000UL)

#define ICTL_IRQCFG_I2C1_MASK              (ICTL_IRQ_I2C1_GCALL  | \
                                            ICTL_IRQ_I2C1_RXF    | \
                                            ICTL_IRQ_I2C1_RDR    | \
                                            ICTL_IRQ_I2C1_STRTD  | \
                                            ICTL_IRQ_I2C1_RSTRTD | \
                                            ICTL_IRQ_I2C1_STPD   | \
                                            ICTL_IRQ_I2C1_ACT    | \
                                            ICTL_IRQ_I2C1_TXE    | \
                                            ICTL_IRQ_I2C1_TXABRT | \
                                            ICTL_IRQ_I2C1_TXO    | \
                                            ICTL_IRQ_I2C1_RXD    | \
                                            ICTL_IRQ_I2C1_RXU    | \
                                            ICTL_IRQ_I2C1_RXO    )

#define ICTL_IRQ_SPI1_MST                  (0x00002000UL)
#define ICTL_IRQ_SPI1_RXU                  (0x00004000UL)
#define ICTL_IRQ_SPI1_RXO                  (0x00008000UL)
#define ICTL_IRQ_SPI1_RXF                  (0x00010000UL)
#define ICTL_IRQ_SPI1_TXO                  (0x00020000UL)
#define ICTL_IRQ_SPI1_TXE                  (0x00040000UL)

#define ICTL_IRQCFG_SPI1_MASK              (ICTL_IRQ_SPI1_MST |\
                                            ICTL_IRQ_SPI1_RXU | \
                                            ICTL_IRQ_SPI1_RXO | \
                                            ICTL_IRQ_SPI1_RXF | \
                                            ICTL_IRQ_SPI1_TXO | \
                                            ICTL_IRQ_SPI1_TXE )


#define ICTL_IRQ_SPI2_MST                  (0x00080000UL)
#define ICTL_IRQ_SPI2_RXU                  (0x00100000UL)
#define ICTL_IRQ_SPI2_RXO                  (0x00200000UL)
#define ICTL_IRQ_SPI2_RXF                  (0x00400000UL)
#define ICTL_IRQ_SPI2_TXO                  (0x00800000UL)
#define ICTL_IRQ_SPI2_TXE                  (0x01000000UL)

#define ICTL_IRQCFG_SPI2_MASK              (ICTL_IRQ_SPI2_MST | \
                                            ICTL_IRQ_SPI2_RXU | \
                                            ICTL_IRQ_SPI2_RXO | \
                                            ICTL_IRQ_SPI2_RXF | \
                                            ICTL_IRQ_SPI2_TXO | \
                                            ICTL_IRQ_SPI2_TXE )

#if ((defined(XT32H0xxAMPW)) || (defined(XT32H0xxBMPW)))
#define ICTL_IRQ_ADC_EOS                   (0x04000000UL)

#define ICTL_IRQCFG_ADC_EOS_MASK           (ICTL_IRQ_ADC_EOS)
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */

#define ICTL_IRQ_UART1_AD                  (0x10000000UL)
#define ICTL_IRQ_UART2_AD                  (0x20000000UL)
#define ICTL_IRQ_UART3_AD                  (0x40000000UL)
#define ICTL_IRQ_UART4_AD                  (0x80000000UL)

#define ICTL_IRQCFG_UART_AD_MASK           (ICTL_IRQ_UART1_AD | \
                                            ICTL_IRQ_UART2_AD | \
                                            ICTL_IRQ_UART3_AD | \
                                            ICTL_IRQ_UART4_AD )

#define ICTL_IRQ_TIMB_11                   (0x02000000UL)
#define ICTL_IRQ_TIMB_12                   (0x04000000UL)
#define ICTL_IRQ_TIMB_13                   (0x08000000UL)
#define ICTL_IRQ_TIMB_14                   (0x10000000UL)
#define ICTL_IRQ_TIMB_21                   (0x20000000UL)
#define ICTL_IRQ_TIMB_22                   (0x40000000UL)
#define ICTL_IRQ_TIMB_23                   (0x80000000UL)
#define ICTL_IRQ_TIMB_24                   (0x00000001UL)

#define ICTL_IRQCFG_TIMB1_MASK             (ICTL_IRQ_TIMB_11 | \
                                            ICTL_IRQ_TIMB_12 | \
                                            ICTL_IRQ_TIMB_13 | \
                                            ICTL_IRQ_TIMB_14 | \
                                            ICTL_IRQ_TIMB_21 | \
                                            ICTL_IRQ_TIMB_22 | \
                                            ICTL_IRQ_TIMB_23 )
#define ICTL_IRQCFG_TIMB2_MASK             (ICTL_IRQ_TIMB_24 )


#define ICTL_IRQ_I2C2_GCALL                (0x00000002UL)
#define ICTL_IRQ_I2C2_RXF                  (0x00000004UL)
#define ICTL_IRQ_I2C2_RDR                  (0x00000008UL)
#define ICTL_IRQ_I2C2_STRTD                (0x00000010UL)
#define ICTL_IRQ_I2C2_RSTRTD               (0x00000020UL)
#define ICTL_IRQ_I2C2_STPD                 (0x00000040UL)
#define ICTL_IRQ_I2C2_ACT                  (0x00000080UL)
#define ICTL_IRQ_I2C2_TXE                  (0x00000100UL)
#define ICTL_IRQ_I2C2_TXABRT               (0x00000200UL)
#define ICTL_IRQ_I2C2_TXO                  (0x00000400UL)
#define ICTL_IRQ_I2C2_RXD                  (0x00000800UL)
#define ICTL_IRQ_I2C2_RXU                  (0x00001000UL)
#define ICTL_IRQ_I2C2_RXO                  (0x00002000UL)

#define ICTL_IRQCFG_I2C2_MASK              (ICTL_IRQ_I2C2_GCALL  | \
                                            ICTL_IRQ_I2C2_RXF    | \
                                            ICTL_IRQ_I2C2_RDR    | \
                                            ICTL_IRQ_I2C2_STRTD  | \
                                            ICTL_IRQ_I2C2_RSTRTD | \
                                            ICTL_IRQ_I2C2_STPD   | \
                                            ICTL_IRQ_I2C2_ACT    | \
                                            ICTL_IRQ_I2C2_TXE    | \
                                            ICTL_IRQ_I2C2_TXABRT | \
                                            ICTL_IRQ_I2C2_TXO    | \
                                            ICTL_IRQ_I2C2_RXD    | \
                                            ICTL_IRQ_I2C2_RXU    | \
                                            ICTL_IRQ_I2C2_RXO    )

#if defined(XT32H0xxB)
#define ICTL_IRQ_ADC_INJ_EOC               (0x00010000UL)
#define ICTL_IRQ_ADC_INJ_EOS               (0x00020000UL)
#define ICTL_IRQ_ADC_REG_EOC               (0x00040000UL)
#define ICTL_IRQ_ADC_REG_EOS               (0x00080000UL)
#define ICTL_IRQ_ADC_INJ_AWD               (0x00100000UL)
#define ICTL_IRQ_ADC_REG_AWD               (0x00200000UL)

#define ICTL_IRQCFG_ADC_MASK               (ICTL_IRQ_ADC_INJ_EOC | \
                                            ICTL_IRQ_ADC_INJ_EOS | \
                                            ICTL_IRQ_ADC_REG_EOC | \
                                            ICTL_IRQ_ADC_REG_EOS | \
                                            ICTL_IRQ_ADC_INJ_AWD | \
                                            ICTL_IRQ_ADC_REG_AWD )
#endif /* XT32H0xxB */

#if (defined(XT32H0xxAMPW) || (defined(XT32H0xxBMPW)))
#define ICTL_IRQ_OCOMP_1                   (0x00100000UL)
#define ICTL_IRQ_OCOMP_2                   (0x00200000UL)
#define ICTL_IRQ_OCOMP_3                   (0x00400000UL)
#define ICTL_IRQ_OCOMP_4                   (0x00800000UL)
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */

#if (defined(XT32H0xxAMPW) || (defined(XT32H0xxBMPW)))
#define ICTL_IRQCFG_OCOMP_MASK             (ICTL_IRQ_OCOMP_1 | \
                                            ICTL_IRQ_OCOMP_2 | \
                                            ICTL_IRQ_OCOMP_3 | \
                                            ICTL_IRQ_OCOMP_4 )
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */

#define ICTL_IRQ_LED_PRD                   (0x01000000UL)
#define ICTL_IRQ_LED_COM                   (0x02000000UL)
#define ICTL_IRQ_LED_FRM                   (0x04000000UL)
#define ICTL_IRQ_LED_UDT                   (0x08000000UL)

#define ICTL_IRQCFG_LED_MASK               (ICTL_IRQ_LED_PRD | \
                                            ICTL_IRQ_LED_COM | \
                                            ICTL_IRQ_LED_FRM | \
                                            ICTL_IRQ_LED_UDT )

#define ICTL_IRQ_AFC_NORM                  (0x10000000UL)
#define ICTL_IRQ_AFC_LOOP                  (0x20000000UL)
#define ICTL_IRQ_AFC_ERR                   (0x40000000UL)

#define ICTL_IRQCFG_AFC_MASK               (ICTL_IRQ_AFC_NORM | \
                                            ICTL_IRQ_AFC_LOOP | \
                                            ICTL_IRQ_AFC_ERR )

#define ICTL_IRQ_CTSM_C2H                  (0x80000000UL)

#define ICTL_IRQCFG_CTSM_MASK              (ICTL_IRQ_CTSM_C2H)

/**
  * @}
  */

/** @defgroup ICTL_Mask  ICTL Mask
  * @{
  */
#define ICTL_UNMASK                      (0x00000000UL)
#define ICTL_MASK                        (0x00000001UL)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup ICTL_Exported_Macros ICTL Exported Macros
  * @{
  */
/** @defgroup ICTL_Status ICTL Status
  * @{
  */
#define __HAL_GET_FINALSTATUS(__LINEIDX__)    (((__LINEIDX__) < 32) ? (ICTL->IRQFINALSTATUSL & (0x01UL << (__LINEIDX__))) : \
	                                            (ICTL->IRQFINALSTATUSH & (0x01UL << ((__LINEIDX__) - 32))))

#define __HAL_GET_RAWSTATUS(__LINEIDX__)    (((__LINEIDX__) < 32) ? (ICTL->IRQRAWSTATUSL & (0x01UL << (__LINEIDX__))) : \
	                                            (ICTL->IRQRAWSTATUSH & (0x01UL << ((__LINEIDX__) - 32))))
/**
  * @}
  */

/**
  * @}
  */

/* Private constants --------------------------------------------------------*/
/** @defgroup ICTL_Private_Constants ICTL Private Constants
  * @{
  */

/**
  * @brief  ICTL Line property definition
  */
#define ICTL_PROPERTY_SHIFT            (24u)
#define ICTL_DIRECT                    (0x01uL << ICTL_PROPERTY_SHIFT)
#define ICTL_CONFIG                    (0x02uL << ICTL_PROPERTY_SHIFT)
#define ICTL_GPIO                      ((0x04uL << ICTL_PROPERTY_SHIFT) | ICTL_CONFIG)
#define ICTL_RESERVED                  (0x08uL << ICTL_PROPERTY_SHIFT)
#define ICTL_PROPERTY_MASK             (ICTL_DIRECT | ICTL_CONFIG | ICTL_GPIO)

/**
  * @brief  ICTL Register and bit usage
  */
#define ICTL_REG_SHIFT                 (16u)
#define ICTL_IRQ1                      (0x01uL << ICTL_REG_SHIFT)
#define ICTL_IRQ2                      (0x02uL << ICTL_REG_SHIFT)
#define ICTL_FIQ                       (0x04uL << ICTL_REG_SHIFT)
#define ICTL_REG_MASK                  (ICTL_IRQ1 | ICTL_IRQ2 | ICTL_FIQ)
#define ICTL_PIN_MASK                  (0x0000001Fu)

/**
  * @brief  ICTL Line number
  */
#define ICTL_IRQ_NB                    (64uL)
#define ICTL_FIQ_NB                    ( 4uL)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup ICTL_Exported_Functions ICTL Exported Functions
  * @brief    ICTL Exported Functions
  * @{
  */

/** @defgroup ICTL_Exported_Functions_Group1 Configuration functions
  * @brief    Configuration functions
  * @{
  */
/* Configuration functions ****************************************************/
HAL_StatusTypeDef HAL_ICTL_SetConfigLine(ICTL_HandleTypeDef *hictl, ICTL_ConfigTypeDef *pIctlConfig);
HAL_StatusTypeDef HAL_ICTL_GetConfigLine(ICTL_HandleTypeDef *hictl, ICTL_ConfigTypeDef *pIctlConfig);
HAL_StatusTypeDef HAL_ICTL_ClearConfigLine(ICTL_HandleTypeDef *hictl);
HAL_StatusTypeDef HAL_ICTL_RegisterCallback(ICTL_HandleTypeDef *hictl, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_ICTL_GetHandle(ICTL_HandleTypeDef *hictl, uint32_t IctlLine);
/**
  * @}
  */

/** @defgroup ICTL_Exported_Functions_Group2 IO operation functions
  * @brief    IO operation functions
  * @{
  */
/* IO operation functions *****************************************************/
void              HAL_ICTL_IRQHandler(ICTL_HandleTypeDef *hictl);
uint32_t          HAL_ICTL_GetPending(ICTL_HandleTypeDef *hictl);
void              HAL_ICTL_ClearPending(ICTL_HandleTypeDef *hictl);
void              HAL_ICTL_ActiveSWI(ICTL_HandleTypeDef *hictl);
void              HAL_ICTL_ClearSWI(ICTL_HandleTypeDef *hictl);

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

#endif /* XT32H0xx_HAL_ICTL_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
