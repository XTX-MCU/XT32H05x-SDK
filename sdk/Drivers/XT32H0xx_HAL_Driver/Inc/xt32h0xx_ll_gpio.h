/**
  ******************************************************************************
  * @file    xt32h0xx_ll_gpio.h
  * @author  Software Team
  * @brief   Header file of GPIO LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_GPIO_H
#define XT32H0xx_LL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOAUX)

/** @defgroup GPIO_LL GPIO
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_Private_Macros GPIO Private Macros
  * @{
  */

/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Types GPIO Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_ES_INIT GPIO Exported Init structures
  * @{
  */

/**
  * @brief LL GPIO Init Structure definition
  */
typedef struct
{
  uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                              This parameter can be any value of @ref GPIO_LL_EC_PIN */

  uint32_t Mode;         /*!< Specifies the operating mode for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_MODE.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinMode().*/

  uint32_t Source;       /*!< Specifies the Peripheral to be connected to the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_SRC.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinSource(). */
} LL_GPIO_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Constants GPIO Exported Constants
  * @{
  */

/** @defgroup GPIO_LL_EC_PIN PIN
  * @{
  */
#define LL_GPIO_PIN_0                  GPIO_DR_B_0                             /*!< Select pin 0 */
#define LL_GPIO_PIN_1                  GPIO_DR_B_1                             /*!< Select pin 1 */
#define LL_GPIO_PIN_2                  GPIO_DR_B_2                             /*!< Select pin 2 */
#define LL_GPIO_PIN_3                  GPIO_DR_B_3                             /*!< Select pin 3 */
#define LL_GPIO_PIN_4                  GPIO_DR_B_4                             /*!< Select pin 4 */
#define LL_GPIO_PIN_5                  GPIO_DR_B_5                             /*!< Select pin 5 */
#define LL_GPIO_PIN_6                  GPIO_DR_B_6                             /*!< Select pin 6 */
#define LL_GPIO_PIN_7                  GPIO_DR_B_7                             /*!< Select pin 7 */
#define LL_GPIO_PIN_8                  GPIO_DR_B_8                             /*!< Select pin 8 */
#define LL_GPIO_PIN_9                  GPIO_DR_B_9                             /*!< Select pin 9 */
#define LL_GPIO_PIN_10                 GPIO_DR_B_10                            /*!< Select pin 10 */
#define LL_GPIO_PIN_11                 GPIO_DR_B_11                            /*!< Select pin 11 */
#define LL_GPIO_PIN_12                 GPIO_DR_B_12                            /*!< Select pin 12 */
#define LL_GPIO_PIN_13                 GPIO_DR_B_13                            /*!< Select pin 13 */
#define LL_GPIO_PIN_14                 GPIO_DR_B_14                            /*!< Select pin 14 */
#define LL_GPIO_PIN_15                 GPIO_DR_B_15                            /*!< Select pin 15 */
#define LL_GPIO_PIN_16                 GPIO_DR_B_16                            /*!< Select pin 16 */
#define LL_GPIO_PIN_17                 GPIO_DR_B_17                            /*!< Select pin 17 */
#define LL_GPIO_PIN_18                 GPIO_DR_B_18                            /*!< Select pin 18 */
#define LL_GPIO_PIN_19                 GPIO_DR_B_19                            /*!< Select pin 19 */
#define LL_GPIO_PIN_20                 GPIO_DR_B_20                            /*!< Select pin 20 */
#define LL_GPIO_PIN_21                 GPIO_DR_B_21                            /*!< Select pin 21 */
#define LL_GPIO_PIN_22                 GPIO_DR_B_22                            /*!< Select pin 22 */
#define LL_GPIO_PIN_23                 GPIO_DR_B_23                            /*!< Select pin 23 */
#define LL_GPIO_PIN_24                 GPIO_DR_B_24                            /*!< Select pin 24 */
#define LL_GPIO_PIN_25                 GPIO_DR_B_25                            /*!< Select pin 25 */
#define LL_GPIO_PIN_26                 GPIO_DR_B_26                            /*!< Select pin 26 */
#define LL_GPIO_PIN_27                 GPIO_DR_B_27                            /*!< Select pin 27 */
#define LL_GPIO_PIN_28                 GPIO_DR_B_28                            /*!< Select pin 28 */
#define LL_GPIO_PIN_29                 GPIO_DR_B_29                            /*!< Select pin 29 */
#define LL_GPIO_PIN_30                 GPIO_DR_B_30                            /*!< Select pin 30 */
#define LL_GPIO_PIN_31                 GPIO_DR_B_31                            /*!< Select pin 31 */
#define LL_GPIO_PIN_ALL                (GPIO_DR_B_0 | GPIO_DR_B_1  | GPIO_DR_B_2  | \
                                        GPIO_DR_B_3  | GPIO_DR_B_4  | GPIO_DR_B_5  | \
                                        GPIO_DR_B_6  | GPIO_DR_B_7  | GPIO_DR_B_8  | \
                                        GPIO_DR_B_9  | GPIO_DR_B_10 | GPIO_DR_B_11 | \
                                        GPIO_DR_B_12 | GPIO_DR_B_13 | GPIO_DR_B_14 | \
                                        GPIO_DR_B_15 | GPIO_DR_B_16 | GPIO_DR_B_17 | \
                                        GPIO_DR_B_18 | GPIO_DR_B_19 | GPIO_DR_B_20 | \
                                        GPIO_DR_B_21 | GPIO_DR_B_22 | GPIO_DR_B_23 | \
                                        GPIO_DR_B_24 | GPIO_DR_B_25 | GPIO_DR_B_26 | \
                                        GPIO_DR_B_27 | GPIO_DR_B_28 | GPIO_DR_B_29 | \
                                        GPIO_DR_B_30 | GPIO_DR_B_31)           /*!< Select all pins */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_MODE Mode
  * @{
  */
#define LL_GPIO_MODE_INPUT             (0x00000000UL)                           /*!< Select input mode */
#define LL_GPIO_MODE_OUTPUT            (0x00000001UL)                           /*!< Select output mode */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_SRC Mode
  * @{
  */
#define LL_GPIO_SRC_SW                 (0x00000000UL)                           /*!< Select software source */
#define LL_GPIO_SRC_HW                 (0x00000001UL)                           /*!< Select hardware source */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_Interrupt_Sensor Interrupt level 
  * @{
  */
#define LL_GPIO_INTTYPE_LEVEL          (0x00000000UL) 
#define LL_GPIO_INTTYPE_EDGE           (0x00000001UL) 
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_Interrupt_Polarity Interrupt Polarity 
  * @{
  */
#define LL_GPIO_INTPOLARITY_LOW        (0x00000000UL) 
#define LL_GPIO_INTPOLARITY_HIGH       (0x00000001UL) 
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_Interrupt_Debounce Interrupt Debounce 
  * @{
  */
#define LL_GPIO_INT_NO_DEBOUNCE        (0x00000000UL) 
#define LL_GPIO_INT_DEBOUNCE           (0x00000001UL) 
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_Interrupt_Synchronize Interrupt Synchronize 
  * @{
  */
#define LL_GPIO_INT_NO_SYNC            (0x00000000UL) 
#define LL_GPIO_INT_SYNC               (0x00000001UL) 
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Macros GPIO Exported Macros
  * @{
  */

/** @defgroup GPIO_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_GPIO_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_GPIO_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup GPIO_LL_EM_PinIdx Get Pin index Macros
  * @{
  */
/**
  * @brief  Get pin index
  * @param  __PINMASK__ GPIO Instance
  * @retval pin index
  */
#define LL_GPIO_GETPININDEX(__PINMASK__) (((__PINMASK__) == LL_GPIO_PIN_0) ? 0 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_1) ? 1 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_2) ? 2 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_3) ? 3 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_4) ? 4 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_5) ? 5 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_6) ? 6 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_7) ? 7 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_8) ? 8 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_9) ? 9 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_10) ? 10 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_11) ? 11 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_12) ? 12 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_13) ? 13 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_14) ? 14 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_15) ? 15 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_16) ? 16 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_17) ? 17 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_18) ? 18 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_19) ? 19 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_20) ? 20 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_21) ? 21 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_22) ? 22 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_23) ? 23 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_24) ? 24 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_25) ? 25 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_26) ? 26 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_27) ? 27 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_28) ? 28 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_29) ? 29 : \
                                          ((__PINMASK__) == LL_GPIO_PIN_30) ? 30 : \
                                          31)
/**
  * @}
  */

/** @defgroup GPIO_LL_EM_PinPosdx Get Pin position Macros
  * @{
  */
/**
  * @brief  Get pin position
  * @param  __PINMASK__ GPIO Instance
  * @retval pin position
  */
#define LL_GPIO_GETPINPOS(__PINMASK__) LL_GPIO_GETPININDEX(__PINMASK__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Functions GPIO Exported Functions
  * @{
  */

/** @defgroup GPIO_LL_Exported_Functions_Group1 Port Configuration
  * @{
  */

/**
  * @brief  Configure gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll DDR        Pin         LL_GPIO_SetPinMode
  * @param  GPIOx GPIO module
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_MODE_INPUT
  *         @arg @ref LL_GPIO_MODE_OUTPUT
  */
__STATIC_INLINE void LL_GPIO_SetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
  MODIFY_REG(GPIOx->DDR, Pin, (Mode << LL_GPIO_GETPINPOS(Pin)));
}

/**
  * @brief  Return gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll DDR        Pin         LL_GPIO_GetPinMode
  * @param  GPIOx GPIO module
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_MODE_INPUT
  *         @arg @ref LL_GPIO_MODE_OUTPUT
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)((READ_BIT(GPIOx->DDR, Pin)) >> LL_GPIO_GETPINPOS(Pin));
}

/**
  * @brief  Configure gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll CTL        Pin         LL_GPIO_SetPinSource
  * @param  GPIOx GPIO module
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  * @param  Source This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_SRC_SW
  *         @arg @ref LL_GPIO_SRC_HW
  */
__STATIC_INLINE void LL_GPIO_SetPinSource(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Source)
{
  MODIFY_REG(GPIOx->CTL, Pin, (Source << LL_GPIO_GETPINPOS(Pin)));
}

/**
  * @brief  Return gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Input mode, General purpose output, Alternate function mode or Analog.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll CTL        Pin         LL_GPIO_GetPinSource
  * @param  GPIOx GPIO module
  * @param  Pin This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_SRC_SW
  *         @arg @ref LL_GPIO_SRC_HW
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinSource(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  return (uint32_t)((READ_BIT(GPIOx->CTL, Pin)) >> LL_GPIO_GETPINPOS(Pin));
}

/**
  * @}
  */

/** @defgroup GPIO_LL_EF_Data_Access Data Access
  * @{
  */

/**
  * @brief  Return full input data register value for a dedicated port.
  * @rmtoll EXTx          Pin           LL_GPIO_ReadInputPort
  * @param  GPIOx GPIO Port
  * @retval Input data register value of port
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadInputPort(GPIO_TypeDef *GPIOx)
{
  if(GPIOx == GPIOA)
  {
    return (uint32_t)(READ_REG(GPIOAUX->EXTA));
  }
  else if(GPIOx == GPIOB)
  {
    return (uint32_t)(READ_REG(GPIOAUX->EXTB));
  }
  else if(GPIOx == GPIOC)
  {
    return (uint32_t)(READ_REG(GPIOAUX->EXTC));
  }
  else if(GPIOx == GPIOD)
  {
    return (uint32_t)(READ_REG(GPIOAUX->EXTD));
  }
	else
	{
	  return 0;
  }
}

/**
  * @brief  Return if input data level for several pins of dedicated port is high or low.
  * @rmtoll EXTx          Pin           LL_GPIO_IsInputPinSet
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsInputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  if(GPIOx == GPIOA)
  {
    return (uint32_t)((READ_BIT(GPIOAUX->EXTA, PinMask) == (PinMask)) ? 1UL : 0UL);
  }
  else if(GPIOx == GPIOB)
  {
    return (uint32_t)((READ_BIT(GPIOAUX->EXTB, PinMask) == (PinMask)) ? 1UL : 0UL);
  }
  else if(GPIOx == GPIOC)
  {
    return (uint32_t)((READ_BIT(GPIOAUX->EXTC, PinMask) == (PinMask)) ? 1UL : 0UL);
  }
  else if(GPIOx == GPIOD)
  {
    return (uint32_t)((READ_BIT(GPIOAUX->EXTD, PinMask) == (PinMask)) ? 1UL : 0UL);
  }
	else
	{
	  return 0;
	}
}

/**
  * @brief  Write output data register for the port.
  * @rmtoll DR          Pin           LL_GPIO_WriteOutputPort
  * @param  GPIOx GPIO Port
  * @param  PortValue Level value for each pin of the port
  */
__STATIC_INLINE void LL_GPIO_WriteOutputPort(GPIO_TypeDef *GPIOx, uint32_t PortValue)
{
  WRITE_REG(GPIOx->DR, PortValue);
}

/**
  * @brief  Return full output data register value for a dedicated port.
  * @rmtoll EXTx          Pin           LL_GPIO_ReadOutputPort
  * @param  GPIOx GPIO Port
  * @retval Output data register value of port
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadOutputPort(GPIO_TypeDef *GPIOx)
{
  if(GPIOx == GPIOA)
  {
    return (uint32_t)(READ_REG(GPIOAUX->EXTA));
  }
  else if(GPIOx == GPIOB)
  {
    return (uint32_t)(READ_REG(GPIOAUX->EXTB));
  }
  else if(GPIOx == GPIOC)
  {
    return (uint32_t)(READ_REG(GPIOAUX->EXTC));
  }
  else if(GPIOx == GPIOD)
  {
    return (uint32_t)(READ_REG(GPIOAUX->EXTD));
  }
	else
	{
	  return 0;
	}
}

/**
  * @brief  Return if input data level for several pins of dedicated port is high or low.
  * @rmtoll EXTx          Pin           LL_GPIO_IsOutputPinSet
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_IsOutputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  if(GPIOx == GPIOA)
  {
    return (uint32_t)((READ_BIT(GPIOAUX->EXTA, PinMask) == (PinMask)) ? 1UL : 0UL);
  }
  else if(GPIOx == GPIOB)
  {
    return (uint32_t)((READ_BIT(GPIOAUX->EXTB, PinMask) == (PinMask)) ? 1UL : 0UL);
  }
  else if(GPIOx == GPIOC)
  {
    return (uint32_t)((READ_BIT(GPIOAUX->EXTC, PinMask) == (PinMask)) ? 1UL : 0UL);
  }
  else if(GPIOx == GPIOD)
  {
    return (uint32_t)((READ_BIT(GPIOAUX->EXTD, PinMask) == (PinMask)) ? 1UL : 0UL);
  }
	else
	{
	  return 0;
	}
}

/**
  * @brief  Set several pins to high level on dedicated gpio port.
  * @rmtoll DR         Pin           LL_GPIO_SetOutputPin
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  */
__STATIC_INLINE void LL_GPIO_SetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  SET_BIT(GPIOx->DR, PinMask);
}

/**
  * @brief  Set several pins to low level on dedicated gpio port.
  * @rmtoll DR          pin           LL_GPIO_ResetOutputPin
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  */
__STATIC_INLINE void LL_GPIO_ResetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  CLEAR_BIT(GPIOx->DR, PinMask);
}

/**
  * @brief  Toggle data value for several pin of dedicated port.
  * @rmtoll DR          pin           LL_GPIO_TogglePin
  * @param  GPIOx GPIO Port
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  */
__STATIC_INLINE void LL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  uint32_t odr = READ_REG(GPIOx->DR);
  WRITE_REG(GPIOx->DR, (odr & ~PinMask) | (~odr & PinMask));
}


/**
  * @}
  */
 
/** @defgroup GPIO_LL_Exported_Functions_Group2 Port A interrupt configuration
 * @{
 */

/**
  * @brief  Port A interrupt enable for each bit.
  * @rmtoll INTEN          bit           LL_GPIOA_EnableInterrupt
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  */
__STATIC_INLINE void LL_GPIOA_EnableInterrupt(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask)
{
  SET_BIT(GPIOAux->INTEN, PinMask);
}

/**
  * @brief  Port A interrupt disable for each bit.
  * @rmtoll INTEN          bit           LL_GPIOA_DisableInterrupt
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  */
__STATIC_INLINE void LL_GPIOA_DisableInterrupt(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask)
{
  CLEAR_BIT(GPIOAux->INTEN, PinMask);
}

/**
  * @brief  Check Port A interrupt is enabled for each bit.
  * @rmtoll INTEN          bit           LL_GPIOA_IsEnabledInterrupt
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval Status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_GPIOA_IsEnabledInterrupt(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask)
{
  return (uint32_t)((READ_BIT(GPIOAux->INTEN, PinMask)) ? 1UL : 0UL);
}

/**
  * @brief  Port A interrupt unmask for each bit.
  * @rmtoll INTMSK          bit           LL_GPIOA_UnmaskInterrupt
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  */
__STATIC_INLINE void LL_GPIOA_UnmaskInterrupt(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask)
{
  CLEAR_BIT(GPIOAux->INTMSK, PinMask);
}

/**
  * @brief  Port A interrupt mask for each bit.
  * @rmtoll INTMSK          bit           LL_GPIOA_MaskInterrupt
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  */
__STATIC_INLINE void LL_GPIOA_MaskInterrupt(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask)
{
  SET_BIT(GPIOAux->INTMSK, PinMask);
}

/**
  * @brief  Port A interrupt mask for each bit.
  * @rmtoll INTLVL          bit           LL_GPIOA_ConfigInterrupt\n
  * @rmtoll INTPOL          bit           LL_GPIOA_ConfigInterrupt\n
  * @rmtoll DEBEN           bit           LL_GPIOA_ConfigInterrupt
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  * @param Type This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_INTTYPE_LEVEL
  *         @arg @ref LL_GPIO_INTTYPE_EDGE
  * @param Polarity This parameter can one of the following values:
  *         @arg @ref LL_GPIO_INTPOLARITY_LOW
  *         @arg @ref LL_GPIO_INTPOLARITY_HIGH
  * @param Debounce This parameter can one of the following values:
  *         @arg @ref LL_GPIO_INT_NO_DEBOUNCE
  *         @arg @ref LL_GPIO_INT_DEBOUNCE
  * @param Sync This parameter can onen of the following values:
  *         @arg @ref LL_GPIO_INT_NO_SYNC
  *         @arg @ref LL_GPIO_INT_SYNC
  */
__STATIC_INLINE void LL_GPIOA_ConfigInterrupt(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask, uint32_t Type, uint32_t Polarity, uint32_t Debounce, uint32_t Sync)
{
  if(Type == LL_GPIO_INTTYPE_EDGE)
  {
    SET_BIT(GPIOAux->INTLVL, PinMask);
  }
  else
  {
    CLEAR_BIT(GPIOAux->INTLVL, PinMask);
  }

  if(Polarity == LL_GPIO_INTPOLARITY_HIGH)
  {
    SET_BIT(GPIOAux->INTPOL, PinMask);
  }
  else
  {
    CLEAR_BIT(GPIOAux->INTPOL, PinMask);
  }

  if(Debounce == LL_GPIO_INT_DEBOUNCE)
  {
    SET_BIT(GPIOAux->DEBOU,  PinMask);
  }
  else
  {
    CLEAR_BIT(GPIOAux->DEBOU,  PinMask);
  }

  if(Sync == LL_GPIO_INT_SYNC)
  {
    SET_BIT(GPIOAux->LSSYNC,  PinMask);
  }
  else
  {
    CLEAR_BIT(GPIOAux->LSSYNC,  PinMask);
  }
}

/**
  * @brief  Port A interrupt clear for each bit.
  * @rmtoll EOIA          bit           LL_GPIOA_ClearInterrupt
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  */
__STATIC_INLINE void LL_GPIOA_ClearInterrupt(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask)
{
  SET_BIT(GPIOAux->EOIA, PinMask);
}

/**
  * @brief  Port A Get interrupt Status for each bit.
  * @rmtoll INTSTA          bit           LL_GPIOA_GetInterruptStatus
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_GPIOA_GetInterruptStatus(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask)
{
  return (uint32_t)((READ_BIT(GPIOAux->INTSTA, PinMask))? 1UL : 0UL);
}

/**
  * @brief  Port A Get interrupt flag for each bit.
  * @rmtoll INTRAWSTA          bit           LL_GPIOA_GetInterruptFlag
  * @param  GPIOAux GPIO handle
  * @param  PinMask This parameter can be a combination of the following values:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_16
  *         @arg @ref LL_GPIO_PIN_17
  *         @arg @ref LL_GPIO_PIN_18
  *         @arg @ref LL_GPIO_PIN_19
  *         @arg @ref LL_GPIO_PIN_20
  *         @arg @ref LL_GPIO_PIN_21
  *         @arg @ref LL_GPIO_PIN_22
  *         @arg @ref LL_GPIO_PIN_23
  *         @arg @ref LL_GPIO_PIN_24
  *         @arg @ref LL_GPIO_PIN_25
  *         @arg @ref LL_GPIO_PIN_26
  *         @arg @ref LL_GPIO_PIN_27
  *         @arg @ref LL_GPIO_PIN_28
  *         @arg @ref LL_GPIO_PIN_29
  *         @arg @ref LL_GPIO_PIN_30
  *         @arg @ref LL_GPIO_PIN_31
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_GPIOA_GetInterruptFlag(GPIO_AUX_TypeDef* GPIOAux, uint32_t PinMask)
{
  return (uint32_t) ((READ_BIT(GPIOAux->INTRAWSTA, PinMask)) ? 1UL : 0UL);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_Exported_Functions_Group3 Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_GPIO_DeInit(GPIO_TypeDef *GPIOx);
ErrorStatus LL_GPIO_Init(GPIO_TypeDef *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct);
void        LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct);

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

#endif /* defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOAUX) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_GPIO_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
