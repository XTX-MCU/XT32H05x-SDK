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
#include "timerbtask.h"

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
  * @brief  Initializes the TIM Base MSP.
  * @param  htim TIM Base handle
  * @retval None
  */
void HAL_TIMR_Base_MspInit(TIMR_HandleTypeDef *htim)
{ 
	/* Peripheral TIMRB1x clock enable */
   if(htim->Instance ==TIMB13)
		{
			/* Configure TO/TI GPIO AUX */
			HAL_TIMR_OutputPortConfig(htim,TIMRB13_TOGGLE_PIN41_IDX);
			HAL_TIMR_InterruptEnable(TIMB13);
		}		
}

/**
  * @brief  DeInitializes TIM Base MSP.
  * @param  htim TIM Base handle
  * @retval None
  */
void HAL_TIMR_Base_MspDeInit(TIMR_HandleTypeDef *htim)
{
		HAL_PADI_DeInit(PADI,TIMRB13_TOGGLE_PIN41_IDX);	
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
