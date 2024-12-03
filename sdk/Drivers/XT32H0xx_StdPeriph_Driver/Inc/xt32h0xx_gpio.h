/**
  ******************************************************************************
  * @file    xt32h0xx_gpio.h
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file contains all the functions prototypes for the GPIO 
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
#ifndef __XT32H0XX_GPIO_H
#define __XT32H0XX_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Types GPIO Exported Types 
  * @{
  */
/** @defgroup GPIO_Configuration_Mode_enumeration GPIO Mode
  * @{
  */
typedef enum
{
  GPIO_Mode_IN   = 0x00,   /*!< GPIO Input Mode              */
  GPIO_Mode_OUT  = 0x01    /*!< GPIO Output Mode             */
}GPIOMode_TypeDef;

#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_Mode_IN)|| ((MODE) == GPIO_Mode_OUT))
/**
  * @}
  */

/** @defgroup GPIO_Source_type_enumeration GPIO Source
  * @{
  */
typedef enum
{
  GPIO_Source_SW = 0x00,
  GPIO_Source_HW = 0x01
}GPIOSource_TypeDef;

#define IS_GPIO_SOURCE(SOURCE) (((SOURCE) == GPIO_Source_SW) || ((SOURCE) == GPIO_Source_HW))

/**
  * @}
  */

/** @defgroup GPIO_Interrupt_type_enumeration GPIO Interrupt Type
  * @{
  */
typedef enum
{
  GPIO_IntType_LEVEL  = 0x00, /*!< interrupt level */
  GPIO_IntType_EDGE   = 0x01  /*!< interrupt edge */
}GPIOIntType_TypeDef;

#define IS_GPIO_INTTYPE(TYPE) (((TYPE) == GPIO_IntType_LEVEL) || ((TYPE) == GPIO_IntType_EDGE))
/**
  * @}
  */

/** @defgroup GPIO_Interupt_polarity_enumeration GPIO Interrupt Polarity
  * @{
  */
typedef enum
{
  GPIO_IntPol_LOW  = 0x00,
  GPIO_IntPol_HIGH = 0x01
}GPIOIntPol_TypeDef;

#define IS_GPIO_INTPOL(POL) (((POL) == GPIO_IntPol_LOW) || ((POL) == GPIO_IntPol_HIGH))
/**
  * @}
  */

/** @defgroup GPIO_Interupt_debounce_enumeration GPIO Interrupt Debounce 
  * @{
  */
typedef enum
{
  GPIO_IntDeb_DISABLE = 0x00,
  GPIO_IntDeb_ENABLE  = 0x01
}GPIOIntDeb_TypeDef;

#define IS_GPIO_INTDEB(DEB) (((DEB) == GPIO_IntDeb_DISABLE) || ((DEB) == GPIO_IntDeb_ENABLE))
/**
  * @}
  */

/** @defgroup GPIO_Interupt_sync_enumeration GPIO Interrupt Sync
  * @{
  */
typedef enum
{
  GPIO_IntSync_NO = 0x00,
  GPIO_IntSync_EN = 0x01
}GPIOIntSync_TypeDef;

#define IS_GPIO_INTSYNC(SYNC) (((SYNC) == GPIO_IntSync_NO) || ((SYNC) == GPIO_IntSync_EN))
/**
  * @}
  */

/** @defgroup GPIO_Bit_Status_enumeration GPIO Bit Status
  * @{
  */
typedef enum
{ 
  Bit_RESET = 0,
  Bit_SET
}BitAction;

#define IS_GPIO_BIT_ACTION(ACTION) (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))
/**
  * @}
  */

/**
  * @brief  GPIO Init structure definition  
  */
typedef struct
{
  uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                              This parameter can be any value of @ref GPIO_EC_Pins */

  uint32_t Mode;         /*!< Specifies the operating mode for the selected pins.
                              This parameter can be a value of @ref GPIOMode_TypeDef. */

  uint32_t Source;       /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref GPIOSource_TypeDef. */
}GPIO_InitTypeDef;

/**
  * @brief  GPIO Interrupt structure definition  
  */
