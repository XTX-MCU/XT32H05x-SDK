/**
  ******************************************************************************
  * @file    xt32h0xx_adc.c
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Analog to Digital Convertor (ADC) peripheral:
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
#include "xt32h0xx_adc.h"
#include "xt32h0xx_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup ADC ADC
  * @brief ADC driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup ADC_Exported_Functions ADC Exported Functions
  * @{
  */

/** @defgroup ADC_Exported_Functions_Group1 Initialization and Configuration functions
  *  @brief   Initialization and Configuration functions 
  *
  * @{
  */

/**
  * @brief  Deinitializes ADC peripheral registers to their default reset values.
 */
void ADC_DeInit(void)
{
}

/**
  * @brief  Initializes the ADCx peripheral according to the specified parameters
  *         in the ADC_InitStruct.
  * @param  ADC_InitStruct: pointer to an ADC_InitTypeDef structure that contains 
  *         the configuration information for the specified ADC peripheral.
  */
void ADC_Init(ADC_InitTypeDef* ADC_InitStruct)
{
  uint32_t tempr = 0;

#if defined(XT32H0xxB)
#else
  /* Check the parameters */
  assert_param(IS_ADC_CONVERT(ADC_InitStruct->Convert_Mode));
  assert_param(IS_ADC_TRGSRC(ADC_InitStruct->Trigger_Source));
  assert_param(IS_ADC_TRG_MODE(ADC_InitStruct->Trigger_Mode));
  assert_param(IS_ADC_CONVERT_DIR(ADC_InitStruct->Sequence_Direct));
  assert_param(IS_ADC_GROUP_CHANNEL(ADC_InitStruct->Sequence_Group));

  /* Get the ADCx CFGR value */
  tempr = MDU->ADC_CTRL;

  tempr &= (uint32_t)~((uint32_t)(MDU_ADCCTRL_CONV_MODE | \
                                  MDU_ADCCTRL_TRGISRC | MDU_ADCCTRL_RISEEDGE | MDU_ADCCTRL_FALLEDGE | \
                                  MDU_ADCCTRL_GCHIND | MDU_ADCCTRL_CH_MODE));

  tempr  |= (uint32_t)(ADC_InitStruct->Convert_Mode | \
             ADC_InitStruct->Trigger_Source | ADC_InitStruct->Trigger_Mode | \
             ADC_InitStruct->Sequence_Group | ADC_InitStruct->Sequence_Direct);

  /* Write to ADCx CFGR */
  MDU->ADC_CTRL = tempr;
#endif /* XT32H0xxB */  
}

/**
  * @brief  Fills each ADC_InitStruct member with its default value.
  * @param  ADC_InitStruct: pointer to an ADC_InitTypeDef structure which will 
  *         be initialized.
  */
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct)
{
#if defined(XT32H0xxB)
#else
  /* Reset ADC init structure parameters values */
  ADC_InitStruct->Convert_Mode = ADC_CONVERT_MULTCH_SINGLE;
  ADC_InitStruct->Trigger_Source = ADC_TRGSRC_TIMA_CH4;
  ADC_InitStruct->Trigger_Mode = ADC_TRIGGEREDGE_BOTH;
  ADC_InitStruct->Sequence_Direct = ADC_CONVERT_INCREMENT;
  ADC_InitStruct->Sequence_Group = ADC_GROUP_CH_0 | ADC_GROUP_CH_1 | ADC_GROUP_CH_2;
#endif /* XT32H0xxB */  
}

/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group2 ADC Operation Functions
  * @brief    Operation functions
  * @{
  */
/**
  * @brief  Reset ADC
  */
void ADC_Reset(void)
{
#if defined(XT32H0xxB)
  MDU->MDU_CFG &= (uint32_t)~((uint32_t)MDU_MDUCFG_ADC_RST);
#else
  MDU->ADC_CTRL &= (uint32_t)~((uint32_t)MDU_ADCCTRL_RST);
#endif /* XT32H0xxB */
}

/**
  * @brief  Release reset ADC
  */
void ADC_ResetRelease(void)
{
#if defined(XT32H0xxB)
  MDU->MDU_CFG |= ((uint32_t)MDU_MDUCFG_ADC_RST);   
#else
  MDU->ADC_CTRL |= ((uint32_t)MDU_ADCCTRL_RST);
#endif /* XT32H0xxB */
}

/**
  * @brief  Power on ADC
  */
void ADC_PowerOn(void)
{
  MDU->PDCTRL &= (uint32_t)~((uint32_t)MDU_PDCTRL_ADCPD);
}

/**
  * @brief  Power down ADC
  */
void ADC_PowerDown(void)
{
  MDU->PDCTRL |= ((uint32_t)MDU_PDCTRL_ADCPD);
}

#if defined(XT32H0xxB)
/**
  * @brief  Set ADC mode
  * @param  Mode
  *         This value is one of the following parapmeter:
  *         @arg @ref ADC_CONTROL_MODE_MANUAL
  *         @arg @ref ADC_CONTROL_MODE_AUTO
  */
void ADC_SetMode(uint32_t Mode)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_ADCC_EN);
  temp |= Mode;
  
  MDU->ADC_CFG = temp;
}

/**
  * @brief  Set ADC data alignment
  * @param  Align
  *         This value is one of the following parapmeter:
  *         @arg @ref ADC_OUTPUT_AGLIN_LSB
  *         @arg @ref ADC_OUTPUT_AGLIN_MSB
  */
void ADC_SetDataAlignment(uint32_t Align)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_ADCOUTALIGN);
  temp |= Align;
  
  MDU->ADC_CFG = temp;
}

/**
  * @brief  Set ADC data resolution
  * @param  Resolution
  *         This value is one of the following parapmeter:
  *         @arg @ref ADC_RESOLUTION_8B
  *         @arg @ref ADC_RESOLUTION_10B
  *         @arg @ref ADC_RESOLUTION_12B
  */
void ADC_SetResolution(uint32_t Resolution)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_ADCDATAW);
  temp |= Resolution;
  
  MDU->ADC_CFG = temp;
}

/**
  * @brief  Enable Injection DMA
  */
void ADC_EnableInjectionDMA(void)
{
  MDU->DMA_CFG |= MDU_ADCDMACFG_INJ_DMA_EN;
}

/**
  * @brief  Disable Injection DMA
  */
void ADC_DisableInjectionDMA(void)
{
  MDU->DMA_CFG &= ~(MDU_ADCDMACFG_INJ_DMA_EN);
}

/**
  * @brief  Enable regular DMA
  */
void ADC_EnableRegularDMA(void)
{
  MDU->DMA_CFG |= MDU_ADCDMACFG_REG_DMA_EN;
}

/**
  * @brief  Disable regular DMA
  */
