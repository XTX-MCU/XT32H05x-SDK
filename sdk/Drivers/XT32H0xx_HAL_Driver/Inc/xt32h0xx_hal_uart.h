/**
  ******************************************************************************
  * @file    xt32h0xx_hal_uart.h
  * @author  Software Team
  * @brief   Header file of UART HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_UART_H
#define XT32H0xx_HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup UART_Exported_Types UART Exported Types
  * @{
  */

/**
  * @brief UART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                   /*!< This member configures the UART communication baud rate. */

  uint32_t WordLength;                 /*!< Specifies the number of data bits transmitted or received in a frame.
                                         This parameter can be a value of @ref UART_Word_Length. */

  uint32_t StopBits;                   /*!< Specifies the number of stop bits transmitted.
                                         This parameter can be a value of @ref UART_Stop_Bits. */

  uint32_t Parity;                     /*!< Specifies the parity mode.
                                         This parameter can be a value of @ref UART_Parity. */

  uint32_t HwFlowCtl;                  /*!< Specifies whether the hardware flow control mode is enabled
                                         or disabled.
                                         This parameter can be a value of @ref UART_Hardware_Flow_Control. */

	uint32_t LoopBack;                   /*!< Specifies UART loopback mode
                                         This parameter can be a value of @ref UART_Rx_Tx_Loopback. */ 
	
	uint32_t IsIrDA;                     /*!< Specifies UART work mode
                                         This parameter can be a value of 0 (normal mode) or 1 (IrDA). */  
} UART_InitTypeDef;

/**
  * @brief HAL UART State definition
  */
typedef uint32_t HAL_UART_StateTypeDef;

/**
  * @brief HAL UART Reception type definition
  * @note  HAL UART Reception type value aims to identify which type of Reception is ongoing.
  *        It is expected to admit following values :
  *           HAL_UART_RECEPTION_STANDARD         = 0x00U,
  *           HAL_UART_RECEPTION_TOIDLE           = 0x01U,
  *           HAL_UART_RECEPTION_TORTO            = 0x02U,
  *           HAL_UART_RECEPTION_TOCHARMATCH      = 0x03U,
  */
typedef uint32_t HAL_UART_RxTypeTypeDef;

/**
  * @brief  UART handle Structure definition
  */
