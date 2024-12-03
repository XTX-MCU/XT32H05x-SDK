/**
  ******************************************************************************
  * @file    xt32h0xx_hal_gpio.c
  * @author  Software Team
  * @brief   GPIO HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the General Purpose Input/Output (GPIO) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

#ifdef HAL_GPIO_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private defines ------------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup GPIO_Exported_Functions
  * @{
  */

/** @addtogroup GPIO_Exported_Functions_Group1
 *  @brief    Initialization and Configuration functions
 *
@verbatim
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the GPIOx peripheral according to the specified parameters in the GPIO_Init.
  * @param  GPIOx where x can be (A..F) to select the GPIO peripheral for XT32H0xx family
  * @param  GPIO_Init pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  */
void HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
  uint32_t position = 0x00u;
  uint32_t iocurrent;
  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Init->Pin));
  assert_param(IS_GPIO_MODE(GPIO_Init->Mode));

  /* Configure the port pins */
  while (((GPIO_Init->Pin) >> position) != 0x00u)
  {
    /* Get current io position */
    iocurrent = (GPIO_Init->Pin) & (1uL << position);

    if (iocurrent != 0x00u)
    {
      /* Configure IO Direction mode (Input, Output, source ) */
      temp = GPIOx->DDR;
      temp &= ~(0x01UL << position);
      temp |= (((GPIO_Init->Mode & GPIO_MODE) << GPIO_MODE_Pos) << position);
      GPIOx->DDR = temp;

      temp = GPIOx->CTL;
      temp &= ~(0x01UL << position);
      temp |= (((GPIO_Init->Mode & (SOURCE_TYPE)) >> SOURCE_TYPE_Pos) << position);
      GPIOx->CTL = temp;

      /*--------------------- Interrupt Mode Configuration ------------------------*/
      /* Configure the External Interrupt or event for the current IO */
      if (((GPIO_Init->Mode & GPIO_IT_MODE) != 0x00u) && (GPIOx == GPIOA))
      {
        if((GPIO_Init->Mode & POL_HIGH) == POL_HIGH)
        {
          SET_BIT(GPIOAUX->INTPOL, iocurrent);
        }
        else
        {
          CLEAR_BIT(GPIOAUX->INTPOL, iocurrent);
        }

        if((GPIO_Init->Mode & SEN_EDGE) == SEN_EDGE)
        {
          SET_BIT(GPIOAUX->INTLVL, iocurrent);
        }
        else
        {
          CLEAR_BIT(GPIOAUX->INTLVL, iocurrent);
        }

        if((GPIO_Init->Mode & DEB_EN) == DEB_EN)
        {
          SET_BIT(GPIOAUX->DEBOU, iocurrent);
        }
        else
        {
          CLEAR_BIT(GPIOAUX->DEBOU, iocurrent);
        }

        if((GPIO_Init->Mode & SYNC_EN) == SYNC_EN)
        {
          SET_BIT(GPIOAUX->LSSYNC, iocurrent);
        }
        else
        {
          CLEAR_BIT(GPIOAUX->LSSYNC, iocurrent);
        }

        CLEAR_BIT(GPIOAUX->INTMSK, iocurrent);
        SET_BIT(GPIOAUX->INTEN, iocurrent);

        /* Configure ICTL and enable ICTL */  
        CLEAR_BIT(ICTL->IRQINTMASKH, iocurrent);
        SET_BIT(ICTL->IRQINTENH, iocurrent);
				
				/* config sim */
				SET_BIT(SYSCFG->IRQ_CFG_2, iocurrent);
      }
    }

    position++;
  }
}

/**
  * @brief  De-initialize the GPIOx peripheral registers to their default reset values.
  * @param  GPIOx specifies the GPIO peripheral for XT32H0xx family
  * @param  GPIO_Pin specifies the port bit to be written.
  *         This parameter can be any combination of GPIO_Pin_x where x can be (0..31).
  */
void HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin)
{
  uint32_t position = 0x00u;
  uint32_t iocurrent;
//  uint32_t tmp;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  /* Configure the port pins */
  while ((GPIO_Pin >> position) != 0x00u)
  {
    /* Get current io position */
    iocurrent = (GPIO_Pin) & (1uL << position);

    if (iocurrent != 0x00u)
    {
      /*------------------------- Interrupt Mode Configuration --------------------*/
      /* Clear the External Interrupt or Event for the current IO */
      if(((GPIOAUX->INTEN & iocurrent) != 0x00u) && (GPIOx == GPIOA))
      {
				SET_BIT(GPIOAUX->EOIA, iocurrent);
				CLEAR_BIT(GPIOAUX->INTEN, iocurrent);
				
        CLEAR_BIT(GPIOAUX->INTPOL, iocurrent);
        CLEAR_BIT(GPIOAUX->INTLVL, iocurrent);
        CLEAR_BIT(GPIOAUX->DEBOU, iocurrent);
        CLEAR_BIT(GPIOAUX->LSSYNC, iocurrent);
				
        /* Disable ICTL */  
        CLEAR_BIT(ICTL->IRQINTENL, iocurrent);
      }
      /*------------------------- GPIO Mode Configuration --------------------*/
      /* Configure IO in input Mode */
      CLEAR_BIT(GPIOx->DDR, iocurrent);

      /* Configure the default value Source (software) */
      CLEAR_BIT(GPIOx->CTL, iocurrent);
    
    }

    position++;
  }
}

