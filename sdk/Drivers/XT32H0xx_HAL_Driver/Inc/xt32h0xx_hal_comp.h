/**
  ******************************************************************************
  * @file    xt32h0xx_hal_comp.h
  * @author  Software Team
  * @brief   Header file of MDU COMP HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_COMP_H
#define XT32H0xx_HAL_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"
#include "xt32h0xx_hal_comp_port.h"

/* Include low level driver */
#include "xt32h0xx_ll_comp.h"
#include "xt32h0xx_hal_ictl.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup COMP
  * @{
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup COMP_Private_Contants COMP Private Contants
  * @{
  */
#define COMP_CHANNEL_NUMBER            (4)
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup COMP_Exported_Types COMP Exported Types
  * @{
  */

/**
  * @brief  Comparator structure definition
  */
typedef struct
{
  uint32_t NegativeSource;                /*!< Configures Comparator negative source.
                                               This parameter can be a value of @ref COMP_HAL_EC_Negative_Source */

  uint32_t PositiveSource;                /*!< Configures Comparator positive source.
                                               This parameter can be a value of @ref COMP_HAL_EC_Positive_Source */

  uint32_t Hysteresis;                    /*!< Configures Comparator Hysteresis.
                                               This parameter can be a value of @ref COMP_HAL_EC_Hysteresis */

  uint32_t Spd;                           /*!< Configures Comparator Spd.
                                               This parameter can be a value of [0, 7] */

  uint32_t OutputPolarity;                /*!< Configures Comparator output polarity.
                                               This parameter can be a value of @ref COMP_HAL_EC_Polarity */
	
	uint32_t trigger;                       /*!< Configures Comparator trigger source.
                                               This parameter can be a value of @ref COMP_HAL_EC_Trigger */

  uint32_t InterruptEnable;               /*!< Configures Comparator interrupt enable.
                                               This parameter can be a value of @ref COMP_HAL_EC_Interrupt */
}  COMP_ChannelInitTypeDef;

typedef struct
{

  uint32_t OutputFilter;                  /*!< Configures Comparator output filter.
                                               This parameter can be a value of @ref COMP_HAL_EC_Filter */
  
  COMP_ChannelInitTypeDef  Channel[COMP_CHANNEL_NUMBER];     /*!< Configures COMP channel 0/1/2/3 */

} COMP_InitTypeDef;

/**
  * @brief  HAL COMP state machine: HAL COMP states definition
  */
typedef enum
{
  HAL_COMP_STATE_RESET             = 0x00U,                                             /*!< COMP not yet initialized                             */
  HAL_COMP_STATE_READY             = 0x01U,                                             /*!< COMP initialized and ready for use                   */
  HAL_COMP_STATE_BUSY              = 0x02U                                              /*!< COMP is running                                      */
} HAL_COMP_StateTypeDef;

/** 
  * @brief DAC_Error_Code DAC Error Code
  */
#define  HAL_COMP_ERROR_NONE              0x00U    /*!< No error                          */

/**
  * @brief  COMP Handle Structure definition
  */
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
typedef struct __COMP_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */
{
  COMP_TypeDef       *Instance;       /*!< Register base address    */
  COMP_InitTypeDef   Init;            /*!< COMP required parameters */
  HAL_LockTypeDef    Lock;            /*!< Locking object           */
  __IO HAL_COMP_StateTypeDef  State;  /*!< COMP communication state */
	uint8_t            dumy[2];
  __IO uint32_t      ErrorCode;       /*!< COMP error code          */
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
  void (* Ch1TriggerCallback)(struct __COMP_HandleTypeDef *hcomp);   /*!< COMP trigger callback */
  void (* Ch2TriggerCallback)(struct __COMP_HandleTypeDef *hcomp);   /*!< COMP trigger callback */
  void (* Ch3TriggerCallback)(struct __COMP_HandleTypeDef *hcomp);   /*!< COMP trigger callback */
  void (* Ch4TriggerCallback)(struct __COMP_HandleTypeDef *hcomp);   /*!< COMP trigger callback */
  void (* MspInitCallback)(struct __COMP_HandleTypeDef *hcomp);   /*!< COMP Msp Init callback */
  void (* MspDeInitCallback)(struct __COMP_HandleTypeDef *hcomp); /*!< COMP Msp DeInit callback */
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */
} COMP_HandleTypeDef;

#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL COMP Callback ID enumeration definition
  */
typedef enum
{
  HAL_COMP_CH1_TRIGGER_CB_ID            = 0x00U,  /*!< COMP trigger callback ID */
  HAL_COMP_CH2_TRIGGER_CB_ID            = 0x01U,  /*!< COMP trigger callback ID */
  HAL_COMP_CH3_TRIGGER_CB_ID            = 0x02U,  /*!< COMP trigger callback ID */
  HAL_COMP_CH4_TRIGGER_CB_ID            = 0x03U,  /*!< COMP trigger callback ID */
  HAL_COMP_MSPINIT_CB_ID                = 0x11U,  /*!< COMP Msp Init callback ID */
  HAL_COMP_MSPDEINIT_CB_ID              = 0x12U,  /*!< COMP Msp DeInit callback ID */
  HAL_COMP_ALL_CB_ID                    = 0x80U   /*!< COMP All ID */
} HAL_COMP_CallbackIDTypeDef;

/**
  * @brief  HAL COMP Callback pointer definition
  */
typedef  void (*pCOMP_CallbackTypeDef)(COMP_HandleTypeDef *hcomp); /*!< pointer to a COMP callback function */

#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup COMP_HAL_Exported_Constants COMP HAL Exported Constants
  * @{
  */
/** @defgroup COMP_HAL_EC_POWER  Comp power 
  * @{
  */
#define COMP_1_MODE_POWERON            (0)
#define COMP_1_MODE_POWERDOWN          (MDU_PDCTRL_CMP1PD)
#define COMP_2_MODE_POWERON            (0)
#define COMP_2_MODE_POWERDOWN          (MDU_PDCTRL_CMP2PD)
#define COMP_3_MODE_POWERON            (0)
#define COMP_3_MODE_POWERDOWN          (MDU_PDCTRL_CMP3PD)
#define COMP_4_MODE_POWERON            (0)
#define COMP_4_MODE_POWERDOWN          (MDU_PDCTRL_CMP4PD)
/**
  * @}
  */

/** @defgroup COMP_HAL_EC_Idx  Comp index 
  * @{
  */
#define COMP_1                         (0)
#define COMP_2                         (1)
#define COMP_3                         (2)
#define COMP_4                         (3)
/**
  * @}
  */

/** @defgroup COMP_HAL_EC_Negative_Source  Comp negative source 
  * @{
  */
#define COMP_1_NEGATIVE_SOURCE_EXTERNAL       (0)
#define COMP_1_NEGATIVE_SOURCE_DAC1_OUT       (MDU_CMPCFG1_NSRC_1_1)
#define COMP_1_NEGATIVE_SOURCE_DAC2_OUT       (MDU_CMPCFG1_NSRC_1_1 | MDU_CMPCFG1_NSRC_1_0)
#define COMP_2_NEGATIVE_SOURCE_EXTERNAL       (0)
#define COMP_2_NEGATIVE_SOURCE_DAC1_OUT       (MDU_CMPCFG1_NSRC_2_1)
#define COMP_2_NEGATIVE_SOURCE_DAC2_OUT       (MDU_CMPCFG1_NSRC_2_1 | MDU_CMPCFG1_NSRC_2_0)
#define COMP_3_NEGATIVE_SOURCE_EXTERNAL       (0)
#define COMP_3_NEGATIVE_SOURCE_DAC1_OUT       (MDU_CMPCFG1_NSRC_3_1)
#define COMP_3_NEGATIVE_SOURCE_DAC2_OUT       (MDU_CMPCFG1_NSRC_3_1 | MDU_CMPCFG1_NSRC_3_0)
#define COMP_4_NEGATIVE_SOURCE_EXTERNAL       (0)
#define COMP_4_NEGATIVE_SOURCE_DAC1_OUT       (MDU_CMPCFG1_NSRC_4_1)
#define COMP_4_NEGATIVE_SOURCE_DAC2_OUT       (MDU_CMPCFG1_NSRC_4_1 | MDU_CMPCFG1_NSRC_4_0)
/**
  * @}
  */

/** @defgroup COMP_HAL_EC_Positive_Source  Comp poritive source 
  * @{
  */
#define COMP_1_POSITIVE_SOURCE_EXTERNAL       (0)
#define COMP_1_POSITIVE_SOURCE_INTERNAL       (MDU_CMPCFG1_PSRC_1)
#define COMP_2_POSITIVE_SOURCE_EXTERNAL       (0)
#define COMP_2_POSITIVE_SOURCE_INTERNAL       (MDU_CMPCFG1_PSRC_2)
#define COMP_3_POSITIVE_SOURCE_EXTERNAL       (0)
#define COMP_3_POSITIVE_SOURCE_INTERNAL       (MDU_CMPCFG1_PSRC_3)
#define COMP_4_POSITIVE_SOURCE_EXTERNAL       (0)
#define COMP_4_POSITIVE_SOURCE_INTERNAL       (MDU_CMPCFG1_PSRC_4)
/**
  * @}
  */

/** @defgroup COMP_HAL_EC_Polarity  Comp polarity 
  * @{
  */
#define COMP_1_OUTPUT_POLARITY_NORMAL      (0)                         /*!< normal */
#define COMP_1_OUTPUT_POLARITY_INVERT      (MDU_CMPCFG3_OPOL_0)        /*!< invert */
#define COMP_2_OUTPUT_POLARITY_NORMAL      (0)                         /*!< normal */
#define COMP_2_OUTPUT_POLARITY_INVERT      (MDU_CMPCFG3_OPOL_1)        /*!< invert */
#define COMP_3_OUTPUT_POLARITY_NORMAL      (0)                         /*!< normal */
#define COMP_3_OUTPUT_POLARITY_INVERT      (MDU_CMPCFG3_OPOL_2)        /*!< invert */
#define COMP_4_OUTPUT_POLARITY_NORMAL      (0)                         /*!< normal */
#define COMP_4_OUTPUT_POLARITY_INVERT      (MDU_CMPCFG3_OPOL_3)        /*!< invert */
/**
  * @}
  */

/** @defgroup COMP_HAL_EC_Hysteresis  Comp Hysteresis 
  * @{
  */
#define COMP_HYSTERESIS_NONE           (0)                                     /* no hysteresis */
#define COMP_HYSTERESIS_10MV           (1)                                     /* 10mV hysteresis */
#define COMP_HYSTERESIS_20MV           (2)                                     /* 20mV hysteresis */
#define COMP_HYSTERESIS_30MV           (3)                                     /* 30mV hysteresis */
/**
  * @}
  */

/** @defgroup COMP_HAL_EC_Filter  Comparator output filter 
  * @{
  */
#define COMP_OUTPUT_FILTER_ENABLE      (0)
#define COMP_OUTPUT_FILTER_DISABLE     (MDU_CMPCFG3_OFLT)
/**
  * @}
  */

/** @defgroup COMP_HAL_EC_Trigger  Comparator trigger 
  * @{
  */
#define COMP_1_TRIGGER_NONE            (0)
#define COMP_1_TRIGGER_RISINGEDGE      (MDU_CMPCFG3_CMP1_RTRG)
#define COMP_1_TRIGGER_FALLINGEDGE     (MDU_CMPCFG3_CMP1_FTRG)
#define COMP_1_TRIGGER_BOTHEDGE        (MDU_CMPCFG3_CMP1_RTRG|MDU_CMPCFG3_CMP1_FTRG)
#define COMP_2_TRIGGER_NONE            (0)
#define COMP_2_TRIGGER_RISINGEDGE      (MDU_CMPCFG3_CMP2_RTRG)
#define COMP_2_TRIGGER_FALLINGEDGE     (MDU_CMPCFG3_CMP2_FTRG)
#define COMP_2_TRIGGER_BOTHEDGE        (MDU_CMPCFG3_CMP2_RTRG|MDU_CMPCFG3_CMP2_FTRG)
#define COMP_3_TRIGGER_NONE            (0)
#define COMP_3_TRIGGER_RISINGEDGE      (MDU_CMPCFG3_CMP3_RTRG)
#define COMP_3_TRIGGER_FALLINGEDGE     (MDU_CMPCFG3_CMP3_FTRG)
#define COMP_3_TRIGGER_BOTHEDGE        (MDU_CMPCFG3_CMP3_RTRG|MDU_CMPCFG3_CMP3_FTRG)
#define COMP_4_TRIGGER_NONE            (0)
#define COMP_4_TRIGGER_RISINGEDGE      (MDU_CMPCFG3_CMP4_RTRG)
#define COMP_4_TRIGGER_FALLINGEDGE     (MDU_CMPCFG3_CMP4_FTRG)
#define COMP_4_TRIGGER_BOTHEDGE        (MDU_CMPCFG3_CMP4_RTRG|MDU_CMPCFG3_CMP4_FTRG)
/**
  * @}
  */

/** @defgroup COMP_HAL_EC_Flag  Comparator interrupt flag 
  * @{
  */
#define COMP_1_FLAG                    (MDU_INT_STATUS_OCOMP1)
#define COMP_2_FLAG                    (MDU_INT_STATUS_OCOMP2)
#define COMP_3_FLAG                    (MDU_INT_STATUS_OCOMP3)
#define COMP_4_FLAG                    (MDU_INT_STATUS_OCOMP4)
/**
  * @}
  */

#if defined(XT32H0xxBMPW)
/** @defgroup COMP_HAL_EC_Interrupt  Comparator interrupt enable 
  * @{
  */
#define COMP_1_INTERRUPT_ENABLE        (ICTL_IRQ_OCOMP_1)
#define COMP_1_INTERRUPT_DISABLE       (0)
#define COMP_2_INTERRUPT_ENABLE        (ICTL_IRQ_OCOMP_2)
#define COMP_2_INTERRUPT_DISABLE       (0)
#define COMP_3_INTERRUPT_ENABLE        (ICTL_IRQ_OCOMP_3)
#define COMP_3_INTERRUPT_DISABLE       (0)
#define COMP_4_INTERRUPT_ENABLE        (ICTL_IRQ_OCOMP_4)
#define COMP_4_INTERRUPT_DISABLE       (0)
/**
  * @}
  */
#endif /* XT32H0xxBMPW */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup COMP_Exported_Macros COMP Exported Macros
  * @{
  */
/** @brief  Reset COMP handle state.
  * @param  __HANDLE__  COMP handle
  */
#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
#define __HAL_COMP_RESET_HANDLE_STATE(__HANDLE__) do{                                                  \
                                                      (__HANDLE__)->State = HAL_COMP_STATE_RESET;      \
                                                      (__HANDLE__)->MspInitCallback = NULL;            \
                                                      (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                    } while(0)
#else
#define __HAL_COMP_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_COMP_STATE_RESET)
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */

/**
  * @brief Clear COMP error code (set it to no error code "HAL_COMP_ERROR_NONE").
  * @param __HANDLE__ COMP handle
  */
#define COMP_CLEAR_ERRORCODE(__HANDLE__) ((__HANDLE__)->ErrorCode = HAL_COMP_ERROR_NONE)

/**
  * @brief COMP poweron.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  */
#define __HAL_COMP_POWERON(__HANDLE__, __CMPIDX__)           ((__CMPIDX__ == COMP_1) ? (((__HANDLE__)->Instance->PDCTRL) &= (~MDU_PDCTRL_CMP1PD)) : \
                                                              (__CMPIDX__ == COMP_2) ? (((__HANDLE__)->Instance->PDCTRL) &= (~MDU_PDCTRL_CMP2PD)) : \
                                                              (__CMPIDX__ == COMP_3) ? (((__HANDLE__)->Instance->PDCTRL) &= (~MDU_PDCTRL_CMP3PD)) : \
                                                              (((__HANDLE__)->Instance->PDCTRL) &= (~MDU_PDCTRL_CMP4PD)))

/**
  * @brief COMP powerdown.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @retval None
  */
#define __HAL_COMP_POWERDOWN(__HANDLE__, __CMPIDX__)         ((__CMPIDX__ == COMP_1) ? (((__HANDLE__)->Instance->PDCTRL) |= (MDU_PDCTRL_CMP1PD)) : \
                                                              (__CMPIDX__ == COMP_2) ? (((__HANDLE__)->Instance->PDCTRL) |= (MDU_PDCTRL_CMP2PD)) : \
                                                              (__CMPIDX__ == COMP_3) ? (((__HANDLE__)->Instance->PDCTRL) |= (MDU_PDCTRL_CMP3PD)) : \
                                                              (((__HANDLE__)->Instance->PDCTRL) |= (MDU_PDCTRL_CMP4PD)))

/**
  * @brief COMP check power on.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @retval State RESET or SET
  */
#define __HAL_COMP_ISPOWERON(__HANDLE__, __CMPIDX__)         ((__CMPIDX__ == COMP_1) ? ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), (MDU_PDCTRL_CMP1PD)) == COMP_1_MODE_POWERDOWN) ? SET : RESET) : \
                                                              (__CMPIDX__ == COMP_2) ? ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), (MDU_PDCTRL_CMP2PD)) == COMP_2_MODE_POWERDOWN) ? SET : RESET) : \
                                                              (__CMPIDX__ == COMP_3) ? ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), (MDU_PDCTRL_CMP3PD)) == COMP_3_MODE_POWERDOWN) ? SET : RESET) : \
                                                              ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), (MDU_PDCTRL_CMP4PD)) == COMP_4_MODE_POWERDOWN) ? SET : RESET))

