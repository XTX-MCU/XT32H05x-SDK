/**
  ******************************************************************************
  * @file    xt32h0xx_hal_tsu.c
  * @author  Software Team
  * @brief   TSU HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the TSU peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup TSU CTSM
  * @brief TSU HAL module driver.
  * @{
  */

#ifdef HAL_TSU_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
//typedef struct st_ctsu_correction_calc
//{
//    ctsu_range_t range;
//    uint16_t     snum;
//    uint16_t     sdpa;
//    uint16_t     cfc;
//    ctsu_md_t    md;
//} ctsu_correction_calc_t;

//typedef struct st_ctsu_correction_multi
//{
//    uint16_t pri[CTSU_CFG_NUM_SUMULTI];
//    uint16_t snd[CTSU_CFG_NUM_SUMULTI];
//    uint32_t offset[CTSU_CFG_NUM_SUMULTI];
//    uint8_t  selected_freq;
//} ctsu_correction_multi_t;

/* Private define ------------------------------------------------------------*/
/** @defgroup TSU_Private_Define TSU Private definitions
  * @{
  */
//#define TSU_TUNING_MAX                      (0x03FF)
//#define TSU_TUNING_MIN                      (0x0000)
//#define TSU_TUNING_VALUE_SELF               (15360)
//#define TSU_TUNING_VALUE_MUTUAL             (10240)
//#define TSU_TUNING_OT_COUNT                 (25)

//#define TSU_SST_RECOMMEND                   (0x1F) // The recommend value of SST
//#define TSU_SST_RECOMMEND_CURRENT           (0x3F) // The recommend value of SST with current
//#define TSU_SNUM_RECOMMEND                  (0x07) // The value of SNUM should be fixed
//#define TSU_SNUM_MAX                        (0xFF) // The maximum value of SNUM
//#define TSU_ICOMP0                          (0x80) // ICOMP0 bit
//#define TSU_ICOMP1                          (0x40) // ICOMP1 bit
//#define TSU_ICOMPRST                        (0x20) // ICOMPRST bit
//#define TSU_CR0_MODIFY_BIT                  (0xC0) // TXVSEL
//#define TSU_CR2_MODIFY_BIT                  (0x33) // POSEL, ATUNE2, MD2
//#define TSU_SUADJ_MAX                       (0xFF) // The maximum value of SUADJx
//#define TSU_SUADJ_SSCNT_ADJ                 (0x20) // The value of Adjusting SCADJx by SSCNT
//#define TSU_MUTUAL_BUF_SIZE                 (TSU_CFG_NUM_SUMULTI * 2)

