/**
  ******************************************************************************
  * @file    xt32h0xx_dma.c
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Direct Memory Access controller (DMA):
  *           + Initialization and Configuration
  *           + Data Counter
  *           + Interrupts and flags management
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
#include "xt32h0xx_dma.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup DMA DMA
  * @brief DMA driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Exported functions ---------------------------------------------------------*/
/** @defgroup DMA_Exported_Functions DMA Exported Functions
  * @{
  */

/** @defgroup DMA_Exported_Functions_Group1 Initialization and Configuration functions
 *  @brief   Initialization and Configuration functions
 *
  * @{
  */
    
/**
  * @brief  Deinitializes the DMAy Channelx registers to their default reset
  *         values.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and 
  *         x can be 1 to 7 for DMA1 to select the DMA Channel.
  */
void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx)
{
  /* Check the parameters */
  assert_param(IS_DMA_ALL_CHANNEL(DMAy_Channelx));

  /* Disable the selected DMAy Channelx */
  DMAAUX1->CHEN &= (uint32_t)~((uint32_t)((DMA_CHEN_WE_0 | DMA_CHEN_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));

  /* Clear interrupt */
  DMAAUX1->CLRTFR = ((uint32_t)((DMA_CLRTFR_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRBLOCK = ((uint32_t)((DMA_CLRBLOCK_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRSRCTRAN = ((uint32_t)((DMA_CLRSRCTRAN_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRDSTTRAN = ((uint32_t)((DMA_CLRDSTTRAN_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRERR = ((uint32_t)((DMA_CLRERR_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));

}

/**
  * @brief  Initializes the DMAy Channelx according to the specified parameters 
  *         in the DMA_InitStruct.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  * @param  DMA_InitStruct: pointer to a DMA_InitTypeDef structure that contains
  *         the configuration information for the specified DMA Channel.
  */
void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct)
{
  uint32_t tempr = 0;

  /* Check the parameters */
  assert_param(IS_DMA_ALL_CHANNEL(DMAy_Channelx));
  assert_param(IS_DMA_TRANSFER_DIRECT(DMA_InitStruct->DMA_DIR));
  assert_param(IS_DMA_SOURCE_INC_STATE(DMA_InitStruct->DMA_SourceInc));
  assert_param(IS_DMA_DESTINATION_INC_STATE(DMA_InitStruct->DMA_DestinationInc));
  assert_param(IS_DMA_SRCDATA_SIZE(DMA_InitStruct->DMA_SourceDataSize));
  assert_param(IS_DMA_DSTDATA_SIZE(DMA_InitStruct->DMA_DestinationDataSize));
  assert_param(IS_DMA_SRCBUSRT_SIZE(DMA_InitStruct->DMA_SourceBurstLength));
  assert_param(IS_DMA_DSTBUSRT_SIZE(DMA_InitStruct->DMA_DestinationBurstLength));
  assert_param(IS_DMA_MODE(DMA_InitStruct->DMA_Mode));
  assert_param(IS_DMA_PRIORITY(DMA_InitStruct->DMA_Priority));

  assert_param(IS_DMA_SRCHS_POLARITY(DMA_InitStruct->DMA_SourceHandShaking.HSPol));
  assert_param(IS_DMA_DSTHS_POLARITY(DMA_InitStruct->DMA_DestinationHandShaking.HSPol));
  assert_param(IS_DMA_SRCHS_MODE(DMA_InitStruct->DMA_SourceHandShaking.HSMode));
  assert_param(IS_DMA_DSTHS_MODE(DMA_InitStruct->DMA_DestinationHandShaking.HSMode));
  assert_param(IS_DMA_SRCHS_IF(DMA_InitStruct->DMA_SourceHandShaking.HSIF));
  assert_param(IS_DMA_DSTHS_IF(DMA_InitStruct->DMA_DestinationHandShaking.HSIF));

  /* Disable the selected DMAy Channelx */
  DMAAUX1->CHEN &= (uint32_t)~((uint32_t)((DMA_CHEN_WE_0 | DMA_CHEN_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));

  /*--------------------------- DMAy Channelx CTL & CFG Configuration ----------------*/
  tempr = DMAy_Channelx->CTL_L;

  if(DMA_InitStruct->DMA_Mode == DMA_SGLBLK)
  {
    tempr &= (uint32_t)~((uint32_t)( DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC));
  }
  else
  {
    tempr |= ((uint32_t)( DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC));
  }

  tempr &= (uint32_t)~((uint32_t)(DMA_CH_CHCTL_TTFC     |                                     \
                                  DMA_CH_CHCTL_SINC     | DMA_CH_CHCTL_DINC |                    \
                                  DMA_CH_CHCTL_SRCTRW   | DMA_CH_CHCTL_DSTTRW |                  \
                                  DMA_CH_CHCTL_SRCMSIZE | DMA_CH_CHCTL_DSTMSIZE));
  tempr |= ((uint32_t)(DMA_InitStruct->DMA_DIR | \
                       DMA_InitStruct->DMA_SourceInc | DMA_InitStruct->DMA_DestinationInc | \
                       DMA_InitStruct->DMA_SourceDataSize | DMA_InitStruct->DMA_DestinationDataSize | \
                       DMA_InitStruct->DMA_SourceBurstLength | DMA_InitStruct->DMA_DestinationBurstLength)) ;                               
  DMAy_Channelx->CTL_L = tempr;

  tempr = DMAy_Channelx->CFG_L;
  tempr &= (uint32_t)~((uint32_t)(DMA_CH_CHCFG_PRIOR | \
                                  DMA_CH_CHCFG_SRCHS | DMA_CH_CHCFG_DSTHS | \
                                  DMA_CH_CHCFG_SRCHSPOL | DMA_CH_CHCFG_DSTHSPOL));
  tempr |= (uint32_t)(DMA_InitStruct->DMA_Priority | \
                      DMA_InitStruct->DMA_SourceHandShaking.HSMode | DMA_InitStruct->DMA_DestinationHandShaking.HSMode | \
                      DMA_InitStruct->DMA_SourceHandShaking.HSPol | DMA_InitStruct->DMA_DestinationHandShaking.HSPol);
  DMAy_Channelx->CFG_L = tempr;

  tempr = DMAy_Channelx->CFG_H;
  tempr &= (uint32_t)~((uint32_t)(DMA_CH_CHCFG_SRCPER | DMA_CH_CHCFG_DSTPER));
  tempr |= (uint32_t)((DMA_InitStruct->DMA_SourceHandShaking.HSIF << DMA_CH_CHCFG_SRCPER_Pos) | \
                      (DMA_InitStruct->DMA_DestinationHandShaking.HSIF << DMA_CH_CHCFG_DSTPER_Pos));
  DMAy_Channelx->CFG_H = tempr;

  /*Enable DMAC */
  DMAAUX1->DMACFG |= (uint32_t)DMA_DMACFG_EN;
}

/**
  * @brief  Fills each DMA_InitStruct member with its default value.
  * @param  DMA_InitStruct: pointer to a DMA_InitTypeDef structure which will
  *         be initialized.
  */
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct)
{
/*-------------- Reset DMA init structure parameters values ------------------*/
  DMA_InitStruct->DMA_DIR = DMA_MEMORY_TO_MEMORY_FC_DMAC;
  DMA_InitStruct->DMA_SourceInc = DMA_SINC_INCREMENT;
  DMA_InitStruct->DMA_DestinationInc = DMA_DINC_INCREMENT;
  DMA_InitStruct->DMA_SourceDataSize = DMA_SDATAALIGN_WORD;
  DMA_InitStruct->DMA_DestinationDataSize = DMA_DDATAALIGN_WORD;
  DMA_InitStruct->DMA_SourceBurstLength = DMA_SRC_MSIZE_1;
  DMA_InitStruct->DMA_DestinationBurstLength = DMA_DST_MSIZE_1;
  DMA_InitStruct->DMA_Mode = DMA_SGLBLK;
  DMA_InitStruct->DMA_Priority = DMA_PRIORITY_0;
  DMA_InitStruct->DMA_SourceHandShaking.HSMode = DMA_SRCHS_SW;
  DMA_InitStruct->DMA_SourceHandShaking.HSPol = DMA_SRCHS_POL_HIGH;
  DMA_InitStruct->DMA_SourceHandShaking.HSIF = 0;
  DMA_InitStruct->DMA_DestinationHandShaking.HSMode = DMA_DSTHS_SW;
  DMA_InitStruct->DMA_DestinationHandShaking.HSPol = DMA_DSTHS_POL_HIGH;
  DMA_InitStruct->DMA_DestinationHandShaking.HSIF = 0;
}

/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group2 Operation Functions
  * @{
  */

/**
  * @brief  Enables DMAC.
  */
void DMA_EnableDMAC(void)
{
  DMAAUX1->DMACFG |= (uint32_t)DMA_DMACFG_EN;
}

/**
  * @brief  Disables DMAC.
  */
void DMA_DisableDMAC(void)
{
  DMAAUX1->DMACFG = 0;
}

/**
  * @brief  Enables DMAy Channelx.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  */
void DMA_EnableChannel(DMA_Channel_TypeDef* DMAy_Channelx)
{
  DMAAUX1->CHEN |= ((uint32_t)((DMA_CHEN_WE_0 | DMA_CHEN_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
}
/**
  * @brief  Disables the specified DMAy Channelx.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  */
void DMA_DisableChannel(DMA_Channel_TypeDef* DMAy_Channelx)
{
  DMAAUX1->CHEN &= (uint32_t)~((uint32_t)((DMA_CHEN_WE_0 | DMA_CHEN_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
}

/**
  * @brief  Config DMA channel and start.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  * @param  DMA_CfgStruct: new state of the DMAy Channelx. 
  *         This parameter can be: ENABLE or DISABLE.
  */
void DMA_Config(DMA_Channel_TypeDef* DMAy_Channelx, DMA_CfgTypeDef* DMA_CfgStruct)
{
  uint32_t tempr = 0;

  DMAAUX1->CHEN &= (uint32_t)~((uint32_t)((DMA_CHEN_WE_0 | DMA_CHEN_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));

  DMAy_Channelx->SAR = DMA_CfgStruct->DMA_SourceBaseAddr;
  DMAy_Channelx->DAR = DMA_CfgStruct->DMA_DestinationBaseAddr;
  
  tempr = DMAy_Channelx->CTL_H;
  tempr &= (uint32_t)~((uint32_t)DMA_CH_CHCTL_BLOCKTS);
  tempr |= ((uint32_t)(DMA_CfgStruct->TransferSize << DMA_CH_CHCTL_BLOCKTS_Pos));
  DMAy_Channelx->CTL_H = tempr;

  /* Clear all interrupts */
  DMAAUX1->CLRTFR = ((uint32_t)((DMA_CLRTFR_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRBLOCK = ((uint32_t)((DMA_CLRBLOCK_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRSRCTRAN = ((uint32_t)((DMA_CLRSRCTRAN_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRDSTTRAN = ((uint32_t)((DMA_CLRDSTTRAN_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRERR = ((uint32_t)((DMA_CLRERR_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));

  DMAy_Channelx->CFG_L &= (uint32_t)~((uint32_t)DMA_CH_CHCFG_SUSP);

  DMAAUX1->CHEN |= ((uint32_t)((DMA_CHEN_WE_0 | DMA_CHEN_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
}

/**
  * @brief  Abort trandfer for DMA channel.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  */
void DMA_Abort(DMA_Channel_TypeDef* DMAy_Channelx)
{
  uint32_t wait = 500;

  DMAy_Channelx->CFG_L |= ((uint32_t)DMA_CH_CHCFG_SUSP);

  while(((DMAy_Channelx->CFG_L & DMA_CH_CHCFG_FIFOE)==RESET)&&(wait>0))
  {
    wait--;
  }

  DMAAUX1->CHEN &= (uint32_t)~((uint32_t)((DMA_CHEN_WE_0 | DMA_CHEN_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  
  /* Clear all interrupts */
  DMAAUX1->CLRTFR = ((uint32_t)((DMA_CLRTFR_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRBLOCK = ((uint32_t)((DMA_CLRBLOCK_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRSRCTRAN = ((uint32_t)((DMA_CLRSRCTRAN_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRDSTTRAN = ((uint32_t)((DMA_CLRDSTTRAN_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  DMAAUX1->CLRERR = ((uint32_t)((DMA_CLRERR_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
}

/**
  * @brief  Source Request.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  */
void DMA_SourceRequest(DMA_Channel_TypeDef* DMAy_Channelx)
{
  DMAAUX1->SGLREQSRC |= ((uint32_t)((DMA_SGLREQSRC_WE_0 | DMA_SGLREQSRC_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  __NOP();
  __NOP();
  __NOP();
  __NOP();
  DMAAUX1->REQSRC |=  ((uint32_t)((DMA_REQSRC_WE_0 | DMA_REQSRC_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
}

/**
  * @brief  Destination Request.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  */
void DMA_DestinationRequest(DMA_Channel_TypeDef* DMAy_Channelx)
{
  DMAAUX1->SGLREQDST |= ((uint32_t)((DMA_SGLREQDST_WE_0 | DMA_SGLREQDST_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  __NOP();
  __NOP();
  __NOP();
  __NOP();
  DMAAUX1->REQDST |=  ((uint32_t)((DMA_REQDST_WE_0 | DMA_REQDST_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
}

/**
  * @}
  */


/** @defgroup DMA_Exported_Functions_Group3 Interrupts and flags management functions
  *  @brief   Interrupts and flags management functions 
  *
  * @{
  */
/**
  * @brief  enable interrupt.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  */
void DMA_ITEnable(DMA_Channel_TypeDef* DMAy_Channelx)
{
  DMAy_Channelx->CTL_L |= (uint32_t)DMA_CH_CHCTL_INTEN;
}

/**
  * @brief  Disable interrupt.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  */
void DMA_ITDisable(DMA_Channel_TypeDef* DMAy_Channelx)
{
  DMAy_Channelx->CTL_L &= (uint32_t)~((uint32_t)DMA_CH_CHCTL_INTEN);
}

/**
  * @brief  Enables or disables the specified DMAy Channelx interrupts.
  * @param  DMAy_Channelx: where y can be 1 to select the DMA and x can be 1 to 7
  *         for DMA1 to select the DMA Channel and 1 to 5 for DMA2 to select the DMA Channel.
  * @param  DMA_IT: specifies the DMA interrupts sources to be enabled
  *         or disabled. 
  *          This parameter can be any combination of the following values:
  *            @arg @ref DMA_IT_TFR    
  *            @arg @ref DMA_IT_BLOCK  
  *            @arg @ref DMA_IT_SRCTRAN
  *            @arg @ref DMA_IT_DSTTRAN
  *            @arg @ref DMA_IT_ERR    
  * @param  DMA_IT_MASK: new state of the specified DMA interrupts.
  *         This parameter can be: ENABLE or DISABLE.
  */
void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT, uint32_t DMA_IT_MASK)
{
  uint32_t * reg = ((uint32_t*)&(DMAAUX1->MSKTFR)) + DMA_IT * 2;

  /* Check the parameters */
  assert_param(IS_DMA_ALL_CHANNEL(DMAy_Channelx));
  assert_param(IS_DMA_IT(DMA_IT));
  assert_param(IS_DMA_IT_MASK(DMA_IT_MASK));

  if (DMA_IT_MASK == DMA_IT_UNMASKED)
  {
    /* Enable the selected DMA interrupts */
    *reg |= ((uint32_t)((DMA_MSKTFR_WE_0 | DMA_MSKTFR_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  }
  else
  {
    /* Disable the selected DMA interrupts */
    *reg &= (uint32_t)~((uint32_t)((DMA_MSKTFR_WE_0 | DMA_MSKTFR_EN_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
  }
}

/**
  * @brief  Checks whether the specified DMAy Channelx flag is set or not.
  * @param  DMAy_Channelx Dma channel
  * @param  DMA_IT: specifies the flag to check.
  *          This parameter can be one of the following values:
  *            @arg @ref DMA_IT_TFR    
  *            @arg @ref DMA_IT_BLOCK  
  *            @arg @ref DMA_IT_SRCTRAN
  *            @arg @ref DMA_IT_DSTTRAN
  *            @arg @ref DMA_IT_ERR    
  * @retval The new state of DMA_FLAG (SET or RESET).
  */
FlagStatus DMA_GetFlagStatus(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT)
{
  FlagStatus bitstatus = RESET;
  uint32_t * reg = ((uint32_t*)&(DMAAUX1->RAWTFR)) + DMA_IT * 2;
  
  /* Check the parameters */
  assert_param(IS_DMA_ALL_CHANNEL(DMAy_Channelx));
  assert_param(IS_DMA_IT(DMA_IT));

  /* Check the status of the specified DMAy flag */
  if ((*reg &  (DMA_RAWTFR_CH_0 << GET_DMA_CHANNEL_INDEX(DMAy_Channelx))) != (uint32_t)RESET)
  {
    /* DMAy_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* DMAy_FLAG is reset */
    bitstatus = RESET;
  }
  
  /* Return the DMAy_FLAG status */
  return  bitstatus;
}

/**
  * @brief  Clears the DMAy Channelx's pending flags.
  * @param  DMAy_Channelx Dma channel
  * @param  DMA_IT: specifies the flag to check.
  *          This parameter can be one of the following values:
  *            @arg @ref DMA_IT_TFR    
  *            @arg @ref DMA_IT_BLOCK  
  *            @arg @ref DMA_IT_SRCTRAN
  *            @arg @ref DMA_IT_DSTTRAN
  *            @arg @ref DMA_IT_ERR    
  *
  */
void DMA_ClearFlag(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT)
{
  uint32_t * reg = ((uint32_t*)&(DMAAUX1->CLRTFR)) + DMA_IT * 2;
  
  /* Check the parameters */
  assert_param(IS_DMA_ALL_CHANNEL(DMAy_Channelx));
  assert_param(IS_DMA_IT(DMA_IT));
  
  *reg = ((uint32_t)((DMA_CLRTFR_CH_0) << GET_DMA_CHANNEL_INDEX(DMAy_Channelx)));
}

/**
  * @brief  Checks whether the specified DMAy Channelx interrupt has occurred or not.
  * @param  DMAy_Channelx Dma channel
  * @param  DMA_IT: specifies the flag to check.
  *          This parameter can be one of the following values:
  *            @arg @ref DMA_IT_TFR    
  *            @arg @ref DMA_IT_BLOCK  
  *            @arg @ref DMA_IT_SRCTRAN
  *            @arg @ref DMA_IT_DSTTRAN
  *            @arg @ref DMA_IT_ERR    
  *      
  * @retval The new state of DMA_IT (SET or RESET).
  */
ITStatus DMA_GetITStatus(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT)
{
  FlagStatus bitstatus = RESET;
  uint32_t * reg = ((uint32_t*)&(DMAAUX1->STATTFR)) + DMA_IT * 2;
  
  /* Check the parameters */
  assert_param(IS_DMA_ALL_CHANNEL(DMAy_Channelx));
  assert_param(IS_DMA_IT(DMA_IT));

  /* Check the status of the specified DMAy flag */
  if ((*reg &  (DMA_STATTFR_CH_0 << GET_DMA_CHANNEL_INDEX(DMAy_Channelx))) != (uint32_t)RESET)
  {
    /* DMAy_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* DMAy_FLAG is reset */
    bitstatus = RESET;
  }
  
  /* Return the DMAy_FLAG status */
  return  bitstatus;
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

