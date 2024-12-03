/**
  ******************************************************************************
  * @file    main.h
  * @author  Software Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup Main_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @addtogroup Main_Task_Exported_Constants
  * @{
  */
#define TRUE                   (1)
#define FALSE                  (0)

#define XTAPP_ICTL_PIN_RANGE00_31          (ICTL_IRQ1 )			///*Pin range assign register in ICTL or : */ 
#define XTAPP_ICTL_PIN_RANGE32_64          (ICTL_IRQ2 )  
#define XTAPP_SYS_IRQ_CFG0                 (LL_IRQ_CFG_1 )			///* the value of SYS IRQ CFG register in SYS_IRQ_CFG_0/SYS_IRQ_CFG_1: */ 
#define XTAPP_SYS_IRQ_CFG1                 (LL_IRQ_CFG_2 )  

									     
#define XTAPP_ICTL_IRQ_I2C1                ((XTAPP_ICTL_PIN_RANGE00_31 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 00--12*/
#define XTAPP_ICTL_IRQ_I2C2                ((XTAPP_ICTL_PIN_RANGE32_64 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 33--45*/
#define XTAPP_ICTL_IRQ_SPI1                ((XTAPP_ICTL_PIN_RANGE00_31 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 13--18*/
#define XTAPP_ICTL_IRQ_SPI2                ((XTAPP_ICTL_PIN_RANGE00_31 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 19--24*/
#define XTAPP_ICTL_IRQ_TIMRB               ((XTAPP_ICTL_PIN_RANGE00_31 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 25--31*/
#define XTAPP_ICTL_IRQ_TIMRB24             ((XTAPP_ICTL_PIN_RANGE32_64 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 32*/
#define XTAPP_ICTL_IRQ_ADC                 ((XTAPP_ICTL_PIN_RANGE32_64 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 48--53*/
#define XTAPP_ICTL_IRQ_lED                 ((XTAPP_ICTL_PIN_RANGE32_64 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 56--59*/
#define XTAPP_ICTL_IRQ_AFC                 ((XTAPP_ICTL_PIN_RANGE32_64 ) | XTAPP_SYS_IRQ_CFG0 )		/*CFG0: pin rang 60--62*/
#define XTAPP_ICTL_IRQ_GPIO                ((XTAPP_ICTL_PIN_RANGE32_64 ) | XTAPP_SYS_IRQ_CFG1 )		/*CFG1: pin rang 32--63*/  


/* Exported macro ------------------------------------------------------------*/

/** @addtogroup Main_Task_Exported_Functions
  * @{
  */
/* Exported functions prototypes ---------------------------------------------*/
void Error_Handle(void );
void XT_IO_Option_Assigned(uint32_t io_idx, uint32_t io_cfg, uint32_t pin_pull);
uint8_t XT_SYS_IRQ_Source_IsSelected(uint32_t irqModule, uint32_t Cfg_mask);
void XT_ICTL_IRQ_Module_Enable(uint32_t irqModule, uint32_t Cfg_mask);
uint32_t XT_ICTL_IRQ_FinalStatus_Check(uint32_t irqModule, uint32_t Irq_lines);
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

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