/**
  * @brief COMP set positive source.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @param __PSRC__ positive source 
  *        @arg @ref COMP_1_POSITIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_1_POSITIVE_SOURCE_INTERNAL
  *        @arg @ref COMP_2_POSITIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_2_POSITIVE_SOURCE_INTERNAL
  *        @arg @ref COMP_3_POSITIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_3_POSITIVE_SOURCE_INTERNAL
  *        @arg @ref COMP_4_POSITIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_4_POSITIVE_SOURCE_INTERNAL
  * @retval None
  */
#define __HAL_COMP_SETPOSITIVESOURCE(__HANDLE__, __CMPIDX__, __PSRC__)    \
     ((__CMPIDX__ == COMP_1) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_PSRC_1), __PSRC__)) : \
      (__CMPIDX__ == COMP_2) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_PSRC_2), __PSRC__)) : \
      (__CMPIDX__ == COMP_3) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_PSRC_3), __PSRC__)) : \
      (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_PSRC_4), __PSRC__)))

/**
  * @brief COMP get positive source.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @retval positive source 
  *        @arg @ref COMP_1_POSITIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_1_POSITIVE_SOURCE_INTERNAL
  *        @arg @ref COMP_2_POSITIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_2_POSITIVE_SOURCE_INTERNAL
  *        @arg @ref COMP_3_POSITIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_3_POSITIVE_SOURCE_INTERNAL
  *        @arg @ref COMP_4_POSITIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_4_POSITIVE_SOURCE_INTERNAL
  */
