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

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup MSP
  * @{
  */
/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

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
* @brief UART MSP Initialization
* This function configures the hardware resources used in this example
* @param huart: uart handle pointer
*/
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{ 
    PADI_InitTypeDef sPadConfig = {0};
    sPadConfig.Pull = PADI_PULLDOWN;
    if(huart->Instance == UART1)
    {
        sPadConfig.Pad       = PADI_IDX_IO5_UART1_RX ;
        sPadConfig.Alternate = PADI_CFG_IO5_UART1_RX ;
        HAL_PADI_Init(PADI, &sPadConfig);  /* Rx pad */
        sPadConfig.Pad       = PADI_IDX_IO1_UART1_TX ;
        sPadConfig.Alternate = PADI_CFG_IO1_UART1_TX ;
        HAL_PADI_Init(PADI, &sPadConfig);  /* Tx pad */
    }
}	

/**
* @brief UART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param huart: UART handle pointer
*/
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
    if(huart->Instance == UART1)
    {
        HAL_PADI_DeInit(PADI,PADI_IDX_IO1_UART1_TX);
        HAL_PADI_DeInit(PADI,PADI_IDX_IO5_UART1_RX);   
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
