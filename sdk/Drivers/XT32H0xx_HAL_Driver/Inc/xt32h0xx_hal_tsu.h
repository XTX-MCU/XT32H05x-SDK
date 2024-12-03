/**
  ******************************************************************************
  * @file    xt32h0xx_hal_tsu.h
  * @author  Software Team
  * @brief   Header file of TSU HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_TSU_H
#define XT32H0xx_HAL_TSU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup TSU
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup TSU_Exported_Types TSU Exported Types
  * @{
  */

/**
  * @brief  TSU HAL State Structure definition
  */
typedef enum
{
  HAL_TSU_STATE_RESET     = 0x00U,  /*!< TSU not yet initialized or disabled */
  HAL_TSU_STATE_READY     = 0x01U,  /*!< TSU initialized and ready for use   */
  HAL_TSU_STATE_BUSY      = 0x02U,  /*!< TSU initialized and ready for use   */
  HAL_TSU_STATE_SCANNING  = 0x03U,  /*!< TSU internal process is ongoing     */
  HAL_TSU_STATE_SCANNED   = 0x04U,  /*!< TSU internal process is ongoing     */
  HAL_TSU_STATE_TIMEOUT   = 0x05U,  /*!< TSU timeout state                   */
  HAL_TSU_STATE_ERROR     = 0x06U   /*!< TSU error state                     */
} HAL_TSU_StateTypeDef;

typedef enum
{
  HAL_TSU_ERROR_NONE      = 0x00U,  /*!< TSU not yet initialized or disabled */
  HAL_TSU_ERROR_OVERFLOW  = 0x01U,  /*!< TSU initialized and ready for use   */
  HAL_TSU_ERROR_ICOMP     = 0x02U,  /*!< TSU initialized and ready for use   */
  HAL_TSU_ERROR_ICOMP1    = 0x04U,  /*!< TSU internal process is ongoing     */
	HAL_TSU_ERROR_INVALID_CALLBACK = 0x80U
} HAL_TSU_ErrorTypeDef;

/**
  * @brief TSU Init Structure definition
  */
typedef struct 
{
  uint32_t TriggerMode;                 /*!< MSS */
	
//	uint32_t OperationClock;              /*!< DIV */
	
	//uint32_t PinCfg;                      /*!< Pin configure */

  uint32_t SensorPulseMode;             /*!< Sensor pulse mode. (CTRL0.SDPSEL) This parameter is a value of @ref TSU_SENSOR_DRIVE_PULSE_MODE*/

	uint32_t SpreadSpectrumEnable; 
	uint32_t SpreadSpectrumCnt;

	uint32_t PrnEnable; 
	uint32_t PrnGenerateCycle;
	uint32_t PrnUpdateCycle;
	
	uint32_t SUCLKSSMode;
	uint32_t SUCLKSSPeriod;

	uint32_t CcoBias;
	uint32_t CurrentMode;
	
	//uint32_t AfcDwaClock;

  uint32_t TuningEnable;               /*!< Offset tuning enable */

} TSU_InitTypeDef;

typedef struct __TSU_ScanTypeDef
{
    uint32_t  ScanNum;                   /*!< Number of scan */

    uint32_t  ChannelEnable;             /*!< enable channels */
    uint32_t  ChannleMode;               /*!< channles mode */

    uint32_t  ScanMode;                  /*!< self/mutual */
	
	uint32_t  ShieldOutput;              /*!< shield pin output mode */ 
	uint32_t  NonMeasureOutput;          /*!< non-measure pin output mode */
	
	uint32_t  FreqPattern;               /*!< frequency pattern */
	uint32_t  Freq[4];                   /*!< frequency */
	uint32_t  FreqJudgmentEnable;        /*!< frequency judgment enable */

	uint32_t  AutoJudgeEnable;           /*!< Auto judgment enable */
	uint32_t  AutoJudgeCondition;        /*!< Auto judgment condition */
	uint32_t  AutoCorrectionEnable;      /*!< Auto Correction enable */
	
	uint32_t  InterruptEnable;           /*!< CTSM interrupts enable */  
} TSU_ScanTypeDef;

typedef struct __TSU_AFCTypeDef
{
    uint32_t  AFCPeriod;                 /*!< AFC time \@us */

    uint32_t  SysClk;                    /*!< Sysyem clock */

    uint32_t  RefclkDivider;             /*!< set reference clock to 4M (HSE/divider) */
	
	uint32_t  Clock;                     /*!< Reference clock */
	
	uint32_t  Diff;
} TSU_AFCTypeDef;
/**
  * @brief  TSU Handle Structure definition
  */
