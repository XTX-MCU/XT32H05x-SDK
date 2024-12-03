/**
  ******************************************************************************
  * @file    xt32h0xx_hal_timr_port.h
  * @author  Software Team
  * @brief   Header file of TIM HAL port module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_TIMR_PORT_H
#define XT32H0xx_HAL_TIMR_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"
//#include "xt32h0xx_ll_timr.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup TIMRPort
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup TIMRPort_Exported_Types TIMRPort Exported Types
  * @{
  */
/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup TIMRPort_Exported_Constants TIMRPort Exported Constants
  * @{
  */
/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/** @defgroup TIMRPort_Exported_Macros TIMRPort Exported Macros
  * @{
  */
/**
  * @}
  */
/* End of private constants --------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/* End of private macros -----------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup TIMRPort_Exported_Functions
  * @{
  */
/** @addtogroup TIMRPort_Exported_Functions_Group1
  *  @brief  Peripheral Port functions
  * @{
  */
/* Peripheral port functions  ************************************************/
HAL_StatusTypeDef HAL_TIMR_OutputPortConfig(TIMR_HandleTypeDef *htim, uint32_t Pad);
HAL_StatusTypeDef HAL_TIMR_InputPortConfig(TIMR_HandleTypeDef *htim, uint32_t Pad);
/**
  * @}
  */

/**
  * @}
  */
/* End of exported functions -------------------------------------------------*/

/* Private functions----------------------------------------------------------*/
/** @defgroup TIMRPort_Private_Functions TIMRPort Private Functions
  * @{
  */
/**
  * @}
  */
/* End of private functions --------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_HAL_TIMR_PORT_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
