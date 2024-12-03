/**
  ******************************************************************************
  * @file    xt32h0xx_hal_pga.h
  * @author  Software Team
  * @brief   Header file of MDU PGA HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_PGA_H
#define XT32H0xx_HAL_PGA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/* Include low level driver */
#include "xt32h0xx_ll_pga.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup PGA
  * @{
  */
/* Private constants ---------------------------------------------------------*/
/** @defgroup PGA_Private_Contants PGA Private Contants
  * @{
  */
#define PGA_CHANNEL_NUMBER            (4)
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup PGA_Exported_Types PGA Exported Types
  * @{
  */

/**
  * @brief  PGA structure definition
  */
typedef struct
{
  uint32_t Mode;                          /*!< Configures PGA mode.
                                               This parameter can be a value of @ref PGA_HAL_EC_MODE */

  uint32_t Gain;                          /*!< Configures PGA Gain.
                                               This parameter can be a value of @ref PGA_HAL_EC_Gain */

//  uint32_t Miller;                        /*!< Configures PGA Miller.
//                                               This parameter can be a value of 0 to 3 */
} PGA_ChannelInitTypeDef;

typedef struct
{
  PGA_ChannelInitTypeDef Channel[PGA_CHANNEL_NUMBER];
} PGA_InitTypeDef;

/** 
  * @brief PGA_Error_Code DAC Error Code
  */
#define  HAL_PGA_ERROR_NONE              0x00U    /*!< No error                          */
#define  HAL_PGA_ERROR_TIMEOUT           0x08U    /*!< Timeout error                     */
#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
#define HAL_PGA_ERROR_INVALID_CALLBACK   0x10U    /*!< Invalid callback error            */
#endif /* USE_HAL_PGA_REGISTER_CALLBACKS */

typedef enum
{
  HAL_PGA_STATE_RESET             = 0x00U,  /*!< DAC not yet initialized or disabled  */
  HAL_PGA_STATE_READY             = 0x01U,  /*!< DAC initialized and ready for use    */
  HAL_PGA_STATE_BUSY              = 0x02U,  /*!< DAC internal processing is ongoing   */
  HAL_PGA_STATE_TIMEOUT           = 0x03U,  /*!< DAC timeout state                    */
  HAL_PGA_STATE_ERROR             = 0x04U   /*!< DAC error state                      */

} HAL_PGA_StateTypeDef;

/**
  * @brief  PGA handle Structure definition
  */
#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
typedef struct __PGA_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_PGA_REGISTER_CALLBACKS */
{
  MDU_TypeDef                 *Instance;     /*!< Register base address             */

  PGA_InitTypeDef             Init;          /*!< PGA initial                       */

  __IO HAL_PGA_StateTypeDef   State;         /*!< PGA communication state           */

  HAL_LockTypeDef             Lock;          /*!< PGA locking object                */

	uint8_t                     dumy[2];
	
  __IO uint32_t               ErrorCode;     /*!< DAC Error code                    */

#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
  void (* MspInitCallback)(struct __PGA_HandleTypeDef *hpga);
  void (* MspDeInitCallback)(struct __PGA_HandleTypeDef *hpga);
#endif /* USE_HAL_PGA_REGISTER_CALLBACKS */

} PGA_HandleTypeDef;

#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL PGA Callback ID enumeration definition
  */
typedef enum
{
  HAL_PGA_MSPINIT_CB_ID                      = 0x00U,  /*!< PGA MspInit Callback ID           */
  HAL_PGA_MSPDEINIT_CB_ID                    = 0x01U,  /*!< PGA MspDeInit Callback ID         */
  HAL_PGA_ALL_CB_ID                          = 0x02U   /*!< PGA All ID                        */
} HAL_PGA_CallbackIDTypeDef;

/**
  * @brief  HAL PGA Callback pointer definition
  */
typedef void (*pPGA_CallbackTypeDef)(PGA_HandleTypeDef *hpga);
#endif /* USE_HAL_PGA_REGISTER_CALLBACKS */

/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/

/** @defgroup PGA_Exported_Constants PGA Exported constants
  * @{
  */
/** @defgroup PGA_HAL_EC_MODE  PGA mode 
  * @{
  */
#define PGA_CHANNEL_NUMBER             (4)

#define PGA_1                          (0)
#define PGA_2                          (1)
#define PGA_3                          (2)
#define PGA_4                          (3)
/**
  * @}
  */

/** @defgroup PGA_HAL_EC_Enable  PGA enable 
  * @{
  */
#define PGA_1_DISABLE                  (0)                               /*!< PGA disable */
#define PGA_1_ENABLE                   (MDU_PDCTRL_PGAEN1)               /*!< PGA enable */
#define PGA_2_DISABLE                  (0)                               /*!< PGA disable */
#define PGA_2_ENABLE                   (MDU_PDCTRL_PGAEN1)               /*!< PGA enable */
#define PGA_3_DISABLE                  (0)                               /*!< PGA disable */
#define PGA_3_ENABLE                   (MDU_PDCTRL_PGAEN1)               /*!< PGA enable */
#define PGA_4_DISABLE                  (0)                               /*!< PGA disable */
#define PGA_4_ENABLE                   (MDU_PDCTRL_PGAEN1)               /*!< PGA enable */
/**
  * @}
  */

/** @defgroup PGA_HAL_EC_Gain  PGA gain 
  * @{
  */
#define PGA_GAIN_2                     (0)                                     /*!< PGA gain */
#define PGA_GAIN_3                     (1)                                     /*!< PGA gain */
#define PGA_GAIN_4                     (2)                                     /*!< PGA gain */
#define PGA_GAIN_5                     (3)                                     /*!< PGA gain */
#define PGA_GAIN_7                     (4)                                     /*!< PGA gain */
#define PGA_GAIN_9                     (5)                                     /*!< PGA gain */
#define PGA_GAIN_11                    (6)                                     /*!< PGA gain */
#define PGA_GAIN_15                    (7)                                     /*!< PGA gain */

/**
  * @}
  */

#if defined(XT32H0xxB)
/** @defgroup PGA_HAL_EC_Source  PGA 0-3 P & N source  
  * @{
  */
#define PGA_1_PSRC_NONE                (0)                                     /*!< PGA 0 P source none */
#define PGA_1_PSRC_MAPTO_IO52          (MDU_CMPCFG3_PGA1_PSRC_0)               /*!< PGA 0 P source io 52 */
#define PGA_1_PSRC_MAPTO_IO45          (MDU_CMPCFG3_PGA1_PSRC_1)               /*!< PGA 0 P source io 45 */
#define PGA_1_PSRC_MAPTO_IO33          (MDU_CMPCFG3_PGA1_PSRC_1 | MDU_CMPCFG3_PGA1_PSRC_0)    /*!< PGA 0 P source io 33 */
#define PGA_1_NSRC_NONE                (0)                                     /*!< PGA 0 N source none */
#define PGA_1_NSRC_MAPTO_IO51          (MDU_CMPCFG3_PGA1_NSRC_1)               /*!< PGA 0 N source io 51 */
#define PGA_1_NSRC_MAPTO_IO34          (MDU_CMPCFG3_PGA1_NSRC_1 | MDU_CMPCFG3_PGA1_NSRC_0)    /*!< PGA 0 N source io 34 */

#define PGA_2_PSRC_NONE                (0)                                     /*!< PGA 1 P source none */
#define PGA_2_PSRC_MAPTO_IO50          (MDU_CMPCFG3_PGA2_PSRC_0)               /*!< PGA 1 P source io 50 */
#define PGA_2_PSRC_MAPTO_IO46          (MDU_CMPCFG3_PGA2_PSRC_1)               /*!< PGA 1 P source io 46 */
#define PGA_2_PSRC_MAPTO_IO31          (MDU_CMPCFG3_PGA2_PSRC_1 | MDU_CMPCFG3_PGA2_PSRC_0)    /*!< PGA 1 P source io 31 */
#define PGA_2_NSRC_NONE                (0)                                     /*!< PGA 1 N source none */
#define PGA_2_NSRC_MAPTO_IO49          (MDU_CMPCFG3_PGA2_NSRC_1)               /*!< PGA 1 N source io 49 */
#define PGA_2_NSRC_MAPTO_IO32          (MDU_CMPCFG3_PGA2_NSRC_1 | MDU_CMPCFG3_PGA2_NSRC_0)    /*!< PGA 1 N source io 32 */

#define PGA_3_PSRC_NONE                (0)                                     /*!< PGA 2 P source none */
#define PGA_3_PSRC_MAPTO_IO58          (MDU_CMPCFG3_PGA3_PSRC_0)               /*!< PGA 2 P source io 58 */
#define PGA_3_PSRC_MAPTO_IO47          (MDU_CMPCFG3_PGA3_PSRC_1)               /*!< PGA 2 P source io 47 */
#define PGA_3_PSRC_MAPTO_IO26          (MDU_CMPCFG3_PGA3_PSRC_1 | MDU_CMPCFG3_PGA3_PSRC_0)    /*!< PGA 2 P source io 26 */
#define PGA_3_NSRC_NONE                (0)                                     /*!< PGA 2 N source none */
#define PGA_3_NSRC_MAPTO_IO57          (MDU_CMPCFG3_PGA3_NSRC_1)               /*!< PGA 2 N source io 57 */
#define PGA_3_NSRC_MAPTO_IO27          (MDU_CMPCFG3_PGA3_NSRC_1 | MDU_CMPCFG3_PGA3_NSRC_0)    /*!< PGA 2 N source io 27 */

#define PGA_4_PSRC_NONE                (0)                                     /*!< PGA 3 P source none */
#define PGA_4_PSRC_MAPTO_IO61          (MDU_CMPCFG3_PGA4_PSRC_0)               /*!< PGA 3 P source io 61 */
#define PGA_4_PSRC_MAPTO_IO48          (MDU_CMPCFG3_PGA4_PSRC_1)               /*!< PGA 3 P source io 48 */
#define PGA_4_PSRC_MAPTO_IO42          (MDU_CMPCFG3_PGA4_PSRC_1 | MDU_CMPCFG3_PGA4_PSRC_0)    /*!< PGA 3 P source io 42 */
#define PGA_4_NSRC_NONE                (0)                                     /*!< PGA 3 N source none */
#define PGA_4_NSRC_MAPTO_IO62          (MDU_CMPCFG3_PGA4_NSRC_1)               /*!< PGA 3 N source io 62 */
#define PGA_4_NSRC_MAPTO_IO41          (MDU_CMPCFG3_PGA4_NSRC_1 | MDU_CMPCFG3_PGA4_NSRC_0)    /*!< PGA 3 N source io 41 */
/**
  * @}
  */
#endif /* XT32H0xxB */

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/

/** @defgroup PGA_Private_Macros PGA Private Macros
  * @{
  */
#define IS_PGA(__PGA__)  (((__PGA__) == PGA_1) || \
                          ((__PGA__) == PGA_2) || \
                          ((__PGA__) == PGA_3) || \
                          ((__PGA__) == PGA_4))


#define IS_PAG_GAIN(__GAIN__)  (((__GAIN__) == PGA_GAIN_2) || \
                                ((__GAIN__) == PGA_GAIN_3) || \
                                ((__GAIN__) == PGA_GAIN_4) || \
                                ((__GAIN__) == PGA_GAIN_4P8) || \
                                ((__GAIN__) == PGA_GAIN_6) || \
                                ((__GAIN__) == PGA_GAIN_8) || \
                                ((__GAIN__) == PGA_GAIN_9P6) || \
                                ((__GAIN__) == PGA_GAIN_12))
