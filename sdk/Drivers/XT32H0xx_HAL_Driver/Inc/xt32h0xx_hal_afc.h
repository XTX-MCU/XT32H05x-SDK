/**
  ******************************************************************************
  * @file    xt32h0xx_hal_afc.h
  * @author  Software Team
  * @brief   Header file of AFC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_AFC_H
#define XT32H0xx_HAL_AFC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup AFC AFC
  * @brief AGC HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup AFC_Exported_Types AFC Exported Types
  * @{
  */
/**
  * @brief  AFC HAL State Structure definition
  */
typedef enum
{
  HAL_AFC_STATE_RESET     = 0x00U,  /*!< AFC not yet initialized or disabled */
  HAL_AFC_STATE_READY     = 0x01U,  /*!< AFC initialized and ready for use   */
  HAL_AFC_STATE_BUSY      = 0x02U,  /*!< AFC internal process is ongoing     */
  HAL_AFC_STATE_TIMEOUT   = 0x03U,  /*!< AFC timeout state                   */
  HAL_AFC_STATE_ERROR     = 0x04U   /*!< AFC error state                     */
} HAL_AFC_StateTypeDef;

/**
  * @brief   AFC Init structure definition
  */
typedef struct
{
  uint32_t ClockSource;             /*!< Specifies the AFC clock source to be configured.
                               This parameter can be any value of @ref AFC_HAL_Clock_Source */

  uint32_t CalibrationTime;          /*!< Specifies the calibration time to be configured.
                               This parameter can be a value between 0 to 0x3FFF */

  uint32_t CalibrationReference;    /*!< Specifies the AFC calibrating difference to be configured.
                               This parameter can be any value between 0 to 0xFF */
	
	uint32_t StandardCount;           /*!< Specifies the AFC calibrating objective to be configured.
                               This parameter can be any value between 0 to 0xFFFFF */
	
	uint32_t InitialValue;       /*!< Specifies the AFC calibrating initial value to be configured.
                               This parameter can be any value between 0 to 0xFF */
	
	uint32_t RefClkDiv;               /*!< Specifies the AFC calibrating reference clock divider to be configured.
                               This parameter can be any value between 0 to 0xFF */
	
} AFC_InitTypeDef;

/**
  * @brief  AFC Handle Structure definition
  */
#if (USE_HAL_AFC_REGISTER_CALLBACKS == 1)
typedef struct __AFC_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_AFC_REGISTER_CALLBACKS */
{
  AFC_TypeDef                 *Instance;   /*!< Register base address        */

  AFC_InitTypeDef             Init;        /*!< AFC configuration parameters */

  HAL_LockTypeDef             Lock;        /*!< AFC Locking object           */

  __IO HAL_AFC_StateTypeDef   State;       /*!< AFC communication state      */

#if (USE_HAL_AFC_REGISTER_CALLBACKS == 1)
  void (* AFC_MspInitCallback)(struct __AFC_HandleTypeDef *hafc);              /*!< AFC Base Msp Init Callback                  */
  void (* AFC_MspDeInitCallback)(struct __AFC_HandleTypeDef *hafc);            /*!< AFC Base Msp DeInit Callback                */
  void (* AFC_EndCallback)(struct __AFC_HandleTypeDef *hafc);                  /*!< AFC End Callback                            */
  void (* AFC_ErrorCallback)(struct __AFC_HandleTypeDef *hafc);                /*!< AFC Error Callback                          */
#endif /* USE_HAL_AFC_REGISTER_CALLBACKS */

} AFC_HandleTypeDef;

#if (USE_HAL_AFC_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL AFC Callback ID enumeration definition
  */
typedef enum
{
  HAL_AFC_MSPINIT_CB_ID                   = 0x00U   /*!< AFC MspInit Callback ID                              */
  , HAL_AFC_MSPDEINIT_CB_ID               = 0x01U   /*!< AFC MspDeInit Callback ID                            */
  , HAL_AFC_END_CB_ID                     = 0x02U   /*!< AFC end Callback ID                                  */
  , HAL_AFC_ERROR_CB_ID                   = 0x03U   /*!< AFC error Callback ID                                */
} HAL_AFC_CallbackIDTypeDef;

/**
  * @brief  HAL AFC Callback pointer definition
  */
typedef  void (*pAFC_CallbackTypeDef)(AFC_HandleTypeDef *hafc);  /*!< pointer to the AFC callback function */

