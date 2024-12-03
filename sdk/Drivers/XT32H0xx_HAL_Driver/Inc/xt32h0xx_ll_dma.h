/**
  ******************************************************************************
  * @file    xt32h0xx_ll_dma.h
  * @author  Software Team
  * @brief   Header file of DMA LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_DMA_H
#define XT32H0xx_LL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"
//#include "xt32h0xx_ll_dmamux.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined(DMA1)

/** @defgroup DMA_LL DMA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup DMA_LL_Private_Variables DMA Private Variables
  * @{
  */
/* Array used to get the DMA channel register offset versus channel index LL_DMA_CHANNEL_x */
static const uint8_t CHANNEL_OFFSET_TAB[] =
{
  (uint8_t)(DMA1_Channel0_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel1_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel2_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel3_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel4_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel5_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel6_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel7_BASE - DMA1_BASE),
};
/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup DMA_LL_Private_Constants DMA Private Constants
  * @{
  */
/* Hardware fixed for XT32H0xxx */
#define   DMA_MASTER_NUMBER        (1)

#define   DMA_MABRST               (0) 

#define   DMA_MULTI_BLOCK_ENABLE   (1)
#if DMA_MULTI_BLOCK_ENABLE
#define   DMA_MB_CONT_RELOAD       (0)
#define   DMA_MB_RELOAD_CONT       (0)
#define   DMA_MB_RELOAD_RELOAD     (1)
#define   DMA_LLP_ENABLE           (0)
#define   DMA_GATHER_ENABLE        (0)
#define   DMA_SCATTER_ENABLE       (0)
#else
#define   DMA_MB_CONT_RELOAD       (0)
#define   DMA_MB_RELOAD_CONT       (0)
#define   DMA_MB_RELOAD_RELOAD     (0)
#define   DMA_LLP_ENABLE           (0)
#define   DMA_GATHER_ENABLE        (0)
#define   DMA_SCATTER_ENABLE       (0)
#endif

#define   DMA_LOCK_ENABLE          (0)

#define   DMA_HW_HANDSHAKING       (1)
/**
  * @}
  */

/** @defgroup DMA_LL_Private_Macros DMA Private Macros
  * @{
  */
/**
  * @brief  Helper macro to convert DMA Instance DMAx into DMAMUX channel
  * @note   DMAMUX channel 0 to 6 are mapped to DMA1 channel 1 to 7.
  *         DMAMUX channel 7 to 11 are mapped to DMA2 channel 1 to 5 (**** only available on chip which support DMA2 ****).
  * @param  __DMA_INSTANCE__ DMAx
  * @retval Channel_Offset (LL_DMA_CHANNEL_7 or 0).
  */
//#define __LL_DMA_INSTANCE_TO_DMAMUX_CHANNEL(__DMA_INSTANCE__)   \
//(((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) ? 0 : LL_DMA_CHANNEL_7)
/**
  * @}
  */
/* Exported types ------------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Types DMA Exported Types
 * @{
 */
#if DMA_LLP_ENABLE   /* Hardware disabled */
/** @defgroup DMA_LL_ES_LLP DMA Exported LLP structure
 * @{
 */
typedef struct __LL_DMA_LLPTypeDef
{
  uint32_t SrcAddress;             /*!< source address                                           */
  uint32_t DstAddress;             /*!< destination address                                      */
  struct __LL_DMA_LLPTypeDef *NextLLP;       /*!< pointer to the next LLP                                  */
  uint32_t Ctl_L;                  /*!< CTL register 31-0                                        */
  uint32_t Ctl_H;                  /*!< CTL register 63-32                                       */
 #if defined(DMAH_CHX_STAT_SRC)   
  uint32_t WbSrcStatus;            /*!< write-back to source status                              */
#endif //defined(DMAH_CHX_STAT_SRC)  
  uint32_t WbDstStatus;            /*!< write-back to destination status                         */
} LL_DMA_LLPTypeDef;
/**
  * @}
  */
#endif /* DMA_LLP_ENABLE */
#if DMA_GATHER_ENABLE
/** @defgroup DMA_LL_ES_GATHER DMA Exported SGR structure
 * @{
 */
typedef struct __LL_DMA_SGRTypeDef
{
  uint32_t SgrCount;               /*!< source gather count                                      */
  uint32_t SgrInterval;            /*!< source gather interval                                   */
 } LL_DMA_SGRTypeDef;
/**
  * @}
  */
#endif /* DMA_GATHER_ENABLE */
#if DMA_SCATTER_ENABLE
/** @defgroup DMA_LL_ES_SCATTER DMA Exported DSR structure
 * @{
 */
typedef struct __LL_DMA_DSRTypeDef
{
  uint32_t DsrCount;               /*!< destination scatter count                                */
  uint32_t DsrInterval;            /*!< destination scatter interval                             */
 } LL_DMA_DSRTypeDef;
/**
  * @}
  */
#endif /* DMA_SCATTER_ENABLE */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_ES_INIT DMA Exported Init structure
  * @{
  */
typedef struct
{
  uint32_t SrcAddress;             /*!< Specifies the Source base address. 

                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFF. */

  uint32_t DstAddress;             /*!< Specifies as Destination base address.

                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFF. */

  uint32_t Direction;              /*!< Specifies if the data will be transferred from memory to peripheral,
                                        from memory to memory or from peripheral to memory and with/withour flow control.
                                        This parameter can be a value of @ref DMA_LL_EC_DIRECTION

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetDataTransferDirection(). */

  uint32_t Mode;                   /*!< Specifies single-block, multi-block, contiguous address, reload/linked list address operation modes.
                                        This parameter can be a value of @ref DMA_LL_EC_MODE
                                        @note: The LLP memory are always aligned to 32-bit boundaries.
  
                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetMode(). */
#if DMA_LLP_ENABLE
  uint32_t LlpAddress;             /*!< Specifies as LLP start address.

                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFE. */
#endif /* DMA_LLP_ENABLE */
  uint32_t SrcIncMode;             /*!< Specifies whether the Source address is incremented, decrement or no change.
                                        This parameter can be a value of @ref DMA_LL_EC_SINC

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetSourceIncMode(). */

  uint32_t DstIncMode;             /*!< Specifies whether the Destination address is incremented, decrement or no change.
                                        This parameter can be a value of @ref DMA_LL_EC_DINC

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetDestinationIncMode(). */

  uint32_t SrcDataSize;            /*!< Specifies Source data size alignment.
                                        This parameter can be a value of @ref DMA_LL_EC_SRC_TRWIDTH

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetSourceSize(). */

  uint32_t DstDataSize;            /*!< Specifies the Destination data size alignment.
                                        This parameter can be a value of @ref DMA_LL_EC_DST_TRWIDTH

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetDestinationSize(). */

  uint32_t SrcBurstSize;           /*!< Specifies Source burst transaction length.
                                        This parameter can be a value of @ref DMA_LL_EC_SRC_MSIZE

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetSourceBurstSize(). */

  uint32_t DstBurstSize;           /*!< Specifies the Destination burst transaction length.
                                        This parameter can be a value of @ref DMA_LL_EC_DST_MSIZE

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetDestinationBurstSize(). */

  uint32_t BlockSize;              /*!< Specifies the number of data to transfer, in data unit.
                                        The data unit is equal to the source buffer configuration set in PeripheralSize
                                        or MemorySize parameters depending in the transfer direction.
                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0x00000FFF

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetBlockSize(). */

  uint32_t Priority;               /*!< Specifies the channel priority level.
                                        This parameter can be a value of @ref DMA_LL_EC_CH_PRIOR

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetChannelPriorityLevel(). */

  uint32_t IntEn;                  /*!< Specifies the channel interrupt enable.
                                        This parameter can be a value of @ref DMA_LL_EC_INTE

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_EnableIT(). */
#if (DMA_HW_HANDSHAKING)
  uint32_t SrcHSMode;              /*!< Specifies the channel source handshaking interface mode.
                                        This parameter ca be value of @ref DMA_LL_EC_HS_SEL_SRC

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetChannelSourceHSMode(). */

  uint32_t DstHSMode;              /*!< Specifies the channel source handshaking interface mode.
                                        This parameter ca be value of @ref DMA_LL_EC_HS_SEL_DST

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetChannelDestinationHSMode(). */

  uint32_t SrcHSPol;               /*!< Specifies the channel source handshaking interface polarity.
                                        This parameter ca be value of @ref DMA_LL_EC_SRC_HS_POL

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetChannelSourceHSPol(). */

  uint32_t DstHSPol;               /*!< Specifies the channel destination handshaking interface polarity.
                                        This parameter ca be value of @ref DMA_LL_EC_DST_HS_POL

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetChannelDestinationHSPol(). */

  uint32_t SrcHSIF;                /*!< Specifies the channel source handshaking interface.
                                        This parameter ca be value of @ref DMA_LL_EC_SRC_PER

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetChannelSourceHSIF(). */

  uint32_t DstHSIF;                /*!< Specifies the channel destination handshaking interface.
                                        This parameter ca be value of @ref DMA_LL_EC_DEST_PER

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetChannelDestinationHSIF(). */
#endif /* DMA_HW_HANDSHAKING */
#if (DMA_MASTER_NUMBER > 1)
  uint32_t Sms;
  uint32_t Dms;
#endif /* (DMA_MASTER_NUMBER > 1) */
#if (DMA_GATHER_ENABLE)
  LL_DMA_SGRTypeDef  SrcGather;
#endif  /* DMA_GATHER_ENABLE */  
#if (DMA_SCATTER_ENABLE)
  LL_DMA_DSRTypeDef  DstScatter;
#endif  /* DMA_GATHER_ENABLE */  
} LL_DMA_InitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Constants DMA Exported Constants
  * @{
  */
/** @defgroup DMA_LL_EC_DMA_CFG  DMA Controller Enable
  * @{
  */
#define LL_DMA_ENABLE                     DMA_CFG_EN             /*!< DMA is enabled            */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_CHANNEL DMA Channel Index 
  * @{
  */
#define LL_DMA_CHANNEL_0                  0x00000000U /*!< DMA Channel 0 */
#define LL_DMA_CHANNEL_1                  0x00000001U /*!< DMA Channel 1 */
#define LL_DMA_CHANNEL_2                  0x00000002U /*!< DMA Channel 2 */
#define LL_DMA_CHANNEL_3                  0x00000003U /*!< DMA Channel 3 */
#define LL_DMA_CHANNEL_4                  0x00000004U /*!< DMA Channel 4 */
#define LL_DMA_CHANNEL_5                  0x00000005U /*!< DMA Channel 5 */
#define LL_DMA_CHANNEL_6                  0x00000006U /*!< DMA Channel 6 */
#define LL_DMA_CHANNEL_7                  0x00000007U /*!< DMA Channel 7 */
#if defined(USE_FULL_LL_DRIVER)
#define LL_DMA_CHANNEL_ALL                0xFFFF0000U /*!< DMA Channel all (used only for function @ref LL_DMA_DeInit(). */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */

/** @defgroup DMA_LL_EC_CHANNEL_EN DMA Channel Enable
  * @{
  */
#define LL_DMA_CHANNEL_EN_0                DMA_CHEN_CH0_EN /*!< DMA Channel 0 */
#define LL_DMA_CHANNEL_EN_1                DMA_CHEN_CH1_EN /*!< DMA Channel 1 */
#define LL_DMA_CHANNEL_EN_2                DMA_CHEN_CH2_EN /*!< DMA Channel 2 */
#define LL_DMA_CHANNEL_EN_3                DMA_CHEN_CH3_EN /*!< DMA Channel 3 */
#define LL_DMA_CHANNEL_EN_4                DMA_CHEN_CH4_EN /*!< DMA Channel 4 */
#define LL_DMA_CHANNEL_EN_5                DMA_CHEN_CH5_EN /*!< DMA Channel 5 */
#define LL_DMA_CHANNEL_EN_6                DMA_CHEN_CH6_EN /*!< DMA Channel 6 */
#define LL_DMA_CHANNEL_EN_7                DMA_CHEN_CH7_EN /*!< DMA Channel 7 */
#if defined(USE_FULL_LL_DRIVER)
#define LL_DMA_CHANNEL_EN_ALL              (DMA_CHEN_CH0_EN \
                                          | DMA_CHEN_CH1_EN \
                                          | DMA_CHEN_CH2_EN \
                                          | DMA_CHEN_CH3_EN \
                                          | DMA_CHEN_CH4_EN \
                                          | DMA_CHEN_CH5_EN \
                                          | DMA_CHEN_CH6_EN \
                                          | DMA_CHEN_CH7_EN) /*!< DMA Channel all (used only for function @ref LL_DMA_DeInit(). */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */

/** @defgroup DMA_LL_EC_CHANNEL_WE DMA Channel Write Enable
  * @{
  */
#define LL_DMA_CHANNEL_WE_0               DMA_CHEN_CH0_WE /*!< DMA Channel 0 Write Enable */
#define LL_DMA_CHANNEL_WE_1               DMA_CHEN_CH1_WE /*!< DMA Channel 1 Write Enable */
#define LL_DMA_CHANNEL_WE_2               DMA_CHEN_CH2_WE /*!< DMA Channel 2 Write Enable */
#define LL_DMA_CHANNEL_WE_3               DMA_CHEN_CH3_WE /*!< DMA Channel 3 Write Enable */
#define LL_DMA_CHANNEL_WE_4               DMA_CHEN_CH4_WE /*!< DMA Channel 4 Write Enable */
#define LL_DMA_CHANNEL_WE_5               DMA_CHEN_CH5_WE /*!< DMA Channel 5 Write Enable */
#define LL_DMA_CHANNEL_WE_6               DMA_CHEN_CH6_WE /*!< DMA Channel 6 Write Enable */
#define LL_DMA_CHANNEL_WE_7               DMA_CHEN_CH7_WE /*!< DMA Channel 7 Write Enable */
#if defined(USE_FULL_LL_DRIVER)
#define LL_DMA_CHANNEL_WE_ALL             (DMA_CHEN_CH0_WE \
                                          | DMA_CHEN_CH1_WE \
                                          | DMA_CHEN_CH2_WE \
                                          | DMA_CHEN_CH3_WE \
                                          | DMA_CHEN_CH4_WE \
                                          | DMA_CHEN_CH5_WE \
                                          | DMA_CHEN_CH6_WE \
                                          | DMA_CHEN_CH7_WE) /*!< DMA Channel all write Emable (used only for function @ref LL_DMA_DeInit(). */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */
#if (DMA_MASTER_NUMBER > 1)
/** @defgroup DMA_LL_EC_LMS List Master Select 
  * @{
  */
#define LL_DMA_LMS_1                       (0x00000000U << DMA_CHLLP_LMS_Pos)            /*!< Channel DMA Done AHB Master 1  */
#define LL_DMA_LMS_2                       (0x00000001U << DMA_CHLLP_LMS_Pos)            /*!< Channel DMA Done AHB Master 2  */
#define LL_DMA_LMS_3                       (0x00000002U << DMA_CHLLP_LMS_Pos)            /*!< Channel DMA Done AHB Master 3  */
#define LL_DMA_LMS_4                       (0x00000003U << DMA_CHLLP_LMS_Pos)            /*!< Channel DMA Done AHB Master 4  */
/**
  * @}
  */
#endif /* DMA_MASTER_NUMBER */
/** @defgroup DMA_LL_EC_DONE Done Bit 
  * @{
  */
#define LL_DMA_DONE                             DMA_CH_CHCTL_DONE             /*!< Channel DMA Done  */
/**
  * @}
  */
#if DMA_LLP_ENABLE
/** @defgroup DMA_LL_EC_LLP_SRC_EN Block chaining is enabled on the source side 
  * @{
  */
#define LL_DMA_LLPSRC_ENABLE                    DMA_CH_CHCTL_LLPSRCEN         /*!< Channel DMA LLP Block Chaining is enabled on the source  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_LLP_DST_EN Block chaining is enabled on the destination side 
  * @{
  */
#define LL_DMA_LLPDST_ENABLE                    DMA_CH_CHCTL_LLPDSTEN         /*!< Channel DMA LLP Block Chaining is enabled on the destination  */
/**
  * @}
  */
#endif /* DMA_LLP_ENABLE */
#if (DMA_MASTER_NUMBER > 1)
/** @defgroup DMA_LL_EC_SMS Source Master Select 
  * @{
  */
#define LL_DMA_SMS_1                            (0x00000000U << DMA_CH_CHCTL_SMS_Pos)         /*!< Channel DMA Source Master Select : AHB Master 1  */
#define LL_DMA_SMS_2                            (0x00000001U << DMA_CH_CHCTL_SMS_Pos)         /*!< Channel DMA Source Master Select : AHB Master 2  */
#define LL_DMA_SMS_3                            (0x00000002U << DMA_CH_CHCTL_SMS_Pos)         /*!< Channel DMA Source Master Select : AHB Master 3  */
#define LL_DMA_SMS_4                            (0x00000003U << DMA_CH_CHCTL_SMS_Pos)         /*!< Channel DMA Source Master Select : AHB Master 4  */
/**
  * @}
  */
#endif /* (DMA_MASTER_NUMBER > 1) */
#if (DMA_MASTER_NUMBER > 1)
/** @defgroup DMA_LL_EC_DMS Destination Master Select 
  * @{
  */
#define LL_DMA_DMS_1                            (0x00000000U << DMA_CH_CHCTL_DMS_Pos)         /*!< Channel DMA Destination Master Select : AHB Master 1  */
#define LL_DMA_DMS_2                            (0x00000001U << DMA_CH_CHCTL_DMS_Pos)         /*!< Channel DMA Destination Master Select : AHB Master 2  */
#define LL_DMA_DMS_3                            (0x00000002U << DMA_CH_CHCTL_DMS_Pos)         /*!< Channel DMA Destination Master Select : AHB Master 3  */
#define LL_DMA_DMS_4                            (0x00000003U << DMA_CH_CHCTL_DMS_Pos)         /*!< Channel DMA Destination Master Select : AHB Master 4  */
/**
  * @}
  */
#endif /* (DMA_MASTER_NUMBER > 1) */ 
/** @defgroup DMA_LL_EC_DIRECTION Transfer Direction & Flow Control
  * @{
  */
#define LL_DMA_MEMORY_TO_MEMORY_FC_DMAC      (0)                                                                   /*!< Memory to memory direction, flow control by DMAC */
#define LL_DMA_MEMORY_TO_PERIPH_FC_DMAC      (DMA_CH_CHCTL_TTFC_0)                                                    /*!< Memory to peripheral direction, flow control by DMAC */
#define LL_DMA_PERIPH_TO_MEMORY_FC_DMAC      (DMA_CH_CHCTL_TTFC_1)                                                    /*!< Peripheral to memory direction, flow control by DMAC */
#define LL_DMA_PERIPH_TO_PERIPH_FC_DMAC      (DMA_CH_CHCTL_TTFC_1 | DMA_CH_CHCTL_TTFC_0)                                 /*!< Peripheral to peripheral direction, flow control by DMAC */
#define LL_DMA_PERIPH_TO_MEMORY_FC_PERI      (DMA_CH_CHCTL_TTFC_2)                                                    /*!< Peripheral to memory direction, flow control by peripheralC */
#define LL_DMA_PERIPH_TO_PERIPH_FC_SRCP      (DMA_CH_CHCTL_TTFC_2 | DMA_CH_CHCTL_TTFC_0)                                 /*!< Peripheral to peripheral direction, flow control by source peripheral */
#define LL_DMA_MEMORY_TO_PERIPH_FC_PERI      (DMA_CH_CHCTL_TTFC_2 | DMA_CH_CHCTL_TTFC_1)                                 /*!< Memory to peripheral direction, flow control by peripheral */
#define LL_DMA_PERIPH_TO_PERIPH_FC_DSTP      (DMA_CH_CHCTL_TTFC_2 | DMA_CH_CHCTL_TTFC_1 | DMA_CH_CHCTL_TTFC_0)              /*!< Peripheral to peripheral direction, flow control by destination peripheral */
/**
  * @}
  */
#if DMA_SCATTER_ENABLE
/** @defgroup DMA_LL_EC_DST_SCATTER_EN Destiantion Scatter enable bit 
  * @{
  */
#define LL_DMA_DST_SCATEN                    DMA_CH_CHCTL_DSTSCAEN                                  /*!< Channel DMA Destination Scatter is enabled  */
/**
  * @}
  */
#endif /* DMA_SCATTER_ENABLE */
#if DMA_GATHER_ENABLE
/** @defgroup DMA_LL_EC_SRC_GATHER_EN Source Gather enable bit 
  * @{
  */
#define LL_DMA_SRC_GATEN                     DMA_CH_CHCTL_SRCGATEN                                  /*!< Channel DMA Source Gather is enabled  */
/**
  * @}
  */
#endif /* DMA_GATHER_ENABLE */
/** @defgroup DMA_LL_EC_DST_TRWIDTH Destination Transfer Width 
  * @{
  */
#define LL_DMA_DST_TRWIDTH_8                 (0x00000000U << DMA_CH_CHCTL_DSTTRW_Pos)            /*!< Transfer Width : 8   bits  */
#define LL_DMA_DST_TRWIDTH_16                (0x00000001U << DMA_CH_CHCTL_DSTTRW_Pos)            /*!< Transfer Width : 16  bits  */
#define LL_DMA_DST_TRWIDTH_32                (0x00000002U << DMA_CH_CHCTL_DSTTRW_Pos)            /*!< Transfer Width : 32  bits  */
#define LL_DMA_DST_TRWIDTH_64                (0x00000003U << DMA_CH_CHCTL_DSTTRW_Pos)            /*!< Transfer Width : 64  bits  */
#define LL_DMA_DST_TRWIDTH_128               (0x00000004U << DMA_CH_CHCTL_DSTTRW_Pos)            /*!< Transfer Width : 128 bits  */
#define LL_DMA_DST_TRWIDTH_256               (0x00000005U << DMA_CH_CHCTL_DSTTRW_Pos)            /*!< Transfer Width : 256 bits  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_SRC_TRWIDTH Destination Transfer Width 
  * @{
  */
#define LL_DMA_SRC_TRWIDTH_8                 (0x00000000U << DMA_CH_CHCTL_SRCTRW_Pos)            /*!< Transfer Width : 8   bits  */
#define LL_DMA_SRC_TRWIDTH_16                (0x00000001U << DMA_CH_CHCTL_SRCTRW_Pos)            /*!< Transfer Width : 16  bits  */
#define LL_DMA_SRC_TRWIDTH_32                (0x00000002U << DMA_CH_CHCTL_SRCTRW_Pos)            /*!< Transfer Width : 32  bits  */
#define LL_DMA_SRC_TRWIDTH_64                (0x00000003U << DMA_CH_CHCTL_SRCTRW_Pos)            /*!< Transfer Width : 64  bits  */
#define LL_DMA_SRC_TRWIDTH_128               (0x00000004U << DMA_CH_CHCTL_SRCTRW_Pos)            /*!< Transfer Width : 128 bits  */
#define LL_DMA_SRC_TRWIDTH_256               (0x00000005U << DMA_CH_CHCTL_SRCTRW_Pos)            /*!< Transfer Width : 256 bits  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DINC Destination Address Increment 
  * @{
  */
#define LL_DMA_DINC_INCREMENT                (0)                                     /*!< Destination Address Increment  */
#define LL_DMA_DINC_DECREMENT                (DMA_CH_CHCTL_DINC_0)                      /*!< Destination Address Decrement  */
#define LL_DMA_DINC_NOCHANGE                 (DMA_CH_CHCTL_DINC_1)                      /*!< Destination Address No Change  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_SINC Source Address Increment 
  * @{
  */
#define LL_DMA_SINC_INCREMENT                (0)                                     /*!< Source Address Increment  */
#define LL_DMA_SINC_DECREMENT                (DMA_CH_CHCTL_SINC_0)                      /*!< Source Address Decrement  */
#define LL_DMA_SINC_NOCHANGE                 (DMA_CH_CHCTL_SINC_1)                      /*!< Source Address No Change  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_INTE Interrupt Enable 
  * @{
  */
#define LL_DMA_INT_ENABLE                    DMA_CH_CHCTL_INTEN                                  /*!< Channel Interrupt Enable   */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DST_MSIZE Destination Burst Transaction Length 
  * @{
  */
#define LL_DMA_DST_MSIZE_1                   (0x00000000U << DMA_CH_CHCTL_DSTMSIZE_Pos)            /*!< Destination Burst Transaction Length : 1   bits  */
#define LL_DMA_DST_MSIZE_4                   (0x00000001U << DMA_CH_CHCTL_DSTMSIZE_Pos)            /*!< Destination Burst Transaction Length : 4   bits  */
#define LL_DMA_DST_MSIZE_8                   (0x00000002U << DMA_CH_CHCTL_DSTMSIZE_Pos)            /*!< Destination Burst Transaction Length : 8   bits  */
#define LL_DMA_DST_MSIZE_16                  (0x00000003U << DMA_CH_CHCTL_DSTMSIZE_Pos)            /*!< Destination Burst Transaction Length : 16  bits  */
#define LL_DMA_DST_MSIZE_32                  (0x00000004U << DMA_CH_CHCTL_DSTMSIZE_Pos)            /*!< Destination Burst Transaction Length : 32  bits  */
#define LL_DMA_DST_MSIZE_64                  (0x00000005U << DMA_CH_CHCTL_DSTMSIZE_Pos)            /*!< Destination Burst Transaction Length : 64  bits  */
#define LL_DMA_DST_MSIZE_128                 (0x00000006U << DMA_CH_CHCTL_DSTMSIZE_Pos)            /*!< Destination Burst Transaction Length : 128 bits  */
#define LL_DMA_DST_MSIZE_256                 (0x00000007U << DMA_CH_CHCTL_DSTMSIZE_Pos)            /*!< Destination Burst Transaction Length : 256 bits  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_SRC_MSIZE Source Burst Transaction Length 
  * @{
  */
#define LL_DMA_SRC_MSIZE_1                   (0x00000000U << DMA_CH_CHCTL_SRCMSIZE_Pos)            /*!< Source Burst Transaction Length : 1   bits  */
#define LL_DMA_SRC_MSIZE_4                   (0x00000001U << DMA_CH_CHCTL_SRCMSIZE_Pos)            /*!< Source Burst Transaction Length : 4   bits  */
#define LL_DMA_SRC_MSIZE_8                   (0x00000002U << DMA_CH_CHCTL_SRCMSIZE_Pos)            /*!< Source Burst Transaction Length : 8   bits  */
#define LL_DMA_SRC_MSIZE_16                  (0x00000003U << DMA_CH_CHCTL_SRCMSIZE_Pos)            /*!< Source Burst Transaction Length : 16  bits  */
#define LL_DMA_SRC_MSIZE_32                  (0x00000004U << DMA_CH_CHCTL_SRCMSIZE_Pos)            /*!< Source Burst Transaction Length : 32  bits  */
#define LL_DMA_SRC_MSIZE_64                  (0x00000005U << DMA_CH_CHCTL_SRCMSIZE_Pos)            /*!< Source Burst Transaction Length : 64  bits  */
#define LL_DMA_SRC_MSIZE_128                 (0x00000006U << DMA_CH_CHCTL_SRCMSIZE_Pos)            /*!< Source Burst Transaction Length : 128 bits  */
#define LL_DMA_SRC_MSIZE_256                 (0x00000007U << DMA_CH_CHCTL_SRCMSIZE_Pos)            /*!< Source Burst Transaction Length : 256 bits  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DEST_PER Destination of channel hardware handshaking interface 
  * @{
  */
#define LL_DMA_DST_PER_IF_0                  (0x00000000UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 0  */
#define LL_DMA_DST_PER_IF_1                  (0x00000001UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 1  */
#define LL_DMA_DST_PER_IF_2                  (0x00000002UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 2  */
#define LL_DMA_DST_PER_IF_3                  (0x00000003UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 3  */
#define LL_DMA_DST_PER_IF_4                  (0x00000004UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 4  */
#define LL_DMA_DST_PER_IF_5                  (0x00000005UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 5  */
#define LL_DMA_DST_PER_IF_6                  (0x00000006UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 6  */
#define LL_DMA_DST_PER_IF_7                  (0x00000007UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 7  */
#define LL_DMA_DST_PER_IF_8                  (0x00000008UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 8  */
#define LL_DMA_DST_PER_IF_9                  (0x00000009UL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 9  */
#define LL_DMA_DST_PER_IF_10                 (0x0000000AUL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 10 */
#define LL_DMA_DST_PER_IF_11                 (0x0000000BUL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 11 */
#define LL_DMA_DST_PER_IF_12                 (0x0000000CUL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 12 */
#define LL_DMA_DST_PER_IF_13                 (0x0000000DUL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 13 */
#define LL_DMA_DST_PER_IF_14                 (0x0000000EUL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 14 */
#define LL_DMA_DST_PER_IF_15                 (0x0000000FUL << DMA_CH_CHCFG_DSTPER_Pos)            /*!< Channel DMA destination hardware handshaking interface 15 */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_SRC_PER Source of channel hardware handshaking interface 
  * @{
  */
#define LL_DMA_SRC_PER_IF_0                  (0x00000000UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 0       */
#define LL_DMA_SRC_PER_IF_1                  (0x00000001UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 1       */
#define LL_DMA_SRC_PER_IF_2                  (0x00000002UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 2       */
#define LL_DMA_SRC_PER_IF_3                  (0x00000003UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 3       */
#define LL_DMA_SRC_PER_IF_4                  (0x00000004UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 4       */
#define LL_DMA_SRC_PER_IF_5                  (0x00000005UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 5       */
#define LL_DMA_SRC_PER_IF_6                  (0x00000006UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 6       */
#define LL_DMA_SRC_PER_IF_7                  (0x00000007UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 7       */
#define LL_DMA_SRC_PER_IF_8                  (0x00000008UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 8       */
#define LL_DMA_SRC_PER_IF_9                  (0x00000009UL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 9       */
#define LL_DMA_SRC_PER_IF_10                 (0x0000000AUL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 10      */
#define LL_DMA_SRC_PER_IF_11                 (0x0000000BUL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 11      */
#define LL_DMA_SRC_PER_IF_12                 (0x0000000CUL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 12      */
#define LL_DMA_SRC_PER_IF_13                 (0x0000000DUL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 13      */
#define LL_DMA_SRC_PER_IF_14                 (0x0000000EUL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 14      */
#define LL_DMA_SRC_PER_IF_15                 (0x0000000FUL << DMA_CH_CHCFG_SRCPER_Pos)            /*!< Channel DMA source hardware handshaking interface 15      */
/**
  * @}
  */
#if DMA_LLP_ENABLE
/** @defgroup DMA_LL_EC_SS_UPD_EN Source Status Update Enable 
  * @{
  */
#define LL_DMA_SS_UPD_EN                     DMA_CH_CHCFG_SSUPDEN             /*!< Channel DMA Source Status Update Enable  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DS_UPD_EN Distination Status Update Enable 
  * @{
  */
#define LL_DMA_DS_UPD_EN                     DMA_CH_CHCFG_DSUPDEN             /*!< Channel DMA Distination Status Update Enable  */
/**
  * @}
  */
#endif /* DMA_LLP_ENABLE */
/** @defgroup DMA_LL_EC_FIFO_MODE FIFO Mode Select 
  * @{
  */
#define LL_DMA_FIFO                          DMA_CH_CHCFG_FIFOMODE            /*!< Channel DMA FIFO Mode Select  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_FCMODE Flow Control Mode Select 
  * @{
  */
#define LL_DMA_FC                            DMA_CH_CHCFG_FCMODE             /*!< Channel DMA Flow Control Mode Select  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_RELOAD_DST Automatic Destination Reload  
  * @{
  */
#define LL_DMA_RELOAD_DST                    DMA_CH_CHCFG_RELDDST             /*!< Channel DMA Automatic Destination Reload */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_RELOAD_SRC Automatic Source Reload  
  * @{
  */
#define LL_DMA_RELOAD_SRC                    DMA_CH_CHCFG_RELDSRC             /*!< Channel DMA Automatic Source Reload */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_SRC_HS_POL Source Handshaking Interface Polarity  
  * @{
  */
#define LL_DMA_SRC_HS_POL_HIGH               0x00000000U                    /*!< Channel DMA Source handshaking Interface Polarity Active high */
#define LL_DMA_SRC_HS_POL_LOW                DMA_CH_CHCFG_SRCHSPOL             /*!< Channel DMA Source handshaking Interface Polarity Active low  */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DST_HS_POL Destination Handshaking Interface Polarity  
  * @{
  */
#define LL_DMA_DST_HS_POL_HIGH               0x00000000U                    /*!< Channel DMA Destination handshaking Interface Polarity Active high */
#define LL_DMA_DST_HS_POL_LOW                DMA_CH_CHCFG_DSTHSPOL             /*!< Channel DMA Destination handshaking Interface Polarity Active low  */
/**
  * @}
  */
#if DMA_LOCK_ENABLE
/** @defgroup DMA_LL_EC_LOCK_B Bus Lock  
  * @{
  */
#define LL_DMA_LOCK_B                        DMA_CH_CHCFG_BLOCK                /*!< Channel DMA Bus Lock */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_LOCK_CH Channel Lock  
  * @{
  */
#define LL_DMA_LOCK_CH                       DMA_CH_CHCFG_LOCK                 /*!< Channel DMA Channel Lock */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_LOCK_B_L Bus Lock Level 
  * @{
  */
#define LL_DMA_LOCK_B_L_TR                   (0x00000000U << DMA_CH_CHCFG_BLOCKL_Pos)                /*!< Channel DMA Bus Lock Level Over complete DMA transfer */
#define LL_DMA_LOCK_B_L_BT                   (0x00000001U << DMA_CH_CHCFG_BLOCKL_Pos)                /*!< Channel DMA Bus Lock Level Over complete DMA block transfer */
#define LL_DMA_LOCK_B_L_TA                   (0x00000002U << DMA_CH_CHCFG_BLOCKL_Pos)                /*!< Channel DMA Bus Lock Level Over complete DMA transaction */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_LOCK_CH_L Channel Lock Level 
  * @{
  */
#define LL_DMA_LOCK_CH_L_TR                  (0x00000000U << DMA_CH_CHCFG_LOCKL_Pos)                 /*!< Channel DMA Channel Lock Level Over complete DMA transfer */
#define LL_DMA_LOCK_CH_L_BT                  (0x00000001U << DMA_CH_CHCFG_LOCKL_Pos)                 /*!< Channel DMA Channel Lock Level Over complete DMA block transfer */
#define LL_DMA_LOCK_CH_L_TA                  (0x00000002U << DMA_CH_CHCFG_LOCKL_Pos)                 /*!< Channel DMA Channel Lock Level Over complete DMA transaction */
/**
  * @}
  */
#endif /* DMA_LOCK_ENABLE */
/** @defgroup DMA_LL_EC_HS_SEL_SRC Source Software or Hardware Handshaking Select  
  * @{
  */
#define LL_DMA_HS_SRC_HW                     0x00000000U                    /*!< Channel DMA Source Hardware Handshaking Select */
#define LL_DMA_HS_SRC_SW                     DMA_CH_CHCFG_SRCHS                /*!< Channel DMA Source Software Handshaking Select */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_HS_SEL_DST Source Software or Hardware Handshaking Select  
  * @{
  */
#define LL_DMA_HS_DST_HW                     0x00000000U                    /*!< Channel DMA Destination Hardware Handshaking Select */
#define LL_DMA_HS_DST_SW                     DMA_CH_CHCFG_DSTHS                /*!< Channel DMA Destination Software Handshaking Select */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_FIFO_EMPTY Indicates if there is data left in the channel FIFO.  
  * @{
  */
#define LL_DMA_FIFO_NOEMPTY                  0x00000000U                    /*!< Channel DMA FIFO is no empty */
#define LL_DMA_FIFO_EMPTY                    DMA_CH_CHCFG_FIFOE                /*!< Channel DMA FIFO is empty    */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_CH_SUSP Channel Suspend.  
  * @{
  */
#define LL_DMA_CH_NOT_SUSP                   0x00000000U                     /*!< Channel DMA Channel not suspend */
#define LL_DMA_CH_SUSP                       DMA_CH_CHCFG_SUSP                  /*!< Channel DMA Channel suspend     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_CH_PRIOR Channel priority.  
  * @{
  */
#define LL_DMA_CH_PRIOR_0                  (0x00000000U << DMA_CH_CHCFG_PRIOR_Pos)                    /*!< Channel DMA Channel priority 0 lowest */
#define LL_DMA_CH_PRIOR_1                  (0x00000001U << DMA_CH_CHCFG_PRIOR_Pos)                    /*!< Channel DMA Channel priority 1        */
#define LL_DMA_CH_PRIOR_2                  (0x00000002U << DMA_CH_CHCFG_PRIOR_Pos)                    /*!< Channel DMA Channel priority 2        */
#define LL_DMA_CH_PRIOR_3                  (0x00000003U << DMA_CH_CHCFG_PRIOR_Pos)                    /*!< Channel DMA Channel priority 3        */
#define LL_DMA_CH_PRIOR_4                  (0x00000004U << DMA_CH_CHCFG_PRIOR_Pos)                    /*!< Channel DMA Channel priority 4        */
#define LL_DMA_CH_PRIOR_5                  (0x00000005U << DMA_CH_CHCFG_PRIOR_Pos)                    /*!< Channel DMA Channel priority 5        */
#define LL_DMA_CH_PRIOR_6                  (0x00000006U << DMA_CH_CHCFG_PRIOR_Pos)                    /*!< Channel DMA Channel priority 6        */
#define LL_DMA_CH_PRIOR_7                  (0x00000007U << DMA_CH_CHCFG_PRIOR_Pos)                    /*!< Channel DMA Channel priority 7        */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_INT Interrupt position of Channel.  
  * @{
  */
#define LL_DMA_INT_CH_0                    (0x00000001U)                    /*!< Channel DMA Interrupt Channel 0        */
#define LL_DMA_INT_CH_1                    (0x00000002U)                    /*!< Channel DMA Interrupt Channel 1        */
#define LL_DMA_INT_CH_2                    (0x00000004U)                    /*!< Channel DMA Interrupt Channel 2        */
#define LL_DMA_INT_CH_3                    (0x00000008U)                    /*!< Channel DMA Interrupt Channel 3        */
#define LL_DMA_INT_CH_4                    (0x00000010U)                    /*!< Channel DMA Interrupt Channel 4        */
#define LL_DMA_INT_CH_5                    (0x00000020U)                    /*!< Channel DMA Interrupt Channel 5        */
#define LL_DMA_INT_CH_6                    (0x00000040U)                    /*!< Channel DMA Interrupt Channel 6        */
#define LL_DMA_INT_CH_7                    (0x00000080U)                    /*!< Channel DMA Interrupt Channel 7        */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_INT_Mask Interrupt mask of Channel.  
  * @{
  */
#define LL_DMA_INT_UNMASK_CH_0             (0x00000001U << DMA_MSK_EN_Pos)                    /*!< Channel DMA Interrupt Channel 0 unmask */
#define LL_DMA_INT_UNMASK_CH_1             (0x00000002U << DMA_MSK_EN_Pos)                    /*!< Channel DMA Interrupt Channel 1 unmask */
#define LL_DMA_INT_UNMASK_CH_2             (0x00000004U << DMA_MSK_EN_Pos)                    /*!< Channel DMA Interrupt Channel 2 unmask */
#define LL_DMA_INT_UNMASK_CH_3             (0x00000008U << DMA_MSK_EN_Pos)                    /*!< Channel DMA Interrupt Channel 3 unmask */
#define LL_DMA_INT_UNMASK_CH_4             (0x00000010U << DMA_MSK_EN_Pos)                    /*!< Channel DMA Interrupt Channel 4 unmask */
#define LL_DMA_INT_UNMASK_CH_5             (0x00000020U << DMA_MSK_EN_Pos)                    /*!< Channel DMA Interrupt Channel 5 unmask */
#define LL_DMA_INT_UNMASK_CH_6             (0x00000040U << DMA_MSK_EN_Pos)                    /*!< Channel DMA Interrupt Channel 6 unmask */
#define LL_DMA_INT_UNMASK_CH_7             (0x00000080U << DMA_MSK_EN_Pos)                    /*!< Channel DMA Interrupt Channel 7 unmask */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_INT_MASK_WE Interrupt mask writeenable of Channel.  
  * @{
  */
#define LL_DMA_INT_MASK_WE_CH_0            (0x00000001U << DMA_MSK_WE_Pos)                    /*!< Channel DMA Interrupt Channel 0 mask write enable */
#define LL_DMA_INT_MASK_WE_CH_1            (0x00000002U << DMA_MSK_WE_Pos)                    /*!< Channel DMA Interrupt Channel 1 mask write enable */
#define LL_DMA_INT_MASK_WE_CH_2            (0x00000004U << DMA_MSK_WE_Pos)                    /*!< Channel DMA Interrupt Channel 2 mask write enable */
#define LL_DMA_INT_MASK_WE_CH_3            (0x00000008U << DMA_MSK_WE_Pos)                    /*!< Channel DMA Interrupt Channel 3 mask write enable */
#define LL_DMA_INT_MASK_WE_CH_4            (0x00000010U << DMA_MSK_WE_Pos)                    /*!< Channel DMA Interrupt Channel 4 mask write enable */
#define LL_DMA_INT_MASK_WE_CH_5            (0x00000020U << DMA_MSK_WE_Pos)                    /*!< Channel DMA Interrupt Channel 5 mask write enable */
#define LL_DMA_INT_MASK_WE_CH_6            (0x00000040U << DMA_MSK_WE_Pos)                    /*!< Channel DMA Interrupt Channel 6 mask write enable */
#define LL_DMA_INT_MASK_WE_CH_7            (0x00000080U << DMA_MSK_WE_Pos)                    /*!< Channel DMA Interrupt Channel 7 mask write enable */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_HS Handshaking of Channel.  
  * @{
  */
#define LL_DMA_HS_CH_0                     (0x00000001U << DMA_REQSRC_EN_Pos)                    /*!< Channel DMA Channel 0 Handshaking */
#define LL_DMA_HS_CH_1                     (0x00000002U << DMA_REQSRC_EN_Pos)                    /*!< Channel DMA Channel 1 Handshaking */
#define LL_DMA_HS_CH_2                     (0x00000004U << DMA_REQSRC_EN_Pos)                    /*!< Channel DMA Channel 2 Handshaking */
#define LL_DMA_HS_CH_3                     (0x00000008U << DMA_REQSRC_EN_Pos)                    /*!< Channel DMA Channel 3 Handshaking */
#define LL_DMA_HS_CH_4                     (0x00000010U << DMA_REQSRC_EN_Pos)                    /*!< Channel DMA Channel 4 Handshaking */
#define LL_DMA_HS_CH_5                     (0x00000020U << DMA_REQSRC_EN_Pos)                    /*!< Channel DMA Channel 5 Handshaking */
#define LL_DMA_HS_CH_6                     (0x00000040U << DMA_REQSRC_EN_Pos)                    /*!< Channel DMA Channel 6 Handshaking */
#define LL_DMA_HS_CH_7                     (0x00000080U << DMA_REQSRC_EN_Pos)                    /*!< Channel DMA Channel 7 Handshaking */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_HS_WE handshaking write enable of Channel.  
  * @{
  */
#define LL_DMA_HS_WE_CH_0                  (0x00000001U << DMA_REQSRC_WE_Pos)                    /*!< Channel DMA Channel 0 handshaking write enable */
#define LL_DMA_HS_WE_CH_1                  (0x00000002U << DMA_REQSRC_WE_Pos)                    /*!< Channel DMA Channel 1 handshaking write enable */
#define LL_DMA_HS_WE_CH_2                  (0x00000004U << DMA_REQSRC_WE_Pos)                    /*!< Channel DMA Channel 2 handshaking write enable */
#define LL_DMA_HS_WE_CH_3                  (0x00000008U << DMA_REQSRC_WE_Pos)                    /*!< Channel DMA Channel 3 handshaking write enable */
#define LL_DMA_HS_WE_CH_4                  (0x00000010U << DMA_REQSRC_WE_Pos)                    /*!< Channel DMA Channel 4 handshaking write enable */
#define LL_DMA_HS_WE_CH_5                  (0x00000020U << DMA_REQSRC_WE_Pos)                    /*!< Channel DMA Channel 5 handshaking write enable */
#define LL_DMA_HS_WE_CH_6                  (0x00000040U << DMA_REQSRC_WE_Pos)                    /*!< Channel DMA Channel 6 handshaking write enable */
#define LL_DMA_HS_WE_CH_7                  (0x00000080U << DMA_REQSRC_WE_Pos)                    /*!< Channel DMA Channel 7 handshaking write enable */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_TEST DMA Test Mode 
  * @{
  */
#define LL_DMA_MODE_NORMAL                 0x00000000U              /*!< Normal Mode              */
#define LL_DMA_MODE_TEST                   DMA_TST_SLVIF            /*!< Test Mode                */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_MODE DMA Mode 
  * @{
  */
#define LL_DMA_TFRMODE_SGLBLK              0x00000000U              /*!< Single-block or last transfer of multi-block \
                                                                         LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#define LL_DMA_TFRMODE_MULBLK_ARLD_CONSAR  0x00000001U              /*!< Auto-reload multi-block transfer with contiguous SAR \
                                                                         LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */
#define LL_DMA_TFRMODE_MULBLK_ARLD_CONDAR  0x00000002U              /*!< Auto-reload multi-block transfer with contiguous DAR \
                                                                         LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#define LL_DMA_TFRMODE_MULBLK_ARLD         0x00000003U              /*!< Auto-reload multi-block transfer \
                                                                         LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */
#define LL_DMA_TFRMODE_MULBLK_LLST_CONSAR  0x00000004U              /*!< Linked list multi-block transfer with contiguous SAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
#define LL_DMA_TFRMODE_MULBLK_LLST_ARLSAR  0x00000005U              /*!< Linked list multi-block transfer with auto-reload SAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
#define LL_DMA_TFRMODE_MULBLK_LLST_CONDAR  0x00000006U              /*!< Linked list multi-block transfer with contiguous DAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0  */
#define LL_DMA_TFRMODE_MULBLK_LLST_ARLDAR  0x00000007U              /*!< Linked list multi-block transfer with auto-reload DAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1  */
#define LL_DMA_TFRMODE_MULBLK_LLST         0x00000008U              /*!< Linked list multi-block transfer \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
//#endif /* DMA_PLL_ENABLE */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DMA_HANDSHAKING_MUX DMA HandShaking Mux
  * @{
  */
/*dma config 0*/
#define LL_DMAMUX_HS_DST_CFG0_UART1             LL_DMA_DST_PER_IF_0      /*!< DMA Dst UART0            */
#define LL_DMAMUX_HS_DST_CFG0_UART2             LL_DMA_DST_PER_IF_2      /*!< DMA Dst UART1            */
#define LL_DMAMUX_HS_DST_CFG0_EPWM              LL_DMA_DST_PER_IF_4      /*!< DMA Dst Combined PWM     */
#define LL_DMAMUX_HS_DST_CFG0_I2C1              LL_DMA_DST_PER_IF_8      /*!< DMA Dst I2C0             */
#define LL_DMAMUX_HS_DST_CFG0_CRC               LL_DMA_DST_PER_IF_10     /*!< DMA Dst CRC              */
#define LL_DMAMUX_HS_DST_CFG0_SPI1              LL_DMA_DST_PER_IF_12     /*!< DMA Dst SPI0             */
#define LL_DMAMUX_HS_DST_CFG0_SPI2              LL_DMA_DST_PER_IF_14     /*!< DMA Dst SPI1             */

#define LL_DMAMUX_HS_SRC_CFG0_UART1             LL_DMA_SRC_PER_IF_1      /*!< DMA Src UART0            */
#define LL_DMAMUX_HS_SRC_CFG0_UART2             LL_DMA_SRC_PER_IF_3      /*!< DMA Src UART1            */
#define LL_DMAMUX_HS_SRC_CFG0_ADCEOS            LL_DMA_SRC_PER_IF_5      /*!< DMA Src ADC EOS          */
#define LL_DMAMUX_HS_SRC_CFG0_ADCEOC            LL_DMA_SRC_PER_IF_7      /*!< DMA Src ADC EOC          */
#define LL_DMAMUX_HS_SRC_CFG0_I2C1              LL_DMA_SRC_PER_IF_9      /*!< DMA Src I2C0             */
#define LL_DMAMUX_HS_SRC_CFG0_CRC               LL_DMA_SRC_PER_IF_11     /*!< DMA Src CRC              */
#define LL_DMAMUX_HS_SRC_CFG0_SPI1              LL_DMA_SRC_PER_IF_13     /*!< DMA Src SPI0             */
#define LL_DMAMUX_HS_SRC_CFG0_SPI2              LL_DMA_SRC_PER_IF_15     /*!< DMA Src SPI1             */

/*dma config 1*/
#define LL_DMAMUX_HS_DST_CFG1_I2C1              LL_DMA_DST_PER_IF_0      /*!< DMA Dst I2C0             */
#define LL_DMAMUX_HS_DST_CFG1_UART3             LL_DMA_DST_PER_IF_4      /*!< DMA Dst UART2            */
#define LL_DMAMUX_HS_DST_CFG1_UART4             LL_DMA_DST_PER_IF_6      /*!< DMA Dst UART3            */
#define LL_DMAMUX_HS_DST_CFG1_SPI1              LL_DMA_DST_PER_IF_8      /*!< DMA Dst SPI0             */
#define LL_DMAMUX_HS_DST_CFG1_I2C2              LL_DMA_DST_PER_IF_10     /*!< DMA Dst I1C1             */
#define LL_DMAMUX_HS_DST_CFG1_UART5             LL_DMA_DST_PER_IF_12     /*!< DMA Dst UART2            */
#define LL_DMAMUX_HS_DST_CFG1_I2C3              LL_DMA_DST_PER_IF_14     /*!< DMA Dst I2C0             */

#define LL_DMAMUX_HS_SRC_CFG1_I2C1              LL_DMA_SRC_PER_IF_1      /*!< DMA SRC I2C0             */
#define LL_DMAMUX_HS_SRC_CFG1_UART3             LL_DMA_SRC_PER_IF_5      /*!< DMA SRC UART2            */
#define LL_DMAMUX_HS_SRC_CFG1_UART4             LL_DMA_SRC_PER_IF_7      /*!< DMA SRC UART3            */
#define LL_DMAMUX_HS_SRC_CFG1_SPI1              LL_DMA_SRC_PER_IF_9      /*!< DMA SRC SPI0             */
#define LL_DMAMUX_HS_SRC_CFG1_I2C2              LL_DMA_SRC_PER_IF_11     /*!< DMA SRC I1C1             */
#define LL_DMAMUX_HS_SRC_CFG1_UART5             LL_DMA_SRC_PER_IF_13     /*!< DMA SRC UART2            */
#define LL_DMAMUX_HS_SRC_CFG1_I2C3              LL_DMA_SRC_PER_IF_15     /*!< DMA SRC I2C0             */

/*dma config 2*/
#define LL_DMAMUX_HS_DST_CFG2_SPI1              LL_DMA_DST_PER_IF_0      /*!< DMA Dst SPI0             */
#define LL_DMAMUX_HS_DST_CFG2_PWMTRG            LL_DMA_DST_PER_IF_2      /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG2_PWM1              LL_DMA_DST_PER_IF_4      /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG2_PWM2              LL_DMA_DST_PER_IF_6      /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG2_PWM3              LL_DMA_DST_PER_IF_8      /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG2_PWM4              LL_DMA_DST_PER_IF_10     /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG2_PWMUDT            LL_DMA_DST_PER_IF_12     /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG2_UART2             LL_DMA_DST_PER_IF_14     /*!< DMA Dst UART1            */

#define LL_DMAMUX_HS_SRC_CFG2_SPI1              LL_DMA_SRC_PER_IF_1      /*!< DMA Src SPI0             */
#define LL_DMAMUX_HS_SRC_CFG2_UART2             LL_DMA_SRC_PER_IF_15     /*!< DMA Src UART1            */

/*dma config 3*/
#if defined(XT32T07xx)
#define LL_DMAMUX_HS_DST_CFG3_LEDFRM            LL_DMA_DST_PER_IF_0      /*!< DMA Dst LED FRM          */
#define LL_DMAMUX_HS_DST_CFG3_LEDUDT            LL_DMA_DST_PER_IF_1      /*!< DMA Dst LED UDT          */
#define LL_DMAMUX_HS_DST_CFG3_LEDCOM            LL_DMA_DST_PER_IF_3      /*!< DMA Dst LED COM          */
#endif //XT8001
#define LL_DMAMUX_HS_DST_CFG3_TIMGTRG           LL_DMA_DST_PER_IF_2      /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG3_TIMG1             LL_DMA_DST_PER_IF_4      /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG3_TIMG2             LL_DMA_DST_PER_IF_6      /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG3_TIMG3             LL_DMA_DST_PER_IF_8      /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG3_TIMG4             LL_DMA_DST_PER_IF_10     /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG3_TIMGUDT           LL_DMA_DST_PER_IF_12     /*!< DMA Dst PWM              */
#define LL_DMAMUX_HS_DST_CFG3_TIMGR             LL_DMA_DST_PER_IF_14     /*!< DMA Dst UART1            */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Macros DMA Exported Macros
  * @{
  */

/** @defgroup DMA_LL_EM_WRITE_READ Common Write and read registers macros
  * @{
  */
/**
  * @brief  Write a value in DMA register
  * @param  __INSTANCE__ DMA Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_DMA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in DMA register
  * @param  __INSTANCE__ DMA Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_DMA_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup DMA_LL_EM_CONVERT_DMAxCHANNELy Convert DMAxChannely
  * @{
  */
/**
  * @brief  Convert DMAx_Channely into DMAx
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval DMAx
  */
#define __LL_DMA_GET_INSTANCE(__CHANNEL_INSTANCE__)  (DMA1)

/**
  * @brief  Convert DMAx_Channely into LL_DMA_CHANNEL_y
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval LL_DMA_CHANNEL_y
  */
#define __LL_DMA_GET_CHANNEL(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel0)) ? LL_DMA_CHANNEL_0 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel1)) ? LL_DMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel2)) ? LL_DMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel3)) ? LL_DMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel4)) ? LL_DMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel5)) ? LL_DMA_CHANNEL_5 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel6)) ? LL_DMA_CHANNEL_6 : \
 LL_DMA_CHANNEL_7)

/**
  * @brief  Convert DMA Instance DMAx and LL_DMA_CHANNEL_y into DMAx_Channely
  * @param  __DMA_INSTANCE__ DMAx
  * @param  __CHANNEL__ LL_DMA_CHANNEL_y
  * @retval DMAx_Channely
  */
#define __LL_DMA_GET_CHANNEL_INSTANCE(__DMA_INSTANCE__, __CHANNEL__)   \
((((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_0))) ? DMA1_Channel0 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA1_Channel1 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA1_Channel2 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA1_Channel3 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA1_Channel4 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA1_Channel5 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_6))) ? DMA1_Channel6 : \
 DMA1_Channel7)

/**
  * @brief  Convert DMAx_Channely into DMAx Auxiliary
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval DMAx Interrupt
  */
#define __LL_DMA_GET_AUXILIARY(__CHANNEL_INSTANCE__)  (DMAAUX1)

/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Functions DMA Exported Functions
 * @{
 */

/** @defgroup DMA_LL_Exported_Functions_Group1 Configuration
  * @{
  */
/**
  * @brief  Enable DMAx.
  * @rmtoll DmaCfgReg   EN            LL_DMA_Enable
  * @param  DMAx DMAx Instance
  */
__STATIC_INLINE void LL_DMA_Enable(DMA_TypeDef *DMAx)
{
  SET_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->DMACFG, DMA_DMACFG_EN);
}

/**
  * @brief  Disable DMAx.
  * @rmtoll DmaCfgReg   EN            LL_DMA_Disable
  * @param  DMAx DMAx Instance
  */
__STATIC_INLINE void LL_DMA_Disable(DMA_TypeDef *DMAx)
{
  CLEAR_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->DMACFG, DMA_DMACFG_EN);
}

/**
  * @brief  Check if DMAx is enabled or disabled.
  * @rmtoll CCDmaCfgReg  EN            LL_DMA_IsEnabled
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabled(DMA_TypeDef *DMAx)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->DMACFG, DMA_DMACFG_EN) == (DMA_DMACFG_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable DMAx channel.
  * @rmtoll ChEnReg   CH_EN            LL_DMA_EnableChannel
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
  */
__STATIC_INLINE void LL_DMA_EnableChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->CHEN = ((DMA_CHEN_WE_0|DMA_CHEN_EN_0) << Channel);
}

/**
  * @brief  Disable DMAx channel.
  * @rmtoll ChEnReg   CH_EN            LL_DMA_DisableChannel
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
  */
__STATIC_INLINE void LL_DMA_DisableChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->CHEN = (DMA_CHEN_WE_0 << Channel);
}

/**
  * @brief  Check if DMAx channel is enabled or disabled.
  * @rmtoll ChEnReg   CH_EN            LL_DMA_IsEnabledChannel
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->CHEN, (DMA_CHEN_EN_0 << Channel)) == (DMA_CHEN_EN_0 << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Configure all parameters link to DMA transfer.
  * @rmtoll CTLx         TT_FC           LL_DMA_ConfigTransfer\n
  *         CTLx         SINC            LL_DMA_ConfigTransfer\n
  *         CTLx         DINC            LL_DMA_ConfigTransfer\n
  *         CTLx         SRC_TR_WIDTH    LL_DMA_ConfigTransfer\n
  *         CTLx         DST_TR_WIDTH    LL_DMA_ConfigTransfer\n
  *         CTLx         SRC_MSIZE       LL_DMA_ConfigTransfer\n
  *         CTLx         DST_MSUZE       LL_DMA_ConfigTransfer\n
  *         CTLx         BLOCK_TS        LL_DMA_ConfigTransfer\n
  *         CTLx         INT_EN          LL_DMA_ConfigTransfer\n
  *         CFGx         CH_PRIOR        LL_DMA_ConfigTransfer\n
  *         CFGx         FIFO_MODE       LL_DMA_ConfigTransfer\n
  *         CFGx         FCMODE          LL_DMA_ConfigTransfer
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
  * @param  Configuration1 This parameter must be a combination of all the following values:
  *         @arg @ref DMA_LL_EC_DIRECTION
  *         @arg @ref DMA_LL_EC_SINC
  *         @arg @ref DMA_LL_EC_DINC
  *         @arg @ref DMA_LL_EC_SRC_TRWIDTH
  *         @arg @ref DMA_LL_EC_DST_TRWIDTH
  *         @arg @ref DMA_LL_EC_SRC_MSIZE
  *         @arg @ref DMA_LL_EC_DST_MSIZE
  *         @arg @ref DMA_LL_EC_INTE
  * @param  Configuration2 This parameter must be one of DMA_CH_CHCTL_BLOCKTS or 0
  * @param  Configuration3 This parameter must be a combination of all the following values:
  *         @arg @ref DMA_LL_EC_CH_PRIOR
  * @param  Configuration4 This parameter must be a combination of all the following values:
  *         @arg @ref DMA_LL_EC_FIFO_MODE
  *         @arg @ref DMA_LL_EC_FCMODE
  */
__STATIC_INLINE void LL_DMA_ConfigTransfer(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Configuration1, uint32_t Configuration2, uint32_t Configuration3, uint32_t Configuration4)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L,
             DMA_CH_CHCTL_TTFC | DMA_CH_CHCTL_SINC | DMA_CH_CHCTL_DINC | DMA_CH_CHCTL_SRCTRW | 
	           DMA_CH_CHCTL_DSTTRW | DMA_CH_CHCTL_SRCMSIZE | DMA_CH_CHCTL_DSTMSIZE | DMA_CH_CHCTL_INTEN,
             Configuration1);
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_H,
             DMA_CH_CHCTL_BLOCKTS,
             Configuration2);
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_PRIOR,
             Configuration3);
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H,
             DMA_CH_CHCFG_FCMODE,
             Configuration4);
}

/**
  * @brief  Set Data transfer direction (read from peripheral or from memory).
  * @rmtoll CTLx         TT_FC       LL_DMA_SetDataTransferDirection
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
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref LL_DMA_MEMORY_TO_MEMORY_FC_DMAC
  *         @arg @ref LL_DMA_MEMORY_TO_PERIPH_FC_DMAC
  *         @arg @ref LL_DMA_PERIPH_TO_MEMORY_FC_DMAC
  *         @arg @ref LL_DMA_PERIPH_TO_PERIPH_FC_DMAC
  *         @arg @ref LL_DMA_PERIPH_TO_MEMORY_FC_PERI
  *         @arg @ref LL_DMA_PERIPH_TO_PERIPH_FC_SRCP
  *         @arg @ref LL_DMA_MEMORY_TO_PERIPH_FC_PERI
  *         @arg @ref LL_DMA_PERIPH_TO_PERIPH_FC_DSTP
  */
__STATIC_INLINE void LL_DMA_SetDataTransferDirection(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Direction)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)(__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel)))->CTL_L,
             DMA_CH_CHCTL_TTFC, Direction);
}

/**
  * @brief  Get Data transfer direction (read from peripheral or from memory).
  * @rmtoll CTLx         TT_FC       LL_DMA_SetDataTransferDirection
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_MEMORY_TO_MEMORY_FC_DMAC
  *         @arg @ref LL_DMA_MEMORY_TO_PERIPH_FC_DMAC
  *         @arg @ref LL_DMA_PERIPH_TO_MEMORY_FC_DMAC
  *         @arg @ref LL_DMA_PERIPH_TO_PERIPH_FC_DMAC
  *         @arg @ref LL_DMA_PERIPH_TO_MEMORY_FC_PERI
  *         @arg @ref LL_DMA_PERIPH_TO_PERIPH_FC_SRCP
  *         @arg @ref LL_DMA_MEMORY_TO_PERIPH_FC_PERI
  *         @arg @ref LL_DMA_PERIPH_TO_PERIPH_FC_DSTP
  */
__STATIC_INLINE uint32_t LL_DMA_GetDataTransferDirection(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)(__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel)))->CTL_L,
                   DMA_CH_CHCTL_TTFC));
}

/**
  * @brief  Set DMA mode circular or normal.
  * @note The circular buffer mode cannot be used if the memory-to-memory
  * data transfer is configured on the selected Channel.
  * @rmtoll LLPx          LOC          LL_DMA_SetMode\n
  *         CTLx          LLP_SRC_EN   LL_DMA_SetMode\n
  *         CTLx          LLP_DST_EN   LL_DMA_SetMode\n
  *         CFGx          RELOAD_SRC   LL_DMA_SetMode\n
  *         CFGx          RELOAD_DST   LL_DMA_SetMode
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
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_DMA_TFRMODE_SGLBLK
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_ARLD_CONSAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_ARLD_CONDAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_ARLD
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST_CONSAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST_ARLSAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST_CONDAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST_ARLDAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST
  * @param  LlpAddr should be 0
  */
__STATIC_INLINE void LL_DMA_SetMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Mode, uint32_t LlpAddr)
{
  switch(Mode)
  {
    case LL_DMA_TFRMODE_SGLBLK :                                    /*!< Single-block or last transfer of multi-block \
	                                                                        LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#if DMA_LLP_ENABLE
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, 0);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
#else
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
#endif 		
      break;
    case LL_DMA_TFRMODE_MULBLK_ARLD_CONSAR :                        /*!< Auto-reload multi-block transfer with contiguous SAR \
	                                                                        LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */
#if DMA_LLP_ENABLE
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, 0);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_DST);                                                                 
#else
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_DST);                                                                 
#endif 		
      break;
    case LL_DMA_TFRMODE_MULBLK_ARLD_CONDAR :                        /*!< Auto-reload multi-block transfer with contiguous DAR \
	                                                                        LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#if DMA_LLP_ENABLE
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, 0);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_SRC);                                                                 
#else
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_SRC);                                                                 
#endif 		
      break;
    case LL_DMA_TFRMODE_MULBLK_ARLD :                               /*!< Auto-reload multi-block transfer \
	                                                                        LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */
#if DMA_LLP_ENABLE
  		MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, 0);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_DST | LL_DMA_RELOAD_SRC);                                                                 
#else
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_DST | LL_DMA_RELOAD_SRC);                                                                 
#endif 		
      break;
#if DMA_LLP_ENABLE		
    case LL_DMA_TFRMODE_MULBLK_LLST_CONSAR :                        /*!< Linked list multi-block transfer with contiguous SAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPDST_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
      break;
    case LL_DMA_TFRMODE_MULBLK_LLST_ARLSAR :                        /*!< Linked list multi-block transfer with auto-reload SAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPDST_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_SRC);                                                                 
      break;
    case LL_DMA_TFRMODE_MULBLK_LLST_CONDAR :                        /*!< Linked list multi-block transfer with contiguous DAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPSRC_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
      break;
    case LL_DMA_TFRMODE_MULBLK_LLST_ARLDAR :                        /*!< Linked list multi-block transfer with auto-reload DAR \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPSRC_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, LL_DMA_RELOAD_DST);                                                                 
      break;
    case LL_DMA_TFRMODE_MULBLK_LLST :                               /*!< Linked list multi-block transfer \
                                                                         LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, LL_DMA_LLPDST_ENABLE | LL_DMA_LLPSRC_ENABLE);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0);                                                                 
      break;
#endif			
    default :
#if DMA_LLP_ENABLE	
  		MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC, LlpAddr);  
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN | DMA_CH_CHCTL_LLPSRCEN, 0);                                                                 
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0); 
#else
      MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST | DMA_CH_CHCFG_RELDSRC, 0); 
#endif 		
      break;
  }
}

/**
  * @brief  Get DMA mode circular or normal.
  * @rmtoll LLPx          LOC          LL_DMA_GetMode\n
  *         CTLx          LLP_SRC_EN   LL_DMA_GetMode\n
  *         CTLx          LLP_DST_EN   LL_DMA_GetMode\n
  *         CFGx          RELOAD_SRC   LL_DMA_GetMode\n
  *         CFGx          RELOAD_DST   LL_DMA_GetMode
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_TFRMODE_SGLBLK
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_ARLD_CONSAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_ARLD_CONDAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_ARLD
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST_CONSAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST_ARLSAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST_CONDAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST_ARLDAR
  *         @arg @ref LL_DMA_TFRMODE_MULBLK_LLST
  */
__STATIC_INLINE uint32_t LL_DMA_GetMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
#if DMA_LLP_ENABLE	
    uint32_t loc    = READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->LLP_L, DMA_CHLLP_LOC);
    uint32_t llpsrc = READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPSRCEN);
    uint32_t llpdst = READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_LLPDSTEN);
#endif	
    uint32_t rldsrc = READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDSRC);
    uint32_t rlddst = READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_RELDDST);

#if DMA_LLP_ENABLE	
    if(llpsrc)
    {
      if(llpdst)
      {
        return (uint32_t)LL_DMA_TFRMODE_MULBLK_LLST;
      }
      else
      {
         if(rlddst) 
         {
           return (uint32_t)LL_DMA_TFRMODE_MULBLK_LLST_ARLDAR; 
         }
         else
         {
           return (uint32_t)LL_DMA_TFRMODE_MULBLK_LLST_CONDAR;
         }
      }
    }
    else
#endif 			
    {
      if (rldsrc)
      {
#if DMA_LLP_ENABLE				
        if (llpdst)
        {
          return (uint32_t)LL_DMA_TFRMODE_MULBLK_LLST_ARLSAR;  
        }
        else
#endif				
        {
          if (rlddst)
          {
            return (uint32_t)LL_DMA_TFRMODE_MULBLK_ARLD;
          }
          else
          {
            return (uint32_t)LL_DMA_TFRMODE_MULBLK_ARLD_CONDAR;
          }
        }
      }
      else
      {
#if DMA_LLP_ENABLE				
        if (llpdst)
        {
            return (uint32_t)LL_DMA_TFRMODE_MULBLK_LLST_CONSAR; 
        }
        else
#endif				
        {
          if(rlddst)
          {
            return (uint32_t)LL_DMA_TFRMODE_MULBLK_ARLD_CONSAR;
          }
          else
          {
            return (uint32_t)LL_DMA_TFRMODE_SGLBLK;
          }
        }
      }
    }
}

