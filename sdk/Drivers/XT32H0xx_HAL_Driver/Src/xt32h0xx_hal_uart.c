/**
  ******************************************************************************
  * @file    xt32h0xx_hal_uart.c
  * @author  Software Team
  * @brief   UART HAL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"
//#include "SEGGER_RTT.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup UART UART
  * @brief HAL UART module driver
  * @{
  */

#ifdef HAL_UART_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup UART_Private_Constants UART Private Constants
  * @{
  */
#define UART_BRR_MIN    0x10U        /* UART BRR minimum authorized value */
#define UART_BRR_MAX    0x0000FFFFU  /* UART BRR maximum authorized value */

/* UART RX FIFO depth */
#define RX_FIFO_DEPTH 16U

/* UART TX FIFO depth */
#define TX_FIFO_DEPTH 16U
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @addtogroup UART_Private_Functions
  * @{
  */
static void UART_EndTxTransfer(UART_HandleTypeDef *huart);
static void UART_EndRxTransfer(UART_HandleTypeDef *huart);
static void UART_EndTxRxTransfer(UART_HandleTypeDef *huart);

static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void UART_DMARxBlock(DMA_HandleTypeDef *hdma);
static void UART_DMATxBlock(DMA_HandleTypeDef *hdma);
#if 0
static void UART_DMARxSrcTran(DMA_HandleTypeDef *hdma);
static void UART_DMATxSrcTran(DMA_HandleTypeDef *hdma);
static void UART_DMARxDstTran(DMA_HandleTypeDef *hdma);
static void UART_DMATxDstTran(DMA_HandleTypeDef *hdma);
#endif //0
static void UART_DMAError(DMA_HandleTypeDef *hdma);
#if 0
static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma);
#endif //0
static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma);
static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma);

static void UART_TxISR(UART_HandleTypeDef *huart);
static void UART_TxISR_FIFOEN(UART_HandleTypeDef *huart);
static void UART_RxISR(UART_HandleTypeDef *huart);
static void UART_RxISR_FIFOEN(UART_HandleTypeDef *huart);
static void UART_EndTransmit_IT(UART_HandleTypeDef *huart);

static void UART_SetNbDataToProcess(UART_HandleTypeDef *huart);
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/** @addtogroup UART_Private_variables
  * @{
  */
/**
  * @}
  */

/* Exported Constants --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @defgroup UART_Exported_Functions UART Exported Functions
  * @{
  */

/** @defgroup UART_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  * @{
  */

/**
  * @brief Initialize the UART mode according to the specified
  *        parameters in the UART_InitTypeDef and initialize the associated handle.
  * @param huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart)
{
  /* Check the UART handle allocation */
  if (huart == NULL)
  {
    return HAL_ERROR;
  }

	/* Check the parameters */
	assert_param(IS_UART_INSTANCE(huart->Instance));

  if (huart->gState == HAL_UART_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    huart->Lock = HAL_UNLOCKED;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    UART_InitCallbacksToDefault(huart);

    if (huart->MspInitCallback == NULL)
    {
      huart->MspInitCallback = HAL_UART_MspInit;
    }

    /* Init the low level hardware */
    huart->MspInitCallback(huart);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_UART_MspInit(huart);
#endif /* (USE_HAL_UART_REGISTER_CALLBACKS) */
  }

  huart->gState = HAL_UART_STATE_BUSY;

  /* Set the UART Communication parameters */
  if (UART_SetConfig(huart) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* TEACK and/or REACK to check before moving huart->gState to Ready */
  return (UART_CheckIdleState(huart));
}

/**
  * @brief DeInitialize the UART peripheral.
  * @param huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart)
{
  /* Check the UART handle allocation */
  if (huart == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_UART_INSTANCE(huart->Instance));

  huart->gState = HAL_UART_STATE_BUSY;
	
	/* disable all interrupts */
	huart->Instance->DLH_IER = 0;


#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  if (huart->MspDeInitCallback == NULL)
  {
    huart->MspDeInitCallback = HAL_UART_MspDeInit;
  }
  /* DeInit the low level hardware */
  huart->MspDeInitCallback(huart);
#else
  /* DeInit the low level hardware */
  HAL_UART_MspDeInit(huart);
#endif /* (USE_HAL_UART_REGISTER_CALLBACKS) */

  huart->ErrorCode = HAL_UART_ERROR_NONE;
  huart->gState = HAL_UART_STATE_RESET;
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief Initialize the UART MSP.
  * @param huart UART handle.
  */
__weak void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_MspInit can be implemented in the user file
   */
}

/**
  * @brief DeInitialize the UART MSP.
  * @param huart UART handle.
  */
__weak void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_MspDeInit can be implemented in the user file
   */
}

/**
  * @brief link dma with uart.
  * @param huart UART handle.
  * @param hdmarx DMA handle.
  * @param hdmatx DMA handle.
  * @param rxif DMA rx if.
  * @param txif DMA tx if.
  * @param rxifcfg DMA rx if configure.
  * @param txifcfg DMA tx if configure.
  * @retval Status
  */
HAL_StatusTypeDef HAL_UART_DMAHSIFConfig(UART_HandleTypeDef *huart, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx, uint32_t rxif, uint32_t txif, uint32_t rxifcfg, uint32_t txifcfg)
{
	uint32_t mask = 0;
	if(huart == NULL) return HAL_ERROR;
	
	if(hdmarx != NULL)
	{
		mask = 3UL << (rxif<<1);
		SYSCFG->DMA_CFG &= ~(mask);   
		SYSCFG->DMA_CFG |= ((rxifcfg & 0x3) << (rxif<<1));
#if defined(XT32H0xxB)    
		SYSCFG->DMA_CFG_2 &= ~(mask);   
		SYSCFG->DMA_CFG_2 |= (((rxifcfg & 0xC) >>2) << (rxif<<1));
#endif /* XT32H0xxB */

    hdmarx->Instance->CFG_L &= ~(DMA_CH_CHCFG_SRCHSPOL|DMA_CH_CHCFG_SRCHS);  //SRC_HS_POL = 0; HS_SEL_SRC = 0
	  hdmarx->Instance->CFG_H &= ~(DMA_CH_CHCFG_SRCPER);
    hdmarx->Instance->CFG_H |= (rxif << DMA_CH_CHCFG_SRCPER_Pos); 
	}
	
	if(hdmatx != NULL)
	{
		mask = 3UL << (txif<<1);
		SYSCFG->DMA_CFG &= ~(mask);  
		SYSCFG->DMA_CFG |= ((txifcfg  & 0x3) << (txif<<1));
#if defined(XT32H0xxB)    
		SYSCFG->DMA_CFG_2 &= ~(mask);   
		SYSCFG->DMA_CFG_2 |= (((txifcfg & 0xC) >>2) << (txif<<1));
#endif /* XT32H0xxB */

	  hdmatx->Instance->CFG_L &= ~(DMA_CH_CHCFG_DSTHSPOL|DMA_CH_CHCFG_DSTHS);  //DST_HS_POL = 0; HS_SEL_DST = 0
	  hdmatx->Instance->CFG_H &= ~(DMA_CH_CHCFG_DSTPER);
    hdmatx->Instance->CFG_H |= (txif << DMA_CH_CHCFG_DSTPER_Pos); 
	}

	return HAL_OK;
}
/**
  * @brief link dma with uart.
  * @param huart UART handle.
  * @param hdmarx DMA handle.
  * @param hdmatx DMA handle.
  * @retval Status
  */