/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PGA_Exported_Macros PGA Exported Macros
  * @{
  */
/** @brief  Reset PGA handle state.
  * @param  __HANDLE__  PGA handle
  * @retval None
  */
#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
#define __HAL_PGA_RESET_HANDLE_STATE(__HANDLE__) do{                                                  \
                                                      (__HANDLE__)->State = HAL_PGA_STATE_RESET;      \
                                                      (__HANDLE__)->MspInitCallback = NULL;            \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                    } while(0)
#else
#define __HAL_PGA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_PGA_STATE_RESET)
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */

/**
  * @brief Clear PGA error code (set it to no error code "HAL_COMP_ERROR_NONE").
  * @param __HANDLE__ PGA handle
  * @retval None
  */
#define PGA_CLEAR_ERRORCODE(__HANDLE__) ((__HANDLE__)->ErrorCode = HAL_PGA_ERROR_NONE)

/**
  * @brief PGA enable.
  * @param __HANDLE__ MDU handle
  * @param __CH__ PGA channel. This parameter can one of the following values:
  *        @arg @ref PGA_1
  *        @arg @ref PGA_2
  *        @arg @ref PGA_3
  *        @arg @ref PGA_4
  * @retval None
  */
#define __HAL_PGA_ENABLE(__HANDLE__, __CH__)            (((__HANDLE__)->Instance->PDCTRL) |= (MDU_PDCTRL_PGAEN1 << (__CH__)))