/**
  * @brief  Set Source increment mode.
  * @rmtoll CTL          SINC          LL_DMA_SetSourceIncMode
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
  * @param  SrcIncMode This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SINC_INCREMENT
  *         @arg @ref LL_DMA_SINC_DECREMENT
  *         @arg @ref LL_DMA_SINC_NOCHANGE
  */
__STATIC_INLINE void LL_DMA_SetSourceIncMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcIncMode)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SINC,
             SrcIncMode);
}

/**
  * @brief  Get Source increment mode.
  * @rmtoll CTL          SINC          LL_DMA_GetSourceIncMode
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SINC_INCREMENT
  *         @arg @ref LL_DMA_SINC_DECREMENT
  *         @arg @ref LL_DMA_SINC_NOCHANGE
  */
__STATIC_INLINE uint32_t LL_DMA_GetSourceIncMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SINC));
}

/**
  * @brief  Set Destination increment mode.
  * @rmtoll CTL          DINC          LL_DMA_SetDestinationIncMode
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
  * @param  DstIncMode This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DINC_INCREMENT
  *         @arg @ref LL_DMA_DINC_DECREMENT
  *         @arg @ref LL_DMA_DINC_NOCHANGE
  */
__STATIC_INLINE void LL_DMA_SetDestinationIncMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t DstIncMode)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DINC,
             DstIncMode);
}

