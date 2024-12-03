/**
  ******************************************************************************
  * @file    xt32h0xx_hal_adc.h
  * @author  Software Team
  * @brief   Header file of MDU ADC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_ADC_H
#define XT32H0xx_HAL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"
#include "xt32h0xx_hal_adc_port.h"

/* Include low level driver */
#include "xt32h0xx_ll_adc.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

/* Exported types ------------------------------------------------------------*/

#if defined(XT32H0xxB)
/** @defgroup ADC_Exported_Types ADC Exported Types
  * @{
  */

/**
  * @brief  ADC injection channel initial Structure definition
  */
typedef struct
{
  uint32_t ChannelIndex;                  /*!< ADC injection channle index
                                               This parameter can be a value of [0,3] for injection channel */

  uint32_t GroupIndex;                    /*!< ADC injetion channel group ID
                                               This parameter can be a value of @ref ADC_HAL_EC_InjectionGroup_ID */
	
  uint32_t AdcChannelIndex;               /*!< ADC channel index
                                               This parameter can be a value of @ref ADC_HAL_EC_ADC_Channel_Index */

  uint32_t AWDId;                         /*!< ADC AWD ID
                                               This parameter can be a value of @ref ADC_HAL_EC_AWD_ID */

  uint32_t PresamplingCycles;             /*!< ADC pre-sampling cycles (n+1)
                                               This parameter can be 0 to 0xFF */
}  ADC_InjectionChannelInitTypeDef;

/**
  * @brief  ADC regular channel initial Structure definition
  */
typedef struct
{
  uint32_t ChannelIndex;                  /*!< ADC regular channle index
                                               This parameter can be a value of [0,31] for regular channel */

  uint32_t AdcChannelIndex;               /*!< ADC channel index
                                               This parameter can be a value of @ref ADC_HAL_EC_ADC_Channel_Index */

  uint32_t AWDId;                         /*!< ADC AWD ID
                                               This parameter can be a value of @ref ADC_HAL_EC_AWD_ID */

}  ADC_RegularChannelInitTypeDef;

/**
  * @brief  ADC injection group initial Structure definition
  */
typedef struct
{
  uint32_t GroupIndex;                    /*!< ADC injection group index
                                               This parameter can be a value of [0,3] for injection group */

  uint32_t TriggerSource;                 /*!< ADC group trigger source
                                               This parameter can be a value of @ref ADC_HAL_EC_Group_TriggerSource */
	
  uint32_t TriggerMode;                   /*!< ADC group trigger mode
                                               This parameter can be a value of @ref ADC_HAL_EC_Group_TriggerMode */

}  ADC_InjectionGroupInitTypeDef;

/**
  * @brief  ADC regular group initial Structure definition
  */
typedef struct
{
  uint32_t GroupIndex;                    /*!< ADC regular group index
                                               This parameter can be a value of [0,7] for regular group */

  uint32_t TriggerSource;                 /*!< ADC group trigger source
                                               This parameter can be a value of @ref ADC_HAL_EC_Group_TriggerSource */
	
  uint32_t TriggerMode;                   /*!< ADC group trigger mode
                                               This parameter can be a value of @ref ADC_HAL_EC_Group_TriggerMode */

  uint32_t GroupMap;
}  ADC_RegularGroupInitTypeDef;

/**
  * @brief  ADC analog watch dog initial Structure definition
  */
typedef struct
{
  uint32_t AwdIndex;                      /*!< ADC AWD index
                                               This parameter can be a value of [0,2] */

  uint32_t Mode;                          /*!< ADC AWD mode
                                               This parameter can be a value of @ref ADC_HAL_EC_AWD_Mode */
	
  uint32_t HighThreshold;                 /*!< ADC AWD high threshold
                                               This parameter can be a value of [0, 0xFFF] */

  uint32_t LowThreshold;                  /*!< ADC AWD low threshold
                                               This parameter can be a value of [0, 0xFFF] */

}  ADC_AWDInitTypeDef;
#endif 

/**
  * @brief  ADC initial Structure definition
  */
typedef struct
{
#if defined(XT32H0xxB)
	uint32_t                             AmplifierGain;       /*!< ADC pre-amplifier gain 
	                                                               This parameter can be a value of @ref ADC_HAL_EC_AMPGAIN */
	
	uint32_t                             CalibrationEnable;   /*!< ADC Calibration enable 
	                                                               This parameter can be a value of @ref ADC_HAL_EC_CALIBRATE_ENABLE */
	
  uint32_t                             DischargeEnable;     /*!< ADC disable mode 
                                                                 This parameter can be a value of @ref ADC_HAL_EC_DISCHARGE_MODE */
  uint32_t                             DischargeCycles;     /*!< ADC discharge cycles (n+1)
                                                                 This parameter can be a value of [0, 0xFF] */

  uint32_t                             PresamplingMode;     /*!< ADC pre-sampling mode 
                                                                This parameter can be a value of @ref ADC_HAL_EC_PGA_PRESAMPLING_MODE */
  uint32_t                             PresamplingCycles;   /*!< ADC pre-sampling cycles (n+1)
                                                                 This parameter can be a value of [0, 0x3F] */ 

  uint32_t                             ResetPulseWidth;     /*!< ADC reset pulse width (n+1)
                                                                 This parameter can be a value of [0, 0xF] */ 

  uint32_t                             InterruptEnable;     /*!< ADC interrupt enable 
                                                                 This parameter can be combined of @ref ADC_HAL_EC_Interrupt_Enable */
  uint32_t                             InterruptPolarity;   /*!< ADC interrupt polarity 
                                                                 This parameter can be a value of @ref ADC_HAL_EC_Interrupt_Polarity */

  uint32_t                             InjectionGroupDMAHandShakingMode;  /*!< ADC injection group dma transfer handshaking enable 
                                                                               This parameter can be a value of @ref ADC_HAL_EC_Injection_DMA_HS_Enable */
  uint32_t                             RegularGroupDMAHandShakingMode;    /*!< ADC regular group dma transfer handshaking enable 
                                                                               This parameter can be a value of @ref ADC_HAL_EC_Regular_DMA_HS_Enable */

  uint32_t                             InjectionConversionEnable;         /*!< ADC injection group enable 
                                                                               This parameter can be combined of @ref ADC_HAL_EC_Injection_Enable */
  uint32_t                             RegularConversionEnable;           /*!< ADC regular group enable 
                                                                               This parameter can be combined of @ref ADC_HAL_EC_Regular_Enable */
 
  uint32_t                             InjectionGroupNumber;              /*!< injection group number*/

  uint32_t                             RegularGroupMap;                   /*!< regular group all channel bitwise mapping 
                                                                               This parameter can be combined of @ref ADC_HAL_EC_Regular_Channel_Map */

  uint32_t                             RegularGroupNumber;                /*!< regular group number */

  uint32_t                             RegularScanMode;                   /*!< ADC regular group scan mode
                                                                               This parameter can be a value of @ref ADC_HAL_EC_RegularGroup_ScanMode */
  uint32_t                             DataAlign;                         /*!< ADC output alignment
                                                                               This parameter can be a value of @ref ADC_HAL_EC_OUTPUT_ALIGNMENT */
	uint32_t                             ConversionResolution;              /*!< ADC convert trigger mode.
                                                                               This parameter can be a value of @ref ADC_HAL_EC_RESOLUTION */
#else 
  uint32_t Mode;                          /*!< ADC convert mode.
                                               This parameter can be a value of @ref ADC_HAL_EC_conversion_mode */
	
  uint32_t TrgSrc;                        /*!< ADC convert trigger source.
                                               This parameter can be a value of @ref ADC_HAL_EC_Trigger_Source */

  uint32_t TrgMode;                       /*!< ADC convert trigger mode.
                                               This parameter can be a value of @ref ADC_HAL_EC_TRIGGER_MODE */
	
	uint32_t SamplingWidth;                 /*!< ADC convert trigger mode.
                                               This parameter can be a value of @ref ADC_HAL_EC_conversion_sampling_width */
	
  uint32_t DutyCycle;                     /*!< Configures ADC duty cycle.
                                               This parameter can be a value of @ref ADC_HAL_EC_DUTYCYCLE */

  uint32_t Delay;                         /*!< Configures ADC delay.
                                               This parameter can be a value of @ref ADC_HAL_EC_DELAY */

	/* sequence convert */
  uint32_t SeqDir;                        /*!< ADC convert sequence direct.
                                               This parameter can be a value of @ref ADC_HAL_EC_SEQ_conversion_direct */
	
  uint32_t SeqGroup;                      /*!< ADC convert sequence channels qroup.
                                               This parameter can be combined values of @ref ADC_HAL_EC_SEQ_conversion_group */
	/* single channel convert */
  uint32_t ConCh;                         /*!< Configures ADC single convert channel.
                                               This parameter can be a value of @ref ADC_HAL_EC_SOURCE */
#endif /* XT32H0xxB */
} ADC_InitTypeDef;

#if defined(XT32H0xxB)
/**
  * @brief  ADC manual mode initial Structure definition
  */
typedef struct
{
  uint32_t PGA_Sampling;                  /*!< Configures ADC pga sample pulse enable.
                                               This parameter can be a value of @ref ADC_HAL_EC_MANU_SAMPLEPULSE_ENABLE */
  uint32_t Reset_Delay;                   /*!< Configures ADC reset delay.
                                               This parameter can be a value of [0, 0xF] */
  uint32_t Conversion_Mode;               /*!< Configures ADC conversion mode.
                                               This parameter can be a value of @ref ADC_HAL_EC_MANU_CONV_MODE */
} ADC_ManualInitTypeDef;
#endif /* XT32H0xxB */

/** 
  * @brief ADC_States ADC States
  */

/**
  * @brief  HAL ADC state machine: ADC states definition (bitfields)
  * @note   ADC state machine is managed by bitfields, state must be compared
  *         with bit by bit.
  *         For example:
  *           " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_REG_BUSY) != 0UL) "
  *           " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_AWD1) != 0UL) "
  */
typedef enum
{
/* States of ADC global scope */
  HAL_ADC_STATE_RESET             = (0x00000000UL),   /*!< ADC not yet initialized or disabled */
  HAL_ADC_STATE_READY             = (0x00000001UL),   /*!< ADC peripheral ready for use */
  HAL_ADC_STATE_BUSY_INTERNAL     = (0x00000002UL),   /*!< ADC is busy due to an internal process (initialization, calibration) */
  HAL_ADC_STATE_TIMEOUT           = (0x00000004UL),   /*!< TimeOut occurrence */

/* States of ADC errors */
  HAL_ADC_STATE_ERROR_INTERNAL    = (0x00000010UL),   /*!< Internal error occurrence */
  HAL_ADC_STATE_ERROR_CONFIG      = (0x00000020UL),   /*!< Configuration error occurrence */
  HAL_ADC_STATE_ERROR_DMA         = (0x00000040UL),   /*!< DMA error occurrence */

/* States of ADC group regular */
  HAL_ADC_STATE_REG_BUSY          = (0x00000100UL),   /*!< A conversion on ADC group regular is ongoing or can occur (either by continuous mode,
                                                              external trigger, low power auto power-on (if feature available), multimode ADC master control (if feature available)) */
  HAL_ADC_STATE_REG_EOC           = (0x00000200UL),   /*!< Conversion data available on group regular */
  HAL_ADC_STATE_REG_OVR           = (0x00000400UL)   /*!< Overrun occurrence */
} HAL_ADC_StateTypeDef;

/**
  * @brief  ADC handle Structure definition
  */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
typedef struct __ADC_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
{
  MDU_TypeDef                   *Instance;              /*!< Register base address */
  ADC_InitTypeDef               Init;                   /*!< MDU initialization parameters and regular conversions setting */
  HAL_LockTypeDef               Lock;                   /*!< MDU locking object */
	uint8_t                       dumy[3];
  __IO uint32_t                 State;                  /*!< MDU communication state (bitmap of MDU states) */
  __IO uint32_t                 ErrorCode;              /*!< MDU Error code */

  DMA_HandleTypeDef             *hdmarx;                /*!< MDU Rx DMA Handle parameters (regular)     */

  DMA_HandleTypeDef             *hdmarx2;               /*!< MDU Rx DMA Handle parameters (injection)     */

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  void (* ConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);              /*!< ADC conversion complete callback */
  void (* ErrorCallback)(struct __ADC_HandleTypeDef *hadc);                 /*!< ADC error callback */
  void (* SequenceCpltCallback)(struct __ADC_HandleTypeDef *hadc);          /*!< ADC sequence complete callback */
#if defined(XT32H0xxB)
  void (* InjectionEOCCallback)(struct __ADC_HandleTypeDef *hadc);          /*!< ADC injection conversion complete callback */
  void (* InjectionAwdCallback)(struct __ADC_HandleTypeDef *hadc);          /*!< ADC injection AWD callback */
  void (* InjectionOverWriteCallback)(struct __ADC_HandleTypeDef *hadc);    /*!< ADC injection over write callback */
  void (* InjectionEOSCallback)(struct __ADC_HandleTypeDef *hadc);          /*!< ADC injection sequence complete callback */
  void (* RegularEOCCallback)(struct __ADC_HandleTypeDef *hadc);            /*!< ADC regular conversion complete callback */
  void (* RegularAwdCallback)(struct __ADC_HandleTypeDef *hadc);            /*!< ADC regular AWD callback */
  void (* RegularOverWriteCallback)(struct __ADC_HandleTypeDef *hadc);      /*!< ADC regular over write callback */
  void (* RegularEOSCallback)(struct __ADC_HandleTypeDef *hadc);            /*!< ADC regular sequence complete callback */
  void (* InjectionDMACpltCallback)(struct __ADC_HandleTypeDef *hadc);      /*!< ADC injection DMA complete callback */
  void (* RegularDMACpltCallback)(struct __ADC_HandleTypeDef *hadc);        /*!< ADC regular DMA complete callback */
  void (* InjectionDMABlockCpltCallback)(struct __ADC_HandleTypeDef *hadc); /*!< ADC injection DMA block complete callback */
  void (* RegularDMABlockCpltCallback)(struct __ADC_HandleTypeDef *hadc);   /*!< ADC regular DMA block complete callback */
#endif /* XT32H0xxB */
  void (* MspInitCallback)(struct __ADC_HandleTypeDef *hadc);               /*!< ADC Msp Init callback */
  void (* MspDeInitCallback)(struct __ADC_HandleTypeDef *hadc);             /*!< ADC Msp DeInit callback */
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
} ADC_HandleTypeDef;


#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL ADC Callback ID enumeration definition
  */
typedef enum
{
  HAL_ADC_CONVERSION_COMPLETE_CB_ID     = 0x00U,  /*!< ADC conversion complete callback ID */
  HAL_ADC_ERROR_CB_ID                   = 0x03U,  /*!< ADC error callback ID */
  HAL_ADC_SEQUENCE_COMPLETE_CB_ID       = 0x08U,  /*!< ADC sequence conversion complete callback ID */
  HAL_ADC_MSPINIT_CB_ID                 = 0x09U,  /*!< ADC Msp Init callback ID          */
  HAL_ADC_MSPDEINIT_CB_ID               = 0x0AU,  /*!< ADC Msp DeInit callback ID        */
#if defined(XT32H0xxB)
  HAL_ADC_INJ_EOC_CB_ID                 = 0x10U,  /*!< ADC injection conversion complete callback ID */
  HAL_ADC_INJ_AWD_CB_ID                 = 0x11U,  /*!< ADC injection AWD callback ID */
  HAL_ADC_INJ_OW_CB_ID                  = 0x12U,  /*!< ADC injection Over Write callback ID */
  HAL_ADC_INJ_EOS_CB_ID                 = 0x18U,  /*!< ADC injection conversion complete callback ID */
  HAL_ADC_REG_EOC_CB_ID                 = 0x10U,  /*!< ADC regular conversion complete callback ID */
  HAL_ADC_REG_AWD_CB_ID                 = 0x11U,  /*!< ADC regular AWD callback ID */
  HAL_ADC_REG_OW_CB_ID                  = 0x12U,  /*!< ADC regular Over Write callback ID */
  HAL_ADC_REG_EOS_CB_ID                 = 0x18U,  /*!< ADC regular conversion complete callback ID */
  HAL_ADC_INJ_DMACPLT_CB_ID             = 0x20U,  /*!< ADC injection DMA complete callback ID */
  HAL_ADC_REG_DMACPLT_CB_ID             = 0x21U,  /*!< ADC regular DMA complete callback ID */
  HAL_ADC_INJ_BLKDMACPLT_CB_ID          = 0x22U,  /*!< ADC injection DMA block complete callback ID */
  HAL_ADC_REG_BLKDMACPLT_CB_ID          = 0x23U,  /*!< ADC regular DMA block complete callback ID */
#endif /* XT32H0xxB */
  HAL_ADC_ALL_CB_ID                     = 0x80U   /*!< ADC all callback ID */
} HAL_ADC_CallbackIDTypeDef;

