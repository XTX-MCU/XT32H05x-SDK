/**
  ******************************************************************************
  * @file    xt32h0xx_hal_adc.c
  * @author  Software Team
  * @brief   This file provides firmware functions to manage the following
  *          functionalities of the Analog to Digital Converter (ADC),
  *          the Digital to Analog Converter (DAC), PGA and Comparator
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

/** @defgroup ADC ADC
  * @brief ADC HAL module driver
  * @{
  */

#ifdef HAL_MDU_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup ADC_Private_Constants ADC Private Constants
  * @{
  */
#define    ADC_CALI_MEAS_MODE_LOW         (0)
#define    ADC_CALI_MEAS_MODE_HIGH        (1)

#define    ADC_CALI_MEAS_NUMBER           (8)
#define    ADC_CALI_MEAS_CLOCK            (8000000)

#if defined(XT32H0xxB)
#define    ADC_INJECTION_CHANNEL_NUMBER   (4)      /*!< injection channel number */
#define    ADC_REGULAR_CHANNEL_NUMBER     (32)     /*!< regular channel number */

#define    ADC_INJECTION_GROUP_NUMBER     (4)      /*!< injection group number */
#define    ADC_REGULAR_GROUP_NUMBER       (8)      /*!< regular group number */

#define    ADC_AWD_NUMBER                 (3)      /*!< analog watch dog number */
#endif /* XT32H0xxB */
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @addtogroup ADC_Private_Variables 
  * @{
  * 
  */
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup ADC_Private_Functions 
  * @{
  * 
  */
#if defined(XT32H0xxB)
static void ADC_InjectionDMAConvCplt(DMA_HandleTypeDef *hdma);
static void ADC_RegularDMAConvCplt(DMA_HandleTypeDef *hdma);
static void ADC_InjectionDMABlockConvCplt(DMA_HandleTypeDef *hdma);
static void ADC_RegularDMABlockConvCplt(DMA_HandleTypeDef *hdma);


HAL_StatusTypeDef HAL_ADC_InitProcess(ADC_HandleTypeDef *hadc);

//static uint32_t ADC_CalibrateMeasure(uint32_t Mode);
#else
static void ADC_DMAConvCplt(DMA_HandleTypeDef *hdma);
#endif /* XT32H0xxB */
static void ADC_DMAError(DMA_HandleTypeDef *hdma);

static void ADC_Delay(uint32_t delay);
/**
  * @}
  */

/* Exported functions ---------------------------------------------------------*/

/** @defgroup ADC_Exported_Functions ADC Exported Functions
  * @{
  */

/** @defgroup ADC_Exported_Functions_Group1 Initialization and de-initialization functions
  * @brief    ADC Initialization and Configuration functions
  *
  * @{
  */

/**
  * @brief  Initialize the ADC peripheral and regular group according to
  *         parameters specified in structure "ADC_InitTypeDef".
  * @note   As prerequisite, ADC clock must be configured at RCC top level
  *         (refer to description of RCC configuration for ADC
  *         in header of this file).
  * @note   Possibility to update parameters on the fly:
  *         This function initializes the ADC MSP (HAL_ADC_MspInit()) only when
  *         coming from ADC state reset. Following calls to this function can
  *         be used to reconfigure some parameters of ADC_InitTypeDef
  *         structure on the fly, without modifying MSP configuration. If ADC
  *         MSP has to be modified again, HAL_ADC_DeInit() must be called
  *         before HAL_ADC_Init().
  *         The setting of these parameters is conditioned to ADC state.
  *         For parameters constraints, see comments of structure
  *         "ADC_InitTypeDef".
  * @note   This function configures the ADC within 2 scopes: scope of entire
  *         ADC and scope of regular group. For parameters details, see comments
  *         of structure "ADC_InitTypeDef".
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef *hadc)
{
 /* Check ADC handle */
  if (hadc == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
	if(hadc->Init.CalibrationEnable)
	{
		return HAL_ADC_Calibration(hadc);
	}
	else
	{
		return HAL_ADC_InitProcess(hadc);
	}
}

/**
  * @brief  Deinitialize the ADC peripheral registers to their default reset
  *         values, with deinitialization of the ADC MSP.
  * @note   For devices with several ADCs: reset of ADC common registers is done
  *         only if all ADCs sharing the same common group are disabled.
  *         (function "HAL_ADC_MspDeInit()" is also called under the same conditions:
  *         all ADC instances use the same core clock at RCC level, disabling
  *         the core clock reset all ADC instances).
  *         If this is not the case, reset of these common parameters reset is
  *         bypassed without error reporting: it can be the intended behavior in
  *         case of reset of a single ADC while the other ADCs sharing the same
  *         common group is still running.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check ADC handle */
  if (hadc == NULL)
  {
    return HAL_ERROR;
  }

//  /* Check the parameters */
//  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
#if defined(XT32H0xxB)
	CLEAR_BIT(hadc->Instance->ADC_CALIB, MDU_ADCCALIB_CODE_COR_EN);
	
  /* disable */
  CLEAR_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_EN);
 
	/* disable ADCC */
	CLEAR_BIT(hadc->Instance->ADC_CFG, MDU_ADCCFG_ADCC_EN);
	
	/* stop & reset */
  CLEAR_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_START_EN|MDU_MDUCFG_ADC_RST);

  /* mask and disable interrupt */
  CLEAR_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_INJ_EOC_EN|MDU_MDUCFG_INJ_EOS_EN|MDU_MDUCFG_REG_EOC_EN|MDU_MDUCFG_REG_EOS_EN);

  hadc->Instance->INT_STATUS_1 = 0;
  hadc->Instance->INT_STATUS_2 = 0;
  hadc->Instance->INT_STATUS_3 = 0;
  hadc->Instance->INT_STATUS_4 = 0;

	SET_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_ADC_MASK);
	CLEAR_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_ADC_MASK);
	CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQCFG_ADC_MASK);

  /* power down */
  SET_BIT(hadc->Instance->PDCTRL, MDU_PDCTRL_ADCPD);
#else
  /* reset */
  CLEAR_BIT(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_RST);

  /* stop */
  CLEAR_BIT(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_SEQ_STRT);

  /* mask and disable interrupt */
	SET_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_ADC_EOS_MASK);
	CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_ADC_EOS_MASK);

  /* power down */
  SET_BIT(hadc->Instance->PDCTRL, MDU_PDCTRL_ADCPD);
#endif /* XT32H0xxB */

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  if (hadc->MspDeInitCallback == NULL)
  {
    hadc->MspDeInitCallback = HAL_ADC_MspDeInit; /* Legacy weak MspDeInit  */
  }

  /* DeInit the low level hardware */
  hadc->MspDeInitCallback(hadc);
#else
  /* DeInit the low level hardware */
  HAL_ADC_MspDeInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

  /* Set ADC error code to none */
  ADC_CLEAR_ERRORCODE(hadc);

  /* Set ADC state */
  hadc->State = HAL_ADC_STATE_RESET;

  __HAL_UNLOCK(hadc);

  return tmp_hal_status;
}

/**
  * @brief  Initialize the ADC MSP.
  * @param hadc ADC handle
  */
__weak void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_MspInit must be implemented in the user file.
   */
}

/**
  * @brief  DeInitialize the ADC MSP.
  * @param hadc ADC handle
  * @note   All ADC instances use the same core clock at RCC level, disabling
  *         the core clock reset all ADC instances).
  */
__weak void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_MspDeInit must be implemented in the user file.
   */
}

/**
  * @brief link dma with adc.
  * @param hadc ADC handle.
  * @param hdmarx DMA handle.
  * @param hdmarx2 DMA handle.
  * @param rxif DMA rx if.
  * @param rx2if DMA rx 2 if.
  * @param rxifcfg DMA tx if cfg.
  * @param rx2ifcfg DMA rx 2 if cfg.
  * @retval Status
  */
HAL_StatusTypeDef HAL_ADC_DMAHSIFConfig(ADC_HandleTypeDef *hadc, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmarx2, uint32_t rxif, uint32_t rx2if, uint32_t rxifcfg, uint32_t rx2ifcfg)
{
	uint32_t mask = 0;
	if(hadc == NULL) return HAL_ERROR;
	
	if(hdmarx != NULL)
	{
		mask = 3UL << (rxif<<1);
		SYSCFG->DMA_CFG &= ~(mask);   
		SYSCFG->DMA_CFG |= ((rxifcfg & 0x3) << (rxif<<1));
#if defined(XT32H0xxB)    
		SYSCFG->DMA_CFG_2 &= ~(mask);   
		SYSCFG->DMA_CFG_2 |= (((rxifcfg &0xC) >> 2) << (rxif<<1));
#endif /* XT32H0xxB */

    hdmarx->Instance->CFG_L &= ~(DMA_CH_CHCFG_SRCHSPOL|DMA_CH_CHCFG_SRCHS);  //SRC_HS_POL = 0; HS_SEL_SRC = 0
	  hdmarx->Instance->CFG_H &= ~(DMA_CH_CHCFG_SRCPER);
    hdmarx->Instance->CFG_H |= (rxif << DMA_CH_CHCFG_SRCPER_Pos); 
	}
	
	if(hdmarx2 != NULL)
	{
		mask = 3UL << (rx2if<<1);
		SYSCFG->DMA_CFG &= ~(mask);  
		SYSCFG->DMA_CFG |= ((rx2ifcfg & 0x3) << (rx2if<<1));
#if defined(XT32H0xxB)       
		SYSCFG->DMA_CFG_2 &= ~(mask);  
		SYSCFG->DMA_CFG_2 |= (((rx2ifcfg & 0xC) >>2) << (rx2if<<1));
#endif /* XT32H0xxB */

	  hdmarx2->Instance->CFG_L &= ~(DMA_CH_CHCFG_SRCHSPOL|DMA_CH_CHCFG_SRCHS);  //DST_HS_POL = 0; HS_SEL_DST = 0
	  hdmarx2->Instance->CFG_H &= ~(DMA_CH_CHCFG_SRCPER);
    hdmarx2->Instance->CFG_H |= (rx2if << DMA_CH_CHCFG_SRCPER_Pos); 
	}

	return HAL_OK;
}


/**
  * @brief link dma with ADC.
  * @param hadc ADC handle.
  * @param hdmarx DMA handle for regular group.
  * @param hdmarx2 DMA handle for injection group.
  * @retval Status
  */
HAL_StatusTypeDef HAL_ADC_LinkDMA(ADC_HandleTypeDef *hadc, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmarx2)
{
	if(hadc == NULL) return HAL_ERROR;
	
	if(hdmarx != NULL)
	{
    hadc->hdmarx = hdmarx;
		hdmarx->Parent = hadc;
	}
	
	if(hdmarx2 != NULL)
	{
    hadc->hdmarx2 = hdmarx2;
		hdmarx2->Parent = hadc;
	}

	return HAL_OK;
}

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User ADC Callback
  *         To be used instead of the weak predefined callback
  * @param  hadc Pointer to a ADC_HandleTypeDef structure that contains
  *                the configuration information for the specified ADC.
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref   HAL_ADC_CONVERSION_COMPLETE_CB_ID 
  *          @arg @ref   HAL_ADC_ERROR_CB_ID               
  *          @arg @ref   HAL_ADC_SEQUENCE_COMPLETE_CB_ID   
  *          @arg @ref   HAL_ADC_MSPINIT_CB_ID             
  *          @arg @ref   HAL_ADC_MSPDEINIT_CB_ID           
  *          @arg @ref   HAL_ADC_INJ_EOC_CB_ID             
  *          @arg @ref   HAL_ADC_INJ_AWD_CB_ID             
  *          @arg @ref   HAL_ADC_INJ_OW_CB_ID              
  *          @arg @ref   HAL_ADC_INJ_EOS_CB_ID             
  *          @arg @ref   HAL_ADC_REG_EOC_CB_ID             
  *          @arg @ref   HAL_ADC_REG_AWD_CB_ID             
  *          @arg @ref   HAL_ADC_REG_OW_CB_ID              
  *          @arg @ref   HAL_ADC_REG_EOS_CB_ID             
  *          @arg @ref   HAL_ADC_INJ_DMACPLT_CB_ID         
  *          @arg @ref   HAL_ADC_REG_DMACPLT_CB_ID  
  *          @arg @ref   HAL_ADC_INJ_DMABLKCPLT_CB_ID	
  *          @arg @ref   HAL_ADC_REG_DMABLKCPLT_CB_ID	
  *          @arg @ref   HAL_ADC_ALL_CB_ID                 
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID,
                                           pADC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;

  if (pCallback == NULL)
  {
    /* Update the error code */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }

  if ((hadc->State & HAL_ADC_STATE_READY) != 0UL)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        hadc->ConvCpltCallback = pCallback;
        break;

      case HAL_ADC_ERROR_CB_ID :
        hadc->ErrorCallback = pCallback;
        break;

      case HAL_ADC_SEQUENCE_COMPLETE_CB_ID :
        hadc->SequenceCpltCallback = pCallback;
        break;

