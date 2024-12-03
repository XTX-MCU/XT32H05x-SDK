/**
  ******************************************************************************
  * @file    xt32h0xx_ll_rtc.h
  * @author  Software Team
  * @brief   Header file of RTC LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_RTC_H
#define XT32H0xx_LL_RTC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <time.h>

#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined(RTC)

/** @defgroup RTC_LL RTC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup RTC_LL_Private_Constants RTC Private Constants
  * @{
  */

/* Defines used to combine date & time */
#define RTC_OFFSET_WEEKDAY             ((uint32_t)24U)                         /*WWDDMMYY*/
#define RTC_OFFSET_DAY                 ((uint32_t)16U)
#define RTC_OFFSET_MONTH               ((uint32_t)8U)
#define RTC_OFFSET_YEAR                ((uint32_t)0U)                          /*since 2000*/
#define RTC_OFFSET_HOUR                ((uint32_t)16U)                         /*00HHMMSS*/
#define RTC_OFFSET_MINUTE              ((uint32_t)8U)
#define RTC_OFFSET_SECOND              ((uint32_t)0U)

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RTC_LL_Private_Macros RTC Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Types RTC Exported Types
  * @{
  */
/** @defgroup RTC_LL_ES_INIT RTC Exported Init structure
  * @{
  */

/**
  * @brief  RTC Init structures definition
  */
typedef struct
{
  uint32_t HourFormat;   /*!< Specifies the RTC Hours Format.
                              This parameter can be a value of @ref RTC_LL_EC_HOURFORMAT

                              This feature can be modified afterwards using unitary function
                              @ref LL_RTC_SetHourFormat(). */

  uint32_t CounterInitVal;   /*!< Specified the RTC a start value that allow the counter to increment
                               This parameter must be a number between 0 and 0xFFFFFFFF (based on RTC_CNT_WIDTH)

                               This feature can be modified afterwards using unitary function
                               @ref LL_RTC_SetTimeStampInit(). */

} LL_RTC_InitTypeDef;

/**
  * @brief  RTC Time structure definition
  */
typedef struct
{
  uint32_t TimeFormat; /*!< Specifies the RTC AM/PM Time.
                            This parameter can be a value of @ref RTC_LL_EC_TIME_FORMAT

                            This feature can be modified afterwards using unitary function @ref LL_RTC_TIME_SetFormat(). */

  uint8_t Hours;       /*!< Specifies the RTC Time Hours.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 11 if the @ref LL_RTC_TIME_FORMAT_PM is selected.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 23 if the @ref LL_RTC_TIME_FORMAT_AM_OR_24 is selected.

                            This feature can be modified afterwards using unitary function @ref LL_RTC_TIME_SetHour(). */

  uint8_t Minutes;     /*!< Specifies the RTC Time Minutes.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 59

                            This feature can be modified afterwards using unitary function @ref LL_RTC_TIME_SetMinute(). */

  uint8_t Seconds;     /*!< Specifies the RTC Time Seconds.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 59

                            This feature can be modified afterwards using unitary function @ref LL_RTC_TIME_SetSecond(). */
	
	uint8_t dumy;
} LL_RTC_TimeTypeDef;

/**
  * @brief  RTC Date structure definition
  */
typedef struct
{
  uint8_t WeekDay;  /*!< Specifies the RTC Date WeekDay.
                         This parameter can be a value of @ref RTC_LL_EC_WEEKDAY between Min_Data = 0 and Max_Data = 6

                         This feature can be modified afterwards using unitary function @ref LL_RTC_DATE_SetWeekDay(). */

  uint8_t Month;    /*!< Specifies the RTC Date Month.
                         This parameter can be a value of @ref RTC_LL_EC_MONTH between Min_Data = 0 and Max_Data = 11

                         This feature can be modified afterwards using unitary function @ref LL_RTC_DATE_SetMonth(). */

  uint8_t Day;      /*!< Specifies the RTC Date Day.
                         This parameter must be a number between Min_Data = 1 and Max_Data = 31

                         This feature can be modified afterwards using unitary function @ref LL_RTC_DATE_SetDay(). */

  uint8_t Year;     /*!< Specifies the RTC Date Year.
                         This parameter must be a number between Min_Data = 0 and Max_Data = 127 since 2000

                         This feature can be modified afterwards using unitary function @ref LL_RTC_DATE_SetYear(). */
} LL_RTC_DateTypeDef;

/**
  * @brief  RTC Alarm structure definition
  */
typedef struct
{
  LL_RTC_TimeTypeDef AlarmTime;  /*!< Specifies the RTC Alarm Time members. */

  uint32_t AlarmDateWeekDaySel;  /*!< Specifies the RTC Alarm is on day or WeekDay.
                                      This parameter can be a value of @ref RTC_LL_EC_ALMA_WEEKDAY_SELECTION for ALARM.

                                      This feature can be modified afterwards using unitary function @ref LL_RTC_ALM_SetWeekDay() 
                                      or @ref LL_RTC_ALM_GetWeekDay() for ALARM.
                                 */

  uint32_t AlarmDateWeekDay;      /*!< Specifies the RTC Alarm Day/WeekDay.
                                      If AlarmDateWeekDaySel set to day, can be a value of 1 to 31 (@ref RTC_LL_EC_ALMA_DAY for ALARM).

                                      This feature can be modified afterwards using unitary function @ref LL_RTC_ALM_SetDay().

                                      If AlarmDateWeekDaySel set to Weekday, this parameter can be a value of @ref RTC_LL_EC_WEEKDAY (@ref RTC_LL_EC_ALMA_WEEKDAY).

                                      This feature can be modified afterwards using unitary function @ref LL_RTC_ALM_SetWeekDay().
                                 */

  uint32_t IsEnable;             /*!< Specifies the RTC Alarm enable.
                                      1: alarm enable; 0: alarm disable. 
                                 */

  uint32_t Status;               /*!< Specifies the RTC Alarm Status.
                                      1: alarm event; 0: no event .
                                 */
} LL_RTC_AlarmTypeDef;

extern LL_RTC_AlarmTypeDef RTC_ALARM;
extern uint32_t RTC_CALENDAR;                    /* bit 0 : FMT  hour format 12/24  0: 24; 1: AM/PM */
                                                 /* bit 1 : DST  daylight saving enable    0 : disnable; 1: enable */

/**
  * @}
  */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Constants RTC Exported Constants
  * @{
  */

/** @defgroup RTC_LL_EC_ALMA_WEEKDAY_SELECTION RTC Alarm Date
  * @{
  */
#define LL_RTC_ALM_DATEWEEKDAYSEL_DATE     (0x00000000U)                       /*!< Alarm A Date is selected */
#define LL_RTC_ALM_DATEWEEKDAYSEL_WEEKDAY  (0x00000001U)                       /*!< Alarm A WeekDay is selected */
#define LL_RTC_ALM_DATEWEEKDAYSEL_WORKDAY  (0x00000002U)                       /*!< Alarm WorkDay is selected */
#define LL_RTC_ALM_DATEWEEKDAYSEL_EVERYDAY (0x00000004U)                       /*!< Alarm EveryDay is selected */
#define LL_RTC_ALM_DATEWEEKDAYSEL_ONCE     (0x00000008U)                       /*!< Alarm Once is selected */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALMA_DAY RTC Alarm Date Day
  * @{
  */
#define LL_RTC_ALM_DAY_1                   (0x00000001UL)                      /*!< Alarm A Date 1 */
#define LL_RTC_ALM_DAY_2                   (0x00000001UL << 1)                 /*!< Alarm A Date 2 */
#define LL_RTC_ALM_DAY_3                   (0x00000001UL << 2)                 /*!< Alarm A Date 3 */
#define LL_RTC_ALM_DAY_4                   (0x00000001UL << 3)                 /*!< Alarm A Date 4 */
#define LL_RTC_ALM_DAY_5                   (0x00000001UL << 4)                 /*!< Alarm A Date 5 */
#define LL_RTC_ALM_DAY_6                   (0x00000001UL << 5)                 /*!< Alarm A Date 6 */
#define LL_RTC_ALM_DAY_7                   (0x00000001UL << 6)                 /*!< Alarm A Date 7 */
#define LL_RTC_ALM_DAY_8                   (0x00000001UL << 7)                 /*!< Alarm A Date 8 */
#define LL_RTC_ALM_DAY_9                   (0x00000001UL << 8)                 /*!< Alarm A Date 9 */
#define LL_RTC_ALM_DAY_10                  (0x00000001UL << 9)                 /*!< Alarm A Date 10 */
#define LL_RTC_ALM_DAY_11                  (0x00000001UL << 10)                /*!< Alarm A Date 11 */
#define LL_RTC_ALM_DAY_12                  (0x00000001UL << 11)                /*!< Alarm A Date 12 */
#define LL_RTC_ALM_DAY_13                  (0x00000001UL << 12)                /*!< Alarm A Date 13 */
#define LL_RTC_ALM_DAY_14                  (0x00000001UL << 13)                /*!< Alarm A Date 14 */
#define LL_RTC_ALM_DAY_15                  (0x00000001UL << 14)                /*!< Alarm A Date 15 */
#define LL_RTC_ALM_DAY_16                  (0x00000001UL << 15)                /*!< Alarm A Date 16 */
#define LL_RTC_ALM_DAY_17                  (0x00000001UL << 16)                /*!< Alarm A Date 17 */
#define LL_RTC_ALM_DAY_18                  (0x00000001UL << 17)                /*!< Alarm A Date 18 */
#define LL_RTC_ALM_DAY_19                  (0x00000001UL << 18)                /*!< Alarm A Date 19 */
#define LL_RTC_ALM_DAY_20                  (0x00000001UL << 19)                /*!< Alarm A Date 20 */
#define LL_RTC_ALM_DAY_21                  (0x00000001UL << 20)                /*!< Alarm A Date 21 */
#define LL_RTC_ALM_DAY_22                  (0x00000001UL << 21)                /*!< Alarm A Date 22 */
#define LL_RTC_ALM_DAY_23                  (0x00000001UL << 22)                /*!< Alarm A Date 23 */
#define LL_RTC_ALM_DAY_24                  (0x00000001UL << 23)                /*!< Alarm A Date 24 */
#define LL_RTC_ALM_DAY_25                  (0x00000001UL << 24)                /*!< Alarm A Date 25 */
#define LL_RTC_ALM_DAY_26                  (0x00000001UL << 25)                /*!< Alarm A Date 26 */
#define LL_RTC_ALM_DAY_27                  (0x00000001UL << 26)                /*!< Alarm A Date 27 */
#define LL_RTC_ALM_DAY_28                  (0x00000001UL << 27)                /*!< Alarm A Date 28 */
#define LL_RTC_ALM_DAY_29                  (0x00000001UL << 28)                /*!< Alarm A Date 29 */
#define LL_RTC_ALM_DAY_30                  (0x00000001UL << 29)                /*!< Alarm A Date 30 */
#define LL_RTC_ALM_DAY_31                  (0x00000001UL << 30)                /*!< Alarm A Date 31 */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALMA_WEEKDAY RTC Alarm Date Week Day
  * @{
  */
#define RTC_LL_EC_ALMA_MONDAY              (0x00000001UL)                      /*!< Alarm A Monday */
#define RTC_LL_EC_ALMA_TUESDAY             (0x00000002UL)                      /*!< Alarm A Tuesday */
#define RTC_LL_EC_ALMA_WEDNESDAY           (0x00000004UL)                      /*!< Alarm A Wednesday */
#define RTC_LL_EC_ALMA_THURSDAY            (0x00000008UL)                      /*!< Alarm A Thursday */
#define RTC_LL_EC_ALMA_FRIDAY              (0x00000010UL)                      /*!< Alarm A Friday */
#define RTC_LL_EC_ALMA_SATURDAY            (0x00000020UL)                      /*!< Alarm A Saturday */
#define RTC_LL_EC_ALMA_SUNDAY              (0x00000040UL)                      /*!< Alarm A Sunday */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_WEEKDAY  RTC Week Day
  * @{
  */
#define LL_RTC_WEEKDAY_MONDAY              ((uint8_t)0x00U)                    /*!< Monday    */
#define LL_RTC_WEEKDAY_TUESDAY             ((uint8_t)0x01U)                    /*!< Tuesday   */
#define LL_RTC_WEEKDAY_WEDNESDAY           ((uint8_t)0x02U)                    /*!< Wednesday */
#define LL_RTC_WEEKDAY_THURSDAY            ((uint8_t)0x03U)                    /*!< Thursday  */
#define LL_RTC_WEEKDAY_FRIDAY              ((uint8_t)0x04U)                    /*!< Friday    */
#define LL_RTC_WEEKDAY_SATURDAY            ((uint8_t)0x05U)                    /*!< Saturday  */
#define LL_RTC_WEEKDAY_SUNDAY              ((uint8_t)0x06U)                    /*!< Sunday    */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_MONTH  RTC Month
  * @{
  */
#define LL_RTC_MONTH_JANUARY               ((uint8_t)0x00U)                    /*!< January   */
#define LL_RTC_MONTH_FEBRUARY              ((uint8_t)0x01U)                    /*!< February  */
#define LL_RTC_MONTH_MARCH                 ((uint8_t)0x02U)                    /*!< March     */
#define LL_RTC_MONTH_APRIL                 ((uint8_t)0x03U)                    /*!< April     */
#define LL_RTC_MONTH_MAY                   ((uint8_t)0x04U)                    /*!< May       */
#define LL_RTC_MONTH_JUNE                  ((uint8_t)0x05U)                    /*!< June      */
#define LL_RTC_MONTH_JULY                  ((uint8_t)0x06U)                    /*!< July      */
#define LL_RTC_MONTH_AUGUST                ((uint8_t)0x07U)                    /*!< August    */
#define LL_RTC_MONTH_SEPTEMBER             ((uint8_t)0x08U)                    /*!< September */
#define LL_RTC_MONTH_OCTOBER               ((uint8_t)0x09U)                    /*!< October   */
#define LL_RTC_MONTH_NOVEMBER              ((uint8_t)0x0AU)                    /*!< November  */
#define LL_RTC_MONTH_DECEMBER              ((uint8_t)0x0BU)                    /*!< December  */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_HOURFORMAT  HOUR FORMAT
  * @{
  */
#define LL_RTC_HOURFORMAT_24HOUR           (0x00000000U)                       /*!< 24 hour/day format */
#define LL_RTC_HOURFORMAT_AMPM             (0x00000001U)                       /*!< AM/PM hour format */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TIME_FORMAT TIME FORMAT
  * @{
  */
#define LL_RTC_TIME_FORMAT_AM_OR_24        (LL_RTC_HOURFORMAT_24HOUR)          /*!< AM or 24-hour format */
#define LL_RTC_TIME_FORMAT_PM              (LL_RTC_HOURFORMAT_AMPM)            /*!< PM */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_ALM_TIME_FORMAT  ALARM TIME FORMAT
  * @{
  */
#define LL_RTC_ALM_TIME_FORMAT_AM          (LL_RTC_HOURFORMAT_24HOUR)          /*!< AM or 24-hour format */
#define LL_RTC_ALM_TIME_FORMAT_PM          (LL_RTC_HOURFORMAT_AMPM)            /*!< PM */
/**
  * @}
  */

/** @defgroup RTC_LL_EC_TIME_SUNLIGHT  Sunlight
  * @{
  */
#define LL_RTC_TIME_DAYLIGHTSAVING_DISABLE          (0x00000000UL)            /*!< daylight saving time disable*/
#define LL_RTC_TIME_DAYLIGHTSAVING_ENABLE           (0x00000002UL)            /*!< daylight saving time enable */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Macros RTC Exported Macros
  * @{
  */

/** @defgroup RTC_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in RTC register
  * @param  __INSTANCE__ RTC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_RTC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in RTC register
  * @param  __INSTANCE__ RTC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_RTC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup RTC_LL_EM_Date Date helper Macros
  * @{
  */

/**
  * @brief  Helper macro to retrieve weekday.
  * @param  __RTC_DATE__ Date returned by @ref  LL_RTC_DATE_Get function.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
#define __LL_RTC_GET_WEEKDAY(__RTC_DATE__) (((__RTC_DATE__) >> RTC_OFFSET_WEEKDAY) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve Year in BCD format
  * @param  __RTC_DATE__ Value returned by @ref  LL_RTC_DATE_Get
  * @retval Year in in BCD format (0 to 99)
  */
#define __LL_RTC_GET_YEAR(__RTC_DATE__) ((__RTC_DATE__) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve Month in BCD format
  * @param  __RTC_DATE__ Value returned by @ref  LL_RTC_DATE_Get
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  */
#define __LL_RTC_GET_MONTH(__RTC_DATE__) (((__RTC_DATE__) >>RTC_OFFSET_MONTH) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve Day in BCD format
  * @param  __RTC_DATE__ Value returned by @ref  LL_RTC_DATE_Get
  * @retval Day in BCD format (0x01 . . . 0x31)
  */
#define __LL_RTC_GET_DAY(__RTC_DATE__) (((__RTC_DATE__) >>RTC_OFFSET_DAY) & 0x000000FFU)

/**
  * @}
  */

/** @defgroup RTC_LL_EM_Time Time helper Macros
  * @{
  */

/**
  * @brief  Helper macro to retrieve hour in BCD format
  * @param  __RTC_TIME__ RTC time returned by @ref LL_RTC_TIME_Get function
  * @retval Hours in BCD format (0x01. . .0x12 or between Min_Data=0x00 and Max_Data=0x23)
  */
#define __LL_RTC_GET_HOUR(__RTC_TIME__) (((__RTC_TIME__) >> RTC_OFFSET_HOUR) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve minute in BCD format
  * @param  __RTC_TIME__ RTC time returned by @ref LL_RTC_TIME_Get function
  * @retval Minutes in BCD format (0x00. . .0x59)
  */
#define __LL_RTC_GET_MINUTE(__RTC_TIME__) (((__RTC_TIME__) >> RTC_OFFSET_MINUTE) & 0x000000FFU)

/**
  * @brief  Helper macro to retrieve second in BCD format
  * @param  __RTC_TIME__ RTC time returned by @ref LL_RTC_TIME_Get function
  * @retval Seconds in  format (0x00. . .0x59)
  */
#define __LL_RTC_GET_SECOND(__RTC_TIME__) ((__RTC_TIME__) & 0x000000FFU)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RTC_LL_Exported_Functions RTC Exported Functions
  * @{
  */

/** @defgroup RTC_LL_Exported_Functions_Group1 Configuration
  * @{
  */
/**
  * @brief  Set RTC counter enable
  * @rmtoll RTC_CCR           rtc_en           LL_RTC_EnableCounter
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_EnableCounter(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CCR, RTC_CCR_EN);
}

/**
  * @brief  Set RTC counter disable
  * @rmtoll RTC_CCR           rtc_en           LL_RTC_DisableCounter
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_DisableCounter(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CCR, RTC_CCR_EN);
}

/**
  * @brief  Check if RTC counter is enable
  * @rmtoll RTC_CCR           rtc_en           LL_RTC_IsEnabledCounter
  * @param  RTCx RTC Instance
  * @retval Status 1 and 0.
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledCounter(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CCR, RTC_CCR_EN) ? 1U : 0U) ;
}

/**
  * @brief  Enable RTC wrap
  * @rmtoll RTC_CCR           rtc_wen           LL_RTC_EnableWrap
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_EnableWrap(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CCR, RTC_CCR_WEN);
}

/**
  * @brief  Disable RTC wrap
  * @rmtoll RTC_CCR           rtc_wen           LL_RTC_DisableWrap
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_DisableWrap(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CCR, RTC_CCR_WEN);
}

/**
  * @brief  Check if RTC is wrap
  * @rmtoll RTC_CCR           rtc_wen           LL_RTC_IsEnabledWrap
  * @param  RTCx RTC Instance
  * @retval Status 1 and 0.
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledWrap(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CCR, RTC_CCR_WEN) ? 1U : 0U) ;
}

/**
  * @brief  Enable RTC interrupt
  * @rmtoll RTC_CCR           rtc_ien           LL_RTC_EnableInterrupt
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_EnableInterrupt(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CCR, RTC_CCR_IEN);
}

/**
  * @brief  Disable RTC interrupt
  * @rmtoll RTC_CCR           rtc_ien           LL_RTC_DisableInterrupt
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_DisableInterrupt(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CCR, RTC_CCR_IEN);
}

/**
  * @brief  Check if RTC is interrupt
  * @rmtoll RTC_CCR           rtc_ien           LL_RTC_IsEnabledInterrupt
  * @param  RTCx RTC Instance
  * @retval Status 1 and 0.
  */
__STATIC_INLINE uint32_t LL_RTC_IsEnabledInterrupt(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CCR, RTC_CCR_IEN) ? 1U : 0U) ;
}

/**
  * @brief  Mask RTC interrupt
  * @rmtoll RTC_CCR           rtc_mask           LL_RTC_MaskInterrupt
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_MaskInterrupt(RTC_TypeDef *RTCx)
{
  SET_BIT(RTCx->CCR, RTC_CCR_MASK);
}

/**
  * @brief  Unmask RTC interrupt
  * @rmtoll RTC_CCR           rtc_mask           LL_RTC_UnmaskInterrupt
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_UnmaskInterrupt(RTC_TypeDef *RTCx)
{
  CLEAR_BIT(RTCx->CCR, RTC_CCR_MASK);
}

/**
  * @brief  Check if RTC is masked interrupt
  * @rmtoll RTC_CCR           rtc_mask           LL_RTC_IsMaskedInterrupt
  * @param  RTCx RTC Instance
  * @retval Status 1 and 0.
  */
__STATIC_INLINE uint32_t LL_RTC_IsMaskedInterrupt(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->CCR, RTC_CCR_MASK) ? 1U : 0U) ;
}

/**
  * @brief  Get RTC interrupt Status
  * @rmtoll RTC_STAT           rtc_stat           LL_RTC_GetInterruptStatus
  * @param  RTCx RTC Instance
  * @retval status (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_GetInterruptStatus(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->STAT, RTC_STAT_STAT));
}

/**
  * @brief  Get RTC flag
  * @rmtoll RTC_RAWSTAT           rtc_stat           LL_RTC_GetInterruptStatus
  * @param  RTCx RTC Instance
  * @retval status (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_GetFlag(RTC_TypeDef *RTCx)
{
  return (READ_BIT(RTCx->RSTAT, RTC_RSTAT_STAT));
}

/**
  * @brief  Clear RTC interrupt
  * @rmtoll RTC_EOI           rtc_eoi           LL_RTC_ClearInterrupt
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_ClearInterrupt(RTC_TypeDef *RTCx)
{
  READ_BIT(RTCx->EOI, RTC_EOI_EOI);
}

/**
  * @brief  Get RTC timestamp
  * @rmtoll RTC_CCVR           rtc_ccvr           LL_RTC_GetTimeStamp
  * @param  RTCx RTC Instance
  * @retval TimeStamp.
  */
__STATIC_INLINE uint32_t LL_RTC_GetTimeStamp(RTC_TypeDef *RTCx)
{
  return (READ_REG(RTCx->CCVR));
}

/**
  * @brief  Set RTC timestamp mask
  * @rmtoll RTC_CMR           rtc_cmr           LL_RTC_SetTimeStampMask
  * @param  RTCx RTC Instance
  * @param  TimeStamp time.
  */
__STATIC_INLINE void LL_RTC_SetTimeStampMask(RTC_TypeDef *RTCx, uint32_t TimeStamp)
{
  WRITE_REG(RTCx->CMR, TimeStamp);
}
/**
  * @brief  Get RTC timestamp mask
  * @rmtoll RTC_CMR           rtc_cmr           LL_RTC_GetTimeStampMask
  * @param  RTCx RTC Instance
  * @retval TimeStamp.
  */
__STATIC_INLINE uint32_t LL_RTC_GetTimeStampMask(RTC_TypeDef *RTCx)
{
  return (READ_REG(RTCx->CMR));
}

/**
  * @brief  Set RTC timestamp init
  * @rmtoll RTC_CLR           rtc_clr           LL_RTC_SetTimeStampInit
  * @param  RTCx RTC Instance
  * @param  TimeStamp time.
  */
__STATIC_INLINE void LL_RTC_SetTimeStampInit(RTC_TypeDef *RTCx, uint32_t TimeStamp)
{
  WRITE_REG(RTCx->CLR, TimeStamp);
}
/**
  * @brief  Get RTC timestamp init
  * @rmtoll RTC_CLR           rtc_clr           LL_RTC_GetTimeStampInit
  * @param  RTCx RTC Instance
  * @retval TimeStamp.
  */
__STATIC_INLINE uint32_t LL_RTC_GetTimeStampInit(RTC_TypeDef *RTCx)
{
  return (READ_REG(RTCx->CLR));
}

/**
  * @brief  Set Hours format (24 hour/day or AM/PM hour format)
  * @rmtoll RTC_CALENDAR          FMT           LL_RTC_SetHourFormat
  * @param  RTCx RTC Instance
  * @param  HourFormat This parameter can be one of the following values:
  *         @arg @ref LL_RTC_HOURFORMAT_24HOUR
  *         @arg @ref LL_RTC_HOURFORMAT_AMPM
  */
__STATIC_INLINE void LL_RTC_SetHourFormat(RTC_TypeDef *RTCx, uint32_t HourFormat)
{
  RTC_CALENDAR |= HourFormat;
}

/**
  * @brief  Get Hours format (24 hour/day or AM/PM hour format)
  * @rmtoll RTC_CALENDAR           FMT           LL_RTC_GetHourFormat
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_HOURFORMAT_24HOUR
  *         @arg @ref LL_RTC_HOURFORMAT_AMPM
  */
__STATIC_INLINE uint32_t LL_RTC_GetHourFormat(RTC_TypeDef *RTCx)
{
  return (RTC_CALENDAR & LL_RTC_HOURFORMAT_AMPM);
}

/**
  * @brief  Set daylight saving time (disable/enable)
  * @rmtoll RTC_CALENDAR          DST           LL_RTC_SetDaylightSaving
  * @param  RTCx RTC Instance
  * @param  Daylight This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TIME_DAYLIGHTSAVING_DISABLE
  *         @arg @ref LL_RTC_TIME_DAYLIGHTSAVING_ENABLE
  */
__STATIC_INLINE void LL_RTC_SetDayLightSaving(RTC_TypeDef *RTCx, uint32_t Daylight)
{
  RTC_CALENDAR |= (LL_RTC_TIME_DAYLIGHTSAVING_ENABLE & Daylight);
}

/**
  * @brief  Get daylight saving time (diable/enable)
  * @rmtoll RTC_CALENDAR           DST           LL_RTC_GetDaylightSaving
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_TIME_DAYLIGHTSAVING_DISABLE
  *         @arg @ref LL_RTC_TIME_DAYLIGHTSAVING_ENABLE
  */
__STATIC_INLINE uint32_t LL_RTC_GetDayLightSaving(RTC_TypeDef *RTCx)
{
  return (RTC_CALENDAR & LL_RTC_TIME_DAYLIGHTSAVING_ENABLE);
}

/**
  * @}
  */

/** @defgroup RTC_LL_Exported_Functions_Group2 Time
  * @{
  */

/**
  * @brief  Set time format (AM/24-hour or PM notation)
  * @rmtoll RTC_CALENDAR           PM            LL_RTC_TIME_SetFormat
  * @param  RTCx RTC Instance
  * @param  TimeFormat This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TIME_FORMAT_AM_OR_24
  *         @arg @ref LL_RTC_TIME_FORMAT_PM
  */
__STATIC_INLINE void LL_RTC_TIME_SetFormat(RTC_TypeDef *RTCx, uint32_t TimeFormat)
{
  LL_RTC_SetHourFormat(RTCx, TimeFormat);
}

/**
  * @brief  Get time format (AM or PM notation)
  * @rmtoll RTC_CALENDAR           PM            LL_RTC_TIME_GetFormat
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_TIME_FORMAT_AM_OR_24
  *         @arg @ref LL_RTC_TIME_FORMAT_PM
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetFormat(RTC_TypeDef *RTCx)
{
  return LL_RTC_GetHourFormat(RTCx);
}

/**
  * @brief  Set Hours
  * @rmtoll RTC_CCVR          rtc_ccvr           LL_RTC_TIME_SetHour\n
  * @rmtoll RTC_CLR           rtc_clr            LL_RTC_TIME_SetHour
  * @param  RTCx RTC Instance
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  */
__STATIC_INLINE void LL_RTC_TIME_SetHour(RTC_TypeDef *RTCx, uint32_t Hours)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
	uint32_t strtts = READ_REG(RTCx->CLR);
  struct tm *time = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

  time->tm_hour = (int)Hours;
  WRITE_REG(RTCx->CLR, (mktime(time)));
}

/**
  * @brief  Get Hours in BCD format
  * @rmtoll RTC_CCVR          rtc_ccvr           LL_RTC_TIME_GetHour\n
  * @rmtoll RTC_CLR           rtc_clr            LL_RTC_TIME_GetHour
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetHour(RTC_TypeDef *RTCx)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
  return (uint32_t)((localtime(&ts))->tm_hour);
}

/**
  * @brief  Set Minutes
  * @rmtoll RTC_CCVR          rtc_ccvr           LL_RTC_TIME_SetMinute\n
  *         RTC_CLR           rtc_clr            LL_RTC_TIME_SetMinute
  * @param  RTCx RTC Instance
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE void LL_RTC_TIME_SetMinute(RTC_TypeDef *RTCx, uint32_t Minutes)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
	uint32_t strtts = READ_REG(RTCx->CLR);
  struct tm *time = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

  time->tm_min = (int)Minutes;
  WRITE_REG(RTCx->CLR, mktime(time));
}

/**
  * @brief  Get Minutes
  * @rmtoll RTC_CCVR          rtc_ccvr           LL_RTC_TIME_GetMinute
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetMinute(RTC_TypeDef *RTCx)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
  return (uint32_t)((localtime(&ts))->tm_min);
}

/**
  * @brief  Set Seconds
  * @rmtoll RTC_CCVR          rtc_ccvr           LL_RTC_TIME_SetSecond\n
  *         RTC_CLR           rtc_clr            LL_RTC_TIME_SetSecond
  * @param  RTCx RTC Instance
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE void LL_RTC_TIME_SetSecond(RTC_TypeDef *RTCx, uint32_t Seconds)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
	uint32_t strtts = READ_REG(RTCx->CLR);
  struct tm *time = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

  time->tm_sec = (int)Seconds;
  WRITE_REG(RTCx->CLR, mktime(time));
}

/**
  * @brief  Get Seconds
  * @rmtoll RTC_CCVR         rtc_ccvr            LL_RTC_TIME_GetSecond\n
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_GetSecond(RTC_TypeDef *RTCx)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
  return (uint32_t)((localtime(&ts))->tm_sec);
}

/**
  * @brief  Set time (hour, minute and second)
  * @rmtoll RTC_CALENDAR       FMT                 LL_RTC_TIME_Config\n
  *         RTC_CCVR           rtc_ccvr            LL_RTC_TIME_Config\n
  *         RTC_CLR            rtc_clr             LL_RTC_TIME_Config
  * @param  RTCx RTC Instance
  * @param  Format12_24 This parameter can be one of the following values:
  *         @arg @ref LL_RTC_TIME_FORMAT_AM_OR_24
  *         @arg @ref LL_RTC_TIME_FORMAT_PM
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE void LL_RTC_TIME_Config(RTC_TypeDef *RTCx, uint32_t Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
{
  struct tm *temp;
  uint32_t ts = READ_REG(RTCx->CCVR);
	uint32_t strtts = READ_REG(RTCx->CLR);

  LL_RTC_SetHourFormat(RTCx, Format12_24);

  temp = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

  if(Format12_24 == LL_RTC_TIME_FORMAT_PM)
  {  
    temp->tm_hour = (int)Hours + 12;
  }
  else
  {
    temp->tm_hour = (int)Hours;
  }  

  temp->tm_min = (int)Minutes;

  temp->tm_sec = (int)Seconds;
  
  WRITE_REG(RTCx->CLR, mktime(temp));
}

/**
  * @brief  Get time (hour, minute and second)
  * @rmtoll RTC_CCVR           rtc_ccvr            LL_RTC_TIME_Get
  * @param  RTCx RTC Instance
  * @retval Combination of hours, minutes and seconds (Format: 0x00HHMMSS).
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_Get(RTC_TypeDef *RTCx)
{
    struct tm * temp = 0;
    uint32_t res = 0;
    uint32_t ts = READ_REG(RTCx->CCVR);

    temp = localtime(&ts);
    res = (((uint32_t)(temp->tm_hour) << RTC_OFFSET_HOUR) | ((uint32_t)(temp->tm_min) << RTC_OFFSET_MINUTE) | ((uint32_t)(temp->tm_sec)));

    return res; 
}

/**
  * @brief  Memorize whether the daylight saving time change has been performed
  * @rmtoll RTC_CCVR           rtc_ccvr            LL_RTC_TIME_EnableDayLight\n
  * @rmtoll RTC_CLR            rtc_clr             LL_RTC_TIME_EnableDayLight\n
  * @rmtoll RTC_CALENDER       DST                 LL_RTC_TIME_EnableDayLight
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_TIME_EnableDayLight(RTC_TypeDef *RTCx)
{
  //SET_BIT(RTCx->CR, RTC_CR_BKP);
    struct tm * temp = 0;
    uint32_t ts = READ_REG(RTCx->CCVR);
	  uint32_t strtts = READ_REG(RTCx->CLR);

    LL_RTC_SetDayLightSaving(RTCx, LL_RTC_TIME_DAYLIGHTSAVING_ENABLE);

    temp = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

    temp->tm_isdst = 1;

    WRITE_REG(RTCx->CLR, mktime(temp));
}

/**
  * @brief  Disable memorization whether the daylight saving time change has been performed.
  * @rmtoll RTC_CCVR           rtc_ccvr            LL_RTC_TIME_DisableDayLight\n
  * @rmtoll RTC_CLR            rtc_clr             LL_RTC_TIME_DisableDayLight\n
  * @rmtoll RTC_CALENDER       DST                 LL_RTC_TIME_DisableDayLight
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_TIME_DisableDayLight(RTC_TypeDef *RTCx)
{
//  CLEAR_BIT(RTCx->CR, RTC_CR_BKP);
    struct tm * temp = 0;
    uint32_t ts = READ_REG(RTCx->CCVR);
  	uint32_t strtts = READ_REG(RTCx->CLR);

    LL_RTC_SetDayLightSaving(RTCx, LL_RTC_TIME_DAYLIGHTSAVING_DISABLE);

    temp = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

    temp->tm_isdst = 0;

    WRITE_REG(RTCx->CLR, mktime(temp));
}

/**
  * @brief  Check if RTC Day Light Saving stored operation has been enabled or not
  * @rmtoll RTC_CR           BKP           LL_RTC_TIME_IsDayLightStoreEnabled
  * @param  RTCx RTC Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_RTC_TIME_IsDayLightStoreEnabled(RTC_TypeDef *RTCx)
{
//  return ((READ_BIT(RTCx->CR, RTC_CR_BKP) == (RTC_CR_BKP)) ? 1UL : 0UL);
    struct tm * temp = 0;
    uint32_t ts = READ_REG(RTCx->CCVR);

    temp = localtime(&ts);

    return (uint32_t)(temp->tm_isdst);
}

/**
  * @}
  */

/** @defgroup RTC_LL_Exported_Functions_Group3 Date
  * @{
  */

/**
  * @brief  Set Year in BCD format
  * @rmtoll RTC_CCVR          rtc_ccvr            LL_RTC_DATE_SetYear\n
  *         RTC_CLR           rtc_clr             LL_RTC_DATE_SetYear
  * @param  RTCx RTC Instance
  * @param  Year Value between Min_Data=0 and Max_Data=0x
  */
__STATIC_INLINE void LL_RTC_DATE_SetYear(RTC_TypeDef *RTCx, uint32_t Year)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
	uint32_t strtts = READ_REG(RTCx->CLR);
  struct tm *time = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

  time->tm_year = (int)Year;
  WRITE_REG(RTCx->CLR, mktime(time));
}

/**
  * @brief  Get Year
  * @rmtoll RTC_CCVR           rtc_ccvr            LL_RTC_DATE_GetYear
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x99
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_GetYear(RTC_TypeDef *RTCx)
{
//  return ((READ_BIT(RTCx->DR, (RTC_DR_YT | RTC_DR_YU))) >> RTC_DR_YU_Pos);
  uint32_t ts = READ_REG(RTCx->CCVR);
  struct tm *time = localtime(&ts);

  return (uint32_t)(time->tm_year);
}

/**
  * @brief  Set Week day
  * @rmtoll RTC_CCVR           rtc_ccvr           LL_RTC_DATE_SetWeekDay\n
  *         RTC_CLR            rtc_clr            LL_RTC_DATE_SetWeekDay
  * @param  RTCx RTC Instance
  * @param  WeekDay This parameter can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
__STATIC_INLINE void LL_RTC_DATE_SetWeekDay(RTC_TypeDef *RTCx, uint32_t WeekDay)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
	uint32_t strtts = READ_REG(RTCx->CLR);
  struct tm *time = (ts>strtts) ? localtime(&ts) : localtime(&strtts);
  
	time->tm_wday = (int)WeekDay;

  WRITE_REG(RTCx->CLR, mktime(time));
}

/**
  * @brief  Get Week day
  * @rmtoll RTC_CCVR           rtc_ccvr           LL_RTC_DATE_GetWeekDay
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_GetWeekDay(RTC_TypeDef *RTCx)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
  struct tm * temp = 0;

  temp = localtime(&ts);
  return (uint32_t)(temp->tm_wday);
}

/**
  * @brief  Set Month
  * @rmtoll RTC_CCVR           rtc_ccvr            LL_RTC_DATE_SetMonth\n
  *         RTC_CLR            rtc_clr             LL_RTC_DATE_SetMonth
  * @param  RTCx RTC Instance
  * @param  Month This parameter can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  */
__STATIC_INLINE void LL_RTC_DATE_SetMonth(RTC_TypeDef *RTCx, uint32_t Month)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
  uint32_t strtts = READ_REG(RTCx->CLR);
  struct tm *time = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

  time->tm_mon = (int)Month;

  WRITE_REG(RTCx->CLR, mktime(time));
}

/**
  * @brief  Get Month
  * @rmtoll RTC_CCVR         rtc_ccvr            LL_RTC_DATE_GetMonth\n
  *         RTC_CLR          rtc_clr             LL_RTC_DATE_GetMonth
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_GetMonth(RTC_TypeDef *RTCx)
{
  struct tm * temp = 0;
  uint32_t ts = READ_REG(RTCx->CCVR);

  temp = localtime(&ts);
  return (uint32_t)(temp->tm_mon);
}

/**
  * @brief  Set Day
  * @rmtoll RTC_CCVR          rtc_ccvr            LL_RTC_DATE_SetDay\n
  *         RTC_CLR           rtc_clr             LL_RTC_DATE_SetDay
  * @param  RTCx RTC Instance
  * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
  */
__STATIC_INLINE void LL_RTC_DATE_SetDay(RTC_TypeDef *RTCx, uint32_t Day)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
	uint32_t strtts = READ_REG(RTCx->CLR);
  struct tm *time = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

  time->tm_mday = (int)Day;

  WRITE_REG(RTCx->CLR, mktime(time));
}

/**
  * @brief  Get Day
  * @rmtoll RTC_CCVR           rtc_ccvr            LL_RTC_DATE_GetDay
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x31
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_GetDay(RTC_TypeDef *RTCx)
{
  struct tm * temp = 0;
  uint32_t ts = READ_REG(RTCx->CCVR);

  temp = localtime(&ts);

  return (uint32_t)(temp->tm_mday);
}

/**
  * @brief  Set date (WeekDay, Day, Month and Year) 
  * @rmtoll RTC_CCVR         rtc_ccvr           LL_RTC_DATE_Config\n
  *         RTC_CLR          rtc_clr            LL_RTC_DATE_Config
  * @param  RTCx RTC Instance
  * @param  WeekDay This parameter can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
  * @param  Month This parameter can be one of the following values:
  *         @arg @ref LL_RTC_MONTH_JANUARY
  *         @arg @ref LL_RTC_MONTH_FEBRUARY
  *         @arg @ref LL_RTC_MONTH_MARCH
  *         @arg @ref LL_RTC_MONTH_APRIL
  *         @arg @ref LL_RTC_MONTH_MAY
  *         @arg @ref LL_RTC_MONTH_JUNE
  *         @arg @ref LL_RTC_MONTH_JULY
  *         @arg @ref LL_RTC_MONTH_AUGUST
  *         @arg @ref LL_RTC_MONTH_SEPTEMBER
  *         @arg @ref LL_RTC_MONTH_OCTOBER
  *         @arg @ref LL_RTC_MONTH_NOVEMBER
  *         @arg @ref LL_RTC_MONTH_DECEMBER
  * @param  Year Value format is YYYY
  */
__STATIC_INLINE void LL_RTC_DATE_Config(RTC_TypeDef *RTCx, uint32_t WeekDay, uint32_t Day, uint32_t Month, uint32_t Year)
{
  uint32_t ts = READ_REG(RTCx->CCVR);
	uint32_t strtts = READ_REG(RTCx->CLR);
  struct tm *temp = (ts>strtts) ? localtime(&ts) : localtime(&strtts);

  temp->tm_wday = (int)WeekDay;
  temp->tm_mday = (int)Day;
  temp->tm_mon = (int)Month;
  temp->tm_year = (int)Year;

  WRITE_REG(RTCx->CLR, mktime(temp));
}

/**
  * @brief  Get date (WeekDay, Day, Month and Year)
  * @rmtoll RTC_CCVR         rtc_ccvr           LL_RTC_DATE_Get
  * @param  RTCx RTC Instance
  * @retval Combination of WeekDay, Day, Month and Year (Format: 0xWWDDMMYY).
  */
__STATIC_INLINE uint32_t LL_RTC_DATE_Get(RTC_TypeDef *RTCx)
{
  struct tm * temp = 0;
  uint32_t res = 0;
  uint32_t ts = READ_REG(RTCx->CCVR);

  temp = localtime(&ts);
  res = ((uint32_t)(temp->tm_wday) << RTC_OFFSET_WEEKDAY) | ((uint32_t)(temp->tm_mday) << RTC_OFFSET_MONTH ) | ((uint32_t)(temp->tm_mon) << RTC_OFFSET_DAY) | ((uint32_t)(temp->tm_year)-100);

  return res;
}

/**
  * @}
  */

/** @defgroup RTC_LL_Exported_Functions_Group4 ALARM
  * @{
  */
/**
  * @brief  Calculate Alarm next timestamp
  * @rmtoll RTC_CCVR          rtc_ccvr   LL_RTC_ALM_CalTimeStamp\n
  *         RTC_ALARM                    LL_RTC_ALM_CalTimeStamp
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_CalTimeStamp(RTC_TypeDef *RTCx)
{
  struct tm * temp = 0;
  uint32_t ts = READ_REG(RTCx->CCVR);
  uint32_t new_ts = ts;
	struct tm * new_temp = 0;

  uint32_t res = 0;

  temp = localtime(&ts);
	new_temp = localtime(&new_ts);

  //calculate Next timestamp mask
  switch (RTC_ALARM.AlarmDateWeekDaySel)
  {
    case LL_RTC_ALM_DATEWEEKDAYSEL_DATE:                 /*!< Alarm A Date is selected */
      new_temp->tm_mday = (int)RTC_ALARM.AlarmDateWeekDay;
      new_temp->tm_hour = (int)RTC_ALARM.AlarmTime.Hours;
      new_temp->tm_min  = (int)RTC_ALARM.AlarmTime.Minutes;
      new_temp->tm_sec  = (int)RTC_ALARM.AlarmTime.Seconds;
		
		  new_ts = mktime(new_temp);
      
      if(ts < new_ts)
      {
        res = mktime(new_temp);
        //return res;
      }
      else
      {
        if(new_temp->tm_mon == 11)
        {
          new_temp->tm_mon = 0;
          new_temp->tm_year += 1;
        }
        else
        {
          new_temp->tm_mon += 1;
        }
        res = mktime(new_temp);
        //return res;
      }

      break;
    case LL_RTC_ALM_DATEWEEKDAYSEL_WEEKDAY:              /*!< Alarm A WeekDay is selected */
      new_temp->tm_wday = (int)RTC_ALARM.AlarmDateWeekDay;
      new_temp->tm_hour = (int)RTC_ALARM.AlarmTime.Hours;
      new_temp->tm_min  = (int)RTC_ALARM.AlarmTime.Minutes;
      new_temp->tm_sec  = (int)RTC_ALARM.AlarmTime.Seconds;
      new_ts = mktime(new_temp);
      if(ts < new_ts)
      {
        res = mktime(new_temp);
        //return res;
      }
      else
      {
        res = mktime(new_temp + 7*24*3600);
        //return res;
      }
      break;
    case LL_RTC_ALM_DATEWEEKDAYSEL_WORKDAY:              /*!< Alarm WorkDay is selected */
      new_temp->tm_hour = (int)RTC_ALARM.AlarmTime.Hours;
      new_temp->tm_min  = (int)RTC_ALARM.AlarmTime.Minutes;
      new_temp->tm_sec  = (int)RTC_ALARM.AlarmTime.Seconds;
			new_ts = mktime(new_temp);
      if(ts < new_ts)
      {
        res = mktime(new_temp);
        //return res;
      }
      else
      {
        if(temp->tm_wday < 4)
        {
          res = (new_ts + 24*3600);
        }
        else 
        {
          res = new_ts + ((7-(uint32_t)(temp->tm_wday))*24*3600);
        }
        //return res;
      }
      break;
    case LL_RTC_ALM_DATEWEEKDAYSEL_EVERYDAY:             /*!< Alarm EveryDay is selected */
      new_temp->tm_hour = (int)RTC_ALARM.AlarmTime.Hours;
      new_temp->tm_min  = (int)RTC_ALARM.AlarmTime.Minutes;
      new_temp->tm_sec  = (int)RTC_ALARM.AlarmTime.Seconds;
		  new_ts = mktime(new_temp);
      if(ts < new_ts)
      {
        res = mktime(new_temp);
        //return res;
      }
      else
      {
        res = (new_ts + 24*3600);
        //return res;
      }
      break;
		case LL_RTC_ALM_DATEWEEKDAYSEL_ONCE:	
    default:
		  res = 0;
      break;
  }
	return res;
}
/**
  * @brief  Enable Alarm
  * @rmtoll RTC_CMR           rtc_cmr         LL_RTC_ALMA_Enable\n
  *         RTC_EOI           rtc_eoi         LL_RTC_ALMA_Enable\n
  *         RTC_CCR           ien             LL_RTC_ALMA_Enable\n
  *         RTC_CCR           mask            LL_RTC_ALMA_Enable
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_ALM_Enable(RTC_TypeDef *RTCx)
{
  uint32_t mts = LL_RTC_ALM_CalTimeStamp(RTCx);
	
	if(mts == 0)
	{
    RTC_ALARM.IsEnable = 0;

    /* mask interrupt */
    SET_BIT(RTCx->CCR, RTC_CCR_MASK);
    /* disable interrupt */
    CLEAR_BIT(RTCx->CCR, RTC_CCR_IEN);  

    /* clear interrupt */
    READ_BIT(RTCx->EOI, RTC_EOI_EOI);   //clear flag
  }
	else
	{
		RTC_ALARM.IsEnable = 1;
		
		/* write counter mask */
		WRITE_REG(RTCx->CMR, mts);

		/* clear interrupt */
		READ_BIT(RTCx->EOI, RTC_EOI_EOI);
		/* unmask interrupt */
		CLEAR_BIT(RTCx->CCR, RTC_CCR_MASK);
		/* enable interrupt */  
		SET_BIT(RTCx->CCR, RTC_CCR_IEN);
  }
}

