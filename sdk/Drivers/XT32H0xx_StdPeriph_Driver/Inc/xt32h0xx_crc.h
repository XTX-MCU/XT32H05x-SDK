/**
  ******************************************************************************
  * @file    xt32h0xx_crc.h
  * @author  Software Team
  * @date    23 June 2022
  * @brief   This file contains all the functions prototypes for the CRC firmware 
  *          library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_CRC_H
#define __XT32H0XX_CRC_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup CRC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup CRC_Exported_Contants CRC Exported Constants
  * @{
  */

/** @defgroup CRC_Polynomial CRC Polynamial
  * @brief   
  * @{
  */
#define CRC_POLY_32                    (0x00000000U)                           /*!< 32 bits Polynomial 0x41C11DB7 */
#define CRC_POLY_8                     (CRC_CFG_POLY_0)                        /*!< 8 bits Polynomial 0x07 */
#define CRC_POLY_16_0                  (CRC_CFG_POLY_1)                        /*!< 16 bits Polynomial 0x1021 */
#define CRC_POLY_16_1                  (CRC_CFG_POLY_1 | CRC_CFG_POLY_0)       /*!< 16 bits Polynomial 0x8005 */

#define IS_CRC_POL(POL)       (((POL) == CRC_POLY_32)   || \
                               ((POL) == CRC_POLY_8)    || \
                               ((POL) == CRC_POLY_16_0) || \
                               ((POL) == CRC_POLY_16_1))

/**
  * @}
  */

/** @defgroup CRC_DATA_REVERSE CRC Data Reverse
  * @{
  */
#define CRC_DATA_REVERSE_NONE          (0x00000000U)                           /*!< Input and output Data bit order not affected */
#define CRC_DATA_REVERSE_ENABLE        (CRC_CFG_REFLECT)                       /*!< Input and output Data bit reversal done by byte */

#define IS_CRC_REVERSE_DATA(REVERSE)   (((REVERSE) == CRC_DATA_REVERSE_NONE)  || \
                                        ((REVERSE) == CRC_DATA_REVERSE_ENABLE))
/**
  * @}
  */

/** @defgroup CRC_OUT_XOR CRC Output Data XOR
  * @{
  */
#define CRC_OUTPUT_XOR_NONE            (0x00000000U)                           /*!< Input and output Data bit order not affected */
#define CRC_OUTPUT_XOR_ENABLE          (CRC_CFG_XOR_EN)                        /*!< Input and output Data bit reversal done by byte */

#define IS_CRC_OUTPUT_XOR(XOR)         (((XOR) == CRC_OUTPUT_XOR_NONE)  || \
                                        ((XOR) == CRC_OUTPUT_XOR_ENABLE))
/**
  * @}
  */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup CRC_Exported_Functions
  * @{
  */
/** @addtogroup CRC_Exported_Functions_Group1 
  * @brief   Configuration of the CRC computation unit functions 
  *
  * @{
  */
/* Configuration of the CRC computation unit **********************************/
void CRC_DeInit(void);
void CRC_ReverseDataSelect(uint32_t CRC_ReverseData);
void CRC_SetOutputXORMask(uint32_t CRC_XORMask); 
void CRC_SetInitValue(uint32_t CRC_InitValue); 
void CRC_SetPolynomial(uint32_t CRC_Pol); 

/**
  * @}
  */

/** @addtogroup CRC_Exported_Functions_Group2
  * @brief   CRC computation of one/many 32-bit data functions
  *
  * @{
  */
/* CRC computation ************************************************************/
uint32_t CRC_CalcCRC(uint32_t CRC_Data);
uint32_t CRC_CalcBlockCRC32(uint32_t pBuffer[], uint32_t BufferLength);
uint16_t CRC_CalcBlockCRC16(uint16_t pBuffer[], uint32_t BufferLength);
uint8_t CRC_CalcBlockCRC8(uint8_t pBuffer[], uint32_t BufferLength);
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

#ifdef __cplusplus
}
#endif

#endif /* __XT32H0XX_CRC_H */