//#if (TSU_CFG_LOW_VOLTAGE_MODE == 0)
//#define TSU_CORRECTION_STD_VAL            (19200) // 20UC standard value
//#define TSU_CORRECTION_STD_UNIT           (1920)  // 2UC value
//#define TSU_CORRECTION_STD_EXREG          (14400) // External registance standard value
//#define TSU_CORRECTION_OFFSET_UNIT        (120)   // (7680 / 64)
//#else
//#define TSU_CORRECTION_STD_VAL            (15360) // 20UC standard value * 0.8
//#define TSU_CORRECTION_STD_UNIT           (1536)  // 2UC value * 0.8
//#define TSU_CORRECTION_STD_EXREG          (11520) // External registance standard value
//#define TSU_CORRECTION_OFFSET_UNIT        (96)    // (7680 / 64) * 0.8
//#endif
//#define TSU_CORRECTION_SUMULTI             (0x20)  // SUMULTI step
//#define TSU_CORRECTION_TRIMB_MAX           (0xFF)
//#define TSU_CORRECTION_TRIMB_SIGN_BIT      (0x80)
//#define TSU_CORRECTION_RTRIM_THRESHOLD1    (0xA0)
//#define TSU_CORRECTION_RTRIM_THRESHOLD2    (0x50)
//#define TSU_CORRECTION_TRIMB_THRESHOLD1    (0xC0)
//#define TSU_CORRECTION_TRIMB_THRESHOLD2    (0x3F)
//#define TSU_CORRECTION_BIT16               (0x10000)
//#define TSU_CORRECTION_BIT10               (0x0400)
//#define TSU_CORRECTION_BIT9                (0x0200)
//#define TSU_CORRECTION_BIT8                (0x0100)
//#define TSU_CORRECTION_BIT7                (0x0080)
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @defgroup TSU_Private_Functions TSU Private Functions
  * @{
  */
//static uint16_t      tsu_element_index = 0;
//static uint8_t       tsu_tuning_count[TSU_CFG_NUM_SELF_ELEMENTS + TSU_CFG_NUM_MUTUAL_ELEMENTS];
//static int32_t       tsu_tuning_diff[TSU_CFG_NUM_SELF_ELEMENTS + TSU_CFG_NUM_MUTUAL_ELEMENTS];
//static uint32_t      tsu_ctsuwr[(TSU_CFG_NUM_SELF_ELEMENTS + TSU_CFG_NUM_MUTUAL_ELEMENTS) * TSU_CFG_NUM_SUMULTI];
//#if (TSU_CFG_NUM_SELF_ELEMENTS != 0)
//static uint16_t      tsu_self_element_index = 0;
//static uint16_t      tsu_self_raw[TSU_CFG_NUM_SELF_ELEMENTS * TSU_CFG_NUM_SUMULTI];
//static uint16_t      tsu_self_corr[TSU_CFG_NUM_SELF_ELEMENTS * TSU_CFG_NUM_SUMULTI];
//static uint16_t      tsu_self_data[TSU_CFG_NUM_SELF_ELEMENTS];
//#endif
//#if (TSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
//static uint16_t      tsu_mutual_element_index = 0;
//static uint16_t      tsu_mutual_raw[TSU_CFG_NUM_MUTUAL_ELEMENTS * TSU_MUTUAL_BUF_SIZE];
//static uint16_t      tsu_mutual_pri_corr[TSU_CFG_NUM_MUTUAL_ELEMENTS * TSU_CFG_NUM_SUMULTI];
//static uint16_t      tsu_mutual_snd_corr[TSU_CFG_NUM_MUTUAL_ELEMENTS * TSU_CFG_NUM_SUMULTI];
//static uint16_t      tsu_mutual_pri_data[TSU_CFG_NUM_MUTUAL_ELEMENTS];
//static uint16_t      tsu_mutual_snd_data[TSU_CFG_NUM_MUTUAL_ELEMENTS];
//#endif
//static ctsu_correction_info_t g_ctsu_correction_info;

//#if (CTSU_CFG_DTC_SUPPORT_ENABLE == 1)
// #if (CTSU_CFG_AUTO_JUDGE_ENABLE == 0)
//static dtc_transfer_data_cfg_t      g_transfer_info_tx;
//static dtc_transfer_data_cfg_t      g_transfer_info_rx;
//static dtc_transfer_data_t          g_transfer_data_tx;
//static dtc_transfer_data_t          g_transfer_data_rx;
//static dtc_cmd_arg_t                g_ctsu_dtc_cmd_arg;         /* DTC command argument */
//static dtc_transfer_data_cfg_t      g_ctsu_dtc_info;            /* table of DTC setting information */
// #else
//static dtc_transfer_data_t          g_transfer_data_auto_tx[6];
//static dtc_transfer_data_t          g_transfer_data_auto_rx[6];
//static dtc_cmd_arg_t                g_ctsu_dtc_cmd_arg;         /* DTC command argument */
//static dtc_transfer_data_cfg_t      g_ctsu_dtc_auto_info[6];    /* table of DTC setting information */
// #endif
//#endif

//#if (CTSU_CFG_DIAG_SUPPORT_ENABLE == 1)
//static HAL_TSU_DiagInfoTypeDef      tsu_diag_info;
//static tsu_diag_save_reg_t tsu_diag_reg;
//#endif

//#if (CTSU_CFG_AUTO_JUDGE_ENABLE == 1)
//static HAL_TSU_AutoJudgeTypeDef tsu_auto_judge[(TSU_CFG_NUM_SELF_ELEMENTS + TSU_CFG_NUM_MUTUAL_ELEMENTS) * TSU_CFG_NUM_SUMULTI];
//#endif

//#if (CTSU_CFG_NUM_SELF_ELEMENTS != 0)
//uint8_t tsu_selected_freq_self[TSU_CFG_NUM_SELF_ELEMENTS];
//#endif
//#if (CTSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
//uint8_t tsu_selected_freq_mutual[TSU_CFG_NUM_MUTUAL_ELEMENTS];
//#endif

//static uint32_t TSU_Calibrate(TSU_HandleTypeDef *htsu);
//static uint32_t TSU_Configure(TSU_HandleTypeDef *htsu);

//static uint32_t TSU_CorrectProcess(TSU_HandleTypeDef *htsu);
//static uint32_t TSU_CorrectExec(TSU_HandleTypeDef *htsu);

//#if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 0)
//void TSU_CorrectionCalc (uint16_t * correction_data, uint16_t raw_data, ctsu_correction_calc_t * p_calc);
//#endif
//void TSU_CorrectionFleq (ctsu_correction_multi_t * p_multi, uint16_t * p_pri, uint16_t * p_snd);
//void TSU_CorrectionMulti (ctsu_correction_multi_t * p_multi, uint16_t * p_pri, uint16_t * p_snd);
//void TSU_CorrectionMeasurement (TSU_HandleTypeDef * htsu, uint16_t * data);
 #if (CTSU_CFG_TEMP_CORRECTION_SUPPORT == 1)
static void ctsu_correction_scan_start(void);
static void ctsu_correction_data_get(TSU_HandleTypeDef * htsu, uint16_t * p_data);

  #if (CTSU_CFG_CALIB_RTRIM_SUPPORT == 1)
static void ctsu_correction_calib_rtrim(TSU_HandleTypeDef * htsu, uint16_t * p_data);

  #endif
 #endif
 #if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 1)
static void ctsu_auto_correction_register_set (TSU_HandleTypeDef *htsu);
 #endif

#if (CTSU_CFG_AUTO_JUDGE_ENABLE == 1)
void ctsu_auto_jugde_threshold_calc (TSU_HandleTypeDef *htsu);
#endif

//static uint32_t TSU_InitOffsetTuning(TSU_HandleTypeDef *htsu);

//void TSU_MovingAverage (uint16_t * p_average, uint16_t new_data, uint16_t average_num);

//static void TSU_EndISR(TSU_HandleTypeDef *htsu);
//static void TSU_RDISR(TSU_HandleTypeDef *htsu);
//static void TSU_WRISR(TSU_HandleTypeDef *htsu);
//static void TSU_ProcessOverflow(TSU_HandleTypeDef *htsu);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup TSU_Exported_Functions TSU Exported Functions
  * @{
  */

/** @defgroup TSU_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions.
  *
@verbatim
 ===============================================================================
            ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Initialize the TSU according to the specified parameters
          in the TSU_InitTypeDef and create the associated handle
      (+) DeInitialize the TSU peripheral
      (+) Initialize the TSU MSP (MCU Specific Package)
      (+) DeInitialize the TSU MSP

@endverbatim
  * @{
  */

/**
  * @brief  Initialize the TSU according to the specified
  *         parameters in the TSU_InitTypeDef and create the associated handle.
  * @param  htsu TSU handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TSU_Init(TSU_HandleTypeDef *htsu)
{
  HAL_StatusTypeDef          err = HAL_OK;
	
//	uint32_t tmp = 0;

  /* Check the TSU handle allocation */
  if (htsu == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_TSU_ALL_INSTANCE(htsu->Instance));

  if (htsu->State == HAL_TSU_STATE_RESET)
  {
    /* Allocate lock resource and initialize it */
    htsu->Lock = HAL_UNLOCKED;
    /* Init the low level hardware */
    HAL_TSU_MspInit(htsu);
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* Initialize driver control structure (address setting) */
	
	/* clock configure */
//	tmp = (HAL_RCC_GetPCLKFreq()/htsu->Init.OperationClock - 1) << TSU_DIV_BDIV_Pos;
//	MODIFY_REG(htsu->Instance->DIV, TSU_DIV_BDIV, tmp); 
	
	/* trigger mode*/
//	MODIFY_REG(htsu->Instance->DCTRL, TSU_DCTRL_MSS, htsu->Init.TriggerMode);                 /*!< MSS */

	/* pin configure */
	//htsu->Instance->CHEN = htsu->Init.PinCfg;
	
	/* sensor pulse configure */
	MODIFY_REG(htsu->Instance->DCTRL, TSU_DCTRL_SDPSEL, htsu->Init.SensorPulseMode); /*!< Sensor pulse mode. (CTRL0.SDPSEL) This parameter is a value of @ref TSU_SENSOR_DRIVE_PULSE_MODE*/
	
	/* ccobias, cmode configure */
	MODIFY_REG(htsu->Instance->ACTRL, TSU_ACTRL_CCOBS|TSU_ACTRL_CMD, htsu->Init.CcoBias | htsu->Init.CurrentMode); 
	
	/* spread spectrum initalial */
	MODIFY_REG(htsu->Instance->DCTRL, TSU_DCTRL_SOFF, htsu->Init.SpreadSpectrumEnable);
	MODIFY_REG(htsu->Instance->DIV, TSU_DIV_SSDIV, htsu->Init.SpreadSpectrumCnt);

  /* PRG initalial */
  MODIFY_REG(htsu->Instance->DCTRL, TSU_DCTRL_PROFF | TSU_DCTRL_PHT | TSU_DCTRL_PHS, htsu->Init.PrnEnable | htsu->Init.PrnGenerateCycle | htsu->Init.PrnUpdateCycle);
	
	/* SUCLK SS */
	MODIFY_REG(htsu->Instance->AD, TSU_AD_SSCTRL, htsu->Init.SUCLKSSMode);
  MODIFY_REG(htsu->Instance->AD, TSU_AD_SSNUM, htsu->Init.SUCLKSSPeriod << TSU_AD_SSNUM_Pos);
	
	/* tuning */
	MODIFY_REG(htsu->Instance->OPT, TSU_OPT_TUNEN, htsu->Init.TuningEnable);
	

  /* Change TSU peripheral state */
  htsu->State = HAL_TSU_STATE_READY;

  /* Return function status */
  return err;
}

/**
  * @brief  DeInitialize the TSU peripheral.
  * @param  htsu TSU handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TSU_DeInit(TSU_HandleTypeDef *htsu)
{
  /* Check the TSU handle allocation */
  if (htsu == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_TSU_ALL_INSTANCE(htsu->Instance));

  /* Check the TSU peripheral state */
  if (htsu->State == HAL_TSU_STATE_BUSY)
  {
    return HAL_BUSY;
  }

  /* Change TSU peripheral state */
  htsu->State = HAL_TSU_STATE_BUSY;

  /* DeInit the low level hardware */
  HAL_TSU_MspDeInit(htsu);

  /* Change TSU peripheral state */
  htsu->State = HAL_TSU_STATE_RESET;

  /* Process unlocked */
  __HAL_UNLOCK(htsu);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief link dma with TSU.
  * @param htsu TSU handle.
  * @param hdmarx DMA handle.
  * @param hdmatx DMA handle.
  * @retval Status
  */
HAL_StatusTypeDef HAL_TSU_LinkDMA(TSU_HandleTypeDef *htsu, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx)
{
	if(htsu == NULL) return HAL_ERROR;
	
	if(hdmarx != NULL)
	{
    htsu->hdmarx = hdmarx;
		hdmarx->Parent = htsu;
	}
	
	if(hdmatx != NULL)
	{
    htsu->hdmatx = hdmatx;
		hdmatx->Parent = htsu;
	}

	return HAL_OK;
}

/**
  * @brief  Initializes the TSU MSP.
  * @param  htsu TSU handle
  */
__weak void HAL_TSU_MspInit(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_MspInit can be implemented in the user file
   */
}

/**
  * @brief  DeInitialize the TSU MSP.
  * @param  htsu TSU handle
  */
__weak void HAL_TSU_MspDeInit(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_MspDeInit can be implemented in the user file
   */
}


#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User TSU Callback
  *         To be used instead of the weak predefined callback
  * @param  htsu uart handle
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *         @arg @ref HAL_TSU_ERROR_CB_ID        
  *         @arg @ref HAL_TSU_ABORT_CB_ID        
  *         @arg @ref HAL_TSU_TXABORT_CB_ID      
  *         @arg @ref HAL_TSU_RXABORT_CB_ID      
  *         @arg @ref HAL_TSU_MEASUREEND_CB_ID   
  *         @arg @ref HAL_TSU_SCANEND_CB_ID      
  *         @arg @ref HAL_TSU_JUDGMENTEND_CB_ID  
  *         @arg @ref HAL_TSU_CORRECTEND_CB_ID   
  *         @arg @ref HAL_TSU_MSPINIT_CB_ID      
  *         @arg @ref HAL_TSU_MSPDEINIT_CB_ID    
  *         @arg @ref HAL_TSU_DMATX_TFR_CB_ID    
  *         @arg @ref HAL_TSU_DMATX_BLOCK_CB_ID  
  *         @arg @ref HAL_TSU_DMATX_SRCTRAN_CB_ID
  *         @arg @ref HAL_TSU_DMATX_DSTTRAN_CB_ID
  *         @arg @ref HAL_TSU_DMARX_TFR_CB_ID    
  *         @arg @ref HAL_TSU_DMARX_BLOCK_CB_ID  
  *         @arg @ref HAL_TSU_DMARX_SRCTRAN_CB_ID
  *         @arg @ref HAL_TSU_DMARX_DSTTRAN_CB_ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TSU_RegisterCallback(TSU_HandleTypeDef *htsu, HAL_TSU_CallbackIDTypeDef CallbackID,
                                            pTSU_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    htsu->ErrorCode |= HAL_TSU_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  __HAL_LOCK(htsu);

  switch (CallbackID)
  {
	  case HAL_TSU_ERROR_CB_ID:
      htsu->ErrorCallback = pCallback;
      break;
    case HAL_TSU_ABORT_CB_ID:
      htsu->AbortCpltCallback = pCallback;
      break;
    case HAL_TSU_TXABORT_CB_ID:
      htsu->AbortTransmitCpltCallback = pCallback;
      break;
    case HAL_TSU_RXABORT_CB_ID:
      htsu->AbortReceiveCpltCallback = pCallback;
      break;
    case HAL_TSU_MEASUREEND_CB_ID:
      htsu->MeasurmentClpCallback = pCallback;
      break;
    case HAL_TSU_SCANEND_CB_ID:
      htsu->ScanClpCallback = pCallback;
      break;
    case HAL_TSU_JUDGMENTEND_CB_ID:
      htsu->JudgmentClpCallback = pCallback;
      break;
    case HAL_TSU_MSPINIT_CB_ID:
      htsu->MspInitCallback = pCallback;
      break;
    case HAL_TSU_MSPDEINIT_CB_ID:
      htsu->MspDeInitCallback = pCallback;
      break;
    case HAL_TSU_DMATX_TFR_CB_ID:
      htsu->DMATxCpltCallback = pCallback;
      break;
    case HAL_TSU_DMATX_BLOCK_CB_ID:
      htsu->DMATxBlockCallback = pCallback;
      break;
    case HAL_TSU_DMATX_SRCTRAN_CB_ID:
      htsu->DMATxSrcTranCallback = pCallback;
      break;
    case HAL_TSU_DMATX_DSTTRAN_CB_ID:
      htsu->DMATxDstTranCallback = pCallback;
      break;
    case HAL_TSU_DMARX_TFR_CB_ID:
      htsu->DMARxCpltCallback = pCallback;
      break;
    case HAL_TSU_DMARX_BLOCK_CB_ID:
      htsu->DMARxBlockCallback = pCallback;
      break;
    case HAL_TSU_DMARX_SRCTRAN_CB_ID:
      htsu->DMARxSrcTranCallback = pCallback;
      break;
    case HAL_TSU_DMARX_DSTTRAN_CB_ID:
      htsu->DMARxDstTranCallback = pCallback;
      break;
  }
  
  __HAL_UNLOCK(htsu);

  return status;

}

/**
  * @brief  Unregister an TSU Callback
  *         TSU callaback is redirected to the weak predefined callback
  * @param  htsu tsu handle
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *         @arg @ref HAL_TSU_ERROR_CB_ID        
  *         @arg @ref HAL_TSU_ABORT_CB_ID        
  *         @arg @ref HAL_TSU_TXABORT_CB_ID      
  *         @arg @ref HAL_TSU_RXABORT_CB_ID      
  *         @arg @ref HAL_TSU_MEASUREEND_CB_ID   
  *         @arg @ref HAL_TSU_SCANEND_CB_ID      
  *         @arg @ref HAL_TSU_JUDGMENTEND_CB_ID  
  *         @arg @ref HAL_TSU_CORRECTEND_CB_ID   
  *         @arg @ref HAL_TSU_MSPINIT_CB_ID      
  *         @arg @ref HAL_TSU_MSPDEINIT_CB_ID    
  *         @arg @ref HAL_TSU_DMATX_TFR_CB_ID    
  *         @arg @ref HAL_TSU_DMATX_BLOCK_CB_ID  
  *         @arg @ref HAL_TSU_DMATX_SRCTRAN_CB_ID
  *         @arg @ref HAL_TSU_DMATX_DSTTRAN_CB_ID
  *         @arg @ref HAL_TSU_DMARX_TFR_CB_ID    
  *         @arg @ref HAL_TSU_DMARX_BLOCK_CB_ID  
  *         @arg @ref HAL_TSU_DMARX_SRCTRAN_CB_ID
  *         @arg @ref HAL_TSU_DMARX_DSTTRAN_CB_ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_TSU_UnRegisterCallback(TSU_HandleTypeDef *htsu, HAL_TSU_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  __HAL_LOCK(htsu);

  switch (CallbackID)
  {
	  case HAL_TSU_ERROR_CB_ID:
      htsu->ErrorCallback = HAL_TSU_ErrorCallback;
      break;
    case HAL_TSU_ABORT_CB_ID:
      htsu->AbortCpltCallback = HAL_TSU_AbortCpltCallback;
      break;
    case HAL_TSU_TXABORT_CB_ID:
      htsu->AbortTransmitCpltCallback = HAL_TSU_AbortTransmitCpltCallback;
      break;
    case HAL_TSU_RXABORT_CB_ID:
      htsu->AbortReceiveCpltCallback = HAL_TSU_AbortReceiveCpltCallback;
      break;
    case HAL_TSU_MEASUREEND_CB_ID:
      htsu->MeasurmentClpCallback = HAL_TSU_MeasurmentEndCallback;
      break;
    case HAL_TSU_SCANEND_CB_ID:
      htsu->ScanClpCallback = HAL_TSU_ScanEndCallback;
      break;
    case HAL_TSU_JUDGMENTEND_CB_ID:
      htsu->JudgmentClpCallback = HAL_TSU_JudgmentEndCallback;
      break;
    case HAL_TSU_MSPINIT_CB_ID:
      htsu->MspInitCallback = HAL_TSU_MspInit;
      break;
    case HAL_TSU_MSPDEINIT_CB_ID:
      htsu->MspDeInitCallback = HAL_TSU_MspDeInit;
      break;
    case HAL_TSU_DMATX_TFR_CB_ID:
      htsu->DMATxCpltCallback = HAL_TSU_TxCpltCallback;
      break;
    case HAL_TSU_DMATX_BLOCK_CB_ID:
      htsu->DMATxBlockCallback = NULL;
      break;
    case HAL_TSU_DMATX_SRCTRAN_CB_ID:
      htsu->DMATxSrcTranCallback = NULL;
      break;
    case HAL_TSU_DMATX_DSTTRAN_CB_ID:
      htsu->DMATxDstTranCallback = NULL;
      break;
    case HAL_TSU_DMARX_TFR_CB_ID:
      htsu->DMARxCpltCallback = HAL_TSU_RxCpltCallback;
      break;
    case HAL_TSU_DMARX_BLOCK_CB_ID:
      htsu->DMARxBlockCallback = NULL;
      break;
    case HAL_TSU_DMARX_SRCTRAN_CB_ID:
      htsu->DMARxSrcTranCallback = NULL;
      break;
    case HAL_TSU_DMARX_DSTTRAN_CB_ID:
      htsu->DMARxDstTranCallback = NULL;
      break;
  }
  __HAL_UNLOCK(htsu);

  return status;
}

#endif /* USE_HAL_TSU_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup TSU_Exported_Functions_Group2 Peripheral Control functions
  *  @brief    management functions.
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) compute the 7, 8, 16 or 32-bit TSU value of an 8, 16 or 32-bit data buffer
          using combination of the previous TSU value and the new one.

       [..]  or

      (+) compute the 7, 8, 16 or 32-bit TSU value of an 8, 16 or 32-bit data buffer
          independently of the previous TSU value.

@endverbatim
  * @{
  */

/**
  * @brief  Normal scan configuration.
  * @param  htsu TSU handle
  * @param  scancfg scan configure
  * @retval HAL_StatusTypeDef TSU (returned value LSBs for TSU shorter than 32 bits)
  */
HAL_StatusTypeDef HAL_TSU_ScanConfig(TSU_HandleTypeDef *htsu, TSU_ScanTypeDef *scancfg)
{
	uint32_t temp = 0;
	uint32_t clk = 0;
	
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;
	
	/* scan number */
	MODIFY_REG(htsu->Instance->SCANNUM, TSU_SCANNUM_SCANNUM, scancfg->ScanNum);
	
	/* MD, MCA, CHEN, CHCTRL */
	MODIFY_REG(htsu->Instance->DCTRL, TSU_DCTRL_MD0|TSU_DCTRL_MD, scancfg->ScanMode);
	
	temp = (scancfg->FreqPattern & 0x1);
	temp += ((scancfg->FreqPattern & 0x2)>>1);
	temp += ((scancfg->FreqPattern & 0x4)>>2);
	temp += ((scancfg->FreqPattern & 0x8)>>3);
	
	htsu->Instance->SUCLK1 = scancfg->Freq[0];
	htsu->Instance->SUCLK2 = scancfg->Freq[1];
	htsu->Instance->SUCLK3 = scancfg->Freq[2];
	htsu->Instance->SUCLK4 = scancfg->Freq[3];
	
	clk = 384*(HAL_RCC_GetSysClockFreq()/1000/1000/2)/temp - 1;
	
	MODIFY_REG(htsu->Instance->TS, TSU_TS_MSNUM, clk << TSU_TS_MSNUM_Pos);
	
	if(htsu->Init.SensorPulseMode == TSU_DCTRL_SDPSEL)
	{
	  clk = (HAL_RCC_GetSysClockFreq()/1000/1000/2) - 1;  //n+1 2M
	}
	else
	{
	  clk = ((HAL_RCC_GetSysClockFreq()/1000/1000/2) - 1)/2;  //2(n+1) 1M
	}
	//clk = 4;   //TSU_SDPMODE_RANDOM
	clk = 11;   //TSU_SDPMODE_HIGHRESOLUTION
	MODIFY_REG(htsu->Instance->DIV, TSU_DIV_BDIV, clk << TSU_DIV_BDIV_Pos);
	
	htsu->Instance->FRECFG = scancfg->FreqPattern;
	MODIFY_REG(htsu->Instance->OPT, TSU_OPT_FREJFEN, scancfg->FreqJudgmentEnable);
	
	htsu->Instance->CHEN = scancfg->ChannelEnable;
	htsu->Instance->CHCTRL = scancfg->ChannleMode;

	MODIFY_REG(htsu->Instance->PS, TSU_PS_NMPSEL|TSU_PS_SHDPSEL, scancfg->ShieldOutput | scancfg->NonMeasureOutput);
	
	/* auto-judgment enable */
	MODIFY_REG(htsu->Instance->OPT, TSU_OPT_AJFEN, scancfg->AutoJudgeEnable);
	MODIFY_REG(htsu->Instance->AJCTRL, TSU_AJC_JC, scancfg->AutoJudgeCondition);
	
	/* auto-correction enable */
	MODIFY_REG(htsu->Instance->OPT, TSU_OPT_CCOCFEN, scancfg->AutoCorrectionEnable);
	

	/* interrupts enable */
	htsu->Instance->INTEN = scancfg->InterruptEnable;

	/*init for simulation*/
	MODIFY_REG(htsu->Instance->TRIM0, TSU_TRIM_RTRIM, 0x10 <<TSU_TRIM_RTRIM_Pos);
	MODIFY_REG(htsu->Instance->TRIM0, TSU_TRIM_SUADJD, 0x30 <<TSU_TRIM_SUADJD_Pos);
	
	htsu->Instance->TRIM1 = 0x30303030UL;
	
	htsu->State = HAL_TSU_STATE_READY;
	
	return HAL_OK;
}

/**
  * @brief  AFC configuration.
  * @param  htsu TSU handle
  * @param  afccfg AFC configure
  * @retval HAL_StatusTypeDef TSU (returned value LSBs for TSU shorter than 32 bits)
  */
HAL_StatusTypeDef HAL_TSU_AFCConfig(TSU_HandleTypeDef *htsu, TSU_AFCTypeDef *afccfg)
{
	//period
	MODIFY_REG(htsu->Instance->AFCCTRL, TSU_AFCCTRL_AFCPRD, (afccfg->AFCPeriod) << TSU_AFCCTRL_AFCPRD_Pos);  //@us
	
	//sysclk
	MODIFY_REG(htsu->Instance->OPT, TSU_OPT_SYSCLK, afccfg->SysClk);  //32M
	
	//divider
	MODIFY_REG(TSUSYS->CTSM_SYSCFG, TSUSYS_SYSCFG_AFCRDIV, afccfg->RefclkDivider << TSUSYS_SYSCFG_AFCRDIV_Pos);  //4M
	
	//clk sel
	MODIFY_REG(htsu->Instance->AFCCFG, TSU_AFCCFG_CBCLKS, afccfg->Clock);  //suclk/cco
	
	//diff
	MODIFY_REG(htsu->Instance->AFCCTRL, TSU_AFCCTRL_DIFFCNT, afccfg->Diff << TSU_AFCCTRL_DIFFCNT_Pos); 

  return HAL_OK;
}

/**
  * @brief  Compute the 8, 16 or 32-bit TSU value of an 8, 16 or 32-bit data buffer
  *         starting with the previously computed TSU as initialization value.
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef TSU (returned value LSBs for TSU shorter than 32 bits)
  */
HAL_StatusTypeDef HAL_TSU_NormalScanStart(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* send normal measurement event */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_MSTRT|SYSCFG_CTSM_INT_INTGEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_SCANNING;

  return HAL_OK;
}

/**
  * @brief  Stop measurement
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_TSU_CorrectScanStart(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* Set CTSU_STRT bit to start scan */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_CSTRT|SYSCFG_CTSM_INT_INTGEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_SCANNING;

  return HAL_OK;
}

/**
  * @brief  Stop measurement
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_TSU_TempCorrectScanStart(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* Set CTSU_STRT bit to start scan */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_TCSTRT|SYSCFG_CTSM_INT_INTGEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_SCANNING;

  return HAL_OK;
}

