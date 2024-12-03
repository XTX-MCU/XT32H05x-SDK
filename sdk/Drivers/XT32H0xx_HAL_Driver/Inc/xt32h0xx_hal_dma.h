/**
  ******************************************************************************
  * @file    xt32h0xx_hal_dma.h
  * @author  Software Team
  * @brief   Header file of DMA HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_DMA_H
#define XT32H0xx_HAL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"
#include "xt32h0xx_ll_dma.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup DMA_Exported_Types DMA Exported Types
  * @{
  */
#if DMA_GATHER_ENABLE
/** @defgroup DMA_GATHER structure definition
 * @{
 */
typedef struct __DMA_SGRTypeDef
{
  uint32_t SgrEnable;              /*!< source gather enable                                     */
  uint32_t SgrCount;               /*!< source gather count                                      */
  uint32_t SgrInterval;            /*!< source gather interval                                   */
} DMA_SGRTypeDef;
/**
  * @}
  */
#endif /* DMA_GATHER_ENABLE */
#if (DMA_SCATTER_ENABLE)
/** @defgroup DMA_SCATTER structure definition
 * @{
 */
typedef struct __DMA_DSRTypeDef
{
  uint32_t DsrEnable;              /*!< destination scatter enable                               */
  uint32_t DsrCount;               /*!< destination scatter count                                */
  uint32_t DsrInterval;            /*!< destination scatter interval                             */
} DMA_DSRTypeDef;
/**
  * @}
  */
#endif /* DMA_SCATTER_ENABLE */
#if (DMA_HW_HANDSHAKING)
/** @defgroup DMA_HANDSHAKING structure definition
 * @{
 */
typedef struct __DMA_HSTypeDef
{
  uint32_t HSMode;                 /*!< DMA handshaking mode (software/hardware)                 */
  uint32_t HSPol;                  /*!< DMA handshaking active polarity                          */
  uint32_t HSIF;                   /*!< Hardware handshaking interface                           */
} DMA_HSTypeDef;
/**
  * @}
  */
#endif /* DMA_HARDWARE_HANDSHAKING */
/** @defgroup DMA_LOCK structure definition
 * @{
 */
typedef struct __DMA_LockTypeDef
{        
  uint32_t LockEnable;                 /*!< DMA Lock enable                                     */
  uint32_t LockLevel;                  /*!< DMA lock level                                      */
} DMA_LockTypeDef;
/**
  * @}
  */

/**
  * @brief  DMA Configuration Structure definition
  */
typedef struct
{
  uint32_t Direction;             /*!< Specifies if the data will be transferred from memory to peripheral,
                                       from memory to memory or from peripheral to memory.
                                       This parameter can be a value of @ref DMA_Data_transfer_direction */

  uint32_t SrcInc;                /*!< Specifies whether the Source address register should be incremented, decrement or no change.
                                       This parameter can be a value of @ref DMA_Source_incremented_mode */

  uint32_t DstInc;                /*!< Specifies whether the destination address register should be incremented,decrement or nocharge.
                                       This parameter can be a value of @ref DMA_Destination_incremented_mode */

  uint32_t SrcDataSize;           /*!< Specifies the Source data width.
                                       This parameter can be a value of @ref DMA_Source_data_size */

  uint32_t DstDataSize;           /*!< Specifies the Destination data width.
                                       This parameter can be a value of @ref DMA_Destination_data_size */

  uint32_t SrcBurstSize;          /*!< Specifies Source burst transaction length.
                                        This parameter can be a value of @ref DMA_source_burst_size */

  uint32_t DstBurstSize;          /*!< Specifies the Destination burst transaction length.
                                        This parameter can be a value of @ref DMA_destination_burst_size */

  uint32_t Mode;                  /*!< Specifies the operation mode of the DMAy Channelx.
                                       This parameter can be a value of @ref DMA_mode
                                       @note The circular buffer mode cannot be used if the memory-to-memory
                                             data transfer is configured on the selected Channel */
#if (DMA_MASTER_NUMBER > 1)
  uint32_t Sms;                   /*!< Specifies the channel source master.
                                        This parameter can be a value of @ref DMA_SMS */

  uint32_t Dms;                   /*!< Specifies the channel destination master.
                                        This parameter can be a value of @ref DMA_DMS */
#endif /* (DMA_MASTER_NUMBER > 1) */
#if (DMA_LLP_ENABLE)
  uint32_t LlpAddress;             /*!< Specifies as LLP start address.
                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFE. */
#endif /* DMA_LLP_ENABLE */
  uint32_t Priority;              /*!< Specifies the software priority for the DMAy Channelx.
                                       This parameter can be a value of @ref DMA_Priority_level */

  uint32_t Suspend;               /*!< Specifies the channel transaction suspend enable.
                                        This parameter can be a value of [0,1]]  */
#if (DMA_GATHER_ENABLE)
  DMA_SGRTypeDef Sgr;             /*!< Specifies the channel source gather. */
#endif /* DMA_GATHER_ENABLE */
#if (DMA_SCATTER_ENABLE)
  DMA_DSRTypeDef Dsr;             /*!< Specifies the channel destination scatter. */
#endif /* DMA_SCATTER_ENABLE */
#if (DMA_HW_HANDSHAKING)
  DMA_HSTypeDef SrcHS;            /*!< Specifies the channel source handshaking interface. */

  DMA_HSTypeDef DstHS;            /*!< Specifies the channel destination handshaking interface. */
#endif /* DMA_HARDWARE_HANDSHAKING */
#if (DMA_LOCK_ENABLE)
  DMA_LockTypeDef LockBus;        /*!< Specifies the bus lock. */

  DMA_LockTypeDef LockChannel;    /*!< Specifies the channel lock. */
#endif /* DMA_LOCK_ENABLE */
#if (DMA_MABRST)
  uint32_t MaxAbrst;              /*!< Specifies the channel maximum AMBA burst length. */
#endif  /* DMA_MABRST */                                        
#if (DMA_LLP_ENABLE)                                 
  uint32_t SsUpdEn;               /*!< Specifies the channel source status update enable. */

  uint32_t DsUpdEn;               /*!< Specifies the channel destination status update enable. */
#endif /* DMA_LLP_ENABLE */                                        
} DMA_InitTypeDef;

/**
  * @brief  HAL DMA State structures definition
  */
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled    */
  HAL_DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use      */
  HAL_DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing                 */
  HAL_DMA_STATE_TIMEOUT           = 0x03U,  /*!< DMA timeout state                      */
} HAL_DMA_StateTypeDef;

/**
  * @brief  HAL DMA Error Code structure definition
  */
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,  /*!< Full transfer     */
  HAL_DMA_HALF_TRANSFER           = 0x01U   /*!< Half Transfer     */
} HAL_DMA_LevelCompleteTypeDef;

/**
  * @brief  HAL DMA Callback ID structure definition
  */
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID          = 0x00U,  /*!< Transfer Complete                  */
  HAL_DMA_XFER_BLOCK_CB_ID         = 0x02U,  /*!< Block Transfer Complete             */
  HAL_DMA_XFER_DSTTRAN_CB_ID       = 0x03U,  /*!< Destination Transaction Complete    */
  HAL_DMA_XFER_ERROR_CB_ID         = 0x04U,  /*!< Error                               */
  HAL_DMA_XFER_SRCTRAN_CB_ID       = 0x05U,  /*!< Source Transaction Complete         */
  HAL_DMA_XFER_ABORT_CB_ID         = 0x06U,  /*!< Abort Transaction                   */
  HAL_DMA_XFER_ALL_CB_ID           = 0x07U   /*!< All                                 */

} HAL_DMA_CallbackIDTypeDef;

