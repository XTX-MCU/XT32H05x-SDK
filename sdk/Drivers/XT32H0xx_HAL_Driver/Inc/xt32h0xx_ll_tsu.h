/**
  ******************************************************************************
  * @file    xt32h0xx_ll_tsu.h
  * @author  Software Team
  * @brief   Header file of TSU LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_TSU_H
#define XT32H0xx_LL_TSU_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined(TSU)

/** @defgroup TSU_LL TSU
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup TSU_LL_Exported_Constants TSU Exported Constants
  * @{
  */

/** @defgroup TSU_LL_EC_AFC AFC interrupt enable 
  * @{
  */
#define LL_TSU_AFC_CDEIE_DISABLE       (0x00000000U)                           /*!< AFC CDE interrupt disable */
#define LL_TSU_AFC_CDEIE_ENABLE        (TSU_DCTRL_CDEIE)                       /*!< AFC CDE interrupt enable */

#define LL_TSU_AFC_ADEIE_DISABLE       (0x00000000U)                           /*!< AFC ADE interrupt disable */
#define LL_TSU_AFC_ADEIE_ENABLE        (TSU_DCTRL_ADEIE)                       /*!< AFC ADE interrupt enable */

#define LL_TSU_AFC_AEIE_DISABLE        (0x00000000U)                           /*!< AFC AE interrupt disable */
#define LL_TSU_AFC_AEIE_ENABLE         (TSU_DCTRL_AEIE)                        /*!< AFC AE interrupt enable */

#define LL_TSU_AFC_ANIE_DISABLE        (0x00000000U)                           /*!< AFC AN interrupt disable */
#define LL_TSU_AFC_ANIE_ENABLE         (TSU_DCTRL_ANIE)                        /*!< AFC AN interrupt enable */