void ADC_DisableRegularDMA(void)
{
  MDU->DMA_CFG &= ~(MDU_ADCDMACFG_REG_DMA_EN);
}

/**
  * @brief  Enable ADC interrupts
  * @param  Interrupts
  *         This value is combined of the following parapmeter:
  *         @arg @ref ADC_INT_ENABLE_INJGRP_EOC
  *         @arg @ref ADC_INT_ENABLE_INJGRP_EOS
  *         @arg @ref ADC_INT_ENABLE_REGGRP_EOC
  *         @arg @ref ADC_INT_ENABLE_REGGRP_EOS
  */
void ADC_EnableInterrupts(uint32_t Interrupts)
{
  MDU->MDU_CFG |= Interrupts;
}

/**
  * @brief  Disable ADC interrupts
  * @param  Interrupts
  *         This value is combined of the following parapmeter:
  *         @arg @ref ADC_INT_ENABLE_INJGRP_EOC
  *         @arg @ref ADC_INT_ENABLE_INJGRP_EOS
  *         @arg @ref ADC_INT_ENABLE_REGGRP_EOC
  *         @arg @ref ADC_INT_ENABLE_REGGRP_EOS
  */
void ADC_DisableInterrupts(uint32_t Interrupts)
{
  MDU->MDU_CFG &= ~(Interrupts);
}

/**
  * @brief  Set ADC injection interrupts polarity
  * @param  Polarity
  *         This value is one of the following parapmeter:
  *         @arg @ref ADC_INT_POLARITY_HIGH
  *         @arg @ref ADC_INT_POLARITY_LOW
  */
void ADC_SetInjectionInterruptsPolarity(uint32_t Polarity)
{
  uint32_t temp = MDU->MDU_CFG;

  temp &= ~(MDU_MDUCFG_INJ_INT_POL);
  temp |= (Polarity << MDU_MDUCFG_INJ_INT_POL_Pos) ;
  
  MDU->MDU_CFG = temp;
}

/**
  * @brief  Set ADC regular interrupts polarity
  * @param  Polarity
  *         This value is one of the following parapmeter:
  *         @arg @ref ADC_INT_POLARITY_HIGH
  *         @arg @ref ADC_INT_POLARITY_LOW
  */
void ADC_SetRegularInterruptsPolarity(uint32_t Polarity)
{
  uint32_t temp = MDU->MDU_CFG;

  temp &= ~(MDU_MDUCFG_REG_INT_POL);
  temp |= (Polarity << MDU_MDUCFG_REG_INT_POL_Pos) ;
  
  MDU->MDU_CFG = temp;
}

/**
  * @brief  Set ADC reset delay
  * @param  Delay
  *         This value is one of [0, 0xF]
  */
void ADC_SetResetDelay(uint32_t Delay)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_RSTBDLY);
  temp |= (Delay << MDU_ADCCFG_RSTBDLY_Pos) ;
  
  MDU->ADC_CFG = temp;
}

/**
  * @brief  Set ADC reset pulse width
  * @param  Cycles
  *         This value is one of [0, 0xF]
  */
void ADC_SetResetPulse(uint32_t Cycles)
{
  uint32_t temp = MDU->MDU_CFG;

  temp &= ~(MDU_MDUCFG_RSTB_CYC);
  temp |= (Cycles << MDU_MDUCFG_RSTB_CYC_Pos) ;
  
  MDU->MDU_CFG = temp;
}

/**
  * @brief  Set ADC PGA pre-sampling mode
  * @param  Mode
  *         This value is one of the following parapmeter:
  *         @arg @ref ADC_PRESAMPLING_MODE_SAME
  *         @arg @ref ADC_PRESAMPLING_MODE_DEDICATED
  */
void ADC_SetPGAPresamplingMode(uint32_t Mode)
{
  uint32_t temp = MDU->MDU_CFG;

  temp &= ~(MDU_MDUCFG_SEL_PGA_CTRL);
  temp |= (Mode);
  
  MDU->MDU_CFG = temp;
}

/**
  * @brief  Set ADC PGA pre-sampling cycles in same mode
  * @param  Cycles
  *         This value is one of [0, 0x3F]
  */
void ADC_SetSamePGAPresamplingCycles(uint32_t Cycles)
{
  uint32_t temp = MDU->MDU_CFG;

  temp &= ~(MDU_MDUCFG_SYNC_PHS);
  temp |= (Cycles << MDU_MDUCFG_SYNC_PHS_Pos);
  
  MDU->MDU_CFG = temp;
}

/**
  * @brief  Enable discharge phase
  */
void ADC_EnableDischargePhase(void)
{
  MDU->MDU_CFG |= MDU_MDUCFG_DSCH_EN;
}

/**
  * @brief  Disable discharge phase
  */
void ADC_DisableDischargePhase(void)
{
  MDU->MDU_CFG &= ~(MDU_MDUCFG_DSCH_EN);
}

/**
  * @brief  Set ADC discharge phase cycles
  * @param  Cycles
  *         This value is one of [0, 0xFF]
  */
void ADC_SetDischargePhaseCycles(uint32_t Cycles)
{
  uint32_t temp = MDU->MDU_CFG;

  temp &= ~(MDU_MDUCFG_DSCH_PHS);
  temp |= (Cycles << MDU_MDUCFG_DSCH_PHS_Pos);
  
  MDU->MDU_CFG = temp;
}

/**
  * @brief  ADC enable ADc controller
  */
void ADC_EnableControler(void)
{
  MDU->MDU_CFG |= MDU_MDUCFG_ADC_EN;
}

/**
  * @brief  ADC disable ADc controller
  */
void ADC_DisableControler(void)
{
  MDU->MDU_CFG &= ~(MDU_MDUCFG_ADC_EN);
}

/**
  * @brief  ADC software trigger force to high
  */
void ADC_SoftwareTriggerForeceHigh(void)
{
  MDU->MDU_CFG |= MDU_MDUCFG_ADC_SFTRG;
}

/**
  * @brief  ADC software trigger force to low
  */
void ADC_SoftwareTriggerForeceLow(void)
{
  MDU->MDU_CFG &= ~(MDU_MDUCFG_ADC_SFTRG);
}

/**
  * @brief  ADC conversion start
  */
void ADC_Start(void)
{
  MDU->MDU_CFG |= MDU_MDUCFG_ADC_START_EN;
}

/**
  * @brief  ADC conversion stop
  */
void ADC_Stop(void)
{
  MDU->MDU_CFG &= ~(MDU_MDUCFG_ADC_START_EN);
}

/**
  * @brief  ADC enable injection group
  */
void ADC_EnableInjectionGroup(void)
{
  MDU->MDU_CFG |= MDU_MDUCFG_INJ_GRP_EN;
}

/**
  * @brief  ADC disable injection group
  */
void ADC_DisableInjectionGroup(void)
{
  MDU->MDU_CFG &= ~(MDU_MDUCFG_INJ_GRP_EN);
}

