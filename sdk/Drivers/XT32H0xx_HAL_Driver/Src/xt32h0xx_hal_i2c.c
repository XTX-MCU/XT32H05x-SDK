/**
  ******************************************************************************
  * @file    xt32h0xx_hal_i2c.c
  * @author  Software Team
  * @brief   I2C HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Inter Integrated Circuit (I2C) peripheral:
  *           + Initialization and de-initialization functions
  *           + IO operation functions
  *           + Peripheral State and Errors functions
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

/** @defgroup I2C I2C
  * @brief I2C HAL module driver
  * @{
  */

#ifdef HAL_I2C_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/** @defgroup I2C_Private_Constants I2C Private Constants
  * @{
  */
#define TIMING_CLEAR_MASK   (0xF0FFFFFFU)  /*!< I2C TIMING clear register Mask */
//#define I2C_TIMEOUT_ADDR    (10000U)       /*!< 10 s  */
#define I2C_TIMEOUT_BUSY    (25U)          /*!< 25 ms */
#define I2C_TIMEOUT_DIR     (25U)          /*!< 25 ms */
#define I2C_TIMEOUT_RXNE    (25U)          /*!< 25 ms */
#define I2C_TIMEOUT_STOPF   (25U)          /*!< 25 ms */
#define I2C_TIMEOUT_TC      (25U)          /*!< 25 ms */
#define I2C_TIMEOUT_TCR     (25U)          /*!< 25 ms */
#define I2C_TIMEOUT_TXIS    (25U)          /*!< 25 ms */
#define I2C_TIMEOUT_FLAG    (25U)          /*!< 25 ms */

#define MAX_NBYTE_SIZE      255U

/* Private define for @ref PreviousState usage */
#define I2C_STATE_MSK             ((uint32_t)((uint32_t)((uint32_t)HAL_I2C_STATE_BUSY_TX | \
                                                         (uint32_t)HAL_I2C_STATE_BUSY_RX) & \
                                              (uint32_t)(~((uint32_t)HAL_I2C_STATE_READY))))
/*!< Mask State define, keep only RX and TX bits */
#define I2C_STATE_NONE            ((uint32_t)(HAL_I2C_MODE_NONE))
/*!< Default Value */
#define I2C_STATE_MASTER_BUSY_TX  ((uint32_t)(((uint32_t)HAL_I2C_STATE_BUSY_TX & I2C_STATE_MSK) | \
                                              (uint32_t)HAL_I2C_MODE_MASTER))
/*!< Master Busy TX, combinaison of State LSB and Mode enum */
#define I2C_STATE_MASTER_BUSY_RX  ((uint32_t)(((uint32_t)HAL_I2C_STATE_BUSY_RX & I2C_STATE_MSK) | \
                                              (uint32_t)HAL_I2C_MODE_MASTER))
/*!< Master Busy RX, combinaison of State LSB and Mode enum */
#define I2C_STATE_SLAVE_BUSY_TX   ((uint32_t)(((uint32_t)HAL_I2C_STATE_BUSY_TX & I2C_STATE_MSK) | \
                                              (uint32_t)HAL_I2C_MODE_SLAVE))
/*!< Slave Busy TX, combinaison of State LSB and Mode enum */
#define I2C_STATE_SLAVE_BUSY_RX   ((uint32_t)(((uint32_t)HAL_I2C_STATE_BUSY_RX & I2C_STATE_MSK) | \
                                              (uint32_t)HAL_I2C_MODE_SLAVE))
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup I2C_Private_Macro I2C Private Macros
  * @{
  */

#define IS_I2C_ADDRESSING_MODE(MODE)    (((MODE) == I2C_ADDRESSINGMODE_7BIT) || \
                                         ((MODE) == I2C_ADDRESSINGMODE_10BIT))

#define I2C_CHECK_ABRT_SOURCE(__ABRT__, __SOURCE__)        ((((__ABRT__) & (__SOURCE__)) == (__SOURCE__)) ? SET : RESET)
#define I2C_CHECK_STATUS(__ICSTATUS__, __STATUS__)         ((((__ICSTATUS__) & (__STATUS__)) == (__STATUS__)) ? SET : RESET)
#define I2C_CHECK_FLAG(__RISR__, __FLAG__)                 ((((__RISR__) & (__FLAG__)) == (__FLAG__)) ? SET : RESET)
#define I2C_CHECK_IT(__ISR__, __IT__)                      ((((__ISR__) & (__IT__)) == (__IT__)) ? SET : RESET)
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/** @defgroup I2C_Private_Functions I2C Private Functions
  * @{
  */
/* Private functions to handle DMA transfer */
static void I2C_DMAMasterTransmitCplt(DMA_HandleTypeDef *hdma);
static void I2C_DMAMasterReceiveCplt(DMA_HandleTypeDef *hdma);
static void I2C_DMASlaveTransmitCplt(DMA_HandleTypeDef *hdma);
static void I2C_DMASlaveReceiveCplt(DMA_HandleTypeDef *hdma);
static void I2C_DMAMasterTransmitDstTran(DMA_HandleTypeDef *hdma);
static void I2C_DMAMasterReceiveSrcTran(DMA_HandleTypeDef *hdma);
static void I2C_DMASlaveTransmitDstTran(DMA_HandleTypeDef *hdma);
static void I2C_DMASlaveReceiveSrcTran(DMA_HandleTypeDef *hdma);
static void I2C_DMAError(DMA_HandleTypeDef *hdma);
static void I2C_DMAAbort(DMA_HandleTypeDef *hdma);

/* Private functions to handle IT transfer */
static void I2C_ITMasterCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
static void I2C_ITSlaveCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
static void I2C_ITSlaveGeneralCall(I2C_HandleTypeDef *hi2c);
static void I2C_ITError(I2C_HandleTypeDef *hi2c, uint32_t ErrorCode);

/* Private functions for I2C transfer IRQ handler */
HAL_StatusTypeDef I2C_Master_ISR_IT(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
HAL_StatusTypeDef I2C_Slave_ISR_IT(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
static HAL_StatusTypeDef I2C_Master_ISR_DMA(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags);
static HAL_StatusTypeDef I2C_Slave_ISR_DMA(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags);

/* Private functions to handle flags during polling transfer */
static HAL_StatusTypeDef I2C_WaitOnFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Flag, FlagStatus Status,
                                                    uint32_t Timeout, uint32_t Tickstart);
static HAL_StatusTypeDef I2C_WaitOnStatusUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Flag, FlagStatus Status,
                                                    uint32_t Timeout, uint32_t Tickstart);

/* Private functions to centralize the enable/disable of Interrupts */
static void I2C_Enable_IRQ(I2C_HandleTypeDef *hi2c, uint16_t InterruptRequest);
static void I2C_Disable_IRQ(I2C_HandleTypeDef *hi2c, uint16_t InterruptRequest);

/* Private function to treat different error callback */
static void I2C_TreatErrorCallback(I2C_HandleTypeDef *hi2c);

/* Private function to process Tx abort source */
static void I2C_Tx_Abort_ISR(I2C_HandleTypeDef *hi2c);

static HAL_StatusTypeDef I2C_CheckTimeout(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup I2C_Exported_Functions I2C Exported Functions
  * @{
  */

/** @defgroup I2C_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  * @{
  */

/**
  * @brief  Initializes the I2C according to the specified parameters
  *         in the I2C_InitTypeDef and initialize the associated handle.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c)
{
  /* Check the I2C handle allocation */
  if (hi2c == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));
  assert_param(IS_I2C_ADDRESSING_MODE(hi2c->Init.AddressingMode));

  if (hi2c->State == HAL_I2C_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    hi2c->Lock = HAL_UNLOCKED;

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
    /* Init the I2C Callback settings */
    hi2c->MasterTxCpltCallback = HAL_I2C_MasterTxCpltCallback; /* Legacy weak MasterTxCpltCallback */
    hi2c->MasterRxCpltCallback = HAL_I2C_MasterRxCpltCallback; /* Legacy weak MasterRxCpltCallback */
    hi2c->SlaveTxCpltCallback  = HAL_I2C_SlaveTxCpltCallback;  /* Legacy weak SlaveTxCpltCallback  */
    hi2c->SlaveRxCpltCallback  = HAL_I2C_SlaveRxCpltCallback;  /* Legacy weak SlaveRxCpltCallback  */
    hi2c->SlaveGeneralCallCallback   = HAL_I2C_SlaveGeneralCallCallback;   /* Legacy weak SlaveGeneralCallCallback  */
    hi2c->ErrorCallback        = HAL_I2C_ErrorCallback;        /* Legacy weak ErrorCallback        */
    hi2c->AbortCpltCallback    = HAL_I2C_AbortCpltCallback;    /* Legacy weak AbortCpltCallback    */
    hi2c->TxAbortCallback      = HAL_I2C_TxAbortCallback;      /* Legacy weak TxAbortCallback      */

    if (hi2c->MspInitCallback == NULL)
    {
      hi2c->MspInitCallback = HAL_I2C_MspInit; /* Legacy weak MspInit  */
    }

    /* Init the low level hardware : GPIO, CLOCK, CORTEX...etc */
    hi2c->MspInitCallback(hi2c);
#else
    /* Init the low level hardware : GPIO, CLOCK, CORTEX...etc */
    HAL_I2C_MspInit(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
  }

  hi2c->State = HAL_I2C_STATE_BUSY;

  /* Disable the selected I2C peripheral */
  __HAL_I2C_DISABLE(hi2c);

  /*---------------------------- I2Cx SPEED Configuration ------------------*/
  /* Configure I2Cx: Frequency range */
  MODIFY_REG(hi2c->Instance->CON, I2C_CON_SPEED,  hi2c->Init.Speed);

  /*---------------------------- I2Cx Configuration -------------------------*/

  /* Configure I2Cx: Slave addressing mode */
  MODIFY_REG(hi2c->Instance->CON, I2C_CON_10ASLV, hi2c->Init.AddressingMode << I2C_CON_10ASLV_Pos);

  /* Configure I2Cx: Addressing Master mode */
  MODIFY_REG(hi2c->Instance->CON, I2C_CON_10AMST, hi2c->Init.AddressingMode << I2C_CON_10AMST_Pos);

  /* Configure I2Cx: STOP_DET interrupt when it is addressed in slave mode */
  CLEAR_BIT(hi2c->Instance->CON, I2C_CON_STOPDETIFA);

  /* Configure I2Cx: Restart enable in master mode */
  SET_BIT(hi2c->Instance->CON, I2C_CON_RESTARTEN);
	
  I2C_Config_Clock(hi2c, hi2c->Init.Baudrate);

	hi2c->Instance->INTRMASK = 0;

  /*---------------------------- I2Cx ACK_GENERAL_CALL Configuration ----------------------*/
  /* Configure I2Cx: Response ACK for General Call */
  SET_BIT(hi2c->Instance->ACKGENERALCALL, I2C_GCACK_ACK);

  hi2c->ErrorCode = HAL_I2C_ERROR_NONE;
  hi2c->State = HAL_I2C_STATE_READY;
  hi2c->PreviousState = I2C_STATE_NONE;
  hi2c->Mode = HAL_I2C_MODE_NONE;

	if(hi2c->Instance == I2C1)
	{
		CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_I2C1_MASK);
		SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_I2C1_MASK);
		/* config sim */
		CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_I2C1_MASK);
	}
	else
	{
		CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_I2C2_MASK);
		SET_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_I2C2_MASK);
		/* config sim */
		CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQCFG_I2C2_MASK);
	}

  /* Enable the selected I2C peripheral */
  __HAL_I2C_ENABLE(hi2c);
  
  return HAL_OK;
}

/**
  * @brief  DeInitialize the I2C peripheral.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c)
{
  /* Check the I2C handle allocation */
  if (hi2c == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_I2C_ALL_INSTANCE(hi2c->Instance));

  hi2c->State = HAL_I2C_STATE_BUSY;

  /* Disable the I2C Peripheral Clock */
  __HAL_I2C_DISABLE(hi2c);

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
  if (hi2c->MspDeInitCallback == NULL)
  {
    hi2c->MspDeInitCallback = HAL_I2C_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware: GPIO, CLOCK, NVIC */
  hi2c->MspDeInitCallback(hi2c);
#else
  /* DeInit the low level hardware: GPIO, CLOCK, NVIC */
  HAL_I2C_MspDeInit(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */

  hi2c->ErrorCode = HAL_I2C_ERROR_NONE;
  hi2c->State = HAL_I2C_STATE_RESET;
  hi2c->PreviousState = I2C_STATE_NONE;
  hi2c->Mode = HAL_I2C_MODE_NONE;

  /* Release Lock */
  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}

/**
  * @brief Initialize the I2C MSP.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_MspInit could be implemented in the user file
   */
}

/**
  * @brief DeInitialize the I2C MSP.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_MspDeInit could be implemented in the user file
   */
}

/**
  * @brief link dma with i2c.
  * @param hi2c I2C handle.
  * @param hdmarx DMA handle.
  * @param hdmatx DMA handle.
  * @param rxif DMA rx if.
  * @param txif DMA tx if.
  * @param rxifcfg rx hsif configure
  * @param txifcfg tx hsif configure
  * @retval Status
  */
HAL_StatusTypeDef HAL_I2C_DMAHSIFConfig(I2C_HandleTypeDef *hi2c, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx, uint32_t rxif, uint32_t txif, uint32_t rxifcfg, uint32_t txifcfg)
{
	uint32_t mask = 0;
	if(hi2c == NULL) return HAL_ERROR;
	
	if(hdmarx != NULL)
	{
#if defined(XT32H0xxBMPW)
		if(hi2c->Instance == I2C1)
		{
			if(rxif == 15)
			{
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_RXDA, (rxifcfg+1) << SYSCFG_SYS_CFG_I2C1_RXDA_Pos );
			}
			else
			{
				MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_RXDA, (rxifcfg) << SYSCFG_SYS_CFG_I2C1_RXDA_Pos );
			}
		}
#elif defined(XT32H0xxB)    
		if(hi2c->Instance == I2C1)
		{
			if(rxif == 1)
			{
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_RXDA, (1) << SYSCFG_SYS_CFG_I2C1_RXDA_Pos );
			}
			else if(rxif == 15)
			{
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_RXDA, (2) << SYSCFG_SYS_CFG_I2C1_RXDA_Pos );
			}
			else
			{
				MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_RXDA, (0) << SYSCFG_SYS_CFG_I2C1_RXDA_Pos );
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
		if(hi2c->Instance == I2C1)
		{
			if(txif == 14)
			{
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_TXDA, (txifcfg+1) << SYSCFG_SYS_CFG_I2C1_TXDA_Pos );
			}
			else
			{
				MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_TXDA, (txifcfg) << SYSCFG_SYS_CFG_I2C1_TXDA_Pos );
			}
		}
