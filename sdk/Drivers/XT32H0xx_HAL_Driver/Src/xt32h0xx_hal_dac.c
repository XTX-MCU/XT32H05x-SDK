/**
  ******************************************************************************
  * @file    xt32h0xx_hal_dac.c
  * @author  Software Team
  * @brief   This file provides firmware functions to manage the following
  *          functionalities of the Digital to Analog Converter (DAC).
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

/** @defgroup DAC DAC
  * @brief DAC HAL module driver
  * @{
  */

#ifdef HAL_MDU_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/
/** @defgroup DAC_Exported_Functions DAC Exported Functions
  * @{
  */
/** @addtogroup DAC_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */
/**
  * @brief  Initialize the DAC peripheral according to the specified parameters
  *         in the DAC_InitStruct and initialize the associated handle.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DAC_Init(DAC_HandleTypeDef *hdac)
{
  /* Check DAC handle */
  if (hdac == NULL)
  {
    return HAL_ERROR;
  }
  /* Check the parameters */
  assert_param(IS_DAC_ALL_INSTANCE(hdac->Instance));

  if (hdac->State == HAL_DAC_STATE_RESET)
  {
#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
    /* Init the DAC Callback settings */
    if (hdac->MspInitCallback == NULL)
    {
      hdac->MspInitCallback             = HAL_DAC_MspInit;
    }
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */

    /* Allocate lock resource and initialize it */
    hdac->Lock = HAL_UNLOCKED;

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
    /* Init the low level hardware */
    hdac->MspInitCallback(hdac);
#else
    /* Init the low level hardware */
    HAL_DAC_MspInit(hdac);
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */
  }

  /* Initialize the DAC state*/
  hdac->State = HAL_DAC_STATE_BUSY;

  /* Set DAC error code to none */
  hdac->ErrorCode = HAL_DAC_ERROR_NONE;

  MODIFY_REG(hdac->Instance->DAC_CFG, MDU_DACCFG_DAC2BBP|MDU_DACCFG_DAC1BBP|MDU_DACCFG_REFSEL, 
             hdac->Init.Channel[0].BufferMode|hdac->Init.Channel[1].BufferMode|hdac->Init.Refer);

  MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_DAC_REF, hdac->Init.ReferVoltageTune);

  /* Initialize the DAC state*/
  hdac->State = HAL_DAC_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Deinitialize the DAC peripheral registers to their default reset values.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DAC_DeInit(DAC_HandleTypeDef *hdac)
{
  /* Check DAC handle */
  if (hdac == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_DAC_ALL_INSTANCE(hdac->Instance));

  /* Change DAC state */
  hdac->State = HAL_DAC_STATE_BUSY;

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
  if (hdac->MspDeInitCallback == NULL)
  {
    hdac->MspDeInitCallback = HAL_DAC_MspDeInit;
  }
  /* DeInit the low level hardware */
  hdac->MspDeInitCallback(hdac);
#else
  /* DeInit the low level hardware */
  HAL_DAC_MspDeInit(hdac);
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */

  /* Set DAC error code to none */
  hdac->ErrorCode = HAL_DAC_ERROR_NONE;

  /* Change DAC state */
  hdac->State = HAL_DAC_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hdac);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initialize the DAC MSP.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  */
__weak void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hdac);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_DAC_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the DAC MSP.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  */
__weak void HAL_DAC_MspDeInit(DAC_HandleTypeDef *hdac)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hdac);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_DAC_MspDeInit could be implemented in the user file
   */
}

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User DAC Callback
  *         To be used instead of the weak (surcharged) predefined callback
  * @param  hdac DAC handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_DAC_MSPINIT_CB_ID            DAC MSP Init Callback ID
  *          @arg @ref HAL_DAC_MSPDEINIT_CB_ID          DAC MSP DeInit Callback ID
  *
  * @param  pCallback pointer to the Callback function
  * @retval status
  */