#if defnied(XT32H0xxB)
      case HAL_ADC_INJ_EOC_CB_ID :
        hadc->InjectionEOCCallback = pCallback;
        break;

      case HAL_ADC_INJ_AWD_CB_ID :
        hadc->InjectionAwdCallback = pCallback;
        break;

      case HAL_ADC_INJ_OW_CB_ID :
        hadc->InjectionOverWriteCallback = pCallback;
        break;

      case HAL_ADC_INJ_EOS_CB_ID :
        hadc->InjectionEOSCallback = pCallback;
        break;

      case HAL_ADC_REG_EOC_CB_ID :
        hadc->RegularEOCCallback = pCallback;
        break;

      case HAL_ADC_REG_AWD_CB_ID :
        hadc->RegularAwdCallback = pCallback;
        break;

      case HAL_ADC_REG_OW_CB_ID :
        hadc->RegularOverWriteCallback = pCallback;
        break;

      case HAL_ADC_REG_EOS_CB_ID :
        hadc->RegularEOSCallback = pCallback;
        break;

      case HAL_ADC_INJ_DMACPLT_CB_ID :
        hadc->InjectionDMACpltCallback = pCallback;
        break;

      case HAL_ADC_REG_DMACPLT_CB_ID :
        hadc->RegularDMACpltCallback = pCallback;
        break;

      case HAL_ADC_INJ_DMABLKCPLT_CB_ID :
        hadc->InjectionDMABlockCpltCallback = pCallback;
        break;

      case HAL_ADC_REG_DMABLKCPLT_CB_ID :
        hadc->RegularDMABlockCpltCallback = pCallback;
        break;
#endif /* XT32H0xxB */


      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = pCallback;
        break;

      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status = HAL_ERROR;
        break;
    }
  }
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = pCallback;
        break;

      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = pCallback;
        break;

      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status = HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

/**
  * @brief  Unregister a ADC Callback
  *         ADC callback is redirected to the weak predefined callback
  * @param  hadc Pointer to a ADC_HandleTypeDef structure that contains
  *                the configuration information for the specified ADC.
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref   HAL_ADC_CONVERSION_COMPLETE_CB_ID 
  *          @arg @ref   HAL_ADC_ERROR_CB_ID               
  *          @arg @ref   HAL_ADC_SEQUENCE_COMPLETE_CB_ID   
  *          @arg @ref   HAL_ADC_MSPINIT_CB_ID             
  *          @arg @ref   HAL_ADC_MSPDEINIT_CB_ID           
  *          @arg @ref   HAL_ADC_INJ_EOC_CB_ID             
  *          @arg @ref   HAL_ADC_INJ_AWD_CB_ID             
  *          @arg @ref   HAL_ADC_INJ_OW_CB_ID              
  *          @arg @ref   HAL_ADC_INJ_EOS_CB_ID             
  *          @arg @ref   HAL_ADC_REG_EOC_CB_ID             
  *          @arg @ref   HAL_ADC_REG_AWD_CB_ID             
  *          @arg @ref   HAL_ADC_REG_OW_CB_ID              
  *          @arg @ref   HAL_ADC_REG_EOS_CB_ID             
  *          @arg @ref   HAL_ADC_INJ_DMACPLT_CB_ID         
  *          @arg @ref   HAL_ADC_REG_DMACPLT_CB_ID         
  *          @arg @ref   HAL_ADC_INJ_DMABLKCPLT_CB_ID	
  *          @arg @ref   HAL_ADC_REG_DMABLKCPLT_CB_ID	
  *          @arg @ref   HAL_ADC_ALL_CB_ID                 
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  if ((hadc->State & HAL_ADC_STATE_READY) != 0)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        hadc->ConvCpltCallback = HAL_ADC_EOCCallback;
        break;

      case HAL_ADC_ERROR_CB_ID :
        hadc->ErrorCallback = HAL_ADC_ErrorCallback;
        break;

      case HAL_ADC_SEQUENCE_COMPLETE_CB_ID :
        hadc->SequenceCpltCallback = HAL_ADC_EOSCallback;
        break;

#if defnied(XT32H0xxB)
      case HAL_ADC_INJ_EOC_CB_ID :
        hadc->InjectionEOCCallback = HAL_ADC_InjectionEOCCallback;
        break;

      case HAL_ADC_INJ_AWD_CB_ID :
        hadc->InjectionAwdCallback = HAL_ADC_InjectionAWDCallback;
        break;

      case HAL_ADC_INJ_OW_CB_ID :
        hadc->InjectionOverWriteCallback = HAL_ADC_InjectionOverWriteCallback;
        break;

      case HAL_ADC_INJ_EOS_CB_ID :
        hadc->InjectionEOSCallback = HAL_ADC_InjectionEOSCallback;
        break;

      case HAL_ADC_REG_EOC_CB_ID :
        hadc->RegularEOCCallback = HAL_ADC_RegularEOCCallback;
        break;

      case HAL_ADC_REG_AWD_CB_ID :
        hadc->RegularAwdCallback = HAL_ADC_RegularAWDCallback;
        break;

      case HAL_ADC_REG_OW_CB_ID :
        hadc->RegularOverWriteCallback = HAL_ADC_RegularOverWriteCallback;
        break;

      case HAL_ADC_REG_EOS_CB_ID :
        hadc->RegularEOSCallback = HAL_ADC_RegularEOSCallback;
        break;

      case HAL_ADC_INJ_DMACPLT_CB_ID :
        hadc->InjectionDMACpltCallback = HAL_ADC_InjectionDMACompletedCallback;
        break;

      case HAL_ADC_REG_DMACPLT_CB_ID :
        hadc->RegularDMACpltCallback = HAL_ADC_RegularDMACompletedCallback;
        break;

      case HAL_ADC_INJ_DMABLKCPLT_CB_ID :
        hadc->InjectionDMABlockCpltCallback = HAL_ADC_InjectionDMABlockCompletedCallback;
        break;

      case HAL_ADC_REG_DMABLKCPLT_CB_ID :
        hadc->RegularDMABlockCpltCallback = HAL_ADC_RegularDMABlockCompletedCallback;
        break;
#endif /* XT32H0xxB */

      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = HAL_ADC_MspInit; 
        break;

      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit; 
        break;

      case HAL_ADC_ALL_CB_ID :
        hadc->ConvCpltCallback = HAL_ADC_EOCCallback;
        hadc->ErrorCallback = HAL_ADC_ErrorCallback;
        hadc->SequenceCpltCallback = HAL_ADC_EOSCallback;
        hadc->MspInitCallback = HAL_ADC_MspInit;
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;
#if defnied(XT32H0xxB)
        hadc->InjectionEOCCallback = HAL_ADC_InjectionEOCCallback;
        hadc->InjectionAwdCallback = HAL_ADC_InjectionAWDCallback;
        hadc->InjectionOverWriteCallback = HAL_ADC_InjectionOverWriteCallback;
        hadc->InjectionEOSCallback = HAL_ADC_InjectionEOSCallback;
        hadc->RegularEOCCallback = HAL_ADC_RegularEOCCallback;
        hadc->RegularAwdCallback = HAL_ADC_RegularAWDCallback;
        hadc->RegularOverWriteCallback = HAL_ADC_RegularOverWriteCallback;
        hadc->RegularEOSCallback = HAL_ADC_RegularEOSCallback;
				hadc->InjectionDMACpltCallback = HAL_ADC_InjectionDMACompletedCallback;
				hadc->RegularDMACpltCallback = HAL_ADC_RegularDMACompletedCallback;
				hadc->InjectionDMABlockCpltCallback = HAL_ADC_InjectionDMABlockCompletedCallback;
				hadc->RegularDMABlockCpltCallback = HAL_ADC_RegularDMABlockCompletedCallback;
#endif /* XT32H0xxB */
        break;  

      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = HAL_ADC_MspInit;                   /* Legacy weak MspInit              */
        break;

      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;               /* Legacy weak MspDeInit            */
        break;
      
      case HAL_ADC_ALL_CB_ID :
        hadc->MspInitCallback = HAL_ADC_MspInit;
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;
        break;

      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    /* Return error status */
    status =  HAL_ERROR;
  }

  return status;
}

#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group2 ADC Input and Output operation functions
  *  @brief    ADC IO operation functions
  *
@verbatim
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Start conversion of regular group.
      (+) Stop conversion of regular group.
      (+) Poll for conversion complete on regular group.
      (+) Poll for conversion event.
      (+) Get result of regular channel conversion.
      (+) Start conversion of regular group and enable interruptions.
      (+) Stop conversion of regular group and disable interruptions.
      (+) Handle ADC interrupt request
      (+) Start conversion of regular group and enable DMA transfer.
      (+) Stop conversion of regular group and disable ADC DMA transfer.
@endverbatim
  * @{
  */

/**
  * @brief  Enable ADC, start conversion of regular group.
  * @note   Interruptions enabled in this function: None.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  HAL_ADC_Enable(hadc);
	
	if((hadc->Instance->MDU_CFG & MDU_MDUCFG_REG_GRP_EN) 
		&& ((hadc->Instance->REGGRP_TRGCFG & MDU_REGGRP_TRGCFG_REGGRP_OPMODE) == ADC_CONVERT_CONTINUOUSSCAN))
	{
		hadc->Instance->REGGRP_TRGCFG |= MDU_REGGRP_TRGCFG_REGGRP_CS_START;
	}

  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion of regular group (and injected channels in
  *         case of auto_injection mode), disable ADC peripheral.
  * @note:  ADC peripheral disable is forcing stop of potential
  *         conversion on injected group. If injected group is under use, it
  *         should be preliminarily stopped using HAL_ADCEx_InjectedStop function.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
	
  __HAL_LOCK(hadc);

	if((hadc->Instance->MDU_CFG & MDU_MDUCFG_REG_GRP_EN) 
		&& ((hadc->Instance->REGGRP_TRGCFG & MDU_REGGRP_TRGCFG_REGGRP_OPMODE) == ADC_CONVERT_CONTINUOUSSCAN))
	{
		hadc->Instance->REGGRP_TRGCFG &= ~(MDU_REGGRP_TRGCFG_REGGRP_CS_START);
	}
	
  HAL_ADC_Disable(hadc);

  __HAL_UNLOCK(hadc);

  return tmp_hal_status;
}

#if defined(XT32H0xxB)
/**
  * @brief  Start continuous onversion of regular group.
  * @note   Interruptions enabled in this function: None.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_RegularGroupContinuousStart(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  hadc->Instance->REGGRP_TRGCFG |= MDU_REGGRP_TRGCFG_REGGRP_CS_START;

  return tmp_hal_status;
}

/**
  * @brief  Stop continuous onversion of regular group.
  * @note   Interruptions enabled in this function: None.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_RegularGroupContinuousStop(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  hadc->Instance->REGGRP_TRGCFG &= ~(MDU_REGGRP_TRGCFG_REGGRP_CS_START);

  return tmp_hal_status;
}
#endif /* XT32H0xxB */

#if defined(XT32H0xxB)
/**
  * @brief  Wait for injection group channel conversion to be completed.
  * @param hadc ADC handle
  * @param Flag flag of end of conversion in injection group
  *        This parameter can be one of the following values:
  *        @arg @ref ADC_FLAG_INJCH_EOC_1
  *        @arg @ref ADC_FLAG_INJCH_EOC_2
  *        @arg @ref ADC_FLAG_INJCH_EOC_3
  *        @arg @ref ADC_FLAG_INJCH_EOC_4
  * @param Timeout Timeout value in millisecond.
  * @retval HAL status
  */
HAL_StatusTypeDef       HAL_ADC_PollForInjectionEOC(ADC_HandleTypeDef *hadc, uint32_t Flag, uint32_t Timeout)
{
  uint32_t tickstart;
  uint32_t tmp_status;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Get tick count */
  tickstart = HAL_GetTick();
  
  tmp_status = (hadc->Instance->INT_STATUS_1 & Flag);

  /* Wait until End of unitary conversion or sequence conversions flag is raised */
  while (tmp_status == 0UL)
  {
    /* Check if timeout is disabled (set to infinite wait) */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0UL))
      {
        /* Update ADC state machine to timeout */
        SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

        __HAL_UNLOCK(hadc);

        return HAL_TIMEOUT;
      }
    }

    tmp_status = (hadc->Instance->INT_STATUS_1 & Flag);
  }

  return HAL_OK;
}

/**
  * @brief  Wait for injection group sequence conversion to be completed.
  * @param hadc ADC handle
  * @param Timeout Timeout value in millisecond.
  * @retval HAL status
  */
