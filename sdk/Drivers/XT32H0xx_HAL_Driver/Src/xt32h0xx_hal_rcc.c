/**
  ******************************************************************************
  * @file    xt32h0xx_hal_rcc.c
  * @author  Software Team
  * @brief   RCC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Reset and Clock Control (RCC) peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup RCC RCC
  * @brief RCC HAL module driver
  * @{
  */

#ifdef HAL_RCC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup RCC_Private_Constants RCC Private Constants
  * @{
  */
#define HSE_TIMEOUT_VALUE          HSE_STARTUP_TIMEOUT
#define HSI_TIMEOUT_VALUE          (2U)    /* 2 ms (minimum Tick + 1) */
#define LSI_TIMEOUT_VALUE          (2U)    /* 2 ms (minimum Tick + 1) */
#define PLL_TIMEOUT_VALUE          (2U)    /* 2 ms (minimum Tick + 1) */

#if defined(RCC_HSI48_SUPPORT)
#define HSI48_TIMEOUT_VALUE        (2U)    /* 2 ms (minimum Tick + 1) */
#endif /* RCC_HSI48_SUPPORT */
#define CLOCKSWITCH_TIMEOUT_VALUE  (5000U) /* 5 s    */

#define PLLSOURCE_NONE             (0U)

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup RCC_Private_Functions 
  * @{
  */
static uint32_t HAL_RCC_GetHSIClockFreq(void);
static uint32_t HAL_RCC_GetHSEClockFreq(void);
static uint32_t HAL_RCC_GetLSClockFreq(void);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup RCC_Exported_Functions RCC Exported Functions
  * @{
  */

/** @defgroup RCC_Exported_Functions_Group2 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  * @{
  */

/**
  * @brief  Reset the RCC clock configuration to the default reset state.
  * @note   The function is used to prepare to change PLL config
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCC_DeInit(void)
{
	/**/
	__HAL_RCC_HSE_CONFIG(RCC_HSE_ON);
	__HAL_RCC_HSI_CONFIG(RCC_HSI_ON);
	
	__HAL_RCC_PLL_SET_STATE(RCC_PLL_ON);
	
	__HAL_RCC_LSE_CONFIG(RCC_LSE_ON);
	__HAL_RCC_LSI_CONFIG(RCC_LSI_ON);
	
	if(__HAL_RCC_GET_HCLK_SOURCE() == RCC_HCLKSOURCE_PLL)
	{
		__HAL_RCC_HCLK_CONFIG(RCC_HCLKSOURCE_HSI);
	}

	if(__HAL_RCC_GET_ADC_SOURCE() == RCC_ADCCLKSOURCE_PLL)
	{
		__HAL_RCC_ADC_CONFIG(RCC_ADCCLKSOURCE_HCLK);
	}
	
	if(__HAL_RCC_GET_TIMAG_SOURCE() == RCC_TIMAGCLKSOURCE_PLL)
	{
		__HAL_RCC_TIMAG_CONFIG(RCC_TIMAGCLKSOURCE_HCLK);
	}
	
	if(__HAL_RCC_GET_GPIO_SOURCE() == RCC_GPIOCLKSOURCE_PLL)
	{
		__HAL_RCC_GPIO_CONFIG(RCC_GPIOCLKSOURCE_HSI);
	}

	if(__HAL_RCC_GET_TIMB1_SOURCE() == RCC_TIMB1CLKSOURCE_PLL)
	{
		__HAL_RCC_TIMB1_CONFIG(RCC_TIMB1CLKSOURCE_HCLK);
	}

	if(__HAL_RCC_GET_TIMB2_SOURCE() == RCC_TIMB2CLKSOURCE_PLL)
	{
		__HAL_RCC_TIMB2_CONFIG(RCC_TIMB2CLKSOURCE_HCLK);
	}

	if(__HAL_RCC_GET_I2C_SOURCE() == RCC_I2CCLKSOURCE_PLL)
	{
		__HAL_RCC_I2C_CONFIG(RCC_I2CCLKSOURCE_HSI);
	}

	if(__HAL_RCC_GET_BR_SOURCE() == RCC_BRCLKSOURCE_PLL)
	{
		__HAL_RCC_BR_CONFIG(RCC_BRCLKSOURCE_HSI);
	}

	if(__HAL_RCC_GET_WDTW_SOURCE() == RCC_WDTWCLKSOURCE_PLL)
	{
		__HAL_RCC_WDTW_CONFIG(RCC_WDTWCLKSOURCE_HCLK);
	}

  return HAL_OK;
}

/**
  * @brief  Initialize the RCC Oscillators according to the specified parameters in the
  *         @ref RCC_OscInitTypeDef.
  * @param  RCC_OscInitStruct pointer to a @ref RCC_OscInitTypeDef structure that
  *         contains the configuration information for the RCC Oscillators.
  * @note   The PLL is not disabled when used as system clock.
  * @note   Transition HSE Bypass to HSE On and HSE On to HSE Bypass are not
  *         supported by this function. User should request a transition to HSE Off
  *         first and then to HSE On or HSE Bypass.
  * @note   Transition LSE Bypass to LSE On and LSE On to LSE Bypass are not
  *         supported by this function. User should request a transition to LSE Off
  *         first and then to LSE On or LSE Bypass.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  uint32_t temp = 0;
  /* Check Null pointer */
  if (RCC_OscInitStruct == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_RCC_OSCILLATORTYPE(RCC_OscInitStruct->OscillatorType));

  /*------------------------------- HSE Configuration ------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSE(RCC_OscInitStruct->HSEState));
		
		if(RCC_OscInitStruct->HSEState == RCC_HSE_ON)
		{
#if defined(XT32H0xxB)			
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO7_XO_HS, RESET);
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO7_XO_HS, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO7_XO_HS, PADI_CFG_IO7_XO_HS);
      __HAL_PADI_SET_DS(PADI_IDX_IO7_XO_HS, PADI_DS_LOW);
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO8_XI_HS, RESET);
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO8_XI_HS, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO8_XI_HS, PADI_CFG_IO8_XI_HS);
      __HAL_PADI_SET_DS(PADI_IDX_IO8_XI_HS, PADI_DS_LOW);
#endif /* XT32H0xxB */			
		}

    __HAL_RCC_HSE_CONFIG(RCC_OscInitStruct->HSEState);
  }
  /*----------------------------- HSI Configuration --------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSI(RCC_OscInitStruct->HSIState));

    __HAL_RCC_HSI_CONFIG(RCC_OscInitStruct->HSIState);
  }
  /*------------------------------ LSI Configuration -------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LSI(RCC_OscInitStruct->LSIState));

    __HAL_RCC_LSI_CONFIG(RCC_OscInitStruct->LSIState);

  }
  /*------------------------------ LSE Configuration -------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LSE(RCC_OscInitStruct->LSEState));
    __HAL_RCC_LSE_CONFIG(RCC_OscInitStruct->LSEState);

  }

  /*-------------------------------- PLL Configuration -----------------------*/
  /* Check the parameters */
  assert_param(IS_RCC_PLL(RCC_OscInitStruct->PLL.PLLState));

  __HAL_RCC_PLL_SET_STATE(RCC_OscInitStruct->PLL.PLLState);
	
	__HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_OscInitStruct->PLL.PLLSource);

  assert_param(IS_RCC_PLLM(RCC_OscInitStruct->PLL.PLLM));
  assert_param(IS_RCC_PLLN(RCC_OscInitStruct->PLL.PLLN));
  assert_param(IS_RCC_PLLR(RCC_OscInitStruct->PLL.PLLR));

  __HAL_RCC_PLL_CONFIG(RCC_OscInitStruct->PLL.PLLM, RCC_OscInitStruct->PLL.PLLN, RCC_OscInitStruct->PLL.PLLR );
	
	if(RCC_OscInitStruct->PLL.PLLState == RCC_PLL_ON)
	{
	  /* check pll lock */
		do {
		  __NOP();
	  } while(!(ICG->PLL_IREF_CTRL & ICG_IREF_PLL_STAT));
		
		temp = ICG->PLL_VCOCAL_CTRL;
    temp &= ~(ICG_VCOCAL_INI_VAL);
    temp |= (((ICG->PLL_IREF_CTRL & ICG_IREF_VCOCAP_RD) >> ICG_IREF_VCOCAP_RD_Pos) << ICG_VCOCAL_INI_VAL_Pos);
		ICG->PLL_VCOCAL_CTRL = temp;
  }
	
  return HAL_OK;
}

