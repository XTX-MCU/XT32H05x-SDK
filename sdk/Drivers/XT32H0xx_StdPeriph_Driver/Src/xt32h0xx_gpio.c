/**
  ******************************************************************************
  * @file    xt32h0xx_gpio.c
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the GPIO peripheral
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_gpio.h"
#include "xt32h0xx_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup GPIO GPIO
  * @brief GPIO driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup GPIO_Exported_Functions GPIO Exported Functions
  * @{
  */

/** @defgroup GPIO_Exported_Functions_Group1 Initialization and Configuration
 *  @brief   Initialization and Configuration
 *
@verbatim
 ===============================================================================
                    ##### Initialization and Configuration #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the GPIOx peripheral according to the specified 
  *         parameters in the GPIO_InitStruct.
  * @param  GPIOx:   
  * @param  GPIO_InitStruct:
  */
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_InitStruct->Pin));
  assert_param(IS_GPIO_MODE(GPIO_InitStruct->Mode));
  assert_param(IS_GPIO_SOURCE(GPIO_InitStruct->Source));

  /*-------------------------- Configure the port pins -----------------------*/
  /*-- GPIO Mode Configuration --*/
  for (pinpos = 0x00; pinpos < 0x20; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;

    /* Get the port pins position */
    currentpin = (GPIO_InitStruct->Pin) & pos;

    if (currentpin == pos)
    {
      tempr =  GPIOx->DDR;
      tempr &= (uint32_t)~((uint32_t)currentpin);
      tempr |= ((uint32_t)GPIO_InitStruct->Mode << pinpos);
      GPIOx->DDR = tempr;

      tempr =  GPIOx->CTL;
      tempr &= (uint32_t)~((uint32_t)currentpin);
      tempr |= ((uint32_t)GPIO_InitStruct->Source << pinpos);
      GPIOx->CTL = tempr;
    }
  }
}

/**
  * @brief  Fills each GPIO_InitStruct member with its default value.
  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure which will 
  *         be initialized.
  */
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
  /* Reset GPIO init structure parameters values */
  GPIO_InitStruct->Pin  = GPIO_PIN_ALL;
  GPIO_InitStruct->Mode = GPIO_Mode_IN;
  GPIO_InitStruct->Source = GPIO_Source_SW;
}

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions_Group2 GPIO Read and Write
 *  @brief   GPIO Read and Write
 *
@verbatim   
 ===============================================================================
                      ##### GPIO Read and Write #####
 ===============================================================================  
    [..] How to use functions
    
         (+) Read GPIO port input Data using GPIO_ReadInputData(port),
             GPIO_ReadOutputData(port) functions
         (+) Read GPIO pin input data using GPIO_ReadInputDataBit(port pin), 
             GPIO_ReadOutputDataBit(port, pin) functions
         (+) Write GPIO port output data using GPIO_Writed(port) functions
         (+) Write GPIO pin output data using GPIO_SetBits(port, pin),
             GPIO_ResetBits(port, pin), GPIO_WriteBit(port, pin, value) 
             functions
@endverbatim
  * @{
  */

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx: where x can be (A, B, C, D) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to read.
  * @retval The input port pin value.
  */
uint32_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin)
{
  uint32_t bitstatus = 0x00;
  uint32_t* reg = 0;

  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

  reg = (uint32_t*)(((uint32_t*)&(GPIOAUX->EXTA)) + GPIO_GET_PORT_OFFSET(GPIOx));

  if ((*reg & GPIO_Pin) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint32_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint32_t)Bit_RESET;
  }
  return bitstatus;
}

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx: where x can be (A, B, C, D) to select the GPIO peripheral.
  * @retval The input port pin value.
  */
uint32_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
{
  uint32_t* reg = 0;

  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  reg = (uint32_t*)(((uint32_t*)&(GPIOAUX->EXTA)) + GPIO_GET_PORT_OFFSET(GPIOx));

  return ((uint32_t)*reg);
}