#define __HAL_COMP_GETPOSITIVESOURCE(__HANDLE__, __CMPIDX__)    \
     ((__CMPIDX__ == COMP_1) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_PSRC_1))) : \
      (__CMPIDX__ == COMP_2) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_PSRC_2))) : \
      (__CMPIDX__ == COMP_3) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_PSRC_3))) : \
      (READ_BIT(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_PSRC_4))))

/**
  * @brief COMP set negative source.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @param __NSRC__ negative source 
  *        @arg @ref COMP_1_NEGATIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_1_NEGATIVE_SOURCE_DAC1_OUT
  *        @arg @ref COMP_1_NEGATIVE_SOURCE_DAC2_OUT
  *        @arg @ref COMP_2_NEGATIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_2_NEGATIVE_SOURCE_DAC1_OUT
  *        @arg @ref COMP_2_NEGATIVE_SOURCE_DAC2_OUT
  *        @arg @ref COMP_3_NEGATIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_3_NEGATIVE_SOURCE_DAC1_OUT
  *        @arg @ref COMP_3_NEGATIVE_SOURCE_DAC2_OUT
  *        @arg @ref COMP_4_NEGATIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_4_NEGATIVE_SOURCE_DAC1_OUT
  *        @arg @ref COMP_4_NEGATIVE_SOURCE_DAC2_OUT
  * @retval None
  */