HAL_StatusTypeDef       HAL_ADC_PollForInjectionEOS(ADC_HandleTypeDef *hadc, uint32_t Timeout)
{
  uint32_t tickstart;
  uint32_t tmp_status;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Get tick count */
  tickstart = HAL_GetTick();
  
  tmp_status = (hadc->Instance->INT_STATUS_1 & ADC_FLAG_INJGRP_EOS);

  /* Wait until End of unitary conversion or sequence conversions flag is raised */
  while (tmp_status == 0UL)
  {
    /* Check if timeout is disabled (set to infinite wait) */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0UL))
      {
        /* Update ADC state machine to timeout */
        SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

        __HAL_UNLOCK(hadc);

        return HAL_TIMEOUT;
      }
    }

    tmp_status = (hadc->Instance->INT_STATUS_1 & ADC_FLAG_INJGRP_EOS);
  }

  return HAL_OK;
}

/**
  * @brief  Wait for regular group channel conversion to be completed.
  * @param hadc ADC handle
  * @param Flag flag of end of conversion in regular group
  *        This parameter can be one of the following values:
  *        @arg @ref ADC_FLAG_REGCH_EOC_1
  *        @arg @ref ADC_FLAG_REGCH_EOC_2
  *        @arg @ref ADC_FLAG_REGCH_EOC_3
  *        @arg @ref ADC_FLAG_REGCH_EOC_4
  *        @arg @ref ADC_FLAG_REGCH_EOC_5
  *        @arg @ref ADC_FLAG_REGCH_EOC_6
  *        @arg @ref ADC_FLAG_REGCH_EOC_7
  *        @arg @ref ADC_FLAG_REGCH_EOC_8
  *        @arg @ref ADC_FLAG_REGCH_EOC_9
  *        @arg @ref ADC_FLAG_REGCH_EOC_10
  *        @arg @ref ADC_FLAG_REGCH_EOC_11
  *        @arg @ref ADC_FLAG_REGCH_EOC_12
  *        @arg @ref ADC_FLAG_REGCH_EOC_13
  *        @arg @ref ADC_FLAG_REGCH_EOC_14
  *        @arg @ref ADC_FLAG_REGCH_EOC_15
  *        @arg @ref ADC_FLAG_REGCH_EOC_16
  *        @arg @ref ADC_FLAG_REGCH_EOC_17
  *        @arg @ref ADC_FLAG_REGCH_EOC_18
  *        @arg @ref ADC_FLAG_REGCH_EOC_19
  *        @arg @ref ADC_FLAG_REGCH_EOC_20
  *        @arg @ref ADC_FLAG_REGCH_EOC_21
  *        @arg @ref ADC_FLAG_REGCH_EOC_22
  *        @arg @ref ADC_FLAG_REGCH_EOC_23
  *        @arg @ref ADC_FLAG_REGCH_EOC_24
  *        @arg @ref ADC_FLAG_REGCH_EOC_25
  *        @arg @ref ADC_FLAG_REGCH_EOC_26
  *        @arg @ref ADC_FLAG_REGCH_EOC_27
  *        @arg @ref ADC_FLAG_REGCH_EOC_28
  *        @arg @ref ADC_FLAG_REGCH_EOC_29
  *        @arg @ref ADC_FLAG_REGCH_EOC_30
  *        @arg @ref ADC_FLAG_REGCH_EOC_31
  *        @arg @ref ADC_FLAG_REGCH_EOC_32
  * @param Timeout Timeout value in millisecond.
  * @retval HAL status
  */
HAL_StatusTypeDef       HAL_ADC_PollForRegularEOC(ADC_HandleTypeDef *hadc, uint32_t Flag, uint32_t Timeout)
{
  uint32_t tickstart;
  uint32_t tmp_status = 0;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Get tick count */
  tickstart = HAL_GetTick();
  
  if(Flag & 0xFFFF)
    tmp_status |= (hadc->Instance->INT_STATUS_2 & (Flag&0xFFFF));
  if(Flag & 0xFFFF0000)
    tmp_status |= ((hadc->Instance->INT_STATUS_3 & ((Flag&0xFFFF0000) >>16)) << 16);

  /* Wait until End of unitary conversion or sequence conversions flag is raised */
  while (tmp_status == 0UL)
  {
    /* Check if timeout is disabled (set to infinite wait) */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0UL))
      {
        /* Update ADC state machine to timeout */
        SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

        __HAL_UNLOCK(hadc);

        return HAL_TIMEOUT;
      }
    }

    tmp_status = 0;
    if(Flag & 0xFFFF)
      tmp_status |= (hadc->Instance->INT_STATUS_2 & (Flag&0xFFFF));
    if(Flag & 0xFFFF0000)
      tmp_status |= ((hadc->Instance->INT_STATUS_3 & ((Flag&0xFFFF0000) >>16)) << 16);
  }

  return HAL_OK;
}

/**
  * @brief  Wait for regular group sequence conversion to be completed.
  * @param hadc ADC handle
  * @param Timeout Timeout value in millisecond.
  * @retval HAL status
  */
HAL_StatusTypeDef       HAL_ADC_PollForRegularEOS(ADC_HandleTypeDef *hadc, uint32_t Timeout)
{
  uint32_t tickstart;
  uint32_t tmp_status;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Get tick count */
  tickstart = HAL_GetTick();
  
  tmp_status = (hadc->Instance->INT_STATUS_1 & ADC_FLAG_REGGRP_EOS);

  /* Wait until End of unitary conversion or sequence conversions flag is raised */
  while (tmp_status == 0UL)
  {
    /* Check if timeout is disabled (set to infinite wait) */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0UL))
      {
        /* Update ADC state machine to timeout */
        SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

        __HAL_UNLOCK(hadc);

        return HAL_TIMEOUT;
      }
    }

    tmp_status = (hadc->Instance->INT_STATUS_1 & ADC_FLAG_REGGRP_EOS);
  }

  return HAL_OK;
}
#else
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef *hadc, uint32_t Timeout)
{
  uint32_t tickstart;
  uint32_t tmp_flag_end;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  /* If end of conversion selected to end of sequence conversions */
  if (hadc->Init.Mode == ADC_CONVERT_MULTCH_SINGLE)
  {
    tmp_flag_end = MDU_ADCST_EOS;
  }
  else
  {
    tmp_flag_end = MDU_ADCST_EOC;
  }

  /* Get tick count */
  tickstart = HAL_GetTick();

  /* Wait until End of unitary conversion or sequence conversions flag is raised */
  while ((hadc->Instance->ADC_STATUS & tmp_flag_end) == 0UL)
  {
    /* Check if timeout is disabled (set to infinite wait) */
    if (Timeout != HAL_MAX_DELAY)
    {
      if (((HAL_GetTick() - tickstart) > Timeout) || (Timeout == 0UL))
      {
        /* New check to avoid false timeout detection in case of preemption */
        if ((hadc->Instance->ADC_STATUS & tmp_flag_end) == 0UL)
        {
          /* Update ADC state machine to timeout */
          SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

          __HAL_UNLOCK(hadc);

          return HAL_TIMEOUT;
        }
      }
    }
  }
  /* Return function status */
  return HAL_OK;
}

HAL_StatusTypeDef HAL_ADC_ClearConversionFlag(ADC_HandleTypeDef *hadc)
{
  /* Update ADC state machine */
  SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);

  /* Clear end of conversion flag of regular group        */
  if (hadc->Init.Mode == ADC_CONVERT_MULTCH_SINGLE)
  {
    /* Clear regular group conversion flag */
    __HAL_ADC_RESET(hadc);
  }
	
	return HAL_OK;
}
#endif /* XT32H0xxB */


/**
  * @brief start ADC and enable interrupts.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
	
	__HAL_LOCK(hadc);
#if defined(XT32H0xxB)
  HAL_ADC_Enable(hadc);

	if((hadc->Instance->MDU_CFG & MDU_MDUCFG_REG_GRP_EN) 
		&& ((hadc->Instance->REGGRP_TRGCFG & MDU_REGGRP_TRGCFG_REGGRP_OPMODE) == ADC_CONVERT_CONTINUOUSSCAN))
	{
		hadc->Instance->REGGRP_TRGCFG |= MDU_REGGRP_TRGCFG_REGGRP_CS_START;
	}
	
  /* Configure ICTL and enable ICTL */  
  CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_ADC_MASK);
  SET_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_ADC_MASK);
  
  /* config sim */
  CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQCFG_ADC_MASK);
  
#else	
	HAL_ADC_Enable(hadc);
	
	if(hadc->Init.Mode == ADC_CONVERT_MULTCH_SINGLE)
	{
  	/* Configure ICTL and enable ICTL */  
  	CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_ADC_EOS_MASK);
  	SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_ADC_EOS_MASK);
  	
  	/* config sim */
  	CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_ADC_EOS_MASK);
  	
	}
	else
	{
//    HAL_NVIC_SetPriority(ADC_EOC_IRQn, 2, 0);
//    HAL_NVIC_EnableIRQ(ADC_EOC_IRQn);
	}
#endif /* XT32H0xxB */
  __HAL_UNLOCK(hadc);
	
  return tmp_hal_status;
}

/**
  * @brief stop ADC and enable interrupts.
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  __HAL_LOCK(hadc);

#if defined(XT32H0xxB)
	if((hadc->Instance->MDU_CFG & MDU_MDUCFG_REG_GRP_EN) 
		&& ((hadc->Instance->REGGRP_TRGCFG & MDU_REGGRP_TRGCFG_REGGRP_OPMODE) == ADC_CONVERT_CONTINUOUSSCAN))
	{
		hadc->Instance->REGGRP_TRGCFG &= ~(MDU_REGGRP_TRGCFG_REGGRP_CS_START);
	}

  HAL_ADC_Disable(hadc);

  SET_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_ADC_MASK);
  CLEAR_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_ADC_MASK);
#else
	if(hadc->Init.Mode == ADC_CONVERT_MULTCH_SINGLE)
	{
  	SET_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_ADC_EOS_MASK);
  	CLEAR_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_ADC_EOS_MASK);
	}
	else
	{
//		HAL_NVIC_DisableIRQ(ADC_EOC_IRQn);
	}
	
	HAL_ADC_Disable(hadc);
#endif /* XT32H0xxB */
  __HAL_UNLOCK(hadc);

  return tmp_hal_status;
}

#if defined(XT32H0xxB)
/**
  * @brief  Enable ADC, start conversion of injection group and transfer result through DMA.
  * @note   Interruptions enabled in this function:
  *         overrun (if applicable), DMA half transfer, DMA transfer complete.
  *         Each of these interruptions has its dedicated callback function.
  * @param hadc ADC handle
  * @param pData Destination Buffer address.
  * @param Length Number of data to be transferred from ADC peripheral to memory
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Start_InjectionDMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
	
	__HAL_LOCK(hadc);
	
	HAL_ADC_Enable(hadc);

  /* Set the DMA transfer complete callback */
  hadc->hdmarx2->XferCpltCallback = ADC_InjectionDMAConvCplt;

  /* Set the DMA block complete callback */
  hadc->hdmarx2->XferBlockCallback = ADC_InjectionDMABlockConvCplt;

  /* Set the DMA error callback */
  hadc->hdmarx2->XferErrorCallback = ADC_DMAError;

  /* Start the DMA channel */
  tmp_hal_status = HAL_DMA_Start_IT(hadc->hdmarx2, (uint32_t)(&(hadc->Instance->INJ_RESULTS_1)), (uint32_t)pData, Length);

  __HAL_UNLOCK(hadc);
  
	return tmp_hal_status;
}

/**
  * @brief  Disable ADC, stop conversion of injection group and transfer result through DMA.
  * @note   Interruptions enabled in this function:
  *         overrun (if applicable), DMA half transfer, DMA transfer complete.
  *         Each of these interruptions has its dedicated callback function.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Stop_InjectionDMA(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  __HAL_LOCK(hadc);
	
	HAL_DMA_Abort(hadc->hdmarx2);
	
	HAL_ADC_Disable(hadc);

  __HAL_UNLOCK(hadc);

  return tmp_hal_status;
}

/**
  * @brief  Enable ADC, start conversion of regular group and transfer result through DMA.
  * @note   Interruptions enabled in this function:
  *         overrun (if applicable), DMA half transfer, DMA transfer complete.
  *         Each of these interruptions has its dedicated callback function.
  * @param hadc ADC handle
  * @param pData Destination Buffer address.
  * @param Length Number of data to be transferred from ADC peripheral to memory
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Start_RegularDMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
	
	__HAL_LOCK(hadc);
	
	HAL_ADC_Enable(hadc);

	if((hadc->Instance->MDU_CFG & MDU_MDUCFG_REG_GRP_EN) 
		&& ((hadc->Instance->REGGRP_TRGCFG & MDU_REGGRP_TRGCFG_REGGRP_OPMODE) == ADC_CONVERT_CONTINUOUSSCAN))
	{
		hadc->Instance->REGGRP_TRGCFG |= MDU_REGGRP_TRGCFG_REGGRP_CS_START;
	}
	
  /* Set the DMA transfer complete callback */
  hadc->hdmarx->XferCpltCallback = ADC_RegularDMAConvCplt;

  /* Set the DMA block complete callback */
  hadc->hdmarx->XferBlockCallback = ADC_RegularDMABlockConvCplt;
	
  /* Set the DMA error callback */
  hadc->hdmarx->XferErrorCallback = ADC_DMAError;

  /* Start the DMA channel */
  tmp_hal_status = HAL_DMA_Start_IT(hadc->hdmarx, (uint32_t)(&(hadc->Instance->REG_RESULTS_1)), (uint32_t)pData, Length);

  __HAL_UNLOCK(hadc);
  
	return tmp_hal_status;
}

