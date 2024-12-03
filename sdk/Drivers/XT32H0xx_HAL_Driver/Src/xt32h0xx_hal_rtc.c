/**
  ******************************************************************************
  * @file    xt32h0xx_hal_rtc.c
  * @author  Software Team
  * @brief   RTC HAL module driver.
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"
#include "xt32h0xx_ll_rtc.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */


/** @addtogroup RTC
  * @brief RTC HAL module driver
  * @{
  */

#ifdef HAL_RTC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup RTC_Exported_Functions
  * @{
  */

/** @addtogroup RTC_Exported_Functions_Group1
 *  @brief    Initialization and Configuration functions
 *
 * @{
  */

/**
  * @brief  Initialize the RTC peripheral
  * @param  hrtc RTC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_Init(RTC_HandleTypeDef *hrtc)
{
  HAL_StatusTypeDef status = HAL_ERROR;

  /* Check the RTC peripheral state */
  if(hrtc != NULL)
  {
    /* Check the parameters */
    assert_param(IS_RTC_ALL_INSTANCE(hrtc->Instance));
    assert_param(IS_RTC_HOUR_FORMAT(hrtc->Init.HourFormat));

    if(hrtc->State == HAL_RTC_STATE_RESET)
    {
      /* Allocate lock resource and initialize it */
      hrtc->Lock = HAL_UNLOCKED;

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
    hrtc->AlarmEventCallback          =  HAL_RTC_AlarmAEventCallback;        /* Legacy weak AlarmAEventCallback      */
    hrtc->TimeStampEventCallback       =  HAL_RTCEx_TimeStampEventCallback;   /* Legacy weak TimeStampEventCallback   */
    hrtc->WakeUpTimerEventCallback     =  HAL_RTCEx_WakeUpTimerEventCallback; /* Legacy weak WakeUpTimerEventCallback */

    if(hrtc->MspInitCallback == NULL)
    {
      hrtc->MspInitCallback = HAL_RTC_MspInit;
    }
    /* Init the low level hardware */
    hrtc->MspInitCallback(hrtc);

    if(hrtc->MspDeInitCallback == NULL)
    {
      hrtc->MspDeInitCallback = HAL_RTC_MspDeInit;
    }
#else
     /* Initialize RTC MSP */
     HAL_RTC_MspInit(hrtc);
#endif /* (USE_HAL_RTC_REGISTER_CALLBACKS) */
    }

	  /* disable RTC interrupt */
	  hrtc->Instance->CCR &= ~(RTC_CCR_IEN);
	
  	/* enable RTC */
	  hrtc->Instance->CCR |= RTC_CCR_EN;

    /* Set RTC state */
    hrtc->State = HAL_RTC_STATE_READY;

	  status = HAL_OK;
  }
  
	return status;
}

/**
  * @brief  DeInitialize the RTC peripheral.
  * @note   This function does not reset the RTC Backup Data registers.
  * @param  hrtc RTC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_DeInit(RTC_HandleTypeDef *hrtc)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  uint32_t tickstart;

  if(hrtc == NULL) return status;
  /* Check the parameters */
  assert_param(IS_RTC_ALL_INSTANCE(hrtc->Instance));

  /* Set RTC state */
  hrtc->State = HAL_RTC_STATE_BUSY;

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
  if(hrtc->MspDeInitCallback == NULL)
  {
     hrtc->MspDeInitCallback = HAL_RTC_MspDeInit;
  }

    /* DeInit the low level hardware: CLOCK, NVIC.*/
  hrtc->MspDeInitCallback(hrtc);

#else
  /* De-Initialize RTC MSP */
  HAL_RTC_MspDeInit(hrtc);