/**
  * @brief  Get Destination increment mode.
  * @rmtoll CTL          DINC          LL_DMA_GetDestionationIncMode
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DINC_INCREMENT
  *         @arg @ref LL_DMA_DINC_DECREMENT
  *         @arg @ref LL_DMA_DINC_NOCHANGE
  */
__STATIC_INLINE uint32_t LL_DMA_GetDestinationIncMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DINC));
}

/**
  * @brief  Set Source size.
  * @rmtoll CTL          SRC_TR_WIDTH         LL_DMA_SetSourceSize
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
  * @param  SrcDataSize This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_TRWIDTH_8  
  *         @arg @ref LL_DMA_SRC_TRWIDTH_16 
  *         @arg @ref LL_DMA_SRC_TRWIDTH_32 
  *         @arg @ref LL_DMA_SRC_TRWIDTH_64 
  *         @arg @ref LL_DMA_SRC_TRWIDTH_128
  *         @arg @ref LL_DMA_SRC_TRWIDTH_256
  */
__STATIC_INLINE void LL_DMA_SetSourceSize(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcDataSize)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SRCTRW,
             SrcDataSize);
}

/**
  * @brief  Get Source size.
  * @rmtoll CTL          SRC_TR_WIDTH         LL_DMA_GetSourceSize
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_TRWIDTH_8  
  *         @arg @ref LL_DMA_SRC_TRWIDTH_16 
  *         @arg @ref LL_DMA_SRC_TRWIDTH_32 
  *         @arg @ref LL_DMA_SRC_TRWIDTH_64 
  *         @arg @ref LL_DMA_SRC_TRWIDTH_128
  *         @arg @ref LL_DMA_SRC_TRWIDTH_256
  */