/**
  * @brief  Disable ADC, stop conversion of regular group and transfer result through DMA.
  * @note   Interruptions enabled in this function:
  *         overrun (if applicable), DMA half transfer, DMA transfer complete.
  *         Each of these interruptions has its dedicated callback function.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Stop_RegularDMA(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  __HAL_LOCK(hadc);
	
	HAL_DMA_Abort(hadc->hdmarx);

	if((hadc->Instance->MDU_CFG & MDU_MDUCFG_REG_GRP_EN) 
		&& ((hadc->Instance->REGGRP_TRGCFG & MDU_REGGRP_TRGCFG_REGGRP_OPMODE) == ADC_CONVERT_CONTINUOUSSCAN))
	{
		hadc->Instance->REGGRP_TRGCFG &= ~(MDU_REGGRP_TRGCFG_REGGRP_CS_START);
	}
	
	HAL_ADC_Disable(hadc);

  __HAL_UNLOCK(hadc);

  return tmp_hal_status;
}

#else
HAL_StatusTypeDef HAL_ADC_Start_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
	
	__HAL_LOCK(hadc);
	
	HAL_ADC_Enable(hadc);

  /* Set the DMA transfer complete callback */
  hadc->hdmarx->XferCpltCallback = ADC_DMAConvCplt;

  /* Set the DMA error callback */
  hadc->hdmarx->XferErrorCallback = ADC_DMAError;

  /* Start the DMA channel */
  tmp_hal_status = HAL_DMA_Start_IT(hadc->hdmarx, (uint32_t)hadc->Instance->ADC_RESULTS_CH0, (uint32_t)pData, Length);

  __HAL_UNLOCK(hadc);
  
	return tmp_hal_status;
}
/**
  * @brief  Stop ADC conversion of regular group (and injected group in
  *         case of auto_injection mode), disable ADC DMA transfer, disable
  *         ADC peripheral.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Stop_DMA(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  __HAL_LOCK(hadc);
	
	HAL_DMA_Abort(hadc->hdmarx);
	
	HAL_ADC_Disable(hadc);

  __HAL_UNLOCK(hadc);

  return tmp_hal_status;
}
#endif /* XT32H0xxB */

#if defined(XT32H0xxB)
/**
  * @brief Get injection channel data
  * @param hadc ADC handle
  * @param ChannelIndex injection channel index
  * @retval data.
  */
uint32_t HAL_ADC_GetInjectionChannelData(ADC_HandleTypeDef *hadc, uint32_t ChannelIndex)
{
  uint32_t* preg = (uint32_t*)&(hadc->Instance->INJ_RESULTS_1);
  uint32_t offset = ChannelIndex >> 1;
  uint32_t pos = ChannelIndex & 1;

  return (uint32_t) *(preg + offset) >> (pos << 4);
}

/**
  * @brief Get regular channel data
  * @param hadc ADC handle
  * @param ChannelIndex injection channel index
  * @retval data.
  */
uint32_t HAL_ADC_GetRegularChannelData(ADC_HandleTypeDef *hadc, uint32_t ChannelIndex)
{
  uint32_t* preg = (uint32_t*)&(hadc->Instance->REG_RESULTS_1);
  uint32_t offset = ChannelIndex >> 1;
  uint32_t pos = ChannelIndex & 1;

  return (uint32_t) *(preg + offset) >> (pos << 4);
}
#else

/**
  * @brief  Get ADC regular group conversion result.
  * @note   Reading register DR automatically clears ADC flag EOC
  *         (ADC group regular end of unitary conversion).
  * @note   This function does not clear ADC flag EOS
  *         (ADC group regular end of sequence conversion).
  *         Occurrence of flag EOS rising:
  *          - If sequencer is composed of 1 rank, flag EOS is equivalent
  *            to flag EOC.
  *          - If sequencer is composed of several ranks, during the scan
  *            sequence flag EOC only is raised, at the end of the scan sequence
  *            both flags EOC and EOS are raised.
  *         To clear this flag, either use function:
  *         in programming model IT: @ref HAL_ADC_IRQHandler(), in programming
  *         model polling: @ref HAL_ADC_PollForConversion()
  *         or @ref __HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_EOS).
  * @param hadc ADC handle
  * @retval ADC group regular conversion data
  */
uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef *hadc)
{
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Note: EOC flag is not cleared here by software because automatically     */
  /*       cleared by hardware when reading register DR.                      */

  /* Return ADC converted value */
  return (hadc->Instance->ADC_RESULTS & MDU_ADC_OUTPUT_DATA);
}
#endif  /* XT32H0xxB */

/**
  * @brief  Handle ADC interrupt request.
  * @param hadc ADC handle
  * @param flag interrrupt flag
  */
void HAL_ADC_IRQHandler(ADC_HandleTypeDef *hadc)
{
#if defined(XT32H0xxB)
	uint32_t flag = ICTL->IRQFINALSTATUSH; 
  /* mask interrupts */
  SET_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_ADC_MASK);
	
  if(flag & ICTL_IRQ_ADC_INJ_EOC)
  {
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->InjectionEOCCallback();
#else    
    HAL_ADC_InjectionEOCCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
    /* clear flag */
    hadc->Instance->INT_STATUS_1 &= ~(ADC_FLAG_INJCH_EOC_1|ADC_FLAG_INJCH_EOC_2|ADC_FLAG_INJCH_EOC_3|ADC_FLAG_INJCH_EOC_4|
                                      ADC_FLAG_INJCH_OW_1|ADC_FLAG_INJCH_OW_2|ADC_FLAG_INJCH_OW_3|ADC_FLAG_INJCH_OW_4);
  }
  if(flag & ICTL_IRQ_ADC_INJ_EOS)
  {
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->InjectionEOSCallback();
#else    
    HAL_ADC_InjectionEOSCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
    /* clear flag */
    hadc->Instance->INT_STATUS_1 &= ~(ADC_FLAG_INJGRP_EOS|ADC_FLAG_INJGRP_OW);
  }
  if(flag & ICTL_IRQ_ADC_REG_EOC)
  {
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->RegularEOCCallback();
#else    
    HAL_ADC_RegularEOCCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
    /* clear flag */
    hadc->Instance->INT_STATUS_2 = 0;
    hadc->Instance->INT_STATUS_3 = 0;
  }
  if(flag & ICTL_IRQ_ADC_REG_EOS)
  {
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->RegularEOSCallback();
#else    
    HAL_ADC_RegularEOSCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
    /* clear flag */
    hadc->Instance->INT_STATUS_1 &= ~(ADC_FLAG_REGGRP_EOS|ADC_FLAG_REGGRP_OW);
  }
  if(flag & ICTL_IRQ_ADC_INJ_AWD)
  {
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->InjectionAwdCallback();
#else    
    HAL_ADC_InjectionAWDCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
    /* clear flag */
    hadc->Instance->INT_STATUS_1 &= ~(ADC_FLAG_INJCH_AWD_1|ADC_FLAG_INJCH_AWD_2|ADC_FLAG_INJCH_AWD_3|ADC_FLAG_INJCH_AWD_4);
  }
  if(flag & ICTL_IRQ_ADC_REG_AWD)
  {
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->RegularAwdCallback();
#else    
    HAL_ADC_RegularAWDCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
    /* clear flag */
    hadc->Instance->INT_STATUS_4 = 0;
  }
  
  /* unmask interrupts */
  CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_ADC_MASK);
#elif defined(XT32H0xxBMPW)	
	if(flag == ADC_FLAG_EOC)
	{
		/*clear interrupt*/
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvCpltCallback();
#else    
		HAL_ADC_EOCCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
	}
	else if(flag == ADC_FLAG_EOS)
	{
		if((SYSCFG->IRQ_CFG_1 & ICTL_IRQCFG_ADC_EOS_MASK))
		{
			return;
		}
		if(ICTL->IRQFINALSTATUSL & ICTL_IRQCFG_ADC_EOS_MASK)
		{
		
		/*clear interrupt*/
//		CLEAR_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_ENABLE);
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->SequenceCpltCallback();
#else    
		  HAL_ADC_EOSCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
		}
	}
#else  /* XT32H0xxAMPW */
	if(flag == ADC_FLAG_EOC)
	{
		/*clear interrupt*/
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvCpltCallback();
#else    
		HAL_ADC_EOCCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
	}
	else if(flag == ADC_FLAG_EOS)
	{
		if((SYSCFG->IRQ_CFG_1 & ICTL_IRQCFG_ADC_EOS_MASK))
		{
			return;
		}
		if(ICTL->IRQFINALSTATUSL & ICTL_IRQCFG_ADC_EOS_MASK)
		{
		
		/*clear interrupt*/
//		CLEAR_BIT(MDU->ADC_CTRL, MDU_ADCCTRL_ENABLE);
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->SequenceCpltCallback();
#else    
		  HAL_ADC_EOSCallback(hadc);
#endif /* (USE_HAL_ADC_REGISTER_CALLBACKS == 1) */    
		}
	}
#endif /* XT32H0xxAMPW */  
}

/**
  * @brief  ADC EOC callback in non-blocking mode
  *         (ADC conversion with interruption or transfer by DMA).
  * @param hadc ADC handle
  */
__weak void HAL_ADC_EOCCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_EOCCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC EOS callback in non-blocking mode
  *         (ADC conversion with interruption or transfer by DMA).
  * @param hadc ADC handle
  */
__weak void HAL_ADC_EOSCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_EOSCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC error callback in non-blocking mode
  *         (ADC conversion with interruption or transfer by DMA).
  * @note   In case of error due to overrun when using ADC with DMA transfer
  *         (HAL ADC handle parameter "ErrorCode" to state "HAL_ADC_ERROR_OVR"):
  *         - Reinitialize the DMA using function "HAL_ADC_Stop_DMA()".
  *         - If needed, restart a new ADC conversion using function
  *           "HAL_ADC_Start_DMA()"
  *           (this function is also clearing overrun flag)
  * @param hadc ADC handle
  */
__weak void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ErrorCallback must be implemented in the user file.
  */
}

#if defined(XT32H0xxB)
/**
  * @brief  ADC injection DMA callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_InjectionDMACompletedCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_DMACompletedCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC injection DMA block callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_InjectionDMABlockCompletedCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_DMACompletedCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC regular DMA callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_RegularDMACompletedCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_DMACompletedCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC regular DMA block callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_RegularDMABlockCompletedCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_DMACompletedCallback must be implemented in the user file.
  */
}
#else
__weak void HAL_ADC_DMACompletedCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_DMACompletedCallback must be implemented in the user file.
  */
}
#endif /* XT32H0xxB */

/**
  * @brief  ADC DMA error callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_DMAErrorCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_DMAErrorCallback must be implemented in the user file.
  */
}


#if defined(XT32H0xxB)
/**
  * @brief  ADC injection EOC callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_InjectionEOCCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_InjectionEOCCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC injection AWD callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_InjectionAWDCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_InjectionAWDCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC injection over write callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_InjectionOverWriteCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_InjectionOverWriteCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC injection EOS callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_InjectionEOSCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_InjectionEOSCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC regular EOC callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_RegularEOCCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_RegularEOCCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC regular AWD callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_RegularAWDCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_RegularAWDCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC regular over write callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_RegularOverWriteCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_RegularOverWriteCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC regular EOS callback
  * @param hadc ADC handle
  */
__weak void HAL_ADC_RegularEOSCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);

  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_RegularEOSCallback must be implemented in the user file.
  */
}
#endif /* XT32H0xxB */
/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group3 Peripheral Control functions
  * @brief    Peripheral Control functions
  *
@verbatim
 ===============================================================================
             ##### Peripheral Control functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Configure channels on regular group
      (+) Configure the analog watchdog