#endif /* (USE_HAL_RTC_REGISTER_CALLBACKS) */

	 /* disable RTC interrupt */
	 hrtc->Instance->CCR &= ~(RTC_CCR_IEN);

   /* disable RTC */
	 hrtc->Instance->CCR &= ~(RTC_CCR_EN);

   hrtc->State = HAL_RTC_STATE_RESET;

   status = HAL_OK;

   /* Release Lock */
   __HAL_UNLOCK(hrtc);

   return status;
}

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User RTC Callback
  *         To be used instead of the weak predefined callback
  * @param  hrtc RTC handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref   HAL_RTC_ALARM_EVENT_CB_ID
  *          @arg @ref   HAL_RTC_MSPINIT_CB_ID    
  *          @arg @ref   HAL_RTC_MSPDEINIT_CB_ID  
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_RegisterCallback(RTC_HandleTypeDef *hrtc, HAL_RTC_CallbackIDTypeDef CallbackID, pRTC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(pCallback == NULL)
  {
    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(hrtc);

  if(HAL_RTC_STATE_READY == hrtc->State)
  {
    switch (CallbackID)
    {
    case HAL_RTC_ALARM_EVENT_CB_ID :
      hrtc->AlarmAEventCallback = pCallback;
      break;

    case HAL_RTC_IRQ_CB_ID :
      hrtc->IRQEventCallback = pCallback;
      break;

    case HAL_RTC_MSPINIT_CB_ID :
      hrtc->MspInitCallback = pCallback;
      break;

    case HAL_RTC_MSPDEINIT_CB_ID :
      hrtc->MspDeInitCallback = pCallback;
      break;

    default :
     /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if(HAL_RTC_STATE_RESET == hrtc->State)
  {
    switch (CallbackID)
    {
    case HAL_RTC_MSPINIT_CB_ID :
      hrtc->MspInitCallback = pCallback;
      break;

   case HAL_RTC_MSPDEINIT_CB_ID :
      hrtc->MspDeInitCallback = pCallback;
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
  __HAL_UNLOCK(hrtc);

  return status;
}

/**
  * @brief  Unregister an RTC Callback
  *         RTC callback is redirected to the weak predefined callback
  * @param  hrtc RTC handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref   HAL_RTC_ALARM_EVENT_CB_ID
  *          @arg @ref   HAL_RTC_MSPINIT_CB_ID    
  *          @arg @ref   HAL_RTC_MSPDEINIT_CB_ID  
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_UnRegisterCallback(RTC_HandleTypeDef *hrtc, HAL_RTC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hrtc);

  if(HAL_RTC_STATE_READY == hrtc->State)
  {
    switch (CallbackID)
    {
    case HAL_RTC_ALARM_EVENT_CB_ID :
      hrtc->AlarmAEventCallback = HAL_RTC_AlarmAEventCallback;         /* Legacy weak AlarmAEventCallback    */
      break;

    case HAL_RTC_IRQ_CB_ID :
      hrtc->IRQCallback = HAL_RTC_IRQCallback;                         /* Legacy weak IRQEventCallback    */
      break;

    case HAL_RTC_MSPINIT_CB_ID :
      hrtc->MspInitCallback = HAL_RTC_MspInit;
      break;

    case HAL_RTC_MSPDEINIT_CB_ID :
      hrtc->MspDeInitCallback = HAL_RTC_MspDeInit;
      break;

    default :
     /* Return error status */
      status =  HAL_ERROR;
      break;
    }
  }
  else if(HAL_RTC_STATE_RESET == hrtc->State)
  {
    switch (CallbackID)
    {
    case HAL_RTC_MSPINIT_CB_ID :
      hrtc->MspInitCallback = HAL_RTC_MspInit;
      break;

    case HAL_RTC_MSPDEINIT_CB_ID :
      hrtc->MspDeInitCallback = HAL_RTC_MspDeInit;
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
  __HAL_UNLOCK(hrtc);

  return status;
}
#endif /* USE_HAL_RTC_REGISTER_CALLBACKS */

/**
  * @brief  Initialize the RTC MSP.
  * @param  hrtc RTC handle
  */
__weak void HAL_RTC_MspInit(RTC_HandleTypeDef* hrtc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrtc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_RTC_MspInit could be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the RTC MSP.
  * @param  hrtc RTC handle
  */
__weak void HAL_RTC_MspDeInit(RTC_HandleTypeDef* hrtc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrtc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_RTC_MspDeInit could be implemented in the user file
   */
}

/**
  * @}
  */

/** @addtogroup RTC_Exported_Functions_Group2
 *  @brief   RTC Time and Date functions
 *
@verbatim
 ===============================================================================
                 ##### RTC Time and Date functions #####
 ===============================================================================

 [..] This section provides functions allowing to configure Time and Date features

@endverbatim
  * @{
  */

/**
  * @brief  Set RTC current time.
  * @param  hrtc RTC handle
  * @param  sTime Pointer to Time structure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_SetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime)
{
  uint32_t tmpreg;
  HAL_StatusTypeDef status = HAL_OK;

 /* Check the parameters */
//  assert_param(IS_RTC_FORMAT(Format));
//  assert_param(IS_RTC_DAYLIGHT_SAVING(sTime->DayLightSaving));
//  assert_param(IS_RTC_STORE_OPERATION(sTime->StoreOperation));

  /* Process Locked */
  __HAL_LOCK(hrtc);

  hrtc->State = HAL_RTC_STATE_BUSY;

  LL_RTC_SetDayLightSaving(hrtc->Instance, sTime->DayLightSaving);
  LL_RTC_TIME_Config(hrtc->Instance, sTime->TimeFormat, sTime->Hours, sTime->Minutes, sTime->Seconds);

  hrtc->State = HAL_RTC_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hrtc);

  return status;
}

/**
  * @brief  Get RTC current time.
  * @note  You can use SubSeconds and SecondFraction (sTime structure fields returned) to convert SubSeconds
  *        value in second fraction ratio with time unit following generic formula:
  *        Second fraction ratio * time_unit= [(SecondFraction-SubSeconds)/(SecondFraction+1)] * time_unit
  *        This conversion can be performed only if no shift operation is pending (ie. SHFP=0) when PREDIV_S >= SS
  * @note  You must call HAL_RTC_GetDate() after HAL_RTC_GetTime() to unlock the values
  *        in the higher-order calendar shadow registers to ensure consistency between the time and date values.
  *        Reading RTC current time locks the values in calendar shadow registers until Current date is read
  *        to ensure consistency between the time and date values.
  * @param  hrtc RTC handle
  * @param  sTime Pointer to Time structure with Hours, Minutes and Seconds fields returned
  *                with input format (BIN or BCD), also SubSeconds field returning the
  *                RTC_SSR register content and SecondFraction field the Synchronous pre-scaler
  *                factor to be used for second fraction ratio computation.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_GetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime)
{
  uint32_t tmpreg;

  /* Check the parameters */
  assert_param(IS_RTC_FORMAT(Format));

  /* Fill the structure fields with the read parameters */
  sTime->Hours = (uint8_t)(LL_RTC_TIME_GetHour(hrtc->Instance));
  sTime->Minutes = (uint8_t)(LL_RTC_TIME_GetMinute(hrtc->Instance));
  sTime->Seconds = (uint8_t)(LL_RTC_TIME_GetSecond(hrtc->Instance));
  sTime->TimeFormat = (uint8_t)(LL_RTC_TIME_GetFormat(hrtc->Instance));

  sTime->DayLightSaving = LL_RTC_GetDayLightSaving(hrtc->Instance);

  return HAL_OK;
}

/**
  * @brief  Set RTC current date.
  * @param  hrtc RTC handle
  * @param  sDate Pointer to date structure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_SetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate)
{
  uint32_t datetmpreg;
  HAL_StatusTypeDef status = HAL_OK;  

 /* Check the parameters */
//  assert_param(IS_RTC_FORMAT(Format));

 /* Process Locked */
 __HAL_LOCK(hrtc);

  hrtc->State = HAL_RTC_STATE_BUSY;

  LL_RTC_DATE_Config(hrtc->Instance, sDate->WeekDay, sDate->Date, sDate->Month, sDate->Year);

  hrtc->State = HAL_RTC_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hrtc);

  return status;
}

