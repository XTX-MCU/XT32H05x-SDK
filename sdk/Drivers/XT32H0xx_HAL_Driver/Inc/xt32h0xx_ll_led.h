/**
  ******************************************************************************
  * @file    xt32h0xx_ll_led.h
  * @author  Software Team
  * @brief   Header file of LED LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_LED_H
#define XT32H0xx_LL_LED_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined(LED)

/** @defgroup LED_LL LED
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup LED_LL_Exported_Constants LED Exported Constants
  * @{
  */

/** @defgroup LED_Display_MODE LED display Mode
  * @{
  */
#define LL_LED_RMODE_ONOFF             (0x00000000U )                          /*!< On-off mode */
#define LL_LED_RMODE_BRIGHT            (LED_MODE_RMD)                          /*!< Brightness mode */
/**
  * @}
  */

/** @defgroup LED_OPERATION_MODE LED panel operation Mode
  * @{
  */
#define LL_LED_DMODE_NORMAL            (0x00000000U )                          /*!< operate in normal mode */
#define LL_LED_DMODE_DIMMING           (LED_MODE_DMD)                          /*!< operate in dimming mode */
/**
  * @}
  */

/** @defgroup LED_COM_ENABLE LED COM enable
  * @{
  */
#define LL_LED_ENABLE_COM0             (LED_CTRL_CE_0)
#define LL_LED_ENABLE_COM1             (LED_CTRL_CE_1) 
#define LL_LED_ENABLE_COM2             (LED_CTRL_CE_2) 
#define LL_LED_ENABLE_COM3             (LED_CTRL_CE_3) 
#define LL_LED_ENABLE_COM4             (LED_CTRL_CE_4) 
#define LL_LED_ENABLE_COM5             (LED_CTRL_CE_5) 
#define LL_LED_ENABLE_COM6             (LED_CTRL_CE_6) 
#define LL_LED_ENABLE_COM7             (LED_CTRL_CE_7) 
/**
  * @}
  */

/** @defgroup LED_SEG_ENABLE LED SEG enable
  * @{
  */
#define LL_LED_ENABLE_SEG0             (LED_CTRL_SE_0)
#define LL_LED_ENABLE_SEG1             (LED_CTRL_SE_1) 
#define LL_LED_ENABLE_SEG2             (LED_CTRL_SE_2) 
#define LL_LED_ENABLE_SEG3             (LED_CTRL_SE_3) 
#define LL_LED_ENABLE_SEG4             (LED_CTRL_SE_4) 
#define LL_LED_ENABLE_SEG5             (LED_CTRL_SE_5) 
#define LL_LED_ENABLE_SEG6             (LED_CTRL_SE_6) 
#define LL_LED_ENABLE_SEG7             (LED_CTRL_SE_7) 
#define LL_LED_ENABLE_SEG8             (LED_CTRL_SE_8) 
/**
  * @}
  */

/** @defgroup LED_DIMMING_STEP LED dimming step
  * @{
  */
#define LL_LED_DIMMING_STEP_16         (0x00000000U)                           /*!< 1/16 */
#define LL_LED_DIMMING_STEP_8          (LED_MODE_DIMS_0)                       /*!< 1/8  */
#define LL_LED_DIMMING_STEP_4          (LED_MODE_DIMS_1)                       /*!< 1/4  */
#define LL_LED_DIMMING_STEP_2          (LED_MODE_DIMS_1|LED_MODE_DIMS_0)       /*!< 1/2  */
#define LL_LED_DIMMING_STEP_1          (LED_MODE_DIMS_2)                       /*!< 1    */
/**
  * @}
  */

/** @defgroup LED_Flag LED Flag
  * @{
  */
#define LL_LED_FLAG_UIF                (LED_STATUS_UIF)                        /*!<  */
#define LL_LED_FLAG_FIF                (LED_STATUS_FIF)                        /*!<  */
#define LL_LED_FLAG_CIF                (LED_STATUS_CIF)                        /*!<  */
#define LL_LED_FLAG_PIF                (LED_STATUS_PIF)                        /*!<  */
/**
  * @}
  */

/** @defgroup LED_INT LED interrupt enable
  * @{
  */
#define LL_LED_INT_UIE                 (LED_CTRL_UIE)                          /*!<  */
#define LL_LED_INT_FIE                 (LED_CTRL_FIE)                          /*!<  */
#define LL_LED_INT_CIE                 (LED_CTRL_CIE)                          /*!<  */
#define LL_LED_INT_PIE                 (LED_CTRL_PIE)                          /*!<  */
/**
  * @}
  */

