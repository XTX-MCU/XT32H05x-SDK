/**
  ******************************************************************************
  * @file    xt32h0xx_dma.h
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file contains all the functions prototypes for the DMA firmware
  *          library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_DMA_H
#define __XT32H0XX_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/** @defgroup DMA_Exported_Types DMA Exported Types
 * @{
 */
typedef struct __DMA_HSTypeDef
{
  uint32_t HSMode;                 /*!< DMA handshaking mode (software/hardware)                 */
  uint32_t HSPol;                  /*!< DMA handshaking active polarity                          */
  uint32_t HSIF;                   /*!< Hardware handshaking interface                           */
} DMA_HSTypeDef;

/** 
  * @brief  DMA Init structures definition
  */
typedef struct
{
  uint32_t DMA_DIR;                     /*!< Specifies data transfer direction.
                                             This parameter can be a value of @ref DMA_Data_transfer_direction     */

  uint32_t DMA_SourceInc;               /*!< Specifies whether the source address register is incremented or not.
                                             This parameter can be a value of @ref DMA_Source_incremented_mode */

  uint32_t DMA_DestinationInc;          /*!< Specifies whether the destination address register is incremented or not.
                                             This parameter can be a value of @ref DMA_Destination_incremented_mode     */

  uint32_t DMA_SourceDataSize;          /*!< Specifies the source data width.
                                            This parameter can be a value of @ref DMA_Source_data_size        */

  uint32_t DMA_DestinationDataSize;     /*!< Specifies the destination data width.
                                             This parameter can be a value of @ref DMA_destination_data_size            */

  uint32_t DMA_SourceBurstLength;       /*!< Specifies the source burst data length.
                                             This parameter can be a value of @ref DMA_source_burst_size */

  uint32_t DMA_DestinationBurstLength;  /*!< Specifies the destination burst data length.
                                             This parameter can be a value of @ref DMA_destination_burst_size     */

  uint32_t DMA_Mode;                    /*!< Specifies the operation mode of the DMAy Channelx.
                                             This parameter can be a value of @ref DMA_mode */

  uint32_t DMA_Priority;                /*!< Specifies the software priority for the DMAy Channelx.
                                             This parameter can be a value of @ref DMA_Priority_level              */

  DMA_HSTypeDef DMA_SourceHandShaking;
  DMA_HSTypeDef DMA_DestinationHandShaking;

}DMA_InitTypeDef;

typedef struct __DMA_CfgTypeDef
{
  uint32_t DMA_SourceBaseAddr;          /*!< Specifies the source base address for DMAy Channelx.              */

  uint32_t DMA_DestinationBaseAddr;     /*!< Specifies the destination base address for DMAy Channelx.         */

  uint32_t TransferSize;                /*!< DMA transfer size                                                 */
} DMA_CfgTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup DMA_Exported_Constants DMA Exported Constants
  * @{
  */

/** @defgroup DMA_Channel DMA Channel
  * @{
  */
#define IS_DMA_ALL_CHANNEL(CHANNEL) (((CHANNEL) == DMA1_Channel0) || \
                                     ((CHANNEL) == DMA1_Channel1) || \
                                     ((CHANNEL) == DMA1_Channel2) || \
                                     ((CHANNEL) == DMA1_Channel3) || \
                                     ((CHANNEL) == DMA1_Channel4) || \
                                     ((CHANNEL) == DMA1_Channel5) || \
                                     ((CHANNEL) == DMA1_Channel6) || \
                                     ((CHANNEL) == DMA1_Channel7))
/**
  * @}
  */

/** @defgroup DMA_Data_transfer_direction DMA Data transfer direction
  * @{
  */
