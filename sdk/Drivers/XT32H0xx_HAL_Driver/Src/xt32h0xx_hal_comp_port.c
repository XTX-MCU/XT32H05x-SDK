/**
  ******************************************************************************
  * @file    xt32h0xx_hal_comp_port.c
  * @author  Software Team
  * @brief   COMP port HAL module driver.
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

/** @addtogroup COMPPort 
  * @brief COMP HAL module driver
  * @{
  */

#ifdef HAL_MDU_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup COMPPort_Private_Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup COMPPort_Private_Functions
  * @{
  */
/**
  * @}
  */
/* Exported functions --------------------------------------------------------*/

/** @defgroup COMPPort_Exported_Functions COMPPort Exported Functions
  * @{
  */
/** @defgroup COMPPort_Exported_Functions_Group1 COMP Peripheral Port functions
  *  @brief  Peripheral Port functions
  * @{
  */
/* Peripheral port functions  ************************************************/
/**
  * @brief  Config the comparator Input IO.
  * @param  Channel Comp channel
  *   @arg @ref COMP_1
  *   @arg @ref COMP_2
  *   @arg @ref COMP_3
  *   @arg @ref COMP_4
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_COMP_InputPortConfig(uint32_t Channel)
{
#if defined(XT32H0xxB)  
  switch (Channel)
	{
    case COMP_1:
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO28_COMP1_P, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO28_COMP1_P, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO28_COMP1_P, PADI_CFG_IO28_COMP1_P);

      __HAL_PADI_SET_PULLUP(PADI_IDX_IO29_COMP1_N, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO29_COMP1_N, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO29_COMP1_N, PADI_CFG_IO29_COMP1_N);

      break;
    case COMP_2:
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO35_COMP2_P, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO35_COMP2_P, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO35_COMP2_P, PADI_CFG_IO35_COMP2_P);

      __HAL_PADI_SET_PULLUP(PADI_IDX_IO36_COMP2_N, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO36_COMP2_N, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO36_COMP2_N, PADI_CFG_IO36_COMP2_N);

      break;
    case COMP_3:
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO38_COMP3_P, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO38_COMP3_P, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO38_COMP3_P, PADI_CFG_IO38_COMP3_P);

      __HAL_PADI_SET_PULLUP(PADI_IDX_IO39_COMP3_N, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO39_COMP3_N, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO39_COMP3_N, PADI_CFG_IO39_COMP3_N);

      break;
    case COMP_4:
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO42_CH3P_COMP4_P, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO42_CH3P_COMP4_P, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO42_CH3P_COMP4_P, PADI_CFG_IO42_CH3P_COMP4_P);

      __HAL_PADI_SET_PULLUP(PADI_IDX_IO41_CH3N_COMP4_N_CTSU_SN_9, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO41_CH3N_COMP4_N_CTSU_SN_9, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO41_CH3N_COMP4_N_CTSU_SN_9, PADI_CFG_IO41_CH3N_COMP4_N_CTSU_SN_9);

      break;
    default:
      break;
	}
#endif /* XT32H0xxB */  
  return HAL_OK;
}

/**
  * @brief  Config the comparator output IO.
  * @param  Channel COMP channel
  *   @arg @ref COMP_1
  *   @arg @ref COMP_2
  *   @arg @ref COMP_3
  *   @arg @ref COMP_4
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_COMP_OutputPortConfig(uint32_t Channel)
{
#if defined(XT32H0xxB)   
  switch (Channel)
	{
    case COMP_1:
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO30_O_COMP1, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO30_O_COMP1, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO30_O_COMP1, PADI_CFG_IO30_O_COMP1);

      break;
    case COMP_2:
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO37_O_COMP2, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO37_O_COMP2, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO37_O_COMP2, PADI_CFG_IO37_O_COMP2);

      break;
    case COMP_3:
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO40_O_COMP3, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO40_O_COMP3, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO40_O_COMP3, PADI_CFG_IO40_O_COMP3);

      break;
    case COMP_4:
      __HAL_PADI_SET_PULLUP(PADI_IDX_IO44_O_COMP4, RESET);    //Pull none
      __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO44_O_COMP4, RESET);
      __HAL_PADI_SET_CFG(PADI_IDX_IO44_O_COMP4, PADI_CFG_IO44_O_COMP4);

      break;
    default:
      break;
	}
#endif /* XT32H0xxB */  
  return HAL_OK;
}
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup COMPPort_Private_Functions COMPPort Private Functions
  * @{
  */
/**
  * @}
  */

#endif /* HAL_MDU_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
