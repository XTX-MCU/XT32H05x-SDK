/**
  ******************************************************************************
  * @file    xt32h0xx_ictl.h
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file contains all the functions prototypes for the ICTL 
  *          firmware library
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_ICTL_H
#define __XT32H0XX_ICTL_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup ICTL
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup ICTL_Exported_Constants ICTL Exported Constants
  * @{
  */
/** @defgroup ICTL_Lines ICTL Lines
  * @{
  */

#define ICTL_LINE_I2C1_GCALL                (0x00000001UL)
#define ICTL_LINE_I2C1_RXF                  (0x00000002UL)
#define ICTL_LINE_I2C1_RDR                  (0x00000004UL)
#define ICTL_LINE_I2C1_STRTD                (0x00000008UL)
#define ICTL_LINE_I2C1_RSTRTD               (0x00000010UL)
#define ICTL_LINE_I2C1_STPD                 (0x00000020UL)
#define ICTL_LINE_I2C1_ACT                  (0x00000040UL)
#define ICTL_LINE_I2C1_TXE                  (0x00000080UL)
#define ICTL_LINE_I2C1_TXABRT               (0x00000100UL)
#define ICTL_LINE_I2C1_TXO                  (0x00000200UL)
#define ICTL_LINE_I2C1_RXD                  (0x00000400UL)
#define ICTL_LINE_I2C1_RXU                  (0x00000800UL)
#define ICTL_LINE_I2C1_RXO                  (0x00001000UL)

#define ICTL_LINE_MASK_I2C1                 (ICTL_LINE_I2C1_GCALL | ICTL_LINE_I2C1_RXF    | ICTL_LINE_I2C1_RDR    | \
                                             ICTL_LINE_I2C1_STRTD | ICTL_LINE_I2C1_RSTRTD | ICTL_LINE_I2C1_STPD   | \
                                             ICTL_LINE_I2C1_ACT   | ICTL_LINE_I2C1_TXE    | ICTL_LINE_I2C1_TXABRT | \
                                             ICTL_LINE_I2C1_TXO   | ICTL_LINE_I2C1_RXD    | ICTL_LINE_I2C1_RXU    | \
                                             ICTL_LINE_I2C1_RXO)

#define ICTL_LINE_SPI1_MST                  (0x00002000UL)
#define ICTL_LINE_SPI1_RXU                  (0x00004000UL)
#define ICTL_LINE_SPI1_RXO                  (0x00008000UL)
#define ICTL_LINE_SPI1_RXF                  (0x00010000UL)
#define ICTL_LINE_SPI1_TXO                  (0x00020000UL)
#define ICTL_LINE_SPI1_TXE                  (0x00040000UL)

#define ICTL_LINE_MASK_SPI1                 (ICTL_LINE_SPI1_MST | ICTL_LINE_SPI1_RXU | ICTL_LINE_SPI1_RXO | \
                                             ICTL_LINE_SPI1_RXF  | ICTL_LINE_SPI1_TXO | ICTL_LINE_SPI1_TXE)

#define ICTL_LINE_SPI2_MST                  (0x00080000UL)
#define ICTL_LINE_SPI2_RXU                  (0x00100000UL)
#define ICTL_LINE_SPI2_RXO                  (0x00200000UL)
#define ICTL_LINE_SPI2_RXF                  (0x00400000UL)
#define ICTL_LINE_SPI2_TXO                  (0x00800000UL)
#define ICTL_LINE_SPI2_TXE                  (0x01000000UL)

#define ICTL_LINE_MASK_SPI2                 (ICTL_LINE_SPI2_MST | ICTL_LINE_SPI2_RXU | ICTL_LINE_SPI2_RXO | \
                                             ICTL_LINE_SPI2_RXF | ICTL_LINE_SPI2_TXO | ICTL_LINE_SPI2_TXE)

#if ((defined(XT32H0xxAMPW)) || (defined(XT32H0xxBMPW)))
#define ICTL_LINE_ADC_EOS                   (0x04000000UL)

