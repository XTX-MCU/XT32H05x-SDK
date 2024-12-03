/**
  ******************************************************************************
  * @file    xt32h0xx_hal_spi.c
  * @author  Software Team
  * @brief   SPI HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Serial Peripheral Interface (SPI) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *
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

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup SPI SPI
  * @brief SPI HAL module driver
  * @{
  */
#ifdef HAL_SPI_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/** @defgroup SPI_Private_Constants SPI Private Constants
  * @{
  */
#define SPI_DEFAULT_TIMEOUT 5000U

#define SPI1_DMA_TXHSMASK   (0x03030003UL)
#define SPI1_DMA_RXHSMASK   (0x0C0C000CUL)
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup SPI_Private_Functions SPI Private Functions
  * @{
  */
static void SPI_DMATransmitCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMAReceiveCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMATransmitReceiveCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMATransmitReceiveTxCplt(DMA_HandleTypeDef *hdma);
static void SPI_DMAError(DMA_HandleTypeDef *hdma);
static void SPI_DMAAbortOnError(DMA_HandleTypeDef *hdma);
static void SPI_DMATxAbortCallback(DMA_HandleTypeDef *hdma);
static void SPI_DMARxAbortCallback(DMA_HandleTypeDef *hdma);
static HAL_StatusTypeDef SPI_WaitStatusUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Status, uint32_t Expert,
                                                       uint32_t Timeout, uint32_t Tickstart);
static void SPI_TxISR_8BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_TxISR_16BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_RxISR_8BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_RxISR_16BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesRxISR_8BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesTxISR_8BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesTxISR_16BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_2linesRxISR_16BIT(struct __SPI_HandleTypeDef *hspi);
static void SPI_AbortRx_ISR(SPI_HandleTypeDef *hspi);
static void SPI_AbortTx_ISR(SPI_HandleTypeDef *hspi);
static void SPI_CloseRxTx_ISR(SPI_HandleTypeDef *hspi);
static void SPI_CloseRx_ISR(SPI_HandleTypeDef *hspi);
static void SPI_CloseTx_ISR(SPI_HandleTypeDef *hspi);
static HAL_StatusTypeDef SPI_EndRxTransaction(SPI_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef SPI_EndRxTxTransaction(SPI_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup SPI_Exported_Functions SPI Exported Functions
  * @{
  */

/** @defgroup SPI_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  * @{
  */

/**
  * @brief  Initialize the SPI according to the specified parameters
  *         in the SPI_InitTypeDef and initialize the associated handle.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi)
{
  /* Check the SPI handle allocation */
  if (hspi == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_SPI_ALL_INSTANCE(hspi->Instance));

  assert_param(IS_SPI_DIRECTION(hspi->Init.Direction));
  assert_param(IS_SPI_DATASIZE(hspi->Init.DataSize));
  assert_param(IS_SPI_TIMODE(hspi->Init.Standard));
  assert_param(IS_SPI_CTRLSIZE(hspi->Init.ControlSize));
  
  if (hspi->Init.Standard != SPI_FRF_TI)
  {
    assert_param(IS_SPI_CPOL(hspi->Init.ClockPolarity));
    assert_param(IS_SPI_CPHA(hspi->Init.ClockPhase));
  }
  else
  {
    /* Force polarity and phase to TI protocaol requirements */
    hspi->Init.ClockPolarity = SPI_POLARITY_LOW;
    hspi->Init.ClockPhase    = SPI_PHASE_1EDGE;
  }

  if (__HAL_SPI_IS_MASTER(hspi))
  {
    assert_param(IS_SPI_BAUDRATE(hspi->Init.BaudRate));
  }

  if (hspi->State == HAL_SPI_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hspi->Lock = HAL_UNLOCKED;

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    /* Init the SPI Callback settings */
    hspi->TxCpltCallback       = HAL_SPI_TxCpltCallback;       /* Legacy weak TxCpltCallback       */
    hspi->RxCpltCallback       = HAL_SPI_RxCpltCallback;       /* Legacy weak RxCpltCallback       */
    hspi->TxRxCpltCallback     = HAL_SPI_TxRxCpltCallback;     /* Legacy weak TxRxCpltCallback     */
//    hspi->TxHalfCpltCallback   = HAL_SPI_TxHalfCpltCallback;   /* Legacy weak TxHalfCpltCallback   */
//    hspi->RxHalfCpltCallback   = HAL_SPI_RxHalfCpltCallback;   /* Legacy weak RxHalfCpltCallback   */
//    hspi->TxRxHalfCpltCallback = HAL_SPI_TxRxHalfCpltCallback; /* Legacy weak TxRxHalfCpltCallback */
    hspi->ErrorCallback        = HAL_SPI_ErrorCallback;        /* Legacy weak ErrorCallback        */
    hspi->AbortCpltCallback    = HAL_SPI_AbortCpltCallback;    /* Legacy weak AbortCpltCallback    */

    if (hspi->MspInitCallback == NULL)
    {
      hspi->MspInitCallback = HAL_SPI_MspInit; /* Legacy weak MspInit  */
    }

    /* Init the low level hardware : GPIO, CLOCK, NVIC... */
    hspi->MspInitCallback(hspi);
#else
    /* Init the low level hardware : GPIO, CLOCK, NVIC... */
    HAL_SPI_MspInit(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
  }

  hspi->State = HAL_SPI_STATE_BUSY;

  /* Disable the selected SPI peripheral */
  __HAL_SPI_DISABLE(hspi);

  /*----------------------- SPIx CTRLR Configuration ---------------------*/
  /* Configure : Communication Mode, Clock polarity and phase, Control bit,
  Data bit  */
  WRITE_REG(hspi->Instance->CTRLR0, ((hspi->Init.Direction & SPI_CTRLR0_TMOD) |
                                     (hspi->Init.ClockPolarity & SPI_CTRLR0_SCPOL) |
                                     (hspi->Init.ClockPhase & SPI_CTRLR0_SCPH) |
                                     (hspi->Init.DataSize & SPI_CTRLR0_DFS) |
                                     (hspi->Init.ControlSize & SPI_CTRLR0_CFS) |
                                     (hspi->Init.Standard & SPI_CTRLR0_FRF)));
  
  if (__HAL_SPI_IS_MASTER(hspi))
  {
    WRITE_REG(hspi->Instance->CTRLR1, hspi->Init.NumberDataFrame - 1);
    WRITE_REG(hspi->Instance->BAUDR, hspi->Init.BaudRate);
  }
  
  WRITE_REG(hspi->Instance->TXFTLR, hspi->Init.TxFIFOTLvl);
  WRITE_REG(hspi->Instance->RXFTLR, hspi->Init.RxFIFOTLvl);
  
  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));

	if ((__HAL_SPI_IS_SLAVE(hspi)) && (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY))
	{
		__HAL_SPI_MASK_IT(hspi, SPI_IT_TXE);
	}


  if (__HAL_SPI_IS_MASTER(hspi))
  {
    SET_BIT(hspi->Instance->SER, SPI_SLAVE_SELECT_0);    
  }

  //DMA init
//  if(hspi->hdmatx != NULL)
//  {
		//hspi->Instance->DMATDLR = 2;
//    HAL_DMA_Init(hspi->hdmatx);
//  }
//  if(hspi->hdmarx != NULL)
//  {
		//hspi->Instance->DMARDLR = 2;
//    HAL_DMA_Init(hspi->hdmarx);
//  }
	
	/* config syscfg */
	if(hspi->Instance == SPI1M)
	{
		SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_MODE);
	}
	else if(hspi->Instance == SPI1S)
	{
		CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_MODE);
	}
	else if(hspi->Instance == SPI2M)
	{
		SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_MODE);
	}
	else if(hspi->Instance == SPI2S)
	{
		CLEAR_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_MODE);
	}

  hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  hspi->State     = HAL_SPI_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  De-Initialize the SPI peripheral.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_DeInit(SPI_HandleTypeDef *hspi)
{
  /* Check the SPI handle allocation */
  if (hspi == NULL)
  {
    return HAL_ERROR;
  }

  /* Check SPI Instance parameter */
  assert_param(IS_SPI_ALL_INSTANCE(hspi->Instance));

  hspi->State = HAL_SPI_STATE_BUSY;

  /* Disable the SPI Peripheral Clock */
  __HAL_SPI_SS_DISABLE(hspi);
  __HAL_SPI_DISABLE(hspi);

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  if (hspi->MspDeInitCallback == NULL)
  {
    hspi->MspDeInitCallback = HAL_SPI_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware: GPIO, CLOCK, NVIC... */
  hspi->MspDeInitCallback(hspi);
#else
  /* DeInit the low level hardware: GPIO, CLOCK, NVIC... */
  HAL_SPI_MspDeInit(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */

  //DMA deinit
  if(hspi->hdmatx != NULL)
  {
    HAL_DMA_Abort(hspi->hdmatx/*,SPI_DEFAULT_TIMEOUT*/);
    HAL_DMA_DeInit(hspi->hdmatx);
  }
  if(hspi->hdmarx != NULL)
  {
    HAL_DMA_Abort(hspi->hdmarx/*,SPI_DEFAULT_TIMEOUT*/);
    HAL_DMA_DeInit(hspi->hdmarx);
  }

  hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  hspi->State = HAL_SPI_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hspi);

  return HAL_OK;
}

/**
  * @brief  Set each @ref LL_SPI_InitTypeDef field to default value.
  * @param  hspi SPI handle
  * whose fields will be set to default values.
  */
void HAL_SPI_StructInit(SPI_HandleTypeDef *hspi)
{
  /* Set SPI_InitStruct fields to default values */
  hspi->Init.Direction             = SPI_DIRECTION_2LINES;
  hspi->Init.DataSize              = SPI_DATASIZE_8BIT;
  hspi->Init.ClockPolarity         = SPI_POLARITY_LOW;
  hspi->Init.ClockPhase            = SPI_PHASE_2EDGE;
  hspi->Init.BaudRate              = 2;                /*!< 2 to 65534 */
  hspi->Init.Standard              = SPI_FRF_MOTO;
  hspi->Init.ControlSize           = SPI_CTRLSIZE_1BIT;
  hspi->Init.NumberDataFrame       = 1;
  hspi->Init.TxFIFOTLvl            = SPI_TXFIFO_THRESHOLD_HF;
  hspi->Init.RxFIFOTLvl            = SPI_RXFIFO_THRESHOLD_HF;
}

/**
  * @brief  Initialize the SPI MSP.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
__weak void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_MspInit should be implemented in the user file
   */
}

/**
  * @brief  De-Initialize the SPI MSP.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
__weak void HAL_SPI_MspDeInit(SPI_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_MspDeInit should be implemented in the user file
   */
}

/**
  * @brief link dma with spi.
  * @param hspi SPI handle.
  * @param hdmarx DMA handle.
  * @param hdmatx DMA handle.
  * @param rxif DMA rx if.
  * @param txif DMA tx if.
  * @param rxifcfg DMA rx if configure.
  * @param txifcfg DMA tx if configure.
  * @retval Status
  */
HAL_StatusTypeDef HAL_SPI_DMAHSIFConfig(SPI_HandleTypeDef *hspi, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx, uint32_t rxif, uint32_t txif, uint32_t rxifcfg, uint32_t txifcfg)
{
	uint32_t mask = 0;
	if(hspi == NULL) return HAL_ERROR;
	
	if(hdmarx != NULL)
	{
#if defined(XT32H0xxBMPW)		
		if((hspi->Instance == SPI1M) || (hspi->Instance == SPI1S))
		{
			MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_RXDA, ( rxifcfg <<SYSCFG_SYS_CFG_SPI1_RXDA_Pos));
		}
#elif defined(XT32H0xxB)    
		if((hspi->Instance == SPI1M) || (hspi->Instance == SPI1S))
		{
      if(rxif == 9)
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_RXDA, ( 1 <<SYSCFG_SYS_CFG_SPI1_RXDA_Pos));
      }
      else if(rxif == 1)
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_RXDA, ( 2 <<SYSCFG_SYS_CFG_SPI1_RXDA_Pos));
      }
      else 
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_RXDA, ( 0 <<SYSCFG_SYS_CFG_SPI1_RXDA_Pos));
      }
		}
		else if((hspi->Instance == SPI2M) || (hspi->Instance == SPI2S))
		{
      if(rxif == 11)
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_RXDA, ( 1 <<SYSCFG_SYS_CFG_SPI2_RXDA_Pos));
      }
      else if(rxif == 3)
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_RXDA, ( 2 <<SYSCFG_SYS_CFG_SPI2_RXDA_Pos));
      }
      else 
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_RXDA, ( 0 <<SYSCFG_SYS_CFG_SPI2_RXDA_Pos));
      }
		}
#endif		
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
#if defined(XT32H0xxBMPW)		
		if((hspi->Instance == SPI1M) || (hspi->Instance == SPI1S))
		{
			MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_TXDA, ( txifcfg <<SYSCFG_SYS_CFG_SPI1_TXDA_Pos));
		}
#elif defined(XT32H0xxB)     
		if((hspi->Instance == SPI1M) || (hspi->Instance == SPI1S))
		{
      if (txif == 8)
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_TXDA, ( 1 <<SYSCFG_SYS_CFG_SPI1_TXDA_Pos));
      }
      else if (txif == 0)
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_TXDA, ( 2 <<SYSCFG_SYS_CFG_SPI1_TXDA_Pos));
      }
      else 
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI1_TXDA, ( 0 <<SYSCFG_SYS_CFG_SPI1_TXDA_Pos));
      }
		}
		else if((hspi->Instance == SPI2M) || (hspi->Instance == SPI2S))
		{
      if (txif == 10)
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_TXDA, ( 1 <<SYSCFG_SYS_CFG_SPI2_TXDA_Pos));
      }
      else if (txif == 2)
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_TXDA, ( 2 <<SYSCFG_SYS_CFG_SPI2_TXDA_Pos));
      }
      else 
      {
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_SPI2_TXDA, ( 0 <<SYSCFG_SYS_CFG_SPI2_TXDA_Pos));
      }
		}
