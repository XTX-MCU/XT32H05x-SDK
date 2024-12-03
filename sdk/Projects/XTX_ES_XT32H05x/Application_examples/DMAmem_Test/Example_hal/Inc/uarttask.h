/**
  ******************************************************************************
  * @file    uarttask.h
  * @author  Software Team
  * @brief   Header for uarttask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __UARTTASK_H
#define __UARTTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup UART_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
#define  SUPPORT_DBG                            (1)

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup UART_Task_Exported_Functions
  * @{
  */
extern void XT_Uart_Init(void);
extern void XT_Uart_Task(void);
extern void DBG_printf(const char * buff, ...);
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

#endif /* __UARTTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
