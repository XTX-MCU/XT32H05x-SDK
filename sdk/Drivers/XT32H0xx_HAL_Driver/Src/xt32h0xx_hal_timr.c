/**
  ******************************************************************************
  * @file    xt32h0xx_hal_timr.c
  * @author  Software Team
  * @brief   TIM HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Timer (TIM) peripheral:
  *           + TIM Time Base Initialization
  *           + TIM Time Base Start
  *           + TIM Time Base Start Interruption
  *           + TIM External Clock configuration
  @verbatim
  ==============================================================================
                      ##### TIMER Generic features #####
  ==============================================================================
  [..] The Timer features include:
       (#) 32-bit down counter.

            ##### How to use this driver #####
  ==============================================================================
    [..]
     (#) Initialize the TIM low level resources by implementing the following functions
         depending on the selected feature:
           (++) Time Base : HAL_TIMR_Base_MspInit()
           (++) Input Capture : HAL_TIMR_IC_MspInit()
           (++) Output Compare : HAL_TIMR_OC_MspInit()
           (++) PWM generation : HAL_TIMR_PWM_MspInit()
           (++) One-pulse mode output : HAL_TIMR_OnePulse_MspInit()
           (++) Encoder mode output : HAL_TIMR_Encoder_MspInit()

     (#) Initialize the TIM low level resources :
        (##) Enable the TIM interface clock using __HAL_RCC_TIMx_CLK_ENABLE();
        (##) TIM pins configuration
            (+++) Enable the clock for the TIM GPIOs using the following function:
             __HAL_RCC_GPIOx_CLK_ENABLE();
            (+++) Configure these TIM pins in Alternate function mode using HAL_GPIO_Init();

     (#) The external Clock can be configured, if needed (the default clock is the
         internal clock from the APBx), using the following function:
         HAL_TIMR_ConfigClockSource, the clock configuration should be done before
         any start function.

     (#) Configure the TIM in the desired functioning mode using one of the
       Initialization function of this driver:
       (++) HAL_TIMR_Base_Init: to use the Timer to generate a simple time base
       (++) HAL_TIMR_OC_Init and HAL_TIMR_OC_ConfigChannel: to use the Timer to generate an
            Output Compare signal.
       (++) HAL_TIMR_PWM_Init and HAL_TIMR_PWM_ConfigChannel: to use the Timer to generate a
            PWM signal.
       (++) HAL_TIMR_IC_Init and HAL_TIMR_IC_ConfigChannel: to use the Timer to measure an
            external signal.
       (++) HAL_TIMR_OnePulse_Init and HAL_TIMR_OnePulse_ConfigChannel: to use the Timer
            in One Pulse Mode.
       (++) HAL_TIMR_Encoder_Init: to use the Timer Encoder Interface.

     (#) Activate the TIM peripheral using one of the start functions depending from the feature used:
           (++) Time Base : HAL_TIMR_Base_Start(), HAL_TIMR_Base_Start_DMA(), HAL_TIMR_Base_Start_IT()
           (++) Input Capture :  HAL_TIMR_IC_Start(), HAL_TIMR_IC_Start_DMA(), HAL_TIMR_IC_Start_IT()
           (++) Output Compare : HAL_TIMR_OC_Start(), HAL_TIMR_OC_Start_DMA(), HAL_TIMR_OC_Start_IT()
           (++) PWM generation : HAL_TIMR_PWM_Start(), HAL_TIMR_PWM_Start_DMA(), HAL_TIMR_PWM_Start_IT()
           (++) One-pulse mode output : HAL_TIMR_OnePulse_Start(), HAL_TIMR_OnePulse_Start_IT()
           (++) Encoder mode output : HAL_TIMR_Encoder_Start(), HAL_TIMR_Encoder_Start_DMA(), HAL_TIMR_Encoder_Start_IT().

     (#) The DMA Burst is managed with the two following functions:
         HAL_TIMR_DMABurst_WriteStart()
         HAL_TIMR_DMABurst_ReadStart()

    *** Callback registration ***
  =============================================

  [..]
  The compilation define  USE_HAL_TIMR_REGISTER_CALLBACKS when set to 1
  allows the user to configure dynamically the driver callbacks.

  [..]
  Use Function @ref HAL_TIMR_RegisterCallback() to register a callback.
  @ref HAL_TIMR_RegisterCallback() takes as parameters the HAL peripheral handle,
  the Callback ID and a pointer to the user callback function.

  [..]
  Use function @ref HAL_TIMR_UnRegisterCallback() to reset a callback to the default
  weak function.
  @ref HAL_TIMR_UnRegisterCallback takes as parameters the HAL peripheral handle,
  and the Callback ID.

  [..]
  These functions allow to register/unregister following callbacks:
    (+) Base_MspInitCallback              : TIM Base Msp Init Callback.
    (+) Base_MspDeInitCallback            : TIM Base Msp DeInit Callback.
    (+) Tim_Callback                      : TIM Callback.

  [..]
By default, after the Init and when the state is HAL_TIMR_STATE_RESET
all interrupt callbacks are set to the corresponding weak functions:
  examples @ref HAL_TIMR_TriggerCallback(), @ref HAL_TIMR_ErrorCallback().

  [..]
  Exception done for MspInit and MspDeInit functions that are reset to the legacy weak
  functionalities in the Init / DeInit only when these callbacks are null
  (not registered beforehand). If not, MspInit or MspDeInit are not null, the Init / DeInit
    keep and use the user MspInit / MspDeInit callbacks(registered beforehand)

  [..]
    Callbacks can be registered / unregistered in HAL_TIMR_STATE_READY state only.
    Exception done MspInit / MspDeInit that can be registered / unregistered
    in HAL_TIMR_STATE_READY or HAL_TIMR_STATE_RESET state,
    thus registered(user) MspInit / DeInit callbacks can be used during the Init / DeInit.
  In that case first register the MspInit/MspDeInit user callbacks
      using @ref HAL_TIMR_RegisterCallback() before calling DeInit or Init function.

  [..]
      When The compilation define USE_HAL_TIMR_REGISTER_CALLBACKS is set to 0 or
      not defined, the callback registration feature is not available and all callbacks
      are set to the corresponding weak functions.

  @endverbatim
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

/** @defgroup TIMR Basic Timer
  * @brief TIMR HAL module driver
  * @{
  */

