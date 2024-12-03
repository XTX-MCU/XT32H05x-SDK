/**
  ******************************************************************************
  * @file    xt32h0xx_ll_dac.c
  * @author  Software Team
  * @brief   MDU LL DAC module driver
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
#include "xt32h0xx_ll_dac.h"
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
/** @addtogroup DAC_LL DAC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup DAC_LL_Private_Macros
  * @{
  */
/* Check of parameters for configuration of DAC hierarchical scope:           */
/* DAC instance.                                                              */
#define IS_LL_DAC_CHANNEL(__CHANNEL__)     \
(((__CHANNEL__) == LL_DAC_1) || \
 ((__CHANNEL__) == LL_DAC_2) \
 )

#define IS_LL_DAC_DACADD(__VALUE__)     \
(((__VALUE__) >= 0) && ((__VALUE__) <= 0xFF))

#define IS_LL_DAC_BYPASS(__MODE__)     \
(((__MODE__) == LL_DAC_1_BUFFER_EN) || \
 ((__MODE__) == LL_DAC_1_BUFFER_BYPASS) || \
 ((__MODE__) == LL_DAC_2_BUFFER_EN) || \
 ((__MODE__) == LL_DAC_2_BUFFER_BYPASS) \
 )

#define IS_LL_DAC_REFERENCE(__REF__)     \
(((__REF__) == LL_DAC_REF_1P2) || \
 ((__REF__) == LL_DAC_REF_2P4) || \
 ((__REF__) == LL_DAC_REF_3P6) || \
 ((__REF__) == LL_DAC_REF_AVDD) \
 )
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/** @addtogroup DAC_LL_Exported_Functions
  * @{
  */

/** @addtogroup DAC_LL_Exported_Functions_Group3
  * @{
  */

/**
  * @brief  De-initialize registers of the selected DAC instance channel
  *         to their default reset values.
  * @param  DACx DAC instance
  * @param  DAC_Channel This parameter can be one of the following values:
  *         @arg @ref LL_DAC_1
  *         @arg @ref LL_DAC_1
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_DAC_ChannelDeInit(MDU_TypeDef *DACx, uint32_t DAC_Channel)
{
  assert_param(IS_DAC_ALL_INSTANCE(DACx));
  return SUCCESS;
}

/**
  * @brief  Initialize some features of DAC channel.
  * @param  DACx DAC instance
  * @param  DAC_Channel This parameter can be one of the following values:
  *         @arg @ref LL_DAC_1
  *         @arg @ref LL_DAC_1
  * @param  DAC_ChannelInitStruct Pointer to a @ref LL_DAC_ChannelInitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are initialized
  *          - ERROR: DAC registers are not initialized
  */
ErrorStatus LL_DAC_ChannelInit(MDU_TypeDef *DACx, uint32_t DAC_Channel, LL_DAC_ChannelInitTypeDef *DAC_ChannelInitStruct)
{
  ErrorStatus status = SUCCESS;

  assert_param(IS_DAC_ALL_INSTANCE(DACx));
  assert_param(IS_LL_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_LL_DAC_BYPASS(DAC_ChannelInitStruct->ByPass));

//  LL_MDU_DAC_SetDacAdd(DAC_Channel, DAC_ChannelInitStruct->DacAdd);

  if(DAC_ChannelInitStruct->BufferByPass == LL_DAC_BUFFER_EN)
  {
    LL_MDU_DAC_ByPassEnable(DAC_Channel);
  }
  else
  {
    LL_MDU_DAC_ByPassDisable(DAC_Channel);
  }

  return status;
}

/**
  * @brief Set each @ref LL_DAC_ChannelInitTypeDef field to default value.
  * @param DAC_ChannelInitStruct pointer to a @ref LL_DAC_ChannelInitTypeDef structure
  *                       whose fields will be set to default values.
  */
void LL_DAC_ChannelStructInit(LL_DAC_ChannelInitTypeDef *DAC_ChannelInitStruct)
{
  DAC_ChannelInitStruct->BufferByPass = LL_DAC_BUFFER_EN;
}

/**
  * @brief  De-initialize registers of the selected DAC instance
  *         to their default reset values.
  * @param  DACx DAC instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_DAC_DeInit(MDU_TypeDef *DACx)
{
  /* Check the parameters */
  assert_param(IS_DAC_ALL_INSTANCE(DACx));

  /* DAC power down */
  LL_MDU_DAC_PowerDown();

  return SUCCESS;
}

/**
  * @brief  Initialize some features of DAC.
  * @param  DACx DAC instance
  * @param  DAC_InitStruct Pointer to a @ref LL_DAC_InitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are initialized
  *          - ERROR: DAC registers are not initialized
  */
ErrorStatus LL_DAC_Init(DAC_TypeDef *DACx, LL_DAC_InitTypeDef *DAC_InitStruct)
{
  ErrorStatus status = SUCCESS;

  assert_param(IS_DAC_ALL_INSTANCE(DACx));
  assert_param(IS_LL_DAC_REFERENCE(DAC_InitStruct->Reference));

  LL_MDU_DAC_PowerOn();
  LL_MDU_DAC_SetRef(DAC_InitStruct->Reference);

  LL_MDU_DAC_SetRefTune(DAC_InitStruct->ReferVoltageTune);

  return status;
}

/**
  * @brief Set each @ref LL_DAC_InitTypeDef field to default value.
  * @param DAC_InitStruct pointer to a @ref LL_DAC_InitTypeDef structure
  *                       whose fields will be set to default values.
  */
void LL_DAC_StructInit(LL_DAC_InitTypeDef *DAC_InitStruct)
{
  /* Set DAC_InitStruct fields to default values */
  DAC_InitStruct->Reference        = LL_DAC_REF_1P2;
  DAC_InitStruct->ReferVoltageTune    = LL_DAC_REFVOL_P60;
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
