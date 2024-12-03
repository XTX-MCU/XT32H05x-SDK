/**
  ******************************************************************************
  * @file    xt32h0xx_hal_spi.h
  * @author  Software Team
  * @brief   Header file of SPI HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_SPI_H
#define XT32H0xx_HAL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"
#include "xt32h0xx_ll_spi.h"

/** @addtogroup XT32H0xx_HAL_Driver
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
  * @brief  SPI Configuration Structure definition
  */
typedef struct
{
  uint32_t BaudRate;             /*!< Specifies the Baud Rate prescaler value which will be
                                     used to configure the transmit and receive SCK clock.
                                     This parameter can be a value of 2 to 65534
                                     @note The communication clock is derived from the master
                                     clock. The slave clock does not need to be set. */

  uint32_t Direction;           /*!< Specifies the SPI bidirectional mode state.
                                     This parameter can be a value of @ref SPI_Direction */

  uint32_t DataSize;            /*!< Specifies the SPI data size.
                                     This parameter can be a value of @ref SPI_Data_Size */

  uint32_t Standard;              /*!< Specifies if the Motorola/TI/NS mode is enabled or not.
                                     This parameter can be a value of @ref SPI_Protocol */

  uint32_t ClockPolarity;         /*!< Specifies the serial clock steady state.
                                     This parameter can be a value of @ref SPI_Clock_Polarity */

  uint32_t ClockPhase;            /*!< Specifies the clock active edge for the bit capture.
                                     This parameter can be a value of @ref SPI_Clock_Phase */

  uint32_t ControlSize;           /*!< Specifies if the control data size
                                     This parameter can be a value of 0-15 */

  uint32_t NumberDataFrame;       /*!< Specifies if the number of data frame received continuously.
                                     This parameter can be a value of 0-65535 */

  uint32_t TxFIFOTLvl;            /*!< Specifies if the transmission FIFO threshold level register.
                                     This parameter can be a value of 0 - Tx fifo depth */

  uint32_t RxFIFOTLvl;            /*!< Specifies if the receive FIFO threshold level register.
                                     This parameter can be a value of 0 - Rx fifo depth */

//  uint32_t ITMask;                /*!< Specifies if the interupt mask.
//                                     This parameter can be a value @ref SPI_Flags_definition */
} SPI_InitTypeDef;

/**
  * @brief  HAL SPI State structure definition
  */
typedef enum
{
  HAL_SPI_STATE_RESET      = 0x00U,    /*!< Peripheral not Initialized                         */
  HAL_SPI_STATE_READY      = 0x01U,    /*!< Peripheral Initialized and ready for use           */
  HAL_SPI_STATE_BUSY       = 0x02U,    /*!< an internal process is ongoing                     */
  HAL_SPI_STATE_BUSY_TX    = 0x03U,    /*!< Data Transmission process is ongoing               */
  HAL_SPI_STATE_BUSY_RX    = 0x04U,    /*!< Data Reception process is ongoing                  */
  HAL_SPI_STATE_BUSY_TX_RX = 0x05U,    /*!< Data Transmission and Reception process is ongoing */
  HAL_SPI_STATE_ERROR      = 0x06U,    /*!< SPI error state                                    */
  HAL_SPI_STATE_ABORT      = 0x07U     /*!< SPI abort is ongoing                               */
} HAL_SPI_StateTypeDef;

/**
  * @brief  SPI handle Structure definition
  */