#define ICTL_LINE_MASK_ADC                  (ICTL_LINE_ADC_EOS)
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */

#if ((defined(XT32H0xxBMPW)) || (defined(XT32H0xxA)) || (defined(XT32H0xxB)))
#define ICTL_LINE_UART1_AD                  (0x10000000UL)
#define ICTL_LINE_UART2_AD                  (0x20000000UL)
#define ICTL_LINE_UART3_AD                  (0x40000000UL)
#define ICTL_LINE_UART4_AD                  (0x80000000UL)

#define ICTL_LINE_MASK_UART_AD              (ICTL_LINE_UART1_AD | ICTL_LINE_UART2_AD | ICTL_LINE_UART3_AD | ICTL_LINE_UART4_AD)
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB  */

#define ICTL_LINE_I2C2_GCALL                (0x00000002UL)
#define ICTL_LINE_I2C2_RXF                  (0x00000004UL)
#define ICTL_LINE_I2C2_RDR                  (0x00000008UL)
#define ICTL_LINE_I2C2_STRTD                (0x00000010UL)
#define ICTL_LINE_I2C2_RSTRTD               (0x00000020UL)
#define ICTL_LINE_I2C2_STPD                 (0x00000040UL)
#define ICTL_LINE_I2C2_ACT                  (0x00000080UL)
#define ICTL_LINE_I2C2_TXE                  (0x00000100UL)
#define ICTL_LINE_I2C2_TXABRT               (0x00000200UL)
#define ICTL_LINE_I2C2_TXO                  (0x00000400UL)
#define ICTL_LINE_I2C2_RXD                  (0x00000800UL)
#define ICTL_LINE_I2C2_RXU                  (0x00001000UL)
#define ICTL_LINE_I2C2_RXO                  (0x00002000UL)

#define ICTL_LINE_MASK_I2C2                 (ICTL_LINE_I2C2_GCALL | ICTL_LINE_I2C2_RXF    | ICTL_LINE_I2C2_RDR   | \
                                             ICTL_LINE_I2C2_STRTD | ICTL_LINE_I2C2_RSTRTD | ICTL_LINE_I2C2_STPD  | \
                                             ICTL_LINE_I2C2_ACT   | ICTL_LINE_I2C2_TXE    | ICTL_LINE_I2C2_TXABRT| \
                                             ICTL_LINE_I2C2_TXO   | ICTL_LINE_I2C2_RXD    | ICTL_LINE_I2C2_RXU   | \
                                             ICTL_LINE_I2C2_RXO)

#if (defined(XT32H0xxAMPW) || (defined(XT32H0xxBMPW)))
#define ICTL_LINE_OCOMP_1                   (0x00100000UL)
#define ICTL_LINE_OCOMP_2                   (0x00200000UL)
#define ICTL_LINE_OCOMP_3                   (0x00400000UL)
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */
#define ICTL_LINE_OCOMP_4                   (0x00800000UL)

#if (defined(XT32H0xxAMPW) || (defined(XT32H0xxBMPW)))
#define ICTL_LINE_MASK_COMP                 (ICTL_LINE_OCOMP_1 | \
                                             ICTL_LINE_OCOMP_2 | \
                                             ICTL_LINE_OCOMP_3 | \
                                             ICTL_LINE_OCOMP_4 )
#else
#define ICTL_LINE_MASK_COMP                 (ICTL_LINE_OCOMP_4 )
#endif                                            

#if ((defined(XT32H0xxBMPW)) || (defined(XT32H0xxA)) || (defined(XT32H0xxB)))
#define ICTL_LINE_LED_PRD                   (0x01000000UL)
#define ICTL_LINE_LED_COM                   (0x02000000UL)
#define ICTL_LINE_LED_FRM                   (0x04000000UL)
#define ICTL_LINE_LED_UDT                   (0x08000000UL)

