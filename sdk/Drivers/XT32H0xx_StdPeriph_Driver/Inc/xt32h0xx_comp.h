/**
  ******************************************************************************
  * @file    xt32h0xx_comp.h
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file contains all the functions prototypes for the COMP firmware 
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
#ifndef __XT32H0XX_COMP_H
#define __XT32H0XX_COMP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup COMP
  * @{
  */

/* Private contants ----------------------------------------------------------*/
/** @defgroup COMP_Private_Contants COMP Private Constants
  * @{
  */
#define COMP_CHANNEL_NUMBER            (4)
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup COMP_Exported_Types COMP Exported Types
  * @{
  */
/**
  * @brief  Comparator structure definition
  */
typedef struct
{
  uint32_t NegativeSource;                /*!< Configures Comparator negative source.
                                               This parameter can be a value of @ref COMP_EC_Negative_Source */

  uint32_t PositiveSource;                /*!< Configures Comparator positive source.
                                               This parameter can be a value of @ref COMP_EC_Positive_Source */

  uint32_t Hysteresis;                    /*!< Configures Comparator Hysteresis.
                                               This parameter can be a value of @ref COMP_EC_Hysteresis */

  uint32_t Spd;                           /*!< Configures Comparator Spd.
                                               This parameter can be a value of @ref COMP_EC_Speed */

  uint32_t OutputPolarity;                /*!< Configures Comparator output polarity.
                                               This parameter can be a value of @ref COMP_EC_Output_Polarity */
}  COMP_ChannelInitTypeDef;

typedef struct
{

  uint32_t OutputFilter;                  /*!< Configures Comparator output filter.
                                               This parameter can be a value of @ref COMP_EC_Output_Filter */
  
  COMP_ChannelInitTypeDef  Channel[COMP_CHANNEL_NUMBER];     /*!< Configures COMP channel 0/1/2/3 
                                                                  The COMP_CHANNEL_NUMBER can be a value of @ref COMP_EC_Channel */

} COMP_InitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup COMP_Exported_Constants COMP Exported Constants
  * @{
  */

/** @defgroup COMP_EC_Channel  Comp channel index
  * @{
  */
#define COMP_0                         (0)
#define COMP_1                         (1)
#define COMP_2                         (2)
#define COMP_3                         (3)

#define IS_COMP_CHANNEL(CHANNEL)       (((CHANNEL) == COMP_0) || \
                                        ((CHANNEL) == COMP_1) || \
                                        ((CHANNEL) == COMP_2) || \
                                        ((CHANNEL) == COMP_3))
/**
  * @}
  */

/** @defgroup COMP_EC_POWER  Comp power 
  * @{
  */
#define COMP_MODE_POWERON              (0)
#define COMP_MODE_POWERDOWN            (1)

#define IS_COMP_POWER(MODE)            (((MODE) == COMP_MODE_POWERON) || \
                                        ((MODE) == COMP_MODE_POWERDOWN))
/**
  * @}
  */


/** @defgroup COMP_EC_Negative_Source  Comp negative source 
  * @{
  */
#define COMP_NEGATIVE_SOURCE_EXTERNAL  (0)
#define COMP_NEGATIVE_SOURCE_DAC0_OUT  (2)
#define COMP_NEGATIVE_SOURCE_DAC1_OUT  (3)

#define IS_COMP_NEGATIVE_SOURCE(SOURCE)    (((SOURCE) == COMP_NEGATIVE_SOURCE_EXTERNAL) || \
                                            ((SOURCE) == COMP_NEGATIVE_SOURCE_DAC0_OUT) || \
                                            ((SOURCE) == COMP_NEGATIVE_SOURCE_DAC1_OUT))
/**
  * @}
  */

/** @defgroup COMP_EC_Positive_Source  Comp positive source 
  * @{
  */
#define COMP_POSITIVE_SOURCE_EXTERNAL  (0)
#define COMP_POSITIVE_SOURCE_INTERNAL  (1)

#define IS_COMP_POSITIVE_SOURCE(SOURCE)    (((SOURCE) == COMP_POSITIVE_SOURCE_EXTERNAL) || \
                                            ((SOURCE) == COMP_POSITIVE_SOURCE_INTERNAL))
