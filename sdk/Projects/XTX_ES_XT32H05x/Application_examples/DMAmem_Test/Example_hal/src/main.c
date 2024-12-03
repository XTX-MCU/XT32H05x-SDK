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
#include "dmamemtask.h"
#include "uarttask.h"

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
    XT_Uart_Init();
    XT_Nvic_Init();
	
    XT_Dmamem_Task();
    /* Infinite loop */
    while (1)
    {
    /* USER CODE */
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
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;    
    RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
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
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE; //RCC_SYSCLKSOURCE_PLL;//RCC_SYSCLKSOURCE_HSI;//
    RCC_ClkInitStruct.AHBCLKDivider = 1; //RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APBCLKDivider = 2; //RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, 0 /*FLASH_LATENCY_2*/) != HAL_OK)
    {
        Error_Handle();
    }

    /** Initializes the peripherals clocks
    */
    __HAL_RCC_SET_DMA_CLK_DIV(1);
    
		__HAL_RCC_BR_CONFIG(RCC_BRCLKSOURCE_HSE);
    __HAL_RCC_SET_BR_CLK_DIV(1);
}

/**
 * @brief  NVIC Initialization Function
 */
static void XT_Nvic_Init(void)
{
#if defined(XT32H0xxB)
    HAL_NVIC_SetPriority(DMA1_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(DMA1_IRQn);
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

/**
  * @brief  Compares two buffers.
  * @param  pBuffer1, pBuffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval 0  : pBuffer1 identical to pBuffer2
  *         >0 : pBuffer1 differs from pBuffer2
  */
uint16_t Buffercmp(uint8_t *pBuffer1, uint8_t *pBuffer2, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if ((*pBuffer1) != *pBuffer2)
    {
      return BufferLength;
    }
    pBuffer1++;
    pBuffer2++;
  }
  
  return 0;
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
