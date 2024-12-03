/**
  ******************************************************************************
  * @file    xt32h0xx_hal_dma.c
  * @author  Software Team
  * @brief   DMA HAL module driver.
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

/** @defgroup DMA DMA
  * @brief DMA HAL module driver
  * @{
  */

#ifdef HAL_DMA_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macros ------------------------------------------------------------*/
/** @defgroup DMA_Private_Macros DMA Private Macros
  * @{
  */

#define IS_DMA_DIRECTION(DIRECTION)             (((DIRECTION) == DMA_MEMORY_TO_MEMORY_FC_DMAC) || \
                                                 ((DIRECTION) == DMA_MEMORY_TO_PERIPH_FC_DMAC) || \
                                                 ((DIRECTION) == DMA_PERIPH_TO_MEMORY_FC_DMAC) || \
                                                 ((DIRECTION) == DMA_PERIPH_TO_PERIPH_FC_DMAC) || \
                                                 ((DIRECTION) == DMA_PERIPH_TO_MEMORY_FC_PERI) || \
                                                 ((DIRECTION) == DMA_PERIPH_TO_PERIPH_FC_SRCP) || \
                                                 ((DIRECTION) == DMA_MEMORY_TO_PERIPH_FC_PERI) || \
                                                 ((DIRECTION) == DMA_PERIPH_TO_PERIPH_FC_DSTP))

#define IS_DMA_BUFFER_SIZE(SIZE)                (((SIZE) >= 0x1U) && ((SIZE) < DMA_CH_CHCTL_BLOCKTS))

#define IS_DMA_SOURCE_INC_STATE(STATE)          (((STATE) == DMA_SINC_INCREMENT) || \
                                                 ((STATE) == DMA_SINC_DECREMENT) || \
                                                 ((STATE) == DMA_SINC_NOCHANGE ))

#define IS_DMA_DESTINATION_INC_STATE(STATE)      (((STATE) == DMA_DINC_INCREMENT) || \
                                                  ((STATE) == DMA_DINC_DECREMENT) || \
                                                  ((STATE) == DMA_DINC_NOCHANGE ))

#define IS_DMA_SOURCE_DATA_SIZE(SIZE)           (((SIZE) == DMA_SDATAALIGN_BYTE      ) || \
                                                 ((SIZE) == DMA_SDATAALIGN_HALFWORD  ) || \
                                                 ((SIZE) == DMA_SDATAALIGN_WORD      ) || \
                                                 ((SIZE) == DMA_SDATAALIGN_DOUBLEWORD) || \
                                                 ((SIZE) == DMA_SDATAALIGN_QUOTAWORD ) || \
                                                 ((SIZE) == DMA_SDATAALIGN_OCTOWORD  ))

#define IS_DMA_DESTINATION_DATA_SIZE(SIZE)      (((SIZE) == DMA_DDATAALIGN_BYTE      ) || \
                                                 ((SIZE) == DMA_DDATAALIGN_HALFWORD  ) || \
                                                 ((SIZE) == DMA_DDATAALIGN_WORD      ) || \
                                                 ((SIZE) == DMA_DDATAALIGN_DOUBLEWORD) || \
                                                 ((SIZE) == DMA_DDATAALIGN_QUOTAWORD ) || \
                                                 ((SIZE) == DMA_DDATAALIGN_OCTOWORD  ))

#define IS_DMA_SOURCE_MSIZE(SIZE)               (((SIZE) == DMA_SRC_MSIZE_1  ) || \
                                                 ((SIZE) == DMA_SRC_MSIZE_4  ) || \
                                                 ((SIZE) == DMA_SRC_MSIZE_8  ) || \
                                                 ((SIZE) == DMA_SRC_MSIZE_16 ) || \
                                                 ((SIZE) == DMA_SRC_MSIZE_32 ) || \
                                                 ((SIZE) == DMA_SRC_MSIZE_64 ) || \
                                                 ((SIZE) == DMA_SRC_MSIZE_128) || \
                                                 ((SIZE) == DMA_SRC_MSIZE_256))

#define IS_DMA_DESTINATION_MSIZE(SIZE)          (((SIZE) == DMA_DST_MSIZE_1  ) || \
                                                 ((SIZE) == DMA_DST_MSIZE_4  ) || \
                                                 ((SIZE) == DMA_DST_MSIZE_8  ) || \
                                                 ((SIZE) == DMA_DST_MSIZE_16 ) || \
                                                 ((SIZE) == DMA_DST_MSIZE_32 ) || \
                                                 ((SIZE) == DMA_DST_MSIZE_64 ) || \
                                                 ((SIZE) == DMA_DST_MSIZE_128) || \
                                                 ((SIZE) == DMA_DST_MSIZE_256))

#define IS_DMA_MODE(MODE)                       (((MODE) == DMA_SGLBLK          ) \
                                              || ((MODE) == DMA_MULBLK_CSAR_RDAR) \
                                              || ((MODE) == DMA_MULBLK_RSAR_CDAR) \
                                              || ((MODE) == DMA_MULBLK_RSAR_RDAR)) 


