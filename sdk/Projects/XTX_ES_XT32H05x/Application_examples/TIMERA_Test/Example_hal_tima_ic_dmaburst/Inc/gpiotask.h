/**
  ******************************************************************************
  * @file    gpiotask.h
  * @author  Software Team
  * @brief   Header for gpiotask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIOTASK_H
#define __GPIOTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup GPIO_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
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

/* Exported macro ------------------------------------------------------------*/

/** @addtogroup GPIO_Task_Exported_Functions
  * @{
  */
/* Exported functions prototypes ---------------------------------------------*/
extern void XT_Gpio_Init(void );
extern void XT_Gpio_Task(void );
extern void XT_EVB_Led_On(uint8_t ledid);
extern void XT_EVB_Led_Off(uint8_t ledid);
extern void XT_EVB_Led_Toggle(uint8_t ledid);
extern uint8_t XT_EVB_Button1_State_Get(void);
extern uint8_t XT_EVB_Button2_State_Get(void);

/**
  * @}
  */

/* Private defines -----------------------------------------------------------*/
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __GPIOTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