HAL_StatusTypeDef HAL_UART_LinkDMA(UART_HandleTypeDef *huart, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx)
{
	if(huart == NULL) return HAL_ERROR;
	
	if(hdmarx != NULL)
	{
    huart->hdmarx = hdmarx;
		hdmarx->Parent = huart;
	}
	
	if(hdmatx != NULL)
	{
    huart->hdmatx = hdmatx;
		hdmatx->Parent = huart;
	}

	return HAL_OK;
}

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User UART Callback
  *         To be used instead of the weak predefined callback
  * @param  huart uart handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_UART_TX_COMPLETE_CB_ID            
  *           @arg @ref HAL_UART_RX_COMPLETE_CB_ID            
  *           @arg @ref HAL_UART_ERROR_CB_ID                  
  *           @arg @ref HAL_UART_ABORT_COMPLETE_CB_ID         
  *           @arg @ref HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID
  *           @arg @ref HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID 
  *           @arg @ref HAL_UART_RX_FIFO_FULL_CB_ID           
  *           @arg @ref HAL_UART_TX_FIFO_EMPTY_CB_ID          
  *           @arg @ref HAL_UART_MSPINIT_CB_ID                
  *           @arg @ref HAL_UART_MSPDEINIT_CB_ID              
  *           @arg @ref HAL_UART_TX_BLOCK_CB_ID               
  *           @arg @ref HAL_UART_TX_SRCTRAN_CB_ID             
  *           @arg @ref HAL_UART_TX_DSTTRAN_CB_ID             
  *           @arg @ref HAL_UART_RX_BLOCK_CB_ID               
  *           @arg @ref HAL_UART_RX_SRCTRAN_CB_ID             
  *           @arg @ref HAL_UART_RX_DSTTRAN_CB_ID             
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID,
                                            pUART_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  __HAL_LOCK(huart);

  if (huart->gState == HAL_UART_STATE_READY)
  {
    switch (CallbackID)
    {
      case HAL_UART_TX_COMPLETE_CB_ID :
        huart->TxCpltCallback = pCallback;
        break;

      case HAL_UART_TX_BLOCK_CB_ID :
        huart->TxBlockCallback = pCallback;
        break;

      case HAL_UART_TX_SRCTRAN_CB_ID :
        huart->TxSrcTranCallback = pCallback;
        break;

      case HAL_UART_TX_DSTTRAN_CB_ID :
        huart->TxDstTranCallback = pCallback;
        break;

      case HAL_UART_RX_COMPLETE_CB_ID :
        huart->RxCpltCallback = pCallback;
        break;

      case HAL_UART_RX_BLOCK_CB_ID :
        huart->RxBlockCallback = pCallback;
        break;

      case HAL_UART_RX_SRCTRAN_CB_ID :
        huart->RxSrcTranCallback = pCallback;
        break;

      case HAL_UART_RX_DSTTRAN_CB_ID :
        huart->RxDstTranCallback = pCallback;
        break;

      case HAL_UART_ERROR_CB_ID :
        huart->ErrorCallback = pCallback;
        break;

      case HAL_UART_ABORT_COMPLETE_CB_ID :
        huart->AbortCpltCallback = pCallback;
        break;

      case HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID :
        huart->AbortTransmitCpltCallback = pCallback;
        break;

      case HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID :
        huart->AbortReceiveCpltCallback = pCallback;
        break;

      case HAL_UART_WAKEUP_CB_ID :
        huart->WakeupCallback = pCallback;
        break;

      case HAL_UART_RX_FIFO_FULL_CB_ID :
        huart->RxFifoFullCallback = pCallback;
        break;

      case HAL_UART_TX_FIFO_EMPTY_CB_ID :
        huart->TxFifoEmptyCallback = pCallback;
        break;

      case HAL_UART_MSPINIT_CB_ID :
        huart->MspInitCallback = pCallback;
        break;

      case HAL_UART_MSPDEINIT_CB_ID :
        huart->MspDeInitCallback = pCallback;
        break;

      default :
        huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else if (huart->gState == HAL_UART_STATE_RESET)
  {
    switch (CallbackID)
    {
      case HAL_UART_MSPINIT_CB_ID :
        huart->MspInitCallback = pCallback;
        break;

      case HAL_UART_MSPDEINIT_CB_ID :
        huart->MspDeInitCallback = pCallback;
        break;

      default :
        huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  __HAL_UNLOCK(huart);

  return status;
}

/**
  * @brief  Unregister an UART Callback
  *         UART callaback is redirected to the weak predefined callback
  * @param  huart uart handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *           @arg @ref HAL_UART_TX_COMPLETE_CB_ID            
  *           @arg @ref HAL_UART_RX_COMPLETE_CB_ID            
  *           @arg @ref HAL_UART_ERROR_CB_ID                  
  *           @arg @ref HAL_UART_ABORT_COMPLETE_CB_ID         
  *           @arg @ref HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID
  *           @arg @ref HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID 
  *           @arg @ref HAL_UART_RX_FIFO_FULL_CB_ID           
  *           @arg @ref HAL_UART_TX_FIFO_EMPTY_CB_ID          
  *           @arg @ref HAL_UART_MSPINIT_CB_ID                
  *           @arg @ref HAL_UART_MSPDEINIT_CB_ID              
  *           @arg @ref HAL_UART_TX_BLOCK_CB_ID               
  *           @arg @ref HAL_UART_TX_SRCTRAN_CB_ID             
  *           @arg @ref HAL_UART_TX_DSTTRAN_CB_ID             
  *           @arg @ref HAL_UART_RX_BLOCK_CB_ID               
  *           @arg @ref HAL_UART_RX_SRCTRAN_CB_ID             
  *           @arg @ref HAL_UART_RX_DSTTRAN_CB_ID             
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  __HAL_LOCK(huart);

  if (HAL_UART_STATE_READY == huart->gState)
  {
    switch (CallbackID)
    {
      case HAL_UART_TX_COMPLETE_CB_ID :
        huart->TxCpltCallback = HAL_UART_TxCpltCallback;                       /* Legacy weak TxCpltCallback         */
        break;

      case HAL_UART_TX_BLOCK_CB_ID :
        huart->TxBlockCallback = HAL_UART_TxBlockCallback;                       /* Legacy weak TxCpltCallback         */
        break;

      case HAL_UART_TX_SRCTRAN_CB_ID :
        huart->TxSrcTranCallback = HAL_UART_TxSrcTranCallback;                       /* Legacy weak TxCpltCallback         */
        break;

      case HAL_UART_TX_DSTTRAN_CB_ID :
        huart->TxDstTranCallback = HAL_UART_TxDstTranCallback;                       /* Legacy weak TxCpltCallback         */
        break;

      case HAL_UART_RX_COMPLETE_CB_ID :
        huart->RxCpltCallback = HAL_UART_RxCpltCallback;                       /* Legacy weak RxCpltCallback         */
        break;

      case HAL_UART_RX_BLOCK_CB_ID :
        huart->RxBlockCallback = HAL_UART_RxBlockCallback;                       /* Legacy weak RxCpltCallback         */
        break;

      case HAL_UART_RX_SRCTRAN_CB_ID :
        huart->RxSrcTranCallback = HAL_UART_RxSrcTranCallback;                       /* Legacy weak RxCpltCallback         */
        break;

      case HAL_UART_RX_DSTTRAN_CB_ID :
        huart->RxDstTranCallback = HAL_UART_RxDstTranCallback;                       /* Legacy weak RxCpltCallback         */
        break;

      case HAL_UART_ERROR_CB_ID :
        huart->ErrorCallback = HAL_UART_ErrorCallback;                         /* Legacy weak ErrorCallback          */
        break;

      case HAL_UART_ABORT_COMPLETE_CB_ID :
        huart->AbortCpltCallback = HAL_UART_AbortCpltCallback;                 /* Legacy weak AbortCpltCallback      */
        break;

      case HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID :
        huart->AbortTransmitCpltCallback = HAL_UART_AbortTransmitCpltCallback; /* Legacy weak
                                                                                  AbortTransmitCpltCallback          */
        break;

      case HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID :
        huart->AbortReceiveCpltCallback = HAL_UART_AbortReceiveCpltCallback;   /* Legacy weak
                                                                                  AbortReceiveCpltCallback           */
        break;

      case HAL_UART_RX_FIFO_FULL_CB_ID :
        huart->RxFifoFullCallback = HAL_UART_RxFifoFullCallback;             /* Legacy weak RxFifoFullCallback     */
        break;

      case HAL_UART_TX_FIFO_EMPTY_CB_ID :
        huart->TxFifoEmptyCallback = HAL_UART_TxFifoEmptyCallback;           /* Legacy weak TxFifoEmptyCallback    */
        break;

      case HAL_UART_MSPINIT_CB_ID :
        huart->MspInitCallback = HAL_UART_MspInit;                             /* Legacy weak MspInitCallback        */
        break;

      case HAL_UART_MSPDEINIT_CB_ID :
        huart->MspDeInitCallback = HAL_UART_MspDeInit;                         /* Legacy weak MspDeInitCallback      */
        break;

      default :
        huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_UART_STATE_RESET == huart->gState)
  {
    switch (CallbackID)
    {
      case HAL_UART_MSPINIT_CB_ID :
        huart->MspInitCallback = HAL_UART_MspInit;
        break;

      case HAL_UART_MSPDEINIT_CB_ID :
        huart->MspDeInitCallback = HAL_UART_MspDeInit;
        break;

      default :
        huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  __HAL_UNLOCK(huart);

  return status;
}

/**
  * @brief  Register a User UART Rx Event Callback
  *         To be used instead of the weak predefined callback
  * @param  huart     Uart handle
  * @param  pCallback Pointer to the Rx Event Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_RegisterRxEventCallback(UART_HandleTypeDef *huart, pUART_RxEventCallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  /* Process locked */
  __HAL_LOCK(huart);

  if (huart->gState == HAL_UART_STATE_READY)
  {
    huart->RxEventCallback = pCallback;
  }
  else
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(huart);

  return status;
}

/**
  * @brief  UnRegister the UART Rx Event Callback
  *         UART Rx Event Callback is redirected to the weak HAL_UARTEx_RxEventCallback() predefined callback
  * @param  huart     Uart handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_UnRegisterRxEventCallback(UART_HandleTypeDef *huart)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(huart);

  if (huart->gState == HAL_UART_STATE_READY)
  {
    huart->RxEventCallback = HAL_UARTEx_RxEventCallback; /* Legacy weak UART Rx Event Callback  */
  }
  else
  {
    huart->ErrorCode |= HAL_UART_ERROR_INVALID_CALLBACK;

    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(huart);
  return status;
}

#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup UART_Exported_Functions_Group2 IO operation functions
  * @brief UART Transmit/Receive functions
  *
  * @{
  */

/**
  * @brief Send an amount of data in blocking mode.
  * @param huart   UART handle.
  * @param pData   Pointer to data buffer (u8 data elements).
  * @param Size    Amount of data elements (u16) to be sent.
  * @param Timeout Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint32_t tickstart;

  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;

    /* Init tickstart for timeout management */
    tickstart = HAL_GetTick();

    huart->TxXferSize  = Size;
    huart->TxXferCount = Size;

    pdata8bits  = pData;

    __HAL_UNLOCK(huart);

    /* Is enabled FIFO*/
    if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
    {
      /* enable THRE interrupt*/
      SET_BIT(huart->Instance->DLH_IER, UART_DLH_IER_PTIME);
    }

    while (huart->TxXferCount > 0U)
    {
      if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
      {
        /* check TX FIFO is not full */
        if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_TEMT, SET, tickstart, Timeout) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }
      }
      else
      {
        /* check tx holding is empty */
        if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_THRE, SET, tickstart, Timeout) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }
      }
      
			huart->Instance->RBR_THR_DLL = (uint8_t)(*pdata8bits & 0xFFU);
      pdata8bits++;
      huart->TxXferCount--;
    }

    /* tx FIFO, transmit holding and transmitter shift are empty */
		if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
		{
			if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_TEMT, SET, tickstart, Timeout) != HAL_OK)
			{
				return HAL_TIMEOUT;
			}
	  }

    /* At end of Tx process, restore huart->gState to Ready */
    huart->gState = HAL_UART_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in blocking mode.
  * @param huart   UART handle.
  * @param pData   Pointer to data buffer (u8 data elements).
  * @param Size    Amount of data elements (u16) to be received.
  * @param Timeout Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint8_t uhMask = 0xFF;
  uint32_t tickstart;

  /* Check that a Rx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_RX;
    huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    /* Init tickstart for timeout management */
    tickstart = HAL_GetTick();

    huart->RxXferSize  = Size;
    huart->RxXferCount = Size;

    /* Computation of UART mask to apply to RDR register */
    if(huart->Mask > 0)
    {
      uhMask = (uint8_t) huart->Mask;
    }

    pdata8bits  = pData;

    __HAL_UNLOCK(huart);

    /* as long as data have to be received */
    while (huart->RxXferCount > 0U)
    {
      if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_DR, SET, tickstart, Timeout) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }

      *pdata8bits = (uint8_t)(huart->Instance->RBR_THR_DLL & (uint8_t)uhMask);
      pdata8bits++;

      huart->RxXferCount--;
    }

    /* At end of Rx process, restore huart->RxState to Ready */
    huart->gState = HAL_UART_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Send an amount of data in blocking mode and receive some data.
  * @param huart   UART handle.
  * @param pTxData   Pointer to data buffer (u8 data elements).
  * @param TxSize    Amount of data elements (u16) to be sent.
  * @param pRxData   Pointer to data buffer (u8 data elements).
  * @param RxSize    Amount of data elements (u16) to be sent.
  * @param Timeout Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_TransmitReceive(UART_HandleTypeDef *huart, uint8_t *pTxData, uint16_t TxSize, uint8_t *pRxData, uint16_t RxSize, uint32_t Timeout)
{
  uint8_t  *ptxdata8bits;
  uint8_t  *prxdata8bits;
  uint32_t tickstart;
  uint32_t uhMask = ((huart->Mask > 0) ? huart->Mask : 0xFF);

  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pTxData == NULL) || (TxSize == 0U) || (pRxData == NULL) || (RxSize == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX_RX;

    /* Init tickstart for timeout management */
    tickstart = HAL_GetTick();

    huart->TxXferSize  = TxSize;
    huart->TxXferCount = TxSize;
    huart->RxXferSize  = RxSize;
    huart->RxXferCount = RxSize;

    ptxdata8bits  = pTxData;
    prxdata8bits  = pRxData;

    __HAL_UNLOCK(huart);

    /* Is enabled FIFO*/
    if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
    {
      /* enable THRE interrupt*/
      SET_BIT(huart->Instance->DLH_IER, UART_DLH_IER_PTIME);
    }

    while ((huart->TxXferCount > 0U) || (huart->RxXferCount > 0U))
    {
      if(huart->TxXferCount > 0U)
      {
        if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
        {
          /* check TX FIFO is not full */
          if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_TEMT, SET, tickstart, Timeout) != HAL_OK)
          {
            return HAL_TIMEOUT;
          }
        }
        else
        {
          /* check tx holding is empty */
          if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_THRE, SET, tickstart, Timeout) != HAL_OK)
          {
            return HAL_TIMEOUT;
          }
        }
      
        huart->Instance->RBR_THR_DLL = (uint8_t)(*ptxdata8bits & 0xFFU);
        ptxdata8bits++;
        huart->TxXferCount--;
      }

      if (huart->RxXferCount > 0U)
      {
        if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_DR, SET, tickstart, Timeout) != HAL_OK)
        {
          return HAL_TIMEOUT;
        }
  
        *prxdata8bits = (uint8_t)(huart->Instance->RBR_THR_DLL & (uint8_t)uhMask);
        prxdata8bits++;
  
        huart->RxXferCount--;
      }
    }

    /* tx FIFO, transmit holding and transmitter shift are empty */
		if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
		{
			if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_TEMT, SET, tickstart, Timeout) != HAL_OK)
			{
				return HAL_TIMEOUT;
			}
	  }

    /* At end of Tx process, restore huart->gState to Ready */
    huart->gState = HAL_UART_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }

}

/**
  * @brief Send an amount of data in interrupt mode.
  * @param huart UART handle.
  * @param pData Pointer to data buffer (u8 data elements).
  * @param Size  Amount of data elements (u16) to be sent.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  uint32_t tickstart;

  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->pTxBuffPtr  = pData;
    huart->TxXferSize  = Size;
    huart->TxXferCount = Size;
    huart->TxISR       = NULL;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;

    /* Configure Tx interrupt processing */
    if (huart->FifoMode == UART_FIFOMODE_ENABLE)
    {
      /* Set the Tx ISR function pointer according to the data word length */
      huart->TxISR = UART_TxISR_FIFOEN;

      __HAL_UNLOCK(huart);
    }
    else
    {
      /* Set the Tx ISR function pointer according to the data word length */
      huart->TxISR = UART_TxISR;

      __HAL_UNLOCK(huart);

    }

		tickstart = HAL_GetTick();
		if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
		{
			/* check TX FIFO is not full */
			if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_TEMT, SET, tickstart, HAL_MAX_DELAY) != HAL_OK)
			{
				return HAL_TIMEOUT;
			}
		}
		else
		{
			/* check tx holding is empty */
			if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_THRE, SET, tickstart, HAL_MAX_DELAY) != HAL_OK)
			{
				return HAL_TIMEOUT;
			}
		}
		huart->Instance->RBR_THR_DLL = (uint8_t)(*huart->pTxBuffPtr & 0xFFU);
		huart->pTxBuffPtr++;
		huart->TxXferCount--;
		
    /* Enable lines status interrupt */
		if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
		{
      __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_PTIME);     //enable THRE
		}
    __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ETBEI);     //enable transmit holding empty
    __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ELSI);      //enable receiver line status

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in interrupt mode.
  * @param huart UART handle.
  * @param pData Pointer to data buffer (u8 data elements).
  * @param Size  Amount of data elements (u16) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    /* Set Reception type to Standard reception */
    huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    return (UART_Start_Receive_IT(huart, pData, Size));
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Send and receive an amount of data in interrupt mode.
  * @param huart UART handle.
  * @param pTxData Pointer to data buffer (u8 data elements).
  * @param TxSize  Amount of data elements (u16) to be received.
  * @param pRxData Pointer to data buffer (u8 data elements).
  * @param RxSize  Amount of data elements (u16) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_TransmitReceive_IT(UART_HandleTypeDef *huart, uint8_t *pTxData, uint16_t TxSize, uint8_t *pRxData, uint16_t RxSize)
{
  uint32_t tickstart;

  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pTxData == NULL) || (TxSize == 0U) || (pRxData == NULL) || (RxSize == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->pTxBuffPtr  = pTxData;
    huart->TxXferSize  = TxSize;
    huart->TxXferCount = TxSize;
    huart->TxISR       = NULL;

    huart->pRxBuffPtr  = pRxData;
    huart->RxXferSize  = RxSize;
    huart->RxXferCount = RxSize;
    huart->RxISR       = NULL;

    huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX_RX;

    /* Configure Tx interrupt processing */
    if (huart->FifoMode == UART_FIFOMODE_ENABLE)
    {
      /* Set the Tx ISR function pointer according to the data word length */
      huart->TxISR = UART_TxISR_FIFOEN;

//      if(RxSize >= huart->NbRxDataToProcess)
//      {
        huart->RxISR = UART_RxISR_FIFOEN;
//      }
//      else
//      {
//        huart->RxISR = UART_RxISR;
//      }

      __HAL_UNLOCK(huart);
    }
    else
    {
      /* Set the Tx ISR function pointer according to the data word length */
      huart->TxISR = UART_TxISR;
      huart->RxISR = UART_RxISR;

      __HAL_UNLOCK(huart);

    }

    tickstart = HAL_GetTick();
    if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
    {
      /* check TX FIFO is not full */
      if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_TEMT, SET, tickstart, HAL_MAX_DELAY) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
    }
    else
    {
      /* check tx holding is empty */
      if (UART_WaitOnLineStatusUntilTimeout(huart, UART_LS_THRE, SET, tickstart, HAL_MAX_DELAY) != HAL_OK)
      {
        return HAL_TIMEOUT;
      }
    }
    huart->Instance->RBR_THR_DLL = (uint8_t)(*huart->pTxBuffPtr & 0xFFU);
    huart->pTxBuffPtr++;
    huart->TxXferCount--;
    
    /* Enable lines status interrupt */
    if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
    {
      __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_PTIME);     //enable THRE
    }
    __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ETBEI);     //enable transmit holding empty
    __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ELSI);      //enable receiver line status
    __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ERBFI);     //enable receuved data available

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }

}