/**
  * @brief  Stop measurement
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_TSU_CurrectScanStart(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* Set CTSU_STRT bit to start scan */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_DCSTRT|SYSCFG_CTSM_INT_INTGEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_SCANNING;

  return HAL_OK;
}

/**
  * @brief  Stop measurement
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_TSU_IntCurrectScanStart(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* Set CTSU_STRT bit to start scan */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_IDCSTRT|SYSCFG_CTSM_INT_INTGEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_SCANNING;

  return HAL_OK;
}

/**
  * @brief  Stop measurement
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_TSU_DiagnosisScanStart(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* Set CTSU_STRT bit to start scan */
  //SET_BIT(htsu->Instance->EXTEVT, TSU_EXTEVT_DIASTRT|TSU_EXTEVT_GEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_SCANNING;

  return HAL_OK;
}

/**
  * @brief  Stop measurement
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_TSU_ScanStop(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State == HAL_TSU_STATE_SCANNING)
  {
    /* Stop measurement and reset block */
    SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_MSTOP|SYSCFG_CTSM_INT_INTGEN);
    
    /* disable interrupt */
    
    /* Change TSU peripheral state */
    htsu->State = HAL_TSU_STATE_READY;
  }

  /* Return the TSU computed value */
  return HAL_OK;
}

/**
  * @brief  Stop measurement
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef
  */
HAL_StatusTypeDef HAL_TSU_IsBusy(TSU_HandleTypeDef *htsu)
{
  /* Get CTSM state */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_GETST|SYSCFG_CTSM_INT_INTGEN);
    
  /* Return the TSU computed value */
  return HAL_OK;
}

/**
  * @brief  Compute the 8, 16 or 32-bit TSU value of an 8, 16 or 32-bit data buffer
  *         starting with the previously computed TSU as initialization value.
  * @param  htsu TSU handle
  * @retval HAL_StatusTypeDef TSU (returned value LSBs for TSU shorter than 32 bits)
  */
HAL_StatusTypeDef HAL_TSU_AFCStart(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* send normal measurement event */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_AFC|SYSCFG_CTSM_INT_INTGEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_SCANNING;

  return HAL_OK;
}

/**
  * @brief  Read measure result
  * @param  pBuffer a pointer to output buffer
  * @param  size expect read data size 
  * @retval read data size
  */
uint32_t HAL_TSU_MeasureDataGet(uint32_t* pBuffer, uint32_t size)
{
	uint32_t res = size;
	
	uint32_t* pscr = (uint32_t*)TSU_MRSLT_BASE;
	
	int i = 0;
	
	if(size > TSU_MRSLT_SIZE)
	{ 
		res = TSU_MRSLT_SIZE;
	}
	
	for(i=0; i< res; i++)
	{
		*pBuffer++ = *pscr++;
	}

  return res;
}

/**
  * @brief  Read judge result
  * @param  pBuffer a pointer to output buffer
  * @param  size expect read data size 
  * @retval read data size
  */
uint32_t HAL_TSU_AutoJudgmentDataGet(uint32_t* pBuffer, uint32_t size)
{
	uint32_t res = size;
	
	uint32_t* pscr = (uint32_t*)TSU_JRSLT_BASE;
	
	int i = 0;
	
	if(size > TSU_JRSLT_SIZE)
	{ 
		res = TSU_JRSLT_SIZE;
	}
	
	for(i=0; i< res; i++)
	{
		*pBuffer++ = *pscr++;
	}

  return res;
}

/**
  * @brief  Judgment initial
  * @param  htsu tsu handle 
  * @retval Hal status
  */
HAL_StatusTypeDef HAL_TSU_JudgInit(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* send normal measurement event */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_JINIT|SYSCFG_CTSM_INT_INTGEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_READY;

  return HAL_OK;
}

/**
  * @brief  Sensor offset initial
  * @param  htsu tsu handle 
  * @retval Hal status
  */
HAL_StatusTypeDef HAL_TSU_SensorOffsetInit(TSU_HandleTypeDef *htsu)
{
  /* Change TSU peripheral state */
  if( htsu->State != HAL_TSU_STATE_READY)
  {
    return HAL_ERROR;
  }

  htsu->State = HAL_TSU_STATE_BUSY;

  /* config */

  /* send normal measurement event */
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_SOINIT|SYSCFG_CTSM_INT_INTGEN);

  /* Change TSU peripheral state */
  htsu->ErrorCode = HAL_TSU_ERROR_NONE;
  htsu->State = HAL_TSU_STATE_READY;

  return HAL_OK;
}

/**
  * @}
  */

/** @addtogroup TSU_Exported_Functions_Group3
  * @{
  */

/**
  * @brief Handle TSU interrupt response.
  * @param htsu TSU handle.
  */
void HAL_TSU_IRQHandler(TSU_HandleTypeDef *htsu)
{
	uint32_t evt = SYSCFG->CTSM_SR;
	/*read flag*/
	
	if (evt & TSU_EVT_MRRD)
	{
		HAL_TSU_MeasurmentEndCallback(htsu);
	}
	
	if (evt & TSU_EVT_MARRD)
	{
		HAL_TSU_MeasurmentEndCallback(htsu);
	}

	if (evt & TSU_EVT_JRRD)
	{
	}

	if (evt & TSU_EVT_MCLPT)
	{
		HAL_TSU_MeasurmentAllChannelEndCallback(htsu);
		
#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
      if (htsu->MeasurmentClpCallback != NULL)
      {
        /* Half transfer callback */
        htsu->MeasurmentClpCallback(htsu);
      }
#endif
	}

	if (evt & TSU_EVT_SCANCPLT)
	{
		htsu->State = HAL_TSU_STATE_READY;
		
		HAL_TSU_ScanEndCallback(htsu);
		
#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
      if (htsu->ScanClpCallback != NULL)
      {
        /* Half transfer callback */
        htsu->ScanClpCallback(htsu);
      }
#endif
	}
	
	if (evt & TSU_EVT_JCPLT)
	{
		HAL_TSU_JudgmentEndCallback(htsu);
		
#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
      if (htsu->JudgmentClpCallback != NULL)
      {
        /* Half transfer callback */
        htsu->JudgmentClpCallback(htsu);
      }
#endif
	}
	
	if (evt & TSU_EVT_CORRCPLT)
	{
		htsu->State = HAL_TSU_STATE_READY;

		HAL_TSU_CorrectEndCallback(htsu);
		
#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
      if (htsu->CorrectClpCallback != NULL)
      {
        /* Half transfer callback */
        htsu->CorrectClpCallback(htsu);
      }
#endif
	}

	if (evt & TSU_EVT_TCORRCPLT)
	{
		htsu->State = HAL_TSU_STATE_READY;

		HAL_TSU_TempCorrectEndCallback(htsu);
		
#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
      if (htsu->CorrectClpCallback != NULL)
      {
        /* Half transfer callback */
        htsu->CorrectClpCallback(htsu);
      }
#endif
	}
	
	/* clear IRQ */
	SYSCFG->CTSM_CTRL |= SYSCFG_CTSM_CTRL_CLRINT; 
	SYSCFG->CTSM_CTRL &= (~SYSCFG_CTSM_CTRL_CLRINT); 
}

