/**
  ******************************************************************************
  * @file    xt32h0xx_hal_timr.h
  * @author  Software Team
  * @brief   Header file of TIM HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_TIMR_H
#define XT32H0xx_HAL_TIMR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"
//#include "xt32h0xx_ll_timr.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup TIMR
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup TIMR_Exported_Types TIMR Exported Types
  * @{
  */

/**
  * @brief  TIMR Time base Configuration Structure definition
  */
typedef struct
{
  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref TIMR_MODE */

  uint32_t LoadCount;         /*!< Specifies the load count.
                                   This parameter can be a value between 0 to 0xFFFFFFFF (based on TIMER_WIDTH) */
} TIMR_Base_InitTypeDef;

/**
  * @brief  HAL State structures definition
  */
typedef enum
{
  HAL_TIMR_STATE_RESET             = 0x00U,    /*!< Peripheral not yet initialized or disabled  */
  HAL_TIMR_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use    */
  HAL_TIMR_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing              */
  HAL_TIMR_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state                               */
  HAL_TIMR_STATE_ERROR             = 0x04U     /*!< Reception process is ongoing                */
} HAL_TIMR_StateTypeDef;

/**
  * @brief  TIMR Channel States definition
  */
typedef enum
{
  HAL_TIMR_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM Channel initial state                         */
  HAL_TIMR_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM Channel ready for use                         */
  HAL_TIMR_CHANNEL_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing on the TIM channel */
} HAL_TIMR_ChannelStateTypeDef;

/**
  * @brief  HAL Active channel structures definition
  */
typedef enum
{
  HAL_TIMR_ACTIVE_CHANNEL_0        = 0x01U,    /*!< The active channel is 0     */
  HAL_TIMR_ACTIVE_CHANNEL_1        = 0x02U,    /*!< The active channel is 1     */
  HAL_TIMR_ACTIVE_CHANNEL_2        = 0x04U,    /*!< The active channel is 2     */
  HAL_TIMR_ACTIVE_CHANNEL_3        = 0x08U,    /*!< The active channel is 3     */
  HAL_TIMR_ACTIVE_CHANNEL_4        = 0x10U,    /*!< The active channel is 4     */
  HAL_TIMR_ACTIVE_CHANNEL_5        = 0x20U,    /*!< The active channel is 5     */
  HAL_TIMR_ACTIVE_CHANNEL_6        = 0x40U,    /*!< The active channel is 6     */
  HAL_TIMR_ACTIVE_CHANNEL_7        = 0x80U,    /*!< The active channel is 7     */
  HAL_TIMR_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< All active channels cleared */
} HAL_TIMR_ActiveChannel;

/**
  * @brief  TIMR Time Base Handle Structure definition
  */
#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
typedef struct __TIMR_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */
{
  TIMR_TypeDef                         *Instance;         /*!< Register base address                             */
  TIMR_Base_InitTypeDef                Init;              /*!< TIM Time Base required parameters                 */

  HAL_LockTypeDef                      Lock;              /*!< Locking object                                    */
  __IO HAL_TIMR_StateTypeDef           State;             /*!< TIM operation state                               */
	
	uint8_t                              dumy[2];

#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
  void (* Base_MspInitCallback)(struct __TIMR_HandleTypeDef *htim);              /*!< TIM Base Msp Init Callback                              */
  void (* Base_MspDeInitCallback)(struct __TIMR_HandleTypeDef *htim);            /*!< TIM Base Msp DeInit Callback                            */
  void (* Tim_Callback)(struct __TIMR_HandleTypeDef *htim);            /*!< TIM Base Msp DeInit Callback                            */
#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */
} TIMR_HandleTypeDef;

#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL TIMR Callback ID enumeration definition
  */