typedef struct __SPI_HandleTypeDef
{
  SPI_TypeDef                *Instance;      /*!< SPI registers base address               */

  SPI_InitTypeDef            Init;           /*!< SPI communication parameters             */

  //uint32_t                   Mode;           /*!< SPI mode                                 */

  uint8_t                    *pTxBuffPtr;    /*!< Pointer to SPI Tx transfer Buffer        */

  uint16_t                   TxXferSize;     /*!< SPI Tx Transfer size                     */

  __IO uint16_t              TxXferCount;    /*!< SPI Tx Transfer Counter                  */

  uint8_t                    *pRxBuffPtr;    /*!< Pointer to SPI Rx transfer Buffer        */

  uint16_t                   RxXferSize;     /*!< SPI Rx Transfer size                     */

  __IO uint16_t              RxXferCount;    /*!< SPI Rx Transfer Counter                  */

  void (*RxISR)(struct __SPI_HandleTypeDef *hspi);   /*!< function pointer on Rx ISR       */

  void (*TxISR)(struct __SPI_HandleTypeDef *hspi);   /*!< function pointer on Tx ISR       */

  DMA_HandleTypeDef          *hdmatx;        /*!< SPI Tx DMA Handle parameters             */

  DMA_HandleTypeDef          *hdmarx;        /*!< SPI Rx DMA Handle parameters             */

  HAL_LockTypeDef            Lock;           /*!< Locking object                           */

  __IO HAL_SPI_StateTypeDef  State;          /*!< SPI communication state                  */

  __IO uint32_t              ErrorCode;      /*!< SPI Error code                           */

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  void (* TxCpltCallback)(struct __SPI_HandleTypeDef *hspi);             /*!< SPI Tx Completed callback          */
  void (* RxCpltCallback)(struct __SPI_HandleTypeDef *hspi);             /*!< SPI Rx Completed callback          */
  void (* TxRxCpltCallback)(struct __SPI_HandleTypeDef *hspi);           /*!< SPI TxRx Completed callback        */
//  void (* TxHalfCpltCallback)(struct __SPI_HandleTypeDef *hspi);         /*!< SPI Tx Half Completed callback     */
//  void (* RxHalfCpltCallback)(struct __SPI_HandleTypeDef *hspi);         /*!< SPI Rx Half Completed callback     */
//  void (* TxRxHalfCpltCallback)(struct __SPI_HandleTypeDef *hspi);       /*!< SPI TxRx Half Completed callback   */
  void (* ErrorCallback)(struct __SPI_HandleTypeDef *hspi);              /*!< SPI Error callback                 */
  void (* AbortCpltCallback)(struct __SPI_HandleTypeDef *hspi);          /*!< SPI Abort callback                 */
  void (* MspInitCallback)(struct __SPI_HandleTypeDef *hspi);            /*!< SPI Msp Init callback              */
  void (* MspDeInitCallback)(struct __SPI_HandleTypeDef *hspi);          /*!< SPI Msp DeInit callback            */

#endif  /* USE_HAL_SPI_REGISTER_CALLBACKS */
} SPI_HandleTypeDef;

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
/**
  * @brief  HAL SPI Callback ID enumeration definition
  */
typedef enum
{
  HAL_SPI_TX_COMPLETE_CB_ID             = 0x00U,    /*!< SPI Tx Completed callback ID         */
  HAL_SPI_RX_COMPLETE_CB_ID             = 0x01U,    /*!< SPI Rx Completed callback ID         */
  HAL_SPI_TX_RX_COMPLETE_CB_ID          = 0x02U,    /*!< SPI TxRx Completed callback ID       */
  HAL_SPI_TX_HALF_COMPLETE_CB_ID        = 0x03U,    /*!< SPI Tx Half Completed callback ID    */
  HAL_SPI_RX_HALF_COMPLETE_CB_ID        = 0x04U,    /*!< SPI Rx Half Completed callback ID    */
  HAL_SPI_TX_RX_HALF_COMPLETE_CB_ID     = 0x05U,    /*!< SPI TxRx Half Completed callback ID  */
  HAL_SPI_ERROR_CB_ID                   = 0x06U,    /*!< SPI Error callback ID                */
  HAL_SPI_ABORT_CB_ID                   = 0x07U,    /*!< SPI Abort callback ID                */
  HAL_SPI_MSPINIT_CB_ID                 = 0x08U,    /*!< SPI Msp Init callback ID             */
  HAL_SPI_MSPDEINIT_CB_ID               = 0x09U     /*!< SPI Msp DeInit callback ID           */

} HAL_SPI_CallbackIDTypeDef;

/**
  * @brief  HAL SPI Callback pointer definition
  */
typedef  void (*pSPI_CallbackTypeDef)(SPI_HandleTypeDef *hspi); /*!< pointer to an SPI callback function */

