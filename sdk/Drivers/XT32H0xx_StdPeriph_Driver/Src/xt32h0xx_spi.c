/**
  ******************************************************************************
  * @file    xt32h0xx_spi.c
  * @author  Software Team
  * @date    28 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Serial peripheral interface (SPI):
  *           + Initialization and Configuration
  *           + Data transfers functions
  *           + Hardware CRC Calculation
  *           + DMA transfers management
  *           + Interrupts and flags management
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_spi.h"
#include "xt32h0xx_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup SPI SPI
  * @brief SPI driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup SPI_Exported_Functions SPI Exported Functions
  * @{
  */

/** @defgroup SPI_Exported_Functions_Group1 Initialization and Configuration functions
  *  @brief   Initialization and Configuration functions 
  *
  * @{
  */

/**
  * @brief  Deinitializes the SPIx peripheral registers to their default
  *         reset values.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  */
void SPI_DeInit(SPI_TypeDef* SPIx)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));

  SPIx->SER &= (uint32_t)~((uint32_t)SPI_SLAVE_SELECT_0);
  SPIx->SSIENR &= (uint32_t)~((uint32_t)SPI_SSIENR_SSIEN);
}

/**
  * @brief  Fills each SPI_InitStruct member with its default value.
  * @param  SPI_InitStruct: pointer to a SPI_InitTypeDef structure which will be initialized.
  */
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct)
{
/*--------------- Reset SPI init structure parameters values -----------------*/
  /* Initialize the SPI_Direction member */
  SPI_InitStruct->SPI_Direction = SPI_DIRECTION_2LINES;
  SPI_InitStruct->SPI_DataSize = SPI_DATASIZE_8BIT;
  SPI_InitStruct->SPI_CPOL = SPI_POLARITY_LOW;
  SPI_InitStruct->SPI_CPHA = SPI_PHASE_1EDGE;
  SPI_InitStruct->SPI_BaudRatePrescaler = 2;
  SPI_InitStruct->SPI_ControlSize = SPI_CTRLSIZE_1BIT;
  SPI_InitStruct->SPI_NumberDataFrame = 1;
  SPI_InitStruct->SPI_TxFIFOTLvl = SPI_TX_FIFO_TH_HALF;
  SPI_InitStruct->SPI_RxFIFOTLvl = SPI_RX_FIFO_TH_HALF;
  SPI_InitStruct->SPI_Protocol = SPI_PROTOCOL_MOTOROLA;
}

/**
  * @brief  Initializes the SPIx peripheral according to the specified 
  *         parameters in the SPI_InitStruct.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @param  SPI_InitStruct: pointer to a SPI_InitTypeDef structure that
  *         contains the configuration information for the specified SPI peripheral.
  */
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct)
{
  uint16_t tmpreg = 0;

  /* check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));

  /* Check the SPI parameters */
  assert_param(IS_SPI_DIRECTION_MODE(SPI_InitStruct->SPI_Direction));
  assert_param(IS_SPI_DATA_SIZE(SPI_InitStruct->SPI_DataSize));
  assert_param(IS_SPI_CPOL(SPI_InitStruct->SPI_CPOL));
  assert_param(IS_SPI_CPHA(SPI_InitStruct->SPI_CPHA));
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_InitStruct->SPI_BaudRatePrescaler));
  assert_param(IS_SPI_RXFIFO_TH(SPI_InitStruct->SPI_RxFIFOTLvl));
  assert_param(IS_SPI_TXFIFO_TH(SPI_InitStruct->SPI_TxFIFOTLvl));


  //disable SPIx
  SPIx->SSIENR &= (uint16_t)~((uint16_t)SPI_SSIENR_SSIEN);

  /*---------------------------- SPIx CTRLR0 Configuration ------------------------*/
  tmpreg = SPIx->CTRLR0;
  tmpreg &= (uint32_t)~((uint32_t)(SPI_CTRLR0_TMOD|SPI_CTRLR0_SCPOL|SPI_CTRLR0_SCPH|
                                   SPI_CTRLR0_DFS|SPI_CTRLR0_CFS|SPI_CTRLR0_FRF));
  tmpreg |= (uint16_t)((uint32_t)SPI_InitStruct->SPI_Direction | SPI_InitStruct->SPI_DataSize |
                      SPI_InitStruct->SPI_CPOL | SPI_InitStruct->SPI_CPHA |
                      SPI_InitStruct->SPI_ControlSize | SPI_InitStruct->SPI_Protocol);  
  SPIx->CTRLR0 = tmpreg;
  
  /*-------------------------Data number frame Configuration -----------------------*/
  SPIx->CTRLR1 = (SPI_InitStruct->SPI_NumberDataFrame -1);
 
  /*---------------------------- SPIx Baudrate Configuration --------------------*/
  SPIx->BAUDR = SPI_InitStruct->SPI_BaudRatePrescaler;
  
  /*---------------------------- SPIx FIFO Configuration ------------------------*/
  SPIx->TXFTLR = SPI_InitStruct->SPI_TxFIFOTLvl;
  SPIx->RXFTLR = SPI_InitStruct->SPI_RxFIFOTLvl;
  
  if(IS_SPI_MASTER(SPIx))
  {
    SPIx->SER |= ((uint16_t)SPI_SLAVE_SELECT_0);
  }

  if(IS_SPI_1M_PERIPH(SPIx))
  {
    SYSCFG->SYS_CFG |= (uint32_t)SYSCFG_SYS_CFG_SPI1_MODE;
  }
  else if(IS_SPI_1S_PERIPH(SPIx))
  {
    SYSCFG->SYS_CFG &= (uint32_t)(~SYSCFG_SYS_CFG_SPI1_MODE);
  }
  else if(IS_SPI_2M_PERIPH(SPIx))
  {
    SYSCFG->SYS_CFG |= (uint32_t)SYSCFG_SYS_CFG_SPI2_MODE;
  }
  else if(IS_SPI_2S_PERIPH(SPIx))
  {
    SYSCFG->SYS_CFG &= (uint32_t)(~SYSCFG_SYS_CFG_SPI2_MODE);
  }
}

