/**
  ******************************************************************************
  * @file    xt32h0xx_UART.h
  * @author  Software Team
  * @date    28 June 2022
  * @brief   This file contains all the functions prototypes for the UART 
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
#ifndef __XT32H0XX_UART_H
#define __XT32H0XX_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
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
  * @brief  UART Init Structure definition  
  */ 

typedef struct
{
  uint32_t UART_BaudRate;            /*!< This member configures the UART communication baud rate. */

  uint32_t UART_WordLength;          /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref UART_Word_Length */

  uint32_t UART_StopBits;            /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref UART_Stop_Bits */

  uint32_t UART_Parity;              /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref UART_Parity */
 
  uint32_t UART_HardwareFlowControl; /*!< Specifies wether the hardware flow control mode is enabled
                                           or disabled.
                                           This parameter can be a value of @ref UART_Hardware_Flow_Control*/
} UART_InitTypeDef;
/**
  * @}
  */ 

/* Exported constants --------------------------------------------------------*/
/** @defgroup UART_Exported_Constants UART Exported Constants
  * @{
  */ 

/** @defgroup UART_Peripheral_Define UART Peripheral Define 
  * @{
  */ 
#define IS_UART_ALL_PERIPH(PERIPH)  (((PERIPH) == UART1) || \
                                     ((PERIPH) == UART2) || \
                                     ((PERIPH) == UART3) || \
                                     ((PERIPH) == UART4))

#define IS_UART_1_PERIPH(PERIPH) ((PERIPH) == UART1) 
#define IS_UART_2_PERIPH(PERIPH) ((PERIPH) == UART2) 
#define IS_UART_3_PERIPH(PERIPH) ((PERIPH) == UART3) 
#define IS_UART_4_PERIPH(PERIPH) ((PERIPH) == UART4) 
/**
  * @}
  */ 

/** @defgroup UART_Word_Length UART Data Width
  * @{
  */ 

#define UART_DLS_5                     (0x0UL)                                 /*!< Data length 5 bit */
#define UART_DLS_6                     (UART_LCR_DLS_0)                        /*!< Data length 6 bit */
#define UART_DLS_7                     (UART_LCR_DLS_1)                        /*!< Data length 7 bit */
#define UART_DLS_8                     (UART_LCR_DLS_0 | UART_LCR_DLS_1)       /*!< Data length 8 bit */

#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_DLS_5) || \
                                     ((LENGTH) == UART_DLS_6) || \
                                     ((LENGTH) == UART_DLS_7) || \
                                     ((LENGTH) == UART_DLS_8))
/**
  * @}
  */ 

/** @defgroup UART_Stop_Bits UART Stop Bits
  * @{
  */ 
#define UART_STOPBIT_1                 (0)                                     /*!< Stop bit 1 */
#define UART_STOPBIT_2                 (UART_LCR_STOP)                         /*!< Stop bit 1.5 (DLS == 0) or 2 */

#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_STOPBIT_1) || \
                                    ((STOPBITS) == UART_STOPBIT_2))
/**
  * @}
  */ 

/** @defgroup UART_Parity UART Parity
  * @{
  */ 
#define UART_PARITY_NONE               (0x00000000U)                           /*!< No parity   */
#define UART_PARITY_EVEN               (UART_LCR_PEN | UART_LCR_EPS)           /*!< Even parity */
#define UART_PARITY_ODD                (UART_LCR_PEN)                          /*!< Odd parity  */

#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NONE) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_ODD))
/**
  * @}
  */ 

/** @defgroup UART_Hardware_Flow_Control UART Hardware Flow Control
  * @{
  */
#define UART_HWCONTROL_NONE            (0x00000000U)                           /*!< No hardware control       */
#define UART_HWCONTROL_ENABLE          (UART_MCR_AFCE)                         /*!< hardware control enable   */

#define IS_UART_HWFC(FC) (((FC) == UART_HWCONTROL_NONE) || \
                          ((FC) == UART_HWCONTROL_ENABLE))
/**
  * @}
  */

/** @defgroup UART_FIFO_EN FIFO enable
  * @brief    
  * @{
  */
#define UART_FIFO_DISABLE              (0)                                     /*!< Modem status */
#define UART_FIFO_ENABLE               (UART_IIR_FCR_FIFOSE)                   /*!< No interrupt pending */

#define IS_UART_FIFO_ENABLE(FIFO) (((FIFO) == UART_FIFO_DISABLE) || \
                                   ((FIFO) == UART_FIFO_ENABLE))
/**
  * @}
  */

/** @defgroup UART_RFIFO_TRIGGER Rx FIFO trigger level
  * @brief    
  * @{
  */
