/**
  ******************************************************************************
  * @file    xt32h0xx_ll_spi.h
  * @author  Software Team
  * @brief   Header file of SPI LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_SPI_H
#define XT32H0xx_LL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (SPI1M) || defined (SPI1S) || defined (SPI2M) || defined (SPI2S)

/** @defgroup SPI_LL SPI
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @addtogroup SPI_LL_Private_Constants
  * @{
  */
#define SPI_LL_RX_FIFO_DEPTH           (8)
#define SPI_LL_TX_FIFO_DEPTH           (8)
/**
  * @}
  */
/* Private macros ------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/** @defgroup SPI_LL_Exported_Types SPI Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup SPI_LL_ES_INIT SPI Exported Init structure
  * @{
  */

/**
  * @brief  SPI Init structures definition
  */
typedef struct
{
  uint32_t TransferDirection;       /*!< Specifies the SPI unidirectional or bidirectional data mode.
                                         This parameter can be a value of @ref SPI_LL_EC_TMOD.

                                         This feature can be modified afterwards using unitary function @ref LL_SPI_SetTransferDirection().*/

  uint32_t BaudRate;                /*!< Specifies the BaudRate prescaler value which will be used to configure the transmit and receive SCK clock.
                                         This parameter can be a value of 0 to 0xFF. 0 means disable serial output clock.
                                         @note The communication clock is derived from the master clock (SPI1 and SPI2). The slave clock does not need to be set.

                                         This feature can be modified afterwards using unitary function @ref LL_SPI_SetBaudRatePrescaler().*/

  uint32_t DataWidth;               /*!< Specifies the SPI data width.
                                         This parameter can be a value of @ref SPI_LL_EC_DFS.

                                         This feature can be modified afterwards using unitary function @ref LL_SPI_SetDataWidth().*/

  uint32_t FrameFormat;             /*!< Specifies the frame format.
                                         This parameter can be a value of @ref SPI_LL_EC_PROTOCOL.
                                         
                                         This feature can be modified afterwards using unitary function @ref LL_SPI_SetStandard().*/


  uint32_t ClockPolarity;           /*!< Specifies the serial clock steady state.
                                         This parameter can be a value of @ref SPI_LL_EC_POLARITY.

                                         This feature can be modified afterwards using unitary function @ref LL_SPI_SetClockPolarity().*/

  uint32_t ClockPhase;              /*!< Specifies the clock active edge for the bit capture.
                                         This parameter can be a value of @ref SPI_LL_EC_PHASE.

                                         This feature can be modified afterwards using unitary function @ref LL_SPI_SetClockPhase().*/


  uint32_t CtrlWidth;               /*!< Specifies the SPI control width.
                                         This parameter can be a value of @ref SPI_LL_EC_CFS.

                                         This feature can be modified afterwards using unitary function @ref LL_SPI_SetCtrlWidth().*/

  uint32_t NumDataFrame;            /*!< Specifies the SPI number of dara frames.
                                         This parameter can be a value of 0 to 0xFFFF.

                                         This feature can be modified afterwards using unitary function @ref LL_SPI_SetNumberDataFrame().*/
} LL_SPI_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup SPI_LL_Exported_Constants SPI Exported Constants
  * @{
  */

/** @defgroup SPI_LL_EC_GET_STATUS Get Status Defines
  * @brief    Status defines which can be used with LL_SPI_StatusReg function
  * @{
  */
#define LL_SPI_SR_BUSY                     SPI_SR_BUSY               /*!< SSI busy flag                    */
#define LL_SPI_SR_TFNF                     SPI_SR_TFNF               /*!< Transmit FIFO not full flag      */
#define LL_SPI_SR_TFE                      SPI_SR_TFE                /*!< Transmit FIFO empty flag         */
#define LL_SPI_SR_RFNF                     SPI_SR_RFNE               /*!< Receive FIFO not empty flag      */
#define LL_SPI_SR_RFF                      SPI_SR_RFF                /*!< Receive FIFO full flag           */
#define LL_SPI_SR_TXE                      SPI_SR_TXE                /*!< Transmission error flag          */
#define LL_SPI_SR_DCOL                     SPI_SR_DCOL               /*!< Data collision error flag        */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_SPI_ReadReg and  LL_SPI_WriteReg functions
  * @{
  */
#define LL_SPI_IT_TXE                      SPI_IMR_TXEIM             /*!< TX FIFO Empty interrupt mask           */
#define LL_SPI_IT_TXO                      SPI_IMR_TXOIM             /*!< Tx FIFO Overflow interrupt mask        */
#define LL_SPI_IT_RXU                      SPI_IMR_RXUIM             /*!< RX FIFO Underflow interrupt mask       */
#define LL_SPI_IT_RXO                      SPI_IMR_RXOIM             /*!< RX FIFO OVerflow interrupt mask        */
#define LL_SPI_IT_RXF                      SPI_IMR_RXFIM             /*!< RX FIFO Full interrupt mask            */
#define LL_SPI_IT_MST                      SPI_IMR_MSTIM             /*!< MUlti-Master Contention interrupt mask */
#define LL_SPI_IT_ALL                      (SPI_IMR_TXEIM | SPI_IMR_TXOIM | SPI_IMR_RXUIM | SPI_IMR_RXOIM | SPI_IMR_RXFIM | SPI_IMR_MSTIM)             
/**
  * @}
  */

/** @defgroup SPI_LL_EC_SRLMODE Operation Mode
  * @{
  */
#define LL_SPI_SRLMODE_NORMAL                0x00000000UL                    /*!< normal mode              */
#define LL_SPI_SRLMODE_TEST                  SPI_CTRLR0_SRL                  /*!< Slave in loopback mode   */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_SLVOE slave oupt enable
  * @{
  */
#define LL_SPI_SLVOE_ENABLE                  0x00000000UL                    /*!< Slave txd is enable      */
#define LL_SPI_SLVOE_DISABLE                 SPI_CTRLR0_SLVOE                /*!< Slave txd is disable     */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_TMOD Operation Mode
  * @{
  */
#define LL_SPI_TMOD_TXRX                     (0x00000000UL)                            /*!< Transmit & Receive  */
#define LL_SPI_TMOD_TX                       (SPI_CTRLR0_TMOD_0)                       /*!< Transmit only       */
#define LL_SPI_TMOD_RX                       (SPI_CTRLR0_TMOD_1)                       /*!< Receive only        */
#define LL_SPI_TMOD_EEPROM                   (SPI_CTRLR0_TMOD_1 | SPI_CTRLR0_TMOD_0)   /*!< EEPROM read         */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_PROTOCOL Serial Protocol
  * @{
  */
#define LL_SPI_PROTOCOL_MOTOROLA             (0x00000000UL)                 /*!< Motorola SPI                         */
#define LL_SPI_PROTOCOL_TI                   (SPI_CTRLR0_FRF_0)             /*!< TI SSP                               */
#define LL_SPI_PROTOCOL_NS                   (SPI_CTRLR0_FRF_1)             /*!< National Semiconductors microwire    */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_PHASE Clock Phase
  * @{
  */
#define LL_SPI_PHASE_1EDGE                   0x00000000U               /*!< First clock transition is the first data capture edge  */
#define LL_SPI_PHASE_2EDGE                   (SPI_CTRLR0_SCPH)         /*!< Second clock transition is the first data capture edge */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_POLARITY Clock Polarity
  * @{
  */
#define LL_SPI_POLARITY_LOW                  0x00000000U               /*!< Clock to 0 when idle */
#define LL_SPI_POLARITY_HIGH                 (SPI_CTRLR0_SCPOL)        /*!< Clock to 1 when idle */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_MMD Operation Mode for microwire control
  * @{
  */
#define LL_SPI_MMD_READ                     0x00000000UL                    /*!< received from external serial device */
#define LL_SPI_MMD_WRITE                    SPI_MWCR_MDD                    /*!< send ro external serial device       */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_MWMOD Operation Mode for microwire control
  * @{
  */
#define LL_SPI_MWMODE_NOSEQ                 0x00000000UL                    /*!< non-sequential transfer              */
#define LL_SPI_MWMODE_SEQ                   SPI_MWCR_MHS                    /*!< sequential transfer                  */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_DFS Datawidth
  * @{
  */
#define LL_SPI_DATAWIDTH_4BIT              (SPI_CTRLR0_DFS_1 | SPI_CTRLR0_DFS_0)                                       /*!< Data length for SPI transfer:  4 bits */
#define LL_SPI_DATAWIDTH_5BIT              (SPI_CTRLR0_DFS_2)                                                          /*!< Data length for SPI transfer:  5 bits */
#define LL_SPI_DATAWIDTH_6BIT              (SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_0)                                       /*!< Data length for SPI transfer:  6 bits */
#define LL_SPI_DATAWIDTH_7BIT              (SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_1)                                       /*!< Data length for SPI transfer:  7 bits */
#define LL_SPI_DATAWIDTH_8BIT              (SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_1 | SPI_CTRLR0_DFS_0)                    /*!< Data length for SPI transfer:  8 bits */
#define LL_SPI_DATAWIDTH_9BIT              (SPI_CTRLR0_DFS_3)                                                          /*!< Data length for SPI transfer:  9 bits */
#define LL_SPI_DATAWIDTH_10BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_0)                                       /*!< Data length for SPI transfer: 10 bits */
#define LL_SPI_DATAWIDTH_11BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_1)                                       /*!< Data length for SPI transfer: 11 bits */
#define LL_SPI_DATAWIDTH_12BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_1 | SPI_CTRLR0_DFS_0)                    /*!< Data length for SPI transfer: 12 bits */
#define LL_SPI_DATAWIDTH_13BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_2)                                       /*!< Data length for SPI transfer: 13 bits */
#define LL_SPI_DATAWIDTH_14BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_0)                    /*!< Data length for SPI transfer: 14 bits */
#define LL_SPI_DATAWIDTH_15BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_1)                    /*!< Data length for SPI transfer: 15 bits */
#define LL_SPI_DATAWIDTH_16BIT             (SPI_CTRLR0_DFS_3 | SPI_CTRLR0_DFS_2 | SPI_CTRLR0_DFS_1 | SPI_CTRLR0_DFS_0) /*!< Data length for SPI transfer: 16 bits */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_CFS Control frame size
  * @{
  */
#define LL_SPI_CTRLWIDTH_1BIT              (0x00000000UL)                                                              /*!< Control length for SPI transfer:  1 bits */
#define LL_SPI_CTRLWIDTH_2BIT              (SPI_CTRLR0_CFS_0)                                                          /*!< Control length for SPI transfer:  2 bits */
#define LL_SPI_CTRLWIDTH_3BIT              (SPI_CTRLR0_CFS_1)                                                          /*!< Control length for SPI transfer:  3 bits */
#define LL_SPI_CTRLWIDTH_4BIT              (SPI_CTRLR0_CFS_1 | SPI_CTRLR0_CFS_0)                                       /*!< Control length for SPI transfer:  4 bits */
#define LL_SPI_CTRLWIDTH_5BIT              (SPI_CTRLR0_CFS_2)                                                          /*!< Control length for SPI transfer:  5 bits */
#define LL_SPI_CTRLWIDTH_6BIT              (SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_0)                                       /*!< Control length for SPI transfer:  6 bits */
#define LL_SPI_CTRLWIDTH_7BIT              (SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_1)                                       /*!< Control length for SPI transfer:  7 bits */
#define LL_SPI_CTRLWIDTH_8BIT              (SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_1 | SPI_CTRLR0_CFS_0)                    /*!< Control length for SPI transfer:  8 bits */
#define LL_SPI_CTRLWIDTH_9BIT              (SPI_CTRLR0_CFS_3)                                                          /*!< Control length for SPI transfer:  9 bits */
#define LL_SPI_CTRLWIDTH_10BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_0)                                       /*!< Control length for SPI transfer: 10 bits */
#define LL_SPI_CTRLWIDTH_11BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_1)                                       /*!< Control length for SPI transfer: 11 bits */
#define LL_SPI_CTRLWIDTH_12BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_1 | SPI_CTRLR0_CFS_0)                    /*!< Control length for SPI transfer: 12 bits */
#define LL_SPI_CTRLWIDTH_13BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_2)                                       /*!< Control length for SPI transfer: 13 bits */
#define LL_SPI_CTRLWIDTH_14BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_0)                    /*!< Control length for SPI transfer: 14 bits */
#define LL_SPI_CTRLWIDTH_15BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_1)                    /*!< Control length for SPI transfer: 15 bits */
#define LL_SPI_CTRLWIDTH_16BIT             (SPI_CTRLR0_CFS_3 | SPI_CTRLR0_CFS_2 | SPI_CTRLR0_CFS_1 | SPI_CTRLR0_CFS_0) /*!< Control length for SPI transfer: 16 bits */
/**
  * @}
  */

/** @defgroup SPI_LL_SLAVE_SELECT  
  * @{
  */
#define LL_SPI_SLAVE_SELECT_0              (SPI_SER_SER )               /*!< Salve select 0 */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_RX_FIFO_TH RX FIFO Threshold
  * @{
  */
#define LL_SPI_RX_FIFO_TH_EMPTY            (0x00000000UL)                    /*!< RXF event is generated if FIFO level is greater than or equal to 1 */
#define LL_SPI_RX_FIFO_TH_QUARTER          ((SPI_LL_RX_FIFO_DEPTH-1)>>2)     /*!< RXF event is generated if FIFO level is greater than or equal to 2 */
#define LL_SPI_RX_FIFO_TH_HALF             ((SPI_LL_RX_FIFO_DEPTH-1)>>1)     /*!< RXF event is generated if FIFO level is greater than or equal to 4 */
#define LL_SPI_RX_FIFO_TH_FULL             (SPI_LL_RX_FIFO_DEPTH-1)          /*!< RXF event is generated if FIFO level is greater than or equal to 8 */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_RX_FIFO RX FIFO Level
  * @{
  */
#define LL_SPI_RX_FIFO_EMPTY               (0x00000000U)                     /*!< FIFO reception 0 */
#define LL_SPI_RX_FIFO_QUARTER_FULL        ((SPI_LL_RX_FIFO_DEPTH)>>2)       /*!< FIFO reception 2 */
#define LL_SPI_RX_FIFO_HALF_FULL           ((SPI_LL_RX_FIFO_DEPTH)>>1)       /*!< FIFO reception 4 */
#define LL_SPI_RX_FIFO_FULL                (SPI_LL_RX_FIFO_DEPTH)            /*!< FIFO reception 8 */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_TX_FIFO_TH TX FIFO Threshold
  * @{
  */
#define LL_SPI_TX_FIFO_TH_EMPTY            (0x00000000UL)                    /*!< TXE event is generated if FIFO level is less than or equal to 0 */
#define LL_SPI_TX_FIFO_TH_QUARTER          ((SPI_LL_TX_FIFO_DEPTH-1)>>2)     /*!< TXE event is generated if FIFO level is less than or equal to 1 */
#define LL_SPI_TX_FIFO_TH_HALF             ((SPI_LL_TX_FIFO_DEPTH-1)>>1)     /*!< TXE event is generated if FIFO level is less than or equal to 3 */
#define LL_SPI_TX_FIFO_TH_FULL             (SPI_LL_TX_FIFO_DEPTH-1)          /*!< TXE event is generated if FIFO level is less than or equal to 7 */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_TX_FIFO TX FIFO Level
  * @{
  */
#define LL_SPI_TX_FIFO_EMPTY               (0x00000000U)                     /*!< FIFO transmission 0 */
#define LL_SPI_TX_FIFO_QUARTER_FULL        ((SPI_LL_TX_FIFO_DEPTH)>>2)       /*!< FIFO transmission 2 */
#define LL_SPI_TX_FIFO_HALF_FULL           ((SPI_LL_TX_FIFO_DEPTH)>>1)       /*!< FIFO transmission 4 */
#define LL_SPI_TX_FIFO_FULL                (SPI_LL_TX_FIFO_DEPTH)            /*!< FIFO transmission 8 */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_DMA_RXL DMA RX Data Level
  * @{
  */
//#define LL_SPI_DMA_RXL_EMPTY               0x00000000U                       /*!< DMA trigger by receive FIFO is equal or above empty */
#define LL_SPI_DMA_RXL_QUARTER_FULL        ((SPI_LL_RX_FIFO_DEPTH-1)>>2)     /*!< DMA trigger by receive FIFO is equal or above 1/4   */
#define LL_SPI_DMA_RXL_HALF_FULL           ((SPI_LL_RX_FIFO_DEPTH-1)>>1)     /*!< DMA trigger by receive FIFO is equal or above 1/2   */
#define LL_SPI_DMA_RXL_FULL                (SPI_LL_RX_FIFO_DEPTH-1)          /*!< DMA trigger by receive FIFO is equal or above full  */
/**
  * @}
  */

/** @defgroup SPI_LL_EC_DMA_TXL DMA TX data Level
  * @{
  */
#define LL_SPI_DMA_TXL_EMPTY               0x00000000U                       /*!< DMA trigger by transmit FIFO is equal or below empty */
#define LL_SPI_DMA_TXL_QUARTER_FULL        ((SPI_LL_TX_FIFO_DEPTH-1)>>2)     /*!< DMA trigger by transmit FIFO is equal or below 1/4   */
#define LL_SPI_DMA_TXL_HALF_FULL           ((SPI_LL_TX_FIFO_DEPTH-1)>>1)     /*!< DMA trigger by transmit FIFO is equal or below 1/2   */
//#define LL_SPI_DMA_TXL_FULL                (SPI_LL_TX_FIFO_DEPTH-1)          /*!< DMA trigger by transmit FIFO is equal or below full  */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup SPI_LL_Exported_Macros SPI Exported Macros
  * @{
  */

/** @defgroup SPI_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in SPI register
  * @param  __INSTANCE__ SPI Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_SPI_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in SPI register
  * @param  __INSTANCE__ SPI Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_SPI_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup SPI_LL_EM_Mode check spi mode Macros
  * @{
  */
/** @brief  check SPI master.
  * @param  __INSTANCE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval Status (1 or 0)
  */
#define LL_SPI_IS_MASTER(__INSTANCE__) ((((__INSTANCE__) == SPI1M) || ((__INSTANCE__) == SPI2M)) ? 1UL : 0UL)

/** @brief  check SPI slave.
  * @param  __INSTANCE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval Status (1 or 0)
  */
#define LL_SPI_IS_SLAVE(__INSTANCE__) ((((__INSTANCE__) == SPI1S) || ((__INSTANCE__) == SPI2S)) ? 1UL : 0UL)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup SPI_LL_Exported_Functions SPI Exported Functions
  * @{
  */

/** @defgroup SPI_LL_Exported_Functions_Group1 Configuration
  * @{
  */

/**
  * @brief  Enable SPI peripheral
  * @rmtoll SSIENR          SSI_EN           LL_SPI_Enable
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_Enable(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->SSIENR, SPI_SSIENR_SSIEN);
}

/**
  * @brief  Disable SPI peripheral
  * @note   When disabling the SPI, follow the procedure described in the Reference Manual.
  * @rmtoll SSIENR          SSI_EN           LL_SPI_Disable
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_Disable(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->SSIENR, SPI_SSIENR_SSIEN);
}

/**
  * @brief  Check if SPI peripheral is enabled
  * @rmtoll SSIENR          SSI_EN           LL_SPI_IsEnabled
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsEnabled(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SSIENR, SPI_SSIENR_SSIEN) == (SPI_SSIENR_SSIEN)) ? 1UL : 0UL);
}

/**
  * @brief  Set serial protocol used
  * @note   This bit should be written only when SPI is disabled (SPE = 0) for correct operation.
  * @rmtoll CTRLR0          FRF           LL_SPI_SetStandard
  * @param  SPIx SPI Instance
  * @param  Standard This parameter can be one of the following values:
  *         @arg @ref LL_SPI_PROTOCOL_MOTOROLA
  *         @arg @ref LL_SPI_PROTOCOL_TI
  *         @arg @ref LL_SPI_PROTOCOL_NS
  */
__STATIC_INLINE void LL_SPI_SetStandard(SPI_TypeDef *SPIx, uint32_t Standard)
{
  MODIFY_REG(SPIx->CTRLR0, SPI_CTRLR0_FRF, Standard);
}

/**
  * @brief  Get serial protocol used
  * @rmtoll CTRLR0          FRF           LL_SPI_GetStandard
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SPI_PROTOCOL_MOTOROLA
  *         @arg @ref LL_SPI_PROTOCOL_TI
  *         @arg @ref LL_SPI_PROTOCOL_NS
  */
__STATIC_INLINE uint32_t LL_SPI_GetStandard(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRLR0, SPI_CTRLR0_FRF));
}

/**
  * @brief  Set clock phase
  * @note   This bit should not be changed when communication is ongoing.
  *         This bit is not used in SPI TI mode.
  * @rmtoll CTRLR0          SCPH          LL_SPI_SetClockPhase
  * @param  SPIx SPI Instance
  * @param  ClockPhase This parameter can be one of the following values:
  *         @arg @ref LL_SPI_PHASE_1EDGE
  *         @arg @ref LL_SPI_PHASE_2EDGE
  */
__STATIC_INLINE void LL_SPI_SetClockPhase(SPI_TypeDef *SPIx, uint32_t ClockPhase)
{
  MODIFY_REG(SPIx->CTRLR0, SPI_CTRLR0_SCPH, ClockPhase);
}

/**
  * @brief  Get clock phase
  * @rmtoll CTRLR0          SCPH          LL_SPI_GetClockPhase
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SPI_PHASE_1EDGE
  *         @arg @ref LL_SPI_PHASE_2EDGE
  */
__STATIC_INLINE uint32_t LL_SPI_GetClockPhase(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRLR0, SPI_CTRLR0_SCPH));
}

/**
  * @brief  Set clock polarity
  * @note   This bit should not be changed when communication is ongoing.
  *         This bit is not used in SPI TI mode.
  * @rmtoll CTRLR0          SCPOL          LL_SPI_SetClockPolarity
  * @param  SPIx SPI Instance
  * @param  ClockPolarity This parameter can be one of the following values:
  *         @arg @ref LL_SPI_POLARITY_LOW
  *         @arg @ref LL_SPI_POLARITY_HIGH
  */
__STATIC_INLINE void LL_SPI_SetClockPolarity(SPI_TypeDef *SPIx, uint32_t ClockPolarity)
{
  MODIFY_REG(SPIx->CTRLR0, SPI_CTRLR0_SCPOL, ClockPolarity);
}

/**
  * @brief  Get clock polarity
  * @rmtoll CTRLR0          SCPOL          LL_SPI_GetClockPolarity
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SPI_POLARITY_LOW
  *         @arg @ref LL_SPI_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t LL_SPI_GetClockPolarity(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRLR0, SPI_CTRLR0_SCPOL));
}

/**
  * @brief  Set baud rate prescaler
  * @note   These bits should not be changed when communication is ongoing. SPI BaudRate = fPCLK/Prescaler.
  * @rmtoll BAUDR          SCKDV            LL_SPI_SetBaudRatePrescaler
  * @param  SPIx SPI Instance
  * @param  BaudRate the values is between 2 to 65534
  */
__STATIC_INLINE void LL_SPI_SetBaudRatePrescaler(SPI_TypeDef *SPIx, uint32_t BaudRate)
{
  MODIFY_REG(SPIx->BAUDR, SPI_BAUDR_SCKDV, BaudRate);
}

/**
  * @brief  Get baud rate prescaler
  * @rmtoll BAUDR          SCKDV            LL_SPI_GetBaudRatePrescaler
  * @param  SPIx SPI Instance
  * @retval Returned value can be between 2 to 65534
  */
__STATIC_INLINE uint32_t LL_SPI_GetBaudRatePrescaler(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->BAUDR, SPI_BAUDR_SCKDV));
}

/**
  * @brief  Set transfer direction mode
  * @note   For Half-Duplex mode, Rx Direction is set by default.
  *         In master mode, the MOSI pin is used and in slave mode, the MISO pin is used for Half-Duplex.
  * @rmtoll CTRLR0          TMOD        LL_SPI_SetTransferDirection
  * @param  SPIx SPI Instance
  * @param  TransferDirection This parameter can be one of the following values:
  *         @arg @ref LL_SPI_TMOD_TXRX
  *         @arg @ref LL_SPI_TMOD_TX
  *         @arg @ref LL_SPI_TMOD_RX
  *         @arg @ref LL_SPI_TMOD_EEPROM
  */
__STATIC_INLINE void LL_SPI_SetTransferDirection(SPI_TypeDef *SPIx, uint32_t TransferDirection)
{
  MODIFY_REG(SPIx->CTRLR0, SPI_CTRLR0_TMOD, TransferDirection);
}

/**
  * @brief  Get transfer direction mode
  * @rmtoll CTRLR0          TMOD        LL_SPI_GetTransferDirection
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SPI_TMOD_TXRX
  *         @arg @ref LL_SPI_TMOD_TX
  *         @arg @ref LL_SPI_TMOD_RX
  *         @arg @ref LL_SPI_TMOD_EEPROM
  */
__STATIC_INLINE uint32_t LL_SPI_GetTransferDirection(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRLR0, SPI_CTRLR0_TMOD));
}

/**
  * @brief  Set frame data width
  * @rmtoll CTRLR0          DFS            LL_SPI_SetDataWidth
  * @param  SPIx SPI Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref LL_SPI_DATAWIDTH_4BIT
  *         @arg @ref LL_SPI_DATAWIDTH_5BIT
  *         @arg @ref LL_SPI_DATAWIDTH_6BIT
  *         @arg @ref LL_SPI_DATAWIDTH_7BIT
  *         @arg @ref LL_SPI_DATAWIDTH_8BIT
  *         @arg @ref LL_SPI_DATAWIDTH_9BIT
  *         @arg @ref LL_SPI_DATAWIDTH_10BIT
  *         @arg @ref LL_SPI_DATAWIDTH_11BIT
  *         @arg @ref LL_SPI_DATAWIDTH_12BIT
  *         @arg @ref LL_SPI_DATAWIDTH_13BIT
  *         @arg @ref LL_SPI_DATAWIDTH_14BIT
  *         @arg @ref LL_SPI_DATAWIDTH_15BIT
  *         @arg @ref LL_SPI_DATAWIDTH_16BIT
  */
__STATIC_INLINE void LL_SPI_SetDataWidth(SPI_TypeDef *SPIx, uint32_t DataWidth)
{
  MODIFY_REG(SPIx->CTRLR0, SPI_CTRLR0_DFS, DataWidth);
}

/**
  * @brief  Get frame data width
  * @rmtoll CTRLR0          DFS            LL_SPI_GetDataWidth
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SPI_DATAWIDTH_4BIT
  *         @arg @ref LL_SPI_DATAWIDTH_5BIT
  *         @arg @ref LL_SPI_DATAWIDTH_6BIT
  *         @arg @ref LL_SPI_DATAWIDTH_7BIT
  *         @arg @ref LL_SPI_DATAWIDTH_8BIT
  *         @arg @ref LL_SPI_DATAWIDTH_9BIT
  *         @arg @ref LL_SPI_DATAWIDTH_10BIT
  *         @arg @ref LL_SPI_DATAWIDTH_11BIT
  *         @arg @ref LL_SPI_DATAWIDTH_12BIT
  *         @arg @ref LL_SPI_DATAWIDTH_13BIT
  *         @arg @ref LL_SPI_DATAWIDTH_14BIT
  *         @arg @ref LL_SPI_DATAWIDTH_15BIT
  *         @arg @ref LL_SPI_DATAWIDTH_16BIT
  */
__STATIC_INLINE uint32_t LL_SPI_GetDataWidth(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRLR0, SPI_CTRLR0_DFS));
}

/**
  * @brief  Set control frame data width
  * @rmtoll CTRLR0          CFS            LL_SPI_SetCtrlWidth
  * @param  SPIx SPI Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref LL_SPI_CTRLWIDTH_1BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_2BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_3BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_4BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_5BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_6BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_7BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_8BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_9BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_10BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_11BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_12BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_13BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_14BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_15BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_16BIT
  */
__STATIC_INLINE void LL_SPI_SetCtrlWidth(SPI_TypeDef *SPIx, uint32_t DataWidth)
{
  MODIFY_REG(SPIx->CTRLR0, SPI_CTRLR0_CFS, DataWidth);
}

/**
  * @brief  Get control frame data width
  * @rmtoll CTRL2          CFS            LL_SPI_GetCtrlWidth
  * @param  SPIx SPI Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_SPI_CTRLWIDTH_1BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_2BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_3BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_4BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_5BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_6BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_7BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_8BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_9BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_10BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_11BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_12BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_13BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_14BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_15BIT
  *         @arg @ref LL_SPI_CTRLWIDTH_16BIT
  */
__STATIC_INLINE uint32_t LL_SPI_GetCtrlWidth(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_BIT(SPIx->CTRLR0, SPI_CTRLR0_CFS));
}

/**
  * @brief  Set number of data frames 
  * @rmtoll CTRLR1          NDF            LL_SPI_SetNumberDataFrame
  * @param  SPIx SPI Instance
  * @param  Frames This parameter can be 0 to 0xFFFF
  */
__STATIC_INLINE void LL_SPI_SetNumberDataFrame(SPI_TypeDef *SPIx, uint32_t Frames)
{
  WRITE_REG(SPIx->CTRLR1, Frames);
}

/**
  * @brief  Get number of data frames 
  * @rmtoll CTRLR1          NDF            LL_SPI_GetNumberDataFrame
  * @param  SPIx SPI Instance
  * @retval  The value can be 0 to 0xFFFF
  */
__STATIC_INLINE uint32_t LL_SPI_GetNumberDataFrame(SPI_TypeDef *SPIx)
{
  return READ_REG(SPIx->CTRLR1);
}

/**
  * @brief  Set threshold of RXFIFO that triggers an RXNE event
  * @rmtoll RXFTLR          RFT         LL_SPI_SetRxFIFOThreshold
  * @param  SPIx SPI Instance
  * @param  Threshold This parameter can be 0 to SPI_LL_RX_FIFO_DEPTH
  */
__STATIC_INLINE void LL_SPI_SetRxFIFOThreshold(SPI_TypeDef *SPIx, uint32_t Threshold)
{
  WRITE_REG(SPIx->RXFTLR, Threshold);
}

/**
  * @brief  Get threshold of RXFIFO that triggers an RXNE event
  * @rmtoll RXFTLR          RFT         LL_SPI_GetRxFIFOThreshold
  * @param  SPIx SPI Instance
  * @retval Returned value can be 0 to SPI_LL_RX_FIFO_DEPTH;
  */
__STATIC_INLINE uint32_t LL_SPI_GetRxFIFOThreshold(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->RXFTLR));
}

/**
  * @brief  Set threshold of TXFIFO that triggers an RXNE event
  * @rmtoll TXFTLR          TFT         LL_SPI_SetTxFIFOThreshold
  * @param  SPIx SPI Instance
  * @param  Threshold This parameter can be 0 to SPI_LL_TX_FIFO_DEPTH
  */
__STATIC_INLINE void LL_SPI_SetTxFIFOThreshold(SPI_TypeDef *SPIx, uint32_t Threshold)
{
  WRITE_REG(SPIx->TXFTLR, Threshold);
}

/**
  * @brief  Get threshold of TXFIFO that triggers an RXNE event
  * @rmtoll TXFTLR          TFT         LL_SPI_GetTxFIFOThreshold
  * @param  SPIx SPI Instance
  * @retval Returned value can be 0 to SPI_LL_TX_FIFO_DEPTH;
  */
__STATIC_INLINE uint32_t LL_SPI_GetTxFIFOThreshold(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->TXFTLR));
}

/**
  * @brief  Set microwire control direction
  * @rmtoll MWCR          MDD         LL_SPI_SetMicrowireDirection
  * @param  SPIx SPI Instance
  * @param  Dir This parameter can be one of the following values:
  *         @arg @ref LL_SPI_MMD_READ
  *         @arg @ref LL_SPI_MMD_WRITE
  */
__STATIC_INLINE void LL_SPI_SetMicrowireDirection(SPI_TypeDef *SPIx, uint32_t Dir)
{
  MODIFY_REG(SPIx->MWCR, SPI_MWCR_MDD, Dir);
}

/**
  * @brief  Get microwire control direction
  * @rmtoll MWCR          MDD         LL_SPI_GetMicrowireDirection
  * @param  SPIx SPI Instance
  * @retval Returned value can be be one of the following values:
  *         @arg @ref LL_SPI_MMD_READ
  *         @arg @ref LL_SPI_MMD_WRITE
  */
__STATIC_INLINE uint32_t LL_SPI_GetMicrowireDirection(SPI_TypeDef *SPIx)
{
  return (READ_BIT(SPIx->MWCR, SPI_MWCR_MDD));
}

/**
  * @brief  Set microwire transfer mode
  * @rmtoll MWCR          MDD         LL_SPI_SetMicrowireTxMode
  * @param  SPIx SPI Instance
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_SPI_MWMODE_NOSEQ
  *         @arg @ref LL_SPI_MWMODE_SEQ
 */
__STATIC_INLINE void LL_SPI_SetMicrowireTxMode(SPI_TypeDef *SPIx, uint32_t Mode)
{
  MODIFY_REG(SPIx->MWCR, SPI_MWCR_MWMOD, Mode);
}

/**
  * @brief  Get microwire control direction
  * @rmtoll MWCR          MDD         LL_SPI_GetMicrowireTxMode
  * @param  SPIx SPI Instance
  * @retval Returned value can be be one of the following values:
  *         @arg @ref LL_SPI_MWMODE_NOSEQ
  *         @arg @ref LL_SPI_MWMODE_SEQ
  */
__STATIC_INLINE uint32_t LL_SPI_GetMicrowireTxMode(SPI_TypeDef *SPIx)
{
  return (READ_BIT(SPIx->MWCR, SPI_MWCR_MWMOD));
}

/**
  * @brief  Enable microwire handshaking
  * @rmtoll MWCR          MDD         LL_SPI_EnableMicrowireHS
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_EnableMicrowireHS(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->MWCR, SPI_MWCR_MHS);
}

/**
  * @brief  Disable microwire handshaking
  * @rmtoll MWCR          MDD         LL_SPI_DisableMicrowireHS
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_DisableMicrowireHS(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->MWCR, SPI_MWCR_MHS);
}

/**
  * @brief  Check if microwire handshaking is enabled 
  * @rmtoll MWCR          MDD         LL_SPI_IsEnabledMicrowireHS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsEnabledMicrowireHS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->MWCR, SPI_MWCR_MHS) == SPI_MWCR_MHS) ? 1 : 0);
}
/**
  * @}
  */

/** @defgroup SPI_LL_Exported_Functions_Group2 Slave Select Pin Management
  * @{
  */

/**
  * @brief  Set Salve select enable
  * @rmtoll SER          SS           LL_SPI_SetSlaveEnable
  * @param  SPIx SPI Instance
  * @param  NSS This parameter can be one of the following values:
  *         @arg @ref LL_SPI_SLAVE_SELECT_0
  */
__STATIC_INLINE void LL_SPI_SetSlaveEnable(SPI_TypeDef *SPIx, uint32_t NSS)
{
  SET_BIT(SPIx->SER, NSS);
}

/**
  * @brief  Clear Salve select enable
  * @rmtoll SER          SS           LL_SPI_ClearSlaveEnable
  * @param  SPIx SPI Instance
  * @param  NSS This parameter can be one of the following values:
  *         @arg @ref LL_SPI_SLAVE_SELECT_0
  */
__STATIC_INLINE void LL_SPI_ClearSlaveEnable(SPI_TypeDef *SPIx, uint32_t NSS)
{
  CLEAR_BIT(SPIx->SER, NSS);
}
/**
  * @}
  */

/** @defgroup SPI_LL_Exported_Functions_Group3 FLAG Management
  * @{
  */
/**
  * @brief  Get data collision error flag
  * @rmtoll SR           DCOL           LL_SPI_IsStatus_DCOL
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsStatus_DCOL(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_DCOL) == (SPI_SR_DCOL)) ? 1UL : 0UL);
}

/**
  * @brief  Get transmission error flag
  * @rmtoll SR           TXE        LL_SPI_IsStatus_TXE
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsStatus_TXE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_TXE) == (SPI_SR_TXE)) ? 1UL : 0UL);
}

/**
  * @brief  Getreceive FIFO full flag
  * @rmtoll SR           RFF          LL_SPI_IsStatus_RFF
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsStatus_RFF(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_RFF) == (SPI_SR_RFF)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Rx buffer is not empty
  * @rmtoll SR           RFNE          LL_SPI_IsStatus_RFNE
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsStatus_RFNE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_RFNE) == (SPI_SR_RFNE)) ? 1UL : 0UL);
}

/**
  * @brief  Check if Tx buffer is empty
  * @rmtoll SR           TFE           LL_SPI_IsStatus_TFE
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsStatus_TFE(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_TFE) == (SPI_SR_TFE)) ? 1UL : 0UL);
}

/**
  * @brief  Get transmit FIFO not full flag
  * @rmtoll SR           TFNF           LL_SPI_IsStatus_TFNF
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsStatus_TFNF(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_TFNF) == (SPI_SR_TFNF)) ? 1UL : 0UL);
}

/**
  * @brief  Get busy flag
  * @rmtoll SR           BUSY           LL_SPI_IsStatus_BUSY
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsStatus_BUSY(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->SR, SPI_SR_BUSY) == (SPI_SR_BUSY)) ? 1UL : 0UL);
}

/**
  * @brief  Get FIFO reception Level
  * @rmtoll RXFLR           RXTFL         LL_SPI_GetRxFIFOLevel
  * @param  SPIx SPI Instance
  * @retval Returned value can be 0 to SPI_LL_RX_FIFO_DEPTH
  */
__STATIC_INLINE uint32_t LL_SPI_GetRxFIFOLevel(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->RXFLR));
}

/**
  * @brief  Get FIFO Transmission Level
  * @rmtoll TXFLR           TXTFL         LL_SPI_GetTxFIFOLevel
  * @param  SPIx SPI Instance
  * @retval Returned value can be 0 to SPI_LL_TX_FIFO_DEPTH
  */
__STATIC_INLINE uint32_t LL_SPI_GetTxFIFOLevel(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->TXFLR));
}