/**
  * @brief  Enables or disables the specified SPI peripheral.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @param  NewState: new state of the SPIx peripheral. 
  *          This parameter can be: ENABLE or DISABLE.
  */
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the selected SPI peripheral */
    SPIx->SSIENR |= SPI_SSIENR_SSIEN;
  }
  else
  {
    /* Disable the selected SPI peripheral */
    SPIx->SSIENR &= (uint16_t)~((uint16_t)SPI_SSIENR_SSIEN);
  }
}


/**
  * @brief  Configures the data size for the selected SPI.
  * @param  SPIx: where x can be 1 or 2  to select the SPI peripheral.
  * @param  SPI_DataSize: specifies the SPI data size.
  *         For the SPIx peripheral this parameter can be one of the following values:
  *            @arg @ref SPI_DATASIZE_4BIT Set data size to 4 bits
  *            @arg @ref SPI_DATASIZE_5BIT Set data size to 5 bits
  *            @arg @ref SPI_DATASIZE_6BIT Set data size to 6 bits
  *            @arg @ref SPI_DATASIZE_7BIT Set data size to 7 bits
  *            @arg @ref SPI_DATASIZE_8BIT Set data size to 8 bits
  *            @arg @ref SPI_DATASIZE_9BIT Set data size to 9 bits
  *            @arg @ref SPI_DATASIZE_10BIT Set data size to 10 bits
  *            @arg @ref SPI_DATASIZE_11BIT Set data size to 11 bits
  *            @arg @ref SPI_DATASIZE_12BIT Set data size to 12 bits
  *            @arg @ref SPI_DATASIZE_13BIT Set data size to 13 bits
  *            @arg @ref SPI_DATASIZE_14BIT Set data size to 14 bits
  *            @arg @ref SPI_DATASIZE_15BIT Set data size to 15 bits
  *            @arg @ref SPI_DATASIZE_16BIT Set data size to 16 bits
  */
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize)
{
  uint16_t tmpreg = 0;
  
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_DATA_SIZE(SPI_DataSize));
  /* Read the CTRLR0 register */
  tmpreg = SPIx->CTRLR0;
  /* Clear DS[3:0] bits */
  tmpreg &= (uint32_t)~SPI_CTRLR0_DFS;
  /* Set new DS[3:0] bits value */
  tmpreg |= SPI_DataSize;
  SPIx->CTRLR0 = tmpreg;
}

/**
  * @brief  Configures the FIFO reception threshold for the selected SPI.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @param  SPI_FIFOThreshold: specifies the FIFO reception threshold.
  *          This parameter can be one of the following values:
  *            @arg @ref SPI_RX_FIFO_TH_EMPTY   
  *            @arg @ref SPI_RX_FIFO_TH_QUARTER 
  *            @arg @ref SPI_RX_FIFO_TH_HALF    
  *            @arg @ref SPI_RX_FIFO_TH_FULL    
  */
