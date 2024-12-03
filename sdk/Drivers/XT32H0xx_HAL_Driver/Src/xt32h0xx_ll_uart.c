/**
  ******************************************************************************
  * @file    xt32h0xx_ll_uart.c
  * @author  Software Team
  * @brief   UART LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_uart.h"
#include "xt32h0xx_ll_rcc.h"
#include "xt32h0xx_ll_bus.h"
#ifdef USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (UART1) || defined (UART2) || defined (UART3) || defined (UART4) 

/** @addtogroup UART_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup USART_LL_Private_Macros
  * @{
  */
#define IS_LL_UART_PARITY(__VALUE__) (((__VALUE__) == LL_UART_PARITY_NONE) \
                                       || ((__VALUE__) == LL_UART_PARITY_EVEN) \
                                       || ((__VALUE__) == LL_UART_PARITY_ODD))

#define IS_LL_UART_DATAWIDTH(__VALUE__) (((__VALUE__) == LL_UART_DLS_5) \
                                          || ((__VALUE__) == LL_UART_DLS_6) \
                                          || ((__VALUE__) == LL_UART_DLS_7) \
                                          || ((__VALUE__) == LL_UART_DLS_8))

#define IS_LL_USART_STOPBITS(__VALUE__) (((__VALUE__) == LL_UART_STOPBIT_1) \
                                         || ((__VALUE__) == LL_UART_STOPBIT_2))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup UART_LL_Exported_Functions
  * @{
  */

/** @addtogroup UART_LL_EF_Init
  * @{
  */

/**
  * @brief  De-initialize UART registers (Registers restored to their default values).
  * @param  UARTx UART Instance
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: UART registers are de-initialized
  *          - ERROR: UART registers are not de-initialized
  */
ErrorStatus LL_UART_DeInit(UART_TypeDef *UARTx)
{
  ErrorStatus status = SUCCESS;

  /* Stop RCC */


  return (status);
}

/**
  * @brief  Initialize UART registers according to the specified
  *         parameters in UART_InitStruct.
  * @param  UARTx UART Instance
  * @param  UART_InitStruct pointer to a LL_UART_InitTypeDef structure
  *         that contains the configuration information for the specified UART peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: UART registers are initialized according to UART_InitStruct content
  *          - ERROR: Problem occurred during UART Registers initialization
  */
ErrorStatus LL_UART_Init(UART_TypeDef *UARTx, LL_UART_InitTypeDef *UART_InitStruct)
{
  ErrorStatus status = ERROR;
//  uint32_t periphclk = LL_RCC_PERIPH_FREQUENCY_NO;
//#if !defined(RCC_CCIPR_USART3SEL)&&!defined(RCC_CCIPR_USART4SEL)||(!defined(RCC_CCIPR_USART2SEL))||!defined(RCC_CCIPR_USART5SEL)||!defined(RCC_CCIPR_USART6SEL)
//  LL_RCC_ClocksTypeDef RCC_Clocks;
//#endif

  /* Check the parameters */
  assert_param(IS_UART_INSTANCE(UARTx));
  assert_param(IS_LL_UART_DATAWIDTH(UART_InitStruct->DataWidth));
  assert_param(IS_LL_UART_STOPBITS(UART_InitStruct->StopBits));
  assert_param(IS_LL_UART_PARITY(UART_InitStruct->Parity));

  /* Disable all interrupts */
  WRITE_REG(UARTx->DLH_IER, 0x00UL);

  /*---------------------------- UART LCR Configuration ---------------------
    * Configure UARTx LCR  (UART Word Length, Parity bits) with parameters:
    * - DataWidth:          UART_LCR_DLS bits according to USART_InitStruct->DataWidth value
    * - StopBits:           UART_LCR_STOP bits according to USART_InitStruct->StopBits value
    * - Parity:             UART_LCR_PEN, UART_LCR_EPS bits according to USART_InitStruct->Parity value
    */
  MODIFY_REG(UARTx->LCR,
              (UART_LCR_DLS | UART_LCR_STOP | UART_LCR_PEN | UART_LCR_EPS),
              (UART_InitStruct->DataWidth | UART_InitStruct->StopBits | UART_InitStruct->Parity));

  /*---------------------------- USART MCR Configuration ---------------------
    * Configure USARTx CR3 (Hardware Flow Control) with parameters:
    * - HardwareFlowControl: USART_CR3_RTSE, USART_CR3_CTSE bits according to
    *   USART_InitStruct->HardwareFlowControl value.
    */
  if(UART_InitStruct->AutoFlowControl)
  {
    LL_UART_EnableAutoFlowControl(UARTx);
  }
  else
  {
    LL_UART_DisableAutoFlowControl(UARTx);
  }

  /*---------------------------- USART DLx Configuration ---------------------
    * Retrieve Clock frequency used for USART Peripheral
    */
  LL_UART_SetDivisor(UARTx, UART_InitStruct->Divisor);

  /* configure FIFO */
  LL_UART_EnableFIFO(UARTx);

  LL_UART_SetTXFIFOThreshold(UARTx, LL_UART_TET_HFULL);
  LL_UART_SetRXFIFOThreshold(UARTx, LL_UART_RCVR_HFULL);

  /* enable IT */
  WRITE_REG(UARTx->DLH_IER, 0xFFUL);

  return (status);
}

/**
  * @brief Set each @ref LL_UART_InitTypeDef field to default value.
  * @param UART_InitStruct pointer to a @ref LL_UART_InitTypeDef structure
  *                         whose fields will be set to default values.
  */

void LL_UART_StructInit(LL_UART_InitTypeDef *UART_InitStruct)
{
  /* Set USART_InitStruct fields to default values */
  UART_InitStruct->Divisor             = 52U;     /* 96M/16/52 = 115200 */
  UART_InitStruct->DataWidth           = LL_UART_DLS_8;
  UART_InitStruct->StopBits            = LL_UART_STOPBIT_1;
  UART_InitStruct->Parity              = LL_UART_PARITY_NONE ;
  UART_InitStruct->AutoFlowControl     = LL_UART_AUTOFLOWCTRL_DISABLE;
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

#endif /* UART1 || UART2 || UART3 || UART4 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

