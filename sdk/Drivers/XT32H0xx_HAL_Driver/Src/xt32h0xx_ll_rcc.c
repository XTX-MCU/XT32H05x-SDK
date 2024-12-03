/**
  ******************************************************************************
  * @file    xt32h0xx_ll_rcc.c
  * @author  Software Team
  * @brief   RCC LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_rcc.h"
#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */
/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined(ICG)

/** @addtogroup RCC_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup RCC_LL_Private_Macros
  * @{
  */
#define IS_LL_RCC_TIMAG_CLKSOURCE(__VALUE__)     (((__VALUE__) == LL_RCC_TIMAG_SRC_HSI) \
                                               || ((__VALUE__) == LL_RCC_TIMAG_SRC_HSE) \
                                               || ((__VALUE__) == LL_RCC_TIMAG_SRC_PLL))

#define IS_LL_RCC_GPIO_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_GPIO_SRC_HSI) \
                                             || ((__VALUE__) == LL_RCC_GPIO_SRC_HSE) \
                                             || ((__VALUE__) == LL_RCC_GPIO_SRC_PLL))

#define IS_LL_RCC_I2C_CLKSOURCE(__VALUE__)     (((__VALUE__) == LL_RCC_I2C_SRC_HSI) \
                                             || ((__VALUE__) == LL_RCC_I2C_SRC_HSE) \
                                             || ((__VALUE__) == LL_RCC_I2C_SRC_PLL))

#define IS_LL_RCC_TIMB1_CLKSOURCE(__VALUE__)     (((__VALUE__) == LL_RCC_TIMB1_SRC_HSI) \
                                               || ((__VALUE__) == LL_RCC_TIMB1_SRC_HSE) \
                                               || ((__VALUE__) == LL_RCC_TIMB1_SRC_PLL))

#define IS_LL_RCC_TIMB2_CLKSOURCE(__VALUE__)     (((__VALUE__) == LL_RCC_TIMB2_SRC_HSI) \
                                               || ((__VALUE__) == LL_RCC_TIMB2_SRC_HSE) \
                                               || ((__VALUE__) == LL_RCC_TIMB2_SRC_PLL))

#define IS_LL_RCC_BR_CLKSOURCE(__VALUE__)        (((__VALUE__) == LL_RCC_BR_SRC_HSI) \
                                               || ((__VALUE__) == LL_RCC_BR_SRC_HSE) \
                                               || ((__VALUE__) == LL_RCC_BR_SRC_PLL))

#define IS_LL_RCC_WDTW_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_WDTW_SRC_HSI) \
                                             || ((__VALUE__) == LL_RCC_WDTW_SRC_HSE) \
                                             || ((__VALUE__) == LL_RCC_WDTW_SRC_PLL))

