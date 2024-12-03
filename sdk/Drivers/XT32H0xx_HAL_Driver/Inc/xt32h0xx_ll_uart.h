/**
  ******************************************************************************
  * @file    xt32h0xx_ll_uart.h
  * @author  Software Team
  * @brief   Header file of UART LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_UART_H
#define XT32H0xx_LL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (UART1) || defined (UART2) || defined (UART3) || defined (UART4) 

/** @defgroup UART_LL UART
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup UART_LL_Private_Macros UART Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
/** @defgroup UART_LL_Exported_Types UART Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup UART_LL_ES_INIT UART Exported Init structures
  * @{
  */

/**
  * @brief LL UART Init Structure definition
  */
typedef struct
{
  uint32_t Divisor;                   /*!< This field defines expected Usart communication baud rate.

                                           This feature can be modified afterwards using unitary
                                           function @ref LL_UART_SetDivisor().*/

  uint32_t DataWidth;                 /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref UART_LL_EC_DLS.

                                           This feature can be modified afterwards using unitary
                                           function @ref LL_UART_SetDataWidth().*/

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref UART_LL_EC_STOPBIT.

                                           This feature can be modified afterwards using unitary
                                           function @ref LL_UART_SetStopBit().*/

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref UART_LL_EC_PARITY.

                                           This feature can be modified afterwards using unitary
                                           function @ref LL_UART_SetParity().*/

  uint32_t AutoFlowControl;           /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                           This parameter can be a value of @ref UART_LL_EC_AUTOFLOWCONTROL.

                                           This feature can be modified afterwards using unitary
                                           function @ref LL_UART_EnableAutoFlowControl().*/

} LL_UART_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup UART_LL_Exported_Constants USART Exported Constants
  * @{
  */
/** @defgroup UART_LL_EC_IT_EN Interrupt enable defines
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_IT_ERBFI               (UART_DLH_IER_ERBFI)                    /*!< Enable received data available */
#define LL_UART_IT_ETBEI               (UART_DLH_IER_ETBEI)                    /*!< Enable transmit holding register empty */
#define LL_UART_IT_ELSI                (UART_DLH_IER_ELSI)                     /*!< Enable receiver line status */
#define LL_UART_IT_EDSSI               (UART_DLH_IER_EDSSI)                    /*!< Enable modem status */
#define LL_UART_IT_PTIME               (UART_DLH_IER_PTIME)                    /*!< Programmable THRE interrupt mode Enable */
/**
  * @}
  */

/** @defgroup UART_LL_EC_IT_ID Interrupt ID Defines
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_IT_ID_MODEM            (0x0UL)                                 /*!< Modem status */
#define LL_UART_IT_ID_NOITPENDING      (UART_IIR_FCR_IID_0)                    /*!< No interrupt pending */
#define LL_UART_IT_ID_THRE             (UART_IIR_FCR_IID_1)                    /*!< THR empty */
#define LL_UART_IT_ID_RXAV             (UART_IIR_FCR_IID_2)                    /*!< Received data available */
#define LL_UART_IT_ID_RXLS             (UART_IIR_FCR_IID_2 | UART_IIR_FCR_IID_1)                                       /*!< Receiver line status */
#define LL_UART_IT_ID_BUSY             (UART_IIR_FCR_IID_2 | UART_IIR_FCR_IID_1 | UART_IIR_FCR_IID_0)                  /*!< Busy detect */
#define LL_UART_IT_ID_CHTO             (UART_IIR_FCR_IID_3 | UART_IIR_FCR_IID_2)                                       /*!< Character timeout */
/**
  * @}
  */

/** @defgroup UART_LL_EC_FIFO_EN FIFO enable
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_FIFO_DISABLE           (0)                                     /*!< Modem status */
#define LL_UART_FIFO_ENABLE            (UART_IIR_FCR_FIFOSEs)                  /*!< No interrupt pending */
/**
  * @}
  */

/** @defgroup UART_LL_EC_RFIFO_TRIGGER Rx FIFO trigger level
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_RCVR_1CHAR             (0x0UL)                                         /*!< 1 character in the FIFO */
#define LL_UART_RCVR_QFULL             (UART_IIR_FCR_RCVR_0)                           /*!< FIFO 1/4 FULL */
#define LL_UART_RCVR_HFULL             (UART_IIR_FCR_RCVR_1)                           /*!< FIFO 1/4 FULL */
#define LL_UART_RCVR_2LESSF            (UART_IIR_FCR_RCVR_1 | UART_IIR_FCR_RCVR_0)     /*!< FIFO 2 less than FULL */
/**
  * @}
  */

/** @defgroup UART_LL_EC_TFIFO_TRIGGER Tx FIFO trigger level
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_TET_EMPTY              (0x0UL)                                         /*!< FIFO empty */
#define LL_UART_TET_2CHAR              (UART_IIR_FCR_TET_0)                            /*!< 2 characters in the FIFO */
#define LL_UART_TET_QFULL              (UART_IIR_FCR_TET_1)                            /*!< FIFO 1/4 FULL */
#define LL_UART_TET_HFULL              (UART_IIR_FCR_TET_1 | UART_IIR_FCR_TET_0)       /*!< FIFO 1/2 FULL */
/**
  * @}
  */

/** @defgroup UART_LL_EC_DMA_MODE Tx FIFO trigger level
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_DMAM_0                 (0x0UL)                                 /*!< DMA single mode */
#define LL_UART_DMAM_1                 (UART_IIR_FCR_DMAM)                     /*!< DMA burst mode */
/**
  * @}
  */

/** @defgroup UART_LL_EC_STOPBIT Stop bit
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_STOPBIT_1              (0x0UL)                                 /*!< Stop bit 1 */
#define LL_UART_STOPBIT_2              (UART_LCR_STOP)                         /*!< Stop bit 1.5 (DLS == 0) or 2 */
/**
  * @}
  */

/** @defgroup UART_LL_EC_DLS Data Length Defines
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_DLS_5                  (0x0UL)                                 /*!< Data length 5 bit */
#define LL_UART_DLS_6                  (UART_LCR_DLS_0)                        /*!< Data length 6 bit */
#define LL_UART_DLS_7                  (UART_LCR_DLS_1)                        /*!< Data length 7 bit */
#define LL_UART_DLS_8                  (UART_LCR_DLS_0 | UART_LCR_DLS_1)       /*!< Data length 8 bit */
/**
  * @}
  */

/** @defgroup UART_LL_EC_LINE_STATUS Uart Line Status
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_LSR_DR                 (UART_LSR_DR)                           /*!< Data ready */
#define LL_UART_LSR_OE                 (UART_LSR_OE)                           /*!< Overrun error */
#define LL_UART_LSR_PE                 (UART_LSR_PE)                           /*!< Parity error */
#define LL_UART_LSR_FE                 (UART_LSR_FE)                           /*!< Framing error */
#define LL_UART_LSR_BI                 (UART_LSR_BI)                           /*!< Break interrupt error */
#define LL_UART_LSR_THRE               (UART_LSR_THRE)                         /*!< Transmit holding register empty error */
#define LL_UART_LSR_TEMT               (UART_LSR_TEMT)                         /*!< Transmitter empty */
#define LL_UART_LSR_RFE                (UART_LSR_RFE)                          /*!< Receiver FIFO error */
/**
  * @}
  */

/** @defgroup UART_LL_EC_MODEM_STATUS Uart Modem Status
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_MSR_DCTS               (UART_MSR_DCTS)                         /*!< Delta clear to send */
#define LL_UART_MSR_DDSR               (UART_MSR_DDSR)                         /*!< Delta data set ready */
#define LL_UART_MSR_TERI               (UART_MSR_TERI)                         /*!< Trailing edge of ring indicator */
#define LL_UART_MSR_DDCD               (UART_MSR_DDCD)                         /*!< Delta data carrier detect */
#define LL_UART_MSR_TCS                (UART_MSR_CTS)                          /*!< Clear to send */
#define LL_UART_MSR_DSR                (UART_MSR_DSR)                          /*!< Data set ready */
#define LL_UART_MSR_RI                 (UART_MSR_RI)                           /*!< Ring indicator */
#define LL_UART_MSR_DCD                (UART_MSR_DCD)                          /*!< Data carrier detect */
/**
  * @}
  */

/** @defgroup UART_LL_EC_STATUS Uart Status
  * @brief    Flags defines which can be used with LL_UART_WriteReg function
  * @{
  */
#define LL_UART_USR_BUSY               (UART_USR_BUSY)                         /*!< UART busy */
/**
  * @}
  */

/** @defgroup UART_LL_EC_PARITY Parity Control
  * @{
  */
#define LL_UART_PARITY_NONE            (0x00000000U)                           /*!< Parity control disabled */
#define LL_UART_PARITY_EVEN            (UART_LCR_PEN | UART_LCR_EPS)           /*!< Parity control enabled and Even Parity is selected */
#define LL_UART_PARITY_ODD             (UART_LCR_PEN)                          /*!< Parity control enabled and Odd Parity is selected */

/** @defgroup UART_LL_EC_AUTOFLOWCONTROL Auto Flow Control
  * @{
  */
#define LL_UART_AUTOFLOWCTRL_DISABLE   (0x00000000U)                           /*!< Auto flow control disabled */
#define LL_UART_AUTOFLOWCTRL_ENABLE    (UART_MCR_AFCE)                         /*!< Auto flow control enabled  */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup UART_LL_Exported_Macros USART Exported Macros
  * @{
  */

/** @defgroup UART_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in USART register
  * @param  __INSTANCE__ USART Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_UART_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in USART register
  * @param  __INSTANCE__ USART Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_UART_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup UART_LL_Exported_Functions UART Exported Functions
  * @{
  */

/** @defgroup UART_LL_EF_Configuration Configuration functions
  * @{
  */

/**
  * @brief  FIFO Mode Enable
  * @rmtoll FCR          FIFOE        LL_UART_EnableFIFO
  * @param  UARTx USART Instance
  */
__STATIC_INLINE void LL_UART_EnableFIFO(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->IIR_FCR, UART_IIR_FCR_FIFOE);
}

/**
  * @brief  FIFO Mode Disable
  * @rmtoll FCR          FIFOE        LL_UART_DisableFIFO
  * @param  UARTx USART Instance
  */
__STATIC_INLINE void LL_UART_DisableFIFO(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->IIR_FCR, UART_IIR_FCR_FIFOE);
}