typedef enum
{
  HAL_TIMR_BASE_MSPINIT_CB_ID              = 0x00U   /*!< TIM Base MspInit Callback ID                              */
  , HAL_TIMR_BASE_MSPDEINIT_CB_ID          = 0x01U   /*!< TIM Base MspDeInit Callback ID                            */
  , HAL_TIMR_CB_ID                         = 0x02U   /*!< TIM timeout Callback ID                                   */
} HAL_TIMR_CallbackIDTypeDef;

/**
  * @brief  HAL TIMR Callback pointer definition
  */
typedef  void (*pTIMR_CallbackTypeDef)(TIMR_HandleTypeDef *htim);  /*!< pointer to the TIM callback function */

#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */

/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup TIMR_Exported_Constants TIMR Exported Constants
  * @{
  */

/** @defgroup TIMR_MODE Timer mode
  * @{
  */
#define TIME_MODE_FREERUNNING          (0)                                     /*!< Free-runningmode */
#define TIME_MODE_USERDEFINED          (TIMR_CR_MODE)                          /*!< User-defined count mode */
/**
  * @}
  */

/** @defgroup TIMR_ENABLE Timer enable
  * @{
  */
#define TIME_DISABLE                   (0)                                     /*!< Timer disabled */
#define TIME_ENABLE                    (TIMR_CR_EN)                            /*!< Timer enabled  */
/**
  * @}
  */

/** @defgroup TIMR_IT_MASK Interrupt mask
  * @{
  */
#define TIME_IT_UNMASK                 (0)                                     /*!< Unmask interrupt */
#define TIME_IT_MASK                   (TIMR_CR_IM)                            /*!< Mask interrupt   */
/**
  * @}
  */

/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/** @defgroup TIMR_Exported_Macros TIMR Exported Macros
  * @{
  */

/** @brief  Reset TIM handle state.
  * @param  __HANDLE__ TIM handle.
  */
#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
#define __HAL_TIMR_RESET_HANDLE_STATE(__HANDLE__) do {                                                               \
                                                      (__HANDLE__)->State            = HAL_TIMR_STATE_RESET;         \
                                                      (__HANDLE__)->Base_MspInitCallback         = NULL;            \
                                                      (__HANDLE__)->Base_MspDeInitCallback       = NULL;            \
                                                      (__HANDLE__)->Tim_Callback                 = NULL;            \
                                                     } while(0)
#else
#define __HAL_TIMR_RESET_HANDLE_STATE(__HANDLE__) do {                                                               \
                                                      (__HANDLE__)->State            = HAL_TIMR_STATE_RESET;         \
                                                     } while(0)
#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */

/**
  * @brief  Enable the TIM peripheral.
  * @param  __HANDLE__ TIM handle
  */
#define __HAL_TIMR_ENABLE(__HANDLE__)            ((__HANDLE__)->Instance->CR |= (TIMR_CR_EN))

/**
  * @brief  Disable the TIM peripheral.
  * @param  __HANDLE__ TIM handle
  */
#define __HAL_TIMR_DISABLE(__HANDLE__)           ((__HANDLE__)->Instance->CR &= ~(TIMR_CR_EN)) 

/** @brief  Unmask the specified TIM interrupt.
  * @param  __HANDLE__ specifies the TIM Handle.
  */
#define __HAL_TIMR_UNMASK_IT(__HANDLE__)         ((__HANDLE__)->Instance->CR &= ~(TIMR_CR_IM))

/** @brief  Mask the specified TIM interrupt.
  * @param  __HANDLE__ specifies the TIM Handle.
  */
#define __HAL_TIMR_MASK_IT(__HANDLE__)           ((__HANDLE__)->Instance->CR |= (TIMR_CR_IM))

/** @brief  Clear the specified TIM interrupt flag.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @retval None.
  */
#define __HAL_TIMR_CLEAR_FLAG(__HANDLE__)        ((__HANDLE__)->Instance->EOI)

/** @brief  Clear the specified TIM interrupt flag.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @retval The new state  (TRUE or FALSE).
  */
#define __HAL_TIMR_GET_IT(__HANDLE__)            ((__HANDLE__)->Instance->STAT)

