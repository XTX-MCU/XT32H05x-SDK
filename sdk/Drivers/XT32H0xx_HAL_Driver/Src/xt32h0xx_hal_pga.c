/**
  ******************************************************************************
  * @file    xt32h0xx_hal_pga.c
  * @author  Software Team
  * @brief   This file provides firmware functions to manage the following
  *          functionalities of the PGA.
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

/** @addtogroup PGA 
  * @brief PGA HAL module driver
  * @{
  */

#ifdef HAL_MDU_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/
/** @defgroup PGA_Exported_Functions PGA Exported Functions
  * @{
  */
/** @addtogroup PGA_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */
/**
  * @brief  Initialize the PGA according to the specified
  *         parameters in the PGA_InitTypeDef and initialize the associated handle.
  * @param  hpga  PGA handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PGA_Init(PGA_HandleTypeDef *hpga)
{
  HAL_StatusTypeDef status = HAL_OK;
	
	uint32_t temp = 0;

  /* Check the PGA handle allocation and lock status */
  if(hpga == NULL)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameters */
    assert_param(IS_PGA_ALL_INSTANCE(hpga->Instance));
    assert_param(IS_PGA_GAIN(hpga->Instance, hpga->Init.Channel[0].Gain));
    assert_param(IS_PGA_GAIN(hpga->Instance, hpga->Init.Channel[1].Gain));
    assert_param(IS_PGA_GAIN(hpga->Instance, hpga->Init.Channel[2].Gain));
    assert_param(IS_PGA_GAIN(hpga->Instance, hpga->Init.Channel[3].Gain));
    if(hpga->State == HAL_PGA_STATE_RESET)
    {
      /* Allocate lock resource and initialize it */
      hpga->Lock = HAL_UNLOCKED;

      /* Set COMP error code to none */
      PGA_CLEAR_ERRORCODE(hpga);
			
#if defined(XT32H0xxB)
      if(hpga->Init.Channel[0].Gain < PGA_GAIN_5)
			{
				temp = (2 << MDU_ADCCFG_PGAMILLER1_Pos);
			}
			else
			{
				temp = (3 << MDU_ADCCFG_PGAMILLER1_Pos);
			}
      if(hpga->Init.Channel[1].Gain < PGA_GAIN_5)
			{
				temp = (2 << MDU_ADCCFG_PGAMILLER2_Pos);
			}
			else
			{
				temp |= (3 << MDU_ADCCFG_PGAMILLER2_Pos);
			}
      if(hpga->Init.Channel[2].Gain < PGA_GAIN_5)
			{
				temp |= (2 << MDU_ADCCFG_PGAMILLER3_Pos);
			}
			else
			{
				temp |= (3 << MDU_ADCCFG_PGAMILLER3_Pos);
			}
      if(hpga->Init.Channel[3].Gain < PGA_GAIN_5)
			{
				temp |= (2 << MDU_ADCCFG_PGAMILLER4_Pos);
			}
			else
			{
				temp |= (3 << MDU_ADCCFG_PGAMILLER4_Pos);
			}
      MODIFY_REG(hpga->Instance->ADC_CFG,(MDU_ADCCFG_PGAMILLER1|MDU_ADCCFG_PGAMILLER2|MDU_ADCCFG_PGAMILLER3|MDU_ADCCFG_PGAMILLER4),
       (temp));
#endif      


#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
      /* Init the PGA Callback settings */

      if (hpga->MspInitCallback == NULL)
      {
        hpga->MspInitCallback = HAL_PGA_MspInit; /* Legacy weak MspInit  */
      }

      /* Init the low level hardware */
      hpga->MspInitCallback(hpga);
#else
      /* Init the low level hardware */
      HAL_PGA_MspInit(hpga);
#endif /* USE_HAL_PGA_REGISTER_CALLBACKS */
    }

    MODIFY_REG( hpga->Instance->PGA_CFG, 
		            ( MDU_PGACFG_PGA1GAIN_Msk |
		              MDU_PGACFG_PGA2GAIN_Msk |
		              MDU_PGACFG_PGA3GAIN_Msk |
		              MDU_PGACFG_PGA4GAIN_Msk ),
		            (   hpga->Init.Channel[0].Gain | 
                  ( hpga->Init.Channel[1].Gain << MDU_PGACFG_PGA2GAIN_Pos ) |
                  ( hpga->Init.Channel[2].Gain << MDU_PGACFG_PGA3GAIN_Pos ) |
                  ( hpga->Init.Channel[3].Gain << MDU_PGACFG_PGA4GAIN_Pos ) ));

    hpga->State = HAL_PGA_STATE_READY;
  }

  return status;
}

