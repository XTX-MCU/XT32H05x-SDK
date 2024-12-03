/**
  ******************************************************************************
  * @file    ledtask.h
  * @author  Software Team
  * @brief   Header for ledtask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LEDTASK_H
#define __LEDTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup LED_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/** @defgroup LED_Exported_Types LED Exported Types
  * @{
  */

/**
  * @brief  LED Demo pattern definition
  */
typedef enum
{
	LED_DEMO_NONE     =0,
  LED_DEMO_SCANONE  =1,	
  LED_DEMO_SCANROW  ,
  LED_DEMO_SCANCOL  ,
  LED_DEMO_NUMBLINK ,
  LED_DEMO_DIMMING  ,
  LED_DEMO_BREATH   ,
} LED_DemoPatternDef;
/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/
/** @defgroup LED_Exported_Constants
  * @{
  */
#define LED_FRM_DMAHSIF_IDX          LL_DMA_SHIF_CFG_3_INDEX_LED_FRM		  /*DMA ModeDMA Handshaking Interface:INDEX 0 of CFG3*/       
#define LED_FRM_DMAHSIF_CFG          LL_DMA_SHIF_CFG_3_CFG_LED_FRM		    /*DMA ModeDMA Handshaking Interface: CFG3*/       

#define LED_UDT_DMAHSIF_IDX          LL_DMA_SHIF_CFG_3_INDEX_LED_UDT	    /*DMA ModeDMA Handshaking Interface:INDEX 1 of CFG3*/ 
#define LED_UDT_DMAHSIF_CFG          LL_DMA_SHIF_CFG_3_CFG_LED_UDT	      /*DMA ModeDMA Handshaking Interface: CFG3*/ 
 
#define LED_COM_DMAHSIF_IDX          LL_DMA_SHIF_CFG_3_INDEX_LED_COM	    /*DMA ModeDMA Handshaking Interface:INDEX 2 of CFG3*/ 
#define LED_COM_DMAHSIF_CFG          LL_DMA_SHIF_CFG_3_CFG_LED_COM	      /*DMA ModeDMA Handshaking Interface: CFG3*/ 

/**
  * @}
  */
/* Exported macro ------------------------------------------------------------*/
//#define LED_USE_DMA            (1)


/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup LED_Task_Exported_Functions
  * @{
  */
extern void XT_Led_Init(void);
extern void XT_Led_Task(void);

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

#endif /* __LEDTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