#define DMA_MEMORY_TO_MEMORY_FC_DMAC       (0)                                     /*!< Memory to memory direction, flow control by DMAC */
#define DMA_MEMORY_TO_PERIPH_FC_DMAC       (DMA_CH_CHCTL_TTFC_0)                      /*!< Memory to peripheral direction, flow control by DMAC */
#define DMA_PERIPH_TO_MEMORY_FC_DMAC       (DMA_CH_CHCTL_TTFC_1)                      /*!< Peripheral to memory direction, flow control by DMAC */
#define DMA_PERIPH_TO_PERIPH_FC_DMAC       (DMA_CH_CHCTL_TTFC_1 | DMA_CH_CHCTL_TTFC_0)   /*!< Peripheral to peripheral direction, flow control by DMAC */

#define IS_DMA_TRANSFER_DIRECT(DIR) (((DIR) == DMA_MEMORY_TO_MEMORY_FC_DMAC) || \
                                     ((DIR) == DMA_MEMORY_TO_PERIPH_FC_DMAC) || \
                                     ((DIR) == DMA_PERIPH_TO_MEMORY_FC_DMAC) || \
                                     ((DIR) == DMA_PERIPH_TO_PERIPH_FC_DMAC))
/**
  * @}
  */

/** @defgroup DMA_Source_incremented_mode DMA Peripheral incremented mode
  * @{
  */
#define DMA_SINC_INCREMENT             (0)                                     /*!< Source Address Increment  */
#define DMA_SINC_DECREMENT             (DMA_CH_CHCTL_SINC_0)                      /*!< Source Address Decrement  */
#define DMA_SINC_NOCHANGE              (DMA_CH_CHCTL_SINC_1)                      /*!< Source Address No Change  */

#define IS_DMA_SOURCE_INC_STATE(STATE) (((STATE) == DMA_SINC_INCREMENT) || \
                                        ((STATE) == DMA_SINC_DECREMENT)  || \
                                        ((STATE) == DMA_SINC_NOCHANGE))
/**
  * @}
  */

/** @defgroup DMA_Destination_incremented_mode DMA Memory incremented mode
  * @{
  */
#define DMA_DINC_INCREMENT             (0)                                     /*!< Destination Address Increment  */
#define DMA_DINC_DECREMENT             (DMA_CH_CHCTL_DINC_0)                      /*!< Destination Address Decrement  */
#define DMA_DINC_NOCHANGE              (DMA_CH_CHCTL_DINC_1)                      /*!< Destination Address No Change  */

#define IS_DMA_DESTINATION_INC_STATE(STATE) (((STATE) == DMA_DINC_INCREMENT) || \
                                             ((STATE) == DMA_DINC_DECREMENT)  || \
                                             ((STATE) == DMA_DINC_NOCHANGE))
/**
  * @}
  */

/** @defgroup DMA_Source_data_size DMA Peripheral data size
  * @{
  */
#define DMA_SDATAALIGN_BYTE            (0)                                         /*!< Transfer Width : 8   bits  */
#define DMA_SDATAALIGN_HALFWORD        (DMA_CH_CHCTL_SRCTRW_0)                        /*!< Transfer Width : 16  bits  */
#define DMA_SDATAALIGN_WORD            (DMA_CH_CHCTL_SRCTRW_1)                        /*!< Transfer Width : 32  bits  */
#define DMA_SDATAALIGN_DOUBLEWORD      (DMA_CH_CHCTL_SRCTRW_1|DMA_CH_CHCTL_SRCTRW_0)     /*!< Transfer Width : 64  bits  */
#define DMA_SDATAALIGN_QUOTAWORD       (DMA_CH_CHCTL_SRCTRW_2)                        /*!< Transfer Width : 128 bits  */
#define DMA_SDATAALIGN_OCTOWORD        (DMA_CH_CHCTL_SRCTRW_1|DMA_CH_CHCTL_SRCTRW_0)     /*!< Transfer Width : 256 bits  */

