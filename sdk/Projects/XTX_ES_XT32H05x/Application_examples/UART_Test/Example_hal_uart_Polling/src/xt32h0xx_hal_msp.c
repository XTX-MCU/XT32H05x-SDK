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
#include "uarttask.h"

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
/** @addtogroup MSP_External_Variables
  * @{
  */
extern UART_HandleTypeDef huart1;

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
* @brief UART1 MSP Initialization
* @param huart: uart handle pointer
* @retval None
*/
void XT_UART1_MspInit(UART_HandleTypeDef* huart)
{
    PADI_InitTypeDef sPadConfig = {0};
    sPadConfig.Pull = PADI_PULLDOWN;
    if(huart->Instance == UART1)
    {
        sPadConfig.Pad       = PADI_IDX_IO5_UART1_RX ;
        sPadConfig.Alternate = PADI_CFG_IO5_UART1_RX ;
        HAL_PADI_Init(PADI, &sPadConfig);  /* Rx IO */
        sPadConfig.Pad       = PADI_IDX_IO1_UART1_TX ;
        sPadConfig.Alternate = PADI_CFG_IO1_UART1_TX ;
        HAL_PADI_Init(PADI, &sPadConfig);  /* Tx IO */
         
    }
}

/**
* @brief UART1 MSP De-Initialization
* @param huart: UART handle pointer
* @retval None
*/
void XT_UART1_MspDeInit(UART_HandleTypeDef* huart)
{
    PADI_InitTypeDef sPadConfig = {0};
    sPadConfig.Pull = PADI_PULLNO;
    /**mapping  UART IO Configuration ***
       IO1     ------> UART0 TX
       IO5     ------> UART0 RX
    */
    if(huart->Instance == UART1)
    {
        HAL_PADI_DeInit(PADI,PADI_IDX_IO1_UART1_TX);
        HAL_PADI_DeInit(PADI,PADI_IDX_IO5_UART1_RX);    
        /* USART1 interrupt DeInit */
        HAL_NVIC_DisableIRQ(UART1_IRQn);  
    }
}

/**
* @brief UART2 MSP Initialization
* @param huart: uart handle pointer
* @retval None
*/
void XT_UART2_MspInit(UART_HandleTypeDef* huart)
{
    /**mapping  UART IO Configuration ***
    IO13/18/39     ------> UART2 TX
    IO14/19/38     ------> UART2 RX
    */
    if(huart->Instance == UART2)
    {
        #if (EVB_UART2_PINCONFIG_GRP== 0x2A)
        XT_IO_Option_Assigned(PADI_IDX_IO13_UART2_TX, PADI_CFG_IO13_UART2_TX, PADI_PULLDOWN);
        XT_IO_Option_Assigned(PADI_IDX_IO14_UART2_RX, PADI_CFG_IO14_UART2_RX, PADI_PULLDOWN);
        #elif (EVB_UART2_PINCONFIG_GRP==0x2B)
        XT_IO_Option_Assigned(PADI_IDX_IO18_UART2_TX, PADI_CFG_IO18_UART2_TX, PADI_PULLDOWN);
        XT_IO_Option_Assigned(PADI_IDX_IO19_UART2_RX, PADI_CFG_IO19_UART2_RX, PADI_PULLDOWN);
        #elif  (EVB_UART2_PINCONFIG_GRP==0x2C)
        XT_IO_Option_Assigned(PADI_IDX_IO39_UART2_TX, PADI_CFG_IO39_UART2_TX, PADI_PULLDOWN);
        XT_IO_Option_Assigned(PADI_IDX_IO38_UART2_RX, PADI_CFG_IO38_UART2_RX, PADI_PULLDOWN);
        #endif
        
    }
}


/**
* @brief UART2 MSP De-Initialization
* @param huart: UART handle pointer
* @retval None
*/
void XT_UART2_MspDeInit(UART_HandleTypeDef* huart)
{
    if(huart->Instance == UART2)
    {
         #if (EVB_UART2_PINCONFIG_GRP==0x2A)
         HAL_PADI_DeInit(PADI,PADI_IDX_IO13_UART2_TX);
         HAL_PADI_DeInit(PADI,PADI_IDX_IO14_UART2_RX);
         #elif (EVB_UART2_PINCONFIG_GRP==0x2B)
         HAL_PADI_DeInit(PADI,PADI_IDX_IO18_UART2_TX);
         HAL_PADI_DeInit(PADI,PADI_IDX_IO19_UART2_RX);
         #elif  (EVB_UART2_PINCONFIG_GRP==0x2C)
         HAL_PADI_DeInit(PADI,PADI_IDX_IO39_UART2_TX);
         HAL_PADI_DeInit(PADI,PADI_IDX_IO38_UART2_RX);
         #endif 
         HAL_NVIC_DisableIRQ(UART2_IRQn);
    }
}

