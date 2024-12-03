/**
  ******************************************************************************
  * @file    xt32h0xx_led_driver.h
  * @author  Software Team
  * @brief   Header for xt32h0xx_led_driver.c
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0XX_LED_DRIVER_H
#define XT32H0XX_LED_DRIVER_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup MW
  * @{
  */

/** @addtogroup XT32H0xx_LED_DRIVER
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"
#include "xt32h0xx_ll_system.h"

/** @defgroup xt32h0xx_LED_DRIVER_Exported_Types Exported Types
  * @{
  */ 
typedef struct 
{
	uint32_t      ComEnable;
	uint32_t      SegEnable;
	uint32_t      Scan_Feq;
  uint32_t      Display_Mode;               /*!< LED display mode LED_RMODE_BRIGHT or LED_RMODE_ONOFF */
  uint32_t      Dead_Time;                  /*!< COM period = 256+dead time, frame period = COM_Period * ComScanNumber */
  uint32_t      Current_Bias;               /*!< Current bias tune */
  uint32_t      Bright_Step;                /*!< Brightness step */
  uint32_t      SegBright_Max[LED_SEG_MAX_NUM];                /*!< Segment brightness maximum */
	
	uint32_t      DmaChannelIndex; /* [0,7] */
} LED_DRV_InitTypeDef;
/**
  * @}
  */ 

/** @defgroup XT32H0xx_LED_DRIVER_Exported_Constants Exported Constants
  * @{
  */ 

#define LED_OK                         0x00
#define LED_ERROR                      0x01
#define LED_TIMEOUT                    0x02


#define LED_TEXT_MODE_REWRITE           (0)
#define LED_TEXT_MODE_OVERLAY           (1)

/**
  * @}
  */

/** @defgroup XT32H0XX_LED_DRIVER_Exported_Functions Exported Functions
  * @{
  */

/** @defgroup XT32H0XX_LED_DRIVER_Exported_Functions_Group1 Display functions 
  * @{
  */
void             LED_DRV_Init(LED_DRV_InitTypeDef* pLedp);
void             LED_DRV_DirectInit(LED_DRV_InitTypeDef* pLedp);
void             LED_DRV_DeInit(void);
void             LED_DRV_On(void);
void             LED_DRV_Off(void);
void             LED_DRV_DisplayText(uint32_t Com, uint8_t Ch, uint32_t Bright, uint32_t Mode);
void             LED_DRV_DisplayNode(uint32_t Com, uint32_t Seg, uint32_t Bright);
void             LED_DRV_Dimming(uint32_t Step, uint32_t Intpol);
void             LED_DRV_Blink(void);
void             LED_DRV_Normal(void);
void             LED_DRV_SetOnOFFMode(void);
void             LED_DRV_SetBrightMode(void);
void             LED_DRV_DisplayTextDirect(uint32_t Com, uint8_t Ch, uint32_t Bright, uint32_t Mode);
void             LED_DRV_DisplayNodeDirect(uint32_t Com, uint32_t Seg, uint32_t Bright);
/**
  * @}
  */ 

/** @defgroup XT32H0XX_LED_DRIVER_Exported_Functions_Group2 Screen buffer functions
  * @{
  */
void             LED_DRV_ClearAllScreens(void);  
void             LED_DRV_DrawNewFrame(void);
void             LED_DRV_InitAllFrames(void);
void             LED_DRV_ClearAllFrames(void);
void             LED_DRV_RefreshFrame(void);
void             LED_DRV_RefreshFrame_DMA(void);

void             LED_DRV_BlockCompleted_DMA(void);

void             LED_DRV_DMA_Block_IRQHandler(DMA_HandleTypeDef *hdma);
void             LED_DRV_DMA_DstTran_IRQHandler(DMA_HandleTypeDef *hdma);
void             LED_DRV_FrameClpt_IRQHandler(void);
void             LED_DRV_FramePreRead_IRQHandler(void);

void             LED_DRV_ResetScreenBuffer(void);

void             LED_DRV_IRQHandler(void);

void             LED_DRV_OnFrames(void);
/**
  * @}
  */ 


/** @addtogroup XT32H0XX_LED_DRIVER_Exported_Functions_Group3 Unit test functions
  * @{
  */
//void             LED_Test_CaseCom(void);
/**
  * @}
  */ 

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

#endif /* XT32H0XX_LED_DRIVER_H */

    
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

