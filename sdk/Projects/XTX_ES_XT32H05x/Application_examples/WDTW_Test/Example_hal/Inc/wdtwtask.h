/**
  ******************************************************************************
  * @file    wdtwtask.h
  * @author  Software Team
  * @brief   Header for wdtwtask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WDTWTASK_H
#define __WDTWTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup WDTW_Task
  * @{
  */
/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup WDTW_Task_Exported_Functions
  * @{
  */
extern void XT_Wdtw_Init(void );
extern void XT_Wdtw_Task(void );
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

#endif /* __WDTWTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