#endif	
 		mask = 3UL << (txif<<1);
		SYSCFG->DMA_CFG &= ~(mask);  
		SYSCFG->DMA_CFG |= ((txifcfg & 0x3) << (txif<<1));
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
  * @brief  Link DMA to SPI.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  hdmarx pointer to DAM rx 
  * @param  hdmatx pointer to DAM tx 
  */
HAL_StatusTypeDef HAL_SPI_LinkDMA(SPI_HandleTypeDef *hspi, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx)
{
  if(hspi == NULL) return HAL_ERROR;

  if(hdmarx != NULL)
  {
    hspi->hdmarx = hdmarx;
    hdmarx->Parent = hspi;
  }

  if(hdmatx != NULL)
  {
    hspi->hdmatx = hdmatx;
    hdmatx->Parent = hspi;
  }

  return HAL_OK;
}

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
/**
  * @brief  Register a User SPI Callback
  *         To be used instead of the weak predefined callback
  * @param  hspi Pointer to a SPI_HandleTypeDef structure that contains
  *                the configuration information for the specified SPI.
  * @param  CallbackID ID of the callback to be registered
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_RegisterCallback(SPI_HandleTypeDef *hspi, HAL_SPI_CallbackIDTypeDef CallbackID,
                                           pSPI_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hspi->ErrorCode |= HAL_SPI_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hspi);

  if (HAL_SPI_STATE_READY == hspi->State)
  {
    switch (CallbackID)
    {
      case HAL_SPI_TX_COMPLETE_CB_ID :
        hspi->TxCpltCallback = pCallback;
        break;

      case HAL_SPI_RX_COMPLETE_CB_ID :
        hspi->RxCpltCallback = pCallback;
        break;

      case HAL_SPI_TX_RX_COMPLETE_CB_ID :
        hspi->TxRxCpltCallback = pCallback;
        break;

//      case HAL_SPI_TX_HALF_COMPLETE_CB_ID :
//        hspi->TxHalfCpltCallback = pCallback;
//        break;
//
//      case HAL_SPI_RX_HALF_COMPLETE_CB_ID :
//        hspi->RxHalfCpltCallback = pCallback;
//        break;
//
//      case HAL_SPI_TX_RX_HALF_COMPLETE_CB_ID :
//        hspi->TxRxHalfCpltCallback = pCallback;
//        break;

      case HAL_SPI_ERROR_CB_ID :
        hspi->ErrorCallback = pCallback;
        break;

      case HAL_SPI_ABORT_CB_ID :
        hspi->AbortCpltCallback = pCallback;
        break;

      case HAL_SPI_MSPINIT_CB_ID :
        hspi->MspInitCallback = pCallback;
        break;

      case HAL_SPI_MSPDEINIT_CB_ID :
        hspi->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_SPI_STATE_RESET == hspi->State)
  {
    switch (CallbackID)
    {
      case HAL_SPI_MSPINIT_CB_ID :
        hspi->MspInitCallback = pCallback;
        break;

      case HAL_SPI_MSPDEINIT_CB_ID :
        hspi->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hspi);
  return status;
}

/**
  * @brief  Unregister an SPI Callback
  *         SPI callback is redirected to the weak predefined callback
  * @param  hspi Pointer to a SPI_HandleTypeDef structure that contains
  *                the configuration information for the specified SPI.
  * @param  CallbackID ID of the callback to be unregistered
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_UnRegisterCallback(SPI_HandleTypeDef *hspi, HAL_SPI_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hspi);

  if (HAL_SPI_STATE_READY == hspi->State)
  {
    switch (CallbackID)
    {
      case HAL_SPI_TX_COMPLETE_CB_ID :
        hspi->TxCpltCallback = HAL_SPI_TxCpltCallback;             /* Legacy weak TxCpltCallback       */
        break;

      case HAL_SPI_RX_COMPLETE_CB_ID :
        hspi->RxCpltCallback = HAL_SPI_RxCpltCallback;             /* Legacy weak RxCpltCallback       */
        break;

      case HAL_SPI_TX_RX_COMPLETE_CB_ID :
        hspi->TxRxCpltCallback = HAL_SPI_TxRxCpltCallback;         /* Legacy weak TxRxCpltCallback     */
        break;

//      case HAL_SPI_TX_HALF_COMPLETE_CB_ID :
//        hspi->TxHalfCpltCallback = HAL_SPI_TxHalfCpltCallback;     /* Legacy weak TxHalfCpltCallback   */
//        break;
//
//      case HAL_SPI_RX_HALF_COMPLETE_CB_ID :
//        hspi->RxHalfCpltCallback = HAL_SPI_RxHalfCpltCallback;     /* Legacy weak RxHalfCpltCallback   */
//        break;
//
//      case HAL_SPI_TX_RX_HALF_COMPLETE_CB_ID :
//        hspi->TxRxHalfCpltCallback = HAL_SPI_TxRxHalfCpltCallback; /* Legacy weak TxRxHalfCpltCallback */
//        break;

      case HAL_SPI_ERROR_CB_ID :
        hspi->ErrorCallback = HAL_SPI_ErrorCallback;               /* Legacy weak ErrorCallback        */
        break;

      case HAL_SPI_ABORT_CB_ID :
        hspi->AbortCpltCallback = HAL_SPI_AbortCpltCallback;       /* Legacy weak AbortCpltCallback    */
        break;

      case HAL_SPI_MSPINIT_CB_ID :
        hspi->MspInitCallback = HAL_SPI_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_SPI_MSPDEINIT_CB_ID :
        hspi->MspDeInitCallback = HAL_SPI_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_SPI_STATE_RESET == hspi->State)
  {
    switch (CallbackID)
    {
      case HAL_SPI_MSPINIT_CB_ID :
        hspi->MspInitCallback = HAL_SPI_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_SPI_MSPDEINIT_CB_ID :
        hspi->MspDeInitCallback = HAL_SPI_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_INVALID_CALLBACK);

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hspi);
  return status;
}
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup SPI_Exported_Functions_Group2 IO operation functions
  *  @brief   Data transfers functions
  *
  * @{
  */

/**
  * @brief  Transmit an amount of data in blocking mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart;
  HAL_StatusTypeDef errorcode = HAL_OK;
  int i=0;
	uint16_t temp = 0;
//  uint16_t initial_TxXferCount;

  /* Check Direction parameter */
  assert_param(IS_SPI_DIRECTION_TX(hspi->Init.Direction));

  /* Process Locked */
  __HAL_LOCK(hspi);

  /* Init tickstart for timeout management*/
  tickstart = HAL_GetTick();
//  initial_TxXferCount = Size;

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    errorcode = HAL_BUSY;
    goto error;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }

	
  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));
	

  /* Set the transaction information */
  hspi->State       = HAL_SPI_STATE_BUSY_TX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (uint8_t *)pData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;

  /*Init field not used in handle to zero */
  hspi->pRxBuffPtr  = (uint8_t *)NULL;
  hspi->RxXferSize  = 0U;
  hspi->RxXferCount = 0U;
  hspi->TxISR       = NULL;
  hspi->RxISR       = NULL;

  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }
	
	if (__HAL_SPI_IS_SLAVE(hspi))
	{
	  for(i=0; i<10; i++) __HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE);  //just for clean TXE in slave mode
	}

  /* Transmit data in 16 Bit mode */
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    /* Transmit data in 16 Bit mode */
    while (hspi->TxXferCount > 0U)
    {
      /* Wait until TFNF status is set to send data */
			if(__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE) && (__HAL_SPI_IS_SLAVE(hspi)))
			{
          errorcode = HAL_ERROR;
          goto error;				
			}
			
      if (__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TFNF))
      {
		temp = (*(hspi->pTxBuffPtr+1));
		temp <<=8;
		temp += (*(hspi->pTxBuffPtr));
        *((__IO uint16_t *)&hspi->Instance->DR) = temp;
        hspi->pTxBuffPtr  += sizeof(uint16_t);
        hspi->TxXferCount -= sizeof(uint16_t);
      }
      else
      {
        /* Timeout management */
        if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
        {
          errorcode = HAL_TIMEOUT;
          goto error;
        }
      }
    }
  }
  /* Transmit data in 8 Bit mode */
  else
  {
    while (hspi->TxXferCount > 0U)
    {
      /* Wait until TFNF status is set to send data */
			if(__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE) && (__HAL_SPI_IS_SLAVE(hspi)))
			{
          errorcode = HAL_ERROR;
          goto error;				
			}

      if (__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TFNF))
      {
        *((__IO uint8_t *)&hspi->Instance->DR) = (*hspi->pTxBuffPtr);
        hspi->pTxBuffPtr += sizeof(uint8_t);
        hspi->TxXferCount--;
      }
      else
      {
        /* Timeout management */
        if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
        {
          errorcode = HAL_TIMEOUT;
          goto error;
        }
      }
     }
  }

  /* Check the end of the transaction */
  if (SPI_EndRxTxTransaction(hspi, Timeout, tickstart) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_FLAG;
  }

  /* Clear overrun flag in 2 Lines communication mode because received is not read */
  if (hspi->Init.Direction == SPI_DIRECTION_2LINES)
  {
    __HAL_SPI_CLEAR_RXOICR(hspi);
    //read DR until empty
    //uint16_t rd;
    while(__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_RFNE))
    {
      //rd = READ_REG(hspi->Instance->DR);
      READ_REG(hspi->Instance->DR);
    }
  }

  if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
  {
    errorcode = HAL_ERROR;
  }

error:
  __HAL_SPI_DISABLE(hspi);
  hspi->State = HAL_SPI_STATE_READY;
  /* Process Unlocked */
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Receive an amount of data in blocking mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be received
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart;
  HAL_StatusTypeDef errorcode = HAL_OK;
	uint16_t temp = 0;

  if ((__HAL_SPI_IS_MASTER(hspi)) && (hspi->Init.Direction == SPI_DIRECTION_2LINES))
  {
    hspi->State = HAL_SPI_STATE_BUSY_RX;
    /* Call transmit-receive function to send Dummy data on Tx line and generate clock on CLK line */
    return HAL_SPI_TransmitReceive(hspi, pData, pData, Size, Timeout);
  }

  if ((__HAL_SPI_IS_MASTER(hspi))&& (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY))
  {
    WRITE_REG(hspi->Instance->CTRLR1, Size - 1);
  }

  /* Process Locked */
  __HAL_LOCK(hspi);

  /* Init tickstart for timeout management*/
  tickstart = HAL_GetTick();

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    errorcode = HAL_BUSY;
    goto error;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }

	
  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));

  /* Set the transaction information */
  hspi->State       = HAL_SPI_STATE_BUSY_RX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

  /*Init field not used in handle to zero */
  hspi->pTxBuffPtr  = (uint8_t *)NULL;
  hspi->TxXferSize  = 0U;
  hspi->TxXferCount = 0U;
  hspi->RxISR       = NULL;
  hspi->TxISR       = NULL;

  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }

  /* for master write dummy to tx fifo to start transfer */
  if (((__HAL_SPI_IS_MASTER(hspi))&& (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY))
		||((__HAL_SPI_IS_SLAVE(hspi)) && (hspi->Init.Direction != SPI_DIRECTION_2LINES_RXONLY)))
  {
    WRITE_REG(hspi->Instance->DR, 0x0);
  }

  /* Receive data in 8 Bit mode */
  if (hspi->Init.DataSize <= SPI_DATASIZE_8BIT)
  {
    /* Transfer loop */
    while (hspi->RxXferCount > 0U)
    {
      /* Check the RFNE flag */
      if (__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE))
      {
        /* read the received data */
        (* (uint8_t *)hspi->pRxBuffPtr) = *(__IO uint8_t *)&hspi->Instance->DR;
        hspi->pRxBuffPtr += sizeof(uint8_t);
        hspi->RxXferCount--;
      }
      else
      {
        /* Timeout management */
        if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
        {
          errorcode = HAL_TIMEOUT;
          goto error;
        }
      }
    }
  }
  else
  {
    /* Transfer loop */
    while (hspi->RxXferCount > 0U)
    {
      /* Check the RFNE flag */
      if (__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE))
      {
		  temp = *(__IO uint16_t*)&hspi->Instance->DR;
        *((uint8_t *)hspi->pRxBuffPtr) = (uint8_t)(temp & 0xFF);
		 *((uint8_t *)(hspi->pRxBuffPtr+1)) = (uint8_t)((temp >> 8) & 0xFF); 
        hspi->pRxBuffPtr += sizeof(uint16_t);
        hspi->RxXferCount -=sizeof(uint16_t);
      }
      else
      {
        /* Timeout management */
        if ((((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY)) || (Timeout == 0U))
        {
          errorcode = HAL_TIMEOUT;
          goto error;
        }
      }
    }
  }

  /* Check the end of the transaction */
  if (SPI_EndRxTransaction(hspi, Timeout, tickstart) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_FLAG;
  }

  if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
  {
    errorcode = HAL_ERROR;
  }