/** @brief Clear the TIM interrupt pending bits.
  * @param  __HANDLE__ TIM handle
  */
#define __HAL_TIMR_CLEAR_IT(__HANDLE__)          ((__HANDLE__)->Instance->EOI)

/**
  * @brief  Set the TIM Counter Register value on runtime.
  * @param  __HANDLE__ TIM handle.
  * @param  __COUNTER__ specifies the Counter register new value.
  */
#define __HAL_TIMR_SET_LOADCOUNT(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->LC = (__COUNTER__))

/**
  * @brief  Get the TIM Counter Register value on runtime.
  * @param  __HANDLE__ TIM handle.
  * @retval 16-bit or 32-bit value of the timer counter register (TIMx_LC)
  */
#define __HAL_TIMR_GET_LOADCOUNT(__HANDLE__)  ((__HANDLE__)->Instance->LC)

/**
  * @brief  Get the TIM Counter Register value on runtime.
  * @param  __HANDLE__ TIM handle.
  * @retval 16-bit or 32-bit value of the timer counter register (TIMx_CV)
  */
#define __HAL_TIMR_GET_COUNTER(__HANDLE__)  ((__HANDLE__)->Instance->CV)

/**
  * @brief  Set the TIM mode.
  * @param  __HANDLE__ TIM handle.
  * @param  __MODE__ the value can be one of the following values:
  *                  @arg @ref TIME_MODE_FREERUNNING
  *                  @arg @ref TIME_MODE_USERDEFINED
  */
#define __HAL_TIMR_SET_MODE(__HANDLE__, __MODE__)  MODIFY_REG((__HANDLE__)->Instance->CR, TIME_MODE_USERDEFINED,(__MODE__))

/**
  * @brief  Get the TIM sys.
  * @param  __HANDLE__ TIM handle.
  * @retval tim sys
  */
#define __HAL_TIMR_GET_TIMRSYS(__HANDLE__)  (((((__HANDLE__)->Instance) == TIMB11) || \
                                          (((__HANDLE__)->Instance) == TIMB12) || \
																					(((__HANDLE__)->Instance) == TIMB13) || \
																					(((__HANDLE__)->Instance) == TIMB14)) ? \
																					(TIMRSYS1) : (TIMRSYS2))

/**
  * @brief  Get the TIM pos.
  * @param  __HANDLE__ TIM handle.
  * @retval tim pos
  */
#define __HAL_TIMR_GET_POS(__HANDLE__)  ((((__HANDLE__) == TIMB11) || ((__HANDLE__) == TIMB21)) ? 0x00000001UL : \
                                         (((__HANDLE__) == TIMB12) || ((__HANDLE__) == TIMB22)) ? 0x00000002UL : \
                                         (((__HANDLE__) == TIMB13) || ((__HANDLE__) == TIMB23)) ? 0x00000004UL : \
                                         0x00000008UL)

/**
  * @brief  Get the TIM flag.
  * @param  __HANDLE__ TIM handle.
  * @retval status (1 or 0)
  */
#define __HAL_TIMR_GET_FLAG(__HANDLE__) (((((__HANDLE__)->Instance) == TIMB11) || \
                                          (((__HANDLE__)->Instance) == TIMB12) || \
																					(((__HANDLE__)->Instance) == TIMB13) || \
																					(((__HANDLE__)->Instance) == TIMB14)) ? \
																					(((TIMSYSB1)->RSTAT & __HAL_TIMR_GET_POS((__HANDLE__)->Instance)) ? 1UL : 0UL) :\
																					(((TIMSYSB2)->RSTAT & __HAL_TIMR_GET_POS((__HANDLE__)->Instance)) ? 1UL : 0UL))


/**
  * @}
  */
/* End of private constants --------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/** @defgroup TIMR_Private_Macros TIMR Private Macros
  * @{
  */
