/**
  ******************************************************************************
  * @file    xt32h0xx_hal_div.c
  * @author  Software Team
  * @brief   DIV HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Cyclic Redundancy Check (DIV) peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
	*           + Configuration functions
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup DIV DIV
  * @brief DIV HAL module driver.
  * @{
  */

#ifdef HAL_DIV_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup DIV_Private_Functions DIV Private Functions
  * @{
  */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup DIV_Exported_Functions DIV Exported Functions
  * @{
  */

/** @defgroup DIV_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions.
  *
@verbatim
 ===============================================================================
            ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Initialize the DIV according to the specified parameters
          in the DIV_InitTypeDef and create the associated handle
      (+) DeInitialize the DIV peripheral
      (+) Initialize the DIV MSP (MCU Specific Package)
      (+) DeInitialize the DIV MSP

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the DIV according to the specified
  *         parameters in the DIV_InitTypeDef and create the associated handle.
  * @param  hdiv DIV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DIV_Init(DIV_HandleTypeDef *hdiv)
{
  /* Check the DIV handle allocation */
  if (hdiv == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_DIV_ALL_INSTANCE(hdiv->Instance));

  if (hdiv->State == HAL_DIV_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hdiv->Lock = HAL_UNLOCKED;
    /* Init the low level hardware */
    HAL_DIV_MspInit(hdiv);
  }

	SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_HDIV_EN);
	
  /* Change DIV peripheral state */
  hdiv->State = HAL_DIV_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  DeInitialize the DIV peripheral.
  * @param  hdiv DIV handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DIV_DeInit(DIV_HandleTypeDef *hdiv)
{
  /* Check the DIV handle allocation */
  if (hdiv == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_DIV_ALL_INSTANCE(hdiv->Instance));

  /* Check the DIV peripheral state */
  if (hdiv->State == HAL_DIV_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* DeInit the low level hardware */
  HAL_DIV_MspDeInit(hdiv);
	
	CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_HDIV_EN);

  /* Change DIV peripheral state */
  hdiv->State = HAL_DIV_STATE_RESET;

  /* Process unlocked */
  __HAL_UNLOCK(hdiv);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initializes the DIV MSP.
  * @param  hdiv DIV handle
  */
__weak void HAL_DIV_MspInit(DIV_HandleTypeDef *hdiv)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hdiv);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_DIV_MspInit can be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the DIV MSP.
  * @param  hdiv DIV handle
  */
__weak void HAL_DIV_MspDeInit(DIV_HandleTypeDef *hdiv)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hdiv);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_DIV_MspDeInit can be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup DIV_Exported_Functions_Group2 Peripheral Control functions
  *  @brief    management functions.
  *
  * @{
  */

/**
  * @brief  Compute div A / B = Q  with R
  * @param  hdiv DIV handle
  * @param  divA A
  * @param  divB B
  * @param  pdivQ a pointer to Q
  * @param  pdivR a pointer to R
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_DIV_Calculate(DIV_HandleTypeDef *hdiv, uint32_t divA, uint32_t divB, uint32_t* pdivQ, uint32_t* pdivR)
{
  if(hdiv == NULL)
  {
    return HAL_ERROR;
  }

  if(divB == 0)
  {
    return HAL_ERROR;
  }


  /* Change DIV peripheral state */
  hdiv->State = HAL_DIV_STATE_BUSY;

  hdiv->Instance->HDIV_A = divA;
  hdiv->Instance->HDIV_B = divB;

  __NOP();
  __NOP();
  
  if (pdivQ != NULL)
  {
    *pdivQ =  hdiv->Instance->HDIV_Q;
  }

  if (pdivR != NULL)
  {
    *pdivR =  hdiv->Instance->HDIV_R;
  }

  /* Change DIV peripheral state */
  hdiv->State = HAL_DIV_STATE_READY;

  /* Return the DIV computed value */
  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup DIV_Exported_Functions_Group3 Peripheral State functions
  *  @brief    Peripheral State functions.
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State functions #####
 ===============================================================================
    [..]
    This subsection permits to get in run-time the status of the peripheral.

@endverbatim
  * @{
  */

/**
  * @brief  Return the DIV handle state.
  * @param  hdiv DIV handle
  * @retval HAL state
  */
HAL_DIV_StateTypeDef HAL_DIV_GetState(DIV_HandleTypeDef *hdiv)
{
  /* Return DIV handle state */
  return hdiv->State;
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_DIV_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
