/**
  ******************************************************************************
  * @file    i2cdevice_tcs34725.h
  * @author  Software Team
  * @brief   Header for i2ctask.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __I2CDEVICE_TCS34725_H
#define __I2CDEVICE_TCS34725_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup I2C_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/


/** @addtogroup TCS34725_External_Types
  * @{
  */
/* Exported types ------------------------------------------------------------*/	
/** @defgroup I2C_Exported_Types I2C Exported Types
  * @{
  */

/** @defgroup I2C_Configuration_Structure_definition I2C Configuration Structure definition
  * @brief  I2C Configuration Structure definition
  * @{
  */
typedef struct _TCS34725_RGBdata
{
    uint16_t u2Rval;
    uint16_t u2Gval; 
    uint16_t u2Bval; 
    uint16_t u2Cval;
} TCS34725_RGBdataDef;

/**
  * @}
  */

/*TCS34725_REG_ATIME The RGBC timing register controls the internal integration time*/
typedef enum
{
  TCS34725_INTEGRATEIONTM_2_4MS          = 0xFF,   /**<  2.4ms - 1 cycle    - Max Count: 1024  */
  TCS34725_INTEGRATEIONTM_24MS           = 0xF6,   /**<  24ms  - 10 cycles  - Max Count: 10240 */
  TCS34725_INTEGRATEIONTM_50MS           = 0xEB,   /**<  50ms  - 20 cycles  - Max Count: 20480 */
  TCS34725_INTEGRATEIONTM_101MS          = 0xD5,   /**<  101ms - 42 cycles  - Max Count: 43008 */
  TCS34725_INTEGRATEIONTM_154MS          = 0xC0,   /**<  154ms - 64 cycles  - Max Count: 65535 */
  TCS34725_INTEGRATEIONTM_700MS          = 0x00    /**<  700ms - 256 cycles - Max Count: 65535 */
}TCS34725IntegrationTiming_t;


/*TCS34725_CONTROL*/
typedef enum
{
  TCS34725_GAIN_1X                = 0x00,   /**<  No gain  */
  TCS34725_GAIN_4X                = 0x01,   /**<  2x gain  */
  TCS34725_GAIN_16X               = 0x02,   /**<  16x gain */
  TCS34725_GAIN_60X               = 0x03    /**<  60x gain */
}TCS4725Gain_t;
/**
  * @}
  */

/** @addtogroup TCS34725_External_Constants
  * @{
  */
/* Exported constants --------------------------------------------------------*/
#define DEVICE_TCS34725_ADDRESS       (0x29)  

#define TCS34725_COMMAND_BIT          (0x80)    /* Specifies register address */   

#define TCS34725_REG_ENABLE           (0x00)    /*Enables states and interrupts */
#define TCS34725_REG_ATIME            (0x01)    /* RGBC time /Integration time */
#define TCS34725_REG_WTIME            (0x03)    /* Wait time (if TCS34725_ENABLE_WEN is asserted) */
#define TCS34725_REG_AILTL            (0x04)    /* Clear channel lower interrupt threshold */
#define TCS34725_REG_AILTH            (0x05)
#define TCS34725_REG_AIHTL            (0x06)    /* Clear channel upper interrupt threshold */
#define TCS34725_REG_AIHTH            (0x07)
#define TCS34725_REG_PERS             (0x0C)    /* Interrupt Persistence register - basic SW filtering mechanism for interrupts */
#define TCS34725_REG_CONFIG           (0x0D)
#define TCS34725_REG_CONTROL          (0x0F)    /* Set the gain level for the sensor */
#define TCS34725_REG_ID               (0x12)    /* 0x44 = TCS34721/TCS34725, 0x4D = TCS34723/TCS34727 */
#define TCS34725_REG_STATUS           (0x13)
#define TCS34725_REG_CDATAL           (0x14)    /* Clear channel data */
#define TCS34725_REG_CDATAH           (0x15)
#define TCS34725_REG_RDATAL           (0x16)    /* Red channel data */
#define TCS34725_REG_RDATAH           (0x17)
#define TCS34725_REG_GDATAL           (0x18)    /* Green channel data */
#define TCS34725_REG_GDATAH           (0x19)
#define TCS34725_REG_BDATAL           (0x1A)    /* Blue channel data */
#define TCS34725_REG_BDATAH           (0x1B)

