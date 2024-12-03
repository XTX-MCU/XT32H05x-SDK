/**
  ******************************************************************************
  * @file    xt32h0xx_pga.c
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the PGA peripheral:
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
#include "xt32h0xx_pga.h"
#include "xt32h0xx_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup PGA PGA
  * @brief PGA driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/** @defgroup PGA_Exported_Functions PGA Exported Functions
  * @{
  */

/** @defgroup PGA_Exported_Functions_Group1 Initialization and Configuration functions
  *  @brief   Initialization and Configuration functions 
  *
  * @{
  */

/**
  * @brief  Deinitializes PGA peripheral registers to their default reset values.
  */
void PGA_DeInit(void)
{
  MDU->PDCTRL &= ~((uint32_t)(MDU_PDCTRL_PGAEN1 |
                              MDU_PDCTRL_PGAEN2 |
                              MDU_PDCTRL_PGAEN3 |
                              MDU_PDCTRL_PGAEN4));
}

/**
  * @brief  Initializes the PGA peripheral according to the specified parameters
  *         in the PGA_InitStruct.
  * @param  PGA_InitStruct: pointer to an PGA_InitTypeDef structure that contains 
  *         the configuration information for the specified ADC peripheral.
  */
void PGA_Init(PGA_InitTypeDef* PGA_InitStruct)
{
  uint32_t tempr = 0;

  int i=0;

  /* Check the parameters */
  for(i=0; i<PGA_CHANNEL_NUMBER; i++)
  {
    assert_param(IS_PAG_GAIN(PGA_InitStruct->Channel[i].Gain));
  }

  tempr = MDU->PGA_CFG;

  for(i=0; i<PGA_CHANNEL_NUMBER; i++)
  {
    tempr &= (uint32_t)~((uint32_t)(MDU_PGACFG_PGA1GAIN << (i*4)));

    tempr  |= ((uint32_t)(PGA_InitStruct->Channel[i].Gain << (i*4)));
  }

  MDU->PGA_CFG = tempr;
}

/**
  * @brief  Fills each PGA_InitStruct member with its default value.
  * @param  PGA_InitStruct: pointer to an PGA_InitTypeDef structure which will 
  *         be initialized.
  */
void PGA_StructInit(PGA_InitTypeDef* PGA_InitStruct)
{
  int i=0;
  /* Reset PGA init structure parameters values */
  for(i=0; i<PGA_CHANNEL_NUMBER; i++)
  {
    PGA_InitStruct->Channel[i].Gain = PGA_GAIN_6;
  }
}

/**
  * @}
  */

/** @addtogroup PGA_Exported_Functions_Group2 Operation Functions
  * @brief    Operation functions
  * @{
  */
/**
  * @brief  PGA channel enable
  * @param  Channel PGA channel
  *         This parameter can be one of the following values:
  *         @arg @ref PGA_0
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  */
void PGA_ChannelEnable(uint32_t Channel)
{
  assert_param(IS_PGA_CHANNEL(Channel));

  MDU->PDCTRL |= (uint32_t)(MDU_PDCTRL_PGAEN1 << (MDU_PDCTRL_PGAEN1_Pos + Channel));
}

/**
  * @brief  PGA channel disable
  * @param  Channel PGA channel
  *         This parameter can be one of the following values:
  *         @arg @ref PGA_0
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  */
void PGA_ChannelDisable(uint32_t Channel)
{
  assert_param(IS_PGA_CHANNEL(Channel));

  MDU->PDCTRL &= (uint32_t)~((uint32_t)MDU_PDCTRL_PGAEN1 << (MDU_PDCTRL_PGAEN1_Pos + Channel));
}

/**
  * @brief  PGA channel disable
  * @param  Channel PGA channel
  *         This parameter can be one of the following values:
  *         @arg @ref PGA_0
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  * @param  Gain PGA channel gain
  *         This parameter can be one of the following values:
  *         @arg @ref PGA_GAIN_2
  *         @arg @ref PGA_GAIN_3
  *         @arg @ref PGA_GAIN_4
  *         @arg @ref PGA_GAIN_4P8
  *         @arg @ref PGA_GAIN_6
  *         @arg @ref PGA_GAIN_8
  *         @arg @ref PGA_GAIN_9P6
  *         @arg @ref PGA_GAIN_12
  */
void PGA_SetChannelGain(uint32_t Channel, uint32_t Gain)
{
  uint32_t tempr = 0;

  assert_param(IS_PGA_CHANNEL(Channel));
  assert_param(IS_PAG_GAIN(Gain));

  tempr = MDU->PGA_CFG;

  tempr &= ~((uint32_t)MDU_PGACFG_PGA1GAIN << (Channel*4));
  tempr |= ((uint32_t)Gain << (Channel*4));

  MDU->PGA_CFG = tempr;
}

/**
  * @brief  PGA channel disable
  * @param  Channel PGA channel
  *         This parameter can be one of the following values:
  *         @arg @ref PGA_0
  *         @arg @ref PGA_1
  *         @arg @ref PGA_2
  *         @arg @ref PGA_3
  * @retval  Gain PGA channel gain
  *         This value can be one of the following values:
  *         @arg @ref PGA_GAIN_2
  *         @arg @ref PGA_GAIN_3
  *         @arg @ref PGA_GAIN_4
  *         @arg @ref PGA_GAIN_4P8
  *         @arg @ref PGA_GAIN_6
  *         @arg @ref PGA_GAIN_8
  *         @arg @ref PGA_GAIN_9P6
  *         @arg @ref PGA_GAIN_12
  */
uint32_t PGA_GetChannelGain(uint32_t Channel)
{
  uint32_t tempr = 0;

  assert_param(IS_PGA_CHANNEL(Channel));

  tempr = MDU->PGA_CFG;

  tempr &= ((uint32_t)MDU_PGACFG_PGA1GAIN << (Channel*4));

  return tempr;
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