typedef struct
{
  uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                              This parameter can be any value of @ref GPIO_EC_Pins */

  uint32_t Type;         /*!< Specifies the operating mode for the selected pins.
                              This parameter can be a value of @ref GPIOIntType_TypeDef. */

  uint32_t Polarity;     /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref GPIOIntPol_TypeDef. */

  uint32_t Debounce;     /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref GPIOIntDeb_TypeDef. */

  uint32_t Sync;         /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref GPIOIntSync_TypeDef. */
}GPIOInt_TypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants GPIO Exported Constants
  * @{
  */

/** @defgroup GPIO_EC_Pins GPIO Pins
  * @{
  */
#define GPIO_PIN_0                     (0x00000001UL)                          /*!< Pin 0 selected    */
#define GPIO_PIN_1                     (0x00000002UL)                          /*!< Pin 1 selected    */
#define GPIO_PIN_2                     (0x00000004UL)                          /*!< Pin 2 selected    */
#define GPIO_PIN_3                     (0x00000008UL)                          /*!< Pin 3 selected    */
#define GPIO_PIN_4                     (0x00000010UL)                          /*!< Pin 4 selected    */
#define GPIO_PIN_5                     (0x00000020UL)                          /*!< Pin 5 selected    */
#define GPIO_PIN_6                     (0x00000040UL)                          /*!< Pin 6 selected    */
#define GPIO_PIN_7                     (0x00000080UL)                          /*!< Pin 7 selected    */
#define GPIO_PIN_8                     (0x00000100UL)                          /*!< Pin 8 selected    */
#define GPIO_PIN_9                     (0x00000200UL)                          /*!< Pin 9 selected    */
#define GPIO_PIN_10                    (0x00000400UL)                          /*!< Pin 10 selected   */
#define GPIO_PIN_11                    (0x00000800UL)                          /*!< Pin 11 selected   */
#define GPIO_PIN_12                    (0x00001000UL)                          /*!< Pin 12 selected   */
#define GPIO_PIN_13                    (0x00002000UL)                          /*!< Pin 13 selected   */
#define GPIO_PIN_14                    (0x00004000UL)                          /*!< Pin 14 selected   */
#define GPIO_PIN_15                    (0x00008000UL)                          /*!< Pin 15 selected   */
#define GPIO_PIN_16                    (0x00010000UL)                          /*!< Pin 16 selected   */
#define GPIO_PIN_17                    (0x00020000UL)                          /*!< Pin 17 selected   */
#define GPIO_PIN_18                    (0x00040000UL)                          /*!< Pin 18 selected   */
#define GPIO_PIN_19                    (0x00080000UL)                          /*!< Pin 19 selected   */
#define GPIO_PIN_20                    (0x00100000UL)                          /*!< Pin 20 selected   */
#define GPIO_PIN_21                    (0x00200000UL)                          /*!< Pin 21 selected   */
#define GPIO_PIN_22                    (0x00400000UL)                          /*!< Pin 22 selected   */
#define GPIO_PIN_23                    (0x00800000UL)                          /*!< Pin 23 selected   */
#define GPIO_PIN_24                    (0x01000000UL)                          /*!< Pin 24 selected   */
#define GPIO_PIN_25                    (0x02000000UL)                          /*!< Pin 25 selected   */
#define GPIO_PIN_26                    (0x04000000UL)                          /*!< Pin 26 selected   */
#define GPIO_PIN_27                    (0x08000000UL)                          /*!< Pin 27 selected   */
#define GPIO_PIN_28                    (0x10000000UL)                          /*!< Pin 28 selected   */
#define GPIO_PIN_29                    (0x20000000UL)                          /*!< Pin 29 selected   */
#define GPIO_PIN_30                    (0x40000000UL)                          /*!< Pin 30 selected   */
#define GPIO_PIN_31                    (0x80000000UL)                          /*!< Pin 31 selected   */
#define GPIO_PIN_ALL                   (0xFFFFFFFFUL)                          /*!< All pins selected */

#define IS_GPIO_PIN(PIN) ((PIN) != (uint16_t)0x00)

#define IS_GET_GPIO_PIN(PIN) (((PIN) == GPIO_PIN_0) || \
                              ((PIN) == GPIO_PIN_1) || \
                              ((PIN) == GPIO_PIN_2) || \
                              ((PIN) == GPIO_PIN_3) || \
                              ((PIN) == GPIO_PIN_4) || \
                              ((PIN) == GPIO_PIN_5) || \
                              ((PIN) == GPIO_PIN_6) || \
                              ((PIN) == GPIO_PIN_7) || \
                              ((PIN) == GPIO_PIN_8) || \
                              ((PIN) == GPIO_PIN_9) || \
                              ((PIN) == GPIO_PIN_10) || \
                              ((PIN) == GPIO_PIN_11) || \
                              ((PIN) == GPIO_PIN_12) || \
                              ((PIN) == GPIO_PIN_13) || \
                              ((PIN) == GPIO_PIN_14) || \
                              ((PIN) == GPIO_PIN_15) || \
                              ((PIN) == GPIO_PIN_16) || \
                              ((PIN) == GPIO_PIN_17) || \
                              ((PIN) == GPIO_PIN_18) || \
                              ((PIN) == GPIO_PIN_19) || \
                              ((PIN) == GPIO_PIN_20) || \
                              ((PIN) == GPIO_PIN_21) || \
                              ((PIN) == GPIO_PIN_22) || \
                              ((PIN) == GPIO_PIN_23) || \
                              ((PIN) == GPIO_PIN_24) || \
                              ((PIN) == GPIO_PIN_25) || \
                              ((PIN) == GPIO_PIN_26) || \
                              ((PIN) == GPIO_PIN_27) || \
                              ((PIN) == GPIO_PIN_28) || \
                              ((PIN) == GPIO_PIN_29) || \
                              ((PIN) == GPIO_PIN_30) || \
                              ((PIN) == GPIO_PIN_31))

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Macros GPIO Exported Macros
  * @{
  */
/** @defgroup GPIO_Group GPIO Group 
  * @{
  */
#define IS_GPIO_ALL_PERIPH(PERIPH) (((PERIPH) == GPIOA) || \
                                    ((PERIPH) == GPIOB) || \
                                    ((PERIPH) == GPIOC) || \
                                    ((PERIPH) == GPIOD))
