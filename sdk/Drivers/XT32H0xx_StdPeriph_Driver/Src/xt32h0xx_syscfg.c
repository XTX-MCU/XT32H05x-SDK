/**
  ******************************************************************************
  * @file    xt32h0xx_syscfg.c
  * @author  Software Team
  * @date    24 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the SYSCFG peripheral:
  *   
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_syscfg.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup SYSCFG SYSCFG
  * @brief SYSCFG driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup SYSCFG_Exported_Functions SYSCFG Exported Functions
  * @{
  */ 

/** @defgroup SYSCFG_Exported_Functions_Group1 SYSCFG Configuration functions
 *  @brief   SYSCFG Configuration functions 
 *
@verbatim
 ===============================================================================
        ##### SYSCFG Configuration functions #####
 ===============================================================================
    [..]
        (++) Memory configure
        (++) UART mode
        (++) SPI mode
        (++) Interrupt mux configure
        (++) DMA handshaking configure
        (++) Windows watch-dog configure
        (++) Peripheral software reset
        (++) Advanced timer configure
        (++) GPIO auxiliary configure
        (++) Read UID
        (++) UART auto detect baud rate


@endverbatim
  * @{
  */

/**
  * @brief  Memory remapping control by hardware.
  */
void SYSCFG_MemoryRemapHW(void)
{
  SYSCFG->SYS_CFG &= (uint32_t)~((uint32_t)SYSCFG_SYS_CFG_BOOTCTRL);
}

/**
  * @brief  Configures the memory mapping at address 0x00000000.
  * @param  SYSCFG_MemoryRemap: selects the memory remapping.
  *          This parameter can be one of the following values:
  *            @arg @ref SYS_BOOT_MODE_FLASH Main Flash memory mapped at 0x00000000  
  *            @arg @ref SYS_BOOT_MODE_ROM System Flash memory mapped at 0x00000000
  *            @arg @ref SYS_BOOT_MODE_SRAM Embedded SRAM mapped at 0x00000000
  */
void SYSCFG_MemoryRemapConfig(uint32_t SYSCFG_MemoryRemap)
{
  uint32_t tempr = 0;

  /* Check the parameter */
  assert_param(IS_SYS_BOOT_MODE(SYSCFG_MemoryRemap));

  tempr = SYSCFG->SYS_CFG;

  tempr &= (uint32_t)~((uint32_t)SYSCFG_SYS_CFG_BOOT_MODE);

  tempr |= (uint32_t) SYSCFG_MemoryRemap;

  SYSCFG->SYS_CFG = tempr;
}

/**
  * @brief  Enable flash DMA access.
  */
void SYSCFG_EnableFlashDMA(void)
{
  SYSCFG->SYS_CFG |= (uint32_t)SYSCFG_SYS_CFG_FLASHDMA;
}

/**
  * @brief  Disable flash DMA access.
  */
void SYSCFG_DisableFlashDMA(void)
{
  SYSCFG->SYS_CFG &= (uint32_t)~((uint32_t)SYSCFG_SYS_CFG_FLASHDMA);
}

/**
  * @brief  Configure UARTx Mode.
  * @param  SYSCFG_UARTMode 
  */
void SYSCFG_SetUARTMode(uint32_t SYSCFG_UARTMode)
{
  uint32_t tempr;
  uint32_t mask = SYS_GET_UARTMODE_MASK(SYSCFG_UARTMode);

  tempr =  SYSCFG->SYS_CFG;

  tempr &= (uint32_t)~((uint32_t)mask); 
  tempr |= (uint32_t)SYSCFG_UARTMode; 

   SYSCFG->SYS_CFG = tempr;
}

/**
  * @brief  Configure SPIx Mode.
  * @param  SYSCFG_SPIMode 
  */
void SYSCFG_SetSPIMode(uint32_t SYSCFG_SPIMode)
{
  uint32_t tempr;
  uint32_t mask = SYS_GET_SPIMODE_MASK(SYSCFG_SPIMode);

  tempr =  SYSCFG->SYS_CFG;

  tempr &= (uint32_t)~((uint32_t)mask); 
  tempr |= (uint32_t)SYSCFG_SPIMode; 

   SYSCFG->SYS_CFG = tempr;
}

/** @brief  Configure ICTL lines
  * @param ICTL_lines: 
  * @param ICTL_Range: 
  * @param SYSCFG_ICTLCfg: 
  */
void SYSCFG_ICTLConfig(uint32_t ICTL_lines, uint32_t ICTL_Range, uint32_t SYSCFG_ICTLCfg)
{
  uint32_t tempr;
  uint32_t* reg = ((uint32_t*)&(SYSCFG->IRQ_CFG_1)) + ICTL_Range;

  tempr = *reg;
  
  tempr &= (uint32_t)~((uint32_t)ICTL_lines);
  tempr |= (uint32_t)(ICTL_lines * SYSCFG_ICTLCfg);

  *reg = tempr;
}