/**
  * @brief PGA disable.
  * @param __HANDLE__ MDU handle
  * @param __CH__ PGA channel. This parameter can one of the following values:
  *        @arg @ref PGA_1
  *        @arg @ref PGA_2
  *        @arg @ref PGA_3
  *        @arg @ref PGA_4
  * @retval None
  */
#define __HAL_PGA_DISABLE(__HANDLE__, __CH__)          (((__HANDLE__)->Instance->PDCTRL) &= ~(MDU_PDCTRL_PGAEN1 << (__CH__)))

/**
  * @brief PGA check enabled.
  * @param __HANDLE__ MDU handle
  * @param __CH__ PGA channel. This parameter can one of the following values:
  *        @arg @ref PGA_1
  *        @arg @ref PGA_2
  *        @arg @ref PGA_3
  *        @arg @ref PGA_4
  * @retval status SET or RESET
  */
#define __HAL_PGA_ISENABLED(__HANDLE__, __CH__)          ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), (MDU_PDCTRL_PGAEN1 << (__CH__))) == (MDU_PDCTRL_PGAEN1 << (__CH__))) ? SET : RESET)

/**
  * @brief PGA Set gain.
  * @param __HANDLE__ MDU handle
  * @param __CH__ PGA channel. This parameter can one of the following values:
  *        @arg @ref PGA_1
  *        @arg @ref PGA_2
  *        @arg @ref PGA_3
  *        @arg @ref PGA_4
  * @param __GAIN__ PGA gain 0 to 7
  * @retval None
  */