#ifdef HAL_TIMR_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup TIMR_Private_Constants
  * @{
  */
//#define TIMx_OR1_OCREF_CLR 0x00000001U
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup TIMR_Private_Functions
  * @{
  */
/**
  * @}
  */
/* Exported functions --------------------------------------------------------*/

/** @addtogroup TIMR_Exported_Functions 
  * @{
  */

/** @addtogroup TIMR_Exported_Functions_Group1
  *  @brief    Time Base functions
  *
@verbatim
  ==============================================================================
              ##### Time Base functions #####
  ==============================================================================
  [..]
    This section provides functions allowing to:
    (+) Initialize and configure the TIM base.
    (+) De-initialize the TIM base.
    (+) Start the Time Base.
    (+) Stop the Time Base.
    (+) Start the Time Base and enable interrupt.
    (+) Stop the Time Base and disable interrupt.
    (+) Start the Time Base and enable DMA transfer.
    (+) Stop the Time Base and disable DMA transfer.

@endverbatim
  * @{
  */
/**
  * @brief  Initializes the TIM Time base Unit according to the specified
  *         parameters in the TIMR_HandleTypeDef and initialize the associated handle.
  * @param  htim TIM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIMR_Base_Init(TIMR_HandleTypeDef *htim)
{
  /* Check the TIM handle allocation */
  if (htim == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_TIMR_INSTANCE(htim->Instance));
  assert_param(IS_TIMR_COUNTER_MODE(htim->Init.CounterMode));

  if (htim->State == HAL_TIMR_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    htim->Lock = HAL_UNLOCKED;

#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
    /* Reset interrupt callbacks to legacy weak callbacks */
    TIMR_ResetCallback(htim);

    if (htim->Base_MspInitCallback == NULL)
    {
      htim->Base_MspInitCallback = HAL_TIMR_Base_MspInit;
    }
    /* Init the low level hardware : GPIO, CLOCK, NVIC */
    htim->Base_MspInitCallback(htim);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC */
    HAL_TIMR_Base_MspInit(htim);
#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */
  }

  /* Set the TIM state */
  htim->State = HAL_TIMR_STATE_BUSY;

  /* Set the Time Base configuration */
  TIMR_Base_SetConfig(htim->Instance, &htim->Init);
  
  //HAL_TIMR_InterruptEnable(htim);
	
  /* Initialize the TIM state*/
  htim->State = HAL_TIMR_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  DeInitializes the TIM Base peripheral
  * @param  htim TIM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIMR_Base_DeInit(TIMR_HandleTypeDef *htim)
{
  /* Check the parameters */
  assert_param(IS_TIMR_INSTANCE(htim->Instance));

  htim->State = HAL_TIMR_STATE_BUSY;

  /* Disable the TIM Peripheral Clock */
  __HAL_TIMR_DISABLE(htim);
	
	//HAL_TIMR_InterruptDisable(&htim);

#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
  if (htim->Base_MspDeInitCallback == NULL)
  {
    htim->Base_MspDeInitCallback = HAL_TIMR_Base_MspDeInit;
  }
  /* DeInit the low level hardware */
  htim->Base_MspDeInitCallback(htim);
#else
  /* DeInit the low level hardware: GPIO, CLOCK, NVIC */
  HAL_TIMR_Base_MspDeInit(htim);
#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */

  /* Change TIM state */
  htim->State = HAL_TIMR_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(htim);

  return HAL_OK;
}

/**
  * @brief  Initializes the TIM Base MSP.
  * @param  htim TIM Base handle
  */
__weak void HAL_TIMR_Base_MspInit(TIMR_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIMR_Base_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitializes TIM Base MSP.
  * @param  htim TIM Base handle
  */
__weak void HAL_TIMR_Base_MspDeInit(TIMR_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIMR_Base_MspDeInit could be implemented in the user file
   */
}


/**
  * @brief  Starts the TIM Base generation.
  * @param  htim TIM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIMR_Base_Start(TIMR_HandleTypeDef *htim)
{
//  uint32_t tmpsmcr;

  /* Check the parameters */
  assert_param(IS_TIMR_INSTANCE(htim->Instance));

  /* Check the TIM state */
  if (htim->State != HAL_TIMR_STATE_READY)
  {
    return HAL_ERROR;
  }

  /* Set the TIM state */
  htim->State = HAL_TIMR_STATE_BUSY;

  /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
  __HAL_TIMR_ENABLE(htim);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the TIM Base generation.
  * @param  htim TIM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIMR_Base_Stop(TIMR_HandleTypeDef *htim)
{
  /* Check the parameters */
  assert_param(IS_TIMR_INSTANCE(htim->Instance));

  /* Disable the Peripheral */
  __HAL_TIMR_DISABLE(htim);

  /* Set the TIM state */
  htim->State = HAL_TIMR_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Starts the TIM Base generation in interrupt mode.
  * @param  htim TIM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIMR_Base_Start_IT(TIMR_HandleTypeDef *htim)
{
//  uint32_t tmpsmcr;

  /* Check the parameters */
  assert_param(IS_TIMR_INSTANCE(htim->Instance));

  /* Check the TIM state */
  if (htim->State != HAL_TIMR_STATE_READY)
  {
    return HAL_ERROR;
  }

  /* Set the TIM state */
  htim->State = HAL_TIMR_STATE_BUSY;
	
	HAL_TIMR_InterruptEnable(htim);

  /* Enable the TIM Update interrupt */
  __HAL_TIMR_UNMASK_IT(htim);

  /* Enable the Peripheral, except in trigger mode where enable is automatically done with trigger */
  __HAL_TIMR_ENABLE(htim);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Stops the TIM Base generation in interrupt mode.
  * @param  htim TIM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIMR_Base_Stop_IT(TIMR_HandleTypeDef *htim)
{
  /* Check the parameters */
  assert_param(IS_TIMR_INSTANCE(htim->Instance));

  /* Disable the TIM Update interrupt */
  __HAL_TIMR_MASK_IT(htim);

  /* Disable the Peripheral */
  __HAL_TIMR_DISABLE(htim);
	
	HAL_TIMR_InterruptDisable(htim);

  /* Set the TIM state */
  htim->State = HAL_TIMR_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

#if defined(XT32H0xxB)
/**
  * @brief  Enable interrupt.
  * @param  htim TIM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIMR_InterruptEnable(TIMR_HandleTypeDef *htim) 
{
	/* ICTL */
  if(htim->Instance == TIMB11)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_11);
	  SET_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_11);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_11);
  }
  else if(htim->Instance == TIMB12)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_12);
	  SET_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_12);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_12);
  }
  else if(htim->Instance == TIMB13)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_13);
	  SET_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_13);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_13);
  }
  else if(htim->Instance == TIMB14)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_14);
	  SET_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_14);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_14);
  }
  else if(htim->Instance == TIMB21)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_21);
	  SET_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_21);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_21);
  }
  else if(htim->Instance == TIMB22)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_22);
	  SET_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_22);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_22);
  }
  else if(htim->Instance == TIMB23)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_23);
	  SET_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_23);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_23);
  }
  else if(htim->Instance == TIMB24)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQ_TIMB_24);
	  SET_BIT(ICTL->IRQINTENH, ICTL_IRQ_TIMB_24);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQ_TIMB_24);
  }

  return HAL_OK;
}