#define IS_LL_RCC_HCLK_CLKSOURCE(__VALUE__)    (((__VALUE__) == LL_RCC_HCLK_SRC_HSI) \
                                             || ((__VALUE__) == LL_RCC_HCLK_SRC_HSE) \
                                             || ((__VALUE__) == LL_RCC_HCLK_SRC_PLL) \
                                             || ((__VALUE__) == LL_RCC_HCLK_SRC_LS))
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup RCC_LL_Private_Functions RCC Private functions
  * @{
  */
static uint32_t RCC_GetSystemClockFreq(void);
static uint32_t RCC_GetHCLKClockFreq(void);
static uint32_t RCC_GetPCLKClockFreq(void);
static uint32_t RCC_GetPLLClockFreq(void);
/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCC_LL_Exported_Functions
  * @{
  */

/** @addtogroup RCC_LL_Exported_Functions_Group5
  * @{
  */

/**
  * @brief  Reset the RCC clock configuration to the default reset state.
  * @note   The default reset state of the clock configuration is given below:
  *         - HSI ON and used as system clock source
  *         - HSE and PLL OFF
  *         - AHB and APB1 prescaler set to 1.
  *         - CSS, MCO OFF
  *         - All interrupts disabled
  * @note   This function does not modify the configuration of the
  *         - Peripheral clocks
  *         - LSI, LSE and RTC clocks
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: RCC registers are de-initialized
  *          - ERROR: not applicable
  */
ErrorStatus LL_RCC_DeInit(void)
{
#if 0  
  /* Set HSION bit and wait for HSI READY bit */
  LL_RCC_HSI_Enable();
  while (LL_RCC_HSI_IsReady() != 1U)
  {}

  /* Set HSITRIM bits to reset value*/
  LL_RCC_HSI_SetCalibTrimming(0x40U);

  /* Reset CFGR register */
  LL_RCC_WriteReg(CFGR, 0x00000000U);

  /* Reset whole CR register but HSI in 2 steps in case HSEBYP is set */
  LL_RCC_WriteReg(CR, RCC_CR_HSION);
  while (LL_RCC_HSE_IsReady() != 0U)
  {}
  LL_RCC_WriteReg(CR, RCC_CR_HSION);

  /* Wait for PLL READY bit to be reset */
  while (LL_RCC_PLL_IsReady() != 0U)
  {}

  /* Reset PLLCFGR register */
  LL_RCC_WriteReg(PLLCFGR, 16U << RCC_PLLCFGR_PLLN_Pos);

  /* Disable all interrupts */
  LL_RCC_WriteReg(CIER, 0x00000000U);

  /* Clear all interrupts flags */
  LL_RCC_WriteReg(CICR, 0xFFFFFFFFU);
#endif
  return SUCCESS;
}

/**
  * @}
  */

/** @addtogroup RCC_LL_Exported_Functions_Group6
  * @brief  Return the frequencies of different on chip clocks;  System, AHB and APB1 buses clocks
  *         and different peripheral clocks available on the device.
  * @note   If SYSCLK source is HSI, function returns values based on HSI_VALUE divided by HSI division factor(**)
  * @note   If SYSCLK source is HSE, function returns values based on HSE_VALUE(***)
  * @note   If SYSCLK source is PLL, function returns values based on HSE_VALUE(***)
  *         or HSI_VALUE(**) multiplied/divided by the PLL factors.
  * @note   (**) HSI_VALUE is a constant defined in this file (default value
  *              16 MHz) but the real value may vary depending on the variations
  *              in voltage and temperature.
  * @note   (***) HSE_VALUE is a constant defined in this file (default value
  *               8 MHz), user has to ensure that HSE_VALUE is same as the real
  *               frequency of the crystal used. Otherwise, this function may
  *               have wrong result.
  * @note   The result of this function could be incorrect when using fractional
  *         value for HSE crystal.
  * @note   This function can be used by the user application to compute the
  *         baud-rate for the communication peripherals or configure other parameters.
  * @{
  */

/**
  * @brief  Return the frequencies of different on chip clocks;  System, AHB and APB1 buses clocks
  * @note   Each time SYSCLK, HCLK and/or PCLK1 clock changes, this function
  *         must be called to update structure fields. Otherwise, any
  *         configuration based on this function will be incorrect.
  * @param  RCC_Clocks pointer to a RCC frequencies
  */
void LL_RCC_GetSystemClocksFreq(LL_RCC_ClocksTypeDef *RCC_Clocks)
{
  /* Get SYSCLK frequency */
  RCC_Clocks->SYSCLK_Frequency = RCC_GetSystemClockFreq();

  /* HCLK clock frequency */
  RCC_Clocks->HCLK_Frequency   = RCC_GetHCLKClockFreq();

  /* PCLK1 clock frequency */
  RCC_Clocks->PCLK_Frequency  = RCC_GetPCLKClockFreq();
}

/**
  * @brief  Return USARTx clock frequency
  * @retval BaudRate clock frequency (in Hz)
  */
uint32_t LL_RCC_GetBRClockFreq(void)
{
  uint32_t br_frequency = HSI_VALUE;

  /* BRCLK clock frequency */
  switch (LL_RCC_GetBRCLKSrc())
  {
    case LL_RCC_BR_SRC_HSE:    /* BR Clock is HSI Osc. */
      br_frequency = HSE_VALUE;
      break;
    case LL_RCC_BR_SRC_PLL:    /* BR Clock is PLL clock. */
      br_frequency = RCC_GetPLLClockFreq();
      break;
    case LL_RCC_BR_SRC_HSI: /* BR Clock is RC clock */
    default:
      br_frequency = HSI_VALUE;
      break;
  }

  return __LL_RCC_CALC_BRCLK_FREQ(br_frequency, LL_RCC_GetBRCLKDiv());
}

/**
  * @brief  Return I2Cx clock frequency
  * @retval I2C clock frequency (in Hz)
  */
uint32_t LL_RCC_GetI2C1ClockFreq(void)
{
  uint32_t i2c_frequency = HSI_VALUE;

  /* I2C1 CLK clock frequency */
  switch (LL_RCC_GetI2CCLKSrc())
  {
    case LL_RCC_I2C_SRC_HSE: /* I2C1 Clock is System Clock */
      i2c_frequency = HSE_VALUE;
      break;

    case LL_RCC_I2C_SRC_PLL:    /* I2C1 Clock is HSI Osc. */
      RCC_GetPLLClockFreq();
      break;

    case LL_RCC_I2C_SRC_HSI:  /* I2C1 Clock is PCLK1 */
    default:
      i2c_frequency = HSI_VALUE;
      break;
  }

  return __LL_RCC_CALC_I2C1CLK_FREQ(i2c_frequency, LL_RCC_GetI2C1CLKDiv());
}

/**
  * @brief  Return I2Cx clock frequency
  * @retval I2C clock frequency (in Hz)
  */
uint32_t LL_RCC_GetI2C2ClockFreq(void)
{
  uint32_t i2c_frequency = HSI_VALUE;

  /* I2C1 CLK clock frequency */
  switch (LL_RCC_GetI2CCLKSrc())
  {
    case LL_RCC_I2C_SRC_HSE: /* I2C1 Clock is System Clock */
      i2c_frequency = HSE_VALUE;
      break;

    case LL_RCC_I2C_SRC_PLL:    /* I2C1 Clock is HSI Osc. */
      RCC_GetPLLClockFreq();
      break;

    case LL_RCC_I2C_SRC_HSI:  /* I2C1 Clock is PCLK1 */
    default:
      i2c_frequency = HSI_VALUE;
      break;
  }

  return __LL_RCC_CALC_I2C2CLK_FREQ(i2c_frequency, LL_RCC_GetI2C2CLKDiv());
}


/**
  * @brief  Return TIMx clock frequency
  * @retval TIMx clock frequency (in Hz)
  */
uint32_t LL_RCC_GetTIMAGClockFreq()
{
  uint32_t tim_frequency = HSI_VALUE;

  /* TIM1CLK clock frequency */
  switch (LL_RCC_GetTimerAGCLKSrc())
  {
    case LL_RCC_TIMAG_SRC_HCLK:    /* TIM1 Clock is PLLQ */
      tim_frequency = RCC_GetHCLKClockFreq();
      break;
    case LL_RCC_TIMAG_SRC_PLL:
      tim_frequency = RCC_GetPLLClockFreq();
      break;
    case LL_RCC_TIMAG_SRC_PCLK:  /* TIM1 Clock is PCLK1 */
    default:
      tim_frequency = RCC_GetPCLKClockFreq();
      break;
  }
  return __LL_RCC_CALC_TIMAGCLK_FREQ(tim_frequency, LL_RCC_GetTIMAGCLKDiv());
}

/**
  * @brief  Return TIMx clock frequency
  * @retval TIMB1x clock frequency (in Hz)
  */
uint32_t LL_RCC_GetTIMB1ClockFreq()
{
  uint32_t tim_frequency = HSI_VALUE;

  /* TIM1CLK clock frequency */
  switch (LL_RCC_GetTimerB1CLKSrc())
  {
    case LL_RCC_TIMB1_SRC_HSE:    /* TIM1 Clock is PLLQ */
      tim_frequency = HSI_VALUE;
      break;
    case LL_RCC_TIMB1_SRC_PLL:
      tim_frequency = RCC_GetPLLClockFreq();
    case LL_RCC_TIMB1_SRC_HSI:  /* TIM1 Clock is PCLK1 */
    default:
      tim_frequency = HSI_VALUE;
      break;
  }
  return __LL_RCC_CALC_TIMB1CLK_FREQ(tim_frequency, LL_RCC_GetTIMB1CLKDiv());
}

/**
  * @brief  Return TIMx clock frequency
  * @retval TIMB2x clock frequency (in Hz)
  */
uint32_t LL_RCC_GetTIMB2ClockFreq()
{
  uint32_t tim_frequency = HSI_VALUE;

  /* TIM1CLK clock frequency */
  switch (LL_RCC_GetTimerB2CLKSrc())
  {
    case LL_RCC_TIMB1_SRC_HSE:    /* TIM1 Clock is PLLQ */
      tim_frequency = HSI_VALUE;
      break;
    case LL_RCC_TIMB1_SRC_PLL:
      tim_frequency = RCC_GetPLLClockFreq();
    case LL_RCC_TIMB1_SRC_HSI:  /* TIM1 Clock is PCLK1 */
    default:
      tim_frequency = HSI_VALUE;
      break;
  }
  return __LL_RCC_CALC_TIMB2CLK_FREQ(tim_frequency, LL_RCC_GetTIMB2CLKDiv());
}

/**
  * @brief  Return TIMx clock frequency
  * @retval WDTW clock frequency (in Hz)
  */
uint32_t LL_RCC_GetWDTWClockFreq()
{
  uint32_t tim_frequency = HSI_VALUE;

  /* TIM1CLK clock frequency */
  switch (LL_RCC_GetWDTWCLKSrc())
  {
    case LL_RCC_TIMB1_SRC_HSE:    /* TIM1 Clock is PLLQ */
      tim_frequency = HSE_VALUE;
      break;
    case LL_RCC_TIMB1_SRC_PLL:
      tim_frequency = RCC_GetPLLClockFreq();
    case LL_RCC_TIMB1_SRC_HSI:  /* TIM1 Clock is PCLK1 */
    default:
      tim_frequency = HSI_VALUE;
      break;
  }
  return __LL_RCC_CALC_WDTWCLK_FREQ(tim_frequency, LL_RCC_GetWDTWCLKDiv());
}

/**
  * @brief  Return ADCx clock frequency
  * @retval ADC clock frequency (in Hz)
  */
uint32_t LL_RCC_GetADCClockFreq(void)
{
  uint32_t adc_frequency = HSI_VALUE;

  /* ADCCLK clock frequency */
  switch (LL_RCC_GetADCCLKSrc())
  {
    case LL_RCC_ADC_SRC_HSE:        /* SYSCLK clock used as ADC clock source */
      adc_frequency = HSE_VALUE;
      break;
    case LL_RCC_ADC_SRC_HSI  :        /* HSI clock used as ADC clock source */
      adc_frequency = HSI_VALUE;
      break;

    case LL_RCC_ADC_SRC_PLL:         /* PLLP clock used as ADC clock source */
      adc_frequency = RCC_GetPLLClockFreq();
      break;
    default:
      adc_frequency = HSI_VALUE;
      break;
  }

  return __LL_RCC_CALC_ADCCLK_FREQ(adc_frequency, LL_RCC_GetADCCLKDiv());
}
/**
  * @brief  Return RTC clock frequency
  * @retval RTC clock frequency (in Hz)
  */
uint32_t LL_RCC_GetRTCClockFreq(void)
{
  uint32_t rtc_frequency = LSI_VALUE;

  /* RTCCLK clock frequency */
  return __LL_RCC_CALC_RTCCLK_FREQ(rtc_frequency, LL_RCC_GetRTCRefClkDiv());
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup RCC_LL_Private_Functions
  * @{
  */

/**
  * @brief  Return SYSTEM clock frequency
  * @retval SYSTEM clock frequency (in Hz)
  */
static uint32_t RCC_GetSystemClockFreq(void)
{
  uint32_t frequency;
  uint32_t hclkdiv;

  hclkdiv = LL_RCC_GetHCLKDiv();

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (LL_RCC_GetSysClkSrc())
  {
    case LL_RCC_HCLK_SRC_HSE:  /* HSE used as system clock  source */
      frequency = HSE_VALUE;
      break;

    case LL_RCC_HCLK_SRC_LS:  /* LSE or LSI used as system clock  source */
      frequency = LSE_VALUE;
      break;

    case LL_RCC_HCLK_SRC_PLL:  /* PLL used as system clock  source */
      frequency = RCC_GetPLLClockFreq();
      break;

    case LL_RCC_HCLK_SRC_HSI:  /* HSI used as system clock  source */
    default:
      frequency = (HSI_VALUE);
      break;
  }

  return (frequency / hclkdiv);
}

/**
  * @brief  Return HCLK clock frequency
  * @retval HCLK clock frequency (in Hz)
  */
static uint32_t RCC_GetHCLKClockFreq(void)
{
  /* HCLK clock frequency */
  return RCC_GetSystemClockFreq();
}

/**
  * @brief  Return PCLK1 clock frequency
  * @retval PCLK1 clock frequency (in Hz)
  */
static uint32_t RCC_GetPCLKClockFreq()
{
  /* PCLK clock frequency */
  uint32_t frequency;
  uint32_t pclkdiv;

  pclkdiv = LL_RCC_GetPCLKDiv();

  /* Get SYSCLK source -------------------------------------------------------*/
  switch (LL_RCC_GetSysClkSrc())
  {
    case LL_RCC_HCLK_SRC_HSE:  /* HSE used as system clock  source */
      frequency = HSE_VALUE;
      break;

    case LL_RCC_HCLK_SRC_LS:  /* LSE or LSI used as system clock  source */
      frequency = LSE_VALUE;
      break;

    case LL_RCC_HCLK_SRC_PLL:  /* PLL used as system clock  source */
      frequency = RCC_GetPLLClockFreq();
      break;

    case LL_RCC_HCLK_SRC_HSI:  /* HSI used as system clock  source */
    default:
      frequency = (HSI_VALUE);
      break;
  }

  return (frequency / pclkdiv);
}

/**
  * @brief  Return PLL clock frequency used for system domain
  * @retval PLL clock frequency (in Hz)
  */
static uint32_t RCC_GetPLLClockFreq(void)
{
  uint32_t pllinputfreq;
  uint32_t pllsource;

  /* PLL_VCO = (HSE_VALUE or HSI_VALUE / PLLM) * PLLN
     SYSCLK = PLL_VCO / PLLR
  */
  pllsource = LL_RCC_GetPLLClkSrc();

  switch (pllsource)
  {
    case LL_RCC_PLL_SRC_HSI:  /* HSI used as PLL clock source */
      pllinputfreq = HSI_VALUE;
      break;

    case LL_RCC_PLL_SRC_HSE:  /* HSE used as PLL clock source */
      pllinputfreq = HSE_VALUE;
      break;

    default:
      pllinputfreq = HSI_VALUE;
      break;
  }
  return __LL_RCC_CALC_PLLCLK_FREQ(pllinputfreq, LL_RCC_GetPLLM(),
                                   LL_RCC_GetPLLN(), LL_RCC_GetPLLR());
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* RCC */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
