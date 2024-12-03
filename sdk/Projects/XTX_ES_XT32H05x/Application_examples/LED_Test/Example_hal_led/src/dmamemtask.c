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
DMA_HandleTypeDef hLedDmatx;
uint8_t u1Dmamem_cbState = CB_DMA_IDLE;
/**
  * @}
  */

/** @addtogroup DMA_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void XT_DMAPeriphLED_Init(void );
static void XT_Dmamem_TransferCplt(DMA_HandleTypeDef *hdma_channel);
static void XT_Dmamem_TransferBLKCplt(DMA_HandleTypeDef *hdma_channel);
static void XT_Dmamem_DstTran_Cplt(DMA_HandleTypeDef *hdma_channel);
static void XT_Dmamem_TransferError(DMA_HandleTypeDef *hdma_channel);
/* Private user code ---------------------------------------------------------*/
/**
 * @brief  DMAPeriphTx Initialization Function
 */
static void XT_DMAPeriphLED_Init(void)
{
    hLedDmatx.Instance       = DMA1_Channel4;
    hLedDmatx.ChannelIndex   = 4;
    hLedDmatx.Init.Direction = DMA_MEMORY_TO_PERIPH_FC_DMAC;
    hLedDmatx.Init.SrcInc    = DMA_SINC_INCREMENT;
    hLedDmatx.Init.DstInc    = DMA_DINC_INCREMENT;
    hLedDmatx.Init.SrcDataSize  = DMA_SDATAALIGN_WORD;
    hLedDmatx.Init.DstDataSize  = DMA_DDATAALIGN_WORD;
    hLedDmatx.Init.SrcBurstSize = DMA_SRC_MSIZE_1;
    hLedDmatx.Init.DstBurstSize = DMA_DST_MSIZE_1;
    hLedDmatx.Init.Mode = DMA_SGLBLK;
    hLedDmatx.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hLedDmatx) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
		
    HAL_DMA_RegisterCallback(&hLedDmatx,HAL_DMA_XFER_CPLT_CB_ID, XT_Dmamem_TransferCplt);		
//    HAL_DMA_RegisterCallback(&hLedDmatx,HAL_DMA_XFER_BLOCK_CB_ID, XT_Dmamem_TransferBLKCplt);
#if (LED_USE_DMA_REQUEST == 0)	
 //   HAL_DMA_RegisterCallback(&hLedDmatx,HAL_DMA_XFER_DSTTRAN_CB_ID, XT_Dmamem_DstTran_Cplt);
#endif	
}

/**
  * @brief  DMA conversion complete callback
  * @note   This function is executed when the transfer complete interrupt
  *         is generated
  * @retval None
  */
static void XT_Dmamem_TransferCplt(DMA_HandleTypeDef *hdma_channel)
{ 
    if(hdma_channel->Instance == hLedDmatx.Instance)
    {
        u1Dmamem_cbState = CB_DMA_TFRFNSH;
			  XT_LED_DmaCpltCB();
    }
}


static void XT_Dmamem_TransferBLKCplt(DMA_HandleTypeDef *hdma_channel)
{   
    if(hdma_channel->Instance == hLedDmatx.Instance)
    {
         u1Dmamem_cbState = CB_DMA_BLKFNSH;
			   XT_LED_DmaCpltCB();
    }
}

static void XT_Dmamem_DstTran_Cplt(DMA_HandleTypeDef *hdma_channel)
{   
    if(hdma_channel->Instance == hLedDmatx.Instance)
    {
         u1Dmamem_cbState = CB_DMA_DSTFNSH;
    }
}
/**
  * @brief  DMA conversion error callback
  * @note   This function is executed when the transfer error interrupt
  *         is generated during DMA transfer
  * @retval None
  */
static void XT_Dmamem_TransferError(DMA_HandleTypeDef *hdma_channel)
{  
    if(hdma_channel->Instance == hLedDmatx.Instance)
    {
         u1Dmamem_cbState = CB_DMA_ERROR;
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
    XT_DMAPeriphLED_Init( );

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