typedef struct __TSU_HandleTypeDef
{
  TSU_TypeDef                          *Instance;          /*!< Register base address        */

  TSU_InitTypeDef                      Init;               /*!< TSU configuration parameters */

  HAL_LockTypeDef                      Lock;               /*!< TSU Locking object           */

  __IO HAL_TSU_StateTypeDef            State;              /*!< TSU communication state      */

//  HAL_TSU_TuningStateTypeDef           TuningState;        /*!< Offset tunning state */
  
//  TSU_ScanTypeDef                      ScanCtrl;           /*!<  */

  HAL_TSU_ErrorTypeDef                 ErrorCode;          /*!< Error */

  DMA_HandleTypeDef        *hdmatx;                  /*!< TSU result DMA Handle parameters      */

  DMA_HandleTypeDef        *hdmarx;                  /*!< TSU config DMA Handle parameters      */

#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
  void (* DMATxCpltCallback)(struct __TSU_HandleTypeDef *htsu);         /*!< TSU Tx Complete Callback             */
  void (* DMATxBlockCallback)(struct __TSU_HandleTypeDef *htsu);        /*!< TSU Tx Complete block Callback             */
  void (* DMATxSrcTranCallback)(struct __TSU_HandleTypeDef *htsu);      /*!< TSU Tx Complete source transaction Callback             */
  void (* DMATxDstTranCallback)(struct __TSU_HandleTypeDef *htsu);      /*!< TSU Tx Complete destination transaction Callback             */
  void (* DMARxCpltCallback)(struct __TSU_HandleTypeDef *htsu);         /*!< TSU Rx Complete Callback             */
  void (* DMARxBlockCallback)(struct __TSU_HandleTypeDef *htsu);        /*!< TSU Rx Complete block Callback             */
  void (* DMARxSrcTranCallback)(struct __TSU_HandleTypeDef *htsu);      /*!< TSU Rx Complete source transaction Callback             */
  void (* DMARxDstTranCallback)(struct __TSU_HandleTypeDef *htsu);      /*!< TSU Rx Complete destination transaction Callback             */
  void (* ErrorCallback)(struct __TSU_HandleTypeDef *htsu);             /*!< TSU Error Callback                   */
  void (* AbortCpltCallback)(struct __TSU_HandleTypeDef *htsu);         /*!< TSU Abort Complete Callback          */
  void (* AbortTransmitCpltCallback)(struct __TSU_HandleTypeDef *htsu); /*!< TSU Abort Transmit Complete Callback */
  void (* AbortReceiveCpltCallback)(struct __TSU_HandleTypeDef *htsu);  /*!< TSU Abort Receive Complete Callback  */
  void (* MeasurmentClpCallback)(struct __TSU_HandleTypeDef *htsu);     /*!< TSU measurement complete Callback     */
  void (* ScanClpCallback)(struct __TSU_HandleTypeDef *htsu);           /*!< TSU measurement complete Callback     */
  void (* JudgmentClpCallback)(struct __TSU_HandleTypeDef *htsu);       /*!< TSU measurement complete Callback     */
  void (* CorrectClpCallback)(struct __TSU_HandleTypeDef *htsu);       /*!< TSU measurement complete Callback     */

  void (* MspInitCallback)(struct __TSU_HandleTypeDef *htsu);           /*!< TSU Msp Init callback                */
  void (* MspDeInitCallback)(struct __TSU_HandleTypeDef *htsu);         /*!< TSU Msp DeInit callback              */
#endif  /* USE_HAL_TSU_REGISTER_CALLBACKS */

} TSU_HandleTypeDef;

#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL TSU Callback ID enumeration definition
  */
typedef enum
{
  HAL_TSU_ERROR_CB_ID                   = 0x00U,    /*!< TSU Error Callback ID                   */
  HAL_TSU_ABORT_CB_ID                   = 0x01U,    /*!< TSU Abort Callback ID                   */
  HAL_TSU_TXABORT_CB_ID                 = 0x02U,    /*!< TSU Tx Abort Callback ID                */
  HAL_TSU_RXABORT_CB_ID                 = 0x03U,    /*!< TSU Rx Abort Callback ID                */
  HAL_TSU_MEASUREEND_CB_ID              = 0x04U,    /*!< TSUMeasurement end Callback ID          */
  HAL_TSU_SCANEND_CB_ID                 = 0x05U,    /*!< TSUMeasurement end Callback ID          */
  HAL_TSU_JUDGMENTEND_CB_ID             = 0x06U,    /*!< TSUMeasurement end Callback ID          */
  HAL_TSU_CORRECTEND_CB_ID              = 0x07U,    /*!< TSUMeasurement end Callback ID          */

  HAL_TSU_MSPINIT_CB_ID                 = 0x10U,    /*!< TSU MspInit callback ID                 */
  HAL_TSU_MSPDEINIT_CB_ID               = 0x11U,    /*!< TSU MspDeInit callback ID               */

  HAL_TSU_DMATX_TFR_CB_ID               = 0x20U,    /*!< TSU Tx Complete Block Callback ID             */
  HAL_TSU_DMATX_BLOCK_CB_ID             = 0x21U,    /*!< TSU Tx Complete Block Callback ID             */
  HAL_TSU_DMATX_SRCTRAN_CB_ID           = 0x22U,    /*!< TSU Tx Complete Source Transaction Callback ID        */
  HAL_TSU_DMATX_DSTTRAN_CB_ID           = 0x23U,    /*!< TSU Tx Complete Destination Transaction Callback ID   */

  HAL_TSU_DMARX_TFR_CB_ID               = 0x30U,    /*!< TSU Rx Complete Block Callback ID             */
  HAL_TSU_DMARX_BLOCK_CB_ID             = 0x31U,    /*!< TSU Rx Complete Block Callback ID             */
  HAL_TSU_DMARX_SRCTRAN_CB_ID           = 0x32U,    /*!< TSU Rx Complete Source Transaction Callback ID        */
  HAL_TSU_DMARX_DSTTRAN_CB_ID           = 0x33U     /*!< TSU Rx Complete Destination Transaction Callback ID   */

} HAL_TSU_CallbackIDTypeDef;

/**
  * @brief  HAL TSU Callback pointer definition
  */
typedef  void (*pTSU_CallbackTypeDef)(TSU_HandleTypeDef *htsu); /*!< pointer to an TSU callback function */