/**
  * @brief  Initialize the CPU, AHB and APB buses clocks according to the specified
  *         parameters in the RCC_ClkInitStruct.
  * @param  RCC_ClkInitStruct  pointer to a @ref RCC_ClkInitTypeDef structure that
  *         contains the configuration information for the RCC peripheral.
  * @param  FLatency  FLASH Latency
  *          This parameter can be one of the following values:
  *            @arg FLASH_LATENCY_0   FLASH 0 Latency cycle
  *            @arg FLASH_LATENCY_1   FLASH 1 Latency cycle
  *
  * @note   The SystemCoreClock CMSIS variable is used to store System Clock Frequency
  *         and updated by @ref HAL_RCC_GetHCLKFreq() function called within this function
  *
  * @note   The HSI is used by default as system clock source after
  *         startup from Reset, wake-up from STANDBY mode. After restart from Reset,
  *         the HSI frequency is set to 8 Mhz, then it reaches its default value 16 MHz.
  *
  * @note   The HSI can be selected as system clock source after
  *         from STOP modes or in case of failure of the HSE used directly or indirectly
  *         as system clock (if the Clock Security System CSS is enabled).
  *
  * @note   The LSI can be selected as system clock source after
  *         in case of failure of the LSE used directly or indirectly
  *         as system clock (if the Clock Security System LSECSS is enabled).
  *
  * @note   A switch from one clock source to another occurs only if the target
  *         clock source is ready (clock stable after startup delay or PLL locked).
  *         If a clock source which is not yet ready is selected, the switch will
  *         occur when the clock source is ready.
  *
  * @note   You can use @ref HAL_RCC_GetClockConfig() function to know which clock is
  *         currently used as system clock source.
  *
  * @note   Depending on the device voltage range, the software has to set correctly
  *         HPRE[3:0] bits to ensure that HCLK not exceed the maximum allowed frequency
  *         (for more details refer to section above "Initialization/de-initialization functions")
  */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency)
{
//  uint32_t tickstart;

  /* Check Null pointer */
  if (RCC_ClkInitStruct == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_RCC_CLOCKTYPE(RCC_ClkInitStruct->ClockType));

  /*------------------------- SYSCLK Configuration ---------------------------*/
  /*-------------------------- HCLK Configuration --------------------------*/
  assert_param(IS_RCC_HCLK(RCC_ClkInitStruct->AHBCLKDivider));
  __HAL_RCC_SET_HCLK_DIV(RCC_ClkInitStruct->AHBCLKDivider);

  /*-------------------------- PCLK1 Configuration ---------------------------*/
  assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APBCLKDivider));
  __HAL_RCC_SET_PCLK_DIV(RCC_ClkInitStruct->APBCLKDivider);

  assert_param(IS_RCC_HCLKSOURCE(RCC_ClkInitStruct->SYSCLKSource));
  __HAL_RCC_HCLK_CONFIG(RCC_ClkInitStruct->SYSCLKSource);

  /* Update the SystemCoreClock global variable */
  SystemCoreClock = HAL_RCC_GetSysClockFreq(); 

  /* Configure the source of time base considering new system clocks settings*/
  return HAL_InitTick(uwTickPrio);
}

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions_Group1 Peripheral Control functions
  *  @brief   RCC clocks control functions
  *
  * @{
  */

/**
  * @brief  Return the SYSCLK frequency.
  *
  * @note   The system frequency computed by this function is not the real
  *         frequency in the chip. It is calculated based on the predefined
  *         constant and the selected clock source:
  * @note     If SYSCLK source is HSI, function returns values based on HSI_VALUE/HSIDIV(*)
  * @note     If SYSCLK source is HSE, function returns values based on HSE_VALUE(**)
  * @note     If SYSCLK source is PLL, function returns values based on HSE_VALUE(**),
  *           or HSI_VALUE(*) multiplied/divided by the PLL factors.
  * @note     If SYSCLK source is LSI, function returns values based on LSI_VALUE(***)
  * @note     If SYSCLK source is LSE, function returns values based on LSE_VALUE(****)
  * @note     (*) HSI_VALUE is a constant defined in xt32h0xx_hal_conf.h file (default value
  *               16 MHz) but the real value may vary depending on the variations
  *               in voltage and temperature.
  * @note     (**) HSE_VALUE is a constant defined in xt32h0xx_hal_conf.h file (default value
  *                8 MHz), user has to ensure that HSE_VALUE is same as the real
  *                frequency of the crystal used. Otherwise, this function may
  *                have wrong result.
  * @note     (***) LSE_VALUE is a constant defined in xt32h0xx_hal_conf.h file (default value
  *               32768 Hz).
  * @note     (****) LSI_VALUE is a constant defined in xt32h0xx_hal_conf.h file (default value
  *               32000 Hz).
  *
  * @note   The result of this function could be not correct when using fractional
  *         value for HSE crystal.
  *
  * @note   This function can be used by the user application to compute the
  *         baudrate for the communication peripherals or configure other parameters.
  *
  * @note   Each time SYSCLK changes, this function must be called to update the
  *         right SYSCLK value. Otherwise, any configuration based on this function will be incorrect.
  *
  *
  * @retval SYSCLK frequency
  */
uint32_t HAL_RCC_GetSysClockFreq(void)
{
	uint32_t hclkdiv = __HAL_RCC_GET_HCLK_DIV();
  uint32_t sysclockfreq = 0;

  if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_HCLKSOURCE_HSI)
  {
    /* HSI used as system clock source */
    sysclockfreq = HAL_RCC_GetHSIClockFreq();
  }
  else if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_HCLKSOURCE_HSE)
  {
    /* HSE used as system clock source */
    sysclockfreq = HAL_RCC_GetHSEClockFreq();
  }
  else if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_HCLKSOURCE_PLL)
  {
    /* PLL used as system clock  source */
    sysclockfreq = HAL_RCC_GetPLLClockFreq();
  }
  else if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_HCLKSOURCE_LS)
  {
    /* LSE used as system clock source */
    sysclockfreq = HAL_RCC_GetLSClockFreq();
  }
  else
  {
    sysclockfreq = 0U;
  }

  return (sysclockfreq / hclkdiv);
}

