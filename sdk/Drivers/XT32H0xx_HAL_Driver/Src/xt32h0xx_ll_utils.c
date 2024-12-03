/**
  ******************************************************************************
  * @file    xt32h0xx_ll_utils.c
  * @author  Software Team
  * @brief   UTILS LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_utils.h"
#include "xt32h0xx_ll_rcc.h"
#include "xt32h0xx_ll_system.h"
#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

/** @addtogroup UTILS_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @addtogroup UTILS_LL_Private_Constants
  * @{
  */
#define UTILS_MAX_FREQUENCY          96000000U     /*!< Maximum frequency for system clock, in Hz */

/* Defines used for PLL range */
//#define UTILS_PLLVCO_INPUT_MIN       4000000U      /*!< Frequency min for PLLVCO input, in Hz   */
//#define UTILS_PLLVCO_INPUT_MAX       8000000U      /*!< Frequency max for PLLVCO input, in Hz   */
//#define UTILS_PLLVCO_OUTPUT_MIN      64000000U     /*!< Frequency min for PLLVCO output, in Hz  */
//#define UTILS_PLLVCO_OUTPUT_MAX      344000000U    /*!< Frequency max for PLLVCO output, in Hz  */

/* Defines used for HSE range */
#define UTILS_HSE_FREQUENCY_MIN      4000000U      /*!< Frequency min for HSE frequency, in Hz   */
#define UTILS_HSE_FREQUENCY_MAX      48000000U     /*!< Frequency max for HSE frequency, in Hz   */

/* Defines used for FLASH latency according to HCLK Frequency */
//#define UTILS_SCALE1_LATENCY1_FREQ  75000000U       /*!< HCLK frequency to set FLASH latency 1 in power scale 1  */
//#define UTILS_SCALE1_LATENCY2_FREQ  48000000U       /*!< HCLK frequency to set FLASH latency 2 in power scale 1  */
//#define UTILS_SCALE1_LATENCY3_FREQ  64000000U       /*!< HCLK frequency to set FLASH latency 3 in power scale 1  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup UTILS_LL_Private_Macros
  * @{
  */
#define IS_LL_UTILS_PLLM_VALUE(__VALUE__) (((__VALUE__) == LL_RCC_PLLM_DIV2) \
                                        || ((__VALUE__) == LL_RCC_PLLM_DIV4) \
                                        || ((__VALUE__) == LL_RCC_PLLM_DIV8) \
                                        || ((__VALUE__) == LL_RCC_PLLM_DIV12))

#define IS_LL_UTILS_PLLN_VALUE(__VALUE__) (((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_99M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_98M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_97M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_96M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_95M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_94M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_93M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_92M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_91M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_90M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_89M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_88M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_87M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_86M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_85M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_84M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_83M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_82M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_81M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_80M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_79M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_78M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_77M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_76M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_75M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_74M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_73M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_72M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_71M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_70M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_69M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_68M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_67M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_66M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_65M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_64M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_62M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_60M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_58M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_56M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_54M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_52M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_50M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_49M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_48M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_47M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_46M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_45M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_44M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_43M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_42M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_41M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_40M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_39M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_38M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_37M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_36M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_35M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_34M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_33M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_32M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_31M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_30M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_29M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_28M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_27M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_26M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_25M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_24M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_23M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_22M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_21M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_20M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_19M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_18M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_17M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_16M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_15M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_14M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_13M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_12M) \
                                        || ((__VALUE__) == LL_RCC_PLLN_DIV_FREQ_11M))           

#if defined(XT32H0xxAMPW)
#define IS_LL_UTILS_PLLR_VALUE(__VALUE__) (((__VALUE__) == LL_RCC_PLLR_DIV4) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV6) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV8) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV12) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV16) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV24))
#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxA) || defined(XT32H0xxB))
#define IS_LL_UTILS_PLLR_VALUE(__VALUE__) (((__VALUE__) == LL_RCC_PLLR_DIV4) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV6) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV8) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV12) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV16) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV24) \
                                        || ((__VALUE__) == LL_RCC_PLLR_DIV48))