/**
  * @brief  Set ADC injection group number
  * @param  Number
  *         This value is one of [0, 4]
  */
void ADC_SetInjectionGroupNumber(uint32_t Number)
{
  uint32_t temp = MDU->INJGRP_TRG;

  temp &= ~(MDU_INJGRP_TRG_INJGRP_SGRP_NUM);
  temp |= (Number << MDU_INJGRP_TRG_INJGRP_SGRP_NUM_Pos);
  
  MDU->INJGRP_TRG = temp;
}

/**
  * @brief  ADC enable regular group
  */
void ADC_EnableRegularGroup(void)
{
  MDU->MDU_CFG |= MDU_MDUCFG_REG_GRP_EN;
}

/**
  * @brief  ADC disable regular group
  */
void ADC_DisableRegularGroup(void)
{
  MDU->MDU_CFG &= ~(MDU_MDUCFG_REG_GRP_EN);
}

/**
  * @brief  Set ADC regular group number
  * @param  Number
  *         This value is one of [0, 8]
  */
void ADC_SetRegularGroupNumber(uint32_t Number)
{
  uint32_t temp = MDU->REGGRP_TRGCFG;

  temp &= ~(MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM);
  temp |= (Number << MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_Pos);
  
  MDU->REGGRP_TRGCFG = temp;
}

/* injection group */
/**
  * @brief  Set ADC injection group trigger source and mode
  * @param  Group
  *         This value is one of the following values:
  *         @arg @ref ADC_INJGRP_ID_1
  *         @arg @ref ADC_INJGRP_ID_2
  *         @arg @ref ADC_INJGRP_ID_3
  *         @arg @ref ADC_INJGRP_ID_4
  * @param  Source
  *         This value is one of the following values:
  *         @arg @ref ADC_TRGSRC_NONE       
  *         @arg @ref ADC_TRGSRC_TIMA1_CH4  
  *         @arg @ref ADC_TRGSRC_TIMA1_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMA2_CH4  
  *         @arg @ref ADC_TRGSRC_TIMA2_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG1_CH4  
  *         @arg @ref ADC_TRGSRC_TIMG1_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG2_CH4  
  *         @arg @ref ADC_TRGSRC_TIMG2_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG3_CH4  
  *         @arg @ref ADC_TRGSRC_TIMG3_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG4_CH4  
  *         @arg @ref ADC_TRGSRC_TIMG4_TRGO2
  *         @arg @ref ADC_TRGSRC_EXTERNAL   
  *         @arg @ref ADC_TRGSRC_TIMB11     
  *         @arg @ref ADC_TRGSRC_SOFTWARE   
  * @param  Mode
  *         This value is one of the following values:
  *         @arg @ref ADC_TRIGGEREDGE_NONE   
  *         @arg @ref ADC_TRIGGEREDGE_RISING 
  *         @arg @ref ADC_TRIGGEREDGE_FALLING
  *         @arg @ref ADC_TRIGGEREDGE_BOTH   
  */
void ADC_InjectionGroupTriggerConfig(uint32_t Group, uint32_t Source, uint32_t Mode)
{
  uint32_t temp = MDU->INJGRP_TRG;

  temp &= ~((MDU_INJGRP_TRG_INJGRP_TRGSRC_1 << ((Group - 1) << 2))|(MDU_INJGRP_TRG_INJGRP_TRGCFG_1 << ((Group - 1) << 1)));
  temp |= ((Source << (MDU_INJGRP_TRG_INJGRP_TRGSRC_1_Pos + ((Group - 1) << 2)))|(Mode << (MDU_INJGRP_TRG_INJGRP_TRGCFG_1_Pos + ((Group - 1) << 1))))
  MDU->INJGRP_TRG = temp;
}

/**
  * @brief  Set ADC injection group channel
  * @param  Channel injection channel
  *         This value is one of [0, 3]
  * @param  Group
  *         This value is one of the following values:
  *         @arg @ref ADC_INJGRP_ID_1
  *         @arg @ref ADC_INJGRP_ID_2
  *         @arg @ref ADC_INJGRP_ID_3
  *         @arg @ref ADC_INJGRP_ID_4
  * @param  ADCChannel ADC channel
  *         This value is one og [0, 63]
  * @param  SamplingCycles
  *         This value is one of [0, 0x3F]
  * @param  Awd
  *         This value is one of the following values:
  *         @arg @ref ADC_AWD_ID_NONE
  *         @arg @ref ADC_AWD_ID_1   
  *         @arg @ref ADC_AWD_ID_2   
  *         @arg @ref ADC_AWD_ID_3   
  */
void ADC_InjectionChannelConfig(uint32_t Channel, uint32_t Group, uint32_t ADCChannel, uint32_t SamplingCycles, uint32_t Awd)
{
  uint32_t *pReg = ((uint32_t*)&(MDU->INJGRP_CHCR_1)) + Channel;

  uint32_t temp = *pReg;

  temp &= ~(MDU_INJGRP_CHCR_GRP_ID_1 | MDU_INJGRP_CHCR_ADCCH_ID_1 | MDU_INJGRP_CHCR_SMP_CYC_1 | MDU_INJGRP_CHCR_AWD_ID_1);
  temp |= ( (Group << MDU_INJGRP_CHCR_GRP_ID_1_Pos) | 
            (ADCChannel << MDU_INJGRP_CHCR_ADCCH_ID_1_Pos) |
            (SamplingCycles << MDU_INJGRP_CHCR_SMP_CYC_1_Pos) |
            (Awd << MDU_INJGRP_CHCR_AWD_ID_1_Pos) );

  *pReg = temp;
}

/**
  * @brief  Get ADC injection channel EOC flag
  * @param  Channel
  *         This value is one of [0, 3]
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetInjectionEOCFlag(uint32_t Channel)
{
  return (MDU->INT_STATUS_1 & (MDU_INT_STATUS_EOC_INJ_CH_1 << Channel) ? SET : RESET);
}

/**
  * @brief  Get ADC injection EOS flag
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetInjectionEOSFlag(void)
{
  return (MDU->INT_STATUS_1 & (MDU_INT_STATUS_EOS_INJ) ? SET : RESET);
}

/**
  * @brief  Get ADC injection channel AWD flag
  * @param  Channel
  *         This value is one of [0, 3]
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetInjectionAWDFlag(uint32_t Channel)
{
  return (MDU->INT_STATUS_1 & (MDU_INT_STATUS_AWD_INJ_CH_1 << Channel) ? SET : RESET);
}

/**
  * @brief  Get ADC injection channel OW flag
  * @param  Channel
  *         This value is one of [0, 3]
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetInjectionOWFlag(uint32_t Channel)
{
  return (MDU->INT_STATUS_1 & (MDU_INT_STATUS_OW_INJ_CH_1 << Channel) ? SET : RESET);
}

/**
  * @brief  Get ADC comp flag
  * @param  Comp
  *         This value is one of [0, 3]
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetCompFlag(uint32_t Comp)
{
  return (MDU->INT_STATUS_1 & (MDU_INT_STATUS_OCOMP0 << Channel) ? SET : RESET);
}

/**
  * @brief  Clear ADC injection channel EOC flag
  * @param  Channel
  *         This value is one of [0, 3]
  */
