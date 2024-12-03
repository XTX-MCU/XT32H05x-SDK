/**
  ******************************************************************************
  * @file    xt32h0xx_hal_adc.h
  * @author  Software Team
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_H
#define XT32H0xx_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"
#include "xt32h0xx_ll_system.h"
#include "xt32h0xx_hal_conf.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup HAL HAL
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup HAL_Exported_Types HAL Exported Types
  * @{
  */
/** @defgroup HAL_TICK_FREQ Tick Frequency
  * @{
  */
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;
/**
  * @}
  */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup HAL_Exported_Constants HAL Exported Constants
  * @{
  */

/** @defgroup HAL_Boot_Mode HAL Boot Mode
  * @{
  */
#define SYSCFG_BOOT_FLASH              (0x00000000U)                           /*!< Flash memory mapped at 0x0000 0000 */
#define SYSCFG_BOOT_ROM                (SYSCFG_SYS_CFG_BOOT_MODE_0)            /*!< ROM memory mapped at 0x0000 0000 */
#define SYSCFG_BOOT_SRAM               (SYSCFG_SYS_CFG_BOOT_MODE_1 | SYSCFG_SYS_CFG_BOOT_MODE_0)  /*!< Embedded SRAM mapped at 0x0000 0000 */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup HAL_Exported_Macros HAL Exported Macros
  * @{
  */

/** @defgroup HAL_Memory_Mapped HAL Memory Mapped
  * @{
  */

/** @brief  Main Flash memory mapped at 0x00000000
  */
#define __HAL_SYSCFG_REMAPMEMORY_FLASH()    MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_BOOT_MODE, SYSCFG_BOOT_FLASH)

/** @brief  System Flash memory mapped at 0x00000000
  */
#define __HAL_SYSCFG_REMAPMEMORY_ROM()      MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_BOOT_MODE, SYSCFG_BOOT_ROM)

/** @brief  Embedded SRAM mapped at 0x00000000
  */
#define __HAL_SYSCFG_REMAPMEMORY_SRAM() \
  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_BOOT_MODE, SYSCFG_BOOT_SRAM)

/**
  * @brief  Return the boot mode as configured by user.
  * @retval The boot mode as configured by user. The returned value can be one
  *         of the following values @ref HAL_Boot_Mode
  */
#define __HAL_SYSCFG_GET_BOOT_MODE()           READ_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_BOOT_MODE)

/**
  * @}
  */

/**
  * @}
  */

/* Exported variables ---------------------------------------------------------*/
/** @addtogroup HAL_Exported_Variables
  * @{
  */
extern __IO uint32_t uwTick;
extern uint32_t uwTickPrio;
extern HAL_TickFreqTypeDef uwTickFreq;
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup HAL_Private_Macros HAL Private Macros
  * @{
  */
#define IS_TICKFREQ(FREQ) (((FREQ) == HAL_TICK_FREQ_10HZ)  || \
                           ((FREQ) == HAL_TICK_FREQ_100HZ) || \
                           ((FREQ) == HAL_TICK_FREQ_1KHZ))
/**
  * @}
  */
/* Exported functions --------------------------------------------------------*/

/** @defgroup HAL_Exported_Functions HAL Exported Functions
  * @{
  */

/** @defgroup HAL_Exported_Functions_Group1 HAL Initialization and Configuration functions
  * @{
  */

/* Initialization and Configuration functions  ******************************/
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group2 HAL Control functions
  * @{
  */

/* Peripheral Control functions  ************************************************/
void HAL_IncTick(void);
void HAL_Delay(uint32_t Delay);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);
uint32_t HAL_GetHalVersion(void);
void HAL_GetUID(uint32_t * pUID);

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group3 SYSCFG configuration functions
  * @{
  */

/* SYSCFG Control functions  ****************************************************/
void HAL_SYSCFG_EnableVoltageDetect(uint32_t TriggerValue);
void HAL_SYSCFG_DisableVoltageDetect(void);
void HAL_SYSCFG_SetVoltageDetectTrigger(uint32_t TriggerValue);
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

#endif /* XT32H0xx_HAL_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