/**
  * @brief  Indicate if FIFO Mode is enabled
  * @rmtoll IIR          FIFOSE        LL_UART_IsEnabledFIFO
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledFIFO(UART_TypeDef *UARTx)
{
  return ((READ_BIT(UARTx->IIR_FCR, UART_IIR_FCR_FIFOSE) == (UART_IIR_FCR_FIFOSE)) ? 1UL : 0UL);
}

/**
  * @brief  Configure TX FIFO Threshold
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll FCR          TET       LL_UART_SetTXFIFOThreshold
  * @param  UARTx UART Instance
  * @param  Threshold This parameter can be one of the following values:
  *         @arg @ref LL_UART_TET_EMPTY               
  *         @arg @ref LL_UART_TET_2CHAR               
  *         @arg @ref LL_UART_TET_QFULL               
  *         @arg @ref LL_UART_TET_HFULL               
  */
__STATIC_INLINE void LL_UART_SetTXFIFOThreshold(UART_TypeDef *UARTx, uint32_t Threshold)
{
  MODIFY_REG(UARTx->IIR_FCR, UART_IIR_FCR_TET, Threshold);
}

/**
  * @brief  Configure RX FIFO Threshold
  * @note   Macro IS_UART_FIFO_INSTANCE(USARTx) can be used to check whether or not
  *         FIFO mode feature is supported by the USARTx instance.
  * @rmtoll FCR          RCVR       LL_UART_SetTXFIFOThreshold
  * @param  UARTx UART Instance
  * @param  Threshold This parameter can be one of the following values:
  *         @arg @ref LL_UART_RCVR_1CHAR               
  *         @arg @ref LL_UART_RCVR_QFULL               
  *         @arg @ref LL_UART_RCVR_HFULL               
  *         @arg @ref LL_UART_RCVR_2LESSF               
  */
