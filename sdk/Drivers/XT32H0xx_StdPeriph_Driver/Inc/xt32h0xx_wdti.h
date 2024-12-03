/**
  ******************************************************************************
  * @file    xt32h0xx_wdti.h
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file contains all the functions prototypes for the WDTI 
  *          firmware library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_WDTI_H
#define __XT32H0XX_WDTI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup WDTI
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup WDTI_Exported_Constants WDTI Exported Constants
  * @{
  */

/** @defgroup WDTI_Response_Mode WDTI Response Mode
  * @{
  */
#define WDTI_RMOD_SYSRST               (0x00000000UL)                          /*!< WDT generate a system reset */
#define WDTI_RMOD_INTRST               (WDT_CR_RMOD)                           /*!< WDT first generate an interruptand if it is not cleared by the time a second timeout occurs then generate a system reset */
#define IS_WDTI_RMOD(MODE)             (((MODE) == WDTI_RMOD_SYSRST)  || \
                                        ((MODE) == WDTI_RMOD_INTRST))
/**
  * @}
  */

/** @defgroup WDTI_ResetPulseWidth WDTI Reset Pulse Width
  * @{
  */

#define WDTI_RPL_2                     (0x00000000UL)                                  /*!< WDT reset pulse length set to 2   pclk cycles */
#define WDTI_RPL_4                     (WDT_CR_RPL_0)                                  /*!< WDT reset pulse length set to 4   pclk cycles */
#define WDTI_RPL_8                     (WDT_CR_RPL_1)                                  /*!< WDT reset pulse length set to 8   pclk cycles */
#define WDTI_RPL_16                    (WDT_CR_RPL_1 | WDT_CR_RPL_0)                   /*!< WDT reset pulse length set to 16  pclk cycles */
#define WDTI_RPL_32                    (WDT_CR_RPL_2)                                  /*!< WDT reset pulse length set to 32  pclk cycles */
#define WDTI_RPL_64                    (WDT_CR_RPL_2 | WDT_CR_RPL_0)                   /*!< WDT reset pulse length set to 64  pclk cycles */
#define WDTI_RPL_128                   (WDT_CR_RPL_2 | WDT_CR_RPL_1)                   /*!< WDT reset pulse length set to 128 pclk cycles */
#define WDTI_RPL_256                   (WDT_CR_RPL_2 | WDT_CR_RPL_1 | WDT_CR_RPL_0)    /*!< WDT reset pulse length set to 256 pclk cycles */
#define IS_WDTI_RPL(RPL)             (((RPL) == WDTI_RPL_2)  || \
                                      ((RPL) == WDTI_RPL_4)  || \
                                      ((RPL) == WDTI_RPL_8)  || \
                                      ((RPL) == WDTI_RPL_16) || \
                                      ((RPL) == WDTI_RPL_32) || \
                                      ((RPL) == WDTI_RPL_64) || \
                                      ((RPL) == WDTI_RPL_128) || \
                                      ((RPL) == WDTI_RPL_256))
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup WDTI_Exported_Functions
  * @{
  */

/** @addtogroup WDTI_Exported_Functions_Group1
  * @{
  */
/* Counter configuration functions ******************************/
void WDTI_SetResponseMode(uint32_t WDTI_ResponseMode);
void WDTI_SetResetPulseWidth(uint32_t WDTI_ResetPulseWidth);
void WDTI_SetInitialRange(uint32_t WDTI_Range);
void WDTI_SetRestartRange(uint32_t WDTI_Range);
/**
  * @}
  */

/** @addtogroup WDTI_Exported_Functions_Group2
  * @{
  */
/* WDTI activation function ***************************************************/
void WDTI_Enable(void);
void WDTI_Disable(void);
void WDTI_Restart(void);
uint32_t WDTI_GetCurrentValue(void);
/**
  * @}
  */

/** @addtogroup WDTI_Exported_Functions_Group3
  * @{
  */
/* Interrupt management function ***************************************************/
uint32_t WDTI_ClearIT(void);
uint32_t WDTI_GetITFlag(void);
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

#endif /* __XT32H0XX_WDTI_H */