error :
  __HAL_SPI_DISABLE(hspi);
  hspi->State = HAL_SPI_STATE_READY;
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Transmit and Receive an amount of data in blocking mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pTxData pointer to transmission data buffer
  * @param  pRxData pointer to reception data buffer
  * @param  Size amount of data to be sent and received
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size,
                                          uint32_t Timeout)
{
	int i = 0;
//  uint16_t             initial_TxXferCount;
//  uint32_t             tmp_mode;
//  HAL_SPI_StateTypeDef tmp_state;
  uint32_t             tickstart;
	uint16_t temp = 0;

  /* Variable used to alternate Rx and Tx during transfer */
  uint32_t             txallowed = 1U;
  HAL_StatusTypeDef    errorcode = HAL_OK;

  /* Check Direction parameter */
  assert_param(IS_SPI_DIRECTION_2LINES(hspi->Init.Direction));

  /* Process Locked */
  __HAL_LOCK(hspi);

  /* Init tickstart for timeout management*/
  tickstart = HAL_GetTick();

  /* Init temporary variables */
//  tmp_state           = hspi->State;
//  tmp_mode            = hspi->Init.Mode;
//  initial_TxXferCount = Size;

//  if (!((tmp_state == HAL_SPI_STATE_READY) || \
//        ((__HAL_SPI_IS_MASTER(hspi)) && (hspi->Init.Direction == SPI_DIRECTION_2LINES) && (tmp_state == HAL_SPI_STATE_BUSY_RX))))
//  {
//    errorcode = HAL_BUSY;
//    goto error;
//  }

  if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }

  /* Don't overwrite in case of HAL_SPI_STATE_BUSY_RX */
  if (hspi->State != HAL_SPI_STATE_BUSY_RX)
  {
    hspi->State = HAL_SPI_STATE_BUSY_TX_RX;
  }
	
  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));


  /* Set the transaction information */
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pRxData;
  hspi->RxXferCount = Size;
  hspi->RxXferSize  = Size;
  hspi->pTxBuffPtr  = (uint8_t *)pTxData;
  hspi->TxXferCount = Size;
  hspi->TxXferSize  = Size;

  /*Init field not used in handle to zero */
  hspi->RxISR       = NULL;
  hspi->TxISR       = NULL;

  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }
	
	if (__HAL_SPI_IS_SLAVE(hspi))
	{
	  for(i=0; i<10; i++) __HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE);  //just for clean TXE in slave mode
	}
	
  /* Transmit and Receive data in 16 Bit mode */
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
#if 0 //MCU_SIMULATION	
	(*((uint32_t*)0x50000C00)) = 0x000000C0UL;
#endif
	
    while ((hspi->TxXferCount > 0U) || (hspi->RxXferCount > 0U))
    {
      /* Check TXE flag */
			if(__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE) && (__HAL_SPI_IS_SLAVE(hspi)))
			{
          errorcode = HAL_ERROR;
          goto error;				
			}

      if ((__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TFNF)) && (hspi->TxXferCount > 0U) && 
				((__HAL_SPI_IS_MASTER(hspi) && (txallowed == 1U))  || __HAL_SPI_IS_SLAVE(hspi)))
      {
		  temp = *((uint8_t *)(hspi->pTxBuffPtr+1));
		  temp <<= 8;
		  temp += *((uint8_t *)hspi->pTxBuffPtr);
        *(__IO uint16_t*)&hspi->Instance->DR = temp;
        hspi->pTxBuffPtr += sizeof(uint16_t);
        hspi->TxXferCount -= sizeof(uint16_t);
        /* Next Data is a reception (Rx). Tx not allowed */
        txallowed = 0U;

      }

      /* Check RXNE flag */
      if ((__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_RFNE)) && (hspi->RxXferCount > 0U))
      {
		  temp = *(__IO uint16_t*)&hspi->Instance->DR;
        *((uint8_t *)hspi->pRxBuffPtr) = (uint8_t)(temp & 0xFF);
        *((uint8_t *)(hspi->pRxBuffPtr+1)) = (uint8_t)((temp>>8) & 0xFF);
        hspi->pRxBuffPtr += sizeof(uint16_t);
        hspi->RxXferCount -= sizeof(uint16_t);
        /* Next Data is a Transmission (Tx). Tx is allowed */
        txallowed = 1U;
      }
      if (((HAL_GetTick() - tickstart) >=  Timeout) && (Timeout != HAL_MAX_DELAY))
      {
        errorcode = HAL_TIMEOUT;
        goto error;
      }
    }
  }
  /* Transmit and Receive data in 8 Bit mode */
  else
  {
#if 0 //MCU_SIMULATION	
	(*((uint32_t*)0x50000C00)) = 0x000000C0UL;
#endif
    while ((hspi->TxXferCount > 0U) || (hspi->RxXferCount > 0U))
    {
      /* Check TXE flag */
			if(__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE) && (__HAL_SPI_IS_SLAVE(hspi)))
			{
          errorcode = HAL_ERROR;
          goto error;				
			}

      if ((__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TFNF)) && (hspi->TxXferCount > 0U) && 
				((__HAL_SPI_IS_MASTER(hspi) && (txallowed == 1U))  || __HAL_SPI_IS_SLAVE(hspi)))
      {
        *(__IO uint8_t *)&hspi->Instance->DR = (*hspi->pTxBuffPtr);
        hspi->pTxBuffPtr++;
        hspi->TxXferCount--;
        /* Next Data is a reception (Rx). Tx not allowed */
        txallowed = 0U;
      }

      /* Wait until RXNE flag is reset */
      if ((__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_RFNE)) && (hspi->RxXferCount > 0U))
      {
        (*(uint8_t *)hspi->pRxBuffPtr) = *(__IO uint8_t *)&hspi->Instance->DR;
        hspi->pRxBuffPtr++;
        hspi->RxXferCount--;
        /* Next Data is a Transmission (Tx). Tx is allowed */
        txallowed = 1U;
      }
      if ((((HAL_GetTick() - tickstart) >=  Timeout) && ((Timeout != HAL_MAX_DELAY))) || (Timeout == 0U))
      {
        errorcode = HAL_TIMEOUT;
        goto error;
      }
    }
  }

  /* Check the end of the transaction */
  if (SPI_EndRxTxTransaction(hspi, Timeout, tickstart) != HAL_OK)
  {
    errorcode = HAL_ERROR;
    hspi->ErrorCode = HAL_SPI_ERROR_FLAG;
  }

error :
  __HAL_SPI_DISABLE(hspi);  //disable just for fpga flash bist test
  hspi->State = HAL_SPI_STATE_READY;
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Transmit an amount of data in non-blocking mode with Interrupt.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Transmit_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef errorcode = HAL_OK;
	uint16_t temp;
	int i;

  /* Check Direction parameter */
  assert_param(IS_SPI_DIRECTION_TX(hspi->Init.Direction));

  /* Process Locked */
  __HAL_LOCK(hspi);

  if ((pData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    errorcode = HAL_BUSY;
    goto error;
  }

  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));

  /* Set the transaction information */
  hspi->State       = HAL_SPI_STATE_BUSY_TX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (uint8_t *)pData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;

  /* Init field not used in handle to zero */
  hspi->pRxBuffPtr  = (uint8_t *)NULL;
  hspi->RxXferSize  = 0U;
  hspi->RxXferCount = 0U;
  hspi->RxISR       = NULL;

  /* Set the function for IT treatment */
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    hspi->TxISR = SPI_TxISR_16BIT;
  }
  else
  {
    hspi->TxISR = SPI_TxISR_8BIT;
  }

  if(READ_REG(hspi->Instance->TXFTLR) == 0)
  {
    WRITE_REG(hspi->Instance->TXFTLR, SPI_TXFIFO_THRESHOLD_HF);
  }

  /* Enable TXE and ERR interrupt */
  __HAL_SPI_UNMASK_IT(hspi, (SPI_IT_TXE | SPI_IT_TXO));
 
	
	if((hspi->Instance == SPI1M) || (hspi->Instance == SPI1S))
	{
		/* Configure ICTL and enable ICTL */  
		CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_SPI1_MASK);  //All API interrupt
		SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_SPI1_MASK);

		/* config sim */
		CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_SPI1_MASK); //All API interrupt
	}
	else
	{
		/* Configure ICTL and enable ICTL */  
		CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_SPI2_MASK);  //All API interrupt
		SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_SPI2_MASK);

		/* config sim */
		CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_SPI2_MASK); //All API interrupt
	}
  
  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }
	
	if (__HAL_SPI_IS_SLAVE(hspi))
	{
	  for(i=0; i<10; i++) __HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE);  //just for clean TXE in slave mode
	}


  if (__HAL_SPI_IS_SLAVE(hspi))
  {
		__HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));
		
		if((__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TFNF)) && (hspi->TxXferCount>0))
		{
			if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
			{
				temp = *((uint16_t *)(hspi->pTxBuffPtr+1));
				temp <<= 8;
				temp += *((uint16_t *)hspi->pTxBuffPtr);
				*((__IO uint16_t*)&hspi->Instance->DR) = temp;
				hspi->pTxBuffPtr += sizeof(uint16_t);
				hspi->TxXferCount -= sizeof(uint16_t);
			}
			else
			{
				*((__IO uint8_t *)&hspi->Instance->DR) = (*hspi->pTxBuffPtr);
				hspi->pTxBuffPtr += sizeof(uint8_t);
				hspi->TxXferCount--;
			}
	  }
		
	  __HAL_SPI_UNMASK_IT(hspi, (SPI_IT_TXE | SPI_IT_TXO));

  }

error :
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Receive an amount of data in non-blocking mode with Interrupt.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Receive_IT(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef errorcode = HAL_OK;

  if ((hspi->Init.Direction == SPI_DIRECTION_2LINES) && (__HAL_SPI_IS_MASTER(hspi)))
  {
    hspi->State = HAL_SPI_STATE_BUSY_RX;
    /* Call transmit-receive function to send Dummy data on Tx line and generate clock on CLK line */
    return HAL_SPI_TransmitReceive_IT(hspi, pData, pData, Size);
  }

  if ((__HAL_SPI_IS_MASTER(hspi))&& (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY))
  {
    WRITE_REG(hspi->Instance->CTRLR1, Size - 1);
  }

	if ((__HAL_SPI_IS_SLAVE(hspi)))
	{
		__HAL_SPI_MASK_IT(hspi, SPI_IT_TXE);
	}
	
  /* Process Locked */
  __HAL_LOCK(hspi);

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    errorcode = HAL_BUSY;
    goto error;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }

  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));

  /* Set the transaction information */
  hspi->State       = HAL_SPI_STATE_BUSY_RX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

  /* Init field not used in handle to zero */
  hspi->pTxBuffPtr  = (uint8_t *)NULL;
  hspi->TxXferSize  = 0U;
  hspi->TxXferCount = 0U;
  hspi->TxISR       = NULL;

  if(READ_REG(hspi->Instance->RXFTLR) == 0)
  {
    WRITE_REG(hspi->Instance->RXFTLR, SPI_RXFIFO_THRESHOLD_HF);
  }
  /* Check the data size to adapt Rx threshold and the set the function for IT treatment */
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    /* Set RX Fifo threshold according the reception data length: 16 bit */
    hspi->RxISR = SPI_RxISR_16BIT;
  }
  else
  {
    /* Set RX Fifo threshold according the reception data length: 8 bit */
    hspi->RxISR = SPI_RxISR_8BIT;
  }

  /* Configure communication direction : 1Line */
//  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
//  {
//    /* Disable SPI Peripheral before set 1Line direction (BIDIOE bit) */
//    __HAL_SPI_DISABLE(hspi);
//    SPI_1LINE_RX(hspi);
//  }

  /* Enable TXE and ERR interrupt */
  __HAL_SPI_UNMASK_IT(hspi, (SPI_IT_RXU | SPI_IT_RXO | SPI_IT_RXF));

	if((hspi->Instance == SPI1M) || (hspi->Instance == SPI1S))
	{
		/* Configure ICTL and enable ICTL */  
		CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_SPI1_MASK);  //All API interrupt
		SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_SPI1_MASK);

		/* config sim */
		CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_SPI1_MASK); //All API interrupt
	}
	else
	{
		/* Configure ICTL and enable ICTL */  
		CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_SPI2_MASK);  //All API interrupt
		SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_SPI2_MASK);

		/* config sim */
		CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_SPI2_MASK); //All API interrupt
	}

  /* Note : The SPI must be enabled after unlocking current process
            to avoid the risk of SPI interrupt handle execution before current
            process unlock */

  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }

  if (((__HAL_SPI_IS_MASTER(hspi))&& (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY))
		||((__HAL_SPI_IS_SLAVE(hspi)) && (hspi->Init.Direction != SPI_DIRECTION_2LINES_RXONLY)))
  {
    if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
    {
      *((__IO uint16_t *)&hspi->Instance->DR) = 0;
      //hspi->pTxBuffPtr += sizeof(uint16_t);
      //hspi->TxXferCount--;
    }
    else
    {
      *((__IO uint8_t *)&hspi->Instance->DR) = 0;
      //hspi->pTxBuffPtr += sizeof(uint8_t);
      //hspi->TxXferCount--;
    }
  }

error :
  /* Process Unlocked */
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Transmit and Receive an amount of data in non-blocking mode with Interrupt.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pTxData pointer to transmission data buffer
  * @param  pRxData pointer to reception data buffer
  * @param  Size amount of data to be sent and received
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_TransmitReceive_IT(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData, uint16_t Size)
{
//  uint32_t             tmp_mode;
//  HAL_SPI_StateTypeDef tmp_state;
  HAL_StatusTypeDef    errorcode = HAL_OK;
	int i=0;
	uint16_t temp;

  /* Check Direction parameter */
  assert_param(IS_SPI_DIRECTION_2LINES(hspi->Init.Direction));

  /* Process locked */
  __HAL_LOCK(hspi);

  /* Init temporary variables */
//  tmp_state           = hspi->State;
  //tmp_mode            = hspi->Init.Mode;

//  if (!((tmp_state == HAL_SPI_STATE_READY) || \
        ((__HAL_SPI_IS_SLAVE(hspi)) && (hspi->Init.Direction == SPI_DIRECTION_2LINES) && (tmp_state == HAL_SPI_STATE_BUSY_RX))))
