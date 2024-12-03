/**
  ******************************************************************************
  * @file    main.c
  * @author  Software Team
  * @brief   
  *          
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup Main_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/
#include "ledtask.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/** @addtogroup Main_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void XT_Nvic_Init(void);


/* Private user code ---------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();
    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    XT_Dmamem_Init();
    XT_Led_Init();
    XT_Nvic_Init();
	
    /* Infinite loop */
    while (1)
    {
        XT_Led_Task();
    }
}

/**
  * @brief System Clock Configuration
  */
static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Initializes the RCC Oscillators according to the specified parameters
    * in the RCC_OscInitTypeDef structure.
    */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;//RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI; 
    RCC_OscInitStruct.HSEState      = RCC_HSE_ON;    
    RCC_OscInitStruct.HSIState      = RCC_HSI_OFF;
    RCC_OscInitStruct.PLL.PLLState  = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE; //RCC_OscInitStruct.PLL.PLLSource =RCC_PLLSOURCE_HSI;  

    RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV12; //RCC_PLLM_DIV12;//RCC_PLLM_DIV4;//RCC_PLLM_DIV4;
    RCC_OscInitStruct.PLL.PLLN = RCC_PLLN_DIV_FREQ_64M;//RCC_PLLN_DIV_FREQ_48M;// RCC_PLLN_DIV_FREQ_96M; //
    RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV_FREQ_64M;//RCC_PLLR_DIV_FREQ_48M;//RCC_PLLR_DIV_FREQ_96M; //
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handle();
    }
    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK;
    RCC_ClkInitStruct.SYSCLKSource  = RCC_SYSCLKSOURCE_HSE; //RCC_SYSCLKSOURCE_PLL;//RCC_SYSCLKSOURCE_HSI;//
    RCC_ClkInitStruct.AHBCLKDivider = 1; //RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APBCLKDivider = 2; //RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, 0 /*FLASH_LATENCY_2*/) != HAL_OK)
    {
        Error_Handle();
    }

    /** Initializes the peripherals clocks
    */
    /* DMA controller clock enable */
    __HAL_RCC_DMA1_CLK_ENABLE();
}

/**
 * @brief  NVIC Initialization Function
 */