@endverbatim
  * @{
  */

/**
  * @brief  Configure a channel to be assigned to ADC group regular.
  * @note   In case of usage of internal measurement channels:
  *         Vbat/VrefInt/TempSensor.
  *         These internal paths can be disabled using function
  *         HAL_ADC_DeInit().
  * @note   Possibility to update parameters on the fly:
  *         This function initializes channel into ADC group regular,
  *         following calls to this function can be used to reconfigure
  *         some parameters of structure "ADC_ChannelConfTypeDef" on the fly,
  *         without resetting the ADC.
  *         The setting of these parameters is conditioned to ADC state:
  *         Refer to comments of structure "ADC_ChannelConfTypeDef".
  * @param hadc ADC handle
  * @param pConfig Structure of ADC channel assigned to ADC group regular.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef *hadc, void *pConfig)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
#if defined(XT32H0xxB)
#else
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_MODE(hadc->Init.Mode));
	assert_param(IS_ADC_TRGSOURCE(hadc->Init.TrgSrc));
  assert_param(IS_ADC_TRGMODE(hadc->Init.TrgMode));

  if (hadc->Init.Mode == ADC_CONVERT_MULTCH_SINGLE)
  {
    assert_param(IS_ADC_GROUP(hadc->Init.SeqGroup));
    assert_param(IS_ADC_GROUPDIRTECT(hadc->Init.SeqDir));
  }
  else
  {
    assert_param(IS_ADC_CHANNEL(hadc->Init.ConCh));
  }

  __HAL_LOCK(hadc);
	
	/* ADC conversion mode */
	__HAL_ADC_SET_CONVERT_MODE(hadc, hadc->Init.Mode);
	if(hadc->Init.Mode == ADC_CONVERT_MULTCH_SINGLE)
	{
		/* ADC channel group */
		__HAL_ADC_SET_GROUP(hadc, hadc->Init.SeqGroup);
		/* ADC channel mode */
		__HAL_ADC_SET_SEQCON_DIR(hadc, hadc->Init.SeqDir);
		
	}
	else 
	{
		/* ADC channel select */
		__HAL_ADC_SETCHANNEL(hadc, hadc->Init.ConCh);
	}

  /* ADC trigger source */
  __HAL_ADC_SET_TRG_SRC(hadc, hadc->Init.TrgSrc);
	/* ADC trigger mode */
	__HAL_ADC_SET_TRG_EDGE(hadc, hadc->Init.TrgMode);
	
  __HAL_UNLOCK(hadc);
#endif /* XT32H0xxB */
  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion.
  * @note   Prerequisite condition to use this function: ADC conversions must be
  *         stopped to disable the ADC.
  * @param  hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_ConversionStop(ADC_HandleTypeDef *hadc)
{
#if defined(XT32H0xxB)
  hadc->Instance->MDU_CFG &= ~(MDU_MDUCFG_ADC_EN);
#elif defined(XT32H0xxBMPW)	
	__HAL_ADC_RESET(hadc);
#else 
	/* ADC release reset, stop */
	__NOP();
	__NOP();
	__HAL_ADC_RESET(hadc);
	__NOP();
	__NOP();
	__HAL_ADC_SEQCON_STOP(hadc);
	__NOP();
	__NOP();
#endif /* XT32H0xxB */
  /* Return HAL status */
  return HAL_OK;
}

/**
  * @brief  Enable the selected ADC.
  * @note   Prerequisite condition to use this function: ADC must be disabled
  *         and voltage regulator must be enabled (done into HAL_ADC_Init()).
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Enable(ADC_HandleTypeDef *hadc)
{
#if defined(XT32H0xxB)
  hadc->Instance->MDU_CFG |= MDU_MDUCFG_ADC_EN;
#else

	/*ADC power on (analog)*/
	__HAL_ADC_POWERON(hadc);
	
	/* ADC release start and release reset */
	__NOP();
	__NOP();
	__HAL_ADC_SEQCON_START(hadc);
	__NOP();
	__NOP();
	__HAL_ADC_RESET_RELEASE(hadc);
	__NOP();
	__NOP();
#endif /* XT32H0xxB */
  /* Return HAL status */
  return HAL_OK;
}

/**
  * @brief  Disable the selected ADC.
  * @note   Prerequisite condition to use this function: ADC conversions must be
  *         stopped.
  * @param hadc ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Disable(ADC_HandleTypeDef *hadc)
{
#if defined(XT32H0xxB)
  hadc->Instance->MDU_CFG &= ~(MDU_MDUCFG_ADC_EN);
#else
	/* ADC release reset, stop */
	__NOP();
	__NOP();
	__HAL_ADC_RESET(hadc);
	__NOP();
	__NOP();
	__HAL_ADC_SEQCON_STOP(hadc);
	__NOP();
	__NOP();

  /*ADC power down (analog)*/
	__HAL_ADC_POWERDOWN(hadc);
#endif /* XT32H0xxB */
  /* Return HAL status */
  return HAL_OK;
}

#if defined(XT32H0xxB)
/**
  * @brief  ADC injection group configuration.
  * @param hadc ADC handle
  * @param pConfig configure handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_ConfigInjectionGroup(ADC_HandleTypeDef *hadc, void *pConfig)
{
  ADC_InjectionGroupInitTypeDef* pGroup = (ADC_InjectionGroupInitTypeDef*)pConfig;
	
	if(pGroup->TriggerSource == ADC_TRGSRC_SOFTWARE)
	{
		if ( pGroup->TriggerMode == ADC_TRIGGEREDGE_RISING)
		{
			__HAL_ADC_CLEAR_SWTRIGGER(hadc);
		}
		else if(pGroup->TriggerMode == ADC_TRIGGEREDGE_FALLING)
		{
			__HAL_ADC_SET_SWTRIGGER(hadc);
		}
			
	}
  
  MODIFY_REG(hadc->Instance->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_TRGSRC_1 << (pGroup->GroupIndex <<2), 
             pGroup->TriggerSource << (pGroup->GroupIndex<<2));
  MODIFY_REG(hadc->Instance->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_TRGCFG_1 << (pGroup->GroupIndex <<1), 
             (pGroup->TriggerMode << MDU_INJGRP_TRG_INJGRP_TRGCFG_1_Pos) << (pGroup->GroupIndex <<1));
	
	return HAL_OK;
}

/**
  * @brief  ADC injection group channel configuration.
  * @param hadc ADC handle
  * @param pConfig configure handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_ConfigInjectionChannel(ADC_HandleTypeDef *hadc, void *pConfig)
{
  ADC_InjectionChannelInitTypeDef* pChannel = (ADC_InjectionChannelInitTypeDef*)pConfig;
  
  /* define injection channel */
  MODIFY_REG(*(((uint32_t*)&(hadc->Instance->INJGRP_CHCR_1)) + pChannel->ChannelIndex), 
           MDU_INJGRP_CHCR_GRP_ID_1|MDU_INJGRP_CHCR_ADCCH_ID_1|MDU_INJGRP_CHCR_SMP_CYC_1|MDU_INJGRP_CHCR_AWD_ID_1, 
           (pChannel->GroupIndex+1) | 
           (pChannel->AdcChannelIndex << MDU_INJGRP_CHCR_ADCCH_ID_1_Pos) |
           (0x3F << MDU_INJGRP_CHCR_SMP_CYC_1_Pos) |
           /*(pChannel->PresamplingCycles << MDU_INJGRP_CHCR_SMP_CYC_1_Pos) |*/
           (pChannel->AWDId << MDU_INJGRP_CHCR_AWD_ID_1_Pos));

	return HAL_OK;
}

/**
  * @brief  ADC regular group configuration.
  * @param hadc ADC handle
  * @param pConfig configure handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_ConfigRegularGroup(ADC_HandleTypeDef *hadc, void *pConfig)
{
   ADC_RegularGroupInitTypeDef* pGroup = (ADC_RegularGroupInitTypeDef*)pConfig;

	 if(pGroup->TriggerSource == ADC_TRGSRC_SOFTWARE)
	 {
	 	if ( pGroup->TriggerMode == ADC_TRIGGEREDGE_RISING)
	 	{
	 		__HAL_ADC_CLEAR_SWTRIGGER(hadc);
	 	}
	 	else if(pGroup->TriggerMode == ADC_TRIGGEREDGE_FALLING)
	 	{
	 		__HAL_ADC_SET_SWTRIGGER(hadc);
	 	}
	 		
	 }

   MODIFY_REG(hadc->Instance->REGGRP_TRG, MDU_REGGRP_TRG_REGGRP_TRGSRC_1 << (pGroup->GroupIndex << 2), 
              pGroup->TriggerSource << (pGroup->GroupIndex << 2));
   MODIFY_REG(hadc->Instance->REGGRP_TRGCFG, MDU_REGGRP_TRGCFG_REGGRP_CFG_1 << (pGroup->GroupIndex << 1), 
             (pGroup->TriggerMode << MDU_REGGRP_TRGCFG_REGGRP_CFG_1_Pos) << (pGroup->GroupIndex << 1));
      
   *(((uint32_t*)&(hadc->Instance->REGGRP_SGRP_CHMAP_1)) + pGroup->GroupIndex) = pGroup->GroupMap;
	
	return HAL_OK;
}

/**
  * @brief  ADC regular group channel configuration.
  * @param hadc ADC handle
  * @param pConfig configure handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_ConfigRegularChannel(ADC_HandleTypeDef *hadc, void *pConfig)
{
  ADC_RegularChannelInitTypeDef* pChannel = (ADC_RegularChannelInitTypeDef*)pConfig;

  /* define regular channel */
  uint32_t* preg = (uint32_t*)&(hadc->Instance->REGGRP_CHCR_1);
  uint32_t offset = (pChannel->ChannelIndex) >> 2;
  uint32_t pos = (((pChannel->ChannelIndex) & 0x3) << 3);
  MODIFY_REG(*(preg + offset), 
           (MDU_REGGRP_CHCR_ADC_CHID_1 << pos)|(MDU_REGGRP_CHCR_AWD_ID_1 << pos), 
           (pChannel->AdcChannelIndex  << pos) | 
           ((pChannel->AWDId << MDU_INJGRP_CHCR_ADCCH_ID_1_Pos) << pos));
	
	return HAL_OK;
}

/**
  * @brief  ADC regular group channels map.
  * @param hadc ADC handle
  * @param Map channel map
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_ConfigRegularMAP(ADC_HandleTypeDef *hadc, uint32_t Map)
{
  hadc->Instance->REGGRP_CHMAP = Map;
	
	return HAL_OK;
}


/**
  * @brief  ADC AWD configuration.
  * @param hadc ADC handle
  * @param pConfig configure handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_ConfigAwd(ADC_HandleTypeDef *hadc, void *pConfig)
{
  ADC_AWDInitTypeDef* pAwd = (ADC_AWDInitTypeDef*)pConfig;
  uint32_t* preg = (uint32_t*)&(hadc->Instance->AWD_CR_1);
  uint32_t offset = (pAwd->AwdIndex);

  MODIFY_REG(*(preg + offset), 
           (MDU_AWD_CR_THR_LOW_1)|(MDU_AWD_CR_THR_HIGH_1)|MDU_AWD_CR_CFG_1, 
           (pAwd->LowThreshold << MDU_AWD_CR_THR_LOW_1_Pos) | 
           (pAwd->HighThreshold << MDU_AWD_CR_THR_HIGH_1_Pos) | 
           (pAwd->Mode));

	return HAL_OK;
}

/**
  * @brief  ADC calibrate.
  * @param hadc ADC handle
  * @retval HAL status.
  */
//HAL_StatusTypeDef HAL_ADC_Calibrate(ADC_HandleTypeDef *hadc)
//{
//  const uint32_t zoom = 14;

//  uint32_t hdata = 0;
//  uint32_t ldata = 0;

//  const uint32_t hcode = 45875;  /*code << 4*/
//  const uint32_t lcode = 19661;  /*code << 4*/

////  uint32_t tmp_status = 0;

//  uint32_t ecd = ((hcode-lcode)<<zoom);
//  uint32_t mcd = 0;

//  uint32_t gain = 1 << zoom;
//  uint32_t offset = 0 << zoom;

//  MODIFY_REG(ICG->CLK_CFG, ICG_CLK_CTL_ADCSRC, (uint32_t)(RCC_ADCCLKSOURCE_HCLK));
//  WRITE_REG(ICG->ADC_CLK_DIV, 1);

//  /* ADC core config */
//	MDU->ADC_CFG |= MDU_ADCCFG_MCONVMODE;  /* core in single conversion mode*/
//	
//  /* configure group conversion */
//  MODIFY_REG(MDU->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_SGRP_NUM, 
//             0x1UL << MDU_INJGRP_TRG_INJGRP_SGRP_NUM_Pos);

//  /* configure parameters */
//  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_DSCH_EN|MDU_MDUCFG_DSCH_PHS,
//             ADC_DISCHARGE_MODE_DISABLE);
//  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_SEL_PGA_CTRL|MDU_MDUCFG_SYNC_PHS,
//             ADC_PRESAMPLING_MODE_DEDICATED|(0x3UL << MDU_MDUCFG_SYNC_PHS_Pos));
//  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_RSTB_CYC,
//             0x2UL << MDU_MDUCFG_RSTB_CYC_Pos);
//  MODIFY_REG(MDU->DMA_CFG, MDU_ADCDMACFG_INJ_DMA_EN|MDU_ADCDMACFG_REG_DMA_EN,
//             ADC_INJGRP_DMA_DISABLE|ADC_REGGRP_DISABLE);
//	MODIFY_REG(MDU->ADC_CFG, MDU_ADCCFG_ADCOUTALIGN|MDU_ADCCFG_ADCDATAW,
//	           ADC_RESOLUTION_12B | ADC_OUTPUT_AGLIN_MSB);