#define __HAL_PGA_SETGAIN(__HANDLE__, __CH__, __GAIN__)       (MODIFY_REG((__HANDLE__)->Instance->PGA_CFG, (MDU_PGACFG_PGA1GAIN << (__CH__<<2)), (__GAIN__ << (__CH__<<2))))

/**
  * @brief PGA Get gain.
  * @param __HANDLE__ MDU handle
  * @param __CH__ PGA channel. This parameter can one of the following values:
  *        @arg @ref PGA_1
  *        @arg @ref PGA_2
  *        @arg @ref PGA_3
  *        @arg @ref PGA_4
  * @retval PGA gain 0 to 7
  */
#define __HAL_PGA_GETGAIN(__HANDLE__, __CH__)       (READ_BIT((__HANDLE__)->Instance->PGA_CFG, (MDU_PGACFG_PGA1GAIN << (__CH__ << 2))) >> (__CH__ >> 2))

#if defined(XT32H0xxB)
/**
  * @brief PGA Set PGA P source.
  * @param __HANDLE__ MDU handle
  * @param __PGA__ PGA channel. This parameter can one of the following values:
  *        @arg @ref PGA_1
  *        @arg @ref PGA_2
  *        @arg @ref PGA_3
  *        @arg @ref PGA_4
  * @param __SOURCE__ PGA P source. This parameter can one of the following values:
  *        @arg @ref PGA_1_PSRC_NONE     
  *        @arg @ref PGA_1_PSRC_MAPTO_IO52
  *        @arg @ref PGA_1_PSRC_MAPTO_IO45
  *        @arg @ref PGA_1_PSRC_MAPTO_IO33
  *        @arg @ref PGA_2_PSRC_NONE     
  *        @arg @ref PGA_2_PSRC_MAPTO_IO50
  *        @arg @ref PGA_2_PSRC_MAPTO_IO46
  *        @arg @ref PGA_2_PSRC_MAPTO_IO31
  *        @arg @ref PGA_3_PSRC_NONE     
  *        @arg @ref PGA_3_PSRC_MAPTO_IO58
  *        @arg @ref PGA_3_PSRC_MAPTO_IO47
  *        @arg @ref PGA_3_PSRC_MAPTO_IO26
  *        @arg @ref PGA_4_PSRC_NONE     
  *        @arg @ref PGA_4_PSRC_MAPTO_IO42
  *        @arg @ref PGA_4_PSRC_MAPTO_IO61
  *        @arg @ref PGA_4_PSRC_MAPTO_IO48
  * @retval None
  */