#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup SPI_Exported_Constants SPI Exported Constants
  * @{
  */
/** @defgroup SPI_Error_Code SPI Error Code
  * @{
  */
#define HAL_SPI_ERROR_NONE              (0x00000000U)   /*!< No error                               */
#define HAL_SPI_ERROR_MODF              (0x00000001U)   /*!< MODF error                             */
#define HAL_SPI_ERROR_CRC               (0x00000002U)   /*!< CRC error                              */
#define HAL_SPI_ERROR_OVR               (0x00000004U)   /*!< OVR error                              */
#define HAL_SPI_ERROR_FRE               (0x00000008U)   /*!< FRE error                              */
#define HAL_SPI_ERROR_DMA               (0x00000010U)   /*!< DMA transfer error                     */
#define HAL_SPI_ERROR_STAUS             (0x00000020U)   /*!< Error on RXNE/TXE/BSY/FTLVL/FRLVL Flag */
#define HAL_SPI_ERROR_ABORT             (0x00000040U)   /*!< Error during SPI Abort procedure       */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
#define HAL_SPI_ERROR_INVALID_CALLBACK  (0x00000080U)   /*!< Invalid Callback error                 */
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
#define HAL_SPI_ERROR_RXO               (0x00000100U)   /*!< RX FIFO overflow error                     */
#define HAL_SPI_ERROR_TXO               (0x00000200U)   /*!< TX FIFO overflow error                     */
#define HAL_SPI_ERROR_TXE               (0x00000400U)   /*!< Transmission error                     */
#define HAL_SPI_ERROR_DCOL              (0x00000800U)   /*!< Data collision error                     */
#define HAL_SPI_ERROR_RXU               (0x00001000U)   /*!< RX underflow error                     */
#define HAL_SPI_ERROR_MST               (0x00002000U)   /*!< Multi-master contention error                     */
#define HAL_SPI_ERROR_FLAG              (0x00004000U)   /*!< Multi-master contention error                     */
#define HAL_SPI_ERROR_TIMEOUT           (0x00008000U)   /*!< timeout error                     */
/**
  * @}
  */

/** @defgroup SPI_Mode SPI Mode
  * @{
  */
#define SPI_MODE_MASTER                (0)
#define SPI_MODE_SLAVE                 (1)
/**
  * @}
  */

/** @defgroup SPI_Direction SPI Direction Mode
  * @{
  */
#define SPI_DIRECTION_2LINES           (0)
#define SPI_DIRECTION_2LINES_TXONLY    (SPI_CTRLR0_TMOD_0)
#define SPI_DIRECTION_2LINES_RXONLY    (SPI_CTRLR0_TMOD_1)
#define SPI_DIRECTION_2LINES_EEPROM    (SPI_CTRLR0_TMOD_1 | SPI_CTRLR0_TMOD_0)
/**
  * @}
  */

/** @defgroup SPI_Data_Size SPI Data Size
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
/**
  * @}
  */

/** @defgroup SPI_Clock_Polarity SPI Clock Polarity
  * @{
  */
#define SPI_POLARITY_LOW               (0x00000000U)
#define SPI_POLARITY_HIGH              (SPI_CTRLR0_SCPOL)
/**
  * @}
  */

/** @defgroup SPI_Clock_Phase SPI Clock Phase
  * @{
  */
#define SPI_PHASE_1EDGE                (0x00000000U)
#define SPI_PHASE_2EDGE                (SPI_CTRLR0_SCPH)
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

/** @defgroup SPI_Protocol SPI Protocol 
  * @{
  */
#define SPI_FRF_MOTO                   (0x00000000UL)                          /*!< Motorola SPI                         */
#define SPI_FRF_TI                     (SPI_CTRLR0_FRF_0)                      /*!< TI SSP                               */
#define SPI_FRF_NS                     (SPI_CTRLR0_FRF_1)                      /*!< National Semiconductors microwire    */
/**
  * @}
  */

/** @defgroup SPI_FIFO_reception_threshold SPI FIFO Reception Threshold
  * @{
  * This parameter can be one of the following values:
  *     RXF event is generated if the FIFO
  *          level is greater or equal to the value
  */
#define SPI_RXFIFO_THRESHOLD_E         (0x00000000UL)                          /*!< RXF event is generated if FIFO level is greater than or equal to 1 */   
#define SPI_RXFIFO_THRESHOLD_QF        ((SPI_RX_FIFO_DEPTH-1)>>2)              /*!< RXF event is generated if FIFO level is greater than or equal to 2 */
#define SPI_RXFIFO_THRESHOLD_HF        ((SPI_RX_FIFO_DEPTH-1)>>1)              /*!< RXF event is generated if FIFO level is greater than or equal to 4 */ 
#define SPI_RXFIFO_THRESHOLD_F         (SPI_RX_FIFO_DEPTH-1)                   /*!< RXF event is generated if FIFO level is greater than or equal to 8 */
/**
  * @}
  */

/** @defgroup SPI_FIFO_transmission_threshold SPI FIFO transmit Threshold
  * @{
  * This parameter can be one of the following values:
  *          TXE event is generated if the FIFO
  *          level is less or equal to the value.
  */
#define SPI_TXFIFO_THRESHOLD_E          (0x00000000UL)                         /*!< TXE event is generated if FIFO level is less than or equal to 0 */
#define SPI_TXFIFO_THRESHOLD_QF         ((SPI_TX_FIFO_DEPTH-1)>>2)             /*!< TXE event is generated if FIFO level is less than or equal to 1 */
#define SPI_TXFIFO_THRESHOLD_HF         ((SPI_TX_FIFO_DEPTH-1)>>1)             /*!< TXE event is generated if FIFO level is less than or equal to 3 */
#define SPI_TXFIFO_THRESHOLD_F          (SPI_TX_FIFO_DEPTH-1)                  /*!< TXE event is generated if FIFO level is less than or equal to 7 */
/**
  * @}
  */

/** @defgroup SPI_Interrupt_definition SPI Interrupt Definition
  * @{
  */
#define SPI_IT_TXE                      SPI_ISR_TXEIS
#define SPI_IT_TXO                      SPI_ISR_TXOIS
#define SPI_IT_RXU                      SPI_ISR_RXUIS
#define SPI_IT_RXO                      SPI_ISR_RXOIS
#define SPI_IT_RXF                      SPI_ISR_RXFIS
#define SPI_IT_MST                      SPI_ISR_MSTIS
#define SPI_IT_ALL                     (SPI_ISR_TXEIS | SPI_ISR_TXOIS | \
                                        SPI_ISR_RXUIS | SPI_ISR_RXOIS | SPI_ISR_RXFIS | \
																				SPI_ISR_MSTIS)
