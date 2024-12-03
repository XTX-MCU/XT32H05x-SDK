/**
  ******************************************************************************
  * @file    xt32h0xx_hal_wdt.c
  * @author  Software Team
  * @brief   WDT HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Independent Watchdog (WDT) peripheral:
  *           + Initialization and Start functions
  *           + IO operation functions
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"
#include "xt32h0xx_ll_wdt.h"
#include "xt32h0xx_hal_wdt.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

#ifdef HAL_WDT_MODULE_ENABLED
/** @addtogroup WDT
  * @brief WDT HAL module driver.
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup WDT_Exported_Functions
  * @{
  */

/** @addtogroup WDT_Exported_Functions_Group1
  *  @brief    Initialization and Start functions.
  *
  * @{
  */

/**
  * @brief  Initialize the WDT according to the specified parameters in the
  *         WDT_InitTypeDef and start watchdog. Before exiting function,
  *         watchdog is refreshed in order to have correct time base.
  * @param  hwdt  pointer to a WDT_HandleTypeDef structure that contains
  *                the configuration information for the specified WDT module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_WDT_Init(WDT_HandleTypeDef *hwdt)
{
  uint32_t tickstart;

  /* Check the WDT handle allocation */
  if (hwdt == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  //assert_param(IS_WDT_ALL_INSTANCE(hwdt->Instance));
  assert_param(IS_WDT_RPL(hwdt->Init.Rpl));
  //assert_param(IS_WDT_RELOAD(hwdt->Init.Reload));
  //assert_param(IS_WDT_WINDOW(hwdt->Init.Window));


  /* Enable write access to WDT_PR, WDT_RLR and WDT_WINR registers by writing
  0x5555 in KR */
  //WDT_ENABLE_WRITE_ACCESS(hwdt);

  /* Write to WDT registers the Prescaler & Reload values to work with */
  LL_WDT_SetResetPulseLength(hwdt->Instance, hwdt->Init.Rpl);
  LL_WDT_SetResponseMode(hwdt->Instance, hwdt->Init.Rmod);

#if defined(XT32H0xxB)
  LL_WDT_SetTimeoutRange(hwdt->Instance, hwdt->Init.Range);
  LL_WDT_SetInitTimeoutRange(hwdt->Instance, hwdt->Init.InitRange);
#endif

  /* Enable WDT. LSI is turned on automatically */
  __HAL_WDT_ENABLE(hwdt);

 /* Restart WDT */
//  __HAL_WDT_RESTART(hwdt);
 
  /* Return function status */
  return HAL_OK;
}


/**
  * @}
  */


/** @addtogroup WDT_Exported_Functions_Group2
  *  @brief   IO operation functions
  *
  * @{
  */

/**
  * @brief  Refresh the WDT.
  * @param  hwdt  pointer to a WDT_HandleTypeDef structure that contains
  *                the configuration information for the specified WDT module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_WDT_Refresh(WDT_HandleTypeDef *hwdt)
{
  /* Reload WDT counter with value defined in the reload register */
  __HAL_WDT_RESTART(hwdt);

  /* Return function status */
  return HAL_OK;
}

/**
  * @}
  */


/** @addtogroup WDT_Exported_Functions_Group3
  *
  * @{
  */

/**
  * @brief Handle WDT interrupt request.
  * @param hwdt Pointer to a WDT_HandleTypeDef structure that contains
  *             the configuration information for the WDT.
  */
void HAL_WDT_IRQHandler(WDT_HandleTypeDef *hwdt)
{
  hwdt->TimeoutCallback(hwdt);
}

/**
  * @brief Register callbacks
  * @param hwdt Pointer to a WDT_HandleTypeDef structure that contains
  *             the configuration information for the WDT.
  * @param pCallback call back function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_WDT_RegisterCallback(WDT_HandleTypeDef *hwdt, void (* pCallback)(WDT_HandleTypeDef *_hwdt))
{
  hwdt->TimeoutCallback = pCallback;

  return HAL_OK;
}

/**
  * @brief UnRegister callbacks
  * @param hwdt Pointer to a WDT_HandleTypeDef structure that contains
  *             the configuration information for the WDT.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_WDT_UnRegisterCallback(WDT_HandleTypeDef *hwdt)
{
  hwdt->TimeoutCallback = NULL;

  return HAL_OK;
}


/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_WDT_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
