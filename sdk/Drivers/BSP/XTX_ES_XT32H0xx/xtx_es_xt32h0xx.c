/**
  ******************************************************************************
  * @file    xtx_es_xt32h0xx.c
  * @author  Software Team
  * @brief   This file provides set of firmware functions to manage:
  *          - LEDs and push-button available on XTX_ES_XT32H0XX Kit 
  *            from XTXTech
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 XTXTech.
  * All rights reserved.
  *
  *
  ******************************************************************************
  */ 
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "xtx_es_xt32h0xx.h"

/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup XTX_ES_XT32H0XX
  * @{
  */   

/** @defgroup XTX_ES_XT32H0XX_Private_Defines Private Defines
  * @{
  */ 
//#define DEBUG_SIMULATION

#if defined(DEBUG_SIMULATION)
#define ITM_PORT8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_PORT16(n)   (*((volatile unsigned short *)(0xE0000000+4*n)))
#define ITM_PORT32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          (0x01000000)
#endif /* DEBUG_SIMULATION */

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 6100000)
struct __FILE { int handle;};
#endif
FILE __stdout;
FILE __stdio;

//UART_HandleTypeDef huartlog;

#define UARTLOG  (UART2) //(UART1) //(UART3)//(UART2)

/**
  * @brief XTX_ES_XT32H0XX BSP Driver version number
  */
#define __XTX_ES_XT32H0XX_BSP_VERSION_MAIN   (0x01U) /*!< [31:24] main version */
#define __XTX_ES_XT32H0XX_BSP_VERSION_SUB1   (0x01U) /*!< [23:16] sub1 version */
#define __XTX_ES_XT32H0XX_BSP_VERSION_SUB2   (0x02U) /*!< [15:8]  sub2 version */
#define __XTX_ES_XT32H0XX_BSP_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */ 
#define __XTX_ES_XT32H0XX_BSP_VERSION        ((__XTX_ES_XT32H0XX_BSP_VERSION_MAIN << 24)\
                                             |(__XTX_ES_XT32H0XX_BSP_VERSION_SUB1 << 16)\
                                             |(__XTX_ES_XT32H0XX_BSP_VERSION_SUB2 << 8 )\
                                             |(__XTX_ES_XT32H0XX_BSP_VERSION_RC))

#if defined(_GUI_INTERFACE)
const uint8_t HWBoardVersionName[] = "XTX_ES_XT32H0XX";
const uint8_t PDTypeName[] = "MB1360A";
#endif /* _GUI_INTERFACE */

/**
  * @brief LINK SD Card
  */
#define SD_DUMMY_BYTE            0xFF    
#define SD_NO_RESPONSE_EXPECTED  0x80

