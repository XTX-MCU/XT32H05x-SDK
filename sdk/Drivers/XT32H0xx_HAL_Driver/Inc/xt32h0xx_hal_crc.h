/**
  ******************************************************************************
  * @file    xt32h0xx_hal_crc.h
  * @author  Software Team
  * @brief   Header file of CRC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_CRC_H
#define XT32H0xx_HAL_CRC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup CRC 
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup CRC_Exported_Types CRC Exported Types
  * @{
  */

/**
  * @brief  CRC HAL State Structure definition
  */
typedef enum
{
  HAL_CRC_STATE_RESET     = 0x00U,  /*!< CRC not yet initialized or disabled */
  HAL_CRC_STATE_READY     = 0x01U,  /*!< CRC initialized and ready for use   */
  HAL_CRC_STATE_BUSY      = 0x02U,  /*!< CRC internal process is ongoing     */
  HAL_CRC_STATE_TIMEOUT   = 0x03U,  /*!< CRC timeout state                   */
  HAL_CRC_STATE_ERROR     = 0x04U   /*!< CRC error state                     */
} HAL_CRC_StateTypeDef;

/**
  * @brief CRC Init Structure definition
  */
typedef struct
{
  uint32_t CRCPoly;                 /*!< This parameter is a value of @ref CRC_Polynomial_Sizes and indicates CRC length.
                                           Value can be either one of
                                           @arg @ref CRC_POLY_32                   (32-bit CRC),
                                           @arg @ref CRC_POLY_8                    (16-bit CRC),
                                           @arg @ref CRC_POLY_16_0                 (8-bit CRC),
                                           @arg @ref CRC_POLY_16_1                 (8-bit CRC). */

  uint32_t InitValue;               /*!< Init value to initiate CRC computation. */

  uint32_t DataInversionMode;       /*!< This parameter is a value of @ref CRC_Data_Inversion and specifies input & output data inversion mode.
                                           Can be either one of the following values
                                           @arg @ref CRC_DATA_INVERSION_NONE       no input & outputdata inversion
                                           @arg @ref CRC_DATA_INVERSION_ENABLE                            */

  uint32_t OutputXorMode;           /*!< This parameter is a value of @ref CRC_Output_Data_Xor and specifies output data XOR mode.
                                           Can be either
                                           @arg @ref CRC_OUTPUTDATA_XOR_DISABLE   no XOR,
                                           @arg @ref CRC_OUTPUTDATA_XOR_ENABLE    XOR with XOR_MASK */

  uint32_t OutputXorMask;           /*!< This parameter is a value of XOR mask */
	
} CRC_InitTypeDef;

/**
  * @brief  CRC Handle Structure definition
  */