/**
  * @brief  HAL ADC Callback pointer definition
  */
typedef  void (*pADC_CallbackTypeDef)(ADC_HandleTypeDef *hadc); /*!< pointer to a ADC callback function */

#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup ADC_Exported_Constants ADC Exported Constants
  * @{
  */

/** @defgroup ADC_Error_Code ADC Error Code
  * @{
  */
#define HAL_ADC_ERROR_NONE              (0x00U)   /*!< No error                                    */
#define HAL_ADC_ERROR_INTERNAL          (0x01U)   /*!< ADC peripheral internal error (problem of clocking,
                                                       enable/disable, erroneous state, ...)       */
#define HAL_ADC_ERROR_OVR               (0x02U)   /*!< Overrun error                               */
#define HAL_ADC_ERROR_DMA               (0x04U)   /*!< DMA transfer error                          */
#define HAL_ADC_ERROR_AWD               (0x08U)   /*!< AWD error                                   */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define HAL_ADC_ERROR_INVALID_CALLBACK  (0x10U)   /*!< Invalid Callback error */
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_POWER  Adc power 
  * @{
  */
#define ADC_MODE_POWERON               (0)                               /*!< ADC power on */
#define ADC_MODE_POWERDOWN             (MDU_PDCTRL_ADCPD)                /*!< ADC power down */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_AMPGAIN  Adc pre-amplifier 
  * @{
  */
#define ADC_AMPGAIN_5P565              (0)                               /*!< ADC AMPGAIN VDD = 5.565V */
#define ADC_AMPGAIN_5                  (MDU_ADCCFG_AMPGAIN_0)            /*!< ADC AMPGAIN VDD = 5V */
#define ADC_AMPGAIN_3P3                (MDU_ADCCFG_AMPGAIN_1)            /*!< ADC AMPGAIN VDD = 3.3V */
#define ADC_AMPGAIN_2P5                (MDU_ADCCFG_AMPGAIN_1 | MDU_ADCCFG_AMPGAIN_0)            /*!< ADC AMPGAIN VDD = 2.5V */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_CALIBRATE_ENABLE  Adc calibrate enable 
  * @{
  */
#define ADC_CALIBRATE_DISABLE          (0)
#define ADC_CALIBRATE_ENABLE           (MDU_ADCCALIB_CODE_COR_EN)
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_CALIBRATE_Mode  Adc calibrate mode 
  * @{
  */
#define ADC_CALIBRATE_MODE_WITHINIT    (0)
#define ADC_CALIBRATE_MODE_STANDONLY   (1)
/**
  * @}
  */

#if defined(XT32H0xxB)
/** @defgroup ADC_HAL_EC_ADC_Channel_Index ADC channel index
  * @{
  */
#define ADC_CHANNEL_1               (0)                 /*!< sync sampling channel*/
#define ADC_CHANNEL_2               (1)                 /*!< sync sampling channel*/
#define ADC_CHANNEL_3               (2)                 /*!< sync sampling channel*/
#define ADC_CHANNEL_4               (3)                 /*!< sync sampling channel*/
#define ADC_CHANNEL_5               (4)                 /*!< single-end channel*/
#define ADC_CHANNEL_6               (5)                 /*!< single-end channel*/
#define ADC_CHANNEL_7               (6)                 /*!< single-end channel*/
#define ADC_CHANNEL_8               (7)                 /*!< single-end channel*/
#define ADC_CHANNEL_9               (8)                 /*!< single-end channel*/
#define ADC_CHANNEL_10              (9)                 /*!< single-end channel*/
#define ADC_CHANNEL_11              (10)                /*!< single-end channel*/
#define ADC_CHANNEL_12              (11)                /*!< single-end channel*/
#define ADC_CHANNEL_13              (12)                /*!< single-end channel*/
#define ADC_CHANNEL_14              (13)                /*!< single-end channel*/
#define ADC_CHANNEL_15              (14)                /*!< single-end channel*/
#define ADC_CHANNEL_16              (15)                /*!< single-end channel*/
#define ADC_CHANNEL_17              (16)                /*!< single-end channel*/
#define ADC_CHANNEL_18              (17)                /*!< single-end channel*/
#define ADC_CHANNEL_19              (18)                /*!< single-end channel*/
#define ADC_CHANNEL_20              (19)                /*!< single-end channel*/
#define ADC_CHANNEL_21              (20)                /*!< single-end channel*/
#define ADC_CHANNEL_22              (21)                /*!< single-end channel*/
#define ADC_CHANNEL_23              (22)                /*!< single-end channel*/
#define ADC_CHANNEL_24              (23)                /*!< single-end channel*/
#define ADC_CHANNEL_25              (24)                /*!< single-end channel*/
#define ADC_CHANNEL_26              (25)                /*!< single-end channel*/
#define ADC_CHANNEL_27              (26)                /*!< single-end channel*/
#define ADC_CHANNEL_28              (27)                /*!< single-end channel*/
#define ADC_CHANNEL_29              (28)                /*!< single-end channel*/
#define ADC_CHANNEL_30              (29)                /*!< single-end channel*/
#define ADC_CHANNEL_31              (30)                /*!< single-end channel*/
#define ADC_CHANNEL_32              (31)                /*!< single-end channel*/
#define ADC_CHANNEL_33              (32)                /*!< single-end channel*/
#define ADC_CHANNEL_34              (33)                /*!< single-end channel*/
#define ADC_CHANNEL_35              (34)                /*!< single-end channel*/
#define ADC_CHANNEL_36              (35)                /*!< single-end channel*/
#define ADC_CHANNEL_37              (36)                /*!< single-end channel*/
#define ADC_CHANNEL_38              (37)                /*!< single-end channel*/
#define ADC_CHANNEL_39              (38)                /*!< single-end channel*/
#define ADC_CHANNEL_40              (39)                /*!< single-end channel*/
#define ADC_CHANNEL_41              (40)                /*!< single-end channel*/
#define ADC_CHANNEL_42              (41)                /*!< single-end channel*/
#define ADC_CHANNEL_43              (42)                /*!< single-end channel*/
#define ADC_CHANNEL_44              (43)                /*!< single-end channel*/
#define ADC_CHANNEL_45              (44)                /*!< single-end channel*/
#define ADC_CHANNEL_46              (45)                /*!< single-end channel*/
#define ADC_CHANNEL_47              (46)                /*!< single-end channel*/
#define ADC_CHANNEL_48              (47)                /*!< single-end channel*/
#define ADC_CHANNEL_49              (48)                /*!< single-end channel*/
#define ADC_CHANNEL_50              (49)                /*!< single-end channel*/
#define ADC_CHANNEL_51              (50)                /*!< single-end channel*/
#define ADC_CHANNEL_52              (51)                /*!< single-end channel*/
#define ADC_CHANNEL_53              (52)                /*!< single-end channel*/
#define ADC_CHANNEL_VBG             (53)                /*!< single-end channel*/
#define ADC_CHANNEL_VTS             (54)                /*!< single-end channel*/
#define ADC_CHANNEL_VBS             (55)                /*!< single-end channel*/
#define ADC_CHANNEL_P2AVDD          (56)                /*!< single-end channel*/
#define ADC_CHANNEL_P3AVDD          (57)                /*!< single-end channel*/
#define ADC_CHANNEL_P4AVDD          (58)                /*!< single-end channel*/
#define ADC_CHANNEL_P5AVDD          (59)                /*!< single-end channel*/
#define ADC_CHANNEL_P6AVDD          (60)                /*!< single-end channel*/
#define ADC_CHANNEL_P7AVDD          (61)                /*!< single-end channel*/
#define ADC_CHANNEL_P8AVDD          (62)                /*!< single-end channel*/
#define ADC_CHANNEL_64              (63)                /*!< reserved */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_InjectionGroup_Index  ADC injection group index
  * @{
  */
#define ADC_INJGRP_1                    (0)                                               /*!< ADC injection group 1 */
#define ADC_INJGRP_2                    (1)                                               /*!< ADC injection group 2 */
#define ADC_INJGRP_3                    (2)                                               /*!< ADC injection group 3 */
#define ADC_INJGRP_4                    (3)                                               /*!< ADC injection group 4 */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_RegularGroup_Index  ADC regular group index
  * @{
  */
#define ADC_REGGRP_1                    (0)                                               /*!< ADC regular group 1 */
#define ADC_REGGRP_2                    (1)                                               /*!< ADC regular group 2 */
#define ADC_REGGRP_3                    (2)                                               /*!< ADC regular group 3 */
#define ADC_REGGRP_4                    (3)                                               /*!< ADC regular group 4 */
#define ADC_REGGRP_5                    (4)                                               /*!< ADC regular group 5 */
#define ADC_REGGRP_6                    (5)                                               /*!< ADC regular group 6 */
#define ADC_REGGRP_7                    (6)                                               /*!< ADC regular group 7 */
#define ADC_REGGRP_8                    (7)                                               /*!< ADC regular group 8 */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_InjectionGroup_Channel_Index  ADC injection group channel index 
  * @{
  */
#define ADC_INJGRP_CHANNEL_1            (0)                                               /*!< ADC injection group channel 1 */
#define ADC_INJGRP_CHANNEL_2            (1)                                               /*!< ADC injection group channel 2 */
#define ADC_INJGRP_CHANNEL_3            (2)                                               /*!< ADC injection group channel 3 */
#define ADC_INJGRP_CHANNEL_4            (3)                                               /*!< ADC injection group channel 4 */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_RegularGroup_Channel_Index  ADC regular group channel index 
  * @{
  */
#define ADC_REGGRP_CHANNEL_1            (0)                                               /*!< ADC regular group channel 1 */
#define ADC_REGGRP_CHANNEL_2            (1)                                               /*!< ADC regular group channel 2 */
#define ADC_REGGRP_CHANNEL_3            (2)                                               /*!< ADC regular group channel 3 */
#define ADC_REGGRP_CHANNEL_4            (3)                                               /*!< ADC regular group channel 4 */
#define ADC_REGGRP_CHANNEL_5            (4)                                               /*!< ADC regular group channel 5 */
#define ADC_REGGRP_CHANNEL_6            (5)                                               /*!< ADC regular group channel 6 */
#define ADC_REGGRP_CHANNEL_7            (6)                                               /*!< ADC regular group channel 7 */
#define ADC_REGGRP_CHANNEL_8            (7)                                               /*!< ADC regular group channel 8 */
#define ADC_REGGRP_CHANNEL_9            (8)                                               /*!< ADC regular group channel 9 */
#define ADC_REGGRP_CHANNEL_10           (9)                                               /*!< ADC regular group channel 10 */
#define ADC_REGGRP_CHANNEL_11           (10)                                              /*!< ADC regular group channel 11 */
#define ADC_REGGRP_CHANNEL_12           (11)                                              /*!< ADC regular group channel 12 */
#define ADC_REGGRP_CHANNEL_13           (12)                                              /*!< ADC regular group channel 13 */
#define ADC_REGGRP_CHANNEL_14           (13)                                              /*!< ADC regular group channel 14 */
#define ADC_REGGRP_CHANNEL_15           (14)                                              /*!< ADC regular group channel 15 */
#define ADC_REGGRP_CHANNEL_16           (15)                                              /*!< ADC regular group channel 16 */
#define ADC_REGGRP_CHANNEL_17           (16)                                              /*!< ADC regular group channel 17 */
#define ADC_REGGRP_CHANNEL_18           (17)                                              /*!< ADC regular group channel 18 */
#define ADC_REGGRP_CHANNEL_19           (18)                                              /*!< ADC regular group channel 19 */
#define ADC_REGGRP_CHANNEL_20           (19)                                              /*!< ADC regular group channel 20 */
#define ADC_REGGRP_CHANNEL_21           (20)                                              /*!< ADC regular group channel 21 */
#define ADC_REGGRP_CHANNEL_22           (21)                                              /*!< ADC regular group channel 22 */
#define ADC_REGGRP_CHANNEL_23           (22)                                              /*!< ADC regular group channel 23 */
#define ADC_REGGRP_CHANNEL_24           (23)                                              /*!< ADC regular group channel 24 */
#define ADC_REGGRP_CHANNEL_25           (24)                                              /*!< ADC regular group channel 25 */
#define ADC_REGGRP_CHANNEL_26           (25)                                              /*!< ADC regular group channel 26 */
#define ADC_REGGRP_CHANNEL_27           (26)                                              /*!< ADC regular group channel 27 */
#define ADC_REGGRP_CHANNEL_28           (27)                                              /*!< ADC regular group channel 28 */
#define ADC_REGGRP_CHANNEL_29           (28)                                              /*!< ADC regular group channel 29 */
#define ADC_REGGRP_CHANNEL_30           (29)                                              /*!< ADC regular group channel 30 */
#define ADC_REGGRP_CHANNEL_31           (30)                                              /*!< ADC regular group channel 31 */
#define ADC_REGGRP_CHANNEL_32           (31)                                              /*!< ADC regular group channel 32 */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Regular_Channel_Map  ADC Regular channel map
  * @{
  */
#define ADC_REGCH_MAP_1                 (0x00000001UL << 0)                               /*!< ADC regular channel 1 */
#define ADC_REGCH_MAP_2                 (0x00000001UL << 1)                               /*!< ADC regular channel 2 */
#define ADC_REGCH_MAP_3                 (0x00000001UL << 2)                               /*!< ADC regular channel 3 */
#define ADC_REGCH_MAP_4                 (0x00000001UL << 3)                               /*!< ADC regular channel 4 */
#define ADC_REGCH_MAP_5                 (0x00000001UL << 4)                               /*!< ADC regular channel 5 */
#define ADC_REGCH_MAP_6                 (0x00000001UL << 5)                               /*!< ADC regular channel 6 */
#define ADC_REGCH_MAP_7                 (0x00000001UL << 6)                               /*!< ADC regular channel 7 */
#define ADC_REGCH_MAP_8                 (0x00000001UL << 7)                               /*!< ADC regular channel 8 */
#define ADC_REGCH_MAP_9                 (0x00000001UL << 8)                               /*!< ADC regular channel 9 */
#define ADC_REGCH_MAP_10                (0x00000001UL << 9)                               /*!< ADC regular channel 10 */
#define ADC_REGCH_MAP_11                (0x00000001UL << 10)                              /*!< ADC regular channel 11 */
#define ADC_REGCH_MAP_12                (0x00000001UL << 11)                              /*!< ADC regular channel 12 */
#define ADC_REGCH_MAP_13                (0x00000001UL << 12)                              /*!< ADC regular channel 13 */
#define ADC_REGCH_MAP_14                (0x00000001UL << 13)                              /*!< ADC regular channel 14 */
#define ADC_REGCH_MAP_15                (0x00000001UL << 14)                              /*!< ADC regular channel 15 */
#define ADC_REGCH_MAP_16                (0x00000001UL << 15)                              /*!< ADC regular channel 16 */
#define ADC_REGCH_MAP_17                (0x00000001UL << 16)                              /*!< ADC regular channel 17 */
#define ADC_REGCH_MAP_18                (0x00000001UL << 17)                              /*!< ADC regular channel 18 */
#define ADC_REGCH_MAP_19                (0x00000001UL << 18)                              /*!< ADC regular channel 19 */
#define ADC_REGCH_MAP_20                (0x00000001UL << 19)                              /*!< ADC regular channel 20 */
#define ADC_REGCH_MAP_21                (0x00000001UL << 20)                              /*!< ADC regular channel 21 */
#define ADC_REGCH_MAP_22                (0x00000001UL << 21)                              /*!< ADC regular channel 22 */
#define ADC_REGCH_MAP_23                (0x00000001UL << 22)                              /*!< ADC regular channel 23 */
#define ADC_REGCH_MAP_24                (0x00000001UL << 23)                              /*!< ADC regular channel 24 */
#define ADC_REGCH_MAP_25                (0x00000001UL << 24)                              /*!< ADC regular channel 25 */
#define ADC_REGCH_MAP_26                (0x00000001UL << 25)                              /*!< ADC regular channel 26 */
#define ADC_REGCH_MAP_27                (0x00000001UL << 26)                              /*!< ADC regular channel 27 */
#define ADC_REGCH_MAP_28                (0x00000001UL << 27)                              /*!< ADC regular channel 28 */
#define ADC_REGCH_MAP_29                (0x00000001UL << 28)                              /*!< ADC regular channel 29 */
#define ADC_REGCH_MAP_30                (0x00000001UL << 29)                              /*!< ADC regular channel 30 */
#define ADC_REGCH_MAP_31                (0x00000001UL << 30)                              /*!< ADC regular channel 31 */
#define ADC_REGCH_MAP_32                (0x00000001UL << 31)                              /*!< ADC regular channel 32 */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_AWD_ID  ADC  channel analog watch dog id
  * @{
  */
#define ADC_AWD_ID_NONE             (0)                                               /*!< ADC injection channel AWD none */
#define ADC_AWD_ID_1                (1)                                               /*!< ADC injection channel AWD id 1 */
#define ADC_AWD_ID_2                (2)                                               /*!< ADC injection channel AWD id 2 */
#define ADC_AWD_ID_3                (3)                                               /*!< ADC injection channel AWD id 3 */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_AWD_Mode  ADC channel analog watch dog monitor mode
  * @{
  */
#define ADC_AWD_MODE_NONE           (0)                                               /*!< ADC AWD none */
#define ADC_AWD_MODE_LOW            (MDU_AWD_CR_CFG_1_0)                              /*!< ADC AWD output when the vaule is less than low threshold */
#define ADC_AWD_MODE_HIGH           (MDU_AWD_CR_CFG_1_1)                              /*!< ADC AWD output when the vaule is in [low threshold, high threshold] */
#define ADC_AWD_MODE_MID            (MDU_AWD_CR_CFG_1_1|MDU_AWD_CR_CFG_1_0)           /*!< ADC AWD output when the vaule is greater than high threshold */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_RegularGroup_ScanMode scan mode for regular group 
  * @{
  */
#define ADC_CONVERT_SINGLESCAN          (0)  
#define ADC_CONVERT_CONTINUOUSSCAN      (MDU_REGGRP_TRGCFG_REGGRP_OPMODE_0)  
#define ADC_CONVERT_DISCONTINUOUSSCAN   (MDU_REGGRP_TRGCFG_REGGRP_OPMODE_1)  
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Group_TriggerMode  ADC trigger edge
  * @{
  */
#define ADC_TRIGGEREDGE_NONE        (0)                                               /*!< ADC no trigger */
#define ADC_TRIGGEREDGE_RISING      (1)                                               /*!< ADC trigger edge rising  */
#define ADC_TRIGGEREDGE_FALLING     (2)                                               /*!< ADC trigger edge falling */
#define ADC_TRIGGEREDGE_BOTH        (3)                                               /*!< ADC trigger edge both */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Group_TriggerSource Source ADC trigger source
  * @{
  */
#define ADC_TRGSRC_NONE             (0)
#define ADC_TRGSRC_TIMA1_CH4        (1)
#define ADC_TRGSRC_TIMA1_TRGO2      (2)
#define ADC_TRGSRC_TIMA2_CH4        (3)
#define ADC_TRGSRC_TIMA2_TRGO2      (4)
#define ADC_TRGSRC_TIMG1_CH4        (5)
#define ADC_TRGSRC_TIMG1_TRGO2      (6)
#define ADC_TRGSRC_TIMG2_CH4        (7)
#define ADC_TRGSRC_TIMG2_TRGO2      (8)
#define ADC_TRGSRC_TIMG3_CH4        (9)
#define ADC_TRGSRC_TIMG3_TRGO2      (10)
#define ADC_TRGSRC_TIMG4_CH4        (11)
#define ADC_TRGSRC_TIMG4_TRGO2      (12)
#define ADC_TRGSRC_EXTERNAL         (13)
#define ADC_TRGSRC_TIMB11           (14)
#define ADC_TRGSRC_SOFTWARE         (15)
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Interrupt_Enable  ADC interrupts enable
  * @{
  */
#define ADC_INT_ENABLE_INJGRP_EOC   (MDU_MDUCFG_INJ_EOC_EN)                           /*!< ADC injection group interrupt EOC enable */
#define ADC_INT_ENABLE_INJGRP_EOS   (MDU_MDUCFG_INJ_EOS_EN)                           /*!< ADC injection group interrupt EOS enable */
#define ADC_INT_ENABLE_REGGRP_EOC   (MDU_MDUCFG_REG_EOC_EN)                           /*!< ADC regular group interrupt EOC enable */
#define ADC_INT_ENABLE_REGGRP_EOS   (MDU_MDUCFG_REG_EOS_EN)                           /*!< ADC regular group interrupt EOS enable */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Interrupt_flag  ADC interrupt flag
  * @{
  */
#define ADC_FLAG_INJ_EOC            (0x00000001UL)	
#define ADC_FLAG_INJ_EOS            (0x00000002UL)	
#define ADC_FLAG_REG_EOC            (0x00000004UL)	
#define ADC_FLAG_REG_EOS            (0x00000008UL)	
#define ADC_FLAG_INJ_AWD            (0x00000010UL)	
#define ADC_FLAG_REG_AWD            (0x00000020UL)	
	
#define ADC_FLAG_INJCH_EOC_1        (MDU_INT_STATUS_EOC_INJ_CH_1)                     /*!< ADC injection Channel 1 EOC flag */
#define ADC_FLAG_INJCH_EOC_2        (MDU_INT_STATUS_EOC_INJ_CH_2)                     /*!< ADC injection Channel 2 EOC flag */
#define ADC_FLAG_INJCH_EOC_3        (MDU_INT_STATUS_EOC_INJ_CH_3)                     /*!< ADC injection Channel 3 EOC flag */
#define ADC_FLAG_INJCH_EOC_4        (MDU_INT_STATUS_EOC_INJ_CH_4)                     /*!< ADC injection Channel 4 EOC flag */
#define ADC_FLAG_INJGRP_EOS         (MDU_INT_STATUS_EOS_INJ)                          /*!< ADC injection group EOS flag */
#define ADC_FLAG_REGGRP_EOS         (MDU_INT_STATUS_EOS_REG)                          /*!< ADC regular group EOC flag */
#define ADC_FLAG_INJCH_AWD_1        (MDU_INT_STATUS_AWD_INJ_CH_1)                     /*!< ADC injection Channel 1 AWD flag */
#define ADC_FLAG_INJCH_AWD_2        (MDU_INT_STATUS_AWD_INJ_CH_2)                     /*!< ADC injection Channel 2 AWD flag */
#define ADC_FLAG_INJCH_AWD_3        (MDU_INT_STATUS_AWD_INJ_CH_3)                     /*!< ADC injection Channel 3 AWD flag */
#define ADC_FLAG_INJCH_AWD_4        (MDU_INT_STATUS_AWD_INJ_CH_4)                     /*!< ADC injection Channel 4 AWD flag */
#define ADC_FLAG_INJCH_OW_1         (MDU_INT_STATUS_OW_INJ_CH_1)                      /*!< ADC injection channel 1 OverWrite flag */
#define ADC_FLAG_INJCH_OW_2         (MDU_INT_STATUS_OW_INJ_CH_2)                      /*!< ADC injection channel 2 OverWrite flag */
#define ADC_FLAG_INJCH_OW_3         (MDU_INT_STATUS_OW_INJ_CH_3)                      /*!< ADC injection channel 3 OverWrite flag */
#define ADC_FLAG_INJCH_OW_4         (MDU_INT_STATUS_OW_INJ_CH_4)                      /*!< ADC injection channel 4 OverWrite flag */
#define ADC_FLAG_INJGRP_OW          (MDU_INT_STATUS_OW_INJ_GRP)                       /*!< ADC injection group OverWrite flag */
#define ADC_FLAG_REGGRP_OW          (MDU_INT_STATUS_OW_REG_GRP)                       /*!< ADC regular group OverWrite flag */

#define ADC_FLAG_REGCH_EOC_1        (0x00000001UL << 0 )                              /*!< ADC regular Channel 1 EOC flag */
#define ADC_FLAG_REGCH_EOC_2        (0x00000001UL << 1 )                              /*!< ADC regular Channel 2 EOC flag */
#define ADC_FLAG_REGCH_EOC_3        (0x00000001UL << 2 )                              /*!< ADC regular Channel 3 EOC flag */
#define ADC_FLAG_REGCH_EOC_4        (0x00000001UL << 3 )                              /*!< ADC regular Channel 4 EOC flag */
#define ADC_FLAG_REGCH_EOC_5        (0x00000001UL << 4 )                              /*!< ADC regular Channel 5 EOC flag */
#define ADC_FLAG_REGCH_EOC_6        (0x00000001UL << 5 )                              /*!< ADC regular Channel 6 EOC flag */
#define ADC_FLAG_REGCH_EOC_7        (0x00000001UL << 6 )                              /*!< ADC regular Channel 7 EOC flag */
#define ADC_FLAG_REGCH_EOC_8        (0x00000001UL << 7 )                              /*!< ADC regular Channel 8 EOC flag */
#define ADC_FLAG_REGCH_EOC_9        (0x00000001UL << 8 )                              /*!< ADC regular Channel 9 EOC flag */
#define ADC_FLAG_REGCH_EOC_10       (0x00000001UL << 9 )                              /*!< ADC regular Channel 10 EOC flag */
#define ADC_FLAG_REGCH_EOC_11       (0x00000001UL << 10)                              /*!< ADC regular Channel 11 EOC flag */
#define ADC_FLAG_REGCH_EOC_12       (0x00000001UL << 11)                              /*!< ADC regular Channel 12 EOC flag */
#define ADC_FLAG_REGCH_EOC_13       (0x00000001UL << 12)                              /*!< ADC regular Channel 13 EOC flag */
#define ADC_FLAG_REGCH_EOC_14       (0x00000001UL << 13)                              /*!< ADC regular Channel 14 EOC flag */
#define ADC_FLAG_REGCH_EOC_15       (0x00000001UL << 14)                              /*!< ADC regular Channel 15 EOC flag */
#define ADC_FLAG_REGCH_EOC_16       (0x00000001UL << 15)                              /*!< ADC regular Channel 16 EOC flag */
#define ADC_FLAG_REGCH_EOC_17       (0x00000001UL << 16)                              /*!< ADC regular Channel 17 EOC flag */
#define ADC_FLAG_REGCH_EOC_18       (0x00000001UL << 17)                              /*!< ADC regular Channel 18 EOC flag */
#define ADC_FLAG_REGCH_EOC_19       (0x00000001UL << 18)                              /*!< ADC regular Channel 19 EOC flag */
#define ADC_FLAG_REGCH_EOC_20       (0x00000001UL << 19)                              /*!< ADC regular Channel 20 EOC flag */
#define ADC_FLAG_REGCH_EOC_21       (0x00000001UL << 20)                              /*!< ADC regular Channel 21 EOC flag */
#define ADC_FLAG_REGCH_EOC_22       (0x00000001UL << 21)                              /*!< ADC regular Channel 22 EOC flag */
#define ADC_FLAG_REGCH_EOC_23       (0x00000001UL << 22)                              /*!< ADC regular Channel 23 EOC flag */
#define ADC_FLAG_REGCH_EOC_24       (0x00000001UL << 23)                              /*!< ADC regular Channel 24 EOC flag */
#define ADC_FLAG_REGCH_EOC_25       (0x00000001UL << 24)                              /*!< ADC regular Channel 25 EOC flag */
#define ADC_FLAG_REGCH_EOC_26       (0x00000001UL << 25)                              /*!< ADC regular Channel 26 EOC flag */
#define ADC_FLAG_REGCH_EOC_27       (0x00000001UL << 26)                              /*!< ADC regular Channel 27 EOC flag */
#define ADC_FLAG_REGCH_EOC_28       (0x00000001UL << 27)                              /*!< ADC regular Channel 28 EOC flag */
#define ADC_FLAG_REGCH_EOC_29       (0x00000001UL << 28)                              /*!< ADC regular Channel 29 EOC flag */
#define ADC_FLAG_REGCH_EOC_30       (0x00000001UL << 29)                              /*!< ADC regular Channel 30 EOC flag */
#define ADC_FLAG_REGCH_EOC_31       (0x00000001UL << 30)                              /*!< ADC regular Channel 31 EOC flag */
#define ADC_FLAG_REGCH_EOC_32       (0x00000001UL << 31)                              /*!< ADC regular Channel 32 EOC flag */

#define ADC_FLAG_REGCH_OW_1         (0x00000001UL << 0 )                              /*!< ADC regular Channel 1 OverWrite flag */
#define ADC_FLAG_REGCH_OW_2         (0x00000001UL << 1 )                              /*!< ADC regular Channel 2 OverWrite flag */
#define ADC_FLAG_REGCH_OW_3         (0x00000001UL << 2 )                              /*!< ADC regular Channel 3 OverWrite flag */
#define ADC_FLAG_REGCH_OW_4         (0x00000001UL << 3 )                              /*!< ADC regular Channel 4 OverWrite flag */
#define ADC_FLAG_REGCH_OW_5         (0x00000001UL << 4 )                              /*!< ADC regular Channel 5 OverWrite flag */
#define ADC_FLAG_REGCH_OW_6         (0x00000001UL << 5 )                              /*!< ADC regular Channel 6 OverWrite flag */
#define ADC_FLAG_REGCH_OW_7         (0x00000001UL << 6 )                              /*!< ADC regular Channel 7 OverWrite flag */
#define ADC_FLAG_REGCH_OW_8         (0x00000001UL << 7 )                              /*!< ADC regular Channel 8 OverWrite flag */
#define ADC_FLAG_REGCH_OW_9         (0x00000001UL << 8 )                              /*!< ADC regular Channel 9 OverWrite flag */
#define ADC_FLAG_REGCH_OW_10        (0x00000001UL << 9 )                              /*!< ADC regular Channel 10 OverWrite flag */
#define ADC_FLAG_REGCH_OW_11        (0x00000001UL << 10)                              /*!< ADC regular Channel 11 OverWrite flag */
#define ADC_FLAG_REGCH_OW_12        (0x00000001UL << 11)                              /*!< ADC regular Channel 12 OverWrite flag */
#define ADC_FLAG_REGCH_OW_13        (0x00000001UL << 12)                              /*!< ADC regular Channel 13 OverWrite flag */
#define ADC_FLAG_REGCH_OW_14        (0x00000001UL << 13)                              /*!< ADC regular Channel 14 OverWrite flag */
#define ADC_FLAG_REGCH_OW_15        (0x00000001UL << 14)                              /*!< ADC regular Channel 15 OverWrite flag */
#define ADC_FLAG_REGCH_OW_16        (0x00000001UL << 15)                              /*!< ADC regular Channel 16 OverWrite flag */
#define ADC_FLAG_REGCH_OW_17        (0x00000001UL << 16)                              /*!< ADC regular Channel 17 OverWrite flag */
#define ADC_FLAG_REGCH_OW_18        (0x00000001UL << 17)                              /*!< ADC regular Channel 18 OverWrite flag */
#define ADC_FLAG_REGCH_OW_19        (0x00000001UL << 18)                              /*!< ADC regular Channel 19 OverWrite flag */
#define ADC_FLAG_REGCH_OW_20        (0x00000001UL << 19)                              /*!< ADC regular Channel 20 OverWrite flag */
#define ADC_FLAG_REGCH_OW_21        (0x00000001UL << 20)                              /*!< ADC regular Channel 21 OverWrite flag */
#define ADC_FLAG_REGCH_OW_22        (0x00000001UL << 21)                              /*!< ADC regular Channel 22 OverWrite flag */
#define ADC_FLAG_REGCH_OW_23        (0x00000001UL << 22)                              /*!< ADC regular Channel 23 OverWrite flag */
#define ADC_FLAG_REGCH_OW_24        (0x00000001UL << 23)                              /*!< ADC regular Channel 24 OverWrite flag */
#define ADC_FLAG_REGCH_OW_25        (0x00000001UL << 24)                              /*!< ADC regular Channel 25 OverWrite flag */
#define ADC_FLAG_REGCH_OW_26        (0x00000001UL << 25)                              /*!< ADC regular Channel 26 OverWrite flag */
#define ADC_FLAG_REGCH_OW_27        (0x00000001UL << 26)                              /*!< ADC regular Channel 27 OverWrite flag */
#define ADC_FLAG_REGCH_OW_28        (0x00000001UL << 27)                              /*!< ADC regular Channel 28 OverWrite flag */
#define ADC_FLAG_REGCH_OW_29        (0x00000001UL << 28)                              /*!< ADC regular Channel 29 OverWrite flag */
#define ADC_FLAG_REGCH_OW_30        (0x00000001UL << 29)                              /*!< ADC regular Channel 30 OverWrite flag */
#define ADC_FLAG_REGCH_OW_31        (0x00000001UL << 30)                              /*!< ADC regular Channel 31 OverWrite flag */
#define ADC_FLAG_REGCH_OW_32        (0x00000001UL << 31)                              /*!< ADC regular Channel 32 OverWrite flag */

#define ADC_FLAG_REGCH_AWD_1        (MDU_INT_STATUS_AWD_REG_CH_0)                     /*!< ADC regular Channel 1 AWD flag */
#define ADC_FLAG_REGCH_AWD_2        (MDU_INT_STATUS_AWD_REG_CH_1)                     /*!< ADC regular Channel 2 AWD flag */
#define ADC_FLAG_REGCH_AWD_3        (MDU_INT_STATUS_AWD_REG_CH_2)                     /*!< ADC regular Channel 3 AWD flag */
#define ADC_FLAG_REGCH_AWD_4        (MDU_INT_STATUS_AWD_REG_CH_3)                     /*!< ADC regular Channel 4 AWD flag */
#define ADC_FLAG_REGCH_AWD_5        (MDU_INT_STATUS_AWD_REG_CH_4)                     /*!< ADC regular Channel 5 AWD flag */
#define ADC_FLAG_REGCH_AWD_6        (MDU_INT_STATUS_AWD_REG_CH_5)                     /*!< ADC regular Channel 6 AWD flag */
#define ADC_FLAG_REGCH_AWD_7        (MDU_INT_STATUS_AWD_REG_CH_6)                     /*!< ADC regular Channel 7 AWD flag */
#define ADC_FLAG_REGCH_AWD_8        (MDU_INT_STATUS_AWD_REG_CH_7)                     /*!< ADC regular Channel 8 AWD flag */
#define ADC_FLAG_REGCH_AWD_9        (MDU_INT_STATUS_AWD_REG_CH_8)                     /*!< ADC regular Channel 9 AWD flag */
#define ADC_FLAG_REGCH_AWD_10       (MDU_INT_STATUS_AWD_REG_CH_9)                     /*!< ADC regular Channel 10 AWD flag */
#define ADC_FLAG_REGCH_AWD_11       (MDU_INT_STATUS_AWD_REG_CH_10)                    /*!< ADC regular Channel 11 AWD flag */
#define ADC_FLAG_REGCH_AWD_12       (MDU_INT_STATUS_AWD_REG_CH_11)                    /*!< ADC regular Channel 12 AWD flag */
#define ADC_FLAG_REGCH_AWD_13       (MDU_INT_STATUS_AWD_REG_CH_12)                    /*!< ADC regular Channel 13 AWD flag */
#define ADC_FLAG_REGCH_AWD_14       (MDU_INT_STATUS_AWD_REG_CH_13)                    /*!< ADC regular Channel 14 AWD flag */
#define ADC_FLAG_REGCH_AWD_15       (MDU_INT_STATUS_AWD_REG_CH_14)                    /*!< ADC regular Channel 15 AWD flag */
#define ADC_FLAG_REGCH_AWD_16       (MDU_INT_STATUS_AWD_REG_CH_15)                    /*!< ADC regular Channel 16 AWD flag */
#define ADC_FLAG_REGCH_AWD_17       (MDU_INT_STATUS_AWD_REG_CH_16)                    /*!< ADC regular Channel 17 AWD flag */
#define ADC_FLAG_REGCH_AWD_18       (MDU_INT_STATUS_AWD_REG_CH_17)                    /*!< ADC regular Channel 18 AWD flag */
#define ADC_FLAG_REGCH_AWD_19       (MDU_INT_STATUS_AWD_REG_CH_18)                    /*!< ADC regular Channel 19 AWD flag */
#define ADC_FLAG_REGCH_AWD_20       (MDU_INT_STATUS_AWD_REG_CH_19)                    /*!< ADC regular Channel 20 AWD flag */
#define ADC_FLAG_REGCH_AWD_21       (MDU_INT_STATUS_AWD_REG_CH_20)                    /*!< ADC regular Channel 21 AWD flag */
#define ADC_FLAG_REGCH_AWD_22       (MDU_INT_STATUS_AWD_REG_CH_21)                    /*!< ADC regular Channel 22 AWD flag */
#define ADC_FLAG_REGCH_AWD_23       (MDU_INT_STATUS_AWD_REG_CH_22)                    /*!< ADC regular Channel 23 AWD flag */
#define ADC_FLAG_REGCH_AWD_24       (MDU_INT_STATUS_AWD_REG_CH_23)                    /*!< ADC regular Channel 24 AWD flag */
#define ADC_FLAG_REGCH_AWD_25       (MDU_INT_STATUS_AWD_REG_CH_24)                    /*!< ADC regular Channel 25 AWD flag */
#define ADC_FLAG_REGCH_AWD_26       (MDU_INT_STATUS_AWD_REG_CH_25)                    /*!< ADC regular Channel 26 AWD flag */
#define ADC_FLAG_REGCH_AWD_27       (MDU_INT_STATUS_AWD_REG_CH_26)                    /*!< ADC regular Channel 27 AWD flag */
#define ADC_FLAG_REGCH_AWD_28       (MDU_INT_STATUS_AWD_REG_CH_27)                    /*!< ADC regular Channel 28 AWD flag */
#define ADC_FLAG_REGCH_AWD_29       (MDU_INT_STATUS_AWD_REG_CH_28)                    /*!< ADC regular Channel 29 AWD flag */
#define ADC_FLAG_REGCH_AWD_30       (MDU_INT_STATUS_AWD_REG_CH_29)                    /*!< ADC regular Channel 30 AWD flag */
#define ADC_FLAG_REGCH_AWD_31       (MDU_INT_STATUS_AWD_REG_CH_30)                    /*!< ADC regular Channel 31 AWD flag */
#define ADC_FLAG_REGCH_AWD_32       (MDU_INT_STATUS_AWD_REG_CH_31)                    /*!< ADC regular Channel 32 AWD flag */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Interrupt_Polarity  ADC interrupt polarity
  * @{
  */
#define ADC_INT_POLARITY_HIGH       (0)                                               /*!< ADC interrupt high level */
#define ADC_INT_POLARITY_LOW        (1)                                               /*!< ADC interrupt low level */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_PGA_PRESAMPLING_MODE  ADC PGA pre-dampling Mode
  * @{
  */
#define ADC_PRESAMPLING_MODE_SAME       (0)                                           /*!< use same pre-sample cycle numbers from MDU_CFG */
#define ADC_PRESAMPLING_MODE_DEDICATED  (MDU_MDUCFG_SEL_PGA_CTRL)                     /*!< use dedicated pre-sample cycle numbers in inj_group_define_x */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_DISCHARGE_MODE  ADC discharge Mode
  * @{
  */
#define ADC_DISCHARGE_MODE_DISABLE   (0)                                           /*!< discharge disable */
#define ADC_DISCHARGE_MODE_ENABLE    (MDU_MDUCFG_DSCH_EN)                          /*!< discharge enable */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Regular_Enable  ADC regular group enable
  * @{
  */
#define ADC_REGGRP_DISABLE       (0)                                              /*!< ADC regular group disable */
#define ADC_REGGRP_ENABLE        (MDU_MDUCFG_REG_GRP_EN)                          /*!< ADC regular group enable */
/** 
  * @}
  */
/** @defgroup ADC_HAL_EC_Injection_Enable  ADC injection group enable
  * @{
  */
#define ADC_INJGRP_DISABLE       (0)                                              /*!< ADC injection group disable */
#define ADC_INJGRP_ENABLE        (MDU_MDUCFG_INJ_GRP_EN)                          /*!< ADC injection group enable */
/** 
  * @}
  */

/** @defgroup ADC_HAL_EC_Regular_DMA_HS_Enable  ADC regular group DMA handshaking enable
  * @{
  */
#define ADC_REGGRP_DMA_DISABLE       (0)                                              /*!< ADC regular group DMA disable */
#define ADC_REGGRP_DMA_ENABLE        (MDU_ADCDMACFG_REG_DMA_EN)                       /*!< ADC regular group DMA enable */
/** 
  * @}
  */
	
/** @defgroup ADC_HAL_EC_Injection_DMA_HS_Enable  ADC injection group DMA handshaking enable
  * @{
  */
#define ADC_INJGRP_DMA_DISABLE       (0)                                              /*!< ADC injection group DMA disable */
#define ADC_INJGRP_DMA_ENABLE        (MDU_ADCDMACFG_INJ_DMA_EN)                       /*!< ADC injection group DMA enable */
/** 
  * @}
  */

/** @defgroup ADC_HAL_EC_OUTPUT_ALIGNMENT ADC output alignment
  * @{
  */
#define ADC_OUTPUT_AGLIN_LSB         (0)                                              /*!< ADC output alignment LSB */
#define ADC_OUTPUT_AGLIN_MSB         (MDU_ADCCFG_ADCOUTALIGN)                         /*!< ADC output alignment MSB */
/** 
  * @}
  */

/** @defgroup ADC_HAL_EC_RESOLUTION ADC conversion resolution
  * @{
  */
#define ADC_RESOLUTION_8B              (0)
#define ADC_RESOLUTION_10B             (MDU_ADCCFG_ADCDATAW_0)
#define ADC_RESOLUTION_12B             (MDU_ADCCFG_ADCDATAW_1)
/** 
  * @}
  */

/** @defgroup ADC_HAL_EC_CONTROL_MODE ADC control mode
  * @{
  */
#define ADC_CONTROL_MODE_MANUAL        (0)                                             /*!< ADC manual mode */
#define ADC_CONTROL_MODE_AUTO          (MDU_ADCCFG_ADCC_EN)                            /*!< ADC auto mode */
/** 
  * @}
  */

/** @defgroup ADC_HAL_EC_MANU_SAMPLEPULSE_ENABLE ADC PFA sample pulse enable for manual mode
  * @{
  */
#define ADC_MANU_SAMPLE_PULSE_DISABLE (0)                                              /*!< ADC PGA sample pulse disable */
#define ADC_MANU_SAMPLE_PULSE_ENABLE  (MDU_ADCCFG_MSAMPEN)                             /*!< ADC PGA sample pulse enable */
/** 
  * @}
  */

/** @defgroup ADC_HAL_EC_MANU_CONV_MODE ADC conversion mode for manual mode
  * @{
  */
#define ADC_MANU_CONV_MODE_CONTINUOUS  (0)                                             /*!< ADC manual conversion mode - continuous conversion */
#define ADC_MANU_CONV_MODE_SINGLE      (MDU_ADCCFG_MCONVMODE)                          /*!< ADC manual conversion mode - single conversion */
/** 
  * @}
  */

/** @defgroup ADC_HAL_EC_MANU_CHANNEL ADC channel for manual mode
  * @{
  */
#define ADC_MANU_CHANNEL_0             (0)                                             /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_1             (MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_2             (MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_3             (MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_4             (MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_5             (MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_6             (MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_7             (MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_8             (MDU_ADCCFG_MCHSLCT_3)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_9             (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_10            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_11            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_12            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_13            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_14            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_15            (MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_16            (MDU_ADCCFG_MCHSLCT_4)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_17            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_18            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_19            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_20            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_21            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_22            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_23            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_24            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_25            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_26            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_27            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_28            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_29            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_30            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_31            (MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_32            (MDU_ADCCFG_MCHSLCT_5)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_33            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_34            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_35            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_36            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_37            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_38            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_39            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_40            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_41            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_42            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_43            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_44            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_45            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_46            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_47            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_48            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_49            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_50            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_51            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_52            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_53            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_54            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_55            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_56            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_57            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_58            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_59            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_60            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_61            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_62            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1)                          /*!< ADC manual channel */
#define ADC_MANU_CHANNEL_63            (MDU_ADCCFG_MCHSLCT_5 | MDU_ADCCFG_MCHSLCT_4 | MDU_ADCCFG_MCHSLCT_3 | MDU_ADCCFG_MCHSLCT_2 | MDU_ADCCFG_MCHSLCT_1 | MDU_ADCCFG_MCHSLCT_0)                          /*!< ADC manual channel */

/** 
  * @}
  */

#else
/** @defgroup ADC_HAL_EC_RESOLUTION  Adc resolution 
  * @{
  */
#if defined(XT32H0xxAMPW)
#define ADC_RESOLUTION_8B              (0)
#define ADC_RESOLUTION_10B             (MDU_ADCCFG_RESCFG_0)
#define ADC_RESOLUTION_12B             (MDU_ADCCFG_RESCFG_1)
#endif
/**
  * @}
  */


/** @defgroup ADC_HAL_EC_SOURCE  Adc source 
  * @{
  */
#define ADC_CHANNEL_0                  (0)  
#define ADC_CHANNEL_1                  (MDU_ADCCFG_CHSLCT_0)  
#define ADC_CHANNEL_2                  (MDU_ADCCFG_CHSLCT_1)  
#define ADC_CHANNEL_3                  (MDU_ADCCFG_CHSLCT_1 | MDU_ADCCFG_CHSLCT_0)  
#define ADC_CHANNEL_4                  (MDU_ADCCFG_CHSLCT_2)  
#define ADC_CHANNEL_5                  (MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_0)  
#define ADC_CHANNEL_6                  (MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_1)  
#define ADC_CHANNEL_7                  (MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_1 | MDU_ADCCFG_CHSLCT_0)  
#define ADC_CHANNEL_8                  (MDU_ADCCFG_CHSLCT_3)  
#define ADC_CHANNEL_9                  (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_0)  
#define ADC_CHANNEL_10                 (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_1)  
#define ADC_CHANNEL_11                 (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_1 | MDU_ADCCFG_CHSLCT_0)  
#define ADC_CHANNEL_12                 (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_2)  
#define ADC_CHANNEL_13                 (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_0)  
#define ADC_CHANNEL_14                 (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_1)  
#define ADC_CHANNEL_15                 (MDU_ADCCFG_CHSLCT_3 | MDU_ADCCFG_CHSLCT_2 | MDU_ADCCFG_CHSLCT_1 | MDU_ADCCFG_CHSLCT_0) 

#define ADC_CHANNEL_EXT                (0) 
#define ADC_CHANNEL_INT                (MDU_ADCCFG_ICHSLCT_0) 
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Trigger_Source source  Adc trigger source 
  * @{
  */
#define ADC_TRGSRC_SOFTWARE            (0)
#define ADC_TRGSRC_TIMA_CH4            (MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMA_TRGO2          (MDU_ADCCTRL_TRGISRC_1)
#define ADC_TRGSRC_TIMA_TRGO           (MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
#if defined(XT32H0xxB)
#define ADC_TRGSRC_TIMG_CH4            (MDU_ADCCTRL_TRGISRC_2)
#define ADC_TRGSRC_TIMG_TRGO           (MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMG_TRGO2          (MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_1)
#define ADC_TRGSRC_GPC24               (MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
#endif /* XT32H0xxB */
#define ADC_TRGSRC_TIMB11              (MDU_ADCCTRL_TRGISRC_3)
#define ADC_TRGSRC_TIMB12              (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMB13              (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_1)
#define ADC_TRGSRC_TIMB14              (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMB21              (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2)
#define ADC_TRGSRC_TIMB22              (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_0)
#define ADC_TRGSRC_TIMB23              (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_1)
#define ADC_TRGSRC_TIMB24              (MDU_ADCCTRL_TRGISRC_3 | MDU_ADCCTRL_TRGISRC_2 | MDU_ADCCTRL_TRGISRC_1 | MDU_ADCCTRL_TRGISRC_0)
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_conversion_mode mode 
  * @{
  */
#define ADC_CONVERT_SINGLECH_SINGLE        (0)  
#define ADC_CONVERT_SINGLECH_CONTINUOUS    (MDU_ADCCTRL_CONV_MODE_0)  
#define ADC_CONVERT_MULTCH_SINGLE          (MDU_ADCCTRL_CONV_MODE_1)  
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_SEQ_conversion_direct sequence 
  * @{
  */
#define ADC_CONVERT_INCREMENT              (0)  
#define ADC_CONVERT_DECREMENT              (MDU_ADCCTRL_CH_MODE)  
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_TRIGGER_MODE  ADC trigger edge
  * @{
  */
#define ADC_TRIGGEREDGE_NONE               (0)                                                /*!< ADC trigger edge none    */
#define ADC_TRIGGEREDGE_RISING             (MDU_ADCCTRL_RISEEDGE)                             /*!< ADC trigger edge rising  */
#define ADC_TRIGGEREDGE_FALLING            (MDU_ADCCTRL_FALLEDGE)                             /*!< ADC trigger edge falling */
#define ADC_TRIGGEREDGE_BOTH               (MDU_ADCCTRL_RISEEDGE | MDU_ADCCTRL_FALLEDGE)      /*!< ADC trigger edge both    */
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_conversion sequence command
  * @{
  */
#define ADC_SEQCONV_IDLE                   (0)  
#define ADC_SEQCONV_START                  (MDU_ADCCTRL_SEQ_STRT)  
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_conversion sequence enable
  * @{
  */
#define ADC_SEQCONV_DISABLE                (0)  
#define ADC_SEQCONV_ENABLE                 (MDU_ADCCTRL_ENABLE)  
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_conversion sequence reset
  * @{
  */
#define ADC_SEQCONV_RESET                  (0)  
#define ADC_SEQCONV_NORMAL                 (MDU_ADCCTRL_RST)  
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_conversion_sampling_width sequence 
  * @{
  */
#define ADC_SEQCONV_PGA_1_CYCLE        (MDU_ADCCTRL_PGASMPW_0)  
#define ADC_SEQCONV_PGA_2_CYCLE        (MDU_ADCCTRL_PGASMPW_1)  
#define ADC_SEQCONV_PGA_3_CYCLE        (MDU_ADCCTRL_PGASMPW_1 | MDU_ADCCTRL_PGASMPW_0)  
#define ADC_SEQCONV_PGA_4_CYCLE        (MDU_ADCCTRL_PGASMPW_2)  
#define ADC_SEQCONV_PGA_5_CYCLE        (MDU_ADCCTRL_PGASMPW_2 | MDU_ADCCTRL_PGASMPW_0)  
#define ADC_SEQCONV_PGA_6_CYCLE        (MDU_ADCCTRL_PGASMPW_2 | MDU_ADCCTRL_PGASMPW_1)  
#define ADC_SEQCONV_PGA_7_CYCLE        (MDU_ADCCTRL_PGASMPW_2 | MDU_ADCCTRL_PGASMPW_1 | MDU_ADCCTRL_PGASMPW_0)  
#define ADC_SEQCONV_PGA_8_CYCLE        (MDU_ADCCTRL_PGASMPW_3)  
#define ADC_SEQCONV_PGA_9_CYCLE        (MDU_ADCCTRL_PGASMPW_3 | MDU_ADCCTRL_PGASMPW_0)  
#define ADC_SEQCONV_PGA_10_CYCLE       (MDU_ADCCTRL_PGASMPW_3 | MDU_ADCCTRL_PGASMPW_1)  
#define ADC_SEQCONV_PGA_11_CYCLE       (MDU_ADCCTRL_PGASMPW_3 | MDU_ADCCTRL_PGASMPW_1 | MDU_ADCCTRL_PGASMPW_0)  
#define ADC_SEQCONV_PGA_12_CYCLE       (MDU_ADCCTRL_PGASMPW_3 | MDU_ADCCTRL_PGASMPW_2)  
#define ADC_SEQCONV_PGA_13_CYCLE       (MDU_ADCCTRL_PGASMPW_3 | MDU_ADCCTRL_PGASMPW_2 | MDU_ADCCTRL_PGASMPW_0)  
#define ADC_SEQCONV_PGA_14_CYCLE       (MDU_ADCCTRL_PGASMPW_3 | MDU_ADCCTRL_PGASMPW_2 | MDU_ADCCTRL_PGASMPW_1)  
#define ADC_SEQCONV_PGA_15_CYCLE       (MDU_ADCCTRL_PGASMPW_3 | MDU_ADCCTRL_PGASMPW_2 | MDU_ADCCTRL_PGASMPW_1 | MDU_ADCCTRL_PGASMPW_0)  
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_SEQ_conversion_group sequence 
  * @{
  */
#define ADC_GROUP_CH_0                 (MDU_ADCCTRL_GCHIND_0)
#define ADC_GROUP_CH_1                 (MDU_ADCCTRL_GCHIND_1)
#define ADC_GROUP_CH_2                 (MDU_ADCCTRL_GCHIND_2)
#define ADC_GROUP_CH_3                 (MDU_ADCCTRL_GCHIND_3)
#define ADC_GROUP_CH_4                 (MDU_ADCCTRL_GCHIND_4)
#define ADC_GROUP_CH_5                 (MDU_ADCCTRL_GCHIND_5)
#define ADC_GROUP_CH_6                 (MDU_ADCCTRL_GCHIND_6)
#define ADC_GROUP_CH_7                 (MDU_ADCCTRL_GCHIND_7)
#define ADC_GROUP_CH_8                 (MDU_ADCCTRL_GCHIND_8)
#define ADC_GROUP_CH_9                 (MDU_ADCCTRL_GCHIND_9)
#define ADC_GROUP_CH_10                (MDU_ADCCTRL_GCHIND_10)
#define ADC_GROUP_CH_11                (MDU_ADCCTRL_GCHIND_11)
#define ADC_GROUP_CH_12                (MDU_ADCCTRL_GCHIND_12)
#define ADC_GROUP_CH_13                (MDU_ADCCTRL_GCHIND_13)
#define ADC_GROUP_CH_14                (MDU_ADCCTRL_GCHIND_14)
#define ADC_GROUP_CH_15                (MDU_ADCCTRL_GCHIND_15)
/**
  * @}
  */

/** @defgroup ADC_HAL_EC_Flag  ADC flag in status 
  * @{
  */
#define ADC_FLAG_EOC                   (MDU_ADCST_EOC)
#define ADC_FLAG_EOS                   (MDU_ADCST_EOS)
/**
  * @}
  */
#endif /* XT32H0xxB */
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup ADC_Private_Macros ADC Private Macros
  * @{
  */
#if defined(XT32H0xxB)
#define IS_ADC_CHANNEL(CHANNEL) (((CHANNEL) == ADC_CHANNEL_1)           || \
                                 ((CHANNEL) == ADC_CHANNEL_2)           || \
                                 ((CHANNEL) == ADC_CHANNEL_3)           || \
                                 ((CHANNEL) == ADC_CHANNEL_4)           || \
                                 ((CHANNEL) == ADC_CHANNEL_5)           || \
                                 ((CHANNEL) == ADC_CHANNEL_6)           || \
                                 ((CHANNEL) == ADC_CHANNEL_7)           || \
                                 ((CHANNEL) == ADC_CHANNEL_8)           || \
                                 ((CHANNEL) == ADC_CHANNEL_9)           || \
                                 ((CHANNEL) == ADC_CHANNEL_10)          || \
                                 ((CHANNEL) == ADC_CHANNEL_11)          || \
                                 ((CHANNEL) == ADC_CHANNEL_12)          || \
                                 ((CHANNEL) == ADC_CHANNEL_13)          || \
                                 ((CHANNEL) == ADC_CHANNEL_14)          || \
                                 ((CHANNEL) == ADC_CHANNEL_15)          || \
                                 ((CHANNEL) == ADC_CHANNEL_16)          || \
                                 ((CHANNEL) == ADC_CHANNEL_17)          || \
                                 ((CHANNEL) == ADC_CHANNEL_18)          || \
                                 ((CHANNEL) == ADC_CHANNEL_19)          || \
                                 ((CHANNEL) == ADC_CHANNEL_20)          || \
                                 ((CHANNEL) == ADC_CHANNEL_21)          || \
                                 ((CHANNEL) == ADC_CHANNEL_22)          || \
                                 ((CHANNEL) == ADC_CHANNEL_23)          || \
                                 ((CHANNEL) == ADC_CHANNEL_24)          || \
                                 ((CHANNEL) == ADC_CHANNEL_25)          || \
                                 ((CHANNEL) == ADC_CHANNEL_26)          || \
                                 ((CHANNEL) == ADC_CHANNEL_27)          || \
                                 ((CHANNEL) == ADC_CHANNEL_28)          || \
                                 ((CHANNEL) == ADC_CHANNEL_29)          || \
                                 ((CHANNEL) == ADC_CHANNEL_30)          || \
                                 ((CHANNEL) == ADC_CHANNEL_31)          || \
                                 ((CHANNEL) == ADC_CHANNEL_32)          || \
                                 ((CHANNEL) == ADC_CHANNEL_33)          || \
                                 ((CHANNEL) == ADC_CHANNEL_34)          || \
                                 ((CHANNEL) == ADC_CHANNEL_35)          || \
                                 ((CHANNEL) == ADC_CHANNEL_36)          || \
                                 ((CHANNEL) == ADC_CHANNEL_37)          || \
                                 ((CHANNEL) == ADC_CHANNEL_38)          || \
                                 ((CHANNEL) == ADC_CHANNEL_39)          || \
                                 ((CHANNEL) == ADC_CHANNEL_40)          || \
                                 ((CHANNEL) == ADC_CHANNEL_41)          || \
                                 ((CHANNEL) == ADC_CHANNEL_42)          || \
                                 ((CHANNEL) == ADC_CHANNEL_43)          || \
                                 ((CHANNEL) == ADC_CHANNEL_44)          || \
                                 ((CHANNEL) == ADC_CHANNEL_45)          || \
                                 ((CHANNEL) == ADC_CHANNEL_46)          || \
                                 ((CHANNEL) == ADC_CHANNEL_47)          || \
                                 ((CHANNEL) == ADC_CHANNEL_48)          || \
                                 ((CHANNEL) == ADC_CHANNEL_49)          || \
                                 ((CHANNEL) == ADC_CHANNEL_50)          || \
                                 ((CHANNEL) == ADC_CHANNEL_51)          || \
                                 ((CHANNEL) == ADC_CHANNEL_52)          || \
                                 ((CHANNEL) == ADC_CHANNEL_53)           || \
                                 ((CHANNEL) == ADC_CHANNEL_VBG)         || \
                                 ((CHANNEL) == ADC_CHANNEL_VTS)         || \
                                 ((CHANNEL) == ADC_CHANNEL_VBS)         || \
                                 ((CHANNEL) == ADC_CHANNEL_P2AVDD)      || \
                                 ((CHANNEL) == ADC_CHANNEL_P3AVDD)      || \
                                 ((CHANNEL) == ADC_CHANNEL_P4AVDD)      || \
                                 ((CHANNEL) == ADC_CHANNEL_P5AVDD)      || \
                                 ((CHANNEL) == ADC_CHANNEL_P6AVDD)      || \
                                 ((CHANNEL) == ADC_CHANNEL_P7AVDD)      || \
                                 ((CHANNEL) == ADC_CHANNEL_P8AVDD)      || \
                                 ((CHANNEL) == ADC_CHANNEL_64))

#define IS_ADC_TRGSOURCE(SOURCE) (((SOURCE) ==  ADC_TRGSRC_NONE        ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMA1_CH4   ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMA1_TRGO2 ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMA2_CH4   ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMA2_TRGO2 ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG1_CH4   ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG1_TRGO2 ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG2_CH4   ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG2_TRGO2 ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG3_CH4   ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG3_TRGO2 ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG4_CH4   ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG4_TRGO2 ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_EXTERNAL    ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_SOFTWARE    ))

#define IS_ADC_TRGMODE(MODE) (((MODE) ==  ADC_TRIGGEREDGE_NONE    ) || \
                              ((MODE) ==  ADC_TRIGGEREDGE_RISING  ) || \
                              ((MODE) ==  ADC_TRIGGEREDGE_FALLING ) || \
                              ((MODE) ==  ADC_TRIGGEREDGE_BOTH    ))

#define IS_ADC_MODE(MODE) (((MODE) == ADC_CONVERT_SINGLESCAN       ) ||\
                           ((MODE) == ADC_CONVERT_CONTINUOUSSCAN   ) ||\
                           ((MODE) == ADC_CONVERT_DISCONTINUOUSSCAN) )

#else
#define IS_ADC_MODE(MODE) (((MODE) == ADC_CONVERT_SINGLECH_SINGLE)     ||\
                           ((MODE) == ADC_CONVERT_SINGLECH_CONTINUOUS) ||\
                           ((MODE) == ADC_CONVERT_MULTCH_SINGLE      ) )

#define IS_ADC_GROUP(GROUP) (((GROUP) & ADC_GROUP_CH_0)           || \
                             ((GROUP) & ADC_GROUP_CH_1)           || \
                             ((GROUP) & ADC_GROUP_CH_2)           || \
                             ((GROUP) & ADC_GROUP_CH_3)           || \
                             ((GROUP) & ADC_GROUP_CH_4)           || \
                             ((GROUP) & ADC_GROUP_CH_5)           || \
                             ((GROUP) & ADC_GROUP_CH_6)           || \
                             ((GROUP) & ADC_GROUP_CH_7)           || \
                             ((GROUP) & ADC_GROUP_CH_8)           || \
                             ((GROUP) & ADC_GROUP_CH_9)           || \
                             ((GROUP) & ADC_GROUP_CH_10)          || \
                             ((GROUP) & ADC_GROUP_CH_11)          || \
                             ((GROUP) & ADC_GROUP_CH_12)          || \
                             ((GROUP) & ADC_GROUP_CH_13)          || \
                             ((GROUP) & ADC_GROUP_CH_14)          || \
                             ((GROUP) & ADC_GROUP_CH_15)           )

#define IS_ADC_GROUPDIRTECT(DIRECT) (((DIRECT) == ADC_CONVERT_INCREMENT) || \
                                     ((DIRECT) == ADC_CONVERT_DECREMENT))  

#define IS_ADC_TRGSOURCE(SOURCE) (((SOURCE) == ADC_TRGSRC_SOFTWARE) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMA_CH4  ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMA_TRGO2) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMG_TRGO ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMB11    ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMB12    ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMB13    ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMB14    ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMB21    ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMB22    ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMB23    ) || \
                                  ((SOURCE) ==  ADC_TRGSRC_TIMB24    ))

#define IS_ADC_TRGMODE(MODE) (((MODE) == ADC_TRIGGEREDGE_NONE)      || \
                              ((MODE) ==  ADC_TRIGGEREDGE_RISING)   || \
                              ((MODE) ==  ADC_TRIGGEREDGE_FALLING)    || \
                              ((MODE) ==  ADC_TRIGGEREDGE_BOTH ))

/**
  * @brief Test if conversion trigger of regular group is software start
  *        or external trigger.
  * @param __HANDLE__ ADC handle
  * @retval SET (software start) or RESET (external trigger)
  */
#define ADC_IS_SOFTWARE_START_REGULAR(__HANDLE__)                              \
  (((__HANDLE__)->Instance->ADC_CFG & MDU_ADCCFG_STRT) ? SET : RESET)

/**
  * @brief Return resolution bits in CFGR1 register RES[1:0] field.
  * @param __HANDLE__ ADC handle
  * @retval Value of bitfield RES in CFGR1 register.
  */
#define ADC_GET_RESOLUTION(__HANDLE__)                                         \
  (READ_REG((__HANDLE__)->Instance->ADC_RESULTS))


#define IS_ADC_CHANNEL(CHANNEL) (((CHANNEL) == ADC_CHANNEL_0)           || \
                                 ((CHANNEL) == ADC_CHANNEL_1)           || \
                                 ((CHANNEL) == ADC_CHANNEL_2)           || \
                                 ((CHANNEL) == ADC_CHANNEL_3)           || \
                                 ((CHANNEL) == ADC_CHANNEL_4)           || \
                                 ((CHANNEL) == ADC_CHANNEL_5)           || \
                                 ((CHANNEL) == ADC_CHANNEL_6)           || \
                                 ((CHANNEL) == ADC_CHANNEL_7)           || \
                                 ((CHANNEL) == ADC_CHANNEL_8)           || \
                                 ((CHANNEL) == ADC_CHANNEL_9)           || \
                                 ((CHANNEL) == ADC_CHANNEL_10)          || \
                                 ((CHANNEL) == ADC_CHANNEL_11)          || \
                                 ((CHANNEL) == ADC_CHANNEL_12)          || \
                                 ((CHANNEL) == ADC_CHANNEL_13)          || \
                                 ((CHANNEL) == ADC_CHANNEL_14)          || \
                                 ((CHANNEL) == ADC_CHANNEL_15))

#define IS_ADC_SOURCE(SOURCE)   (((SOURCE) == ADC_CHANNEL_EXT) || \
                                 ((SOURCE) == ADC_CHANNEL_INT))
#endif /* XT32H0xxB */

#if defined(XT32H0xxAMPW) || defined(XT32H0xxB)
#define IS_ADC_RESOLUTION(RESOLUTION) (((RESOLUTION) == ADC_RESOLUTION_12B) || \
                                       ((RESOLUTION) == ADC_RESOLUTION_10B) || \
                                       ((RESOLUTION) == ADC_RESOLUTION_8B)  )
#endif /* XT32H0xxAMPW || XT32H0xxB */

/**
  * @}
  */


/* Private constants ---------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/** @defgroup ADC_Exported_Macros ADC Exported Macros
  * @{
  */
/** @brief  Reset ADC handle state.
  * @param __HANDLE__ ADC handle
  * @retval None
  */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  do{                                                                          \
    (__HANDLE__)->State = HAL_ADC_STATE_RESET;                                 \
    (__HANDLE__)->MspInitCallback = NULL;                                      \
    (__HANDLE__)->MspDeInitCallback = NULL;                                    \
  } while(0)
#else
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  ((__HANDLE__)->State = HAL_ADC_STATE_RESET)
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @brief Clear ADC error code (set it to no error code "HAL_ADC_ERROR_NONE").
  * @param __HANDLE__ ADC handle
  * @retval None
  */
#define ADC_CLEAR_ERRORCODE(__HANDLE__) ((__HANDLE__)->ErrorCode = HAL_ADC_ERROR_NONE)

/**
  * @brief ADC poweron.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_POWERON(__HANDLE__)            (((__HANDLE__)->Instance->PDCTRL) &= (~MDU_PDCTRL_ADCPD))

/**
  * @brief ADC powerdown.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_POWERDOWN(__HANDLE__)          (((__HANDLE__)->Instance->PDCTRL) |= (MDU_PDCTRL_ADCPD))

/**
  * @brief ADC chec power on.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_ISPOWERON(__HANDLE__)         ((READ_BIT(((__HANDLE__)->Instance->PDCTRL), (MDU_PDCTRL_ADCPD)) == MDU_PDCTRL_ADCPD) ? SET : RESET)

#if defined (XT32H0xxB)
/**
  * @brief ADC regular group EOS DMA enable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_REGGRP_DMAEOS_ENABLE(__HANDLE__)         (SET_BIT(((__HANDLE__)->Instance->DMA_CFG), MDU_ADCDMACFG_REG_DMA_EN))

/**
  * @brief ADC regular group EOS DMA diaable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_REGGRP_DMAEOS_DIAABLE(__HANDLE__)         (CLEAR_BIT(((__HANDLE__)->Instance->DMA_CFG), MDU_ADCDMACFG_REG_DMA_EN))

/**
  * @brief ADC injection group EOS DMA enable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_INJGRP_DMAEOS_ENABLE(__HANDLE__)         (SET_BIT(((__HANDLE__)->Instance->DMA_CFG), MDU_ADCDMACFG_INJ_DMA_EN))

/**
  * @brief ADC injection group EOS DMA diaable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_INJGRP_DMAEOS_DIAABLE(__HANDLE__)         (CLEAR_BIT(((__HANDLE__)->Instance->DMA_CFG), MDU_ADCDMACFG_INJ_DMA_EN))

/**
  * @brief ADC regular group EOS enable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_REGGRP_EOS_ENABLE(__HANDLE__)         (SET_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_REG_EOS_EN))

/**
  * @brief ADC regular group EOS disable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_REGGRP_EOS_DISABLE(__HANDLE__)         (CLEAR_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_REG_EOS_EN))

/**
  * @brief ADC regular group EOC enable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_REGGRP_EOC_ENABLE(__HANDLE__)         (SET_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_REG_EOC_EN))

/**
  * @brief ADC regular group EOC disable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_REGGRP_EOC_DISABLE(__HANDLE__)         (CLEAR_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_REG_EOC_EN))

/**
  * @brief ADC injection group EOS enable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_INJGRP_EOS_ENABLE(__HANDLE__)         (SET_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_INJ_EOS_EN))

/**
  * @brief ADC injection group EOS disable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_INJGRP_EOS_DISABLE(__HANDLE__)         (CLEAR_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_INJ_EOS_EN))

/**
  * @brief ADC injection group EOC enable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_INJGRP_EOC_ENABLE(__HANDLE__)         (SET_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_INJ_EOC_EN))

/**
  * @brief ADC injection group EOC disable.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_INJGRP_EOC_DISABLE(__HANDLE__)         (CLEAR_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_INJ_EOC_EN))

/**
  * @brief ADC set regular interrupt polarity.
  * @param __HANDLE__ MDU handle
  * @param __POLARITY__ interrupt polarity
  *        @arg @ref ADC_INT_POLARITY_HIGH
  *        @arg @ref ADC_INT_POLARITY_LOW
  * @retval None
  */
#define __HAL_ADC_SET_REG_INT_POLARITY(__HANDLE__, __POLARITY__)          (MODIFY_REG(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_REG_INT_POL, (__POLARITY__) << MDU_MDUCFG_REG_INT_POL_Pos))

/**
  * @brief ADC set injection interrupt polarity.
  * @param __HANDLE__ MDU handle
  * @param __POLARITY__ interrupt polarity
  *        @arg @ref ADC_INT_POLARITY_HIGH
  *        @arg @ref ADC_INT_POLARITY_LOW
  * @retval None
  */
#define __HAL_ADC_SET_INJ_INT_POLARITY(__HANDLE__, __POLARITY__)          (MODIFY_REG(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_INJ_INT_POL, (__POLARITY__) << MDU_MDUCFG_INJ_INT_POL_Pos))

/**
  * @brief ADC set reset pulse width.
  * @param __HANDLE__ MDU handle
  * @param __CYCLES__ reset pulse width (n+1)
  *        This value is one of [0,3]
  * @retval None
  */
#define __HAL_ADC_SET_RESET_PULSE_WIDTH(__HANDLE__, __CYCLES__)          (MODIFY_REG(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_RSTB_CYC, (__CYCLES__) << MDU_MDUCFG_RSTB_CYC_Pos))

/**
  * @brief ADC set PGA pre-sampling cycles.
  * @param __HANDLE__ MDU handle
  * @param __CYCLES__ PGA pre-sampling (n+1)
  *        This value is one of [0,0xFF]
  * @retval None
  */
#define __HAL_ADC_SET_PRESAMPLING_CYCLES(__HANDLE__, __CYCLES__)          (MODIFY_REG(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_SYNC_PHS, (__CYCLES__) << MDU_MDUCFG_SYNC_PHS_Pos))

/**
  * @brief ADC enable/disable
  * @param __HANDLE__ MDU handle
  * @retval None 
  */
#define __HAL_ADC_ENABLE(__HANDLE__)             SET_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_ADC_EN)
#define __HAL_ADC_DISABLE(__HANDLE__)            CLEAR_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_ADC_EN)

/**
  * @brief ADC reset/release reset.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_RESET(__HANDLE__)                  (CLEAR_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_ADC_RST))
#define __HAL_ADC_RESET_RELEASE(__HANDLE__)          (SET_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_ADC_RST))

/**
  * @brief ADC Start/Stop.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_START(__HANDLE__)          (SET_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_ADC_START_EN))
#define __HAL_ADC_STOP(__HANDLE__)           (CLEAR_BIT(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_ADC_START_EN))

/**
  * @brief ADC set PGA pre-sampling mode.
  * @param __HANDLE__ MDU handle
  * @param __MODE__ pre-sampling mode
  *       @arg @ref ADC_PRESAMPLING_MODE_SAME
  *       @arg @ref ADC_PRESAMPLING_MODE_DEDICATED
  * @retval None
  */
#define __HAL_ADC_SET_PRESAMPLING_MODE(__HANDLE__, __MODE__)          (MODIFY_REG(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_SEL_PGA_CTRL, (__MODE__)))

/**
  * @brief ADC regular group enable/disable
  * @param __HANDLE__ MDU handle
  * @retval None 
  */
#define __HAL_ADC_REGGRP_ENABLE(__HANDLE__)             SET_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_REG_GRP_EN)
#define __HAL_ADC_REGGRP_DISABLE(__HANDLE__)            CLEAR_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_REG_GRP_EN)

/**
  * @brief ADC injection group enable/disable
  * @param __HANDLE__ MDU handle
  * @retval None 
  */
#define __HAL_ADC_INJGRP_ENABLE(__HANDLE__)             SET_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_INJ_GRP_EN)
#define __HAL_ADC_INJGRP_DISABLE(__HANDLE__)            CLEAR_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_INJ_GRP_EN)

/**
  * @brief ADC discharge phase enable/disable
  * @param __HANDLE__ MDU handle
  * @retval None 
  */
#define __HAL_ADC_DISCHARGE_ENABLE(__HANDLE__)             SET_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_DSCH_EN)
#define __HAL_ADC_DISCHARGE_DISABLE(__HANDLE__)            CLEAR_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_DSCH_EN)

/**
  * @brief ADC set discharge phase cycles.
  * @param __HANDLE__ MDU handle
  * @param __CYCLES__ discharge phase cycles (n+1)
  *        This value is one of [0, 0xFF]
  * @retval None
  */
#define __HAL_ADC_SET_DISCHARGE_CYCLES(__HANDLE__, __CYCLES__)          (MODIFY_REG(((__HANDLE__)->Instance->MDU_CFG), MDU_MDUCFG_DSCH_PHS, (__CYCLES__) << MDU_MDUCFG_DSCH_PHS_Pos))

/**
  * @brief ADC Set software trigger
  * @param __HANDLE__ MDU handle
  * @retval None 
  */
#define __HAL_ADC_SET_SWTRIGGER(__HANDLE__)              SET_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_ADC_SFTRG)
#define __HAL_ADC_CLEAR_SWTRIGGER(__HANDLE__)            CLEAR_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_ADC_SFTRG)
#define __HAL_ADC_TOGGLE_SWTRIGGER(__HANDLE__)           (((__HANDLE__)->Instance->MDU_CFG & MDU_MDUCFG_ADC_SFTRG) ?\
                                                          CLEAR_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_ADC_SFTRG) :\
                                                          SET_BIT((__HANDLE__)->Instance->MDU_CFG, MDU_MDUCFG_ADC_SFTRG) )

/**
  * @brief ADC Set AMP Gain.
  * @param __HANDLE__ MDU handle
  * @param __GAIN__ the value is 0 to 0x3
  * @retval None
  */
#define __HAL_ADC_SETAMPGAIN(__HANDLE__, __GAIN__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_AMPGAIN, ((__GAIN__) << MDU_ADCCFG_AMPGAIN_Pos)))

/**
  * @brief ADC Get APMP Gain.
  * @param __HANDLE__ MDU handle
  * @retval the value is 0 to 0x3
  */
#define __HAL_ADC_GETAMPGAIN(__HANDLE__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_AMPGAIN)) >> MDU_ADCCFG_AMPGAIN_Pos)

#else
#if defined(XT32H0xxBMPW)
/**
  * @brief ADC Set temperature sensor trim.
  * @param __HANDLE__ MDU handle
  * @param __TRIM__ the value is 0 to 0x7
  * @retval None
  */
#define __HAL_ADC_SETTSTRIM(__HANDLE__, __TRIM__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_TS_TRIM, ((__TRIM__) << MDU_ADCCFG_TS_TRIM_Pos)))

/**
  * @brief ADC Get temperature sensor trim.
  * @param __HANDLE__ MDU handle
  * @retval the value is 0 to 0xF
  */
#define __HAL_ADC_GETTSTRIM(__HANDLE__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_TS_TRIM)) >> MDU_ADCCFG_TS_TRIM_Pos)

/**
  * @brief ADC Set Dtune.
  * @param __HANDLE__ MDU handle
  * @param __TUNE__ the value is 0 to 0x3
  * @retval None
  */
#define __HAL_ADC_SETDTUNE(__HANDLE__, __TUNE__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_ADCDTUNE, ((__TUNE__) << MDU_ADCCFG_ADCDTUNE_Pos)))

/**
  * @brief ADC Get Dtune.
  * @param __HANDLE__ MDU handle
  * @retval the value is 0 to 0x3
  */
#define __HAL_ADC_GETDTUNE(__HANDLE__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_ADCDTUNE)) >> MDU_ADCCFG_ADCDTUNE_Pos)

/**
  * @brief ADC Set AMP Gain.
  * @param __HANDLE__ MDU handle
  * @param __GAIN__ the value is 0 to 0x3
  * @retval None
  */
#define __HAL_ADC_SETAMPGAIN(__HANDLE__, __GAIN__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_AMPGAIN, ((__GAIN__) << MDU_ADCCFG_AMPGAIN_Pos)))

/**
  * @brief ADC Get APMP Gain.
  * @param __HANDLE__ MDU handle
  * @retval the value is 0 to 0x3
  */
#define __HAL_ADC_GETAMPGAIN(__HANDLE__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_AMPGAIN)) >> MDU_ADCCFG_AMPGAIN_Pos)

/**
  * @brief ADC Set PGA Miller.
  * @param __HANDLE__ MDU handle
  * @param __PGACH__ the value is 0 to 0x3
  * @param __MILLER__ the value is 0 to 0x3
  * @retval None
  */
#define __HAL_ADC_SETPGAMILLER(__HANDLE__, __PGACH__, __MILLER__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_PGAMILLER1 << (__PGACH__<< 1) , ((__MILLER__) << (MDU_ADCCFG_PGAMILLER1_Pos+(__PGACH__<<1)))))

/**
  * @brief ADC Get PGA Miller.
  * @param __HANDLE__ MDU handle
  * @param __PGACH__ the value is 0 to 0x3
  * @retval the value is 0 to 0x3
  */
#define __HAL_ADC_GETPGAMILLER(__HANDLE__, __PGACH__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_PGAMILLER1 << (__PGACH__<< 1) )) >> (MDU_ADCCFG_PGAMILLER1_Pos+(__PGACH__<<1)))

/**
  * @brief ADC Set AMP Miller.
  * @param __HANDLE__ MDU handle
  * @param __MILLER__ the value is 0 to 1
  * @retval None
  */
#define __HAL_ADC_SETAMPMILLER(__HANDLE__, __MILLER__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_AMPMILLER, ((__MILLER__) << MDU_ADCCFG_AMPMILLER_Pos)))

/**
  * @brief ADC Get APMP Miller.
  * @param __HANDLE__ MDU handle
  * @retval the value is 0 to 1
  */
#define __HAL_ADC_GETAMPMILLER(__HANDLE__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_AMPMILLER)) >> MDU_ADCCFG_AMPMILLER_Pos)

/**
  * @brief ADC Set TSample.
  * @param __HANDLE__ MDU handle
  * @param __SAMPLE__ the value is 0 to 1
  * @retval None
  */
#define __HAL_ADC_SETTSAMPLE(__HANDLE__, __SAMPLE__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_ADCTSAMPLE, ((__SAMPLE__) << MDU_ADCCFG_ADCTSAMPLE_Pos)))

/**
  * @brief ADC Get APMP Miller.
  * @param __HANDLE__ MDU handle
  * @retval the value is 0 to 1
  */
#define __HAL_ADC_GETTSAMPLE(__HANDLE__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_ADCTSAMPLE)) >> MDU_ADCCFG_ADCTSAMPLE_Pos)

#endif /* XT32H0xxBMPW */

/**
  * @brief ADC Set reset Delay after start.
  * @param __HANDLE__ MDU handle
  * @param __DELAY__ reset delay 0 to 0xF
  * @retval None
  */
#define __HAL_ADC_SETRSTDELAY(__HANDLE__, __DELAY__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_RSTBDLY, (__DELAY__ << MDU_ADCCFG_RSTBDLY_Pos)))

/**
  * @brief ADC Get reset Delay after start.
  * @param __HANDLE__ MDU handle
  * @retval reset delay 0 to 0xF
  */
#define __HAL_ADC_GETRSTDELAY(__HANDLE__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_RSTBDLY)) >> MDU_ADCCFG_RSTBDLY_Pos)

#if defined(XT32H0xxAMPW)
/**
  * @brief ADC Set resolution.
  * @param __HANDLE__ MDU handle
  * @param __RESOLUTION__ This parameter can one of the following values:
  *        @arg @ref ADC_RESOLUTION_8B
  *        @arg @ref ADC_RESOLUTION_10B
  *        @arg @ref ADC_RESOLUTION_12B
  * @retval None
  */
#define __HAL_ADC_SETRESOLUTION(__HANDLE__, __RESOLUTION__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_RESCFG, (__RESOLUTION__)))

/**
  * @brief ADC Get resolution.
  * @param __HANDLE__ MDU handle
  * @retval resolution
  *        @arg @ref ADC_RESOLUTION_8B
  *        @arg @ref ADC_RESOLUTION_10B
  *        @arg @ref ADC_RESOLUTION_12B
  */
#define __HAL_ADC_GETRESOLUTION(__HANDLE__)          ((READ_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_RESCFG)) )
#endif /* XT32H0xxAMPW */

/**
  * @brief ADC Set Channel.
  * @param __HANDLE__ MDU handle
  * @param __CH__ ADC channel 
  *        @arg @ref ADC_CHANNEL_0
  *        @arg @ref ADC_CHANNEL_1
  *        @arg @ref ADC_CHANNEL_2
  *        @arg @ref ADC_CHANNEL_3
  *        @arg @ref ADC_CHANNEL_4
  *        @arg @ref ADC_CHANNEL_5
  *        @arg @ref ADC_CHANNEL_6
  *        @arg @ref ADC_CHANNEL_7
  *        @arg @ref ADC_CHANNEL_8
  *        @arg @ref ADC_CHANNEL_9
  *        @arg @ref ADC_CHANNEL_10
  *        @arg @ref ADC_CHANNEL_11
  *        @arg @ref ADC_CHANNEL_12
  *        @arg @ref ADC_CHANNEL_13
  *        @arg @ref ADC_CHANNEL_14 
  *        @arg @ref ADC_CHANNEL_15 |
  * @retval None
  */
#define __HAL_ADC_SETCHANNEL(__HANDLE__, __CH__)          (MODIFY_REG(((__HANDLE__)->Instance->ADC_CFG), MDU_ADCCFG_CHSLCT, __CH__))

/**
  * @brief ADC Get Channel.
  * @param __HANDLE__ MDU handle
  * @retval ADC channel 
  *        @arg @ref ADC_CHANNEL_0
  *        @arg @ref ADC_CHANNEL_1
  *        @arg @ref ADC_CHANNEL_2
  *        @arg @ref ADC_CHANNEL_3
  *        @arg @ref ADC_CHANNEL_4
  *        @arg @ref ADC_CHANNEL_5
  *        @arg @ref ADC_CHANNEL_6
  *        @arg @ref ADC_CHANNEL_7
  *        @arg @ref ADC_CHANNEL_8
  *        @arg @ref ADC_CHANNEL_9
  *        @arg @ref ADC_CHANNEL_10
  *        @arg @ref ADC_CHANNEL_11
  *        @arg @ref ADC_CHANNEL_12
  *        @arg @ref ADC_CHANNEL_13
  *        @arg @ref ADC_CHANNEL_14
  *        @arg @ref ADC_CHANNEL_15 |
  */
#define __HAL_ADC_GETCHANNEL(__HANDLE__)          (READ_BIT((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_CHSLCT))

/**
  * @brief ADC Set Channel.
  * @param __HANDLE__ MDU handle
  * @param __CH__ ADC Source 
  *        @arg @ref ADC_CHANNEL_EXT
  *        @arg @ref ADC_CHANNEL_INT
  * @retval None
  */
#define __HAL_ADC_SETCHANNELSOURCE(__HANDLE__, __CH__)          (MODIFY_REG((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_ICHSLCT, __CH__))

/**
  * @brief ADC Get Channel.
  * @param __HANDLE__ MDU handle
  * @retval ADC Source 
  *        @arg @ref ADC_CHANNEL_EXT
  *        @arg @ref ADC_CHANNEL_INT
  */
#define __HAL_ADC_GETCHANNELSOURCE(__HANDLE__)                  (READ_BIT((__HANDLE__)->Instance->ADC_CFG, MDU_ADCCFG_ICHSLCT))

/**
  * @brief ADC Get output data.
  * @param __HANDLE__ MDU handle
  * @retval ADC channel 
  */
#define __HAL_ADC_GETEOCDATA(__HANDLE__)          (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS, MDU_ADC_OUTPUT_DATA) >> MDU_ADC_OUTPUT_DATA_Pos)

/**
  * @brief ADC Set ADC trigger source.
  * @param __HANDLE__ MDU handle
  * @param __SOURCE__ ADC trigger source
  * @retval None 
  */
#define __HAL_ADC_SET_TRG_SRC(__HANDLE__, __SOURCE__)  (MODIFY_REG((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_TRGISRC, (__SOURCE__)))
#define __HAL_ADC_GET_TRG_SRC(__HANDLE__)              (READ_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_TRGISRC))

/**
  * @brief ADC Set ADC trigger edge.
  * @param __HANDLE__ MDU handle
  * @param __EDGE__ ADC trigger edge
  * @retval None 
  */
#define __HAL_ADC_SET_TRG_EDGE(__HANDLE__, __EDGE__)    (MODIFY_REG((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_RISEEDGE|MDU_ADCCTRL_FALLEDGE, (__EDGE__)))
#define __HAL_ADC_GET_TRG_EDGE(__HANDLE__)              (READ_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_RISEEDGE|MDU_ADCCTRL_FALLEDGE))

/**
  * @brief ADC Set software trigger
  * @param __HANDLE__ MDU handle
  * @param __EDGE__ ADC trigger edge
  * @retval None 
  */
#define __HAL_ADC_SET_SWTRIGGER(__HANDLE__)              SET_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_SWTRG)
#define __HAL_ADC_CLEAR_SWTRIGGER(__HANDLE__)            CLEAR_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_SWTRG)
#define __HAL_ADC_TOGGLE_SWTRIGGER(__HANDLE__)           (((__HANDLE__)->Instance->ADC_CTRL & MDU_ADCCTRL_SWTRG) ?\
                                                          CLEAR_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_SWTRG) :\
                                                          SET_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_SWTRG) )
/**
  * @brief ADC reset.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_RESET(__HANDLE__)          (CLEAR_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_RST))

/**
  * @brief ADC reset release.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_RESET_RELEASE(__HANDLE__)          (SET_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_RST))

/**
  * @brief ADC check reset.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_ISRESET(__HANDLE__)          ((READ_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_RST) == MDU_ADCCTRL_RST) ? SET : RESET)

/**
  * @brief ADC Start.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_START(__HANDLE__)          (SET_BIT(((__HANDLE__)->Instance->ADC_CTRL), MDU_ADCCTRL_SEQ_STRT))

/**
  * @brief ADC Stop.
  * @param __HANDLE__ MDU handle
  * @retval None
  */
#define __HAL_ADC_STOP(__HANDLE__)          (CLEAR_BIT(((__HANDLE__)->Instance->ADC_CTRL), MDU_ADCCTRL_SEQ_STRT))

/**
  * @brief ADC Set ADC convert mode.
  * @param __HANDLE__ MDU handle
  * @param __MODE__ ADC mode
  *        @arg @ref ADC_CONVERT_SINGLE
  *        @arg @ref ADC_CONVERT_CONTINUOUS
  * @retval None 
  */
#define __HAL_ADC_SET_CONVERT_MODE(__HANDLE__, __MODE__)  (MODIFY_REG((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_CONV_MODE, (__MODE__)))
#define __HAL_ADC_GET_CONVERT_MODE(__HANDLE__)            (READ_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_CONV_MODE))

/**
  * @brief ADC Set ADC convert channel.
  * @param __HANDLE__ MDU handle
  * @param __MODE__ ADC channel
  *        @arg @ref ADC_CONVERT_INCREMENT
  *        @arg @ref ADC_CONVERT_DECREMENT
  * @retval None 
  */
#define __HAL_ADC_SET_SEQCON_DIR(__HANDLE__, __MODE__)  (MODIFY_REG((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_CH_MODE, (__MODE__)))
#define __HAL_ADC_GET_SEQCON_DIR(__HANDLE__)            (READ_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_CH_MODE))

/**
  * @brief ADC Set ADC group channel.
  * @param __HANDLE__ MDU handle
  * @param __MODE__ ADC channel (or all value)
  *        @arg @ref ADC_GROUP_CH_0
  *        @arg @ref ADC_GROUP_CH_1
  *        @arg @ref ADC_GROUP_CH_2
  *        @arg @ref ADC_GROUP_CH_3
  *        @arg @ref ADC_GROUP_CH_4
  *        @arg @ref ADC_GROUP_CH_5
  *        @arg @ref ADC_GROUP_CH_6
  *        @arg @ref ADC_GROUP_CH_7
  *        @arg @ref ADC_GROUP_CH_8
  *        @arg @ref ADC_GROUP_CH_9
  *        @arg @ref ADC_GROUP_CH_10
  *        @arg @ref ADC_GROUP_CH_11
  *        @arg @ref ADC_GROUP_CH_12
  *        @arg @ref ADC_GROUP_CH_13
  *        @arg @ref ADC_GROUP_CH_14
  *        @arg @ref ADC_GROUP_CH_15
  * @retval None 
  */
#define __HAL_ADC_SET_GROUP(__HANDLE__, __GROUP__)  (MODIFY_REG((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_GCHIND, (__GROUP__)))
#define __HAL_ADC_GET_GROUP(__HANDLE__)             (READ_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_GCHIND))

/**
  * @brief ADC Set ADC sequence convert enable.
  * @param __HANDLE__ MDU handle
  * @param __MODE__ ADC channel
  *        @arg @ref ADC_CONVERT_CHANNEL
  *        @arg @ref ADC_CONVERT_SEQUENCE
  * @retval None 
  */
#define __HAL_ADC_SEQCON_ENABLE(__HANDLE__)         (SET_BIT((__HANDLE__)->Instance->ADC_CTRL, (MDU_ADCCTRL_ENABLE)))
#define __HAL_ADC_SEQCON_DISABLE(__HANDLE__)        (CLEAR_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_ENABLE))
#define __HAL_ADC_SEQCON_IDENABLED(__HANDLE__)      (READ_BIT((__HANDLE__)->Instance->ADC_CTRL, MDU_ADCCTRL_ENABLE) ? SET : RESET)

/**
  * @brief ADC Set ADC sequence convert start/stop.
  * @param __HANDLE__ MDU handle
  * @param __MODE__ ADC channel
  *        @arg @ref ADC_CONVERT_CHANNEL
  *        @arg @ref ADC_CONVERT_SEQUENCE
  * @retval None 
  */
#define __HAL_ADC_SEQCON_START(__HANDLE__)         (SET_BIT((__HANDLE__)->Instance->ADC_CTRL, (MDU_ADCCTRL_SEQ_STRT)))
#define __HAL_ADC_SEQCON_STOP(__HANDLE__)          (CLEAR_BIT((__HANDLE__)->Instance->ADC_CTRL, (MDU_ADCCTRL_SEQ_STRT)))

/**
  * @brief ADC Set ADC sequence convert reset.
  * @param __HANDLE__ MDU handle
  * @param __MODE__ ADC channel
  *        @arg @ref ADC_CONVERT_CHANNEL
  *        @arg @ref ADC_CONVERT_SEQUENCE
  * @retval None 
  */
#define __HAL_ADC_SEQCON_NORMAL(__HANDLE__)         (SET_BIT((__HANDLE__)->Instance->ADC_CTRL, (MDU_ADCCTRL_RST)))
#define __HAL_ADC_SEQCON_RESET(__HANDLE__)          (CLEAR_BIT((__HANDLE__)->Instance->ADC_CTRL, (MDU_ADCCTRL_RST)))

/**
  * @brief ADC Set ADC sequence PGA sampleing width.
  * @param __HANDLE__ MDU handle
  * @param __MODE__ ADC channel
  *        @arg @ref ADC_SEQCONV_PGA_1_CYCLE
  *        @arg @ref ADC_SEQCONV_PGA_2_CYCLE
  * @retval None 
  */
#define __HAL_ADC_SEQCON_SET_SAMPLING_WIDTH(__HANDLE__, __WIDTH__)         (MODIFY_REG((__HANDLE__)->Instance->ADC_CTRL, (MDU_ADCCTRL_PGASMPW), (__WIDTH__)))
#define __HAL_ADC_SEQCON_GET_SAMPLING_WIDTH(__HANDLE__)                    (READ_BIT((__HANDLE__)->Instance->ADC_CTRL, (MDU_ADCCTRL_PGASMPW)))

/**
  * @brief ADC Get channel output data.
  * @param __HANDLE__ MDU handle
  * @retval ADC channel 
  */
#define __HAL_ADC_GETEOSRESULT(__HANDLE__, __CHANNEL__)      ( ((__CHANNEL__) == 0) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH0, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 1) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH1, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 2) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH2, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 3) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH3, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 4) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH4, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 5) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH5, MDU_ADC_OUTPUT_DATA)) : \
																															 ((__CHANNEL__) == 6) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH6, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 7) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH7, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 8) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH8, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 9) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH9, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 10) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH10, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 11) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH11, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 12) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH12, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 13) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH13, MDU_ADC_OUTPUT_DATA)) : \
                                                               ((__CHANNEL__) == 14) ? (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH14, MDU_ADC_OUTPUT_DATA)) : \
																															 (READ_BIT((__HANDLE__)->Instance->ADC_RESULTS_CH15, MDU_ADC_OUTPUT_DATA)))

/**
  * @brief Configure and enable ADC EOS interrupt.
  * @param __HANDLE__ ADC handle
  * @retval None
  */
#define __HAL_ADC_EOS_IT_ENABLE() do {                                                           \
	                                      CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_ADC_EOS_MASK);  \
	                                      SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_ADC_EOS_MASK);      \
	                                      CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_ADC_EOS_MASK);  \
                                     } while(0)