#define IS_DMA_PRIORITY(PRIORITY)               (((PRIORITY) == DMA_PRIORITY_0) || \
                                                 ((PRIORITY) == DMA_PRIORITY_1) || \
                                                 ((PRIORITY) == DMA_PRIORITY_2) || \
                                                 ((PRIORITY) == DMA_PRIORITY_3) || \
                                                 ((PRIORITY) == DMA_PRIORITY_4) || \
                                                 ((PRIORITY) == DMA_PRIORITY_5) || \
                                                 ((PRIORITY) == DMA_PRIORITY_6) || \
                                                 ((PRIORITY) == DMA_PRIORITY_7))
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/
static uint8_t uMutualStop = 0;
static uint8_t uMutualCplt = 0;
/* Private function prototypes -----------------------------------------------*/

/** @defgroup DMA_Private_Functions DMA Private Functions
  * @{
  */
static void DMA_SetConfig(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
static void DMA_SetMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Mode, uint32_t LlpAddr);
//static uint32_t DMA_ClearAllpendingInterupts(DMA_HandleTypeDef *hdma, uint32_t Timeout);

/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/

/** @defgroup DMA_Exported_Functions DMA Exported Functions
  * @{
  */

/** @defgroup DMA_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief   Initialization and de-initialization functions
  *
  * @{
  */

/**
  * @brief Allocate channel for DMA 
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_AllocateChannel(DMA_HandleTypeDef *hdma)
{
  uint32_t i = 0;
	uint32_t mask = DMA_CHEN_EN_0;

  for (i=0; i<HAL_DMA_CH_NUMBER; i++)
  {
    if(((uint32_t)READ_BIT((((DMA_TypeDef *)DMAAUX1)->CHEN), mask)) == 0)
    {
      hdma->ChannelIndex = i;
      hdma->Instance = (DMA_Channel_TypeDef *)(__HAL_DMA_GET_CHANNEL_INSTANCE(DMA1, i));
      hdma->DMAAux = (DMA_TypeDef *)DMAAUX1;
      return HAL_OK;
    }
		mask <<= 1;
  }
  
  return HAL_ERROR;
}

/**
  * @brief Initialize the DMA according to the specified
  *        parameters in the DMA_InitTypeDef and initialize the associated handle.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma)
{
  /* Check the DMA handle allocation */
  if (hdma == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));
  assert_param(IS_DMA_DIRECTION(hdma->Init.Direction));
  assert_param(IS_DMA_SOURCE_INC_STATE(hdma->Init.SrcInc));
  assert_param(IS_DMA_DESTINATION_INC_STATE(hdma->Init.DstInc));
  assert_param(IS_DMA_SOURCE_DATA_SIZE(hdma->Init.SrcDataSize));
  assert_param(IS_DMA_DESTINATION_DATA_SIZE(hdma->Init.DstDataSize));
  assert_param(IS_DMA_MODE(hdma->Init.Mode));
  assert_param(IS_DMA_PRIORITY(hdma->Init.Priority));

  /* Change DMA peripheral state */
  hdma->State = HAL_DMA_STATE_BUSY;
	
	__HAL_DMA_DISABLE(hdma);

  /* Clear all flags */
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);  
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT); 
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT); 
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR); 

  /* read RawStatus & Interrupt Status to confirm all interrupts have been cleared */

#if (DMA_LLP_ENABLE)
  /* CTLx, The linked lists are set up in memory prior to enabling the channel */
  CLEAR_BIT(((DMA_Channel_TypeDef*)(hdma->Instance))->CTL_H, DMA_CH_CHCTL_DONE);
#endif /* DMA_LLP_ENABLE */  

  /* set the DMA channel mode LLPx, CTLx(DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN), CFGx(DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC) */
#if (DMA_LLP_ENABLE)
  DMA_SetMode((DMA_TypeDef*)(DMA1), hdma->ChannelIndex, hdma->Init.Mode, hdma->Init.LlpAddress);
#else
  DMA_SetMode((DMA_TypeDef*)(DMA1), hdma->ChannelIndex, hdma->Init.Mode, 0);
#endif /* DMA_LLP_ENABLE */
  
  /* Set the DMA Channel configuration CTLx(TTFC, SINC, DINC, SRC_TR_WIDTH, DST_TR_WIDTH, SRC_MSIZE, DST_MSIZE)*/
  MODIFY_REG(hdma->Instance->CTL_L, (DMA_CH_CHCTL_TTFC     |                                     \
                                     DMA_CH_CHCTL_SINC     | DMA_CH_CHCTL_DINC |                    \
                                     DMA_CH_CHCTL_SRCTRW   | DMA_CH_CHCTL_DSTTRW |                  \
                                     DMA_CH_CHCTL_SRCMSIZE | DMA_CH_CHCTL_DSTMSIZE),                \
                                    (hdma->Init.Direction     |                               \
                                     hdma->Init.SrcInc        | hdma->Init.DstInc           | \
                                     hdma->Init.SrcDataSize   | hdma->Init.DstDataSize      | \
                                     hdma->Init.SrcBurstSize  | hdma->Init.DstBurstSize));
  /* CFGx(CH_PRIOR: reset value is x) */                                  
  MODIFY_REG(hdma->Instance->CFG_L, DMA_CH_CHCFG_PRIOR, (hdma->Init.Priority)); 
  
  /* CFGx
   * used default value 
   * - FIFO_MODE: 0 Space/data available for single AHB transfer; 
   * - FCMODE: 0 data pre-fetching is enabled.
   */

  /* CTLx(SRC_GATHER_EN, DST_SCATTER_EN) */
