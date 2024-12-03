/**
  ******************************************************************************
  * @file    xt32h0xx_afc.h
  * @author  Software Team
  * @date    29 November 2022
  * @brief   This file contains all the functions prototypes for the AFC firmware 
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
#ifndef __XT32H0XX_AFC_H
#define __XT32H0XX_AFC_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup AFC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup AFC_Exported_Types AFC Exported Types
  * @{
  */
/**
  * @brief   AFC Init structure definition
  */
typedef struct
{
  uint32_t ClockSource;             /*!< Specifies the AFC clock source to be configured.
                                         This parameter can be any value of @ref AFC_CLKSRC */

  uint32_t CalibrationTime;          /*!< Specifies the calibration time to be configured.
                                          This parameter can be a value between 0 to 0x3FFF */

  uint32_t CalibrationReference;    /*!< Specifies the AFC calibrating difference to be configured.
                                         This parameter can be any value between 0 to 0xFF */
	
	uint32_t StandardCount;           /*!< Specifies the AFC calibrating objective to be configured.
                                         This parameter can be any value between 0 to 0xFFFFF */
	
	uint32_t InitialValue;            /*!< Specifies the AFC calibrating initial value to be configured.
                                         This parameter can be any value between 0 to 0xFF */
	
	uint32_t RefClkDiv;               /*!< Specifies the AFC calibrating reference clock divider to be configured.
                                         This parameter can be any value between 0 to 0xFF */
	
} AFC_InitTypeDef;

/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/
/** @defgroup AFC_Exported_Constants AFC Exported Constants
  * @{
  */

/** @defgroup AFC_CLKSRC AFC Clock Source
  * @{
  */
#define AFC_CLKSRC_32K                 (0)  
#define AFC_CLKSRC_16M                 (SYSCFG_AFCCTRL_CBCLKS)  

#define IS_AFC_CLKSRC(SRC)        (((SRC) == AFC_CLKSRC_32K)  || \
                                   ((SRC) == AFC_CLKSRC_16M))
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup AFC_Exported_Functions
  * @{
  */
void AFC_DeInit(void);
void AFC_Init(AFC_InitTypeDef* AFC_InitStruct);
void AFC_StructInit(AFC_InitTypeDef* AFC_InitStruct);

void AFC_Start(void);
void AFC_Stop(void);
uint32_t AFC_GetResult(void);
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

#endif /* __XT32H0XX_AFC_H */


