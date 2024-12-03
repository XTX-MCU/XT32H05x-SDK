/**
  ******************************************************************************
  * @file    xt32h0xx_ll_pga.h
  * @author  Software Team
  * @brief   Header file of MDU PGA LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_PGA_H
#define XT32H0xx_LL_PGA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (MDU)

/** @defgroup PGA_LL PGA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup PGA_LL_Private_Constants PGA Private Constants
  * @{
  */
#define LL_PGA_CHANNEL_NUM             (4)
/**
  * @}
  */


/* Private macros ------------------------------------------------------------*/
/** @defgroup PGA_LL_Private_Macros PGA Private Macros
  * @{
  */
/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
/** @defgroup PGA_LL_Exported_Types PGA Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PGA_LL_ES_INIT PGA Exported Init structure
  * @{
  */
/**
  * @brief  Structure definition of some features of PGA
  */
typedef struct
{
  uint32_t Gain;                      /*!< Set PGA 0 1 2 gain.
                                           This parameter can be a value of 0 to 0x7

                                           This feature can be modified afterwards using unitary function @ref LL_MDU_PGA_SetGain(). */
} LL_PGA_ChannelInitTypeDef;


/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup PGA_LL_Exported_Constants PGA Exported Constants
  * @{
  */

/** @defgroup PGA_LL_EC_POWER PGA power control
  * @{
  */
#define LL_PGA0_DISABLE                (0UL              )  /*!< PGA disanle */
#define LL_PGA0_ENABLE                 (MDU_PDCTRL_PGAEN1)  /*!< PGA enable */
#define LL_PGA1_DISABLE                (0UL              )  /*!< PGA disanle */
#define LL_PGA1_ENABLE                 (MDU_PDCTRL_PGAEN2)  /*!< PGA enable */
#define LL_PGA2_DISABLE                (0UL              )  /*!< PGA disanle */
#define LL_PGA2_ENABLE                 (MDU_PDCTRL_PGAEN3)  /*!< PGA enable */
#define LL_PGA3_DISABLE                (0UL              )  /*!< PGA disanle */
#define LL_PGA3_ENABLE                 (MDU_PDCTRL_PGAEN4)  /*!< PGA enable */
/**
  * @}
  */

/** @defgroup PGA_LL_EC_PGA Pga index
  * @{
  */
#define LL_PGA_1                       (0)  
#define LL_PGA_2                       (1)  
#define LL_PGA_3                       (2)  
#define LL_PGA_4                       (3)  
/**
  * @}
  */

/** @defgroup PGA_EC_Gain  PGA gain 
  * @{
  */
#define LL_PGA_GAIN_2                  (0)                                     /*!< PGA gain */
#define LL_PGA_GAIN_3                  (1)                                     /*!< PGA gain */
#define LL_PGA_GAIN_4                  (2)                                     /*!< PGA gain */
#define LL_PGA_GAIN_4P8                (3)                                     /*!< PGA gain */
#define LL_PGA_GAIN_6                  (4)                                     /*!< PGA gain */
#define LL_PGA_GAIN_8                  (5)                                     /*!< PGA gain */
#define LL_PGA_GAIN_9P6                (6)                                     /*!< PGA gain */
#define LL_PGA_GAIN_12                 (7)                                     /*!< PGA gain */

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PGA_LL_Exported_Macros PGA Exported Macros
  * @{
  */

/** @defgroup PGA_LL_EM_WRITE_READ Common write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in PGA register
  * @param  __INSTANCE__ PGA Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_PGA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in PGA register
  * @param  __INSTANCE__ PGA Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_PGA_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PGA_LL_Exported_Functions PGA Exported Functions
  * @{
  */

/** @defgroup PGA_LL_Exported_Functions_Group1 PGA power management
  * @{
  */
/**
  * @brief  Function to configure PGA channel diable
  * @rmtoll MDU_PDCTRL      PGAx_PD               LL_MDU_PGA0_Disable
  */
__STATIC_INLINE void LL_MDU_PGA0_Disable(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_PGAEN1);
}

/**
  * @brief  Function to configure PGA channel enable
  * @rmtoll MDU_PDCTRL      PGAx_PD               LL_MDU_PGA0_Enable
  */
__STATIC_INLINE void LL_MDU_PGA0_Enable(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_PGAEN1);
}

/**
  * @brief  Function to configure PGA channel disable
  * @rmtoll MDU_PDCTRL      PGAx_PD               LL_MDU_PGA1_Disable
  */
__STATIC_INLINE void LL_MDU_PGA1_Disable(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_PGAEN2);
}

/**
  * @brief  Function to configure PGA channel enable
  * @rmtoll MDU_PDCTRL      PGAx_PD               LL_MDU_PGA1_Enable
  */
__STATIC_INLINE void LL_MDU_PGA1_Enable(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_PGAEN2);
}

/**
  * @brief  Function to configure PGA channel disable
  * @rmtoll MDU_PDCTRL      PGAx_PD               LL_MDU_PGA2_Disable
  */