//  {
//    errorcode = HAL_BUSY;
//    goto error;
//  }

  if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }

  /* Don't overwrite in case of HAL_SPI_STATE_BUSY_RX */
  if (hspi->State != HAL_SPI_STATE_BUSY_RX)
  {
    hspi->State = HAL_SPI_STATE_BUSY_TX_RX;
  }
 
  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));
	

  /* Set the transaction information */
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (uint8_t *)pTxData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;
  hspi->pRxBuffPtr  = (uint8_t *)pRxData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

  /* Set the function for IT treatment */
  if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
  {
    hspi->RxISR     = SPI_2linesRxISR_16BIT;
    hspi->TxISR     = SPI_2linesTxISR_16BIT;
  }
  else
  {
    hspi->RxISR     = SPI_2linesRxISR_8BIT;
    hspi->TxISR     = SPI_2linesTxISR_8BIT;
  }

  /* Check if packing mode is enabled and if there is more than 2 data to receive */
  if(READ_REG(hspi->Instance->TXFTLR) == 0)
  {
    WRITE_REG(hspi->Instance->TXFTLR, SPI_TXFIFO_THRESHOLD_QF);
  }
  if(READ_REG(hspi->Instance->RXFTLR) == 0)
  {
    WRITE_REG(hspi->Instance->RXFTLR, SPI_RXFIFO_THRESHOLD_QF);
  }

	if((hspi->Instance == SPI1M) || (hspi->Instance == SPI1S))
	{
		/* Configure ICTL and enable ICTL */  
		CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_SPI1_MASK);  //All API interrupt
		SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_SPI1_MASK);

		/* config sim */
		CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_SPI1_MASK); //All API interrupt
	}
	else
	{
		/* Configure ICTL and enable ICTL */  
		CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_SPI2_MASK);  //All API interrupt
		SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_SPI2_MASK);

		/* config sim */
		CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_SPI2_MASK); //All API interrupt
	}

  /* Enable TXE, RXF and ERR interrupt */
	__HAL_SPI_CLEAR_ALLICR(hspi);
  __HAL_SPI_UNMASK_IT(hspi, (SPI_IT_TXE | SPI_IT_RXF | SPI_IT_TXO | SPI_IT_RXU | SPI_IT_RXO));

  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }
	
	if (__HAL_SPI_IS_SLAVE(hspi))
	{
	  for(i=0; i<10; i++) __HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE);  //just for clean TXE in slave mode
	}

	
//	if (__HAL_SPI_IS_MASTER(hspi))
	{
    __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);

		while((__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TFNF)) && (hspi->TxXferCount>0))
	  {
			if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
			{
				temp = *((uint16_t *)(hspi->pTxBuffPtr+1));
				temp <<= 8;
				temp += *((uint16_t *)hspi->pTxBuffPtr);
				*((__IO uint16_t *)&hspi->Instance->DR) = temp;
				hspi->pTxBuffPtr += sizeof(uint16_t);
				hspi->TxXferCount -= sizeof(uint16_t);
			}
			else
			{
				*((__IO uint8_t *)&hspi->Instance->DR) = (*hspi->pTxBuffPtr);
				hspi->pTxBuffPtr += sizeof(uint8_t);
				hspi->TxXferCount--;
			}
	  }
		
	  __HAL_SPI_UNMASK_IT(hspi, (SPI_IT_TXE | SPI_IT_RXF | SPI_IT_TXO | SPI_IT_RXU | SPI_IT_RXO));

	}


error :
  /* Process Unlocked */
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Transmit an amount of data in non-blocking mode with DMA.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pData pointer to data buffer
  * @param  Size amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Transmit_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef errorcode = HAL_OK;
	int i=0;
	uint16_t temp;

  /* Check tx dma handle */
  assert_param(IS_SPI_DMA_HANDLE(hspi->hdmatx));

  /* Check Direction parameter */
  assert_param(IS_SPI_DIRECTION_2LINES_TX(hspi->Init.Direction));

  /* Process Locked */
  __HAL_LOCK(hspi);

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    errorcode = HAL_BUSY;
    goto error;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }
  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));


  /* Set the transaction information */
  hspi->State       = HAL_SPI_STATE_BUSY_TX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (uint8_t *)pData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;

  /* Init field not used in handle to zero */
  hspi->pRxBuffPtr  = (uint8_t *)NULL;
  hspi->TxISR       = NULL;
  hspi->RxISR       = NULL;
  hspi->RxXferSize  = 0U;
  hspi->RxXferCount = 0U;


  //if(READ_REG(hspi->Instance->TXFTLR) == 0)
  {
    WRITE_REG(hspi->Instance->TXFTLR, SPI_TXFIFO_THRESHOLD_HF);
  }

  //if(READ_REG(hspi->Instance->DMATDLR) == 0)
  {
    WRITE_REG(hspi->Instance->DMATDLR, SPI_TXFIFO_THRESHOLD_HF);
  }

  /* Configure communication direction : 1Line */
//  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
//  {
//    /* Disable SPI Peripheral before set 1Line direction (BIDIOE bit) */
//    __HAL_SPI_DISABLE(hspi);
//    SPI_1LINE_TX(hspi);
//  }

  /* Set the SPI TxDMA Half transfer complete callback */
//  hspi->hdmatx->XferHalfCpltCallback = SPI_DMAHalfTransmitCplt;

  /* Set the SPI TxDMA transfer complete callback */
  hspi->hdmatx->XferCpltCallback = SPI_DMATransmitCplt;

  /* Set the DMA error callback */
  hspi->hdmatx->XferErrorCallback = SPI_DMAError;

  /* Set the DMA AbortCpltCallback */
  hspi->hdmatx->XferAbortCallback = SPI_DMATxAbortCallback;

  /* Packing mode is enabled only if the DMA setting is HALWORD */
  if ((hspi->Init.DataSize <= SPI_DATASIZE_8BIT) && (hspi->hdmatx->Init.DstDataSize == DMA_DDATAALIGN_HALFWORD))
  {
    /* Check the even/odd of the data size + crc if enabled */
    if ((hspi->TxXferCount & 0x1U) == 0U)
    {
      hspi->TxXferCount = (hspi->TxXferCount >> 1U);
    }
    else
    {
      hspi->TxXferCount = (hspi->TxXferCount >> 1U) + 1U;
    }
  }

  /* Enable the SPI Error Interrupt Bit */
  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));



  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }

	if (__HAL_SPI_IS_SLAVE(hspi))
	{
	  for(i=0; i<10; i++) __HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE);  //just for clean TXE in slave mode
	}
	
  //if (__HAL_SPI_IS_SLAVE(hspi))
	{
		//__HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));
		
		if((__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TFNF)) && (hspi->TxXferCount>0))
		{
			if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
			{
				temp = *((uint16_t *)(hspi->pTxBuffPtr+1));
				temp <<= 8;
				temp += *((uint16_t *)hspi->pTxBuffPtr);
				*((__IO uint16_t *)&hspi->Instance->DR) = temp;
				hspi->pTxBuffPtr += sizeof(uint16_t);
				hspi->TxXferCount -= sizeof(uint16_t);
			}
			else
			{
				*((__IO uint8_t *)&hspi->Instance->DR) = (*hspi->pTxBuffPtr);
				hspi->pTxBuffPtr += sizeof(uint8_t);
				hspi->TxXferCount--;
		  }
	  }
		__HAL_SPI_UNMASK_IT(hspi, (SPI_IT_TXO));
  }
	
	if(hspi->TxXferCount > 0)
	{
		/* Enable the Tx DMA Stream/Channel */
		if (HAL_OK != HAL_DMA_Start_IT(hspi->hdmatx, (uint32_t)hspi->pTxBuffPtr, (uint32_t)&hspi->Instance->DR,
																	 hspi->TxXferCount))
		{
			/* Update SPI error code */
			SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
			errorcode = HAL_ERROR;

			hspi->State = HAL_SPI_STATE_READY;
			goto error;
		}

		/* Enable Tx DMA Request */
		SET_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE);
  }
	else
	{
		if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
		{
			hspi->TxISR = SPI_TxISR_16BIT;
		}
		else
		{
			hspi->TxISR = SPI_TxISR_8BIT;
		}
		__HAL_SPI_UNMASK_IT(hspi, (SPI_IT_TXE));
	}

error :
  /* Process Unlocked */
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Receive an amount of data in non-blocking mode with DMA.
  * @note   In case of MASTER mode and SPI_DIRECTION_2LINES direction, hdmatx shall be defined.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pData pointer to data buffer
  * @note   When the CRC feature is enabled the pData Length must be Size + 1.
  * @param  Size amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Receive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef errorcode = HAL_OK;


  /* Check rx dma handle */
  assert_param(IS_SPI_DMA_HANDLE(hspi->hdmarx));

  if ((hspi->Init.Direction == SPI_DIRECTION_2LINES) && (__HAL_SPI_IS_MASTER(hspi)))
  {
    hspi->State = HAL_SPI_STATE_BUSY_RX;

    /* Check tx dma handle */
    assert_param(IS_SPI_DMA_HANDLE(hspi->hdmatx));

    /* Call transmit-receive function to send Dummy data on Tx line and generate clock on CLK line */
    return HAL_SPI_TransmitReceive_DMA(hspi, pData, pData, Size);
  }

  if ((__HAL_SPI_IS_MASTER(hspi))&& (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY))
  {
    WRITE_REG(hspi->Instance->CTRLR1, Size - 1);
  }

	if ((__HAL_SPI_IS_SLAVE(hspi)))
	{
		__HAL_SPI_MASK_IT(hspi, SPI_IT_TXE);
	}
	
	
  /* Process Locked */
  __HAL_LOCK(hspi);

  if (hspi->State != HAL_SPI_STATE_READY)
  {
    errorcode = HAL_BUSY;
    goto error;
  }

  if ((pData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }

  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));

  /* Set the transaction information */
  hspi->State       = HAL_SPI_STATE_BUSY_RX;
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pRxBuffPtr  = (uint8_t *)pData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

  /*Init field not used in handle to zero */
  hspi->RxISR       = NULL;
  hspi->TxISR       = NULL;
  hspi->TxXferSize  = 0U;
  hspi->TxXferCount = 0U;

  //if(READ_REG(hspi->Instance->RXFTLR) == 0)
  {
    WRITE_REG(hspi->Instance->RXFTLR, SPI_RXFIFO_THRESHOLD_E);
  }

  //if(READ_REG(hspi->Instance->DMARDLR) == 0)
  {
    WRITE_REG(hspi->Instance->DMARDLR, SPI_RXFIFO_THRESHOLD_E);
  }
  /* Configure communication direction : 1Line */
//  if (hspi->Init.Direction == SPI_DIRECTION_1LINE)
//  {
//    /* Disable SPI Peripheral before set 1Line direction (BIDIOE bit) */
//    __HAL_SPI_DISABLE(hspi);
//    SPI_1LINE_RX(hspi);
//  }

    if ((hspi->Init.DataSize <= SPI_DATASIZE_8BIT) && (hspi->hdmarx->Init.DstDataSize == DMA_DDATAALIGN_HALFWORD))
    {
      /* Set RX Fifo threshold according the reception data length: 16bit */

      if ((hspi->RxXferCount & 0x1U) == 0x0U)
      {
        hspi->RxXferCount = hspi->RxXferCount >> 1U;
      }
      else
      {
        hspi->RxXferCount = (hspi->RxXferCount >> 1U) + 1U;
      }
    }

  /* Set the SPI RxDMA Half transfer complete callback */
//  hspi->hdmarx->XferHalfCpltCallback = SPI_DMAHalfReceiveCplt;

  /* Set the SPI Rx DMA transfer complete callback */
  hspi->hdmarx->XferCpltCallback = SPI_DMAReceiveCplt;

  /* Set the DMA error callback */
  hspi->hdmarx->XferErrorCallback = SPI_DMAError;

  /* Set the DMA AbortCpltCallback */
  hspi->hdmarx->XferAbortCallback = SPI_DMARxAbortCallback;

  /* Enable the SPI Error Interrupt Bit */
  __HAL_SPI_UNMASK_IT(hspi, (SPI_IT_RXO | SPI_IT_RXU));

	/* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }
		
  if (((__HAL_SPI_IS_MASTER(hspi))&& (hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY))
		 || ((__HAL_SPI_IS_SLAVE(hspi))&& (hspi->Init.Direction != SPI_DIRECTION_2LINES_RXONLY)))
	{
		if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
		{
			hspi->Instance->DR = 0;
			//hspi->pTxBuffPtr += sizeof(uint16_t);
			//hspi->TxXferCount = 0;
		}
		else
		{
			*((__IO uint8_t *)&hspi->Instance->DR) = 0;
			//hspi->pTxBuffPtr += sizeof(uint8_t);
			//hspi->TxXferCount = 0;
		}
  }

#if 1 //MCU_SIMULATION	
	(*((uint32_t*)0x50000C00)) = 0x000000C0UL;
#endif
		
  /* Enable the Rx DMA Stream/Channel  */
  if (HAL_OK != HAL_DMA_Start_IT(hspi->hdmarx, (uint32_t)&hspi->Instance->DR, (uint32_t)hspi->pRxBuffPtr,
                                 hspi->RxXferCount))
  {
    /* Update SPI error code */
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
    errorcode = HAL_ERROR;

    hspi->State = HAL_SPI_STATE_READY;
    goto error;
  }

//  /* Check if the SPI is already enabled */
//  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
//  {
//    /* Enable SPI peripheral */
//    __HAL_SPI_ENABLE(hspi);
//  }


  /* Enable Rx DMA Request */
  SET_BIT(hspi->Instance->DMACR, SPI_DMACR_RDMAE);