__STATIC_INLINE void LL_UART_SetRXFIFOThreshold(UART_TypeDef *UARTx, uint32_t Threshold)
{
  MODIFY_REG(UARTx->IIR_FCR, UART_IIR_FCR_RCVR, Threshold);
}

/**
  * @brief  Configure TX and RX FIFOs Threshold
  * @rmtoll FCR          TET        LL_UART_ConfigFIFOsThreshold\n
  *         FCR          RCVR       LL_UART_ConfigFIFOsThreshold
  * @param  UARTx UART Instance
  * @param  TXThreshold This parameter can be one of the following values:
  *         @arg @ref LL_UART_TET_EMPTY               
  *         @arg @ref LL_UART_TET_2CHAR               
  *         @arg @ref LL_UART_TET_QFULL               
  *         @arg @ref LL_UART_TET_HFULL               
  * @param  RXThreshold This parameter can be one of the following values:
  *         @arg @ref LL_UART_RCVR_1CHAR   
  *         @arg @ref LL_UART_RCVR_QFULL   
  *         @arg @ref LL_UART_RCVR_HFULL   
  *         @arg @ref LL_UART_RCVR_2LESSF  
  */
__STATIC_INLINE void LL_UART_ConfigFIFOsThreshold(UART_TypeDef *UARTx, uint32_t TXThreshold, uint32_t RXThreshold)
{
  MODIFY_REG(UARTx->IIR_FCR, UART_IIR_FCR_TET | UART_IIR_FCR_RCVR, (TXThreshold | RXThreshold));
}

/**
  * @brief  Configure Parity (enabled/disabled and parity mode if enabled).
  * @rmtoll LCR          EPS            LL_UART_SetParity\n
  *         LCR          PEN            LL_UART_SetParity
  * @param  UARTx UART Instance
  * @param  Parity This parameter can be one of the following values:
  *         @arg @ref LL_UART_PARITY_NONE
  *         @arg @ref LL_UART_PARITY_EVEN
  *         @arg @ref LL_UART_PARITY_ODD
  */
__STATIC_INLINE void LL_UART_SetParity(UART_TypeDef *UARTx, uint32_t Parity)
{
  MODIFY_REG(UARTx->LCR, UART_LCR_PEN | UART_LCR_EPS, Parity);
}

/**
  * @brief  Return Parity configuration (enabled/disabled and parity mode if enabled)
  * @rmtoll LCR          EPS           LL_UART_GetParity\n
  *         LCR          PEN           LL_UART_GetParity
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_PARITY_NONE
  *         @arg @ref LL_UART_PARITY_EVEN
  *         @arg @ref LL_UART_PARITY_ODD
  */
__STATIC_INLINE uint32_t LL_UART_GetParity(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->LCR, UART_LCR_PEN | UART_LCR_EPS));
}

/**
  * @brief  Set Word length (i.e. nb of data bits, excluding start and stop bits)
  * @rmtoll LCR          DLS           LL_USART_SetDataWidth
  * @param  UARTx UART Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref LL_UART_DLS_5
  *         @arg @ref LL_UART_DLS_6
  *         @arg @ref LL_UART_DLS_7
  *         @arg @ref LL_UART_DLS_8
  */
