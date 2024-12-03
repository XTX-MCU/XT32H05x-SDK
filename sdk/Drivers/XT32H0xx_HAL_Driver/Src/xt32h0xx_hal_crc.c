/**
  ******************************************************************************
  * @file    xt32h0xx_hal_crc.c
  * @author  Software Team
  * @brief   CRC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Cyclic Redundancy Check (CRC) peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
	*           + Configuration functions
  *
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

/** @defgroup CRC CRC
  * @brief CRC HAL module driver.
  * @{
  */

#ifdef HAL_CRC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup  CRC_Private_Macros CRC Private Macros
  * @{
  */

#define IS_CRC_POL(LENGTH)            (((LENGTH) == CRC_POLY_32)    || \
                                       ((LENGTH) == CRC_POLY_8)     || \
                                       ((LENGTH) == CRC_POLY_16_0)  || \
                                       ((LENGTH) == CRC_POLY_16_1))

#define IS_CRC_INPUTDATA_FORMAT(FORMAT)           (((FORMAT) == CRC_INPUTDATA_FORMAT_BYTES)     || \
                                                   ((FORMAT) == CRC_INPUTDATA_FORMAT_HALFWORDS) || \
                                                   ((FORMAT) == CRC_INPUTDATA_FORMAT_WORDS))

#define IS_CRC_DATA_INVERSION_MODE(MODE)          (((MODE) == CRC_DATA_INVERSION_NONE)     || \
                                                   ((MODE) == CRC_DATA_INVERSION_ENABLE))

#define IS_CRC_OUTPUTDATA_XOR_MODE(MODE)          (((MODE) == CRC_OUTPUTDATA_XOR_DISABLE) || \
                                                   ((MODE) == CRC_OUTPUTDATA_XOR_ENABLE))

