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
#include "main.h"

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
    CB_TIM1_OC_DELAY_ELAPSED,	
    CB_TIM1_PWM_PUSLE_CPL,
	
    CB_TIM2_PERIOD_ELAPSED,
    CB_TIM2_OC_DELAY_ELAPSED,	
    CB_TIM2_PWM_PUSLE_CPL,
    CB_TIM1_ERROR  = 0xE1,
    CB_TIM2_ERROR   ,	
}I2CTASK_CBSTA;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
#define TIMAG_CLOCK_SRC                   (RCC_TIMAGCLKSOURCE_HCLK)
#define TIMAG_DIVIDER                     (2)	
#define TIMAG_CLOCK_FREQ                  (HSI_VALUE/HCLK_DIVIDER_VALUE/1000)   /*HSI:HSI_VALUE,   HSE: HSE_VALUE, PLL: refer to user defined in main.c*/

#define TIMA2_PERIOD_1KHZ_1ms             ((TIMAG_CLOCK_FREQ/TIMAG_DIVIDER)-1)
#define TIMA2_PERIOD_100HZ_10ms           ((TIMAG_CLOCK_FREQ/TIMAG_DIVIDER)/10-1)	
#define TIMA2_PRESCALER_VALUE             (1)

#define TIMAG_OC_FREQ                    (TIMA2_PERIOD_1KHZ_1ms/(TIMA2_PRESCALER_VALUE+1)) 
#define APP_TIM_OC_PULSE1_STEP						((uint16_t)TIMAG_OC_FREQ/5)  	/* Capture Compare 1 Value  */
#define APP_TIM_OC_PULSE2_STEP						((uint16_t)TIMAG_OC_FREQ*2/5) 		/* Capture Compare 2 Value  */
#define APP_TIM_OC_PULSE3_STEP						((uint16_t)TIMAG_OC_FREQ*3/5)  		/* Capture Compare 3 Value  */
#define APP_TIM_OC_PULSE4_STEP						((uint16_t)TIMAG_OC_FREQ*4/5) 		/* Capture Compare 4 Value  */

/*channel 1*/ 
#define TIM2_CH1P_OUT_PIN_IDX          PADI_IDX_IO18_ATOUT2_CH1_P																					    
#define TIM2_CH1N_OUT_PIN_IDX          PADI_IDX_IO19_ATOUT2_CH1_N   
																													 
/*channel 2*/                                                      
#define TIM2_CH2P_OUT_PIN_IDX          PADI_IDX_IO20_ATOUT2_CH2_P   
#define TIM2_CH2N_OUT_PIN_IDX          PADI_IDX_IO21_ATOUT2_CH2_N   
																												 
/*channel 3*/                                                      
#define TIM2_CH3P_OUT_PIN_IDX          PADI_IDX_IO2_ATOUT2_CH3_P    																			    
#define TIM2_CH3N_OUT_PIN_IDX          PADI_IDX_IO3_ATOUT2_CH3_N    
										               

/* Exported macros -----------------------------------------------------------*/
/* USER CODE  1 BEGIN --------------------------------------------------------*/

/* USER CODE  1 END   --------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup TIM_Task_Exported_Functions
  * @{
  */
extern void XT_TimerA_Init(void);
extern void XT_TimerA_Task(void);
extern void XT_TIM2_Start(void );

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