__STATIC_INLINE void LL_UART_SetDataWidth(UART_TypeDef *UARTx, uint32_t DataWidth)
{
  MODIFY_REG(UARTx->LCR, UART_LCR_DLS, DataWidth);
}

/**
  * @brief  Return Word length (i.e. nb of data bits, excluding start and stop bits)
  * @rmtoll LCR          DLS            LL_UART_GetDataWidth
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_DLS_5
  *         @arg @ref LL_UART_DLS_6
  *         @arg @ref LL_UART_DLS_7
  *         @arg @ref LL_UART_DLS_8
  */
__STATIC_INLINE uint32_t LL_UART_GetDataWidth(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->LCR, UART_LCR_DLS));
}

/**
  * @brief  Configure Clock source divisor for baudrate generator
  * @note the baud rate = (serial clock frequency)/(16*divisor)
  *       Dicisor is 0, baud clock is disabled.  
  * @rmtoll DLL          DLL     LL_UART_SetDivisor\n
  *         DLH          DLH     LL_UART_SetDivisor\n
  *         LCR          DLAB      LL_UART_SetDivisor
  * @param  UARTx UART Instance
  * @param  Divisor This parameter can be between 0 to 0xFFFF
  */
__STATIC_INLINE void LL_UART_SetDivisor(UART_TypeDef *UARTx, uint32_t Divisor)
{
  SET_BIT(UARTx->LCR, UART_LCR_DLAB);
  MODIFY_REG(UARTx->RBR_THR_DLL, UART_RBR_THR_DLL_DLL, (Divisor & UART_RBR_THR_DLL_DLL));
  MODIFY_REG(UARTx->DLH_IER, UART_DLH_IER_DLH, ((Divisor >> 8) & UART_DLH_IER_DLH));
  CLEAR_BIT(UARTx->LCR, UART_LCR_DLAB);
}

/**
  * @brief  Retrieve the Clock source prescaler for baudrate generator
  * @rmtoll DLL          DLL     LL_UART_GetDivisor\n
  *         DLH          DLH     LL_UART_GetDivisor\n
  *         LCR          DLAB      LL_UART_GetDivisor
  * @param  UARTx UART Instance
  * @retval Returned value can be between 0 to 0xFFFF
  */
__STATIC_INLINE uint32_t LL_UART_GetDivisor(UART_TypeDef *UARTx)
{
  uint32_t div = 0;
  SET_BIT(UARTx->LCR, UART_LCR_DLAB);
  div =  (uint32_t)(READ_BIT(UARTx->DLH_IER, UART_DLH_IER_DLH));
  div <<= 8;
  div += (uint32_t)(READ_BIT(UARTx->RBR_THR_DLL, UART_RBR_THR_DLL_DLL));
  CLEAR_BIT(UARTx->LCR, UART_LCR_DLAB);
  return div;
}

/**
  * @brief  UART set STOP bit.
  * @rmtoll LCR          STOP          LL_UART_SetStopBit
  * @param  UARTx UART Instance
  * @param  Stop This parameter can be one of the following values:
  *         @arg @ref LL_UART_STOPBIT_1                   
  *         @arg @ref LL_UART_STOPBIT_2                   
  */
__STATIC_INLINE void LL_UART_SetStopBit(UART_TypeDef *UARTx, uint32_t Stop)
{
  MODIFY_REG(UARTx->LCR, UART_LCR_STOP, Stop);
}

/**
  * @brief  Retrieve the length of the stop bits
  * @rmtoll LCR          STOP          LL_UART_GetStopBit
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_UART_STOPBIT_1                   
  *         @arg @ref LL_UART_STOPBIT_2                   
  */
__STATIC_INLINE uint32_t LL_UART_GetStopBit(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->LCR, UART_LCR_STOP));
}

/**
  * @brief  Configure Character frame format (Datawidth, Parity control, Stop Bits)
  * @rmtoll LCR          DLS            LL_UART_ConfigCharacter\n
  *         LCR          EPS            LL_UART_ConfigCharacter\n
  *         LCR          PEN            LL_UART_ConfigCharacter\n
  *         LCR          STOP           LL_UART_ConfigCharacter
  * @param  UARTx UART Instance
  * @param  DataWidth This parameter can be one of the following values:
  *         @arg @ref LL_UART_DLS_5
  *         @arg @ref LL_UART_DLS_6
  *         @arg @ref LL_UART_DLS_7
  *         @arg @ref LL_UART_DLS_8
  * @param  Parity This parameter can be one of the following values:
  *         @arg @ref LL_UART_PARITY_NONE
  *         @arg @ref LL_UART_PARITY_EVEN
  *         @arg @ref LL_UART_PARITY_ODD
  * @param  StopBits This parameter can be one of the following values:
  *         @arg @ref LL_UART_STOPBIT_1                   
  *         @arg @ref LL_UART_STOPBIT_2                   
  */