/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @defgroup  CRC_Private_Variables CRC Private Variables
  * @{
  */
static uint32_t crc_accumulate = 0; 
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup CRC_Private_Functions CRC Private Functions
  * @{
  */
static uint32_t CRC_Handle_8(CRC_HandleTypeDef *hcrc, uint8_t pBuffer[], uint32_t BufferLength);
static uint32_t CRC_Handle_16(CRC_HandleTypeDef *hcrc, uint16_t pBuffer[], uint32_t BufferLength);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup CRC_Exported_Functions CRC Exported Functions
  * @{
  */

/** @defgroup CRC_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions.
  *
@verbatim
 ===============================================================================
            ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Initialize the CRC according to the specified parameters
          in the CRC_InitTypeDef and create the associated handle
      (+) DeInitialize the CRC peripheral
      (+) Initialize the CRC MSP (MCU Specific Package)
      (+) DeInitialize the CRC MSP

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the CRC according to the specified
  *         parameters in the CRC_InitTypeDef and create the associated handle.
  * @param  hcrc CRC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_CRC_Init(CRC_HandleTypeDef *hcrc)
{
  /* Check the CRC handle allocation */
  if (hcrc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_CRC_ALL_INSTANCE(hcrc->Instance));

  if (hcrc->State == HAL_CRC_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hcrc->Lock = HAL_UNLOCKED;
    /* Init the low level hardware */
    HAL_CRC_MspInit(hcrc);
  }

  hcrc->State = HAL_CRC_STATE_BUSY;

  /* check whether or not non-default generating polynomial has been
   * picked up by user */
  /* initialize CRC peripheral with generating polynomial defined by user */
   if (HAL_CRC_Polynomial_Set(hcrc, hcrc->Init.CRCPoly) != HAL_OK)
   {
     return HAL_ERROR;
   }

  /* check whether or not non-default CRC initial value has been
   * picked up by user */
  WRITE_REG(hcrc->Instance->RESULT, hcrc->Init.InitValue);
  crc_accumulate = hcrc->Init.InitValue;


  /* set input data inversion mode */
  assert_param(IS_CRC_DATA_INVERSION_MODE(hcrc->Init.DataInversionMode));
  MODIFY_REG(hcrc->Instance->CFG, CRC_CFG_REFLECT, hcrc->Init.DataInversionMode);

  /* set output data inversion mode */
  assert_param(IS_CRC_OUTPUTDATA_XOR_MODE(hcrc->Init.OutputXorMode));
  MODIFY_REG(hcrc->Instance->CFG, CRC_CFG_XOR_EN, hcrc->Init.OutputXorMode);
  WRITE_REG(hcrc->Instance->XORVALUE, hcrc->Init.OutputXorMask);

  /* makes sure the input data format (bytes, halfwords or words stream)
   * is properly specified by user */
  assert_param(IS_CRC_INPUTDATA_FORMAT(hcrc->InputDataFormat));

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  DeInitialize the CRC peripheral.
  * @param  hcrc CRC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_CRC_DeInit(CRC_HandleTypeDef *hcrc)
{
  /* Check the CRC handle allocation */
  if (hcrc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_CRC_ALL_INSTANCE(hcrc->Instance));

  /* Check the CRC peripheral state */
  if (hcrc->State == HAL_CRC_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_BUSY;

  /* Reset CRC calculation unit */
  __HAL_CRC_RESET(hcrc);
  
  /* DeInit the low level hardware */
  HAL_CRC_MspDeInit(hcrc);

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_RESET;

  /* Process unlocked */
  __HAL_UNLOCK(hcrc);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Initializes the CRC MSP.
  * @param  hcrc CRC handle
  */
__weak void HAL_CRC_MspInit(CRC_HandleTypeDef *hcrc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hcrc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_CRC_MspInit can be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the CRC MSP.
  * @param  hcrc CRC handle
  */
__weak void HAL_CRC_MspDeInit(CRC_HandleTypeDef *hcrc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hcrc);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_CRC_MspDeInit can be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup CRC_Exported_Functions_Group2 Peripheral Control functions
  *  @brief    management functions.
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) compute the 7, 8, 16 or 32-bit CRC value of an 8, 16 or 32-bit data buffer
          using combination of the previous CRC value and the new one.

       [..]  or

      (+) compute the 7, 8, 16 or 32-bit CRC value of an 8, 16 or 32-bit data buffer
          independently of the previous CRC value.

@endverbatim
  * @{
  */

/**
  * @brief  Compute the 8, 16 or 32-bit CRC value of an 8, 16 or 32-bit data buffer
  *         starting with the previously computed CRC as initialization value.
  * @param  hcrc CRC handle
  * @param  pBuffer pointer to the input data buffer, exact input data format is
  *         provided by hcrc->InputDataFormat.
  * @param  BufferLength input data buffer length (number of bytes if pBuffer
  *         type is * uint8_t, number of half-words if pBuffer type is * uint16_t,
  *         number of words if pBuffer type is * uint32_t).
  * @note  By default, the API expects a uint32_t pointer as input buffer parameter.
  *        Input buffer pointers with other types simply need to be cast in uint32_t
  *        and the API will internally adjust its input data processing based on the
  *        handle field hcrc->InputDataFormat.
  * @retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
  */
uint32_t HAL_CRC_Accumulate(CRC_HandleTypeDef *hcrc, uint32_t pBuffer[], uint32_t BufferLength)
{
  uint32_t index;      /* CRC input data buffer index */
  uint32_t temp = 0U;  /* CRC output (read from hcrc->Instance->DR register) */

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_BUSY;

  hcrc->Instance->RESULT = crc_accumulate;

  switch (hcrc->InputDataFormat)
  {
    case CRC_INPUTDATA_FORMAT_WORDS:
      /* Enter Data to the CRC calculator */
      for (index = 0U; index < BufferLength; index++)
      {
        hcrc->Instance->DATA = pBuffer[index];
      }
      temp = hcrc->Instance->RESULT;
      break;

    case CRC_INPUTDATA_FORMAT_BYTES:
      temp = CRC_Handle_8(hcrc, (uint8_t *)pBuffer, BufferLength);
      break;

    case CRC_INPUTDATA_FORMAT_HALFWORDS:
      temp = CRC_Handle_16(hcrc, (uint16_t *)(void *)pBuffer, BufferLength);    /* Derogation MisraC2012 R.11.5 */
      break;
    default:
      break;
  }

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_READY;

  /* Return the CRC computed value */
  crc_accumulate = temp;
  return temp;
}

/**
  * @brief  Compute the 8, 16 or 32-bit CRC value of an 8, 16 or 32-bit data buffer
  *         starting with hcrc->Instance->INIT as initialization value.
  * @param  hcrc CRC handle
  * @param  pBuffer pointer to the input data buffer, exact input data format is
  *         provided by hcrc->InputDataFormat.
  * @param  BufferLength input data buffer length (number of bytes if pBuffer
  *         type is * uint8_t, number of half-words if pBuffer type is * uint16_t,
  *         number of words if pBuffer type is * uint32_t).
  * @note  By default, the API expects a uint32_t pointer as input buffer parameter.
  *        Input buffer pointers with other types simply need to be cast in uint32_t
  *        and the API will internally adjust its input data processing based on the
  *        handle field hcrc->InputDataFormat.
  * @retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
  */
uint32_t HAL_CRC_Calculate(CRC_HandleTypeDef *hcrc, uint32_t pBuffer[], uint32_t BufferLength)
{
  uint32_t index;      /* CRC input data buffer index */
  uint32_t temp = 0U;  /* CRC output (read from hcrc->Instance->DR register) */

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_BUSY;

  /* Reset CRC Calculation Unit (hcrc->Init.InitValue is
   *  written in hcrc->Instance->RESULT) */
  __HAL_CRC_INITIALCRCVALUE_CONFIG(hcrc, hcrc->Init.InitValue);

  switch (hcrc->InputDataFormat)
  {
    case CRC_INPUTDATA_FORMAT_WORDS:
      /* Enter 32-bit input data to the CRC calculator */
      for (index = 0U; index < BufferLength; index++)
      {
        hcrc->Instance->DATA = pBuffer[index];
      }
      temp = hcrc->Instance->RESULT;
      break;

    case CRC_INPUTDATA_FORMAT_BYTES:
      /* Specific 8-bit input data handling  */
      temp = CRC_Handle_8(hcrc, (uint8_t *)pBuffer, BufferLength);
      break;

    case CRC_INPUTDATA_FORMAT_HALFWORDS:
      /* Specific 16-bit input data handling  */
      temp = CRC_Handle_16(hcrc, (uint16_t *)(void *)pBuffer, BufferLength);    /* Derogation MisraC2012 R.11.5 */
      break;

    default:
      break;
  }

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_READY;

  /* Return the CRC computed value */
  return temp;
}

/**
  * @}
  */

/** @defgroup CRC_Exported_Functions_Group3 Peripheral State functions
  *  @brief    Peripheral State functions.
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State functions #####
 ===============================================================================
    [..]
    This subsection permits to get in run-time the status of the peripheral.

@endverbatim
  * @{
  */

/**
  * @brief  Return the CRC handle state.
  * @param  hcrc CRC handle
  * @retval HAL state
  */
HAL_CRC_StateTypeDef HAL_CRC_GetState(CRC_HandleTypeDef *hcrc)
{
  /* Return CRC handle state */
  return hcrc->State;
}

/**
  * @}
  */

/** @defgroup CRC_Exported_Functions_Group4 Configuration functions
  *  @brief    Configuration functions.
  *
@verbatim
 ===============================================================================
                      ##### Configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */


/**
  * @brief  Initialize the CRC polynomial if different from default one.
  * @param  hcrc CRC handle
  * @param  Pol CRC generating polynomial.
  *         This parameter can be one of the following values:
  *          @arg @ref CRC_POLY_32   CRC polynomial 0x41C11DB7
  *          @arg @ref CRC_POLY_8    CRC polynomial 0x07
  *          @arg @ref CRC_POLY_16_0 CRC polynomial 0x1021
  *          @arg @ref CRC_POLY_16_1 CRC polynomial 0x8005
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_CRC_Polynomial_Set(CRC_HandleTypeDef *hcrc, uint32_t Pol)
{
  HAL_StatusTypeDef status = HAL_OK;
 
  /* Check the parameters */
  assert_param(IS_CRC_POL(Pol));

  MODIFY_REG(hcrc->Instance->CFG, CRC_CFG_POLY, Pol);

  return status;
}

/**
  * @brief  Set the Reverse Input data mode.
  * @param  hcrc CRC handle
  * @param  ReverseMode Input Data inversion mode.
  *         This parameter can be one of the following values:
  *          @arg @ref CRC_DATA_INVERSION_NONE          no change in bit order (default value)
  *          @arg @ref CRC_DATA_INVERSION_ENABLE        bit reversal
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_CRC_Data_Reverse(CRC_HandleTypeDef *hcrc, uint32_t ReverseMode)
{
  /* Check the parameters */
  assert_param(IS_CRC_DATA_INVERSION_MODE(ReverseMode));

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_BUSY;

  /* set input data inversion mode */
  MODIFY_REG(hcrc->Instance->CFG, CRC_CFG_REFLECT, ReverseMode);
  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_READY;

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  Set the Reverse Output data mode.
  * @param  hcrc CRC handle
  * @param  Xor Output Data inversion mode.
  *         This parameter can be one of the following values:
  *          @arg @ref CRC_OUTPUTDATA_XOR_DISABLE no CRC inversion (default value)
  *          @arg @ref CRC_OUTPUTDATA_XOR_ENABLE  CRC output XOR
  * @param  Mask Output Xor mask
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_CRC_Output_Data_Xor(CRC_HandleTypeDef *hcrc, uint32_t Xor, uint32_t Mask)
{
  /* Check the parameters */
  assert_param(IS_CRC_OUTPUTDATA_XOR_MODE(Xor));

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_BUSY;

  /* set output data inversion mode */
  MODIFY_REG(hcrc->Instance->CFG, CRC_CFG_XOR_EN, Xor);
  WRITE_REG(hcrc->Instance->XORVALUE, Mask);

  /* Change CRC peripheral state */
  hcrc->State = HAL_CRC_STATE_READY;

  /* Return function status */
  return HAL_OK;
}




/**
  * @}
  */


/**
  * @}
  */

/** @addtogroup CRC_Private_Functions
  * @{
  */

/**
  * @brief  Enter 8-bit input data to the CRC calculator.
  *         Specific data handling to optimize processing time.
  * @param  hcrc CRC handle
  * @param  pBuffer pointer to the input data buffer
  * @param  BufferLength input data buffer length
  * @retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
  */
static uint32_t CRC_Handle_8(CRC_HandleTypeDef *hcrc, uint8_t pBuffer[], uint32_t BufferLength)
{
  uint32_t i; /* input data buffer index */

  /* Processing time optimization: 4 bytes are entered in a row with a single word write,
   * last bytes must be carefully fed to the CRC calculator to ensure a correct type
   * handling by the peripheral */
  for (i = 0U; i < (BufferLength ); i++)
  {
    *(__IO uint8_t *)(__IO void *)(&hcrc->Instance->DATA) = pBuffer[i];
  }

  /* Return the CRC computed value */
  return hcrc->Instance->RESULT;
}

/**
  * @brief  Enter 16-bit input data to the CRC calculator.
  *         Specific data handling to optimize processing time.
  * @param  hcrc CRC handle
  * @param  pBuffer pointer to the input data buffer
  * @param  BufferLength input data buffer length
  * @retval uint32_t CRC (returned value LSBs for CRC shorter than 32 bits)
  */
static uint32_t CRC_Handle_16(CRC_HandleTypeDef *hcrc, uint16_t pBuffer[], uint32_t BufferLength)
{
  uint32_t i;  /* input data buffer index */

  /* Processing time optimization: 2 HalfWords are entered in a row with a single word write,
   * in case of odd length, last HalfWord must be carefully fed to the CRC calculator to ensure
   * a correct type handling by the peripheral */
  for (i = 0U; i < (BufferLength); i++)
  {
    *(__IO uint16_t *)(__IO void *)(&hcrc->Instance->DATA) = pBuffer[i];
  }
  /* Return the CRC computed value */
  return hcrc->Instance->RESULT;
}

/**
  * @}
  */

#endif /* HAL_CRC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