#define UART_RCVR_1CHAR                (0x0UL)                                         /*!< 1 character in the FIFO */
#define UART_RCVR_QFULL                (UART_IIR_FCR_RCVR_0)                           /*!< FIFO 1/4 FULL */
#define UART_RCVR_HFULL                (UART_IIR_FCR_RCVR_1)                           /*!< FIFO 1/4 FULL */
#define UART_RCVR_2LESSF               (UART_IIR_FCR_RCVR_1 | UART_IIR_FCR_RCVR_0)     /*!< FIFO 2 less than FULL */

#define IS_UART_RFIFO(FIFO)       (((FIFO) == UART_RCVR_1CHAR) || \
                                   ((FIFO) == UART_RCVR_QFULL) || \
                                   ((FIFO) == UART_RCVR_HFULL) || \
                                   ((FIFO) == UART_RCVR_2LESSF))
/**
  * @}
  */

/** @defgroup UART_TFIFO_TRIGGER Tx FIFO trigger level
  * @brief    
  * @{
  */
#define UART_TET_EMPTY                 (0x0UL)                                         /*!< FIFO empty */
#define UART_TET_2CHAR                 (UART_IIR_FCR_TET_0)                            /*!< 2 characters in the FIFO */
#define UART_TET_QFULL                 (UART_IIR_FCR_TET_1)                            /*!< FIFO 1/4 FULL */
#define UART_TET_HFULL                 (UART_IIR_FCR_TET_1 | UART_IIR_FCR_TET_0)       /*!< FIFO 1/2 FULL */

#define IS_UART_TFIFO(FIFO)       (((FIFO) == UART_TET_EMPTY) || \
                                   ((FIFO) == UART_TET_2CHAR) || \
                                   ((FIFO) == UART_TET_QFULL) || \
                                   ((FIFO) == UART_TET_HFULL))
/**
  * @}
  */

/** @defgroup UART_IT_EN Interrupt enable defines
  * @brief    
  * @{
  */
#define UART_IT_ERBFI                  (UART_DLH_IER_ERBFI)                    /*!< Enable received data available */
#define UART_IT_ETBEI                  (UART_DLH_IER_ETBEI)                    /*!< Enable transmit holding register empty */
#define UART_IT_ELSI                   (UART_DLH_IER_ELSI)                     /*!< Enable receiver line status */
#define UART_IT_EDSSI                  (UART_DLH_IER_EDSSI)                    /*!< Enable modem status */
#define UART_IT_PTIME                  (UART_DLH_IER_PTIME)                    /*!< Programmable THRE interrupt mode Enable */

#define IS_UART_IT(IT)  (((IT) == UART_IT_ERBFI) || \
                         ((IT) == UART_IT_ETBEI) || \
                         ((IT) == UART_IT_ELSI) || \
                         ((IT) == UART_IT_EDSSI) || \
                         ((IT) == UART_IT_PTIME))
/**
  * @}
  */

/** @defgroup UART_IT_ID Interrupt ID Defines
  * @brief    
  * @{
  */
#define UART_IT_ID_MODEM               (0x0UL)                                 /*!< Modem status */
#define UART_IT_ID_NOITPENDING         (0x1UL)                                 /*!< No interrupt pending */
#define UART_IT_ID_THRE                (0x2UL)                                 /*!< THR empty */
#define UART_IT_ID_RXAV                (0x4UL)                                 /*!< Received data available */
#define UART_IT_ID_RXLS                (0x6UL)                                 /*!< Receiver line status */
#define UART_IT_ID_BUSY                (0x7UL)                                 /*!< Busy detect */
#define UART_IT_ID_CHTO                (0xCUL)                                 /*!< Character timeout */

#define IS_UART_IT_ID(IT)  (((IT) == UART_IT_ID_MODEM) || \
                           ((IT) == UART_IT_ID_NOITPENDING) || \
                           ((IT) == UART_IT_ID_THRE) || \
                           ((IT) == UART_IT_ID_RXAV) || \
                           ((IT) == UART_IT_ID_RXLS) || \
                           ((IT) == UART_IT_ID_BUSY) || \
                           ((IT) == UART_IT_ID_CHTO))
/**
  * @}
  */

/** @defgroup UART_LINE_STATUS UART Line Status
  * @brief    
  * @{
  */
