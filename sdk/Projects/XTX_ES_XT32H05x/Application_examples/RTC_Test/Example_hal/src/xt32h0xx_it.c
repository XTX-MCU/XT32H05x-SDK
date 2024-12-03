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
#include "main.h"

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
extern RTC_HandleTypeDef hrtc;
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

void RTC_IRQHandler(void )
{
//    HAL_RTC_AlarmIRQHandler(&hrtc);

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