/**
  * @brief  Get transmit FIFO empty interrupt status
  * @rmtoll ISR           TXEIS           LL_SPI_IsIT_TXEIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsIT_TXEIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->ISR, SPI_ISR_TXEIS) == (SPI_ISR_TXEIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get transmit FIFO overflow interrupt status
  * @rmtoll ISR           TXEIS           LL_SPI_IsIT_TXOIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsIT_TXOIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->ISR, SPI_ISR_TXOIS) == (SPI_ISR_TXOIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get receive FIFO underflow interrupt status
  * @rmtoll ISR           TXEIS           LL_SPI_IsIT_RXUIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsIT_RXUIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->ISR, SPI_ISR_RXUIS) == (SPI_ISR_RXUIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get receive FIFO overflow interrupt status
  * @rmtoll ISR           TXEIS           LL_SPI_IsIT_RXOIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsIT_RXOIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->ISR, SPI_ISR_RXOIS) == (SPI_ISR_RXOIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get receive FIFO full interrupt status
  * @rmtoll ISR           TXEIS           LL_SPI_IsIT_RXFIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsIT_RXFIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->ISR, SPI_ISR_RXFIS) == (SPI_ISR_RXFIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get Multi-master contention  interrupt status
  * @rmtoll ISR           TXEIS           LL_SPI_IsIT_MSTIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsIT_MSTIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->ISR, SPI_ISR_MSTIS) == (SPI_ISR_MSTIS)) ? 1UL : 0UL);
}

/**
  * @brief  Clear transmit FIFO overflow interrupt 
  * @rmtoll TXOICR           CRCERR        LL_SPI_ClearIT_TXOICR
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_ClearIT_TXOCR(SPI_TypeDef *SPIx)
{
  READ_BIT(SPIx->TXOICR, SPI_TXOICR_TXOICR);
}

/**
  * @brief  Clear receive FIFO overflow interrupt
  * @rmtoll RXOICR           RXOICR          LL_SPI_ClearIT_RXOICR
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_ClearIT_RXOICR(SPI_TypeDef *SPIx)
{
 READ_BIT(SPIx->RXOICR, SPI_RXOICR_RXOICR);
}

/**
  * @brief  Clear receive FIFO underflow interrupt
  * @rmtoll RXUICR           RXUICR           LL_SPI_ClearIT_RXUICR
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_ClearIT_RXUICR(SPI_TypeDef *SPIx)
{
 READ_BIT(SPIx->RXUICR, SPI_RXUICR_RXUICR);
}

/**
  * @brief  Clear multi-master contention interrupt
  * @rmtoll MSTICR           MSTICR           LL_SPI_ClearIF_MSTICR
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_ClearIF_MSTICR(SPI_TypeDef *SPIx)
{
 READ_BIT(SPIx->MSTICR, SPI_MSTICR_MSTICR);
}

/**
  * @brief  Clear all interrupts
  * @rmtoll ICR           ICR           LL_SPI_ClearIF_ICR
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_ClearIF_ICR(SPI_TypeDef *SPIx)
{
 READ_BIT(SPIx->ICR, SPI_ICR_ICR);
}

/**
  * @brief  Get transmit FIFO empty interrupt status
  * @rmtoll RISR           TXEIS           LL_SPI_IsFlag_TXEIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsFlag_TXEIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->RISR, SPI_ISR_TXEIS) == (SPI_ISR_TXEIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get transmit FIFO overflow interrupt status
  * @rmtoll RISR           TXEIS           LL_SPI_IsFlag_TXOIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsFlag_TXOIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->RISR, SPI_ISR_TXOIS) == (SPI_ISR_TXOIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get receive FIFO underflow interrupt status
  * @rmtoll RISR           TXEIS           LL_SPI_IsFlag_RXUIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsFlag_RXUIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->RISR, SPI_ISR_RXUIS) == (SPI_ISR_RXUIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get receive FIFO overflow interrupt status
  * @rmtoll RISR           TXEIS           LL_SPI_IsFlag_RXOIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsFlag_RXOIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->RISR, SPI_ISR_RXOIS) == (SPI_ISR_RXOIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get receive FIFO full interrupt status
  * @rmtoll RISR           TXEIS           LL_SPI_IsFlag_RXFIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsFlag_RXFIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->RISR, SPI_ISR_RXFIS) == (SPI_ISR_RXFIS)) ? 1UL : 0UL);
}

/**
  * @brief  Get Multi-master contention  interrupt status
  * @rmtoll RISR           TXEIS           LL_SPI_IsFlag_MSTIS
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsFlag_MSTIS(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->RISR, SPI_ISR_MSTIS) == (SPI_ISR_MSTIS)) ? 1UL : 0UL);
}


/**
  * @}
  */

