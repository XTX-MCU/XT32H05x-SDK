/**
  ******************************************************************************
  * @file    xt32h0xx_ll_led.c
  * @author  Software Team
  * @brief   LED LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_led.h"
#include "xt32h0xx_ll_bus.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (LED)

/** @addtogroup LED_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup LED_LL_Exported_Functions
  * @{
  */

/** @addtogroup LED_LL_Exported_Functions_Group2
  * @{
  */

/**
  * @brief  De-initialize LED registers (Registers restored to their default values).
  * @param  LEDx LED Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: LED registers are de-initialized
  *          - ERROR: LED registers are not de-initialized
  */
ErrorStatus LL_LED_DeInit(LED_TypeDef *LEDx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_LED_ALL_INSTANCE(LEDx));

  if (LEDx == LED)
  {
    /* Force LED reset */
//    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_LED);

    /* Release LED reset */
//    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_LED);
  }
  else
  {
    status = ERROR;
  }

  return (status);
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

#endif /* defined (LED) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

