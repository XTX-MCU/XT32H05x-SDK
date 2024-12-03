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

/* Private includes ----------------------------------------------------------*/
#include "gpiotask.h"

/** @addtogroup App_Gpio
  * @{
  */

/** @addtogroup Gpio_Blink Gpio Blink
  * @{
  */

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/	

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup App_Private_Functions
  * @{
  */
static void SystemClock_Config(void);
static void XT_Nvic_Init(void);
/** 
  * @}
  */

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
  XT_Nvic_Init();
	
	XT_Gpio_Init();		

	while(1)
	{	
		XT_Gpio_Task();
	}
	
	return 0;
}

/** @addtogroup App_Private_Functions App Private Functions
  * @{
  */

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
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;    
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE; //RCC_OscInitStruct.PLL.PLLSource =RCC_PLLSOURCE_HSI;  
	
	RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV12; //RCC_PLLM_DIV12;//RCC_PLLM_DIV4;//RCC_PLLM_DIV4;
	RCC_OscInitStruct.PLL.PLLN = RCC_PLLN_DIV_FREQ_64M;//RCC_PLLN_DIV_FREQ_48M;// RCC_PLLN_DIV_FREQ_96M; //
	RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV_FREQ_64M;//RCC_PLLR_DIV_FREQ_48M;//RCC_PLLR_DIV_FREQ_96M; //
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}
	/** Initializes the CPU, AHB and APB buses clocks
	*/
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE; //RCC_SYSCLKSOURCE_PLL;//RCC_SYSCLKSOURCE_HSI;//
	RCC_ClkInitStruct.AHBCLKDivider = 1; //RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APBCLKDivider = 2; //RCC_HCLK_DIV1;
	
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, 0 /*FLASH_LATENCY_2*/) != HAL_OK)
	{
		Error_Handler();
	}

  /** Initializes the peripherals clocks
  */
  __HAL_RCC_GPIO_CONFIG(RCC_GPIOCLKSOURCE_HSE);
  __HAL_RCC_SET_GPIO_CLK_DIV(1);

}

/**
 * @brief  NVIC Initialization Function
 */
static void XT_Nvic_Init(void)
{
#if defined(XT32H0xxB)
  HAL_NVIC_SetPriority(ICTL_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(ICTL_IRQn);
#endif /* XT32H0xxB */
}
/** 
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @addtogroup App_Exported_Functions App Exported Functions
  * @{
  */

/**
  * @brief  This function is executed in case of error occurrence.
  */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	while (1)
	{
		HAL_Delay(1000);
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
  * @}
  */

/** 
  * @}
  */

/** 
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
