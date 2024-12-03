/**
  ******************************************************************************
  * @file    xt32h0xx_spi.h
  * @author  Software Team
  * @date    28 June 2022
  * @brief   This file contains all the functions prototypes for the SPI 
  *          firmware library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_SPI_H
#define __XT32H0XX_SPI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup SPI
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup SPI_Exported_Types SPI Exported Types
  * @{
  */

/** 
  * @brief  SPI Init structure definition  
  */

typedef struct
{
  uint16_t SPI_Direction;           /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                         This parameter can be a value of @ref SPI_data_direction */

  
  uint16_t SPI_DataSize;            /*!< Specifies the SPI data size.
                                         This parameter can be a value of @ref SPI_data_size */

  uint16_t SPI_CPOL;                /*!< Specifies the serial clock steady state.
                                         This parameter can be a value of @ref SPI_Clock_Polarity */

  uint16_t SPI_CPHA;                /*!< Specifies the clock active edge for the bit capture.
                                         This parameter can be a value of @ref SPI_Clock_Phase */

  uint16_t SPI_BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
                                         used to configure the transmit and receive SCK clock.
                                         This parameter can be a value of [2, 65534]
                                         @note The communication clock is derived from the master
                                               clock. The slave clock does not need to be set. */

  uint32_t SPI_ControlSize;         /*!< Specifies if the control data size
                                         This parameter can be a value of 0-15 */

  uint32_t SPI_NumberDataFrame;     /*!< Specifies if the number of data frame received continuously.
                                         This parameter can be a value of 0-65535 */

  uint32_t SPI_TxFIFOTLvl;          /*!< Specifies if the transmission FIFO threshold level register.
                                         This parameter can be a value of 0 - Tx fifo depth */

  uint32_t SPI_RxFIFOTLvl;          /*!< Specifies if the receive FIFO threshold level register.
                                         This parameter can be a value of 0 - Rx fifo depth */

  uint32_t SPI_Protocol;            /*!< Specifies if the receive FIFO threshold level register.
                                         This parameter can be a value of 0 - Rx fifo depth */
}SPI_InitTypeDef;
/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/

/** @defgroup SPI_Exported_Constants SPI Exported Constants
  * @{
  */

#define IS_SPI_ALL_PERIPH(PERIPH) (((PERIPH) == SPI1M) || \
                                   ((PERIPH) == SPI1S) || \
                                   ((PERIPH) == SPI2M) || \
                                   ((PERIPH) == SPI2S))
                                   
#define IS_SPI_1M_PERIPH(PERIPH) (((PERIPH) == SPI1M))
#define IS_SPI_1S_PERIPH(PERIPH) (((PERIPH) == SPI1S))
#define IS_SPI_2M_PERIPH(PERIPH) (((PERIPH) == SPI2M))
#define IS_SPI_2S_PERIPH(PERIPH) (((PERIPH) == SPI2S))

#define IS_SPI_MASTER(PERIPH)     (((PERIPH) == SPI1M) || \
                                   ((PERIPH) == SPI2M))

#define IS_SPI_SLAVE(PERIPH)      (((PERIPH) == SPI1S) || \
                                   ((PERIPH) == SPI1S))

/** @defgroup SPI_FIFO_Depth SPI FIFO Depth
  * @{
  */
#define SPI_RX_FIFO_DEPTH              (8)
#define SPI_TX_FIFO_DEPTH              (8)
/**
  * @}
  */

/** @defgroup SPI_data_direction SPI Data Direction
  * @{
  */
  
#define SPI_DIRECTION_2LINES           (0)
#define SPI_DIRECTION_2LINES_TXONLY    (SPI_CTRLR0_TMOD_0)
#define SPI_DIRECTION_2LINES_RXONLY    (SPI_CTRLR0_TMOD_1)

#define IS_SPI_DIRECTION_MODE(MODE) (((MODE) == SPI_DIRECTION_2LINES) || \
                                     ((MODE) == SPI_DIRECTION_2LINES_TXONLY) || \
                                     ((MODE) == SPI_DIRECTION_2LINES_RXONLY))
/**
  * @}
  */

/** @defgroup SPI_mode SPI Mode
  * @{
  */
#define SPI_MODE_MASTER                (0)
#define SPI_MODE_SLAVE                 (1)

