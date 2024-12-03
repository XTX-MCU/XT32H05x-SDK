/**
  ******************************************************************************
  * @file    xt32h0xx_hal_wdt.h
  * @author  Software Team
  * @brief   Header file of WDT HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_WDT_H
#define XT32H0xx_HAL_WDT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup WDT WDT
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup WDT_Exported_Types WDT Exported Types
  * @{
  */

/**
  * @brief  WDT Init structure definition
  */
typedef struct
{
  uint32_t Rpl;        /*!< Select the reset pulse length of the WDT.
                            This parameter can be a value of @ref WDT_RPL */

  uint32_t Rmod;       /*!< Response mode of the WDT
                            This parameter can be a value of @ref WDT_RMOD */

  uint32_t Range;     /*!< Specifies the timeout range.
                            This parameter can be a value of @ref WDT_Range */

  uint32_t InitRange;     /*!< Specifies the timeout range for initialization.
                            This parameter can be a value of @ref WDT_Range */

} WDT_InitTypeDef;

/**
  * @brief  WDT Handle Structure definition
  */
typedef struct __WDT_HandleTypeDef
{
  WDT_TypeDef                 *Instance;  /*!< Register base address    */

  WDT_InitTypeDef             Init;       /*!< WDT required parameters */

  void (* TimeoutCallback)(struct __WDT_HandleTypeDef *hwdt);        /*!< WDT timeout callback        */
} WDT_HandleTypeDef;


