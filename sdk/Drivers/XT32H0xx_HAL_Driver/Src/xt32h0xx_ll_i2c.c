/**
  ******************************************************************************
  * @file    xt32h0xx_ll_i2c.c
  * @author  Software Team
  * @brief   I2C LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by XTX under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_i2c.h"
#include "xt32h0xx_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (I2C1) || defined (I2C2) 

/** @defgroup I2C_LL I2C
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup I2C_LL_Private_Macros
  * @{
  */

#define IS_LL_I2C_MODE(__VALUE__)    (((__VALUE__) == LL_I2C_MODE_SLAVE)          || \
                                      ((__VALUE__) == LL_I2C_MODE_MASTER))

#define IS_LL_I2C_DIGITAL_FILTER(__VALUE__)     ((__VALUE__) <= 0x000000FFU)

#define IS_LL_I2C_SLAVE_ADDRESS(__VALUE__)       ((__VALUE__) <= 0x000003FFU)

#define IS_LL_I2C_ADDRSIZE(__VALUE__)       (((__VALUE__) == LL_I2C_7BIT_ADDRESSING) || \
                                             ((__VALUE__) == LL_I2C_10BIT_ADDRESSING))
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup I2C_LL_Exported_Functions
  * @{
  */

/** @addtogroup I2C_LL_Exported_Functions_Group5
  * @{
  */

/**
  * @brief  De-initialize the I2C registers to their default reset values.
  * @param  I2Cx I2C Instance.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: I2C registers are de-initialized
  *          - ERROR: I2C registers are not de-initialized
  */
ErrorStatus LL_I2C_DeInit(I2C_TypeDef *I2Cx)
{
  ErrorStatus status = SUCCESS;

  /* Check the I2C Instance I2Cx */
  assert_param(IS_I2C_ALL_INSTANCE(I2Cx));

  if ((I2Cx == I2C1) || (I2Cx == I2C2))
  {
    LL_I2C_Disable(I2Cx);
  }
  else
  {
    status = ERROR;
  }

  return status;
}

/**
  * @brief  Initialize the I2C registers according to the specified parameters in I2C_InitStruct.
  * @param  I2Cx I2C Instance.
  * @param  I2C_InitStruct pointer to a @ref LL_I2C_InitTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: I2C registers are initialized
  *          - ERROR: Not applicable
  */
ErrorStatus LL_I2C_Init(I2C_TypeDef *I2Cx, LL_I2C_InitTypeDef *I2C_InitStruct)
{
  /* Check the I2C Instance I2Cx */
  assert_param(IS_I2C_ALL_INSTANCE(I2Cx));

  /* Check the I2C parameters from I2C_InitStruct */
  assert_param(IS_LL_I2C_MODE(I2C_InitStruct->Mode));
  assert_param(IS_LL_I2C_DIGITAL_FILTER(I2C_InitStruct->DigitalFilter));
  assert_param(IS_LL_I2C_SLAVE_ADDRESS1(I2C_InitStruct->SlaveAddress));
  assert_param(IS_LL_I2C_ADDRSIZE(I2C_InitStruct->AddrSize));

  /* Disable the selected I2Cx Peripheral */
  LL_I2C_Disable(I2Cx);

  /*---------------------------- I2Cx Filter Configuration ------------------------
   * Configure digital noise filters with parameters :
   * - DigitalFilter: HSSPKLEN bits
   */
  if(I2C_InitStruct->Speed == LL_I2C_SPEED_HIGH_MODE)
  {
    LL_I2C_SetHSSpikeLength(I2Cx, I2C_InitStruct->DigitalFilter);
  }
  else
  {
    LL_I2C_SetFSSpikeLength(I2Cx, I2C_InitStruct->DigitalFilter);
  }

  /*---------------------------- I2Cx TIMINGR Configuration --------------------
   * Configure the SDA setup, hold time and the SCL high, low period with parameter :
   * - Timing: I2C_TIMINGR_PRESC[3:0], I2C_TIMINGR_SCLDEL[3:0], I2C_TIMINGR_SDADEL[3:0],
   *           I2C_TIMINGR_SCLH[7:0] and I2C_TIMINGR_SCLL[7:0] bits
   */
  LL_I2C_SetSpeed(I2Cx, I2C_InitStruct->Speed);

  /*---------------------------- I2Cx OAR1 Configuration -----------------------
   * Disable, Configure and Enable I2Cx device own address 1 with parameters :
   * - OwnAddress1:  I2C_OAR1_OA1[9:0] bits
   * - OwnAddrSize:  I2C_OAR1_OA1MODE bit
   */
  LL_I2C_SetSlvAddressing(I2Cx, I2C_InitStruct->SlaveAddrSize);
  LL_I2C_SetSlaveAddress(I2Cx, I2C_InitStruct->SlaveAddress);

  /* OwnAdress1 == 0 is reserved for General Call address */
//  if (I2C_InitStruct->OwnAddress1 != 0U)
//  {
//    LL_I2C_EnableOwnAddress1(I2Cx);
//  }
  LL_I2C_SetMstAddressing(I2Cx, I2C_InitStruct->MasterAddrSize);

  /*---------------------------- I2Cx MODE Configuration -----------------------
  * Configure I2Cx peripheral mode with parameter :
   * - PeripheralMode: I2C_CR1_SMBDEN and I2C_CR1_SMBHEN bits
   */
  LL_I2C_SetMode(I2Cx, I2C_InitStruct->Mode);

  /* Enable the selected I2Cx Peripheral */
  LL_I2C_Enable(I2Cx);

  return SUCCESS;
}

/**
  * @brief  Set each @ref LL_I2C_InitTypeDef field to default value.
  * @param  I2C_InitStruct Pointer to a @ref LL_I2C_InitTypeDef structure.
  */
void LL_I2C_StructInit(LL_I2C_InitTypeDef *I2C_InitStruct)
{
  /* Set I2C_InitStruct fields to default values */
  I2C_InitStruct->Mode            = LL_I2C_MODE_MASTER;
  I2C_InitStruct->Speed           = LL_I2C_SPEED_STANDARD_MODE;
  //I2C_InitStruct->AnalogFilter    = LL_I2C_ANALOGFILTER_ENABLE;
  I2C_InitStruct->DigitalFilter   = 11U;
  I2C_InitStruct->SlaveAddress    = 0x10U;
  I2C_InitStruct->SlaveAddrSize   = LL_I2C_SLV_ADDRESSING_7BIT;
  I2C_InitStruct->MasterAddrSize  = LL_I2C_MST_ADDRESSING_7BIT;
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

#endif /* I2C1 || I2C2 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
