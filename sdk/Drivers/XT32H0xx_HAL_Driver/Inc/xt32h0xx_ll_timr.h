/**
  ******************************************************************************
  * @file    xt32h0xx_ll_timr.h
  * @author  Software Team
  * @brief   Header file of TIM LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0xx_LL_TIMR_H
#define __XT32H0xx_LL_TIMR_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if (defined (TIMB11) || defined (TIMB12) || defined (TIMB13) || defined (TIMB14) || defined (TIMB21) || defined (TIMB22) || defined (TIMB23) || defined (TIMB24)) 

/** @defgroup TIMR_LL TIMR
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup TIMR_LL_Private_Constants TIM Private Constants
  * @{
  */

/** @defgroup LL_TIMR_CHANNEL_group timer channel
  * @{
  */
#define LL_TIMR_CHANNEL_0              (0x00000001UL)  
#define LL_TIMR_CHANNEL_1              (0x00000002UL)  
#define LL_TIMR_CHANNEL_2              (0x00000004UL)  
#define LL_TIMR_CHANNEL_3              (0x00000008UL)  
#define LL_TIMR_CHANNEL_4              (0x00000010UL)  
#define LL_TIMR_CHANNEL_5              (0x00000020UL)  
#define LL_TIMR_CHANNEL_6              (0x00000040UL)  
#define LL_TIMR_CHANNEL_7              (0x00000080UL)  

#define LL_TIMR_CHANNEL_10             (0x00000001UL)  
#define LL_TIMR_CHANNEL_11             (0x00000002UL)  
#define LL_TIMR_CHANNEL_12             (0x00000004UL)  
#define LL_TIMR_CHANNEL_13             (0x00000008UL)  
#define LL_TIMR_CHANNEL_14             (0x00000010UL)  
#define LL_TIMR_CHANNEL_15             (0x00000020UL)  
#define LL_TIMR_CHANNEL_16             (0x00000040UL)  
#define LL_TIMR_CHANNEL_17             (0x00000080UL)  
/**
  * @}
  */

/** @defgroup LL_TIMR_CHANNEL_IT_group timer channel
  * @{
  */
#define LL_TIMR_CHANNEL_IT_0           (0x00000001UL)  
#define LL_TIMR_CHANNEL_IT_1           (0x00000002UL)  
#define LL_TIMR_CHANNEL_IT_2           (0x00000004UL)  
#define LL_TIMR_CHANNEL_IT_3           (0x00000008UL)  
#define LL_TIMR_CHANNEL_IT_4           (0x00000010UL)  
#define LL_TIMR_CHANNEL_IT_5           (0x00000020UL)  
#define LL_TIMR_CHANNEL_IT_6           (0x00000040UL)  
#define LL_TIMR_CHANNEL_IT_7           (0x00000080UL)  