__STATIC_INLINE void LL_UART_ConfigCharacter(UART_TypeDef *UARTx, uint32_t DataWidth, uint32_t Parity,
                                              uint32_t StopBits)
{
  MODIFY_REG(UARTx->LCR, UART_LCR_DLS | UART_LCR_STOP | UART_LCR_PEN | UART_LCR_EPS, Parity | DataWidth | StopBits);
}

/**
  * @brief  Configure TX/RX pins loop back setting.
  * @rmtoll MCR          LB          LL_UART_SetTXRXLoop
  * @param  UARTx UART Instance
  * @param  Loop This parameter can be one of the following values:
  *         RESET or SET
  */
__STATIC_INLINE void LL_UART_SetTXRXLoop(UART_TypeDef *UARTx, uint32_t Loop)
{
  MODIFY_REG(UARTx->MCR, UART_MCR_LB, Loop << UART_MCR_LB_Pos);
}

/**
  * @brief  Retrieve TX/RX pins swapping configuration.
  * @rmtoll MCR          LB          LL_UART_GetTXRXLoop
  * @param  UARTx UART Instance
  * @retval Returned value can be one of the following values:
  *         RESET or SET
  */
__STATIC_INLINE uint32_t LL_UART_GetTXRXLoop(UART_TypeDef *UARTx)
{
  return (uint32_t)(READ_BIT(UARTx->MCR, UART_MCR_LB) >> UART_MCR_LB_Pos);
}

/**
  * @brief  Enable auto flow control
  * @rmtoll MCT          AFCE         LL_UART_EnableAutoFlowControl
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_EnableAutoFlowControl(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->MCR, UART_MCR_AFCE);
}

/**
  * @brief  Disable auto flow control
  * @rmtoll MCT          AFCE         LL_UART_DisableAutoFlowControl
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DisableAutoFlowControl(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->MCR, UART_MCR_AFCE);
}

/**
  * @brief  Indicate if auto flow control is enabled
  * @rmtoll MCT          AFCE         LL_UART_IsEnabledAutoFlowControl
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledAutoFlowControl(UART_TypeDef *UARTx)
{
  return ((READ_BIT(UARTx->MCR, UART_MCR_AFCE) == (UART_MCR_AFCE)) ? 1UL : 0UL);
}

/**
  * @brief  Assert RTS (logic 0)
  * @rmtoll MCR          RTS          LL_UART_AssertRTS
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AssertRTS(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->MCR, UART_MCR_RTS);
}

/**
  * @brief  De-assert RTS (logic 1)
  * @rmtoll MCR          RTS          LL_UART_DeassertRTS
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DeassertRTS(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->MCR, UART_MCR_RTS);
}

/**
  * @brief  Assert DTR (logic 0)
  * @rmtoll MCR          DTR          LL_UART_AssertDTR
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AssertDTR(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->MCR, UART_MCR_DTR);
}

/**
  * @brief  De-assert DTR (logic 1)
  * @rmtoll MCR          DTR          LL_UART_DeassertDTR
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DeassertDTR(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->MCR, UART_MCR_DTR);
}

#if 0
/**
  * @brief  Assert OUT1 (logic 0)
  * @rmtoll MCR          OUT1          LL_UART_AssertOUT1
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AssertOUT1(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->MCR, UART_MCR_OUT1);
}

/**
  * @brief  De-assert OUT1 (logic 1)
  * @rmtoll MCR          OUT1          LL_UART_DeassertOUT1
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DeassertOUT1(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->MCR, UART_MCR_OUT1);
}

/**
  * @brief  Assert OUT2 (logic 0)
  * @rmtoll MCR          OUT2          LL_UART_AssertOUT2
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AssertOUT2(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->MCR, UART_MCR_OUT2);
}

/**
  * @brief  De-assert OUT2 (logic 1)
  * @rmtoll MCR          OUT2          LL_UART_DeassertOUT2
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DeassertOUT2(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->MCR, UART_MCR_OUT2);
}
#endif //0
/**
  * @}
  */

/** @defgroup UART_LL_EF_Configuration_IRDA Configuration functions related to Irda feature
  * @{
  */

/**
  * @brief  Enable IrDA mode
  * @rmtoll MCR          SIRE          LL_UART_EnableIrda
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_EnableIrDA(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->MCR, UART_MCR_SIRE);
}

/**
  * @brief  Disable IrDA mode
  * @rmtoll MCR          SIRE          LL_USART_DisableIrda
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DisableIrDA(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->MCR, UART_MCR_SIRE);
}

/**
  * @brief  Indicate if IrDA mode is enabled
  * @rmtoll MCR          SIRE          LL_USART_IsEnabledIrda
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIrDA(UART_TypeDef *UARTx)
{
  return ((READ_BIT(UARTx->MCR, UART_MCR_SIRE) == (UART_MCR_SIRE)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Get Line status and clear line status
  * @rmtoll LSR                      LL_UART_GetLineStatus
  * @param  UARTx UART Instance
  * @retval the value is combine of the following values:
  *         @arg @ref LL_UART_LSR_DR                      
  *         @arg @ref LL_UART_LSR_OE                      
  *         @arg @ref LL_UART_LSR_PE                      
  *         @arg @ref LL_UART_LSR_FE                      
  *         @arg @ref LL_UART_LSR_BI                      
  *         @arg @ref LL_UART_LSR_THRE                    
  *         @arg @ref LL_UART_LSR_TEMT                    
  *         @arg @ref LL_UART_LSR_RFE                     
  */
