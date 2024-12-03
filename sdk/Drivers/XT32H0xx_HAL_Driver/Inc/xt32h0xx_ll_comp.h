/**
  ******************************************************************************
  * @file    xt32h0xx_ll_comp.h
  * @author  Software Team
  * @brief   Header file of MDU COMP LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_COMP_H
#define XT32H0xx_LL_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (MDU)

/** @defgroup COMP_LL COMP
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup COMP_LL_Private_Constants COMP Private Constants
  * @{
  */
#define LL_COMP_CHANNEL_NUM            (4)
/**
  * @}
  */


/* Private macros ------------------------------------------------------------*/
/** @defgroup COMP_LL_Private_Macros COMP Private Macros
  * @{
  */
/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Types COMP Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup COMP_LL_ES_INIT COMP Exported Init structure
  * @{
  */
/**
  * @brief  Structure definition of some features of DAC
  */
typedef struct
{
  uint32_t PositiveSource;            /*!< Set COMP positive source.
                                           This parameter can be a value of @ref COMP_LL_EC_Positive_Source

                                           This feature can be modified afterwards using unitary function LL_COMP_SetPSource(). */

  uint32_t NegativeSource;            /*!< Set COMP negative source
                                           This parameter can be a value of @ref COMP_LL_EC_Negative_Source

                                           This feature can be modified afterwards using unitary function LL_COMP_SetNSource(). */

  uint32_t Hysteresis;                /*!< Set COMP hysteresis.
                                           This parameter can be a value 0 to 3

                                           This feature can be modified afterwards using unitary function LL_COMP_SetHysteresis(). */

  uint32_t Spd;                       /*!< Set COMP Spd.
                                           This parameter can be a value 0 to 7

                                           This feature can be modified afterwards using unitary function LL_COMP_SetSpd(). */

  uint32_t Polarity;                  /*!< Set COMP output polarity
                                           This parameter can be a value of @ref COMP_LL_EC_Output_Polarity

                                           This feature can be modified afterwards using unitary function LL_COMP_SetOutputPolarity(). */

} LL_COMP_ChannelInitTypeDef;

typedef struct
{
  uint32_t Filter;                    /*!< Set COMP output filter
                                           This parameter can be a value of @ref COMP_LL_EC_Output_Filter

                                           This feature can be modified afterwards using unitary function LL_COMP_SetOutputFilter(). */
} LL_COMP_InitTypeDef;
/**
  * @}
  */


#endif /* USE_FULL_LL_DRIVER */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Constants COMP Exported Constants
  * @{
  */

/** @defgroup COMP_LL_EC_POWER COMP power control
  * @{
  */
#define LL_COMP0_POWERON               (0UL              )  /*!< DAC power on */
#define LL_COMP0_POWERDOWN             (MDU_PDCTRL_CMP1PD)  /*!< DAC power down */
#define LL_COMP1_POWERON               (0UL              )  /*!< DAC power on */
#define LL_COMP1_POWERDOWN             (MDU_PDCTRL_CMP2PD)  /*!< DAC power down */
#define LL_COMP2_POWERON               (0UL              )  /*!< DAC power on */
#define LL_COMP2_POWERDOWN             (MDU_PDCTRL_CMP3PD)  /*!< DAC power down */
#define LL_COMP3_POWERON               (0UL              )  /*!< DAC power on */
#define LL_COMP3_POWERDOWN             (MDU_PDCTRL_CMP4PD)  /*!< DAC power down */
/**
  * @}
  */

/** @defgroup COMP_LL_EC_COMP_Index Comparator Index
  * @{
  */
#define LL_COMP_1                      (0)  
#define LL_COMP_2                      (1)  
#define LL_COMP_3                      (2)  
#define LL_COMP_4                      (3)  
/**
  * @}
  */

/** @defgroup COMP_LL_EC_Negative_Source Comparator Negative Source
  * @{
  */
#define LL_COMP_NEGATIVE_SOURCE_EXTERNAL      (0)  
#define LL_COMP_NEGATIVE_SOURCE_DAC1_OUT      (2)  
#define LL_COMP_NEGATIVE_SOURCE_DAC2_OUT      (3)  
/**
  * @}
  */

/** @defgroup COMP_LL_EC_Positive_Source Comparator Positive Source
  * @{
  */
#define LL_COMP_POSITIVE_SOURCE_EXTERNAL      (0)  
#define LL_COMP_POSITIVE_SOURCE_INTERNAL      (1)  
/**
  * @}
  */

/** @defgroup COMP_LL_EC_Hysteresis  Comparator Hysteresis 
  * @{
  */
#define LL_COMP_HYSTERESIS_NONE        (0)                                     /* no hysteresis */
#define LL_COMP_HYSTERESIS_10MV        (1)                                     /* 10mV hysteresis */
#define LL_COMP_HYSTERESIS_20MV        (2)                                     /* 20mV hysteresis */
#define LL_COMP_HYSTERESIS_30MV        (3)                                     /* 30mV hysteresis */
/**
  * @}
  */

/** @defgroup COMP_LL_EC_Speed  Comparator speed 
  * @{
  */
#define LL_COMP_SPEED_0                 (0)                                     /* low speed */
#define LL_COMP_SPEED_1                 (1)                                     /*  */
#define LL_COMP_SPEED_2                 (2)                                     /*  */
#define LL_COMP_SPEED_3                 (3)                                     /*  */
#define LL_COMP_SPEED_4                 (4)                                     /*  */
#define LL_COMP_SPEED_5                 (5)                                     /*  */
#define LL_COMP_SPEED_6                 (6)                                     /*  */
#define LL_COMP_SPEED_7                 (7)                                     /* high speed */
/**
  * @}
  */

/** @defgroup COMP_LL_EC_Output_Polarity Comparator Output Polarity
  * @{
  */
#define LL_COMP_OUTPUT_POL_NORMAL      (0)  
#define LL_COMP_OUTPUT_POL_INVERT      (1)  
/**
  * @}
  */

/** @defgroup COMP_LL_EC_Output_Filter Comparator Output Filter
  * @{
  */
#define LL_COMP_OUTPUT_FILTER_ENABLE   (0)  
#define LL_COMP_OUTPUT_FILTER_DISABLE  (MDU_CMPCFG3_OFLT)  
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Macros COMP Exported Macros
  * @{
  */

/** @defgroup COMP_LL_EM_WRITE_READ Common write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in COMP register
  * @param  __INSTANCE__ COMP Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_COMP_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in COMP register
  * @param  __INSTANCE__ COMP Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_COMP_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup COMP_LL_Exported_Functions COMP Exported Functions
  * @{
  */

/** @defgroup COMP_LL_Exported_Functions_Group1 COMP power management
  * @{
  */
/**
  * @brief  Function to configure power on
  * @rmtoll MDU_PDCTRL      CMP1PD               LL_MDU_CMP0_PowerOn
  */
__STATIC_INLINE void LL_MDU_COMP0_PowerOn(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP1PD);
}

/**
  * @brief  Function to configure power down
  * @rmtoll MDU_PDCTRL      CMP1PD               LL_MDU_CMP0_PowerDown
  */
__STATIC_INLINE void LL_MDU_COMP0_PowerDown(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP1PD);
}

/**
  * @brief  Function to configure power on
  * @rmtoll MDU_PDCTRL      CMP2PD               LL_MDU_CMP1_PowerOn
  */
__STATIC_INLINE void LL_MDU_COMP1_PowerOn(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP2PD);
}

