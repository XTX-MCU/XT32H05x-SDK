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



void HAL_TIM_OnePulse_MspInit(TIM_HandleTypeDef *htim)
{
    if(htim->Instance==TIM1)
    {
        /* Peripheral clock enable */
        __HAL_RCC_TIMA_CLK_ENABLE();
        /* USER CODE BEGIN TIM1_MspInit 1 */
        LL_RCC_SetAdvancedTimerInput(LL_RCC_TIMA1_CH1IN,SET);			
        HAL_TIM_InputPortConfig(htim->Instance, htim->Instance, TIM_PORT_CHANNEL_1 ,  TIM1_CH1_IC_PIN_IDX);
        HAL_TIM_OutputPortConfig(htim, TIM_PORT_CHANNEL_2,   TIM1_CH1_IC_PIN_IDX);	
    }
}

void HAL_TIM_OnePulse_MspDeInit(TIM_HandleTypeDef *htim)
{     
    if(htim->Instance==TIM1)
    {
        /* Peripheral clock disable */
        __HAL_RCC_TIMA_CLK_DISABLE();
        HAL_PADI_DeInit(PADI,TIM1_CH1_IC_PIN_IDX );		
        HAL_PADI_DeInit(PADI,TIM1_CH1_IC_PIN_IDX );
        HAL_NVIC_DisableIRQ(TIM1_CC_IRQn);	
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
