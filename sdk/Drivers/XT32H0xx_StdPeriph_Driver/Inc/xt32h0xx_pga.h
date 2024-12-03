/**
  ******************************************************************************
  * @file    xt32h0xx_pga.h
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file contains all the functions prototypes for the MDU PGA firmware 
  *          library
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_PGA_H
#define __XT32H0XX_PGA_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup PGA
  * @{
  */

/* Private contants ----------------------------------------------------------*/
/** @defgroup PGA_Private_Constants PGA Private Constants
  * @{
  */
#define PGA_CHANNEL_NUMBER            (4)
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup PGA_Export_Types PGA Exported Types
  * @{
  */

/** 
  * @brief  PGA Init structure definition
  */
  
typedef struct
{
  uint32_t Gain;                          /*!< Configures PGA Gain.
                                               This parameter can be a value of @ref PGA_EC_Gain */
#if (defined(XT32H0xxBMPW) || defined(XT32H0xxB))
  uint32_t Miller;                        /*!< Configures PGA Miller.
                                               This parameter can be a value of 0 and 1 */
#endif /* XT32H0xxBMPW || XT32H0xxB */
} PGA_ChannelInitTypeDef;

typedef struct
{
  PGA_ChannelInitTypeDef Channel[PGA_CHANNEL_NUMBER];
} PGA_InitTypeDef;
/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/
/** @defgroup PGA_Exported_Constants PGA Exported Constants
  * @{
  */

/** @defgroup PGA_EC_Channel  PGA Channel 
  * @{
  */
#define PGA_0                          (0)
#define PGA_1                          (1)
#define PGA_2                          (2)
#define PGA_3                          (3)

#define IS_PAG_CHANNEL(CHANNEL)        (((CHANNEL) == PGA_0) || \
                                        ((CHANNEL) == PGA_1) || \
                                        ((CHANNEL) == PGA_2) || \
                                        ((CHANNEL) == PGA_3))
/**
  * @}
  */

/** @defgroup PGA_EC_Enable  PGA enable 
  * @{
  */
#define PGA_DISABLE                    (0)                                     /*!< PGA disable */
#define PGA_ENABLE                     (1)                                     /*!< PGA enable */

#define IS_PAG_MODE(MODE)              (((MODE) == PGA_DISABLE) || \
                                        ((MODE) == PGA_ENABLE))
/**
  * @}
  */

/** @defgroup PGA_EC_Gain  PGA gain 
  * @{
  */
#define PGA_GAIN_2                     (0)                                     /*!< PGA gain */
#define PGA_GAIN_3                     (1)                                     /*!< PGA gain */
#define PGA_GAIN_4                     (2)                                     /*!< PGA gain */
#define PGA_GAIN_4P8                   (3)                                     /*!< PGA gain */
#define PGA_GAIN_6                     (4)                                     /*!< PGA gain */
#define PGA_GAIN_8                     (5)                                     /*!< PGA gain */
#define PGA_GAIN_9P6                   (6)                                     /*!< PGA gain */
#define PGA_GAIN_12                    (7)                                     /*!< PGA gain */

#define IS_PAG_GAIN(GAIN)              (((GAIN) == PGA_GAIN_2) || \
                                        ((GAIN) == PGA_GAIN_3) || \
                                        ((GAIN) == PGA_GAIN_4) || \
                                        ((GAIN) == PGA_GAIN_4P8) || \
                                        ((GAIN) == PGA_GAIN_6) || \
                                        ((GAIN) == PGA_GAIN_8) || \
                                        ((GAIN) == PGA_GAIN_9P6) || \
                                        ((GAIN) == PGA_GAIN_12))
/**
  * @}
  */

/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
/** @addtogroup PGA_Exported_Functions
  * @{
  */

/** @addtogroup PGA_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */

/*  Function used to set the ADC configuration to the default reset state *****/
void PGA_DeInit(void);

/* Initialization and Configuration functions *********************************/ 
void PGA_Init(PGA_InitTypeDef* PGA_InitStruct);
void PGA_StructInit(PGA_InitTypeDef* PGA_InitStruct);

/**
  * @}
  */ 

/** @addtogroup PGA_Exported_Functions_Group2
  * @brief    Operation functions
  * @{
  */
void PGA_ChannelEnable(uint32_t Channel);
void PGA_ChannelDisable(uint32_t Channel);

void PGA_SetChannelGain(uint32_t Channel, uint32_t Gain);
uint32_t PGA_GetChannelGain(uint32_t Channel);

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

#endif /*__XT32H0XX_PGA_H */

