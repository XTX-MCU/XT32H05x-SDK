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
uint8_t u1I2c_cbState = CB_I2C_IDLE;
 

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
  * @brief  This function is waiting the i2c state collback completed.
  */
void XT_I2c_Checksta(I2CTASK_CBSTA esta)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    while(u1I2c_cbState!=esta);	
    u1I2c_cbState = CB_I2C_IDLE;	
    /* USER CODE END Error_Handler_Debug */
}


/**
  * @brief  Master Tx Transfer completed callback.
  * @param  I2cHandle Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @retval None
  */
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *I2cHandle)
{
    if(I2cHandle->Instance == I2C1)
        u1I2c_cbState = CB_I2C1_TXFNSH;
    else if(I2cHandle->Instance == I2C2)
        u1I2c_cbState = CB_I2C2_TXFNSH;	
}

/**
  * @brief  Master Rx Transfer completed callback.
  * @param  I2cHandle Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @retval None
  */
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *I2cHandle)
{
    if(I2cHandle->Instance == I2C1)
        u1I2c_cbState = CB_I2C1_RXFNSH;
    else if(I2cHandle->Instance == I2C2)
        u1I2c_cbState = CB_I2C2_RXFNSH;		
}

 
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *I2cHandle)
{
    /** Error_Handle() function is called when error occurs.
    * 1- When Slave doesn't acknowledge its address, Master restarts communication.
    * 2- When Master doesn't acknowledge the last data transferred, Slave doesn't care in this example.
    */
    if (HAL_I2C_GetError(I2cHandle) != HAL_I2C_ERROR_NONE)
    {
        Error_Handle();
    }
    u1I2c_cbState = CB_I2C_ERROR;
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
