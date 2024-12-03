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
//#define  SUPPORT_DBGPRINTF                            (1)
#ifdef SUPPORT_DBGPRINTF 
#include "stdarg.h"
#include "stdio.h"
#endif

/* Private variables ---------------------------------------------------------*/
/** @addtogroup UART_Task_Private_Variables
  * @{
  */
UART_HandleTypeDef huart1;

static uint8_t aTxBuffer[]    ="**xt32h0xx app test, uart transmit polling@2023**\n";/* Buffer used for transmission */
static uint8_t aRxBuffer[255] ={0};  /* Buffer used for reception */
static uint16_t received_count   = 0;

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
  if (HAL_UART_DisableFifoMode(&huart1) != HAL_OK)
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
    if (HAL_UART_Transmit(&huart1, (uint8_t *)aTxBuffer, sizeof(aTxBuffer), 5000) != HAL_OK)
    {
      if(HAL_UART_GetError(&huart1)!=HAL_UART_ERROR_NONE)
        Error_Handle();        
    } 
    
    /*receive data from slave device */
    if (HAL_UART_Receive(&huart1, (uint8_t *)aRxBuffer, sizeof(aTxBuffer)-2, 5000) != HAL_OK)
    {
      if(HAL_UART_GetError(&huart1)!=HAL_UART_ERROR_NONE)
        Error_Handle();
    } 

    /*receive data until the bus idle state*/
//    if (HAL_UART_ReceiveToIdle(&uart_huart, (uint8_t *)aRxBuffer, sizeof(aTxBuffer), &received_count,0x1000) != HAL_OK)
//    {
//      if(HAL_UART_GetError(&uart_huart)!=HAL_UART_ERROR_NONE)
//      Error_Handler();
//    }    
    if(Buffercmp(aRxBuffer,aTxBuffer,(sizeof(aTxBuffer))-2)==0){	
      XT_EVB_Led_Toggle(LED_GREEN);			
    }else
      XT_EVB_Led_Off(LED_GREEN);
  }
}

#if defined(SUPPORT_DBGPRINTF)
/**
  * @brief  UART Transmit data to PC-RS232 for testing purpose.
  * @retval None
  */
void DBG_printf(const char * buff, ...)
{
  va_list args;
  char txbuff[255] ={'\0'};
  uint16_t total_len = 0;
  
  /*only for test purpose, the stdarg lib costs 4k memory*/
  va_start(args, buff);     
  total_len = vsprintf(txbuff, buff, args);
  va_end(args);
  
  //total_len +=1 ;
  if (HAL_UART_Transmit(&huart1, (uint8_t *)txbuff, total_len, 1000) != HAL_OK)
  {
  	//u32ErrSt = HAL_UART_GetError(&huart1);    
  }
}
#endif
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
