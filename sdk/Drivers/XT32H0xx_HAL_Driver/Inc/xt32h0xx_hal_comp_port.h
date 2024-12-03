/**
  ******************************************************************************
  * @file    xt32h0xx_hal_comp_port.h
  * @author  Software Team
  * @brief   Header file of COMP HAL port module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_COMP_PORT_H
#define XT32H0xx_HAL_COMP_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup COMPPort
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup COMPPort_Exported_Types COMPPort Exported Types
  * @{
  */
/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup COMPPort_Exported_Constants COMPPort Exported Constants
  * @{
  */
/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/** @defgroup COMPPort_Exported_Macros COMPPort Exported Macros
  * @{
  */
/**
  * @}
  */
/* End of private constants --------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/* End of private macros -----------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup COMPPort_Exported_Functions
  * @{
  */
/** @addtogroup COMPPort_Exported_Functions_Group1
  *  @brief  Peripheral Port functions
  * @{
  */
/* Peripheral port functions  ************************************************/
HAL_StatusTypeDef HAL_COMP_InputPortConfig(uint32_t Channel);
HAL_StatusTypeDef HAL_COMP_OutputPortConfig(uint32_t Channel);
/**
  * @}
  */

/**
  * @}
  */
/* End of exported functions -------------------------------------------------*/

/* Private functions----------------------------------------------------------*/
/** @defgroup COMPPort_Private_Functions COMPPort Private Functions
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

#endif /* XT32H0xx_HAL_COMP_PORT_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
