/**
  ******************************************************************************
  * @file    xt32h0xx_led.h
  * @author  Software Team
  * @date    29 November 2022
  * @brief   This file contains all the functions prototypes for the CRC firmware 
  *          library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_LED_H
#define __XT32H0XX_LED_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup LED
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup LED_Exported_Types LED Exported Types
  * @{
  */
typedef struct
{
  uint32_t ComEnable;                  /*!< COM Enable
                                            @ref LED_COM_ENABLE. */

  uint32_t SegEnable;                  /*!< Enable segment 
                                            @ref LED_SEG_ENABLE. */

  uint32_t ScanFeq;                    /*!< \@frames per second. i.g. 30,60,100,120 
                                            divider = SCLK / frame period / Scan_Feq */

  uint32_t DisplayMode;                /*!< LED display mode 
                                            @ref LED_Display_MODE */

  uint32_t DeadTime;                   /*!< COM period = 256+dead time, frame period = COM_Period * ComScanNumber */

  uint32_t CurrentBias;                /*!< Current bias tune */
  uint32_t BrightStep;                 /*!< Brightness step */
} LED_InitTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup LED_Exported_Constants LED Exported Constants
  * @{
  */
/** @defgroup LED_COM_ENABLE LED COM enable
  * @{
  */
#define LED_COM0                       (LED_CTRL_CE_0)
#define LED_COM1                       (LED_CTRL_CE_1) 
#define LED_COM2                       (LED_CTRL_CE_2) 
#define LED_COM3                       (LED_CTRL_CE_3) 
#define LED_COM4                       (LED_CTRL_CE_4) 
#define LED_COM5                       (LED_CTRL_CE_5) 
#define LED_COM6                       (LED_CTRL_CE_6) 
#define LED_COM7                       (LED_CTRL_CE_7) 
#define LED_COMALL                     (LED_CTRL_CE_7 | LED_CTRL_CE_6 | LED_CTRL_CE_5 | LED_CTRL_CE_4 |\
                                        LED_CTRL_CE_3 | LED_CTRL_CE_2 | LED_CTRL_CE_1 | LED_CTRL_CE_0) 
/**
  * @}
  */

/** @defgroup LED_SEG_ENABLE LED SEG enable
  * @{
  */
#define LED_SEG0                       (LED_CTRL_SE_0)
#define LED_SEG1                       (LED_CTRL_SE_1) 
#define LED_SEG2                       (LED_CTRL_SE_2) 
#define LED_SEG3                       (LED_CTRL_SE_3) 
#define LED_SEG4                       (LED_CTRL_SE_4) 
#define LED_SEG5                       (LED_CTRL_SE_5) 
#define LED_SEG6                       (LED_CTRL_SE_6) 
#define LED_SEG7                       (LED_CTRL_SE_7) 
#define LED_SEG8                       (LED_CTRL_SE_8) 
#define LED_SEGALL                     (LED_CTRL_SE_8 | LED_CTRL_SE_7 | LED_CTRL_SE_6 | LED_CTRL_SE_5 |\
                                        LED_CTRL_SE_4 | LED_CTRL_SE_3 | LED_CTRL_SE_2 | LED_CTRL_SE_1 |\
                                        LED_CTRL_SE_0) 
/**
  * @}
  */

/** @defgroup LED_DIMMING_STEP LED dimming step
  * @{
  */
#define LED_DIMMING_STEP_16            (0x00000000U)                           /*!< 1/16 */
#define LED_DIMMING_STEP_8             (LED_MODE_DIMS_0)                       /*!< 1/8  */
#define LED_DIMMING_STEP_4             (LED_MODE_DIMS_1)                       /*!< 1/4  */
#define LED_DIMMING_STEP_2             (LED_MODE_DIMS_1|LED_MODE_DIMS_0)       /*!< 1/2  */
#define LED_DIMMING_STEP_1             (LED_MODE_DIMS_2)                       /*!< 1    */
/**
  * @}
  */

/** @defgroup LED_Display_MODE LED display Mode
  * @{
  */
#define LED_RMODE_ONOFF                (0x00000000U )                          /*!< On-off mode */
#define LED_RMODE_BRIGHT               (LED_MODE_RMD)                          /*!< Brightness mode */
/**
  * @}
  */

/** @defgroup LED_OPERATION_MODE LED panel operation Mode
  * @{
  */
#define LED_DMODE_NORMAL               (0x00000000U )                          /*!< operate in normal mode */
#define LED_DMODE_DIMMING              (LED_MODE_DMD)                          /*!< operate in dimming mode */
/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup LED_Exported_Functions
  * @{
  */
void LED_Init(LED_InitTypeDef* LED_InitStruct);
void LED_StructInit(LED_InitTypeDef* LED_InitStruct);

void LED_AnalogCmd(uint32_t Cmd);
void LED_Cmd(uint32_t Cmd);

void LED_SetFrameBufferSize(uint32_t Size);
void LED_SetRunningMode(uint32_t Mode, uint32_t Step, uint32_t Interpolator); 
void LED_SetMaximumBright(uint32_t* Brights); 
void LED_SetNode(uint32_t FrameIdx, uint32_t ComIdx, uint32_t SegIdx, uint32_t Bright); 

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

#endif /* __XT32H0XX_LED_H */


