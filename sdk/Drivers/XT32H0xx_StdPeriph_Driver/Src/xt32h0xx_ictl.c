/**
  ******************************************************************************
  * @file    xt32h0xx_ictl.c
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the ICTL peripheral:
  *           + Initialization and Configuration
  *           + Interrupts and flags management
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
#include "xt32h0xx_ictl.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup ICTL ICTL
  * @brief ICTL driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup ICTL_Exported_Functions ICTL Exported Functions
  * @{
  */

/** @defgroup ICTL_Exported_Functions_Group1 Initialization and Configuration functions
 *  @brief   Initialization and Configuration functions 
 *
  * @{
  */

/**
  * @brief  Deinitializes the ICTL peripheral registers to their default reset 
  *         values.
  */
void ICTL_DeInit(void)
{
  ICTL->IRQINTENL = 0;
  ICTL->IRQINTENH = 0;
  ICTL->IRQINTMASKL = 0;
  ICTL->IRQINTMASKH = 0;
  ICTL->IRQINTFORCEL = 0;
  ICTL->IRQINTFORCEH = 0;
}

/**
  * @brief  Enable interrupt 
  *        
  * @param  ICTL_Lines
  * @param  ICTL_Range
  */
void ICTL_Enable(uint32_t ICTL_Lines, uint32_t ICTL_Range)
{
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    ICTL->IRQINTENL |= (uint32_t)ICTL_Lines;
  }
  else
  {
    ICTL->IRQINTENH |= (uint32_t)ICTL_Lines;
  }
}

/**
  * @brief  Disable interrupt 
  *        
  * @param  ICTL_Lines
  * @param  ICTL_Range
  */
void ICTL_Disable(uint32_t ICTL_Lines, uint32_t ICTL_Range)
{
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    ICTL->IRQINTENL &= (uint32_t)~((uint32_t)ICTL_Lines);
  }
  else
  {
    ICTL->IRQINTENH &= (uint32_t)~((uint32_t)ICTL_Lines);
  }
}

/**
  * @brief  Mask interrupt 
  *        
  * @param  ICTL_Lines
  * @param  ICTL_Range
  */
void ICTL_Mask(uint32_t ICTL_Lines, uint32_t ICTL_Range)
{
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    ICTL->IRQINTMASKL |= (uint32_t)ICTL_Lines;
  }
  else
  {
    ICTL->IRQINTMASKH |= (uint32_t)ICTL_Lines;
  }
}

/**
  * @brief  Unmask interrupt 
  *        
  * @param  ICTL_Lines
  * @param  ICTL_Range
  */
void ICTL_Unmask(uint32_t ICTL_Lines, uint32_t ICTL_Range)
{
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    ICTL->IRQINTMASKL &= (uint32_t)~((uint32_t)ICTL_Lines);
  }
  else
  {
    ICTL->IRQINTMASKH &= (uint32_t)~((uint32_t)ICTL_Lines);
  }
}

/**
  * @brief  Force interrupt active
  *        
  * @param  ICTL_Lines
  * @param  ICTL_Range
  */
void ICTL_ForceActive(uint32_t ICTL_Lines, uint32_t ICTL_Range)
{
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    ICTL->IRQINTFORCEL |= (uint32_t)ICTL_Lines;
  }
  else
  {
    ICTL->IRQINTFORCEH |= (uint32_t)ICTL_Lines;
  }
}

/**
  * @brief  Force interrupt inactive
  *        
  * @param  ICTL_Lines
  * @param  ICTL_Range
  */
void ICTL_ForceInactive(uint32_t ICTL_Lines, uint32_t ICTL_Range)
{
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    ICTL->IRQINTFORCEL &= (uint32_t)~((uint32_t)ICTL_Lines);
  }
  else
  {
    ICTL->IRQINTFORCEH &= (uint32_t)~((uint32_t)ICTL_Lines);
  }
}

/**
  * @}
  */

/** @defgroup ICTL_Exported_Functions_Group2 Interrupts and flags management functions
 *  @brief    Interrupts and flags management functions 
 *
 * @{
 */

