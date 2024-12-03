/**
  ******************************************************************************
  * @file    xt32h0xx_hal_afc.c
  * @author  Software Team
  * @brief   AFC HAL module driver.
  *
  @verbatim
  ==============================================================================
                    ##### AFC Peripheral features #####
  ==============================================================================
  [..]
                     ##### How to use this driver #####
  ==============================================================================
  [..]

  @endverbatim
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

/** @addtogroup AFC
  * @{
  */

#ifdef HAL_AFC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ----------------------------------------------------------- */
/** @defgroup  AFC_Private_Macros AFC Private Macros
  * @{
  */

#define IS_AFC_CLKSRC(SOURCE)          (((SOURCE) == HAL_AFC_CLKSRC_32K)  || \
                                        ((SOURCE) == HAL_AFC_CLKSRC_16M))

#define IS_AFC_IT(IT)                  (((IT) == HAL_AFC_IT_ERROR)     || \
                                        ((IT) == HAL_AFC_IT_NORMALEND) || \
                                        ((IT) == HAL_AFC_IT_LOOPEND))

#define IS_AFC_FLAG(FLAG)              (((FLAG) == HAL_AFC_FLAG_ERROR)      || \
                                        ((FLAG) == HAL_AFC_FLAG_NORMALEND)  || \
                                        ((FLAG) == HAL_AFC_FLAG_LOOPEND))