#define IS_DMA_SRCDATA_SIZE(SIZE) (((SIZE) == DMA_SDATAALIGN_BYTE) || \
                                   ((SIZE) == DMA_SDATAALIGN_HALFWORD)  || \
                                   ((SIZE) == DMA_SDATAALIGN_WORD)  || \
                                   ((SIZE) == DMA_SDATAALIGN_DOUBLEWORD)  || \
                                   ((SIZE) == DMA_SDATAALIGN_QUOTAWORD)  || \
                                   ((SIZE) == DMA_SDATAALIGN_OCTOWORD))
/**
  * @}
  */

/** @defgroup DMA_destination_data_size DMA Memory data size
  * @{
  */
#define DMA_DDATAALIGN_BYTE            (0)                                         /*!< Transfer Width : 8   bits  */
#define DMA_DDATAALIGN_HALFWORD        (DMA_CH_CHCTL_DSTTRW_0)                        /*!< Transfer Width : 16  bits  */
#define DMA_DDATAALIGN_WORD            (DMA_CH_CHCTL_DSTTRW_1)                        /*!< Transfer Width : 32  bits  */
#define DMA_DDATAALIGN_DOUBLEWORD      (DMA_CH_CHCTL_DSTTRW_1|DMA_CH_CHCTL_DSTTRW_0)     /*!< Transfer Width : 64  bits  */
#define DMA_DDATAALIGN_QUOTAWORD       (DMA_CH_CHCTL_DSTTRW_2)                        /*!< Transfer Width : 128 bits  */
#define DMA_DDATAALIGN_OCTOWORD        (DMA_CH_CHCTL_DSTTRW_2|DMA_CH_CHCTL_DSTTRW_0)     /*!< Transfer Width : 256 bits  */

#define IS_DMA_DSTDATA_SIZE(SIZE) (((SIZE) == DMA_DDATAALIGN_BYTE) || \
                                   ((SIZE) == DMA_DDATAALIGN_HALFWORD)  || \
                                   ((SIZE) == DMA_DDATAALIGN_WORD)  || \
                                   ((SIZE) == DMA_DDATAALIGN_DOUBLEWORD)  || \
                                   ((SIZE) == DMA_DDATAALIGN_QUOTAWORD)  || \
                                   ((SIZE) == DMA_DDATAALIGN_OCTOWORD))
/**
  * @}
  */

/** @defgroup DMA_destination_burst_size DMA Destination Burst Transaction Length 
  * @{
  */
#define DMA_DST_MSIZE_1                (0)                                                                 /*!< Destination Burst Transaction Length : 1   bits  */
#define DMA_DST_MSIZE_4                (DMA_CH_CHCTL_DSTMSIZE_0)                                              /*!< Destination Burst Transaction Length : 4   bits  */
#define DMA_DST_MSIZE_8                (DMA_CH_CHCTL_DSTMSIZE_1)                                              /*!< Destination Burst Transaction Length : 8   bits  */
#define DMA_DST_MSIZE_16               (DMA_CH_CHCTL_DSTMSIZE_1|DMA_CH_CHCTL_DSTMSIZE_0)                         /*!< Destination Burst Transaction Length : 16  bits  */
#define DMA_DST_MSIZE_32               (DMA_CH_CHCTL_DSTMSIZE_2)                                              /*!< Destination Burst Transaction Length : 32  bits  */
#define DMA_DST_MSIZE_64               (DMA_CH_CHCTL_DSTMSIZE_2|DMA_CH_CHCTL_DSTMSIZE_0)                         /*!< Destination Burst Transaction Length : 64  bits  */
#define DMA_DST_MSIZE_128              (DMA_CH_CHCTL_DSTMSIZE_2|DMA_CH_CHCTL_DSTMSIZE_1)                         /*!< Destination Burst Transaction Length : 128 bits  */
#define DMA_DST_MSIZE_256              (DMA_CH_CHCTL_DSTMSIZE_2|DMA_CH_CHCTL_DSTMSIZE_1|DMA_CH_CHCTL_DSTMSIZE_0)    /*!< Destination Burst Transaction Length : 256 bits  */