/**
  * @brief Send an amount of data in DMA mode.
  * @note   When UART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @note   When UART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         address of user data buffer containing data to be sent, should be aligned on a half word frontier (16 bits)
  *         (as sent data will be handled by DMA from halfword frontier). Depending on compilation chain,
  *         use of specific alignment compilation directives or pragmas might be required
  *         to ensure proper alignment for pData.
  * @param huart UART handle.
  * @param pData Pointer to data buffer (u8 data elements).
  * @param Size  Amount of data elements (u16) to be sent.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->pTxBuffPtr  = pData;
    huart->TxXferSize  = Size;
    huart->TxXferCount = Size;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX;

    if (huart->hdmatx != NULL)
    {
      /* Set the UART DMA transfer complete callback */
      huart->hdmatx->XferCpltCallback = UART_DMATransmitCplt;

      /* Set the UART DMA Half transfer complete callback */
			huart->hdmatx->XferBlockCallback = UART_DMATxBlock;
//			huart->hdmatx->XferSrcTranCallback = UART_DMATxSrcTran;
//			huart->hdmatx->XferDstTranCallback = UART_DMATxDstTran;

      /* Set the DMA error callback */
      huart->hdmatx->XferErrorCallback = UART_DMAError;

      /* Set the DMA abort callback */
      huart->hdmatx->XferAbortCallback = NULL;

      /* Enable the UART transmit DMA channel */
      if (HAL_DMA_Start_IT(huart->hdmatx, (uint32_t)huart->pTxBuffPtr, (uint32_t)&huart->Instance->RBR_THR_DLL, Size) != HAL_OK)
      {
        /* Set error code to DMA */
        huart->ErrorCode = HAL_UART_ERROR_DMA;

        __HAL_UNLOCK(huart);

        /* Restore huart->gState to ready */
        huart->gState = HAL_UART_STATE_READY;

        return HAL_ERROR;
      }
    }
    /* Clear the TC flag in the ICR register */
    __HAL_UART_IT_CLEAR_TE(huart);
    __HAL_UART_IT_CLEAR_LS(huart);

    __HAL_UNLOCK(huart);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in DMA mode.
  * @param huart UART handle.
  * @param pData Pointer to data buffer (u8 data elements).
  * @param Size  Amount of data elements (u16) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    /* Set Reception type to Standard reception */
    huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    return (UART_Start_Receive_DMA(huart, pData, Size));
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Send and receive an amount of data in DMA mode.
  * @param huart UART handle.
  * @param pTxData Pointer to TX data buffer (u8 data elements).
  * @param TxSize  Amount of TX data elements (u16) to be received.
  * @param pRxData Pointer to RX data buffer (u8 data elements).
  * @param RxSize  Amount of RX data elements (u16) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_TransmitReceive_DMA(UART_HandleTypeDef *huart, uint8_t *pTxData, uint16_t TxSize, uint8_t *pRxData, uint16_t RxSize)
{
  /* Check that a Tx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pTxData == NULL) || (TxSize == 0U) || (pRxData == NULL) || (RxSize == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->pTxBuffPtr  = pTxData;
    huart->TxXferSize  = TxSize;
    huart->TxXferCount = TxSize;

    huart->pRxBuffPtr = pRxData;
    huart->RxXferSize = RxSize;
    huart->RxXferCount = RxSize;

    huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_TX_RX;

    if (huart->hdmatx != NULL)
    {
      /* Set the UART DMA transfer complete callback */
      huart->hdmatx->XferCpltCallback = UART_DMATransmitCplt;

      /* Set the UART DMA Half transfer complete callback */
			huart->hdmatx->XferBlockCallback = UART_DMATxBlock;
//			huart->hdmatx->XferSrcTranCallback = UART_DMATxSrcTran;
//			huart->hdmatx->XferDstTranCallback = UART_DMATxDstTran;

      /* Set the DMA error callback */
      huart->hdmatx->XferErrorCallback = UART_DMAError;

      /* Set the DMA abort callback */
      huart->hdmatx->XferAbortCallback = NULL;

      /* Enable the UART transmit DMA channel */
      if (HAL_DMA_Start_IT(huart->hdmatx, (uint32_t)huart->pTxBuffPtr, (uint32_t)&huart->Instance->RBR_THR_DLL, TxSize) != HAL_OK)
      {
        /* Set error code to DMA */
        huart->ErrorCode = HAL_UART_ERROR_DMA;

        __HAL_UNLOCK(huart);

        /* Restore huart->gState to ready */
        huart->gState = HAL_UART_STATE_READY;

        return HAL_ERROR;
      }
    }

    if (huart->hdmarx != NULL)
    {
      /* Set the UART DMA transfer complete callback */
      huart->hdmarx->XferCpltCallback = UART_DMAReceiveCplt;
  
      /* Set the UART DMA Half transfer complete callback */
  		huart->hdmarx->XferBlockCallback = UART_DMARxBlock;
//  		huart->hdmarx->XferSrcTranCallback = UART_DMARxSrcTran;
// 		huart->hdmarx->XferDstTranCallback = UART_DMARxDstTran;
  		
      /* Set the DMA error callback */
      huart->hdmarx->XferErrorCallback = UART_DMAError;
  
      /* Set the DMA abort callback */
      huart->hdmarx->XferAbortCallback = NULL;
  
      /* Enable the DMA channel */
      if (HAL_DMA_Start_IT(huart->hdmarx, (uint32_t)&huart->Instance->RBR_THR_DLL, (uint32_t)huart->pRxBuffPtr, RxSize) != HAL_OK)
      {
        /* Set error code to DMA */
        huart->ErrorCode = HAL_UART_ERROR_DMA;
  
        __HAL_UNLOCK(huart);
  
        /* Restore huart->RxState to ready */
        huart->gState = HAL_UART_STATE_READY;
  
        return HAL_ERROR;
      }
    }

//    __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ELSI);
//    __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ERBFI);
    __HAL_UART_IT_CLEAR_RA(huart);
    /* Clear the TC flag in the ICR register */
    __HAL_UART_IT_CLEAR_TE(huart);
    __HAL_UART_IT_CLEAR_LS(huart);
 
    __HAL_UNLOCK(huart);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Stop the DMA Transfer.
  * @param huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart)
{
  /* The Lock is not implemented on this API to allow the user application
     to call the HAL UART API under callbacks HAL_UART_TxCpltCallback() / HAL_UART_RxCpltCallback():
     indeed, when HAL_DMA_Abort() API is called, the DMA TX/RX Transfer or Half Transfer complete
     interrupt is generated if the DMA transfer interruption occurs at the middle or at the end of
     the stream and the corresponding call back is executed. */

  const HAL_UART_StateTypeDef gstate = huart->gState;
//  const HAL_UART_StateTypeDef rxstate = huart->RxState;

  /* Stop UART DMA Tx request if ongoing */
  if (gstate == HAL_UART_STATE_BUSY_TX)
  {
    /* Abort the UART DMA Tx channel */
    if (huart->hdmatx != NULL)
    {
      if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    UART_EndTxTransfer(huart);
  }

  /* Stop UART DMA Rx request if ongoing */
  else if (gstate == HAL_UART_STATE_BUSY_RX)
  {
    /* Abort the UART DMA Rx channel */
    if (huart->hdmarx != NULL)
    {
      if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    UART_EndRxTransfer(huart);
  }
	
  /* Stop UART DMA Tx Rx request if ongoing */
  else if (gstate == HAL_UART_STATE_BUSY_TX_RX)
  {
    /* Abort the UART DMA Tx channel */
    if (huart->hdmatx != NULL)
    {
      if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }
    /* Abort the UART DMA Tx channel */
    if (huart->hdmarx != NULL)
    {
      if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    UART_EndTxRxTransfer(huart);
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (blocking mode).
  * @param  huart UART handle.
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart)
{
  /* Disable all interrupts */
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ALL);

  /* Disable the UART DMA Tx request if enabled */
  /* Abort the UART DMA Tx channel : use blocking DMA Abort API (no callback) */
  if (huart->hdmatx != NULL)
  {
    /* Set the UART DMA Abort callback to Null.
       No call back execution at end of DMA abort procedure */
    huart->hdmatx->XferAbortCallback = NULL;

    if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK)
    {
      if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
      {
        /* Set error code to DMA */
        huart->ErrorCode = HAL_UART_ERROR_DMA;

        return HAL_TIMEOUT;
      }
    }
  }

  /* Disable the UART DMA Rx request if enabled */

	/* Abort the UART DMA Rx channel : use blocking DMA Abort API (no callback) */
	if (huart->hdmarx != NULL)
	{
		/* Set the UART DMA Abort callback to Null.
			 No call back execution at end of DMA abort procedure */
		huart->hdmarx->XferAbortCallback = NULL;

		if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK)
		{
			if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
			{
				/* Set error code to DMA */
				huart->ErrorCode = HAL_UART_ERROR_DMA;

				return HAL_TIMEOUT;
			}
		}
	}

  /* Reset Tx and Rx transfer counters */
  huart->TxXferCount = 0U;
  huart->RxXferCount = 0U;

  /* Clear the Error flags in the ICR register */
  __HAL_UART_CLEAR_IT_MODEMSTATUS(huart);
  __HAL_UART_CLEAR_IT_UARTSTATUS(huart);
  __HAL_UART_CLEAR_IT_TXEMPTY(huart);
  __HAL_UART_CLEAR_IT_RXAVAILABLE(huart);
  __HAL_UART_CLEAR_IT_LINESTATUS(huart);

  /* Flush the whole TX/RX FIFO (if needed) */
  if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
  {
    huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
  }

  /* Restore huart->gState and huart->RxState to Ready */
  huart->gState  = HAL_UART_STATE_READY;
//  huart->RxState = HAL_UART_STATE_READY;
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

  huart->ErrorCode = HAL_UART_ERROR_NONE;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Transmit transfer (blocking mode).
  * @param  huart UART handle.
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart)
{
  /* Disable TCIE, TXEIE and TXFTIE interrupts */
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ETBEI|UART_ENABLEIT_PTIME);

  /* Disable the UART DMA Tx request if enabled */

	/* Abort the UART DMA Tx channel : use blocking DMA Abort API (no callback) */
	if (huart->hdmatx != NULL)
	{
		/* Set the UART DMA Abort callback to Null.
			 No call back execution at end of DMA abort procedure */
		huart->hdmatx->XferAbortCallback = NULL;

		if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK)
		{
			if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
			{
				/* Set error code to DMA */
				huart->ErrorCode = HAL_UART_ERROR_DMA;

				return HAL_TIMEOUT;
			}
		}
	}

  /* Reset Tx transfer counter */
  huart->TxXferCount = 0U;

  /* Flush the whole TX FIFO (if needed) */
  if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
  {
    huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
  }

	if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
	{
		huart->gState = HAL_UART_STATE_BUSY_RX;
	}
	else
	{
    /* Restore huart->gState to Ready */
    huart->gState = HAL_UART_STATE_READY;
	}

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Receive transfer (blocking mode).
  * @param  huart UART handle.
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart)
{
  /* Disable PEIE, EIE, RXNEIE and RXFTIE interrupts */
 __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ERBFI|UART_ENABLEIT_ELSI);

  /* Disable the UART DMA Rx request if enabled */
	/* Abort the UART DMA Rx channel : use blocking DMA Abort API (no callback) */
	if (huart->hdmarx != NULL)
	{
		/* Set the UART DMA Abort callback to Null.
			 No call back execution at end of DMA abort procedure */
		huart->hdmarx->XferAbortCallback = NULL;

		if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK)
		{
			if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
			{
				/* Set error code to DMA */
				huart->ErrorCode = HAL_UART_ERROR_DMA;

				return HAL_TIMEOUT;
			}
		}
	}

  /* Reset Rx transfer counter */
  huart->RxXferCount = 0U;

  /* Flush the whole TX/RX FIFO (if needed) */
  if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
  {
    huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
  }

  /* Clear the Error flags in the ICR register */
  __HAL_UART_CLEAR_IT_MODEMSTATUS(huart);
  __HAL_UART_CLEAR_IT_UARTSTATUS(huart);
  __HAL_UART_CLEAR_IT_TXEMPTY(huart);
  __HAL_UART_CLEAR_IT_RXAVAILABLE(huart);
  __HAL_UART_CLEAR_IT_LINESTATUS(huart);

	if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
	{
		huart->gState = HAL_UART_STATE_BUSY_TX;
	}
	else
	{
    /* Restore huart->RxState to Ready */
    huart->gState = HAL_UART_STATE_READY;
	}
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

  return HAL_OK;
}

