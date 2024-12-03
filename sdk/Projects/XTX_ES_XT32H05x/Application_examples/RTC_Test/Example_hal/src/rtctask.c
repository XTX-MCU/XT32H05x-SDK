/**
  ******************************************************************************
  * @file    rtctask.c
  * @author  Software Team
  * @brief   
  *          
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "rtctask.h"
/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup RTC_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
#define RTC_CALENDER_ENABLE					(1)  //use for Calender function

/** @addtogroup RTC_Task_Private_Variables
  * @{
  */
/* Private variables ---------------------------------------------------------*/
RTC_HandleTypeDef hRtc;
RTC_TimeTypeDef sTime = {0};
RTC_DateTypeDef sDate = {0};
/**
  * @}
  */

/** @addtogroup RTC_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/

/**
  * @}
  */

/* Private user code ---------------------------------------------------------*/
/** @addtogroup RTC_Task_Exported_Functions
  * @{
  */
static void XTX_Rtc_Calender_Init(void)
{
    RTC_DateTypeDef sDateconfig = {0};
		/** Initialize RTC and set the Time and Date
    */	
    sTime.Hours   = 11;
    sTime.Minutes = 30;
    sTime.Seconds = 00;
    sTime.TimeFormat = LL_RTC_TIME_FORMAT_AM_OR_24;
    // sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;	

    sDateconfig.Month   = RTC_MONTH_OCTOBER;
    sDateconfig.Date    = 5;
    sDateconfig.Year    = YEAR_INIT(2023);	

//		while((sDate.Year) != (sDateconfig.Year))
		{
        if (HAL_RTC_SetDate(&hRtc, &sDateconfig/*, RTC_FORMAT_BCD*/) != HAL_OK)
        {
        		Error_Handle();
        }
 //       HAL_RTC_GetDate(&hRtc, &sDate/*, RTC_FORMAT_BIN*/);
    }
//		HAL_Delay(1500);
    if (HAL_RTC_SetTime(&hRtc, &sTime/*, RTC_FORMAT_BCD*/) != HAL_OK)
    {
        Error_Handle();
    }	
//		HAL_Delay(10);
    /* Get the RTC current Time */
 //   HAL_RTC_GetTime(&hRtc, &sTime/*, RTC_FORMAT_BIN*/);		
}

/**
 * @brief  Rtc Initialization Function
 */
void XT_Rtc_Init(void)
{
    /* -1- Configure RTC clock source and divider in SystemClock_Config() */
    LL_RCC_RTCResetRelease();  //release RTC reset  
    /* -2-* Initialize RTC */
    hRtc.Instance = RTC;
    hRtc.Init.HourFormat = RTC_HOURFORMAT_24;
    if (HAL_RTC_Init(&hRtc) != HAL_OK)
    {
        Error_Handle();
    }
#if defined(RTC_CALENDER_ENABLE)
    XTX_Rtc_Calender_Init();
#endif

    /* -3-* NVIC Initialization RTC in XT_Nvic_Init() */ 
    HAL_Delay(1000);
}


/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_Rtc_Task(void)
{
    /* USER CODE */
   	
    /* Get the RTC current Time */
    HAL_RTC_GetTime(&hRtc, &sTime/*, RTC_FORMAT_BIN*/);
    /* Get the RTC current Date */
    HAL_RTC_GetDate(&hRtc, &sDate/*, RTC_FORMAT_BIN*/);
	
    /* Display time Format : hh:mm:ss */
    DBG_printf("%02d-%2d-%02d(%02d)", sDate.Year + YEAR_SINCE,  sDate.Month+1, sDate.Date,sDate.WeekDay);	
    DBG_printf("  %02d:%02d:%02d  \n", sTime.Hours, sTime.Minutes, sTime.Seconds);	
    HAL_Delay(100);
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


/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
