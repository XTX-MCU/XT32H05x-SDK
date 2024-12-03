/**
  ******************************************************************************
  * @file    xt32h0xx_rcc.c
  * @author  Software Team
  * @version V1.5.1
  * @date    13-October-2021
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Reset and clock control (RCC) peripheral:
  *           + Internal/external clocks, PLL, CSS and MCO configuration
  *           + System, AHB and APB busses clocks configuration
  *           + Peripheral clocks configuration
  *           + Interrupts and flags management
  *
 @verbatim

 ===============================================================================
                        ##### RCC specific features #####
 ===============================================================================
    [..] After reset the device is running from HSI (8 MHz) with Flash 0 WS, 
         all peripherals are off except internal SRAM, Flash and SWD.
         (#) There is no prescaler on High speed (AHB) and Low speed (APB) busses;
             all peripherals mapped on these busses are running at HSI speed.
         (#) The clock for all peripherals is switched off, except the SRAM and FLASH.
         (#) All GPIOs are in input floating state, except the SWD pins which
             are assigned to be used for debug purpose.
    [..] Once the device started from reset, the user application has to:
         (#) Configure the clock source to be used to drive the System clock
             (if the application needs higher frequency/performance)
         (#) Configure the System clock frequency and Flash settings
         (#) Configure the AHB and APB busses prescalers
         (#) Enable the clock for the peripheral(s) to be used
         (#) Configure the clock source(s) for peripherals which clocks are not
             derived from the System clock (ADC, CEC, I2C, USART, RTC and IWDG)

 @endverbatim
  
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup RCC RCC
  * @brief RCC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup RCC_Exported_Functions RCC Exported Functions
  * @{
  */

/** @defgroup RCC_Exported_Functions_Group1 Internal and external clocks, PLL configuration functions
  *  @brief   Internal and external clocks, PLL configuration functions 
  *
  * @{
  */

/**
  * @brief  Power down all clock source.
  */
void RCC_DeInit(void)
{
  /* power down */
  ICG->CLK_CFG |= (RCC_HSI_OFF | RCC_HSE_OFF | RCC_PLL_OFF);
  AON->AON_CLK_CTRL |= (RCC_LSE_OFF | RCC_LSI_OFF);
}

/**
  * @brief  Configures the Internal High Speed oscillator (HSI).
  * @param  RCC_HSI: specifies the new state of the HSI.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_HSI_OFF turn OFF the HSI.
  *            @arg @ref RCC_HSI_ON turn ON the HSI.
  */
void RCC_HSIConfig(uint32_t RCC_HSI)
{
  uint32_t tempr;

  assert_param(IS_RCC_HSI(RCC_HSI));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)ICG_CLK_CTL_HSRC);
  tempr |= (uint32_t)(RCC_HSI); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Configures the External High Speed oscillator (HSE).
  * @param  RCC_HSE: specifies the new state of the HSE.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_HSE_OFF turn OFF the HSE.
  *            @arg @ref RCC_HSE_ON turn ON the HSE.
  */
void RCC_HSEConfig(uint32_t RCC_HSE)
{
  uint32_t tempr;

  assert_param(IS_RCC_HSI(RCC_HSE));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT));
  tempr |= (uint32_t)(RCC_HSE); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Configures the PLL .
  * @param  RCC_PLL: specifies the new state of the PLL.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_PLL_OFF turn OFF the HSE.
  *            @arg @ref RCC_PLL_ON turn ON the HSE.
  * @param  RCC_PLLSource PLL clock source  
  * @param  RCC_PLLM PLL divider  
  * @param  RCC_PLLN PLL divider 
  * @param  RCC_PLLR PLL divider  
  */