/**
  * @}
  */

/** @addtogroup GPIO_Exported_Functions_Group2
 *  @brief GPIO Read, Write, Toggle, Lock and EXTI management functions.
 *
@verbatim
 ===============================================================================
                       ##### IO operation functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Read the specified input port pin.
  * @param  GPIOx specifies the GPIO peripheral for XT32H0xx family
  * @param  GPIO_Pin specifies the port bit to be written.
  *         This parameter can be any combination of GPIO_Pin_x where x can be (0..31).
  * @retval The input port pin value.
  */
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
  GPIO_PinState bitstatus;
  uint32_t regval = 0;

  /* Check the parameters */
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  if(GPIOx == GPIOA)
  {
    regval = READ_REG(GPIOAUX->EXTA);
  }
  else if(GPIOx == GPIOB)
  {
    regval = READ_REG(GPIOAUX->EXTB);
  }
  else if(GPIOx == GPIOC)
  {
    regval = READ_REG(GPIOAUX->EXTC);
  }
  else if(GPIOx == GPIOD)
  {
    regval = READ_REG(GPIOAUX->EXTD);
  }
	else
	{
	}

  if ((regval & GPIO_Pin) != 0x00u)
  {
    bitstatus = GPIO_PIN_SET;
  }
  else
  {
    bitstatus = GPIO_PIN_RESET;
  }
	
  return bitstatus;
}

/**
  * @brief  Set or clear the selected data port bit.
  *
  * @note   This function uses GPIOx_BSRR and GPIOx_BRR registers to allow atomic read/modify
  *         accesses. In this way, there is no risk of an IRQ occurring between
  *         the read and the modify access.
  *
  * @param  GPIOx specifies the GPIO peripheral for XT32H0xx family
  * @param  GPIO_Pin specifies the port bit to be written.
  *         This parameter can be any combination of GPIO_Pin_x where x can be (0..31).
  * @param  PinState specifies the value to be written to the selected bit.
  *         This parameter can be one of the GPIO_PinState enum values:
  *            @arg GPIO_PIN_RESET: to clear the port pin
  *            @arg GPIO_PIN_SET: to set the port pin
  */
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin, GPIO_PinState PinState)
{
  /* Check the parameters */
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  assert_param(IS_GPIO_PIN_ACTION(PinState));

  if(PinState == GPIO_PIN_SET)
  {
    SET_BIT(GPIOx->DR, GPIO_Pin);
  }
  else
  {
    CLEAR_BIT(GPIOx->DR, GPIO_Pin);
  }
}

/**
  * @brief  Toggle the specified GPIO pin.
  * @param  GPIOx specifies the GPIO peripheral for XT32H0xx family
  * @param  GPIO_Pin specifies the port bit to be written.
  *         This parameter can be any combination of GPIO_Pin_x where x can be (0..31).
  */
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
  uint32_t odr;

  /* Check the parameters */
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  odr = GPIOx->DR;

  /* Set selected pins that were at low level, and reset ones that were high */
  GPIOx->DR = (odr & ~GPIO_Pin) | (~odr & GPIO_Pin);
}

/**
  * @brief  Handle interrupt request.
  * @param  GPIO_Pin Specifies the port pin connected to corresponding EXTI line.
  */
void HAL_GPIO_IRQHandler(uint32_t GPIO_Pin)
{
  /* ICTL line interrupt detected */
	if(SYSCFG->IRQ_CFG_2 & GPIO_Pin)
	{
		if (__HAL_GPIO_ICTL_GET_IT(GPIO_Pin) != 0x00u)
		{
			HAL_GPIO_Callback(GPIO_Pin);
		}
  }
}

/**
  * @brief  EXTI line detection callback.
  * @param  GPIO_Pin Specifies the port pin connected to corresponding EXTI line.
  */
__weak void HAL_GPIO_Callback(uint32_t GPIO_Pin)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(GPIO_Pin);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_GPIO_EXTI_Rising_Callback could be implemented in the user file
   */
}

/**
  * @}
  */


/**
  * @}
  */

#endif /* HAL_GPIO_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