#elif defined(XT32H0xxB)    
		if(hi2c->Instance == I2C1)
		{
			if(txif == 0)
			{
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_TXDA, (1) << SYSCFG_SYS_CFG_I2C1_TXDA_Pos );
			}
			else if(txif == 14)
			{
			  MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_TXDA, (2) << SYSCFG_SYS_CFG_I2C1_TXDA_Pos );
			}
			else
			{
				MODIFY_REG(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_I2C1_TXDA, (0) << SYSCFG_SYS_CFG_I2C1_TXDA_Pos );
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
  * @brief Link DMA with .
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  hdmarx Pointer to RXDMA 
  * @param  hdmatx Pointer to TXDMA 
  */
HAL_StatusTypeDef HAL_I2C_LinkDMA(I2C_HandleTypeDef *hi2c, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx)
{
  if(hi2c == NULL) return HAL_ERROR;

  if(hdmarx != NULL)
  {
    hdmarx->Parent = hi2c;
    hi2c->hdmarx = hdmarx;
  }

  if(hdmatx != NULL)
  {
    hdmatx->Parent = hi2c;
    hi2c->hdmatx = hdmatx;
  }

  return HAL_OK;
}

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User I2C Callback
  *         To be used instead of the weak predefined callback
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_I2C_MASTER_TX_COMPLETE_CB_ID
  *          @arg @ref HAL_I2C_MASTER_RX_COMPLETE_CB_ID
  *          @arg @ref HAL_I2C_SLAVE_TX_COMPLETE_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_RX_COMPLETE_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_GEN_CALL_CB_ID    
  *          @arg @ref HAL_I2C_ERROR_CB_ID             
  *          @arg @ref HAL_I2C_ABORT_CB_ID             
  *          @arg @ref HAL_I2C_TXABORT_CB_ID           
  *          @arg @ref HAL_I2C_MSPINIT_CB_ID           
  *          @arg @ref HAL_I2C_MSPDEINIT_CB_ID         
  *          @arg @ref HAL_I2C_MASTER_TX_TFRCLPT_CB_ID
  *          @arg @ref HAL_I2C_MASTER_TX_BLOCK_CB_ID  
  *          @arg @ref HAL_I2C_MASTER_TX_DSTTRAN_CB_ID
  *          @arg @ref HAL_I2C_MASTER_TX_TFRERR_CB_ID 
  *          @arg @ref HAL_I2C_MASTER_TX_TFRABRT_CB_ID
  *          @arg @ref HAL_I2C_MASTER_RX_TFRCLPT_CB_ID
  *          @arg @ref HAL_I2C_MASTER_RX_BLOCK_CB_ID  
  *          @arg @ref HAL_I2C_MASTER_RX_SRCTRAN_CB_ID
  *          @arg @ref HAL_I2C_MASTER_RX_TFRERR_CB_ID 
  *          @arg @ref HAL_I2C_MASTER_RX_TFRABRT_CB_ID
  *          @arg @ref HAL_I2C_SLAVE_TX_TFRCLPT_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_TX_BLOCK_CB_ID   
  *          @arg @ref HAL_I2C_SLAVE_TX_DSTTRAN_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_TX_TFRERR_CB_ID  
  *          @arg @ref HAL_I2C_SLAVE_TX_TFRABRT_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_RX_TFRCLPT_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_RX_BLOCK_CB_ID   
  *          @arg @ref HAL_I2C_SLAVE_RX_SRCTRAN_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_RX_TFRERR_CB_ID  
  *          @arg @ref HAL_I2C_SLAVE_RX_TFRABRT_CB_ID 
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_RegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID,
                                           pI2C_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hi2c->ErrorCode |= HAL_I2C_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  /* Process locked */
  __HAL_LOCK(hi2c);

  if (HAL_I2C_STATE_READY == hi2c->State)
  {
    switch (CallbackID)
    {
      case HAL_I2C_MASTER_TX_COMPLETE_CB_ID :
        hi2c->MasterTxCpltCallback = pCallback;
        break;

      case HAL_I2C_MASTER_RX_COMPLETE_CB_ID :
        hi2c->MasterRxCpltCallback = pCallback;
        break;

      case HAL_I2C_SLAVE_TX_COMPLETE_CB_ID :
        hi2c->SlaveTxCpltCallback = pCallback;
        break;

      case HAL_I2C_SLAVE_RX_COMPLETE_CB_ID :
        hi2c->SlaveRxCpltCallback = pCallback;
        break;

      case HAL_I2C_SLAVE_GEN_CALL_CB_ID :
        hi2c->SlaveGeneralCallCallback = pCallback;
        break;

      case HAL_I2C_ERROR_CB_ID :
        hi2c->ErrorCallback = pCallback;
        break;

      case HAL_I2C_ABORT_CB_ID :
        hi2c->AbortCpltCallback = pCallback;
        break;

      case HAL_I2C_TXABORT_CB_ID :
        hi2c->TxAbortCallback = pCallback;
        break;

      case HAL_I2C_MSPINIT_CB_ID :
        hi2c->MspInitCallback = pCallback;
        break;

      case HAL_I2C_MSPDEINIT_CB_ID :
        hi2c->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hi2c->ErrorCode |= HAL_I2C_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_I2C_STATE_RESET == hi2c->State)
  {
    switch (CallbackID)
    {
      case HAL_I2C_MSPINIT_CB_ID :
        hi2c->MspInitCallback = pCallback;
        break;

      case HAL_I2C_MSPDEINIT_CB_ID :
        hi2c->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hi2c->ErrorCode |= HAL_I2C_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hi2c->ErrorCode |= HAL_I2C_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hi2c);
  return status;
}

/**
  * @brief  Unregister an I2C Callback
  *         I2C callback is redirected to the weak predefined callback
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_I2C_MASTER_TX_COMPLETE_CB_ID
  *          @arg @ref HAL_I2C_MASTER_RX_COMPLETE_CB_ID
  *          @arg @ref HAL_I2C_SLAVE_TX_COMPLETE_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_RX_COMPLETE_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_GEN_CALL_CB_ID    
  *          @arg @ref HAL_I2C_ERROR_CB_ID             
  *          @arg @ref HAL_I2C_ABORT_CB_ID             
  *          @arg @ref HAL_I2C_TXABORT_CB_ID           
  *          @arg @ref HAL_I2C_MSPINIT_CB_ID           
  *          @arg @ref HAL_I2C_MSPDEINIT_CB_ID         
  *          @arg @ref HAL_I2C_MASTER_TX_TFRCLPT_CB_ID
  *          @arg @ref HAL_I2C_MASTER_TX_BLOCK_CB_ID  
  *          @arg @ref HAL_I2C_MASTER_TX_DSTTRAN_CB_ID
  *          @arg @ref HAL_I2C_MASTER_TX_TFRERR_CB_ID 
  *          @arg @ref HAL_I2C_MASTER_TX_TFRABRT_CB_ID
  *          @arg @ref HAL_I2C_MASTER_RX_TFRCLPT_CB_ID
  *          @arg @ref HAL_I2C_MASTER_RX_BLOCK_CB_ID  
  *          @arg @ref HAL_I2C_MASTER_RX_SRCTRAN_CB_ID
  *          @arg @ref HAL_I2C_MASTER_RX_TFRERR_CB_ID 
  *          @arg @ref HAL_I2C_MASTER_RX_TFRABRT_CB_ID
  *          @arg @ref HAL_I2C_SLAVE_TX_TFRCLPT_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_TX_BLOCK_CB_ID   
  *          @arg @ref HAL_I2C_SLAVE_TX_DSTTRAN_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_TX_TFRERR_CB_ID  
  *          @arg @ref HAL_I2C_SLAVE_TX_TFRABRT_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_RX_TFRCLPT_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_RX_BLOCK_CB_ID   
  *          @arg @ref HAL_I2C_SLAVE_RX_SRCTRAN_CB_ID 
  *          @arg @ref HAL_I2C_SLAVE_RX_TFRERR_CB_ID  
  *          @arg @ref HAL_I2C_SLAVE_RX_TFRABRT_CB_ID 
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_UnRegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hi2c);

  if (HAL_I2C_STATE_READY == hi2c->State)
  {
    switch (CallbackID)
    {
      case HAL_I2C_MASTER_TX_COMPLETE_CB_ID :
        hi2c->MasterTxCpltCallback = HAL_I2C_MasterTxCpltCallback; /* Legacy weak MasterTxCpltCallback */
        break;

      case HAL_I2C_MASTER_RX_COMPLETE_CB_ID :
        hi2c->MasterRxCpltCallback = HAL_I2C_MasterRxCpltCallback; /* Legacy weak MasterRxCpltCallback */
        break;

      case HAL_I2C_SLAVE_TX_COMPLETE_CB_ID :
        hi2c->SlaveTxCpltCallback = HAL_I2C_SlaveTxCpltCallback;   /* Legacy weak SlaveTxCpltCallback  */
        break;

      case HAL_I2C_SLAVE_RX_COMPLETE_CB_ID :
        hi2c->SlaveRxCpltCallback = HAL_I2C_SlaveRxCpltCallback;   /* Legacy weak SlaveRxCpltCallback  */
        break;

      case HAL_I2C_SLAVE_GEN_CALL_CB_ID :
        hi2c->SlaveGeneralCallCallback = HAL_I2C_SlaveGeneralCallCallback;   /* Legacy weak SlaveGeneralCallCallback  */
        break;

      case HAL_I2C_ERROR_CB_ID :
        hi2c->ErrorCallback = HAL_I2C_ErrorCallback;               /* Legacy weak ErrorCallback        */
        break;

      case HAL_I2C_ABORT_CB_ID :
        hi2c->AbortCpltCallback = HAL_I2C_AbortCpltCallback;       /* Legacy weak AbortCpltCallback    */
        break;

      case HAL_I2C_TXABORT_CB_ID :
        hi2c->TxAbortCallback = HAL_I2C_TxAbortCallback;       /* Legacy weak AbortCpltCallback    */
        break;

      case HAL_I2C_MSPINIT_CB_ID :
        hi2c->MspInitCallback = HAL_I2C_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_I2C_MSPDEINIT_CB_ID :
        hi2c->MspDeInitCallback = HAL_I2C_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        hi2c->ErrorCode |= HAL_I2C_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_I2C_STATE_RESET == hi2c->State)
  {
    switch (CallbackID)
    {
      case HAL_I2C_MSPINIT_CB_ID :
        hi2c->MspInitCallback = HAL_I2C_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_I2C_MSPDEINIT_CB_ID :
        hi2c->MspDeInitCallback = HAL_I2C_MspDeInit;               /* Legacy weak MspDeInit            */
        break;

      default :
        /* Update the error code */
        hi2c->ErrorCode |= HAL_I2C_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hi2c->ErrorCode |= HAL_I2C_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hi2c);
  return status;
}

#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_Group2 Input and Output operation functions
  *  @brief   Data transfers functions
  *
  * @{
  */

/**
  * @brief  Transmits in master mode an amount of data in blocking mode.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  DevAddress Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                             uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

//    if (I2C_WaitOnStatusUntilTimeout(hi2c, I2C_STAT_MST_ACTIVITY, RESET, I2C_TIMEOUT_BUSY, tickstart) != HAL_OK)
//    {
//      return HAL_ERROR;
//    }

    hi2c->State     = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode      = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;

    /* Set XferSize */
    if (hi2c->XferCount >= I2C_TX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_TX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* Disable I2C */
     __HAL_I2C_DISABLE(hi2c);

    /* Config master */
    __HAL_I2C_MASTER(hi2c);

    /* Send Slave Address */
    MODIFY_REG(hi2c->Instance->TAR, I2C_TAR_TAR, DevAddress);
    
    /* I2C enable */
    __HAL_I2C_ENABLE(hi2c);

    /* Master-transmitter */  
    while (hi2c->XferCount > 0U)
    {
      /* write to TX FIFO */
      if (__HAL_I2C_GET_STATUS(hi2c, I2C_STAT_TFNF) == SET)
      {
        /* I2C write */
				MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD|I2C_DATACMD_DAT, I2C_CMD_WRITE|(*hi2c->pBuffPtr));

        /* Increment Buffer pointer */
        hi2c->pBuffPtr++;

        hi2c->XferCount--;

        tickstart = HAL_GetTick();
      }
      else
      {
        if(I2C_CheckTimeout(hi2c, Timeout, tickstart)!= HAL_OK)
        {
          return HAL_ERROR;
        } 
      }
    }

    /* Wait until TX FIFO is empty */
    if (I2C_WaitOnStatusUntilTimeout(hi2c, I2C_STAT_TFE, SET, Timeout, tickstart) != HAL_OK)
    {
      return HAL_ERROR;
    }

    /* Wait until Tx complete */
//    if (I2C_WaitOnStatusUntilTimeout(hi2c, I2C_STAT_MST_ACTIVITY, RESET, Timeout, tickstart) != HAL_OK)
//    {
//      return HAL_ERROR;
//    }

    /* Clear all Flag */
    __HAL_I2C_CLEAR_ALL(hi2c);

    /* Disable I2C */
    //__HAL_I2C_DISABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode  = HAL_I2C_MODE_NONE;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receives in master mode an amount of data in blocking mode.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  DevAddress Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                            uint16_t Size, uint32_t Timeout)
{
  uint32_t tickstart;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

//    if (I2C_WaitOnStatusUntilTimeout(hi2c, I2C_STAT_MST_ACTIVITY, RESET, I2C_TIMEOUT_BUSY, tickstart) != HAL_OK)
//    {
//      return HAL_ERROR;
//    }

    hi2c->State     = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode      = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;

    /* Set XferSize */
    if (hi2c->XferCount > I2C_RX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_RX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config master */
    __HAL_I2C_MASTER(hi2c);

    /* Send Slave Address */
    MODIFY_REG(hi2c->Instance->TAR, I2C_TAR_TAR, DevAddress);

    /* I2C enable */
    __HAL_I2C_ENABLE(hi2c);

    /* I2C read */
    MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);
    while (hi2c->XferCount > 0U)
    {
      /* Wait until RXNE flag is set */
      if (__HAL_I2C_GET_STATUS(hi2c, I2C_STAT_RFNE) == SET)
      {
        /* Read data from CMD_DATA */
        
        *hi2c->pBuffPtr = READ_BIT(hi2c->Instance->DATACMD, I2C_DATACMD_DAT);

        /* Increment Buffer pointer */
        hi2c->pBuffPtr++;

        hi2c->XferCount--;
		  
		if(hi2c->XferCount > 0)  
		{
			MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);
		}

        tickstart = HAL_GetTick();
      }
      else 
      {
        if(I2C_CheckTimeout(hi2c, Timeout, tickstart)!= HAL_OK)
        {
          __HAL_UNLOCK(hi2c);
          return HAL_ERROR;
        } 
      }
			
    }

    /* Wait until I2C idle is set */
//    if (I2C_WaitOnStatusUntilTimeout(hi2c, I2C_STAT_MST_ACTIVITY, RESET, Timeout, tickstart) != HAL_OK)
//    {
//      return HAL_ERROR;
//    }

    /* Clear all Flag */
    __HAL_I2C_CLEAR_ALL(hi2c);

    /* Disable I2C */
    //__HAL_I2C_DISABLE(hi2c);

    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->Mode  = HAL_I2C_MODE_NONE;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Transmits in slave mode an amount of data in blocking mode.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                            uint32_t Timeout)
{
  uint32_t tickstart;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      hi2c->ErrorCode = HAL_I2C_ERROR_INVALID_PARAM;
      return  HAL_ERROR;
    }
    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

    hi2c->State     = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode      = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;

    if (hi2c->XferCount > I2C_RX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_RX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config slave */
		MODIFY_REG(hi2c->Instance->SAR, I2C_SAR_SAR, hi2c->Init.OwnAddress);
		hi2c->Instance->CON |= I2C_CON_RESTARTEN;
		
    __HAL_I2C_SLAVE(hi2c);

    /* I2C enable */
    __HAL_I2C_ENABLE(hi2c);

    /* I2C not idle */
    do
    {
      while (hi2c->XferCount > 0U)
      {
        /* Check RD_REQ */
        if (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_RD_REQ) == SET)
        {
          /* check TX_ABRT and clear */
          if(__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_TX_ABRT) == SET)
          {
			  		//clear TX_ABRT
			  		__HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_TX_ABRT);
			  		
            if(__HAL_I2C_GET_TXABRT_SOURCE(hi2c, I2C_ABRT_SLVRD_INTX) == SET)
            {
              MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_WRITE);
              __HAL_UNLOCK(hi2c);
              return HAL_ERROR;
            }
            else if(__HAL_I2C_GET_TXABRT_SOURCE(hi2c, I2C_ABRT_SLV_ARBLOST) == SET)
            {
              __HAL_UNLOCK(hi2c);
              return HAL_ERROR;
            }
            else if(__HAL_I2C_GET_TXABRT_SOURCE(hi2c, I2C_ABRT_SLVFLUSH_TXFIFO) == SET)
            {
              __HAL_UNLOCK(hi2c);
              return HAL_ERROR;
            }
            else if(__HAL_I2C_GET_TXABRT_SOURCE(hi2c, I2C_ABRT_LOST) == SET)
            {
              __HAL_UNLOCK(hi2c);
              return HAL_ERROR;
            }
          }
  
			  	/* Slave-transmitter */  
          
       
          /* write to TX FIFO */
          while ((__HAL_I2C_GET_STATUS(hi2c, I2C_STAT_TFNF) == SET) && (hi2c->XferCount > 0U))
          {
            /* Write to CMD write & Write data to DATA_CMD */
            MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_DAT|I2C_DATACMD_CMD, (*hi2c->pBuffPtr)|I2C_CMD_WRITE);

            /* Increment Buffer pointer */
            hi2c->pBuffPtr++;

            hi2c->XferCount--;

            tickstart = HAL_GetTick();
          }
       
  
          /* Wait until TX FIFO is empty */
          //if (I2C_WaitOnStatusUntilTimeout(hi2c, I2C_STAT_TFE, SET, Timeout, tickstart) != HAL_OK)
          //{
          //  return HAL_ERROR;
          //}
  
          /* Clear RD_REQ flag*/
          __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_RD_REQ);
  
        }
        else 
        {
          if(I2C_CheckTimeout(hi2c, Timeout, tickstart)!= HAL_OK)
          {
            __HAL_UNLOCK(hi2c);
            return HAL_ERROR;
          } 
        }
      }

      /* Clear all Flag */
      __HAL_I2C_CLEAR_ALL(hi2c);
  
      /* Disable I2C */
      //__HAL_I2C_DISABLE(hi2c);
  
      hi2c->State = HAL_I2C_STATE_READY;
      hi2c->Mode  = HAL_I2C_MODE_NONE;
  
      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);
  
      return HAL_OK;

    } while(__HAL_I2C_GET_STATUS(hi2c, I2C_STAT_SLV_ACTIVITY));/* I2C activity */

  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receive in slave mode an amount of data in blocking mode
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                           uint32_t Timeout)
{
  uint32_t tickstart;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      hi2c->ErrorCode = HAL_I2C_ERROR_INVALID_PARAM;
      return  HAL_ERROR;
    }
    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* Init tickstart for timeout management*/
    tickstart = HAL_GetTick();

    hi2c->State     = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode      = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr  = pData;
    hi2c->XferCount = Size;
    hi2c->XferISR   = NULL;

    if (hi2c->XferCount > I2C_RX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_RX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }
		
    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);


    /* Config slave */
		MODIFY_REG(hi2c->Instance->SAR, I2C_SAR_SAR, hi2c->Init.OwnAddress);
		hi2c->Instance->CON |= I2C_CON_RESTARTEN;
		
    __HAL_I2C_SLAVE(hi2c);
		

    /* I2C enable */
    __HAL_I2C_ENABLE(hi2c);

    /* I2C not idle */
    //do
    //{
      /* Check RFNE */
      while ((hi2c->XferCount > 0U))
      {
        if(__HAL_I2C_GET_STATUS(hi2c, I2C_STAT_RFNE) == SET)
        {
          /* Slave-receiver byte by byte */  
          if (hi2c->XferCount > 0U)
          {
  					/* I2C read */
  					MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);  //no requires
  					/* Read data from CMD_DATA */
  					*hi2c->pBuffPtr = READ_BIT(hi2c->Instance->DATACMD, I2C_DATACMD_DAT);
  
  					/* Increment Buffer pointer */
  					hi2c->pBuffPtr++;
  
  					hi2c->XferCount--;
  
  					tickstart = HAL_GetTick();
  				}
  				else 
  				{
  					if(I2C_CheckTimeout(hi2c, Timeout, tickstart)!= HAL_OK)
  					{
              __HAL_UNLOCK(hi2c);
   						return HAL_ERROR;
  					} 
  				}
        }
      }
         /* Clear all Flag */
      __HAL_I2C_CLEAR_ALL(hi2c);
  
      /* Disable I2C */
      //__HAL_I2C_DISABLE(hi2c);
  
      hi2c->State = HAL_I2C_STATE_READY;
      hi2c->Mode  = HAL_I2C_MODE_NONE;
  
      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);
  
      return HAL_OK;

    //} while(__HAL_I2C_GET_STATUS(hi2c, I2C_STAT_SLV_ACTIVITY)); /* I2C activity */
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Transmit in master mode an amount of data in non-blocking mode with Interrupt
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  DevAddress Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                             uint16_t Size)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {
//    if (I2C_WaitOnStatusUntilTimeout(hi2c, I2C_STAT_MST_ACTIVITY, RESET, I2C_TIMEOUT_BUSY, tickstart) != HAL_OK)
//    {
//      return HAL_ERROR;
//    }

    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferISR     = I2C_Master_ISR_IT;

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config master */
    __HAL_I2C_MASTER(hi2c);

    /* config TX_TL to trigger TX_EMPTY */
    hi2c->Instance->TXTL = 0;

    /* config RX_TL to trigger RX_FULL */
    hi2c->Instance->RXTL = 0;

    /* ser XferSize */
    if (hi2c->XferCount > I2C_TX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_TX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* Send Slave Address */
    MODIFY_REG(hi2c->Instance->TAR, I2C_TAR_TAR, DevAddress);
  
    /* Enable I2C */
    __HAL_I2C_ENABLE(hi2c);

    /* Write CMD write */

    /* Write TX FIFO */  
    if (hi2c->XferCount > 0U)
    {
      /* write to TX FIFO */
      //while (hi2c->XferSize > 0)
      {
	      if (__HAL_I2C_GET_STATUS(hi2c, I2C_STAT_TFNF) == SET)
        {
					/* Write data to DATA_CMD */
					MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD|I2C_DATACMD_DAT,*hi2c->pBuffPtr|I2C_CMD_WRITE);

					/* Increment Buffer pointer */
					hi2c->pBuffPtr++;

					hi2c->XferCount--;
					hi2c->XferSize--;
				}
      }
    }

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    /* Note : The I2C interrupts must be enabled after unlocking current process
              to avoid the risk of I2C interrupt handle execution before current
              process unlock */

    I2C_Enable_IRQ(hi2c, I2C_IT_TX_EMPTY);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receive in master mode an amount of data in non-blocking mode with Interrupt
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  DevAddress Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                            uint16_t Size)
{
//  uint32_t xfermode;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
//    if (I2C_WaitOnStatusUntilTimeout(hi2c, I2C_STAT_MST_ACTIVITY, RESET, I2C_TIMEOUT_BUSY, tickstart) != HAL_OK)
//    {
//      return HAL_ERROR;
//    }

    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferISR     = I2C_Master_ISR_IT;

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config master */
    __HAL_I2C_MASTER(hi2c);

    /* Enable interrupt (I2C_IT_TX_EMPTY | I2C_IT_RX_FULL | I2C_IT_TX_ABRT) */
    I2C_Enable_IRQ(hi2c, I2C_IT_RX_FULL);

    /* config TX_TL to trigger TX_EMPTY */
    hi2c->Instance->TXTL = 0;

    /* config RX_TL to trigger RX_FULL */
    hi2c->Instance->RXTL = 0;

    /* Send Slave Address */
    MODIFY_REG(hi2c->Instance->TAR, I2C_TAR_TAR, DevAddress);

    /* Set XferSize */
    if (hi2c->XferCount > I2C_RX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_RX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* Enable I2C */
    __HAL_I2C_ENABLE(hi2c);

    /* Write CMD READ */
    MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Transmit in slave mode an amount of data in non-blocking mode with Interrupt
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;

    /* Set XferSize */
    if (hi2c->XferCount > I2C_RX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_RX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    hi2c->XferISR     = I2C_Slave_ISR_IT;

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config master */
    __HAL_I2C_SLAVE(hi2c);

    /* Enable interrupt */
    I2C_Enable_IRQ(hi2c, I2C_IT_RD_REQ);

    /* config TX_TL to trigger TX_EMPTY */
    hi2c->Instance->TXTL = 0;

    /* config RX_TL to trigger RX_FULL */
    hi2c->Instance->RXTL = 0;

    /* Enable I2C */
    __HAL_I2C_ENABLE(hi2c);

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receive in slave mode an amount of data in non-blocking mode with Interrupt
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)
{
  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
		
    /* Set XferSize */
    if (hi2c->XferCount > I2C_RX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_RX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    hi2c->XferISR     = I2C_Slave_ISR_IT;

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config slave */
		MODIFY_REG(hi2c->Instance->SAR, I2C_SAR_SAR, hi2c->Init.OwnAddress);
		hi2c->Instance->CON |= I2C_CON_RESTARTEN;
   __HAL_I2C_SLAVE(hi2c);

/* Enable interrupt (I2C_IT_RX_FULL | I2C_IT_TX_ABRT | I2C_IT_TX_EMPTY) */
    I2C_Enable_IRQ(hi2c, I2C_IT_RX_FULL);

    /* config TX_TL t trigger TX_EMPTY */
    hi2c->Instance->TXTL = 0;

    /* config RX_TL to trigger RX_FULL */
    hi2c->Instance->RXTL = 0;

    /* Enable I2C */
    __HAL_I2C_ENABLE(hi2c);

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Transmit in master mode an amount of data in non-blocking mode with DMA
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  DevAddress Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                              uint16_t Size)
{
//  uint32_t xfermode;
  HAL_StatusTypeDef dmaxferstatus;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
//    while (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_ACTIVITY))
//    {
//      //return HAL_BUSY;
//    }

    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config master */
    __HAL_I2C_MASTER(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
    hi2c->XferISR     = I2C_Master_ISR_DMA;

    /* Set XferSize */
    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    if (hi2c->XferCount > 0U)
    {
      /* configure DMA*/
      if (hi2c->hdmatx != NULL)
      {
        /* Set the I2C DMA transfer complete callback */
        hi2c->hdmatx->XferCpltCallback = I2C_DMAMasterTransmitCplt;

        /* Set the DMA error callback */
        hi2c->hdmatx->XferErrorCallback = I2C_DMAError;

        /* Set the unused DMA callbacks to NULL */
        hi2c->hdmatx->XferAbortCallback = NULL;

        /* Enable the DMA channel */
        dmaxferstatus = HAL_DMA_Start_IT(hi2c->hdmatx, (uint32_t)pData, (uint32_t)&hi2c->Instance->DATACMD,
                                         hi2c->XferSize);
      }
      else
      {
        /* Update I2C state */
        hi2c->State     = HAL_I2C_STATE_READY;
        hi2c->Mode      = HAL_I2C_MODE_NONE;

        /* Update I2C error code */
        hi2c->ErrorCode |= HAL_I2C_ERROR_DMA_PARAM;

        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);

        return HAL_ERROR;
      }

      if (dmaxferstatus == HAL_OK)
      {
        /* Send Slave Address */
        MODIFY_REG(hi2c->Instance->TAR, I2C_TAR_TAR, DevAddress);

        /* Enable interrupt (I2C_IT_RX_FULL | I2C_IT_TX_ABRT | I2C_IT_TX_EMPTY) */
        I2C_Enable_IRQ(hi2c, I2C_IT_TX_EMPTY);

        /* config TX_TL to trigger TX_EMPTY */
        hi2c->Instance->TXTL = 0;

        /* config RX_TL to trigger RX_FULL */
        hi2c->Instance->RXTL = 0;

        /* enable Tx DMA */
        MODIFY_REG(hi2c->Instance->DMACR, I2C_DMACR_TDMAE, I2C_DMACR_TDMAE);

        /* Configure Tx DMA water level*/
        hi2c->Instance->DMATDLR = 0;
				
				hi2c->XferCount -= hi2c->XferSize;

        /* Enable I2C */
        __HAL_I2C_ENABLE(hi2c);

        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);

      }
      else
      {
        /* Update I2C state */
        hi2c->State     = HAL_I2C_STATE_READY;
        hi2c->Mode      = HAL_I2C_MODE_NONE;

        /* Update I2C error code */
        hi2c->ErrorCode |= HAL_I2C_ERROR_DMA;

        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);

        return HAL_ERROR;
      }
    }
    else
    {
      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);
    }

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receive in master mode an amount of data in non-blocking mode with DMA
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  DevAddress Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                             uint16_t Size)
{
//  uint32_t xfermode;
  HAL_StatusTypeDef dmaxferstatus;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
//    while (__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_ACTIVITY))
//    {
//      //return HAL_BUSY;
//    }

    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config master */
    __HAL_I2C_MASTER(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_MASTER;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
//    hi2c->XferOptions = I2C_NO_OPTION_FRAME;
    hi2c->XferISR     = I2C_Master_ISR_DMA;

    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    if (hi2c->XferCount > 0U)
    {
      if (hi2c->hdmarx != NULL)
      {
        /* Set the I2C DMA transfer complete callback */
        hi2c->hdmarx->XferCpltCallback = I2C_DMAMasterReceiveCplt;
				
				/* Set the I2C DMA source transfer request callback */
				hi2c->hdmarx->XferSrcTranCallback = I2C_DMAMasterReceiveSrcTran;

        /* Set the DMA error callback */
        hi2c->hdmarx->XferErrorCallback = I2C_DMAError;

        /* Set the unused DMA callbacks to NULL */
        hi2c->hdmarx->XferAbortCallback = NULL;

        /* Enable the DMA channel */
        dmaxferstatus = HAL_DMA_Start_IT(hi2c->hdmarx, (uint32_t)&hi2c->Instance->DATACMD, (uint32_t)pData,
                                         hi2c->XferSize);
      }
      else
      {
        /* Update I2C state */
        hi2c->State     = HAL_I2C_STATE_READY;
        hi2c->Mode      = HAL_I2C_MODE_NONE;

        /* Update I2C error code */
        hi2c->ErrorCode |= HAL_I2C_ERROR_DMA_PARAM;

        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);

        return HAL_ERROR;
      }

      if (dmaxferstatus == HAL_OK)
      {
        /* Send Slave Address */
        MODIFY_REG(hi2c->Instance->TAR, I2C_TAR_TAR, DevAddress);

        /* Enable interrupt (I2C_IT_RX_FULL | I2C_IT_TX_ABRT | I2C_IT_TX_EMPTY) */
        I2C_Enable_IRQ(hi2c, I2C_IT_RX_FULL);

        /* config TX_TL to trigger TX_EMPTY */
        hi2c->Instance->TXTL = 0;

        /* config RX_TL to trigger RX_FULL */
        hi2c->Instance->RXTL = 0;

        /* enable Rx DMA */
        MODIFY_REG(hi2c->Instance->DMACR, I2C_DMACR_RDMAE, I2C_DMACR_RDMAE);

        /* Configure Rx DMA water level*/
        hi2c->Instance->DMARDLR = 0;
				
				hi2c->XferCount -= hi2c->XferSize;

        /* Enable I2C */
        __HAL_I2C_ENABLE(hi2c);

        /* Write CMD READ */
		if(hi2c->XferCount > 0)
		{
            MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);
		}

        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);

      }
      else
      {
        /* Update I2C state */
        hi2c->State     = HAL_I2C_STATE_READY;
        hi2c->Mode      = HAL_I2C_MODE_NONE;

        /* Update I2C error code */
        hi2c->ErrorCode |= HAL_I2C_ERROR_DMA;

        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);

        return HAL_ERROR;
      }
    }
    else
    {
      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

    }

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Transmit in slave mode an amount of data in non-blocking mode with DMA
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef dmaxferstatus;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      hi2c->ErrorCode = HAL_I2C_ERROR_INVALID_PARAM;
      return  HAL_ERROR;
    }
    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config slave */
    __HAL_I2C_SLAVE(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_TX;
    hi2c->Mode        = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
		
    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    hi2c->XferISR     = I2C_Slave_ISR_DMA;

		if (hi2c->XferCount > 0U)
		{
    if (hi2c->hdmatx != NULL)
    {
      /* Set the I2C DMA transfer complete callback */
      hi2c->hdmatx->XferCpltCallback = I2C_DMASlaveTransmitCplt;

      /* Set the DMA error callback */
      hi2c->hdmatx->XferErrorCallback = I2C_DMAError;

      /* Set the unused DMA callbacks to NULL */
      hi2c->hdmatx->XferAbortCallback = NULL;

      /* Enable the DMA channel */
      dmaxferstatus = HAL_DMA_Start_IT(hi2c->hdmatx, (uint32_t)pData, (uint32_t)&hi2c->Instance->DATACMD,
                                       hi2c->XferSize);
    }
    else
    {
      /* Update I2C state */
      hi2c->State     = HAL_I2C_STATE_READY;
      hi2c->Mode      = HAL_I2C_MODE_NONE;

      /* Update I2C error code */
      hi2c->ErrorCode |= HAL_I2C_ERROR_DMA_PARAM;

      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

      return HAL_ERROR;
    }

    if (dmaxferstatus == HAL_OK)
    {
        /* Enable interrupt (I2C_IT_RX_FULL | I2C_IT_TX_ABRT | I2C_IT_TX_EMPTY) */
        I2C_Enable_IRQ(hi2c, I2C_IT_RD_REQ);

        /* config TX_TL to trigger TX_EMPTY */
        hi2c->Instance->TXTL = 0;

        /* config RX_TL to trigger RX_FULL */
        hi2c->Instance->RXTL = 0;

        /* enable Tx DMA */
        MODIFY_REG(hi2c->Instance->DMACR, I2C_DMACR_TDMAE, I2C_DMACR_TDMAE);

        /* Configure Tx DMA water level*/
        hi2c->Instance->DMATDLR = 0;
			
			  hi2c->XferCount -= hi2c->XferSize;

        /* Enable I2C */
        __HAL_I2C_ENABLE(hi2c);
				
				/* I2C write */
        MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_WRITE);


      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

    }
    else
    {
      /* Update I2C state */
      hi2c->State     = HAL_I2C_STATE_READY;
      hi2c->Mode      = HAL_I2C_MODE_NONE;

      /* Update I2C error code */
      hi2c->ErrorCode |= HAL_I2C_ERROR_DMA;

      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

      return HAL_ERROR;
    }
	}
		else
			{
				__HAL_UNLOCK(hi2c);
			}

    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Receive in slave mode an amount of data in non-blocking mode with DMA
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size)
{
  HAL_StatusTypeDef dmaxferstatus;

  if (hi2c->State == HAL_I2C_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      hi2c->ErrorCode = HAL_I2C_ERROR_INVALID_PARAM;
      return  HAL_ERROR;
    }
    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* I2C disable */
    __HAL_I2C_DISABLE(hi2c);

    /* Config slave */
		MODIFY_REG(hi2c->Instance->SAR, I2C_SAR_SAR, hi2c->Init.OwnAddress);
		hi2c->Instance->CON |= I2C_CON_RESTARTEN;
    __HAL_I2C_SLAVE(hi2c);

    hi2c->State       = HAL_I2C_STATE_BUSY_RX;
    hi2c->Mode        = HAL_I2C_MODE_SLAVE;
    hi2c->ErrorCode   = HAL_I2C_ERROR_NONE;

    /* Prepare transfer parameters */
    hi2c->pBuffPtr    = pData;
    hi2c->XferCount   = Size;
		
    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    hi2c->XferISR     = I2C_Slave_ISR_DMA;

		if(hi2c->XferCount > 0U)
		{		
    if (hi2c->hdmarx != NULL)
    {
      /* Set the I2C DMA transfer complete callback */
      hi2c->hdmarx->XferCpltCallback = I2C_DMASlaveReceiveCplt;
			
			/* Set the I2C DMA source transfer request callback */
      hi2c->hdmarx->XferSrcTranCallback = I2C_DMASlaveReceiveSrcTran;
			
      /* Set the DMA error callback */
      hi2c->hdmarx->XferErrorCallback = I2C_DMAError;

      /* Set the unused DMA callbacks to NULL */
      hi2c->hdmarx->XferAbortCallback = NULL;

      /* Enable the DMA channel */
      dmaxferstatus = HAL_DMA_Start_IT(hi2c->hdmarx, (uint32_t)&hi2c->Instance->DATACMD, (uint32_t)pData,
                                       hi2c->XferSize);
    }
    else
    {
      /* Update I2C state */
      hi2c->State     = HAL_I2C_STATE_READY;
      hi2c->Mode      = HAL_I2C_MODE_NONE;

      /* Update I2C error code */
      hi2c->ErrorCode |= HAL_I2C_ERROR_DMA_PARAM;

      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

      return HAL_ERROR;
    }

    if (dmaxferstatus == HAL_OK)
    {
        /* Enable interrupt (I2C_IT_RX_FULL | I2C_IT_TX_ABRT | I2C_IT_TX_EMPTY) */
        I2C_Enable_IRQ(hi2c, I2C_IT_RX_FULL);

        /* config TX_TL to trigger TX_EMPTY */
        hi2c->Instance->TXTL = 0;

        /* config RX_TL to trigger RX_FULL */
        hi2c->Instance->RXTL = 0;

        /* enable Tx DMA */
        MODIFY_REG(hi2c->Instance->DMACR, I2C_DMACR_RDMAE, I2C_DMACR_RDMAE);

        /* Configure Tx DMA water level*/
        hi2c->Instance->DMATDLR = 0;
			
			  hi2c->XferCount -= hi2c->XferSize;

        /* Enable I2C */
        __HAL_I2C_ENABLE(hi2c);
				
        /* I2C read */
        MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);  //no requires


      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

    }
    else
    {
      /* Update I2C state */
      hi2c->State     = HAL_I2C_STATE_READY;
      hi2c->Mode      = HAL_I2C_MODE_NONE;

      /* Update I2C error code */
      hi2c->ErrorCode |= HAL_I2C_ERROR_DMA;

      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

      return HAL_ERROR;
    }
	}
		else{
			__HAL_UNLOCK(hi2c);
		}
    return HAL_OK;
  }
  else
  {
    return HAL_BUSY;
  }
}