error:
  /* Process Unlocked */
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Transmit and Receive an amount of data in non-blocking mode with DMA.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  pTxData pointer to transmission data buffer
  * @param  pRxData pointer to reception data buffer
  * @note   When the CRC feature is enabled the pRxData Length must be Size + 1
  * @param  Size amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_TransmitReceive_DMA(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData,
                                              uint16_t Size)
{
  //uint32_t             tmp_mode;
//  HAL_SPI_StateTypeDef tmp_state;
  HAL_StatusTypeDef errorcode = HAL_OK;
	int i=0;
		uint16_t temp;

  /* Check rx & tx dma handles */
  assert_param(IS_SPI_DMA_HANDLE(hspi->hdmarx));
  assert_param(IS_SPI_DMA_HANDLE(hspi->hdmatx));

  /* Check Direction parameter */
  assert_param(IS_SPI_DIRECTION_2LINES(hspi->Init.Direction));

  /* Process locked */
  __HAL_LOCK(hspi);

  /* Init temporary variables */
//  tmp_state           = hspi->State;
  //tmp_mode            = hspi->Init.Mode;

//  if (!((tmp_state == HAL_SPI_STATE_READY) ||
//        ((__HAL_SPI_IS_MASTER(hspi)) && (hspi->Init.Direction == SPI_DIRECTION_2LINES) && (tmp_state == HAL_SPI_STATE_BUSY_RX))))
//  {
//    errorcode = HAL_BUSY;
//    goto error;
//  }

  if ((pTxData == NULL) || (pRxData == NULL) || (Size == 0U))
  {
    errorcode = HAL_ERROR;
    goto error;
  }

  /* Don't overwrite in case of HAL_SPI_STATE_BUSY_RX */
  if (hspi->State != HAL_SPI_STATE_BUSY_RX)
  {
    hspi->State = HAL_SPI_STATE_BUSY_TX_RX;
  }

  __HAL_SPI_DISABLE(hspi);

  __HAL_SPI_MASK_IT(hspi, (SPI_IT_ALL));
	

  /* Set the transaction information */
  hspi->ErrorCode   = HAL_SPI_ERROR_NONE;
  hspi->pTxBuffPtr  = (uint8_t *)pTxData;
  hspi->TxXferSize  = Size;
  hspi->TxXferCount = Size;
  hspi->pRxBuffPtr  = (uint8_t *)pRxData;
  hspi->RxXferSize  = Size;
  hspi->RxXferCount = Size;

  /* Init field not used in handle to zero */
  hspi->RxISR       = NULL;
  hspi->TxISR       = NULL;


//  if(READ_REG(hspi->Instance->TXFTLR) == 0)
  {
    WRITE_REG(hspi->Instance->TXFTLR, SPI_TXFIFO_THRESHOLD_HF);
  }

//  if(READ_REG(hspi->Instance->DMATDLR) == 0)
  {
    WRITE_REG(hspi->Instance->DMATDLR, SPI_TXFIFO_THRESHOLD_HF);
  }

// if(READ_REG(hspi->Instance->RXFTLR) == 0)
  {
    WRITE_REG(hspi->Instance->RXFTLR, SPI_RXFIFO_THRESHOLD_E);
  }

//  if(READ_REG(hspi->Instance->DMARDLR) == 0)
  {
    WRITE_REG(hspi->Instance->DMARDLR, SPI_RXFIFO_THRESHOLD_E);
  }

    if (hspi->hdmatx->Init.DstDataSize == DMA_DDATAALIGN_HALFWORD)
    {
      if ((hspi->TxXferSize & 0x1U) == 0x0U)
      {
        hspi->TxXferCount = hspi->TxXferCount >> 1U;
      }
      else
      {
        hspi->TxXferCount = (hspi->TxXferCount >> 1U) + 1U;
      }
    }

    if (hspi->hdmarx->Init.DstDataSize == DMA_DDATAALIGN_HALFWORD)
    {
      /* Set RX Fifo threshold according the reception data length: 16bit */
      if ((hspi->RxXferCount & 0x1U) == 0x0U)
      {
        hspi->RxXferCount = hspi->RxXferCount >> 1U;
      }
      else
      {
        hspi->RxXferCount = (hspi->RxXferCount >> 1U) + 1U;
      }
    }

  /* Check if we are in Rx only or in Rx/Tx Mode and configure the DMA transfer complete callback */
  if (hspi->State == HAL_SPI_STATE_BUSY_RX)
  {
    /* Set the SPI Rx DMA Half transfer complete callback */
//    hspi->hdmarx->XferHalfCpltCallback = SPI_DMAHalfReceiveCplt;
    hspi->hdmarx->XferCpltCallback     = SPI_DMAReceiveCplt;
  }
  else
  {
    /* Set the SPI Tx/Rx DMA Half transfer complete callback */
//    hspi->hdmarx->XferHalfCpltCallback = SPI_DMAHalfTransmitReceiveCplt;
    hspi->hdmarx->XferCpltCallback     = SPI_DMATransmitReceiveCplt;
  }

  /* Set the DMA error callback */
  hspi->hdmarx->XferErrorCallback = SPI_DMAError;

  /* Set the DMA AbortCpltCallback */
  hspi->hdmarx->XferAbortCallback = SPI_DMARxAbortCallback;
	
  /* Enable the SPI Error Interrupt Bit */
  //__HAL_SPI_UNMASK_IT(hspi, (SPI_IT_TXO | SPI_IT_RXO | SPI_IT_RXU));

  /* Check if the SPI is already enabled */
  if ((hspi->Instance->SSIENR & SPI_SSIENR_SSIEN) != SPI_SSIENR_SSIEN)
  {
    /* Enable SPI peripheral */
    __HAL_SPI_ENABLE(hspi);
  }
	
	if (__HAL_SPI_IS_SLAVE(hspi))
	{
	  for(i=0; i<10; i++) __HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TXE);  //just for clean TXE in slave mode
	}


  //if (__HAL_SPI_IS_SLAVE(hspi))
	{
		//__HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);
		
		while((__HAL_SPI_GET_STATUS(hspi, SPI_STATUS_TFNF)) && (hspi->TxXferCount>0)) 
		{
			if (hspi->Init.DataSize > SPI_DATASIZE_8BIT)
			{
				temp = *((uint16_t *)(hspi->pTxBuffPtr+1));
				temp <<= 8;
				temp = *((uint16_t *)hspi->pTxBuffPtr);
				*((__IO uint16_t *)&hspi->Instance->DR) = temp;
				hspi->pTxBuffPtr += sizeof(uint16_t);
				hspi->TxXferCount -= sizeof(uint16_t);
			}
			else
			{
				*((__IO uint8_t *)&hspi->Instance->DR) = (*hspi->pTxBuffPtr);
				hspi->pTxBuffPtr += sizeof(uint8_t);
				hspi->TxXferCount--;
			}
	  }
		
		__HAL_SPI_UNMASK_IT(hspi, (SPI_IT_TXO | SPI_IT_RXO | SPI_IT_RXU));
  }
	
  /* Enable the Rx DMA Stream/Channel  */
  if (HAL_OK != HAL_DMA_Start_IT(hspi->hdmarx, (uint32_t)&hspi->Instance->DR, (uint32_t)hspi->pRxBuffPtr,
                                 hspi->RxXferCount))
  {
    /* Update SPI error code */
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
    errorcode = HAL_ERROR;

    hspi->State = HAL_SPI_STATE_READY;
    goto error;
  }


  if(hspi->TxXferCount > 0)
	{
		/* Set the SPI Tx DMA transfer complete callback as NULL because the communication closing
		is performed in DMA reception complete callback  */
	//  hspi->hdmatx->XferHalfCpltCallback = NULL;
		hspi->hdmatx->XferCpltCallback     = SPI_DMATransmitReceiveTxCplt;
		hspi->hdmatx->XferErrorCallback    = NULL;
		hspi->hdmatx->XferAbortCallback    = SPI_DMATxAbortCallback;

		/* Enable the Tx DMA Stream/Channel  */
		if (HAL_OK != HAL_DMA_Start_IT(hspi->hdmatx, (uint32_t)hspi->pTxBuffPtr, (uint32_t)&hspi->Instance->DR,
																	 hspi->TxXferCount))
		{
			/* Update SPI error code */
			SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
			errorcode = HAL_ERROR;

			hspi->State = HAL_SPI_STATE_READY;
			goto error;
		}

		/* Enable Tx DMA Request */
		SET_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE);
  }
  
  /* Enable Tx DMA Request */
  SET_BIT(hspi->Instance->DMACR, SPI_DMACR_RDMAE);

error :
  /* Process Unlocked */
  __HAL_UNLOCK(hspi);
  return errorcode;
}

/**
  * @brief  Abort ongoing transfer (blocking mode).
  * @param  hspi SPI handle.
  * @note   This procedure could be used for aborting any ongoing transfer (Tx and Rx),
  *         started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable SPI Interrupts (depending of transfer direction)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort (in case of transfer in DMA mode)
  *           - Set handle State to READY
  * @note   This procedure is executed in blocking mode : when exiting function, Abort is considered as completed.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Abort(SPI_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef errorcode;
  __IO uint32_t count;
  __IO uint32_t resetcount;

  /* Initialized local variable  */
  errorcode = HAL_OK;
  resetcount = SPI_DEFAULT_TIMEOUT * (SystemCoreClock / 24U / 1000U);
  count = resetcount;

  /* Clear all interrupt to avoid error interrupts generation during Abort procedure */
  CLEAR_BIT(hspi->Instance->ICR, SPI_ICR_ICR);

  /* Disable TXEIE, RXNEIE and ERRIE(mode fault event, overrun error, TI frame error) interrupts */
  if (HAL_IS_BIT_SET(hspi->Instance->IMR, SPI_IT_TXE))
  {
    hspi->TxISR = SPI_AbortTx_ISR;
    /* Wait HAL_SPI_STATE_ABORT state */
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (hspi->State != HAL_SPI_STATE_ABORT);
    /* Reset Timeout Counter */
    count = resetcount;
  }

  if (HAL_IS_BIT_SET(hspi->Instance->IMR, SPI_IT_RXF))
  {
    hspi->RxISR = SPI_AbortRx_ISR;
    /* Wait HAL_SPI_STATE_ABORT state */
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (hspi->State != HAL_SPI_STATE_ABORT);
    /* Reset Timeout Counter */
    count = resetcount;
  }

  /* Disable the SPI DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hspi->Instance->DMACR, SPI_DMACR_TDMAE))
  {
    /* Abort the SPI DMA Tx Stream/Channel : use blocking DMA Abort API (no callback) */
    if (hspi->hdmatx != NULL)
    {
      /* Set the SPI DMA Abort callback :
      will lead to call HAL_SPI_AbortCpltCallback() at end of DMA abort procedure */
      hspi->hdmatx->XferAbortCallback = NULL;

      /* Abort DMA Tx Handle linked to SPI Peripheral */
      if (HAL_DMA_Abort(hspi->hdmatx/*, SPI_DEFAULT_TIMEOUT*/) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

      /* Disable Tx DMA Request */
      CLEAR_BIT(hspi->Instance->DMACR, (SPI_DMACR_RDMAE));

      if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

      /* Disable SPI Peripheral */
      __HAL_SPI_DISABLE(hspi);

      /* Empty the FRLVL fifo */
      if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_TFE, SET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }
    }
  }

  /* Disable the SPI DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hspi->Instance->DMACR, SPI_DMACR_RDMAE))
  {
    /* Abort the SPI DMA Rx Stream/Channel : use blocking DMA Abort API (no callback) */
    if (hspi->hdmarx != NULL)
    {
      /* Set the SPI DMA Abort callback :
      will lead to call HAL_SPI_AbortCpltCallback() at end of DMA abort procedure */
      hspi->hdmarx->XferAbortCallback = NULL;

      /* Abort DMA Rx Handle linked to SPI Peripheral */
      if (HAL_DMA_Abort(hspi->hdmarx/*, SPI_DEFAULT_TIMEOUT*/) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

      /* Disable peripheral */
      __HAL_SPI_DISABLE(hspi);

      /* Control the BSY flag */
      if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_BUSY, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

      /* Empty the FRLVL fifo */
      if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_RFNE, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
      {
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }

      /* Disable Rx DMA Request */
      CLEAR_BIT(hspi->Instance->DMACR, (SPI_DMACR_RDMAE));
    }
  }
  /* Reset Tx and Rx transfer counters */
  hspi->RxXferCount = 0U;
  hspi->TxXferCount = 0U;

  /* Check error during Abort procedure */
  if (hspi->ErrorCode == HAL_SPI_ERROR_ABORT)
  {
    /* return HAL_Error in case of error during Abort procedure */
    errorcode = HAL_ERROR;
  }
  else
  {
    /* Reset errorCode */
    hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  }

  /* Restore hspi->state to ready */
  hspi->State = HAL_SPI_STATE_READY;

  return errorcode;
}

/**
  * @brief  Abort ongoing transfer (Interrupt mode).
  * @param  hspi SPI handle.
  * @note   This procedure could be used for aborting any ongoing transfer (Tx and Rx),
  *         started in Interrupt or DMA mode.
  *         This procedure performs following operations :
  *           - Disable SPI Interrupts (depending of transfer direction)
  *           - Disable the DMA transfer in the peripheral register (if enabled)
  *           - Abort DMA transfer by calling HAL_DMA_Abort_IT (in case of transfer in DMA mode)
  *           - Set handle State to READY
  *           - At abort completion, call user abort complete callback
  * @note   This procedure is executed in Interrupt mode, meaning that abort procedure could be
  *         considered as completed only when user abort complete callback is executed (not when exiting function).
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_Abort_IT(SPI_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef errorcode;
  uint32_t abortcplt ;
  __IO uint32_t count;
  __IO uint32_t resetcount;

  /* Initialized local variable  */
  errorcode = HAL_OK;
  abortcplt = 1U;
  resetcount = SPI_DEFAULT_TIMEOUT * (SystemCoreClock / 24U / 1000U);
  count = resetcount;

  /* Clear ERRIE interrupt to avoid error interrupts generation during Abort procedure */
  __HAL_SPI_MASK_IT(hspi, (SPI_IT_TXO | SPI_IT_RXO |SPI_IT_RXU));

  /* Change Rx and Tx Irq Handler to Disable TXEIE, RXNEIE and ERRIE interrupts */
  if (HAL_IS_BIT_SET(hspi->Instance->IMR, SPI_IT_TXE))
  {
    hspi->TxISR = SPI_AbortTx_ISR;
    /* Wait HAL_SPI_STATE_ABORT state */
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (hspi->State != HAL_SPI_STATE_ABORT);
    /* Reset Timeout Counter */
    count = resetcount;
  }

  if (HAL_IS_BIT_SET(hspi->Instance->IMR, SPI_IT_RXF))
  {
    hspi->RxISR = SPI_AbortRx_ISR;
    /* Wait HAL_SPI_STATE_ABORT state */
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (hspi->State != HAL_SPI_STATE_ABORT);
    /* Reset Timeout Counter */
    count = resetcount;
  }

  /* Disable the SPI DMA Tx request if enabled */
  if (HAL_IS_BIT_SET(hspi->Instance->DMACR, SPI_DMACR_TDMAE))
  {
    /* Abort the SPI DMA Tx Stream/Channel */
    if (hspi->hdmatx != NULL)
    {
      /* Abort DMA Tx Handle linked to SPI Peripheral */
      if (HAL_DMA_Abort_IT(hspi->hdmatx/*, SPI_DEFAULT_TIMEOUT*/) != HAL_OK)
      {
        //hspi->hdmatx->XferAbortCallback = NULL;
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }
      else
      {
        abortcplt = 0U;
      }
    }
  }
  /* Disable the SPI DMA Rx request if enabled */
  if (HAL_IS_BIT_SET(hspi->Instance->DMACR, SPI_DMACR_RDMAE))
  {
    /* Abort the SPI DMA Rx Stream/Channel */
    if (hspi->hdmarx != NULL)
    {
      /* Abort DMA Rx Handle linked to SPI Peripheral */
      if (HAL_DMA_Abort_IT(hspi->hdmarx/*, SPI_DEFAULT_TIMEOUT*/) !=  HAL_OK)
      {
        //hspi->hdmarx->XferAbortCallback = NULL;
        hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
      }
      else
      {
        abortcplt = 0U;
      }
    }
  }

  if (abortcplt == 1U)
  {
    /* Reset Tx and Rx transfer counters */
    hspi->RxXferCount = 0U;
    hspi->TxXferCount = 0U;

    /* Check error during Abort procedure */
    if (hspi->ErrorCode == HAL_SPI_ERROR_ABORT)
    {
      /* return HAL_Error in case of error during Abort procedure */
      errorcode = HAL_ERROR;
    }
    else
    {
      /* Reset errorCode */
      hspi->ErrorCode = HAL_SPI_ERROR_NONE;
    }

    /* Restore hspi->State to Ready */
    hspi->State = HAL_SPI_STATE_READY;

    /* As no DMA to be aborted, call directly user Abort complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->AbortCpltCallback(hspi);
#else
    HAL_SPI_AbortCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
  }

  return errorcode;
}

/**
  * @brief  Pause the DMA Transfer.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for the specified SPI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_DMAPause(SPI_HandleTypeDef *hspi)
{
  /* Process Locked */
  __HAL_LOCK(hspi);

   /* Suspend DMA */
  __HAL_DMA_Suspend(hspi->hdmatx);
  __HAL_DMA_Suspend(hspi->hdmarx);

  /* Polling DMA FIFI.empty*/

 

  /* Disable the SPI Tx & Rx DMA FIFO channel */
  CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE | SPI_DMACR_RDMAE);

  /* Process Unlocked */
  __HAL_UNLOCK(hspi);

  return HAL_OK;
}

