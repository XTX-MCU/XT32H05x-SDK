/**
  ******************************************************************************
  * @file    ledtask.c
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
#include "ledtask.h"
#include "leddriver.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup LED_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/
/** @defgroup XT32H0xx_EVB__LED_Private_Defines Private Defines
  * @{
  */ 

/**
  * @}
  */
	
/* Private macro -------------------------------------------------------------*/
 
/** @addtogroup LED_Task_Private_Variables
  * @{
  */
/* Private Variables ------------------------------------------------------------*/
LED_HandleTypeDef hled1;

static uint8_t u4DemoPattern_idx = LED_DEMO_NONE; 
static uint32_t  status =0;
/**
  * @}
  */


/** @addtogroup LED_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @}
  */

/** @addtogroup LED_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  */
void XT_Led_Init(void)
{
    LED_InitTypeDef ledInit = {0};

    ledInit.ComEnable    = LED_ENABLE_COM0 | LED_ENABLE_COM1 | LED_ENABLE_COM2 | LED_ENABLE_COM3|
                           LED_ENABLE_COM4 | LED_ENABLE_COM5 | LED_ENABLE_COM6 | LED_ENABLE_COM7;
    ledInit.SegEnable    = LED_ENABLE_SEG0 | LED_ENABLE_SEG1 | LED_ENABLE_SEG2 | LED_ENABLE_SEG3|
                           LED_ENABLE_SEG4 | LED_ENABLE_SEG5 | LED_ENABLE_SEG6 | LED_ENABLE_SEG7|
                           LED_ENABLE_SEG8;
    ledInit.Scan_Feq     = 60;
    ledInit.Display_Mode = LED_RMODE_BRIGHT;//LED_RMODE_ONOFF;  //
    ledInit.Dead_Time    = 2;    
    ledInit.Current_Bias = 4;
    ledInit.Bright_Step  = 8;
    ledInit.SegBright_Max[0] = 0x1f;                /*!< Segment brightness maximum */
    ledInit.SegBright_Max[1] = 0x1f;                /*!< Segment brightness maximum */
    ledInit.SegBright_Max[2] = 0x1f;                /*!< Segment brightness maximum */
    ledInit.SegBright_Max[3] = 0x1f;                /*!< Segment brightness maximum */
    ledInit.SegBright_Max[4] = 0x1f;                /*!< Segment brightness maximum */
    ledInit.SegBright_Max[5] = 0x1f;                /*!< Segment brightness maximum */
    ledInit.SegBright_Max[6] = 0x1f;                /*!< Segment brightness maximum */
    ledInit.SegBright_Max[7] = 0x1f;                /*!< Segment brightness maximum */
    ledInit.SegBright_Max[8] = 0x1f;                /*!< Segment brightness maximum */

    hled1.Instance = LED;
    hled1.Init     = ledInit;
    hled1.hdma     = NULL;
    HAL_LED_Init(&hled1);
    HAL_LED_Off(&hled1);
    if(ledInit.Display_Mode == LED_RMODE_BRIGHT)
        XT_LED_Rmode_SetBrightMode();
    else
        XT_LED_Rmode_SetOnOFFMode();

    __HAL_LED_CLEAR_ALLFLAGS(&hled1);	

    __HAL_LED_INTERRUPT_ENABLE(&hled1, LED_CTRL_FIE);

    HAL_LED_AnaOn(&hled1);
    HAL_LED_On(&hled1);
    u4DemoPattern_idx = LED_DEMO_SCANONE;
}

/**
  * @brief  This function is executed.
  */
void XT_Led_Task(void)
{
    uint8_t i=0, j=0;
    
    if(u4DemoPattern_idx == LED_DEMO_SCANONE)
    { 		  
        for(j=0; j<8; j++)
        { 
            for(i=LED_COM1; i<= LED_COM8; i++ )
            { 
                XT_LED_ScreenAllFrames_Clear();							 
                XT_LED_DisplayLed(i, 0x1<<j, 30, LED_TEXT_MODE_REWRITE);
                XT_LED_DisplayRefresh();
                HAL_Delay(300);
            }	   	   
        } 	    				
    }	
    else if(u4DemoPattern_idx == LED_DEMO_SCANROW)
    {
        XT_LED_ScreenAllFrames_Clear();
        for(j=0; j<8; j++)
        { 
            for(i=LED_COM1; i<=LED_COM8; i++ )
            { XT_LED_DisplayLed(i, 0x1<<j, 30, LED_TEXT_MODE_REWRITE);		}			  
            XT_LED_DisplayRefresh();
            HAL_Delay(300);
        } 	    				
    }			
    else if(u4DemoPattern_idx == LED_DEMO_SCANCOL)
    {		
        for(i=LED_COM1; i<=LED_COM8; i++ )
        { 
            XT_LED_ScreenAllFrames_Clear();
            XT_LED_DisplayLed(i, LED_D1|LED_D2|LED_D3|LED_D4|LED_D5|LED_D6|LED_D7|LED_D8, 60, LED_TEXT_MODE_REWRITE);
            XT_LED_DisplayRefresh();
            HAL_Delay(300);
        }        		 
    }
    else if(u4DemoPattern_idx == LED_DEMO_NUMBLINK)	
    {
        for(i=LED_COM1; i<=LED_COM8; i++ )
        { 
            XT_LED_DisplayLed(i, LED_D1|LED_D2|LED_D3|LED_D4|LED_D5|LED_D6|LED_D7|LED_D8, 60, LED_TEXT_MODE_REWRITE);
        }		
        XT_LED_DisplayRefresh();			
        HAL_LED_SetRunningMode(&hled1, LED_DMODE_DIMMING, LED_DIMMING_STEP_1, 2);
        
    }	
    else if(u4DemoPattern_idx == LED_DEMO_DIMMING)	
    {
        HAL_LED_SetRunningMode(&hled1, LED_DMODE_DIMMING, 1, 16);
    }	
    
    u4DemoPattern_idx++;
    HAL_Delay(1000);
}



/**
  * @brief  Led IRQ handler.
  * @param  hled LED handle
  */
void HAL_LED_IRQHandler(LED_HandleTypeDef *hled)
{
    uint32_t flag = hled1.Instance->STATUS;
    
    __HAL_LED_INTERRUPT_DISABLE(&hled1, LED_CTRL_FIE);
    __HAL_LED_CLEAR_ALLFLAGS(&hled1);
    
    
    if(flag & LED_FLAG_FIF)
    {
    	//user code here
			XT_LED_FrameClpt_IRQHandler();
	
    }
    
    __HAL_LED_INTERRUPT_ENABLE(&hled1, LED_CTRL_FIE);
    __HAL_LED_CLEAR_ALLFLAGS(&hled1);
    
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