/**
  * @brief  DMA handle Structure definition
  */
typedef struct __DMA_HandleTypeDef
{
  DMA_Channel_TypeDef             *Instance;                          /*!< Register base address                 */

  DMA_InitTypeDef                 Init;                               /*!< DMA communication parameters          */

  HAL_LockTypeDef                 Lock;                               /*!< DMA locking object                    */

  __IO HAL_DMA_StateTypeDef       State;                              /*!< DMA transfer state                    */
	
	uint8_t                         dumy[2];

  void   *Parent;                                                     /*!< Parent object state                   */

  void (* XferCpltCallback)(struct __DMA_HandleTypeDef *hdma);        /*!< DMA transfer complete callback        */

  void (* XferBlockCallback)(struct __DMA_HandleTypeDef *hdma);       /*!< DMA Block transfer complete callback  */

  void (* XferDstTranCallback)(struct __DMA_HandleTypeDef *hdma);     /*!< DMA destination transfer complete callback  */

  void (* XferErrorCallback)(struct __DMA_HandleTypeDef *hdma);       /*!< DMA transfer error callback           */

  void (* XferSrcTranCallback)(struct __DMA_HandleTypeDef *hdma);     /*!< DMA source transfer complete callback */

  void (* XferAbortCallback)(struct __DMA_HandleTypeDef *hdma);       /*!< DMA snort callback */
	
  __IO uint32_t                   ErrorCode;                          /*!< DMA Error code                        */

  uint32_t                        ChannelIndex;                       /*!< DMA Channel Index                     */

  DMA_TypeDef                     *DMAAux;                            /*!< DMA interrupt, configuation,channel enable, software handshaking and miscellanuous         */

} DMA_HandleTypeDef;

#if (DMA_LLP_ENABLE)
/**
  * @brief  DMA CTLx_L in LLP Structure definition
  */
typedef union __DMA_LLP_CTLLTypeDef
{
  struct
  {
    uint32_t IntEn          : 1 ;      /*!< interrupt enable                          [0]                              */           
    uint32_t DstTrWidth     : 3 ;      /*!< Destination transfer width                [3:1]                            */           
    uint32_t SrcTrWidth     : 3 ;      /*!< Source transfer width                     [6:4]                            */           
    uint32_t Dinc           : 2 ;      /*!< Destinaton address increment              [8:7]                            */           
    uint32_t Sinc           : 2 ;      /*!< Source address increment                  [10:9]                           */           
    uint32_t DstMSize       : 3 ;      /*!< Destination burst transaction length      [13:11]                          */           
    uint32_t SrcMSize       : 3 ;      /*!< Source burst transaction length           [16:14]                          */           
    uint32_t SrcGatherEn    : 1 ;      /*!< Source gather enable                      [17]                             */           
    uint32_t DstScatterEn   : 1 ;      /*!< Destination scatter enable                [18]                             */   
    uint32_t Dumy1          : 1 ;      /*!< Reserved                                  [19]                             */  
    uint32_t Ttfc           : 3 ;      /*!< Transfer type and flow control            [22:20]                          */  
    uint32_t Dms            : 2 ;      /*!< Destination master select                 [24:23]                          */  
    uint32_t Sms            : 2 ;      /*!< Source master select                      [26:25]                          */  
    uint32_t LlpDstEn       : 1 ;      /*!< Destination block chaining enable         [27]                             */  
    uint32_t LlpSrcEn       : 1 ;      /*!< Source block chaining enable              [28]                             */  
    uint32_t Dumy2          : 3 ;      /*!< Reserved                                  [31:29]                          */  
  } Bitfield;
  uint32_t Value;
}DMA_LLP_CTLLTypeDef;

/**
  * @brief  DMA CTLx_H in LLP Structure definition
  */
typedef union __DMA_LLP_CTLHTypeDef
{
  struct
  {
    uint32_t BlockTs        : 12;      /*!< Block transfer size                       [0:11]                           */           
    uint32_t Done           : 1 ;      /*!< Done                                      [12]                             */           
    uint32_t Dumy1          : 19;      /*!< Reserved                                  [31-13]                          */  
  } Bitfield;
  uint32_t Value;
}DMA_LLP_CTLHTypeDef;

/**
  * @brief  DMA LLP Structure definition
  */