#if (DMA_GATHER_ENABLE)
#endif /* DMA_GATHER_ENABLE */  
#if (DMA_SCATTER_ENABLE)
#endif /* DMA_SCATTER_ENABLE */

#if (DMA_HW_HANDSHAKING)
  /* designst the handshaking interfrace type (no required for memory) */  
  /* CFGx(HS_SEL_SRC, HS_SEL_DST, SRC_PER, DST_PER, SRC_HS_POL, DST_HS_POL) 
   * default is software handshaking
   */
#endif /* DMA_HW_HANDSHAKING */

#if (DMA_LLP_ENABLE)
  /* CFGx(SS_UPD_EN, DS_UPD_EN) */   
#endif
  /* CFGx(PROTCTL) 
  * used reset value : 0x01: all transfer are data accesses.
  */  

#if (DMA_MABRST)
  /* CFGx(MAX_ABRST) */ 
#endif /* DMA_MABRST */

#if (DMA_LOCK_ENABLE)
  /* CFGx(LOCK_B, LOCK_CH, LOCK_B_L, LOCK_CH_L) */
#endif /* DMA_LOCK_ENABLE */  

  /* CGFx(CH_SUSP) 
  * used reset value 0: Not suspended
  */

  /* if gather enabled or scatter enabled, SGRx & DSRx */
#if (DMA_GATHER_ENABLE)
#endif /* DMA_GATHER_ENABLE */  
#if (DMA_SCATTER_ENABLE)
#endif /* DMA_SCATTER_ENABLE */

  /* enable DMAC */
  __HAL_DMA_ENABLE_DMAC(hdma);       

  /* Initialize the error code */
  hdma->ErrorCode = HAL_DMA_ERROR_NONE;

  /* Initialize the DMA state*/
  hdma->State = HAL_DMA_STATE_READY;

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return HAL_OK;
}

/**
  * @brief DeInitialize the DMA peripheral.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma)
{
  /* Check the DMA handle allocation */
  if (NULL == hdma)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));

  /* Disable the selected DMA Channelx */
  __HAL_DMA_DISABLE(hdma);

  /* Clear all flags */
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);  
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT); 
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT); 
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR); 

  /* Clean callbacks */
  hdma->XferCpltCallback = NULL;
  hdma->XferBlockCallback = NULL;
  hdma->XferSrcTranCallback = NULL;
  hdma->XferDstTranCallback = NULL;
  hdma->XferErrorCallback = NULL;

  /* Initialize the error code */
  hdma->ErrorCode = HAL_DMA_ERROR_NONE;

  /* Initialize the DMA state */
  hdma->State = HAL_DMA_STATE_RESET;

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Group2 Input and Output operation functions
  *  @brief   Input and Output operation functions
  *
  * @{
  */

/**
  * @brief Start the DMA Transfer.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @param SrcAddress The source memory Buffer address
  * @param DstAddress The destination memory Buffer address
  * @param DataLength The length of data to be transferred from source to destination
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_DMA_BUFFER_SIZE(DataLength));

  /* Process locked */
  __HAL_LOCK(hdma);

  if (hdma->State == HAL_DMA_STATE_READY)
  {
    /* Change DMA peripheral state */
    hdma->State = HAL_DMA_STATE_BUSY;

    /* Initialize the error code */
    hdma->ErrorCode = HAL_DMA_ERROR_NONE;

    /* Disable the peripheral */
    __HAL_DMA_DISABLE(hdma);

#if (DMA_LLP_ENABLE)
#else
    /* Configure the source, destination address and the data length & clear flags*/
		DMA_SetMode((DMA_TypeDef*)(DMA1), hdma->ChannelIndex, hdma->Init.Mode, 0);
    DMA_SetConfig(hdma, SrcAddress, DstAddress, DataLength);
#endif
    /* Clear all flags */
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);  
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT); 
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT); 
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR); 
		
		__HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_TFR);
		__HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_BLOCK);
		__HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_SRCT);
		__HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_DSTT);
		__HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_ERR);
		
		 __HAL_DMA_ENABLE_IT(hdma); /* for stop multiple blocks transfer */

    __HAL_DMA_NotSuspend(hdma);

    /* Enable the Peripheral */
    __HAL_DMA_ENABLE(hdma);
  }
  else
  {
    /* Change the error code */
    hdma->ErrorCode = HAL_DMA_ERROR_BUSY;

    /* Process Unlocked */
    __HAL_UNLOCK(hdma);

    /* Return error status */
    status = HAL_ERROR;
  }

  return status;
}

