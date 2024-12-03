/**
  ******************************************************************************
  * @file    xt32h0xx_dac.h
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file contains all the functions prototypes for the DAC firmware 
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
#ifndef __XT32H0XX_DAC_H
#define __XT32H0XX_DAC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup DAC
  * @{
  */

/* Private contants ----------------------------------------------------------*/
/** @defgroup DAC_Private_Contants DAC Private Constants
  * @{
  */
#define DAC_CHANNEL_NUMBER            (2)
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup DAC_Export_Types DAC Exported Types
  * @{
  */

/** 
  * @brief  DAC Init structure definition
  */
typedef struct
{
  uint32_t BufferMode;                   /*!< Configures DAC 0 buffer mode.
                                               This parameter can be a value of @ref DAC_EC_BUFFER_MODE */
} DAC_ChannelInitTypeDef;

typedef struct
{
  uint32_t Refer;                         /*!< Configures DAC reference.
                                               This parameter can be a value of @ref DAC_EC_REF */

  uint32_t ReferVoltageTune;              /*!< Configures DAC reference voltage.
                                               This parameter can be a value of @ref DAC_EC_REFVOL */

  DAC_ChannelInitTypeDef Channel[DAC_CHANNEL_NUMBER];           /*!< Configures DAC channel 0/1 
                                                                     The DAC_CHANNEL_NUMBER can be a value of @ref DAC_EC_Channel */

} DAC_InitTypeDef;
/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/
/** @defgroup DAC_Exported_Contants DAC Exported Constants
  * @{
  */
/** @defgroup DAC_EC_Channel  DAC Channel index 
  * @{
  */
#define DAC_1                          (0)
#define DAC_2                          (1)

#define IS_DAC_CHANNEL(CHANNEL)        (((CHANNEL) == DAC_1) || \
                                        ((CHANNEL) == DAC_2))
/**
  * @}
  */

/** @defgroup DAC_EC_POWER  DAC power mode 
  * @{
  */
#define DAC_POWERON                    (0)                                     /*!< DAC power on */
#define DAC_POWERDOWN                  (MDU_PDCTRL_DACPD)                      /*!< DAC power down */

#define IS_DAC_POWER(MODE)             (((MODE) == DAC_POWERON) || \
                                        ((MODE) == DAC_POWERDOWN))
/**
  * @}
  */

/** @defgroup DAC_EC_REF  DAC reference 
  * @{
  */
#define DAC_REFERENCE_1P2              (0)                                                 /*!< DAC reference */
#define DAC_REFERENCE_2P4              (MDU_DACCFG_REFSEL_0)                               /*!< DAC reference */
#define DAC_REFERENCE_3P6              (MDU_DACCFG_REFSEL_1)                               /*!< DAC reference */
#define DAC_REFERENCE_AVDD             (MDU_DACCFG_REFSEL_1 | MDU_DACCFG_REFSEL_0)         /*!< DAC reference */

#define IS_DAC_REFERENCE(REFERENCE)    (((REFERENCE) == DAC_REFERENCE_1P2) || \
                                        ((REFERENCE) == DAC_REFERENCE_2P4) || \
                                        ((REFERENCE) == DAC_REFERENCE_3P6) || \
                                        ((REFERENCE) == DAC_REFERENCE_AVDD))
/**
  * @}
  */

/** @defgroup DAC_EC_BUFFER_MODE  DAC buffer mode 
  * @{
  */
#define DAC_BUFFER_MODE_NORMAL         (0)                                     /*!< DAC buffer  */
#define DAC_BUFFER_MODE_BYPASS         (1)                                     /*!< DAC 0/1 buffer bypass */

#define IS_DAC_BUFFERMODE(MODE)        (((MODE) == DAC_BUFFER_MODE_NORMAL) || \
                                        ((MODE) == DAC_BUFFER_MODE_BYPASS))
/**
  * @}
  */

/** @defgroup DAC_EC_REFVOL  DAC reference 
  * @{
  */
#define DAC_REFVOL_P57                 (0)                                                                                         /*!< DAC reference */
#define DAC_REFVOL_P58                 (AON_IVREF_CFG_3_DAC_REF_0)                                                                 /*!< DAC reference */
#define DAC_REFVOL_P59                 (AON_IVREF_CFG_3_DAC_REF_1)                                                                 /*!< DAC reference */
#define DAC_REFVOL_P60                 (AON_IVREF_CFG_3_DAC_REF_1 | AON_IVREF_CFG_3_DAC_REF_0)                                     /*!< DAC reference */
#define DAC_REFVOL_P61                 (AON_IVREF_CFG_3_DAC_REF_2)                                                                 /*!< DAC reference */
#define DAC_REFVOL_P62                 (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_0)                                     /*!< DAC reference */
#define DAC_REFVOL_P63                 (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_1)                                     /*!< DAC reference */
#define DAC_REFVOL_P64                 (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_1 | AON_IVREF_CFG_3_DAC_REF_0)         /*!< DAC reference */

#define IS_DAC_REFTUNE(REFERENCE)      (((REFERENCE) == DAC_REFVOL_P57) || \
                                        ((REFERENCE) == DAC_REFVOL_P58) || \
                                        ((REFERENCE) == DAC_REFVOL_P59) || \
                                        ((REFERENCE) == DAC_REFVOL_P60) || \
                                        ((REFERENCE) == DAC_REFVOL_P61) || \
                                        ((REFERENCE) == DAC_REFVOL_P62) || \
                                        ((REFERENCE) == DAC_REFVOL_P63) || \
                                        ((REFERENCE) == DAC_REFVOL_P64))
/**
  * @}
  */

/** @defgroup DAC_EC_InputData  DAC channel imput data 
  * @{
  */
#define IS_DAC_INPUT_DATA(DATA)        (((DATA) >= 0) && ((DATA) <= 0xFF))     /*!< DAC output= DAC_REFERENCE*DATA/255 */
/**
  * @}
  */
  
/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
/** @addtogroup DAC_Exported_Functions
  * @{
  */

/** @addtogroup DAC_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */

/*  Function used to set the DAC configuration to the default reset state *****/
void DAC_DeInit(void);

/* Initialization and Configuration functions *********************************/ 
void DAC_Init(DAC_InitTypeDef* DAC_InitStruct);
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);

/**
  * @}
  */ 

/** @addtogroup DAC_Exported_Functions_Group2
  * @brief    Operation functions
  * @{
  */
void DAC_Start(void);
void DAC_Stop(void);

void DAC_SetValue(uint32_t Channel, uint8_t Data);
uint8_t DAC_GetValue(uint32_t Channel);

void DAC_SetChannelBufferMode(uint32_t Channel, uint32_t Mode);

void DAC_SetReference(uint32_t RefVol);
void DAC_SetTuneReference(uint32_t RefTune);

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

#endif /*__XT32H0XX_DAC_H */


