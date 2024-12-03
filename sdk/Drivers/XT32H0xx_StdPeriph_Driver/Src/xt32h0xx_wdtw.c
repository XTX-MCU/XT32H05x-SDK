/**
  ******************************************************************************
  * @file    xt32h0xx_wdtw.c
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Independent watchdog (WDTW) peripheral:           
  *           + Counter configuration
  *           + WDTW activation
  *           + Interrupt management
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
#include "xt32h0xx_wdtw.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup WDTW WDTW
  * @brief WDTW driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup WDTW_Private_Constants WDTW Private Constants
  * @{
  */ 
/* ---------------------- WDTW restart code ----------------------------------*/
#define WDTW_RESTART_CODE    ((uint32_t)0x76)
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup WDTW_Exported_Functions WDTW Exported Functions
  * @{
  */

/** @defgroup WDTW_Exported_Functions_Group1 Counter configuration functions
 *  @brief   Counter configuration functions
 *
@verbatim   
  ==============================================================================
            ##### Counter configuration functions #####
  ==============================================================================  

@endverbatim
  * @{
  */

/**
  * @brief Set response mode.
  * @param  WDTW_ResponseMode
  */
void WDTW_SetResponseMode(uint32_t WDTW_ResponseMode)
{
  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_WDTW_RMOD(WDTW_ResponseMode));
  
  tempr = WDTW->CR;
  tempr &= (uint32_t)~((uint32_t)WDT_CR_RMOD);
  tempr |= (uint32_t)WDTW_ResponseMode;

  WDTW->CR = tempr;
}

/**
  * @brief  Set WDTW reset pulse width.
  * @param  WDTW_ResetPulseWidth: 
  */
void WDTW_SetResetPulseWidth(uint32_t WDTW_ResetPulseWidth)
{
  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_WDTW_RPL(WDTW_ResetPulseWidth));
  
  tempr = WDTW->CR;
  tempr &= (uint32_t)~((uint32_t)WDT_CR_RPL);
  tempr |= (uint32_t)WDTW_ResetPulseWidth;

  WDTW->CR = tempr;
}
#if 0
/**
  * @brief  Set WDTW initial range.
  * @param  WDTW_Range: 
  */
void WDTW_SetInitialRange(uint32_t WDTW_Range)
{
  uint32_t tempr;
  
  tempr = WDTW->TORR;
  tempr &= (uint32_t)~((uint32_t)WDT_TORR_TOPINIT);
  tempr |= (uint32_t)(WDTW_Range << WDT_TORR_TOPINIT_Pos);

  WDTW->TORR = tempr;
}
#endif
/**
  * @brief  Set WDTW restart range.
  * @param  WDTW_Range: 
  */
void WDTW_SetRestartRange(uint32_t WDTW_Range)
{
  uint32_t tempr;
  
  tempr = WDTW->TORR;
  tempr &= (uint32_t)~((uint32_t)WDT_TORR_TOP);
  tempr |= (uint32_t)(WDTW_Range << WDT_TORR_TOP_Pos);

  WDTW->TORR = tempr;
}

/**
  * @}
  */

/** @defgroup WDTW_Exported_Functions_Group2 WDTW activation function
 *  @brief   WDTW activation function 
 *
@verbatim   
 ==============================================================================
                          ##### WDTW activation function #####
 ==============================================================================  

@endverbatim
  * @{
  */

/**
  * @brief  Enables WDTW
  */
void WDTW_Enable(void)
{
  WDTW->CR |= (uint32_t)WDT_CR_EN;
}

/**
  * @brief  Disables WDTW
  */
void WDTW_Disable(void)
{
  WDTW->CR &= (uint32_t)~((uint32_t)WDT_CR_EN);
}

/**
  * @brief  Restart WDTW
  */
void WDTW_Restart(void)
{
  WDTW->CRR = (uint32_t)WDTW_RESTART_CODE;
}

/**
  * @brief  Get WDTW counter value
  * @retval counter value
  */
uint32_t WDTW_GetCurrentValue(void)
{
  return (uint32_t)WDTW->CCVR;
}

/**
  * @}
  */

/** @defgroup WDTW_Exported_Functions_Group3 Interrupt management function 
 *  @brief  Interrupt management function  
 *
@verbatim   
 ===============================================================================
                      ##### Interrupt management function ##### 
 ===============================================================================  

@endverbatim
  * @{
  */
/**
  * @brief  Clear WDTW flag.
  * @retval flag.
  */
uint32_t WDTW_ClearIT(void)
{
  return (uint32_t)WDTW->EOI;
}

/**
  * @brief  Checks whether WDTW flag is set or not.
  * @retval flag.
  */
uint32_t WDTW_GetITFlag(void)
{
  return (uint32_t)WDTW->STAT;
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

/**
  * @}
  */

