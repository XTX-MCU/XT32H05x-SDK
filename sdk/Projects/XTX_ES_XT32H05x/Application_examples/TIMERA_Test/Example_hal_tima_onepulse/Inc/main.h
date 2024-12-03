/**
  ******************************************************************************
  * @file    main.h
  * @author  Software Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup Main_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @addtogroup Main_Task_Exported_Constants
  * @{
  */
#define HCLK_DIVIDER_VALUE     (1) /*user defined*/
#define PCLK_DIVIDER_VALUE     (2) /*user defined*/

#define TRUE                   (1)
#define FALSE                  (0)


/* Exported macro ------------------------------------------------------------*/

/** @addtogroup Main_Task_Exported_Functions
  * @{
  */
/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void );
void XT_IO_Option_Assigned(uint32_t io_idx, uint32_t io_cfg, uint32_t pin_pull);
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

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
