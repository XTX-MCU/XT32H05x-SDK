/**
  ******************************************************************************
  * @file    xt32h0xx_wdtw.h
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file contains all the functions prototypes for the WDTW 
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
#ifndef __XT32H0XX_WDTW_H
#define __XT32H0XX_WDTW_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup WDTW WDTW
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup WDTW_Exported_Constants WDTW Exported Constants
  * @{
  */

/** @defgroup WDTW_Response_Mode WDTW Reponse Mode
  * @{
  */
#define WDTW_RMOD_SYSRST               (0x00000000UL)                          /*!< WDT generate a system reset */
#define WDTW_RMOD_INTRST               (WDT_CR_RMOD)                           /*!< WDT first generate an interruptand if it is not cleared by the time a second timeout occurs then generate a system reset */
#define IS_WDTW_RMOD(MODE)             (((MODE) == WDTW_RMOD_SYSRST)  || \
                                        ((MODE) == WDTW_RMOD_INTRST))
/**
  * @}
  */

/** @defgroup WDTW_ResetPulseWidth WDTW Reset Pulse Width
  * @{
  */

#define WDTW_RPL_2                     (0x00000000UL)                                  /*!< WDT reset pulse length set to 2   pclk cycles */
#define WDTW_RPL_4                     (WDT_CR_RPL_0)                                  /*!< WDT reset pulse length set to 4   pclk cycles */
#define WDTW_RPL_8                     (WDT_CR_RPL_1)                                  /*!< WDT reset pulse length set to 8   pclk cycles */
#define WDTW_RPL_16                    (WDT_CR_RPL_1 | WDT_CR_RPL_0)                   /*!< WDT reset pulse length set to 16  pclk cycles */
#define WDTW_RPL_32                    (WDT_CR_RPL_2)                                  /*!< WDT reset pulse length set to 32  pclk cycles */
#define WDTW_RPL_64                    (WDT_CR_RPL_2 | WDT_CR_RPL_0)                   /*!< WDT reset pulse length set to 64  pclk cycles */
#define WDTW_RPL_128                   (WDT_CR_RPL_2 | WDT_CR_RPL_1)                   /*!< WDT reset pulse length set to 128 pclk cycles */
#define WDTW_RPL_256                   (WDT_CR_RPL_2 | WDT_CR_RPL_1 | WDT_CR_RPL_0)    /*!< WDT reset pulse length set to 256 pclk cycles */
#define IS_WDTW_RPL(RPL)             (((RPL) == WDTW_RPL_2)  || \
                                      ((RPL) == WDTW_RPL_4)  || \
                                      ((RPL) == WDTW_RPL_8)  || \
                                      ((RPL) == WDTW_RPL_16) || \
                                      ((RPL) == WDTW_RPL_32) || \
                                      ((RPL) == WDTW_RPL_64) || \
                                      ((RPL) == WDTW_RPL_128) || \
                                      ((RPL) == WDTW_RPL_256))
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup WDTW_Exported_Functions
  * @{
  */

/** @addtogroup WDTW_Exported_Functions_Group1
  * @{
  */
/* Counter configuration functions ******************************/
void WDTW_SetResponseMode(uint32_t WDTW_ResponseMode);
void WDTW_SetResetPulseWidth(uint32_t WDTW_ResetPulseWidth);
void WDTW_SetInitialRange(uint32_t WDTW_Range);
void WDTW_SetRestartRange(uint32_t WDTW_Range);
/**
  * @}
  */

/** @addtogroup WDTW_Exported_Functions_Group2
  * @{
  */
/* WDTW activation function ***************************************************/
void WDTW_Enable(void);
void WDTW_Disable(void);
void WDTW_Restart(void);
uint32_t WDTW_GetCurrentValue(void);
/**
  * @}
  */

/** @addtogroup WDTW_Exported_Functions_Group3
  * @{
  */
/* Interrupt management function ***************************************************/
uint32_t WDTW_ClearIT(void);
uint32_t WDTW_GetITFlag(void);
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

#endif /* __XT32H0XX_WDTW_H */