/**
  * @brief  Return the HCLK frequency.
  * @note   Each time HCLK changes, this function must be called to update the
  *         right HCLK value. Otherwise, any configuration based on this function will be incorrect.
  *
  * @note   The SystemCoreClock CMSIS variable is used to store System Clock Frequency.
  * @retval HCLK frequency in Hz
  */
uint32_t HAL_RCC_GetHCLKFreq(void)
{
  return HAL_RCC_GetSysClockFreq();
}

/**
  * @brief  Return the PCLK1 frequency.
  * @note   Each time PCLK1 changes, this function must be called to update the
  *         right PCLK1 value. Otherwise, any configuration based on this function will be incorrect.
  * @retval PCLK1 frequency in Hz
  */
uint32_t HAL_RCC_GetPCLKFreq(void)
{
  /* Get HCLK source and Compute PCLK1 frequency ---------------------------*/
	uint32_t pclkdiv = __HAL_RCC_GET_PCLK_DIV();
  uint32_t sysclockfreq;

  if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_HCLKSOURCE_HSI)
  {
    /* HSI used as system clock source */
    sysclockfreq = HAL_RCC_GetHSIClockFreq();
  }
  else if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_HCLKSOURCE_HSE)
  {
    /* HSE used as system clock source */
    sysclockfreq = HAL_RCC_GetHSEClockFreq();
  }
  else if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_HCLKSOURCE_PLL)
  {
    /* PLL used as system clock  source */
    sysclockfreq = HAL_RCC_GetPLLClockFreq();
  }
  else if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_HCLKSOURCE_LS)
  {
    /* LSE used as system clock source */
    sysclockfreq = HAL_RCC_GetLSClockFreq();
  }
  else
  {
    sysclockfreq = 0U;
  }

  return (sysclockfreq / pclkdiv);
}

/**
  * @brief  Get PLL clock frquency
  * @retval PLL frequency. The frequence can be 11000000 to 96000000. 0 means PLL is off.
  */