/**
  * @brief Tx Transfer completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_TxCpltCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_TxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief Rx Transfer completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_RxCpltCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_RxCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief Error callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_ErrorCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_ErrorCallback can be implemented in the user file.
   */
}

/**
  * @brief Abort Transfer completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_AbortCpltCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_AbortCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief Abort Transmit completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_AbortTransmitCpltCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_AbortTransmitCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief Abort receive completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_AbortReceiveCpltCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_AbortReceiveCpltCallback can be implemented in the user file.
   */
}

/**
  * @brief Measurement completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_MeasurmentEndCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_MeasurmentEndCallback can be implemented in the user file.
   */
}

/**
  * @brief Measurement completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_MeasurmentAllChannelEndCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_MeasurmentEndCallback can be implemented in the user file.
   */
}

/**
  * @brief Scan completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_ScanEndCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_MeasurmentEndCallback can be implemented in the user file.
   */
}

/**
  * @brief Judgment completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_JudgmentEndCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_MeasurmentEndCallback can be implemented in the user file.
   */
}

/**
  * @brief Correction completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_CorrectEndCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_MeasurmentEndCallback can be implemented in the user file.
   */
}

/**
  * @brief Correction completed callback.
  * @param htsu TSU handle.
  */
__weak void HAL_TSU_TempCorrectEndCallback(TSU_HandleTypeDef *htsu)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htsu);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_TSU_MeasurmentEndCallback can be implemented in the user file.
   */
}


/**
  * @}
  */

/** @addtogroup TSU_Exported_Functions_Group4 Peripheral State functions
  *  @brief    Peripheral State functions.
  *
@verbatim
 ===============================================================================
                      ##### Peripheral State functions #####
 ===============================================================================
    [..]
    This subsection permits to get in run-time the status of the peripheral.

@endverbatim
  * @{
  */

/**
  * @brief  Return the TSU handle state.
  * @param  htsu TSU handle
  * @retval HAL state
  */