#define IS_DMA_DSTBUSRT_SIZE(SIZE) (((SIZE) == DMA_DST_MSIZE_1) || \
                                    ((SIZE) == DMA_DST_MSIZE_4)  || \
                                    ((SIZE) == DMA_DST_MSIZE_8)  || \
                                    ((SIZE) == DMA_DST_MSIZE_16)  || \
                                    ((SIZE) == DMA_DST_MSIZE_32)  || \
                                    ((SIZE) == DMA_DST_MSIZE_64)  || \
                                    ((SIZE) == DMA_DST_MSIZE_128)  || \
                                    ((SIZE) == DMA_DST_MSIZE_256))
/**
  * @}
  */

/** @defgroup DMA_source_burst_size DMA Source Burst Transaction Length 
  * @{
  */
#define DMA_SRC_MSIZE_1                (0)                                                                 /*!< Source Burst Transaction Length : 1   bits  */
#define DMA_SRC_MSIZE_4                (DMA_CH_CHCTL_SRCMSIZE_0)                                              /*!< Source Burst Transaction Length : 4   bits  */
#define DMA_SRC_MSIZE_8                (DMA_CH_CHCTL_SRCMSIZE_1)                                              /*!< Source Burst Transaction Length : 8   bits  */
#define DMA_SRC_MSIZE_16               (DMA_CH_CHCTL_SRCMSIZE_1|DMA_CH_CHCTL_SRCMSIZE_0)                         /*!< Source Burst Transaction Length : 16  bits  */
#define DMA_SRC_MSIZE_32               (DMA_CH_CHCTL_SRCMSIZE_2)                                              /*!< Source Burst Transaction Length : 32  bits  */
#define DMA_SRC_MSIZE_64               (DMA_CH_CHCTL_SRCMSIZE_2|DMA_CH_CHCTL_SRCMSIZE_0)                         /*!< Source Burst Transaction Length : 64  bits  */
#define DMA_SRC_MSIZE_128              (DMA_CH_CHCTL_SRCMSIZE_2|DMA_CH_CHCTL_SRCMSIZE_1)                         /*!< Source Burst Transaction Length : 128 bits  */
#define DMA_SRC_MSIZE_256              (DMA_CH_CHCTL_SRCMSIZE_2|DMA_CH_CHCTL_SRCMSIZE_1|DMA_CH_CHCTL_SRCMSIZE_0)    /*!< Source Burst Transaction Length : 256 bits  */

#define IS_DMA_SRCBUSRT_SIZE(SIZE) (((SIZE) == DMA_SRC_MSIZE_1) || \
                                    ((SIZE) == DMA_SRC_MSIZE_4)  || \
                                    ((SIZE) == DMA_SRC_MSIZE_8)  || \
                                    ((SIZE) == DMA_SRC_MSIZE_16)  || \
                                    ((SIZE) == DMA_SRC_MSIZE_32)  || \
                                    ((SIZE) == DMA_SRC_MSIZE_64)  || \
                                    ((SIZE) == DMA_SRC_MSIZE_128)  || \
                                    ((SIZE) == DMA_SRC_MSIZE_256))
/**
  * @}
  */

/** @defgroup DMA_mode DMA mode
  * @{
  */
#define DMA_SGLBLK                     (0x00000000UL)                          /*!< Single-block or last transfer of multi-block \
                                                                                    LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#define DMA_MULBLK_RSAR_RDAR           (0x00000003U)                           /*!< Auto-reload multi-block transfer \
                                                                                    LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */

#define IS_DMA_MODE(MODE) (((MODE) == DMA_SGLBLK) || ((MODE) == DMA_MULBLK_RSAR_RDAR))
/**
  * @}
  */

/** @defgroup DMA_Priority_level DMA Priority level
  * @{
  */
