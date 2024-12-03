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
* @brief TIM_IC MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_ic: TIM_IC handle pointer
* @retval None
*/
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef* htim_ic)
{
    if(htim_ic->Instance==TIM1)
    {
        HAL_TIM_InputPortConfig(htim_ic->Instance, htim_ic->Instance, TIM_PORT_CHANNEL_1 ,  TIM1_CH1_IC_PIN_IDX);
       //HAL_TIM_InputPortConfig(htim_ic, TIM_PORT_CHANNEL_2 ,  TIM1_CH2_IC_PIN_IDX);
       //HAL_TIM_InputPortConfig(htim_ic, TIM_PORT_CHANNEL_3 ,  TIM1_CH3_IC_PIN_IDX);
       //HAL_TIM_InputPortConfig(htim_ic, TIM_PORT_CHANNEL_4 ,  TIM1_CH4_IC_PIN_IDX);
    }
    else if(htim_ic->Instance==TIM2)
    {
        HAL_TIM_InputPortConfig(htim_ic, htim_ic->Instance, TIM_PORT_CHANNEL_3 ,  TIM2_CH3_IC_PIN_IDX);
        HAL_TIM_InputPortConfig(htim_ic, htim_ic->Instance, TIM_PORT_CHANNEL_4 ,  TIM2_CH4_IC_PIN_IDX);
    }
   #if defined(SUPPORT_CC1_OUTPUT) 
    XT_TIMx_DMA_readcfg(htim_ic,TIM_DMA_ID_CC1); 
    __HAL_TIM_ENABLE_IT(htim_ic, TIM_IT_CC1);		
    #endif
		
    #if defined(SUPPORT_CC2_OUTPUT)
    XT_TIMx_DMA_readcfg(htim_ic,TIM_DMA_ID_CC2); 
    __HAL_TIM_ENABLE_IT(htim_ic, TIM_IT_CC2);		
    #endif
		
    #if defined(SUPPORT_CC3_OUTPUT) 
    XT_TIMx_DMA_readcfg(htim_ic,TIM_DMA_ID_CC3);  
    __HAL_TIM_ENABLE_IT(htim_ic, TIM_IT_CC3);
    #endif
		
    #if defined(SUPPORT_CC4_OUTPUT) 
    XT_TIMx_DMA_readcfg(htim_ic,TIM_DMA_ID_CC4); 
    __HAL_TIM_ENABLE_IT(htim_ic, TIM_IT_CC4);		
    #endif
		
    __HAL_TIM_ENABLE_IT(htim_ic, TIM_IT_UPDATE);
    __HAL_TIM_ENABLE(htim_ic);	
}

/**
* @brief TIM_IC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_ic: TIM_IC handle pointer
* @retval None
*/
void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef* htim_ic)
{
	if(htim_ic->Instance==TIM1)
	{
		
		HAL_PADI_DeInit(PADI,TIM1_CH1_IC_PIN_IDX);
		//HAL_PADI_DeInit(PADI,TIM1_CH2_IC_PIN_IDX);	
		//HAL_PADI_DeInit(PADI,TIM1_CH3_IC_PIN_IDX);
		//HAL_PADI_DeInit(PADI,TIM1_CH4_IC_PIN_IDX);	
 
    HAL_DMA_DeInit(htim_ic->hdma[TIM_DMA_ID_UPDATE]);
    HAL_DMA_DeInit(htim_ic->hdma[TIM_DMA_ID_CC1]);
   //HAL_DMA_DeInit(htim_ic->hdma[TIM_DMA_ID_CC2]);
   //HAL_DMA_DeInit(htim_ic->hdma[TIM_DMA_ID_CC3]);
   //HAL_DMA_DeInit(htim_ic->hdma[TIM_DMA_ID_CC4]);
   //HAL_DMA_DeInit(htim_ic->hdma[TIM_DMA_ID_COMMUTATION]);
 
    __HAL_TIM_DISABLE_IT(htim_ic, TIM_IT_CC1);	
    //__HAL_TIM_DISABLE_IT(htim_ic, TIM_IT_CC2); 
    //__HAL_TIM_DISABLE_IT(htim_ic, TIM_IT_CC3);	
    //__HAL_TIM_DISABLE_IT(htim_ic, TIM_IT_CC4);
    //__HAL_TIM_DISABLE_IT(htim_ic, TIM_IT_COM);	
    __HAL_TIM_DISABLE_IT(htim_ic, TIM_IT_UPDATE);	
    __HAL_TIM_DISABLE(htim_ic);		

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
