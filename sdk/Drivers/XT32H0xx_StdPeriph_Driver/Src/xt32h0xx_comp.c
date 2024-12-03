/**
  ******************************************************************************
  * @file    xt32h0xx_comp.c
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Comparator (COMP) peripheral:
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_comp.h"
#include "xt32h0xx_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup COMP COMP
  * @brief COMP driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/** @defgroup COMP_Exported_Functions COMP Exported Functions
  * @{
  */

/** @defgroup COMP_Exported_Functions_Group1 Initialization and Configuration functions
  *  @brief   Initialization and Configuration functions 
  *
  * @{
  */

/**
  * @brief  Deinitializes COMP peripheral registers to their default reset values.
  */
void COMP_DeInit(void)
{
  MDU->PDCTRL |= ( MDU_PDCTRL_CMP1PD |
                       MDU_PDCTRL_CMP2PD |
                       MDU_PDCTRL_CMP3PD |
                       MDU_PDCTRL_CMP4PD );
}

/**
  * @brief  Initializes the COMP peripheral according to the specified parameters
  *         in the COMP_InitStruct.
  * @param  COMP_InitStruct: pointer to an COMP_InitTypeDef structure that contains 
  *         the configuration information for the specified COMP peripheral.
  */
void COMP_Init(COMP_InitTypeDef* COMP_InitStruct)
{
  uint32_t tmpreg0,tmpreg1,tmpreg2;
  int i=0;
  /* Check the parameters */
  assert_param(IS_COMP_OUTPUT_FILTER_MODE(COMP_InitStruct->OutputFilter));
  for(i=0; i<COMP_CHANNEL_NUMBER; i++)
  {
    assert_param(IS_COMP_NEGATIVE_SOURCE(COMP_InitStruct->Channel[i].NegativeSource));
    assert_param(IS_COMP_POSITIVE_SOURCE(COMP_InitStruct->Channel[i].PositiveSource));
    assert_param(IS_COMP_SPEED(COMP_InitStruct->Channel[i].Spd));
    assert_param(IS_COMP_HYSTERESIS(COMP_InitStruct->Channel[i].Hysteresis));
    assert_param(IS_COMP_OUTPUT_POLARITY(COMP_InitStruct->Channel[i].OutputPolarity));
  }

  /* config comp */
  tmpreg0 = 0;
  tmpreg1 = 0;
  tmpreg2 = 0;
  for(i=0; i<COMP_CHANNEL_NUMBER; i++)
  {
    tmpreg0 |= ((COMP_InitStruct->Channel[i].PositiveSource << (MDU_CMPCFG1_PSRC_1_Pos + i*8)) |
                (COMP_InitStruct->Channel[i].NegativeSource << (MDU_CMPCFG1_NSRC_1_Pos + i*8)));

    tmpreg1 |= ((COMP_InitStruct->Channel[i].Hysteresis << (MDU_CMPCFG2_HYS_1_Pos + i*8)) |
               (COMP_InitStruct->Channel[i].Spd << (MDU_CMPCFG2_SPD_1_Pos + i*8)));

    tmpreg2 |= (COMP_InitStruct->Channel[i].OutputPolarity << i);
  }

  MDU->COMP_CFG0 = tmpreg0;
  MDU->COMP_CFG1 = tmpreg1;
  MDU->COMP_CFG2 = (tmpreg2|COMP_InitStruct->OutputFilter);
}

/**
  * @brief  Fills each COMP_InitStruct member with its default value.
  * @param  COMP_InitStruct: pointer to an COMP_InitTypeDef structure which will 
  *         be initialized.
  */
void COMP_StructInit(COMP_InitTypeDef* COMP_InitStruct)
{
  int i=0;
  /* Reset COMP init structure parameters values */
  COMP_InitStruct->OutputFilter = COMP_OUTPUT_FILTER_ENABLE;
  for(i=0; i<COMP_CHANNEL_NUMBER; i++)
  {
    COMP_InitStruct->Channel[i].NegativeSource  = COMP_NEGATIVE_SOURCE_EXTERNAL;
    COMP_InitStruct->Channel[i].PositiveSource  = COMP_POSITIVE_SOURCE_EXTERNAL;
    COMP_InitStruct->Channel[i].Spd             = COMP_SPEED_0;
    COMP_InitStruct->Channel[i].Hysteresis      = COMP_HYSTERESIS_NONE;
    COMP_InitStruct->Channel[i].OutputPolarity  = COMP_OUTPUT_POLARITY_NORMAL;
  }
}

/**
  * @}
  */ 

/** @addtogroup COMP_Exported_Functions_Group2 Operation Functions
  * @brief    Operation functions
  * @{
  */
/**
  * @brief  Start COMP
  * @param  Channel COMP channel
  *         This parameter can be one of the following values:
  *         @arg @ref COMP_0
  *         @arg @ref COMP_1
  *         @arg @ref COMP_2
  *         @arg @ref COMP_3
  */
void COMP_Start(uint32_t Channel)
{
  assert_param(IS_COMP_CHANNEL(Channel));

  MDU->PDCTRL &= (~((uint32_t)(MDU_PDCTRL_CMP1PD << (MDU_PDCTRL_CMP1PD_Pos + Channel*4))));
}

/**
  * @brief  Stop COMP
  * @param  Channel COMP channel
  *         This parameter can be one of the following values:
  *         @arg @ref COMP_0
  *         @arg @ref COMP_1
  *         @arg @ref COMP_2
  *         @arg @ref COMP_3
  */
void COMP_Stop(uint32_t Channel)
{
  assert_param(IS_COMP_CHANNEL(Channel));
  
  MDU->PDCTRL |= ((uint32_t)(MDU_PDCTRL_CMP1PD << (MDU_PDCTRL_CMP1PD_Pos + Channel*4)));
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

/**
  * @}
  */ 