#endif /* XT32H0xxBMPW || XT32H0xxA || XT32H0xxB */

//#define IS_LL_UTILS_PLLVCO_INPUT(__VALUE__)  ((UTILS_PLLVCO_INPUT_MIN <= (__VALUE__)) && ((__VALUE__) <= UTILS_PLLVCO_INPUT_MAX))

//#define IS_LL_UTILS_PLLVCO_OUTPUT(__VALUE__) ((UTILS_PLLVCO_OUTPUT_MIN <= (__VALUE__)) && ((__VALUE__) <= UTILS_PLLVCO_OUTPUT_MAX))

#define IS_LL_UTILS_PLL_FREQUENCY(__VALUE__) ((__VALUE__) <= UTILS_MAX_FREQUENCY)

//#define IS_LL_UTILS_HSE_BYPASS(__STATE__) (((__STATE__) == LL_UTILS_HSEBYPASS_ON) \
                                        || ((__STATE__) == LL_UTILS_HSEBYPASS_OFF))

#define IS_LL_UTILS_HSE_FREQUENCY(__FREQUENCY__) (((__FREQUENCY__) >= UTILS_HSE_FREQUENCY_MIN) && ((__FREQUENCY__) <= UTILS_HSE_FREQUENCY_MAX))
/**
  * @}
  */
/* Private function prototypes -----------------------------------------------*/
/** @defgroup UTILS_LL_Private_Functions UTILS Private functions
  * @{
  */
//static uint32_t    UTILS_GetPLLOutputFrequency(uint32_t PLL_InputFrequency,
//                                               LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct);
//static ErrorStatus UTILS_EnablePLLAndSwitchSystem(uint32_t SYSCLK_Frequency, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct);
//static ErrorStatus UTILS_PLL_IsBusy(void);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup UTILS_LL_Exported_Functions
  * @{
  */

/** @addtogroup UTILS_LL_EF_DELAY
  * @{
  */

/**
  * @brief  This function configures the Cortex-M SysTick source to have 1ms time base.
  * @note   When a RTOS is used, it is recommended to avoid changing the Systick
  *         configuration by calling this function, for a delay use rather osDelay RTOS service.
  * @param  HCLKFrequency HCLK frequency in Hz
  */
void LL_Init1msTick(uint32_t HCLKFrequency)
{
  /* Use frequency provided in argument */
  LL_InitTick(HCLKFrequency, 1000U);
}

/**
  * @brief  This function provides accurate delay (in milliseconds) based
  *         on SysTick counter flag
  * @note   When a RTOS is used, it is recommended to avoid using blocking delay
  *         and use rather osDelay service.
  * @note   To respect 1ms timebase, user should call @ref LL_Init1msTick function which
  *         will configure Systick to 1ms
  * @param  Delay specifies the delay time length, in milliseconds.
  */
void LL_mDelay(uint32_t Delay)
{
  __IO uint32_t  tmp = SysTick->CTRL;  /* Clear the COUNTFLAG first */
   uint32_t tmpDelay; /* MISRAC2012-Rule-17.8 */
  /* Add this code to indicate that local variable is not used */
  ((void)tmp);
  tmpDelay  = Delay;
  /* Add a period to guaranty minimum wait */
  if (tmpDelay  < LL_MAX_DELAY)
  {
    tmpDelay ++;
  }

  while (tmpDelay  != 0U)
  {
    if ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) != 0U)
    {
      tmpDelay --;
    }
  }
}

/**
  * @}
  */

/** @addtogroup UTILS_EF_SYSTEM
  *  @brief    System Configuration functions
  *
  * @{
  */

/**
  * @brief  This function sets directly SystemCoreClock CMSIS variable.
  * @note   Variable can be calculated also through SystemCoreClockUpdate function.
  * @param  HCLKFrequency HCLK frequency in Hz (can be calculated thanks to RCC helper macro)
  */
