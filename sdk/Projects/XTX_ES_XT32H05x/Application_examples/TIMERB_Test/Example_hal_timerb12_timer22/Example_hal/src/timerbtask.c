/**
  ******************************************************************************
  * @file    timerbtask.c
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
#include "main.h"
#include "timerbtask.h"
#include "gpiotask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup TIMR_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/* USER CODE  1 BEGIN --------------------------------------------------------*/

/* USER CODE  1 END   --------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @addtogroup TIMR_Task_Private_Variables
  * @{
  */
TIMR_HandleTypeDef htimb2;
TIMR_HandleTypeDef htimb6;

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup TIMR_Task_Private_Functions
  * @{
  */
static void XT_TIMB11_Init(void );
static void XT_TIMB22_Init(void );

/* Private user code ---------------------------------------------------------*/
/**
 * @brief  TIMB13 Initialization Function
 */
static void XT_TIMB12_Init(void)
{
  /* Initialize TIMB */
  htimb2.Instance = TIMB12;
    
  /* Initialize TIMx peripheral as follow:
  */
  htimb2.Init.CounterMode = TIME_MODE_USERDEFINED; 
  htimb2.Init.LoadCount   = TIMERB1_PERIOD_1KHZ_1ms; 
  if(HAL_TIMR_Base_Init(&htimb2) != HAL_OK)
  {
    /* Error_Handler */
  }
}

/**
 * @brief  TIMB22 Initialization Function
 */
static void XT_TIMB22_Init(void)
{
  /* Initialize TIMB */
  htimb6.Instance = TIMB22;
    
  /* Initialize TIMx peripheral as follow:
  */
  htimb6.Init.CounterMode = TIME_MODE_USERDEFINED; 
  htimb6.Init.LoadCount   = TIMERB2_PERIOD_100HZ_10ms; 
  if(HAL_TIMR_Base_Init(&htimb6) != HAL_OK)
  {
    /* Error_Handler */
  }
}


/* USER CODE  2 BEGIN --------------------------------------------------------*/

/* USER CODE  2 END   --------------------------------------------------------*/

/**
  * @}
  */

/** @addtogroup TIMR_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  */
void XT_TimerB_Init(void)
{
  XT_TIMB12_Init( );
  XT_TIMB22_Init( );
}

/**
  * @brief  This function is executed.
  */
void XT_TimerB_Task(void)
{
/* USER CODE  3 BEGIN --------------------------------------------------------*/
    /* USER CODE */
    if(XT_EVB_Button1_State_Get())
    {
        /* Start the TIM time Base generation in interrupt mode */
        if(HAL_TIMR_Base_Start_IT(&htimb2) != HAL_OK)
        {
            /* Starting Error */
            Error_Handle();
        } 

        if(HAL_TIMR_Base_Start_IT(&htimb6) != HAL_OK)
        {
            /* Starting Error */
            Error_Handle();
        }	
				
    }	
    
    if(XT_EVB_Button2_State_Get())
    {	
        /* Stop the TIM time Base generation in interrupt mode */
        if(HAL_TIMR_Base_Stop_IT(&htimb2) != HAL_OK)
        {
            /* Starting Error */
            Error_Handle();
        }
        if(HAL_TIMR_Base_Stop_IT(&htimb6) != HAL_OK)
        {
            /* Starting Error */
            Error_Handle();
        }
    } 
/* USER CODE  3 END   --------------------------------------------------------*/
}

/* USER CODE  4 BEGIN --------------------------------------------------------*/
/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM2 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIMR_Callback(TIMR_HandleTypeDef *htim)
{
    if(htim->Instance == htimb2.Instance)
    {
        XT_EVB_Led_Toggle(LED1);
    }
    else if(htim->Instance == htimb6.Instance)
    {
        XT_EVB_Led_Toggle(LED2);		
    }	
}
/* USER CODE  4 END   --------------------------------------------------------*/
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