/**
  * @}
  */

/** @defgroup COMP_EC_Speed  Comp speed 
  * @{
  */
#define COMP_SPEED_0                   (0)                                     /* low speed */
#define COMP_SPEED_1                   (1)                                     /*  */
#define COMP_SPEED_2                   (2)                                     /*  */
#define COMP_SPEED_3                   (3)                                     /*  */
#define COMP_SPEED_4                   (4)                                     /*  */
#define COMP_SPEED_5                   (5)                                     /*  */
#define COMP_SPEED_6                   (6)                                     /*  */
#define COMP_SPEED_7                   (7)                                     /* high speed */

#define IS_COMP_SPEED(SPEED)           (((SPEED) == COMP_SPEED_0) || \
                                        ((SPEED) == COMP_SPEED_1) || \
                                        ((SPEED) == COMP_SPEED_2) || \
                                        ((SPEED) == COMP_SPEED_3) || \
                                        ((SPEED) == COMP_SPEED_4) || \
                                        ((SPEED) == COMP_SPEED_5) || \
                                        ((SPEED) == COMP_SPEED_6) || \
                                        ((SPEED) == COMP_SPEED_7))
/**
  * @}
  */

/** @defgroup COMP_EC_Hysteresis  Comp Hysteresis 
  * @{
  */
#define COMP_HYSTERESIS_NONE           (0)                                     /* no hysteresis */
#define COMP_HYSTERESIS_10MV           (1)                                     /* 10mV hysteresis */
#define COMP_HYSTERESIS_20MV           (2)                                     /* 20mV hysteresis */
#define COMP_HYSTERESIS_30MV           (3)                                     /* 30mV hysteresis */

#define IS_COMP_HYSTERESIS(HYSTERESIS) (((HYSTERESIS) == COMP_HYSTERESIS_NONE) || \
                                        ((HYSTERESIS) == COMP_HYSTERESIS_10MV) || \
                                        ((HYSTERESIS) == COMP_HYSTERESIS_20MV) || \
                                        ((HYSTERESIS) == COMP_HYSTERESIS_30MV))
/**
  * @}
  */

/** @defgroup COMP_EC_Output_Polarity  Comp polarity 
  * @{
  */
#define COMP_OUTPUT_POLARITY_NORMAL    (0)                                     /*!< normal */
#define COMP_OUTPUT_POLARITY_INVERT    (1)                                     /*!< invert */

#define IS_COMP_OUTPUT_POLARITY(POLARITY)  (((POLARITY) == COMP_OUTPUT_POLARITY_NORMAL) || \
                                            ((POLARITY) == COMP_OUTPUT_POLARITY_INVERT))
/**
  * @}
  */


/** @defgroup COMP_EC_Output_Filter  Comparator output filter 
  * @{
  */
#define COMP_OUTPUT_FILTER_ENABLE      (0)
#define COMP_OUTPUT_FILTER_DISABLE     (MDU_CMPCFG3_OFLT)

#define IS_COMP_OUTPUT_FILTER_MODE(MODE)   (((MODE) == COMP_OUTPUT_FILTER_ENABLE) || \
                                            ((MODE) == COMP_OUTPUT_FILTER_DISABLE))
/**
  * @}
  */
  
/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
/** @addtogroup COMP_Exported_Functions COMP Exported Functions
  * @{
  */

/** @addtogroup COMP_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */

/*  Function used to set the COMP configuration to the default reset state *****/
void COMP_DeInit(void);

/* Initialization and Configuration functions *********************************/ 
void COMP_Init(COMP_InitTypeDef* COMP_InitStruct);
void COMP_StructInit(COMP_InitTypeDef* COMP_InitStruct);


/**
  * @}
  */ 

/** @addtogroup COMP_Exported_Functions_Group2
  * @brief    Operation functions
  * @{
  */
void COMP_Start(uint32_t Channel);
void COMP_Stop(uint32_t Channel);

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

#endif /*__XT32H0XX_COMP_H */