//  /* powder on and enable */
//  CLEAR_BIT(MDU->PDCTRL, MDU_PDCTRL_ADCPD);
//  SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_START_EN|MDU_MDUCFG_ADC_RST);
//	
//	/* enable ADCC */
//	SET_BIT(MDU->ADC_CFG, MDU_ADCCFG_ADCC_EN);

//  /* interrupt enable */
//  MDU->INT_STATUS_1 = 0;  /* clear all flags */
//  MDU->INT_STATUS_2 = 0;
//  MDU->INT_STATUS_3 = 0;
//  MDU->INT_STATUS_4 = 0;

//  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_REG_INT_POL, ADC_INT_POLARITY_HIGH << MDU_MDUCFG_REG_INT_POL_Pos);
//  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_INJ_INT_POL, ADC_INT_POLARITY_HIGH << MDU_MDUCFG_INJ_INT_POL_Pos);

//  MODIFY_REG(MDU->MDU_CFG, MDU_MDUCFG_INJ_EOC_EN|MDU_MDUCFG_INJ_EOS_EN|MDU_MDUCFG_REG_EOC_EN|MDU_MDUCFG_REG_EOS_EN,
//             ADC_INT_ENABLE_INJGRP_EOS);

//  /* enable and unmask interrupt */
//  CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_ADC_MASK);
//  SET_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_ADC_MASK);

//  /* configure interupt */
//  CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQCFG_ADC_MASK);
//	
//  /* Configure Injection Group */
//  MODIFY_REG(MDU->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_TRGSRC_1, 
//             ADC_TRGSRC_SOFTWARE);
//  MODIFY_REG(MDU->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_TRGCFG_1, 
//            (ADC_TRIGGEREDGE_BOTH << MDU_INJGRP_TRG_INJGRP_TRGCFG_1_Pos));
// 
// 	MDU->PDCTRL |= MDU_PDCTRL_ADCBUF_EN;

//  /* measure 0.7vdd */
//  hdata = ADC_CalibrateMeasure(ADC_CALI_MEAS_MODE_HIGH) << 4;

//  /* measure 0.3vdd */
//	ldata = ADC_CalibrateMeasure(ADC_CALI_MEAS_MODE_LOW) << 4;

//  /* calculate gain & offset */
//  SET_BIT(SYSCFG->SYS_CFG, SYSCFG_SYS_CFG_HDIV_EN);

//  mcd = hdata - ldata;

//  HDIV->HDIV_A = ecd;
//  HDIV->HDIV_B = mcd;

//  gain = HDIV->HDIV_Q;  /* gain << zoom */
//  offset = (hcode << zoom) - hdata * gain; /* offset << zoom */

//  /* set calibrate register & enable */
//	MDU->ADC_CALIB = MDU_ADCCALIB_CODE_COR_EN|(gain << MDU_ADCCALIB_CODE_GAIN_Pos)|(offset << MDU_ADCCALIB_CODE_OFFSET_Pos);

//  return HAL_OK;
//}

#endif /* XT32H0xxB */

#if defined(XT32H0xxB)
/**
  * @brief  ADC enable auto mode
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_AutoModeEnable(ADC_HandleTypeDef *hadc)
{
  SET_BIT(hadc->Instance->ADC_CFG, MDU_ADCCFG_ADCC_EN);
  return HAL_OK;
}

/**
  * @brief  ADC enable manual mode
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ManualModeEnable(ADC_HandleTypeDef *hadc)
{
  CLEAR_BIT(hadc->Instance->ADC_CFG, MDU_ADCCFG_ADCC_EN);
  return HAL_OK;
}

/**
  * @brief  ADC enable conversion in manual mode
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ManualModeStart(ADC_HandleTypeDef *hadc)
{
  SET_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_START_EN);
  SET_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_RST);
  return HAL_OK;
}

/**
  * @brief  ADC stop conversion in manual mode
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ManualModeStop(ADC_HandleTypeDef *hadc)
{
  CLEAR_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_START_EN);
  CLEAR_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_RST);
  return HAL_OK;
}

/**
  * @brief  ADC conversion trigger in manual mode
  * @param hadc ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ManualModeTriggle(ADC_HandleTypeDef *hadc)
{
  CLEAR_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_SFTRG);
  SET_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_SFTRG);
  return HAL_OK;
}

/**
  * @brief  ADC configure in manual mode
  * @param hadc ADC handle
  * @param pConfig a pointer of config
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ManualModeConfig(ADC_HandleTypeDef *hadc, void* pConfig)
{
  ADC_ManualInitTypeDef *pInit = (ADC_ManualInitTypeDef*)pConfig;

  MODIFY_REG(hadc->Instance->ADC_CFG,
            MDU_ADCCFG_MSAMPEN | MDU_ADCCFG_RSTBDLY | MDU_ADCCFG_MCONVMODE,
            pInit->PGA_Sampling | pInit->Conversion_Mode | (pInit->Reset_Delay << MDU_ADCCFG_RSTBDLY_Pos));
  return HAL_OK;
}

/**
  * @brief  ADC select channel in manual mode
  * @param hadc ADC handle
  * @param Channel
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ManualModeChannelSelect(ADC_HandleTypeDef *hadc, uint32_t Channel)
{
  MODIFY_REG(hadc->Instance->ADC_CFG, MDU_ADCCFG_MCHSLCT, Channel);
  return HAL_OK;
}

/**
  * @brief  ADC get result of selected channel in manual mode
  * @param hadc ADC handle
  * @param Channel
  * @retval result
  */
uint32_t HAL_ADC_ManualModeGetValue(ADC_HandleTypeDef *hadc, uint32_t Channel)
{
  return READ_REG(hadc->Instance->REG_RESULTS_1);
}
#endif /* XT32H0xxB */

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group4 Peripheral State functions
  *  @brief    ADC Peripheral State functions
  *
  * @{
  */

/**
  * @brief  Return the ADC handle state.
  * @note   ADC state machine is managed by bitfields, ADC status must be
  *         compared with states bits.
  *         For example:
  *           " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_REG_BUSY) != 0UL) "
  *           " if ((HAL_ADC_GetState(hadc1) & HAL_ADC_STATE_AWD1) != 0UL) "
  * @param hadc ADC handle
  * @retval ADC handle state (bitfield on 32 bits)
  */
uint32_t HAL_ADC_GetState(ADC_HandleTypeDef *hadc)
{
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Return ADC handle state */
  return hadc->State;
}

/**
  * @brief  Return the ADC error code.
  * @param hadc ADC handle
  * @retval ADC error code (bitfield on 32 bits)
  */
uint32_t HAL_ADC_GetError(ADC_HandleTypeDef *hadc)
{
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  return hadc->ErrorCode;
}

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group5 Calibration functions
  *  @brief    ADC calibrate operation functions
  *
  * @{
  */
/**
  * @brief   ADC calibration process.
  * @param   hadc ADC handle
  * @retval  HAL status
  */
uint32_t                HAL_ADC_Calibration(ADC_HandleTypeDef *hadc)
{
	uint32_t adcclkdiv = 2;
	
//	uint16_t aADCxCaliData[ADC_CALI_MEAS_NUMBER*2];

//	int datidx = 0;
	int i=0;
	
	int avgl = 0;
	int avgh = 0;

	int k = 0;
	int offset = 0;
	
	int16_t kval = 0;
	int16_t offsetval = 0;

	/* set ADC clock */
	adcclkdiv = HAL_RCC_GetHCLKFreq() / ADC_CALI_MEAS_CLOCK;
	__HAL_RCC_ADC_CONFIG(RCC_ADCCLKSOURCE_HCLK);
	__HAL_RCC_SET_ADC_CLK_DIV(adcclkdiv);
	
	/* initial calibration */
	/* ADC core config */
	//hadc->Instance->ADC_CFG |= MDU_ADCCFG_MCONVMODE;  /* core in single conversion mode*/
	MODIFY_REG(hadc->Instance->ADC_CFG,
             MDU_ADCCFG_MCONVMODE|MDU_ADCCFG_AMPGAIN|MDU_ADCCFG_ADCTSAMPLE,
             MDU_ADCCFG_MCONVMODE| hadc->Init.AmplifierGain|MDU_ADCCFG_ADCTSAMPLE);
	
  /* configure group conversion */
  MODIFY_REG(hadc->Instance->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_SGRP_NUM, 
             1 << MDU_INJGRP_TRG_INJGRP_SGRP_NUM_Pos);

  /* configure parameters */
  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_DSCH_EN|MDU_MDUCFG_DSCH_PHS,
             ADC_DISCHARGE_MODE_DISABLE);
//  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_SEL_PGA_CTRL|MDU_MDUCFG_SYNC_PHS,
//             ADC_PRESAMPLING_MODE_DEDICATED|(3 << MDU_MDUCFG_SYNC_PHS_Pos));
  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_SEL_PGA_CTRL|MDU_MDUCFG_SYNC_PHS,
             ADC_PRESAMPLING_MODE_DEDICATED|(0x3F << MDU_MDUCFG_SYNC_PHS_Pos));
  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_RSTB_CYC,
             2 << MDU_MDUCFG_RSTB_CYC_Pos);
  MODIFY_REG(hadc->Instance->DMA_CFG, MDU_ADCDMACFG_INJ_DMA_EN|MDU_ADCDMACFG_REG_DMA_EN,
             ADC_INJGRP_DMA_DISABLE|ADC_REGGRP_DMA_DISABLE);
	MODIFY_REG(hadc->Instance->ADC_CFG, MDU_ADCCFG_ADCOUTALIGN|MDU_ADCCFG_ADCDATAW,
	           ADC_RESOLUTION_12B | ADC_OUTPUT_AGLIN_MSB);

  /* powder on and enable */
  CLEAR_BIT(hadc->Instance->PDCTRL, MDU_PDCTRL_ADCPD);
	SET_BIT(hadc->Instance->PDCTRL, MDU_PDCTRL_ADCBUF_EN);
	SET_BIT(hadc->Instance->PGA_CFG, MDU_PGACFG_ADC_VCM_HVDD);
  SET_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_START_EN|MDU_MDUCFG_ADC_RST);
	
	/* enable ADCC */
	SET_BIT(hadc->Instance->ADC_CFG, MDU_ADCCFG_ADCC_EN);

  /* interrupt enable */
  hadc->Instance->INT_STATUS_1 = 0;  /* clear all flags */
  hadc->Instance->INT_STATUS_2 = 0;
  hadc->Instance->INT_STATUS_3 = 0;
  hadc->Instance->INT_STATUS_4 = 0;

  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_REG_INT_POL, ADC_INT_POLARITY_HIGH << MDU_MDUCFG_REG_INT_POL_Pos);
  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_INJ_INT_POL, ADC_INT_POLARITY_HIGH << MDU_MDUCFG_INJ_INT_POL_Pos);

  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_INJ_EOC_EN|MDU_MDUCFG_INJ_EOS_EN|MDU_MDUCFG_REG_EOC_EN|MDU_MDUCFG_REG_EOS_EN,
             MDU_MDUCFG_INJ_EOS_EN);

  /* disable and unmask interrupt */
  CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_ADC_MASK);
  CLEAR_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_ADC_MASK);

  /* configure interupt */
  CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQCFG_ADC_MASK);

  /* config injection group 1 */
  MODIFY_REG(hadc->Instance->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_TRGSRC_1, 
             ADC_TRGSRC_SOFTWARE);
  MODIFY_REG(hadc->Instance->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_TRGCFG_1 , 
             (ADC_TRIGGEREDGE_BOTH << MDU_INJGRP_TRG_INJGRP_TRGCFG_1_Pos) );
 
	/* Configure Injection Channel */
  MODIFY_REG(*(((uint32_t*)&(hadc->Instance->INJGRP_CHCR_1))), 
           MDU_INJGRP_CHCR_GRP_ID_1|MDU_INJGRP_CHCR_ADCCH_ID_1|MDU_INJGRP_CHCR_SMP_CYC_1|MDU_INJGRP_CHCR_AWD_ID_1, 
           (ADC_INJGRP_1+1) | 
           (ADC_CHANNEL_P3AVDD << MDU_INJGRP_CHCR_ADCCH_ID_1_Pos) |
           (3 << MDU_INJGRP_CHCR_SMP_CYC_1_Pos) |
           (ADC_AWD_ID_NONE << MDU_INJGRP_CHCR_AWD_ID_1_Pos));
	
	/* measurement */
	MDU->PDCTRL |= (MDU_PDCTRL_ADCBUF_EN);
	MDU->ADC_CFG |= (MDU_ADCCFG_ADCTSAMPLE);
	MDU->MDU_CFG |= (MDU_MDUCFG_RSTB_CYC);
	
  hadc->Instance->REGGRP_TRGCFG &= ~(MDU_REGGRP_TRGCFG_REGGRP_CS_START);
	hadc->Instance->MDU_CFG |= MDU_MDUCFG_ADC_EN;

	for(i=0; i<ADC_CALI_MEAS_NUMBER; i++)
	{
		__HAL_ADC_TOGGLE_SWTRIGGER(hadc);
		
		HAL_ADC_PollForInjectionEOS(hadc, HAL_MAX_DELAY);

		hadc->Instance->INT_STATUS_1  = 0;
		
		//aADCxCaliData[datidx++] = HAL_ADC_GetInjectionChannelData(hadc, 0);
		if(i>1)
		{
		  avgl += (HAL_ADC_GetInjectionChannelData(hadc, 0) & 0xFFFF);
		}
		ADC_Delay(10);
	}

	hadc->Instance->MDU_CFG &= ~(MDU_MDUCFG_ADC_EN);

	/* Configure Injection Channel */
  MODIFY_REG(*(((uint32_t*)&(hadc->Instance->INJGRP_CHCR_1))), 
           MDU_INJGRP_CHCR_GRP_ID_1|MDU_INJGRP_CHCR_ADCCH_ID_1|MDU_INJGRP_CHCR_SMP_CYC_1|MDU_INJGRP_CHCR_AWD_ID_1, 
           (ADC_INJGRP_1+1) | 
           (ADC_CHANNEL_P7AVDD << MDU_INJGRP_CHCR_ADCCH_ID_1_Pos) |
           (0x3F << MDU_INJGRP_CHCR_SMP_CYC_1_Pos) |
           (ADC_AWD_ID_NONE << MDU_INJGRP_CHCR_AWD_ID_1_Pos));
	
  hadc->Instance->MDU_CFG |= MDU_MDUCFG_ADC_EN;
	
	for(i=0; i<ADC_CALI_MEAS_NUMBER; i++)
	{
		__HAL_ADC_TOGGLE_SWTRIGGER(hadc);
		
		HAL_ADC_PollForInjectionEOS(hadc, HAL_MAX_DELAY);

		hadc->Instance->INT_STATUS_1  = 0;
		
		//aADCxCaliData[datidx++] = HAL_ADC_GetInjectionChannelData(&hadccali, 0);
		if(i>1)
		{
  		avgh += (HAL_ADC_GetInjectionChannelData(hadc, 0) & 0xFFFF);
		}
		
		ADC_Delay(10);
	}

	hadc->Instance->MDU_CFG &= ~(MDU_MDUCFG_ADC_EN);
	
	/* calculate k & offset */
	avgl = avgl/(ADC_CALI_MEAS_NUMBER-2);
	avgh = avgh/(ADC_CALI_MEAS_NUMBER-2);
	
	k = 0.4*4096*65536/(avgh-avgl);
	offset = 0.7*4096*4-0.4*4096*avgh*4/(avgh-avgl);
	
	kval = ((int16_t)k) & 0x7FFF;
	offsetval = ((int16_t)offset) & 0x3FFF;
	
	/* set k & offset */
	MODIFY_REG(hadc->Instance->ADC_CALIB, MDU_ADCCALIB_CODE_GAIN, kval << MDU_ADCCALIB_CODE_GAIN_Pos);
	MODIFY_REG(hadc->Instance->ADC_CALIB, MDU_ADCCALIB_CODE_OFFSET, offsetval << MDU_ADCCALIB_CODE_OFFSET_Pos);

	return HAL_ADC_InitProcess(hadc);
}

