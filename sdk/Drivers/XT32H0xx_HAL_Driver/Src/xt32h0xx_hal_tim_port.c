/**
  ******************************************************************************
  * @file    xt32h0xx_hal_tim_port.c
  * @author  Software Team
  * @brief   TIM HAL Port module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Timer (TIM) peripheral:
  *           + TIM Time Port configuration
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

/** @defgroup TIMPort TIMPort
  * @brief TIMPort HAL module driver
  * @{
  */

#ifdef HAL_TIM_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup TIMPort_Private_Constants
  * @{
  */
#define PORT_OFF   (0)	
#define PORT_ON    (1)	
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup TIMPort_Private_Functions
  * @{
  */
static uint32_t TIM_InputPort_A1(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_InputPort_A2(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_InputPort_G1(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_InputPort_G2(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_InputPort_G3(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_InputPort_G4(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad);

static uint32_t TIM_OutputPort_A1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_OutputPort_A2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_OutputPort_G1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_OutputPort_G2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_OutputPort_G3(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_OutputPort_G4(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);

static uint32_t TIM_ForcePort_A1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State);
static uint32_t TIM_ForcePort_A2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State);
static uint32_t TIM_ForcePort_G1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State);
static uint32_t TIM_ForcePort_G2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State);
static uint32_t TIM_ForcePort_G3(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State);
static uint32_t TIM_ForcePort_G4(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State);

static uint32_t TIM_SwitchPWMPort_A1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_SwitchPWMPort_A2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_SwitchPWMPort_G1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_SwitchPWMPort_G2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_SwitchPWMPort_G3(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
static uint32_t TIM_SwitchPWMPort_G4(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad);
/**
  * @}
  */
/* Exported functions --------------------------------------------------------*/

/** @defgroup TIMPort_Exported_Functions TIMPort Exported Functions
  * @{
  */
/** @defgroup TIMPort_Exported_Functions_Group1 TIMPort Peripheral Port functions
  *  @brief  Peripheral Port functions
  * @{
  */
/* Peripheral port functions  ************************************************/
/**
  * @brief  Config TIM output port.
  * @param  htim TIM handle
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval state
  */
HAL_StatusTypeDef HAL_TIM_OutputPortConfig(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
  HAL_StatusTypeDef state = HAL_OK;
#if defined(XT32H0xxB)  
  if(htim->Instance == TIM1)
  {
    if(TIM_OutputPort_A1(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIM2)
  {
    if(TIM_OutputPort_A2(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG1)
  {
    if(TIM_OutputPort_G1(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG2)
  {
    if(TIM_OutputPort_G2(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG3)
  {
    if(TIM_OutputPort_G3(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG4)
  {
    if(TIM_OutputPort_G4(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else
  {
    state = HAL_ERROR;
  }
#endif /* XT32H0xxB */  
  return state;
}

/**
  * @brief  Config TIM input port.
  * @param  dstTim destination TIM handle
  * @param  srcTim source TIM handle
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_ETR
  *            @arg TIM_PORT_BRK_IN
  *            @arg TIM_PORT_BRK2_IN
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval state
  */
HAL_StatusTypeDef HAL_TIM_InputPortConfig(TIM_TypeDef* dstTim, TIM_TypeDef *srcTim, uint32_t Channel, uint32_t Pad)
{
  HAL_StatusTypeDef state = HAL_OK;
#if defined(XT32H0xxB) 	
  uint32_t *pReg = (uint32_t *)&(SYSCFG->TIM_A1_IMX);
  uint32_t pos = 0;
  uint32_t cfg = 0;
  uint32_t mask = 0;
  uint32_t temp = 0;
	
  if((TIM_InputPort_A1(srcTim, Channel, Pad)) ||
     (TIM_InputPort_A2(srcTim, Channel, Pad)) ||
     (TIM_InputPort_G1(srcTim, Channel, Pad)) ||
     (TIM_InputPort_G2(srcTim, Channel, Pad)) ||
     (TIM_InputPort_G3(srcTim, Channel, Pad)) ||
     (TIM_InputPort_G4(srcTim, Channel, Pad)) )
  {
    pReg = (uint32_t *)&(SYSCFG->TIM_A1_IMX);
    if(dstTim == TIM1)
    {
      pReg += 0;
    }
    else if (dstTim == TIM2)
    {
      pReg += 1;
    }
    else if (dstTim == TIMG1)
    {
      pReg += 2;
    }
    else if (dstTim == TIMG2)
    {
      pReg += 3;
    }
    else if (dstTim == TIMG3)
    {
      pReg += 4;
    }
    else if (dstTim == TIMG4)
    {
      pReg += 5;
    }
    else
    {
      return HAL_ERROR;
    }
    
    if(srcTim == TIM1)
    {
      cfg = 0;
    }
    else if (srcTim == TIM2)
    {
      cfg = 1;
    }
    else if (srcTim == TIMG1)
    {
      cfg = 2;
    }
    else if (srcTim == TIMG2)
    {
      cfg = 3;
    }
    else if (srcTim == TIMG3)
    {
      cfg = 4;
    }
    else if (srcTim == TIMG4)
    {
      cfg = 5;
    }
    else
    {
      return HAL_ERROR;
    }

    if (Channel == TIM_PORT_ETR)
    {
      pos = SYSCFG_TIMA1IMX_ETR_Pos;
      mask = SYSCFG_TIMA1IMX_ETR;
    }
    else if (Channel == TIM_PORT_CHANNEL_4)
    {
      pos = SYSCFG_TIMA1IMX_CH_4_Pos;
      mask = SYSCFG_TIMA1IMX_CH_4;
    }
    else if (Channel == TIM_PORT_CHANNEL_3)
    {
      pos = SYSCFG_TIMA1IMX_CH_3_Pos;
      mask = SYSCFG_TIMA1IMX_CH_3;
    }
    else if (Channel == TIM_PORT_CHANNEL_2)
    {
      pos = SYSCFG_TIMA1IMX_CH_2_Pos;
      mask = SYSCFG_TIMA1IMX_CH_2;
    }
    else if (Channel == TIM_PORT_CHANNEL_1)
    {
      pos = SYSCFG_TIMA1IMX_CH_1_Pos;
      mask = SYSCFG_TIMA1IMX_CH_1;
    }
    else
    {
      return HAL_ERROR;
    }

    temp = *pReg;
    temp &= ~mask;
    temp |= (cfg << pos);
    *pReg = temp; 
  }
  else if ((srcTim == TIM1)&&(Pad == PADI_IDX_IO1_ATIN1_BRKIN1)&&(Channel == TIM_PORT_BRK_IN))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO1_ATIN1_BRKIN1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO1_ATIN1_BRKIN1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO1_ATIN1_BRKIN1, PADI_CFG_IO1_ATIN1_BRKIN1);
  }
  else if ((srcTim == TIM1)&&(Pad == PADI_IDX_IO5_ATIN1_BRKIN2)&&(Channel == TIM_PORT_BRK2_IN))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO5_ATIN1_BRKIN2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO5_ATIN1_BRKIN2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO5_ATIN1_BRKIN2, PADI_CFG_IO5_ATIN1_BRKIN2);
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 0);   //aux input PC0
    GPIOC->CTL |= (GPIO_SRC_HW << 0);   //Hardware Source
  }
  else if ((srcTim == TIM1)&&(Pad == PADI_IDX_IO30_ATIN1_BRKIN1)&&(Channel == TIM_PORT_BRK_IN))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO30_ATIN1_BRKIN1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO30_ATIN1_BRKIN1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO30_ATIN1_BRKIN1, PADI_CFG_IO30_ATIN1_BRKIN1);
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 9);   //aux input PC9
    GPIOC->CTL |= (GPIO_SRC_HW << 9);   //Hardware Source
  }
  else if ((srcTim == TIM2)&&(Pad == PADI_IDX_IO55_ATIN2_BRKIN1)&&(Channel == TIM_PORT_BRK_IN))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO55_ATIN2_BRKIN1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO55_ATIN2_BRKIN1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO55_ATIN2_BRKIN1, PADI_CFG_IO55_ATIN2_BRKIN1);
    SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 3);   //aux input PB3
    GPIOB->CTL |= (GPIO_SRC_HW << 3);   //Hardware Source
  }
  else if ((srcTim == TIM2)&&(Pad == PADI_IDX_IO57_ATIN2_BRKIN2)&&(Channel == TIM_PORT_BRK2_IN))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO57_ATIN2_BRKIN2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO57_ATIN2_BRKIN2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO57_ATIN2_BRKIN2, PADI_CFG_IO57_ATIN2_BRKIN2);
    SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 1);   //aux input PB1
    GPIOB->CTL |= (GPIO_SRC_HW << 1);   //Hardware Source
  }
  else
  {
    state = HAL_ERROR;
  }
#endif /* XT32H0xxB */  
  return  state;
}

/**
  * @brief  Force TIM port on.
  * @param  htim TIM handle
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval state
  */
HAL_StatusTypeDef HAL_TIM_ForcePortOn(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
  HAL_StatusTypeDef state = HAL_OK;
#if defined(XT32H0xxB)  
  if(htim->Instance == TIM1)
  {
    if(TIM_ForcePort_A1(htim, Channel, Pad, PORT_ON) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIM2)
  {
    if(TIM_ForcePort_A2(htim, Channel, Pad, PORT_ON) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG1)
  {
    if(TIM_ForcePort_G1(htim, Channel, Pad, PORT_ON) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG2)
  {
    if(TIM_ForcePort_G2(htim, Channel, Pad, PORT_ON) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG3)
  {
    if(TIM_ForcePort_G3(htim, Channel, Pad, PORT_ON) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG4)
  {
    if(TIM_ForcePort_G4(htim, Channel, Pad, PORT_ON) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else
  {
    state = HAL_ERROR;
  }
#endif /* XT32H0xxB */  
  return state;
}
	
/**
  * @brief  Force TIM port off.
  * @param  htim TIM handle
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval state
  */
HAL_StatusTypeDef HAL_TIM_ForcePortOff(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
  HAL_StatusTypeDef state = HAL_OK;
#if defined(XT32H0xxB)  
  if(htim->Instance == TIM1)
  {
    if(TIM_ForcePort_A1(htim, Channel, Pad, PORT_OFF) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIM2)
  {
    if(TIM_ForcePort_A2(htim, Channel, Pad, PORT_OFF) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG1)
  {
    if(TIM_ForcePort_G1(htim, Channel, Pad, PORT_OFF) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG2)
  {
    if(TIM_ForcePort_G2(htim, Channel, Pad, PORT_OFF) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG3)
  {
    if(TIM_ForcePort_G3(htim, Channel, Pad, PORT_OFF) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG4)
  {
    if(TIM_ForcePort_G4(htim, Channel, Pad, PORT_OFF) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else
  {
    state = HAL_ERROR;
  }
#endif /* XT32H0xxB */  
  return state;
}

	/**
  * @brief  switch to TIM pwm port.
  * @param  htim TIM handle
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval state
  */
HAL_StatusTypeDef HAL_TIM_SwitchtoPWMPort(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
//	return HAL_TIM_OutputPortConfig(htim, Channel, Pad);
  HAL_StatusTypeDef state = HAL_OK;
#if defined(XT32H0xxB)  
  if(htim->Instance == TIM1)
  {
    if(TIM_SwitchPWMPort_A1(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIM2)
  {
    if(TIM_SwitchPWMPort_A2(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG1)
  {
    if(TIM_SwitchPWMPort_G1(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG2)
  {
    if(TIM_SwitchPWMPort_G2(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG3)
  {
    if(TIM_SwitchPWMPort_G3(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else if(htim->Instance == TIMG4)
  {
    if(TIM_SwitchPWMPort_G4(htim, Channel, Pad) == 0)
    {
      state = HAL_ERROR;
    }
  }
  else
  {
    state = HAL_ERROR;
  }
#endif /* XT32H0xxB */  
  return state;
}
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup TIMPort_Private_Functions TIMPort Private Functions
  * @{
  */

/**
  * @brief  TIM A1 Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_OutputPort_A1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
	
  uint32_t st = 1;

  if (htim->Instance != TIM1)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO10_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO10_ATOUT1_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO10_ATOUT1_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO10_ATOUT1_CH1_P, PADI_CFG_IO10_ATOUT1_CH1_P);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 26);   //aux output  PB26
    GPIOB->CTL |= (GPIO_SRC_HW << 26);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 26);
  }
  else if((Pad == PADI_IDX_IO13_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO13_ATOUT1_CH1_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO13_ATOUT1_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO13_ATOUT1_CH1_N, PADI_CFG_IO13_ATOUT1_CH1_N);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 16);   //aux output PC16
    GPIOC->CTL |= (GPIO_SRC_HW << 16);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 16);
    if(Channel==TIM_PORT_CHANNEL_1)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
    }
  }
  else if((Pad == PADI_IDX_IO38_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO38_ATOUT1_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO38_ATOUT1_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO38_ATOUT1_CH1_P, PADI_CFG_IO38_ATOUT1_CH1_P);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 12);   //aux output PB12
    GPIOB->CTL |= (GPIO_SRC_HW << 12);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 12);
  }
  else if((Pad == PADI_IDX_IO39_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO39_ATOUT1_CH1_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO39_ATOUT1_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO39_ATOUT1_CH1_N, PADI_CFG_IO39_ATOUT1_CH1_N);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 11);   //aux output PB11
    GPIOB->CTL |= (GPIO_SRC_HW << 11);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 11);
    if(Channel==TIM_PORT_CHANNEL_1)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
    }
  }
  else if((Pad == PADI_IDX_IO57_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO57_ATOUT1_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO57_ATOUT1_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO57_ATOUT1_CH1_P, PADI_CFG_IO57_ATOUT1_CH1_P);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 1);   //aux output PB1
    GPIOB->CTL |= (GPIO_SRC_HW << 1);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 1);
  }
  else if((Pad == PADI_IDX_IO58_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO58_ATOUT1_CH1_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO58_ATOUT1_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO58_ATOUT1_CH1_N, PADI_CFG_IO58_ATOUT1_CH1_N);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 0);   //aux output PB0
    GPIOB->CTL |= (GPIO_SRC_HW << 0);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 0);
    if(Channel==TIM_PORT_CHANNEL_1)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
    }
  }
  else if((Pad == PADI_IDX_IO14_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO14_ATOUT1_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO14_ATOUT1_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO14_ATOUT1_CH2_P, PADI_CFG_IO14_ATOUT1_CH2_P);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 17);   //aux output PC17
    GPIOC->CTL |= (GPIO_SRC_HW << 17);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 17);
  }
  else if((Pad == PADI_IDX_IO15_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO15_ATOUT1_CH2_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO15_ATOUT1_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO15_ATOUT1_CH2_N, PADI_CFG_IO15_ATOUT1_CH2_N);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 18);   //aux output PC18
    GPIOC->CTL |= (GPIO_SRC_HW << 18);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 18);
    if(Channel==TIM_PORT_CHANNEL_2)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
    }
  }
  else if((Pad == PADI_IDX_IO35_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO35_ATOUT1_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO35_ATOUT1_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO35_ATOUT1_CH2_P, PADI_CFG_IO35_ATOUT1_CH2_P);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 15);   //aux output PB15
    GPIOB->CTL |= (GPIO_SRC_HW << 15);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 15);
  }
  else if((Pad == PADI_IDX_IO36_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO36_ATOUT1_CH2_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO36_ATOUT1_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO36_ATOUT1_CH2_N, PADI_CFG_IO36_ATOUT1_CH2_N);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 14);   //aux output PB14
    GPIOB->CTL |= (GPIO_SRC_HW << 14);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 14);
    if(Channel==TIM_PORT_CHANNEL_2)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
    }
  }
  else if((Pad == PADI_IDX_IO51_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO51_ATOUT1_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO51_ATOUT1_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO51_ATOUT1_CH2_P, PADI_CFG_IO51_ATOUT1_CH2_P);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 17);   //aux output PB17
    GPIOB->CTL |= (GPIO_SRC_HW << 17);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 17);
  }
  else if((Pad == PADI_IDX_IO52_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO52_ATOUT1_CH2_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO52_ATOUT1_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO52_ATOUT1_CH2_N, PADI_CFG_IO52_ATOUT1_CH2_N);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 16);   //aux output PB16
    GPIOB->CTL |= (GPIO_SRC_HW << 16);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 16);
    if(Channel==TIM_PORT_CHANNEL_2)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
    }
  }
  else if((Pad == PADI_IDX_IO5_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO5_ATOUT1_CH3_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO5_ATOUT1_CH3_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO5_ATOUT1_CH3_P, PADI_CFG_IO5_ATOUT1_CH3_P);
		GPIOC->CTL &= ~(0x1UL << 0);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 0);
  }
  else if((Pad == PADI_IDX_IO9_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO9_ATOUT1_CH3_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO9_ATOUT1_CH3_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO9_ATOUT1_CH3_N, PADI_CFG_IO9_ATOUT1_CH3_N);
    SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 15);   //aux output PD15
    GPIOD->CTL |= (GPIO_SRC_HW << 15);   //Hardware Source
		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 15);
  }
  else if((Pad == PADI_IDX_IO28_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO28_ATOUT1_CH3_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO28_ATOUT1_CH3_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO28_ATOUT1_CH3_P, PADI_CFG_IO28_ATOUT1_CH3_P);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 24);   //aux output PB24
    GPIOB->CTL |= (GPIO_SRC_HW << 24);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 24);
  }
  else if((Pad == PADI_IDX_IO29_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO29_ATOUT1_CH3_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO29_ATOUT1_CH3_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO29_ATOUT1_CH3_N, PADI_CFG_IO29_ATOUT1_CH3_N);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 8);   //aux output PC8
    GPIOC->CTL |= (GPIO_SRC_HW << 8);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 8);
  }
  else if((Pad == PADI_IDX_IO49_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO49_ATOUT1_CH3_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO49_ATOUT1_CH3_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO49_ATOUT1_CH3_P, PADI_CFG_IO49_ATOUT1_CH3_P);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 19);   //aux output PB19
    GPIOB->CTL |= (GPIO_SRC_HW << 19);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 19);
  }
  else if((Pad == PADI_IDX_IO50_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO50_ATOUT1_CH3_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO50_ATOUT1_CH3_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO50_ATOUT1_CH3_N, PADI_CFG_IO50_ATOUT1_CH3_N);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 18);   //aux output PB18
    GPIOB->CTL |= (GPIO_SRC_HW << 18);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 18);
  }
  else if((Pad == PADI_IDX_IO44_ATOUT1_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO44_ATOUT1_CH4, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO44_ATOUT1_CH4, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO44_ATOUT1_CH4, PADI_CFG_IO44_ATOUT1_CH4);
    SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 23);   //aux output PD23
    GPIOD->CTL |= (GPIO_SRC_HW << 23);   //Hardware Source
		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 23);
  }
  else if((Pad == PADI_IDX_IO23_ATOUT1_BRKOUT2)&&(Channel==TIM_PORT_BRK2_OUT))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO23_ATOUT1_BRKOUT2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO23_ATOUT1_BRKOUT2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO23_ATOUT1_BRKOUT2, PADI_CFG_IO23_ATOUT1_BRKOUT2);
		GPIOC->CTL &= ~(0x1UL << 26);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 26);
  }
  else if((Pad == PADI_IDX_IO24_ATOUT1_BRKOUT1)&&(Channel==TIM_PORT_BRK_OUT))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO24_ATOUT1_BRKOUT1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO24_ATOUT1_BRKOUT1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO24_ATOUT1_BRKOUT1, PADI_CFG_IO24_ATOUT1_BRKOUT1);
		GPIOC->CTL &= ~(0x1UL << 25);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 25);
  }
  else
  {
    st = 0;
  }

  return st;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM A2 Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_OutputPort_A2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIM2)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO18_ATOUT2_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO18_ATOUT2_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO18_ATOUT2_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO18_ATOUT2_CH1_P, PADI_CFG_IO18_ATOUT2_CH1_P);
		GPIOC->CTL &= ~(0x1UL << 31);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 31);
  }
  else if((Pad == PADI_IDX_IO19_ATOUT2_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO19_ATOUT2_CH1_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO19_ATOUT2_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO19_ATOUT2_CH1_N, PADI_CFG_IO19_ATOUT2_CH1_N);
    if(Channel==TIM_PORT_CHANNEL_1)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA2_CH1_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA2_CH1_OS);
    }
		GPIOC->CTL &= ~(0x1UL << 30);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 30);
  }
  else if((Pad == PADI_IDX_IO20_ATOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO20_ATOUT2_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO20_ATOUT2_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO20_ATOUT2_CH2_P, PADI_CFG_IO20_ATOUT2_CH2_P);
		GPIOC->CTL &= ~(0x1UL << 29);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 29);
  }
  else if((Pad == PADI_IDX_IO21_ATOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO21_ATOUT2_CH2_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO21_ATOUT2_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO21_ATOUT2_CH2_N, PADI_CFG_IO21_ATOUT2_CH2_N);
    if(Channel==TIM_PORT_CHANNEL_2)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA2_CH2_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA2_CH2_OS);
    }
		GPIOC->CTL &= ~(0x1UL << 28);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 28);
  }
  else if((Pad == PADI_IDX_IO2_ATOUT2_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO2_ATOUT2_CH3_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO2_ATOUT2_CH3_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO2_ATOUT2_CH3_P, PADI_CFG_IO2_ATOUT2_CH3_P);
		GPIOC->CTL &= ~(0x1UL << 3);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 3);
  }
  else if((Pad == PADI_IDX_IO3_ATOUT2_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO3_ATOUT2_CH3_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO3_ATOUT2_CH3_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO3_ATOUT2_CH3_N, PADI_CFG_IO3_ATOUT2_CH3_N);
		GPIOC->CTL &= ~(0x1UL << 2);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 2);
  }
  else if((Pad == PADI_IDX_IO54_ATOUT2_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO54_ATOUT2_CH4, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO54_ATOUT2_CH4, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO54_ATOUT2_CH4, PADI_CFG_IO54_ATOUT2_CH4);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 4);   //aux output PB4
    GPIOB->CTL |= (GPIO_SRC_HW << 4);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 4);
  }
  else if((Pad == PADI_IDX_IO16_ATOUT2_BRKOUT1)&&(Channel==TIM_PORT_BRK_OUT))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO16_ATOUT2_BRKOUT1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO16_ATOUT2_BRKOUT1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO16_ATOUT2_BRKOUT1, PADI_CFG_IO16_ATOUT2_BRKOUT1);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 19);   //aux output PC19
    GPIOC->CTL |= (GPIO_SRC_HW << 19);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 19);
  }
  else if((Pad == PADI_IDX_IO27_ATOUT2_BRKOUT2)&&(Channel==TIM_PORT_BRK2_OUT))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO27_ATOUT2_BRKOUT2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO27_ATOUT2_BRKOUT2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO27_ATOUT2_BRKOUT2, PADI_CFG_IO27_ATOUT2_BRKOUT2);
		GPIOB->CTL &= ~(0x1UL << 5);
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 5);
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G1 Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_OutputPort_G1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG1)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO43_GTOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO43_GTOUT1_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO43_GTOUT1_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO43_GTOUT1_CH1_P, PADI_CFG_IO43_GTOUT1_CH1_P);
    SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 22);   //aux output PD22
    GPIOD->CTL |= (GPIO_SRC_HW << 22);   //Hardware Source
		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 22);
  }
  else if((Pad == PADI_IDX_IO30_GTOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO30_GTOUT1_CH1_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO30_GTOUT1_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO30_GTOUT1_CH1_N, PADI_CFG_IO30_GTOUT1_CH1_N);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 9);   //aux output PC9
    GPIOC->CTL |= (GPIO_SRC_HW << 9);   //Hardware Source
    if(Channel==TIM_PORT_CHANNEL_1)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG1_CH1_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG1_CH1_OS);
    }
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 9);
  }
  else if((Pad == PADI_IDX_IO53_GTOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO53_GTOUT1_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO53_GTOUT1_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO53_GTOUT1_CH2_P, PADI_CFG_IO53_GTOUT1_CH2_P);
    SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 8);   //aux output PD8
    GPIOD->CTL |= (GPIO_SRC_HW << 8);   //Hardware Source
		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 8);
  }
  else if((Pad == PADI_IDX_IO60_GTOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO60_GTOUT1_CH3_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO60_GTOUT1_CH3_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO60_GTOUT1_CH3_P, PADI_CFG_IO60_GTOUT1_CH3_P);
    SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 16);   //aux output PD16
    GPIOD->CTL |= (GPIO_SRC_HW << 16);   //Hardware Source
		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 16);
  }
  else if((Pad == PADI_IDX_IO45_GTOUT1_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO45_GTOUT1_CH4, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO45_GTOUT1_CH4, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO45_GTOUT1_CH4, PADI_CFG_IO45_GTOUT1_CH4);
		GPIOB->CTL &= ~(0x1UL << 23);
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 23);
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G2 Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUR
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_OutputPort_G2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG2)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO22_GTOUT2_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO22_GTOUT2_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO22_GTOUT2_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO22_GTOUT2_CH1_P, PADI_CFG_IO22_GTOUT2_CH1_P);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 27);   //aux output PC27
    GPIOC->CTL |= (GPIO_SRC_HW << 27);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 27);
  }
  else if((Pad == PADI_IDX_IO23_GTOUT2_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO23_GTOUT2_CH1_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO23_GTOUT2_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO23_GTOUT2_CH1_N, PADI_CFG_IO23_GTOUT2_CH1_N);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 26);   //aux output PC26
    GPIOC->CTL |= (GPIO_SRC_HW << 26);   //Hardware Source
    if(Channel==TIM_PORT_CHANNEL_1)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG2_CH1_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG2_CH1_OS);
    }
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 26);
  }
  else if((Pad == PADI_IDX_IO18_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO18_GTOUT2_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO18_GTOUT2_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO18_GTOUT2_CH2_P, PADI_CFG_IO18_GTOUT2_CH2_P);
    SYSCFG->GPIO_ENAUX_C |= ((uint32_t)LL_GPIO_AUX_OUTPUT << 31);   //aux output PC31
    GPIOC->CTL |= (GPIO_SRC_HW << 31);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 31);
  }
  else if((Pad == PADI_IDX_IO46_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO46_GTOUT2_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO46_GTOUT2_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO46_GTOUT2_CH2_P, PADI_CFG_IO46_GTOUT2_CH2_P);
		GPIOB->CTL &= ~(0x1UL << 22);
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 22);
  }
  else if((Pad == PADI_IDX_IO53_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO53_GTOUT2_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO53_GTOUT2_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO53_GTOUT2_CH2_P, PADI_CFG_IO53_GTOUT2_CH2_P);
		GPIOD->CTL &= ~(0x1UL << 8);
		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 8);
  }
  else if((Pad == PADI_IDX_IO19_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO19_GTOUT2_CH2_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO19_GTOUT2_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO19_GTOUT2_CH2_N, PADI_CFG_IO19_GTOUT2_CH2_N);
    if(Channel==TIM_PORT_CHANNEL_2)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
    }
		GPIOC->CTL &= ~(0x1UL << 30);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 30);
  }
  else if((Pad == PADI_IDX_IO55_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO55_GTOUT2_CH2_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO55_GTOUT2_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO55_GTOUT2_CH2_N, PADI_CFG_IO55_GTOUT2_CH2_N);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 3);   //aux output PB3
    GPIOB->CTL |= (GPIO_SRC_HW << 3);   //Hardware Source
    if(Channel==TIM_PORT_CHANNEL_2)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
    }
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 3);
  }
  else if((Pad == PADI_IDX_IO60_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO60_GTOUT2_CH2_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO60_GTOUT2_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO60_GTOUT2_CH2_N, PADI_CFG_IO60_GTOUT2_CH2_N);
    if(Channel==TIM_PORT_CHANNEL_2)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
    }
		GPIOD->CTL &= ~(0x1UL << 16);
		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 16);
  }
  else if((Pad == PADI_IDX_IO19_GTOUT2_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO19_GTOUT2_CH3_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO19_GTOUT2_CH3_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO19_GTOUT2_CH3_P, PADI_CFG_IO19_GTOUT2_CH3_P);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 30);   //aux output PC30
    GPIOC->CTL |= (GPIO_SRC_HW << 30);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 30);
  }
  else if((Pad == PADI_IDX_IO56_GTOUT2_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO56_GTOUT2_CH3_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO56_GTOUT2_CH3_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO56_GTOUT2_CH3_N, PADI_CFG_IO56_GTOUT2_CH3_N);
    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 2);   //aux output PB2
    GPIOB->CTL |= (GPIO_SRC_HW << 2);   //Hardware Source
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 2);
  }
  else if((Pad == PADI_IDX_IO24_GTOUT2_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO24_GTOUT2_CH4, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO24_GTOUT2_CH4, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO24_GTOUT2_CH4, PADI_CFG_IO24_GTOUT2_CH4);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 25);   //aux output PC25
    GPIOC->CTL |= (GPIO_SRC_HW << 25);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 25);
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G3 Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_OutputPort_G3(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG3)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO47_GTOUT3_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO47_GTOUT3_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO47_GTOUT3_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO47_GTOUT3_CH1_P, PADI_CFG_IO47_GTOUT3_CH1_P);
		GPIOB->CTL &= ~(0x1UL << 21);
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 21);
  }
  else if((Pad == PADI_IDX_IO48_GTOUT3_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO48_GTOUT3_CH1_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO48_GTOUT3_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO48_GTOUT3_CH1_N, PADI_CFG_IO48_GTOUT3_CH1_N);
    if(Channel==TIM_PORT_CHANNEL_1)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG3_CH1_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG3_CH1_OS);
    }
		GPIOB->CTL &= ~(0x1UL << 20);
		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 20);
  }
  else if((Pad == PADI_IDX_IO20_GTOUT3_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO20_GTOUT3_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO20_GTOUT3_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO20_GTOUT3_CH2_P, PADI_CFG_IO20_GTOUT3_CH2_P);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 29);   //aux output PC29
    GPIOC->CTL |= (GPIO_SRC_HW << 29);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 29);
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G4 Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_OutputPort_G4(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG4)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO4_GTOUT4_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO4_GTOUT4_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO4_GTOUT4_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO4_GTOUT4_CH1_P, PADI_CFG_IO4_GTOUT4_CH1_P);
		GPIOC->CTL &= ~(0x1UL << 1);
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 1);
  }
  else if((Pad == PADI_IDX_IO61_GTOUT4_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO61_GTOUT4_CH1_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO61_GTOUT4_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO61_GTOUT4_CH1_P, PADI_CFG_IO61_GTOUT4_CH1_P);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 4);   //aux output PC4
    GPIOC->CTL |= (GPIO_SRC_HW << 4);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 4);
  }
  else if((Pad == PADI_IDX_IO62_GTOUT4_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO62_GTOUT4_CH1_N, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO62_GTOUT4_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO62_GTOUT4_CH1_N, PADI_CFG_IO62_GTOUT4_CH1_N);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 5);   //aux output PC5
    GPIOC->CTL |= (GPIO_SRC_HW << 5);   //Hardware Source
    if(Channel==TIM_PORT_CHANNEL_1)
    {
      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG4_CH1_OS);
    }
    else
    {
      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG4_CH1_OS);
    }
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 5);
  }
  else if((Pad == PADI_IDX_IO21_GTOUT4_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO21_GTOUT4_CH2_P, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO21_GTOUT4_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO21_GTOUT4_CH2_P, PADI_CFG_IO21_GTOUT4_CH2_P);
    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 28);   //aux output PC28
    GPIOC->CTL |= (GPIO_SRC_HW << 28);   //Hardware Source
		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 28);
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM A1 Input port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_ETR
  *            @arg TIM_PORT_BRK_IN
  *            @arg TIM_PORT_BRK2_IN
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_InputPort_A1(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim != TIM1)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO1_ATIN1_ETR) && (Channel == TIM_PORT_ETR))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO1_ATIN1_ETR, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO1_ATIN1_ETR, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO1_ATIN1_ETR, PADI_CFG_IO1_ATIN1_ETR);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM1SRC_CH_4;  //enable external clock for ETR
    SYSCFG->GPIO_ENAUX_D &= ~(LL_GPIO_AUX_OUTPUT << 0);   //aux input PD0
    GPIOD->CTL |= (GPIO_SRC_HW << 0);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO9_ATIN1_CH3)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO9_ATIN1_CH3, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO9_ATIN1_CH3, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO9_ATIN1_CH3, PADI_CFG_IO9_ATIN1_CH3);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM1SRC_CH_2;  //enable external clock for CH3
    SYSCFG->GPIO_ENAUX_D &= ~(LL_GPIO_AUX_OUTPUT << 15);   //aux input PD15
    GPIOD->CTL |= (GPIO_SRC_HW << 15);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO13_ATIN1_CH1)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO13_ATIN1_CH1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO13_ATIN1_CH1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO13_ATIN1_CH1, PADI_CFG_IO13_ATIN1_CH1);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM1SRC_CH_0;  //enable external clock for CH1
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 16);   //aux input PC16
    GPIOC->CTL |= (GPIO_SRC_HW << 16);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO15_ATIN1_CH2)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO15_ATIN1_CH2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO15_ATIN1_CH2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO15_ATIN1_CH2, PADI_CFG_IO15_ATIN1_CH2);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM1SRC_CH_1;  //enable external clock for CH2
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 18);   //aux input PC18
    GPIOC->CTL |= (GPIO_SRC_HW << 18);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO28_ATIN1_ETR)&&(Channel==TIM_PORT_ETR))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO28_ATIN1_ETR, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO28_ATIN1_ETR, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO28_ATIN1_ETR, PADI_CFG_IO28_ATIN1_ETR);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM1SRC_CH_4;  //enable external clock for ETR
    SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 24);   //aux input PB24
    GPIOB->CTL |= (GPIO_SRC_HW << 24);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO35_ATIN1_CH2)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO35_ATIN1_CH2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO35_ATIN1_CH2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO35_ATIN1_CH2, PADI_CFG_IO35_ATIN1_CH2);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM1SRC_CH_1;  //enable external clock for CH2
    SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 15);   //aux input PB15
    GPIOB->CTL |= (GPIO_SRC_HW << 15);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO44_ATIN1_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO44_ATIN1_CH4, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO44_ATIN1_CH4, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO44_ATIN1_CH4, PADI_CFG_IO44_ATIN1_CH4);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM1SRC_CH_3;  //enable external clock for CH4
    SYSCFG->GPIO_ENAUX_D &= ~(LL_GPIO_AUX_OUTPUT << 23);   //aux input PD23
    GPIOD->CTL |= (GPIO_SRC_HW << 23);   //Hardware Source
  }
  else
  {
    return 0;
  }
  return 1;
#else
  return 0;
#endif /* XT32H0xxB */	
}

/**
  * @brief  TIM A2 Input port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_ETR
  *            @arg TIM_PORT_BRK_IN
  *            @arg TIM_PORT_BRK2_IN
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_InputPort_A2(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim != TIM2)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO59_ATIN2_ETR)&&(Channel==TIM_PORT_ETR))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO59_ATIN2_ETR, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO59_ATIN2_ETR, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO59_ATIN2_ETR, PADI_CFG_IO59_ATIN2_ETR);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM2SRC_CH_4;  //enable external clock for ETR
    SYSCFG->GPIO_ENAUX_D &= ~(LL_GPIO_AUX_OUTPUT << 17);   //aux input PD17
    GPIOD->CTL |= (GPIO_SRC_HW << 17);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO2_ATIN2_CH3)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO2_ATIN2_CH3, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO2_ATIN2_CH3, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO2_ATIN2_CH3, PADI_CFG_IO2_ATIN2_CH3);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM2SRC_CH_2;  //enable external clock for CH3
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 3);   //aux input PC3
    GPIOC->CTL |= (GPIO_SRC_HW << 3);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO54_ATIN2_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO54_ATIN2_CH4, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO54_ATIN2_CH4, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO54_ATIN2_CH4, PADI_CFG_IO54_ATIN2_CH4);
    ICG->TIMER_EXCLK_EN_1 |= ICG_TMXC_ATM2SRC_CH_3;  //enable external clock for CH4
    SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT << 4);   //aux input PB4
    GPIOB->CTL |= (GPIO_SRC_HW << 4);   //Hardware Source
  }
  else
  {
    return 0;
  }
  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G1 Input port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_ETR
  *            @arg TIM_PORT_BRK_IN
  *            @arg TIM_PORT_BRK2_IN
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_InputPort_G1(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim != TIMG1)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO29_GTIN1_ETR)&&(Channel==TIM_PORT_ETR))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO29_GTIN1_ETR, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO29_GTIN1_ETR, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO29_GTIN1_ETR, PADI_CFG_IO29_GTIN1_ETR);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM1SRC_CH_4;  //enable external clock for ETR
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 8);   //aux input PC8
    GPIOC->CTL |= (GPIO_SRC_HW << 8);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO37_GTIN1_ETR)&&(Channel==TIM_PORT_ETR))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO37_GTIN1_ETR, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO37_GTIN1_ETR, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO37_GTIN1_ETR, PADI_CFG_IO37_GTIN1_ETR);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM1SRC_CH_4;  //enable external clock for ETR
  }
  else if ((Pad == PADI_IDX_IO43_GTIN1_CH1)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO43_GTIN1_CH1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO43_GTIN1_CH1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO43_GTIN1_CH1, PADI_CFG_IO43_GTIN1_CH1);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM1SRC_CH_0;  //enable external clock for CH1
    SYSCFG->GPIO_ENAUX_D &= ~(LL_GPIO_AUX_OUTPUT << 22);   //aux input PD22
    GPIOD->CTL |= (GPIO_SRC_HW << 22);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO53_GTIN1_CH2)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO53_GTIN1_CH2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO53_GTIN1_CH2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO53_GTIN1_CH2, PADI_CFG_IO53_GTIN1_CH2);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM1SRC_CH_1;  //enable external clock for CH2
    SYSCFG->GPIO_ENAUX_D &= ~(LL_GPIO_AUX_OUTPUT << 8);   //aux input PD8
    GPIOD->CTL |= (GPIO_SRC_HW << 8);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO60_GTIN1_CH3)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO60_GTIN1_CH3, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO60_GTIN1_CH3, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO60_GTIN1_CH3, PADI_CFG_IO60_GTIN1_CH3);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM1SRC_CH_2;  //enable external clock for CH3
    SYSCFG->GPIO_ENAUX_D &= ~(LL_GPIO_AUX_OUTPUT << 16);   //aux input PD16
    GPIOD->CTL |= (GPIO_SRC_HW << 16);   //Hardware Source
  }
  else
  {
    return 0;
  }
  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G2 Input port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_ETR
  *            @arg TIM_PORT_BRK_IN
  *            @arg TIM_PORT_BRK2_IN
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_InputPort_G2(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim != TIMG2)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO19_GTIN2_ETR)&&(Channel==TIM_PORT_ETR))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO19_GTIN2_ETR, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO19_GTIN2_ETR, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO19_GTIN2_ETR, PADI_CFG_IO19_GTIN2_ETR);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM2SRC_CH_4;  //enable external clock for ETR
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 30);  //aux input PC30
    GPIOC->CTL |= (GPIO_SRC_HW << 30);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO56_GTIN2_ETR)&&(Channel==TIM_PORT_ETR))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO56_GTIN2_ETR, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO56_GTIN2_ETR, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO56_GTIN2_ETR, PADI_CFG_IO56_GTIN2_ETR);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM2SRC_CH_4;  //enable external clock for ETR
    SYSCFG->GPIO_ENAUX_B &= ~(LL_GPIO_AUX_OUTPUT <<2);   //aux input PB2
    GPIOB->CTL |= (GPIO_SRC_HW << 2);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO22_GTIN2_CH1)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO22_GTIN2_CH1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO22_GTIN2_CH1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO22_GTIN2_CH1, PADI_CFG_IO22_GTIN2_CH1);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM2SRC_CH_0;  //enable external clock for CH1
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 27);   //aux input PC27
    GPIOC->CTL |= (GPIO_SRC_HW << 27);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO18_GTIN2_CH2)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO18_GTIN2_CH2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO18_GTIN2_CH2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO18_GTIN2_CH2, PADI_CFG_IO18_GTIN2_CH2);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM2SRC_CH_1;  //enable external clock for CH2
    SYSCFG->GPIO_ENAUX_C &= ~((uint32_t)LL_GPIO_AUX_OUTPUT << 31);   //aux input PC31
    GPIOC->CTL |= (GPIO_SRC_HW << 31);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO24_GTIN2_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO24_GTIN2_CH4, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO24_GTIN2_CH4, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO24_GTIN2_CH4, PADI_CFG_IO24_GTIN2_CH4);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM2SRC_CH_3;  //enable external clock for CH4
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 25);   //aux input PC25
    GPIOC->CTL |= (GPIO_SRC_HW << 25);   //Hardware Source
  }
  else
  {
    return 0;
  }
  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G3 Input port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_ETR
  *            @arg TIM_PORT_BRK_IN
  *            @arg TIM_PORT_BRK2_IN
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_InputPort_G3(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim != TIMG3)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO20_GTIN3_CH2)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO20_GTIN3_CH2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO20_GTIN3_CH2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO20_GTIN3_CH2, PADI_CFG_IO20_GTIN3_CH2);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM3SRC_CH_1;  //enable external clock for CH2
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 29);   //aux input PC29
    GPIOC->CTL |= (GPIO_SRC_HW << 29);   //Hardware Source
  }
  else
  {
    return 0;
  }
  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G4 Input port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_ETR
  *            @arg TIM_PORT_BRK_IN
  *            @arg TIM_PORT_BRK2_IN
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @retval State (0: unvalid or 1 : vaild)
  */
static uint32_t TIM_InputPort_G4(TIM_TypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim != TIMG4)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO4_GTIN4_CH1)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO4_GTIN4_CH1, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO4_GTIN4_CH1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO4_GTIN4_CH1, PADI_CFG_IO4_GTIN4_CH1);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM4SRC_CH_0;  //enable external clock for CH1
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 1);   //aux input PC1
    GPIOC->CTL |= (GPIO_SRC_HW << 1);   //Hardware Source
  }
  else if ((Pad == PADI_IDX_IO21_GTIN4_CH2)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_PULLUP(PADI_IDX_IO21_GTIN4_CH2, RESET);    //Pull down
    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO21_GTIN4_CH2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO21_GTIN4_CH2, PADI_CFG_IO21_GTIN4_CH2);
    ICG->TIMER_EXCLK_EN_2 |= ICG_TMXC_GTM4SRC_CH_1;  //enable external clock for CH2
    SYSCFG->GPIO_ENAUX_C &= ~(LL_GPIO_AUX_OUTPUT << 28);   //aux input PC28
    GPIOC->CTL |= (GPIO_SRC_HW << 28);   //Hardware Source
  }
  else
  {
    return 0;
  }
  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM A1 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_ForcePort_A1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State)
{
#if defined(XT32H0xxB) 	
	
  uint32_t st = 1;

  if (htim->Instance != TIM1)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO10_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO10_ATOUT1_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO10_ATOUT1_CH1_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO10_ATOUT1_CH1_P, PADI_CFG_IO10_PB26);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 26);   //aux output  PB26
    GPIOB->CTL &= ~(0x1UL << 26);   //Hardware Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 26);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 26);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 26);
		}
  }
  else if((Pad == PADI_IDX_IO13_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO13_ATOUT1_CH1_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO13_ATOUT1_CH1_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO13_ATOUT1_CH1_N, PADI_CFG_IO13_PC16);
//    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 16);   //aux output PC16
    GPIOC->CTL &= ~(0x1UL << 16);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_1)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
//    }
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 16);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 16);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 16);
		}
  }
  else if((Pad == PADI_IDX_IO38_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO38_ATOUT1_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO38_ATOUT1_CH1_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO38_ATOUT1_CH1_P, PADI_CFG_IO38_PB12);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 12);   //aux output PB12
    GPIOB->CTL &= ~(0x1UL << 12);   //Hardware Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 12);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 12);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 12);
		}
  }
  else if((Pad == PADI_IDX_IO39_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO39_ATOUT1_CH1_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO39_ATOUT1_CH1_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO39_ATOUT1_CH1_N, PADI_CFG_IO39_PB11);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 11);   //aux output PB11
    GPIOB->CTL &= ~(0x1UL << 11);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_1)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
//    }
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 11);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 11);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 11);
		}
  }
  else if((Pad == PADI_IDX_IO57_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO57_ATOUT1_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO57_ATOUT1_CH1_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO57_ATOUT1_CH1_P, PADI_CFG_IO57_PB1);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 1);   //aux output PB1
    GPIOB->CTL &= ~(0x1UL << 1);   //Hardware Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 1);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 1);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 1);
		}
  }
  else if((Pad == PADI_IDX_IO58_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO58_ATOUT1_CH1_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO58_ATOUT1_CH1_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO58_ATOUT1_CH1_N, PADI_CFG_IO58_PB0);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 0);   //aux output PB0
    GPIOB->CTL &= ~(0x1UL << 0);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_1)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH1_OS);
//    }
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 0);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 0);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 0);
		}
  }
  else if((Pad == PADI_IDX_IO14_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO14_ATOUT1_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO14_ATOUT1_CH2_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO14_ATOUT1_CH2_P, PADI_CFG_IO14_PC17);
//    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 17);   //aux output PC17
    GPIOC->CTL &= ~(0x1UL << 17);   //Hardware Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 17);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 17);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 17);
		}
  }
  else if((Pad == PADI_IDX_IO15_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO15_ATOUT1_CH2_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO15_ATOUT1_CH2_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO15_ATOUT1_CH2_N, PADI_CFG_IO15_PC18);
//    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 18);   //aux output PC18
    GPIOC->CTL &= ~(0x1UL << 18);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_2)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