#define IS_SPI_MODE(MODE) (((MODE) == SPI_MODE_MASTER) || \
                           ((MODE) == SPI_MODE_SLAVE))
/**
  * @}
  */

/** @defgroup SPI_data_size SPI Data Width
  * @{
  */

#define SPI_DATASIZE_4BIT              (SPI_CTRLR0_DFS_1 | SPI_CTRLR0_DFS_0)
#define SPI_DATASIZE_5BIT              (SPI_CTRLR0_DFS_2)
#define SPI_DATASIZE_6BIT              (SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_0)
#define SPI_DATASIZE_7BIT              (SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_1)
#define SPI_DATASIZE_8BIT              (SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_1 | SPI_CTRLR0_DFS_0)
#define SPI_DATASIZE_9BIT              (SPI_CTRLR0_DFS_3)
#define SPI_DATASIZE_10BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_0)
#define SPI_DATASIZE_11BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_1)
#define SPI_DATASIZE_12BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_1 | SPI_CTRLR0_DFS_0)
#define SPI_DATASIZE_13BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_2)
#define SPI_DATASIZE_14BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_0)
#define SPI_DATASIZE_15BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_1)
#define SPI_DATASIZE_16BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_1 | SPI_CTRLR0_DFS_0)

#define IS_SPI_DATA_SIZE(SIZE)  (((SIZE) == SPI_DATASIZE_4BIT) || \
                                 ((SIZE) == SPI_DATASIZE_5BIT) || \
                                 ((SIZE) == SPI_DATASIZE_6BIT) || \
                                 ((SIZE) == SPI_DATASIZE_7BIT) || \
                                 ((SIZE) == SPI_DATASIZE_8BIT) || \
                                 ((SIZE) == SPI_DATASIZE_9BIT) || \
                                 ((SIZE) == SPI_DATASIZE_10BIT) || \
                                 ((SIZE) == SPI_DATASIZE_11BIT) || \
                                 ((SIZE) == SPI_DATASIZE_12BIT) || \
                                 ((SIZE) == SPI_DATASIZE_13BIT) || \
                                 ((SIZE) == SPI_DATASIZE_14BIT) || \
                                 ((SIZE) == SPI_DATASIZE_15BIT) || \
                                 ((SIZE) == SPI_DATASIZE_16BIT))
/**
  * @}
  */

/** @defgroup SPI_CTRL_Size SPI Control Size
  * @{
  */
#define SPI_CTRLSIZE_1BIT              (0x00000000UL)                                                             
#define SPI_CTRLSIZE_2BIT              (SPI_CTRLR0_CFS_0)                                                         
#define SPI_CTRLSIZE_3BIT              (SPI_CTRLR0_CFS_1)                                                         
#define SPI_CTRLSIZE_4BIT              (SPI_CTRLR0_CFS_1 | SPI_CTRLR0_CFS_0)                                      
#define SPI_CTRLSIZE_5BIT              (SPI_CTRLR0_CFS_2)                                                         
#define SPI_CTRLSIZE_6BIT              (SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_0)                                      
#define SPI_CTRLSIZE_7BIT              (SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_1)                                      
#define SPI_CTRLSIZE_8BIT              (SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_1 | SPI_CTRLR0_CFS_0)                   
#define SPI_CTRLSIZE_9BIT              (SPI_CTRLR0_CFS_3)                                                         
#define SPI_CTRLSIZE_10BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_0)                                      
#define SPI_CTRLSIZE_11BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_1)                                      
#define SPI_CTRLSIZE_12BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_1 | SPI_CTRLR0_CFS_0)                   
#define SPI_CTRLSIZE_13BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_2)                                      
#define SPI_CTRLSIZE_14BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_0)                   
#define SPI_CTRLSIZE_15BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_1)                   
#define SPI_CTRLSIZE_16BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_1 | SPI_CTRLR0_CFS_0)

#define IS_SPI_CTRL_SIZE(SIZE)  (((SIZE) == SPI_CTRLSIZE_1BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_2BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_3BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_4BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_5BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_6BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_7BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_8BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_9BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_10BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_11BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_12BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_13BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_14BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_15BIT) || \
                                 ((SIZE) == SPI_CTRLSIZE_16BIT))
/**
  * @}
  */

/** @defgroup SPI_Clock_Polarity SPI Clock Polarity
  * @{
  */
