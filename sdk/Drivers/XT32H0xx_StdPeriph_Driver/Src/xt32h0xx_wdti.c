/**
  ******************************************************************************
  * @file    xt32h0xx_wdti.c
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Independent watchdog (WDTI) peripheral:           
  *           + Counter configuration
  *           + WDTI activation
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
#include "xt32h0xx_wdti.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup WDTI WDTI
  * @brief WDTI driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup WDTI_Private_Constants WDTI Private Constants
  * @{
  */
/* ---------------------- WDTI restart code ----------------------------------*/
#define WDTI_RESTART_CODE    ((uint32_t)0x76)
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/


/** @defgroup WDTI_Exported_Functions WDTI Exported Functions
  * @{
  */
/** @defgroup WDTI_Exported_Functions_Group1 Counter configuration functions
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
  * @param  WDTI_ResponseMode
  */
void WDTI_SetResponseMode(uint32_t WDTI_ResponseMode)
{
  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_WDTI_RMOD(WDTI_ResponseMode));
  
  tempr = WDTI->CR;
  tempr &= (uint32_t)~((uint32_t)WDT_CR_RMOD);
  tempr |= (uint32_t)WDTI_ResponseMode;

  WDTI->CR = tempr;
}

/**
  * @brief  Set WDTI reset pulse width.
  * @param  WDTI_ResetPulseWidth: 
  */
void WDTI_SetResetPulseWidth(uint32_t WDTI_ResetPulseWidth)
{
  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_WDTI_RPL(WDTI_ResetPulseWidth));
  
  tempr = WDTI->CR;
  tempr &= (uint32_t)~((uint32_t)WDT_CR_RPL);
  tempr |= (uint32_t)WDTI_ResetPulseWidth;

  WDTI->CR = tempr;
}
#if 0
/**
  * @brief  Set WDTI initial range.
  * @param  WDTI_Range: 
  */
void WDTI_SetInitialRange(uint32_t WDTI_Range)
{
  uint32_t tempr;
  
  tempr = WDTI->TORR;
  tempr &= (uint32_t)~((uint32_t)WDT_TORR_TOPINIT);
  tempr |= (uint32_t)(WDTI_Range << WDT_TORR_TOPINIT_Pos);

  WDTI->TORR = tempr;
}
#endif
/**
  * @brief  Set WDTI restart range.
  * @param  WDTI_Range: 
  */
void WDTI_SetRestartRange(uint32_t WDTI_Range)
{
  uint32_t tempr;
  
  tempr = WDTI->TORR;
  tempr &= (uint32_t)~((uint32_t)WDT_TORR_TOP);
  tempr |= (uint32_t)(WDTI_Range << WDT_TORR_TOP_Pos);

  WDTI->TORR = tempr;
}

/**
  * @}
  */

/** @defgroup WDTI_Exported_Functions_Group2 WDTI activation function
 *  @brief   WDTI activation function 
 *
@verbatim   
 ==============================================================================
                          ##### WDTI activation function #####
 ==============================================================================  

@endverbatim
  * @{
  */

/**
  * @brief  Enables WDTI
  */
void WDTI_Enable(void)
{
  WDTI->CR |= (uint32_t)WDT_CR_EN;
}

/**
  * @brief  Disables WDTI
  */
void WDTI_Disable(void)
{
  WDTI->CR &= (uint32_t)~((uint32_t)WDT_CR_EN);
}

/**
  * @brief  Restart WDTI
  */
void WDTI_Restart(void)
{
  WDTI->CRR = (uint32_t)WDTI_RESTART_CODE;
}

/**
  * @brief  Get WDTI counter value
  * @retval counter value
  */
uint32_t WDTI_GetCurrentValue(void)
{
  return (uint32_t)WDTI->CCVR;
}

/**
  * @}
  */

/** @defgroup WDTI_Exported_Functions_Group3 Interrupt management function 
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
  * @brief  Clear WDTI flag.
  * @retval flag.
  */
uint32_t WDTI_ClearIT(void)
{
  return (uint32_t)WDTI->EOI;
}

/**
  * @brief  Checks whether WDTI flag is set or not.
  * @retval flag.
  */
uint32_t WDTI_GetITFlag(void)
{
  return (uint32_t)WDTI->STAT;
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

