/**
  ******************************************************************************
  * @file    gpiotask.c
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
#include "gpiotask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup GPIO_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/** @addtogroup GPIO_Task_Private_Variables
  * @{
  */
/* Private variables ---------------------------------------------------------*/
/**
  * @}
  */

/** @addtogroup GPIO_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/



/* Private user code ---------------------------------------------------------*/

/**
 * @brief GPIO Initialization Function
 *
 * Configure PAD 59 and pad 60 to GPIO output as LED 
 * this example only use for LED testing purpose
 */
void XT_Gpio_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct = {0};
    PADI_InitTypeDef sPadConfig = {0};
    /* -1- PAD option: Configure pin alternate function as GPIO */
    sPadConfig.Pad       = EVB_GPIO_INPUT_KEY_IO_IDX; //KEY1: SW3101
    sPadConfig.Alternate = EVB_GPIO_INPUT_KEY_IO_CFG;
    sPadConfig.Pull      = PADI_PULLUP;
    sPadConfig.DriveStrength = PADI_DS_HIGH;
    HAL_PADI_Init(PADI, &sPadConfig);
    
    sPadConfig.Pad       = EVB_GPIO_INPUT_KEY2_IO_IDX; //KEY2: SW3102
    sPadConfig.Alternate = EVB_GPIO_INPUT_KEY2_IO_CFG;
    sPadConfig.Pull = PADI_PULLUP;
    HAL_PADI_Init(PADI, &sPadConfig);
    sPadConfig.Pad       = EVB_GPIO_OUTPUT_LED_IO_IDX;  //LED1: C_BLUE
    sPadConfig.Alternate = EVB_GPIO_OUTPUT_LED_IO_CFG;
    sPadConfig.Pull = PADI_PULLDOWN;
    HAL_PADI_Init(PADI, &sPadConfig);
    
    sPadConfig.Pad       = EVB_GPIO_OUTPUT_LED2_IO_IDX;  //LED2: C_GRN
    sPadConfig.Alternate = EVB_GPIO_OUTPUT_LED2_IO_CFG;
    sPadConfig.Pull = PADI_PULLDOWN;
    HAL_PADI_Init(PADI, &sPadConfig);
    /* -2- Configure IO in output push-pull mode to drive external led */
    GPIO_InitStruct.Pin    = EVB_GPIO_LED1_IO_PIN |EVB_GPIO_LED2_IO_PIN;  ////LED: C_BLUE, LED2: C_GRN
    GPIO_InitStruct.Mode   = GPIO_MODE_OUTPUT_SW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    
    /* -3- Configure IO in input pull-down mode to detect external button */
    GPIO_InitStruct.Pin    = EVB_GPIO_INPUT_KEY_IO_PIN; //KEY1: SW3101
    GPIO_InitStruct.Mode   = GPIO_MODE_INPUT_SW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);  
    /* -4- Configure IO in input pull-down mode and enable interrupt mode to detect external button */
    GPIO_InitStruct.Pin    = EVB_GPIO_INPUT_KEY2_IO_PIN; //KEY2: SW3102
    GPIO_InitStruct.Mode   = GPIO_MODE_INPUT_SW;   // config key2 interrupt
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
    
    XT_EVB_Led_On(LED_BLUE); //LED1: C_BLUE off
    XT_EVB_Led_On(LED_GREEN); //LED1: C_BLUE off
    return;
}

/**
  * @}
  */

/** @addtogroup GPIO_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  */
void XT_Gpio_Task(void)
{
  /* USER CODE */
}

/**
 * @brief GPIO SET Function,Pin set, LED on
 * @param ledid LED ID
 */
void XT_EVB_Led_On(uint8_t ledid)
{
    switch(ledid){
        case LED1:
            HAL_GPIO_WritePin(EVB_GPIO_LED1_IO_PORT, EVB_GPIO_LED1_IO_PIN,GPIO_PIN_SET);
            break;
        case LED2:
            HAL_GPIO_WritePin(EVB_GPIO_LED2_IO_PORT, EVB_GPIO_LED2_IO_PIN,GPIO_PIN_SET);
            break;
        default:
            break;
    }
    return;	
}
	
/**
 * @brief GPIO SET Function,Pin set, LED off
 * @param ledid LED ID
 */
void XT_EVB_Led_Off(uint8_t ledid)
{
    switch(ledid){
        case LED1:
            HAL_GPIO_WritePin(EVB_GPIO_LED1_IO_PORT, EVB_GPIO_LED1_IO_PIN,GPIO_PIN_RESET);
            break;
        case LED2:
            HAL_GPIO_WritePin(EVB_GPIO_LED2_IO_PORT, EVB_GPIO_LED2_IO_PIN,GPIO_PIN_RESET);
            break;
        default:
            break;
    }		
    return;
}
	
/**
 * @brief GPIO SET Function,Pin set toggle
 */
void XT_EVB_Led_Toggle(uint8_t ledid)
{
    switch(ledid){
        case LED1:
            HAL_GPIO_TogglePin(EVB_GPIO_LED1_IO_PORT, EVB_GPIO_LED1_IO_PIN);
            break;
        case LED2:
            HAL_GPIO_TogglePin(EVB_GPIO_LED2_IO_PORT, EVB_GPIO_LED2_IO_PIN);
            break;
        default:
            break;	
    }
    return;
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