#define DMA_PRIORITY_0                 (0)                                                         /*!< Channel DMA Channel priority 0 lowest */
#define DMA_PRIORITY_1                 (DMA_CH_CHCFG_PRIOR_0)                                         /*!< Channel DMA Channel priority 1        */
#define DMA_PRIORITY_2                 (DMA_CH_CHCFG_PRIOR_1)                                         /*!< Channel DMA Channel priority 2        */
#define DMA_PRIORITY_3                 (DMA_CH_CHCFG_PRIOR_1|DMA_CH_CHCFG_PRIOR_0)                       /*!< Channel DMA Channel priority 3        */
#define DMA_PRIORITY_4                 (DMA_CH_CHCFG_PRIOR_2)                                         /*!< Channel DMA Channel priority 4        */
#define DMA_PRIORITY_5                 (DMA_CH_CHCFG_PRIOR_2|DMA_CH_CHCFG_PRIOR_0)                       /*!< Channel DMA Channel priority 5        */
#define DMA_PRIORITY_6                 (DMA_CH_CHCFG_PRIOR_2|DMA_CH_CHCFG_PRIOR_1)                       /*!< Channel DMA Channel priority 6        */
#define DMA_PRIORITY_7                 (DMA_CH_CHCFG_PRIOR_2|DMA_CH_CHCFG_PRIOR_1|DMA_CH_CHCFG_PRIOR_0)     /*!< Channel DMA Channel priority 7        */

#define IS_DMA_PRIORITY(PRIORITY) (((PRIORITY) == DMA_PRIORITY_0) || \
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

/** @defgroup DMA_SRCHS_POL DMA source hand shaking polarity
  * @{
  */
#define DMA_SRCHS_POL_HIGH             (0)                                     /*!< source hand shaking active high */
#define DMA_SRCHS_POL_LOW              (DMA_CH_CHCFG_SRCHSPOL)                    /*!< source hand shaking active low */

#define IS_DMA_SRCHS_POLARITY(POL) (((POL) == DMA_SRCHS_POL_HIGH) || ((POL) == DMA_SRCHS_POL_LOW))
/**
  * @}
  */

/** @defgroup DMA_DSTHS_POL DMA destination hand shaking polarity
  * @{
  */
#define DMA_DSTHS_POL_HIGH             (0)                                     /*!< Destination hand shaking active high */
#define DMA_DSTHS_POL_LOW              (DMA_CH_CHCFG_DSTHSPOL)                    /*!< Destination hand shaking active low */

#define IS_DMA_DSTHS_POLARITY(POL) (((POL) == DMA_DSTHS_POL_HIGH) || ((POL) == DMA_DSTHS_POL_LOW))
/**
  * @}
  */

/** @defgroup DMA_SRCHS_MODE DMA source hand shaking select
  * @{
  */
#define DMA_SRCHS_HW                   (0)                                     /*!< source hand shaking hardware select */
#define DMA_SRCHS_SW                   (DMA_CH_CHCFG_SRCHS)                       /*!< source hand shaking software select */

#define IS_DMA_SRCHS_MODE(MODE) (((MODE) == DMA_SRCHS_HW) || ((MODE) == DMA_SRCHS_SW))
/**
  * @}
  */

/** @defgroup DMA_DSTHS_MODE DMA destination hand shaking select
  * @{
  */
#define DMA_DSTHS_HW                   (0)                                     /*!< Destination hand shaking hardware select */
#define DMA_DSTHS_SW                   (DMA_CH_CHCFG_DSTHS)                       /*!< Destination hand shaking software select */

#define IS_DMA_DSTHS_MODE(MODE) (((MODE) == DMA_DSTHS_HW) || ((MODE) == DMA_DSTHS_SW))
/**
  * @}
  */

/** @defgroup DMA_xxxHS_IF DMA source/destination hand shaking inrweface
  * @{
  */
