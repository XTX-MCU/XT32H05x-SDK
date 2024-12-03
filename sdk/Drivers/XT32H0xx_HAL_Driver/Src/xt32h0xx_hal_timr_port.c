/**
  ******************************************************************************
  * @file    xt32h0xx_hal_timr_port.c
  * @author  Software Team
  * @brief   TIM HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Timer (TIM) peripheral:
  *           + TIM Time Base Initialization
  *           + TIM Time Base Start
  *           + TIM Time Base Start Interruption
  *           + TIM External Clock configuration
  @verbatim
  ==============================================================================
                      ##### TIMER Generic features #####
  ==============================================================================
  [..] The Timer features include:
       (#) 32-bit down counter.

            ##### How to use this driver #####
  ==============================================================================
    [..]
     (#) Initialize the TIM low level resources by implementing the following functions
         depending on the selected feature:
           (++) Time Base : HAL_TIMR_Base_MspInit()
           (++) Input Capture : HAL_TIMR_IC_MspInit()
           (++) Output Compare : HAL_TIMR_OC_MspInit()
           (++) PWM generation : HAL_TIMR_PWM_MspInit()
           (++) One-pulse mode output : HAL_TIMR_OnePulse_MspInit()
           (++) Encoder mode output : HAL_TIMR_Encoder_MspInit()

     (#) Initialize the TIM low level resources :
        (##) Enable the TIM interface clock using __HAL_RCC_TIMx_CLK_ENABLE();
        (##) TIM pins configuration
            (+++) Enable the clock for the TIM GPIOs using the following function:
             __HAL_RCC_GPIOx_CLK_ENABLE();
            (+++) Configure these TIM pins in Alternate function mode using HAL_GPIO_Init();

     (#) The external Clock can be configured, if needed (the default clock is the
         internal clock from the APBx), using the following function:
         HAL_TIMR_ConfigClockSource, the clock configuration should be done before
         any start function.

     (#) Configure the TIM in the desired functioning mode using one of the
       Initialization function of this driver:
       (++) HAL_TIMR_Base_Init: to use the Timer to generate a simple time base
       (++) HAL_TIMR_OC_Init and HAL_TIMR_OC_ConfigChannel: to use the Timer to generate an
            Output Compare signal.
       (++) HAL_TIMR_PWM_Init and HAL_TIMR_PWM_ConfigChannel: to use the Timer to generate a
            PWM signal.
       (++) HAL_TIMR_IC_Init and HAL_TIMR_IC_ConfigChannel: to use the Timer to measure an
            external signal.
       (++) HAL_TIMR_OnePulse_Init and HAL_TIMR_OnePulse_ConfigChannel: to use the Timer
            in One Pulse Mode.
       (++) HAL_TIMR_Encoder_Init: to use the Timer Encoder Interface.

     (#) Activate the TIM peripheral using one of the start functions depending from the feature used:
           (++) Time Base : HAL_TIMR_Base_Start(), HAL_TIMR_Base_Start_DMA(), HAL_TIMR_Base_Start_IT()
           (++) Input Capture :  HAL_TIMR_IC_Start(), HAL_TIMR_IC_Start_DMA(), HAL_TIMR_IC_Start_IT()
           (++) Output Compare : HAL_TIMR_OC_Start(), HAL_TIMR_OC_Start_DMA(), HAL_TIMR_OC_Start_IT()
           (++) PWM generation : HAL_TIMR_PWM_Start(), HAL_TIMR_PWM_Start_DMA(), HAL_TIMR_PWM_Start_IT()
           (++) One-pulse mode output : HAL_TIMR_OnePulse_Start(), HAL_TIMR_OnePulse_Start_IT()
           (++) Encoder mode output : HAL_TIMR_Encoder_Start(), HAL_TIMR_Encoder_Start_DMA(), HAL_TIMR_Encoder_Start_IT().

     (#) The DMA Burst is managed with the two following functions:
         HAL_TIMR_DMABurst_WriteStart()
         HAL_TIMR_DMABurst_ReadStart()

    *** Callback registration ***
  =============================================

  [..]
  The compilation define  USE_HAL_TIMR_REGISTER_CALLBACKS when set to 1
  allows the user to configure dynamically the driver callbacks.

  [..]
  Use Function @ref HAL_TIMR_RegisterCallback() to register a callback.
  @ref HAL_TIMR_RegisterCallback() takes as parameters the HAL peripheral handle,
  the Callback ID and a pointer to the user callback function.

  [..]
  Use function @ref HAL_TIMR_UnRegisterCallback() to reset a callback to the default
  weak function.
  @ref HAL_TIMR_UnRegisterCallback takes as parameters the HAL peripheral handle,
  and the Callback ID.

  [..]
  These functions allow to register/unregister following callbacks:
    (+) Base_MspInitCallback              : TIM Base Msp Init Callback.
    (+) Base_MspDeInitCallback            : TIM Base Msp DeInit Callback.
    (+) Tim_Callback                      : TIM Callback.

  [..]
By default, after the Init and when the state is HAL_TIMR_STATE_RESET
all interrupt callbacks are set to the corresponding weak functions:
  examples @ref HAL_TIMR_TriggerCallback(), @ref HAL_TIMR_ErrorCallback().

  [..]
  Exception done for MspInit and MspDeInit functions that are reset to the legacy weak
  functionalities in the Init / DeInit only when these callbacks are null
  (not registered beforehand). If not, MspInit or MspDeInit are not null, the Init / DeInit
    keep and use the user MspInit / MspDeInit callbacks(registered beforehand)

  [..]
    Callbacks can be registered / unregistered in HAL_TIMR_STATE_READY state only.
    Exception done MspInit / MspDeInit that can be registered / unregistered
    in HAL_TIMR_STATE_READY or HAL_TIMR_STATE_RESET state,
    thus registered(user) MspInit / DeInit callbacks can be used during the Init / DeInit.
  In that case first register the MspInit/MspDeInit user callbacks
      using @ref HAL_TIMR_RegisterCallback() before calling DeInit or Init function.

  [..]
      When The compilation define USE_HAL_TIMR_REGISTER_CALLBACKS is set to 0 or
      not defined, the callback registration feature is not available and all callbacks
      are set to the corresponding weak functions.

  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup TIMRPort 
  * @brief TIMR HAL module driver
  * @{
  */

