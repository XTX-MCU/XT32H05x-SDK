/**
  ******************************************************************************
  * @file    xt32h0xx_hal_adc_port.h
  * @author  Software Team
  * @brief   Header file of ADC HAL port module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_ADC_PORT_H
#define XT32H0xx_HAL_ADC_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup ADCPort
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup ADCPort_Exported_Types ADCPort Exported Types
  * @{
  */
/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup ADCPort_Exported_Constants ADCPort Exported Constants
  * @{
  */
/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/** @defgroup ADCPort_Exported_Macros ADCPort Exported Macros
  * @{
  */
/**
  * @}
  */
/* End of private constants --------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/* End of private macros -----------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADCPort_Exported_Functions
  * @{
  */
/** @addtogroup ADCPort_Exported_Functions_Group1
  *  @brief  Peripheral Port functions
  * @{
  */
/* Peripheral port functions  ************************************************/
HAL_StatusTypeDef HAL_ADC_InputPortConfig(uint32_t Channel, uint32_t PIo, uint32_t NIo);
/**
  * @}
  */

/**
  * @}
  */
/* End of exported functions -------------------------------------------------*/

/* Private functions----------------------------------------------------------*/
/** @defgroup ADCPort_Private_Functions ADCPort Private Functions
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

#endif /* XT32H0xx_HAL_ADC_PORT_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
