/**
  ******************************************************************************
  * @file    xt32h0xx_ll_crc.h
  * @author  Software Team
  * @brief   Header file of CRC LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_CRC_H
#define XT32H0xx_LL_CRC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined(CRC)

/** @defgroup CRC_LL CRC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup CRC_LL_Exported_Constants CRC Exported Constants
  * @{
  */

/** @defgroup CRC_LL_EC_POLY Polynomial length
  * @{
  */
#define LL_CRC_POLY_32                 0x00000000U                             /*!< 32 bits Polynomial 0x41C11DB7 */
#define LL_CRC_POLY_8                  (CRC_CFG_POLY_0)                        /*!< 8 bits Polynomial 0x07 */
#define LL_CRC_POLY_16_0               (CRC_CFG_POLY_1)                        /*!< 16 bits Polynomial 0x1021 */
#define LL_CRC_POLY_16_1               (CRC_CFG_POLY_1 | CRC_CFG_POLY_0)       /*!< 16 bits Polynomial 0x8005 */
/**
  * @}
  */

/** @defgroup CRC_LL_EC_INDATA_REVERSE Input Data Reverse
  * @{
  */
#define LL_CRC_DATA_REVERSE_NONE       0x00000000U                             /*!< Input and output Data bit order not affected */
#define LL_CRC_DATA_REVERSE_ENABLE     CRC_CFG_REFLECT                         /*!< Input and output Data bit reversal done by byte */
/**
  * @}
  */

/** @defgroup CRC_LL_EC_OUT_XOR Output Data XOR
  * @{
  */
#define LL_CRC_OUTPUT_XOR_NONE         0x00000000U                             /*!< Input and output Data bit order not affected */
#define LL_CRC_OUTPUT_XOR_ENABLE       CRC_CFG_XOR_EN                             /*!< Input and output Data bit reversal done by byte */
/**
  * @}
  */

/** @defgroup CRC_LL_EC_Default_Polynomial_Value    Default CRC generating polynomial value
  * @brief    Normal representation of this polynomial value is
  *           X^32 + X^26 + X^23 + X^22 + X^16 + X^12 + X^11 + X^10 +X^8 + X^7 + X^5 + X^4 + X^2 + X + 1 .
  * @{
  */
#define LL_CRC_CRC32_POLY              0x04C11DB7U                             /*!< CRC generating polynomial value */
#define LL_CRC_CRC8_POLY               0x07U                                   /*!< CRC generating polynomial value */
#define LL_CRC_CRC16_0_POLY            0x1021U                                 /*!< CRC generating polynomial value */
#define LL_CRC_CRC16_1_POLY            0x8005U                                 /*!< CRC generating polynomial value */
/**
  * @}
  */

/** @defgroup CRC_LL_EC_Default_InitValue    Default CRC computation initialization value
  * @{
  */
#define LL_CRC_DEFAULT_CRC_INITVALUE   0                                       /*!< Default CRC computation initialization value */
/**
  * @}
  */

/** @defgroup CRC_LL_EC_Default_XorValue    Default CRC computation initialization value
  * @{
  */
