/**
  ******************************************************************************
  * @file    crctask.h
  * @author  Software Team
  * @brief   Header for crctask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CRCTASK_H
#define __CRCTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup CRC_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/** @addtogroup CRC_Task_Exported_Macro
  * @{
  */
#define CRC_TEST_BUFFER_SIZE		 8 
/**
  * @}
  */
	
/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup CRC_Task_Exported_Functions
  * @{
  */
extern void XT_Crc_Init(void );
extern void XT_Crc_Task(void );
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

#endif /* __CRCTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
