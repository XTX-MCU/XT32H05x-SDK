/**
  ******************************************************************************
  * @file    xt32h0xx_hal_dac.h
  * @author  Software Team
  * @brief   Header file of MDU DAC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_DAC_H
#define XT32H0xx_HAL_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/* Include low level driver */
#include "xt32h0xx_ll_dac.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup DAC
  * @{
  */
/* Private contants ----------------------------------------------------------*/
/** @defgroup DAC_Private_Constants DAC Private Constants
  * @{
  */
#define DAC_CHANNEL_NUMBER            (2)
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup DAC_Exported_Types DAC Exported Types
  * @{
  */
/**
  * @brief  DAC structure definition
  */
typedef struct
{
  uint32_t BufferMode;                   /*!< Configures DAC 0 buffer mode.
                                               This parameter can be a value of @ref DAC_HAL_EC_BUFFER_MODE */
} DAC_ChannelInitTypeDef;

typedef struct
{
  uint32_t Refer;                         /*!< Configures DAC reference.
                                               This parameter can be a value of @ref DAC_HAL_EC_REF */

  uint32_t ReferVoltageTune;              /*!< Configures DAC reference voltage.
                                               This parameter can be a value of @ref DAC_HAL_EC_REFVOL */

  DAC_ChannelInitTypeDef Channel[DAC_CHANNEL_NUMBER];           /*!< Configures DAC channel 0/1 */

} DAC_InitTypeDef;

/**
  * @brief  DAC HAL State structures definition
  */
typedef enum
{
  HAL_DAC_STATE_RESET             = 0x00U,  /*!< DAC not yet initialized or disabled  */
  HAL_DAC_STATE_READY             = 0x01U,  /*!< DAC initialized and ready for use    */
  HAL_DAC_STATE_BUSY              = 0x02U,  /*!< DAC internal processing is ongoing   */
  HAL_DAC_STATE_TIMEOUT           = 0x03U,  /*!< DAC timeout state                    */
  HAL_DAC_STATE_ERROR             = 0x04U   /*!< DAC error state                      */

} HAL_DAC_StateTypeDef;


/** 
  * @brief DAC_Error_Code DAC Error Code
  */
#define  HAL_DAC_ERROR_NONE              0x00U    /*!< No error                          */
#define  HAL_DAC_ERROR_DMAUNDERRUNCH1    0x01U    /*!< DAC channel1 DMA underrun error   */
#define  HAL_DAC_ERROR_DMAUNDERRUNCH2    0x02U    /*!< DAC channel2 DMA underrun error   */
#define  HAL_DAC_ERROR_DMA               0x04U    /*!< DMA error                         */
#define  HAL_DAC_ERROR_TIMEOUT           0x08U    /*!< Timeout error                     */
#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
#define HAL_DAC_ERROR_INVALID_CALLBACK   0x10U    /*!< Invalid callback error            */
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */

/**
  * @brief  DAC handle Structure definition
  */
#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
typedef struct __DAC_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */
{
  MDU_TypeDef                 *Instance;     /*!< Register base address             */

  DAC_InitTypeDef             Init;          /*!< DAC initial                       */

  __IO HAL_DAC_StateTypeDef   State;         /*!< DAC communication state           */

  HAL_LockTypeDef             Lock;          /*!< DAC locking object                */
	
	uint8_t                     dumy[2];

  __IO uint32_t               ErrorCode;     /*!< DAC Error code                    */

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
  void (* MspInitCallback)(struct __DAC_HandleTypeDef *hdac);
  void (* MspDeInitCallback)(struct __DAC_HandleTypeDef *hdac);
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */

} DAC_HandleTypeDef;

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL DAC Callback ID enumeration definition
  */
typedef enum
{
  HAL_DAC_MSPINIT_CB_ID                      = 0x08U,  /*!< DAC MspInit Callback ID           */
  HAL_DAC_MSPDEINIT_CB_ID                    = 0x09U,  /*!< DAC MspDeInit Callback ID         */
  HAL_DAC_ALL_CB_ID                          = 0x0AU   /*!< DAC All ID                        */
} HAL_DAC_CallbackIDTypeDef;

/**
  * @brief  HAL DAC Callback pointer definition
  */
typedef void (*pDAC_CallbackTypeDef)(DAC_HandleTypeDef *hdac);
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup DAC_Exported_Constants DAC Exported Constants
  * @{
  */

/** @defgroup DAC_HAL_EC_Index  DAC index 
  * @{
  */
#define DAC_CHANNEL_NUMBER             (2)

#define DAC_1                          (0)
#define DAC_2                          (1)
/**
  * @}
  */

/** @defgroup DAC_HAL_EC_POWER  DAC power mode 
  * @{
  */
#define DAC_POWERON                    (0)                               /*!< DAC power on */
#define DAC_POWERDOWN                  (MDU_PDCTRL_DACPD)                /*!< DAC power down */
/**
  * @}
  */

/** @defgroup DAC_HAL_EC_REF  DAC reference 
  * @{
  */
#define DAC_REFERENCE_1P2              (0)                                                 /*!< DAC reference */
#define DAC_REFERENCE_2P4              (MDU_DACCFG_REFSEL_0)                               /*!< DAC reference */
#define DAC_REFERENCE_3P6              (MDU_DACCFG_REFSEL_1)                               /*!< DAC reference */
#define DAC_REFERENCE_AVDD             (MDU_DACCFG_REFSEL_1 | MDU_DACCFG_REFSEL_0)         /*!< DAC reference */
/**
  * @}
  */

/** @defgroup DAC_HAL_EC_BUFFER_MODE  DAC buffer mode 
  * @{
  */
#define DAC_MODE_NORMAL                (0)                               /*!< DAC buffer  */
#define DAC_1_MODE_BYPASS              (MDU_DACCFG_DAC1BBP)              /*!< DAC 0 buffer bypass */
#define DAC_2_MODE_BYPASS              (MDU_DACCFG_DAC2BBP)              /*!< DAC 1 buffer bypass */
/**
  * @}
  */

/** @defgroup DAC_HAL_EC_REFVOL  DAC reference 
  * @{
  */
#define DAC_REFVOL_P57                 (0)                                                                                         /*!< DAC reference */
#define DAC_REFVOL_P58                 (AON_IVREF_CFG_3_DAC_REF_0)                                                                 /*!< DAC reference */
#define DAC_REFVOL_P59                 (AON_IVREF_CFG_3_DAC_REF_1)                                                                 /*!< DAC reference */
#define DAC_REFVOL_P60                 (AON_IVREF_CFG_3_DAC_REF_1 | AON_IVREF_CFG_3_DAC_REF_0)                                     /*!< DAC reference */
#define DAC_REFVOL_P61                 (AON_IVREF_CFG_3_DAC_REF_2)                                                                 /*!< DAC reference */
#define DAC_REFVOL_P62                 (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_0)                                     /*!< DAC reference */
#define DAC_REFVOL_P63                 (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_1)                                     /*!< DAC reference */
#define DAC_REFVOL_P64                 (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_1 | AON_IVREF_CFG_3_DAC_REF_0)         /*!< DAC reference */
/**
  * @}
  */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/

/** @defgroup DAC_Private_Macros DAC Private Macros
  * @{
  */
#define IS_DAC_MODE(MODE) (((MODE) == DAC_MODE_POWERON) ||\
                           ((MODE) == DAC_MODE_POWERDOWN) )

#define IS_DAC(DAC)  (((DAC) == DAC_1) || \
                      ((DAC) == DAC_2))

#define IS_DAC_REFERENCE(REF)  (((REF) == DAC_REFERENCE_1P2) || \
                                ((REF) == DAC_REFERENCE_2P4) || \
                                ((REF) == DAC_REFERENCE_3P6) || \
                                ((REF) == DAC_REFERENCE_VDD) )