#define SPI_POLARITY_LOW               (0x00000000U)
#define SPI_POLARITY_HIGH              (SPI_CTRLR0_SCPOL)

#define IS_SPI_CPOL(CPOL) (((CPOL) == SPI_POLARITY_LOW) || \
                           ((CPOL) == SPI_POLARITY_HIGH))
/**
  * @}
  */

/** @defgroup SPI_Clock_Phase SP Clock Phase
  * @{
  */
#define SPI_PHASE_1EDGE                (0x00000000U)
#define SPI_PHASE_2EDGE                (SPI_CTRLR0_SCPH)

#define IS_SPI_CPHA(CPHA) (((CPHA) == SPI_PHASE_1EDGE) || \
                           ((CPHA) == SPI_PHASE_2EDGE))
/**
  * @}
  */

/** @defgroup SPI_Slave_Select_management SPI Slave Select Management
  * @{
  */
#define SPI_SLAVE_SELECT_0             (SPI_SER_SER)
/**
  * @}
  */

/** @defgroup SPI_Standard SPI Standard
  * @{
  */
#define SPI_PROTOCOL_MOTOROLA          (0x00000000UL)                          /*!< Motorola SPI                         */
#define SPI_PROTOCOL_TI                (SPI_CTRLR0_FRF_0)                      /*!< TI SSP                               */
#define SPI_PROTOCOL_NS                (SPI_CTRLR0_FRF_1)                      /*!< National Semiconductors microwire    */

#define IS_SPI_PROTOCOL(FRF)   (((FRF) == SPI_PROTOCOL_MOTOROLA) || \
                                ((FRF) == SPI_PROTOCOL_TI) || \
                                ((FRF) == SPI_PROTOCOL_NS))
/**
  * @}
  */

/** @defgroup SPI_EC_RX_FIFO_TH RX FIFO Threshold
  * @{
  */
#define SPI_RX_FIFO_TH_EMPTY           (0x00000000UL)                          /*!< RXNE event is generated if FIFO level is greater than or equal to empty */
#define SPI_RX_FIFO_TH_QUARTER         ((SPI_RX_FIFO_DEPTH-1)>>2)              /*!< RXNE event is generated if FIFO level is greater than or equal to 1/4   */
#define SPI_RX_FIFO_TH_HALF            ((SPI_RX_FIFO_DEPTH-1)>>1)              /*!< RXNE event is generated if FIFO level is greater than or equal to 1/2   */
#define SPI_RX_FIFO_TH_FULL            (SPI_RX_FIFO_DEPTH-1)                   /*!< RXNE event is generated if FIFO level is greater than or equal to full  */

#define IS_SPI_RXFIFO_TH(TH) (((TH) == SPI_RX_FIFO_TH_EMPTY) || \
                              ((TH) == SPI_RX_FIFO_TH_QUARTER) || \
                              ((TH) == SPI_RX_FIFO_TH_HALF) || \
                              ((TH) == SPI_RX_FIFO_TH_FULL))
/**
  * @}
  */

/** @defgroup SPI_EC_TX_FIFO_TH TX FIFO Threshold
  * @{
  */
#define SPI_TX_FIFO_TH_EMPTY           (0x00000000UL)                          /*!< TXNF event is generated if FIFO level is greater than or equal to empty   */
#define SPI_TX_FIFO_TH_QUARTER         ((SPI_TX_FIFO_DEPTH)>>2)                /*!< TXNF event is generated if FIFO level is greater than or equal to 1/4     */
#define SPI_TX_FIFO_TH_HALF            ((SPI_TX_FIFO_DEPTH)>>1)                /*!< TXNF event is generated if FIFO level is greater than or equal to 1/2     */
#define SPI_TX_FIFO_TH_FULL            (SPI_TX_FIFO_DEPTH)                     /*!< TXNF event is generated if FIFO level is greater than or equal to full    */

#define IS_SPI_TXFIFO_TH(TH) (((TH) == SPI_TX_FIFO_TH_EMPTY) || \
                              ((TH) == SPI_TX_FIFO_TH_QUARTER) || \
                              ((TH) == SPI_TX_FIFO_TH_HALF) || \
                              ((TH) == SPI_TX_FIFO_TH_FULL))
/**
  * @}
  */