/**
  * @brief Disable ADC EOS interrupt.
  * @param __HANDLE__ ADC handle
  * @retval None
  */
#define __HAL_ADC_EOS_IT_DISABLE()   CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_ADC_EOS_MASK)

/* Macro for internal HAL driver usage, and possibly can be used into code of */
/* final user.                                                                */

/** @defgroup ADC_HAL_EM_HANDLE_IT_FLAG HAL ADC macro to manage HAL ADC handle, IT and flags.
  * @{
  */

/** @brief  Reset ADC handle state.
  * @param __HANDLE__ ADC handle
  * @retval None
  */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  do{                                                                          \
    (__HANDLE__)->State = HAL_ADC_STATE_RESET;                                 \
    (__HANDLE__)->MspInitCallback = NULL;                                      \
    (__HANDLE__)->MspDeInitCallback = NULL;                                    \
  } while(0)
#else
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  ((__HANDLE__)->State = HAL_ADC_STATE_RESET)
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @brief Check whether the specified ADC flag is set or not.
  * @param __HANDLE__ ADC handle
  * @param __FLAG__ ADC flag
  *        This parameter can be one of the following values:
  *            @arg @ref ADC_FLAG_EOC     ADC End of Regular Conversion flag
  *            @arg @ref ADC_FLAG_EOS     ADC End of Regular sequence of Conversions flag
  * @retval State of flag (TRUE or FALSE).
  */