__STATIC_INLINE void LL_MDU_PGA2_Disable(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_PGAEN3);
}

/**
  * @brief  Function to configure PGA channel enable
  * @rmtoll MDU_PDCTRL      PGAx_PD               LL_MDU_PGA2_Enable
  */
__STATIC_INLINE void LL_MDU_PGA2_Enable(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_PGAEN3);
}

/**
  * @brief  Function to configure PGA channel disable
  * @rmtoll MDU_PDCTRL      PGAx_PD               LL_MDU_PGA3_Disable
  */
__STATIC_INLINE void LL_MDU_PGA3_Disable(void)
{
  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_PGAEN4);
}

/**
  * @brief  Function to configure PGA channel enable
  * @rmtoll MDU_PDCTRL      PGAx_PD               LL_MDU_PGA3_Enable
  */
__STATIC_INLINE void LL_MDU_PGA3_Enable(void)
{
  SET_BIT(MDU->PDCTRL, MDU_PDCTRL_PGAEN4);
}

/**
  * @}
  */

/** @defgroup PGA_LL_Exported_Functions_Group2 PGA configure
  * @{
  */
/**
  * @brief  Function to configure PGA bypass
  * @rmtoll MDU_PGA_CFG      pgax_gain               LL_MDU_PGA_SetGain
  * @param  PGA_Channel This parameter can be one of the following values:
  *         @arg @ref LL_PGA_1
  *         @arg @ref LL_PGA_2
  *         @arg @ref LL_PGA_3
  *         @arg @ref LL_PGA_4
  * @param  Gain the param can be one between 0 to 0x7
  */
__STATIC_INLINE void LL_MDU_PGA_SetGain(uint32_t PGA_Channel, uint32_t Gain)
{
  switch (PGA_Channel)
  {
    case LL_PGA_1:
      MODIFY_REG(MDU->PGA_CFG, MDU_PGACFG_PGA1GAIN, Gain);
      break;
    case LL_PGA_2:
      MODIFY_REG(MDU->PGA_CFG, MDU_PGACFG_PGA2GAIN, Gain);
      break;
    case LL_PGA_3:
      MODIFY_REG(MDU->PGA_CFG, MDU_PGACFG_PGA3GAIN, Gain);
      break;
    case LL_PGA_4:
      MODIFY_REG(MDU->PGA_CFG, MDU_PGACFG_PGA4GAIN, Gain);
      break;
    default:
      break;
  }
}

/**
  * @brief  Function to configure PGA bypass
  * @rmtoll MDU_PGA_CFG      pgax_gain               LL_MDU_PGA_GetGain
  * @param  PGA_Channel This parameter can be one of the following values:
  *         @arg @ref LL_PGA_1
  *         @arg @ref LL_PGA_2
  *         @arg @ref LL_PGA_3
  *         @arg @ref LL_PGA_4
  * @retval  Gain the value can be one between 0 to 0x7
  */
__STATIC_INLINE uint32_t LL_MDU_PGA_GetGain(uint32_t PGA_Channel)
{
	uint32_t temp = 0;
  switch (PGA_Channel)
  {
    case LL_PGA_1:
      temp = (uint32_t)(READ_BIT(MDU->PGA_CFG, MDU_PGACFG_PGA1GAIN) >> MDU_PGACFG_PGA1GAIN_Pos);
      break;
    case LL_PGA_2:
      temp = (uint32_t)(READ_BIT(MDU->PGA_CFG, MDU_PGACFG_PGA2GAIN) >> MDU_PGACFG_PGA2GAIN_Pos);
      break;
    case LL_PGA_3:
      temp = (uint32_t)(READ_BIT(MDU->PGA_CFG, MDU_PGACFG_PGA3GAIN) >> MDU_PGACFG_PGA3GAIN_Pos);
      break;
    case LL_PGA_4:
      temp = (uint32_t)(READ_BIT(MDU->PGA_CFG, MDU_PGACFG_PGA4GAIN) >> MDU_PGACFG_PGA4GAIN_Pos);
      break;
    default:
		  temp = 0;
      break;
  }
	return temp;
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PGA_LL_Exported_Functions_Group3 Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_PGA_ChannelDeInit(MDU_TypeDef *PGAx, uint32_t PGA_Channel);
ErrorStatus LL_PGA_ChannelInit(MDU_TypeDef *PGAx, uint32_t PGA_Channel, LL_PGA_ChannelInitTypeDef *PGA_ChannelInitStruct);
void        LL_PGA_ChannelStructInit(LL_PGA_ChannelInitTypeDef *PGA_ChannelInitStruct);

ErrorStatus LL_PGA_DeInit(MDU_TypeDef *PGAx);
ErrorStatus LL_PGA_Init(MDU_TypeDef *PGAx);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

#endif /* MDU */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif
#endif /* XT32H0xx_LL_PGA_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