/**
  * @brief  Disable Alarm 
  * @rmtoll RTC_CMR           rtc_cmr         LL_RTC_ALMA_Disable\n
  *         RTC_EOI           rtc_eoi         LL_RTC_ALMA_Disable\n
  *         RTC_CCR           ien             LL_RTC_ALMA_Disable\n
  *         RTC_CCR           mask            LL_RTC_ALMA_Disable
  * @param  RTCx RTC Instance
  */
__STATIC_INLINE void LL_RTC_ALM_Disable(RTC_TypeDef *RTCx)
{
  RTC_ALARM.IsEnable = 0;

  /* mask interrupt */
  SET_BIT(RTCx->CCR, RTC_CCR_MASK);
  /* disable interrupt */
  CLEAR_BIT(RTCx->CCR, RTC_CCR_IEN);  //disable

  /* clear interrupt */
  READ_BIT(RTCx->EOI, RTC_EOI_EOI);   //clear flag
}

/**
  * @brief  Enable AlarmA Week day selection (DU[3:0] represents the week day. DT[1:0] is do not care)
  * @rmtoll RTC_ALARM       AlarmDateWeekDaySel         LL_RTC_ALM_SetWeekdaySel
  * @param  RTCx RTC Instance
  * @param  WeekdaySel This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALM_DATEWEEKDAYSEL_DATE     
  *         @arg @ref LL_RTC_ALM_DATEWEEKDAYSEL_WEEKDAY  
  *         @arg @ref LL_RTC_ALM_DATEWEEKDAYSEL_WORKDAY  
  *         @arg @ref LL_RTC_ALM_DATEWEEKDAYSEL_EVERYDAY 
  */