//    }
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 18);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 18);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 18);
		}
  }
  else if((Pad == PADI_IDX_IO35_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO35_ATOUT1_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO35_ATOUT1_CH2_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO35_ATOUT1_CH2_P, PADI_CFG_IO35_PB15);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 15);   //aux output PB15
    GPIOB->CTL &= ~(0x1UL << 15);   //Hardware Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 15);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 15);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 15);
		}
  }
  else if((Pad == PADI_IDX_IO36_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO36_ATOUT1_CH2_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO36_ATOUT1_CH2_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO36_ATOUT1_CH2_N, PADI_CFG_IO36_PB14);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 14);   //aux output PB14
    GPIOB->CTL &= ~(0x1UL << 14);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_2)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
//    }
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 14);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 14);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 14);
		}
  }
  else if((Pad == PADI_IDX_IO51_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO51_ATOUT1_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO51_ATOUT1_CH2_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO51_ATOUT1_CH2_P, PADI_CFG_IO51_PB17);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 17);   //aux output PB17
    GPIOB->CTL &= ~(0x1UL << 17);   //Hardware Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 17);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 17);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 17);
		}
  }
  else if((Pad == PADI_IDX_IO52_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO52_ATOUT1_CH2_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO52_ATOUT1_CH2_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO52_ATOUT1_CH2_N, PADI_CFG_IO52_PB16);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 16);   //aux output PB16
    GPIOB->CTL &= ~(0x1UL << 16);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_2)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA1_CH2_OS);