/**
  * @brief Start the DMA Transfer with interrupt enabled.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @param SrcAddress The source memory Buffer address
  * @param DstAddress The destination memory Buffer address
  * @param DataLength The length of data to be transferred from source to destination
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_DMA_BUFFER_SIZE(DataLength));

  /* Process locked */
  __HAL_LOCK(hdma);

  if (hdma->State == HAL_DMA_STATE_READY)
  {
    /* Change DMA peripheral state */
    hdma->State = HAL_DMA_STATE_BUSY;
    hdma->ErrorCode = HAL_DMA_ERROR_NONE;

    /* Disable the peripheral */
    __HAL_DMA_DISABLE(hdma);

#if (DMA_LLP_ENABLE)
#else
    /* Configure the source, destination address and the data length & clear flags*/
		DMA_SetMode((DMA_TypeDef*)(DMA1), hdma->ChannelIndex, hdma->Init.Mode, 0);
    DMA_SetConfig(hdma, SrcAddress, DstAddress, DataLength);
#endif    

    /* Enable the transfer complete interrupt */
    /* Enable the block transfer complete interrupt */
    /* Enable the transfer Error interrupt */
    if (NULL != hdma->XferCpltCallback)
    {
      /* Enable the Half transfer complete interrupt as well */
      __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_TFR);
    }
    if (NULL != hdma->XferBlockCallback)
    {
      __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_BLOCK);
    }
    if (NULL != hdma->XferErrorCallback)
    {
      __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_ERR);
    }
    if (NULL != hdma->XferSrcTranCallback)
    {
      __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_SRCT);
    }
    if (NULL != hdma->XferDstTranCallback)
    {
      __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_DSTT);
    }

    /* Clear all flags */
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);  
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT); 
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT); 
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR); 

    /* Enable the DMA channel interrupt */
    __HAL_DMA_ENABLE_IT(hdma);
		
		__HAL_DMA_NotSuspend(hdma);

    /* Enable the DMA channel */
    __HAL_DMA_ENABLE(hdma);
  }
  else
  {
    /* Change the error code */
    hdma->ErrorCode = HAL_DMA_ERROR_BUSY;

    /* Process Unlocked */
    
	  __HAL_UNLOCK(hdma);

    /* Return error status */
    status = HAL_ERROR;
  }
	

  return status;
}

/**
  * @brief Abort the DMA Transfer.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma)
{
  uint32_t tickstart = HAL_GetTick();

  /* Check the DMA peripheral handle */
  if (NULL == hdma)
  {
    return HAL_ERROR;
  }

	if( (READ_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC|DMA_CH_CHCFG_RELDDST))
	  && (hdma->State == HAL_DMA_STATE_BUSY) )
	{
		__HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_TFR);
		__HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_BLOCK);
		
		uMutualCplt = 0;
		uMutualStop = 1;
		do {
			if (((HAL_GetTick() - tickstart) > HAL_MAX_DELAY))
			{
				CLEAR_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC);
        CLEAR_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDDST);
				break;
			}
		} while(uMutualCplt == 0);
		
		uMutualStop = 0;
		uMutualCplt = 0;
	}
	
  /* Check the DMA peripheral state */
  if (hdma->State != HAL_DMA_STATE_BUSY)
  {
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;

		__HAL_DMA_DISABLE(hdma);
		
    /* Process Unlocked */
    __HAL_UNLOCK(hdma);

    //return HAL_ERROR;
  }
  else
  {
    /* Disable the channel */
    __HAL_DMA_Suspend(hdma);

    /* Get tick */
    tickstart = HAL_GetTick();

    /* Check FIFO empty */
    while(!__HAL_DMA_CHECK_FIFOEMPTY(hdma))
    {
      /* Check for the Timeout */
			if (((HAL_GetTick() - tickstart) > HAL_MAX_DELAY))
			{
				/* Update error code */
				hdma->ErrorCode = HAL_DMA_ERROR_TIMEOUT;

				/* Change the DMA state */
				hdma->State = HAL_DMA_STATE_READY;

				/* Process Unlocked */
				__HAL_UNLOCK(hdma);

				return HAL_ERROR;
			}
    }

    __HAL_DMA_DISABLE(hdma);
		
    /* Clear all flags */
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);  
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT); 
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT); 
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR); 

    /* Change the DMA state */
    hdma->State = HAL_DMA_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hdma);

    /* Call User Abort callback */
    if (hdma->XferAbortCallback != NULL)
    {
      hdma->XferAbortCallback(hdma);
    }
  }

  return HAL_OK;
}

/**
  * @brief Aborts the DMA Transfer in Interrupt mode.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();
	int i=0;

  if (NULL == hdma)
  {
    return HAL_ERROR;
  }
	
	if( (READ_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC|DMA_CH_CHCFG_RELDDST))
	  && (hdma->State == HAL_DMA_STATE_BUSY) )
	{
		uMutualCplt = 0;
		uMutualStop = 1;
		do {
			if (((HAL_GetTick() - tickstart) > HAL_MAX_DELAY))
			{
				CLEAR_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC);
        CLEAR_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDDST);
				break;
			}
		} while(uMutualCplt == 0);
		
		uMutualStop = 0;
		uMutualCplt = 0;
	}
	
  if (hdma->State != HAL_DMA_STATE_BUSY)
  {
    /* no transfer ongoing */
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
		
    status = HAL_ERROR;
  }
  else
  {
    /* Disable the channel */
    __HAL_DMA_Suspend(hdma);

    /* Get tick */
    tickstart = HAL_GetTick();

    /* Check FIFO empty */
    while(!__HAL_DMA_CHECK_FIFOEMPTY(hdma))
    {
      /* Check for the Timeout */
			if (((HAL_GetTick() - tickstart) > HAL_MAX_DELAY))
			{
				/* Update error code */
				hdma->ErrorCode = HAL_DMA_ERROR_TIMEOUT;

				/* Change the DMA state */
				hdma->State = HAL_DMA_STATE_READY;

				/* Process Unlocked */
				__HAL_UNLOCK(hdma);

				return HAL_ERROR;
			}
    }
		
    __HAL_DMA_DISABLE(hdma);
		
    /* Clear all flags */
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);  
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT); 
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT); 
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR); 

    /* Change the DMA state */
    hdma->State = HAL_DMA_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hdma);

    /* Call User Abort callback */
    if (hdma->XferAbortCallback != NULL)
    {
      hdma->XferAbortCallback(hdma);
    }
  }
  return status;
}