/**
  * @brief   ADC calibration enable.
  * @param   hadc ADC handle
  * @retval  HAL status
  */
uint32_t                HAL_ADC_CalibrationEnable(ADC_HandleTypeDef *hadc)
{
	SET_BIT(hadc->Instance->ADC_CALIB, MDU_ADCCALIB_CODE_COR_EN);
	return HAL_OK;
}

/**
  * @brief   ADC calibration disable.
  * @param   hadc ADC handle
  * @retval  HAL status
  */
uint32_t                HAL_ADC_CalibrationDisable(ADC_HandleTypeDef *hadc)
{
	CLEAR_BIT(hadc->Instance->ADC_CALIB, MDU_ADCCALIB_CODE_COR_EN);
	return HAL_OK;
}	

/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup ADC_Private_Functions ADC Private Functions
  * @{
  */

#if defined(XT32H0xxB)
/**
  * @brief ADC initial process.
  * @param hadc pointer to ADC handle.
  */
HAL_StatusTypeDef HAL_ADC_InitProcess(ADC_HandleTypeDef *hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;

  uint32_t adcclk = 0;
  uint32_t rstpul = 0;

  /* Check ADC handle */
  if (hadc == NULL)
  {
    return HAL_ERROR;
  }

  /* - Initialization of ADC MSP                                              */
  if (hadc->State == HAL_ADC_STATE_RESET)
  {
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    /* Init the ADC Callback settings */
    hadc->ConvCpltCallback              = HAL_ADC_EOCCallback;                 /* Legacy weak callback */
    hadc->ErrorCallback                 = HAL_ADC_ErrorCallback;               /* Legacy weak callback */
    hadc->SequenceCpltCallback          = HAL_ADC_EOSCallback;                 /* Legacy weak callback */
#if defined(XT32H0xxB)
    hadc->InjectionEOCCallback          = HAL_ADC_InjectionEOCCallback;                 /* Legacy weak callback */
    hadc->INjectionEOSCallback          = HAL_ADC_InjectionEOSCallback;                 /* Legacy weak callback */
    hadc->InjectionAwdCallback          = HAL_ADC_InjectionAWDCallback;
    hadc->InjectionOverWriteCallback    = HAL_ADC_InjectionOverWriteCallback;
    hadc->RegularEOCCallback            = HAL_ADC_RegularEOCCallback;                 /* Legacy weak callback */
    hadc->RegularEOSCallback            = HAL_ADC_RegularEOSCallback;                 /* Legacy weak callback */
    hadc->RegularAwdCallback            = HAL_ADC_RegularAWDCallback;
    hadc->RegularOverWriteCallback      = HAL_ADC_RegularOverWriteCallback;
		hadc->InjectionDMACpltCallback      = HAL_ADC_InjectionDMACompletedCallback;
    hadc->RegularDMACpltCallback        = HAL_ADC_RegularDMACompletedCallback;		
		hadc->InjectionDMABlockCpltCallback = HAL_ADC_InjectionDMABlockCompletedCallback;
    hadc->RegularDMABlockCpltCallback   = HAL_ADC_RegularDMABlockCompletedCallback;		
#endif /* XT32H0xxB */
    if (hadc->MspInitCallback == NULL)
    {
      hadc->MspInitCallback = HAL_ADC_MspInit; /* Legacy weak MspInit  */
    }

    /* Init the low level hardware */
    hadc->MspInitCallback(hadc);
#else
    /* Init the low level hardware */
    HAL_ADC_MspInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

    /* Set ADC error code to none */
    ADC_CLEAR_ERRORCODE(hadc);

    /* Initialize Lock */
    hadc->Lock = HAL_UNLOCKED;
  }

#if defined(XT32H0xxB)
	/* ADC core config */
	//hadc->Instance->ADC_CFG |= MDU_ADCCFG_MCONVMODE;  /* core in single conversion mode*/
	MODIFY_REG(hadc->Instance->ADC_CFG,
             MDU_ADCCFG_MCONVMODE|MDU_ADCCFG_AMPGAIN|MDU_ADCCFG_ADCTSAMPLE,
             MDU_ADCCFG_MCONVMODE| hadc->Init.AmplifierGain|MDU_ADCCFG_ADCTSAMPLE);

	
  /* configure group conversion */
  if( hadc->Init.InjectionConversionEnable == ADC_INJGRP_ENABLE)
  {
    /* define injection group */
    MODIFY_REG(hadc->Instance->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_SGRP_NUM, 
               hadc->Init.InjectionGroupNumber << MDU_INJGRP_TRG_INJGRP_SGRP_NUM_Pos);
		
		__HAL_ADC_INJGRP_ENABLE(hadc);
  }
	else
	{
		MODIFY_REG(hadc->Instance->INJGRP_TRG, MDU_INJGRP_TRG_INJGRP_SGRP_NUM, 0);
		__HAL_ADC_INJGRP_DISABLE(hadc);
	}

  if( hadc->Init.RegularConversionEnable == ADC_REGGRP_ENABLE)
  {
    /* define regular group channel map */
    hadc->Instance->REGGRP_CHMAP = hadc->Init.RegularGroupMap;

    /* define regular group */
    MODIFY_REG(hadc->Instance->REGGRP_TRGCFG, MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM | MDU_REGGRP_TRGCFG_REGGRP_OPMODE, 
               (hadc->Init.RegularGroupNumber << MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM_Pos) |
               (hadc->Init.RegularScanMode));
    __HAL_ADC_REGGRP_ENABLE(hadc);
  }
	else
	{
		hadc->Instance->REGGRP_CHMAP = 0;
		MODIFY_REG(hadc->Instance->REGGRP_TRGCFG, MDU_REGGRP_TRGCFG_REGGRP_SGRP_NUM | MDU_REGGRP_TRGCFG_REGGRP_OPMODE, 0 );
		__HAL_ADC_REGGRP_DISABLE(hadc);
	}

  adcclk = HAL_RCC_GetPeriphCLKFreq(RCC_PERIPHCLK_ADC);
  rstpul = adcclk*2/1000000 - 1;
  if(hadc->Init.ResetPulseWidth > rstpul)
  {
    rstpul = hadc->Init.ResetPulseWidth;
  }

  /* configure parameters */
  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_DSCH_EN|MDU_MDUCFG_DSCH_PHS,
             hadc->Init.DischargeEnable|hadc->Init.DischargeCycles);
//  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_SEL_PGA_CTRL|MDU_MDUCFG_SYNC_PHS,
//             hadc->Init.PresamplingMode|(hadc->Init.PresamplingCycles << MDU_MDUCFG_SYNC_PHS_Pos));
  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_SEL_PGA_CTRL|MDU_MDUCFG_SYNC_PHS,
             hadc->Init.PresamplingMode|(0x3F << MDU_MDUCFG_SYNC_PHS_Pos));
//  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_RSTB_CYC,
//             hadc->Init.ResetPulseWidth << MDU_MDUCFG_RSTB_CYC_Pos);
  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_RSTB_CYC,
             rstpul << MDU_MDUCFG_RSTB_CYC_Pos);
  MODIFY_REG(hadc->Instance->DMA_CFG, MDU_ADCDMACFG_INJ_DMA_EN|MDU_ADCDMACFG_REG_DMA_EN,
             hadc->Init.RegularGroupDMAHandShakingMode|hadc->Init.InjectionGroupDMAHandShakingMode);
	MODIFY_REG(hadc->Instance->ADC_CFG, MDU_ADCCFG_ADCOUTALIGN|MDU_ADCCFG_ADCDATAW,
	           hadc->Init.ConversionResolution | hadc->Init.DataAlign);

  /* powder on and enable */
  CLEAR_BIT(hadc->Instance->PDCTRL, MDU_PDCTRL_ADCPD);
	SET_BIT(hadc->Instance->PDCTRL, MDU_PDCTRL_ADCBUF_EN);
	SET_BIT(hadc->Instance->PGA_CFG, MDU_PGACFG_ADC_VCM_HVDD);
  SET_BIT(hadc->Instance->MDU_CFG, MDU_MDUCFG_ADC_START_EN|MDU_MDUCFG_ADC_RST);
	
	/* enable ADCC */
	SET_BIT(hadc->Instance->ADC_CFG, MDU_ADCCFG_ADCC_EN);

  /* interrupt enable */
  hadc->Instance->INT_STATUS_1 = 0;  /* clear all flags */
  hadc->Instance->INT_STATUS_2 = 0;
  hadc->Instance->INT_STATUS_3 = 0;
  hadc->Instance->INT_STATUS_4 = 0;

  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_REG_INT_POL, hadc->Init.InterruptPolarity << MDU_MDUCFG_REG_INT_POL_Pos);
  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_INJ_INT_POL, hadc->Init.InterruptPolarity << MDU_MDUCFG_INJ_INT_POL_Pos);

  MODIFY_REG(hadc->Instance->MDU_CFG, MDU_MDUCFG_INJ_EOC_EN|MDU_MDUCFG_INJ_EOS_EN|MDU_MDUCFG_REG_EOC_EN|MDU_MDUCFG_REG_EOS_EN,
             hadc->Init.InterruptEnable);

  /* clear channels */
  hadc->Instance->INJGRP_CHCR_1 = 0x00030000; 
  hadc->Instance->INJGRP_CHCR_2 = 0x00030000; 
  hadc->Instance->INJGRP_CHCR_3 = 0x00030000; 
  hadc->Instance->INJGRP_CHCR_4 = 0x00030000; 
  
	hadc->Instance->REGGRP_SGRP_CHMAP_1 = 0x00000000; 
	hadc->Instance->REGGRP_SGRP_CHMAP_2 = 0x00000000; 
	hadc->Instance->REGGRP_SGRP_CHMAP_3 = 0x00000000; 
	hadc->Instance->REGGRP_SGRP_CHMAP_4 = 0x00000000; 
	hadc->Instance->REGGRP_SGRP_CHMAP_5 = 0x00000000; 
	hadc->Instance->REGGRP_SGRP_CHMAP_6 = 0x00000000; 
	hadc->Instance->REGGRP_SGRP_CHMAP_7 = 0x00000000; 
	hadc->Instance->REGGRP_SGRP_CHMAP_8 = 0x00000000; 
	
	hadc->Instance->REGGRP_CHCR_1 = 0x00000000;
	hadc->Instance->REGGRP_CHCR_2 = 0x00000000;
	hadc->Instance->REGGRP_CHCR_3 = 0x00000000;
	hadc->Instance->REGGRP_CHCR_4 = 0x00000000;
	hadc->Instance->REGGRP_CHCR_5 = 0x00000000;
	hadc->Instance->REGGRP_CHCR_6 = 0x00000000;
	hadc->Instance->REGGRP_CHCR_7 = 0x00000000;
	hadc->Instance->REGGRP_CHCR_8 = 0x00000000;

  /* enable and unmask interrupt */
  CLEAR_BIT(ICTL->IRQINTMASKH, ICTL_IRQCFG_ADC_MASK);
  SET_BIT(ICTL->IRQINTENH, ICTL_IRQCFG_ADC_MASK);

  /* configure interupt */
  CLEAR_BIT(SYSCFG->IRQ_CFG_2, ICTL_IRQCFG_ADC_MASK);

