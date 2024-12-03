/**
  ******************************************************************************
  * @file    xt32h0xx_ll_comp.c
  * @author  Software Team
  * @brief   MDU LL COMP module driver
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
#include "xt32h0xx_ll_comp.h"
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

/** @addtogroup COMP_LL COMP
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup COMP_LL_Private_Macros
  * @{
  */
/* Check of parameters for configuration of COMP hierarchical scope:           */
/* COMP instance.                                                              */
#define IS_LL_COMP_CHANNEL(__CHANNEL__)     \
(((__CHANNEL__) == LL_COMP_1) || \
 ((__CHANNEL__) == LL_COMP_2) || \
 ((__CHANNEL__) == LL_COMP_3) || \
 ((__CHANNEL__) == LL_COMP_4) \
 )

#define IS_LL_COMP_NEGATIVESOURCE(__SOURCE__)     \
(((__SOURCE__) == LL_COMP_NEGATIVE_SOURCE_0) || \
 ((__SOURCE__) == LL_COMP_NEGATIVE_SOURCE_1) || \
 ((__SOURCE__) == LL_COMP_NEGATIVE_SOURCE_2) || \
 ((__SOURCE__) == LL_COMP_NEGATIVE_SOURCE_3) \
 )

#define IS_LL_COMP_POSITIVESOURCE(__SOURCE__)     \
(((__SOURCE__) == LL_COMP_POSITIVE_SOURCE_0) || \
 ((__SOURCE__) == LL_COMP_POSITIVE_SOURCE_1) \
 )

#define IS_LL_COMP_HYSTERESIS(__VALUE__)     \
(((__VALUE__) >= 0) && \
 ((__VALUE__) <= 3) \
 )

#define IS_LL_COMP_SPD(__VALUE__)     \
(((__VALUE__) >= 0) && \
 ((__VALUE__) <= 7) \
 )

#define IS_LL_COMP_OUTPUTPOLARITY(__POL__)     \
(((__POL__) == LL_COMP_OUTPUT_POL_NORMAL) || \
 ((__POL__) == LL_COMP_OUTPUT_POL_INVERT) \
 )
/**
  * @}
  */
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup COMP_LL_Exported_Functions
  * @{
  */

/** @addtogroup COMP_LL_Exported_Functions_Group3
  * @{
  */

/**
  * @brief  De-initialize registers of the selected COMP channel
  *         to their default reset values.
  * @param  COMPx COMP instance
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: COMP registers are de-initialized
  *          - ERROR: COMP registers are not de-initialized
  */
ErrorStatus LL_COMP_ChannelDeInit(MDU_TypeDef *COMPx, uint32_t COMP_Channel)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_COMP_ALL_INSTANCE(COMPx));

  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP1PD << (COMP_Channel*4));

  return status;
}

/**
  * @brief  Initialize some features of COMP channel.
  * @param  COMPx COMP instance
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @param  COMP_ChannelInitStruct Pointer to a LL_COMP_ChannelInitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: COMP registers are initialized
  *          - ERROR: COMP registers are not initialized
  */
ErrorStatus LL_COMP_ChannelInit(MDU_TypeDef *COMPx, uint32_t COMP_Channel, LL_COMP_ChannelInitTypeDef *COMP_ChannelInitStruct)
{
  ErrorStatus status = SUCCESS;
  assert_param(IS_COMP_ALL_INSTANCE(COMPx));
  assert_param(IS_LL_COMP_CHANNEL(COMP_Channel));
  assert_param(IS_LL_COMP_NEGATIVESOURCE(COMPx, COMP_ChannelInitStruct->NegativeSource));
  assert_param(IS_LL_COMP_POSITIVESOURCE(COMPx, COMP_ChannelInitStruct->PositiveSource));
  assert_param(IS_LL_COMP_HYSTERESIS(COMPx, COMP_ChannelInitStruct->Hysteresis));
  assert_param(IS_LL_COMP_SPD(COMPx, COMP_ChannelInitStruct->Spd));
  assert_param(IS_LL_COMP_OUTPUTPOLARITY(COMPx, COMP_ChannelInitStruct->Polarity));

  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP1PD << (COMP_Channel*4));
  
  LL_MDU_COMP_SetNegativeSource(COMP_Channel, COMP_ChannelInitStruct->NegativeSource);
  LL_MDU_COMP_SetPositiveSource(COMP_Channel, COMP_ChannelInitStruct->PositiveSource);
  LL_MDU_COMP_SetHysteresis(COMP_Channel, COMP_ChannelInitStruct->Hysteresis);
  LL_MDU_COMP_SetSpd(COMP_Channel, COMP_ChannelInitStruct->Spd);
  LL_MDU_COMP_SetOutputPolarity(COMP_Channel, COMP_ChannelInitStruct->Polarity);

  return status;
}

/**
  * @brief Set each LL_COMP_ChannelInitTypeDef field to default value.
  * @param COMP_ChannelInitStruct Pointer to a LL_COMP_ChannelInitTypeDef structure
  *                        whose fields will be set to default values.
  */
void LL_COMP_ChannelStructInit(LL_COMP_ChannelInitTypeDef *COMP_ChannelInitStruct)
{
  /* Set COMP_InitStruct fields to default values */
  COMP_ChannelInitStruct->PositiveSource      = 0;
  COMP_ChannelInitStruct->NegativeSource      = 0;
  COMP_ChannelInitStruct->Hysteresis          = 0;
  COMP_ChannelInitStruct->Spd                 = 0;
  COMP_ChannelInitStruct->Polarity            = 0;
}

/**
  * @brief  De-initialize registers of the selected COMP instance
  *         to their default reset values.
  * @param  COMPx COMP instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: COMP registers are de-initialized
  *          - ERROR: COMP registers are not de-initialized
  */
ErrorStatus LL_COMP_DeInit(MDU_TypeDef *COMPx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_COMP_ALL_INSTANCE(COMPx));

  return status;
}

/**
  * @brief  Initialize some features of COMP instance.
  * @param  COMPx COMP instance
  * @param  COMP_InitStruct Pointer to a @ref LL_COMP_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: COMP registers are initialized
  *          - ERROR: COMP registers are not initialized
  */
ErrorStatus LL_COMP_Init(MDU_TypeDef *COMPx, LL_COMP_InitTypeDef *COMP_InitStruct)
{
  ErrorStatus status = SUCCESS;
  assert_param(IS_COMP_ALL_INSTANCE(COMPx));

  LL_MDU_COMP_SetOutputFilter(COMP_InitStruct->Filter);

  return status;
}

/**
  * @brief Set each @ref LL_COMP_InitTypeDef field to default value.
  * @param COMP_InitStruct Pointer to a @ref LL_COMP_InitTypeDef structure
  *                        whose fields will be set to default values.
  */
void LL_COMP_StructInit(LL_COMP_InitTypeDef *COMP_InitStruct)
{
  /* Set COMP_InitStruct fields to default values */
  COMP_InitStruct->Filter              = 0;
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