__STATIC_INLINE uint32_t LL_DMA_GetSourceSize(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L,
                   DMA_CH_CHCTL_SRCTRW));
}

/**
  * @brief  Set Destination size.
  * @rmtoll CTL          DST_TR_WIDTH         LL_DMA_SetDestinationSize
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
  * @param  DstDataSize This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DST_TRWIDTH_8  
  *         @arg @ref LL_DMA_DST_TRWIDTH_16 
  *         @arg @ref LL_DMA_DST_TRWIDTH_32 
  *         @arg @ref LL_DMA_DST_TRWIDTH_64 
  *         @arg @ref LL_DMA_DST_TRWIDTH_128
  *         @arg @ref LL_DMA_DST_TRWIDTH_256
  */
__STATIC_INLINE void LL_DMA_SetDestinationSize(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t DstDataSize)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DSTTRW,
             DstDataSize);
}

/**
  * @brief  Get Destination size.
  * @rmtoll CTL          DST_TR_WIDTH         LL_DMA_GetDestinationSize
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DST_TRWIDTH_8  
  *         @arg @ref LL_DMA_DST_TRWIDTH_16 
  *         @arg @ref LL_DMA_DST_TRWIDTH_32 
  *         @arg @ref LL_DMA_DST_TRWIDTH_64 
  *         @arg @ref LL_DMA_DST_TRWIDTH_128
  *         @arg @ref LL_DMA_DST_TRWIDTH_256
  */
