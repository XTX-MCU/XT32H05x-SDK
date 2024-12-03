/**
  ******************************************************************************
  * @file    xt32h0xx_ll_dma.c
  * @author  Software Team
  * @brief   DMA LL module driver.
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
#include "xt32h0xx_ll_dma.h"
#include "xt32h0xx_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (DMA1) 

/** @defgroup DMA_LL DMA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup DMA_LL_Private_Macros
  * @{
  */
#define IS_LL_DMA_DIRECTION(__VALUE__)          (((__VALUE__) == LL_DMA_DIRECTION_MEMORY_TO_MEMORY_FC_DMAC) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_MEMORY_TO_PERIPH_FC_DMAC) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_PERIPH_TO_MEMORY_FC_DMAC) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_PERIPH_TO_PERIPH_FC_DMAC) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_PERIPH_TO_MEMORY_FC_PERI) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_PERIPH_TO_PERIPH_FC_SRCP) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_MEMORY_TO_PERIPH_FC_PERI) || \
                                                 ((__VALUE__) == LL_DMA_DIRECTION_PERIPH_TO_PERIPH_FC_DSTP))

#define IS_LL_DMA_MODE(__VALUE__)               (((__VALUE__) == LL_DMA_TFRMODE_SGLBLK            ) || \
                                                 ((__VALUE__) == LL_DMA_TFRMODE_MULBLK_ARLD_CONSAR) || \
                                                 ((__VALUE__) == LL_DMA_TFRMODE_MULBLK_ARLD_CONDAR) || \
                                                 ((__VALUE__) == LL_DMA_TFRMODE_MULBLK_ARLD       ) || \
                                                 ((__VALUE__) == LL_DMA_TFRMODE_MULBLK_LLST_CONSAR) || \
                                                 ((__VALUE__) == LL_DMA_TFRMODE_MULBLK_LLST_ARLSAR) || \
                                                 ((__VALUE__) == LL_DMA_TFRMODE_MULBLK_LLST_CONDAR) || \
                                                 ((__VALUE__) == LL_DMA_TFRMODE_MULBLK_LLST_ARLDAR) || \
                                                 ((__VALUE__) == LL_DMA_TFRMODE_MULBLK_LLST       ))

#define IS_LL_DMA_SRCINCMODE(__VALUE__)         (((__VALUE__) == LL_DMA_SINC_INCREMENT) || \
                                                 ((__VALUE__) == LL_DMA_SINC_DECREMENT) || \
                                                 ((__VALUE__) == LL_DMA_SINC_NOCHANGE ))

#define IS_LL_DMA_DSTINCMODE(__VALUE__)         (((__VALUE__) == LL_DMA_DINC_INCREMENT) || \
                                                 ((__VALUE__) == LL_DMA_DINC_DECREMENT) || \
                                                 ((__VALUE__) == LL_DMA_DINC_NOCHANGE ))

#define IS_LL_DMA_SRCDATASIZE(__VALUE__)        (((__VALUE__) == LL_DMA_SRC_TRWIDTH_8  ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_TRWIDTH_16 ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_TRWIDTH_32 ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_TRWIDTH_64 ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_TRWIDTH_128) || \
                                                 ((__VALUE__) == LL_DMA_SRC_TRWIDTH_256))

#define IS_LL_DMA_DSTDATASIZE(__VALUE__)        (((__VALUE__) == LL_DMA_DST_TRWIDTH_8  ) || \
                                                 ((__VALUE__) == LL_DMA_DST_TRWIDTH_16 ) || \
                                                 ((__VALUE__) == LL_DMA_DST_TRWIDTH_32 ) || \
                                                 ((__VALUE__) == LL_DMA_DST_TRWIDTH_64 ) || \
                                                 ((__VALUE__) == LL_DMA_DST_TRWIDTH_128) || \
                                                 ((__VALUE__) == LL_DMA_DST_TRWIDTH_256))