__STATIC_INLINE uint32_t LL_UART_GetLineStatus(UART_TypeDef *UARTx)
{
  return ((uint32_t)(READ_REG(UARTx->LSR)));
}

/**
  * @brief  Get modem status and clear line status
  * @rmtoll MSR                      LL_UART_GetModemStatus
  * @param  UARTx UART Instance
  * @retval the value is combine of the following values:
  *         @arg @ref LL_UART_MSR_DCTS 
  *         @arg @ref LL_UART_MSR_DDSR 
  *         @arg @ref LL_UART_MSR_TERI 
  *         @arg @ref LL_UART_MSR_DDCD 
  *         @arg @ref LL_UART_MSR_TCS  
  *         @arg @ref LL_UART_MSR_DSR  
  *         @arg @ref LL_UART_MSR_RI   
  *         @arg @ref LL_UART_MSR_DCD  
  */
__STATIC_INLINE uint32_t LL_UART_GetModemStatus(UART_TypeDef *UARTx)
{
  return ((uint32_t)(READ_REG(UARTx->MSR)));
}

/**
  * @brief  Check if the UART is busy
  * @rmtoll USR          BUST          LL_UART_IsBusy
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsBusy(UART_TypeDef *UARTx)
{
  return ((READ_BIT(UARTx->USR, UART_USR_BUSY) == (UART_USR_BUSY)) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup USART_LL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  Enable received data available Interrupt
  * @rmtoll IER          ERBFI        LL_UART_EnableIT_ReceviedDataAvailable
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_EnableIT_ReceviedDataAvailable(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->DLH_IER, UART_DLH_IER_ERBFI);
}

/**
  * @brief  Enable transmit holding register empty Interrupt
  * @rmtoll IER          ETBEI       LL_UART_EnableIT_TransmitHoldingRegisterEmpty
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_EnableIT_TransmitHoldingRegisterEmpty(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->DLH_IER, UART_DLH_IER_ETBEI);
}

/**
  * @brief  Enable receiver line status Interrupt
  * @rmtoll IER          ELSI          LL_UART_EnableIT_ReceiverLineStatus
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_EnableIT_ReceiverLineStatus(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->DLH_IER, UART_DLH_IER_ELSI);
}

/**
  * @brief  Enable modem status Interrupt
  * @rmtoll IER          EDSSI          LL_UART_EnableIT_ModemStatus
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_EnableIT_ModemStatus(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->DLH_IER, UART_DLH_IER_EDSSI);
}

/**
  * @brief  Enable programmable THRE Interrupt
  * @rmtoll IER         PTIME  LL_UART_EnableIT_Ptime
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_EnableIT_Ptime(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->DLH_IER, UART_DLH_IER_PTIME);
}

/**
  * @brief  Disable received data available Interrupt
  * @rmtoll IER          ERBFI        LL_UART_DisableIT_ReceviedDataAvailable
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DisableIT_ReceviedDataAvailable(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->DLH_IER, UART_DLH_IER_ERBFI);
}

/**
  * @brief  Disable transmit holding register empty Interrupt
  * @rmtoll IER          ETBEI       LL_UART_DisableIT_TransmitHoldingRegisterEmpty
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DisableIT_TransmitHoldingRegisterEmpty(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->DLH_IER, UART_DLH_IER_ETBEI);
}

/**
  * @brief  Disable receiver line status Interrupt
  * @rmtoll IER          ELSI          LL_UART_DisableIT_ReceiverLineStatus
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DisableIT_ReceiverLineStatus(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->DLH_IER, UART_DLH_IER_ELSI);
}

/**
  * @brief  Disable modem status Interrupt
  * @rmtoll IER          EDSSI          LL_UART_DisableIT_ModemStatus
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DisableIT_ModemStatus(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->DLH_IER, UART_DLH_IER_EDSSI);
}

/**
  * @brief  Disable programmable THRE Interrupt
  * @rmtoll IER         PTIME  LL_UART_DisableIT_Ptime
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_DisableIT_Ptime(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->DLH_IER, UART_DLH_IER_PTIME);
}

/**
  * @brief  Check if the received data available Interrupt
  * @rmtoll IER          ERBFI        LL_UART_IsEnabledIT_ReceviedDataAvailable
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_ReceviedDataAvailable(UART_TypeDef *UARTx)
{
  return (uint32_t)((READ_BIT(UARTx->DLH_IER, UART_DLH_IER_ERBFI) == UART_DLH_IER_ERBFI) ? 1UL : 0UL);
}

/**
  * @brief  Check if the transmit holding register empty Interrupt
  * @rmtoll IER          ETBEI       LL_UART_IsEnabledIT_TransmitHoldingRegisterEmpty
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_TransmitHoldingRegisterEmpty(UART_TypeDef *UARTx)
{
  return (uint32_t)((READ_BIT(UARTx->DLH_IER, UART_DLH_IER_ETBEI) == UART_DLH_IER_ETBEI) ? 1UL : 0UL);
}

/**
  * @brief  Check if the receiver line status Interrupt
  * @rmtoll IER          ELSI          LL_UART_IsEnabledIT_ReceiverLineStatus
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_ReceiverLineStatus(UART_TypeDef *UARTx)
{
  return (uint32_t)((READ_BIT(UARTx->DLH_IER, UART_DLH_IER_ELSI) == UART_DLH_IER_ELSI) ? 1UL : 0UL);
}

/**
  * @brief  Check if the modem status Interrupt
  * @rmtoll IER          EDSSI          LL_UART_IsEnabledIT_ModemStatus
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_ModemStatus(UART_TypeDef *UARTx)
{
  return (uint32_t)((READ_BIT(UARTx->DLH_IER, UART_DLH_IER_EDSSI) == UART_DLH_IER_EDSSI) ? 1UL : 0UL);
}

/**
  * @brief  Check if the programmable THRE Interrupt
  * @rmtoll IER         PTIME  LL_UART_IsEnabledIT_Ptime
  * @param  UARTx UART Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_UART_IsEnabledIT_Ptime(UART_TypeDef *UARTx)
{
  return (uint32_t)((READ_BIT(UARTx->DLH_IER, UART_DLH_IER_PTIME) == UART_DLH_IER_PTIME) ? 1UL : 0UL);
}
/**
  * @}
  */