/**
  * @brief  Get RTC current date.
  * @note  You must call HAL_RTC_GetDate() after HAL_RTC_GetTime() to unlock the values
  *        in the higher-order calendar shadow registers to ensure consistency between the time and date values.
  *        Reading RTC current time locks the values in calendar shadow registers until Current date is read.
  * @param  hrtc RTC handle
  * @param  sDate Pointer to Date structure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_GetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate)
{
  uint32_t datetmpreg;

  /* Check the parameters */
  assert_param(IS_RTC_FORMAT(Format));

  /* Fill the structure fields with the read parameters */
  sDate->Year = (uint16_t)(LL_RTC_DATE_GetYear(hrtc->Instance));
  sDate->Month = (uint8_t)(LL_RTC_DATE_GetMonth(hrtc->Instance));
  sDate->Date = (uint8_t)(LL_RTC_DATE_GetDay(hrtc->Instance));
  sDate->WeekDay = (uint8_t)(LL_RTC_DATE_GetWeekDay(hrtc->Instance));

  return HAL_OK;
}

/**
  * @}
  */

/** @addtogroup RTC_Exported_Functions_Group3
 *  @brief   RTC Alarm functions
 *
@verbatim
 ===============================================================================
                 ##### RTC Alarm functions #####
 ===============================================================================

 [..] This section provides functions allowing to configure Alarm feature

@endverbatim
  * @{
  */