/**
  * @}
  */

/** @defgroup SPI_Interrupt_definition SPI Interrupt Definition
  * @{
  */
#define SPI_FLAG_TXE                      SPI_ISR_TXEIS
#define SPI_FLAG_TXO                      SPI_ISR_TXOIS
#define SPI_FLAG_RXU                      SPI_ISR_RXUIS
#define SPI_FLAG_RXO                      SPI_ISR_RXOIS
#define SPI_FLAG_RXF                      SPI_ISR_RXFIS
#define SPI_FLAG_MST                      SPI_ISR_MSTIS
#define SPI_FLAG_ALL                     (SPI_ISR_TXEIS | SPI_ISR_TXOIS | \
                                        SPI_ISR_RXUIS | SPI_ISR_RXOIS | SPI_ISR_RXFIS | \
																				SPI_ISR_MSTIS)
/**
  * @}
  */

/** @defgroup SPI_Flags_definition SPI Status Definition
  * @{
  */
#define SPI_STATUS_BUSY                   SPI_SR_BUSY                          /* SPI status flag: ssi busy flag            */
#define SPI_STATUS_TFNF                   SPI_SR_TFNF                          /* SPI status flag: tx FIFO no full flag     */
#define SPI_STATUS_TFE                    SPI_SR_TFE                           /* SPI status flag: tx FIFO empty flag       */
#define SPI_STATUS_RFNE                   SPI_SR_RFNE                          /* SPI Error flag: rx FIFO not empty flag    */
#define SPI_STATUS_RFF                    SPI_SR_RFF                           /* SPI Error flag: rx FIFO full flag         */
#define SPI_STATUS_TXE                    SPI_SR_TXE                           /* SPI Error flag: tx error flag             */
#define SPI_STATUS_DCOL                   SPI_SR_DCOL                          /* SPI Error flag: data collision error flag */
#define SPI_STATUS_MASK                   (SPI_SR_BUSY | SPI_SR_TFNF | SPI_SR_TFE | SPI_SR_RFNE\
                                         | SPI_SR_RFF | SPI_SR_TXE | SPI_SR_DCOL)
/**
  * @}
  */

/** @defgroup SPI_transmission_fifo_status_level SPI Transmission FIFO Status Level
  * @{
  */
#define SPI_FTLVL_EMPTY                (0x00000000U)                           /*!< FIFO reception 0 */
#define SPI_FTLVL_QUARTER_FULL         ((SPI_RX_FIFO_DEPTH)>>2)                /*!< FIFO reception 2 */
#define SPI_FTLVL_HALF_FULL            ((SPI_RX_FIFO_DEPTH)>>1)                /*!< FIFO reception 4 */
#define SPI_FTLVL_FULL                 (SPI_RX_FIFO_DEPTH)                     /*!< FIFO reception 8 */

/**
  * @}
  */

/** @defgroup SPI_reception_fifo_status_level SPI Reception FIFO Status Level
  * @{
  */