HAL_TSU_StateTypeDef HAL_TSU_GetState(TSU_HandleTypeDef *htsu)
{
  /* Return TSU handle state */
  return htsu->State;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup TSU_Private_Functions
  * @{
  */
#if 0
/**
  * @brief  Enter 8-bit input data to the TSU calculator.
  *         Specific data handling to optimize processing time.
  * @param  htsu TSU handle
  * @retval uint32_t TSU (returned value LSBs for TSU shorter than 32 bits)
  */
static uint32_t TSU_Calibrate(TSU_HandleTypeDef *htsu)
{
  uint32_t i; /* input data buffer index */


  /* Return the TSU computed value */
  return 0;
}

/**
  * @brief  Enter 16-bit input data to the TSU calculator.
  *         Specific data handling to optimize processing time.
  * @param  htsu TSU handle
  * @retval uint32_t TSU (returned value LSBs for TSU shorter than 32 bits)
  */
static uint32_t TSU_Configure(TSU_HandleTypeDef *htsu)
{
  uint32_t i;  /* input data buffer index */

  /* Processing time optimization: 2 HalfWords are entered in a row with a single word write,
   * in case of odd length, last HalfWord must be carefully fed to the TSU calculator to ensure
   * a correct type handling by the peripheral */
  for (i = 0U; i < (BufferLength); i++)
  {
    *(__IO uint16_t *)(__IO void *)(&htsu->Instance->DATA) = pBuffer[i];
  }
  /* Return the TSU computed value */
  return htsu->Instance->RESULT;
}

/**
  * @brief  Enter 16-bit input data to the TSU calculator.
  *         Specific data handling to optimize processing time.
  * @param  htsu TSU handle
  * @retval uint32_t TSU (returned value LSBs for TSU shorter than 32 bits)
  */
static uint32_t TSU_CorrectProcess(TSU_HandleTypeDef *htsu)
{
    uint32_t i;
    uint32_t j;
    uint16_t error_registance[HAL_TSU_RANGE_NUM];
    uint32_t * p_trimb = (uint32_t *)(0x007fc3a8);
    uint32_t trimb;
    uint8_t  trimb_byte;
    uint8_t  rtrim;
    uint16_t base_value;
    uint16_t base_conv_dac;
    uint32_t ref_include_error;
    int32_t  x0;
    int32_t  x1;
    int32_t  y0;

  tsu_correction_info.status = CTSU_CORRECTION_RUN;
//    CTSU.CTSUCRA.BIT.MD0  = 1;
//    CTSU.CTSUCRA.BIT.MD1  = 0;
//    CTSU.CTSUMCH.BIT.MCA0 = 1;
//    CTSU.CTSUMCH.BIT.MCA1 = 0;
//    CTSU.CTSUMCH.BIT.MCA2 = 0;
//    CTSU.CTSUMCH.BIT.MCA3 = 0;
//    CTSU.CTSUCRA.BIT.LOAD = 1;
  MODIFY_REG(htsu->Instance->CTRL0, TSU_CTRL_MD0|TSU_CTRL_MD1, (1<<TSU_CTRL_MD0_Pos));
  MODIFY_REG(htsu->Instance->CH_CFG, TSU_CHCFG_MCA0|TSU_CHCFG_MCA1|TSU_CHCFG_MCA2|TSU_CHCFG_MCA3, (1<<TSU_CHCFG_MCA0_Pos));
  MODIFY_REG(htsu->Instance->CTRL0, TSU_CTRL_LOAD, TSU_MEAS_LOAD_NO);

  /* Setting time of measurement */
  tsu_correction_info.ctsuwr = (CTSU_SNUM_RECOMMEND << 10);

  /* Step1 : Get resistance value from TRIMB register. */
  trimb = * p_trimb;
  rtrim = READ_BIT(htsu->Instance->TRIM0, TSU_TRIM_RTRIM);
    for (i = 0; i < HAL_TSU_RANGE_NUM; i++)
    {
        trimb_byte          = (trimb >> (i * 8)) & TSU_CORRECTION_TRIMB_MAX;
        error_registance[i] = (uint16_t) (trimb_byte & (uint8_t) (~TSU_CORRECTION_TRIMB_SIGN_BIT));
        if (trimb_byte & TSU_CORRECTION_TRIMB_SIGN_BIT)
        {
            if ((rtrim > TSU_CORRECTION_RTRIM_THRESHOLD1) && (trimb_byte >= TSU_CORRECTION_TRIMB_THRESHOLD1))
            {
                /* Minus2 : bit8(0.50) set 1 */
                error_registance[i] = (error_registance[i] | TSU_CORRECTION_BIT8);
            }
            else
            {
                /* Plus   : bit9(1.00) set 1 */
                error_registance[i] = (error_registance[i] | TSU_CORRECTION_BIT9);
            }
        }
        else
        {
            if ((rtrim < TSU_CORRECTION_RTRIM_THRESHOLD2) && (trimb_byte <= TSU_CORRECTION_TRIMB_THRESHOLD2))
            {
                /* Plus2  : bit7(0.25) and bit9(1.00) set 1 */
                error_registance[i] = (error_registance[i] | TSU_CORRECTION_BIT7 | TSU_CORRECTION_BIT9);
            }
            else
            {
                /* Minus : bit8(0.50) and bit7(0.25) set 1 */
                error_registance[i] = (error_registance[i] | TSU_CORRECTION_BIT7 | TSU_CORRECTION_BIT8);
            }
        }

        /* 6-bit left shift, 512 to 32768 */
        error_registance[i] = (uint16_t) (error_registance[i] << (TSU_SHIFT_AMOUNT - 9));

 #if (CTSU_CFG_DIAG_SUPPORT_ENABLE == 1)
        tsu_diag_info.error_registance[i] = error_registance[i];
 #endif
    }

    /* Step2-a : Measure the current input to the ICO by passing current through the internal resistance */
    /*           in each range. The theoretical value of the current is 12.5uA. */
    //CTSU.CTSUCHACA.LONG        = 1;
    //CTSU.CTSUCHACB.LONG        = 0;
    //CTSU.CTSUCALIB.BIT.TSOC = 1;
    htsu->CH_EN0 = 1;
    htsu->CH_EN1 = 0;
    SET_BIT(htsu->CALIB, TSU_CALIB_TSOC);
    for (i = 0; i < HAL_TSU_RANGE_NUM; i++)
    {
        if (HAL_TSU_RANGE_20UA == i)
        {
            //CTSU.CTSUCRA.BIT.ATUNE1 = 0;
            //CTSU.CTSUCRA.BIT.ATUNE2 = 1;
            MODIFY_REG(htsu->Instance->CTRL0, TSU_CTRL_ATUNE1|TSU_CTRL_ATUNE2, TSU_CURRENT_RANGE_20uA);
        }
        else if (HAL_TSU_RANGE_40UA == i)
        {
            //CTSU.CTSUCRA.BIT.ATUNE1 = 1;
            //CTSU.CTSUCRA.BIT.ATUNE2 = 0;
            MODIFY_REG(htsu->Instance->CTRL0, TSU_CTRL_ATUNE1|TSU_CTRL_ATUNE2, TSU_CURRENT_RANGE_40uA);
        }
        else if (HAL_TSU_RANGE_80UA == i)
        {
            //CTSU.CTSUCRA.BIT.ATUNE1 = 0;
            //CTSU.CTSUCRA.BIT.ATUNE2 = 0;
            MODIFY_REG(htsu->Instance->CTRL0, TSU_CTRL_ATUNE1|TSU_CTRL_ATUNE2, TSU_CURRENT_RANGE_80uA);
        }
        else
        {
            //CTSU.CTSUCRA.BIT.ATUNE1 = 1;
            //CTSU.CTSUCRA.BIT.ATUNE2 = 1;
            MODIFY_REG(htsu->Instance->CTRL0, TSU_CTRL_ATUNE1|TSU_CTRL_ATUNE2, TSU_CURRENT_RANGE_160uA);
        }

        //CTSU.CTSUCRA.BIT.LOAD = 3;
        MODIFY_REG(htsu->Instance->CTRL0, TSU_CTRL_LOAD, TSU_MEAS_LOAD_RES_CALIB);
        TSU_CorrectionMeasurement(htsu, &tsu_correction_info.base_value[i]);
        //CTSU.CTSUCRA.BIT.LOAD = 3;
        MODIFY_REG(htsu->Instance->CTRL0, TSU_CTRL_LOAD, TSU_MEAS_LOAD_RES_CALIB);
    }

    /* Step3 : Measure by inputting each constant current from internal DAC to ICO. */
    //CTSU.CTSUCRB.BIT.SSCNT      = 0;
    //CTSU.CTSUCALIB.BIT.CCOCLK   = 0;
    //CTSU.CTSUCALIB.BIT.CCOCALIB = 1;
    MODIFY_REG(htsu->Instance->CTRL1, TSU_CTRL_SSCNT, 0);
    MODIFY_REG(htsu->Instance->CALIB, TSU_CALIB_CCOCLK|TSU_CALIB_CCOCALIB, (1 << TSU_CALIB_CCOCALIB_Pos));

    /* 1.25uA * (j + 1), SUCARRY is required for greater than 10uA */
    for (j = 0; j < TSU_CORRECTION_POINT_NUM; j++)
    {
        //CTSU.CTSUCRA.BIT.SDPSEL = 0;
        CLEAR_BIT(htsu->Instance->CTRL0, TSU_CTRL_SDPSEL);
        if (8 > j)
        {
            //CTSU.CTSUSUCLKA.BIT.SUADJ0 = (uint32_t) (((j + 1) * TSU_CORRECTION_SUMULTI) - 1);
            MODIFY_REG(htsu->Instance->SUCLK_CTRL0, TSU_SUCLKCTRL_SUADJ0, (((uint32_t) (((j + 1) * TSU_CORRECTION_SUMULTI) - 1)) << TSU_SUCLKCTRL_SUADJ0_Pos));
        }
        else
        {
            //CTSU.CTSUCRB.BIT.SSCNT     = 3;
            //CTSU.CTSUCALIB.BIT.SUCARRY = 1;
            //CTSU.CTSUSUCLKA.BIT.SUADJ0 = (uint32_t) (((j - 3) * TSU_CORRECTION_SUMULTI) - 1);
            MODIFY_REG(htsu->Instance->CTRL1, TSU_CTRL_SSCNT, (3 << TSU_CTRL_SSCNT_Pos));
            SET_BIT(htsu->Instance->CALIB, TSU_CALIB_SUCARRY);
            MODIFY_REG(htsu->Instance->SUCLK_CTRL0, TSU_SUCLKCTRL_SUADJ0, (((uint32_t) (((j - 3) * TSU_CORRECTION_SUMULTI) - 1)) << TSU_SUCLKCTRL_SUADJ0_Pos));
        }

        CTSU.CTSUCRA.BIT.SDPSEL = 1;
        TSU_CorrectionMeasurement(htsu, &tsu_correction_info.dac_value[j]);
    }

    /* Step4 : Calculate the coefficient between step2 and step3. */
    for (i = 0; i < HAL_TSU_RANGE_NUM; i++)
    {
        /* Linear interpolation calculation */
        base_value = tsu_correction_info.base_value[i];
        j          = 1;
        while (1)
        {
            if ((base_value < tsu_correction_info.dac_value[j]) || ((TSU_CORRECTION_POINT_NUM - 1) == j))
            {
                y0 = (uint16_t) (TSU_CORRECTION_STD_UNIT * (j + 1));
                x0 = tsu_correction_info.dac_value[j];
                x1 = tsu_correction_info.dac_value[j - 1];
                break;
            }

            j++;
        }

        base_conv_dac = (uint16_t) (y0 - ((TSU_CORRECTION_STD_UNIT * (x0 - base_value)) / (x0 - x1)));

        /* Error rate calculation */
        ref_include_error = (uint32_t) (TSU_CORRECTION_STD_VAL * (TSU_CORRECTION_BIT16 - error_registance[i]));
        tsu_correction_info.error_rate[i] = (uint16_t) (ref_include_error / base_conv_dac);

        for (j = 0; j < TSU_CORRECTION_POINT_NUM; j++)
        {
            tsu_correction_info.ref_value[i][j] =
                (uint16_t) ((TSU_CORRECTION_STD_UNIT * (j + 1) * tsu_correction_info.error_rate[i]) >>
                            TSU_SHIFT_AMOUNT);
        }
    }

    for (i = 0; i < HAL_TSU_RANGE_NUM - 1; i++)
    {
        tsu_correction_info.range_ratio[i] =
            (uint16_t) (((uint32_t) tsu_correction_info.error_rate[i] << TSU_SHIFT_AMOUNT) /
                        tsu_correction_info.error_rate[HAL_TSU_RANGE_160UA]);
    }

#if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 1)
    for (j = 0; j < TSU_CORRECTION_POINT_NUM; j++)
    {
        /* The correction coefficient is shifted to the right by 12 bits after the decimal point and treated as an integer. */
        corr_original = ((uint32_t)tsu_correction_info.ref_value[p_instance_ctrl->range][j] << TSU_AUTO_DECIMAL_POINT_NUM) / tsu_correction_info.dac_value[j];
        /* Extract an integer of the correction factor */
        corr_integer = (corr_original >> TSU_AUTO_DECIMAL_POINT_NUM) & 0xF;
        /* Extract a decimal of the correction factor */
        corr_decimal = corr_original & 0xFFF;

        corr_dac = tsu_correction_info.dac_value[j];

        /* Table 0 is set to 0x0000 and table 11 is set to 0xFFFF */
        if (0 == j)
        {
            corr_dac = 0x0000;
        }
        else if ((TSU_CORRECTION_POINT_NUM - 1) == j)
        {
            corr_dac = TSU_COUNT_MAX;
        }

        htsu->Instance->ACT = (corr_dac << 16) | (corr_integer << 12) | (corr_decimal);
    }

    /* Sensor counter auto correction enabled */
    //CTSU.CTSUOPT.BIT.CCOCFEN = 1;
    SET_BIT(htsu->Instance->OPT, TSU_OPT_CCOCFEN);
#endif

  return 0;
}

/**
  * @brief  Enter 16-bit input data to the TSU calculator.
  *         Specific data handling to optimize processing time.
  * @param  htsu TSU handle
  * @retval uint32_t TSU (returned value LSBs for TSU shorter than 32 bits)
  */
static uint32_t TSU_CorrectExec(TSU_HandleTypeDef *htsu)
{
    uint16_t element_id;

    ctsu_correction_calc_t calc;

    uint16_t                i;
    uint32_t                ctsuso;
    uint32_t                snum;
    int32_t                 offset_unit;
    ctsu_correction_multi_t multi;
 #if (CTSU_CFG_NUM_SELF_ELEMENTS != 0)
    uint16_t * p_self_data;
    uint16_t   average_self;
 #endif
 #if (CTSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
    uint16_t * p_pri_data;
    uint16_t * p_snd_data;
    uint16_t   average_pri;
    uint16_t   average_snd;
 #endif   
    calc.range = htsu->Init.Range;
    calc.md    = htsu->Init.ScanMode;

    for (element_id = 0; element_id < htsu->ScanCtrl.ScanElementNum; element_id++)
    {
        calc.snum = (htsu->ScanCtrl.pTsuwr[(element_id * CTSU_CFG_NUM_SUMULTI)] >> 10) & CTSU_SNUM_MAX;
        for (i = 0; i < CTSU_CFG_NUM_SUMULTI; i++)
        {
            ctsuso =
                (htsu->ScanCtrl.pTsuwr[(element_id * CTSU_CFG_NUM_SUMULTI) + i] & CTSU_TUNING_MAX);
            snum = (htsu->ScanCtrl.pTsuwr[(element_id * CTSU_CFG_NUM_SUMULTI)] >> 10) &
                   CTSU_SNUM_MAX;
            offset_unit = ((int32_t) (CTSU_CORRECTION_OFFSET_UNIT * (snum + 1))) /
                          ((int32_t) (CTSU_SNUM_RECOMMEND + 1));
            multi.offset[i] = (ctsuso * (uint32_t) (offset_unit >> calc.range));
        }

        if (HAL_TSU_OPMODE_SELF_MUTLI == htsu->Init.ScanMode)
        {
 #if (CTSU_CFG_NUM_SELF_ELEMENTS != 0)
            for (i = 0; i < CTSU_CFG_NUM_SUMULTI; i++)
            {
  #if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 0)
                TSU_CorrectionCalc(&htsu->ScanCtrl.pSelfCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i],
                                     htsu->ScanCtrl.pSelfRaw[(element_id * CTSU_CFG_NUM_SUMULTI) + i],
                                     &calc);
  #else
                htsu->ScanCtrl.pSelfCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i] = htsu->ScanCtrl.pSelfRaw[(element_id * CTSU_CFG_NUM_SUMULTI) + i];
  #endif

                multi.pri[i] = htsu->ScanCtrl.pSelfCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i];

                multi.snd[i] = 0;
            }

            p_self_data = (htsu->ScanCtrl.pSelfData + element_id);

            if (0 == htsu->ScanCtrl.Average)
            {
                /* Store corrected data in p_pri_data[i] for initial offset tuning */
            }
            else
            {
                /* Store last moving averaged data */
                average_self = *p_self_data;

                /* Matching values */
                TSU_CorrectionFleq(&multi, multi.pri, NULL);
                TSU_CorrectionMulti(&multi, p_self_data, NULL);

                *(htsu->ScanCtrl.pSelectedFreqSelf + element_id) = multi.selected_freq;

                /* Update moving averaged data */
                TSU_MovingAverage(&average_self, *p_self_data, htsu->ScanCtrl.Average);
                *p_self_data = average_self;
            }
        }
        else if (HAL_TSU_OPMODE_CURRENT == htsu->Init.ScanMode)
        {
            p_self_data = (htsu->ScanCtrl.pSelfData + (element_id * CTSU_CFG_NUM_SUMULTI));

            /* Store last moving averaged data */
            average_self = *p_self_data;

            /* Correction */
  #if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 0)
            TSU_CorrectionCalc(p_self_data, htsu->ScanCtrl.pSelfRaw[element_id], &calc);
  #else
            *p_self_data = htsu->ScanCtrl.pSelfRaw[element_id];
  #endif

            /* Update moving averaged data */
            if (1 < htsu->ScanCtrl.Average)
            {
                TSU_MovingAverage(&average_self, *p_self_data, htsu->ScanCtrl.Average);
                *p_self_data = average_self;
            }
 #endif
        }
        else if (HAL_TSU_OPMODE_MUTUAL == htsu->Init.ScanMode)
        {
 #if (CTSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
            for (i = 0; i < CTSU_CFG_NUM_SUMULTI; i++)
            {
  #if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 0)
                TSU_CorrectionCalc(&htsu->ScanCtrl.pMutualPriCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i],
                                     htsu->ScanCtrl.pMutualRaw[(element_id * CTSU_MUTUAL_BUF_SIZE) + (i * 2)],
                                     &calc);
  #else
                htsu->ScanCtrl.pMutualPriCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i] = htsu->ScanCtrl.pMutualRaw[(element_id * CTSU_MUTUAL_BUF_SIZE) + (i * 2)];
  #endif

                multi.pri[i] = htsu->ScanCtrl.pMutualPriCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i];

  #if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 0)
                TSU_CorrectionCalc(&htsu->ScanCtrl.pMutualSndCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i],
                                     htsu->ScanCtrl.pMutualRaw[(element_id * CTSU_MUTUAL_BUF_SIZE) + (i * 2) + 1],
                                     &calc);
  #else
                htsu->ScanCtrl.pMutualSndCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i] =htsu->ScanCtrl.pMutualRaw[(element_id * CTSU_MUTUAL_BUF_SIZE) + (i * 2) + 1];
  #endif

                multi.snd[i] = htsu->ScanCtrl.pMutualSndCorr[(element_id * CTSU_CFG_NUM_SUMULTI) + i];
            }

            p_pri_data = (htsu->ScanCtrl.pMutualPriData + element_id);
            p_snd_data = (htsu->ScanCtrl.pMutualSndData + element_id);

            if (0 == htsu->ScanCtrl.Average)
            {
                /* Store corrected data in p_pri_data[i] for initial offset tuning */
            }
            else
            {
                /* Store last moving averaged data */
                average_pri = *p_pri_data;
                average_snd = *p_snd_data;

                /* Matching values */
                TSU_CorrectionFleq(&multi, multi.pri, multi.snd);
                TSU_CorrectionMulti(&multi, p_pri_data, p_snd_data);
                *(htsu->ScanCtrl.pSelectedFreqMutual + element_id) = multi.selected_freq;

                /* Update moving averaged data */
                TSU_MovingAverage(&average_pri, *p_pri_data, htsu->ScanCtrl.Average);
                *p_pri_data = average_pri;
                TSU_MovingAverage(&average_snd, *p_snd_data, htsu->ScanCtrl.Average);
                *p_snd_data = average_snd;
            }
 #endif
        }
        else
        {
        }
    }
  return 0
}

