/**
  ******************************************************************************
  * @file    xt32h0xx_flash.h
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file contains all the functions prototypes for the FLASH 
  *          firmware library.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_FLASH_H
#define __XT32H0XX_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */
#if (defined(XT32H0xxAMPW) || defined(XT32H0xxA))
/* Exported types ------------------------------------------------------------*/
/** @defgroup FLASH_Exported_Types Flash Exported Types
  * @{
  */ 
/**
  * @brief  FLASH Erase structure definition
  */
typedef struct
{
  uint32_t ErasePulseWidth;       /*!< @us */
  uint32_t EraseWebPulseWidth;    /*!< @us */
  uint32_t EraseWebSetupTime;     /*!< @us */
} FLASH_EraseInitTypeDef;

/**
  * @brief  FLASH Option Bytes Program structure definition
  */
typedef struct
{
  uint32_t ProgWebSetupHoldTime;  /*!< @us */
  uint32_t Prog2SetupTime;        /*!< @us */
  uint32_t ProgWebPulseWidth;     /*!< @us */
} FLASH_ProgramInitTypeDef;
/**
  * @}
  */ 

/* Exported constants --------------------------------------------------------*/
  
/** @defgroup FLASH_Exported_Constants Flash Exported Constants
  * @{
  */ 
  
/** @defgroup FLASH_Mode Flash Mode
  * @{
  */ 
#define FLASH_MODE_READ                (0x00000000UL)                          /*!< FLASH Zero wait state */
#define FLASH_MODE_RECALLREAD          (0x00000001UL)                          /*!< FLASH One wait state */
#define FLASH_MODE_PROG                (0x00000002UL)                          /*!< FLASH Two wait states */
#define FLASH_MODE_SLOWPROG            (0x00000003UL)                          /*!< FLASH Two wait states */
#define FLASH_MODE_SECTORERASE         (0x00000004UL)                          /*!< FLASH Two wait states */
#define FLASH_MODE_BLOCKERASE          (0x00000005UL)                          /*!< FLASH Two wait states */
#define FLASH_MODE_CHIPERASE           (0x00000006UL)                          /*!< FLASH Two wait states */

#define IS_FLASH_MODE(MODE)       (((MODE) == FLASH_MODE_READ)        || \
                                   ((MODE) == FLASH_MODE_RECALLREAD)  || \
                                   ((MODE) == FLASH_MODE_PROG)        || \
                                   ((MODE) == FLASH_MODE_SLOWPROG)    || \
                                   ((MODE) == FLASH_MODE_SECTORERASE) || \
                                   ((MODE) == FLASH_MODE_BLOCKERASE)  || \
                                   ((MODE) == FLASH_MODE_CHIPERASE))
/**
  * @}
  */ 

/** @defgroup FLASH_PREPR FLASH Pre-Prog
  * @{
  */
#define FLASH_PREPROG_DISABLE          (0x00000000UL)                           /*!< FLASH Zero wait state */
#define FLASH_PREPROG_ENABLE           (FLASH_CTRL_PREPR)                       /*!< FLASH One wait state */

#define IS_FLASH_PREPROG(MODE)       (((MODE) == FLASH_PREPROG_DISABLE)        || \
                                      ((MODE) == FLASH_PREPROG_ENABLE))
/**
  * @}
  */

/** @defgroup FLASH_Address Flash Address
  * @{
  */
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= 0x08000000) && ((ADDRESS) <= 0x0803FFFF))
/**
  * @}
  */

/** @defgroup FLASH_Sector_size  Flash Sector Size
  * @{
  */
#define FLASH_SIZE_ROW                 (64*4)                                  /*!< FLASH rrwo is 64 words */

#define FLASH_SIZE_CODE_SECTOR         (8   )                                  /*!< FLASH code secter 8 row */
#define FLASH_SIZE_DATA_SECTOR         (2   )                                  /*!< FLASH data sector 2 row */
#define FLASH_SIZE_CODE_BLOCK          (8*8 )                                  /*!< FLASH code block 8*8 row */
#define FLASH_SIZE_DATA_BLOCK          (32*2)                                  /*!< FLASH data block 32*2 row */
/**
  * @}
  */

/** @defgroup FLASH_Time FLASH Time \@us
  * @{
  */
#define FLASH_TIME_SLOW_NVS            (   4UL)                                /*!< PROG rise to WEB fall */
#define FLASH_TIME_SLOW_PGS            (  20UL)                                /*!< PROG2 WEB */
#define FLASH_TIME_SLOW_PREPROG        (   5UL)                                /*!< PROG2 pulse width (pre-prog) */
#define FLASH_TIME_SLOW_PREPGH         (  15UL)                                /*!< PROG2 fall to PREPG fall */
#define FLASH_TIME_SLOW_PREPGS         (  16UL)                                /*!< PROG2 rise to PREPG fall */
#define FLASH_TIME_SLOW_PROG           (  15UL)                                /*!< PROG2 Pulse width */
#define FLASH_TIME_SLOW_PGH            (  15UL)                                /*!< PROG2 fall to WEB rise */
#define FLASH_TIME_SLOW_HV             (3000UL)                                /*!< WEB low width */
#define FLASH_TIME_SLOW_RCV            (   5UL)                                /*!< WEB rise to PROG fall */
#define FLASH_TIME_NOR_PGS             (  12UL)                                /*!< PROG2 WEB */
#define FLASH_TIME_NOR_PREPROG         (   3UL)                                /*!< PROG2 pulse width (pre-prog)*/
#define FLASH_TIME_NOR_PREPGS          (   8UL)                                /*!< PROG2 rise to PREPG fall */
#define FLASH_TIME_NOR_PROG            (  10UL)                                /*!< PROG2 Pulse width */
#define FLASH_TIME_NOR_HV              (3000UL)                                /*!< WEB low width */
#define FLASH_TIME_NOR_RCV             (   5UL)                                /*!< WEB rise to PROG fall */
/**
  * @}
  */