/**
  * @brief  Function to configure power down
  * @rmtoll MDU_PDCTRL      CMP2PD               LL_MDU_CMP1_PowerDown
  */
__STATIC_INLINE void LL_MDU_COMP1_PowerDown(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP2PD);
}

/**
  * @brief  Function to configure power on
  * @rmtoll MDU_PDCTRL      CMP3PD               LL_MDU_CMP2_PowerOn
  */
__STATIC_INLINE void LL_MDU_COMP2_PowerOn(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP3PD);
}

/**
  * @brief  Function to configure power down
  * @rmtoll MDU_PDCTRL      CMP3PD               LL_MDU_CMP2_PowerDown
  */
__STATIC_INLINE void LL_MDU_COMP2_PowerDown(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP3PD);
}

/**
  * @brief  Function to configure power on
  * @rmtoll MDU_PDCTRL      CMP4PD               LL_MDU_CMP3_PowerOn
  */
__STATIC_INLINE void LL_MDU_COMP3_PowerOn(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP4PD);
}

/**
  * @brief  Function to configure power down
  * @rmtoll MDU_PDCTRL      CMP4PD               LL_MDU_CMP3_PowerDown
  */
__STATIC_INLINE void LL_MDU_COMP3_PowerDown(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_CMP4PD);
}

