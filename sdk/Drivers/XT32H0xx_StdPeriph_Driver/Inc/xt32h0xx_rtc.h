/**
  ******************************************************************************
  * @file    xt32h0xx_rtc.h
  * @author  Software Team
  * @date    23 June 2022
  * @brief   This file contains all the functions prototypes for the RTC firmware 
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
#ifndef __XT32H0XX_RTC_H
#define __XT32H0XX_RTC_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup RTC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup RTC_Exported_Functions
  * @{
  */

/** @addtogroup RTC_Exported_Functions_Group1
 * @{
 */
/* Configuration of RTC *******************************************************/
void RTC_DeInit(void);
void RTC_SetMatchValue( uint32_t RTC_MatchValue);
void RTC_SetLoadValue( uint32_t RTC_LoadValue);
void RTC_EnableWrap(void); 
void RTC_DisableWrap(void); 
/**
  * @}
  */

/** @addtogroup RTC_Exported_Functions_Group2
 * @{
 */
/* RTC operation **************************************************************/
void RTC_Enable(void);
void RTC_Disable(void);
uint32_t RTC_GetCurrentValue(void);

/**
  * @}
  */

/** @addtogroup RTC_Exported_Functions_Group3
 * @{
 */
/* RTC interrupt managemaet ***************************************************/
void RTC_EnableIT(void);
void RTC_DisableIT(void);
void RTC_MaskIT(void);
void RTC_UnmaskIT(void);
uint32_t RTC_ClearIT(void);
uint32_t RTC_GetITFlag(void);
uint32_t RTC_GetITStatus(void);

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

#endif /* __XT32H0XX_RTC_H */