/**
  * @}
  */

/** @defgroup GPIO_Port_Offset GPIO Port Offset
  * @{
  */
#define GPIO_GET_PORT_OFFSET(GPIOx)     (((GPIOx) == GPIOA) ? 0 : \
                                         ((GPIOx) == GPIOB) ? 1 : \
                                         ((GPIOx) == GPIOC) ? 2 : \
                                         3)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */
/** @addtogroup GPIO_Exported_Functions
  * @{
  */

/** @addtogroup GPIO_Exported_Functions_Group1
  * @{
  */
/* Initialization and Configuration functions *********************************/
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
/**
  * @}
  */

/** @addtogroup GPIO_Exported_Functions_Group2
  * @{
  */
/* GPIO Read and Write functions **********************************************/
uint32_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
uint32_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
uint32_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
uint32_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint32_t PortVal);
/**
  * @}
  */

/** @addtogroup GPIO_Exported_Functions_Group3
  * @{
  */
/* GPIO interrupt management functions ****************************************/
void GPIO_InterruptConfig(GPIOInt_TypeDef* GPIO_IntCfg);
void GPIO_InterruptStructInit(GPIOInt_TypeDef* GPIO_IntCfg);
void GPIO_InterruptEnable(uint32_t GPIO_Pin);
void GPIO_InterruptDisable(uint32_t GPIO_Pin);
void GPIO_InterruptMask(uint32_t GPIO_Pin);
void GPIO_InterruptUnmask(uint32_t GPIO_Pin);
ITStatus GPIO_GetITFlag(uint32_t GPIO_Pin);
FlagStatus GPIO_GetITStatus(uint32_t GPIO_Pin);
void GPIO_ClearITFlag(uint32_t GPIO_Pin);
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif
/**
  * @}
  */

/**
  * @}
  */

#endif /* __XT32H0XX_GPIO_H */

