/**
  ******************************************************************************
  * @file    rtctask.h
  * @author  Software Team
  * @brief   Header for rtctask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RTCTASK_H
#define __RTCTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"


/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup RTC_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
#define  YEAR_SINCE	 					(1900)
#define  YEAR_INIT(xy) 					(xy - YEAR_SINCE)

/* Exported macro ------------------------------------------------------------*/

/** @addtogroup RTC_Task_Exported_Functions
  * @{
  */
/* Exported functions prototypes ---------------------------------------------*/
extern void XT_Rtc_Init(void );
extern void XT_Rtc_Task(void );

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

#endif /* __RTCTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
