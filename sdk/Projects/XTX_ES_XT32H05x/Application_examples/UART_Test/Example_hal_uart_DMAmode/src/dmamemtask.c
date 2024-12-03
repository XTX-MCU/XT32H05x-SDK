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
DMA_HandleTypeDef hDmauartTX;
DMA_HandleTypeDef hDmauartRX;

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
static void XT_DMAUartTx_Init(void)
{
    hDmauartTX.Instance       = DMA1_Channel2;
    hDmauartTX.ChannelIndex   = 2;
    hDmauartTX.Init.Direction = DMA_MEMORY_TO_PERIPH_FC_DMAC;
    hDmauartTX.Init.SrcInc    = DMA_SINC_INCREMENT;
    hDmauartTX.Init.DstInc    = DMA_DINC_NOCHANGE;
    hDmauartTX.Init.SrcDataSize  = DMA_SDATAALIGN_BYTE;
    hDmauartTX.Init.DstDataSize  = DMA_DDATAALIGN_BYTE;
    hDmauartTX.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hDmauartTX.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hDmauartTX.Init.Mode = DMA_SGLBLK;
    hDmauartTX.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hDmauartTX) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
    
}

/**
 * @brief  DMAPeriphRx Initialization Function
 */
static void XT_DMAUartRx_Init(void)
{
    hDmauartRX.Instance       = DMA1_Channel3;
    hDmauartRX.ChannelIndex   = 3;
    hDmauartRX.Init.Direction = DMA_PERIPH_TO_MEMORY_FC_DMAC;
    hDmauartRX.Init.SrcInc    = DMA_SINC_NOCHANGE;
    hDmauartRX.Init.DstInc    = DMA_DINC_INCREMENT;
    
    hDmauartRX.Init.SrcDataSize  = DMA_SDATAALIGN_BYTE;
    hDmauartRX.Init.DstDataSize  = DMA_DDATAALIGN_BYTE;
    hDmauartRX.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hDmauartRX.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hDmauartRX.Init.Mode = DMA_SGLBLK;
    hDmauartRX.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hDmauartRX) != HAL_OK)
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
    XT_DMAUartTx_Init();
    XT_DMAUartRx_Init();
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
