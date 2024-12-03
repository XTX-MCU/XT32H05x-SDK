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
#ifdef SUPPORT_DBG 
#include "stdarg.h"
#include "stdio.h"
#endif

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup UART_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @addtogroup UART_Task_Private_Variables
  * @{
  */
UART_HandleTypeDef huart1;

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup UART_Task_Private_Functions
  * @{
  */
static void XT_UART1_Init(void );


/* Private user code ---------------------------------------------------------*/

/**
 * @brief  UART1 Initialization Function
 */
static void XT_UART1_Init(void)
{
  huart1.Instance        = UART1;
  huart1.Init.BaudRate   = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8;
  huart1.Init.StopBits   = UART_STOPBITS_1;
  huart1.Init.Parity     = UART_PARITY_NONE;
  huart1.Init.HwFlowCtl  = UART_HWCONTROL_NONE;

  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    /* Error_Handler */
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
}

#if defined(SUPPORT_DBG)
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
        //u32ErrSt = HAL_UART_GetError(&uart_huart);    
    }
}

#else
void DBG_printf(const char * buff, ...)
{
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