typedef struct
{
  CRC_TypeDef                 *Instance;   /*!< Register base address        */

  CRC_InitTypeDef             Init;        /*!< CRC configuration parameters */

  HAL_LockTypeDef             Lock;        /*!< CRC Locking object           */

  __IO HAL_CRC_StateTypeDef   State;       /*!< CRC communication state      */

  uint32_t InputDataFormat;                /*!< This parameter is a value of @ref CRC_Input_Buffer_Format and specifies input data format.
                                            Can be either
                                            @arg @ref CRC_INPUTDATA_FORMAT_BYTES       input data is a stream of bytes
                                            (8-bit data)
                                            @arg @ref CRC_INPUTDATA_FORMAT_HALFWORDS   input data is a stream of
                                            half-words (16-bit data)
                                            @arg @ref CRC_INPUTDATA_FORMAT_WORDS       input data is a stream of words
                                            (32-bit data)

                                          Note that constant CRC_INPUT_FORMAT_UNDEFINED is defined but an initialization
                                          error must occur if InputBufferFormat is not one of the three values listed
                                          above  */
} CRC_HandleTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup CRC_Exported_Constants CRC Exported Constants
  * @{
  */

/** @defgroup CRC_Polynomial_Sizes Polynomial sizes to configure the peripheral
  * @{
  */
#define CRC_POLY_32                    (0x00000000U)                           /*!< Resort to a 32-bit generating polynomial */
#define CRC_POLY_8                     (0x1UL << CRC_CFG_POLY_Pos)             /*!< Resort to a 8-bit generating polynomial */
#define CRC_POLY_16_0                  (0x2UL << CRC_CFG_POLY_Pos)             /*!< Resort to a 16-bit generating polynomial  */
#define CRC_POLY_16_1                  (0x3UL << CRC_CFG_POLY_Pos)             /*!< Resort to a 16-bit generating polynomial  */
/**
  * @}
  */

/** @defgroup CRC_Polynomial_Size_Definitions CRC polynomial possible sizes actual definitions
  * @{
  */
#define HAL_CRC_LENGTH_32B             (32U)                                   /*!< 32-bit long CRC */
#define HAL_CRC_LENGTH_16B             (16U)                                   /*!< 16-bit long CRC */
#define HAL_CRC_LENGTH_8B              ( 8U)                                   /*!< 8-bit long CRC  */
/**
  * @}
  */

/** @defgroup CRC_Input_Buffer_Format Input Buffer Format
  * @{
  */
#define CRC_INPUTDATA_FORMAT_UNDEFINED     (0x00000000U)                       /*!< Undefined input data format    */
#define CRC_INPUTDATA_FORMAT_BYTES         (0x00000001U)                       /*!< Input data in byte format      */
#define CRC_INPUTDATA_FORMAT_HALFWORDS     (0x00000002U)                       /*!< Input data in half-word format */
#define CRC_INPUTDATA_FORMAT_WORDS         (0x00000003U)                       /*!< Input data in word format      */
/**
  * @}
  */

/** @defgroup CRC_Data_Inversion Input Data Inversion Modes
  * @{
  */
#define CRC_DATA_INVERSION_NONE            (0x00000000U)                       /*!< no data inversion       */
#define CRC_DATA_INVERSION_ENABLE          (CRC_CFG_REFLECT)                   /*!< data inversion          */
/**
  * @}
  */

/** @defgroup CRC_Output_Data_Xor Output Data Xor
  * @{
  */
#define CRC_OUTPUTDATA_XOR_DISABLE         (0x00000000U)                       /*!< No output data xor       */
#define CRC_OUTPUTDATA_XOR_ENABLE          (CRC_CFG_XOR_EN)                       /*!< output data xor          */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup CRC_Exported_Macros CRC Exported Macros
  * @{
  */

/** @brief Reset CRC handle state.
  * @param  __HANDLE__ CRC handle.
  * @retval None
  */
#define __HAL_CRC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_CRC_STATE_RESET)

/**
  * @brief  Reset CRC Data Register.
  * @param  __HANDLE__ CRC handle
  * @retval None
  */
#define __HAL_CRC_RESET(__HANDLE__) READ_REG((__HANDLE__)->Instance->RESULT)

/**
  * @brief  Set CRC INIT non-default value
  * @param  __HANDLE__ CRC handle
  * @param  __INIT__ 32-bit initial value
  * @retval None
  */
#define __HAL_CRC_INITIALCRCVALUE_CONFIG(__HANDLE__, __INIT__) ((__HANDLE__)->Instance->RESULT = (__INIT__))

/**
  * @brief  Set CRC output xor
  * @param  __HANDLE__ CRC handle
  * @retval None
  */
#define  __HAL_CRC_OUTPURXOR_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CFG |= CRC_CFG_XOR)

/**
  * @brief  Unset CRC output xor
  * @param  __HANDLE__ CRC handle
  * @retval None
  */
#define __HAL_CRC_OUTPUTXOR_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CFG &= ~(CRC_CFG_XOR))

/**
  * @brief  Set CRC non-default polynomial
  * @param  __HANDLE__ CRC handle
  * @param  __POLYNOMIAL__ polynomial
  *         @arg @ref CRC_POLY_32
  *         @arg @ref CRC_POLY_8
  *         @arg @ref CRC_POLY_16_0
  *         @arg @ref CRC_POLY_16_1
  * @retval None
  */
#define __HAL_CRC_POLYNOMIAL_CONFIG(__HANDLE__, __POLYNOMIAL__) { ((__HANDLE__)->Instance->CFG &= ~(CRC_CFG_POLY)); \
                                                                  ((__HANDLE__)->Instance->CFG |= (__POLYNOMIAL__)); }

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup CRC_Exported_Functions CRC Exported Functions
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
/** @defgroup CRC_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
HAL_StatusTypeDef HAL_CRC_Init(CRC_HandleTypeDef *hcrc);
HAL_StatusTypeDef HAL_CRC_DeInit(CRC_HandleTypeDef *hcrc);
void HAL_CRC_MspInit(CRC_HandleTypeDef *hcrc);
void HAL_CRC_MspDeInit(CRC_HandleTypeDef *hcrc);
/**
  * @}
  */

/* Peripheral Control functions ***********************************************/
/** @defgroup CRC_Exported_Functions_Group2 Peripheral Control functions
  * @{
  */
uint32_t HAL_CRC_Accumulate(CRC_HandleTypeDef *hcrc, uint32_t pBuffer[], uint32_t BufferLength);
uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef *hcrc, uint32_t pBuffer[], uint32_t BufferLength);
/**
  * @}
  */

/* Peripheral State and Error functions ***************************************/
/** @defgroup CRC_Exported_Functions_Group3 Peripheral State functions
  * @{
  */
HAL_CRC_StateTypeDef HAL_CRC_GetState(CRC_HandleTypeDef *hcrc);
/**
  * @}
  */

/** @addtogroup CRC_Exported_Functions_Group4
  * @{
  */
/* Configuration functions  ****************************/
HAL_StatusTypeDef HAL_CRC_Polynomial_Set(CRC_HandleTypeDef *hcrc, uint32_t Pol);
HAL_StatusTypeDef HAL_CRC_Data_Reverse(CRC_HandleTypeDef *hcrc, uint32_t InputReverseMode);
HAL_StatusTypeDef HAL_CRC_Output_Data_Xor(CRC_HandleTypeDef *hcrc, uint32_t Xor, uint32_t Mask);

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

#endif /* XT32H0xx_HAL_CRC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