/**
  * @brief  Disable interrupt.
  * @param  htim TIM Base handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TIMR_InterruptDisable(TIMR_HandleTypeDef *htim) 
{
	/* ICTL */
  if(htim->Instance == TIMB11)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_11);
	  CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_11);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_11);
  }
  else if(htim->Instance == TIMB12)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_12);
	  CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_12);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_12);
  }
  else if(htim->Instance == TIMB13)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_13);
	  CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_13);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_13);
  }
  else if(htim->Instance == TIMB14)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_14);
	  CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_14);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_14);
  }
  else if(htim->Instance == TIMB21)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_21);
	  CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_21);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_21);
  }
  else if(htim->Instance == TIMB22)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_22);
	  CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_22);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_22);
  }
  else if(htim->Instance == TIMB23)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQ_TIMB_23);
	  CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQ_TIMB_23);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQ_TIMB_23);
  }
  else if(htim->Instance == TIMB24)
  {
	  CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQ_TIMB_24);
	  CLEAR_BIT(ICTL->IRQINTENH, ICTL_IRQ_TIMB_24);
	  CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQ_TIMB_24);
  }

  return HAL_OK;
}
#endif /* XT32H0xxB */	 

/**
  * @}
  */

/** @addtogroup TIMR_Exported_Functions_Group2
  *  @brief    TIM IRQ handler management
  *
@verbatim
  ==============================================================================
                        ##### IRQ handler management #####
  ==============================================================================
  [..]
    This section provides Timer IRQ handler function.

@endverbatim
  * @{
  */
