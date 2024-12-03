/**
  ******************************************************************************
  * @file    xt32h0xx_hal_rtc.h
  * @author  Software Team
  * @brief   Header file of RTC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_RTC_H
#define XT32H0xx_HAL_RTC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"
#include "xt32h0xx_ll_rtc.h"
/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup RTC RTC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup RTC_Exported_Types RTC Exported Types
  * @{
  */

/**
  * @brief  HAL State structures definition
  */
typedef enum
{
  HAL_RTC_STATE_RESET             = 0x00U,  /*!< RTC not yet initialized or disabled */
  HAL_RTC_STATE_READY             = 0x01U,  /*!< RTC initialized and ready for use   */
  HAL_RTC_STATE_BUSY              = 0x02U,  /*!< RTC process is ongoing              */
  HAL_RTC_STATE_TIMEOUT           = 0x03U,  /*!< RTC timeout state                   */
  HAL_RTC_STATE_ERROR             = 0x04U   /*!< RTC error state                     */

}HAL_RTCStateTypeDef;

/**
  * @brief  RTC Configuration Structure definition
  */
typedef struct
{
  uint32_t HourFormat;        /*!< Specifies the RTC Hour Format.
                                 This parameter can be a value of @ref RTC_Hour_Formats */

}RTC_InitTypeDef;

/**
  * @brief  RTC Time structure definition
  */
typedef struct
{
  uint8_t Hours;            /*!< Specifies the RTC Time Hour.
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 12 if the RTC_HourFormat_12 is selected.
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 23 if the RTC_HourFormat_24 is selected */

  uint8_t Minutes;          /*!< Specifies the RTC Time Minutes.
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 59 */

  uint8_t Seconds;          /*!< Specifies the RTC Time Seconds.
                                 This parameter must be a number between Min_Data = 0 and Max_Data = 59 */

  uint8_t TimeFormat;       /*!< Specifies the RTC AM/PM Time.
                                 This parameter can be a value of @ref RTC_AM_PM_Definitions */

  uint32_t DayLightSaving;  /*!< This interface is deprecated. To manage Daylight Saving Time,
                                 please use HAL_RTC_DST_xxx functions */

}RTC_TimeTypeDef;

/**
  * @brief  RTC Date structure definition
  */
typedef struct
{
  uint8_t WeekDay;  /*!< Specifies the RTC Date WeekDay.
                         This parameter can be a value of @ref RTC_WeekDay_Definitions */

  uint8_t Month;    /*!< Specifies the RTC Date Month (in BCD format).
                         This parameter can be a value of @ref RTC_Month_Date_Definitions */

  uint8_t Date;     /*!< Specifies the RTC Date.
                         This parameter must be a number between Min_Data = 1 and Max_Data = 31 */

  uint16_t Year;    /*!< Specifies the RTC Date Year.
                         This parameter must be a number between Min_Data = 1900 and Max_Data =  */

}RTC_DateTypeDef;

/**
  * @brief  RTC Alarm structure definition
  */
typedef struct
{
  RTC_TimeTypeDef AlarmTime;     /*!< Specifies the RTC Alarm Time members */


  uint32_t AlarmDateWeekDaySel;  /*!< Specifies the RTC Alarm is on Date or WeekDay.
                                      This parameter can be a value of @ref RTC_AlarmDateWeekDay_Definitions */

  uint8_t AlarmDateWeekDay;      /*!< Specifies the RTC Alarm Date/WeekDay.
                                      If the Alarm Date is selected, this parameter must be set to a value in the 1-31 range.
                                      If the Alarm WeekDay is selected, this parameter can be a value of @ref RTC_WeekDay_Definitions */

}RTC_AlarmTypeDef;

/**
  * @brief  RTC Handle Structure definition
  */
#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
typedef struct __RTC_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_RTC_REGISTER_CALLBACKS */
{
  RTC_TypeDef               *Instance;  /*!< Register base address    */

  RTC_InitTypeDef           Init;       /*!< RTC required parameters  */
	
  HAL_LockTypeDef           Lock;       /*!< RTC locking object       */

  __IO HAL_RTCStateTypeDef  State;      /*!< Time communication state */

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
  void  (* AlarmEventCallback)      ( struct __RTC_HandleTypeDef * hrtc);   /*!< RTC Alarm A Event callback         */

  void  (* IRQCallback)             ( struct __RTC_HandleTypeDef * hrtc);   /*!< RTC IRQ callback                   */

  void  (* MspInitCallback)         ( struct __RTC_HandleTypeDef * hrtc);   /*!< RTC Msp Init callback              */

  void  (* MspDeInitCallback)       ( struct __RTC_HandleTypeDef * hrtc);   /*!< RTC Msp DeInit callback            */

#endif /* (USE_HAL_RTC_REGISTER_CALLBACKS) */

}RTC_HandleTypeDef;

