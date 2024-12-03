/**
  ******************************************************************************
  * @file    leddriver.h
  * @author  Software Team
  * @brief   Header for leddriver.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LEDDRIVER
#define __LEDDRIVER

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup LEDDRIVER
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/** @defgroup LEDDRIVER_Exported_Types LEDDRIVER Exported Types
  * @{
  */
typedef enum
{
  LED_D1   = 0b00000001,   
  LED_D2   = 0b00000010,   
  LED_D3   = 0b00000100,   
  LED_D4   = 0b00001000,  
  LED_D5   = 0b00010000,
  LED_D6   = 0b00100000,
  LED_D7   = 0b01000000,	
  LED_D8   = 0b10000000,		
} LED_PosTypeDef;

typedef enum
{
  LED_COM1   = 0x00U,   
  LED_COM2   = 1,   
  LED_COM3   = 2,   
  LED_COM4   = 3,  
  LED_COM5   = 4,
  LED_COM6   = 5,
  LED_COM7   = 6,	
  LED_COM8   = 7,   
	
} LED_ComTypeDef;
/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/
/** @addtogroup LEDDRIVER_Exported_Constants
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
/* Exported macro ------------------------------------------------------------*/
#define LED_USE_DMA            (1)


/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup LEDDRIVER_Exported_Functions
  * @{
  */
extern void XT_LED_ScreenAllFrames_Clear(void);
extern void XT_LED_ScreenAllFrames_Turnon(void);
extern void XT_LED_Rmode_SetBrightMode(void);
extern void XT_LED_Rmode_SetOnOFFMode(void);
extern void XT_LED_DisplayLed(LED_ComTypeDef comid, uint8_t column, uint32_t Bright, uint32_t Mode);
extern void XT_LED_DisplayRefresh(void);
extern void XT_LED_DmaCpltCB(void);
extern void XT_LED_FrameClpt_IRQHandler(void);

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

#endif /* __LEDDRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
