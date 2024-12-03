/**
  ******************************************************************************
  * @file    xt32h0xx_div.h
  * @author  Software Team
  * @date    29 November 2022
  * @brief   This file contains all the functions prototypes for the DIV firmware 
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
#ifndef __XT32H0XX_DIV_H
#define __XT32H0XX_DIV_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup DIV
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup DIV_Exported_Functions
  * @{
  */
void DIV_Cmd(uint32_t Cmd);
void DIV_Calc(uint32_t divA, uint32_t divB, uint32_t* pdivQ, uint32_t* pdivR);

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

#endif /* __XT32H0XX_DIV_H */


