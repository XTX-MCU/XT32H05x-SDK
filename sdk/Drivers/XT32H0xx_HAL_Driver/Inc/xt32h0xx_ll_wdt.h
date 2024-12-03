/**
  ******************************************************************************
  * @file    xt32h0xx_ll_wdt.h
  * @author  Software Team
  * @brief   Header file of WDT LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_WDT_H
#define XT32H0xx_LL_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if (defined(WDTW) || defined(WDTI))

/** @defgroup WDT_LL WDT
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup WDT_LL_Private_Constants WDT Private Constants
  * @{
  */
#define LL_WDT_CCR                     (0x76)                                 /*!< WDT restart counter   */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup WDT_LL_Exported_Constants WDT Exported Constants
  * @{
  */

/** @defgroup WDT_LL_EC_RMOD  Response Mode
  * @{
  */
#define LL_WDT_RMOD_SYSRST             (0x00000000u << WDT_CR_RMOD_Pos)        /*!< WDT generate a system reset */
#define LL_WDT_RMOD_INTRST             (0x00000001u << WDT_CR_RMOD_Pos)        /*!< WDT first generate an interruptand if it is not cleared by the time a second timeout occurs then generate a system reset */
/**
  * @}
  */

/** @defgroup WDT_LL_EC_RPL  Reset Pulse Length
  * @{
  */
#define LL_WDT_RPL_2                   (0x00000000u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 2   pclk cycles */
#define LL_WDT_RPL_4                   (0x00000001u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 4   pclk cycles */
#define LL_WDT_RPL_8                   (0x00000002u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 8   pclk cycles */
#define LL_WDT_RPL_16                  (0x00000003u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 16  pclk cycles */
#define LL_WDT_RPL_32                  (0x00000004u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 32  pclk cycles */
#define LL_WDT_RPL_64                  (0x00000005u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 64  pclk cycles */
#define LL_WDT_RPL_128                 (0x00000006u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 128 pclk cycles */
#define LL_WDT_RPL_256                 (0x00000007u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 256 pclk cycles */
/**
  * @}
  */

/** @defgroup WDT_LL_EC_Range  Range period
  * @{
  */
#define LL_WDT_RANGE_PERIOD_0          (0)                                                   /*!< 0x0000FFFFUL */	
#define LL_WDT_RANGE_PERIOD_1          (WDT_TORR_TOP_0)                                      /*!< 0x0001FFFFUL */	
#define LL_WDT_RANGE_PERIOD_2          (WDT_TORR_TOP_1)                                      /*!< 0x0003FFFFUL */	
#define LL_WDT_RANGE_PERIOD_3          (WDT_TORR_TOP_1|WDT_TORR_TOP_0)                       /*!< 0x0007FFFFUL */	
#define LL_WDT_RANGE_PERIOD_4          (WDT_TORR_TOP_2)                                      /*!< 0x000FFFFFUL */	
#define LL_WDT_RANGE_PERIOD_5          (WDT_TORR_TOP_2|WDT_TORR_TOP_0)                       /*!< 0x001FFFFFUL */	
#define LL_WDT_RANGE_PERIOD_6          (WDT_TORR_TOP_2|WDT_TORR_TOP_1)                       /*!< 0x003FFFFFUL */	
#define LL_WDT_RANGE_PERIOD_7          (WDT_TORR_TOP_2|WDT_TORR_TOP_1|WDT_TORR_TOP_0)        /*!< 0x007FFFFFUL */	
#define LL_WDT_RANGE_PERIOD_8          (WDT_TORR_TOP_3)                                      /*!< 0x00FFFFFFUL */	
#define LL_WDT_RANGE_PERIOD_9          (WDT_TORR_TOP_3|WDT_TORR_TOP_0)                       /*!< 0x01FFFFFFUL */	
#define LL_WDT_RANGE_PERIOD_10         (WDT_TORR_TOP_3|WDT_TORR_TOP_1)                       /*!< 0x03FFFFFFUL */	
#define LL_WDT_RANGE_PERIOD_11         (WDT_TORR_TOP_3|WDT_TORR_TOP_1|WDT_TORR_TOP_0)        /*!< 0x07FFFFFFUL */	
#define LL_WDT_RANGE_PERIOD_12         (WDT_TORR_TOP_3|WDT_TORR_TOP_2)                       /*!< 0x0FFFFFFFUL */	
#define LL_WDT_RANGE_PERIOD_13         (WDT_TORR_TOP_3|WDT_TORR_TOP_2|WDT_TORR_TOP_0)        /*!< 0x1FFFFFFFUL */	
#define LL_WDT_RANGE_PERIOD_14         (WDT_TORR_TOP_3|WDT_TORR_TOP_2|WDT_TORR_TOP_1)        /*!< 0x3FFFFFFFUL */	
#define LL_WDT_RANGE_PERIOD_15         (WDT_TORR_TOP_3|WDT_TORR_TOP_2|WDT_TORR_TOP_1|WDT_TORR_TOP_0)  /*!< 0x7FFFFFFFUL */	
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup WDT_LL_Exported_Macros WDT Exported Macros
  * @{
  */

/** @defgroup WDT_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in WDT register
  * @param  __INSTANCE__ WDT Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_WDT_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in WDT register
  * @param  __INSTANCE__ WDT Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_WDT_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup WDT_LL_Exported_Functions WDT Exported Functions
  * @{
  */
/** @defgroup WDT_LL_EF_Configuration Configuration
  * @{
  */

/**
  * @brief  Enable the Independent Watchdog
  * @note   Except if the hardware watchdog option is selected
  * @rmtoll CR           WDT_EN           LL_WDT_Enable
  * @param  WDTx WDT Instance
  */
__STATIC_INLINE void LL_WDT_Enable(WDT_TypeDef *WDTx)
{
  SET_BIT(WDTx->CR, WDT_CR_EN);
}

/**
  * @brief  Dsiable the Independent Watchdog
  * @note   Except if the hardware watchdog option is selected
  * @rmtoll CR           WDT_EN           LL_WDT_Disable
  * @param  WDTx WDT Instance
  */
__STATIC_INLINE void LL_WDT_Disable(WDT_TypeDef *WDTx)
{
  CLEAR_BIT(WDTx->CR, WDT_CR_EN);
}

/**
  * @brief  Reloads WDT counter with value defined in the reload register
  * @rmtoll CRR           WDT_CCR           LL_WDT_RestartCounter
  * @param  WDTx WDT Instance
  */
__STATIC_INLINE void LL_WDT_RestartCounter(WDT_TypeDef *WDTx)
{
  WRITE_REG(WDTx->CRR, (LL_WDT_CCR << WDT_CRR_CCR_Pos));
}

/**
  * @brief  Select the reset pulse length of the WDT
  * @rmtoll CR           RPL            LL_WDT_SetResetPulseLength
  * @param  WDTx WDT Instance
  * @param  Rpl This parameter can be one of the following values:
  *         @arg @ref LL_WDT_RPL_2
  *         @arg @ref LL_WDT_RPL_4
  *         @arg @ref LL_WDT_RPL_8
  *         @arg @ref LL_WDT_RPL_16
  *         @arg @ref LL_WDT_RPL_32
  *         @arg @ref LL_WDT_RPL_64
  *         @arg @ref LL_WDT_RPL_128
  *         @arg @ref LL_WDT_RPL_256
  */
__STATIC_INLINE void LL_WDT_SetResetPulseLength(WDT_TypeDef *WDTx, uint32_t Rpl)
{
  MODIFY_REG(WDTx->CR, WDT_CR_RPL, Rpl);
}

/**
  * @brief  Get the reset pulse length of the WDT
  * @rmtoll CR           RPL            LL_WDT_GetResetPulseLength
  * @param  WDTx WDT Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_WDT_RPL_2
  *         @arg @ref LL_WDT_RPL_4
  *         @arg @ref LL_WDT_RPL_8
  *         @arg @ref LL_WDT_RPL_16
  *         @arg @ref LL_WDT_RPL_32
  *         @arg @ref LL_WDT_RPL_64
  *         @arg @ref LL_WDT_RPL_128
  *         @arg @ref LL_WDT_RPL_256
  */
__STATIC_INLINE uint32_t LL_WDT_GetResetPulseLength(WDT_TypeDef *WDTx)
{
  return (READ_REG(WDTx->CR) & WDT_CR_RPL);
}

/**
  * @brief  Specify the WDT response mode
  * @rmtoll CR          RMOD            LL_WDT_SetResponseMode
  * @param  WDTx WDT Instance
  * @param  Rmod Value can be one of the following values:
  *         @arg @ref LL_WDT_RMOD_SYSRST 
  *         @arg @ref LL_WDT_RMOD_INTRST 
  */
__STATIC_INLINE void LL_WDT_SetResponseMode(WDT_TypeDef *WDTx, uint32_t Rmod)
{
  MODIFY_REG(WDTx->CR, WDT_CR_RMOD, Rmod);
}

/**
  * @brief  Get the specified WDT esponse mode
  * @rmtoll CR          RMOD           LL_WDT_GetResponseMode
  * @param  WDTx WDT Instance
  * @retval Value can be one of the following values:
  *         @arg @ref LL_WDT_RMOD_SYSRST 
  *         @arg @ref LL_WDT_RMOD_INTRST 
  */
__STATIC_INLINE uint32_t LL_WDT_GetResponseMode(WDT_TypeDef *WDTx)
{
  return (READ_REG(WDTx->CR) & WDT_CR_RMOD);
}

#if defined(XT32H0xxB)
/**
  * @brief  Specify timeout range.
  * @rmtoll TORR         TOP           LL_WDT_SetTimeoutRange
  * @param  WDTx WDT Instance
  * @param  Range Value can be one of the following values:
  *         @arg @ref LL_WDT_RANGE_PERIOD_0          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_1          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_2          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_3          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_4          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_5          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_6          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_7          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_8          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_9          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_10         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_11         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_12         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_13         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_14         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_15         	
  */
__STATIC_INLINE void LL_WDT_SetTimeoutRange(WDT_TypeDef *WDTx, uint32_t Range)
{
  MODIFY_REG(WDTx->TORR, WDT_TORR_TOP, Range);
}

/**
  * @brief  Get timeout range.
  * @rmtoll TORR         TOP           LL_WDT_GetTimeoutRange
  * @param  WDTx WDT Instance
  * @retval return value can be one of the following values:
  *         @arg @ref LL_WDT_RANGE_PERIOD_0          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_1          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_2          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_3          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_4          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_5          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_6          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_7          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_8          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_9          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_10         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_11         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_12         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_13         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_14         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_15         	
  */
__STATIC_INLINE uint32_t LL_WDT_GetTimeoutRange(WDT_TypeDef *WDTx)
{
  return (READ_REG(WDTx->TORR) & WDT_TORR_TOP);
}


/**
  * @brief  Specify timeout range for initialization.
  * @rmtoll TORR         TOP_INIT     LL_WDT_SetInitTimeoutRange
  * @param  WDTx WDT Instance
  * @param  Range Value can be one of the following values:
  *         @arg @ref LL_WDT_RANGE_PERIOD_0          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_1          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_2          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_3          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_4          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_5          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_6          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_7          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_8          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_9          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_10         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_11         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_12         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_13         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_14         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_15         	
  */
__STATIC_INLINE void LL_WDT_SetInitTimeoutRange(WDT_TypeDef *WDTx, uint32_t Range)
{
  MODIFY_REG(WDTx->TORR, WDT_TORR_TOP_INIT, (Range << WDT_TORR_TOP_INIT_Pos));
}

/**
  * @brief  Get timeout range for initialization.
  * @rmtoll TORR         TOP_INIT      LL_WDT_GetInitTimeoutRange
  * @param  WDTx WDT Instance
  * @retval return value can be one of the following values:
  *         @arg @ref LL_WDT_RANGE_PERIOD_0          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_1          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_2          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_3          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_4          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_5          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_6          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_7          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_8          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_9          	
  *         @arg @ref LL_WDT_RANGE_PERIOD_10         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_11         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_12         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_13         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_14         	
  *         @arg @ref LL_WDT_RANGE_PERIOD_15         	
  */
__STATIC_INLINE uint32_t LL_WDT_GetInitTimeoutRange(WDT_TypeDef *WDTx)
{
  return ((READ_REG(WDTx->TORR) & WDT_TORR_TOP_INIT) >> WDT_TORR_TOP_INIT_Pos);
}
#endif
/**
  * @brief  Get current counter value.
  * @rmtoll CCVR                    LL_WDT_GetCurrentCounterValue
  * @param  WDTx WDT Instance
  * @retval Value between Min_Data=0 and Max_Data=0x0FFFFFFFF
  */
__STATIC_INLINE uint32_t LL_WDT_GetCurrentCounterValue(WDT_TypeDef *WDTx)
{
  return (READ_REG(WDTx->CCVR));
}
/**
  * @}
  */

/** @defgroup WDT_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Check if timeout
  * @rmtoll STAT           STAT           LL_WDT_IsTimeout
  * @param  WDTx WDT Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_WDT_IsTimeout(WDT_TypeDef *WDTx)
{
  return ((READ_BIT(WDTx->STAT, WDT_STAT_STAT) == (WDT_STAT_STAT)) ? 1UL : 0UL);
}

/**
  * @brief  Clear timeout interrupt
  * @rmtoll EOI           EOI           LL_WDT_ClearTimeout
  * @param  WDTx WDT Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_WDT_ClearTimeout(WDT_TypeDef *WDTx)
{
  return ((READ_BIT(WDTx->EOI, WDT_EOI_EOI) == (WDT_EOI_EOI)) ? 1UL : 0UL);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* WDTW || WDTI */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_WDT_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