#define IS_DAC_BYPASS(MODE)   (((MODE) == DAC_MODE_NORMAL  ) || \
                               ((MODE) == DAC_1_MODE_BYPASS) || \
                               ((MODE) == DAC_2_MODE_BYPASS) )

#define IS_DAC_REFTUNE(REF)    (((REF) == DAC_REFVOL_P57) || \
                                ((REF) == DAC_REFVOL_P58) || \
                                ((REF) == DAC_REFVOL_P59) || \
                                ((REF) == DAC_REFVOL_P60) || \
                                ((REF) == DAC_REFVOL_P61) || \
                                ((REF) == DAC_REFVOL_P62) || \
                                ((REF) == DAC_REFVOL_P63) || \
                                ((REF) == DAC_REFVOL_P64) )

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup DAC_Exported_Macros DAC Exported Macros
  * @{
  */
/** @brief Reset DAC handle state.
  * @param  __HANDLE__ specifies the DAC handle.
  * @retval None
  */
#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
#define __HAL_DAC_RESET_HANDLE_STATE(__HANDLE__) do {                                                            \
                                                        (__HANDLE__)->State             = HAL_DAC_STATE_RESET;   \
                                                        (__HANDLE__)->MspInitCallback   = NULL;                  \
                                                        (__HANDLE__)->MspDeInitCallback = NULL;                  \
                                                     } while(0)
