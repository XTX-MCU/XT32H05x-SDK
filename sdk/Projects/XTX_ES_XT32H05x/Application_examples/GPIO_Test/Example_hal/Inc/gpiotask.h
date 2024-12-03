/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    /Inc/gpiotask.h
  * @author  Software Team
  * @brief   Header for gpiotask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech .
  * All rights reserved.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H
#define __GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"	
/* Private includes ----------------------------------------------------------*/

/** @addtogroup App_Gpio
 * @{
 */

/** @addtogroup Gpio_Blink
 * @{
 */

/* Exported macro ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @addtogroup App_Exported_Constants
  * @{
  */
#define EVB_GPIO_INPUT_KEY_IO_IDX					PADI_IDX_IO19_PA10	       
#define EVB_GPIO_INPUT_KEY_IO_CFG					PADI_CFG_IO19_PA10
			
#define EVB_GPIO_INPUT_KEY2_IO_IDX				PADI_IDX_IO44_PA26	             
#define EVB_GPIO_INPUT_KEY2_IO_CFG				PADI_CFG_IO44_PA26	
			                                        
#define EVB_GPIO_OUTPUT_LED_IO_IDX				PADI_IDX_IO60_PA6   /*KEY_INPUT: PA6*/ 
#define EVB_GPIO_OUTPUT_LED_IO_CFG				PADI_CFG_IO60_PA6   /*KEY_INPUT: PA6*/ 

#define EVB_GPIO_OUTPUT_LED2_IO_IDX				PADI_IDX_IO59_PA7   /*KEY_INPUT: PA7*/ 
#define EVB_GPIO_OUTPUT_LED2_IO_CFG				PADI_CFG_IO59_PA7   /*KEY_INPUT: PA7*/ 

#define EVB_GPIO_INPUT_KEY_IO_PIN						GPIO_PIN_10	
#define EVB_GPIO_INPUT_KEY_IO_PORT					GPIOA			

#define EVB_GPIO_INPUT_KEY2_IO_PIN					GPIO_PIN_26           /*KEY_INPUT: PA10*/
#define EVB_GPIO_INPUT_KEY2_IO_PORT					GPIOA 

#define EVB_GPIO_LED1_IO_PIN								GPIO_PIN_6				
#define EVB_GPIO_LED1_IO_PORT								GPIOA				

#define EVB_GPIO_LED2_IO_PIN								GPIO_PIN_7				
#define EVB_GPIO_LED2_IO_PORT								GPIOA	
/**
  * @}
  */

/** @addtogroup App_Exported_Types
  * @{
  */
/**
  * @brief  LED Type Structure definition
  */
typedef enum  {
	LED1 = 0,
	LED_BLUE = LED1,
	LED2,
	LED_GREEN = LED2,
}LED_INDEX;

/**
  * @brief  button status Structure definition
  */
typedef enum  {
	Button_None = 0,
	PRESSED ,
	RELEASED,
}ButtonSta;
/**
  * @}
  */

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup App_Exported_Functions
  * @{
  */
extern void XT_Gpio_Init(void );
extern void XT_Gpio_Task(void );
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif /* __GPIO_H */
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