/**
  * @brief  This function handles TIM interrupts requests.
  * @param  htim TIM  handle
  */
void HAL_TIMR_IRQHandler(TIMR_HandleTypeDef *htim)
{
  if( ((htim->Instance == TIMB11) && (ICTL->IRQFINALSTATUSL & ICTL_IRQ_TIMB_11)) ||
	  ((htim->Instance == TIMB12) && (ICTL->IRQFINALSTATUSL & ICTL_IRQ_TIMB_12)) ||
      ((htim->Instance == TIMB13) && (ICTL->IRQFINALSTATUSL & ICTL_IRQ_TIMB_13)) ||
      ((htim->Instance == TIMB14) && (ICTL->IRQFINALSTATUSL & ICTL_IRQ_TIMB_14)) ||
      ((htim->Instance == TIMB21) && (ICTL->IRQFINALSTATUSL & ICTL_IRQ_TIMB_21)) ||
      ((htim->Instance == TIMB22) && (ICTL->IRQFINALSTATUSL & ICTL_IRQ_TIMB_22)) ||
      ((htim->Instance == TIMB23) && (ICTL->IRQFINALSTATUSL & ICTL_IRQ_TIMB_23)) ||
      ((htim->Instance == TIMB24) && (ICTL->IRQFINALSTATUSH & ICTL_IRQ_TIMB_24)) )
  {
    if (__HAL_TIMR_GET_FLAG(htim) != RESET)
    {
       __HAL_TIMR_CLEAR_IT(htim);
#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
         htim->Tim_Callback(htim);
#else
         HAL_TIMR_Callback(htim);
#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */
    }
  }
}

/**
  * @}
  */


/** @addtogroup TIMR_Exported_Functions_Group3
  *  @brief    TIM Callbacks functions
  *
@verbatim
  ==============================================================================
                        ##### TIM Callbacks functions #####
  ==============================================================================
 [..]
   This section provides TIM callback functions:
   (+) TIM Period elapsed callback
   (+) TIM Output Compare callback
   (+) TIM Input capture callback
   (+) TIM Trigger callback
   (+) TIM Error callback

@endverbatim
  * @{
  */

/**
  * @brief  Timeout callback 
  * @param  htim TIM handle
  */
__weak void HAL_TIMR_Callback(TIMR_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TIMR_PeriodElapsedCallback could be implemented in the user file
   */
}

#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User TIM callback to be used instead of the weak predefined callback
  * @param htim tim handle
  * @param CallbackID ID of the callback to be registered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_TIMR_BASE_MSPINIT_CB_ID Base MspInit Callback ID
  *          @arg @ref HAL_TIMR_BASE_MSPDEINIT_CB_ID Base MspDeInit Callback ID
  *          @arg @ref HAL_TIMR_CB_ID Tim Callback ID
  *          @param pCallback pointer to the callback function
  *          @retval status
  */