__STATIC_INLINE void LL_RTC_ALM_SetWeekdaySel(RTC_TypeDef *RTCx, uint32_t WeekdaySel)
{
  RTC_ALARM.AlarmDateWeekDaySel = WeekdaySel;
}

/**
  * @brief  Disable AlarmA Week day selection (DU[3:0] represents the date )
  * @rmtoll RTC_ALARM       AlarmDateWeekDaySel         LL_RTC_ALM_GetWeekdaySel
  * @param  RTCx RTC Instance
  * @retval value can be one of the following values:
  *         @arg @ref LL_RTC_ALM_DATEWEEKDAYSEL_DATE     
  *         @arg @ref LL_RTC_ALM_DATEWEEKDAYSEL_WEEKDAY  
  *         @arg @ref LL_RTC_ALM_DATEWEEKDAYSEL_WORKDAY  
  *         @arg @ref LL_RTC_ALM_DATEWEEKDAYSEL_EVERYDAY 
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_GetWeekdaySel(RTC_TypeDef *RTCx)
{
  return RTC_ALARM.AlarmDateWeekDaySel;
}

/**
  * @brief  Set ALARM Day
  * @rmtoll RTC_ALARM       AlarmDateWeekDay            LL_RTC_ALMA_SetDay
  * @param  RTCx RTC Instance
  * @param  Day Value between Min_Data=0x01 and Max_Data=0x31
  */
