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

/** @addtogroup App_Gpio
 * @{
 */

/** @addtogroup Gpio_Blink
 * @{
 */

/* Private variables ---------------------------------------------------------*/
/** @addtogroup App_Private_Variables App Private Variables
 * @{
 */
static uint8_t button_trigged_flag = FALSE;
static uint8_t key1_status = SET;
static uint8_t key2_status = SET;
/**
 * @}
 */
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup App_Private_Functions 
 * @{
 */
static void Gpio_Led_On(uint8_t ledid);
static void Gpio_Led_Off(uint8_t ledid);
static void Gpio_Led_Toggle(uint8_t ledid);
static uint8_t Get_Button1_State(void);
static uint8_t Get_Button2_State(void);
/**
 * @}
 */

/** @addtogroup App_Exported_Functions
  * @{
  */

/**
 * @brief GPIO Initialization Function
 *
 * Configure IO 59 and pad 60 to GPIO output as LED 
 * this example only use for LED testing purpose
 */
void XT_Gpio_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct = {0};
    PADI_InitTypeDef sPadConfig = {0};
    /* -1- IO option: Configure pin alternate function as GPIO */
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
    GPIO_InitStruct.Mode   = GPIO_MODE_IT_PL_SE_DE_SN;   // config key2 interrupt
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct); 
    
    Gpio_Led_On(LED_BLUE); //LED1: C_BLUE off
    Gpio_Led_On(LED_GREEN); //LED1: C_BLUE off
    return;
}



/**
 * @brief SDK API: GPIO Test case - verify HAL_GPIO_*_ Function
 */
void XT_Gpio_Task(void)
{
    uint8_t button_sta = 0;
    /*read the Key status*/
    button_sta = Get_Button1_State();
    if(button_sta==PRESSED)	{/*Key pressed*/	
        /*LED on*/
        Gpio_Led_On(LED_BLUE);
        HAL_Delay(200);  
        Gpio_Led_Toggle(LED_BLUE);
        HAL_Delay(200);  
        Gpio_Led_Toggle(LED_BLUE);
        HAL_Delay(200); 
    }
    else if(button_sta==RELEASED){
        /*LED on*/
        Gpio_Led_Off(LED_BLUE);
    }
    	
    if(button_trigged_flag)
    {
        button_trigged_flag =0;	
        Gpio_Led_On(LED_GREEN);	
        HAL_Delay(200); 		
        Gpio_Led_Toggle(LED_GREEN);
        HAL_Delay(200);  
        Gpio_Led_Toggle(LED_GREEN);
        HAL_Delay(200); 
        Gpio_Led_Toggle(LED_GREEN);
        HAL_Delay(200); 
        Gpio_Led_Toggle(LED_GREEN);
        HAL_Delay(200); 
    }
}

/* Private user code ---------------------------------------------------------*/
/**
 * @brief ICTL line detection callbacks
 * @param GPIO_Pin Specifies the pins connected ICTL line
 */
void HAL_GPIO_Callback(uint32_t GPIO_Pin)
{
    __HAL_GPIO_CLEAR_IT(GPIO_Pin);
    button_trigged_flag = TRUE;
}
/**
 * @}
 */


/** @addtogroup App_Private_Functions
 *  @{
 */
/**
 * @brief GPIO SET Function,Pin set, LED on
 * @param ledid LED ID
 */
static void Gpio_Led_On(uint8_t ledid)
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
static void Gpio_Led_Off(uint8_t ledid)
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
static void Gpio_Led_Toggle(uint8_t ledid)
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
 * @brief GPIO read Function, read gpio value
 * @retval State (SET or RESET)
 */
static uint8_t Get_Button1_State(void)
{
	uint8_t  temp_status  = HAL_GPIO_ReadPin(EVB_GPIO_INPUT_KEY_IO_PORT,EVB_GPIO_INPUT_KEY_IO_PIN);
	
	if(key1_status == temp_status)
		return FALSE;
	else
		key1_status = temp_status;
	
	if(key1_status == RESET){
		return PRESSED;
	}else
		return RELEASED;
}



/**
 * @brief GPIO read Function, read gpio value
 * @retval State (SET or RESET)
 */
static uint8_t Get_Button2_State(void)
{
	uint8_t  temp_status  = HAL_GPIO_ReadPin(EVB_GPIO_INPUT_KEY2_IO_PORT,EVB_GPIO_INPUT_KEY2_IO_PIN);
	
 if(key2_status == temp_status)
		return FALSE;
	else
		key2_status = temp_status;
	
	if(key2_status == RESET)
	{
		return PRESSED;
	}else
		return RELEASED;
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