/**
  * @brief  DeInitialize the PGA peripheral.
  * @param  hpga  PGA handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PGA_DeInit(PGA_HandleTypeDef *hpga)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the PGA handle allocation and lock status */
  if(hpga == NULL)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameter */
    assert_param(IS_PGA_ALL_INSTANCE(hpga->Instance));

#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
    if (hpga->MspDeInitCallback == NULL)
    {
      hpga->MspDeInitCallback = HAL_PGA_MspDeInit; /* Legacy weak MspDeInit  */
    }

    /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
    hpga->MspDeInitCallback(hpga);
#else
    /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
    HAL_PGA_MspDeInit(hpga);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */

    /* Disable PGA all channels */
    MODIFY_REG(hpga->Instance->PDCTRL, MDU_PDCTRL_PGAEN1|MDU_PDCTRL_PGAEN2|MDU_PDCTRL_PGAEN3|MDU_PDCTRL_PGAEN4, 0);

    /* Set HAL COMP handle state */
    hpga->State = HAL_PGA_STATE_RESET;

    /* Release Lock */
    __HAL_UNLOCK(hpga);
  }

  return status;
}

/**
  * @brief  Initialize the PGA MSP.
  * @param  hpga  PGA handle
  */
__weak void HAL_PGA_MspInit(PGA_HandleTypeDef *hpga)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpga);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PGA_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the PGA MSP.
  * @param  hpga  PGA handle
  */
__weak void HAL_PGA_MspDeInit(PGA_HandleTypeDef *hpga)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hpga);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_PGA_MspDeInit could be implemented in the user file
   */
}

#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User PGA Callback
  *         To be used instead of the weak predefined callback
  * @param  hpga Pointer to a COMP_HandleTypeDef structure that contains
  *                the configuration information for the specified COMP.
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_PGA_MSPINIT_CB_ID MspInit callback ID
  *          @arg @ref HAL_PGA_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PGA_RegisterCallback(PGA_HandleTypeDef *hpga, HAL_PGA_CallbackIDTypeDef CallbackID, pPGA_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hpga->ErrorCode |= HAL_PGA_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  switch (CallbackID)
  {
    case HAL_PGA_MSPINIT_CB_ID :
      hpga->MspInitCallback = pCallback;
      break;

    case HAL_PGA_MSPDEINIT_CB_ID :
      hpga->MspDeInitCallback = pCallback;
      break;

    default :
      /* Update the error code */
      hpga->ErrorCode |= HAL_PGA_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status = HAL_ERROR;
      break;
  }

  return status;
}

/**
  * @brief  Unregister a PGA Callback
  *         PGA callback is redirected to the weak predefined callback
  * @param  hpga Pointer to a PPA_HandleTypeDef structure that contains
  *                the configuration information for the specified PGA.
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_PGA_MSPINIT_CB_ID MspInit callback ID
  *          @arg @ref HAL_PGA_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_PGA_UnRegisterCallback(PGA_HandleTypeDef *hpga, HAL_PGA_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  switch (CallbackID)
  {
    case HAL_PGA_MSPINIT_CB_ID :
      hpga->MspInitCallback = HAL_PGA_MspInit;                 /* Legacy weak MspInit */
      break;

    case HAL_PGA_MSPDEINIT_CB_ID :
      hpga->MspDeInitCallback = HAL_PGA_MspDeInit;             /* Legacy weak MspDeInit */
      break;

    default :
      /* Update the error code */
      hpga->ErrorCode |= HAL_PGA_ERROR_INVALID_CALLBACK;

      /* Return error status */
      status =  HAL_ERROR;
      break;
  }

  return status;
}

#endif /* USE_HAL_PGA_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup PGA_Exported_Functions_Group2
  * @brief    Operation functions
  * @{
  */

/**
  * @brief  Enable PGA channel.
  * @param  hpga  PGA handle
  * @param  Channel PGA Channnel
  *         This parameter can one of the following values:
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  *         @arg @ref PGA_4
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_PGA_ChannelEnable(PGA_HandleTypeDef *hpga, uint32_t Channel)
{
  if(hpga == NULL)
  {
    return HAL_ERROR;
  }

  /* enable PGA Channel*/
  __HAL_PGA_ENABLE(hpga, Channel);

  return HAL_OK;
}

/**
  * @brief  Disable PGA channel.
  * @param  hpga  PGA handle
  * @param  Channel PGA Channnel
  *         This parameter can one of the following values:
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  *         @arg @ref PGA_4
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_PGA_ChannelDisable(PGA_HandleTypeDef *hpga, uint32_t Channel)
{
  if(hpga == NULL)
  {
    return HAL_ERROR;
  }

  /* enable PGA Channel*/
  __HAL_PGA_DISABLE(hpga, Channel);

  return HAL_OK;
}

