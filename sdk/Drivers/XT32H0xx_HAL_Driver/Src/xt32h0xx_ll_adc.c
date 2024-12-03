/**
  ******************************************************************************
  * @file    xt32h0xx_ll_adc.c
  * @author  Software Team
  * @brief   MDU LL ADC module driver
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
#include "xt32h0xx_ll_adc.h"
#include "xt32h0xx_ll_bus.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (MDU)
/** @addtogroup ADC_LL 
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/** @addtogroup ADC_LL_Private_Macros ADC Private Macros
  * @{
  */
/* Check of parameters for configuration of ADC hierarchical scope:           */
/* ADC instance.                                                              */
#define IS_LL_ADC_DELAY(__DELAY__)     (((__DELAY__) >= 0) && ((__DELAY__) <= 0xF))
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADC_LL_Exported_Functions
  * @{
  */

/** @addtogroup ADC_LL_EF_Init
  * @{
  */
/**
  * @brief  De-initialize registers of the selected ADC instance
  *         to their default reset values.
  * @param  MDUx MDU instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are de-initialized
  *          - ERROR: ADC registers are not de-initialized
  */
ErrorStatus LL_ADC_DeInit(MDU_TypeDef *MDUx)
{
  ErrorStatus status = SUCCESS;

  __IO uint32_t timeout_cpu_cycles = 0UL;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(MDUx));
  
  LL_MDU_ADC_PowerDown();

  return status;
}

/**
  * @brief  Initialize some features of ADC instance.
  * @param  MDUx ADC instance
  * @param  pADC_InitStruct Pointer to a LL_ADC_REG_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: ADC registers are initialized
  *          - ERROR: ADC registers are not initialized
  */
ErrorStatus LL_ADC_Init(MDU_TypeDef *MDUx, LL_ADC_InitTypeDef *pADC_InitStruct)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(MDUx));
  assert_param(IS_LL_ADC_DELAY(pADC_InitStruct->Delay));

  LL_MDU_ADC_PowerOn();
#if defined(XT32H0xxB)
#else	
  LL_MDU_ADC_SetDelay(pADC_InitStruct->Delay);
#endif
  return status;
}

/**
  * @brief  Set each LL_ADC_InitTypeDef field to default value.
  * @param  pADC_InitStruct Pointer to a LL_ADC_InitTypeDef structure
  *                        whose fields will be set to default values.
  */
void LL_ADC_StructInit(LL_ADC_InitTypeDef *pADC_InitStruct)
{
  /* Set pADC_InitStruct fields to default values */
  /* Set fields of ADC instance */
#if defined(XT32H0xxB)
#else	
  pADC_InitStruct->Delay         = 1;
#endif	
}
/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/


/**
  * @}
  */

#endif /* MDU */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