#endif /* USE_HAL_TSU_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup TSU_Exported_Constants TSU Exported Constants
  * @{
  */
/** @defgroup TSU_CHANNEL_NUMBER TSU Channel Number
  * @{
  */
#define TSU_CHANNEL_NUMBER             (32)  
#define TSU_MEASUREMENT_MAX            (12)  
/**
  * @}
  */

/** @defgroup TSU_SCAN_START_STOP TSU Scan start or stop
  * @{
  */
#define TSU_SCAN_STOP                  (0x00000000U)                           /*!<  */
#define TSU_SCAN_START                 (TSU_DCTRL_STRT)                        /*!<  */
/**
  * @}
  */

/** @defgroup TSU_SCAN_TRIGGER TSU Scan Trigger
  * @{
  */
#define TSU_TRG_SOFTWARE               (0x00000000U)                           /*!<  */
#define TSU_TRG_EXTERNAL               (TSU_DCTRL_CAP)                         /*!<  */
/**
  * @}
  */

/** @defgroup TSU_POWER_ON_OFF  TSU Power on or off
  * @{
  */
#define TSU_POWER_OFF                  (0x00000000U)                           /*!<  */
#define TSU_POWER_ON                   (TSU_DCTRL_PON)                         /*!<  */
/**
  * @}
  */

/** @defgroup TSU_POWER_VOL TSU Power voltage
  * @{
  */
#define TSU_POWER_VOL_L2P4             (0x00000000U)                           /*!<  */
#define TSU_POWER_VOL_G2P4             (TSU_DCTRL_ATUNE0)                      /*!<  */
/**
  * @}
  */

/** @defgroup TSU_CURRENT_RANGE TSU Current Range
  * @{
  */
#define TSU_CURRENT_RANGE_80uA         (0x00000000U)                           /*!<  */
#define TSU_CURRENT_RANGE_40uA         (TSU_ACTRL_CMD_0)                       /*!<  */
#define TSU_CURRENT_RANGE_20uA         (TSU_ACTRL_CMD_1)                       /*!<  */
#define TSU_CURRENT_RANGE_160uA        (TSU_ACTRL_CMD_1 | TSU_ACTRL_CMD_0)     /*!<  */
/**
  * @}
  */

/** @defgroup TSU_SCAN_MODE TSU Scan Mode
  * @{
  */
#define TSU_SCAN_MODE_SINGLE           (0x00000000U)                           /*!<  */
#define TSU_SCAN_MODE_MULTI            (TSU_DCTRL_MD0)                         /*!<  */
/**
  * @}
  */

/** @defgroup TSU_MEAS_MODE TSU Measure Mode
  * @{
  */
#define TSU_MEAS_MODE_SELF             (0x00000000U)                           /*!<  */
#define TSU_MEAS_MODE_MUTUAL           (TSU_DCTRL_MD)                          /*!<  */
/**
  * @}
  */

/** @defgroup TSU_Measurement_Load TSU Measurement Load
  * @{
  */
#define TSU_MEAS_LOAD_CONS_NOR         (0x00000000U)                           /*!< Constant current load mode for normal measurement */
#define TSU_MEAS_LOAD_NO               (TSU_CTRL_LOAD_0)                       /*!< No load mode */
#define TSU_MEAS_LOAD_CONS_CALIB       (TSU_CTRL_LOAD_1)                       /*!< Constant current load mode for calibration */
#define TSU_MEAS_LOAD_RES_CALIB        (TSU_CTRL_LOAD_1 | TSU_CTRL_LOAD_0)     /*!< Resistive load mode for calibration */
/**
  * @}
  */

/** @defgroup TSU_SENSOR_DRIVE_PULSE_MODE TSU Sensor Driver Pulse Mode
  * @{
  */
#define TSU_SDPMODE_RANDOM             (0x00000000U)                           /*!< Random pulse mode */
#define TSU_SDPMODE_HIGHRESOLUTION     (TSU_DCTRL_SDPSEL)                      /*!< High resolution pulse mode */
/**
  * @}
  */

/** @defgroup TSU_PRN_PEROID TSU PRN Period
  * @{
  */
#define TSU_PRN_PERIOD_255             (0x00000000U)                           /*!< PRN generation cycle 255 */
#define TSU_PRN_PERIOD_63              (TSU_DCTRL_PHT_0)                       /*!< PRN generation cycle 63 */
#define TSU_PRN_PERIOD_31              (TSU_DCTRL_PHT_1)                       /*!< PRN generation cycle 31 */
#define TSU_PRN_PERIOD_3               (TSU_DCTRL_PHT_1 | TSU_DCTRL_PHT_0)     /*!< PRN generation cycle 3 */
/**
  * @}
  */

/** @defgroup TSU_PRN_UPDATE TSU PRN Update
  * @{
  */
#define TSU_PRN_UPDATE_1               (0x00000000U)                                                             /*!< PRN update cycle 1 */
#define TSU_PRN_UPDATE_2               (TSU_DCTRL_PHS_0)                                                         /*!< PRN update cycle 2 */
#define TSU_PRN_UPDATE_3               (TSU_DCTRL_PHS_1)                                                         /*!< PRN update cycle 3 */
#define TSU_PRN_UPDATE_4               (TSU_DCTRL_PHS_1 | TSU_DCTRL_PHS_0)                                       /*!< PRN update cycle 4 */
#define TSU_PRN_UPDATE_5               (TSU_DCTRL_PHS_2)                                                         /*!< PRN update cycle 5 */
#define TSU_PRN_UPDATE_6               (TSU_DCTRL_PHS_2 | TSU_DCTRL_PHS_0)                                       /*!< PRN update cycle 6 */
#define TSU_PRN_UPDATE_7               (TSU_DCTRL_PHS_2 | TSU_DCTRL_PHS_1)                                       /*!< PRN update cycle 7 */
#define TSU_PRN_UPDATE_8               (TSU_DCTRL_PHS_2 | TSU_DCTRL_PHS_1 | TSU_DCTRL_PHS_0)                     /*!< PRN update cycle 8 */
#define TSU_PRN_UPDATE_9               (TSU_DCTRL_PHS_3)                                                         /*!< PRN update cycle 9 */
#define TSU_PRN_UPDATE_10              (TSU_DCTRL_PHS_3 | TSU_DCTRL_PHS_0)                                       /*!< PRN update cycle 10 */
#define TSU_PRN_UPDATE_11              (TSU_DCTRL_PHS_3 | TSU_DCTRL_PHS_1)                                       /*!< PRN update cycle 11 */
#define TSU_PRN_UPDATE_12              (TSU_DCTRL_PHS_3 | TSU_DCTRL_PHS_1 | TSU_DCTRL_PHS_0)                     /*!< PRN update cycle 12 */
#define TSU_PRN_UPDATE_13              (TSU_DCTRL_PHS_3 | TSU_DCTRL_PHS_2)                                       /*!< PRN update cycle 13 */
#define TSU_PRN_UPDATE_14              (TSU_DCTRL_PHS_3 | TSU_DCTRL_PHS_2 | TSU_DCTRL_PHS_0)                     /*!< PRN update cycle 14 */
#define TSU_PRN_UPDATE_15              (TSU_DCTRL_PHS_3 | TSU_DCTRL_PHS_2 | TSU_DCTRL_PHS_1)                     /*!< PRN update cycle 15 */
#define TSU_PRN_UPDATE_16              (TSU_DCTRL_PHS_3 | TSU_DCTRL_PHS_2 | TSU_DCTRL_PHS_1 | TSU_DCTRL_PHS_0)   /*!< PRN update cycle 16 */
/**
  * @}
  */


/** @defgroup TSU_SS_Enable TSU SS Enable
  * @{
  */
#define TSU_SS_ENABLE                  (0x00000000U)                           /*!< Spread spectrum function enable */
#define TSU_SS_DISABLE                 (TSU_DCTRL_SOFF)                        /*!< Spread spectrum function disable */
/**
  * @}
  */

/** @defgroup TSU_PRN_Enable TSU PRN Enable
  * @{
  */
#define TSU_PRN_ENABLE                 (0x00000000U)                           /*!< PRN function enable */
#define TSU_PRN_DISABLE                (TSU_DCTRL_PROFF)                       /*!< PRN function disable */
/**
  * @}
  */

/** @defgroup TSU_SS_PERIOD TSU SS Period
  * @{
  */
#define TSU_SS_PERIOD_1                (0x00000000U)                                                               /*!< SS sampleing period SUCLK cycle 1 */
#define TSU_SS_PERIOD_2                (TSU_DIV_SSDIV_0)                                                           /*!< SS sampleing period SUCLK cycle 2 */
#define TSU_SS_PERIOD_3                (TSU_DIV_SSDIV_1)                                                           /*!< SS sampleing period SUCLK cycle 3 */
#define TSU_SS_PERIOD_4                (TSU_DIV_SSDIV_1 | TSU_DIV_SSDIV_0)                                         /*!< SS sampleing period SUCLK cycle 4 */
#define TSU_SS_PERIOD_5                (TSU_DIV_SSDIV_2)                                                           /*!< SS sampleing period SUCLK cycle 5 */
#define TSU_SS_PERIOD_6                (TSU_DIV_SSDIV_2 | TSU_DIV_SSDIV_0)                                         /*!< SS sampleing period SUCLK cycle 6 */
#define TSU_SS_PERIOD_7                (TSU_DIV_SSDIV_2 | TSU_DIV_SSDIV_1)                                         /*!< SS sampleing period SUCLK cycle 7 */
#define TSU_SS_PERIOD_8                (TSU_DIV_SSDIV_2 | TSU_DIV_SSDIV_1 | TSU_DIV_SSDIV_0)                       /*!< SS sampleing period SUCLK cycle 8 */
#define TSU_SS_PERIOD_9                (TSU_DIV_SSDIV_3)                                                           /*!< SS sampleing period SUCLK cycle 9 */
#define TSU_SS_PERIOD_10               (TSU_DIV_SSDIV_3 | TSU_DIV_SSDIV_0)                                         /*!< SS sampleing period SUCLK cycle 10 */
#define TSU_SS_PERIOD_11               (TSU_DIV_SSDIV_3 | TSU_DIV_SSDIV_1)                                         /*!< SS sampleing period SUCLK cycle 11 */
#define TSU_SS_PERIOD_12               (TSU_DIV_SSDIV_3 | TSU_DIV_SSDIV_1 | TSU_DIV_SSDIV_0)                       /*!< SS sampleing period SUCLK cycle 12 */
#define TSU_SS_PERIOD_13               (TSU_DIV_SSDIV_3 | TSU_DIV_SSDIV_2)                                         /*!< SS sampleing period SUCLK cycle 13 */
#define TSU_SS_PERIOD_14               (TSU_DIV_SSDIV_3 | TSU_DIV_SSDIV_2 | TSU_DIV_SSDIV_0)                       /*!< SS sampleing period SUCLK cycle 14 */
#define TSU_SS_PERIOD_15               (TSU_DIV_SSDIV_3 | TSU_DIV_SSDIV_2 | TSU_DIV_SSDIV_1)                       /*!< SS sampleing period SUCLK cycle 15 */
#define TSU_SS_PERIOD_16               (TSU_DIV_SSDIV_3 | TSU_DIV_SSDIV_2 | TSU_DIV_SSDIV_1 | TSU_DIV_SSDIV_0)     /*!< SS sampleing period SUCLK cycle 16 */
/**
  * @}
  */

/** @defgroup TSU_SUCLK_SS_CTRL TSU SUCLK SS Control
  * @{
  */
#define TSU_SUCLK_SS_CTRL_00           (0x00000000U)                                            /*!< SS frequenct adjust 00 */
#define TSU_SUCLK_SS_CTRL_04           (TSU_AD_SSCTRL_0)                                        /*!< SS frequenct adjust 20 */
#define TSU_SUCLK_SS_CTRL_08           (TSU_AD_SSCTRL_1)                                        /*!< SS frequenct adjust 40 */
#define TSU_SUCLK_SS_CTRL_0C           (TSU_AD_SSCTRL_1 | TSU_AD_SSCTRL_0)                      /*!< SS frequenct adjust 60 */
#define TSU_SUCLK_SS_CTRL_10           (TSU_AD_SSCTRL_2)                                        /*!< SS frequenct adjust 00 */
#define TSU_SUCLK_SS_CTRL_14           (TSU_AD_SSCTRL_2 | TSU_AD_SSCTRL_0)                      /*!< SS frequenct adjust 20 */
#define TSU_SUCLK_SS_CTRL_18           (TSU_AD_SSCTRL_2 | TSU_AD_SSCTRL_1)                      /*!< SS frequenct adjust 40 */
#define TSU_SUCLK_SS_CTRL_1C           (TSU_AD_SSCTRL_2 | TSU_AD_SSCTRL_1 | TSU_AD_SSCTRL_0)    /*!< SS frequenct adjust 60 */
/**
  * @}
  */

/** @defgroup TSU_MFC_SUCLK TSU Multiple Frequency Control
  * @{
  */
#define TSU_MFC_SUCLK0                 (0x00000000U)                           /*!< Multi-clock SUCLK0 */
#define TSU_MFC_SUCLK1                 (TSU_STAUS_MFC_0)                       /*!< Multi-clock SUCLK1 */
#define TSU_MFC_SUCLK2                 (TSU_STAUS_MFC_1)                       /*!< Multi-clock SUCLK2 */
#define TSU_MFC_SUCLK3                 (TSU_STAUS_MFC_1 | TSU_STAUS_MFC_0)     /*!< Multi-clock SUCLK3 */
/**
  * @}
  */

/** @defgroup TSU_STATE TSU Status
  * @{
  */
#define TSU_STATE_0                    (0x00000000U)                           /*!< TSU state 0 */
#define TSU_STATE_1                    (TSU_STAUS_STC_0)                       /*!< TSU state 1 */
#define TSU_STATE_2                    (TSU_STAUS_STC_1)                       /*!< TSU state 2 */
#define TSU_STATE_3                    (TSU_STAUS_STC_1 | TSU_STAUS_STC_0)     /*!< TSU state 3 */
#define TSU_STATE_4                    (TSU_STAUS_STC_2)                       /*!< TSU state 4 */
#define TSU_STATE_5                    (TSU_STAUS_STC_2 | TSU_STAUS_STC_0)     /*!< TSU state 5 */
/**
  * @}
  */

/** @defgroup TSU_FLAG TSU Flags
  * @{
  */
#define TSU_FLAG_OCUR                  (TSU_STAUS_ICOMP1)                      /*!< TSU over-current */
#define TSU_FLAG_OVOL                  (TSU_STAUS_ICOMP0)                      /*!< TSU over-voltage */
#define TSU_FLAG_NRD                   (TSU_STAUS_DTSR)                        /*!< TSU not read result */
#define TSU_FLAG_SCO                   (TSU_STAUS_SCOVF)                       /*!< TSU SC over */
#define TSU_FLAG_UCO                   (TSU_STAUS_UCOVF)                       /*!< TSU SUCLK over */
#define TSU_FLAG_PS                    (TSU_STAUS_PS)                          /*!< TSU mutual capacitance second measurement */
/**
  * @}
  */

/** @defgroup TSU_FREQ_JEN TSU Frequency Judgment Enable
  * @{
  */
#define TSU_FREQJUDGMENT_DISABLE       (0x00000000U)                           /*!< touch frequency judgment disable */
#define TSU_FREQJUDGMENT_ENABLE        (TSU_OPT_FREJFEN)                       /*!< touch grequency judgment enable */
/**
  * @}
  */

/** @defgroup TSU_TUNING_EN TSU Runing Enable
  * @{
  */
#define TSU_TUNING_DISABLE             (0x00000000U)                           /*!< touch tuning disable */
#define TSU_TUNING_ENABLE              (TSU_OPT_TUNEN)                         /*!< touch tuning enable */
/**
  * @}
  */

/** @defgroup TSU_AUTOJUDGMENT_EN TSU Auto Judgment Enable
  * @{
  */
#define TSU_AUTOJUDGMENT_DISABLE       (0x00000000U)                           /*!< touch auto judgment disable */
#define TSU_AUTOJUDGMENT_ENABLE        (TSU_OPT_AJFEN)                         /*!< touch auto judgment*/
/**
  * @}
  */

/** @defgroup TSU_CORRECTION_EN TSU Correction Enable
  * @{
  */
#define TSU_CORRECTION_DISABLE         (0x00000000U)                           /*!< touch auto judgment disable */
#define TSU_CORRECTION_ENABLE          (TSU_OPT_CCOCFEN)                       /*!< touch auto judgment*/
/**
  * @}
  */

/** @defgroup TSU_SUCLK_ENABLE TSU SUCLK Enable
  * @{
  */
#define TSU_SUCLK_DISABLE              (0x00000000U)                           /*!< SUCLK disable */
#define TSU_SUCLK_ENABLE               (TSU_CALIB_SUCLKEN)                     /*!< SUCLK enable */
/**
  * @}
  */

/** @defgroup TSU_AJC_COND TSU Audo Judgment Conditions
  * @{
  */
#define TSU_AJC_ONE                    (0x00000000U)                           /*!< One or more touch judgments */
#define TSU_AJC_TWO                    (TSU_AJC_JC_0)                          /*!< Two or more touch judgments */
#define TSU_AJC_THREE                  (TSU_AJC_JC_1)                          /*!< Three or more touch judgments */
#define TSU_AJC_FOUR                   (TSU_AJC_JC_1 | TSU_AJC_JC_0)           /*!< Four or more touch judgments */
/**
  * @}
  */

/** @defgroup TSU_SSDIV  TSU SS Divider
  * @{
  */
#define TSU_SSDIV_4000                 (00)                                   /*!< 4.00 <= Base clock frequency (MHz)        */
#define TSU_SSDIV_2000                 (01)                                   /*!< 2.00 <= Base clock frequency (MHz) < 4.00 */
#define TSU_SSDIV_1330                 (02)                                   /*!< 1.33 <= Base clock frequency (MHz) < 2.00 */
#define TSU_SSDIV_1000                 (03)                                   /*!< 1.00 <= Base clock frequency (MHz) < 1.33 */
#define TSU_SSDIV_0800                 (04)                                   /*!< 0.80 <= Base clock frequency (MHz) < 1.00 */
#define TSU_SSDIV_0670                 (05)                                   /*!< 0.67 <= Base clock frequency (MHz) < 0.80 */
#define TSU_SSDIV_0570                 (06)                                   /*!< 0.57 <= Base clock frequency (MHz) < 0.67 */
#define TSU_SSDIV_0500                 (07)                                   /*!< 0.50 <= Base clock frequency (MHz) < 0.57 */
#define TSU_SSDIV_0440                 (08)                                   /*!< 0.44 <= Base clock frequency (MHz) < 0.50 */
#define TSU_SSDIV_0400                 (09)                                   /*!< 0.40 <= Base clock frequency (MHz) < 0.44 */
#define TSU_SSDIV_0360                 (10)                                   /*!< 0.36 <= Base clock frequency (MHz) < 0.40 */
#define TSU_SSDIV_0330                 (11)                                   /*!< 0.33 <= Base clock frequency (MHz) < 0.36 */
#define TSU_SSDIV_0310                 (12)                                   /*!< 0.31 <= Base clock frequency (MHz) < 0.33 */
#define TSU_SSDIV_0290                 (13)                                   /*!< 0.29 <= Base clock frequency (MHz) < 0.31 */
#define TSU_SSDIV_0270                 (14)                                   /*!< 0.27 <= Base clock frequency (MHz) < 0.29 */
#define TSU_SSDIV_0000                 (15)                                   /*!< 0.00 <= Base clock frequency (MHz) < 0.27 */
/**
  * @}
  */

/** @defgroup TSU_EVENT TSU Event
  * @{
  */
#define TSU_EVT_MRRD                   (TSUSYS_C2HEVT_MRRD)                    /*!< TSU read messurement result */
#define TSU_EVT_MARRD                  (TSUSYS_C2HEVT_MARRD)                   /*!< TSU read average result */
#define TSU_EVT_JRRD                   (TSUSYS_C2HEVT_JRRD)                    /*!< TSU read judgment result */
#define TSU_EVT_BUSY                   (TSUSYS_C2HEVT_BUSY)                    /*!< TSU busy */
#define TSU_EVT_MCLPT                  (TSUSYS_C2HEVT_MCPLT)                   /*!< TSU measurement completed */
#define TSU_EVT_SCANCPLT               (TSUSYS_C2HEVT_SCPLT)                   /*!< TSU scan completed */
#define TSU_EVT_JCPLT                  (TSUSYS_C2HEVT_JCPLT)                   /*!< TSU judgment completed */
#define TSU_EVT_ERROR                  (TSUSYS_C2HEVT_ERROR)                   /*!< TSU error */
#define TSU_EVT_IDLE                   (TSUSYS_C2HEVT_IDLE)                    /*!< TSU idle */
#define TSU_EVT_CORRCPLT               (TSUSYS_C2HEVT_CORRCPLT)                /*!< TSU correction completed */
#define TSU_EVT_TCORRCPLT              (TSUSYS_C2HEVT_TCORRCPLT)               /*!< TSU temperature correction completed */
/**
  * @}
  */

/** @defgroup TSU_RESULT TSU Result
  * @{
  */
#define TSU_MRSLT_BASE                 (0x8002C000UL)
#define TSU_MRSLT_SIZE                 (0x1F0UL) 
#define TSU_JRSLT_BASE                 (0x8002C1F0UL)
#define TSU_JRSLT_SIZE                 (0x10UL) 
/**
  * @}
  */

/** @defgroup TSU_SYSCLK TSU System Clock
  * @{
  */
#define TSU_SYSCLK_1M                  (0)
#define TSU_SYSCLK_2M                  (TSU_OPT_SYSCLK_0)
#define TSU_SYSCLK_4M                  (TSU_OPT_SYSCLK_1)
#define TSU_SYSCLK_8M                  (TSU_OPT_SYSCLK_1|TSU_OPT_SYSCLK_0)
#define TSU_SYSCLK_16M                 (TSU_OPT_SYSCLK_2)
#define TSU_SYSCLK_32M                 (TSU_OPT_SYSCLK_2|TSU_OPT_SYSCLK_0)
#define TSU_SYSCLK_64M                 (TSU_OPT_SYSCLK_2|TSU_OPT_SYSCLK_1)
/**
  * @}
  */
	
/** @defgroup TSU_AFC_REFCLK TSU AFC Reference Clock
  * @{
  */
#define TSU_AFC_REFCLK_SUCLK           (0)
#define TSU_AFC_REFCLK_CCOCLK          (TSU_AFCCFG_CBCLKS)
/**
  * @}
  */

/** @defgroup TSU_PS_ShieldOutput TSU PS Shield Output
  * @{
  */
#define TSU_PS_SHIELD_OUTPUT_0         (0)
#define TSU_PS_SHIELD_OUTPUT_1         (TSU_PS_SHDPSEL_0)
#define TSU_PS_SHIELD_OUTPUT_PULSE     (TSU_PS_SHDPSEL_1)
/**
  * @}
  */

/** @defgroup TSU_PS_NonMeasureOutput TSU PS Non-Measurement Output
  * @{
  */
#define TSU_PS_NONMEASURE_OUTPUT_0     (0)
#define TSU_PS_NONMEASURE_OUTPUT_1     (TSU_PS_NMPSEL_0)
#define TSU_PS_NONMEASURE_OUTPUT_PULSE (TSU_PS_NMPSEL_1)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup TSU_Exported_Macros TSU Exported Macros
  * @{
  */

/** @brief Reset TSU handle state.
  * @param  __HANDLE__ TSU handle.
  * @retval None
  */
#define __HAL_TSU_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_TSU_STATE_RESET)

/** @brief Get Sensor Counter Overflow FLag.
  * @param  __HANDLE__ TSU handle.
  * @retval SCOVF
  */
#define __HAL_TSU_GETSCOVF(__HANDLE__) (READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_SCOVF))

/** @brief Get Sensor Unit Counter Overflow FLag.
  * @param  __HANDLE__ TSU handle.
  * @retval UCOVF
  */
#define __HAL_TSU_GETUCOVF(__HANDLE__) (READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_UCOVF))

/** @brief Get Over-Current FLag.
  * @param  __HANDLE__ TSU handle.
  * @retval ICOMP1
  */
#define __HAL_TSU_GETICOMP1(__HANDLE__) (READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_ICOMP1))

/** @brief Get Over-Voltage FLag.
  * @param  __HANDLE__ TSU handle.
  * @retval ICOMP2
  */
#define __HAL_TSU_GETICOMP0(__HANDLE__) (READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_ICOMP0))

/** @brief Clear Over-Voltage & Over-Current FLag.
  * @param  __HANDLE__ TSU handle.
  * @retval None
  */
#define __HAL_TSU_CLEARICOMP(__HANDLE__) (SET_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_ICOMPRST))

/** @brief Clear Sensor Counter Overflow FLag.
  * @param  __HANDLE__ TSU handle.
  * @retval None
  */
#define __HAL_TSU_CLEARSCOVF(__HANDLE__) (CLEAR_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_SCOVF))

/** @brief CLear Sensor Unit Counter Overflow FLag.
  * @param  __HANDLE__ TSU handle.
  * @retval None
  */
#define __HAL_TSU_CLEARUCOVF(__HANDLE__) (CLEAR_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_UCOVF))

/** @brief Check Sencond measurement for each channel in mutual capacitance method (MD1 = 1) .
  * @param  __HANDLE__ TSU handle.
  * @retval SET or RESET
  */
#define __HAL_TSU_IS_2NDMEAS_MUTUALCAP(__HANDLE__) ((READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_PS)) ? SET : RESET)

/** @brief Check measurement stop for each channel in self capacitance method (MD1 = 0) .
  * @param  __HANDLE__ TSU handle.
  * @retval SET or RESET
  */
#define __HAL_TSU_IS_MEASSTOP_SELFCAP(__HANDLE__) ((READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_PS)) ? RESET : SET)

/** @brief Check SCNT is read.
  * @param  __HANDLE__ TSU handle.
  * @retval SET or RESET
  */
#define __HAL_TSU_IS_READ_RESULT(__HANDLE__) ((READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_DTSR)) ? RESET : SET)

/** @brief Get SUCLK number.
  * @param  __HANDLE__ TSU handle.
  * @retval SUCLKx
  */
#define __HAL_TSU_GETSUCLKIDX(__HANDLE__) (READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_MFC) >> TSU_STAUS_MFC_Pos)

/** @brief Get Measurement status.
  * @param  __HANDLE__ TSU handle.
  * @retval SUCLKx
  */
#define __HAL_TSU_GETMeasureStatus(__HANDLE__) (READ_BIT((__HANDLE__)->Instance->STATUS, TSU_STAUS_STC) >> TSU_STAUS_STC_Pos)

/** @brief CTSM enable.
  * @param  None
  * @retval None
  */
#define __HAL_TSU_ENABLE()   SET_BIT(SYSCFG->CTSM_CTRL, SYSCFG_CTSM_CTRL_EN)

/** @brief CTSM disable.
  * @param  None
  * @retval None
  */
#define __HAL_TSU_DISABLE()  CLEAR_BIT(SYSCFG->CTSM_CTRL, SYSCFG_CTSM_CTRL_EN)

/**
  * @}
  */


/* Private macros --------------------------------------------------------*/
/** @defgroup  TSU_Private_Macros TSU Private Macros
  * @{
  */

#define IS_TSU_POL(LENGTH)            (((LENGTH) == TSU_POLY_32)    || \
                                       ((LENGTH) == TSU_POLY_8)     || \
                                       ((LENGTH) == TSU_POLY_16_0)  || \
                                       ((LENGTH) == TSU_POLY_16_1))

#define IS_TSU_INPUTDATA_FORMAT(FORMAT)           (((FORMAT) == TSU_INPUTDATA_FORMAT_BYTES)     || \
                                                   ((FORMAT) == TSU_INPUTDATA_FORMAT_HALFWORDS) || \
                                                   ((FORMAT) == TSU_INPUTDATA_FORMAT_WORDS))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup TSU_Exported_Functions TSU Exported Functions
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
/** @defgroup TSU_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
HAL_StatusTypeDef HAL_TSU_Init(TSU_HandleTypeDef *htsu);
HAL_StatusTypeDef HAL_TSU_DeInit(TSU_HandleTypeDef *htsu);
void HAL_TSU_MspInit(TSU_HandleTypeDef *htsu);
void HAL_TSU_MspDeInit(TSU_HandleTypeDef *htsu);

HAL_StatusTypeDef HAL_TSU_LinkDMA(TSU_HandleTypeDef *htsu, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx);

#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_TSU_RegisterCallback(TSU_HandleTypeDef *htsu, HAL_TSU_CallbackIDTypeDef CallbackID,
                                            pTSU_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_TSU_UnRegisterCallback(TSU_HandleTypeDef *htsu, HAL_TSU_CallbackIDTypeDef CallbackID);

#endif /* USE_HAL_TSU_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Peripheral Control functions ***********************************************/
/** @defgroup TSU_Exported_Functions_Group2 Peripheral Control functions
  * @{
  */