/** @defgroup SPI_EC_DMA_RX_LEVEL DMA RX REQ data level
  * @{
  */
#define SPI_DMA_RX_REQ_LVL_EMPTY       (0x00000000UL)                          /*!< DMA RX REQ event is generated if FIFO level is equal to empty */
#define SPI_DMA_RX_REQ_LVL_QUARTER     ((SPI_RX_FIFO_DEPTH)>>2 - 1)            /*!< DMA RX REQ event is generated if FIFO level is equal to 1/4   */
#define SPI_DMA_RX_REQ_LVL_HALF        ((SPI_RX_FIFO_DEPTH)>>1 - 1)            /*!< DMA RX REQ event is generated if FIFO level is equal to 1/2   */
#define SPI_DMA_RX_REQ_LVL_FULL        (SPI_RX_FIFO_DEPTH - 1)                 /*!< DMA RX REQ event is generated if FIFO level is equal to full  */

#define IS_SPI_DMA_RX_REQ_LVL(LVL) (((LVL) == SPI_DMA_RX_REQ_LVL_EMPTY) || \
                                    ((LVL) == SPI_DMA_RX_REQ_LVL_QUARTER) || \
                                    ((LVL) == SPI_DMA_RX_REQ_LVL_HALF) || \
                                    ((LVL) == SPI_DMA_RX_REQ_LVL_FULL))
/**
  * @}
  */

/** @defgroup SPI_EC_DMA_TX_LEVEL DMA TX REQ data level
  * @{
  */
#define SPI_DMA_TX_REQ_LVL_EMPTY       (0x00000000UL)                          /*!< DMA TX REQ event is generated if FIFO level is equal to empty   */
#define SPI_DMA_TX_REQ_LVL_QUARTER     ((SPI_TX_FIFO_DEPTH)>>2)                /*!< DMA TX REQ event is generated if FIFO level is equal to 1/4     */
#define SPI_DMA_TX_REQ_LVL_HALF        ((SPI_TX_FIFO_DEPTH)>>1)                /*!< DMA TX REQ event is generated if FIFO level is equal to 1/2     */
#define SPI_DMA_TX_REQ_LVL_FULL        (SPI_TX_FIFO_DEPTH)                     /*!< DMA TX REQ event is generated if FIFO level is equal to full    */

#define IS_SPI_DMA_TX_REQ_LVL(LVL) (((LVL) == SPI_DMA_TX_REQ_LVL_EMPTY) || \
                                    ((LVL) == SPI_DMA_TX_REQ_LVL_QUARTER) || \
                                    ((LVL) == SPI_DMA_TX_REQ_LVL_HALF) || \
                                    ((LVL) == SPI_DMA_TX_REQ_LVL_FULL))
/**
  * @}
  */

/** @defgroup SPI_DMA_transfer_requests SPI DMA Transfer Request
  * @{
  */

#define SPI_DMAREQ_TX                  (SPI_DMACR_TDMAE)
#define SPI_DMAREQ_RX                  (SPI_DMACR_RDMAE)

#define IS_SPI_DMA_REQ(REQ) (((REQ) == SPI_DMACR_TDMAE) || ((REQ) == SPI_DMACR_RDMAE))
/**
  * @}
  */

/** @defgroup SPI_Interrupt_definition SPI Interrupt Definition
  * @{
  */
#define SPI_IT_TXE                     (SPI_ISR_TXEIS)
#define SPI_IT_TXO                     (SPI_ISR_TXOIS)
#define SPI_IT_RXU                     (SPI_ISR_RXUIS)
#define SPI_IT_RXO                     (SPI_ISR_RXOIS)
#define SPI_IT_RXF                     (SPI_ISR_RXFIS)
#define SPI_IT_MST                     (SPI_ISR_MSTIS)
#define SPI_IT_ALL                     (SPI_ISR_TXEIS | SPI_ISR_TXOIS | \
                                        SPI_ISR_RXUIS | SPI_ISR_RXOIS | SPI_ISR_RXFIS | \
																				SPI_ISR_MSTIS)

#define IS_SPI_GET_IT(IT)     (((IT) == SPI_IT_TXE) || ((IT) == SPI_IT_TXO) || \
                               ((IT) == SPI_IT_RXU) || ((IT) == SPI_IT_RXO) || \
                               ((IT) == SPI_IT_RXF)|| ((IT) == SPI_IT_MST))