HAL_StatusTypeDef HAL_TIMR_RegisterCallback(TIMR_HandleTypeDef *htim, HAL_TIMR_CallbackIDTypeDef CallbackID,
                                           pTIMR_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(htim);

  if (htim->State == HAL_TIMR_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_TIMR_BASE_MSPINIT_CB_ID :
        htim->Base_MspInitCallback     = pCallback;
        break;

      case HAL_TIMR_BASE_MSPDEINIT_CB_ID :
        htim->Base_MspDeInitCallback   = pCallback;
        break;

      case HAL_TIMR_CB_ID :
        htim->Tim_Callback             = pCallback;
        break;

      default :
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (htim->State == HAL_TIMR_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_TIMR_BASE_MSPINIT_CB_ID :
        htim->Base_MspInitCallback     = pCallback;
        break;

      case HAL_TIMR_BASE_MSPDEINIT_CB_ID :
        htim->Base_MspDeInitCallback   = pCallback;
        break;

      case HAL_TIMR_CB_ID :
        htim->Tim_Callback             = pCallback;
        break;

      default :
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(htim);

  return status;
}

/**
  * @brief  Unregister a TIM callback
  *         TIM callback is redirected to the weak predefined callback
  * @param htim tim handle
  * @param CallbackID ID of the callback to be unregistered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_TIMR_BASE_MSPINIT_CB_ID Base MspInit Callback ID
  *          @arg @ref HAL_TIMR_BASE_MSPDEINIT_CB_ID Base MspDeInit Callback ID
  *          @arg @ref HAL_TIMR_CB_ID Tim Callback ID
  *          @retval status
  */
HAL_StatusTypeDef HAL_TIMR_UnRegisterCallback(TIMR_HandleTypeDef *htim, HAL_TIMR_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(htim);

  if (htim->State == HAL_TIMR_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_TIMR_BASE_MSPINIT_CB_ID :
        /* Legacy weak Base MspInit Callback */
        htim->Base_MspInitCallback     = HAL_TIMR_Base_MspInit;
        break;

      case HAL_TIMR_BASE_MSPDEINIT_CB_ID :
        /* Legacy weak Base Msp DeInit Callback */
        htim->Base_MspDeInitCallback   = HAL_TIMR_Base_MspDeInit;
        break;

      case HAL_TIMR_CB_ID :
        /* Legacy weak Base Msp DeInit Callback */
        htim->Tim_Callback             = HAL_TIMR_Callback;
        break;

      default :
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (htim->State == HAL_TIMR_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_TIMR_BASE_MSPINIT_CB_ID :
        /* Legacy weak Base MspInit Callback */
        htim->Base_MspInitCallback     = HAL_TIMR_Base_MspInit;
        break;

      case HAL_TIMR_BASE_MSPDEINIT_CB_ID :
        /* Legacy weak Base Msp DeInit Callback */
        htim->Base_MspDeInitCallback   = HAL_TIMR_Base_MspDeInit;
        break;

      case HAL_TIMR_CB_ID :
        /* Legacy weak Base Msp DeInit Callback */
        htim->Tim_Callback             = HAL_TIMR_Callback;
        break;

      default :
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(htim);

  return status;
}
#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup TIMR_Exported_Functions_Group4
  *  @brief   TIM Peripheral State functions
  *
@verbatim
  ==============================================================================
                        ##### Peripheral State functions #####
  ==============================================================================
    [..]
    This subsection permits to get in run-time the status of the peripheral
    and the data flow.

@endverbatim
  * @{
  */

/**
  * @brief  Return the TIM Base handle state.
  * @param  htim TIM Base handle
  * @retval HAL state
  */
HAL_TIMR_StateTypeDef HAL_TIMR_Base_GetState(TIMR_HandleTypeDef *htim)
{
  return htim->State;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup TIMR_Private_Functions
  * @{
  */
/**
  * @brief  Time Base configuration
  * @param  TIMx TIM peripheral
  * @param  Structure TIM Base configuration structure
  */
void TIMR_Base_SetConfig(TIMR_TypeDef *TIMx, TIMR_Base_InitTypeDef *Structure)
{
  /* Set TIM Time Base Unit parameters ---------------------------------------*/
  MODIFY_REG(TIMx->CR, TIME_MODE_USERDEFINED,	(Structure->CounterMode));
  TIMx->LC = Structure->LoadCount;
}
/**
  * @}
  */

#endif /* HAL_TIMR_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
