/**
  ******************************************************************************
  * @file    xt32h0xx_hal_msp.c
  * @author  Software Team
  * @brief   This file provides code for the MSP Initialization 
  *          and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spitask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup MSP
  * @{
  */
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/* External variables --------------------------------------------------------*/
/** @addtogroup IT_External_Variables
  * @{
  */
extern DMA_HandleTypeDef hDmaSpi1tx;
extern DMA_HandleTypeDef hDmaSpi1rx;
extern DMA_HandleTypeDef hDmaSpi2tx;
extern DMA_HandleTypeDef hDmaSpi2rx;

/**
  * @}
  */
	
/* External functions --------------------------------------------------------*/
/** @addtogroup MSP_Exported_Functions
  * @{
  */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
}

/**
* @brief SPI1 MSP Initialization
* @param hspi: SPI handle pointer
* @retval None
*/
void XT_SPI1_MspInit(SPI_HandleTypeDef* hspi)
{
    if((hspi->Instance== SPI1M)|| (hspi->Instance== SPI1S))
    {
        /**mapping  SPI1 IO Configuration ***
        IO22 ------> SPI1_CS                       
        IO25 ------> SPI1_SCK                      
        IO24 ------> SPI1_MISO (RXD)               	
        IO23 ------> SPI1_MOSI (TXD)			
        */ 		/* mapping IO alternation */
        XT_IO_Option_Assigned(EVB_SPI1_CS_IO_IDX,	  EVB_SPI1_CS_IO_CFG, PADI_PULLDOWN);
        XT_IO_Option_Assigned(EVB_SPI1_TXD_IO_IDX,	EVB_SPI1_TXD_IO_CFG,PADI_PULLUP);
        XT_IO_Option_Assigned(EVB_SPI1_RXD_IO_IDX,	EVB_SPI1_RXD_IO_CFG,PADI_PULLUP);
        XT_IO_Option_Assigned(EVB_SPI1_CLK_IO_IDX,	EVB_SPI1_CLK_IO_CFG,PADI_PULLDOWN);	
		   
        //DMA ModeDMA Handshaking Interface:INDEX 8 and INDEX 9 of CFG1 SPI1 TX RX cfg1 for SPI1M or SPI1S 
        HAL_SPI_DMAHSIFConfig(hspi,  &hDmaSpi1rx, &hDmaSpi1tx, SPI1_RXD_DMAHSIF_IDX, SPI1_TXD_DMAHSIF_IDX, 
                                                               SPI1_RXD_DMAHSIF_CFG, SPI1_TXD_DMAHSIF_CFG);  //option 2
        HAL_SPI_LinkDMA(hspi, &hDmaSpi1rx, &hDmaSpi1tx);		
    }

}

/**
  * @brief  De-Initialize the SPI1 MSP.
  * @retval None
  */
void XT_SPI1_MspDeInit(SPI_HandleTypeDef* hspi)
{
    if((hspi->Instance== SPI1M)||(hspi->Instance== SPI1S))
    {
        HAL_PADI_DeInit(PADI,EVB_SPI1_CS_IO_IDX  );
        HAL_PADI_DeInit(PADI,EVB_SPI1_TXD_IO_IDX );	
        HAL_PADI_DeInit(PADI,EVB_SPI1_RXD_IO_IDX );
        HAL_PADI_DeInit(PADI,EVB_SPI1_CLK_IO_IDX);	
    }
}

/**
* @brief SPI2 MSP Initialization
* @param hspi: SPI handle pointer
* @retval None
*/
void XT_SPI2_MspInit(SPI_HandleTypeDef* hspi)
{
    if((hspi->Instance== SPI2M)|| (hspi->Instance== SPI2S))
    {
        /**mapping SPI2 IO Configuration ***                                                                                   
        // IO10    ------> SPI2_CS
        // IO13    ------> SPI2_SCK
        // IO14    ------> SPI2_MISO (TXD)	
        // IO15    ------> SPI2_MOSI (RXD) 
        *//* mapping IO */
        XT_IO_Option_Assigned(EVB_SPI2_CS_IO_IDX,	  EVB_SPI2_CS_IO_CFG, PADI_PULLDOWN);
        XT_IO_Option_Assigned(EVB_SPI2_TXD_IO_IDX,	EVB_SPI2_TXD_IO_CFG,PADI_PULLUP);
        XT_IO_Option_Assigned(EVB_SPI2_RXD_IO_IDX,	EVB_SPI2_RXD_IO_CFG,PADI_PULLUP);
        XT_IO_Option_Assigned(EVB_SPI2_CLK_IO_IDX,	EVB_SPI2_CLK_IO_CFG,PADI_PULLDOWN);	
		   
        /*//DMA ModeDMA Handshaking Interface:INDEX 10 and INDEX 11 of CFG0 SPI2 TX RX cfg0 for SPI1M or SPI1S */
        HAL_SPI_DMAHSIFConfig(hspi, &hDmaSpi2rx, &hDmaSpi2tx, SPI2_RXD_DMAHSIF_IDX, SPI2_TXD_DMAHSIF_IDX,  
                                                              SPI2_RXD_DMAHSIF_CFG, SPI2_TXD_DMAHSIF_CFG);  //option 2
        HAL_SPI_LinkDMA(hspi, &hDmaSpi2rx, &hDmaSpi2tx);		
    }

}

/**
  * @brief  De-Initialize the SPI2 MSP.
  * @retval None
  */
void XT_SPI2_MspDeInit(SPI_HandleTypeDef* hspi)
{
    if((hspi->Instance== SPI2M)||(hspi->Instance== SPI2S))
    {
        HAL_PADI_DeInit(PADI,EVB_SPI2_CS_IO_IDX  );
        HAL_PADI_DeInit(PADI,EVB_SPI2_TXD_IO_IDX );	
        HAL_PADI_DeInit(PADI,EVB_SPI2_RXD_IO_IDX );
        HAL_PADI_DeInit(PADI,EVB_SPI2_CLK_IO_IDX);	
    }  
}
 
/**
* @brief SPI MSP Initialization
* This function configures the hardware resources used in this example
* @param hspi: SPI handle pointer
* @retval None
*/
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
 
    XT_SPI1_MspInit(hspi);
    XT_SPI2_MspInit(hspi);	
}

/**
  * @brief  De-Initialize the SPI MSP.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval None
  */
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi)
{
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE()
    XT_SPI1_MspDeInit(hspi);
    XT_SPI2_MspDeInit(hspi);
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