#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL RTC Callback ID enumeration definition
  */
typedef enum
{
  HAL_RTC_ALARM_EVENT_CB_ID           = 0x00U,    /*!< RTC Alarm A Event Callback ID      */
  HAL_RTC_IRQ_CB_ID                   = 0x08U,    /*!< RTC IRQ callback ID                */
  HAL_RTC_MSPINIT_CB_ID               = 0x0EU,    /*!< RTC Msp Init callback ID           */
  HAL_RTC_MSPDEINIT_CB_ID             = 0x0FU     /*!< RTC Msp DeInit callback ID         */
}HAL_RTC_CallbackIDTypeDef;

/**
  * @brief  HAL RTC Callback pointer definition
  */
typedef  void (*pRTC_CallbackTypeDef)(RTC_HandleTypeDef * hrtc); /*!< pointer to an RTC callback function */
#endif /* USE_HAL_RTC_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RTC_Exported_Constants RTC Exported Constants
  * @{
  */

/** @defgroup RTC_Hour_Formats RTC Hour Formats
  * @{
  */
#define RTC_HOURFORMAT_24                   (0x00000000u)
#define RTC_HOURFORMAT_12                   (0x00000001u)
/**
  * @}
  */

/** @defgroup RTC_AM_PM_Definitions RTC AM PM Definitions
  * @{
  */
#define RTC_HOURFORMAT12_AM                 (0x0u)
#define RTC_HOURFORMAT12_PM                 (0x1u)
/**
  * @}
  */

/** @defgroup RTC_AM_PM_Definitions RTC AM PM Definitions
  * @{
  */
#define RTC_DAYLIGHTSAVING_NONE             (LL_RTC_TIME_DAYLIGHTSAVING_DISABLE)       /*!< daylight saving time disable*/
#define RTC_DAYLIGHTSAVING_ENABLE           (LL_RTC_TIME_DAYLIGHTSAVING_ENABLE)        /*!< daylight saving time enable */
/**
  * @}
  */

/** @defgroup RTC_Month_Date_Definitions RTC Month Date Definitions
  * @{
  */

/* Coded in BCD format */
#define RTC_MONTH_JANUARY                   ((uint8_t)0x00U)
#define RTC_MONTH_FEBRUARY                  ((uint8_t)0x01U)
#define RTC_MONTH_MARCH                     ((uint8_t)0x02U)
#define RTC_MONTH_APRIL                     ((uint8_t)0x03U)
#define RTC_MONTH_MAY                       ((uint8_t)0x04U)
#define RTC_MONTH_JUNE                      ((uint8_t)0x05U)
#define RTC_MONTH_JULY                      ((uint8_t)0x06U)
#define RTC_MONTH_AUGUST                    ((uint8_t)0x07U)
#define RTC_MONTH_SEPTEMBER                 ((uint8_t)0x08U)
#define RTC_MONTH_OCTOBER                   ((uint8_t)0x09U)
#define RTC_MONTH_NOVEMBER                  ((uint8_t)0x10U)
#define RTC_MONTH_DECEMBER                  ((uint8_t)0x11U)

/**
  * @}
  */

/** @defgroup RTC_WeekDay_Definitions RTC WeekDay Definitions
  * @{
  */
#define RTC_WEEKDAY_MONDAY                  ((uint8_t)0x00U)
#define RTC_WEEKDAY_TUESDAY                 ((uint8_t)0x01U)
#define RTC_WEEKDAY_WEDNESDAY               ((uint8_t)0x02U)
#define RTC_WEEKDAY_THURSDAY                ((uint8_t)0x03U)
#define RTC_WEEKDAY_FRIDAY                  ((uint8_t)0x04U)
#define RTC_WEEKDAY_SATURDAY                ((uint8_t)0x05U)
#define RTC_WEEKDAY_SUNDAY                  ((uint8_t)0x06U)

/**
  * @}
  */

/** @defgroup RTC_AlarmDateWeekDay_Definitions RTC AlarmDateWeekDay Definitions
  * @{
  */
#define RTC_ALARMDATEWEEKDAYSEL_DATE        (0x00000000u)
#define RTC_ALARMDATEWEEKDAYSEL_WEEKDAY     (0x00000001u)
#define RTC_ALARMDATEWEEKDAYSEL_WORKDAY     (0x00000002u)
#define RTC_ALARMDATEWEEKDAYSEL_EVERYDAY    (0x00000004u)

/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup RTC_Exported_Macros RTC Exported Macros
  * @{
  */

/** @brief Reset RTC handle state
  * @param  __HANDLE__ RTC handle.
  * @retval None
  */
#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
#define __HAL_RTC_RESET_HANDLE_STATE(__HANDLE__) do{\
                                                      (__HANDLE__)->State = HAL_RTC_STATE_RESET;\
                                                      (__HANDLE__)->MspInitCallback = NULL;\
                                                      (__HANDLE__)->MspDeInitCallback = NULL;\
                                                     }while(0)
#else
#define __HAL_RTC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_RTC_STATE_RESET)
#endif /* USE_HAL_RTC_REGISTER_CALLBACKS */

/**
  * @brief  Enable the RTC ALARMA peripheral.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_ENABLE(__HANDLE__)  LL_RTC_ALM_Enable((__HANDLE__)->Instance) 

/**
  * @brief  Disable the RTC ALARMA peripheral.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_DISABLE(__HANDLE__)  LL_RTC_ALM_Disable((__HANDLE__)->Instance) 

/**
  * @brief  Enable the RTC Alarm interrupt.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_ENABLE_IT(__HANDLE__)   ((__HANDLE__)->Instance->CCR |= (RTC_CCR_IEN))

/**
  * @brief  Disable the RTC Alarm interrupt.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_DISABLE_IT(__HANDLE__) ((__HANDLE__)->Instance->CCR &= ~(RTC_CCR_IEN))

/**
  * @brief  Mask the RTC Alarm interrupt.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_MASK_IT(__HANDLE__)   ((__HANDLE__)->Instance->CCR |= (RTC_CCR_MASK))

/**
  * @brief  Unmask the RTC Alarm interrupt.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_UNMASK_IT(__HANDLE__) ((__HANDLE__)->Instance->CCR &= ~(RTC_CCR_MASK))

/**
  * @brief  Check whether the specified RTC Alarm interrupt has occurred or not.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_GET_IT(__HANDLE__) (((((__HANDLE__)->Instance->STAT)))? 1U : 0U)

/**
  * @brief  Get the selected RTC Alarms flag status.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_GET_FLAG(__HANDLE__)   (__HAL_RTC_GET_FLAG((__HANDLE__)))

/**
  * @brief  Clear the RTC Alarms pending flags.
  * @param  __HANDLE__ specifies the RTC handle.
  * @retval None
  */
#define __HAL_RTC_ALARM_CLEAR_FLAG(__HANDLE__)   (__HAL_RTC_CLEAR_FLAG((__HANDLE__)))

/** @brief  Clear the specified RTC pending flag.
  * @param  __HANDLE__ specifies the RTC Handle.
  * @retval None
  */
#define __HAL_RTC_CLEAR_FLAG(__HANDLE__)   READ_REG((__HANDLE__)->Instance->EOI)

/** @brief  Check whether the specified RTC flag is set or not.
  * @param  __HANDLE__ specifies the RTC Handle.
  * @retval None
  */
#define __HAL_RTC_GET_FLAG(__HANDLE__)    READ_REG((__HANDLE__)->Instance->STAT)

/**
  * @}
  */

/* Include RTC HAL Extended module */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RTC_Exported_Functions RTC Exported Functions
  * @{
  */

/** @defgroup RTC_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
/* Initialization and de-initialization functions  ****************************/
HAL_StatusTypeDef HAL_RTC_Init(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_DeInit(RTC_HandleTypeDef *hrtc);

void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc);
void HAL_RTC_MspDeInit(RTC_HandleTypeDef *hrtc);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_RTC_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_RTC_RegisterCallback(RTC_HandleTypeDef *hrtc, HAL_RTC_CallbackIDTypeDef CallbackID, pRTC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_RTC_UnRegisterCallback(RTC_HandleTypeDef *hrtc, HAL_RTC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_RTC_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup RTC_Exported_Functions_Group2 RTC Time and Date functions
  * @{
  */
/* RTC Time and Date functions ************************************************/
HAL_StatusTypeDef HAL_RTC_SetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime);
HAL_StatusTypeDef HAL_RTC_GetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime);
HAL_StatusTypeDef HAL_RTC_SetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate);
HAL_StatusTypeDef HAL_RTC_GetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate);
/**
  * @}
  */

/** @defgroup RTC_Exported_Functions_Group3 RTC Alarm functions
  * @{
  */
/* RTC Alarm functions ********************************************************/
HAL_StatusTypeDef HAL_RTC_SetAlarm(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm);
HAL_StatusTypeDef HAL_RTC_SetAlarm_IT(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm);
HAL_StatusTypeDef HAL_RTC_DeactivateAlarm(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_GetAlarm(RTC_HandleTypeDef *hrtc, RTC_AlarmTypeDef *sAlarm);
void              HAL_RTC_AlarmIRQHandler(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_PollForAlarmEvent(RTC_HandleTypeDef *hrtc, uint32_t Timeout);
void              HAL_RTC_AlarmEventCallback(RTC_HandleTypeDef *hrtc);
/**
  * @}
  */

/** @defgroup  RTC_Exported_Functions_Group4 Peripheral Control functions
  * @{
  */
/* Peripheral Control functions ***********************************************/
void              HAL_RTC_IRQHandler(RTC_HandleTypeDef *hrtc);
void              HAL_RTC_IRQCallback(RTC_HandleTypeDef *hrtc);
/**
  * @}
  */

/** @defgroup RTC_Exported_Functions_Group5 Peripheral State functions
  * @{
  */
/* Peripheral State functions *************************************************/
HAL_RTCStateTypeDef HAL_RTC_GetState(RTC_HandleTypeDef *hrtc);
/**
  * @}
  */

/**
  * @}
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup RTC_Private_Constants RTC Private Constants
  * @{
  */
#define RTC_TIMEOUT_VALUE                   (1000u)

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup RTC_Private_Macros RTC Private Macros
  * @{
  */

/** @defgroup RTC_IS_RTC_Definitions RTC Private macros to check input parameters
  * @{
  */
#define IS_RTC_HOUR_FORMAT(FORMAT)     (((FORMAT) == RTC_HOURFORMAT_12) || \
                                        ((FORMAT) == RTC_HOURFORMAT_24))

#define IS_RTC_HOURFORMAT12(PM)  (((PM) == RTC_HOURFORMAT12_AM) || \
                                  ((PM) == RTC_HOURFORMAT12_PM))

#define IS_RTC_YEAR(YEAR)              ((YEAR) > 1900u)

#define IS_RTC_MONTH(MONTH)            (((MONTH) >= 0u) && ((MONTH) <= 11u))

#define IS_RTC_DATE(DATE)              (((DATE) >= 1u) && ((DATE) <= 31u))

#define IS_RTC_WEEKDAY(WEEKDAY) (((WEEKDAY) == RTC_WEEKDAY_MONDAY)    || \
                                 ((WEEKDAY) == RTC_WEEKDAY_TUESDAY)   || \
                                 ((WEEKDAY) == RTC_WEEKDAY_WEDNESDAY) || \
                                 ((WEEKDAY) == RTC_WEEKDAY_THURSDAY)  || \
                                 ((WEEKDAY) == RTC_WEEKDAY_FRIDAY)    || \
                                 ((WEEKDAY) == RTC_WEEKDAY_SATURDAY)  || \
                                 ((WEEKDAY) == RTC_WEEKDAY_SUNDAY))

#define IS_RTC_ALARM_DATE_WEEKDAY_DATE(DATE) (((DATE) >0u) && ((DATE) <= 31u))

#define IS_RTC_ALARM_DATE_WEEKDAY_WEEKDAY(WEEKDAY) (((WEEKDAY) == RTC_WEEKDAY_MONDAY)    || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_TUESDAY)   || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_WEDNESDAY) || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_THURSDAY)  || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_FRIDAY)    || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_SATURDAY)  || \
                                                    ((WEEKDAY) == RTC_WEEKDAY_SUNDAY))

#define IS_RTC_ALARM_DATE_WEEKDAY_SEL(SEL) (((SEL) == RTC_ALARMDATEWEEKDAYSEL_DATE) || \
                                            ((SEL) == RTC_ALARMDATEWEEKDAYSEL_WEEKDAY) || \
                                            ((SEL) == RTC_ALARMDATEWEEKDAYSEL_WORKDAY) || \
                                            ((SEL) == RTC_ALARMDATEWEEKDAYSEL_EVERYDAY))

#define IS_RTC_HOUR12(HOUR)            (((HOUR) > 0u) && ((HOUR) <= 12u))

#define IS_RTC_HOUR24(HOUR)            ((HOUR) <= 23u)

#define IS_RTC_MINUTES(MINUTES)        ((MINUTES) <= 59u)

#define IS_RTC_SECONDS(SECONDS)        ((SECONDS) <= 59u)

/**
  * @}
  */

/**
  * @}
  */

/* Private functions -------------------------------------------------------------*/
/** @defgroup RTC_Private_Functions RTC Private Functions
  * @{
  */
/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_HAL_RTC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
