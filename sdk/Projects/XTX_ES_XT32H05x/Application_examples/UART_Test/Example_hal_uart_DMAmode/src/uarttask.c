/**
  ******************************************************************************
  * @file    uarttask.c
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
#include "uarttask.h"
#include "gpiotask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup UART_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/
/** @addtogroup UART_Task_Private_Variables
  * @{
  */
UART_HandleTypeDef huart1;

static uint8_t aTxBuffer[]    ="**xt32h0xx app test, uart transmit DMA@2023**\n";/* Buffer used for transmission */
static uint8_t aRxBuffer[255] ={0};  /* Buffer used for reception */
static uint8_t uTxFinished = FALSE;
static uint8_t uRxFinished = FALSE;

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup UART_Task_Private_Functions
  * @{
  */
static void XT_UART1_Init(void );
static void XT_UART4_Init(void );

/* Private user code ---------------------------------------------------------*/

/**
 * @brief  UART1 Initialization Function
 */
static void XT_UART1_Init(void)
{
    huart1.Instance = UART1;
    huart1.Init.BaudRate = 9600;
    huart1.Init.WordLength = UART_WORDLENGTH_8;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    
    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
    if (HAL_UART_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_4) != HAL_OK)
    {
      /* Error_Handler */
    }
    if (HAL_UART_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_4) != HAL_OK)
    {
      /* Error_Handler */
    }
    if (HAL_UART_EnableFifoMode(&huart1) != HAL_OK)
    {
        /* Error_Handler */
        Error_Handle();
    }
    
}


/**
  * @}
  */

/** @addtogroup UART_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  */
void XT_Uart_Init(void)
{
    XT_UART1_Init( );
}

/**
  * @brief  This function is executed.
  */
void XT_Uart_Task(void)
{
    /* USER CODE */
    if(XT_EVB_Button1_State_Get()==PRESSED)
    {
        if (HAL_UART_Transmit_DMA(&huart1, (uint8_t *)aTxBuffer, sizeof(aTxBuffer)) != HAL_OK)
        {
            if(HAL_UART_GetError(&huart1)!=HAL_UART_ERROR_NONE)
              Error_Handle();        
        } 
        while(!uTxFinished)
        {	      
        } 
        uTxFinished = FALSE;
        /*receive data from slave device */
        if (HAL_UART_Receive_DMA(&huart1, (uint8_t *)aRxBuffer, sizeof(aTxBuffer)-2) != HAL_OK)
        {
            if(HAL_UART_GetError(&huart1)!=HAL_UART_ERROR_NONE)
              Error_Handle();
        } 
        while(!uRxFinished)
        {	      
        }   
        uRxFinished = FALSE;
        /*receive data until the bus idle state*/
        
        if(Buffercmp(aRxBuffer,aTxBuffer,(sizeof(aTxBuffer))-2)==0){	
            XT_EVB_Led_Toggle(LED_GREEN);			
        }else
            XT_EVB_Led_Off(LED_GREEN);
    }
}

/**
  * @brief  Tx Transfer completed callback
  * @param  UartHandle: UART handle.
  * @note   This example shows a simple way to report end of IT Tx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    /* Set transmission flag: transfer complete */
    uTxFinished = TRUE;	 
}

/**
  * @brief  Rx Transfer completed callback
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report end of DMA Rx transfer, and
  *         you can add your own implementation.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    /* Set transmission flag: transfer complete */
    uRxFinished = TRUE;
}

/**
  * @brief  UART error callbacks
  * @param  UartHandle: UART handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    uRxFinished = TRUE;
    uTxFinished = TRUE;		
}

/**
  * @brief  Reception Event Callback (Rx event notification called after use of advanced reception service).
  * @param  huart UART handle
  * @param  Size  Number of data available in application reception buffer (indicates a position in
  *               reception buffer until which, data are available)
  * @retval None
  */
void HAL_UART_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
		uRxFinished = TRUE; 
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
