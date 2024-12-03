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
DMA_HandleTypeDef hI2c1Dmarx;
DMA_HandleTypeDef hI2c1Dmatx;
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
static void XT_DMAPeriphI2C1_Init(void)
{
    hI2c1Dmatx.Instance       = DMA1_Channel2;
    hI2c1Dmatx.ChannelIndex   = 2;
    hI2c1Dmatx.Init.Direction = DMA_MEMORY_TO_PERIPH_FC_DMAC;
    hI2c1Dmatx.Init.SrcInc    = DMA_SINC_INCREMENT;
    hI2c1Dmatx.Init.DstInc    = DMA_DINC_NOCHANGE;
    hI2c1Dmatx.Init.SrcDataSize  = DMA_SDATAALIGN_BYTE;
    hI2c1Dmatx.Init.DstDataSize  = DMA_DDATAALIGN_BYTE;
    hI2c1Dmatx.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hI2c1Dmatx.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hI2c1Dmatx.Init.Mode = DMA_SGLBLK;
    hI2c1Dmatx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hI2c1Dmatx) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
	  
	  hI2c1Dmarx.Instance       = DMA1_Channel3;
    hI2c1Dmarx.ChannelIndex   = 3;
    hI2c1Dmarx.Init.Direction = DMA_PERIPH_TO_MEMORY_FC_DMAC;
    hI2c1Dmarx.Init.SrcInc    = DMA_SINC_NOCHANGE;
    hI2c1Dmarx.Init.DstInc    = DMA_DINC_INCREMENT;
	  
    hI2c1Dmarx.Init.SrcDataSize  = DMA_SDATAALIGN_BYTE;
    hI2c1Dmarx.Init.DstDataSize  = DMA_DDATAALIGN_BYTE;
    hI2c1Dmarx.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hI2c1Dmarx.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hI2c1Dmarx.Init.Mode = DMA_SGLBLK;
    hI2c1Dmarx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hI2c1Dmarx) != HAL_OK)
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
    XT_DMAPeriphI2C1_Init( );

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
