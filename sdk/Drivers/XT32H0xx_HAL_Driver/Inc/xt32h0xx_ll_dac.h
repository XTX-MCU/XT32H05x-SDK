/**
  ******************************************************************************
  * @file    xt32h0xx_ll_dac.h
  * @author  Software Team
  * @brief   Header file of MDU DAC LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_DAC_H
#define XT32H0xx_LL_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (MDU)

/** @defgroup DAC_LL DAC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup DAC_LL_Private_Constants DAC Private Constants
  * @{
  */
#define LL_DAC_CHANNEL_NUM             (2)
/**
  * @}
  */


/* Private macros ------------------------------------------------------------*/
/** @defgroup DAC_LL_Private_Macros DAC Private Macros
  * @{
  */
/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
/** @defgroup DAC_LL_Exported_Types DAC Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DAC_LL_ES_INIT DAC Exported Init structure
  * @{
  */
/**
  * @brief  Structure definition of some features of DAC
  */
typedef struct
{
  uint32_t Reference;                 /*!< Set DAC reference.
                                           This parameter can be a value of @ref PGA_LL_EC_DAC_REF

                                           This feature can be modified afterwards using unitary function @ref LL_MDU_DAC_SetRef(). */

  uint32_t ReferVoltageTune;          /*!< Configures DAC reference voltage.
                                           This parameter can be a value of @ref DAC_HAL_EC_REFVOL */

}LL_DAC_InitTypeDef;

