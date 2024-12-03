/**
  ******************************************************************************
  * @file    xt32h0xx_hal_gpio.h
  * @author  Software Team
  * @brief   Header file of GPIO HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_GPIO_H
#define XT32H0xx_HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup GPIO GPIO
  * @brief GPIO HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup GPIO_Exported_Types GPIO Exported Types
  * @{
  */
/**
  * @brief   GPIO Init structure definition
  */
typedef struct
{
  uint32_t Pin;           /*!< Specifies the GPIO pins to be configured.
                               This parameter can be any value of @ref GPIO_pins */

  uint32_t Mode;          /*!< Specifies the operating mode for the selected pins.
                               This parameter can be a value of @ref GPIO_mode */
} GPIO_InitTypeDef;

/**
  * @brief  GPIO Bit SET and Bit RESET enumeration
  */
typedef enum
{
  GPIO_PIN_RESET = 0U,
  GPIO_PIN_SET
} GPIO_PinState;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIO_Exported_Constants GPIO Exported Constants
  * @{
  */
/** @defgroup GPIO_pins GPIO pins
  * @{
  */
#define GPIO_PIN_0                 ((uint32_t)0x00000001UL)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint32_t)0x00000002UL)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint32_t)0x00000004UL)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint32_t)0x00000008UL)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint32_t)0x00000010UL)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint32_t)0x00000020UL)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint32_t)0x00000040UL)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint32_t)0x00000080UL)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint32_t)0x00000100UL)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint32_t)0x00000200UL)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint32_t)0x00000400UL)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint32_t)0x00000800UL)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint32_t)0x00001000UL)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint32_t)0x00002000UL)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint32_t)0x00004000UL)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint32_t)0x00008000UL)  /* Pin 15 selected   */
#define GPIO_PIN_16                ((uint32_t)0x00010000UL)  /* Pin 16 selected   */
#define GPIO_PIN_17                ((uint32_t)0x00020000UL)  /* Pin 17 selected   */
#define GPIO_PIN_18                ((uint32_t)0x00040000UL)  /* Pin 18 selected   */
#define GPIO_PIN_19                ((uint32_t)0x00080000UL)  /* Pin 19 selected   */
#define GPIO_PIN_20                ((uint32_t)0x00100000UL)  /* Pin 20 selected   */
#define GPIO_PIN_21                ((uint32_t)0x00200000UL)  /* Pin 21 selected   */
#define GPIO_PIN_22                ((uint32_t)0x00400000UL)  /* Pin 22 selected   */
#define GPIO_PIN_23                ((uint32_t)0x00800000UL)  /* Pin 23 selected   */
#define GPIO_PIN_24                ((uint32_t)0x01000000UL)  /* Pin 24 selected   */
#define GPIO_PIN_25                ((uint32_t)0x02000000UL)  /* Pin 25 selected   */
#define GPIO_PIN_26                ((uint32_t)0x04000000UL)  /* Pin 26 selected   */
#define GPIO_PIN_27                ((uint32_t)0x08000000UL)  /* Pin 27 selected   */
#define GPIO_PIN_28                ((uint32_t)0x10000000UL)  /* Pin 28 selected   */
#define GPIO_PIN_29                ((uint32_t)0x20000000UL)  /* Pin 29 selected   */
#define GPIO_PIN_30                ((uint32_t)0x40000000UL)  /* Pin 30 selected   */
#define GPIO_PIN_31                ((uint32_t)0x80000000UL)  /* Pin 31 selected   */
#define GPIO_PIN_ALL               ((uint32_t)0xFFFFFFFFUL)  /* All pins selected */

#define GPIO_PIN_MASK              (0xFFFFFFFFUL) /* PIN mask for assert test */
/**
  * @}
  */

/** @defgroup GPIO_mode GPIO mode
  * @{
  */
#define GPIO_MODE_INPUT_SW                   (MODE_INPUT | SRC_SW)                                                           /*!< Input Mode softwa source                                                      */
#define GPIO_MODE_INPUT_HW                   (MODE_INPUT | SRC_HW)                                                           /*!< Input Mode hardware source                                                    */
#define GPIO_MODE_OUTPUT_SW                  (MODE_OUTPUT | SRC_SW)                                                          /*!< Output Mode software source                                                   */
#define GPIO_MODE_OUTPUT_HW                  (MODE_OUTPUT | SRC_HW)                                                          /*!< Output Mode hardware source                                                   */
#define GPIO_MODE_IT_PL_SL_DE_SE             (MODE_INPUT | SRC_SW | POL_LOW  | SEN_LEVEL | DEB_EN | SYNC_EN | GPIO_IT_EN)    /*!< External Interrupt Mode with active-low, level, debounce, sync,               */
#define GPIO_MODE_IT_PH_SL_DE_SE             (MODE_INPUT | SRC_SW | POL_HIGH | SEN_LEVEL | DEB_EN | SYNC_EN | GPIO_IT_EN)    /*!< External Interrupt Mode with active-high, level, debounce, sync,              */
#define GPIO_MODE_IT_PL_SE_DE_SE             (MODE_INPUT | SRC_SW | POL_LOW  | SEN_EDGE  | DEB_EN | SYNC_EN | GPIO_IT_EN)    /*!< External Interrupt Mode with active-low, edge,  debounce, sync,               */
#define GPIO_MODE_IT_PH_SE_DE_SE             (MODE_INPUT | SRC_SW | POL_HIGH | SEN_EDGE  | DEB_EN | SYNC_EN | GPIO_IT_EN)    /*!< External Interrupt Mode with active-high, edge,  debounce, sync,              */
#define GPIO_MODE_IT_PL_SL_DN_SE             (MODE_INPUT | SRC_SW | POL_LOW  | SEN_LEVEL | DEB_NO | SYNC_EN | GPIO_IT_EN)    /*!< External Interrupt Mode with active-low, level, no debounce, sync,            */
#define GPIO_MODE_IT_PH_SL_DN_SE             (MODE_INPUT | SRC_SW | POL_HIGH | SEN_LEVEL | DEB_NO | SYNC_EN | GPIO_IT_EN)    /*!< External Interrupt Mode with active-high, level, no debounce, sync,           */
#define GPIO_MODE_IT_PL_SE_DN_SE             (MODE_INPUT | SRC_SW | POL_LOW  | SEN_EDGE  | DEB_NO | SYNC_EN | GPIO_IT_EN)    /*!< External Interrupt Mode with active-low, edge,  no debounce, sync,            */
#define GPIO_MODE_IT_PH_SE_DN_SE             (MODE_INPUT | SRC_SW | POL_HIGH | SEN_EDGE  | DEB_NO | SYNC_EN | GPIO_IT_EN)    /*!< External Interrupt Mode with active-high, edge,  no debounce, sync,           */
#define GPIO_MODE_IT_PL_SL_DE_SN             (MODE_INPUT | SRC_SW | POL_LOW  | SEN_LEVEL | DEB_EN | SYNC_NO | GPIO_IT_EN)    /*!< External Interrupt Mode with active-low, level, debounce, no sync,            */
#define GPIO_MODE_IT_PH_SL_DE_SN             (MODE_INPUT | SRC_SW | POL_HIGH | SEN_LEVEL | DEB_EN | SYNC_NO | GPIO_IT_EN)    /*!< External Interrupt Mode with active-high, level, debounce, no sync,           */
#define GPIO_MODE_IT_PL_SE_DE_SN             (MODE_INPUT | SRC_SW | POL_LOW  | SEN_EDGE  | DEB_EN | SYNC_NO | GPIO_IT_EN)    /*!< External Interrupt Mode with active-low, edge,  debounce, no sync,            */
#define GPIO_MODE_IT_PH_SE_DE_SN             (MODE_INPUT | SRC_SW | POL_HIGH | SEN_EDGE  | DEB_EN | SYNC_NO | GPIO_IT_EN)    /*!< External Interrupt Mode with active-high, edge,  debounce, no sync,           */
#define GPIO_MODE_IT_PL_SL_DN_SN             (MODE_INPUT | SRC_SW | POL_LOW  | SEN_LEVEL | DEB_NO | SYNC_NO | GPIO_IT_EN)    /*!< External Interrupt Mode with active-low, level, no debounce, no sync,         */
#define GPIO_MODE_IT_PH_SL_DN_SN             (MODE_INPUT | SRC_SW | POL_HIGH | SEN_LEVEL | DEB_NO | SYNC_NO | GPIO_IT_EN)    /*!< External Interrupt Mode with active-high, level, no debounce, no sync,        */
#define GPIO_MODE_IT_PL_SE_DN_SN             (MODE_INPUT | SRC_SW | POL_LOW  | SEN_EDGE  | DEB_NO | SYNC_NO | GPIO_IT_EN)    /*!< External Interrupt Mode with active-low, dege,  no debounce, no sync,         */
#define GPIO_MODE_IT_PH_SE_DN_SN             (MODE_INPUT | SRC_SW | POL_HIGH | SEN_EDGE  | DEB_NO | SYNC_NO | GPIO_IT_EN)    /*!< External Interrupt Mode with active-high, dege,  no debounce, no sync,        */
/**
  * @}
  */

/** @defgroup GPIO_source GPIO source
  * @brief GPIO software source or hardware source
  * @{
  */
#define GPIO_SRC_SW                    (0x00000000UL)                          /*!< Software source  */
#define GPIO_SRC_HW                    (0x00000001UL)                          /*!< Harware source   */
/**
  * @}
  */

/** @defgroup GPIO_mode
  * @brief GPIO Iuput/output mode
  * @{
  */
#define GPIO_MODE_INPUT                (0x00000000UL)                          /*!< Input mode  */
#define GPIO_MODE_OUTPUT               (0x00000001UL)                          /*!< Output mode   */
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

/**
  * @brief  Check whether the specified EXTI line is rising edge asserted or not.
  * @param  __ICTL_LINE__ specifies the EXTI line to check.
  *          This parameter can be GPIO_PIN_x where x can be(0..31)
  * @retval The new state of __EXTI_LINE__ (SET or RESET).
  */
#define __HAL_GPIO_ICTL_GET_IT(__ICTL_LINE__)         READ_BIT(ICTL->IRQFINALSTATUSH, (__ICTL_LINE__))

/**
  * @brief  Clear the EXTI line falling pending bits.
  * @param  __ICTL_LINE__ specifies the EXTI lines to clear.
  *          This parameter can be any combination of GPIO_PIN_x where x can be (0..31)
  * @retval None
  */
#define __HAL_GPIO_CLEAR_IT(__ICTL_LINE__)            SET_BIT(GPIOAUX->EOIA, (__ICTL_LINE__))

/**
  * @brief  Generate a Software interrupt on selected EXTI line.
  * @param __ICTL_LINE__ specifies the EXTI line to check.
  *          This parameter can be GPIO_PIN_x where x can be(0..31)
  * @retval None
  */
#define __HAL_GPIO_ICTL_GENERATE_SWIT(__ICTL_LINE__)  SET_BIT(ICTL->IRQINTFORCEH, (__ICTL_LINE__))

/**
  * @brief  Check whether the specified EXTI line flag is set or not.
  * @param  __ICTL_LINE__ specifies the EXTI line flag to check.
  *         This parameter can be GPIO_PIN_x where x can be(0..31)
  * @retval The new state of __ICTL_LINE__ (SET or RESET).
  */
#define __HAL_GPIO_ICTL_GET_FLAG(__ICTL_LINE__)       READ_BIT(ICTL->IRQSTATUSH, (__ICTL_LINE__))

/**
  * @brief  Clear the EXTI line pending flags.
  * @param  __ICTL_LINE__ specifies the EXTI lines flags to clear.
  *         This parameter can be any combination of GPIO_PIN_x where x can be (0..31)
  * @retval None
  */
#define __HAL_GPIO_ICTL_CLEAR_FLAG(__ICTL_LINE__)     __HAL_GPIO_CLEAR_IT(__ICTL_LINE__)

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup GPIO_Private_Constants GPIO Private Constants
  * @note  HAL GPIO State value is coding follow below described bitmap :
  *            b20  Interrupt no used/enable
  *              0 : not used for interrupt
  *              1 : enable interrupt
  *            b19  Interrupt sync no used/enable
  *              0 : no sync
  *              1 : enable sync
  *            b18  Interrupt debounce no used/enable
  *              0 : no debounce
  *              1 : enable debounce
  *            b17  Interrupt sensitive level/edge
  *              0 : level
  *              1 : edge
  *            b16  Interrupt polarity low/high
  *              0 : low
  *              1 : high
  *             b4  source
  *              0 : software
  *              1 : hardware
  *             b0  mode
  *              0 : input
  *              1 : output
  * @{
  */
#define GPIO_MODE_Pos                           (0u)
#define GPIO_MODE                               (0x1uL << GPIO_MODE_Pos)
#define MODE_INPUT                              (0x0uL << GPIO_MODE_Pos)
#define MODE_OUTPUT                             (0x1uL << GPIO_MODE_Pos)
#define SOURCE_TYPE_Pos                         (4u)
#define SOURCE_TYPE                             (0x1uL << SOURCE_TYPE_Pos)
#define SRC_SW                                  (0x0uL << SOURCE_TYPE_Pos)
#define SRC_HW                                  (0x1uL << SOURCE_TYPE_Pos)
#define INT_MODE_Pos                            (16u)
#define INT_MODE                                (0xFuL << INT_MODE_Pos)
#define POL_LOW                                 (0x0uL << INT_MODE_Pos)
#define POL_HIGH                                (0x1uL << INT_MODE_Pos)
#define SEN_LEVEL                               (0x0uL << INT_MODE_Pos)
#define SEN_EDGE                                (0x2uL << INT_MODE_Pos)
#define DEB_NO                                  (0x0uL << INT_MODE_Pos)
#define DEB_EN                                  (0x4uL << INT_MODE_Pos)
#define SYNC_NO                                 (0x0uL << INT_MODE_Pos)
#define SYNC_EN                                 (0x8uL << INT_MODE_Pos)
#define GPIO_IT_MODE_Pos                        (20u)
#define GPIO_IT_MODE                            (0x1uL << GPIO_IT_MODE_Pos)
#define GPIO_IT_NO                              (0x0uL << GPIO_IT_MODE_Pos)
#define GPIO_IT_EN                              (0x1uL << GPIO_IT_MODE_Pos)
/**
  * @}
  */

/** @defgroup GPIO_Private_Macros GPIO Private Macros
  * @{
  */
#define IS_GPIO_PIN_ACTION(ACTION)  (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET))

#define IS_GPIO_PIN(__PIN__)        ((((uint32_t)(__PIN__) & GPIO_PIN_MASK) != 0x00u) &&\
                                     (((uint32_t)(__PIN__) & ~GPIO_PIN_MASK) == 0x00u))

#define IS_GPIO_MODE(__MODE__)      (((__MODE__) == GPIO_MODE_INPUT_SW)           ||\
                                     ((__MODE__) == GPIO_MODE_INTUT_HW)           ||\
                                     ((__MODE__) == GPIO_MODE_OUTPUT_SW)          ||\
                                     ((__MODE__) == GPIO_MODE_OUTPUT_HW)          ||\
                                     ((__MODE__) == GPIO_MODE_IT_PL_SL_DE_SE)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PH_SL_DE_SE)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PL_SE_DE_SE)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PH_SE_DE_SE)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PL_SL_DN_SE)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PH_SL_DN_SE)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PL_SE_DN_SE)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PH_SE_DN_SE)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PL_SL_DE_SN)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PH_SL_DE_SN)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PL_SE_DE_SN)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PH_SE_DE_SN)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PL_SL_DN_SN)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PH_SL_DN_SN)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PL_SE_DN_SN)     ||\
                                     ((__MODE__) == GPIO_MODE_IT_PH_SE_DN_SN))

#define IS_GPIO_SOURCE(__SOURCE__)  (((__SOURCE__) == GPIO_SRC_SW)           ||\
                                     ((__SOURCE__) == GPIO_SRC_HW))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup GPIO_Exported_Functions GPIO Exported Functions
  * @{
  */

/** @defgroup GPIO_Exported_Functions_Group1 Initialization/de-initialization functions
 *  @brief    Initialization and Configuration functions
 * @{
 */

/* Initialization and de-initialization functions *****************************/
void              HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void              HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions_Group2 IO operation functions
 *  @brief    IO operation functions
 * @{
 */

/* IO operation functions *****************************************************/
GPIO_PinState     HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
void              HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIO_PinState PinState);
void              HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
void              HAL_GPIO_IRQHandler(uint32_t GPIO_Pin);
void              HAL_GPIO_Callback(uint32_t GPIO_Pin);

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

#endif /* XT32H0xx_HAL_GPIO_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
