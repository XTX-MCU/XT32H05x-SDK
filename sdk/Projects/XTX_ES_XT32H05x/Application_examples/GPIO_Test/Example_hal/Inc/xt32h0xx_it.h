/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    ../Inc/xt32h0xx_it.h
  * @author  Software Team
  * @brief   This file contains the headers of the interrupt handlers.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32G0xx_IT_H
#define __XT32G0xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup App_Gpio
 * @{
 */

/** @addtogroup Gpio_Blink
 * @{
 */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
/** @addtogroup App_Exported_Functions
  * @{
  */
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
/* USER CODE BEGIN EFP */
void ICTL_IRQHandler(void );
/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __XT32G0xx_IT_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