/**
  * @}
  */

/** @defgroup COMP_LL_Exported_Functions_Group2 COMP configure
  * @{
  */
/**
  * @brief  Function to configure COMP input source
  * @rmtoll MDU_COMP_CFG1      negative source               LL_MDU_COMP_SetNegativeSource
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @param Source This parameter can be one of the following values:
  *         @arg @ref LL_COMP_NEGATIVE_SOURCE_EXTERNAL    
  *         @arg @ref LL_COMP_NEGATIVE_SOURCE_DAC1_OUT    
  *         @arg @ref LL_COMP_NEGATIVE_SOURCE_DAC2_OUT    
  */
__STATIC_INLINE void LL_MDU_COMP_SetNegativeSource(uint32_t COMP_Channel, uint32_t Source)
{
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      MODIFY_REG(MDU->COMP_CFG1, MDU_CMPCFG1_NSRC_1, (Source << MDU_CMPCFG1_NSRC_1_Pos));
      break;
    case LL_COMP_2:
      MODIFY_REG(MDU->COMP_CFG1, MDU_CMPCFG1_NSRC_2, (Source << MDU_CMPCFG1_NSRC_2_Pos));
      break;
    case LL_COMP_3:
      MODIFY_REG(MDU->COMP_CFG1, MDU_CMPCFG1_NSRC_3, (Source << MDU_CMPCFG1_NSRC_3_Pos));
      break;
    case LL_COMP_4:
      MODIFY_REG(MDU->COMP_CFG1, MDU_CMPCFG1_NSRC_4, (Source << MDU_CMPCFG1_NSRC_4_Pos));
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure COMP input source
  * @rmtoll MDU_COMP_CFG1      negative source               LL_MDU_COMP_GetNegativeSource
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @retval Return value can be one of the following values:
  *         @arg @ref LL_COMP_NEGATIVE_SOURCE_EXTERNAL    
  *         @arg @ref LL_COMP_NEGATIVE_SOURCE_DAC1_OUT    
  *         @arg @ref LL_COMP_NEGATIVE_SOURCE_DAC2_OUT    
  */
__STATIC_INLINE uint32_t LL_MDU_COMP_GetNegativeSource(uint32_t COMP_Channel)
{
	uint32_t temp = 0;
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG1, MDU_CMPCFG1_NSRC_1) >> MDU_CMPCFG1_NSRC_1_Pos);
      break;
    case LL_COMP_2:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG1, MDU_CMPCFG1_NSRC_2) >> MDU_CMPCFG1_NSRC_2_Pos);
      break;
    case LL_COMP_3:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG1, MDU_CMPCFG1_NSRC_3) >> MDU_CMPCFG1_NSRC_3_Pos);
      break;
    case LL_COMP_4:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG1, MDU_CMPCFG1_NSRC_4) >> MDU_CMPCFG1_NSRC_4_Pos);
      break;
    default:
      temp = 0;
      break;
  }
	return temp;
}

/**
  * @brief  Function to configure COMP input source
  * @rmtoll MDU_COMP_CFG1      positive source               LL_MDU_COMP_SetPositiveSource
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @param Source This parameter can be one of the following values:
  *         @arg @ref LL_COMP_POSITIVE_SOURCE_EXTERNAL    
  *         @arg @ref LL_COMP_POSITIVE_SOURCE_INTERNAL    
  */