#else
#define __HAL_DAC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DAC_STATE_RESET)
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */

/**
  * @brief Clear DAC error code (set it to no error code "HAL_DAC_ERROR_NONE").
  * @param __HANDLE__ DAC handle
  * @retval None
  */
#define DAC_CLEAR_ERRORCODE(__HANDLE__) ((__HANDLE__)->ErrorCode = HAL_DAC_ERROR_NONE)

/**
  * @brief DAC poweron.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_DAC_POWERON(__HANDLE__)            (((__HANDLE__)->Instance->PDCTRL) &= (~MDU_PDCTRL_DACPD))

/**
  * @brief DAC powerdown.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_DAC_POWERDOWN(__HANDLE__)          (((__HANDLE__)->Instance->PDCTRL) |= (MDU_PDCTRL_DACPD))

/**
  * @brief DAC check poweron.
  * @param __HANDLE__ MDU handle
  * @retval status SET or RESET
  */
#define __HAL_DAC_ISPOWERON(__HANDLE__)          ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), MDU_PDCTRL_DACPD) == DAC_POWERON) ? SET : RESET)

/**
  * @brief DAC set reference.
  * @param __HANDLE__ MDU handle
  * @param __REF__ reference 
  *        @arg @ref DAC_REFERENCE_1P2 
  *        @arg @ref DAC_REFERENCE_2P4 
  *        @arg @ref DAC_REFERENCE_3P6 
  *        @arg @ref DAC_REFERENCE_AVDD
  * @retval None
  */
#define __HAL_DAC_SETREFERENCE(__HANDLE__, __REF__)            (MODIFY_REG(((__HANDLE__)->Instance->DAC_CFG), MDU_DACCFG_REFSEL, __REF__))

/**
  * @brief DAC get reference.
  * @param __HANDLE__ MDU handle
  * @retval reference
  *        @arg @ref DAC_REFERENCE_1P2 
  *        @arg @ref DAC_REFERENCE_2P4 
  *        @arg @ref DAC_REFERENCE_3P6 
  *        @arg @ref DAC_REFERENCE_AVDD
  */
#define __HAL_DAC_GETREFERENCE(__HANDLE__)            (READ_BIT(((__HANDLE__)->Instance->DAC_CFG), MDU_DACCFG_REFSEL))

/**
  * @brief DAC set add.
  * @param __HANDLE__ MDU handle
  * @param __CH__ DAC channel. This parameter can one of the following values:
  *        @arg @ref DAC_1
  *        @arg @ref DAC_2
  * @param __VAL__ add value
  * @retval None
  */
#define __HAL_DAC_SETADD(__HANDLE__, __CH__, __VAL__)            ((__CH__ == DAC_1) ? MODIFY_REG((__HANDLE__)->Instance->DAC_CFG, MDU_DACCFG_DAC1ADD, (__VAL__ << MDU_DACCFG_DAC1ADD_Pos)) : \
                                                                  MODIFY_REG((__HANDLE__)->Instance->DAC_CFG, MDU_DACCFG_DAC2ADD, (__VAL__ << MDU_DACCFG_DAC2ADD_Pos)))

/**
  * @brief DAC Get add.
  * @param __HANDLE__ MDU handle
  * @param __CH__ DAC channel. This parameter can one of the following values:
  *        @arg @ref DAC_1
  *        @arg @ref DAC_2
  * @retval add value 0 to 0xFF
  */
#define __HAL_DAC_GETADD(__HANDLE__, __CH__)            ((__CH__ == DAC_1) ? (READ_BIT((__HANDLE__)->Instance->DAC_CFG, MDU_DACCFG_DAC1ADD) >> MDU_DACCFG_DAC1ADD_Pos) : \
                                                         (READ_BIT((__HANDLE__)->Instance->DAC_CFG, MDU_DACCFG_DAC2ADD) >> MDU_DACCFG_DAC2ADD_Pos))
