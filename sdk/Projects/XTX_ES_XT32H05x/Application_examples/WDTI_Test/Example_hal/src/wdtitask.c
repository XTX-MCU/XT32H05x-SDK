/**
  ******************************************************************************
  * @file    wdtitask.c
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
#include "wdtitask.h"
#include "gpiotask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup WDTI_Task
  * @{
  */
/* Private includes ----------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @addtogroup WDTI_Task_Private_Variables
  * @{
  */
WDT_HandleTypeDef hwdti;
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup WDTI_Task_Private_Functions
  * @{
  */
/**
  * @}
  */

/* Private user code ---------------------------------------------------------*/
/** @addtogroup WDTI_Task_Exported_Functions
  * @{
  */

/**
 * @brief  Wdti Initialization Function
 */
void XT_Wdti_Init(void)
{
    hwdti.Instance   = WDTI;
    hwdti.Init.Rpl   = WDT_RPL_8;                 /* reset pulse length 8 pclk cycles */
    hwdti.Init.Rmod  = WDT_RMOD_SYSRST;
    hwdti.Init.Range = 3;
    hwdti.Init.InitRange = 3;
    if (HAL_WDT_Init(&hwdti) != HAL_OK)
    {
      /* Error_Handler */
    }
    HAL_WDT_Refresh(&hwdti);	
}


/**
  * @brief  This function is executed.
  */
void XT_Wdti_Task(void)
{
    /* USER CODE */
    HAL_Delay(15);  //User code, here delay 15ms only for test purpose.
    HAL_WDT_Refresh(&hwdti);  /*Kick dog*/
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