/**
  * @brief  Abort ongoing transfers (Interrupt mode).
  * @param  huart UART handle.
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart)
{
  uint32_t abortcplt = 1U;

  /* Disable interrupts */
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ALL);

  /* If DMA Tx and/or DMA Rx Handles are associated to UART Handle, DMA Abort complete callbacks should be initialised
     before any call to DMA Abort functions */
  /* DMA Tx Handle is valid */
  if (huart->hdmatx != NULL)
  {
    /* Set DMA Abort Complete callback if UART DMA Tx request if enabled.
       Otherwise, set it to NULL */
    huart->hdmatx->XferAbortCallback = UART_DMATxAbortCallback;
  }
  /* DMA Rx Handle is valid */
  if (huart->hdmarx != NULL)
  {
    huart->hdmarx->XferAbortCallback = UART_DMARxAbortCallback;
  }

  /* Disable the UART DMA Tx request if enabled */
	/* Abort the UART DMA Tx channel : use non blocking DMA Abort API (callback) */
	if (huart->hdmatx != NULL)
	{
		/* UART Tx DMA Abort callback has already been initialised :
			 will lead to call HAL_UART_AbortCpltCallback() at end of DMA abort procedure */

		/* Abort DMA TX */
		if (HAL_DMA_Abort_IT(huart->hdmatx) != HAL_OK)
		{
			huart->hdmatx->XferAbortCallback = NULL;
		}
		else
		{
			abortcplt = 0U;
		}
	}

  /* Disable the UART DMA Rx request if enabled */
	/* Abort the UART DMA Rx channel : use non blocking DMA Abort API (callback) */
	if (huart->hdmarx != NULL)
	{
		/* UART Rx DMA Abort callback has already been initialised :
			 will lead to call HAL_UART_AbortCpltCallback() at end of DMA abort procedure */

		/* Abort DMA RX */
		if (HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK)
		{
			huart->hdmarx->XferAbortCallback = NULL;
			abortcplt = 1U;
		}
		else
		{
			abortcplt = 0U;
		}
	}

  /* if no DMA abort complete callback execution is required => call user Abort Complete callback */
  if (abortcplt == 1U)
  {
    /* Reset Tx and Rx transfer counters */
    huart->TxXferCount = 0U;
    huart->RxXferCount = 0U;

    /* Clear ISR function pointers */
    huart->RxISR = NULL;
    huart->TxISR = NULL;

    /* Reset errorCode */
    huart->ErrorCode = HAL_UART_ERROR_NONE;

    /* Clear the Error flags in the ICR register */
  __HAL_UART_CLEAR_IT_MODEMSTATUS(huart);
  __HAL_UART_CLEAR_IT_UARTSTATUS(huart);
  __HAL_UART_CLEAR_IT_TXEMPTY(huart);
  __HAL_UART_CLEAR_IT_RXAVAILABLE(huart);
  __HAL_UART_CLEAR_IT_LINESTATUS(huart);

    /* Flush the whole TX FIFO (if needed) */
  if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
  {
    huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
  }

	/* Restore huart->gState and huart->RxState to Ready */
	huart->gState  = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort complete callback */
  huart->AbortCpltCallback(huart);
#else
    /* Call legacy weak Abort complete callback */
  HAL_UART_AbortCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Transmit transfer (Interrupt mode).
  * @param  huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart)
{
  /* Disable interrupts */
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ETBEI|UART_ENABLEIT_PTIME);

  /* Disable the UART DMA Tx request if enabled */
	/* Abort the UART DMA Tx channel : use non blocking DMA Abort API (callback) */
	if (huart->hdmatx != NULL)
	{
		/* Set the UART DMA Abort callback :
			 will lead to call HAL_UART_AbortCpltCallback() at end of DMA abort procedure */
		huart->hdmatx->XferAbortCallback = UART_DMATxOnlyAbortCallback;

		/* Abort DMA TX */
		if (HAL_DMA_Abort_IT(huart->hdmatx) != HAL_OK)
		{
			/* Call Directly huart->hdmatx->XferAbortCallback function in case of error */
			huart->hdmatx->XferAbortCallback(huart->hdmatx);
		}
	}
	else
	{
		/* Reset Tx transfer counter */
		huart->TxXferCount = 0U;

		/* Clear TxISR function pointers */
		huart->TxISR = NULL;

		/* Restore huart->gState to Ready */
		huart->gState = HAL_UART_STATE_READY;

		/* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
		/* Call registered Abort Transmit Complete Callback */
		huart->AbortTransmitCpltCallback(huart);
#else
		/* Call legacy weak Abort Transmit Complete Callback */
		HAL_UART_AbortTransmitCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
	}

	/* Flush the whole TX FIFO (if needed) */
  if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
  {
    huart->Instance->IIR_FCR= huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
  }

	if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
	{
		huart->gState = HAL_UART_STATE_BUSY_RX;
	}
	else
	{
  	/* Restore huart->gState to Ready */
	  huart->gState = HAL_UART_STATE_READY;
	}

	/* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
	/* Call registered Abort Transmit Complete Callback */
	huart->AbortTransmitCpltCallback(huart);
#else
	/* Call legacy weak Abort Transmit Complete Callback */
	HAL_UART_AbortTransmitCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  

  return HAL_OK;
}

/**
  * @brief  Abort ongoing Receive transfer (Interrupt mode).
  * @param  huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart)
{
  /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ERBFI|UART_ENABLEIT_ELSI);

  /* Abort the UART DMA Rx channel : use non blocking DMA Abort API (callback) */
  if (huart->hdmarx != NULL)
  {
    /* Set the UART DMA Abort callback :
        will lead to call HAL_UART_AbortCpltCallback() at end of DMA abort procedure */
    huart->hdmarx->XferAbortCallback = UART_DMARxOnlyAbortCallback;

    /* Abort DMA RX */
    if (HAL_DMA_Abort_IT(huart->hdmarx) != HAL_OK)
    {
      /* Call Directly huart->hdmarx->XferAbortCallback function in case of error */
      huart->hdmarx->XferAbortCallback(huart->hdmarx);
    }

    /* Reset Rx transfer counter */
    huart->RxXferCount = 0U;

    /* Clear RxISR function pointer */
    huart->pRxBuffPtr = NULL;

    /* Clear the Error flags in the ICR register */
    __HAL_UART_CLEAR_IT_MODEMSTATUS(huart);
    __HAL_UART_CLEAR_IT_UARTSTATUS(huart);
    __HAL_UART_CLEAR_IT_TXEMPTY(huart);
    __HAL_UART_CLEAR_IT_RXAVAILABLE(huart);
    __HAL_UART_CLEAR_IT_LINESTATUS(huart);

    /* Flush the whole RX FIFO (if needed) */
    if(READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
    {
      huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
    }

		if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
		{
			huart->gState = HAL_UART_STATE_BUSY_TX;
		}
		else
		{
			/* Restore huart->RxState to Ready */
			huart->gState = HAL_UART_STATE_READY;
		}
    huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Receive Complete Callback */
    huart->AbortReceiveCpltCallback(huart);
#else
    /* Call legacy weak Abort Receive Complete Callback */
    HAL_UART_AbortReceiveCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
  else
  {
    /* Reset Rx transfer counter */
    huart->RxXferCount = 0U;

    /* Clear RxISR function pointer */
    huart->pRxBuffPtr = NULL;

    /* Clear the Error flags in the ICR register */
    __HAL_UART_CLEAR_IT_MODEMSTATUS(huart);
    __HAL_UART_CLEAR_IT_UARTSTATUS(huart);
    __HAL_UART_CLEAR_IT_TXEMPTY(huart);
    __HAL_UART_CLEAR_IT_RXAVAILABLE(huart);
    __HAL_UART_CLEAR_IT_LINESTATUS(huart);

    /* Restore huart->RxState to Ready */
    huart->gState = HAL_UART_STATE_READY;
    huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /* Call registered Abort Receive Complete Callback */
    huart->AbortReceiveCpltCallback(huart);
#else
    /* Call legacy weak Abort Receive Complete Callback */
    HAL_UART_AbortReceiveCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }

  return HAL_OK;
}

/**
  * @brief Handle UART interrupt request.
  * @param huart UART handle.
  */
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart)
{
  uint32_t isrflags   = READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_IID);
  uint32_t lsflag;
  uint32_t msflag;
	
	//SEGGER_RTT_printf(0, "IID %d\n", isrflags);

  switch(isrflags)
  {
    case UART_IT_LS: /*!< UART receiver line status, highest priority    */
    {
      lsflag = READ_REG(huart->Instance->LSR);  /* Clear lines status & clear interrupt */ 
			
//  		SEGGER_RTT_WriteString(0, "LS\n");

      if(__HAL_UART_GET_LS_SOURCE(lsflag, UART_LS_DR))
      {
//				SEGGER_RTT_WriteString(0, "LS_DR\n");
        //huart->gState = HAL_UART_STATE_BUSY_RX;
        if (huart->RxISR != NULL)
        {
          huart->RxISR(huart);
        }
      }
      else if(__HAL_UART_GET_LS_SOURCE(lsflag, UART_LS_OE))
      {
        huart->ErrorCode |= HAL_UART_ERROR_OE;
      }
      else if(__HAL_UART_GET_LS_SOURCE(lsflag, UART_LS_PE))
      {
        huart->ErrorCode |= HAL_UART_ERROR_PE;
      }
      else if(__HAL_UART_GET_LS_SOURCE(lsflag, UART_LS_FE))
      {
        huart->ErrorCode |= HAL_UART_ERROR_FE;
      }
      else if(__HAL_UART_GET_LS_SOURCE(lsflag, UART_LS_BI))
      {
        huart->ErrorCode |= HAL_UART_ERROR_BI;
      }
      else if(__HAL_UART_GET_LS_SOURCE(lsflag, UART_LS_RFE))
      {
        huart->ErrorCode |= HAL_UART_ERROR_RFE;
      }
      else if(__HAL_UART_GET_LS_SOURCE(lsflag, UART_LS_THRE))
      {
        //huart->gState = HAL_UART_STATE_BUSY_TX;
        if (huart->TxISR != NULL)
        {
          huart->TxISR(huart);
        }
      }
      else if(__HAL_UART_GET_LS_SOURCE(lsflag, UART_LS_TEMT))
      {
        //huart->gState = HAL_UART_STATE_BUSY_TX;
        if (huart->TxISR != NULL)
        {
          huart->TxISR(huart);
        }
      }
      else
      {

      }
      break;
    }
    case UART_IT_RA: /*!< UART received data available, second priority  */
    {
//			SEGGER_RTT_WriteString(0, "RA\n");
      //huart->gState = HAL_UART_STATE_BUSY_RX; /* clear interrupt by read buffer/FIFO */
      if (huart->RxISR != NULL)
      {
        huart->RxISR(huart);
      }
      break;
    }
    case UART_IT_TO: /*!< UART character timeout, second priority        */
    {
//			SEGGER_RTT_WriteString(0, "TO\n");
      //huart->ErrorCode |= HAL_UART_ERROR_TO;
			
			/* clear interrupt by read buffer/FIFO */
//			{
//				uint32_t temp = huart->Instance->RBR_THR_DLL;
//				SEGGER_RTT_printf(0, "to rx fifo data: %d\n", temp);
//			}
      if (huart->RxISR != NULL)
      {
        huart->RxISR(huart);
      }
      break;
    }
    case UART_IT_TE: /*!< UART THRE empty, third priority                 */
    {
//			SEGGER_RTT_WriteString(0, "TE\n");
      //huart->gState = HAL_UART_STATE_BUSY_TX; /* clear interrupt by read IIR or write THR */
      if (huart->TxISR != NULL)
      {
        huart->TxISR(huart);
      }
      break;
    }
    case UART_IT_MS: /*!< UART modem status interrupt, fourth priority   */
    {
//			SEGGER_RTT_WriteString(0, "MS\n");
      msflag = READ_REG(huart->Instance->MSR);  /* Clear modem status and clear interrupt */
      if(__HAL_UART_GET_MS_SOURCE(msflag, UART_MS_DCD)) 
      {
        /* from DTR */
      }
      else if(__HAL_UART_GET_MS_SOURCE(msflag, UART_MS_RI)) 
      {

      }
      else if(__HAL_UART_GET_MS_SOURCE(msflag, UART_MS_DSR)) 
      {
        /* from DTR */
      }
      else if(__HAL_UART_GET_MS_SOURCE(msflag, UART_MS_CTS)) 
      {
        /* from RTS */
      }
      else
      {

      }
      break;
    }
    case UART_IT_BUSY: /*!< UART busy detect, fifth priority               */
    {
//			SEGGER_RTT_WriteString(0, "BUSY\n");
      huart->gState = HAL_UART_STATE_BUSY;
			/* clear interrupt by read STATE */
			{
				uint32_t temp = huart->Instance->USR; 
			}
      break;
    }
    case UART_IT_NO: /*!< UART no interrupt pending                      */
//			SEGGER_RTT_WriteString(0, "NO\n");
      break;
    default:
      break;
  }

  return;
}