void SPI_RxFIFOThresholdConfig(SPI_TypeDef* SPIx, uint16_t SPI_FIFOThreshold)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_RXFIFO_TH(SPI_FIFOThreshold));

  /* Set new FRXTH bit value */
  SPIx->RXFTLR = SPI_FIFOThreshold;
}

/**
  * @brief  Configures the FIFO transmission threshold for the selected SPI.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @param  SPI_FIFOThreshold: specifies the FIFO transmission threshold.
  *          This parameter can be one of the following values:
  *            @arg @ref SPI_TX_FIFO_TH_EMPTY  
  *            @arg @ref SPI_TX_FIFO_TH_QUARTER
  *            @arg @ref SPI_TX_FIFO_TH_HALF   
  *            @arg @ref SPI_TX_FIFO_TH_FULL   
  */
void SPI_TxFIFOThresholdConfig(SPI_TypeDef* SPIx, uint16_t SPI_FIFOThreshold)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_TXFIFO_TH(SPI_FIFOThreshold));

  /* Set new FRXTH bit value */
  SPIx->TXFTLR = SPI_FIFOThreshold;
}

/**
  * @brief  Enables or disables the SS output for the selected SPI.
  * @note   This function can be called only after the SPI_Init() function has 
  *         been called and the NSS hardware management mode is selected. 
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @param  NewState: new state of the SPIx SS output. 
  *          This parameter can be: ENABLE or DISABLE.
  */
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* Enable the selected SPI SS output */
    SPIx->SER |= SPI_SLAVE_SELECT_0;
  }
  else
  {
    /* Disable the selected SPI SS output */
    SPIx->SER &= (uint16_t)~((uint16_t)SPI_SLAVE_SELECT_0);
  }
}

/**
  * @}
  */

/** @defgroup SPI_Exported_Functions_Group2 Data transfers functions
 *  @brief   Data transfers functions
 *
  * @{
  */

/**
  * @brief  Transmits a Data through the SPIx peripheral.
  * @param  SPIx: where x can be 1 or 2 in SPI mode to select the SPI peripheral.
  * @param  Data: Data to be transmitted.
  */
void SPI_SendData8(SPI_TypeDef* SPIx, uint8_t Data)
{
  uint32_t spixbase = 0x00;

  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));

  *(__IO uint8_t *) &SPIx->DR = Data;
}

/**
  * @brief  Transmits a Data through the SPIx peripheral.
  * @param  SPIx: where x can be 1 or 2 in SPI mode to select 
  *         the SPI peripheral. 
  * @param  Data: Data to be transmitted.
  */
void SPI_SendData16(SPI_TypeDef* SPIx, uint16_t Data)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  
  SPIx->DR = (uint16_t)Data;
}

/**
  * @brief  Returns the most recent received data by the SPIx peripheral. 
  * @param  SPIx: where x can be 1 or 2 in SPI mode to select the SPI peripheral. 
  * @retval The value of the received data.
  */
uint8_t SPI_ReceiveData8(SPI_TypeDef* SPIx)
{
  return *(__IO uint8_t *) &SPIx->DR;
}

/**
  * @brief  Returns the most recent received data by the SPIx peripheral. 
  * @param  SPIx: where x can be 1 or 2 in SPI mode to select
  * @retval The value of the received data.
  */
uint16_t SPI_ReceiveData16(SPI_TypeDef* SPIx)
{
  return SPIx->DR;
}
/**
  * @}
  */

/** @defgroup SPI_Exported_Functions_Group3 DMA transfers management functions
 *  @brief   DMA transfers management functions
  *
  * @{
  */

/**
  * @brief  Enables or disables the SPIx DMA interface.
  * @param  SPIx: where x can be 1 or 2 in SPI mode to select 
  *         the SPI peripheral.
  * @param  SPI_DMAReq: specifies the SPI DMA transfer request to be enabled or disabled. 
  *          This parameter can be any combination of the following values:
  *            @arg @ref SPI_DMAREQ_TX Tx buffer DMA transfer request
  *            @arg @ref SPI_DMAREQ_RX Rx buffer DMA transfer request
  * @param  NewState: new state of the selected SPI DMA transfer request.
  *          This parameter can be: ENABLE or DISABLE.
  */
void SPI_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_DMAReq, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_SPI_DMA_REQ(SPI_DMAReq));

  if (NewState != DISABLE)
  {
    /* Enable the selected SPI DMA requests */
    SPIx->DMACR |= SPI_DMAReq;
  }
  else
  {
    /* Disable the selected SPI DMA requests */
    SPIx->DMACR &= (uint16_t)~SPI_DMAReq;
  }
}