/**
  * @brief Polling for transfer complete.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @param CompleteLevel Specifies the DMA level complete.
  * @param Timeout Timeout duration.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel, uint32_t Timeout)
{
  uint32_t temp;
  uint32_t tickstart;

  if (hdma->State != HAL_DMA_STATE_BUSY)
  {
    /* no transfer ongoing */
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
    __HAL_UNLOCK(hdma);
    return HAL_ERROR;
  }

  /* Polling mode only supported in single block mode */
  if((READ_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC|DMA_CH_CHCFG_RELDDST)) )
  {
    hdma->ErrorCode = HAL_DMA_ERROR_NOT_SUPPORTED;
    return HAL_ERROR;
  }

  /* Get the level transfer complete flag */
  temp = __HAL_DMA_GET_FLAG(hdma, DMA_FLAG_TFR);

  /* Get tick */
  tickstart = HAL_GetTick();

  while (0U == temp)
  {
    if (0U != __HAL_DMA_GET_FLAG(hdma, DMA_FLAG_ERR))
    {
      /* When a DMA transfer error occurs */
      /* A hardware clear of its EN bits is performed */
      /* Clear all flags */
      __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR);

      /* Update error code */
      hdma->ErrorCode = HAL_DMA_ERROR_TE;

      /* Change the DMA state */
      hdma->State = HAL_DMA_STATE_READY;

      /* Process Unlocked */
      __HAL_UNLOCK(hdma);

      return HAL_ERROR;
    }

    /* Check for the Timeout */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
      {
        /* Update error code */
        hdma->ErrorCode = HAL_DMA_ERROR_TIMEOUT;

        /* Change the DMA state */
        hdma->State = HAL_DMA_STATE_READY;

        /* Process Unlocked */
        __HAL_UNLOCK(hdma);

        return HAL_ERROR;
      }
    }
		
		temp = __HAL_DMA_GET_FLAG(hdma, DMA_FLAG_TFR);
  }

  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);

  return HAL_OK;
}

/**
  * @brief Handle DMA interrupt request.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  */
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma)
{
  /* Transfer Complete Interrupt management ******************************/
  if (__HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_TFR))
  {
		  __HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_TFR);

      /* Change the DMA state */
      hdma->State = HAL_DMA_STATE_READY;

      /* Clear the bust transfer complete flag */
      __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);
		
		  if(READ_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC|DMA_CH_CHCFG_RELDDST))
			{
				if(uMutualStop == 1)
				{
				  uMutualCplt = 1;
				}
			}

		  __HAL_UNLOCK(hdma);

      if (hdma->XferCpltCallback != NULL)
      {
        /* Half transfer callback */
        hdma->XferCpltCallback(hdma);
      }
			__HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_TFR);
  }

  /* Block Transfer Complete Interrupt management ***********************************/
  if (__HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_BLOCK))
  {
		  __HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_BLOCK);

      /* Change the DMA state */
		  if((READ_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC|DMA_CH_CHCFG_RELDDST)) == 0)
			{
        hdma->State = HAL_DMA_STATE_READY;
				
				if(uMutualStop == 1)
				{
				  uMutualCplt = 1;
				}
			}
			else
			{
				if(uMutualStop == 1)
				{
					CLEAR_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC);
          CLEAR_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDDST);
				}
			}
      
      /* Process Unlocked */
      __HAL_UNLOCK(hdma);

      if (hdma->XferBlockCallback != NULL)
      {
        /* Transfer complete callback */
        hdma->XferBlockCallback(hdma);
      }

      /* Clear the transfer complete flag */
      __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);

		  __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_BLOCK);

  }

  /* Source Transaction Complete Interrupt management ***********************************/
  if (__HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_SRCT))
  {
		  __HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_SRCT);

      /* Clear the transfer complete flag */
      __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT);

      /* Process Unlocked */
      __HAL_UNLOCK(hdma);

      if (hdma->XferSrcTranCallback != NULL)
      {
        /* Transfer complete callback */
        hdma->XferSrcTranCallback(hdma);
      }
		  __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_SRCT);

  }

  /* Destination Transaction Complete Interrupt management ***********************************/
  if (__HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_DSTT))
  {
		  __HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_DSTT);

      /* Clear the transfer complete flag */
      __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT);

      /* Process Unlocked */
      __HAL_UNLOCK(hdma);

      if (hdma->XferDstTranCallback != NULL)
      {
        /* Transfer complete callback */
        hdma->XferDstTranCallback(hdma);
      }
		  __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_DSTT);

  }

  /* Transfer Error Interrupt management **************************************/
  if (__HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_ERR))
  {
    /* When a DMA transfer error occurs */
    /* A hardware clear of its EN bits is performed */
	  __HAL_DMA_MASK_FLAG(hdma, DMA_FLAG_ERR);

    /* Clear all flags */
    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR);

    /* Update error code */
    hdma->ErrorCode = HAL_DMA_ERROR_TE;
		
    /* Change the DMA state */
    hdma->State = HAL_DMA_STATE_READY;

    /* Process Unlocked */
    __HAL_UNLOCK(hdma);

    if (hdma->XferErrorCallback != NULL)
    {
      /* Transfer error callback */
      hdma->XferErrorCallback(hdma);
    }
		__HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_ERR);

  }
