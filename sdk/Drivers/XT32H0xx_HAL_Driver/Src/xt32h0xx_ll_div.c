/**
  ******************************************************************************
  * @file    xt32h0xx_ll_div.c
  * @author  Software Team
  * @brief   DIV LL module driver.
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
#include "xt32h0xx_ll_div.h"
#include "xt32h0xx_ll_bus.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (HDIV)

/** @addtogroup DIV_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup DIV_LL_Exported_Functions
  * @{
  */

/** @addtogroup DIV_LL_Exported_Functions_Group3
  * @{
  */

/**
  * @brief  De-initialize DIV registers (Registers restored to their default values).
  * @param  DIVx DIV Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DIV registers are de-initialized
  *          - ERROR: DIV registers are not de-initialized
  */
ErrorStatus LL_DIV_DeInit(DIV_TypeDef *DIVx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_DIV_ALL_INSTANCE(DIVx));

  if (DIVx == HDIV)
  {
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

#endif /* defined (HDIV) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