/** @defgroup SPI_LL_Exported_Functions_Group4 Interrupt Management
  * @{
  */

/**
  * @brief  Mask transmit FIFO empty interrupt
  * @rmtoll IMR          TXEIM         LL_SPI_MaskIT_TXEIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_MaskIT_TXEIM(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->IMR, SPI_IMR_TXEIM);
}

/**
  * @brief  Mask transmit FIFO overflow interrupt
  * @rmtoll IMR          TXOIM         LL_SPI_MaskIT_TXOIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_MaskIT_TXOIM(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->IMR, SPI_IMR_TXOIM);
}

/**
  * @brief  Mask receive FIFO underflow interrupt
  * @rmtoll IMR          RXUIM         LL_SPI_MaskIT_RXUIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_MaskIT_RXUIM(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->IMR, SPI_IMR_RXUIM);
}

/**
  * @brief  Mask receiv FIFO overflow interrupt
  * @rmtoll IMR          RXOIM         LL_SPI_MaskITRXOIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_MaskKIT_RXOIM(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->IMR, SPI_IMR_RXOIM);
}

/**
  * @brief  Mask receive FIFO full interrupt
  * @rmtoll IMR          RXFIM         LL_SPI_MaskIT_RXFIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_MaskIT_RXFIM(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->IMR, SPI_IMR_RXFIM);
}

/**
  * @brief  Mask multi-master contention interrupt
  * @rmtoll IMR          MSTIM         LL_SPI_MaskIT_MSTIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_MaskIT_MSTIM(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->IMR, SPI_IMR_MSTIM);
}

/**
  * @brief  Unmask transmit FIFO empty interrupt
  * @rmtoll IMR          TXEIM         LL_SPI_UnmaskIT_TXEIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_UnmaskIT_TXEIM(SPI_TypeDef *SPIx)
{
 SET_BIT(SPIx->IMR, SPI_IMR_TXEIM);
}

/**
  * @brief  Unmask transmit FIFO overflow interrupt
  * @rmtoll IMR          TXOIM         LL_SPI_UnmaskIT_TXOIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_UnmaskIT_TXOIM(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->IMR, SPI_IMR_TXOIM);
}

/**
  * @brief  Unmask receive FIFO underflow interrupt
  * @rmtoll IMR          RXUIM         LL_SPI_UnmaskIT_RXUIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_UnmaskIT_RXUIM(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->IMR, SPI_IMR_RXUIM);
}

/**
  * @brief  Unmask receive FIFO overflow interrupt
  * @rmtoll IMR          RXOIM         LL_SPI_UnmaskIT_RXOIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_UnmaskIT_RXOIM(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->IMR, SPI_IMR_RXOIM);
}

/**
  * @brief  Unmask receive FIFO full interrupt
  * @rmtoll IMR          RXFIM         LL_SPI_UnmaskIT_RXFIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_UnmaskIT_RXFIM(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->IMR, SPI_IMR_RXFIM);
}

/**
  * @brief  Unmask multi-master contention interrupt
  * @rmtoll IMR          MSTIM         LL_SPI_UnmaskIT_MSTIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_UnmaskIT_MSTIM(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->IMR, SPI_IMR_MSTIM);
}

/**
  * @brief  Check unmasked transmit FIFO empty interrupt
  * @rmtoll IMR          TXEIM         LL_SPI_IsUnmaskedIT_TXEIM
  * @param  SPIx SPI Instance
  * @retval status (1 or 0)
  */