void ADC_ClearInjectionEOCFlag(uint32_t Channel)
{
  MDU->INT_STATUS_1 &= ~(MDU_INT_STATUS_EOC_INJ_CH_1 << Channel);
}

/**
  * @brief  Clear ADC injection channel EOS flag
  */
void ADC_ClearInjectionEOSFlag(void)
{
  MDU->INT_STATUS_1 &= ~(MDU_INT_STATUS_EOS_INJ);
}

/**
  * @brief  Clear ADC injection channel AWD flag
  * @param  Channel
  *         This value is one of [0, 3]
  */
void ADC_ClearInjectionAWDFlag(uint32_t Channel)
{
  MDU->INT_STATUS_1 &= ~(MDU_INT_STATUS_AWD_INJ_CH_1 << Channel);
}

/**
  * @brief  Clear ADC injection channel OW flag
  * @param  Channel
  *         This value is one of [0, 3]
  */
void ADC_ClearInjectionOWFlag(uint32_t Channel)
{
  MDU->INT_STATUS_1 &= ~(MDU_INT_STATUS_OW_INJ_CH_1 << Channel);
}

/**
  * @brief  Clear ADC comp flag
  * @param  Comp
  *         This value is one of [0, 3]
  */
void ADC_ClearCompFlag(uint32_t Comp)
{
  MDU->INT_STATUS_1 &= ~(MDU_INT_STATUS_OCOMP0 << Channel);
}

/* regular group */
/**
  * @brief  Set ADC regular group operation mode
  * @param  Mode
  *         This value is one of the following values:
  *         @arg @ref ADC_CONVERT_SINGLESCAN
  *         @arg @ref ADC_CONVERT_CONTINUOUSSCAN
  *         @arg @ref ADC_CONVERT_DISCONTINUOUSSCAN
  */
void ADC_SetRegularOperationMode(uint32_t Mode)
{
  uint32_t temp = MDU->REGGRP_TRGCFG;

  temp &= ~(MDU_REGGRP_TRGCFG_REGGRP_OPMODE);
  temp |= Mode;

  MDU->REGGRP_TRGCFG = temp;
}

/**
  * @brief  Set ADC injection group trigger source and mode
  * @param  Group
  *         This value is one of the following values:
  *         @arg @ref ADC_REGGRP_ID_1
  *         @arg @ref ADC_REGGRP_ID_2
  *         @arg @ref ADC_REGGRP_ID_3
  *         @arg @ref ADC_REGGRP_ID_4
  *         @arg @ref ADC_REGGRP_ID_5
  *         @arg @ref ADC_REGGRP_ID_6
  *         @arg @ref ADC_REGGRP_ID_7
  *         @arg @ref ADC_REGGRP_ID_8
  * @param  Source
  *         This value is one of the following values:
  *         @arg @ref ADC_TRGSRC_NONE       
  *         @arg @ref ADC_TRGSRC_TIMA1_CH4  
  *         @arg @ref ADC_TRGSRC_TIMA1_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMA2_CH4  
  *         @arg @ref ADC_TRGSRC_TIMA2_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG1_CH4  
  *         @arg @ref ADC_TRGSRC_TIMG1_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG2_CH4  
  *         @arg @ref ADC_TRGSRC_TIMG2_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG3_CH4  
  *         @arg @ref ADC_TRGSRC_TIMG3_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG4_CH4  
  *         @arg @ref ADC_TRGSRC_TIMG4_TRGO2
  *         @arg @ref ADC_TRGSRC_EXTERNAL   
  *         @arg @ref ADC_TRGSRC_TIMB11     
  *         @arg @ref ADC_TRGSRC_SOFTWARE   
  * @param  Mode
  *         This value is one of the following values:
  *         @arg @ref ADC_TRIGGEREDGE_NONE   
  *         @arg @ref ADC_TRIGGEREDGE_RISING 
  *         @arg @ref ADC_TRIGGEREDGE_FALLING
  *         @arg @ref ADC_TRIGGEREDGE_BOTH   
  */
void ADC_RegularGroupTriggerConfig(uint32_t Group, uint32_t Source, uint32_t Mode)
{
  uint32_t temp = 0;
  
  temp = MDU->REGGRP_TRG;

  temp &= ~(MDU_REGGRP_TRG_REGGRP_TRGSRC_1 << ((Group-1) << 2));
  temp |= (Mode << (MDU_REGGRP_TRG_REGGRP_TRGSRC_1_Pos + ((Group-1) << 2)));

  MDU->REGGRP_TRG = temp;

  temp = MDU->REGGRP_TRGCFG;

  temp &= ~(MDU_REGGRP_TRGCFG_REGGRP_CFG_1 << ((Group -1) << 1));
  temp |= (Mode << (MDU_REGGRP_TRGCFG_REGGRP_CFG_1_Pos + ((Group -1) << 1)));

  MDU->REGGRP_TRGCFG = temp;
}

/**
  * @brief  Set ADC all regular channel map
  * @param  Map
  *         This value is one of [0, 0xFFFFFFFF]
  */
void ADC_SetAllRegularChannelMap(uint32_t Map)
{
  MDU->REGGRP_CHMAP = Map;
}

/**
  * @brief  Set ADC regular group channel map
  * @param  Group
  *         This value is one of the following values:
  *         @arg @ref ADC_REGGRP_ID_1
  *         @arg @ref ADC_REGGRP_ID_2
  *         @arg @ref ADC_REGGRP_ID_3
  *         @arg @ref ADC_REGGRP_ID_4
  *         @arg @ref ADC_REGGRP_ID_5
  *         @arg @ref ADC_REGGRP_ID_6
  *         @arg @ref ADC_REGGRP_ID_7
  *         @arg @ref ADC_REGGRP_ID_8
  * @param  Map
  *         This value is one of [0, 0xFFFFFFFF]
  */
void ADC_SetGroupRegularChannelMap(uint32_t Group, uint32_t Map)
{
   uint32_t *pReg = ((uint32_t*)&(MDU->REGGRP_SGRP_CHMAP_1)) + (Group -1);
   *pReg = Map;
}

