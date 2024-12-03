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
#define EVB_UART2_PINCONFIG_GRP        0x2A     //2A:  13&14,   2B:18&19,   2C:39&38
#define EVB_UART3_PINCONFIG_GRP        0x3A     //3A:  35&36,   3B:40&41,     
#define EVB_UART4_PINCONFIG_GRP        0x4B     //4A:  56&55,   4B:58&57,    

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup UART_Task_Exported_Functions
  * @{
  */
extern void XT_Uart_Init(void);
extern void XT_Uart_Task(void);
/**
  * @}
  */

/* Private defines -----------------------------------------------------------*/
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