__STATIC_INLINE uint32_t LL_SPI_IsUnmaskedIT_TXEIM(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->IMR, SPI_IMR_TXEIM) == (SPI_IMR_TXEIM)) ? 1UL : 0UL);
}

/**
  * @brief  Check unmasked transmit FIFO overflow interrupt
  * @rmtoll IMR          TXOIM         LL_SPI_IsUnmaskedIT_TXOIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE uint32_t LL_SPI_IsUnmaskedIT_TXOIM(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->IMR, SPI_IMR_TXOIM) == (SPI_IMR_TXOIM)) ? 1UL : 0UL);
}

/**
  * @brief  Chec unmask receive FIFO underflow interrupt
  * @rmtoll IMR          RXUIM         LL_SPI_IsUnmaskedIT_RXUIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE uint32_t LL_SPI_IsUnmaskedIT_RXUIM(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->IMR, SPI_IMR_RXUIM) == (SPI_IMR_RXUIM)) ? 1UL : 0UL);
}

/**
  * @brief  Check unmask receiv FIFO overflow interrupt
  * @rmtoll IMR          RXOIM         LL_SPI_IsUnmaskedIT_RXOIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE uint32_t LL_SPI_IsUnmaskedIT_RXOIM(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->IMR, SPI_IMR_RXOIM) == (SPI_IMR_RXOIM)) ? 1UL : 0UL);
}

/**
  * @brief  Check unmask receive FIFO full interrupt
  * @rmtoll IMR          RXFIM         LL_SPI_IsUnmaskedIT_RXFIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE uint32_t LL_SPI_IsUnmaskedIT_RXFIM(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->IMR, SPI_IMR_RXFIM) == (SPI_IMR_RXFIM)) ? 1UL : 0UL);
}

/**
  * @brief  Check unmask multi-master contention interrupt
  * @rmtoll IMR          MSTIM         LL_SPI_IsUnmaskedIT_MSTIM
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE uint32_t LL_SPI_IsUnmaskedIT_MSTIM(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->IMR, SPI_IMR_MSTIM) == (SPI_IMR_MSTIM)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup SPI_LL_Exported_Functions_Group5 DMA Management
  * @{
  */