#define LL_TSU_AFC_ALIE_DISABLE        (0x00000000U)                           /*!< AFC AL interrupt disable */
#define LL_TSU_AFC_ALIE_ENABLE         (TSU_DCTRL_ALIE)                        /*!< AFC AL interrupt enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC TSU interrupt enable 
  * @{
  */
#define LL_TSU_SCOIE_DISABLE           (0x00000000U)                           /*!< TSU SCO interrupt disable */
#define LL_TSU_SCOIE_ENABLE            (TSU_DCTRL_SCOIE)                       /*!< TSU SCO interrupt enable */

#define LL_TSU_UCOIE_DISABLE           (0x00000000U)                           /*!< TSU UCO interrupt disable */
#define LL_TSU_UCOIE_ENABLE            (TSU_DCTRL_UCOIE)                       /*!< TSU UCO interrupt enable */

#define LL_TSU_MDIE_DISABLE            (0x00000000U)                           /*!< TSU MD interrupt disable */
#define LL_TSU_MDIE_ENABLE             (TSU_DCTRL_MDIE)                        /*!< TSU MD interrupt enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_PRN Pseudo-random number off
  * @{
  */
#define LL_TSU_PRN_OFF                 (TSU_DCTRL_PROFF)                       /*!< Pseudo-random number off */
#define LL_TSU_PRN_ON                  (0x00000000UL)                          /*!< Pseudo-random number on */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_SS Spread-spectrum off
  * @{
  */
#define LL_TSU_SS_OFF                  (TSU_DCTRL_SOFF)                        /*!< Spread-spectrum off */
#define LL_TSU_SS_ON                   (0x00000000UL)                          /*!< Spread-spectrum on */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_PRN_GenCyc  Pseudo-random number generation cycles
  * @{
  */
#define LL_TSU_PHT_255                 (0)                                     /*!< TSU Pseudo-random number generating cycles 255 */
#define LL_TSU_PHT_63                  (TSU_DCTRL_PHT_0)                       /*!< TSU Pseudo-random number generating cycles 63 */
#define LL_TSU_PHT_31                  (TSU_DCTRL_PHT_1)                       /*!< TSU Pseudo-random number generating cycles 31 */
#define LL_TSU_PHT_3                   (TSU_DCTRL_PHT_1|TSU_DCTRL_PHT_0)       /*!< TSU Pseudo-random number generating cycles 3 */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Sensor_Driver_Pulse Sensor driver pulse
  * @{
  */
#define LL_TSU_SDPSEL_RPM              (0)                                     /*!< Sensor driver pulse */
#define LL_TSU_SDPSEL_HRPM             (TSU_DCTRL_SDPSEL)                      /*!< Sensor driver pulse high resolution */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Measurement_Mode Measurement Mode
  * @{
  */
#define LL_TSU_MD_SELF                 (0)                                     /*!< Self-capacitance */
#define LL_TSU_MD_MUTUAL               (TSU_DCTRL_MD)                          /*!< Mutual-capacitance */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Scan_Mode Scan Mode
  * @{
  */
#define LL_TSU_MD0_SINGLESCAN          (0)                                     /*!< Single scan  */
#define LL_TSU_MD0_MULTISCAN           (TSU_DCTRL_MD0)                         /*!< Multiple scan  */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_CTS_DWA CTS DWA enable
  * @{
  */
#define LL_TSU_CTS_DWA_DISABLE         (0)                                     /*!< CTS DWA disable */
#define LL_TSU_CTS_DWA_ENABLE          (TSU_DCTRL_CTSDWAEN)                    /*!< CTS DWA enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_AFC_DWA AFC DWA enable
  * @{
  */
#define LL_TSU_AFC_DWA_DISABLE         (0)                                     /*!< AFC DWA disable */
#define LL_TSU_AFC_DWA_ENABLE          (TSU_DCTRL_AFCDWAEN)                    /*!< AFC DWA enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_AFC_mode AFC enable
  * @{
  */
#define LL_TSU_AFC_DISABLE             (0)                                     /*!< AFC disable */
#define LL_TSU_AFC_ENABLE              (TSU_DCTRL_AFCEN)                       /*!< AFC enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_STRT Start
  * @{
  */
#define LL_TSU_STOP                    (0)                                     /*!< Measurement stop */
#define LL_TSU_START                   (TSU_DCTRL_STRT)                        /*!< Measurement start */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Shield Shield pin
  * @{
  */
#define LL_TSU_SHIELD_NONE             (0)                                     /*!< Shield pin disable */
#define LL_TSU_SHIELD                  (TSU_PS_SHD)                            /*!< Shield pin enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Tx_Invert Tx invert
  * @{
  */
#define LL_TSU_TXINV_NONE              (0)                                     /*!< TX invert disable */
#define LL_TSU_TXINV                   (TSU_PS_TXINV)                          /*!< TX invert enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Shield_Output Shield ouput
  * @{
  */
#define LL_TSU_SHIELD_OUTPUT_0         (0)                                     /*!< Shield pin outputs 0 */
#define LL_TSU_SHIELD_OUTPUT_1         (TSU_PS_SHDPSEL_0)                      /*!< Shield pin outputs 1 */
#define LL_TSU_SHIELD_OUTPUT_PULSE     (TSU_PS_SHDPSEL_1)                      /*!< Shield pin outputs pulses */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Non_Measurement_Output Non measurement pin ouput
  * @{
  */
#define LL_TSU_NONMEAS_OUTPUT_0        (0)                                     /*!< Non measurement pin outputs 0 */
#define LL_TSU_NONMEAS_OUTPUT_1        (TSU_PS_NMPSEL_0)                       /*!< Non measurement pin outputs 1 */
#define LL_TSU_NONMEAS_OUTPUT_PULSE    (TSU_PS_NMPSEL_1)                       /*!< Non measurement pin outputs pulses */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Status Measure status
  * @{
  */
#define LL_TSU_MEAS_STATUS_IDLE        (0)                                         /*!< measurement status idle */
#define LL_TSU_MEAS_STATUS_WAIT_1      (TSU_SR_STC_0)                              /*!< measurement status wait 1 */
#define LL_TSU_MEAS_STATUS_MEAS_1      (TSU_SR_STC_1)                              /*!< measurement status measure 1 */
#define LL_TSU_MEAS_STATUS_SYNC_1      (TSU_SR_STC_1|TSU_SR_STC_0)                 /*!< measurement status sync 1 */
#define LL_TSU_MEAS_STATUS_READ_1      (TSU_SR_STC_2)                              /*!< measurement status read 1 */
#define LL_TSU_MEAS_STATUS_WAIT_2      (TSU_SR_STC_2|TSU_SR_STC_0)                 /*!< measurement status wait 2 */
#define LL_TSU_MEAS_STATUS_MEAS_2      (TSU_SR_STC_2|TSU_SR_STC_1)                 /*!< measurement status measure 2 */
#define LL_TSU_MEAS_STATUS_SYNC_2      (TSU_SR_STC_2|TSU_SR_STC_1|TSU_SR_STC_0)    /*!< measurement status sync 2 */
#define LL_TSU_MEAS_STATUS_READ_2      (TSU_SR_STC_3)                              /*!< measurement status read 2 */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_channel CHANNEL enable
  * @{
  */
#define LL_TSU_CHANNEL_DISABLE         (0)                                     /*!< measure channel disable */
#define LL_TSU_CHANNEL_ENABLE          (1)                                     /*!< measure channel enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Channel_Mode CHANNEL Mode
  * @{
  */
#define LL_TSU_CHANNEL_RECEIVE         (0)                                     /*!< measurement channel mode: receive */
#define LL_TSU_CHANNEL_TRANSMIT        (1)                                     /*!< measurement channel mode: transmit */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Load_Mode Load mode
  * @{
  */
#define LL_TSU_LOADMODE_CC_NORMAL      (0)                                     /*!< Load mode: current normal */
#define LL_TSU_LOADMODE_NOLOAD         (TSU_ACTRL_LOAD_0)                      /*!< Load mode: moload */
#define LL_TSU_LOADMODE_CC_CALIB       (TSU_ACTRL_LOAD_1)                      /*!< Load mode: current calibrate */
#define LL_TSU_LOADMODE_RES_CALIB      (TSU_ACTRL_LOAD_1|TSU_ACTRL_LOAD_0)     /*!< Load mode: resistance calibrate */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Current_Range current range
  * @{
  */
#define LL_TSU_CURRENT_RANGE_80        (0)                                     /*!< current range 80uA */
#define LL_TSU_CURRENT_RANGE_40        (TSU_ACTRL_CMD_0)                       /*!< current range 40uA */
#define LL_TSU_CURRENT_RANGE_20        (TSU_ACTRL_CMD_1)                       /*!< current range 20uA */
#define LL_TSU_CURRENT_RANGE_160       (TSU_ACTRL_CMD_1|TSU_ACTRL_CMD_0)       /*!< current range 160uA */
/** 
  * @}
  */

/** @defgroup TSU_LL_EC_Load_Resistance load resistance
  * @{
  */
#define LL_TSU_LOADRES_10              (0)                                     /*!< load resistance 10 */
#define LL_TSU_LOADRES_20              (TSU_ACTRL_CMD_0)                       /*!< load resistance 20 */
#define LL_TSU_LOADRES_40              (TSU_ACTRL_CMD_1)                       /*!< load resistance 40 */
#define LL_TSU_LOADRES_5               (TSU_ACTRL_CMD_1|TSU_ACTRL_CMD_0)       /*!< load resistance 5 */
/** 
  * @}
  */

/** @defgroup TSU_LL_EC_CCO_Bais CCO bais
  * @{
  */
#define LL_TSU_CCO_BAIS_REFER          (0)                                     /*!< CCP baise reference */
#define LL_TSU_CCO_BAIS_SENSE          (TSU_ACTRL_CCOBS)                       /*!< CCP baise sensor */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Tuning_Control tuning control for the over current detect
  * @{
  */
#define LL_TSU_OCTUN_10                (0)                                     /*!< Tuning control for current range 10 */
#define LL_TSU_OCTUN_20                (TSU_ACTRL_OCTUN_0)                     /*!< Tuning control for current range 20 */
#define LL_TSU_OCTUN_40                (TSU_ACTRL_OCTUN_1)                     /*!< Tuning control for current range 40 */
#define LL_TSU_OCTUN_80                (TSU_ACTRL_OCTUN_1|TSU_ACTRL_OCTUN_0)   /*!< Tuning control for current range 80 */
/** 
  * @}
  */

/** @defgroup TSU_LL_EC_CTS_Analog_Mode CTS analog mode enable
  * @{
  */
#define LL_TSU_ANAE_DISABLE            (0)                                     /*!< analog mode disable */
#define LL_TSU_ANAE_ENABLE             (TSU_ACTRL_ANAE)                        /*!< analog mode enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Detect detect enable
  * @{
  */
#define LL_TSU_DTE_DISABLE             (0)                                     /*!< detect disable */
#define LL_TSU_DTE_ENABLE              (TSU_ACTRL_DTE)                         /*!< detect enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Charge_Current charge current enable
  * @{
  */
#define LL_TSU_CCMBE_DISABLE           (0)                                     /*!< charge current disable */
#define LL_TSU_CCMBE_ENABLE            (TSU_ACTRL_CCMBE)                       /*!< charge current disable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_CCO_CLK CCO CLK enable
  * @{
  */
#define LL_TSU_CCOCLKEN_DISABLE        (0)                                     /*!< CCO CLK disable */
#define LL_TSU_CCOCLKEN_ENABLE         (TSU_ACTRL_CCOCLKEN)                    /*!< CCO CLK enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_SUCLK SUCLK enable
  * @{
  */
#define LL_TSU_SUCLKEN_DISABLE         (0)                                     /*!< SUCLK disable */
#define LL_TSU_SUCLKEN_ENABLE          (TSU_ACTRL_SUCLKEN)                     /*!< SUCLK enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_TSCAP TSCAP turn on
  * @{
  */
#define LL_TSU_TSCAP_OFF               (0)                                     /*!< TSCAP off */
#define LL_TSU_TSCAP_ON                (TSU_ACTRL_TON)                         /*!< TSCAP on */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_DCBACK DCBACK turn on
  * @{
  */
#define LL_TSU_DCBACK_OFF              (0)                                     /*!< DC back off */
#define LL_TSU_DCBACK_ON               (TSU_ACTRL_TDCON)                       /*!< DC back on */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_DC DC measure on
  * @{
  */
#define LL_TSU_DCMEAS_DISABLE          (0)                                     /*!< DC measurement off */
#define LL_TSU_DCMEAS_ENABLE           (TSU_ACTRL_DCME)                        /*!< DC measurement on */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Power power on
  * @{
  */
#define LL_TSU_POWER_OFF               (0)                                     /*!< Power off */
#define LL_TSU_POWER_ON                (TSU_ACTRL_PON)                         /*!< Power on */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_SUCLK_SS SUCLK SS control
  * @{
  */
#define LL_TSU_SSCTRL_00               (0)                                     /*!< SUCLK SS */
#define LL_TSU_SSCTRL_04               (TSU_AD_SSCTRL_0)
#define LL_TSU_SSCTRL_08               (TSU_AD_SSCTRL_1)
#define LL_TSU_SSCTRL_0C               (TSU_AD_SSCTRL_1|TSU_AD_SSCTRL_0)
#define LL_TSU_SSCTRL_10               (TSU_AD_SSCTRL_2)
#define LL_TSU_SSCTRL_14               (TSU_AD_SSCTRL_2|TSU_AD_SSCTRL_0)
#define LL_TSU_SSCTRL_18               (TSU_AD_SSCTRL_2|TSU_AD_SSCTRL_1)
#define LL_TSU_SSCTRL_1C               (TSU_AD_SSCTRL_2|TSU_AD_SSCTRL_1|TSU_AD_SSCTRL_0)
/**
  * @}
  */

/** @defgroup TSU_LL_EC_CTS_DWA_Bypass CTS DWA by pass
  * @{
  */
#define LL_TSU_CTSDWA_NOBYPASS         (0)                                     /*!< CTS DWA no bypass */
#define LL_TSU_CTSDWA_BYPASS           (TSU_AD_CTSDWABYS)                      /*!< CTS DWA bypass */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_AFC_DWA_Bypass AFC DWA by pass
  * @{
  */
#define LL_TSU_AFCDWA_NOBYPASS         (0)                                     /*!< AFC DWA no bypass */
#define LL_TSU_AFCDWA_BYPASS           (TSU_AFCCTRL_AFCDWABYS)                 /*!< AFC DWA bypass */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_AFC_Bypass AFC by pass
  * @{
  */
#define LL_TSU_AFC_NOBYPASS            (0)                                     /*!< AFC no bypass */
#define LL_TSU_AFC_BYPASS              (TSU_AFCCTRL_AFCBYS)                    /*!< AFC bypass */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_CaliClock Calib Clock
  * @{
  */
#define LL_TSU_CBCLKS_SUCLK            (0)                                     /*!< Calibate clock: SUCLK */
#define LL_TSU_CBCLKS_CCOCLK           (TSU_AFCCFG_CBCLKS)                     /*!< Calibate clock: CCOCLK */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_System_Clock system clock
  * @{
  */
#define LL_TSU_SYSCLK_1                (0)                                     /*!< system clock 1M */
#define LL_TSU_SYSCLK_2                (TSU_OPT_SYSCLK_0)                      /*!< system clock 2M */
#define LL_TSU_SYSCLK_4                (TSU_OPT_SYSCLK_1)                      /*!< system clock 4M */
#define LL_TSU_SYSCLK_8                (TSU_OPT_SYSCLK_1|TSU_OPT_SYSCLK_0)     /*!< system clock 8M */
#define LL_TSU_SYSCLK_16               (TSU_OPT_SYSCLK_2)                      /*!< system clock 16M */
#define LL_TSU_SYSCLK_32               (TSU_OPT_SYSCLK_2|TSU_OPT_SYSCLK_0)     /*!< system clock 32M */
#define LL_TSU_SYSCLK_64               (TSU_OPT_SYSCLK_2|TSU_OPT_SYSCLK_1)     /*!< system clock 64M */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Atro_Judgment Auto judgment function enable
  * @{
  */
#define LL_TSU_AJF_DISABLE             (0)                                     /*!< Auto judgment disable */
#define LL_TSU_AJF_ENABLE              (TSU_OPT_AJFEN)                         /*!< Auto judgment enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Mutual_Cap Mutual capacitance calculation enable
  * @{
  */
#define LL_TSU_MTUCF_DISABLE           (0)                                     /*!< Mutual capacitance calculeate disable */
#define LL_TSU_MTUCF_ENABLE            (TSU_OPT_MTUCFEN)                       /*!< Mutual capacitance calculeate enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_DMA Data transfer request enable
  * @{
  */
#define LL_TSU_DTC_DISABLE             (TSU_OPT_DTCLESS)                       /*!< Data transfer disable */
#define LL_TSU_DTC_ENABLE              (0)                                     /*!< Data transfer enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Sensor_Offset_Tuning SO tuning enable
  * @{
  */
#define LL_TSU_SOTUNING_DISABLE        (0)                                     /*!< SO tuning disable */
#define LL_TSU_SOTUNING_ENABLE         (TSU_OPT_TUNEN)                         /*!< SO tuning enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_Frequency_Judgment Frequency judgment enable
  * @{
  */
#define LL_TSU_FREJF_DISABLE           (0)                                     /*!< Frequency judgment disable */
#define LL_TSU_FREJF_ENABLE            (TSU_OPT_FREJFEN)                       /*!< Frequency judgment enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_CCO_Correct CCO Characteristics Correction function enable
  * @{
  */
#define LL_TSU_CCOCF_DISABLE           (0)                                     /*!< CCO correct disable */
#define LL_TSU_CCOCF_ENABLE            (TSU_OPT_CCOCFEN)                       /*!< CCO correct enable */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_ATC_Condition AJC condition
  * @{
  */
#define LL_TSU_AJC_1                   (0)                                     /*!< Auto judgment confition 1 time */
#define LL_TSU_AJC_2                   (TSU_AJC_JC_0)                          /*!< Auto judgment confition 2 times */
#define LL_TSU_AJC_3                   (TSU_AJC_JC_1)                          /*!< Auto judgment confition 3 times */
#define LL_TSU_AJC_4                   (TSU_AJC_JC_1|TSU_AJC_JC_0)             /*!< Auto judgment confition 4 times */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_C2H_Reponse CTSM to Host interrupt
  * @{
  */
#define LL_TSU_CTSM2HOST_IT_MRRD       (TSU_INTEN_MRRD)                        /*!< CTSM event: measurement result */
#define LL_TSU_CTSM2HOST_IT_MARRD      (TSU_INTEN_MARRD)                       /*!< CTSM event: measurement average result */ 
#define LL_TSU_CTSM2HOST_IT_JRRD       (TSU_INTEN_JRRD)                        /*!< CTSM event: judgment result */
#define LL_TSU_CTSM2HOST_IT_BUSY       (TSU_INTEN_BUSY)                        /*!< CTSM event: system busy */
#define LL_TSU_CTSM2HOST_IT_MCPLT      (TSU_INTEN_MCPLT)                       /*!< CTSM event: measurement complete */
#define LL_TSU_CTSM2HOST_IT_SCPLT      (TSU_INTEN_SCPLT)                       /*!< CTSM event: scan complete */
#define LL_TSU_CTSM2HOST_IT_JCPLT      (TSU_INTEN_JCPLT)                       /*!< CTSM event: judgment complete */
#define LL_TSU_CTSM2HOST_IT_ERROR      (TSU_INTEN_ERROR)                       /*!< CTSM event: error */
#define LL_TSU_CTSM2HOST_IT_IDLE       (TSU_INTEN_IDLE)                        /*!< CTSM event: system idle */
#define LL_TSU_CTSM2HOST_IT_CORRCPLT   (TSU_INTEN_CORRCPLT)                    /*!< CTSM event: correction complete */
/**
  * @}
  */

/** @defgroup TSU_LL_EC_H2C_Command Host to CTSM command
  * @{
  */
#define LL_TSU_HOST2CTSM_CMD_MSTOP     (TSUSYS_H2CEVT_MSTOP)                   /*!< CTSM command: measure stop */
#define LL_TSU_HOST2CTSM_CMD_MSTRT     (TSUSYS_H2CEVT_MSTRT)                   /*!< CTSM command: measure start */
#define LL_TSU_HOST2CTSM_CMD_CSTRT     (TSUSYS_H2CEVT_CSTRT)                   /*!< CTSM command: correct start */
#define LL_TSU_HOST2CTSM_CMD_SCSTRT    (TSUSYS_H2CEVT_DCSTRT)                  /*!< CTSM command: current start */
#define LL_TSU_HOST2CTSM_CMD_DIASTRT   (TSUSYS_H2CEVT_DIASTRT)                 /*!< CTSM command: diagnosis start */
#define LL_TSU_HOST2CTSM_CMD_TCSTRT    (TSUSYS_H2CEVT_TCSTRT)                  /*!< CTSM command: temperature correct start */
#define LL_TSU_HOST2CTSM_CMD_IDCSTRT   (TSUSYS_H2CEVT_IDCSTRT)                 /*!< CTSM command: internal current start */
#define LL_TSU_HOST2CTSM_CMD_JINIT     (TSUSYS_H2CEVT_JINIT)                   /*!< CTSM command: judgment initialize */
#define LL_TSU_HOST2CTSM_CMD_GETST     (TSUSYS_H2CEVT_GETST)                   /*!< CTSM command: get status */
#define LL_TSU_HOST2CTSM_CMD_AFC       (TSUSYS_H2CEVT_AFC)                     /*!< CTSM command: afc start */
#define LL_TSU_HOST2CTSM_CMD_MSCAN     (TSUSYS_H2CEVT_MSCAN)                   /*!< CTSM command: measure scan */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup TSU_LL_Exported_Macros TSU Exported Macros
  * @{
  */

/** @defgroup TSU_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in TSU register
  * @param  __INSTANCE__ TSU Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_TSU_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, __VALUE__)

/**
  * @brief  Read a value in TSU register
  * @param  __INSTANCE__ TSU Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_TSU_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup TSU_LL_Exported_Functions TSU Exported Functions
  * @{
  */

/** @defgroup TSU_LL_EF_Configuration TSU Configuration functions
  * @{
  */

/**
  * @brief  AFC interrupt enable.
  * @rmtoll DCTRL                    LL_TSU_AFCInterruptEnable
  * @param  TSUx TSU Instance
  * @param  Interrupt the value is one of the following values: 
  *       @arg @ref LL_TSU_AFC_CDEIE_ENABLE
  *       @arg @ref LL_TSU_AFC_ADEIE_ENABLE
  *       @arg @ref LL_TSU_AFC_AEIE_ENABLE
  *       @arg @ref LL_TSU_AFC_ANIE_ENABLE
  *       @arg @ref LL_TSU_AFC_ALIE_ENABLE
  */
__STATIC_INLINE void LL_TSU_AFCInterruptEnable(TSU_TypeDef *TSUx, uint32_t Interrupt)
{
  SET_BIT(TSUx->DCTRL, Interrupt);
}

/**
  * @brief  AFC interrupt disable.
  * @rmtoll DCTRL                    LL_TSU_AFCInterruptDisable
  * @param  TSUx TSU Instance
  * @param  Interrupt the value is one of the following values: 
  *       @arg @ref LL_TSU_AFC_CDEIE_ENABLE
  *       @arg @ref LL_TSU_AFC_ADEIE_ENABLE
  *       @arg @ref LL_TSU_AFC_AEIE_ENABLE
  *       @arg @ref LL_TSU_AFC_ANIE_ENABLE
  *       @arg @ref LL_TSU_AFC_ALIE_ENABLE
  */
__STATIC_INLINE void LL_TSU_AFCInterruptDisable(TSU_TypeDef *TSUx, uint32_t Interrupt)
{
  CLEAR_BIT(TSUx->DCTRL, Interrupt);
}

/**
  * @brief  TSU interrupt enable.
  * @rmtoll DCTRL                    LL_TSU_InterruptEnable
  * @param  TSUx TSU Instance
  * @param  Interrupt the value is one of the following values: 
  *       @arg @ref LL_TSU_SCOIE_ENABLE
  *       @arg @ref LL_TSU_UCOIE_ENABLE
  *       @arg @ref LL_TSU_MDIE_ENABLE
  */
__STATIC_INLINE void LL_TSU_InterruptEnable(TSU_TypeDef *TSUx, uint32_t Interrupt)
{
  SET_BIT(TSUx->DCTRL, Interrupt);
}

/**
  * @brief  TSU interrupt disable.
  * @rmtoll DCTRL                    LL_TSU_InterruptDisable
  * @param  TSUx TSU Instance
  * @param  Interrupt the value is one of the following values: 
  *       @arg @ref LL_TSU_SCOIE_ENABLE
  *       @arg @ref LL_TSU_UCOIE_ENABLE
  *       @arg @ref LL_TSU_MDIE_ENABLE
  */
__STATIC_INLINE void LL_TSU_InterruptDisable(TSU_TypeDef *TSUx, uint32_t Interrupt)
{
  CLEAR_BIT(TSUx->DCTRL, Interrupt);
}

/**
  * @brief  TSU PRN on.
  * @rmtoll DCTRL                    LL_TSU_PRNOn
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_PRNOn(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_PROFF);
}

/**
  * @brief  TSU PRN off.
  * @rmtoll DCTRL                    LL_TSU_PRNOff
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_PRNOff(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_PROFF);
}

/**
  * @brief  TSU SS on.
  * @rmtoll DCTRL                    LL_TSU_SSOn
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SSOn(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_SOFF);
}

/**
  * @brief  TSU SS off.
  * @rmtoll DCTRL                    LL_TSU_SSOff
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SSOff(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_SOFF);
}

/**
  * @brief  Configure the PRN generation period.
  * @rmtoll DCTRL           PHT      LL_TSU_SetPRNGenerationPrd
  * @param  TSUx TSU Instance
  * @param  Cycle This parameter can be one of the following values:
  *         @arg @ref LL_TSU_PHT_255
  *         @arg @ref LL_TSU_PHT_63
  *         @arg @ref LL_TSU_PHT_31
  *         @arg @ref LL_TSU_PHT_3
  */
__STATIC_INLINE void LL_TSU_SetPRNGenerationPrd(TSU_TypeDef *TSUx, uint32_t Cycle)
{
  MODIFY_REG(TSUx->DCTRL, TSU_DCTRL_PHT, Cycle);
}

/**
  * @brief  Configure the PRN update period.
  * @rmtoll DCTRL           PHS      LL_TSU_SetPRNUpdatePrd
  * @param  TSUx TSU Instance
  * @param  Cycle 
  */
__STATIC_INLINE void LL_TSU_SetPRNUpdatePrd(TSU_TypeDef *TSUx, uint32_t Cycle)
{
  MODIFY_REG(TSUx->DCTRL, TSU_DCTRL_PHS, Cycle << TSU_DCTRL_PHS_Pos);
}

/**
  * @brief  TSU Set random pulse mode.
  * @rmtoll DCTRL                    LL_TSU_SetRandomPulseMode
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetRandomPulseMode(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_SDPSEL);
}

/**
  * @brief  TSU Set high resolution pulse mode.
  * @rmtoll DCTRL                    LL_TSU_SetHighResolutionPulseMode
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetHighResolutionPulseMode(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_SDPSEL);
}

/**
  * @brief  TSU Set self-capcaitance method.
  * @rmtoll DCTRL                    LL_TSU_SetSelfCapacitanceMeasurement
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetSelfCapacitanceMeasurement(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_MD);
}

/**
  * @brief  TSU Set mutual-capcaitance method.
  * @rmtoll DCTRL                    LL_TSU_SetMutualCapacitanceMeasurement
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetMutualCapacitanceMeasurement(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_MD);
}

/**
  * @brief  TSU Set single scan.
  * @rmtoll DCTRL                    LL_TSU_SetSingleScan
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetSingleScan(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_MD0);
}

/**
  * @brief  TSU Set multi scan.
  * @rmtoll DCTRL                    LL_TSU_SetMultiScan
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetMultiScan(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_MD0);
}

/**
  * @brief  TSU CTS DWA enable.
  * @rmtoll DCTRL                    LL_TSU_CTSDWAEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_CTSDWAEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_CTSDWAEN);
}

/**
  * @brief  TSU CTS DWA disable.
  * @rmtoll DCTRL                    LL_TSU_CTSDWADisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_CTSDWADisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_CTSDWAEN);
}

/**
  * @brief  TSU AFC DWA enable.
  * @rmtoll DCTRL                    LL_TSU_AFCDWAEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_AFCDWAEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_AFCDWAEN);
}

/**
  * @brief  TSU AFC DWA disable.
  * @rmtoll DCTRL                    LL_TSU_AFCDWADisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_AFCDWADisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_AFCDWAEN);
}

/**
  * @brief  TSU AFC enable.
  * @rmtoll DCTRL                    LL_TSU_AFCEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_AFCEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_AFCEN);
}

/**
  * @brief  TSU AFC disable.
  * @rmtoll DCTRL                    LL_TSU_AFCDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_AFCDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_AFCEN);
}

/**
  * @brief  TSU Measure start.
  * @rmtoll DCTRL                    LL_TSU_MeasureStart
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_MeasureStart(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->DCTRL, TSU_DCTRL_STRT);
}

/**
  * @brief  TSU Measure stop.
  * @rmtoll DCTRL                    LL_TSU_MeasureStop
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_MeasureStop(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->DCTRL, TSU_DCTRL_STRT);
}

/**
  * @brief  TSU set sensor stabilization wait time.
  * @rmtoll TS       WTNUM             LL_TSU_SetMeasureWaittime
  * @param  TSUx TSU Instance
  * @param  Wait 
  */
__STATIC_INLINE void LL_TSU_SetMeasureWaittime(TSU_TypeDef *TSUx, uint32_t Wait)
{
  MODIFY_REG(TSUx->TS, TSU_TS_WTNUM, Wait << TSU_TS_WTNUM_Pos);
}

/**
  * @brief  TSU set measurem period.
  * @rmtoll TS       MSNUM             LL_TSU_SetMeasurePeriod
  * @param  TSUx TSU Instance
  * @param  Period 
  */
__STATIC_INLINE void LL_TSU_SetMeasurePeriod(TSU_TypeDef *TSUx, uint32_t Period)
{
  MODIFY_REG(TSUx->TS, TSU_TS_MSNUM, Period << TSU_TS_MSNUM_Pos);
}

/**
  * @brief  TSU set SS sampling period.
  * @rmtoll DW       SSDIV             LL_TSU_SetSSSamplingPeriod
  * @param  TSUx TSU Instance
  * @param  Period 
  */
__STATIC_INLINE void LL_TSU_SetSSSamplingPeriod(TSU_TypeDef *TSUx, uint32_t Period)
{
  MODIFY_REG(TSUx->DIV, TSU_DIV_SSDIV, Period << TSU_DIV_SSDIV_Pos);
}

/**
  * @brief  TSU set Base clock period.
  * @rmtoll DW       SSDIV             LL_TSU_SetBaseClockDivider
  * @param  TSUx TSU Instance
  * @param  Divider 
  */
__STATIC_INLINE void LL_TSU_SetBaseClockDivider(TSU_TypeDef *TSUx, uint32_t Divider)
{
  MODIFY_REG(TSUx->DIV, TSU_DIV_BDIV, Divider << TSU_DIV_BDIV_Pos);
}

/**
  * @brief  TSU set non-measure pin output.
  * @rmtoll PS       NMPSEL             LL_TSU_SetNonMeasurePinOutput
  * @param  TSUx TSU Instance
  * @param  Status This parameter can be one of the following values:
  *       @arg @ref LL_TSU_NONMEAS_OUTPUT_0
  *       @arg @ref LL_TSU_NONMEAS_OUTPUT_1
  *       @arg @ref LL_TSU_NONMEAS_OUTPUT_PULSE
  */
__STATIC_INLINE void LL_TSU_SetNonMeasurePinOutput(TSU_TypeDef *TSUx, uint32_t Status)
{
  MODIFY_REG(TSUx->PS, TSU_PS_NMPSEL, Status);
}

/**
  * @brief  TSU set shield pin output.
  * @rmtoll PS       SHPSEL             LL_TSU_SetShieldPinOutput
  * @param  TSUx TSU Instance
  * @param  Status This parameter can be one of the following values:
  *       @arg @ref LL_TSU_SHIELD_OUTPUT_0
  *       @arg @ref LL_TSU_SHIELD_OUTPUT_1
  *       @arg @ref LL_TSU_SHIELD_OUTPUT_PULSE
  */
__STATIC_INLINE void LL_TSU_SetShieldPinOutput(TSU_TypeDef *TSUx, uint32_t Status)
{
  MODIFY_REG(TSUx->PS, TSU_PS_SHDPSEL, Status);
}

/**
  * @brief  TSU set transmit pin inverting output.
  * @rmtoll PS       TXINV             LL_TSU_SetTxinvSame
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetTxinvSame(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->PS, TSU_PS_TXINV);
}

/**
  * @brief  TSU set transmit pin inverting output.
  * @rmtoll PS       TXINV             LL_TSU_SetTxinvOpposite
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetTxinvOpposite(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->PS, TSU_PS_TXINV);
}

/**
  * @brief  TSU shield pin enable.
  * @rmtoll PS       SHD             LL_TSU_ShieldPinEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_ShieldPinEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->PS, TSU_PS_SHD);
}

/**
  * @brief  TSU shield pin disable.
  * @rmtoll PS       SHD             LL_TSU_ShieldPinDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_ShieldPinDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->PS, TSU_PS_SHD);
}

/**
  * @brief  TSU get measured Rx channel.
  * @rmtoll PS       RXCH             LL_TSU_GetMeasuredRxChannel
  * @param  TSUx TSU Instance
  * @retval Rx channle index
  */
__STATIC_INLINE uint32_t LL_TSU_GetMeasuredRxChannel(TSU_TypeDef *TSUx)
{
  return (uint32_t)(READ_BIT(TSUx->PS, TSU_PS_RXCH) >> TSU_PS_RXCH_Pos);
}

/**
  * @brief  TSU get measured Tx channel.
  * @rmtoll PS       RXCH             LL_TSU_GetMeasuredTxChannel
  * @param  TSUx TSU Instance
  * @retval Tx channle index
  */
__STATIC_INLINE uint32_t LL_TSU_GetMeasuredTxChannel(TSU_TypeDef *TSUx)
{
  return (uint32_t)(READ_BIT(TSUx->PS, TSU_PS_TXCH) >> TSU_PS_TXCH_Pos);
}

/**
  * @brief  TSU get measured status.
  * @rmtoll SR       STC             LL_TSU_GetMeasureStatus
  * @param  TSUx TSU Instance
  * @retval the value is one of the following values:
  *        @arg @ref  LL_TSU_MEAS_STATUS_IDLE         
  *        @arg @ref  LL_TSU_MEAS_STATUS_WAIT_1       
  *        @arg @ref  LL_TSU_MEAS_STATUS_MEAS_1       
  *        @arg @ref  LL_TSU_MEAS_STATUS_SYNC_1       
  *        @arg @ref  LL_TSU_MEAS_STATUS_READ_1       
  *        @arg @ref  LL_TSU_MEAS_STATUS_WAIT_2       
  *        @arg @ref  LL_TSU_MEAS_STATUS_MEAS_2       
  *        @arg @ref  LL_TSU_MEAS_STATUS_SYNC_2       
  *        @arg @ref  LL_TSU_MEAS_STATUS_READ_2       
  * 
  */
__STATIC_INLINE uint32_t LL_TSU_GetMeasureStatus(TSU_TypeDef *TSUx)
{
  return (uint32_t)(READ_BIT(TSUx->SR, TSU_SR_STC));
}

/**
  * @brief  TSU get measure step.
  * @rmtoll SR       MST             LL_TSU_GetMeasureStep
  * @param  TSUx TSU Instance
  * @retval Tx channle index
  */
__STATIC_INLINE uint32_t LL_TSU_GetMeasureStep(TSU_TypeDef *TSUx)
{
  return (uint32_t)(READ_BIT(TSUx->SR, TSU_SR_MST) >> TSU_SR_MST_Pos);
}

/**
  * @brief  TSU get Action step.
  * @rmtoll SR       AST             LL_TSU_GetActionStep
  * @param  TSUx TSU Instance
  * @retval Tx channle index
  */
__STATIC_INLINE uint32_t LL_TSU_GetActionStep(TSU_TypeDef *TSUx)
{
  return (uint32_t)(READ_BIT(TSUx->SR, TSU_SR_AST) >> TSU_SR_AST_Pos);
}

/**
  * @brief  TSU get Scan step.
  * @rmtoll SR       CST             LL_TSU_GetScanStep
  * @param  TSUx TSU Instance
  * @retval Tx channle index
  */
__STATIC_INLINE uint32_t LL_TSU_GetScanStep(TSU_TypeDef *TSUx)
{
  return (uint32_t)(READ_BIT(TSUx->SR, TSU_SR_CST) >> TSU_SR_CST_Pos);
}

/**
  * @brief  TSU set frequency.
  * @rmtoll FRQCFG                   LL_TSU_SetFrequency
  * @param  TSUx TSU Instance
  * @param  Freq
  */
__STATIC_INLINE void LL_TSU_SetFrequency(TSU_TypeDef *TSUx, uint32_t Freq)
{
  WRITE_REG(TSUx->FRQCFG, Freq);
}

/**
  * @brief  TSU channels enable.
  * @rmtoll CHEN                    LL_TSU_EnableChannels
  * @param  TSUx TSU Instance
  * @param  Channels
  */
__STATIC_INLINE void LL_TSU_EnableChannels(TSU_TypeDef *TSUx, uint32_t Channels)
{
  WRITE_REG(TSUx->CHEN, Channels);
}

/**
  * @brief  TSU configure channels.
  * @rmtoll CHCTRL                    LL_TSU_ConfigChannels
  * @param  TSUx TSU Instance
  * @param  Config
  */
__STATIC_INLINE void LL_TSU_ConfigChannels(TSU_TypeDef *TSUx, uint32_t Config)
{
  WRITE_REG(TSUx->CHCTRL, Config);
}

/**
  * @brief  TSU set measurement load.
  * @rmtoll ACTRL                    LL_TSU_SetLoad
  * @param  TSUx TSU Instance
  * @param  Load
  *       @arg @ref  LL_TSU_LOADMODE_CC_NORMAL        
  *       @arg @ref  LL_TSU_LOADMODE_NOLOAD           
  *       @arg @ref  LL_TSU_LOADMODE_CC_CALIB         
  *       @arg @ref  LL_TSU_LOADMODE_RES_CALIB        
  */
__STATIC_INLINE void LL_TSU_SetLoad(TSU_TypeDef *TSUx, uint32_t Load)
{
  MODIFY_REG(TSUx->ACTRL, TSU_ACTRL_LOAD, Load);
}

/**
  * @brief  TSU set measurement current range.
  * @rmtoll ACTRL                    LL_TSU_SetCurrentRange
  * @param  TSUx TSU Instance
  * @param  Range
  *       @arg @ref  LL_TSU_CURRENT_RANGE_80        
  *       @arg @ref  LL_TSU_CURRENT_RANGE_40           
  *       @arg @ref  LL_TSU_CURRENT_RANGE_20         
  *       @arg @ref  LL_TSU_CURRENT_RANGE_160        
  */
__STATIC_INLINE void LL_TSU_SetCurrentRange(TSU_TypeDef *TSUx, uint32_t Range)
{
  MODIFY_REG(TSUx->ACTRL, TSU_ACTRL_CMD, Range);
}

/**
  * @brief  TSU set measurement resistance load.
  * @rmtoll ACTRL                    LL_TSU_SetResistanceLoad
  * @param  TSUx TSU Instance
  * @param  Load
  *       @arg @ref  LL_TSU_LOADRES_10        
  *       @arg @ref  LL_TSU_LOADRES_20           
  *       @arg @ref  LL_TSU_LOADRES_40         
  *       @arg @ref  LL_TSU_LOADRES_5        
  */
__STATIC_INLINE void LL_TSU_SetResistanceLoad(TSU_TypeDef *TSUx, uint32_t Load)
{
  MODIFY_REG(TSUx->ACTRL, TSU_ACTRL_CMD, Load);
}

/**
  * @brief  TSU set IDAC bais for reference CCO.
  * @rmtoll ACTRL                    LL_TSU_SetIDACforRefCCO
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetIDACforRefCCO(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_CCOBS);
}

/**
  * @brief  TSU set IDAC bais for sense CCO.
  * @rmtoll ACTRL                    LL_TSU_SetIDACforSenCCO
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetIDACforSenCCO(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_CCOBS);
}

/**
  * @brief  TSU set tuning control for the over current detect.
  * @rmtoll ACTRL                    LL_TSU_SetTuningControl
  * @param  TSUx TSU Instance
  * @param  Ctrl
  *       @arg @ref  LL_TSU_OCTUN_10        
  *       @arg @ref  LL_TSU_OCTUN_20           
  *       @arg @ref  LL_TSU_OCTUN_40         
  *       @arg @ref  LL_TSU_OCTUN_80        
  */
__STATIC_INLINE void LL_TSU_SetTuningControl(TSU_TypeDef *TSUx, uint32_t Ctrl)
{
  MODIFY_REG(TSUx->ACTRL, TSU_ACTRL_OCTUN, Ctrl);
}

/**
  * @brief  TSU analog module enable.
  * @rmtoll ACTRL                    LL_TSU_AnalogModuleEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_AnalogModuleEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_ANAE);
}

/**
  * @brief  TSU analog module disable.
  * @rmtoll ACTRL                    LL_TSU_AnalogModuleDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_AnalogModuleDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_ANAE);
}

/**
  * @brief  TSU over current and over voltage detect enable.
  * @rmtoll ACTRL                    LL_TSU_OverDetectEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_OverDetectEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_DTE);
}

/**
  * @brief  TSU over current and over voltage detect disable.
  * @rmtoll ACTRL                    LL_TSU_OverDetectDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_OverDetectDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_DTE);
}

/**
  * @brief  TSU charge current measure enable.
  * @rmtoll ACTRL                    LL_TSU_ChargeCurrentEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_ChargeCurrentEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_CCMBE);
}

/**
  * @brief  TSU charge current measure disable.
  * @rmtoll ACTRL                    LL_TSU_ChargeCurrentDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_ChargeCurrentDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_CCMBE);
}

/**
  * @brief  TSU CCO clock enable.
  * @rmtoll ACTRL                    LL_TSU_CCOClockEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_CCOClockEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_CCOCLKEN);
}

/**
  * @brief  TSU CCO clock disable.
  * @rmtoll ACTRL                    LL_TSU_CCOClockDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_CCOClockDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_CCOCLKEN);
}

/**
  * @brief  TSU SUCLK clock enable.
  * @rmtoll ACTRL                    LL_TSU_SUCLKEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SUCLKEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_SUCLKEN);
}

/**
  * @brief  TSU SUCLK clock disable.
  * @rmtoll ACTRL                    LL_TSU_SUCLKDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SUCLKDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_SUCLKEN);
}

/**
  * @brief  TSU TSCAP turn on.
  * @rmtoll ACTRL                    LL_TSU_TSCAPOn
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_TSCAPOn(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_TON);
}

/**
  * @brief  TSU TSCAP turn off.
  * @rmtoll ACTRL                    LL_TSU_TSCAPOff
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_TSCAPOff(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_TON);
}

/**
  * @brief  TSU DCBack turn on.
  * @rmtoll ACTRL                    LL_TSU_DCBackOn
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_DCBackOn(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_TDCON);
}

/**
  * @brief  TSU DCBack turn off.
  * @rmtoll ACTRL                    LL_TSU_DCBackOff
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_DCBackOff(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_TDCON);
}

/**
  * @brief  TSU DC measure enable.
  * @rmtoll ACTRL                    LL_TSU_DCMeasureEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_DCMeasureEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_DCME);
}

/**
  * @brief  TSU DC measure disable.
  * @rmtoll ACTRL                    LL_TSU_DCMeasureDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_DCMeasureDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_DCME);
}

/**
  * @brief  TSU measure power on.
  * @rmtoll ACTRL                    LL_TSU_MeasurePowerOn
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_MeasurePowerOn(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACTRL, TSU_ACTRL_PON);
}

/**
  * @brief  TSU measure power off.
  * @rmtoll ACTRL                    LL_TSU_MeasurePowerOff
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_MeasurePowerOff(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->ACTRL, TSU_ACTRL_PON);
}

/**
  * @brief  TSU clear over flag.
  * @rmtoll ACFG                    LL_TSU_ClearOverFlags
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_ClearOverFlags(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->ACFG, TSU_ACFG_FCLR);
}

/**
  * @brief  TSU get RTRIM.
  * @rmtoll ACFG                    LL_TSU_GetRTRIM
  * @param  TSUx TSU Instance
  * @retval RTRIM
  */
__STATIC_INLINE uint32_t LL_TSU_GetRTRIM(TSU_TypeDef *TSUx)
{
  return (uint32_t)(READ_BIT(TSUx->ACFG, TSU_ACFG_RTRIM));
}

/**
  * @brief  TSU CTS DWA bypass.
  * @rmtoll AD                    LL_TSU_CTSDWABypass
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_CTSDWABypass(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->AD, TSU_AD_CTSDWABYS);
}

/**
  * @brief  TSU CTS DWA non bypass.
  * @rmtoll AD                    LL_TSU_CTSDWANonBypass
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_CTSDWANonBypass(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->AD, TSU_AD_CTSDWABYS);
}

/**
  * @brief  TSU set SS control.
  * @rmtoll AD                    LL_TSU_SetSSControl
  * @param  TSUx TSU Instance
  * @param  Ctrl
  *       @arg @ref LL_TSU_SSCTRL_00              
  *       @arg @ref LL_TSU_SSCTRL_04              
  *       @arg @ref LL_TSU_SSCTRL_08              
  *       @arg @ref LL_TSU_SSCTRL_0C              
  *       @arg @ref LL_TSU_SSCTRL_10              
  *       @arg @ref LL_TSU_SSCTRL_14              
  *       @arg @ref LL_TSU_SSCTRL_18              
  *       @arg @ref LL_TSU_SSCTRL_1C              
  */
__STATIC_INLINE void LL_TSU_SetSSControl(TSU_TypeDef *TSUx, uint32_t Ctrl)
{
  MODIFY_REG(TSUx->AD, TSU_AD_SSCTRL, Ctrl);
}

/**
  * @brief  TSU set SS period.
  * @rmtoll AD                    LL_TSU_SetSSPeriod
  * @param  TSUx TSU Instance
  * @param  Period
  */
__STATIC_INLINE void LL_TSU_SetSSPeriod(TSU_TypeDef *TSUx, uint32_t Period)
{
  MODIFY_REG(TSUx->AD, TSU_AD_SSNUM, Period << TSU_AD_SSNUM_Pos);
}

/**
  * @brief  TSU set SO.
  * @rmtoll AD                    LL_TSU_SetSO
  * @param  TSUx TSU Instance
  * @param  So
  */
__STATIC_INLINE void LL_TSU_SetSO(TSU_TypeDef *TSUx, uint32_t So)
{
  MODIFY_REG(TSUx->AD, TSU_AD_SO, So << TSU_AD_SO_Pos);
}

/**
  * @brief  TSU set AFC reference clock.
  * @rmtoll AFCCTRL                    LL_TSU_SetAFCRefClk
  * @param  TSUx TSU Instance
  * @param  Period
  */
__STATIC_INLINE void LL_TSU_SetAFCRefClk(TSU_TypeDef *TSUx, uint32_t Period)
{
  MODIFY_REG(TSUx->AFCCTRL, TSU_AFCCTRL_AFCPRD, Period << TSU_AFCCTRL_AFCPRD_Pos);
}

/**
  * @brief  TSU set AFC different.
  * @rmtoll AFCCTRL                    LL_TSU_SetAFCDiff
  * @param  TSUx TSU Instance
  * @param  Diff
  */
__STATIC_INLINE void LL_TSU_SetAFCDiff(TSU_TypeDef *TSUx, uint32_t Diff)
{
  MODIFY_REG(TSUx->AFCCTRL, TSU_AFCCTRL_DIFFCNT, Diff << TSU_AFCCTRL_DIFFCNT_Pos);
}

/**
  * @brief  TSU set AFC DWA bypass.
  * @rmtoll AFCCTRL                    LL_TSU_SetAFCDWABypass
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetAFCDWABypass(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->AFCCTRL, TSU_AFCCTRL_AFCDWABYS);
}

/**
  * @brief  TSU set AFC DWA bypass non.
  * @rmtoll AFCCTRL                    LL_TSU_SetAFCDWANonBypass
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetAFCDWANonBypass(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->AFCCTRL, TSU_AFCCTRL_AFCDWABYS);
}

/**
  * @brief  TSU set AFC bypass.
  * @rmtoll AFCCTRL                    LL_TSU_SetAFCBypass
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetAFCBypass(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->AFCCTRL, TSU_AFCCTRL_AFCBYS);
}

/**
  * @brief  TSU set AFC bypass non.
  * @rmtoll AFCCTRL                    LL_TSU_SetAFCNonBypass
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetAFCNonBypass(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->AFCCTRL, TSU_AFCCTRL_AFCBYS);
}

/**
  * @brief  TSU set reference clock SUCLK.
  * @rmtoll AFCCFG                    LL_TSU_SetCBClkSUCLK
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetCBClkSUCLK(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->AFCCFG, TSU_AFCCFG_CBCLKS);
}

/**
  * @brief  TSU set reference clock CCOCLK.
  * @rmtoll AFCCFG                    LL_TSU_SetCBClkCCO
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SetCBClkCCO(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->AFCCFG, TSU_AFCCFG_CBCLKS);
}

/**
  * @brief  TSU set SUCLK frequency initial.
  * @rmtoll AFCCFG                    LL_TSU_SetSUCLKFreqInit
  * @param  TSUx TSU Instance
  * @param  Freqidx 
  * @param  Freq
  */
__STATIC_INLINE void LL_TSU_SetSUCLKFreqInit(TSU_TypeDef *TSUx, uint32_t Freqidx, uint32_t Freq)
{
  MODIFY_REG(TSUx->SUCLK0, 0xFFUL<<(Freqidx<<3), Freq<<(Freqidx<<3));
}

/**
  * @brief  TSU set SUCLK frequency.
  * @rmtoll AFCCFG                    LL_TSU_SetSUCLKFreq
  * @param  TSUx TSU Instance
  * @param  Freqidx 
  * @param  Freq
  */
__STATIC_INLINE void LL_TSU_SetSUCLKFreq(TSU_TypeDef *TSUx, uint32_t Freqidx, uint32_t Freq)
{
  uint32_t* reg = (uint32_t*)&(TSUx->SUCLK1) + 4*Freqidx;
  *reg = Freq;
}

/**
  * @brief  TSU set moving average window.
  * @rmtoll OPT                    LL_TSU_SetMovingAverageWindow
  * @param  TSUx TSU Instance
  * @param  Window 
  */
__STATIC_INLINE void LL_TSU_SetMovingAverageWindow(TSU_TypeDef *TSUx, uint32_t Window)
{
  MODIFY_REG(TSUx->OPT, TSU_OPT_AWIN, Window <<TSU_OPT_AWIN_Pos );
}

/**
  * @brief  TSU set system clock
  * @rmtoll OPT                    LL_TSU_SetSysteClock
  * @param  TSUx TSU Instance
  * @param  Clock 
  *       @arg @ref  LL_TSU_SYSCLK_1              
  *       @arg @ref  LL_TSU_SYSCLK_2              
  *       @arg @ref  LL_TSU_SYSCLK_4              
  *       @arg @ref  LL_TSU_SYSCLK_8              
  *       @arg @ref  LL_TSU_SYSCLK_16             
  *       @arg @ref  LL_TSU_SYSCLK_32             
  *       @arg @ref  LL_TSU_SYSCLK_64             
  */
__STATIC_INLINE void LL_TSU_SetSysteClock(TSU_TypeDef *TSUx, uint32_t Clock)
{
  MODIFY_REG(TSUx->OPT, TSU_OPT_SYSCLK, Clock);
}

/**
  * @brief  TSU set AJF enable.
  * @rmtoll OPT                    LL_TSU_AJFEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_AJFEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->OPT, TSU_OPT_AJFEN);
}

/**
  * @brief  TSU set AJF disable.
  * @rmtoll OPT                    LL_TSU_AJFDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_AJFDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->OPT, TSU_OPT_AJFEN);
}

/**
  * @brief  TSU set MTUCF enable.
  * @rmtoll OPT                    LL_TSU_MTUCFEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_MTUCFEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->OPT, TSU_OPT_MTUCFEN);
}

/**
  * @brief  TSU set MTUCF disable.
  * @rmtoll OPT                    LL_TSU_MTUCFDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_MTUCFDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->OPT, TSU_OPT_MTUCFEN);
}

/**
  * @brief  TSU set DTC enable.
  * @rmtoll OPT                    LL_TSU_DTCEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_DTCEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->OPT, TSU_OPT_DTCLESS);
}

/**
  * @brief  TSU set DTC Disable.
  * @rmtoll OPT                    LL_TSU_DTCDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_DTCDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->OPT, TSU_OPT_DTCLESS);
}

/**
  * @brief  TSU set SO tuning enable.
  * @rmtoll OPT                    LL_TSU_SOTuningEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SOTuningEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->OPT, TSU_OPT_TUNEN);
}

/**
  * @brief  TSU set SO tuning disable.
  * @rmtoll OPT                    LL_TSU_SOTuningDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_SOTuningDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->OPT, TSU_OPT_TUNEN);
}

/**
  * @brief  TSU set Frequnecy judgment enable.
  * @rmtoll OPT                    LL_TSU_FreJEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_FreJEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->OPT, TSU_OPT_FREJFEN);
}

/**
  * @brief  TSU set Frequnecy judgment disable.
  * @rmtoll OPT                    LL_TSU_FreJDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_FreJDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->OPT, TSU_OPT_FREJFEN);
}

/**
  * @brief  TSU set CCO CF enable.
  * @rmtoll OPT                    LL_TSU_CCOCFEnable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_CCOCFEnable(TSU_TypeDef *TSUx)
{
  SET_BIT(TSUx->OPT, TSU_OPT_CCOCFEN);
}

/**
  * @brief  TSU set CCO CF disable.
  * @rmtoll OPT                    LL_TSU_CCOCFDisable
  * @param  TSUx TSU Instance
  */
__STATIC_INLINE void LL_TSU_CCOCFDisable(TSU_TypeDef *TSUx)
{
  CLEAR_BIT(TSUx->OPT, TSU_OPT_CCOCFEN);
}

/**
  * @brief  TSU set scan counter.
  * @rmtoll SCANNUM                    LL_TSU_SetScanNumber
  * @param  TSUx TSU Instance
  * @param  Number
  */
__STATIC_INLINE void LL_TSU_SetScanNumber(TSU_TypeDef *TSUx, uint32_t Number )
{
  MODIFY_REG(TSUx->SCANNUM, TSU_SCANNUM_SCANNUM, Number<<TSU_SCANNUM_SCANNUM_Pos);
}

/**
  * @brief  TSU get scan counter.
  * @rmtoll SCANNUM                    LL_TSU_GetScanIndex
  * @param  TSUx TSU Instance
  * @retval Scan count
  */
__STATIC_INLINE uint32_t LL_TSU_GetScanIndex(TSU_TypeDef *TSUx)
{
  return (uint32_t)(READ_BIT(TSUx->SCANNUM, TSU_SCANNUM_SCANCNT)>>TSU_SCANNUM_SCANCNT_Pos);
}

/**
  * @brief  TSU set auto judgment average window.
  * @rmtoll AJCTRL                    LL_TSU_SetAJAWin
  * @param  TSUx TSU Instance
  * @param  Win
  */
__STATIC_INLINE void LL_TSU_SetAJAWin(TSU_TypeDef *TSUx, uint32_t Win )
{
  MODIFY_REG(TSUx->AJCTRL, TSU_AJC_AJMMAT, Win<<TSU_AJC_AJMMAT_Pos);
}

/**
  * @brief  TSU set auto judgment condition.
  * @rmtoll AJCTRL                    LL_TSU_SetAJACondition
  * @param  TSUx TSU Instance
  * @param  Condition
  *       @arg @ref LL_TSU_AJC_1                 
  *       @arg @ref LL_TSU_AJC_2                 
  *       @arg @ref LL_TSU_AJC_3                 
  *       @arg @ref LL_TSU_AJC_4                 
  */
__STATIC_INLINE void LL_TSU_SetAJACondition(TSU_TypeDef *TSUx, uint32_t Condition )
{
  MODIFY_REG(TSUx->AJCTRL, TSU_AJC_JC, Condition);
}

/**
  * @brief  TSU set touch judgment criterion.
  * @rmtoll AJCTRL                    LL_TSU_SetTouchCriterion
  * @param  TSUx TSU Instance
  * @param  Criterion
  */
__STATIC_INLINE void LL_TSU_SetTouchCriterion(TSU_TypeDef *TSUx, uint32_t Criterion )
{
  MODIFY_REG(TSUx->AJCTRL, TSU_AJC_THOT, Criterion << TSU_AJC_THOT_Pos);
}

/**
  * @brief  TSU set non touch judgment criterion.
  * @rmtoll AJCTRL                    LL_TSU_SetNonTouchCriterion
  * @param  TSUx TSU Instance
  * @param  Criterion
  */
__STATIC_INLINE void LL_TSU_SetNonTouchCriterion(TSU_TypeDef *TSUx, uint32_t Criterion )
{
  MODIFY_REG(TSUx->AJCTRL, TSU_AJC_TLOT, Criterion << TSU_AJC_TLOT_Pos);
}

/**
  * @brief  TSU set touch judgment high threshold.
  * @rmtoll AJTHR                    LL_TSU_SetTouchThresholdHigh
  * @param  TSUx TSU Instance
  * @param  Threshold
  */
__STATIC_INLINE void LL_TSU_SetTouchThresholdHigh(TSU_TypeDef *TSUx, uint32_t Threshold )
{
  MODIFY_REG(TSUx->AJTHR, TSU_THR_AJTHH, Threshold << TSU_THR_AJTHH_Pos);
}

/**
  * @brief  TSU set touch judgment low threshold.
  * @rmtoll AJTHR                    LL_TSU_SetTouchThresholdLow
  * @param  TSUx TSU Instance
  * @param  Threshold
  */
__STATIC_INLINE void LL_TSU_SetTouchThresholdLow(TSU_TypeDef *TSUx, uint32_t Threshold )
{
  MODIFY_REG(TSUx->AJTHR, TSU_THR_AJTHL, Threshold << TSU_THR_AJTHL_Pos);
}

/**
  * @brief  TSU CTSM2HOST interrrupt enable.
  * @rmtoll INTEN                    LL_TSU_T2HInterruptEnable
  * @param  TSUx TSU Instance
  * @param  Interrupt
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MRRD     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MARRD    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_JRRD     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_BUSY     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_SCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_JCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_ERROR    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_IDLE     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_CORRCPLT 
  */
__STATIC_INLINE void LL_TSU_T2HInterruptEnable(TSU_TypeDef *TSUx, uint32_t Interrupt )
{
  SET_BIT(TSUx->INTEN, Interrupt);
}

/**
  * @brief  TSU CTSM2HOST interrrupt disable.
  * @rmtoll INTEN                    LL_TSU_T2HInterruptDisable
  * @param  TSUx TSU Instance
  * @param  Interrupt
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MRRD     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MARRD    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_JRRD     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_BUSY     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_SCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_JCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_ERROR    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_IDLE     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_CORRCPLT 
  */
__STATIC_INLINE void LL_TSU_T2HInterruptDisable(TSU_TypeDef *TSUx, uint32_t Interrupt )
{
  CLEAR_BIT(TSUx->INTEN, Interrupt);
}

/**
  * @brief  TSU CTSM2HOST Get interrrupt status.
  * @rmtoll INT_CTSM2HOST                    LL_TSU_T2HInterruptStatus
  * @param  Interrupt 
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MRRD     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MARRD    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_JRRD     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_BUSY     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_MCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_SCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_JCPLT    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_ERROR    
  *       @arg @ref LL_TSU_CTSM2HOST_IT_IDLE     
  *       @arg @ref LL_TSU_CTSM2HOST_IT_CORRCPLT 
  * @retval  status (SET or RESET)
  */
__STATIC_INLINE uint32_t LL_TSU_T2HGetInterruptStatus(uint32_t Interrupt)
{
  return (uint32_t)(READ_BIT(TSUSYS->INT_CTSM2HOST)? SET : RESET);
}

/**
  * @brief  TSU HOST2CTSM Send Command.
  * @rmtoll INT_HOST2CTSM                    LL_TSU_H2TSendCommand
  * @param  Command 
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_MSTOP     
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_MSTRT     
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_CSTRT     
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_SCSTRT    
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_DIASTRT   
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_TCSTRT    
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_IDCSTRT   
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_JINIT     
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_GETST     
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_AFC       
  *       @arg @ref  LL_TSU_HOST2CTSM_CMD_MSCAN     
  */
__STATIC_INLINE void LL_TSU_H2TSendCommand(uint32_t Command)
{
  SET_BIT(TSUSYS->INT_HOST2CTSM, Command);
  SET_BIT(TSUSYS->INT_HOST2CTSM, TSUSYS_H2CEVT_INTGEN);
  CLEAR_BIT(TSUSYS->INT_HOST2CTSM, TSUSYS_H2CEVT_INTGEN);
  CLEAR_BIT(TSUSYS->INT_HOST2CTSM, Command);
}

/**
  * @brief  TSU HOST2CTSM Clear Command.
  * @rmtoll CTSM_SYSCFG                    LL_TSU_H2TClearCommand
  */
__STATIC_INLINE void LL_TSU_H2TClearCommand(void)
{
  SET_BIT(TSUSYS->CTSM_SYSCFG, TSUSYS_SYSCFG_INTCLR);
}

/**
  * @brief  TSU set AFC reference clock divider.
  * @rmtoll CTSM_SYSCFG                    LL_TSU_SetAFCRefCLkDivider
  * @param  Divider
  */
__STATIC_INLINE void LL_TSU_SetAFCRefCLkDivider(uint32_t Divider)
{
  MODIFY_REG(TSUSYS->CTSM_SYSCFG, TSUSYS_SYSCFG_AFCRDIV, Divider<<TSUSYS_SYSCFG_AFCRDIV_Pos);
}

/**
  * @brief  TSU Reset.
  * @rmtoll CTSM_SYSCFG                    LL_TSU_Reset
  */
__STATIC_INLINE void LL_TSU_Reset(void)
{
  CLEAR_BIT(TSUSYS->CTSM_SYSCFG, TSUSYS_SYSCFG_RST);
}

/**
  * @brief  TSU Release Reset.
  * @rmtoll CTSM_SYSCFG                    LL_TSU_RelaeseReset
  */
__STATIC_INLINE void LL_TSU_RelaeseReset(void)
{
  SET_BIT(TSUSYS->CTSM_SYSCFG, TSUSYS_SYSCFG_RST);
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup TSU_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_TSU_DeInit(TSU_TypeDef *TSUx);

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

#endif /* defined(TSU) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_TSU_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
