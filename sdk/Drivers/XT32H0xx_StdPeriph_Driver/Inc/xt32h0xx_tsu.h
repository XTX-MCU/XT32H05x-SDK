/**
  ******************************************************************************
  * @file    xt32h0xx_tsu.h
  * @author  Software Team
  * @date    29 November 2022
  * @brief   This file contains all the functions prototypes for the TSU firmware 
  *          library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_TSU_H
#define __XT32H0XX_TSU_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
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
  * @brief TSU Init Structure definition
  */
typedef struct 
{
  uint32_t TriggerMode;                 /*!< MSS */

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
	
  uint32_t TuningEnable;               /*!< Offset tuning enable */
} TSU_InitTypeDef;

typedef struct __TSU_ScanTypeDef
{
  uint16_t  ScanNum;                   /*!< Number of scan */

  uint32_t  ChannelEnable;             /*!< enable channels */
  uint32_t  ChannleMode;               /*!< channles mode */

  uint32_t  ScanMode;                  /*!< self/mutual */
	
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
  uint16_t  AFCPeriod;                 /*!< AFC time \@us */

  uint32_t  SysClk;                    /*!< Sysyem clock */

  uint32_t  RefclkDivider;             /*!< set reference clock to 4M (HSE/divider) */
	
	uint32_t  Clock;                     /*!< Reference clock */
	
	uint32_t  Diff;
} TSU_AFCTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup TSU_Exported_Constants TSU Exported Constants
  * @{
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

/** @defgroup TSU_SCAN_MODE TSU Scan Mode
  * @{
  */
#define TSU_SCAN_MODE_SINGLE           (0x00000000U)                           /*!< single scan */
#define TSU_SCAN_MODE_MULTI            (TSU_DCTRL_MD0)                         /*!< multiple scan */
/**
  * @}
  */

/** @defgroup TSU_MEAS_MODE TSU Measure Mode
  * @{
  */
#define TSU_MEAS_MODE_SELF             (0x00000000U)                           /*!< self capacitance */
#define TSU_MEAS_MODE_MUTUAL           (TSU_DCTRL_MD)                          /*!< mutual capacitance */
/**
  * @}
  */

/** @defgroup TSU_FREQ_JEN TSU Trequency Judgment Control
  * @{
  */
#define TSU_FREQJUDGMENT_DISABLE       (0x00000000U)                           /*!< touch frequency judgment disable */
#define TSU_FREQJUDGMENT_ENABLE        (TSU_OPT_FREJFEN)                       /*!< touch grequency judgment enable */
/**
  * @}
  */

/** @defgroup TSU_AUTOJUDGMENT_EN TSU Auto Judgment Control
  * @{
  */
#define TSU_AUTOJUDGMENT_DISABLE       (0x00000000U)                           /*!< touch auto judgment disable */
#define TSU_AUTOJUDGMENT_ENABLE        (TSU_OPT_AJFEN)                         /*!< touch auto judgment*/
/**
  * @}
  */

/** @defgroup TSU_CORRECTION_EN TSU correction Control
  * @{
  */
#define TSU_CORRECTION_DISABLE       (0x00000000U)                             /*!< touch auto judgment disable */
#define TSU_CORRECTION_ENABLE        (TSU_OPT_CCOCFEN)                         /*!< touch auto judgment*/
/**
  * @}
  */

/** @defgroup TSU_AJC_COND TSU Auto Judgment Condition
  * @{
  */
#define TSU_AJC_ONE                    (0x00000000U)                           /*!< One or more touch judgments */
#define TSU_AJC_TWO                    (TSU_AJC_JC_0)                          /*!< Two or more touch judgments */
#define TSU_AJC_THREE                  (TSU_AJC_JC_1)                          /*!< Three or more touch judgments */
#define TSU_AJC_FOUR                   (TSU_AJC_JC_1 | TSU_AJC_JC_0)           /*!< Four or more touch judgments */
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

/** @defgroup TSU_SENSOR_DRIVE_PULSE_MODE TSU Sensor Drive Pulse Mode
  * @{
  */
#define TSU_SDPMODE_RANDOM             (0x00000000U)                           /*!< Random pulse mode */
#define TSU_SDPMODE_HIGHRESOLUTION     (TSU_DCTRL_SDPSEL)                      /*!< High resolution pulse mode */
/**
  * @}
  */

/** @defgroup TSU_PRN_PERIOD TSU PRN Period
  * @{
  */
#define TSU_PRN_PERIOD_255             (0x00000000U)                           /*!< PRN generation cycle 255 */
#define TSU_PRN_PERIOD_63              (TSU_DCTRL_PHT_0)                       /*!< PRN generation cycle 63 */
#define TSU_PRN_PERIOD_31              (TSU_DCTRL_PHT_1)                       /*!< PRN generation cycle 31 */
#define TSU_PRN_PERIOD_3               (TSU_DCTRL_PHT_1 | TSU_DCTRL_PHT_0)     /*!< PRN generation cycle 3 */
/**
  * @}
  */

/** @defgroup TSU_PRN_UPDATE TSU PRN Update Cycles
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


/** @defgroup TSU_SS_Enable TSU SS Control
  * @{
  */
#define TSU_SS_ENABLE                  (0x00000000U)                           /*!< Spread spectrum function enable */
#define TSU_SS_DISABLE                 (TSU_DCTRL_SOFF)                        /*!< Spread spectrum function disable */
/**
  * @}
  */

/** @defgroup TSU_PRN_Enable TSU PRN Control
  * @{
  */
#define TSU_PRN_ENABLE                 (0x00000000U)                           /*!< PRN function enable */
#define TSU_PRN_DISABLE                (TSU_DCTRL_PROFF)                       /*!< PRN function disable */
/**
  * @}
  */

/** @defgroup TSU_SS_PERIOD TSU SS Period Cycles
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
#define TSU_SUCLK_SS_CTRL_00           (0x00000000U)                                           /*!< SS frequenct adjust 00 */
#define TSU_SUCLK_SS_CTRL_04           (TSU_AD_SSCTRL_0)                                       /*!< SS frequenct adjust 20 */
#define TSU_SUCLK_SS_CTRL_08           (TSU_AD_SSCTRL_1)                                       /*!< SS frequenct adjust 40 */
#define TSU_SUCLK_SS_CTRL_0C           (TSU_AD_SSCTRL_1 | TSU_AD_SSCTRL_0)                     /*!< SS frequenct adjust 60 */
#define TSU_SUCLK_SS_CTRL_10           (TSU_AD_SSCTRL_2)                                       /*!< SS frequenct adjust 00 */
#define TSU_SUCLK_SS_CTRL_14           (TSU_AD_SSCTRL_2 | TSU_AD_SSCTRL_0)                     /*!< SS frequenct adjust 20 */
#define TSU_SUCLK_SS_CTRL_18           (TSU_AD_SSCTRL_2 | TSU_AD_SSCTRL_1)                     /*!< SS frequenct adjust 40 */
#define TSU_SUCLK_SS_CTRL_1C           (TSU_AD_SSCTRL_2 | TSU_AD_SSCTRL_1 | TSU_AD_SSCTRL_0)   /*!< SS frequenct adjust 60 */
/**
  * @}
  */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup TSU_Exported_Functions
  * @{
  */

/** @addtogroup TSU_Exported_Functions_Group1
  * @{
  */
void TSU_DeInit(void);
void TSU_Init(TSU_InitTypeDef* TSU_InitStruct);
void TSU_StructInit(TSU_InitTypeDef* TSU_InitStruct);
/**
  * @}
  */

/** @addtogroup TSU_Exported_Functions_Group2
  * @{
  */
void TSU_ScanConfig(TSU_ScanTypeDef* TSU_ScanCfg);
void TSU_StructScanCfg(TSU_ScanTypeDef* TSU_ScanCfg);
void TSU_AFCConfig(TSU_AFCTypeDef* TSU_AfcCfg); 
void TSU_StructAfcCfg(TSU_AFCTypeDef* TSU_AfcCfg); 

void TSU_NormalScanStart(void);
void TSU_CorrectScanStart(void);
void TSU_TempCorrectScanStart(void);
void TSU_CurrentScanStart(void);
void TSU_IntCurrentScanStart(void);

void TSU_ScanStop(void);

void TSU_IsBusy(void);

void TSU_AFCStart(void);

uint32_t TSU_MeasureDataGet(uint32_t* pBuffer, uint32_t size);
uint32_t TSU_AutoJudgmentDataGet(uint32_t* pBuffer, uint32_t size);
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

#endif /* __XT32H0XX_TSU_H */