HAL_StatusTypeDef HAL_DAC_RegisterCallback(DAC_HandleTypeDef *hdac, HAL_DAC_CallbackIDTypeDef CallbackID,
                                           pDAC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hdac->ErrorCode |= HAL_DAC_ERROR_INVALID_CALLBACK;
    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(hdac);

  if (hdac->State == HAL_DAC_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_DAC_MSPINIT_CB_ID :
        hdac->MspInitCallback = pCallback;
        break;
      case HAL_DAC_MSPDEINIT_CB_ID :
        hdac->MspDeInitCallback = pCallback;
        break;
      default :
        /* Update the error code */
        hdac->ErrorCode |= HAL_DAC_ERROR_INVALID_CALLBACK;
        /* update return status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (hdac->State == HAL_DAC_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_DAC_MSPINIT_CB_ID :
        hdac->MspInitCallback = pCallback;
        break;
      case HAL_DAC_MSPDEINIT_CB_ID :
        hdac->MspDeInitCallback = pCallback;
        break;
      default :
        /* Update the error code */
        hdac->ErrorCode |= HAL_DAC_ERROR_INVALID_CALLBACK;
        /* update return status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hdac->ErrorCode |= HAL_DAC_ERROR_INVALID_CALLBACK;
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hdac);
  return status;
}

/**
  * @brief  Unregister a User DAC Callback
  *         DAC Callback is redirected to the weak (surcharged) predefined callback
  * @param  hdac DAC handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_DAC_MSPINIT_CB_ID               DAC MSP Init Callback ID
  *          @arg @ref HAL_DAC_MSPDEINIT_CB_ID             DAC MSP DeInit Callback ID
  *          @arg @ref HAL_DAC_ALL_CB_ID                   DAC All callbacks
  * @retval status
  */
HAL_StatusTypeDef HAL_DAC_UnRegisterCallback(DAC_HandleTypeDef *hdac, HAL_DAC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdac);

  if (hdac->State == HAL_DAC_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_DAC_MSPINIT_CB_ID :
        hdac->MspInitCallback = HAL_DAC_MspInit;
        break;
      case HAL_DAC_MSPDEINIT_CB_ID :
        hdac->MspDeInitCallback = HAL_DAC_MspDeInit;
        break;
      case HAL_DAC_ALL_CB_ID :
        hdac->MspInitCallback = HAL_DAC_MspInit;
        hdac->MspDeInitCallback = HAL_DAC_MspDeInit;
        break;
      default :
        /* Update the error code */
        hdac->ErrorCode |= HAL_DAC_ERROR_INVALID_CALLBACK;
        /* update return status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (hdac->State == HAL_DAC_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_DAC_MSPINIT_CB_ID :
        hdac->MspInitCallback = HAL_DAC_MspInit;
        break;
      case HAL_DAC_MSPDEINIT_CB_ID :
        hdac->MspDeInitCallback = HAL_DAC_MspDeInit;
        break;
      default :
        /* Update the error code */
        hdac->ErrorCode |= HAL_DAC_ERROR_INVALID_CALLBACK;
        /* update return status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hdac->ErrorCode |= HAL_DAC_ERROR_INVALID_CALLBACK;
    /* update return status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hdac);
  return status;
}
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup DAC_Exported_Functions_Group2
  * @brief    Operation functions
  * @{
  */

/**
  * @brief  Enables DAC and starts conversion of channel.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DAC_Start(DAC_HandleTypeDef *hdac)
{
  if(hdac == NULL)
  {
    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(hdac);

  /* Change DAC state */
  hdac->State = HAL_DAC_STATE_BUSY;

  __HAL_DAC_POWERON(hdac);

  /* Change DAC state */
  hdac->State = HAL_DAC_STATE_READY;

  /* Process unlocked */
  __HAL_UNLOCK(hdac);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Disables DAC and stop conversion of channel.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DAC_Stop(DAC_HandleTypeDef *hdac)
{
  if(hdac == NULL)
  {
    return HAL_ERROR;
  }

  /* Disable the Peripheral */
  __HAL_DAC_POWERDOWN(hdac);
  
  /* Change DAC state */
  hdac->State = HAL_DAC_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Set the specified data holding register value for DAC channel.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @param  Channel The selected DAC channel.
  *          This parameter can be one of the following values:
  *            @arg DAC_1: DAC Channel1 selected
  *            @arg DAC_2: DAC Channel2 selected
  * @param  Data Data to be loaded in the selected data holding register.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DAC_SetValue(DAC_HandleTypeDef *hdac, uint32_t Channel, uint8_t Data)
{
  if(hdac == NULL)
  {
    return HAL_ERROR;
  }

  assert_param(IS_DAC(Channel));

  __HAL_DAC_SETADD(hdac, Channel, Data);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Returns the last data output value of the selected DAC channel.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @param  Channel The selected DAC channel.
  *          This parameter can be one of the following values:
  *           @arg @ref DAC_1
  *           @arg @ref DAC_2
  * @retval The selected DAC channel data output value.
  */
uint8_t HAL_DAC_GetValue(DAC_HandleTypeDef *hdac, uint32_t Channel)
{
  if(hdac == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_DAC(Channel));

  return (uint8_t)(__HAL_DAC_GETADD(hdac, Channel));

}

/**
  * @brief  Configures the DAC channel buffer.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @param  Mode The selected DAC channel.
  *          This parameter can be one or combined of the following values:
  *           @arg @ref DAC_MODE_NORMAL
  *           @arg @ref DAC_1_MODE_BYPASS
  *           @arg @ref DAC_2_MODE_BYPASS
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DAC_SetChannelBypassBuffer(DAC_HandleTypeDef *hdac, uint32_t Mode)
{
  if(hdac == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_DAC_BYPASS(Mode));

  MODIFY_REG(hdac->Instance->DAC_CFG, MDU_DACCFG_DAC2BBP|MDU_DACCFG_DAC1BBP, Mode);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Configures the DAC reference voltage.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @param  Ref The selected DAC channel.
  *          This parameter can be one of the following values:
  *           @arg @ref DAC_REFERENCE_1P2
  *           @arg @ref DAC_REFERENCE_2P4
  *           @arg @ref DAC_REFERENCE_3P6
  *           @arg @ref DAC_REFERENCE_AVDD
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DAC_SetReference(DAC_HandleTypeDef *hdac, uint32_t Ref)
{
  if(hdac == NULL)
  {
    return HAL_ERROR;
  }

  assert_param(IS_DAC_REFERENCE(Ref));

  MODIFY_REG(hdac->Instance->DAC_CFG, MDU_DACCFG_REFSEL, Ref);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Configures the DAC reference voltage tune.
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @param  Ref The selected DAC channel.
  *          This parameter can be one of the following values:
  *           @arg @ref DAC_REFVOL_P57
  *           @arg @ref DAC_REFVOL_P58
  *           @arg @ref DAC_REFVOL_P59
  *           @arg @ref DAC_REFVOL_P60
  *           @arg @ref DAC_REFVOL_P61
  *           @arg @ref DAC_REFVOL_P62
  *           @arg @ref DAC_REFVOL_P63
  *           @arg @ref DAC_REFVOL_P64
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DAC_SetTuneReference(DAC_HandleTypeDef *hdac, uint32_t Ref)
{
  if(hdac == NULL)
  {
    return HAL_ERROR;
  }

  MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_DAC_REF, Ref);

  /* Return function status */
  return HAL_OK;
}

/**
  * @}
  */

/** @addtogroup DAC_Exported_Functions_Group3
  * @brief    Peripheral State functions
  * @{
  */

/**
  * @brief  return the DAC handle state
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval HAL state
  */
HAL_DAC_StateTypeDef HAL_DAC_GetState(DAC_HandleTypeDef *hdac)
{
  /* Return DAC handle state */
  return hdac->State;
}


/**
  * @brief  Return the DAC error code
  * @param  hdac pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval DAC Error Code
  */
uint32_t HAL_DAC_GetError(DAC_HandleTypeDef *hdac)
{
  return hdac->ErrorCode;
}
/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_MDU_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTECH *****END OF FILE****/
