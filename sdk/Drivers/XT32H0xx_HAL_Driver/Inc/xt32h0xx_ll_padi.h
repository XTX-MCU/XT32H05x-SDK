/**
  ******************************************************************************
  * @file    xt32h0xx_ll_padi.h
  * @author  Software Team
  * @brief   Header file of PADI LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_PADI_H
#define XT32H0xx_LL_PADI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (PADI) 

/** @addtogroup PADI_LL PADI
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @addtogroup PADI_LL_Private_Constants
  * @{
  */
/** @defgroup PADI_LL_PC_PinCfgReg_Index PADI LL Pad Pin Configure Register Index
  * @{
  */
#define PADI_PINCFG_REG_0         (0)  
#define PADI_PINCFG_REG_1         (1)  
#define PADI_PINCFG_REG_2         (2)  
#define PADI_PINCFG_REG_3         (3)  
#define PADI_PINCFG_REG_4         (4)  
#define PADI_PINCFG_REG_5         (5)  
#define PADI_PINCFG_REG_6         (6)  
#define PADI_PINCFG_REG_7         (7)  
/**
  * @}
  */

/** @defgroup PADI_LL_PC_pullup_reg pin pullup register idx
  * @{
  */
#define PADI_IO_PULLUP_REG_0      (0)  
#define PADI_IO_PULLUP_REG_1      (1)  
/**
  * @}
  */

/** @defgroup PADI_LL_PC_pulldown_reg pin pulldown register idx
  * @{
  */
#define PADI_IO_PULLDW_REG_0      (0)  
#define PADI_IO_PULLDW_REG_1      (1)  
/**
  * @}
  */

/** @defgroup PADI_LL_PC_ds_reg pin ds register idx
  * @{
  */
#define PADI_IO_DS_REG_0          (0)  
#define PADI_IO_DS_REG_1          (1)  
/**
  * @}
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PADI_LL_Exported_Types PADI Exported Types
  * @{
  */
/** @defgroup PADI_LL_InitTypeDef PADI LL Init structures
  * @{
  */

/**
  * @brief LL PADI Init Structure definition
  */
typedef struct
{
  uint32_t Pad;               /*!< Specifies the PADI pins to be configured.
                                   This parameter can be any value of 0 to 63 */

  uint32_t Pull;              /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                                   This parameter can be a value of @ref PADI_LL_EC_Pull.

                                   PADI HW configuration can be modified afterwards using unitary function @ref LL_PADI_EnablePullUp() and LL_PADI_EnablePullDown().*/

  uint32_t Alternate;         /*!< Specifies the Peripheral to be connected to the selected pins.
                                   This parameter can be a value of @ref PADI_LL_EC_AF.
     
                                   PADI HW configuration can be modified afterwards using unitary function @ref LL_PADI_SetPinCfg().*/

  uint32_t DriveStrength;     /*!< Specifies the Peripheral to be connected to the selected pins.
                                   This parameter can be a value of @ref PADI_LL_EC_DriveStrengh.

                                   PADI HW configuration can be modified afterwards using unitary function @ref LL_PADI_SetDriveStrengthHigh() and LL_PADI_SetDriveStrengthLow().*/
} LL_PADI_InitTypeDef;

/**
  * @}
  */