#ifdef HAL_TIMR_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup TIMRPort_Private_Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup TIMRPort_Private_Functions
  * @{
  */
/**
  * @}
  */
/* Exported functions --------------------------------------------------------*/

/** @defgroup TIMRPort_Exported_Functions TIMRPort Exported Functions
  * @{
  */
/** @defgroup TIMRPort_Exported_Functions_Group1 TIMR Peripheral Port functions
  *  @brief  Peripheral Port functions
  * @{
  */
/* Peripheral port functions  ************************************************/
/**
  * @brief  Config the TIM Base output pad.
  * @param  htim TIM Base handle
  * @param  Pad port pad
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_TIMR_OutputPortConfig(TIMR_HandleTypeDef *htim, uint32_t Pad)
{
#if defined(XT32H0xxB)  
  if(htim->Instance == TIMB11)
  {
    if(Pad == PADI_IDX_IO41_BTOUT11)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO41_BTOUT11, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO41_BTOUT11, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO41_BTOUT11, PADI_CFG_IO41_BTOUT11);
      SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 9);   //aux output PB9
      GPIOB->CTL |= (GPIO_SRC_HW << 9);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
  
    return HAL_OK;

  }
  else if(htim->Instance == TIMB12)
  {
    if(Pad == PADI_IDX_IO42_BTOUT12)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO42_BTOUT12, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO42_BTOUT12, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO42_BTOUT12, PADI_CFG_IO42_BTOUT12);
      SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 8);   //aux output PB8
      GPIOB->CTL |= (GPIO_SRC_HW << 8);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
  
    return HAL_OK;

  }
  else if(htim->Instance == TIMB13)
  {
    if(Pad == PADI_IDX_IO37_BTOUT13)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO37_BTOUT13, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO37_BTOUT13, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO37_BTOUT13, PADI_CFG_IO37_BTOUT13);
      SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 13);   //aux output PB13
      GPIOB->CTL |= (GPIO_SRC_HW << 13);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
  
    return HAL_OK;

  }
  else if(htim->Instance == TIMB14)
  {
    if(Pad == PADI_IDX_IO17_BTOUT14)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO17_BTOUT14, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO17_BTOUT14, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO17_BTOUT14, PADI_CFG_IO17_BTOUT14);
      SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 25);   //aux output PB25
      GPIOB->CTL |= (GPIO_SRC_HW << 25);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
  
    return HAL_OK;

  }
  else if(htim->Instance == TIMB21)
  {
    if(Pad == PADI_IDX_IO3_BTOUT21)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO3_BTOUT21, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO3_BTOUT21, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO3_BTOUT21, PADI_CFG_IO3_BTOUT21);
      SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 2);   //aux output PC2
      GPIOC->CTL |= (GPIO_SRC_HW << 2);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
  
    return HAL_OK;

  }
  else if(htim->Instance == TIMB22)
  {
    if(Pad == PADI_IDX_IO27_BTOUT22)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO27_BTOUT22, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO27_BTOUT22, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO27_BTOUT22, PADI_CFG_IO27_BTOUT22);
      SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 5);   //aux output PB5
      GPIOB->CTL |= (GPIO_SRC_HW << 5);   //Hardware Source
    }
    else if(Pad == PADI_IDX_IO40_BTOUT22)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO40_BTOUT22, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO40_BTOUT22, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO40_BTOUT22, PADI_CFG_IO40_BTOUT22);
      SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 10);   //aux output PB10
      GPIOB->CTL |= (GPIO_SRC_HW << 10);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
  
    return HAL_OK;

  }
  else if(htim->Instance == TIMB23)
  {
    if(Pad == PADI_IDX_IO26_BTOUT23)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO26_BTOUT23, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO26_BTOUT23, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO26_BTOUT23, PADI_CFG_IO26_BTOUT23);
      SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 6);   //aux output PB6
      GPIOB->CTL |= (GPIO_SRC_HW << 6);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
  
    return HAL_OK;

  }
  else if(htim->Instance == TIMB24)
  {
    if(Pad == PADI_IDX_IO4_BTOUT24)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO4_BTOUT24, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO4_BTOUT24, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO4_BTOUT24, PADI_CFG_IO4_BTOUT24);
      SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 1);   //aux output PC1
      GPIOC->CTL |= (GPIO_SRC_HW << 1);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
  
    return HAL_OK;

  }
  else
  {
    return HAL_ERROR;
  }
#else
  return HAL_OK;
#endif /* XT32H0xxB */  
}