/**
  * @brief  Configures the DMA RX request data level for the selected SPI.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @param  SPI_DmaDataLevel: specifies the DMA reception data level.
  *          This parameter can be one of the following values:
  *            @arg @ref SPI_DMA_RX_REQ_LVL_EMPTY
  *            @arg @ref SPI_DMA_RX_REQ_LVL_QUARTER 
  *            @arg @ref SPI_DMA_RX_REQ_LVL_HALF
  *            @arg @ref SPI_DMA_RX_REQ_LVL_FULL 
  */
void SPI_DMARxLevelConfig(SPI_TypeDef* SPIx, uint16_t SPI_DmaDataLevel)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_DMA_TX_REQ_LVL(SPI_DmaDataLevel));

  /* Set new data level value */
  SPIx->DMARDLR = SPI_DmaDataLevel;
}
/**
  * @brief  Configures the DMA TX request data level for the selected SPI.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @param  SPI_DmaDataLevel: specifies the DMA tranmission data level.
  *          This parameter can be one of the following values:
  *            @arg @ref SPI_DMA_TX_REQ_LVL_EMPTY
  *            @arg @ref SPI_DMA_TX_REQ_LVL_QUARTER 
  *            @arg @ref SPI_DMA_TX_REQ_LVL_HALF
  *            @arg @ref SPI_DMA_TX_REQ_LVL_FULL 
  */
void SPI_DMATxLevelConfig(SPI_TypeDef* SPIx, uint16_t SPI_DmaDataLevel)
{
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_DMA_TX_REQ_LVL(SPI_DmaDataLevel));

  /* Set new data level value */
  SPIx->DMATDLR = SPI_DmaDataLevel;
}

/**
  * @}
  */

/** @defgroup SPI_Exported_Functions_Group4 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions
  *
  * @{
  */

/**
  * @brief  Enables or disables the specified SPI interrupts.
  * @param  SPIx: where x can be 1 or 2 in SPI mode  to select 
  *         the SPI peripheral.  
  * @param  SPI_IT: specifies the SPI interrupt source to be enabled or disabled. 
  *         This parameter can be one of the following values:
  *         @arg @ref SPI_IT_TXE
  *         @arg @ref SPI_IT_TXO
  *         @arg @ref SPI_IT_RXU
  *         @arg @ref SPI_IT_RXO
  *         @arg @ref SPI_IT_RXF
  *         @arg @ref SPI_IT_MST
  *         @arg @ref SPI_IT_ALL
  * @param  NewState: new state of the specified SPI interrupt.
  *          This parameter can be: ENABLE or DISABLE.
  */
void SPI_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_IT, FunctionalState NewState)
{
  uint16_t itpos = 0, itmask = 0 ;

  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the selected SPI interrupt */
    SPIx->IMR |= SPI_IT;
  }
  else
  {
    /* Disable the selected SPI interrupt */
    SPIx->IMR &= (uint16_t)~SPI_IT;
  }
}

/**
  * @brief  Returns the current SPIx Transmission FIFO filled level.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @retval The Transmission FIFO filling state.
  *          - SPI_TransmissionFIFOStatus_Empty: when FIFO is empty
  *          - SPI_TransmissionFIFOStatus_1QuarterFull: if more than 1 quarter-full.
  *          - SPI_TransmissionFIFOStatus_HalfFull: if more than 1 half-full.
  *          - SPI_TransmissionFIFOStatus_Full: when FIFO is full.
  */
uint16_t SPI_GetTransmissionFIFOStatus(SPI_TypeDef* SPIx)
{
  /* Get the SPIx Transmission FIFO level bits */
  return (uint16_t)((SPIx->TXFLR));
}

/**
  * @brief  Returns the current SPIx Reception FIFO filled level.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @retval The Reception FIFO filling state.
  *          - SPI_ReceptionFIFOStatus_Empty: when FIFO is empty
  *          - SPI_ReceptionFIFOStatus_1QuarterFull: if more than 1 quarter-full.
  *          - SPI_ReceptionFIFOStatus_HalfFull: if more than 1 half-full.
  *          - SPI_ReceptionFIFOStatus_Full: when FIFO is full.
  */
uint16_t SPI_GetReceptionFIFOStatus(SPI_TypeDef* SPIx)
{
  /* Get the SPIx Reception FIFO level bits */
  return (uint16_t)((SPIx->RXFLR));
}

