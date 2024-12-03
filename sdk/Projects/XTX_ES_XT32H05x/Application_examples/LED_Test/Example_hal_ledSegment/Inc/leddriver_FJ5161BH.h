/**
  ******************************************************************************
  * @file    leddriver_FJ5161BH.h
  * @author  Software Team
  * @brief   Header for leddriver_FJ5161BH.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LEDDRIVER_FJ5161BH
#define __LEDDRIVER_FJ5161BH

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup LEDDRIVER_FJ5161BH
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/** @defgroup LEDDRIVER_FJ5161BH_Exported_Types LEDDRIVER_FJ5161BH Exported Types
  * @{
  */
typedef enum
{
  DISPLAY_LED_SEG_COM1   = 0x00U,   
  DISPLAY_LED_SEG_COM2   ,   
  DISPLAY_LED_SEG_COM3   ,   
  DISPLAY_LED_SEG_COM4   ,  
  DISPLAY_LED_SEG_COM5   ,
  DISPLAY_LED_SEG_COM6   ,
  DISPLAY_LED_SEG_COM7   ,	
  DISPLAY_LED_SEG_COM8       
} LED_SegComTypeDef;

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
/** @defgroup LEDDRIVER_FJ5161BH_Exported_Constants
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
/** @addtogroup LEDDRIVER_FJ5161BH_Exported_Functions
  * @{
  */
extern void XT_LED_ScreenAllFrames_Clear(void);
extern void XT_LED_ScreenAllFrames_Turnon(void);
extern void XT_LED_Rmode_SetBrightMode(void);
extern void XT_LED_Rmode_SetOnOFFMode(void);
extern void XT_LED_DisplayChar(LED_ComTypeDef comid, uint8_t Ch, uint32_t Bright, uint32_t Mode);
extern void XT_LED_DisplayStr(uint8_t* showstr);
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

#endif /* __LEDDRIVER_FJ5161BH */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