/**
  * @brief Tx Transfer completed callback.
  * @param huart UART handle.
  */
__weak void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_TxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Half Transfer completed callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_TxBlockCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_TxBlockCallback can be implemented in the user file.
   */
}
#if 0
/**
  * @brief  Tx Half Transfer completed callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_TxSrcTranCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_TxSrcTranCallback can be implemented in the user file.
   */
}

/**
  * @brief  Tx Half Transfer completed callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_TxDstTranCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_TxDstTranCallback can be implemented in the user file.
   */
}
#endif //0
/**
  * @brief  Rx Transfer completed callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_RxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Half Transfer completed callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_RxBlockCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxBlockCallback can be implemented in the user file.
   */
}
#if 0
/**
  * @brief  Rx Half Transfer completed callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_RxSrcTranCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxSrcTranCallback can be implemented in the user file.
   */
}

/**
  * @brief  Rx Half Transfer completed callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_RxDstTranCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxDstTranCallback can be implemented in the user file.
   */
}
#endif //0
/**
  * @brief  UART error callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_ErrorCallback can be implemented in the user file.
   */
}

/**
  * @brief  UART Abort Complete callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_AbortCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  UART Abort Complete callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_AbortTransmitCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  UART Abort Receive Complete callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_AbortReceiveCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief  Reception Event Callback (Rx event notification called after use of advanced reception service).
  * @param  huart UART handle
  * @param  Size  Number of data available in application reception buffer (indicates a position in
  *               reception buffer until which, data are available)
  */
__weak void HAL_UART_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  UNUSED(Size);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_RxEventCallback can be implemented in the user file.
   */
}

/**
  * @}
  */

/** @defgroup UART_Exported_Functions_Group3 FIFO Control functions
  *  @brief   UART FIFO control functions
  *
  * @{
  */
/**
  * @brief  UART RX Fifo full callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_RxFifoFullCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_RxFifoFullCallback can be implemented in the user file.
   */
}

/**
  * @brief  UART TX Fifo empty callback.
  * @param  huart UART handle.
  */
__weak void HAL_UART_TxFifoEmptyCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_TxFifoEmptyCallback can be implemented in the user file.
   */
}

/**
  * @brief  Enable the FIFO mode.
  * @param huart      UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_EnableFifoMode(UART_HandleTypeDef *huart)
{
//  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_UART_FIFO_INSTANCE(huart->Instance));

  /* Process Locked */
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

  /* Save actual UART configuration */
  //tmpcr1 = READ_REG(huart->Instance->IIR_FCR);

  /* Disable UART */
//  __HAL_UART_DISABLE(huart);

  /* Enable FIFO mode */
  //SET_BIT(tmpcr1, UART_IIR_FCR_FIFOE);
  huart->FifoMode = UART_FIFOMODE_ENABLE;
	huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;

  /* Restore UART configuration */
	
  /* Determine the number of data to process during RX/TX ISR execution */
  UART_SetNbDataToProcess(huart);

  huart->gState = HAL_UART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief  Disable the FIFO mode.
  * @param huart      UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_DisableFifoMode(UART_HandleTypeDef *huart)
{
//  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_UART_FIFO_INSTANCE(huart->Instance));

  /* Process Locked */
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

  /* Save actual UART configuration */
  //tmpcr1 = READ_REG(huart->Instance->IIR_FCR);

  /* Disable UART */
//  __HAL_UART_DISABLE(huart);

  /* Enable FIFO mode */
  //CLEAR_BIT(tmpcr1, UART_IIR_FCR_FIFOE);
  huart->FifoMode = UART_FIFOMODE_DISABLE;
	huart->Instance->IIR_FCR = huart->FifoMode;

  /* Restore UART configuration */
//  WRITE_REG(huart->Instance->IIR_FCR, tmpcr1);

  huart->gState = HAL_UART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief  Set the TXFIFO threshold.
  * @param huart      UART handle.
  * @param Threshold  TX FIFO threshold value
  *          This parameter can be one of the following values:
  *            @arg @ref UART_TXFIFO_THRESHOLD_EMPTY 
  *            @arg @ref UART_TXFIFO_THRESHOLD_2CHAR 
  *            @arg @ref UART_TXFIFO_THRESHOLD_1_4   
  *            @arg @ref UART_TXFIFO_THRESHOLD_1_2   
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_SetTxFifoThreshold(UART_HandleTypeDef *huart, uint32_t Threshold)
{
//  uint32_t tmpcr1;

  /* Check parameters */
  assert_param(IS_UART_FIFO_INSTANCE(huart->Instance));
  assert_param(IS_UART_TXFIFO_THRESHOLD(Threshold));

  /* Process Locked */
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

  /* Update TX threshold configuration */
  //MODIFY_REG(huart->Instance->IIR_FCR, UART_IIR_FCR_TET, Threshold);
	huart->TxFifoTrigger = Threshold;

  /* Determine the number of data to process during RX/TX ISR execution */
  UART_SetNbDataToProcess(huart);

  huart->gState = HAL_UART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief  Set the RXFIFO threshold.
  * @param huart      UART handle.
  * @param Threshold  RX FIFO threshold value
  *          This parameter can be one of the following values:
  *            @arg @ref UART_RXFIFO_THRESHOLD_1CHAR 
  *            @arg @ref UART_RXFIFO_THRESHOLD_1_4   
  *            @arg @ref UART_RXFIFO_THRESHOLD_1_2   
  *            @arg @ref UART_RXFIFO_THRESHOLD_2FUll 
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_SetRxFifoThreshold(UART_HandleTypeDef *huart, uint32_t Threshold)
{
  /* Check the parameters */
  assert_param(IS_UART_FIFO_INSTANCE(huart->Instance));
  assert_param(IS_UART_RXFIFO_THRESHOLD(Threshold));

  /* Process Locked */
  __HAL_LOCK(huart);

  huart->gState = HAL_UART_STATE_BUSY;

  /* Update RX threshold configuration */
  //MODIFY_REG(huart->Instance->IIR_FCR, UART_IIR_FCR_RCVR, Threshold);
	huart->RxFifoTrigger = Threshold;

  /* Determine the number of data to process during RX/TX ISR execution */
  UART_SetNbDataToProcess(huart);

  huart->gState = HAL_UART_STATE_READY;

  /* Process Unlocked */
  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief Receive an amount of data in blocking mode till either the expected number of data
  *        is received or an IDLE event occurs.
  * @param huart   UART handle.
  * @param pData   Pointer to data buffer (uint8_t or uint16_t data elements).
  * @param Size    Amount of data elements (uint8_t or uint16_t) to be received.
  * @param RxLen   Number of data elements finally received
  *                (could be lower than Size, in case reception ends on IDLE event)
  * @param Timeout Timeout duration expressed in ms (covers the whole reception sequence).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout)
{
  uint8_t  *pdata8bits;
  uint32_t uhMask = 0xFF;
  uint32_t tickstart = 0;
	uint32_t idlestart = 0;

  /* Check that a Rx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return  HAL_ERROR;
    }

    __HAL_LOCK(huart);

    huart->ErrorCode = HAL_UART_ERROR_NONE;
    huart->gState = HAL_UART_STATE_BUSY_RX;
    huart->ReceptionType = HAL_UART_RECEPTION_TOIDLE;

    /* Init tickstart for timeout management */
    tickstart = HAL_GetTick();

    huart->RxXferSize  = Size;
    huart->RxXferCount = Size;

    /* Computation of UART mask to apply to RDR register */
    if(huart->Mask > 0)
    {
      uhMask = huart->Mask;
    }

    /* In case of 9bits/No Parity transfer, pRxData needs to be handled as a uint16_t pointer */
    pdata8bits  = pData;

    __HAL_UNLOCK(huart);

    /* Initialize output number of received elements */
    *RxLen = 0U;

    /* as long as data have to be received */
		idlestart = HAL_GetTick();
    while (huart->RxXferCount > 0U)
    {
			
      /* Check if IDLE flag is set */
      if (!__HAL_UART_GET_STATUS(huart, UART_STATE_BUSY)) 
      {
				/* If Set, but no data ever received, clear flag without exiting loop */
				/* If Set, and data has already been received, this means Idle Event is valid : End reception */
				if (*RxLen > 0U)
				{
					if(((HAL_GetTick() - idlestart) > 100))
					{
					  huart->gState = HAL_UART_STATE_READY;

					  return HAL_OK;
					}
				}
				else
				{
					idlestart = HAL_GetTick();
				}
      }
			else
			{
				idlestart = HAL_GetTick();
			}

      /* Check if RXNE flag is set */
      if (__HAL_UART_GET_LS_FLAG(huart, UART_LS_DR))
      {
        *pdata8bits = (uint8_t)(huart->Instance->RBR_THR_DLL & (uint8_t)uhMask);
        pdata8bits++;

        /* Increment number of received elements */
        *RxLen += 1U;
        huart->RxXferCount--;
				
				idlestart = HAL_GetTick();
      }

      /* Check for the Timeout */
      if (Timeout != HAL_MAX_DELAY)
      {
        if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
        {
          huart->gState = HAL_UART_STATE_READY;

          return HAL_TIMEOUT;
        }
      }
    }

    /* Set number of received elements in output parameter : RxLen */
    *RxLen = huart->RxXferSize - huart->RxXferCount;
    /* At end of Rx process, restore huart->RxState to Ready */
    huart->gState = HAL_UART_STATE_READY;

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief Receive an amount of data in interrupt mode or stop at the special character.
  * @param huart UART handle.
  * @param pData Pointer to data buffer (u8 data elements).
  * @param Size  Amount of data elements (u16) to be received.
  * @param Char  stop character.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Receive_IT_MatchChar(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint8_t Char)
{
  /* Check that a Rx process is not already ongoing */
  if (huart->gState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    __HAL_LOCK(huart);

    /* Set Reception type to Standard reception */
    huart->ReceptionType = HAL_UART_RECEPTION_TOCHARMATCH;
	huart->MatchChar     = Char;

    return (UART_Start_Receive_IT(huart, pData, Size));
  }
  else
  {
    return HAL_BUSY;
  }
}


/**
  * @}
  */

/** @defgroup UART_Exported_Functions_Group4 Peripheral State and Error functions
  *  @brief   UART Peripheral State functions
  *
  * @{
  */

/**
  * @brief Return the UART handle state.
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART.
  * @retval HAL state
  */
HAL_UART_StateTypeDef HAL_UART_GetState(UART_HandleTypeDef *huart)
{
  return (HAL_UART_StateTypeDef)(huart->gState);
}

/**
  * @brief  Return the UART handle error code.
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART.
  * @retval UART Error Code
  */
uint32_t HAL_UART_GetError(UART_HandleTypeDef *huart)
{
  return huart->ErrorCode;
}
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup UART_Private_Functions UART Private Functions
  * @{
  */

/**
  * @brief  Initialize the callbacks to their default values.
  * @param  huart UART handle.
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
void UART_InitCallbacksToDefault(UART_HandleTypeDef *huart)
{
  /* Init the UART Callback settings */
  huart->TxCpltCallback            = HAL_UART_TxCpltCallback;            /* Legacy weak TxCpltCallback            */
  huart->TxBlockCallback           = HAL_UART_TxBlockCallback;           /* Legacy weak TxBlockCallback           */
  huart->TxSrcTranCallback         = HAL_UART_TxSrcTranCallback;         /* Legacy weak TxSrcTranCallback         */
  huart->TxDstTranCallback         = HAL_UART_TxDstTranCallback;         /* Legacy weak TxDstTranCallback         */
  huart->RxCpltCallback            = HAL_UART_RxCpltCallback;            /* Legacy weak RxCpltCallback            */
  huart->RxBlockCallback           = HAL_UART_RxBlockCallback;           /* Legacy weak RxBlockCallback           */
  huart->RxSrcTranCallback         = HAL_UART_RxSrcTranCallback;         /* Legacy weak RxSrcTranCallback         */
  huart->RxDstTranCallback         = HAL_UART_RxDstTranCallback;         /* Legacy weak RxDstTranCallback         */
  huart->ErrorCallback             = HAL_UART_ErrorCallback;             /* Legacy weak ErrorCallback             */
  huart->AbortCpltCallback         = HAL_UART_AbortCpltCallback;         /* Legacy weak AbortCpltCallback         */
  huart->AbortTransmitCpltCallback = HAL_UART_AbortTransmitCpltCallback; /* Legacy weak AbortTransmitCpltCallback */
  huart->AbortReceiveCpltCallback  = HAL_UART_AbortReceiveCpltCallback;  /* Legacy weak AbortReceiveCpltCallback  */
  huart->RxFifoFullCallback        = HAL_UART_RxFifoFullCallback;      /* Legacy weak RxFifoFullCallback        */
  huart->TxFifoEmptyCallback       = HAL_UART_TxFifoEmptyCallback;     /* Legacy weak TxFifoEmptyCallback       */
  huart->RxEventCallback           = HAL_UART_RxEventCallback;         /* Legacy weak RxEventCallback           */

}
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @brief Configure the UART peripheral.
  * @param huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef UART_SetConfig(UART_HandleTypeDef *huart)
{
  uint32_t tmpreg;
  uint32_t usartdiv;
  HAL_StatusTypeDef ret = HAL_OK;
  uint32_t sclk;

  /* Check the parameters */
  assert_param(IS_UART_BAUDRATE(huart->Init.BaudRate));
  assert_param(IS_UART_WORD_LENGTH(huart->Init.WordLength));
  assert_param(IS_UART_STOPBITS(huart->Init.StopBits));
  assert_param(IS_UART_PARITY(huart->Init.Parity));
  assert_param(IS_UART_HARDWARE_FLOW_CONTROL(huart->Init.HwFlowCtl));
	assert_param(IS_UART_LOOPBACK(huart->Init.LoopBack));

  /*-------------------------- UART LCR Configuration -----------------------*/
  tmpreg = (uint32_t)huart->Init.WordLength | huart->Init.Parity | huart->Init.StopBits | huart->Init.LoopBack;
  MODIFY_REG(huart->Instance->LCR, UART_LCR_DLS | UART_LCR_STOP | UART_LCR_PEN | UART_LCR_EPS | UART_MCR_LB, tmpreg);

  /*-------------------------- UART MCR Configuration -----------------------*/
  tmpreg = (uint32_t)huart->Init.HwFlowCtl;
  MODIFY_REG(huart->Instance->MCR, UART_MCR_AFCE, tmpreg);
	if(huart->Init.HwFlowCtl == UART_HWCONTROL_ENABLE)
	{
	  SET_BIT(huart->Instance->MCR, UART_MCR_RTS);
	}
	
	if(huart->Init.IsIrDA)
	{
		SET_BIT(huart->Instance->MCR, UART_MCR_SIRE);
		if(huart->Instance == UART1)
		{
		  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART1_MODE);
		}
		else if(huart->Instance == UART2)
		{
		  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART2_MODE);
		}
		else if(huart->Instance == UART3)
		{
		  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART3_MODE);
		}
		else if(huart->Instance == UART4)
		{
		  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART4_MODE);
		}
	}
	else
	{
		CLEAR_BIT(huart->Instance->MCR, UART_MCR_SIRE);
		if(huart->Instance == UART1)
		{
		  CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART1_MODE);
		}
		else if(huart->Instance == UART2)
		{
		  CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART2_MODE);
		}
		else if(huart->Instance == UART3)
		{
		  CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART3_MODE);
		}
		else if(huart->Instance == UART4)
		{
		  CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_UART4_MODE);
		}
	}

  /*-------------------------- UART Baudrate Configuration -----------------------*/
  {
	  sclk = HAL_RCC_GetPeriphCLKFreq(RCC_PERIPHCLK_BR);
  //  sclk = 50000000;  //just for fpga flash bist test
    if (sclk != 0U)
    {
//      uint32_t tickstart;
//      tickstart = HAL_GetTick();

      usartdiv = ((( sclk ) / huart->Init.BaudRate) >> 3);
      usartdiv = (( usartdiv >> 1 ) + (usartdiv & 0x1));

//      if (UART_WaitOnUartStatusUntilTimeout(huart, UART_STATE_BUSY, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
//      {
        /* Timeout occurred */
//        return HAL_TIMEOUT;
//      }

      SET_BIT(huart->Instance->LCR, UART_LCR_DLAB);
      if ((usartdiv > 0xFF))
      {
        MODIFY_REG(huart->Instance->DLH_IER, UART_DLH_IER_DLH, ((usartdiv >> 8) & 0xFF));
      }
      MODIFY_REG(huart->Instance->RBR_THR_DLL, UART_RBR_THR_DLL_DLL, (usartdiv & 0xFF));
      CLEAR_BIT(huart->Instance->LCR, UART_LCR_DLAB);
    }
  }

  /* initialize data mask */
  huart->Mask = ((huart->Init.WordLength == UART_WORDLENGTH_5) ? 0x1F : \
                 (huart->Init.WordLength == UART_WORDLENGTH_6) ? 0x3F : \
                 (huart->Init.WordLength == UART_WORDLENGTH_7) ? 0x7F : \
                 0xFF);

  /* Initialize the number of data to process during RX/TX ISR execution */
  huart->NbTxDataToProcess = 1;
  huart->NbRxDataToProcess = 1;

  /* Clear ISR function pointers */
  huart->RxISR = NULL;
  huart->TxISR = NULL;
	
	/* disable all interrupts */
	huart->Instance->DLH_IER = 0;

  return ret;
}