/**
  * @brief  Resume the DMA Transfer.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for the specified SPI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_DMAResume(SPI_HandleTypeDef *hspi)
{
  /* Process Locked */
  __HAL_LOCK(hspi);

  /* Enable the SPI Tx & Rx DMA FIFO channel */
  SET_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE | SPI_DMACR_RDMAE);

  /* not suspend DMA */
  __HAL_DMA_NotSuspend(hspi->hdmatx);
  __HAL_DMA_NotSuspend(hspi->hdmarx);

  /* Process Unlocked */
  __HAL_UNLOCK(hspi);

  return HAL_OK;
}

/**
  * @brief  Stop the DMA Transfer.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for the specified SPI module.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_SPI_DMAStop(SPI_HandleTypeDef *hspi)
{
  HAL_StatusTypeDef errorcode = HAL_OK;
  /* The Lock is not implemented on this API to allow the user application
     to call the HAL SPI API under callbacks HAL_SPI_TxCpltCallback() or HAL_SPI_RxCpltCallback() or HAL_SPI_TxRxCpltCallback():
     when calling HAL_DMA_Abort() API the DMA TX/RX Transfer complete interrupt is generated
     and the correspond call back is executed HAL_SPI_TxCpltCallback() or HAL_SPI_RxCpltCallback() or HAL_SPI_TxRxCpltCallback()
     */

  /* Abort the SPI DMA tx Stream/Channel  */
  if (hspi->hdmatx != NULL)
  {
    if (HAL_OK != HAL_DMA_Abort(hspi->hdmatx/*, SPI_DEFAULT_TIMEOUT*/))
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
      errorcode = HAL_ERROR;
    }
  }
  /* Abort the SPI DMA rx Stream/Channel  */
  if (hspi->hdmarx != NULL)
  {
    if (HAL_OK != HAL_DMA_Abort(hspi->hdmarx/*, SPI_DEFAULT_TIMEOUT*/))
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
      errorcode = HAL_ERROR;
    }
  }

  /* Disable the SPI DMA Tx & Rx requests */
  CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE | SPI_DMACR_RDMAE);
  hspi->State = HAL_SPI_STATE_READY;
  return errorcode;
}

/**
  * @}
  */

/** @defgroup SPI_Exported_Functions_Group3 IRQ handler and interrupt functions
  * @brief   IRQ handler and interrupt functions
  *
  * @{
  */

/**
  * @brief  Handle SPI interrupt request.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for the specified SPI module.
  */
void HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi)
{
  uint32_t it = hspi->Instance->ISR;
  uint32_t status   = hspi->Instance->SR;
  uint32_t mask = hspi->Instance->IMR;
	
	if((hspi->Instance == SPI1M)||(hspi->Instance == SPI1S))
	{
	  if(SYSCFG->IRQ_CFG_1 & ICTL_IRQCFG_SPI1_MASK)
		{
			return;
		}
		if((ICTL->IRQFINALSTATUSL & ICTL_IRQCFG_SPI1_MASK) == 0)
		{
			return;
		}
	}
	if((hspi->Instance == SPI2M)||(hspi->Instance == SPI2S))
	{
	  if(SYSCFG->IRQ_CFG_1 & ICTL_IRQCFG_SPI2_MASK)
		{
			return;
		}
		if((ICTL->IRQFINALSTATUSL & ICTL_IRQCFG_SPI2_MASK) == 0)
		{
			return;
		}
	}
	
  /* SPI in mode Receiver ----------------------------------------------------*/
  if ((SPI_CHECK_STATUS(status, SPI_STATUS_RFNE) != RESET) && (SPI_CHECK_IT(it, SPI_IT_RXF) != RESET))
  {
		if(hspi->RxISR != NULL)
		{
      hspi->RxISR(hspi);
      //return;
		}
  }

  /* SPI in mode Transmitter -------------------------------------------------*/
  if ((SPI_CHECK_STATUS(status, SPI_STATUS_TFNF) != RESET) && (SPI_CHECK_IT(it, SPI_IT_TXE) != RESET))
  {
		if(hspi->TxISR != NULL)
		{
      hspi->TxISR(hspi);
      //return;
		}
  }

  /* SPI in Error Treatment --------------------------------------------------*/
  if ((SPI_CHECK_STATUS(status, SPI_STATUS_DCOL) != RESET) || (SPI_CHECK_STATUS(status, SPI_STATUS_TXE) != RESET)
       || (SPI_CHECK_IT(it, SPI_IT_MST) != RESET) || (SPI_CHECK_IT(it, SPI_IT_RXO) != RESET)
       || (SPI_CHECK_IT(it, SPI_IT_RXU) != RESET) || (SPI_CHECK_IT(it, SPI_IT_TXO) != RESET))
  {
		/* Disable all interrupts */
  	__HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);

    /* SPI Overrun error interrupt occurred ----------------------------------*/
    if (SPI_CHECK_IT(it, SPI_IT_TXO) != RESET)
    {
//      if (hspi->State != HAL_SPI_STATE_BUSY_TX)
//      {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_TXO);
//        __HAL_SPI_CLEAR_OVRFLAG(hspi);
//      }
//      else
//      {
//        __HAL_SPI_CLEAR_OVRFLAG(hspi);
//        return;
//      }
      __HAL_SPI_CLEAR_TXOICR(hspi);
      //return;
    }

    if (SPI_CHECK_IT(it, SPI_IT_RXO) != RESET) 
    {
//      if (hspi->State != HAL_SPI_STATE_BUSY_TX)
//      {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_RXO);
//        __HAL_SPI_CLEAR_OVRFLAG(hspi);
//      }
//      else
//      {
//        __HAL_SPI_CLEAR_OVRFLAG(hspi);
//        return;
//      }
      __HAL_SPI_CLEAR_RXOICR(hspi);
      //return;
    }

    if (SPI_CHECK_IT(it, SPI_IT_RXU) != RESET) 
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_RXU);
      __HAL_SPI_CLEAR_RXUICR(hspi);
      //return;
    }

    if (SPI_CHECK_IT(it, SPI_IT_MST) != RESET) 
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_MST);
      __HAL_SPI_CLEAR_MSTICR(hspi);
      //return;
    }

    /* SPI Mode Fault error interrupt occurred -------------------------------*/
    if (SPI_CHECK_STATUS(status, SPI_STATUS_DCOL) != RESET)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DCOL);
      //__HAL_SPI_CLEAR_MODFFLAG(hspi);
    }

    /* SPI Frame error interrupt occurred ------------------------------------*/
    if (SPI_CHECK_STATUS(status, SPI_STATUS_TXE) != RESET)
    {
			if((__HAL_SPI_IS_SLAVE(hspi)) && (hspi->TxXferCount > 0))
			{
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_TXE);
      }
    }

    if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
    {
      hspi->State = HAL_SPI_STATE_READY;
      /* Disable the SPI DMA requests if enabled */
      if ((HAL_IS_BIT_SET(hspi->Instance->DMACR, SPI_DMACR_TDMAE)) || (HAL_IS_BIT_SET(hspi->Instance->DMACR, SPI_DMACR_RDMAE)))
      {
        CLEAR_BIT(hspi->Instance->DMACR, (SPI_DMACR_TDMAE | SPI_DMACR_RDMAE));

        /* Abort the SPI DMA Rx channel */
        if (hspi->hdmarx != NULL)
        {
          /* Set the SPI DMA Abort callback :
          will lead to call HAL_SPI_ErrorCallback() at end of DMA abort procedure */
          hspi->hdmarx->XferAbortCallback = SPI_DMAAbortOnError;
          if (HAL_OK != HAL_DMA_Abort_IT(hspi->hdmarx/*,SPI_DEFAULT_TIMEOUT*/))
          {
            SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
          }
        }
        /* Abort the SPI DMA Tx channel */
        if (hspi->hdmatx != NULL)
        {
          /* Set the SPI DMA Abort callback :
          will lead to call HAL_SPI_ErrorCallback() at end of DMA abort procedure */
          hspi->hdmatx->XferAbortCallback = SPI_DMAAbortOnError;
          if (HAL_OK != HAL_DMA_Abort_IT(hspi->hdmatx/*, SPI_DEFAULT_TIMEOUT*/))
          {
            SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
          }
        }
      }
      else
      {
        /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
        hspi->ErrorCallback(hspi);
#else
        HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
      }
    }
		
 	  __HAL_SPI_UNMASK_IT(hspi, mask);
 }
	
	
}

/**
  * @brief  Tx Transfer completed callback.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
__weak void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_TxCpltCallback should be implemented in the user file
   */
}

/**
  * @brief  Rx Transfer completed callback.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
__weak void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_RxCpltCallback should be implemented in the user file
   */
}

/**
  * @brief  Tx and Rx Transfer completed callback.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
__weak void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_TxRxCpltCallback should be implemented in the user file
   */
}

/**
  * @brief  SPI error callback.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
__weak void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_ErrorCallback should be implemented in the user file
   */
  /* NOTE : The ErrorCode parameter in the hspi handle is updated by the SPI processes
            and user can use HAL_SPI_GetError() API to check the latest error occurred
   */
}

/**
  * @brief  SPI Abort Complete callback.
  * @param  hspi SPI handle.
  */
__weak void HAL_SPI_AbortCpltCallback(SPI_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_AbortCpltCallback can be implemented in the user file.
   */
}

/**
  * @}
  */

/** @defgroup SPI_Exported_Functions_Group4 Peripheral State and Errors functions
  * @brief   SPI control functions
  *
  * @{
  */

/**
  * @brief  Return the SPI handle state.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval SPI state
  */
HAL_SPI_StateTypeDef HAL_SPI_GetState(SPI_HandleTypeDef *hspi)
{
  /* Return SPI handle state */
  return hspi->State;
}

/**
  * @brief  Return the SPI error code.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @retval SPI error code in bitmap format
  */
uint32_t HAL_SPI_GetError(SPI_HandleTypeDef *hspi)
{
  /* Return SPI ErrorCode */
  return hspi->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup SPI_Private_Functions
  * @brief   
  * @{
  */

/**
  * @brief  DMA SPI transmit process complete callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA module.
  */
static void SPI_DMATransmitCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */
  uint32_t tickstart;

  /* Init tickstart for timeout management*/
  tickstart = HAL_GetTick();

  /* DMA Normal Mode */
  if (hspi->hdmatx->Init.Mode == DMA_SGLBLK)
  {
    /* Disable ERR interrupt */
    __HAL_SPI_MASK_IT(hspi, SPI_IT_TXO);

    /* Disable Tx DMA Request */
    CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE);
		
    /* Check the end of the transaction */
    if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    }

    /* Clear overrun flag in 2 Lines communication mode because received data is not read */
    if (hspi->Init.Direction == SPI_DIRECTION_2LINES)
    {
      __HAL_SPI_CLEAR_RXOICR(hspi);
    }

    hspi->TxXferCount = 0U;
    hspi->State = HAL_SPI_STATE_READY;

    if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
    {
      /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->ErrorCallback(hspi);
#else
      HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
      return;
    }
  }
  /* Call user Tx complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->TxCpltCallback(hspi);
#else
  HAL_SPI_TxCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SPI receive process complete callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA module.
  */
