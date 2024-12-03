/**
  ******************************************************************************
  * @file    xt32h0xx_ll_tsu.c
  * @author  Software Team
  * @brief   TSU LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_crc.h"
#include "xt32h0xx_ll_bus.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (TSU)

/** @addtogroup TSU_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup TSU_LL_Exported_Functions
  * @{
  */

/** @addtogroup TSU_LL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize TSU registers (Registers restored to their default values).
  * @param  TSUx TSU Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: TSU registers are de-initialized
  *          - ERROR: TSU registers are not de-initialized
  */
ErrorStatus LL_TSU_DeInit(TSU_TypeDef *TSUx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_TSU_ALL_INSTANCE(TSUx));

  if (TSUx == TSU)
  {
//    /* Force TSU reset */
//    LL_AHB1_GRP1_ForceReset(LL_AHB1_GRP1_PERIPH_TSU);
//
//    /* Release TSU reset */
//    LL_AHB1_GRP1_ReleaseReset(LL_AHB1_GRP1_PERIPH_TSU);
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

#endif /* defined (TSU) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

