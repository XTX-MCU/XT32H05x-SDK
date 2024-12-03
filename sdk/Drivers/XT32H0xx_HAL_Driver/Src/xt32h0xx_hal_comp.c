/**
  ******************************************************************************
  * @file    xt32h0xx_hal_comp.c
  * @author  Software Team
  * @brief   This file provides firmware functions to manage the following
  *          functionalities of the Comparator
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

/** @defgroup COMP COMP
  * @brief COMP HAL module driver
  * @{
  */

#ifdef HAL_MDU_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup COMP_Private_Functions COMP Private Functions
  * @{
  */
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/
/** @defgroup COMP_Exported_Functions COMP Exported Functions
  * @{
  */

/** @addtogroup COMP_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */
/**
  * @brief  Initialize the COMP according to the specified
  *         parameters in the COMP_InitTypeDef and initialize the associated handle.
  * @note   If the selected comparator is locked, initialization can't be performed.
  *         To unlock the configuration, perform a system reset.
  * @param  hcomp  COMP handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_COMP_Init(COMP_HandleTypeDef *hcomp)
{
  HAL_StatusTypeDef status = HAL_OK;
	
	uint32_t reg; 

  int i=0;

  /* Check the COMP handle allocation and lock status */
  if(hcomp == NULL)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameters */
    assert_param(IS_COMP_ALL_INSTANCE(hcomp->Instance));
    for(i=0; i<COMP_CHANNEL_NUMBER; i++)
    {
      assert_param(IS_COMP_NEGATIVESOURCE(hcomp->Instance, hcomp->Init.Channel[i].NegativeSource));
      assert_param(IS_COMP_POSITIVESOURCE(hcomp->Instance, hcomp->Init.Channel[i].PositiveSource));
      assert_param(IS_COMP_OUTPUTPOL(hcomp->Init.Channel[i].OutputPolarity));
      assert_param(IS_COMP_SPD(hcomp->Init.Channel[i].Spd));
      assert_param(IS_COMP_HYSTERESIS(hcomp->Init.Channel[i].Hysteresis));
    }

    if(hcomp->State == HAL_COMP_STATE_RESET)
    {
      /* Allocate lock resource and initialize it */
      hcomp->Lock = HAL_UNLOCKED;

      /* Set COMP error code to none */
      COMP_CLEAR_ERRORCODE(hcomp);


#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
      /* Init the COMP Callback settings */
      //hcomp->TriggerCallback = HAL_COMP_TriggerCallback; /* Legacy weak callback */

      if (hcomp->MspInitCallback == NULL)
      {
        hcomp->MspInitCallback = HAL_COMP_MspInit; /* Legacy weak MspInit  */
      }

      /* Init the low level hardware */
      /* Note: Internal control clock of the comparators must                 */
      /*       be enabled in "HAL_COMP_MspInit()"                             */
      /*       using "__HAL_RCC_SYSCFG_CLK_ENABLE()".                         */
      hcomp->MspInitCallback(hcomp);
#else
      /* Init the low level hardware */
      /* Note: Internal control clock of the comparators must                 */
      /*       be enabled in "HAL_COMP_MspInit()"                             */
      /*       using "__HAL_RCC_SYSCFG_CLK_ENABLE()".                         */
      HAL_COMP_MspInit(hcomp);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */
    }

    hcomp->Instance->COMP_CFG1 = hcomp->Init.Channel[0].PositiveSource |
                                 hcomp->Init.Channel[1].PositiveSource |
                                 hcomp->Init.Channel[2].PositiveSource |
                                 hcomp->Init.Channel[3].PositiveSource |
                                 hcomp->Init.Channel[0].NegativeSource |
                                 hcomp->Init.Channel[1].NegativeSource |
                                 hcomp->Init.Channel[2].NegativeSource |
                                 hcomp->Init.Channel[3].NegativeSource;
    hcomp->Instance->COMP_CFG2 = (hcomp->Init.Channel[0].Hysteresis << MDU_CMPCFG2_HYS_1_Pos) |
                                 (hcomp->Init.Channel[1].Hysteresis << MDU_CMPCFG2_HYS_2_Pos) |
                                 (hcomp->Init.Channel[2].Hysteresis << MDU_CMPCFG2_HYS_3_Pos) |
                                 (hcomp->Init.Channel[3].Hysteresis << MDU_CMPCFG2_HYS_4_Pos) |
                                 (hcomp->Init.Channel[0].Spd << MDU_CMPCFG2_SPD_1_Pos) |
                                 (hcomp->Init.Channel[1].Spd << MDU_CMPCFG2_SPD_2_Pos) |
                                 (hcomp->Init.Channel[2].Spd << MDU_CMPCFG2_SPD_3_Pos) |
                                 (hcomp->Init.Channel[3].Spd << MDU_CMPCFG2_SPD_4_Pos);
		reg = hcomp->Instance->COMP_CFG3;
		reg &= ~(MDU_CMPCFG3_CMP_BPFLG_Msk
		        |MDU_CMPCFG3_CMP4_FTRG_Msk|MDU_CMPCFG3_CMP4_RTRG_Msk
		        |MDU_CMPCFG3_CMP3_FTRG_Msk|MDU_CMPCFG3_CMP3_RTRG_Msk
		        |MDU_CMPCFG3_CMP2_FTRG_Msk|MDU_CMPCFG3_CMP2_RTRG_Msk
		        |MDU_CMPCFG3_CMP1_FTRG_Msk|MDU_CMPCFG3_CMP1_RTRG_Msk
						|MDU_CMPCFG3_OFLT_Msk|MDU_CMPCFG3_OPOL_Msk);
    reg |= hcomp->Init.OutputFilter |
                                 hcomp->Init.Channel[0].OutputPolarity |
                                 hcomp->Init.Channel[1].OutputPolarity |
                                 hcomp->Init.Channel[2].OutputPolarity |
                                 hcomp->Init.Channel[3].OutputPolarity |
																 hcomp->Init.Channel[0].trigger |
								                 hcomp->Init.Channel[1].trigger |
																 hcomp->Init.Channel[2].trigger |
																 hcomp->Init.Channel[3].trigger;
		hcomp->Instance->COMP_CFG3 = reg;

#if defined(XT32H0xxB)
    if(hcomp->Init.Channel[0].InterruptEnable)
		{
      HAL_NVIC_SetPriority(CMP1_IRQn, 2, 0);
      HAL_NVIC_EnableIRQ(CMP1_IRQn);
		}
    if(hcomp->Init.Channel[1].InterruptEnable)
		{
      HAL_NVIC_SetPriority(CMP2_IRQn, 2, 0);
      HAL_NVIC_EnableIRQ(CMP2_IRQn);
		}
    if(hcomp->Init.Channel[2].InterruptEnable)
		{
      HAL_NVIC_SetPriority(CMP3_IRQn, 2, 0);
      HAL_NVIC_EnableIRQ(CMP3_IRQn);
		}
    if(hcomp->Init.Channel[3].InterruptEnable)
		{
      HAL_NVIC_SetPriority(CMP4_IRQn, 2, 0);
      HAL_NVIC_EnableIRQ(CMP4_IRQn);
		}
#else
    /* configure and enable interrupts */
    CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_OCOMP_MASK);  /* unmask */
    CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQCFG_OCOMP_MASK);  /* config 0 */
    
    CLEAR_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_OCOMP_MASK);
    SET_BIT(ICTL->IRQINTENH, hcomp->Init.Channel[0].InterruptEnable | \
                             hcomp->Init.Channel[1].InterruptEnable | \
                             hcomp->Init.Channel[2].InterruptEnable | \
                             hcomp->Init.Channel[3].InterruptEnable );