#define LL_CRC_DEFAULT_CRC_XORVALUE    0                                       /*!< Default CRC computation initialization value */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup CRC_LL_Exported_Macros CRC Exported Macros
  * @{
  */

/** @defgroup CRC_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in CRC register
  * @param  __INSTANCE__ CRC Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_CRC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, __VALUE__)

/**
  * @brief  Read a value in CRC register
  * @param  __INSTANCE__ CRC Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_CRC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup CRC_LL_Exported_Functions CRC Exported Functions
  * @{
  */

/** @defgroup CRC_LL_Exported_Functions_Group1 CRC Configuration functions
  * @{
  */

/**
  * @brief  Reset the CRC calculation unit.
  * @note   If Programmable Initial CRC value feature
  *         is available, also set the Data Register to the value stored in the
  *         CRC_INIT register, otherwise, reset Data Register to its default value.
  * @rmtoll RESULT           RESULT         LL_CRC_ResetCRCCalculationUnit
  * @param  CRCx CRC Instance
  */
__STATIC_INLINE void LL_CRC_ResetCRCCalculationUnit(CRC_TypeDef *CRCx)
{
    READ_REG(CRCx->RESULT);
}

/**
  * @brief  Configure the polynomial.
  * @rmtoll CFG           POLY      LL_CRC_SetPolynomial
  * @param  CRCx CRC Instance
  * @param  Poly This parameter can be one of the following values:
  *         @arg @ref LL_CRC_POLY_32
  *         @arg @ref LL_CRC_POLY_8
  *         @arg @ref LL_CRC_POLY_16_0
  *         @arg @ref LL_CRC_POLY_16_1
  */
__STATIC_INLINE void LL_CRC_SetPolynomial(CRC_TypeDef *CRCx, uint32_t Poly)
{
  MODIFY_REG(CRCx->CFG, CRC_CFG_POLY, Poly);
}

/**
  * @brief  Return the polynomial.
  * @rmtoll CFG          POLY      LL_CRC_GetPolynomial
  * @param  CRCx CRC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_CRC_POLY_32
  *         @arg @ref LL_CRC_POLY_8
  *         @arg @ref LL_CRC_POLY_16_0
  *         @arg @ref LL_CRC_POLY_16_1
  */
__STATIC_INLINE uint32_t LL_CRC_GetPolynomial(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_BIT(CRCx->CFG, CRC_CFG_POLY));
}

/**
  * @brief  Configure the reversal of the bit order of the data
  * @rmtoll CFG           REFLECT        LL_CRC_SetDataReverseMode
  * @param  CRCx CRC Instance
  * @param  ReverseMode This parameter can be one of the following values:
  *         @arg @ref LL_CRC_DATA_REVERSE_NONE
  *         @arg @ref LL_CRC_DATA_REVERSE_ENABLE
  */
__STATIC_INLINE void LL_CRC_SetDataReverseMode(CRC_TypeDef *CRCx, uint32_t ReverseMode)
{
  MODIFY_REG(CRCx->CFG, CRC_CFG_REFLECT, ReverseMode);
}

/**
  * @brief  Return reversal for data bit order
  * @rmtoll CR           REV_IN        LL_CRC_GetDataReverseMode
  * @param  CRCx CRC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_CRC_DATA_REVERSE_NONE
  *         @arg @ref LL_CRC_DATA_REVERSE_ENABLE
  */
__STATIC_INLINE uint32_t LL_CRC_GetDataReverseMode(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_BIT(CRCx->CFG, CRC_CFG_REFLECT));
}

/**
  * @brief  Configure XOR of output data
  * @rmtoll CFG           XOR        LL_CRC_SetOutputXORMode
  * @param  CRCx CRC Instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_CRC_OUTPUT_XOR_NONE
  *         @arg @ref LL_CRC_OUTPUT_XOR_ENABLE
  */
__STATIC_INLINE void LL_CRC_SetOutputXORMode(CRC_TypeDef *CRCx, uint32_t Mode)
{
  MODIFY_REG(CRCx->CFG, CRC_CFG_XOR_EN, Mode);
}

/**
  * @brief  Return XOR for output
  * @rmtoll CR           XOR        LL_CRC_GetOutputXORMode
  * @param  CRCx CRC Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_CRC_OUTPUT_XOR_NONE
  *         @arg @ref LL_CRC_OUTPUT_XOR_ENABLE
  */
__STATIC_INLINE uint32_t LL_CRC_GetOutputXORMode(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_BIT(CRCx->CFG, CRC_CFG_XOR_EN));
}

/**
  * @brief  Initialize the Programmable initial CRC value.
  * @note   If the CRC size is less than 32 bits, the least significant bits
  *         are used to write the correct value
  * @note   LL_CRC_DEFAULT_CRC_INITVALUE could be used as value for InitCrc parameter.
  * @rmtoll RESULT         RESULT          LL_CRC_SetInitialData
  * @param  CRCx CRC Instance
  * @param  InitCrc Value to be programmed in Programmable initial CRC value register
  */