#define ICTL_LINE_MASK_LED                  (ICTL_LINE_LED_PRD | ICTL_LINE_LED_COM | ICTL_LINE_LED_FRM | ICTL_LINE_LED_UDT)

#define ICTL_LINE_AFC_NORM                  (0x10000000UL)
#define ICTL_LINE_AFC_LOOP                  (0x20000000UL)
#define ICTL_LINE_AFC_ERR                   (0x40000000UL)

#define ICTL_LINE_MASK_AFC                  (ICTL_LINE_AFC_NORM | ICTL_LINE_AFC_LOOP | ICTL_LINE_AFC_ERR)

#define ICTL_LINE_CTSM_C2H                  (0x80000000UL)

#define ICTL_LINE_MASK_CTSM                 (ICTL_LINE_CTSM_C2H)
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB  */

#define ICTL_LINE_GPIOA_0                   (0x00000001UL)
#define ICTL_LINE_GPIOA_1                   (0x00000002UL)
#define ICTL_LINE_GPIOA_2                   (0x00000004UL)
#define ICTL_LINE_GPIOA_3                   (0x00000008UL)
#define ICTL_LINE_GPIOA_4                   (0x00000010UL)
#define ICTL_LINE_GPIOA_5                   (0x00000020UL)
#define ICTL_LINE_GPIOA_6                   (0x00000040UL)
#define ICTL_LINE_GPIOA_7                   (0x00000080UL)
#define ICTL_LINE_GPIOA_8                   (0x00000100UL)
#define ICTL_LINE_GPIOA_9                   (0x00000200UL)
#define ICTL_LINE_GPIOA_10                  (0x00000400UL)
#define ICTL_LINE_GPIOA_11                  (0x00000800UL)
#define ICTL_LINE_GPIOA_12                  (0x00001000UL)
#define ICTL_LINE_GPIOA_13                  (0x00002000UL)
#define ICTL_LINE_GPIOA_14                  (0x00004000UL)
#define ICTL_LINE_GPIOA_15                  (0x00008000UL)
#define ICTL_LINE_GPIOA_16                  (0x00010000UL)
#define ICTL_LINE_GPIOA_17                  (0x00020000UL)
#define ICTL_LINE_GPIOA_18                  (0x00040000UL)
#define ICTL_LINE_GPIOA_19                  (0x00080000UL)
#define ICTL_LINE_GPIOA_20                  (0x00100000UL)
#define ICTL_LINE_GPIOA_21                  (0x00200000UL)
#define ICTL_LINE_GPIOA_22                  (0x00400000UL)
#define ICTL_LINE_GPIOA_23                  (0x00800000UL)
#define ICTL_LINE_GPIOA_24                  (0x01000000UL)
#define ICTL_LINE_GPIOA_25                  (0x02000000UL)
#define ICTL_LINE_GPIOA_26                  (0x04000000UL)
#define ICTL_LINE_GPIOA_27                  (0x08000000UL)
#define ICTL_LINE_GPIOA_28                  (0x10000000UL)
#define ICTL_LINE_GPIOA_29                  (0x20000000UL)
#define ICTL_LINE_GPIOA_30                  (0x40000000UL)
#define ICTL_LINE_GPIOA_31                  (0x80000000UL)

