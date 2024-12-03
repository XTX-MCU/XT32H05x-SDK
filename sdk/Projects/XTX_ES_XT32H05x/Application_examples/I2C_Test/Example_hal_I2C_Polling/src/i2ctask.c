/**
  ******************************************************************************
  * @file    i2ctask.c
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
#include "i2ctask.h"
#include "i2cdevice_tcs34725.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup I2C_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/** @addtogroup I2C_Task_Private_Macro
  * @{
  */
#define XT32HX_I2C_OWNER_ADDR						 (0x5C)

/**
  * @}
  */
	
/* Private variables ---------------------------------------------------------*/	
/** @addtogroup I2C_Task_Private_Variables
  * @{
  */
I2C_HandleTypeDef hI2c1;


/**
  * @}
  */

/** @addtogroup I2C_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void XT_I2C1_Init(void );

/* Private user code ---------------------------------------------------------*/

/**
 * @brief  I2C1 Initialization Function
 */
void XT_I2C1_Init(void)
{
    hI2c1.Instance = I2C1;
    hI2c1.Init.SlaveAddress   = DEVICE_TCS34725_ADDRESS;   /*used for master mode*/
    hI2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hI2c1.Init.OwnAddress     = XT32HX_I2C_OWNER_ADDR;         /*used for slaver mode*/
    hI2c1.Init.Speed          = I2C_SPEED_STANDARD;
    hI2c1.Init.Baudrate       = 100000; 
    hI2c1.Mode                = HAL_I2C_MODE_MASTER;    
    if (HAL_I2C_Init(&hI2c1) != HAL_OK)
    {
      /* Error_Handle */
    }
}


/**
  * @}
  */

/** @addtogroup I2C_Task_Exported_Functions
  * @{
  */
/**
  * @brief  This function is executed.
  */
void XT_I2c_Init(void)
{
  XT_I2C1_Init( );
	
	
}

/**
  * @brief  This function is executed.
  */
void XT_I2c_Task(void)
{
  /* USER CODE */
    TCS34725_RGBdataDef sRGBda;
    uint8_t deviceenable = FALSE;
    deviceenable = XT_I2cTcs34725_Enable();    
		
    while(deviceenable)
    {
        XT_I2cTcs34725_getRawData(&sRGBda);	
        HAL_Delay(500); //ms
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