#define __HAL_COMP_SETNEGATIVESOURCE(__HANDLE__, __CMPIDX__, __NSRC__)    \
     ((__CMPIDX__ == COMP_1) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_NSRC_1), __NSRC__)) : \
      (__CMPIDX__ == COMP_2) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_NSRC_2), __NSRC__)) : \
      (__CMPIDX__ == COMP_3) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_NSRC_3), __NSRC__)) : \
      (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_NSRC_4), __NSRC__)))

/**
  * @brief COMP get negative source.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @retval negative source 
  *        @arg @ref COMP_1_NEGATIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_1_NEGATIVE_SOURCE_DAC1_OUT
  *        @arg @ref COMP_1_NEGATIVE_SOURCE_DAC2_OUT
  *        @arg @ref COMP_2_NEGATIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_2_NEGATIVE_SOURCE_DAC1_OUT
  *        @arg @ref COMP_2_NEGATIVE_SOURCE_DAC2_OUT
  *        @arg @ref COMP_3_NEGATIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_3_NEGATIVE_SOURCE_DAC1_OUT
  *        @arg @ref COMP_3_NEGATIVE_SOURCE_DAC2_OUT
  *        @arg @ref COMP_4_NEGATIVE_SOURCE_EXTERNAL
  *        @arg @ref COMP_4_NEGATIVE_SOURCE_DAC1_OUT
  *        @arg @ref COMP_4_NEGATIVE_SOURCE_DAC2_OUT
  */