#endif /* XT32H0xxB */

    /* Set HAL COMP handle state */
    /* Note: Transition from state reset to state ready,                      */
    /*       otherwise (coming from state ready or busy) no state update.     */
    if (hcomp->State == HAL_COMP_STATE_RESET)
    {
      hcomp->State = HAL_COMP_STATE_READY;
    }
  }

  return status;
}

/**
  * @brief  DeInitialize the COMP peripheral.
  * @note   Deinitialization cannot be performed if the COMP configuration is locked.
  *         To unlock the configuration, perform a system reset.
  * @param  hcomp  COMP handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_COMP_DeInit(COMP_HandleTypeDef *hcomp)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the COMP handle allocation and lock status */
  if(hcomp == NULL)
  {
    status = HAL_ERROR;
  }
  else
  {
    /* Check the parameter */
    assert_param(IS_COMP_ALL_INSTANCE(hcomp->Instance));

#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
    if (hcomp->MspDeInitCallback == NULL)
    {
      hcomp->MspDeInitCallback = HAL_COMP_MspDeInit; /* Legacy weak MspDeInit  */
    }

    /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
    hcomp->MspDeInitCallback(hcomp);
#else
    /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
    HAL_COMP_MspDeInit(hcomp);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */

    /* Power down all COMP channels */
    MODIFY_REG(hcomp->Instance->PDCTRL, 
               MDU_PDCTRL_CMP1PD|MDU_PDCTRL_CMP2PD|MDU_PDCTRL_CMP3PD|MDU_PDCTRL_CMP4PD,
               MDU_PDCTRL_CMP1PD|MDU_PDCTRL_CMP2PD|MDU_PDCTRL_CMP3PD|MDU_PDCTRL_CMP4PD);

    /* Set HAL COMP handle state */
    hcomp->State = HAL_COMP_STATE_RESET;

    /* Release Lock */
    __HAL_UNLOCK(hcomp);
  }

  return status;
}

