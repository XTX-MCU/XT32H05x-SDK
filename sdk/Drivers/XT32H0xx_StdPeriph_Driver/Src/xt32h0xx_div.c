/**
  ******************************************************************************
  * @file    xt32h0xx_div.c
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
#include "xt32h0xx_div.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */
/** @defgroup DIV DIV
  * @brief DIV driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup DIV_Private_Functions DIV Private Functions
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup DIV_Exported_Functions DIV Exported Functions
  * @{
  */
/**
  * @brief  DIV enable.
  * @param  Cmd
  */
void DIV_Cmd(uint32_t Cmd)
{
  if(Cmd != DISABLE)
  {
    SYSCFG->SYS_CFG |= SYSCFG_SYS_CFG_HDIV_EN;
  }
  else
  {
    SYSCFG->SYS_CFG &= (uint32_t)(~(SYSCFG_SYS_CFG_HDIV_EN));
  }
}

/**
  * @brief  Compute div A / B = Q  with R
  * @param  divA A
  * @param  divB B
  * @param  pdivQ a pointer to Q
  * @param  pdivR a pointer to R
  */
void DIV_Calc(uint32_t divA, uint32_t divB, uint32_t* pdivQ, uint32_t* pdivR)
{
  HDIV->HDIV_A = divA;
  HDIV->HDIV_B = divB;
	
  __NOP();
  __NOP();

  *pdivQ = HDIV->HDIV_Q;
  *pdivR = HDIV->HDIV_R;
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