/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @addtogroup PADI_LL_Exported_Constants PADI Exported Constants
  * @{
  */

/** @defgroup PADI_LL_EC_PinCfg PADI LL Pin Configure
  * @{
  */
#if defined(XT32H0xxAMPW)
#include "xt32h0xxampw_ll_padi.h"
#elif defined(XT32H0xxBMPW) 
#include "xt32h0xxbmpw_ll_padi.h" 
#elif defined(XT32H0xxA) 
#include "xt32h0xxampw_ll_padi.h" 
#elif defined(XT32H0xxB) 
#include "xt32h0xxb_ll_padi.h" 
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @defgroup PADI_LL_EC_Mode PADI Mode
  * @{
  */
#define LL_PADI_INPUT                 (0)
#define LL_PADI_OUTPUT                (1)
/**
  * @}
  */

/** @defgroup PADI_LL_EC_DriveStrengh PADI Drive Strengh
  * @{
  */
#define LL_PADI_DS_LOW                 (0)
#define LL_PADI_DS_HIGH                (1)
/**
  * @}
  */

/** @defgroup PADI_LL_EC_Pull PADI Output
  * @{
  */
#define LL_PADI_PULLNO                (0)
#define LL_PADI_PULLUP                (1)
#define LL_PADI_PULLDOWN              (2)
/**
  * @}
  */

/** @defgroup PADI_LL_EC_AF PADI Configure
  * @{
  */
#define LL_PADI_AF_0              (0)
#define LL_PADI_AF_1              (1)
#define LL_PADI_AF_2              (2)
#define LL_PADI_AF_3              (3)
#define LL_PADI_AF_4              (4)
#define LL_PADI_AF_5              (5)
#define LL_PADI_AF_6              (6)
#define LL_PADI_AF_7              (7)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PADI_LL_Exported_Macros PADI LL Exported Macros
  * @{
  */

/** @defgroup PADI_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in PADI register
  * @param  __INSTANCE__ PADI Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_PADI_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in PADI register
  * @param  __INSTANCE__ PADI Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_PADI_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PADI_LL_Exported_Functions PADI Exported Functions
  * @{
  */

/** @defgroup PADI_LL_Exported_Functions_Group1 PADI Pin configure
  * @{
  */

/**
  * @brief  Set pin configuration
  * @rmtoll PADI      LL_PADI_SetPinCfg
  * @param  Pin 0 to 63 
  * @param  cfg
  *         This parameter should ne one of the following values:
  *         @arg @ref PADI_PINCFG_REG_0
  *         @arg @ref PADI_PINCFG_REG_1
  *         @arg @ref PADI_PINCFG_REG_2
  *         @arg @ref PADI_PINCFG_REG_3
  *         @arg @ref PADI_PINCFG_REG_4
  *         @arg @ref PADI_PINCFG_REG_5
  *         @arg @ref PADI_PINCFG_REG_6
  *         @arg @ref PADI_PINCFG_REG_7
  */
__STATIC_INLINE void LL_PADI_SetPinCfg(uint32_t Pin, uint32_t cfg)
{
  uint32_t pos =  (Pin & 0x07) << 2;
  uint32_t mask = (0x0FUL << pos);
  uint32_t reg = Pin >> 3;
  switch (reg)
  {
    case PADI_PINCFG_REG_0:
      MODIFY_REG(PADI->PORTMUX_CFG_1, mask, cfg);
      break;
    case PADI_PINCFG_REG_1:
      MODIFY_REG(PADI->PORTMUX_CFG_2, mask, cfg);
      break;
    case PADI_PINCFG_REG_2:
      MODIFY_REG(PADI->PORTMUX_CFG_3, mask, cfg);
      break;
    case PADI_PINCFG_REG_3:
      MODIFY_REG(PADI->PORTMUX_CFG_4, mask, cfg);
      break;
    case PADI_PINCFG_REG_4:
      MODIFY_REG(PADI->PORTMUX_CFG_5, mask, cfg);
      break;
    case PADI_PINCFG_REG_5:
      MODIFY_REG(PADI->PORTMUX_CFG_6, mask, cfg);
      break;
    case PADI_PINCFG_REG_6:
      MODIFY_REG(PADI->PORTMUX_CFG_7, mask, cfg);
      break;
    case PADI_PINCFG_REG_7:
    default:
      MODIFY_REG(PADI->PORTMUX_CFG_8, mask, cfg);
      break;
  }
}

/**
  * @brief  Get pin configuration
  * @rmtoll PADI      LL_PADI_GetPinCfg
  * @param  Pin 0 to 63 
  * @retval Returned value configure
  */
__STATIC_INLINE uint32_t LL_PADI_GetPinCfg(uint32_t Pin)
{
  uint32_t res = 0;
  uint32_t pos = (Pin & 0x07) << 2;
  uint32_t mask = (0x0FUL << pos);
  uint32_t reg = Pin >> 3;
  switch (reg)
  {
    case PADI_PINCFG_REG_0:
      res = (READ_BIT(PADI->PORTMUX_CFG_1, mask));
      break;
    case PADI_PINCFG_REG_1:
      res = (READ_BIT(PADI->PORTMUX_CFG_2, mask));
      break;
    case PADI_PINCFG_REG_2:
      res = (READ_BIT(PADI->PORTMUX_CFG_3, mask));
      break;
    case PADI_PINCFG_REG_3:
      res = (READ_BIT(PADI->PORTMUX_CFG_4, mask));
      break;
    case PADI_PINCFG_REG_4:
      res = (READ_BIT(PADI->PORTMUX_CFG_5, mask));
      break;
    case PADI_PINCFG_REG_5:
      res = (READ_BIT(PADI->PORTMUX_CFG_6, mask));
      break;
    case PADI_PINCFG_REG_6:
      res = (READ_BIT(PADI->PORTMUX_CFG_7, mask));
      break;
    case PADI_PINCFG_REG_7:
    default:
      res = (READ_BIT(PADI->PORTMUX_CFG_8, mask));
      break;
  }
  return res;
}

/**
  * @brief  Enable Pull-up
  * @rmtoll IO_PULLUP_CFG     LL_PADI_EnablePullUp
  * @param  Pin 0 to 63
  */
__STATIC_INLINE void LL_PADI_EnablePullUp(uint32_t Pin)
{
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_PULLUP_REG_0:
      CLEAR_BIT(PADI->IO_PULLDW_CFG_1, 1 << pos);
      SET_BIT(PADI->IO_PULLUP_CFG_1, 1 << pos);
      break;
    case PADI_IO_PULLUP_REG_1:
    default:
      CLEAR_BIT(PADI->IO_PULLDW_CFG_2, 1 << pos);
      SET_BIT(PADI->IO_PULLUP_CFG_2, 1 << pos);
      break;
  }
}

/**
  * @brief  Disable Pull-up
  * @rmtoll IO_PULLUP_CFG     LL_PADI_DisablePullUp
  * @param  Pin
  */
__STATIC_INLINE void LL_PADI_DisablePullUp(uint32_t Pin)
{
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_PULLUP_REG_0:
      CLEAR_BIT(PADI->IO_PULLUP_CFG_1, 1 << pos);
      break;
    case PADI_IO_PULLUP_REG_1:
    default:
      CLEAR_BIT(PADI->IO_PULLUP_CFG_2, 1 << pos);
      break;
  }
}

/**
  * @brief  IsEnabled Pull-up
  * @rmtoll IO_PULLUP_CFG     LL_PADI_IsEnabledPullUp
  * @param  Pin
  * @retval Status
  */
__STATIC_INLINE uint32_t LL_PADI_IsEnabledPullUp(uint32_t Pin)
{
  uint32_t res;
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_PULLUP_REG_0:
      res = (READ_BIT(PADI->IO_PULLUP_CFG_1, 1 << pos) ? 1 : 0) ;
      break;
    case PADI_IO_PULLUP_REG_1:
    default:
      res = (READ_BIT(PADI->IO_PULLUP_CFG_2, 1 << pos) ? 1 : 0);
      break;
  }

  return res;
}