/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup WDT_Exported_Constants WDT Exported Constants
  * @{
  */

/** @defgroup WDT_RMOD  Response Mode
  * @{
  */
#define WDT_RMOD_SYSRST                (0x00000000u << WDT_CR_RMOD_Pos)        /*!< WDT generate a system reset */
#define WDT_RMOD_INTRST                (0x00000001u << WDT_CR_RMOD_Pos)        /*!< WDT first generate an interruptand if it is not cleared by the time a second timeout occurs then generate a system reset */
/**
  * @}
  */

/** @defgroup WDT_RPL  Reset Pulse Length
  * @{
  */
#define WDT_RPL_2                      (0x00000000u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 2   pclk cycles */
#define WDT_RPL_4                      (0x00000001u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 4   pclk cycles */
#define WDT_RPL_8                      (0x00000002u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 8   pclk cycles */
#define WDT_RPL_16                     (0x00000003u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 16  pclk cycles */
#define WDT_RPL_32                     (0x00000004u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 32  pclk cycles */
#define WDT_RPL_64                     (0x00000005u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 64  pclk cycles */
#define WDT_RPL_128                    (0x00000006u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 128 pclk cycles */
#define WDT_RPL_256                    (0x00000007u << WDT_CR_RPL_Pos)         /*!< WDT reset pulse length set to 256 pclk cycles */
/**
  * @}
  */

/** @defgroup WDT_Range  Range period
  * @{
  */
#define WDT_RANGE_PERIOD_0             (0)                                                   /*!< 0x0000FFFFUL */	
#define WDT_RANGE_PERIOD_1             (WDT_TORR_TOP_0)                                      /*!< 0x0001FFFFUL */	
#define WDT_RANGE_PERIOD_2             (WDT_TORR_TOP_1)                                      /*!< 0x0003FFFFUL */	
#define WDT_RANGE_PERIOD_3             (WDT_TORR_TOP_1|WDT_TORR_TOP_0)                       /*!< 0x0007FFFFUL */	
#define WDT_RANGE_PERIOD_4             (WDT_TORR_TOP_2)                                      /*!< 0x000FFFFFUL */	
#define WDT_RANGE_PERIOD_5             (WDT_TORR_TOP_2|WDT_TORR_TOP_0)                       /*!< 0x001FFFFFUL */	
#define WDT_RANGE_PERIOD_6             (WDT_TORR_TOP_2|WDT_TORR_TOP_1)                       /*!< 0x003FFFFFUL */	
#define WDT_RANGE_PERIOD_7             (WDT_TORR_TOP_2|WDT_TORR_TOP_1|WDT_TORR_TOP_0)        /*!< 0x007FFFFFUL */	
#define WDT_RANGE_PERIOD_8             (WDT_TORR_TOP_3)                                      /*!< 0x00FFFFFFUL */	
#define WDT_RANGE_PERIOD_9             (WDT_TORR_TOP_3|WDT_TORR_TOP_0)                       /*!< 0x01FFFFFFUL */	
#define WDT_RANGE_PERIOD_10            (WDT_TORR_TOP_3|WDT_TORR_TOP_1)                       /*!< 0x03FFFFFFUL */	
#define WDT_RANGE_PERIOD_11            (WDT_TORR_TOP_3|WDT_TORR_TOP_1|WDT_TORR_TOP_0)        /*!< 0x07FFFFFFUL */	
#define WDT_RANGE_PERIOD_12            (WDT_TORR_TOP_3|WDT_TORR_TOP_2)                       /*!< 0x0FFFFFFFUL */	
#define WDT_RANGE_PERIOD_13            (WDT_TORR_TOP_3|WDT_TORR_TOP_2|WDT_TORR_TOP_0)        /*!< 0x1FFFFFFFUL */	
#define WDT_RANGE_PERIOD_14            (WDT_TORR_TOP_3|WDT_TORR_TOP_2|WDT_TORR_TOP_1)        /*!< 0x3FFFFFFFUL */	
#define WDT_RANGE_PERIOD_15            (WDT_TORR_TOP_3|WDT_TORR_TOP_2|WDT_TORR_TOP_1|WDT_TORR_TOP_0)  /*!< 0x7FFFFFFFUL */	
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup WDT_Exported_Macros WDT Exported Macros
  * @{
  */

/**
  * @brief  Enable WDT.
  * @param  __HANDLE__  WDT handle
  * @retval None
  */
#define __HAL_WDT_ENABLE(__HANDLE__)               SET_BIT((__HANDLE__)->Instance->CR, WDT_CR_EN)

/**
  * @brief  Disable WDT.
  * @param  __HANDLE__  WDT handle
  * @retval None
  */
#define __HAL_WDT_DISABLE(__HANDLE__)              CLEAR_BIT((__HANDLE__)->Instance->CR, WDT_CR_EN)

/**
  * @brief  Reset WDT counter.
  * @param  __HANDLE__  WDT handle
  * @retval None
  */
#define __HAL_WDT_RESTART(__HANDLE__)              WRITE_REG((__HANDLE__)->Instance->CRR, LL_WDT_CCR)

/**
  * @brief  Get interrupt stauts.
  * @param  __HANDLE__  WDT handle
  * @retval None
  */
#define __HAL_WDT_GET_INT(__HANDLE__)              READ_BIT((__HANDLE__)->Instance->STAT, WDT_STAT_STAT)

/**
  * @brief  Clear interrupt stauts.
  * @param  __HANDLE__  WDT handle
  * @retval None
  */
#define __HAL_WDT_CLEAR_INT(__HANDLE__)            READ_BIT((__HANDLE__)->Instance->EOI, WDT_EOI_EOI)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup WDT_Exported_Functions  WDT Exported Functions
  * @{
  */

/** @defgroup WDT_Exported_Functions_Group1 Initialization and Start functions
  * @{
  */
/* Initialization/Start functions  ********************************************/
HAL_StatusTypeDef     HAL_WDT_Init(WDT_HandleTypeDef *hwdt);
/**
  * @}
  */

/** @defgroup WDT_Exported_Functions_Group2 IO operation functions
  * @{
  */
/* I/O operation functions ****************************************************/
HAL_StatusTypeDef     HAL_WDT_Refresh(WDT_HandleTypeDef *hwdt);
/**
  * @}
  */

/** @defgroup WDT_Exported_Functions_Group3 IRQ handle and interrupt functions
  * @{
  */
/* Interrupt operation functions ****************************************************/
void HAL_WDT_IRQHandler(WDT_HandleTypeDef *hwdt);
HAL_StatusTypeDef HAL_WDT_RegisterCallback(WDT_HandleTypeDef *hwdt, void (* pCallback)(WDT_HandleTypeDef *_hwdt));
HAL_StatusTypeDef HAL_WDT_UnRegisterCallback(WDT_HandleTypeDef *hwdt);
/**
  * @}
  */

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup WDT_Private_Constants WDT Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup WDT_Private_Macros WDT Private Macros
  * @{
  */

/**
  * @brief  Check WDT reset pulse length.
  * @param  __RPL__  WDT reset pulse length
  * @retval None
  */
#define IS_WDT_PRESCALER(__RPL__)            (((__RPL__) == WDT_RPL_2)  || \
                                               ((__RPL__) == WDT_RPL_4)  || \
                                               ((__RPL__) == WDT_RPL_8)  || \
                                               ((__RPL__) == WDT_RPL_16) || \
                                               ((__RPL__) == WDT_RPL_32) || \
                                               ((__RPL__) == WDT_RPL_64) || \
                                               ((__RPL__) == WDT_RPL_128)|| \
                                               ((__RPL__) == WDT_RPL_256))

/**
  * @brief  Check WDT timeout range.
  * @param  __TOP__  WDT timeout range
  * @retval None
  */
#define IS_WDT_TOP(__TOP__)                   ((__TOP__) <= WDT_TORR_TOP)

/**
  * @brief  Check WDT timeout range for initialization.
  * @param  __TOPINIT__  WDT timeour range
  * @retval None
  */
#define IS_WDT_TOPINIT(__TOPINIT__)           ((__TOPINIT__) <= WDT_TORR_TOP)


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

#endif /* XT2G0xx_HAL_WDT_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