#define __HAL_ADC_GET_FLAG(__HANDLE__, __FLAG__)                               \
  ((((__HANDLE__)->Instance->ADC_STATUS) & (__FLAG__)) == (__FLAG__))

/**
  * @brief Clear the specified ADC flag.
  * @param __HANDLE__ ADC handle
  * @param __FLAG__ ADC flag
  *        This parameter can be one of the following values:
  *            @arg @ref ADC_FLAG_EOC     ADC End of Regular Conversion flag
  *            @arg @ref ADC_FLAG_EOS     ADC End of Regular sequence of Conversions flag
  * @retval None
  */
/* Note: bit cleared bit by writing 1 (writing 0 has no effect on any bit of register ISR) */
#define __HAL_ADC_CLEAR_FLAG(__HANDLE__, __FLAG__)                             \
  (((__HANDLE__)->Instance->ADC_STATUS) = (__FLAG__))

/**
  * @}
  */

/** @defgroup ADC_HAL_EM_HELPER_MACRO HAL ADC helper macro
  * @{
  */

/**
  * @brief  Helper macro to get ADC channel number in decimal format
  *         from literals ADC_CHANNEL_x.
  * @note   Example:
  *           __HAL_ADC_CHANNEL_TO_DECIMAL_NB(ADC_CHANNEL_4)
  *           will return decimal number "4".
  * @note   The input can be a value from functions where a channel
  *         number is returned, either defined with number
  *         or with bitfield (only one bit must be set).
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref ADC_CHANNEL_0
  *         @arg @ref ADC_CHANNEL_1
  *         @arg @ref ADC_CHANNEL_2
  *         @arg @ref ADC_CHANNEL_3
  *         @arg @ref ADC_CHANNEL_4
  *         @arg @ref ADC_CHANNEL_5
  *         @arg @ref ADC_CHANNEL_6
  *         @arg @ref ADC_CHANNEL_7
  *         @arg @ref ADC_CHANNEL_8
  *         @arg @ref ADC_CHANNEL_9
  *         @arg @ref ADC_CHANNEL_10
  *         @arg @ref ADC_CHANNEL_11
  *         @arg @ref ADC_CHANNEL_12
  *         @arg @ref ADC_CHANNEL_13
  *         @arg @ref ADC_CHANNEL_14
  *         @arg @ref ADC_CHANNEL_15         (1)
  *         @arg @ref ADC_CHANNEL_16         (1)
  *         @arg @ref ADC_CHANNEL_17         (1)
  *         @arg @ref ADC_CHANNEL_18
  *         @arg @ref ADC_CHANNEL_VREFINT
  *         @arg @ref ADC_CHANNEL_TEMPSENSOR
  *         @arg @ref ADC_CHANNEL_VBAT
  *
  *         (1) On XT32H0, parameter can be set in ADC group sequencer
  *             only if sequencer is set in mode "not fully configurable",
  *             refer to function @ref LL_ADC_REG_SetSequencerConfigurable().
  * @retval Value between Min_Data=0 and Max_Data=18
  */
