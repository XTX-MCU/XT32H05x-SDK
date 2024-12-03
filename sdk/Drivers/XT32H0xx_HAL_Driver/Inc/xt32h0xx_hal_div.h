/**
  ******************************************************************************
  * @file    xt32h0xx_hal_div.h
  * @author  Software Team
  * @brief   Header file of DIV HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_DIV_H
#define XT32H0xx_HAL_DIV_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup DIV
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup DIV_Exported_Types DIV Exported Types
  * @{
  */

/**
  * @brief  DIV HAL State Structure definition
  */
typedef enum
{
  HAL_DIV_STATE_RESET     = 0x00U,  /*!< DIV not yet initialized or disabled */
  HAL_DIV_STATE_READY     = 0x01U,  /*!< DIV initialized and ready for use   */
  HAL_DIV_STATE_BUSY      = 0x02U,  /*!< DIV internal process is ongoing     */
  HAL_DIV_STATE_TIMEOUT   = 0x03U,  /*!< DIV timeout state                   */
  HAL_DIV_STATE_ERROR     = 0x04U   /*!< DIV error state                     */
} HAL_DIV_StateTypeDef;

/**
  * @brief  DIV Handle Structure definition
  */
typedef struct
{
  DIV_TypeDef                 *Instance;   /*!< Register base address        */

  HAL_LockTypeDef             Lock;        /*!< DIV Locking object           */

  __IO HAL_DIV_StateTypeDef   State;       /*!< DIV communication state      */
	
	uint8_t                     dumy[2];

} DIV_HandleTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup DIV_Exported_Constants DIV Exported Constants
  * @{
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup DIV_Exported_Macros DIV Exported Macros
  * @{
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup DIV_Exported_Functions DIV Exported Functions
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
/** @defgroup DIV_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
HAL_StatusTypeDef HAL_DIV_Init(DIV_HandleTypeDef *hdiv);
HAL_StatusTypeDef HAL_DIV_DeInit(DIV_HandleTypeDef *hdiv);
void HAL_DIV_MspInit(DIV_HandleTypeDef *hdiv);
void HAL_DIV_MspDeInit(DIV_HandleTypeDef *hdiv);
/**
  * @}
  */

/* Peripheral Control functions ***********************************************/
/** @defgroup DIV_Exported_Functions_Group2 Peripheral Control functions
  * @{
  */
HAL_StatusTypeDef HAL_DIV_Calculate(DIV_HandleTypeDef *hdiv, uint32_t divA, uint32_t divB, uint32_t* pdivQ, uint32_t* pdivR);

/**
  * @}
  */

/* Peripheral State and Error functions ***************************************/
/** @defgroup DIV_Exported_Functions_Group3 Peripheral State functions
  * @{
  */
HAL_DIV_StateTypeDef HAL_DIV_GetState(DIV_HandleTypeDef *hdiv);
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

#endif /* XT32H0xx_HAL_DIV_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