__STATIC_INLINE void LL_RTC_ALM_SetDay(RTC_TypeDef *RTCx, uint32_t Day)
{
  RTC_ALARM.AlarmDateWeekDay = Day;
}

/**
  * @brief  Get ALARM Day
  * @rmtoll RTC_ALARM       AlarmDateWeekDay            LL_RTC_ALMA_GetDay
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x31
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_GetDay(RTC_TypeDef *RTCx)
{
  return RTC_ALARM.AlarmDateWeekDay;
}

/**
  * @brief  Set ALARM Weekday
  * @rmtoll RTC_ALARM       AlarmDateWeekDay            LL_RTC_ALMA_SetWeekDay
  * @param  RTCx RTC Instance
  * @param  WeekDay This parameter can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
__STATIC_INLINE void LL_RTC_ALM_SetWeekDay(RTC_TypeDef *RTCx, uint32_t WeekDay)
{
  RTC_ALARM.AlarmDateWeekDay = WeekDay;
}

/**
  * @brief  Get ALARM Weekday
  * @rmtoll RTC_ALARM       AlarmDateWeekDay            LL_RTC_ALMA_GetWeekDay
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_WEEKDAY_MONDAY
  *         @arg @ref LL_RTC_WEEKDAY_TUESDAY
  *         @arg @ref LL_RTC_WEEKDAY_WEDNESDAY
  *         @arg @ref LL_RTC_WEEKDAY_THURSDAY
  *         @arg @ref LL_RTC_WEEKDAY_FRIDAY
  *         @arg @ref LL_RTC_WEEKDAY_SATURDAY
  *         @arg @ref LL_RTC_WEEKDAY_SUNDAY
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_GetWeekDay(RTC_TypeDef *RTCx)
{
  return RTC_ALARM.AlarmDateWeekDay;
}

/**
  * @brief  Set Alarm time format (AM/24-hour or PM notation)
  * @rmtoll RTC_ALARM       PM            LL_RTC_ALMA_SetTimeFormat
  * @param  RTCx RTC Instance
  * @param  TimeFormat This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALM_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALM_TIME_FORMAT_PM
  */