/**
  * @brief  Abort a master I2C IT or DMA process communication with Interrupt.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  Timeout timeout
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint32_t Timeout)
{
//  uint32_t tickstart;

  if (hi2c->Mode == HAL_I2C_MODE_MASTER)
  {
    /* Process Locked */
    __HAL_LOCK(hi2c);

    /* Disable Interrupts and Store Previous state */
    if (hi2c->State == HAL_I2C_STATE_BUSY_TX)
    {
      I2C_Disable_IRQ(hi2c, I2C_IT_TX_EMPTY);
      hi2c->PreviousState = I2C_STATE_MASTER_BUSY_TX;

      /* Disable DMA */
      CLEAR_BIT(hi2c->Instance->DMACR, I2C_DMACR_TDMAE);
    }
    else if (hi2c->State == HAL_I2C_STATE_BUSY_RX)
    {
      I2C_Disable_IRQ(hi2c, I2C_IT_RX_FULL);
      hi2c->PreviousState = I2C_STATE_MASTER_BUSY_RX;

      /* Disable DMA */
      CLEAR_BIT(hi2c->Instance->DMACR, I2C_DMACR_RDMAE);
    }
    else
    {
      /* Do nothing */
    }

    I2C_Enable_IRQ(hi2c, I2C_IT_TX_ABRT);

		hi2c->Instance->ENABLE |= I2C_ENABLE_AB;
		
    /* Set State at HAL_I2C_STATE_ABORT */
    hi2c->State = HAL_I2C_STATE_ABORT;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);


    return HAL_OK;
  }
  else
  {
    /* Wrong usage of abort function */
    /* This function should be used only in case of abort monitored by master device */
    return HAL_ERROR;
  }
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_Group3 IRQ Handler and Callbacks
 *  @brief I2C IRQ handler and callbacks
  * @{
  */
/**
  * @brief  Handle interrupt request.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
void HAL_I2C_IRQHandler(I2C_HandleTypeDef *hi2c)
{
  /* ICTL line interrupt detected */
	if(hi2c->Instance == I2C1)
	{
		if(SYSCFG->IRQ_CFG_1 & ICTL_IRQCFG_I2C1_MASK)
		{
			return;
		}
	  if(ICTL->IRQFINALSTATUSL & ICTL_IRQCFG_I2C1_MASK)
	  {
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_GCALL)
			 {
					hi2c->XferISR(hi2c, I2C_IT_GEN_CALL, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_RXF)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RX_FULL, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_RDR)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RD_REQ, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_STRTD)
			 {
					hi2c->XferISR(hi2c, I2C_IT_START_DET, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_STPD)
			 {
					hi2c->XferISR(hi2c, I2C_IT_STOP_DET, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_ACT)
			 {
					hi2c->XferISR(hi2c, I2C_IT_ACTIVITY, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_TXE)
			 {
					hi2c->XferISR(hi2c, I2C_IT_TX_EMPTY, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_TXABRT)
			 {
					hi2c->XferISR(hi2c, I2C_IT_TX_ABRT, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_TXO)
			 {
					hi2c->XferISR(hi2c, I2C_IT_TX_OVER, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_RXD)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RX_DONE, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_RXU)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RX_UNDER, 0);
			 }
			 if (ICTL->IRQFINALSTATUSL & ICTL_IRQ_I2C1_RXO)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RX_OVER, 0);
			 }
    }
	}
	if(hi2c->Instance == I2C2)
	{
		if(SYSCFG->IRQ_CFG_2 & ICTL_IRQCFG_I2C2_MASK)
		{
			return;
		}
	  if(ICTL->IRQFINALSTATUSH & ICTL_IRQCFG_I2C2_MASK)
	  {
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_GCALL)
			 {
					hi2c->XferISR(hi2c, I2C_IT_GEN_CALL, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_RXF)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RX_FULL, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_RDR)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RD_REQ, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_STRTD)
			 {
					hi2c->XferISR(hi2c, I2C_IT_START_DET, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_STPD)
			 {
					hi2c->XferISR(hi2c, I2C_IT_STOP_DET, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_ACT)
			 {
					hi2c->XferISR(hi2c, I2C_IT_ACTIVITY, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_TXE)
			 {
					hi2c->XferISR(hi2c, I2C_IT_TX_EMPTY, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_TXABRT)
			 {
					hi2c->XferISR(hi2c, I2C_IT_TX_ABRT, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_TXO)
			 {
					hi2c->XferISR(hi2c, I2C_IT_TX_OVER, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_RXD)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RX_DONE, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_RXU)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RX_UNDER, 0);
			 }
			 if (ICTL->IRQFINALSTATUSH & ICTL_IRQ_I2C2_RXO)
			 {
					hi2c->XferISR(hi2c, I2C_IT_RX_OVER, 0);
			 }
    }
	}
}

