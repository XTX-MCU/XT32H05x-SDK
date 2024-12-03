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
#include "timeratask.h"
 

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
* @brief TIM_PWM MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_pwm: TIM_PWM handle pointer
* @retval None
*/
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef* htim_pwm)
{
  
    if(htim_pwm->Instance==TIM2)
    {
        /* Peripheral clock enable */
        __HAL_RCC_TIMA_CLK_ENABLE();
        /* USER CODE BEGIN TIM1_MspInit 1 */		
        /* Configure output pin */   
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_1,   TIM2_CH1P_OUT_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_1,   TIM2_CH1N_OUT_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_2,   TIM2_CH2P_OUT_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_2,   TIM2_CH2N_OUT_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_3,   TIM2_CH3P_OUT_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_3,   TIM2_CH3N_OUT_PIN_IDX);
    }	
}


void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef* htim)
{
   

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