/**
  * @brief Configure the UART peripheral buadrate.
  * @param huart UART handle.
  * @param Baudrate
  * @retval HAL status
  */
HAL_StatusTypeDef UART_SetBaudRate(UART_HandleTypeDef *huart,uint32_t Baudrate)
{
	HAL_StatusTypeDef ret = HAL_OK;
	uint32_t usartdiv;
	uint32_t sclk;

	sclk = HAL_RCC_GetPeriphCLKFreq(RCC_PERIPHCLK_BR);
	
	if (sclk != 0U)
	{
//    uint32_t tickstart;
//    tickstart = HAL_GetTick();
		/* USARTDIV must be greater than or equal to 0d16 */
		usartdiv = (((sclk) / Baudrate) >> 3);
    usartdiv = ((usartdiv >> 1) + (usartdiv&0x01));

//    if (UART_WaitOnUartStatusUntilTimeout(huart, UART_STATE_BUSY, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
//    {
       /* Timeout occurred */
//       return HAL_TIMEOUT;
//    }
  
		SET_BIT(huart->Instance->LCR, UART_LCR_DLAB);
		if ((usartdiv & 0x0000FF00UL))
		{
			MODIFY_REG(huart->Instance->DLH_IER, UART_DLH_IER_DLH, ((usartdiv >> 8) & 0xFF));
		}
		//MODIFY_REG(huart->Instance->RBR_THR_DLL, UART_RBR_THR_DLL_DLL, (usartdiv & 0xFF));
		huart->Instance->RBR_THR_DLL = (usartdiv & 0x000000FFUL);
		CLEAR_BIT(huart->Instance->LCR, UART_LCR_DLAB);
	}

	return ret;
}

/**
  * @brief Check the UART Idle State.
  * @param huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef UART_CheckIdleState(UART_HandleTypeDef *huart)
{
//  uint32_t tickstart;

  /* Initialize the UART ErrorCode */
  huart->ErrorCode = HAL_UART_ERROR_NONE;

  /* Init tickstart for timeout management */
  //tickstart = HAL_GetTick();

  /* Wait until IDLE flag is set */
  //if (UART_WaitOnUartStatusUntilTimeout(huart, UART_STATE_BUSY, RESET, tickstart, HAL_UART_TIMEOUT_VALUE) != HAL_OK)
  //{
     /* Timeout occurred */
  //   return HAL_TIMEOUT;
  //}

  /* Initialize the UART State */
  huart->gState = HAL_UART_STATE_READY;
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

  __HAL_UNLOCK(huart);

  return HAL_OK;
}

/**
  * @brief  Handle UART Communication Timeout.
  * @param huart     UART handle.
  * @param Flag      Specifies the UART flag to check
  * @param Status    Flag status (SET or RESET)
  * @param Tickstart Tick start value
  * @param Timeout   Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef UART_WaitOnUartStatusUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout)
{
  /* Wait until flag is set */
  while ((__HAL_UART_GET_STATUS(huart, Flag) ? SET : RESET) != Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
      {
        huart->gState = HAL_UART_STATE_READY;

        __HAL_UNLOCK(huart);

        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  Check Line status Timeout.
  * @param huart     UART handle.
  * @param Flag      Specifies the UART flag to check
  * @param Status    Flag status (SET or RESET)
  * @param Tickstart Tick start value
  * @param Timeout   Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef UART_WaitOnLineStatusUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout)
{
  /* Wait until flag is set */
  while ((__HAL_UART_GET_LS_FLAG(huart, Flag) ? SET : RESET) != Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
      {
        huart->gState = HAL_UART_STATE_READY;

        __HAL_UNLOCK(huart);

        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  Check Modem status Timeout.
  * @param huart     UART handle.
  * @param Flag      Specifies the UART flag to check
  * @param Status    Flag status (SET or RESET)
  * @param Tickstart Tick start value
  * @param Timeout   Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef UART_WaitOnModemStatusUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status,
                                              uint32_t Tickstart, uint32_t Timeout)
{
  /* Wait until flag is set */
  while ((__HAL_UART_GET_MS_FLAG(huart, Flag) ? SET : RESET) != Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
      {
        huart->gState = HAL_UART_STATE_READY;

        __HAL_UNLOCK(huart);

        return HAL_TIMEOUT;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  Start Receive operation in interrupt mode.
  * @param  huart UART handle.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  huart->pRxBuffPtr  = pData;
  huart->RxXferSize  = Size;
  huart->RxXferCount = Size;
  huart->RxISR       = NULL;

  huart->ErrorCode = HAL_UART_ERROR_NONE;
  huart->gState = HAL_UART_STATE_BUSY_RX;

  /* Configure Rx interrupt processing */
  if ((huart->FifoMode == UART_FIFOMODE_ENABLE) /*&& (Size >= huart->NbRxDataToProcess)*/)
  {
    /* Set the Rx ISR function pointer according to the data word length */
    huart->RxISR = UART_RxISR_FIFOEN;
  }
  else
  {
    /* Set the Rx ISR function pointer according to the data word length */
    huart->RxISR = UART_RxISR;
  }

  __HAL_UNLOCK(huart);

  /* Enable the UART line status Interrupt: (Frame error, parity error, overrun error ..) */
	__HAL_UART_IT_CLEAR_LS(huart);
	__HAL_UART_IT_CLEAR_RA(huart);
  __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ELSI);   //enable receiver line status
  __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ERBFI);  //enable receuved data available

  return HAL_OK;
}

/**
  * @brief  Start Receive operation in DMA mode.
  * @param  huart UART handle.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  huart->pRxBuffPtr = pData;
  huart->RxXferSize = Size;
  huart->RxXferCount = Size;

  huart->ErrorCode = HAL_UART_ERROR_NONE;
  huart->gState = HAL_UART_STATE_BUSY_RX;

  if (huart->hdmarx != NULL)
  {
    /* Set the UART DMA transfer complete callback */
    huart->hdmarx->XferCpltCallback = UART_DMAReceiveCplt;

    /* Set the UART DMA Half transfer complete callback */
		huart->hdmarx->XferBlockCallback = UART_DMARxBlock;
	
    /* Set the DMA error callback */
    huart->hdmarx->XferErrorCallback = UART_DMAError;

    /* Set the DMA abort callback */
    huart->hdmarx->XferAbortCallback = NULL;

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(huart->hdmarx, (uint32_t)&huart->Instance->RBR_THR_DLL, (uint32_t)huart->pRxBuffPtr, Size) != HAL_OK)
    {
      /* Set error code to DMA */
      huart->ErrorCode = HAL_UART_ERROR_DMA;

      __HAL_UNLOCK(huart);

      /* Restore huart->RxState to ready */
      huart->gState = HAL_UART_STATE_READY;

      return HAL_ERROR;
    }
  }
  __HAL_UNLOCK(huart);

//  __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ELSI);
//  __HAL_UART_ENABLE_IT(huart, UART_ENABLEIT_ERBFI);
  __HAL_UART_IT_CLEAR_RA(huart);

  return HAL_OK;
}

#if defined(XT32H0xxB) ||defined(XT32H0xxBMPW)
/**
  * @brief  Autodetect baudrate.
  * 
  * @param  huart UART handle.
  * @param  pBaudRate  pointer to baudrate.
  * @retval HAL status
  */