#define IS_LL_DMA_SRCMSIZE(__VALUE__)           (((__VALUE__) == LL_DMA_SRC_MSIZE_1  ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_MSIZE_4  ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_MSIZE_8  ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_MSIZE_16 ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_MSIZE_32 ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_MSIZE_64 ) || \
                                                 ((__VALUE__) == LL_DMA_SRC_MSIZE_128) || \
                                                 ((__VALUE__) == LL_DMA_SRC_MSIZE_256))

#define IS_LL_DMA_DSTMSIZE(__VALUE__)           (((__VALUE__) == LL_DMA_DST_MSIZE_1  ) || \
                                                 ((__VALUE__) == LL_DMA_DST_MSIZE_4  ) || \
                                                 ((__VALUE__) == LL_DMA_DST_MSIZE_8  ) || \
                                                 ((__VALUE__) == LL_DMA_DST_MSIZE_16 ) || \
                                                 ((__VALUE__) == LL_DMA_DST_MSIZE_32 ) || \
                                                 ((__VALUE__) == LL_DMA_DST_MSIZE_64 ) || \
                                                 ((__VALUE__) == LL_DMA_DST_MSIZE_128) || \
                                                 ((__VALUE__) == LL_DMA_DST_MSIZE_256))

#define IS_LL_DMA_BLOCKSIZE(__VALUE__)             ((__VALUE__)  <= 0x00000FFFU)

#define IS_LL_DMA_PRIORITY(__VALUE__)           (((__VALUE__) == LL_DMA_CH_PRIOR_0) || \
                                                 ((__VALUE__) == LL_DMA_CH_PRIOR_1) || \
                                                 ((__VALUE__) == LL_DMA_CH_PRIOR_2) || \
                                                 ((__VALUE__) == LL_DMA_CH_PRIOR_3) || \
                                                 ((__VALUE__) == LL_DMA_CH_PRIOR_4) || \
                                                 ((__VALUE__) == LL_DMA_CH_PRIOR_5) || \
                                                 ((__VALUE__) == LL_DMA_CH_PRIOR_6) || \
                                                 ((__VALUE__) == LL_DMA_CH_PRIOR_7))

#define IS_LL_DMA_ALL_CHANNEL_INSTANCE(INSTANCE, CHANNEL)  ((((INSTANCE) == DMA1) && \
                                                            (((CHANNEL) == LL_DMA_CHANNEL_0) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_1) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_2) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_3) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_4) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_5) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_6) || \
                                                             ((CHANNEL) == LL_DMA_CHANNEL_7))))
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup DMA_LL_Exported_Functions
  * @{
  */

/** @addtogroup DMA_LL_Exported_Functions_Group4
  * @{
  */

/**
  * @brief  De-initialize the DMA registers to their default reset values.
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_0
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  *         @arg @ref LL_DMA_CHANNEL_ALL
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DMA registers are de-initialized
  *          - ERROR: DMA registers are not de-initialized
  */
ErrorStatus LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ErrorStatus status = SUCCESS;

  /* Check the DMA Instance DMAx and Channel parameters*/
  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel) || (Channel == LL_DMA_CHANNEL_ALL));

  if (Channel == LL_DMA_CHANNEL_ALL)
  {
    if (DMAx == DMA1)
    {
    }
    else
    {
      status = ERROR;
    }
  }
  else
  {
    DMA_Channel_TypeDef *tmp;
  
    tmp = (DMA_Channel_TypeDef *)(__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel));
  
    /* Disable the selected DMAx_Channely */
    LL_DMA_DisableChannel(DMAx, Channel);

    /* Reset DMAx_Channely control register */
    WRITE_REG(tmp->CTL_L, 0x00004900UL);
    WRITE_REG(tmp->CTL_H, 0x00000002UL);

    /* Reset DMAx_Channely peripheral address register */
    WRITE_REG(tmp->SAR, 0U);

    /* Reset DMAx_Channely memory address register */
    WRITE_REG(tmp->DAR, 0U);

    /* Reset all interrupts */
    LL_DMA_ClearFlag_Tfr(DMAx, Channel);
    LL_DMA_ClearFlag_Block(DMAx, Channel);
    LL_DMA_ClearFlag_SrcTran(DMAx, Channel);
    LL_DMA_ClearFlag_DstTran(DMAx, Channel);
    LL_DMA_ClearFlag_Error(DMAx, Channel);
  
  }

  return status;
}

