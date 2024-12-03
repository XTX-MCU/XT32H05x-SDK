/**
  ******************************************************************************
  * @file    xt32h0xxampw.h
  * @author  Software Team
  * @brief   CMSIS Cortex-M0+ Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for xt32h0xxampw devices.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */
/** @addtogroup CMSIS_Device
  * @{
  */

/** @addtogroup xt32h0xxampw
  * @{
  */

#ifndef XT32H0XXAMPW_H
#define XT32H0XXAMPW_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
  * @brief Configuration of the Cortex-M0+ Processor and Core Peripherals
   */
#define __CM0PLUS_REV             0U /*!< Core Revision r0p0                            */
#define __MPU_PRESENT             0U /*!< xt32h0xxampw  provides an MPU                    */
#define __VTOR_PRESENT            1U /*!< Vector  Table  Register supported             */
#define __NVIC_PRIO_BITS          2U /*!< xt32h0xxampw uses 2 Bits for the Priority Levels */
#define __Vendor_SysTickConfig    0U /*!< Set to 1 if different SysTick Config is used  */

/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

/**
 * @brief xt32h0xxampw Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
/**
 * @brief xt32h0xxampw Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */

/*!< Interrupt Number Definition */
typedef enum
{
/*****************  Cortex-M0+ Processor Exceptions Numbers  ******************/
  NonMaskableInt_IRQn         = -14,
  HardFault_IRQn              = -13,
  SVC_IRQn                    = -5,
  PendSV_IRQn                 = -2,
  SysTick_IRQn                = -1,
/*****************  XT32H0XXAMPW specific Interrupt Numbers  ******************/
  DMA1_IRQn                   = 0,
  WDTW_IRQn                   = 1,
  ADC_EOC_IRQn                = 2,
  RTC_IRQn                    = 3,
  ICTL_IRQn                   = 4,
  UART1_IRQn                  = 5,
  UART2_IRQn                  = 6,
  UART3_IRQn                  = 7,
  UART4_IRQn                  = 8,
  TIMB11_IRQn                 = 9,
  TIMB12_IRQn                 = 10,
  TIMB13_IRQn                 = 11,
  TIMB14_IRQn                 = 12,
  TIMB21_IRQn                 = 13,
  TIMB22_IRQn                 = 14,
  TIMB23_IRQn                 = 15,
  TIMB24_IRQn                 = 16,
  TIM1_BRK_IRQn               = 17,
  TIM1_TRG_IRQn               = 18,
  TIM1_COM_IRQn               = 19,
  TIM1_CC1_IRQn               = 20,
  TIM1_CC2_IRQn               = 21,
  TIM1_CC3_IRQn               = 22,
  TIM1_CC4_IRQn               = 23,
  TIM1_UDT_IRQn               = 24,
  TIMG_TRG_IRQn               = 25,
  TIMG_COM_IRQn               = 26,
  TIMG_CC1_IRQn               = 27,
  TIMG_CC2_IRQn               = 28,
  TIMG_CC3_IRQn               = 29,
  TIMG_CC4_IRQn               = 30,
  TIMG_UDT_IRQn               = 31
} IRQn_Type;

/**
  * @}
  */

#include "core_cm0plus.h"               /* Cortex-M0+ processor and core peripherals */
#include "system_xt32h0xx.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */
  
/**
  * @brief AON Registers
  */
typedef struct
{
  __IO uint32_t AON_CFG;                /*!< Address offset: 0x00 */
  __IO uint32_t RTC_REFCLK_DIV;         /*!< Address offset: 0x04 */
  __IO uint32_t AON_CLK_CTRL;           /*!< Address offset: 0x08 */
  __IO uint32_t LDO_CFG;                /*!< Address offset: 0x0C */
       uint32_t RESERVED0[2];
  __IO uint32_t IVREF_CFG_3;            /*!< Address offset: 0x18 */
       uint32_t RESERVED1[1];
  __IO uint32_t DEEPSLEEP_TIME;         /*!< Address offset: 0x20 */
  __IO uint32_t DEEPSLEEP_CTRL;         /*!< Address offset: 0x24 */
} AON_TypeDef;
    
/**
  * @brief CRC Registers
  */
typedef struct
{
  __IO uint32_t CFG;                    /*!< Address offset: 0x00 */
  __IO uint32_t DATA;                   /*!< Address offset: 0x04 */
  __IO uint32_t RESULT;                 /*!< Address offset: 0x08 */
  __IO uint32_t XORVALUE;               /*!< Address offset: 0x0C */
} CRC_TypeDef;
    
/**
  * @brief DAM_CH Registers
  */
typedef struct
{
  __IO uint32_t SAR;                    /*!< Address offset: 0x00 */
       uint32_t RESERVED0[1];
  __IO uint32_t DAR;                    /*!< Address offset: 0x08 */
       uint32_t RESERVED1[3];
  __IO uint32_t CTL_L;                  /*!< Address offset: 0x18 */
  __IO uint32_t CTL_H;                  /*!< Address offset: 0x1C */
       uint32_t RESERVED2[8];
  __IO uint32_t CFG_L;                  /*!< Address offset: 0x40 */
  __IO uint32_t CFG_H;                  /*!< Address offset: 0x44 */
} DMA_Channel_TypeDef;
    
/**
  * @brief DMA Registers
  */
typedef struct
{
  __IO uint32_t RAWTFR;                 /*!< Address offset: 0x00 */
       uint32_t RESERVED0[1];
  __IO uint32_t RAWBLOCK;               /*!< Address offset: 0x08 */
       uint32_t RESERVED1[1];
  __IO uint32_t RAWSRCTRAN;             /*!< Address offset: 0x10 */
       uint32_t RESERVED2[1];
  __IO uint32_t RAWDSTTRAN;             /*!< Address offset: 0x18 */
       uint32_t RESERVED3[1];
  __IO uint32_t RAWERR;                 /*!< Address offset: 0x20 */
       uint32_t RESERVED4[1];
  __IO uint32_t STATTFR;                /*!< Address offset: 0x28 */
       uint32_t RESERVED5[1];
  __IO uint32_t STATBLOCK;              /*!< Address offset: 0x30 */
       uint32_t RESERVED6[1];
  __IO uint32_t STATSRCTRAN;            /*!< Address offset: 0x38 */
       uint32_t RESERVED7[1];
  __IO uint32_t STATDSTTRAN;            /*!< Address offset: 0x40 */
       uint32_t RESERVED8[1];
  __IO uint32_t STATERR;                /*!< Address offset: 0x48 */
       uint32_t RESERVED9[1];
  __IO uint32_t MSKTFR;                 /*!< Address offset: 0x50 */
       uint32_t RESERVED10[1];
  __IO uint32_t MSKBLOCK;               /*!< Address offset: 0x58 */
       uint32_t RESERVED11[1];
  __IO uint32_t MSKSRCTRAN;             /*!< Address offset: 0x60 */
       uint32_t RESERVED12[1];
  __IO uint32_t MSKDSTTRAN;             /*!< Address offset: 0x68 */
       uint32_t RESERVED13[1];
  __IO uint32_t MSKERR;                 /*!< Address offset: 0x70 */
       uint32_t RESERVED14[1];
  __IO uint32_t CLRTFR;                 /*!< Address offset: 0x78 */
       uint32_t RESERVED15[1];
  __IO uint32_t CLRBLOCK;               /*!< Address offset: 0x80 */
       uint32_t RESERVED16[1];
  __IO uint32_t CLRSRCTRAN;             /*!< Address offset: 0x88 */
       uint32_t RESERVED17[1];
  __IO uint32_t CLRDSTTRAN;             /*!< Address offset: 0x90 */
       uint32_t RESERVED18[1];
  __IO uint32_t CLRERR;                 /*!< Address offset: 0x98 */
       uint32_t RESERVED19[1];
  __IO uint32_t STATINT;                /*!< Address offset: 0xA0 */
       uint32_t RESERVED20[1];
  __IO uint32_t REQSRC;                 /*!< Address offset: 0xA8 */
       uint32_t RESERVED21[1];
  __IO uint32_t REQDST;                 /*!< Address offset: 0xB0 */
       uint32_t RESERVED22[1];
  __IO uint32_t SGLREQSRC;              /*!< Address offset: 0xB8 */
       uint32_t RESERVED23[1];
  __IO uint32_t SGLREQDST;              /*!< Address offset: 0xC0 */
       uint32_t RESERVED24[1];
  __IO uint32_t LSTREQSRC;              /*!< Address offset: 0xC8 */
       uint32_t RESERVED25[1];
  __IO uint32_t LSTREQDST;              /*!< Address offset: 0xD0 */
       uint32_t RESERVED26[1];
  __IO uint32_t DMACFG;                 /*!< Address offset: 0xD8 */
       uint32_t RESERVED27[1];
  __IO uint32_t CHEN;                   /*!< Address offset: 0xE0 */
} DMA_TypeDef;
    
/**
  * @brief FLASH Registers
  */
typedef struct
{
  __IO uint32_t CTRL;                   /*!< Address offset: 0x00 */
  __IO uint32_t ERPLW;                  /*!< Address offset: 0x04 */
  __IO uint32_t ERWEPLW;                /*!< Address offset: 0x08 */
  __IO uint32_t ERWESTPT;               /*!< Address offset: 0x0C */
  __IO uint32_t PRWESTPHLDT;            /*!< Address offset: 0x10 */
  __IO uint32_t PR2STPT;                /*!< Address offset: 0x14 */
  __IO uint32_t PRWEPLW;                /*!< Address offset: 0x18 */
       uint32_t RESERVED0[1];
  __IO uint32_t ROWADDR;                /*!< Address offset: 0x20 */
       uint32_t RESERVED1[54];
  __IO uint32_t STRT;                   /*!< Address offset: 0xFC */
} FLASH_TypeDef;
    
/**
  * @brief GPIO Registers
  */
typedef struct
{
  __IO uint32_t DR;                     /*!< Address offset: 0x00 */
  __IO uint32_t DDR;                    /*!< Address offset: 0x04 */
  __IO uint32_t CTL;                    /*!< Address offset: 0x08 */
} GPIO_TypeDef;
    
/**
  * @brief GPIO_AUX Registers
  */
typedef struct
{
  __IO uint32_t DRA;                    /*!< Address offset: 0x00 */
  __IO uint32_t DDRA;                   /*!< Address offset: 0x04 */
  __IO uint32_t CTLA;                   /*!< Address offset: 0x08 */
  __IO uint32_t DRB;                    /*!< Address offset: 0x0C */
  __IO uint32_t DDRB;                   /*!< Address offset: 0x10 */
  __IO uint32_t CTLB;                   /*!< Address offset: 0x14 */
  __IO uint32_t DRC;                    /*!< Address offset: 0x18 */
  __IO uint32_t DDRC;                   /*!< Address offset: 0x1C */
  __IO uint32_t CTLC;                   /*!< Address offset: 0x20 */
  __IO uint32_t DRD;                    /*!< Address offset: 0x24 */
  __IO uint32_t DDRD;                   /*!< Address offset: 0x28 */
  __IO uint32_t CTLD;                   /*!< Address offset: 0x2C */
  __IO uint32_t INTEN;                  /*!< Address offset: 0x30 */
  __IO uint32_t INTMSK;                 /*!< Address offset: 0x34 */
  __IO uint32_t INTLVL;                 /*!< Address offset: 0x38 */
  __IO uint32_t INTPOL;                 /*!< Address offset: 0x3C */
  __IO uint32_t INTSTA;                 /*!< Address offset: 0x40 */
  __IO uint32_t INTRAWSTA;              /*!< Address offset: 0x44 */
  __IO uint32_t DEBOU;                  /*!< Address offset: 0x48 */
  __IO uint32_t EOIA;                   /*!< Address offset: 0x4C */
  __IO uint32_t EXTA;                   /*!< Address offset: 0x50 */
  __IO uint32_t EXTB;                   /*!< Address offset: 0x54 */
  __IO uint32_t EXTC;                   /*!< Address offset: 0x58 */
  __IO uint32_t EXTD;                   /*!< Address offset: 0x5C */
  __IO uint32_t LSSYNC;                 /*!< Address offset: 0x60 */
} GPIO_AUX_TypeDef;
    
/**
  * @brief I2C Registers
  */
typedef struct
{
  __IO uint32_t CON;                    /*!< Address offset: 0x00 */
  __IO uint32_t TAR;                    /*!< Address offset: 0x04 */
  __IO uint32_t SAR;                    /*!< Address offset: 0x08 */
  __IO uint32_t HSMADDR;                /*!< Address offset: 0x0C */
  __IO uint32_t DATACMD;                /*!< Address offset: 0x10 */
  __IO uint32_t SSSCLHCNT;              /*!< Address offset: 0x14 */
  __IO uint32_t SSSCLLCNT;              /*!< Address offset: 0x18 */
  __IO uint32_t FSSCLHCNT;              /*!< Address offset: 0x1C */
  __IO uint32_t FSSCLLCNT;              /*!< Address offset: 0x20 */
  __IO uint32_t HSSCLHCNT;              /*!< Address offset: 0x24 */
  __IO uint32_t HSSCLLCNT;              /*!< Address offset: 0x28 */
  __IO uint32_t INTRSTAT;               /*!< Address offset: 0x2C */
  __IO uint32_t INTRMASK;               /*!< Address offset: 0x30 */
  __IO uint32_t RAWINTRSTAT;            /*!< Address offset: 0x34 */
  __IO uint32_t RXTL;                   /*!< Address offset: 0x38 */
  __IO uint32_t TXTL;                   /*!< Address offset: 0x3C */
  __IO uint32_t CLRINTR;                /*!< Address offset: 0x40 */
  __IO uint32_t CLRRXUNDER;             /*!< Address offset: 0x44 */
  __IO uint32_t CLRRXOVER;              /*!< Address offset: 0x48 */
  __IO uint32_t CLRTXOVER;              /*!< Address offset: 0x4C */
  __IO uint32_t CLRRDREQ;               /*!< Address offset: 0x50 */
  __IO uint32_t CLRTXABRT;              /*!< Address offset: 0x54 */
  __IO uint32_t CLRRXDONE;              /*!< Address offset: 0x58 */
  __IO uint32_t CLRACTIVITY;            /*!< Address offset: 0x5C */
  __IO uint32_t CLRSTOPDET;             /*!< Address offset: 0x60 */
  __IO uint32_t CLRSTARTDET;            /*!< Address offset: 0x64 */
  __IO uint32_t CLRGENCALL;             /*!< Address offset: 0x68 */
  __IO uint32_t ENABLE;                 /*!< Address offset: 0x6C */
  __IO uint32_t STATUS;                 /*!< Address offset: 0x70 */
  __IO uint32_t TXFLR;                  /*!< Address offset: 0x74 */
  __IO uint32_t RXFLR;                  /*!< Address offset: 0x78 */
  __IO uint32_t SDAHOLD;                /*!< Address offset: 0x7C */
  __IO uint32_t TXABRTSOURCE;           /*!< Address offset: 0x80 */
       uint32_t RESERVED0[1];
  __IO uint32_t DMACR;                  /*!< Address offset: 0x88 */
  __IO uint32_t DMATDLR;                /*!< Address offset: 0x8C */
  __IO uint32_t DMARDLR;                /*!< Address offset: 0x90 */
  __IO uint32_t SDASETUP;               /*!< Address offset: 0x94 */
  __IO uint32_t ACKGENERALCALL;         /*!< Address offset: 0x98 */
  __IO uint32_t ENABLESTATUS;           /*!< Address offset: 0x9C */
  __IO uint32_t FSSPKLEN;               /*!< Address offset: 0xA0 */
  __IO uint32_t HSSPKLEN;               /*!< Address offset: 0xA4 */
} I2C_TypeDef;
    
/**
  * @brief ICG Registers
  */
typedef struct
{
  __IO uint32_t CLK_CFG;                /*!< Address offset: 0x00 */
  __IO uint32_t HCLK_DIV;               /*!< Address offset: 0x04 */
  __IO uint32_t PCLK_DIV;               /*!< Address offset: 0x08 */
  __IO uint32_t DMA_CLK_DIV;            /*!< Address offset: 0x0C */
  __IO uint32_t BR_CLK_DIV;             /*!< Address offset: 0x10 */
  __IO uint32_t I2C0_CLK_DIV;           /*!< Address offset: 0x14 */
  __IO uint32_t I2C1_CLK_DIV;           /*!< Address offset: 0x18 */
  __IO uint32_t GPIO_CLK_DIV;           /*!< Address offset: 0x1C */
  __IO uint32_t RC16M_CTRL;             /*!< Address offset: 0x20 */
  __IO uint32_t PLL_DIV;                /*!< Address offset: 0x24 */
  __IO uint32_t PLL_PD_CTRL;            /*!< Address offset: 0x28 */
  __IO uint32_t PLL_LFCFG_CTRL;         /*!< Address offset: 0x2C */
  __IO uint32_t PLL_VCOCAL_CTRL;        /*!< Address offset: 0x30 */
  __IO uint32_t PLL_IREF_CTRL;          /*!< Address offset: 0x34 */
       uint32_t RESERVED0[2];
  __IO uint32_t TIMER_ADV_CLK_DIV;      /*!< Address offset: 0x40 */
  __IO uint32_t TIMER_B0_CLK_DIV;       /*!< Address offset: 0x44 */
  __IO uint32_t TIMER_B1_CLK_DIV;       /*!< Address offset: 0x48 */
  __IO uint32_t WDT_W_CLK_DIV;          /*!< Address offset: 0x4C */
  __IO uint32_t TIMER_EXCLK_EN;         /*!< Address offset: 0x50 */
  __IO uint32_t ADC_CLK_DIV;            /*!< Address offset: 0x54 */
} ICG_TypeDef;
    
/**
  * @brief ICTL Registers
  */
typedef struct
{
  __IO uint32_t IRQINTENL;              /*!< Address offset: 0x00 */
  __IO uint32_t IRQINTENH;              /*!< Address offset: 0x04 */
  __IO uint32_t IRQINTMASKL;            /*!< Address offset: 0x08 */
  __IO uint32_t IRQINTMASKH;            /*!< Address offset: 0x0C */
  __IO uint32_t IRQINTFORCEL;           /*!< Address offset: 0x10 */
  __IO uint32_t IRQINTFORCEH;           /*!< Address offset: 0x14 */
  __IO uint32_t IRQRAWSTATUSL;          /*!< Address offset: 0x18 */
  __IO uint32_t IRQRAWSTATUSH;          /*!< Address offset: 0x1C */
  __IO uint32_t IRQSTATUSL;             /*!< Address offset: 0x20 */
  __IO uint32_t IRQSTATUSH;             /*!< Address offset: 0x24 */
  __IO uint32_t IRQMASKSTATUSL;         /*!< Address offset: 0x28 */
  __IO uint32_t IRQMASKSTATUSH;         /*!< Address offset: 0x2C */
  __IO uint32_t IRQFINALSTATUSL;        /*!< Address offset: 0x30 */
  __IO uint32_t IRQFINALSTATUSH;        /*!< Address offset: 0x34 */
       uint32_t RESERVED0[34];
  __IO uint32_t FIQINTEN;               /*!< Address offset: 0xC0 */
  __IO uint32_t FIQINTMASK;             /*!< Address offset: 0xC4 */
  __IO uint32_t FIQINTFORCE;            /*!< Address offset: 0xC8 */
  __IO uint32_t FIQRAWSTATUS;           /*!< Address offset: 0xCC */
  __IO uint32_t FIQSTATUS;              /*!< Address offset: 0xD0 */
  __IO uint32_t FIQFINALSTATUS;         /*!< Address offset: 0xD4 */
  __IO uint32_t IRQPLEVEL;              /*!< Address offset: 0xD8 */
} ICTL_TypeDef;
    
/**
  * @brief MDU Registers
  */
typedef struct
{
  __IO uint32_t PDCTRL;                 /*!< Address offset: 0x00 */
  __IO uint32_t DAC_CFG;                /*!< Address offset: 0x04 */
  __IO uint32_t PGA_CFG;                /*!< Address offset: 0x08 */
  __IO uint32_t ADC_CFG;                /*!< Address offset: 0x0C */
  __IO uint32_t COMP_CFG0;              /*!< Address offset: 0x10 */
  __IO uint32_t COMP_CFG1;              /*!< Address offset: 0x14 */
  __IO uint32_t COMP_CFG2;              /*!< Address offset: 0x18 */
       uint32_t RESERVED0[1];
  __IO uint32_t ADC_STATUS;             /*!< Address offset: 0x20 */
  __IO uint32_t ADC_RESULTS;            /*!< Address offset: 0x24 */
  __IO uint32_t ADC_CTRL;               /*!< Address offset: 0x28 */
       uint32_t RESERVED1[1];
  __IO uint32_t ADC_RESULTS_CH0;        /*!< Address offset: 0x30 */
  __IO uint32_t ADC_RESULTS_CH1;        /*!< Address offset: 0x34 */
  __IO uint32_t ADC_RESULTS_CH2;        /*!< Address offset: 0x38 */
  __IO uint32_t ADC_RESULTS_CH3;        /*!< Address offset: 0x3C */
  __IO uint32_t ADC_RESULTS_CH4;        /*!< Address offset: 0x40 */
  __IO uint32_t ADC_RESULTS_CH5;        /*!< Address offset: 0x44 */
  __IO uint32_t ADC_RESULTS_CH6;        /*!< Address offset: 0x48 */
  __IO uint32_t ADC_RESULTS_CH7;        /*!< Address offset: 0x4C */
  __IO uint32_t ADC_RESULTS_CH8;        /*!< Address offset: 0x50 */
  __IO uint32_t ADC_RESULTS_CH9;        /*!< Address offset: 0x54 */
  __IO uint32_t ADC_RESULTS_CH10;       /*!< Address offset: 0x58 */
  __IO uint32_t ADC_RESULTS_CH11;       /*!< Address offset: 0x5C */
  __IO uint32_t ADC_RESULTS_CH12;       /*!< Address offset: 0x60 */
  __IO uint32_t ADC_RESULTS_CH13;       /*!< Address offset: 0x64 */
  __IO uint32_t ADC_RESULTS_CH14;       /*!< Address offset: 0x68 */
  __IO uint32_t ADC_RESULTS_CH15;       /*!< Address offset: 0x6C */
} MDU_TypeDef;

typedef MDU_TypeDef ADC_TypeDef;
typedef MDU_TypeDef DAC_TypeDef;
typedef MDU_TypeDef PGA_TypeDef;
typedef MDU_TypeDef COMP_TypeDef;
    
/**
  * @brief PADI Registers
  */
typedef struct
{
  __IO uint32_t PORTMUX_CFG_1;          /*!< Address offset: 0x00 */
  __IO uint32_t PORTMUX_CFG_2;          /*!< Address offset: 0x04 */
  __IO uint32_t PORTMUX_CFG_3;          /*!< Address offset: 0x08 */
  __IO uint32_t PORTMUX_CFG_4;          /*!< Address offset: 0x0C */
  __IO uint32_t PORTMUX_CFG_5;          /*!< Address offset: 0x10 */
  __IO uint32_t PORTMUX_CFG_6;          /*!< Address offset: 0x14 */
  __IO uint32_t PORTMUX_CFG_7;          /*!< Address offset: 0x18 */
  __IO uint32_t PORTMUX_CFG_8;          /*!< Address offset: 0x1C */
  __IO uint32_t IO_PULLUP_CFG_1;        /*!< Address offset: 0x20 */
  __IO uint32_t IO_PULLUP_CFG_2;        /*!< Address offset: 0x24 */
  __IO uint32_t IO_PULLDW_CFG_1;        /*!< Address offset: 0x28 */
  __IO uint32_t IO_PULLDW_CFG_2;        /*!< Address offset: 0x2C */
  __IO uint32_t IO_DS_CFG_1;            /*!< Address offset: 0x30 */
  __IO uint32_t IO_DS_CFG_2;            /*!< Address offset: 0x34 */
} PADI_TypeDef;
    
/**
  * @brief RTC Registers
  */
typedef struct
{
  __IO uint32_t CCVR;                   /*!< Address offset: 0x00 */
  __IO uint32_t CMR;                    /*!< Address offset: 0x04 */
  __IO uint32_t CLR;                    /*!< Address offset: 0x08 */
  __IO uint32_t CCR;                    /*!< Address offset: 0x0C */
  __IO uint32_t STAT;                   /*!< Address offset: 0x10 */
  __IO uint32_t RSTAT;                  /*!< Address offset: 0x14 */
  __IO uint32_t EOI;                    /*!< Address offset: 0x18 */
} RTC_TypeDef;
    
/**
  * @brief SPI Registers
  */
typedef struct
{
  __IO uint32_t CTRLR0;                 /*!< Address offset: 0x00 */
  __IO uint32_t CTRLR1;                 /*!< Address offset: 0x04 */
  __IO uint32_t SSIENR;                 /*!< Address offset: 0x08 */
  __IO uint32_t MWCR;                   /*!< Address offset: 0x0C */
  __IO uint32_t SER;                    /*!< Address offset: 0x10 */
  __IO uint32_t BAUDR;                  /*!< Address offset: 0x14 */
  __IO uint32_t TXFTLR;                 /*!< Address offset: 0x18 */
  __IO uint32_t RXFTLR;                 /*!< Address offset: 0x1C */
  __IO uint32_t TXFLR;                  /*!< Address offset: 0x20 */
  __IO uint32_t RXFLR;                  /*!< Address offset: 0x24 */
  __IO uint32_t SR;                     /*!< Address offset: 0x28 */
  __IO uint32_t IMR;                    /*!< Address offset: 0x2C */
  __IO uint32_t ISR;                    /*!< Address offset: 0x30 */
  __IO uint32_t RISR;                   /*!< Address offset: 0x34 */
  __IO uint32_t TXOICR;                 /*!< Address offset: 0x38 */
  __IO uint32_t RXOICR;                 /*!< Address offset: 0x3C */
  __IO uint32_t RXUICR;                 /*!< Address offset: 0x40 */
  __IO uint32_t MSTICR;                 /*!< Address offset: 0x44 */
  __IO uint32_t ICR;                    /*!< Address offset: 0x48 */
  __IO uint32_t DMACR;                  /*!< Address offset: 0x4C */
  __IO uint32_t DMATDLR;                /*!< Address offset: 0x50 */
  __IO uint32_t DMARDLR;                /*!< Address offset: 0x54 */
       uint32_t RESERVED0[2];
  __IO uint32_t DR;                     /*!< Address offset: 0x60 */
} SPI_TypeDef;
    
/**
  * @brief SYSCFG Registers
  */
typedef struct
{
       uint32_t RESERVED0[9];
  __IO uint32_t SYS_CFG;                /*!< Address offset: 0x24 */
  __IO uint32_t IRQ_CFG_1;              /*!< Address offset: 0x28 */
  __IO uint32_t IRQ_CFG_2;              /*!< Address offset: 0x2C */
  __IO uint32_t DMA_CFG;                /*!< Address offset: 0x30 */
  __IO uint32_t WDT_CFG;                /*!< Address offset: 0x34 */
  __IO uint32_t SW_RST_CFG;             /*!< Address offset: 0x38 */
       uint32_t RESERVED1[1];
  __IO uint32_t TIMER_ADV_CFG;          /*!< Address offset: 0x40 */
       uint32_t RESERVED2[3];
  __IO uint32_t GPIO_ENAUX_A;           /*!< Address offset: 0x50 */
  __IO uint32_t GPIO_ENAUX_B;           /*!< Address offset: 0x54 */
  __IO uint32_t GPIO_ENAUX_C;           /*!< Address offset: 0x58 */
  __IO uint32_t GPIO_ENAUX_D;           /*!< Address offset: 0x5C */
       uint32_t RESERVED3[37];
  __IO uint32_t UID_REG_0;              /*!< Address offset: 0xF4 */
  __IO uint32_t UID_REG_1;              /*!< Address offset: 0xF8 */
  __IO uint32_t UID_REG_2;              /*!< Address offset: 0xFC */
} SYSCFG_TypeDef;
    
/**
  * @brief TIM Registers
  */
typedef struct
{
  __IO uint32_t CTRL1;                    /*!< Address offset: 0x00 */
  __IO uint32_t CTRL2;                    /*!< Address offset: 0x04 */
  __IO uint32_t SLVMD;                   /*!< Address offset: 0x08 */
  __IO uint32_t REQEN;                   /*!< Address offset: 0x0C */
  __IO uint32_t STATUS;                     /*!< Address offset: 0x10 */
  __IO uint32_t EVT;                    /*!< Address offset: 0x14 */
  __IO uint32_t CHMD1;                  /*!< Address offset: 0x18 */
  __IO uint32_t CHMD2;                  /*!< Address offset: 0x1C */
  __IO uint32_t CHEP;                   /*!< Address offset: 0x20 */
  __IO uint32_t CNTR;                    /*!< Address offset: 0x24 */
  __IO uint32_t PSCR;                    /*!< Address offset: 0x28 */
  __IO uint32_t PRD;                    /*!< Address offset: 0x2C */
  __IO uint32_t REP;                    /*!< Address offset: 0x30 */
  __IO uint32_t CHR1;                   /*!< Address offset: 0x34 */
  __IO uint32_t CHR2;                   /*!< Address offset: 0x38 */
  __IO uint32_t CHR3;                   /*!< Address offset: 0x3C */
  __IO uint32_t CHR4;                   /*!< Address offset: 0x40 */
  __IO uint32_t BKDT;                   /*!< Address offset: 0x44 */
  __IO uint32_t DMAC;                    /*!< Address offset: 0x48 */
  __IO uint32_t DMAI;                   /*!< Address offset: 0x4C */
  __IO uint32_t AUX;                    /*!< Address offset: 0x50 */
  __IO uint32_t CHMD3;                  /*!< Address offset: 0x54 */
  __IO uint32_t CHR5;                   /*!< Address offset: 0x58 */
  __IO uint32_t CHR6;                   /*!< Address offset: 0x5C */
  __IO uint32_t BRK;                    /*!< Address offset: 0x60 */
  __IO uint32_t BRK2;                    /*!< Address offset: 0x64 */
  __IO uint32_t ISCLT;                  /*!< Address offset: 0x68 */
} TIM_TypeDef;
    
/**
  * @brief TIMR Registers
  */
typedef struct
{
  __IO uint32_t LC;                     /*!< Address offset: 0x00 */
  __IO uint32_t CV;                     /*!< Address offset: 0x04 */
  __IO uint32_t CR;                     /*!< Address offset: 0x08 */
  __IO uint32_t EOI;                    /*!< Address offset: 0x0C */
  __IO uint32_t STAT;                   /*!< Address offset: 0x10 */
} TIMR_TypeDef;
    
/**
  * @brief TIMRSYS Registers
  */
typedef struct
{
  __IO uint32_t STAT;                   /*!< Address offset: 0x00 */
  __IO uint32_t EOI;                    /*!< Address offset: 0x04 */
  __IO uint32_t RSTAT;                  /*!< Address offset: 0x08 */
} TIMRSYS_TypeDef;
    
/**
  * @brief UART Registers
  */
typedef struct
{
  __IO uint32_t RBR_THR_DLL;            /*!< Address offset: 0x00 */
  __IO uint32_t DLH_IER;                /*!< Address offset: 0x04 */
  __IO uint32_t IIR_FCR;                /*!< Address offset: 0x08 */
  __IO uint32_t LCR;                    /*!< Address offset: 0x0C */
  __IO uint32_t MCR;                    /*!< Address offset: 0x10 */
  __IO uint32_t LSR;                    /*!< Address offset: 0x14 */
  __IO uint32_t MSR;                    /*!< Address offset: 0x18 */
       uint32_t RESERVED0[24];
  __IO uint32_t USR;                    /*!< Address offset: 0x7C */
} UART_TypeDef;
    
/**
  * @brief WDT Registers
  */
typedef struct
{
  __IO uint32_t CR;                     /*!< Address offset: 0x00 */
  __IO uint32_t TORR;                   /*!< Address offset: 0x04 */
  __IO uint32_t CCVR;                   /*!< Address offset: 0x08 */
  __IO uint32_t CRR;                    /*!< Address offset: 0x0C */
  __IO uint32_t STAT;                   /*!< Address offset: 0x10 */
  __IO uint32_t EOI;                    /*!< Address offset: 0x14 */
} WDT_TypeDef;
    
/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

/*!< Memory base */
#define FLASH_BASE            (0x08000000)
#define ROM_BASE              (0x1FFF0000)
#define SRAM_BASE             (0x20000000)
#define PERIPH1_BASE          (0x40000000)
#define PERIPH2_BASE          (0x50000000)
#define SRAM_SIZE_MAX         (0x00008000)

/*!< Perioheral memory map */
#define APBPERIPH_BASE1       (PERIPH1_BASE)
#define APBPERIPH_BASE2       (PERIPH2_BASE)
#define AHBPERIPH_BASE        (0x80000000)
#define AHBPERIPH_BASE2       (0x80020000)

/*!< APB peripherals 1 */
#define SYSCFG_BASE           (APBPERIPH_BASE1 + 0x00000800)
#define WDTW_BASE             (APBPERIPH_BASE1 + 0x00000C00)
#define TIMA_BASE             (APBPERIPH_BASE1 + 0x00001000)
#define TIMB1_BASE            (APBPERIPH_BASE1 + 0x00001400)
#define TIMB2_BASE            (APBPERIPH_BASE1 + 0x00001500)
#define TIMG_BASE             (APBPERIPH_BASE1 + 0x00001800)
#define UART1_BASE            (APBPERIPH_BASE1 + 0x00001C00)
#define UART2_BASE            (APBPERIPH_BASE1 + 0x00001D00)
#define UART3_BASE            (APBPERIPH_BASE1 + 0x00001E00)
#define UART4_BASE            (APBPERIPH_BASE1 + 0x00001F00)
#define I2C1_BASE             (APBPERIPH_BASE1 + 0x00002000)
#define I2C2_BASE             (APBPERIPH_BASE1 + 0x00002100)
#define SPI1_BASE             (APBPERIPH_BASE1 + 0x00002400)
#define SPI2_BASE             (APBPERIPH_BASE1 + 0x00002500)
#define SPI3_BASE             (APBPERIPH_BASE1 + 0x00002600)
#define SPI4_BASE             (APBPERIPH_BASE1 + 0x00002700)
#define MDU_BASE              (APBPERIPH_BASE1 + 0x00002800)
#define WDTI_BASE             (APBPERIPH_BASE1 + 0x00003400)
#define RTC_BASE              (APBPERIPH_BASE1 + 0x00003500)
#define AON_BASE              (APBPERIPH_BASE1 + 0x00003600)

/*!< APB peripherals base timer */
#define TIMB1_1_BASE          (TIMB1_BASE + 0x00000000)
#define TIMB1_2_BASE          (TIMB1_BASE + 0x00000014)
#define TIMB1_3_BASE          (TIMB1_BASE + 0x00000028)
#define TIMB1_4_BASE          (TIMB1_BASE + 0x0000003C)
#define TIMB1_5_BASE          (TIMB1_BASE + 0x00000050)
#define TIMB1_6_BASE          (TIMB1_BASE + 0x00000064)
#define TIMB1_7_BASE          (TIMB1_BASE + 0x00000078)
#define TIMB1_8_BASE          (TIMB1_BASE + 0x0000008C)
#define TIMB1_SYS_BASE        (TIMB1_BASE + 0x000000A0)
#define TIMB2_1_BASE          (TIMB2_BASE + 0x00000000)
#define TIMB2_2_BASE          (TIMB2_BASE + 0x00000014)
#define TIMB2_3_BASE          (TIMB2_BASE + 0x00000028)
#define TIMB2_4_BASE          (TIMB2_BASE + 0x0000003C)
#define TIMB2_5_BASE          (TIMB2_BASE + 0x00000050)
#define TIMB2_6_BASE          (TIMB2_BASE + 0x00000064)
#define TIMB2_7_BASE          (TIMB2_BASE + 0x00000078)
#define TIMB2_8_BASE          (TIMB2_BASE + 0x0000008C)
#define TIMB2_SYS_BASE        (TIMB2_BASE + 0x000000A0)

/*!< APB peripherals 2 */
#define GPIOA_BASE            (APBPERIPH_BASE2 + 0x00000C00)
#define GPIOB_BASE            (APBPERIPH_BASE2 + 0x00000C0C)
#define GPIOC_BASE            (APBPERIPH_BASE2 + 0x00000C18)
#define GPIOD_BASE            (APBPERIPH_BASE2 + 0x00000C24)
#define GPIOAUX_BASE          (APBPERIPH_BASE2 + 0x00000C00)
#define PADI_BASE             (APBPERIPH_BASE2 + 0x00000800)

/*!< AHB peripherals 1 */
#define DMA1_BASE             (AHBPERIPH_BASE + 0x00000000)
#define DMAAUX1_BASE          (AHBPERIPH_BASE + 0x000002C0)
#define CLK_BASE              (AHBPERIPH_BASE + 0x00010000)
#define RST_BASE              (AHBPERIPH_BASE + 0x00020000)
#define INTC_BASE             (AHBPERIPH_BASE + 0x00030000)
#define CRC_BASE              (AHBPERIPH_BASE + 0x00050000)

/*!< AHB peripheral DMA channels */
#define DMA1_Channel0_BASE    (DMA1_BASE + 0x00000000)
#define DMA1_Channel1_BASE    (DMA1_BASE + 0x00000058)
#define DMA1_Channel2_BASE    (DMA1_BASE + 0x000000B0)
#define DMA1_Channel3_BASE    (DMA1_BASE + 0x00000108)
#define DMA1_Channel4_BASE    (DMA1_BASE + 0x00000160)
#define DMA1_Channel5_BASE    (DMA1_BASE + 0x000001B8)
#define DMA1_Channel6_BASE    (DMA1_BASE + 0x00000210)
#define DMA1_Channel7_BASE    (DMA1_BASE + 0x00000268)

/*!< Flash base */
#define FLASH_CODE_BASE       (FLASH_BASE + 0x00000000)
#define FLASH_DATA_BASE       (FLASH_BASE + 0x00040000)
#define FLASH_NVM_BASE        (FLASH_BASE + 0x00080000)
#define FLASH_NVMCFG_BASE     (FLASH_BASE + 0x00092000)
#define FLASH_REG_BASE        (FLASH_BASE + 0x000C0000)
#define FLASH_CODE_SIZE       (0x40000)
#define FLASH_DATA_SIZE       (0x20000)
#define FLASH_NVM_SIZE        (0x1000)
#define FLASH_NVMCFG_SIZE     (0x200 )
#define FLASH_SIZE            (FLASH_CODE_SIZE+FLASH_DATA_SIZE)

/*!< Device electronic signature */
#define PACKAGE_BASE          (FLASH_NVM_BASE + 0x1F00)
#define UID_BASE              (FLASH_NVM_BASE + 0x1F10)
#define FLASHSIZE_BASE        (FLASH_NVM_BASE + 0x1F20)

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */

/*!< APB 1 */
#define SYSCFG                ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define WDTW                  ((WDT_TypeDef *) WDTW_BASE  )
#define TIM1                  ((TIM_TypeDef *) TIMA_BASE  )
#define TIMG                  ((TIM_TypeDef *) TIMG_BASE  )
#define UART1                 ((UART_TypeDef *) UART1_BASE )
#define UART2                 ((UART_TypeDef *) UART2_BASE )
#define UART3                 ((UART_TypeDef *) UART3_BASE )
#define UART4                 ((UART_TypeDef *) UART4_BASE )
#define I2C1                  ((I2C_TypeDef *) I2C1_BASE  )
#define I2C2                  ((I2C_TypeDef *) I2C2_BASE  )
#define SPI1M                 ((SPI_TypeDef *) SPI1_BASE  )
#define SPI1S                 ((SPI_TypeDef *) SPI2_BASE  )
#define SPI2M                 ((SPI_TypeDef *) SPI3_BASE  )
#define SPI2S                 ((SPI_TypeDef *) SPI4_BASE  )
#define MDU                   ((MDU_TypeDef *) MDU_BASE   )
#define WDTI                  ((WDT_TypeDef *) WDTI_BASE)
#define RTC                   ((RTC_TypeDef *) RTC_BASE )
#define AON                   ((AON_TypeDef *) AON_BASE )
#define TIMB11                ((TIMR_TypeDef *) TIMB1_1_BASE)
#define TIMB12                ((TIMR_TypeDef *) TIMB1_2_BASE)
#define TIMB13                ((TIMR_TypeDef *) TIMB1_3_BASE)
#define TIMB14                ((TIMR_TypeDef *) TIMB1_4_BASE)
#define TIMSYSB1              ((TIMRSYS_TypeDef *) TIMB1_SYS_BASE)
#define TIMB21                ((TIMR_TypeDef *) TIMB2_1_BASE)
#define TIMB22                ((TIMR_TypeDef *) TIMB2_2_BASE)
#define TIMB23                ((TIMR_TypeDef *) TIMB2_3_BASE)
#define TIMB24                ((TIMR_TypeDef *) TIMB2_4_BASE)
#define TIMSYSB2              ((TIMRSYS_TypeDef *) TIMB2_SYS_BASE)

/*!< APB 2 */
#define GPIOA                 ((GPIO_TypeDef *) GPIOA_BASE  )
#define GPIOB                 ((GPIO_TypeDef *) GPIOB_BASE  )
#define GPIOC                 ((GPIO_TypeDef *) GPIOC_BASE  )
#define GPIOD                 ((GPIO_TypeDef *) GPIOD_BASE  )
#define GPIOAUX               ((GPIO_AUX_TypeDef *) GPIOAUX_BASE)
#define PADI                  ((PADI_TypeDef *) PADI_BASE)

/*!< AHB 1 */
#define DMA1                  ((DMA_TypeDef *) DMA1_BASE   )
#define DMAAUX1               ((DMA_TypeDef *) DMAAUX1_BASE)
#define ICG                   ((ICG_TypeDef *) CLK_BASE )
#define RST                   ((RST_TypeDef *) RST_BASE )
#define ICTL                  ((ICTL_TypeDef *) INTC_BASE)
#define CRC                   ((CRC_TypeDef *) CRC_BASE )
#define DMA1_Channel0         ((DMA_Channel_TypeDef *) DMA1_Channel0_BASE)
#define DMA1_Channel1         ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#define DMA1_Channel2         ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#define DMA1_Channel3         ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#define DMA1_Channel4         ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#define DMA1_Channel5         ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_Channel6         ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#define DMA1_Channel7         ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)

/*!< Flash 1 */
#define FLASH                 ((FLASH_TypeDef *) FLASH_REG_BASE   )

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */

  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*                                     AON                                    */
/*                                                                            */
/******************************************************************************/

/*********************  Bits definition for AON_AON_CFG  **********************/
#define AON_CFG_32KCLKSRC_Pos                               (0)
#define AON_CFG_32KCLKSRC_Msk                               (0x3UL << AON_CFG_32KCLKSRC_Pos)
#define AON_CFG_32KCLKSRC                                   AON_CFG_32KCLKSRC_Msk
#define AON_CFG_32KCLKSRC_0                                 (0x1UL << AON_CFG_32KCLKSRC_Pos)
#define AON_CFG_32KCLKSRC_1                                 (0x2UL << AON_CFG_32KCLKSRC_Pos)
#define AON_CFG_WDTI_SPD_Pos                                (28)
#define AON_CFG_WDTI_SPD_Msk                                (0x1UL << AON_CFG_WDTI_SPD_Pos)
#define AON_CFG_WDTI_SPD                                    AON_CFG_WDTI_SPD_Msk
#define AON_CFG_WDTI_EN_Pos                                 (30)
#define AON_CFG_WDTI_EN_Msk                                 (0x1UL << AON_CFG_WDTI_EN_Pos)
#define AON_CFG_WDTI_EN                                     AON_CFG_WDTI_EN_Msk
#define AON_CFG_RTCRST_Pos                                  (31)
#define AON_CFG_RTCRST_Msk                                  (0x1UL << AON_CFG_RTCRST_Pos)
#define AON_CFG_RTCRST                                      AON_CFG_RTCRST_Msk

/******************  Bits definition for AON_RTC_REFCLK_DIV  ******************/
#define AON_RTC_REFCLK_DIV_DIV_Pos                          (0)
#define AON_RTC_REFCLK_DIV_DIV_Msk                          (0xffffffffUL << AON_RTC_REFCLK_DIV_DIV_Pos)
#define AON_RTC_REFCLK_DIV_DIV                              AON_RTC_REFCLK_DIV_DIV_Msk

/*******************  Bits definition for AON_AON_CLK_CTRL  *******************/
#define AON_CLKCTRL_32KRC_PD_Pos                            (0)
#define AON_CLKCTRL_32KRC_PD_Msk                            (0x1UL << AON_CLKCTRL_32KRC_PD_Pos)
#define AON_CLKCTRL_32KRC_PD                                AON_CLKCTRL_32KRC_PD_Msk
#define AON_CLKCTRL_32KXTAL_PD_Pos                          (1)
#define AON_CLKCTRL_32KXTAL_PD_Msk                          (0x1UL << AON_CLKCTRL_32KXTAL_PD_Pos)
#define AON_CLKCTRL_32KXTAL_PD                              AON_CLKCTRL_32KXTAL_PD_Msk
#define AON_CLKCTRL_32KXTAL_ITUNE_Pos                       (8)
#define AON_CLKCTRL_32KXTAL_ITUNE_Msk                       (0xfUL << AON_CLKCTRL_32KXTAL_ITUNE_Pos)
#define AON_CLKCTRL_32KXTAL_ITUNE                           AON_CLKCTRL_32KXTAL_ITUNE_Msk
#define AON_CLKCTRL_32KXTAL_ITUNE_0                         (0x1UL << AON_CLKCTRL_32KXTAL_ITUNE_Pos)
#define AON_CLKCTRL_32KXTAL_ITUNE_1                         (0x2UL << AON_CLKCTRL_32KXTAL_ITUNE_Pos)
#define AON_CLKCTRL_32KXTAL_ITUNE_2                         (0x4UL << AON_CLKCTRL_32KXTAL_ITUNE_Pos)
#define AON_CLKCTRL_32KXTAL_ITUNE_3                         (0x8UL << AON_CLKCTRL_32KXTAL_ITUNE_Pos)
#define AON_CLKCTRL_32KXTAL_CAPTUNE_Pos                     (12)
#define AON_CLKCTRL_32KXTAL_CAPTUNE_Msk                     (0xfUL << AON_CLKCTRL_32KXTAL_CAPTUNE_Pos)
#define AON_CLKCTRL_32KXTAL_CAPTUNE                         AON_CLKCTRL_32KXTAL_CAPTUNE_Msk
#define AON_CLKCTRL_32KXTAL_CAPTUNE_0                       (0x1UL << AON_CLKCTRL_32KXTAL_CAPTUNE_Pos)
#define AON_CLKCTRL_32KXTAL_CAPTUNE_1                       (0x2UL << AON_CLKCTRL_32KXTAL_CAPTUNE_Pos)
#define AON_CLKCTRL_32KXTAL_CAPTUNE_2                       (0x4UL << AON_CLKCTRL_32KXTAL_CAPTUNE_Pos)
#define AON_CLKCTRL_32KXTAL_CAPTUNE_3                       (0x8UL << AON_CLKCTRL_32KXTAL_CAPTUNE_Pos)
#define AON_CLKCTRL_32KRC_RESTUNE_Pos                       (16)
#define AON_CLKCTRL_32KRC_RESTUNE_Msk                       (0x3fUL << AON_CLKCTRL_32KRC_RESTUNE_Pos)
#define AON_CLKCTRL_32KRC_RESTUNE                           AON_CLKCTRL_32KRC_RESTUNE_Msk
#define AON_CLKCTRL_32KRC_RESTUNE_0                         (0x1UL << AON_CLKCTRL_32KRC_RESTUNE_Pos)
#define AON_CLKCTRL_32KRC_RESTUNE_1                         (0x2UL << AON_CLKCTRL_32KRC_RESTUNE_Pos)
#define AON_CLKCTRL_32KRC_RESTUNE_2                         (0x4UL << AON_CLKCTRL_32KRC_RESTUNE_Pos)
#define AON_CLKCTRL_32KRC_RESTUNE_3                         (0x8UL << AON_CLKCTRL_32KRC_RESTUNE_Pos)
#define AON_CLKCTRL_32KRC_RESTUNE_4                         (0x10UL << AON_CLKCTRL_32KRC_RESTUNE_Pos)
#define AON_CLKCTRL_32KRC_RESTUNE_5                         (0x20UL << AON_CLKCTRL_32KRC_RESTUNE_Pos)

/*********************  Bits definition for AON_LDO_CFG  **********************/
#define AON_LDO_CFG_IVREF_PD_Pos                            (0)
#define AON_LDO_CFG_IVREF_PD_Msk                            (0x1UL << AON_LDO_CFG_IVREF_PD_Pos)
#define AON_LDO_CFG_IVREF_PD                                AON_LDO_CFG_IVREF_PD_Msk
#define AON_LDO_CFG_CORE_PD_Pos                             (1)
#define AON_LDO_CFG_CORE_PD_Msk                             (0x1UL << AON_LDO_CFG_CORE_PD_Pos)
#define AON_LDO_CFG_CORE_PD                                 AON_LDO_CFG_CORE_PD_Msk
#define AON_LDO_CFG_ANALOG_PD_Pos                           (2)
#define AON_LDO_CFG_ANALOG_PD_Msk                           (0x1UL << AON_LDO_CFG_ANALOG_PD_Pos)
#define AON_LDO_CFG_ANALOG_PD                               AON_LDO_CFG_ANALOG_PD_Msk
#define AON_LDO_CFG_IO_PD_Pos                               (3)
#define AON_LDO_CFG_IO_PD_Msk                               (0x1UL << AON_LDO_CFG_IO_PD_Pos)
#define AON_LDO_CFG_IO_PD                                   AON_LDO_CFG_IO_PD_Msk
#define AON_LDO_CFG_VOLDET_PD_Pos                           (5)
#define AON_LDO_CFG_VOLDET_PD_Msk                           (0x1UL << AON_LDO_CFG_VOLDET_PD_Pos)
#define AON_LDO_CFG_VOLDET_PD                               AON_LDO_CFG_VOLDET_PD_Msk
#define AON_LDO_CFG_VOLDET_TRG_Pos                          (8)
#define AON_LDO_CFG_VOLDET_TRG_Msk                          (0x1fUL << AON_LDO_CFG_VOLDET_TRG_Pos)
#define AON_LDO_CFG_VOLDET_TRG                              AON_LDO_CFG_VOLDET_TRG_Msk
#define AON_LDO_CFG_VOLDET_TRG_0                            (0x1UL << AON_LDO_CFG_VOLDET_TRG_Pos)
#define AON_LDO_CFG_VOLDET_TRG_1                            (0x2UL << AON_LDO_CFG_VOLDET_TRG_Pos)
#define AON_LDO_CFG_VOLDET_TRG_2                            (0x4UL << AON_LDO_CFG_VOLDET_TRG_Pos)
#define AON_LDO_CFG_VOLDET_TRG_3                            (0x8UL << AON_LDO_CFG_VOLDET_TRG_Pos)
#define AON_LDO_CFG_VOLDET_TRG_4                            (0x10UL << AON_LDO_CFG_VOLDET_TRG_Pos)
#define AON_LDO_CFG_CORE_OTUNE_Pos                          (16)
#define AON_LDO_CFG_CORE_OTUNE_Msk                          (0x7UL << AON_LDO_CFG_CORE_OTUNE_Pos)
#define AON_LDO_CFG_CORE_OTUNE                              AON_LDO_CFG_CORE_OTUNE_Msk
#define AON_LDO_CFG_CORE_OTUNE_0                            (0x1UL << AON_LDO_CFG_CORE_OTUNE_Pos)
#define AON_LDO_CFG_CORE_OTUNE_1                            (0x2UL << AON_LDO_CFG_CORE_OTUNE_Pos)
#define AON_LDO_CFG_CORE_OTUNE_2                            (0x4UL << AON_LDO_CFG_CORE_OTUNE_Pos)
#define AON_LDO_CFG_ANALOG_OTUNE_Pos                        (20)
#define AON_LDO_CFG_ANALOG_OTUNE_Msk                        (0x7UL << AON_LDO_CFG_ANALOG_OTUNE_Pos)
#define AON_LDO_CFG_ANALOG_OTUNE                            AON_LDO_CFG_ANALOG_OTUNE_Msk
#define AON_LDO_CFG_ANALOG_OTUNE_0                          (0x1UL << AON_LDO_CFG_ANALOG_OTUNE_Pos)
#define AON_LDO_CFG_ANALOG_OTUNE_1                          (0x2UL << AON_LDO_CFG_ANALOG_OTUNE_Pos)
#define AON_LDO_CFG_ANALOG_OTUNE_2                          (0x4UL << AON_LDO_CFG_ANALOG_OTUNE_Pos)
#define AON_LDO_CFG_IO_OTUNE_Pos                            (24)
#define AON_LDO_CFG_IO_OTUNE_Msk                            (0x7UL << AON_LDO_CFG_IO_OTUNE_Pos)
#define AON_LDO_CFG_IO_OTUNE                                AON_LDO_CFG_IO_OTUNE_Msk
#define AON_LDO_CFG_IO_OTUNE_0                              (0x1UL << AON_LDO_CFG_IO_OTUNE_Pos)
#define AON_LDO_CFG_IO_OTUNE_1                              (0x2UL << AON_LDO_CFG_IO_OTUNE_Pos)
#define AON_LDO_CFG_IO_OTUNE_2                              (0x4UL << AON_LDO_CFG_IO_OTUNE_Pos)

/*******************  Bits definition for AON_IVREF_CFG_3  ********************/
#define AON_IVREF_CFG_3_DAC_REF_Pos                         (0)
#define AON_IVREF_CFG_3_DAC_REF_Msk                         (0xfUL << AON_IVREF_CFG_3_DAC_REF_Pos)
#define AON_IVREF_CFG_3_DAC_REF                             AON_IVREF_CFG_3_DAC_REF_Msk
#define AON_IVREF_CFG_3_DAC_REF_0                           (0x1UL << AON_IVREF_CFG_3_DAC_REF_Pos)
#define AON_IVREF_CFG_3_DAC_REF_1                           (0x2UL << AON_IVREF_CFG_3_DAC_REF_Pos)
#define AON_IVREF_CFG_3_DAC_REF_2                           (0x4UL << AON_IVREF_CFG_3_DAC_REF_Pos)
#define AON_IVREF_CFG_3_DAC_REF_3                           (0x8UL << AON_IVREF_CFG_3_DAC_REF_Pos)
#define AON_IVREF_CFG_3_EFLASH_REF_Pos                      (4)
#define AON_IVREF_CFG_3_EFLASH_REF_Msk                      (0xfUL << AON_IVREF_CFG_3_EFLASH_REF_Pos)
#define AON_IVREF_CFG_3_EFLASH_REF                          AON_IVREF_CFG_3_EFLASH_REF_Msk
#define AON_IVREF_CFG_3_EFLASH_REF_0                        (0x1UL << AON_IVREF_CFG_3_EFLASH_REF_Pos)
#define AON_IVREF_CFG_3_EFLASH_REF_1                        (0x2UL << AON_IVREF_CFG_3_EFLASH_REF_Pos)
#define AON_IVREF_CFG_3_EFLASH_REF_2                        (0x4UL << AON_IVREF_CFG_3_EFLASH_REF_Pos)
#define AON_IVREF_CFG_3_EFLASH_REF_3                        (0x8UL << AON_IVREF_CFG_3_EFLASH_REF_Pos)
#define AON_IVREF_CFG_3_PVD_REF_Pos                         (8)
#define AON_IVREF_CFG_3_PVD_REF_Msk                         (0xfUL << AON_IVREF_CFG_3_PVD_REF_Pos)
#define AON_IVREF_CFG_3_PVD_REF                             AON_IVREF_CFG_3_PVD_REF_Msk
#define AON_IVREF_CFG_3_PVD_REF_0                           (0x1UL << AON_IVREF_CFG_3_PVD_REF_Pos)
#define AON_IVREF_CFG_3_PVD_REF_1                           (0x2UL << AON_IVREF_CFG_3_PVD_REF_Pos)
#define AON_IVREF_CFG_3_PVD_REF_2                           (0x4UL << AON_IVREF_CFG_3_PVD_REF_Pos)
#define AON_IVREF_CFG_3_PVD_REF_3                           (0x8UL << AON_IVREF_CFG_3_PVD_REF_Pos)
#define AON_IVREF_CFG_3_HSI_REF_Pos                         (12)
#define AON_IVREF_CFG_3_HSI_REF_Msk                         (0xfUL << AON_IVREF_CFG_3_HSI_REF_Pos)
#define AON_IVREF_CFG_3_HSI_REF                             AON_IVREF_CFG_3_HSI_REF_Msk
#define AON_IVREF_CFG_3_HSI_REF_0                           (0x1UL << AON_IVREF_CFG_3_HSI_REF_Pos)
#define AON_IVREF_CFG_3_HSI_REF_1                           (0x2UL << AON_IVREF_CFG_3_HSI_REF_Pos)
#define AON_IVREF_CFG_3_HSI_REF_2                           (0x4UL << AON_IVREF_CFG_3_HSI_REF_Pos)
#define AON_IVREF_CFG_3_HSI_REF_3                           (0x8UL << AON_IVREF_CFG_3_HSI_REF_Pos)
#define AON_IVREF_CFG_3_LDO_REF_Pos                         (16)
#define AON_IVREF_CFG_3_LDO_REF_Msk                         (0xfUL << AON_IVREF_CFG_3_LDO_REF_Pos)
#define AON_IVREF_CFG_3_LDO_REF                             AON_IVREF_CFG_3_LDO_REF_Msk
#define AON_IVREF_CFG_3_LDO_REF_0                           (0x1UL << AON_IVREF_CFG_3_LDO_REF_Pos)
#define AON_IVREF_CFG_3_LDO_REF_1                           (0x2UL << AON_IVREF_CFG_3_LDO_REF_Pos)
#define AON_IVREF_CFG_3_LDO_REF_2                           (0x4UL << AON_IVREF_CFG_3_LDO_REF_Pos)
#define AON_IVREF_CFG_3_LDO_REF_3                           (0x8UL << AON_IVREF_CFG_3_LDO_REF_Pos)
#define AON_IVREF_CFG_3_LDO_BIAS_Pos                        (20)
#define AON_IVREF_CFG_3_LDO_BIAS_Msk                        (0xfUL << AON_IVREF_CFG_3_LDO_BIAS_Pos)
#define AON_IVREF_CFG_3_LDO_BIAS                            AON_IVREF_CFG_3_LDO_BIAS_Msk
#define AON_IVREF_CFG_3_LDO_BIAS_0                          (0x1UL << AON_IVREF_CFG_3_LDO_BIAS_Pos)
#define AON_IVREF_CFG_3_LDO_BIAS_1                          (0x2UL << AON_IVREF_CFG_3_LDO_BIAS_Pos)
#define AON_IVREF_CFG_3_LDO_BIAS_2                          (0x4UL << AON_IVREF_CFG_3_LDO_BIAS_Pos)
#define AON_IVREF_CFG_3_LDO_BIAS_3                          (0x8UL << AON_IVREF_CFG_3_LDO_BIAS_Pos)

/******************  Bits definition for AON_DEEPSLEEP_TIME  ******************/
#define AON_DEEPSLEEP_TIME_TIME_Pos                         (0)
#define AON_DEEPSLEEP_TIME_TIME_Msk                         (0xffffffffUL << AON_DEEPSLEEP_TIME_TIME_Pos)
#define AON_DEEPSLEEP_TIME_TIME                             AON_DEEPSLEEP_TIME_TIME_Msk

/******************  Bits definition for AON_DEEPSLEEP_CTRL  ******************/
#define AON_DEEPSLEEP_CTRL_MODE_Pos                         (0)
#define AON_DEEPSLEEP_CTRL_MODE_Msk                         (0x1UL << AON_DEEPSLEEP_CTRL_MODE_Pos)
#define AON_DEEPSLEEP_CTRL_MODE                             AON_DEEPSLEEP_CTRL_MODE_Msk

/******************************************************************************/
/*                                                                            */
/*                                     CRC                                    */
/*                                                                            */
/******************************************************************************/

/***********************  Bits definition for CRC_CFG  ************************/
#define CRC_CFG_REFLECT_Pos                                 (0)
#define CRC_CFG_REFLECT_Msk                                 (0x1UL << CRC_CFG_REFLECT_Pos)
#define CRC_CFG_REFLECT                                     CRC_CFG_REFLECT_Msk
#define CRC_CFG_XOR_EN_Pos                                  (1)
#define CRC_CFG_XOR_EN_Msk                                  (0x1UL << CRC_CFG_XOR_EN_Pos)
#define CRC_CFG_XOR_EN                                      CRC_CFG_XOR_EN_Msk
#define CRC_CFG_POLY_Pos                                    (4)
#define CRC_CFG_POLY_Msk                                    (0x3UL << CRC_CFG_POLY_Pos)
#define CRC_CFG_POLY                                        CRC_CFG_POLY_Msk
#define CRC_CFG_POLY_0                                      (0x1UL << CRC_CFG_POLY_Pos)
#define CRC_CFG_POLY_1                                      (0x2UL << CRC_CFG_POLY_Pos)

/***********************  Bits definition for CRC_DATA  ***********************/
#define CRC_DATA_SRC_DATA_0_Pos                             (0)
#define CRC_DATA_SRC_DATA_0_Msk                             (0xffUL << CRC_DATA_SRC_DATA_0_Pos)
#define CRC_DATA_SRC_DATA_0                                 CRC_DATA_SRC_DATA_0_Msk
#define CRC_DATA_SRC_DATA_1_Pos                             (8)
#define CRC_DATA_SRC_DATA_1_Msk                             (0xffUL << CRC_DATA_SRC_DATA_1_Pos)
#define CRC_DATA_SRC_DATA_1                                 CRC_DATA_SRC_DATA_1_Msk
#define CRC_DATA_SRC_DATA_2_Pos                             (16)
#define CRC_DATA_SRC_DATA_2_Msk                             (0xffUL << CRC_DATA_SRC_DATA_2_Pos)
#define CRC_DATA_SRC_DATA_2                                 CRC_DATA_SRC_DATA_2_Msk
#define CRC_DATA_SRC_DATA_3_Pos                             (24)
#define CRC_DATA_SRC_DATA_3_Msk                             (0xffUL << CRC_DATA_SRC_DATA_3_Pos)
#define CRC_DATA_SRC_DATA_3                                 CRC_DATA_SRC_DATA_3_Msk

/**********************  Bits definition for CRC_RESULT  **********************/
#define CRC_RESULT_RES_INIT_0_Pos                           (0)
#define CRC_RESULT_RES_INIT_0_Msk                           (0xffUL << CRC_RESULT_RES_INIT_0_Pos)
#define CRC_RESULT_RES_INIT_0                               CRC_RESULT_RES_INIT_0_Msk
#define CRC_RESULT_RES_INIT_1_Pos                           (8)
#define CRC_RESULT_RES_INIT_1_Msk                           (0xffUL << CRC_RESULT_RES_INIT_1_Pos)
#define CRC_RESULT_RES_INIT_1                               CRC_RESULT_RES_INIT_1_Msk
#define CRC_RESULT_RES_INIT_2_Pos                           (16)
#define CRC_RESULT_RES_INIT_2_Msk                           (0xffUL << CRC_RESULT_RES_INIT_2_Pos)
#define CRC_RESULT_RES_INIT_2                               CRC_RESULT_RES_INIT_2_Msk
#define CRC_RESULT_RES_INIT_3_Pos                           (24)
#define CRC_RESULT_RES_INIT_3_Msk                           (0xffUL << CRC_RESULT_RES_INIT_3_Pos)
#define CRC_RESULT_RES_INIT_3                               CRC_RESULT_RES_INIT_3_Msk

/*********************  Bits definition for CRC_XORVALUE  *********************/
#define CRC_XOR_XOR_MASK_0_Pos                              (0)
#define CRC_XOR_XOR_MASK_0_Msk                              (0xffUL << CRC_XOR_XOR_MASK_0_Pos)
#define CRC_XOR_XOR_MASK_0                                  CRC_XOR_XOR_MASK_0_Msk
#define CRC_XOR_XOR_MASK_1_Pos                              (8)
#define CRC_XOR_XOR_MASK_1_Msk                              (0xffUL << CRC_XOR_XOR_MASK_1_Pos)
#define CRC_XOR_XOR_MASK_1                                  CRC_XOR_XOR_MASK_1_Msk
#define CRC_XOR_XOR_MASK_2_Pos                              (16)
#define CRC_XOR_XOR_MASK_2_Msk                              (0xffUL << CRC_XOR_XOR_MASK_2_Pos)
#define CRC_XOR_XOR_MASK_2                                  CRC_XOR_XOR_MASK_2_Msk
#define CRC_XOR_XOR_MASK_3_Pos                              (24)
#define CRC_XOR_XOR_MASK_3_Msk                              (0xffUL << CRC_XOR_XOR_MASK_3_Pos)
#define CRC_XOR_XOR_MASK_3                                  CRC_XOR_XOR_MASK_3_Msk

/******************************************************************************/
/*                                                                            */
/*                                   DMA CH                                   */
/*                                                                            */
/******************************************************************************/

/**********************  Bits definition for DMA_CH_SAR  **********************/
#define DMA_CH_SAR_SAR_Pos                                  (0)
#define DMA_CH_SAR_SAR_Msk                                  (0xffffffffUL << DMA_CH_SAR_SAR_Pos)
#define DMA_CH_SAR_SAR                                      DMA_CH_SAR_SAR_Msk

/**********************  Bits definition for DMA_CH_DAR  **********************/
#define DMA_CH_DAR_DAR_Pos                                  (0)
#define DMA_CH_DAR_DAR_Msk                                  (0xffffffffUL << DMA_CH_DAR_DAR_Pos)
#define DMA_CH_DAR_DAR                                      DMA_CH_DAR_DAR_Msk

/*********************  Bits definition for DMA_CH_CTL_L  *********************/
#define DMA_CH_CHCTL_INTEN_Pos                              (0)
#define DMA_CH_CHCTL_INTEN_Msk                              (0x1UL << DMA_CH_CHCTL_INTEN_Pos)
#define DMA_CH_CHCTL_INTEN                                  DMA_CH_CHCTL_INTEN_Msk
#define DMA_CH_CHCTL_DSTTRW_Pos                             (1)
#define DMA_CH_CHCTL_DSTTRW_Msk                             (0x7UL << DMA_CH_CHCTL_DSTTRW_Pos)
#define DMA_CH_CHCTL_DSTTRW                                 DMA_CH_CHCTL_DSTTRW_Msk
#define DMA_CH_CHCTL_DSTTRW_0                               (0x1UL << DMA_CH_CHCTL_DSTTRW_Pos)
#define DMA_CH_CHCTL_DSTTRW_1                               (0x2UL << DMA_CH_CHCTL_DSTTRW_Pos)
#define DMA_CH_CHCTL_DSTTRW_2                               (0x4UL << DMA_CH_CHCTL_DSTTRW_Pos)
#define DMA_CH_CHCTL_SRCTRW_Pos                             (4)
#define DMA_CH_CHCTL_SRCTRW_Msk                             (0x7UL << DMA_CH_CHCTL_SRCTRW_Pos)
#define DMA_CH_CHCTL_SRCTRW                                 DMA_CH_CHCTL_SRCTRW_Msk
#define DMA_CH_CHCTL_SRCTRW_0                               (0x1UL << DMA_CH_CHCTL_SRCTRW_Pos)
#define DMA_CH_CHCTL_SRCTRW_1                               (0x2UL << DMA_CH_CHCTL_SRCTRW_Pos)
#define DMA_CH_CHCTL_SRCTRW_2                               (0x4UL << DMA_CH_CHCTL_SRCTRW_Pos)
#define DMA_CH_CHCTL_DINC_Pos                               (7)
#define DMA_CH_CHCTL_DINC_Msk                               (0x3UL << DMA_CH_CHCTL_DINC_Pos)
#define DMA_CH_CHCTL_DINC                                   DMA_CH_CHCTL_DINC_Msk
#define DMA_CH_CHCTL_DINC_0                                 (0x1UL << DMA_CH_CHCTL_DINC_Pos)
#define DMA_CH_CHCTL_DINC_1                                 (0x2UL << DMA_CH_CHCTL_DINC_Pos)
#define DMA_CH_CHCTL_SINC_Pos                               (9)
#define DMA_CH_CHCTL_SINC_Msk                               (0x3UL << DMA_CH_CHCTL_SINC_Pos)
#define DMA_CH_CHCTL_SINC                                   DMA_CH_CHCTL_SINC_Msk
#define DMA_CH_CHCTL_SINC_0                                 (0x1UL << DMA_CH_CHCTL_SINC_Pos)
#define DMA_CH_CHCTL_SINC_1                                 (0x2UL << DMA_CH_CHCTL_SINC_Pos)
#define DMA_CH_CHCTL_DSTMSIZE_Pos                           (11)
#define DMA_CH_CHCTL_DSTMSIZE_Msk                           (0x7UL << DMA_CH_CHCTL_DSTMSIZE_Pos)
#define DMA_CH_CHCTL_DSTMSIZE                               DMA_CH_CHCTL_DSTMSIZE_Msk
#define DMA_CH_CHCTL_DSTMSIZE_0                             (0x1UL << DMA_CH_CHCTL_DSTMSIZE_Pos)
#define DMA_CH_CHCTL_DSTMSIZE_1                             (0x2UL << DMA_CH_CHCTL_DSTMSIZE_Pos)
#define DMA_CH_CHCTL_DSTMSIZE_2                             (0x4UL << DMA_CH_CHCTL_DSTMSIZE_Pos)
#define DMA_CH_CHCTL_SRCMSIZE_Pos                           (14)
#define DMA_CH_CHCTL_SRCMSIZE_Msk                           (0x7UL << DMA_CH_CHCTL_SRCMSIZE_Pos)
#define DMA_CH_CHCTL_SRCMSIZE                               DMA_CH_CHCTL_SRCMSIZE_Msk
#define DMA_CH_CHCTL_SRCMSIZE_0                             (0x1UL << DMA_CH_CHCTL_SRCMSIZE_Pos)
#define DMA_CH_CHCTL_SRCMSIZE_1                             (0x2UL << DMA_CH_CHCTL_SRCMSIZE_Pos)
#define DMA_CH_CHCTL_SRCMSIZE_2                             (0x4UL << DMA_CH_CHCTL_SRCMSIZE_Pos)
#define DMA_CH_CHCTL_TTFC_Pos                               (20)
#define DMA_CH_CHCTL_TTFC_Msk                               (0x7UL << DMA_CH_CHCTL_TTFC_Pos)
#define DMA_CH_CHCTL_TTFC                                   DMA_CH_CHCTL_TTFC_Msk
#define DMA_CH_CHCTL_TTFC_0                                 (0x1UL << DMA_CH_CHCTL_TTFC_Pos)
#define DMA_CH_CHCTL_TTFC_1                                 (0x2UL << DMA_CH_CHCTL_TTFC_Pos)
#define DMA_CH_CHCTL_TTFC_2                                 (0x4UL << DMA_CH_CHCTL_TTFC_Pos)

/*********************  Bits definition for DMA_CH_CTL_H  *********************/
#define DMA_CH_CHCTL_BLOCKTS_Pos                            (0)
#define DMA_CH_CHCTL_BLOCKTS_Msk                            (0xffUL << DMA_CH_CHCTL_BLOCKTS_Pos)
#define DMA_CH_CHCTL_BLOCKTS                                DMA_CH_CHCTL_BLOCKTS_Msk
#define DMA_CH_CHCTL_DONE_Pos                               (12)
#define DMA_CH_CHCTL_DONE_Msk                               (0x1UL << DMA_CH_CHCTL_DONE_Pos)
#define DMA_CH_CHCTL_DONE                                   DMA_CH_CHCTL_DONE_Msk

/*********************  Bits definition for DMA_CH_CFG_L  *********************/
#define DMA_CH_CHCFG_PRIOR_Pos                              (5)
#define DMA_CH_CHCFG_PRIOR_Msk                              (0x7UL << DMA_CH_CHCFG_PRIOR_Pos)
#define DMA_CH_CHCFG_PRIOR                                  DMA_CH_CHCFG_PRIOR_Msk
#define DMA_CH_CHCFG_PRIOR_0                                (0x1UL << DMA_CH_CHCFG_PRIOR_Pos)
#define DMA_CH_CHCFG_PRIOR_1                                (0x2UL << DMA_CH_CHCFG_PRIOR_Pos)
#define DMA_CH_CHCFG_PRIOR_2                                (0x4UL << DMA_CH_CHCFG_PRIOR_Pos)
#define DMA_CH_CHCFG_SUSP_Pos                               (8)
#define DMA_CH_CHCFG_SUSP_Msk                               (0x1UL << DMA_CH_CHCFG_SUSP_Pos)
#define DMA_CH_CHCFG_SUSP                                   DMA_CH_CHCFG_SUSP_Msk
#define DMA_CH_CHCFG_FIFOE_Pos                              (9)
#define DMA_CH_CHCFG_FIFOE_Msk                              (0x1UL << DMA_CH_CHCFG_FIFOE_Pos)
#define DMA_CH_CHCFG_FIFOE                                  DMA_CH_CHCFG_FIFOE_Msk
#define DMA_CH_CHCFG_DSTHS_Pos                              (10)
#define DMA_CH_CHCFG_DSTHS_Msk                              (0x1UL << DMA_CH_CHCFG_DSTHS_Pos)
#define DMA_CH_CHCFG_DSTHS                                  DMA_CH_CHCFG_DSTHS_Msk
#define DMA_CH_CHCFG_SRCHS_Pos                              (11)
#define DMA_CH_CHCFG_SRCHS_Msk                              (0x1UL << DMA_CH_CHCFG_SRCHS_Pos)
#define DMA_CH_CHCFG_SRCHS                                  DMA_CH_CHCFG_SRCHS_Msk
#define DMA_CH_CHCFG_DSTHSPOL_Pos                           (18)
#define DMA_CH_CHCFG_DSTHSPOL_Msk                           (0x1UL << DMA_CH_CHCFG_DSTHSPOL_Pos)
#define DMA_CH_CHCFG_DSTHSPOL                               DMA_CH_CHCFG_DSTHSPOL_Msk
#define DMA_CH_CHCFG_SRCHSPOL_Pos                           (19)
#define DMA_CH_CHCFG_SRCHSPOL_Msk                           (0x1UL << DMA_CH_CHCFG_SRCHSPOL_Pos)
#define DMA_CH_CHCFG_SRCHSPOL                               DMA_CH_CHCFG_SRCHSPOL_Msk
#define DMA_CH_CHCFG_RELDSRC_Pos                            (30)
#define DMA_CH_CHCFG_RELDSRC_Msk                            (0x1UL << DMA_CH_CHCFG_RELDSRC_Pos)
#define DMA_CH_CHCFG_RELDSRC                                DMA_CH_CHCFG_RELDSRC_Msk
#define DMA_CH_CHCFG_RELDDST_Pos                            (31)
#define DMA_CH_CHCFG_RELDDST_Msk                            (0x1UL << DMA_CH_CHCFG_RELDDST_Pos)
#define DMA_CH_CHCFG_RELDDST                                DMA_CH_CHCFG_RELDDST_Msk

/*********************  Bits definition for DMA_CH_CFG_H  *********************/
#define DMA_CH_CHCFG_FCMODE_Pos                             (0)
#define DMA_CH_CHCFG_FCMODE_Msk                             (0x1UL << DMA_CH_CHCFG_FCMODE_Pos)
#define DMA_CH_CHCFG_FCMODE                                 DMA_CH_CHCFG_FCMODE_Msk
#define DMA_CH_CHCFG_SRCPER_Pos                             (7)
#define DMA_CH_CHCFG_SRCPER_Msk                             (0xfUL << DMA_CH_CHCFG_SRCPER_Pos)
#define DMA_CH_CHCFG_SRCPER                                 DMA_CH_CHCFG_SRCPER_Msk
#define DMA_CH_CHCFG_SRCPER_0                               (0x1UL << DMA_CH_CHCFG_SRCPER_Pos)
#define DMA_CH_CHCFG_SRCPER_1                               (0x2UL << DMA_CH_CHCFG_SRCPER_Pos)
#define DMA_CH_CHCFG_SRCPER_2                               (0x4UL << DMA_CH_CHCFG_SRCPER_Pos)
#define DMA_CH_CHCFG_SRCPER_3                               (0x8UL << DMA_CH_CHCFG_SRCPER_Pos)
#define DMA_CH_CHCFG_DSTPER_Pos                             (11)
#define DMA_CH_CHCFG_DSTPER_Msk                             (0xfUL << DMA_CH_CHCFG_DSTPER_Pos)
#define DMA_CH_CHCFG_DSTPER                                 DMA_CH_CHCFG_DSTPER_Msk
#define DMA_CH_CHCFG_DSTPER_0                               (0x1UL << DMA_CH_CHCFG_DSTPER_Pos)
#define DMA_CH_CHCFG_DSTPER_1                               (0x2UL << DMA_CH_CHCFG_DSTPER_Pos)
#define DMA_CH_CHCFG_DSTPER_2                               (0x4UL << DMA_CH_CHCFG_DSTPER_Pos)
#define DMA_CH_CHCFG_DSTPER_3                               (0x8UL << DMA_CH_CHCFG_DSTPER_Pos)

/******************************************************************************/
/*                                                                            */
/*                                     DMA                                    */
/*                                                                            */
/******************************************************************************/

/**********************  Bits definition for DMA_RAWTFR  **********************/
#define DMA_RAWTFR_CH_Pos                                   (0)
#define DMA_RAWTFR_CH_Msk                                   (0xffUL << DMA_RAWTFR_CH_Pos)
#define DMA_RAWTFR_CH                                       DMA_RAWTFR_CH_Msk
#define DMA_RAWTFR_CH_0                                     (0x1UL << DMA_RAWTFR_CH_Pos)
#define DMA_RAWTFR_CH_1                                     (0x2UL << DMA_RAWTFR_CH_Pos)
#define DMA_RAWTFR_CH_2                                     (0x4UL << DMA_RAWTFR_CH_Pos)
#define DMA_RAWTFR_CH_3                                     (0x8UL << DMA_RAWTFR_CH_Pos)
#define DMA_RAWTFR_CH_4                                     (0x10UL << DMA_RAWTFR_CH_Pos)
#define DMA_RAWTFR_CH_5                                     (0x20UL << DMA_RAWTFR_CH_Pos)
#define DMA_RAWTFR_CH_6                                     (0x40UL << DMA_RAWTFR_CH_Pos)
#define DMA_RAWTFR_CH_7                                     (0x80UL << DMA_RAWTFR_CH_Pos)

/*********************  Bits definition for DMA_RAWBLOCK  *********************/
#define DMA_RAWBLOCK_CH_Pos                                 (0)
#define DMA_RAWBLOCK_CH_Msk                                 (0xffUL << DMA_RAWBLOCK_CH_Pos)
#define DMA_RAWBLOCK_CH                                     DMA_RAWBLOCK_CH_Msk
#define DMA_RAWBLOCK_CH_0                                   (0x1UL << DMA_RAWBLOCK_CH_Pos)
#define DMA_RAWBLOCK_CH_1                                   (0x2UL << DMA_RAWBLOCK_CH_Pos)
#define DMA_RAWBLOCK_CH_2                                   (0x4UL << DMA_RAWBLOCK_CH_Pos)
#define DMA_RAWBLOCK_CH_3                                   (0x8UL << DMA_RAWBLOCK_CH_Pos)
#define DMA_RAWBLOCK_CH_4                                   (0x10UL << DMA_RAWBLOCK_CH_Pos)
#define DMA_RAWBLOCK_CH_5                                   (0x20UL << DMA_RAWBLOCK_CH_Pos)
#define DMA_RAWBLOCK_CH_6                                   (0x40UL << DMA_RAWBLOCK_CH_Pos)
#define DMA_RAWBLOCK_CH_7                                   (0x80UL << DMA_RAWBLOCK_CH_Pos)

/********************  Bits definition for DMA_RAWSRCTRAN  ********************/
#define DMA_RAWSRCTRAN_CH_Pos                               (0)
#define DMA_RAWSRCTRAN_CH_Msk                               (0xffUL << DMA_RAWSRCTRAN_CH_Pos)
#define DMA_RAWSRCTRAN_CH                                   DMA_RAWSRCTRAN_CH_Msk
#define DMA_RAWSRCTRAN_CH_0                                 (0x1UL << DMA_RAWSRCTRAN_CH_Pos)
#define DMA_RAWSRCTRAN_CH_1                                 (0x2UL << DMA_RAWSRCTRAN_CH_Pos)
#define DMA_RAWSRCTRAN_CH_2                                 (0x4UL << DMA_RAWSRCTRAN_CH_Pos)
#define DMA_RAWSRCTRAN_CH_3                                 (0x8UL << DMA_RAWSRCTRAN_CH_Pos)
#define DMA_RAWSRCTRAN_CH_4                                 (0x10UL << DMA_RAWSRCTRAN_CH_Pos)
#define DMA_RAWSRCTRAN_CH_5                                 (0x20UL << DMA_RAWSRCTRAN_CH_Pos)
#define DMA_RAWSRCTRAN_CH_6                                 (0x40UL << DMA_RAWSRCTRAN_CH_Pos)
#define DMA_RAWSRCTRAN_CH_7                                 (0x80UL << DMA_RAWSRCTRAN_CH_Pos)

/********************  Bits definition for DMA_RAWDSTTRAN  ********************/
#define DMA_RAWDSTTRAN_CH_Pos                               (0)
#define DMA_RAWDSTTRAN_CH_Msk                               (0xffUL << DMA_RAWDSTTRAN_CH_Pos)
#define DMA_RAWDSTTRAN_CH                                   DMA_RAWDSTTRAN_CH_Msk
#define DMA_RAWDSTTRAN_CH_0                                 (0x1UL << DMA_RAWDSTTRAN_CH_Pos)
#define DMA_RAWDSTTRAN_CH_1                                 (0x2UL << DMA_RAWDSTTRAN_CH_Pos)
#define DMA_RAWDSTTRAN_CH_2                                 (0x4UL << DMA_RAWDSTTRAN_CH_Pos)
#define DMA_RAWDSTTRAN_CH_3                                 (0x8UL << DMA_RAWDSTTRAN_CH_Pos)
#define DMA_RAWDSTTRAN_CH_4                                 (0x10UL << DMA_RAWDSTTRAN_CH_Pos)
#define DMA_RAWDSTTRAN_CH_5                                 (0x20UL << DMA_RAWDSTTRAN_CH_Pos)
#define DMA_RAWDSTTRAN_CH_6                                 (0x40UL << DMA_RAWDSTTRAN_CH_Pos)
#define DMA_RAWDSTTRAN_CH_7                                 (0x80UL << DMA_RAWDSTTRAN_CH_Pos)

/**********************  Bits definition for DMA_RAWERR  **********************/
#define DMA_RAWERR_CH_Pos                                   (0)
#define DMA_RAWERR_CH_Msk                                   (0xffUL << DMA_RAWERR_CH_Pos)
#define DMA_RAWERR_CH                                       DMA_RAWERR_CH_Msk
#define DMA_RAWERR_CH_0                                     (0x1UL << DMA_RAWERR_CH_Pos)
#define DMA_RAWERR_CH_1                                     (0x2UL << DMA_RAWERR_CH_Pos)
#define DMA_RAWERR_CH_2                                     (0x4UL << DMA_RAWERR_CH_Pos)
#define DMA_RAWERR_CH_3                                     (0x8UL << DMA_RAWERR_CH_Pos)
#define DMA_RAWERR_CH_4                                     (0x10UL << DMA_RAWERR_CH_Pos)
#define DMA_RAWERR_CH_5                                     (0x20UL << DMA_RAWERR_CH_Pos)
#define DMA_RAWERR_CH_6                                     (0x40UL << DMA_RAWERR_CH_Pos)
#define DMA_RAWERR_CH_7                                     (0x80UL << DMA_RAWERR_CH_Pos)

/*********************  Bits definition for DMA_STATTFR  **********************/
#define DMA_STATTFR_CH_Pos                                  (0)
#define DMA_STATTFR_CH_Msk                                  (0xffUL << DMA_STATTFR_CH_Pos)
#define DMA_STATTFR_CH                                      DMA_STATTFR_CH_Msk
#define DMA_STATTFR_CH_0                                    (0x1UL << DMA_STATTFR_CH_Pos)
#define DMA_STATTFR_CH_1                                    (0x2UL << DMA_STATTFR_CH_Pos)
#define DMA_STATTFR_CH_2                                    (0x4UL << DMA_STATTFR_CH_Pos)
#define DMA_STATTFR_CH_3                                    (0x8UL << DMA_STATTFR_CH_Pos)
#define DMA_STATTFR_CH_4                                    (0x10UL << DMA_STATTFR_CH_Pos)
#define DMA_STATTFR_CH_5                                    (0x20UL << DMA_STATTFR_CH_Pos)
#define DMA_STATTFR_CH_6                                    (0x40UL << DMA_STATTFR_CH_Pos)
#define DMA_STATTFR_CH_7                                    (0x80UL << DMA_STATTFR_CH_Pos)

/********************  Bits definition for DMA_STATBLOCK  *********************/
#define DMA_STATBLOCK_CH_Pos                                (0)
#define DMA_STATBLOCK_CH_Msk                                (0xffUL << DMA_STATBLOCK_CH_Pos)
#define DMA_STATBLOCK_CH                                    DMA_STATBLOCK_CH_Msk
#define DMA_STATBLOCK_CH_0                                  (0x1UL << DMA_STATBLOCK_CH_Pos)
#define DMA_STATBLOCK_CH_1                                  (0x2UL << DMA_STATBLOCK_CH_Pos)
#define DMA_STATBLOCK_CH_2                                  (0x4UL << DMA_STATBLOCK_CH_Pos)
#define DMA_STATBLOCK_CH_3                                  (0x8UL << DMA_STATBLOCK_CH_Pos)
#define DMA_STATBLOCK_CH_4                                  (0x10UL << DMA_STATBLOCK_CH_Pos)
#define DMA_STATBLOCK_CH_5                                  (0x20UL << DMA_STATBLOCK_CH_Pos)
#define DMA_STATBLOCK_CH_6                                  (0x40UL << DMA_STATBLOCK_CH_Pos)
#define DMA_STATBLOCK_CH_7                                  (0x80UL << DMA_STATBLOCK_CH_Pos)

/*******************  Bits definition for DMA_STATSRCTRAN  ********************/
#define DMA_STATSRCTRAN_CH_Pos                              (0)
#define DMA_STATSRCTRAN_CH_Msk                              (0xffUL << DMA_STATSRCTRAN_CH_Pos)
#define DMA_STATSRCTRAN_CH                                  DMA_STATSRCTRAN_CH_Msk
#define DMA_STATSRCTRAN_CH_0                                (0x1UL << DMA_STATSRCTRAN_CH_Pos)
#define DMA_STATSRCTRAN_CH_1                                (0x2UL << DMA_STATSRCTRAN_CH_Pos)
#define DMA_STATSRCTRAN_CH_2                                (0x4UL << DMA_STATSRCTRAN_CH_Pos)
#define DMA_STATSRCTRAN_CH_3                                (0x8UL << DMA_STATSRCTRAN_CH_Pos)
#define DMA_STATSRCTRAN_CH_4                                (0x10UL << DMA_STATSRCTRAN_CH_Pos)
#define DMA_STATSRCTRAN_CH_5                                (0x20UL << DMA_STATSRCTRAN_CH_Pos)
#define DMA_STATSRCTRAN_CH_6                                (0x40UL << DMA_STATSRCTRAN_CH_Pos)
#define DMA_STATSRCTRAN_CH_7                                (0x80UL << DMA_STATSRCTRAN_CH_Pos)

/*******************  Bits definition for DMA_STATDSTTRAN  ********************/
#define DMA_STATDSTTRAN_CH_Pos                              (0)
#define DMA_STATDSTTRAN_CH_Msk                              (0xffUL << DMA_STATDSTTRAN_CH_Pos)
#define DMA_STATDSTTRAN_CH                                  DMA_STATDSTTRAN_CH_Msk
#define DMA_STATDSTTRAN_CH_0                                (0x1UL << DMA_STATDSTTRAN_CH_Pos)
#define DMA_STATDSTTRAN_CH_1                                (0x2UL << DMA_STATDSTTRAN_CH_Pos)
#define DMA_STATDSTTRAN_CH_2                                (0x4UL << DMA_STATDSTTRAN_CH_Pos)
#define DMA_STATDSTTRAN_CH_3                                (0x8UL << DMA_STATDSTTRAN_CH_Pos)
#define DMA_STATDSTTRAN_CH_4                                (0x10UL << DMA_STATDSTTRAN_CH_Pos)
#define DMA_STATDSTTRAN_CH_5                                (0x20UL << DMA_STATDSTTRAN_CH_Pos)
#define DMA_STATDSTTRAN_CH_6                                (0x40UL << DMA_STATDSTTRAN_CH_Pos)
#define DMA_STATDSTTRAN_CH_7                                (0x80UL << DMA_STATDSTTRAN_CH_Pos)

/*********************  Bits definition for DMA_STATERR  **********************/
#define DMA_STATERR_CH_Pos                                  (0)
#define DMA_STATERR_CH_Msk                                  (0xffUL << DMA_STATERR_CH_Pos)
#define DMA_STATERR_CH                                      DMA_STATERR_CH_Msk
#define DMA_STATERR_CH_0                                    (0x1UL << DMA_STATERR_CH_Pos)
#define DMA_STATERR_CH_1                                    (0x2UL << DMA_STATERR_CH_Pos)
#define DMA_STATERR_CH_2                                    (0x4UL << DMA_STATERR_CH_Pos)
#define DMA_STATERR_CH_3                                    (0x8UL << DMA_STATERR_CH_Pos)
#define DMA_STATERR_CH_4                                    (0x10UL << DMA_STATERR_CH_Pos)
#define DMA_STATERR_CH_5                                    (0x20UL << DMA_STATERR_CH_Pos)
#define DMA_STATERR_CH_6                                    (0x40UL << DMA_STATERR_CH_Pos)
#define DMA_STATERR_CH_7                                    (0x80UL << DMA_STATERR_CH_Pos)

/**********************  Bits definition for DMA_MSKTFR  **********************/
#define DMA_MSKTFR_EN_Pos                                   (0)
#define DMA_MSKTFR_EN_Msk                                   (0xffUL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_EN                                       DMA_MSKTFR_EN_Msk
#define DMA_MSKTFR_EN_0                                     (0x1UL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_EN_1                                     (0x2UL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_EN_2                                     (0x4UL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_EN_3                                     (0x8UL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_EN_4                                     (0x10UL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_EN_5                                     (0x20UL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_EN_6                                     (0x40UL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_EN_7                                     (0x80UL << DMA_MSKTFR_EN_Pos)
#define DMA_MSKTFR_WE_Pos                                   (8)
#define DMA_MSKTFR_WE_Msk                                   (0xffUL << DMA_MSKTFR_WE_Pos)
#define DMA_MSKTFR_WE                                       DMA_MSKTFR_WE_Msk
#define DMA_MSKTFR_WE_0                                     (0x1UL << DMA_MSKTFR_WE_Pos)
#define DMA_MSKTFR_WE_1                                     (0x2UL << DMA_MSKTFR_WE_Pos)
#define DMA_MSKTFR_WE_2                                     (0x4UL << DMA_MSKTFR_WE_Pos)
#define DMA_MSKTFR_WE_3                                     (0x8UL << DMA_MSKTFR_WE_Pos)
#define DMA_MSKTFR_WE_4                                     (0x10UL << DMA_MSKTFR_WE_Pos)
#define DMA_MSKTFR_WE_5                                     (0x20UL << DMA_MSKTFR_WE_Pos)
#define DMA_MSKTFR_WE_6                                     (0x40UL << DMA_MSKTFR_WE_Pos)
#define DMA_MSKTFR_WE_7                                     (0x80UL << DMA_MSKTFR_WE_Pos)

/*********************  Bits definition for DMA_MSKBLOCK  *********************/
#define DMA_MSKBLOCK_EN_Pos                                 (0)
#define DMA_MSKBLOCK_EN_Msk                                 (0xffUL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_EN                                     DMA_MSKBLOCK_EN_Msk
#define DMA_MSKBLOCK_EN_0                                   (0x1UL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_EN_1                                   (0x2UL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_EN_2                                   (0x4UL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_EN_3                                   (0x8UL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_EN_4                                   (0x10UL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_EN_5                                   (0x20UL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_EN_6                                   (0x40UL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_EN_7                                   (0x80UL << DMA_MSKBLOCK_EN_Pos)
#define DMA_MSKBLOCK_WE_Pos                                 (8)
#define DMA_MSKBLOCK_WE_Msk                                 (0xffUL << DMA_MSKBLOCK_WE_Pos)
#define DMA_MSKBLOCK_WE                                     DMA_MSKBLOCK_WE_Msk
#define DMA_MSKBLOCK_WE_0                                   (0x1UL << DMA_MSKBLOCK_WE_Pos)
#define DMA_MSKBLOCK_WE_1                                   (0x2UL << DMA_MSKBLOCK_WE_Pos)
#define DMA_MSKBLOCK_WE_2                                   (0x4UL << DMA_MSKBLOCK_WE_Pos)
#define DMA_MSKBLOCK_WE_3                                   (0x8UL << DMA_MSKBLOCK_WE_Pos)
#define DMA_MSKBLOCK_WE_4                                   (0x10UL << DMA_MSKBLOCK_WE_Pos)
#define DMA_MSKBLOCK_WE_5                                   (0x20UL << DMA_MSKBLOCK_WE_Pos)
#define DMA_MSKBLOCK_WE_6                                   (0x40UL << DMA_MSKBLOCK_WE_Pos)
#define DMA_MSKBLOCK_WE_7                                   (0x80UL << DMA_MSKBLOCK_WE_Pos)

/********************  Bits definition for DMA_MSKSRCTRAN  ********************/
#define DMA_MSKSRCTRAN_EN_Pos                               (0)
#define DMA_MSKSRCTRAN_EN_Msk                               (0xffUL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_EN                                   DMA_MSKSRCTRAN_EN_Msk
#define DMA_MSKSRCTRAN_EN_0                                 (0x1UL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_EN_1                                 (0x2UL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_EN_2                                 (0x4UL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_EN_3                                 (0x8UL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_EN_4                                 (0x10UL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_EN_5                                 (0x20UL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_EN_6                                 (0x40UL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_EN_7                                 (0x80UL << DMA_MSKSRCTRAN_EN_Pos)
#define DMA_MSKSRCTRAN_WE_Pos                               (8)
#define DMA_MSKSRCTRAN_WE_Msk                               (0xffUL << DMA_MSKSRCTRAN_WE_Pos)
#define DMA_MSKSRCTRAN_WE                                   DMA_MSKSRCTRAN_WE_Msk
#define DMA_MSKSRCTRAN_WE_0                                 (0x1UL << DMA_MSKSRCTRAN_WE_Pos)
#define DMA_MSKSRCTRAN_WE_1                                 (0x2UL << DMA_MSKSRCTRAN_WE_Pos)
#define DMA_MSKSRCTRAN_WE_2                                 (0x4UL << DMA_MSKSRCTRAN_WE_Pos)
#define DMA_MSKSRCTRAN_WE_3                                 (0x8UL << DMA_MSKSRCTRAN_WE_Pos)
#define DMA_MSKSRCTRAN_WE_4                                 (0x10UL << DMA_MSKSRCTRAN_WE_Pos)
#define DMA_MSKSRCTRAN_WE_5                                 (0x20UL << DMA_MSKSRCTRAN_WE_Pos)
#define DMA_MSKSRCTRAN_WE_6                                 (0x40UL << DMA_MSKSRCTRAN_WE_Pos)
#define DMA_MSKSRCTRAN_WE_7                                 (0x80UL << DMA_MSKSRCTRAN_WE_Pos)

/********************  Bits definition for DMA_MSKDSTTRAN  ********************/
#define DMA_MSKDSTTRAN_EN_Pos                               (0)
#define DMA_MSKDSTTRAN_EN_Msk                               (0xffUL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_EN                                   DMA_MSKDSTTRAN_EN_Msk
#define DMA_MSKDSTTRAN_EN_0                                 (0x1UL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_EN_1                                 (0x2UL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_EN_2                                 (0x4UL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_EN_3                                 (0x8UL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_EN_4                                 (0x10UL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_EN_5                                 (0x20UL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_EN_6                                 (0x40UL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_EN_7                                 (0x80UL << DMA_MSKDSTTRAN_EN_Pos)
#define DMA_MSKDSTTRAN_WE_Pos                               (8)
#define DMA_MSKDSTTRAN_WE_Msk                               (0xffUL << DMA_MSKDSTTRAN_WE_Pos)
#define DMA_MSKDSTTRAN_WE                                   DMA_MSKDSTTRAN_WE_Msk
#define DMA_MSKDSTTRAN_WE_0                                 (0x1UL << DMA_MSKDSTTRAN_WE_Pos)
#define DMA_MSKDSTTRAN_WE_1                                 (0x2UL << DMA_MSKDSTTRAN_WE_Pos)
#define DMA_MSKDSTTRAN_WE_2                                 (0x4UL << DMA_MSKDSTTRAN_WE_Pos)
#define DMA_MSKDSTTRAN_WE_3                                 (0x8UL << DMA_MSKDSTTRAN_WE_Pos)
#define DMA_MSKDSTTRAN_WE_4                                 (0x10UL << DMA_MSKDSTTRAN_WE_Pos)
#define DMA_MSKDSTTRAN_WE_5                                 (0x20UL << DMA_MSKDSTTRAN_WE_Pos)
#define DMA_MSKDSTTRAN_WE_6                                 (0x40UL << DMA_MSKDSTTRAN_WE_Pos)
#define DMA_MSKDSTTRAN_WE_7                                 (0x80UL << DMA_MSKDSTTRAN_WE_Pos)

/**********************  Bits definition for DMA_MSKERR  **********************/
#define DMA_MSKERR_EN_Pos                                   (0)
#define DMA_MSKERR_EN_Msk                                   (0xffUL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_EN                                       DMA_MSKERR_EN_Msk
#define DMA_MSKERR_EN_0                                     (0x1UL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_EN_1                                     (0x2UL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_EN_2                                     (0x4UL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_EN_3                                     (0x8UL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_EN_4                                     (0x10UL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_EN_5                                     (0x20UL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_EN_6                                     (0x40UL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_EN_7                                     (0x80UL << DMA_MSKERR_EN_Pos)
#define DMA_MSKERR_WE_Pos                                   (8)
#define DMA_MSKERR_WE_Msk                                   (0xffUL << DMA_MSKERR_WE_Pos)
#define DMA_MSKERR_WE                                       DMA_MSKERR_WE_Msk
#define DMA_MSKERR_WE_0                                     (0x1UL << DMA_MSKERR_WE_Pos)
#define DMA_MSKERR_WE_1                                     (0x2UL << DMA_MSKERR_WE_Pos)
#define DMA_MSKERR_WE_2                                     (0x4UL << DMA_MSKERR_WE_Pos)
#define DMA_MSKERR_WE_3                                     (0x8UL << DMA_MSKERR_WE_Pos)
#define DMA_MSKERR_WE_4                                     (0x10UL << DMA_MSKERR_WE_Pos)
#define DMA_MSKERR_WE_5                                     (0x20UL << DMA_MSKERR_WE_Pos)
#define DMA_MSKERR_WE_6                                     (0x40UL << DMA_MSKERR_WE_Pos)
#define DMA_MSKERR_WE_7                                     (0x80UL << DMA_MSKERR_WE_Pos)

/**********************  Bits definition for DMA_CLRTFR  **********************/
#define DMA_CLRTFR_CH_Pos                                   (0)
#define DMA_CLRTFR_CH_Msk                                   (0xffUL << DMA_CLRTFR_CH_Pos)
#define DMA_CLRTFR_CH                                       DMA_CLRTFR_CH_Msk
#define DMA_CLRTFR_CH_0                                     (0x1UL << DMA_CLRTFR_CH_Pos)
#define DMA_CLRTFR_CH_1                                     (0x2UL << DMA_CLRTFR_CH_Pos)
#define DMA_CLRTFR_CH_2                                     (0x4UL << DMA_CLRTFR_CH_Pos)
#define DMA_CLRTFR_CH_3                                     (0x8UL << DMA_CLRTFR_CH_Pos)
#define DMA_CLRTFR_CH_4                                     (0x10UL << DMA_CLRTFR_CH_Pos)
#define DMA_CLRTFR_CH_5                                     (0x20UL << DMA_CLRTFR_CH_Pos)
#define DMA_CLRTFR_CH_6                                     (0x40UL << DMA_CLRTFR_CH_Pos)
#define DMA_CLRTFR_CH_7                                     (0x80UL << DMA_CLRTFR_CH_Pos)

/*********************  Bits definition for DMA_CLRBLOCK  *********************/
#define DMA_CLRBLOCK_CH_Pos                                 (0)
#define DMA_CLRBLOCK_CH_Msk                                 (0xffUL << DMA_CLRBLOCK_CH_Pos)
#define DMA_CLRBLOCK_CH                                     DMA_CLRBLOCK_CH_Msk
#define DMA_CLRBLOCK_CH_0                                   (0x1UL << DMA_CLRBLOCK_CH_Pos)
#define DMA_CLRBLOCK_CH_1                                   (0x2UL << DMA_CLRBLOCK_CH_Pos)
#define DMA_CLRBLOCK_CH_2                                   (0x4UL << DMA_CLRBLOCK_CH_Pos)
#define DMA_CLRBLOCK_CH_3                                   (0x8UL << DMA_CLRBLOCK_CH_Pos)
#define DMA_CLRBLOCK_CH_4                                   (0x10UL << DMA_CLRBLOCK_CH_Pos)
#define DMA_CLRBLOCK_CH_5                                   (0x20UL << DMA_CLRBLOCK_CH_Pos)
#define DMA_CLRBLOCK_CH_6                                   (0x40UL << DMA_CLRBLOCK_CH_Pos)
#define DMA_CLRBLOCK_CH_7                                   (0x80UL << DMA_CLRBLOCK_CH_Pos)

/********************  Bits definition for DMA_CLRSRCTRAN  ********************/
#define DMA_CLRSRCTRAN_CH_Pos                               (0)
#define DMA_CLRSRCTRAN_CH_Msk                               (0xffUL << DMA_CLRSRCTRAN_CH_Pos)
#define DMA_CLRSRCTRAN_CH                                   DMA_CLRSRCTRAN_CH_Msk
#define DMA_CLRSRCTRAN_CH_0                                 (0x1UL << DMA_CLRSRCTRAN_CH_Pos)
#define DMA_CLRSRCTRAN_CH_1                                 (0x2UL << DMA_CLRSRCTRAN_CH_Pos)
#define DMA_CLRSRCTRAN_CH_2                                 (0x4UL << DMA_CLRSRCTRAN_CH_Pos)
#define DMA_CLRSRCTRAN_CH_3                                 (0x8UL << DMA_CLRSRCTRAN_CH_Pos)
#define DMA_CLRSRCTRAN_CH_4                                 (0x10UL << DMA_CLRSRCTRAN_CH_Pos)
#define DMA_CLRSRCTRAN_CH_5                                 (0x20UL << DMA_CLRSRCTRAN_CH_Pos)
#define DMA_CLRSRCTRAN_CH_6                                 (0x40UL << DMA_CLRSRCTRAN_CH_Pos)
#define DMA_CLRSRCTRAN_CH_7                                 (0x80UL << DMA_CLRSRCTRAN_CH_Pos)

/********************  Bits definition for DMA_CLRDSTTRAN  ********************/
#define DMA_CLRDSTTRAN_CH_Pos                               (0)
#define DMA_CLRDSTTRAN_CH_Msk                               (0xffUL << DMA_CLRDSTTRAN_CH_Pos)
#define DMA_CLRDSTTRAN_CH                                   DMA_CLRDSTTRAN_CH_Msk
#define DMA_CLRDSTTRAN_CH_0                                 (0x1UL << DMA_CLRDSTTRAN_CH_Pos)
#define DMA_CLRDSTTRAN_CH_1                                 (0x2UL << DMA_CLRDSTTRAN_CH_Pos)
#define DMA_CLRDSTTRAN_CH_2                                 (0x4UL << DMA_CLRDSTTRAN_CH_Pos)
#define DMA_CLRDSTTRAN_CH_3                                 (0x8UL << DMA_CLRDSTTRAN_CH_Pos)
#define DMA_CLRDSTTRAN_CH_4                                 (0x10UL << DMA_CLRDSTTRAN_CH_Pos)
#define DMA_CLRDSTTRAN_CH_5                                 (0x20UL << DMA_CLRDSTTRAN_CH_Pos)
#define DMA_CLRDSTTRAN_CH_6                                 (0x40UL << DMA_CLRDSTTRAN_CH_Pos)
#define DMA_CLRDSTTRAN_CH_7                                 (0x80UL << DMA_CLRDSTTRAN_CH_Pos)

/**********************  Bits definition for DMA_CLRERR  **********************/
#define DMA_CLRERR_CH_Pos                                   (0)
#define DMA_CLRERR_CH_Msk                                   (0xffUL << DMA_CLRERR_CH_Pos)
#define DMA_CLRERR_CH                                       DMA_CLRERR_CH_Msk
#define DMA_CLRERR_CH_0                                     (0x1UL << DMA_CLRERR_CH_Pos)
#define DMA_CLRERR_CH_1                                     (0x2UL << DMA_CLRERR_CH_Pos)
#define DMA_CLRERR_CH_2                                     (0x4UL << DMA_CLRERR_CH_Pos)
#define DMA_CLRERR_CH_3                                     (0x8UL << DMA_CLRERR_CH_Pos)
#define DMA_CLRERR_CH_4                                     (0x10UL << DMA_CLRERR_CH_Pos)
#define DMA_CLRERR_CH_5                                     (0x20UL << DMA_CLRERR_CH_Pos)
#define DMA_CLRERR_CH_6                                     (0x40UL << DMA_CLRERR_CH_Pos)
#define DMA_CLRERR_CH_7                                     (0x80UL << DMA_CLRERR_CH_Pos)

/*********************  Bits definition for DMA_STATINT  **********************/
#define DMA_STATINT_TFR_Pos                                 (0)
#define DMA_STATINT_TFR_Msk                                 (0x1UL << DMA_STATINT_TFR_Pos)
#define DMA_STATINT_TFR                                     DMA_STATINT_TFR_Msk
#define DMA_STATINT_BLOCK_Pos                               (1)
#define DMA_STATINT_BLOCK_Msk                               (0x1UL << DMA_STATINT_BLOCK_Pos)
#define DMA_STATINT_BLOCK                                   DMA_STATINT_BLOCK_Msk
#define DMA_STATINT_SRCT_Pos                                (2)
#define DMA_STATINT_SRCT_Msk                                (0x1UL << DMA_STATINT_SRCT_Pos)
#define DMA_STATINT_SRCT                                    DMA_STATINT_SRCT_Msk
#define DMA_STATINT_DSTT_Pos                                (3)
#define DMA_STATINT_DSTT_Msk                                (0x1UL << DMA_STATINT_DSTT_Pos)
#define DMA_STATINT_DSTT                                    DMA_STATINT_DSTT_Msk
#define DMA_STATINT_ERR_Pos                                 (4)
#define DMA_STATINT_ERR_Msk                                 (0x1UL << DMA_STATINT_ERR_Pos)
#define DMA_STATINT_ERR                                     DMA_STATINT_ERR_Msk

/**********************  Bits definition for DMA_REQSRC  **********************/
#define DMA_REQSRC_EN_Pos                                   (0)
#define DMA_REQSRC_EN_Msk                                   (0xffUL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_EN                                       DMA_REQSRC_EN_Msk
#define DMA_REQSRC_EN_0                                     (0x1UL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_EN_1                                     (0x2UL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_EN_2                                     (0x4UL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_EN_3                                     (0x8UL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_EN_4                                     (0x10UL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_EN_5                                     (0x20UL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_EN_6                                     (0x40UL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_EN_7                                     (0x80UL << DMA_REQSRC_EN_Pos)
#define DMA_REQSRC_WE_Pos                                   (8)
#define DMA_REQSRC_WE_Msk                                   (0xffUL << DMA_REQSRC_WE_Pos)
#define DMA_REQSRC_WE                                       DMA_REQSRC_WE_Msk
#define DMA_REQSRC_WE_0                                     (0x1UL << DMA_REQSRC_WE_Pos)
#define DMA_REQSRC_WE_1                                     (0x2UL << DMA_REQSRC_WE_Pos)
#define DMA_REQSRC_WE_2                                     (0x4UL << DMA_REQSRC_WE_Pos)
#define DMA_REQSRC_WE_3                                     (0x8UL << DMA_REQSRC_WE_Pos)
#define DMA_REQSRC_WE_4                                     (0x10UL << DMA_REQSRC_WE_Pos)
#define DMA_REQSRC_WE_5                                     (0x20UL << DMA_REQSRC_WE_Pos)
#define DMA_REQSRC_WE_6                                     (0x40UL << DMA_REQSRC_WE_Pos)
#define DMA_REQSRC_WE_7                                     (0x80UL << DMA_REQSRC_WE_Pos)

/**********************  Bits definition for DMA_REQDST  **********************/
#define DMA_REQDST_EN_Pos                                   (0)
#define DMA_REQDST_EN_Msk                                   (0xffUL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_EN                                       DMA_REQDST_EN_Msk
#define DMA_REQDST_EN_0                                     (0x1UL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_EN_1                                     (0x2UL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_EN_2                                     (0x4UL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_EN_3                                     (0x8UL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_EN_4                                     (0x10UL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_EN_5                                     (0x20UL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_EN_6                                     (0x40UL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_EN_7                                     (0x80UL << DMA_REQDST_EN_Pos)
#define DMA_REQDST_WE_Pos                                   (8)
#define DMA_REQDST_WE_Msk                                   (0xffUL << DMA_REQDST_WE_Pos)
#define DMA_REQDST_WE                                       DMA_REQDST_WE_Msk
#define DMA_REQDST_WE_0                                     (0x1UL << DMA_REQDST_WE_Pos)
#define DMA_REQDST_WE_1                                     (0x2UL << DMA_REQDST_WE_Pos)
#define DMA_REQDST_WE_2                                     (0x4UL << DMA_REQDST_WE_Pos)
#define DMA_REQDST_WE_3                                     (0x8UL << DMA_REQDST_WE_Pos)
#define DMA_REQDST_WE_4                                     (0x10UL << DMA_REQDST_WE_Pos)
#define DMA_REQDST_WE_5                                     (0x20UL << DMA_REQDST_WE_Pos)
#define DMA_REQDST_WE_6                                     (0x40UL << DMA_REQDST_WE_Pos)
#define DMA_REQDST_WE_7                                     (0x80UL << DMA_REQDST_WE_Pos)

/********************  Bits definition for DMA_SGLREQSRC  *********************/
#define DMA_SGLREQSRC_EN_Pos                                (0)
#define DMA_SGLREQSRC_EN_Msk                                (0xffUL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_EN                                    DMA_SGLREQSRC_EN_Msk
#define DMA_SGLREQSRC_EN_0                                  (0x1UL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_EN_1                                  (0x2UL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_EN_2                                  (0x4UL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_EN_3                                  (0x8UL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_EN_4                                  (0x10UL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_EN_5                                  (0x20UL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_EN_6                                  (0x40UL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_EN_7                                  (0x80UL << DMA_SGLREQSRC_EN_Pos)
#define DMA_SGLREQSRC_WE_Pos                                (8)
#define DMA_SGLREQSRC_WE_Msk                                (0xffUL << DMA_SGLREQSRC_WE_Pos)
#define DMA_SGLREQSRC_WE                                    DMA_SGLREQSRC_WE_Msk
#define DMA_SGLREQSRC_WE_0                                  (0x1UL << DMA_SGLREQSRC_WE_Pos)
#define DMA_SGLREQSRC_WE_1                                  (0x2UL << DMA_SGLREQSRC_WE_Pos)
#define DMA_SGLREQSRC_WE_2                                  (0x4UL << DMA_SGLREQSRC_WE_Pos)
#define DMA_SGLREQSRC_WE_3                                  (0x8UL << DMA_SGLREQSRC_WE_Pos)
#define DMA_SGLREQSRC_WE_4                                  (0x10UL << DMA_SGLREQSRC_WE_Pos)
#define DMA_SGLREQSRC_WE_5                                  (0x20UL << DMA_SGLREQSRC_WE_Pos)
#define DMA_SGLREQSRC_WE_6                                  (0x40UL << DMA_SGLREQSRC_WE_Pos)
#define DMA_SGLREQSRC_WE_7                                  (0x80UL << DMA_SGLREQSRC_WE_Pos)

/********************  Bits definition for DMA_SGLREQDST  *********************/
#define DMA_SGLREQDST_EN_Pos                                (0)
#define DMA_SGLREQDST_EN_Msk                                (0xffUL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_EN                                    DMA_SGLREQDST_EN_Msk
#define DMA_SGLREQDST_EN_0                                  (0x1UL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_EN_1                                  (0x2UL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_EN_2                                  (0x4UL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_EN_3                                  (0x8UL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_EN_4                                  (0x10UL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_EN_5                                  (0x20UL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_EN_6                                  (0x40UL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_EN_7                                  (0x80UL << DMA_SGLREQDST_EN_Pos)
#define DMA_SGLREQDST_WE_Pos                                (8)
#define DMA_SGLREQDST_WE_Msk                                (0xffUL << DMA_SGLREQDST_WE_Pos)
#define DMA_SGLREQDST_WE                                    DMA_SGLREQDST_WE_Msk
#define DMA_SGLREQDST_WE_0                                  (0x1UL << DMA_SGLREQDST_WE_Pos)
#define DMA_SGLREQDST_WE_1                                  (0x2UL << DMA_SGLREQDST_WE_Pos)
#define DMA_SGLREQDST_WE_2                                  (0x4UL << DMA_SGLREQDST_WE_Pos)
#define DMA_SGLREQDST_WE_3                                  (0x8UL << DMA_SGLREQDST_WE_Pos)
#define DMA_SGLREQDST_WE_4                                  (0x10UL << DMA_SGLREQDST_WE_Pos)
#define DMA_SGLREQDST_WE_5                                  (0x20UL << DMA_SGLREQDST_WE_Pos)
#define DMA_SGLREQDST_WE_6                                  (0x40UL << DMA_SGLREQDST_WE_Pos)
#define DMA_SGLREQDST_WE_7                                  (0x80UL << DMA_SGLREQDST_WE_Pos)

/********************  Bits definition for DMA_LSTREQSRC  *********************/
#define DMA_LSTREQSRC_EN_Pos                                (0)
#define DMA_LSTREQSRC_EN_Msk                                (0xffUL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_EN                                    DMA_LSTREQSRC_EN_Msk
#define DMA_LSTREQSRC_EN_0                                  (0x1UL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_EN_1                                  (0x2UL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_EN_2                                  (0x4UL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_EN_3                                  (0x8UL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_EN_4                                  (0x10UL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_EN_5                                  (0x20UL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_EN_6                                  (0x40UL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_EN_7                                  (0x80UL << DMA_LSTREQSRC_EN_Pos)
#define DMA_LSTREQSRC_WE_Pos                                (8)
#define DMA_LSTREQSRC_WE_Msk                                (0xffUL << DMA_LSTREQSRC_WE_Pos)
#define DMA_LSTREQSRC_WE                                    DMA_LSTREQSRC_WE_Msk
#define DMA_LSTREQSRC_WE_0                                  (0x1UL << DMA_LSTREQSRC_WE_Pos)
#define DMA_LSTREQSRC_WE_1                                  (0x2UL << DMA_LSTREQSRC_WE_Pos)
#define DMA_LSTREQSRC_WE_2                                  (0x4UL << DMA_LSTREQSRC_WE_Pos)
#define DMA_LSTREQSRC_WE_3                                  (0x8UL << DMA_LSTREQSRC_WE_Pos)
#define DMA_LSTREQSRC_WE_4                                  (0x10UL << DMA_LSTREQSRC_WE_Pos)
#define DMA_LSTREQSRC_WE_5                                  (0x20UL << DMA_LSTREQSRC_WE_Pos)
#define DMA_LSTREQSRC_WE_6                                  (0x40UL << DMA_LSTREQSRC_WE_Pos)
#define DMA_LSTREQSRC_WE_7                                  (0x80UL << DMA_LSTREQSRC_WE_Pos)

/********************  Bits definition for DMA_LSTREQDST  *********************/
#define DMA_LSTREQDST_EN_Pos                                (0)
#define DMA_LSTREQDST_EN_Msk                                (0xffUL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_EN                                    DMA_LSTREQDST_EN_Msk
#define DMA_LSTREQDST_EN_0                                  (0x1UL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_EN_1                                  (0x2UL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_EN_2                                  (0x4UL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_EN_3                                  (0x8UL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_EN_4                                  (0x10UL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_EN_5                                  (0x20UL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_EN_6                                  (0x40UL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_EN_7                                  (0x80UL << DMA_LSTREQDST_EN_Pos)
#define DMA_LSTREQDST_WE_Pos                                (8)
#define DMA_LSTREQDST_WE_Msk                                (0xffUL << DMA_LSTREQDST_WE_Pos)
#define DMA_LSTREQDST_WE                                    DMA_LSTREQDST_WE_Msk
#define DMA_LSTREQDST_WE_0                                  (0x1UL << DMA_LSTREQDST_WE_Pos)
#define DMA_LSTREQDST_WE_1                                  (0x2UL << DMA_LSTREQDST_WE_Pos)
#define DMA_LSTREQDST_WE_2                                  (0x4UL << DMA_LSTREQDST_WE_Pos)
#define DMA_LSTREQDST_WE_3                                  (0x8UL << DMA_LSTREQDST_WE_Pos)
#define DMA_LSTREQDST_WE_4                                  (0x10UL << DMA_LSTREQDST_WE_Pos)
#define DMA_LSTREQDST_WE_5                                  (0x20UL << DMA_LSTREQDST_WE_Pos)
#define DMA_LSTREQDST_WE_6                                  (0x40UL << DMA_LSTREQDST_WE_Pos)
#define DMA_LSTREQDST_WE_7                                  (0x80UL << DMA_LSTREQDST_WE_Pos)

/**********************  Bits definition for DMA_DMACFG  **********************/
#define DMA_DMACFG_EN_Pos                                   (0)
#define DMA_DMACFG_EN_Msk                                   (0x1UL << DMA_DMACFG_EN_Pos)
#define DMA_DMACFG_EN                                       DMA_DMACFG_EN_Msk

/***********************  Bits definition for DMA_CHEN  ***********************/
#define DMA_CHEN_EN_Pos                                     (0)
#define DMA_CHEN_EN_Msk                                     (0xffUL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_EN                                         DMA_CHEN_EN_Msk
#define DMA_CHEN_EN_0                                       (0x1UL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_EN_1                                       (0x2UL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_EN_2                                       (0x4UL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_EN_3                                       (0x8UL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_EN_4                                       (0x10UL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_EN_5                                       (0x20UL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_EN_6                                       (0x40UL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_EN_7                                       (0x80UL << DMA_CHEN_EN_Pos)
#define DMA_CHEN_WE_Pos                                     (8)
#define DMA_CHEN_WE_Msk                                     (0xffUL << DMA_CHEN_WE_Pos)
#define DMA_CHEN_WE                                         DMA_CHEN_WE_Msk
#define DMA_CHEN_WE_0                                       (0x1UL << DMA_CHEN_WE_Pos)
#define DMA_CHEN_WE_1                                       (0x2UL << DMA_CHEN_WE_Pos)
#define DMA_CHEN_WE_2                                       (0x4UL << DMA_CHEN_WE_Pos)
#define DMA_CHEN_WE_3                                       (0x8UL << DMA_CHEN_WE_Pos)
#define DMA_CHEN_WE_4                                       (0x10UL << DMA_CHEN_WE_Pos)
#define DMA_CHEN_WE_5                                       (0x20UL << DMA_CHEN_WE_Pos)
#define DMA_CHEN_WE_6                                       (0x40UL << DMA_CHEN_WE_Pos)
#define DMA_CHEN_WE_7                                       (0x80UL << DMA_CHEN_WE_Pos)

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/

/**********************  Bits definition for FLASH_CTRL  **********************/
#define FLASH_CTRL_MODE_Pos                                 (0)
#define FLASH_CTRL_MODE_Msk                                 (0x7UL << FLASH_CTRL_MODE_Pos)
#define FLASH_CTRL_MODE                                     FLASH_CTRL_MODE_Msk
#define FLASH_CTRL_MODE_0                                   (0x1UL << FLASH_CTRL_MODE_Pos)
#define FLASH_CTRL_MODE_1                                   (0x2UL << FLASH_CTRL_MODE_Pos)
#define FLASH_CTRL_MODE_2                                   (0x4UL << FLASH_CTRL_MODE_Pos)
#define FLASH_CTRL_ERREORD_Pos                              (8)
#define FLASH_CTRL_ERREORD_Msk                              (0x3UL << FLASH_CTRL_ERREORD_Pos)
#define FLASH_CTRL_ERREORD                                  FLASH_CTRL_ERREORD_Msk
#define FLASH_CTRL_ERREORD_0                                (0x1UL << FLASH_CTRL_ERREORD_Pos)
#define FLASH_CTRL_ERREORD_1                                (0x2UL << FLASH_CTRL_ERREORD_Pos)
#define FLASH_CTRL_NVMCFG_Pos                               (12)
#define FLASH_CTRL_NVMCFG_Msk                               (0x1UL << FLASH_CTRL_NVMCFG_Pos)
#define FLASH_CTRL_NVMCFG                                   FLASH_CTRL_NVMCFG_Msk
#define FLASH_CTRL_VERRD_Pos                                (13)
#define FLASH_CTRL_VERRD_Msk                                (0x1UL << FLASH_CTRL_VERRD_Pos)
#define FLASH_CTRL_VERRD                                    FLASH_CTRL_VERRD_Msk
#define FLASH_CTRL_TEMEN_Pos                                (24)
#define FLASH_CTRL_TEMEN_Msk                                (0x1UL << FLASH_CTRL_TEMEN_Pos)
#define FLASH_CTRL_TEMEN                                    FLASH_CTRL_TEMEN_Msk
#define FLASH_CTRL_ARRDN_Pos                                (28)
#define FLASH_CTRL_ARRDN_Msk                                (0x3UL << FLASH_CTRL_ARRDN_Pos)
#define FLASH_CTRL_ARRDN                                    FLASH_CTRL_ARRDN_Msk
#define FLASH_CTRL_ARRDN_0                                  (0x1UL << FLASH_CTRL_ARRDN_Pos)
#define FLASH_CTRL_ARRDN_1                                  (0x2UL << FLASH_CTRL_ARRDN_Pos)
#define FLASH_CTRL_NVMCFGLK_Pos                             (30)
#define FLASH_CTRL_NVMCFGLK_Msk                             (0x1UL << FLASH_CTRL_NVMCFGLK_Pos)
#define FLASH_CTRL_NVMCFGLK                                 FLASH_CTRL_NVMCFGLK_Msk
#define FLASH_CTRL_PREPR_Pos                                (31)
#define FLASH_CTRL_PREPR_Msk                                (0x1UL << FLASH_CTRL_PREPR_Pos)
#define FLASH_CTRL_PREPR                                    FLASH_CTRL_PREPR_Msk

/*********************  Bits definition for FLASH_ERPLW  **********************/
#define FLASH_ERPLW_ERPLW_Pos                               (0)
#define FLASH_ERPLW_ERPLW_Msk                               (0xffffffffUL << FLASH_ERPLW_ERPLW_Pos)
#define FLASH_ERPLW_ERPLW                                   FLASH_ERPLW_ERPLW_Msk

/********************  Bits definition for FLASH_ERWEPLW  *********************/
#define FLASH_ERWEPLW_ERWEPLW_Pos                           (0)
#define FLASH_ERWEPLW_ERWEPLW_Msk                           (0xffffffffUL << FLASH_ERWEPLW_ERWEPLW_Pos)
#define FLASH_ERWEPLW_ERWEPLW                               FLASH_ERWEPLW_ERWEPLW_Msk

/********************  Bits definition for FLASH_ERWESTPT  ********************/
#define FLASH_ERWESTPT_ERWESTPT_Pos                         (0)
#define FLASH_ERWESTPT_ERWESTPT_Msk                         (0xffffffffUL << FLASH_ERWESTPT_ERWESTPT_Pos)
#define FLASH_ERWESTPT_ERWESTPT                             FLASH_ERWESTPT_ERWESTPT_Msk

/******************  Bits definition for FLASH_PRWESTPHLDT  *******************/
#define FLASH_PRWESTPHLDT_PRWESTPHLDT_Pos                   (0)
#define FLASH_PRWESTPHLDT_PRWESTPHLDT_Msk                   (0xffffffffUL << FLASH_PRWESTPHLDT_PRWESTPHLDT_Pos)
#define FLASH_PRWESTPHLDT_PRWESTPHLDT                       FLASH_PRWESTPHLDT_PRWESTPHLDT_Msk

/********************  Bits definition for FLASH_PR2STPT  *********************/
#define FLASH_PR2STPT_PR2STPT_Pos                           (0)
#define FLASH_PR2STPT_PR2STPT_Msk                           (0xffffffffUL << FLASH_PR2STPT_PR2STPT_Pos)
#define FLASH_PR2STPT_PR2STPT                               FLASH_PR2STPT_PR2STPT_Msk

/********************  Bits definition for FLASH_PRWEPLW  *********************/
#define FLASH_PRWEPLW_PRWEPLW_Pos                           (0)
#define FLASH_PRWEPLW_PRWEPLW_Msk                           (0xffffffffUL << FLASH_PRWEPLW_PRWEPLW_Pos)
#define FLASH_PRWEPLW_PRWEPLW                               FLASH_PRWEPLW_PRWEPLW_Msk

/********************  Bits definition for FLASH_ROWADDR  *********************/
#define FLASH_ROWADDR_ROWADDR_Pos                           (0)
#define FLASH_ROWADDR_ROWADDR_Msk                           (0xffffffffUL << FLASH_ROWADDR_ROWADDR_Pos)
#define FLASH_ROWADDR_ROWADDR                               FLASH_ROWADDR_ROWADDR_Msk

/**********************  Bits definition for FLASH_STRT  **********************/
#define FLASH_STRT_STRT_Pos                                 (0)
#define FLASH_STRT_STRT_Msk                                 (0xffffffffUL << FLASH_STRT_STRT_Pos)
#define FLASH_STRT_STRT                                     FLASH_STRT_STRT_Msk

/******************************************************************************/
/*                                                                            */
/*                                    GPIO                                    */
/*                                                                            */
/******************************************************************************/

/***********************  Bits definition for GPIO_DR  ************************/
#define GPIO_DR_B_Pos                                       (0)
#define GPIO_DR_B_Msk                                       (0xffffffffUL << GPIO_DR_B_Pos)
#define GPIO_DR_B                                           GPIO_DR_B_Msk
#define GPIO_DR_B_0                                         (0x1UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_1                                         (0x2UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_2                                         (0x4UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_3                                         (0x8UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_4                                         (0x10UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_5                                         (0x20UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_6                                         (0x40UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_7                                         (0x80UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_8                                         (0x100UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_9                                         (0x200UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_10                                        (0x400UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_11                                        (0x800UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_12                                        (0x1000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_13                                        (0x2000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_14                                        (0x4000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_15                                        (0x8000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_16                                        (0x10000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_17                                        (0x20000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_18                                        (0x40000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_19                                        (0x80000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_20                                        (0x100000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_21                                        (0x200000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_22                                        (0x400000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_23                                        (0x800000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_24                                        (0x1000000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_25                                        (0x2000000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_26                                        (0x4000000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_27                                        (0x8000000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_28                                        (0x10000000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_29                                        (0x20000000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_30                                        (0x40000000UL << GPIO_DR_B_Pos)
#define GPIO_DR_B_31                                        (0x80000000UL << GPIO_DR_B_Pos)

/***********************  Bits definition for GPIO_DDR  ***********************/
#define GPIO_DDR_B_Pos                                      (0)
#define GPIO_DDR_B_Msk                                      (0xffffffffUL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B                                          GPIO_DDR_B_Msk
#define GPIO_DDR_B_0                                        (0x1UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_1                                        (0x2UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_2                                        (0x4UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_3                                        (0x8UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_4                                        (0x10UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_5                                        (0x20UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_6                                        (0x40UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_7                                        (0x80UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_8                                        (0x100UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_9                                        (0x200UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_10                                       (0x400UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_11                                       (0x800UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_12                                       (0x1000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_13                                       (0x2000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_14                                       (0x4000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_15                                       (0x8000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_16                                       (0x10000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_17                                       (0x20000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_18                                       (0x40000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_19                                       (0x80000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_20                                       (0x100000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_21                                       (0x200000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_22                                       (0x400000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_23                                       (0x800000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_24                                       (0x1000000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_25                                       (0x2000000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_26                                       (0x4000000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_27                                       (0x8000000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_28                                       (0x10000000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_29                                       (0x20000000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_30                                       (0x40000000UL << GPIO_DDR_B_Pos)
#define GPIO_DDR_B_31                                       (0x80000000UL << GPIO_DDR_B_Pos)

/***********************  Bits definition for GPIO_CTL  ***********************/
#define GPIO_CTL_B_Pos                                      (0)
#define GPIO_CTL_B_Msk                                      (0xffffffffUL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B                                          GPIO_CTL_B_Msk
#define GPIO_CTL_B_0                                        (0x1UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_1                                        (0x2UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_2                                        (0x4UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_3                                        (0x8UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_4                                        (0x10UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_5                                        (0x20UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_6                                        (0x40UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_7                                        (0x80UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_8                                        (0x100UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_9                                        (0x200UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_10                                       (0x400UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_11                                       (0x800UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_12                                       (0x1000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_13                                       (0x2000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_14                                       (0x4000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_15                                       (0x8000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_16                                       (0x10000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_17                                       (0x20000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_18                                       (0x40000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_19                                       (0x80000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_20                                       (0x100000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_21                                       (0x200000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_22                                       (0x400000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_23                                       (0x800000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_24                                       (0x1000000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_25                                       (0x2000000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_26                                       (0x4000000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_27                                       (0x8000000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_28                                       (0x10000000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_29                                       (0x20000000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_30                                       (0x40000000UL << GPIO_CTL_B_Pos)
#define GPIO_CTL_B_31                                       (0x80000000UL << GPIO_CTL_B_Pos)

/******************************************************************************/
/*                                                                            */
/*                                  GPIO_AUX                                  */
/*                                                                            */
/******************************************************************************/

/*********************  Bits definition for GPIO_AUX_DRA  *********************/
#define GPIO_AUX_DRA_B_Pos                                  (0)
#define GPIO_AUX_DRA_B_Msk                                  (0xffffffffUL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B                                      GPIO_AUX_DRA_B_Msk
#define GPIO_AUX_DRA_B_0                                    (0x1UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_1                                    (0x2UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_2                                    (0x4UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_3                                    (0x8UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_4                                    (0x10UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_5                                    (0x20UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_6                                    (0x40UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_7                                    (0x80UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_8                                    (0x100UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_9                                    (0x200UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_10                                   (0x400UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_11                                   (0x800UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_12                                   (0x1000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_13                                   (0x2000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_14                                   (0x4000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_15                                   (0x8000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_16                                   (0x10000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_17                                   (0x20000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_18                                   (0x40000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_19                                   (0x80000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_20                                   (0x100000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_21                                   (0x200000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_22                                   (0x400000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_23                                   (0x800000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_24                                   (0x1000000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_25                                   (0x2000000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_26                                   (0x4000000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_27                                   (0x8000000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_28                                   (0x10000000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_29                                   (0x20000000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_30                                   (0x40000000UL << GPIO_AUX_DRA_B_Pos)
#define GPIO_AUX_DRA_B_31                                   (0x80000000UL << GPIO_AUX_DRA_B_Pos)

/********************  Bits definition for GPIO_AUX_DDRA  *********************/
#define GPIO_AUX_DDRA_B_Pos                                 (0)
#define GPIO_AUX_DDRA_B_Msk                                 (0xffffffffUL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B                                     GPIO_AUX_DDRA_B_Msk
#define GPIO_AUX_DDRA_B_0                                   (0x1UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_1                                   (0x2UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_2                                   (0x4UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_3                                   (0x8UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_4                                   (0x10UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_5                                   (0x20UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_6                                   (0x40UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_7                                   (0x80UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_8                                   (0x100UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_9                                   (0x200UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_10                                  (0x400UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_11                                  (0x800UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_12                                  (0x1000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_13                                  (0x2000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_14                                  (0x4000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_15                                  (0x8000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_16                                  (0x10000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_17                                  (0x20000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_18                                  (0x40000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_19                                  (0x80000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_20                                  (0x100000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_21                                  (0x200000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_22                                  (0x400000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_23                                  (0x800000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_24                                  (0x1000000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_25                                  (0x2000000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_26                                  (0x4000000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_27                                  (0x8000000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_28                                  (0x10000000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_29                                  (0x20000000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_30                                  (0x40000000UL << GPIO_AUX_DDRA_B_Pos)
#define GPIO_AUX_DDRA_B_31                                  (0x80000000UL << GPIO_AUX_DDRA_B_Pos)

/********************  Bits definition for GPIO_AUX_CTLA  *********************/
#define GPIO_AUX_CTLA_B_Pos                                 (0)
#define GPIO_AUX_CTLA_B_Msk                                 (0xffffffffUL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B                                     GPIO_AUX_CTLA_B_Msk
#define GPIO_AUX_CTLA_B_0                                   (0x1UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_1                                   (0x2UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_2                                   (0x4UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_3                                   (0x8UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_4                                   (0x10UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_5                                   (0x20UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_6                                   (0x40UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_7                                   (0x80UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_8                                   (0x100UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_9                                   (0x200UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_10                                  (0x400UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_11                                  (0x800UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_12                                  (0x1000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_13                                  (0x2000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_14                                  (0x4000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_15                                  (0x8000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_16                                  (0x10000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_17                                  (0x20000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_18                                  (0x40000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_19                                  (0x80000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_20                                  (0x100000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_21                                  (0x200000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_22                                  (0x400000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_23                                  (0x800000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_24                                  (0x1000000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_25                                  (0x2000000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_26                                  (0x4000000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_27                                  (0x8000000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_28                                  (0x10000000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_29                                  (0x20000000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_30                                  (0x40000000UL << GPIO_AUX_CTLA_B_Pos)
#define GPIO_AUX_CTLA_B_31                                  (0x80000000UL << GPIO_AUX_CTLA_B_Pos)

/*********************  Bits definition for GPIO_AUX_DRB  *********************/
#define GPIO_AUX_DRB_B_Pos                                  (0)
#define GPIO_AUX_DRB_B_Msk                                  (0xffffffffUL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B                                      GPIO_AUX_DRB_B_Msk
#define GPIO_AUX_DRB_B_0                                    (0x1UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_1                                    (0x2UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_2                                    (0x4UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_3                                    (0x8UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_4                                    (0x10UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_5                                    (0x20UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_6                                    (0x40UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_7                                    (0x80UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_8                                    (0x100UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_9                                    (0x200UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_10                                   (0x400UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_11                                   (0x800UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_12                                   (0x1000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_13                                   (0x2000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_14                                   (0x4000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_15                                   (0x8000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_16                                   (0x10000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_17                                   (0x20000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_18                                   (0x40000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_19                                   (0x80000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_20                                   (0x100000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_21                                   (0x200000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_22                                   (0x400000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_23                                   (0x800000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_24                                   (0x1000000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_25                                   (0x2000000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_26                                   (0x4000000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_27                                   (0x8000000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_28                                   (0x10000000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_29                                   (0x20000000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_30                                   (0x40000000UL << GPIO_AUX_DRB_B_Pos)
#define GPIO_AUX_DRB_B_31                                   (0x80000000UL << GPIO_AUX_DRB_B_Pos)

/********************  Bits definition for GPIO_AUX_DDRB  *********************/
#define GPIO_AUX_DDRB_B_Pos                                 (0)
#define GPIO_AUX_DDRB_B_Msk                                 (0xffffffffUL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B                                     GPIO_AUX_DDRB_B_Msk
#define GPIO_AUX_DDRB_B_0                                   (0x1UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_1                                   (0x2UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_2                                   (0x4UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_3                                   (0x8UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_4                                   (0x10UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_5                                   (0x20UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_6                                   (0x40UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_7                                   (0x80UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_8                                   (0x100UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_9                                   (0x200UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_10                                  (0x400UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_11                                  (0x800UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_12                                  (0x1000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_13                                  (0x2000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_14                                  (0x4000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_15                                  (0x8000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_16                                  (0x10000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_17                                  (0x20000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_18                                  (0x40000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_19                                  (0x80000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_20                                  (0x100000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_21                                  (0x200000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_22                                  (0x400000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_23                                  (0x800000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_24                                  (0x1000000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_25                                  (0x2000000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_26                                  (0x4000000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_27                                  (0x8000000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_28                                  (0x10000000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_29                                  (0x20000000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_30                                  (0x40000000UL << GPIO_AUX_DDRB_B_Pos)
#define GPIO_AUX_DDRB_B_31                                  (0x80000000UL << GPIO_AUX_DDRB_B_Pos)

/********************  Bits definition for GPIO_AUX_CTLB  *********************/
#define GPIO_AUX_CTLB_B_Pos                                 (0)
#define GPIO_AUX_CTLB_B_Msk                                 (0xffffffffUL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B                                     GPIO_AUX_CTLB_B_Msk
#define GPIO_AUX_CTLB_B_0                                   (0x1UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_1                                   (0x2UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_2                                   (0x4UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_3                                   (0x8UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_4                                   (0x10UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_5                                   (0x20UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_6                                   (0x40UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_7                                   (0x80UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_8                                   (0x100UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_9                                   (0x200UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_10                                  (0x400UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_11                                  (0x800UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_12                                  (0x1000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_13                                  (0x2000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_14                                  (0x4000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_15                                  (0x8000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_16                                  (0x10000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_17                                  (0x20000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_18                                  (0x40000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_19                                  (0x80000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_20                                  (0x100000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_21                                  (0x200000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_22                                  (0x400000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_23                                  (0x800000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_24                                  (0x1000000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_25                                  (0x2000000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_26                                  (0x4000000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_27                                  (0x8000000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_28                                  (0x10000000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_29                                  (0x20000000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_30                                  (0x40000000UL << GPIO_AUX_CTLB_B_Pos)
#define GPIO_AUX_CTLB_B_31                                  (0x80000000UL << GPIO_AUX_CTLB_B_Pos)

/*********************  Bits definition for GPIO_AUX_DRC  *********************/
#define GPIO_AUX_DRC_B_Pos                                  (0)
#define GPIO_AUX_DRC_B_Msk                                  (0xffffffffUL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B                                      GPIO_AUX_DRC_B_Msk
#define GPIO_AUX_DRC_B_0                                    (0x1UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_1                                    (0x2UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_2                                    (0x4UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_3                                    (0x8UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_4                                    (0x10UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_5                                    (0x20UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_6                                    (0x40UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_7                                    (0x80UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_8                                    (0x100UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_9                                    (0x200UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_10                                   (0x400UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_11                                   (0x800UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_12                                   (0x1000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_13                                   (0x2000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_14                                   (0x4000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_15                                   (0x8000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_16                                   (0x10000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_17                                   (0x20000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_18                                   (0x40000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_19                                   (0x80000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_20                                   (0x100000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_21                                   (0x200000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_22                                   (0x400000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_23                                   (0x800000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_24                                   (0x1000000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_25                                   (0x2000000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_26                                   (0x4000000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_27                                   (0x8000000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_28                                   (0x10000000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_29                                   (0x20000000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_30                                   (0x40000000UL << GPIO_AUX_DRC_B_Pos)
#define GPIO_AUX_DRC_B_31                                   (0x80000000UL << GPIO_AUX_DRC_B_Pos)

/********************  Bits definition for GPIO_AUX_DDRC  *********************/
#define GPIO_AUX_DDRC_B_Pos                                 (0)
#define GPIO_AUX_DDRC_B_Msk                                 (0xffffffffUL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B                                     GPIO_AUX_DDRC_B_Msk
#define GPIO_AUX_DDRC_B_0                                   (0x1UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_1                                   (0x2UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_2                                   (0x4UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_3                                   (0x8UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_4                                   (0x10UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_5                                   (0x20UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_6                                   (0x40UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_7                                   (0x80UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_8                                   (0x100UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_9                                   (0x200UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_10                                  (0x400UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_11                                  (0x800UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_12                                  (0x1000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_13                                  (0x2000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_14                                  (0x4000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_15                                  (0x8000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_16                                  (0x10000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_17                                  (0x20000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_18                                  (0x40000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_19                                  (0x80000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_20                                  (0x100000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_21                                  (0x200000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_22                                  (0x400000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_23                                  (0x800000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_24                                  (0x1000000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_25                                  (0x2000000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_26                                  (0x4000000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_27                                  (0x8000000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_28                                  (0x10000000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_29                                  (0x20000000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_30                                  (0x40000000UL << GPIO_AUX_DDRC_B_Pos)
#define GPIO_AUX_DDRC_B_31                                  (0x80000000UL << GPIO_AUX_DDRC_B_Pos)

/********************  Bits definition for GPIO_AUX_CTLC  *********************/
#define GPIO_AUX_CTLC_B_Pos                                 (0)
#define GPIO_AUX_CTLC_B_Msk                                 (0xffffffffUL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B                                     GPIO_AUX_CTLC_B_Msk
#define GPIO_AUX_CTLC_B_0                                   (0x1UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_1                                   (0x2UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_2                                   (0x4UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_3                                   (0x8UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_4                                   (0x10UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_5                                   (0x20UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_6                                   (0x40UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_7                                   (0x80UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_8                                   (0x100UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_9                                   (0x200UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_10                                  (0x400UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_11                                  (0x800UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_12                                  (0x1000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_13                                  (0x2000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_14                                  (0x4000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_15                                  (0x8000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_16                                  (0x10000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_17                                  (0x20000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_18                                  (0x40000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_19                                  (0x80000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_20                                  (0x100000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_21                                  (0x200000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_22                                  (0x400000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_23                                  (0x800000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_24                                  (0x1000000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_25                                  (0x2000000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_26                                  (0x4000000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_27                                  (0x8000000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_28                                  (0x10000000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_29                                  (0x20000000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_30                                  (0x40000000UL << GPIO_AUX_CTLC_B_Pos)
#define GPIO_AUX_CTLC_B_31                                  (0x80000000UL << GPIO_AUX_CTLC_B_Pos)

/*********************  Bits definition for GPIO_AUX_DRD  *********************/
#define GPIO_AUX_DRD_B_Pos                                  (0)
#define GPIO_AUX_DRD_B_Msk                                  (0xffffffffUL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B                                      GPIO_AUX_DRD_B_Msk
#define GPIO_AUX_DRD_B_0                                    (0x1UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_1                                    (0x2UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_2                                    (0x4UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_3                                    (0x8UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_4                                    (0x10UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_5                                    (0x20UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_6                                    (0x40UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_7                                    (0x80UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_8                                    (0x100UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_9                                    (0x200UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_10                                   (0x400UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_11                                   (0x800UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_12                                   (0x1000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_13                                   (0x2000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_14                                   (0x4000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_15                                   (0x8000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_16                                   (0x10000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_17                                   (0x20000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_18                                   (0x40000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_19                                   (0x80000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_20                                   (0x100000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_21                                   (0x200000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_22                                   (0x400000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_23                                   (0x800000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_24                                   (0x1000000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_25                                   (0x2000000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_26                                   (0x4000000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_27                                   (0x8000000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_28                                   (0x10000000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_29                                   (0x20000000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_30                                   (0x40000000UL << GPIO_AUX_DRD_B_Pos)
#define GPIO_AUX_DRD_B_31                                   (0x80000000UL << GPIO_AUX_DRD_B_Pos)

/********************  Bits definition for GPIO_AUX_DDRD  *********************/
#define GPIO_AUX_DDRD_B_Pos                                 (0)
#define GPIO_AUX_DDRD_B_Msk                                 (0xffffffffUL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B                                     GPIO_AUX_DDRD_B_Msk
#define GPIO_AUX_DDRD_B_0                                   (0x1UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_1                                   (0x2UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_2                                   (0x4UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_3                                   (0x8UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_4                                   (0x10UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_5                                   (0x20UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_6                                   (0x40UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_7                                   (0x80UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_8                                   (0x100UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_9                                   (0x200UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_10                                  (0x400UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_11                                  (0x800UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_12                                  (0x1000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_13                                  (0x2000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_14                                  (0x4000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_15                                  (0x8000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_16                                  (0x10000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_17                                  (0x20000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_18                                  (0x40000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_19                                  (0x80000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_20                                  (0x100000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_21                                  (0x200000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_22                                  (0x400000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_23                                  (0x800000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_24                                  (0x1000000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_25                                  (0x2000000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_26                                  (0x4000000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_27                                  (0x8000000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_28                                  (0x10000000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_29                                  (0x20000000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_30                                  (0x40000000UL << GPIO_AUX_DDRD_B_Pos)
#define GPIO_AUX_DDRD_B_31                                  (0x80000000UL << GPIO_AUX_DDRD_B_Pos)

/********************  Bits definition for GPIO_AUX_CTLD  *********************/
#define GPIO_AUX_CTLD_B_Pos                                 (0)
#define GPIO_AUX_CTLD_B_Msk                                 (0xffffffffUL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B                                     GPIO_AUX_CTLD_B_Msk
#define GPIO_AUX_CTLD_B_0                                   (0x1UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_1                                   (0x2UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_2                                   (0x4UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_3                                   (0x8UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_4                                   (0x10UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_5                                   (0x20UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_6                                   (0x40UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_7                                   (0x80UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_8                                   (0x100UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_9                                   (0x200UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_10                                  (0x400UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_11                                  (0x800UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_12                                  (0x1000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_13                                  (0x2000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_14                                  (0x4000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_15                                  (0x8000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_16                                  (0x10000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_17                                  (0x20000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_18                                  (0x40000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_19                                  (0x80000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_20                                  (0x100000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_21                                  (0x200000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_22                                  (0x400000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_23                                  (0x800000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_24                                  (0x1000000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_25                                  (0x2000000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_26                                  (0x4000000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_27                                  (0x8000000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_28                                  (0x10000000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_29                                  (0x20000000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_30                                  (0x40000000UL << GPIO_AUX_CTLD_B_Pos)
#define GPIO_AUX_CTLD_B_31                                  (0x80000000UL << GPIO_AUX_CTLD_B_Pos)

/********************  Bits definition for GPIO_AUX_INTEN  ********************/
#define GPIO_AUX_INTEN_B_Pos                                (0)
#define GPIO_AUX_INTEN_B_Msk                                (0xffffffffUL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B                                    GPIO_AUX_INTEN_B_Msk
#define GPIO_AUX_INTEN_B_0                                  (0x1UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_1                                  (0x2UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_2                                  (0x4UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_3                                  (0x8UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_4                                  (0x10UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_5                                  (0x20UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_6                                  (0x40UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_7                                  (0x80UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_8                                  (0x100UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_9                                  (0x200UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_10                                 (0x400UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_11                                 (0x800UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_12                                 (0x1000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_13                                 (0x2000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_14                                 (0x4000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_15                                 (0x8000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_16                                 (0x10000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_17                                 (0x20000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_18                                 (0x40000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_19                                 (0x80000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_20                                 (0x100000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_21                                 (0x200000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_22                                 (0x400000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_23                                 (0x800000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_24                                 (0x1000000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_25                                 (0x2000000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_26                                 (0x4000000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_27                                 (0x8000000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_28                                 (0x10000000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_29                                 (0x20000000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_30                                 (0x40000000UL << GPIO_AUX_INTEN_B_Pos)
#define GPIO_AUX_INTEN_B_31                                 (0x80000000UL << GPIO_AUX_INTEN_B_Pos)

/*******************  Bits definition for GPIO_AUX_INTMSK  ********************/
#define GPIO_AUX_INTMSK_B_Pos                               (0)
#define GPIO_AUX_INTMSK_B_Msk                               (0xffffffffUL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B                                   GPIO_AUX_INTMSK_B_Msk
#define GPIO_AUX_INTMSK_B_0                                 (0x1UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_1                                 (0x2UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_2                                 (0x4UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_3                                 (0x8UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_4                                 (0x10UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_5                                 (0x20UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_6                                 (0x40UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_7                                 (0x80UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_8                                 (0x100UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_9                                 (0x200UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_10                                (0x400UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_11                                (0x800UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_12                                (0x1000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_13                                (0x2000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_14                                (0x4000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_15                                (0x8000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_16                                (0x10000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_17                                (0x20000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_18                                (0x40000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_19                                (0x80000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_20                                (0x100000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_21                                (0x200000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_22                                (0x400000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_23                                (0x800000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_24                                (0x1000000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_25                                (0x2000000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_26                                (0x4000000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_27                                (0x8000000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_28                                (0x10000000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_29                                (0x20000000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_30                                (0x40000000UL << GPIO_AUX_INTMSK_B_Pos)
#define GPIO_AUX_INTMSK_B_31                                (0x80000000UL << GPIO_AUX_INTMSK_B_Pos)

/*******************  Bits definition for GPIO_AUX_INTLVL  ********************/
#define GPIO_AUX_INTLVL_B_Pos                               (0)
#define GPIO_AUX_INTLVL_B_Msk                               (0xffffffffUL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B                                   GPIO_AUX_INTLVL_B_Msk
#define GPIO_AUX_INTLVL_B_0                                 (0x1UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_1                                 (0x2UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_2                                 (0x4UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_3                                 (0x8UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_4                                 (0x10UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_5                                 (0x20UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_6                                 (0x40UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_7                                 (0x80UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_8                                 (0x100UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_9                                 (0x200UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_10                                (0x400UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_11                                (0x800UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_12                                (0x1000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_13                                (0x2000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_14                                (0x4000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_15                                (0x8000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_16                                (0x10000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_17                                (0x20000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_18                                (0x40000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_19                                (0x80000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_20                                (0x100000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_21                                (0x200000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_22                                (0x400000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_23                                (0x800000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_24                                (0x1000000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_25                                (0x2000000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_26                                (0x4000000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_27                                (0x8000000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_28                                (0x10000000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_29                                (0x20000000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_30                                (0x40000000UL << GPIO_AUX_INTLVL_B_Pos)
#define GPIO_AUX_INTLVL_B_31                                (0x80000000UL << GPIO_AUX_INTLVL_B_Pos)

/*******************  Bits definition for GPIO_AUX_INTPOL  ********************/
#define GPIO_AUX_INTPOL_B_Pos                               (0)
#define GPIO_AUX_INTPOL_B_Msk                               (0xffffffffUL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B                                   GPIO_AUX_INTPOL_B_Msk
#define GPIO_AUX_INTPOL_B_0                                 (0x1UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_1                                 (0x2UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_2                                 (0x4UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_3                                 (0x8UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_4                                 (0x10UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_5                                 (0x20UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_6                                 (0x40UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_7                                 (0x80UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_8                                 (0x100UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_9                                 (0x200UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_10                                (0x400UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_11                                (0x800UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_12                                (0x1000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_13                                (0x2000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_14                                (0x4000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_15                                (0x8000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_16                                (0x10000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_17                                (0x20000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_18                                (0x40000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_19                                (0x80000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_20                                (0x100000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_21                                (0x200000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_22                                (0x400000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_23                                (0x800000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_24                                (0x1000000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_25                                (0x2000000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_26                                (0x4000000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_27                                (0x8000000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_28                                (0x10000000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_29                                (0x20000000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_30                                (0x40000000UL << GPIO_AUX_INTPOL_B_Pos)
#define GPIO_AUX_INTPOL_B_31                                (0x80000000UL << GPIO_AUX_INTPOL_B_Pos)

/*******************  Bits definition for GPIO_AUX_INTSTA  ********************/
#define GPIO_AUX_INTSTA_B_Pos                               (0)
#define GPIO_AUX_INTSTA_B_Msk                               (0xffffffffUL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B                                   GPIO_AUX_INTSTA_B_Msk
#define GPIO_AUX_INTSTA_B_0                                 (0x1UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_1                                 (0x2UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_2                                 (0x4UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_3                                 (0x8UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_4                                 (0x10UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_5                                 (0x20UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_6                                 (0x40UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_7                                 (0x80UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_8                                 (0x100UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_9                                 (0x200UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_10                                (0x400UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_11                                (0x800UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_12                                (0x1000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_13                                (0x2000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_14                                (0x4000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_15                                (0x8000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_16                                (0x10000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_17                                (0x20000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_18                                (0x40000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_19                                (0x80000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_20                                (0x100000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_21                                (0x200000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_22                                (0x400000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_23                                (0x800000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_24                                (0x1000000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_25                                (0x2000000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_26                                (0x4000000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_27                                (0x8000000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_28                                (0x10000000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_29                                (0x20000000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_30                                (0x40000000UL << GPIO_AUX_INTSTA_B_Pos)
#define GPIO_AUX_INTSTA_B_31                                (0x80000000UL << GPIO_AUX_INTSTA_B_Pos)

/******************  Bits definition for GPIO_AUX_INTRAWSTA  ******************/
#define GPIO_AUX_INTRAWSTA_B_Pos                            (0)
#define GPIO_AUX_INTRAWSTA_B_Msk                            (0xffffffffUL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B                                GPIO_AUX_INTRAWSTA_B_Msk
#define GPIO_AUX_INTRAWSTA_B_0                              (0x1UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_1                              (0x2UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_2                              (0x4UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_3                              (0x8UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_4                              (0x10UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_5                              (0x20UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_6                              (0x40UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_7                              (0x80UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_8                              (0x100UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_9                              (0x200UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_10                             (0x400UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_11                             (0x800UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_12                             (0x1000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_13                             (0x2000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_14                             (0x4000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_15                             (0x8000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_16                             (0x10000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_17                             (0x20000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_18                             (0x40000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_19                             (0x80000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_20                             (0x100000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_21                             (0x200000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_22                             (0x400000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_23                             (0x800000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_24                             (0x1000000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_25                             (0x2000000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_26                             (0x4000000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_27                             (0x8000000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_28                             (0x10000000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_29                             (0x20000000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_30                             (0x40000000UL << GPIO_AUX_INTRAWSTA_B_Pos)
#define GPIO_AUX_INTRAWSTA_B_31                             (0x80000000UL << GPIO_AUX_INTRAWSTA_B_Pos)

/********************  Bits definition for GPIO_AUX_DEBOU  ********************/
#define GPIO_AUX_DEBOU_B_Pos                                (0)
#define GPIO_AUX_DEBOU_B_Msk                                (0xffffffffUL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B                                    GPIO_AUX_DEBOU_B_Msk
#define GPIO_AUX_DEBOU_B_0                                  (0x1UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_1                                  (0x2UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_2                                  (0x4UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_3                                  (0x8UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_4                                  (0x10UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_5                                  (0x20UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_6                                  (0x40UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_7                                  (0x80UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_8                                  (0x100UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_9                                  (0x200UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_10                                 (0x400UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_11                                 (0x800UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_12                                 (0x1000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_13                                 (0x2000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_14                                 (0x4000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_15                                 (0x8000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_16                                 (0x10000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_17                                 (0x20000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_18                                 (0x40000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_19                                 (0x80000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_20                                 (0x100000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_21                                 (0x200000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_22                                 (0x400000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_23                                 (0x800000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_24                                 (0x1000000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_25                                 (0x2000000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_26                                 (0x4000000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_27                                 (0x8000000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_28                                 (0x10000000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_29                                 (0x20000000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_30                                 (0x40000000UL << GPIO_AUX_DEBOU_B_Pos)
#define GPIO_AUX_DEBOU_B_31                                 (0x80000000UL << GPIO_AUX_DEBOU_B_Pos)

/********************  Bits definition for GPIO_AUX_EOIA  *********************/
#define GPIO_AUX_EOIA_B_Pos                                 (0)
#define GPIO_AUX_EOIA_B_Msk                                 (0xffffffffUL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B                                     GPIO_AUX_EOIA_B_Msk
#define GPIO_AUX_EOIA_B_0                                   (0x1UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_1                                   (0x2UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_2                                   (0x4UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_3                                   (0x8UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_4                                   (0x10UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_5                                   (0x20UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_6                                   (0x40UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_7                                   (0x80UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_8                                   (0x100UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_9                                   (0x200UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_10                                  (0x400UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_11                                  (0x800UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_12                                  (0x1000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_13                                  (0x2000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_14                                  (0x4000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_15                                  (0x8000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_16                                  (0x10000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_17                                  (0x20000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_18                                  (0x40000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_19                                  (0x80000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_20                                  (0x100000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_21                                  (0x200000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_22                                  (0x400000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_23                                  (0x800000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_24                                  (0x1000000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_25                                  (0x2000000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_26                                  (0x4000000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_27                                  (0x8000000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_28                                  (0x10000000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_29                                  (0x20000000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_30                                  (0x40000000UL << GPIO_AUX_EOIA_B_Pos)
#define GPIO_AUX_EOIA_B_31                                  (0x80000000UL << GPIO_AUX_EOIA_B_Pos)

/********************  Bits definition for GPIO_AUX_EXTA  *********************/
#define GPIO_AUX_EXTA_B_Pos                                 (0)
#define GPIO_AUX_EXTA_B_Msk                                 (0xffffffffUL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B                                     GPIO_AUX_EXTA_B_Msk
#define GPIO_AUX_EXTA_B_0                                   (0x1UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_1                                   (0x2UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_2                                   (0x4UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_3                                   (0x8UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_4                                   (0x10UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_5                                   (0x20UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_6                                   (0x40UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_7                                   (0x80UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_8                                   (0x100UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_9                                   (0x200UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_10                                  (0x400UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_11                                  (0x800UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_12                                  (0x1000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_13                                  (0x2000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_14                                  (0x4000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_15                                  (0x8000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_16                                  (0x10000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_17                                  (0x20000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_18                                  (0x40000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_19                                  (0x80000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_20                                  (0x100000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_21                                  (0x200000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_22                                  (0x400000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_23                                  (0x800000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_24                                  (0x1000000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_25                                  (0x2000000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_26                                  (0x4000000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_27                                  (0x8000000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_28                                  (0x10000000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_29                                  (0x20000000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_30                                  (0x40000000UL << GPIO_AUX_EXTA_B_Pos)
#define GPIO_AUX_EXTA_B_31                                  (0x80000000UL << GPIO_AUX_EXTA_B_Pos)

/********************  Bits definition for GPIO_AUX_EXTB  *********************/
#define GPIO_AUX_EXTB_B_Pos                                 (0)
#define GPIO_AUX_EXTB_B_Msk                                 (0xffffffffUL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B                                     GPIO_AUX_EXTB_B_Msk
#define GPIO_AUX_EXTB_B_0                                   (0x1UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_1                                   (0x2UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_2                                   (0x4UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_3                                   (0x8UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_4                                   (0x10UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_5                                   (0x20UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_6                                   (0x40UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_7                                   (0x80UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_8                                   (0x100UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_9                                   (0x200UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_10                                  (0x400UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_11                                  (0x800UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_12                                  (0x1000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_13                                  (0x2000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_14                                  (0x4000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_15                                  (0x8000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_16                                  (0x10000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_17                                  (0x20000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_18                                  (0x40000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_19                                  (0x80000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_20                                  (0x100000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_21                                  (0x200000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_22                                  (0x400000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_23                                  (0x800000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_24                                  (0x1000000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_25                                  (0x2000000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_26                                  (0x4000000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_27                                  (0x8000000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_28                                  (0x10000000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_29                                  (0x20000000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_30                                  (0x40000000UL << GPIO_AUX_EXTB_B_Pos)
#define GPIO_AUX_EXTB_B_31                                  (0x80000000UL << GPIO_AUX_EXTB_B_Pos)

/********************  Bits definition for GPIO_AUX_EXTC  *********************/
#define GPIO_AUX_EXTC_B_Pos                                 (0)
#define GPIO_AUX_EXTC_B_Msk                                 (0xffffffffUL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B                                     GPIO_AUX_EXTC_B_Msk
#define GPIO_AUX_EXTC_B_0                                   (0x1UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_1                                   (0x2UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_2                                   (0x4UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_3                                   (0x8UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_4                                   (0x10UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_5                                   (0x20UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_6                                   (0x40UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_7                                   (0x80UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_8                                   (0x100UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_9                                   (0x200UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_10                                  (0x400UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_11                                  (0x800UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_12                                  (0x1000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_13                                  (0x2000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_14                                  (0x4000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_15                                  (0x8000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_16                                  (0x10000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_17                                  (0x20000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_18                                  (0x40000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_19                                  (0x80000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_20                                  (0x100000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_21                                  (0x200000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_22                                  (0x400000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_23                                  (0x800000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_24                                  (0x1000000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_25                                  (0x2000000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_26                                  (0x4000000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_27                                  (0x8000000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_28                                  (0x10000000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_29                                  (0x20000000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_30                                  (0x40000000UL << GPIO_AUX_EXTC_B_Pos)
#define GPIO_AUX_EXTC_B_31                                  (0x80000000UL << GPIO_AUX_EXTC_B_Pos)

/********************  Bits definition for GPIO_AUX_EXTD  *********************/
#define GPIO_AUX_EXTD_B_Pos                                 (0)
#define GPIO_AUX_EXTD_B_Msk                                 (0xffffffffUL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B                                     GPIO_AUX_EXTD_B_Msk
#define GPIO_AUX_EXTD_B_0                                   (0x1UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_1                                   (0x2UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_2                                   (0x4UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_3                                   (0x8UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_4                                   (0x10UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_5                                   (0x20UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_6                                   (0x40UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_7                                   (0x80UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_8                                   (0x100UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_9                                   (0x200UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_10                                  (0x400UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_11                                  (0x800UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_12                                  (0x1000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_13                                  (0x2000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_14                                  (0x4000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_15                                  (0x8000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_16                                  (0x10000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_17                                  (0x20000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_18                                  (0x40000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_19                                  (0x80000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_20                                  (0x100000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_21                                  (0x200000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_22                                  (0x400000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_23                                  (0x800000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_24                                  (0x1000000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_25                                  (0x2000000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_26                                  (0x4000000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_27                                  (0x8000000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_28                                  (0x10000000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_29                                  (0x20000000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_30                                  (0x40000000UL << GPIO_AUX_EXTD_B_Pos)
#define GPIO_AUX_EXTD_B_31                                  (0x80000000UL << GPIO_AUX_EXTD_B_Pos)

/*******************  Bits definition for GPIO_AUX_LSSYNC  ********************/
#define GPIO_AUX_LSSYNC_SYNC_Pos                            (0)
#define GPIO_AUX_LSSYNC_SYNC_Msk                            (0x1UL << GPIO_AUX_LSSYNC_SYNC_Pos)
#define GPIO_AUX_LSSYNC_SYNC                                GPIO_AUX_LSSYNC_SYNC_Msk

/******************************************************************************/
/*                                                                            */
/*                                    I2C                                     */
/*                                                                            */
/******************************************************************************/

/***********************  Bits definition for I2C_CON  ************************/
#define I2C_CON_MMOD_Pos                                    (0)
#define I2C_CON_MMOD_Msk                                    (0x1UL << I2C_CON_MMOD_Pos)
#define I2C_CON_MMOD                                        I2C_CON_MMOD_Msk
#define I2C_CON_SPEED_Pos                                   (1)
#define I2C_CON_SPEED_Msk                                   (0x3UL << I2C_CON_SPEED_Pos)
#define I2C_CON_SPEED                                       I2C_CON_SPEED_Msk
#define I2C_CON_SPEED_0                                     (0x1UL << I2C_CON_SPEED_Pos)
#define I2C_CON_SPEED_1                                     (0x2UL << I2C_CON_SPEED_Pos)
#define I2C_CON_10ASLV_Pos                                  (3)
#define I2C_CON_10ASLV_Msk                                  (0x1UL << I2C_CON_10ASLV_Pos)
#define I2C_CON_10ASLV                                      I2C_CON_10ASLV_Msk
#define I2C_CON_10AMST_Pos                                  (4)
#define I2C_CON_10AMST_Msk                                  (0x1UL << I2C_CON_10AMST_Pos)
#define I2C_CON_10AMST                                      I2C_CON_10AMST_Msk
#define I2C_CON_RESTARTEN_Pos                               (5)
#define I2C_CON_RESTARTEN_Msk                               (0x1UL << I2C_CON_RESTARTEN_Pos)
#define I2C_CON_RESTARTEN                                   I2C_CON_RESTARTEN_Msk
#define I2C_CON_SLVDIS_Pos                                  (6)
#define I2C_CON_SLVDIS_Msk                                  (0x1UL << I2C_CON_SLVDIS_Pos)
#define I2C_CON_SLVDIS                                      I2C_CON_SLVDIS_Msk
#define I2C_CON_STOPDETIFA_Pos                              (7)
#define I2C_CON_STOPDETIFA_Msk                              (0x1UL << I2C_CON_STOPDETIFA_Pos)
#define I2C_CON_STOPDETIFA                                  I2C_CON_STOPDETIFA_Msk
#define I2C_CON_TXEMPCTRL_Pos                               (8)
#define I2C_CON_TXEMPCTRL_Msk                               (0x1UL << I2C_CON_TXEMPCTRL_Pos)
#define I2C_CON_TXEMPCTRL                                   I2C_CON_TXEMPCTRL_Msk
#define I2C_CON_RXFHCTRL_Pos                                (9)
#define I2C_CON_RXFHCTRL_Msk                                (0x1UL << I2C_CON_RXFHCTRL_Pos)
#define I2C_CON_RXFHCTRL                                    I2C_CON_RXFHCTRL_Msk

/***********************  Bits definition for I2C_TAR  ************************/
#define I2C_TAR_TAR_Pos                                     (0)
#define I2C_TAR_TAR_Msk                                     (0x3ffUL << I2C_TAR_TAR_Pos)
#define I2C_TAR_TAR                                         I2C_TAR_TAR_Msk
#define I2C_TAR_GCORSTART_Pos                               (10)
#define I2C_TAR_GCORSTART_Msk                               (0x1UL << I2C_TAR_GCORSTART_Pos)
#define I2C_TAR_GCORSTART                                   I2C_TAR_GCORSTART_Msk
#define I2C_TAR_SPECIAL_Pos                                 (11)
#define I2C_TAR_SPECIAL_Msk                                 (0x1UL << I2C_TAR_SPECIAL_Pos)
#define I2C_TAR_SPECIAL                                     I2C_TAR_SPECIAL_Msk

/***********************  Bits definition for I2C_SAR  ************************/
#define I2C_SAR_SAR_Pos                                     (0)
#define I2C_SAR_SAR_Msk                                     (0x3ffUL << I2C_SAR_SAR_Pos)
#define I2C_SAR_SAR                                         I2C_SAR_SAR_Msk

/*********************  Bits definition for I2C_HSMADDR  **********************/
#define I2C_HSMADDR_HSMAR_Pos                               (0)
#define I2C_HSMADDR_HSMAR_Msk                               (0x7UL << I2C_HSMADDR_HSMAR_Pos)
#define I2C_HSMADDR_HSMAR                                   I2C_HSMADDR_HSMAR_Msk
#define I2C_HSMADDR_HSMAR_0                                 (0x1UL << I2C_HSMADDR_HSMAR_Pos)
#define I2C_HSMADDR_HSMAR_1                                 (0x2UL << I2C_HSMADDR_HSMAR_Pos)
#define I2C_HSMADDR_HSMAR_2                                 (0x4UL << I2C_HSMADDR_HSMAR_Pos)

/*********************  Bits definition for I2C_DATACMD  **********************/
#define I2C_DATACMD_DAT_Pos                                 (0)
#define I2C_DATACMD_DAT_Msk                                 (0xffUL << I2C_DATACMD_DAT_Pos)
#define I2C_DATACMD_DAT                                     I2C_DATACMD_DAT_Msk
#define I2C_DATACMD_CMD_Pos                                 (8)
#define I2C_DATACMD_CMD_Msk                                 (0x1UL << I2C_DATACMD_CMD_Pos)
#define I2C_DATACMD_CMD                                     I2C_DATACMD_CMD_Msk

/********************  Bits definition for I2C_SSSCLHCNT  *********************/
#define I2C_SSSCLHCNT_CNT_Pos                               (0)
#define I2C_SSSCLHCNT_CNT_Msk                               (0xffffUL << I2C_SSSCLHCNT_CNT_Pos)
#define I2C_SSSCLHCNT_CNT                                   I2C_SSSCLHCNT_CNT_Msk

/********************  Bits definition for I2C_SSSCLLCNT  *********************/
#define I2C_SSSCLLCNT_CNT_Pos                               (0)
#define I2C_SSSCLLCNT_CNT_Msk                               (0xffffUL << I2C_SSSCLLCNT_CNT_Pos)
#define I2C_SSSCLLCNT_CNT                                   I2C_SSSCLLCNT_CNT_Msk

/********************  Bits definition for I2C_FSSCLHCNT  *********************/
#define I2C_FSSCLHCNT_CNT_Pos                               (0)
#define I2C_FSSCLHCNT_CNT_Msk                               (0xffffUL << I2C_FSSCLHCNT_CNT_Pos)
#define I2C_FSSCLHCNT_CNT                                   I2C_FSSCLHCNT_CNT_Msk

/********************  Bits definition for I2C_FSSCLLCNT  *********************/
#define I2C_FSSCLLCNT_CNT_Pos                               (0)
#define I2C_FSSCLLCNT_CNT_Msk                               (0xffffUL << I2C_FSSCLLCNT_CNT_Pos)
#define I2C_FSSCLLCNT_CNT                                   I2C_FSSCLLCNT_CNT_Msk

/********************  Bits definition for I2C_HSSCLHCNT  *********************/
#define I2C_HSSCLHCNT_CNT_Pos                               (0)
#define I2C_HSSCLHCNT_CNT_Msk                               (0xffffUL << I2C_HSSCLHCNT_CNT_Pos)
#define I2C_HSSCLHCNT_CNT                                   I2C_HSSCLHCNT_CNT_Msk

/********************  Bits definition for I2C_HSSCLLCNT  *********************/
#define I2C_HSSCLLCNT_CNT_Pos                               (0)
#define I2C_HSSCLLCNT_CNT_Msk                               (0xffffUL << I2C_HSSCLLCNT_CNT_Pos)
#define I2C_HSSCLLCNT_CNT                                   I2C_HSSCLLCNT_CNT_Msk

/*********************  Bits definition for I2C_INTRSTAT  *********************/
#define I2C_INTRSTAT_RXU_Pos                                (0)
#define I2C_INTRSTAT_RXU_Msk                                (0x1UL << I2C_INTRSTAT_RXU_Pos)
#define I2C_INTRSTAT_RXU                                    I2C_INTRSTAT_RXU_Msk
#define I2C_INTRSTAT_RXO_Pos                                (1)
#define I2C_INTRSTAT_RXO_Msk                                (0x1UL << I2C_INTRSTAT_RXO_Pos)
#define I2C_INTRSTAT_RXO                                    I2C_INTRSTAT_RXO_Msk
#define I2C_INTRSTAT_RXF_Pos                                (2)
#define I2C_INTRSTAT_RXF_Msk                                (0x1UL << I2C_INTRSTAT_RXF_Pos)
#define I2C_INTRSTAT_RXF                                    I2C_INTRSTAT_RXF_Msk
#define I2C_INTRSTAT_TXO_Pos                                (3)
#define I2C_INTRSTAT_TXO_Msk                                (0x1UL << I2C_INTRSTAT_TXO_Pos)
#define I2C_INTRSTAT_TXO                                    I2C_INTRSTAT_TXO_Msk
#define I2C_INTRSTAT_TXE_Pos                                (4)
#define I2C_INTRSTAT_TXE_Msk                                (0x1UL << I2C_INTRSTAT_TXE_Pos)
#define I2C_INTRSTAT_TXE                                    I2C_INTRSTAT_TXE_Msk
#define I2C_INTRSTAT_RDR_Pos                                (5)
#define I2C_INTRSTAT_RDR_Msk                                (0x1UL << I2C_INTRSTAT_RDR_Pos)
#define I2C_INTRSTAT_RDR                                    I2C_INTRSTAT_RDR_Msk
#define I2C_INTRSTAT_TXA_Pos                                (6)
#define I2C_INTRSTAT_TXA_Msk                                (0x1UL << I2C_INTRSTAT_TXA_Pos)
#define I2C_INTRSTAT_TXA                                    I2C_INTRSTAT_TXA_Msk
#define I2C_INTRSTAT_RXD_Pos                                (7)
#define I2C_INTRSTAT_RXD_Msk                                (0x1UL << I2C_INTRSTAT_RXD_Pos)
#define I2C_INTRSTAT_RXD                                    I2C_INTRSTAT_RXD_Msk
#define I2C_INTRSTAT_ACT_Pos                                (8)
#define I2C_INTRSTAT_ACT_Msk                                (0x1UL << I2C_INTRSTAT_ACT_Pos)
#define I2C_INTRSTAT_ACT                                    I2C_INTRSTAT_ACT_Msk
#define I2C_INTRSTAT_STOPD_Pos                              (9)
#define I2C_INTRSTAT_STOPD_Msk                              (0x1UL << I2C_INTRSTAT_STOPD_Pos)
#define I2C_INTRSTAT_STOPD                                  I2C_INTRSTAT_STOPD_Msk
#define I2C_INTRSTAT_STARTD_Pos                             (10)
#define I2C_INTRSTAT_STARTD_Msk                             (0x1UL << I2C_INTRSTAT_STARTD_Pos)
#define I2C_INTRSTAT_STARTD                                 I2C_INTRSTAT_STARTD_Msk
#define I2C_INTRSTAT_GCALL_Pos                              (11)
#define I2C_INTRSTAT_GCALL_Msk                              (0x1UL << I2C_INTRSTAT_GCALL_Pos)
#define I2C_INTRSTAT_GCALL                                  I2C_INTRSTAT_GCALL_Msk

/*********************  Bits definition for I2C_INTRMASK  *********************/
#define I2C_INTRMASK_RXU_Pos                                (0)
#define I2C_INTRMASK_RXU_Msk                                (0x1UL << I2C_INTRMASK_RXU_Pos)
#define I2C_INTRMASK_RXU                                    I2C_INTRMASK_RXU_Msk
#define I2C_INTRMASK_RXO_Pos                                (1)
#define I2C_INTRMASK_RXO_Msk                                (0x1UL << I2C_INTRMASK_RXO_Pos)
#define I2C_INTRMASK_RXO                                    I2C_INTRMASK_RXO_Msk
#define I2C_INTRMASK_RXF_Pos                                (2)
#define I2C_INTRMASK_RXF_Msk                                (0x1UL << I2C_INTRMASK_RXF_Pos)
#define I2C_INTRMASK_RXF                                    I2C_INTRMASK_RXF_Msk
#define I2C_INTRMASK_TXO_Pos                                (3)
#define I2C_INTRMASK_TXO_Msk                                (0x1UL << I2C_INTRMASK_TXO_Pos)
#define I2C_INTRMASK_TXO                                    I2C_INTRMASK_TXO_Msk
#define I2C_INTRMASK_TXE_Pos                                (4)
#define I2C_INTRMASK_TXE_Msk                                (0x1UL << I2C_INTRMASK_TXE_Pos)
#define I2C_INTRMASK_TXE                                    I2C_INTRMASK_TXE_Msk
#define I2C_INTRMASK_RDR_Pos                                (5)
#define I2C_INTRMASK_RDR_Msk                                (0x1UL << I2C_INTRMASK_RDR_Pos)
#define I2C_INTRMASK_RDR                                    I2C_INTRMASK_RDR_Msk
#define I2C_INTRMASK_TXA_Pos                                (6)
#define I2C_INTRMASK_TXA_Msk                                (0x1UL << I2C_INTRMASK_TXA_Pos)
#define I2C_INTRMASK_TXA                                    I2C_INTRMASK_TXA_Msk
#define I2C_INTRMASK_RXD_Pos                                (7)
#define I2C_INTRMASK_RXD_Msk                                (0x1UL << I2C_INTRMASK_RXD_Pos)
#define I2C_INTRMASK_RXD                                    I2C_INTRMASK_RXD_Msk
#define I2C_INTRMASK_ACT_Pos                                (8)
#define I2C_INTRMASK_ACT_Msk                                (0x1UL << I2C_INTRMASK_ACT_Pos)
#define I2C_INTRMASK_ACT                                    I2C_INTRMASK_ACT_Msk
#define I2C_INTRMASK_STOPD_Pos                              (9)
#define I2C_INTRMASK_STOPD_Msk                              (0x1UL << I2C_INTRMASK_STOPD_Pos)
#define I2C_INTRMASK_STOPD                                  I2C_INTRMASK_STOPD_Msk
#define I2C_INTRMASK_STARTD_Pos                             (10)
#define I2C_INTRMASK_STARTD_Msk                             (0x1UL << I2C_INTRMASK_STARTD_Pos)
#define I2C_INTRMASK_STARTD                                 I2C_INTRMASK_STARTD_Msk
#define I2C_INTRMASK_GCALL_Pos                              (11)
#define I2C_INTRMASK_GCALL_Msk                              (0x1UL << I2C_INTRMASK_GCALL_Pos)
#define I2C_INTRMASK_GCALL                                  I2C_INTRMASK_GCALL_Msk

/*******************  Bits definition for I2C_RAWINTRSTAT  ********************/
#define I2C_RINTRSTAT_RXU_Pos                               (0)
#define I2C_RINTRSTAT_RXU_Msk                               (0x1UL << I2C_RINTRSTAT_RXU_Pos)
#define I2C_RINTRSTAT_RXU                                   I2C_RINTRSTAT_RXU_Msk
#define I2C_RINTRSTAT_RXO_Pos                               (1)
#define I2C_RINTRSTAT_RXO_Msk                               (0x1UL << I2C_RINTRSTAT_RXO_Pos)
#define I2C_RINTRSTAT_RXO                                   I2C_RINTRSTAT_RXO_Msk
#define I2C_RINTRSTAT_RXF_Pos                               (2)
#define I2C_RINTRSTAT_RXF_Msk                               (0x1UL << I2C_RINTRSTAT_RXF_Pos)
#define I2C_RINTRSTAT_RXF                                   I2C_RINTRSTAT_RXF_Msk
#define I2C_RINTRSTAT_TXO_Pos                               (3)
#define I2C_RINTRSTAT_TXO_Msk                               (0x1UL << I2C_RINTRSTAT_TXO_Pos)
#define I2C_RINTRSTAT_TXO                                   I2C_RINTRSTAT_TXO_Msk
#define I2C_RINTRSTAT_TXE_Pos                               (4)
#define I2C_RINTRSTAT_TXE_Msk                               (0x1UL << I2C_RINTRSTAT_TXE_Pos)
#define I2C_RINTRSTAT_TXE                                   I2C_RINTRSTAT_TXE_Msk
#define I2C_RINTRSTAT_RDR_Pos                               (5)
#define I2C_RINTRSTAT_RDR_Msk                               (0x1UL << I2C_RINTRSTAT_RDR_Pos)
#define I2C_RINTRSTAT_RDR                                   I2C_RINTRSTAT_RDR_Msk
#define I2C_RINTRSTAT_TXA_Pos                               (6)
#define I2C_RINTRSTAT_TXA_Msk                               (0x1UL << I2C_RINTRSTAT_TXA_Pos)
#define I2C_RINTRSTAT_TXA                                   I2C_RINTRSTAT_TXA_Msk
#define I2C_RINTRSTAT_RXD_Pos                               (7)
#define I2C_RINTRSTAT_RXD_Msk                               (0x1UL << I2C_RINTRSTAT_RXD_Pos)
#define I2C_RINTRSTAT_RXD                                   I2C_RINTRSTAT_RXD_Msk
#define I2C_RINTRSTAT_ACT_Pos                               (8)
#define I2C_RINTRSTAT_ACT_Msk                               (0x1UL << I2C_RINTRSTAT_ACT_Pos)
#define I2C_RINTRSTAT_ACT                                   I2C_RINTRSTAT_ACT_Msk
#define I2C_RINTRSTAT_STOPD_Pos                             (9)
#define I2C_RINTRSTAT_STOPD_Msk                             (0x1UL << I2C_RINTRSTAT_STOPD_Pos)
#define I2C_RINTRSTAT_STOPD                                 I2C_RINTRSTAT_STOPD_Msk
#define I2C_RINTRSTAT_STARTD_Pos                            (10)
#define I2C_RINTRSTAT_STARTD_Msk                            (0x1UL << I2C_RINTRSTAT_STARTD_Pos)
#define I2C_RINTRSTAT_STARTD                                I2C_RINTRSTAT_STARTD_Msk
#define I2C_RINTRSTAT_GCALL_Pos                             (11)
#define I2C_RINTRSTAT_GCALL_Msk                             (0x1UL << I2C_RINTRSTAT_GCALL_Pos)
#define I2C_RINTRSTAT_GCALL                                 I2C_RINTRSTAT_GCALL_Msk

/***********************  Bits definition for I2C_RXTL  ***********************/
#define I2C_RXTL_RXTL_Pos                                   (0)
#define I2C_RXTL_RXTL_Msk                                   (0xffUL << I2C_RXTL_RXTL_Pos)
#define I2C_RXTL_RXTL                                       I2C_RXTL_RXTL_Msk

/***********************  Bits definition for I2C_TXTL  ***********************/
#define I2C_TXTL_TXTL_Pos                                   (0)
#define I2C_TXTL_TXTL_Msk                                   (0xffUL << I2C_TXTL_TXTL_Pos)
#define I2C_TXTL_TXTL                                       I2C_TXTL_TXTL_Msk

/*********************  Bits definition for I2C_CLRINTR  **********************/
#define I2C_CLRINTR_CLR_Pos                                 (0)
#define I2C_CLRINTR_CLR_Msk                                 (0x1UL << I2C_CLRINTR_CLR_Pos)
#define I2C_CLRINTR_CLR                                     I2C_CLRINTR_CLR_Msk

/********************  Bits definition for I2C_CLRRXUNDER  ********************/
#define I2C_CLRRXU_RXU_Pos                                  (0)
#define I2C_CLRRXU_RXU_Msk                                  (0x1UL << I2C_CLRRXU_RXU_Pos)
#define I2C_CLRRXU_RXU                                      I2C_CLRRXU_RXU_Msk

/********************  Bits definition for I2C_CLRRXOVER  *********************/
#define I2C_CLRRXO_RXO_Pos                                  (0)
#define I2C_CLRRXO_RXO_Msk                                  (0x1UL << I2C_CLRRXO_RXO_Pos)
#define I2C_CLRRXO_RXO                                      I2C_CLRRXO_RXO_Msk

/********************  Bits definition for I2C_CLRTXOVER  *********************/
#define I2C_CLRTXO_TXO_Pos                                  (0)
#define I2C_CLRTXO_TXO_Msk                                  (0x1UL << I2C_CLRTXO_TXO_Pos)
#define I2C_CLRTXO_TXO                                      I2C_CLRTXO_TXO_Msk

/*********************  Bits definition for I2C_CLRRDREQ  *********************/
#define I2C_CLRRDR_RDR_Pos                                  (0)
#define I2C_CLRRDR_RDR_Msk                                  (0x1UL << I2C_CLRRDR_RDR_Pos)
#define I2C_CLRRDR_RDR                                      I2C_CLRRDR_RDR_Msk

/********************  Bits definition for I2C_CLRTXABRT  *********************/
#define I2C_CLRTXA_TXA_Pos                                  (0)
#define I2C_CLRTXA_TXA_Msk                                  (0x1UL << I2C_CLRTXA_TXA_Pos)
#define I2C_CLRTXA_TXA                                      I2C_CLRTXA_TXA_Msk

/********************  Bits definition for I2C_CLRRXDONE  *********************/
#define I2C_CLRRXD_RXD_Pos                                  (0)
#define I2C_CLRRXD_RXD_Msk                                  (0x1UL << I2C_CLRRXD_RXD_Pos)
#define I2C_CLRRXD_RXD                                      I2C_CLRRXD_RXD_Msk

/*******************  Bits definition for I2C_CLRACTIVITY  ********************/
#define I2C_CLRACT_ACT_Pos                                  (0)
#define I2C_CLRACT_ACT_Msk                                  (0x1UL << I2C_CLRACT_ACT_Pos)
#define I2C_CLRACT_ACT                                      I2C_CLRACT_ACT_Msk

/********************  Bits definition for I2C_CLRSTOPDET  ********************/
#define I2C_CLRSTOPD_DET_Pos                                (0)
#define I2C_CLRSTOPD_DET_Msk                                (0x1UL << I2C_CLRSTOPD_DET_Pos)
#define I2C_CLRSTOPD_DET                                    I2C_CLRSTOPD_DET_Msk

/*******************  Bits definition for I2C_CLRSTARTDET  ********************/
#define I2C_CLRSTARTD_DET_Pos                               (0)
#define I2C_CLRSTARTD_DET_Msk                               (0x1UL << I2C_CLRSTARTD_DET_Pos)
#define I2C_CLRSTARTD_DET                                   I2C_CLRSTARTD_DET_Msk

/********************  Bits definition for I2C_CLRGENCALL  ********************/
#define I2C_CLRGCALL_GCALL_Pos                              (0)
#define I2C_CLRGCALL_GCALL_Msk                              (0x1UL << I2C_CLRGCALL_GCALL_Pos)
#define I2C_CLRGCALL_GCALL                                  I2C_CLRGCALL_GCALL_Msk

/**********************  Bits definition for I2C_ENABLE  **********************/
#define I2C_ENABLE_EN_Pos                                   (0)
#define I2C_ENABLE_EN_Msk                                   (0x1UL << I2C_ENABLE_EN_Pos)
#define I2C_ENABLE_EN                                       I2C_ENABLE_EN_Msk
#define I2C_ENABLE_AB_Pos                                   (1)
#define I2C_ENABLE_AB_Msk                                   (0x1UL << I2C_ENABLE_AB_Pos)
#define I2C_ENABLE_AB                                       I2C_ENABLE_AB_Msk

/**********************  Bits definition for I2C_STATUS  **********************/
#define I2C_STATUS_ACT_Pos                                  (0)
#define I2C_STATUS_ACT_Msk                                  (0x1UL << I2C_STATUS_ACT_Pos)
#define I2C_STATUS_ACT                                      I2C_STATUS_ACT_Msk
#define I2C_STATUS_TFNF_Pos                                 (1)
#define I2C_STATUS_TFNF_Msk                                 (0x1UL << I2C_STATUS_TFNF_Pos)
#define I2C_STATUS_TFNF                                     I2C_STATUS_TFNF_Msk
#define I2C_STATUS_TFE_Pos                                  (2)
#define I2C_STATUS_TFE_Msk                                  (0x1UL << I2C_STATUS_TFE_Pos)
#define I2C_STATUS_TFE                                      I2C_STATUS_TFE_Msk
#define I2C_STATUS_RFNE_Pos                                 (3)
#define I2C_STATUS_RFNE_Msk                                 (0x1UL << I2C_STATUS_RFNE_Pos)
#define I2C_STATUS_RFNE                                     I2C_STATUS_RFNE_Msk
#define I2C_STATUS_RFF_Pos                                  (4)
#define I2C_STATUS_RFF_Msk                                  (0x1UL << I2C_STATUS_RFF_Pos)
#define I2C_STATUS_RFF                                      I2C_STATUS_RFF_Msk
#define I2C_STATUS_MSTA_Pos                                 (5)
#define I2C_STATUS_MSTA_Msk                                 (0x1UL << I2C_STATUS_MSTA_Pos)
#define I2C_STATUS_MSTA                                     I2C_STATUS_MSTA_Msk
#define I2C_STATUS_SLVA_Pos                                 (6)
#define I2C_STATUS_SLVA_Msk                                 (0x1UL << I2C_STATUS_SLVA_Pos)
#define I2C_STATUS_SLVA                                     I2C_STATUS_SLVA_Msk

/**********************  Bits definition for I2C_TXFLR  ***********************/
#define I2C_TXFLR_TXFLR_Pos                                 (0)
#define I2C_TXFLR_TXFLR_Msk                                 (0xfUL << I2C_TXFLR_TXFLR_Pos)
#define I2C_TXFLR_TXFLR                                     I2C_TXFLR_TXFLR_Msk
#define I2C_TXFLR_TXFLR_0                                   (0x1UL << I2C_TXFLR_TXFLR_Pos)
#define I2C_TXFLR_TXFLR_1                                   (0x2UL << I2C_TXFLR_TXFLR_Pos)
#define I2C_TXFLR_TXFLR_2                                   (0x4UL << I2C_TXFLR_TXFLR_Pos)
#define I2C_TXFLR_TXFLR_3                                   (0x8UL << I2C_TXFLR_TXFLR_Pos)

/**********************  Bits definition for I2C_RXFLR  ***********************/
#define I2C_RXFLR_RXFLR_Pos                                 (0)
#define I2C_RXFLR_RXFLR_Msk                                 (0xfUL << I2C_RXFLR_RXFLR_Pos)
#define I2C_RXFLR_RXFLR                                     I2C_RXFLR_RXFLR_Msk
#define I2C_RXFLR_RXFLR_0                                   (0x1UL << I2C_RXFLR_RXFLR_Pos)
#define I2C_RXFLR_RXFLR_1                                   (0x2UL << I2C_RXFLR_RXFLR_Pos)
#define I2C_RXFLR_RXFLR_2                                   (0x4UL << I2C_RXFLR_RXFLR_Pos)
#define I2C_RXFLR_RXFLR_3                                   (0x8UL << I2C_RXFLR_RXFLR_Pos)

/*********************  Bits definition for I2C_SDAHOLD  **********************/
#define I2C_SDAH_TX_Pos                                     (0)
#define I2C_SDAH_TX_Msk                                     (0xffffUL << I2C_SDAH_TX_Pos)
#define I2C_SDAH_TX                                         I2C_SDAH_TX_Msk
#define I2C_SDAH_RX_Pos                                     (16)
#define I2C_SDAH_RX_Msk                                     (0xffUL << I2C_SDAH_RX_Pos)
#define I2C_SDAH_RX                                         I2C_SDAH_RX_Msk

/*******************  Bits definition for I2C_TXABRTSOURCE  *******************/
#define I2C_TXAS_7ANACK_Pos                                 (0)
#define I2C_TXAS_7ANACK_Msk                                 (0x1UL << I2C_TXAS_7ANACK_Pos)
#define I2C_TXAS_7ANACK                                     I2C_TXAS_7ANACK_Msk
#define I2C_TXAS_10A1NA_Pos                                 (1)
#define I2C_TXAS_10A1NA_Msk                                 (0x1UL << I2C_TXAS_10A1NA_Pos)
#define I2C_TXAS_10A1NA                                     I2C_TXAS_10A1NA_Msk
#define I2C_TXAS_10A2NA_Pos                                 (2)
#define I2C_TXAS_10A2NA_Msk                                 (0x1UL << I2C_TXAS_10A2NA_Pos)
#define I2C_TXAS_10A2NA                                     I2C_TXAS_10A2NA_Msk
#define I2C_TXAS_TXNACK_Pos                                 (3)
#define I2C_TXAS_TXNACK_Msk                                 (0x1UL << I2C_TXAS_TXNACK_Pos)
#define I2C_TXAS_TXNACK                                     I2C_TXAS_TXNACK_Msk
#define I2C_TXAS_GCNACK_Pos                                 (4)
#define I2C_TXAS_GCNACK_Msk                                 (0x1UL << I2C_TXAS_GCNACK_Pos)
#define I2C_TXAS_GCNACK                                     I2C_TXAS_GCNACK_Msk
#define I2C_TXAS_GCRD_Pos                                   (5)
#define I2C_TXAS_GCRD_Msk                                   (0x1UL << I2C_TXAS_GCRD_Pos)
#define I2C_TXAS_GCRD                                       I2C_TXAS_GCRD_Msk
#define I2C_TXAS_HSADET_Pos                                 (6)
#define I2C_TXAS_HSADET_Msk                                 (0x1UL << I2C_TXAS_HSADET_Pos)
#define I2C_TXAS_HSADET                                     I2C_TXAS_HSADET_Msk
#define I2C_TXAS_STBACK_Pos                                 (7)
#define I2C_TXAS_STBACK_Msk                                 (0x1UL << I2C_TXAS_STBACK_Pos)
#define I2C_TXAS_STBACK                                     I2C_TXAS_STBACK_Msk
#define I2C_TXAS_HSNRST_Pos                                 (8)
#define I2C_TXAS_HSNRST_Msk                                 (0x1UL << I2C_TXAS_HSNRST_Pos)
#define I2C_TXAS_HSNRST                                     I2C_TXAS_HSNRST_Msk
#define I2C_TXAS_SBNRST_Pos                                 (9)
#define I2C_TXAS_SBNRST_Msk                                 (0x1UL << I2C_TXAS_SBNRST_Pos)
#define I2C_TXAS_SBNRST                                     I2C_TXAS_SBNRST_Msk
#define I2C_TXAS_10BRNR_Pos                                 (10)
#define I2C_TXAS_10BRNR_Msk                                 (0x1UL << I2C_TXAS_10BRNR_Pos)
#define I2C_TXAS_10BRNR                                     I2C_TXAS_10BRNR_Msk
#define I2C_TXAS_MSTDIS_Pos                                 (11)
#define I2C_TXAS_MSTDIS_Msk                                 (0x1UL << I2C_TXAS_MSTDIS_Pos)
#define I2C_TXAS_MSTDIS                                     I2C_TXAS_MSTDIS_Msk
#define I2C_TXAS_LOST_Pos                                   (12)
#define I2C_TXAS_LOST_Msk                                   (0x1UL << I2C_TXAS_LOST_Pos)
#define I2C_TXAS_LOST                                       I2C_TXAS_LOST_Msk
#define I2C_TXAS_SFTF_Pos                                   (13)
#define I2C_TXAS_SFTF_Msk                                   (0x1UL << I2C_TXAS_SFTF_Pos)
#define I2C_TXAS_SFTF                                       I2C_TXAS_SFTF_Msk
#define I2C_TXAS_SLOST_Pos                                  (14)
#define I2C_TXAS_SLOST_Msk                                  (0x1UL << I2C_TXAS_SLOST_Pos)
#define I2C_TXAS_SLOST                                      I2C_TXAS_SLOST_Msk
#define I2C_TXAS_SRDITX_Pos                                 (15)
#define I2C_TXAS_SRDITX_Msk                                 (0x1UL << I2C_TXAS_SRDITX_Pos)
#define I2C_TXAS_SRDITX                                     I2C_TXAS_SRDITX_Msk
#define I2C_TXAS_USERAB_Pos                                 (16)
#define I2C_TXAS_USERAB_Msk                                 (0x1UL << I2C_TXAS_USERAB_Pos)
#define I2C_TXAS_USERAB                                     I2C_TXAS_USERAB_Msk
#define I2C_TXAS_FCNT_Pos                                   (24)
#define I2C_TXAS_FCNT_Msk                                   (0xffUL << I2C_TXAS_FCNT_Pos)
#define I2C_TXAS_FCNT                                       I2C_TXAS_FCNT_Msk

/**********************  Bits definition for I2C_DMACR  ***********************/
#define I2C_DMACR_RDMAE_Pos                                 (0)
#define I2C_DMACR_RDMAE_Msk                                 (0x1UL << I2C_DMACR_RDMAE_Pos)
#define I2C_DMACR_RDMAE                                     I2C_DMACR_RDMAE_Msk
#define I2C_DMACR_TDMAE_Pos                                 (1)
#define I2C_DMACR_TDMAE_Msk                                 (0x1UL << I2C_DMACR_TDMAE_Pos)
#define I2C_DMACR_TDMAE                                     I2C_DMACR_TDMAE_Msk

/*********************  Bits definition for I2C_DMATDLR  **********************/
#define I2C_DMATDLR_DMATDLR_Pos                             (0)
#define I2C_DMATDLR_DMATDLR_Msk                             (0xfUL << I2C_DMATDLR_DMATDLR_Pos)
#define I2C_DMATDLR_DMATDLR                                 I2C_DMATDLR_DMATDLR_Msk
#define I2C_DMATDLR_DMATDLR_0                               (0x1UL << I2C_DMATDLR_DMATDLR_Pos)
#define I2C_DMATDLR_DMATDLR_1                               (0x2UL << I2C_DMATDLR_DMATDLR_Pos)
#define I2C_DMATDLR_DMATDLR_2                               (0x4UL << I2C_DMATDLR_DMATDLR_Pos)
#define I2C_DMATDLR_DMATDLR_3                               (0x8UL << I2C_DMATDLR_DMATDLR_Pos)

/*********************  Bits definition for I2C_DMARDLR  **********************/
#define I2C_DMARDLR_DMARDLR_Pos                             (0)
#define I2C_DMARDLR_DMARDLR_Msk                             (0xfUL << I2C_DMARDLR_DMARDLR_Pos)
#define I2C_DMARDLR_DMARDLR                                 I2C_DMARDLR_DMARDLR_Msk
#define I2C_DMARDLR_DMARDLR_0                               (0x1UL << I2C_DMARDLR_DMARDLR_Pos)
#define I2C_DMARDLR_DMARDLR_1                               (0x2UL << I2C_DMARDLR_DMARDLR_Pos)
#define I2C_DMARDLR_DMARDLR_2                               (0x4UL << I2C_DMARDLR_DMARDLR_Pos)
#define I2C_DMARDLR_DMARDLR_3                               (0x8UL << I2C_DMARDLR_DMARDLR_Pos)

/*********************  Bits definition for I2C_SDASETUP  *********************/
#define I2C_SDASETUP_SETUP_Pos                              (0)
#define I2C_SDASETUP_SETUP_Msk                              (0xffUL << I2C_SDASETUP_SETUP_Pos)
#define I2C_SDASETUP_SETUP                                  I2C_SDASETUP_SETUP_Msk

/******************  Bits definition for I2C_ACKGENERALCALL  ******************/
#define I2C_GCACK_ACK_Pos                                   (0)
#define I2C_GCACK_ACK_Msk                                   (0x1UL << I2C_GCACK_ACK_Pos)
#define I2C_GCACK_ACK                                       I2C_GCACK_ACK_Msk

/*******************  Bits definition for I2C_ENABLESTATUS  *******************/
#define I2C_ESTAT_EN_Pos                                    (0)
#define I2C_ESTAT_EN_Msk                                    (0x1UL << I2C_ESTAT_EN_Pos)
#define I2C_ESTAT_EN                                        I2C_ESTAT_EN_Msk
#define I2C_ESTAT_BY_Pos                                    (1)
#define I2C_ESTAT_BY_Msk                                    (0x1UL << I2C_ESTAT_BY_Pos)
#define I2C_ESTAT_BY                                        I2C_ESTAT_BY_Msk
#define I2C_ESTAT_SL_Pos                                    (2)
#define I2C_ESTAT_SL_Msk                                    (0x1UL << I2C_ESTAT_SL_Pos)
#define I2C_ESTAT_SL                                        I2C_ESTAT_SL_Msk

/*********************  Bits definition for I2C_FSSPKLEN  *********************/
#define I2C_FSSPKLEN_LEN_Pos                                (0)
#define I2C_FSSPKLEN_LEN_Msk                                (0xffUL << I2C_FSSPKLEN_LEN_Pos)
#define I2C_FSSPKLEN_LEN                                    I2C_FSSPKLEN_LEN_Msk

/*********************  Bits definition for I2C_HSSPKLEN  *********************/
#define I2C_HSSPKLEN_LEN_Pos                                (0)
#define I2C_HSSPKLEN_LEN_Msk                                (0xffUL << I2C_HSSPKLEN_LEN_Pos)
#define I2C_HSSPKLEN_LEN                                    I2C_HSSPKLEN_LEN_Msk

/******************************************************************************/
/*                                                                            */
/*                                    ICG                                     */
/*                                                                            */
/******************************************************************************/

/*********************  Bits definition for ICG_CLK_CFG  **********************/
#define ICG_CLK_CTL_HCLKSRC_Pos                             (0)
#define ICG_CLK_CTL_HCLKSRC_Msk                             (0x3UL << ICG_CLK_CTL_HCLKSRC_Pos)
#define ICG_CLK_CTL_HCLKSRC                                 ICG_CLK_CTL_HCLKSRC_Msk
#define ICG_CLK_CTL_HCLKSRC_0                               (0x1UL << ICG_CLK_CTL_HCLKSRC_Pos)
#define ICG_CLK_CTL_HCLKSRC_1                               (0x2UL << ICG_CLK_CTL_HCLKSRC_Pos)
#define ICG_CLK_CTL_WDTWSRC_Pos                             (2)
#define ICG_CLK_CTL_WDTWSRC_Msk                             (0x3UL << ICG_CLK_CTL_WDTWSRC_Pos)
#define ICG_CLK_CTL_WDTWSRC                                 ICG_CLK_CTL_WDTWSRC_Msk
#define ICG_CLK_CTL_WDTWSRC_0                               (0x1UL << ICG_CLK_CTL_WDTWSRC_Pos)
#define ICG_CLK_CTL_WDTWSRC_1                               (0x2UL << ICG_CLK_CTL_WDTWSRC_Pos)
#define ICG_CLK_CTL_BRSRC_Pos                               (4)
#define ICG_CLK_CTL_BRSRC_Msk                               (0x3UL << ICG_CLK_CTL_BRSRC_Pos)
#define ICG_CLK_CTL_BRSRC                                   ICG_CLK_CTL_BRSRC_Msk
#define ICG_CLK_CTL_BRSRC_0                                 (0x1UL << ICG_CLK_CTL_BRSRC_Pos)
#define ICG_CLK_CTL_BRSRC_1                                 (0x2UL << ICG_CLK_CTL_BRSRC_Pos)
#define ICG_CLK_CTL_TMRB0SRC_Pos                            (6)
#define ICG_CLK_CTL_TMRB0SRC_Msk                            (0x3UL << ICG_CLK_CTL_TMRB0SRC_Pos)
#define ICG_CLK_CTL_TMRB0SRC                                ICG_CLK_CTL_TMRB0SRC_Msk
#define ICG_CLK_CTL_TMRB0SRC_0                              (0x1UL << ICG_CLK_CTL_TMRB0SRC_Pos)
#define ICG_CLK_CTL_TMRB0SRC_1                              (0x2UL << ICG_CLK_CTL_TMRB0SRC_Pos)
#define ICG_CLK_CTL_I2CSRC_Pos                              (8)
#define ICG_CLK_CTL_I2CSRC_Msk                              (0x3UL << ICG_CLK_CTL_I2CSRC_Pos)
#define ICG_CLK_CTL_I2CSRC                                  ICG_CLK_CTL_I2CSRC_Msk
#define ICG_CLK_CTL_I2CSRC_0                                (0x1UL << ICG_CLK_CTL_I2CSRC_Pos)
#define ICG_CLK_CTL_I2CSRC_1                                (0x2UL << ICG_CLK_CTL_I2CSRC_Pos)
#define ICG_CLK_CTL_TMRB1SRC_Pos                            (10)
#define ICG_CLK_CTL_TMRB1SRC_Msk                            (0x3UL << ICG_CLK_CTL_TMRB1SRC_Pos)
#define ICG_CLK_CTL_TMRB1SRC                                ICG_CLK_CTL_TMRB1SRC_Msk
#define ICG_CLK_CTL_TMRB1SRC_0                              (0x1UL << ICG_CLK_CTL_TMRB1SRC_Pos)
#define ICG_CLK_CTL_TMRB1SRC_1                              (0x2UL << ICG_CLK_CTL_TMRB1SRC_Pos)
#define ICG_CLK_CTL_GPIOSRC_Pos                             (12)
#define ICG_CLK_CTL_GPIOSRC_Msk                             (0x3UL << ICG_CLK_CTL_GPIOSRC_Pos)
#define ICG_CLK_CTL_GPIOSRC                                 ICG_CLK_CTL_GPIOSRC_Msk
#define ICG_CLK_CTL_GPIOSRC_0                               (0x1UL << ICG_CLK_CTL_GPIOSRC_Pos)
#define ICG_CLK_CTL_GPIOSRC_1                               (0x2UL << ICG_CLK_CTL_GPIOSRC_Pos)
#define ICG_CLK_CTL_TMRSRC_Pos                              (14)
#define ICG_CLK_CTL_TMRSRC_Msk                              (0x3UL << ICG_CLK_CTL_TMRSRC_Pos)
#define ICG_CLK_CTL_TMRSRC                                  ICG_CLK_CTL_TMRSRC_Msk
#define ICG_CLK_CTL_TMRSRC_0                                (0x1UL << ICG_CLK_CTL_TMRSRC_Pos)
#define ICG_CLK_CTL_TMRSRC_1                                (0x2UL << ICG_CLK_CTL_TMRSRC_Pos)
#define ICG_CLK_CTL_HSRC_Pos                                (16)
#define ICG_CLK_CTL_HSRC_Msk                                (0x1UL << ICG_CLK_CTL_HSRC_Pos)
#define ICG_CLK_CTL_HSRC                                    ICG_CLK_CTL_HSRC_Msk
#define ICG_CLK_CTL_HSXTAL_Pos                              (17)
#define ICG_CLK_CTL_HSXTAL_Msk                              (0x1UL << ICG_CLK_CTL_HSXTAL_Pos)
#define ICG_CLK_CTL_HSXTAL                                  ICG_CLK_CTL_HSXTAL_Msk
#define ICG_CLK_CTL_HSXTALOUT_Pos                           (18)
#define ICG_CLK_CTL_HSXTALOUT_Msk                           (0x1UL << ICG_CLK_CTL_HSXTALOUT_Pos)
#define ICG_CLK_CTL_HSXTALOUT                               ICG_CLK_CTL_HSXTALOUT_Msk
#define ICG_CLK_CTL_PLL_Pos                                 (19)
#define ICG_CLK_CTL_PLL_Msk                                 (0x1UL << ICG_CLK_CTL_PLL_Pos)
#define ICG_CLK_CTL_PLL                                     ICG_CLK_CTL_PLL_Msk
#define ICG_CLK_CTL_HSXTAL_ITUNE_Pos                        (20)
#define ICG_CLK_CTL_HSXTAL_ITUNE_Msk                        (0xfUL << ICG_CLK_CTL_HSXTAL_ITUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_ITUNE                            ICG_CLK_CTL_HSXTAL_ITUNE_Msk
#define ICG_CLK_CTL_HSXTAL_ITUNE_0                          (0x1UL << ICG_CLK_CTL_HSXTAL_ITUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_ITUNE_1                          (0x2UL << ICG_CLK_CTL_HSXTAL_ITUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_ITUNE_2                          (0x4UL << ICG_CLK_CTL_HSXTAL_ITUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_ITUNE_3                          (0x8UL << ICG_CLK_CTL_HSXTAL_ITUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_CTUNE_Pos                        (24)
#define ICG_CLK_CTL_HSXTAL_CTUNE_Msk                        (0xfUL << ICG_CLK_CTL_HSXTAL_CTUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_CTUNE                            ICG_CLK_CTL_HSXTAL_CTUNE_Msk
#define ICG_CLK_CTL_HSXTAL_CTUNE_0                          (0x1UL << ICG_CLK_CTL_HSXTAL_CTUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_CTUNE_1                          (0x2UL << ICG_CLK_CTL_HSXTAL_CTUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_CTUNE_2                          (0x4UL << ICG_CLK_CTL_HSXTAL_CTUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_CTUNE_3                          (0x8UL << ICG_CLK_CTL_HSXTAL_CTUNE_Pos)
#define ICG_CLK_CTL_HSXTAL_CRES_Pos                         (28)
#define ICG_CLK_CTL_HSXTAL_CRES_Msk                         (0x1UL << ICG_CLK_CTL_HSXTAL_CRES_Pos)
#define ICG_CLK_CTL_HSXTAL_CRES                             ICG_CLK_CTL_HSXTAL_CRES_Msk
#define ICG_CLK_CTL_TEST_OUT_Pos                            (29)
#define ICG_CLK_CTL_TEST_OUT_Msk                            (0x1UL << ICG_CLK_CTL_TEST_OUT_Pos)
#define ICG_CLK_CTL_TEST_OUT                                ICG_CLK_CTL_TEST_OUT_Msk
#define ICG_CLK_CTL_ADCSRC_Pos                              (30)
#define ICG_CLK_CTL_ADCSRC_Msk                              (0x3UL << ICG_CLK_CTL_ADCSRC_Pos)
#define ICG_CLK_CTL_ADCSRC                                  ICG_CLK_CTL_ADCSRC_Msk
#define ICG_CLK_CTL_ADCSRC_0                                (0x1UL << ICG_CLK_CTL_ADCSRC_Pos)
#define ICG_CLK_CTL_ADCSRC_1                                (0x2UL << ICG_CLK_CTL_ADCSRC_Pos)

/*********************  Bits definition for ICG_HCLK_DIV  *********************/
#define ICG_HCLK_DIV_DIV_Pos                                (0)
#define ICG_HCLK_DIV_DIV_Msk                                (0xffffffffUL << ICG_HCLK_DIV_DIV_Pos)
#define ICG_HCLK_DIV_DIV                                    ICG_HCLK_DIV_DIV_Msk

/*********************  Bits definition for ICG_PCLK_DIV  *********************/
#define ICG_PCLK_DIV_DIV_Pos                                (0)
#define ICG_PCLK_DIV_DIV_Msk                                (0xffffffffUL << ICG_PCLK_DIV_DIV_Pos)
#define ICG_PCLK_DIV_DIV                                    ICG_PCLK_DIV_DIV_Msk

/*******************  Bits definition for ICG_DMA_CLK_DIV  ********************/
#define ICG_HSMADDR_HSMAR_Pos                               (0)
#define ICG_HSMADDR_HSMAR_Msk                               (0xffffffffUL << ICG_HSMADDR_HSMAR_Pos)
#define ICG_HSMADDR_HSMAR                                   ICG_HSMADDR_HSMAR_Msk

/********************  Bits definition for ICG_BR_CLK_DIV  ********************/
#define ICG_BR_CLK_DIV_DIV_Pos                              (0)
#define ICG_BR_CLK_DIV_DIV_Msk                              (0xffffffffUL << ICG_BR_CLK_DIV_DIV_Pos)
#define ICG_BR_CLK_DIV_DIV                                  ICG_BR_CLK_DIV_DIV_Msk

/*******************  Bits definition for ICG_I2C0_CLK_DIV  *******************/
#define ICG_I2C0_CLK_DIV_DIV_Pos                            (0)
#define ICG_I2C0_CLK_DIV_DIV_Msk                            (0xffffffffUL << ICG_I2C0_CLK_DIV_DIV_Pos)
#define ICG_I2C0_CLK_DIV_DIV                                ICG_I2C0_CLK_DIV_DIV_Msk

/*******************  Bits definition for ICG_I2C1_CLK_DIV  *******************/
#define ICG_I2C1_CLK_DIV_DIV_Pos                            (0)
#define ICG_I2C1_CLK_DIV_DIV_Msk                            (0xffffffffUL << ICG_I2C1_CLK_DIV_DIV_Pos)
#define ICG_I2C1_CLK_DIV_DIV                                ICG_I2C1_CLK_DIV_DIV_Msk

/*******************  Bits definition for ICG_GPIO_CLK_DIV  *******************/
#define ICG_GPIO_CLK_DIV_DIV_Pos                            (0)
#define ICG_GPIO_CLK_DIV_DIV_Msk                            (0xffffffffUL << ICG_GPIO_CLK_DIV_DIV_Pos)
#define ICG_GPIO_CLK_DIV_DIV                                ICG_GPIO_CLK_DIV_DIV_Msk

/********************  Bits definition for ICG_RC16M_CTRL  ********************/
#define ICG_RC16M_CTRL_CRES_Pos                             (0)
#define ICG_RC16M_CTRL_CRES_Msk                             (0x3fUL << ICG_RC16M_CTRL_CRES_Pos)
#define ICG_RC16M_CTRL_CRES                                 ICG_RC16M_CTRL_CRES_Msk
#define ICG_RC16M_CTRL_CRES_0                               (0x1UL << ICG_RC16M_CTRL_CRES_Pos)
#define ICG_RC16M_CTRL_CRES_1                               (0x2UL << ICG_RC16M_CTRL_CRES_Pos)
#define ICG_RC16M_CTRL_CRES_2                               (0x4UL << ICG_RC16M_CTRL_CRES_Pos)
#define ICG_RC16M_CTRL_CRES_3                               (0x8UL << ICG_RC16M_CTRL_CRES_Pos)
#define ICG_RC16M_CTRL_CRES_4                               (0x10UL << ICG_RC16M_CTRL_CRES_Pos)
#define ICG_RC16M_CTRL_CRES_5                               (0x20UL << ICG_RC16M_CTRL_CRES_Pos)
#define ICG_RC16M_CTRL_CCAP_Pos                             (8)
#define ICG_RC16M_CTRL_CCAP_Msk                             (0x7fUL << ICG_RC16M_CTRL_CCAP_Pos)
#define ICG_RC16M_CTRL_CCAP                                 ICG_RC16M_CTRL_CCAP_Msk
#define ICG_RC16M_CTRL_CCAP_0                               (0x1UL << ICG_RC16M_CTRL_CCAP_Pos)
#define ICG_RC16M_CTRL_CCAP_1                               (0x2UL << ICG_RC16M_CTRL_CCAP_Pos)
#define ICG_RC16M_CTRL_CCAP_2                               (0x4UL << ICG_RC16M_CTRL_CCAP_Pos)
#define ICG_RC16M_CTRL_CCAP_3                               (0x8UL << ICG_RC16M_CTRL_CCAP_Pos)
#define ICG_RC16M_CTRL_CCAP_4                               (0x10UL << ICG_RC16M_CTRL_CCAP_Pos)
#define ICG_RC16M_CTRL_CCAP_5                               (0x20UL << ICG_RC16M_CTRL_CCAP_Pos)
#define ICG_RC16M_CTRL_CCAP_6                               (0x40UL << ICG_RC16M_CTRL_CCAP_Pos)
#define ICG_RC16M_CTRL_CCOMP_Pos                            (16)
#define ICG_RC16M_CTRL_CCOMP_Msk                            (0x7UL << ICG_RC16M_CTRL_CCOMP_Pos)
#define ICG_RC16M_CTRL_CCOMP                                ICG_RC16M_CTRL_CCOMP_Msk
#define ICG_RC16M_CTRL_CCOMP_0                              (0x1UL << ICG_RC16M_CTRL_CCOMP_Pos)
#define ICG_RC16M_CTRL_CCOMP_1                              (0x2UL << ICG_RC16M_CTRL_CCOMP_Pos)
#define ICG_RC16M_CTRL_CCOMP_2                              (0x4UL << ICG_RC16M_CTRL_CCOMP_Pos)
#define ICG_RC16M_CTRL_CBIAS_Pos                            (20)
#define ICG_RC16M_CTRL_CBIAS_Msk                            (0x7UL << ICG_RC16M_CTRL_CBIAS_Pos)
#define ICG_RC16M_CTRL_CBIAS                                ICG_RC16M_CTRL_CBIAS_Msk
#define ICG_RC16M_CTRL_CBIAS_0                              (0x1UL << ICG_RC16M_CTRL_CBIAS_Pos)
#define ICG_RC16M_CTRL_CBIAS_1                              (0x2UL << ICG_RC16M_CTRL_CBIAS_Pos)
#define ICG_RC16M_CTRL_CBIAS_2                              (0x4UL << ICG_RC16M_CTRL_CBIAS_Pos)

/*********************  Bits definition for ICG_PLL_DIV  **********************/
#define ICG_PLL_POSTDIV_Pos                                 (0)
#define ICG_PLL_POSTDIV_Msk                                 (0xfUL << ICG_PLL_POSTDIV_Pos)
#define ICG_PLL_POSTDIV                                     ICG_PLL_POSTDIV_Msk
#define ICG_PLL_POSTDIV_0                                   (0x1UL << ICG_PLL_POSTDIV_Pos)
#define ICG_PLL_POSTDIV_1                                   (0x2UL << ICG_PLL_POSTDIV_Pos)
#define ICG_PLL_POSTDIV_2                                   (0x4UL << ICG_PLL_POSTDIV_Pos)
#define ICG_PLL_POSTDIV_3                                   (0x8UL << ICG_PLL_POSTDIV_Pos)
#define ICG_PLL_FBDIV_Pos                                   (8)
#define ICG_PLL_FBDIV_Msk                                   (0x7fUL << ICG_PLL_FBDIV_Pos)
#define ICG_PLL_FBDIV                                       ICG_PLL_FBDIV_Msk
#define ICG_PLL_FBDIV_0                                     (0x1UL << ICG_PLL_FBDIV_Pos)
#define ICG_PLL_FBDIV_1                                     (0x2UL << ICG_PLL_FBDIV_Pos)
#define ICG_PLL_FBDIV_2                                     (0x4UL << ICG_PLL_FBDIV_Pos)
#define ICG_PLL_FBDIV_3                                     (0x8UL << ICG_PLL_FBDIV_Pos)
#define ICG_PLL_FBDIV_4                                     (0x10UL << ICG_PLL_FBDIV_Pos)
#define ICG_PLL_FBDIV_5                                     (0x20UL << ICG_PLL_FBDIV_Pos)
#define ICG_PLL_FBDIV_6                                     (0x40UL << ICG_PLL_FBDIV_Pos)
#define ICG_PLL_PREDIV_Pos                                  (16)
#define ICG_PLL_PREDIV_Msk                                  (0xfUL << ICG_PLL_PREDIV_Pos)
#define ICG_PLL_PREDIV                                      ICG_PLL_PREDIV_Msk
#define ICG_PLL_PREDIV_0                                    (0x1UL << ICG_PLL_PREDIV_Pos)
#define ICG_PLL_PREDIV_1                                    (0x2UL << ICG_PLL_PREDIV_Pos)
#define ICG_PLL_PREDIV_2                                    (0x4UL << ICG_PLL_PREDIV_Pos)
#define ICG_PLL_PREDIV_3                                    (0x8UL << ICG_PLL_PREDIV_Pos)
#define ICG_PLL_VCOCAP_Pos                                  (20)
#define ICG_PLL_VCOCAP_Msk                                  (0xffUL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOCAP                                      ICG_PLL_VCOCAP_Msk
#define ICG_PLL_VCOCAP_0                                    (0x1UL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOCAP_1                                    (0x2UL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOCAP_2                                    (0x4UL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOCAP_3                                    (0x8UL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOCAP_4                                    (0x10UL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOCAP_5                                    (0x20UL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOCAP_6                                    (0x40UL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOCAP_7                                    (0x80UL << ICG_PLL_VCOCAP_Pos)
#define ICG_PLL_VCOBIAS_Pos                                 (28)
#define ICG_PLL_VCOBIAS_Msk                                 (0x3UL << ICG_PLL_VCOBIAS_Pos)
#define ICG_PLL_VCOBIAS                                     ICG_PLL_VCOBIAS_Msk
#define ICG_PLL_VCOBIAS_0                                   (0x1UL << ICG_PLL_VCOBIAS_Pos)
#define ICG_PLL_VCOBIAS_1                                   (0x2UL << ICG_PLL_VCOBIAS_Pos)
#define ICG_PLL_RBPOSTDIV_Pos                               (30)
#define ICG_PLL_RBPOSTDIV_Msk                               (0x1UL << ICG_PLL_RBPOSTDIV_Pos)
#define ICG_PLL_RBPOSTDIV                                   ICG_PLL_RBPOSTDIV_Msk
#define ICG_PLL_RBFBDIV_Pos                                 (31)
#define ICG_PLL_RBFBDIV_Msk                                 (0x1UL << ICG_PLL_RBFBDIV_Pos)
#define ICG_PLL_RBFBDIV                                     ICG_PLL_RBFBDIV_Msk

/*******************  Bits definition for ICG_PLL_PD_CTRL  ********************/
#define ICG_PLL_PD_CP_Pos                                   (0)
#define ICG_PLL_PD_CP_Msk                                   (0x1UL << ICG_PLL_PD_CP_Pos)
#define ICG_PLL_PD_CP                                       ICG_PLL_PD_CP_Msk
#define ICG_PLL_PD_VCO_Pos                                  (1)
#define ICG_PLL_PD_VCO_Msk                                  (0x1UL << ICG_PLL_PD_VCO_Pos)
#define ICG_PLL_PD_VCO                                      ICG_PLL_PD_VCO_Msk
#define ICG_PLL_PD_PDF_Pos                                  (2)
#define ICG_PLL_PD_PDF_Msk                                  (0x1UL << ICG_PLL_PD_PDF_Pos)
#define ICG_PLL_PD_PDF                                      ICG_PLL_PD_PDF_Msk
#define ICG_PLL_PD_VCOCAL_Pos                               (4)
#define ICG_PLL_PD_VCOCAL_Msk                               (0x1UL << ICG_PLL_PD_VCOCAL_Pos)
#define ICG_PLL_PD_VCOCAL                                   ICG_PLL_PD_VCOCAL_Msk
#define ICG_PLL_PD_VCOBUF_Pos                               (5)
#define ICG_PLL_PD_VCOBUF_Msk                               (0x1UL << ICG_PLL_PD_VCOBUF_Pos)
#define ICG_PLL_PD_VCOBUF                                   ICG_PLL_PD_VCOBUF_Msk
#define ICG_PLL_PD_VCOCOMP_Pos                              (6)
#define ICG_PLL_PD_VCOCOMP_Msk                              (0x1UL << ICG_PLL_PD_VCOCOMP_Pos)
#define ICG_PLL_PD_VCOCOMP                                  ICG_PLL_PD_VCOCOMP_Msk
#define ICG_PLL_VCOCAL_EN_Pos                               (7)
#define ICG_PLL_VCOCAL_EN_Msk                               (0x1UL << ICG_PLL_VCOCAL_EN_Pos)
#define ICG_PLL_VCOCAL_EN                                   ICG_PLL_VCOCAL_EN_Msk
#define ICG_PLL_VCOCAL_AUTOB_Pos                            (8)
#define ICG_PLL_VCOCAL_AUTOB_Msk                            (0x1UL << ICG_PLL_VCOCAL_AUTOB_Pos)
#define ICG_PLL_VCOCAL_AUTOB                                ICG_PLL_VCOCAL_AUTOB_Msk
#define ICG_PLL_VCTST_EN_Pos                                (12)
#define ICG_PLL_VCTST_EN_Msk                                (0x1UL << ICG_PLL_VCTST_EN_Pos)
#define ICG_PLL_VCTST_EN                                    ICG_PLL_VCTST_EN_Msk
#define ICG_PLL_PLLCLKTST_EN_Pos                            (13)
#define ICG_PLL_PLLCLKTST_EN_Msk                            (0x1UL << ICG_PLL_PLLCLKTST_EN_Pos)
#define ICG_PLL_PLLCLKTST_EN                                ICG_PLL_PLLCLKTST_EN_Msk

/******************  Bits definition for ICG_PLL_LFCFG_CTRL  ******************/
#define ICG_PLL_IF_CTRL_Pos                                 (0)
#define ICG_PLL_IF_CTRL_Msk                                 (0xffffffUL << ICG_PLL_IF_CTRL_Pos)
#define ICG_PLL_IF_CTRL                                     ICG_PLL_IF_CTRL_Msk
#define ICG_PLL_CLKSRC_Pos                                  (24)
#define ICG_PLL_CLKSRC_Msk                                  (0x1UL << ICG_PLL_CLKSRC_Pos)
#define ICG_PLL_CLKSRC                                      ICG_PLL_CLKSRC_Msk
#define ICG_PLL_PDF_SLCT_Pos                                (25)
#define ICG_PLL_PDF_SLCT_Msk                                (0x7UL << ICG_PLL_PDF_SLCT_Pos)
#define ICG_PLL_PDF_SLCT                                    ICG_PLL_PDF_SLCT_Msk
#define ICG_PLL_PDF_SLCT_0                                  (0x1UL << ICG_PLL_PDF_SLCT_Pos)
#define ICG_PLL_PDF_SLCT_1                                  (0x2UL << ICG_PLL_PDF_SLCT_Pos)
#define ICG_PLL_PDF_SLCT_2                                  (0x4UL << ICG_PLL_PDF_SLCT_Pos)
#define ICG_PLL_SW_VAR_CTRL_Pos                             (28)
#define ICG_PLL_SW_VAR_CTRL_Msk                             (0x1UL << ICG_PLL_SW_VAR_CTRL_Pos)
#define ICG_PLL_SW_VAR_CTRL                                 ICG_PLL_SW_VAR_CTRL_Msk

/*****************  Bits definition for ICG_PLL_VCOCAL_CTRL  ******************/
#define ICG_VCOCAL_COMPVL_Pos                               (0)
#define ICG_VCOCAL_COMPVL_Msk                               (0x3UL << ICG_VCOCAL_COMPVL_Pos)
#define ICG_VCOCAL_COMPVL                                   ICG_VCOCAL_COMPVL_Msk
#define ICG_VCOCAL_COMPVL_0                                 (0x1UL << ICG_VCOCAL_COMPVL_Pos)
#define ICG_VCOCAL_COMPVL_1                                 (0x2UL << ICG_VCOCAL_COMPVL_Pos)
#define ICG_VCOCAL_COMPVH_Pos                               (2)
#define ICG_VCOCAL_COMPVH_Msk                               (0xfUL << ICG_VCOCAL_COMPVH_Pos)
#define ICG_VCOCAL_COMPVH                                   ICG_VCOCAL_COMPVH_Msk
#define ICG_VCOCAL_COMPVH_0                                 (0x1UL << ICG_VCOCAL_COMPVH_Pos)
#define ICG_VCOCAL_COMPVH_1                                 (0x2UL << ICG_VCOCAL_COMPVH_Pos)
#define ICG_VCOCAL_COMPVH_2                                 (0x4UL << ICG_VCOCAL_COMPVH_Pos)
#define ICG_VCOCAL_COMPVH_3                                 (0x8UL << ICG_VCOCAL_COMPVH_Pos)
#define ICG_VCOCAL_IN_L_RNG_Pos                             (4)
#define ICG_VCOCAL_IN_L_RNG_Msk                             (0x7UL << ICG_VCOCAL_IN_L_RNG_Pos)
#define ICG_VCOCAL_IN_L_RNG                                 ICG_VCOCAL_IN_L_RNG_Msk
#define ICG_VCOCAL_IN_L_RNG_0                               (0x1UL << ICG_VCOCAL_IN_L_RNG_Pos)
#define ICG_VCOCAL_IN_L_RNG_1                               (0x2UL << ICG_VCOCAL_IN_L_RNG_Pos)
#define ICG_VCOCAL_IN_L_RNG_2                               (0x4UL << ICG_VCOCAL_IN_L_RNG_Pos)
#define ICG_VCOCAL_IN_H_RNG_Pos                             (8)
#define ICG_VCOCAL_IN_H_RNG_Msk                             (0x7UL << ICG_VCOCAL_IN_H_RNG_Pos)
#define ICG_VCOCAL_IN_H_RNG                                 ICG_VCOCAL_IN_H_RNG_Msk
#define ICG_VCOCAL_IN_H_RNG_0                               (0x1UL << ICG_VCOCAL_IN_H_RNG_Pos)
#define ICG_VCOCAL_IN_H_RNG_1                               (0x2UL << ICG_VCOCAL_IN_H_RNG_Pos)
#define ICG_VCOCAL_IN_H_RNG_2                               (0x4UL << ICG_VCOCAL_IN_H_RNG_Pos)
#define ICG_VCOCAL_INI_VAL_Pos                              (12)
#define ICG_VCOCAL_INI_VAL_Msk                              (0x7fUL << ICG_VCOCAL_INI_VAL_Pos)
#define ICG_VCOCAL_INI_VAL                                  ICG_VCOCAL_INI_VAL_Msk
#define ICG_VCOCAL_INI_VAL_0                                (0x1UL << ICG_VCOCAL_INI_VAL_Pos)
#define ICG_VCOCAL_INI_VAL_1                                (0x2UL << ICG_VCOCAL_INI_VAL_Pos)
#define ICG_VCOCAL_INI_VAL_2                                (0x4UL << ICG_VCOCAL_INI_VAL_Pos)
#define ICG_VCOCAL_INI_VAL_3                                (0x8UL << ICG_VCOCAL_INI_VAL_Pos)
#define ICG_VCOCAL_INI_VAL_4                                (0x10UL << ICG_VCOCAL_INI_VAL_Pos)
#define ICG_VCOCAL_INI_VAL_5                                (0x20UL << ICG_VCOCAL_INI_VAL_Pos)
#define ICG_VCOCAL_INI_VAL_6                                (0x40UL << ICG_VCOCAL_INI_VAL_Pos)
#define ICG_VCOCAL_STB_TM_Pos                               (20)
#define ICG_VCOCAL_STB_TM_Msk                               (0x7UL << ICG_VCOCAL_STB_TM_Pos)
#define ICG_VCOCAL_STB_TM                                   ICG_VCOCAL_STB_TM_Msk
#define ICG_VCOCAL_STB_TM_0                                 (0x1UL << ICG_VCOCAL_STB_TM_Pos)
#define ICG_VCOCAL_STB_TM_1                                 (0x2UL << ICG_VCOCAL_STB_TM_Pos)
#define ICG_VCOCAL_STB_TM_2                                 (0x4UL << ICG_VCOCAL_STB_TM_Pos)
#define ICG_VCOCAL_CAL_ITVL_Pos                             (24)
#define ICG_VCOCAL_CAL_ITVL_Msk                             (0x7UL << ICG_VCOCAL_CAL_ITVL_Pos)
#define ICG_VCOCAL_CAL_ITVL                                 ICG_VCOCAL_CAL_ITVL_Msk
#define ICG_VCOCAL_CAL_ITVL_0                               (0x1UL << ICG_VCOCAL_CAL_ITVL_Pos)
#define ICG_VCOCAL_CAL_ITVL_1                               (0x2UL << ICG_VCOCAL_CAL_ITVL_Pos)
#define ICG_VCOCAL_CAL_ITVL_2                               (0x4UL << ICG_VCOCAL_CAL_ITVL_Pos)

/******************  Bits definition for ICG_PLL_IREF_CTRL  *******************/
#define ICG_IREF_OCCTRL_Pos                                 (0)
#define ICG_IREF_OCCTRL_Msk                                 (0x7UL << ICG_IREF_OCCTRL_Pos)
#define ICG_IREF_OCCTRL                                     ICG_IREF_OCCTRL_Msk
#define ICG_IREF_OCCTRL_0                                   (0x1UL << ICG_IREF_OCCTRL_Pos)
#define ICG_IREF_OCCTRL_1                                   (0x2UL << ICG_IREF_OCCTRL_Pos)
#define ICG_IREF_OCCTRL_2                                   (0x4UL << ICG_IREF_OCCTRL_Pos)
#define ICG_IREF_CTRL_Pos                                   (4)
#define ICG_IREF_CTRL_Msk                                   (0x7UL << ICG_IREF_CTRL_Pos)
#define ICG_IREF_CTRL                                       ICG_IREF_CTRL_Msk
#define ICG_IREF_CTRL_0                                     (0x1UL << ICG_IREF_CTRL_Pos)
#define ICG_IREF_CTRL_1                                     (0x2UL << ICG_IREF_CTRL_Pos)
#define ICG_IREF_CTRL_2                                     (0x4UL << ICG_IREF_CTRL_Pos)
#define ICG_IREF_VCOCAP_RD_Pos                              (16)
#define ICG_IREF_VCOCAP_RD_Msk                              (0x7fUL << ICG_IREF_VCOCAP_RD_Pos)
#define ICG_IREF_VCOCAP_RD                                  ICG_IREF_VCOCAP_RD_Msk
#define ICG_IREF_VCOCAP_RD_0                                (0x1UL << ICG_IREF_VCOCAP_RD_Pos)
#define ICG_IREF_VCOCAP_RD_1                                (0x2UL << ICG_IREF_VCOCAP_RD_Pos)
#define ICG_IREF_VCOCAP_RD_2                                (0x4UL << ICG_IREF_VCOCAP_RD_Pos)
#define ICG_IREF_VCOCAP_RD_3                                (0x8UL << ICG_IREF_VCOCAP_RD_Pos)
#define ICG_IREF_VCOCAP_RD_4                                (0x10UL << ICG_IREF_VCOCAP_RD_Pos)
#define ICG_IREF_VCOCAP_RD_5                                (0x20UL << ICG_IREF_VCOCAP_RD_Pos)
#define ICG_IREF_VCOCAP_RD_6                                (0x40UL << ICG_IREF_VCOCAP_RD_Pos)
#define ICG_IREF_VCOCAP_WR_Pos                              (24)
#define ICG_IREF_VCOCAP_WR_Msk                              (0x7fUL << ICG_IREF_VCOCAP_WR_Pos)
#define ICG_IREF_VCOCAP_WR                                  ICG_IREF_VCOCAP_WR_Msk
#define ICG_IREF_VCOCAP_WR_0                                (0x1UL << ICG_IREF_VCOCAP_WR_Pos)
#define ICG_IREF_VCOCAP_WR_1                                (0x2UL << ICG_IREF_VCOCAP_WR_Pos)
#define ICG_IREF_VCOCAP_WR_2                                (0x4UL << ICG_IREF_VCOCAP_WR_Pos)
#define ICG_IREF_VCOCAP_WR_3                                (0x8UL << ICG_IREF_VCOCAP_WR_Pos)
#define ICG_IREF_VCOCAP_WR_4                                (0x10UL << ICG_IREF_VCOCAP_WR_Pos)
#define ICG_IREF_VCOCAP_WR_5                                (0x20UL << ICG_IREF_VCOCAP_WR_Pos)
#define ICG_IREF_VCOCAP_WR_6                                (0x40UL << ICG_IREF_VCOCAP_WR_Pos)

/****************  Bits definition for ICG_TIMER_ADV_CLK_DIV  *****************/
#define ICG_TIMACLK_DIV_Pos                                 (0)
#define ICG_TIMACLK_DIV_Msk                                 (0xffffffffUL << ICG_TIMACLK_DIV_Pos)
#define ICG_TIMACLK_DIV                                     ICG_TIMACLK_DIV_Msk

/*****************  Bits definition for ICG_TIMER_B0_CLK_DIV  *****************/
#define ICG_TIMB1_DIV_Pos                                   (0)
#define ICG_TIMB1_DIV_Msk                                   (0xffffffffUL << ICG_TIMB1_DIV_Pos)
#define ICG_TIMB1_DIV                                       ICG_TIMB1_DIV_Msk

/*****************  Bits definition for ICG_TIMER_B1_CLK_DIV  *****************/
#define ICG_TIMB2_DIV_Pos                                   (0)
#define ICG_TIMB2_DIV_Msk                                   (0xffffffffUL << ICG_TIMB2_DIV_Pos)
#define ICG_TIMB2_DIV                                       ICG_TIMB2_DIV_Msk

/******************  Bits definition for ICG_WDT_W_CLK_DIV  *******************/
#define ICG_WDTW_DIV_Pos                                    (0)
#define ICG_WDTW_DIV_Msk                                    (0xffffffffUL << ICG_WDTW_DIV_Pos)
#define ICG_WDTW_DIV                                        ICG_WDTW_DIV_Msk

/******************  Bits definition for ICG_TIMER_EXCLK_EN  ******************/
#define ICG_TMXC_BTMSRC_Pos                                 (0)
#define ICG_TMXC_BTMSRC_Msk                                 (0xffUL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_BTMSRC                                     ICG_TMXC_BTMSRC_Msk
#define ICG_TMXC_BTMSRC_0                                   (0x1UL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_BTMSRC_1                                   (0x2UL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_BTMSRC_2                                   (0x4UL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_BTMSRC_3                                   (0x8UL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_BTMSRC_4                                   (0x10UL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_BTMSRC_5                                   (0x20UL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_BTMSRC_6                                   (0x40UL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_BTMSRC_7                                   (0x80UL << ICG_TMXC_BTMSRC_Pos)
#define ICG_TMXC_GTMSRC_CH_Pos                              (8)
#define ICG_TMXC_GTMSRC_CH_Msk                              (0x1fUL << ICG_TMXC_GTMSRC_CH_Pos)
#define ICG_TMXC_GTMSRC_CH                                  ICG_TMXC_GTMSRC_CH_Msk
#define ICG_TMXC_GTMSRC_CH_0                                (0x1UL << ICG_TMXC_GTMSRC_CH_Pos)
#define ICG_TMXC_GTMSRC_CH_1                                (0x2UL << ICG_TMXC_GTMSRC_CH_Pos)
#define ICG_TMXC_GTMSRC_CH_2                                (0x4UL << ICG_TMXC_GTMSRC_CH_Pos)
#define ICG_TMXC_GTMSRC_CH_3                                (0x8UL << ICG_TMXC_GTMSRC_CH_Pos)
#define ICG_TMXC_GTMSRC_CH_4                                (0x10UL << ICG_TMXC_GTMSRC_CH_Pos)
#define ICG_TMXC_ATMSRC_CH_Pos                              (16)
#define ICG_TMXC_ATMSRC_CH_Msk                              (0x1fUL << ICG_TMXC_ATMSRC_CH_Pos)
#define ICG_TMXC_ATMSRC_CH                                  ICG_TMXC_ATMSRC_CH_Msk
#define ICG_TMXC_ATMSRC_CH_0                                (0x1UL << ICG_TMXC_ATMSRC_CH_Pos)
#define ICG_TMXC_ATMSRC_CH_1                                (0x2UL << ICG_TMXC_ATMSRC_CH_Pos)
#define ICG_TMXC_ATMSRC_CH_2                                (0x4UL << ICG_TMXC_ATMSRC_CH_Pos)
#define ICG_TMXC_ATMSRC_CH_3                                (0x8UL << ICG_TMXC_ATMSRC_CH_Pos)
#define ICG_TMXC_ATMSRC_CH_4                                (0x10UL << ICG_TMXC_ATMSRC_CH_Pos)

/*******************  Bits definition for ICG_ADC_CLK_DIV  ********************/
#define ICG_ADCCLK_DIV_Pos                                  (0)
#define ICG_ADCCLK_DIV_Msk                                  (0xffffffffUL << ICG_ADCCLK_DIV_Pos)
#define ICG_ADCCLK_DIV                                      ICG_ADCCLK_DIV_Msk

/******************************************************************************/
/*                                                                            */
/*                                   ICTL                                     */
/*                                                                            */
/******************************************************************************/

/********************  Bits definition for ICTL_IRQINTENL  ********************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/********************  Bits definition for ICTL_IRQINTENH  ********************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/*******************  Bits definition for ICTL_IRQINTMASKL  *******************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/*******************  Bits definition for ICTL_IRQINTMASKH  *******************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/******************  Bits definition for ICTL_IRQINTFORCEL  *******************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/******************  Bits definition for ICTL_IRQINTFORCEH  *******************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/******************  Bits definition for ICTL_IRQRAWSTATUSL  ******************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/******************  Bits definition for ICTL_IRQRAWSTATUSH  ******************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/*******************  Bits definition for ICTL_IRQSTATUSL  ********************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/*******************  Bits definition for ICTL_IRQSTATUSH  ********************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/*****************  Bits definition for ICTL_IRQMASKSTATUSL  ******************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/*****************  Bits definition for ICTL_IRQMASKSTATUSH  ******************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/*****************  Bits definition for ICTL_IRQFINALSTATUSL  *****************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/*****************  Bits definition for ICTL_IRQFINALSTATUSH  *****************/
#define ICTL_IRQ_CH_Pos                                     (0)
#define ICTL_IRQ_CH_Msk                                     (0xffffffffUL << ICTL_IRQ_CH_Pos)
#define ICTL_IRQ_CH                                         ICTL_IRQ_CH_Msk

/********************  Bits definition for ICTL_FIQINTEN  *********************/
#define ICTL_FIQ_CH_Pos                                     (0)
#define ICTL_FIQ_CH_Msk                                     (0xfUL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH                                         ICTL_FIQ_CH_Msk
#define ICTL_FIQ_CH_0                                       (0x1UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_1                                       (0x2UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_2                                       (0x4UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_3                                       (0x8UL << ICTL_FIQ_CH_Pos)

/*******************  Bits definition for ICTL_FIQINTMASK  ********************/
#define ICTL_FIQ_CH_Pos                                     (0)
#define ICTL_FIQ_CH_Msk                                     (0xfUL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH                                         ICTL_FIQ_CH_Msk
#define ICTL_FIQ_CH_0                                       (0x1UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_1                                       (0x2UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_2                                       (0x4UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_3                                       (0x8UL << ICTL_FIQ_CH_Pos)

/*******************  Bits definition for ICTL_FIQINTFORCE  *******************/
#define ICTL_FIQ_CH_Pos                                     (0)
#define ICTL_FIQ_CH_Msk                                     (0xfUL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH                                         ICTL_FIQ_CH_Msk
#define ICTL_FIQ_CH_0                                       (0x1UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_1                                       (0x2UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_2                                       (0x4UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_3                                       (0x8UL << ICTL_FIQ_CH_Pos)

/******************  Bits definition for ICTL_FIQRAWSTATUS  *******************/
#define ICTL_FIQ_CH_Pos                                     (0)
#define ICTL_FIQ_CH_Msk                                     (0xfUL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH                                         ICTL_FIQ_CH_Msk
#define ICTL_FIQ_CH_0                                       (0x1UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_1                                       (0x2UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_2                                       (0x4UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_3                                       (0x8UL << ICTL_FIQ_CH_Pos)

/********************  Bits definition for ICTL_FIQSTATUS  ********************/
#define ICTL_FIQ_CH_Pos                                     (0)
#define ICTL_FIQ_CH_Msk                                     (0xfUL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH                                         ICTL_FIQ_CH_Msk
#define ICTL_FIQ_CH_0                                       (0x1UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_1                                       (0x2UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_2                                       (0x4UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_3                                       (0x8UL << ICTL_FIQ_CH_Pos)

/*****************  Bits definition for ICTL_FIQFINALSTATUS  ******************/
#define ICTL_FIQ_CH_Pos                                     (0)
#define ICTL_FIQ_CH_Msk                                     (0xfUL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH                                         ICTL_FIQ_CH_Msk
#define ICTL_FIQ_CH_0                                       (0x1UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_1                                       (0x2UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_2                                       (0x4UL << ICTL_FIQ_CH_Pos)
#define ICTL_FIQ_CH_3                                       (0x8UL << ICTL_FIQ_CH_Pos)

/********************  Bits definition for ICTL_IRQPLEVEL  ********************/
#define ICTL_IRQ_PLEVEL_Pos                                 (0)
#define ICTL_IRQ_PLEVEL_Msk                                 (0xfUL << ICTL_IRQ_PLEVEL_Pos)
#define ICTL_IRQ_PLEVEL                                     ICTL_IRQ_PLEVEL_Msk
#define ICTL_IRQ_PLEVEL_0                                   (0x1UL << ICTL_IRQ_PLEVEL_Pos)
#define ICTL_IRQ_PLEVEL_1                                   (0x2UL << ICTL_IRQ_PLEVEL_Pos)
#define ICTL_IRQ_PLEVEL_2                                   (0x4UL << ICTL_IRQ_PLEVEL_Pos)
#define ICTL_IRQ_PLEVEL_3                                   (0x8UL << ICTL_IRQ_PLEVEL_Pos)

/******************************************************************************/
/*                                                                            */
/*                                   MDU                                      */
/*                                                                            */
/******************************************************************************/

/**********************  Bits definition for MDU_PDCTRL  **********************/
#define MDU_PDCTRL_DACPD_Pos                                (0)
#define MDU_PDCTRL_DACPD_Msk                                (0x1UL << MDU_PDCTRL_DACPD_Pos)
#define MDU_PDCTRL_DACPD                                    MDU_PDCTRL_DACPD_Msk
#define MDU_PDCTRL_CMP1PD_Pos                               (4)
#define MDU_PDCTRL_CMP1PD_Msk                               (0x1UL << MDU_PDCTRL_CMP1PD_Pos)
#define MDU_PDCTRL_CMP1PD                                   MDU_PDCTRL_CMP1PD_Msk
#define MDU_PDCTRL_CMP2PD_Pos                               (8)
#define MDU_PDCTRL_CMP2PD_Msk                               (0x1UL << MDU_PDCTRL_CMP2PD_Pos)
#define MDU_PDCTRL_CMP2PD                                   MDU_PDCTRL_CMP2PD_Msk
#define MDU_PDCTRL_CMP3PD_Pos                               (12)
#define MDU_PDCTRL_CMP3PD_Msk                               (0x1UL << MDU_PDCTRL_CMP3PD_Pos)
#define MDU_PDCTRL_CMP3PD                                   MDU_PDCTRL_CMP3PD_Msk
#define MDU_PDCTRL_CMP4PD_Pos                               (16)
#define MDU_PDCTRL_CMP4PD_Msk                               (0x1UL << MDU_PDCTRL_CMP4PD_Pos)
#define MDU_PDCTRL_CMP4PD                                   MDU_PDCTRL_CMP4PD_Msk
#define MDU_PDCTRL_ADCPD_Pos                                (20)
#define MDU_PDCTRL_ADCPD_Msk                                (0x1UL << MDU_PDCTRL_ADCPD_Pos)
#define MDU_PDCTRL_ADCPD                                    MDU_PDCTRL_ADCPD_Msk
#define MDU_PDCTRL_PGAEN1_Pos                               (24)
#define MDU_PDCTRL_PGAEN1_Msk                               (0x1UL << MDU_PDCTRL_PGAEN1_Pos)
#define MDU_PDCTRL_PGAEN1                                   MDU_PDCTRL_PGAEN1_Msk
#define MDU_PDCTRL_PGAEN2_Pos                               (25)
#define MDU_PDCTRL_PGAEN2_Msk                               (0x1UL << MDU_PDCTRL_PGAEN2_Pos)
#define MDU_PDCTRL_PGAEN2                                   MDU_PDCTRL_PGAEN2_Msk
#define MDU_PDCTRL_PGAEN3_Pos                               (26)
#define MDU_PDCTRL_PGAEN3_Msk                               (0x1UL << MDU_PDCTRL_PGAEN3_Pos)
#define MDU_PDCTRL_PGAEN3                                   MDU_PDCTRL_PGAEN3_Msk
#define MDU_PDCTRL_PGAEN4_Pos                               (27)
#define MDU_PDCTRL_PGAEN4_Msk                               (0x1UL << MDU_PDCTRL_PGAEN4_Pos)
#define MDU_PDCTRL_PGAEN4                                   MDU_PDCTRL_PGAEN4_Msk

/*********************  Bits definition for MDU_DAC_CFG  **********************/
#define MDU_DACCFG_DAC1ADD_Pos                              (0)
#define MDU_DACCFG_DAC1ADD_Msk                              (0xffUL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC1ADD                                  MDU_DACCFG_DAC1ADD_Msk
#define MDU_DACCFG_DAC1ADD_0                                (0x1UL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC1ADD_1                                (0x2UL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC1ADD_2                                (0x4UL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC1ADD_3                                (0x8UL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC1ADD_4                                (0x10UL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC1ADD_5                                (0x20UL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC1ADD_6                                (0x40UL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC1ADD_7                                (0x80UL << MDU_DACCFG_DAC1ADD_Pos)
#define MDU_DACCFG_DAC2ADD_Pos                              (8)
#define MDU_DACCFG_DAC2ADD_Msk                              (0xffUL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_DAC2ADD                                  MDU_DACCFG_DAC2ADD_Msk
#define MDU_DACCFG_DAC2ADD_0                                (0x1UL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_DAC2ADD_1                                (0x2UL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_DAC2ADD_2                                (0x4UL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_DAC2ADD_3                                (0x8UL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_DAC2ADD_4                                (0x10UL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_DAC2ADD_5                                (0x20UL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_DAC2ADD_6                                (0x40UL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_DAC2ADD_7                                (0x80UL << MDU_DACCFG_DAC2ADD_Pos)
#define MDU_DACCFG_REFSEL_Pos                               (16)
#define MDU_DACCFG_REFSEL_Msk                               (0x3UL << MDU_DACCFG_REFSEL_Pos)
#define MDU_DACCFG_REFSEL                                   MDU_DACCFG_REFSEL_Msk
#define MDU_DACCFG_REFSEL_0                                 (0x1UL << MDU_DACCFG_REFSEL_Pos)
#define MDU_DACCFG_REFSEL_1                                 (0x2UL << MDU_DACCFG_REFSEL_Pos)
#define MDU_DACCFG_DAC1BBP_Pos                              (20)
#define MDU_DACCFG_DAC1BBP_Msk                              (0x1UL << MDU_DACCFG_DAC1BBP_Pos)
#define MDU_DACCFG_DAC1BBP                                  MDU_DACCFG_DAC1BBP_Msk
#define MDU_DACCFG_DAC2BBP_Pos                              (24)
#define MDU_DACCFG_DAC2BBP_Msk                              (0x1UL << MDU_DACCFG_DAC2BBP_Pos)
#define MDU_DACCFG_DAC2BBP                                  MDU_DACCFG_DAC2BBP_Msk

/*********************  Bits definition for MDU_PGA_CFG  **********************/
#define MDU_PGACFG_PGA1GAIN_Pos                             (0)
#define MDU_PGACFG_PGA1GAIN_Msk                             (0x7UL << MDU_PGACFG_PGA1GAIN_Pos)
#define MDU_PGACFG_PGA1GAIN                                 MDU_PGACFG_PGA1GAIN_Msk
#define MDU_PGACFG_PGA1GAIN_0                               (0x1UL << MDU_PGACFG_PGA1GAIN_Pos)
#define MDU_PGACFG_PGA1GAIN_1                               (0x2UL << MDU_PGACFG_PGA1GAIN_Pos)
#define MDU_PGACFG_PGA1GAIN_2                               (0x4UL << MDU_PGACFG_PGA1GAIN_Pos)
#define MDU_PGACFG_PGA2GAIN_Pos                             (4)
#define MDU_PGACFG_PGA2GAIN_Msk                             (0x7UL << MDU_PGACFG_PGA2GAIN_Pos)
#define MDU_PGACFG_PGA2GAIN                                 MDU_PGACFG_PGA2GAIN_Msk
#define MDU_PGACFG_PGA2GAIN_0                               (0x1UL << MDU_PGACFG_PGA2GAIN_Pos)
#define MDU_PGACFG_PGA2GAIN_1                               (0x2UL << MDU_PGACFG_PGA2GAIN_Pos)
#define MDU_PGACFG_PGA2GAIN_2                               (0x4UL << MDU_PGACFG_PGA2GAIN_Pos)
#define MDU_PGACFG_PGA3GAIN_Pos                             (8)
#define MDU_PGACFG_PGA3GAIN_Msk                             (0x7UL << MDU_PGACFG_PGA3GAIN_Pos)
#define MDU_PGACFG_PGA3GAIN                                 MDU_PGACFG_PGA3GAIN_Msk
#define MDU_PGACFG_PGA3GAIN_0                               (0x1UL << MDU_PGACFG_PGA3GAIN_Pos)
#define MDU_PGACFG_PGA3GAIN_1                               (0x2UL << MDU_PGACFG_PGA3GAIN_Pos)
#define MDU_PGACFG_PGA3GAIN_2                               (0x4UL << MDU_PGACFG_PGA3GAIN_Pos)
#define MDU_PGACFG_PGA4GAIN_Pos                             (12)
#define MDU_PGACFG_PGA4GAIN_Msk                             (0x7UL << MDU_PGACFG_PGA4GAIN_Pos)
#define MDU_PGACFG_PGA4GAIN                                 MDU_PGACFG_PGA4GAIN_Msk
#define MDU_PGACFG_PGA4GAIN_0                               (0x1UL << MDU_PGACFG_PGA4GAIN_Pos)
#define MDU_PGACFG_PGA4GAIN_1                               (0x2UL << MDU_PGACFG_PGA4GAIN_Pos)
#define MDU_PGACFG_PGA4GAIN_2                               (0x4UL << MDU_PGACFG_PGA4GAIN_Pos)

/*********************  Bits definition for MDU_ADC_CFG  **********************/
#define MDU_ADCCFG_CHSLCT_Pos                               (0)
#define MDU_ADCCFG_CHSLCT_Msk                               (0xfUL << MDU_ADCCFG_CHSLCT_Pos)
#define MDU_ADCCFG_CHSLCT                                   MDU_ADCCFG_CHSLCT_Msk
#define MDU_ADCCFG_CHSLCT_0                                 (0x1UL << MDU_ADCCFG_CHSLCT_Pos)
#define MDU_ADCCFG_CHSLCT_1                                 (0x2UL << MDU_ADCCFG_CHSLCT_Pos)
#define MDU_ADCCFG_CHSLCT_2                                 (0x4UL << MDU_ADCCFG_CHSLCT_Pos)
#define MDU_ADCCFG_CHSLCT_3                                 (0x8UL << MDU_ADCCFG_CHSLCT_Pos)
#define MDU_ADCCFG_ICHSLCT_Pos                              (4)
#define MDU_ADCCFG_ICHSLCT_Msk                              (0x3UL << MDU_ADCCFG_ICHSLCT_Pos)
#define MDU_ADCCFG_ICHSLCT                                  MDU_ADCCFG_ICHSLCT_Msk
#define MDU_ADCCFG_ICHSLCT_0                                (0x1UL << MDU_ADCCFG_ICHSLCT_Pos)
#define MDU_ADCCFG_ICHSLCT_1                                (0x2UL << MDU_ADCCFG_ICHSLCT_Pos)
#define MDU_ADCCFG_RESCFG_Pos                               (6)
#define MDU_ADCCFG_RESCFG_Msk                               (0x3UL << MDU_ADCCFG_RESCFG_Pos)
#define MDU_ADCCFG_RESCFG                                   MDU_ADCCFG_RESCFG_Msk
#define MDU_ADCCFG_RESCFG_0                                 (0x1UL << MDU_ADCCFG_RESCFG_Pos)
#define MDU_ADCCFG_RESCFG_1                                 (0x2UL << MDU_ADCCFG_RESCFG_Pos)
#define MDU_ADCCFG_RSTBDLY_Pos                              (12)
#define MDU_ADCCFG_RSTBDLY_Msk                              (0xfUL << MDU_ADCCFG_RSTBDLY_Pos)
#define MDU_ADCCFG_RSTBDLY                                  MDU_ADCCFG_RSTBDLY_Msk
#define MDU_ADCCFG_RSTBDLY_0                                (0x1UL << MDU_ADCCFG_RSTBDLY_Pos)
#define MDU_ADCCFG_RSTBDLY_1                                (0x2UL << MDU_ADCCFG_RSTBDLY_Pos)
#define MDU_ADCCFG_RSTBDLY_2                                (0x4UL << MDU_ADCCFG_RSTBDLY_Pos)
#define MDU_ADCCFG_RSTBDLY_3                                (0x8UL << MDU_ADCCFG_RSTBDLY_Pos)

/********************  Bits definition for MDU_COMP_CFG0  *********************/
#define MDU_CMPCFG1_NSRC_1_Pos                              (0)
#define MDU_CMPCFG1_NSRC_1_Msk                              (0x3UL << MDU_CMPCFG1_NSRC_1_Pos)
#define MDU_CMPCFG1_NSRC_1                                  MDU_CMPCFG1_NSRC_1_Msk
#define MDU_CMPCFG1_NSRC_1_0                                (0x1UL << MDU_CMPCFG1_NSRC_1_Pos)
#define MDU_CMPCFG1_NSRC_1_1                                (0x2UL << MDU_CMPCFG1_NSRC_1_Pos)
#define MDU_CMPCFG1_PSRC_1_Pos                              (4)
#define MDU_CMPCFG1_PSRC_1_Msk                              (0x1UL << MDU_CMPCFG1_PSRC_1_Pos)
#define MDU_CMPCFG1_PSRC_1                                  MDU_CMPCFG1_PSRC_1_Msk
#define MDU_CMPCFG1_NSRC_2_Pos                              (8)
#define MDU_CMPCFG1_NSRC_2_Msk                              (0x3UL << MDU_CMPCFG1_NSRC_2_Pos)
#define MDU_CMPCFG1_NSRC_2                                  MDU_CMPCFG1_NSRC_2_Msk
#define MDU_CMPCFG1_NSRC_2_0                                (0x1UL << MDU_CMPCFG1_NSRC_2_Pos)
#define MDU_CMPCFG1_NSRC_2_1                                (0x2UL << MDU_CMPCFG1_NSRC_2_Pos)
#define MDU_CMPCFG1_PSRC_2_Pos                              (12)
#define MDU_CMPCFG1_PSRC_2_Msk                              (0x1UL << MDU_CMPCFG1_PSRC_2_Pos)
#define MDU_CMPCFG1_PSRC_2                                  MDU_CMPCFG1_PSRC_2_Msk
#define MDU_CMPCFG1_NSRC_3_Pos                              (16)
#define MDU_CMPCFG1_NSRC_3_Msk                              (0x3UL << MDU_CMPCFG1_NSRC_3_Pos)
#define MDU_CMPCFG1_NSRC_3                                  MDU_CMPCFG1_NSRC_3_Msk
#define MDU_CMPCFG1_NSRC_3_0                                (0x1UL << MDU_CMPCFG1_NSRC_3_Pos)
#define MDU_CMPCFG1_NSRC_3_1                                (0x2UL << MDU_CMPCFG1_NSRC_3_Pos)
#define MDU_CMPCFG1_PSRC_3_Pos                              (20)
#define MDU_CMPCFG1_PSRC_3_Msk                              (0x1UL << MDU_CMPCFG1_PSRC_3_Pos)
#define MDU_CMPCFG1_PSRC_3                                  MDU_CMPCFG1_PSRC_3_Msk
#define MDU_CMPCFG1_NSRC_4_Pos                              (24)
#define MDU_CMPCFG1_NSRC_4_Msk                              (0x3UL << MDU_CMPCFG1_NSRC_4_Pos)
#define MDU_CMPCFG1_NSRC_4                                  MDU_CMPCFG1_NSRC_4_Msk
#define MDU_CMPCFG1_NSRC_4_0                                (0x1UL << MDU_CMPCFG1_NSRC_4_Pos)
#define MDU_CMPCFG1_NSRC_4_1                                (0x2UL << MDU_CMPCFG1_NSRC_4_Pos)
#define MDU_CMPCFG1_PSRC_4_Pos                              (28)
#define MDU_CMPCFG1_PSRC_4_Msk                              (0x1UL << MDU_CMPCFG1_PSRC_4_Pos)
#define MDU_CMPCFG1_PSRC_4                                  MDU_CMPCFG1_PSRC_4_Msk

/********************  Bits definition for MDU_COMP_CFG1  *********************/
#define MDU_CMPCFG2_HYS_1_Pos                               (0)
#define MDU_CMPCFG2_HYS_1_Msk                               (0x3UL << MDU_CMPCFG2_HYS_1_Pos)
#define MDU_CMPCFG2_HYS_1                                   MDU_CMPCFG2_HYS_1_Msk
#define MDU_CMPCFG2_HYS_1_0                                 (0x1UL << MDU_CMPCFG2_HYS_1_Pos)
#define MDU_CMPCFG2_HYS_1_1                                 (0x2UL << MDU_CMPCFG2_HYS_1_Pos)
#define MDU_CMPCFG2_SPD_1_Pos                               (4)
#define MDU_CMPCFG2_SPD_1_Msk                               (0x7UL << MDU_CMPCFG2_SPD_1_Pos)
#define MDU_CMPCFG2_SPD_1                                   MDU_CMPCFG2_SPD_1_Msk
#define MDU_CMPCFG2_SPD_1_0                                 (0x1UL << MDU_CMPCFG2_SPD_1_Pos)
#define MDU_CMPCFG2_SPD_1_1                                 (0x2UL << MDU_CMPCFG2_SPD_1_Pos)
#define MDU_CMPCFG2_SPD_1_2                                 (0x4UL << MDU_CMPCFG2_SPD_1_Pos)
#define MDU_CMPCFG2_HYS_2_Pos                               (8)
#define MDU_CMPCFG2_HYS_2_Msk                               (0x3UL << MDU_CMPCFG2_HYS_2_Pos)
#define MDU_CMPCFG2_HYS_2                                   MDU_CMPCFG2_HYS_2_Msk
#define MDU_CMPCFG2_HYS_2_0                                 (0x1UL << MDU_CMPCFG2_HYS_2_Pos)
#define MDU_CMPCFG2_HYS_2_1                                 (0x2UL << MDU_CMPCFG2_HYS_2_Pos)
#define MDU_CMPCFG2_SPD_2_Pos                               (12)
#define MDU_CMPCFG2_SPD_2_Msk                               (0x7UL << MDU_CMPCFG2_SPD_2_Pos)
#define MDU_CMPCFG2_SPD_2                                   MDU_CMPCFG2_SPD_2_Msk
#define MDU_CMPCFG2_SPD_2_0                                 (0x1UL << MDU_CMPCFG2_SPD_2_Pos)
#define MDU_CMPCFG2_SPD_2_1                                 (0x2UL << MDU_CMPCFG2_SPD_2_Pos)
#define MDU_CMPCFG2_SPD_2_2                                 (0x4UL << MDU_CMPCFG2_SPD_2_Pos)
#define MDU_CMPCFG2_HYS_3_Pos                               (16)
#define MDU_CMPCFG2_HYS_3_Msk                               (0x3UL << MDU_CMPCFG2_HYS_3_Pos)
#define MDU_CMPCFG2_HYS_3                                   MDU_CMPCFG2_HYS_3_Msk
#define MDU_CMPCFG2_HYS_3_0                                 (0x1UL << MDU_CMPCFG2_HYS_3_Pos)
#define MDU_CMPCFG2_HYS_3_1                                 (0x2UL << MDU_CMPCFG2_HYS_3_Pos)
#define MDU_CMPCFG2_SPD_3_Pos                               (20)
#define MDU_CMPCFG2_SPD_3_Msk                               (0x7UL << MDU_CMPCFG2_SPD_3_Pos)
#define MDU_CMPCFG2_SPD_3                                   MDU_CMPCFG2_SPD_3_Msk
#define MDU_CMPCFG2_SPD_3_0                                 (0x1UL << MDU_CMPCFG2_SPD_3_Pos)
#define MDU_CMPCFG2_SPD_3_1                                 (0x2UL << MDU_CMPCFG2_SPD_3_Pos)
#define MDU_CMPCFG2_SPD_3_2                                 (0x4UL << MDU_CMPCFG2_SPD_3_Pos)
#define MDU_CMPCFG2_HYS_4_Pos                               (24)
#define MDU_CMPCFG2_HYS_4_Msk                               (0x3UL << MDU_CMPCFG2_HYS_4_Pos)
#define MDU_CMPCFG2_HYS_4                                   MDU_CMPCFG2_HYS_4_Msk
#define MDU_CMPCFG2_HYS_4_0                                 (0x1UL << MDU_CMPCFG2_HYS_4_Pos)
#define MDU_CMPCFG2_HYS_4_1                                 (0x2UL << MDU_CMPCFG2_HYS_4_Pos)
#define MDU_CMPCFG2_SPD_4_Pos                               (28)
#define MDU_CMPCFG2_SPD_4_Msk                               (0x7UL << MDU_CMPCFG2_SPD_4_Pos)
#define MDU_CMPCFG2_SPD_4                                   MDU_CMPCFG2_SPD_4_Msk
#define MDU_CMPCFG2_SPD_4_0                                 (0x1UL << MDU_CMPCFG2_SPD_4_Pos)
#define MDU_CMPCFG2_SPD_4_1                                 (0x2UL << MDU_CMPCFG2_SPD_4_Pos)
#define MDU_CMPCFG2_SPD_4_2                                 (0x4UL << MDU_CMPCFG2_SPD_4_Pos)

/********************  Bits definition for MDU_COMP_CFG2  *********************/
#define MDU_CMPCFG3_OPOL_Pos                                (0)
#define MDU_CMPCFG3_OPOL_Msk                                (0xfUL << MDU_CMPCFG3_OPOL_Pos)
#define MDU_CMPCFG3_OPOL                                    MDU_CMPCFG3_OPOL_Msk
#define MDU_CMPCFG3_OPOL_0                                  (0x1UL << MDU_CMPCFG3_OPOL_Pos)
#define MDU_CMPCFG3_OPOL_1                                  (0x2UL << MDU_CMPCFG3_OPOL_Pos)
#define MDU_CMPCFG3_OPOL_2                                  (0x4UL << MDU_CMPCFG3_OPOL_Pos)
#define MDU_CMPCFG3_OPOL_3                                  (0x8UL << MDU_CMPCFG3_OPOL_Pos)
#define MDU_CMPCFG3_OFLT_Pos                                (4)
#define MDU_CMPCFG3_OFLT_Msk                                (0x1UL << MDU_CMPCFG3_OFLT_Pos)
#define MDU_CMPCFG3_OFLT                                    MDU_CMPCFG3_OFLT_Msk

/********************  Bits definition for MDU_ADC_STATUS  ********************/
#define MDU_ADCST_CMPOUT_Pos                                (0)
#define MDU_ADCST_CMPOUT_Msk                                (0xfUL << MDU_ADCST_CMPOUT_Pos)
#define MDU_ADCST_CMPOUT                                    MDU_ADCST_CMPOUT_Msk
#define MDU_ADCST_CMPOUT_0                                  (0x1UL << MDU_ADCST_CMPOUT_Pos)
#define MDU_ADCST_CMPOUT_1                                  (0x2UL << MDU_ADCST_CMPOUT_Pos)
#define MDU_ADCST_CMPOUT_2                                  (0x4UL << MDU_ADCST_CMPOUT_Pos)
#define MDU_ADCST_CMPOUT_3                                  (0x8UL << MDU_ADCST_CMPOUT_Pos)
#define MDU_ADCST_EOC_Pos                                   (5)
#define MDU_ADCST_EOC_Msk                                   (0x1UL << MDU_ADCST_EOC_Pos)
#define MDU_ADCST_EOC                                       MDU_ADCST_EOC_Msk
#define MDU_ADCST_EOS_Pos                                   (6)
#define MDU_ADCST_EOS_Msk                                   (0x1UL << MDU_ADCST_EOS_Pos)
#define MDU_ADCST_EOS                                       MDU_ADCST_EOS_Msk

/*******************  Bits definition for MDU_ADC_RESULTS  ********************/
#define MDU_ADC_OUTPUT_DATA_Pos                             (0)
#define MDU_ADC_OUTPUT_DATA_Msk                             (0xfffUL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA                                 MDU_ADC_OUTPUT_DATA_Msk
#define MDU_ADC_OUTPUT_DATA_0                               (0x1UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_1                               (0x2UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_2                               (0x4UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_3                               (0x8UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_4                               (0x10UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_5                               (0x20UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_6                               (0x40UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_7                               (0x80UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_8                               (0x100UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_9                               (0x200UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_10                              (0x400UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_OUTPUT_DATA_11                              (0x800UL << MDU_ADC_OUTPUT_DATA_Pos)
#define MDU_ADC_EOC_Pos                                     (31)
#define MDU_ADC_EOC_Msk                                     (0x1UL << MDU_ADC_EOC_Pos)
#define MDU_ADC_EOC                                         MDU_ADC_EOC_Msk

/*********************  Bits definition for MDU_ADC_CTRL  *********************/
#define MDU_ADCCTRL_TRGISRC_Pos                             (0)
#define MDU_ADCCTRL_TRGISRC_Msk                             (0xfUL << MDU_ADCCTRL_TRGISRC_Pos)
#define MDU_ADCCTRL_TRGISRC                                 MDU_ADCCTRL_TRGISRC_Msk
#define MDU_ADCCTRL_TRGISRC_0                               (0x1UL << MDU_ADCCTRL_TRGISRC_Pos)
#define MDU_ADCCTRL_TRGISRC_1                               (0x2UL << MDU_ADCCTRL_TRGISRC_Pos)
#define MDU_ADCCTRL_TRGISRC_2                               (0x4UL << MDU_ADCCTRL_TRGISRC_Pos)
#define MDU_ADCCTRL_TRGISRC_3                               (0x8UL << MDU_ADCCTRL_TRGISRC_Pos)
#define MDU_ADCCTRL_RISEEDGE_Pos                            (4)
#define MDU_ADCCTRL_RISEEDGE_Msk                            (0x1UL << MDU_ADCCTRL_RISEEDGE_Pos)
#define MDU_ADCCTRL_RISEEDGE                                MDU_ADCCTRL_RISEEDGE_Msk
#define MDU_ADCCTRL_FALLEDGE_Pos                            (5)
#define MDU_ADCCTRL_FALLEDGE_Msk                            (0x1UL << MDU_ADCCTRL_FALLEDGE_Pos)
#define MDU_ADCCTRL_FALLEDGE                                MDU_ADCCTRL_FALLEDGE_Msk
#define MDU_ADCCTRL_SWTRG_Pos                               (6)
#define MDU_ADCCTRL_SWTRG_Msk                               (0x1UL << MDU_ADCCTRL_SWTRG_Pos)
#define MDU_ADCCTRL_SWTRG                                   MDU_ADCCTRL_SWTRG_Msk
#define MDU_ADCCTRL_SEQ_STRT_Pos                            (7)
#define MDU_ADCCTRL_SEQ_STRT_Msk                            (0x1UL << MDU_ADCCTRL_SEQ_STRT_Pos)
#define MDU_ADCCTRL_SEQ_STRT                                MDU_ADCCTRL_SEQ_STRT_Msk
#define MDU_ADCCTRL_CONV_MODE_Pos                           (8)
#define MDU_ADCCTRL_CONV_MODE_Msk                           (0x3UL << MDU_ADCCTRL_CONV_MODE_Pos)
#define MDU_ADCCTRL_CONV_MODE                               MDU_ADCCTRL_CONV_MODE_Msk
#define MDU_ADCCTRL_CONV_MODE_0                             (0x1UL << MDU_ADCCTRL_CONV_MODE_Pos)
#define MDU_ADCCTRL_CONV_MODE_1                             (0x2UL << MDU_ADCCTRL_CONV_MODE_Pos)
#define MDU_ADCCTRL_CH_MODE_Pos                             (10)
#define MDU_ADCCTRL_CH_MODE_Msk                             (0x1UL << MDU_ADCCTRL_CH_MODE_Pos)
#define MDU_ADCCTRL_CH_MODE                                 MDU_ADCCTRL_CH_MODE_Msk
#define MDU_ADCCTRL_RST_Pos                                 (11)
#define MDU_ADCCTRL_RST_Msk                                 (0x1UL << MDU_ADCCTRL_RST_Pos)
#define MDU_ADCCTRL_RST                                     MDU_ADCCTRL_RST_Msk
#define MDU_ADCCTRL_PGASMPW_Pos                             (12)
#define MDU_ADCCTRL_PGASMPW_Msk                             (0xfUL << MDU_ADCCTRL_PGASMPW_Pos)
#define MDU_ADCCTRL_PGASMPW                                 MDU_ADCCTRL_PGASMPW_Msk
#define MDU_ADCCTRL_PGASMPW_0                               (0x1UL << MDU_ADCCTRL_PGASMPW_Pos)
#define MDU_ADCCTRL_PGASMPW_1                               (0x2UL << MDU_ADCCTRL_PGASMPW_Pos)
#define MDU_ADCCTRL_PGASMPW_2                               (0x4UL << MDU_ADCCTRL_PGASMPW_Pos)
#define MDU_ADCCTRL_PGASMPW_3                               (0x8UL << MDU_ADCCTRL_PGASMPW_Pos)
#define MDU_ADCCTRL_GCHIND_Pos                              (16)
#define MDU_ADCCTRL_GCHIND_Msk                              (0xffffUL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND                                  MDU_ADCCTRL_GCHIND_Msk
#define MDU_ADCCTRL_GCHIND_0                                (0x1UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_1                                (0x2UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_2                                (0x4UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_3                                (0x8UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_4                                (0x10UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_5                                (0x20UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_6                                (0x40UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_7                                (0x80UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_8                                (0x100UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_9                                (0x200UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_10                               (0x400UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_11                               (0x800UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_12                               (0x1000UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_13                               (0x2000UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_14                               (0x4000UL << MDU_ADCCTRL_GCHIND_Pos)
#define MDU_ADCCTRL_GCHIND_15                               (0x8000UL << MDU_ADCCTRL_GCHIND_Pos)

/*****************  Bits definition for MDU_ADC_RESULTS_CH0  ******************/
#define MDU_ADCRSLT_RSLT_CHX_Pos                            (0)
#define MDU_ADCRSLT_RSLT_CHX_Msk                            (0xfffUL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX                                MDU_ADCRSLT_RSLT_CHX_Msk
#define MDU_ADCRSLT_RSLT_CHX_0                              (0x1UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_1                              (0x2UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_2                              (0x4UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_3                              (0x8UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_4                              (0x10UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_5                              (0x20UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_6                              (0x40UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_7                              (0x80UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_8                              (0x100UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_9                              (0x200UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_10                             (0x400UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_RSLT_CHX_11                             (0x800UL << MDU_ADCRSLT_RSLT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_Pos                             (16)
#define MDU_ADCRSLT_OUT_CHX_Msk                             (0xfffUL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX                                 MDU_ADCRSLT_OUT_CHX_Msk
#define MDU_ADCRSLT_OUT_CHX_0                               (0x1UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_1                               (0x2UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_2                               (0x4UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_3                               (0x8UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_4                               (0x10UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_5                               (0x20UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_6                               (0x40UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_7                               (0x80UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_8                               (0x100UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_9                               (0x200UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_10                              (0x400UL << MDU_ADCRSLT_OUT_CHX_Pos)
#define MDU_ADCRSLT_OUT_CHX_11                              (0x800UL << MDU_ADCRSLT_OUT_CHX_Pos)

/*****************  Bits definition for MDU_ADC_RESULTS_CH1  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH2  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH3  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH4  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH5  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH6  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH7  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH8  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH9  ******************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH10  *****************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH11  *****************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH12  *****************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH13  *****************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH14  *****************/

/*****************  Bits definition for MDU_ADC_RESULTS_CH15  *****************/

/******************************************************************************/
/*                                                                            */
/*                                   PADI                                     */
/*                                                                            */
/******************************************************************************/

/******************  Bits definition for PADI_PORTMUX_CFG_1  ******************/
#define PADI_PINCFG_PIN_0_Pos                               (0)
#define PADI_PINCFG_PIN_0_Msk                               (0xfUL << PADI_PINCFG_PIN_0_Pos)
#define PADI_PINCFG_PIN_0                                   PADI_PINCFG_PIN_0_Msk
#define PADI_PINCFG_PIN_0_0                                 (0x1UL << PADI_PINCFG_PIN_0_Pos)
#define PADI_PINCFG_PIN_0_1                                 (0x2UL << PADI_PINCFG_PIN_0_Pos)
#define PADI_PINCFG_PIN_0_2                                 (0x4UL << PADI_PINCFG_PIN_0_Pos)
#define PADI_PINCFG_PIN_0_3                                 (0x8UL << PADI_PINCFG_PIN_0_Pos)
#define PADI_PINCFG_PIN_1_Pos                               (4)
#define PADI_PINCFG_PIN_1_Msk                               (0xfUL << PADI_PINCFG_PIN_1_Pos)
#define PADI_PINCFG_PIN_1                                   PADI_PINCFG_PIN_1_Msk
#define PADI_PINCFG_PIN_1_0                                 (0x1UL << PADI_PINCFG_PIN_1_Pos)
#define PADI_PINCFG_PIN_1_1                                 (0x2UL << PADI_PINCFG_PIN_1_Pos)
#define PADI_PINCFG_PIN_1_2                                 (0x4UL << PADI_PINCFG_PIN_1_Pos)
#define PADI_PINCFG_PIN_1_3                                 (0x8UL << PADI_PINCFG_PIN_1_Pos)
#define PADI_PINCFG_PIN_2_Pos                               (8)
#define PADI_PINCFG_PIN_2_Msk                               (0xfUL << PADI_PINCFG_PIN_2_Pos)
#define PADI_PINCFG_PIN_2                                   PADI_PINCFG_PIN_2_Msk
#define PADI_PINCFG_PIN_2_0                                 (0x1UL << PADI_PINCFG_PIN_2_Pos)
#define PADI_PINCFG_PIN_2_1                                 (0x2UL << PADI_PINCFG_PIN_2_Pos)
#define PADI_PINCFG_PIN_2_2                                 (0x4UL << PADI_PINCFG_PIN_2_Pos)
#define PADI_PINCFG_PIN_2_3                                 (0x8UL << PADI_PINCFG_PIN_2_Pos)
#define PADI_PINCFG_PIN_3_Pos                               (12)
#define PADI_PINCFG_PIN_3_Msk                               (0xfUL << PADI_PINCFG_PIN_3_Pos)
#define PADI_PINCFG_PIN_3                                   PADI_PINCFG_PIN_3_Msk
#define PADI_PINCFG_PIN_3_0                                 (0x1UL << PADI_PINCFG_PIN_3_Pos)
#define PADI_PINCFG_PIN_3_1                                 (0x2UL << PADI_PINCFG_PIN_3_Pos)
#define PADI_PINCFG_PIN_3_2                                 (0x4UL << PADI_PINCFG_PIN_3_Pos)
#define PADI_PINCFG_PIN_3_3                                 (0x8UL << PADI_PINCFG_PIN_3_Pos)
#define PADI_PINCFG_PIN_4_Pos                               (16)
#define PADI_PINCFG_PIN_4_Msk                               (0xfUL << PADI_PINCFG_PIN_4_Pos)
#define PADI_PINCFG_PIN_4                                   PADI_PINCFG_PIN_4_Msk
#define PADI_PINCFG_PIN_4_0                                 (0x1UL << PADI_PINCFG_PIN_4_Pos)
#define PADI_PINCFG_PIN_4_1                                 (0x2UL << PADI_PINCFG_PIN_4_Pos)
#define PADI_PINCFG_PIN_4_2                                 (0x4UL << PADI_PINCFG_PIN_4_Pos)
#define PADI_PINCFG_PIN_4_3                                 (0x8UL << PADI_PINCFG_PIN_4_Pos)
#define PADI_PINCFG_PIN_5_Pos                               (20)
#define PADI_PINCFG_PIN_5_Msk                               (0xfUL << PADI_PINCFG_PIN_5_Pos)
#define PADI_PINCFG_PIN_5                                   PADI_PINCFG_PIN_5_Msk
#define PADI_PINCFG_PIN_5_0                                 (0x1UL << PADI_PINCFG_PIN_5_Pos)
#define PADI_PINCFG_PIN_5_1                                 (0x2UL << PADI_PINCFG_PIN_5_Pos)
#define PADI_PINCFG_PIN_5_2                                 (0x4UL << PADI_PINCFG_PIN_5_Pos)
#define PADI_PINCFG_PIN_5_3                                 (0x8UL << PADI_PINCFG_PIN_5_Pos)
#define PADI_PINCFG_PIN_6_Pos                               (24)
#define PADI_PINCFG_PIN_6_Msk                               (0xfUL << PADI_PINCFG_PIN_6_Pos)
#define PADI_PINCFG_PIN_6                                   PADI_PINCFG_PIN_6_Msk
#define PADI_PINCFG_PIN_6_0                                 (0x1UL << PADI_PINCFG_PIN_6_Pos)
#define PADI_PINCFG_PIN_6_1                                 (0x2UL << PADI_PINCFG_PIN_6_Pos)
#define PADI_PINCFG_PIN_6_2                                 (0x4UL << PADI_PINCFG_PIN_6_Pos)
#define PADI_PINCFG_PIN_6_3                                 (0x8UL << PADI_PINCFG_PIN_6_Pos)
#define PADI_PINCFG_PIN_7_Pos                               (28)
#define PADI_PINCFG_PIN_7_Msk                               (0xfUL << PADI_PINCFG_PIN_7_Pos)
#define PADI_PINCFG_PIN_7                                   PADI_PINCFG_PIN_7_Msk
#define PADI_PINCFG_PIN_7_0                                 (0x1UL << PADI_PINCFG_PIN_7_Pos)
#define PADI_PINCFG_PIN_7_1                                 (0x2UL << PADI_PINCFG_PIN_7_Pos)
#define PADI_PINCFG_PIN_7_2                                 (0x4UL << PADI_PINCFG_PIN_7_Pos)
#define PADI_PINCFG_PIN_7_3                                 (0x8UL << PADI_PINCFG_PIN_7_Pos)

/******************  Bits definition for PADI_PORTMUX_CFG_2  ******************/
#define PADI_PINCFG_PIN_8_Pos                               (0)
#define PADI_PINCFG_PIN_8_Msk                               (0xfUL << PADI_PINCFG_PIN_8_Pos)
#define PADI_PINCFG_PIN_8                                   PADI_PINCFG_PIN_8_Msk
#define PADI_PINCFG_PIN_8_0                                 (0x1UL << PADI_PINCFG_PIN_8_Pos)
#define PADI_PINCFG_PIN_8_1                                 (0x2UL << PADI_PINCFG_PIN_8_Pos)
#define PADI_PINCFG_PIN_8_2                                 (0x4UL << PADI_PINCFG_PIN_8_Pos)
#define PADI_PINCFG_PIN_8_3                                 (0x8UL << PADI_PINCFG_PIN_8_Pos)
#define PADI_PINCFG_PIN_9_Pos                               (4)
#define PADI_PINCFG_PIN_9_Msk                               (0xfUL << PADI_PINCFG_PIN_9_Pos)
#define PADI_PINCFG_PIN_9                                   PADI_PINCFG_PIN_9_Msk
#define PADI_PINCFG_PIN_9_0                                 (0x1UL << PADI_PINCFG_PIN_9_Pos)
#define PADI_PINCFG_PIN_9_1                                 (0x2UL << PADI_PINCFG_PIN_9_Pos)
#define PADI_PINCFG_PIN_9_2                                 (0x4UL << PADI_PINCFG_PIN_9_Pos)
#define PADI_PINCFG_PIN_9_3                                 (0x8UL << PADI_PINCFG_PIN_9_Pos)
#define PADI_PINCFG_PIN_10_Pos                              (8)
#define PADI_PINCFG_PIN_10_Msk                              (0xfUL << PADI_PINCFG_PIN_10_Pos)
#define PADI_PINCFG_PIN_10                                  PADI_PINCFG_PIN_10_Msk
#define PADI_PINCFG_PIN_10_0                                (0x1UL << PADI_PINCFG_PIN_10_Pos)
#define PADI_PINCFG_PIN_10_1                                (0x2UL << PADI_PINCFG_PIN_10_Pos)
#define PADI_PINCFG_PIN_10_2                                (0x4UL << PADI_PINCFG_PIN_10_Pos)
#define PADI_PINCFG_PIN_10_3                                (0x8UL << PADI_PINCFG_PIN_10_Pos)
#define PADI_PINCFG_PIN_11_Pos                              (12)
#define PADI_PINCFG_PIN_11_Msk                              (0xfUL << PADI_PINCFG_PIN_11_Pos)
#define PADI_PINCFG_PIN_11                                  PADI_PINCFG_PIN_11_Msk
#define PADI_PINCFG_PIN_11_0                                (0x1UL << PADI_PINCFG_PIN_11_Pos)
#define PADI_PINCFG_PIN_11_1                                (0x2UL << PADI_PINCFG_PIN_11_Pos)
#define PADI_PINCFG_PIN_11_2                                (0x4UL << PADI_PINCFG_PIN_11_Pos)
#define PADI_PINCFG_PIN_11_3                                (0x8UL << PADI_PINCFG_PIN_11_Pos)
#define PADI_PINCFG_PIN_12_Pos                              (16)
#define PADI_PINCFG_PIN_12_Msk                              (0xfUL << PADI_PINCFG_PIN_12_Pos)
#define PADI_PINCFG_PIN_12                                  PADI_PINCFG_PIN_12_Msk
#define PADI_PINCFG_PIN_12_0                                (0x1UL << PADI_PINCFG_PIN_12_Pos)
#define PADI_PINCFG_PIN_12_1                                (0x2UL << PADI_PINCFG_PIN_12_Pos)
#define PADI_PINCFG_PIN_12_2                                (0x4UL << PADI_PINCFG_PIN_12_Pos)
#define PADI_PINCFG_PIN_12_3                                (0x8UL << PADI_PINCFG_PIN_12_Pos)
#define PADI_PINCFG_PIN_13_Pos                              (20)
#define PADI_PINCFG_PIN_13_Msk                              (0xfUL << PADI_PINCFG_PIN_13_Pos)
#define PADI_PINCFG_PIN_13                                  PADI_PINCFG_PIN_13_Msk
#define PADI_PINCFG_PIN_13_0                                (0x1UL << PADI_PINCFG_PIN_13_Pos)
#define PADI_PINCFG_PIN_13_1                                (0x2UL << PADI_PINCFG_PIN_13_Pos)
#define PADI_PINCFG_PIN_13_2                                (0x4UL << PADI_PINCFG_PIN_13_Pos)
#define PADI_PINCFG_PIN_13_3                                (0x8UL << PADI_PINCFG_PIN_13_Pos)
#define PADI_PINCFG_PIN_14_Pos                              (24)
#define PADI_PINCFG_PIN_14_Msk                              (0xfUL << PADI_PINCFG_PIN_14_Pos)
#define PADI_PINCFG_PIN_14                                  PADI_PINCFG_PIN_14_Msk
#define PADI_PINCFG_PIN_14_0                                (0x1UL << PADI_PINCFG_PIN_14_Pos)
#define PADI_PINCFG_PIN_14_1                                (0x2UL << PADI_PINCFG_PIN_14_Pos)
#define PADI_PINCFG_PIN_14_2                                (0x4UL << PADI_PINCFG_PIN_14_Pos)
#define PADI_PINCFG_PIN_14_3                                (0x8UL << PADI_PINCFG_PIN_14_Pos)
#define PADI_PINCFG_PIN_15_Pos                              (28)
#define PADI_PINCFG_PIN_15_Msk                              (0xfUL << PADI_PINCFG_PIN_15_Pos)
#define PADI_PINCFG_PIN_15                                  PADI_PINCFG_PIN_15_Msk
#define PADI_PINCFG_PIN_15_0                                (0x1UL << PADI_PINCFG_PIN_15_Pos)
#define PADI_PINCFG_PIN_15_1                                (0x2UL << PADI_PINCFG_PIN_15_Pos)
#define PADI_PINCFG_PIN_15_2                                (0x4UL << PADI_PINCFG_PIN_15_Pos)
#define PADI_PINCFG_PIN_15_3                                (0x8UL << PADI_PINCFG_PIN_15_Pos)

/******************  Bits definition for PADI_PORTMUX_CFG_3  ******************/
#define PADI_PINCFG_PIN_16_Pos                              (0)
#define PADI_PINCFG_PIN_16_Msk                              (0xfUL << PADI_PINCFG_PIN_16_Pos)
#define PADI_PINCFG_PIN_16                                  PADI_PINCFG_PIN_16_Msk
#define PADI_PINCFG_PIN_16_0                                (0x1UL << PADI_PINCFG_PIN_16_Pos)
#define PADI_PINCFG_PIN_16_1                                (0x2UL << PADI_PINCFG_PIN_16_Pos)
#define PADI_PINCFG_PIN_16_2                                (0x4UL << PADI_PINCFG_PIN_16_Pos)
#define PADI_PINCFG_PIN_16_3                                (0x8UL << PADI_PINCFG_PIN_16_Pos)
#define PADI_PINCFG_PIN_17_Pos                              (4)
#define PADI_PINCFG_PIN_17_Msk                              (0xfUL << PADI_PINCFG_PIN_17_Pos)
#define PADI_PINCFG_PIN_17                                  PADI_PINCFG_PIN_17_Msk
#define PADI_PINCFG_PIN_17_0                                (0x1UL << PADI_PINCFG_PIN_17_Pos)
#define PADI_PINCFG_PIN_17_1                                (0x2UL << PADI_PINCFG_PIN_17_Pos)
#define PADI_PINCFG_PIN_17_2                                (0x4UL << PADI_PINCFG_PIN_17_Pos)
#define PADI_PINCFG_PIN_17_3                                (0x8UL << PADI_PINCFG_PIN_17_Pos)
#define PADI_PINCFG_PIN_18_Pos                              (8)
#define PADI_PINCFG_PIN_18_Msk                              (0xfUL << PADI_PINCFG_PIN_18_Pos)
#define PADI_PINCFG_PIN_18                                  PADI_PINCFG_PIN_18_Msk
#define PADI_PINCFG_PIN_18_0                                (0x1UL << PADI_PINCFG_PIN_18_Pos)
#define PADI_PINCFG_PIN_18_1                                (0x2UL << PADI_PINCFG_PIN_18_Pos)
#define PADI_PINCFG_PIN_18_2                                (0x4UL << PADI_PINCFG_PIN_18_Pos)
#define PADI_PINCFG_PIN_18_3                                (0x8UL << PADI_PINCFG_PIN_18_Pos)
#define PADI_PINCFG_PIN_19_Pos                              (12)
#define PADI_PINCFG_PIN_19_Msk                              (0xfUL << PADI_PINCFG_PIN_19_Pos)
#define PADI_PINCFG_PIN_19                                  PADI_PINCFG_PIN_19_Msk
#define PADI_PINCFG_PIN_19_0                                (0x1UL << PADI_PINCFG_PIN_19_Pos)
#define PADI_PINCFG_PIN_19_1                                (0x2UL << PADI_PINCFG_PIN_19_Pos)
#define PADI_PINCFG_PIN_19_2                                (0x4UL << PADI_PINCFG_PIN_19_Pos)
#define PADI_PINCFG_PIN_19_3                                (0x8UL << PADI_PINCFG_PIN_19_Pos)
#define PADI_PINCFG_PIN_20_Pos                              (16)
#define PADI_PINCFG_PIN_20_Msk                              (0xfUL << PADI_PINCFG_PIN_20_Pos)
#define PADI_PINCFG_PIN_20                                  PADI_PINCFG_PIN_20_Msk
#define PADI_PINCFG_PIN_20_0                                (0x1UL << PADI_PINCFG_PIN_20_Pos)
#define PADI_PINCFG_PIN_20_1                                (0x2UL << PADI_PINCFG_PIN_20_Pos)
#define PADI_PINCFG_PIN_20_2                                (0x4UL << PADI_PINCFG_PIN_20_Pos)
#define PADI_PINCFG_PIN_20_3                                (0x8UL << PADI_PINCFG_PIN_20_Pos)
#define PADI_PINCFG_PIN_21_Pos                              (20)
#define PADI_PINCFG_PIN_21_Msk                              (0xfUL << PADI_PINCFG_PIN_21_Pos)
#define PADI_PINCFG_PIN_21                                  PADI_PINCFG_PIN_21_Msk
#define PADI_PINCFG_PIN_21_0                                (0x1UL << PADI_PINCFG_PIN_21_Pos)
#define PADI_PINCFG_PIN_21_1                                (0x2UL << PADI_PINCFG_PIN_21_Pos)
#define PADI_PINCFG_PIN_21_2                                (0x4UL << PADI_PINCFG_PIN_21_Pos)
#define PADI_PINCFG_PIN_21_3                                (0x8UL << PADI_PINCFG_PIN_21_Pos)
#define PADI_PINCFG_PIN_22_Pos                              (24)
#define PADI_PINCFG_PIN_22_Msk                              (0xfUL << PADI_PINCFG_PIN_22_Pos)
#define PADI_PINCFG_PIN_22                                  PADI_PINCFG_PIN_22_Msk
#define PADI_PINCFG_PIN_22_0                                (0x1UL << PADI_PINCFG_PIN_22_Pos)
#define PADI_PINCFG_PIN_22_1                                (0x2UL << PADI_PINCFG_PIN_22_Pos)
#define PADI_PINCFG_PIN_22_2                                (0x4UL << PADI_PINCFG_PIN_22_Pos)
#define PADI_PINCFG_PIN_22_3                                (0x8UL << PADI_PINCFG_PIN_22_Pos)
#define PADI_PINCFG_PIN_23_Pos                              (28)
#define PADI_PINCFG_PIN_23_Msk                              (0xfUL << PADI_PINCFG_PIN_23_Pos)
#define PADI_PINCFG_PIN_23                                  PADI_PINCFG_PIN_23_Msk
#define PADI_PINCFG_PIN_23_0                                (0x1UL << PADI_PINCFG_PIN_23_Pos)
#define PADI_PINCFG_PIN_23_1                                (0x2UL << PADI_PINCFG_PIN_23_Pos)
#define PADI_PINCFG_PIN_23_2                                (0x4UL << PADI_PINCFG_PIN_23_Pos)
#define PADI_PINCFG_PIN_23_3                                (0x8UL << PADI_PINCFG_PIN_23_Pos)

/******************  Bits definition for PADI_PORTMUX_CFG_4  ******************/
#define PADI_PINCFG_PIN_24_Pos                              (0)
#define PADI_PINCFG_PIN_24_Msk                              (0xfUL << PADI_PINCFG_PIN_24_Pos)
#define PADI_PINCFG_PIN_24                                  PADI_PINCFG_PIN_24_Msk
#define PADI_PINCFG_PIN_24_0                                (0x1UL << PADI_PINCFG_PIN_24_Pos)
#define PADI_PINCFG_PIN_24_1                                (0x2UL << PADI_PINCFG_PIN_24_Pos)
#define PADI_PINCFG_PIN_24_2                                (0x4UL << PADI_PINCFG_PIN_24_Pos)
#define PADI_PINCFG_PIN_24_3                                (0x8UL << PADI_PINCFG_PIN_24_Pos)
#define PADI_PINCFG_PIN_25_Pos                              (4)
#define PADI_PINCFG_PIN_25_Msk                              (0xfUL << PADI_PINCFG_PIN_25_Pos)
#define PADI_PINCFG_PIN_25                                  PADI_PINCFG_PIN_25_Msk
#define PADI_PINCFG_PIN_25_0                                (0x1UL << PADI_PINCFG_PIN_25_Pos)
#define PADI_PINCFG_PIN_25_1                                (0x2UL << PADI_PINCFG_PIN_25_Pos)
#define PADI_PINCFG_PIN_25_2                                (0x4UL << PADI_PINCFG_PIN_25_Pos)
#define PADI_PINCFG_PIN_25_3                                (0x8UL << PADI_PINCFG_PIN_25_Pos)
#define PADI_PINCFG_PIN_26_Pos                              (8)
#define PADI_PINCFG_PIN_26_Msk                              (0xfUL << PADI_PINCFG_PIN_26_Pos)
#define PADI_PINCFG_PIN_26                                  PADI_PINCFG_PIN_26_Msk
#define PADI_PINCFG_PIN_26_0                                (0x1UL << PADI_PINCFG_PIN_26_Pos)
#define PADI_PINCFG_PIN_26_1                                (0x2UL << PADI_PINCFG_PIN_26_Pos)
#define PADI_PINCFG_PIN_26_2                                (0x4UL << PADI_PINCFG_PIN_26_Pos)
#define PADI_PINCFG_PIN_26_3                                (0x8UL << PADI_PINCFG_PIN_26_Pos)
#define PADI_PINCFG_PIN_27_Pos                              (12)
#define PADI_PINCFG_PIN_27_Msk                              (0xfUL << PADI_PINCFG_PIN_27_Pos)
#define PADI_PINCFG_PIN_27                                  PADI_PINCFG_PIN_27_Msk
#define PADI_PINCFG_PIN_27_0                                (0x1UL << PADI_PINCFG_PIN_27_Pos)
#define PADI_PINCFG_PIN_27_1                                (0x2UL << PADI_PINCFG_PIN_27_Pos)
#define PADI_PINCFG_PIN_27_2                                (0x4UL << PADI_PINCFG_PIN_27_Pos)
#define PADI_PINCFG_PIN_27_3                                (0x8UL << PADI_PINCFG_PIN_27_Pos)
#define PADI_PINCFG_PIN_28_Pos                              (16)
#define PADI_PINCFG_PIN_28_Msk                              (0xfUL << PADI_PINCFG_PIN_28_Pos)
#define PADI_PINCFG_PIN_28                                  PADI_PINCFG_PIN_28_Msk
#define PADI_PINCFG_PIN_28_0                                (0x1UL << PADI_PINCFG_PIN_28_Pos)
#define PADI_PINCFG_PIN_28_1                                (0x2UL << PADI_PINCFG_PIN_28_Pos)
#define PADI_PINCFG_PIN_28_2                                (0x4UL << PADI_PINCFG_PIN_28_Pos)
#define PADI_PINCFG_PIN_28_3                                (0x8UL << PADI_PINCFG_PIN_28_Pos)
#define PADI_PINCFG_PIN_29_Pos                              (20)
#define PADI_PINCFG_PIN_29_Msk                              (0xfUL << PADI_PINCFG_PIN_29_Pos)
#define PADI_PINCFG_PIN_29                                  PADI_PINCFG_PIN_29_Msk
#define PADI_PINCFG_PIN_29_0                                (0x1UL << PADI_PINCFG_PIN_29_Pos)
#define PADI_PINCFG_PIN_29_1                                (0x2UL << PADI_PINCFG_PIN_29_Pos)
#define PADI_PINCFG_PIN_29_2                                (0x4UL << PADI_PINCFG_PIN_29_Pos)
#define PADI_PINCFG_PIN_29_3                                (0x8UL << PADI_PINCFG_PIN_29_Pos)
#define PADI_PINCFG_PIN_30_Pos                              (24)
#define PADI_PINCFG_PIN_30_Msk                              (0xfUL << PADI_PINCFG_PIN_30_Pos)
#define PADI_PINCFG_PIN_30                                  PADI_PINCFG_PIN_30_Msk
#define PADI_PINCFG_PIN_30_0                                (0x1UL << PADI_PINCFG_PIN_30_Pos)
#define PADI_PINCFG_PIN_30_1                                (0x2UL << PADI_PINCFG_PIN_30_Pos)
#define PADI_PINCFG_PIN_30_2                                (0x4UL << PADI_PINCFG_PIN_30_Pos)
#define PADI_PINCFG_PIN_30_3                                (0x8UL << PADI_PINCFG_PIN_30_Pos)
#define PADI_PINCFG_PIN_31_Pos                              (28)
#define PADI_PINCFG_PIN_31_Msk                              (0xfUL << PADI_PINCFG_PIN_31_Pos)
#define PADI_PINCFG_PIN_31                                  PADI_PINCFG_PIN_31_Msk
#define PADI_PINCFG_PIN_31_0                                (0x1UL << PADI_PINCFG_PIN_31_Pos)
#define PADI_PINCFG_PIN_31_1                                (0x2UL << PADI_PINCFG_PIN_31_Pos)
#define PADI_PINCFG_PIN_31_2                                (0x4UL << PADI_PINCFG_PIN_31_Pos)
#define PADI_PINCFG_PIN_31_3                                (0x8UL << PADI_PINCFG_PIN_31_Pos)

/******************  Bits definition for PADI_PORTMUX_CFG_5  ******************/
#define PADI_PINCFG_PIN_32_Pos                              (0)
#define PADI_PINCFG_PIN_32_Msk                              (0xfUL << PADI_PINCFG_PIN_32_Pos)
#define PADI_PINCFG_PIN_32                                  PADI_PINCFG_PIN_32_Msk
#define PADI_PINCFG_PIN_32_0                                (0x1UL << PADI_PINCFG_PIN_32_Pos)
#define PADI_PINCFG_PIN_32_1                                (0x2UL << PADI_PINCFG_PIN_32_Pos)
#define PADI_PINCFG_PIN_32_2                                (0x4UL << PADI_PINCFG_PIN_32_Pos)
#define PADI_PINCFG_PIN_32_3                                (0x8UL << PADI_PINCFG_PIN_32_Pos)
#define PADI_PINCFG_PIN_33_Pos                              (4)
#define PADI_PINCFG_PIN_33_Msk                              (0xfUL << PADI_PINCFG_PIN_33_Pos)
#define PADI_PINCFG_PIN_33                                  PADI_PINCFG_PIN_33_Msk
#define PADI_PINCFG_PIN_33_0                                (0x1UL << PADI_PINCFG_PIN_33_Pos)
#define PADI_PINCFG_PIN_33_1                                (0x2UL << PADI_PINCFG_PIN_33_Pos)
#define PADI_PINCFG_PIN_33_2                                (0x4UL << PADI_PINCFG_PIN_33_Pos)
#define PADI_PINCFG_PIN_33_3                                (0x8UL << PADI_PINCFG_PIN_33_Pos)
#define PADI_PINCFG_PIN_34_Pos                              (8)
#define PADI_PINCFG_PIN_34_Msk                              (0xfUL << PADI_PINCFG_PIN_34_Pos)
#define PADI_PINCFG_PIN_34                                  PADI_PINCFG_PIN_34_Msk
#define PADI_PINCFG_PIN_34_0                                (0x1UL << PADI_PINCFG_PIN_34_Pos)
#define PADI_PINCFG_PIN_34_1                                (0x2UL << PADI_PINCFG_PIN_34_Pos)
#define PADI_PINCFG_PIN_34_2                                (0x4UL << PADI_PINCFG_PIN_34_Pos)
#define PADI_PINCFG_PIN_34_3                                (0x8UL << PADI_PINCFG_PIN_34_Pos)
#define PADI_PINCFG_PIN_35_Pos                              (12)
#define PADI_PINCFG_PIN_35_Msk                              (0xfUL << PADI_PINCFG_PIN_35_Pos)
#define PADI_PINCFG_PIN_35                                  PADI_PINCFG_PIN_35_Msk
#define PADI_PINCFG_PIN_35_0                                (0x1UL << PADI_PINCFG_PIN_35_Pos)
#define PADI_PINCFG_PIN_35_1                                (0x2UL << PADI_PINCFG_PIN_35_Pos)
#define PADI_PINCFG_PIN_35_2                                (0x4UL << PADI_PINCFG_PIN_35_Pos)
#define PADI_PINCFG_PIN_35_3                                (0x8UL << PADI_PINCFG_PIN_35_Pos)
#define PADI_PINCFG_PIN_36_Pos                              (16)
#define PADI_PINCFG_PIN_36_Msk                              (0xfUL << PADI_PINCFG_PIN_36_Pos)
#define PADI_PINCFG_PIN_36                                  PADI_PINCFG_PIN_36_Msk
#define PADI_PINCFG_PIN_36_0                                (0x1UL << PADI_PINCFG_PIN_36_Pos)
#define PADI_PINCFG_PIN_36_1                                (0x2UL << PADI_PINCFG_PIN_36_Pos)
#define PADI_PINCFG_PIN_36_2                                (0x4UL << PADI_PINCFG_PIN_36_Pos)
#define PADI_PINCFG_PIN_36_3                                (0x8UL << PADI_PINCFG_PIN_36_Pos)
#define PADI_PINCFG_PIN_37_Pos                              (20)
#define PADI_PINCFG_PIN_37_Msk                              (0xfUL << PADI_PINCFG_PIN_37_Pos)
#define PADI_PINCFG_PIN_37                                  PADI_PINCFG_PIN_37_Msk
#define PADI_PINCFG_PIN_37_0                                (0x1UL << PADI_PINCFG_PIN_37_Pos)
#define PADI_PINCFG_PIN_37_1                                (0x2UL << PADI_PINCFG_PIN_37_Pos)
#define PADI_PINCFG_PIN_37_2                                (0x4UL << PADI_PINCFG_PIN_37_Pos)
#define PADI_PINCFG_PIN_37_3                                (0x8UL << PADI_PINCFG_PIN_37_Pos)
#define PADI_PINCFG_PIN_38_Pos                              (24)
#define PADI_PINCFG_PIN_38_Msk                              (0xfUL << PADI_PINCFG_PIN_38_Pos)
#define PADI_PINCFG_PIN_38                                  PADI_PINCFG_PIN_38_Msk
#define PADI_PINCFG_PIN_38_0                                (0x1UL << PADI_PINCFG_PIN_38_Pos)
#define PADI_PINCFG_PIN_38_1                                (0x2UL << PADI_PINCFG_PIN_38_Pos)
#define PADI_PINCFG_PIN_38_2                                (0x4UL << PADI_PINCFG_PIN_38_Pos)
#define PADI_PINCFG_PIN_38_3                                (0x8UL << PADI_PINCFG_PIN_38_Pos)
#define PADI_PINCFG_PIN_39_Pos                              (28)
#define PADI_PINCFG_PIN_39_Msk                              (0xfUL << PADI_PINCFG_PIN_39_Pos)
#define PADI_PINCFG_PIN_39                                  PADI_PINCFG_PIN_39_Msk
#define PADI_PINCFG_PIN_39_0                                (0x1UL << PADI_PINCFG_PIN_39_Pos)
#define PADI_PINCFG_PIN_39_1                                (0x2UL << PADI_PINCFG_PIN_39_Pos)
#define PADI_PINCFG_PIN_39_2                                (0x4UL << PADI_PINCFG_PIN_39_Pos)
#define PADI_PINCFG_PIN_39_3                                (0x8UL << PADI_PINCFG_PIN_39_Pos)

/******************  Bits definition for PADI_PORTMUX_CFG_6  ******************/
#define PADI_PINCFG_PIN_40_Pos                              (0)
#define PADI_PINCFG_PIN_40_Msk                              (0xfUL << PADI_PINCFG_PIN_40_Pos)
#define PADI_PINCFG_PIN_40                                  PADI_PINCFG_PIN_40_Msk
#define PADI_PINCFG_PIN_40_0                                (0x1UL << PADI_PINCFG_PIN_40_Pos)
#define PADI_PINCFG_PIN_40_1                                (0x2UL << PADI_PINCFG_PIN_40_Pos)
#define PADI_PINCFG_PIN_40_2                                (0x4UL << PADI_PINCFG_PIN_40_Pos)
#define PADI_PINCFG_PIN_40_3                                (0x8UL << PADI_PINCFG_PIN_40_Pos)
#define PADI_PINCFG_PIN_41_Pos                              (4)
#define PADI_PINCFG_PIN_41_Msk                              (0xfUL << PADI_PINCFG_PIN_41_Pos)
#define PADI_PINCFG_PIN_41                                  PADI_PINCFG_PIN_41_Msk
#define PADI_PINCFG_PIN_41_0                                (0x1UL << PADI_PINCFG_PIN_41_Pos)
#define PADI_PINCFG_PIN_41_1                                (0x2UL << PADI_PINCFG_PIN_41_Pos)
#define PADI_PINCFG_PIN_41_2                                (0x4UL << PADI_PINCFG_PIN_41_Pos)
#define PADI_PINCFG_PIN_41_3                                (0x8UL << PADI_PINCFG_PIN_41_Pos)
#define PADI_PINCFG_PIN_42_Pos                              (8)
#define PADI_PINCFG_PIN_42_Msk                              (0xfUL << PADI_PINCFG_PIN_42_Pos)
#define PADI_PINCFG_PIN_42                                  PADI_PINCFG_PIN_42_Msk
#define PADI_PINCFG_PIN_42_0                                (0x1UL << PADI_PINCFG_PIN_42_Pos)
#define PADI_PINCFG_PIN_42_1                                (0x2UL << PADI_PINCFG_PIN_42_Pos)
#define PADI_PINCFG_PIN_42_2                                (0x4UL << PADI_PINCFG_PIN_42_Pos)
#define PADI_PINCFG_PIN_42_3                                (0x8UL << PADI_PINCFG_PIN_42_Pos)
#define PADI_PINCFG_PIN_43_Pos                              (12)
#define PADI_PINCFG_PIN_43_Msk                              (0xfUL << PADI_PINCFG_PIN_43_Pos)
#define PADI_PINCFG_PIN_43                                  PADI_PINCFG_PIN_43_Msk
#define PADI_PINCFG_PIN_43_0                                (0x1UL << PADI_PINCFG_PIN_43_Pos)
#define PADI_PINCFG_PIN_43_1                                (0x2UL << PADI_PINCFG_PIN_43_Pos)
#define PADI_PINCFG_PIN_43_2                                (0x4UL << PADI_PINCFG_PIN_43_Pos)
#define PADI_PINCFG_PIN_43_3                                (0x8UL << PADI_PINCFG_PIN_43_Pos)
#define PADI_PINCFG_PIN_44_Pos                              (16)
#define PADI_PINCFG_PIN_44_Msk                              (0xfUL << PADI_PINCFG_PIN_44_Pos)
#define PADI_PINCFG_PIN_44                                  PADI_PINCFG_PIN_44_Msk
#define PADI_PINCFG_PIN_44_0                                (0x1UL << PADI_PINCFG_PIN_44_Pos)
#define PADI_PINCFG_PIN_44_1                                (0x2UL << PADI_PINCFG_PIN_44_Pos)
#define PADI_PINCFG_PIN_44_2                                (0x4UL << PADI_PINCFG_PIN_44_Pos)
#define PADI_PINCFG_PIN_44_3                                (0x8UL << PADI_PINCFG_PIN_44_Pos)
#define PADI_PINCFG_PIN_45_Pos                              (20)
#define PADI_PINCFG_PIN_45_Msk                              (0xfUL << PADI_PINCFG_PIN_45_Pos)
#define PADI_PINCFG_PIN_45                                  PADI_PINCFG_PIN_45_Msk
#define PADI_PINCFG_PIN_45_0                                (0x1UL << PADI_PINCFG_PIN_45_Pos)
#define PADI_PINCFG_PIN_45_1                                (0x2UL << PADI_PINCFG_PIN_45_Pos)
#define PADI_PINCFG_PIN_45_2                                (0x4UL << PADI_PINCFG_PIN_45_Pos)
#define PADI_PINCFG_PIN_45_3                                (0x8UL << PADI_PINCFG_PIN_45_Pos)
#define PADI_PINCFG_PIN_46_Pos                              (24)
#define PADI_PINCFG_PIN_46_Msk                              (0xfUL << PADI_PINCFG_PIN_46_Pos)
#define PADI_PINCFG_PIN_46                                  PADI_PINCFG_PIN_46_Msk
#define PADI_PINCFG_PIN_46_0                                (0x1UL << PADI_PINCFG_PIN_46_Pos)
#define PADI_PINCFG_PIN_46_1                                (0x2UL << PADI_PINCFG_PIN_46_Pos)
#define PADI_PINCFG_PIN_46_2                                (0x4UL << PADI_PINCFG_PIN_46_Pos)
#define PADI_PINCFG_PIN_46_3                                (0x8UL << PADI_PINCFG_PIN_46_Pos)
#define PADI_PINCFG_PIN_47_Pos                              (28)
#define PADI_PINCFG_PIN_47_Msk                              (0xfUL << PADI_PINCFG_PIN_47_Pos)
#define PADI_PINCFG_PIN_47                                  PADI_PINCFG_PIN_47_Msk
#define PADI_PINCFG_PIN_47_0                                (0x1UL << PADI_PINCFG_PIN_47_Pos)
#define PADI_PINCFG_PIN_47_1                                (0x2UL << PADI_PINCFG_PIN_47_Pos)
#define PADI_PINCFG_PIN_47_2                                (0x4UL << PADI_PINCFG_PIN_47_Pos)
#define PADI_PINCFG_PIN_47_3                                (0x8UL << PADI_PINCFG_PIN_47_Pos)

/******************  Bits definition for PADI_PORTMUX_CFG_7  ******************/
#define PADI_PINCFG_PIN_48_Pos                              (0)
#define PADI_PINCFG_PIN_48_Msk                              (0xfUL << PADI_PINCFG_PIN_48_Pos)
#define PADI_PINCFG_PIN_48                                  PADI_PINCFG_PIN_48_Msk
#define PADI_PINCFG_PIN_48_0                                (0x1UL << PADI_PINCFG_PIN_48_Pos)
#define PADI_PINCFG_PIN_48_1                                (0x2UL << PADI_PINCFG_PIN_48_Pos)
#define PADI_PINCFG_PIN_48_2                                (0x4UL << PADI_PINCFG_PIN_48_Pos)
#define PADI_PINCFG_PIN_48_3                                (0x8UL << PADI_PINCFG_PIN_48_Pos)
#define PADI_PINCFG_PIN_49_Pos                              (4)
#define PADI_PINCFG_PIN_49_Msk                              (0xfUL << PADI_PINCFG_PIN_49_Pos)
#define PADI_PINCFG_PIN_49                                  PADI_PINCFG_PIN_49_Msk
#define PADI_PINCFG_PIN_49_0                                (0x1UL << PADI_PINCFG_PIN_49_Pos)
#define PADI_PINCFG_PIN_49_1                                (0x2UL << PADI_PINCFG_PIN_49_Pos)
#define PADI_PINCFG_PIN_49_2                                (0x4UL << PADI_PINCFG_PIN_49_Pos)
#define PADI_PINCFG_PIN_49_3                                (0x8UL << PADI_PINCFG_PIN_49_Pos)
#define PADI_PINCFG_PIN_50_Pos                              (8)
#define PADI_PINCFG_PIN_50_Msk                              (0xfUL << PADI_PINCFG_PIN_50_Pos)
#define PADI_PINCFG_PIN_50                                  PADI_PINCFG_PIN_50_Msk
#define PADI_PINCFG_PIN_50_0                                (0x1UL << PADI_PINCFG_PIN_50_Pos)
#define PADI_PINCFG_PIN_50_1                                (0x2UL << PADI_PINCFG_PIN_50_Pos)
#define PADI_PINCFG_PIN_50_2                                (0x4UL << PADI_PINCFG_PIN_50_Pos)
#define PADI_PINCFG_PIN_50_3                                (0x8UL << PADI_PINCFG_PIN_50_Pos)
#define PADI_PINCFG_PIN_51_Pos                              (12)
#define PADI_PINCFG_PIN_51_Msk                              (0xfUL << PADI_PINCFG_PIN_51_Pos)
#define PADI_PINCFG_PIN_51                                  PADI_PINCFG_PIN_51_Msk
#define PADI_PINCFG_PIN_51_0                                (0x1UL << PADI_PINCFG_PIN_51_Pos)
#define PADI_PINCFG_PIN_51_1                                (0x2UL << PADI_PINCFG_PIN_51_Pos)
#define PADI_PINCFG_PIN_51_2                                (0x4UL << PADI_PINCFG_PIN_51_Pos)
#define PADI_PINCFG_PIN_51_3                                (0x8UL << PADI_PINCFG_PIN_51_Pos)
#define PADI_PINCFG_PIN_52_Pos                              (16)
#define PADI_PINCFG_PIN_52_Msk                              (0xfUL << PADI_PINCFG_PIN_52_Pos)
#define PADI_PINCFG_PIN_52                                  PADI_PINCFG_PIN_52_Msk
#define PADI_PINCFG_PIN_52_0                                (0x1UL << PADI_PINCFG_PIN_52_Pos)
#define PADI_PINCFG_PIN_52_1                                (0x2UL << PADI_PINCFG_PIN_52_Pos)
#define PADI_PINCFG_PIN_52_2                                (0x4UL << PADI_PINCFG_PIN_52_Pos)
#define PADI_PINCFG_PIN_52_3                                (0x8UL << PADI_PINCFG_PIN_52_Pos)
#define PADI_PINCFG_PIN_53_Pos                              (20)
#define PADI_PINCFG_PIN_53_Msk                              (0xfUL << PADI_PINCFG_PIN_53_Pos)
#define PADI_PINCFG_PIN_53                                  PADI_PINCFG_PIN_53_Msk
#define PADI_PINCFG_PIN_53_0                                (0x1UL << PADI_PINCFG_PIN_53_Pos)
#define PADI_PINCFG_PIN_53_1                                (0x2UL << PADI_PINCFG_PIN_53_Pos)
#define PADI_PINCFG_PIN_53_2                                (0x4UL << PADI_PINCFG_PIN_53_Pos)
#define PADI_PINCFG_PIN_53_3                                (0x8UL << PADI_PINCFG_PIN_53_Pos)
#define PADI_PINCFG_PIN_54_Pos                              (24)
#define PADI_PINCFG_PIN_54_Msk                              (0xfUL << PADI_PINCFG_PIN_54_Pos)
#define PADI_PINCFG_PIN_54                                  PADI_PINCFG_PIN_54_Msk
#define PADI_PINCFG_PIN_54_0                                (0x1UL << PADI_PINCFG_PIN_54_Pos)
#define PADI_PINCFG_PIN_54_1                                (0x2UL << PADI_PINCFG_PIN_54_Pos)
#define PADI_PINCFG_PIN_54_2                                (0x4UL << PADI_PINCFG_PIN_54_Pos)
#define PADI_PINCFG_PIN_54_3                                (0x8UL << PADI_PINCFG_PIN_54_Pos)
#define PADI_PINCFG_PIN_55_Pos                              (28)
#define PADI_PINCFG_PIN_55_Msk                              (0xfUL << PADI_PINCFG_PIN_55_Pos)
#define PADI_PINCFG_PIN_55                                  PADI_PINCFG_PIN_55_Msk
#define PADI_PINCFG_PIN_55_0                                (0x1UL << PADI_PINCFG_PIN_55_Pos)
#define PADI_PINCFG_PIN_55_1                                (0x2UL << PADI_PINCFG_PIN_55_Pos)
#define PADI_PINCFG_PIN_55_2                                (0x4UL << PADI_PINCFG_PIN_55_Pos)
#define PADI_PINCFG_PIN_55_3                                (0x8UL << PADI_PINCFG_PIN_55_Pos)

/******************  Bits definition for PADI_PORTMUX_CFG_8  ******************/
#define PADI_PINCFG_PIN_56_Pos                              (0)
#define PADI_PINCFG_PIN_56_Msk                              (0xfUL << PADI_PINCFG_PIN_56_Pos)
#define PADI_PINCFG_PIN_56                                  PADI_PINCFG_PIN_56_Msk
#define PADI_PINCFG_PIN_56_0                                (0x1UL << PADI_PINCFG_PIN_56_Pos)
#define PADI_PINCFG_PIN_56_1                                (0x2UL << PADI_PINCFG_PIN_56_Pos)
#define PADI_PINCFG_PIN_56_2                                (0x4UL << PADI_PINCFG_PIN_56_Pos)
#define PADI_PINCFG_PIN_56_3                                (0x8UL << PADI_PINCFG_PIN_56_Pos)
#define PADI_PINCFG_PIN_57_Pos                              (4)
#define PADI_PINCFG_PIN_57_Msk                              (0xfUL << PADI_PINCFG_PIN_57_Pos)
#define PADI_PINCFG_PIN_57                                  PADI_PINCFG_PIN_57_Msk
#define PADI_PINCFG_PIN_57_0                                (0x1UL << PADI_PINCFG_PIN_57_Pos)
#define PADI_PINCFG_PIN_57_1                                (0x2UL << PADI_PINCFG_PIN_57_Pos)
#define PADI_PINCFG_PIN_57_2                                (0x4UL << PADI_PINCFG_PIN_57_Pos)
#define PADI_PINCFG_PIN_57_3                                (0x8UL << PADI_PINCFG_PIN_57_Pos)
#define PADI_PINCFG_PIN_58_Pos                              (8)
#define PADI_PINCFG_PIN_58_Msk                              (0xfUL << PADI_PINCFG_PIN_58_Pos)
#define PADI_PINCFG_PIN_58                                  PADI_PINCFG_PIN_58_Msk
#define PADI_PINCFG_PIN_58_0                                (0x1UL << PADI_PINCFG_PIN_58_Pos)
#define PADI_PINCFG_PIN_58_1                                (0x2UL << PADI_PINCFG_PIN_58_Pos)
#define PADI_PINCFG_PIN_58_2                                (0x4UL << PADI_PINCFG_PIN_58_Pos)
#define PADI_PINCFG_PIN_58_3                                (0x8UL << PADI_PINCFG_PIN_58_Pos)
#define PADI_PINCFG_PIN_59_Pos                              (12)
#define PADI_PINCFG_PIN_59_Msk                              (0xfUL << PADI_PINCFG_PIN_59_Pos)
#define PADI_PINCFG_PIN_59                                  PADI_PINCFG_PIN_59_Msk
#define PADI_PINCFG_PIN_59_0                                (0x1UL << PADI_PINCFG_PIN_59_Pos)
#define PADI_PINCFG_PIN_59_1                                (0x2UL << PADI_PINCFG_PIN_59_Pos)
#define PADI_PINCFG_PIN_59_2                                (0x4UL << PADI_PINCFG_PIN_59_Pos)
#define PADI_PINCFG_PIN_59_3                                (0x8UL << PADI_PINCFG_PIN_59_Pos)

/*****************  Bits definition for PADI_IO_PULLUP_CFG_1  *****************/
#define PADI_IO_PULLUP_PIN_Pos                              (0)
#define PADI_IO_PULLUP_PIN_Msk                              (0xffffffffUL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN                                  PADI_IO_PULLUP_PIN_Msk
#define PADI_IO_PULLUP_PIN_0                                (0x1UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_1                                (0x2UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_2                                (0x4UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_3                                (0x8UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_4                                (0x10UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_5                                (0x20UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_6                                (0x40UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_7                                (0x80UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_8                                (0x100UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_9                                (0x200UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_10                               (0x400UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_11                               (0x800UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_12                               (0x1000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_13                               (0x2000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_14                               (0x4000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_15                               (0x8000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_16                               (0x10000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_17                               (0x20000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_18                               (0x40000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_19                               (0x80000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_20                               (0x100000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_21                               (0x200000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_22                               (0x400000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_23                               (0x800000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_24                               (0x1000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_25                               (0x2000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_26                               (0x4000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_27                               (0x8000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_28                               (0x10000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_29                               (0x20000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_30                               (0x40000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_31                               (0x80000000UL << PADI_IO_PULLUP_PIN_Pos)

/*****************  Bits definition for PADI_IO_PULLUP_CFG_2  *****************/
#define PADI_IO_PULLUP_PIN_Pos                              (0)
#define PADI_IO_PULLUP_PIN_Msk                              (0xffffffffUL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN                                  PADI_IO_PULLUP_PIN_Msk
#define PADI_IO_PULLUP_PIN_0                                (0x1UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_1                                (0x2UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_2                                (0x4UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_3                                (0x8UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_4                                (0x10UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_5                                (0x20UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_6                                (0x40UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_7                                (0x80UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_8                                (0x100UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_9                                (0x200UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_10                               (0x400UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_11                               (0x800UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_12                               (0x1000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_13                               (0x2000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_14                               (0x4000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_15                               (0x8000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_16                               (0x10000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_17                               (0x20000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_18                               (0x40000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_19                               (0x80000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_20                               (0x100000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_21                               (0x200000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_22                               (0x400000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_23                               (0x800000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_24                               (0x1000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_25                               (0x2000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_26                               (0x4000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_27                               (0x8000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_28                               (0x10000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_29                               (0x20000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_30                               (0x40000000UL << PADI_IO_PULLUP_PIN_Pos)
#define PADI_IO_PULLUP_PIN_31                               (0x80000000UL << PADI_IO_PULLUP_PIN_Pos)

/*****************  Bits definition for PADI_IO_PULLDW_CFG_1  *****************/
#define PADI_IO_PULLDW_PIN_Pos                              (0)
#define PADI_IO_PULLDW_PIN_Msk                              (0xffffffffUL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN                                  PADI_IO_PULLDW_PIN_Msk
#define PADI_IO_PULLDW_PIN_0                                (0x1UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_1                                (0x2UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_2                                (0x4UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_3                                (0x8UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_4                                (0x10UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_5                                (0x20UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_6                                (0x40UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_7                                (0x80UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_8                                (0x100UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_9                                (0x200UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_10                               (0x400UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_11                               (0x800UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_12                               (0x1000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_13                               (0x2000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_14                               (0x4000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_15                               (0x8000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_16                               (0x10000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_17                               (0x20000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_18                               (0x40000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_19                               (0x80000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_20                               (0x100000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_21                               (0x200000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_22                               (0x400000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_23                               (0x800000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_24                               (0x1000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_25                               (0x2000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_26                               (0x4000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_27                               (0x8000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_28                               (0x10000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_29                               (0x20000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_30                               (0x40000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_31                               (0x80000000UL << PADI_IO_PULLDW_PIN_Pos)

/*****************  Bits definition for PADI_IO_PULLDW_CFG_2  *****************/
#define PADI_IO_PULLDW_PIN_Pos                              (0)
#define PADI_IO_PULLDW_PIN_Msk                              (0xffffffffUL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN                                  PADI_IO_PULLDW_PIN_Msk
#define PADI_IO_PULLDW_PIN_0                                (0x1UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_1                                (0x2UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_2                                (0x4UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_3                                (0x8UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_4                                (0x10UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_5                                (0x20UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_6                                (0x40UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_7                                (0x80UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_8                                (0x100UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_9                                (0x200UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_10                               (0x400UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_11                               (0x800UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_12                               (0x1000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_13                               (0x2000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_14                               (0x4000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_15                               (0x8000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_16                               (0x10000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_17                               (0x20000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_18                               (0x40000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_19                               (0x80000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_20                               (0x100000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_21                               (0x200000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_22                               (0x400000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_23                               (0x800000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_24                               (0x1000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_25                               (0x2000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_26                               (0x4000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_27                               (0x8000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_28                               (0x10000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_29                               (0x20000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_30                               (0x40000000UL << PADI_IO_PULLDW_PIN_Pos)
#define PADI_IO_PULLDW_PIN_31                               (0x80000000UL << PADI_IO_PULLDW_PIN_Pos)

/*******************  Bits definition for PADI_IO_DS_CFG_1  *******************/
#define PADI_IO_DS_PIN_Pos                                  (0)
#define PADI_IO_DS_PIN_Msk                                  (0xffffffffUL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN                                      PADI_IO_DS_PIN_Msk
#define PADI_IO_DS_PIN_0                                    (0x1UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_1                                    (0x2UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_2                                    (0x4UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_3                                    (0x8UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_4                                    (0x10UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_5                                    (0x20UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_6                                    (0x40UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_7                                    (0x80UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_8                                    (0x100UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_9                                    (0x200UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_10                                   (0x400UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_11                                   (0x800UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_12                                   (0x1000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_13                                   (0x2000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_14                                   (0x4000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_15                                   (0x8000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_16                                   (0x10000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_17                                   (0x20000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_18                                   (0x40000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_19                                   (0x80000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_20                                   (0x100000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_21                                   (0x200000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_22                                   (0x400000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_23                                   (0x800000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_24                                   (0x1000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_25                                   (0x2000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_26                                   (0x4000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_27                                   (0x8000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_28                                   (0x10000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_29                                   (0x20000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_30                                   (0x40000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_31                                   (0x80000000UL << PADI_IO_DS_PIN_Pos)

/*******************  Bits definition for PADI_IO_DS_CFG_2  *******************/
#define PADI_IO_DS_PIN_Pos                                  (0)
#define PADI_IO_DS_PIN_Msk                                  (0xffffffffUL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN                                      PADI_IO_DS_PIN_Msk
#define PADI_IO_DS_PIN_0                                    (0x1UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_1                                    (0x2UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_2                                    (0x4UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_3                                    (0x8UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_4                                    (0x10UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_5                                    (0x20UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_6                                    (0x40UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_7                                    (0x80UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_8                                    (0x100UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_9                                    (0x200UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_10                                   (0x400UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_11                                   (0x800UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_12                                   (0x1000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_13                                   (0x2000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_14                                   (0x4000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_15                                   (0x8000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_16                                   (0x10000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_17                                   (0x20000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_18                                   (0x40000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_19                                   (0x80000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_20                                   (0x100000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_21                                   (0x200000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_22                                   (0x400000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_23                                   (0x800000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_24                                   (0x1000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_25                                   (0x2000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_26                                   (0x4000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_27                                   (0x8000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_28                                   (0x10000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_29                                   (0x20000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_30                                   (0x40000000UL << PADI_IO_DS_PIN_Pos)
#define PADI_IO_DS_PIN_31                                   (0x80000000UL << PADI_IO_DS_PIN_Pos)

/******************************************************************************/
/*                                                                            */
/*                                   RTC                                      */
/*                                                                            */
/******************************************************************************/

/***********************  Bits definition for RTC_CCVR  ***********************/
#define RTC_CCVR_CCVR_Pos                                   (0)
#define RTC_CCVR_CCVR_Msk                                   (0xffffffffUL << RTC_CCVR_CCVR_Pos)
#define RTC_CCVR_CCVR                                       RTC_CCVR_CCVR_Msk

/***********************  Bits definition for RTC_CMR  ************************/
#define RTC_CMR_CMR_Pos                                     (0)
#define RTC_CMR_CMR_Msk                                     (0xffffffffUL << RTC_CMR_CMR_Pos)
#define RTC_CMR_CMR                                         RTC_CMR_CMR_Msk

/***********************  Bits definition for RTC_CLR  ************************/
#define RTC_CLR_CLR_Pos                                     (0)
#define RTC_CLR_CLR_Msk                                     (0xffffffffUL << RTC_CLR_CLR_Pos)
#define RTC_CLR_CLR                                         RTC_CLR_CLR_Msk

/***********************  Bits definition for RTC_CCR  ************************/
#define RTC_CCR_IEN_Pos                                     (0)
#define RTC_CCR_IEN_Msk                                     (0x1UL << RTC_CCR_IEN_Pos)
#define RTC_CCR_IEN                                         RTC_CCR_IEN_Msk
#define RTC_CCR_MASK_Pos                                    (1)
#define RTC_CCR_MASK_Msk                                    (0x1UL << RTC_CCR_MASK_Pos)
#define RTC_CCR_MASK                                        RTC_CCR_MASK_Msk
#define RTC_CCR_EN_Pos                                      (2)
#define RTC_CCR_EN_Msk                                      (0x1UL << RTC_CCR_EN_Pos)
#define RTC_CCR_EN                                          RTC_CCR_EN_Msk
#define RTC_CCR_WEN_Pos                                     (3)
#define RTC_CCR_WEN_Msk                                     (0x1UL << RTC_CCR_WEN_Pos)
#define RTC_CCR_WEN                                         RTC_CCR_WEN_Msk

/***********************  Bits definition for RTC_STAT  ***********************/
#define RTC_STAT_STAT_Pos                                   (0)
#define RTC_STAT_STAT_Msk                                   (0x1UL << RTC_STAT_STAT_Pos)
#define RTC_STAT_STAT                                       RTC_STAT_STAT_Msk

/**********************  Bits definition for RTC_RSTAT  ***********************/
#define RTC_RSTAT_STAT_Pos                                  (0)
#define RTC_RSTAT_STAT_Msk                                  (0x1UL << RTC_RSTAT_STAT_Pos)
#define RTC_RSTAT_STAT                                      RTC_RSTAT_STAT_Msk

/***********************  Bits definition for RTC_EOI  ************************/
#define RTC_EOI_EOI_Pos                                     (0)
#define RTC_EOI_EOI_Msk                                     (0x1UL << RTC_EOI_EOI_Pos)
#define RTC_EOI_EOI                                         RTC_EOI_EOI_Msk

/******************************************************************************/
/*                                                                            */
/*                                   SPI                                      */
/*                                                                            */
/******************************************************************************/

/**********************  Bits definition for SPI_CTRLR0  **********************/
#define SPI_CTRLR0_DFS_Pos                                  (0)
#define SPI_CTRLR0_DFS_Msk                                  (0xfUL << SPI_CTRLR0_DFS_Pos)
#define SPI_CTRLR0_DFS                                      SPI_CTRLR0_DFS_Msk
#define SPI_CTRLR0_DFS_0                                    (0x1UL << SPI_CTRLR0_DFS_Pos)
#define SPI_CTRLR0_DFS_1                                    (0x2UL << SPI_CTRLR0_DFS_Pos)
#define SPI_CTRLR0_DFS_2                                    (0x4UL << SPI_CTRLR0_DFS_Pos)
#define SPI_CTRLR0_DFS_3                                    (0x8UL << SPI_CTRLR0_DFS_Pos)
#define SPI_CTRLR0_FRF_Pos                                  (4)
#define SPI_CTRLR0_FRF_Msk                                  (0x3UL << SPI_CTRLR0_FRF_Pos)
#define SPI_CTRLR0_FRF                                      SPI_CTRLR0_FRF_Msk
#define SPI_CTRLR0_FRF_0                                    (0x1UL << SPI_CTRLR0_FRF_Pos)
#define SPI_CTRLR0_FRF_1                                    (0x2UL << SPI_CTRLR0_FRF_Pos)
#define SPI_CTRLR0_SCPH_Pos                                 (6)
#define SPI_CTRLR0_SCPH_Msk                                 (0x1UL << SPI_CTRLR0_SCPH_Pos)
#define SPI_CTRLR0_SCPH                                     SPI_CTRLR0_SCPH_Msk
#define SPI_CTRLR0_SCPOL_Pos                                (7)
#define SPI_CTRLR0_SCPOL_Msk                                (0x1UL << SPI_CTRLR0_SCPOL_Pos)
#define SPI_CTRLR0_SCPOL                                    SPI_CTRLR0_SCPOL_Msk
#define SPI_CTRLR0_TMOD_Pos                                 (8)
#define SPI_CTRLR0_TMOD_Msk                                 (0x3UL << SPI_CTRLR0_TMOD_Pos)
#define SPI_CTRLR0_TMOD                                     SPI_CTRLR0_TMOD_Msk
#define SPI_CTRLR0_TMOD_0                                   (0x1UL << SPI_CTRLR0_TMOD_Pos)
#define SPI_CTRLR0_TMOD_1                                   (0x2UL << SPI_CTRLR0_TMOD_Pos)
#define SPI_CTRLR0_SLVOE_Pos                                (10)
#define SPI_CTRLR0_SLVOE_Msk                                (0x1UL << SPI_CTRLR0_SLVOE_Pos)
#define SPI_CTRLR0_SLVOE                                    SPI_CTRLR0_SLVOE_Msk
#define SPI_CTRLR0_SRL_Pos                                  (11)
#define SPI_CTRLR0_SRL_Msk                                  (0x1UL << SPI_CTRLR0_SRL_Pos)
#define SPI_CTRLR0_SRL                                      SPI_CTRLR0_SRL_Msk
#define SPI_CTRLR0_CFS_Pos                                  (12)
#define SPI_CTRLR0_CFS_Msk                                  (0xfUL << SPI_CTRLR0_CFS_Pos)
#define SPI_CTRLR0_CFS                                      SPI_CTRLR0_CFS_Msk
#define SPI_CTRLR0_CFS_0                                    (0x1UL << SPI_CTRLR0_CFS_Pos)
#define SPI_CTRLR0_CFS_1                                    (0x2UL << SPI_CTRLR0_CFS_Pos)
#define SPI_CTRLR0_CFS_2                                    (0x4UL << SPI_CTRLR0_CFS_Pos)
#define SPI_CTRLR0_CFS_3                                    (0x8UL << SPI_CTRLR0_CFS_Pos)

/**********************  Bits definition for SPI_CTRLR1  **********************/
#define SPI_CTRLR1_NDF_Pos                                  (0)
#define SPI_CTRLR1_NDF_Msk                                  (0xffffUL << SPI_CTRLR1_NDF_Pos)
#define SPI_CTRLR1_NDF                                      SPI_CTRLR1_NDF_Msk

/**********************  Bits definition for SPI_SSIENR  **********************/
#define SPI_SSIENR_SSIEN_Pos                                (0)
#define SPI_SSIENR_SSIEN_Msk                                (0x1UL << SPI_SSIENR_SSIEN_Pos)
#define SPI_SSIENR_SSIEN                                    SPI_SSIENR_SSIEN_Msk

/***********************  Bits definition for SPI_MWCR  ***********************/
#define SPI_MWCR_MWMOD_Pos                                  (0)
#define SPI_MWCR_MWMOD_Msk                                  (0x1UL << SPI_MWCR_MWMOD_Pos)
#define SPI_MWCR_MWMOD                                      SPI_MWCR_MWMOD_Msk
#define SPI_MWCR_MDD_Pos                                    (1)
#define SPI_MWCR_MDD_Msk                                    (0x1UL << SPI_MWCR_MDD_Pos)
#define SPI_MWCR_MDD                                        SPI_MWCR_MDD_Msk
#define SPI_MWCR_MHS_Pos                                    (2)
#define SPI_MWCR_MHS_Msk                                    (0x1UL << SPI_MWCR_MHS_Pos)
#define SPI_MWCR_MHS                                        SPI_MWCR_MHS_Msk

/***********************  Bits definition for SPI_SER  ************************/
#define SPI_SER_SER_Pos                                     (0)
#define SPI_SER_SER_Msk                                     (0x1UL << SPI_SER_SER_Pos)
#define SPI_SER_SER                                         SPI_SER_SER_Msk

/**********************  Bits definition for SPI_BAUDR  ***********************/
#define SPI_BAUDR_SCKDV_Pos                                 (0)
#define SPI_BAUDR_SCKDV_Msk                                 (0xffffUL << SPI_BAUDR_SCKDV_Pos)
#define SPI_BAUDR_SCKDV                                     SPI_BAUDR_SCKDV_Msk

/**********************  Bits definition for SPI_TXFTLR  **********************/
#define SPI_TXFTLR_TFT_Pos                                  (0)
#define SPI_TXFTLR_TFT_Msk                                  (0x7UL << SPI_TXFTLR_TFT_Pos)
#define SPI_TXFTLR_TFT                                      SPI_TXFTLR_TFT_Msk
#define SPI_TXFTLR_TFT_0                                    (0x1UL << SPI_TXFTLR_TFT_Pos)
#define SPI_TXFTLR_TFT_1                                    (0x2UL << SPI_TXFTLR_TFT_Pos)
#define SPI_TXFTLR_TFT_2                                    (0x4UL << SPI_TXFTLR_TFT_Pos)

/**********************  Bits definition for SPI_RXFTLR  **********************/
#define SPI_RXFTLR_RFT_Pos                                  (0)
#define SPI_RXFTLR_RFT_Msk                                  (0x7UL << SPI_RXFTLR_RFT_Pos)
#define SPI_RXFTLR_RFT                                      SPI_RXFTLR_RFT_Msk
#define SPI_RXFTLR_RFT_0                                    (0x1UL << SPI_RXFTLR_RFT_Pos)
#define SPI_RXFTLR_RFT_1                                    (0x2UL << SPI_RXFTLR_RFT_Pos)
#define SPI_RXFTLR_RFT_2                                    (0x4UL << SPI_RXFTLR_RFT_Pos)

/**********************  Bits definition for SPI_TXFLR  ***********************/
#define SPI_TXFLR_TFL_Pos                                   (0)
#define SPI_TXFLR_TFL_Msk                                   (0xfUL << SPI_TXFLR_TFL_Pos)
#define SPI_TXFLR_TFL                                       SPI_TXFLR_TFL_Msk
#define SPI_TXFLR_TFL_0                                     (0x1UL << SPI_TXFLR_TFL_Pos)
#define SPI_TXFLR_TFL_1                                     (0x2UL << SPI_TXFLR_TFL_Pos)
#define SPI_TXFLR_TFL_2                                     (0x4UL << SPI_TXFLR_TFL_Pos)
#define SPI_TXFLR_TFL_3                                     (0x8UL << SPI_TXFLR_TFL_Pos)

/**********************  Bits definition for SPI_RXFLR  ***********************/
#define SPI_RXFLR_RFL_Pos                                   (0)
#define SPI_RXFLR_RFL_Msk                                   (0xfUL << SPI_RXFLR_RFL_Pos)
#define SPI_RXFLR_RFL                                       SPI_RXFLR_RFL_Msk
#define SPI_RXFLR_RFL_0                                     (0x1UL << SPI_RXFLR_RFL_Pos)
#define SPI_RXFLR_RFL_1                                     (0x2UL << SPI_RXFLR_RFL_Pos)
#define SPI_RXFLR_RFL_2                                     (0x4UL << SPI_RXFLR_RFL_Pos)
#define SPI_RXFLR_RFL_3                                     (0x8UL << SPI_RXFLR_RFL_Pos)

/************************  Bits definition for SPI_SR  ************************/
#define SPI_SR_BUSY_Pos                                     (0)
#define SPI_SR_BUSY_Msk                                     (0x1UL << SPI_SR_BUSY_Pos)
#define SPI_SR_BUSY                                         SPI_SR_BUSY_Msk
#define SPI_SR_TFNF_Pos                                     (1)
#define SPI_SR_TFNF_Msk                                     (0x1UL << SPI_SR_TFNF_Pos)
#define SPI_SR_TFNF                                         SPI_SR_TFNF_Msk
#define SPI_SR_TFE_Pos                                      (2)
#define SPI_SR_TFE_Msk                                      (0x1UL << SPI_SR_TFE_Pos)
#define SPI_SR_TFE                                          SPI_SR_TFE_Msk
#define SPI_SR_RFNE_Pos                                     (3)
#define SPI_SR_RFNE_Msk                                     (0x1UL << SPI_SR_RFNE_Pos)
#define SPI_SR_RFNE                                         SPI_SR_RFNE_Msk
#define SPI_SR_RFF_Pos                                      (4)
#define SPI_SR_RFF_Msk                                      (0x1UL << SPI_SR_RFF_Pos)
#define SPI_SR_RFF                                          SPI_SR_RFF_Msk
#define SPI_SR_TXE_Pos                                      (5)
#define SPI_SR_TXE_Msk                                      (0x1UL << SPI_SR_TXE_Pos)
#define SPI_SR_TXE                                          SPI_SR_TXE_Msk
#define SPI_SR_DCOL_Pos                                     (6)
#define SPI_SR_DCOL_Msk                                     (0x1UL << SPI_SR_DCOL_Pos)
#define SPI_SR_DCOL                                         SPI_SR_DCOL_Msk

/***********************  Bits definition for SPI_IMR  ************************/
#define SPI_IMR_TXEIM_Pos                                   (0)
#define SPI_IMR_TXEIM_Msk                                   (0x1UL << SPI_IMR_TXEIM_Pos)
#define SPI_IMR_TXEIM                                       SPI_IMR_TXEIM_Msk
#define SPI_IMR_TXOIM_Pos                                   (1)
#define SPI_IMR_TXOIM_Msk                                   (0x1UL << SPI_IMR_TXOIM_Pos)
#define SPI_IMR_TXOIM                                       SPI_IMR_TXOIM_Msk
#define SPI_IMR_RXUIM_Pos                                   (2)
#define SPI_IMR_RXUIM_Msk                                   (0x1UL << SPI_IMR_RXUIM_Pos)
#define SPI_IMR_RXUIM                                       SPI_IMR_RXUIM_Msk
#define SPI_IMR_RXOIM_Pos                                   (3)
#define SPI_IMR_RXOIM_Msk                                   (0x1UL << SPI_IMR_RXOIM_Pos)
#define SPI_IMR_RXOIM                                       SPI_IMR_RXOIM_Msk
#define SPI_IMR_RXFIM_Pos                                   (4)
#define SPI_IMR_RXFIM_Msk                                   (0x1UL << SPI_IMR_RXFIM_Pos)
#define SPI_IMR_RXFIM                                       SPI_IMR_RXFIM_Msk
#define SPI_IMR_MSTIM_Pos                                   (5)
#define SPI_IMR_MSTIM_Msk                                   (0x1UL << SPI_IMR_MSTIM_Pos)
#define SPI_IMR_MSTIM                                       SPI_IMR_MSTIM_Msk

/***********************  Bits definition for SPI_ISR  ************************/
#define SPI_ISR_TXEIS_Pos                                   (0)
#define SPI_ISR_TXEIS_Msk                                   (0x1UL << SPI_ISR_TXEIS_Pos)
#define SPI_ISR_TXEIS                                       SPI_ISR_TXEIS_Msk
#define SPI_ISR_TXOIS_Pos                                   (1)
#define SPI_ISR_TXOIS_Msk                                   (0x1UL << SPI_ISR_TXOIS_Pos)
#define SPI_ISR_TXOIS                                       SPI_ISR_TXOIS_Msk
#define SPI_ISR_RXUIS_Pos                                   (2)
#define SPI_ISR_RXUIS_Msk                                   (0x1UL << SPI_ISR_RXUIS_Pos)
#define SPI_ISR_RXUIS                                       SPI_ISR_RXUIS_Msk
#define SPI_ISR_RXOIS_Pos                                   (3)
#define SPI_ISR_RXOIS_Msk                                   (0x1UL << SPI_ISR_RXOIS_Pos)
#define SPI_ISR_RXOIS                                       SPI_ISR_RXOIS_Msk
#define SPI_ISR_RXFIS_Pos                                   (4)
#define SPI_ISR_RXFIS_Msk                                   (0x1UL << SPI_ISR_RXFIS_Pos)
#define SPI_ISR_RXFIS                                       SPI_ISR_RXFIS_Msk
#define SPI_ISR_MSTIS_Pos                                   (5)
#define SPI_ISR_MSTIS_Msk                                   (0x1UL << SPI_ISR_MSTIS_Pos)
#define SPI_ISR_MSTIS                                       SPI_ISR_MSTIS_Msk

/***********************  Bits definition for SPI_RISR  ***********************/
#define SPI_RISR_TXEIR_Pos                                  (0)
#define SPI_RISR_TXEIR_Msk                                  (0x1UL << SPI_RISR_TXEIR_Pos)
#define SPI_RISR_TXEIR                                      SPI_RISR_TXEIR_Msk
#define SPI_RISR_TXOIR_Pos                                  (1)
#define SPI_RISR_TXOIR_Msk                                  (0x1UL << SPI_RISR_TXOIR_Pos)
#define SPI_RISR_TXOIR                                      SPI_RISR_TXOIR_Msk
#define SPI_RISR_RXUIR_Pos                                  (2)
#define SPI_RISR_RXUIR_Msk                                  (0x1UL << SPI_RISR_RXUIR_Pos)
#define SPI_RISR_RXUIR                                      SPI_RISR_RXUIR_Msk
#define SPI_RISR_RXOIR_Pos                                  (3)
#define SPI_RISR_RXOIR_Msk                                  (0x1UL << SPI_RISR_RXOIR_Pos)
#define SPI_RISR_RXOIR                                      SPI_RISR_RXOIR_Msk
#define SPI_RISR_RXFIR_Pos                                  (4)
#define SPI_RISR_RXFIR_Msk                                  (0x1UL << SPI_RISR_RXFIR_Pos)
#define SPI_RISR_RXFIR                                      SPI_RISR_RXFIR_Msk
#define SPI_RISR_MSTIR_Pos                                  (5)
#define SPI_RISR_MSTIR_Msk                                  (0x1UL << SPI_RISR_MSTIR_Pos)
#define SPI_RISR_MSTIR                                      SPI_RISR_MSTIR_Msk

/**********************  Bits definition for SPI_TXOICR  **********************/
#define SPI_TXOICR_TXOICR_Pos                               (0)
#define SPI_TXOICR_TXOICR_Msk                               (0x1UL << SPI_TXOICR_TXOICR_Pos)
#define SPI_TXOICR_TXOICR                                   SPI_TXOICR_TXOICR_Msk

/**********************  Bits definition for SPI_RXOICR  **********************/
#define SPI_RXOICR_RXOICR_Pos                               (0)
#define SPI_RXOICR_RXOICR_Msk                               (0x1UL << SPI_RXOICR_RXOICR_Pos)
#define SPI_RXOICR_RXOICR                                   SPI_RXOICR_RXOICR_Msk

/**********************  Bits definition for SPI_RXUICR  **********************/
#define SPI_RXUICR_RXUICR_Pos                               (0)
#define SPI_RXUICR_RXUICR_Msk                               (0x1UL << SPI_RXUICR_RXUICR_Pos)
#define SPI_RXUICR_RXUICR                                   SPI_RXUICR_RXUICR_Msk

/**********************  Bits definition for SPI_MSTICR  **********************/
#define SPI_MSTICR_MSTICR_Pos                               (0)
#define SPI_MSTICR_MSTICR_Msk                               (0x1UL << SPI_MSTICR_MSTICR_Pos)
#define SPI_MSTICR_MSTICR                                   SPI_MSTICR_MSTICR_Msk

/***********************  Bits definition for SPI_ICR  ************************/
#define SPI_ICR_ICR_Pos                                     (0)
#define SPI_ICR_ICR_Msk                                     (0x1UL << SPI_ICR_ICR_Pos)
#define SPI_ICR_ICR                                         SPI_ICR_ICR_Msk

/**********************  Bits definition for SPI_DMACR  ***********************/
#define SPI_DMACR_RDMAE_Pos                                 (0)
#define SPI_DMACR_RDMAE_Msk                                 (0x1UL << SPI_DMACR_RDMAE_Pos)
#define SPI_DMACR_RDMAE                                     SPI_DMACR_RDMAE_Msk
#define SPI_DMACR_TDMAE_Pos                                 (1)
#define SPI_DMACR_TDMAE_Msk                                 (0x1UL << SPI_DMACR_TDMAE_Pos)
#define SPI_DMACR_TDMAE                                     SPI_DMACR_TDMAE_Msk

/*********************  Bits definition for SPI_DMATDLR  **********************/
#define SPI_DMATDLR_TDL_Pos                                 (0)
#define SPI_DMATDLR_TDL_Msk                                 (0x7UL << SPI_DMATDLR_TDL_Pos)
#define SPI_DMATDLR_TDL                                     SPI_DMATDLR_TDL_Msk
#define SPI_DMATDLR_TDL_0                                   (0x1UL << SPI_DMATDLR_TDL_Pos)
#define SPI_DMATDLR_TDL_1                                   (0x2UL << SPI_DMATDLR_TDL_Pos)
#define SPI_DMATDLR_TDL_2                                   (0x4UL << SPI_DMATDLR_TDL_Pos)

/*********************  Bits definition for SPI_DMARDLR  **********************/
#define SPI_DMARDLR_RDL_Pos                                 (0)
#define SPI_DMARDLR_RDL_Msk                                 (0x7UL << SPI_DMARDLR_RDL_Pos)
#define SPI_DMARDLR_RDL                                     SPI_DMARDLR_RDL_Msk
#define SPI_DMARDLR_RDL_0                                   (0x1UL << SPI_DMARDLR_RDL_Pos)
#define SPI_DMARDLR_RDL_1                                   (0x2UL << SPI_DMARDLR_RDL_Pos)
#define SPI_DMARDLR_RDL_2                                   (0x4UL << SPI_DMARDLR_RDL_Pos)

/************************  Bits definition for SPI_DR  ************************/
#define SPI_DR_DR_Pos                                       (0)
#define SPI_DR_DR_Msk                                       (0xffffUL << SPI_DR_DR_Pos)
#define SPI_DR_DR                                           SPI_DR_DR_Msk

/******************************************************************************/
/*                                                                            */
/*                                 SYSCFG                                     */
/*                                                                            */
/******************************************************************************/

/********************  Bits definition for SYSCFG_SYS_CFG  ********************/
#define SYSCFG_SYS_CFG_SPI1_MODE_Pos                        (0)
#define SYSCFG_SYS_CFG_SPI1_MODE_Msk                        (0x1UL << SYSCFG_SYS_CFG_SPI1_MODE_Pos)
#define SYSCFG_SYS_CFG_SPI1_MODE                            SYSCFG_SYS_CFG_SPI1_MODE_Msk
#define SYSCFG_SYS_CFG_SPI2_MODE_Pos                        (1)
#define SYSCFG_SYS_CFG_SPI2_MODE_Msk                        (0x1UL << SYSCFG_SYS_CFG_SPI2_MODE_Pos)
#define SYSCFG_SYS_CFG_SPI2_MODE                            SYSCFG_SYS_CFG_SPI2_MODE_Msk
#define SYSCFG_SYS_CFG_UART1_MODE_Pos                       (8)
#define SYSCFG_SYS_CFG_UART1_MODE_Msk                       (0x1UL << SYSCFG_SYS_CFG_UART1_MODE_Pos)
#define SYSCFG_SYS_CFG_UART1_MODE                           SYSCFG_SYS_CFG_UART1_MODE_Msk
#define SYSCFG_SYS_CFG_UART2_MODE_Pos                       (9)
#define SYSCFG_SYS_CFG_UART2_MODE_Msk                       (0x1UL << SYSCFG_SYS_CFG_UART2_MODE_Pos)
#define SYSCFG_SYS_CFG_UART2_MODE                           SYSCFG_SYS_CFG_UART2_MODE_Msk
#define SYSCFG_SYS_CFG_UART3_MODE_Pos                       (10)
#define SYSCFG_SYS_CFG_UART3_MODE_Msk                       (0x1UL << SYSCFG_SYS_CFG_UART3_MODE_Pos)
#define SYSCFG_SYS_CFG_UART3_MODE                           SYSCFG_SYS_CFG_UART3_MODE_Msk
#define SYSCFG_SYS_CFG_UART4_MODE_Pos                       (11)
#define SYSCFG_SYS_CFG_UART4_MODE_Msk                       (0x1UL << SYSCFG_SYS_CFG_UART4_MODE_Pos)
#define SYSCFG_SYS_CFG_UART4_MODE                           SYSCFG_SYS_CFG_UART4_MODE_Msk
#define SYSCFG_SYS_CFG_BOOT_MODE_Pos                        (28)
#define SYSCFG_SYS_CFG_BOOT_MODE_Msk                        (0x3UL << SYSCFG_SYS_CFG_BOOT_MODE_Pos)
#define SYSCFG_SYS_CFG_BOOT_MODE                            SYSCFG_SYS_CFG_BOOT_MODE_Msk
#define SYSCFG_SYS_CFG_BOOT_MODE_0                          (0x1UL << SYSCFG_SYS_CFG_BOOT_MODE_Pos)
#define SYSCFG_SYS_CFG_BOOT_MODE_1                          (0x2UL << SYSCFG_SYS_CFG_BOOT_MODE_Pos)
#define SYSCFG_SYS_CFG_FLASHDMA_Pos                         (30)
#define SYSCFG_SYS_CFG_FLASHDMA_Msk                         (0x1UL << SYSCFG_SYS_CFG_FLASHDMA_Pos)
#define SYSCFG_SYS_CFG_FLASHDMA                             SYSCFG_SYS_CFG_FLASHDMA_Msk
#define SYSCFG_SYS_CFG_BOOTCTRL_Pos                         (31)
#define SYSCFG_SYS_CFG_BOOTCTRL_Msk                         (0x1UL << SYSCFG_SYS_CFG_BOOTCTRL_Pos)
#define SYSCFG_SYS_CFG_BOOTCTRL                             SYSCFG_SYS_CFG_BOOTCTRL_Msk

/*******************  Bits definition for SYSCFG_IRQ_CFG_1  *******************/
#define SYSCFG_IRQ_CFG_IRQ_0_Pos                            (0)
#define SYSCFG_IRQ_CFG_IRQ_0_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_0_Pos)
#define SYSCFG_IRQ_CFG_IRQ_0                                SYSCFG_IRQ_CFG_IRQ_0_Msk
#define SYSCFG_IRQ_CFG_IRQ_1_Pos                            (1)
#define SYSCFG_IRQ_CFG_IRQ_1_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_1_Pos)
#define SYSCFG_IRQ_CFG_IRQ_1                                SYSCFG_IRQ_CFG_IRQ_1_Msk
#define SYSCFG_IRQ_CFG_IRQ_2_Pos                            (2)
#define SYSCFG_IRQ_CFG_IRQ_2_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_2_Pos)
#define SYSCFG_IRQ_CFG_IRQ_2                                SYSCFG_IRQ_CFG_IRQ_2_Msk
#define SYSCFG_IRQ_CFG_IRQ_3_Pos                            (3)
#define SYSCFG_IRQ_CFG_IRQ_3_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_3_Pos)
#define SYSCFG_IRQ_CFG_IRQ_3                                SYSCFG_IRQ_CFG_IRQ_3_Msk
#define SYSCFG_IRQ_CFG_IRQ_4_Pos                            (4)
#define SYSCFG_IRQ_CFG_IRQ_4_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_4_Pos)
#define SYSCFG_IRQ_CFG_IRQ_4                                SYSCFG_IRQ_CFG_IRQ_4_Msk
#define SYSCFG_IRQ_CFG_IRQ_5_Pos                            (5)
#define SYSCFG_IRQ_CFG_IRQ_5_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_5_Pos)
#define SYSCFG_IRQ_CFG_IRQ_5                                SYSCFG_IRQ_CFG_IRQ_5_Msk
#define SYSCFG_IRQ_CFG_IRQ_6_Pos                            (6)
#define SYSCFG_IRQ_CFG_IRQ_6_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_6_Pos)
#define SYSCFG_IRQ_CFG_IRQ_6                                SYSCFG_IRQ_CFG_IRQ_6_Msk
#define SYSCFG_IRQ_CFG_IRQ_7_Pos                            (7)
#define SYSCFG_IRQ_CFG_IRQ_7_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_7_Pos)
#define SYSCFG_IRQ_CFG_IRQ_7                                SYSCFG_IRQ_CFG_IRQ_7_Msk
#define SYSCFG_IRQ_CFG_IRQ_8_Pos                            (8)
#define SYSCFG_IRQ_CFG_IRQ_8_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_8_Pos)
#define SYSCFG_IRQ_CFG_IRQ_8                                SYSCFG_IRQ_CFG_IRQ_8_Msk
#define SYSCFG_IRQ_CFG_IRQ_9_Pos                            (9)
#define SYSCFG_IRQ_CFG_IRQ_9_Msk                            (0x1UL << SYSCFG_IRQ_CFG_IRQ_9_Pos)
#define SYSCFG_IRQ_CFG_IRQ_9                                SYSCFG_IRQ_CFG_IRQ_9_Msk
#define SYSCFG_IRQ_CFG_IRQ_10_Pos                           (10)
#define SYSCFG_IRQ_CFG_IRQ_10_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_10_Pos)
#define SYSCFG_IRQ_CFG_IRQ_10                               SYSCFG_IRQ_CFG_IRQ_10_Msk
#define SYSCFG_IRQ_CFG_IRQ_11_Pos                           (11)
#define SYSCFG_IRQ_CFG_IRQ_11_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_11_Pos)
#define SYSCFG_IRQ_CFG_IRQ_11                               SYSCFG_IRQ_CFG_IRQ_11_Msk
#define SYSCFG_IRQ_CFG_IRQ_12_Pos                           (12)
#define SYSCFG_IRQ_CFG_IRQ_12_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_12_Pos)
#define SYSCFG_IRQ_CFG_IRQ_12                               SYSCFG_IRQ_CFG_IRQ_12_Msk
#define SYSCFG_IRQ_CFG_IRQ_13_Pos                           (13)
#define SYSCFG_IRQ_CFG_IRQ_13_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_13_Pos)
#define SYSCFG_IRQ_CFG_IRQ_13                               SYSCFG_IRQ_CFG_IRQ_13_Msk
#define SYSCFG_IRQ_CFG_IRQ_14_Pos                           (14)
#define SYSCFG_IRQ_CFG_IRQ_14_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_14_Pos)
#define SYSCFG_IRQ_CFG_IRQ_14                               SYSCFG_IRQ_CFG_IRQ_14_Msk
#define SYSCFG_IRQ_CFG_IRQ_15_Pos                           (15)
#define SYSCFG_IRQ_CFG_IRQ_15_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_15_Pos)
#define SYSCFG_IRQ_CFG_IRQ_15                               SYSCFG_IRQ_CFG_IRQ_15_Msk
#define SYSCFG_IRQ_CFG_IRQ_16_Pos                           (16)
#define SYSCFG_IRQ_CFG_IRQ_16_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_16_Pos)
#define SYSCFG_IRQ_CFG_IRQ_16                               SYSCFG_IRQ_CFG_IRQ_16_Msk
#define SYSCFG_IRQ_CFG_IRQ_17_Pos                           (17)
#define SYSCFG_IRQ_CFG_IRQ_17_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_17_Pos)
#define SYSCFG_IRQ_CFG_IRQ_17                               SYSCFG_IRQ_CFG_IRQ_17_Msk
#define SYSCFG_IRQ_CFG_IRQ_18_Pos                           (18)
#define SYSCFG_IRQ_CFG_IRQ_18_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_18_Pos)
#define SYSCFG_IRQ_CFG_IRQ_18                               SYSCFG_IRQ_CFG_IRQ_18_Msk
#define SYSCFG_IRQ_CFG_IRQ_19_Pos                           (19)
#define SYSCFG_IRQ_CFG_IRQ_19_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_19_Pos)
#define SYSCFG_IRQ_CFG_IRQ_19                               SYSCFG_IRQ_CFG_IRQ_19_Msk
#define SYSCFG_IRQ_CFG_IRQ_20_Pos                           (20)
#define SYSCFG_IRQ_CFG_IRQ_20_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_20_Pos)
#define SYSCFG_IRQ_CFG_IRQ_20                               SYSCFG_IRQ_CFG_IRQ_20_Msk
#define SYSCFG_IRQ_CFG_IRQ_21_Pos                           (21)
#define SYSCFG_IRQ_CFG_IRQ_21_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_21_Pos)
#define SYSCFG_IRQ_CFG_IRQ_21                               SYSCFG_IRQ_CFG_IRQ_21_Msk
#define SYSCFG_IRQ_CFG_IRQ_22_Pos                           (22)
#define SYSCFG_IRQ_CFG_IRQ_22_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_22_Pos)
#define SYSCFG_IRQ_CFG_IRQ_22                               SYSCFG_IRQ_CFG_IRQ_22_Msk
#define SYSCFG_IRQ_CFG_IRQ_23_Pos                           (23)
#define SYSCFG_IRQ_CFG_IRQ_23_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_23_Pos)
#define SYSCFG_IRQ_CFG_IRQ_23                               SYSCFG_IRQ_CFG_IRQ_23_Msk
#define SYSCFG_IRQ_CFG_IRQ_24_Pos                           (24)
#define SYSCFG_IRQ_CFG_IRQ_24_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_24_Pos)
#define SYSCFG_IRQ_CFG_IRQ_24                               SYSCFG_IRQ_CFG_IRQ_24_Msk
#define SYSCFG_IRQ_CFG_IRQ_25_Pos                           (25)
#define SYSCFG_IRQ_CFG_IRQ_25_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_25_Pos)
#define SYSCFG_IRQ_CFG_IRQ_25                               SYSCFG_IRQ_CFG_IRQ_25_Msk
#define SYSCFG_IRQ_CFG_IRQ_26_Pos                           (26)
#define SYSCFG_IRQ_CFG_IRQ_26_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_26_Pos)
#define SYSCFG_IRQ_CFG_IRQ_26                               SYSCFG_IRQ_CFG_IRQ_26_Msk
#define SYSCFG_IRQ_CFG_IRQ_27_Pos                           (27)
#define SYSCFG_IRQ_CFG_IRQ_27_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_27_Pos)
#define SYSCFG_IRQ_CFG_IRQ_27                               SYSCFG_IRQ_CFG_IRQ_27_Msk
#define SYSCFG_IRQ_CFG_IRQ_28_Pos                           (28)
#define SYSCFG_IRQ_CFG_IRQ_28_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_28_Pos)
#define SYSCFG_IRQ_CFG_IRQ_28                               SYSCFG_IRQ_CFG_IRQ_28_Msk
#define SYSCFG_IRQ_CFG_IRQ_29_Pos                           (29)
#define SYSCFG_IRQ_CFG_IRQ_29_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_29_Pos)
#define SYSCFG_IRQ_CFG_IRQ_29                               SYSCFG_IRQ_CFG_IRQ_29_Msk
#define SYSCFG_IRQ_CFG_IRQ_30_Pos                           (30)
#define SYSCFG_IRQ_CFG_IRQ_30_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_30_Pos)
#define SYSCFG_IRQ_CFG_IRQ_30                               SYSCFG_IRQ_CFG_IRQ_30_Msk
#define SYSCFG_IRQ_CFG_IRQ_31_Pos                           (31)
#define SYSCFG_IRQ_CFG_IRQ_31_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_31_Pos)
#define SYSCFG_IRQ_CFG_IRQ_31                               SYSCFG_IRQ_CFG_IRQ_31_Msk

/*******************  Bits definition for SYSCFG_IRQ_CFG_2  *******************/
#define SYSCFG_IRQ_CFG_IRQ_32_Pos                           (0)
#define SYSCFG_IRQ_CFG_IRQ_32_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_32_Pos)
#define SYSCFG_IRQ_CFG_IRQ_32                               SYSCFG_IRQ_CFG_IRQ_32_Msk
#define SYSCFG_IRQ_CFG_IRQ_33_Pos                           (1)
#define SYSCFG_IRQ_CFG_IRQ_33_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_33_Pos)
#define SYSCFG_IRQ_CFG_IRQ_33                               SYSCFG_IRQ_CFG_IRQ_33_Msk
#define SYSCFG_IRQ_CFG_IRQ_34_Pos                           (2)
#define SYSCFG_IRQ_CFG_IRQ_34_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_34_Pos)
#define SYSCFG_IRQ_CFG_IRQ_34                               SYSCFG_IRQ_CFG_IRQ_34_Msk
#define SYSCFG_IRQ_CFG_IRQ_35_Pos                           (3)
#define SYSCFG_IRQ_CFG_IRQ_35_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_35_Pos)
#define SYSCFG_IRQ_CFG_IRQ_35                               SYSCFG_IRQ_CFG_IRQ_35_Msk
#define SYSCFG_IRQ_CFG_IRQ_36_Pos                           (4)
#define SYSCFG_IRQ_CFG_IRQ_36_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_36_Pos)
#define SYSCFG_IRQ_CFG_IRQ_36                               SYSCFG_IRQ_CFG_IRQ_36_Msk
#define SYSCFG_IRQ_CFG_IRQ_37_Pos                           (5)
#define SYSCFG_IRQ_CFG_IRQ_37_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_37_Pos)
#define SYSCFG_IRQ_CFG_IRQ_37                               SYSCFG_IRQ_CFG_IRQ_37_Msk
#define SYSCFG_IRQ_CFG_IRQ_38_Pos                           (6)
#define SYSCFG_IRQ_CFG_IRQ_38_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_38_Pos)
#define SYSCFG_IRQ_CFG_IRQ_38                               SYSCFG_IRQ_CFG_IRQ_38_Msk
#define SYSCFG_IRQ_CFG_IRQ_39_Pos                           (7)
#define SYSCFG_IRQ_CFG_IRQ_39_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_39_Pos)
#define SYSCFG_IRQ_CFG_IRQ_39                               SYSCFG_IRQ_CFG_IRQ_39_Msk
#define SYSCFG_IRQ_CFG_IRQ_40_Pos                           (8)
#define SYSCFG_IRQ_CFG_IRQ_40_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_40_Pos)
#define SYSCFG_IRQ_CFG_IRQ_40                               SYSCFG_IRQ_CFG_IRQ_40_Msk
#define SYSCFG_IRQ_CFG_IRQ_41_Pos                           (9)
#define SYSCFG_IRQ_CFG_IRQ_41_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_41_Pos)
#define SYSCFG_IRQ_CFG_IRQ_41                               SYSCFG_IRQ_CFG_IRQ_41_Msk
#define SYSCFG_IRQ_CFG_IRQ_42_Pos                           (10)
#define SYSCFG_IRQ_CFG_IRQ_42_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_42_Pos)
#define SYSCFG_IRQ_CFG_IRQ_42                               SYSCFG_IRQ_CFG_IRQ_42_Msk
#define SYSCFG_IRQ_CFG_IRQ_43_Pos                           (11)
#define SYSCFG_IRQ_CFG_IRQ_43_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_43_Pos)
#define SYSCFG_IRQ_CFG_IRQ_43                               SYSCFG_IRQ_CFG_IRQ_43_Msk
#define SYSCFG_IRQ_CFG_IRQ_44_Pos                           (12)
#define SYSCFG_IRQ_CFG_IRQ_44_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_44_Pos)
#define SYSCFG_IRQ_CFG_IRQ_44                               SYSCFG_IRQ_CFG_IRQ_44_Msk
#define SYSCFG_IRQ_CFG_IRQ_45_Pos                           (13)
#define SYSCFG_IRQ_CFG_IRQ_45_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_45_Pos)
#define SYSCFG_IRQ_CFG_IRQ_45                               SYSCFG_IRQ_CFG_IRQ_45_Msk
#define SYSCFG_IRQ_CFG_IRQ_46_Pos                           (14)
#define SYSCFG_IRQ_CFG_IRQ_46_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_46_Pos)
#define SYSCFG_IRQ_CFG_IRQ_46                               SYSCFG_IRQ_CFG_IRQ_46_Msk
#define SYSCFG_IRQ_CFG_IRQ_47_Pos                           (15)
#define SYSCFG_IRQ_CFG_IRQ_47_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_47_Pos)
#define SYSCFG_IRQ_CFG_IRQ_47                               SYSCFG_IRQ_CFG_IRQ_47_Msk
#define SYSCFG_IRQ_CFG_IRQ_48_Pos                           (16)
#define SYSCFG_IRQ_CFG_IRQ_48_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_48_Pos)
#define SYSCFG_IRQ_CFG_IRQ_48                               SYSCFG_IRQ_CFG_IRQ_48_Msk
#define SYSCFG_IRQ_CFG_IRQ_49_Pos                           (17)
#define SYSCFG_IRQ_CFG_IRQ_49_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_49_Pos)
#define SYSCFG_IRQ_CFG_IRQ_49                               SYSCFG_IRQ_CFG_IRQ_49_Msk
#define SYSCFG_IRQ_CFG_IRQ_50_Pos                           (18)
#define SYSCFG_IRQ_CFG_IRQ_50_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_50_Pos)
#define SYSCFG_IRQ_CFG_IRQ_50                               SYSCFG_IRQ_CFG_IRQ_50_Msk
#define SYSCFG_IRQ_CFG_IRQ_51_Pos                           (19)
#define SYSCFG_IRQ_CFG_IRQ_51_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_51_Pos)
#define SYSCFG_IRQ_CFG_IRQ_51                               SYSCFG_IRQ_CFG_IRQ_51_Msk
#define SYSCFG_IRQ_CFG_IRQ_52_Pos                           (20)
#define SYSCFG_IRQ_CFG_IRQ_52_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_52_Pos)
#define SYSCFG_IRQ_CFG_IRQ_52                               SYSCFG_IRQ_CFG_IRQ_52_Msk
#define SYSCFG_IRQ_CFG_IRQ_53_Pos                           (21)
#define SYSCFG_IRQ_CFG_IRQ_53_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_53_Pos)
#define SYSCFG_IRQ_CFG_IRQ_53                               SYSCFG_IRQ_CFG_IRQ_53_Msk
#define SYSCFG_IRQ_CFG_IRQ_54_Pos                           (22)
#define SYSCFG_IRQ_CFG_IRQ_54_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_54_Pos)
#define SYSCFG_IRQ_CFG_IRQ_54                               SYSCFG_IRQ_CFG_IRQ_54_Msk
#define SYSCFG_IRQ_CFG_IRQ_55_Pos                           (23)
#define SYSCFG_IRQ_CFG_IRQ_55_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_55_Pos)
#define SYSCFG_IRQ_CFG_IRQ_55                               SYSCFG_IRQ_CFG_IRQ_55_Msk
#define SYSCFG_IRQ_CFG_IRQ_56_Pos                           (24)
#define SYSCFG_IRQ_CFG_IRQ_56_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_56_Pos)
#define SYSCFG_IRQ_CFG_IRQ_56                               SYSCFG_IRQ_CFG_IRQ_56_Msk
#define SYSCFG_IRQ_CFG_IRQ_57_Pos                           (25)
#define SYSCFG_IRQ_CFG_IRQ_57_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_57_Pos)
#define SYSCFG_IRQ_CFG_IRQ_57                               SYSCFG_IRQ_CFG_IRQ_57_Msk
#define SYSCFG_IRQ_CFG_IRQ_58_Pos                           (26)
#define SYSCFG_IRQ_CFG_IRQ_58_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_58_Pos)
#define SYSCFG_IRQ_CFG_IRQ_58                               SYSCFG_IRQ_CFG_IRQ_58_Msk
#define SYSCFG_IRQ_CFG_IRQ_59_Pos                           (27)
#define SYSCFG_IRQ_CFG_IRQ_59_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_59_Pos)
#define SYSCFG_IRQ_CFG_IRQ_59                               SYSCFG_IRQ_CFG_IRQ_59_Msk
#define SYSCFG_IRQ_CFG_IRQ_60_Pos                           (28)
#define SYSCFG_IRQ_CFG_IRQ_60_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_60_Pos)
#define SYSCFG_IRQ_CFG_IRQ_60                               SYSCFG_IRQ_CFG_IRQ_60_Msk
#define SYSCFG_IRQ_CFG_IRQ_61_Pos                           (29)
#define SYSCFG_IRQ_CFG_IRQ_61_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_61_Pos)
#define SYSCFG_IRQ_CFG_IRQ_61                               SYSCFG_IRQ_CFG_IRQ_61_Msk
#define SYSCFG_IRQ_CFG_IRQ_62_Pos                           (30)
#define SYSCFG_IRQ_CFG_IRQ_62_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_62_Pos)
#define SYSCFG_IRQ_CFG_IRQ_62                               SYSCFG_IRQ_CFG_IRQ_62_Msk
#define SYSCFG_IRQ_CFG_IRQ_63_Pos                           (31)
#define SYSCFG_IRQ_CFG_IRQ_63_Msk                           (0x1UL << SYSCFG_IRQ_CFG_IRQ_63_Pos)
#define SYSCFG_IRQ_CFG_IRQ_63                               SYSCFG_IRQ_CFG_IRQ_63_Msk

/********************  Bits definition for SYSCFG_DMA_CFG  ********************/
#define SYSCFG_DMA_CFG_HWCH0_Pos                            (0)
#define SYSCFG_DMA_CFG_HWCH0_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH0_Pos)
#define SYSCFG_DMA_CFG_HWCH0                                SYSCFG_DMA_CFG_HWCH0_Msk
#define SYSCFG_DMA_CFG_HWCH0_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH0_Pos)
#define SYSCFG_DMA_CFG_HWCH0_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH0_Pos)
#define SYSCFG_DMA_CFG_HWCH1_Pos                            (2)
#define SYSCFG_DMA_CFG_HWCH1_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH1_Pos)
#define SYSCFG_DMA_CFG_HWCH1                                SYSCFG_DMA_CFG_HWCH1_Msk
#define SYSCFG_DMA_CFG_HWCH1_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH1_Pos)
#define SYSCFG_DMA_CFG_HWCH1_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH1_Pos)
#define SYSCFG_DMA_CFG_HWCH2_Pos                            (4)
#define SYSCFG_DMA_CFG_HWCH2_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH2_Pos)
#define SYSCFG_DMA_CFG_HWCH2                                SYSCFG_DMA_CFG_HWCH2_Msk
#define SYSCFG_DMA_CFG_HWCH2_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH2_Pos)
#define SYSCFG_DMA_CFG_HWCH2_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH2_Pos)
#define SYSCFG_DMA_CFG_HWCH3_Pos                            (6)
#define SYSCFG_DMA_CFG_HWCH3_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH3_Pos)
#define SYSCFG_DMA_CFG_HWCH3                                SYSCFG_DMA_CFG_HWCH3_Msk
#define SYSCFG_DMA_CFG_HWCH3_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH3_Pos)
#define SYSCFG_DMA_CFG_HWCH3_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH3_Pos)
#define SYSCFG_DMA_CFG_HWCH4_Pos                            (8)
#define SYSCFG_DMA_CFG_HWCH4_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH4_Pos)
#define SYSCFG_DMA_CFG_HWCH4                                SYSCFG_DMA_CFG_HWCH4_Msk
#define SYSCFG_DMA_CFG_HWCH4_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH4_Pos)
#define SYSCFG_DMA_CFG_HWCH4_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH4_Pos)
#define SYSCFG_DMA_CFG_HWCH5_Pos                            (10)
#define SYSCFG_DMA_CFG_HWCH5_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH5_Pos)
#define SYSCFG_DMA_CFG_HWCH5                                SYSCFG_DMA_CFG_HWCH5_Msk
#define SYSCFG_DMA_CFG_HWCH5_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH5_Pos)
#define SYSCFG_DMA_CFG_HWCH5_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH5_Pos)
#define SYSCFG_DMA_CFG_HWCH6_Pos                            (12)
#define SYSCFG_DMA_CFG_HWCH6_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH6_Pos)
#define SYSCFG_DMA_CFG_HWCH6                                SYSCFG_DMA_CFG_HWCH6_Msk
#define SYSCFG_DMA_CFG_HWCH6_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH6_Pos)
#define SYSCFG_DMA_CFG_HWCH6_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH6_Pos)
#define SYSCFG_DMA_CFG_HWCH7_Pos                            (14)
#define SYSCFG_DMA_CFG_HWCH7_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH7_Pos)
#define SYSCFG_DMA_CFG_HWCH7                                SYSCFG_DMA_CFG_HWCH7_Msk
#define SYSCFG_DMA_CFG_HWCH7_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH7_Pos)
#define SYSCFG_DMA_CFG_HWCH7_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH7_Pos)
#define SYSCFG_DMA_CFG_HWCH8_Pos                            (16)
#define SYSCFG_DMA_CFG_HWCH8_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH8_Pos)
#define SYSCFG_DMA_CFG_HWCH8                                SYSCFG_DMA_CFG_HWCH8_Msk
#define SYSCFG_DMA_CFG_HWCH8_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH8_Pos)
#define SYSCFG_DMA_CFG_HWCH8_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH8_Pos)
#define SYSCFG_DMA_CFG_HWCH9_Pos                            (18)
#define SYSCFG_DMA_CFG_HWCH9_Msk                            (0x3UL << SYSCFG_DMA_CFG_HWCH9_Pos)
#define SYSCFG_DMA_CFG_HWCH9                                SYSCFG_DMA_CFG_HWCH9_Msk
#define SYSCFG_DMA_CFG_HWCH9_0                              (0x1UL << SYSCFG_DMA_CFG_HWCH9_Pos)
#define SYSCFG_DMA_CFG_HWCH9_1                              (0x2UL << SYSCFG_DMA_CFG_HWCH9_Pos)
#define SYSCFG_DMA_CFG_HWCH10_Pos                           (20)
#define SYSCFG_DMA_CFG_HWCH10_Msk                           (0x3UL << SYSCFG_DMA_CFG_HWCH10_Pos)
#define SYSCFG_DMA_CFG_HWCH10                               SYSCFG_DMA_CFG_HWCH10_Msk
#define SYSCFG_DMA_CFG_HWCH10_0                             (0x1UL << SYSCFG_DMA_CFG_HWCH10_Pos)
#define SYSCFG_DMA_CFG_HWCH10_1                             (0x2UL << SYSCFG_DMA_CFG_HWCH10_Pos)
#define SYSCFG_DMA_CFG_HWCH11_Pos                           (22)
#define SYSCFG_DMA_CFG_HWCH11_Msk                           (0x3UL << SYSCFG_DMA_CFG_HWCH11_Pos)
#define SYSCFG_DMA_CFG_HWCH11                               SYSCFG_DMA_CFG_HWCH11_Msk
#define SYSCFG_DMA_CFG_HWCH11_0                             (0x1UL << SYSCFG_DMA_CFG_HWCH11_Pos)
#define SYSCFG_DMA_CFG_HWCH11_1                             (0x2UL << SYSCFG_DMA_CFG_HWCH11_Pos)
#define SYSCFG_DMA_CFG_HWCH12_Pos                           (24)
#define SYSCFG_DMA_CFG_HWCH12_Msk                           (0x3UL << SYSCFG_DMA_CFG_HWCH12_Pos)
#define SYSCFG_DMA_CFG_HWCH12                               SYSCFG_DMA_CFG_HWCH12_Msk
#define SYSCFG_DMA_CFG_HWCH12_0                             (0x1UL << SYSCFG_DMA_CFG_HWCH12_Pos)
#define SYSCFG_DMA_CFG_HWCH12_1                             (0x2UL << SYSCFG_DMA_CFG_HWCH12_Pos)
#define SYSCFG_DMA_CFG_HWCH13_Pos                           (26)
#define SYSCFG_DMA_CFG_HWCH13_Msk                           (0x3UL << SYSCFG_DMA_CFG_HWCH13_Pos)
#define SYSCFG_DMA_CFG_HWCH13                               SYSCFG_DMA_CFG_HWCH13_Msk
#define SYSCFG_DMA_CFG_HWCH13_0                             (0x1UL << SYSCFG_DMA_CFG_HWCH13_Pos)
#define SYSCFG_DMA_CFG_HWCH13_1                             (0x2UL << SYSCFG_DMA_CFG_HWCH13_Pos)
#define SYSCFG_DMA_CFG_HWCH14_Pos                           (28)
#define SYSCFG_DMA_CFG_HWCH14_Msk                           (0x3UL << SYSCFG_DMA_CFG_HWCH14_Pos)
#define SYSCFG_DMA_CFG_HWCH14                               SYSCFG_DMA_CFG_HWCH14_Msk
#define SYSCFG_DMA_CFG_HWCH14_0                             (0x1UL << SYSCFG_DMA_CFG_HWCH14_Pos)
#define SYSCFG_DMA_CFG_HWCH14_1                             (0x2UL << SYSCFG_DMA_CFG_HWCH14_Pos)
#define SYSCFG_DMA_CFG_HWCH15_Pos                           (30)
#define SYSCFG_DMA_CFG_HWCH15_Msk                           (0x3UL << SYSCFG_DMA_CFG_HWCH15_Pos)
#define SYSCFG_DMA_CFG_HWCH15                               SYSCFG_DMA_CFG_HWCH15_Msk
#define SYSCFG_DMA_CFG_HWCH15_0                             (0x1UL << SYSCFG_DMA_CFG_HWCH15_Pos)
#define SYSCFG_DMA_CFG_HWCH15_1                             (0x2UL << SYSCFG_DMA_CFG_HWCH15_Pos)

/********************  Bits definition for SYSCFG_WDT_CFG  ********************/
#define SYSCFG_WDTW_CFG_EXTCLK_Pos                              (0)
#define SYSCFG_WDTW_CFG_EXTCLK_Msk                              (0x1UL << SYSCFG_WDTW_CFG_EXTCLK_Pos)
#define SYSCFG_WDTW_CFG_EXTCLK                                  SYSCFG_WDTW_CFG_EXTCLK_Msk
#define SYSCFG_WDTW_CFG_SPD_Pos                              (1)
#define SYSCFG_WDTW_CFG_SPD_Msk                              (0x1UL << SYSCFG_WDTW_CFG_SPD_Pos)
#define SYSCFG_WDTW_CFG_SPD                                  SYSCFG_WDTW_CFG_SPD_Msk
#define SYSCFG_WDTW_CFG_RST_Pos                             (31)
#define SYSCFG_WDTW_CFG_RST_Msk                             (0x1UL << SYSCFG_WDTW_CFG_RST_Pos)
#define SYSCFG_WDTW_CFG_RST                                 SYSCFG_WDTW_CFG_RST_Msk

/******************  Bits definition for SYSCFG_SW_RST_CFG  *******************/
#define SYSCFG_RST_CFG_UART0_Pos                            (0)
#define SYSCFG_RST_CFG_UART0_Msk                            (0x1UL << SYSCFG_RST_CFG_UART0_Pos)
#define SYSCFG_RST_CFG_UART0                                SYSCFG_RST_CFG_UART0_Msk
#define SYSCFG_RST_CFG_UART2_Pos                            (1)
#define SYSCFG_RST_CFG_UART2_Msk                            (0x1UL << SYSCFG_RST_CFG_UART2_Pos)
#define SYSCFG_RST_CFG_UART2                                SYSCFG_RST_CFG_UART2_Msk
#define SYSCFG_RST_CFG_UART2_Pos                            (2)
#define SYSCFG_RST_CFG_UART2_Msk                            (0x1UL << SYSCFG_RST_CFG_UART2_Pos)
#define SYSCFG_RST_CFG_UART2                                SYSCFG_RST_CFG_UART2_Msk
#define SYSCFG_RST_CFG_UART4_Pos                            (3)
#define SYSCFG_RST_CFG_UART4_Msk                            (0x1UL << SYSCFG_RST_CFG_UART4_Pos)
#define SYSCFG_RST_CFG_UART4                                SYSCFG_RST_CFG_UART4_Msk
#define SYSCFG_RST_CFG_I2C1_Pos                             (4)
#define SYSCFG_RST_CFG_I2C1_Msk                             (0x1UL << SYSCFG_RST_CFG_I2C1_Pos)
#define SYSCFG_RST_CFG_I2C1                                 SYSCFG_RST_CFG_I2C1_Msk
#define SYSCFG_RST_CFG_I2C2_Pos                             (5)
#define SYSCFG_RST_CFG_I2C2_Msk                             (0x1UL << SYSCFG_RST_CFG_I2C2_Pos)
#define SYSCFG_RST_CFG_I2C2                                 SYSCFG_RST_CFG_I2C2_Msk
#define SYSCFG_RST_CFG_TIMB00_Pos                           (6)
#define SYSCFG_RST_CFG_TIMB00_Msk                           (0x1UL << SYSCFG_RST_CFG_TIMB00_Pos)
#define SYSCFG_RST_CFG_TIMB00                               SYSCFG_RST_CFG_TIMB00_Msk
#define SYSCFG_RST_CFG_TIMB01_Pos                           (7)
#define SYSCFG_RST_CFG_TIMB01_Msk                           (0x1UL << SYSCFG_RST_CFG_TIMB01_Pos)
#define SYSCFG_RST_CFG_TIMB01                               SYSCFG_RST_CFG_TIMB01_Msk
#define SYSCFG_RST_CFG_TIMB02_Pos                           (8)
#define SYSCFG_RST_CFG_TIMB02_Msk                           (0x1UL << SYSCFG_RST_CFG_TIMB02_Pos)
#define SYSCFG_RST_CFG_TIMB02                               SYSCFG_RST_CFG_TIMB02_Msk
#define SYSCFG_RST_CFG_TIMB14_Pos                           (9)
#define SYSCFG_RST_CFG_TIMB14_Msk                           (0x1UL << SYSCFG_RST_CFG_TIMB14_Pos)
#define SYSCFG_RST_CFG_TIMB14                               SYSCFG_RST_CFG_TIMB14_Msk
#define SYSCFG_RST_CFG_TIMB21_Pos                           (10)
#define SYSCFG_RST_CFG_TIMB21_Msk                           (0x1UL << SYSCFG_RST_CFG_TIMB21_Pos)
#define SYSCFG_RST_CFG_TIMB21                               SYSCFG_RST_CFG_TIMB21_Msk
#define SYSCFG_RST_CFG_TIMB22_Pos                           (11)
#define SYSCFG_RST_CFG_TIMB22_Msk                           (0x1UL << SYSCFG_RST_CFG_TIMB22_Pos)
#define SYSCFG_RST_CFG_TIMB22                               SYSCFG_RST_CFG_TIMB22_Msk
#define SYSCFG_RST_CFG_TIMB23_Pos                           (12)
#define SYSCFG_RST_CFG_TIMB23_Msk                           (0x1UL << SYSCFG_RST_CFG_TIMB23_Pos)
#define SYSCFG_RST_CFG_TIMB23                               SYSCFG_RST_CFG_TIMB23_Msk
#define SYSCFG_RST_CFG_TIMB24_Pos                           (13)
#define SYSCFG_RST_CFG_TIMB24_Msk                           (0x1UL << SYSCFG_RST_CFG_TIMB24_Pos)
#define SYSCFG_RST_CFG_TIMB24                               SYSCFG_RST_CFG_TIMB24_Msk
#define SYSCFG_RST_CFG_SPI0_Pos                             (14)
#define SYSCFG_RST_CFG_SPI0_Msk                             (0x1UL << SYSCFG_RST_CFG_SPI0_Pos)
#define SYSCFG_RST_CFG_SPI0                                 SYSCFG_RST_CFG_SPI0_Msk
#define SYSCFG_RST_CFG_SPI1_Pos                             (15)
#define SYSCFG_RST_CFG_SPI1_Msk                             (0x1UL << SYSCFG_RST_CFG_SPI1_Pos)
#define SYSCFG_RST_CFG_SPI1                                 SYSCFG_RST_CFG_SPI1_Msk
#define SYSCFG_RST_CFG_GPIO_Pos                             (16)
#define SYSCFG_RST_CFG_GPIO_Msk                             (0x1UL << SYSCFG_RST_CFG_GPIO_Pos)
#define SYSCFG_RST_CFG_GPIO                                 SYSCFG_RST_CFG_GPIO_Msk
#define SYSCFG_RST_CFG_TIMA_Pos                             (17)
#define SYSCFG_RST_CFG_TIMA_Msk                             (0x1UL << SYSCFG_RST_CFG_TIMA_Pos)
#define SYSCFG_RST_CFG_TIMA                                 SYSCFG_RST_CFG_TIMA_Msk
#define SYSCFG_RST_CFG_TIMG_Pos                             (18)
#define SYSCFG_RST_CFG_TIMG_Msk                             (0x1UL << SYSCFG_RST_CFG_TIMG_Pos)
#define SYSCFG_RST_CFG_TIMG                                 SYSCFG_RST_CFG_TIMG_Msk

/*****************  Bits definition for SYSCFG_TIMER_ADV_CFG  *****************/
#define SYSCFG_TACFG_LKE_Pos                                (0)
#define SYSCFG_TACFG_LKE_Msk                                (0x1UL << SYSCFG_TACFG_LKE_Pos)
#define SYSCFG_TACFG_LKE                                    SYSCFG_TACFG_LKE_Msk
#define SYSCFG_TACFG_VOLDET_Pos                             (1)
#define SYSCFG_TACFG_VOLDET_Msk                             (0x1UL << SYSCFG_TACFG_VOLDET_Pos)
#define SYSCFG_TACFG_VOLDET                                 SYSCFG_TACFG_VOLDET_Msk
#define SYSCFG_TACFG_PARCHK_Pos                             (2)
#define SYSCFG_TACFG_PARCHK_Msk                             (0x1UL << SYSCFG_TACFG_PARCHK_Pos)
#define SYSCFG_TACFG_PARCHK                                 SYSCFG_TACFG_PARCHK_Msk
#define SYSCFG_TACFG_ECCERR_Pos                             (3)
#define SYSCFG_TACFG_ECCERR_Msk                             (0x1UL << SYSCFG_TACFG_ECCERR_Pos)
#define SYSCFG_TACFG_ECCERR                                 SYSCFG_TACFG_ECCERR_Msk

/*****************  Bits definition for SYSCFG_GPIO_ENAUX_A  ******************/
#define SYSCFG_GPIOAUX_A_Pos                                (0)
#define SYSCFG_GPIOAUX_A_Msk                                (0xffffffffUL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A                                    SYSCFG_GPIOAUX_A_Msk
#define SYSCFG_GPIOAUX_A_0                                  (0x1UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_1                                  (0x2UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_2                                  (0x4UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_3                                  (0x8UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_4                                  (0x10UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_5                                  (0x20UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_6                                  (0x40UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_7                                  (0x80UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_8                                  (0x100UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_9                                  (0x200UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_10                                 (0x400UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_11                                 (0x800UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_12                                 (0x1000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_13                                 (0x2000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_14                                 (0x4000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_15                                 (0x8000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_16                                 (0x10000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_17                                 (0x20000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_18                                 (0x40000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_19                                 (0x80000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_20                                 (0x100000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_21                                 (0x200000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_22                                 (0x400000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_23                                 (0x800000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_24                                 (0x1000000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_25                                 (0x2000000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_26                                 (0x4000000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_27                                 (0x8000000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_28                                 (0x10000000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_29                                 (0x20000000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_30                                 (0x40000000UL << SYSCFG_GPIOAUX_A_Pos)
#define SYSCFG_GPIOAUX_A_31                                 (0x80000000UL << SYSCFG_GPIOAUX_A_Pos)

/*****************  Bits definition for SYSCFG_GPIO_ENAUX_B  ******************/
#define SYSCFG_GPIOAUX_B_Pos                                (0)
#define SYSCFG_GPIOAUX_B_Msk                                (0xffffffffUL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B                                    SYSCFG_GPIOAUX_B_Msk
#define SYSCFG_GPIOAUX_B_0                                  (0x1UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_1                                  (0x2UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_2                                  (0x4UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_3                                  (0x8UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_4                                  (0x10UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_5                                  (0x20UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_6                                  (0x40UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_7                                  (0x80UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_8                                  (0x100UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_9                                  (0x200UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_10                                 (0x400UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_11                                 (0x800UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_12                                 (0x1000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_13                                 (0x2000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_14                                 (0x4000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_15                                 (0x8000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_16                                 (0x10000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_17                                 (0x20000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_18                                 (0x40000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_19                                 (0x80000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_20                                 (0x100000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_21                                 (0x200000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_22                                 (0x400000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_23                                 (0x800000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_24                                 (0x1000000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_25                                 (0x2000000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_26                                 (0x4000000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_27                                 (0x8000000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_28                                 (0x10000000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_29                                 (0x20000000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_30                                 (0x40000000UL << SYSCFG_GPIOAUX_B_Pos)
#define SYSCFG_GPIOAUX_B_31                                 (0x80000000UL << SYSCFG_GPIOAUX_B_Pos)

/*****************  Bits definition for SYSCFG_GPIO_ENAUX_C  ******************/
#define SYSCFG_GPIOAUX_C_Pos                                (0)
#define SYSCFG_GPIOAUX_C_Msk                                (0xffffffffUL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C                                    SYSCFG_GPIOAUX_C_Msk
#define SYSCFG_GPIOAUX_C_0                                  (0x1UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_1                                  (0x2UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_2                                  (0x4UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_3                                  (0x8UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_4                                  (0x10UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_5                                  (0x20UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_6                                  (0x40UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_7                                  (0x80UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_8                                  (0x100UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_9                                  (0x200UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_10                                 (0x400UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_11                                 (0x800UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_12                                 (0x1000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_13                                 (0x2000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_14                                 (0x4000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_15                                 (0x8000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_16                                 (0x10000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_17                                 (0x20000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_18                                 (0x40000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_19                                 (0x80000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_20                                 (0x100000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_21                                 (0x200000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_22                                 (0x400000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_23                                 (0x800000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_24                                 (0x1000000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_25                                 (0x2000000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_26                                 (0x4000000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_27                                 (0x8000000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_28                                 (0x10000000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_29                                 (0x20000000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_30                                 (0x40000000UL << SYSCFG_GPIOAUX_C_Pos)
#define SYSCFG_GPIOAUX_C_31                                 (0x80000000UL << SYSCFG_GPIOAUX_C_Pos)

/*****************  Bits definition for SYSCFG_GPIO_ENAUX_D  ******************/
#define SYSCFG_GPIOAUX_D_Pos                                (0)
#define SYSCFG_GPIOAUX_D_Msk                                (0xffffffffUL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D                                    SYSCFG_GPIOAUX_D_Msk
#define SYSCFG_GPIOAUX_D_0                                  (0x1UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_1                                  (0x2UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_2                                  (0x4UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_3                                  (0x8UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_4                                  (0x10UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_5                                  (0x20UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_6                                  (0x40UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_7                                  (0x80UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_8                                  (0x100UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_9                                  (0x200UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_10                                 (0x400UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_11                                 (0x800UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_12                                 (0x1000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_13                                 (0x2000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_14                                 (0x4000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_15                                 (0x8000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_16                                 (0x10000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_17                                 (0x20000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_18                                 (0x40000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_19                                 (0x80000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_20                                 (0x100000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_21                                 (0x200000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_22                                 (0x400000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_23                                 (0x800000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_24                                 (0x1000000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_25                                 (0x2000000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_26                                 (0x4000000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_27                                 (0x8000000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_28                                 (0x10000000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_29                                 (0x20000000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_30                                 (0x40000000UL << SYSCFG_GPIOAUX_D_Pos)
#define SYSCFG_GPIOAUX_D_31                                 (0x80000000UL << SYSCFG_GPIOAUX_D_Pos)

/*******************  Bits definition for SYSCFG_UID_REG_0  *******************/
#define SYSCFG_UID_REG_0_UID_Pos                            (0)
#define SYSCFG_UID_REG_0_UID_Msk                            (0xffffffffUL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID                                SYSCFG_UID_REG_0_UID_Msk
#define SYSCFG_UID_REG_0_UID_0                              (0x1UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_1                              (0x2UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_2                              (0x4UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_3                              (0x8UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_4                              (0x10UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_5                              (0x20UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_6                              (0x40UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_7                              (0x80UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_8                              (0x100UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_9                              (0x200UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_10                             (0x400UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_11                             (0x800UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_12                             (0x1000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_13                             (0x2000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_14                             (0x4000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_15                             (0x8000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_16                             (0x10000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_17                             (0x20000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_18                             (0x40000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_19                             (0x80000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_20                             (0x100000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_21                             (0x200000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_22                             (0x400000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_23                             (0x800000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_24                             (0x1000000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_25                             (0x2000000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_26                             (0x4000000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_27                             (0x8000000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_28                             (0x10000000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_29                             (0x20000000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_30                             (0x40000000UL << SYSCFG_UID_REG_0_UID_Pos)
#define SYSCFG_UID_REG_0_UID_31                             (0x80000000UL << SYSCFG_UID_REG_0_UID_Pos)

/*******************  Bits definition for SYSCFG_UID_REG_1  *******************/
#define SYSCFG_UID_REG_1_UID_Pos                            (0)
#define SYSCFG_UID_REG_1_UID_Msk                            (0xffffffffUL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID                                SYSCFG_UID_REG_1_UID_Msk
#define SYSCFG_UID_REG_1_UID_0                              (0x1UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_1                              (0x2UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_2                              (0x4UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_3                              (0x8UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_4                              (0x10UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_5                              (0x20UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_6                              (0x40UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_7                              (0x80UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_8                              (0x100UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_9                              (0x200UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_10                             (0x400UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_11                             (0x800UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_12                             (0x1000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_13                             (0x2000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_14                             (0x4000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_15                             (0x8000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_16                             (0x10000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_17                             (0x20000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_18                             (0x40000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_19                             (0x80000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_20                             (0x100000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_21                             (0x200000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_22                             (0x400000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_23                             (0x800000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_24                             (0x1000000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_25                             (0x2000000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_26                             (0x4000000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_27                             (0x8000000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_28                             (0x10000000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_29                             (0x20000000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_30                             (0x40000000UL << SYSCFG_UID_REG_1_UID_Pos)
#define SYSCFG_UID_REG_1_UID_31                             (0x80000000UL << SYSCFG_UID_REG_1_UID_Pos)

/*******************  Bits definition for SYSCFG_UID_REG_2  *******************/
#define SYSCFG_UID_REG_2_UID_Pos                            (0)
#define SYSCFG_UID_REG_2_UID_Msk                            (0xffffffffUL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID                                SYSCFG_UID_REG_2_UID_Msk
#define SYSCFG_UID_REG_2_UID_0                              (0x1UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_1                              (0x2UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_2                              (0x4UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_3                              (0x8UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_4                              (0x10UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_5                              (0x20UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_6                              (0x40UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_7                              (0x80UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_8                              (0x100UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_9                              (0x200UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_10                             (0x400UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_11                             (0x800UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_12                             (0x1000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_13                             (0x2000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_14                             (0x4000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_15                             (0x8000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_16                             (0x10000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_17                             (0x20000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_18                             (0x40000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_19                             (0x80000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_20                             (0x100000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_21                             (0x200000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_22                             (0x400000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_23                             (0x800000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_24                             (0x1000000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_25                             (0x2000000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_26                             (0x4000000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_27                             (0x8000000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_28                             (0x10000000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_29                             (0x20000000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_30                             (0x40000000UL << SYSCFG_UID_REG_2_UID_Pos)
#define SYSCFG_UID_REG_2_UID_31                             (0x80000000UL << SYSCFG_UID_REG_2_UID_Pos)

/******************************************************************************/
/*                                                                            */
/*                                   TIM                                      */
/*                                                                            */
/******************************************************************************/

/***********************  Bits definition for TIM_CR1  ************************/
#define TIM_CR1_CEN_Pos                                     (0)
#define TIM_CR1_CEN_Msk                                     (0x1UL << TIM_CR1_CEN_Pos)
#define TIM_CR1_CEN                                         TIM_CR1_CEN_Msk
#define TIM_CR1_UDIS_Pos                                    (1)
#define TIM_CR1_UDIS_Msk                                    (0x1UL << TIM_CR1_UDIS_Pos)
#define TIM_CR1_UDIS                                        TIM_CR1_UDIS_Msk
#define TIM_CR1_URS_Pos                                     (2)
#define TIM_CR1_URS_Msk                                     (0x1UL << TIM_CR1_URS_Pos)
#define TIM_CR1_URS                                         TIM_CR1_URS_Msk
#define TIM_CR1_OPM_Pos                                     (3)
#define TIM_CR1_OPM_Msk                                     (0x1UL << TIM_CR1_OPM_Pos)
#define TIM_CR1_OPM                                         TIM_CR1_OPM_Msk
#define TIM_CR1_DIR_Pos                                     (4)
#define TIM_CR1_DIR_Msk                                     (0x1UL << TIM_CR1_DIR_Pos)
#define TIM_CR1_DIR                                         TIM_CR1_DIR_Msk
#define TIM_CR1_CMS_Pos                                     (5)
#define TIM_CR1_CMS_Msk                                     (0x3UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS                                         TIM_CR1_CMS_Msk
#define TIM_CR1_CMS_0                                       (0x1UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_CMS_1                                       (0x2UL << TIM_CR1_CMS_Pos)
#define TIM_CR1_ARPE_Pos                                    (7)
#define TIM_CR1_ARPE_Msk                                    (0x1UL << TIM_CR1_ARPE_Pos)
#define TIM_CR1_ARPE                                        TIM_CR1_ARPE_Msk
#define TIM_CR1_CKD_Pos                                     (8)
#define TIM_CR1_CKD_Msk                                     (0x3UL << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD                                         TIM_CR1_CKD_Msk
#define TIM_CR1_CKD_0                                       (0x1UL << TIM_CR1_CKD_Pos)
#define TIM_CR1_CKD_1                                       (0x2UL << TIM_CR1_CKD_Pos)
#define TIM_CR1_UIFREMAP_Pos                                (11)
#define TIM_CR1_UIFREMAP_Msk                                (0x1UL << TIM_CR1_UIFREMAP_Pos)
#define TIM_CR1_UIFREMAP                                    TIM_CR1_UIFREMAP_Msk

/***********************  Bits definition for TIM_CR2  ************************/
#define TIM_CR2_CCPC_Pos                                    (0)
#define TIM_CR2_CCPC_Msk                                    (0x1UL << TIM_CR2_CCPC_Pos)
#define TIM_CR2_CCPC                                        TIM_CR2_CCPC_Msk
#define TIM_CR2_CCUS_Pos                                    (2)
#define TIM_CR2_CCUS_Msk                                    (0x1UL << TIM_CR2_CCUS_Pos)
#define TIM_CR2_CCUS                                        TIM_CR2_CCUS_Msk
#define TIM_CR2_CCDS_Pos                                    (3)
#define TIM_CR2_CCDS_Msk                                    (0x1UL << TIM_CR2_CCDS_Pos)
#define TIM_CR2_CCDS                                        TIM_CR2_CCDS_Msk
#define TIM_CR2_MMS_Pos                                     (4)
#define TIM_CR2_MMS_Msk                                     (0x7UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS                                         TIM_CR2_MMS_Msk
#define TIM_CR2_MMS_0                                       (0x1UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_1                                       (0x2UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_MMS_2                                       (0x4UL << TIM_CR2_MMS_Pos)
#define TIM_CR2_TI1S_Pos                                    (7)
#define TIM_CR2_TI1S_Msk                                    (0x1UL << TIM_CR2_TI1S_Pos)
#define TIM_CR2_TI1S                                        TIM_CR2_TI1S_Msk
#define TIM_CR2_OIS1_Pos                                    (8)
#define TIM_CR2_OIS1_Msk                                    (0x1UL << TIM_CR2_OIS1_Pos)
#define TIM_CR2_OIS1                                        TIM_CR2_OIS1_Msk
#define TIM_CR2_OIS1N_Pos                                   (9)
#define TIM_CR2_OIS1N_Msk                                   (0x1UL << TIM_CR2_OIS1N_Pos)
#define TIM_CR2_OIS1N                                       TIM_CR2_OIS1N_Msk
#define TIM_CR2_OIS2_Pos                                    (10)
#define TIM_CR2_OIS2_Msk                                    (0x1UL << TIM_CR2_OIS2_Pos)
#define TIM_CR2_OIS2                                        TIM_CR2_OIS2_Msk
#define TIM_CR2_OIS2N_Pos                                   (11)
#define TIM_CR2_OIS2N_Msk                                   (0x1UL << TIM_CR2_OIS2N_Pos)
#define TIM_CR2_OIS2N                                       TIM_CR2_OIS2N_Msk
#define TIM_CR2_OIS3_Pos                                    (12)
#define TIM_CR2_OIS3_Msk                                    (0x1UL << TIM_CR2_OIS3_Pos)
#define TIM_CR2_OIS3                                        TIM_CR2_OIS3_Msk
#define TIM_CR2_OIS3N_Pos                                   (13)
#define TIM_CR2_OIS3N_Msk                                   (0x1UL << TIM_CR2_OIS3N_Pos)
#define TIM_CR2_OIS3N                                       TIM_CR2_OIS3N_Msk
#define TIM_CR2_OIS4_Pos                                    (14)
#define TIM_CR2_OIS4_Msk                                    (0x1UL << TIM_CR2_OIS4_Pos)
#define TIM_CR2_OIS4                                        TIM_CR2_OIS4_Msk
#define TIM_CR2_OIS5_Pos                                    (16)
#define TIM_CR2_OIS5_Msk                                    (0x1UL << TIM_CR2_OIS5_Pos)
#define TIM_CR2_OIS5                                        TIM_CR2_OIS5_Msk
#define TIM_CR2_OIS6_Pos                                    (18)
#define TIM_CR2_OIS6_Msk                                    (0x1UL << TIM_CR2_OIS6_Pos)
#define TIM_CR2_OIS6                                        TIM_CR2_OIS6_Msk
#define TIM_CR2_MMS2_Pos                                    (20)
#define TIM_CR2_MMS2_Msk                                    (0xfUL << TIM_CR2_MMS2_Pos)
#define TIM_CR2_MMS2                                        TIM_CR2_MMS2_Msk
#define TIM_CR2_MMS2_0                                      (0x1UL << TIM_CR2_MMS2_Pos)
#define TIM_CR2_MMS2_1                                      (0x2UL << TIM_CR2_MMS2_Pos)
#define TIM_CR2_MMS2_2                                      (0x4UL << TIM_CR2_MMS2_Pos)
#define TIM_CR2_MMS2_3                                      (0x8UL << TIM_CR2_MMS2_Pos)

/***********************  Bits definition for TIM_SMCR  ***********************/
#define TIM_SMCR_SMS_Pos                                    (0)
#define TIM_SMCR_SMS_Msk                                    (0x10007UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS                                        TIM_SMCR_SMS_Msk
#define TIM_SMCR_SMS_0                                      (0x1UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_1                                      (0x2UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_2                                      (0x4UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_SMS_3                                      (0x10000UL << TIM_SMCR_SMS_Pos)
#define TIM_SMCR_OCCS_Pos                                   (3)
#define TIM_SMCR_OCCS_Msk                                   (0x1UL << TIM_SMCR_OCCS_Pos)
#define TIM_SMCR_OCCS                                       TIM_SMCR_OCCS_Msk
#define TIM_SMCR_TS_Pos                                     (4)
#define TIM_SMCR_TS_Msk                                     (0x30007UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS                                         TIM_SMCR_TS_Msk
#define TIM_SMCR_TS_0                                       (0x1UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_1                                       (0x2UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_2                                       (0x4UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_3                                       (0x10000UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_TS_4                                       (0x20000UL << TIM_SMCR_TS_Pos)
#define TIM_SMCR_MSM_Pos                                    (7)
#define TIM_SMCR_MSM_Msk                                    (0x1UL << TIM_SMCR_MSM_Pos)
#define TIM_SMCR_MSM                                        TIM_SMCR_MSM_Msk
#define TIM_SMCR_ETF_Pos                                    (8)
#define TIM_SMCR_ETF_Msk                                    (0xfUL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF                                        TIM_SMCR_ETF_Msk
#define TIM_SMCR_ETF_0                                      (0x1UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_1                                      (0x2UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_2                                      (0x4UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETF_3                                      (0x8UL << TIM_SMCR_ETF_Pos)
#define TIM_SMCR_ETPS_Pos                                   (12)
#define TIM_SMCR_ETPS_Msk                                   (0x3UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS                                       TIM_SMCR_ETPS_Msk
#define TIM_SMCR_ETPS_0                                     (0x1UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ETPS_1                                     (0x2UL << TIM_SMCR_ETPS_Pos)
#define TIM_SMCR_ECE_Pos                                    (14)
#define TIM_SMCR_ECE_Msk                                    (0x1UL << TIM_SMCR_ECE_Pos)
#define TIM_SMCR_ECE                                        TIM_SMCR_ECE_Msk
#define TIM_SMCR_ETP_Pos                                    (15)
#define TIM_SMCR_ETP_Msk                                    (0x1UL << TIM_SMCR_ETP_Pos)
#define TIM_SMCR_ETP                                        TIM_SMCR_ETP_Msk

/***********************  Bits definition for TIM_DIER  ***********************/
#define TIM_DIER_UIE_Pos                                    (0)
#define TIM_DIER_UIE_Msk                                    (0x1UL << TIM_DIER_UIE_Pos)
#define TIM_DIER_UIE                                        TIM_DIER_UIE_Msk
#define TIM_DIER_CC1IE_Pos                                  (1)
#define TIM_DIER_CC1IE_Msk                                  (0x1UL << TIM_DIER_CC1IE_Pos)
#define TIM_DIER_CC1IE                                      TIM_DIER_CC1IE_Msk
#define TIM_DIER_CC2IE_Pos                                  (2)
#define TIM_DIER_CC2IE_Msk                                  (0x1UL << TIM_DIER_CC2IE_Pos)
#define TIM_DIER_CC2IE                                      TIM_DIER_CC2IE_Msk
#define TIM_DIER_CC3IE_Pos                                  (3)
#define TIM_DIER_CC3IE_Msk                                  (0x1UL << TIM_DIER_CC3IE_Pos)
#define TIM_DIER_CC3IE                                      TIM_DIER_CC3IE_Msk
#define TIM_DIER_CC4IE_Pos                                  (4)
#define TIM_DIER_CC4IE_Msk                                  (0x1UL << TIM_DIER_CC4IE_Pos)
#define TIM_DIER_CC4IE                                      TIM_DIER_CC4IE_Msk
#define TIM_DIER_COMIE_Pos                                  (5)
#define TIM_DIER_COMIE_Msk                                  (0x1UL << TIM_DIER_COMIE_Pos)
#define TIM_DIER_COMIE                                      TIM_DIER_COMIE_Msk
#define TIM_DIER_TIE_Pos                                    (6)
#define TIM_DIER_TIE_Msk                                    (0x1UL << TIM_DIER_TIE_Pos)
#define TIM_DIER_TIE                                        TIM_DIER_TIE_Msk
#define TIM_DIER_BIE_Pos                                    (7)
#define TIM_DIER_BIE_Msk                                    (0x1UL << TIM_DIER_BIE_Pos)
#define TIM_DIER_BIE                                        TIM_DIER_BIE_Msk
#define TIM_DIER_UDE_Pos                                    (8)
#define TIM_DIER_UDE_Msk                                    (0x1UL << TIM_DIER_UDE_Pos)
#define TIM_DIER_UDE                                        TIM_DIER_UDE_Msk
#define TIM_DIER_CC1DE_Pos                                  (9)
#define TIM_DIER_CC1DE_Msk                                  (0x1UL << TIM_DIER_CC1DE_Pos)
#define TIM_DIER_CC1DE                                      TIM_DIER_CC1DE_Msk
#define TIM_DIER_CC2DE_Pos                                  (10)
#define TIM_DIER_CC2DE_Msk                                  (0x1UL << TIM_DIER_CC2DE_Pos)
#define TIM_DIER_CC2DE                                      TIM_DIER_CC2DE_Msk
#define TIM_DIER_CC3DE_Pos                                  (11)
#define TIM_DIER_CC3DE_Msk                                  (0x1UL << TIM_DIER_CC3DE_Pos)
#define TIM_DIER_CC3DE                                      TIM_DIER_CC3DE_Msk
#define TIM_DIER_CC4DE_Pos                                  (12)
#define TIM_DIER_CC4DE_Msk                                  (0x1UL << TIM_DIER_CC4DE_Pos)
#define TIM_DIER_CC4DE                                      TIM_DIER_CC4DE_Msk
#define TIM_DIER_COMDE_Pos                                  (13)
#define TIM_DIER_COMDE_Msk                                  (0x1UL << TIM_DIER_COMDE_Pos)
#define TIM_DIER_COMDE                                      TIM_DIER_COMDE_Msk
#define TIM_DIER_TDE_Pos                                    (14)
#define TIM_DIER_TDE_Msk                                    (0x1UL << TIM_DIER_TDE_Pos)
#define TIM_DIER_TDE                                        TIM_DIER_TDE_Msk

/************************  Bits definition for TIM_SR  ************************/
#define TIM_SR_UIF_Pos                                      (0)
#define TIM_SR_UIF_Msk                                      (0x1UL << TIM_SR_UIF_Pos)
#define TIM_SR_UIF                                          TIM_SR_UIF_Msk
#define TIM_SR_CC1IF_Pos                                    (1)
#define TIM_SR_CC1IF_Msk                                    (0x1UL << TIM_SR_CC1IF_Pos)
#define TIM_SR_CC1IF                                        TIM_SR_CC1IF_Msk
#define TIM_SR_CC2IF_Pos                                    (2)
#define TIM_SR_CC2IF_Msk                                    (0x1UL << TIM_SR_CC2IF_Pos)
#define TIM_SR_CC2IF                                        TIM_SR_CC2IF_Msk
#define TIM_SR_CC3IF_Pos                                    (3)
#define TIM_SR_CC3IF_Msk                                    (0x1UL << TIM_SR_CC3IF_Pos)
#define TIM_SR_CC3IF                                        TIM_SR_CC3IF_Msk
#define TIM_SR_CC4IF_Pos                                    (4)
#define TIM_SR_CC4IF_Msk                                    (0x1UL << TIM_SR_CC4IF_Pos)
#define TIM_SR_CC4IF                                        TIM_SR_CC4IF_Msk
#define TIM_SR_COMIF_Pos                                    (5)
#define TIM_SR_COMIF_Msk                                    (0x1UL << TIM_SR_COMIF_Pos)
#define TIM_SR_COMIF                                        TIM_SR_COMIF_Msk
#define TIM_SR_TIF_Pos                                      (6)
#define TIM_SR_TIF_Msk                                      (0x1UL << TIM_SR_TIF_Pos)
#define TIM_SR_TIF                                          TIM_SR_TIF_Msk
#define TIM_SR_BIF_Pos                                      (7)
#define TIM_SR_BIF_Msk                                      (0x1UL << TIM_SR_BIF_Pos)
#define TIM_SR_BIF                                          TIM_SR_BIF_Msk
#define TIM_SR_B2IF_Pos                                     (8)
#define TIM_SR_B2IF_Msk                                     (0x1UL << TIM_SR_B2IF_Pos)
#define TIM_SR_B2IF                                         TIM_SR_B2IF_Msk
#define TIM_SR_CC1OF_Pos                                    (9)
#define TIM_SR_CC1OF_Msk                                    (0x1UL << TIM_SR_CC1OF_Pos)
#define TIM_SR_CC1OF                                        TIM_SR_CC1OF_Msk
#define TIM_SR_CC2OF_Pos                                    (10)
#define TIM_SR_CC2OF_Msk                                    (0x1UL << TIM_SR_CC2OF_Pos)
#define TIM_SR_CC2OF                                        TIM_SR_CC2OF_Msk
#define TIM_SR_CC3OF_Pos                                    (11)
#define TIM_SR_CC3OF_Msk                                    (0x1UL << TIM_SR_CC3OF_Pos)
#define TIM_SR_CC3OF                                        TIM_SR_CC3OF_Msk
#define TIM_SR_CC4OF_Pos                                    (12)
#define TIM_SR_CC4OF_Msk                                    (0x1UL << TIM_SR_CC4OF_Pos)
#define TIM_SR_CC4OF                                        TIM_SR_CC4OF_Msk
#define TIM_SR_SBIF_Pos                                     (13)
#define TIM_SR_SBIF_Msk                                     (0x1UL << TIM_SR_SBIF_Pos)
#define TIM_SR_SBIF                                         TIM_SR_SBIF_Msk
#define TIM_SR_CC5IF_Pos                                    (16)
#define TIM_SR_CC5IF_Msk                                    (0x1UL << TIM_SR_CC5IF_Pos)
#define TIM_SR_CC5IF                                        TIM_SR_CC5IF_Msk
#define TIM_SR_CC6IF_Pos                                    (17)
#define TIM_SR_CC6IF_Msk                                    (0x1UL << TIM_SR_CC6IF_Pos)
#define TIM_SR_CC6IF                                        TIM_SR_CC6IF_Msk
#define TIM_SR_DMA_Pos                                      (29)
#define TIM_SR_DMA_Msk                                      (0x7UL << TIM_SR_DMA_Pos)
#define TIM_SR_DMA                                          TIM_SR_DMA_Msk
#define TIM_SR_DMA_0                                        (0x1UL << TIM_SR_DMA_Pos)
#define TIM_SR_DMA_1                                        (0x2UL << TIM_SR_DMA_Pos)
#define TIM_SR_DMA_2                                        (0x4UL << TIM_SR_DMA_Pos)

/***********************  Bits definition for TIM_EGR  ************************/
#define TIM_EGR_UG_Pos                                      (0)
#define TIM_EGR_UG_Msk                                      (0x1UL << TIM_EGR_UG_Pos)
#define TIM_EGR_UG                                          TIM_EGR_UG_Msk
#define TIM_EGR_CC1G_Pos                                    (1)
#define TIM_EGR_CC1G_Msk                                    (0x1UL << TIM_EGR_CC1G_Pos)
#define TIM_EGR_CC1G                                        TIM_EGR_CC1G_Msk
#define TIM_EGR_CC2G_Pos                                    (2)
#define TIM_EGR_CC2G_Msk                                    (0x1UL << TIM_EGR_CC2G_Pos)
#define TIM_EGR_CC2G                                        TIM_EGR_CC2G_Msk
#define TIM_EGR_CC3G_Pos                                    (3)
#define TIM_EGR_CC3G_Msk                                    (0x1UL << TIM_EGR_CC3G_Pos)
#define TIM_EGR_CC3G                                        TIM_EGR_CC3G_Msk
#define TIM_EGR_CC4G_Pos                                    (4)
#define TIM_EGR_CC4G_Msk                                    (0x1UL << TIM_EGR_CC4G_Pos)
#define TIM_EGR_CC4G                                        TIM_EGR_CC4G_Msk
#define TIM_EGR_COMG_Pos                                    (5)
#define TIM_EGR_COMG_Msk                                    (0x1UL << TIM_EGR_COMG_Pos)
#define TIM_EGR_COMG                                        TIM_EGR_COMG_Msk
#define TIM_EGR_TG_Pos                                      (6)
#define TIM_EGR_TG_Msk                                      (0x1UL << TIM_EGR_TG_Pos)
#define TIM_EGR_TG                                          TIM_EGR_TG_Msk
#define TIM_EGR_BG_Pos                                      (7)
#define TIM_EGR_BG_Msk                                      (0x1UL << TIM_EGR_BG_Pos)
#define TIM_EGR_BG                                          TIM_EGR_BG_Msk
#define TIM_EGR_B2G_Pos                                     (8)
#define TIM_EGR_B2G_Msk                                     (0x1UL << TIM_EGR_B2G_Pos)
#define TIM_EGR_B2G                                         TIM_EGR_B2G_Msk

/**********************  Bits definition for TIM_CCMR1  ***********************/
#define TIM_CCMR1_CC1S_Pos                                  (0)
#define TIM_CCMR1_CC1S_Msk                                  (0x3UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S                                      TIM_CCMR1_CC1S_Msk
#define TIM_CCMR1_CC1S_0                                    (0x1UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_CC1S_1                                    (0x2UL << TIM_CCMR1_CC1S_Pos)
#define TIM_CCMR1_OC1FE_Pos                                 (2)
#define TIM_CCMR1_OC1FE_Msk                                 (0x1UL << TIM_CCMR1_OC1FE_Pos)
#define TIM_CCMR1_OC1FE                                     TIM_CCMR1_OC1FE_Msk
#define TIM_CCMR1_OC1PE_Pos                                 (3)
#define TIM_CCMR1_OC1PE_Msk                                 (0x1UL << TIM_CCMR1_OC1PE_Pos)
#define TIM_CCMR1_OC1PE                                     TIM_CCMR1_OC1PE_Msk
#define TIM_CCMR1_OC1M_Pos                                  (4)
#define TIM_CCMR1_OC1M_Msk                                  (0x1007UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M                                      TIM_CCMR1_OC1M_Msk
#define TIM_CCMR1_OC1M_0                                    (0x1UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_1                                    (0x2UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_2                                    (0x4UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1M_3                                    (0x1000UL << TIM_CCMR1_OC1M_Pos)
#define TIM_CCMR1_OC1CE_Pos                                 (7)
#define TIM_CCMR1_OC1CE_Msk                                 (0x1UL << TIM_CCMR1_OC1CE_Pos)
#define TIM_CCMR1_OC1CE                                     TIM_CCMR1_OC1CE_Msk
#define TIM_CCMR1_CC2S_Pos                                  (8)
#define TIM_CCMR1_CC2S_Msk                                  (0x3UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S                                      TIM_CCMR1_CC2S_Msk
#define TIM_CCMR1_CC2S_0                                    (0x1UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_CC2S_1                                    (0x2UL << TIM_CCMR1_CC2S_Pos)
#define TIM_CCMR1_OC2FE_Pos                                 (10)
#define TIM_CCMR1_OC2FE_Msk                                 (0x1UL << TIM_CCMR1_OC2FE_Pos)
#define TIM_CCMR1_OC2FE                                     TIM_CCMR1_OC2FE_Msk
#define TIM_CCMR1_OC2PE_Pos                                 (11)
#define TIM_CCMR1_OC2PE_Msk                                 (0x1UL << TIM_CCMR1_OC2PE_Pos)
#define TIM_CCMR1_OC2PE                                     TIM_CCMR1_OC2PE_Msk
#define TIM_CCMR1_OC2M_Pos                                  (12)
#define TIM_CCMR1_OC2M_Msk                                  (0x1007UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M                                      TIM_CCMR1_OC2M_Msk
#define TIM_CCMR1_OC2M_0                                    (0x1UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_1                                    (0x2UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_2                                    (0x4UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2M_3                                    (0x1000UL << TIM_CCMR1_OC2M_Pos)
#define TIM_CCMR1_OC2CE_Pos                                 (15)
#define TIM_CCMR1_OC2CE_Msk                                 (0x1UL << TIM_CCMR1_OC2CE_Pos)
#define TIM_CCMR1_OC2CE                                     TIM_CCMR1_OC2CE_Msk
#define TIM_CCMR1_IC1PSC_Pos                                (2)
#define TIM_CCMR1_IC1PSC_Msk                                (0x3UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC                                    TIM_CCMR1_IC1PSC_Msk
#define TIM_CCMR1_IC1PSC_0                                  (0x1UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1PSC_1                                  (0x2UL << TIM_CCMR1_IC1PSC_Pos)
#define TIM_CCMR1_IC1F_Pos                                  (4)
#define TIM_CCMR1_IC1F_Msk                                  (0xfUL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F                                      TIM_CCMR1_IC1F_Msk
#define TIM_CCMR1_IC1F_0                                    (0x1UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_1                                    (0x2UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_2                                    (0x4UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC1F_3                                    (0x8UL << TIM_CCMR1_IC1F_Pos)
#define TIM_CCMR1_IC2PSC_Pos                                (10)
#define TIM_CCMR1_IC2PSC_Msk                                (0x3UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC                                    TIM_CCMR1_IC2PSC_Msk
#define TIM_CCMR1_IC2PSC_0                                  (0x1UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2PSC_1                                  (0x2UL << TIM_CCMR1_IC2PSC_Pos)
#define TIM_CCMR1_IC2F_Pos                                  (12)
#define TIM_CCMR1_IC2F_Msk                                  (0xfUL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F                                      TIM_CCMR1_IC2F_Msk
#define TIM_CCMR1_IC2F_0                                    (0x1UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_1                                    (0x2UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_2                                    (0x4UL << TIM_CCMR1_IC2F_Pos)
#define TIM_CCMR1_IC2F_3                                    (0x8UL << TIM_CCMR1_IC2F_Pos)

/**********************  Bits definition for TIM_CCMR2  ***********************/
#define TIM_CCMR2_CC3S_Pos                                  (0)
#define TIM_CCMR2_CC3S_Msk                                  (0x3UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S                                      TIM_CCMR2_CC3S_Msk
#define TIM_CCMR2_CC3S_0                                    (0x1UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_CC3S_1                                    (0x2UL << TIM_CCMR2_CC3S_Pos)
#define TIM_CCMR2_OC3FE_Pos                                 (2)
#define TIM_CCMR2_OC3FE_Msk                                 (0x1UL << TIM_CCMR2_OC3FE_Pos)
#define TIM_CCMR2_OC3FE                                     TIM_CCMR2_OC3FE_Msk
#define TIM_CCMR2_OC3PE_Pos                                 (3)
#define TIM_CCMR2_OC3PE_Msk                                 (0x1UL << TIM_CCMR2_OC3PE_Pos)
#define TIM_CCMR2_OC3PE                                     TIM_CCMR2_OC3PE_Msk
#define TIM_CCMR2_OC3M_Pos                                  (4)
#define TIM_CCMR2_OC3M_Msk                                  (0x1007UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M                                      TIM_CCMR2_OC3M_Msk
#define TIM_CCMR2_OC3M_0                                    (0x1UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_1                                    (0x2UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_2                                    (0x4UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3M_3                                    (0x1000UL << TIM_CCMR2_OC3M_Pos)
#define TIM_CCMR2_OC3CE_Pos                                 (7)
#define TIM_CCMR2_OC3CE_Msk                                 (0x1UL << TIM_CCMR2_OC3CE_Pos)
#define TIM_CCMR2_OC3CE                                     TIM_CCMR2_OC3CE_Msk
#define TIM_CCMR2_CC4S_Pos                                  (8)
#define TIM_CCMR2_CC4S_Msk                                  (0x3UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S                                      TIM_CCMR2_CC4S_Msk
#define TIM_CCMR2_CC4S_0                                    (0x1UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_CC4S_1                                    (0x2UL << TIM_CCMR2_CC4S_Pos)
#define TIM_CCMR2_OC4FE_Pos                                 (10)
#define TIM_CCMR2_OC4FE_Msk                                 (0x1UL << TIM_CCMR2_OC4FE_Pos)
#define TIM_CCMR2_OC4FE                                     TIM_CCMR2_OC4FE_Msk
#define TIM_CCMR2_OC4PE_Pos                                 (11)
#define TIM_CCMR2_OC4PE_Msk                                 (0x1UL << TIM_CCMR2_OC4PE_Pos)
#define TIM_CCMR2_OC4PE                                     TIM_CCMR2_OC4PE_Msk
#define TIM_CCMR2_OC4M_Pos                                  (12)
#define TIM_CCMR2_OC4M_Msk                                  (0x1007UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M                                      TIM_CCMR2_OC4M_Msk
#define TIM_CCMR2_OC4M_0                                    (0x1UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_1                                    (0x2UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_2                                    (0x4UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4M_3                                    (0x1000UL << TIM_CCMR2_OC4M_Pos)
#define TIM_CCMR2_OC4CE_Pos                                 (15)
#define TIM_CCMR2_OC4CE_Msk                                 (0x1UL << TIM_CCMR2_OC4CE_Pos)
#define TIM_CCMR2_OC4CE                                     TIM_CCMR2_OC4CE_Msk
#define TIM_CCMR2_IC3PSC_Pos                                (2)
#define TIM_CCMR2_IC3PSC_Msk                                (0x3UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC                                    TIM_CCMR2_IC3PSC_Msk
#define TIM_CCMR2_IC3PSC_0                                  (0x1UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3PSC_1                                  (0x2UL << TIM_CCMR2_IC3PSC_Pos)
#define TIM_CCMR2_IC3F_Pos                                  (4)
#define TIM_CCMR2_IC3F_Msk                                  (0xfUL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F                                      TIM_CCMR2_IC3F_Msk
#define TIM_CCMR2_IC3F_0                                    (0x1UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_1                                    (0x2UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_2                                    (0x4UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC3F_3                                    (0x8UL << TIM_CCMR2_IC3F_Pos)
#define TIM_CCMR2_IC4PSC_Pos                                (10)
#define TIM_CCMR2_IC4PSC_Msk                                (0x3UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC                                    TIM_CCMR2_IC4PSC_Msk
#define TIM_CCMR2_IC4PSC_0                                  (0x1UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4PSC_1                                  (0x2UL << TIM_CCMR2_IC4PSC_Pos)
#define TIM_CCMR2_IC4F_Pos                                  (12)
#define TIM_CCMR2_IC4F_Msk                                  (0xfUL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F                                      TIM_CCMR2_IC4F_Msk
#define TIM_CCMR2_IC4F_0                                    (0x1UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_1                                    (0x2UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_2                                    (0x4UL << TIM_CCMR2_IC4F_Pos)
#define TIM_CCMR2_IC4F_3                                    (0x8UL << TIM_CCMR2_IC4F_Pos)

/***********************  Bits definition for TIM_CCER  ***********************/
#define TIM_CCER_CC1E_Pos                                   (0)
#define TIM_CCER_CC1E_Msk                                   (0x1UL << TIM_CCER_CC1E_Pos)
#define TIM_CCER_CC1E                                       TIM_CCER_CC1E_Msk
#define TIM_CCER_CC1P_Pos                                   (1)
#define TIM_CCER_CC1P_Msk                                   (0x1UL << TIM_CCER_CC1P_Pos)
#define TIM_CCER_CC1P                                       TIM_CCER_CC1P_Msk
#define TIM_CCER_CC1NE_Pos                                  (2)
#define TIM_CCER_CC1NE_Msk                                  (0x1UL << TIM_CCER_CC1NE_Pos)
#define TIM_CCER_CC1NE                                      TIM_CCER_CC1NE_Msk
#define TIM_CCER_CC1NP_Pos                                  (3)
#define TIM_CCER_CC1NP_Msk                                  (0x1UL << TIM_CCER_CC1NP_Pos)
#define TIM_CCER_CC1NP                                      TIM_CCER_CC1NP_Msk
#define TIM_CCER_CC2E_Pos                                   (4)
#define TIM_CCER_CC2E_Msk                                   (0x1UL << TIM_CCER_CC2E_Pos)
#define TIM_CCER_CC2E                                       TIM_CCER_CC2E_Msk
#define TIM_CCER_CC2P_Pos                                   (5)
#define TIM_CCER_CC2P_Msk                                   (0x1UL << TIM_CCER_CC2P_Pos)
#define TIM_CCER_CC2P                                       TIM_CCER_CC2P_Msk
#define TIM_CCER_CC2NE_Pos                                  (6)
#define TIM_CCER_CC2NE_Msk                                  (0x1UL << TIM_CCER_CC2NE_Pos)
#define TIM_CCER_CC2NE                                      TIM_CCER_CC2NE_Msk
#define TIM_CCER_CC2NP_Pos                                  (7)
#define TIM_CCER_CC2NP_Msk                                  (0x1UL << TIM_CCER_CC2NP_Pos)
#define TIM_CCER_CC2NP                                      TIM_CCER_CC2NP_Msk
#define TIM_CCER_CC3E_Pos                                   (8)
#define TIM_CCER_CC3E_Msk                                   (0x1UL << TIM_CCER_CC3E_Pos)
#define TIM_CCER_CC3E                                       TIM_CCER_CC3E_Msk
#define TIM_CCER_CC3P_Pos                                   (9)
#define TIM_CCER_CC3P_Msk                                   (0x1UL << TIM_CCER_CC3P_Pos)
#define TIM_CCER_CC3P                                       TIM_CCER_CC3P_Msk
#define TIM_CCER_CC3NE_Pos                                  (10)
#define TIM_CCER_CC3NE_Msk                                  (0x1UL << TIM_CCER_CC3NE_Pos)
#define TIM_CCER_CC3NE                                      TIM_CCER_CC3NE_Msk
#define TIM_CCER_CC3NP_Pos                                  (11)
#define TIM_CCER_CC3NP_Msk                                  (0x1UL << TIM_CCER_CC3NP_Pos)
#define TIM_CCER_CC3NP                                      TIM_CCER_CC3NP_Msk
#define TIM_CCER_CC4E_Pos                                   (12)
#define TIM_CCER_CC4E_Msk                                   (0x1UL << TIM_CCER_CC4E_Pos)
#define TIM_CCER_CC4E                                       TIM_CCER_CC4E_Msk
#define TIM_CCER_CC4P_Pos                                   (13)
#define TIM_CCER_CC4P_Msk                                   (0x1UL << TIM_CCER_CC4P_Pos)
#define TIM_CCER_CC4P                                       TIM_CCER_CC4P_Msk
#define TIM_CCER_CC4NP_Pos                                  (15)
#define TIM_CCER_CC4NP_Msk                                  (0x1UL << TIM_CCER_CC4NP_Pos)
#define TIM_CCER_CC4NP                                      TIM_CCER_CC4NP_Msk
#define TIM_CCER_CC5E_Pos                                   (16)
#define TIM_CCER_CC5E_Msk                                   (0x1UL << TIM_CCER_CC5E_Pos)
#define TIM_CCER_CC5E                                       TIM_CCER_CC5E_Msk
#define TIM_CCER_CC5P_Pos                                   (17)
#define TIM_CCER_CC5P_Msk                                   (0x1UL << TIM_CCER_CC5P_Pos)
#define TIM_CCER_CC5P                                       TIM_CCER_CC5P_Msk
#define TIM_CCER_CC6E_Pos                                   (20)
#define TIM_CCER_CC6E_Msk                                   (0x1UL << TIM_CCER_CC6E_Pos)
#define TIM_CCER_CC6E                                       TIM_CCER_CC6E_Msk
#define TIM_CCER_CC6P_Pos                                   (21)
#define TIM_CCER_CC6P_Msk                                   (0x1UL << TIM_CCER_CC6P_Pos)
#define TIM_CCER_CC6P                                       TIM_CCER_CC6P_Msk

/***********************  Bits definition for TIM_CNT  ************************/
#define TIM_CNT_CNT_Pos                                     (0)
#define TIM_CNT_CNT_Msk                                     (0xffffffffUL << TIM_CNT_CNT_Pos)
#define TIM_CNT_CNT                                         TIM_CNT_CNT_Msk
#define TIM_CNT_UIFCPY_Pos                                  (31)
#define TIM_CNT_UIFCPY_Msk                                  (0x1UL << TIM_CNT_UIFCPY_Pos)
#define TIM_CNT_UIFCPY                                      TIM_CNT_UIFCPY_Msk

/***********************  Bits definition for TIM_PSC  ************************/
#define TIM_PSC_PSC_Pos                                     (0)
#define TIM_PSC_PSC_Msk                                     (0xffffUL << TIM_PSC_PSC_Pos)
#define TIM_PSC_PSC                                         TIM_PSC_PSC_Msk

/***********************  Bits definition for TIM_ARR  ************************/
#define TIM_ARR_ARR_Pos                                     (0)
#define TIM_ARR_ARR_Msk                                     (0xffffffffUL << TIM_ARR_ARR_Pos)
#define TIM_ARR_ARR                                         TIM_ARR_ARR_Msk

/***********************  Bits definition for TIM_RCR  ************************/
#define TIM_RCR_REP_Pos                                     (0)
#define TIM_RCR_REP_Msk                                     (0xffffUL << TIM_RCR_REP_Pos)
#define TIM_RCR_REP                                         TIM_RCR_REP_Msk

/***********************  Bits definition for TIM_CCR1  ***********************/
#define TIM_CCR1_CCR1_Pos                                   (0)
#define TIM_CCR1_CCR1_Msk                                   (0xffffUL << TIM_CCR1_CCR1_Pos)
#define TIM_CCR1_CCR1                                       TIM_CCR1_CCR1_Msk

/***********************  Bits definition for TIM_CCR2  ***********************/
#define TIM_CCR2_CCR2_Pos                                   (0)
#define TIM_CCR2_CCR2_Msk                                   (0xffffUL << TIM_CCR2_CCR2_Pos)
#define TIM_CCR2_CCR2                                       TIM_CCR2_CCR2_Msk

/***********************  Bits definition for TIM_CCR3  ***********************/
#define TIM_CCR3_CCR3_Pos                                   (0)
#define TIM_CCR3_CCR3_Msk                                   (0xffffUL << TIM_CCR3_CCR3_Pos)
#define TIM_CCR3_CCR3                                       TIM_CCR3_CCR3_Msk

/***********************  Bits definition for TIM_CCR4  ***********************/
#define TIM_CCR4_CCR4_Pos                                   (0)
#define TIM_CCR4_CCR4_Msk                                   (0xffffUL << TIM_CCR4_CCR4_Pos)
#define TIM_CCR4_CCR4                                       TIM_CCR4_CCR4_Msk

/***********************  Bits definition for TIM_BDTR  ***********************/
#define TIM_BDTR_DTG_Pos                                    (0)
#define TIM_BDTR_DTG_Msk                                    (0xffUL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG                                        TIM_BDTR_DTG_Msk
#define TIM_BDTR_DTG_0                                      (0x1UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_1                                      (0x2UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_2                                      (0x4UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_3                                      (0x8UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_4                                      (0x10UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_5                                      (0x20UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_6                                      (0x40UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_DTG_7                                      (0x80UL << TIM_BDTR_DTG_Pos)
#define TIM_BDTR_LOCK_Pos                                   (8)
#define TIM_BDTR_LOCK_Msk                                   (0x3UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK                                       TIM_BDTR_LOCK_Msk
#define TIM_BDTR_LOCK_0                                     (0x1UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_LOCK_1                                     (0x2UL << TIM_BDTR_LOCK_Pos)
#define TIM_BDTR_OSSI_Pos                                   (10)
#define TIM_BDTR_OSSI_Msk                                   (0x1UL << TIM_BDTR_OSSI_Pos)
#define TIM_BDTR_OSSI                                       TIM_BDTR_OSSI_Msk
#define TIM_BDTR_OSSR_Pos                                   (11)
#define TIM_BDTR_OSSR_Msk                                   (0x1UL << TIM_BDTR_OSSR_Pos)
#define TIM_BDTR_OSSR                                       TIM_BDTR_OSSR_Msk
#define TIM_BDTR_BKE_Pos                                    (12)
#define TIM_BDTR_BKE_Msk                                    (0x1UL << TIM_BDTR_BKE_Pos)
#define TIM_BDTR_BKE                                        TIM_BDTR_BKE_Msk
#define TIM_BDTR_BKP_Pos                                    (13)
#define TIM_BDTR_BKP_Msk                                    (0x1UL << TIM_BDTR_BKP_Pos)
#define TIM_BDTR_BKP                                        TIM_BDTR_BKP_Msk
#define TIM_BDTR_AOE_Pos                                    (14)
#define TIM_BDTR_AOE_Msk                                    (0x1UL << TIM_BDTR_AOE_Pos)
#define TIM_BDTR_AOE                                        TIM_BDTR_AOE_Msk
#define TIM_BDTR_MOE_Pos                                    (15)
#define TIM_BDTR_MOE_Msk                                    (0x1UL << TIM_BDTR_MOE_Pos)
#define TIM_BDTR_MOE                                        TIM_BDTR_MOE_Msk
#define TIM_BDTR_BKF_Pos                                    (16)
#define TIM_BDTR_BKF_Msk                                    (0xfUL << TIM_BDTR_BKF_Pos)
#define TIM_BDTR_BKF                                        TIM_BDTR_BKF_Msk
#define TIM_BDTR_BKF_0                                      (0x1UL << TIM_BDTR_BKF_Pos)
#define TIM_BDTR_BKF_1                                      (0x2UL << TIM_BDTR_BKF_Pos)
#define TIM_BDTR_BKF_2                                      (0x4UL << TIM_BDTR_BKF_Pos)
#define TIM_BDTR_BKF_3                                      (0x8UL << TIM_BDTR_BKF_Pos)
#define TIM_BDTR_BK2F_Pos                                   (20)
#define TIM_BDTR_BK2F_Msk                                   (0xfUL << TIM_BDTR_BK2F_Pos)
#define TIM_BDTR_BK2F                                       TIM_BDTR_BK2F_Msk
#define TIM_BDTR_BK2F_0                                     (0x1UL << TIM_BDTR_BK2F_Pos)
#define TIM_BDTR_BK2F_1                                     (0x2UL << TIM_BDTR_BK2F_Pos)
#define TIM_BDTR_BK2F_2                                     (0x4UL << TIM_BDTR_BK2F_Pos)
#define TIM_BDTR_BK2F_3                                     (0x8UL << TIM_BDTR_BK2F_Pos)
#define TIM_BDTR_BK2E_Pos                                   (24)
#define TIM_BDTR_BK2E_Msk                                   (0x1UL << TIM_BDTR_BK2E_Pos)
#define TIM_BDTR_BK2E                                       TIM_BDTR_BK2E_Msk
#define TIM_BDTR_BK2P_Pos                                   (25)
#define TIM_BDTR_BK2P_Msk                                   (0x1UL << TIM_BDTR_BK2P_Pos)
#define TIM_BDTR_BK2P                                       TIM_BDTR_BK2P_Msk
#define TIM_BDTR_BKDSRM_Pos                                 (26)
#define TIM_BDTR_BKDSRM_Msk                                 (0x1UL << TIM_BDTR_BKDSRM_Pos)
#define TIM_BDTR_BKDSRM                                     TIM_BDTR_BKDSRM_Msk
#define TIM_BDTR_BK2DSRM_Pos                                (27)
#define TIM_BDTR_BK2DSRM_Msk                                (0x1UL << TIM_BDTR_BK2DSRM_Pos)
#define TIM_BDTR_BK2DSRM                                    TIM_BDTR_BK2DSRM_Msk
#define TIM_BDTR_BKBID_Pos                                  (28)
#define TIM_BDTR_BKBID_Msk                                  (0x1UL << TIM_BDTR_BKBID_Pos)
#define TIM_BDTR_BKBID                                      TIM_BDTR_BKBID_Msk
#define TIM_BDTR_BK2BID_Pos                                 (29)
#define TIM_BDTR_BK2BID_Msk                                 (0x1UL << TIM_BDTR_BK2BID_Pos)
#define TIM_BDTR_BK2BID                                     TIM_BDTR_BK2BID_Msk

/***********************  Bits definition for TIM_DCR  ************************/
#define TIM_DCR_DBA_Pos                                     (0)
#define TIM_DCR_DBA_Msk                                     (0x1fUL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA                                         TIM_DCR_DBA_Msk
#define TIM_DCR_DBA_0                                       (0x1UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_1                                       (0x2UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_2                                       (0x4UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_3                                       (0x8UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBA_4                                       (0x10UL << TIM_DCR_DBA_Pos)
#define TIM_DCR_DBL_Pos                                     (8)
#define TIM_DCR_DBL_Msk                                     (0x1fUL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL                                         TIM_DCR_DBL_Msk
#define TIM_DCR_DBL_0                                       (0x1UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_1                                       (0x2UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_2                                       (0x4UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_3                                       (0x8UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DBL_4                                       (0x10UL << TIM_DCR_DBL_Pos)
#define TIM_DCR_DMARST_Pos                                  (16)
#define TIM_DCR_DMARST_Msk                                  (0x1UL << TIM_DCR_DMARST_Pos)
#define TIM_DCR_DMARST                                      TIM_DCR_DMARST_Msk

/***********************  Bits definition for TIM_DMAR  ***********************/
#define TIM_DMAR_DMAB_Pos                                   (0)
#define TIM_DMAR_DMAB_Msk                                   (0xffffUL << TIM_DMAR_DMAB_Pos)
#define TIM_DMAR_DMAB                                       TIM_DMAR_DMAB_Msk

/***********************  Bits definition for TIM1_OR1  ***********************/
#define TIM1_OR1_OCREF_CLR_Pos                              (0)
#define TIM1_OR1_OCREF_CLR_Msk                              (0x1UL << TIM1_OR1_OCREF_CLR_Pos)
#define TIM1_OR1_OCREF_CLR                                  TIM1_OR1_OCREF_CLR_Msk

/**********************  Bits definition for TIM_CCMR3  ***********************/
#define TIM_CCMR3_OC5FE_Pos                                 (2)
#define TIM_CCMR3_OC5FE_Msk                                 (0x1UL << TIM_CCMR3_OC5FE_Pos)
#define TIM_CCMR3_OC5FE                                     TIM_CCMR3_OC5FE_Msk
#define TIM_CCMR3_OC5PE_Pos                                 (3)
#define TIM_CCMR3_OC5PE_Msk                                 (0x1UL << TIM_CCMR3_OC5PE_Pos)
#define TIM_CCMR3_OC5PE                                     TIM_CCMR3_OC5PE_Msk
#define TIM_CCMR3_OC5M_Pos                                  (4)
#define TIM_CCMR3_OC5M_Msk                                  (0x1007UL << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5M                                      TIM_CCMR3_OC5M_Msk
#define TIM_CCMR3_OC5M_0                                    (0x1UL << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5M_1                                    (0x2UL << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5M_2                                    (0x4UL << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5M_3                                    (0x1000UL << TIM_CCMR3_OC5M_Pos)
#define TIM_CCMR3_OC5CE_Pos                                 (7)
#define TIM_CCMR3_OC5CE_Msk                                 (0x1UL << TIM_CCMR3_OC5CE_Pos)
#define TIM_CCMR3_OC5CE                                     TIM_CCMR3_OC5CE_Msk
#define TIM_CCMR3_OC6FE_Pos                                 (10)
#define TIM_CCMR3_OC6FE_Msk                                 (0x1UL << TIM_CCMR3_OC6FE_Pos)
#define TIM_CCMR3_OC6FE                                     TIM_CCMR3_OC6FE_Msk
#define TIM_CCMR3_OC6PE_Pos                                 (11)
#define TIM_CCMR3_OC6PE_Msk                                 (0x1UL << TIM_CCMR3_OC6PE_Pos)
#define TIM_CCMR3_OC6PE                                     TIM_CCMR3_OC6PE_Msk
#define TIM_CCMR3_OC6M_Pos                                  (12)
#define TIM_CCMR3_OC6M_Msk                                  (0x1007UL << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6M                                      TIM_CCMR3_OC6M_Msk
#define TIM_CCMR3_OC6M_0                                    (0x1UL << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6M_1                                    (0x2UL << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6M_2                                    (0x4UL << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6M_3                                    (0x1000UL << TIM_CCMR3_OC6M_Pos)
#define TIM_CCMR3_OC6CE_Pos                                 (15)
#define TIM_CCMR3_OC6CE_Msk                                 (0x1UL << TIM_CCMR3_OC6CE_Pos)
#define TIM_CCMR3_OC6CE                                     TIM_CCMR3_OC6CE_Msk

/***********************  Bits definition for TIM_CCR5  ***********************/
#define TIM_CCR5_CCR5_Pos                                   (0)
#define TIM_CCR5_CCR5_Msk                                   (0xffffffffUL << TIM_CCR5_CCR5_Pos)
#define TIM_CCR5_CCR5                                       TIM_CCR5_CCR5_Msk
#define TIM_CCR5_GC5C1_Pos                                  (29)
#define TIM_CCR5_GC5C1_Msk                                  (0x1UL << TIM_CCR5_GC5C1_Pos)
#define TIM_CCR5_GC5C1                                      TIM_CCR5_GC5C1_Msk
#define TIM_CCR5_GC5C2_Pos                                  (30)
#define TIM_CCR5_GC5C2_Msk                                  (0x1UL << TIM_CCR5_GC5C2_Pos)
#define TIM_CCR5_GC5C2                                      TIM_CCR5_GC5C2_Msk
#define TIM_CCR5_GC5C3_Pos                                  (31)
#define TIM_CCR5_GC5C3_Msk                                  (0x1UL << TIM_CCR5_GC5C3_Pos)
#define TIM_CCR5_GC5C3                                      TIM_CCR5_GC5C3_Msk

/***********************  Bits definition for TIM_CCR6  ***********************/
#define TIM_CCR6_CCR6_Pos                                   (0)
#define TIM_CCR6_CCR6_Msk                                   (0xffffUL << TIM_CCR6_CCR6_Pos)
#define TIM_CCR6_CCR6                                       TIM_CCR6_CCR6_Msk

/***********************  Bits definition for TIM1_AF1  ***********************/
#define TIM1_AF1_BKINE_Pos                                  (0)
#define TIM1_AF1_BKINE_Msk                                  (0x1UL << TIM1_AF1_BKINE_Pos)
#define TIM1_AF1_BKINE                                      TIM1_AF1_BKINE_Msk
#define TIM1_AF1_BKCMP1E_Pos                                (1)
#define TIM1_AF1_BKCMP1E_Msk                                (0x1UL << TIM1_AF1_BKCMP1E_Pos)
#define TIM1_AF1_BKCMP1E                                    TIM1_AF1_BKCMP1E_Msk
#define TIM1_AF1_BKCMP2E_Pos                                (2)
#define TIM1_AF1_BKCMP2E_Msk                                (0x1UL << TIM1_AF1_BKCMP2E_Pos)
#define TIM1_AF1_BKCMP2E                                    TIM1_AF1_BKCMP2E_Msk
#define TIM1_AF1_BKCMP3E_Pos                                (3)
#define TIM1_AF1_BKCMP3E_Msk                                (0x1UL << TIM1_AF1_BKCMP3E_Pos)
#define TIM1_AF1_BKCMP3E                                    TIM1_AF1_BKCMP3E_Msk
#define TIM1_AF1_BKINP_Pos                                  (9)
#define TIM1_AF1_BKINP_Msk                                  (0x1UL << TIM1_AF1_BKINP_Pos)
#define TIM1_AF1_BKINP                                      TIM1_AF1_BKINP_Msk
#define TIM1_AF1_BKCMP1P_Pos                                (10)
#define TIM1_AF1_BKCMP1P_Msk                                (0x1UL << TIM1_AF1_BKCMP1P_Pos)
#define TIM1_AF1_BKCMP1P                                    TIM1_AF1_BKCMP1P_Msk
#define TIM1_AF1_BKCMP2P_Pos                                (11)
#define TIM1_AF1_BKCMP2P_Msk                                (0x1UL << TIM1_AF1_BKCMP2P_Pos)
#define TIM1_AF1_BKCMP2P                                    TIM1_AF1_BKCMP2P_Msk
#define TIM1_AF1_BKCMP3P_Pos                                (12)
#define TIM1_AF1_BKCMP3P_Msk                                (0x1UL << TIM1_AF1_BKCMP3P_Pos)
#define TIM1_AF1_BKCMP3P                                    TIM1_AF1_BKCMP3P_Msk
#define TIM1_AF1_ETRSEL_Pos                                 (14)
#define TIM1_AF1_ETRSEL_Msk                                 (0xfUL << TIM1_AF1_ETRSEL_Pos)
#define TIM1_AF1_ETRSEL                                     TIM1_AF1_ETRSEL_Msk
#define TIM1_AF1_ETRSEL_0                                   (0x1UL << TIM1_AF1_ETRSEL_Pos)
#define TIM1_AF1_ETRSEL_1                                   (0x2UL << TIM1_AF1_ETRSEL_Pos)
#define TIM1_AF1_ETRSEL_2                                   (0x4UL << TIM1_AF1_ETRSEL_Pos)
#define TIM1_AF1_ETRSEL_3                                   (0x8UL << TIM1_AF1_ETRSEL_Pos)

/***********************  Bits definition for TIM1_AF2  ***********************/
#define TIM1_AF2_BK2INE_Pos                                 (0)
#define TIM1_AF2_BK2INE_Msk                                 (0x1UL << TIM1_AF2_BK2INE_Pos)
#define TIM1_AF2_BK2INE                                     TIM1_AF2_BK2INE_Msk
#define TIM1_AF2_BK2CMP1E_Pos                               (1)
#define TIM1_AF2_BK2CMP1E_Msk                               (0x1UL << TIM1_AF2_BK2CMP1E_Pos)
#define TIM1_AF2_BK2CMP1E                                   TIM1_AF2_BK2CMP1E_Msk
#define TIM1_AF2_BK2CMP2E_Pos                               (2)
#define TIM1_AF2_BK2CMP2E_Msk                               (0x1UL << TIM1_AF2_BK2CMP2E_Pos)
#define TIM1_AF2_BK2CMP2E                                   TIM1_AF2_BK2CMP2E_Msk
#define TIM1_AF2_BK2CMP3E_Pos                               (3)
#define TIM1_AF2_BK2CMP3E_Msk                               (0x1UL << TIM1_AF2_BK2CMP3E_Pos)
#define TIM1_AF2_BK2CMP3E                                   TIM1_AF2_BK2CMP3E_Msk
#define TIM1_AF2_BK2INP_Pos                                 (9)
#define TIM1_AF2_BK2INP_Msk                                 (0x1UL << TIM1_AF2_BK2INP_Pos)
#define TIM1_AF2_BK2INP                                     TIM1_AF2_BK2INP_Msk
#define TIM1_AF2_BK2CMP1P_Pos                               (10)
#define TIM1_AF2_BK2CMP1P_Msk                               (0x1UL << TIM1_AF2_BK2CMP1P_Pos)
#define TIM1_AF2_BK2CMP1P                                   TIM1_AF2_BK2CMP1P_Msk
#define TIM1_AF2_BK2CMP2P_Pos                               (11)
#define TIM1_AF2_BK2CMP2P_Msk                               (0x1UL << TIM1_AF2_BK2CMP2P_Pos)
#define TIM1_AF2_BK2CMP2P                                   TIM1_AF2_BK2CMP2P_Msk
#define TIM1_AF2_BK2CMP3P_Pos                               (12)
#define TIM1_AF2_BK2CMP3P_Msk                               (0x1UL << TIM1_AF2_BK2CMP3P_Pos)
#define TIM1_AF2_BK2CMP3P                                   TIM1_AF2_BK2CMP3P_Msk

/**********************  Bits definition for TIM_TISEL  ***********************/
#define TIM_TISEL_TI1SEL_Pos                                (0)
#define TIM_TISEL_TI1SEL_Msk                                (0xfUL << TIM_TISEL_TI1SEL_Pos)
#define TIM_TISEL_TI1SEL                                    TIM_TISEL_TI1SEL_Msk
#define TIM_TISEL_TI1SEL_0                                  (0x1UL << TIM_TISEL_TI1SEL_Pos)
#define TIM_TISEL_TI1SEL_1                                  (0x2UL << TIM_TISEL_TI1SEL_Pos)
#define TIM_TISEL_TI1SEL_2                                  (0x4UL << TIM_TISEL_TI1SEL_Pos)
#define TIM_TISEL_TI1SEL_3                                  (0x8UL << TIM_TISEL_TI1SEL_Pos)
#define TIM_TISEL_TI2SEL_Pos                                (8)
#define TIM_TISEL_TI2SEL_Msk                                (0xfUL << TIM_TISEL_TI2SEL_Pos)
#define TIM_TISEL_TI2SEL                                    TIM_TISEL_TI2SEL_Msk
#define TIM_TISEL_TI2SEL_0                                  (0x1UL << TIM_TISEL_TI2SEL_Pos)
#define TIM_TISEL_TI2SEL_1                                  (0x2UL << TIM_TISEL_TI2SEL_Pos)
#define TIM_TISEL_TI2SEL_2                                  (0x4UL << TIM_TISEL_TI2SEL_Pos)
#define TIM_TISEL_TI2SEL_3                                  (0x8UL << TIM_TISEL_TI2SEL_Pos)
#define TIM_TISEL_TI3SEL_Pos                                (16)
#define TIM_TISEL_TI3SEL_Msk                                (0xfUL << TIM_TISEL_TI3SEL_Pos)
#define TIM_TISEL_TI3SEL                                    TIM_TISEL_TI3SEL_Msk
#define TIM_TISEL_TI3SEL_0                                  (0x1UL << TIM_TISEL_TI3SEL_Pos)
#define TIM_TISEL_TI3SEL_1                                  (0x2UL << TIM_TISEL_TI3SEL_Pos)
#define TIM_TISEL_TI3SEL_2                                  (0x4UL << TIM_TISEL_TI3SEL_Pos)
#define TIM_TISEL_TI3SEL_3                                  (0x8UL << TIM_TISEL_TI3SEL_Pos)
#define TIM_TISEL_TI4SEL_Pos                                (24)
#define TIM_TISEL_TI4SEL_Msk                                (0xfUL << TIM_TISEL_TI4SEL_Pos)
#define TIM_TISEL_TI4SEL                                    TIM_TISEL_TI4SEL_Msk
#define TIM_TISEL_TI4SEL_0                                  (0x1UL << TIM_TISEL_TI4SEL_Pos)
#define TIM_TISEL_TI4SEL_1                                  (0x2UL << TIM_TISEL_TI4SEL_Pos)
#define TIM_TISEL_TI4SEL_2                                  (0x4UL << TIM_TISEL_TI4SEL_Pos)
#define TIM_TISEL_TI4SEL_3                                  (0x8UL << TIM_TISEL_TI4SEL_Pos)

/******************************************************************************/
/*                                                                            */
/*                                  TIMR                                      */
/*                                                                            */
/******************************************************************************/

/***********************  Bits definition for TIMR_LC  ************************/
#define TIMR_LC_CNT_Pos                                     (0)
#define TIMR_LC_CNT_Msk                                     (0xffffffffUL << TIMR_LC_CNT_Pos)
#define TIMR_LC_CNT                                         TIMR_LC_CNT_Msk

/***********************  Bits definition for TIMR_CV  ************************/
#define TIMR_CV_CNT_Pos                                     (0)
#define TIMR_CV_CNT_Msk                                     (0xffffffffUL << TIMR_CV_CNT_Pos)
#define TIMR_CV_CNT                                         TIMR_CV_CNT_Msk

/***********************  Bits definition for TIMR_CR  ************************/
#define TIMR_CR_EN_Pos                                      (0)
#define TIMR_CR_EN_Msk                                      (0x1UL << TIMR_CR_EN_Pos)
#define TIMR_CR_EN                                          TIMR_CR_EN_Msk
#define TIMR_CR_MODE_Pos                                    (1)
#define TIMR_CR_MODE_Msk                                    (0x1UL << TIMR_CR_MODE_Pos)
#define TIMR_CR_MODE                                        TIMR_CR_MODE_Msk
#define TIMR_CR_IM_Pos                                      (2)
#define TIMR_CR_IM_Msk                                      (0x1UL << TIMR_CR_IM_Pos)
#define TIMR_CR_IM                                          TIMR_CR_IM_Msk

/***********************  Bits definition for TIMR_EOI  ***********************/
#define TIMR_EOI_EOI_Pos                                    (0)
#define TIMR_EOI_EOI_Msk                                    (0x1UL << TIMR_EOI_EOI_Pos)
#define TIMR_EOI_EOI                                        TIMR_EOI_EOI_Msk

/**********************  Bits definition for TIMR_STAT  ***********************/
#define TIMR_STAT_STAT_Pos                                  (0)
#define TIMR_STAT_STAT_Msk                                  (0x1UL << TIMR_STAT_STAT_Pos)
#define TIMR_STAT_STAT                                      TIMR_STAT_STAT_Msk

/******************************************************************************/
/*                                                                            */
/*                                 TIMRSYS                                    */
/*                                                                            */
/******************************************************************************/

/*********************  Bits definition for TIMRSYS_STAT  *********************/
#define TIMRSYS_STAT_TIMR_Pos                               (0)
#define TIMRSYS_STAT_TIMR_Msk                               (0xfUL << TIMRSYS_STAT_TIMR_Pos)
#define TIMRSYS_STAT_TIMR                                   TIMRSYS_STAT_TIMR_Msk
#define TIMRSYS_STAT_TIMR_0                                 (0x1UL << TIMRSYS_STAT_TIMR_Pos)
#define TIMRSYS_STAT_TIMR_1                                 (0x2UL << TIMRSYS_STAT_TIMR_Pos)
#define TIMRSYS_STAT_TIMR_2                                 (0x4UL << TIMRSYS_STAT_TIMR_Pos)
#define TIMRSYS_STAT_TIMR_3                                 (0x8UL << TIMRSYS_STAT_TIMR_Pos)

/*********************  Bits definition for TIMRSYS_EOI  **********************/
#define TIMRSYS_EOI_TIMR_Pos                                (0)
#define TIMRSYS_EOI_TIMR_Msk                                (0xfUL << TIMRSYS_EOI_TIMR_Pos)
#define TIMRSYS_EOI_TIMR                                    TIMRSYS_EOI_TIMR_Msk
#define TIMRSYS_EOI_TIMR_0                                  (0x1UL << TIMRSYS_EOI_TIMR_Pos)
#define TIMRSYS_EOI_TIMR_1                                  (0x2UL << TIMRSYS_EOI_TIMR_Pos)
#define TIMRSYS_EOI_TIMR_2                                  (0x4UL << TIMRSYS_EOI_TIMR_Pos)
#define TIMRSYS_EOI_TIMR_3                                  (0x8UL << TIMRSYS_EOI_TIMR_Pos)

/********************  Bits definition for TIMRSYS_RSTAT  *********************/
#define TIMRSYS_RSTAT_TIMR_Pos                              (0)
#define TIMRSYS_RSTAT_TIMR_Msk                              (0xfUL << TIMRSYS_RSTAT_TIMR_Pos)
#define TIMRSYS_RSTAT_TIMR                                  TIMRSYS_RSTAT_TIMR_Msk
#define TIMRSYS_RSTAT_TIMR_0                                (0x1UL << TIMRSYS_RSTAT_TIMR_Pos)
#define TIMRSYS_RSTAT_TIMR_1                                (0x2UL << TIMRSYS_RSTAT_TIMR_Pos)
#define TIMRSYS_RSTAT_TIMR_2                                (0x4UL << TIMRSYS_RSTAT_TIMR_Pos)
#define TIMRSYS_RSTAT_TIMR_3                                (0x8UL << TIMRSYS_RSTAT_TIMR_Pos)

/******************************************************************************/
/*                                                                            */
/*                                  UART                                      */
/*                                                                            */
/******************************************************************************/

/*******************  Bits definition for UART_RBR_THR_DLL  *******************/
#define UART_RBR_THR_DLL_RBR_Pos                            (0)
#define UART_RBR_THR_DLL_RBR_Msk                            (0xffUL << UART_RBR_THR_DLL_RBR_Pos)
#define UART_RBR_THR_DLL_RBR                                UART_RBR_THR_DLL_RBR_Msk
#define UART_RBR_THR_DLL_THR_Pos                            (0)
#define UART_RBR_THR_DLL_THR_Msk                            (0xffUL << UART_RBR_THR_DLL_THR_Pos)
#define UART_RBR_THR_DLL_THR                                UART_RBR_THR_DLL_THR_Msk
#define UART_RBR_THR_DLL_DLL_Pos                            (0)
#define UART_RBR_THR_DLL_DLL_Msk                            (0xffUL << UART_RBR_THR_DLL_DLL_Pos)
#define UART_RBR_THR_DLL_DLL                                UART_RBR_THR_DLL_DLL_Msk

/*********************  Bits definition for UART_DLH_IER  *********************/
#define UART_DLH_IER_DLH_Pos                                (0)
#define UART_DLH_IER_DLH_Msk                                (0xffUL << UART_DLH_IER_DLH_Pos)
#define UART_DLH_IER_DLH                                    UART_DLH_IER_DLH_Msk
#define UART_DLH_IER_ERBFI_Pos                              (0)
#define UART_DLH_IER_ERBFI_Msk                              (0x1UL << UART_DLH_IER_ERBFI_Pos)
#define UART_DLH_IER_ERBFI                                  UART_DLH_IER_ERBFI_Msk
#define UART_DLH_IER_ETBEI_Pos                              (1)
#define UART_DLH_IER_ETBEI_Msk                              (0x1UL << UART_DLH_IER_ETBEI_Pos)
#define UART_DLH_IER_ETBEI                                  UART_DLH_IER_ETBEI_Msk
#define UART_DLH_IER_ELSI_Pos                               (2)
#define UART_DLH_IER_ELSI_Msk                               (0x1UL << UART_DLH_IER_ELSI_Pos)
#define UART_DLH_IER_ELSI                                   UART_DLH_IER_ELSI_Msk
#define UART_DLH_IER_EDSSI_Pos                              (3)
#define UART_DLH_IER_EDSSI_Msk                              (0x1UL << UART_DLH_IER_EDSSI_Pos)
#define UART_DLH_IER_EDSSI                                  UART_DLH_IER_EDSSI_Msk
#define UART_DLH_IER_PTIME_Pos                              (7)
#define UART_DLH_IER_PTIME_Msk                              (0x1UL << UART_DLH_IER_PTIME_Pos)
#define UART_DLH_IER_PTIME                                  UART_DLH_IER_PTIME_Msk

/*********************  Bits definition for UART_IIR_FCR  *********************/
#define UART_IIR_FCR_IID_Pos                                (0)
#define UART_IIR_FCR_IID_Msk                                (0xfUL << UART_IIR_FCR_IID_Pos)
#define UART_IIR_FCR_IID                                    UART_IIR_FCR_IID_Msk
#define UART_IIR_FCR_IID_0                                  (0x1UL << UART_IIR_FCR_IID_Pos)
#define UART_IIR_FCR_IID_1                                  (0x2UL << UART_IIR_FCR_IID_Pos)
#define UART_IIR_FCR_IID_2                                  (0x4UL << UART_IIR_FCR_IID_Pos)
#define UART_IIR_FCR_IID_3                                  (0x8UL << UART_IIR_FCR_IID_Pos)
#define UART_IIR_FCR_FIFOSE_Pos                             (6)
#define UART_IIR_FCR_FIFOSE_Msk                             (0x3UL << UART_IIR_FCR_FIFOSE_Pos)
#define UART_IIR_FCR_FIFOSE                                 UART_IIR_FCR_FIFOSE_Msk
#define UART_IIR_FCR_FIFOSE_0                               (0x1UL << UART_IIR_FCR_FIFOSE_Pos)
#define UART_IIR_FCR_FIFOSE_1                               (0x2UL << UART_IIR_FCR_FIFOSE_Pos)
#define UART_IIR_FCR_FIFOE_Pos                              (0)
#define UART_IIR_FCR_FIFOE_Msk                              (0x1UL << UART_IIR_FCR_FIFOE_Pos)
#define UART_IIR_FCR_FIFOE                                  UART_IIR_FCR_FIFOE_Msk
#define UART_IIR_FCR_RFIFOR_Pos                             (1)
#define UART_IIR_FCR_RFIFOR_Msk                             (0x1UL << UART_IIR_FCR_RFIFOR_Pos)
#define UART_IIR_FCR_RFIFOR                                 UART_IIR_FCR_RFIFOR_Msk
#define UART_IIR_FCR_TFIFOR_Pos                             (2)
#define UART_IIR_FCR_TFIFOR_Msk                             (0x1UL << UART_IIR_FCR_TFIFOR_Pos)
#define UART_IIR_FCR_TFIFOR                                 UART_IIR_FCR_TFIFOR_Msk
#define UART_IIR_FCR_DMAM_Pos                               (3)
#define UART_IIR_FCR_DMAM_Msk                               (0x1UL << UART_IIR_FCR_DMAM_Pos)
#define UART_IIR_FCR_DMAM                                   UART_IIR_FCR_DMAM_Msk
#define UART_IIR_FCR_TET_Pos                                (4)
#define UART_IIR_FCR_TET_Msk                                (0x3UL << UART_IIR_FCR_TET_Pos)
#define UART_IIR_FCR_TET                                    UART_IIR_FCR_TET_Msk
#define UART_IIR_FCR_TET_0                                  (0x1UL << UART_IIR_FCR_TET_Pos)
#define UART_IIR_FCR_TET_1                                  (0x2UL << UART_IIR_FCR_TET_Pos)
#define UART_IIR_FCR_RCVR_Pos                               (6)
#define UART_IIR_FCR_RCVR_Msk                               (0x3UL << UART_IIR_FCR_RCVR_Pos)
#define UART_IIR_FCR_RCVR                                   UART_IIR_FCR_RCVR_Msk
#define UART_IIR_FCR_RCVR_0                                 (0x1UL << UART_IIR_FCR_RCVR_Pos)
#define UART_IIR_FCR_RCVR_1                                 (0x2UL << UART_IIR_FCR_RCVR_Pos)

/***********************  Bits definition for UART_LCR  ***********************/
#define UART_LCR_DLS_Pos                                    (0)
#define UART_LCR_DLS_Msk                                    (0x3UL << UART_LCR_DLS_Pos)
#define UART_LCR_DLS                                        UART_LCR_DLS_Msk
#define UART_LCR_DLS_0                                      (0x1UL << UART_LCR_DLS_Pos)
#define UART_LCR_DLS_1                                      (0x2UL << UART_LCR_DLS_Pos)
#define UART_LCR_STOP_Pos                                   (2)
#define UART_LCR_STOP_Msk                                   (0x1UL << UART_LCR_STOP_Pos)
#define UART_LCR_STOP                                       UART_LCR_STOP_Msk
#define UART_LCR_PEN_Pos                                    (3)
#define UART_LCR_PEN_Msk                                    (0x1UL << UART_LCR_PEN_Pos)
#define UART_LCR_PEN                                        UART_LCR_PEN_Msk
#define UART_LCR_EPS_Pos                                    (4)
#define UART_LCR_EPS_Msk                                    (0x1UL << UART_LCR_EPS_Pos)
#define UART_LCR_EPS                                        UART_LCR_EPS_Msk
#define UART_LCR_STICK_PARITY_Pos                           (5)
#define UART_LCR_STICK_PARITY_Msk                           (0x1UL << UART_LCR_STICK_PARITY_Pos)
#define UART_LCR_STICK_PARITY                               UART_LCR_STICK_PARITY_Msk
#define UART_LCR_BC_Pos                                     (6)
#define UART_LCR_BC_Msk                                     (0x1UL << UART_LCR_BC_Pos)
#define UART_LCR_BC                                         UART_LCR_BC_Msk
#define UART_LCR_DLAB_Pos                                   (7)
#define UART_LCR_DLAB_Msk                                   (0x1UL << UART_LCR_DLAB_Pos)
#define UART_LCR_DLAB                                       UART_LCR_DLAB_Msk

/***********************  Bits definition for UART_MCR  ***********************/
#define UART_MCR_DTR_Pos                                    (0)
#define UART_MCR_DTR_Msk                                    (0x1UL << UART_MCR_DTR_Pos)
#define UART_MCR_DTR                                        UART_MCR_DTR_Msk
#define UART_MCR_RTS_Pos                                    (1)
#define UART_MCR_RTS_Msk                                    (0x1UL << UART_MCR_RTS_Pos)
#define UART_MCR_RTS                                        UART_MCR_RTS_Msk
#define UART_MCR_LB_Pos                                     (4)
#define UART_MCR_LB_Msk                                     (0x1UL << UART_MCR_LB_Pos)
#define UART_MCR_LB                                         UART_MCR_LB_Msk
#define UART_MCR_AFCE_Pos                                   (5)
#define UART_MCR_AFCE_Msk                                   (0x1UL << UART_MCR_AFCE_Pos)
#define UART_MCR_AFCE                                       UART_MCR_AFCE_Msk
#define UART_MCR_SIRE_Pos                                   (6)
#define UART_MCR_SIRE_Msk                                   (0x1UL << UART_MCR_SIRE_Pos)
#define UART_MCR_SIRE                                       UART_MCR_SIRE_Msk

/***********************  Bits definition for UART_LSR  ***********************/
#define UART_LSR_DR_Pos                                     (0)
#define UART_LSR_DR_Msk                                     (0x1UL << UART_LSR_DR_Pos)
#define UART_LSR_DR                                         UART_LSR_DR_Msk
#define UART_LSR_OE_Pos                                     (1)
#define UART_LSR_OE_Msk                                     (0x1UL << UART_LSR_OE_Pos)
#define UART_LSR_OE                                         UART_LSR_OE_Msk
#define UART_LSR_PE_Pos                                     (2)
#define UART_LSR_PE_Msk                                     (0x1UL << UART_LSR_PE_Pos)
#define UART_LSR_PE                                         UART_LSR_PE_Msk
#define UART_LSR_FE_Pos                                     (3)
#define UART_LSR_FE_Msk                                     (0x1UL << UART_LSR_FE_Pos)
#define UART_LSR_FE                                         UART_LSR_FE_Msk
#define UART_LSR_BI_Pos                                     (4)
#define UART_LSR_BI_Msk                                     (0x1UL << UART_LSR_BI_Pos)
#define UART_LSR_BI                                         UART_LSR_BI_Msk
#define UART_LSR_THRE_Pos                                   (5)
#define UART_LSR_THRE_Msk                                   (0x1UL << UART_LSR_THRE_Pos)
#define UART_LSR_THRE                                       UART_LSR_THRE_Msk
#define UART_LSR_TEMT_Pos                                   (6)
#define UART_LSR_TEMT_Msk                                   (0x1UL << UART_LSR_TEMT_Pos)
#define UART_LSR_TEMT                                       UART_LSR_TEMT_Msk
#define UART_LSR_RFE_Pos                                    (7)
#define UART_LSR_RFE_Msk                                    (0x1UL << UART_LSR_RFE_Pos)
#define UART_LSR_RFE                                        UART_LSR_RFE_Msk

/***********************  Bits definition for UART_MSR  ***********************/
#define UART_MSR_DCTS_Pos                                   (0)
#define UART_MSR_DCTS_Msk                                   (0x1UL << UART_MSR_DCTS_Pos)
#define UART_MSR_DCTS                                       UART_MSR_DCTS_Msk
#define UART_MSR_DDSR_Pos                                   (1)
#define UART_MSR_DDSR_Msk                                   (0x1UL << UART_MSR_DDSR_Pos)
#define UART_MSR_DDSR                                       UART_MSR_DDSR_Msk
#define UART_MSR_TERI_Pos                                   (2)
#define UART_MSR_TERI_Msk                                   (0x1UL << UART_MSR_TERI_Pos)
#define UART_MSR_TERI                                       UART_MSR_TERI_Msk
#define UART_MSR_DDCD_Pos                                   (3)
#define UART_MSR_DDCD_Msk                                   (0x1UL << UART_MSR_DDCD_Pos)
#define UART_MSR_DDCD                                       UART_MSR_DDCD_Msk
#define UART_MSR_CTS_Pos                                    (4)
#define UART_MSR_CTS_Msk                                    (0x1UL << UART_MSR_CTS_Pos)
#define UART_MSR_CTS                                        UART_MSR_CTS_Msk
#define UART_MSR_DSR_Pos                                    (5)
#define UART_MSR_DSR_Msk                                    (0x1UL << UART_MSR_DSR_Pos)
#define UART_MSR_DSR                                        UART_MSR_DSR_Msk
#define UART_MSR_RI_Pos                                     (6)
#define UART_MSR_RI_Msk                                     (0x1UL << UART_MSR_RI_Pos)
#define UART_MSR_RI                                         UART_MSR_RI_Msk
#define UART_MSR_DCD_Pos                                    (7)
#define UART_MSR_DCD_Msk                                    (0x1UL << UART_MSR_DCD_Pos)
#define UART_MSR_DCD                                        UART_MSR_DCD_Msk

/***********************  Bits definition for UART_USR  ***********************/
#define UART_USR_BUSY_Pos                                   (0)
#define UART_USR_BUSY_Msk                                   (0x1UL << UART_USR_BUSY_Pos)
#define UART_USR_BUSY                                       UART_USR_BUSY_Msk

/******************************************************************************/
/*                                                                            */
/*                                   WDT                                      */
/*                                                                            */
/******************************************************************************/

/************************  Bits definition for WDT_CR  ************************/
#define WDT_CR_EN_Pos                                       (0)
#define WDT_CR_EN_Msk                                       (0x1UL << WDT_CR_EN_Pos)
#define WDT_CR_EN                                           WDT_CR_EN_Msk
#define WDT_CR_RMOD_Pos                                     (1)
#define WDT_CR_RMOD_Msk                                     (0x1UL << WDT_CR_RMOD_Pos)
#define WDT_CR_RMOD                                         WDT_CR_RMOD_Msk
#define WDT_CR_RPL_Pos                                      (2)
#define WDT_CR_RPL_Msk                                      (0x7UL << WDT_CR_RPL_Pos)
#define WDT_CR_RPL                                          WDT_CR_RPL_Msk
#define WDT_CR_RPL_0                                        (0x1UL << WDT_CR_RPL_Pos)
#define WDT_CR_RPL_1                                        (0x2UL << WDT_CR_RPL_Pos)
#define WDT_CR_RPL_2                                        (0x4UL << WDT_CR_RPL_Pos)

/***********************  Bits definition for WDT_TORR  ***********************/
#define WDT_TORR_TOP_Pos                                    (0)
#define WDT_TORR_TOP_Msk                                    (0xfUL << WDT_TORR_TOP_Pos)
#define WDT_TORR_TOP                                        WDT_TORR_TOP_Msk
#define WDT_TORR_TOP_0                                      (0x1UL << WDT_TORR_TOP_Pos)
#define WDT_TORR_TOP_1                                      (0x2UL << WDT_TORR_TOP_Pos)
#define WDT_TORR_TOP_2                                      (0x4UL << WDT_TORR_TOP_Pos)
#define WDT_TORR_TOP_3                                      (0x8UL << WDT_TORR_TOP_Pos)

/***********************  Bits definition for WDT_CCVR  ***********************/
#define WDT_CCVR_CNT_Pos                                    (0)
#define WDT_CCVR_CNT_Msk                                    (0xffffffffUL << WDT_CCVR_CNT_Pos)
#define WDT_CCVR_CNT                                        WDT_CCVR_CNT_Msk

/***********************  Bits definition for WDT_CRR  ************************/
#define WDT_CRR_CCR_Pos                                     (0)
#define WDT_CRR_CCR_Msk                                     (0xffUL << WDT_CRR_CCR_Pos)
#define WDT_CRR_CCR                                         WDT_CRR_CCR_Msk

/***********************  Bits definition for WDT_STAT  ***********************/
#define WDT_STAT_STAT_Pos                                   (0)
#define WDT_STAT_STAT_Msk                                   (0x1UL << WDT_STAT_STAT_Pos)
#define WDT_STAT_STAT                                       WDT_STAT_STAT_Msk

/***********************  Bits definition for WDT_EOI  ************************/
#define WDT_EOI_EOI_Pos                                     (0)
#define WDT_EOI_EOI_Msk                                     (0x1UL << WDT_EOI_EOI_Pos)
#define WDT_EOI_EOI                                         WDT_EOI_EOI_Msk


/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup Exported_macros
  * @{
  */
    
/******************************* MDU Instances ********************************/
#define IS_MDU_ALL_INSTANCE(INSTANCE) ((INSTANCE) == MDU)
#define IS_ADC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == MDU)
#define IS_COMP_ALL_INSTANCE(INSTANCE) ((INSTANCE) == MDU)
#define IS_DAC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == MDU)
#define IS_PGA_ALL_INSTANCE(INSTANCE) ((INSTANCE) == MDU)

/******************************* CRC Instances ********************************/
#define IS_AFC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == SYSCFG)

/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(INSTANCE) ((INSTANCE) == CRC)

/******************************** DMA Instances *******************************/
#define IS_DMA_ALL_INSTANCE(INSTANCE) (((INSTANCE) == DMA1_Channel0) || \
                                       ((INSTANCE) == DMA1_Channel1) || \
                                       ((INSTANCE) == DMA1_Channel2) || \
                                       ((INSTANCE) == DMA1_Channel3) || \
                                       ((INSTANCE) == DMA1_Channel4) || \
                                       ((INSTANCE) == DMA1_Channel5) || \
                                       ((INSTANCE) == DMA1_Channel6) || \
                                       ((INSTANCE) == DMA1_Channel7))

/******************************** DMAMUX Instances ****************************/
#define IS_DMAMUX_ALL_INSTANCE(INSTANCE) ((INSTANCE) == DMAMUX0)

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(INSTANCE) (((INSTANCE) == GPIOA) || \
                                        ((INSTANCE) == GPIOB) || \
                                        ((INSTANCE) == GPIOC) || \
                                        ((INSTANCE) == GPIOD) || \
                                        ((INSTANCE) == GPIOAUX))

/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(INSTANCE) (((INSTANCE) == I2C0) || \
                                       ((INSTANCE) == I2C1))


/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(INSTANCE)  ((INSTANCE) == RTC)

/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(INSTANCE) (((INSTANCE) == SPI1M) || \
                                       ((INSTANCE) == SPI1S) || \
                                       ((INSTANCE) == SPI2M) || \
                                       ((INSTANCE) == SPI2S))

/****************** TIM Instances : All supported instances *******************/
#define IS_TIM_INSTANCE(INSTANCE)       (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting 32 bits counter ****************/
#define IS_TIM_32B_COUNTER_INSTANCE(INSTANCE) (((INSTANCE) == TIMB11) || \
                                         ((INSTANCE) == TIMB12) || \
                                         ((INSTANCE) == TIMB13) || \
                                         ((INSTANCE) == TIMB14) || \
                                         ((INSTANCE) == TIMB21) || \
                                         ((INSTANCE) == TIMB22) || \
                                         ((INSTANCE) == TIMB23) || \
                                         ((INSTANCE) == TIMB24))

/****************** TIM Instances : supporting the break function *************/
#define IS_TIM_BREAK_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/************** TIM Instances : supporting Break source selection *************/
#define IS_TIM_BREAKSOURCE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting 2 break inputs *****************/
#define IS_TIM_BKIN2_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/************* TIM Instances : at least 1 capture/compare channel *************/
#define IS_TIM_CC1_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/************ TIM Instances : at least 2 capture/compare channels *************/
#define IS_TIM_CC2_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/************ TIM Instances : at least 3 capture/compare channels *************/
#define IS_TIM_CC3_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/************ TIM Instances : at least 4 capture/compare channels *************/
#define IS_TIM_CC4_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/****************** TIM Instances : at least 5 capture/compare channels *******/
#define IS_TIM_CC5_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/****************** TIM Instances : at least 6 capture/compare channels *******/
#define IS_TIM_CC6_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/************ TIM Instances : DMA requests generation (TIMx_DIER.COMDE) *******/
#define IS_TIM_CCDMA_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/****************** TIM Instances : DMA requests generation (TIMx_DIER.UDE) ***/
#define IS_TIM_DMA_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/************ TIM Instances : DMA requests generation (TIMx_DIER.CCxDE) *******/
#define IS_TIM_DMA_CC_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/******************** TIM Instances : DMA burst feature ***********************/
#define IS_TIM_DMABURST_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/******************* TIM Instances : output(s) available **********************/
#define IS_TIM_CCX_INSTANCE(INSTANCE, CHANNEL) \
    (((((INSTANCE) == TIM1) || ((INSTANCE) == TIMG)) &&                  \
     (((CHANNEL) == TIM_CHANNEL_1) ||          \
      ((CHANNEL) == TIM_CHANNEL_2) ||          \
      ((CHANNEL) == TIM_CHANNEL_3) ||          \
      ((CHANNEL) == TIM_CHANNEL_4) ||          \
      ((CHANNEL) == TIM_CHANNEL_5) ||          \
      ((CHANNEL) == TIM_CHANNEL_6)))           \
     )

/****************** TIM Instances : supporting complementary output(s) ********/
#define IS_TIM_CCXN_INSTANCE(INSTANCE, CHANNEL) \
   (((((INSTANCE) == TIM1) || ((INSTANCE) == TIMG)) &&                    \
     (((CHANNEL) == TIM_CHANNEL_1) ||           \
      ((CHANNEL) == TIM_CHANNEL_2) ||           \
      ((CHANNEL) == TIM_CHANNEL_3)))            \
    )

/****************** TIM Instances : supporting clock division *****************/
#define IS_TIM_CLOCK_DIVISION_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1)  || \
                                                    ((INSTANCE) == TIMG))

/****** TIM Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIMG))

/****** TIM Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting external clock mode 1 for TIX inputs*/
#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting internal trigger inputs(ITRX) *******/
#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(INSTANCE)     (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting combined 3-phase PWM mode ******/
#define IS_TIM_COMBINED3PHASEPWM_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting commutation event generation ***/
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                     ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting counting mode selection ********/
#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                                        ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting encoder interface **************/
#define IS_TIM_ENCODER_INTERFACE_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                                      ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting Hall sensor interface **********/
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                                         ((INSTANCE) == TIMG))

/**************** TIM Instances : external trigger input available ************/
#define IS_TIM_ETR_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/************* TIM Instances : supporting ETR source selection ***************/
#define IS_TIM_ETRSEL_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/****** TIM Instances : Master mode available (TIMx_CR2.MMS available )********/
#define IS_TIM_MASTER_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/*********** TIM Instances : Slave mode available (TIMx_SMCR available )*******/
#define IS_TIM_SLAVE_INSTANCE(INSTANCE)   (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting OCxREF clear *******************/
#define IS_TIM_OCXREF_CLEAR_INSTANCE(INSTANCE)        (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting bitfield OCCS in SLVMD register *******************/
#define IS_TIM_OCCS_INSTANCE(INSTANCE)                (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/****************** TIM Instances : remapping capability **********************/
#define IS_TIM_REMAP_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting repetition counter *************/
#define IS_TIM_REPETITION_COUNTER_INSTANCE(INSTANCE)  (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/****************** TIM Instances : supporting ADC triggering through TRGO2 ***/
#define IS_TIM_TRGO2_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/******************* TIM Instances : Timer input XOR function *****************/
#define IS_TIM_XOR_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/******************* TIM Instances : Timer input selection ********************/
#define IS_TIM_TISEL_INSTANCE(INSTANCE) (((INSTANCE) == TIM1) || \
                                            ((INSTANCE) == TIMG))

/************ TIM Instances : Advanced timers  ********************************/
#define IS_TIM_ADVANCED_INSTANCE(INSTANCE)    (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/****************** TIMG Instances : All supported instances *******************/
#define IS_TIMG_INSTANCE(INSTANCE)      (((INSTANCE) == TIM1) || \
                                         ((INSTANCE) == TIMG))

/****************** TIMB Instances : All supported instances *******************/
#define IS_TIMR_INSTANCE(INSTANCE)      (((INSTANCE) == TIMB11) || \
                                         ((INSTANCE) == TIMB12) || \
                                         ((INSTANCE) == TIMB13) || \
                                         ((INSTANCE) == TIMB14) || \
                                         ((INSTANCE) == TIMB21) || \
                                         ((INSTANCE) == TIMB22) || \
                                         ((INSTANCE) == TIMB23) || \
                                         ((INSTANCE) == TIMB24))

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(INSTANCE) (((INSTANCE) == UART1) || \
                                    ((INSTANCE) == UART2) || \
                                    ((INSTANCE) == UART3) || \
                                    ((INSTANCE) == UART4))

/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(INSTANCE) (((INSTANCE) == UART1) || \
                                           ((INSTANCE) == UART2) || \
                                           ((INSTANCE) == UART3) || \
                                           ((INSTANCE) == UART4) )

/****************** UART Instances : Driver Enable *****************/
#define IS_UART_FIFO_INSTANCE(INSTANCE)     (((INSTANCE) == UART1) || \
                                             ((INSTANCE) == UART2) || \
                                             ((INSTANCE) == UART3) || \
                                             ((INSTANCE) == UART4))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(INSTANCE) (((INSTANCE) == UART1) || \
                                    ((INSTANCE) == UART2) || \
                                    ((INSTANCE) == UART3) || \
                                    ((INSTANCE) == UART4))

/****************************** WDT Instances ********************************/
#define IS_WDT_ALL_INSTANCE(INSTANCE)  (((INSTANCE) == WDTW) || \
                                        ((INSTANCE) == WDTI))


/**
  * @}
  */

    
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* XT32H0XXAMPW_H */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

    