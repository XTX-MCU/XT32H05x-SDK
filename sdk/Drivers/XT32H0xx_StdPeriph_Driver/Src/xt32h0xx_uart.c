/**
  ******************************************************************************
  * @file    xt32h0xx_UART.c
  * @author  Software Team
  * @date    28 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Universal asynchronous receiver
  *          transmitter (UART):
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
#include "xt32h0xx_uart.h"
#include "xt32h0xx_rcc.h"
#include "xt32h0xx_syscfg.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup UART UART
  * @brief UART driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup UART_Exported_Functions UART Exported Functions
  * @{
  */

/** @defgroup UART_Exported_Functions_Group1 Initialization and Configuration functions
  * @brief   Initialization and Configuration functions 
  *
  * @{
  */
  
/**
  * @brief  Deinitializes the UARTx peripheral registers to their default reset values.
  * @param  UARTx: where x can be from 1 to 8 to select the UART peripheral.
  */
void UART_DeInit(UART_TypeDef* UARTx)
{
  if(UARTx == UART1)
  {
    SYSCFG_PeripheralReset(SYS_SWRST_UART1);
    SYSCFG_PeripheralResetRelease(SYS_SWRST_UART1);
  }
  else if(UARTx == UART2)
  {
    SYSCFG_PeripheralReset(SYS_SWRST_UART2);
    SYSCFG_PeripheralResetRelease(SYS_SWRST_UART2);
  }
  else if(UARTx == UART3)
  {
    SYSCFG_PeripheralReset(SYS_SWRST_UART3);
    SYSCFG_PeripheralResetRelease(SYS_SWRST_UART3);
  }
  else if(UARTx == UART4)
  {
    SYSCFG_PeripheralReset(SYS_SWRST_UART4);
    SYSCFG_PeripheralResetRelease(SYS_SWRST_UART4);
  }
  else
  {
  
  }
}

/**
  * @brief  Initializes the UARTx peripheral according to the specified
  *         parameters in the UART_InitStruct .
  * @param  UARTx: where x can be from 1 to 8 to select the UART peripheral.
  * @param  UART_InitStruct: pointer to a UART_InitTypeDef structure that contains
  *         the configuration information for the specified UART peripheral.
  */
void UART_Init(UART_TypeDef* UARTx, UART_InitTypeDef* UART_InitStruct)
{
  uint32_t divider = 0, sclk = 0, tmpreg = 0;
  uint32_t wait = 0x00FFFFFF;
  
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_BAUDRATE(UART_InitStruct->UART_BaudRate));  
  assert_param(IS_UART_WORD_LENGTH(UART_InitStruct->UART_WordLength));
  assert_param(IS_UART_STOPBITS(UART_InitStruct->UART_StopBits));
  assert_param(IS_UART_PARITY(UART_InitStruct->UART_Parity));
  assert_param(IS_UART_HWFC(UART_InitStruct->UART_HardwareFlowControl));
  
  /*---------------------------- UART LCR Configuration -----------------------*/
  tmpreg = UARTx->LCR;
  tmpreg &= (uint32_t)~((uint32_t)(UART_LCR_DLS|UART_LCR_STOP|UART_LCR_PEN|UART_LCR_EPS));
  tmpreg |= (uint32_t)(UART_InitStruct->UART_StopBits | UART_InitStruct->UART_WordLength | UART_InitStruct->UART_Parity);
  UARTx->LCR = tmpreg;
  
  /*---------------------------- UART MCR Configuration -----------------------*/
  tmpreg = UARTx->MCR;
  tmpreg &= (uint32_t)~((uint32_t)UART_MCR_AFCE);
  tmpreg |= (uint32_t)UART_InitStruct->UART_HardwareFlowControl;
  UARTx->MCR = tmpreg;
  
  /*---------------------------- UART DLL DLH Configuration -----------------------*/
  /* Configure the UART Baud Rate -------------------------------------------*/
  sclk = RCC_GetBRCLKClock();
  
  /* Determine the integer part */
  if (sclk != 0)
  {
    divider = ((sclk / UART_InitStruct->UART_BaudRate) >> 3);
    divider = ((divider >> 1) + (divider&0x01));
    
    /* wait to idle or inactive */
    while((UARTx->USR & UART_USR_BUSY) && (wait>0))
    {
      wait--;
    }

    UARTx->LCR |= (uint32_t)UART_LCR_DLAB;

    UARTx->RBR_THR_DLL = (uint32_t)(divider&0x00FF);
    UARTx->DLH_IER = (uint32_t)((divider&0xFF00) >> 8);

    UARTx->LCR &= (uint32_t)~((uint32_t)UART_LCR_DLAB);
  }
}

/**
  * @brief  Fills each UART_InitStruct member with its default value.
  * @param  UART_InitStruct: pointer to a UART_InitTypeDef structure
  *         which will be initialized.
  */