HAL_StatusTypeDef HAL_TSU_ScanConfig(TSU_HandleTypeDef *htsu, TSU_ScanTypeDef *scancfg);
HAL_StatusTypeDef HAL_TSU_AFCConfig(TSU_HandleTypeDef *htsu, TSU_AFCTypeDef *afccfg);

HAL_StatusTypeDef HAL_TSU_NormalScanStart(TSU_HandleTypeDef *htsu);
HAL_StatusTypeDef HAL_TSU_CorrectScanStart(TSU_HandleTypeDef *htsu);
HAL_StatusTypeDef HAL_TSU_TempCorrectScanStart(TSU_HandleTypeDef *htsu);
HAL_StatusTypeDef HAL_TSU_CurrentScanStart(TSU_HandleTypeDef *htsu);
HAL_StatusTypeDef HAL_TSU_IntCurrentScanStart(TSU_HandleTypeDef *htsu);
HAL_StatusTypeDef HAL_TSU_ScanStop(TSU_HandleTypeDef *htsu);
HAL_StatusTypeDef HAL_TSU_IsBusy(TSU_HandleTypeDef *htsu);

HAL_StatusTypeDef HAL_TSU_AFCStart(TSU_HandleTypeDef *htsu);

uint32_t HAL_TSU_MeasureDataGet(uint32_t* pBuffer, uint32_t size);
uint32_t HAL_TSU_AutoJudgmentDataGet(uint32_t* pBuffer, uint32_t size);