void LL_SetSystemCoreClock(uint32_t HCLKFrequency)
{
  /* HCLK clock frequency */
  SystemCoreClock = HCLKFrequency;
}

/**
  * @brief  This function configures system clock at maximum frequency with HSI as clock source of the PLL
  * @note   The application need to ensure that PLL is disabled.
  * @note   Function is based on the following formula:
  *         - PLL output frequency = (((HSI frequency / PLLM) * PLLN) / PLLR)
  *         - PLLM: ensure that the VCO input frequency ranges from 4 to 16 MHz (PLLVCO_input = HSI frequency / PLLM)
  *         - PLLN: ensure that the VCO output frequency is between 64 and 344 MHz (PLLVCO_output = PLLVCO_input * PLLN)
  *         - PLLR: ensure that max frequency at 64000000 Hz is reach (PLLVCO_output / PLLR)
  * @param  UTILS_PLLInitStruct pointer to a @ref LL_UTILS_PLLInitTypeDef structure that contains
  *                             the configuration information for the PLL.
  * @param  UTILS_ClkInitStruct pointer to a @ref LL_UTILS_ClkInitTypeDef structure that contains
  *                             the configuration information for the BUS prescalers.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: Max frequency configuration done
  *          - ERROR: Max frequency configuration not done
  */
ErrorStatus LL_PLL_ConfigSystemClock_HSI(LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct,
                                         LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct)
{
  ErrorStatus status = SUCCESS;

  CLEAR_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSRC);  //enable HSI

  /* Check if one of the PLL is enabled */
  if(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSRC) == LL_RCC_HCLK_SRC_PLL)
  {
    MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSRC, LL_RCC_HCLK_SRC_HSI);

    //calibrate 
  }
  
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSRC, LL_RCC_HCLK_SRC_HSI);

  ICG->HCLK_DIV = UTILS_ClkInitStruct->AHBCLKDivider;
  ICG->PCLK_DIV = UTILS_ClkInitStruct->APBCLKDivider;

  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_PLL, LL_RCC_PLL_ENABLE);

  MODIFY_REG(ICG->PLL_LFCFG_CTRL, ICG_PLL_CLKSRC, LL_RCC_PLL_SRC_HSI); //set PLL source HSI

  MODIFY_REG(ICG->PLL_DIV, \
             (ICG_PLL_PREDIV | ICG_PLL_FBDIV | ICG_PLL_POSTDIV),   \
             ((UTILS_PLLInitStruct->PLLN) | (UTILS_PLLInitStruct->PLLM) | (UTILS_PLLInitStruct->PLLR)));

  return status;
}

/**
  * @brief  This function configures system clock with HSE as clock source of the PLL
  * @note   The application need to ensure that PLL is disabled.
  * @note   Function is based on the following formula:
  *         - PLL output frequency = (((HSE frequency / PLLM) * PLLN) / PLLR)
  *         - PLLM: ensure that the VCO input frequency ranges from 4 to 16 MHz (PLLVCO_input = HSE frequency / PLLM)
  *         - PLLN: ensure that the VCO output frequency is between 64 and 344 MHz (PLLVCO_output = PLLVCO_input * PLLN)
  *         - PLLR: ensure that max frequency at 64000000 Hz is reached (PLLVCO_output / PLLR)
  * @param  HSEFrequency Value between Min_Data = 4000000 and Max_Data = 48000000
  * @param  UTILS_PLLInitStruct pointer to a @ref LL_UTILS_PLLInitTypeDef structure that contains
  *                             the configuration information for the PLL.
  * @param  UTILS_ClkInitStruct pointer to a @ref LL_UTILS_ClkInitTypeDef structure that contains
  *                             the configuration information for the BUS prescalers.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: Max frequency configuration done
  *          - ERROR: Max frequency configuration not done
  */