/** @defgroup USART_LL_EF_DMA_Management DMA_Management
  * @{
  */

/**
  * @brief  Set DMA Mode
  * @rmtoll FCR          DMAM          LL_UART_SetDMAMode
  * @param  UARTx UART Instance
  * @param  Mode the value can be one of the following values:
  *         @arg @ref LL_UART_DMAM_0 
  *         @arg @ref LL_UART_DMAM_1 
  */
__STATIC_INLINE void LL_UART_SetDMAMode(UART_TypeDef *UARTx, uint32_t Mode)
{
  MODIFY_REG(UARTx->IIR_FCR, UART_IIR_FCR_DMAM, Mode << UART_IIR_FCR_DMAM_Pos);
}

/**
  * @}
  */

/** @defgroup UART_LL_EF_Data_Management Data_Management
  * @{
  */

/**
  * @brief  Read Receiver Data register (Receive Data value, 8 bits)
  * @rmtoll RBR          RBR           LL_UART_ReceiveData8
  * @param  UARTx UART Instance
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint8_t LL_UART_ReceiveData8(UART_TypeDef *UARTx)
{
  return (uint8_t)(READ_BIT(UARTx->RBR_THR_DLL, UART_RBR_THR_DLL_RBR));
}

/**
  * @brief  Write in Transmitter Data Register (Transmit Data value, 8 bits)
  * @rmtoll THR          THR           LL_UART_TransmitData8
  * @param  UARTx UART Instance
  * @param  Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE void LL_UART_TransmitData8(UART_TypeDef *UARTx, uint8_t Value)
{
  MODIFY_REG(UARTx->RBR_THR_DLL, UART_RBR_THR_DLL_THR, Value);
}
/**
  * @}
  */

/** @defgroup USART_LL_EF_Execution Execution
  * @{
  */