/**
  * @brief  Checks whether the specified SPI flag is set or not.
  * @param  SPIx: where x can be 1 or 2 in SPI mode to select the SPI peripheral.    
  * @retval The spi flag.
  *         This parameter can be one of the following values:
  *         @arg @ref SPI_STATUS_BUSY 
  *         @arg @ref SPI_STATUS_TFNF 
  *         @arg @ref SPI_STATUS_TFE  
  *         @arg @ref SPI_STATUS_RFNE 
  *         @arg @ref SPI_STATUS_RFF  
  *         @arg @ref SPI_STATUS_TXE  
  *         @arg @ref SPI_STATUS_DCOL 
  *         @arg @ref SPI_STATUS_MASK 
  */
uint32_t SPI_GetFlagStatus(SPI_TypeDef* SPIx)
{
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  return  (uint32_t)(SPIx->SR);
}

/**
  * @brief  Clears the SPIx CRC Error (CRCERR) flag.
  * @param  SPIx: where x can be 1 or 2 to select the SPI peripheral.
  * @param  SPI_IT: specifies the SPI flag to clear. 
  *         This parameter can be one of the following values:
  *         @arg @ref SPI_IT_TXO
  *         @arg @ref SPI_IT_RXU
  *         @arg @ref SPI_IT_RXO
  *         @arg @ref SPI_IT_MST
  *         @arg @ref SPI_IT_ALL
  */
void SPI_ClearIT(SPI_TypeDef* SPIx, uint16_t SPI_IT)
{
  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
//  assert_param(IS_SPI_CLEAR_FLAG(SPI_IT));

  /* Clear the selected SPI flag */
  if(SPI_IT & SPI_IT_TXO)
  {
    SPIx->TXOICR;
  }
  if(SPI_IT & SPI_IT_RXO)
  {
    SPIx->RXOICR;
  }
  if(SPI_IT & SPI_IT_RXU)
  {
    SPIx->RXUICR;
  }
  if(SPI_IT & SPI_IT_MST)
  {
    SPIx->MSTICR;
  }
  if(SPI_IT & SPI_IT_ALL)
  {
    SPIx->ICR;
  }
  
}

/**
  * @brief  Checks whether the specified SPI interrupt has occurred or not.
  * @param  SPIx: where x can be 1 or 2 in SPI mode to select 
  *         the SPI peripheral.
  * @param  SPI_IT: specifies the SPI interrupt source to check. 
  *         This parameter can be one of the following values:
  *         @arg @ref SPI_IT_TXE
  *         @arg @ref SPI_IT_TXO
  *         @arg @ref SPI_IT_RXU
  *         @arg @ref SPI_IT_RXO
  *         @arg @ref SPI_IT_RXF
  *         @arg @ref SPI_IT_MST
  *         @arg @ref SPI_IT_ALL
  * @retval The new state of SPI_IT (SET or RESET).
  */
ITStatus SPI_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_IT)
{
  ITStatus bitstatus = RESET;

  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_GET_IT(SPI_IT));

  /* Check the status of the specified SPI interrupt */
  if (((SPIx->ISR & SPI_IT) != (uint16_t)RESET))
  {
    /* SPI_IT is set */
    bitstatus = SET;
  }
  else
  {
    /* SPI_IT is reset */
    bitstatus = RESET;
  }
  /* Return the SPI_IT status */
  return bitstatus;
}

/**
  * @brief  Checks whether the specified SPI interrupt has occurred or not.
  * @param  SPIx: where x can be 1 or 2 in SPI mode to select 
  *         the SPI peripheral.
  * @param  SPI_IT: specifies the SPI interrupt source to check. 
  *         This parameter can be one of the following values:
  *         @arg @ref SPI_IT_TXE
  *         @arg @ref SPI_IT_TXO
  *         @arg @ref SPI_IT_RXU
  *         @arg @ref SPI_IT_RXO
  *         @arg @ref SPI_IT_RXF
  *         @arg @ref SPI_IT_MST
  *         @arg @ref SPI_IT_ALL
  * @retval The new state of SPI_IT (SET or RESET).
  */
ITStatus SPI_GetITRawStatus(SPI_TypeDef* SPIx, uint8_t SPI_IT)
{
  ITStatus bitstatus = RESET;

  /* Check the parameters */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_GET_IT(SPI_IT));

  /* Check the status of the specified SPI interrupt */
  if (((SPIx->RISR & SPI_IT) != (uint16_t)RESET))
  {
    /* SPI_IT is set */
    bitstatus = SET;
  }
  else
  {
    /* SPI_IT is reset */
    bitstatus = RESET;
  }
  /* Return the SPI_IT status */
  return bitstatus;
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