/**
  * @brief  Enable Pull-down
  * @rmtoll IO_PULLDW_CFG     LL_PADI_EnablePullDown
  * @param  Pin
  */
__STATIC_INLINE void LL_PADI_EnablePullDown(uint32_t Pin)
{
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_PULLDW_REG_0:
      CLEAR_BIT(PADI->IO_PULLUP_CFG_1, 1 << pos);
      SET_BIT(PADI->IO_PULLDW_CFG_1, 1 << pos);
      break;
    case PADI_IO_PULLDW_REG_1:
    default:
      CLEAR_BIT(PADI->IO_PULLUP_CFG_2, 1 << pos);
      SET_BIT(PADI->IO_PULLDW_CFG_2, 1 << pos);
      break;
  }
}

/**
  * @brief  Disable Pull-down
  * @rmtoll IO_PULLUP_CFG     LL_PADI_DisablePullDown
  * @param  Pin
  */
__STATIC_INLINE void LL_PADI_DisablePullDown(uint32_t Pin)
{
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_PULLDW_REG_0:
      CLEAR_BIT(PADI->IO_PULLDW_CFG_1, 1 << pos);
      break;
    case PADI_IO_PULLDW_REG_1:
    default:
      CLEAR_BIT(PADI->IO_PULLDW_CFG_2, 1 << pos);
      break;
  }
}