/**
  * @brief  Config the TIM Base input pad.
  * @param  htim TIM Base handle
  * @param  Pad port pad
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_TIMR_InputPortConfig(TIMR_HandleTypeDef *htim, uint32_t Pad)
{
#if defined(XT32H0xxB)   
  if(htim->Instance == TIMB11)
  {
    if (Pad == PADI_IDX_IO41_BTIN11)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO41_BTIN11, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO41_BTIN11, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO41_BTIN11, PADI_CFG_IO41_BTIN11);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_0;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 9);   //aux input PB9
      GPIOB->CTL |= (GPIO_SRC_HW << 9);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
    return HAL_OK;
  }
  else if(htim->Instance == TIMB12)
  {
    if (Pad == PADI_IDX_IO42_BTIN12)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO42_BTIN12, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO42_BTIN12, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO42_BTIN12, PADI_CFG_IO42_BTIN12);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_1;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 8);   //aux input PB8
      GPIOB->CTL |= (GPIO_SRC_HW << 8);   //Hardware Source
    }
    else if (Pad == PADI_IDX_IO36_BTIN12)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO36_BTIN12, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO36_BTIN12, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO36_BTIN12, PADI_CFG_IO36_BTIN12);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_1;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 14);   //aux input PB14
      GPIOB->CTL |= (GPIO_SRC_HW << 14);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
    return HAL_OK;
  }
  else if(htim->Instance == TIMB13)
  {
    if (Pad == PADI_IDX_IO37_BTIN13)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO37_BTIN13, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO37_BTIN13, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO37_BTIN13, PADI_CFG_IO37_BTIN13);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_2;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 13);   //aux input PB13
      GPIOB->CTL |= (GPIO_SRC_HW << 13);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
    return HAL_OK;
  }
  else if(htim->Instance == TIMB14)
  {
    if (Pad == PADI_IDX_IO17_BTIN14)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO17_BTIN14, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO17_BTIN14, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO17_BTIN14, PADI_CFG_IO17_BTIN14);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_3;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 25);   //aux input PB25
      GPIOB->CTL |= (GPIO_SRC_HW << 25);   //Hardware Source
    }
    else if (Pad == PADI_IDX_IO38_BTIN14)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO38_BTIN14, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO38_BTIN14, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO38_BTIN14, PADI_CFG_IO38_BTIN14);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_3;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 12);   //aux input PB12
      GPIOB->CTL |= (GPIO_SRC_HW << 12);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
    return HAL_OK;
  }
  else if(htim->Instance == TIMB21)
  {
    if (Pad == PADI_IDX_IO3_BTIN21)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO3_BTIN21, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO3_BTIN21, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO3_BTIN21, PADI_CFG_IO3_BTIN21);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_4;  //enable external clock 
    }
    else if (Pad == PADI_IDX_IO39_BTIN21)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO39_BTIN21, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO39_BTIN21, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO39_BTIN21, PADI_CFG_IO39_BTIN21);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_4;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 11);   //aux input PB11
      GPIOB->CTL |= (GPIO_SRC_HW << 11);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
    return HAL_OK;
  }
  else if(htim->Instance == TIMB22)
  {
    if (Pad == PADI_IDX_IO27_BTIN22)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO27_BTIN22, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO27_BTIN22, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO27_BTIN22, PADI_CFG_IO27_BTIN22);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_5;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 5);   //aux input PB5
      GPIOB->CTL |= (GPIO_SRC_HW << 5);   //Hardware Source
    }
    else if (Pad == PADI_IDX_IO40_BTIN22)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO40_BTIN22, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO40_BTIN22, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO40_BTIN22, PADI_CFG_IO40_BTIN22);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_5;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 10);   //aux input PB10
      GPIOB->CTL |= (GPIO_SRC_HW << 10);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
    return HAL_OK;
  }
  else if(htim->Instance == TIMB23)
  {
    if (Pad == PADI_IDX_IO26_BTIN23)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO26_BTIN23, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO26_BTIN23, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO26_BTIN23, PADI_CFG_IO26_BTIN23);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_6;  //enable external clock 
      SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 6);   //aux input PB6
      GPIOB->CTL |= (GPIO_SRC_HW << 6);   //Hardware Source
    }
    else
    {
      return HAL_ERROR;
    }
    return HAL_OK;
  }
  else if(htim->Instance == TIMB24)
  {
    if (Pad == PADI_IDX_IO4_BTIN24)
    {
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO4_BTIN24, RESET);    //Pull down
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO4_BTIN24, SET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO4_BTIN24, PADI_CFG_IO4_BTIN24);
      ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_BTMSRC_7;  //enable external clock 
    }
    else
    {
      return HAL_ERROR;
    }
    return HAL_OK;
  }
  else
  {
    return HAL_ERROR;
  }
#else
  return HAL_OK;
#endif /* XT32H0xxB */  
}
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup TIMRPort_Private_Functions TIMRPort Private Functions
  * @{
  */
/**
  * @}
  */

#endif /* HAL_TIMR_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