/**
  * @brief  Reads the specified output data port bit.
  * @param  GPIOx: where x can be (A, B, C, D) to select the GPIO peripheral.
  * @param  GPIO_Pin: Specifies the port bit to read.
  * @retval The output port pin value.
  */
uint32_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin)
{
  uint32_t bitstatus = 0x00;
  uint32_t* reg = 0;

  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

  reg = (uint32_t*)(((uint32_t*)&(GPIOAUX->EXTA)) + GPIO_GET_PORT_OFFSET(GPIOx));

  if ((*reg & GPIO_Pin) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint32_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint32_t)Bit_RESET;
  }
  return bitstatus;
}

/**
  * @brief  Reads the specified GPIO output data port.
  * @param  GPIOx: where x can be (A, B, C, D) to select the GPIO peripheral.
  * @retval GPIO output data port value.
  */
uint32_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
{
  uint32_t* reg = 0;

  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  
  reg = (uint32_t*)(((uint32_t*)&(GPIOAUX->EXTA)) + GPIO_GET_PORT_OFFSET(GPIOx));

  return ((uint32_t)*reg);
}

/**
  * @brief  Sets the selected data port bits.
  * @param  GPIOx: where x can be (A, B, C, D) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  */
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  GPIOx->DR |= GPIO_Pin;
}

/**
  * @brief  Clears the selected data port bits.
  * @param  GPIOx: where x can be (A, B, C, D) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bits to be written.
  */
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  GPIOx->DR &= (uint32_t)~((uint32_t)GPIO_Pin);
}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  GPIOx: where x can be (A, B, C, D) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  * @param  BitVal: specifies the value to be written to the selected bit.
  *          This parameter can be one of the BitAction enumeration values:
  *            @arg Bit_RESET: to clear the port pin
  *            @arg Bit_SET: to set the port pin
  */
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, BitAction BitVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
  assert_param(IS_GPIO_BIT_ACTION(BitVal));

  if (BitVal != Bit_RESET)
  {
    GPIOx->DR |= (uint32_t)GPIO_Pin;
  }
  else
  {
    GPIOx->DR &= (uint32_t)~((uint32_t)GPIO_Pin);
  }
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A, B, C, D) to select the GPIO peripheral.
  * @param  PortVal: specifies the value to be written to the port output data register.
  */
void GPIO_Write(GPIO_TypeDef* GPIOx, uint32_t PortVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  GPIOx->DR = PortVal;
}

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions_Group3 GPIO Interrupt management functions
 *  @brief   GPIOInterrupt management functions
 *
@verbatim   
 ===============================================================================
          ##### GPIO Interrupt management functions #####
 ===============================================================================  
    [..] How to use GPIO interrupt
    
         (+) Initial GPIO interrupt using GPIO_InterruptStructInit(init) function
         (+) Config the interupt using GPIO_InterruptConfig(init) function.
             Config SYSCFG and ICTL the GPIO interrupt source.
         (+) Unmask the interrupt using GPIO_InterruptUnmask(pin) function
         (+) Enable the interrupt using GPIO_InterruptEnable(pin) function
             Response the interrupt by ICTL IRQ Handle
         (+) Clear the interrupt using GPIO_ClearITFlag(pin) function

