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
    CB_DMATX_TFRFNSH,
    CB_DMATX_BLKFNSH,	
    CB_DMARX_TFRFNSH,
    CB_DMARX_BLKFNSH,		
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
extern void XT_DMAstate_Reset(void);
extern void XT_TIMx_DMA_readcfg(TIM_HandleTypeDef *htim, uint16_t timchid);
extern void XT_TIMx_DMA_writecfg(TIM_HandleTypeDef *htim, uint16_t timchid);
extern void XT_DMAstate_Reset(void);
extern uint8_t XT_DMAstate_End_Check(void);

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
