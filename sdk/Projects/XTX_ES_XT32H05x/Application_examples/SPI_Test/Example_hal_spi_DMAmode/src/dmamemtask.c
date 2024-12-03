/**
  ******************************************************************************
  * @file    dmamemtask.c
  * @author  Software Team
  * @brief   
  *          
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dmamemtask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup DMA_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @addtogroup DMA_Task_Private_Variables 
  * @{
  */
DMA_HandleTypeDef hDmaSpi1tx;
DMA_HandleTypeDef hDmaSpi1rx;
DMA_HandleTypeDef hDmaSpi2tx;
DMA_HandleTypeDef hDmaSpi2rx;
/**
  * @}
  */

/** @addtogroup DMA_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void XT_DMAMEM1_Init(void );
static void XT_DMAMEM2_Init(void );

/* Private user code ---------------------------------------------------------*/
/**
 * @brief  DMAPeriphTx Initialization Function
 */
static void XT_DMAPeriphSPI1_Init(void)
{
    hDmaSpi1tx.Instance       = DMA1_Channel2;
    hDmaSpi1tx.ChannelIndex   = 2;
    hDmaSpi1tx.Init.Direction = DMA_MEMORY_TO_PERIPH_FC_DMAC;
    hDmaSpi1tx.Init.SrcInc    = DMA_SINC_INCREMENT;
    hDmaSpi1tx.Init.DstInc    = DMA_DINC_NOCHANGE;
    hDmaSpi1tx.Init.SrcDataSize  = DMA_SDATAALIGN_BYTE;
    hDmaSpi1tx.Init.DstDataSize  = DMA_DDATAALIGN_BYTE;
    hDmaSpi1tx.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hDmaSpi1tx.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hDmaSpi1tx.Init.Mode = DMA_SGLBLK;
    hDmaSpi1tx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hDmaSpi1tx) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
	  
	  hDmaSpi1rx.Instance       = DMA1_Channel3;
    hDmaSpi1rx.ChannelIndex   = 3;
    hDmaSpi1rx.Init.Direction = DMA_PERIPH_TO_MEMORY_FC_DMAC;
    hDmaSpi1rx.Init.SrcInc    = DMA_SINC_NOCHANGE;
    hDmaSpi1rx.Init.DstInc    = DMA_DINC_INCREMENT;
	  
    hDmaSpi1rx.Init.SrcDataSize  = DMA_SDATAALIGN_BYTE;
    hDmaSpi1rx.Init.DstDataSize  = DMA_DDATAALIGN_BYTE;
    hDmaSpi1rx.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hDmaSpi1rx.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hDmaSpi1rx.Init.Mode = DMA_SGLBLK;
    hDmaSpi1rx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hDmaSpi1rx) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
}

/**
 * @brief  DMAPeriphRx Initialization Function
 */
static void XT_DMAPeriphSPI2_Init(void)
{
    hDmaSpi2tx.Instance       = DMA1_Channel5;
    hDmaSpi2tx.ChannelIndex   = 5;
    hDmaSpi2tx.Init.Direction = DMA_MEMORY_TO_PERIPH_FC_DMAC;
    hDmaSpi2tx.Init.SrcInc    = DMA_SINC_INCREMENT;
    hDmaSpi2tx.Init.DstInc    = DMA_DINC_NOCHANGE;
    hDmaSpi2tx.Init.SrcDataSize  = DMA_SDATAALIGN_BYTE;
    hDmaSpi2tx.Init.DstDataSize  = DMA_DDATAALIGN_BYTE;
    hDmaSpi2tx.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hDmaSpi2tx.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hDmaSpi2tx.Init.Mode = DMA_SGLBLK;
    hDmaSpi2tx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hDmaSpi2tx) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
	  
	  hDmaSpi2rx.Instance       = DMA1_Channel6;
    hDmaSpi2rx.ChannelIndex   = 6;
    hDmaSpi2rx.Init.Direction = DMA_PERIPH_TO_MEMORY_FC_DMAC;
    hDmaSpi2rx.Init.SrcInc    = DMA_SINC_NOCHANGE;
    hDmaSpi2rx.Init.DstInc    = DMA_DINC_INCREMENT;
					  
    hDmaSpi2rx.Init.SrcDataSize  = DMA_SDATAALIGN_BYTE;
    hDmaSpi2rx.Init.DstDataSize  = DMA_DDATAALIGN_BYTE;
    hDmaSpi2rx.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hDmaSpi2rx.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hDmaSpi2rx.Init.Mode = DMA_SGLBLK;
    hDmaSpi2rx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hDmaSpi2rx) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
}

/**
  * @}
  */

/** @addtogroup DMA_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_Dmamem_Init(void)
{
    XT_DMAPeriphSPI1_Init( );
    XT_DMAPeriphSPI2_Init( );
}

/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_Dmamem_Task(void)
{
  /* USER CODE */
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