//  else
//  {
//    /* Nothing To Do */
//  }
  return;
}

/**
  * @brief Register callbacks
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @param CallbackID User Callback identifier
  *                   a HAL_DMA_CallbackIDTypeDef ENUM as parameter.
  * @param pCallback Pointer to private callbacsk function which has pointer to
  *                  a DMA_HandleTypeDef structure as parameter.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)(DMA_HandleTypeDef *_hdma))
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);

  if (hdma->State == HAL_DMA_STATE_READY)
  {
    switch (CallbackID)
    {
      case  HAL_DMA_XFER_CPLT_CB_ID:
        hdma->XferCpltCallback = pCallback;
        break;

      case  HAL_DMA_XFER_BLOCK_CB_ID:
        hdma->XferBlockCallback = pCallback;
        break;

      case  HAL_DMA_XFER_DSTTRAN_CB_ID:
        hdma->XferDstTranCallback = pCallback;
        break;

      case  HAL_DMA_XFER_SRCTRAN_CB_ID:
        hdma->XferSrcTranCallback = pCallback;
        break;

      case  HAL_DMA_XFER_ERROR_CB_ID:
        hdma->XferErrorCallback = pCallback;
        break;

      case  HAL_DMA_XFER_ABORT_CB_ID:
        hdma->XferAbortCallback = pCallback;
        break;
			
      case  HAL_DMA_XFER_ALL_CB_ID:
				break;
			
      default:
        status = HAL_ERROR;
        break;
    }
  }
  else
  {
    status = HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return status;
}

/**
  * @brief UnRegister callbacks
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @param CallbackID User Callback identifier
  *                   a HAL_DMA_CallbackIDTypeDef ENUM as parameter.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);

  if (hdma->State == HAL_DMA_STATE_READY)
  {
    switch (CallbackID)
    {
      case  HAL_DMA_XFER_CPLT_CB_ID:
        hdma->XferCpltCallback = NULL;
        break;

      case  HAL_DMA_XFER_BLOCK_CB_ID:
        hdma->XferBlockCallback = NULL;
        break;

      case  HAL_DMA_XFER_SRCTRAN_CB_ID:
        hdma->XferSrcTranCallback = NULL;
        break;

      case  HAL_DMA_XFER_DSTTRAN_CB_ID:
        hdma->XferDstTranCallback = NULL;
        break;

      case  HAL_DMA_XFER_ERROR_CB_ID:
        hdma->XferErrorCallback = NULL;
        break;

      case  HAL_DMA_XFER_ABORT_CB_ID:
        hdma->XferAbortCallback = NULL;
        break;

      case   HAL_DMA_XFER_ALL_CB_ID:
        hdma->XferCpltCallback = NULL;
        hdma->XferBlockCallback = NULL;
        hdma->XferSrcTranCallback = NULL;
        hdma->XferDstTranCallback = NULL;
        hdma->XferErrorCallback = NULL;
        hdma->XferAbortCallback = NULL;
        break;

      default:
        status = HAL_ERROR;
        break;
    }
  }
  else
  {
    status = HAL_ERROR;
  }

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return status;
}

/**
  * @brief Stop DMA transfer in Auot reload mode
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_StopInReloadMode(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t tickstart = HAL_GetTick();

  /* Process locked */
  //__HAL_LOCK(hdma);
	
	if( (READ_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC|DMA_CH_CHCFG_RELDDST))
	  && (hdma->State == HAL_DMA_STATE_BUSY) )
	{
    if((DMAAUX1->MSKBLOCK & (DMA_MSKBLOCK_EN_0 << hdma->ChannelIndex)) == 0)
		{
	 		__HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_TFR);
		  __HAL_DMA_UNMASK_FLAG(hdma, DMA_FLAG_BLOCK);
   	}
		
		uMutualCplt = 0;
		uMutualStop = 1;
		do {
			if (((HAL_GetTick() - tickstart) > HAL_MAX_DELAY))
			{
				CLEAR_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDSRC);
        CLEAR_BIT(hdma->Instance->CFG_L, DMA_CH_CHCFG_RELDDST);
				break;
			}
		} while(uMutualCplt == 0);
		
		uMutualStop = 0;
		uMutualCplt = 0;
	}

  /* Release Lock */
  //__HAL_UNLOCK(hdma);

  return status;
}

/**
  * @brief Resumr DMA transfer in Auot reload mode
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_ResumeInReloadMode(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  //__HAL_LOCK(hdma);
#if (DMA_LLP_ENABLE)
  DMA_SetMode((DMA_TypeDef*)(DMA1), hdma->ChannelIndex, hdma->Init.Mode, hdma->Init.LlpAddress);
#else
  DMA_SetMode((DMA_TypeDef*)(DMA1), hdma->ChannelIndex, hdma->Init.Mode, 0);
#endif /* DMA_LLP_ENABLE */
  /* Release Lock */
  //__HAL_UNLOCK(hdma);

  return status;
}