#define __HAL_COMP_GETNEGATIVESOURCE(__HANDLE__, __CMPIDX__)    \
     ((__CMPIDX__ == COMP_1) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_NSRC_1))) : \
      (__CMPIDX__ == COMP_2) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_NSRC_2))) : \
      (__CMPIDX__ == COMP_3) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_NSRC_3))) : \
      (READ_BIT(((__HANDLE__)->Instance->COMP_CFG1), (MDU_CMPCFG1_NSRC_4))))

/**
  * @brief COMP set hys.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @param __HYS__ Hysteresis 0 to 3 
  * @retval None
  */
#define __HAL_COMP_SETHYS(__HANDLE__, __CMPIDX__, __HYS__)    \
     ((__CMPIDX__ == COMP_1) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_HYS_1), (__HYS__ << MDU_CMPCFG2_HYS_1_Pos))) : \
      (__CMPIDX__ == COMP_2) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_HYS_2), (__HYS__ << MDU_CMPCFG2_HYS_2_Pos))) : \
      (__CMPIDX__ == COMP_3) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_HYS_3), (__HYS__ << MDU_CMPCFG2_HYS_3_Pos))) : \
      (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_HYS_4), (__HYS__ << MDU_CMPCFG2_HYS_4_Pos))))

/**
  * @brief COMP get hys.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @retval Hysteresis 0 to 3 
  */
#define __HAL_COMP_GETHYS(__HANDLE__, __CMPIDX__)    \
     ((__CMPIDX__ == COMP_1) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_HYS_1)) >> MDU_CMPCFG2_HYS_1_Pos) : \
      (__CMPIDX__ == COMP_2) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_HYS_2)) >> MDU_CMPCFG2_HYS_2_Pos) : \
      (__CMPIDX__ == COMP_3) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_HYS_3)) >> MDU_CMPCFG2_HYS_3_Pos) : \
      (READ_BIT(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_HYS_4)) >> MDU_CMPCFG2_HYS_4_Pos))

/**
  * @brief COMP set spd.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @param __SPD__ spd 0 to 7 
  * @retval None
  */
#define __HAL_COMP_SETSPD(__HANDLE__, __CMPIDX__, __SPD__)    \
     ((__CMPIDX__ == COMP_1) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_SPD_1), (__SPD__ << MDU_CMPCFG2_SPD_1_Pos))) : \
      (__CMPIDX__ == COMP_2) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_SPD_2), (__SPD__ << MDU_CMPCFG2_SPD_2_Pos))) : \
      (__CMPIDX__ == COMP_3) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_SPD_3), (__SPD__ << MDU_CMPCFG2_SPD_3_Pos))) : \
      (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_SPD_4), (__SPD__ << MDU_CMPCFG2_SPD_4_Pos))))

/**
  * @brief COMP get hys.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @retval spd 0 to 7 
  */
#define __HAL_COMP_GETSPD(__HANDLE__, __CMPIDX__)    \
     ((__CMPIDX__ == COMP_1) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_SPD_1)) >> MDU_CMPCFG2_SPD_1_Pos) : \
      (__CMPIDX__ == COMP_2) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_SPD_2)) >> MDU_CMPCFG2_SPD_2_Pos) : \
      (__CMPIDX__ == COMP_3) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_SPD_3)) >> MDU_CMPCFG2_SPD_3_Pos) : \
      (READ_BIT(((__HANDLE__)->Instance->COMP_CFG2), (MDU_CMPCFG2_SPD_4)) >> MDU_CMPCFG2_SPD_4_Pos))