#endif /* USE_HAL_AFC_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup AFC_Exported_Constants AFC Exported Constants
  * @{
  */

/** @defgroup AFC_HAL_Clock_Source  AFC Clock Source
  * @{
  */
#define HAL_AFC_CLKSRC_32K             (0)  
#define HAL_AFC_CLKSRC_16M             (SYSCFG_AFCCTRL_CBCLKS)  
/**
  * @}
  */

/** @defgroup AFC_HAL_Interrupt AFC Interrupt
  * @{
  */
#define HAL_AFC_IT_ERROR               (SYSCFG_AFCCTRL_AEIE)  
#define HAL_AFC_IT_NORMALEND           (SYSCFG_AFCCTRL_ANIE)  
#define HAL_AFC_IT_LOOPEND             (SYSCFG_AFCCTRL_ALIE)  
/**
  * @}
  */

/** @defgroup AFC_HAL_Flag AFC Flag
  * @{
  */
#define HAL_AFC_FLAG_ERROR             (SYSCFG_AFCRES_AEIF)  
#define HAL_AFC_FLAG_NORMALEND         (SYSCFG_AFCRES_ANIF)  
#define HAL_AFC_FLAG_LOOPEND           (SYSCFG_AFCRES_ALIF)  
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup AFC_Exported_Macros AFC Exported Macros
  * @{
  */

/**
  * @brief  AFC enable.
  * @param  __HANDLE__ AFC handle
  * @retval None
  */
#define __HAL_AFC_ENABLE(__HANDLE__)         SET_BIT((__HANDLE__)->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCEN)

/**
  * @brief  AFC disable.
  * @param  __HANDLE__ AFC handle
  * @retval None
  */
#define __HAL_AFC_DISABLE(__HANDLE__)        CLEAR_BIT((__HANDLE__)->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCEN)

/**
  * @brief  AFC interrupt enable.
  * @param  __HANDLE__ AFC handle
  * @param  __IT__ IT 
  *         The parameter can be combined of the following values:
  *           @arg @ref HAL_AFC_IT_ERROR
  *           @arg @ref HAL_AFC_IT_NORMALEND
  *           @arg @ref HAL_AFC_IT_LOOPEND
  * @retval None
  */
#define __HAL_AFC_IT_ENABLE(__HANDLE__, __IT__)      SET_BIT((__HANDLE__)->Instance->AFC_CTRL, __IT__)

/**
  * @brief  AFC interrupt disable.
  * @param  __HANDLE__ AFC handle
  * @param  __IT__ IT 
  *         The parameter can be combined of the following values:
  *           @arg @ref HAL_AFC_IT_ERROR
  *           @arg @ref HAL_AFC_IT_NORMALEND
  *           @arg @ref HAL_AFC_IT_LOOPEND
  * @retval None
  */
#define __HAL_AFC_IT_DISABLE(__HANDLE__, __IT__)      CLEAR_BIT((__HANDLE__)->Instance->AFC_CTRL, __IT__)

/**
  * @brief  AFC not bypass.
  * @param  __HANDLE__ AFC handle
  * @retval None
  */
#define __HAL_AFC_NONBYPASS(__HANDLE__)         CLEAR_BIT((__HANDLE__)->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCBYS)

/**
  * @brief  AFC bypass.
  * @param  __HANDLE__ AFC handle
  * @retval None
  */
#define __HAL_AFC_BYPASS(__HANDLE__)            SET_BIT((__HANDLE__)->Instance->AFC_CTRL, SYSCFG_AFCCTRL_AFCBYS)

/**
  * @brief  AFC set clock source.
  * @param  __HANDLE__ AFC handle
  * @param  __SRCCLK__ calibration clock
  *         The parameter can be one of the following values:
  *           @arg @ref HAL_AFC_CLKSRC_32K
  *           @arg @ref HAL_AFC_CLKSRC_16M
  * @retval None
  */
#define __HAL_AFC_SET_CLKSRC(__HANDLE__, __SRCCLK__)            MODIFY_REG((__HANDLE__)->Instance->AFC_CTRL, SYSCFG_AFCCTRL_CBCLKS, (__SRCCLK__))

/**
  * @brief  AFC get clock source.
  * @param  __HANDLE__ AFC handle
  * @retval calibration clock
  *         The parameter can be one of the following values:
  *           @arg @ref HAL_AFC_CLKSRC_32K
  *           @arg @ref HAL_AFC_CLKSRC_16M
  */
#define __HAL_AFC_GET_CLKSRC(__HANDLE__)            READ_BIT((__HANDLE__)->Instance->AFC_CTRL, SYSCFG_AFCCTRL_CBCLKS)

/**
  * @brief  AFC set calibration referenve.
  * @param  __HANDLE__ AFC handle
  * @param  __REF__ calibration reference
  * @retval None
  */
#define __HAL_AFC_SET_CALIBREF(__HANDLE__, __REF__)            MODIFY_REG((__HANDLE__)->Instance->AFC_CTRL, SYSCFG_AFCCTRL_DIFFCNT, (__REF__)<<SYSCFG_AFCCTRL_DIFFCNT_Pos)

/**
  * @brief  AFC set calibration time.
  * @param  __HANDLE__ AFC handle
  * @param  __TIME__ calibration time
  * @retval None
  */
#define __HAL_AFC_SET_CALIBTIME(__HANDLE__, __TIME__)            MODIFY_REG((__HANDLE__)->Instance->AFC_CTRL, SYSCFG_AFCCTRL_RFCNT, (__TIME__)<<SYSCFG_AFCCTRL_RFCNT_Pos)

/**
  * @brief  AFC set initial control code.
  * @param  __HANDLE__ AFC handle
  * @param  __INIT__ reference clock divider
  * @retval None
  */
#define __HAL_AFC_SET_INITVALUE(__HANDLE__, __INIT__)            MODIFY_REG((__HANDLE__)->Instance->AFC_CFG, SYSCFG_AFCCFG_CBADJ, (__INIT__)<<SYSCFG_AFCCFG_CBADJ_Pos)

/**
  * @brief  AFC set calibration objective.
  * @param  __HANDLE__ AFC handle
  * @param  __OBJ__ calibration objective
  * @retval None
  */
#define __HAL_AFC_SET_CALIBOBJ(__HANDLE__, __OBJ__)            MODIFY_REG((__HANDLE__)->Instance->AFC_CFG, SYSCFG_AFCCFG_STDCNT, (__OBJ__)<<SYSCFG_AFCCFG_STDCNT_Pos)

/**
  * @brief  AFC set reference clock prescaler.
  * @param  __HANDLE__ AFC handle
  * @param  __DIV__ reference clock divider
  * @retval None
  */
#define __HAL_AFC_SET_REFCLK_DIV(__HANDLE__, __DIV__)            MODIFY_REG((__HANDLE__)->Instance->AFC_RES, SYSCFG_AFCRES_RFDIV, (__DIV__)<<SYSCFG_AFCRES_RFDIV_Pos)

/**
  * @brief  AFC get calibration result.
  * @param  __HANDLE__ AFC handle
  * @retval None
  */
#define __HAL_AFC_GET_CALIBRESULT(__HANDLE__)            (READ_BIT((__HANDLE__)->Instance->AFC_RES, SYSCFG_AFCRES_ADJRES) >> SYSCFG_AFCRES_ADJRES_Pos)

/**
  * @brief  AFC get flag.
  * @param  __HANDLE__ AFC handle
  * @param  __FLAG__ AFC flag 
  *         The parameter can be combined of the following values:
  *           @arg @ref HAL_AFC_FLAG_ERROR
  *           @arg @ref HAL_AFC_FLAG_NORMALEND
  *           @arg @ref HAL_AFC_FLAG_LOOPEND
  * @retval State (RESET or SET)
  */
#define __HAL_AFC_GET_FLAG(__HANDLE__, __FLAG__)            (READ_BIT((__HANDLE__)->Instance->AFC_RES, __FLAG__) ? SET : RESET)

/**
  * @brief  AFC clear flag.
  * @param  __HANDLE__ AFC handle
  * @param  __FLAG__ AFC flag 
  *         The parameter can be combined of the following values:
  *           @arg @ref HAL_AFC_FLAG_ERROR
  *           @arg @ref HAL_AFC_FLAG_NORMALEND
  *           @arg @ref HAL_AFC_FLAG_LOOPEND
  * @retval None
  */
#define __HAL_AFC_CLEAR_FLAG(__HANDLE__, __FLAG__)            CLEAR_BIT((__HANDLE__)->Instance->AFC_RES, __FLAG__)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup AFC_Exported_Functions AFC Exported Functions
 *  @brief    AFC Exported Functions
  * @{
  */

/** @defgroup AFC_Exported_Functions_Group1 Initialization/de-initialization functions
 *  @brief    Initialization and Configuration functions
 * @{
 */

/* Initialization and de-initialization functions *****************************/
HAL_StatusTypeDef     HAL_AFC_Init(AFC_HandleTypeDef *hafc);
HAL_StatusTypeDef     HAL_AFC_DeInit(AFC_HandleTypeDef *hafc);
void HAL_AFC_MspInit(AFC_HandleTypeDef *hafcc);
void HAL_AFC_MspDeInit(AFC_HandleTypeDef *hafc);

/**
  * @}
  */

/** @defgroup AFC_Exported_Functions_Group2 operation functions
 *  @brief    Operation functions
 * @{
 */

/* Operation functions *****************************************************/
HAL_StatusTypeDef     HAL_AFC_Start(AFC_HandleTypeDef *hafc);
HAL_StatusTypeDef     HAL_AFC_Stop(AFC_HandleTypeDef *hafc);

uint32_t HAL_AFC_GetAdjustResult(AFC_HandleTypeDef *hafc);


void     HAL_AFC_IRQHandler(AFC_HandleTypeDef *hafc);

void     HAL_AFC_EndCallback(AFC_HandleTypeDef *hafc);
void     HAL_AFC_ErrorCallback(AFC_HandleTypeDef *hafc);
#if (USE_HAL_AFC_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_AFC_RegisterCallback(AFC_HandleTypeDef *hafc, HAL_AFC_CallbackIDTypeDef CallbackID,
                                           pAFC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_AFC_UnRegisterCallback(AFC_HandleTypeDef *hafc, HAL_AFC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_AFC_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup AFC_Exported_Functions_Group3 Peripheral State functions
  * @{
  */
HAL_AFC_StateTypeDef HAL_AFC_GetState(AFC_HandleTypeDef *hafc);
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

#endif /* XT32H0xx_HAL_AFC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