#define ICTL_LINE_MASK_GPIOA                (ICTL_LINE_GPIOA_0  | ICTL_LINE_GPIOA_1  | ICTL_LINE_GPIOA_2  | ICTL_LINE_GPIOA_3  | \
                                             ICTL_LINE_GPIOA_4  | ICTL_LINE_GPIOA_5  | ICTL_LINE_GPIOA_6  | ICTL_LINE_GPIOA_7  | \
                                             ICTL_LINE_GPIOA_8  | ICTL_LINE_GPIOA_9  | ICTL_LINE_GPIOA_10 | ICTL_LINE_GPIOA_11 | \
                                             ICTL_LINE_GPIOA_12 | ICTL_LINE_GPIOA_13 | ICTL_LINE_GPIOA_14 | ICTL_LINE_GPIOA_15 | \
                                             ICTL_LINE_GPIOA_16 | ICTL_LINE_GPIOA_17 | ICTL_LINE_GPIOA_18 | ICTL_LINE_GPIOA_19 | \
                                             ICTL_LINE_GPIOA_20 | ICTL_LINE_GPIOA_21 | ICTL_LINE_GPIOA_22 | ICTL_LINE_GPIOA_23 | \
                                             ICTL_LINE_GPIOA_24 | ICTL_LINE_GPIOA_25 | ICTL_LINE_GPIOA_26 | ICTL_LINE_GPIOA_27 | \
                                             ICTL_LINE_GPIOA_28 | ICTL_LINE_GPIOA_29 | ICTL_LINE_GPIOA_30 | ICTL_LINE_GPIOA_31)

#define ICTL_LINE_RANGE_LOW                 (0)
#define ICTL_LINE_RANGE_HIGH                (1)

#define ICTL_LINE_RANGE_I2C1                (ICTL_LINE_RANGE_LOW)
#define ICTL_LINE_RANGE_I2C2                (ICTL_LINE_RANGE_HIGH)
#define ICTL_LINE_RANGE_SPI1                (ICTL_LINE_RANGE_LOW)
#define ICTL_LINE_RANGE_SPI2                (ICTL_LINE_RANGE_LOW)
#if (defined(XT32H0xxAMPW) || (defined(XT32H0xxBMPW)))
#define ICTL_LINE_RANGE_ADC                 (ICTL_LINE_RANGE_LOW)
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */
#define ICTL_LINE_RANGE_COMP                (ICTL_LINE_RANGE_HIGH)
#define ICTL_LINE_RANGE_GPIO                (ICTL_LINE_RANGE_HIGH)
#if ((defined(XT32H0xxBMPW)) || (defined(XT32H0xxA)) || (defined(XT32H0xxB)))
#define ICTL_LINE_RANGE_UART_AD             (ICTL_LINE_RANGE_LOW)
#define ICTL_LINE_RANGE_LED                 (ICTL_LINE_RANGE_HIGH)
#define ICTL_LINE_RANGE_AFC                 (ICTL_LINE_RANGE_HIGH)
#define ICTL_LINE_RANGE_CTSM                (ICTL_LINE_RANGE_HIGH)
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup ICTL_Exported_Functions
  * @{
  */
/** @addtogroup ICTL_Exported_Functions_Group1
  * @{
  */
/* Function used to set the ICTL configuration to the default reset state *****/
void ICTL_DeInit(void);

/* Initialization and Configuration functions *********************************/
void ICTL_Enable(uint32_t ICTL_Lines, uint32_t ICTL_Range);
void ICTL_Disable(uint32_t ICTL_Lines, uint32_t ICTL_Range);
void ICTL_Mask(uint32_t ICTL_Lines, uint32_t ICTL_Range);
void ICTL_Unmask(uint32_t ICTL_Lines, uint32_t ICTL_Range);
void ICTL_ForceActive(uint32_t ICTL_Lines, uint32_t ICTL_Range);
void ICTL_ForceInactive(uint32_t ICTL_Lines, uint32_t ICTL_Range);

/**
  * @}
  */

/** @addtogroup ICTL_Exported_Functions_Group2
  * @{
  */
/* Interrupts and flags management functions **********************************/
FlagStatus ICTL_GetRawStatus(uint32_t ICTL_Line, uint32_t ICTL_Range);
FlagStatus ICTL_GetStatus(uint32_t ICTL_Line, uint32_t ICTL_Range);
FlagStatus ICTL_GetMaskStatus(uint32_t ICTL_Line, uint32_t ICTL_Range);
FlagStatus ICTL_GetFinalStatus(uint32_t ICTL_Line, uint32_t ICTL_Range);

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

#endif /* __XT32H0XX_ICTL_H */