/**
  * @brief  Initialize the DMA registers according to the specified parameters in DMA_InitStruct.
  * @note   To convert DMAx_Channely Instance to DMAx Instance and Channely, use helper macros :
  *         @arg @ref __LL_DMA_GET_INSTANCE
  *         @arg @ref __LL_DMA_GET_CHANNEL
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  DMA_InitStruct pointer to a @ref LL_DMA_InitTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: DMA registers are initialized
  *          - ERROR: Not applicable
  */
ErrorStatus LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct)
{
  /* Check the DMA Instance DMAx and Channel parameters*/
  assert_param(IS_LL_DMA_ALL_CHANNEL_INSTANCE(DMAx, Channel));

  /* Check the DMA parameters from DMA_InitStruct */
  assert_param(IS_LL_DMA_DIRECTION(DMA_InitStruct->Direction));
  assert_param(IS_LL_DMA_MODE(DMA_InitStruct->Mode));
  assert_param(IS_LL_DMA_SRCINCMODE(DMA_InitStruct->SrcIncMode));
  assert_param(IS_LL_DMA_DSTINCMODE(DMA_InitStruct->DstIncMode));
  assert_param(IS_LL_DMA_SRCDATASIZE(DMA_InitStruct->SrcDataSize));
  assert_param(IS_LL_DMA_DSTDATASIZE(DMA_InitStruct->DstDataSize));
  assert_param(IS_LL_DMA_SRCMSIZE(DMA_InitStruct->SrcBurstSize));
  assert_param(IS_LL_DMA_DSTMSIZE(DMA_InitStruct->DstBurstSize));
  assert_param(IS_LL_DMA_BLOCKSIZE(DMA_InitStruct->BlockSize));
  //assert_param(IS_LL_DMA_PERIPHREQUEST(DMA_InitStruct->PeriphRequest));
  assert_param(IS_LL_DMA_PRIORITY(DMA_InitStruct->Priority));

#if (DMA_LLP_ENABLE)
  /* CTLx, The linked lists are set up in memory prior to enabling the channel */
  CLEAR_BIT(((DMA_Channel_TypeDef*)(hdma->Instance))->CTL_H, DMA_CH_CHCTL_DONE);
#endif /* DMA_LLP_ENABLE */  

  /*---------------------------- DMAx channel CTLx & CFGx Configuration ------------------------
   * Configure DMAx_Channely: data transfer direction, data transfer mode,
   *                          peripheral and memory increment mode,
   *                          data size alignment and  priority level with parameters :
   * - Direction:    DMA_CH_CHCTL_TTFC
   * - SrcIncMode:   DMA_CH_CHCTL_SINC 
   * - DstIncMode:   DMA_CH_CHCTL_DINC 
   * - SrcDataSize:  DMA_CH_CHCTL_SRCTRW
   * - DstDataSize:  DMA_CH_CHCTL_DSTTRW
   * - SrcBurstSize: DMA_CH_CHCTL_SRCMSIZE
   * - DstBurstSize: DMA_CH_CHCTL_DSTMSIZE
   * - IntEn:        DMA_CH_CHCTL_INTEN
   * - BlockSize:    DMA_CH_CHCTL_BLOCKTS (H)
   * - Priority:     DMA_CH_CHCFG_PRIOR
   * - FifoEn:       DMA_CH_CHCFG_FIFOMODE (H)
   * - FlowControl:  DMA_CH_CHCFG_FCMODE (H)
   */
  LL_DMA_ConfigTransfer(DMAx, Channel, DMA_InitStruct->Direction              | \
                        DMA_InitStruct->SrcIncMode   | \
                        DMA_InitStruct->DstIncMode   | \
                        DMA_InitStruct->SrcDataSize  | \
                        DMA_InitStruct->DstDataSize  | \
                        DMA_InitStruct->SrcBurstSize | \
                        DMA_InitStruct->DstBurstSize | \
                        DMA_InitStruct->IntEn,         \
                        DMA_InitStruct->BlockSize,     \
                        DMA_InitStruct->Priority,
                        0);
                       // DMA_InitStruct->FifoEn       | \
                       // DMA_InitStruct->FlowControl);

  /*-------------------------- DMAx Mode Configuration -------------------------
   * Configure data trafer mode with parameter :
   * - Mode:       DMA_CH_CHCTL_LLPSRCEN bit
   *               DMA_CH_CHCTL_LLPDSTEN bit
   *               DMA_CH_CHCFG_RELDSRC bit
   *               DMA_CH_CHCFG_RELDDST bit
   * - LlpAddress: DMA_CHLLP_LOC bits
   */
  #if DMA_LLP_ENABLE
  LL_DMA_SetMode(DMAx, Channel, DMA_InitStruct->Mode, DMA_InitStruct->LlpAddress);
  #else
  LL_DMA_SetMode(DMAx, Channel, DMA_InitStruct->Mode, 0);
  #endif
  #if (DMA_MASTER_NUMBER > 1)
  /*-------------------------- DMAx Channel CTLx Configuration -------------------------
   * Configure source/destination master select :
   * - SMS
   * - DMS
   */
  LL_DMA_SetSourceMaster(DMAx, Channel, DMA_InitStruct->Sms); 
  LL_DMA_SetDestinationMaster(DMAx, Channel, DMA_InitStruct->Dms); 
  #endif

  #if (DMA_GATHER_ENABLE)
  /*-------------------------- DMAx Channel CTLx Configuration -------------------------
   * Configure source gather enable :
   * - SRC_GATHER_EN: reset is disable
   */
  LL_DMA_SrcGather_Enable(DMAx, Channel); 
  LL_DMA_ConfigSrcGather(DMAx, Channel, DMA_InitStruct->SrcGather);
  #endif
  #if (DMA_SCATTER_ENABLE)
  /*-------------------------- DMAx Channel CTLx Configuration -------------------------
   * Configure detination scatter enable :
   * - DST_SCATTER_EN: reset is disable
   */
  LL_DMA_DstScatter_Enable(DMAx, Channel); 
  LL_DMA_ConfigDstScatter(DMAx, Channel, DMA_InitStruct->DstScatter);
  #endif

  #if DMA_LLP_ENABLE
  /*-------------------------- DMAx Channel CFGx Configuration -------------------------
   * Configure Source/destination status update enable :
   * - SS_UPD_EN: reset is disable
   * - DS_UPD_EN: reset is disable
   */
   LL_DMA_EnableSourceStatusUpdate(DMAx, Channel);
   LL_DMA_EnableDestinationStatusUpdate(DMAx, Channel);
   /*---------- Prepare LLP -------------*/
   /* Set LLPx */
  #endif /* DMA_LLP_ENABLE */

  #if DMA_MABRST
  /*-------------------------- DMAx Channel CFGx Configuration -------------------------
   * Configure maximum ANBA burst legth :
   * - MAX_ABRST: 0 indicates not limiting
   */
   LL_DMA_SetMaxAMBABurstLength(DMAx, Channel, 0);
  #endif /* DMA_MABRST */

  #if DMA_HW_HANDSHAKING
  /*-------------------------- DMAx Channel CFGx Configuration -----------------------
   * Config handshaking (reset si software handshaking)
   * HS_SEL_SRC: reset is 1 software
   * HS_SEL_DST: reset is 1 software
   * SRC_HS_POL: reset is 0 high
   * DST_HS_POL: reset is 0 high
   * DEST_PER: reset is 0 no assign
   * SRC_PER: reset is 0 no assign
   */
  LL_DMA_SetChannelSourceHSMode(DMAx, Channel, DMA_InitStruct->SrcHSMode);
  LL_DMA_SetChannelDestinationHSMode(DMAx, Channel, DMA_InitStruct->DstHSMode); 
  LL_DMA_SetChannelSourceHSPol(DMAx, Channel, DMA_InitStruct->SrcHSPol);
  LL_DMA_SetChannelDestinationHSPol(DMAx, Channel, DMA_InitStruct->DstHSPol);  
  LL_DMA_SetChannelSourceHSIF(DMAx, Channel, DMA_InitStruct->SrcHSIF); 
  LL_DMA_SetChannelDestinationHSIF(DMAx, Channel, DMA_InitStruct->DstHSIF);
  #endif /* DMA_HW_HANDSHAKING */

  #if (DMA_LOCK_ENABLE)
  /*-------------------------- DMAx Channel CFGx Configuration -------------------------
   * Configure lock :
   * - LOCK_B: 0 unlock
   * - LOCK_B_L: 0 over complete DMA transfer
   * - LOCK_CH: 0 unlock
   * - LOCK_CH_L: 0 over complete DMA transfer
   */
  #endif

  /*-------------------------- DMAx DARx Configuration -------------------------
   * Configure the memory or destination base address with parameter :
   * - MemoryOrM2MDstAddress: DMA_DAR[31:0] bits
   */
  LL_DMA_SetDestinationAddress(DMAx, Channel, DMA_InitStruct->DstAddress);

  /*-------------------------- DMAx SARx Configuration -------------------------
   * Configure the peripheral or source base address with parameter :
   * - PeriphOrM2MSrcAddress: DMA_SAR[31:0] bits
   */
  LL_DMA_SetSourceAddress(DMAx, Channel, DMA_InitStruct->SrcAddress);

  /*--------------------------- DMAx ChEn Configuration ----------------------
   * Enable DMA channel
   */
  LL_DMA_EnableChannel(DMAx, Channel);

  return SUCCESS;
}