/**
  * @brief  Set the specified RTC Alarm.
  * @param  hrtc RTC handle
  * @param  sAlarm Pointer to Alarm structure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_SetAlarm(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm)
{
  uint32_t tickstart;
  uint32_t tmpreg;
  uint32_t subsecondtmpreg;

  /* Check the parameters */
//  assert_param(IS_RTC_ALARM_DATE_WEEKDAY_SEL(sAlarm->AlarmDateWeekDaySel));

  /* Process Locked */
  __HAL_LOCK(hrtc);

  hrtc->State = HAL_RTC_STATE_BUSY;
	
	LL_RTC_ALM_SetWeekdaySel(0, sAlarm->AlarmDateWeekDaySel);
	LL_RTC_ALM_SetWeekDay(0, sAlarm->AlarmDateWeekDay);

  LL_RTC_ALM_ConfigTime(0, sAlarm->AlarmTime.TimeFormat, sAlarm->AlarmTime.Hours, sAlarm->AlarmTime.Minutes, sAlarm->AlarmTime.Seconds);

  /* Configure the Alarm state: Enable Alarm */
  __HAL_RTC_ALARM_ENABLE(hrtc);

  /* Change RTC state */
  hrtc->State = HAL_RTC_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hrtc);

  return HAL_OK;
}

/**
  * @brief  Set the specified RTC Alarm with Interrupt.
  * @note   The Alarm register can only be written when the corresponding Alarm
  *         is disabled (Use the HAL_RTC_DeactivateAlarm()).
  * @note   The HAL_RTC_SetTime() must be called before enabling the Alarm feature.
  * @param  hrtc RTC handle
  * @param  sAlarm Pointer to Alarm structure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_SetAlarm_IT(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm)
{
  uint32_t tickstart;
  uint32_t tmpreg;
  uint32_t subsecondtmpreg;

  /* Check the parameters */
//  assert_param(IS_RTC_ALARM_DATE_WEEKDAY_SEL(sAlarm->AlarmDateWeekDaySel));

  /* Process Locked */
//  __HAL_LOCK(hrtc);

//  hrtc->State = HAL_RTC_STATE_BUSY;

  HAL_RTC_SetAlarm(hrtc, sAlarm);

//  hrtc->State = HAL_RTC_STATE_READY;

  /* Process Unlocked */
//  __HAL_UNLOCK(hrtc);

  return HAL_OK;
}

/**
  * @brief  Deactivate the specified RTC Alarm.
  * @param  hrtc RTC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_DeactivateAlarm(RTC_HandleTypeDef *hrtc)
{
  uint32_t tickstart;

  /* Check the parameters */

  /* Process Locked */
  __HAL_LOCK(hrtc);

  hrtc->State = HAL_RTC_STATE_BUSY;


  /* AlarmA */
  __HAL_RTC_ALARM_DISABLE(hrtc);

  /* In case of interrupt mode is used, the interrupt source must disabled */
  __HAL_RTC_ALARM_DISABLE_IT(hrtc);

  tickstart = HAL_GetTick();

  /* Wait till RTC ALRxWF flag is set and if Time out is reached exit */
  while(__HAL_RTC_ALARM_GET_FLAG(hrtc) == 0U)
  {
    if( (HAL_GetTick()  - tickstart ) > RTC_TIMEOUT_VALUE)
    {
      /* Enable the write protection for RTC registers */
      hrtc->State = HAL_RTC_STATE_TIMEOUT;

      /* Process Unlocked */
      __HAL_UNLOCK(hrtc);

      return HAL_TIMEOUT;
    }
  }

  hrtc->State = HAL_RTC_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(hrtc);

  return HAL_OK;
}

/**
  * @brief  Get the RTC Alarm value and masks.
  * @param  hrtc RTC handle
  * @param  sAlarm Pointer to Date structure
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_GetAlarm(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm)
{
  uint32_t tmpreg;
  uint32_t subsecondtmpreg;

  /* Check the parameters */
//  assert_param(IS_RTC_FORMAT(Format));
//  assert_param(IS_RTC_ALARM(Alarm));

  /* Fill the structure with the read parameters */
  sAlarm->AlarmTime.Hours = (uint8_t)LL_RTC_ALM_GetHour(hrtc->Instance);
  sAlarm->AlarmTime.Minutes = (uint8_t)LL_RTC_ALM_GetMinute(hrtc->Instance);
  sAlarm->AlarmTime.Seconds = (uint8_t)LL_RTC_ALM_GetSecond(hrtc->Instance);
  sAlarm->AlarmTime.TimeFormat = (uint8_t)LL_RTC_ALM_GetTimeFormat(hrtc->Instance);
  sAlarm->AlarmDateWeekDay = (uint8_t)LL_RTC_ALM_GetDay(hrtc->Instance);
  sAlarm->AlarmDateWeekDaySel = (uint32_t)LL_RTC_ALM_GetWeekdaySel(hrtc->Instance);

  return HAL_OK;
}

