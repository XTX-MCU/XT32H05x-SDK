/**
  ******************************************************************************
  * @file    xt32h0xx_timr.h
  * @author  Software Team
  * @date    23 June 2022
  * @brief   This file contains all the functions prototypes for the basic timer firmware 
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
#ifndef __XT32H0XX_TIMR_H
#define __XT32H0XX_TIMR_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup TIMR
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup TIMR_Exported_Constants Basic Timer Exported Constants
  * @{
  */

/** @defgroup TIMR_CHANNEL Basic Timer Channel
  * @brief   
  * @{
  */
#define TIMR_CHANNEL_0                 (0x00000001UL)                          /*!< Basic timer channle 0 */
#define TIMR_CHANNEL_1                 (0x00000002UL)                          /*!< Basic timer channle 1 */
#define TIMR_CHANNEL_2                 (0x00000004UL)                          /*!< Basic timer channle 2 */
#define TIMR_CHANNEL_3                 (0x00000008UL)                          /*!< Basic timer channle 3 */

#define IS_TIMR_CHANNEL(CHANNEL)       (((CHANNEL) == TIMR_CHANNEL_0) || \
                                        ((CHANNEL) == TIMR_CHANNEL_1) || \
                                        ((CHANNEL) == TIMR_CHANNEL_2) || \
                                        ((CHANNEL) == TIMR_CHANNEL_3))

/**
  * @}
  */

/** @defgroup TIMR_MODE Basic Timer Mode
  * @{
  */
#define TIMR_MODE_FREERUNNING          (0x00000000U)                           /*!< Free-running mode */
#define TIMR_MODE_USERDEFINED          (TIMR_CR_MODE)                          /*!< user-defined mode */

#define IS_TIMR_MODE(MODE)             (((MODE) == TIMR_MODE_FREERUNNING) || \
                                        ((MODE) == TIMR_MODE_USERDEFINED))
/**
  * @}
  */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup TIMR_Exported_Macros Basic Timer Exported Macros
  * @{
  */
/**
  * @brief  Get timer channel.
  * @param  __HANDLE__ TIM handle
  * @retval TIM Sys
  */
#define TIMR_GET_TIMRCHANNEL(__HANDLE__) ((((__HANDLE__) == (TIMB11)) || \
                                           ((__HANDLE__) == (TIMB21))) ? TIMR_CHANNEL_0 : \
                                          (((__HANDLE__) == (TIMB12)) || \
                                           ((__HANDLE__) == (TIMB22))) ? TIMR_CHANNEL_1 : \
                                          (((__HANDLE__) == (TIMB13)) || \
                                           ((__HANDLE__) == (TIMB23))) ? TIMR_CHANNEL_2 : \
                                          TIMR_CHANNEL_3)

/**
  * @brief  Get timer sys.
  * @param  __HANDLE__ TIM handle
  * @retval TIM Sys
  */
#define TIMR_GET_TIMRSYS(__HANDLE__) ((((__HANDLE__) == (TIMB11)) || \
                                       ((__HANDLE__) == (TIMB12)) || \
                                       ((__HANDLE__) == (TIMB13)) || \
                                       ((__HANDLE__) == (TIMB14))) ? TIMSYSB1 : TIMSYSB2)
/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */
/** @addtogroup TIMR_Exported_Functions 
  * @{
  */
/** @addtogroup TIMR_Exported_Functions_Group1 
  * @{
  */
/* Configuration of the basic timer *******************************************/
void TIMR_DeInit(TIMR_TypeDef *TIMx);
void TIMR_SetLoadValue(TIMR_TypeDef *TIMx, uint32_t TIMR_LoadValue);
void TIMR_SetMode(TIMR_TypeDef *TIMx, uint32_t TIMR_Mode); 
/**
  * @}
  */

/** @addtogroup TIMR_Exported_Functions_Group2 
  * @{
  */
/* Basic timer operation ******************************************************/
void TIMR_Enable(TIMR_TypeDef *TIMx);
void TIMR_Disable(TIMR_TypeDef *TIMx);
void TIMR_Start(TIMR_TypeDef *TIMx);
void TIMR_Stop(TIMR_TypeDef *TIMx);
uint32_t TIMR_GetCurrentValue(TIMR_TypeDef *TIMx);
/**
  * @}
  */

/** @addtogroup TIMR_Exported_Functions_Group3 
  * @{
  */
/* Basic timer interrupt management ******************************************/
void TIMR_MaskIT(TIMR_TypeDef *TIMx);
void TIMR_UnmaskIT(TIMR_TypeDef *TIMx);
uint32_t TIMR_ClearIT(TIMR_TypeDef *TIMx);
uint32_t TIMR_GetITFlag(TIMR_TypeDef *TIMx);

uint32_t TIMR_GetChannleFlag(TIMR_TypeDef *TIMx);
uint32_t TIMR_GetChannleStatus(TIMR_TypeDef *TIMx);
uint32_t TIMR_ClearChannleAllFlag(TIMR_TypeDef *TIMx);
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

#endif /* __XT32H0XX_TIMR_H */