__STATIC_INLINE uint32_t LL_DMA_GetDestinationSize(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L,
                   DMA_CH_CHCTL_DSTTRW));
}

/**
  * @brief  Set Source Burst size.
  * @rmtoll CTL          SRC_MSIZE         LL_DMA_SetSourceBurstSize
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
  * @param  SrcBurstSize This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_MSIZE_1  
  *         @arg @ref LL_DMA_SRC_MSIZE_4  
  *         @arg @ref LL_DMA_SRC_MSIZE_8  
  *         @arg @ref LL_DMA_SRC_MSIZE_16 
  *         @arg @ref LL_DMA_SRC_MSIZE_32 
  *         @arg @ref LL_DMA_SRC_MSIZE_64 
  *         @arg @ref LL_DMA_SRC_MSIZE_128
  *         @arg @ref LL_DMA_SRC_MSIZE_256
  */
__STATIC_INLINE void LL_DMA_SetSourceBurstSize(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcBurstSize)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SRCMSIZE,
             SrcBurstSize);
}

/**
  * @brief  Get Source Burst size.
  * @rmtoll CTL          SRC_MSIZE         LL_DMA_GetSourceBurstSize
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_MSIZE_1  
  *         @arg @ref LL_DMA_SRC_MSIZE_4  
  *         @arg @ref LL_DMA_SRC_MSIZE_8  
  *         @arg @ref LL_DMA_SRC_MSIZE_16 
  *         @arg @ref LL_DMA_SRC_MSIZE_32 
  *         @arg @ref LL_DMA_SRC_MSIZE_64 
  *         @arg @ref LL_DMA_SRC_MSIZE_128
  *         @arg @ref LL_DMA_SRC_MSIZE_256
  */
