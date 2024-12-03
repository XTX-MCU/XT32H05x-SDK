/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    /Inc/main.h
  * @author  Software Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech .
  * All rights reserved.
  *
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"
#include "xt32h0xx_ll_system.h"

/** @addtogroup App_Gpio
  * @{
  */

/** @addtogroup Gpio_Blink
  * @{
  */

/* Exported constants --------------------------------------------------------*/
/** @addtogroup App_Exported_Constants App Exported Constants
  * @{
  */
#define TRUE                   (1)
#define FALSE                  (0)
#define TEST_TIMEOUT           (50000) //ms
#define TIMEOUT_MAX_DELAY      0xFFFFFFFFU
/**
  * @}
  */
	
/* Exported types ------------------------------------------------------------*/
/** @addtogroup App_Exported_Types App Exported Types
  * @{
  */
/**
  * @brief  Type Structure definition
  */
typedef enum {
	STATE_RESET     	= 0,
	STATE_READY     	= 1,
	STATE_BUSY          ,
	STATE_BUSY_TX       ,
	STATE_BUSY_RX       ,
	STATE_TIMEOUT       ,
	STATE_ABORT         ,	
	STATE_ERROR         ,
}MODULE_STATE;

/**
  * @}
  */

/** @addtogroup App_Exported_Macros App Exported Macros
  * @{
  */
#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
/**
  * @}
  */

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup App_Exported_Functions
  * @{
  */
extern void Error_Handler(void);
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

#endif /* __MAIN_H */