#define LL_TIMR_CHANNEL_IT_10          (0x00000001UL)  
#define LL_TIMR_CHANNEL_IT_11          (0x00000002UL)  
#define LL_TIMR_CHANNEL_IT_12          (0x00000004UL)  
#define LL_TIMR_CHANNEL_IT_13          (0x00000008UL)  
#define LL_TIMR_CHANNEL_IT_14          (0x00000010UL)  
#define LL_TIMR_CHANNEL_IT_15          (0x00000020UL)  
#define LL_TIMR_CHANNEL_IT_16          (0x00000040UL)  
#define LL_TIMR_CHANNEL_IT_17          (0x00000080UL)  
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup TIMR_LL_Private_Macros TIM Private Macros
  * @{
  */
/** @brief  Convert channel id into channel index.
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref LL_TIMR_CHANNEL_0
  *         @arg @ref LL_TIMR_CHANNEL_1
  *         @arg @ref LL_TIMR_CHANNEL_2
  *         @arg @ref LL_TIMR_CHANNEL_3
  *         @arg @ref LL_TIMR_CHANNEL_4
  *         @arg @ref LL_TIMR_CHANNEL_5
  *         @arg @ref LL_TIMR_CHANNEL_6
  *         @arg @ref LL_TIMR_CHANNEL_7
  *         @arg @ref LL_TIMR_CHANNEL_10
  *         @arg @ref LL_TIMR_CHANNEL_11
  *         @arg @ref LL_TIMR_CHANNEL_12
  *         @arg @ref LL_TIMR_CHANNEL_13
  *         @arg @ref LL_TIMR_CHANNEL_14
  *         @arg @ref LL_TIMR_CHANNEL_15
  *         @arg @ref LL_TIMR_CHANNEL_16
  *         @arg @ref LL_TIMR_CHANNEL_17
  */
#define TIMR_GET_CHANNEL_INDEX( __CHANNEL__)  ((((__CHANNEL__) == LL_TIMR_CHANNEL_0) || (__CHANNEL__) == (LL_TIMR_CHANNEL_10)) ? 0UL : \
                                              (((__CHANNEL__) == LL_TIMR_CHANNEL_1) || (__CHANNEL__) == (LL_TIMR_CHANNEL_11)) ? 1UL : \
                                              (((__CHANNEL__) == LL_TIMR_CHANNEL_2) || (__CHANNEL__) == (LL_TIMR_CHANNEL_12)) ? 2UL : \
                                              (((__CHANNEL__) == LL_TIMR_CHANNEL_3) || (__CHANNEL__) == (LL_TIMR_CHANNEL_13)) ? 3UL : \
                                              (((__CHANNEL__) == LL_TIMR_CHANNEL_4) || (__CHANNEL__) == (LL_TIMR_CHANNEL_14)) ? 4UL : \
                                              (((__CHANNEL__) == LL_TIMR_CHANNEL_5) || (__CHANNEL__) == (LL_TIMR_CHANNEL_15)) ? 5UL : \
                                              (((__CHANNEL__) == LL_TIMR_CHANNEL_6) || (__CHANNEL__) == (LL_TIMR_CHANNEL_16)) ? 6UL : \
                                              7UL)

/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
/** @defgroup TIMR_LL_Exported_Types TIMR Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup TIMR_LL_ES_INIT TIMR Exported Init structure
  * @{
  */

/**
  * @brief  TIM Time Base configuration structure definition.
  */