/**
  * @brief  Master Tx Transfer completed callback.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_MasterTxCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Master Rx Transfer completed callback.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_MasterRxCpltCallback could be implemented in the user file
   */
}

/** @brief  Slave Tx Transfer completed callback.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_SlaveTxCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Slave Rx Transfer completed callback.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_SlaveRxCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  Slave received general call callback.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_SlaveGeneralCallCallback(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_SlaveGeneralCallCallback could be implemented in the user file
   */
}

/**
  * @brief  I2C error callback.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_ErrorCallback could be implemented in the user file
   */
}

/**
  * @brief  I2C abort callback.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_AbortCpltCallback could be implemented in the user file
   */
}

/**
  * @brief  I2C Tx abort callback.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  */
__weak void HAL_I2C_TxAbortCallback(I2C_HandleTypeDef *hi2c)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hi2c);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_I2C_AbortCpltCallback could be implemented in the user file
   */
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_Group4 Peripheral State, Mode and Error functions
  *  @brief   Peripheral State, Mode and Error functions
  *
  * @{
  */

/**
  * @brief  Return the I2C handle state.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @retval HAL state
  */
HAL_I2C_StateTypeDef HAL_I2C_GetState(I2C_HandleTypeDef *hi2c)
{
  /* Return I2C handle state */
  return hi2c->State;
}

/**
  * @brief  Returns the I2C Master, Slave, Memory or no mode.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *         the configuration information for I2C module
  * @retval HAL mode
  */
HAL_I2C_ModeTypeDef HAL_I2C_GetMode(I2C_HandleTypeDef *hi2c)
{
  return hi2c->Mode;
}

/**
  * @brief  Return the I2C error code.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *              the configuration information for the specified I2C.
  * @retval I2C Error Code
  */
uint32_t HAL_I2C_GetError(I2C_HandleTypeDef *hi2c)
{
  return hi2c->ErrorCode;
}

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_Group5 Special Configuration functions
  *  @brief   Configuration functions
  *
  * @{
  */
/**
  * @brief  Config I2C Timing.
  * @note this function shall be run when I2C is disabled
  * @param  hi2c I2C handle.
  * @param  BaudRate I2C baud rate in kbps
  */
void I2C_Config_Clock(I2C_HandleTypeDef *hi2c, uint32_t BaudRate)
{
  /*---------------------------- I2Cx XS_SPKLEN/XS_SCL_LCNT/XS_SCL_HCNT/SDA_SETUP/SDA_HOLD Configuration ------------------*/  
  uint32_t minscl_l;
  uint32_t minscl_h;
	uint32_t sclk;
	
	uint32_t lcnt;
  uint32_t hcnt;
	uint32_t spklen;
  
	uint32_t bps = BaudRate;
	uint32_t tcnt;
  
	uint32_t sdasu = 0x64;
  uint32_t rxht = 1;
  uint32_t txht = 1;

  if(hi2c->Instance == I2C1)
	{
    sclk = HAL_RCC_GetPeriphCLKFreq(RCC_PERIPHCLK_I2C1);
	}
	else
	{
    sclk = HAL_RCC_GetPeriphCLKFreq(RCC_PERIPHCLK_I2C2);
	}
	
  if(hi2c->Init.Speed == I2C_SPEED_STANDARD)
  {
		//@100kbps 2.7M
    minscl_l = 4700; //@ns
		minscl_h = 4000; //@ns
    spklen = 1;
		
		tcnt = 1000000000/bps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
    
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(hi2c->Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
		
    MODIFY_REG(hi2c->Instance->FSSPKLEN, I2C_FSSPKLEN_LEN, spklen << I2C_FSSPKLEN_LEN_Pos);
    WRITE_REG(hi2c->Instance->SSSCLHCNT, (uint16_t)(hcnt - spklen - 7));
    WRITE_REG(hi2c->Instance->SSSCLLCNT, (uint16_t)(lcnt - 1));
  }
  else if((hi2c->Init.Speed == I2C_SPEED_FAST)
    && (BaudRate <= 400000))
  {
		//@400kbps 12M
    minscl_l = 1300; //@ns
		minscl_h = 600; //@ns
    spklen = 1;
		
		tcnt = 1000000000/bps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
 
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(hi2c->Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
		
    MODIFY_REG(hi2c->Instance->FSSPKLEN, I2C_FSSPKLEN_LEN, spklen << I2C_FSSPKLEN_LEN_Pos);
    WRITE_REG(hi2c->Instance->FSSCLHCNT, (uint16_t)(hcnt - spklen - 7));
    WRITE_REG(hi2c->Instance->FSSCLLCNT, (uint16_t)(lcnt - 1));
  }
  else if((hi2c->Init.Speed == I2C_SPEED_FAST)
    && ((BaudRate > 400000)&&(BaudRate <= 1000000)))
  {
		//@1Mbps 32M
    minscl_l = 500; //@ns
		minscl_h = 260; //@ns
    spklen = 2;
		
		tcnt = 1000000000/bps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
 
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(hi2c->Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
		
    MODIFY_REG(hi2c->Instance->FSSPKLEN, I2C_FSSPKLEN_LEN, spklen << I2C_FSSPKLEN_LEN_Pos);
    WRITE_REG(hi2c->Instance->FSSCLHCNT, (uint16_t)(hcnt - spklen - 7));
    WRITE_REG(hi2c->Instance->FSSCLLCNT, (uint16_t)(lcnt - 1));
  }
  else //if(hi2c->Init.Speed == I2C_SPEED_HIGH)
  {
		//@100pf 3.4Mbps 105.4M
    minscl_l = 120; //@ns
		minscl_h = 60; //@ns
    spklen = 1;
		
		tcnt = 1000000000/bps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
 
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(rxht > (lcnt - 1 - spklen - 3))
		{
		  rxht = lcnt -1 - spklen - 3;
		}
		if(hi2c->Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
		
    MODIFY_REG(hi2c->Instance->HSSPKLEN, I2C_HSSPKLEN_LEN, 1 << I2C_HSSPKLEN_LEN_Pos);
    WRITE_REG(hi2c->Instance->HSSCLHCNT, (uint16_t)(hcnt - spklen - 7));
    WRITE_REG(hi2c->Instance->HSSCLLCNT, (uint16_t)(lcnt - 1));
  }
//  else if(hi2c->Init.Speed == I2C_SPEED_HIGH)
//  {
//		//@400pf 3.4Mbps 51M
//    minscl_l = 320; //@ns
//		minscl_h = 160; //@ns
//    spklen = 1;
//		
//		tcnt = 1000000000/bps;
//		
//		if(tcnt > (minscl_l + minscl_h))
//		{
//			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
//			minscl_l = tcnt - minscl_h;
//		}
//		else
//		{
//			//error, need to decrease kpbs
//		}
//		
//    lcnt = (sclk/1000*minscl_l)/(1000000);
//		hcnt = (sclk/1000*minscl_h)/(1000000);
//		
//		if(lcnt < (spklen+7+1))
//		{
//			//lcnt = (spklen+7);
//			//error, need to increase sclk
//		}
//		if(hcnt < (2*spklen+5+7))
//		{
//			//hcnt = (spklen+5);
//			//error, need to increase sclk
//		}
// 
//		rxht = hcnt - spklen - 7 - spklen - 3;
//		if(rxht > ((lcnt - 1)/2 - spklen - 3))
//		{
//		  rxht = (lcnt -1)/2 - spklen - 3;
//		}
//		if(hi2c->Mode == I2C_MODE_SLAVE)
//		{
//			txht = spklen + 7;
//		}
//		else
//		{
//			txht = 1;
//		}
//		
//    MODIFY_REG(hi2c->Instance->HSSPKLEN, I2C_HSSPKLEN_LEN, 1 << I2C_HSSPKLEN_LEN_Pos);
//    WRITE_REG(hi2c->Instance->HSSCLHCNT, (uint16_t)(hcnt - spklen - 7));
//    WRITE_REG(hi2c->Instance->HSSCLLCNT, (uint16_t)(lcnt - 1));
//  }
  
  //the amount of time delay (in terms of number of ic_clk clock periods)
  //default 0x64
	if(hi2c->Init.Speed == I2C_SPEED_STANDARD)
	{
		sdasu = sclk / 1000 * 250 / 1000000;
	}
	else if((hi2c->Init.Speed == I2C_SPEED_FAST)
          && (BaudRate <= 400000))
	{
		sdasu = sclk / 1000 * 100 / 1000000;
	}
  else if((hi2c->Init.Speed == I2C_SPEED_FAST)
          && ((BaudRate > 400000)&&(BaudRate <= 1000000)))
	{
		sdasu = sclk / 1000 * 50 / 1000000;
	}
  else //if(hi2c->Init.Speed == I2C_SPEED_HIGH)
	{
		sdasu = sclk / 100000000;
	}
	
	WRITE_REG(hi2c->Instance->SDASETUP, sdasu);
  
  //the hold time of SDA during transmit in both slave and master mode
  //default IC_DEFAULT_SDA_HOLD
  MODIFY_REG(hi2c->Instance->SDAHOLD, I2C_SDAH_RX, rxht << I2C_SDAH_RX_Pos);
  MODIFY_REG(hi2c->Instance->SDAHOLD, I2C_SDAH_TX, txht << I2C_SDAH_TX_Pos);
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup I2C_Private_Functions
  * @{
  */

/**
  * @brief  Interrupt Sub-Routine which handle the Interrupt Flags Master Mode with Interrupt.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  ITFlags Interrupt flags to handle.
  *         This parameter can be one of the following values:
  *         @arg @ref I2C_IT_RX_UNDER 
  *         @arg @ref I2C_IT_RX_OVER  
  *         @arg @ref I2C_IT_RX_FULL  
  *         @arg @ref I2C_IT_TX_OVER  
  *         @arg @ref I2C_IT_TX_EMPTY 
  *         @arg @ref I2C_IT_RD_REQ   
  *         @arg @ref I2C_IT_TX_ABRT  
  *         @arg @ref I2C_IT_RX_DONE  
  *         @arg @ref I2C_IT_ACTIVITY 
  *         @arg @ref I2C_IT_STOP_DET 
  *         @arg @ref I2C_IT_START_DET
  *         @arg @ref I2C_IT_GEN_CALL 
  * @retval HAL status
  */
HAL_StatusTypeDef I2C_Master_ISR_IT(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{
  //uint16_t devaddress;
  uint32_t tmpITFlags = ITFlags;

  /* Process Locked */
  __HAL_LOCK(hi2c);

  if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_UNDER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_UNDER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_RXU;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_OVER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_OVER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_RXO;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_FULL) != RESET) 
  {
    /* Remove RX FULL flag on temporary variable as read done */
    tmpITFlags &= ~I2C_IT_RX_FULL;

    while((__HAL_I2C_CHECK_STATUS(hi2c, I2C_STAT_RFNE)) && (hi2c->XferSize > 0))
    {
      /* Read data from IC_DATA_CMD */
      *hi2c->pBuffPtr = (uint8_t)(hi2c->Instance->DATACMD & I2C_DATACMD_DAT);
			

      /* Increment Buffer pointer */
      hi2c->pBuffPtr++;

      hi2c->XferSize--;
      hi2c->XferCount--;
		
	  if(hi2c->XferCount > 0)	
	  {
	  	  MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);
	  }
			
    }

    if (hi2c->XferCount > I2C_RX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_RX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }
		
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_OVER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_TX_OVER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_TXO;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_EMPTY) != RESET)
  {
//		(*((uint32_t*)0x50000C00)) = 0x49525120;
		
    tmpITFlags &= ~I2C_IT_TX_EMPTY;

    while((__HAL_I2C_CHECK_STATUS(hi2c, I2C_STAT_TFNF)) && (hi2c->XferSize > 0))
    {
      /* Write data to TXDR */
      MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD|I2C_DATACMD_DAT, I2C_CMD_WRITE|(*hi2c->pBuffPtr));

      /* Increment Buffer pointer */
      hi2c->pBuffPtr++;

      hi2c->XferSize--;
      hi2c->XferCount--;
			
    }
    if (hi2c->XferCount > I2C_TX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_TX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_ABRT) != RESET)
  {
    /* process Tx abort */
    I2C_Tx_Abort_ISR(hi2c);

    /* Clear tx abort */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_TX_ABRT);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_TXABRT;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_STOP_DET) != RESET)
  {
    /* Clear stop detect */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_STOP_DET);
	
    if(hi2c->XferCount > 0)	
	{
		hi2c->ErrorCode |= HAL_I2C_ERROR_TXABRT;
	}		
		
	if ((hi2c->XferCount == 0)||(hi2c->ErrorCode > HAL_I2C_ERROR_NONE))
	{
      /* Call I2C Master complete process */
      I2C_ITMasterCplt(hi2c, tmpITFlags);
	}

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_START_DET) != RESET)
  {
    /* Clear start dectect */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_START_DET);
  }
  else
  {
    /* Nothing to do */
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}