uint32_t HAL_RCC_GetPLLClockFreq(void)
{
	uint32_t freq = 0;
	
	uint32_t pllsource, pllm, pllvco, pllr;

	if(__HAL_RCC_PLL_GET_STATE() == RCC_PLL_ON)
	{
		/* PLL_VCO = ((HSE_VALUE or HSI_VALUE)/ PLLM) * PLLN
		SYSCLK = PLL_VCO / PLLR
		*/
		pllsource = __HAL_RCC_GET_PLL_OSCSOURCE(); 
		pllm = __HAL_RCC_PLL_GET_PLLM_VALUE(); 

		pllvco = 0;
		switch (pllsource)
		{
			case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
				if(__HAL_RCC_HSE_GET_STATE() == RCC_HSE_ON)
			    pllvco = (HSE_VALUE / pllm) * (__HAL_RCC_PLL_GET_PLLN_VALUE());
			  break;

			case RCC_PLLSOURCE_HSI:  /* HSI16 used as PLL clock source */
			default:                 /* HSI16 used as PLL clock source */
				if(__HAL_RCC_HSI_GET_STATE() == RCC_HSI_ON)
				  pllvco = (HSI_VALUE / pllm) * (__HAL_RCC_PLL_GET_PLLN_VALUE()) ;
				break;
		}
		pllr = ( __HAL_RCC_PLL_GET_PLLR_VALUE());
		freq = pllvco / pllr;
  }
	else
	{
		freq = 0;
	}
	
	return freq;
}

/**
  * @brief  Configure the RCC_OscInitStruct according to the internal
  *         RCC configuration registers.
  * @param  RCC_OscInitStruct  pointer to an RCC_OscInitTypeDef structure that
  *         will be configured.
  */
void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  /* Check the parameters */
  assert_param(RCC_OscInitStruct != (void *)NULL);

  /* Set all possible values for the Oscillator type parameter ---------------*/
  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI | \
                                      RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI;

  /* Get the HSE configuration -----------------------------------------------*/
  if (__HAL_RCC_HSE_GET_STATE() == RCC_HSE_ON)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_ON;
  }
  else
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_OFF;
  }

  /* Get the HSI configuration -----------------------------------------------*/
  if (__HAL_RCC_HSI_GET_STATE() == RCC_HSI_ON)
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_ON;
  }
  else
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_OFF;
  }
//  RCC_OscInitStruct->HSICalibrationValue = ((RCC->ICSCR & RCC_ICSCR_HSITRIM) >> RCC_ICSCR_HSITRIM_Pos);
//  RCC_OscInitStruct->HSIDiv = (RCC->CR & RCC_CR_HSIDIV);

  /* Get the LSE configuration -----------------------------------------------*/
  if (__HAL_RCC_LSE_GET_STATE() == RCC_LSE_ON)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_ON;
  }
  else
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_OFF;
  }

  /* Get the LSI configuration -----------------------------------------------*/
  if (__HAL_RCC_LSI_GET_STATE() == RCC_LSI_ON)
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_ON;
  }
  else
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_OFF;
  }

  /* Get the PLL configuration -----------------------------------------------*/
  if (__HAL_RCC_PLL_GET_STATE() == RCC_PLL_ON)
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_ON;
  }
  else
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_OFF;
  }
  //RCC_OscInitStruct->PLL.PLLSource = (RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
  RCC_OscInitStruct->PLL.PLLM = __HAL_RCC_PLL_GET_PLLM();
  RCC_OscInitStruct->PLL.PLLN = __HAL_RCC_PLL_GET_PLLN();
  RCC_OscInitStruct->PLL.PLLR = __HAL_RCC_PLL_GET_PLLR();
}

/**
  * @brief  Configure the RCC_ClkInitStruct according to the internal
  *         RCC configuration registers.
  * @param  RCC_ClkInitStruct Pointer to a @ref RCC_ClkInitTypeDef structure that
  *                           will be configured.
  * @param  pFLatency         Pointer on the Flash Latency.
  */
void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency)
{
  /* Check the parameters */
  assert_param(RCC_ClkInitStruct != (void *)NULL);

  /* Set all possible values for the Clock type parameter --------------------*/
  RCC_ClkInitStruct->ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK;

  /* Get the SYSCLK configuration --------------------------------------------*/
  RCC_ClkInitStruct->SYSCLKSource = (uint32_t)__HAL_RCC_GET_SYSCLK_SOURCE();

  /* Get the HCLK configuration ----------------------------------------------*/
  RCC_ClkInitStruct->AHBCLKDivider = (uint32_t)__HAL_RCC_GET_HCLK_DIV();

  /* Get the APB1 configuration ----------------------------------------------*/
  RCC_ClkInitStruct->APBCLKDivider = (uint32_t)__HAL_RCC_GET_PCLK_DIV();

}

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions_Group3 Extended Peripheral Control functions
  * @brief  Extended Peripheral Control functions
  *
@verbatim
 ===============================================================================
                ##### Extended Peripheral Control functions  #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the RCC Clocks
    frequencies.
    [..]
    (@) Important note: Care must be taken when @ref HAL_RCC_PeriphCLKConfig() is used to
        select the RTC clock source; in this case the Backup domain will be reset in
        order to modify the RTC Clock source, as consequence RTC registers (including
        the backup registers) and RCC_BDCR register are set to their reset values.