typedef struct __DMA_LLPTypeDef
{
  uint32_t SrcAddress;             /*!< source address                                           */
  uint32_t DstAddress;             /*!< destination address                                      */
  struct __DMA_LLPTypeDef *NextLLP;       /*!< pointer to the next LLP                           */
  uint32_t Ctl_L;                  /*!< CTL register 31-0                                        */
  uint32_t Ctl_H;                  /*!< CTL register 63-32                                       */
 #if defined(DMAH_CHX_STAT_SRC)   
  uint32_t WbSrcStatus;            /*!< write-back to source status                              */
#endif //defined(DMAH_CHX_STAT_SRC)  
  uint32_t WbDstStatus;            /*!< write-back to destination status                         */
} DMA_LLPTypeDef;
#endif /* DMA_LLP_ENABLE */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup DMA_Exported_Constants DMA Exported Constants
  * @{
  */

/** @defgroup DMA_Channel_number DMA channel number
  * @{
  */
#define HAL_DMA_CH_NUMBER            0x00000008U       /*!< DMA channel number                      */
/**
  * @}
  */

/** @defgroup DMA_EC_CHANNEL CHANNEL 
  * @{
  */
#define DMA_CHANNEL_0                (0x00000000UL)    /*!< DMA Channel 0 */
#define DMA_CHANNEL_1                (0x00000001UL)    /*!< DMA Channel 1 */
#define DMA_CHANNEL_2                (0x00000002UL)    /*!< DMA Channel 2 */
#define DMA_CHANNEL_3                (0x00000003UL)    /*!< DMA Channel 3 */
#define DMA_CHANNEL_4                (0x00000004UL)    /*!< DMA Channel 4 */
#define DMA_CHANNEL_5                (0x00000005UL)    /*!< DMA Channel 5 */
#define DMA_CHANNEL_6                (0x00000006UL)    /*!< DMA Channel 6 */
#define DMA_CHANNEL_7                (0x00000007UL)    /*!< DMA Channel 7 */
/**
  * @}
  */

/** @defgroup DMA_Error_Code DMA Error Code
  * @{
  */
#define HAL_DMA_ERROR_NONE           (0x00000000U)     /*!< No error                                */
#define HAL_DMA_ERROR_TE             (0x00000001U)     /*!< Transfer error                          */
#define HAL_DMA_ERROR_NO_XFER        (0x00000004U)     /*!< Abort requested with no Xfer ongoing    */
#define HAL_DMA_ERROR_TIMEOUT        (0x00000020U)     /*!< Timeout error                           */
#define HAL_DMA_ERROR_PARAM          (0x00000040U)     /*!< Parameter error                         */
#define HAL_DMA_ERROR_BUSY           (0x00000080U)     /*!< DMA Busy error                          */
#define HAL_DMA_ERROR_NOT_SUPPORTED  (0x00000100U)     /*!< Not supported mode                      */
#define HAL_DMA_ERROR_SYNC           (0x00000200U)     /*!< DMAMUX sync overrun error               */
#define HAL_DMA_ERROR_REQGEN         (0x00000400U)     /*!< DMAMUX request generator overrun error  */
#define HAL_DMA_ERROR_NO_CH          (0x00000800U)     /*!< Channel is full                         */

/**
  * @}
  */
	
/** @defgroup DMA_HS_IF hardware handshaking interface defination
  * @{
  */
#define DMA_SRC_HSIF_0                 (0x00000000UL)                                                                          /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_1                 (DMA_CH_CHCFG_SRCPER_0)                                                                    /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_2                 (DMA_CH_CHCFG_SRCPER_1)                                                                    /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_3                 (DMA_CH_CHCFG_SRCPER_1 | DMA_CH_CHCFG_SRCPER_0)                                               /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_4                 (DMA_CH_CHCFG_SRCPER_2)                                                                    /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_5                 (DMA_CH_CHCFG_SRCPER_2 | DMA_CH_CHCFG_SRCPER_0)                                               /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_6                 (DMA_CH_CHCFG_SRCPER_2 | DMA_CH_CHCFG_SRCPER_1)                                               /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_7                 (DMA_CH_CHCFG_SRCPER_2 | DMA_CH_CHCFG_SRCPER_1 | DMA_CH_CHCFG_SRCPER_0)                          /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_8                 (DMA_CH_CHCFG_SRCPER_3)                                                                    /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_9                 (DMA_CH_CHCFG_SRCPER_3 | DMA_CH_CHCFG_SRCPER_0)                                               /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_10                (DMA_CH_CHCFG_SRCPER_3 | DMA_CH_CHCFG_SRCPER_1)                                               /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_11                (DMA_CH_CHCFG_SRCPER_3 | DMA_CH_CHCFG_SRCPER_1 | DMA_CH_CHCFG_SRCPER_0)                          /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_12                (DMA_CH_CHCFG_SRCPER_3 | DMA_CH_CHCFG_SRCPER_2)                                               /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_13                (DMA_CH_CHCFG_SRCPER_3 | DMA_CH_CHCFG_SRCPER_2 | DMA_CH_CHCFG_SRCPER_0)                          /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_14                (DMA_CH_CHCFG_SRCPER_3 | DMA_CH_CHCFG_SRCPER_2 | DMA_CH_CHCFG_SRCPER_1)                          /*!< Channel DMA hardware handshaking interface (source) */
#define DMA_SRC_HSIF_15                (DMA_CH_CHCFG_SRCPER_3 | DMA_CH_CHCFG_SRCPER_2 | DMA_CH_CHCFG_SRCPER_1 | DMA_CH_CHCFG_SRCPER_0)     /*!< Channel DMA hardware handshaking interface (source) */

#define DMA_DST_HSIF_0                 (0x00000000UL)                                                                          /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_1                 (DMA_CH_CHCFG_DSTPER_0)                                                                    /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_2                 (DMA_CH_CHCFG_DSTPER_1)                                                                    /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_3                 (DMA_CH_CHCFG_DSTPER_1 | DMA_CH_CHCFG_DSTPER_0)                                               /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_4                 (DMA_CH_CHCFG_DSTPER_2)                                                                    /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_5                 (DMA_CH_CHCFG_DSTPER_2 | DMA_CH_CHCFG_DSTPER_0)                                               /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_6                 (DMA_CH_CHCFG_DSTPER_2 | DMA_CH_CHCFG_DSTPER_1)                                               /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_7                 (DMA_CH_CHCFG_DSTPER_2 | DMA_CH_CHCFG_DSTPER_1 | DMA_CH_CHCFG_DSTPER_0)                          /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_8                 (DMA_CH_CHCFG_DSTPER_3)                                                                    /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_9                 (DMA_CH_CHCFG_DSTPER_3 | DMA_CH_CHCFG_DSTPER_0)                                               /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_10                (DMA_CH_CHCFG_DSTPER_3 | DMA_CH_CHCFG_DSTPER_1)                                               /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_11                (DMA_CH_CHCFG_DSTPER_3 | DMA_CH_CHCFG_DSTPER_1 | DMA_CH_CHCFG_DSTPER_0)                          /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_12                (DMA_CH_CHCFG_DSTPER_3 | DMA_CH_CHCFG_DSTPER_2)                                               /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_13                (DMA_CH_CHCFG_DSTPER_3 | DMA_CH_CHCFG_DSTPER_2 | DMA_CH_CHCFG_DSTPER_0)                          /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_14                (DMA_CH_CHCFG_DSTPER_3 | DMA_CH_CHCFG_DSTPER_2 | DMA_CH_CHCFG_DSTPER_1)                          /*!< Channel DMA hardware handshaking interface (destination) */
#define DMA_DST_HSIF_15                (DMA_CH_CHCFG_DSTPER_3 | DMA_CH_CHCFG_DSTPER_2 | DMA_CH_CHCFG_DSTPER_1 | DMA_CH_CHCFG_DSTPER_0)     /*!< Channel DMA hardware handshaking interface (destination) */

/* Alias */
//#define DMA_UART1_RX_CFG0_SRC_HSIF     (DMA_SRC_HSIF_1)
//#define DMA_UART2_RX_CFG0_SRC_HSIF     (DMA_SRC_HSIF_3)
//#define DMA_ADC_EOS_CFG0_SRC_HSIF      (DMA_SRC_HSIF_5)
//#define DMA_I2C1_RX_CFG0_SRC_HSIF      (DMA_SRC_HSIF_9)
//#define DMA_CRC_RX_CFG0_SRC_HSIF       (DMA_SRC_HSIF_11)
//#define DMA_SPI1_RX_CFG0_SRC_HSIF      (DMA_SRC_HSIF_13)
//#define DMA_SPI3_RX_CFG0_SRC_HSIF      (DMA_SRC_HSIF_15)
//
//#define DMA_UART1_TX_CFG0_DST_HSIF     (DMA_DST_HSIF_0)
//#define DMA_UART2_TX_CFG0_DST_HSIF     (DMA_DST_HSIF_2)
//#define DMA_TIMA_COMB_CFG0_DST_HSIF    (DMA_DST_HSIF_4)
//#define DMA_I2C1_TX_CFG0_DST_HSIF      (DMA_DST_HSIF_8)
//#define DMA_CRC_TX_CFG0_DST_HSIF       (DMA_DST_HSIF_10)
//#define DMA_SPI1_TX_CFG0_DST_HSIF      (DMA_DST_HSIF_12)
//#define DMA_SPI3_TX_CFG0_DST_HSIF      (DMA_DST_HSIF_14)
//
//#define DMA_I2C1_RX_CFG1_SRC_HSIF      (DMA_SRC_HSIF_1)
//#define DMA_UART3_RX_CFG1_SRC_HSIF     (DMA_SRC_HSIF_5)
//#define DMA_UART4_RX_CFG1_SRC_HSIF     (DMA_SRC_HSIF_7)
//#define DMA_SPI1_RX_CFG1_SRC_HSIF      (DMA_SRC_HSIF_9)
//#define DMA_I2C2_RX_CFG1_SRC_HSIF      (DMA_SRC_HSIF_11)
//#define DMA_UART3A_RX_CFG1_SRC_HSIF    (DMA_SRC_HSIF_13)
//#define DMA_I2C1A_RX_CFG1_SRC_HSIF     (DMA_SRC_HSIF_15)
//
//#define DMA_I2C1_TX_CFG1_DST_HSIF      (DMA_DST_HSIF_0)
//#define DMA_UART3_TX_CFG1_DST_HSIF     (DMA_DST_HSIF_4)
//#define DMA_UART4_TX_CFG1_DST_HSIF     (DMA_DST_HSIF_6)
//#define DMA_SPI1_TX_CFG1_DST_HSIF      (DMA_DST_HSIF_8)
//#define DMA_I2C2_TX_CFG1_DST_HSIF      (DMA_DST_HSIF_10)
//#define DMA_UART3A_TX_CFG1_DST_HSIF    (DMA_DST_HSIF_12)
//#define DMA_I2C1A_TX_CFG1_DST_HSIF     (DMA_DST_HSIF_14)
//
//#define DMA_SPI1_RX_CFG2_SRC_HSIF      (DMA_SRC_HSIF_1)
//#define DMA_UART2_RX_CFG2_SRC_HSIF     (DMA_SRC_HSIF_15)
//
//#define DMA_SPI1_TX_CFG2_DST_HSIF      (DMA_DST_HSIF_0)
//#define DMA_TIMA_TRG_COM_CFG2_DST_HSIF (DMA_DST_HSIF_2)
//#define DMA_TIMA_CC1_CFG2_DST_HSIF     (DMA_DST_HSIF_4)
//#define DMA_TIMA_CC2_CFG2_DST_HSIF     (DMA_DST_HSIF_6)
//#define DMA_TIMA_CC3_CFG2_DST_HSIF     (DMA_DST_HSIF_8)
//#define DMA_TIMA_CC4_CFG2_DST_HSIF     (DMA_DST_HSIF_10)
//#define DMA_TIMA_UDT_CFG2_DST_HSIF     (DMA_DST_HSIF_12)
//#define DMA_UART2_TX_CFG2_DST_HSIF     (DMA_DST_HSIF_14)
//
//#define DMA_LED_FRM_CFG3_DST_HSIF      (DMA_DST_HSIF_0)
//#define DMA_LED_UDT_CFG3_DST_HSIF      (DMA_DST_HSIF_1)
//#define DMA_TIMG_TRG_COM_CFG3_DST_HSIF (DMA_DST_HSIF_2)
//#define DMA_LED_COM_CFG3_DST_HSIF      (DMA_DST_HSIF_3)
//#define DMA_TIMG_CC1_CFG3_DST_HSIF     (DMA_DST_HSIF_4)
//#define DMA_TIMG_CC2_CFG3_DST_HSIF     (DMA_DST_HSIF_6)
//#define DMA_TIMG_CC3_CFG3_DST_HSIF     (DMA_DST_HSIF_8)
//#define DMA_TIMG_CC4_CFG3_DST_HSIF     (DMA_DST_HSIF_10)
//#define DMA_TIMG_UDT_CFG3_DST_HSIF     (DMA_DST_HSIF_12)
//#define DMA_TIMG_COMB_CFG3_DST_HSIF    (DMA_DST_HSIF_14)
/**
  * @}
  */

/** @defgroup DMA_Data_transfer_direction DMA Data transfer direction
  * @{
  */
#define DMA_MEMORY_TO_MEMORY_FC_DMAC       (0)                                                                 /*!< Memory to memory direction, flow control by DMAC */
#define DMA_MEMORY_TO_PERIPH_FC_DMAC       (DMA_CH_CHCTL_TTFC_0)                                                  /*!< Memory to peripheral direction, flow control by DMAC */
#define DMA_PERIPH_TO_MEMORY_FC_DMAC       (DMA_CH_CHCTL_TTFC_1)                                                  /*!< Peripheral to memory direction, flow control by DMAC */
#define DMA_PERIPH_TO_PERIPH_FC_DMAC       (DMA_CH_CHCTL_TTFC_1 | DMA_CH_CHCTL_TTFC_0)                               /*!< Peripheral to peripheral direction, flow control by DMAC */
#define DMA_PERIPH_TO_MEMORY_FC_PERI       (DMA_CH_CHCTL_TTFC_2)                                                  /*!< Peripheral to memory direction, flow control by peripheralC */
#define DMA_PERIPH_TO_PERIPH_FC_SRCP       (DMA_CH_CHCTL_TTFC_2 | DMA_CH_CHCTL_TTFC_0)                               /*!< Peripheral to peripheral direction, flow control by source peripheral */
#define DMA_MEMORY_TO_PERIPH_FC_PERI       (DMA_CH_CHCTL_TTFC_2 | DMA_CH_CHCTL_TTFC_1)                               /*!< Memory to peripheral direction, flow control by peripheral */
#define DMA_PERIPH_TO_PERIPH_FC_DSTP       (DMA_CH_CHCTL_TTFC_2 | DMA_CH_CHCTL_TTFC_1 | DMA_CH_CHCTL_TTFC_0)            /*!< Peripheral to peripheral direction, flow control by destination peripheral */
/**
  * @}
  */

/** @defgroup DMA_Source_incremented_mode DMA Peripheral incremented mode
  * @{
  */
#define DMA_SINC_INCREMENT             (0)                                     /*!< Source Address Increment  */
#define DMA_SINC_DECREMENT             (DMA_CH_CHCTL_SINC_0)                      /*!< Source Address Decrement  */
#define DMA_SINC_NOCHANGE              (DMA_CH_CHCTL_SINC_1)                      /*!< Source Address No Change  */
/**
  * @}
  */

/** @defgroup DMA_Destination_incremented_mode DMA Memory incremented mode
  * @{
  */
#define DMA_DINC_INCREMENT             (0)                                     /*!< Destination Address Increment  */
#define DMA_DINC_DECREMENT             (DMA_CH_CHCTL_DINC_0)                      /*!< Destination Address Decrement  */
#define DMA_DINC_NOCHANGE              (DMA_CH_CHCTL_DINC_1)                      /*!< Destination Address No Change  */
/**
  * @}
  */

/** @defgroup DMA_Source_data_size DMA Peripheral data size
  * @{
  */
#define DMA_SDATAALIGN_BYTE            (0)                                                  /*!< Transfer Width : 8   bits  */
#define DMA_SDATAALIGN_HALFWORD        (DMA_CH_CHCTL_SRCTRW_0)                                 /*!< Transfer Width : 16  bits  */
#define DMA_SDATAALIGN_WORD            (DMA_CH_CHCTL_SRCTRW_1)                                 /*!< Transfer Width : 32  bits  */
#define DMA_SDATAALIGN_DOUBLEWORD      (DMA_CH_CHCTL_SRCTRW_1|DMA_CH_CHCTL_SRCTRW_0)              /*!< Transfer Width : 64  bits  */
#define DMA_SDATAALIGN_QUOTAWORD       (DMA_CH_CHCTL_SRCTRW_2)                                 /*!< Transfer Width : 128 bits  */
#define DMA_SDATAALIGN_OCTOWORD        (DMA_CH_CHCTL_SRCTRW_1|DMA_CH_CHCTL_SRCTRW_0)              /*!< Transfer Width : 256 bits  */
/**
  * @}
  */

/** @defgroup DMA_Destination_data_size DMA Memory data size
  * @{
  */
#define DMA_DDATAALIGN_BYTE            (0)                                                  /*!< Transfer Width : 8   bits  */
#define DMA_DDATAALIGN_HALFWORD        (DMA_CH_CHCTL_DSTTRW_0)                                 /*!< Transfer Width : 16  bits  */
#define DMA_DDATAALIGN_WORD            (DMA_CH_CHCTL_DSTTRW_1)                                 /*!< Transfer Width : 32  bits  */
#define DMA_DDATAALIGN_DOUBLEWORD      (DMA_CH_CHCTL_DSTTRW_1|DMA_CH_CHCTL_DSTTRW_0)              /*!< Transfer Width : 64  bits  */
#define DMA_DDATAALIGN_QUOTAWORD       (DMA_CH_CHCTL_DSTTRW_2)                                 /*!< Transfer Width : 128 bits  */
#define DMA_DDATAALIGN_OCTOWORD        (DMA_CH_CHCTL_DSTTRW_2|DMA_CH_CHCTL_DSTTRW_0)              /*!< Transfer Width : 256 bits  */
/**
  * @}
  */

/** @defgroup DMA_destination_burst_size Destination Burst Transaction Length 
  * @{
  */
#define DMA_DST_MSIZE_1                (0)                                                                            /*!< Destination Burst Transaction Length : 1   bits  */
#define DMA_DST_MSIZE_4                (DMA_CH_CHCTL_DSTMSIZE_0)                                                         /*!< Destination Burst Transaction Length : 4   bits  */
#define DMA_DST_MSIZE_8                (DMA_CH_CHCTL_DSTMSIZE_1)                                                         /*!< Destination Burst Transaction Length : 8   bits  */
#define DMA_DST_MSIZE_16               (DMA_CH_CHCTL_DSTMSIZE_1|DMA_CH_CHCTL_DSTMSIZE_0)                                    /*!< Destination Burst Transaction Length : 16  bits  */
#define DMA_DST_MSIZE_32               (DMA_CH_CHCTL_DSTMSIZE_2)                                                         /*!< Destination Burst Transaction Length : 32  bits  */
#define DMA_DST_MSIZE_64               (DMA_CH_CHCTL_DSTMSIZE_2|DMA_CH_CHCTL_DSTMSIZE_0)                                    /*!< Destination Burst Transaction Length : 64  bits  */
#define DMA_DST_MSIZE_128              (DMA_CH_CHCTL_DSTMSIZE_2|DMA_CH_CHCTL_DSTMSIZE_1)                                    /*!< Destination Burst Transaction Length : 128 bits  */
#define DMA_DST_MSIZE_256              (DMA_CH_CHCTL_DSTMSIZE_2|DMA_CH_CHCTL_DSTMSIZE_1|DMA_CH_CHCTL_DSTMSIZE_0)               /*!< Destination Burst Transaction Length : 256 bits  */
/**
  * @}
  */

/** @defgroup DMA_source_burst_size Source Burst Transaction Length 
  * @{
  */
#define DMA_SRC_MSIZE_1                (0)                                                                            /*!< Source Burst Transaction Length : 1   bits  */
#define DMA_SRC_MSIZE_4                (DMA_CH_CHCTL_SRCMSIZE_0)                                                         /*!< Source Burst Transaction Length : 4   bits  */
#define DMA_SRC_MSIZE_8                (DMA_CH_CHCTL_SRCMSIZE_1)                                                         /*!< Source Burst Transaction Length : 8   bits  */
#define DMA_SRC_MSIZE_16               (DMA_CH_CHCTL_SRCMSIZE_1|DMA_CH_CHCTL_SRCMSIZE_0)                                    /*!< Source Burst Transaction Length : 16  bits  */
#define DMA_SRC_MSIZE_32               (DMA_CH_CHCTL_SRCMSIZE_2)                                                         /*!< Source Burst Transaction Length : 32  bits  */
#define DMA_SRC_MSIZE_64               (DMA_CH_CHCTL_SRCMSIZE_2|DMA_CH_CHCTL_SRCMSIZE_0)                                    /*!< Source Burst Transaction Length : 64  bits  */
#define DMA_SRC_MSIZE_128              (DMA_CH_CHCTL_SRCMSIZE_2|DMA_CH_CHCTL_SRCMSIZE_1)                                    /*!< Source Burst Transaction Length : 128 bits  */
#define DMA_SRC_MSIZE_256              (DMA_CH_CHCTL_SRCMSIZE_2|DMA_CH_CHCTL_SRCMSIZE_1|DMA_CH_CHCTL_SRCMSIZE_0)               /*!< Source Burst Transaction Length : 256 bits  */
/**
  * @}
  */

/** @defgroup DMA_mode DMA mode
  * @{
  */
#define DMA_SGLBLK                     (0x00000000UL)                     /*!< Single-block or last transfer of multi-block \
                                                                               LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#define DMA_MULBLK_CSAR_RDAR           (0x00000001UL)                     /*!< Auto-reload multi-block transfer with contiguous SAR \
                                                                               LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */
#define DMA_MULBLK_RSAR_CDAR           (0x00000002UL)                     /*!< Auto-reload multi-block transfer with contiguous DAR \
                                                                               LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0     */
#define DMA_MULBLK_RSAR_RDAR           (0x00000003U)                      /*!< Auto-reload multi-block transfer \
                                                                               LLP.LOC 0 | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1     */
#if (DMA_LLP_ENABLE)  							  																															
#define DMA_MULBLK_CSAR_LDAR           LL_DMA_TFRMODE_MULBLK_LLST_CONSAR  /*!< Linked list multi-block transfer with contiguous SAR \
                                                                               LLP.LOC addr | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
#define DMA_MULBLK_RSAR_LDAR           LL_DMA_TFRMODE_MULBLK_LLST_ARLSAR  /*!< Linked list multi-block transfer with auto-reload SAR \
                                                                               LLP.LOC addr | CTL.LLP_SRC_EN 0 | CFG.RELOAD_SRC 1 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
#define DMA_MULBLK_LSAR_CDAR           LL_DMA_TFRMODE_MULBLK_LLST_CONDAR  /*!< Linked list multi-block transfer with contiguous DAR \
                                                                               LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 0  */
#define DMA_MULBLK_LSAR_RDAR           LL_DMA_TFRMODE_MULBLK_LLST_ARLDAR  /*!< Linked list multi-block transfer with auto-reload DAR \
                                                                               LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 0 | CFG.RELOAD_DST 1  */
#define DMA_MULBLK_LSAR_LDAR           LL_DMA_TFRMODE_MULBLK_LLST         /*!< Linked list multi-block transfer \
                                                                               LLP.LOC addr | CTL.LLP_SRC_EN 1 | CFG.RELOAD_SRC 0 | CTL.LLP_DST_EN 1 | CFG.RELOAD_DST 0  */
#endif																																						 
/**
  * @}
  */

/** @defgroup DMA_Priority_level DMA Priority level
  * @{
  */
#define DMA_PRIORITY_0               (0)                                                                      /*!< Channel DMA Channel priority 0 lowest */
#define DMA_PRIORITY_1               (DMA_CH_CHCFG_PRIOR_0)                                                      /*!< Channel DMA Channel priority 1        */
#define DMA_PRIORITY_2               (DMA_CH_CHCFG_PRIOR_1)                                                      /*!< Channel DMA Channel priority 2        */
#define DMA_PRIORITY_3               (DMA_CH_CHCFG_PRIOR_1|DMA_CH_CHCFG_PRIOR_0)                                    /*!< Channel DMA Channel priority 3        */
#define DMA_PRIORITY_4               (DMA_CH_CHCFG_PRIOR_2)                                                      /*!< Channel DMA Channel priority 4        */
#define DMA_PRIORITY_5               (DMA_CH_CHCFG_PRIOR_2|DMA_CH_CHCFG_PRIOR_0)                                    /*!< Channel DMA Channel priority 5        */
#define DMA_PRIORITY_6               (DMA_CH_CHCFG_PRIOR_2|DMA_CH_CHCFG_PRIOR_1)                                    /*!< Channel DMA Channel priority 6        */
#define DMA_PRIORITY_7               (DMA_CH_CHCFG_PRIOR_2|DMA_CH_CHCFG_PRIOR_1|DMA_CH_CHCFG_PRIOR_0)                  /*!< Channel DMA Channel priority 7        */
/**
  * @}
  */

/** @defgroup DMA_interrupt_enable_definitions DMA interrupt enable definitions
  * @{
  */
#define DMA_IT                         (DMA_CH_CHCTL_INTEN)                  /*!< Channel interrupt      */
/**
  * @}
  */
	
/** @defgroup DMA_Init_MODe DMA initial mode
  * @{
  */
#define DMA_NORMAL                     (DMA_SGLBLK)                        /*!< Normal Mode              */
/**
  * @}
  */
	

/** @defgroup DMA_SRCHS_POL DMA source hand shaking polarity
  * @{
  */
#define DMA_SRCHS_POL_HIGH             (0)                                     /*!< source hand shaking active high */
#define DMA_SRCHS_POL_LOW              (DMA_CH_CHCFG_SRCHSPOL)                    /*!< source hand shaking active low  */
/**
  * @}
  */

/** @defgroup DMA_DSTHS_POL DMA destination hand shaking polarity
  * @{
  */
#define DMA_DSTHS_POL_HIGH             (0)                                     /*!< Destination hand shaking active high */
#define DMA_DSTHS_POL_LOW              (DMA_CH_CHCFG_DSTHSPOL)                    /*!< Destination hand shaking active low  */
/**
  * @}
  */

/** @defgroup DMA_SRCHS_MODE DMA source hand shaking select
  * @{
  */
#define DMA_SRCHS_HW                   (0)                                     /*!< source hand shaking hardware select */
#define DMA_SRCHS_SW                   (DMA_CH_CHCFG_SRCHS)                       /*!< source hand shaking software select */
/**
  * @}
  */

/** @defgroup DMA_DSTHS_MODE DMA destination hand shaking select
  * @{
  */
#define DMA_DSTHS_HW                   (0)                                     /*!< Destination hand shaking hardware select */
#define DMA_DSTHS_SW                   (DMA_CH_CHCFG_DSTHS)                       /*!< Destination hand shaking software select */
/**
  * @}
  */

#if (DMA_MASTER_NUMBER > 1)
/** @defgroup DMA_SMS Source Master Select 
  * @{
  */
#define DMA_SMS_1                      (0)                                     /*!< Channel DMA Source Master Select : AHB Master 1  */
#define DMA_SMS_2                      (DMA_CH_CHCTL_SMS_0)                       /*!< Channel DMA Source Master Select : AHB Master 2  */
#define DMA_SMS_3                      (DMA_CH_CHCTL_SMS_1)                       /*!< Channel DMA Source Master Select : AHB Master 3  */
#define DMA_SMS_4                      (DMA_CH_CHCTL_SMS_0 | DMA_CH_CHCTL_SMS_0)     /*!< Channel DMA Source Master Select : AHB Master 4  */
/**
  * @}
  */

/** @defgroup DMA_DMS Destination Master Select 
  * @{
  */
#define DMA_DMS_1                      (0)                                     /*!< Channel DMA Destination Master Select : AHB Master 1  */
#define DMA_DMS_2                      (DMA_CH_CHCTL_DMS_0)                       /*!< Channel DMA Destination Master Select : AHB Master 2  */
#define DMA_DMS_3                      (DMA_CH_CHCTL_DMS_1)                       /*!< Channel DMA Destination Master Select : AHB Master 3  */
#define DMA_DMS_4                      (DMA_CH_CHCTL_DMS_1 | DMA_CH_CHCTL_DMS_0)     /*!< Channel DMA Destination Master Select : AHB Master 4  */
/**
  * @}
  */
#endif /* (DMA_MASTER_NUMBER > 1) */
/** @defgroup DMA_flag_definitions DMA flag definitions
  * @{
  */
#define DMA_FLAG_TFR                   (DMA_STATINT_TFR)                        /*!< Transfer complete combined Interrupt flag                */
#define DMA_FLAG_BLOCK                 (DMA_STATINT_BLOCK)                      /*!< Block transfer complete combined Interrupt flag          */
#define DMA_FLAG_SRCT                  (DMA_STATINT_SRCT)                       /*!< Source transaction complete combined Interrupt flag      */
#define DMA_FLAG_DSTT                  (DMA_STATINT_DSTT)                       /*!< Destination transaction complete combined Interrupt flag */
#define DMA_FLAG_ERR                   (DMA_STATINT_ERR)                        /*!< error combined Interrupt flag                            */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup DMA_Exported_Macros DMA Exported Macros
  * @{
  */

/** @brief  Reset DMA handle state
  * @param __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA_STATE_RESET)

/** @brief  Enable DMAC 
  * @param __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_DMAC(__HANDLE__) ((__HANDLE__)->DMAAux->DMACFG |= DMA_DMACFG_EN)

/** @brief  Disable DMAC 
  * @param __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_DMAC(__HANDLE__) ((__HANDLE__)->DMAAux->DMACFG &= ~DMA_DMACFG_EN)

/**
  * @brief  Enable the specified DMA Channel.
  * @param __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE(__HANDLE__)        ((__HANDLE__)->DMAAux->CHEN = ((DMA_CHEN_WE_0|DMA_CHEN_EN_0) << ((__HANDLE__)->ChannelIndex)))

/**
  * @brief  Disable the specified DMA Channel.
  * @param __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE(__HANDLE__)       ((__HANDLE__)->DMAAux->CHEN =  ((DMA_CHEN_WE_0) << ((__HANDLE__)->ChannelIndex)))

/**
  * @brief  Return the current DMA Channel interrupt flag.
  * @param __HANDLE__ DMA handle
  * @retval The specified interrup flag bit.
  */
#define __HAL_DMA_GET_IT_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA0_Channel0))? DMA_INTF_CH_0 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA0_Channel1))? DMA_INTF_CH_1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA0_Channel2))? DMA_INTF_CH_2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA0_Channel3))? DMA_INTF_CH_3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA0_Channel4))? DMA_INTF_CH_4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA0_Channel5))? DMA_INTF_CH_5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA0_Channel6))? DMA_INTF_CH_6 :\
   DMA_INTF_CH_7)

/**
  * @brief  Get the DMA Channel pending flags.
  * @param  __HANDLE__ DMA handle
  * @param  __FLAG__ Get the specified flag.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TFR:    Transfer complete flag
  *            @arg DMA_FLAG_BLOCK:  Block transfer complete flag
  *            @arg DMA_FLAG_SRCT:   Source transaction complete flag
  *            @arg DMA_FLAG_DSTT:   Destination transaction complete flag
  *            @arg DMA_FLAG_ERR:    Error interrupt flag
  * @retval The state of FLAG (SET or RESET).
  */
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)  \
(((__FLAG__) == DMA_FLAG_TFR)   ? ((DMAAUX1->RAWTFR) & (DMA_RAWTFR_CH_0 << ((__HANDLE__)->ChannelIndex)))     :\
 ((__FLAG__) == DMA_FLAG_BLOCK) ? ((DMAAUX1->RAWBLOCK) & (DMA_RAWBLOCK_CH_0 << ((__HANDLE__)->ChannelIndex)))   :\
 ((__FLAG__) == DMA_FLAG_SRCT)  ? ((DMAAUX1->RAWSRCTRAN) & (DMA_RAWSRCTRAN_CH_0 << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_DSTT)  ? ((DMAAUX1->RAWDSTTRAN) & (DMA_RAWDSTTRAN_CH_0 << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_ERR)   ? ((DMAAUX1->RAWERR) & (DMA_RAWERR_CH_0 << ((__HANDLE__)->ChannelIndex)))     :\
 0)

/**
  * @brief  Get the DMA Channel pending masked flags .
  * @param  __HANDLE__ DMA handle
  * @param  __FLAG__ Get the specified flag.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TFR:    Transfer complete flag
  *            @arg DMA_FLAG_BLOCK:  Block transfer complete flag
  *            @arg DMA_FLAG_SRCT:   Source transaction complete flag
  *            @arg DMA_FLAG_DSTT:   Destination transaction complete flag
  *            @arg DMA_FLAG_ERR:    Error interrupt flag
  * @retval The state of FLAG (SET or RESET).
  */
#define __HAL_DMA_GET_IT_FLAG(__HANDLE__, __FLAG__)  \
(((__FLAG__) == DMA_FLAG_TFR)   ? ((DMAAUX1->STATTFR) & (DMA_STATTFR_CH_0 << ((__HANDLE__)->ChannelIndex)))     :\
 ((__FLAG__) == DMA_FLAG_BLOCK) ? ((DMAAUX1->STATBLOCK) & (DMA_STATBLOCK_CH_0 << ((__HANDLE__)->ChannelIndex)))   :\
 ((__FLAG__) == DMA_FLAG_SRCT)  ? ((DMAAUX1->STATSRCTRAN) & (DMA_STATSRCTRAN_CH_0 << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_DSTT)  ? ((DMAAUX1->STATDSTTRAN) & (DMA_STATDSTTRAN_CH_0 << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_ERR)   ? ((DMAAUX1->STATERR) & (DMA_STATERR_CH_0 << ((__HANDLE__)->ChannelIndex)))     :\
 0)

/**
  * @brief  Clear the DMA Channel pending flags.
  * @param  __HANDLE__ DMA handle
  * @param  __FLAG__ specifies the flag to clear.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TFR:    Transfer complete flag
  *            @arg DMA_FLAG_BLOCK:  Block transfer complete flag
  *            @arg DMA_FLAG_SRCT:   Source transaction complete flag
  *            @arg DMA_FLAG_DSTT:   Destination transaction complete flag
  *            @arg DMA_FLAG_ERR:    Error interrupt flag
  * @retval None
  */
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) \
(((__FLAG__) == DMA_FLAG_TFR)   ? ((DMAAUX1->CLRTFR) = (DMA_CLRTFR_CH_0 << ((__HANDLE__)->ChannelIndex)))     :\
 ((__FLAG__) == DMA_FLAG_BLOCK) ? ((DMAAUX1->CLRBLOCK) = (DMA_CLRBLOCK_CH_0 << ((__HANDLE__)->ChannelIndex)))   :\
 ((__FLAG__) == DMA_FLAG_SRCT)  ? ((DMAAUX1->CLRSRCTRAN) = (DMA_CLRSRCTRAN_CH_0 << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_DSTT)  ? ((DMAAUX1->CLRDSTTRAN) = (DMA_CLRDSTTRAN_CH_0 << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_ERR)   ? ((DMAAUX1->CLRERR) = (DMA_CLRERR_CH_0 << ((__HANDLE__)->ChannelIndex)))     :\
 0)

/**
  * @brief  Mask the DMA Channel flags.
  * @param  __HANDLE__ DMA handle
  * @param  __FLAG__ specifies the flag to clear.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TFR:    Transfer complete flag
  *            @arg DMA_FLAG_BLOCK:  Block transfer complete flag
  *            @arg DMA_FLAG_SRCT:   Source transaction complete flag
  *            @arg DMA_FLAG_DSTT:   Destination transaction complete flag
  *            @arg DMA_FLAG_ERR:    Error interrupt flag
  * @retval None
  */
#define __HAL_DMA_MASK_FLAG(__HANDLE__, __FLAG__) \
(((__FLAG__) == DMA_FLAG_TFR)   ? ((DMAAUX1->MSKTFR)     = ((DMA_MSKTFR_WE_0) << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_BLOCK) ? ((DMAAUX1->MSKBLOCK)   = ((DMA_MSKBLOCK_WE_0) << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_SRCT)  ? ((DMAAUX1->MSKSRCTRAN) = ((DMA_MSKSRCTRAN_WE_0) << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_DSTT)  ? ((DMAAUX1->MSKDSTTRAN) = ((DMA_MSKDSTTRAN_WE_0) << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_ERR)   ? ((DMAAUX1->MSKERR)     = ((DMA_MSKERR_WE_0) << ((__HANDLE__)->ChannelIndex))) :\
 0)  

/**
  * @brief  Unmask the DMA Channel flags.
  * @param  __HANDLE__ DMA handle
  * @param  __FLAG__ specifies the flag to clear.
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TFR:    Transfer complete flag
  *            @arg DMA_FLAG_BLOCK:  Block transfer complete flag
  *            @arg DMA_FLAG_SRCT:   Source transaction complete flag
  *            @arg DMA_FLAG_DSTT:   Destination transaction complete flag
  *            @arg DMA_FLAG_ERR:    Error interrupt flag
  * @retval None
  */
#define __HAL_DMA_UNMASK_FLAG(__HANDLE__, __FLAG__) \
(((__FLAG__) == DMA_FLAG_TFR)   ? ((DMAAUX1->MSKTFR)     = ((DMA_MSKTFR_WE_0|DMA_MSKTFR_EN_0) << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_BLOCK) ? ((DMAAUX1->MSKBLOCK)   = ((DMA_MSKBLOCK_WE_0|DMA_MSKBLOCK_EN_0) << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_SRCT)  ? ((DMAAUX1->MSKSRCTRAN) = ((DMA_MSKSRCTRAN_WE_0|DMA_MSKSRCTRAN_EN_0) << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_DSTT)  ? ((DMAAUX1->MSKDSTTRAN) = ((DMA_MSKDSTTRAN_WE_0|DMA_MSKDSTTRAN_EN_0) << ((__HANDLE__)->ChannelIndex))) :\
 ((__FLAG__) == DMA_FLAG_ERR)   ? ((DMAAUX1->MSKERR)     = ((DMA_MSKERR_WE_0|DMA_MSKERR_EN_0) << ((__HANDLE__)->ChannelIndex))) :\
 0)    

/**
  * @brief  Enable the specified DMA Channel interrupts.
  * @param  __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_ENABLE_IT(__HANDLE__)   ((__HANDLE__)->Instance->CTL_L |= (DMA_CH_CHCTL_INTEN))

/**
  * @brief  Disable the specified DMA Channel interrupts.
  * @param  __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_DISABLE_IT(__HANDLE__)  ((__HANDLE__)->Instance->CTL_L &= ~(DMA_CH_CHCTL_INTEN))

/**
  * @brief  Get interrupt sources
  * @param  __HANDLE__ DMA handle
  * @retval Interrupts.
  */
#define __HAL_DMA_GET_IT_SOURCE(__HANDLE__)  (((__HANDLE__)->Instance->STATINT_L))

/**
  * @brief  Check whick interrupt occurs.
  * @param  __HANDLE__ DMA handle
  * @retval status (1: True; 0:False).
  */
#define __HAL_DMA_CHECK_IT_SOURCE(__HANDLE__, __FLAG__)  (((((__HANDLE__)->Instance->STATINT) & (__FLAG__)) == (__FLAG__)) ? 1UL : 0UL)

/**
  * @brief  Returns the number of remaining data units in the current DMA Channel transfer.
  * @param  __HANDLE__ DMA handle
  * @retval The number of remaining data units in the current DMA Channel transfer.
  */
#define __HAL_DMA_GET_DST_DATASIZE(__HANDLE__)	   ((((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTTRW) == DMA_DDATAALIGN_BYTE) ? 1 : \
                                                    (((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTTRW) == DMA_DDATAALIGN_HALFWORD) ? 2 : \
                                                    (((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTTRW) == DMA_DDATAALIGN_WORD) ? 4 : \
                                                    (((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTTRW) == DMA_DDATAALIGN_DOUBLEWORD) ? 8 : \
                                                    (((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTTRW) == DMA_DDATAALIGN_QUOTAWORD) ? 16 : \
                                                    32)
#define __HAL_DMA_GET_SRC_DATASIZE(__HANDLE__)	   ((((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCTRW) == DMA_SDATAALIGN_BYTE) ? 1 : \
                                                    (((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCTRW) == DMA_SDATAALIGN_HALFWORD) ? 2 : \
                                                    (((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCTRW) == DMA_SDATAALIGN_WORD) ? 4 : \
                                                    (((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCTRW) == DMA_SDATAALIGN_DOUBLEWORD) ? 8 : \
                                                    (((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCTRW) == DMA_SDATAALIGN_QUOTAWORD) ? 16 : \
                                                    32)

#define __HAL_DMA_GET_DST_MSIZE(__HANDLE__)	   ((((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTMSIZE) == DMA_DST_MSIZE_1) ? 1 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTMSIZE) == DMA_DST_MSIZE_4) ? 4 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTMSIZE) == DMA_DST_MSIZE_8) ? 8 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTMSIZE) == DMA_DST_MSIZE_16) ? 16 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTMSIZE) == DMA_DST_MSIZE_32) ? 32 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTMSIZE) == DMA_DST_MSIZE_64) ? 64 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_DSTMSIZE) == DMA_DST_MSIZE_128) ? 128 : \
                                               	256)
#define __HAL_DMA_GET_SRC_MSIZE(__HANDLE__)	   ((((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCMSIZE) == DMA_SRC_MSIZE_1) ? 1 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCMSIZE) == DMA_SRC_MSIZE_4) ? 4 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCMSIZE) == DMA_SRC_MSIZE_8) ? 8 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCMSIZE) == DMA_SRC_MSIZE_16) ? 16 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCMSIZE) == DMA_SRC_MSIZE_32) ? 32 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCMSIZE) == DMA_SRC_MSIZE_64) ? 64 : \
                                               	(((__HANDLE__)->Instance->CTL_L & DMA_CH_CHCTL_SRCMSIZE) == DMA_SRC_MSIZE_128) ? 128 : \
                                               	256)
																								

#define __HAL_DMA_GET_DST_COUNTER(__HANDLE__)  ((((__HANDLE__)->Instance->CTL_H & DMA_CH_CHCTL_BLOCKTS)>>DMA_CH_CHCTL_BLOCKTS_Pos)*\
                                                __HAL_DMA_GET_DST_MSIZE(__HANDLE__)*\
																							  __HAL_DMA_GET_DST_DATASIZE(__HANDLE__))
#define __HAL_DMA_GET_SRC_COUNTER(__HANDLE__)  ((((__HANDLE__)->Instance->CTL_H & DMA_CH_CHCTL_BLOCKTS)>>DMA_CH_CHCTL_BLOCKTS_Pos)*\
                                                __HAL_DMA_GET_SRC_MSIZE(__HANDLE__)*\
																								__HAL_DMA_GET_SRC_DATASIZE(__HANDLE__))
/**
  * @brief  Suspend DMA channel.
  * @param  __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_Suspend(__HANDLE__) (((__HANDLE__)->Instance->CFG_L |= (DMA_CH_CHCFG_SUSP)))

/**
  * @brief  Suspend DMA channel.
  * @param  __HANDLE__ DMA handle
  * @retval None
  */
#define __HAL_DMA_NotSuspend(__HANDLE__) (((__HANDLE__)->Instance->CFG_L &= (~(DMA_CH_CHCFG_SUSP))))

/**
  * @brief  Check FIFO empty
  * @param  __HANDLE__ DMA handle
  * @retval Status (1 or 0)
  */
#define __HAL_DMA_CHECK_FIFOEMPTY(__HANDLE__) ((((__HANDLE__)->Instance->CFG_L) & DMA_CH_CHCFG_FIFOE) ? 1UL : 0UL )

/**
  * @brief  Config source hand shaking
  * @param  __HANDLE__ DMA handle
	* @param  __CFG__
	* @param  __IF__
  * @retval None
  */
#define __HAL_DMA_CONFIG_SRCHS(__HANDLE__, __CFG__, __IF__) do { \
	                                                               MODIFY_REG(((__HANDLE__)->Instance->CFG_L), DMA_CH_CHCFG_SRCHSPOL|DMA_CH_CHCFG_SRCHS, __CFG__); \
	                                                               MODIFY_REG(((__HANDLE__)->Instance->CFG_H), DMA_CH_CHCFG_SRCPER, __IF__); \
                                                               } while(0)
	                                                                

/**
  * @brief  Config destination hand shaking
  * @param  __HANDLE__ DMA handle
	* @param  __CFG__
	* @param  __IF__
  * @retval None
  */
#define __HAL_DMA_CONFIG_DSTHS(__HANDLE__, __CFG__, __IF__) do { \
	                                                               MODIFY_REG(((__HANDLE__)->Instance->CFG_L), DMA_CH_CHCFG_DSTHSPOL|DMA_CH_CHCFG_DSTHS, __CFG__); \
	                                                               MODIFY_REG(((__HANDLE__)->Instance->CFG_H), DMA_CH_CHCFG_DSTPER, __IF__); \
                                                               } while(0)


/**
  * @brief  Convert DMA Instance DMAx and LL_DMA_CHANNEL_y into DMAx_Channely
  * @param  __DMA_INSTANCE__ DMAx
  * @param  __CHANNEL__ LL_DMA_CHANNEL_y
  * @retval DMAx_Channely
  */
#define __HAL_DMA_GET_CHANNEL_INSTANCE(__DMA_INSTANCE__, __CHANNEL__)   \
((((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)DMA_CHANNEL_0))) ? DMA1_Channel0 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)DMA_CHANNEL_1))) ? DMA1_Channel1 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)DMA_CHANNEL_2))) ? DMA1_Channel2 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)DMA_CHANNEL_3))) ? DMA1_Channel3 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)DMA_CHANNEL_4))) ? DMA1_Channel4 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)DMA_CHANNEL_5))) ? DMA1_Channel5 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)DMA_CHANNEL_6))) ? DMA1_Channel6 : \
 DMA1_Channel7)
																															 
/**
  * @}
  */

/* Include DMA HAL Extension module */
//#include "xt32h0xx_hal_dma_ex.h"

/* Exported functions --------------------------------------------------------*/

/** @addtogroup DMA_Exported_Functions
  * @{
  */

/** @addtogroup DMA_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions *****************************/
HAL_StatusTypeDef HAL_DMA_AllocateChannel(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);
/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
//HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma, uint32_t Timeout);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, HAL_DMA_LevelCompleteTypeDef CompleteLevel, uint32_t Timeout);
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)(DMA_HandleTypeDef *_hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);

HAL_StatusTypeDef HAL_DMA_StopInReloadMode(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_ResumeInReloadMode(DMA_HandleTypeDef *hdma);

HAL_StatusTypeDef HAL_DMA_SourceRequest(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DestinationRequest(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollingSourceRequest(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollingDestinationRequest(DMA_HandleTypeDef *hdma);

/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group3
  * @{
  */
/* Peripheral State and Error functions ***************************************/
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t             HAL_DMA_GetError(DMA_HandleTypeDef *hdma);
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
#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_HAL_DMA_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