void RCC_PLLConfig(uint32_t RCC_PLL,
                   uint32_t RCC_PLLSource,
                   uint32_t RCC_PLLM, uint32_t RCC_PLLN, uint32_t RCC_PLLR)
{
  uint32_t tempr;

  assert_param(IS_RCC_PLL(RCC_PLL));
  assert_param(IS_RCC_PLL_SOURCE(RCC_PLLSource));
  assert_param(IS_RCC_PLLM(RCC_PLLM));
  assert_param(IS_RCC_PLLN(RCC_PLLN));
  assert_param(IS_RCC_PLLR(RCC_PLLR));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)ICG_CLK_CTL_PLL);
  tempr |= (uint32_t)(RCC_PLL); 
  ICG->CLK_CFG = tempr;

  tempr = ICG->PLL_LFCFG_CTRL;
  tempr &= (uint32_t)~((uint32_t)ICG_PLL_CLKSRC);
  tempr |= (uint32_t)(RCC_PLLSource); 
  ICG->PLL_LFCFG_CTRL = tempr;

  tempr = ICG->PLL_DIV;
  tempr &= (uint32_t)~((uint32_t)(ICG_PLL_PREDIV | ICG_PLL_FBDIV | ICG_PLL_POSTDIV));
  tempr |= (uint32_t)(RCC_PLLM | RCC_PLLN | RCC_PLLR); 
  ICG->PLL_DIV = tempr;

}

/**
  * @brief  Get Pll clock.
  * @retval clock
  */
uint32_t RCC_GetPLLClock(void)
{
  uint32_t sclk = 0;
  uint32_t pllsource, pllm, pllvco, pllr,plln;

  if((ICG->CLK_CFG & ICG_CLK_CTL_PLL) == RCC_PLL_ON)
  {
    pllsource = ICG->PLL_LFCFG_CTRL & ICG_PLL_CLKSRC;
#if defined(XT32H0xxAMPW)
    switch(ICG->PLL_DIV & ICG_PLL_PREDIV)
    {
      case RCC_PLLM_DIV2:
        pllm = 2;
        break;
      case RCC_PLLM_DIV4:
        pllm = 4;
        break;
      case RCC_PLLM_DIV8:
        pllm = 8;
        break;
      case RCC_PLLM_DIV12:
      default:
        pllm = 12;
        break;
    }
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
    switch(ICG->PLL_DIV & ICG_PLL_PREDIV)
    {
      case RCC_PLLM_DIV1:
        pllm = 1;
        break;
      case RCC_PLLM_DIV2:
        pllm = 2;
        break;
      case RCC_PLLM_DIV3:
        pllm = 3;
        break;
      case RCC_PLLM_DIV4:
        pllm = 4;
        break;
      case RCC_PLLM_DIV6:
        pllm = 6;
        break;
      case RCC_PLLM_DIV8:
        pllm = 8;
        break;
      case RCC_PLLM_DIV12:
        pllm = 12;
        break;
      case RCC_PLLM_DIV24:
      default:
        pllm = 24;
        break;
    }
#endif
    pllvco = 0;
    plln = ((ICG->PLL_DIV & ICG_PLL_FBDIV) >> ICG_PLL_FBDIV_Pos);
#if defined(XT32H0xxAMPW)
    switch(ICG->PLL_DIV & ICG_PLL_POSTDIV)
    {
      case RCC_PLLR_DIV4:
        pllr = 4;
        break;
      case RCC_PLLR_DIV6:
        pllr = 6;
        break;
      case RCC_PLLR_DIV8:
        pllr = 8;
        break;
      case RCC_PLLR_DIV12:
        pllr = 12;
        break;
      case RCC_PLLR_DIV24:
      default:
        pllr = 24;
        break;
    }
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
    switch(ICG->PLL_DIV & ICG_PLL_POSTDIV)
    {
      case RCC_PLLR_DIV4:
        pllr = 4;
        break;
      case RCC_PLLR_DIV6:
        pllr = 6;
        break;
      case RCC_PLLR_DIV8:
        pllr = 8;
        break;
      case RCC_PLLR_DIV12:
        pllr = 12;
        break;
      case RCC_PLLR_DIV16:
        pllr = 16;
        break;
      case RCC_PLLR_DIV24:
        pllr = 24;
        break;
      case RCC_PLLR_DIV48:
      default:
        pllr = 48;
        break;
    }
#endif
    switch (pllsource)
    {
      case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
        if((ICG->CLK_CFG & (ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT)) == RCC_HSE_ON)
          pllvco = (HSE_VALUE / pllm) * plln;
        break;
    
      case RCC_PLLSOURCE_HSI:  /* HSI used as PLL clock source */
      default:                 
        if((ICG->CLK_CFG & ICG_CLK_CTL_HSRC) == RCC_HSI_ON)
          pllvco = (HSI_VALUE / pllm) * plln ;
        break;
    }
    sclk = pllvco / pllr;
  }

  return sclk;
}