/**
  * @}
  */ 

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup FLASH_Exported_Functions
  * @{
  */

/** @addtogroup FLASH_Exported_Functions_Group1
  * @{
  */ 
/** 
  * @brief  FLASH memory functions that can be executed from FLASH.  
  */  
/* FLASH Interface configuration functions ************************************/
void FLASH_ReadEnable(void);
void FLASH_RecallReadEnable(void);
void FLASH_Program_SetTime(FLASH_ProgramInitTypeDef* ProgInit);
void FLASH_Erase_SetTime(FLASH_EraseInitTypeDef* EraseInit);
void FLASH_ProgramTimeInit(FLASH_ProgramInitTypeDef* ProgInit);
void FLASH_EraseTimeInit(FLASH_EraseInitTypeDef* EraseInit);

/**
  * @}
  */
/** @addtogroup FLASH_Exported_Functions_Group2
  * @{
  */ 
/* FLASH Memory Programming functions *****************************************/
void FLASH_Program(uint32_t* Address, uint32_t* Data);
void FLASH_ProgramMass(uint32_t* Address, uint32_t* Data, uint32_t* Size);
void FLASH_EraseSector(uint32_t* Address, uint32_t* SectorSize);
void FLASH_EraseBlock(uint32_t* Address, uint32_t* BlockSize);
void FLASH_EraseMass(void);
/**
  * @}
  */
/**
  * @}
  */ 

#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxB))
/* Exported types ------------------------------------------------------------*/
/** @defgroup FLASH_Exported_Types Flash Exported Types
  * @{
  */ 
/**
  * @}
  */ 

/* Exported constants --------------------------------------------------------*/
  
/** @defgroup FLASH_Exported_Constants Flash Exported Constants
  * @{
  */ 

/** @defgroup FLASH_Size FLASH size 
  * @{
  */
#define FLASH_SIZE_PAGE                (0x2000)                                /*!< 8Kbytes */
/**
  * @}
  */
  
/** @defgroup FLASH_Mode Flash Mode
  * @{
  */ 
#define FLASH_MODE_READ                (0x00000000UL)                          /*!< FLASH read */
#define FLASH_MODE_CHIPERASE           (0x00000002UL)                          /*!< FLASH chip erase */
#define FLASH_MODE_PAGEERASE           (0x00000003UL)                          /*!< FLASH page erase */
#define FLASH_MODE_PROG                (0x00000004UL)                          /*!< FLASH program */
#define FLASH_MODE_REPROG              (0x00000006UL)                          /*!< FLASH re-program */

#define IS_FLASH_MODE(MODE)       (((MODE) == FLASH_MODE_READ)        || \
                                   ((MODE) == FLASH_MODE_PAGEERASE)   || \
                                   ((MODE) == FLASH_MODE_PROG)        || \
                                   ((MODE) == FLASH_MODE_REPROG)      || \
                                   ((MODE) == FLASH_MODE_CHIPERASE))
/**
  * @}
  */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup FLASH_Exported_Functions 
  * @{
  */ 

/** @addtogroup FLASH_Exported_Functions_Group1
  * @{
  */ 
void FLASH_SetTimeBase(uint32_t Cycle);
void FLASH_SetReadTime(uint32_t Cycle);
/**
  * @}
  */

/** @addtogroup FLASH_Exported_Functions_Group2
  * @{
  */ 
/** 
  * @brief  FLASH memory functions that can be executed from FLASH.  
  */  
/* FLASH Interface configuration functions ************************************/
void FLASH_ReadEnable(void);
void FLASH_Program(uint32_t* Address, uint32_t* Data);
void FLASH_ProgramCode(uint32_t* Address, uint32_t* Data, uint32_t* Size);
void FLASH_ProgramData(uint32_t* Address, uint32_t* Data, uint32_t* Size);
void FLASH_ProgramInfo(uint32_t* Address, uint32_t* Data, uint32_t* Size);
void FLASH_ErasePage(uint32_t* Address, uint32_t* PageSize);
void FLASH_EraseCode(uint32_t* Address, uint32_t* PageSize);
void FLASH_EraseData(uint32_t* Address, uint32_t* PageSize);
void FLASH_EraseInfo(uint32_t* Address, uint32_t* PageSize);
void FLASH_EraseMass(void);
void FLASH_EraseChip(void);
void FLASH_EraseChipWithInfo(void);

/**
  * @}
  */

/**
  * @}
  */
#endif /* XT32H0xxBMPW || XT32H0xxB */


#ifdef __cplusplus
}
#endif

/**
  * @}
  */

/**
  * @}
  */ 

#endif /* __XT32H0XX_FLASH_H */