//    }
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 16);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 16);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 16);
		}
  }
  else if((Pad == PADI_IDX_IO5_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO5_ATOUT1_CH3_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO5_ATOUT1_CH3_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO5_ATOUT1_CH3_P, PADI_CFG_IO5_PC0);
//    GPIOC->CTL |= (0x1UL << 0);   //Hardware Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 0);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 0);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 0);
		}
  }
  else if((Pad == PADI_IDX_IO9_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO9_ATOUT1_CH3_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO9_ATOUT1_CH3_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO9_ATOUT1_CH3_N, PADI_CFG_IO9_PD15);
//    SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 15);   //aux output PD15
    GPIOD->CTL &= ~(0x1UL << 15);   //Hardware Source
//		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 15);
		if(State == 1)
		{
			GPIOD->DR |= (GPIO_MODE_OUTPUT << 15);
		}
		else
		{
			GPIOD->DR &= ~(GPIO_MODE_OUTPUT << 15);
		}
  }
  else if((Pad == PADI_IDX_IO28_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO28_ATOUT1_CH3_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO28_ATOUT1_CH3_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO28_ATOUT1_CH3_P, PADI_CFG_IO28_PB24);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 24);   //aux output PB24
    GPIOB->CTL &= ~(0x1UL << 24);   //Hardware Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 24);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 24);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 24);
		}
  }
  else if((Pad == PADI_IDX_IO29_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO29_ATOUT1_CH3_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO29_ATOUT1_CH3_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO29_ATOUT1_CH3_N, PADI_CFG_IO29_PC8);
//    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 8);   //aux output PC8
    GPIOC->CTL &= ~(0x1UL << 8);   //Hardware Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 8);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 8);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 8);
		}
  }
  else if((Pad == PADI_IDX_IO49_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO49_ATOUT1_CH3_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO49_ATOUT1_CH3_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO49_ATOUT1_CH3_P, PADI_CFG_IO49_PB19);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 19);   //aux output PB19
    GPIOB->CTL &= ~(0x1UL << 19);   //Hardware Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 19);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 19);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 19);
		}
  }
  else if((Pad == PADI_IDX_IO50_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO50_ATOUT1_CH3_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO50_ATOUT1_CH3_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO50_ATOUT1_CH3_N, PADI_CFG_IO50_PB18);
//    SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 18);   //aux output PB18
    GPIOB->CTL &= ~(0x1UL << 18);   //Hardware Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 18);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 18);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 18);
		}
  }
  else if((Pad == PADI_IDX_IO44_ATOUT1_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO44_ATOUT1_CH4, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO44_ATOUT1_CH4, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO44_ATOUT1_CH4, PADI_CFG_IO44_PD23);
//    SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 23);   //aux output PD23
    GPIOD->CTL &= ~(0x1UL << 23);   //Hardware Source
//		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 23);
		if(State == 1)
		{
			GPIOD->DR |= (GPIO_MODE_OUTPUT << 23);
		}
		else
		{
			GPIOD->DR &= ~(GPIO_MODE_OUTPUT << 23);
		}
  }
  else if((Pad == PADI_IDX_IO23_ATOUT1_BRKOUT2)&&(Channel==TIM_PORT_BRK2_OUT))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO23_ATOUT1_BRKOUT2, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO23_ATOUT1_BRKOUT2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO23_ATOUT1_BRKOUT2, PADI_CFG_IO23_PC26);