#define __HAL_ADC_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)                           \
   (((__CHANNEL__) == MDU_ADCCTRL_GCHIND_0) ? 0 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_1) ? 1 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_2) ? 2 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_3) ? 3 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_4) ? 4 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_5) ? 5 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_6) ? 6 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_7) ? 7 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_8) ? 8 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_9) ? 9 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_10) ? 10 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_11) ? 11 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_12) ? 12 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_13) ? 13 : \
	  ((__CHANNEL__) == MDU_ADCCTRL_GCHIND_14) ? 14 : \
	  15)
/**
  * @brief  Helper macro to get ADC channel in literal format ADC_CHANNEL_x
  *         from number in decimal format.
  * @note   Example:
  *           __HAL_ADC_DECIMAL_NB_TO_CHANNEL(4)
  *           will return a data equivalent to "ADC_CHANNEL_4".
  * @param  __DECIMAL_NB__ Value between Min_Data=0 and Max_Data=18
  * @retval Returned value can be one of the following values:
  *         @arg @ref ADC_CHANNEL_0
  *         @arg @ref ADC_CHANNEL_1
  *         @arg @ref ADC_CHANNEL_2
  *         @arg @ref ADC_CHANNEL_3
  *         @arg @ref ADC_CHANNEL_4
  *         @arg @ref ADC_CHANNEL_5
  *         @arg @ref ADC_CHANNEL_6
  *         @arg @ref ADC_CHANNEL_7
  *         @arg @ref ADC_CHANNEL_8
  *         @arg @ref ADC_CHANNEL_9
  *         @arg @ref ADC_CHANNEL_10
  *         @arg @ref ADC_CHANNEL_11
  *         @arg @ref ADC_CHANNEL_12
  *         @arg @ref ADC_CHANNEL_13
  *         @arg @ref ADC_CHANNEL_14
  *         @arg @ref ADC_CHANNEL_15         (1)
  *         @arg @ref ADC_CHANNEL_16         (1)
  *         @arg @ref ADC_CHANNEL_17         (1)
  *         @arg @ref ADC_CHANNEL_18
  *         @arg @ref ADC_CHANNEL_VREFINT    (2)
  *         @arg @ref ADC_CHANNEL_TEMPSENSOR (2)
  *         @arg @ref ADC_CHANNEL_VBAT       (2)
  *
  *         (1) On XT32H0, parameter can be set in ADC group sequencer
  *             only if sequencer is set in mode "not fully configurable",
  *             refer to function @ref LL_ADC_REG_SetSequencerConfigurable().\n
  *         (2) For ADC channel read back from ADC register,
  *             comparison with internal channel parameter to be done
  *             using helper macro @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL().
  */