static void XT_Nvic_Init(void)
{
#if defined(XT32H0xxB)
    HAL_NVIC_SetPriority(DMA1_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(DMA1_IRQn);
    
    HAL_NVIC_SetPriority(ICTL_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(ICTL_IRQn);
#endif /* XT32H0xxB */
}

/**
  * @}
  */

/** @addtogroup Main_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed in case of error occurrence.
  */
void Error_Handle(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    while(1) 
    {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1)
  {
  }

  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @brief  This extern function used to select alternal function for PADI.
  * @note   None.
  * @param  pad_idx:
  * @param  pad_cfg:
  * @param  pin_pull:
  * @retval None
  */
void XT_IO_Option_Assigned(uint32_t io_idx, uint32_t io_cfg, uint32_t pin_pull)
{
    
    PADI_InitTypeDef sPadConfig = {0};
    
    sPadConfig.Pad           = io_idx;
    sPadConfig.Alternate     = io_cfg;
    sPadConfig.Pull          = pin_pull;
    sPadConfig.DriveStrength = PADI_DS_HIGH;
    HAL_PADI_Init(PADI, &sPadConfig);
}

/**
  * @brief  The interrupt source selection control of  ICTL pin 0~63 
  * @rmtoll SYSCFG.IRQ_CFG  pin          LL_ICTL_SetPinSelect
  * @param  irqModule the parameter can be ont of the follow values:
  *         @arg @ref XTAPP_ICTL_IRQ_I2C1   
  *         @arg @ref XTAPP_ICTL_IRQ_I2C2   
  *         @arg @ref XTAPP_ICTL_IRQ_SPI1   
  *         @arg @ref XTAPP_ICTL_IRQ_SPI2   
  *         @arg @ref XTAPP_ICTL_IRQ_TIMRB  
  *         @arg @ref XTAPP_ICTL_IRQ_TIMRB24
  *         @arg @ref XTAPP_ICTL_IRQ_ADC    
  *         @arg @ref XTAPP_ICTL_IRQ_lED    
  *         @arg @ref XTAPP_ICTL_IRQ_AFC    
  *         @arg @ref XTAPP_ICTL_IRQ_GPIO  
  * @param  Cfg_mask the parameter can be ont of the follow values:
  *         @arg @ref ICTL_IRQCFG_LED_MASK
  *         @arg @ref ICTL_IRQCFG_ADC_MASK
  *         @arg @ref ICTL_IRQCFG_SPI1_MASK
  *         @arg @ref ICTL_IRQCFG_SPI2_MASK
  *         @arg @ref ICTL_IRQCFG_I2C1_MASK
  *         @arg @ref ICTL_IRQCFG_I2C2_MASK
  *         @arg @ref ICTL_IRQCFG_TIMB1_MASK
  *         @arg @ref ICTL_IRQCFG_TIMB2_MASK
  *         @arg @ref GPIO_PIN_MASK
  * @retval None
  */
uint8_t XT_SYS_IRQ_Source_IsSelected(uint32_t irqModule, uint32_t Cfg_mask)
{
	uint32_t linerange = irqModule & ICTL_REG_MASK ;
	uint8_t syscfgval = irqModule & 0xFF;
	uint8_t selected =0;
	
	//mask = ICTL_GetMaskStatus(Cfg_mask,linerange);
	if(linerange == XTAPP_ICTL_PIN_RANGE00_31)
	{
		selected = LL_ICTL_GetMultiPinsSelect(0,Cfg_mask);
	}
	else if(linerange == XTAPP_ICTL_PIN_RANGE32_64)
	{
		selected = LL_ICTL_GetMultiPinsSelect(1,Cfg_mask);
	}
	
	if((syscfgval==XTAPP_SYS_IRQ_CFG1) && (selected&Cfg_mask)||
		(syscfgval==XTAPP_SYS_IRQ_CFG0) && (selected==0))
		return TRUE;

	return FALSE;
}


/**
  * @brief  The interrupt unmark and enable ICTL pin 0~63 
  * @rmtoll SYSCFG.IRQ_CFG  pin          LL_ICTL_SetPinSelect
  * @param  irqModule the parameter can be ont of the follow values:
  *         @arg @ref XTAPP_ICTL_IRQ_I2C1   
  *         @arg @ref XTAPP_ICTL_IRQ_I2C2   
  *         @arg @ref XTAPP_ICTL_IRQ_SPI1   
  *         @arg @ref XTAPP_ICTL_IRQ_SPI2   
  *         @arg @ref XTAPP_ICTL_IRQ_TIMRB  
  *         @arg @ref XTAPP_ICTL_IRQ_TIMRB24
  *         @arg @ref XTAPP_ICTL_IRQ_ADC    
  *         @arg @ref XTAPP_ICTL_IRQ_lED    
  *         @arg @ref XTAPP_ICTL_IRQ_AFC    
  *         @arg @ref XTAPP_ICTL_IRQ_GPIO  
  * @param  Cfg_mask the parameter can be ont of the follow values:
  *         @arg @ref ICTL_IRQCFG_LED_MASK
  *         @arg @ref ICTL_IRQCFG_ADC_MASK
  *         @arg @ref ICTL_IRQCFG_SPI1_MASK
  *         @arg @ref ICTL_IRQCFG_SPI2_MASK
  *         @arg @ref ICTL_IRQCFG_I2C1_MASK
  *         @arg @ref ICTL_IRQCFG_I2C2_MASK
  *         @arg @ref ICTL_IRQCFG_TIMB1_MASK
  *         @arg @ref ICTL_IRQCFG_TIMB2_MASK
  *         @arg @ref GPIO_PIN_0 or LL_ICTL_GPIO_0 
  *         @arg @ref ... 
  *         @arg @ref GPIO_PIN_31 or LL_ICTL_GPIO_31
  *         @arg @ref GPIO_PIN_MASK
  * @retval None
  */
void XT_ICTL_IRQ_Module_Enable(uint32_t irqModule, uint32_t Cfg_mask)
{
	uint32_t linerange = irqModule & ICTL_REG_MASK ;
	uint8_t syscfgval = irqModule & 0xFF;
	uint8_t linegrp = 0;

	 /* Configure ICTL and enable ICTL */ 
	if(linerange == XTAPP_ICTL_PIN_RANGE00_31)
	{	
		linegrp = 0;
		MODIFY_REG(ICTL->IRQINTMASKL, Cfg_mask, 0);   /*unmark, clear*/
		MODIFY_REG(ICTL->IRQINTENL, Cfg_mask, Cfg_mask);  /*enable*/
		 	
	}
	else if(linerange == XTAPP_ICTL_PIN_RANGE32_64)
	{	
		linegrp = 1;
		MODIFY_REG(ICTL->IRQINTMASKH, Cfg_mask, 0);   /*unmark, clear*/
		MODIFY_REG(ICTL->IRQINTENH, Cfg_mask, Cfg_mask);  /*enable*/
	}
	
	if(syscfgval == XTAPP_SYS_IRQ_CFG1)
		LL_ICTL_SetMultiPinsSelect(linegrp,Cfg_mask,Cfg_mask);	
	else
		LL_ICTL_SetMultiPinsSelect(linegrp,Cfg_mask,~Cfg_mask);	

	return;
}
/**
  * @brief  Get final Interrupt request for Lines in range 0 to 63 
  * @rmtoll SYSCFG.IRQ_CFG  pin          LL_ICTL_SetPinSelect
  * @param  irqModule the parameter can be ont of the follow values:
  *         @arg @ref XTAPP_ICTL_IRQ_I2C1   
  *         @arg @ref XTAPP_ICTL_IRQ_I2C2   
  *         @arg @ref XTAPP_ICTL_IRQ_SPI1   
  *         @arg @ref XTAPP_ICTL_IRQ_SPI2   
  *         @arg @ref XTAPP_ICTL_IRQ_TIMRB  
  *         @arg @ref XTAPP_ICTL_IRQ_TIMRB24
  *         @arg @ref XTAPP_ICTL_IRQ_ADC    
  *         @arg @ref XTAPP_ICTL_IRQ_lED    
  *         @arg @ref XTAPP_ICTL_IRQ_AFC    
  *         @arg @ref XTAPP_ICTL_IRQ_GPIO  
  * @param  Cfg_mask the parameter can be ont of the follow values:
  *         @arg @ref ICTL_IRQCFG_LED_MASK
  *         @arg @ref ICTL_IRQCFG_ADC_MASK
  *         @arg @ref ICTL_IRQCFG_SPI1_MASK
  *         @arg @ref ICTL_IRQCFG_SPI2_MASK
  *         @arg @ref ICTL_IRQCFG_I2C1_MASK
  *         @arg @ref ICTL_IRQCFG_I2C2_MASK
  *         @arg @ref ICTL_IRQCFG_TIMB1_MASK
  *         @arg @ref ICTL_IRQCFG_TIMB2_MASK
  *         @arg @ref GPIO_PIN_0 or LL_ICTL_GPIO_0 
  *         @arg @ref ... 
  *         @arg @ref GPIO_PIN_31 or LL_ICTL_GPIO_31
  *         @arg @ref GPIO_PIN_MASK
  * @retval None
  */
uint32_t XT_ICTL_IRQ_FinalStatus_Check(uint32_t irqModule, uint32_t Irq_lines)
{
	uint32_t linerange = irqModule & ICTL_REG_MASK ;	
//	uint8_t syscfgval = irqModule & 0xFF;
	uint32_t status = 0;
	
	if(linerange == XTAPP_ICTL_PIN_RANGE00_31)
	{	
		status = READ_REG(ICTL->IRQFINALSTATUSL) & Irq_lines;		 	
	}
	else if(linerange == XTAPP_ICTL_PIN_RANGE32_64)
	{	
		status = READ_REG(ICTL->IRQFINALSTATUSH) & Irq_lines;
	}
	
	return status; 
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

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
