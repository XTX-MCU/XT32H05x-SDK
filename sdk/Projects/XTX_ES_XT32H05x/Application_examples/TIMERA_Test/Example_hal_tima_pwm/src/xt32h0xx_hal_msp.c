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
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef* htim_pwm)
{
  
    if(htim_pwm->Instance==TIM1)
    {
        /* Peripheral clock enable */
        __HAL_RCC_TIMA_CLK_ENABLE();
        /* USER CODE BEGIN TIM1_MspInit 1 */		
        /* Configure output pin */
        /**
        * TIMA ch1o IO10 ch1on IO13; **ch2o IO14 ch2on IO15; **ch3o IO29 ch3on IO30 ;  **ch4o  IO9
        * Aux  ch1o B.26  ch1on C.16;  **ch2o C.17  ch2on C.18;  **ch3o C.8   ch3on C.9;     **ch4o D.15 
        *
        * GPIO.hardware source
        **/        
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_1,   TIM1_CH1P_PWM_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_1,   TIM1_CH1N_PWM_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_2,   TIM1_CH2P_PWM_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_2,   TIM1_CH2N_PWM_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_3,   TIM1_CH3P_PWM_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_3,   TIM1_CH3N_PWM_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim_pwm,  TIM_PORT_CHANNEL_4,   TIM1_CH4P_PWM_PIN_IDX);
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