/**
  * @brief  Enable DMA Rx
  * @rmtoll DMACR          RDMAE       LL_SPI_EnableDMA_RX
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_EnableDMA_RX(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->DMACR, SPI_DMACR_RDMAE);
}

/**
  * @brief  Disable DMA Rx
  * @rmtoll DMACR          RDMAE       LL_SPI_DisableDMA_RX
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_DisableDMA_RX(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->DMACR, SPI_DMACR_RDMAE);
}

/**
  * @brief  Check if DMA Rx is enabled
  * @rmtoll DMACR          RDMAE       LL_SPI_IsEnabledDMA_RX
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsEnabledDMA_RX(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->DMACR, SPI_DMACR_RDMAE) == (SPI_DMACR_RDMAE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable DMA Tx
  * @rmtoll DMACR          TDMAE       LL_SPI_EnableDMA_TX
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_EnableDMA_TX(SPI_TypeDef *SPIx)
{
  SET_BIT(SPIx->DMACR, SPI_DMACR_TDMAE);
}

/**
  * @brief  Disable DMA Tx
  * @rmtoll DMACR          TDMAE       LL_SPI_DisableDMA_TX
  * @param  SPIx SPI Instance
  */
__STATIC_INLINE void LL_SPI_DisableDMAReq_TX(SPI_TypeDef *SPIx)
{
  CLEAR_BIT(SPIx->DMACR, SPI_DMACR_TDMAE);
}