/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_Private_Variables Private Variables
  * @{
  */ 
static const uint32_t LED_PAD[LEDn] = {LED1_PAD};
static const uint32_t LED_AF[LEDn] = {LED1_AF};

static GPIO_TypeDef*  LED_PORT[LEDn] = {LED1_GPIO_PORT};
static const uint32_t LED_PIN[LEDn] = {LED1_PIN};

static const uint32_t BUTTON_PAD[LEDn] = {USER_BUTTON_PAD};
static const uint32_t BUTTON_AF[LEDn] = {USER_BUTTON_AF};

static GPIO_TypeDef*  BUTTON_PORT[BUTTONn] = {USER_BUTTON_GPIO_PORT};
static const uint32_t BUTTON_PIN[BUTTONn] = {USER_BUTTON_PIN};
static const uint32_t  BUTTON_IRQn[BUTTONn] = {USER_BUTTON_IRQn };

/**
 * @brief BUS variables
 */
#ifdef HAL_I2C_MODULE_ENABLED
static I2C_HandleTypeDef hes_i2c;
#endif
#ifdef HAL_SPI_MODULE_ENABLED
static SPI_HandleTypeDef hes_spi1;
#endif

/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_Functions Private Functions
  * @{
  */ 
/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_Exported_Functions Exported Functions
  * @{
  */ 

/** @addtogroup XTX_ES_XT32H0XX_generic_functions
  * @{
  */
/**
  * @brief  This method returns the XTX_ES_XT32H0XX BSP Driver revision
  * @retval version : 0xXYZR (8bits for each decimal, R for RC)
  */
uint32_t BSP_GetVersion(void)
{
  return __XTX_ES_XT32H0XX_BSP_VERSION;
}
/**
  * @}
  */

/** @addtogroup XTX_ES_XT32H0XX_LED_Functions
  * @{
  */ 

/**
  * @brief  Configures LED GPIO.
  * @param  Led: Led to be configured. 
  *         This parameter can be one of the following values:
  * @arg LED1
  * @retval None
  */
void BSP_LED_Init(Led_TypeDef Led)
{
  GPIO_InitTypeDef  gpioinitstruct;
	PADI_InitTypeDef  padiinitstruct;
  
  /* Enable the GPIO_LED Clock */
  //LEDx_GPIO_CLK_ENABLE(Led);
	
	padiinitstruct.Pad = LED_PAD[Led];
	padiinitstruct.Alternate = LED_AF[Led];
	padiinitstruct.Pull = PADI_PULLNO;
	
	HAL_PADI_Init(PADI, &padiinitstruct);

  /* Configure the GPIO_LED pin */
  gpioinitstruct.Pin = LED_PIN[Led];
  gpioinitstruct.Mode = GPIO_MODE_OUTPUT_SW;
  
  HAL_GPIO_Init(LED_PORT[Led], &gpioinitstruct);
}

/**
  * @brief  DeInit LEDs.
  * @param  Led: LED to be de-init. 
  *   This parameter can be one of the following values:
  *     @arg  LED1
  * @note Led DeInit does not disable the GPIO clock nor disable the Mfx 
  * @retval None
  */
void BSP_LED_DeInit(Led_TypeDef Led)
{
  GPIO_InitTypeDef  gpio_init_structure;

  /* Make sure GPIO_LED clock is enable */
  LEDx_GPIO_CLK_ENABLE(Led);

  /* DeInit the GPIO_LED pin */
  gpio_init_structure.Pin = LED_PIN[Led];
  HAL_GPIO_DeInit(LED_PORT[Led], gpio_init_structure.Pin);
}

/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  * @retval None
  */
void BSP_LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET); 
}

/**
  * @brief  Turns selected LED Off.
  * @param  Led: Specifies the Led to be set off. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  * @retval None
  */
void BSP_LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET); 
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  * @retval None
  */
void BSP_LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}

/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_BUTTON_Functions BUTTON Functions
  * @{
  */ 

/**
  * @brief  Configures Button GPIO and EXTI Line.
  * @param  Button: Specifies the Button to be configured.
  *   This parameter should be: BUTTON_USER
  * @param  ButtonMode: Specifies Button mode.
  *   This parameter can be one of following parameters:   
  *     @arg BUTTON_MODE_GPIO: Button will be used as simple IO
  *     @arg BUTTON_MODE_EXTI: Button will be connected to EXTI line with interrupt
  *                            generation capability  
  * @retval None
  */
void BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode)
{
  GPIO_InitTypeDef gpioinitstruct;
	PADI_InitTypeDef  padiinitstruct;

  /* Enable the BUTTON Clock */
  //BUTTONx_GPIO_CLK_ENABLE(Button);

	padiinitstruct.Pad = BUTTON_PAD[Button];
	padiinitstruct.Alternate = BUTTON_AF[Button];
	padiinitstruct.Pull = PADI_PULLUP;
	
	HAL_PADI_Init(PADI, &padiinitstruct);
	
  gpioinitstruct.Pin = BUTTON_PIN[Button];

  if(ButtonMode == BUTTON_MODE_GPIO)
  {
    /* Configure Button pin as input */
    gpioinitstruct.Mode = GPIO_MODE_INPUT_SW;

    HAL_GPIO_Init(BUTTON_PORT[Button], &gpioinitstruct);
  }

  if(ButtonMode == BUTTON_MODE_EXTI)
  {
    /* Configure Button pin as input with External interrupt */
	gpioinitstruct.Mode = GPIO_MODE_IT_PL_SE_DE_SE;

    HAL_GPIO_Init(BUTTON_PORT[Button], &gpioinitstruct);

    /* Enable and set Button EXTI Interrupt to the lowest priority */
    HAL_NVIC_SetPriority((IRQn_Type)(BUTTON_IRQn[Button]), 0x03, 0x00);
    HAL_NVIC_EnableIRQ((IRQn_Type)(BUTTON_IRQn[Button]));
  }
}