/**
  * @brief COMP set output polarity.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @param __POL__ 
  *        @arg @ref COMP_1_OUTPUT_POLARITY_NORMAL
  *        @arg @ref COMP_1_OUTPUT_POLARITY_INVERT
  *        @arg @ref COMP_2_OUTPUT_POLARITY_NORMAL
  *        @arg @ref COMP_2_OUTPUT_POLARITY_INVERT
  *        @arg @ref COMP_3_OUTPUT_POLARITY_NORMAL
  *        @arg @ref COMP_3_OUTPUT_POLARITY_INVERT
  *        @arg @ref COMP_4_OUTPUT_POLARITY_NORMAL
  *        @arg @ref COMP_4_OUTPUT_POLARITY_INVERT
  * @retval None
  */
#define __HAL_COMP_SETOUTPUTPOLARITY(__HANDLE__, __CMPIDX__, __POL__)    \
     ((__CMPIDX__ == COMP_1) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OPOL_0), (__POL__))) : \
      (__CMPIDX__ == COMP_2) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OPOL_1), (__POL__))) : \
      (__CMPIDX__ == COMP_3) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OPOL_2), (__POL__))) : \
      (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OPOL_3), (__POL__))))

/**
  * @brief COMP get output polarity.
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @retval polarity 
  *        @arg @ref COMP_1_OUTPUT_POLARITY_NORMAL
  *        @arg @ref COMP_1_OUTPUT_POLARITY_INVERT
  *        @arg @ref COMP_2_OUTPUT_POLARITY_NORMAL
  *        @arg @ref COMP_2_OUTPUT_POLARITY_INVERT
  *        @arg @ref COMP_3_OUTPUT_POLARITY_NORMAL
  *        @arg @ref COMP_3_OUTPUT_POLARITY_INVERT
  *        @arg @ref COMP_4_OUTPUT_POLARITY_NORMAL
  *        @arg @ref COMP_4_OUTPUT_POLARITY_INVERT
  */
#define __HAL_COMP_GETOUTPUTPOLARITY(__HANDLE__, __CMPIDX__)    \
     ((__CMPIDX__ == COMP_1) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OPOL_0))) : \
      (__CMPIDX__ == COMP_2) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OPOL_1))) : \
      (__CMPIDX__ == COMP_3) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OPOL_2))) : \
      (READ_BIT(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OPOL_3))))

/**
  * @brief COMP set trigger .
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @param __TRG__ 
          @arg @ref COMP_1_TRIGGER_NONE            
          @arg @ref COMP_1_TRIGGER_RISINGEDGE      
          @arg @ref COMP_1_TRIGGER_FALLINGEDGE     
          @arg @ref COMP_1_TRIGGER_BOTHEDGE        
          @arg @ref COMP_2_TRIGGER_NONE            
          @arg @ref COMP_2_TRIGGER_RISINGEDGE      
          @arg @ref COMP_2_TRIGGER_FALLINGEDGE     
          @arg @ref COMP_2_TRIGGER_BOTHEDGE        
          @arg @ref COMP_3_TRIGGER_NONE            
          @arg @ref COMP_3_TRIGGER_RISINGEDGE      
          @arg @ref COMP_3_TRIGGER_FALLINGEDGE     
          @arg @ref COMP_3_TRIGGER_BOTHEDGE        
          @arg @ref COMP_4_TRIGGER_NONE            
          @arg @ref COMP_4_TRIGGER_RISINGEDGE      
          @arg @ref COMP_4_TRIGGER_FALLINGEDGE     
          @arg @ref COMP_4_TRIGGER_BOTHEDGE        
  * @retval None
  */
#define __HAL_COMP_SETTRIGGER(__HANDLE__, __CMPIDX__, __TRG__)    \
     ((__CMPIDX__ == COMP_1) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG3), (COMP_1_TRIGGER_BOTHEDGE), (__TRG__))) : \
      (__CMPIDX__ == COMP_2) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG3), (COMP_2_TRIGGER_BOTHEDGE), (__TRG__))) : \
      (__CMPIDX__ == COMP_3) ? (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG3), (COMP_3_TRIGGER_BOTHEDGE), (__TRG__))) : \
      (MODIFY_REG(((__HANDLE__)->Instance->COMP_CFG3), (COMP_4_TRIGGER_BOTHEDGE), (__TRG__))))

/**
  * @brief COMP get trigger .
  * @param __HANDLE__ MDU handle
  * @param __CMPIDX__ COMP index
  * @retval trigger
          @arg @ref COMP_1_TRIGGER_NONE            
          @arg @ref COMP_1_TRIGGER_RISINGEDGE      
          @arg @ref COMP_1_TRIGGER_FALLINGEDGE     
          @arg @ref COMP_1_TRIGGER_BOTHEDGE        
          @arg @ref COMP_2_TRIGGER_NONE            
          @arg @ref COMP_2_TRIGGER_RISINGEDGE      
          @arg @ref COMP_2_TRIGGER_FALLINGEDGE     
          @arg @ref COMP_2_TRIGGER_BOTHEDGE        
          @arg @ref COMP_3_TRIGGER_NONE            
          @arg @ref COMP_3_TRIGGER_RISINGEDGE      
          @arg @ref COMP_3_TRIGGER_FALLINGEDGE     
          @arg @ref COMP_3_TRIGGER_BOTHEDGE        
          @arg @ref COMP_4_TRIGGER_NONE            
          @arg @ref COMP_4_TRIGGER_RISINGEDGE      
          @arg @ref COMP_4_TRIGGER_FALLINGEDGE     
          @arg @ref COMP_4_TRIGGER_BOTHEDGE        
  * @retval None
  */
