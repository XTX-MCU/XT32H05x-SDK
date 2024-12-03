/**
  ******************************************************************************
  * @file    xt32h0xx_hal_tim_port.h
  * @author  Software Team
  * @brief   Header file of TIM HAL port module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_TIM_PORT_H
#define XT32H0xx_HAL_TIM_PORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup TIMPort
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup TIMPort_Exported_Types TIMPort Exported Types
  * @{
  */
/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup TIMPort_Exported_Constants TIMPort Exported Constants
  * @{
  */
/** @defgroup TIMPort_Channel TIMPort Channel
  * @{
  */
#define TIM_PORT_CHANNEL_1                      0x00000000U                          /*!< Capture/compare channel 1 identifier      */
#define TIM_PORT_CHANNEL_2                      0x00000004U                          /*!< Capture/compare channel 2 identifier      */
#define TIM_PORT_CHANNEL_3                      0x00000008U                          /*!< Capture/compare channel 3 identifier      */
#define TIM_PORT_CHANNEL_4                      0x0000000CU                          /*!< Capture/compare channel 4 identifier      */
#define TIM_PORT_CHANNEL_5                      0x00000010U                          /*!< Compare channel 5 identifier              */
#define TIM_PORT_CHANNEL_6                      0x00000014U                          /*!< Compare channel 6 identifier              */

#define TIM_PORT_BRK_OUT                        0x00010000U                          /*!< Break out 1 identifier                    */
#define TIM_PORT_BRK2_OUT                       0x00020000U                          /*!< Break out 2 identifier                    */
#define TIM_PORT_BRK_IN                         0x00100000U                          /*!< Break in 1 identifier                     */
#define TIM_PORT_BRK2_IN                        0x00200000U                          /*!< Break in 2 identifier                     */
#define TIM_PORT_ETR                            0x01000000U                          /*!< ETR identifier                            */

/**
  * @}
  */
/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/** @defgroup TIMPort_Exported_Macros TIMPort Exported Macros
  * @{
  */
/**
  * @}
  */
/* End of exported macros ----------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup TIMPort_Private_Constants TIMPort Private Constants
  * @{
  */
/**
  * @}
  */
/* End of private constants --------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/** @defgroup TIMPort_Private_Macros TIMPort Private Macros
  * @{
  */
#define IS_TIMPORT_CHANNELS(__CHANNEL__)   (((__CHANNEL__) == TIM_PORT_CHANNEL_1) || \
                                            ((__CHANNEL__) == TIM_PORT_CHANNEL_2) || \
                                            ((__CHANNEL__) == TIM_PORT_CHANNEL_3) || \
                                            ((__CHANNEL__) == TIM_PORT_CHANNEL_4) || \
                                            ((__CHANNEL__) == TIM_PORT_CHANNEL_5) || \
                                            ((__CHANNEL__) == TIM_PORT_CHANNEL_6) || \
                                            ((__CHANNEL__) == TIM_PORT_BRK_OUT)   || \
                                            ((__CHANNEL__) == TIM_PORT_BRK2_OUT)  || \
                                            ((__CHANNEL__) == TIM_PORT_BRK_IN)    || \
                                            ((__CHANNEL__) == TIM_PORT_BRK2_IN)   || \
                                            ((__CHANNEL__) == TIM_PORT_ETR))
/**
  * @}
  */
/* End of private macros -----------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup TIMPort_Exported_Functions TIMPort Exported Functions
  * @{
  */
/** @defgroup TIMPort_Exported_Functions_Group1 TIMPort Peripheral Port functions
  *  @brief  Peripheral Poet functions
  * @{
  */
/* Peripheral port functions  ************************************************/
HAL_StatusTypeDef HAL_TIM_OutputPortConfig(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
HAL_StatusTypeDef HAL_TIM_InputPortConfig(TIM_TypeDef* dstTim, TIM_TypeDef *srcTim, uint32_t Channel, uint32_t Pad);

HAL_StatusTypeDef HAL_TIM_ForcePortOn(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
HAL_StatusTypeDef HAL_TIM_ForcePortOff(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);

HAL_StatusTypeDef HAL_TIM_SwitchtoPWMPort(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
/**
  * @}
  */
/**
  * @}
  */
/* End of exported functions -------------------------------------------------*/

/* Private functions----------------------------------------------------------*/
/** @defgroup TIMPort_Private_Functions TIMPort Private Functions
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

#endif /* XT32H0xx_HAL_TIM_PORT_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