//    GPIOC->CTL |= (0x1UL << 26);   //Hardware Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 26);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 26);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 26);
		}
  }
  else if((Pad == PADI_IDX_IO24_ATOUT1_BRKOUT1)&&(Channel==TIM_PORT_BRK_OUT))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO24_ATOUT1_BRKOUT1, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO24_ATOUT1_BRKOUT1, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO24_ATOUT1_BRKOUT1, PADI_CFG_IO24_PC25);
//    GPIOC->CTL |= (0x1UL << 25);   //Hardware Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 25);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 25);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 25);
		}
  }
  else
  {
    st = 0;
  }

  return st;
#else
  return 0;
#endif /* XT32H0xxB */
}
	
/**
  * @brief  TIM A2 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_ForcePort_A2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIM2)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO18_ATOUT2_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO18_ATOUT2_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO18_ATOUT2_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO18_ATOUT2_CH1_P, PADI_CFG_IO18_PC31);
//    GPIOC->CTL |= (0x1UL << 31);   //Software Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 31);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 31);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 31);
		}
  }
  else if((Pad == PADI_IDX_IO19_ATOUT2_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO19_ATOUT2_CH1_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO19_ATOUT2_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO19_ATOUT2_CH1_N, PADI_CFG_IO19_PC30);
//    if(Channel==TIM_PORT_CHANNEL_1)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA2_CH1_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA2_CH1_OS);
//    }
//    GPIOC->CTL |= (0x1UL << 30);   //Software Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 30);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 30);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 30);
		}
  }
  else if((Pad == PADI_IDX_IO20_ATOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO20_ATOUT2_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO20_ATOUT2_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO20_ATOUT2_CH2_P, PADI_CFG_IO20_PC29);
//    GPIOC->CTL |= (0x1UL << 29);   //Software Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 29);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 29);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 29);
		}
  }
  else if((Pad == PADI_IDX_IO21_ATOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO21_ATOUT2_CH2_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO21_ATOUT2_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO21_ATOUT2_CH2_N, PADI_CFG_IO21_PC28);
//    if(Channel==TIM_PORT_CHANNEL_2)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMA2_CH2_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMA2_CH2_OS);
//    }
//    GPIOC->CTL |= (0x1UL << 28);   //Software Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 28);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 28);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 28);
		}
  }
  else if((Pad == PADI_IDX_IO2_ATOUT2_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO2_ATOUT2_CH3_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO2_ATOUT2_CH3_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO2_ATOUT2_CH3_P, PADI_CFG_IO2_PC3);
//    GPIOC->CTL |= (0x1UL << 3);   //Software Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 3);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 3);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 3);
		}
  }
  else if((Pad == PADI_IDX_IO3_ATOUT2_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO3_ATOUT2_CH3_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO3_ATOUT2_CH3_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO3_ATOUT2_CH3_N, PADI_CFG_IO3_PC2);
//    GPIOC->CTL |= (0x1UL << 2);   //Software Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 2);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 2);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 2);
		}
  }
  else if((Pad == PADI_IDX_IO54_ATOUT2_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO54_ATOUT2_CH4, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO54_ATOUT2_CH4, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO54_ATOUT2_CH4, PADI_CFG_IO54_PB4);
    //SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 4);   //aux output PB4
    //GPIOB->CTL |= (GPIO_SRC_HW << 4);   //Hardware Source
    GPIOB->CTL &= ~(0x1UL << 4);   //Software Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 4);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 4);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 4);
		}
  }
  else if((Pad == PADI_IDX_IO16_ATOUT2_BRKOUT1)&&(Channel==TIM_PORT_BRK_OUT))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO16_ATOUT2_BRKOUT1, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO16_ATOUT2_BRKOUT1, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO16_ATOUT2_BRKOUT1, PADI_CFG_IO16_PC19);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 19);   //aux output PC19
    //GPIOC->CTL |= (GPIO_SRC_HW << 19);   //Hardware Source
    GPIOC->CTL &= ~(0x1UL << 19);   //Software Source
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 19);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 19);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 19);
		}
  }
  else if((Pad == PADI_IDX_IO27_ATOUT2_BRKOUT2)&&(Channel==TIM_PORT_BRK2_OUT))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO27_ATOUT2_BRKOUT2, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO27_ATOUT2_BRKOUT2, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO27_ATOUT2_BRKOUT2, PADI_CFG_IO27_PB5);
//    GPIOB->CTL |= (0x1UL << 5);   //Software Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 5);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 5);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 5);
		}
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G1 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_ForcePort_G1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG1)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO43_GTOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO43_GTOUT1_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO43_GTOUT1_CH1_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO43_GTOUT1_CH1_P, PADI_CFG_IO43_PD22);
    //SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 22);   //aux output PD22
    GPIOD->CTL &= ~(0x1UL << 22);   //Software Source
//		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 22);
		if(State == 1)
		{
			GPIOD->DR |= (GPIO_MODE_OUTPUT << 22);
		}
		else
		{
			GPIOD->DR &= ~(GPIO_MODE_OUTPUT << 22);
		}
  }
  else if((Pad == PADI_IDX_IO30_GTOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO30_GTOUT1_CH1_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO30_GTOUT1_CH1_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO30_GTOUT1_CH1_N, PADI_CFG_IO30_PC9);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 9);   //aux output PC9
    GPIOC->CTL &= ~(0x1UL << 9);   //Software Source
//    if(Channel==TIM_PORT_CHANNEL_1)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG1_CH1_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG1_CH1_OS);
//    }
//		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 9);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 9);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 9);
		}
  }
  else if((Pad == PADI_IDX_IO53_GTOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO53_GTOUT1_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO53_GTOUT1_CH2_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO53_GTOUT1_CH2_P, PADI_CFG_IO53_PD8);
    //SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 8);   //aux output PD8
    GPIOD->CTL &= ~(0x1UL << 8);   //Software Source
//		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 8);
		if(State == 1)
		{
			GPIOD->DR |= (GPIO_MODE_OUTPUT << 8);
		}
		else
		{
			GPIOD->DR &= ~(GPIO_MODE_OUTPUT << 8);
		}
  }
  else if((Pad == PADI_IDX_IO60_GTOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO60_GTOUT1_CH3_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO60_GTOUT1_CH3_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO60_GTOUT1_CH3_P, PADI_CFG_IO60_PD16);
    //SYSCFG->GPIO_ENAUX_D |= (LL_GPIO_AUX_OUTPUT << 16);   //aux output PD16
    GPIOD->CTL &= ~(0x1UL << 16);   //Software Source
//		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 16);
		if(State == 1)
		{
			GPIOD->DR |= (GPIO_MODE_OUTPUT << 16);
		}
		else
		{
			GPIOD->DR &= ~(GPIO_MODE_OUTPUT << 16);
		}
  }
  else if((Pad == PADI_IDX_IO45_GTOUT1_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO45_GTOUT1_CH4, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO45_GTOUT1_CH4, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO45_GTOUT1_CH4, PADI_CFG_IO45_PB23);
//    GPIOB->CTL |= (0x1UL << 23);   //Software Source
//		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 23);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 23);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 23);
		}
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}
	
/**
  * @brief  TIM G2 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_ForcePort_G2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG2)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO22_GTOUT2_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO22_GTOUT2_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO22_GTOUT2_CH1_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO22_GTOUT2_CH1_P, PADI_CFG_IO22_PC27);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 27);   //aux output PC27
    GPIOC->CTL &= ~(0x1UL << 27);   //Software Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 27);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 27);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 27);
		}
 }
  else if((Pad == PADI_IDX_IO23_GTOUT2_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO23_GTOUT2_CH1_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO23_GTOUT2_CH1_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO23_GTOUT2_CH1_N, PADI_CFG_IO23_PC26);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 26);   //aux output PC26
//    GPIOC->CTL |= (GPIO_SRC_HW << 26);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_1)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG2_CH1_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG2_CH1_OS);
//    }
    GPIOC->CTL &= ~(0x1UL << 26);   //Software Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 26);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 26);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 26);
		}
  }
  else if((Pad == PADI_IDX_IO18_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO18_GTOUT2_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO18_GTOUT2_CH2_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO18_GTOUT2_CH2_P, PADI_CFG_IO18_PC31);
    //SYSCFG->GPIO_ENAUX_C |= ((uint32_t)LL_GPIO_AUX_OUTPUT << 31);   //aux output PC31
    GPIOC->CTL &= ~(0x1UL << 31);   //Hardware Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 31);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 31);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 31);
		}
  }
  else if((Pad == PADI_IDX_IO46_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO46_GTOUT2_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO46_GTOUT2_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO46_GTOUT2_CH2_P, PADI_CFG_IO46_PB22);
//    GPIOB->CTL |= (0x1UL << 22);   //Software Source
// 		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 22);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 22);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 22);
		}
  }
  else if((Pad == PADI_IDX_IO53_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO53_GTOUT2_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO53_GTOUT2_CH2_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO53_GTOUT2_CH2_P, PADI_CFG_IO53_PD8);
//    GPIOD->CTL |= (0x1UL << 8);   //Software Source
// 		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 8);
		if(State == 1)
		{
			GPIOD->DR |= (GPIO_MODE_OUTPUT << 8);
		}
		else
		{
			GPIOD->DR &= ~(GPIO_MODE_OUTPUT << 8);
		}
  }
  else if((Pad == PADI_IDX_IO19_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO19_GTOUT2_CH2_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO19_GTOUT2_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO19_GTOUT2_CH2_N, PADI_CFG_IO19_PC30);
//    if(Channel==TIM_PORT_CHANNEL_2)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
//    }
//    GPIOC->CTL |= (0x1UL << 30);   //Software Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 30);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 30);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 30);
		}
  }
  else if((Pad == PADI_IDX_IO55_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO55_GTOUT2_CH2_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO55_GTOUT2_CH2_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO55_GTOUT2_CH2_N, PADI_CFG_IO55_PB3);
    //SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 3);   //aux output PB3
    GPIOB->CTL &= ~(0x1UL << 3);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_2)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
//    }
// 		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 3);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 3);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 3);
		}
  }
  else if((Pad == PADI_IDX_IO60_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO60_GTOUT2_CH2_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO60_GTOUT2_CH2_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO60_GTOUT2_CH2_N, PADI_CFG_IO60_PD16);
//    if(Channel==TIM_PORT_CHANNEL_2)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG2_CH2_OS);
//    }
//    GPIOD->CTL |= (0x1UL << 16);   //Software Source
// 		GPIOD->DDR |= (GPIO_MODE_OUTPUT << 16);
		if(State == 1)
		{
			GPIOD->DR |= (GPIO_MODE_OUTPUT << 16);
		}
		else
		{
			GPIOD->DR &= ~(GPIO_MODE_OUTPUT << 16);
		}
  }
  else if((Pad == PADI_IDX_IO19_GTOUT2_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO19_GTOUT2_CH3_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO19_GTOUT2_CH3_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO19_GTOUT2_CH3_P, PADI_CFG_IO19_PC30);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 30);   //aux output PC30
    GPIOC->CTL &= ~(0x1UL << 30);   //Hardware Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 30);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 30);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 30);
		}
  }
  else if((Pad == PADI_IDX_IO56_GTOUT2_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO56_GTOUT2_CH3_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO56_GTOUT2_CH3_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO56_GTOUT2_CH3_N, PADI_CFG_IO56_PB2);
    //SYSCFG->GPIO_ENAUX_B |= (LL_GPIO_AUX_OUTPUT << 2);   //aux output PB2
    GPIOB->CTL &= ~(0x1UL << 2);   //Hardware Source
// 		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 2);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 2);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 2);
		}
  }
  else if((Pad == PADI_IDX_IO24_GTOUT2_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO24_GTOUT2_CH4, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO24_GTOUT2_CH4, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO24_GTOUT2_CH4, PADI_CFG_IO24_PC25);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 25);   //aux output PC30
    GPIOC->CTL &= ~(0x1UL << 25);   //Hardware Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 25);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 25);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 25);
		}
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G3 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_ForcePort_G3(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG3)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO47_GTOUT3_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO47_GTOUT3_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO47_GTOUT3_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO47_GTOUT3_CH1_P, PADI_CFG_IO47_PB21);
//    GPIOB->CTL |= (0x1UL << 21);   //Hardware Source
// 		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 21);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 21);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 21);
		}
  }
  else if((Pad == PADI_IDX_IO48_GTOUT3_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO48_GTOUT3_CH1_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO48_GTOUT3_CH1_N, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO48_GTOUT3_CH1_N, PADI_CFG_IO48_PB20);
//    if(Channel==TIM_PORT_CHANNEL_1)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG3_CH1_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG3_CH1_OS);
//    }
//    GPIOB->CTL |= (0x1UL << 20);   //Hardware Source
// 		GPIOB->DDR |= (GPIO_MODE_OUTPUT << 20);
		if(State == 1)
		{
			GPIOB->DR |= (GPIO_MODE_OUTPUT << 20);
		}
		else
		{
			GPIOB->DR &= ~(GPIO_MODE_OUTPUT << 20);
		}
  }
  else if((Pad == PADI_IDX_IO20_GTOUT3_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO20_GTOUT3_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO20_GTOUT3_CH2_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO20_GTOUT3_CH2_P, PADI_CFG_IO20_PC29);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 29);   //aux output PC29
    //GPIOC->CTL |= (GPIO_SRC_HW << 29);   //Hardware Source
    GPIOC->CTL &= ~(0x1UL << 29);   //Hardware Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 29);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 29);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 29);
		}
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G4 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_ForcePort_G4(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad, uint8_t State)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG4)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO4_GTOUT4_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO4_GTOUT4_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO4_GTOUT4_CH1_P, SET);
    __HAL_PADI_SET_CFG(PADI_IDX_IO4_GTOUT4_CH1_P, PADI_CFG_IO4_PC1);
//    GPIOC->CTL |= (0x1UL << 1);   //Hardware Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 1);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 1);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 1);
		}
  }
  else if((Pad == PADI_IDX_IO61_GTOUT4_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO61_GTOUT4_CH1_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO61_GTOUT4_CH1_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO61_GTOUT4_CH1_P, PADI_CFG_IO61_PC4);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 4);   //aux output PC4
    GPIOC->CTL &= ~(0x1UL << 4);   //Hardware Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 4);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 4);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 4);
		}
  }
  else if((Pad == PADI_IDX_IO62_GTOUT4_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO62_GTOUT4_CH1_N, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO62_GTOUT4_CH1_N, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO62_GTOUT4_CH1_N, PADI_CFG_IO62_PC5);
//    SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 5);   //aux output PC5
//    GPIOC->CTL |= (GPIO_SRC_HW << 5);   //Hardware Source
//    if(Channel==TIM_PORT_CHANNEL_1)
//    {
//      SYSCFG->TIM_CMS_OC &= ~(SYSCFG_TIMCMSOC_TIMG4_CH1_OS);
//    }
//    else
//    {
//      SYSCFG->TIM_CMS_OC |= (SYSCFG_TIMCMSOC_TIMG4_CH1_OS);
//    }
    GPIOC->CTL &= ~(0x1UL << 5);   //Hardware Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 5);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 5);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 5);
		}
  }
  else if((Pad == PADI_IDX_IO21_GTOUT4_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
//    __HAL_PADI_SET_PULLUP(PADI_IDX_IO21_GTOUT4_CH2_P, RESET);    //Pull down
//    __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO21_GTOUT4_CH2_P, SET);
//    __HAL_PADI_SET_CFG(PADI_IDX_IO21_GTOUT4_CH2_P, PADI_CFG_IO21_PC28);
    //SYSCFG->GPIO_ENAUX_C |= (LL_GPIO_AUX_OUTPUT << 28);   //aux output PC28
    GPIOC->CTL &= ~(0x1UL << 28);   //Hardware Source
// 		GPIOC->DDR |= (GPIO_MODE_OUTPUT << 28);
		if(State == 1)
		{
			GPIOC->DR |= (GPIO_MODE_OUTPUT << 28);
		}
		else
		{
			GPIOC->DR &= ~(GPIO_MODE_OUTPUT << 28);
		}
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM A1 switch Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_SwitchPWMPort_A1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
	
  uint32_t st = 1;

  if (htim->Instance != TIM1)
  {
    return 0;
  }
  if ((Pad == PADI_IDX_IO10_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 26);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO13_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 16);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO38_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 12);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO39_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 11);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO57_ATOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 1);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO58_ATOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 0);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO14_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 17);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO15_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 18);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO35_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 15);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO36_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 14);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO51_ATOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 17);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO52_ATOUT1_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 16);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO5_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO5_ATOUT1_CH3_P, PADI_CFG_IO5_ATOUT1_CH3_P);
  }
  else if((Pad == PADI_IDX_IO9_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    GPIOD->CTL |= (GPIO_SRC_HW << 15);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO28_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 24);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO29_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 8);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO49_ATOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 19);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO50_ATOUT1_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 18);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO44_ATOUT1_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    GPIOD->CTL |= (GPIO_SRC_HW << 23);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO23_ATOUT1_BRKOUT2)&&(Channel==TIM_PORT_BRK2_OUT))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO23_ATOUT1_BRKOUT2, PADI_CFG_IO23_ATOUT1_BRKOUT2);
  }
  else if((Pad == PADI_IDX_IO24_ATOUT1_BRKOUT1)&&(Channel==TIM_PORT_BRK_OUT))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO24_ATOUT1_BRKOUT1, PADI_CFG_IO24_ATOUT1_BRKOUT1);
  }
  else
  {
    st = 0;
  }

  return st;
#else
  return 0;
#endif /* XT32H0xxB */
}
	