#define SPI_FRLVL_EMPTY                (0x00000000U)                           /*!< FIFO transmission 0 */
#define SPI_FRLVL_QUARTER_FULL         ((SPI_TX_FIFO_DEPTH)>>2)                /*!< FIFO transmission 2 */ 
#define SPI_FRLVL_HALF_FULL            ((SPI_TX_FIFO_DEPTH)>>1)                /*!< FIFO transmission 4 */
#define SPI_FRLVL_FULL                 (SPI_TX_FIFO_DEPTH)                     /*!< FIFO transmission 8 */
/**
  * @}
  */

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup SPI_Private_Constant SPI Private Constant
  * @{
  */

/** @defgroup SPI_FIFO_Depth SPI Reception/Transmission FIFO depth
  * @{
  */
#define SPI_RX_FIFO_DEPTH              (8)
#define SPI_TX_FIFO_DEPTH              (8)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup SPI_Exported_Macros SPI Exported Macros
  * @{
  */

/** @brief  Reset SPI handle state.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
#define __HAL_SPI_RESET_HANDLE_STATE(__HANDLE__)                do{                                                  \
                                                                    (__HANDLE__)->State = HAL_SPI_STATE_RESET;       \
                                                                    (__HANDLE__)->MspInitCallback = NULL;            \
                                                                    (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                                  } while(0)
#else
#define __HAL_SPI_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_SPI_STATE_RESET)
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */

/** @brief  Unmask the specified SPI interrupts.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @param  __INTERRUPT__ specifies the interrupt source to enable.
  *         This parameter can be one of the following values:
  *            @arg SPI_IT_TXE: Tx buffer empty interrupt unmask
  *            @arg SPI_IT_TXO: TX buffer overflow interrupt unmask
  *            @arg SPI_IT_RXU: Rx buffer underflow interrupt unmask
  *            @arg SPI_IT_RXO: Rx buffer overflow interrupt unmask
  *            @arg SPI_IT_RXF: Rx buffer full interrupt unmask
  *            @arg SPI_IT_MST: Multi_master contention interrupt unmask
  * @retval None
  */
#define __HAL_SPI_UNMASK_IT(__HANDLE__, __INTERRUPT__)   SET_BIT((__HANDLE__)->Instance->IMR, (__INTERRUPT__))

/** @brief  Mask the specified SPI interrupts.
  * @param  __HANDLE__ specifies the SPI handle.
  *         This parameter can be SPIx where x: 1, 2, or 3 to select the SPI peripheral.
  * @param  __INTERRUPT__ specifies the interrupt source to disable.
  *         This parameter can be one of the following values:
  *            @arg SPI_IT_TXE: Tx buffer empty interrupt mask
  *            @arg SPI_IT_TXO: TX buffer overflow interrupt mask
  *            @arg SPI_IT_RXU: Rx buffer underflow interrupt mask
  *            @arg SPI_IT_RXO: Rx buffer overflow interrupt mask
  *            @arg SPI_IT_RXF: Rx buffer full interrupt mask
  *            @arg SPI_IT_MST: Multi_master contention interrupt mask
  * @retval None
  */
#define __HAL_SPI_MASK_IT(__HANDLE__, __INTERRUPT__)  CLEAR_BIT((__HANDLE__)->Instance->IMR, (__INTERRUPT__))

/** @brief  Check whether the specified SPI interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @param  __INTERRUPT__ specifies the SPI interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg SPI_IT_TXE: Tx buffer empty interrupt status
  *            @arg SPI_IT_TXO: TX buffer overflow interrupt status
  *            @arg SPI_IT_RXU: Rx buffer underflow interrupt status
  *            @arg SPI_IT_RXO: Rx buffer overflow interrupt status
  *            @arg SPI_IT_RXF: Rx buffer full interrupt status
  *            @arg SPI_IT_MST: Multi_master contention interrupt status
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
#define __HAL_SPI_GET_IT(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->ISR & (__INTERRUPT__))

/** @brief  Check whether the specified SPI interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @param  __INTERRUPT__ specifies the SPI interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg SPI_FLAG_TXE: Tx buffer empty interrupt status
  *            @arg SPI_FLAG_TXO: TX buffer overflow interrupt status
  *            @arg SPI_FLAG_RXU: Rx buffer underflow interrupt status
  *            @arg SPI_FLAG_RXO: Rx buffer overflow interrupt status
  *            @arg SPI_FLAG_RXF: Rx buffer full interrupt status
  *            @arg SPI_FLAG_MST: Multi_master contention interrupt status
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
#define __HAL_SPI_GET_FLAG(__HANDLE__, __INTERRUPT__) ((__HANDLE__)->Instance->RISR & (__INTERRUPT__)) 

/** @brief  Get the specified SPI flag.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @param  __FLAG__ specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_STATUS_BUSY : SPI status flag: ssi busy flag       
  *            @arg SPI_STATUS_TFNF : SPI status flag: tx FIFO no full flag           
  *            @arg SPI_STATUS_TFE  : SPI status flag: tx FIFO empty flag             
  *            @arg SPI_STATUS_RFNE : SPI Error flag: rx FIFO not empty flag          
  *            @arg SPI_STATUS_RFF  : SPI Error flag: rx FIFO full flag               
  *            @arg SPI_STATUS_TXE  : SPI Error flag: tx error flag                    
  *            @arg SPI_STATUS_DCOL :* SPI Error flag: data collision error flag 
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
	#define __HAL_SPI_GET_STATUS(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR) & (__FLAG__)) 

/** @brief  Clear the SPI transmit FIFO overflow interrupt.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_CLEAR_TXOICR(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->TXOICR, SPI_TXOICR_TXOICR)

/** @brief  Clear the SPI receive FIFO overflow interrupt.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_CLEAR_RXOICR(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->RXOICR, SPI_RXOICR_RXOICR)

/** @brief  Clear the SPI receive FIFO underflow interrupt.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_CLEAR_RXUICR(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->RXUICR, SPI_RXUICR_RXUICR)

/** @brief  Clear the SPI multi-master contention interrupt.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_CLEAR_MSTICR(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->MSTICR, SPI_MSTICR_MSTICR)

/** @brief  Clear the SPI all interrupts.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_CLEAR_ALLICR(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->ICR, SPI_ICR_ICR)

/** @brief  Enable the SPI peripheral.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_ENABLE(__HANDLE__)  SET_BIT((__HANDLE__)->Instance->SSIENR, SPI_SSIENR_SSIEN)

/** @brief  Disable the SPI peripheral.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_DISABLE(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->SSIENR, SPI_SSIENR_SSIEN)

/** @brief  check SPI master.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval Status (1 or 0)
  */
#define __HAL_SPI_IS_MASTER(__HANDLE__) ((((__HANDLE__)->Instance == SPI1M) || ((__HANDLE__)->Instance == SPI2M)) ? 1UL : 0UL)

/** @brief  check SPI slave.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval Status (1 or 0)
  */
#define __HAL_SPI_IS_SLAVE(__HANDLE__) ((((__HANDLE__)->Instance == SPI1S) || ((__HANDLE__)->Instance == SPI2S)) ? 1UL : 0UL)
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup SPI_Private_Macros SPI Private Macros
  * @{
  */

/** @brief  Set the SPI transmit-only mode.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define SPI_1LINE_TX(__HANDLE__)  MODIFY_REG((__HANDLE__)->Instance->CTRLR0, SPI_CTRLR0_TMOD, SPI_DIRECTION_2LINES_TXONLY)

/** @brief  Set the SPI receive-only mode.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define SPI_1LINE_RX(__HANDLE__)  MODIFY_REG((__HANDLE__)->Instance->CTRLR0, SPI_CTRLR0_TMOD, SPI_DIRECTION_2LINES_RXONLY)

/** @brief  Check whether the specified SPI flag is set or not.
  * @param  __SR__  copy of SPI SR register.
  * @param  __STATUS__ specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_STATUS_BUSY : SPI status flag: ssi busy flag       
  *            @arg SPI_STATUS_TFNF : SPI status flag: tx FIFO no full flag           
  *            @arg SPI_STATUS_TFE  : SPI status flag: tx FIFO empty flag             
  *            @arg SPI_STATUS_RFNE : SPI Error flag: rx FIFO not empty flag          
  *            @arg SPI_STATUS_RFF  : SPI Error flag: rx FIFO full flag               
  *            @arg SPI_STATUS_TXE  : SPI Error flag: tx error flag                    
  *            @arg SPI_STATUS_DCOL :* SPI Error flag: data collision error flag 
  * @retval SET or RESET.
  */
#define SPI_CHECK_STATUS(__SR__, __STATUS__) ((((__SR__) & ((__STATUS__) & SPI_STATUS_MASK)) == \
                                          ((__STATUS__) & SPI_STATUS_MASK)) ? SET : RESET)

/** @brief  Check whether the specified SPI Interrupt is set or not.
  * @param  __ISR__  copy of SPI ISR register.
  * @param  __INTERRUPT__ specifies the SPI interrupt source to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_IT_TXE: Tx buffer empty interrupt status
  *            @arg SPI_IT_TXO: TX buffer overflow interrupt status
  *            @arg SPI_IT_RXU: Rx buffer underflow interrupt status
  *            @arg SPI_IT_RXO: Rx buffer overflow interrupt status
  *            @arg SPI_IT_RXF: Rx buffer full interrupt status
  *            @arg SPI_IT_MST: Multi_master contention interrupt status
  * @retval SET or RESET.
  */
#define SPI_CHECK_IT(__ISR__, __INTERRUPT__) ((((__ISR__) & (__INTERRUPT__)) == \
                                                     (__INTERRUPT__)) ? SET : RESET)

