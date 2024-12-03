/**
  ******************************************************************************
  * @file    wdtitask.h
  * @author  Software Team
  * @brief   Header for wdtitask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WDTITASK_H
#define __WDTITASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"
 

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup WDTI_Task
  * @{
  */
/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup WDTI_Task_Exported_Functions
  * @{
  */
extern void XT_Wdti_Init(void );
extern void XT_Wdti_Task(void );
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

#endif /* __WDTITASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
