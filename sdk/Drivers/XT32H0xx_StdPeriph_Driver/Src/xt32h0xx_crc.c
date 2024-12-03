/**
  ******************************************************************************
  * @file    xt32h0xx_crc.c
  * @author  Software Team
  * @date    23 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of CRC computation unit peripheral:
  *            + Configuration of the CRC computation unit
  *            + CRC computation of one/many 32-bit data
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_crc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup CRC CRC
  * @brief CRC driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup CRC_Exported_Functions CRC Exported Functions
  * @{
  */

/** @defgroup CRC_Exported_Functions_Group1 Configuration of the CRC computation unit functions
 *  @brief   Configuration of the CRC computation unit functions 
 *
@verbatim
 ===============================================================================
                     ##### CRC configuration functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Deinitializes CRC peripheral registers to their default reset values.
  */
void CRC_DeInit(void)
{
  /* Reset the CRC calculation unit */
  uint32_t temp = CRC->RESULT;
}

/**
  * @brief  Selects the reverse operation to be performed on input/output data.
  * @param  CRC_ReverseData: Specifies the reverse operation on input data.
  *          This parameter can be:
  *            @arg @ref CRC_DATA_REVERSE_NONE
  *            @arg @ref CRC_DATA_REVERSE_ENABLE
  */
void CRC_ReverseDataSelect(uint32_t CRC_ReverseData)
{
  uint32_t tmpcr = 0;

  /* Check the parameter */
  assert_param(IS_CRC_REVERSE_DATA(CRC_ReverseData));

  /* Get CR register value */
  tmpcr = CRC->CFG;

  /* Reset REV_IN bits */
  tmpcr &= (uint32_t)~((uint32_t)CRC_CFG_REFLECT);
  /* Set the reverse operation */
  tmpcr |= (uint32_t)CRC_ReverseData;

  /* Write to CR register */
  CRC->CFG = (uint32_t)tmpcr;
}

/**
  * @brief  Enables or disable XOR mask for output date.
  * @param  CRC_XORMask:
  *         0: output no XOR
  */
void CRC_SetOutputXORMask(uint32_t CRC_XORMask)
{
  /* Check the parameters */
  if (CRC_XORMask != 0)
  {
    /* Enable reverse operation on output data */
    CRC->CFG |=  (uint32_t)CRC_CFG_XOR_EN;
    CRC->XORVALUE = CRC_XORMask;
  }
  else
  {
    /* Disable reverse operation on output data */
    CRC->CFG &= (uint32_t)~((uint32_t)CRC_CFG_XOR_EN);
    CRC->XORVALUE = 0;
  }
}

/**
  * @brief  Initializes the INIT register.
  * @note   After resetting CRC calculation unit, CRC_InitValue is stored in DR register
  * @param  CRC_InitValue: Programmable initial CRC value
  */
void CRC_SetInitValue(uint32_t CRC_InitValue)
{
  CRC->RESULT = CRC_InitValue;
}

/**
  * @brief  Initializes the polynomail coefficients. This function is only 
  *         applicable for xt32h0xx devices.
  * @param  CRC_Pol: Polynomial to be used for CRC calculation.
  *         The parameter can be one of the following values:
  *         @arg @ref CRC_POLY_32
  *         @arg @ref CRC_POLY_8
  *         @arg @ref CRC_POLY_16_0
  *         @arg @ref CRC_POLY_16_1
  */
void CRC_SetPolynomial(uint32_t CRC_Pol)
{
  uint32_t tempr = CRC->CFG;

  tempr &= (uint32_t)~((uint32_t)CRC_CFG_POLY);
  tempr |= (uint32_t)CRC_Pol;
  
  CRC->CFG = (uint32_t)tempr;
}

/**
  * @}
  */

/** @defgroup CRC_Exported_Functions_Group2 CRC computation of one/many 32-bit data functions
 *  @brief   CRC computation of one/many 32-bit data functions
 *
@verbatim
 ===============================================================================
                     ##### CRC computation functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  Computes the 32-bit CRC of a given data word(32-bit).
  * @param  CRC_Data: data word(32-bit) to compute its CRC
  * @retval 32-bit CRC
  */
uint32_t CRC_CalcCRC(uint32_t CRC_Data)
{
  CRC->DATA = CRC_Data;
  
  return (CRC->RESULT);
}

/**
  * @brief  Computes the 32-bit CRC of a given buffer of data word(32-bit).
  * @param  pBuffer: pointer to the buffer containing the data to be computed
  * @param  BufferLength: length of the buffer to be computed
  * @retval 32-bit CRC
  */
uint32_t CRC_CalcBlockCRC32(uint32_t pBuffer[], uint32_t BufferLength)
{
  uint32_t index = 0;
  
  for(index = 0; index < BufferLength; index++)
  {
    CRC->DATA = pBuffer[index];
  }
  return (CRC->RESULT);
}

/**
  * @brief  Computes the 16-bit CRC of a given buffer of data (16-bit).
  * @param  pBuffer: pointer to the buffer containing the data to be computed
  * @param  BufferLength: length of the buffer to be computed
  * @retval 16-bit CRC
  */
uint16_t CRC_CalcBlockCRC16(uint16_t pBuffer[], uint32_t BufferLength)
{
  uint32_t index = 0;
  
  for(index = 0; index < BufferLength; index++)
  {
    CRC->DATA = pBuffer[index];
  }
  return (uint16_t)(CRC->RESULT);
}

/**
  * @brief  Computes the 8-bit CRC of a given buffer of data(8-bit).
  * @param  pBuffer: pointer to the buffer containing the data to be computed
  * @param  BufferLength: length of the buffer to be computed
  * @retval 8-bit CRC
  */
uint8_t CRC_CalcBlockCRC8(uint8_t pBuffer[], uint32_t BufferLength)
{
  uint32_t index = 0;
  
  for(index = 0; index < BufferLength; index++)
  {
    CRC->DATA = pBuffer[index];
  }
  return (uint8_t)(CRC->RESULT);
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