/**
  * @brief DAC Bypass enable.
  * @param __HANDLE__ MDU handle
  * @param __CH__ DAC channel. This parameter can one of the following values:
  *        @arg @ref DAC_1
  *        @arg @ref DAC_2
  * @retval None
  */
#define __HAL_DAC_BYPASSENABLE(__HANDLE__, __CH__)            ((__CH__ == DAC_1) ? SET_BIT((__HANDLE__)->Instance->DAC_CFG, MDU_DACCFG_DAC1BBP) : \
                                                                  SET_BIT((__HANDLE__)->Instance->DAC_CFG, MDU_DACCFG_DAC2BBP))

/**
  * @brief DAC Bypass disable.
  * @param __HANDLE__ MDU handle
  * @param __CH__ DAC channel. This parameter can one of the following values:
  *        @arg @ref DAC_1
  *        @arg @ref DAC_2
  * @retval None
  */
#define __HAL_DAC_BYPASSDISABLE(__HANDLE__, __CH__)            ((__CH__ == DAC_1) ? CLEAR_BIT((__HANDLE__)->Instance->DAC_CFG, MDU_DACCFG_DAC1BBP) : \
                                                                  CLEAR_BIT((__HANDLE__)->Instance->DAC_CFG, MDU_DACCFG_DAC2BBP))

/**
  * @brief DAC check bypass.
  * @param __HANDLE__ MDU handle
  * @param __CH__ DAC channel. This parameter can one of the following values:
  *        @arg @ref DAC_1
  *        @arg @ref DAC_2
  * @retval status SET or RESET
  */
#define __HAL_DAC_ISBYPASS(__HANDLE__, __CH__)         ((__CH__ == DAC_1) ? ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), MDU_DACCFG_DAC1BBP) == MDU_DACCFG_DAC1BBP) ? SET : RESET) : \
                                                        ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), MDU_DACCFG_DAC2BBP) == MDU_DACCFG_DAC2BBP) ? SET : RESET))
/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/

/** @addtogroup DAC_Exported_Functions
  * @{
  */
/** @addtogroup DAC_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */
HAL_StatusTypeDef HAL_DAC_Init(DAC_HandleTypeDef *hdac);
HAL_StatusTypeDef HAL_DAC_DeInit(DAC_HandleTypeDef *hdac);
void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac);
void HAL_DAC_MspDeInit(DAC_HandleTypeDef *hdac);

#if (USE_HAL_DAC_REGISTER_CALLBACKS == 1)
/* DAC callback registering/unregistering */
HAL_StatusTypeDef     HAL_DAC_RegisterCallback(DAC_HandleTypeDef *hdac, HAL_DAC_CallbackIDTypeDef CallbackID,
                                               pDAC_CallbackTypeDef pCallback);
HAL_StatusTypeDef     HAL_DAC_UnRegisterCallback(DAC_HandleTypeDef *hdac, HAL_DAC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_DAC_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup DAC_Exported_Functions_Group2
  * @brief    Operation functions
  * @{
  */

HAL_StatusTypeDef HAL_DAC_Start(DAC_HandleTypeDef *hdac);
HAL_StatusTypeDef HAL_DAC_Stop(DAC_HandleTypeDef *hdac);

HAL_StatusTypeDef HAL_DAC_SetValue(DAC_HandleTypeDef *hdac, uint32_t Channel, uint8_t Data);

uint8_t HAL_DAC_GetValue(DAC_HandleTypeDef *hdac, uint32_t Channel);

HAL_StatusTypeDef HAL_DAC_SetChannelBypassBuffer(DAC_HandleTypeDef *hdac, uint32_t Mode);
HAL_StatusTypeDef HAL_DAC_SetReference(DAC_HandleTypeDef *hdac, uint32_t Ref);
HAL_StatusTypeDef HAL_DAC_SetTuneReference(DAC_HandleTypeDef *hdac, uint32_t Ref);

/**
  * @}
  */

/** @addtogroup DAC_Exported_Functions_Group3
  * @brief    Peripheral State functions
  * @{
  */
HAL_DAC_StateTypeDef HAL_DAC_GetState(DAC_HandleTypeDef *hdac);
uint32_t HAL_DAC_GetError(DAC_HandleTypeDef *hdac);
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


#endif /* XT32H0xx_HAL_ADC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