#if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 0)
void TSU_CorrectionCalc (uint16_t * correction_data, uint16_t raw_data, ctsu_correction_calc_t * p_calc)
{
    uint32_t answer;
    int32_t  cmp_data;
    uint8_t  calc_flag = 0;
    int32_t  y0 = 0;
    int32_t  y1 = 0;
    int32_t  x0 = 0;
    int32_t  x1 = 0;
    uint16_t i;

    if (CTSU_CORRECTION_COMPLETE == tsu_correction_info.status)
    {
        calc_flag = 1;
    }

    if (calc_flag)
    {
        /* Since the correction coefficient table is created with the recommended measurement time, */
        /* If the measurement time is different, adjust the value level. */
        if (CTSU_SNUM_RECOMMEND == p_calc->snum)
        {
            cmp_data = raw_data;
        }
        else
        {
            cmp_data = (int32_t) (((int32_t) raw_data * (CTSU_SNUM_RECOMMEND + 1)) / (p_calc->snum + 1));
        }

        /* y = y0 + (y1 - y0) * (x - x0) / (x1 - x0);    [y=coefficient, x=value] */
        if (CTSU_MODE_MUTUAL_CFC_SCAN != p_calc->md)
        {
            i = 0;
            while (1)
            {
                if ((cmp_data < tsu_correction_info.dac_value[i]) || ((CTSU_CORRECTION_POINT_NUM - 1) == i))
                {
                    y0 = tsu_correction_info.ref_value[p_calc->range][i];
                    x0 = tsu_correction_info.dac_value[i];
                    if (0 == i)
                    {
                        x1 = 0;
                        y1 = 0;
                    }
                    else
                    {
                        x1 = tsu_correction_info.dac_value[i - 1];
                        y1 = tsu_correction_info.ref_value[p_calc->range][i - 1];
                    }

                    break;
                }

                i++;
            }
        }

        answer = (uint32_t) (y0 - (((y0 - y1) * (x0 - cmp_data)) / (x0 - x1)));

        if (CTSU_SNUM_RECOMMEND != p_calc->snum)
        {
            answer = (uint32_t) ((answer * (uint32_t) (p_calc->snum + 1)) / (CTSU_SNUM_RECOMMEND + 1));
        }

        /* Value Overflow Check */
        if (CTSU_COUNT_MAX < answer)
        {
            *correction_data = CTSU_COUNT_MAX;
        }
        else
        {
            *correction_data = (uint16_t) answer;
        }
    }
    else
    {
        *correction_data = raw_data;
    }
}
#endif

void TSU_CorrectionFleq (ctsu_correction_multi_t * p_multi, uint16_t * p_pri, uint16_t * p_snd)
{
    uint32_t i;
    int32_t  sumulti[CTSU_CFG_NUM_SUMULTI];
    int32_t  pri_calc[CTSU_CFG_NUM_SUMULTI];
    int32_t  snd_calc[CTSU_CFG_NUM_SUMULTI];
    int32_t  pri_total;
    int32_t  snd_total;

    sumulti[0] = CTSU_CFG_SUMULTI0 + 1;
 #if CTSU_CFG_NUM_SUMULTI >= 2
    sumulti[1] = CTSU_CFG_SUMULTI1 + 1;
 #endif
 #if CTSU_CFG_NUM_SUMULTI >= 3
    sumulti[2] = CTSU_CFG_SUMULTI2 + 1;
 #endif
 #if CTSU_CFG_NUM_SUMULTI >= 4
    sumulti[2] = CTSU_CFG_SUMULTI3 + 1;
 #endif

    for (i = 1; i < CTSU_CFG_NUM_SUMULTI; i++)
    {
        pri_total   = (int32_t) (p_multi->pri[i] + p_multi->offset[i]);
        pri_calc[i] = (int32_t) (((pri_total * sumulti[0]) / sumulti[i]) - (int32_t) p_multi->offset[0]);
        p_pri[i]    = (uint16_t) pri_calc[i];
    }

    if (NULL == p_snd)
    {
        for (i = 0; i < CTSU_CFG_NUM_SUMULTI; i++)
        {
            p_multi->snd[i] = 0;
        }
    }
    else
    {
        for (i = 1; i < CTSU_CFG_NUM_SUMULTI; i++)
        {
            snd_total   = (int32_t) (p_multi->snd[i] + p_multi->offset[i]);
            snd_calc[i] = (int32_t) (((snd_total * sumulti[0]) / sumulti[i]) - (int32_t) p_multi->offset[0]);
            p_snd[i]    = (uint16_t) snd_calc[i];
        }
    }
}

void TSU_CorrectionMulti (ctsu_correction_multi_t * p_multi, uint16_t * p_pri, uint16_t * p_snd)
{
    int32_t add_pri;
    int32_t add_snd;
 #if CTSU_CFG_NUM_SUMULTI >= 3
    uint32_t i;
    int32_t  pri_calc[CTSU_CFG_NUM_SUMULTI];
    int32_t  snd_calc[CTSU_CFG_NUM_SUMULTI];
    int32_t  diff[CTSU_CFG_NUM_SUMULTI];
 #endif

 #if CTSU_CFG_NUM_SUMULTI == 1
    add_pri = p_multi->pri[0];
    add_snd = p_multi->snd[0];
 #endif
 #if CTSU_CFG_NUM_SUMULTI == 2
    add_pri = p_multi->pri[0] + p_multi->pri[1];
    add_snd = p_multi->snd[0] + p_multi->snd[1];
 #endif
 #if CTSU_CFG_NUM_SUMULTI >= 3
    for (i = 0; i < CTSU_CFG_NUM_SUMULTI; i++)
    {
        pri_calc[i] = (int32_t) p_multi->pri[i];
        if (NULL == p_snd)
        {
            snd_calc[i] = 0;
        }
        else
        {
            snd_calc[i] = (int32_t) p_multi->snd[i];
        }
    }

    diff[0] = (snd_calc[1] - pri_calc[1]) - (snd_calc[0] - pri_calc[0]);
    diff[1] = (snd_calc[2] - pri_calc[2]) - (snd_calc[0] - pri_calc[0]);
    diff[2] = (snd_calc[2] - pri_calc[2]) - (snd_calc[1] - pri_calc[1]);

    for (i = 0; i < CTSU_CFG_NUM_SUMULTI; i++)
    {
        if (diff[i] < 0)
        {
            diff[i] = -diff[i];
        }
    }

    /* Normally select freq0 and freq1 addition */
    /* If the following conditions are false, it is estimated to be a noise environment. */
    /* Compare with the combination with the other frequency difference (including margin). */
    if ((diff[0] < (diff[1] * 2)) && (diff[0] < ((diff[2] * 3) / 2)))
    {
        add_pri = pri_calc[0] + pri_calc[1];
        add_snd = snd_calc[0] + snd_calc[1];

        p_multi->selected_freq = 0x3;
    }
    else
    {
        if (diff[1] < diff[2])
        {
            add_pri = pri_calc[0] + pri_calc[2];
            add_snd = snd_calc[0] + snd_calc[2];

            p_multi->selected_freq = 0x5;
        }
        else
        {
            add_pri = pri_calc[1] + pri_calc[2];
            add_snd = snd_calc[1] + snd_calc[2];

            p_multi->selected_freq = 0x6;
        }
    }
 #endif

    if (CTSU_COUNT_MAX < add_pri)
    {
        *p_pri = CTSU_COUNT_MAX;
    }
    else
    {
        *p_pri = (uint16_t) add_pri;
    }

    if (NULL != p_snd)
    {
        if (CTSU_COUNT_MAX < add_snd)
        {
            *p_snd = CTSU_COUNT_MAX;
        }
        else
        {
            *p_snd = (uint16_t) add_snd;
        }
    }
}

void TSU_CorrectionMeasurement (TSU_HandleTypeDef * htsu, uint16_t * data)
{
    uint16_t i;
    uint32_t sum = 0;

    for (i = 0; i < CTSU_CORRECTION_AVERAGE; i++)
    {
#if (CTSU_CFG_DTC_SUPPORT_ENABLE == 1)
 #if (CTSU_CFG_AUTO_JUDGE_ENABLE == 0)
        ctsu_transfer_configure(htsu);
 #else
        ctsu_transfer_auto_configure(htsu);
 #endif
#else
//        FSP_PARAMETER_NOT_USED(htsu);
#endif
        htsu->State = CTSU_STATE_SCANNING;
        //CTSU.CTSUCRA.LONG       |= 0x01;
        htsu->Instance->CTRL0 |= 0x01;
        while (htsu->State != CTSU_STATE_SCANNED)
        {
        }

        sum += tsu_correction_info.scanbuf;
    }

    *data = (uint16_t) (sum / CTSU_CORRECTION_AVERAGE);
}

 #if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 1)
/***********************************************************************************************************************
 * ctsu_auto_correction_register_set
 ***********************************************************************************************************************/
void ctsu_auto_correction_register_set (TSU_HandleTypeDef *htsu)
{
    uint32_t j;
    uint32_t corr_original;
    uint8_t  corr_integer;
    uint16_t corr_decimal;
    uint16_t corr_dac;

    /* Enter the correction factor and dac_value in CTSUSCNTACT for 12 correction tables */
    for (j = 0; j < CTSU_CORRECTION_POINT_NUM; j++)
    {
        /* The correction coefficient is shifted to the right by 12 bits after the decimal point and treated as an integer. */
        corr_original = ((uint32_t)tsu_correction_info.ref_value[p_instance_ctrl->range][j] << CTSU_AUTO_DECIMAL_POINT_NUM) / tsu_correction_info.dac_value[j];
        /* Extract an integer of the correction factor */
        corr_integer = (corr_original >> CTSU_AUTO_DECIMAL_POINT_NUM) & 0xF;
        /* Extract a decimal of the correction factor */
        corr_decimal = corr_original & 0xFFF;

        corr_dac = tsu_correction_info.dac_value[j];

        /* Table 0 is set to 0x0000 and table 11 is set to 0xFFFF */
        if (0 == j)
        {
            corr_dac = 0x0000;
        }
        else if ((CTSU_CORRECTION_POINT_NUM - 1) == j)
        {
            corr_dac = CTSU_COUNT_MAX;
        }

        CTSU.CTSUSCNTACT.LONG = (corr_dac << 16) | (corr_integer << 12) | (corr_decimal);
    }
}
 #endif

 #if (CTSU_CFG_AUTO_JUDGE_ENABLE == 1)
/***********************************************************************************************************************
 * ctsu_auto_jugde_threshold_calc
 ***********************************************************************************************************************/
void ctsu_auto_jugde_threshold_calc (TSU_HandleTypeDef *htsu)
{
    uint16_t multi_threshold;
    uint16_t multi_hysteresis;
    int32_t  sumulti[CTSU_CFG_NUM_SUMULTI];
    uint8_t  element_id;
    uint8_t  i;
  #if (CTSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
    int16_t  ajthr_h;
    int16_t  ajthr_l;
  #endif

    sumulti[0] = CTSU_CFG_SUMULTI0 + 1;
  #if CTSU_CFG_NUM_SUMULTI >= 2
    sumulti[1] = CTSU_CFG_SUMULTI1 + 1;
  #endif
  #if CTSU_CFG_NUM_SUMULTI >= 3
    sumulti[2] = CTSU_CFG_SUMULTI2 + 1;
  #endif
  #if CTSU_CFG_NUM_SUMULTI >= 4
    sumulti[3] = CTSU_CFG_SUMULTI3 + 1;
  #endif

    for (element_id = 0; element_id < htsu->ScanCtrl.ScanElementNum; element_id++)
    {
        for (i = 0; i < CTSU_CFG_NUM_SUMULTI; i++)
        {
            /* Calculate multi clock threshold and hysteresis value and input to the automatic judgement register */
            multi_threshold  = (htsu->Init.pAutoButtons[element_id].threshold * sumulti[i]) / sumulti[0] / 2;
            multi_hysteresis = (htsu->Init.pAutoButtons[element_id].hysteresis * sumulti[i]) / sumulti[0] / 2;
  #if (CTSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
            if(CTSU_MODE_SELF_MULTI_SCAN == htsu->Init.ScanMode)
            {
  #endif
                htsu->ScanCtrl.pAutoJudge[(element_id * CTSU_CFG_NUM_SUMULTI) + i].ajthr = (multi_threshold << 16) | (multi_threshold - multi_hysteresis);
  #if (CTSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
            }
            else
            {
                ajthr_h = -(multi_threshold) + multi_hysteresis;
                ajthr_l = -(multi_threshold);
                htsu->ScanCtrl.pAutoJudge[(element_id * CTSU_CFG_NUM_SUMULTI) + i].ajthr = (ajthr_h << 16) | (ajthr_l & 0x0000FFFF);
            }
  #endif
        }
    }
}
 #endif

 #if (CTSU_CFG_TEMP_CORRECTION_SUPPORT == 1)

/***********************************************************************************************************************
 * ctsu_correction_scan_start
 ***********************************************************************************************************************/