/**
  * @brief Periapheral to set RegSrcReg and SglReqSrcReg
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_SourceRequest(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);

  hdma->DMAAux->REQSRC    = ((DMA_REQSRC_WE_0|DMA_REQSRC_EN_0) << hdma->ChannelIndex);
  hdma->DMAAux->SGLREQSRC = ((DMA_SGLREQSRC_WE_0|DMA_SGLREQSRC_EN_0) << hdma->ChannelIndex);

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return status;
}

/**
  * @brief Periapheral to set RegDstReg and SglReqDstReg
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_DestinationRequest(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);

  hdma->DMAAux->REQDST    = (( DMA_REQDST_WE_0|DMA_REQDST_EN_0) << hdma->ChannelIndex);
  hdma->DMAAux->SGLREQDST = (( DMA_SGLREQDST_WE_0|DMA_SGLREQDST_EN_0) << hdma->ChannelIndex);

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return status;
}

/**
  * @brief Periapheral Check RegSrcReg
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_PollingSourceRequest(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);

  status = (READ_BIT(hdma->DMAAux->REQSRC, (DMA_REQSRC_EN_0 << hdma->ChannelIndex))) ? HAL_BUSY : HAL_OK;

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return status;
}

/**
  * @brief Periapheral Check RegDstReg
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_DMA_PollingDestinationRequest(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Process locked */
  __HAL_LOCK(hdma);

  status = (READ_BIT(hdma->DMAAux->REQDST, (DMA_REQDST_EN_0 << hdma->ChannelIndex))) ? HAL_BUSY : HAL_OK;

  /* Release Lock */
  __HAL_UNLOCK(hdma);

  return status;
}

/**
  * @}
  */



/** @defgroup DMA_Exported_Functions_Group3 Peripheral State and Errors functions
 *  @brief    Peripheral State and Errors functions
 *
@verbatim
 ===============================================================================
            ##### Peripheral State and Errors functions #####
 ===============================================================================
    [..]
    This subsection provides functions allowing to
      (+) Check the DMA state
      (+) Get error code

@endverbatim
  * @{
  */

/**
  * @brief Return the DMA handle state.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval HAL state
  */
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma)
{
  /* Return DMA handle state */
  return hdma->State;
}

/**
  * @brief Return the DMA error code.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @retval DMA Error Code
  */
uint32_t HAL_DMA_GetError(DMA_HandleTypeDef *hdma)
{
  /* Return the DMA error code */
  return hdma->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup DMA_Private_Functions
  * @{
  */

/**
  * @brief Sets the DMA Transfer parameter.
  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
  *             the configuration information for the specified DMA Channel.
  * @param SrcAddress The source memory Buffer address
  * @param DstAddress The destination memory Buffer address
  * @param DataLength The length of data in transfer data width to be transferred from source to destination
  */
static void DMA_SetConfig(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  /* Clear all flags */
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);  
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT); 
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT); 
  __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR); 

  /* Configure DMA Channel data length */
  MODIFY_REG(hdma->Instance->CTL_H, DMA_CH_CHCTL_BLOCKTS, ( DataLength << DMA_CH_CHCTL_BLOCKTS_Pos));

  /* Configure DMA Channel destination address */
  hdma->Instance->DAR = DstAddress;

  /* Configure DMA Channel source address */
  hdma->Instance->SAR = SrcAddress;
}

///**
//  * @brief Clear all pending interrupt.
//  * @param hdma Pointer to a DMA_HandleTypeDef structure that contains
//  *             the configuration information for the specified DMA Channel.
//  * @param Timeout timeout
//  * @retval status (0: succeed; x: interrupts )
//  */
//static uint32_t DMA_ClearAllpendingInterupts(DMA_HandleTypeDef *hdma, uint32_t Timeout)
//{
//  uint32_t tickstart;
//  uint32_t result = 0;

//  /* Process locked */
//  __HAL_LOCK(hdma);

//  /* Disable DMA IT */
//  __HAL_DMA_DISABLE_IT(hdma);

//  /* Get tick */
//  tickstart = HAL_GetTick();

//  while(__HAL_DMA_GET_FLAG(hdma, DMA_FLAG_TFR) || __HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_TFR))
//  {
//    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_TFR);  
//    /* Check for the Timeout */
//    if (Timeout != HAL_MAX_DELAY)
//    {
//      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
//      {
//        result |= DMA_FLAG_TFR;
//        break;
//      }
//    }
//  }

//  /* Get tick */
//  tickstart = HAL_GetTick();

//  while(__HAL_DMA_GET_FLAG(hdma, DMA_FLAG_BLOCK) || __HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_BLOCK))
//  {
//    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_BLOCK);
//    /* Check for the Timeout */
//    if (Timeout != HAL_MAX_DELAY)
//    {
//      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
//      {
//        result |= DMA_FLAG_BLOCK;
//        break;
//      }
//    }
//  }

//  /* Get tick */
//  tickstart = HAL_GetTick();

//  while(__HAL_DMA_GET_FLAG(hdma, DMA_FLAG_SRCT) || __HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_SRCT))
//  {
//    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_SRCT); 
//    /* Check for the Timeout */
//    if (Timeout != HAL_MAX_DELAY)
//    {
//      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
//      {
//        result |= DMA_FLAG_SRCT;
//        break;
//      }
//    }
//  }

