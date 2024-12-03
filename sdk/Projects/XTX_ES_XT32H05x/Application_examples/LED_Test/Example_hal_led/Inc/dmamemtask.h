/**
  ******************************************************************************
  * @file    dmamemtask.h
  * @author  Software Team
  * @brief   Header for dmamemtask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __DMAMEMTASK_H
#define __DMAMEMTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"


/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup DMA_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/**
  * @brief  Callback status Type Structure definition
  */
typedef enum  {
    CB_DMA_IDLE = 0,
    CB_DMA_TFRFNSH,
    CB_DMA_BLKFNSH,	
    CB_DMA_DSTFNSH,	
    CB_DMA_ABORT,		
    CB_DMA_ERROR,		
}SPITASK_CBSTA;
/* Exported constants --------------------------------------------------------*/
 
/* Exported macro ------------------------------------------------------------*/

/** @addtogroup DMA_Task_Exported_Functions
  * @{
  */
/* Exported functions prototypes ---------------------------------------------*/
extern void XT_Dmamem_Init(void );
extern void XT_Dmamem_Task(void );
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

#endif /* __DMAMEMTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