static void SPI_DMAReceiveCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */
  uint32_t tickstart;

  /* Init tickstart for timeout management*/
  tickstart = HAL_GetTick();

  /* DMA Normal Mode */
  if (hspi->hdmarx->Init.Mode == DMA_SGLBLK)
  {
    /* Disable ERR interrupt */
    __HAL_SPI_MASK_IT(hspi, (SPI_IT_RXO | SPI_IT_RXU));

    /* Check if we are in Master RX 2 line mode */
    if ((hspi->Init.Direction == SPI_DIRECTION_2LINES) /*&& (__HAL_SPI_IS_MASTER(hspi)*/)
    {
      /* Disable Rx/Tx DMA Request (done by default to handle the case master rx direction 2 lines) */
      CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE | SPI_DMACR_RDMAE);
    }
    else
    {
      /* Normal case */
      CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_RDMAE);
    }

    /* Check the end of the transaction */
    if (SPI_EndRxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
    {
      hspi->ErrorCode = HAL_SPI_ERROR_FLAG;
    }

    hspi->RxXferCount = 0U;
    hspi->State = HAL_SPI_STATE_READY;

    if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
    {
      /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->ErrorCallback(hspi);
#else
      HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
      return;
    }
  }
  /* Call user Rx complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->RxCpltCallback(hspi);
#else
  HAL_SPI_RxCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SPI transmit receive process complete callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA module.
  */
static void SPI_DMATransmitReceiveCplt(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */
  uint32_t tickstart;

  /* Init tickstart for timeout management*/
  tickstart = HAL_GetTick();

  /* DMA Normal Mode */
  if (hspi->hdmatx->Init.Mode == DMA_SGLBLK)
  {
    /* Disable ERR interrupt */
    __HAL_SPI_MASK_IT(hspi, (SPI_IT_TXO | SPI_IT_RXO | SPI_IT_RXU));

    /* Check the end of the transaction */
    if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    }

    /* Disable Rx/Tx DMA Request */
    CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE | SPI_DMACR_RDMAE);

    hspi->TxXferCount = 0U;
    hspi->RxXferCount = 0U;
    hspi->State = HAL_SPI_STATE_READY;

    if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
    {
      /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->ErrorCallback(hspi);
#else
      HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
      return;
    }
  }
  /* Call user TxRx complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->TxRxCpltCallback(hspi);
#else
  HAL_SPI_TxRxCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
}

static void SPI_DMATransmitReceiveTxCplt(DMA_HandleTypeDef *hdma)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hdma);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_RxCpltCallback should be implemented in the user file
   */
}

/**
  * @brief  DMA SPI communication error callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *               the configuration information for the specified DMA module.
  */
static void SPI_DMAError(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */

  /* Stop the disable DMA transfer on SPI side */
  CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE | SPI_DMACR_RDMAE);

  SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_DMA);
  hspi->State = HAL_SPI_STATE_READY;

  /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->ErrorCallback(hspi);
#else
  HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SPI communication abort callback, when initiated by HAL services on Error
  *         (To be called at end of DMA Abort procedure following error occurrence).
  * @param  hdma DMA handle.
  */
static void SPI_DMAAbortOnError(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */
  hspi->RxXferCount = 0U;
  hspi->TxXferCount = 0U;

  /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->ErrorCallback(hspi);
#else
  HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SPI Tx communication abort callback, when initiated by user
  *         (To be called at end of DMA Tx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Rx DMA Handle.
  * @param  hdma DMA handle.
  */
static void SPI_DMATxAbortCallback(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */

  hspi->hdmatx->XferAbortCallback = NULL;

  /* Disable Tx DMA Request */
  CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_TDMAE);

  if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  /* Disable SPI Peripheral */
  __HAL_SPI_DISABLE(hspi);

  /* Empty the FRLVL fifo */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_TFE, SET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  /* Check if an Abort process is still ongoing */
  if (hspi->hdmarx != NULL)
  {
    if (hspi->hdmarx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA Stream/Channel are aborted, call user Abort Complete callback */
  hspi->RxXferCount = 0U;
  hspi->TxXferCount = 0U;

  /* Check no error during Abort procedure */
  if (hspi->ErrorCode != HAL_SPI_ERROR_ABORT)
  {
    /* Reset errorCode */
    hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  }

  /* Clear the Error flags in the SR register */
  __HAL_SPI_CLEAR_TXOICR(hspi);

  /* Restore hspi->State to Ready */
  hspi->State  = HAL_SPI_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->AbortCpltCallback(hspi);
#else
  HAL_SPI_AbortCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA SPI Rx communication abort callback, when initiated by user
  *         (To be called at end of DMA Rx Abort procedure following user abort request).
  * @note   When this callback is executed, User Abort complete call back is called only if no
  *         Abort still ongoing for Tx DMA Handle.
  * @param  hdma DMA handle.
  */
static void SPI_DMARxAbortCallback(DMA_HandleTypeDef *hdma)
{
  SPI_HandleTypeDef *hspi = (SPI_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent); /* Derogation MISRAC2012-Rule-11.5 */

  /* Disable SPI Peripheral */
  __HAL_SPI_DISABLE(hspi);

  hspi->hdmarx->XferAbortCallback = NULL;

  /* Disable Rx DMA Request */
  CLEAR_BIT(hspi->Instance->DMACR, SPI_DMACR_RDMAE);

  /* Control the BSY flag */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_BUSY, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  /* Empty the FRLVL fifo */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_RFNE, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  /* Check if an Abort process is still ongoing */
  if (hspi->hdmatx != NULL)
  {
    if (hspi->hdmatx->XferAbortCallback != NULL)
    {
      return;
    }
  }

  /* No Abort process still ongoing : All DMA Stream/Channel are aborted, call user Abort Complete callback */
  hspi->RxXferCount = 0U;
  hspi->TxXferCount = 0U;

  /* Check no error during Abort procedure */
  if (hspi->ErrorCode != HAL_SPI_ERROR_ABORT)
  {
    /* Reset errorCode */
    hspi->ErrorCode = HAL_SPI_ERROR_NONE;
  }

  /* Clear the Error flags in the SR register */
  __HAL_SPI_CLEAR_RXUICR(hspi);

  /* Restore hspi->State to Ready */
  hspi->State  = HAL_SPI_STATE_READY;

  /* Call user Abort complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
  hspi->AbortCpltCallback(hspi);
#else
  HAL_SPI_AbortCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
}

/**
  * @brief  Rx 8-bit handler for Transmit and Receive in Interrupt mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_2linesRxISR_8BIT(struct __SPI_HandleTypeDef *hspi)
{
   uint32_t mask = hspi->Instance->IMR;	
	
	 __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);
//  /* Receive data in packing mode */
//  if (hspi->RxXferCount > 1U)
//  {
//    *((uint16_t *)hspi->pRxBuffPtr) = (uint16_t)(hspi->Instance->DR);
//    hspi->pRxBuffPtr += sizeof(uint16_t);
//    hspi->RxXferCount -= 2U;
//    if (hspi->RxXferCount == 1U)
//    {
//      /* Set RX Fifo threshold according the reception data length: 8bit */
//      SET_BIT(hspi->Instance->RXFTLR, SPI_FRLVL_HALF_FULL);
//    }
//  }
//  /* Receive data in 8 Bit mode */
//  else
  {
		while((__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE)) && (hspi->RxXferCount > hspi->Instance->RXFTLR))
		{
			*hspi->pRxBuffPtr = *((__IO uint8_t *)&hspi->Instance->DR);
			hspi->pRxBuffPtr++;
			hspi->RxXferCount--;
		}
  }

  /* Check end of the reception */
  if (hspi->RxXferCount <= hspi->Instance->RXFTLR)
  {
		uint32_t tickstart = HAL_GetTick();
		while(hspi->RxXferCount > 0)
		{
      if(__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE))
		  {
			  *hspi->pRxBuffPtr = *((__IO uint8_t *)&hspi->Instance->DR);
			  hspi->pRxBuffPtr++;
			  hspi->RxXferCount--;
		  }
      if ((HAL_GetTick() - tickstart) >=  HAL_MAX_DELAY) 
      {
        hspi->ErrorCode |= HAL_SPI_ERROR_TIMEOUT;
        break;
      }
		}
		
    /* Disable RXNE  and ERR interrupt */
		mask &= (~(SPI_IT_RXF | SPI_IT_RXO | SPI_IT_RXU));
    __HAL_SPI_UNMASK_IT(hspi, mask);

    if (hspi->TxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
	else
	{
		__HAL_SPI_UNMASK_IT(hspi, mask);
	}
}

/**
  * @brief  Tx 8-bit handler for Transmit and Receive in Interrupt mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_2linesTxISR_8BIT(struct __SPI_HandleTypeDef *hspi)
{
   uint32_t mask = hspi->Instance->IMR;	
	
	 __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);
  /* Transmit data in packing Bit mode */
//  if (hspi->TxXferCount >= 2U)
//  {
//    hspi->Instance->DR = *((uint16_t *)hspi->pTxBuffPtr);
//    hspi->pTxBuffPtr += sizeof(uint16_t);
//    hspi->TxXferCount -= 2U;
//  }
//  /* Transmit data in 8 Bit mode */
//  else
  {
		while((__HAL_SPI_GET_STATUS(hspi, SPI_SR_TFNF)) && (hspi->TxXferCount > 0))
		{
			*(__IO uint8_t *)&hspi->Instance->DR = (*hspi->pTxBuffPtr);
			hspi->pTxBuffPtr++;
			hspi->TxXferCount--;
		}
  }

  /* Check the end of the transmission */
  if (hspi->TxXferCount == 0U)
  {
    /* Disable TXE interrupt */
		mask &= (~(SPI_IT_TXE | SPI_IT_TXO));
    __HAL_SPI_UNMASK_IT(hspi, mask);

    if (hspi->RxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
	else
	{
		__HAL_SPI_UNMASK_IT(hspi, mask);
	}
}

/**
  * @brief  Rx 16-bit handler for Transmit and Receive in Interrupt mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_2linesRxISR_16BIT(struct __SPI_HandleTypeDef *hspi)
{
   uint32_t mask = hspi->Instance->IMR;	
	uint16_t temp;
	
	 __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);
  /* Receive data in 16 Bit mode */
	while((__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE)) && (hspi->RxXferCount > hspi->Instance->RXFTLR))
	{
		temp = (uint16_t)(hspi->Instance->DR);
		*((uint8_t *)hspi->pRxBuffPtr) = (uint8_t)(temp & 0xFF);
		*((uint8_t *)(hspi->pRxBuffPtr+1)) = (uint8_t)((temp>>8) & 0xFF);
		hspi->pRxBuffPtr += sizeof(uint16_t);
		hspi->RxXferCount -= sizeof(uint16_t);
	}

  if (hspi->RxXferCount <= hspi->Instance->RXFTLR)
  {
		uint32_t tickstart = HAL_GetTick();
		while(hspi->RxXferCount > 0)
		{
      if(__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE))
		  {
			temp = (uint16_t)(hspi->Instance->DR);
			*((uint8_t *)hspi->pRxBuffPtr) = (uint8_t)(temp & 0xFF);
			*((uint8_t *)(hspi->pRxBuffPtr+1)) = (uint8_t)((temp>>8) & 0xFF);
			hspi->pRxBuffPtr += sizeof(uint16_t);
			hspi->RxXferCount -= sizeof(uint16_t);
		  }
      if ((HAL_GetTick() - tickstart) >=  HAL_MAX_DELAY) 
      {
        hspi->ErrorCode |= HAL_SPI_ERROR_TIMEOUT;
        break;
      }
		}

    /* Disable RXNE interrupt */
		mask &= (~(SPI_IT_RXF | SPI_IT_RXU | SPI_IT_RXO));
    __HAL_SPI_UNMASK_IT(hspi, mask);

    if (hspi->TxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
	else
	{
		__HAL_SPI_UNMASK_IT(hspi, mask);
	}
}

/**
  * @brief  Tx 16-bit handler for Transmit and Receive in Interrupt mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_2linesTxISR_16BIT(struct __SPI_HandleTypeDef *hspi)
{
   uint32_t mask = hspi->Instance->IMR;	
	uint16_t temp;
	
	 __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);
  /* Transmit data in 16 Bit mode */
	while((__HAL_SPI_GET_STATUS(hspi, SPI_SR_TFNF)) && (hspi->TxXferCount > 0))
	{
		temp = *((uint16_t *)(hspi->pTxBuffPtr+1));
		temp <<= 8;
		temp += *((uint16_t *)hspi->pTxBuffPtr);
		hspi->Instance->DR = temp;
		hspi->pTxBuffPtr += sizeof(uint16_t);
		hspi->TxXferCount -= sizeof(uint16_t);
	}

  /* Enable CRC Transmission */
  if (hspi->TxXferCount == 0U)
  {
    /* Disable TXE interrupt */
		mask &= (~(SPI_IT_TXE | SPI_IT_TXO));
    __HAL_SPI_UNMASK_IT(hspi, mask);

    if (hspi->RxXferCount == 0U)
    {
      SPI_CloseRxTx_ISR(hspi);
    }
  }
	else
	{
		__HAL_SPI_UNMASK_IT(hspi, mask);
	}
}

/**
  * @brief  Manage the receive 8-bit in Interrupt context.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_RxISR_8BIT(struct __SPI_HandleTypeDef *hspi)
{
   uint32_t mask = hspi->Instance->IMR;	
	
	 __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);
	
	while((__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE)) && (hspi->RxXferCount > hspi->Instance->RXFTLR)) 
	{
		*hspi->pRxBuffPtr = (*(__IO uint8_t *)&hspi->Instance->DR);
		hspi->pRxBuffPtr++;
		hspi->RxXferCount--;
	}

  if (hspi->RxXferCount <= hspi->Instance->RXFTLR)
  {
		uint32_t tickstart = HAL_GetTick();
		while(hspi->RxXferCount > 0)
		{
      if(__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE))
		  {
			  *hspi->pRxBuffPtr = *((__IO uint8_t *)&hspi->Instance->DR);
			  hspi->pRxBuffPtr++;
			  hspi->RxXferCount--;
		  }
      if ((HAL_GetTick() - tickstart) >=  HAL_MAX_DELAY) 
      {
        hspi->ErrorCode |= HAL_SPI_ERROR_TIMEOUT;
        break;
      }
		}
	  mask &= (~(SPI_IT_RXF | SPI_IT_RXO | SPI_IT_RXU));
		__HAL_SPI_UNMASK_IT(hspi, mask);

    SPI_CloseRx_ISR(hspi);
  }
	else
	{
		__HAL_SPI_UNMASK_IT(hspi, mask);
	}
}

/**
  * @brief  Manage the 16-bit receive in Interrupt context.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_RxISR_16BIT(struct __SPI_HandleTypeDef *hspi)
{
   uint32_t mask = hspi->Instance->IMR;	
	uint16_t temp = 0;
	
	 __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);

	while((__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE)) && (hspi->RxXferCount > hspi->Instance->RXFTLR))
	{
		temp = (uint16_t)(hspi->Instance->DR);
		*((uint8_t *)hspi->pRxBuffPtr) = (uint8_t)(temp & 0xFF);
		*((uint8_t *)(hspi->pRxBuffPtr+1)) = (uint8_t)((temp >> 8) & 0xFF);
		hspi->pRxBuffPtr += sizeof(uint16_t);
		hspi->RxXferCount -= sizeof(uint16_t);
	}

  if (hspi->RxXferCount <= hspi->Instance->RXFTLR)
  {
		uint32_t tickstart = HAL_GetTick();
		while(hspi->RxXferCount > 0)
		{
      if(__HAL_SPI_GET_STATUS(hspi, SPI_SR_RFNE))
		  {
		temp = (uint16_t)(hspi->Instance->DR);
		*((uint8_t *)hspi->pRxBuffPtr) = (uint8_t)(temp & 0xFF);
		*((uint8_t *)(hspi->pRxBuffPtr+1)) = (uint8_t)((temp >> 8) & 0xFF);
		hspi->pRxBuffPtr += sizeof(uint16_t);
		hspi->RxXferCount -= sizeof(uint16_t);
		  }
      if ((HAL_GetTick() - tickstart) >=  HAL_MAX_DELAY) 
      {
        hspi->ErrorCode |= HAL_SPI_ERROR_TIMEOUT;
        break;
      }
		}

	  
		mask &= (~(SPI_IT_RXF | SPI_IT_RXO | SPI_IT_RXU));
		__HAL_SPI_UNMASK_IT(hspi, mask);

    SPI_CloseRx_ISR(hspi);
  }
	else
	{
	  __HAL_SPI_UNMASK_IT(hspi, mask);
	}
}

/**
  * @brief  Handle the data 8-bit transmit in Interrupt mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_TxISR_8BIT(struct __SPI_HandleTypeDef *hspi)
{
   uint32_t mask = hspi->Instance->IMR;	
	
	 __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);

	while((__HAL_SPI_GET_STATUS(hspi, SPI_SR_TFNF)) && (hspi->TxXferCount > 0))
	{
		*(__IO uint8_t *)&hspi->Instance->DR = (*hspi->pTxBuffPtr);
		hspi->pTxBuffPtr++;
		hspi->TxXferCount--;
	}

  if (hspi->TxXferCount == 0U)
  {
	  mask &= (~(SPI_IT_TXE | SPI_IT_TXO));
		__HAL_SPI_UNMASK_IT(hspi, mask);

    SPI_CloseTx_ISR(hspi);
  }
	else
	{
	  __HAL_SPI_UNMASK_IT(hspi, mask);
	}
}

/**
  * @brief  Handle the data 16-bit transmit in Interrupt mode.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_TxISR_16BIT(struct __SPI_HandleTypeDef *hspi)
{
   uint32_t mask = hspi->Instance->IMR;	
	uint16_t temp =0;
	
	 __HAL_SPI_MASK_IT(hspi, SPI_IT_ALL);

  /* Transmit data in 16 Bit mode */
	while((__HAL_SPI_GET_STATUS(hspi, SPI_SR_TFNF)) && (hspi->TxXferCount > 0))
	{
		temp = *((uint16_t *)(hspi->pTxBuffPtr+1));
		temp <<= 8;
		temp += *((uint16_t *)hspi->pTxBuffPtr);
		*((__IO uint16_t *)&hspi->Instance->DR) = temp;
		hspi->pTxBuffPtr += sizeof(uint16_t);
		hspi->TxXferCount -= sizeof(uint16_t);
	}

  if (hspi->TxXferCount == 0U)
  {
	  mask &= (~(SPI_IT_TXE | SPI_IT_TXO));
		__HAL_SPI_UNMASK_IT(hspi, mask);
    SPI_CloseTx_ISR(hspi);
  }
  else
	{
	  __HAL_SPI_UNMASK_IT(hspi, mask);
	}
}

/**
  * @brief  Handle SPI timeout for status.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *              the configuration information for SPI module.
  * @param  Status status
  * @param  Expert expert status
  * @param  Timeout Timeout duration
  * @param  Tickstart tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef SPI_WaitStatusUntilTimeout(SPI_HandleTypeDef *hspi, uint32_t Status, uint32_t Expert,
                                                       uint32_t Timeout, uint32_t Tickstart)
{
  __IO uint32_t count;
  uint32_t tmp_timeout;
  uint32_t tmp_tickstart;

  /* Adjust Timeout value  in case of end of transfer */
  tmp_timeout = Timeout - (HAL_GetTick() - Tickstart);
  tmp_tickstart = HAL_GetTick();

  /* Calculate Timeout based on a software loop to avoid blocking issue if Systick is disabled */
  count = tmp_timeout * ((SystemCoreClock * 35U) >> 20U);

  while (((hspi->Instance->SR & Status) ? SET : RESET)!= Expert)
  {
    if(READ_BIT(hspi->Instance->CTRLR0, SPI_CTRLR0_TMOD) != SPI_DIRECTION_2LINES_TXONLY)
    {
      uint16_t dr = READ_REG(hspi->Instance->DR);
      UNUSED(dr);
    }
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tmp_tickstart) >= tmp_timeout) || (tmp_timeout == 0U))
      {
        /* Disable TXE, RXNE and ERR interrupts for the interrupt process */
        __HAL_SPI_MASK_IT(hspi, (SPI_IT_TXE | SPI_IT_RXF | SPI_IT_TXO | SPI_IT_RXO | SPI_IT_RXU));

        /* Disable SPI peripheral */
        __HAL_SPI_DISABLE(hspi);

        hspi->State = HAL_SPI_STATE_READY;

        /* Process Unlocked */
        __HAL_UNLOCK(hspi);

        return HAL_TIMEOUT;
      }
      /* If Systick is disabled or not incremented, deactivate timeout to go in disable loop procedure */
      if(count == 0U)
      {
        tmp_timeout = 0U;
      }      
      count--;
    }
  }

  return HAL_OK;
}

