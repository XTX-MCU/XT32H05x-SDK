/**
  ******************************************************************************
  * @file    spitask.c
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
#include "spitask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup SPI_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @addtogroup SPI_Task_Private_Variables
  * @{
  */
SPI_HandleTypeDef hSpi1master;
SPI_HandleTypeDef hSpi2slaver;

uint8_t aSpi1TxBuffer[] = "==SPI1 Master transmint testing 2023**";
uint8_t aSpi2TxBuffer[] = "==SPI2 Slaver transmint testing 2023**";
uint8_t aRxBuffer[255]; /* Buffer used for reception */
uint8_t u1Spi_cbState = CB_SPI_IDLE;


/**
  * @}
  */

/** @addtogroup SPI_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void XT_SPI1M_Init(void );
static void XT_SPI2S_Init(void );
/* Private user code ---------------------------------------------------------*/


/**
 * @brief  SPI1M Initialization Function
 */
void XT_SPI1M_Init(void)
{
    hSpi1master.Instance           = SPI1M;
    hSpi1master.Init.Direction     = SPI_DIRECTION_2LINES;
    hSpi1master.Init.DataSize      = SPI_DATASIZE_8BIT;
    hSpi1master.Init.ClockPolarity = SPI_POLARITY_LOW;
    hSpi1master.Init.ClockPhase    = SPI_PHASE_1EDGE;
    hSpi1master.Init.BaudRate      = 64;
    hSpi1master.Init.Standard      = SPI_FRF_MOTO;
    hSpi1master.Init.ControlSize   = SPI_CTRLSIZE_1BIT;
    hSpi1master.Init.NumberDataFrame = 1;
    hSpi1master.Init.TxFIFOTLvl = SPI_TXFIFO_THRESHOLD_QF;
    hSpi1master.Init.RxFIFOTLvl = SPI_RXFIFO_THRESHOLD_HF;
  
    if (HAL_SPI_Init(&hSpi1master) != HAL_OK)
    {
      /* Error_Handle */
  		Error_Handle();
    }
  
}


/**
 * @brief  SPI2S Initialization Function
 */
void XT_SPI2S_Init(void)
{
    hSpi2slaver.Instance           = SPI2S;
    hSpi2slaver.Init.Direction     = SPI_DIRECTION_2LINES;
    hSpi2slaver.Init.DataSize      = SPI_DATASIZE_8BIT;
    hSpi2slaver.Init.ClockPolarity = SPI_POLARITY_LOW;
    hSpi2slaver.Init.ClockPhase    = SPI_PHASE_2EDGE;
    hSpi2slaver.Init.BaudRate      = 64;
    hSpi2slaver.Init.Standard      = SPI_FRF_MOTO;
    hSpi2slaver.Init.ControlSize   = SPI_CTRLSIZE_1BIT;
    hSpi2slaver.Init.NumberDataFrame = 1;
    hSpi2slaver.Init.TxFIFOTLvl = SPI_TXFIFO_THRESHOLD_QF;
    hSpi2slaver.Init.RxFIFOTLvl = SPI_RXFIFO_THRESHOLD_HF;
  
    if (HAL_SPI_Init(&hSpi2slaver) != HAL_OK)
    {
      /* Error_Handle */
    }
  
}
/**
  * @}
  */

/** @addtogroup SPI_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  */
void XT_Spi_Init(void)
{
    XT_SPI1M_Init();
    XT_SPI2S_Init();
}

/**
  * @brief  This function is executed.
  */
void XT_Spi_Task(void)
{
    /* USER CODE */
  	/*test spi1 as master transfer comunication*/	
  	if(HAL_SPI_Transmit_IT(&hSpi1master, (uint8_t *)aSpi1TxBuffer, sizeof(aSpi1TxBuffer)-1)!=HAL_OK)
  	{
  	    Error_Handle();
  	}
    while (HAL_SPI_GetState(&hSpi1master) != HAL_SPI_STATE_READY);
    while(u1Spi_cbState!=CB_SPI1_TXFNSH);	
    u1Spi_cbState = CB_SPI_IDLE;
  		
    if(HAL_SPI_Receive_IT(&hSpi1master, (uint8_t *)aRxBuffer, sizeof(aSpi1TxBuffer)-1)!=HAL_OK)
    {
        Error_Handle();
    }
    while (HAL_SPI_GetState(&hSpi1master) != HAL_SPI_STATE_READY);	
    while(u1Spi_cbState!=CB_SPI1_RXFNSH);	
    u1Spi_cbState = CB_SPI_IDLE;
  	
    if(HAL_SPI_TransmitReceive_IT(&hSpi1master, (uint8_t *)aSpi1TxBuffer, (uint8_t *)aRxBuffer, sizeof(aSpi1TxBuffer)-1)!=HAL_OK)
    {
        Error_Handle();
    }
    while(u1Spi_cbState!=CB_SPI1_TXRXFNSH);
    u1Spi_cbState = CB_SPI_IDLE;
  		
    /*test spi2 as slaver transfer comunication*/	
  	if(HAL_SPI_Transmit_IT(&hSpi2slaver, (uint8_t *)aSpi2TxBuffer, sizeof(aSpi2TxBuffer))!=HAL_OK)
    {
        Error_Handle();
    }
    while (HAL_SPI_GetState(&hSpi2slaver) != HAL_SPI_STATE_READY);
    while(u1Spi_cbState!=CB_SPI2_TXFNSH);	
    u1Spi_cbState = CB_SPI_IDLE;
    	
    if(HAL_SPI_Receive_IT(&hSpi2slaver, (uint8_t *)aRxBuffer, sizeof(aSpi2TxBuffer)-1)!=HAL_OK)
    {
        Error_Handle();
    }
  	while (HAL_SPI_GetState(&hSpi2slaver) != HAL_SPI_STATE_READY);
    while(u1Spi_cbState!=CB_SPI2_RXFNSH);
    u1Spi_cbState = CB_SPI_IDLE;
  
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi->Instance== SPI1M)
        u1Spi_cbState = CB_SPI1_TXFNSH;	
    else if(hspi->Instance== SPI2S)
        u1Spi_cbState = CB_SPI2_TXFNSH;
    return;
}

void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi->Instance== SPI1M)
        u1Spi_cbState = CB_SPI1_RXFNSH;	
    else if(hspi->Instance== SPI2S)
        u1Spi_cbState = CB_SPI2_RXFNSH;
    return;
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{	
    if(hspi->Instance== SPI1M)
        u1Spi_cbState = CB_SPI1_TXRXFNSH;	
    else if(hspi->Instance== SPI2S)
        u1Spi_cbState = CB_SPI2_TXRXFNSH;
    return;
}
                                                                                                  
void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi)
{
    u1Spi_cbState = CB_SPI_ABORT;
}
/**
  * @brief  SPI error callback.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval None
  */
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
    u1Spi_cbState = CB_SPI_ERROR;
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
