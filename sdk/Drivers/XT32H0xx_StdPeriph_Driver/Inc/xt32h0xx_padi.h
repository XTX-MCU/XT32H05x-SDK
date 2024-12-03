/**
  ******************************************************************************
  * @file    xt32h0xx_padi.h
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file contains all the functions prototypes for the PAD firmware 
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
#ifndef __XT32H0XX_PADI_H
#define __XT32H0XX_PADI_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup PADI
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup PADI_Exported_Types PADI Exported Types
  * @{
  */
/**
  * @brief   PAD Init structure definition
  */
typedef struct
{
  uint32_t Pad;                  /*!< Specifies the PADI pads to be configured.
                                      This parameter can be any value of 0 to 63 */
        
  uint32_t Pull;                 /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                                      This parameter can be a value of @ref PADI_PullMode no used */
        
  uint32_t Alternate;            /*!< Peripheral to be connected to the selected pins
                                      This parameter can be a value of @ref PADI_Cfg no-used*/

  uint32_t DriveStrength;        /*!< Specifies the PADI pins to be configured.
                                      This parameter can be any value of @ref PADI_DriveStrengh  */
} PADI_InitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup PADI_Exported_Constants PADI Exported Constants
  * @{
  */

/** @defgroup PADI_Cfg PADI Confgiure
  * @brief   
  * @{
  */
#define PADI_CFG_0                     (0x00000000UL)                          /*!< config 0 */
#define PADI_CFG_1                     (0x00000001UL)                          /*!< config 1 */
#define PADI_CFG_2                     (0x00000002UL)                          /*!< config 2 */
#define PADI_CFG_3                     (0x00000003UL)                          /*!< config 3 */
#define PADI_CFG_4                     (0x00000004UL)                          /*!< config 4 */
#define PADI_CFG_5                     (0x00000005UL)                          /*!< config 5 */
#define PADI_CFG_6                     (0x00000006UL)                          /*!< config 6 */

#define IS_PADI_CFG(CFG)               (((CFG) == PADI_CFG_0) || \
                                        ((CFG) == PADI_CFG_1) || \
                                        ((CFG) == PADI_CFG_2) || \
                                        ((CFG) == PADI_CFG_3) || \
                                        ((CFG) == PADI_CFG_4) || \
                                        ((CFG) == PADI_CFG_5) || \
                                        ((CFG) == PADI_CFG_6))
/**
  * @}
  */

/** @defgroup PADI_PullMode PADI Pull Mode
  * @{
  */
#define PADI_PULLNONE                  (0x00000000U)                           /*!< None pull */
#define PADI_PULLUP                    (0x00000001U)                           /*!< Pull up */
#define PADI_PULLDOWN                  (0x00000002U)                           /*!< Pull down */

#define IS_PADI_PULL(MODE)             (((MODE) == PADI_PULLNONE) || \
                                        ((MODE) == PADI_PULLUP)   || \
                                        ((MODE) == PADI_PULLDOWN))
/**
  * @}
  */

/** @defgroup PADI_DriveStrengh PADI Drive Strengh
  * @{
  */
#define PADI_DS_LOW                    (0x00000000U)                           /*!< Driver strengh low */
#define PADI_DS_HIGH                   (0x00000001U)                           /*!<  Driver strengh high */

#define IS_PADI_DS(DS)                 (((DS) == PADI_DS_LOW) || \
                                        ((DS) == PADI_DS_HIGH))
/**
  * @}
  */

/** @defgroup PADI_Definition PADI define
  * @{
  */
#if defined(XT32H0xxAMPW)
#include "xt32h0xxampw_padi.h"
#elif defined(XT32H0xxBMPW)
#include "xt32h0xxbmpw_padi.h"
#elif defined(XT32H0xxB)
#include "xt32h0xxb_padi.h"
#endif /* XT32H0xxB */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup PADI_Exported_Macros PADI Exported Macros
  * @{
  */
/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */
/** @addtogroup PADI_Exported_Functions
  * @{
  */
/* Initialization and Configuration functions *********************************/
void PADI_Init(PADI_InitTypeDef *PADI_InitStruct);
void PADI_StructInit(PADI_InitTypeDef *PADI_InitStruct);

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

#endif /* __XT32H0XX_PADI_H */