void UART_StructInit(UART_InitTypeDef* UART_InitStruct)
{
  /* UART_InitStruct members default value */
  UART_InitStruct->UART_BaudRate = 9600;
  UART_InitStruct->UART_WordLength = UART_DLS_8;
  UART_InitStruct->UART_StopBits = UART_STOPBIT_1;
  UART_InitStruct->UART_Parity = UART_PARITY_NONE ;
  UART_InitStruct->UART_HardwareFlowControl = UART_HWCONTROL_NONE;  
}

/**
  * @brief  Sets the baudrate.
  * @param  UARTx: where x can be 1, 2 or 3 to select the UART peripheral.
  * @param  UART_Baudrate: specifies the prescaler clock.
  */
void UART_SetBaudrate(UART_TypeDef* UARTx, uint32_t UART_Baudrate)
{ 
  uint32_t divider = 0, sclk = 0;
  uint32_t wait = 0x00FFFFFF;

  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_BAUDRATE(UART_Baudrate));  
  
  /* Configure the UART Baud Rate -------------------------------------------*/
  sclk = RCC_GetBRCLKClock();
  
  /* Determine the integer part */
  if (sclk != 0)
  {
    divider = ((sclk / UART_Baudrate ) >> 3);
    divider = ((divider >> 1) + (divider & 0x01));

    /* wait to idle or inactive */
    while((UARTx->USR & UART_USR_BUSY) && (wait>0))
    {
      wait--;
    }

    UARTx->LCR |= (uint32_t)UART_LCR_DLAB;

    UARTx->RBR_THR_DLL = (uint32_t)(divider&0x00FF);
    UARTx->DLH_IER = (uint32_t)((divider&0xFF00) >> 8);

    UARTx->LCR &= (uint32_t)~((uint32_t)UART_LCR_DLAB);
  }
}

/**
  * @brief  Set Rx FIFO threshold.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  * @param  Threshold:
  */
void UART_RxFIFOThresholdConfig(UART_TypeDef* UARTx, uint8_t Threshold)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_RFIFO(Threshold));

   UARTx->IIR_FCR &= (uint32_t)~((uint32_t)UART_IIR_FCR_RCVR);
   UARTx->IIR_FCR |= Threshold;
}

/**
  * @brief  Set Tx FIFO threshold.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  * @param  Threshold:
  */
void UART_TxFIFOThresholdConfig(UART_TypeDef* UARTx, uint8_t Threshold)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_TFIFO(Threshold));

   UARTx->IIR_FCR &= (uint32_t)~((uint32_t)UART_IIR_FCR_TET);
   UARTx->IIR_FCR |= Threshold;
}

/**
  * @brief  Enables or disables the UART's break.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  * @param  NewState: new state of break.
  *          This parameter can be: ENABLE or DISABLE.
  */
void UART_FIFOCmd(UART_TypeDef* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    UARTx->IIR_FCR |= UART_IIR_FCR_FIFOE;
  }
  else
  {
    UARTx->IIR_FCR &= (uint32_t)~((uint32_t)UART_IIR_FCR_FIFOE);
  }
}

/**
  * @brief  Set Rx FIFO threshold.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  */
void UART_ResetRxFIFO(UART_TypeDef* UARTx)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  UARTx->IIR_FCR |= UART_IIR_FCR_RFIFOR;
}

/**
  * @brief  Set Tx FIFO threshold.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  */
void UART_ResetTxFIFO(UART_TypeDef* UARTx)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  UARTx->IIR_FCR |= UART_IIR_FCR_TFIFOR;
}

/**
  * @brief  Enables or disables the UART's break.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  * @param  NewState: new state of break.
  *          This parameter can be: ENABLE or DISABLE.
  */
void UART_ForceBreakCmd(UART_TypeDef* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the IrDA mode by setting the IREN bit in the CR3 register */
    UARTx->LCR |= UART_LCR_BC;
  }
  else
  {
    /* Disable the IrDA mode by clearing the IREN bit in the CR3 register */
    UARTx->LCR &= (uint32_t)~((uint32_t)UART_LCR_BC);
  }
}

/**
  * @brief  Enables or disables the UART's Loopback interface.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  * @param  NewState: new state of the Loopback mode.
  *          This parameter can be: ENABLE or DISABLE.
  */
void UART_LoopBackModeCmd(UART_TypeDef* UARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the IrDA mode by setting the IREN bit in the CR3 register */
    UARTx->MCR |= UART_MCR_LB;
  }
  else
  {
    /* Disable the IrDA mode by clearing the IREN bit in the CR3 register */
    UARTx->MCR &= (uint32_t)~((uint32_t)UART_MCR_LB);
  }
}

/**
  * @brief  Enables or disables the UART's IrDA interface.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  * @param  NewState: new state of the IrDA mode.
  *          This parameter can be: ENABLE or DISABLE.
  */
void UART_IrDACmd(UART_TypeDef* UARTx, FunctionalState NewState) 
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* Enable the IrDA mode by setting the IREN bit in the CR3 register */
    UARTx->MCR |= UART_MCR_SIRE;
  }
  else
  {
    /* Disable the IrDA mode by clearing the IREN bit in the CR3 register */
    UARTx->MCR &= (uint32_t)~((uint32_t)UART_MCR_SIRE);
  }
}