ErrorStatus LL_PLL_ConfigSystemClock_HSE(uint32_t HSEFrequency, 
                                         LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct, LL_UTILS_ClkInitTypeDef *UTILS_ClkInitStruct)
{
  ErrorStatus status = SUCCESS;
  uint32_t pllfreq;

  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSXTAL|ICG_CLK_CTL_HSXTALOUT, 0);  //enable HSI

  /* Check if one of the PLL is enabled */
  if(READ_BIT(ICG->CLK_CFG, ICG_CLK_CTL_HSRC) == LL_RCC_HCLK_SRC_PLL)
  {
    MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSRC, LL_RCC_HCLK_SRC_HSE);

    //calibrate 
  }
  
  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_HSRC, LL_RCC_HCLK_SRC_HSE);

  ICG->HCLK_DIV = UTILS_ClkInitStruct->AHBCLKDivider;
  ICG->PCLK_DIV = UTILS_ClkInitStruct->APBCLKDivider;

  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_PLL, LL_RCC_PLL_ENABLE);

  MODIFY_REG(ICG->PLL_LFCFG_CTRL, ICG_PLL_CLKSRC, LL_RCC_PLL_SRC_HSE); //set PLL source HSI

  MODIFY_REG(ICG->PLL_DIV, \
             (ICG_PLL_PREDIV | ICG_PLL_FBDIV | ICG_PLL_POSTDIV),   \
             ((UTILS_PLLInitStruct->PLLN << ICG_PLL_FBDIV_Pos) | (UTILS_PLLInitStruct->PLLM << ICG_PLL_PREDIV_Pos) | (UTILS_PLLInitStruct->PLLR << ICG_PLL_POSTDIV_Pos)));

  return status;
}

/**
  * @brief  Update number of Flash wait states in line with new frequency and current
  *         voltage range.
  * @param  HCLKFrequency  HCLK frequency
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: Latency has been modified
  *          - ERROR: Latency cannot be modified
  */
ErrorStatus LL_SetFlashLatency(uint32_t HCLKFrequency)
{
  ErrorStatus status = SUCCESS;

#if defined(XT32H0xxB)
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_ACCWAIT, FLASH_CTRL_ACCWAIT_1);
#endif /* XT32H0xxB */

  return status;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup UTILS_LL_Private_Functions
  * @{
  */

/**
  * @brief  Function to check that PLL can be modified
  * @param  PLL_InputFrequency  PLL input frequency (in Hz)
  * @param  UTILS_PLLInitStruct pointer to a @ref LL_UTILS_PLLInitTypeDef structure that contains
  *                             the configuration information for the PLL.
  * @retval PLL output frequency (in Hz)
  */
static uint32_t UTILS_GetPLLOutputFrequency(uint32_t PLL_InputFrequency, LL_UTILS_PLLInitTypeDef *UTILS_PLLInitStruct)
{
  uint32_t pllfreq;

  /* Check the parameters */
  assert_param(IS_LL_UTILS_PLLM_VALUE(UTILS_PLLInitStruct->PLLM));
  assert_param(IS_LL_UTILS_PLLN_VALUE(UTILS_PLLInitStruct->PLLN));
  assert_param(IS_LL_UTILS_PLLR_VALUE(UTILS_PLLInitStruct->PLLR));

  /* Check different PLL parameters according to RM                          */
  /*  - PLLM: ensure that the VCO input frequency ranges from 4 to 16 MHz.   */
  pllfreq = PLL_InputFrequency / __LL_RCC_PLLM_VALUE(UTILS_PLLInitStruct->PLLM);

  /*  - PLLN: ensure that the VCO output frequency is between 64 and 344 MHz.*/
  pllfreq = pllfreq * __LL_RCC_PLLR_VALUE(UTILS_PLLInitStruct->PLLN);

  /*  - PLLR: ensure that max frequency at 64000000 Hz is reached                   */
  pllfreq = pllfreq / __LL_RCC_PLLR_VALUE(UTILS_PLLInitStruct->PLLR);

  return pllfreq;
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
