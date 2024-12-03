/**
  ******************************************************************************
  * @file    i2cdevice_tcs34725.c
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
#include "i2cdevice_tcs34725.h"
/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup I2C_DEVICE_TCS34725
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
 
/** @addtogroup I2C_Device_Tcs34725_Private_Variables
  * @{
  */
/* Private variables ---------------------------------------------------------*/
uint8_t u1Integrationtiming = TCS34725_INTEGRATEIONTM_2_4MS;
/**
  * @}
  */


/** @addtogroup TCS34725_External_Variables
  * @{
  */
/* External variables --------------------------------------------------------*/
extern I2C_HandleTypeDef hI2c1;
/**
  * @}
  */

/** @addtogroup I2C_Task_Private_Functions
  * @{
  */
/* Private function prototypes -----------------------------------------------*/
static void XT_I2cTcs34725_Write8(uint8_t reg, uint32_t value);
static uint16_t XT_I2cTcs34725_Read8(uint8_t reg);
static uint16_t XT_I2cTcs34725_Read16(uint8_t reg);

/* Private user code ---------------------------------------------------------*/
static void XT_I2cTcs34725_Write8(uint8_t reg, uint32_t value)
{
    uint8_t txbuff[8] = {0};
    uint8_t length = 0;
    
    txbuff[length++] = TCS34725_COMMAND_BIT |reg;
    txbuff[length++] = value & 0xFF;
	
    if(HAL_I2C_Master_Transmit(&hI2c1,(uint16_t)(DEVICE_TCS34725_ADDRESS),txbuff,length,5000) != HAL_OK)
    {
        if (HAL_I2C_GetError(&hI2c1) != HAL_I2C_ERROR_NONE)
        {
            Error_Handle();
        }
    }
    while (HAL_I2C_GetState(&hI2c1) != HAL_I2C_STATE_READY);	
    return;
}

static uint16_t XT_I2cTcs34725_Read8(uint8_t reg)
{
    uint8_t rxbuff[8] = {0};
    uint8_t txbuff = TCS34725_COMMAND_BIT |reg;
	
    HAL_I2C_Master_Transmit(&hI2c1,(uint16_t)(DEVICE_TCS34725_ADDRESS),&txbuff,1,5000);
		
    if(HAL_I2C_Master_Receive(&hI2c1,(uint16_t)(DEVICE_TCS34725_ADDRESS),(uint8_t*)rxbuff,1,5000) != HAL_OK)
    {
        if (HAL_I2C_GetError(&hI2c1) != HAL_I2C_ERROR_NONE)
        {
            Error_Handle();
        }
    }
    while (HAL_I2C_GetState(&hI2c1) != HAL_I2C_STATE_READY);		
    return (rxbuff[0]);
}

static uint16_t XT_I2cTcs34725_Read16(uint8_t reg)
{
    uint8_t rxbuff[8] = {0};
    uint8_t txbuff = TCS34725_COMMAND_BIT |reg;
	
    HAL_I2C_Master_Transmit(&hI2c1,(uint16_t)(DEVICE_TCS34725_ADDRESS),&txbuff,1,5000);
		
    if(HAL_I2C_Master_Receive(&hI2c1,(uint16_t)(DEVICE_TCS34725_ADDRESS),(uint8_t*)rxbuff,2,5000) != HAL_OK)
    {
        if (HAL_I2C_GetError(&hI2c1) != HAL_I2C_ERROR_NONE)
        {
            Error_Handle();
        }
    }	
		
    while (HAL_I2C_GetState(&hI2c1) != HAL_I2C_STATE_READY);	
    return ((rxbuff[0]<<8) |rxbuff[0]);
}

/**
  * @}
  */

/** @addtogroup TCS34725_Task_Exported_Functions
  * @{
  */
/*** @brief  Enables the device TCS34725.  */
void XT_I2cTcs34725_enable(void)
{
    XT_I2cTcs34725_Write8(TCS34725_REG_ENABLE, TCS34725_ENABLE_PON);
    HAL_Delay(3);
    XT_I2cTcs34725_Write8(TCS34725_REG_ENABLE, TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN);  
}


/***    Disables the device (putting it in lower power sleep mode)*/
void XT_I2cTcs34725_disable(void)
{
     /* Turn the device off to save power */
     uint8_t regval = 0;
     regval = XT_I2cTcs34725_Read8(TCS34725_REG_ENABLE);
     XT_I2cTcs34725_Write8(TCS34725_REG_ENABLE, regval & ~(TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN));
}

/**
    Initializes I2C and configures the sensor (call this function before
    doing anything else)
*/
uint8_t XT_I2cTcs34725_Enable(void) 
{
    
    /* Make sure we're actually connected */
    uint8_t id = XT_I2cTcs34725_Read8(TCS34725_REG_ID);
    
    if (id != SENSORID_TCS34725)
    {
        return FALSE;
    }
    
    /* Set default integration time and gain */
    XT_I2cTcs34725_setATime(u1Integrationtiming);
    XT_I2cTcs34725_setGain(TCS34725_GAIN_1X);
    
    /* Note: by default, the device is in power down mode on bootup */
    XT_I2cTcs34725_enable();
    
    return TRUE;
}

/**
    Sets the integration time for the TC34725
*/
void XT_I2cTcs34725_setATime(uint8_t itime)
{
    /* Update the timing register */
    XT_I2cTcs34725_Write8(TCS34725_REG_ATIME, itime);
    u1Integrationtiming = itime;
}


/**
    Adjusts the gain on the TCS34725 (adjusts the sensitivity to light)
*/

void XT_I2cTcs34725_setGain(uint8_t gain)
{
    /* Update the timing register */
    XT_I2cTcs34725_Write8(TCS34725_REG_CONTROL, gain);
}


/**
    @brief  Reads the raw red, green, blue and clear channel values
*/
void XT_I2cTcs34725_getRawData (TCS34725_RGBdataDef* rgbdata)
{
    
    rgbdata->u2Cval = XT_I2cTcs34725_Read16(TCS34725_REG_CDATAL);
    rgbdata->u2Rval = XT_I2cTcs34725_Read16(TCS34725_REG_RDATAL);
    rgbdata->u2Gval = XT_I2cTcs34725_Read16(TCS34725_REG_GDATAL);
    rgbdata->u2Bval = XT_I2cTcs34725_Read16(TCS34725_REG_BDATAL);
    
    /* Set a delay for the integration time */
    switch (u1Integrationtiming)
    {
        case TCS34725_INTEGRATEIONTM_2_4MS:
          HAL_Delay(3);
          break;
        case TCS34725_INTEGRATEIONTM_24MS:
          HAL_Delay(24);
          break;
        case TCS34725_INTEGRATEIONTM_50MS:
          HAL_Delay(50);
          break;
        case TCS34725_INTEGRATEIONTM_101MS:
          HAL_Delay(101);
          break;
        case TCS34725_INTEGRATEIONTM_154MS:
          HAL_Delay(154);
          break;
        case TCS34725_INTEGRATEIONTM_700MS:
          HAL_Delay(700);
          break;
    }
    return;
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