@endverbatim
  * @{
  */
/**
  * @brief  Initialize the RCC extended peripherals clocks according to the specified
  *         parameters in the @ref RCC_PeriphCLKInitTypeDef.
  * @param  PeriphClkInit  pointer to a @ref RCC_PeriphCLKInitTypeDef structure that
  *         contains a field PeriphClockSelection which can be a combination of the following values:
  *            @arg @ref RCC_PERIPHCLK_BR   
  *            @arg @ref RCC_PERIPHCLK_I2C1 
  *            @arg @ref RCC_PERIPHCLK_I2C2 
  *            @arg @ref RCC_PERIPHCLK_ADC  
  *            @arg @ref RCC_PERIPHCLK_RTC  
  *            @arg @ref RCC_PERIPHCLK_TIMAG
  *            @arg @ref RCC_PERIPHCLK_TIMB1
  *            @arg @ref RCC_PERIPHCLK_TIMB2
  *            @arg @ref RCC_PERIPHCLK_GPIO 
  *            @arg @ref RCC_PERIPHCLK_WDTW 
  *            @arg @ref RCC_PERIPHCLK_RTC  
  *
  * @note   (1) Peripherals are not available on all devices
  * @note   (2) Peripherals clock selection is not available on all devices
  * @note   Care must be taken when @ref HAL_RCC_PeriphCLKConfig() is used to select
  *         the RTC clock source: in this case the access to Backup domain is enabled.
  *
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCC_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  /* Check the parameters */
  assert_param(IS_RCC_PERIPHCLOCK(PeriphClkInit->PeriphClockSelection));

  /*-------------------------- RTC clock source configuration ----------------------*/
  if ((PeriphClkInit->PeriphClockSelection & RCC_PERIPHCLK_RTC) == RCC_PERIPHCLK_RTC)
  {
		assert_param(IS_RCC_RTCCLKSOURCE(PeriphClkInit->RtcClockSelection));
		
		__HAL_RCC_SET_LS_SOURCE(PeriphClkInit->RtcClockSelection);
  }

  /*-------------------------- USART1 clock source configuration -------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_BR) == RCC_PERIPHCLK_BR)
  {
    /* Check the parameters */
    assert_param(IS_RCC_BRCLKSOURCE(PeriphClkInit->BrClockSelection));

    /* Configure the USART1 clock source */
    __HAL_RCC_BR_CONFIG(PeriphClkInit->BrClockSelection);
  }

  /*-------------------------- I2C1 clock source configuration ---------------------*/
  if ((((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_I2C1) == RCC_PERIPHCLK_I2C1) \
   || (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_I2C2) == RCC_PERIPHCLK_I2C2))
  {
    /* Check the parameters */
    assert_param(IS_RCC_I2CCLKSOURCE(PeriphClkInit->I2cClockSelection));

    /* Configure the I2C1 clock source */
    __HAL_RCC_I2C_CONFIG(PeriphClkInit->I2cClockSelection);
  }

  /*-------------------------- WDTW clock source configuration ---------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_WDTW) == RCC_PERIPHCLK_WDTW)
  {
    /* Check the parameters */
    assert_param(IS_RCC_WDTWCLKSOURCE(PeriphClkInit->WdtwClockSelection));

    /* Configure the I2C1 clock source */
    __HAL_RCC_WDTW_CONFIG(PeriphClkInit->WdtwClockSelection);
  }

  /*-------------------------- Basic timer 1 clock source configuration ---------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIMB1) == RCC_PERIPHCLK_TIMB1)
  {
    /* Check the parameters */
    assert_param(IS_RCC_TIMB1CLKSOURCE(PeriphClkInit->BaseTimer1ClockSelection));

    /* Configure the I2C1 clock source */
    __HAL_RCC_TIMB1_CONFIG(PeriphClkInit->BaseTimer1ClockSelection);
  }

  /*-------------------------- Basic timer 2 clock source configuration ---------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIMB2) == RCC_PERIPHCLK_TIMB2)
  {
    /* Check the parameters */
    assert_param(IS_RCC_TIMB2CLKSOURCE(PeriphClkInit->BaseTimer2ClockSelection));

    /* Configure the I2C1 clock source */
    __HAL_RCC_TIMB2_CONFIG(PeriphClkInit->BaseTimer2ClockSelection);
  }

  /*-------------------------- GPIO clock source configuration ---------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_GPIO) == RCC_PERIPHCLK_GPIO)
  {
    /* Check the parameters */
    assert_param(IS_RCC_GPIOCLKSOURCE(PeriphClkInit->GpioClockSelection));

    /* Configure the I2C1 clock source */
    __HAL_RCC_GPIO_CONFIG(PeriphClkInit->GpioClockSelection);
  }

  /*-------------------------- Timer A/G clock source configuration ---------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_TIMAG) == RCC_PERIPHCLK_TIMAG)
  {
    /* Check the parameters */
    assert_param(IS_RCC_TIMAGCLKSOURCE(PeriphClkInit->TimerClockSelection));

    /* Configure the I2C1 clock source */
    __HAL_RCC_TIMAG_CONFIG(PeriphClkInit->TimerClockSelection);
  }

  /*-------------------------- ADC clock source configuration ----------------------*/
  if (((PeriphClkInit->PeriphClockSelection) & RCC_PERIPHCLK_ADC) == RCC_PERIPHCLK_ADC)
  {
    /* Check the parameters */
    assert_param(IS_RCC_ADCCLKSOURCE(PeriphClkInit->AdcClockSelection));

    /* Configure the ADC interface clock source */
    __HAL_RCC_ADC_CONFIG(PeriphClkInit->AdcClockSelection);

  }

  return status;
}

/**
  * @brief  Get the RCC_ClkInitStruct according to the internal RCC configuration registers.
  * @param  PeriphClkInit pointer to an RCC_PeriphCLKInitTypeDef structure that
  *         returns the configuration information for the Extended Peripherals
  *         clocks: I2C1, I2S1, USART1, RTC, ADC,
  *         LPTIM1 (1), LPTIM2 (1), TIM1 (2), TIM15 (1)(2), USART2 (2), LPUART1 (1), CEC (1) and RNG (1)
  * @note (1) Peripheral is not available on all devices
  * @note (2) Peripheral clock selection is not available on all devices
  */
