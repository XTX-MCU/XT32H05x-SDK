/**
  ******************************************************************************
  * @file    xt32t0xx_evb_ts.h
  * @author  Software Team
  * @brief   Header for xt32t0xx_evb_ts.c
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32T0XX_EVB_TS_H
#define XT32T0XX_EVB_TS_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup BSP
  * @{
  */

/** @defgroup XT32T0XX_EVB XT32H0XX_EVB
  * @{
  */

/** @defgroup XT32T0XX_EVB_TS XT32H0XX_EVB_TS
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"
#include "xt32h0xx_ll_system.h"

/** @defgroup XT32H0XX_EVB_Exported_Types Exported Types
  * @{
  */ 
//typedef struct 
//{
//  
//} TS_TypeDef;

/**
  * @}
  */ 

/** @defgroup XT32T0XX_EVB_TS_Exported_Constants Exported Constants
  * @{
  */ 

/** @defgroup XT32T0XX_EVB_TS_Status TS Status Constants
  * @{
  */
#define TS_OK                          0x00
#define TS_ERROR                       0x01
#define TS_TIMEOUT                     0x02
/**
  * @}
  */ 
  
/**
  * @}
  */ 

/** @defgroup XT32T0XX_EVB_Exported_Functions Exported Functions
  * @{
  */

/** @defgroup XT32T0XX_EVB_TS_Functions  TS Functions
  * @{
  */   
void             BSP_TS_Init(void);
void             BSP_TS_DeInit(void);

uint32_t             BSP_TS_Key(uint32_t Key);
uint32_t             BSP_TS_Slider(void);
uint32_t             BSP_TS_Wheel(void);

void             BSP_TS_WriteRawData(uint16_t* pData, uint16_t size);
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

/**
  * @}
  */ 

#ifdef __cplusplus
}
#endif

#endif /* XT32T0XX_EVB_TS_H */

    
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