/** @defgroup LED_DMAREQ LED DMA requeset
  * @{
  */
#define LL_LED_DMAREQ_UDE              (LED_CTRL_UDE)                          /*!<  */
#define LL_LED_DMAREQ_FDE              (LED_CTRL_FDE)                          /*!<  */
#define LL_LED_DMAREQ_CDE              (LED_CTRL_CDE)                          /*!<  */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup LED_LL_Exported_Macros LED Exported Macros
  * @{
  */

/** @defgroup LED_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in LED register
  * @param  __INSTANCE__ LED Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_LED_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, __VALUE__)

/**
  * @brief  Read a value in LED register
  * @param  __INSTANCE__ LED Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_LED_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup LED_LL_Exported_Functions LED Exported Functions
  * @{
  */

/** @defgroup LED_LL_Exported_Functions_Group1 LED Configuration functions
  * @{
  */

/**
  * @brief  Set enabled segment.
  * @rmtoll CTRL           LED_CTRL_SE         LL_LED_SetSegmentEnable
  * @param  LEDx LED Instance
  * @param  Seg_Enable Enabled segment
  *         @arg @ref LL_LED_ENABLE_SEG0
  *         @arg @ref LL_LED_ENABLE_SEG1
  *         @arg @ref LL_LED_ENABLE_SEG2
  *         @arg @ref LL_LED_ENABLE_SEG3
  *         @arg @ref LL_LED_ENABLE_SEG4
  *         @arg @ref LL_LED_ENABLE_SEG5
  *         @arg @ref LL_LED_ENABLE_SEG6
  *         @arg @ref LL_LED_ENABLE_SEG7
  *         @arg @ref LL_LED_ENABLE_SEG8
  */
__STATIC_INLINE void LL_LED_SetSegmentEnable(LED_TypeDef *LEDx, uint32_t Seg_Enable)
{
  MODIFY_REG(LEDx->CTRL, LED_CTRL_SE, Seg_Enable);
}

/**
  * @brief  Set enabled comment.
  * @rmtoll CTRL           LED_CTRL_CE         LL_LED_SetCommentEnable
  * @param  LEDx LED Instance
  * @param  Com_Enable Enabled comment
  *         @arg @ref LL_LED_ENABLE_COM0
  *         @arg @ref LL_LED_ENABLE_COM1
  *         @arg @ref LL_LED_ENABLE_COM2
  *         @arg @ref LL_LED_ENABLE_COM3
  *         @arg @ref LL_LED_ENABLE_COM4
  *         @arg @ref LL_LED_ENABLE_COM5
  *         @arg @ref LL_LED_ENABLE_COM6
  *         @arg @ref LL_LED_ENABLE_COM7
  */
__STATIC_INLINE void LL_LED_SetCommentEnable(LED_TypeDef *LEDx, uint32_t Com_Enable)
{
  MODIFY_REG(LEDx->CTRL, LED_CTRL_CE, Com_Enable);
}

/**
  * @brief  Update DMA request enable.
  * @rmtoll CTRL          LED_CTRL_UDE      LL_LED_UpdateDMARequestEnable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_UpdateDMARequestEnable(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_UDE);
}

/**
  * @brief  Update DMA request disable.
  * @rmtoll CTRL          LED_CTRL_UDE      LL_LED_UpdateDMARequestDisable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_UpdateDMARequestDisable(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_UDE);
}

/**
  * @brief  COM DMA request enable.
  * @rmtoll CTRL          LED_CTRL_CDE      LL_LED_COMDMARequestEnable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_COMDMARequestEnable(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_CDE);
}

/**
  * @brief  COM DMA request disable.
  * @rmtoll CTRL          LED_CTRL_CDE      LL_LED_COMDMARequestDisable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_COMDMARequestDisable(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_CDE);
}

/**
  * @brief  Frame DMA request enable.
  * @rmtoll CTRL          LED_CTRL_FDE      LL_LED_FrameDMARequestEnable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_FrameDMARequestEnable(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_FDE);
}

/**
  * @brief  Frame DMA request disable.
  * @rmtoll CTRL          LED_CTRL_FDE      LL_LED_FrameDMARequestDisable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_FrameDMARequestDisable(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_FDE);
}

/**
  * @brief  Update interrupt enable.
  * @rmtoll CTRL          LED_CTRL_UIE      LL_LED_UpdateInterruptEnable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_UpdateInterruptEnable(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_UIE);
}

/**
  * @brief  Update interrupt Disable.
  * @rmtoll CTRL          LED_CTRL_UIE      LL_LED_UpdateInterruptDisable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_UpdateInterruptDisable(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_UIE);
}

/**
  * @brief  Frame interrupt enable.
  * @rmtoll CTRL          LED_CTRL_FIE      LL_LED_FrameInterruptEnable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_FrameInterruptEnable(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_FIE);
}

/**
  * @brief  Frame interrupt Disable.
  * @rmtoll CTRL          LED_CTRL_FIE      LL_LED_FrameInterruptDisable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_FrameInterruptDisable(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_FIE);
}

/**
  * @brief  COM interrupt enable.
  * @rmtoll CTRL          LED_CTRL_CIE      LL_LED_COMInterruptEnable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_COMInterruptEnable(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_CIE);
}

/**
  * @brief  COM interrupt Disable.
  * @rmtoll CTRL          LED_CTRL_CIE      LL_LED_COMInterruptDisable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_COMInterruptDisable(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_CIE);
}

/**
  * @brief  Pre-read interrupt enable.
  * @rmtoll CTRL          LED_CTRL_PIE      LL_LED_PreReadInterruptEnable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_PreReadInterruptEnable(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_PIE);
}

/**
  * @brief  Pre-Read interrupt Disable.
  * @rmtoll CTRL          LED_CTRL_PIE      LL_LED_PreReadInterruptDisable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_PreReadInterruptDisable(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_PIE);
}

/**
  * @brief  Set current bias.
  * @rmtoll CTRL          LED_CTRL_ITRIM      LL_LED_SetCurrentBias
  * @param  LEDx LED Instance
  * @param  Bias Current bias
  */
__STATIC_INLINE void LL_LED_SetCurrentBias(LED_TypeDef *LEDx, uint32_t Bias)
{
  MODIFY_REG(LEDx->CTRL, LED_CTRL_ITRIM, Bias << LED_CTRL_ITRIM_Pos);
}

/**
  * @brief  Set update generate.
  * @rmtoll EG          LED_EG_UG      LL_LED_SetUpdateGenerate
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_SetUpdateGenerate(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->EG, LED_EG_UG);
}

/**
  * @brief  LED enable.
  * @rmtoll CTRL          LED_CTRL_LEDEN      LL_LED_Enable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_Enable(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_LEDEN);
}

/**
  * @brief  LED disable.
  * @rmtoll CTRL          LED_CTRL_LEDEN      LL_LED_Disable
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_Disable(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_LEDEN);
}

/**
  * @brief  LED analog on.
  * @rmtoll CTRL          LED_CTRL_ON      LL_LED_AnaOn
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_AnaOn(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_ON);
}

/**
  * @brief  LED analog off.
  * @rmtoll CTRL          LED_CTRL_ON      LL_LED_AnaOff
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_AnaOff(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_ON);
}

/**
  * @brief  LED MEMORY on.
  * @rmtoll CTRL          LED_CTRL_SWME      LL_LED_AnaOn
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_MemoryOn(LED_TypeDef *LEDx)
{
  SET_BIT(LEDx->CTRL, LED_CTRL_SWME);
}

/**
  * @brief  LED memory off.
  * @rmtoll CTRL          LED_CTRL_SWME      LL_LED_AnaOff
  * @param  LEDx LED Instance
  */
__STATIC_INLINE void LL_LED_MemoryOff(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->CTRL, LED_CTRL_SWME);
}

