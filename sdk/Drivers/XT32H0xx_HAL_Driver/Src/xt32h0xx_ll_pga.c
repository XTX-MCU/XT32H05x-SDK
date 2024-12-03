/**
  ******************************************************************************
  * @file    xt32h0xx_ll_pga.c
  * @author  Software Team
  * @brief   MDU LL module driver
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
#include "xt32h0xx_ll_pga.h"
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
/** @addtogroup PGA_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup PGA_LL_Private_Macros
  * @{
  */
/* Check of parameters for configuration of PGA hierarchical scope:           */
/* PGA instance.                                                              */
#define IS_LL_PGA_CHANNEL(__CHANNEL__)     \
(((__CHANNEL__) == LL_PGA_1) || \
 ((__CHANNEL__) == LL_PGA_2) || \
 ((__CHANNEL__) == LL_PGA_3) || \
 ((__CHANNEL__) == LL_PGA_4) \
 )

#define IS_LL_PGA_GAIN(__VALUE__)     \
(((__VALUE__) >= 0) && ((__VALUE__) <= 0x7))

/**
  * @}
  */
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup PGA_LL_Exported_Functions
  * @{
  */

/** @addtogroup PGA_LL_Exported_Functions_Group3
  * @{
  */

/**
  * @brief  De-initialize registers of the selected PGA channel 
  *         to their default reset values.
  * @param  PGAx PGA instance
  * @param  PGA_Channel This parameter can be one of the following values:
  *         @arg @ref LL_PGA_1
  *         @arg @ref LL_PGA_2
  *         @arg @ref LL_PGA_3
  *         @arg @ref LL_PGA_4
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_PGA_ChannelDeInit(MDU_TypeDef *PGAx, uint32_t PGA_Channel)
{
  /* Check the parameters */
  assert_param(IS_PGA_ALL_INSTANCE(PGAx));
  assert_param(IS_LL_PGA_CHANNEL(PGA_Channel));

  /* PGA channel power down */
  CLEAR_BIT(MDU->PDCTRL, (MDU_PDCTRL_PGAEN1<<PGA_Channel));

  return SUCCESS;
}

/**
  * @brief  Initialize some features of PGA channel.
  * @param  PGAx PGA instance
  * @param  PGA_Channel This parameter can be one of the following values:
  *         @arg @ref LL_PGA_1
  *         @arg @ref LL_PGA_2
  *         @arg @ref LL_PGA_3
  *         @arg @ref LL_PGA_4
  * @param  PGA_ChannelInitStruct Pointer to a @ref LL_PGA_ChannelInitTypeDef structure
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are initialized
  *          - ERROR: DAC registers are not initialized
  */
ErrorStatus LL_PGA_ChannelInit(MDU_TypeDef *PGAx, uint32_t PGA_Channel, LL_PGA_ChannelInitTypeDef *PGA_ChannelInitStruct)
{
  ErrorStatus status = SUCCESS;
  assert_param(IS_PGA_ALL_INSTANCE(PGAx));
  assert_param(IS_LL_PGA_CHANNEL(PGA_Channel));
  assert_param(IS_LL_PGA_GAIN(PGA_ChannelInitStruct->Gain));

  LL_MDU_PGA_SetGain(PGA_Channel, PGA_ChannelInitStruct->Gain);

  SET_BIT(MDU->PDCTRL, (MDU_PDCTRL_PGAEN1<<PGA_Channel));

  return status;
}

/**
  * @brief Set each @ref LL_PGA_ChannelInitTypeDef field to default value.
  * @param PGA_ChannelInitStruct pointer to a @ref LL_PGA_ChannelInitTypeDef structure
  *                       whose fields will be set to default values.
  */
void LL_PGA_ChannelStructInit(LL_PGA_ChannelInitTypeDef *PGA_ChannelInitStruct)
{
  /* Set DAC_InitStruct fields to default values */
  PGA_ChannelInitStruct->Gain            = 0;
}

/**
  * @brief  De-initialize registers of the selected PGA instance
  *         to their default reset values.
  * @param  PGAx PGA instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_PGA_DeInit(MDU_TypeDef *PGAx)
{
  /* Check the parameters */
  assert_param(IS_PGA_ALL_INSTANCE(PGAx));

  return SUCCESS;
}

/**
  * @brief  Initialize some features of PGA instance.
  * @param  PGAx DAC instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DAC registers are initialized
  *          - ERROR: DAC registers are not initialized
  */
ErrorStatus LL_PGA_Init(MDU_TypeDef *PGAx)
{
  ErrorStatus status = SUCCESS;
  assert_param(IS_PGA_ALL_INSTANCE(PGAx));

  return status;
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
