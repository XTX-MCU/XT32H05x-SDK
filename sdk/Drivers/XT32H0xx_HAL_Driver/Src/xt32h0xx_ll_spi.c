/**
  ******************************************************************************
  * @file    xt32h0xx_ll_spi.c
  * @author  Software Team
  * @brief   SPI LL module driver.
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
#include "xt32h0xx_ll_spi.h"
#include "xt32h0xx_ll_bus.h"
#include "xt32h0xx_ll_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (SPI1M) || defined (SPI1S) || defined (SPI2M) || defined (SPI2S)

/** @addtogroup SPI_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup SPI_LL_Private_Constants SPI Private Constants
  * @{
  */
/* SPI registers Masks */
#define SPI_IMR_CLEAR_MASK                 (SPI_IMR_TXEIM | SPI_IMR_TXOIM | SPI_IMR_RXUIM   | \
                                            SPI_IMR_RXOIM | SPI_IMR_RXFIM | SPI_IMR_MSTIM   )
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup SPI_LL_Private_Macros SPI Private Macros
  * @{
  */
#define IS_LL_SPI_TRANSFER_DIRECTION(__VALUE__) (((__VALUE__) == LL_SPI_TMOD_TXRX)       \
                                                 || ((__VALUE__) == LL_SPI_TMOD_TX)     \
                                                 || ((__VALUE__) == LL_SPI_TMOD_RX) \
                                                 || ((__VALUE__) == LL_SPI_TMOD_EEPROM))

#define IS_LL_SPI_DATAWIDTH(__VALUE__) (((__VALUE__) == LL_SPI_DATAWIDTH_4BIT)     \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_5BIT)  \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_6BIT)  \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_7BIT)  \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_8BIT)  \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_9BIT)  \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_10BIT) \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_11BIT) \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_12BIT) \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_13BIT) \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_14BIT) \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_15BIT) \
                                        || ((__VALUE__) == LL_SPI_DATAWIDTH_16BIT))

#define IS_LL_SPI_CTRLWIDTH(__VALUE__) (((__VALUE__) == LL_SPI_CTRLWIDTH_1BIT)     \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_2BIT)  \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_3BIT)  \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_4BIT)  \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_5BIT)  \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_6BIT)  \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_7BIT)  \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_8BIT)  \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_9BIT)  \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_10BIT) \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_11BIT) \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_12BIT) \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_13BIT) \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_14BIT) \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_15BIT) \
                                        || ((__VALUE__) == LL_SPI_CTRLWIDTH_16BIT))

#define IS_LL_SPI_POLARITY(__VALUE__) (((__VALUE__) == LL_SPI_POLARITY_LOW) \
                                       || ((__VALUE__) == LL_SPI_POLARITY_HIGH))

#define IS_LL_SPI_PHASE(__VALUE__) (((__VALUE__) == LL_SPI_PHASE_1EDGE) \
                                    || ((__VALUE__) == LL_SPI_PHASE_2EDGE))

#define IS_LL_SPI_NSS(__VALUE__) ((__VALUE__) == LL_SPI_SLAVE_SELCT_0)