/**
  * @brief  Set pre-scaler.
  * @rmtoll CFG          LED_CFG_PSC      LL_LED_SetPrescaler
  * @param  LEDx LED Instance
  * @param  Prescaler clock prescaler
  */
__STATIC_INLINE void LL_LED_SetPrescaler(LED_TypeDef *LEDx, uint32_t Prescaler)
{
  MODIFT_REG(LEDx->CFG, LED_CFG_PSC, Prescaler);
}

/**
  * @brief  Set dead-time.
  * @rmtoll CFG          LED_CFG_DTW      LL_LED_SetDeadTime
  * @param  LEDx LED Instance
  * @param  Deadtime Dead time
  */
__STATIC_INLINE void LL_LED_SetDeadTime(LED_TypeDef *LEDx, uint32_t Deadtime)
{
  MODIFT_REG(LEDx->CFG, LED_CFG_DTW, Deadtime << LED_CFG_DTW_Pos);
}

/**
  * @brief  Set interpolator.
  * @rmtoll CFG          LED_CFG_IFN      LL_LED_SetInterpolator
  * @param  LEDx LED Instance
  * @param  Interpolator interpolator
  */
__STATIC_INLINE void LL_LED_SetInterpolator(LED_TypeDef *LEDx, uint32_t Interpolator)
{
  MODIFT_REG(LEDx->CFG, LED_CFG_IFN, Interpolator << LED_CFG_IFN_Pos);
}