__STATIC_INLINE void LL_RTC_ALM_SetTimeFormat(RTC_TypeDef *RTCx, uint32_t TimeFormat)
{
  RTC_ALARM.AlarmTime.TimeFormat = TimeFormat;
}

/**
  * @brief  Get Alarm time format (AM or PM notation)
  * @rmtoll RTC_ALARM       PM            LL_RTC_ALMA_GetTimeFormat
  * @param  RTCx RTC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_RTC_ALM_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALM_TIME_FORMAT_PM
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_GetTimeFormat(RTC_TypeDef *RTCx)
{
  return RTC_ALARM.AlarmTime.TimeFormat;
}

/**
  * @brief  Set ALARM Hours 
  * @rmtoll RTC_ALARM       Hours            LL_RTC_ALMA_SetHour
  * @param  RTCx RTC Instance
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  */
__STATIC_INLINE void LL_RTC_ALM_SetHour(RTC_TypeDef *RTCx, uint32_t Hours)
{
  RTC_ALARM.AlarmTime.Hours = (uint8_t)Hours;
}

/**
  * @brief  Get ALARM Hours
  * @rmtoll RTC_ALARM       Hours            LL_RTC_ALMA_GetHour
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_GetHour(RTC_TypeDef *RTCx)
{
  return RTC_ALARM.AlarmTime.Hours;
}

/**
  * @brief  Set ALARM Minutes
  * @rmtoll RTC_ALARM        Minutes           LL_RTC_ALMA_SetMinute
  * @param  RTCx RTC Instance
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE void LL_RTC_ALM_SetMinute(RTC_TypeDef *RTCx, uint32_t Minutes)
{
  RTC_ALARM.AlarmTime.Minutes = (uint8_t)Minutes;
}

/**
  * @brief  Get ALARM Minutes
  * @rmtoll RTC_ALARM       Minutes           LL_RTC_ALMA_GetMinute
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_GetMinute(RTC_TypeDef *RTCx)
{
  return RTC_ALARM.AlarmTime.Minutes;
}

/**
  * @brief  Set ALARM Seconds
  * @rmtoll RTC_ALARM       Seconds            LL_RTC_ALMA_SetSecond
  * @param  RTCx RTC Instance
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE void LL_RTC_ALM_SetSecond(RTC_TypeDef *RTCx, uint32_t Seconds)
{
  RTC_ALARM.AlarmTime.Seconds = (uint8_t)Seconds;
}

/**
  * @brief  Get ALARM Seconds 
  * @rmtoll RTC_ALARM       Seconds            LL_RTC_ALMA_GetSecond
  * @param  RTCx RTC Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_GetSecond(RTC_TypeDef *RTCx)
{
  return RTC_ALARM.AlarmTime.Seconds;
}

/**
  * @brief  Set Alarm Time (hour, minute and second) 
  * @rmtoll RTC_ALARM       AlarmTime            LL_RTC_ALMA_ConfigTime
  * @param  RTCx RTC Instance
  * @param  Format12_24 This parameter can be one of the following values:
  *         @arg @ref LL_RTC_ALM_TIME_FORMAT_AM
  *         @arg @ref LL_RTC_ALM_TIME_FORMAT_PM
  * @param  Hours Value between Min_Data=0x01 and Max_Data=0x12 or between Min_Data=0x00 and Max_Data=0x23
  * @param  Minutes Value between Min_Data=0x00 and Max_Data=0x59
  * @param  Seconds Value between Min_Data=0x00 and Max_Data=0x59
  */