__STATIC_INLINE uint32_t LL_DMA_GetSourceBurstSize(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L,
                   DMA_CH_CHCTL_SRCMSIZE));
}

/**
  * @brief  Set Destination Burst size.
  * @rmtoll CTL          DST_MSIZE         LL_DMA_SetDestinationBurstSize
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
  * @param  DstBurstSize This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DST_MSIZE_1  
  *         @arg @ref LL_DMA_DST_MSIZE_4  
  *         @arg @ref LL_DMA_DST_MSIZE_8  
  *         @arg @ref LL_DMA_DST_MSIZE_16 
  *         @arg @ref LL_DMA_DST_MSIZE_32 
  *         @arg @ref LL_DMA_DST_MSIZE_64 
  *         @arg @ref LL_DMA_DST_MSIZE_128
  *         @arg @ref LL_DMA_DST_MSIZE_256
  */
__STATIC_INLINE void LL_DMA_SetDestinationBurstSize(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t DstBurstSize)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DSTMSIZE,
             DstBurstSize);
}

/**
  * @brief  Get Destination Burst size.
  * @rmtoll CTL          DST_MSIZE         LL_DMA_GetDestinationBurstSize
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DST_MSIZE_1  
  *         @arg @ref LL_DMA_DST_MSIZE_4  
  *         @arg @ref LL_DMA_DST_MSIZE_8  
  *         @arg @ref LL_DMA_DST_MSIZE_16 
  *         @arg @ref LL_DMA_DST_MSIZE_32 
  *         @arg @ref LL_DMA_DST_MSIZE_64 
  *         @arg @ref LL_DMA_DST_MSIZE_128
  *         @arg @ref LL_DMA_DST_MSIZE_256
  */
__STATIC_INLINE uint32_t LL_DMA_GetDestinationBurstSize(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L,
                   DMA_CH_CHCTL_DSTMSIZE));
}

/**
  * @brief  Set Channel priority level.
  * @rmtoll CFG          CH_PRIOR            LL_DMA_SetChannelPriorityLevel
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
  * @param  Priority This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CH_PRIOR_0
  *         @arg @ref LL_DMA_CH_PRIOR_1
  *         @arg @ref LL_DMA_CH_PRIOR_2
  *         @arg @ref LL_DMA_CH_PRIOR_3
  *         @arg @ref LL_DMA_CH_PRIOR_4
  *         @arg @ref LL_DMA_CH_PRIOR_5
  *         @arg @ref LL_DMA_CH_PRIOR_6
  *         @arg @ref LL_DMA_CH_PRIOR_7
  */
__STATIC_INLINE void LL_DMA_SetChannelPriorityLevel(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Priority)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_PRIOR,
             Priority);
}

/**
  * @brief  Get Channel priority level.
  * @rmtoll CFG          CH_PRIOR            LL_DMA_GetChannelPriorityLevel
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_CH_PRIOR_0
  *         @arg @ref LL_DMA_CH_PRIOR_1
  *         @arg @ref LL_DMA_CH_PRIOR_2
  *         @arg @ref LL_DMA_CH_PRIOR_3
  *         @arg @ref LL_DMA_CH_PRIOR_4
  *         @arg @ref LL_DMA_CH_PRIOR_5
  *         @arg @ref LL_DMA_CH_PRIOR_6
  *         @arg @ref LL_DMA_CH_PRIOR_7
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelPriorityLevel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
                   DMA_CH_CHCFG_PRIOR));
}

/**
  * @brief  Set Number of data to transfer.
  * @note   This action has no effect if
  *         channel is enabled.
  * @rmtoll CTL        BLOCK_TS           LL_DMA_SetBlockSize
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
  * @param  BlkSize Between Min_Data = 0 and Max_Data = 0x00000FFF
  */
__STATIC_INLINE void LL_DMA_SetBlockSize(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t BlkSize)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_H,
             DMA_CH_CHCTL_BLOCKTS, BlkSize);
}

/**
  * @brief  Get Number of data to transfer.
  * @note   Once the channel is enabled, the return value indicate the
  *         remaining bytes to be transmitted.
  * @rmtoll CTL        BLOCK_TS           LL_DMA_GetBlockSize
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
  * @retval Between Min_Data = 0 and Max_Data = 0x00000FFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetBlockSize(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_H,
                   DMA_CH_CHCTL_BLOCKTS));
}

/**
  * @brief  Set source handshaking interface mode.
  * @rmtoll CFG       HS_SEL_SRC           LL_DMA_SetChannelSourceHSMode
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
  * @param  HsMode This parameter can be one of the following values:
  *         @arg @ref LL_DMA_HS_SRC_HW
  *         @arg @ref LL_DMA_HS_SRC_SW
  */
__STATIC_INLINE void LL_DMA_SetChannelSourceHSMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t HsMode)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_SRCHS, HsMode);
}

/**
  * @brief  Get source handshaking interface mode.
  * @rmtoll CFG       HS_SEL_SRC           LL_DMA_GetChannelSourceHSMode
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
  * @retval  Returned value can be one of the following values:
  *         @arg @ref LL_DMA_HS_SRC_HW
  *         @arg @ref LL_DMA_HS_SRC_SW
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelSourceHSMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_SRCHS));
}

/**
  * @brief  Set source handshaking interface mode.
  * @rmtoll CFG       HS_SEL_DST           LL_DMA_SetChannelDestinationHSMode
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
  * @param  HsMode This parameter can be one of the following values:
  *         @arg @ref LL_DMA_HS_DST_HW
  *         @arg @ref LL_DMA_HS_DST_SW
  */
__STATIC_INLINE void LL_DMA_SetChannelDestinationHSMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t HsMode)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_DSTHS, HsMode);
}

/**
  * @brief  Get destination handshaking interface mode.
  * @rmtoll CFG       HS_SEL_DST           LL_DMA_GetChannelDestinationHSMode
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
  * @retval  Returned value can be one of the following values:
  *         @arg @ref LL_DMA_HS_DST_HW
  *         @arg @ref LL_DMA_HS_DST_SW
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelDestinationHSMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_DSTHS));
}

/**
  * @brief  Set source handshaking interface polarity.
  * @rmtoll CFG       SRC_HS_POL           LL_DMA_SetChannelSourceHSPol
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
  * @param  Pol This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_HS_POL_HIGH
  *         @arg @ref LL_DMA_SRC_HS_POL_LOW
  */
__STATIC_INLINE void LL_DMA_SetChannelSourceHSPol(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Pol)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_SRCHSPOL, Pol);
}

/**
  * @brief  Get source handshaking interface polarity.
  * @rmtoll CFG       SRC_HS_POL           LL_DMA_GetChannelSourceHSPol
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
  * @retval  Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_HS_POL_HIGH
  *         @arg @ref LL_DMA_SRC_HS_POL_LOW
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelSourceHSPol(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_SRCHSPOL));
}

/**
  * @brief  Set source handshaking interface polarity.
  * @rmtoll CFG       DST_HS_POL           LL_DMA_SetChannelDestinationHSPol
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
  * @param  Pol This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DST_HS_POL_HIGH
  *         @arg @ref LL_DMA_DST_HS_POL_LOW
  */
__STATIC_INLINE void LL_DMA_SetChannelDestinationHSPol(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Pol)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_DSTHS, Pol);
}

/**
  * @brief  Get destination handshaking interface polarity.
  * @rmtoll CFG       DST_HS_POL           LL_DMA_GetChannelDestinationHSPol
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
  * @retval  Returned value can be one of the following values:
  *         @arg @ref LL_DMA_DST_HS_POL_HIGH
  *         @arg @ref LL_DMA_DST_HS_POL_LOW
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelDestinationHSPol(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L,
             DMA_CH_CHCFG_DSTHS));
}

/**
  * @brief  Assign source handshaking interface.
  * @rmtoll CFG       SRC_PER           LL_DMA_SetChannelSourceHSIF
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
  * @param  Interface This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_PER_IF_0
  *         @arg @ref LL_DMA_SRC_PER_IF_1
  *         @arg @ref LL_DMA_SRC_PER_IF_2
  *         @arg @ref LL_DMA_SRC_PER_IF_3
  *         @arg @ref LL_DMA_SRC_PER_IF_4
  *         @arg @ref LL_DMA_SRC_PER_IF_5
  *         @arg @ref LL_DMA_SRC_PER_IF_6
  *         @arg @ref LL_DMA_SRC_PER_IF_7
  *         @arg @ref LL_DMA_SRC_PER_IF_8
  *         @arg @ref LL_DMA_SRC_PER_IF_9
  *         @arg @ref LL_DMA_SRC_PER_IF_10
  *         @arg @ref LL_DMA_SRC_PER_IF_11
  *         @arg @ref LL_DMA_SRC_PER_IF_12
  *         @arg @ref LL_DMA_SRC_PER_IF_13
  *         @arg @ref LL_DMA_SRC_PER_IF_14
  *         @arg @ref LL_DMA_SRC_PER_IF_15
  */
__STATIC_INLINE void LL_DMA_SetChannelSourceHSIF(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Interface)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H,
             DMA_CH_CHCFG_SRCPER, Interface);
}

/**
  * @brief  Read source handshaking interface polarity.
  * @rmtoll CFG       SRC_PER           LL_DMA_GetChannelSourceHSIF
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
  * @retval  Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_PER_IF_0
  *         @arg @ref LL_DMA_SRC_PER_IF_1
  *         @arg @ref LL_DMA_SRC_PER_IF_2
  *         @arg @ref LL_DMA_SRC_PER_IF_3
  *         @arg @ref LL_DMA_SRC_PER_IF_4
  *         @arg @ref LL_DMA_SRC_PER_IF_5
  *         @arg @ref LL_DMA_SRC_PER_IF_6
  *         @arg @ref LL_DMA_SRC_PER_IF_7
  *         @arg @ref LL_DMA_SRC_PER_IF_8
  *         @arg @ref LL_DMA_SRC_PER_IF_9
  *         @arg @ref LL_DMA_SRC_PER_IF_10
  *         @arg @ref LL_DMA_SRC_PER_IF_11
  *         @arg @ref LL_DMA_SRC_PER_IF_12
  *         @arg @ref LL_DMA_SRC_PER_IF_13
  *         @arg @ref LL_DMA_SRC_PER_IF_14
  *         @arg @ref LL_DMA_SRC_PER_IF_15
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelSourceHSIF(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H,
             DMA_CH_CHCFG_SRCPER));
}

/**
  * @brief  Assign source handshaking interface.
  * @rmtoll CFG       DEST_PER           LL_DMA_SetChannelDestinationHSIF
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
  * @param  Interface This parameter can be one of the following values:
  *         @arg @ref LL_DMA_SRC_PER_IF_0
  *         @arg @ref LL_DMA_SRC_PER_IF_1
  *         @arg @ref LL_DMA_SRC_PER_IF_2
  *         @arg @ref LL_DMA_SRC_PER_IF_3
  *         @arg @ref LL_DMA_SRC_PER_IF_4
  *         @arg @ref LL_DMA_SRC_PER_IF_5
  *         @arg @ref LL_DMA_SRC_PER_IF_6
  *         @arg @ref LL_DMA_SRC_PER_IF_7
  *         @arg @ref LL_DMA_SRC_PER_IF_8
  *         @arg @ref LL_DMA_SRC_PER_IF_9
  *         @arg @ref LL_DMA_SRC_PER_IF_10
  *         @arg @ref LL_DMA_SRC_PER_IF_11
  *         @arg @ref LL_DMA_SRC_PER_IF_12
  *         @arg @ref LL_DMA_SRC_PER_IF_13
  *         @arg @ref LL_DMA_SRC_PER_IF_14
  *         @arg @ref LL_DMA_SRC_PER_IF_15
  */
__STATIC_INLINE void LL_DMA_SetChannelDestinationHSIF(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Interface)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H,
             DMA_CH_CHCFG_DSTPER, Interface);
}

/**
  * @brief  Read destination handshaking interface.
  * @rmtoll CFG       DEST_PER           LL_DMA_GetChannelDestinationHSIF
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
  * @retval  Returned value can be one of the following values:
  *         @arg @ref LL_DMA_SRC_PER_IF_0
  *         @arg @ref LL_DMA_SRC_PER_IF_1
  *         @arg @ref LL_DMA_SRC_PER_IF_2
  *         @arg @ref LL_DMA_SRC_PER_IF_3
  *         @arg @ref LL_DMA_SRC_PER_IF_4
  *         @arg @ref LL_DMA_SRC_PER_IF_5
  *         @arg @ref LL_DMA_SRC_PER_IF_6
  *         @arg @ref LL_DMA_SRC_PER_IF_7
  *         @arg @ref LL_DMA_SRC_PER_IF_8
  *         @arg @ref LL_DMA_SRC_PER_IF_9
  *         @arg @ref LL_DMA_SRC_PER_IF_10
  *         @arg @ref LL_DMA_SRC_PER_IF_11
  *         @arg @ref LL_DMA_SRC_PER_IF_12
  *         @arg @ref LL_DMA_SRC_PER_IF_13
  *         @arg @ref LL_DMA_SRC_PER_IF_14
  *         @arg @ref LL_DMA_SRC_PER_IF_15
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelDestinationHSIF(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H,
             DMA_CH_CHCFG_DSTPER));
}

/**
  * @brief  Configure the Source and Destination addresses.
  * @note   This API must not be called when the DMA channel is enabled.
  * @note   Each peripheral using DMA provides an API to get directly the register address (LL_PPP_DMA_GetRegAddr).
  * @rmtoll SAR         SAR            LL_DMA_ConfigAddresses\n
  *         DAR         DAR            LL_DMA_ConfigAddresses
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
  * @param  SrcAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @param  DstAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE void LL_DMA_ConfigAddresses(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcAddress, uint32_t DstAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->SAR, SrcAddress);
  WRITE_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->DAR, DstAddress);
}

/**
  * @brief  Set the Destination address.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll DAR         DAR            LL_DMA_SetDestinationAddress
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
  * @param  DstAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE void LL_DMA_SetDestinationAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t DstAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->DAR, DstAddress);
}

/**
  * @brief  Set the Source address.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll SAR         SAR            LL_DMA_SetSourceAddress
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
  * @param  SourceAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE void LL_DMA_SetSourceAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SourceAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->SAR, SourceAddress);
}

/**
  * @brief  Get destination address.
  * @rmtoll DAR         DAR            LL_DMA_GetDestinationAddress
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
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetDestinationAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->DAR));
}

/**
  * @brief  Get Source address.
  * @rmtoll SAR         SAR            LL_DMA_GetSourceAddress
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
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetSourceAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->SAR));
}

#if DMA_GATHER_ENABLE
/**
  * @brief  Enable the Source gather.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CTL         SRC_GATHER_EN            LL_DMA_SrcGather_Enable
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
  */