#define __HAL_PGA_SETPGAPSOURCE(__HANDLE__, __PGA__, __SOURCE__)       (MODIFY_REG((__HANDLE__)->Instance->COMP_CFG3, (MDU_CMPCFG3_PGA1_PSRC << (__PGA__ << 2)), (__SOURCE__)))

/**
  * @brief PGA Set PGA N source.
  * @param __HANDLE__ MDU handle
  * @param __PGA__ PGA channel. This parameter can one of the following values:
  *        @arg @ref PGA_1
  *        @arg @ref PGA_2
  *        @arg @ref PGA_3
  *        @arg @ref PGA_4
  * @param __SOURCE__ PGA N source. This parameter can one of the following values:
  *        @arg @ref PGA_1_NSRC_NONE     
  *        @arg @ref PGA_1_NSRC_MAPTO_IO51
  *        @arg @ref PGA_1_NSRC_MAPTO_IO34
  *        @arg @ref PGA_2_NSRC_NONE     
  *        @arg @ref PGA_2_NSRC_MAPTO_IO49
  *        @arg @ref PGA_2_NSRC_MAPTO_IO32
  *        @arg @ref PGA_3_NSRC_NONE     
  *        @arg @ref PGA_3_NSRC_MAPTO_IO57
  *        @arg @ref PGA_3_NSRC_MAPTO_IO27
  *        @arg @ref PGA_4_NSRC_NONE     
  *        @arg @ref PGA_4_NSRC_MAPTO_IO62
  *        @arg @ref PGA_4_NSRC_MAPTO_IO41
  * @retval None
  */
#define __HAL_PGA_SETPGANSOURCE(__HANDLE__, __PGA__, __SOURCE__)       (MODIFY_REG((__HANDLE__)->Instance->COMP_CFG3, (MDU_CMPCFG3_PGA1_NSRC << (__PGA__ << 2)), (__SOURCE__)))
#endif /* XT32H0xxB */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup PGA_Exported_Functions
  * @{
  */
/** @addtogroup PGA_Exported_Functions_Group1 Initialization and Configuration functions
  * @brief    Initialization and Configuration functions
  * @{
  */
HAL_StatusTypeDef HAL_PGA_Init(PGA_HandleTypeDef *hpga);
HAL_StatusTypeDef HAL_PGA_DeInit(PGA_HandleTypeDef *hpga);
void              HAL_PGA_MspInit(PGA_HandleTypeDef *hpga);
void              HAL_PGA_MspDeInit(PGA_HandleTypeDef *hpga);

#if (USE_HAL_PGA_REGISTER_CALLBACKS == 1)
/* Callbacks Register/UnRegister functions  ***********************************/
HAL_StatusTypeDef HAL_PGA_RegisterCallback(PGA_HandleTypeDef *hpga, HAL_PGA_CallbackIDTypeDef CallbackID,
                                            pPGA_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_PGA_UnRegisterCallback(PGA_HandleTypeDef *hpga, HAL_PGA_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_PGA_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup PGA_Exported_Functions_Group2 Operation functions
  * @brief    Operation functions
  * @{
  */
HAL_StatusTypeDef HAL_PGA_ChannelEnable(PGA_HandleTypeDef *hpga, uint32_t Channel);
HAL_StatusTypeDef HAL_PGA_ChannelDisable(PGA_HandleTypeDef *hpga, uint32_t Channel);

HAL_StatusTypeDef HAL_PGA_SetChannelGain(PGA_HandleTypeDef *hpga, uint32_t Channel, uint32_t Gain);
uint32_t          HAL_PGA_GetChannelGain(PGA_HandleTypeDef *hpga, uint32_t Channel);

#if defined(XT32H0xxB)
HAL_StatusTypeDef HAL_PGA_SetChannelSource(PGA_HandleTypeDef *hpga, uint32_t Channel, uint32_t PSource, uint32_t NSource);
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @addtogroup PGA_Exported_Functions_Group3 Peripheral State functions
  * @brief    Peripheral State functions
  * @{
  */
HAL_PGA_StateTypeDef HAL_PGA_GetState(PGA_HandleTypeDef *hpga);
uint32_t             HAL_PGA_GetError(PGA_HandleTypeDef *hpga);
/**
  * @}
  */
/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif


#endif /* XT32H0xx_HAL_PGA_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
