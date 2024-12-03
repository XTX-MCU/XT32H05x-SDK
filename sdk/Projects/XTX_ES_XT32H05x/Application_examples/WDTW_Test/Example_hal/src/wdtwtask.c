/**
  ******************************************************************************
  * @file    wdtwtask.c
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
#include "wdtwtask.h"
#include "gpiotask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup WDTW_Task
  * @{
  */
/* Private includes ----------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @addtogroup WDTW_Task_Private_Variables
  * @{
  */
WDT_HandleTypeDef hwdtw;
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup WDTW_Task_Private_Functions
  * @{
  */
static void XT_Wdtw_TimeoutCB(WDT_HandleTypeDef *hwdt);
/**
  * @}
  */

/* Private user code ---------------------------------------------------------*/
/** @addtogroup WDTW_Task_Exported_Functions
  * @{
  */

/**
 * @brief  Wdtw Initialization Function
 */
void XT_Wdtw_Init(void)
{
    
    //enable WDT, external clock
    LL_WDTW_Reset();
    LL_WDTW_ResetRelease();
    LL_WDTW_EnableExternalClock();
    
    /* USER CODE BEGIN WWDG_Init 1 */
    HAL_WDT_RegisterCallback(&hwdtw, XT_Wdtw_TimeoutCB);
    hwdtw.Instance   = WDTW;
    hwdtw.Init.Rpl   = WDT_RPL_8;          /* reset pulse length 2 pclk cycles */
    hwdtw.Init.Rmod  = WDT_RMOD_INTRST;   /* interrupt then reset */
    hwdtw.Init.Range = 3;
    hwdtw.Init.InitRange = 2;
    if (HAL_WDT_Init(&hwdtw) != HAL_OK)
    {
      /* Error_Handler */
    }
    HAL_WDT_Refresh(&hwdtw);
    XT_EVB_Led_Off(LED1);		
}


/**
  * @brief  This function is executed.
  * @retval None
  */
void XT_Wdtw_Task(void)
{
  /* USER CODE */
	
}


/**
 * @brief  Wdtw callback Function
  * @retval None
  */
static void XT_Wdtw_TimeoutCB(WDT_HandleTypeDef *hwdt)
{
    HAL_WDT_Refresh(&hwdtw);
    XT_EVB_Led_Toggle(LED1);
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