#define __HAL_ADC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                        \
  __LL_ADC_DECIMAL_NB_TO_CHANNEL((__DECIMAL_NB__))

/**
  * @brief  Helper macro to determine whether the selected channel
  *         corresponds to literal definitions of driver.
  * @note   The different literal definitions of ADC channels are:
  *         - ADC internal channel:
  *           ADC_CHANNEL_VREFINT, ADC_CHANNEL_TEMPSENSOR, ...
  *         - ADC external channel (channel connected to a GPIO pin):
  *           ADC_CHANNEL_1, ADC_CHANNEL_2, ...
  * @note   The channel parameter must be a value defined from literal
  *         definition of a ADC internal channel (ADC_CHANNEL_VREFINT,
  *         ADC_CHANNEL_TEMPSENSOR, ...),
  *         ADC external channel (ADC_CHANNEL_1, ADC_CHANNEL_2, ...),
  *         must not be a value from functions where a channel number is
  *         returned from ADC registers,
  *         because internal and external channels share the same channel
  *         number in ADC registers. The differentiation is made only with
  *         parameters definitions of driver.
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref ADC_CHANNEL_0
  *         @arg @ref ADC_CHANNEL_1
  *         @arg @ref ADC_CHANNEL_2
  *         @arg @ref ADC_CHANNEL_3
  *         @arg @ref ADC_CHANNEL_4
  *         @arg @ref ADC_CHANNEL_5
  *         @arg @ref ADC_CHANNEL_6
  *         @arg @ref ADC_CHANNEL_7
  *         @arg @ref ADC_CHANNEL_8
  *         @arg @ref ADC_CHANNEL_9
  *         @arg @ref ADC_CHANNEL_10
  *         @arg @ref ADC_CHANNEL_11
  *         @arg @ref ADC_CHANNEL_12
  *         @arg @ref ADC_CHANNEL_13
  *         @arg @ref ADC_CHANNEL_14
  *         @arg @ref ADC_CHANNEL_15         (1)
  *         @arg @ref ADC_CHANNEL_16         (1)
  *         @arg @ref ADC_CHANNEL_17         (1)
  *         @arg @ref ADC_CHANNEL_18
  *         @arg @ref ADC_CHANNEL_VREFINT
  *         @arg @ref ADC_CHANNEL_TEMPSENSOR
  *         @arg @ref ADC_CHANNEL_VBAT
  *
  *         (1) On XT32H0, parameter can be set in ADC group sequencer
  *             only if sequencer is set in mode "not fully configurable",
  *             refer to function @ref LL_ADC_REG_SetSequencerConfigurable().
  * @retval Value "0" if the channel corresponds to a parameter definition of a ADC external channel (channel connected to a GPIO pin).
  *         Value "1" if the channel corresponds to a parameter definition of a ADC internal channel.
  */