/**
  * @brief  IsEnabled Pull-down
  * @rmtoll IO_PULLUP_CFG     LL_PADI_IsEnabledPullDown
  * @param  Pin
  * @retval Status
  */
__STATIC_INLINE uint32_t LL_PADI_IsEnabledPullDown(uint32_t Pin)
{
  uint32_t res;
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_PULLDW_REG_0:
      res = (READ_BIT(PADI->IO_PULLDW_CFG_1, 1 << pos) ? 1 : 0) ;
      break;
    case PADI_IO_PULLDW_REG_1:
    default:
      res = (READ_BIT(PADI->IO_PULLDW_CFG_2, 1 << pos) ? 1 : 0);
      break;
  }

  return res;
}

/**
  * @brief  Set High drive strength
  * @rmtoll IO_DS_CFG     LL_PADI_SetDriveStrengthHigh
  * @param  Pin
  */
__STATIC_INLINE void LL_PADI_SetDriveStrengthHigh(uint32_t Pin)
{
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_DS_REG_0:
      SET_BIT(PADI->IO_DS_CFG_1, 1 << pos);
      break;
    case PADI_IO_DS_REG_1:
    default:
      SET_BIT(PADI->IO_DS_CFG_2, 1 << pos);
      break;
  }
}

/**
  * @brief  Set Low drive strength
  * @rmtoll IO_PULLUP_CFG     LL_PADI_SetDriveStrengthLow
  * @param  Pin
  */
__STATIC_INLINE void LL_PADI_SetDriveStrengthLow(uint32_t Pin)
{
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_DS_REG_0:
      CLEAR_BIT(PADI->IO_DS_CFG_1, 1 << pos);
      break;
    case PADI_IO_DS_REG_1:
    default:
      CLEAR_BIT(PADI->IO_DS_CFG_2, 1 << pos);
      break;
  }
}

/**
  * @brief  Get drive strength
  * @rmtoll IO_PULLUP_CFG     LL_PADI_GetDriveStrength
  * @param  Pin
  * @retval Status 0: low 1: high
  */
__STATIC_INLINE uint32_t LL_PADI_GetDriveStrength(uint32_t Pin)
{
  uint32_t res;
  uint32_t reg = Pin >> 5;
  uint32_t pos = Pin & 0x1F;
  switch(reg)
  {
    case PADI_IO_DS_REG_0:
      res = (READ_BIT(PADI->IO_DS_CFG_1, 1 << pos) ? 1 : 0) ;
      break;
    case PADI_IO_DS_REG_1:
    default:
      res = (READ_BIT(PADI->IO_DS_CFG_2, 1 << pos) ? 1 : 0);
      break;
  }

  return res;
}


/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup PADI_LL_Exported_Functions_Group2 Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_PADI_DeInit(PADI_TypeDef *PADIx);
ErrorStatus LL_PADI_Init(PADI_TypeDef *PADIx, LL_PADI_InitTypeDef *PADI_InitStruct);
void        LL_PADI_StructInit(LL_PADI_InitTypeDef *PADI_InitStruct);
#endif  /* USE_FULL_LL_DRIVER */
/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (PADI) */

/**
  * @}
  */

/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_PADI_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