typedef struct
{
  uint32_t InitialValue;      /*!< Specifies the initial value used to loaded to the TIM counter.
                                   This parameter can be a number between Min_Data=0x0000 and Max_Data=0xFFFF.

                                   This feature can be modified afterwards using unitary function
                                   @ref LL_TIMR_SetLoadCount().*/

  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref TIMR_LL_EC_MODE.

                                   This feature can be modified afterwards using unitary function
                                   @ref LL_TIMR_SetMode().*/

  uint32_t ItEnable;         /*!< Specifies the interupt enable.
                                   This parameter can be a value of @ref TIMR_LL_EC_IT_MASK.

                                   This feature can be modified afterwards using unitary function
                                   @ref LL_TIMR_MaskIT().*/

} LL_TIMR_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup TIMR_LL_Exported_Constants TIM Exported Constants
  * @{
  */

/** @defgroup TIMR_LL_EC_MODE Timer mode
  * @{
  */
#define LL_TIMR_MODE_FREERUNNING       (0x00000000U )                          /*!< Free-runningmode */
#define LL_TIMR_MODE_USERDEFINED       (TIMR_CR_MODE)                          /*!< User-defined count mode */
/**
  * @}
  */

/** @defgroup TIMR_LL_EC_ENABLE Timer enable
  * @{
  */
#define LL_TIMR_DISABLE                (0x00000000U)                           /*!< Timer disabled */
#define LL_TIMR_ENABLE                 (TIMR_CR_EN)                            /*!< Timer enabled  */
/**
  * @}
  */

/** @defgroup TIMR_LL_EC_IT_MASK Interrupt mask
  * @{
  */
#define LL_TIMR_IT_UNMASK              (0x00000000U)                           /*!< Unmask interrupt */
#define LL_TIMR_IT_MASK                (TIMR_CR_IM )                           /*!< Mask interrupt   */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup TIMR_LL_Exported_Macros TIM Exported Macros
  * @{
  */

/** @defgroup TIMR_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */
/**
  * @brief  Write a value in TIM register.
  * @param  __INSTANCE__ TIM Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_TIMR_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG((__INSTANCE__)->__REG__, (__VALUE__))

/**
  * @brief  Read a value in TIM register.
  * @param  __INSTANCE__ TIM Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_TIMR_ReadReg(__INSTANCE__, __REG__) READ_REG((__INSTANCE__)->__REG__)
/**
  * @}
  */

/** @defgroup TIMR_LL_EM_Exported_Macros Exported_Macros
  * @{
  */
/**
  * @brief  Get time sys.
  * @param  __HANDLE__ TIM handle
  * @retval TIM Sys
  */
#define LL_TIMR_GET_TIMRSYS(__HANDLE__) ((((__HANDLE__) == (TIMB10)) || \
                                        ((__HANDLE__) == (TIMB11)) || \
                                        ((__HANDLE__) == (TIMB12)) || \
                                        ((__HANDLE__) == (TIMB13)) || \
                                        ((__HANDLE__) == (TIMB14)) || \
                                        ((__HANDLE__) == (TIMB15)) || \
                                        ((__HANDLE__) == (TIMB16)) || \
                                        ((__HANDLE__) == (TIMB17))) ? TIMRSYSB1 : \
                                       (((__HANDLE__) == (TIMB20)) || \
                                        ((__HANDLE__) == (TIMB21)) || \
                                        ((__HANDLE__) == (TIMB22)) || \
                                        ((__HANDLE__) == (TIMB23)) || \
                                        ((__HANDLE__) == (TIMB24)) || \
                                        ((__HANDLE__) == (TIMB25)) || \
                                        ((__HANDLE__) == (TIMB26)) || \
                                        ((__HANDLE__) == (TIMB27))) ? TIMRSYSB2 : \
                                       (((__HANDLE__) == (TIMG0)) || \
                                        ((__HANDLE__) == (TIMG1)) || \
                                        ((__HANDLE__) == (TIMG2)) || \
                                        ((__HANDLE__) == (TIMG3)) || \
                                        ((__HANDLE__) == (TIMG4)) || \
                                        ((__HANDLE__) == (TIMG5)) || \
                                        ((__HANDLE__) == (TIMG6)) || \
                                        ((__HANDLE__) == (TIMG7))) ? TIMRSYSG : \
                                        TIMRSYSG )
/**
  * @}
  */


