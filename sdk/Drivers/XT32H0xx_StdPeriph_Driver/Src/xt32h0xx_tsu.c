/**
  ******************************************************************************
  * @file    xt32h0xx_tsu.c
  * @author  Software Team
  * @date    29 November 2022
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_tsu.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */
/** @defgroup TSU TSU
  * @brief TSU driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup TSU_Private_Constants TSU Private Constants
  * @{
  */
#define TSU_MRSLT_BASE  (0x8002C000UL)
#define TSU_MRSLT_SIZE  (0x1F0UL) 
#define TSU_JRSLT_BASE  (0x8002C1F0UL)
#define TSU_JRSLT_SIZE  (0x10UL) 
/**
  * @}
  */
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup TSU_Exported_Functions TSU Exported Functions
  * @{
  */

/** @defgroup TSU_Exported_Functions_Group1 Initialized Functions
  * @{
  */
/**
  * @brief  De-Initialize the TSU
  */
void TSU_DeInit(void)
{}

/**
  * @brief  Initialize the TSU
  */
void TSU_Init(TSU_InitTypeDef* TSU_InitStruct)
{
//  TSU->DCTRL &= (uint32_t)(~(TSU_DCTRL_MSS)); 
//  TSU->DCTRL |= htsu->Init.TriggerMode);                 /*!< MSS */

	/* sensor pulse configure */
	TSU->DCTRL &= (uint32_t)(~(TSU_DCTRL_SDPSEL));
  TSU->DCTRL |= (uint32_t)(TSU_InitStruct->SensorPulseMode); /*!< Sensor pulse mode. (CTRL0.SDPSEL) This parameter is a value of @ref TSU_SENSOR_DRIVE_PULSE_MODE*/
	
	/* ccobias, cmode configure */
	TSU->ACTRL &= (uint32_t)(~(TSU_ACTRL_CCOBS|TSU_ACTRL_CMD));
  TSU->ACTRL |= (uint32_t)(TSU_InitStruct->CcoBias | TSU_InitStruct->CurrentMode); 
	
	/* spread spectrum initalial */
	TSU->DCTRL &= (uint32_t)(~(TSU_DCTRL_SOFF));
  TSU->DCTRL |= (uint32_t)(TSU_InitStruct->SpreadSpectrumEnable);
	TSU->DIV &= (uint32_t)(~(TSU_DIV_SSDIV));
  TSU->DIV |= (uint32_t)(TSU_InitStruct->SpreadSpectrumCnt);

  /* PRG initalial */
  TSU->DCTRL &= (uint32_t)(~(TSU_DCTRL_PROFF | TSU_DCTRL_PHT | TSU_DCTRL_PHS));
  TSU->DCTRL |= (uint32_t)( TSU_InitStruct->PrnEnable | TSU_InitStruct->PrnGenerateCycle | TSU_InitStruct->PrnUpdateCycle);
	
	/* SUCLK SS */
	TSU->AD &= (uint32_t)(~(TSU_AD_SSCTRL|TSU_AD_SSNUM));
  TSU->AD |= (uint32_t)((TSU_InitStruct->SUCLKSSMode)|(TSU_InitStruct->SUCLKSSPeriod << TSU_AD_SSNUM_Pos));
	
	/* tuning */
	TSU->OPT &= (uint32_t)(~(TSU_OPT_TUNEN));
  TSU->OPT |= (uint32_t)(TSU_InitStruct->TuningEnable);

}

/**
  * @brief  Filled Initial struct the TSU
  */
void TSU_StructInit(TSU_InitTypeDef* TSU_InitStruct)
{
  TSU_InitStruct->TriggerMode           = TSU_TRG_SOFTWARE;
  TSU_InitStruct->SensorPulseMode       = TSU_SDPMODE_HIGHRESOLUTION;
  TSU_InitStruct->SpreadSpectrumEnable  = TSU_SS_DISABLE;
  TSU_InitStruct->SpreadSpectrumCnt     = TSU_SS_PERIOD_2;
  TSU_InitStruct->PrnEnable             = TSU_PRN_DISABLE;
  TSU_InitStruct->PrnGenerateCycle      = TSU_PRN_PERIOD_31;
  TSU_InitStruct->PrnUpdateCycle        = TSU_PRN_UPDATE_3;
  TSU_InitStruct->SUCLKSSMode           = TSU_SUCLK_SS_CTRL_00;
  TSU_InitStruct->SUCLKSSPeriod         = 0;
  TSU_InitStruct->CcoBias               = 0;
  TSU_InitStruct->CurrentMode           = TSU_CURRENT_RANGE_40uA;
  TSU_InitStruct->TuningEnable          = 0;
}
/**
  * @}
  */

/** @defgroup TSU_Exported_Functions_Group2 Scan and Measure Functions
  * @{
  */
/**
  * @brief  TSU Scan Configure
  */
void TSU_ScanConfig(TSU_ScanTypeDef* TSU_ScanCfg)
{
	uint32_t temp = 0;
	uint32_t clk = 0;

  TSU->SCANNUM &= (uint32_t)(~(TSU_SCANNUM_SCANNUM));
  TSU->SCANNUM |= (uint32_t)(TSU_ScanCfg->ScanNum);

  TSU->DCTRL &= (uint32_t)(~(TSU_DCTRL_MD0|TSU_DCTRL_MD));
  TSU->DCTRL |= (uint32_t)(TSU_ScanCfg->ScanMode);

	temp = (TSU_ScanCfg->FreqPattern & 0x1);
	temp += ((TSU_ScanCfg->FreqPattern & 0x2)>>1);
	temp += ((TSU_ScanCfg->FreqPattern & 0x4)>>2);
	temp += ((TSU_ScanCfg->FreqPattern & 0x8)>>3);
	
	TSU->SUCLK1 = TSU_ScanCfg->Freq[0];
	TSU->SUCLK2 = TSU_ScanCfg->Freq[1];
	TSU->SUCLK3 = TSU_ScanCfg->Freq[2];
	TSU->SUCLK4 = TSU_ScanCfg->Freq[3];
	
	clk = 384*(RCC_GetSYSCLKClock()/1000/1000/2)/temp - 1;
	TSU->TS &= (uint32_t)(~(TSU_TS_MSNUM));
  TSU->TS |= (uint32_t)(clk << TSU_TS_MSNUM_Pos);
	
	if(TSU->DCTRL & TSU_DCTRL_SDPSEL)
	{
	  clk = (RCC_GetSYSCLKClock()/1000/1000/2) - 1;  //n+1 1M
	}
	else
	{
		clk = ((RCC_GetSYSCLKClock()/1000/1000/2) - 1)/2;  //2(n+1) 1M
	}
	TSU->DIV &= (uint32_t)(~(TSU_DIV_BDIV));
  TSU->DIV |= (uint32_t)(clk << TSU_DIV_BDIV_Pos);
	
	TSU->FRECFG = TSU_ScanCfg->FreqPattern;
	TSU->OPT &= (uint32_t)(~(TSU_OPT_FREJFEN)); 
  TSU->OPT |= (uint32_t)(TSU_ScanCfg->FreqJudgmentEnable);
	
	TSU->CHEN = TSU_ScanCfg->ChannelEnable;
	TSU->CHCTRL = TSU_ScanCfg->ChannleMode;
	
	/* auto-judgment enable */
	TSU->OPT &= (uint32_t)(~(TSU_OPT_AJFEN)); 
  TSU->OPT |= (uint32_t)(TSU_ScanCfg->AutoJudgeEnable);
	TSU->AJCTRL &= (uint32_t)(~(TSU_AJC_JC)), 
  TSU->AJCTRL |= (uint32_t)(TSU_ScanCfg->AutoJudgeCondition);
	
	/* auto-correction enable */
	TSU->OPT &= (uint32_t)(~(TSU_OPT_CCOCFEN)); 
  TSU->OPT |= (uint32_t)(TSU_ScanCfg->AutoCorrectionEnable);
	

	/* interrupts enable */
	TSU->INTEN = TSU_ScanCfg->InterruptEnable;

	/*init for simulation*/
	TSU->TRIM0 &= (uint32_t)(~(TSU_TRIM_RTRIM | TSU_TRIM_SUADJD));
  TSU->TRIM0 |= (uint32_t)((0x10 <<TSU_TRIM_RTRIM_Pos) | (0x30 <<TSU_TRIM_SUADJD_Pos));
	
	TSU->TRIM1 = 0x30303030UL;
	
}

/**
  * @brief  Filled Scan struct the TSU
  */
void TSU_StructScanCfg(TSU_ScanTypeDef* TSU_ScanCfg)
{
  TSU_ScanCfg->ScanNum              = 11;
  TSU_ScanCfg->ChannelEnable        = 0x0F;
  TSU_ScanCfg->ChannleMode          = 0;
  TSU_ScanCfg->ScanMode             = TSU_MEAS_MODE_SELF|TSU_SCAN_MODE_MULTI;
  TSU_ScanCfg->FreqPattern          = TSU_FRQCFG_MCA0;
  TSU_ScanCfg->Freq[0]              = 0x3F;
  TSU_ScanCfg->Freq[1]              = 0x36;
  TSU_ScanCfg->Freq[2]              = 0x48;
  TSU_ScanCfg->Freq[3]              = 0x3F;
  TSU_ScanCfg->FreqJudgmentEnable   = TSU_FREQJUDGMENT_DISABLE;
  TSU_ScanCfg->AutoJudgeEnable      = TSU_AUTOJUDGMENT_ENABLE;
  TSU_ScanCfg->AutoJudgeCondition   = TSU_AJC_FOUR;
  TSU_ScanCfg->AutoCorrectionEnable = TSU_CORRECTION_DISABLE;
  TSU_ScanCfg->InterruptEnable      = 0xFFF;
}

/**
  * @brief  TSU AFC Configure
  */
void TSU_AFCConfig(TSU_AFCTypeDef* TSU_AfcCfg)
{
  TSU->AFCCTRL &= (uint32_t)(~(TSU_AFCCTRL_AFCPRD|TSU_AFCCTRL_DIFFCNT));
  TSU->AFCCTRL |= (uint32_t)((TSU_AfcCfg->AFCPeriod << TSU_AFCCTRL_AFCPRD_Pos)
                            |(TSU_AfcCfg->Diff << TSU_AFCCTRL_DIFFCNT_Pos));

  TSU->OPT &= (uint32_t)(~(TSU_OPT_SYSCLK));
  TSU->OPT |= (uint32_t)(TSU_AfcCfg->SysClk);

  TSU->AFCCFG &= (uint32_t)(~(TSU_AFCCFG_CBCLKS));
  TSU->AFCCFG |= (uint32_t)(TSU_AfcCfg->Clock);

  TSUSYS->CTSM_SYSCFG &= (uint32_t)(~(TSUSYS_SYSCFG_AFCRDIV));
  TSUSYS->CTSM_SYSCFG |= (uint32_t)(TSU_AfcCfg->RefclkDivider << TSUSYS_SYSCFG_AFCRDIV_Pos);
}

/**
  * @brief  Filled Initial struct the TSU
  */
void TSU_StructAfcCfg(TSU_AFCTypeDef* TSU_AfcCfg)
{
  TSU_AfcCfg->AFCPeriod       = 128;
  TSU_AfcCfg->SysClk          = TSU_SYSCLK_32M;
  TSU_AfcCfg->RefclkDivider   = 12;
  TSU_AfcCfg->Clock           = TSU_AFC_REFCLK_CCOCLK;
  TSU_AfcCfg->Diff            = 16;
} 

/**
  * @brief  TSU Normal Scan Start
  */
void TSU_NormalScanStart(void)
{
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_MSTRT|SYSCFG_CTSM_INT_INTGEN);
}