#define __HAL_ADC_IS_CHANNEL_INTERNAL(__CHANNEL__)                             \
  __LL_ADC_IS_CHANNEL_INTERNAL((__CHANNEL__))

/**
  * @brief  Helper macro to convert a channel defined from parameter
  *         definition of a ADC internal channel (ADC_CHANNEL_VREFINT,
  *         ADC_CHANNEL_TEMPSENSOR, ...),
  *         to its equivalent parameter definition of a ADC external channel
  *         (ADC_CHANNEL_1, ADC_CHANNEL_2, ...).
  * @note   The channel parameter can be, additionally to a value
  *         defined from parameter definition of a ADC internal channel
  *         (ADC_CHANNEL_VREFINT, ADC_CHANNEL_TEMPSENSOR, ...),
  *         a value defined from parameter definition of
  *         ADC external channel (ADC_CHANNEL_1, ADC_CHANNEL_2, ...)
  *         or a value from functions where a channel number is returned
  *         from ADC registers.
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref ADC_CHANNEL_0
  *         @arg @ref ADC_CHANNEL_1
  *         @arg @ref ADC_CHANNEL_2
  *         @arg @ref ADC_CHANNEL_3
  *         @arg @ref ADC_CHANNEL_4
  *         @arg @ref ADC_CHANNEL_5
  *         @arg @ref ADC_CHANNEL_6
  *         @arg @ref ADC_CHANNEL_7
  *         @arg @ref ADC_CHANNEL_8
  *         @arg @ref ADC_CHANNEL_9
  *         @arg @ref ADC_CHANNEL_10
  *         @arg @ref ADC_CHANNEL_11
  *         @arg @ref ADC_CHANNEL_12
  *         @arg @ref ADC_CHANNEL_13
  *         @arg @ref ADC_CHANNEL_14
  *         @arg @ref ADC_CHANNEL_15         (1)
  *         @arg @ref ADC_CHANNEL_16         (1)
  *         @arg @ref ADC_CHANNEL_17         (1)
  *         @arg @ref ADC_CHANNEL_18
  *         @arg @ref ADC_CHANNEL_VREFINT
  *         @arg @ref ADC_CHANNEL_TEMPSENSOR
  *         @arg @ref ADC_CHANNEL_VBAT
  *
  *         (1) On XT32H0, parameter can be set in ADC group sequencer
  *             only if sequencer is set in mode "not fully configurable",
  *             refer to function @ref LL_ADC_REG_SetSequencerConfigurable().
  * @retval Returned value can be one of the following values:
  *         @arg @ref ADC_CHANNEL_0
  *         @arg @ref ADC_CHANNEL_1
  *         @arg @ref ADC_CHANNEL_2
  *         @arg @ref ADC_CHANNEL_3
  *         @arg @ref ADC_CHANNEL_4
  *         @arg @ref ADC_CHANNEL_5
  *         @arg @ref ADC_CHANNEL_6
  *         @arg @ref ADC_CHANNEL_7
  *         @arg @ref ADC_CHANNEL_8
  *         @arg @ref ADC_CHANNEL_9
  *         @arg @ref ADC_CHANNEL_10
  *         @arg @ref ADC_CHANNEL_11
  *         @arg @ref ADC_CHANNEL_12
  *         @arg @ref ADC_CHANNEL_13
  *         @arg @ref ADC_CHANNEL_14
  *         @arg @ref ADC_CHANNEL_15
  *         @arg @ref ADC_CHANNEL_16
  *         @arg @ref ADC_CHANNEL_17
  *         @arg @ref ADC_CHANNEL_18
  */