/**
  * @brief  Set ADC regular group channel
  * @param  Channel injection channel
  *         This value is one of [0, 31]
  * @param  ADCChannel ADC channel
  *         This value is one og [0, 63]
  * @param  Awd
  *         This value is one of the following values:
  *         @arg @ref ADC_AWD_ID_NONE
  *         @arg @ref ADC_AWD_ID_1   
  *         @arg @ref ADC_AWD_ID_2   
  *         @arg @ref ADC_AWD_ID_3   
  */
void ADC_RegularChannelConfig(uint32_t Channel, uint32_t ADCChannel, uint32_t Awd)
{
  uint32_t *pReg = ((uint32_t*)&(MDU->REGGRP_CHCR_1)) + (Channel >> 2);
  uint32_t temp = *pReg;

  temp &= ~((MDU_REGGRP_CHCR_ADC_CHID_1 << ((Channel & 0x3) << 3)) | 
            (MDU_REGGRP_CHCR_AWD_ID_1 << ((Channel & 0x3) << 3)));
  temp |= ( (ADCChannel << (MDU_REGGRP_CHCR_ADC_CHID_1_Pos + ((Channel & 0x3) << 3))) | 
            (Awd << (MDU_REGGRP_CHCR_AWD_ID_1_Pos + ((Channel & 0x3) << 3))));

  *pReg = temp;
}

/**
  * @brief  ADC regular group continuous scan mode start
  */
void ADC_RegularGroupContinuousConversionStart(void)
{
  MDU->REGGRP_TRGCFG |= MDU_REGGRP_TRGCFG_REGGRP_CS_START;
}

/**
  * @brief  ADC regular group continuous scan mode stop
  */
void ADC_RegularGroupContinuousConversionStop(void)
{
  MDU->REGGRP_TRGCFG &= ~(MDU_REGGRP_TRGCFG_REGGRP_CS_START);
}

/* interrupt flsgs */
/**
  * @brief  Get ADC regular channel EOC flag
  * @param  Channel
  *         This value is one of [0, 31]
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetRegularEOCFlag(uint32_t Channel)
{
  if(Channel<16)
  {
    return (MDU->INT_STATUS_2 & (1 << Channel) ? SET : RESET);
  }
  else
  {
    return (MDU->INT_STATUS_3 & (1 << (Channel-16)) ? SET : RESET);
  }
}

/**
  * @brief  Get ADC regular EOS flag
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetRegularEOSFlag(void)
{
  return (MDU->INT_STATUS_1 & (MDU_INT_STATUS_EOS_REG) ? SET : RESET);
}

/**
  * @brief  Get ADC regular channel AWD flag
  * @param  Channel
  *         This value is one of [0, 31]
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetRegularAWDFlag(uint32_t Channel)
{
  return (MDU->INT_STATUS_4 & (1 << Channel) ? SET : RESET);
}

/**
  * @brief  Get ADC regular channel OW flag
  * @param  Channel
  *         This value is one of [0, 31]
  * @retval status (SET or RESET)
  */
uint32_t ADC_GetRegularOWFlag(uint32_t Channel)
{
  if(Channel<16)
  {
    return (MDU->INT_STATUS_2 & (MDU_INT_STATUS_OW_REG_CH_1 << Channel) ? SET : RESET);
  }
  else
  {
    return (MDU->INT_STATUS_3 & (MDU_INT_STATUS_OW_REG_CH_1 << (Channel-16)) ? SET : RESET);
  }
}

/**
  * @brief  Clear ADC regular channel EOC flag
  * @param  Channel
  *         This value is one of [0, 31]
  */
void ADC_ClearRegularEOCFlag(uint32_t Channel)
{
  if(Channel<16)
  {
    MDU->INT_STATUS_2 &= ~ (1 << Channel);
  }
  else
  {
    MDU->INT_STATUS_3 &= ~(1 << (Channel-16));
  }

}

/**
  * @brief  Clear ADC regular channel AWD flag
  */
void ADC_ClearRegularEOSFlag(void)
{
  MDU->INT_STATUS_1 &= ~(MDU_INT_STATUS_EOS_REG);
}

/**
  * @brief  Clear ADC regular channel AWD flag
  * @param  Channel
  *         This value is one of [0, 31]
  */
void ADC_ClearRegularAWDFlag(uint32_t Channel)
{
  MDU->INT_STATUS_4 &= ~(1 << Channel);
}

/**
  * @brief  Clear ADC regular channel OW flag
  * @param  Channel
  *         This value is one of [0, 31]
  */
void ADC_ClearRegularOWFlag(uint32_t Channel)
{
  if(Channel<16)
  {
    MDU->INT_STATUS_2 &= ~(MDU_INT_STATUS_OW_REG_CH_1 << Channel);
  }
  else
  {
    MDU->INT_STATUS_3 &= ~(MDU_INT_STATUS_OW_REG_CH_1 << (Channel-16));
  }
}

/* Awd */
/**
  * @brief  ADC AWD configure
  * @param  Awd
  *         This value is one of the following values:
  *         @arg @ref ADC_AWD_ID_NONE 
  *         @arg @ref ADC_AWD_ID_1    
  *         @arg @ref ADC_AWD_ID_2    
  *         @arg @ref ADC_AWD_ID_3    
  * @param  ThresholdLow
  *         This value is one of [0, 0xFFF]
  * @param  ThresholdHigh
  *         This value is one of [0, 0xFFF]
  * @param  Mode
  *         This value is one of the following values:
  *         @arg @ref ADC_AWD_MODE_NONE   
  *         @arg @ref ADC_AWD_MODE_LOW    
  *         @arg @ref ADC_AWD_MODE_MID    
  *         @arg @ref ADC_AWD_MODE_HIGH   
  */
void ADC_AwdConfig(uint32_t Awd, uint32_t ThresholdLow, uint32_t ThresholdHigh, uint32_t Mode)
{
  uint32_t *pReg = (uint32_t*)&(MDU->AWD_CR_1);
  uint32_t temp = 0;

  pReg = pReg+(Awd-1);

  temp = *pReg;

  temp &= ~(MDU_AWD_CR_THR_LOW_1|MDU_AWD_CR_THR_HIGH_1|MDU_AWD_CR_CFG_1);
  temp |= (Mode|(ThresholdLow << MDU_AWD_CR_THR_LOW_1_Pos)|(ThresholdHigh << MDU_AWD_CR_THR_HIGH_1_Pos));
  
  *pReg = temp;
}

/* manual mode operations */
/**
  * @brief  ADC enable PGA pre-sampling in manual mode
  */
void ADC_EnablePGASamplingPulseInManualMode(void)
{
  MDU->ADC_CFG |= MDU_ADCCFG_MSAMPEN;
}

/**
  * @brief  ADC disable PGA pre-sampling in manual mode
  */
void ADC_DisablePGASamplingPulseInManualMode(void)
{
  MDU->ADC_CFG &= ~(MDU_ADCCFG_MSAMPEN);
}