__STATIC_INLINE void LL_MDU_COMP_SetPositiveSource(uint32_t COMP_Channel, uint32_t Source)
{
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      MODIFY_REG(MDU->COMP_CFG1, MDU_CMPCFG1_PSRC_1, (Source << MDU_CMPCFG1_PSRC_1_Pos));
      break;
    case LL_COMP_2:
      MODIFY_REG(MDU->COMP_CFG1, MDU_CMPCFG1_PSRC_2, (Source << MDU_CMPCFG1_PSRC_2_Pos));
      break;
    case LL_COMP_3:
      MODIFY_REG(MDU->COMP_CFG1, MDU_CMPCFG1_PSRC_3, (Source << MDU_CMPCFG1_PSRC_3_Pos));
      break;
    case LL_COMP_4:
      MODIFY_REG(MDU->COMP_CFG1, MDU_CMPCFG1_PSRC_4, (Source << MDU_CMPCFG1_PSRC_4_Pos));
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure COMP input source
  * @rmtoll MDU_COMP_CFG1      positive source               LL_MDU_COMP_GetPositiveSource
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @retval Return value can be one of the following values:
  *         @arg @ref LL_COMP_POSITIVE_SOURCE_EXTERNAL    
  *         @arg @ref LL_COMP_POSITIVE_SOURCE_INTERNAL    
  */
__STATIC_INLINE uint32_t LL_MDU_COMP_GetPositiveSource(uint32_t COMP_Channel)
{
	uint32_t temp = 0;
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG1, MDU_CMPCFG1_PSRC_1) >> MDU_CMPCFG1_PSRC_1_Pos);
      break;
    case LL_COMP_2:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG1, MDU_CMPCFG1_PSRC_2) >> MDU_CMPCFG1_PSRC_2_Pos);
      break;
    case LL_COMP_3:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG1, MDU_CMPCFG1_PSRC_3) >> MDU_CMPCFG1_PSRC_3_Pos);
      break;
    case LL_COMP_4:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG1, MDU_CMPCFG1_PSRC_4) >> MDU_CMPCFG1_PSRC_4_Pos);
      break;
    default:
      temp = 0;
      break;
  }
	return temp;
}

/**
  * @brief  Function to configure COMP Hys
  * @rmtoll MDU_COMP_CFG2      hysteresis               LL_MDU_COMP_SetHysteresis
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @param Hysteresis This parameter can be one of the following values:
  *         @arg @ref LL_COMP_HYSTERESIS_NONE
  *         @arg @ref LL_COMP_HYSTERESIS_10MV
  *         @arg @ref LL_COMP_HYSTERESIS_20MV
  *         @arg @ref LL_COMP_HYSTERESIS_30MV
  */
__STATIC_INLINE void LL_MDU_COMP_SetHysteresis(uint32_t COMP_Channel, uint32_t Hysteresis)
{
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      MODIFY_REG(MDU->COMP_CFG2, MDU_CMPCFG2_HYS_1, (Hysteresis << MDU_CMPCFG2_HYS_1_Pos));
      break;
    case LL_COMP_2:
      MODIFY_REG(MDU->COMP_CFG2, MDU_CMPCFG2_HYS_2, (Hysteresis << MDU_CMPCFG2_HYS_2_Pos));
      break;
    case LL_COMP_3:
      MODIFY_REG(MDU->COMP_CFG2, MDU_CMPCFG2_HYS_3, (Hysteresis << MDU_CMPCFG2_HYS_3_Pos));
      break;
    case LL_COMP_4:
      MODIFY_REG(MDU->COMP_CFG2, MDU_CMPCFG2_HYS_4, (Hysteresis << MDU_CMPCFG2_HYS_4_Pos));
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure COMP Hys
  * @rmtoll MDU_COMP_CFG2      hysteresis               LL_MDU_COMP_GetHysteresis
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @retval Return valuer can be one of the following values:
  *         @arg @ref LL_COMP_HYSTERESIS_NONE
  *         @arg @ref LL_COMP_HYSTERESIS_10MV
  *         @arg @ref LL_COMP_HYSTERESIS_20MV
  *         @arg @ref LL_COMP_HYSTERESIS_30MV
  */
__STATIC_INLINE uint32_t LL_MDU_COMP_GetHysteresis(uint32_t COMP_Channel)
{
	uint32_t temp = 0;
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG2, MDU_CMPCFG2_HYS_1) >> MDU_CMPCFG2_HYS_1_Pos);
      break;
    case LL_COMP_2:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG2, MDU_CMPCFG2_HYS_2) >> MDU_CMPCFG2_HYS_2_Pos);
      break;
    case LL_COMP_3:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG2, MDU_CMPCFG2_HYS_3) >> MDU_CMPCFG2_HYS_3_Pos);
      break;
    case LL_COMP_4:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG2, MDU_CMPCFG2_HYS_4) >> MDU_CMPCFG2_HYS_4_Pos);
      break;
    default:
      temp = 0;
      break;
  }
	return temp;
}