void HAL_RCC_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit)
{
  /* Set all possible values for the extended clock type parameter------------*/
  PeriphClkInit->PeriphClockSelection = RCC_PERIPHCLK_BR | RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_GPIO | \
                                        RCC_PERIPHCLK_TIMB1 | RCC_PERIPHCLK_TIMB2 | RCC_PERIPHCLK_TIMAG | \
                                        RCC_PERIPHCLK_WDTW | RCC_PERIPHCLK_ADC;

  /* Get the UART clock source ---------------------------------------------*/
  PeriphClkInit->BrClockSelection  = __HAL_RCC_GET_BR_SOURCE();
  /* Get the I2C1 clock source -----------------------------------------------*/
  PeriphClkInit->I2cClockSelection    = __HAL_RCC_GET_I2C_SOURCE();
  /* Get the GPIO clock source -----------------------------------------------*/
  PeriphClkInit->GpioClockSelection    = __HAL_RCC_GET_GPIO_SOURCE();
  /* Get the TIMAG clock source ---------------------------------------------*/
  PeriphClkInit->TimerClockSelection  = __HAL_RCC_GET_TIMAG_SOURCE();
  /* Get the TIMB1 clock source ---------------------------------------------*/
  PeriphClkInit->BaseTimer1ClockSelection  = __HAL_RCC_GET_TIMB1_SOURCE();
  /* Get the TIMB2 clock source ---------------------------------------------*/
  PeriphClkInit->BaseTimer2ClockSelection  = __HAL_RCC_GET_TIMB2_SOURCE();
  /* Get the WDTW clock source -----------------------------------------------*/
  PeriphClkInit->WdtwClockSelection    = __HAL_RCC_GET_WDTW_SOURCE();
  /* Get the ADC clock source -----------------------------------------------*/
  PeriphClkInit->AdcClockSelection    = __HAL_RCC_GET_ADC_SOURCE();
}

/**
  * @brief  Return the peripheral clock frequency for peripherals with clock source from PLL
  * @note   Return 0 if peripheral clock identifier not managed by this API
  * @param  PeriphClk  Peripheral clock identifier
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_PERIPHCLK_BR   
  *            @arg @ref RCC_PERIPHCLK_I2C1 
  *            @arg @ref RCC_PERIPHCLK_I2C2 
  *            @arg @ref RCC_PERIPHCLK_ADC  
  *            @arg @ref RCC_PERIPHCLK_RTC  
  *            @arg @ref RCC_PERIPHCLK_TIMAG
  *            @arg @ref RCC_PERIPHCLK_TIMB1
  *            @arg @ref RCC_PERIPHCLK_TIMB2
  *            @arg @ref RCC_PERIPHCLK_GPIO 
  *            @arg @ref RCC_PERIPHCLK_WDTW 
  *            @arg @ref RCC_PERIPHCLK_RTC  
  * @note   (1) Peripheral not available on all devices
  * @note   (2) Peripheral Clock configuration not available on all devices
  * @retval Frequency in Hz
  */