/**
  * @brief  Set Run mode.
  * @rmtoll MODE          LED_MODE_RMD      LL_LED_SetRunMode
  * @param  LEDx LED Instance
  * @param  Mode run mode
  *         @arg @ref LL_LED_RMODE_ONOFF
  *         @arg @ref LL_LED_RMODE_BRIGHT
  */
__STATIC_INLINE void LL_LED_SetRunMode(LED_TypeDef *LEDx, uint32_t Mode)
{
  MODIFT_REG(LEDx->MODE, LED_MODE_RMD, Mode);
}

/**
  * @brief  Set Display mode.
  * @rmtoll MODE          LED_MODE_DMD      LL_LED_SetDisplayMode
  * @param  LEDx LED Instance
  * @param  Mode Display mode
  *         @arg @ref LL_LED_DMODE_NORMAL
  *         @arg @ref LL_LED_DMODE_DIMMING
  */
__STATIC_INLINE void LL_LED_SetDisplayMode(LED_TypeDef *LEDx, uint32_t Mode)
{
  MODIFT_REG(LEDx->MODE, LED_MODE_DMD, Mode);
}

/**
  * @brief  Set bright step.
  * @rmtoll MODE          LED_MODE_BRTS      LL_LED_SetBrightStep
  * @param  LEDx LED Instance
  * @param  Step bright step
  */
__STATIC_INLINE void LL_LED_SetBrightStep(LED_TypeDef *LEDx, uint32_t Step)
{
  MODIFT_REG(LEDx->MODE, LED_MODE_BRTS, Step << LED_MODE_BRTS_Pos);
}

/**
  * @brief  Set dimming step.
  * @rmtoll MODE          LED_MODE_DIMS      LL_LED_SetDimmingStep
  * @param  LEDx LED Instance
  * @param  Step dimming step
  */
__STATIC_INLINE void LL_LED_SetDimmingStep(LED_TypeDef *LEDx, uint32_t Step)
{
  MODIFT_REG(LEDx->MODE, LED_MODE_DIMS, Step << LED_MODE_DIMS_Pos);
}

/**
  * @brief  Set display buffer length.
  * @rmtoll MODE          LED_MODE_ALAST      LL_LED_SetDisplayBufferLength
  * @param  LEDx LED Instance
  * @param  Len Display buffer length in word
  */
__STATIC_INLINE void LL_LED_SetDisplayBufferLength(LED_TypeDef *LEDx, uint32_t Len)
{
  MODIFT_REG(LEDx->MODE, LED_MODE_ALAST, Len-1);
}

/**
  * @brief  Set display buffer frame number.
  * @rmtoll MODE          LED_MODE_BFN      LL_LED_SetDisplayBufferFrameNumber
  * @param  LEDx LED Instance
  * @param  FrameNumber Display buffer frame number
  */
__STATIC_INLINE void LL_LED_SetDisplayBufferFrameNumber(LED_TypeDef *LEDx, uint32_t FrameNumber)
{
  MODIFT_REG(LEDx->MODE, LED_MODE_BFN, FrameNumber-1);
}

/**
  * @brief  Set display frame length in on-off mode.
  * @rmtoll MODE          LED_MODE_BFN      LL_LED_SetDisplayBufferFrameLengthOnOff
  * @param  LEDx LED Instance
  * @param  FrameLength Display buffer frame length
  */
__STATIC_INLINE void LL_LED_SetDisplayBufferFrameLengthOnOff(LED_TypeDef *LEDx, uint32_t FrameLength)
{
  MODIFT_REG(LEDx->MODE, LED_MODE_DN, FrameLength);
}

/**
  * @brief  Set segment brightness maximum.
  * @rmtoll BRGx          LED_BRG_BRTx      LL_LED_SetSegBrightMax
  * @param  LEDx LED Instance
  * @param  SegIdx segment index
  * @param  BrgMax Segment brightness maximum
  */
__STATIC_INLINE void LL_LED_SetSegBrightMax(LED_TypeDef *LEDx, uint32_t SegIdx, uint32_t BrgMax)
{
  uint32_t* addr = (uint32_t*)(&(LEDx->BRG1) + ((SegIdx >> 2) << 2));
  uint32_t pos = ((SegIdx & 0x03) << 3);  
  *addr &= ~(0x000000FFUL << pos);
  *addr |= (BrgMax << pos);
}

