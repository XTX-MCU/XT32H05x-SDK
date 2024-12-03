/**
  ******************************************************************************
  * @file    xt32h0xx_ll_timr.c
  * @author  Software Team
  * @brief   TIM LL module driver.
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
#include "xt32h0xx_ll_timr.h"
#include "xt32h0xx_ll_bus.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (TIMB11) || defined (TIMB12) || defined (TIMB13) || defined (TIMB14) || defined (TIMB21) || defined (TIMB22) || defined (TIMB23) || defined (TIMB24)

/** @addtogroup TIMR_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup TIMR_LL_Private_Macros
  * @{
  */
#define IS_LL_TIMR_MODE(__VALUE__) (((__VALUE__) == LL_TIMR_MODE_FREERUNNING) || \
                                   ((__VALUE__) == LL_TIMR_MODE_USERDEFINED))

/**
  * @}
  */


/* Private function prototypes -----------------------------------------------*/
/** @defgroup TIMR_LL_Private_Functions TIM Private Functions
  * @{
  */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup TIMR_LL_Exported_Functions
  * @{
  */

/** @addtogroup TIMR_LL_EF_Init
  * @{
  */

/**
  * @brief  Set TIMx registers to their reset values.
  * @param  TIMx Timer instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: TIMx registers are de-initialized
  *          - ERROR: invalid TIMx instance
  */
ErrorStatus LL_TIMR_DeInit(TIMR_TypeDef *TIMx)
{
  ErrorStatus result = SUCCESS;

  /* Check the parameters */
  assert_param(IS_TIMR_INSTANCE(TIMx));

  /* Mask interrupt */
  LL_TIMR_MaskIT(TIMx);

  /* Disable counter */
  LL_TIMR_DisableCounter(TIMx);

  return result;
}

/**
  * @brief  Set the fields of the time base unit configuration data structure
  *         to their default values.
  * @param  TIMR_InitStruct pointer to a @ref LL_TIMR_InitTypeDef structure (time base unit configuration data structure)
  */
void LL_TIMR_StructInit(LL_TIMR_InitTypeDef *TIMR_InitStruct)
{
  /* Set the default configuration */
  TIMR_InitStruct->CounterMode       = LL_TIMR_MODE_FREERUNNING;
  TIMR_InitStruct->InitialValue      = 0xFFFF;
  TIMR_InitStruct->ItEnable          = LL_TIMR_IT_MASK;
}

/**
  * @brief  Configure the TIMx time base unit.
  * @param  TIMx Timer Instance
  * @param  TIMR_InitStruct pointer to a @ref LL_TIMR_InitTypeDef structure
  *         (TIMx time base unit configuration data structure)
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: TIMx registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_TIMR_Init(TIMR_TypeDef *TIMx, LL_TIMR_InitTypeDef *TIMR_InitStruct)
{
  uint32_t tmpcr1;

  /* Check the parameters */
  assert_param(IS_TIMR_INSTANCE(TIMx));
  assert_param(IS_LL_TIMR_MODE(TIMR_InitStruct->CounterMode));

  /* Disable Counter */
  LL_TIMR_DisableCounter(TIMx);

  /* Set counter mode */
  LL_TIMR_SetMode(TIMx, TIMR_InitStruct->CounterMode);

  /* Set IT */
  if(TIMR_InitStruct->ItEnable == LL_TIMR_IT_UNMASK)
    LL_TIMR_UnmaskIT(TIMx);
  else
    LL_TIMR_MaskIT(TIMx);

  /* Set count */
  LL_TIMR_SetLoadCount(TIMx, TIMR_InitStruct->InitialValue);

  return SUCCESS;
}

/**
  * @}
  */


/**
  * @}
  */

#endif /* TIM1 || TIM2 || TIM3 || TIM4 */

/**
  * @}
  */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