/** @brief  Check whether the specified SPI Interrupt is set or not.
  * @param  __RISR__  copy of SPI ISR register.
  * @param  __INTERRUPT__ specifies the SPI interrupt source to check.
  *         This parameter can be one of the following values:
  *            @arg SPI_IT_TXE: Tx buffer empty interrupt status
  *            @arg SPI_IT_TXO: TX buffer overflow interrupt status
  *            @arg SPI_IT_RXU: Rx buffer underflow interrupt status
  *            @arg SPI_IT_RXO: Rx buffer overflow interrupt status
  *            @arg SPI_IT_RXF: Rx buffer full interrupt status
  *            @arg SPI_IT_MST: Multi_master contention interrupt status
  * @retval SET or RESET.
  */
#define SPI_CHECK_FLAG(__RISR__, __INTERRUPT__) ((((__RISR__) & (__INTERRUPT__)) == \
                                                     (__INTERRUPT__)) ? SET : RESET)

/** @brief  Checks if SPI Direction Mode parameter is in allowed range.
  * @param  __MODE__ specifies the SPI Direction Mode.
  *         This parameter can be a value of @ref SPI_Direction
  * @retval None
  */
#define IS_SPI_DIRECTION(__MODE__) (((__MODE__) == SPI_DIRECTION_2LINES)        || \
                                    ((__MODE__) == SPI_DIRECTION_2LINES_RXONLY) || \
                                    ((__MODE__) == SPI_DIRECTION_2LINES_TXONLY))

