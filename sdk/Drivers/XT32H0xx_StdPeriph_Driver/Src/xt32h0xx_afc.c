/**
  ******************************************************************************
  * @file    xt32h0xx_afc.c
  * @author  Software Team
  * @date    29 November 2022
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_afc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */
/** @defgroup AFC AFC
  * @brief AFC driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup AFC_Exported_Functions AFC Exported Functions
  * @{
  */
/**
  * @brief  De-initialize AFC.
  */
void AFC_DeInit(void)
{
  SYSCFG->AFC_CTRL &= (uint32_t)(~(SYSCFG_AFCCTRL_AFCEN));
}

/** 
  * @brief  Initialize AFC.
  * @param  AFC_InitStruct pointer to a AFC_InitTypeDef structure 
  */
void AFC_Init(AFC_InitTypeDef* AFC_InitStruct)
{
  uint32_t tmp;
  tmp = SYSCFG->AFC_CTRL;
  tmp &= (uint32_t)(~(SYSCFG_AFCCTRL_RFCNT|SYSCFG_AFCCTRL_DIFFCNT|SYSCFG_AFCCTRL_CBCLKS));
  tmp |= (uint32_t)(AFC_InitStruct->CalibrationTime << SYSCFG_AFCCTRL_RFCNT_Pos 
                               | AFC_InitStruct->CalibrationReference << SYSCFG_AFCCTRL_DIFFCNT_Pos
                               | AFC_InitStruct->ClockSource);
  SYSCFG->AFC_CTRL = tmp;

  tmp = SYSCFG->AFC_CFG;
  tmp &= (uint32_t)(~(SYSCFG_AFCCFG_CBADJ | SYSCFG_AFCCFG_STDCNT));
  tmp |= (uint32_t)(AFC_InitStruct->InitialValue << SYSCFG_AFCCFG_CBADJ_Pos
                              | AFC_InitStruct->StandardCount << SYSCFG_AFCCFG_STDCNT_Pos);
  SYSCFG->AFC_CFG = tmp;

  tmp = SYSCFG->AFC_RES;
  tmp &= (uint32_t)(~(SYSCFG_AFCRES_RFDIV)); 
  tmp |= (uint32_t)(AFC_InitStruct->RefClkDiv << SYSCFG_AFCRES_RFDIV_Pos);
  SYSCFG->AFC_RES = tmp;

  tmp = SYSCFG->AFC_CTRL;
  tmp &= (uint32_t)(~(SYSCFG_AFCCTRL_AFCBYS));
  tmp |= (uint32_t)(SYSCFG_AFCCTRL_AEIE|SYSCFG_AFCCTRL_ANIE|SYSCFG_AFCCTRL_ALIE);
  SYSCFG->AFC_CTRL = tmp;
}

/**
  * @brief  Fills each AFC_InitStruct member with its default value.
  * @param  AFC_InitStruct: pointer to a AFC_InitTypeDef structure which will be initialized.
  */
void AFC_StructInit(AFC_InitTypeDef* AFC_InitStruct)
{
  AFC_InitStruct->ClockSource            = AFC_CLKSRC_16M;
  AFC_InitStruct->CalibrationTime        = 2000;
  AFC_InitStruct->CalibrationReference   = 2;
  AFC_InitStruct->StandardCount          = 2000;
  AFC_InitStruct->InitialValue           = 128;
  AFC_InitStruct->RefClkDiv              = 3;
}

/**
  * @brief  AFC start.
  */
void AFC_Start(void)
{
  if((SYSCFG->AFC_CTRL&SYSCFG_AFCCTRL_CBCLKS) ==  AFC_CLKSRC_16M)
  {
    ICG->RC16M_CTRL |= ICG_RC16M_CTRL_CALI;
  }
  else
  {
    AON->AON_CLK_CTRL |= AON_CLKCTRL_32K_CAL;
  }
  SYSCFG->AFC_CTRL |= (uint32_t)(SYSCFG_AFCCTRL_AFCEN);
}

/**
  * @brief  AFC stop.
  */
void AFC_Stop(void)
{
  uint32_t tmp;
  if((SYSCFG->AFC_CTRL&SYSCFG_AFCCTRL_CBCLKS) ==  AFC_CLKSRC_16M)
  {
    tmp = ICG->RC16M_CTRL;
    tmp &= ICG_RC16M_CTRL_CRES;
    tmp |= ((SYSCFG->AFC_RES & SYSCFG_AFCRES_ADJRES) << ICG_RC16M_CTRL_CRES_Pos);

    SYSCFG->AFC_CTRL &= (uint32_t)(~(SYSCFG_AFCCTRL_AFCEN));

    ICG->RC16M_CTRL &= (uint32_t)~ICG_RC16M_CTRL_CALI;
  }
  else 
  {
    tmp = AON->AON_CLK_CTRL;
    tmp &= (uint32_t)~(AON_CLKCTRL_32KRC_RESTUNE);
    tmp |= ((SYSCFG->AFC_RES & SYSCFG_AFCRES_ADJRES) << AON_CLKCTRL_32KRC_RESTUNE_Pos);

    SYSCFG->AFC_CTRL &= (uint32_t)(~(SYSCFG_AFCCTRL_AFCEN));
    
    AON->AON_CLK_CTRL &= (uint32_t)~AON_CLKCTRL_32K_CAL;
  }
}

/**
  * @brief  AFC get result.
  * @retval result
  */
uint32_t AFC_GetResult(void)
{
  return (uint32_t)(SYSCFG->AFC_RES & SYSCFG_AFCRES_ADJRES);
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