/**
  * @}
  */
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup AFC_Exported_Functions
  * @{
  */

/** @addtogroup AFC_Exported_Functions_Group1
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
  * @brief  Initialize the AFC according to the specified
  *         parameters in the AFC_InitTypeDef and create the associated handle.
  * @param  hafc AFC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_AFC_Init(AFC_HandleTypeDef *hafc)
{
  /* Check the AFC handle allocation */
  if (hafc == NULL)
  {
    return HAL_ERROR;
  }
  
  /* Check the parameters */
  assert_param(IS_AFC_ALL_INSTANCE(hafc->Instance));

  if (hafc->State == HAL_AFC_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hafc->Lock = HAL_UNLOCKED;

    /* Init the low level hardware */
#if (USE_HAL_AFC_REGISTER_CALLBACKS == 1)
    if (hafc->AFC_MspInitCallback == NULL)
    {
      hafc->AFC_MspInitCallback = HAL_AFC_MspInit;
    }
    hafc->AFC_MspInitCallback(hafc);
#else
    HAL_AFC_MspInit(hafc);
#endif /*USE_HAL_AFC_REGISTER_CALLBACKS*/    
  }

  hafc->State = HAL_AFC_STATE_BUSY;

	/* control */
	MODIFY_REG(hafc->Instance->AFC_CTRL, SYSCFG_AFCCTRL_RFCNT|SYSCFG_AFCCTRL_DIFFCNT|SYSCFG_AFCCTRL_CBCLKS,
	hafc->Init.CalibrationTime << SYSCFG_AFCCTRL_RFCNT_Pos 
	| hafc->Init.CalibrationReference << SYSCFG_AFCCTRL_DIFFCNT_Pos
	| hafc->Init.ClockSource);
	
	/* config */
	MODIFY_REG(hafc->Instance->AFC_CFG, SYSCFG_AFCCFG_CBADJ | SYSCFG_AFCCFG_STDCNT,
	hafc->Init.InitialValue << SYSCFG_AFCCFG_CBADJ_Pos
	| hafc->Init.StandardCount << SYSCFG_AFCCFG_STDCNT_Pos);
	
	/* divider */
	MODIFY_REG(hafc->Instance->AFC_RES, SYSCFG_AFCRES_RFDIV, hafc->Init.RefClkDiv << SYSCFG_AFCRES_RFDIV_Pos);
	
	/* not bypassed */
	CLEAR_BIT(hafc->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCBYS);
	
	/* enable interrupt */
	SET_BIT(hafc->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AEIE|SYSCFG_AFCCTRL_ANIE|SYSCFG_AFCCTRL_ALIE);
	
	/* waiting */ 
	{
		int i;
		for(i=0; i<3000; i++)
		{
			__NOP();
		}
	}

  /* Change AFC peripheral state */
  hafc->State = HAL_AFC_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  DeInitialize the AFC peripheral.
  * @param  hafc AFC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_AFC_DeInit(AFC_HandleTypeDef *hafc)
{
  /* Check the AFC handle allocation */
  if (hafc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_AFC_ALL_INSTANCE(hafc->Instance));

  /* Check the AFC peripheral state */
  if (hafc->State == HAL_AFC_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Change AFC peripheral state */
  hafc->State = HAL_AFC_STATE_BUSY;

  /* Disable AFC */
  CLEAR_BIT(hafc->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCEN);
  
  /* DeInit the low level hardware */
#if (USE_HAL_AFC_REGISTER_CALLBACKS == 1)
  if (hafc->AFC_MspDeInitCallback == NULL)
  {
    hafc->AFC_MspDeInitCallback = HAL_AFC_MspDeInit;
  }
  hafc->AFC_MspDeInitCallback(hafc);
#else
  HAL_AFC_MspDeInit(hafc);
#endif /*USE_HAL_AFC_REGISTER_CALLBACKS*/  

  /* Change AFC peripheral state */
  hafc->State = HAL_AFC_STATE_RESET;

  /* Process unlocked */
  __HAL_UNLOCK(hafc);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initializes the AFC MSP.
  * @param  hafc AFC handle
  */
__weak void HAL_AFC_MspInit(AFC_HandleTypeDef *hafc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hafc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_AFC_MspInit can be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the AFC MSP.
  * @param  hafc AFC handle
  */
__weak void HAL_AFC_MspDeInit(AFC_HandleTypeDef *hafc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hafc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_AFC_MspDeInit can be implemented in the user file
   */
}

/**
  * @}
  */

/** @addtogroup AFC_Exported_Functions_Group2
 *  @brief AFC Start Stop functions.
 *
@verbatim
 ===============================================================================
                       ##### AFC operation functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Start AFC.
  * @param  hafc Pointer to a AFC_HandleTypeDef.
  * @retval HAL state.
  */
HAL_StatusTypeDef     HAL_AFC_Start(AFC_HandleTypeDef *hafc)
{
  if(__HAL_AFC_GET_CLKSRC(hafc) == HAL_AFC_CLKSRC_16M)
  {
    __HAL_RCC_SET_RCOSC_MODE(RCC_RCOSC_CALIB);
  }
  else
  {
    __HAL_RCC_LSI_SET_MODE(RCC_LSI_CALIB);
  }

	SET_BIT(hafc->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCEN);
  return HAL_OK;
}

/**
  * @brief  Stop AFC.
  * @param  hafc Pointer to a AFC_HandleTypeDef.
  * @retval HAL state.
  */
HAL_StatusTypeDef     HAL_AFC_Stop(AFC_HandleTypeDef *hafc)
{
  uint32_t tmp = READ_BIT(hafc->Instance->AFC_RES, SYSCFG_AFCRES_ADJRES);
  
  if(__HAL_AFC_GET_CLKSRC(hafc) == HAL_AFC_CLKSRC_16M)
  {
    __HAL_RCC_SET_RCOSC_CODE(tmp);
    CLEAR_BIT(hafc->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCEN);
    __HAL_RCC_SET_RCOSC_MODE(RCC_RCOSC_NORMAL);
  }
  else
  {
    __HAL_RCC_SET_LSI_RTUNE(tmp);
    CLEAR_BIT(hafc->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCEN);
    __HAL_RCC_LSI_SET_MODE(RCC_LSI_NORMAL);
  }
  
  return HAL_OK;
}

/**
  * @brief  Get AFC result.
  * @param  hafc Pointer to a AFC_HandleTypeDef.
  * @retval AFC result the value is between 0 to 0xFF.
  */
uint32_t HAL_AFC_GetAdjustResult(AFC_HandleTypeDef *hafc)
{
	return READ_BIT(hafc->Instance->AFC_RES, SYSCFG_AFCRES_ADJRES);
}

/**
  * @brief Handle AFC interrupt request.
  * @param hafc Pointer to a AFC_HandleTypeDef.
  */
void     HAL_AFC_IRQHandler(AFC_HandleTypeDef *hafc)
{
	if(ICTL->IRQFINALSTATUSH & ICTL_IRQCFG_AFC_MASK)
	{
  	if(READ_BIT(SYSCFG->AFC_RES, SYSCFG_AFCRES_ANIF))
  	{
  		/*clear */
  		CLEAR_BIT(SYSCFG->AFC_RES, SYSCFG_AFCRES_ANIF);
  		
  #if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
      hafc->AFC_EndCallback(htim);
  #else
  		HAL_AFC_EndCallback(hafc);
  #endif /*USE_HAL_TIMR_REGISTER_CALLBACKS*/   
  	}
  	if(READ_BIT(SYSCFG->AFC_RES, SYSCFG_AFCRES_ALIF))
  	{
  		/*clear */
  		CLEAR_BIT(SYSCFG->AFC_RES, SYSCFG_AFCRES_ALIF);
  		
  #if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
      hafc->AFC_EndCallback(htim);
  #else
  		HAL_AFC_EndCallback(hafc);
  #endif /*USE_HAL_TIMR_REGISTER_CALLBACKS*/   
  	}
  	if(READ_BIT(SYSCFG->AFC_RES, SYSCFG_AFCRES_AEIF))
  	{
  		/*clear */
  		CLEAR_BIT(SYSCFG->AFC_RES, SYSCFG_AFCRES_AEIF);
  #if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
      hafc->AFC_ErrorCallback(htim);
  #else
  		HAL_AFC_ErrorCallback(hafc);
  #endif /*USE_HAL_TIMR_REGISTER_CALLBACKS*/   
  	}
  }
}

/**
  * @brief  AFC End callback.
  * @param  hafc AFC handle
  */
__weak void HAL_AFC_EndCallback(AFC_HandleTypeDef *hafc)
{
  /* Prevent unused argument(s) compilation warning */
  //UNUSED();

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_AFC_EndCallback can be implemented in the user file.
   */
}

/**
  * @brief  AFC error callback.
  * @param  hafc AFC handle
  */
__weak void HAL_AFC_ErrorCallback(AFC_HandleTypeDef *hafc)
{
  /* Prevent unused argument(s) compilation warning */
  //UNUSED();

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_AFC_ErrorCallback can be implemented in the user file.
   */
}

#if (USE_HAL_AFC_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User AFC callback to be used instead of the weak predefined callback
  * @param hafc afc handle
  * @param CallbackID ID of the callback to be registered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_AFC_MSPINIT_CB_ID Base MspInit Callback ID
  *          @arg @ref HAL_AFC_MSPDEINIT_CB_ID Base MspDeInit Callback ID
  *          @arg @ref HAL_AFC_END_CB_ID End Callback ID
  *          @arg @ref HAL_AFC_ERROR_CB_ID Error Callback ID
  *          @param pCallback pointer to the callback function
  *          @retval status
  */
HAL_StatusTypeDef HAL_AFC_RegisterCallback(AFC_HandleTypeDef *hafc, HAL_AFC_CallbackIDTypeDef CallbackID,
                                           pAFC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hafc);

  if (hafc->State == HAL_AFC_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_AFC_MSPINIT_CB_ID :
        hafc->AFC_MspInitCallback      = pCallback;
        break;

      case HAL_AFC_MSPDEINIT_CB_ID :
        hafc->AFC_MspDeInitCallback    = pCallback;
        break;

      case HAL_AFC_END_CB_ID :
        hafc->AFC_EndCallback          = pCallback;
        break;

      case HAL_AFC_ERROR_CB_ID :
        hafc->AFC_ErrorCallback        = pCallback;
        break;

      default :
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (hafc->State == HAL_AFC_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_AFC_MSPINIT_CB_ID :
        hafc->AFC_MspInitCallback     = pCallback;
        break;

      case HAL_AFC_MSPDEINIT_CB_ID :
        hafc->AFC_MspDeInitCallback   = pCallback;
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
  __HAL_UNLOCK(hafc);

  return status;
}

/**
  * @brief  Unregister a AFC callback
  *         AFC callback is redirected to the weak predefined callback
  * @param hafc afc handle
  * @param CallbackID ID of the callback to be unregistered
  *        This parameter can be one of the following values:
  *          @arg @ref HAL_AFC_MSPINIT_CB_ID Base MspInit Callback ID
  *          @arg @ref HAL_AFC_MSPDEINIT_CB_ID Base MspDeInit Callback ID
  *          @arg @ref HAL_AFC_END_CB_ID End Callback ID
  *          @arg @ref HAL_AFC_ERROR_CB_ID Error Callback ID
  *          @retval status
  */
HAL_StatusTypeDef HAL_AFC_UnRegisterCallback(AFC_HandleTypeDef *hafc, HAL_AFC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hafc);

  if (hafc->State == HAL_AFC_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_AFC_MSPINIT_CB_ID :
        /* Legacy weak MspInit Callback */
        hafc->AFC_MspInitCallback     = HAL_AFC_MspInit;
        break;

      case HAL_AFC_MSPDEINIT_CB_ID :
        /* Legacy weak Msp DeInit Callback */
        hafc->AFC_MspDeInitCallback   = HAL_AFC_MspDeInit;
        break;

      case HAL_AFC_END_CB_ID :
        /* Legacy weak end Callback */
        hafc->AFC_EndCallback         = HAL_AFC_EndCallback;
        break;

      case HAL_AFC_ERROR_CB_ID :
        /* Legacy weak end Callback */
        hafc->AFC_ErrorCallback       = HAL_AFC_ErrorCallback;
        break;

      default :
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (hafc->State == HAL_AFC_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_AFC_MSPINIT_CB_ID :
        /* Legacy weak Base MspInit Callback */
        hafc->AFC_MspInitCallback     = HAL_AFC_MspInit;
        break;

      case HAL_AFC_MSPDEINIT_CB_ID :
        /* Legacy weak Base Msp DeInit Callback */
        hafc->AFC_MspDeInitCallback   = HAL_AFC_MspDeInit;
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
#endif /* USE_HAL_AFC_REGISTER_CALLBACKS */
	
/**
  * @}
  */

/** @defgroup AFC_Exported_Functions_Group3 Peripheral State functions
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
  * @brief  Return the AFC handle state.
  * @param  hafc AFC handle
  * @retval HAL state
  */
HAL_AFC_StateTypeDef HAL_AFC_GetState(AFC_HandleTypeDef *hafc)
{
  /* Return AFC handle state */
  return hafc->State;
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_AFC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