/**
  * @brief  Request Break sending
  * @rmtoll LCR          BC         LL_UART_RequestBreakSending
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_RequestBreakSending(UART_TypeDef *UARTx)
{
  SET_BIT(UARTx->LCR, (uint16_t)UART_LCR_BC);
}

/**
  * @brief  Clear Break sending
  * @rmtoll LCR          BC         LL_UART_ClearBreakSending
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_ClearBreakSending(UART_TypeDef *UARTx)
{
  CLEAR_BIT(UARTx->LCR, (uint16_t)UART_LCR_BC);
}

/**
  * @brief  Check interrupt ID
  * @rmtoll IIR_FCR               LL_UART_CheckIID
  * @param  UARTx UART Instance
  * @param  Iid the value is one of the following values:
  *        @arg @ref LL_UART_IT_ID_MODEM           
  *        @arg @ref LL_UART_IT_ID_NOITPENDING     
  *        @arg @ref LL_UART_IT_ID_THRE            
  *        @arg @ref LL_UART_IT_ID_RXAV            
  *        @arg @ref LL_UART_IT_ID_RXLS            
  *        @arg @ref LL_UART_IT_ID_BUSY            
  *        @arg @ref LL_UART_IT_ID_CHTO            
  * @retval status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_UART_CheckIID(UART_TypeDef *UARTx, uint32_t Iid)
{
  return (READ_BIT(UARTx->IIR_FCR, Iid) ? SET : RESET);
}

#if (defined(XT32H0xxBMPW) || defined(XT32H0xxB))
/**
  * @brief  Enable Auto baud rate detect
  * @rmtoll SYSCFG          UART_ADCFG         LL_UART_AutoBrDetectEnable
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AutoBrDetectEnable(UART_TypeDef *UARTx)
{
  if (UARTx == UART1)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART1_ADCFG_EN);
  }
  else if (UARTx == UART2)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART2_ADCFG_EN);
  }
  else if (UARTx == UART3)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART3_ADCFG_EN);
  }
  else if (UARTx == UART4)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART4_ADCFG_EN);
  }
}

/**
  * @brief  Disable Auto baud rate detect
  * @rmtoll SYSCFG          UART_ADCFG         LL_UART_AutoBrDetectDisable
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AutoBrDetectDisable(UART_TypeDef *UARTx)
{
  if (UARTx == UART1)
  {
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART1_ADCFG_EN);
  }
  else if (UARTx == UART2)
  {
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART2_ADCFG_EN);
  }
  else if (UARTx == UART3)
  {
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART3_ADCFG_EN);
  }
  else if (UARTx == UART4)
  {
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART4_ADCFG_EN);
  }
}

/**
  * @brief  Enable Auto baud rate detect interrupt
  * @rmtoll SYSCFG          UART_ADCFG         LL_UART_AutoBrDetectIntEnable
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AutoBrDetectIntEnable(UART_TypeDef *UARTx)
{
  if (UARTx == UART1)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART1_ADCFG_IE);
  }
  else if (UARTx == UART2)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART2_ADCFG_IE);
  }
  else if (UARTx == UART3)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART3_ADCFG_IE);
  }
  else if (UARTx == UART4)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART4_ADCFG_IE);
  }
}

/**
  * @brief  Disable Auto baud rate detect interrupt
  * @rmtoll SYSCFG          UART_ADCFG         LL_UART_AutoBrDetectIntDisable
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AutoBrDetectIntDisable(UART_TypeDef *UARTx)
{
  if (UARTx == UART1)
  {
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART1_ADCFG_IE);
  }
  else if (UARTx == UART2)
  {
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART2_ADCFG_IE);
  }
  else if (UARTx == UART3)
  {
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART3_ADCFG_IE);
  }
  else if (UARTx == UART4)
  {
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART4_ADCFG_IE);
  }
}

/**
  * @brief  Clear Auto baud rate detect interrupt status
  * @rmtoll SYSCFG          UART_ADCFG         LL_UART_AutoBrDetectIntClear
  * @param  UARTx UART Instance
  */
__STATIC_INLINE void LL_UART_AutoBrDetectIntClear(UART_TypeDef *UARTx)
{
  if (UARTx == UART1)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART1_ADCFG_CLR);
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART1_ADCFG_CLR);
  }
  else if (UARTx == UART2)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART2_ADCFG_CLR);
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART2_ADCFG_CLR);
  }
  else if (UARTx == UART3)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART3_ADCFG_CLR);
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART3_ADCFG_CLR);
  }
  else if (UARTx == UART4)
  {
    SET_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART4_ADCFG_CLR);
    CLEAR_BIT(SYSCFG->UART_ADCFG, SYSCFG_UART4_ADCFG_CLR);
  }
}

/**
  * @brief  cleck Auto baud rate detect status
  * @rmtoll SYSCFG          UART_ADCFG         LL_UART_CheckAutoBrDetectFlag
  * @param  UARTx UART Instance
  * @retval status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_UART_CheckAutoBrDetectFlag(UART_TypeDef *UARTx)
{
  if (UARTx == UART1)
  {
    return (READ_BIT(SYSCFG->UART_ADFLG, SYSCFG_UART1_ADFLG) ? SET : RESET);
  }
  else if (UARTx == UART2)
  {
    return (READ_BIT(SYSCFG->UART_ADFLG, SYSCFG_UART2_ADFLG) ? SET : RESET);
  }
  else if (UARTx == UART3)
  {
    return (READ_BIT(SYSCFG->UART_ADFLG, SYSCFG_UART3_ADFLG) ? SET : RESET);
  }
  else if (UARTx == UART4)
  {
    return (READ_BIT(SYSCFG->UART_ADFLG, SYSCFG_UART4_ADFLG) ? SET : RESET);
  }
	return RESET;
}

/**
  * @brief  cleck Auto baud rate detect status
  * @rmtoll SYSCFG          UART_ADCFG         LL_UART_GetAutoBrDetectResult
  * @param  UARTx UART Instance
  * @retval value of result
  */
__STATIC_INLINE uint32_t LL_UART_GetAutoBrDetectResult(UART_TypeDef *UARTx)
{
  if (UARTx == UART1)
  {
    return (READ_REG(SYSCFG->UART1_ADBR));
  }
  else if (UARTx == UART2)
  {
    return (READ_REG(SYSCFG->UART2_ADBR));
  }
  else if (UARTx == UART3)
  {
    return (READ_REG(SYSCFG->UART3_ADBR));
  }
  else if (UARTx == UART4)
  {
    return (READ_REG(SYSCFG->UART4_ADBR));
  }
	return RESET;
}
#endif /* XT32H0xxBMPW || XT32H0xxB */
/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup UART_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_UART_DeInit(UART_TypeDef *UARTx);
ErrorStatus LL_UART_Init(UART_TypeDef *UARTx, LL_UART_InitTypeDef *UART_InitStruct);
void        LL_UART_StructInit(LL_UART_InitTypeDef *UART_InitStruct);
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

#endif /* UART1 || UART2 || UART3 || UART4 */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_UART_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