#define __HAL_COMP_GETTRIGGER(__HANDLE__, __CMPIDX__)    \
     ((__CMPIDX__ == COMP_1) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG3), (COMP_1_TRIGGER_BOTHEDGE))) : \
      (__CMPIDX__ == COMP_2) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG3), (COMP_2_TRIGGER_BOTHEDGE))) : \
      (__CMPIDX__ == COMP_3) ? (READ_BIT(((__HANDLE__)->Instance->COMP_CFG3), (COMP_3_TRIGGER_BOTHEDGE))) : \
      (READ_BIT(((__HANDLE__)->Instance->COMP_CFG3), (COMP_4_TRIGGER_BOTHEDGE))))

/**
  * @brief COMP check flag
	* @param __HANDLE__ MDU handle
	* @param __CMPIDX__
	* @retval status (SET or RESET)
	*/
#define __HAL_COMP_CHECKFLAG(__HANDLE__, __CMPIDX__)    \
((__CMPIDX__ == COMP_1) ? (READ_BIT(((__HANDLE__)->Instance->INT_STATUS_1), (COMP_1_FLAG)) ? SET : RESET) : \
      (__CMPIDX__ == COMP_2) ? (READ_BIT(((__HANDLE__)->Instance->INT_STATUS_1), (COMP_2_FLAG)) ? SET : RESET) : \
      (__CMPIDX__ == COMP_3) ? (READ_BIT(((__HANDLE__)->Instance->INT_STATUS_1), (COMP_3_FLAG)) ? SET : RESET) : \
      (READ_BIT(((__HANDLE__)->Instance->INT_STATUS_1), (COMP_4_FLAG)) ? SET : RESET))

/**
  * @brief COMP clear flag
	* @param __HANDLE__ MDU handle
	* @param __CMPIDX__
	* @retval None
	*/
#define __HAL_COMP_CLEARFLAG(__HANDLE__, __CMPIDX__)    \
     ((__CMPIDX__ == COMP_1) ? (CLEAR_BIT(((__HANDLE__)->Instance->INT_STATUS_1), (COMP_1_FLAG))) : \
      (__CMPIDX__ == COMP_2) ? (CLEAR_BIT(((__HANDLE__)->Instance->INT_STATUS_1), (COMP_2_FLAG))) : \
      (__CMPIDX__ == COMP_3) ? (CLEAR_BIT(((__HANDLE__)->Instance->INT_STATUS_1), (COMP_3_FLAG))) : \
      (CLEAR_BIT(((__HANDLE__)->Instance->INT_STATUS_1), (COMP_4_FLAG))))
			
/**
  * @brief COMP enable output filter.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_COMP_ENABLEOUTPUTFILTER(__HANDLE__)    \
      (CLEAR_BIT(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OFLT)))

/**
  * @brief COMP disable output filter.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_COMP_DISABLEOUTPUTFILTER(__HANDLE__)    \
      (SET_BIT(((__HANDLE__)->Instance->COMP_CFG3), (MDU_CMPCFG3_OFLT)))
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup COMP_Private_Macros COMP Private Macros
  * @{
  */
#define IS_COMP_MODE(MODE) (((MODE) == COMP_1_MODE_POWERON)   ||\
                            ((MODE) == COMP_1_MODE_POWERDOWN) ||\
                            ((MODE) == COMP_2_MODE_POWERON)   ||\
                            ((MODE) == COMP_2_MODE_POWERDOWN) ||\
                            ((MODE) == COMP_3_MODE_POWERON)   ||\
                            ((MODE) == COMP_4_MODE_POWERDOWN) ||\
                            ((MODE) == COMP_4_MODE_POWERON)   ||\
                            ((MODE) == COMP_4_MODE_POWERDOWN) )

#define IS_COMP(COMP)  (((COMP) == COMP_1)  || \
                       ((COMP) == COMP_2)   || \
                       ((COMP) == COMP_3)   || \
                       ((COMP) == COMP_4)   )

