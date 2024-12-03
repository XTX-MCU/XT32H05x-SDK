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
TIM_HandleTypeDef htima2;
uint8_t u1Tim_cbState = CB_TIM_IDLE;
/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @addtogroup TIM_Task_Private_Functions
  * @{
  */
static void XT_TIM2_Init(void );

/* Private user code ---------------------------------------------------------*/

/**
 * @brief  TIM2 Initialization Function
 */
static void XT_TIM2_Init(void)
{
    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_SlaveConfigTypeDef sSlaveConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};
    TIM_OC_InitTypeDef sConfigOC = {0};
    TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};
    TIM_ClearInputConfigTypeDef sClearInputConfig = {0};
    
    /* -1- Enable TIMA Clock:  TIMA source clock in SystemClock_Config()  */
    /* -2- PAD option: Configure pin alternate function 
    /* -3- Configure TIM A parameter configuration */	
    /* Initialize TIMA */
    htima2.Instance = TIM2;
    htima2.Init.Prescaler = TIMA2_PRESCALER_VALUE;
    htima2.Init.Period    = TIMA2_PERIOD_1KHZ_1ms;
    htima2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htima2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htima2.Init.RepetitionCounter = 0;
    htima2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_OC_Init(&htima2) != HAL_OK)
    {
        Error_Handler();
    }
    
    sSlaveConfig.SlaveMode = TIM_SLAVEMODE_DISABLE;
    sSlaveConfig.InputTrigger = TIM_TS_NONE;
    sSlaveConfig.TriggerPolarity = TIM_CLOCKPOLARITY_NONINVERTED;
    sSlaveConfig.TriggerFilter = 0;
    if (HAL_TIM_SlaveConfigSynchro(&htima2, &sSlaveConfig) != HAL_OK)
    {
        Error_Handler();
    }
    
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterOutputTrigger2 = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htima2, &sMasterConfig) != HAL_OK)
    {
        Error_Handler();
    }
    
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    sClockSourceConfig.ClockPolarity = TIM_CLOCKPOLARITY_NONINVERTED;
    sClockSourceConfig.ClockPrescaler = TIM_CLOCKPRESCALER_DIV1;
    sClockSourceConfig.ClockFilter = 0;
    if (HAL_TIM_ConfigClockSource(&htima2, &sClockSourceConfig) != HAL_OK)
    {
        Error_Handler();
    }
    /* -4- Configure output compare parameter configuration */	
    sConfigOC.OCMode = TIM_OCMODE_TOGGLE;
    sConfigOC.Pulse  = APP_TIM_OC_PULSE1_STEP;
    sConfigOC.OCPolarity   = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
    sConfigOC.OCFastMode   = TIM_OCFAST_DISABLE;
    sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    sConfigOC.OCDeadTime  = 0;
    sConfigOC.OCNDeadTime = 0;
    if (HAL_TIM_OC_ConfigChannel(&htima2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
    {
        Error_Handler();
    }
    
    
    sConfigOC.OCMode = TIM_OCMODE_TOGGLE;
    sConfigOC.Pulse  = APP_TIM_OC_PULSE2_STEP;
    sConfigOC.OCPolarity   = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
    sConfigOC.OCFastMode   = TIM_OCFAST_DISABLE;
    sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    sConfigOC.OCDeadTime  = 0;
    sConfigOC.OCNDeadTime = 0;
    if (HAL_TIM_OC_ConfigChannel(&htima2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
    {
        Error_Handler();
    }
    
    
    sConfigOC.OCMode = TIM_OCMODE_TOGGLE;
    sConfigOC.Pulse  =APP_TIM_OC_PULSE3_STEP;
    sConfigOC.OCPolarity   = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
    sConfigOC.OCFastMode   = TIM_OCFAST_DISABLE;
    sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    sConfigOC.OCDeadTime = 0;
    sConfigOC.OCNDeadTime = 0;
    if (HAL_TIM_OC_ConfigChannel(&htima2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
    {
        Error_Handler();
    }
    
    
    sConfigOC.OCMode = TIM_OCMODE_TOGGLE;
    sConfigOC.Pulse  = APP_TIM_OC_PULSE4_STEP;
    sConfigOC.OCPolarity   = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
    sConfigOC.OCFastMode   = TIM_OCFAST_DISABLE;
    sConfigOC.OCIdleState  = TIM_OCIDLESTATE_RESET;
    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
    sConfigOC.OCDeadTime  = 0;     /* x<127: T=x*tDTS;   128<=x<191: T= (64+bit[5:0])*2 * tDTS;
                                     192<=x < 224:(32+bit[4:0])*8 * tDTS;
                                     x>=224: (32+bit[4:0])*16** tDTS*/
    sConfigOC.OCNDeadTime = 0;
    if (HAL_TIM_OC_ConfigChannel(&htima2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
    {
        Error_Handler();
    }

    sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
    sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
    sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
    	
    sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
    sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
    sBreakDeadTimeConfig.BreakFilter = 0;
    sBreakDeadTimeConfig.BreakAFMode = TIM_BREAK_AFMODE_INPUT;
    	
    sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
    sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
    sBreakDeadTimeConfig.Break2Filter = 0;
    sBreakDeadTimeConfig.Break2AFMode = TIM_BREAK2_AFMODE_INPUT;
    	
    sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
    if (HAL_TIMEx_ConfigBreakDeadTime(&htima2, &sBreakDeadTimeConfig) != HAL_OK)
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
    XT_TIM2_Init( );
    XT_TIM2_Start();
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

void XT_TIM2_Start(void )
{
    if (HAL_TIM_OC_Start_IT(&htima2, TIM_CHANNEL_1) != HAL_OK)
    {
    /*Error_Handler*/
    }
//    /*complementary channel */
//    if (HAL_TIMEx_OCN_Start(&htima2, TIM_CHANNEL_1) != HAL_OK)
//    {
//    /*Error_Handler*/
//    }
		
    if (HAL_TIM_OC_Start_IT(&htima2, TIM_CHANNEL_2) != HAL_OK)
    {
    /*Error_Handler*/
    }
//    /*complementary channel */
//    if (HAL_TIMEx_OCN_Start(&htima2, TIM_CHANNEL_2) != HAL_OK)
//    {
//    /*Error_Handler*/
//    }
		
    if (HAL_TIM_OC_Start_IT(&htima2, TIM_CHANNEL_3) != HAL_OK)
    {
    /*Error_Handler*/
    }
		
//    /*complementary channel */
//    if (HAL_TIMEx_OCN_Start(&htima2, TIM_CHANNEL_3) != HAL_OK)
//    {
//    /*Error_Handler*/
//    }
//    if (HAL_TIM_OC_Start_IT(&htima2, TIM_CHANNEL_4) != HAL_OK)
//    {
//    /*Error_Handler*/
//    }

}

/* USER CODE  4 BEGIN --------------------------------------------------------*/

/**
  * @brief  Timer error callback in non-blocking mode
  * @param  htim TIM handle
  * @retval None
  */
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2)
    {
        u1Tim_cbState = CB_TIM2_ERROR;
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
    if(htim->Instance == TIM2)
    {
        u1Tim_cbState = CB_TIM2_PERIOD_ELAPSED;
        XT_EVB_Led_Toggle(LED2);
    }	
}




/*##-Expected Test waveform can be displayed using an oscilloscope and it looks like this##############
                     ___      ___      _____________________________      ___      _____                
   *                |   |    |   |    |                             |    |   |    |     |                 
   * CH1P___________|   |____|   |____|                             |____|   |____|     |_________________
   * (TOGGLE)                        25000                                           25000               
   *     ___________   ____________   ______________________________   ____________   ___________________
   *                | |            | |                              | |            | |                    
   * CH2P           |_|            |_|                              |_|            |_|                    
   *(ACTIVE)                      20000                                           20000                   
   *     ___________   __________________   ________________________   __________________   _____________
   *                | |                  | |                        | |                  | |              
   * CH3P           |_|                  |_|                        |_|                  |_|            
   *(INACTIVE)  50000(0)                  30000                     50000(0)              30000                
   *
   */
/**
  * @brief  Output Compare callback in non-blocking mode
  * @param  htim TIM OC handle
  * @retval None
  */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
    uint16_t autoreload_value;
    uint32_t u4CompareValue = 0;
    autoreload_value = __HAL_TIM_GET_AUTORELOAD(htim);
    
    if ((__HAL_TIM_GET_FLAG(htim, TIM_FLAG_CC1) != RESET)		||(HAL_TIM_GetActiveChannel(htim)== HAL_TIM_ACTIVE_CHANNEL_1))	
    {   
        __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_CC1);
        u4CompareValue = __HAL_TIM_GET_COMPARE(htim,TIM_CHANNEL_1); 
        if (u4CompareValue +APP_TIM_OC_PULSE1_STEP < (autoreload_value/2))
            __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_1, u4CompareValue + APP_TIM_OC_PULSE1_STEP);
        else
            __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_1,0);//(u4CompareValue + PULSE1_STEP) - autoreload_value);       
    }
    	
    if ((__HAL_TIM_GET_FLAG(htim, TIM_FLAG_CC2) != RESET)		||(HAL_TIM_GetActiveChannel(htim)== HAL_TIM_ACTIVE_CHANNEL_2))	
    {
        __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_CC2);			
        u4CompareValue = __HAL_TIM_GET_COMPARE(htim,TIM_CHANNEL_2);
        if (u4CompareValue + APP_TIM_OC_PULSE2_STEP < autoreload_value/2)
            __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2, u4CompareValue + APP_TIM_OC_PULSE2_STEP);
        else
            __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2,0);//(u4CompareValue + PULSE2_STEP) - autoreload_value);
    }
    
    	
    if ((__HAL_TIM_GET_FLAG(htim, TIM_FLAG_CC3) != RESET)		||(HAL_TIM_GetActiveChannel(htim)== HAL_TIM_ACTIVE_CHANNEL_3))	
    {
        __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_CC3);		
        u4CompareValue = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
        
        if (u4CompareValue + APP_TIM_OC_PULSE3_STEP < autoreload_value)
            __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_3, u4CompareValue + APP_TIM_OC_PULSE3_STEP);
        else
            __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_3,0);//(u4CompareValue + PULSE3_STEP) - autoreload_value);  
    }
    	
//    if ((__HAL_TIM_GET_FLAG(htim, TIM_FLAG_CC4) != RESET)		||(HAL_TIM_GetActiveChannel(htim)== HAL_TIM_ACTIVE_CHANNEL_4))	
//    {
//        __HAL_TIM_CLEAR_FLAG(htim, TIM_FLAG_CC4);		
//        u4CompareValue = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
//        
//        if (u4CompareValue + APP_TIM_OC_PULSE3_STEP < autoreload_value)
//            __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_4, u4CompareValue + APP_TIM_OC_PULSE4_STEP);
//        else
//            __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_4,0);//(u4CompareValue + PULSE3_STEP) - autoreload_value);       
//    }	
 	
    u1Tim_cbState = CB_TIM2_OC_DELAY_ELAPSED;
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