typedef struct
{
  uint32_t BufferByPass;              /*!< Set DAC 0 & DAC 1 buffer bypass.
                                           This parameter can be a value @ref DAC_LL_EC_Bypass

                                           This feature can be modified afterwards using unitary function @ref LL_MDU_DAC_ByPassEnable(). */
} LL_DAC_ChannelInitTypeDef;
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup DAC_LL_Exported_Constants DAC Exported Constants
  * @{
  */

/** @defgroup DAC_LL_EC_POWER DAC power control
  * @{
  */
#define LL_DAC_POWERON                 (0UL             )   /*!< DAC power on */
#define LL_DAC_POWERDOWN               (MDU_PDCTRL_DACPD)   /*!< DAC power down */
/**
  * @}
  */

/** @defgroup DAC_LL_EC_Bypass DAC bypass control
  * @{
  */
#define LL_DAC_BUFFER_EN               (0)                  /*!< DAC 0 buffer enable */
#define LL_DAC_1_BUFFER_BYPASS         (MDU_DACCFG_DAC1BBP) /*!< DAC 0 buffer bypass */
#define LL_DAC_2_BUFFER_BYPASS         (MDU_DACCFG_DAC2BBP) /*!< DAC 1 buffer bypass */
/**
  * @}
  */

/** @defgroup PGA_LL_EC_DAC Dac index
  * @{
  */
#define LL_DAC_1                       (0)  
#define LL_DAC_2                       (1)  
/**
  * @}
  */

/** @defgroup PGA_LL_EC_DAC_REF Dac reference
  * @{
  */
#define LL_DAC_REF_1P2                 (0)
#define LL_DAC_REF_2P4                 (MDU_DACCFG_REFSEL_0)
#define LL_DAC_REF_3P6                 (MDU_DACCFG_REFSEL_1)
#define LL_DAC_REF_AVDD                (MDU_DACCFG_REFSEL_0 | MDU_DACCFG_REFSEL_1)
/**
  * @}
  */

/** @defgroup PGA_LL_EC_DAC_REFVOL Dac reference tune
  * @{
  */
#define LL_DAC_REFVOL_P57              (0)
#define LL_DAC_REFVOL_P58              (AON_IVREF_CFG_3_DAC_REF_0)
#define LL_DAC_REFVOL_P59              (AON_IVREF_CFG_3_DAC_REF_1)
#define LL_DAC_REFVOL_P60              (AON_IVREF_CFG_3_DAC_REF_1 | AON_IVREF_CFG_3_DAC_REF_0)
#define LL_DAC_REFVOL_P61              (AON_IVREF_CFG_3_DAC_REF_2)
#define LL_DAC_REFVOL_P62              (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_0)
#define LL_DAC_REFVOL_P63              (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_1)
#define LL_DAC_REFVOL_P64              (AON_IVREF_CFG_3_DAC_REF_2 | AON_IVREF_CFG_3_DAC_REF_1 | AON_IVREF_CFG_3_DAC_REF_0)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup DAC_LL_Exported_Macros DAC Exported Macros
  * @{
  */

/** @defgroup DAC_LL_EM_WRITE_READ Common write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in DAC register
  * @param  __INSTANCE__ DAC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_DAC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in DAC register
  * @param  __INSTANCE__ DAC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_DAC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */
/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup DAC_LL_Exported_Functions DAC Exported Functions
  * @{
  */

/** @defgroup DAC_LL_Exported_Functions_Group1 DAC power management
  * @{
  */
/**
  * @brief  Function to configure power on
  * @rmtoll MDU_PDCTRL      DACPD               LL_MDU_DAC_PowerOn
  */
__STATIC_INLINE void LL_MDU_DAC_PowerOn(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_DACPD);
}

/**
  * @brief  Function to configure power down
  * @rmtoll MDU_PDCTRL      DACPD               LL_MDU_DAC_PowerDown
  */
__STATIC_INLINE void LL_MDU_DAC_PowerDown(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_DACPD);
}

/**
  * @}
  */

/** @defgroup DAC_LL_Exported_Functions_Group2 DAC configure
  * @{
  */
/**
  * @brief  Function to configure DAC add
  * @rmtoll MDU_DAC_CFG      dacx_add               LL_MDU_DAC_SetDacAdd
  * @param  Dacx This parameter can be one of the following values:
  *         @arg @ref LL_DAC_1
  *         @arg @ref LL_DAC_2
  * @param  Add
  */
__STATIC_INLINE void LL_MDU_DAC_SetDacAdd(uint32_t Dacx, uint32_t Add)
{
  switch (Dacx)
  {
    case LL_DAC_1:
      MODIFY_REG(MDU->DAC_CFG, MDU_DACCFG_DAC1ADD, Add);
      break;
    case LL_DAC_2:
      MODIFY_REG(MDU->DAC_CFG, MDU_DACCFG_DAC2ADD, Add);
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure DAC add
  * @rmtoll MDU_DAC_CFG      dacx_add               LL_MDU_DAC_GetDacAdd
  * @param  Dacx This parameter can be one of the following values:
  *         @arg @ref LL_DAC_1
  *         @arg @ref LL_DAC_2
  * @retval dac_add
  */
__STATIC_INLINE uint32_t LL_MDU_DAC_GetDacAdd(uint32_t Dacx)
{
	uint32_t temp;
  switch (Dacx)
  {
    case LL_DAC_1:
      temp = (uint32_t)(READ_BIT(MDU->DAC_CFG, MDU_DACCFG_DAC1ADD) >> MDU_DACCFG_DAC1ADD_Pos);
      break;
    case LL_DAC_2:
      temp = (uint32_t)(READ_BIT(MDU->DAC_CFG, MDU_DACCFG_DAC2ADD) >> MDU_DACCFG_DAC2ADD_Pos);
      break;
    default:
      temp = 0;
      break;
  }
	return temp;
}

/**
  * @brief  Function to configure DAC reference selection
  * @rmtoll MDU_DAC_CFG      dacx_add               LL_MDU_DAC_SetRef
  * @param  Ref This parameter can be one of the following values:
  *         @arg @ref LL_DAC_REF_1P2 
  *         @arg @ref LL_DAC_REF_2P4 
  *         @arg @ref LL_DAC_REF_3P6 
  *         @arg @ref LL_DAC_REF_AVDD
  */
__STATIC_INLINE void LL_MDU_DAC_SetRef(uint32_t Ref)
{
  MODIFY_REG(MDU->DAC_CFG, MDU_DACCFG_REFSEL, Ref);
}

/**
  * @brief  Function to configure DAC reference selection
  * @rmtoll MDU_DAC_CFG      dacx_add               LL_MDU_DAC_GetRef
  * @retval Return value can be one of the following values:
  *         @arg @ref LL_DAC_REF_1P2 
  *         @arg @ref LL_DAC_REF_2P4 
  *         @arg @ref LL_DAC_REF_3P6 
  *         @arg @ref LL_DAC_REF_AVDD
  */
__STATIC_INLINE uint32_t LL_MDU_DAC_GetRef(void)
{
  return (uint32_t)(READ_BIT(MDU->DAC_CFG, MDU_DACCFG_REFSEL));
}

/**
  * @brief  Function to configure DAC reference selection
  * @rmtoll MDU_DAC_CFG      dacx_bypass               LL_MDU_DAC_ByPassEnable
  * @param  Dacx This parameter can be one of the following values:
  *         @arg @ref LL_DAC_1
  *         @arg @ref LL_DAC_2
  */
__STATIC_INLINE void LL_MDU_DAC_ByPassEnable(uint32_t Dacx)
{
  switch (Dacx)
  {
    case LL_DAC_1:
      SET_BIT(MDU->DAC_CFG, MDU_DACCFG_DAC1BBP);
      break;
    case LL_DAC_2:
      SET_BIT(MDU->DAC_CFG, MDU_DACCFG_DAC2BBP);
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure DAC reference selection
  * @rmtoll MDU_DAC_CFG      dacx_bypass               LL_MDU_DAC_ByPassDisable
  * @param  Dacx This parameter can be one of the following values:
  *         @arg @ref LL_DAC_1
  *         @arg @ref LL_DAC_2
  */
__STATIC_INLINE void LL_MDU_DAC_ByPassDisable(uint32_t Dacx)
{
  switch (Dacx)
  {
    case LL_DAC_1:
      CLEAR_BIT(MDU->DAC_CFG, MDU_DACCFG_DAC1BBP);
      break;
    case LL_DAC_2:
      CLEAR_BIT(MDU->DAC_CFG, MDU_DACCFG_DAC2BBP);
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure DAC reference selection
  * @rmtoll MDU_DAC_CFG      dacx_bypass               LL_MDU_DAC_IsByPass
  * @param  Dacx This parameter can be one of the following values:
  *         @arg @ref LL_DAC_1
  *         @arg @ref LL_DAC_2
  * @retval Status 0: no bypass 1: bypass
  */
__STATIC_INLINE uint32_t LL_MDU_DAC_IsByPassed(uint32_t Dacx)
{
	uint32_t temp = 0;
  switch (Dacx)
  {
    case LL_DAC_1:
      temp = (uint32_t)(READ_BIT(MDU->DAC_CFG, MDU_DACCFG_DAC1BBP) ? 1 : 0);
      break;
    case LL_DAC_2:
      temp = (uint32_t)(READ_BIT(MDU->DAC_CFG, MDU_DACCFG_DAC2BBP) ? 1 : 0);
      break;
    default:
      temp = 0;
      break;
  }
	return temp;
}

/**
  * @brief  Function to configure DAC reference tune
  * @rmtoll AON_IVREF_CFG_3      AON_IVREF_CFG_3_DAC_REF               LL_MDU_DAC_SetRefTune
  * @param  Ref This parameter can be one of the following values:
  *         @arg @ref LL_DAC_REFVOL_P57
  *         @arg @ref LL_DAC_REFVOL_P58
  *         @arg @ref LL_DAC_REFVOL_P59
  *         @arg @ref LL_DAC_REFVOL_P60
  *         @arg @ref LL_DAC_REFVOL_P61
  *         @arg @ref LL_DAC_REFVOL_P62
  *         @arg @ref LL_DAC_REFVOL_P63
  *         @arg @ref LL_DAC_REFVOL_P64
  */
__STATIC_INLINE void LL_MDU_DAC_SetRefTune(uint32_t Ref)
{
  MODIFY_REG(AON->IVREF_CFG_3, AON_IVREF_CFG_3_DAC_REF, Ref);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DAC_LL_Exported_Functions_Group3 Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_DAC_ChannelDeInit(MDU_TypeDef *DACx, uint32_t DAC_Channel);
ErrorStatus LL_DAC_ChannelInit(MDU_TypeDef *DACx, uint32_t DAC_Channel, LL_DAC_ChannelInitTypeDef *DAC_ChannelInitStruct);
void        LL_DAC_ChannelStructInit(LL_DAC_ChannelInitTypeDef *DAC_ChannelInitStruct);

ErrorStatus LL_DAC_DeInit(MDU_TypeDef *DACx);
ErrorStatus LL_DAC_Init(MDU_TypeDef *DACx, LL_DAC_InitTypeDef *DAC_InitStruct);
void        LL_DAC_StructInit(LL_DAC_InitTypeDef *DAC_InitStruct);
/**
  * @}
  */
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

#ifdef __cplusplus
}
#endif
#endif /* XT32H0xx_LL_DAC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