/**
  * @brief  Config DMA handshaking interface
  * @param  SYSCFG_DMAHSIdx: 
  * @param  SYSCFG_DMAHSCfg: 
  */
void SYSCFG_DMAHSConfig(uint32_t SYSCFG_DMAHSIdx,uint32_t SYSCFG_DMAHSCfg)
{
  uint32_t tempr = SYSCFG->DMA_CFG;
  uint32_t mask = 0x03UL << (SYSCFG_DMAHSIdx<<1);
  
  tempr &= (uint32_t)~((uint32_t)mask);
  tempr |= (uint32_t)(SYSCFG_DMAHSCfg);

  SYSCFG->DMA_CFG = tempr;
}

/**
  * @brief  Enable WDTW external clock
  */
void SYSCFG_EnableWDTWExternalClock(void)
{
  SYSCFG->WDT_CFG |= (uint32_t)SYSCFG_WDTW_CFG_EXTCLK;
}

/**
  * @brief  Disable WDTW external clock
  */
void SYSCFG_DisableWDTWExternalClock(void)
{
  SYSCFG->WDT_CFG &= (uint32_t)~((uint32_t)SYSCFG_WDTW_CFG_EXTCLK);
}

/**
  * @brief  Reset WDTW
  */
void SYSCFG_WDTWReset(void)
{
  SYSCFG->WDT_CFG &= (uint32_t)~((uint32_t)SYSCFG_WDTW_CFG_RST);
}

/**
  * @brief  Release reset WDTW
  */
void SYSCFG_WDTWResetRelease(void)
{
  SYSCFG->WDT_CFG |= (uint32_t)SYSCFG_WDTW_CFG_RST;
}

/**
  * @brief  Reset peripheral
  * @param  SYSCFG_Reset 
  */
void SYSCFG_PeripheralReset(uint32_t SYSCFG_Reset)
{
  assert_param(IS_SYS_SWRST(SYSCFG_Reset));
  SYSCFG->SW_RST_CFG &= (uint32_t)~((uint32_t)SYSCFG_Reset);
}

/**
  * @brief  Release reset peripheral
  * @param  SYSCFG_Reset 
  */
void SYSCFG_PeripheralResetRelease(uint32_t SYSCFG_Reset)
{
  assert_param(IS_SYS_SWRST(SYSCFG_Reset));
  SYSCFG->SW_RST_CFG |= (uint32_t)SYSCFG_Reset;
}

/**
  * @brief  Enable system break for advanced timer
  * @param  SYSCFG_SysBreak 
  */
void SYSCFG_TIMASysBreakEnable(uint32_t SYSCFG_SysBreak)
{
  assert_param(IS_SYS_TIMA_BRKSYSSRC(SYSCFG_SysBreak));
  SYSCFG->TIMER_ADV_CFG |= (uint32_t)SYSCFG_SysBreak;
}

/**
  * @brief  Disable system break for advanced timer
  * @param  SYSCFG_SysBreak 
  */
void SYSCFG_TIMASysBreakDisable(uint32_t SYSCFG_SysBreak)
{
  assert_param(IS_SYS_TIMA_BRKSYSSRC(SYSCFG_SysBreak));
  SYSCFG->TIMER_ADV_CFG &= (uint32_t)~((uint32_t)SYSCFG_SysBreak);
}

/**
  * @brief  Set GPIO output aux
  * @param  Port
  * @param  Pin 
  */
void SYSCFG_SetGPIOOutAux(uint32_t Port, uint32_t Pin)
{
  uint32_t* reg = ((uint32_t*)&(SYSCFG->GPIO_ENAUX_A)) + Port;

  *reg |= (uint32_t)Pin;
}

/**
  * @brief  Set GPIO input aux
  * @param  Port
  * @param  Pin 
  */
void SYSCFG_SetGPIOInAux(uint32_t Port, uint32_t Pin)
{
  uint32_t* reg = ((uint32_t*)&(SYSCFG->GPIO_ENAUX_A)) + Port;

  *reg &= (uint32_t)~((uint32_t)Pin);
}

/**
  * @brief  Get UID
  * @note   XT32H0xx UID is 96 bits
  * @param  pUID a pointer to UID
  */
void SYSCFG_GetUID(Uint32_t * pUID)
{
  uint32_t * ptr = pUID;
  *ptr++ = SYSCFG->UID_REG_0;
  *ptr++ = SYSCFG->UID_REG_1;
  *ptr   = SYSCFG->UID_REG_2;
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