__STATIC_INLINE void LL_DMA_SrcGather_Enable(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SRCGATEN);
}

/**
  * @brief  Diable the Source gather.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CTL         SRC_GATHER_EN            LL_DMA_SrcGather_Disable
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
  */
__STATIC_INLINE void LL_DMA_SrcGather_Disable(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SRCGATEN);
}

/**
  * @brief  check if the Source gather is enabled.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CTL         SRC_GATHER_EN            LL_DMA_SrcGather_IsEnabled
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_SrcGather_IsEnabled(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SRCGATEN)) ? 1UL : 0UL);
}
#endif /* DMA_GATHER_ENABLE */
#if DMA_SCATTER_ENABLE
/**
  * @brief  Enable the destination scatter.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CTL         DST_SCATTER_EN            LL_DMA_DstScatter_Enable
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
  */
__STATIC_INLINE void LL_DMA_DstScatter_Enable(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DSTSCAEN);
}

/**
  * @brief  Diable the destination scatter.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CTL         DST_SCATTER_EN            LL_DMA_DstScatter_Disable
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
  */
__STATIC_INLINE void LL_DMA_DstScatter_Disable(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DSTSCAEN);
}

/**
  * @brief  check if the destination scatter is enabled.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CTL         DST_SCATTER_EN            LL_DMA_DstScatter_IsEnabled
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_DstScatter_IsEnabled(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DSTSCAEN)) ? 1UL : 0UL);
}
#endif /* DMA_SCATTER_ENABLE */
#if DMA_GATHER_ENABLE
/**
  * @brief  Enable the Source gather.
  * @rmtoll SGR         SGC            LL_DMA_ConfigSrcGather\n
  *         SGR         SGI            LL_DMA_ConfigSrcGather
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
  * @param  Gather gather count (0~0xFFF)
  *                gather interval (0~0xFFFFF)
  */
__STATIC_INLINE void LL_DMA_ConfigSrcGather(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_SGRTypeDef Gather)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->SGR_L, DMA_CHSGR_SGC, Gather.SgrCount);
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->SGR_L, DMA_CHSGR_SGI, Gather.SgrInterval);
}
#endif /* DMA_GATHER_ENABLE */
#if DMA_SCATTER_ENABLE
/**
  * @brief  Enable the destination scatter.
  * @rmtoll DSR         DSC            LL_DMA_ConfigDstScatter\n
  *         DSR         DSI            LL_DMA_ConfigDstScatter
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
  * @param  Scatter scatter count (0~0xFFF)
  *                 scatter interval (0~0xFFFFF)
  */
__STATIC_INLINE void LL_DMA_ConfigDstScatter(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_DSRTypeDef Scatter)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->DSR_L, DMA_CHDSR_DSC, Scatter.DsrCount);
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->DSR_L, DMA_CHDSR_DSI, Scatter.DsrInterval);
}
#endif /* DMA_SCATTER_ENABLE */
/**
  * @brief  Set DMA source software transaction request.
  * @rmtoll ReqSrcReg         SRC_REQ     LL_DMA_SetSourceRequest
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
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE void LL_DMA_SetSourceRequest(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Request)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->REQSRC = ((DMA_REQSRC_WE_0|Request) << Channel);
}

/**
  * @brief  Get DMA Source software transaction request.
  * @rmtoll ReqSrcReg         SRC_REQ     LL_DMA_GetSourceRequest
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE uint32_t LL_DMA_GetSourceRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->REQSRC, (DMA_REQSRC_EN_0 << Channel)));
}

/**
  * @brief  Set DMA detination software transaction request.
  * @rmtoll ReqDstReg         DST_REQ     LL_DMA_SetDestinationRequest
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
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE void LL_DMA_SetDestinationRequest(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Request)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->REQDST = ((DMA_REQDST_WE_0|Request) << Channel);
}

/**
  * @brief  Get DMA destination software transaction request.
  * @rmtoll ReqDstReg         DST_REQ     LL_DMA_GetDestinationRequest
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE uint32_t LL_DMA_GetDestinationRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->REQDST, (DMA_REQDST_EN_0 << Channel)));
}

/**
  * @brief  Set DMA single source software transaction request.
  * @rmtoll SglReqSrcReg         SRC_SGLREQ     LL_DMA_SetSingleSourceRequest
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
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE void LL_DMA_SetSingleSourceRequest(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Request)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->SGLREQSRC = ((DMA_SGLREQSRC_WE_0|Request) << Channel);
}

/**
  * @brief  Get DMA single Source software transaction request.
  * @rmtoll SglReqSrcReg         SRC_SGLREQ     LL_DMA_GetSingleSourceRequest
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE uint32_t LL_DMA_GetSingleSourceRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->SGLREQSRC, (DMA_SGLREQSRC_EN_0 << Channel)));
}

/**
  * @brief  Set DMA single detination software transaction request.
  * @rmtoll SglReqDstReg         DST_SGLREQ     LL_DMA_SetSingleDestinationRequest
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
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE void LL_DMA_SetSingleDestinationRequest(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Request)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->SGLREQDST = ((DMA_SGLREQDST_WE_0|Request) << Channel);
}

/**
  * @brief  Get DMA single destination software transaction request.
  * @rmtoll SglReqDstReg         DST_SGLREQ     LL_DMA_GetDestinationRequest
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE uint32_t LL_DMA_GetSingleDestinationRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->SGLREQDST, (DMA_SGLREQDST_EN_0 << Channel)));
}

/**
  * @brief  Set DMA last source software transaction request.
  * @rmtoll LstSrcReg         LSTSRC     LL_DMA_SetLastSourceRequest
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
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE void LL_DMA_SetLastSourceRequest(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Request)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->LSTREQSRC = ((DMA_LSTREQSRC_WE_0|Request) << Channel);
}

/**
  * @brief  Get DMA Last Source software transaction request.
  * @rmtoll LstSrcReg         LSTSRC     LL_DMA_GetLastSourceRequest
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE uint32_t LL_DMA_GetLastSourceRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->LSTREQSRC, (DMA_LSTREQSRC_EN_0 << Channel)));
}

/**
  * @brief  Set DMA last detination software transaction request.
  * @rmtoll LstDstReg         LSTDST     LL_DMA_SetLastDestinationRequest
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
  * @param  Request This parameter can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE void LL_DMA_SetLastDestinationRequest(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Request)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->LSTREQDST = ((DMA_LSTREQDST_WE_0|Request) << Channel);
}

/**
  * @brief  Get DMAlast destination software transaction request.
  * @rmtoll LstDstReg         LSTDST     LL_DMA_GetLastDestinationRequest
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_HS_CH_0
  *         @arg @ref LL_DMA_HS_CH_1
  *         @arg @ref LL_DMA_HS_CH_2
  *         @arg @ref LL_DMA_HS_CH_3
  *         @arg @ref LL_DMA_HS_CH_4
  *         @arg @ref LL_DMA_HS_CH_5
  *         @arg @ref LL_DMA_HS_CH_6
  *         @arg @ref LL_DMA_HS_CH_7
  */
__STATIC_INLINE uint32_t LL_DMA_GetLastDestinationRequest(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->LSTREQDST, (DMA_LSTREQDST_EN_0 << Channel)));
}

/**
  * @}
  */

/** @defgroup DMA_LL_Exported_Functions_Group2 FLAG_Management
  * @{
  */
/**
  * @brief  Get Channel transfer complete interrupt flag.
  * @rmtoll StatusTfr          Status          LL_DMA_IsActiveFlag_RawTfr
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_RawTfr(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->RAWTFR,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Get Channel block transfer complete interrupt flag.
  * @rmtoll StatusTfr          Status          LL_DMA_IsActiveFlag_RawBlock
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_RawBlock(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->RAWBLOCK,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Get Channel source transfer request interrupt flag.
  * @rmtoll StatusTfr          Status          LL_DMA_IsActiveFlag_RawSrcTran
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_RawSrcTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->RAWSRCTRAN,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Get Channel destination transfer request interrupt flag.
  * @rmtoll StatusTfr          Status          LL_DMA_IsActiveFlag_RawDstTran
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_RawDstTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->RAWDSTTRAN,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Get Channel transfer error interrupt flag.
  * @rmtoll StatusTfr          Status          LL_DMA_IsActiveFlag_RawErr
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_RawErr(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->RAWERR,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}


/**
  * @brief  Get Channel Block transfer complete interrupt flag.
  * @rmtoll StatusBlock          Status          LL_DMA_IsActiveFlag_Block
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_Block(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATBLOCK,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Get Channel destination transaction complete interrupt flag.
  * @rmtoll StatusDstTran          Status          LL_DMA_IsActiveFlag_DstTran
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_DstTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATDSTTRAN,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Get Channel Error interrupt flag.
  * @rmtoll StatusErr          Status          LL_DMA_IsActiveFlag_Error
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_Error(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATERR,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Get Channel Source transaction complete interrupt flag.
  * @rmtoll StatusSrcTran         Status          LL_DMA_IsActiveFlag_SrcTran
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_SrcTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATSRCTRAN,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Get Channel transfer complete interrupt flag.
  * @rmtoll StatusTfr          Status          LL_DMA_IsActiveFlag_Tfr
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_Tfr(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATTFR,  (0x1UL << Channel)) == (0x1UL << Channel)) ? 1UL : 0UL);
}

/**
  * @brief  Clear Channel transfer complete interrupt flag.
  * @rmtoll ClearTfr         CLEAR         LL_DMA_ClearFlag_Tfr
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
  */
__STATIC_INLINE void LL_DMA_ClearFlag_Tfr(DMA_TypeDef *DMAx, uint32_t Channel)
{
  WRITE_REG(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->CLRTFR, (0x1UL << Channel));
}

/**
  * @brief  Clear Channel block transfer complete interrupt flag.
  * @rmtoll ClearBlock         CLEAR         LL_DMA_ClearFlag_Block
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
  */
__STATIC_INLINE void LL_DMA_ClearFlag_Block(DMA_TypeDef *DMAx, uint32_t Channel)
{
  WRITE_REG(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->CLRBLOCK, (0x1UL << Channel));
}

/**
  * @brief  Clear Channel source tranaction complete interrupt flag.
  * @rmtoll ClearSrcTran         CLEAR         LL_DMA_ClearFlag_SrcTran
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
  */
__STATIC_INLINE void LL_DMA_ClearFlag_SrcTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  WRITE_REG(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->CLRSRCTRAN, (0x1UL << Channel));
}

/**
  * @brief  Clear Channel destination trnsaction complete interrupt flag.
  * @rmtoll ClearDstTran         CLEAR         LL_DMA_ClearFlag_DstTran
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
  */
__STATIC_INLINE void LL_DMA_ClearFlag_DstTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  WRITE_REG(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->CLRDSTTRAN, (0x1UL << Channel));
}

/**
  * @brief  Clear Channel error interrupt flag.
  * @rmtoll ClearErr         CLEAR         LL_DMA_ClearFlag_Error
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
  */
__STATIC_INLINE void LL_DMA_ClearFlag_Error(DMA_TypeDef *DMAx, uint32_t Channel)
{
  WRITE_REG(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->CLRERR, (0x1UL << Channel));
}

/**
  * @brief  Mask Channel transfer complete interrupt flag.
  * @rmtoll MaskTfr         INT_MASK         LL_DMA_Mask_Tfr
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
  */
__STATIC_INLINE void LL_DMA_Mask_Tfr(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKTFR = ((DMA_MSKTFR_WE_0) << Channel);
}

/**
  * @brief  Mask Channel block transfer complete interrupt flag.
  * @rmtoll MaskBlock         INT_MASK         LL_DMA_Mask_Block
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
  */
__STATIC_INLINE void LL_DMA_Mask_Block(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKBLOCK = ((DMA_MSKBLOCK_WE_0) << Channel);
}

/**
  * @brief  Mask Channel source transaction complete interrupt flag.
  * @rmtoll MaskSrcTran         INT_MASK         LL_DMA_Mask_SrcTran
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
  */
__STATIC_INLINE void LL_DMA_Mask_SrcTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKSRCTRAN = ((DMA_MSKSRCTRAN_WE_0) << Channel);
}

/**
  * @brief  Mask Channel dstination transaction complete interrupt flag.
  * @rmtoll MaskDstTran         INT_MASK         LL_DMA_Mask_DstTran
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
  */
__STATIC_INLINE void LL_DMA_Mask_DstTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKDSTTRAN = ((DMA_MSKDSTTRAN_WE_0) << Channel);
}

/**
  * @brief  Mask Channel error interrupt flag.
  * @rmtoll MaskErr         INT_MASK         LL_DMA_Mask_Error
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
  */
__STATIC_INLINE void LL_DMA_Mask_Errorr(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKERR = ((DMA_MSKERR_WE_0) << Channel);
}

/**
  * @brief  Unmask Channel transfer complete interrupt flag.
  * @rmtoll MaskTfr         INT_MASK         LL_DMA_UnMask_Tfr
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
  */
__STATIC_INLINE void LL_DMA_UnMask_Tfr(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKTFR = ((DMA_MSKTFR_EN_0|DMA_MSKTFR_WE_0) << Channel);
}

/**
  * @brief  UnMask Channel block transfer complete interrupt flag.
  * @rmtoll MaskBlock         INT_MASK         LL_DMA_UnMask_Block
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
  */