/**
  * @brief  Configures the Internal low Speed oscillator (LSI).
  * @param  RCC_LSI: specifies the new state of the LSI.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LSI_OFF turn OFF the LSI.
  *            @arg @ref RCC_LSI_ON turn ON the LSI.
  */
void RCC_LSIConfig(uint32_t RCC_LSI)
{
  uint32_t tempr;

  assert_param(IS_RCC_LSI(RCC_LSI));

  tempr = AON->AON_CLK_CTRL;
  tempr &= (uint32_t)~((uint32_t)(AON_CLKCTRL_32KRC_PD));
  tempr |= (uint32_t)(RCC_LSI); 
  AON->AON_CLK_CTRL = tempr;
}

/**
  * @brief  Configures the External low Speed oscillator (LSE).
  * @param  RCC_LSE: specifies the new state of the LSE.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LSE_OFF turn OFF the LSE.
  *            @arg @ref RCC_LSE_ON turn ON the LSE.
  */
void RCC_LSEConfig(uint32_t RCC_LSE)
{
  uint32_t tempr;

  assert_param(IS_RCC_LSE(RCC_LSE));

  tempr = AON->AON_CLK_CTRL;
  tempr &= (uint32_t)~((uint32_t)(AON_CLKCTRL_32KXTAL_PD));
  tempr |= (uint32_t)(RCC_LSE); 
  AON->AON_CLK_CTRL = tempr;
}

/**
  * @brief  Set system clock source.
  * @param  Source: specifies the new state of the LSE.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_SYSCLKSOURCE_HSI
  *            @arg @ref RCC_SYSCLKSOURCE_HSE
  *            @arg @ref RCC_SYSCLKSOURCE_PLL
  *            @arg @ref RCC_SYSCLKSOURCE_LS
  */