#define IS_TIMR_COUNTER_MODE(__MODE__)      (((__MODE__) == TIME_MODE_FREERUNNING)              || \
                                            ((__MODE__) == TIME_MODE_USERDEFINED))

#define IS_TIMR_CHANNELS(__CHANNEL__)       (((__CHANNEL__) == TIMR_CHANNEL_0) || \
                                            ((__CHANNEL__) == TIMR_CHANNEL_1) || \
                                            ((__CHANNEL__) == TIMR_CHANNEL_2) || \
                                            ((__CHANNEL__) == TIMR_CHANNEL_3) || \
                                            ((__CHANNEL__) == TIMR_CHANNEL_4) || \
                                            ((__CHANNEL__) == TIMR_CHANNEL_5) || \
                                            ((__CHANNEL__) == TIMR_CHANNEL_6) || \
                                            ((__CHANNEL__) == TIMR_CHANNEL_ALL))

/**
  * @}
  */
/* End of private macros -----------------------------------------------------*/

#include "xt32h0xx_hal_timr_port.h"

/* Exported functions --------------------------------------------------------*/
/** @addtogroup TIMR_Exported_Functions TIM Exported Functions
  * @{
  */

/** @addtogroup TIMR_Exported_Functions_Group1 TIMR Time Base functions
  *  @brief   Time Base functions
  * @{
  */
/* Time Base functions ********************************************************/
HAL_StatusTypeDef HAL_TIMR_Base_Init(TIMR_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMR_Base_DeInit(TIMR_HandleTypeDef *htim);
void HAL_TIMR_Base_MspInit(TIMR_HandleTypeDef *htim);
void HAL_TIMR_Base_MspDeInit(TIMR_HandleTypeDef *htim);
/* Polling */
HAL_StatusTypeDef HAL_TIMR_Base_Start(TIMR_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMR_Base_Stop(TIMR_HandleTypeDef *htim);
/* Interrupt */
HAL_StatusTypeDef HAL_TIMR_Base_Start_IT(TIMR_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMR_Base_Stop_IT(TIMR_HandleTypeDef *htim);

#if defined(XT32H0xxB)
HAL_StatusTypeDef HAL_TIMR_InterruptEnable(TIMR_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIMR_InterruptDisable(TIMR_HandleTypeDef *htim);
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @addtogroup TIMR_Exported_Functions_Group2 TIMR IRQ handler management
  *  @brief   IRQ handler management
  * @{
  */
/* Interrupt Handler functions  ***********************************************/
void HAL_TIMR_IRQHandler(TIMR_HandleTypeDef *htim);
/**
  * @}
  */


/** @defgroup TIMR_Exported_Functions_Group3 TIMR Callbacks functions
  *  @brief   TIM Callbacks functions
  * @{
  */

/* Callbacks Register/UnRegister functions  ***********************************/
void HAL_TIMR_Callback(TIMR_HandleTypeDef *htim);

#if (USE_HAL_TIMR_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_TIMR_RegisterCallback(TIMR_HandleTypeDef *htim, HAL_TIMR_CallbackIDTypeDef CallbackID,
                                           pTIMR_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_TIMR_UnRegisterCallback(TIMR_HandleTypeDef *htim, HAL_TIMR_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_TIMR_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup TIMR_Exported_Functions_Group4 TIMR Peripheral State functions
  *  @brief  Peripheral State functions
  * @{
  */
/* Peripheral State functions  ************************************************/
HAL_TIMR_StateTypeDef HAL_TIMR_Base_GetState(TIMR_HandleTypeDef *htim);

/**
  * @}
  */

/**
  * @}
  */
/* End of exported functions -------------------------------------------------*/

/* Private functions----------------------------------------------------------*/
/** @defgroup TIMR_Private_Functions TIMR Private Functions
  * @{
  */
void TIMR_Base_SetConfig(TIMR_TypeDef *TIMx, TIMR_Base_InitTypeDef *Structure);

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

#endif /* XT32H0xx_HAL_TIMR_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
