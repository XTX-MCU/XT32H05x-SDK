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
#define DMA_BUFFER_SIZE                    (32)

/* Private variables ---------------------------------------------------------*/
/** @addtogroup DMA_Task_Private_Variables 
  * @{
  */
DMA_HandleTypeDef hDmamem1;
uint32_t aSrc1[40];
static  const uint32_t aSRC1_FLASH_Buffer[DMA_BUFFER_SIZE] =
{
	0x01020304,  0x05060708,  0x090A0B0C,  0x0D0E0F10,
	0x11121314,  0x15161718,  0x191A1B1C,  0x1D1E1F20,
	0x21222324,  0x25262728,  0x292A2B2C,  0x2D2E2F30,
	0x31323334,  0x35363738,  0x393A3B3C,  0x3D3E3F40,
	0x41424344,  0x45464748,  0x494A4B4C,  0x4D4E4F50,
	0x51525354,  0x55565758,  0x595A5B5C,  0x5D5E5F60,
	0x61626364,  0x65666768,  0x696A6B6C,  0x6D6E6F70,
	0x71727374,  0x75767778,  0x797A7B7C,  0x7D7E7F80
};
uint32_t aDst1[DMA_BUFFER_SIZE];
uint8_t u1Dmamem_cbState = CB_DMA_IDLE;

/**
  * @}
  */

/** @addtogroup DMA_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void XT_DMAMEM1_Init(void );
static void XT_Dmamem_TransferCplt(DMA_HandleTypeDef *hdma_channel);
static void XT_Dmamem_TransferBLKCplt(DMA_HandleTypeDef *hdma_channel);
static void XT_Dmamem_TransferError(DMA_HandleTypeDef *hdma_channel);
/* Private user code ---------------------------------------------------------*/
/**
 * @brief  DMAMEM1 Initialization Function
 */
static void XT_DMAMEM_Flash2ram_Init(void)
{
    /* Enable FLASH DMA transfer*/
    MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_FLASHDMA, SYSCFG_SYS_CFG_FLASHDMA);
	
    hDmamem1.Instance     = DMA1_Channel4;
    hDmamem1.ChannelIndex = 4;
    hDmamem1.Init.Direction = DMA_MEMORY_TO_MEMORY_FC_DMAC;
    hDmamem1.Init.SrcInc    = DMA_SINC_INCREMENT;
    hDmamem1.Init.DstInc    = DMA_DINC_INCREMENT;
    hDmamem1.Init.SrcDataSize  = DMA_SDATAALIGN_WORD;
    hDmamem1.Init.DstDataSize  = DMA_DDATAALIGN_WORD;
    hDmamem1.Init.SrcBurstSize = DMA_SRC_MSIZE_4;
    hDmamem1.Init.DstBurstSize = DMA_DST_MSIZE_4;
    hDmamem1.Init.Mode = DMA_SGLBLK;
    hDmamem1.DMAAux = DMAAUX1;
    if (HAL_DMA_Init(&hDmamem1) != HAL_OK)
    {
      /* Error_Handler */
    }
    
}


/**
  * @brief  DMA conversion complete callback
  * @note   This function is executed when the transfer complete interrupt
  *         is generated
  */
static void XT_Dmamem_TransferCplt(DMA_HandleTypeDef *hdma_channel)
{ 
    if(hdma_channel->Instance == hDmamem1.Instance)
    {
        u1Dmamem_cbState = CB_DMA_TFRFNSH;
    }
}


static void XT_Dmamem_TransferBLKCplt(DMA_HandleTypeDef *hdma_channel)
{   
    if(hdma_channel->Instance == hDmamem1.Instance)
    {
         u1Dmamem_cbState = CB_DMA_BLKFNSH;
    }
}
/**
  * @brief  DMA conversion error callback
  * @note   This function is executed when the transfer error interrupt
  *         is generated during DMA transfer
  */
static void XT_Dmamem_TransferError(DMA_HandleTypeDef *hdma_channel)
{  
    if(hdma_channel->Instance == hDmamem1.Instance)
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
  */
void XT_Dmamem_Init(void)
{
    XT_DMAMEM_Flash2ram_Init( );
}

/**
  * @brief  This function is executed.
  */
void XT_Dmamem_Task(void)
{
    /* USER CODE */
    DBG_printf("DMA Memory2memeory test Start!\n");
    /* Select Callbacks functions called after Transfer complete and Transfer error */
    HAL_DMA_RegisterCallback(&hDmamem1, HAL_DMA_XFER_CPLT_CB_ID, XT_Dmamem_TransferCplt);
    HAL_DMA_RegisterCallback(&hDmamem1, HAL_DMA_XFER_BLOCK_CB_ID, XT_Dmamem_TransferBLKCplt);
    HAL_DMA_RegisterCallback(&hDmamem1, HAL_DMA_XFER_ERROR_CB_ID, XT_Dmamem_TransferError);
	
    /* Configure the source, destination and buffer size DMA fields and Start DMA Channel/Stream transfer */
    /* Enable All the DMA interrupts */
    if (HAL_DMA_Start_IT(&hDmamem1, (uint32_t)&aSRC1_FLASH_Buffer, (uint32_t)&aDst1, DMA_BUFFER_SIZE) != HAL_OK)
    {
    	/* Transfer Error */
        Error_Handle();
    }
    
    while(u1Dmamem_cbState==CB_DMA_IDLE);	
    u1Dmamem_cbState = CB_DMA_IDLE;
    if(Buffercmp(aSRC1_FLASH_Buffer,aDst1,DMA_BUFFER_SIZE)!=0)
    {	
		    DBG_printf("DMA Memory2memeory test fail.\n");
        Error_Handle();
    }else
    {
        DBG_printf("DMA Memory2memeory test success.\n");
    }
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