/**
  * @brief  Set ADC core conversion mode in manual mode
  * @param  Mode
  *         This value is one of the following parapmeter:
  *         @arg @ref ADC_CORE_CONV_MODE_CONTINUOUS
  *         @arg @ref ADC_CORE_CONV_MODE_SINGLE
  */
void ADC_SetCoreConversionMode(uint32_t Mode)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_MCONVMODE);
  temp |= (Mode);
  
  MDU->ADC_CFG = temp;
}

/**
  * @brief  Set ADC core channel in manual mode
  * @param  Channel
  *         This value is one of the following values:
  *         @arg @ref ADC_CHANNEL_1               
  *         @arg @ref ADC_CHANNEL_2               
  *         @arg @ref ADC_CHANNEL_3               
  *         @arg @ref ADC_CHANNEL_4               
  *         @arg @ref ADC_CHANNEL_5               
  *         @arg @ref ADC_CHANNEL_6               
  *         @arg @ref ADC_CHANNEL_7               
  *         @arg @ref ADC_CHANNEL_8               
  *         @arg @ref ADC_CHANNEL_9               
  *         @arg @ref ADC_CHANNEL_10              
  *         @arg @ref ADC_CHANNEL_11              
  *         @arg @ref ADC_CHANNEL_12              
  *         @arg @ref ADC_CHANNEL_13              
  *         @arg @ref ADC_CHANNEL_14              
  *         @arg @ref ADC_CHANNEL_15              
  *         @arg @ref ADC_CHANNEL_16              
  *         @arg @ref ADC_CHANNEL_17              
  *         @arg @ref ADC_CHANNEL_18              
  *         @arg @ref ADC_CHANNEL_19              
  *         @arg @ref ADC_CHANNEL_20              
  *         @arg @ref ADC_CHANNEL_21              
  *         @arg @ref ADC_CHANNEL_22              
  *         @arg @ref ADC_CHANNEL_23              
  *         @arg @ref ADC_CHANNEL_24              
  *         @arg @ref ADC_CHANNEL_25              
  *         @arg @ref ADC_CHANNEL_26              
  *         @arg @ref ADC_CHANNEL_27              
  *         @arg @ref ADC_CHANNEL_28              
  *         @arg @ref ADC_CHANNEL_29              
  *         @arg @ref ADC_CHANNEL_30              
  *         @arg @ref ADC_CHANNEL_31              
  *         @arg @ref ADC_CHANNEL_32              
  *         @arg @ref ADC_CHANNEL_33              
  *         @arg @ref ADC_CHANNEL_34              
  *         @arg @ref ADC_CHANNEL_35              
  *         @arg @ref ADC_CHANNEL_36              
  *         @arg @ref ADC_CHANNEL_37              
  *         @arg @ref ADC_CHANNEL_38              
  *         @arg @ref ADC_CHANNEL_39              
  *         @arg @ref ADC_CHANNEL_40              
  *         @arg @ref ADC_CHANNEL_41              
  *         @arg @ref ADC_CHANNEL_42              
  *         @arg @ref ADC_CHANNEL_43              
  *         @arg @ref ADC_CHANNEL_44              
  *         @arg @ref ADC_CHANNEL_45              
  *         @arg @ref ADC_CHANNEL_46              
  *         @arg @ref ADC_CHANNEL_47              
  *         @arg @ref ADC_CHANNEL_48              
  *         @arg @ref ADC_CHANNEL_49              
  *         @arg @ref ADC_CHANNEL_50              
  *         @arg @ref ADC_CHANNEL_51              
  *         @arg @ref ADC_CHANNEL_52              
  *         @arg @ref ADC_CHANNEL_53               
  *         @arg @ref ADC_CHANNEL_VBG             
  *         @arg @ref ADC_CHANNEL_VTS             
  *         @arg @ref ADC_CHANNEL_VBS             
  *         @arg @ref ADC_CHANNEL_P2AVDD          
  *         @arg @ref ADC_CHANNEL_P3AVDD          
  *         @arg @ref ADC_CHANNEL_P4AVDD          
  *         @arg @ref ADC_CHANNEL_P5AVDD          
  *         @arg @ref ADC_CHANNEL_P6AVDD          
  *         @arg @ref ADC_CHANNEL_P7AVDD          
  *         @arg @ref ADC_CHANNEL_P8AVDD          
  *         @arg @ref ADC_CHANNEL_64              
  */
void ADC_SetCoreChannelInManualMode(uint32_t Channel)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_MCHSLCT);
  temp |= (Channel << MDU_ADCCFG_MCHSLCT_Pos);
  
  MDU->ADC_CFG = temp;
}

/* calibrate operations */
/**
  * @brief  ADC measure for calibrate
  * @param  Mode
  *         0 : low code
  *         1 : high code
  */
uint32_t ADC_Measure(uint32_t Mode)
{
	uint32_t reg = 0;
	uint32_t channel = (Mode) ? ADC_CHANNEL_P7AVDD : ADC_CHANNEL_P3AVDD;
	
	uint32_t result = 0;
	
  /* measure x vdd */
  /* Configure Injection Channel */
  reg = MDU->INJGRP_CHCR_1;
  reg &= ~((uint32_t)(MDU_INJGRP_CHCR_GRP_ID_1|
                      MDU_INJGRP_CHCR_ADCCH_ID_1|
                      MDU_INJGRP_CHCR_SMP_CYC_1|
                      MDU_INJGRP_CHCR_AWD_ID_1));
  reg |= (uint32_t)( ADC_INJGRP_ID_1 | 
                    (channel << MDU_INJGRP_CHCR_ADCCH_ID_1_Pos) |
                    (0x3UL << MDU_INJGRP_CHCR_SMP_CYC_1_Pos) |
                    (ADC_AWD_ID_NONE << MDU_INJGRP_CHCR_AWD_ID_1_Pos));
  MDU->INJGRP_CHCR_1 = reg;

  /* start */
  MDU->MDU_CFG |= MDU_MDUCFG_ADC_EN;
  MDU->REGGRP_TRGCFG &= ~(MDU_REGGRP_TRGCFG_REGGRP_CS_START);

	/* wait 10us */
	while(tmp_status < 10)
	{
		tmp_status++;
	}

  /* soft trigger */
  if(MDU->ADC_CTRL & MDU_ADCCTRL_SWTRG) 
  {
    MDU->ADC_CTRL &= ~((uint32_t) MDU_ADCCTRL_SWTRG);
  }
  else
  {
    MDU->ADC_CTRL |= (uint32_t) MDU_ADCCTRL_SWTRG;
  }

  /* read result */
  tmp_status = (MDU->INT_STATUS_1 & ADC_FLAG_INJGRP_EOS);

  /* Wait until End of unitary conversion or sequence conversions flag is raised */
  while (tmp_status == 0UL)
  {
    tmp_status = (MDU->INT_STATUS_1 & ADC_FLAG_INJGRP_EOS);
  }

  MDU->INT_STATUS_1  = 0;

  result = ((MDU->INJ_RESULTS_1)&0x0000FFFFUL);

  /* stop */
  MDU->MDU_CFG &= ~(MDU_MDUCFG_ADC_EN);
	
	return result;
}