__STATIC_INLINE void LL_DMA_UnMask_Block(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKBLOCK = ((DMA_MSKBLOCK_EN_0|DMA_MSKBLOCK_WE_0) << Channel);
}

/**
  * @brief  UnMask Channel source transaction complete interrupt flag.
  * @rmtoll MaskSrcTran         INT_MASK         LL_DMA_UnMask_SrcTran
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
  */
__STATIC_INLINE void LL_DMA_UnMask_SrcTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKSRCTRAN = ((DMA_MSKSRCTRAN_EN_0|DMA_MSKSRCTRAN_WE_0) << Channel);
}

/**
  * @brief  UnMask Channel dstination transaction complete interrupt flag.
  * @rmtoll MaskDstTran         INT_MASK         LL_DMA_UnMask_DstTran
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
  */
__STATIC_INLINE void LL_DMA_UnMask_DstTran(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKDSTTRAN = ((DMA_MSKDSTTRAN_EN_0|DMA_MSKDSTTRAN_WE_0) << Channel);
}

/**
  * @brief  UnMask Channel error interrupt flag.
  * @rmtoll MaskErr         INT_MASK         LL_DMA_UnMask_Error
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
  */
__STATIC_INLINE void LL_DMA_UnMask_Errorr(DMA_TypeDef *DMAx, uint32_t Channel)
{
  ((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->MSKERR = ((DMA_MSKERR_EN_0|DMA_MSKERR_WE_0) << Channel);
}

/**
  * @brief  get combined tranfer complete interrupt flag.
  * @rmtoll StatusInt         TFR         LL_DMA_IsActiveCombFlag_Tfr
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveCombFlag_Tfr(DMA_TypeDef *DMAx)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATINT, DMA_STATINT_TFR) ? 1UL : 0UL);
}

/**
  * @brief  get combined block transfer complete interrupt flag.
  * @rmtoll StatusInt         BLOCK         LL_DMA_IsActiveCombFlag_Block
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveCombFlag_Block(DMA_TypeDef *DMAx)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATINT, DMA_STATINT_BLOCK) ? 1UL : 0UL);
}

/**
  * @brief  get combined source tranaction complete interrupt flag.
  * @rmtoll StatusInt         SrcTran         LL_DMA_IsActiveCombFlag_SrcTran
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveCombFlag_SrcTran(DMA_TypeDef *DMAx)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATINT, DMA_STATINT_SRCT) ? 1UL : 0UL);
}

/**
  * @brief  get combined destination tranaction complete interrupt flag.
  * @rmtoll StatusInt         DstTran         LL_DMA_IsActiveCombFlag_DstTran
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveCombFlag_DstTran(DMA_TypeDef *DMAx)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATINT, DMA_STATINT_DSTT) ? 1UL : 0UL);
}

/**
  * @brief  get combined error interrupt flag.
  * @rmtoll StatusInt         TFR         LL_DMA_IsActiveCombFlag_Error
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveCombFlag_Error(DMA_TypeDef *DMAx)
{
  return (READ_BIT(((DMA_TypeDef *)__LL_DMA_GET_AUXILIARY(DMAx))->STATINT, DMA_STATINT_ERR) ? 1UL : 0UL);
}
/**
  * @}
  */

/** @defgroup DMA_LL_Exported_Functions_Group3 IT_Management
  * @{
  */
/**
  * @brief  Channel Enable interrupt.
  * @rmtoll CTL          INT_EN          LL_DMA_EnableIT
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
  */
__STATIC_INLINE void LL_DMA_EnableIT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_INTEN);
}

/**
  * @brief  Channel Disable interrupt.
  * @rmtoll CTL          INT_EN          LL_DMA_DisableIT
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
  */
__STATIC_INLINE void LL_DMA_DisableIT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_INTEN);
}

/**
  * @brief  Check if channel Interrupt is enabled.
  * @rmtoll CTL          INT_EN          LL_DMA_IsEnabledIT
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_INTEN) == (DMA_CH_CHCTL_INTEN)) ? 1UL : 0UL);
}
#if DMA_LOCK_ENABLE
/**
  * @brief  Lock bus.
  * @rmtoll CFG          LOCK_B          LL_DMA_LockBus
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
  */
__STATIC_INLINE void LL_DMA_LockBus(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_BLOCK);
}

/**
  * @brief  Unlock bus.
  * @rmtoll CFG          LOCK_B          LL_DMA_UnlockBus
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
  */
__STATIC_INLINE void LL_DMA_UnlockBus(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_BLOCK);
}

/**
  * @brief  Check if bus locked.
  * @rmtoll CFG          LOCK_B          LL_DMA_IsLockedBus
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsLockedBus(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_BLOCK) == (DMA_CH_CHCFG_BLOCK)) ? 1UL : 0UL);
}

/**
  * @brief  Lock channel.
  * @rmtoll CFG          LOCK_CH          LL_DMA_LockChannel
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
  */
__STATIC_INLINE void LL_DMA_LockChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_LOCK);
}

/**
  * @brief  Unlock channel.
  * @rmtoll CFG          LOCK_CH          LL_DMA_UnlockChannel
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
  */
__STATIC_INLINE void LL_DMA_UnlockChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_LOCK);
}

/**
  * @brief  Check if channel locked.
  * @rmtoll CFG          LOCK_CH          LL_DMA_IsLockedChannel
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsLockedChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_LOCK) == (DMA_CH_CHCFG_LOCK)) ? 1UL : 0UL);
}

/**
  * @brief  Set lock bus level.
  * @rmtoll CFG          LOCK_B_L          LL_DMA_SetLockBusLevel
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
  * @param Level This parameter can be one of thr following values:
  *         @arg @ref LL_DMA_LOCK_B_L_TR
  *         @arg @ref LL_DMA_LOCK_B_L_BT
  *         @arg @ref LL_DMA_LOCK_B_L_TA
  */
__STATIC_INLINE void LL_DMA_SetLockBusLevel(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Level)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_BLOCKL, Level);
}

/**
  * @brief  Get lock bus level.
  * @rmtoll CFG          LOCK_B_L          LL_DMA_GetLockBusLevel
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
  * @retval Return value can be one of thr following values:
  *         @arg @ref LL_DMA_LOCK_B_L_TR
  *         @arg @ref LL_DMA_LOCK_B_L_BT
  *         @arg @ref LL_DMA_LOCK_B_L_TA
  */
__STATIC_INLINE uint32_t LL_DMA_GetLockBusLevel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_BLOCKL));
}

/**
  * @brief  Set lock channel level.
  * @rmtoll CFG          LOCK_CH_L          LL_DMA_SetLockChannelLevel
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
  * @param Level This parameter can be one of thr following values:
  *         @arg @ref LL_DMA_LOCK_CH_L_TR
  *         @arg @ref LL_DMA_LOCK_CH_L_BT
  *         @arg @ref LL_DMA_LOCK_CH_L_TA
  */
__STATIC_INLINE void LL_DMA_SetLockChannelLevel(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Level)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_LOCKL, Level);
}

/**
  * @brief  Get lock channel level.
  * @rmtoll CFG          LOCK_CH_L          LL_DMA_GetLockChannelLevel
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
  * @retval Return value can be one of thr following values:
  *         @arg @ref LL_DMA_LOCK_CH_L_TR
  *         @arg @ref LL_DMA_LOCK_CH_L_BT
  *         @arg @ref LL_DMA_LOCK_CH_L_TA
  */
__STATIC_INLINE uint32_t LL_DMA_GetLockChannelLevel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_LOCKL));
}
#endif /* DMA_LOCK_ENBLE */
/**
  * @brief  Check if channel FIFO empty.
  * @rmtoll CFG          FIFO_EMPTY          LL_DMA_IsFIFOEmpty
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsFIFOEmpty(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_FIFOE) == (DMA_CH_CHCFG_FIFOE)) ? 1UL : 0UL);
}

/**
  * @brief  DMA channel done.
  * @rmtoll CTL          DONE          LL_DMA_SetDone
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
  */
__STATIC_INLINE void LL_DMA_SetDone(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_H, DMA_CH_CHCTL_DONE);
}

/**
  * @brief  Clear DMA Done.
  * @rmtoll CTL         DONE          LL_DMA_ClearDone
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
  */
__STATIC_INLINE void LL_DMA_ClearDone(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_H, DMA_CH_CHCTL_DONE);
}

/**
  * @brief  Check if DMA done.
  * @rmtoll CTL          DONE          LL_DMA_IsDone
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsDone(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_H, DMA_CH_CHCTL_DONE) == (DMA_CH_CHCTL_DONE)) ? 1UL : 0UL);
}
#if (DMA_MASTER_NUMBER > 1)
/**
  * @brief  Set source master.
  * @rmtoll CTL          SMS          LL_DMA_SetSourceMaster
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
  * @param SrcMaster This parameter can be one of thr following values:
  *         @arg @ref LL_DMA_SMS_1
  *         @arg @ref LL_DMA_SMS_2
  *         @arg @ref LL_DMA_SMS_3
  *         @arg @ref LL_DMA_SMS_4
  */
__STATIC_INLINE void LL_DMA_SetSourceMaster(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcMaster)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SMS, SrcMaster);
}

/**
  * @brief  Get lock channel level.
  * @rmtoll CTL          SMS          LL_DMA_GetSourceMaster
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
  * @retval Return value can be one of thr following values:
  *         @arg @ref LL_DMA_SMS_1
  *         @arg @ref LL_DMA_SMS_2
  *         @arg @ref LL_DMA_SMS_3
  *         @arg @ref LL_DMA_SMS_4
  */
__STATIC_INLINE uint32_t LL_DMA_GetSourceMaster(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_SMS));
}

/**
  * @brief  Set destination master.
  * @rmtoll CTL          DMS          LL_DMA_SetDestinationMaster
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
  * @param DstMaster This parameter can be one of thr following values:
  *         @arg @ref LL_DMA_DMS_1
  *         @arg @ref LL_DMA_DMS_2
  *         @arg @ref LL_DMA_DMS_3
  *         @arg @ref LL_DMA_DMS_4
  */
__STATIC_INLINE void LL_DMA_SetDestinationMaster(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t DstMaster)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DMS, DstMaster);
}

/**
  * @brief  Get lock channel level.
  * @rmtoll CTL          DMS          LL_DMA_GetDestinationMaster
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
  * @retval Return value can be one of thr following values:
  *         @arg @ref LL_DMA_DMS_1
  *         @arg @ref LL_DMA_DMS_2
  *         @arg @ref LL_DMA_DMS_3
  *         @arg @ref LL_DMA_DMS_4
  */
__STATIC_INLINE uint32_t LL_DMA_GetDestinationMaster(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CTL_L, DMA_CH_CHCTL_DMS));
}
#endif /* (DMA_MASTER_NUMBER > 1) */
#if DMA_LLP_ENABLE
/**
  * @brief  DMA source status update enable.
  * @rmtoll CFG          SS_UPD_EN          LL_DMA_EnableSourceStatusUpdate
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
  */
__STATIC_INLINE void LL_DMA_EnableSourceStatusUpdate(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H, DMA_CH_CHCFG_SSUPDEN);
}

/**
  * @brief  DMA Source status disable.
  * @rmtoll CFG         SS_UPD_EN          LL_DMA_DisableSourceStatusUpdate
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
  */
__STATIC_INLINE void LL_DMA_DisableSourceStatusUpdate(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H, DMA_CH_CHCFG_SSUPDEN);
}

/**
  * @brief  Check if DMA source status update.
  * @rmtoll CFG          SS_UPD_EN          LL_DMA_IsSourceStatusUpdated
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsSourceStatusUpdated(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H, DMA_CH_CHCFG_SSUPDEN) == (DMA_CH_CHCFG_SSUPDEN)) ? 1UL : 0UL);
}

/**
  * @brief  DMA destination status update enable.
  * @rmtoll CFG          SS_UPD_EN          LL_DMA_EnableDestinationStatusUpdate
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
  */
__STATIC_INLINE void LL_DMA_EnableDestinationStatusUpdate(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H, DMA_CH_CHCFG_DSUPDEN);
}

/**
  * @brief  DMA destination status update disable.
  * @rmtoll CFG         SS_UPD_EN          LL_DMA_DisableDestinationStatusUpdate
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
  */
__STATIC_INLINE void LL_DMA_DisableDestinationStatusUpdate(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H, DMA_CH_CHCFG_DSUPDEN);
}

/**
  * @brief  Check if DMA destination status update.
  * @rmtoll CFG          SS_UPD_EN          LL_DMA_IsDestinationStatusUpdated
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsDestinationStatusUpdated(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_H, DMA_CH_CHCFG_DSUPDEN) == (DMA_CH_CHCFG_DSUPDEN)) ? 1UL : 0UL);
}
#endif /* DMA_LLP_ENABLE */
#if DMA_MABRST 
/**
  * @brief  Set maximum AMBA burst length.
  * @rmtoll CFG          DMA_CH_CHCFG_MAXABRST          LL_DMA_SetMaxAMBABurstLength
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
  * @param Length Between 0 to 0x000003FF:
  */
__STATIC_INLINE void LL_DMA_SetMaxAMBABurstLength(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Length)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_MAXABRST, (Length << DMA_CH_CHCFG_MAXABRST_Pos));
}

/**
  * @brief  Get maximum AMBA burst length.
  * @rmtoll CFG          DMA_CH_CHCFG_MAXABRST          LL_DMA_GetMaxAMBABurstLength
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
  * @retval Return between 0 to 0x000003FF
  */
__STATIC_INLINE uint32_t LL_DMA_GetMaxAMBABurstLength(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_MAXABRST)) >> DMA_CH_CHCFG_MAXABRST_Pos);
}
#endif /* DMA_MABRST */
/**
  * @brief  DMA channel suspend enable.
  * @rmtoll CFG          CH_SUSP          LL_DMA_Suspend
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
  */
__STATIC_INLINE void LL_DMA_Suspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_SUSP);
}

/**
  * @brief  DMA destination status update disable.
  * @rmtoll CFG         CH_SUSP          LL_DMA_NotSuspend
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
  */
__STATIC_INLINE void LL_DMA_NotSuspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_SUSP);
}

/**
  * @brief  Check if DMA is suspended.
  * @rmtoll CFG          CH_SUSP          LL_DMA_IsSuspend
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
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsSuspend(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return ((READ_BIT(((DMA_Channel_TypeDef *)__LL_DMA_GET_CHANNEL_INSTANCE(DMAx, Channel))->CFG_L, DMA_CH_CHCFG_SUSP) == (DMA_CH_CHCFG_SUSP)) ? 1UL : 0UL);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_Exported_Functions_Group4 Initialization and de-initialization functions
  * @{
  */
ErrorStatus LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct);
ErrorStatus LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel);
void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct);

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

#endif /* DMA1 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_DMA_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