uint32_t HAL_RCC_GetPeriphCLKFreq(uint32_t PeriphClk)
{
  uint32_t frequency = 0U;

  /* Check the parameters */
  assert_param(IS_RCC_PERIPHCLOCK(PeriphClk));

  if (PeriphClk == RCC_PERIPHCLK_RTC)
  {
		uint32_t srcclk;
    /* Get the current RTC source */
    srcclk = __HAL_RCC_GET_LS_SOURCE();

    /* Check if LSE is ready and if RTC clock selection is LSE */
    if (srcclk == RCC_LSSRC_LSE)
    {
      frequency = LSE_VALUE;
    }
    /* Check if LSI is ready and if RTC clock selection is LSI */
    else 
    {
      frequency = LSI_VALUE;
    }

    frequency = HSE_VALUE / __HAL_RCC_GET_RTC_REFCLK_DIV();
  }
  else
  {
    /* Other external peripheral clock source than RTC */

    /* Compute PLL clock input */
    {
      uint32_t pllvco, pllsource, pllr, pllm;  
      /* PLL used as system clock  source */
      /* PLL_VCO = ((HSE_VALUE or HSI_VALUE)/ PLLM) * PLLN
         SYSCLK = PLL_VCO / PLLR
      */
      pllsource = __HAL_RCC_GET_PLL_OSCSOURCE(); //(RCC->PLLCFGR & RCC_PLLCFGR_PLLSRC);
      pllm = __HAL_RCC_PLL_GET_PLLM_VALUE(); //((RCC->PLLCFGR & RCC_PLLCFGR_PLLM) >> RCC_PLLCFGR_PLLM_Pos) + 1U ;
  
      switch (pllsource)
      {
        case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
         pllvco = (HSE_VALUE / pllm) * (__HAL_RCC_PLL_GET_PLLN_VALUE());
         break;
  
        case RCC_PLLSOURCE_HSI:  /* HSI16 used as PLL clock source */
        default:                 /* HSI16 used as PLL clock source */
          pllvco = (HSI_VALUE / pllm) * (__HAL_RCC_PLL_GET_PLLN_VALUE()) ;
          break;
      }
      pllr = ( __HAL_RCC_PLL_GET_PLLR_VALUE());
      frequency = pllvco / pllr;
    }

    switch (PeriphClk)
    {
      case RCC_PERIPHCLK_BR:
        switch(__HAL_RCC_GET_BR_SOURCE())
        {
          case RCC_BRCLKSOURCE_HSE:
            frequency = HSE_VALUE;
            break;
          case RCC_BRCLKSOURCE_HSI:
            frequency = HSI_VALUE;
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_BR_CLK_DIV();
        break;
      case RCC_PERIPHCLK_I2C1:
        switch(__HAL_RCC_GET_I2C_SOURCE())
        {
          case RCC_I2CCLKSOURCE_HSE:
            frequency = HSE_VALUE;
            break;
          case RCC_I2CCLKSOURCE_HSI:
            frequency = HSI_VALUE;
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_I2C1_CLK_DIV();
        break;
      case RCC_PERIPHCLK_I2C2:
        switch(__HAL_RCC_GET_I2C_SOURCE())
        {
          case RCC_I2CCLKSOURCE_HSE:
            frequency = HSE_VALUE;
            break;
          case RCC_I2CCLKSOURCE_HSI:
            frequency = HSI_VALUE;
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_I2C2_CLK_DIV();
        break;
      case RCC_PERIPHCLK_GPIO:
        switch(__HAL_RCC_GET_GPIO_SOURCE())
        {
          case RCC_GPIOCLKSOURCE_HSE:
            frequency = HSE_VALUE;
            break;
          case RCC_GPIOCLKSOURCE_HSI:
            frequency = HSI_VALUE;
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_GPIO_CLK_DIV();
        break;
      case RCC_PERIPHCLK_TIMAG:
        switch(__HAL_RCC_GET_TIMAG_SOURCE())
        {
          case RCC_TIMAGCLKSOURCE_PCLK:
            frequency = HAL_RCC_GetPCLKFreq();
            break;
          case RCC_TIMAGCLKSOURCE_HCLK:
            frequency = HAL_RCC_GetHCLKFreq();
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_TIMER_ADV_CLK_DIV();
        break;
      case RCC_PERIPHCLK_TIMB1:
        switch(__HAL_RCC_GET_TIMB1_SOURCE())
        {
          case RCC_TIMB1CLKSOURCE_HCLK:
            frequency = HAL_RCC_GetHCLKFreq();
            break;
          case RCC_TIMB1CLKSOURCE_PCLK:
            frequency = HAL_RCC_GetPCLKFreq();
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_TIMER_B1_CLK_DIV();
        break;
      case RCC_PERIPHCLK_TIMB2:
        switch(__HAL_RCC_GET_TIMB2_SOURCE())
        {
          case RCC_TIMB2CLKSOURCE_HCLK:
            frequency = HAL_RCC_GetHCLKFreq();
            break;
          case RCC_TIMB2CLKSOURCE_PCLK:
            frequency = HAL_RCC_GetPCLKFreq();
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_TIMER_B2_CLK_DIV();
        break;
      case RCC_PERIPHCLK_WDTW:
        switch(__HAL_RCC_GET_WDTW_SOURCE())
        {
          case RCC_WDTWCLKSOURCE_HCLK:
            frequency = HAL_RCC_GetHCLKFreq();
            break;
          case RCC_WDTWCLKSOURCE_PCLK:
            frequency = HAL_RCC_GetPCLKFreq();
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_WDT_W_CLK_DIV();
        break;
      case RCC_PERIPHCLK_ADC:
        switch(__HAL_RCC_GET_ADC_SOURCE())
        {
          case RCC_ADCCLKSOURCE_HCLK:
            frequency = HAL_RCC_GetHCLKFreq();
            break;
          case RCC_ADCCLKSOURCE_PCLK:
            frequency = HAL_RCC_GetPCLKFreq();
            break;
          default:
            break;
        }
        frequency = frequency / __HAL_RCC_GET_ADC_CLK_DIV();
        break;
  		case RCC_PERIPHCLK_RTC:
  			frequency = LSI_VALUE / __HAL_RCC_GET_RTC_REFCLK_DIV();
  			break;
      default:
        break;
    }
  }

  return (frequency);
}

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group4
  * @{
  */
#if defined(XT32H0xxAMPW)  
/**
  * @brief  Calibrate HSI RC oscillator start.
  * @param  None
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_HSITuneStart(void)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  ICG->RC16M_CTRL = ( ICG_RC16M_CTRL_CBIAS_2 \
                    | ICG_RC16M_CTRL_CCOMP_2 \
                    | ICG_RC16M_CTRL_CCAP_6 | ICG_RC16M_CTRL_CCAP_0 \
                    | ICG_RC16M_CTRL_CRES_2 | ICG_RC16M_CTRL_CRES_1 | ICG_RC16M_CTRL_CRES_0);

  return status;
}

/**
  * @brief  Coarse tuning HSI RC oscillator.
  * @param  Code CBIAS value is one value between 0 to 0x7 
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_HSICoarseTuning(uint32_t Code)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CBIAS, Code);

  return status;
}

/**
  * @brief  Fine tuning HSI RC oscillator.
  * @param  Code CCAP value is one value between 0 to 0x7F
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_HSIFineTuning(uint32_t Code)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  MODIFY_REG(ICG->RC16M_CTRL, ICG_RC16M_CTRL_CCAP, Code);

  return status;
}

/**
  * @brief  Calibrate LSI RC oscillator start.
  * @param  None
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_LSITuneStart(void)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_RESTUNE, AON_CLKCTRL_32KRC_RESTUNE_5);

  return status;
}

/**
  * @brief  Tuning LSI RC oscillator.
  * @param  Code
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_LSITuning(uint32_t Code)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  MODIFY_REG(AON->AON_CLK_CTRL, AON_CLKCTRL_32KRC_RESTUNE, Code);
 
  return status;
}

/**
  * @brief  Calibrate PLL start.
  * @param  None
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_PLLTuneStart(void)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  /* set default value*/
  ICG->PLL_DIV         = 0xC20C6002UL;
  ICG->PLL_PD_CTRL     = 0x08010000UL;
  ICG->PLL_LFCFG_CTRL  = 0x060128D4UL;
  ICG->PLL_VCOCAL_CTRL = 0x05140540UL;
  ICG->PLL_IREF_CTRL   = 0x00000043UL;

  /* turn off pll calibrate */
  CLEAR_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCOCAL_EN);

  /* config calibration */
  MODIFY_REG(ICG->PLL_VCOCAL_CTRL, ICG_VCOCAL_CAL_ITVL|ICG_VCOCAL_INI_VAL,
             ICG_VCOCAL_CAL_ITVL_0 | ICG_VCOCAL_INI_VAL_6 );

  /* enable pll test clock */
  SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_PLLCLKTST_EN);

  /* turn on pll calibrate */
  SET_BIT(ICG->PLL_PD_CTRL, ICG_PLL_VCOCAL_EN);

  /* calibrate need to wait 10 ms */

  return status;
}

/**
  * @brief  Tuning PLL.
  * @param  LFCode IF value is one value between 0 to 0xFFFFFF
  * @param  IRefCode IRef value is one value between 0 to 0x7
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_PLLTuning(uint32_t LFCode, uint32_t IRefCode)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  MODIFY_REG(ICG->PLL_LFCFG_CTRL, ICG_PLL_IF_CTRL, LFCode);
  MODIFY_REG(ICG->PLL_IREF_CTRL, ICG_IREF_CTRL, IRefCode);
 
  return status;
}

#endif /*XT32H0xxAMPW*/

#if defined(XT32H0xxB) 
/**
  * @brief  Configure DeepSleep.
  * @param  pConfig 
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_DeepSleepConfig(RCC_DeepSleepInitTypeDef *pConfig)
{
  HAL_StatusTypeDef status = HAL_OK;   /* Final status */

  AON->DEEPSLEEP_TIME = pConfig->TimerCount;
  MODIFY_REG(AON->DEEPSLEEP_CTRL, AON_DEEPSLEEP_CTRL_EXT_WAKEUP, pConfig->ExternalWakeup);
  
  return status;
}  

/**
  * @brief  Enable DeepSleep.
  */
void HAL_RCC_DeepSleepStart(void)
{
  SET_BIT(AON->DEEPSLEEP_CTRL, AON_DEEPSLEEP_CTRL_MODE);
}
#endif /* XT32H0xxB */  

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group5
  * @{
  */

/**
  * @brief  Change PLL config.
  * @param  PllClk a pointer to pll config
  * @retval status
  */
HAL_StatusTypeDef HAL_RCC_ChangePLLClk(RCC_PLLInitTypeDef  *PllClk)
{
#if defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW)
  uint32_t pll_src;

  uint32_t sys_src;
  uint32_t alt_sys_src;

  /* check parameters */
  assert_param(IS_RCC_PLLM(PllClk->PLLM));
  assert_param(IS_RCC_PLLN(PllClk->PLLN));
  assert_param(IS_RCC_PLLR(PllClk->PLLR));

  /* get pll source */
  pll_src = __HAL_RCC_GET_PLL_OSCSOURCE();
  if(pll_src == RCC_PLLSOURCE_HSI)
  {
    alt_sys_src = RCC_SYSCLKSOURCE_HSI;
  }
  else
  {
    alt_sys_src = RCC_SYSCLKSOURCE_HSE;
  }

  /* get system clock source */
  sys_src = __HAL_RCC_GET_SYSCLK_SOURCE();
  if(sys_src == RCC_SYSCLKSOURCE_PLL)
  {
    __HAL_RCC_SYSCLK_CONFIG(alt_sys_src);
  }

  /* check all peripheral clk source */

  /* change pll config*/
  __HAL_RCC_PLL_CONFIG(PllClk->PLLM, PllClk->PLLN, PllClk->PLLR);

  /* wait pll */

  /* recoverage system clk */
  if(sys_src == RCC_SYSCLKSOURCE_PLL)
  {
    __HAL_RCC_SYSCLK_CONFIG(sys_src);
  }

  /* recoverage peripheral clk */

#endif /* XT32H0xxAMPW || XT32H0xxBMPW */
  return HAL_OK;
}

/**
  * @}
  */

/**
  * @}
  */

/* Private functions --------------------------------------------------------*/

/** @defgroup RCC_Private_Functions RCC Private Functions
  * @{
  */

/**
  * @brief  Get HSI clock frquency
  * @retval can be 0 to 0xFFFFFFFF
  */
static uint32_t HAL_RCC_GetHSIClockFreq(void)
{
	uint32_t freq = 0;
	
	if(__HAL_RCC_HSI_GET_STATE() == RCC_HSI_ON)
	{
	  freq = HSI_VALUE;
	}
	
  return 	freq;
}

/**
  * @brief  Get HSE clock frquency
  * @retval can be 0 to 0xFFFFFFFF
  */
static uint32_t HAL_RCC_GetHSEClockFreq(void)
{
	uint32_t freq = 0;
	
	if(__HAL_RCC_HSE_GET_STATE() == RCC_HSE_ON)
	{
	  freq = HSE_VALUE;
	}
	
  return 	freq;
}

/**
  * @brief  Get LS clock frquency
  * @retval can be 0 to 0xFFFFFFFF
  */
static uint32_t HAL_RCC_GetLSClockFreq(void)
{
	uint32_t freq = 0;
	
	if((__HAL_RCC_LSE_GET_STATE() == RCC_LSE_ON) && (__HAL_RCC_GET_LS_SOURCE() == RCC_LSSRC_LSE))
	{
	  freq = LSE_VALUE;
	}
	else if ((__HAL_RCC_LSI_GET_STATE() == RCC_LSI_ON) && (__HAL_RCC_GET_LS_SOURCE() == RCC_LSSRC_LSI))
	{
		freq = LSI_VALUE;
	}
	else
	{
		freq = 0;
	}
	
  return 	freq;
}

/**
  * @}
  */

#endif /* HAL_RCC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
