/**
  ******************************************************************************
  * @file    xt32h0xx_hal_msp.c
  * @author  Software Team
  * @brief   This file provides code for the MSP Initialization 
  *          and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2ctask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup MSP
  * @{
  */
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/* External variables --------------------------------------------------------*/
/** @addtogroup MSP_External_Variables
  * @{
  */
extern I2C_HandleTypeDef hI2c1;
/**
  * @}
  */
	
/* External functions --------------------------------------------------------*/
/** @addtogroup MSP_Exported_Functions
  * @{
  */
/**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
}

/**
* @brief I2C MSP Initialization
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c)
{
    if(hi2c->Instance==I2C1)
    {
        /**mapping IO  I2C1 GPIO Configuration ***
        IO13/28/38/49/54/     ------> I2C1 SCK
        IO14/29/39/50/55     ------> I2C1 SDA			
        */ 		 
        XT_IO_Option_Assigned(EVB_I2C1_SCK_IO_IDX,	EVB_I2C1_SCK_IO_CFG, PADI_PULLUP);
        XT_IO_Option_Assigned(EVB_I2C1_SDA_IO_IDX,	EVB_I2C1_SDA_IO_CFG, PADI_PULLUP);	
    }

}

/**
* @brief I2C MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2c: I2C handle pointer
* @retval None
*/
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c)
{
	if(hi2c->Instance==I2C1)
	{
		/* USER CODE BEGIN I2C1_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_I2C1_CLK_DISABLE()
		/**mapping pad  I2C GPIO Configuration ***
		IO38     ------> I2C1 SCK
		IO39     ------> I2C1 SDA
		*/
		HAL_PADI_DeInit(PADI,EVB_I2C1_SCK_IO_IDX);
		HAL_PADI_DeInit(PADI,EVB_I2C1_SDA_IO_IDX);		
		/* USER CODE ENDPADI, I2C1_MspDeInit 0 */  
	}
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