HAL_StatusTypeDef UART_Detect_BaudRate(UART_HandleTypeDef *huart, uint32_t *pBaudRate)
{
	uint32_t br;
	
	CLEAR_BIT(ICTL->IRQINTMASKL, 0xF0000000);
	SET_BIT(ICTL->IRQINTENL, 0xF0000000);
	
	/* config sim */
	CLEAR_BIT(SYSCFG->IRQ_CFG_1, 0xF0000000);
	
	if (huart->Instance == UART1)
	{
		SYSCFG->UART_ADCFG |= 0x00000003UL;  //auto en|int en
		
		while((SYSCFG->UART_ADFLG & 0x00000001UL) == 0)
		{
		}
		 
		br = SYSCFG->UART1_ADBR;
		br = HAL_RCC_GetPCLKFreq()/br;	
		
		*pBaudRate = br;
		
		SYSCFG->UART_ADCFG |= 0x00000004UL;
		SYSCFG->UART_ADCFG &= 0xFFFFFFFCUL;  //auto disable|int disable
  }
	else if (huart->Instance == UART2)
	{
		SYSCFG->UART_ADCFG |= 0x00000300UL;  //auto en|int en
		
		while((SYSCFG->UART_ADFLG & 0x00000002UL) == 0)
		{
		}
		 
		br = SYSCFG->UART2_ADBR;
		br = HAL_RCC_GetPCLKFreq()/br;	
		
		*pBaudRate = br;
		
		SYSCFG->UART_ADCFG |= 0x00000400UL;
		SYSCFG->UART_ADCFG &= 0xFFFFFCFFUL;  //auto en|int en
  }
	else if (huart->Instance == UART3)
	{
		SYSCFG->UART_ADCFG |= 0x00030000UL;  //auto en|int en
		
		while((SYSCFG->UART_ADFLG & 0x00000004UL) == 0)
		{
		}
		 
		br = SYSCFG->UART3_ADBR;
		br = HAL_RCC_GetPCLKFreq()/br;	
		
		*pBaudRate = br;
		
		SYSCFG->UART_ADCFG |= 0x00040000UL;
		SYSCFG->UART_ADCFG &= 0xFFFCFFFFUL;  //auto en|int en
  }
	else if (huart->Instance == UART4)
	{
		SYSCFG->UART_ADCFG |= 0x03000000UL;  //auto en|int en
		
		while((SYSCFG->UART_ADFLG & 0x00000008UL) == 0)
		{
		}
		 
		br = SYSCFG->UART4_ADBR;
		br = HAL_RCC_GetPCLKFreq()/br;	
		
		*pBaudRate = br;
		
		SYSCFG->UART_ADCFG |= 0x04000000UL;
		SYSCFG->UART_ADCFG &= 0xFCFFFFFFUL;  //auto en|int en
  }

	return HAL_OK;
}

/**
  * @brief  Autodetect baudrate Complete.
  * 
  * @param  huart UART handle.
  * @retval HAL status
  */
HAL_StatusTypeDef UART_Detect_BaudRateComplete(UART_HandleTypeDef *huart)
{
	uint8_t flag[6]="ADCLP";
	return HAL_UART_Transmit(huart, (uint8_t *)flag, 5, 5000);
}
#endif

/**
  * @brief  End ongoing Tx transfer on UART peripheral (following error detection or Transmit completion).
  * @param  huart UART handle.
  */
static void UART_EndTxTransfer(UART_HandleTypeDef *huart)
{
  /* Disable TXEIE, TCIE, TXFT interrupts */
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ETBEI);
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ELSI);

  /* At end of Tx process, restore huart->gState to Ready */
  huart->gState = HAL_UART_STATE_READY;
	
	huart->TxISR = NULL;
}


/**
  * @brief  End ongoing Rx transfer on UART peripheral (following error detection or Reception completion).
  * @param  huart UART handle.
  */
static void UART_EndRxTransfer(UART_HandleTypeDef *huart)
{
  /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ERBFI);
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ELSI);


  /* At end of Rx process, restore huart->RxState to Ready */
  huart->gState = HAL_UART_STATE_READY;
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

  /* Reset RxIsr function pointer */
  huart->RxISR = NULL;
}

/**
  * @brief  End ongoing TX_Rx transfer on UART peripheral (following error detection or Reception completion).
  * @param  huart UART handle.
  */
static void UART_EndTxRxTransfer(UART_HandleTypeDef *huart)
{
  /* Disable interrupts */
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ETBEI);
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ELSI);
  __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ERBFI);

  /* At end of Tx process, restore huart->gState to Ready */
  huart->gState = HAL_UART_STATE_READY;
	huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;
	
	huart->RxISR = NULL;
	huart->TxISR = NULL;
}


/**
  * @brief DMA UART transmit process complete callback.
  * @param hdma DMA handle.
  */
static void UART_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);
	
	if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
	{
		huart->gState = HAL_UART_STATE_BUSY_RX;
	}
	else
	{
	  huart->gState = HAL_UART_STATE_READY;
	}


#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx complete callback*/
  huart->TxCpltCallback(huart);
#else
  /*Call legacy weak Tx complete callback*/
  HAL_UART_TxCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART transmit process half complete callback.
  * @param hdma DMA handle.
  */