/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup TIMR_LL_Exported_Functions TIM Exported Functions
  * @{
  */

/** @defgroup TIMR_LL_EF_Time_Base Time Base configuration
  * @{
  */
/**
  * @brief  Enable timer counter.
  * @rmtoll CR          EN           LL_TIMR_EnableCounter
  * @param  TIMx Timer instance
  */
__STATIC_INLINE void LL_TIMR_EnableCounter(TIMR_TypeDef *TIMx)
{
  SET_BIT(TIMx->CR, TIMR_CR_EN);
}

/**
  * @brief  Disable timer counter.
  * @rmtoll CR          EN           LL_TIMR_DisableCounter
  * @param  TIMx Timer instance
  */
__STATIC_INLINE void LL_TIMR_DisableCounter(TIMR_TypeDef *TIMx)
{
  CLEAR_BIT(TIMx->CR, TIMR_CR_EN);
}

/**
  * @brief  Indicates whether the timer counter is enabled.
  * @rmtoll CR          EN           LL_TIMR_IsEnabledCounter
  * @param  TIMx Timer instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_TIMR_IsEnabledCounter(TIMR_TypeDef *TIMx)
{
  return ((READ_BIT(TIMx->CR, TIMR_CR_EN) == (TIMR_CR_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Unmask interrput.
  * @rmtoll CR          IM          LL_TIMR_UnmaskIT
  * @param  TIMx Timer instance
  */
__STATIC_INLINE void LL_TIMR_UnmaskIT(TIMR_TypeDef *TIMx)
{
  CLEAR_BIT(TIMx->CR, TIMR_CR_IM);
}

/**
  * @brief  Mask Interrupt.
  * @rmtoll CR          IM          LL_TIMR_MaskIT
  * @param  TIMx Timer instance
  */
__STATIC_INLINE void LL_TIMR_MaskIT(TIMR_TypeDef *TIMx)
{
  SET_BIT(TIMx->CR, TIMR_CR_IM);
}

/**
  * @brief  Indicates whether the interupt is masked.
  * @rmtoll CR          IM          LL_TIMR_IsMaskedIT
  * @param  TIMx Timer instance
  * @retval Inverted state of bit (0 or 1).
  */
__STATIC_INLINE uint32_t LL_TIMR_IsMaskedIT(TIMR_TypeDef *TIMx)
{
  return ((READ_BIT(TIMx->CR, TIMR_CR_IM) == TIMR_CR_IM) ? 1UL : 0UL);
}

/**
  * @brief  Set timr mode
  * @rmtoll CR          MODE           LL_TIMR_SetMode
  * @param  TIMx Timer instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_TIMR_MODE_FREERUNNING
  *         @arg @ref LL_TIMR_MODE_USERDEFINED
  */
__STATIC_INLINE void LL_TIMR_SetMode(TIMR_TypeDef *TIMx, uint32_t Mode)
{
  MODIFY_REG(TIMx->CR, TIMR_CR_MODE, Mode);
}

/**
  * @brief  Get actual event update source
  * @rmtoll CR          MODE           LL_TIMR_GetMode
  * @param  TIMx Timer instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_TIMR_MODE_FREERUNNING
  *         @arg @ref LL_TIMR_MODE_USERDEFINED
  */
__STATIC_INLINE uint32_t LL_TIMR_GetMode(TIMR_TypeDef *TIMx)
{
  return (uint32_t)(READ_BIT(TIMx->CR, TIMR_CR_MODE));
}

/**
  * @brief  Get current value of counter.
  * @rmtoll CV         value            LL_TIMR_GetCurrentValue
  * @param  TIMx Timer instance
  * @retval value is between 0 and 0xFFFFFFFF (based TIMER_WIDTH)
  */
__STATIC_INLINE uint32_t LL_TIMR_GetCurrentValue(TIMR_TypeDef *TIMx)
{
  return (uint32_t)(READ_REG(TIMx->CV));
}

/**
  * @brief  Set load count.
  * @rmtoll LC         value            LL_TIMR_SetLoadCount
  * @param  TIMx Timer instance
  * @param  Count value is between 0 and 0xFFFFFFFF (based TIMER_WIDTH)
  */
__STATIC_INLINE void LL_TIMR_SetLoadCount(TIMR_TypeDef *TIMx, uint32_t Count)
{
  WRITE_REG(TIMx->LC, Count);
}

/**
  * @brief  Get load count
  * @rmtoll LC                    LL_TIMR_GetLoadCount
  * @param  TIMx Timer instance
  * @retval value is between 0 and 0xFFFFFFFF (based TIMER_WIDTH)
  */
__STATIC_INLINE uint32_t LL_TIMR_GetLoadCount(TIMR_TypeDef *TIMx)
{
  return (uint32_t)(READ_REG(TIMx->LC));
}

/**
  * @brief  Clear interrupt
  * @rmtoll EOI          EOI           LL_TIMR_ClearIT
  * @param  TIMx Timer instance
  */
__STATIC_INLINE void LL_TIMR_ClearIT(TIMR_TypeDef *TIMx)
{
  READ_REG(TIMx->EOI);
}

/**
  * @brief  Get interrupt status
  * @rmtoll STAT          STAT           LL_TIMR_GetITStat
  * @param  TIMx Timer instance
  * @retval status 0 or 1.
  */
__STATIC_INLINE uint32_t LL_TIMR_GetITStat(TIMR_TypeDef *TIMx)
{
  return (uint32_t)(READ_REG(TIMx->STAT));
}

/**
  * @brief  Get timers interrupt status
  * @rmtoll STAT          STAT           LL_TIMRSYS_GetITStat
  * @param  TIMRSYSx Timer instance
  * @retval value can be conbimed of the following values:
  *         @arg @ref LL_TIMR_CHANNEL_IT_0   
  *         @arg @ref LL_TIMR_CHANNEL_IT_1   
  *         @arg @ref LL_TIMR_CHANNEL_IT_2   
  *         @arg @ref LL_TIMR_CHANNEL_IT_3   
  *         @arg @ref LL_TIMR_CHANNEL_IT_4   
  *         @arg @ref LL_TIMR_CHANNEL_IT_5   
  *         @arg @ref LL_TIMR_CHANNEL_IT_6   
  *         @arg @ref LL_TIMR_CHANNEL_IT_7   
  *         @arg @ref LL_TIMR_CHANNEL_IT_10  
  *         @arg @ref LL_TIMR_CHANNEL_IT_11  
  *         @arg @ref LL_TIMR_CHANNEL_IT_12  
  *         @arg @ref LL_TIMR_CHANNEL_IT_13  
  *         @arg @ref LL_TIMR_CHANNEL_IT_14  
  *         @arg @ref LL_TIMR_CHANNEL_IT_15  
  *         @arg @ref LL_TIMR_CHANNEL_IT_16  
  *         @arg @ref LL_TIMR_CHANNEL_IT_17  
  */
__STATIC_INLINE uint32_t LL_TIMRSYS_GetITStat(TIMRSYS_TypeDef *TIMRSYSx)
{
  return (uint32_t)(READ_REG(TIMRSYSx->STAT));
}

/**
  * @brief  Clear all timers interrupt
  * @rmtoll EOI          EOI           LL_TIMRSYS_ClearIT
  * @param  TIMRSYSx Timer instance
  */
__STATIC_INLINE void LL_TIMRSYS_ClearIT(TIMRSYS_TypeDef *TIMRSYSx)
{
  READ_REG(TIMRSYSx->EOI);
}

#if 0
/**
  * @brief  Get Timer version
  * @rmtoll Ver          version           LL_TIMR_GetVersion
  * @param  TIMRSYSx Timer instance
  * @retval value 32-bit version.
  */
__STATIC_INLINE uint32_t LL_TIMR_GetVersion(TIMRSYS_TypeDef *TIMRSYSx)
{
  return (uint32_t)(READ_REG(TIMRSYSx->VER));
}
#endif
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup TIMR_LL_EF_Init Initialisation and deinitialisation functions
  * @{
  */

ErrorStatus LL_TIMR_DeInit(TIMR_TypeDef *TIMx);
void LL_TIMR_StructInit(LL_TIMR_InitTypeDef *TIMR_InitStruct);
ErrorStatus LL_TIMR_Init(TIMR_TypeDef *TIMx, LL_TIMR_InitTypeDef *TIMR_InitStruct);
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */


#endif /* TIMB10 || TIMB11 || TIMB12 || TIMB13 || TIMB14 || TIMB15 || TIMB16 || TIMB17 || 
          TIMB20 || TIMB21 || TIMB22 || TIMB23 || TIMB24 || TIMB25 || TIMB26 || TIMB27 || 
          TIMG0 || TIMG1 || TIMG2 || TIMG3 || TIMG4 || TIMG5 || TIMG6 || TIMG7 */

/**
  * @}
  */

/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif /* __XT32H0xx_LL_TIMR_H */
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