void RCC_SetSYSCLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_SYSCLK_SOURCE(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_HCLKSRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set AHB clock source.
  * @param  Source: specifies the new state of the LSE.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_SYSCLKSOURCE_HSI
  *            @arg @ref RCC_SYSCLKSOURCE_HSE
  *            @arg @ref RCC_SYSCLKSOURCE_PLL
  *            @arg @ref RCC_SYSCLKSOURCE_LS
  */
void RCC_SetHCLKSource(uint32_t Source)
{
  RCC_SetSYSCLKSource(Source);
}

/**
  * @brief  Set APB clock source.
  * @param  Source: specifies the new state of the LSE.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_SYSCLKSOURCE_HSI
  *            @arg @ref RCC_SYSCLKSOURCE_HSE
  *            @arg @ref RCC_SYSCLKSOURCE_PLL
  *            @arg @ref RCC_SYSCLKSOURCE_LS
  */
void RCC_SetPCLKSource(uint32_t Source)
{
  RCC_SetSYSCLKSource(Source);
}


/**
  * @brief  Set system clock divider.
  * @param  Divider: 
  */
void RCC_SetSYSCLKDivider(uint32_t Divider)
{
  ICG->HCLK_DIV = Divider;
}

/**
  * @brief  Set AHB clock divider.
  * @param  Divider: 
  */
void RCC_SetHCLKDivider(uint32_t Divider)
{
  ICG->HCLK_DIV = Divider;
}

/**
  * @brief  Set APB clock divider.
  * @param  Divider: 
  */
void RCC_SetPCLKDivider(uint32_t Divider)
{
  ICG->PCLK_DIV = Divider;
}

/**
  * @brief  Get system clock.
  * @retval Clock
  */
uint32_t RCC_GetSYSCLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_HCLKSRC;
  uint32_t div = ICG->HCLK_DIV ? ICG->HCLK_DIV : 1;
  switch(src)
  {
    case RCC_SYSCLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_SYSCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_SYSCLKSOURCE_LS:
      if((AON->AON_CFG & AON_CFG_32KCLKSRC) == RCC_LSSRC_LSE)
      {
        sclk = LSE_VALUE;
      }
      else
      {
        sclk = LSI_VALUE;
      }
      break;
    case RCC_SYSCLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Get AHB clock.
  * @retval Clock
  */
uint32_t RCC_GetHCLKClock(void)
{
  return  RCC_GetSYSCLKClock();
}

/**
  * @brief  Get APB clock.
  * @retval Clock
  */
uint32_t RCC_GetPCLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_HCLKSRC;
  uint32_t div = ICG->PCLK_DIV ? ICG->PCLK_DIV : 1;
  switch(src)
  {
    case RCC_SYSCLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_SYSCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_SYSCLKSOURCE_LS:
      if((AON->AON_CFG & AON_CFG_32KCLKSRC) == RCC_LSSRC_LSE)
      {
        sclk = LSE_VALUE;
      }
      else
      {
        sclk = LSI_VALUE;
      }
      break;
    case RCC_SYSCLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set ADC clock.
  * @param  Source: 
  */
void RCC_SetADCCLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_ADCCLK(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_ADCSRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set ADC divider.
  * @param  Divider 
  */
void RCC_SetADCCLKDivider(uint32_t Divider)
{
  ICG->ADC_CLK_DIV = Divider;
}

/**
  * @brief  Get ADC clock.
  * @retval Clock
  */
uint32_t RCC_GetADCCLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_ADCSRC;
  uint32_t div = ICG->ADC_CLK_DIV ? ICG->ADC_CLK_DIV : 1;
  switch(src)
  {
    case RCC_ADCCLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_ADCCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_ADCCLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set Timer A and G clock source.
  * @param  Source: 
  */
void RCC_SetTIMAGCLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_TIMAGCLK(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_TMRAGSRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set Timer A & G divider.
  * @param  Divider 
  */
void RCC_SetTIMAGCLKDivider(uint32_t Divider)
{
  ICG->TIMER_ADV_CLK_DIV = Divider;
}

/**
  * @brief  Get Timer A & G clock.
  * @retval Clock
  */
uint32_t RCC_GetTIMAGCLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_TMRAGSRC;
  uint32_t div = ICG->TIMER_ADV_CLK_DIV ? ICG->TIMER_ADV_CLK_DIV : 1;
  switch(src)
  {
    case RCC_TIMAGCLKSOURCE_PCLK:
      sclk = RCC_GetPCLKClock();
      break;
    case RCC_TIMAGCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_TIMAGCLKSOURCE_HCLK:
    default :
      sclk = RCC_GetHCLKClock();
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set GPIO debounce clock source.
  * @param  Source
  */
void RCC_SetGPIOCLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_GPIOCLK(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_GPIOSRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set GPIO Debounce divider.
  * @param  Divider 
  */
void RCC_SetGPIOCLKDivider(uint32_t Divider)
{
  ICG->GPIO_CLK_DIV = Divider;
}

/**
  * @brief  Get GPIO Debounce clock.
  * @retval Clock
  */
uint32_t RCC_GetGPIOCLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_GPIOSRC;
  uint32_t div = ICG->GPIO_CLK_DIV ? ICG->GPIO_CLK_DIV : 1;
  switch(src)
  {
    case RCC_GPIOCLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_GPIOCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_GPIOCLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set Timer B group 2 clock source.
  * @param  Source: 
  */
void RCC_SetTIMB2CLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_TIMB2CLK(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_TMRB2SRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set Timer B group 2 divider.
  * @param  Divider 
  */
void RCC_SetTIMB2CLKDivider(uint32_t Divider)
{
  ICG->TIMER_B2_CLK_DIV = Divider;
}

/**
  * @brief  Get Timer B group 2 clock.
  * @retval Clock
  */
uint32_t RCC_GetTIMB2CLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_TMRB2SRC;
  uint32_t div = ICG->TIMER_B2_CLK_DIV ? ICG->TIMER_B2_CLK_DIV : 1;
  switch(src)
  {
    case RCC_TIMB2CLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_TIMB2CLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_TIMB2CLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set I2C clock source.
  * @param  Source
  */
void RCC_SetI2CCLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_I2CCLK(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_I2CSRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set I2C1 divider.
  * @param  Divider 
  */
void RCC_SetI2C1CLKDivider(uint32_t Divider)
{
  ICG->I2C1_CLK_DIV = Divider;
}

/**
  * @brief  Set I2C2 divider.
  * @param  Divider 
  */
void RCC_SetI2C2CLKDivider(uint32_t Divider)
{
  ICG->I2C2_CLK_DIV = Divider;
}

/**
  * @brief  Get I2C1 clock.
  * @retval Clock
  */
uint32_t RCC_GetI2C1CLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_I2CSRC;
  uint32_t div = ICG->I2C1_CLK_DIV ? ICG->I2C1_CLK_DIV : 1;
  switch(src)
  {
    case RCC_I2CCLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_I2CCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_I2CCLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Get I2C2 clock.
  * @retval Clock
  */
uint32_t RCC_GetI2C2CLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_I2CSRC;
  uint32_t div = ICG->I2C2_CLK_DIV ? ICG->I2C2_CLK_DIV : 1;
  switch(src)
  {
    case RCC_I2CCLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_I2CCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_I2CCLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set Timer b group 1 clock source.
  * @param  Source
  */
void RCC_SetTIMB1CLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_TIMB1CLK(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_TMRB1SRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set Timer B group 1 divider.
  * @param  Divider 
  */
void RCC_SetTIMB1CLKDivider(uint32_t Divider)
{
  ICG->TIMER_B1_CLK_DIV = Divider;
}

/**
  * @brief  Get Timer b group 1 clock.
  * @retval Clock
  */
uint32_t RCC_GetTIMB1CLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_TMRB1SRC;
  uint32_t div = ICG->TIMER_B1_CLK_DIV ? ICG->TIMER_B1_CLK_DIV : 1;
  switch(src)
  {
    case RCC_TIMB1CLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_TIMB1CLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_TIMB1CLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set baudrate clock source.
  * @param  Source 
  */
void RCC_SetBRCLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_BRCLK(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_BRSRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set baudrate divider.
  * @param  Divider 
  */
void RCC_SetBRCLKDivider(uint32_t Divider)
{
  ICG->BR_CLK_DIV = Divider;
}

/**
  * @brief  Get baudrate clock.
  * @retval Clock
  */
uint32_t RCC_GetBRCLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_BRSRC;
  uint32_t div = ICG->BR_CLK_DIV ? ICG->BR_CLK_DIV : 1;
  switch(src)
  {
    case RCC_BRCLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_BRCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_BRCLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set windows watch-dog clock source.
  * @param  Source 
  */
void RCC_SetWDTWCLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_WDTWCLK(Source));

  tempr = ICG->CLK_CFG;
  tempr &= (uint32_t)~((uint32_t)(ICG_CLK_CTL_WDTWSRC));
  tempr |= (uint32_t)(Source); 
  ICG->CLK_CFG = tempr;
}

/**
  * @brief  Set windows watch-dog divider.
  * @param  Divider 
  */
void RCC_SetWDTWCLKDivider(uint32_t Divider)
{
  ICG->WDT_W_CLK_DIV = Divider;
}

/**
  * @brief  Get windows watch-dog clock.
  * @retval Clock
  */
uint32_t RCC_GetWDTWCLKClock(void)
{
  uint32_t sclk;
  uint32_t src = ICG->CLK_CFG & ICG_CLK_CTL_WDTWSRC;
  uint32_t div = ICG->WDT_W_CLK_DIV ? ICG->WDT_W_CLK_DIV : 1;
  switch(src)
  {
    case RCC_WDTWCLKSOURCE_HSE:
      sclk = HSE_VALUE;
      break;
    case RCC_WDTWCLKSOURCE_PLL:
      sclk = RCC_GetPLLClock();
      break;
    case RCC_WDTWCLKSOURCE_HSI:
    default :
      sclk = HSI_VALUE;
      break;
  }

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set DMA divider.
  * @param  Divider 
  */
void RCC_SetDMACLKDivider(uint32_t Divider)
{
  ICG->DMA_CLK_DIV = Divider;
}

/**
  * @brief  Get DMA clock.
  * @retval Clock
  */
uint32_t RCC_GetDMACLKClock(void)
{
  uint32_t sclk = RCC_GetHCLKClock();
  uint32_t div = ICG->DMA_CLK_DIV ? ICG->DMA_CLK_DIV : 1;

  sclk = sclk / div;
  return sclk;
}

/**
  * @brief  Set Timer A use external clock.
  * @param  ClkSrc 
  */
void RCC_SetTIMAExternalClock(uint32_t ClkSrc)
{
  uint32_t tempr;

  tempr = ICG->TIMER_EXCLK_EN;
  tempr &= (uint32_t)~((uint32_t)(ICG_TMXC_ATMSRC_CH));
  tempr |= (uint32_t)(ClkSrc); 
  ICG->TIMER_EXCLK_EN = tempr;
}

/**
  * @brief  Set Timer G use external clock.
  * @param  ClkSrc: 
  */
void RCC_SetTIMGExternalClock(uint32_t ClkSrc)
{
  uint32_t tempr;

  tempr = ICG->TIMER_EXCLK_EN;
  tempr &= (uint32_t)~((uint32_t)(ICG_TMXC_GTMSRC_CH));
  tempr |= (uint32_t)(ClkSrc); 
  ICG->TIMER_EXCLK_EN = tempr;
}

/**
  * @brief  Set Timer B use external clock.
  * @param  ClkSrc: 
  */
void RCC_SetTIMBExternalClock(uint32_t ClkSrc)
{
  uint32_t tempr;

  tempr = ICG->TIMER_EXCLK_EN;
  tempr &= (uint32_t)~((uint32_t)(ICG_TMXC_BTMSRC));
  tempr |= (uint32_t)(ClkSrc); 
  ICG->TIMER_EXCLK_EN = tempr;
}

/**
  * @brief Set RTC clock source.
  * @param  Source: specifies the new state of the LSE.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LSSRC_LSI 
  *            @arg @ref RCC_LSSRC_LSE 
  */
void RCC_SetRTCCLKSource(uint32_t Source)
{
  uint32_t tempr;

  assert_param(IS_RCC_LSCLK(Source));

  tempr = AON->AON_CFG;
  tempr &= (uint32_t)~((uint32_t)(AON_CFG_32KCLKSRC));
  tempr |= (uint32_t)(Source); 
  AON->AON_CFG = tempr;
}

/**
  * @brief Set RTC clock divider.
  * @param  Divider RTC clock divider
  */
void RCC_SetRTCCLKDivider(uint32_t Divider)
{
  AON->RTC_REFCLK_DIV = Divider;
}

/**
  * @brief Get RTC clock.
  * @retval Clock \@Hz
  */
uint32_t RCC_GetRTCCLKClock(void)
{
  uint32_t sclk;
  uint32_t div = AON->RTC_REFCLK_DIV;
  
  if((AON->AON_CFG & AON_CFG_32KCLKSRC) == RCC_LSSRC_LSE)
  {
    sclk = LSE_VALUE;
  }
  else
  {
    sclk = LSI_VALUE;
  }
  div = div ? div : 1;
  sclk = sclk / div;

  return sclk;
}

/**
  * @brief Set Deep sleep clock.
  * @param Clk \@us  
  */
void RCC_SetDeepSleepTime(uint32_t Clk)
{
  uint32_t time; 
  uint32_t sclk;
  
  if((AON->AON_CFG & AON_CFG_32KCLKSRC) == RCC_LSSRC_LSE)
  {
    sclk = LSE_VALUE;
  }
  else
  {
    sclk = LSI_VALUE;
  }

  time = sclk * Clk /1000000;

  AON->DEEPSLEEP_TIME = time;
}

/**
  * @brief Set Deep sleep mode.
  */
void RCC_DeepSleep(void)
{
  AON->DEEPSLEEP_CTRL |= (uint32_t)AON_DEEPSLEEP_CTRL_MODE;
}

#if defined(XT32H0xxB)
/**
  * @brief Set Deep sleep mode.
  * @param ExtWakeup 
  *        This parameter can be one of the following values:
  *        @arg @ref RCC_DEEPSLEEP_EXTWAKRUP_DISABLE
  *        @arg @ref RCC_DEEPSLEEP_EXTWAKRUP_ENABLE
  */
void RCC_DeepSleep(uint32_t ExtWakeup)
{
  AON->DEEPSLEEP_CTRL = ((uint32_t)AON_DEEPSLEEP_CTRL_MODE | ExtWakeup);
}
#else
/**
  * @brief Set Deep sleep mode.
  * @param None  
  */
void RCC_DeepSleep(void)
{
  AON->DEEPSLEEP_CTRL = (uint32_t)AON_DEEPSLEEP_CTRL_MODE;
}
#endif /* XT32H0xxB */

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
/**
  * @brief Set HSI mode.
  * @param Mode
  *        The parameter can be one of the following values:
  *        @arg @ref  RCC_HSI_NORMAL  
  *        @arg @ref  RCC_HSI_CALIB  
  */
void RCC_SetHSIMode(uint32_t Mode)
{
  uint32_t tmp = ICG->RC16M_CTRL;
  tmp &= (uint32_t)(~(ICG_RC16M_CTRL_CALI));
  tmp |= Mode;
  ICG->RC16M_CTRL = tmp;
}

/**
  * @brief Set HSI code.
  * @param Code
  *        the parameter can be one between 0 to 0xFF  
  */
void RCC_SetHSICode(uint32_t Code)
{
  uint32_t tmp = ICG->RC16M_CTRL;
  tmp &= (uint32_t)(~(ICG_RC16M_CTRL_CRES));
  tmp |= Code;
  ICG->RC16M_CTRL = tmp;
}

/**
  * @brief Set LSI mode.
  * @param Mode
  *        The parameter can be one of the following values:
  *        @arg @ref  RCC_LSI_NORMAL  
  *        @arg @ref  RCC_LSI_CALIB  
  */
void RCC_SetLSIMode(uint32_t Mode)
{
  uint32_t tmp = AON->AON_CLK_CTRL;
  tmp &= (uint32_t)(~(AON_CLKCTRL_32K_CAL));
  tmp |= Mode;
  AON->AON_CLK_CTRL = tmp;
}

/**
  * @brief Set LSI code.
  * @param Code
  *        the parameter can be one between 0 to 0x3F  
  */
void RCC_SetLSICode(uint32_t Code)
{
  uint32_t tmp = AON->AON_CLK_CTRL;
  tmp &= (uint32_t)(~(AON_CLKCTRL_32KRC_RESTUNE));
  tmp |= (Code << AON_CLKCTRL_32KRC_RESTUNE_Pos);
  AON->AON_CLK_CTRL = tmp;
}
#endif

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