/**
  * @brief  Interrupt Sub-Routine which handle the Interrupt Flags Slave Mode with Interrupt.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  ITFlags Interrupt flags to handle.
  *         This parameter can be one of the following values:
  *         @arg @ref I2C_IT_RX_UNDER 
  *         @arg @ref I2C_IT_RX_OVER  
  *         @arg @ref I2C_IT_RX_FULL  
  *         @arg @ref I2C_IT_TX_OVER  
  *         @arg @ref I2C_IT_TX_EMPTY 
  *         @arg @ref I2C_IT_RD_REQ   
  *         @arg @ref I2C_IT_TX_ABRT  
  *         @arg @ref I2C_IT_RX_DONE  
  *         @arg @ref I2C_IT_ACTIVITY 
  *         @arg @ref I2C_IT_STOP_DET 
  *         @arg @ref I2C_IT_START_DET
  *         @arg @ref I2C_IT_GEN_CALL 
  * @retval HAL status
  */
HAL_StatusTypeDef I2C_Slave_ISR_IT(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{
//  uint32_t tmpoptions = hi2c->XferOptions;
  uint32_t tmpITFlags = ITFlags;

  /* Process locked */
  __HAL_LOCK(hi2c);

  if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_UNDER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_UNDER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_RXU;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_OVER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_OVER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_RXO;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_FULL) != RESET) 
  {
    /* Remove RX FULL flag on temporary variable as read done */
    tmpITFlags &= ~I2C_IT_RX_FULL;

    while((__HAL_I2C_CHECK_STATUS(hi2c, I2C_STAT_RFNE)) && (hi2c->XferSize > 0))
    {
      *hi2c->pBuffPtr = (uint8_t)(hi2c->Instance->DATACMD & I2C_DATACMD_DAT);
      /* Read data from IC_DATA_CMD */
			

      /* Increment Buffer pointer */
      hi2c->pBuffPtr++;

      hi2c->XferSize--;
      hi2c->XferCount--;
		
	  if(hi2c->XferCount>0)	
	  {
		  MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);  //no requires
	  }
    }
    
		if (hi2c->XferCount > I2C_TX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_TX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_OVER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_TX_OVER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_TXO;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_EMPTY) != RESET)
  {
    tmpITFlags &= ~I2C_IT_TX_EMPTY;

    while((__HAL_I2C_CHECK_STATUS(hi2c, I2C_STAT_TFNF)) && (hi2c->XferSize > 0))
    {
      /* Write data to TXDR */
      MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD|I2C_DATACMD_DAT, I2C_CMD_WRITE|*hi2c->pBuffPtr);

      /* Increment Buffer pointer */
      hi2c->pBuffPtr++;

      hi2c->XferSize--;
      hi2c->XferCount--;
    }
    
		if (hi2c->XferCount > I2C_TX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_TX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_ABRT) != RESET)
  {
    /* process Tx abort */
    I2C_Tx_Abort_ISR(hi2c);

    /* Clear Tx Abort */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_TX_ABRT);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_TXABRT;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RD_REQ) != RESET)
  {
    /* Clear Tx abort */
    if(__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_TX_ABRT))
    {
      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_TX_ABRT);
    }

    /* Slave-transmitter */  
    /* write data to tx FIFO */
    while((__HAL_I2C_GET_STATUS(hi2c, I2C_STAT_TFNF)) && (hi2c->XferSize > 0U))
    {
      /* Write data to DATA_CMD */
      MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD|I2C_DATACMD_DAT,I2C_CMD_WRITE|*hi2c->pBuffPtr);

      /* Increment Buffer pointer */
      hi2c->pBuffPtr++;

      hi2c->XferCount--;
      hi2c->XferSize--;

    }

    if (hi2c->XferCount > I2C_TX_BUFFER_DEPTH)
    {
      hi2c->XferSize = I2C_TX_BUFFER_DEPTH;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* Clear rd det */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RD_REQ);

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_DONE) != RESET)
  {
    /* Clear rx done */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_DONE);

    /* Call I2C Master complete process */
    I2C_ITSlaveCplt(hi2c, tmpITFlags);

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_STOP_DET) != RESET)
  {
    /* Clear stop det */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_STOP_DET);

    /* Call I2C Master complete process */
    I2C_ITSlaveCplt(hi2c, tmpITFlags);

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_START_DET) != RESET)
  {
    /* Clear start det */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_START_DET);
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_GEN_CALL) != RESET)
  {
    /* Clear general call */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_GEN_CALL);

    /* call I2C general call process */
    I2C_ITSlaveGeneralCall(hi2c);
  }
  else
  {
    /* Nothing to do */
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}