/**
  * @brief  TSU Correct Scan Start
  */
void TSU_CorrectScanStart(void)
{
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_CSTRT|SYSCFG_CTSM_INT_INTGEN);
}

/**
  * @brief  TSU temp correct scan start
  */
void TSU_TempCorrectScanStart(void)
{
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_TCSTRT|SYSCFG_CTSM_INT_INTGEN); 
}

/**
  * @brief  TSU current scan start
  */
void TSU_CurrentScanStart(void)
{
   SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_DCSTRT|SYSCFG_CTSM_INT_INTGEN);
}

/**
  * @brief  TSU internal current scan start
  */
void TSU_IntCurrentScanStart(void)
{
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_IDCSTRT|SYSCFG_CTSM_INT_INTGEN);
}

/**
  * @brief  TSU scan stop
  */
void TSU_ScanStop(void)
{
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_MSTOP|SYSCFG_CTSM_INT_INTGEN);
}

/**
  * @brief  get TSU status
  */
void TSU_IsBusy(void)
{
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_GETST|SYSCFG_CTSM_INT_INTGEN);
}

/**
  * @brief  TSU AFC start
  */
void TSU_AFCStart(void)
{
  SYSCFG->CTSM_INT |=  (SYSCFG_CTSM_INT_AFC|SYSCFG_CTSM_INT_INTGEN);
}

/**
  * @brief  TSU get measurement data
  * @param  pBuffer
  * @param  size
  * @retval get size
  */
uint32_t TSU_MeasureDataGet(uint32_t* pBuffer, uint32_t size)
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
  * @brief  TSU get Auto judgment data
  * @param  pBuffer
  * @param  size
  * @retval get size
  */
uint32_t TSU_AutoJudgmentDataGet(uint32_t* pBuffer, uint32_t size)
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

