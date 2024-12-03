/**
  ******************************************************************************
  * @file    xt32h0xx_ll_rtc.c
  * @author  Software Team
  * @brief   RTC LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by XTX under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the 
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_rtc.h"
#include "xt32h0xx_ll_cortex.h"
#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined(RTC)

/** @addtogroup RTC_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup RTC_LL_Private_Variables RTC Private Variables
  * @{
  */
LL_RTC_AlarmTypeDef RTC_ALARM;
uint32_t RTC_CALENDAR;                    /* bit 0 : FMT  hour format 12/24  0: 24; 1: AMPM */
                                          /* bit 1 : DST  daylight saving enable    0 : disnable; 1: enable */
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/* Private constants ---------------------------------------------------------*/
/** @addtogroup RTC_LL_Private_Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup RTC_LL_Private_Macros
  * @{
  */

#define IS_LL_RTC_HOURFORMAT(__VALUE__) (((__VALUE__) == LL_RTC_HOURFORMAT_24HOUR) \
                                      || ((__VALUE__) == LL_RTC_HOURFORMAT_AMPM))

#define IS_LL_RTC_TIME_FORMAT(__VALUE__) (((__VALUE__) == LL_RTC_TIME_FORMAT_AM_OR_24) \
                                       || ((__VALUE__) == LL_RTC_TIME_FORMAT_PM))

#define IS_LL_RTC_HOUR12(__HOUR__)            (((__HOUR__) > 0U) && ((__HOUR__) <= 12U))
#define IS_LL_RTC_HOUR24(__HOUR__)            ((__HOUR__) <= 23U)
#define IS_LL_RTC_MINUTES(__MINUTES__)        ((__MINUTES__) <= 59U)
#define IS_LL_RTC_SECONDS(__SECONDS__)        ((__SECONDS__) <= 59U)

#define IS_LL_RTC_WEEKDAY(__VALUE__) (((__VALUE__) == LL_RTC_WEEKDAY_MONDAY) \
                                   || ((__VALUE__) == LL_RTC_WEEKDAY_TUESDAY) \
                                   || ((__VALUE__) == LL_RTC_WEEKDAY_WEDNESDAY) \
                                   || ((__VALUE__) == LL_RTC_WEEKDAY_THURSDAY) \
                                   || ((__VALUE__) == LL_RTC_WEEKDAY_FRIDAY) \
                                   || ((__VALUE__) == LL_RTC_WEEKDAY_SATURDAY) \
                                   || ((__VALUE__) == LL_RTC_WEEKDAY_SUNDAY))

#define IS_LL_RTC_DAY(__DAY__)    (((__DAY__) >= 1U) && ((__DAY__) <= 31U))

#define IS_LL_RTC_MONTH(__MONTH__) (((__MONTH__) >= 0U) && ((__MONTH__) <= 11U))

#define IS_LL_RTC_YEAR(__YEAR__) ((__YEAR__) >= 1900U)

#define IS_LL_RTC_ALM_DATE_WEEKDAY_SEL(__SEL__) (((__SEL__) == LL_RTC_ALMA_DATEWEEKDAYSEL_DATE) || \
                                                 ((__SEL__) == LL_RTC_ALMA_DATEWEEKDAYSEL_WEEKDAY) || \
                                                 ((__SEL__) == LL_RTC_ALMA_DATEWEEKDAYSEL_WORKDAY) || \
                                                 ((__SEL__) == LL_RTC_ALMA_DATEWEEKDAYSEL_EVERYDAY))