typedef struct __UART_HandleTypeDef
{
  UART_TypeDef            *Instance;                /*!< UART registers base address        */

  UART_InitTypeDef         Init;                     /*!< UART communication parameters      */

  uint8_t                  *pTxBuffPtr;              /*!< Pointer to UART Tx transfer Buffer */
	
  uint16_t                 TxXferSize;               /*!< UART Tx Transfer size              */

  __IO uint16_t            TxXferCount;              /*!< UART Tx Transfer Counter           */

  uint8_t                  *pRxBuffPtr;              /*!< Pointer to UART Rx transfer Buffer */

  uint16_t                 RxXferSize;               /*!< UART Rx Transfer size              */

  __IO uint16_t            RxXferCount;              /*!< UART Rx Transfer Counter           */

  uint32_t                 Mask;                     /*!< UART Rx RDR register mask          */

  uint32_t                 FifoMode;                 /*!< Specifies if the FIFO mode is being used.
                                                          This parameter can be a value of @ref UART_FIFO_mode. */
  uint32_t                 RxFifoTrigger;
  uint32_t                 TxFifoTrigger;

  uint16_t                 NbRxDataToProcess;        /*!< Number of data to process during RX ISR execution */

  uint16_t                 NbTxDataToProcess;        /*!< Number of data to process during TX ISR execution */

  __IO HAL_UART_RxTypeTypeDef ReceptionType;         /*!< Type of ongoing reception          */

  uint8_t                 MatchChar;                /*!< Match character to stop reception */

  void (*RxISR)(struct __UART_HandleTypeDef *huart); /*!< Function pointer on Rx IRQ handler */

  void (*TxISR)(struct __UART_HandleTypeDef *huart); /*!< Function pointer on Tx IRQ handler */

  DMA_HandleTypeDef        *hdmatx;                  /*!< UART Tx DMA Handle parameters      */

  DMA_HandleTypeDef        *hdmarx;                  /*!< UART Rx DMA Handle parameters      */

  HAL_LockTypeDef           Lock;                    /*!< Locking object                     */

  uint8_t                   dumy[2];

  __IO HAL_UART_StateTypeDef    gState;              /*!< UART state information related to global Handle management
                                                          and also related to Tx operations. This parameter
                                                          can be a value of @ref HAL_UART_StateTypeDef */

//  __IO HAL_UART_StateTypeDef    RxState;             /*!< UART state information related to Rx operations. This
//                                                          parameter can be a value of @ref HAL_UART_StateTypeDef */


  __IO uint32_t                 ErrorCode;           /*!< UART Error code                    */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  void (* TxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Tx Complete Callback             */
  void (* TxBlockCallback)(struct __UART_HandleTypeDef *huart);           /*!< UART Tx Complete block Callback             */
  void (* TxSrcTranCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Tx Complete source transaction Callback             */
  void (* TxDstTranCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Tx Complete destination transaction Callback             */
  void (* RxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Rx Complete Callback             */
  void (* RxBlockCallback)(struct __UART_HandleTypeDef *huart);           /*!< UART Rx Complete block Callback             */
  void (* RxSrcTranCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Rx Complete source transaction Callback             */
  void (* RxDstTranCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Rx Complete destination transaction Callback             */
  void (* ErrorCallback)(struct __UART_HandleTypeDef *huart);             /*!< UART Error Callback                   */
  void (* AbortCpltCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Abort Complete Callback          */
  void (* AbortTransmitCpltCallback)(struct __UART_HandleTypeDef *huart); /*!< UART Abort Transmit Complete Callback */
  void (* AbortReceiveCpltCallback)(struct __UART_HandleTypeDef *huart);  /*!< UART Abort Receive Complete Callback  */
  void (* RxFifoFullCallback)(struct __UART_HandleTypeDef *huart);        /*!< UART Rx Fifo Full Callback            */
  void (* TxFifoEmptyCallback)(struct __UART_HandleTypeDef *huart);       /*!< UART Tx Fifo Empty Callback           */
  void (* RxEventCallback)(struct __UART_HandleTypeDef *huart, uint16_t Pos); /*!< UART Reception Event Callback     */

  void (* MspInitCallback)(struct __UART_HandleTypeDef *huart);           /*!< UART Msp Init callback                */
  void (* MspDeInitCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Msp DeInit callback              */
#endif  /* USE_HAL_UART_REGISTER_CALLBACKS */

} UART_HandleTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL UART Callback ID enumeration definition
  */
typedef enum
{
  HAL_UART_TX_COMPLETE_CB_ID             = 0x01U,    /*!< UART Tx Complete Callback ID             */
  HAL_UART_RX_COMPLETE_CB_ID             = 0x03U,    /*!< UART Rx Complete Callback ID             */
  HAL_UART_ERROR_CB_ID                   = 0x04U,    /*!< UART Error Callback ID                   */
  HAL_UART_ABORT_COMPLETE_CB_ID          = 0x05U,    /*!< UART Abort Complete Callback ID          */
  HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x06U,    /*!< UART Abort Transmit Complete Callback ID */
  HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x07U,    /*!< UART Abort Receive Complete Callback ID  */
  HAL_UART_RX_FIFO_FULL_CB_ID            = 0x09U,    /*!< UART Rx Fifo Full Callback ID            */
  HAL_UART_TX_FIFO_EMPTY_CB_ID           = 0x0AU,    /*!< UART Tx Fifo Empty Callback ID           */

  HAL_UART_MSPINIT_CB_ID                 = 0x0BU,    /*!< UART MspInit callback ID                 */
  HAL_UART_MSPDEINIT_CB_ID               = 0x0CU,    /*!< UART MspDeInit callback ID               */

  HAL_UART_TX_BLOCK_CB_ID                = 0x0DU,    /*!< UART Tx Complete Block Callback ID             */
  HAL_UART_TX_SRCTRAN_CB_ID              = 0x0EU,    /*!< UART Tx Complete Source Transaction Callback ID             */
  HAL_UART_TX_DSTTRAN_CB_ID              = 0x0FU,    /*!< UART Tx Complete Destination Transaction Callback ID             */

  HAL_UART_RX_BLOCK_CB_ID                = 0x10U,    /*!< UART Rx Complete Block Callback ID             */
  HAL_UART_RX_SRCTRAN_CB_ID              = 0x11U,    /*!< UART Rx Complete Source Transaction Callback ID             */
  HAL_UART_RX_DSTTRAN_CB_ID              = 0x12U,    /*!< UART Rx Complete Destination Transaction Callback ID             */

} HAL_UART_CallbackIDTypeDef;

/**
  * @brief  HAL UART Callback pointer definition
  */
typedef  void (*pUART_CallbackTypeDef)(UART_HandleTypeDef *huart); /*!< pointer to an UART callback function */
typedef  void (*pUART_RxEventCallbackTypeDef)
(struct __UART_HandleTypeDef *huart, uint16_t Pos); /*!< pointer to a UART Rx Event specific callback function */

#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup UART_Exported_Constants UART Exported Constants
  * @{
  */

/** @defgroup UART_State_Definition UART State Code Definition
  * @{
  */
#define  HAL_UART_STATE_RESET          (0x00000000U)                           /*!< Peripheral is not initialized */
#define  HAL_UART_STATE_READY          (0x00000020U)                           /*!< Peripheral Initialized and ready for use */
#define  HAL_UART_STATE_BUSY           (0x00000024U)                           /*!< an internal process is ongoing */
#define  HAL_UART_STATE_BUSY_TX        (0x00000021U)                           /*!< Data Transmission process is ongoing */
#define  HAL_UART_STATE_BUSY_RX        (0x00000022U)                           /*!< Data Reception process is ongoing */
#define  HAL_UART_STATE_BUSY_TX_RX     (0x00000023U)                           /*!< Data Transmission and Reception process is ongoing */
#define  HAL_UART_STATE_TIMEOUT        (0x000000A0U)                           /*!< Timeout state */
#define  HAL_UART_STATE_ERROR          (0x000000E0U)                           /*!< Error */
/**
  * @}
  */

/** @defgroup UART_Error_Definition   UART Error Definition
  * @{
  */
#define  HAL_UART_ERROR_NONE           (0x00000000U)                           /*!< No error                        */
#define  HAL_UART_ERROR_DMA            (0x00000001U)                           /*!< DMA transfer error              */
#define  HAL_UART_ERROR_OE             (0x00000002U)                           /*!< Overrun error                   */
#define  HAL_UART_ERROR_PE             (0x00000004U)                           /*!< Parity error                    */
#define  HAL_UART_ERROR_FE             (0x00000008U)                           /*!< Frame error                     */
#define  HAL_UART_ERROR_BI             (0x00000010U)                           /*!< break indicate                  */
#define  HAL_UART_ERROR_RFE            (0x00000080U)                           /*!< Receive FIFO error              */
#define  HAL_UART_ERROR_TO             (0x00001000U)                           /*!< Receive FIFO timeout error      */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define  HAL_UART_ERROR_INVALID_CALLBACK (0x00000040U)    /*!< Invalid Callback error  */
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup UART_Stop_Bits   UART Number of Stop Bits
  * @{
  */
#define UART_STOPBITS_1                (0x00000000U)                           /*!< UART frame with 1 stop bit    */
#define UART_STOPBITS_2                (UART_LCR_STOP)                         /*!< UART frame with 2 stop bits   */
/**
  * @}
  */

/** @defgroup UART_Parity  UART Parity
  * @{
  */
#define UART_PARITY_NONE               (0x00000000U)                           /*!< No parity   */
#define UART_PARITY_EVEN               (UART_LCR_PEN | UART_LCR_EPS)           /*!< Even parity */
#define UART_PARITY_ODD                (UART_LCR_PEN)                          /*!< Odd parity  */
/**
  * @}
  */

/** @defgroup UART_Hardware_Flow_Control UART Hardware Flow Control
  * @{
  */
#define UART_HWCONTROL_NONE            (0x00000000U)                           /*!< No hardware control       */
#define UART_HWCONTROL_ENABLE          (UART_MCR_AFCE)                         /*!< hardware control enable   */
/**
  * @}
  */

/** @defgroup UART_State  UART State
  * @{
  */
#define UART_STATE_BUSY                (UART_USR_BUSY)                         /*!< UART busy  */
//#define UART_STATE_TFNF                (UART_USR_TFNF)                         /*!< UART tx fifo not full  */
//#define UART_STATE_TFE                 (UART_USR_TFE)                          /*!< UART tx fifo empty  */
//#define UART_STATE_RFNE                (UART_USR_RFNE)                         /*!< UART rx fifo not empty  */
//#define UART_STATE_RFF                 (UART_USR_RFF)                          /*!< UART rx fifo full  */
/**
  * @}
  */

/** @defgroup UART_DMA_Tx    UART DMA Tx
  * @{
  */
#define UART_DMA_MODE_0                (0x00000000U)                           /*!< UART DMA Single Mode */
#define UART_DMA_MODE_1                (UART_IIR_FCR_DMAM)                     /*!< UART DMA Burst Mode */
/**
  * @}
  */

/** @defgroup UART_Rx_Tx_Loopback UART Advanced Feature RX TX Pins loop back
  * @{
  */
#define UART_LOOPBACK_DISABLE          (0x00000000U)                           /*!< TX/RX pins loopback disable */
#define UART_LOOPBACK_ENABLE           (UART_MCR_LB)                           /*!< TX/RX pins loopback enable  */
/**
  * @}
  */

/** @defgroup UART_Interruption_Mask    UART Interruptions Flag Mask
  * @{
  */
#define UART_IT_MASK                   (0x007FU)                               /*!< UART interruptions flags mask */
/**
  * @}
  */

/** @defgroup UART_TimeOut_Value    UART polling-based communications time-out value
  * @{
  */
#define HAL_UART_TIMEOUT_VALUE         (0x1FFFFFFU)                            /*!< UART polling-based communications time-out value */
/**
  * @}
  */

/** @defgroup UART_Interrupt_Enable    UART interrupt enable definition
  * @{
  */
#define UART_ENABLEIT_ERBFI            (UART_DLH_IER_ERBFI)                    /*!< UART enable received data available interrupt         */
#define UART_ENABLEIT_ETBEI            (UART_DLH_IER_ETBEI)                    /*!< UART enable transmit holding register empty interrupt */
#define UART_ENABLEIT_ELSI             (UART_DLH_IER_ELSI)                     /*!< UART enable receiver line status interrupt            */
#define UART_ENABLEIT_EDSSI            (UART_DLH_IER_EDSSI)                    /*!< UART enable modem status interrupt                    */
#define UART_ENABLEIT_PTIME            (UART_DLH_IER_PTIME)                    /*!< UART enable programmable THRE interrupt mode          */
#define UART_ENABLEIT_ALL              (UART_DLH_IER_ERBFI | \
                                        UART_DLH_IER_ETBEI | \
                                        UART_DLH_IER_ELSI  | \
                                        UART_DLH_IER_EDSSI | \
                                        UART_DLH_IER_PTIME)                    /*!< UART enable all interrupts                            */
/**                                    
  * @}
  */

/** @defgroup UART_Interrupt_definition   UART Interrupts Definition
  * @{
  */
#define UART_MS_DCTS                   (UART_MSR_DCTS)                         /*!< UART delta clear to send                       */
#define UART_MS_DDSR                   (UART_MSR_DDSR)                         /*!< UART delta data set ready                      */
#define UART_MS_TERI                   (UART_MSR_TERI)                         /*!< UART trailing edge of ring indicator           */
#define UART_MS_DDCD                   (UART_MSR_DDCD)                         /*!< UART dalta data carrier detect                 */
#define UART_MS_CTS                    (UART_MSR_CTS)                          /*!< UART Clear to send                             */
#define UART_MS_DSR                    (UART_MSR_DSR)                          /*!< UART Data set ready                            */
#define UART_MS_RI                     (UART_MSR_RI)                           /*!< UART ring indicator                            */
#define UART_MS_DCD                    (UART_MSR_DCD)                          /*!< UART data carrier detect                       */

#define UART_LS_DR                     (UART_LSR_DR)                           /*!< UART Data ready bit                            */
#define UART_LS_OE                     (UART_LSR_OE)                           /*!< UART overrun error bit                         */
#define UART_LS_PE                     (UART_LSR_PE)                           /*!< UART parity error bit                          */
#define UART_LS_FE                     (UART_LSR_FE)                           /*!< UART Framing error bit                         */
#define UART_LS_BI                     (UART_LSR_BI)                           /*!< UART break interrupt bit                       */
#define UART_LS_THRE                   (UART_LSR_THRE)                         /*!< UART transmit holding register empty           */
#define UART_LS_TEMT                   (UART_LSR_TEMT)                         /*!< UART transmitter empty bit                     */
#define UART_LS_RFE                    (UART_LSR_RFE)                          /*!< UART receiver FIFO error bit                   */

#define UART_IT_MS                     (0)                                     /*!< UART modem status interrupt, fourth priority   */
#define UART_IT_NO                     (UART_IIR_FCR_IID_0)                    /*!< UART no interrupt pending                      */
#define UART_IT_TE                     (UART_IIR_FCR_IID_1)                    /*!< UART THE empty, third priority                 */
#define UART_IT_RA                     (UART_IIR_FCR_IID_2)                    /*!< UART received data available, second priority  */
#define UART_IT_LS                     (UART_IIR_FCR_IID_2 | UART_IIR_FCR_IID_1)                           /*!< UART receiver line status, highest priority    */
#define UART_IT_BUSY                   (UART_IIR_FCR_IID_2 | UART_IIR_FCR_IID_1 | UART_IIR_FCR_IID_0)      /*!< UART busy detect, fifth priority               */
#define UART_IT_TO                     (UART_IIR_FCR_IID_3 | UART_IIR_FCR_IID_2)                           /*!< UART character timeout, second priority        */
/**
  * @}
  */

/** @defgroup UART_RECEPTION_TYPE_Values  UART Reception type values
  * @{
  */
#define HAL_UART_RECEPTION_STANDARD    (0x00000000U)                           /*!< Standard reception                       */
#define HAL_UART_RECEPTION_TOIDLE      (0x00000001U)                           /*!< Reception till completion or IDLE event  */
#define HAL_UART_RECEPTION_TORTO       (0x00000002U)                           /*!< Reception till completion or RTO event   */
#define HAL_UART_RECEPTION_TOCHARMATCH (0x00000003U)                           /*!< Reception till completion or CM event    */
/**
  * @}
  */

/** @defgroup UART_Word_Length UARTEx Word Length
  * @{
  */
#define UART_WORDLENGTH_5              (0x0UL)                                 /*!< 5-bit long UART frame */
#define UART_WORDLENGTH_6              (UART_LCR_DLS_0)                        /*!< 6-bit long UART frame */
#define UART_WORDLENGTH_7              (UART_LCR_DLS_1)                        /*!< 7-bit long UART frame */
#define UART_WORDLENGTH_8              (UART_LCR_DLS_0 | UART_LCR_DLS_1)       /*!< 8-bit long UART frame */
/**
  * @}
  */

/** @defgroup UART_FIFO_mode UARTEx FIFO mode
  * @brief    UART FIFO mode
  * @{
  */
#define UART_FIFOMODE_DISABLE          (0x00000000U)                           /*!< FIFO mode disable */
#define UART_FIFOMODE_ENABLE           (UART_IIR_FCR_FIFOE)                    /*!< FIFO mode enable  */
/**
  * @}
  */

/** @defgroup UART_TXFIFO_threshold_level UARTEx TXFIFO threshold level
  * @brief    UART TXFIFO threshold level
  * @{
  */
#define UART_TXFIFO_THRESHOLD_EMPTY    (0x00000000U)                           /*!< TX FIFO empty */
#define UART_TXFIFO_THRESHOLD_2CHAR    (UART_IIR_FCR_TET_0)                    /*!< TX FIFO 2 characters */
#define UART_TXFIFO_THRESHOLD_1_4      (UART_IIR_FCR_TET_1)                    /*!< TX FIFO reaches 1/4 of its depth */
#define UART_TXFIFO_THRESHOLD_1_2      (UART_IIR_FCR_TET_0 | UART_IIR_FCR_TET_1)         /*!< TX FIFO reaches 1/2 of its depth */
/**
  * @}
  */

/** @defgroup UART_RXFIFO_threshold_level UARTEx RXFIFO threshold level
  * @brief    UART RXFIFO threshold level
  * @{
  */
#define UART_RXFIFO_THRESHOLD_1CHAR    (0x00000000U)                           /*!< RX FIFO 1 character */
#define UART_RXFIFO_THRESHOLD_1_4      (UART_IIR_FCR_RCVR_0)                   /*!< RX FIFO reaches 1/4 of its depth */
#define UART_RXFIFO_THRESHOLD_1_2      (UART_IIR_FCR_RCVR_1)                   /*!< RX FIFO reaches 1/2 of its depth */
#define UART_RXFIFO_THRESHOLD_2FUll    (UART_IIR_FCR_RCVR_0 | UART_IIR_FCR_RCVR_1)       /*!< RX FIFO 2 less than full */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup UART_Exported_Macros UART Exported Macros
  * @{
  */

/** @brief  Reset UART handle states.
  * @param  __HANDLE__ UART handle.
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                       (__HANDLE__)->MspInitCallback = NULL;             \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \
                                                     } while(0U)
#else
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                     } while(0U)
#endif /*USE_HAL_UART_REGISTER_CALLBACKS */

/** @brief  Clear receiver line status.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_IT_CLEAR_LS(__HANDLE__) (READ_REG((__HANDLE__)->Instance->LSR))

/** @brief  Clear receiver data available.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_IT_CLEAR_RA(__HANDLE__) (READ_REG((__HANDLE__)->Instance->RBR_THR_DLL))

/** @brief  Clear character timeout indication.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_IT_CLEAR_TO(__HANDLE__) (READ_REG((__HANDLE__)->Instance->RBR_THR_DLL))

/** @brief  Clear transmit holding register empty.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_IT_CLEAR_TE(__HANDLE__) (READ_REG((__HANDLE__)->Instance->IIR_FCR))

/** @brief  Clear modem status.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_IT_CLEAR_MS(__HANDLE__) (READ_REG((__HANDLE__)->Instance->MSR))

/** @brief  Clear busy detect.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_IT_CLEAR_BUSY(__HANDLE__) (READ_REG((__HANDLE__)->Instance->USR))

/** @brief  Get pending interrupt.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval  This parameter can be one of the following values:
  *            @arg @ref UART_IT_MS       UART modem status interrupt, fourth priority   
  *            @arg @ref UART_IT_NO       UART no interrupt pending                      
  *            @arg @ref UART_IT_TE       UART THE empty, third priority                 
  *            @arg @ref UART_IT_RA       UART received data available, second priority  
  *            @arg @ref UART_IT_LS       UART receiver line status, highest priority    
  *            @arg @ref UART_IT_BUSY     UART busy detect, fifth priority               
  *            @arg @ref UART_IT_TO       UART character timeout, second priority        
  */
#define __HAL_UART_GET_IT(__HANDLE__) (((__HANDLE__)->Instance->IIR_FCR))

/** @brief  Enable the specified UART interrupt.
  * @param  __HANDLE__ specifies the UART Handle.
  * @param  __INTERRUPT__ specifies the UART interrupt source to enable.
  *          This parameter can be combined any of the following values:
  *            @arg @ref UART_ENABLEIT_ERBFI                UART enable received data available interrupt         
  *            @arg @ref UART_ENABLEIT_ETBEI                UART enable transmit holding register empty interrupt 
  *            @arg @ref UART_ENABLEIT_ELSI                 UART enable receiver line status interrupt            
  *            @arg @ref UART_ENABLEIT_EDSSI                UART enable modem status interrupt                    
  *            @arg @ref UART_ENABLEIT_PTIME                UART enable programmable THRE interrupt mode          
  *            @arg @ref UART_ENABLEIT_ALL                  UART enable all interrupts                            
  */
#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (SET_BIT((__HANDLE__)->Instance->DLH_IER, __INTERRUPT__)) 

/** @brief  Disable the specified UART interrupt.
  * @param  __HANDLE__ specifies the UART Handle.
  * @param  __INTERRUPT__ specifies the UART interrupt source to disable.
  *          This parameter can be combined any of the following values:
  *            @arg @ref UART_ENABLEIT_ERBFI                UART enable received data available interrupt         
  *            @arg @ref UART_ENABLEIT_ETBEI                UART enable transmit holding register empty interrupt 
  *            @arg @ref UART_ENABLEIT_ELSI                 UART enable receiver line status interrupt            
  *            @arg @ref UART_ENABLEIT_EDSSI                UART enable modem status interrupt                    
  *            @arg @ref UART_ENABLEIT_PTIME                UART enable programmable THRE interrupt mode          
  *            @arg @ref UART_ENABLEIT_ALL                  UART enable all interrupts                            
  */
#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (CLEAR_BIT((__HANDLE__)->Instance->DLH_IER, __INTERRUPT__)) 

/** @brief  Clear interrupt mode starus.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_CLEAR_IT_MODEMSTATUS(__HANDLE__)  (READ_REG((__HANDLE__)->Instance->MSR))

/** @brief  Clear interrupt mode starus.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_CLEAR_IT_UARTSTATUS(__HANDLE__) READ_REG((__HANDLE__)->Instance->USR)

/** @brief  Clear interrupt mode starus.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_CLEAR_IT_TXEMPTY(__HANDLE__) READ_REG((__HANDLE__)->Instance->IIR_FCR)

/** @brief  Clear interrupt mode starus.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_CLEAR_IT_CHARTIMEOUT(__HANDLE__) READ_REG((__HANDLE__)->Instance->RBR_THR_DLL)

/** @brief  Clear interrupt mode starus.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_CLEAR_IT_RXAVAILABLE(__HANDLE__) READ_REG((__HANDLE__)->Instance->RBR_THR_DLL)

/** @brief  Clear interrupt mode starus.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_CLEAR_IT_LINESTATUS(__HANDLE__) READ_REG((__HANDLE__)->Instance->LSR)

/** @brief  GET modem status.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_GET_MS(__HANDLE__) READ_REG((__HANDLE__)->Instance->MSR)

/** @brief  GET lines status.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_GET_MS_FLAG(__HANDLE__, __FLAG__) ((READ_BIT((__HANDLE__)->Instance->MSR, __FLAG__)) ? SET : RESET)

/** @brief  Check modem status.
  * @param  __STATUS__ specifies the UART modem status.
  * @param  __INTERRUPT__ specifies the UART interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref UART_MS_DCTS                   UART delta clear to send                       
  *            @arg @ref UART_MS_DDSR                   UART delta data set ready                      
  *            @arg @ref UART_MS_TERI                   UART trailing edge of ring indicator           
  *            @arg @ref UART_MS_DDCD                   UART dalta data carrier detect                 
  *            @arg @ref UART_MS_CTS                    UART Clear to send                             
  *            @arg @ref UART_MS_DSR                    UART Data set ready                            
  *            @arg @ref UART_MS_RI                     UART ring indicator                            
  *            @arg @ref UART_MS_DCD                     UART data carrier detect                       
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_UART_GET_MS_SOURCE(__STATUS__, __INTERRUPT__) ((__STATUS__ & (__INTERRUPT__ & 0xFF)) ? SET : RESET)

/** @brief  GET lines status.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_GET_LS(__HANDLE__) READ_REG((__HANDLE__)->Instance->LSR)

/** @brief  GET lines status.
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval state (0-0xFF)
  */
#define __HAL_UART_GET_LS_FLAG(__HANDLE__, __FLAG__) ((READ_BIT((__HANDLE__)->Instance->LSR, __FLAG__)) ? SET : RESET)

/** @brief  Check lines status.
  * @param  __STATUS__ specifies the UART modem status.
  * @param  __INTERRUPT__ specifies the UART interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref UART_LS_DR                     UART Data ready bit                            
  *            @arg @ref UART_LS_OE                     UART overrun error bit                         
  *            @arg @ref UART_LS_PE                     UART parity error bit                          
  *            @arg @ref UART_LS_FE                     UART Framing error bit                         
  *            @arg @ref UART_LS_BI                     UART break interrupt bit                       
  *            @arg @ref UART_LS_THRE                   UART transmit holding register empty           
  *            @arg @ref UART_LS_TEMT                   UART transmitter empty bit                     
  *            @arg @ref UART_LS_RFE                    UART receiver FIFO error bit                   
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_UART_GET_LS_SOURCE(__STATUS__, __INTERRUPT__) ((__STATUS__ & (__INTERRUPT__ & 0xFF)) ? SET : RESET)

/** @brief  Check UART status.
  * @param  __HANDLE__ specifies the UART Handle.
  * @param  __FLAG__ specifies the UART interrupt source to check.
  *            @arg @ref UART_STATE_BUSY                UART busy              
  * @retval The new state of __FLAG__ (SET or RESET).
  */
#define __HAL_UART_GET_STATUS(__HANDLE__, __FLAG__) ((READ_BIT((__HANDLE__)->Instance->USR, __FLAG__)) ? SET : RESET)

/** @brief  Set a specific UART request to send.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_SET_RTS(__HANDLE__) (SET_BIT((__HANDLE__)->Instance->MCR, UART_MCR_RTS))

/** @brief  Clear a specific UART request to send.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_CLEAR_RTS(__HANDLE__) (CLEAR_BIT((__HANDLE__)->Instance->MCR, UART_MCR_RTS))

/** @brief  Set a specific UART data terminal ready.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_SET_DTR(__HANDLE__) (SET_BIT((__HANDLE__)->Instance->MCR, UART_MCR_DTR))

/** @brief  Clear a specific UART data terminal ready.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_CLEAR_DTR(__HANDLE__) (CLEAR_BIT((__HANDLE__)->Instance->MCR, UART_MCR_DTR))

/** @brief  Enable CTS flow control.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_HWCONTROL_ENABLE(__HANDLE__)  (SET_BIT((__HANDLE__)->Instance->MCR, UART_MCR_AFCE))

/** @brief  Disable CTS flow control.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_HWCONTROL_DISABLE(__HANDLE__)  (CLEAR_BIT((__HANDLE__)->Instance->MCR, UART_MCR_AFCE))

/** @brief  Clear DMA request.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_CLEAR_DMA_REQ(__HANDLE__)  (SET_BIT((__HANDLE__)->Instance->DMASA, UART_DMASA_DMASA))

/** @brief  enable UART loopback.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_LOOPBACK_ENABLE(__HANDLE__)  (SET_BIT((__HANDLE__)->Instance->MCR, UART_MCR_LB))

/** @brief  disable UART loopback.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_LOOPBACK_DISABLE(__HANDLE__)  (CLEAR_BIT((__HANDLE__)->Instance->MCR, UART_MCR_LB))

/** @brief  enable UART IrDA SIR Mode.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_IRDA_ENABLE(__HANDLE__)  (SET_BIT((__HANDLE__)->Instance->MCR, UART_MCR_SIRE))

/** @brief  disable UART  IrDA SIR Mode.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_IRDA_DISABLE(__HANDLE__)  (CLEAR_BIT((__HANDLE__)->Instance->MCR, UART_MCR_SIRE))

/** @brief  enable UART break.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_BREAK_ENABLE(__HANDLE__)  (SET_BIT((__HANDLE__)->Instance->LCR, UART_LCR_BC))

/** @brief  disable UART break.
  * @param  __HANDLE__ specifies the UART Handle.
  */
#define __HAL_UART_BREAK_DISABLE(__HANDLE__)  (CLEAR_BIT((__HANDLE__)->Instance->LCR, UART_LCR_BC))
/**
  * @}
  */

/* Private macros --------------------------------------------------------*/
/** @defgroup UART_Private_Macros   UART Private Macros
  * @{
  */

/** @brief  Check UART Baud rate.
  * @param  __BAUDRATE__ Baudrate specified by the user.
  *         The maximum Baud Rate is derived from the maximum clock on G0 (i.e. 96 MHz)
  *         divided by the smallest oversampling used on the UART (i.e. 16)
  * @retval SET (__BAUDRATE__ is valid) or RESET (__BAUDRATE__ is invalid)
  */
#define IS_UART_BAUDRATE(__BAUDRATE__) ((__BAUDRATE__) < 6001U)

/**
  * @brief Ensure that UART frame number of stop bits is valid.
  * @param __STOPBITS__ UART frame number of stop bits.
  * @retval SET (__STOPBITS__ is valid) or RESET (__STOPBITS__ is invalid)
  */
#define IS_UART_STOPBITS(__STOPBITS__) (((__STOPBITS__) == UART_STOPBITS_1)   || \
                                        ((__STOPBITS__) == UART_STOPBITS_2))

/**
  * @brief Ensure that UART frame parity is valid.
  * @param __PARITY__ UART frame parity.
  * @retval SET (__PARITY__ is valid) or RESET (__PARITY__ is invalid)
  */
#define IS_UART_PARITY(__PARITY__) (((__PARITY__) == UART_PARITY_NONE) || \
                                    ((__PARITY__) == UART_PARITY_EVEN) || \
                                    ((__PARITY__) == UART_PARITY_ODD))

/**
  * @brief Ensure that UART hardware flow control is valid.
  * @param __CONTROL__ UART hardware flow control.
  * @retval SET (__CONTROL__ is valid) or RESET (__CONTROL__ is invalid)
  */
#define IS_UART_HARDWARE_FLOW_CONTROL(__CONTROL__)\
  (((__CONTROL__) == UART_HWCONTROL_NONE) || \
   ((__CONTROL__) == UART_HWCONTROL_ENABLE))

/**
  * @brief Ensure that UART DMA mode is valid.
  * @param __DMAM__ UART DMA mode.
  * @retval SET (__DMAM__ is valid) or RESET (__DMAM__ is invalid)
  */
#define IS_UART_DMA_MODE(__DMAM__)     (((__DMAM__) == UART_DMA_MODE_0) || \
                                        ((__DMAM__) == UART_DMA_MODE_1))

/**
  * @brief Ensure that UART frame length is valid.
  * @param __LENGTH__ UART frame length.
  * @retval SET (__LENGTH__ is valid) or RESET (__LENGTH__ is invalid)
  */
#define IS_UART_WORD_LENGTH(__LENGTH__) (((__LENGTH__) == UART_WORDLENGTH_5) || \
                                         ((__LENGTH__) == UART_WORDLENGTH_6) || \
                                         ((__LENGTH__) == UART_WORDLENGTH_7) || \
                                         ((__LENGTH__) == UART_WORDLENGTH_8))

/**
  * @brief Ensure that UART loopback is valid.
  * @param __LB__ UART loopback.
  * @retval SET (__LB__ is valid) or RESET (__LENGTH__ is invalid)
  */
#define IS_UART_LOOPBACK(__LB__)        (((__LB__) == UART_LOOPBACK_DISABLE) || \
                                         ((__LB__) == UART_LOOPBACK_ENABLE))
/**
  * @brief Ensure that UART TXFIFO threshold level is valid.
  * @param __THRESHOLD__ UART TXFIFO threshold level.
  * @retval SET (__THRESHOLD__ is valid) or RESET (__THRESHOLD__ is invalid)
  */
#define IS_UART_TXFIFO_THRESHOLD(__THRESHOLD__) (((__THRESHOLD__) == UART_TXFIFO_THRESHOLD_EMPTY) || \
                                                 ((__THRESHOLD__) == UART_TXFIFO_THRESHOLD_2CHAR) || \
                                                 ((__THRESHOLD__) == UART_TXFIFO_THRESHOLD_1_4) || \
                                                 ((__THRESHOLD__) == UART_TXFIFO_THRESHOLD_1_2))

/**
  * @brief Ensure that UART RXFIFO threshold level is valid.
  * @param __THRESHOLD__ UART RXFIFO threshold level.
  * @retval SET (__THRESHOLD__ is valid) or RESET (__THRESHOLD__ is invalid)
  */
#define IS_UART_RXFIFO_THRESHOLD(__THRESHOLD__) (((__THRESHOLD__) == UART_RXFIFO_THRESHOLD_1CHAR) || \
                                                 ((__THRESHOLD__) == UART_RXFIFO_THRESHOLD_1_4) || \
                                                 ((__THRESHOLD__) == UART_RXFIFO_THRESHOLD_1_2) || \
                                                 ((__THRESHOLD__) == UART_RXFIFO_THRESHOLD_2FULL))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup UART_Exported_Functions UART Exported Functions
  * @{
  */

/** @addtogroup UART_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

HAL_StatusTypeDef HAL_UART_DMAHSIFConfig(UART_HandleTypeDef *huart, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx, 
                                         uint32_t rxif, uint32_t txif, uint32_t rxifcfg, uint32_t txifcfg);
HAL_StatusTypeDef HAL_UART_LinkDMA(UART_HandleTypeDef *huart, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID,
                                            pUART_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID);

HAL_StatusTypeDef HAL_UART_RegisterRxEventCallback(UART_HandleTypeDef *huart, pUART_RxEventCallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_UART_UnRegisterRxEventCallback(UART_HandleTypeDef *huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group2 IO operation functions
  * @{
  */

/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_TransmitReceive(UART_HandleTypeDef *huart, uint8_t *pTxData, uint16_t TxSize, uint8_t *pRxData, uint16_t RxSize, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_TransmitReceive_IT(UART_HandleTypeDef *huart, uint8_t *pTxData, uint16_t TxSize, uint8_t *pRxData, uint16_t RxSize);
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_TransmitReceive_DMA(UART_HandleTypeDef *huart, uint8_t *pTxData, uint16_t TxSize, uint8_t *pRxData, uint16_t RxSize);
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

/* Transfer Abort functions */
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxBlockCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxBlockCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);

void HAL_UART_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group3 FIFO Control functions
  * @{
  */
void HAL_UART_RxFifoFullCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxFifoEmptyCallback(UART_HandleTypeDef *huart);

HAL_StatusTypeDef HAL_UART_EnableFifoMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DisableFifoMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_SetTxFifoThreshold(UART_HandleTypeDef *huart, uint32_t Threshold);
HAL_StatusTypeDef HAL_UART_SetRxFifoThreshold(UART_HandleTypeDef *huart, uint32_t Threshold);

HAL_StatusTypeDef HAL_UART_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive_IT_MatchChar(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint8_t Char);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group4 Peripheral State and Error functions
  * @{
  */

/* Peripheral State and Errors functions  **************************************************/
HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart);
uint32_t              HAL_UART_GetError(UART_HandleTypeDef *huart);

/**
  * @}
  */

/**
  * @}
  */

/* Private functions -----------------------------------------------------------*/
/** @addtogroup UART_Private_Functions UART Private Functions
  * @{
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
void              UART_InitCallbacksToDefault(UART_HandleTypeDef *huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
HAL_StatusTypeDef UART_SetConfig(UART_HandleTypeDef *huart);
HAL_StatusTypeDef UART_CheckIdleState(UART_HandleTypeDef *huart);

HAL_StatusTypeDef UART_WaitOnModemStatusUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout);
HAL_StatusTypeDef UART_WaitOnLineStatusUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout);
HAL_StatusTypeDef UART_WaitOnUartStatusUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout);


HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

/* for autodetect */
HAL_StatusTypeDef UART_SetBaudRate(UART_HandleTypeDef *huart,uint32_t Baudrate);
HAL_StatusTypeDef UART_Detect_BaudRate(UART_HandleTypeDef *huart, uint32_t *pBaudRate);
HAL_StatusTypeDef UART_Detect_BaudRateComplete(UART_HandleTypeDef *huart);
/**
  * @}
  */

/* Private variables -----------------------------------------------------------*/
/** @defgroup UART_Private_variables UART Private variables
  * @{
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

#endif /* XT32H0xx_HAL_UART_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