HAL_StatusTypeDef HAL_TSU_JudgInit(TSU_HandleTypeDef *htsu);
HAL_StatusTypeDef HAL_TSU_SensorOffsetInit(TSU_HandleTypeDef *htsu);
/**
  * @}
  */

/** @defgroup TSU_Exported_Functions_Group3 IRQ handle and interrupt functions
  * @{
  */
void HAL_TSU_IRQHandler(TSU_HandleTypeDef *htsu);
void HAL_TSU_TxCpltCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_RxCpltCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_ErrorCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_AbortCpltCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_AbortTransmitCpltCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_AbortReceiveCpltCallback(TSU_HandleTypeDef *htsu);
//void HAL_TSU_ConfigureRequestCallback(TSU_HandleTypeDef *htsu);
//void HAL_TSU_ReadResultCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_MeasurmentEndCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_MeasurmentAllChannelEndCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_ScanEndCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_JudgmentEndCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_CorrectEndCallback(TSU_HandleTypeDef *htsu);
void HAL_TSU_TempCorrectEndCallback(TSU_HandleTypeDef *htsu);
/**
  * @}
  */

/* Peripheral State and Error functions ***************************************/
/** @defgroup TSU_Exported_Functions_Group4 Peripheral State functions
  * @{
  */
HAL_TSU_StateTypeDef HAL_TSU_GetState(TSU_HandleTypeDef *htsu);
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

#endif /* XT32H0xx_HAL_TSU_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