/**
  * @brief  ADC calibrate
  */
void ADC_Calibration(void)
{
#define ADC_CALI_MEAS_NUMBER (8)
#define ADC_CALI_MEAS_CLOCK  (8000000)

  uint32_t adcclkdiv = 2;
  
  uint32_t hdata = 0;
  uint32_t ldata = 0;

	int k = 0;
	int d = 0;

  uint16_t gain = 1;
  uint16_t offset = 0;

  uint32_t reg = 0;

  int i = 0;

  /* configure ADC clock */
  adcclkdiv = RCC_GetHCLKClock() / ADC_CALI_MEAS_CLOCK;
  reg = ICG->CLK_CFG;
  reg &= ~((uint32_t)ICG_CLK_CTL_ADCSRC);
  reg |= (uint32_t)(RCC_ADCCLKSOURCE_HCLK);
  ICG->CLK_CFG=reg;

  ICG->ADC_CLK_DIV = adcclkdiv;

  /* ADC core config */
	MDU->ADC_CFG |= MDU_ADCCFG_MCONVMODE;  /* core in single conversion mode*/
	
  /* configure group conversion */
  reg = MDU->INJGRP_TRG;
  reg &= ~((uint32_t)MDU_INJGRP_TRG_INJGRP_SGRP_NUM);
  reg |= (uint32_t)( 0x1UL << MDU_INJGRP_TRG_INJGRP_SGRP_NUM_Pos);
  MDU->INJGRP_TRG = reg;

  /* configure parameters */
  reg = MDU->MDU_CFG;
  reg &= ~((uint32_t)(MDU_MDUCFG_DSCH_EN|MDU_MDUCFG_DSCH_PHS|
                      MDU_MDUCFG_SEL_PGA_CTRL|MDU_MDUCFG_SYNC_PHS|
                      MDU_MDUCFG_RSTB_CYC|
                      MDU_ADCDMACFG_INJ_DMA_EN|MDU_ADCDMACFG_REG_DMA_EN|
                      MDU_ADCCFG_ADCOUTALIGN|MDU_ADCCFG_ADCDATAW));
  reg |= (uint32_t)(ADC_DISCHARGE_MODE_DISABLE|
                    ADC_PRESAMPLING_MODE_DEDICATED|(0x3UL << MDU_MDUCFG_SYNC_PHS_Pos)|
                    (0x2UL << MDU_MDUCFG_RSTB_CYC_Pos)|
                    ADC_INJGRP_DMA_DISABLE|ADC_REGGRP_DISABLE|
                    ADC_RESOLUTION_12B | ADC_OUTPUT_AGLIN_MSB);
  MDU->MDU_CFG = reg;

  /* powder on and enable */
  reg = MDU->PDCTRL;
  reg &= ~((uint32_t)(MDU_PDCTRL_ADCPD));
  MDU->PDCTRL = reg;

  reg = MDU->MDU_CFG;
  reg |= (uint32_t)(MDU_MDUCFG_ADC_START_EN|MDU_MDUCFG_ADC_RST);
  MDU->MDU_CFG = reg;

  /* enable ADCC */
  reg = MDU->ADC_CFG;
  reg |= (uint32_t)(MDU_ADCCFG_ADCC_EN);
  MDU->ADC_CFG = reg;

  /* interrupt enable */
  MDU->INT_STATUS_1 = 0;  /* clear all flags */
  MDU->INT_STATUS_2 = 0;
  MDU->INT_STATUS_3 = 0;
  MDU->INT_STATUS_4 = 0;

  reg = MDU->MDU_CFG;
  reg &= ~((uint32_t)(MDU_MDUCFG_REG_INT_POL|MDU_MDUCFG_INJ_INT_POL|
                      MDU_MDUCFG_INJ_EOC_EN|MDU_MDUCFG_INJ_EOS_EN|MDU_MDUCFG_REG_EOC_EN|MDU_MDUCFG_REG_EOS_EN));
  reg |= (uint32_t)((ADC_INT_POLARITY_HIGH << MDU_MDUCFG_REG_INT_POL_Pos)|
                    (ADC_INT_POLARITY_HIGH << MDU_MDUCFG_INJ_INT_POL_Pos)|
                    ADC_INT_ENABLE_INJGRP_EOS);
  MDU->MDU_CFG = reg;

  /* enable and unmask interrupt */
  ICTL->IRQINTMASKH &= ~((uint32_t)ICTL_IRQCFG_ADC_MASK);
  ICTL->IRQINTENH |= (uint32_t)(ICTL_IRQCFG_ADC_MASK);

  /* configure interupt */
  SYSCFG->IRQ_CFG_2 &= ~((uint32_t)ICTL_IRQCFG_ADC_MASK);

  /* Configure Injection Group */
  reg = MDU->INJGRP_TRG;
  reg &= ~((uint32_t)(MDU_INJGRP_TRG_INJGRP_TRGSRC_1|
                      MDU_INJGRP_TRG_INJGRP_TRGCFG_1));
  reg |= (uint32_t)((ADC_TRGSRC_SOFTWARE)|
                    (ADC_TRIGGEREDGE_BOTH << MDU_INJGRP_TRG_INJGRP_TRGCFG_1_Pos));
  MDU->INJGRP_TRG = reg;
	
	MDU->PDCTRL |= MDU_PDCTRL_ADCBUF_EN;
 
  /* measure 0.7vdd */
  for(i=0; i<ADC_CALI_MEAS_NUMBER; i++)
  {
    if(i<1)
    {
      hdata += ADC_Measure(1);
    }
  }
  hdata = hdata/(ADC_CALI_MEAS_NUMBER-2);

  /* measure 0.3vdd */
  for(i=0; i<ADC_CALI_MEAS_NUMBER; i++)
  {
    if(i<1)
    {
      ldata += ADC_Measure(0);
    }
  }
  ldata = ldata/(ADC_CALI_MEAS_NUMBER-2);

  /* calculate gain & offset */
	k = 0.4*4096*65536/((int)hdata-(int)ldata)/4;
	d = 0.7*4096*4-0.4*4096*(int)hdata*4/((int)hdata-(int)ldata);
	
	gain = ((int16_t)k) & 0x7FFF;
	offset = ((int16_t)d) & 0x3FFF;

  /* set calibrate register & enable */
	MDU->ADC_CALIB = MDU_ADCCALIB_CODE_COR_EN|(gain << MDU_ADCCALIB_CODE_GAIN_Pos)|(offset << MDU_ADCCALIB_CODE_OFFSET_Pos);

}