/**
  * @brief  Interrupt Sub-Routine which handle the Interrupt Flags Master Mode with DMA.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  ITFlags Interrupt flags to handle.
  *         This parameter can be one of the following values:
  *         @arg @ref I2C_IT_RX_UNDER 
  *         @arg @ref I2C_IT_RX_OVER  
  *         @arg @ref I2C_IT_RX_FULL  
  *         @arg @ref I2C_IT_TX_OVER  
  *         @arg @ref I2C_IT_TX_EMPTY 
  *         @arg @ref I2C_IT_RD_REQ   
  *         @arg @ref I2C_IT_TX_ABRT  
  *         @arg @ref I2C_IT_RX_DONE  
  *         @arg @ref I2C_IT_ACTIVITY 
  *         @arg @ref I2C_IT_STOP_DET 
  *         @arg @ref I2C_IT_START_DET
  *         @arg @ref I2C_IT_GEN_CALL 
  * @retval HAL status
  */
static HAL_StatusTypeDef I2C_Master_ISR_DMA(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{
//  uint16_t devaddress;
//  uint32_t xfermode;

	uint32_t tmpITFlags = ITFlags;
  /* Process Locked */
  __HAL_LOCK(hi2c);

  if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_UNDER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_UNDER);

    /* Set corresponding Error Code */
    /* No need to generate STOP, it is automatically done */
    
    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_RXU;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_OVER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_OVER);

    /* Set corresponding Error Code */
    /* No need to generate STOP, it is automatically done */
    
    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_RXO;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_FULL) != RESET) 
  {
    /* Remove RX FULL flag on temporary variable as read done */
    tmpITFlags &= ~I2C_IT_RX_FULL;
		
	MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_OVER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_TX_OVER);

    /* Set corresponding Error Code */
    /* No need to generate STOP, it is automatically done */
    
    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_TXO;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_EMPTY) != RESET)
  {
    tmpITFlags &= ~I2C_IT_TX_EMPTY;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_ABRT) != RESET)
  {
    /* process Tx abort */
    I2C_Tx_Abort_ISR(hi2c);

    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_TX_ABRT);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_TXABRT;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_STOP_DET) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_STOP_DET);

	if (hi2c->ErrorCode > HAL_I2C_ERROR_NONE)
	{
      /* Call I2C Master complete process */
      I2C_ITMasterCplt(hi2c, tmpITFlags);
    }
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_START_DET) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_START_DET);
  }
  else
  {
    /* Nothing to do */
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}

/**
  * @brief  Interrupt Sub-Routine which handle the Interrupt Flags Slave Mode with DMA.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  ITFlags Interrupt flags to handle.
  *         This parameter can be one of the following values:
  *         @arg @ref I2C_IT_RX_UNDER 
  *         @arg @ref I2C_IT_RX_OVER  
  *         @arg @ref I2C_IT_RX_FULL  
  *         @arg @ref I2C_IT_TX_OVER  
  *         @arg @ref I2C_IT_TX_EMPTY 
  *         @arg @ref I2C_IT_RD_REQ   
  *         @arg @ref I2C_IT_TX_ABRT  
  *         @arg @ref I2C_IT_RX_DONE  
  *         @arg @ref I2C_IT_ACTIVITY 
  *         @arg @ref I2C_IT_STOP_DET 
  *         @arg @ref I2C_IT_START_DET
  *         @arg @ref I2C_IT_GEN_CALL 
  * @retval HAL status
  */
static HAL_StatusTypeDef I2C_Slave_ISR_DMA(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{
//  uint32_t tmpoptions = hi2c->XferOptions;
//  uint32_t treatdmanack = 0U;
//  HAL_I2C_StateTypeDef tmpstate;
	uint32_t tmpITFlags = ITFlags;

  /* Process locked */
  __HAL_LOCK(hi2c);

  if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_UNDER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_UNDER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_RXU;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_OVER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_OVER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_RXO;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_FULL) != RESET) 
  {
    /* Remove RX FULL flag on temporary variable as read done */
    tmpITFlags &= ~I2C_IT_RX_FULL;
		
		MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);  //no requires
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_OVER) != RESET)
  {
    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_TX_OVER);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_TXO;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_EMPTY) != RESET)
  {
    tmpITFlags &= ~I2C_IT_TX_EMPTY;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_TX_ABRT) != RESET)
  {
    /* process Tx abort */
    I2C_Tx_Abort_ISR(hi2c);

    /* Clear rx under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_TX_ABRT);

    /* Error callback will be send during stop flag treatment */
    hi2c->ErrorCode |= HAL_I2C_ERROR_TXABRT;
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RD_REQ) != RESET)
  {

    /* Clear Tx abort */
    if(__HAL_I2C_GET_FLAG(hi2c, I2C_FLAG_TX_ABRT))
    {
      __HAL_I2C_CLEAR_FLAG(hi2c, I2C_FLAG_TX_ABRT);
    }

    /* write command write  */
    MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_WRITE);
    
		/* Clear rd det */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RD_REQ);

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_RX_DONE) != RESET)
  {
    /* Clear rx done */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_RX_DONE);

    /* Call I2C Master complete process */
    I2C_ITSlaveCplt(hi2c, tmpITFlags);

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_STOP_DET) != RESET)
  {
    /* Clear stop under */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_STOP_DET);

		if (hi2c->ErrorCode > HAL_I2C_ERROR_NONE)
		{
      /* Call I2C Master complete process */
      I2C_ITSlaveCplt(hi2c, tmpITFlags);
		}

  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_START_DET) != RESET)
  {
    /* Clear start det */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_START_DET);
  }
  else if (I2C_CHECK_IT(tmpITFlags, I2C_IT_GEN_CALL) != RESET)
  {
    /* Clear general call */
    __HAL_I2C_CLEAR_IT(hi2c, I2C_IT_GEN_CALL);
  }
  else
  {
    /* Nothing to do */
  }

  /* Process Unlocked */
  __HAL_UNLOCK(hi2c);

  return HAL_OK;
}

/**
  * @brief  I2C Tx abort Isr.
  * @param  hi2c I2C handle.
  */
static void I2C_Tx_Abort_ISR(I2C_HandleTypeDef *hi2c)
{
  uint32_t source = READ_REG(hi2c->Instance->TXABRTSOURCE);

  hi2c->TxAbortSource = source;

  /*!< Not receive an acknowledgement in 7-bit addressing mode        */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_7B_ADDR_NOACK))
  {
    /* Master-Transmitter or Master-Receiver  */
    /* Master is in 7-bit addressing mode and the address sent was not acknowledged by any slave. */
  }

  /*!< Not receive an acknowledgement for 10-bit address first byte */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_TXAS_10A1NA))
  {
    /* Master-Transmitter or Master-Receiver  */
    /* Master is in 10-bit address mode and the first 10-bit address byte was not acknowledged by any slave. */
  }

  /*!< Not receive an acknowledgement for 10-bit address second byte     */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_TXAS_10A2NA))
  {
    /* Master-Transmitter or Master-Receiver  */
    /* Master is in 10-bit address mode and the second 10-bit address byte was not acknowledged by any slave. */
  }
  
  /*!< Not receive an acknowledgement for data */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_TXDATA_NOACK))
  {
    /* Master-Transmitter  */
    /* This is a master-mode only bit. Master has received an acknowledgement for the address, but when it sent data byte(s)
       following the address, it did not receive an acknowledge from the remote slave(s). */
  }

  /*!< Master sent a General Call and no slave onthe bus acknowledged the General Call */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_TXAS_GCNACK))
  {
    /* Master-Transmitter  */
    /* Master sent a General Call and no slave on the bus acknowledged the General Call. */
  }

  /*!< Master sent a Generak Cakk but the user programmed the byte following the General Call to be a read from the bus */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_GCALL_READ))
  {
    /* Master-Transmitter  */
    /* Master sent a General Call but the user programmed the byte following the General Call to be a read from the bus */
  }
  /*!< Master in High Speed mode and High Speed Master code was acknownledged */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_HS_ACKDET))
  {
    /* Master */
    /* Master is in High Speed mode and the High Speed Master code was acknowledged (wrong behavior). */
  }
  /*!< Master has sent a START Byte and the START Byte was acknowledged */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_SBYTE_ACKDET))
  {
    /* Master */
    /* Master has sent a START Byte and the START Byte was acknowledged (wrong behavior). */
  }
  /*!< The restart is disabled and the user is trying to use the master to transfer data in High Speed mode */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_HS_NORSTRT))
  {
    /* Master-Transmitter or Master-Receiver  */
    /* The restart is disabled (IC_RESTART_EN bit (IC_CON[5]) = 0) and the user is trying to use the master to transfer data in High Speed mode. */
  }
  /*!< To clear Bit 9 */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_SBYTE_NORSTRT))
  {
    /* Master */
    /* The restart is disabled (IC_RESTART_EN bit (IC_CON[5]) = 0) and the user is trying to send a START Byte. */
  }
  /*!< The restart is disabled and the master sends a read command in 10-bit addressing mode */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_10B_RD_NORSTRT))
  {
    /* Master-Receiver */
    /* The restart is disabled (IC_RESTART_EN bit (IC_CON[5]) = 0) and the master sends a read command in 10-bit addressing mode. */
  }
  /*!< User initiate a master operation with the master mode disabled */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_MASTER_DIS))
  {
    /* Master-Transmitter or Master-Receiver  */
    /* User tries to initiate a Master operation with the Master mode disabled. */
  }
  /*!< Master has lost arbitration */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_LOST))
  {
    /* Master-Transmitter or Slave-Transmitter */
    /* Master has lost arbitration, or if IC_TX_ABRT_SOURCE[14] is also set, then the slave transmitter has lost arbitration. */
  }
  /*!< Slave has received a read command and some data exists in the TX FIFO */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_SLVFLUSH_TXFIFO))
  {
    /* Slave-Transmitter */
    /* Slave has received a read command and some data exists in the TX FIFO so the slave issues a TX_ABRT interrupt to flush old data in TX FIFO. */
  }
  /*!< Slave lost bus while transmitting data to a remote master         */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_SLV_ARBLOST))
  {
    /* Slave-Transmitter */
    /* Slave lost the bus while transmitting data to a remote master. */
  }
  /*!< When the processor side reponds to a slave mode request for data to be transmitted to aremote master and user write 1 to CMD */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_SLVRD_INTX))
  {
    /* Slave-Transmitter */
    /* When the processor side responds to a slave mode request for data to be transmitted to a remote master and user writes a 1 in CMD (bit 8) of IC_DATA_CMD register. */
  }
  /*!< Master has detected the transfer abort                            */
  if(I2C_CHECK_ABRT_SOURCE(source, I2C_ABRT_USER_ABRT))
  {
    /* Master-Transmitter */
    /* This is a master-mode-only bit. Master has detected the transfer abort (IC_ENABLE[1]). */
  }

    /* Call the corresponding callback to inform upper layer of tx abort */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
    hi2c->TxAbortCallback(hi2c);
#else
    HAL_I2C_TxAbortCallback(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
}