/**
  * @brief  Enables or disables the UART's RTS signal.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  * @param  NewState: new state of the RTS.
  *          This parameter can be: ENABLE or DISABLE.
  */
void UART_ModemForceRtsPinState(UART_TypeDef* UARTx, SignalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    UARTx->MCR |= UART_MCR_RTS;
  }
  else
  {
    UARTx->MCR &= (uint32_t)~((uint32_t)UART_MCR_RTS);
  }
}

/**
  * @brief  Enables or disables the UART's RTS signal.
  * @param  UARTx: where x can be 1or 4  to select the UART peripheral.
  * @param  UART_DMAMode: new state of the DMA mode.
  *          This parameter can be: Single or Burst.
  */
void UART_DMACmd(UART_TypeDef* UARTx, uint32_t UART_DMAMode)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_DMAM(UART_DMAMode));

  if (UART_DMAMode != LL_UART_DMAM_SINGLE)
  {
    UARTx->IIR_FCR |= UART_IIR_FCR_DMAM;
  }
  else
  {
    UARTx->IIR_FCR &= (uint32_t)~((uint32_t)UART_IIR_FCR_DMAM);
  }
}

/**
  * @}
  */


/** @defgroup UART_Exported_Functions_Group2 Data transfers functions
 *  @brief   Data transfers functions 
 *
  * @{
  */

/**
  * @brief  Transmits single data through the UARTx peripheral.
  * @param  UARTx: where x can be from 1 to 4 to select the UART peripheral.
  * @param  Data: the data to transmit.
  */
void UART_SendData(UART_TypeDef* UARTx, uint8_t Data)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_DATA(Data)); 
    
  /* Transmit Data */
  UARTx->RBR_THR_DLL = (Data & (uint8_t)0x0FF);
}

/**
  * @brief  Returns the most recent received data by the UARTx peripheral.
  * @param  UARTx: where x can be from 1 to 4 to select the UART peripheral.
  * @retval The received data.
  */
uint8_t UART_ReceiveData(UART_TypeDef* UARTx)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  /* Receive Data */
  return (uint8_t)(UARTx->RBR_THR_DLL & (uint8_t)0x0FF);
}

/**
  * @}
  */

/** @defgroup UART_Exported_Functions_Group3 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions 
 *
  * @{
  */

/**
  * @brief  Enables or disables the specified UART interrupts.
  * @param  UARTx: where x can be from 1 to 4 to select the UART peripheral.
  * @param  UART_IT: specifies the UART interrupt sources to be enabled or disabled.
  *          This parameter can be one of the following values:
  *          @arg @ref UART_IT_ERBFI
  *          @arg @ref UART_IT_ETBEI
  *          @arg @ref UART_IT_ELSI 
  *          @arg @ref UART_IT_EDSSI
  *          @arg @ref UART_IT_PTIME
  * @param  NewState: new state of the specified UARTx interrupts.
  *          This parameter can be: ENABLE or DISABLE.
  */
void UART_ITConfig(UART_TypeDef* UARTx, uint32_t UART_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  assert_param(IS_UART_IT(UART_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    UARTx->DLH_IER  |= UART_IT;
  }
  else
  {
    UARTx->DLH_IER &= (uint32_t)~((uint32_t)UART_IT);
  }
}

/**
  * @brief  Checks whether the specified UART Line flag is set or not.
  * @param  UARTx: where x can be from 1 to 4 to select the UART peripheral.
  * @retval The lines state
  */
uint32_t UART_GetLineStatus(UART_TypeDef* UARTx)
{
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  return (UARTx->LSR);
}

/**
  * @brief  Checks whether the specified UART modem flag is set or not.
  * @param  UARTx: where x can be from 1 to 4 to select the UART peripheral.
  * @retval The modem state.
  */
uint32_t UART_GetModemStatus(UART_TypeDef* UARTx)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  return (UARTx->MSR);
}

/**
  * @brief  Checks whether the specified UART flag is set or not.
  * @param  UARTx: where x can be from 1 to 8 to select the UART peripheral.
  * @retval The uart state.
  */
uint32_t UART_GetUartStatus(UART_TypeDef* UARTx)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  return (UARTx->USR);
}

/**
  * @brief  Checks whether the specified UART interrupt has occurred or not.
  * @param  UARTx: where x can be from 1 to 8 to select the UART peripheral.
  * @retval This parameter can be one of the following values:
  *           @arg @ref UART_IT_ID_MODEM      
  *           @arg @ref UART_IT_ID_NOITPENDING
  *           @arg @ref UART_IT_ID_THRE       
  *           @arg @ref UART_IT_ID_RXAV       
  *           @arg @ref UART_IT_ID_RXLS       
  *           @arg @ref UART_IT_ID_BUSY       
  *           @arg @ref UART_IT_ID_CHTO       
  */
uint32_t UART_GetITId(UART_TypeDef* UARTx)
{
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  return (uint32_t)(UARTx->IIR_FCR & 0x0000000FUL);  
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