/**
  * @brief  Check if DMA Tx is enabled
  * @rmtoll DMACR          TXDMAEN       LL_SPI_IsEnabledDMA_TX
  * @param  SPIx SPI Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_SPI_IsEnabledDMA_TX(SPI_TypeDef *SPIx)
{
  return ((READ_BIT(SPIx->DMACR, SPI_DMACR_TDMAE) == (SPI_DMACR_TDMAE)) ? 1UL : 0UL);
}

/**
  * @brief  Set DMA transmit level
  * @rmtoll DMATDLR          DMATDL        LL_SPI_SetDMADataLevel_Tx
  * @param  SPIx SPI Instance
  * @param  Level This parameter can be 0 to 0xFF
  */
__STATIC_INLINE void LL_SPI_SetDMADataLevel_Tx(SPI_TypeDef *SPIx, uint32_t Level)
{
  WRITE_REG(SPIx->DMATDLR, Level);
}

/**
  * @brief  Get DMA transmit level
  * @rmtoll DMATDLR          DMATDL        LL_SPI_GetDMADataLevel_Tx
  * @param  SPIx SPI Instance
  * @retval Returned value can be 0 to 0xFF
  */
__STATIC_INLINE uint32_t LL_SPI_GetDMADataLevel_Tx(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->DMATDLR));
}

