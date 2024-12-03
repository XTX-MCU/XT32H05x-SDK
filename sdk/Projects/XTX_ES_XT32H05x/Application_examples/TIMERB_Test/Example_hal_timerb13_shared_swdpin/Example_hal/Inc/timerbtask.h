/**
  ******************************************************************************
  * @file    timerbtask.h
  * @author  Software Team
  * @brief   Header for timerbtask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TIMERBTASK_H
#define __TIMERBTASK_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup TIMR_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
#define TIMERB1_CLOCK_SRC                 (RCC_TIMB1CLKSOURCE_HCLK)// (RCC_TIMB1CLKSOURCE_PLL) //(RCC_TIMB1CLKSOURCE_PCLK) // 
#define TIMERB1_CLOCK_DIV                 (1)   
                                              
#define TIMERB2_CLOCK_SRC                 (RCC_TIMB2CLKSOURCE_PCLK)  //HCLK/2
#define TIMERB2_CLOCK_DIV                 (2)    

#define TIMERB1_CLOCK_FREQ                (HSI_VALUE/HCLK_DIVIDER_VALUE/1000)   /*HSI:HSI_VALUE,   HSE: HSE_VALUE, PLL: refer to user defined in main.c*/
#define TIMERB2_CLOCK_FREQ                (HSI_VALUE/PCLK_DIVIDER_VALUE/1000)  

#define TIMERB1_PERIOD_1KHZ_1ms           ((TIMERB1_CLOCK_FREQ/TIMERB1_CLOCK_DIV)-1)
#define TIMERB1_PERIOD_100HZ_10ms         (TIMERB1_CLOCK_FREQ*10/TIMERB1_CLOCK_DIV)-1)																		
#define TIMERB2_PERIOD_1KHZ_1ms           ((TIMERB2_CLOCK_FREQ/TIMERB2_CLOCK_DIV)-1)
#define TIMERB2_PERIOD_100HZ_10ms         ((TIMERB2_CLOCK_FREQ*10/TIMERB2_CLOCK_DIV)-1)


#define TIMRB13_TOGGLE_PIN41_IDX       PADI_IDX_IO37_BTOUT13
//#define TIMRB13_TOGGLE_PIN41_CFG       PADI_CFG_IO37_BTOUT13																			    


/* Exported macros -----------------------------------------------------------*/
/* USER CODE  1 BEGIN --------------------------------------------------------*/

/* USER CODE  1 END   --------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup TIMR_Task_Exported_Functions
  * @{
  */
extern void XT_TimerB_Init(void );
extern void XT_TimerB_Task(void );

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

#endif /* __TIMERBTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