/**
  * @brief  Initialize the COMP MSP.
  * @param  hcomp  COMP handle
  */
__weak void HAL_COMP_MspInit(COMP_HandleTypeDef *hcomp)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hcomp);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_COMP_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the COMP MSP.
  * @param  hcomp  COMP handle
  */
__weak void HAL_COMP_MspDeInit(COMP_HandleTypeDef *hcomp)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hcomp);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_COMP_MspDeInit could be implemented in the user file
   */
}

#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User COMP Callback
  *         To be used instead of the weak predefined callback
  * @param  hcomp Pointer to a COMP_HandleTypeDef structure that contains
  *                the configuration information for the specified COMP.
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_COMP_CH1_TRIGGER_CB_ID Trigger callback ID
  *          @arg @ref HAL_COMP_CH2_TRIGGER_CB_ID Trigger callback ID
  *          @arg @ref HAL_COMP_CH3_TRIGGER_CB_ID Trigger callback ID
  *          @arg @ref HAL_COMP_CH4_TRIGGER_CB_ID Trigger callback ID
  *          @arg @ref HAL_COMP_MSPINIT_CB_ID MspInit callback ID
  *          @arg @ref HAL_COMP_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_COMP_RegisterCallback(COMP_HandleTypeDef *hcomp, HAL_COMP_CallbackIDTypeDef CallbackID, pCOMP_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hcomp->ErrorCode |= HAL_COMP_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  if (HAL_COMP_STATE_READY == hcomp->State)
  {
    switch (CallbackID)
    {
      case HAL_COMP_CH1_TRIGGER_CB_ID :
        hcomp->Ch1TriggerCallback = pCallback;
        break;

      case HAL_COMP_CH12TRIGGER_CB_ID :
        hcomp->Ch2TriggerCallback = pCallback;
        break;

      case HAL_COMP_CH3_TRIGGER_CB_ID :
        hcomp->Ch3TriggerCallback = pCallback;
        break;

      case HAL_COMP_CH4_TRIGGER_CB_ID :
        hcomp->Ch4TriggerCallback = pCallback;
        break;

      case HAL_COMP_MSPINIT_CB_ID :
        hcomp->MspInitCallback = pCallback;
        break;

      case HAL_COMP_MSPDEINIT_CB_ID :
        hcomp->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hcomp->ErrorCode |= HAL_COMP_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status = HAL_ERROR;
        break;
    }
  }
  else if (HAL_COMP_STATE_RESET == hcomp->State)
  {
    switch (CallbackID)
    {
      case HAL_COMP_MSPINIT_CB_ID :
        hcomp->MspInitCallback = pCallback;
        break;

      case HAL_COMP_MSPDEINIT_CB_ID :
        hcomp->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hcomp->ErrorCode |= HAL_COMP_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status = HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hcomp->ErrorCode |= HAL_COMP_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Unregister a COMP Callback
  *         COMP callback is redirected to the weak predefined callback
  * @param  hcomp Pointer to a COMP_HandleTypeDef structure that contains
  *                the configuration information for the specified COMP.
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_COMP_CH1_TRIGGER_CB_ID Trigger callback ID
  *          @arg @ref HAL_COMP_CH2_TRIGGER_CB_ID Trigger callback ID
  *          @arg @ref HAL_COMP_CH3_TRIGGER_CB_ID Trigger callback ID
  *          @arg @ref HAL_COMP_CH4_TRIGGER_CB_ID Trigger callback ID
  *          @arg @ref HAL_COMP_MSPINIT_CB_ID MspInit callback ID
  *          @arg @ref HAL_COMP_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_COMP_UnRegisterCallback(COMP_HandleTypeDef *hcomp, HAL_COMP_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (HAL_COMP_STATE_READY == hcomp->State)
  {
    switch (CallbackID)
    {
      case HAL_COMP_CH1_TRIGGER_CB_ID :
        hcomp->Ch1TriggerCallback = HAL_COMP_Ch1TriggerCallback;         /* Legacy weak callback */
        break;

      case HAL_COMP_CH2_TRIGGER_CB_ID :
        hcomp->Ch2TriggerCallback = HAL_COMP_Ch2TriggerCallback;         /* Legacy weak callback */
        break;

      case HAL_COMP_CH3_TRIGGER_CB_ID :
        hcomp->Ch31TriggerCallback = HAL_COMP_Ch3TriggerCallback;         /* Legacy weak callback */
        break;

      case HAL_COMP_CH4_TRIGGER_CB_ID :
        hcomp->Ch4TriggerCallback = HAL_COMP_Ch4TriggerCallback;         /* Legacy weak callback */
        break;

      case HAL_COMP_MSPINIT_CB_ID :
        hcomp->MspInitCallback = HAL_COMP_MspInit;                 /* Legacy weak MspInit */
        break;

      case HAL_COMP_MSPDEINIT_CB_ID :
        hcomp->MspDeInitCallback = HAL_COMP_MspDeInit;             /* Legacy weak MspDeInit */
        break;

      case HAL_COMP_ALL_CB_ID :
        hcomp->TriggerCallback = HAL_COMP_TriggerCallback;
        hcomp->MspInitCallback = HAL_COMP_MspInit;
        hcomp->MspDeInitCallback = HAL_COMP_MspDeInit;
        break;

      default :
        /* Update the error code */
        hcomp->ErrorCode |= HAL_COMP_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_COMP_STATE_RESET == hcomp->State)
  {
    switch (CallbackID)
    {
      case HAL_COMP_MSPINIT_CB_ID :
        hcomp->MspInitCallback = HAL_COMP_MspInit;                 /* Legacy weak MspInit */
        break;

      case HAL_COMP_MSPDEINIT_CB_ID :
        hcomp->MspDeInitCallback = HAL_COMP_MspDeInit;             /* Legacy weak MspDeInit */
        break;

      case HAL_COMP_ALL_CB_ID :
        hcomp->MspInitCallback = HAL_COMP_MspInit;
        hcomp->MspDeInitCallback = HAL_COMP_MspDeInit;
        break;

      default :
        /* Update the error code */
        hcomp->ErrorCode |= HAL_COMP_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hcomp->ErrorCode |= HAL_COMP_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup COMP_Exported_Functions_Group2
  * @brief  Operation and interrupt response functions
  * @{
  */

/**
  * @brief  Enable COMP.
  * @param hcomp Comp handle
  * @param Channel COMP channel
  *        This parameter can one of the following values:
  *        @arg @ref COMP_1
  *        @arg @ref COMP_2
  *        @arg @ref COMP_3
  *        @arg @ref COMP_4
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_COMP_Start(COMP_HandleTypeDef *hcomp, uint32_t Channel)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

	__HAL_COMP_POWERON(hcomp, Channel);

  return tmp_hal_status;
}

/**
  * @brief  Disable COMP.
  * @param hcomp Comp handle
  * @param Channel COMP channel
  *        This parameter can one of the following values:
  *        @arg @ref COMP_1
  *        @arg @ref COMP_2
  *        @arg @ref COMP_3
  *        @arg @ref COMP_4
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_COMP_Stop(COMP_HandleTypeDef *hcomp, uint32_t Channel)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

	__HAL_COMP_POWERDOWN(hcomp, Channel);

  return tmp_hal_status;
}

/**
  * @brief  Enable COMP filter.
  * @param hcomp Comp handle
  * @param Freq IO debounce frequency
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_COMP_FilterEnable(COMP_HandleTypeDef *hcomp, uint32_t Freq)
{
	uint32_t gpioclk = HAL_RCC_GetPeriphCLKFreq(RCC_PERIPHCLK_GPIO);
	uint32_t div = gpioclk/Freq;
	
	__HAL_RCC_SET_GPIO_CLK_DIV(div);
	
	__HAL_COMP_ENABLEOUTPUTFILTER(hcomp);
	
	return HAL_OK;
}

/**
  * @brief  Disable COMP filter.
  * @param hcomp Comp handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_COMP_FilterDisable(COMP_HandleTypeDef *hcomp)
{
	__HAL_COMP_DISABLEOUTPUTFILTER(hcomp);
	
	return HAL_OK;
}
	
/**
  * @brief  COMP channel 1 interrupt handler
  * @param hcomp COMP handle
  */
void              HAL_COMP_Ch1IRQHandler(COMP_HandleTypeDef *hcomp)
{
#if defined(XT32H0xxB)
  /*clear interrupt*/
  MDU->INT_STATUS_1 &= ~((uint32_t)MDU_INT_STATUS_OCOMP1);
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
  if (hcomp->Ch1TriggerCallback == NULL)
  {
    hcomp->Ch1TriggerCallback = HAL_COMP_Ch1TriggerCallback; /* Legacy weak TriggerCallback  */
  }

  /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
  hcomp->Ch1TriggerCallback(hcomp);
#else
  HAL_COMP_Ch1TriggerCallback(hcomp);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */    
#else	
  if(ICTL->IRQFINALSTATUSH & (ICTL_IRQ_OCOMP_2|ICTL_IRQ_OCOMP_3|ICTL_IRQ_OCOMP_4|ICTL_IRQ_OCOMP_4))
  {
    /*clear interrupt*/

#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
    if (hcomp->TriggerCallback == NULL)
    {
      hcomp->TriggerCallback = HAL_COMP_TriggerCallback; /* Legacy weak TriggerCallback  */
    }

    /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
    hcomp->TriggerCallback(hcomp);
#else
    HAL_COMP_TriggerCallback(hcomp);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */    
  }
#endif /* XT32H0xxB  */	
}

/**
  * @brief  COMP channel 2 interrupt handler
  * @param hcomp COMP handle
  */
void              HAL_COMP_Ch2IRQHandler(COMP_HandleTypeDef *hcomp)
{
  /*clear interrupt*/
	MDU->INT_STATUS_1 &= ~((uint32_t)MDU_INT_STATUS_OCOMP2);
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
  if (hcomp->Ch2TriggerCallback == NULL)
  {
    hcomp->Ch2TriggerCallback = HAL_COMP_Ch2TriggerCallback; /* Legacy weak TriggerCallback  */
  }

  /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
  hcomp->Ch2TriggerCallback(hcomp);
#else
  HAL_COMP_Ch2TriggerCallback(hcomp);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */    
}

/**
  * @brief  COMP channel 3 interrupt handler
  * @param hcomp COMP handle
  */
void              HAL_COMP_Ch3IRQHandler(COMP_HandleTypeDef *hcomp)
{
  /*clear interrupt*/
	MDU->INT_STATUS_1 &= ~((uint32_t)MDU_INT_STATUS_OCOMP3);
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
  if (hcomp->Ch3TriggerCallback == NULL)
  {
    hcomp->Ch3TriggerCallback = HAL_COMP_Ch3TriggerCallback; /* Legacy weak TriggerCallback  */
  }

  /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
  hcomp->Ch3TriggerCallback(hcomp);
#else
  HAL_COMP_Ch3TriggerCallback(hcomp);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */    
}

/**
  * @brief  COMP channel 4 interrupt handler
  * @param hcomp COMP handle
  */
void              HAL_COMP_Ch4IRQHandler(COMP_HandleTypeDef *hcomp)
{
  /*clear interrupt*/
	MDU->INT_STATUS_1 &= ~((uint32_t)MDU_INT_STATUS_OCOMP4);
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
  if (hcomp->Ch4TriggerCallback == NULL)
  {
    hcomp->Ch4TriggerCallback = HAL_COMP_Ch4TriggerCallback; /* Legacy weak TriggerCallback  */
  }

  /* DeInit the low level hardware: GPIO, RCC clock, NVIC */
  hcomp->Ch4TriggerCallback(hcomp);
#else
  HAL_COMP_Ch4TriggerCallback(hcomp);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */    
}

/**
  * @brief  COMP channel 1 trigger callback.
  * @param  hcomp  COMP handle
  */
__weak void HAL_COMP_Ch1TriggerCallback(COMP_HandleTypeDef *hcomp)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hcomp);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_COMP_TriggerCallback could be implemented in the user file
   */
}

/**
  * @brief  COMP channel 2 trigger callback.
  * @param  hcomp  COMP handle
  */
__weak void HAL_COMP_Ch2TriggerCallback(COMP_HandleTypeDef *hcomp)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hcomp);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_COMP_TriggerCallback could be implemented in the user file
   */
}
/**
  * @brief  COMP channel 3 trigger callback.
  * @param  hcomp  COMP handle
  */
__weak void HAL_COMP_Ch3TriggerCallback(COMP_HandleTypeDef *hcomp)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hcomp);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_COMP_TriggerCallback could be implemented in the user file
   */
}
/**
  * @brief  COMP channel 4 trigger callback.
  * @param  hcomp  COMP handle
  */
__weak void HAL_COMP_Ch4TriggerCallback(COMP_HandleTypeDef *hcomp)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hcomp);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_COMP_TriggerCallback could be implemented in the user file
   */
}
/**
  * @}
  */

/** @defgroup COMP_Exported_Functions_Group3 Peripheral State functions
  *  @brief    COMP Peripheral State functions
  *
  * @{
  */

/**
  * @brief  Return the COMP handle state.
  * @param  hcomp  COMP handle
  * @retval HAL state
  */
HAL_COMP_StateTypeDef HAL_COMP_GetState(COMP_HandleTypeDef *hcomp)
{
  /* Check the COMP handle allocation */
  if(hcomp == NULL)
  {
    return HAL_COMP_STATE_RESET;
  }

  /* Check the parameter */
  assert_param(IS_COMP_ALL_INSTANCE(hcomp->Instance));

  /* Return HAL COMP handle state */
  return hcomp->State;
}

/**
  * @brief  Return the COMP error code.
  * @param hcomp COMP handle
  * @retval COMP error code
  */
uint32_t HAL_COMP_GetError(COMP_HandleTypeDef *hcomp)
{
  /* Check the parameters */
  assert_param(IS_COMP_ALL_INSTANCE(hcomp->Instance));

  return hcomp->ErrorCode;
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