void ctsu_correction_scan_start (void)
{
    CTSU.CTSUCRA.BIT.MD0  = 1;
    CTSU.CTSUCRA.BIT.MD1  = 0;
    CTSU.CTSUMCH.BIT.MCA0 = 1;
    CTSU.CTSUMCH.BIT.MCA1 = 0;
    CTSU.CTSUMCH.BIT.MCA2 = 0;
    CTSU.CTSUMCH.BIT.MCA3 = 0;

    /* Setting time of measurement */
    tsu_correction_info.ctsuwr = (CTSU_SNUM_RECOMMEND << 10);
    tsu_correction_info.suadj0        = (uint8_t) (CTSU.CTSUSUCLKA.BIT.SUADJ0 & CTSU_SUADJ_MAX);

    if (tsu_correction_info.scan_index < CTSU_CORRECTION_POINT_NUM)
    {
        /* Dummy setting */
        CTSU.CTSUCHACA.LONG = 1;
        CTSU.CTSUCHACB.LONG = 0;

        /* Step3 : Measure by inputting each constant current from internal DAC to ICO. */
        CTSU.CTSUCRB.BIT.SSCNT      = 0;
        CTSU.CTSUCALIB.BIT.CCOCLK   = 0;
        CTSU.CTSUCALIB.BIT.CCOCALIB = 1;
        CTSU.CTSUCALIB.BIT.TSOC     = 1;

        CTSU.CTSUCRA.BIT.SDPSEL = 0;
        if (8 > tsu_correction_info.scan_index)
        {
            CTSU.CTSUSUCLKA.BIT.SUADJ0 = (uint16_t) (((tsu_correction_info.scan_index + 1) * CTSU_CORRECTION_SUMULTI) - 1);
        }
        else
        {
            /* SUCARRY is required for greater than 10uA */
            CTSU.CTSUCRB.BIT.SSCNT     = 3;
            CTSU.CTSUCALIB.BIT.SUCARRY = 1;
            CTSU.CTSUSUCLKA.BIT.SUADJ0          =
                (uint16_t) (((tsu_correction_info.scan_index - 3) * CTSU_CORRECTION_SUMULTI) - 1);
        }

        CTSU.CTSUCRA.BIT.SDPSEL = 1;
    }
    else
    {
        /* Step2-b : Measure the current input to the ICO by passing current through the external resistance. */
        /*           The theoretical value of the current is 9.375uA. */
        CTSU.CTSUCRA.BIT.ATUNE1 = 1;
        CTSU.CTSUCRA.BIT.ATUNE2 = 1;
  #if (CTSU_CFG_TEMP_CORRECTION_TS < 32)
        CTSU.CTSUCHACA.LONG = (uint32_t) (1 << CTSU_CFG_TEMP_CORRECTION_TS);
        CTSU.CTSUCHACB.LONG = 0;
  #else
        CTSU.CTSUCHACA.LONG = 0;
        CTSU.CTSUCHACB.LONG = (uint32_t) (1 << (CTSU_CFG_TEMP_CORRECTION_TS - 32));
  #endif
        CTSU.CTSUCRA.BIT.DCMODE = 1;
        CTSU.CTSUCRA.BIT.DCBACK = 1;
        CTSU.CTSUSO.BIT.SO      = 0;
    }
}

/***********************************************************************************************************************
 * ctsu_correction_data_get
 ***********************************************************************************************************************/
void ctsu_correction_data_get (TSU_HandleTypeDef * htsu, uint16_t * p_data)
{
    uint32_t i;
    uint32_t j;
    uint16_t base_value;
    uint16_t base_conv_dac;
    int32_t  x0;
    int32_t  x1;
    int32_t  y0;

    if (tsu_correction_info.scan_index < CTSU_CORRECTION_POINT_NUM)
    {
        TSU_MovingAverage(&tsu_correction_info.dac_value[tsu_correction_info.scan_index],
                            *htsu->ScanCtrl.pSelfRaw,
                            4);
        tsu_correction_info.scan_index++;
    }
    else
    {
        if (0 == tsu_correction_info.ex_base_value)
        {
            tsu_correction_info.ex_base_value  = *htsu->ScanCtrl.pSelfRaw;
            tsu_correction_info.update_counter = CTSU_CFG_TEMP_CORRECTION_TIME;
        }
        else
        {
            TSU_MovingAverage(&tsu_correction_info.ex_base_value, *htsu->ScanCtrl.pSelfRaw, 4);
        }

        tsu_correction_info.scan_index = 0;
        tsu_correction_info.update_counter++;
    }

    /* Step4 : Calculate the coefficient between step2 and step3. */
    if (tsu_correction_info.update_counter > CTSU_CFG_TEMP_CORRECTION_TIME)
    {
        /* Linear interpolation calculation */
        base_value = tsu_correction_info.ex_base_value;
        j          = 1;
        while (1)
        {
            if ((base_value < tsu_correction_info.dac_value[j]) || ((CTSU_CORRECTION_POINT_NUM - 1) == j))
            {
                y0 = (uint16_t) (CTSU_CORRECTION_STD_UNIT * (j + 1));
                x0 = tsu_correction_info.dac_value[j];
                x1 = tsu_correction_info.dac_value[j - 1];
                break;
            }

            j++;
        }

        base_conv_dac = (uint16_t) (y0 - ((CTSU_CORRECTION_STD_UNIT * (x0 - base_value)) / (x0 - x1)));

        /* Error rate calculation */
        tsu_correction_info.error_rate[CTSU_RANGE_160UA] =
            (uint16_t) ((CTSU_CORRECTION_STD_EXREG << CTSU_SHIFT_AMOUNT) / base_conv_dac);

        for (j = 0; j < CTSU_CORRECTION_POINT_NUM; j++)
        {
            tsu_correction_info.ref_value[CTSU_RANGE_160UA][j] =
                (uint16_t) ((CTSU_CORRECTION_STD_UNIT * (j + 1) *
                             tsu_correction_info.error_rate[CTSU_RANGE_160UA]) >> CTSU_SHIFT_AMOUNT);
            for (i = 0; i < CTSU_RANGE_NUM - 1; i++)
            {
                tsu_correction_info.ref_value[i][j] =
                    (uint16_t) ((tsu_correction_info.ref_value[CTSU_RANGE_160UA][j] *
                                 tsu_correction_info.range_ratio[i]) >> CTSU_SHIFT_AMOUNT);
            }
        }

  #if (CTSU_CFG_AUTO_CORRECTION_ENABLE == 1)
        /* Initialization of sensor counter auto correction table register number */
        CTSU.CTSUOPT.BIT.SCACTB = 0;

        ctsu_auto_correction_register_set (p_instance_ctrl);
  #endif

        tsu_correction_info.update_counter = 0;
  #if (CTSU_CFG_CALIB_RTRIM_SUPPORT == 1)
        ctsu_correction_calib_rtrim(p_instance_ctrl, p_data);
  #endif
    }
    else
    {
        /* Indicates that ADC measurement was not performed. */
        *p_data = CTSU_COUNT_MAX;
    }
}

  #if (CTSU_CFG_CALIB_RTRIM_SUPPORT == 1)

/***********************************************************************************************************************
 * ctsu_correction_calib_rtrim
 ***********************************************************************************************************************/
void ctsu_correction_calib_rtrim (TSU_HandleTypeDef * htsu, uint16_t * p_data)
{
    uint16_t               i;
    uint16_t               adctdr_result;
    uint16_t               adctdr_ave;
    uint32_t               adctdr_sum;
    int16_t                diff;
    int16_t                dir  = 0;
    uint16_t               comp = 0;
    adc_cfg_t     open_cfg;
    adc_ch_cfg_t  ctrl_cfg;
    adc_err_t     poll;

    /* TSCAP AD/C AN008 Setting */
    CTSU.CTSUADCC.LONG = 1;

    /* Setting for A/D convert mode */
    open_cfg.conv_speed = ADC_CONVERT_SPEED_DEFAULT;
    open_cfg.alignment = ADC_ALIGN_RIGHT;
    open_cfg.add_cnt = ADC_ADD_OFF;                 /* addition is turned off for chans/sensors */
    open_cfg.clearing = ADC_CLEAR_AFTER_READ_OFF;
    open_cfg.trigger = ADC_TRIG_SOFTWARE;           /* Software trigger */
    open_cfg.trigger_groupb = ADC_TRIG_NONE;        /* Trigger none when without group mode */
    open_cfg.priority = 0;                          /* S12ADIO no interrupt(polling) */
    open_cfg.priority_groupb = 0;                   /* S12GBADI no interrupt */
    R_ADC_Open (0, ADC_MODE_SS_ONE_CH, &open_cfg, FIT_NO_FUNC);

    /* choice A/D port(allow A/D convert) */
    ctrl_cfg.chan_mask = ADC_MASK_CH8;
    ctrl_cfg.chan_mask_groupb = ADC_MASK_GROUPB_OFF;
    ctrl_cfg.priority_groupa = ADC_GRPA_PRIORITY_OFF;
    ctrl_cfg.diag_method = ADC_DIAG_OFF;
    ctrl_cfg.add_mask = ADC_MASK_ADD_OFF;
    ctrl_cfg.signal_elc = ADC_ELC_ALL_SCANS_DONE;
    R_ADC_Control (0, ADC_CMD_ENABLE_CHANS, &ctrl_cfg);

    /* Self single scan mode */
    CTSU.CTSUCRA.BIT.LOAD = 1;
    CTSU.CTSUCRA.BIT.MD0  = 0;
    CTSU.CTSUCRA.BIT.MD1  = 0;

    /* Set Channel */
   #if (CTSU_CFG_TEMP_CORRECTION_TS < 32)
    CTSU.CTSUCHACA.LONG  |= (uint32_t) (1 << CTSU_CFG_TEMP_CORRECTION_TS);
    CTSU.CTSUCHTRCA.LONG &= (uint32_t) ~(1 << CTSU_CFG_TEMP_CORRECTION_TS);
   #else
    CTSU.CTSUCHACB.LONG  |= (uint32_t) (1 << (CTSU_CFG_TEMP_CORRECTION_TS - 32));
    CTSU.CTSUCHTRCB.LONG &= (uint32_t) ~(1 << (CTSU_CFG_TEMP_CORRECTION_TS - 32));
   #endif
    CTSU.CTSUMCH.BIT.MCH0 = CTSU_CFG_TEMP_CORRECTION_TS;

    /* 150uA current measurement */
    CTSU.CTSUCRA.BIT.DCMODE = 1;
    CTSU.CTSUCRA.BIT.DCBACK = 1;
    CTSU.CTSUSO.BIT.SO      = CTSU_CALIB_CTSUSO;
    CTSU.CTSUCRA.BIT.CSW    = 0;
    CTSU.CTSUCALIB.BIT.DRV  = 1;

    /* ADC scan */
    while (!comp)
    {
        adctdr_sum = 0;
        for (i = 0; i < CTSU_CALIB_AVERAGE_TIME; i++)
        {
            /* Software trigger start scan */
            R_ADC_Control (0, ADC_CMD_SCAN_NOW, FIT_NO_PTR);

            /* Polling for scan complete */
            do
            {
                poll = R_ADC_Control (0, ADC_CMD_CHECK_SCAN_DONE, FIT_NO_PTR);
            } while (ADC_ERR_SCAN_NOT_DONE == poll);

            /* Read A/D data then scan normal end */
            R_ADC_Read (0, ADC_REG_CH8, &adctdr_result);
            adctdr_sum += adctdr_result;
        }

        adctdr_ave = (uint16_t) ((adctdr_sum * 10) / CTSU_CALIB_AVERAGE_TIME);
        diff       = (int16_t) ((adctdr_ave - CTSU_CALIB_REF) / 10);

        /* The change unit of the voltage by the RTRIM register is about 4mV (4096 * 4) = 16.384 */
        if (diff > CTSU_CALIB_THRESHOLD)
        {
            if (0 <= dir)
            {
                CTSU.CTSUTRIMA.BIT.RTRIM = (uint8_t) (CTSU.CTSUTRIMA.BIT.RTRIM + 1);
                dir = 1;
            }
            else
            {
                comp = 1;
            }
        }
        else if (diff < -(CTSU_CALIB_THRESHOLD))
        {
            if (0 >= dir)
            {
                CTSU.CTSUTRIMA.BIT.RTRIM = (uint8_t) (CTSU.CTSUTRIMA.BIT.RTRIM - 1);
                dir = -1;
            }
            else
            {
                comp = 1;
            }
        }
        else
        {
            comp = 1;
        }
    }

    /* Restore register settings */
    CTSU.CTSUCALIB.BIT.DRV  = 0;
    CTSU.CTSUCRA.BIT.CSW    = 1;
    CTSU.CTSUCRA.BIT.DCMODE = 0;
    CTSU.CTSUCRA.BIT.DCBACK = 0;

    /* Indicates that ADC measurement was performed  */
    *p_data = CTSU.CTSUTRIMA.BIT.RTRIM;

    /* Close ADC for CTSU TSCAP */
    R_ADC_Close(0);
}

  #endif
 #endif