/** @brief  Checks if SPI Direction Mode parameter is 2 lines.
  * @param  __MODE__ specifies the SPI Direction Mode.
  * @retval None
  */
#define IS_SPI_DIRECTION_2LINES(__MODE__) ((__MODE__) == SPI_DIRECTION_2LINES)

/** @brief  Checks if SPI Direction Mode parameter is 1 or 2 lines.
  * @param  __MODE__ specifies the SPI Direction Mode.
  * @retval None
  */
#define IS_SPI_DIRECTION_TX(__MODE__) (((__MODE__) == SPI_DIRECTION_2LINES) || \
                                       ((__MODE__) == SPI_DIRECTION_2LINES_TXONLY))

/** @brief  Checks if SPI Direction Mode parameter is 1 or 2 lines.
  * @param  __MODE__ specifies the SPI Direction Mode.
  * @retval None
  */
#define IS_SPI_DIRECTION_RX(__MODE__) (((__MODE__) == SPI_DIRECTION_2LINES) || \
                                       ((__MODE__) == SPI_DIRECTION_2LINES_RXONLY))

/** @brief  Checks if SPI Data Size parameter is in allowed range.
  * @param  __DATASIZE__ specifies the SPI Data Size.
  *         This parameter can be a value of @ref SPI_Data_Size
  * @retval None
  */
#define IS_SPI_DATASIZE(__DATASIZE__) (((__DATASIZE__) == SPI_DATASIZE_16BIT) || \
                                       ((__DATASIZE__) == SPI_DATASIZE_15BIT) || \
                                       ((__DATASIZE__) == SPI_DATASIZE_14BIT) || \
                                       ((__DATASIZE__) == SPI_DATASIZE_13BIT) || \
                                       ((__DATASIZE__) == SPI_DATASIZE_12BIT) || \
                                       ((__DATASIZE__) == SPI_DATASIZE_11BIT) || \
                                       ((__DATASIZE__) == SPI_DATASIZE_10BIT) || \
                                       ((__DATASIZE__) == SPI_DATASIZE_9BIT)  || \
                                       ((__DATASIZE__) == SPI_DATASIZE_8BIT)  || \
                                       ((__DATASIZE__) == SPI_DATASIZE_7BIT)  || \
                                       ((__DATASIZE__) == SPI_DATASIZE_6BIT)  || \
                                       ((__DATASIZE__) == SPI_DATASIZE_5BIT)  || \
                                       ((__DATASIZE__) == SPI_DATASIZE_4BIT))

/** @brief  Checks if SPI Control Size parameter is in allowed range.
  * @param  __CTRLSIZE__ specifies the SPI CTRL Size.
  *         This parameter can be a value of @ref SPI_CTRL_Size
  * @retval None
  */
#define IS_SPI_CTRLSIZE(__CTRLSIZE__) (((__CTRLSIZE__) == SPI_CTRLSIZE_16BIT) || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_15BIT) || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_14BIT) || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_13BIT) || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_12BIT) || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_11BIT) || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_10BIT) || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_9BIT)  || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_8BIT)  || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_7BIT)  || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_6BIT)  || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_5BIT)  || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_4BIT)  || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_3BIT)  || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_2BIT)  || \
                                       ((__CTRLSIZE__) == SPI_CTRLSIZE_1BIT))