/**
  * @brief  ADC calibrate enable
  */
void ADC_CalibrationEnable(void)
{
  MDU->ADC_CALIB |= MDU_ADCCALIB_CODE_COR_EN;
}

/**
  * @brief  ADC calibrate disable
  */
void ADC_CalibrationDisable(void)
{
  MDU->ADC_CALIB &= (uint32_t)~MDU_ADCCALIB_CODE_COR_EN;
}

#else
/**
  * @brief  Start ADC
  */
void ADC_Start(void)
{
  MDU->ADC_CTRL |= ((uint32_t)MDU_ADCCTRL_SEQ_STRT);
  __NOP();
  __NOP();
  MDU->ADC_CTRL |= ((uint32_t)MDU_ADCCTRL_RST);
}

/**
  * @brief  Clear ADC EOC.
  */
void ADC_ClearEOC(void)
{
  MDU->ADC_CTRL &= (uint32_t)~((uint32_t)MDU_ADCCTRL_RST);

  __NOP();
  __NOP();
  __NOP();
  __NOP();

  MDU->ADC_CTRL |= (uint32_t)MDU_ADCCTRL_RST;
}

/**
  * @brief  Set ADC delay after reset release.
  * @param  Delay the value is 0 to 0xF.
  */
void ADC_SetDelay(uint32_t Delay)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_RSTBDLY);
  temp |= (Delay << MDU_ADCCFG_RSTBDLY_Pos);

  MDU->ADC_CFG = temp;
}

/**
  * @brief  Set ADC channel source.
  * @param  Source the value is one of the following values:
  *         @arg @ref ADC_CHANNEL_EXTERNAL
  *         @arg @ref ADC_CHANNEL_INTERNAL
  */
void ADC_SetChannelSource(uint32_t Source)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_ICHSLCT);
  temp |= (Source << MDU_ADCCFG_ICHSLCT_Pos);

  MDU->ADC_CFG = temp;
}

/**
  * @brief  Set ADC conversion mode.
  * @param  Mode the value is one of the following values:
  *         @arg @ref ADC_CONVERT_SINGLECH_SINGLE
  *         @arg @ref ADC_CONVERT_SINGLECH_CONTINUOUS
  *         @arg @ref ADC_CONVERT_MULTCH_SINGLE
  */
void ADC_SetConversionMode(uint32_t Mode)
{
  uint32_t temp = MDU->ADC_CTRL;

  temp &= ~(MDU_ADCCTRL_CONV_MODE);
  temp |= (Mode << MDU_ADCCTRL_CONV_MODE_Pos);

  MDU->ADC_CTRL = temp;
}

/**
  * @brief  Set ADC trigger mode.
  * @param  Source the value is one of the following values:
  *         @arg @ref ADC_TRGSRC_SOFTWARE  
  *         @arg @ref ADC_TRGSRC_TIMA_CH4  
  *         @arg @ref ADC_TRGSRC_TIMA_TRGO2
  *         @arg @ref ADC_TRGSRC_TIMG_TRGO 
  *         @arg @ref ADC_TRGSRC_TIMB11    
  *         @arg @ref ADC_TRGSRC_TIMB12    
  *         @arg @ref ADC_TRGSRC_TIMB13    
  *         @arg @ref ADC_TRGSRC_TIMB14    
  *         @arg @ref ADC_TRGSRC_TIMB21    
  *         @arg @ref ADC_TRGSRC_TIMB22    
  *         @arg @ref ADC_TRGSRC_TIMB23    
  *         @arg @ref ADC_TRGSRC_TIMB24    
  * @param  Mode the value is one of the following values:
  *         @arg @ref ADC_TRIGGEREDGE_NONE   
  *         @arg @ref ADC_TRIGGEREDGE_RISING 
  *         @arg @ref ADC_TRIGGEREDGE_FALLING
  *         @arg @ref ADC_TRIGGEREDGE_BOTH   
  */
void ADC_SetTriggerMode(uint32_t Source, uint32_t Mode)
{
  uint32_t temp = MDU->ADC_CTRL;

  temp &= ~(MDU_ADCCTRL_TRGISRC|MDU_ADCCTRL_RISEEDGE|MDU_ADCCTRL_FALLEDGE);
  temp |= (Source << MDU_ADCCTRL_TRGISRC_Pos);
  temp |= (Mode << MDU_ADCCTRL_RISEEDGE_Pos);

  MDU->ADC_CTRL = temp;
}

/**
  * @brief  Set ADC group.
  * @param  Group the value is combined of the following values:
  *         @arg @ref ADC_GROUP_CH_0  
  *         @arg @ref ADC_GROUP_CH_1  
  *         @arg @ref ADC_GROUP_CH_2  
  *         @arg @ref ADC_GROUP_CH_3  
  *         @arg @ref ADC_GROUP_CH_4  
  *         @arg @ref ADC_GROUP_CH_5  
  *         @arg @ref ADC_GROUP_CH_6  
  *         @arg @ref ADC_GROUP_CH_7  
  *         @arg @ref ADC_GROUP_CH_8  
  *         @arg @ref ADC_GROUP_CH_9  
  *         @arg @ref ADC_GROUP_CH_10 
  *         @arg @ref ADC_GROUP_CH_11 
  *         @arg @ref ADC_GROUP_CH_12 
  *         @arg @ref ADC_GROUP_CH_13 
  *         @arg @ref ADC_GROUP_CH_14 
  *         @arg @ref ADC_GROUP_CH_15 
  * @param  ScanDir the value is one of the following values:
  *         @arg @ref ADC_CONVERT_INCREMENT   
  *         @arg @ref ADC_CONVERT_DECREMENT 
  *         @arg @ref ADC_TRIGGEREDGE_FALLING
  *         @arg @ref ADC_TRIGGEREDGE_BOTH   
  */
void ADC_SetGroup(uint32_t Group, uint32_t ScanDir)
{
  uint32_t temp = MDU->ADC_CTRL;

  temp &= ~(MDU_ADCCTRL_GCHIND | MDU_ADCCTRL_CH_MODE);
  temp |= (Group << MDU_ADCCTRL_GCHIND_Pos);
  temp |= (ScanDir << MDU_ADCCTRL_CH_MODE_Pos);

  MDU->ADC_CTRL = temp;
}
#endif /* XT32H0xxB */

#if defined(XT32H0xxAMPW)
/**
  * @brief  Clear ADC EOC.
  * @param Resolution Conversion resolution 
  */
void ADC_SetResolution(uint32_t Resolution)
{
  uint32_t temp = MDU->ADC_CFG;

  temp &= ~(MDU_ADCCFG_RESCFG);
  temp |= (Resolution << MDU_ADCCFG_RESCFG_Pos);

  MDU->ADC_CFG = temp;
}
#endif /* XT32H0xxAMPW */

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