@endverbatim
  * @{
  */

/**
  * @brief  Configure interupt to the specified GPIOA data port.
  * @param  GPIO_IntCfg: 
  */
void GPIO_InterruptConfig(GPIOInt_TypeDef* GPIO_IntCfg)
{
  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

  uint32_t tempr;

  /* Check the parameters */
  assert_param(IS_GPIO_PIN(GPIO_IntCfg->Pin));
  assert_param(IS_GPIO_INTTYPE(GPIO_IntCfg->Type));
  assert_param(IS_GPIO_INTPOL(GPIO_IntCfg->Polarity));
  assert_param(IS_GPIO_INTDEB(GPIO_IntCfg->Debounce));
  assert_param(IS_GPIO_INTSYNC(GPIO_IntCfg->Sync));

  for (pinpos = 0x00; pinpos < 0x20; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;

    /* Get the port pins position */
    currentpin = (GPIO_IntCfg->Pin) & pos;

    if (currentpin == pos)
    {
      tempr = GPIOAUX->INTLVL;
      tempr &= (uint32_t)~((uint32_t)currentpin); 
      tempr |= ((uint32_t)GPIO_IntCfg->Type << pinpos);
      GPIOAUX->INTLVL = tempr;

      tempr = GPIOAUX->INTPOL;
      tempr &= (uint32_t)~((uint32_t)currentpin); 
      tempr |= ((uint32_t)GPIO_IntCfg->Polarity << pinpos);
      GPIOAUX->INTPOL = tempr;

      tempr = GPIOAUX->DEBOU;
      tempr &= (uint32_t)~((uint32_t)currentpin); 
      tempr |= ((uint32_t)GPIO_IntCfg->Debounce << pinpos);
      GPIOAUX->DEBOU = tempr;

      tempr = GPIOAUX->LSSYNC;
      tempr &= (uint32_t)~((uint32_t)currentpin); 
      tempr |= ((uint32_t)GPIO_IntCfg->Sync << pinpos);
      GPIOAUX->LSSYNC = tempr;
    }
  }
}

/**
  * @brief  Fills each GPIO_IntCfg member with its default value.
  * @param  GPIO_IntCfg: pointer to a GPIOInt_TypeDef structure which will 
  *         be initialized.
  */
void GPIO_InterruptStructInit(GPIOInt_TypeDef* GPIO_IntCfg)
{
  GPIO_IntCfg->Pin  = GPIO_PIN_ALL;
  GPIO_IntCfg->Type = GPIO_IntType_LEVEL;
  GPIO_IntCfg->Polarity = GPIO_IntPol_HIGH;
  GPIO_IntCfg->Debounce = GPIO_IntDeb_DISABLE;
  GPIO_IntCfg->Sync = GPIO_IntSync_NO;
}

/**
  * @brief  Enable interrupt.
  * @param  GPIO_Pin: 
  */
void GPIO_InterruptEnable(uint32_t GPIO_Pin)
{
  GPIOAUX->INTEN |= (uint32_t)GPIO_Pin;
}

/**
  * @brief  Disable interrupt.
  * @param  GPIO_Pin: 
  */
void GPIO_InterruptDisable(uint32_t GPIO_Pin)
{
  GPIOAUX->INTEN &= (uint32_t)~((uint32_t)GPIO_Pin);
}

/**
  * @brief  Mask interrupt.
  * @param  GPIO_Pin: 
  */
void GPIO_InterruptMask(uint32_t GPIO_Pin)
{
  GPIOAUX->INTMSK |= (uint32_t)GPIO_Pin;
}

/**
  * @brief  Mask interrupt.
  * @param  GPIO_Pin: 
  */
void GPIO_InterruptUnmask(uint32_t GPIO_Pin)
{
  GPIOAUX->INTMSK &= (uint32_t)~((uint32_t)GPIO_Pin);
}

/**
  * @brief  Get interrupt flag.
  * @param  GPIO_Pin: 
  */
ITStatus GPIO_GetITFlag(uint32_t GPIO_Pin)
{
  ITStatus res = RESET;
  if(GPIOAUX->INTSTA & GPIO_Pin)
  {
    res = SET;
  }
  return res;
}

/**
  * @brief  Get interrupt status.
  * @param  GPIO_Pin: 
  */
FlagStatus GPIO_GetITStatus(uint32_t GPIO_Pin)
{
  FlagStatus res = RESET;
  if(GPIOAUX->INTRAWSTA & GPIO_Pin)
  {
    res = SET;
  }

  return res;
}

/**
  * @brief  Clear interrupt flag.
  * @param  GPIO_Pin: 
  */
void GPIO_ClearITFlag(uint32_t GPIO_Pin)
{
  GPIOAUX->EOIA |= GPIO_Pin;
}

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