/**
  * @brief  Set DMA receive level
  * @rmtoll DMARDLR          DMARDL        LL_SPI_SetDMADataLevel_Rx
  * @param  SPIx SPI Instance
  * @param  Level This parameter can be 0 to 0xFF
  */
__STATIC_INLINE void LL_SPI_SetDMADataLevel_Rx(SPI_TypeDef *SPIx, uint32_t Level)
{
  WRITE_REG(SPIx->DMARDLR, Level);
}

/**
  * @brief  Get DMA receive level
  * @rmtoll DMARDLR          DMARDL        LL_SPI_GetDMADataLevel_Rx
  * @param  SPIx SPI Instance
  * @retval Returned value can be 0 to 0xFF
  */
__STATIC_INLINE uint32_t LL_SPI_GetDMADataLevel_Rx(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->DMARDLR));
}

/**
  * @brief  Get the data register address used for DMA transfer
  * @rmtoll DR         DR        LL_SPI_DMA_GetRegAddr
  * @param  SPIx SPI Instance
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t LL_SPI_DMA_GetRegAddr(SPI_TypeDef *SPIx)
{
  return (uint32_t) (&(SPIx->DR));
}

#if 0
/**
  * @brief  Get ID
  * @rmtoll IDR          IDCODE        LL_SPI_GetDMAID
  * @param  SPIx SPI Instance
  * @retval Returned value can be 0 to 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_SPI_GetID(SPI_TypeDef *SPIx)
{
  return (uint32_t)(READ_REG(SPIx->IDR));
}
#endif
/**
  * @}
  */