/**
  * @brief  TIM A2 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_SwitchPWMPort_A2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIM2)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO18_ATOUT2_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO18_ATOUT2_CH1_P, PADI_CFG_IO18_ATOUT2_CH1_P);
  }
  else if((Pad == PADI_IDX_IO19_ATOUT2_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO19_ATOUT2_CH1_N, PADI_CFG_IO19_ATOUT2_CH1_N);
  }
  else if((Pad == PADI_IDX_IO20_ATOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO20_ATOUT2_CH2_P, PADI_CFG_IO20_ATOUT2_CH2_P);
  }
  else if((Pad == PADI_IDX_IO21_ATOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO21_ATOUT2_CH2_N, PADI_CFG_IO21_ATOUT2_CH2_N);
  }
  else if((Pad == PADI_IDX_IO2_ATOUT2_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO2_ATOUT2_CH3_P, PADI_CFG_IO2_ATOUT2_CH3_P);
  }
  else if((Pad == PADI_IDX_IO3_ATOUT2_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO3_ATOUT2_CH3_N, PADI_CFG_IO3_ATOUT2_CH3_N);
  }
  else if((Pad == PADI_IDX_IO54_ATOUT2_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 4);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO16_ATOUT2_BRKOUT1)&&(Channel==TIM_PORT_BRK_OUT))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 19);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO27_ATOUT2_BRKOUT2)&&(Channel==TIM_PORT_BRK2_OUT))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO27_ATOUT2_BRKOUT2, PADI_CFG_IO27_ATOUT2_BRKOUT2);
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G1 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_SwitchPWMPort_G1(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG1)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO43_GTOUT1_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    GPIOD->CTL |= (GPIO_SRC_HW << 22);   //Software Source
  }
  else if((Pad == PADI_IDX_IO30_GTOUT1_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 9);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO53_GTOUT1_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    GPIOD->CTL |= (GPIO_SRC_HW << 8);   //Software Source
  }
  else if((Pad == PADI_IDX_IO60_GTOUT1_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    GPIOD->CTL |= (GPIO_SRC_HW << 16);   //Software Source
  }
  else if((Pad == PADI_IDX_IO45_GTOUT1_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO45_GTOUT1_CH4, PADI_CFG_IO45_GTOUT1_CH4);
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}
	
/**
  * @brief  TIM G2 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_SwitchPWMPort_G2(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG2)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO22_GTOUT2_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 27);   //Software Source
 }
  else if((Pad == PADI_IDX_IO23_GTOUT2_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 26);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO18_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 31);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO46_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO46_GTOUT2_CH2_P, PADI_CFG_IO46_GTOUT2_CH2_P);
  }
  else if((Pad == PADI_IDX_IO53_GTOUT2_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO53_GTOUT2_CH2_P, PADI_CFG_IO53_GTOUT2_CH2_P);
  }
  else if((Pad == PADI_IDX_IO19_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO19_GTOUT2_CH2_N, PADI_CFG_IO19_GTOUT2_CH2_N);
  }
  else if((Pad == PADI_IDX_IO55_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 3);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO60_GTOUT2_CH2_N)&&((Channel==TIM_PORT_CHANNEL_2)||(Channel==TIM_PORT_CHANNEL_6)))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO60_GTOUT2_CH2_N, PADI_CFG_IO60_GTOUT2_CH2_N);
  }
  else if((Pad == PADI_IDX_IO19_GTOUT2_CH3_P)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 30);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO56_GTOUT2_CH3_N)&&(Channel==TIM_PORT_CHANNEL_3))
  {
    GPIOB->CTL |= (GPIO_SRC_HW << 2);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO24_GTOUT2_CH4)&&(Channel==TIM_PORT_CHANNEL_4))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 25);   //Hardware Source
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G3 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_SwitchPWMPort_G3(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG3)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO47_GTOUT3_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO47_GTOUT3_CH1_P, PADI_CFG_IO47_GTOUT3_CH1_P);
  }
  else if((Pad == PADI_IDX_IO48_GTOUT3_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO48_GTOUT3_CH1_N, PADI_CFG_IO48_GTOUT3_CH1_N);
  }
  else if((Pad == PADI_IDX_IO20_GTOUT3_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 29);   //Hardware Source
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}

/**
  * @brief  TIM G4 Force Output port
  * @param  htim pointer to TIM handle.
  * @param  Channel TIM Channel
  *          This parameter can be one of the following values:
  *            @arg TIM_PORT_CHANNEL_1: TIM Channel 1
  *            @arg TIM_PORT_CHANNEL_2: TIM Channel 2
  *            @arg TIM_PORT_CHANNEL_3: TIM Channel 3
  *            @arg TIM_PORT_CHANNEL_4: TIM Channel 4
  *            @arg TIM_PORT_CHANNEL_5: TIM Channel 5
  *            @arg TIM_PORT_CHANNEL_6: TIM Channel 6
  *            @arg TIM_PORT_BRK_OUT
  *            @arg TIM_PORT_BRK2_OUT
  * @param  Pad Port pad
  *          This parameter can be one of [0, 61]
  * @param  State (0: off or 1 : on)
  */
static uint32_t TIM_SwitchPWMPort_G4(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Pad)
{
#if defined(XT32H0xxB) 	
  if (htim->Instance != TIMG4)
  {
    return 0;
  }
  if((Pad == PADI_IDX_IO4_GTOUT4_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    __HAL_PADI_SET_CFG(PADI_IDX_IO4_GTOUT4_CH1_P, PADI_CFG_IO4_GTOUT4_CH1_P);
  }
  else if((Pad == PADI_IDX_IO61_GTOUT4_CH1_P)&&(Channel==TIM_PORT_CHANNEL_1))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 4);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO62_GTOUT4_CH1_N)&&((Channel==TIM_PORT_CHANNEL_1)||(Channel==TIM_PORT_CHANNEL_5)))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 5);   //Hardware Source
  }
  else if((Pad == PADI_IDX_IO21_GTOUT4_CH2_P)&&(Channel==TIM_PORT_CHANNEL_2))
  {
    GPIOC->CTL |= (GPIO_SRC_HW << 28);   //Hardware Source
  }
  else
  {
    return 0;
  }

  return 1;
#else
  return 0;
#endif /* XT32H0xxB */
}
/**
  * @}
  */

#endif /* HAL_TIM_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
