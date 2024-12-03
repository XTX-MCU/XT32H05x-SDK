/**
  ******************************************************************************
  * @file    xt32h0xx_hal_adc_port.c
  * @author  Software Team
  * @brief   ADC port HAL module driver.
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

/** @addtogroup ADCPort 
  * @brief ADC HAL module driver
  * @{
  */

#ifdef HAL_MDU_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @addtogroup ADCPort_Private_Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup ADCPort_Private_Functions
  * @{
  */
/**
  * @}
  */
/* Exported functions --------------------------------------------------------*/

/** @defgroup ADCPort_Exported_Functions ADCPort Exported Functions
  * @{
  */
/** @defgroup ADCPort_Exported_Functions_Group1 ADC Peripheral Port functions
  *  @brief  Peripheral Port functions
  * @{
  */
/* Peripheral port functions  ************************************************/
/**
  * @brief  Config the ADC input pad.
  * @param  Channel ADC Channel
  *   @arg @ref ADC_CHANNEL_1           
  *   @arg @ref ADC_CHANNEL_2           
  *   @arg @ref ADC_CHANNEL_3           
  *   @arg @ref ADC_CHANNEL_4           
  *   @arg @ref ADC_CHANNEL_5           
  *   @arg @ref ADC_CHANNEL_6           
  *   @arg @ref ADC_CHANNEL_7           
  *   @arg @ref ADC_CHANNEL_8           
  *   @arg @ref ADC_CHANNEL_9           
  *   @arg @ref ADC_CHANNEL_10          
  *   @arg @ref ADC_CHANNEL_11          
  *   @arg @ref ADC_CHANNEL_12          
  *   @arg @ref ADC_CHANNEL_13          
  *   @arg @ref ADC_CHANNEL_14          
  *   @arg @ref ADC_CHANNEL_15          
  *   @arg @ref ADC_CHANNEL_16          
  *   @arg @ref ADC_CHANNEL_17          
  *   @arg @ref ADC_CHANNEL_18          
  *   @arg @ref ADC_CHANNEL_19          
  *   @arg @ref ADC_CHANNEL_20          
  *   @arg @ref ADC_CHANNEL_21          
  *   @arg @ref ADC_CHANNEL_22          
  *   @arg @ref ADC_CHANNEL_23          
  *   @arg @ref ADC_CHANNEL_24          
  *   @arg @ref ADC_CHANNEL_25          
  *   @arg @ref ADC_CHANNEL_26          
  *   @arg @ref ADC_CHANNEL_27          
  *   @arg @ref ADC_CHANNEL_28          
  *   @arg @ref ADC_CHANNEL_29          
  *   @arg @ref ADC_CHANNEL_30          
  *   @arg @ref ADC_CHANNEL_31          
  *   @arg @ref ADC_CHANNEL_32          
  *   @arg @ref ADC_CHANNEL_33          
  *   @arg @ref ADC_CHANNEL_34          
  *   @arg @ref ADC_CHANNEL_35          
  *   @arg @ref ADC_CHANNEL_36          
  *   @arg @ref ADC_CHANNEL_37          
  *   @arg @ref ADC_CHANNEL_38          
  *   @arg @ref ADC_CHANNEL_39          
  *   @arg @ref ADC_CHANNEL_40          
  *   @arg @ref ADC_CHANNEL_41          
  *   @arg @ref ADC_CHANNEL_42          
  *   @arg @ref ADC_CHANNEL_43          
  *   @arg @ref ADC_CHANNEL_44           
  * @param  PIo positive input port or single-ended input port
  * @param  NIo negative input port
  * @retval HAL state
  */
HAL_StatusTypeDef HAL_ADC_InputPortConfig(uint32_t Channel, uint32_t PIo, uint32_t NIo)
{
#if defined(XT32H0xxB)
  switch (Channel)
  {
    case ADC_CHANNEL_1 :
      if((PIo == PADI_IDX_IO52_CH0) && (NIo == NULL))
      {
        /* single-ended*/
        __HAL_PADI_SET_PULLUP(PADI_IDX_IO52_CH0, RESET);    /* Pull none */
        __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO52_CH0, RESET);
        __HAL_PADI_SET_CFG(PADI_IDX_IO52_CH0, PADI_CFG_IO52_CH0);
      }
      else
      {
        /* differential-ended*/
        __HAL_PADI_SET_PULLUP(PIo, RESET);    /* Pull none */
        __HAL_PADI_SET_PULLDOWN(NIo, RESET);
        __HAL_PADI_SET_CFG(PIo, 0 << ((PIo & 0x7UL) << 2));
        __HAL_PADI_SET_CFG(NIo, 0 << ((NIo & 0x7UL) << 2));

        if(PIo == PADI_IDX_IO52_CH0P)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA1_PSRC), (PGA_1_PSRC_MAPTO_IO52));
        }
        else if(PIo == PADI_IDX_IO45_CH0P_CH20)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA1_PSRC), (PGA_1_PSRC_MAPTO_IO45));
        }
        else if(PIo == PADI_IDX_IO33_CH0P)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA1_PSRC), (PGA_1_PSRC_MAPTO_IO33));
        }

        if(NIo == PADI_IDX_IO51_CH0N_CTSU_SN_0)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA1_NSRC), (PGA_1_NSRC_MAPTO_IO51));
        }
        else if(NIo == PADI_IDX_IO34_CH0N)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA1_NSRC), (PGA_1_NSRC_MAPTO_IO34));
        }
      }
      break;
    case ADC_CHANNEL_2 :
      if((PIo == PADI_IDX_IO50_CH1) && (NIo == NULL))
      {
        /* single-ended*/
        __HAL_PADI_SET_PULLUP(PADI_IDX_IO50_CH1, RESET);    /* Pull none */
        __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO50_CH1, RESET);
        __HAL_PADI_SET_CFG(PADI_IDX_IO50_CH1, PADI_CFG_IO50_CH1);
      }
      else
      {
        /* differential-ended*/
        __HAL_PADI_SET_PULLUP(PIo, RESET);    /* Pull none */
        __HAL_PADI_SET_PULLDOWN(NIo, RESET);
        __HAL_PADI_SET_CFG(PIo, 0 << ((PIo & 0x7UL) << 2));
        __HAL_PADI_SET_CFG(NIo, 0 << ((NIo & 0x7UL) << 2));

        if(PIo == PADI_IDX_IO50_CH1P)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA2_PSRC), (PGA_2_PSRC_MAPTO_IO50));
        }
        else if(PIo == PADI_IDX_IO46_CH1P_CH21)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA2_PSRC), (PGA_2_PSRC_MAPTO_IO46));
        }
        else if(PIo == PADI_IDX_IO31_CH1P)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA2_PSRC), (PGA_2_PSRC_MAPTO_IO31));
        }

        if(NIo == PADI_IDX_IO49_CH1N_CTSU_SN_1)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA2_NSRC), (PGA_2_NSRC_MAPTO_IO49));
        }
        else if(NIo == PADI_IDX_IO32_CH1N)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA2_NSRC), (PGA_2_NSRC_MAPTO_IO32));
        }
      }
      break;
    case ADC_CHANNEL_3 :
      if((PIo == PADI_IDX_IO58_CH2) && (NIo == NULL))
      {
        /* single-ended*/
        __HAL_PADI_SET_PULLUP(PADI_IDX_IO58_CH2, RESET);    /* Pull none */
        __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO58_CH2, RESET);
        __HAL_PADI_SET_CFG(PADI_IDX_IO58_CH2, PADI_CFG_IO58_CH2);
      }
      else
      {
        /* differential-ended*/
        __HAL_PADI_SET_PULLUP(PIo, RESET);    /* Pull none */
        __HAL_PADI_SET_PULLDOWN(NIo, RESET);
        __HAL_PADI_SET_CFG(PIo, 0 << ((PIo & 0x7UL) << 2));
        __HAL_PADI_SET_CFG(NIo, 0 << ((NIo & 0x7UL) << 2));

        if(PIo == PADI_IDX_IO58_CH2P)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA3_PSRC), (PGA_3_PSRC_MAPTO_IO58));
        }
        else if(PIo == PADI_IDX_IO47_CH2P_CH22)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA3_PSRC), (PGA_3_PSRC_MAPTO_IO47));
        }
        else if(PIo == PADI_IDX_IO26_CH2P)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA3_PSRC), (PGA_3_PSRC_MAPTO_IO26));
        }

        if(NIo == PADI_IDX_IO57_CH2N_CTSU_SN_31)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA3_NSRC), (PGA_3_NSRC_MAPTO_IO57));
        }
        else if(NIo == PADI_IDX_IO27_CH2N)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA3_NSRC), (PGA_3_NSRC_MAPTO_IO27));
        }
      }
      break;
    case ADC_CHANNEL_4 :
      if((PIo == PADI_IDX_IO42_CH3) && (NIo == NULL))
      {
        /* single-ended*/
        __HAL_PADI_SET_PULLUP(PADI_IDX_IO42_CH3, RESET);    /* Pull none */
        __HAL_PADI_SET_PULLDOWN(PADI_IDX_IO42_CH3, RESET);
        __HAL_PADI_SET_CFG(PADI_IDX_IO42_CH3, PADI_CFG_IO42_CH3);
      }
      else
      {
        /* differential-ended*/
        __HAL_PADI_SET_PULLUP(PIo, RESET);    /* Pull none */
        __HAL_PADI_SET_PULLDOWN(NIo, RESET);
        __HAL_PADI_SET_CFG(PIo, 0 << ((PIo & 0x7UL) << 2));
        __HAL_PADI_SET_CFG(NIo, 0 << ((NIo & 0x7UL) << 2));

        if(PIo == PADI_IDX_IO42_CH3P_COMP4_P)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA4_PSRC), (PGA_4_PSRC_MAPTO_IO42));
        }
        else if(PIo == PADI_IDX_IO61_CH3P)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA4_PSRC), (PGA_4_PSRC_MAPTO_IO61));
        }
        else if(PIo == PADI_IDX_IO48_CH3P_CH23)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA4_PSRC), (PGA_4_PSRC_MAPTO_IO48));
        }

        if(NIo == PADI_IDX_IO62_CH3N)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA4_NSRC), (PGA_4_NSRC_MAPTO_IO62));
        }
        else if(NIo == PADI_IDX_IO41_CH3N_COMP4_N_CTSU_SN_9)
        {
          MODIFY_REG(MDU->COMP_CFG3, (MDU_CMPCFG3_PGA4_NSRC), (PGA_4_NSRC_MAPTO_IO41));
        }
      }
      break;
    case ADC_CHANNEL_5 :
    case ADC_CHANNEL_6 :
    case ADC_CHANNEL_7 :
    case ADC_CHANNEL_8 :
    case ADC_CHANNEL_9 :
    case ADC_CHANNEL_10:
    case ADC_CHANNEL_11:
    case ADC_CHANNEL_12:
    case ADC_CHANNEL_13:
    case ADC_CHANNEL_14:
    case ADC_CHANNEL_15:
    case ADC_CHANNEL_16:
    case ADC_CHANNEL_17:
    case ADC_CHANNEL_18:
    case ADC_CHANNEL_19:
    case ADC_CHANNEL_20:
    case ADC_CHANNEL_25:
    case ADC_CHANNEL_26:
    case ADC_CHANNEL_27:
    case ADC_CHANNEL_28:
    case ADC_CHANNEL_29:
    case ADC_CHANNEL_30:
    case ADC_CHANNEL_31:
    case ADC_CHANNEL_32:
    case ADC_CHANNEL_33:
    case ADC_CHANNEL_34:
    case ADC_CHANNEL_35:
    case ADC_CHANNEL_36:
    case ADC_CHANNEL_37:
    case ADC_CHANNEL_38:
    case ADC_CHANNEL_39:
    case ADC_CHANNEL_40:
    case ADC_CHANNEL_41:
    case ADC_CHANNEL_42:
    case ADC_CHANNEL_43:
    case ADC_CHANNEL_44:
      /* single-ended*/
      __HAL_PADI_SET_PULLUP(PIo, RESET);    /* Pull none */
      __HAL_PADI_SET_PULLDOWN(PIo, RESET);
      __HAL_PADI_SET_CFG(PIo, 8 << ((PIo & 0x7UL) << 2));
      break;
    default:
      break;
  }   
  return HAL_OK;
#endif /* XT32H0xxB */  
}
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup ADCPort_Private_Functions ADCPort Private Functions
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