/** @defgroup SPI_LL_Exported_Functions_Group6 DATA Management
  * @{
  */

/**
  * @brief  Read 8-Bits in the data register
  * @rmtoll DR           DR            LL_SPI_ReceiveData8
  * @param  SPIx SPI Instance
  * @retval RxData Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t LL_SPI_ReceiveData8(SPI_TypeDef *SPIx)
{
  return (*((__IO uint8_t *)(SPIx->DR)));
}

/**
  * @brief  Read 16-Bits in the data register
  * @rmtoll DR           DR            LL_SPI_ReceiveData16
  * @param  SPIx SPI Instance
  * @retval RxData Value between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint16_t LL_SPI_ReceiveData16(SPI_TypeDef *SPIx)
{
  return (uint16_t)(READ_REG(SPIx->DR));
}

/**
  * @brief  Write 8-Bits in the data register
  * @rmtoll DR           DR            LL_SPI_TransmitData8
  * @param  SPIx SPI Instance
  * @param  TxData Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE void LL_SPI_TransmitData8(SPI_TypeDef *SPIx, uint8_t TxData)
{
#if defined (__GNUC__)
  __IO uint8_t *spidr = ((__IO uint8_t *)&SPIx->DR);
  *spidr = TxData;
#else
  *((__IO uint8_t *)(SPIx->DR)) = TxData;
#endif /* __GNUC__ */
}

/**
  * @brief  Write 16-Bits in the data register
  * @rmtoll DR           DR            LL_SPI_TransmitData16
  * @param  SPIx SPI Instance
  * @param  TxData Value between Min_Data=0x00 and Max_Data=0xFFFF
  */
__STATIC_INLINE void LL_SPI_TransmitData16(SPI_TypeDef *SPIx, uint16_t TxData)
{
#if defined (__GNUC__)
  __IO uint16_t *spidr = ((__IO uint16_t *)&SPIx->DR);
  *spidr = TxData;
#else
  SPIx->DR = TxData;
#endif /* __GNUC__ */
}

/**
  * @}
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup SPI_LL_Exported_Functions_Group7 Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_SPI_DeInit(SPI_TypeDef *SPIx);
ErrorStatus LL_SPI_Init(SPI_TypeDef *SPIx, LL_SPI_InitTypeDef *SPI_InitStruct);
void        LL_SPI_StructInit(LL_SPI_InitTypeDef *SPI_InitStruct);

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

#endif /* defined (SPI1M) || defined (SPI1S) || defined (SPI2M) || defined (SPI2S) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_SPI_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