/**
  * @brief  Set each @ref LL_DMA_InitTypeDef field to default value.
  * @param  DMA_InitStruct Pointer to a @ref LL_DMA_InitTypeDef structure.
  */
void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct)
{
  /* Set DMA_InitStruct fields to default values */
  DMA_InitStruct->SrcAddress             = 0x00000000UL;
  DMA_InitStruct->DstAddress             = 0x00000000UL;
  DMA_InitStruct->Direction              = LL_DMA_MEMORY_TO_MEMORY_FC_DMAC;
  DMA_InitStruct->Mode                   = LL_DMA_TFRMODE_SGLBLK;
#if (DMA_LLP_ENABLE)  
  DMA_InitStruct->LlpAddress             = 0x00000000UL;
#endif  
  DMA_InitStruct->SrcIncMode             = LL_DMA_SINC_INCREMENT;
  DMA_InitStruct->DstIncMode             = LL_DMA_DINC_INCREMENT;
  DMA_InitStruct->SrcDataSize            = LL_DMA_SRC_TRWIDTH_8;
  DMA_InitStruct->DstDataSize            = LL_DMA_DST_TRWIDTH_8;
  DMA_InitStruct->SrcBurstSize           = LL_DMA_SRC_MSIZE_1;
  DMA_InitStruct->DstBurstSize           = LL_DMA_DST_MSIZE_1;
  DMA_InitStruct->BlockSize              = 2;
  DMA_InitStruct->Priority               = LL_DMA_CH_PRIOR_0;
  DMA_InitStruct->IntEn                  = 0;

#if DMA_HW_HANDSHAKING
  DMA_InitStruct->SrcHSMode              = LL_DMA_HS_SRC_SW;
  DMA_InitStruct->DstHSMode              = LL_DMA_HS_DST_SW;
  DMA_InitStruct->SrcHSPol               = LL_DMA_SRC_HS_POL_HIGH;
  DMA_InitStruct->DstHSPol               = LL_DMA_DST_HS_POL_HIGH;
  DMA_InitStruct->SrcHSIF                = 0;
  DMA_InitStruct->DstHSIF                = 0;
#endif /* DMA_HW_HANDSHAKING */
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

#endif /* DMA1 */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
