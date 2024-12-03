/**
  ******************************************************************************
  * @file    xt32h0xx_dac.c
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Digital to Analog Convertor (DAC) peripheral:
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
#include "xt32h0xx_dac.h"
#include "xt32h0xx_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup DAC DAC
  * @brief DAC driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

/** @defgroup DAC_Exported_Functions DAC Exported Functions
  * @{
  */

/** @defgroup DAC_Exported_Functions_Group1 Initialization and Configuration functions
  *  @brief   Initialization and Configuration functions 
  *
  * @{
  */

/**
  * @brief  Deinitializes DAC peripheral registers to their default reset values.
  */
void DAC_DeInit(void)
{
  MDU->PDCTRL |= MDU_PDCTRL_DACPD;
}

/**
  * @brief  Initializes the DAC peripheral according to the specified parameters
  *         in the ADC_InitStruct.
  * @param  DAC_InitStruct: pointer to an DAC_InitTypeDef structure that contains 
  *         the configuration information for the specified ADC peripheral.
  */
void DAC_Init(DAC_InitTypeDef* DAC_InitStruct)
{
  uint32_t tempr = 0;

  /* Check the parameters */
  assert_param(IS_DAC_REFERENCE(DAC_InitStruct->Refer));
  assert_param(IS_DAC_REFTUNE(DAC_InitStruct->ReferVoltageTune));
  assert_param(IS_DAC_BUFFERMODE(DAC_InitStruct->Channel[0].BufferMode));
  assert_param(IS_DAC_BUFFERMODE(DAC_InitStruct->Channel[1].BufferMode));

  /* Config DAC */
  MDU->DAC_CFG =  DAC_InitStruct->Refer | 
                 (DAC_InitStruct->Channel[0].BufferMode << MDU_DACCFG_DAC1BBP_Pos) | 
                 (DAC_InitStruct->Channel[1].BufferMode << MDU_DACCFG_DAC2BBP_Pos);

  tempr = AON->IVREF_CFG_3;
  tempr &= ~((uint32_t)AON_IVREF_CFG_3_DAC_REF);
  tempr |= DAC_InitStruct->ReferVoltageTune;
  AON->IVREF_CFG_3 = tempr;

}

/**
  * @brief  Fills each DAC_InitStruct member with its default value.
  * @param  DAC_InitStruct: pointer to an DAC_InitTypeDef structure which will 
  *         be initialized.
  */
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct)
{
  /* Reset DAC init structure parameters values */
  DAC_InitStruct->Refer = DAC_REFERENCE_1P2;
  DAC_InitStruct->ReferVoltageTune = DAC_REFVOL_P60;

  DAC_InitStruct->Channel[0].BufferMode = DAC_BUFFER_MODE_NORMAL;
  DAC_InitStruct->Channel[1].BufferMode = DAC_BUFFER_MODE_NORMAL;
}

/**
  * @}
  */ 

/** @addtogroup DAC_Exported_Functions_Group2 Operation Functions
  * @brief    Operation functions
  * @{
  */

/**
  * @brief  Start DAC
  */
void DAC_Start(void)
{
  MDU->PDCTRL &= ~((uint32_t)MDU_PDCTRL_DACPD);
}

/**
  * @brief  Stop DAC
  */
void DAC_Stop(void)
{
  MDU->PDCTRL |= ((uint32_t)MDU_PDCTRL_DACPD);
}

/**
  * @brief  DAC set input data
  * @param  Channel DAC Channel
  *         This parameter can be one of the following values:
  *         @arg @ref DAC_1
  *         @arg @ref DAC_2
  * @param  Data Input data
  *         This parameter can be one between 0 and 0xFF.
  */
void DAC_SetValue(uint32_t Channel, uint8_t Data)
{
  uint32_t tempr=0;
  assert_param(IS_DAC_CHANNEL(Channel));
  assert_param(IS_DAC_INPUT_DATA(Data));

  tempr = MDU->DAC_CFG;
  tempr &= ~(((uint32_t) MDU_DACCFG_DAC1ADD) << (Channel*8));
  tempr |= (((uint32_t) Data) << (Channel*8));

  MDU->DAC_CFG = tempr;
}

/**
  * @brief  DAC get input data
  * @param  Channel DAC Channel
  *         This parameter can be one of the following values:
  *         @arg @ref DAC_1
  *         @arg @ref DAC_2
  * @retval  Data Input data
  *         This value can be one between 0 and 0xFF.
  */
uint8_t DAC_GetValue(uint32_t Channel)
{
  uint32_t ret = MDU->DAC_CFG;

  assert_param(IS_DAC_CHANNEL(Channel));

  ret &= (((uint32_t) MDU_DACCFG_DAC1ADD) << (Channel*8));
  ret >>= (Channel*8);

  return (uint8_t) ret;
}

/**
  * @brief  DAC set channle buffer mode
  * @param  Channel DAC Channel
  *         This parameter can be one of the following values:
  *         @arg @ref DAC_1
  *         @arg @ref DAC_2
  * @param  Mode Channel buffer mode
  *         This parameter can be one of the following values:
  *         @arg @ref DAC_BUFFER_MODE_NORMAL
  *         @arg @ref DAC_BUFFER_MODE_BYPASS
  */
void DAC_SetChannelBufferMode(uint32_t Channel, uint32_t Mode)
{
  uint32_t tempr=0;
  assert_param(IS_DAC_CHANNEL(Channel));
  assert_param(IS_DAC_BUFFERMODE(Mode));

  tempr = MDU->DAC_CFG;
  tempr &= ~(((uint32_t) MDU_DACCFG_DAC1BBP) << (MDU_DACCFG_DAC1BBP_Pos + Channel*4));
  tempr |= (((uint32_t) Mode) << (MDU_DACCFG_DAC1BBP_Pos + Channel*4));

  MDU->DAC_CFG = tempr;
}

/**
  * @brief  DAC set reference voltage
  * @param  RefVol reference voltage
  *         This parameter can be one of the following values:
  *         @arg @ref DAC_REFERENCE_1P2
  *         @arg @ref DAC_REFERENCE_2P4
  *         @arg @ref DAC_REFERENCE_3P6
  *         @arg @ref DAC_REFERENCE_AVDD
  */
void DAC_SetReference(uint32_t RefVol)
{
  uint32_t tempr=0;
  assert_param(IS_DAC_REFERENCE(RefVol));

  tempr = MDU->DAC_CFG;
  tempr &= ~(((uint32_t) MDU_DACCFG_REFSEL));
  tempr |= (((uint32_t) RefVol));

  MDU->DAC_CFG = tempr;
}

/**
  * @brief  DAC set reference voltage tune control
  * @param  RefTune reference voltage tune
  *         This parameter can be one of the following values:
  *         @arg @ref DAC_REFVOL_P57
  *         @arg @ref DAC_REFVOL_P58
  *         @arg @ref DAC_REFVOL_P59
  *         @arg @ref DAC_REFVOL_P60
  *         @arg @ref DAC_REFVOL_P61
  *         @arg @ref DAC_REFVOL_P62
  *         @arg @ref DAC_REFVOL_P63
  *         @arg @ref DAC_REFVOL_P64
  */
void DAC_SetTuneReference(uint32_t RefTune)
{
  uint32_t tempr=0;
  assert_param(IS_DAC_REFTUNE(RefTune));

  tempr = AON->IVREF_CFG_3;
  tempr &= ~(((uint32_t) AON_IVREF_CFG_3_DAC_REF));
  tempr |= (((uint32_t) RefTune));

  AON->IVREF_CFG_3 = tempr;
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