/**
  * @brief  Function to configure COMP Spd
  * @rmtoll MDU_COMP_CFG2      hysteresis               LL_MDU_COMP_SetSpd
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @param Spd This parameter can be one of the following values:
  *         @arg @ref LL_COMP_SPEED_0  
  *         @arg @ref LL_COMP_SPEED_1  
  *         @arg @ref LL_COMP_SPEED_2  
  *         @arg @ref LL_COMP_SPEED_3  
  *         @arg @ref LL_COMP_SPEED_4  
  *         @arg @ref LL_COMP_SPEED_5  
  *         @arg @ref LL_COMP_SPEED_6  
  *         @arg @ref LL_COMP_SPEED_7  
  */
__STATIC_INLINE void LL_MDU_COMP_SetSpd(uint32_t COMP_Channel, uint32_t Spd)
{
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      MODIFY_REG(MDU->COMP_CFG2, MDU_CMPCFG2_SPD_1, (Spd << MDU_CMPCFG2_SPD_1_Pos));
      break;
    case LL_COMP_2:
      MODIFY_REG(MDU->COMP_CFG2, MDU_CMPCFG2_SPD_2, (Spd << MDU_CMPCFG2_SPD_2_Pos));
      break;
    case LL_COMP_3:
      MODIFY_REG(MDU->COMP_CFG2, MDU_CMPCFG2_SPD_3, (Spd << MDU_CMPCFG2_SPD_3_Pos));
      break;
    case LL_COMP_4:
      MODIFY_REG(MDU->COMP_CFG2, MDU_CMPCFG2_SPD_4, (Spd << MDU_CMPCFG2_SPD_4_Pos));
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure COMP Spd
  * @rmtoll MDU_COMP_CFG2      Spd               LL_MDU_COMP_GetSpd
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @retval Return valuer can be one of the following values:
  *         @arg @ref LL_COMP_SPEED_0  
  *         @arg @ref LL_COMP_SPEED_1  
  *         @arg @ref LL_COMP_SPEED_2  
  *         @arg @ref LL_COMP_SPEED_3  
  *         @arg @ref LL_COMP_SPEED_4  
  *         @arg @ref LL_COMP_SPEED_5  
  *         @arg @ref LL_COMP_SPEED_6  
  *         @arg @ref LL_COMP_SPEED_7  
  */
__STATIC_INLINE uint32_t LL_MDU_COMP_GetSpd(uint32_t COMP_Channel)
{
	uint32_t temp = 0;
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG2, MDU_CMPCFG2_SPD_1) >> MDU_CMPCFG2_SPD_1_Pos);
      break;
    case LL_COMP_2:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG2, MDU_CMPCFG2_SPD_2) >> MDU_CMPCFG2_SPD_2_Pos);
      break;
    case LL_COMP_3:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG2, MDU_CMPCFG2_SPD_3) >> MDU_CMPCFG2_SPD_3_Pos);
      break;
    case LL_COMP_4:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG2, MDU_CMPCFG2_SPD_4) >> MDU_CMPCFG2_SPD_4_Pos);
      break;
    default:
      temp = 0;
      break;
  }
	return temp;
}

/**
  * @brief  Function to configure COMP output polarity
  * @rmtoll MDU_COMP_CFG3      pol               LL_MDU_COMP_SetOutputPolarity
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @param Polarity This parameter can be one of the following values:
  *         @arg @ref LL_COMP_OUTPUT_POL_NORMAL
  *         @arg @ref LL_COMP_OUTPUT_POL_INVERT
  */