/**
  * @brief  Get Flag.
  * @rmtoll STATUS                LL_LED_GetAllFlag
  * @param  LEDx LED Instance
  * @retval uint32_t flag
  */
__STATIC_INLINE uint32_t LL_LED_GetAllFlag(LED_TypeDef *LEDx)
{
  return READ_BIT(LEDx->STATUS, LED_STATUS_UIF|LED_STATUS_FIF|LED_STATUS_CIF|LED_STATUS_PIF);
}

/**
  * @brief  Check Flag.
  * @param  Flag Flags
  * @param  ID Flag ID
  * @retval uint32_t SET ot RESET
  */
__STATIC_INLINE uint32_t LL_LED_IsFlag(uint32_t Flag, uint32_t ID)
{
  return ((Flag & ID) ? SET : RESET);
}

/**
  * @brief  Get Flag.
  * @rmtoll STATUS                LL_LED_GetFlag
  * @param  LEDx LED Instance
  * @param  Flag the value is one of the following value
  *       @arg @ref LL_LED_FLAG_UIF
  *       @arg @ref LL_LED_FLAG_FIF
  *       @arg @ref LL_LED_FLAG_CIF
  *       @arg @ref LL_LED_FLAG_PIF
  * @retval uint32_t flag
  */
__STATIC_INLINE uint32_t LL_LED_GetFlag(LED_TypeDef *LEDx, uint32_t Flag)
{
  return READ_BIT(LEDx->STATUS, Flag);
}

/**
  * @brief  Clear Flag.
  * @rmtoll STATUS                LL_LED_ClearFlag
  * @param  LEDx LED Instance
  * @retval uint32_t flag
  */
__STATIC_INLINE uint32_t LL_LED_ClearFlag(LED_TypeDef *LEDx)
{
  return READ_REG(LEDx->STATUS);
}

/**
  * @brief  Get FSM state.
  * @rmtoll DEBUG       LED_DEBUG_FSM         LL_LED_GetState
  * @param  LEDx LED Instance
  * @retval uint32_t FSM state
  */
__STATIC_INLINE uint32_t LL_LED_GetState(LED_TypeDef *LEDx)
{
  return READ_BIT(LEDx->DEBUG, LED_DEBUG_FSM);
}

/**
  * @brief  Get Display frame index.
  * @rmtoll DEBUG      LED_DEBUG_FRMN          LL_LED_GetDisplayFrameIndex
  * @param  LEDx LED Instance
  * @retval uint32_t display frame index
  */
__STATIC_INLINE uint32_t LL_LED_GetDisplayFrameIndex(LED_TypeDef *LEDx)
{
  return READ_BIT(LEDx->DEBUG, LED_DEBUG_FRMN);
}

/**
  * @brief  Check buffer error.
  * @rmtoll DEBUG      LED_DEBUG_BUFERR          LL_LED_CheckBufferError
  * @param  LEDx LED Instance
  * @retval uint32_t state (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_LED_CheckBufferError(LED_TypeDef *LEDx)
{
return ((READ_BIT(LEDx->DEBUG, LED_DEBUG_BUFERR)) ? SET : RESET);
}

/**
  * @brief  clear buffer error.
  * @rmtoll DEBUG      LED_DEBUG_BUFERR          LL_LED_CheckBufferError
  * @param  LEDx LED Instance
  */
__STATIC_INLINE uint32_t LL_LED_ClearBufferError(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->DEBUG, LED_DEBUG_BUFERR);
}

/**
  * @brief  Check analog on error.
  * @rmtoll DEBUG      LED_DEBUG_ADONERR          LL_LED_CheckAnalogOnError
  * @param  LEDx LED Instance
  * @retval uint32_t state (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_LED_CheckAnalogOnError(LED_TypeDef *LEDx)
{
return ((READ_BIT(LEDx->DEBUG, LED_DEBUG_ADONERR)) ? SET : RESET);
}

/**
  * @brief  clear analog on error.
  * @rmtoll DEBUG      LED_DEBUG_ADONERR          LL_LED_CheckAnalogOnError
  * @param  LEDx LED Instance
  */
__STATIC_INLINE uint32_t LL_LED_ClearAnalogOnError(LED_TypeDef *LEDx)
{
  CLEAR_BIT(LEDx->DEBUG, LED_DEBUG_ADONERR);
}

/**
  * @}
  */


#if defined(USE_FULL_LL_DRIVER)
/** @defgroup LED_LL_Exported_Functions_Group2 Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_LED_DeInit(LED_TypeDef *LEDx);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(LED) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_LED_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