#define __HAL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL(__CHANNEL__)                    \
  __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL((__CHANNEL__))

/**
  * @brief  Helper macro to determine whether the internal channel
  *         selected is available on the ADC instance selected.
  * @note   The channel parameter must be a value defined from parameter
  *         definition of a ADC internal channel (ADC_CHANNEL_VREFINT,
  *         ADC_CHANNEL_TEMPSENSOR, ...),
  *         must not be a value defined from parameter definition of
  *         ADC external channel (ADC_CHANNEL_1, ADC_CHANNEL_2, ...)
  *         or a value from functions where a channel number is
  *         returned from ADC registers,
  *         because internal and external channels share the same channel
  *         number in ADC registers. The differentiation is made only with
  *         parameters definitions of driver.
  * @param  __ADC_INSTANCE__ ADC instance
  * @param  __CHANNEL__ This parameter can be one of the following values:
  *         @arg @ref ADC_CHANNEL_VREFINT
  *         @arg @ref ADC_CHANNEL_TEMPSENSOR
  *         @arg @ref ADC_CHANNEL_VBAT
  * @retval Value "0" if the internal channel selected is not available on the ADC instance selected.
  *         Value "1" if the internal channel selected is available on the ADC instance selected.
  */
#define __HAL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE(__ADC_INSTANCE__, __CHANNEL__)  \
  __LL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE((__ADC_INSTANCE__), (__CHANNEL__))
#endif /* XT32H0xxB */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADC_Exported_Functions
  * @{
  */

/** @addtogroup ADC_Exported_Functions_Group1
  * @brief    Initialization and Configuration functions
  * @{
  */
/* Initialization and de-initialization functions  ****************************/
HAL_StatusTypeDef       HAL_ADC_Init(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADC_DeInit(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_MspInit(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc);

HAL_StatusTypeDef HAL_ADC_DMAHSIFConfig(ADC_HandleTypeDef *hadc, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmarx2, uint32_t rxif, uint32_t rx2if, uint32_t rxifcfg, uint32_t rx2ifcfg);
HAL_StatusTypeDef HAL_ADC_LinkDMA(ADC_HandleTypeDef *hadc, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmarx2);



#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/* Callbacks Register/UnRegister functions  ***********************************/
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID,
                                           pADC_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group2
  * @brief    IO operation functions
  * @{
  */
/* IO operation functions  *****************************************************/

HAL_StatusTypeDef       HAL_ADC_Start(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADC_Stop(ADC_HandleTypeDef *hadc);
#if defined(XT32H0xxB)
HAL_StatusTypeDef HAL_ADC_RegularGroupContinuousStart(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_RegularGroupContinuousStop(ADC_HandleTypeDef *hadc);
#endif /* XT32H0xxB */

/* Blocking mode: Polling */
#if defined(XT32H0xxB)
HAL_StatusTypeDef       HAL_ADC_PollForInjectionEOC(ADC_HandleTypeDef *hadc, uint32_t Flag, uint32_t Timeout);
HAL_StatusTypeDef       HAL_ADC_PollForInjectionEOS(ADC_HandleTypeDef *hadc, uint32_t Timeout);
HAL_StatusTypeDef       HAL_ADC_PollForRegularEOC(ADC_HandleTypeDef *hadc, uint32_t Flag, uint32_t Timeout);
HAL_StatusTypeDef       HAL_ADC_PollForRegularEOS(ADC_HandleTypeDef *hadc, uint32_t Timeout);
#else
HAL_StatusTypeDef       HAL_ADC_PollForConversion(ADC_HandleTypeDef *hadc, uint32_t Timeout);
HAL_StatusTypeDef       HAL_ADC_ClearConversionFlag(ADC_HandleTypeDef *hadc);
#endif /* XT32H0xxB */

/* Non-blocking mode: Interruption */
HAL_StatusTypeDef       HAL_ADC_Start_IT(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef       HAL_ADC_Stop_IT(ADC_HandleTypeDef *hadc);

/* Non-blocking mode: DMA */
#if defined(XT32H0xxB)
HAL_StatusTypeDef HAL_ADC_Start_InjectionDMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
HAL_StatusTypeDef HAL_ADC_Stop_InjectionDMA(ADC_HandleTypeDef *hadc);

HAL_StatusTypeDef HAL_ADC_Start_RegularDMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
HAL_StatusTypeDef HAL_ADC_Stop_RegularDMA(ADC_HandleTypeDef *hadc);
#else
HAL_StatusTypeDef       HAL_ADC_Start_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
HAL_StatusTypeDef       HAL_ADC_Stop_DMA(ADC_HandleTypeDef *hadc);
#endif /* XT32H0xxB */

/* ADC retrieve conversion value intended to be used with polling or interruption */
#if defined(XT32H0xxB)
uint32_t                HAL_ADC_GetInjectionChannelData(ADC_HandleTypeDef *hadc, uint32_t ChannelIndex);
uint32_t                HAL_ADC_GetRegularChannelData(ADC_HandleTypeDef *hadc, uint32_t ChannelIndex);
#else
uint32_t                HAL_ADC_GetValue(ADC_HandleTypeDef *hadc);
#endif /* XT32H0xxB */

/* ADC IRQHandler and Callbacks used in non-blocking modes (Interruption and DMA) */
void                    HAL_ADC_IRQHandler(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_EOCCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_EOSCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_DMAErrorCallback(ADC_HandleTypeDef *hadc);
#if defined(XT32H0xxB)
void                    HAL_ADC_InjectionEOCCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_InjectionEOSCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_InjectionAWDCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_InjectionOverWriteCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_RegularEOCCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_RegularEOSCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_RegularAWDCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_RegularOverWriteCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_InjectionDMACompletedCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_RegularDMACompletedCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_InjectionDMABlockCompletedCallback(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_RegularDMABlockCompletedCallback(ADC_HandleTypeDef *hadc);
#else
void                    HAL_ADC_DMACompletedCallback(ADC_HandleTypeDef *hadc);
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group3 Peripheral Control functions
  *  @brief    Peripheral Control functions
  * @{
  */
/* Peripheral Control functions ***********************************************/
HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef *hadc, void *pConfig);
HAL_StatusTypeDef HAL_ADC_ConversionStop(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_Enable(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_Disable(ADC_HandleTypeDef *hadc);
#if defined(XT32H0xxB)
HAL_StatusTypeDef HAL_ADC_ConfigInjectionGroup(ADC_HandleTypeDef *hadc, void *pConfig);
HAL_StatusTypeDef HAL_ADC_ConfigInjectionChannel(ADC_HandleTypeDef *hadc, void *pConfig);
HAL_StatusTypeDef HAL_ADC_ConfigRegularGroup(ADC_HandleTypeDef *hadc, void *pConfig);
HAL_StatusTypeDef HAL_ADC_ConfigRegularChannel(ADC_HandleTypeDef *hadc, void *pConfig);
HAL_StatusTypeDef HAL_ADC_ConfigRegularMAP(ADC_HandleTypeDef *hadc, uint32_t Map);

HAL_StatusTypeDef HAL_ADC_ConfigAwd(ADC_HandleTypeDef *hadc, void *pConfig);

#endif /* XT32H0xxB */

/* ADC manual mode functions */
#if defined(XT32H0xxB)
HAL_StatusTypeDef HAL_ADC_AutoModeEnable(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_ManualModeEnable(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_ManualModeStart(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_ManualModeStop(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_ManualModeTriggle(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_ManualModeConfig(ADC_HandleTypeDef *hadc, void* pConfig);
HAL_StatusTypeDef HAL_ADC_ManualModeChannelSelect(ADC_HandleTypeDef *hadc, uint32_t Channel);
uint32_t          HAL_ADC_ManualModeGetValue(ADC_HandleTypeDef *hadc, uint32_t Channel);
#endif /* XT32H0xxB */

/**
  * @}
  */

/* Peripheral State functions *************************************************/
/** @addtogroup ADC_Exported_Functions_Group4
  * @{
  */
uint32_t                HAL_ADC_GetState(ADC_HandleTypeDef *hadc);
uint32_t                HAL_ADC_GetError(ADC_HandleTypeDef *hadc);

/**
  * @}
  */

/** @addtogroup ADC_Exported_Functions_Group5
  * @{
  */
uint32_t                HAL_ADC_Calibration(ADC_HandleTypeDef *hadc);
uint32_t                HAL_ADC_CalibrationEnable(ADC_HandleTypeDef *hadc);
uint32_t                HAL_ADC_CalibrationDisable(ADC_HandleTypeDef *hadc);

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


#endif /* XT32H0xx_HAL_ADC_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
