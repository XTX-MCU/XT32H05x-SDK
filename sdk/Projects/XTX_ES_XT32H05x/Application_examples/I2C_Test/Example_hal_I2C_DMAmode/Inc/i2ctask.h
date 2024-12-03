/**
  ******************************************************************************
  * @file    i2ctask.h
  * @author  Software Team
  * @brief   Header for i2ctask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2CTASK_H
#define __I2CTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup I2C_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/** @addtogroup I2C_Task_Exported_Types
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/**
  * @brief  Callback status Type Structure definition
  */
typedef enum  {
    CB_I2C_IDLE = 0,
    CB_I2C1_TXFNSH,
    CB_I2C1_RXFNSH,
    CB_I2C2_TXFNSH,
    CB_I2C2_RXFNSH,
    CB_I2C_ABORT,		
    CB_I2C_ERROR,		
}I2CTASK_CBSTA;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @addtogroup I2C_Task_Exported_Constants
  * @{
  */
#define EVB_I2C1_SCK_IO_IDX					PADI_IDX_IO13_I2C1_SCK		   	/* I2C1*/	     
#define EVB_I2C1_SCK_IO_CFG					PADI_CFG_IO13_I2C1_SCK		 

#define EVB_I2C1_SDA_IO_IDX					PADI_IDX_IO14_I2C1_SDA		        
#define EVB_I2C1_SDA_IO_CFG					PADI_CFG_IO14_I2C1_SDA	

#define I2C1_RXD_DMAHSIF_IDX          LL_DMA_SHIF_CFG_0_INDEX_I2C1_RX		  /*DMA ModeDMA Handshaking Interface: INDEX 9 of CFG0*/       
#define I2C1_TXD_DMAHSIF_IDX          LL_DMA_SHIF_CFG_0_INDEX_I2C1_TX	    /*DMA ModeDMA Handshaking Interface:INDEX 8 of CFG0*/ 
#define I2C1_RXD_DMAHSIF_CFG          LL_DMA_SHIF_CFG_0_CFG_I2C1_RX		    /*DMA ModeDMA Handshaking Interface: CFG1*/       
#define I2C1_TXD_DMAHSIF_CFG          LL_DMA_SHIF_CFG_0_CFG_I2C1_TX	      /*DMA ModeDMA Handshaking Interface: CFG1*/ 
        

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @addtogroup I2C_Task_Exported_Functions
  * @{
  */
/* Exported functions --------------------------------------------------------*/
extern void XT_I2c_Init(void );
extern void XT_I2c_Task(void );
extern void XT_I2c_Checksta(I2CTASK_CBSTA esta);
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

#endif /* __I2CTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