/*REG_ID value*/
#define SENSORID_TCS34725             (0x44)
#define SENSORID_TCS34727             (0x4D)

/*REG_ENABLE value*/
#define TCS34725_ENABLE_PON           (0x01)    /* Power on - Writing 1 activates the internal oscillator, 0 disables it */
#define TCS34725_ENABLE_AEN           (0x02)    /* RGBC Enable - Writing 1 actives the ADC, 0 disables it */
#define TCS34725_ENABLE_WEN           (0x08)    /* Wait enable - Writing 1 activates the wait timer */
#define TCS34725_ENABLE_AIEN          (0x10)    /* RGBC Interrupt Enable */
																	    
/*TCS34725_REG_WTIME value*/          
#define TCS34725_WTIME_2_4MS          (0xFF)    /* WLONG0 = 2.4ms   WLONG1 = 0.029s */
#define TCS34725_WTIME_204MS          (0xAB)    /* WLONG0 = 204ms   WLONG1 = 2.45s  */
#define TCS34725_WTIME_614MS          (0x00)    /* WLONG0 = 614ms   WLONG1 = 7.4s   */
																	    
/*TCS34725_REG_CONFIG value*/         
#define TCS34725_CONFIG_WLONG         (0x02)    /* Choose between short and long (12x) wait times via TCS34725_WTIME */
																	    
/*TCS34725_REG_PERS value*/           
#define TCS34725_PERS_NONE            (0b0000)  /* Every RGBC cycle generates an interrupt                                */
#define TCS34725_PERS_1_CYCLE         (0b0001)  /* 1 clean channel value outside threshold range generates an interrupt   */
#define TCS34725_PERS_2_CYCLE         (0b0010)  /* 2 clean channel values outside threshold range generates an interrupt  */
#define TCS34725_PERS_3_CYCLE         (0b0011)  /* 3 clean channel values outside threshold range generates an interrupt  */
#define TCS34725_PERS_5_CYCLE         (0b0100)  /* 5 clean channel values outside threshold range generates an interrupt  */
#define TCS34725_PERS_10_CYCLE        (0b0101)  /* 10 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_15_CYCLE        (0b0110)  /* 15 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_20_CYCLE        (0b0111)  /* 20 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_25_CYCLE        (0b1000)  /* 25 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_30_CYCLE        (0b1001)  /* 30 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_35_CYCLE        (0b1010)  /* 35 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_40_CYCLE        (0b1011)  /* 40 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_45_CYCLE        (0b1100)  /* 45 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_50_CYCLE        (0b1101)  /* 50 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_55_CYCLE        (0b1110)  /* 55 clean channel values outside threshold range generates an interrupt */
#define TCS34725_PERS_60_CYCLE        (0b1111)  /* 60 clean channel values outside threshold range generates an interrupt */
																	    
/*TCS34725_REG_STATUS value*/         
#define TCS34725_STATUS_AINT          (0x10)    /* RGBC Clean channel interrupt */
#define TCS34725_STATUS_AVALID        (0x01)    /* Indicates that the RGBC channels have completed an integration cycle */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @addtogroup TCS34725_Exported_Functions
  * @{
  */
/* Exported functions --------------------------------------------------------*/
extern uint8_t XT_I2cTcs34725_Enable(void);
extern void XT_I2cTcs34725_setATime(uint8_t itime);
extern void XT_I2cTcs34725_setGain(uint8_t gain);
extern void XT_I2cTcs34725_getRawData (TCS34725_RGBdataDef* rgbdata);

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

#ifdef __cplusplus
}
#endif

#endif /* __I2CTASK_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