__STATIC_INLINE void LL_MDU_COMP_SetOutputPolarity(uint32_t COMP_Channel, uint32_t Polarity)
{
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      MODIFY_REG(MDU->COMP_CFG3, MDU_CMPCFG3_OPOL_0, (Polarity << MDU_CMPCFG3_OPOL_Pos));
      break;
    case LL_COMP_2:
      MODIFY_REG(MDU->COMP_CFG3, MDU_CMPCFG3_OPOL_1, (Polarity << (MDU_CMPCFG3_OPOL_Pos+1)));
      break;
    case LL_COMP_3:
      MODIFY_REG(MDU->COMP_CFG3, MDU_CMPCFG3_OPOL_2, (Polarity << (MDU_CMPCFG3_OPOL_Pos+2)));
      break;
    case LL_COMP_4:
      MODIFY_REG(MDU->COMP_CFG3, MDU_CMPCFG3_OPOL_3, (Polarity << (MDU_CMPCFG3_OPOL_Pos+3)));
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure COMP output polarity
  * @rmtoll MDU_COMP_CFG3      pol               LL_MDU_COMP_GetOutputPolarity
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @retval Return value can be one of the following values:
  *         @arg @ref LL_COMP_OUTPUT_POL_NORMAL
  *         @arg @ref LL_COMP_OUTPUT_POL_INVERT
  */
__STATIC_INLINE uint32_t LL_MDU_COMP_GetOutputPolarity(uint32_t COMP_Channel)
{
	uint32_t temp = 0;
  switch(COMP_Channel)
  {
    case LL_COMP_1:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG3, MDU_CMPCFG3_OPOL_0) >> MDU_CMPCFG3_OPOL_Pos);
      break;
    case LL_COMP_2:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG3, MDU_CMPCFG3_OPOL_1) >> (MDU_CMPCFG3_OPOL_Pos+1));
      break;
    case LL_COMP_3:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG3, MDU_CMPCFG3_OPOL_2) >> (MDU_CMPCFG3_OPOL_Pos+2));
      break;
    case LL_COMP_4:
      temp = (uint32_t)(READ_BIT(MDU->COMP_CFG3, MDU_CMPCFG3_OPOL_3) >> (MDU_CMPCFG3_OPOL_Pos+3));
      break;
    default:
		  temp = 0;
      break;
  }
	return temp;
}

/**
  * @brief  Function to configure COMP output filter
  * @rmtoll MDU_COMP_CFG3      OUT_FLT               LL_MDU_COMP_SetOutputFilter
  * @param Filter This parameter can be one of the following values:
  *         @arg @ref LL_COMP_OUTPUT_FILTER_ENABLE
  *         @arg @ref LL_COMP_OUTPUT_FILTER_DISABLE
  */
__STATIC_INLINE void LL_MDU_COMP_SetOutputFilter(uint32_t Filter)
{
  MODIFY_REG(MDU->COMP_CFG3, MDU_CMPCFG3_OFLT, Filter);
}

/**
  * @brief  Function to get COMP output filter
  * @rmtoll MDU_COMP_CFG3      OUT_FLT               LL_MDU_COMP_GetOutputFilter
  * @retval Return value can be one of the following values:
  *         @arg @ref LL_COMP_OUTPUT_FILTER_ENABLE
  *         @arg @ref LL_COMP_OUTPUT_FILTER_DISABLE
  */
__STATIC_INLINE uint32_t LL_MDU_COMP_GetOutputFilter(void)
{
  return (uint32_t)(READ_BIT(MDU->COMP_CFG3, MDU_CMPCFG3_OFLT));
}

#if defined(XT32H0xxAMPW) || defined(XT32H0xxBMPW)
/**
  * @brief  Function to Get COMP output
  * @rmtoll MDU_ADC_RESULT      CMP_OUTPUT               LL_MDU_COMP_GetOutput
  * @param  COMP_Channel This parameter can be one of the following values:
  *         @arg @ref LL_COMP_1
  *         @arg @ref LL_COMP_2
  *         @arg @ref LL_COMP_3
  *         @arg @ref LL_COMP_4
  * @retval Return value can be SET or RESET
  */
__STATIC_INLINE uint32_t LL_MDU_COMP_GetOutput(uint32_t COMP_Channel)
{
  return (uint32_t)((READ_BIT(MDU->ADC_STATUS, (MDU_ADCST_CMPOUT_0 << (COMP_Channel)))) ? SET : RESET);
}
#endif /* XT32H0xxAMPW || XT32H0xxBMPW */
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup COMP_LL_Exported_Functions_Group3 Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_COMP_ChannelDeInit(MDU_TypeDef *COMPx, uint32_t COMP_Channel);
ErrorStatus LL_COMP_ChannelInit(MDU_TypeDef *COMPx, uint32_t COMP_Channel, LL_COMP_ChannelInitTypeDef *COMP_ChannelInitStruct);
void        LL_COMP_ChannelStructInit(LL_COMP_ChannelInitTypeDef *COMP_ChannelInitStruct);

ErrorStatus LL_COMP_DeInit(MDU_TypeDef *COMPx);
ErrorStatus LL_COMP_Init(MDU_TypeDef *COMPx, LL_COMP_InitTypeDef *COMP_InitStruct);
void        LL_COMP_StructInit(LL_COMP_InitTypeDef *COMP_InitStruct);
/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* MDU */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif /* XT32H0xx_LL_COMP_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
