/**
  ******************************************************************************
  * @file    xt32h0xx_hal_msp.c
  * @author  Software Team
  * @brief   This file provides code for the MSP Initialization 
  *          and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "ledtask.h"
#include "dmamemtask.h"
#include "leddriver_FJ5161BH.h"
/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup MSP
  * @{
  */
/* Private types -------------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* External variables --------------------------------------------------------*/
/** @addtogroup MSP_External_Variables
  * @{
  */
extern DMA_HandleTypeDef hLedDmatx;
/**
  * @}
  */
/* External functions --------------------------------------------------------*/
/** @addtogroup MSP_Exported_Functions
  * @{
  */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
}

/**
  * @brief  Initializes the LED MSP.
  * @param  hled LED handle
  */
void HAL_LED_MspInit(LED_HandleTypeDef *hled)
{
    XT_IO_Option_Assigned(PADI_IDX_IO1_LED0,  PADI_CFG_IO1_LED0,  PADI_PULLNO);
    XT_IO_Option_Assigned(PADI_IDX_IO5_LED1,  PADI_CFG_IO5_LED1,  PADI_PULLNO);
    XT_IO_Option_Assigned(PADI_IDX_IO9_LED2,  PADI_CFG_IO9_LED2,  PADI_PULLNO);
    XT_IO_Option_Assigned(PADI_IDX_IO10_LED3, PADI_CFG_IO10_LED3, PADI_PULLNO);
    XT_IO_Option_Assigned(PADI_IDX_IO13_LED4, PADI_CFG_IO13_LED4, PADI_PULLNO);
    XT_IO_Option_Assigned(PADI_IDX_IO14_LED5, PADI_CFG_IO14_LED5, PADI_PULLNO);	
    XT_IO_Option_Assigned(PADI_IDX_IO15_LED6, PADI_CFG_IO15_LED6, PADI_PULLNO);
    XT_IO_Option_Assigned(PADI_IDX_IO17_LED7, PADI_CFG_IO17_LED7, PADI_PULLNO);
    XT_IO_Option_Assigned(PADI_IDX_IO25_LED8, PADI_CFG_IO25_LED8, PADI_PULLNO);	

#if defined(LED_USE_DMA)	
     //DMA ModeDMA Handshaking Interface:
    HAL_LED_DMAHSIFConfig(hled, &hLedDmatx,LED_FRM_DMAHSIF_IDX,LED_FRM_DMAHSIF_CFG);
//    HAL_LED_DMAHSIFConfig(hled, &hLedDmatx,LED_UDT_DMAHSIF_IDX,LED_UDT_DMAHSIF_CFG);
    HAL_LED_LinkDMA(hled, &hLedDmatx);
    __HAL_LED_DMAREQ_ENABLE(hled, LED_DMAREQ_FDE);
#endif	
     /*led interrupt enable*/
    XT_ICTL_IRQ_Module_Enable(XTAPP_ICTL_IRQ_lED,ICTL_IRQCFG_LED_MASK);

     return;
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