/**
  * @brief  Enter 16-bit input data to the TSU calculator.
  *         Specific data handling to optimize processing time.
  * @param  htsu TSU handle
  * @retval uint32_t TSU (returned value LSBs for TSU shorter than 32 bits)
  */
static uint32_t TSU_InitOffsetTuning(TSU_HandleTypeDef *htsu)
{
  uint16_t element_id;
  int32_t  diff          = 0;
  uint32_t complete_flag = 0;
  uint32_t num_complete  = 0;
  uint16_t target_val;
  uint16_t i;
  uint16_t element_top;
  uint16_t corr_data[CTSU_CFG_NUM_SUMULTI];
  int32_t  ctsuso;
  uint32_t snum;
  int32_t  offset_unit;

  /* element_id through each element for control block */
  for (element_id = 0; element_id < htsu->ScanCtrl.ScanElementNum; element_id++)
  {
    if (CTSU_TUNING_OT_COUNT != *(htsu->ScanCtrl.pTuningCount + element_id))
    {
      element_top = (uint16_t) (element_id * TSU_CFG_NUM_SUMULTI);
      for (i = 0; i < CTSU_CFG_NUM_SUMULTI; i++)
      {
        if (HAL_TSU_OPMODE_SELF_MUTLI == htsu->Init.ScanMode)
        {
            target_val = (htsu->Init.TuningSelfTargetValue / 2);
        }
        else
        {
            target_val = (htsu->Init.TuningMutualTargetValue / 2);
        }
        if (HAL_TSU_OPMODE_SELF_MUTLI == htsu->Init.ScanMode)
        {
            corr_data[i] = htsu->ScanCtrl.pSelfCorr[element_top + i];
        }
        else
        {
            corr_data[i] = htsu->ScanCtrl.pMutualPriCorr[element_top + i];
        }

        snum = (htsu->ScanCtrl.pTsuwr[element_id * CTSU_CFG_NUM_SUMULTI] >> TSU_SO_SNUM_Pos) &
               TSU_SNUM_MAX;
        target_val  = (uint16_t) (((uint32_t) target_val * (snum + 1)) / (TSU_SNUM_RECOMMEND + 1));
        offset_unit = (int32_t) ((TSU_CORRECTION_OFFSET_UNIT * (snum + 1)) / (TSU_SNUM_RECOMMEND + 1));

        /* Calculate CTSUSO equivalent difference between current value and target value */
        diff = (int32_t) ((int32_t) corr_data[i] - (int32_t) target_val) /
               (offset_unit >> htsu->Init.Range);

        ctsuso  = (int32_t) (htsu->ScanCtrl.pTsuwr[element_top + i] & TSU_TUNING_MAX);
        ctsuso += diff;

        /* If the CTSUSO exceeds the minimum value or the maximum value, tuning complete */
        if (ctsuso < 0)
        {
          ctsuso = 0;
          complete_flag++;
        }
        else if (ctsuso > TSU_TUNING_MAX)
        {
          ctsuso = TSU_TUNING_MAX;
          complete_flag++;
        }
        else
        {
          /* If the difference is large, tuning value may not be able to match, so create the next opportunity */
          if (0 == diff)
          {
            complete_flag++;
          }
          else
          {
            (*(htsu->ScanCtrl.pTuningCount+element_id))++;
          }
        }

        /* Set the result of the calculated CTSUSO */
        htsu->ScanCtrl.pTsuwr[element_top + i] &= (uint32_t) (~TSU_TUNING_MAX);
        htsu->ScanCtrl.pTsuwr[element_top + i] |= (uint32_t) ctsuso;
      }
    }
    else
    {
        complete_flag = TSU_CFG_NUM_SUMULTI;
    }

    if (TSU_CFG_NUM_SUMULTI == complete_flag)
    {
        complete_flag = 0;
        num_complete++;
       *(htsu->ScanCtrl.pTuningCount + element_id) = TSU_TUNING_OT_COUNT;
    }
  }

  if (num_complete == htsu->Init.ChannelNumber)
  {
    htsu->TuningState = HAL_TSU_TUNING_COMPLETE;
  }

  return 0;
}

void TSU_MovingAverage (uint16_t * p_average, uint16_t new_data, uint16_t average_num)
{
    uint32_t work;

    work       = (uint32_t) ((uint32_t) *p_average * (uint32_t) (average_num - 1)); /* Average * (num - 1) */
    work      += new_data;                                                          /* Add Now data        */
    *p_average = (uint16_t) (work / average_num);                                   /* Average calculation */
}

/**
  * @brief  ISR of measurement end.
  * @param  htsu TSU handle
  */
static void TSU_EndISR(TSU_HandleTypeDef *htsu)
{
 #if (CTSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
    if (HAL_TSU_OPMODE_MUTUAL == htsu->OperateMode)
    {
        if (true == p_instance_ctrl->serial_tuning_enable)
        {
            if (0 == ((p_instance_ctrl->ctsucr1 >> 7) & 0x01))
            {
                rd_index = p_instance_ctrl->rd_index;
            }
            else
            {
                rd_index = p_instance_ctrl->rd_index / 2;
            }
        }
        else
        {
            /* In the mutual capacity of CTSU2, the value of rd_index is twice the value of wr_index. */
            rd_index = p_instance_ctrl->rd_index / 2;
        }
    }
#endif

    /* Countermeasure for the problem that RD interrupt and FN interrupt are reversed. */
    if (rd_index != p_instance_ctrl->wr_index)
    {
        p_instance_ctrl->interrupt_reverse_flag = 1;

        return;
    }

    TSU_ProcessOverflow(htsu);

#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
    if (htsu->MeasurmentClpCallback == NULL)
    {
      htsu->MeasurmentClpCallback = HAL_TSU_MeasurmentEndCallback;
    }

    /* Init the low level hardware */
    htsu->MeasurmentClpCallback(htsu);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_TSU_MeasurmentEndCallback(htsu);
#endif /* (USE_HAL_TSU_REGISTER_CALLBACKS) */

  tsu_wridx = 0;
  tsu_rdidx = 0;
  htsu->State = HAL_TSU_STATE_SCANNED;
  
  return;
}

/**
  * @brief  Enter 16-bit input data to the TSU calculator.
  *         Specific data handling to optimize processing time.
  * @param  htsu TSU handle
  */
static void TSU_RDISR(TSU_HandleTypeDef *htsu)
{
#if (TSU_DMA_ENABLE == 0)  
    if (HAL_TSU_CORRECTION_RUN == htsu->CorrectionState)
    {
        g_ctsu_correction_info.scanbuf = CTSU.CTSUSCNT.BIT.SC;
    }
    else
    {
  #if (CTSU_CFG_NUM_SELF_ELEMENTS != 0)
        if (HAL_TSU_OPMODE_SELF_MUTLI == (HAL_TSU_OPMODE_MUTUAL & htsu->OperateMode))
        {
            p_instance_ctrl->p_self_raw[p_instance_ctrl->rd_index] = CTSU.CTSUSCNT.BIT.SC;
            p_instance_ctrl->rd_index++;

            /* Interim */
            if (0 == p_instance_ctrl->rd_index % 3)
            {
                CTSU.CTSUSR.BIT.MFC = 0;
            }
        }
  #endif
  #if (CTSU_CFG_NUM_MUTUAL_ELEMENTS != 0)
        if (HAL_TSU_OPMODE_MUTUAL == htsu->OperateMode)
        {
            p_instance_ctrl->p_mutual_raw[p_instance_ctrl->rd_index] = CTSU.CTSUSCNT.BIT.SC;
            p_instance_ctrl->rd_index++;
        }
  #endif
    }
#endif /* TSU_DMA_ENABLE */   
  if (1 == p_instance_ctrl->interrupt_reverse_flag)
  {
      p_instance_ctrl->interrupt_reverse_flag = 0;

      TSU_ProcessOverflow(htsu);
  
#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
      if (htsu->ReadResultReqCallback == NULL)
      {
        htsu->ReadResultReqCallback = HAL_TSU_ReadResultCallback;
      }
  
      /* Init the low level hardware */
      htsu->ReadResultReqCallback(htsu);
#else
      /* Init the low level hardware : GPIO, CLOCK */
      HAL_TSU_ReadResultCallback(htsu);
#endif /* (USE_HAL_TSU_REGISTER_CALLBACKS) */
 
    tsu_wridx = 0;
    tsu_rdidx = 0;
    htsu->State = HAL_TSU_STATE_SCANNED;
  }
}

/**
  * @brief  Enter 16-bit input data to the TSU calculator.
  *         Specific data handling to optimize processing time.
  * @param  htsu TSU handle
  */
static void TSU_WRISR(TSU_HandleTypeDef *htsu)
{
#if (TSU_DMA_ENABLE == 0)
    ctsu_instance_ctrl_t * p_instance_ctrl = gp_ctsu_isr_context;

    /* Write settings for current element */
    if (CTSU_CORRECTION_RUN == htsu->CorrectionState)
    {
        CTSU.CTSUSO.LONG = g_ctsu_correction_info.ctsuwr.ctsuso;
    }
    else if (CTSU_MODE_DIAGNOSIS_SCAN == htsu->OperateMode)
    {
#if (CTSU_CFG_DIAG_SUPPORT_ENABLE == 1)
        CTSU.CTSUSO.LONG = g_ctsu_diag_info.ctsuwr.ctsuso;
        p_instance_ctrl->wr_index++;
#endif
    }
    else
    {
      htsu->Instance->SO = tsu_channel_so[tsu_wridx];
      tsu_wridx++;
    }
#endif /* TSU_DMA_ENABLE */

#if (USE_HAL_TSU_REGISTER_CALLBACKS == 1)
    if (htsu->ConfigureReqCallback == NULL)
    {
      htsu->ConfigureReqCallback = HAL_TSU_ConfigureRequestCallback;
    }

    /* Init the low level hardware */
    htsu->ConfigureReqCallback(htsu);
#else
    /* Init the low level hardware : GPIO, CLOCK */
    HAL_TSU_ConfigureRequestCallback(htsu);
#endif /* (USE_HAL_TSU_REGISTER_CALLBACKS) */

}

/**
  * @brief  Process overflow anf clear flags.
  * @param  htsu TSU handle
  */
static void TSU_ProcessOverflow(TSU_HandleTypeDef *htsu)
{
  if (READ_BIT(htsu->Instance->STAUS, TSU_STAUS_SCOVF))
  {
      htsu->ErrorCode  |= HAL_TSU_ERROR_OVERFLOW;
      CLEAR_BIT(htsu->Instance->STAUS, TSU_STAUS_SCOVF)
  }
  if ((READ_BIT(htsu->Instance->STAUS, TSU_STAUS_ICOMP0)) || (READ_BIT(htsu->Instance->STAUS, TSU_STAUS_ICOMP1)))
  {
      if (READ_BIT(htsu->Instance->STAUS, TSU_STAUS_ICOMP0))
      {
          htsu->ErrorCode |= HAL_TSU_ERROR_ICOMP;
      }
      if (READ_BIT(htsu->Instance->STAUS, TSU_STAUS_ICOMP1))
      {
          htsu->ErrorCode |= HAL_TSU_ERROR_ICOMP1;
      }
      SET_BIT(htsu->Instance->STAUS, TSU_STAUS_ICOMPRST);
  }

#if (TSU_CFG_TEMP_CORRECTION_SUPPORT)
  if(htsu->OperateMode == HAL_TSU_OPMODE_CORRECTION)
  {
    if(htsu->CorrectionState != HAL_TSU_CORRECTION_RUN)
    {
            CTSU.CTSUCRA.BIT.SDPSEL      = 0;
            CTSU.CTSUSUCLKA.BIT.SUADJ0   = g_ctsu_correction_info.suadj0;
            CTSU.CTSUSUCLKA.BIT.SUMULTI0 = CTSU_CFG_SUMULTI0;
            CTSU.CTSUCRB.BIT.SSCNT       = 1;
            CTSU.CTSUCALIB.BIT.SUCARRY   = 0;
            CTSU.CTSUCALIB.BIT.CCOCALIB  = 0;
            CTSU.CTSUCALIB.BIT.CCOCLK    = 1;
            CTSU.CTSUCALIB.BIT.TSOC      = 0;
            CTSU.CTSUCRA.BIT.SDPSEL      = 1;
    }
  }
#endif /* TSU_CFG_TEMP_CORRECTION_SUPPORT */  
}


#endif //0
/**
  * @}
  */

#endif /* HAL_TSU_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