//  /* Get tick */
//  tickstart = HAL_GetTick();

//  while(__HAL_DMA_GET_FLAG(hdma, DMA_FLAG_DSTT) || __HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_DSTT))
//  {
//    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_DSTT); 
//    /* Check for the Timeout */
//    if (Timeout != HAL_MAX_DELAY)
//    {
//      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
//      {
//        result |= DMA_FLAG_DSTT;
//        break;
//      }
//    }
//  }

//  /* Get tick */
//  tickstart = HAL_GetTick();

//  while(__HAL_DMA_GET_FLAG(hdma, DMA_FLAG_ERR) || __HAL_DMA_GET_IT_FLAG(hdma, DMA_FLAG_ERR))
//  {
//    __HAL_DMA_CLEAR_FLAG(hdma, DMA_FLAG_ERR); 
//    /* Check for the Timeout */
//    if (Timeout != HAL_MAX_DELAY)
//    {
//      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0U))
//      {
//        result |= DMA_FLAG_ERR;
//        break;
//      }
//    }
//  }

//  /* Process Unlocked */
//  __HAL_UNLOCK(hdma);

//  return result;
//}
/**
  * @brief  Set DMA mode circular or normal.
  * @note The circular buffer mode cannot be used if the memory-to-memory
  * data transfer is configured on the selected Channel.
  * @rmtoll LLPx          LOC          DMA_SetMode\n
  *         CTLx          LLP_SRC_EN   DMA_SetMode\n
  *         CTLx          LLP_DST_EN   DMA_SetMode\n
  *         CFGx          RELOAD_SRC   DMA_SetMode\n
  *         CFGx          RELOAD_DST   DMA_SetMode
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref DMA_CHANNEL_0
  *         @arg @ref DMA_CHANNEL_1
  *         @arg @ref DMA_CHANNEL_2
  *         @arg @ref DMA_CHANNEL_3
  *         @arg @ref DMA_CHANNEL_4
  *         @arg @ref DMA_CHANNEL_5
  *         @arg @ref DMA_CHANNEL_6
  *         @arg @ref DMA_CHANNEL_7
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref DMA_SGLBLK
  *         @arg @ref DMA_MULBLK_CSAR_RDAR
  *         @arg @ref DMA_MULBLK_RSAR_CDAR
  *         @arg @ref DMA_MULBLK_RSAR_RDAR
  * @if (DMA_LLP_ENABLE)
  *         @arg @ref DMA_MULBLK_CSAR_LDAR
  *         @arg @ref DMA_MULBLK_RSAR_LDAR
  *         @arg @ref DMA_MULBLK_LSAR_CDAR
  *         @arg @ref DMA_MULBLK_LSAR_RDAR
  *         @arg @ref DMA_MULBLK_LSAR_LDAR
  * @endif
  * @param  LlpAddr LLP address
  */
static void DMA_SetMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Mode, uint32_t LlpAddr)
{
  switch(Mode)
  {
    case DMA_SGLBLK :                                    /*!< Single-block or last transfer of multi-block \
                                                                         LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#if (DMA_LLP_ENABLE)
  		MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, 0);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);     
#else
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);     
#endif		
      break;
    case DMA_MULBLK_CSAR_RDAR :                        /*!< Auto-reload multi-block transfer with contiguous SAR \
                                                                         LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */
#if (DMA_LLP_ENABLE)
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, 0);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, DMA_CH_CHCFG_RELDDST);                                                                 
#else
		  MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, DMA_CH_CHCFG_RELDDST);
#endif
		  break;
    case DMA_MULBLK_RSAR_CDAR :                        /*!< Auto-reload multi-block transfer with contiguous DAR \
                                                                         LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#if (DMA_LLP_ENABLE)
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, 0);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, DMA_CH_CHCFG_RELDSRC);                                                                 
#else
		  MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, DMA_CH_CHCFG_RELDSRC);
#endif
      break;
    case DMA_MULBLK_RSAR_RDAR :                               /*!< Auto-reload multi-block transfer \
                                                                         LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */
#if (DMA_LLP_ENABLE)
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, 0);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC);                                                                 
#else
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC);                                                                 
#endif
      break;
#if (DMA_LLP_ENABLE)		
    case DMA_MULBLK_CSAR_LDAR :                        /*!< Linked list multi-block transfer with contiguous SAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPDST_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
      break;
    case DMA_MULBLK_RSAR_LDAR :                        /*!< Linked list multi-block transfer with auto-reload SAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPDST_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_SRC);                                                                 
      break;
    case DMA_MULBLK_LSAR_CDAR :                        /*!< Linked list multi-block transfer with contiguous DAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPSRC_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
      break;
    case DMA_MULBLK_LSAR_RDAR :                        /*!< Linked list multi-block transfer with auto-reload DAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPSRC_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_DST);                                                                 
      break;
    case DMA_MULBLK_LSAR_LDAR :                               /*!< Linked list multi-block transfer \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPDST_ENABLE | LL_DMA_LLPSRC_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
      break;
#endif			
    default :
#if (DMA_LLP_ENABLE)		
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
#else
      MODIFY_REG(((DMA_Channel_TypeDef *)__HAL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);     
#endif		
      break;
  }
}
/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_DMA_MODULE_ENABLED */
/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