#define IS_COMP_NEGATIVESOURCE(SOURCE)  (((SOURCE) == COMP_1_NEGATIVE_SOURCE_EXTERNAL)  || \
                                         ((SOURCE) == COMP_1_NEGATIVE_SOURCE_DAC1_OUT)  || \
                                         ((SOURCE) == COMP_1_NEGATIVE_SOURCE_DAC2_OUT)  || \
                                         ((SOURCE) == COMP_2_NEGATIVE_SOURCE_EXTERNAL)  || \
                                         ((SOURCE) == COMP_2_NEGATIVE_SOURCE_DAC1_OUT)  || \
                                         ((SOURCE) == COMP_2_NEGATIVE_SOURCE_DAC2_OUT)  || \
                                         ((SOURCE) == COMP_3_NEGATIVE_SOURCE_EXTERNAL)  || \
                                         ((SOURCE) == COMP_3_NEGATIVE_SOURCE_DAC1_OUT)  || \
                                         ((SOURCE) == COMP_3_NEGATIVE_SOURCE_DAC2_OUT)  || \
                                         ((SOURCE) == COMP_4_NEGATIVE_SOURCE_EXTERNAL)  || \
                                         ((SOURCE) == COMP_4_NEGATIVE_SOURCE_DAC1_OUT)  || \
                                         ((SOURCE) == COMP_4_NEGATIVE_SOURCE_DAC2_OUT)  )

#define IS_COMP_POSITIVESOURCE(SOURCE)  (((SOURCE) == COMP_1_POSITIVE_SOURCE_EXTERNAL) || \
                                         ((SOURCE) == COMP_1_POSITIVE_SOURCE_INTERNAL) || \
                                         ((SOURCE) == COMP_2_POSITIVE_SOURCE_EXTERNAL) || \
                                         ((SOURCE) == COMP_2_POSITIVE_SOURCE_INTERNAL) || \
                                         ((SOURCE) == COMP_3_POSITIVE_SOURCE_EXTERNAL) || \
                                         ((SOURCE) == COMP_3_POSITIVE_SOURCE_INTERNAL) || \
                                         ((SOURCE) == COMP_4_POSITIVE_SOURCE_EXTERNAL) || \
                                         ((SOURCE) == COMP_4_POSITIVE_SOURCE_INTERNAL) )

#define IS_COMP_HYSTERESIS(HYSTERESIS) (((HYSTERESIS) == COMP_HYSTERESIS_NONE) || \
                                        ((HYSTERESIS) == COMP_HYSTERESIS_10MV) || \
                                        ((HYSTERESIS) == COMP_HYSTERESIS_20MV) || \
                                        ((HYSTERESIS) == COMP_HYSTERESIS_30MV))

#define IS_COMP_SPD(__SPD__)                (((__SPD__) >= 0)   && \
                                             ((__SPD__) <= 7))

#define IS_COMP_OUTPUTPOL(__POL__)          (((__POL__) == 0) || \
                                             ((__POL__) == COMP_1_OUTPUT_POLARITY_INVERT) || \
                                             ((__POL__) == COMP_2_OUTPUT_POLARITY_INVERT) || \
                                             ((__POL__) == COMP_3_OUTPUT_POLARITY_INVERT) || \
                                             ((__POL__) == COMP_4_OUTPUT_POLARITY_INVERT))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup COMP_Exported_Functions
  * @{
  */
/** @addtogroup COMP_Exported_Functions_Group1 COMP Exported Functions Group1
  * @brief    Initialization and Configuration functions
  * @{
  */
/* Initialization and de-initialization functions  ****************************/
HAL_StatusTypeDef HAL_COMP_Init(COMP_HandleTypeDef *hcomp);
HAL_StatusTypeDef HAL_COMP_DeInit(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_MspInit(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_MspDeInit(COMP_HandleTypeDef *hcomp);

#if (USE_HAL_COMP_REGISTER_CALLBACKS == 1)
/* Callbacks Register/UnRegister functions  ***********************************/
HAL_StatusTypeDef HAL_COMP_RegisterCallback(COMP_HandleTypeDef *hcomp, HAL_COMP_CallbackIDTypeDef CallbackID,
                                            pCOMP_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_COMP_UnRegisterCallback(COMP_HandleTypeDef *hcomp, HAL_COMP_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_COMP_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup COMP_Exported_Functions_Group2 COMP Exported Functions Group2
  * @brief  Operation and interrupt response functions
  * @{
  */
/* Operation functions  *****************************************************/
HAL_StatusTypeDef HAL_COMP_Start(COMP_HandleTypeDef *hcomp, uint32_t Channel);
HAL_StatusTypeDef HAL_COMP_Stop(COMP_HandleTypeDef *hcomp, uint32_t Channel);

HAL_StatusTypeDef HAL_COMP_FilterEnable(COMP_HandleTypeDef *hcomp, uint32_t Freq);
HAL_StatusTypeDef HAL_COMP_FilterDisable(COMP_HandleTypeDef *hcomp);

void              HAL_COMP_IRQHandler(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_TriggerCallback(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_Ch1IRQHandler(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_Ch2IRQHandler(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_Ch3IRQHandler(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_Ch4IRQHandler(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_Ch1TriggerCallback(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_Ch2TriggerCallback(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_Ch3TriggerCallback(COMP_HandleTypeDef *hcomp);
void              HAL_COMP_Ch4TriggerCallback(COMP_HandleTypeDef *hcomp);
/**
  * @}
  */


/** @addtogroup COMP_Exported_Functions_Group3
  * @{
  */
/* Peripheral State functions *************************************************/
HAL_COMP_StateTypeDef HAL_COMP_GetState(COMP_HandleTypeDef *hcomp);
uint32_t              HAL_COMP_GetError(COMP_HandleTypeDef *hcomp);
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


#endif /* XT32H0xx_HAL_COMP_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