/** @brief  Checks if SPI Serial clock steady state parameter is in allowed range.
  * @param  __SCPOL__ specifies the SPI serial clock steady state.
  *         This parameter can be a value of @ref SPI_Clock_Polarity
  * @retval None
  */
#define IS_SPI_SCPOL(__SCPOL__)      (((__SCPOL__) == SPI_POLARITY_LOW) || \
                                    ((__SCPOL__) == SPI_POLARITY_HIGH))

/** @brief  Checks if SPI Clock Phase parameter is in allowed range.
  * @param  __SCPH__ specifies the SPI Clock Phase.
  *         This parameter can be a value of @ref SPI_Clock_Phase
  * @retval None
  */
#define IS_SPI_SCPH(__SCPH__)      (((__SCPH__) == SPI_PHASE_1EDGE) || \
                                    ((__SCPH__) == SPI_PHASE_2EDGE))

/** @brief  Enable the SPI slave select.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_SS_ENABLE(__HANDLE__)  SET_BIT((__HANDLE__)->Instance->SER, SPI_SLAVE_SELECT_0)

/** @brief  Dsiable the SPI slave select.
  * @param  __HANDLE__ specifies the SPI Handle.
  *         This parameter can be SPI where x: 1, 2, or 3 to select the SPI peripheral.
  * @retval None
  */
#define __HAL_SPI_SS_DISABLE(__HANDLE__)  CLEAR_BIT((__HANDLE__)->Instance->SER, SPI_SLAVE_SELECT_0)

/** @brief  Checks if SPI Baudrate prescaler parameter is in allowed range.
  * @param  __BAUDRATE__ specifies the SPI Baudrate prescaler.
  *         This parameter can be a value of [2, 65534]
  * @retval None
  */
#define IS_SPI_BAUDRATE(__BAUDRATE__) (((__PRESCALER__) >= 0x0UL  && \
                                                  ((__PRESCALER__) <= 0xFFFEUL))

/** @brief  Checks if SPI protocol parameter is in allowed range.
  * @param  __MODE__ specifies the SPI procotol.
  *         This parameter can be a value of @ref SPI_Protocol
  * @retval None
  */
#define IS_SPI_FRF(__MODE__)    (((__MODE__) == SPI_FRF_MOTO) || \
                                 ((__MODE__) == SPI_FRF_TI)   || \
                                 ((__MODE__) == SPI_FRF_NS) )

/** @brief  Checks if DMA handle is valid.
  * @param  __HANDLE__ specifies a DMA Handle.
  * @retval None
  */
#define IS_SPI_DMA_HANDLE(__HANDLE__) ((__HANDLE__) != NULL)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SPI_Exported_Functions
  * @{
  */

/** @addtogroup SPI_Exported_Functions_Group1
  * @{
  */
/* Initialization/de-initialization functions  ********************************/
HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DeInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_StructInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi);

HAL_StatusTypeDef HAL_SPI_DMAHSIFConfig(SPI_HandleTypeDef *hspi, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx, 
                                         uint32_t rxif, uint32_t txif, uint32_t rxifcfg, uint32_t txifcfg);
HAL_StatusTypeDef HAL_SPI_LinkDMA(SPI_HandleTypeDef *hspi, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
HAL_StatusTypeDef HAL_SPI_RegisterCallback(SPI_HandleTypeDef *hspi, HAL_SPI_CallbackIDTypeDef CallbackID, pSPI_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_SPI_UnRegisterCallback(SPI_HandleTypeDef *hspi, HAL_SPI_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group2
  * @{
  */
/* I/O operation functions  ***************************************************/
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size,
                                          uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Transmit_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Receive_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData,
                                             uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Transmit_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_Receive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData,
                                              uint16_t Size);
HAL_StatusTypeDef HAL_SPI_DMAPause(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DMAResume(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_DMAStop(SPI_HandleTypeDef *hspi);
/* Transfer Abort functions */
HAL_StatusTypeDef HAL_SPI_Abort(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Abort_IT(SPI_HandleTypeDef *hspi);

/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group3
  * @{
  */
void HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi);
//void HAL_SPI_TxHalfCpltCallback(SPI_HandleTypeDef *hspi);
//void HAL_SPI_RxHalfCpltCallback(SPI_HandleTypeDef *hspi);
//void HAL_SPI_TxRxHalfCpltCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi);
void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi);
/**
  * @}
  */

/** @addtogroup SPI_Exported_Functions_Group4
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_SPI_StateTypeDef HAL_SPI_GetState(SPI_HandleTypeDef *hspi);
uint32_t             HAL_SPI_GetError(SPI_HandleTypeDef *hspi);
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

#endif /* XT32H0xx_HAL_SPI_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