/**
  * @brief  Push Button DeInit.
  * @param  Button: Button to be configured
  *   This parameter should be: BUTTON_USER
  * @note PB DeInit does not disable the GPIO clock
  * @retval None
  */
void BSP_PB_DeInit(Button_TypeDef Button)
{
  GPIO_InitTypeDef gpio_init_structure;

  gpio_init_structure.Pin = BUTTON_PIN[Button];
  HAL_NVIC_DisableIRQ((IRQn_Type)(BUTTON_IRQn[Button]));
  HAL_GPIO_DeInit(BUTTON_PORT[Button], gpio_init_structure.Pin);
}

/**
  * @brief  Returns the selected Button state.
  * @param  Button: Specifies the Button to be checked.
  *   This parameter should be: BUTTON_USER
  * @retval Button state.
  */
uint32_t BSP_PB_GetState(Button_TypeDef Button)
{
  return HAL_GPIO_ReadPin(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}
/**
  * @}
  */ 

/**
  * @}
  */

/** @defgroup XTX_ES_XT32H0XX_PMOD2_Functions  PMOD2 Functions
  * @{
  */   
/**
  * @brief  PMOD0 SPI
  * @retval None
  */
void BSP_PMOD2_SPI_Init(void)
{
	PADI_InitTypeDef sPadConfig = {0};

  sPadConfig.Pull = PADI_PULLUP;
  sPadConfig.Pad = PMOD2_SPI_MASTER_MOSI_PIN;
  sPadConfig.Alternate = PMOD2_SPI_MASTER_MOSI_PINCFG;
  HAL_PADI_Init(PADI, &sPadConfig);   //TXD
  sPadConfig.Pad = PMOD2_SPI_MASTER_MISO_PIN;
  sPadConfig.Alternate = PMOD2_SPI_MASTER_MISO_PINCFG;
  HAL_PADI_Init(PADI, &sPadConfig);   //RXD
	sPadConfig.Pad = PMOD2_SPI_SCK_PIN;
  sPadConfig.Alternate = PMOD2_SPI_SCK_PINCFG;
  HAL_PADI_Init(PADI, &sPadConfig);   //CLK
	sPadConfig.Pad = PMOD2_SPI_SS_PIN;
  sPadConfig.Alternate = PMOD2_SPI_SS_PINCFG;
  HAL_PADI_Init(PADI, &sPadConfig);   //SS	
	
	//GPIO
  sPadConfig.Pull = PADI_PULLNO;
  sPadConfig.Pad = PMOD2_6_PAD;
  sPadConfig.Alternate = PMOD2_6_AF;
  HAL_PADI_Init(PADI, &sPadConfig);   //GPIO
  sPadConfig.Pad = PMOD2_7_PAD;
  sPadConfig.Alternate = PMOD2_7_AF;
  HAL_PADI_Init(PADI, &sPadConfig);   //GPIO
  sPadConfig.Pad = PMOD2_8_PAD;
  sPadConfig.Alternate = PMOD2_8_AF;
  HAL_PADI_Init(PADI, &sPadConfig);   //GPIO
  sPadConfig.Pad = PMOD2_9_PAD;
  sPadConfig.Alternate = PMOD2_9_AF;
  HAL_PADI_Init(PADI, &sPadConfig);   //GPIO
}

/**
  * @brief  DeInit PMOD0 SPI.
  * @retval None
  */
void BSP_PMOD2_SPI_DeInit(void)
{
}

/**
  * @}
  */ 

/** @defgroup XT32H0XX_EVB_USB2_Functions  USB2 Functions
  * @{
  */
/**
  * @brief  USB2 UART
  * @retval None
  */
void BSP_USB2_UART_Init(void)
{
	PADI_InitTypeDef sPadConfig = {0};
  sPadConfig.Pull = PADI_PULLUP;
  sPadConfig.Pad = USB2_UART_TX_PIN;
  sPadConfig.Alternate = USB2_UART_TX_PINCFG;
  HAL_PADI_Init(PADI, &sPadConfig);   //TX
  sPadConfig.Pad = USB2_UART_RX_PIN;
  sPadConfig.Alternate = USB2_UART_RX_PINCFG;
  HAL_PADI_Init(PADI, &sPadConfig);   //RX
}

/**
  * @brief  DeInit USB2 UART.
  * @retval None
  */
void BSP_USB2_UART_DeInit(void)
{
}

/**
  * @}
  */ 

/** @defgroup XT32H0XX_EVB_PMOD1_Functions  PMOD1 Functions
  * @{
  */
/**
  * @brief  PMOD1 I2C
  * @retval None
  */
void BSP_PMOD1_I2C_Init(void)
{
	PADI_InitTypeDef sPadConfig = {0};

  sPadConfig.Pull = PADI_PULLUP;
  sPadConfig.Pad = PMOD1_I2C_SCK_PIN;
  sPadConfig.Alternate = PMOD1_I2C_SCK_PINCFG;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = PMOD1_I2C_SDA_PIN;
  sPadConfig.Alternate = PMOD1_I2C_SDA_PINCFG;
  HAL_PADI_Init(PADI, &sPadConfig);
	
	//GPIO
  sPadConfig.Pull = PADI_PULLNO;
  sPadConfig.Pad = PMOD1_6_PAD;
  sPadConfig.Alternate = PMOD1_6_AF;
  HAL_PADI_Init(PADI, &sPadConfig);   //GPIO
  sPadConfig.Pad = PMOD1_7_PAD;
  sPadConfig.Alternate = PMOD1_7_AF;
  HAL_PADI_Init(PADI, &sPadConfig);   //GPIO
  sPadConfig.Pad = PMOD1_8_PAD;
  sPadConfig.Alternate = PMOD1_8_AF;
  HAL_PADI_Init(PADI, &sPadConfig);   //GPIO
  sPadConfig.Pad = PMOD1_9_PAD;
  sPadConfig.Alternate = PMOD1_9_AF;
  HAL_PADI_Init(PADI, &sPadConfig);   //GPIO
}

/**
  * @brief  DeInit PMOD1 I2C.
  * @retval None
  */
void BSP_PMOD1_I2C_DeInit(void)
{
}
/**
  * @}
  */ 

/** @addtogroup XTX_ES_XT32H0XX_TouchKey_Functions  
  * @{
  */
/**
  * @brief  Touch Key
  * @retval None
  */
void BSP_TouchKey_Init(void)
{
	PADI_InitTypeDef sPadConfig = {0};

  sPadConfig.Pull = PADI_PULLNO;
    
	sPadConfig.Pad = PADI_IDX_IO44_CTSU_CAP;
  sPadConfig.Alternate = PADI_CFG_IO44_CTSU_CAP;
  HAL_PADI_Init(PADI, &sPadConfig);

	sPadConfig.Pad = TOUCH_KEY_PAD;
  sPadConfig.Alternate = TOUCH_KEY_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
}

/**
  * @brief  DeInit Touch Key
  * @retval None
  */
void BSP_TouchKey_DeInit(void)
{
}
/**
  * @}
  */ 

/** @addtogroup XTX_ES_XT32H0XX_DigitDisplay_Functions  
  * @{
  */
/**
  * @brief  Digit Display
  * @retval None
  */
void BSP_DigitDisplay_Init(void)
{
	PADI_InitTypeDef sPadConfig = {0};
	
  sPadConfig.Pull = PADI_PULLNO;

  sPadConfig.Pad = LED_A_PAD;
  sPadConfig.Alternate = LED_A_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = LED_B_PAD;
  sPadConfig.Alternate = LED_B_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = LED_C_PAD;
  sPadConfig.Alternate = LED_C_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = LED_D_PAD;
  sPadConfig.Alternate = LED_D_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = LED_E_PAD;
  sPadConfig.Alternate = LED_E_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = LED_F_PAD;
  sPadConfig.Alternate = LED_F_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = LED_G_PAD;
  sPadConfig.Alternate = LED_G_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = LED_H_PAD;
  sPadConfig.Alternate = LED_H_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
  sPadConfig.Pad = LED_I_PAD;
  sPadConfig.Alternate = LED_I_AF;
  HAL_PADI_Init(PADI, &sPadConfig);
}

/**
  * @brief  DeInit Digit Display
  * @retval None
  */
void BSP_DigitDisplay_DeInit(void)
{
}
/**
  * @}
  */ 

/** @defgroup XT32H0XX_EVB_UARTLOG_Functions  UART log Functions
  * @{
  */
 
/**
  * @brief  Debug log init
  * @retval None
  */
void BSP_LogInit(void)
{
  uint32_t tmpreg = 0;
  uint32_t usartdiv = 1;
  
  PADI_InitTypeDef sPadConfig = {0};

  /* USER CODE BEGIN USART1_Init 0 */
  sPadConfig.Pull = PADI_PULLUP;
  if (UARTLOG == UART1)
  {
      sPadConfig.Pad =  PADI_IDX_IO5_UART1_RX; 
      sPadConfig.Alternate = PADI_CFG_IO5_UART1_RX; 
      HAL_PADI_Init(PADI, &sPadConfig);   //RX
      sPadConfig.Pad = PADI_IDX_IO1_UART1_TX; 
      sPadConfig.Alternate = PADI_CFG_IO1_UART1_TX; 
      HAL_PADI_Init(PADI, &sPadConfig);   //TX
  }
  if (UARTLOG == UART2)
  {
//  sPadConfig.Pad = PADI_IDX_IO14_UART2_RX; /* PADI_IDX_IO19_UART2_RX; */
//  sPadConfig.Alternate = PADI_CFG_IO14_UART2_RX; /* PADI_CFG_IO19_UART2_RX; */
//  HAL_PADI_Init(PADI, &sPadConfig);   //RX
//  sPadConfig.Pad = PADI_IDX_IO13_UART2_TX; /* PADI_IDX_IO18_UART2_TX; */
//  sPadConfig.Alternate = PADI_CFG_IO13_UART2_TX; /* PADI_CFG_IO18_UART2_TX; */
//  HAL_PADI_Init(PADI, &sPadConfig);   //TX

  sPadConfig.Pad =  PADI_IDX_IO19_UART2_RX; 
  sPadConfig.Alternate = PADI_CFG_IO19_UART2_RX; 
  HAL_PADI_Init(PADI, &sPadConfig);   //RX
  sPadConfig.Pad = PADI_IDX_IO18_UART2_TX; 
  sPadConfig.Alternate = PADI_CFG_IO18_UART2_TX; 
  HAL_PADI_Init(PADI, &sPadConfig);   //TX

//      sPadConfig.Pad =  PADI_IDX_IO38_UART2_RX; 
//      sPadConfig.Alternate = PADI_CFG_IO38_UART2_RX; 
//      HAL_PADI_Init(PADI, &sPadConfig);   //RX
//      sPadConfig.Pad = PADI_IDX_IO39_UART2_TX; 
//      sPadConfig.Alternate = PADI_CFG_IO39_UART2_TX; 
//      HAL_PADI_Init(PADI, &sPadConfig);   //TX
  }
  if (UARTLOG == UART3)
  {
      sPadConfig.Pad =  PADI_IDX_IO36_UART3_RX; 
      sPadConfig.Alternate = PADI_CFG_IO36_UART3_RX; 
      HAL_PADI_Init(PADI, &sPadConfig);   //RX
      sPadConfig.Pad = PADI_IDX_IO35_UART3_TX; 
      sPadConfig.Alternate = PADI_CFG_IO35_UART3_TX; 
      HAL_PADI_Init(PADI, &sPadConfig);   //TX
  }
  if (UARTLOG == UART4)
  {
      sPadConfig.Pad =  PADI_IDX_IO57_UART4_RX; 
      sPadConfig.Alternate = PADI_CFG_IO57_UART4_RX; 
      HAL_PADI_Init(PADI, &sPadConfig);   //RX
      sPadConfig.Pad = PADI_IDX_IO58_UART4_TX; 
      sPadConfig.Alternate = PADI_CFG_IO58_UART4_TX; 
      HAL_PADI_Init(PADI, &sPadConfig);   //TX
  }
  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
//  huartlog.Instance = UART2;
//  huartlog.Init.BaudRate = 115200;
//  huartlog.Init.WordLength = UART_WORDLENGTH_8;
//  huartlog.Init.StopBits = UART_STOPBITS_1;
//  huartlog.Init.Parity = UART_PARITY_NONE;
//  huartlog.Init.HwFlowCtl = UART_HWCONTROL_NONE;

  __HAL_RCC_BR_CONFIG(RCC_BRCLKSOURCE_HSE);
  __HAL_RCC_SET_BR_CLK_DIV(1);    

  tmpreg = (uint32_t)(UART_WORDLENGTH_8 | UART_PARITY_NONE | UART_STOPBITS_1);
  MODIFY_REG(UARTLOG->LCR, UART_LCR_DLS | UART_LCR_STOP | UART_LCR_PEN | UART_LCR_EPS | UART_MCR_LB, tmpreg);

  /*-------------------------- UART MCR Configuration -----------------------*/
  MODIFY_REG(UARTLOG->MCR, UART_MCR_AFCE|UART_MCR_RTS, UART_HWCONTROL_NONE);

  usartdiv = (uint32_t)26;   //115200 26@48M  
  SET_BIT(UARTLOG->LCR, UART_LCR_DLAB);
  if ((usartdiv > 0xFF))
  {
     MODIFY_REG(UARTLOG->DLH_IER, UART_DLH_IER_DLH, ((usartdiv >> 8) & 0xFF));
  }
  MODIFY_REG(UARTLOG->RBR_THR_DLL, UART_RBR_THR_DLL_DLL, (usartdiv & 0xFF));
  CLEAR_BIT(UARTLOG->LCR, UART_LCR_DLAB);

//  if (HAL_UART_Init(&huartlog) != HAL_OK)
//  {
    //Error_Handler();
 // }
//  if (HAL_UART_SetTxFifoThreshold(&huartlog, UART_TXFIFO_THRESHOLD_1_2) != HAL_OK)
//  {
//    //Error_Handler();
//  }
//  if (HAL_UART_SetRxFifoThreshold(&huartlog, UART_RXFIFO_THRESHOLD_1_4) != HAL_OK)
//  {
//    //Error_Handler();
//  }
//  if (HAL_UART_EnableFifoMode(&huartlog) != HAL_OK)
//  {
//    //Error_Handler();
//  }
  UARTLOG->IIR_FCR = (uint32_t)(UART_FIFOMODE_ENABLE|UART_TXFIFO_THRESHOLD_1_2|UART_RXFIFO_THRESHOLD_1_4);

  /* USER CODE BEGIN USART1_Init 2 */
  SET_BIT(UARTLOG->DLH_IER, UART_DLH_IER_PTIME);
  /* USER CODE END USART1_Init 2 */
}
/**
  * @brief  fputc
  * @retval None
  */
int fputc(int ch, FILE *f)
{
#if 0 //defined(DEBUG_SIMULATION)  
	if(DEMCR & TRCENA)
	{
		while(ITM_PORT32(0) == 0);
		ITM_PORT8(0) = ch;
	}
#else
  //HAL_UART_Transmit(&huartlog, (uint8_t *)&ch, 1, 0xFFFF);
	
	while((READ_BIT(UARTLOG->LSR, UART_LS_TEMT)) == 0)
	{
		__NOP();
		__NOP();
		__NOP();
		__NOP();
	}
	UARTLOG->RBR_THR_DLL = (uint8_t)ch;
	
#endif /* DEBUG_SIMULATION */	

	return ch;
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

/**
  * @}
  */ 
    
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
