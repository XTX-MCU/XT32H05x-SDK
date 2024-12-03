/**
  ******************************************************************************
  * @file    xt32h0xx_hal_ictl.c
  * @author  Software Team
  * @brief   ICTL HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the General Purpose Input/Output (ICTL) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup ICTL
  * @{
  */

#ifdef HAL_ICTL_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup ICTL_Private_Macros ICTL Private Macros
  * @{
  */
#define IS_ICTL_LINE(__ICTL_LINE__)     ((((__ICTL_LINE__) & ~(ICTL_PROPERTY_MASK | ICTL_REG_MASK | ICTL_PIN_MASK)) == 0x00u) && \
                                        ((((__ICTL_LINE__) & ICTL_PROPERTY_MASK) == ICTL_DIRECT)   || \
                                         (((__ICTL_LINE__) & ICTL_PROPERTY_MASK) == ICTL_CONFIG)   || \
                                         (((__ICTL_LINE__) & ICTL_PROPERTY_MASK) == ICTL_GPIO))    )
/**
  * @}
  */
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup ICTL_Exported_Functions
  * @{
  */

/** @addtogroup ICTL_Exported_Functions_Group1
 *  @brief    Configuration functions
 *
@verbatim
 ===============================================================================
              ##### Configuration functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Set configuration of a dedicated Ictl line.
  * @param  hictl Ictl handle.
  * @param  pIctlConfig Pointer on ICTL configuration to be set.
  * @retval HAL Status.
  */
HAL_StatusTypeDef HAL_ICTL_SetConfigLine(ICTL_HandleTypeDef *hictl, ICTL_ConfigTypeDef *pIctlConfig)
{
  uint32_t reg = (hictl->Line & ICTL_REG_MASK);
  uint32_t idx = (hictl->Line & ICTL_PIN_MASK);

  if(reg == ICTL_IRQ1)
  {
    MODIFY_REG(ICTL->IRQINTMASKL, (0x1UL << idx), pIctlConfig->IsMasked);
  }
  else if(reg == ICTL_IRQ2)
  {
    MODIFY_REG(ICTL->IRQINTMASKH, (0x1UL << idx), pIctlConfig->IsMasked);
  }
  else if(reg == ICTL_FIQ)
  {
    MODIFY_REG(ICTL->FIQINTMASK, (0x1UL << idx), pIctlConfig->IsMasked);
  }

  return HAL_OK;
}


/**
  * @brief  Get configuration of a dedicated Ictl line.
  * @param  hictl Ictl handle.
  * @param  pIctlConfig Pointer on structure to store Ictl configuration.
  * @retval HAL Status.
  */
HAL_StatusTypeDef HAL_ICTL_GetConfigLine(ICTL_HandleTypeDef *hictl, ICTL_ConfigTypeDef *pIctlConfig)
{
  uint32_t reg = (hictl->Line & ICTL_REG_MASK);
  uint32_t idx = (hictl->Line & ICTL_PIN_MASK);

  if(reg == ICTL_IRQ1)
  {
    pIctlConfig->IsMasked = READ_BIT(ICTL->IRQINTMASKL, (0x1UL << idx));
  }
  else if(reg == ICTL_IRQ2)
  {
    pIctlConfig->IsMasked = READ_BIT(ICTL->IRQINTMASKH, (0x1UL << idx));
  }
  else if(reg == ICTL_FIQ)
  {
    pIctlConfig->IsMasked = READ_BIT(ICTL->FIQINTMASK, (0x1UL << idx));
  }

  return HAL_OK;
}


/**
  * @brief  Clear whole configuration of a dedicated Ictl line.
  * @param  hictl Ictl handle.
  * @retval HAL Status.
  */
HAL_StatusTypeDef HAL_ICTL_ClearConfigLine(ICTL_HandleTypeDef *hictl)
{
  uint32_t reg = (hictl->Line & ICTL_REG_MASK);
  uint32_t idx = (hictl->Line & ICTL_PIN_MASK);

  if(reg == ICTL_IRQ1)
  {
    CLEAR_BIT(ICTL->IRQINTMASKL, (0x1UL << idx));
  }
  else if(reg == ICTL_IRQ2)
  {
    CLEAR_BIT(ICTL->IRQINTMASKH, (0x1UL << idx));
  }
  else if(reg == ICTL_FIQ)
  {
    CLEAR_BIT(ICTL->FIQINTMASK, (0x1UL << idx));
  }

  return HAL_OK;
}


/**
  * @brief  Register callback for a dedicaated Ictl line.
  * @param  hictl Ictl handle.
  * @param  pPendingCbfn function pointer to be stored as callback.
  * @retval HAL Status.
  */
HAL_StatusTypeDef HAL_ICTL_RegisterCallback(ICTL_HandleTypeDef *hictl, void (*pPendingCbfn)(void))
{
  HAL_StatusTypeDef status = HAL_OK;

  hictl->ISRCallback = pPendingCbfn;

  return status;
}


/**
  * @brief  Store line number as handle private field.
  * @param  hictl Ictl handle.
  * @param  IctlLine Ictl line number.
  *         This parameter can be from 0 to 0xFFFFFFFF.
  * @retval HAL Status.
  */
HAL_StatusTypeDef HAL_ICTL_GetHandle(ICTL_HandleTypeDef *hictl, uint32_t IctlLine)
{
  /* Check the parameters */
  assert_param(IS_ICTL_LINE(IctlLine));

  /* Check null pointer */
  if (hictl == NULL)
  {
    return HAL_ERROR;
  }
  else
  {
    /* Store line number as handle private field */
    hictl->Line = IctlLine;

    return HAL_OK;
  }
}


/**
  * @}
  */

/** @addtogroup ICTL_Exported_Functions_Group2
 *  @brief ICTL IO functions.
 *
@verbatim
 ===============================================================================
                       ##### IO operation functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Handle ICTL interrupt request.
  * @param  hictl Ictl handle.
  */
void HAL_ICTL_IRQHandler(ICTL_HandleTypeDef *hictl)
{
  hictl->ISRCallback();
}


/**
  * @brief  Get interrupt pending bit of a dedicated line.
  * @param  hictl Ictl handle.
  * @retval 1 if interrupt is pending else 0.
  */
uint32_t HAL_ICTL_GetPending(ICTL_HandleTypeDef *hictl)
{
  uint32_t reg = (hictl->Line & ICTL_REG_MASK);
  uint32_t idx = (hictl->Line & ICTL_PIN_MASK);

  if(reg == ICTL_IRQ1)
  {
    return (uint32_t)((READ_BIT(ICTL->IRQFINALSTATUSL, (0x1UL << idx))) ? 1UL : 0UL);
  }
  else if(reg == ICTL_IRQ2)
  {
    return (uint32_t)((READ_BIT(ICTL->IRQFINALSTATUSH, (0x1UL << idx))) ? 1UL : 0UL);
  }
  else if(reg == ICTL_FIQ)
  {
    return (uint32_t)((READ_BIT(ICTL->FIQFINALSTATUS, (0x1UL << idx))) ? 1UL : 0UL);
  }
	else
	{
		return 0;
	}
}


/**
  * @brief  Clear interrupt pending bit of a dedicated line.
  * @param  hictl Ictl handle.
  */
void HAL_ICTL_ClearPending(ICTL_HandleTypeDef *hictl)
{
}


/**
  * @brief  Generate a software interrupt for a dedicated line.
  * @param  hictl Ictl handle.
  */
void HAL_ICTL_ActiveSWI(ICTL_HandleTypeDef *hictl)
{
  uint32_t reg = (hictl->Line & ICTL_REG_MASK);
  uint32_t idx = (hictl->Line & ICTL_PIN_MASK);

  if(reg == ICTL_IRQ1)
  {
    SET_BIT(ICTL->IRQINTFORCEL, (0x1UL << idx));
  }
  else if(reg == ICTL_IRQ2)
  {
    SET_BIT(ICTL->IRQINTFORCEH, (0x1UL << idx));
  }
  else if(reg == ICTL_FIQ)
  {
    SET_BIT(ICTL->FIQINTFORCE, (0x1UL << idx));
  }
}

/**
  * @brief  Clear a software interrupt for a dedicated line.
  * @param  hictl Ictl handle.
  */
void HAL_ICTL_ClearSWI(ICTL_HandleTypeDef *hictl)
{
  uint32_t reg = (hictl->Line & ICTL_REG_MASK);
  uint32_t idx = (hictl->Line & ICTL_PIN_MASK);

  if(reg == ICTL_IRQ1)
  {
    CLEAR_BIT(ICTL->IRQINTFORCEL, (0x1UL << idx));
  }
  else if(reg == ICTL_IRQ2)
  {
    CLEAR_BIT(ICTL->IRQINTFORCEH, (0x1UL << idx));
  }
  else if(reg == ICTL_FIQ)
  {
    CLEAR_BIT(ICTL->FIQINTFORCE, (0x1UL << idx));
  }
}


/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_ICTL_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