/**
* @brief UART3 MSP Initialization
* @param huart: uart handle pointer
* @retval None
*/
void XT_UART3_MspInit(UART_HandleTypeDef* huart)
{
    /**mapping UART IO Configuration ***
      IO35/40     ------> UART3 TX
      IO36/41     ------> UART3 RX    
    */ 
    if(huart->Instance == UART3)
    {
        #if (EVB_UART3_PINCONFIG_GRP == 0x3A)
        XT_IO_Option_Assigned(PADI_IDX_IO35_UART3_TX, PADI_CFG_IO35_UART3_TX, PADI_PULLDOWN);
        XT_IO_Option_Assigned(PADI_IDX_IO36_UART3_RX, PADI_CFG_IO36_UART3_RX, PADI_PULLDOWN);
        #elif (EVB_UART3_PINCONFIG_GRP==0x3B)
        XT_IO_Option_Assigned(PADI_IDX_IO40_UART3_TX, PADI_CFG_IO40_UART3_TX, PADI_PULLDOWN);
        XT_IO_Option_Assigned(PADI_IDX_IO41_UART3_RX, PADI_CFG_IO41_UART3_RX, PADI_PULLDOWN);
        #endif
    }
}


/**
* @brief UART3 MSP De-Initialization
* @param huart: UART handle pointer
* @retval None
*/
void XT_UART3_MspDeInit(UART_HandleTypeDef* huart)
{
    if(huart->Instance == UART3)
    {
        #if (EVB_UART3_PINCONFIG_GRP == 0x3A)
        HAL_PADI_DeInit(PADI,PADI_IDX_IO35_UART3_TX);
        HAL_PADI_DeInit(PADI,PADI_IDX_IO36_UART3_RX);
        #elif (EVB_UART3_PINCONFIG_GRP==0x3B)
        HAL_PADI_DeInit(PADI,PADI_IDX_IO40_UART3_TX);
        HAL_PADI_DeInit(PADI,PADI_IDX_IO41_UART3_RX);
        #endif
        HAL_NVIC_DisableIRQ(UART3_IRQn);
    }
}


/**
* @brief UART4 MSP Initialization
* @param huart: uart handle pointer
* @retval None
*/
void XT_UART4_MspInit(UART_HandleTypeDef* huart)
{
    
    if(huart->Instance == UART4)
    {
        /**mapping  UART IO Configuration ***
        IO56/58     ------> UART3 TX
        IO55/57     ------> UART3 RX
        */    
        #if (EVB_UART4_PINCONFIG_GRP == 0x4A) 
        XT_IO_Option_Assigned(PADI_IDX_IO56_UART4_TX, PADI_CFG_IO56_UART4_TX, PADI_PULLDOWN);
        XT_IO_Option_Assigned(PADI_IDX_IO55_UART4_RX, PADI_CFG_IO55_UART4_RX, PADI_PULLDOWN);
        #elif (EVB_UART4_PINCONFIG_GRP == 0x4B) 
        XT_IO_Option_Assigned(PADI_IDX_IO58_UART4_TX, PADI_CFG_IO58_UART4_TX, PADI_PULLDOWN);
        XT_IO_Option_Assigned(PADI_IDX_IO57_UART4_RX, PADI_CFG_IO57_UART4_RX, PADI_PULLDOWN);
        #endif
    }
}

/**
* @brief UART4 MSP De-Initialization
* @param huart: UART handle pointer
* @retval None
*/
void XT_UART4_MspDeInit(UART_HandleTypeDef* huart)
{
    if(huart->Instance == UART4)
    {
        #if (EVB_UART4_PINCONFIG_GRP==0x4A)
        HAL_PADI_DeInit(PADI,PADI_IDX_IO56_UART4_TX);
        HAL_PADI_DeInit(PADI,PADI_IDX_IO55_UART4_RX);
        #elif (EVB_UART4_PINCONFIG_GRP==0x4B)
        HAL_PADI_DeInit(PADI,PADI_IDX_IO58_UART4_TX);
        HAL_PADI_DeInit(PADI,PADI_IDX_IO57_UART4_RX);
        #endif
        HAL_NVIC_DisableIRQ(UART4_IRQn);
    }
}


/**
* @brief UART MSP Initialization
* This function configures the hardware resources used in this example
* @param huart: uart handle pointer
* @retval None
*/
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{    
    /* -1- Enable source Clock:  UART Baudrate source clock in function: SystemClock_Config*/

	  /* -2- IO option: Configure pin alternate function as UART  */
    XT_UART1_MspInit(huart);
    XT_UART2_MspInit(huart);
    XT_UART3_MspInit(huart);
    XT_UART4_MspInit(huart);
}

/**
* @brief UART MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param huart: UART handle pointer
* @retval None
*/
void HAL_UART_MspDeInit(UART_HandleTypeDef* huart)
{
    XT_UART1_MspDeInit(huart);
    XT_UART2_MspDeInit(huart);
    XT_UART3_MspDeInit(huart);
    XT_UART4_MspDeInit(huart);
	
  /* Peripheral clock disable */
    __HAL_RCC_BR_CLK_DISABLE();
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