/**
  * @brief  I2C Master complete process.
  * @param  hi2c I2C handle.
  * @param  ITFlags Interrupt flags to handle.
  *         This parameter can be one of the following values:
  *         @arg @ref I2C_IT_RX_UNDER 
  *         @arg @ref I2C_IT_RX_OVER  
  *         @arg @ref I2C_IT_RX_FULL  
  *         @arg @ref I2C_IT_TX_OVER  
  *         @arg @ref I2C_IT_TX_EMPTY 
  *         @arg @ref I2C_IT_RD_REQ   
  *         @arg @ref I2C_IT_TX_ABRT  
  *         @arg @ref I2C_IT_RX_DONE  
  *         @arg @ref I2C_IT_ACTIVITY 
  *         @arg @ref I2C_IT_STOP_DET 
  *         @arg @ref I2C_IT_START_DET
  *         @arg @ref I2C_IT_GEN_CALL 
  */
static void I2C_ITMasterCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{
  uint32_t tmperror;
  uint32_t tmpITFlags = ITFlags;
  __IO uint32_t tmpreg;

  /* Disable Interrupts and Store Previous state */
  if (hi2c->State == HAL_I2C_STATE_BUSY_TX)
  {
    I2C_Disable_IRQ(hi2c, I2C_IT_TX_EMPTY);
    hi2c->PreviousState = I2C_STATE_MASTER_BUSY_TX;
  }
  else if (hi2c->State == HAL_I2C_STATE_BUSY_RX)
  {
    I2C_Disable_IRQ(hi2c, I2C_IT_RX_DONE);
    hi2c->PreviousState = I2C_STATE_MASTER_BUSY_RX;
  }
  else
  {
    /* Do nothing */
  }

  /* Reset handle parameters */
  hi2c->XferISR       = NULL;

  /* Fetch Last receive data if any */
  if ((hi2c->State == HAL_I2C_STATE_ABORT) && (I2C_CHECK_FLAG(tmpITFlags, I2C_FLAG_RX_FULL) != RESET))
  {
    /* Read data from RXDR */
    tmpreg = (uint8_t)hi2c->Instance->DATACMD;
    UNUSED(tmpreg);
  }

  /* Store current volatile hi2c->ErrorCode, misra rule */
  tmperror = hi2c->ErrorCode;

  /* Call the corresponding callback to inform upper layer of End of Transfer */
  if ((hi2c->State == HAL_I2C_STATE_ABORT) || (tmperror != HAL_I2C_ERROR_NONE))
  {
    /* Call the corresponding callback to inform upper layer of End of Transfer */
    I2C_ITError(hi2c, hi2c->ErrorCode);
  }
  /* hi2c->State == HAL_I2C_STATE_BUSY_TX */
  else if (hi2c->State == HAL_I2C_STATE_BUSY_TX)
  {
    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->PreviousState = I2C_STATE_NONE;

    hi2c->Mode = HAL_I2C_MODE_NONE;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);
	  
	if(tmperror != HAL_I2C_ERROR_NONE)  
	{
	  I2C_ITError(hi2c, hi2c->ErrorCode);
	}
	else
	{
      /* Call the corresponding callback to inform upper layer of End of Transfer */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
      hi2c->MasterTxCpltCallback(hi2c);
#else
      HAL_I2C_MasterTxCpltCallback(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
	}
  }
  /* hi2c->State == HAL_I2C_STATE_BUSY_RX */
  else if (hi2c->State == HAL_I2C_STATE_BUSY_RX)
  {
    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->PreviousState = I2C_STATE_NONE;

    hi2c->Mode = HAL_I2C_MODE_NONE;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

	if(tmperror != HAL_I2C_ERROR_NONE)  
	{
	  I2C_ITError(hi2c, hi2c->ErrorCode);
	}
	else
	{
	  
    /* Call the corresponding callback to inform upper layer of End of Transfer */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
    hi2c->MasterRxCpltCallback(hi2c);
#else
    HAL_I2C_MasterRxCpltCallback(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
	}
  }
  else
  {
    /* Nothing to do */
  }
}
/**
  * @brief  I2C Slave complete process.
  * @param  hi2c I2C handle.
  * @param  ITFlags Interrupt flags to handle.
  */
static void I2C_ITSlaveCplt(I2C_HandleTypeDef *hi2c, uint32_t ITFlags)
{
  uint32_t tmpITFlags = ITFlags;
  HAL_I2C_StateTypeDef tmpstate = hi2c->State;

  /* Disable Interrupts and Store Previous state */
  if ((tmpstate == HAL_I2C_STATE_BUSY_TX) /*|| (tmpstate == HAL_I2C_STATE_BUSY_TX_LISTEN)*/)
  {
    I2C_Disable_IRQ(hi2c, I2C_IT_TX_EMPTY);
    hi2c->PreviousState = I2C_STATE_SLAVE_BUSY_TX;
  }
  else if ((tmpstate == HAL_I2C_STATE_BUSY_RX) /*|| (tmpstate == HAL_I2C_STATE_BUSY_RX_LISTEN)*/)
  {
    I2C_Disable_IRQ(hi2c, I2C_IT_RX_DONE);
    hi2c->PreviousState = I2C_STATE_SLAVE_BUSY_RX;
  }
  else
  {
    /* Do nothing */
  }

  /* If a DMA is ongoing, Update handle size context */
  if ((hi2c->Instance->DMACR & I2C_DMACR_TDMAE) != RESET)
  {
    /* Disable DMA Request */
    hi2c->Instance->DMACR &= ~I2C_DMACR_TDMAE;

    if (hi2c->hdmatx != NULL)
    {
      hi2c->XferCount = (uint16_t)__HAL_DMA_GET_DST_COUNTER(hi2c->hdmatx);
    }
  }
  else if ((hi2c->Instance->DMACR & I2C_DMACR_RDMAE) != RESET)
  {
    /* Disable DMA Request */
    hi2c->Instance->DMACR &= ~I2C_DMACR_RDMAE;

    if (hi2c->hdmarx != NULL)
    {
      hi2c->XferCount = (uint16_t)__HAL_DMA_GET_SRC_COUNTER(hi2c->hdmarx);
    }
  }
  else
  {
    /* Do nothing */
  }

  /* Store Last receive data if any */
  if (I2C_CHECK_FLAG(tmpITFlags, I2C_FLAG_RX_FULL) != RESET)
  {
    /* Read data from RXDR */
    *hi2c->pBuffPtr = (uint8_t)hi2c->Instance->DATACMD;

    /* Increment Buffer pointer */
    hi2c->pBuffPtr++;

    if ((hi2c->XferSize > 0U))
    {
      hi2c->XferSize--;
      hi2c->XferCount--;
    }
  }

  /* All data are not transferred, so set error code accordingly */
//  if (hi2c->XferCount != 0U)
//  {
//    /* Set ErrorCode corresponding to a Non-Acknowledge */
//    hi2c->ErrorCode |= HAL_I2C_ERROR_AF;
//  }

  hi2c->Mode = HAL_I2C_MODE_NONE;
  hi2c->XferISR = NULL;

  if (hi2c->ErrorCode != HAL_I2C_ERROR_NONE)
  {
    /* Call the corresponding callback to inform upper layer of End of Transfer */
    I2C_ITError(hi2c, hi2c->ErrorCode);

  }
  else if (hi2c->State == HAL_I2C_STATE_BUSY_RX)
  {
    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->PreviousState = I2C_STATE_NONE;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    /* Call the corresponding callback to inform upper layer of End of Transfer */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
    hi2c->SlaveRxCpltCallback(hi2c);
#else
    HAL_I2C_SlaveRxCpltCallback(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
  }
  else
  {
    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->PreviousState = I2C_STATE_NONE;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    /* Call the corresponding callback to inform upper layer of End of Transfer */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
    hi2c->SlaveTxCpltCallback(hi2c);
#else
    HAL_I2C_SlaveTxCpltCallback(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
  }
}

/**
  * @brief  I2C interrupts error process.
  * @param  hi2c I2C handle.
  * @param  ErrorCode Error code to handle.
  */
static void I2C_ITError(I2C_HandleTypeDef *hi2c, uint32_t ErrorCode)
{
  HAL_I2C_StateTypeDef tmpstate = hi2c->State;
  uint32_t tmppreviousstate;

  /* Reset handle parameters */
  hi2c->Mode          = HAL_I2C_MODE_NONE;
//  hi2c->XferOptions   = I2C_NO_OPTION_FRAME;
  hi2c->XferCount     = 0U;

  /* Set new error code */
  hi2c->ErrorCode |= ErrorCode;

	/* Disable all interrupts */
	I2C_Disable_IRQ(hi2c, I2C_IT_TX_EMPTY|I2C_IT_RD_REQ|I2C_IT_RX_FULL);

	/* If state is an abort treatment on going, don't change state */
	/* This change will be do later */
	if (hi2c->State != HAL_I2C_STATE_ABORT)
	{
		/* Set HAL_I2C_STATE_READY */
		hi2c->State         = HAL_I2C_STATE_READY;
	}
	hi2c->XferISR       = NULL;

  /* Abort DMA TX transfer if any */
  tmppreviousstate = hi2c->PreviousState;
  if ((hi2c->hdmatx != NULL) && ((tmppreviousstate == I2C_STATE_MASTER_BUSY_TX) || \
                                 (tmppreviousstate == I2C_STATE_SLAVE_BUSY_TX)))
  {
    if ((hi2c->Instance->DMACR & I2C_DMACR_TDMAE) == I2C_DMACR_TDMAE)
    {
      hi2c->Instance->DMACR &= ~I2C_DMACR_TDMAE;
    }

    if (HAL_DMA_GetState(hi2c->hdmatx) != HAL_DMA_STATE_READY)
    {
      /* Set the I2C DMA Abort callback :
       will lead to call HAL_I2C_ErrorCallback() at end of DMA abort procedure */
      hi2c->hdmatx->XferAbortCallback = I2C_DMAAbort;

      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

      /* Abort DMA TX */
      if (HAL_DMA_Abort_IT(hi2c->hdmatx) != HAL_OK)
      {
        /* Call Directly XferAbortCallback function in case of error */
        hi2c->hdmatx->XferAbortCallback(hi2c->hdmatx);
      }
    }
    else
    {
      I2C_TreatErrorCallback(hi2c);
    }
  }
  /* Abort DMA RX transfer if any */
  else if ((hi2c->hdmarx != NULL) && ((tmppreviousstate == I2C_STATE_MASTER_BUSY_RX) || \
                                      (tmppreviousstate == I2C_STATE_SLAVE_BUSY_RX)))
  {
    if ((hi2c->Instance->DMACR & I2C_DMACR_RDMAE) == I2C_DMACR_RDMAE)
    {
      hi2c->Instance->DMACR &= ~I2C_DMACR_RDMAE;
    }

    if (HAL_DMA_GetState(hi2c->hdmarx) != HAL_DMA_STATE_READY)
    {
      /* Set the I2C DMA Abort callback :
        will lead to call HAL_I2C_ErrorCallback() at end of DMA abort procedure */
      hi2c->hdmarx->XferAbortCallback = I2C_DMAAbort;

      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);

      /* Abort DMA RX */
      if (HAL_DMA_Abort_IT(hi2c->hdmarx) != HAL_OK)
      {
        /* Call Directly hi2c->hdmarx->XferAbortCallback function in case of error */
        hi2c->hdmarx->XferAbortCallback(hi2c->hdmarx);
      }
    }
    else
    {
      I2C_TreatErrorCallback(hi2c);
    }
  }
  else
  {
    I2C_TreatErrorCallback(hi2c);
  }
}

/**
  * @brief  I2C Error callback treatment.
  * @param  hi2c I2C handle.
  */
static void I2C_TreatErrorCallback(I2C_HandleTypeDef *hi2c)
{
  if (hi2c->State == HAL_I2C_STATE_ABORT)
  {
    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->PreviousState = I2C_STATE_NONE;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    /* Call the corresponding callback to inform upper layer of End of Transfer */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
    hi2c->AbortCpltCallback(hi2c);
#else
    HAL_I2C_AbortCpltCallback(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
  }
  else
  {
    hi2c->State = HAL_I2C_STATE_READY;
    hi2c->PreviousState = I2C_STATE_NONE;

    /* Process Unlocked */
    __HAL_UNLOCK(hi2c);

    /* Call the corresponding callback to inform upper layer of End of Transfer */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
    hi2c->ErrorCallback(hi2c);
#else
    HAL_I2C_ErrorCallback(hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
  }
}

/**
  * @brief  DMA I2C master transmit process complete callback.
  * @param  hdma DMA handle
  */
static void I2C_DMAMasterTransmitCplt(DMA_HandleTypeDef *hdma)
{
  /* Derogation MISRAC2012-Rule-11.5 */
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

  /* Disable DMA Request */
  hi2c->Instance->DMACR &= ~I2C_DMACR_TDMAE;

  /* If last transfer, enable STOP interrupt */
  if (hi2c->XferCount == 0U)
  {
    I2C_ITMasterCplt(hi2c, I2C_IT_STOP_DET);
    /* Enable STOP interrupt */
    //I2C_Enable_IRQ(hi2c, I2C_IT_TX_EMPTY);
  }
  /* else prepare a new DMA transfer and enable TCReload interrupt */
  else
  {
    /* Update Buffer pointer */
    hi2c->pBuffPtr += hi2c->XferSize;

    /* Set the XferSize to transfer */
    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hi2c->hdmatx, (uint32_t)hi2c->pBuffPtr, (uint32_t)&hi2c->Instance->DATACMD,
                         hi2c->XferSize) != HAL_OK)
    {
      /* Call the corresponding callback to inform upper layer of End of Transfer */
      I2C_ITError(hi2c, HAL_I2C_ERROR_DMA);
    }
    else
    {
			hi2c->XferCount -= hi2c->XferSize;
			
			hi2c->Instance->DMACR |= I2C_DMACR_TDMAE;
      /* Enable TC interrupts */
      //I2C_Enable_IRQ(hi2c, I2C_XFER_RELOAD_IT);
    }
  }
}

/**
  * @brief  DMA I2C slave transmit process complete callback.
  * @param  hdma DMA handle
  */
static void I2C_DMASlaveTransmitCplt(DMA_HandleTypeDef *hdma)
{
  /* Derogation MISRAC2012-Rule-11.5 */
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

  /* Disable DMA Request */
  hi2c->Instance->DMACR &= ~I2C_DMACR_TDMAE;

  /* If last transfer, enable STOP interrupt */
  if (hi2c->XferCount == 0U)
  {
		I2C_ITSlaveCplt(hi2c, I2C_IT_STOP_DET);
    /* Enable STOP interrupt */
    //I2C_Enable_IRQ(hi2c, I2C_IT_RD_REQ);
  }
  /* else prepare a new DMA transfer and enable TCReload interrupt */
  else
  {
    /* Update Buffer pointer */
    hi2c->pBuffPtr += hi2c->XferSize;

    /* Set the XferSize to transfer */
    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hi2c->hdmatx, (uint32_t)hi2c->pBuffPtr, (uint32_t)&hi2c->Instance->DATACMD,
                         hi2c->XferSize) != HAL_OK)
    {
      /* Call the corresponding callback to inform upper layer of End of Transfer */
      I2C_ITError(hi2c, HAL_I2C_ERROR_DMA);
    }
    else
    {
			hi2c->XferCount -= hi2c->XferSize;
			
			hi2c->Instance->DMACR |= I2C_DMACR_TDMAE;
      /* Enable TC interrupts */
      //I2C_Enable_IRQ(hi2c, I2C_XFER_RELOAD_IT);
    }
  }
}