/**
  * @}
  */

/** @defgroup SPI_Status_definition SPI Status Definition
  * @{
  */
#define SPI_STATUS_BUSY                (SPI_SR_BUSY)                           /* SPI status flag: ssi busy flag            */
#define SPI_STATUS_TFNF                (SPI_SR_TFNF)                           /* SPI status flag: tx FIFO no full flag     */
#define SPI_STATUS_TFE                 (SPI_SR_TFE )                           /* SPI status flag: tx FIFO empty flag       */
#define SPI_STATUS_RFNE                (SPI_SR_RFNE)                           /* SPI Error flag: rx FIFO not empty flag    */
#define SPI_STATUS_RFF                 (SPI_SR_RFF )                           /* SPI Error flag: rx FIFO full flag         */
#define SPI_STATUS_TXE                 (SPI_SR_TXE )                           /* SPI Error flag: tx error flag             */
#define SPI_STATUS_DCOL                (SPI_SR_DCOL)                           /* SPI Error flag: data collision error flag */
#define SPI_STATUS_MASK                (SPI_SR_BUSY | SPI_SR_TFNF | SPI_SR_TFE | SPI_SR_RFNE\
                                         | SPI_SR_RFF | SPI_SR_TXE | SPI_SR_DCOL)

#define IS_SPI_GET_STATUS(STATUS)     (((STATUS) == SPI_STATUS_BUSY) || ((STATUS) == SPI_STATUS_TFNF) || \
                                       ((STATUS) == SPI_STATUS_TFE) || ((STATUS) == SPI_STATUS_RFNE) || \
                                       ((STATUS) == SPI_STATUS_RFF)|| ((STATUS) == SPI_STATUS_TXE) || \
                                       ((STATUS) == SPI_STATUS_DCOL))
/**
  * @}
  */

/** @defgroup SPI_Baudrate_Prescaler SPI Baudrate
  * @{
  */
#define IS_SPI_BAUDRATE_PRESCALER(PRESCALER) (((PRESCALER) >= 2) && ((PRESCALER) <= 65534))
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup SPI_Exported_Functions
  * @{
  */

/** @addtogroup SPI_Exported_Functions_Group1
  * @{
  */

/* Initialization and Configuration functions *********************************/
void SPI_DeInit(SPI_TypeDef* SPIx);
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize);
void SPI_RxFIFOThresholdConfig(SPI_TypeDef* SPIx, uint16_t SPI_FIFOThreshold);
void SPI_TxFIFOThresholdConfig(SPI_TypeDef* SPIx, uint16_t SPI_FIFOThreshold);
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState);
/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group2
  * @{
  */
/* Data transfers functions ***************************************************/
void SPI_SendData8(SPI_TypeDef* SPIx, uint8_t Data);
void SPI_SendData16(SPI_TypeDef* SPIx, uint16_t Data);
uint8_t SPI_ReceiveData8(SPI_TypeDef* SPIx);
uint16_t SPI_ReceiveData16(SPI_TypeDef* SPIx);

/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group3
  * @{
  */
/* DMA transfers management functions *****************************************/
void SPI_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_DMAReq, FunctionalState NewState);
void SPI_DMARxLevelConfig(SPI_TypeDef* SPIx, uint16_t SPI_DmaDataLevel);
void SPI_DMATxLevelConfig(SPI_TypeDef* SPIx, uint16_t SPI_DmaDataLevel);
//void SPI_LastDMATransferCmd(SPI_TypeDef* SPIx, uint16_t SPI_LastDMATransfer);

/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group4
  * @{
  */
/* Interrupts and flags management functions **********************************/
void SPI_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_IT, FunctionalState NewState);
uint16_t SPI_GetTransmissionFIFOStatus(SPI_TypeDef* SPIx);
uint16_t SPI_GetReceptionFIFOStatus(SPI_TypeDef* SPIx);
uint32_t SPI_GetFlagStatus(SPI_TypeDef* SPIx);
void SPI_ClearIT(SPI_TypeDef* SPIx, uint16_t SPI_IT);
ITStatus SPI_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_IT);
ITStatus SPI_GetITRawStatus(SPI_TypeDef* SPIx, uint8_t SPI_IT);
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

#endif /*__XT32H0XX_SPI_H */


