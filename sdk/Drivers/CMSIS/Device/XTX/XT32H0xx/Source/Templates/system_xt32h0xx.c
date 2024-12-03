/**
  ******************************************************************************
  * @file    system_xt32h0xx.c
  * @author  Software Team
  * @brief   CMSIS Cortex-M0+ Device Peripheral Access Layer System Source File
  *
  *   This file provides two functions and one global variable to be called from
  *   user application:
  *      - SystemInit(): This function is called at startup just after reset and
  *                      before branch to main program. This call is made inside
  *                      the "startup_xt32h0xxb.s" file.
  *
  *      - SystemCoreClock variable: Contains the core clock (HCLK), it can be used
  *                                  by the user application to setup the SysTick
  *                                  timer or configure other parameters.
  *
  *      - SystemCoreClockUpdate(): Updates the variable SystemCoreClock and must
  *                                 be called whenever the core clock is changed
  *                                 during program execution.
  *
  *   After each device reset the HSI (8 MHz then 16 MHz) is used as system clock source.
  *   Then SystemInit() function is called, in "startup_xt32h0xxb.s" file, to
  *   configure the system clock before to branch to main program.
  *
  *   This file configures the system clock as follows:
  *=============================================================================
  *-----------------------------------------------------------------------------
  *        System Clock source                    | HSI
  *-----------------------------------------------------------------------------
  *        SYSCLK(Hz)                             | 16000000
  *-----------------------------------------------------------------------------
  *        HCLK(Hz)                               | 16000000
  *-----------------------------------------------------------------------------
  *=============================================================================
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup xt32h0xx_system
  * @{
  */

/** @addtogroup XT32H05x_System_Private_Includes
  * @{
  */
#include "xt32h0xx.h"


#if !defined  (HSE_VALUE)
#define HSE_VALUE    48000000U    /*!< Value of the External oscillator in Hz */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE  16000000U   /*!< Value of the Internal oscillator in Hz*/
#endif /* HSI_VALUE */

#if !defined  (LSI_VALUE)
 #define LSI_VALUE   32000U      /*!< Value of LSI in Hz*/
#endif /* LSI_VALUE */

#if !defined  (LSE_VALUE)
  #define LSE_VALUE  32768U      /*!< Value of LSE in Hz*/
#endif /* LSE_VALUE */

#define  SYSTEM_CLOCK    (HSI_VALUE)
/**
  * @}
  */

/** @addtogroup XT32H05x_System_Private_TypesDefinitions
  * @{
  */
uint32_t SystemCoreClock = SYSTEM_CLOCK;  /* System Core Clock Frequency */
/**
  * @}
  */

extern const VECTOR_TABLE_Type __VECTOR_TABLE[48];

/** @addtogroup XT32H05x_System_Private_Functions
  * @{
  */
void SystemCoreClockUpdate (void)
{
  uint32_t tmp;
  uint32_t pllvco;
  uint32_t pllr;
  uint32_t pllsource;
  uint32_t pllm;
  uint32_t hsidiv;

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (__HAL_RCC_GET_SYSCLK_SOURCE())
  {
    case RCC_SYSCLKSOURCE_HSE:  /* HSE used as system clock */
      SystemCoreClock = HSE_VALUE;
      break;

    case RCC_SYSCLKSOURCE_LS:  /* LSI used as system clock */
      SystemCoreClock = LSI_VALUE;
      break;

    case RCC_SYSCLKSOURCE_PLL:  /* PLL used as system clock */
      {
      pllsource = __HAL_RCC_GET_PLL_OSCSOURCE(); 
      pllm = (__HAL_RCC_PLL_GET_PLLM_VALUE());
      switch (pllsource)
      {
        case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
          pllvco = (HSE_VALUE / pllm);
          break;

        case RCC_PLLSOURCE_HSI:  /* HSI used as PLL clock source */
        default:
          pllvco = (HSI_VALUE / pllm);
          break;
      }
      pllvco = pllvco * (__HAL_RCC_PLL_GET_PLLN_VALUE());
      pllr = (__HAL_RCC_PLL_GET_PLLR_VALUE());
      SystemCoreClock = pllvco/pllr;
      break;
      }
    case RCC_SYSCLKSOURCE_HSI:  /* HSI used as system clock */
    default:                /* HSI used as system clock */
		  SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK clock frequency --------------------------------------------*/
  /* Get HCLK prescaler */
	hsidiv = __HAL_RCC_GET_HCLK_DIV();
  /* HCLK clock frequency */
  SystemCoreClock = (SystemCoreClock / hsidiv);
}

/*----------------------------------------------------------------------------
  System initialization function
 *----------------------------------------------------------------------------*/
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
void SystemDelay(void) __attribute__((optnone))
{
	int i = 0; 
	do {
    __NOP();
    i++;
  } while(i<640000);
}
#else
#pragma push	
#pragma O0	
void SystemDelay(void)
{
	int i = 0; 
	do {
    __NOP();
    i++;
  } while(i<640000);
}
#pragma pop	
#endif

void SystemInit (void)
{
  SystemDelay();
#if defined (__VTOR_PRESENT) && (__VTOR_PRESENT == 1U)
  SCB->VTOR = (uint32_t) &(__VECTOR_TABLE);
#endif

  SystemCoreClock = SYSTEM_CLOCK;
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

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