/**
  * @brief DMA I2C master receive process complete callback.
  * @param  hdma DMA handle
  */
static void I2C_DMAMasterReceiveCplt(DMA_HandleTypeDef *hdma)
{
  /* Derogation MISRAC2012-Rule-11.5 */
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

  /* Disable DMA Request */
  hi2c->Instance->DMACR &= ~I2C_DMACR_RDMAE;

  /* If last transfer, enable STOP interrupt */
  if (hi2c->XferCount == 0U)
  {
		I2C_ITMasterCplt(hi2c, I2C_IT_STOP_DET);
    /* Enable STOP interrupt */
    //I2C_Enable_IRQ(hi2c, I2C_IT_RX_FULL);
  }
  /* else prepare a new DMA transfer and enable TCReload interrupt */
  else
  {
    /* Update Buffer pointer */
    hi2c->pBuffPtr += hi2c->XferSize;

    /* Set the XferSize to transfer */
    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hi2c->hdmarx, (uint32_t)&hi2c->Instance->DATACMD, (uint32_t)hi2c->pBuffPtr,
                         hi2c->XferSize) != HAL_OK)
    {
      /* Call the corresponding callback to inform upper layer of End of Transfer */
      I2C_ITError(hi2c, HAL_I2C_ERROR_DMA);
    }
    else
    {
			hi2c->XferCount -= hi2c->XferSize;
			
			hi2c->Instance->DMACR |= I2C_DMACR_RDMAE;
      /* Enable TC interrupts */
//      I2C_Enable_IRQ(hi2c, I2C_XFER_RELOAD_IT);
    }
  }
}

/**
  * @brief  DMA I2C slave receive process complete callback.
  * @param  hdma DMA handle
  */
static void I2C_DMASlaveReceiveCplt(DMA_HandleTypeDef *hdma)
{
  /* Derogation MISRAC2012-Rule-11.5 */
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);
  /* Disable DMA Request */
  hi2c->Instance->DMACR &= ~I2C_DMACR_RDMAE;

  /* If last transfer, enable STOP interrupt */
  if (hi2c->XferCount == 0U)
  {
		I2C_ITSlaveCplt(hi2c, I2C_IT_STOP_DET);
    /* Enable STOP interrupt */
    //I2C_Enable_IRQ(hi2c, I2C_IT_RX_FULL);
  }
  /* else prepare a new DMA transfer and enable TCReload interrupt */
  else
  {
    /* Update Buffer pointer */
    hi2c->pBuffPtr += hi2c->XferSize;

    /* Set the XferSize to transfer */
    if (hi2c->XferCount > MAX_NBYTE_SIZE)
    {
      hi2c->XferSize = MAX_NBYTE_SIZE;
    }
    else
    {
      hi2c->XferSize = hi2c->XferCount;
    }

    /* Enable the DMA channel */
    if (HAL_DMA_Start_IT(hi2c->hdmarx, (uint32_t)&hi2c->Instance->DATACMD, (uint32_t)hi2c->pBuffPtr,
                         hi2c->XferSize) != HAL_OK)
    {
      /* Call the corresponding callback to inform upper layer of End of Transfer */
      I2C_ITError(hi2c, HAL_I2C_ERROR_DMA);
    }
    else
    {
			hi2c->XferCount -= hi2c->XferSize;
			
			hi2c->Instance->DMACR |= I2C_DMACR_RDMAE;
      /* Enable TC interrupts */
//      I2C_Enable_IRQ(hi2c, I2C_XFER_RELOAD_IT);
    }
  }
}

/**
  * @brief  DMA I2C master transmit dsttran callback.
  * @param  hdma DMA handle
  */
static void I2C_DMAMasterTransmitDstTran(DMA_HandleTypeDef *hdma)
{
}

/**
  * @brief  DMA I2C master receive srctran callback.
  * @param  hdma DMA handle
  */
static void I2C_DMAMasterReceiveSrcTran(DMA_HandleTypeDef *hdma)
{
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);
  
  MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);
}

/**
  * @brief  DMA I2C slave transmit dsttran callback.
  * @param  hdma DMA handle
  */
static void I2C_DMASlaveTransmitDstTran(DMA_HandleTypeDef *hdma)
{
}

/**
  * @brief  DMA I2C slave receive srctran callback.
  * @param  hdma DMA handle
  */
static void I2C_DMASlaveReceiveSrcTran(DMA_HandleTypeDef *hdma)
{
	I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);
	
	MODIFY_REG(hi2c->Instance->DATACMD, I2C_DATACMD_CMD, I2C_CMD_READ);
}

/**
  * @brief  DMA I2C communication error callback.
  * @param hdma DMA handle
  */
static void I2C_DMAError(DMA_HandleTypeDef *hdma)
{
  /* Derogation MISRAC2012-Rule-11.5 */
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

  /* Call the corresponding callback to inform upper layer of End of Transfer */
  I2C_ITError(hi2c, HAL_I2C_ERROR_DMA);
}

/**
  * @brief DMA I2C communication abort callback
  *        (To be called at end of DMA Abort procedure).
  * @param hdma DMA handle.
  */
static void I2C_DMAAbort(DMA_HandleTypeDef *hdma)
{
  /* Derogation MISRAC2012-Rule-11.5 */
  I2C_HandleTypeDef *hi2c = (I2C_HandleTypeDef *)(((DMA_HandleTypeDef *)hdma)->Parent);

  /* Reset AbortCpltCallback */
  if (hi2c->hdmatx != NULL)
  {
    hi2c->hdmatx->XferAbortCallback = NULL;
  }
  if (hi2c->hdmarx != NULL)
  {
    hi2c->hdmarx->XferAbortCallback = NULL;
  }

  I2C_TreatErrorCallback(hi2c);
}

/**
  * @brief  This function handles I2C Communication Timeout.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  Flag Specifies the I2C flag to check.
  * @param  Status The new Flag status (SET or RESET).
  * @param  Timeout Timeout duration
  * @param  Tickstart Tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef I2C_WaitOnFlagUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Flag, FlagStatus Status,
                                                    uint32_t Timeout, uint32_t Tickstart)
{
  while (__HAL_I2C_GET_FLAG(hi2c, Flag) != Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
      {
        hi2c->ErrorCode |= HAL_I2C_ERROR_TIMEOUT;
        hi2c->State = HAL_I2C_STATE_READY;
        hi2c->Mode = HAL_I2C_MODE_NONE;

        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  This function handles I2C Communication Timeout.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  Flag Specifies the I2C flag to check.
  * @param  Status The new Flag status (SET or RESET).
  * @param  Timeout Timeout duration
  * @param  Tickstart Tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef I2C_WaitOnStatusUntilTimeout(I2C_HandleTypeDef *hi2c, uint32_t Flag, FlagStatus Status,
                                                    uint32_t Timeout, uint32_t Tickstart)
{
  while (__HAL_I2C_GET_STATUS(hi2c, Flag) != Status)
  {
    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
      {
        hi2c->ErrorCode |= HAL_I2C_ERROR_TIMEOUT;
        hi2c->State = HAL_I2C_STATE_READY;
        hi2c->Mode = HAL_I2C_MODE_NONE;

        /* Process Unlocked */
        __HAL_UNLOCK(hi2c);
        return HAL_ERROR;
      }
    }
  }
  return HAL_OK;
}

/**
  * @brief  This function handles I2C Communication Timeout.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  Timeout Timeout duration
  * @param  Tickstart Tick start value
  * @retval HAL status
  */
static HAL_StatusTypeDef I2C_CheckTimeout(I2C_HandleTypeDef *hi2c, uint32_t Timeout, uint32_t Tickstart)
{
  /* Check for the Timeout */
  if (Timeout != HAL_MAX_DELAY)
  {
    if (((HAL_GetTick() - Tickstart) > Timeout) || (Timeout == 0U))
    {
      hi2c->ErrorCode |= HAL_I2C_ERROR_TIMEOUT;
      hi2c->State = HAL_I2C_STATE_READY;
      hi2c->Mode = HAL_I2C_MODE_NONE;

      /* Process Unlocked */
      __HAL_UNLOCK(hi2c);
      return HAL_ERROR;
    }
  }
  return HAL_OK;
}

/**
  * @brief  Manage the enabling of Interrupts.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  InterruptRequest I2C Interrupts.
  *         This parameter can be one of the following values:
  *         @arg @ref I2C_IT_RX_UNDER 
  *         @arg @ref I2C_IT_RX_OVER  
  *         @arg @ref I2C_IT_RX_FULL  
  *         @arg @ref I2C_IT_TX_OVER  
  *         @arg @ref I2C_IT_TX_EMPTY 
  *         @arg @ref I2C_IT_RD_REQ   
  *         @arg @ref I2C_IT_TX_ABRT  
  *         @arg @ref I2C_IT_RX_DONE  
  *         @arg @ref I2C_IT_ACTIVITY 
  *         @arg @ref I2C_IT_STOP_DET 
  *         @arg @ref I2C_IT_START_DET
  *         @arg @ref I2C_IT_GEN_CALL 
  */
static void I2C_Enable_IRQ(I2C_HandleTypeDef *hi2c, uint16_t InterruptRequest)
{
  uint32_t tmpisr = 0U;

  if ((InterruptRequest & I2C_IT_STOP_DET) == I2C_IT_STOP_DET)
  {
    tmpisr |= I2C_IT_STOP_DET;
  }
  if ((InterruptRequest & I2C_IT_TX_ABRT) == I2C_IT_TX_ABRT)
  {
    tmpisr |= I2C_IT_TX_ABRT | I2C_IT_STOP_DET;
  }
  
  if ((InterruptRequest & I2C_IT_TX_EMPTY) == I2C_IT_TX_EMPTY)
  {
    /* Enable ERR, TC, STOP, NACK and RXI interrupts */
    tmpisr |= I2C_IT_TX_ABRT | I2C_IT_RX_FULL | I2C_IT_TX_EMPTY | I2C_IT_STOP_DET;
  }
  if ((InterruptRequest & I2C_IT_RX_FULL) == I2C_IT_RX_FULL)
  {
    /* Enable ERR, TC, STOP, NACK and TXI interrupts */
    tmpisr |= I2C_IT_TX_ABRT | I2C_IT_RX_FULL | I2C_IT_STOP_DET;
  }
  if ((InterruptRequest & I2C_IT_RD_REQ) == I2C_IT_RD_REQ)
  {
    /* Enable ERR, TC, STOP, NACK and TXI interrupts */
    tmpisr |= /*I2C_IT_TX_EMPTY |*/ I2C_IT_TX_ABRT | I2C_IT_RX_FULL | I2C_IT_RD_REQ | I2C_IT_STOP_DET;
  }

  /* Enable interrupts only at the end */
  /* to avoid the risk of I2C interrupt handle execution before */
  /* all interrupts requested done */
  __HAL_I2C_UNMASK_IT(hi2c, tmpisr);
}

/**
  * @brief  Manage the disabling of Interrupts.
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  InterruptRequest I2C Interrupts.
  *         This parameter can be one of the following values:
  *         @arg @ref I2C_IT_RX_UNDER 
  *         @arg @ref I2C_IT_RX_OVER  
  *         @arg @ref I2C_IT_RX_FULL  
  *         @arg @ref I2C_IT_TX_OVER  
  *         @arg @ref I2C_IT_TX_EMPTY 
  *         @arg @ref I2C_IT_RD_REQ   
  *         @arg @ref I2C_IT_TX_ABRT  
  *         @arg @ref I2C_IT_RX_DONE  
  *         @arg @ref I2C_IT_ACTIVITY 
  *         @arg @ref I2C_IT_STOP_DET 
  *         @arg @ref I2C_IT_START_DET
  *         @arg @ref I2C_IT_GEN_CALL 
  */
static void I2C_Disable_IRQ(I2C_HandleTypeDef *hi2c, uint16_t InterruptRequest)
{
  uint32_t tmpisr = 0U;

  tmpisr = InterruptRequest;

  if ((InterruptRequest & I2C_IT_TX_EMPTY) == I2C_IT_TX_EMPTY)
  {
    /* Disable TC and TXI interrupts */
    tmpisr |= I2C_IT_TX_EMPTY | I2C_IT_TX_ABRT | I2C_IT_TX_OVER | I2C_IT_STOP_DET;
  }

  if (((InterruptRequest & I2C_IT_RX_FULL) == I2C_IT_RX_FULL) 
     || ((InterruptRequest & I2C_IT_RD_REQ) == I2C_IT_RD_REQ)
     || ((InterruptRequest & I2C_IT_RX_DONE) == I2C_IT_RX_DONE)) 
  {
    /* Disable TC and RXI interrupts */
    tmpisr |= I2C_IT_RX_FULL | I2C_IT_RX_UNDER | I2C_IT_RX_OVER | I2C_IT_RD_REQ | I2C_IT_TX_ABRT | I2C_IT_RX_DONE | I2C_IT_GEN_CALL | I2C_IT_START_DET | I2C_IT_STOP_DET;
  }

  /* Disable interrupts only at the end */
  /* to avoid a breaking situation like at "t" time */
  /* all disable interrupts request are not done */
  __HAL_I2C_MASK_IT(hi2c, tmpisr);
}

static void I2C_ITSlaveGeneralCall(I2C_HandleTypeDef *hi2c)
{
}
/**
  * @}
  */

#endif /* HAL_I2C_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
