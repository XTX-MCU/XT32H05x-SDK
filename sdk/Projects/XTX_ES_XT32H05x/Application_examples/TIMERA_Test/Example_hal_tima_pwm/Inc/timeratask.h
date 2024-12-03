/**
  ******************************************************************************
  * @file    timeratask.h
  * @author  Software Team
  * @brief   Header for timeratask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMERATASK_H
#define __TIMERATASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup TIM_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/** @addtogroup TIM_Task_Exported_Types
  * @{
  */
/**
  * @brief  Callback status Type Structure definition
  */
typedef enum  {
    CB_TIM_IDLE   = 0,
    CB_TIM1_PERIOD_ELAPSED,
    CB_TIM1_PWM_PUSLE_CPL,
    CB_TIM2_PERIOD_ELAPSED,
    CB_TIM2_PWM_PUSLE_CPL,
    CB_TIM1_ERROR  = 0xE1,
    CB_TIM2_ERROR   	
}I2CTASK_CBSTA;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
#define TIMAG_CLOCK_SRC                   (RCC_TIMAGCLKSOURCE_HCLK)
#define TIMAG_DIVIDER                     (2)	
#define TIMAG_CLOCK_FREQ                  (HSI_VALUE/HCLK_DIVIDER_VALUE/1000)   /*HSI:HSI_VALUE,   HSE: HSE_VALUE, PLL: refer to user defined in main.c*/

#define TIMA1_PERIOD_1KHZ_1ms             ((TIMAG_CLOCK_FREQ/TIMAG_DIVIDER)-1)
#define TIMA1_PERIOD_100HZ_10ms           ((TIMAG_CLOCK_FREQ/TIMAG_DIVIDER)/10-1)	
#define TIMA1_PRESCALER_VALUE             (1)

#define TIMAG_PWM_FREQ                    (TIMA1_PERIOD_1KHZ_1ms/(TIMA1_PRESCALER_VALUE+1)) 

#define APP_PWM_PULSE1_VALUE              (uint32_t)(TIMAG_PWM_FREQ/2) /* Capture Compare 1 Value duty cycle= 50% */
#define APP_PWM_PULSE2_VALUE              (uint32_t)(TIMAG_PWM_FREQ/3) /* Capture Compare 2 Value duty cycle= 37.5% */
#define APP_PWM_PULSE3_VALUE              (uint32_t)(TIMAG_PWM_FREQ/4) /* Capture Compare 3 Value duty cycle= 25% */
#define APP_PWM_PULSE4_VALUE              (uint32_t)(TIMAG_PWM_FREQ/8) /* Capture Compare 4 Value duty cycle= 12.5% */


/*channel 1*/ 
#define TIM1_CH1P_PWM_PIN_IDX          PADI_IDX_IO10_ATOUT1_CH1_P																					    
#define TIM1_CH1N_PWM_PIN_IDX          PADI_IDX_IO13_ATOUT1_CH1_N   
														           
/*channel 2*/                                                      
#define TIM1_CH2P_PWM_PIN_IDX          PADI_IDX_IO14_ATOUT1_CH2_P   
#define TIM1_CH2N_PWM_PIN_IDX          PADI_IDX_IO15_ATOUT1_CH2_N   
															          
/*channel 3*/                                                      
#define TIM1_CH3P_PWM_PIN_IDX          PADI_IDX_IO5_ATOUT1_CH3_P    																			    
#define TIM1_CH3N_PWM_PIN_IDX          PADI_IDX_IO9_ATOUT1_CH3_N    
														           
/*channel 4*/                                                      
#define TIM1_CH4P_PWM_PIN_IDX          PADI_IDX_IO44_ATOUT1_CH4     

/* Exported macros -----------------------------------------------------------*/
/* USER CODE  1 BEGIN --------------------------------------------------------*/

/* USER CODE  1 END   --------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup TIM_Task_Exported_Functions
  * @{
  */
extern void XT_TimerA_Init(void);
extern void XT_TimerA_Task(void);
extern void XT_TIM1_Start(void );

/* USER CODE  2 BEGIN --------------------------------------------------------*/

/* USER CODE  2 END   --------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __TIMERATASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
