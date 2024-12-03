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
#include "gpiotask.h"
#include "timeratask.h"

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
    XT_Gpio_Init();
    XT_TimerA_Init();
    XT_Nvic_Init();
    /* Infinite loop */
    while (1)
    {
        XT_TimerA_Task();
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
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI; 
    RCC_OscInitStruct.HSEState      = RCC_HSE_OFF;    
    RCC_OscInitStruct.HSIState      = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState  = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;   

    RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV12;  
    RCC_OscInitStruct.PLL.PLLN = RCC_PLLN_DIV_FREQ_64M; 
    RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV_FREQ_64M; 
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK;
    RCC_ClkInitStruct.SYSCLKSource  = RCC_SYSCLKSOURCE_HSI; 
    RCC_ClkInitStruct.AHBCLKDivider = HCLK_DIVIDER_VALUE;  
    RCC_ClkInitStruct.APBCLKDivider = PCLK_DIVIDER_VALUE; 

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, 0 /*FLASH_LATENCY_2*/) != HAL_OK)
    {
        Error_Handler();
    }

    /** Initializes the peripherals clocks
    */
    __HAL_RCC_SET_DMA_CLK_DIV(1);	
		
    __HAL_RCC_TIMAG_CONFIG(TIMAG_CLOCK_SRC);
    __HAL_RCC_SET_TIMER_ADV_CLK_DIV(TIMAG_DIVIDER);

}

/**
 * @brief  NVIC Initialization Function
 */
static void XT_Nvic_Init(void)
{
#if defined(XT32H0xxB)
    HAL_NVIC_SetPriority(DMA1_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(DMA1_IRQn);
	
   //HAL_NVIC_SetPriority(TIM1_CC_IRQn, 2, 0);
   //HAL_NVIC_EnableIRQ(TIM1_CC_IRQn);
	
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
void Error_Handler(void)
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
  * @param  io_idx:
  * @param  io_cfg:
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
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