#elif defined(XT32H0xxBMPW)
  /* configure ADC_CTRL */
//  MODIFY_REG(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_CONV_MODE, ADC_CONVERT_MULTCH_SINGLE);

//  MODIFY_REG(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_GCHIND | MDU_ADCCTRL_CH_MODE 
//                          | MDU_ADCCTRL_FALLEDGE | MDU_ADCCTRL_RISEEDGE | MDU_ADCCTRL_TRGISRC,
//                          hadc->Init.SeqGroup | hadc->Init.SeqDir 
//                          | hadc->Init.TrgMode | hadc->Init.TrgSrc );

//	CLEAR_BIT(hadc->Instance->ADC_CFG, MDU_ADCCFG_SINGLECONV);   /* Core in continuous mode (don't change it) */
//  
//	hadc->Instance->ADC_CFG &= ~(MDU_ADCCFG_RSTBDLY);  /* reset core */
	
	//MDU->ADC_CFG = 0x30072100;
	MDU->ADC_CFG = MDU_ADCCFG_ADCTSAMPLE|MDU_ADCCFG_AMPMILLER|
	               MDU_ADCCFG_AMPGAIN_0|MDU_ADCCFG_ADCDTUNE_1|MDU_ADCCFG_ADCDTUNE_0|
	               MDU_ADCCFG_TS_TRIM_1|
	               MDU_ADCCFG_RSTBDLY_0;
  
	/* ADC Power on */
  CLEAR_BIT(hadc->Instance->PDCTRL, MDU_PDCTRL_ADCPD); /* power on core */

  /* ADC start */
//  SET_BIT(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_SEQ_STRT); /* start core */
  
  /* ADC release reset */
//  SET_BIT(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_RST);  /* release core to wait trigger */
	
	MDU->ADC_CTRL = MDU_ADCCTRL_GCHIND_0|MDU_ADCCTRL_PGASMPW_0|
	                hadc->Init.SeqDir|ADC_CONVERT_MULTCH_SINGLE| 
	                hadc->Init.TrgMode | hadc->Init.TrgSrc|
									MDU_ADCCTRL_SEQ_STRT|MDU_ADCCTRL_RST;

  /* enable and unmask interrupt */
	CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_ADC_EOS_MASK);
	SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_ADC_EOS_MASK);

//  /* configure interupt */
	CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_ADC_EOS_MASK);

//  HAL_NVIC_SetPriority(ADC_EOC_IRQn, 2, 0);   /* enable EOC interrupt */
//  HAL_NVIC_EnableIRQ(ADC_EOC_IRQn);

#else /* XT32H0xxAMPW */
  /* configure ADC_CTRL */
  MODIFY_REG(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_GCHIND | MDU_ADCCTRL_CH_MODE | MDU_ADCCTRL_CONV_MODE
                          | MDU_ADCCTRL_FALLEDGE | MDU_ADCCTRL_RISEEDGE | MDU_ADCCTRL_TRGISRC,
                          hadc->Init.SeqGroup | hadc->Init.SeqDir | hadc->Init.Mode
                          | hadc->Init.TrgMode | hadc->Init.TrgSrc );
  
	/* ADC Power on */
  CLEAR_BIT(hadc->Instance->PDCTRL, MDU_PDCTRL_ADCPD);

  /* ADC start */
  SET_BIT(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_SEQ_STRT);
  
  /* ADC release reset */
  SET_BIT(hadc->Instance->ADC_CTRL, MDU_ADCCTRL_RST);
	
  hadc->Instance->PDCTRL &= (uint32_t)(~(uint32_t)(MDU_PDCTRL_ADCPD));

  /* enable and unmask interrupt */
	CLEAR_BIT(ICTL->IRQINTMASKL, ICTL_IRQCFG_ADC_EOS_MASK);
	SET_BIT(ICTL->IRQINTENL, ICTL_IRQCFG_ADC_EOS_MASK);

  /* configure interupt */
	CLEAR_BIT(SYSCFG->IRQ_CFG_1, ICTL_IRQCFG_ADC_EOS_MASK);
#endif /* XT32H0xxAMPW */

	if(hadc->Init.CalibrationEnable)
	{
		SET_BIT(hadc->Instance->ADC_CALIB, MDU_ADCCALIB_CODE_COR_EN);
	}

  __HAL_UNLOCK(hadc);

  hadc->State = HAL_ADC_STATE_READY;

  return tmp_hal_status;
}

/**
  * @brief  injection DMA transfer complete callback.
  * @param hdma pointer to DMA handle.
  */
static void ADC_InjectionDMAConvCplt(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
	hadc->InjectionDMACpltCallback(hadc);
#else	
  HAL_ADC_InjectionDMACompletedCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */	
}

/**
  * @brief regular DMA transfer complete callback.
  * @param hdma pointer to DMA handle.
  */
static void ADC_RegularDMAConvCplt(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
	hadc->RegularDMACpltCallback(hadc);
#else	
  HAL_ADC_RegularDMACompletedCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */	
}

/**
  * @brief  injection DMA block transfer complete callback.
  * @param hdma pointer to DMA handle.
  */
static void ADC_InjectionDMABlockConvCplt(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
	hadc->InjectionDMABlockCpltCallback(hadc);
#else	
  HAL_ADC_InjectionDMABlockCompletedCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */	
}

/**
  * @brief regular DMA block transfer complete callback.
  * @param hdma pointer to DMA handle.
  */
static void ADC_RegularDMABlockConvCplt(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
	hadc->RegularDMABlockCpltCallback(hadc);
#else	
  HAL_ADC_RegularDMABlockCompletedCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */	
}

#if 0
/**
  * @brief ADC mesurement in calibration.
  * @param Mode
  * @retval data
  */
static uint32_t ADC_CalibrateMeasure(uint32_t Mode)
{
	uint32_t result = 0;
	
	uint32_t tmp_status = 0;
	
	uint32_t channel = (Mode) ? ADC_CHANNEL_P7AVDD : ADC_CHANNEL_P3AVDD;
	
  /* measure x vdd */
	/* Configure Injection Channel */
  MODIFY_REG(MDU->INJGRP_CHCR_1, 
           MDU_INJGRP_CHCR_GRP_ID_1|MDU_INJGRP_CHCR_ADCCH_ID_1|MDU_INJGRP_CHCR_SMP_CYC_1|MDU_INJGRP_CHCR_AWD_ID_1, 
           (ADC_INJGRP_1+1) | 
           (channel << MDU_INJGRP_CHCR_ADCCH_ID_1_Pos) |
           (0x3FUL << MDU_INJGRP_CHCR_SMP_CYC_1_Pos) |
           (ADC_AWD_ID_NONE << MDU_INJGRP_CHCR_AWD_ID_1_Pos));

  /* start */
  MDU->MDU_CFG |= MDU_MDUCFG_ADC_EN;
  MDU->REGGRP_TRGCFG &= ~(MDU_REGGRP_TRGCFG_REGGRP_CS_START);

	/* wait 10us */
	while(tmp_status < 10)
	{
		tmp_status++;
	}
	
  /* soft trigger */
  if(MDU->MDU_CFG & MDU_MDUCFG_ADC_SFTRG) 
  {
    CLEAR_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_SFTRG);
  }
  else
  {
    SET_BIT(MDU->MDU_CFG, MDU_MDUCFG_ADC_SFTRG);
  }
	
  /* read result */
  tmp_status = (MDU->INT_STATUS_1 & ADC_FLAG_INJGRP_EOS);

  /* Wait until End of unitary conversion or sequence conversions flag is raised */
  while (tmp_status == 0UL)
  {
    tmp_status = (MDU->INT_STATUS_1 & ADC_FLAG_INJGRP_EOS);
  }

  MDU->INT_STATUS_1  = 0;

  result = ((MDU->INJ_RESULTS_1)&0x0000FFFFUL) ;

  /* stop */
  MDU->MDU_CFG &= ~(MDU_MDUCFG_ADC_EN);
	
	return result;
}
#endif // 0

#else
/**
  * @brief  DMA conversion completed callback.
  * @param hdma pointer to DMA handle.
  */
static void ADC_DMAConvCplt(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  HAL_ADC_DMACompletedCallback(hadc);
  
//  /* Update state machine on conversion status if not in error state */
//  if ((hadc->State & (HAL_ADC_STATE_ERROR_INTERNAL | HAL_ADC_STATE_ERROR_DMA)) == 0UL)
//  {
//    /* Set ADC state */
//    SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);

//    /* Determine whether any further conversion upcoming on group regular     */
//    /* by external trigger, continuous mode or scan sequence on going         */
//    /* to disable interruption.                                               */
//    if ((LL_ADC_REG_IsTriggerSourceSWStart(hadc->Instance) != 0UL)
//        && (hadc->Init.ContinuousConvMode == DISABLE)
//       )
//    {
//      /* If End of Sequence is reached, disable interrupts */
//      if (__HAL_ADC_GET_FLAG(hadc, ADC_FLAG_EOS))
//      {
//        /* Allowed to modify bits ADC_IT_EOC/ADC_IT_EOS only if bit           */
//        /* ADSTART==0 (no conversion on going)                                */
//        if (LL_ADC_REG_IsConversionOngoing(hadc->Instance) == 0UL)
//        {
//          /* Disable ADC end of single conversion interrupt on group regular */
//          /* Note: Overrun interrupt was enabled with EOC interrupt in        */
//          /* HAL_Start_IT(), but is not disabled here because can be used     */
//          /* by overrun IRQ process below.                                    */
//          __HAL_ADC_DISABLE_IT(hadc, ADC_IT_EOC | ADC_IT_EOS);

//          /* Set ADC state */
//          ADC_STATE_CLR_SET(hadc->State,
//                            HAL_ADC_STATE_REG_BUSY,
//                            HAL_ADC_STATE_READY);
//        }
//        else
//        {
//          /* Change ADC state to error state */
//          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);

//          /* Set ADC error code to ADC peripheral internal error */
//          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
//        }
//      }
//    }

//    /* Conversion complete callback */
//#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
//    hadc->ConvCpltCallback(hadc);
//#else
//    HAL_ADC_ConvCpltCallback(hadc);
//#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
//  }
//  else /* DMA and-or internal error occurred */
//  {
//    if ((hadc->State & HAL_ADC_STATE_ERROR_INTERNAL) != 0UL)
//    {
//      /* Call HAL ADC Error Callback function */
//#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
//      hadc->ErrorCallback(hadc);
//#else
//      HAL_ADC_ErrorCallback(hadc);
//#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
//    }
//    else
//    {
//      /* Call ADC DMA error callback */
//      hadc->DMA_Handle->XferErrorCallback(hdma);
//    }
//  }
}
#endif /* XT32H0xxB */

/**
  * @brief  DMA error callback.
  * @param hdma pointer to DMA handle.
  */
static void ADC_DMAError(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef *hadc = (ADC_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  /* Set ADC state */
  SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);

  /* Set ADC error code to DMA error */
  SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_DMA);

  /* Error callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  hadc->ErrorCallback(hadc);
#else
  HAL_ADC_ErrorCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}

/**
  * @brief  ADC delay.
  * @param delay delay cycles.
  */
static void ADC_Delay(uint32_t delay)
{
	int i = 0;
	do {
		i++;
	}while(i<delay);
}

/**
  * @}
  */

#endif /* HAL_ADC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTECH *****END OF FILE****/
