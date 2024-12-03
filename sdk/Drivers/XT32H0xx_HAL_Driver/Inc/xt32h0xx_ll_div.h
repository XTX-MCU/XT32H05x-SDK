/**
  ******************************************************************************
  * @file    xt32h0xx_ll_div.h
  * @author  Software Team
  * @brief   Header file of DIV LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_DIV_H
#define XT32H0xx_LL_DIV_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined(HDIV)

/** @defgroup DIV_LL DIV
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup DIV_LL_Exported_Constants DIV Exported Constants
  * @{
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup DIV_LL_Exported_Macros DIV Exported Macros
  * @{
  */

/** @defgroup DIV_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in DIV register
  * @param  __INSTANCE__ DIV Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_DIV_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, __VALUE__)

/**
  * @brief  Read a value in DIV register
  * @param  __INSTANCE__ DIV Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_DIV_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup DIV_LL_Exported_Functions DIV Exported Functions
  * @{
  */

/** @defgroup DIV_LL_Exported_Functions_Group1 DIV Configuration functions
  * @{
  */

/**
  * @brief  Set DIV A.
  * @param  DIVx DIV Instance
  * @param  divA A
  */
__STATIC_INLINE void LL_DIV_SetA(DIV_TypeDef *DIVx, uint32_t divA)
{
  WRITE_REG(DIVx->HDIV_A, divA);
}

/**
  * @brief  Set DIV B.
  * @param  DIVx DIV Instance
  * @param  divB B
  */
__STATIC_INLINE void LL_DIV_SetB(DIV_TypeDef *DIVx, uint32_t divB)
{
  WRITE_REG(DIVx->HDIV_B, divB);
}

/**
  * @brief  Get DIV Q.
  * @param  DIVx DIV Instance
  * @param  pdivQ a pointer to Q
  */
__STATIC_INLINE void LL_DIV_GetQ(DIV_TypeDef *DIVx, uint32_t* pdivQ)
{
  *pdivQ = READ_REG(DIVx->HDIV_Q);
}

/**
  * @brief  Get DIV R.
  * @param  DIVx DIV Instance
  * @param  pdivR a pointer to R
  */
__STATIC_INLINE void LL_DIV_GetR(DIV_TypeDef *DIVx, uint32_t* pdivR)
{
  *pdivR = READ_REG(DIVx->HDIV_R);
}

/**
  * @}
  */

/** @defgroup DIV_LL_Exported_Functions_Group2 Data_Management
  * @{
  */

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DIV_LL_Exported_Functions_Group3 Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_DIV_DeInit(DIV_TypeDef *DIVx);

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

#endif /* defined(HDIV) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_DIV_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