#define IS_UART_LSR(STATUS)  (((STATUS) == UART_LSR_DR) || \
                              ((STATUS) == UART_LSR_OE) || \
                              ((STATUS) == UART_LSR_PE) || \
                              ((STATUS) == UART_LSR_FE) || \
                              ((STATUS) == UART_LSR_BI) || \
                              ((STATUS) == UART_LSR_THRE) || \
                              ((STATUS) == UART_LSR_TEMT) || \
                              ((STATUS) == UART_LSR_RFE))
/**
  * @}
  */

/** @defgroup UART_MODEM_STATUS UART Modem Status
  * @brief    
  * @{
  */
#define IS_UART_MSR(STATUS)  (((STATUS) == UART_MSR_DCTS) || \
                              ((STATUS) == UART_MSR_DDSR) || \
                              ((STATUS) == UART_MSR_TERI) || \
                              ((STATUS) == UART_MSR_DDCD) || \
                              ((STATUS) == UART_MSR_TCS) || \
                              ((STATUS) == UART_MSR_DSR) || \
                              ((STATUS) == UART_MSR_RI) || \
                              ((STATUS) == UART_MSR_DCD))
/**
  * @}
  */

/** @defgroup UART_STATUS UART Status
  * @brief    
  * @{
  */
#define IS_UART_USR(STATUS)  (((STATUS) == UART_USR_BUSY))
/**
  * @}
  */

/** @defgroup UART_DMA_MODE UART DMA Mode
  * @brief    
  * @{
  */
#define UART_DMAM_SINGLE            (0x0UL)                                 /*!< DMA mode 0 */
#define UART_DMAM_BURST             (UART_IIR_FCR_DMAM)                     /*!< DMA mode 1 */

#define IS_UART_DMAM(MODE) (((MODE) == UART_DMAM_SINGLE) || \
                            ((MODE) == UART_DMAM_BURST))
/**
  * @}
  */

/** @defgroup UART_Global_definition  UART Global Define
  * @{
  */

#define IS_UART_BAUDRATE(BAUDRATE) (((BAUDRATE) > 0) && ((BAUDRATE) < 0x005B8D81))
#define IS_UART_DE_ASSERTION_DEASSERTION_TIME(TIME) ((TIME) <= 0x1F)
#define IS_UART_AUTO_RETRY_COUNTER(COUNTER) ((COUNTER) <= 0x7)
#define IS_UART_TIMEOUT(TIMEOUT) ((TIMEOUT) <= 0x00FFFFFF)
#define IS_UART_DATA(DATA) ((DATA) <= 0xFF)

/**
  * @}
  */ 

/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup UART_Exported_Functions
  * @{
  */

/** @addtogroup UART_Exported_Functions_Group1
  * @{
  */
/* Initialization and Configuration functions *********************************/
void UART_DeInit(UART_TypeDef* UARTx);
void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct);
void UART_StructInit(UART_InitTypeDef* UART_InitStruct);
void UART_SetBaudrate(UART_TypeDef* UARTx, uint32_t UART_Baudrate);

void UART_RxFIFOThresholdConfig(UART_TypeDef* UARTx, uint8_t Threshold);
void UART_TxFIFOThresholdConfig(UART_TypeDef* UARTx, uint8_t Threshold);
void UART_FIFOCmd(UART_TypeDef* UARTx, FunctionalState NewState);
void UART_ResetRxFIFO(UART_TypeDef* UARTx);
void UART_ResetTxFIFO(UART_TypeDef* UARTx);

void UART_ForceBreakCmd(UART_TypeDef* UARTx, FunctionalState NewState);
void UART_LoopBackModeCmd(UART_TypeDef* UARTx, FunctionalState NewState);
void UART_IrDACmd(UART_TypeDef* UARTx, FunctionalState NewState); 
void UART_ModemForceRtsPinState(UART_TypeDef* UARTx, SignalState NewState);
void UART_DMACmd(UART_TypeDef* UARTx, uint32_t UART_DMAMode);
/**
  * @}
  */ 

/** @addtogroup UART_Exported_Functions_Group2
  * @{
  */
/* Data transfers functions ***************************************************/
void UART_SendData(UART_TypeDef* UARTx, uint8_t Data);
uint8_t UART_ReceiveData(UART_TypeDef* UARTx);
/**
  * @}
  */ 

/** @addtogroup UART_Exported_Functions_Group3
  * @{
  */
/* Interrupts and flags management functions **********************************/
void UART_ITConfig(UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState);
uint32_t UART_GetITId(UART_TypeDef* UARTx);

uint32_t UART_GetLineStatus(UART_TypeDef* UARTx);
uint32_t UART_GetModemStatus(UART_TypeDef* UARTx);
uint32_t UART_GetUartStatus(UART_TypeDef* UARTx);
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

#endif /* __XT32H0XX_UART_H */


