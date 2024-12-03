/* USER CODE BEGIN Header */
/** 
  ******************************************************************************
  * @file    xt32h0xx_it.c
  * @author  Software Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "xt32h0xx_it.h"

/* Private includes ----------------------------------------------------------*/

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup IT
  * @{
  */
/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/* External variables --------------------------------------------------------*/
/** @addtogroup IT_External_Variables
  * @{
  */
extern TIM_HandleTypeDef htima1;
extern DMA_HandleTypeDef hTimaDmarx;
extern DMA_HandleTypeDef hTimaDmatx;
/**
  * @}
  */

/** @addtogroup IT_Exported_Functions
  * @{
  */
/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  while (1)
  {
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/******************************************************************************/
/* XT32H0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_xt32h0xx.s).                    */
/******************************************************************************/
/**
  * @brief This function handles DMA1 channel 1 interrupt.
  */
void DMA_IRQHandler(void)
{
    if (__HAL_DMA_GET_IT_FLAG(&hTimaDmarx, DMA_FLAG_BLOCK))
    {	  
        HAL_DMA_IRQHandler(&hTimaDmatx);
    }
	
  	if (__HAL_DMA_GET_IT_FLAG(&hTimaDmarx, DMA_FLAG_TFR))
  	{
  		HAL_DMA_IRQHandler(&hTimaDmarx);
  	}	
}

void TIM1_UDT_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htima1);
}


void TIM1_CC_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htima1);
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