/**
  * @brief  Handle Alarm interrupt request.
  * @param  hrtc RTC handle
  */
void HAL_RTC_AlarmIRQHandler(RTC_HandleTypeDef* hrtc)
{
  /* Clear the Alarm interrupt pending bit */
  __HAL_RTC_ALARM_CLEAR_FLAG(hrtc);

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
      /* Call Compare Match registered Callback */
      hrtc->AlarmEventCallback(hrtc);
#else
      /* AlarmA callback */
      HAL_RTC_AlarmEventCallback(hrtc);
#endif /* USE_HAL_RTC_REGISTER_CALLBACKS */

	 __HAL_RTC_ALARM_ENABLE(hrtc);

  /* Change RTC state */
  hrtc->State = HAL_RTC_STATE_READY;
}

/**
  * @brief  Alarm callback.
  * @param  hrtc RTC handle
  */
__weak void HAL_RTC_AlarmEventCallback(RTC_HandleTypeDef *hrtc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrtc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_RTC_AlarmAEventCallback could be implemented in the user file
   */
}

/**
  * @brief  Handle Alarm Polling request.
  * @param  hrtc RTC handle
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RTC_PollForAlarmEvent(RTC_HandleTypeDef *hrtc, uint32_t Timeout)
{

  uint32_t tickstart = HAL_GetTick();

  while(__HAL_RTC_ALARM_GET_FLAG(hrtc) == 0U)
  {
    if(Timeout != HAL_MAX_DELAY)
    {
      if(((HAL_GetTick() - tickstart ) > Timeout)||(Timeout == 0U))
      {
        hrtc->State = HAL_RTC_STATE_TIMEOUT;
        return HAL_TIMEOUT;
      }
    }
  }

  /* Clear the Alarm interrupt pending bit */
  __HAL_RTC_ALARM_CLEAR_FLAG(hrtc);

  /* Change RTC state */
  hrtc->State = HAL_RTC_STATE_READY;

  return HAL_OK;
}

/**
  * @}
  */

/** @addtogroup RTC_Exported_Functions_Group4
 *  @brief   Peripheral Control functions
 *
@verbatim
 ===============================================================================
                     ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides functions allowing to
      (+) Wait for RTC Time and Date Synchronization

@endverbatim
  * @{
  */
/**
  * @brief  RTC IRQ handler.
  * @param  hrtc RTC handle
  */
void              HAL_RTC_IRQHandler(RTC_HandleTypeDef *hrtc)
{
  /* Clear the Alarm interrupt pending bit */
 READ_REG(hrtc->Instance->EOI);

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
      /* Call Compare Match registered Callback */
      hrtc->IRQCallback(hrtc);
#else
      /* AlarmA callback */
      HAL_RTC_IRQCallback(hrtc);
#endif /* USE_HAL_RTC_REGISTER_CALLBACKS */

  /* Change RTC state */
  hrtc->State = HAL_RTC_STATE_READY;
}

/**
  * @brief  IRQ callback.
  * @param  hrtc RTC handle
  */
__weak void HAL_RTC_IRQCallback(RTC_HandleTypeDef *hrtc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hrtc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_RTC_AlarmAEventCallback could be implemented in the user file
   */
}
/**
  * @}
  */

/** @addtogroup RTC_Exported_Functions_Group5
 *  @brief   Peripheral State functions
 *
@verbatim
 ===============================================================================
                     ##### Peripheral State functions #####
 ===============================================================================
    [..]
    This subsection provides functions allowing to
      (+) Get RTC state

@endverbatim
  * @{
  */
/**
  * @brief  Return the RTC handle state.
  * @param  hrtc RTC handle
  * @retval HAL state
  */
HAL_RTCStateTypeDef HAL_RTC_GetState(RTC_HandleTypeDef* hrtc)
{
  /* Return RTC handle state */
  return hrtc->State;
}

/**
  * @}
  */
/**
  * @}
  */

/** @addtogroup RTC_Private_Functions
  * @{
  */
/**
  * @}
  */

#endif /* HAL_RTC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