/**
  * @brief  Handle the check of the RX transaction complete.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  * @param  Timeout Timeout duration
  * @param  Tickstart tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef SPI_EndRxTransaction(SPI_HandleTypeDef *hspi,  uint32_t Timeout, uint32_t Tickstart)
{
  if ((__HAL_SPI_IS_MASTER(hspi)) && ((hspi->Init.Direction == SPI_DIRECTION_2LINES_RXONLY)))
  {
    /* Disable SPI peripheral */
    __HAL_SPI_DISABLE(hspi);
  }

  /* Control the BSY flag */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_BUSY, RESET, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
    return HAL_TIMEOUT;
  }

  if (hspi->Init.Direction != SPI_DIRECTION_2LINES_TXONLY)
  {
    /* Empty the FRLVL fifo */
    if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_RFNE, RESET, Timeout, Tickstart) != HAL_OK)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
      return HAL_TIMEOUT;
    }
  }
  return HAL_OK;
}

/**
  * @brief  Handle the check of the RXTX or TX transaction complete.
  * @param  hspi SPI handle
  * @param  Timeout Timeout duration
  * @param  Tickstart tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef SPI_EndRxTxTransaction(SPI_HandleTypeDef *hspi, uint32_t Timeout, uint32_t Tickstart)
{
  /* Control if the TX fifo is empty */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_TFE, SET, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_STAUS);
    return HAL_TIMEOUT;
  }

  /* Control the BSY flag */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_BUSY, RESET, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_STAUS);
    return HAL_TIMEOUT;
  }

  /* Control if the RX fifo is empty */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_RFNE, RESET, Timeout, Tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_STAUS);
    return HAL_TIMEOUT;
  }

  return HAL_OK;
}

/**
  * @brief  Handle the end of the RXTX transaction.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_CloseRxTx_ISR(SPI_HandleTypeDef *hspi)
{
  uint32_t tickstart;

  /* Init tickstart for timeout management */
  tickstart = HAL_GetTick();

  /* Disable ERR interrupt */
  __HAL_SPI_MASK_IT(hspi, (SPI_IT_TXO | SPI_IT_RXO | SPI_IT_RXU));

  /* Check the end of the transaction */
  if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
  }

  if (hspi->ErrorCode == HAL_SPI_ERROR_NONE)
  {
    if (hspi->State == HAL_SPI_STATE_BUSY_RX)
    {
      hspi->State = HAL_SPI_STATE_READY;
      /* Call user Rx complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->RxCpltCallback(hspi);
#else
      HAL_SPI_RxCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
    }
    else
    {
      hspi->State = HAL_SPI_STATE_READY;
      /* Call user TxRx complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
      hspi->TxRxCpltCallback(hspi);
#else
      HAL_SPI_TxRxCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
    }
  }
  else
  {
    hspi->State = HAL_SPI_STATE_READY;
    /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->ErrorCallback(hspi);
#else
    HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
  }
}

/**
  * @brief  Handle the end of the RX transaction.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_CloseRx_ISR(SPI_HandleTypeDef *hspi)
{
  /* Disable RXNE and ERR interrupt */
  __HAL_SPI_MASK_IT(hspi, (SPI_IT_RXF | SPI_IT_RXU | SPI_IT_RXO));

  /* Check the end of the transaction */
  if (SPI_EndRxTransaction(hspi, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
  }
  hspi->State = HAL_SPI_STATE_READY;

  if (hspi->ErrorCode == HAL_SPI_ERROR_NONE)
  {
    /* Call user Rx complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->RxCpltCallback(hspi);
#else
    HAL_SPI_RxCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
  }
  else
  {
    /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->ErrorCallback(hspi);
#else
    HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
  }
}

/**
  * @brief  Handle the end of the TX transaction.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_CloseTx_ISR(SPI_HandleTypeDef *hspi)
{
  uint32_t tickstart;

  /* Init tickstart for timeout management*/
  tickstart = HAL_GetTick();

  /* Disable TXE and ERR interrupt */
  __HAL_SPI_MASK_IT(hspi, (SPI_IT_TXE | SPI_IT_TXO));

  /* Check the end of the transaction */
  if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, tickstart) != HAL_OK)
  {
    SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_FLAG);
  }

  /* Clear overrun flag in 2 Lines communication mode because received is not read */
  if (hspi->Init.Direction == SPI_DIRECTION_2LINES)
  {
//    __HAL_SPI_CLEAR_OVRFLAG(hspi);
  }

  hspi->State = HAL_SPI_STATE_READY;
  if (hspi->ErrorCode != HAL_SPI_ERROR_NONE)
  {
    /* Call user error callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->ErrorCallback(hspi);
#else
    HAL_SPI_ErrorCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
  }
  else
  {
    /* Call user Rx complete callback */
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
    hspi->TxCpltCallback(hspi);
#else
    HAL_SPI_TxCpltCallback(hspi);
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
  }
}

/**
  * @brief  Handle abort a Rx transaction.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_AbortRx_ISR(SPI_HandleTypeDef *hspi)
{
  __IO uint32_t count;

  /* Disable SPI Peripheral */
  __HAL_SPI_DISABLE(hspi);

  count = SPI_DEFAULT_TIMEOUT * (SystemCoreClock / 24U / 1000U);

  /* Disable RXNEIE interrupt */
  __HAL_SPI_MASK_IT(hspi, (SPI_IT_RXF));

  /* Check RXNEIE is disabled */
  do
  {
    if (count == 0U)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
      break;
    }
    count--;
  } while (SPI_CHECK_IT(hspi->Instance->ISR, SPI_IT_RXF));

  /* Control the BSY flag */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_BUSY, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  /* Empty the FRLVL fifo */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_RFNE, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  hspi->State = HAL_SPI_STATE_ABORT;
}

/**
  * @brief  Handle abort a Tx or Rx/Tx transaction.
  * @param  hspi pointer to a SPI_HandleTypeDef structure that contains
  *               the configuration information for SPI module.
  */
static void SPI_AbortTx_ISR(SPI_HandleTypeDef *hspi)
{
  __IO uint32_t count;

  count = SPI_DEFAULT_TIMEOUT * (SystemCoreClock / 24U / 1000U);

  /* Disable TXEIE interrupt */
  __HAL_SPI_MASK_IT(hspi, (SPI_IT_TXE));

  /* Check TXEIE is disabled */
  do
  {
    if (count == 0U)
    {
      SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
      break;
    }
    count--;
  } while (__HAL_SPI_GET_IT(hspi, SPI_IT_TXE));

  if (SPI_EndRxTxTransaction(hspi, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  /* Disable SPI Peripheral */
  __HAL_SPI_DISABLE(hspi);

  /* Empty the FRLVL fifo */
  if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_TFE, SET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
  {
    hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
  }

  /* Check case of Full-Duplex Mode and disable directly RXNEIE interrupt */
  if (__HAL_SPI_GET_IT(hspi, SPI_IT_RXF))
  {
    /* Disable RXNEIE interrupt */
    __HAL_SPI_MASK_IT(hspi, (SPI_IT_RXF));

    /* Check RXNEIE is disabled */
    do
    {
      if (count == 0U)
      {
        SET_BIT(hspi->ErrorCode, HAL_SPI_ERROR_ABORT);
        break;
      }
      count--;
    } while (__HAL_SPI_GET_IT(hspi, SPI_IT_RXF));

    /* Control the BSY flag */
    if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_BUSY, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
    {
      hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
    }

    /* Empty the FRLVL fifo */
    if (SPI_WaitStatusUntilTimeout(hspi, SPI_STATUS_RFNE, RESET, SPI_DEFAULT_TIMEOUT, HAL_GetTick()) != HAL_OK)
    {
      hspi->ErrorCode = HAL_SPI_ERROR_ABORT;
    }
  }
  hspi->State = HAL_SPI_STATE_ABORT;
}

/**
  * @}
  */

#endif /* HAL_SPI_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