#define IS_DMA_SRCHS_IF(IF) (((IF) >= 0) && ((IF) <= 15))
#define IS_DMA_DSTHS_IF(IF) (((IF) >= 0) && ((IF) <= 15))
/**
  * @}
  */


/** @defgroup DMA_IT DMA interrupt 
  * @{
  */
#define DMA_IT_TFR                     (0)                                     /*!< TFR */
#define DMA_IT_BLOCK                   (1)                                     /*!< BLOCK */
#define DMA_IT_SRCTRAN                 (2)                                     /*!< SrcTran */
#define DMA_IT_DSTTRAN                 (3)                                     /*!< DstTran */
#define DMA_IT_ERR                     (4)                                     /*!< ERR */

#define IS_DMA_IT(IT) (((IT) == DMA_IT_TFR) || \
                       ((IT) == DMA_IT_BLOCK) || \
                       ((IT) == DMA_IT_SRCTRAN) || \
                       ((IT) == DMA_IT_DSTTRAN) || \
                       ((IT) == DMA_IT_ERR))
/**
  * @}
  */

/** @defgroup DMA_IT_MASK DMA destination hand shaking select
  * @{
  */
#define DMA_IT_MASKED                  (0)                                     /*!< Destination hand shaking hardware select */
#define DMA_IT_UNMASKED                (1)                                     /*!< Destination hand shaking software select */

#define IS_DMA_IT_MASK(MASK) (((MASK) == DMA_IT_MASKED) || ((MASK) == DMA_IT_UNMASKED))
/**
  * @}
  */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup DMA_Exported_Macros DMA Exported Macros 
  * @{
  */
/** @brief Get DMA Channel Index in [0,7]
  * 
  */

#define GET_DMA_CHANNEL_INDEX(CHANNEL) (((CHANNEL) == DMA1_Channel0) ? 0 : \
                                        ((CHANNEL) == DMA1_Channel1) ? 1 : \
                                        ((CHANNEL) == DMA1_Channel2) ? 2 : \
                                        ((CHANNEL) == DMA1_Channel3) ? 3 : \
                                        ((CHANNEL) == DMA1_Channel4) ? 4 : \
                                        ((CHANNEL) == DMA1_Channel5) ? 5 : \
                                        ((CHANNEL) == DMA1_Channel6) ? 6 : \
                                        7)
/**
  * @}
  */

/* Exported functions ------------------------------------------------------- */
/** @addtogroup DMA_Exported_Functions
  * @{
  */

/** @addtogroup DMA_Exported_Functions_Group1
  * @{
  */
/* Function used to set the DMA configuration to the default reset state ******/
void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx);

/* Initialization and Configuration functions *********************************/
void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct);

/**
  * @}
  */
/** @addtogroup DMA_Exported_Functions_Group2
  * @{
  */
void DMA_EnableDMAC(void);
void DMA_DisableDMAC(void);

void DMA_EnableChannel(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_DisableChannel(DMA_Channel_TypeDef* DMAy_Channelx);

void DMA_Config(DMA_Channel_TypeDef* DMAy_Channelx, DMA_CfgTypeDef* DMA_CfgStruct);
void DMA_Abort(DMA_Channel_TypeDef* DMAy_Channelx);

void DMA_SourceRequest(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_DestinationRequest(DMA_Channel_TypeDef* DMAy_Channelx);

/**
  * @}
  */
/** @addtogroup DMA_Exported_Functions_Group3
  * @{
  */
/* Interrupts and flags management functions **********************************/
void DMA_ITEnable(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_ITDisable(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT, uint32_t DMA_IT_MASK);
FlagStatus DMA_GetFlagStatus(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT);
void DMA_ClearFlag(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT);
ITStatus DMA_GetITStatus(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT);
/**
  * @}
  */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif
/**
  * @}
  */

/**
  * @}
  */

#endif /*__XT32H0XX_DMA_H */


