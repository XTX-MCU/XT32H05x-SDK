/**
  ******************************************************************************
  * @file    spitask.h
  * @author  Software Team
  * @brief   Header for spitask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPITASK_H
#define __SPITASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup SPI_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/**
  * @brief  Callback status Type Structure definition
  */
typedef enum  {
    CB_SPI_IDLE = 0,
    CB_SPI1_TXFNSH,
    CB_SPI1_RXFNSH,
    CB_SPI1_TXRXFNSH,	
    CB_SPI2_TXFNSH,
    CB_SPI2_RXFNSH,
    CB_SPI2_TXRXFNSH,
    CB_SPI_ABORT,		
    CB_SPI_ERROR,		
}SPITASK_CBSTA;
/* Exported macro ------------------------------------------------------------*/
	
/* Exported constants --------------------------------------------------------*/

#define EVB_SPI1_CS_IO_IDX           PADI_IDX_IO22_SPI1_SS			/*1: CSB*/        
#define EVB_SPI1_CS_IO_CFG           PADI_CFG_IO22_SPI1_SS		 
				 
#define EVB_SPI1_CLK_IO_IDX          PADI_IDX_IO25_SPI1_SCK			/*1: CLK*/        
#define EVB_SPI1_CLK_IO_CFG          PADI_CFG_IO25_SPI1_SCK		
			 									          
#define EVB_SPI1_TXD_IO_IDX          PADI_IDX_IO23_SPI1_TXD		  /*SPI0.TXD (Master as MO; Slaver as SO*/      
#define EVB_SPI1_TXD_IO_CFG          PADI_CFG_IO23_SPI1_TXD	
			 						          
#define EVB_SPI1_RXD_IO_IDX          PADI_IDX_IO24_SPI1_RXD		  /*SPI0.RXD (Master as MI; Slaver as SI*/       
#define EVB_SPI1_RXD_IO_CFG          PADI_CFG_IO24_SPI1_RXD	

#define SPI1_RXD_DMAHSIF_IDX          LL_DMA_SHIF_CFG_1_INDEX_SPI1_RX		  /*DMA ModeDMA Handshaking Interface: INDEX 9 of CFG1*/       
#define SPI1_TXD_DMAHSIF_IDX          LL_DMA_SHIF_CFG_1_INDEX_SPI1_TX	    /*DMA ModeDMA Handshaking Interface:INDEX 8 of CFG1*/ 
#define SPI1_RXD_DMAHSIF_CFG          LL_DMA_SHIF_CFG_1_CFG_SPI1_RX		    /*DMA ModeDMA Handshaking Interface: CFG1*/       
#define SPI1_TXD_DMAHSIF_CFG          LL_DMA_SHIF_CFG_1_CFG_SPI1_TX	      /*DMA ModeDMA Handshaking Interface: CFG1*/ 

#define EVB_SPI2_CS_IO_IDX					PADI_IDX_IO10_SPI2_SS			/* CSB*/        
#define EVB_SPI2_CS_IO_CFG					PADI_CFG_IO10_SPI2_SS		 
				 
#define EVB_SPI2_CLK_IO_IDX					PADI_IDX_IO13_SPI2_SCK			/* CLK*/        
#define EVB_SPI2_CLK_IO_CFG					PADI_CFG_IO13_SPI2_SCK		
				 						
#define EVB_SPI2_TXD_IO_IDX					PADI_IDX_IO14_SPI2_TXD		  /*SPI1.TXD (Master as MO; Slaver as SO*/      
#define EVB_SPI2_TXD_IO_CFG					PADI_CFG_IO14_SPI2_TXD	
			 					
#define EVB_SPI2_RXD_IO_IDX					PADI_IDX_IO15_SPI2_RXD		  /*SPI1.RXD (Master as MI; Slaver as SI*/       
#define EVB_SPI2_RXD_IO_CFG					PADI_CFG_IO15_SPI2_RXD	


#define SPI2_RXD_DMAHSIF_IDX          LL_DMA_SHIF_CFG_0_INDEX_SPI2_RX		  /*DMA ModeDMA Handshaking Interface: INDEX 11 of CFG0*/       
#define SPI2_TXD_DMAHSIF_IDX          LL_DMA_SHIF_CFG_0_INDEX_SPI2_TX	    /*DMA ModeDMA Handshaking Interface:INDEX 10 of CFG0*/ 
#define SPI2_RXD_DMAHSIF_CFG          LL_DMA_SHIF_CFG_0_CFG_SPI2_RX		    /*DMA ModeDMA Handshaking Interface: CFG0*/       
#define SPI2_TXD_DMAHSIF_CFG          LL_DMA_SHIF_CFG_0_CFG_SPI2_TX	      /*DMA ModeDMA Handshaking Interface: CFG0*/ 

/** @addtogroup SPI_Task_Exported_Functions
  * @{
  */
/* Exported functions prototypes ---------------------------------------------*/
extern void XT_Spi_Init(void );
extern void XT_Spi_Task(void );

/* Private defines -----------------------------------------------------------*/
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

#endif /* __SPITASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