static void UART_DMATxBlock(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Half complete callback*/
  huart->TxBlockCallback(huart);
#else
  /*Call legacy weak Tx Half complete callback*/
  HAL_UART_TxBlockCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

#if 0
/**
  * @brief DMA UART transmit process half complete callback.
  * @param hdma DMA handle.
  */
static void UART_DMATxSrcTran(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Half complete callback*/
  huart->TxSrcTranCallback(huart);
#else
  /*Call legacy weak Tx Half complete callback*/
  HAL_UART_TxSrcTranCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief DMA UART transmit process half complete callback.
  * @param hdma DMA handle.
  */
static void UART_DMATxDstTran(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx Half complete callback*/
  huart->TxDstTranCallback(huart);
#else
  /*Call legacy weak Tx Half complete callback*/
  HAL_UART_TxDstTranCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}
#endif //0

/**
  * @brief DMA UART receive process complete callback.
  * @param hdma DMA handle.
  */
static void UART_DMAReceiveCplt(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);
	
	
	if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
	{
		huart->gState = HAL_UART_STATE_BUSY_TX;
	}
	else
	{
	  huart->gState = HAL_UART_STATE_READY;
	}
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;


  /* Check current reception Mode :
     If Reception till IDLE event has been selected : use Rx Event callback */
  if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
  {
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Rx Event callback*/
    huart->RxEventCallback(huart, huart->RxXferSize);
#else
    /*Call legacy weak Rx Event callback*/
    HAL_UART_RxEventCallback(huart, huart->RxXferSize);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
  else
  {
    /* In other cases : use Rx Complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Rx complete callback*/
    huart->RxCpltCallback(huart);
#else
    /*Call legacy weak Rx complete callback*/
    HAL_UART_RxCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
}

/**
  * @brief DMA UART receive process block complete callback.
  * @param hdma DMA handle.
  */
static void UART_DMARxBlock(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  /* Check current reception Mode :
     If Reception till IDLE event has been selected : use Rx Event callback */
  if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
  {
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Rx Event callback*/
    huart->RxEventCallback(huart, huart->RxXferSize / 2U);
#else
    /*Call legacy weak Rx Event callback*/
    HAL_UART_RxEventCallback(huart, huart->RxXferSize / 2U);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
  else
  {
    /* In other cases : use Rx Half Complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Rx Half complete callback*/
    huart->RxBlockCallback(huart);
#else
    /*Call legacy weak Rx Half complete callback*/
    HAL_UART_RxBlockCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
}

#if 0
/**
  * @brief DMA UART receive process block complete callback.
  * @param hdma DMA handle.
  */
static void UART_DMARxSrcTran(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  /* Check current reception Mode :
     If Reception till IDLE event has been selected : use Rx Event callback */
  if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
  {
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Rx Event callback*/
    huart->RxEventCallback(huart, huart->RxXferSize / 2U);
#else
    /*Call legacy weak Rx Event callback*/
    HAL_UART_RxEventCallback(huart, huart->RxXferSize / 2U);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
  else
  {
    /* In other cases : use Rx Half Complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Rx Half complete callback*/
    huart->RxSrcTranCallback(huart);
#else
    /*Call legacy weak Rx Half complete callback*/
    HAL_UART_RxSrcTranCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
}

/**
  * @brief DMA UART receive process block complete callback.
  * @param hdma DMA handle.
  */
static void UART_DMARxDstTran(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  /* Check current reception Mode :
     If Reception till IDLE event has been selected : use Rx Event callback */
  if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
  {
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Rx Event callback*/
    huart->RxEventCallback(huart, huart->RxXferSize / 2U);
#else
    /*Call legacy weak Rx Event callback*/
    HAL_UART_RxEventCallback(huart, huart->RxXferSize / 2U);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
  else
  {
    /* In other cases : use Rx Half Complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
    /*Call registered Rx Half complete callback*/
    huart->RxDstTranCallback(huart);
#else
    /*Call legacy weak Rx Half complete callback*/
    HAL_UART_RxDstTranCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
  }
}
#endif //0
/**
  * @brief DMA UART communication error callback.
  * @param hdma DMA handle.
  */
static void UART_DMAError(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  const HAL_UART_StateTypeDef gstate = huart->gState;

  /* Stop UART DMA Tx request if ongoing */
  if (gstate == HAL_UART_STATE_BUSY_TX) 
  {
    huart->TxXferCount = 0U;
    UART_EndTxTransfer(huart);
  }

  /* Stop UART DMA Rx request if ongoing */
  if (gstate == HAL_UART_STATE_BUSY_RX) 
  {
    huart->RxXferCount = 0U;
    UART_EndRxTransfer(huart);
  }
	
	/* Stop UART DMA Tx Rx request if ongoing */
	if (gstate == HAL_UART_STATE_BUSY_TX_RX)
  {
		huart->TxXferCount = 0U;
    huart->RxXferCount = 0U;
    UART_EndTxRxTransfer(huart);
  }

  huart->ErrorCode |= HAL_UART_ERROR_DMA;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered error callback*/
  huart->ErrorCallback(huart);
#else
  /*Call legacy weak error callback*/
  HAL_UART_ErrorCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

#if 0
/**
  * @brief  DMA UART communication abort callback, when initiated by HAL services on Error
  *         (To be called at end of DMA Abort procedure following error occurrence).
  * @param  hdma DMA handle.
  */
static void UART_DMAAbortOnError(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);
  huart->RxXferCount = 0U;
  huart->TxXferCount = 0U;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered error callback*/
  huart->ErrorCallback(huart);
#else
  /*Call legacy weak error callback*/
  HAL_UART_ErrorCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}
#endif //0

/**
  * @brief  DMA UART Tx communication abort callback, when initiated by user
  *         (To be called at end of DMA Tx Abort procedure following user abort request).
  * @param  hdma DMA handle.
  */
static void UART_DMATxAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  huart->hdmatx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (huart->hdmarx != NULL)
  {
    if (huart->hdmarx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  huart->TxXferCount = 0U;
  huart->RxXferCount = 0U;

  /* Reset errorCode */
  huart->ErrorCode = HAL_UART_ERROR_NONE;

  /* Clear the Error flags in the ICR register */
//  __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

  /* Flush the whole TX FIFO (if needed) */
  if (huart->FifoMode == UART_FIFOMODE_ENABLE)
  {
    huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
  }

  /* Restore huart->gState and huart->RxState to Ready */
  huart->gState  = HAL_UART_STATE_READY;
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

  /* Call user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort complete callback */
  huart->AbortCpltCallback(huart);
#else
  /* Call legacy weak Abort complete callback */
  HAL_UART_AbortCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}


/**
  * @brief  DMA UART Rx communication abort callback, when initiated by user
  *         (To be called at end of DMA Rx Abort procedure following user abort request).
  * @param  hdma DMA handle.
  */
static void UART_DMARxAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  huart->hdmarx->XferAbortCallback = NULL;

  /* Check if an Abort process is still ongoing */
  if (huart->hdmatx != NULL)
  {
    if (huart->hdmatx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA channels are aborted, call user Abort Complete callback */
  huart->TxXferCount = 0U;
  huart->RxXferCount = 0U;

  /* Reset errorCode */
  huart->ErrorCode = HAL_UART_ERROR_NONE;

  /* Clear the Error flags in the ICR register */
//  __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

  /* Discard the received data */
  if (READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
  {
    huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
  }

  /* Restore huart->gState and huart->RxState to Ready */
  huart->gState  = HAL_UART_STATE_READY;
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

  /* Call user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort complete callback */
  huart->AbortCpltCallback(huart);
#else
  /* Call legacy weak Abort complete callback */
  HAL_UART_AbortCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}


/**
  * @brief  DMA UART Tx communication abort callback, when initiated by user by a call to
  *         HAL_UART_AbortTransmit_IT API (Abort only Tx transfer)
  *         (This callback is executed at end of DMA Tx Abort procedure following user abort request,
  *         and leads to user Tx Abort Complete callback execution).
  * @param  hdma DMA handle.
  */
static void UART_DMATxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)(hdma->Parent);

  huart->TxXferCount = 0U;

  /* Flush the whole TX FIFO (if needed) */
  if (READ_BIT(huart->Instance->IIR_FCR, UART_IIR_FCR_FIFOSE))
  {
    huart->Instance->IIR_FCR = huart->FifoMode|huart->RxFifoTrigger|huart->TxFifoTrigger;
  }

  /* Restore huart->gState to Ready */
  huart->gState = HAL_UART_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Transmit Complete Callback */
  huart->AbortTransmitCpltCallback(huart);
#else
  /* Call legacy weak Abort Transmit Complete Callback */
  HAL_UART_AbortTransmitCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA UART Rx communication abort callback, when initiated by user by a call to
  *         HAL_UART_AbortReceive_IT API (Abort only Rx transfer)
  *         (This callback is executed at end of DMA Rx Abort procedure following user abort request,
  *         and leads to user Rx Abort Complete callback execution).
  * @param  hdma DMA handle.
  */
static void UART_DMARxOnlyAbortCallback(DMA_HandleTypeDef *hdma)
{
  UART_HandleTypeDef *huart = (UART_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  huart->RxXferCount = 0U;

  /* Clear the Error flags in the ICR register */
//  __HAL_UART_CLEAR_FLAG(huart, UART_CLEAR_OREF | UART_CLEAR_NEF | UART_CLEAR_PEF | UART_CLEAR_FEF);

  /* Discard the received data */
//  __HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);

  /* Restore huart->RxState to Ready */
  huart->gState = HAL_UART_STATE_READY;
  huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

  /* Call user Abort complete callback */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /* Call registered Abort Receive Complete Callback */
  huart->AbortReceiveCpltCallback(huart);
#else
  /* Call legacy weak Abort Receive Complete Callback */
  HAL_UART_AbortReceiveCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief TX interrupt handler for 7 or 8 bits data word length .
  * @param huart UART handle.
  */
static void UART_TxISR(UART_HandleTypeDef *huart)
{
  uint32_t uhMask = ((huart->Mask > 0) ? huart->Mask : 0xFF);
  
	READ_REG(huart->Instance->LSR);  /*!< Clear LS */

  /* Check that a Tx process is ongoing */
  if ((huart->gState == HAL_UART_STATE_BUSY_TX) || (huart->gState == HAL_UART_STATE_BUSY_TX_RX))
  {
    if (huart->TxXferCount == 0U)
    {
      /* Enable the UART Transmit Complete Interrupt */
      SET_BIT(huart->Instance->DLH_IER, UART_DLH_IER_ETBEI);

      UART_EndTransmit_IT(huart);
    }
    else
    {
      huart->Instance->RBR_THR_DLL = (uint8_t)(*huart->pTxBuffPtr & (uint8_t)uhMask);
      huart->pTxBuffPtr++;
      huart->TxXferCount--;
    }
  }
}

/**
  * @brief TX interrupt handler for 7 or 8 bits data word length and FIFO mode is enabled.
  * @param huart UART handle.
  */
static void UART_TxISR_FIFOEN(UART_HandleTypeDef *huart)
{
  uint16_t  nb_tx_data;
  uint32_t uhMask = ((huart->Mask > 0) ? huart->Mask : 0xFF);

  READ_REG(huart->Instance->LSR);  /*!< Clear LS */

  /* Check that a Tx process is ongoing */
  if ((huart->gState == HAL_UART_STATE_BUSY_TX) || (huart->gState == HAL_UART_STATE_BUSY_TX_RX))
  {
    for (nb_tx_data = huart->NbTxDataToProcess ; nb_tx_data > 0U ; nb_tx_data--)
    {
      if (huart->TxXferCount == 0U)
      {
        /* Enable the UART Transmit Complete Interrupt */
        SET_BIT(huart->Instance->DLH_IER, UART_DLH_IER_ETBEI);
        SET_BIT(huart->Instance->DLH_IER, UART_ENABLEIT_PTIME);

        UART_EndTransmit_IT(huart);

        break; /* force exit loop */
      }
      else 
      {
        huart->Instance->RBR_THR_DLL = (uint8_t)(*huart->pTxBuffPtr & (uint8_t)uhMask);
        huart->pTxBuffPtr++;
        huart->TxXferCount--;
      }
    }
  }
}

/**
  * @brief  Wrap up transmission in non-blocking mode.
  * @param  huart pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  */
static void UART_EndTransmit_IT(UART_HandleTypeDef *huart)
{
  /* Disable the UART Transmit Complete Interrupt */
  CLEAR_BIT(huart->Instance->DLH_IER, UART_DLH_IER_ETBEI);

  /* Clear lines status */
  READ_REG(huart->Instance->LSR);

  /* Tx process is ended, restore huart->gState to Ready */
	if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
	{
		huart->gState = HAL_UART_STATE_BUSY_RX;
	}
	else
	{
    huart->gState = HAL_UART_STATE_READY;
	}

  /* Cleat TxISR function pointer */
  huart->TxISR = NULL;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  /*Call registered Tx complete callback*/
  huart->TxCpltCallback(huart);
#else
  /*Call legacy weak Tx complete callback*/
  HAL_UART_TxCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
}

/**
  * @brief RX interrupt handler for 7 or 8 bits data word length .
  * @param huart UART handle.
  */
static void UART_RxISR(UART_HandleTypeDef *huart)
{
  uint32_t uhMask = ((huart->Mask > 0) ? huart->Mask : 0xFF);
  uint16_t  uhdata;

  READ_REG(huart->Instance->LSR);  /*!< Clear lines status */

  /* Check that a Rx process is ongoing */
  if ((huart->gState == HAL_UART_STATE_BUSY_RX) || (huart->gState == HAL_UART_STATE_BUSY_TX_RX))
  {
    uhdata = (uint16_t) READ_REG(huart->Instance->RBR_THR_DLL);
    *huart->pRxBuffPtr = (uint8_t)(uhdata & (uint8_t)uhMask);
    huart->pRxBuffPtr++;
    huart->RxXferCount--;

//		SEGGER_RTT_printf(0, "rx data: %d\n", uhdata);
	if (huart->ReceptionType == HAL_UART_RECEPTION_TOCHARMATCH)
	{
		if(*(huart->pRxBuffPtr-1) == huart->MatchChar)
		{
			huart->RxXferCount = 0;
		}
	}
		
    if (huart->RxXferCount == 0U)
    {
      /* Rx process is completed, restore huart->RxState to Ready */
			if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
			{
				huart->gState = HAL_UART_STATE_BUSY_TX;
			}
			else
			{
                huart->gState = HAL_UART_STATE_READY;
			}

      /* Clear RxISR function pointer */
      huart->RxISR = NULL;

			/* disable interrupt & clear interrupt */
      __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ELSI);   
      __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ERBFI);  
	    __HAL_UART_IT_CLEAR_LS(huart);
	    __HAL_UART_IT_CLEAR_RA(huart);
			
      /* Check current reception Mode :
         If Reception till IDLE event has been selected : */
      if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
      {
        /* Set reception type to Standard */
        huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        /*Call registered Rx Event callback*/
        huart->RxEventCallback(huart, huart->RxXferSize);
#else
        /*Call legacy weak Rx Event callback*/
        HAL_UART_RxEventCallback(huart, huart->RxXferSize);
#endif /* (USE_HAL_UART_REGISTER_CALLBACKS) */
      }
      else
      {
        /* Standard reception API called */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
        /*Call registered Rx complete callback*/
        huart->RxCpltCallback(huart);
#else
        /*Call legacy weak Rx complete callback*/
        HAL_UART_RxCpltCallback(huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
      }
    }
  }
  else
  {
  }
}

/**
  * @brief RX interrupt handler for data and FIFO mode is enabled.
  * @param huart UART handle.
  */
static void UART_RxISR_FIFOEN(UART_HandleTypeDef *huart)
{
  uint32_t  uhMask = ((huart->Mask > 0) ? huart->Mask : 0xFF);
  uint16_t  uhdata;
//  uint16_t  nb_rx_data;
//  uint16_t  rxdatacount;
  uint32_t  lsflags  = 0; //READ_REG(huart->Instance->LSR); /*!< Read lines status and clear lines status */

  /* Check that a Rx process is ongoing */
  if ((huart->gState == HAL_UART_STATE_BUSY_RX) || (huart->gState == HAL_UART_STATE_BUSY_TX_RX))
  {
//    nb_rx_data = huart->NbRxDataToProcess;
    do //while (/*(nb_rx_data > 0U) &&*/ (lsflags && UART_LS_DR) &&(huart->RxXferCount > 0)) 
    {
      uhdata = (uint16_t) READ_REG(huart->Instance->RBR_THR_DLL);
      *huart->pRxBuffPtr = (uint8_t)(uhdata & (uint8_t)uhMask);
      huart->pRxBuffPtr++;
      huart->RxXferCount--;
      
//			SEGGER_RTT_printf(0, "rx fifo data: %d\n", uhdata);
			/* If some non blocking errors occurred */
			if ((lsflags & (UART_LS_RFE | UART_LS_FE | UART_LS_PE | UART_LS_OE)) != 0U)
			{
				/* UART parity error interrupt occurred -------------------------------------*/
				if ((lsflags & UART_LS_PE) != 0U)
				{
					huart->ErrorCode |= HAL_UART_ERROR_PE;
				}

				/* UART frame error interrupt occurred --------------------------------------*/
				if ((lsflags & UART_LS_FE) != 0U)
				{
					huart->ErrorCode |= HAL_UART_ERROR_FE;
				}

				/* UART overrrun error interrupt occurred --------------------------------------*/
				if ((lsflags & UART_LS_OE) != 0U)
				{
					huart->ErrorCode |= HAL_UART_ERROR_OE;
				}

				/* UART receive FIFO interrupt occurred --------------------------------------*/
				if ((lsflags & UART_LS_RFE) != 0U) 
				{
					huart->ErrorCode |= HAL_UART_ERROR_RFE;
				}

				/* Call UART Error Call back function if need be ----------------------------*/
				if (huart->ErrorCode != HAL_UART_ERROR_NONE)
				{
					/* Non Blocking error : transfer could go on.
					Error is notified to user through user error callback */
	#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
					/*Call registered error callback*/
					huart->ErrorCallback(huart);
	#else
					/*Call legacy weak error callback*/
					HAL_UART_ErrorCallback(huart);
	#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
					huart->ErrorCode = HAL_UART_ERROR_NONE;
				}
			}

			if (huart->ReceptionType == HAL_UART_RECEPTION_TOCHARMATCH)
	        {
		        if(*(huart->pRxBuffPtr-1) == huart->MatchChar)
		        {
			        huart->RxXferCount = 0;
		        }
	        }

			if (huart->RxXferCount == 0U)
			{
				if(huart->gState == HAL_UART_STATE_BUSY_TX_RX)
				{
					huart->gState = HAL_UART_STATE_BUSY_TX;
				}
				else
				{
					/* Rx process is completed, restore huart->RxState to Ready */
					huart->gState = HAL_UART_STATE_READY;
				}

				/* Clear RxISR function pointer */
				huart->RxISR = NULL;

			  /* disable interrupt & clear interrupt */
        __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ELSI);   
        __HAL_UART_DISABLE_IT(huart, UART_ENABLEIT_ERBFI);  
	      __HAL_UART_IT_CLEAR_LS(huart);
	      __HAL_UART_IT_CLEAR_RA(huart);
				
				/* Check current reception Mode :
						If Reception till IDLE event has been selected : */
				if (huart->ReceptionType == HAL_UART_RECEPTION_TOIDLE)
				{
					/* Set reception type to Standard */
					huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

	#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
					/*Call registered Rx Event callback*/
					huart->RxEventCallback(huart, huart->RxXferSize);
	#else
					/*Call legacy weak Rx Event callback*/
					HAL_UART_RxEventCallback(huart, huart->RxXferSize);
	#endif /* (USE_HAL_UART_REGISTER_CALLBACKS) */
				}
				else
				{
					/* Standard reception API called */
	#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
					/*Call registered Rx complete callback*/
					huart->RxCpltCallback(huart);
	#else
					/*Call legacy weak Rx complete callback*/
					HAL_UART_RxCpltCallback(huart);
	#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
				}
			}
			lsflags  = READ_REG(huart->Instance->LSR); /* check rxfifo is not empty */
    } while (/*(nb_rx_data > 0U) &&*/ (lsflags & UART_LS_DR) &&(huart->RxXferCount > 0)); /*while*/
  }
  else
  {
  }
}

/**
  * @brief Calculate the number of data to process in RX/TX ISR.
  * @param huart UART handle.
  */
static void UART_SetNbDataToProcess(UART_HandleTypeDef *huart)
{
  uint8_t rx_fifo_threshold;
  uint8_t tx_fifo_threshold;
  static const uint8_t rxnumerator[4] = {1U, 4U, 8U, 14U};
  static const uint8_t txnominator[4] = {16U, 14U, 12U, 8U};

  if (huart->FifoMode == UART_FIFOMODE_DISABLE)
  {
    huart->NbTxDataToProcess = 1U;
    huart->NbRxDataToProcess = 1U;
  }
  else
  {
    rx_fifo_threshold = (uint8_t)(huart->RxFifoTrigger >> UART_IIR_FCR_RCVR_Pos);
    tx_fifo_threshold = (uint8_t)(huart->TxFifoTrigger >> UART_IIR_FCR_TET_Pos);
    huart->NbTxDataToProcess = ((uint16_t)txnominator[tx_fifo_threshold]);
    huart->NbRxDataToProcess = ((uint16_t)rxnumerator[rx_fifo_threshold]);
  }
}

/**
  * @}
  */

#endif /* HAL_UART_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