/**
  * @}
  */
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup RTC_LL_Exported_Functions
  * @{
  */

/** @addtogroup RTC_LL_Exported_Functions_Group5
  * @{
  */

/**
  * @brief  De-Initializes the RTC registers to their default reset values.
  * @note   This function does not reset the RTC Clock source and RTC Backup Data
  *         registers.
  * @param  RTCx RTC Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are de-initialized
  *          - ERROR: RTC registers are not de-initialized
  */
ErrorStatus LL_RTC_DeInit(RTC_TypeDef *RTCx)
{
  ErrorStatus status = ERROR;

  /* Check the parameter */
  assert_param(IS_RTC_ALL_INSTANCE(RTCx));

  /* Disable the write protection for RTC registers */
//  LL_RTC_DisableWriteProtection(RTCx);
//
//  /* Set Initialization mode */
//  if (LL_RTC_EnterInitMode(RTCx) != ERROR)
//  {
//    /* Reset TR, DR and CR registers */
//    WRITE_REG(RTCx->TR,       0x00000000U);
//#if defined(RTC_WAKEUP_SUPPORT)
//    WRITE_REG(RTCx->WUTR,     RTC_WUTR_WUT);
//#endif /* RTC_WAKEUP_SUPPORT */
//    WRITE_REG(RTCx->DR  ,     (RTC_DR_WDU_0 | RTC_DR_MU_0 | RTC_DR_DU_0));
//    /* Reset All CR bits except CR[2:0] */
//#if defined(RTC_WAKEUP_SUPPORT)
//    WRITE_REG(RTCx->CR, (READ_REG(RTCx->CR) & RTC_CR_WUCKSEL));
//#else
//    WRITE_REG(RTCx->CR, 0x00000000U);
//#endif /* RTC_WAKEUP_SUPPORT */
//    WRITE_REG(RTCx->PRER,     (RTC_PRER_PREDIV_A | RTC_SYNCH_PRESC_DEFAULT));
//    WRITE_REG(RTCx->ALRMAR,   0x00000000U);
//    WRITE_REG(RTCx->ALRMBR,   0x00000000U);
//    WRITE_REG(RTCx->SHIFTR,   0x00000000U);
//    WRITE_REG(RTCx->CALR,     0x00000000U);
//    WRITE_REG(RTCx->ALRMASSR, 0x00000000U);
//    WRITE_REG(RTCx->ALRMBSSR, 0x00000000U);
//
//    /* Exit Initialization mode */
//    LL_RTC_DisableInitMode(RTCx);
//
//    /* Wait till the RTC RSF flag is set */
//    status = LL_RTC_WaitForSynchro(RTCx);
//  }
//
//  /* Enable the write protection for RTC registers */
//  LL_RTC_EnableWriteProtection(RTCx);

  LL_RTC_DisableCounter(RTCx);
  LL_RTC_ALM_Disable(RTCx);

  status = SUCCESS;

  return status;
}

/**
  * @brief  Initializes the RTC registers according to the specified parameters
  *         in RTC_InitStruct.
  * @param  RTCx RTC Instance
  * @param  RTC_InitStruct pointer to a @ref LL_RTC_InitTypeDef structure that contains
  *         the configuration information for the RTC peripheral.
  * @note   The RTC Prescaler register is write protected and can be written in
  *         initialization mode only.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC registers are initialized
  *          - ERROR: RTC registers are not initialized
  */
ErrorStatus LL_RTC_Init(RTC_TypeDef *RTCx, LL_RTC_InitTypeDef *RTC_InitStruct)
{
  ErrorStatus status = ERROR;

  /* Check the parameters */
  assert_param(IS_RTC_ALL_INSTANCE(RTCx));
  assert_param(IS_LL_RTC_HOURFORMAT(RTC_InitStruct->HourFormat));
//  assert_param(IS_LL_RTC_ASYNCH_PREDIV(RTC_InitStruct->AsynchPrescaler));
//  assert_param(IS_LL_RTC_SYNCH_PREDIV(RTC_InitStruct->SynchPrescaler));

  /* Disable the write protection for RTC registers */
//  LL_RTC_DisableWriteProtection(RTCx);
//
//  /* Set Initialization mode */
//  if (LL_RTC_EnterInitMode(RTCx) != ERROR)
//  {
//    /* Set Hour Format */
  LL_RTC_SetHourFormat(RTCx, RTC_InitStruct->HourFormat);
//
//    /* Configure Synchronous and Asynchronous prescaler factor */
//    LL_RTC_SetSynchPrescaler(RTCx, RTC_InitStruct->SynchPrescaler);
//    LL_RTC_SetAsynchPrescaler(RTCx, RTC_InitStruct->AsynchPrescaler);
//
//    /* Exit Initialization mode */
//    LL_RTC_DisableInitMode(RTCx);
//
//    status = SUCCESS;
//  }
//  /* Enable the write protection for RTC registers */
//  LL_RTC_EnableWriteProtection(RTCx);
  LL_RTC_DisableWrap(RTCx);
  LL_RTC_EnableCounter(RTCx);
  status = SUCCESS;
  return status;
}

/**
  * @brief  Set each @ref LL_RTC_InitTypeDef field to default value.
  * @param  RTC_InitStruct pointer to a @ref LL_RTC_InitTypeDef structure which will be initialized.
  */
void LL_RTC_StructInit(LL_RTC_InitTypeDef *RTC_InitStruct)
{
  /* Set RTC_InitStruct fields to default values */
  RTC_InitStruct->HourFormat      = LL_RTC_HOURFORMAT_24HOUR;
//  RTC_InitStruct->AsynchPrescaler = RTC_ASYNCH_PRESC_DEFAULT;
//  RTC_InitStruct->SynchPrescaler  = RTC_SYNCH_PRESC_DEFAULT;
}

/**
  * @brief  Set the RTC current time.
  * @param  RTCx RTC Instance
  * @param  RTC_TimeStruct pointer to a RTC_TimeTypeDef structure that contains
  *                        the time configuration information for the RTC.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Time register is configured
  *          - ERROR: RTC Time register is not configured
  */
ErrorStatus LL_RTC_TIME_Init(RTC_TypeDef *RTCx, LL_RTC_TimeTypeDef *RTC_TimeStruct)
{
  ErrorStatus status = ERROR;

  /* Check the parameters */
  assert_param(IS_RTC_ALL_INSTANCE(RTCx));

  if (LL_RTC_GetHourFormat(RTCx) != LL_RTC_HOURFORMAT_24HOUR)
  {
    assert_param(IS_LL_RTC_HOUR12(RTC_TimeStruct->Hours));
    assert_param(IS_LL_RTC_TIME_FORMAT(RTC_TimeStruct->TimeFormat));
  }
  else
  {
    RTC_TimeStruct->TimeFormat = 0x00U;
    assert_param(IS_LL_RTC_HOUR24(RTC_TimeStruct->Hours));
  }
  assert_param(IS_LL_RTC_MINUTES(RTC_TimeStruct->Minutes));
  assert_param(IS_LL_RTC_SECONDS(RTC_TimeStruct->Seconds));

  /* Disable the write protection for RTC registers */
//  LL_RTC_DisableWriteProtection(RTCx);

  /* Set Initialization mode */
//  if (LL_RTC_EnterInitMode(RTCx) != ERROR)
//  {
    /* Check the input parameters format */
//    if (RTC_Format != LL_RTC_FORMAT_BIN)
//    {
  LL_RTC_TIME_Config(RTCx, RTC_TimeStruct->TimeFormat, RTC_TimeStruct->Hours,
                         RTC_TimeStruct->Minutes, RTC_TimeStruct->Seconds);
//    }
//    else
//    {
//      LL_RTC_TIME_Config(RTCx, RTC_TimeStruct->TimeFormat, __LL_RTC_CONVERT_BIN2BCD(RTC_TimeStruct->Hours),
//                         __LL_RTC_CONVERT_BIN2BCD(RTC_TimeStruct->Minutes),
//                         __LL_RTC_CONVERT_BIN2BCD(RTC_TimeStruct->Seconds));
//    }

    /* Exit Initialization mode */
//    LL_RTC_DisableInitMode(RTCx);

    /* If  RTC_CR_BYPSHAD bit = 0, wait for synchro else this check is not needed */
//    if (LL_RTC_IsShadowRegBypassEnabled(RTCx) == 0U)
//    {
//      status = LL_RTC_WaitForSynchro(RTCx);
//    }
//    else
//    {
  status = SUCCESS;
//    }
//  }
  /* Enable the write protection for RTC registers */
//  LL_RTC_EnableWriteProtection(RTCx);

  return status;
}

/**
  * @brief  Set each @ref LL_RTC_TimeTypeDef field to default value (Time = 00h:00min:00sec).
  * @param  RTC_TimeStruct pointer to a @ref LL_RTC_TimeTypeDef structure which will be initialized.
  */
void LL_RTC_TIME_StructInit(LL_RTC_TimeTypeDef *RTC_TimeStruct)
{
  /* Time = 00h:00min:00sec */
  RTC_TimeStruct->TimeFormat = LL_RTC_TIME_FORMAT_AM_OR_24;
  RTC_TimeStruct->Hours      = 0U;
  RTC_TimeStruct->Minutes    = 0U;
  RTC_TimeStruct->Seconds    = 0U;
}

/**
  * @brief  Set the RTC current date.
  * @param  RTCx RTC Instance
  * @param  RTC_DateStruct pointer to a RTC_DateTypeDef structure that contains
  *                         the date configuration information for the RTC.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RTC Day register is configured
  *          - ERROR: RTC Day register is not configured
  */
ErrorStatus LL_RTC_DATE_Init(RTC_TypeDef *RTCx, LL_RTC_DateTypeDef *RTC_DateStruct)
{
  ErrorStatus status = ERROR;

  /* Check the parameters */
  assert_param(IS_RTC_ALL_INSTANCE(RTCx));
  assert_param(IS_LL_RTC_FORMAT(RTC_Format));

  assert_param(IS_LL_RTC_YEAR(RTC_DateStruct->Year));
  assert_param(IS_LL_RTC_MONTH(RTC_DateStruct->Month));
  assert_param(IS_LL_RTC_DAY(RTC_DateStruct->Day));
  assert_param(IS_LL_RTC_WEEKDAY(RTC_DateStruct->WeekDay));

  /* Disable the write protection for RTC registers */
//  LL_RTC_DisableWriteProtection(RTCx);

  /* Set Initialization mode */
//  if (LL_RTC_EnterInitMode(RTCx) != ERROR)
//  {
//    /* Check the input parameters format */
//    if (RTC_Format != LL_RTC_FORMAT_BIN)
//    {
  LL_RTC_DATE_Config(RTCx, (uint32_t)RTC_DateStruct->WeekDay, (uint32_t)RTC_DateStruct->Day, (uint32_t)RTC_DateStruct->Month, (uint32_t)RTC_DateStruct->Year+100);
//    }
//    else
//    {
//      LL_RTC_DATE_Config(RTCx, RTC_DateStruct->WeekDay, __LL_RTC_CONVERT_BIN2BCD(RTC_DateStruct->Day),
//                         __LL_RTC_CONVERT_BIN2BCD(RTC_DateStruct->Month), __LL_RTC_CONVERT_BIN2BCD(RTC_DateStruct->Year));
//    }
//
//    /* Exit Initialization mode */
//    LL_RTC_DisableInitMode(RTCx);

    /* If  RTC_CR_BYPSHAD bit = 0, wait for synchro else this check is not needed */
//    if (LL_RTC_IsShadowRegBypassEnabled(RTCx) == 0U)
//    {
//      status = LL_RTC_WaitForSynchro(RTCx);
//    }
//    else
//    {
  status = SUCCESS;
//    }
//  }
//  /* Enable the write protection for RTC registers */
//  LL_RTC_EnableWriteProtection(RTCx);

  return status;
}

/**
  * @brief  Set each @ref LL_RTC_DateTypeDef field to default value (date = Monday, January 01 xx00)
  * @param  RTC_DateStruct pointer to a @ref LL_RTC_DateTypeDef structure which will be initialized.
  */
void LL_RTC_DATE_StructInit(LL_RTC_DateTypeDef *RTC_DateStruct)
{
  /* Wednesday, January 01 2020 */
  RTC_DateStruct->WeekDay = LL_RTC_WEEKDAY_WEDNESDAY;
  RTC_DateStruct->Day     = 1;
  RTC_DateStruct->Month   = LL_RTC_MONTH_JANUARY;
  RTC_DateStruct->Year    = 20;  /*2020*/
}

/**
  * @brief  Set the RTC Alarm.
  * @param  RTCx RTC Instance
  * @param  RTC_AlarmStruct pointer to a @ref LL_RTC_AlarmTypeDef structure that
  *                         contains the alarm configuration parameters.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ALARMA registers are configured
  *          - ERROR: ALARMA registers are not configured
  */
ErrorStatus LL_RTC_ALM_Init(RTC_TypeDef *RTCx, LL_RTC_AlarmTypeDef *RTC_AlarmStruct)
{
  /* Check the parameters */
  assert_param(IS_RTC_ALL_INSTANCE(RTCx));
  assert_param(IS_LL_RTC_FORMAT(RTC_Format));
//  assert_param(IS_LL_RTC_ALM_MASK(RTC_AlarmStruct->AlarmMask));
  assert_param(IS_LL_RTC_ALM_DATE_WEEKDAY_SEL(RTC_AlarmStruct->AlarmDateWeekDaySel));

  if (LL_RTC_GetHourFormat(RTCx) != LL_RTC_HOURFORMAT_24HOUR)
  {
    assert_param(IS_LL_RTC_HOUR12(RTC_AlarmStruct->AlarmTime.Hours));
    assert_param(IS_LL_RTC_TIME_FORMAT(RTC_AlarmStruct->AlarmTime.TimeFormat));
  }
  else
  {
    RTC_AlarmStruct->AlarmTime.TimeFormat = 0x00U;
    assert_param(IS_LL_RTC_HOUR24(RTC_AlarmStruct->AlarmTime.Hours));
  }
  assert_param(IS_LL_RTC_MINUTES(RTC_AlarmStruct->AlarmTime.Minutes));
  assert_param(IS_LL_RTC_SECONDS(RTC_AlarmStruct->AlarmTime.Seconds));
  if (RTC_AlarmStruct->AlarmDateWeekDaySel == LL_RTC_ALM_DATEWEEKDAYSEL_DATE)
  {
    assert_param(IS_LL_RTC_DAY(RTC_AlarmStruct->AlarmDateWeekDay));
  }
  else if (RTC_AlarmStruct->AlarmDateWeekDaySel == LL_RTC_ALM_DATEWEEKDAYSEL_WEEKDAY)
  {
    assert_param(IS_LL_RTC_WEEKDAY(RTC_AlarmStruct->AlarmDateWeekDay));
  }

  /* Disable the write protection for RTC registers */

  /* Select weekday selection */
  LL_RTC_ALM_SetWeekdaySel(RTCx, RTC_AlarmStruct->AlarmDateWeekDaySel);
  if (RTC_AlarmStruct->AlarmDateWeekDaySel == LL_RTC_ALM_DATEWEEKDAYSEL_DATE)
  {
    /* Set the date for ALARM */
    LL_RTC_ALM_SetDay(RTCx, RTC_AlarmStruct->AlarmDateWeekDay);
  }
  else if (RTC_AlarmStruct->AlarmDateWeekDaySel == LL_RTC_ALM_DATEWEEKDAYSEL_WEEKDAY)
  {
    /* Set the week day for ALARM */
    LL_RTC_ALM_SetWeekDay(RTCx, RTC_AlarmStruct->AlarmDateWeekDay);
  }

  /* Configure the Alarm register */
  LL_RTC_ALM_ConfigTime(RTCx, RTC_AlarmStruct->AlarmTime.TimeFormat, RTC_AlarmStruct->AlarmTime.Hours,
                           RTC_AlarmStruct->AlarmTime.Minutes, RTC_AlarmStruct->AlarmTime.Seconds);

  return SUCCESS;
}

/**
  * @brief  Set each @ref LL_RTC_AlarmTypeDef of ALARMA field to default value (Time = 00h:00mn:00sec /
  *         Day = 1st day of the month/Mask = all fields are masked).
  * @param  RTC_AlarmStruct pointer to a @ref LL_RTC_AlarmTypeDef structure which will be initialized.
  */
void LL_RTC_ALM_StructInit(LL_RTC_AlarmTypeDef *RTC_AlarmStruct)
{
  /* Alarm Time Settings : Time = 00h:00mn:00sec */
  RTC_AlarmStruct->AlarmTime.TimeFormat = LL_RTC_ALM_TIME_FORMAT_AM;
  RTC_AlarmStruct->AlarmTime.Hours      = 0U;
  RTC_AlarmStruct->AlarmTime.Minutes    = 0U;
  RTC_AlarmStruct->AlarmTime.Seconds    = 0U;

  /* Alarm Day Settings : Day = 1st day of the month */
  RTC_AlarmStruct->AlarmDateWeekDaySel = LL_RTC_ALM_DATEWEEKDAYSEL_DATE;
  RTC_AlarmStruct->AlarmDateWeekDay    = 1U;

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
#endif /* USE_FULL_LL_DRIVER */

#endif /* defined(RTC) */

/**
  * @}
  */


/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
