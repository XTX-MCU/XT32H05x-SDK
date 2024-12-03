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
#include "dmamemtask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup TIM_Task
  * @{
  */
/* Private includes ----------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
#define CAPTURE_STEP_READY          (1)
#define CAPTURE_STEP_START          (2)
#define CAPTURE_STEP_END            (3)

#define DMA_TRANSMIT_LENGTH          (TIM_DMABASE_CCR4-TIM_DMABASE_ARR +1)
#define DMA_SRC_BUFFGRP_SIZE         (5)

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


/* Captured Values */
static uint32_t uwICaptureVal = 0;  /*For testing DMA read CC value*/
static uint32_t uwICaptureValue1 = 0;
static uint32_t uwICaptureValue2 = 0;
static uint32_t uwDiffCapture = 0;

static uint32_t uwICaptureCount = 0;

/* Capture index */
static uint16_t u2CaptureStep = 0;

/* Frequency Value */
static uint32_t uwFrequency = 0;
static uint32_t capture_tickstart = 0;
static uint32_t u4BurstRD_data[4] = {0};/*get data of TIM_DMA_ID_CC1~4*/

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
    TIM_IC_InitTypeDef sConfigIC = {0};
    
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
    if (HAL_TIM_IC_Init(&htima1) != HAL_OK)
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
		
    /* -4- Configure input capture  parameter configuration */	
    sConfigIC.ICPolarity = TIM_ICPOLARITY_RISING;
    sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
    sConfigIC.ICPrescaler = TIM_ICPSC_DIV2;
    sConfigIC.ICFilter = 0;
    if (HAL_TIM_IC_ConfigChannel(&htima1, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)

    {
        Error_Handler();
    }
 
}


/* USER CODE  2 BEGIN --------------------------------------------------------*/
static uint32_t XT_Captured_Calculater(TIM_HandleTypeDef *htim, uint32_t input_ch)
{
    uint16_t max_value = __HAL_TIM_GET_AUTORELOAD(htim);
    uwICaptureCount++;
    if(u2CaptureStep == CAPTURE_STEP_READY)
    {
        /* Get the 1st Input Capture value */
        uwICaptureValue1 = u4BurstRD_data[input_ch-1]; //HAL_TIM_ReadCapturedValue(htim,  input_ch);
        u2CaptureStep = CAPTURE_STEP_START;
    }
    else if(u2CaptureStep == CAPTURE_STEP_START)
    {
        /* Get the 2nd Input Capture value */
        uwICaptureValue2 = u4BurstRD_data[input_ch-1]; //HAL_TIM_ReadCapturedValue(htim, input_ch);
        
        /* Capture computation */
        if (uwICaptureValue2 >= uwICaptureValue1)
        {
            uwDiffCapture = (uwICaptureValue2 - uwICaptureValue1); 
        }
        else if (uwICaptureValue2 < uwICaptureValue1)
        {
        	/* 0xFFFF is max TIM1_CCRx value */
            uwDiffCapture = ((max_value - uwICaptureValue1) + uwICaptureValue2) + 1;
        }
        else
        {
        	/* If capture values are equal, we have reached the limit of frequency
        	measures */
            Error_Handler();
        }
        __HAL_TIM_DISABLE_IT(htim,TIM_IT_CC1);
        /* Frequency computation: for this example TIMx (TIM1) is clocked by
        	APB1Clk */      
        uwFrequency = HAL_RCC_GetPeriphCLKFreq(RCC_PERIPHCLK_TIMAG);   //MHz
        uwFrequency = uwFrequency/uwDiffCapture;
        u2CaptureStep = CAPTURE_STEP_END;
    }
}
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
	  if(XT_DMAstate_End_Check())
    {
        XT_Captured_Calculater(&htima1, TIM_DMA_ID_CC1);	
			  XT_DMAstate_Reset(); 
		}
	
    if(u2CaptureStep == CAPTURE_STEP_END)
    {
        u2CaptureStep = CAPTURE_STEP_READY;
        __HAL_TIM_ENABLE_IT(&htima1, TIM_IT_CC1);			
        capture_tickstart = HAL_GetTick();
    }
    
    if((uwFrequency != 0)) //&&((MX_GetTick() - capture_tickstart) > 500))
    {
        capture_tickstart = HAL_GetTick();
        uwICaptureCount = 0;
        uwFrequency = 0;
    }
		
/* USER CODE  3 END   --------------------------------------------------------*/
}

void XT_TIM1_Start(void )
{
    if (HAL_TIM_IC_Start_IT(&htima1, TIM_CHANNEL_1) != HAL_OK)
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
	  	  //XT_EVB_Led_Toggle(LED2);
	  }	
}
/* USER CODE BEGIN 4 */
/**
  * @brief  Input capture callback in non blocking mode 
  * @param  htim : htim handle
  * @retval None
  */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if(HAL_TIM_GetActiveChannel(htim)== HAL_TIM_ACTIVE_CHANNEL_1 )
    {
        if(HAL_TIM_DMABurst_ReadStart(htim,TIM_DMABASE_CCR1,TIM_DMA_CC1,u4BurstRD_data,TIM_DMABURSTLENGTH_4TRANSFERS)!= HAL_OK)
        {
            /* PWM Generation Error */
            Error_Handler();
        }  	
    }

		if(HAL_TIM_GetActiveChannel(htim)== HAL_TIM_ACTIVE_CHANNEL_3 )
    {
    	XT_EVB_Led_Toggle(LED2);	
    }
    u1Tim_cbState = CB_TIM1_IC_CAPTURE;		
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
