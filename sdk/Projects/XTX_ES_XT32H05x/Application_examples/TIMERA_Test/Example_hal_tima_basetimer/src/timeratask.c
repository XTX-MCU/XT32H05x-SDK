/**
  ******************************************************************************
  * @file    timeratask.c
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
#include "timeratask.h"
#include "gpiotask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup TIM_Task
  * @{
  */
/* Private includes ----------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* USER CODE  1 BEGIN --------------------------------------------------------*/

/* USER CODE  1 END   --------------------------------------------------------*/

extern void Error_Handle(void);
/* Private variables ---------------------------------------------------------*/
/** @addtogroup TIM_Task_Private_Variables
  * @{
  */
TIM_HandleTypeDef htima1;
uint8_t u1Tim_cbState = CB_TIM_IDLE;
/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @addtogroup TIM_Task_Private_Functions
  * @{
  */
static void XT_TIM1_Init(void );

/* Private user code ---------------------------------------------------------*/

/**
 * @brief  TIM1 Initialization Function
 */
void XT_TIM1_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_SlaveConfigTypeDef sSlaveConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};
    
    /* -1- Enable TIMA Clock:  TIMA source clock in SystemClock_Config()  */
    /* -2- PAD option: Configure pin alternate function in HAL_TIM_Base_MspInit() /HAL_TIM_PWM_MspInit/HAL_TIM_OnePulse_MspInit /HAL_TIM_IC_MspInit/HAL_TIM_OC_MspInit */
    
    /* -3- Configure TIM A parameter configuration */	
    /* Initialize TIMA */
    htima1.Instance = TIM1;
    htima1.Init.Prescaler = TIMA1_PRESCALER_VALUE;
    htima1.Init.Period    = TIMA1_PERIOD_1KHZ_1ms;
    htima1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htima1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htima1.Init.RepetitionCounter = 0;
    htima1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_Base_Init(&htima1) != HAL_OK)
    {
        Error_Handler();
    }
    
    sSlaveConfig.SlaveMode = TIM_SLAVEMODE_DISABLE;
    sSlaveConfig.InputTrigger = TIM_TS_NONE;
    sSlaveConfig.TriggerPolarity = TIM_CLOCKPOLARITY_NONINVERTED;
    sSlaveConfig.TriggerFilter = 0;
    if (HAL_TIM_SlaveConfigSynchro(&htima1, &sSlaveConfig) != HAL_OK)
    {
        Error_Handler();
    }
    
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterOutputTrigger2 = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htima1, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }
    
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    sClockSourceConfig.ClockPolarity = TIM_CLOCKPOLARITY_NONINVERTED;
    sClockSourceConfig.ClockPrescaler = TIM_CLOCKPRESCALER_DIV1;
    sClockSourceConfig.ClockFilter = 0;
    if (HAL_TIM_ConfigClockSource(&htima1, &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }
}


/* USER CODE  2 BEGIN --------------------------------------------------------*/

/* USER CODE  2 END   --------------------------------------------------------*/

/**
  * @}
  */

/** @addtogroup TIM_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_TimerA_Init(void)
{
    XT_TIM1_Init( );
    XT_TIM1_Start();
}

/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_TimerA_Task(void)
{
/* USER CODE  3 BEGIN --------------------------------------------------------*/

/* USER CODE  3 END   --------------------------------------------------------*/
}

void XT_TIM1_Start(void )
{
    if (HAL_TIM_Base_Start_IT(&htima1) != HAL_OK)
    {
        /*Error_Handler*/
    }
}

/* USER CODE  4 BEGIN --------------------------------------------------------*/

/**
  * @brief  Timer error callback in non-blocking mode
  * @param  htim TIM handle
  * @retval None
  */
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM1)
    {
        u1Tim_cbState = CB_TIM1_ERROR;
    }	
}

/* USER CODE BEGIN 4 */
/**
  * @brief  Period elapsed callback in non blocking mode
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    
    if(htim->Instance == TIM1)
    {
        u1Tim_cbState = CB_TIM1_PERIOD_ELAPSED;
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