/**
  * @brief  Set PGA channel gain.
  * @param  hpga  PGA handle
  * @param  Channel PGA Channnel
  *         This parameter can one of the following values:
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  *         @arg @ref PGA_4
  * @param Gain This parameter can one between 0 and 7.
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_PGA_SetChannelGain(PGA_HandleTypeDef *hpga, uint32_t Channel, uint32_t Gain)
{
  if(hpga == NULL)
  {
    return HAL_ERROR;
  }

  /* set PGA Channel gain */
  __HAL_PGA_SETGAIN(hpga, Channel, Gain);

  return HAL_OK;
}

/**
  * @brief  Get PGA channel gain.
  * @param  hpga  PGA handle
  * @param  Channel PGA Channnel
  *         This parameter can one of the following values:
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  *         @arg @ref PGA_4
  * @retval The value can one between 0 and 7.
  */
uint32_t          HAL_PGA_GetChannelGain(PGA_HandleTypeDef *hpga, uint32_t Channel)
{
  if(hpga == NULL)
  {
    return 0;
  }
  
  return (uint32_t)__HAL_PGA_GETGAIN(hpga, Channel);
}

#if defined(XT32H0xxB)
/**
  * @brief  Set PGA channel P and N source.
  * @param  hpga  PGA handle
  * @param  Channel PGA Channnel
  *         This parameter can one of the following values:
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  *         @arg @ref PGA_4
  * @param PSource PGA P source. This parameter can one of the following values:
  *        @arg @ref PGA_1_PSRC_NONE      
  *        @arg @ref PGA_1_PSRC_REMAPCH0  
  *        @arg @ref PGA_1_PSRC_REMAPCH20 
  *        @arg @ref PGA_1_PSRC_REMAPCH13 
  *        @arg @ref PGA_2_PSRC_NONE      
  *        @arg @ref PGA_2_PSRC_REMAPCH1  
  *        @arg @ref PGA_2_PSRC_REMAPCH21 
  *        @arg @ref PGA_2_PSRC_REMAPCH15 
  *        @arg @ref PGA_3_PSRC_NONE      
  *        @arg @ref PGA_3_PSRC_REMAPCH2  
  *        @arg @ref PGA_3_PSRC_REMAPCH22 
  *        @arg @ref PGA_3_PSRC_REMAPCH17 
  *        @arg @ref PGA_4_PSRC_NONE      
  *        @arg @ref PGA_4_PSRC_REMAPCH19 
  *        @arg @ref PGA_4_PSRC_REMAPCH23 
  *        @arg @ref PGA_4_PSRC_REMAPCH3  
  * @param NSource PGA N source. This parameter can one of the following values:
  *        @arg @ref PGA_1_NSRC_NONE      
  *        @arg @ref PGA_1_NSRC_REMAPCH24 
  *        @arg @ref PGA_1_NSRC_REMAPCH12 
  *        @arg @ref PGA_2_NSRC_NONE      
  *        @arg @ref PGA_2_NSRC_REMAPCH25 
  *        @arg @ref PGA_2_NSRC_REMAPCH14 
  *        @arg @ref PGA_3_NSRC_NONE      
  *        @arg @ref PGA_3_NSRC_REMAPCH26 
  *        @arg @ref PGA_3_NSRC_REMAPCH16 
  *        @arg @ref PGA_4_NSRC_NONE      
  *        @arg @ref PGA_4_NSRC_REMAPCH18 
  *        @arg @ref PGA_4_NSRC_REMAPCH27 
  */
HAL_StatusTypeDef HAL_PGA_SetChannelSource(PGA_HandleTypeDef *hpga, uint32_t Channel, uint32_t PSource, uint32_t NSource)
{
  __HAL_PGA_SETPGAPSOURCE(hpga, Channel, PSource);
  __HAL_PGA_SETPGANSOURCE(hpga, Channel, NSource);
  return HAL_OK;
}
#endif /* XT32H0xxB */

/**
  * @}
  */

/** @addtogroup PGA_Exported_Functions_Group3
  * @brief    Peripheral State functions
  * @{
  */

/**
  * @brief  Return the PGA handle state.
  * @param  hpga  PGA handle
  * @retval HAL state
  */
HAL_PGA_StateTypeDef HAL_PGA_GetState(PGA_HandleTypeDef *hpga)
{
  /* Check the PGA handle allocation */
  if(hpga == NULL)
  {
    return HAL_PGA_STATE_RESET;
  }

  /* Check the parameter */
  assert_param(IS_PGA_ALL_INSTANCE(hpga->Instance));

  /* Return HAL PGA handle state */
  return hpga->State;
}

/**
  * @brief  Return the PGA error code.
  * @param hpga PGA handle
  * @retval PGA error code
  */
uint32_t HAL_PGA_GetError(PGA_HandleTypeDef *hpga)
{
  /* Check the parameters */
  assert_param(IS_PGA_ALL_INSTANCE(hpga->Instance));

  return hpga->ErrorCode;
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
