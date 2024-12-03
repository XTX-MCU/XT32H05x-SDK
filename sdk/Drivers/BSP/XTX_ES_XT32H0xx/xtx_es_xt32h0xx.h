/**
  ******************************************************************************
  * @file    xtx_es_xt32h0xx.h
  * @author  Software Team
  * @brief   Header for xtx_es_xt32h0xx.c
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XTX_ES_XT32H0XX_H
#define XTX_ES_XT32H0XX_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup BSP
  * @{
  */

/** @defgroup XTX_ES_XT32H0XX XTX_ES_XT32H0XX
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"
#include "xt32h0xx_ll_system.h"

/** @defgroup XTX_ES_XT32H0XX_Exported_Types Exported Types
  * @{
  */ 
typedef enum 
{
  LED1      = 0,
  LED_RED = LED1
} Led_TypeDef;

typedef enum 
{  
  BUTTON_USER = 0,
  /* Alias */
  BUTTON_KEY  = BUTTON_USER
} Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef; 

typedef enum 
{  
  SPIx_MASTER    = 0,
  SPIx_SLAVE     = 1
} SPIx_ModeDef;

/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_Exported_Constants Exported Constants
  * @{
  */ 

/** 
* @brief	Define for XTX_ES_XT32H0XX board  
  */ 
#if !defined (USE_XTX_ES_XT32H0XX)
 #define USE_XTX_ES_XT32H0XX
#endif

/** @defgroup XTX_ES_XT32H0XX_LED LED Constants
  * @{
  */
#define LEDn                               1

#define LED1_PAD                           PADI_IDX_IO2_PB31
#define LED1_AF                            PADI_CFG_IO2_PB31

#define LED1_PIN                           GPIO_PIN_31
#define LED1_GPIO_PORT                     GPIOB
#define LED1_GPIO_CLK_ENABLE()           __HAL_RCC_GPIO_CLK_ENABLE()  
#define LED1_GPIO_CLK_DISABLE()          __HAL_RCC_GPIO_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)   do { if((__INDEX__) == 0) LED1_GPIO_CLK_ENABLE();} while(0)
#define LEDx_GPIO_CLK_DISABLE(__INDEX__)  do { if((__INDEX__) == 0) LED1_GPIO_CLK_DISABLE();} while(0)

/**
  * @}
  */ 
  
/** @defgroup XTX_ES_XT32H0XX_BUTTON BUTTON Constants
  * @{
  */  
#define BUTTONn                            1

/**
  * @brief User push-button
  */
#define USER_BUTTON_PAD                       PADI_IDX_IO60_PA6
#define USER_BUTTON_AF                        PADI_CFG_IO60_PA6

#define USER_BUTTON_PIN                       GPIO_PIN_6
#define USER_BUTTON_GPIO_PORT                 GPIOA
#define USER_BUTTON_GPIO_CLK_ENABLE()         __HAL_RCC_GPIO_CLK_ENABLE()   
#define USER_BUTTON_GPIO_CLK_DISABLE()        __HAL_RCC_GPIO_CLK_DISABLE()  
#define USER_BUTTON_INT                       GPIO_PIN_6
#define USER_BUTTON_IRQn                      ICTL_IRQn

/* Aliases */
#define KEY_BUTTON_PIN                        USER_BUTTON_PIN
#define KEY_BUTTON_GPIO_PORT                  USER_BUTTON_GPIO_PORT
#define KEY_BUTTON_GPIO_CLK_ENABLE()          USER_BUTTON_GPIO_CLK_ENABLE()
#define KEY_BUTTON_GPIO_CLK_DISABLE()         USER_BUTTON_GPIO_CLK_DISABLE()
#define KEY_BUTTON_INT                        USER_BUTTON_INT
#define KEY_BUTTON_IRQn                       USER_BUTTON_IRQn

#define BUTTONx_GPIO_CLK_ENABLE(__INDEX__)    do { if((__INDEX__) == 0) USER_BUTTON_GPIO_CLK_ENABLE();} while(0)
#define BUTTONx_GPIO_CLK_DISABLE(__INDEX__)   do { if((__INDEX__) == 0) ? USER_BUTTON_GPIO_CLK_DISABLE();} while(0)
/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_BUS BUS Constants
  * @{
  */ 


/*##################### I2C ###################################*/
/**
  * @brief  I2C Interface pins (PMOD1 6A)
  *         
  */
#define PMOD1_I2C                                 I2C1
#define PMOD1_I2C_CLK_ENABLE()                    __HAL_RCC_I2C1_CLK_ENABLE()
#define PMOD1_I2C_CLK_DISABLE()                   __HAL_RCC_I2C1_CLK_DISABLE()

#define PMOD1_I2C_CLK_SETSOURCE(__SOURCE__)	      __HAL_RCC_I2C_CONFIG(__SOURCE__)
#define PMOD1_I2C_CLK_SETDIVIDER(__DIVIDER__)	    __HAL_RCC_SET_I2C1_CLK_DIV(__DIVIDER__)

#define PMOD1_I2C_SCK_PIN                         PADI_IDX_IO38_I2C1_SCK
#define PMOD1_I2C_SCK_PINCFG                      PADI_CFG_IO38_I2C1_SCK
#define PMOD1_I2C_SDA_PIN                         PADI_IDX_IO39_I2C1_SDA
#define PMOD1_I2C_SDA_PINCFG                      PADI_CFG_IO39_I2C1_SDA

/*###################### SPI ###################################*/
/**
  * @brief  SPI Interface pins (PMOD2 2A)
  *         
	*/
#define PMOD2_SPI_MASTER                          SPI1M
#define PMOD2_SPI_SLAVE                           SPI1S
#define PMOD2_SPI_CLK_ENABLE()                  __HAL_RCC_SPI1_CLK_ENABLE()

#define PMOD2_SPI_CLK_SETSOURCE(__SOURCE__)	   __HAL_RCC_BR_CONFIG(__SOURCE__)
#define PMOD2_SPI_CLK_SETDIVIDER(__DIVIDER__)	 __HAL_RCC_SET_BR_CLK_DIV(__DIVIDER__)

#define PMOD2_SPI_SCK_PIN                         PADI_IDX_IO54_SPI1_SCK
#define PMOD2_SPI_SCK_PINCFG                      PADI_CFG_IO54_SPI1_SCK
#define PMOD2_SPI_MASTER_MISO_PIN                 PADI_IDX_IO55_SPI1_RXD
#define PMOD2_SPI_MASTER_MISO_PINCFG              PADI_CFG_IO55_SPI1_RXD
#define PMOD2_SPI_MASTER_MOSI_PIN                 PADI_IDX_IO56_SPI1_TXD
#define PMOD2_SPI_MASTER_MOSI_PINCFG              PADI_CFG_IO56_SPI1_TXD
#define PMOD2_SPI_SS_PIN                          PADI_IDX_IO53_SPI1_SS
#define PMOD2_SPI_SS_PINCFG                       PADI_CFG_IO53_SPI1_SS
#define PMOD2_SPI_SLAVE_MOSI_PIN                  PADI_IDX_IO55_SPI1_RXD
#define PMOD2_SPI_SLAVE_MOSI_PINCFG               PADI_CFG_IO55_SPI1_RXD
#define PMOD2_SPI_SLAVE_MISO_PIN                  PADI_IDX_IO56_SPI1_TXD
#define PMOD2_SPI_SLAVE_MISO_PINCFG               PADI_CFG_IO56_SPI1_TXD


/*##################### UART ###################################*/
/**
  * @brief  UART Interface pins (USB2)
  *         
  */
#define USB2_UART                                UART2                          //option UART1
#define USB2_UART_CLK_ENABLE()                 __HAL_RCC_UART_CLK_ENABLE()
#define USB2_UART_CLK_DISABLE()                __HAL_RCC_UART_CLK_DISABLE()

#define USB2_UART_CLK_SETSOURCE(__SOURCE__)	   __HAL_RCC_BR_CONFIG(__SOURCE__)
#define USB2_UART_CLK_SETDIVIDER()	           __HAL_RCC_SET_BR_CLK_DIV(1UL)

#define USB2_UART_TX_PIN                         PADI_IDX_IO18_UART2_TX        //option PADI_IDX_IO1_UART1_TX
#define USB2_UART_TX_PINCFG                      PADI_CFG_IO18_UART2_TX        //option PADI_CFG_IO1_UART1_TX
#define USB2_UART_RX_PIN                         PADI_IDX_IO19_UART2_RX        //option PADI_IDX_IO5_UART1_RX
#define USB2_UART_RX_PINCFG                      PADI_CFG_IO19_UART2_RX        //option PADI_CFG_IO5_UART1_RX

/*##################### GPIO ###################################*/
/**
  * @brief  I2C Interface pins (PMOD1 6A)
  *         
  */
#define PMOD1_6_PAD                         PADI_IDX_IO45_PA25
#define PMOD1_6_AF                          PADI_CFG_IO45_PA25
#define PMOD1_6_PIN                         GPIO_PIN_25
#define PMOD1_6_GPIO_PORT                   GPIOA
#define PMOD1_6_INT                         GPIO_PIN_25
#define PMOD1_6_IRQn                        ICTL_IRQn

#define PMOD1_7_PAD                         PADI_IDX_IO46_PA24
#define PMOD1_7_AF                          PADI_CFG_IO46_PA24
#define PMOD1_7_PIN                         GPIO_PIN_24
#define PMOD1_7_GPIO_PORT                   GPIOA
#define PMOD1_7_INT                         GPIO_PIN_24
#define PMOD1_7_IRQn                        ICTL_IRQn

#define PMOD1_8_PAD                         PADI_IDX_IO47_PA23
#define PMOD1_8_AF                          PADI_CFG_IO47_PA23
#define PMOD1_8_PIN                         GPIO_PIN_23
#define PMOD1_8_GPIO_PORT                   GPIOA
#define PMOD1_8_INT                         GPIO_PIN_23
#define PMOD1_8_IRQn                        ICTL_IRQn

#define PMOD1_9_PAD                         PADI_IDX_IO48_PA22
#define PMOD1_9_AF                          PADI_CFG_IO48_PA22
#define PMOD1_9_PIN                         GPIO_PIN_22
#define PMOD1_9_GPIO_PORT                   GPIOA
#define PMOD1_9_INT                         GPIO_PIN_22
#define PMOD1_9_IRQn                        ICTL_IRQn

/**
  * @brief  SPI Interface pins (PMOD2 2A)
  *         
  */
#define PMOD2_6_PAD                         PADI_IDX_IO57_PA13
#define PMOD2_6_AF                          PADI_CFG_IO57_PA13
#define PMOD2_6_PIN                         GPIO_PIN_13
#define PMOD2_6_GPIO_PORT                   GPIOA
#define PMOD2_6_INT                         GPIO_PIN_13
#define PMOD2_6_IRQn                        ICTL_IRQn

#define PMOD2_7_PAD                         PADI_IDX_IO58_PA12
#define PMOD2_7_AF                          PADI_CFG_IO58_PA12
#define PMOD2_7_PIN                         GPIO_PIN_12
#define PMOD2_7_GPIO_PORT                   GPIOA
#define PMOD2_7_INT                         GPIO_PIN_12
#define PMOD2_7_IRQn                        ICTL_IRQn

#define PMOD2_8_PAD                         PADI_IDX_IO52_PA18
#define PMOD2_8_AF                          PADI_CFG_IO52_PA18
#define PMOD2_8_PIN                         GPIO_PIN_18
#define PMOD2_8_GPIO_PORT                   GPIOA
#define PMOD2_8_INT                         GPIO_PIN_18
#define PMOD2_8_IRQn                        ICTL_IRQn

#define PMOD2_9_PAD                         PADI_IDX_IO50_PA20
#define PMOD2_9_AF                          PADI_CFG_IO50_PA20
#define PMOD2_9_PIN                         GPIO_PIN_20
#define PMOD2_9_GPIO_PORT                   GPIOA
#define PMOD2_9_INT                         GPIO_PIN_20
#define PMOD2_9_IRQn                        ICTL_IRQn

/**
  * @brief  Touch Key Interface pins 
  *         
  */
#define TOUCH_KEY_PAD                       PADI_IDX_IO43_CTSU_SN_8
#define TOUCH_KEY_AF                        PADI_CFG_IO43_CTSU_SN_8

/**
  * @brief  Digit display Interface pins 
  *         
  */
#define LED_A_PAD                          PADI_IDX_IO1_LED0
#define LED_A_AF                           PADI_CFG_IO1_LED0
#define LED_B_PAD                          PADI_IDX_IO5_LED1
#define LED_B_AF                           PADI_CFG_IO5_LED1
#define LED_C_PAD                          PADI_IDX_IO9_LED2
#define LED_C_AF                           PADI_CFG_IO9_LED2
#define LED_D_PAD                          PADI_IDX_IO10_LED3
#define LED_D_AF                           PADI_CFG_IO10_LED3
#define LED_E_PAD                          PADI_IDX_IO13_LED4
#define LED_E_AF                           PADI_CFG_IO13_LED4
#define LED_F_PAD                          PADI_IDX_IO14_LED5
#define LED_F_AF                           PADI_CFG_IO14_LED5
#define LED_G_PAD                          PADI_IDX_IO15_LED6
#define LED_G_AF                           PADI_CFG_IO15_LED6
#define LED_H_PAD                          PADI_IDX_IO17_LED7
#define LED_H_AF                           PADI_CFG_IO17_LED7
#define LED_I_PAD                          PADI_IDX_IO25_LED8
#define LED_I_AF                           PADI_CFG_IO25_LED8
/**
  * @}
  */
    
/**
  * @}
  */

/** @defgroup XTX_ES_XT32H0XX_Exported_Functions Exported Functions
  * @{
  */
/** @defgroup XTX_ES_XT32H0XX_generic_functions Version functions
  * @{
  */
uint32_t                BSP_GetVersion(void);
#if defined(_GUI_INTERFACE)
const uint8_t*          BSP_GetHWBoardVersionName(void);
const uint8_t*          BSP_GetPDTypeName(void);
#endif /* _GUI_INTERFACE */
/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_LED_Functions  LED Functions
  * @{
  */   
void             BSP_LED_Init(Led_TypeDef Led);
void             BSP_LED_DeInit(Led_TypeDef Led);
void             BSP_LED_On(Led_TypeDef Led);
void             BSP_LED_Off(Led_TypeDef Led);
void             BSP_LED_Toggle(Led_TypeDef Led);
/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_PB_Functions  Button Functions
  * @{
  */   
void             BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode);
void             BSP_PB_DeInit(Button_TypeDef Button);
uint32_t         BSP_PB_GetState(Button_TypeDef Button);
/**
  * @}
  */ 


/** @defgroup XTX_ES_XT32H0XX_PMOD1_Functions  PMOD1 Functions
  * @{
  */   
void             BSP_PMOD1_I2C_Init(void);
void             BSP_PMOD1_I2C_DeInit(void);
/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_PMOD2_Functions  PMOD1 Functions
  * @{
  */
void             BSP_PMOD2_SPI_Init(void);
void             BSP_PMOD2_SPI_DeInit(void);
/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_TouchKey_Functions  TouchKey Functions
  * @{
  */
void             BSP_TouchKey_Init(void);
void             BSP_TouchKey_DeInit(void);
/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_DigitDisplay_Functions  Digit display Functions
  * @{
  */
void             BSP_DigitDisplay_Init(void);
void             BSP_DigitDisplay_DeInit(void);
/**
  * @}
  */ 

/** @defgroup XTX_ES_XT32H0XX_PMOD1_Functions  PMOD1 Functions
  * @{
  */
void             BSP_LogInit(void);
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

#ifdef __cplusplus
}
#endif

#endif /* XTX_ES_XT32H0XX_H */

    
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