__STATIC_INLINE void LL_CRC_SetInitialData(CRC_TypeDef *CRCx, uint32_t InitCrc)
{
  WRITE_REG(CRCx->RESULT, InitCrc);
}

/**
  * @brief  Set CRC XOR value.
  * @rmtoll XOR         XOR          LL_CRC_SetXorMask
  * @param  CRCx CRC Instance
  * @param  Xor Value to be programmed in Programmable initial CRC value register
  */
__STATIC_INLINE void LL_CRC_SetXorMask(CRC_TypeDef *CRCx, uint32_t Xor)
{
  WRITE_REG(CRCx->XORVALUE, Xor);
}

/**
  * @}
  */

/** @defgroup CRC_LL_Exported_Functions_Group2 Data_Management
  * @{
  */

/**
  * @brief  Write given 32-bit data to the CRC calculator
  * @rmtoll DATA           DATA            LL_CRC_FeedData32
  * @param  CRCx CRC Instance
  * @param  InData value to be provided to CRC calculator between between Min_Data=0 and Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE void LL_CRC_FeedData32(CRC_TypeDef *CRCx, uint32_t InData)
{
  WRITE_REG(CRCx->DATA, InData);
}

/**
  * @brief  Write given 16-bit data to the CRC calculator
  * @rmtoll DATA           DATA            LL_CRC_FeedData16
  * @param  CRCx CRC Instance
  * @param  InData 16 bit value to be provided to CRC calculator between between Min_Data=0 and Max_Data=0xFFFF
  */
__STATIC_INLINE void LL_CRC_FeedData16(CRC_TypeDef *CRCx, uint16_t InData)
{
  __IO uint16_t *pReg;

  pReg = (__IO uint16_t *)(__IO void *)(&CRCx->DATA);                             /* Derogation MisraC2012 R.11.5 */
  *pReg = InData;
}

/**
  * @brief  Write given 8-bit data to the CRC calculator
  * @rmtoll DATA           DATA            LL_CRC_FeedData8
  * @param  CRCx CRC Instance
  * @param  InData 8 bit value to be provided to CRC calculator between between Min_Data=0 and Max_Data=0xFF
  */
__STATIC_INLINE void LL_CRC_FeedData8(CRC_TypeDef *CRCx, uint8_t InData)
{
  *(uint8_t __IO *)(&CRCx->DATA) = (uint8_t) InData;
}

/**
  * @brief  Return current CRC calculation result. 32 bits value is returned.
  * @rmtoll RESULT           RESULT            LL_CRC_ReadData32
  * @param  CRCx CRC Instance
  * @retval Current CRC calculation result as stored in CRC_DR register (32 bits).
  */
__STATIC_INLINE uint32_t LL_CRC_ReadData32(CRC_TypeDef *CRCx)
{
  return (uint32_t)(READ_REG(CRCx->RESULT));
}

/**
  * @brief  Return current CRC calculation result. 16 bits value is returned.
  * @note   This function is expected to be used in a 16 bits CRC polynomial size context.
  * @rmtoll RESULT           RESULT            LL_CRC_ReadData16
  * @param  CRCx CRC Instance
  * @retval Current CRC calculation result as stored in CRC_DR register (16 bits).
  */
__STATIC_INLINE uint16_t LL_CRC_ReadData16(CRC_TypeDef *CRCx)
{
  return (uint16_t)READ_REG(CRCx->RESULT);
}

/**
  * @brief  Return current CRC calculation result. 8 bits value is returned.
  * @note   This function is expected to be used in a 8 bits CRC polynomial size context.
  * @rmtoll RESULT           RESULT            LL_CRC_ReadData8
  * @param  CRCx CRC Instance
  * @retval Current CRC calculation result as stored in CRC_DR register (8 bits).
  */
__STATIC_INLINE uint8_t LL_CRC_ReadData8(CRC_TypeDef *CRCx)
{
  return (uint8_t)READ_REG(CRCx->RESULT);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup CRC_LL_Exported_Functions_Group3 Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_CRC_DeInit(CRC_TypeDef *CRCx);

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

#endif /* defined(CRC) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_CRC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