/**
  * @brief  Checks whether the specified ICTL line raw flag is set or not.
  * @param  ICTL_Line specifies the ICTL line flag to check.
  * @param  ICTL_Range interrupt range 
  *         This parameter can be a value of the following values:
  *         @arg @ref ICTL_LINE_RANGE_LOW
  *         @arg @ref ICTL_LINE_RANGE_HIGH
  * @retval The new state of ICTL_Line (SET or RESET).
  */
FlagStatus ICTL_GetRawStatus(uint32_t ICTL_Line, uint32_t ICTL_Range)
{
  FlagStatus bitstatus = RESET;
  
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    if ((ICTL->IRQRAWSTATUSL & ICTL_Line) != (uint32_t)RESET)
    {
      bitstatus = SET;
    }
    else
    {
      bitstatus = RESET;
    }
  }
  else
  {
    if ((ICTL->IRQRAWSTATUSH & ICTL_Line) != (uint32_t)RESET)
    {
      bitstatus = SET;
    }
    else
    {
      bitstatus = RESET;
    }
  }
  
  return bitstatus;
}

/**
  * @brief  Checks whether the specified ICTL line flag is set or not.
  * @param  ICTL_Line: specifies the ICTL line flag to check.
  * @param  ICTL_Range interrupt range 
  *         This parameter can be a value of the following values:
  *         @arg @ref ICTL_LINE_RANGE_LOW
  *         @arg @ref ICTL_LINE_RANGE_HIGH
  * @retval The new state of ICTL_Line (SET or RESET).
  */
FlagStatus ICTL_GetStatus(uint32_t ICTL_Line, uint32_t ICTL_Range)
{
  FlagStatus bitstatus = RESET;
  
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    if ((ICTL->IRQSTATUSL & ICTL_Line) != (uint32_t)RESET)
    {
      bitstatus = SET;
    }
    else
    {
      bitstatus = RESET;
    }
  }
  else
  {
    if ((ICTL->IRQSTATUSH & ICTL_Line) != (uint32_t)RESET)
    {
      bitstatus = SET;
    }
    else
    {
      bitstatus = RESET;
    }
  }
  
  return bitstatus;
}

/**
  * @brief  Checks whether the specified ICTL line masked flag is set or not.
  * @param  ICTL_Line: specifies the ICTL line flag to check.
  * @param  ICTL_Range interrupt range 
  *         This parameter can be a value of the following values:
  *         @arg @ref ICTL_LINE_RANGE_LOW
  *         @arg @ref ICTL_LINE_RANGE_HIGH
  * @retval The new state of ICTL_Line (SET or RESET).
  */
FlagStatus ICTL_GetMaskStatus(uint32_t ICTL_Line, uint32_t ICTL_Range)
{
  FlagStatus bitstatus = RESET;
  
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    if ((ICTL->IRQMASKSTATUSL & ICTL_Line) != (uint32_t)RESET)
    {
      bitstatus = SET;
    }
    else
    {
      bitstatus = RESET;
    }
  }
  else
  {
    if ((ICTL->IRQMASKSTATUSH & ICTL_Line) != (uint32_t)RESET)
    {
      bitstatus = SET;
    }
    else
    {
      bitstatus = RESET;
    }
  }
  
  return bitstatus;
}

/**
  * @brief  Checks whether the specified ICTL line final (including force) flag is set or not.
  * @param  ICTL_Line: specifies the ICTL line flag to check.
  * @param  ICTL_Range interrupt range 
  *         This parameter can be a value of the following values:
  *         @arg @ref ICTL_LINE_RANGE_LOW
  *         @arg @ref ICTL_LINE_RANGE_HIGH
  * @retval The new state of ICTL_Line (SET or RESET).
  */
FlagStatus ICTL_GetFinalStatus(uint32_t ICTL_Line, uint32_t ICTL_Range)
{
  FlagStatus bitstatus = RESET;
  
  if(ICTL_Range == ICTL_LINE_RANGE_LOW)
  {
    if ((ICTL->IRQFINALSTATUSL & ICTL_Line) != (uint32_t)RESET)
    {
      bitstatus = SET;
    }
    else
    {
      bitstatus = RESET;
    }
  }
  else
  {
    if ((ICTL->IRQFINALSTATUSH & ICTL_Line) != (uint32_t)RESET)
    {
      bitstatus = SET;
    }
    else
    {
      bitstatus = RESET;
    }
  }
  
  return bitstatus;
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