#define IS_LL_SPI_BAUDRATE(__VALUE__) (((__VALUE__) >= 2)      \
                                       && ((__VALUE__) <= 0x0000FFFE))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SPI_LL_Exported_Functions
  * @{
  */

/** @addtogroup SPI_LL_Exported_Functions_Group7
  * @{
  */

/**
  * @brief  De-initialize the SPI registers to their default reset values.
  * @param  SPIx SPI Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: SPI registers are de-initialized
  *          - ERROR: SPI registers are not de-initialized
  */
ErrorStatus LL_SPI_DeInit(SPI_TypeDef *SPIx)
{
  ErrorStatus status = ERROR;

  /* Check the parameters */
  assert_param(IS_SPI_ALL_INSTANCE(SPIx));

  /* Disable SPIx */
  LL_SPI_Disable(SPIx);

//#if defined(SPI1)
//  if (SPIx == SPI1)
//  {
//    /* Force reset of SPI clock */
//    LL_APB2_GRP1_ForceReset(LL_APB2_GRP1_PERIPH_SPI1);
//
//    /* Release reset of SPI clock */
//    LL_APB2_GRP1_ReleaseReset(LL_APB2_GRP1_PERIPH_SPI1);
//
//    status = SUCCESS;
//  }
//#endif /* SPI1 */
//#if defined(SPI2)
//  if (SPIx == SPI2)
//  {
//    /* Force reset of SPI clock */
//    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_SPI2);
//
//    /* Release reset of SPI clock */
//    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_SPI2);
//
//    status = SUCCESS;
//  }
//#endif /* SPI2 */
//#if defined(SPI3)
//  if (SPIx == SPI3)
//  {
//    /* Force reset of SPI clock */
//    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_SPI3);
//
//    /* Release reset of SPI clock */
//    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_SPI3);
//
//    status = SUCCESS;
//  }
//#endif /* SPI3 */
//#if defined(SPI4)
//  if (SPIx == SPI4)
//  {
//    /* Force reset of SPI clock */
//    LL_APB1_GRP1_ForceReset(LL_APB1_GRP1_PERIPH_SPI4);
//
//    /* Release reset of SPI clock */
//    LL_APB1_GRP1_ReleaseReset(LL_APB1_GRP1_PERIPH_SPI4);
//
//    status = SUCCESS;
//  }
//#endif /* SPI4 */

  status = SUCCESS;
  return status;
}

/**
  * @brief  Initialize the SPI registers according to the specified parameters in SPI_InitStruct.
  * @note   As some bits in SPI configuration registers can only be written when the SPI is disabled (SPI_CR1_SPE bit =0),
  *         SPI peripheral should be in disabled state prior calling this function. Otherwise, ERROR result will be returned.
  * @param  SPIx SPI Instance
  * @param  SPI_InitStruct pointer to a @ref LL_SPI_InitTypeDef structure
  * @retval An ErrorStatus enumeration value. (Return always SUCCESS)
  */
ErrorStatus LL_SPI_Init(SPI_TypeDef *SPIx, LL_SPI_InitTypeDef *SPI_InitStruct)
{
  ErrorStatus status = ERROR;

  /* Check the SPI Instance SPIx*/
  assert_param(IS_SPI_ALL_INSTANCE(SPIx));

  /* Check the SPI parameters from SPI_InitStruct*/
  assert_param(IS_LL_SPI_TRANSFER_DIRECTION(SPI_InitStruct->TransferDirection));
   assert_param(IS_LL_SPI_DATAWIDTH(SPI_InitStruct->DataWidth));
  assert_param(IS_LL_SPI_POLARITY(SPI_InitStruct->ClockPolarity));
  assert_param(IS_LL_SPI_PHASE(SPI_InitStruct->ClockPhase));
  assert_param(IS_LL_SPI_BAUDRATE(SPI_InitStruct->BaudRate));

  /* Disable SPIx */
  LL_SPI_Disable(SPIx);

  if(SPI_InitStruct->FrameFormat == LL_SPI_PROTOCOL_TI)
  {
    SPI_InitStruct->ClockPhase = LL_SPI_PHASE_1EDGE;
    SPI_InitStruct->ClockPolarity = LL_SPI_POLARITY_LOW;
  }

  /*---------------------------- SPIx CRTLR0 Configuration ------------------------
    * Configure SPIx CCTRLR0 with parameters:
    * - TransferDirection:  SPI_CTRLR_TMOD bits
    * - ClockPolarity:      SPI_CTRLR0_SCPOL bit
    * - ClockPhase:         SPI_CTRLR0_SCPH bit
    * - FrameFormat:        SPI_CTRLR0_FRF bit
    * - CtrlWidth:          SPI_CTRLR0_CFS bit
    * - DataWidth:          SPI_CTRLR0_DFS bit
    */
  MODIFY_REG(SPIx->CTRLR0,
              SPI_CTRLR0_TMOD | 
              SPI_CTRLR0_SCPOL | SPI_CTRLR0_SCPH |
              SPI_CTRLR0_FRF | SPI_CTRLR0_CFS | 
              SPI_CTRLR0_DFS,
              SPI_InitStruct->TransferDirection |
              SPI_InitStruct->ClockPolarity | SPI_InitStruct->ClockPhase |
              SPI_InitStruct->FrameFormat | SPI_InitStruct->CtrlWidth |
              SPI_InitStruct->DataWidth );

  /*---------------------------- SPIx CRTL1 Configuration ------------------------
    * Configure SPIx CRTLR1 with parameters:
    * - Number of data frame : NDF bits
    */
  WRITE_REG(SPIx->CTRLR1, SPI_InitStruct->NumDataFrame);

  /*---------------------------- SPIx BAUDR Configuration ------------------------
    * Configure SPIx BAUDR with parameters:
    * - Naudrate ssi clock divider : SCKDV bits
    */
  if (LL_SPI_IS_MASTER(SPIx))
  {
    WRITE_REG(SPIx->BAUDR, SPI_InitStruct->BaudRate);
    SET_BIT(SPIx->SER, LL_SPI_SLAVE_SELCT_0);
  }

  status = SUCCESS;

  return status;
}

/**
  * @brief  Set each @ref LL_SPI_InitTypeDef field to default value.
  * @param  SPI_InitStruct pointer to a @ref LL_SPI_InitTypeDef structure
  * whose fields will be set to default values.
  */
void LL_SPI_StructInit(LL_SPI_InitTypeDef *SPI_InitStruct)
{
  /* Set SPI_InitStruct fields to default values */
  SPI_InitStruct->TransferDirection = LL_SPI_TMOD_TXRX;
  SPI_InitStruct->DataWidth         = LL_SPI_DATAWIDTH_16BIT;
  SPI_InitStruct->ClockPolarity     = LL_SPI_POLARITY_LOW;
  SPI_InitStruct->ClockPhase        = LL_SPI_PHASE_1EDGE;
  SPI_InitStruct->BaudRate          = 2;                          /*!< 2 to 65534 */
  SPI_InitStruct->FrameFormat       = LL_SPI_PROTOCOL_MOTOROLA;
  SPI_InitStruct->CtrlWidth         = LL_SPI_CTRLWIDTH_1BIT;
  SPI_InitStruct->NumDataFrame      = 1;
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

#endif /* defined (SPI1) || defined (SPI2) || defined (SPI3) || defined (SPI4) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