__STATIC_INLINE void LL_RTC_ALM_ConfigTime(RTC_TypeDef *RTCx, uint32_t Format12_24, uint32_t Hours, uint32_t Minutes, uint32_t Seconds)
{
  RTC_ALARM.AlarmTime.TimeFormat = (uint8_t)Format12_24;
  RTC_ALARM.AlarmTime.Hours      = (uint8_t)Hours;
  RTC_ALARM.AlarmTime.Minutes    = (uint8_t)Minutes;
  RTC_ALARM.AlarmTime.Seconds    = (uint8_t)Seconds;
}

/**
  * @brief  Get Alarm Time (hour, minute and second) 
  * @rmtoll RTC_ALARM       AlarmTime            LL_RTC_ALMA_GetTime
  * @param  RTCx RTC Instance
  * @retval Combination of hours, minutes and seconds 0xXXHHMMSS.
  */
__STATIC_INLINE uint32_t LL_RTC_ALM_GetTime(RTC_TypeDef *RTCx)
{
  return (((uint32_t)(RTC_ALARM.AlarmTime.Hours) << RTC_OFFSET_HOUR) | ( (uint32_t)(RTC_ALARM.AlarmTime.Minutes) << RTC_OFFSET_MINUTE) | ( (uint32_t)(RTC_ALARM.AlarmTime.Seconds)));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RTC_LL_Exported_Functions_Group5 Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_RTC_DeInit(RTC_TypeDef *RTCx);
ErrorStatus LL_RTC_Init(RTC_TypeDef *RTCx, LL_RTC_InitTypeDef *RTC_InitStruct);
void        LL_RTC_StructInit(LL_RTC_InitTypeDef *RTC_InitStruct);

ErrorStatus LL_RTC_TIME_Init(RTC_TypeDef *RTCx, LL_RTC_TimeTypeDef *RTC_TimeStruct);
void        LL_RTC_TIME_StructInit(LL_RTC_TimeTypeDef *RTC_TimeStruct);
ErrorStatus LL_RTC_DATE_Init(RTC_TypeDef *RTCx, LL_RTC_DateTypeDef *RTC_DateStruct);
void        LL_RTC_DATE_StructInit(LL_RTC_DateTypeDef *RTC_DateStruct);
ErrorStatus LL_RTC_ALM_Init(RTC_TypeDef *RTCx, LL_RTC_AlarmTypeDef *RTC_AlarmStruct);
void        LL_RTC_ALM_StructInit(LL_RTC_AlarmTypeDef *RTC_AlarmStruct);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(RTC) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_RTC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
