/**
  ******************************************************************************
  * @file    xt32h0xx_hal_flash.h
  * @author  Software Team
  * @brief   Header file of FLASH HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_FLASH_H
#define XT32H0xx_HAL_FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

#if defined(XT32H0xxAMPW) || defined(XT32H0xxA)
/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup FLASH_Exported_Types FLASH Exported Types
  * @{
  */

/**
  * @brief  FLASH Erase structure definition
  */
typedef struct
{
  uint32_t ErasePulseWidth;       /*!< Erase pulse width */
  uint32_t EraseWebPulseWidth;    /*!< Erase web pulse width */
  uint32_t EraseWebSetupTime;     /*!< Erase web setup time */
} FLASH_EraseInitTypeDef;

/**
  * @brief  FLASH Option Bytes Program structure definition
  */
typedef struct
{
  uint32_t Mode;                  /*!< Operation mode to be configured.
                                       This parameter can be a combination of the values of @ref FLASH_Mode */
  uint32_t ProgWebSetupHoldTime;  /*!< Set programming web setup hold time. */
  uint32_t Prog2SetupTime;        /*!< Set programming process 2 setup time */
  uint32_t ProgWebPulseWidth;     /*!< Set programming web pulse width */
} FLASH_ProgramInitTypeDef;

/**
  * @brief  FLASH handle Structure definition
  */
//typedef struct
//{
//  HAL_LockTypeDef   Lock;              /* FLASH locking object */
//  uint32_t          ErrorCode;         /* FLASH error code */
//  uint32_t          ProcedureOnGoing;  /* Internal variable to indicate which procedure is ongoing or not in IT context */
//  uint32_t          Address;           /* Internal variable to save address selected for program in IT context */
//  uint32_t          Banks;             /* Internal variable to save current bank selected during erase in IT context */
//  uint32_t          Page;              /* Internal variable to define the current page which is erasing in IT context */
//  uint32_t          NbPagesToErase;    /* Internal variable to save the remaining pages to erase in IT context */
//} FLASH_ProcessTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup FLASH_Exported_Constants FLASH Exported Constants
  * @{
  */

/** @defgroup FLASH_ROW_Size FLASH size 
  */
#define FLASH_SIZE_CODE_ROW            (64*4)                                  /*!< FLASH CODE row is 64*4 Bytes */
#define FLASH_SIZE_DATA_ROW            (64*4)                                  /*!< FLASH DATA row is 65*4 Bytes */
#define FLASH_SIZE_NVM_ROW             (64*4)                                  /*!< FLASH NVM row is 65*4 Bytes */
#define FLASH_SIZE_NVMCFG_ROW          (64*4)                                  /*!< FLASH NVMCFG row is 65*4 Bytes */
/**
  * @}
  */

/** @defgroup FLASH_Size FLASH size 
  * @{
  */
#define FLASH_SECTOR_CODE_BLOCK        (8)                                     /*!< FLASH 8 code sectors per code block */
#define FLASH_SECTOR_DATA_BLOCK        (32)                                    /*!< FLASH 32 data sectors per data block */

#define FLASH_ROW_CODE_SECTOR          (8)                                     /*!< FLASH 8 code rows per code secter */
#define FLASH_ROW_DATA_SECTOR          (2)                                     /*!< FLASH 2 data rows per data sector */
#define FLASH_ROW_NVM_SECTOR           (2)                                     /*!< FLASH 2 nvm rows pre nvm sector */
#define FLASH_ROW_NVMCFG_SECTOR        (2)                                     /*!< FLASH 2 nvmcfg rows per nvmcfg sector */

#define FLASH_ROW_CODE_BLOCK           (FLASH_SECTOR_CODE_BLOCK*FLASH_ROW_CODE_SECTOR)      /*!< FLASH row number per code block */
#define FLASH_ROW_DATA_BLOCK           (FLASH_SECTOR_DATA_BLOCK*FLASH_ROW_DATA_SECTOR)      /*!< FLASH row number per data block */

#define FLASH_CODE_SECTOR_NUM          (128)                                    /*!< FLASH totals 128 code secters */
#define FLASH_DATA_SECTOR_NUM          (256)                                    /*!< FLASH totals 256 data sectors */
#define FLASH_NVM_SECTOR_NUM           (8)                                      /*!< FLASH totals 8 nvm sectors */
#define FLASH_NVMCFG_SECTOR_NUM        (1)                                      /*!< FLASH totals 1 nvmcfg sector */

#define FLASH_CODE_BLOCK_NUM           (FLASH_CODE_SECTOR_NUM/FLASH_SECTOR_CODE_BLOCK)  /*!< FLASH code block number */
#define FLASH_DATA_BLOCK_NUM           (FLASH_DATA_SECTOR_NUM/FLASH_SECTOR_DATA_BLOCK)  /*!< FLASH data block number */

#define FLASH_BYTESIZE_CODE            (FLASH_CODE_SECTOR_NUM*FLASH_ROW_CODE_SECTOR*FLASH_SIZE_CODE_ROW)        /*!< FLASH code bytes */
#define FLASH_BYTESIZE_DATA            (FLASH_DATA_SECTOR_NUM*FLASH_ROW_DATA_SECTOR*FLASH_SIZE_DATA_ROW)        /*!< FLASH data bytes */
#define FLASH_BYTESIZE_NVM             (FLASH_NVM_SECTOR_NUM*FLASH_ROW_NVM_SECTOR*FLASH_SIZE_NVM_ROW)           /*!< FLASH nvm bytes */
#define FLASH_BYTESIZE_NVMCFG          (FLASH_NVMCFG_SECTOR_NUM*FLASH_ROW_NVMCFG_SECTOR*FLASH_SIZE_NVMCFG_ROW)  /*!< FLASH nvmcfg bytes */

/**
  * @}
  */

/** @defgroup FLASH_Mode FLASH Mode
  * @{
  */
#define FLASH_MODE_READ                (0x00000000UL)                          /*!< FLASH Zero wait state */
#define FLASH_MODE_RECALLREAD          (0x00000001UL)                          /*!< FLASH One wait state */
#define FLASH_MODE_PROG                (0x00000002UL)                          /*!< FLASH Two wait states */
#define FLASH_MODE_SLOWPROG            (0x00000003UL)                          /*!< FLASH Two wait states */
#define FLASH_MODE_SECTORERASE         (0x00000004UL)                          /*!< FLASH Two wait states */
#define FLASH_MODE_BLOCKERASE          (0x00000005UL)                          /*!< FLASH Two wait states */
#define FLASH_MODE_CHIPERASE           (0x00000006UL)                          /*!< FLASH Two wait states */
/**
  * @}
  */

/** @defgroup FLASH_NVM_CFG FLASH NVMCfg
  * @{
  */
#define FLASH_NVMCFG_DISABLE           (0x00000000UL)                          /*!< FLASH Zero wait state */
#define FLASH_NVMCFG_ENABLE            (FLASH_CTRL_NVMCFG)                     /*!< FLASH One wait state */
/**
  * @}
  */

/** @defgroup FLASH_VERRD FLASH verify read
  * @{
  */
#define FLASH_VERRD_DISABLE            (0x00000000UL)                          /*!< FLASH Zero wait state */
#define FLASH_VERRD_ENABLE             (FLASH_CTRL_VERRD)                      /*!< FLASH One wait state */
/**
  * @}
  */

/** @defgroup FLASH_TMEN FLASH TMEN
  * @{
  */
#define FLASH_TMEN_DISABLE             (0x00000000UL)                          /*!< FLASH Zero wait state */
#define FLASH_TMEN_ENABLE              (FLASH_CTRL_TMEN)                       /*!< FLASH One wait state */
/**
  * @}
  */

/** @defgroup FLASH_ARRDN FLASH ARRDN
  * @{
  */
#define FLASH_ARRDN_DISABLE            (0x00000000UL)                           /*!< FLASH Zero wait state */
#define FLASH_ARRDN_1                  (0x00000001UL << FLASH_CTRL_ARRDN_Pos)   /*!< FLASH One wait state */
#define FLASH_ARRDN_2                  (0x00000002UL << FLASH_CTRL_ARRDN_Pos)   /*!< FLASH Zero wait state */
#define FLASH_ARRDN_3                  (0x00000003UL << FLASH_CTRL_ARRDN_Pos)   /*!< FLASH One wait state */
/**
  * @}
  */

/** @defgroup FLASH_NVMCGF_LOCK FLASH NVM CFG Lock
  * @{
  */
#define FLASH_NVMCFG_UNLOCK            (0x00000000UL)                           /*!< FLASH Zero wait state */
#define FLASH_NVMCFG_LOCK              (FLASH_CTRL_NVMCFGLK)                    /*!< FLASH One wait state */
/**
  * @}
  */

/** @defgroup FLASH_PREPR FLASH Pre-Prog
  * @{
  */
#define FLASH_PREPROG_DISABLE          (0x00000000UL)                           /*!< FLASH Zero wait state */
#define FLASH_PREPROG_ENABLE           (FLASH_CTRL_PREPR)                       /*!< FLASH One wait state */
/**
  * @}
  */

/** @defgroup FLASH_Time FLASH Time @us
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

/** @defgroup FLASH_Type_Erase FLASH Erase Type
  * @{
  */
#define FLASH_TYPEERASE_SECTOR         (FLASH_MODE_SECTORERASE)                /*!< Pages erase only */
#define FLASH_TYPEERASE_BLCOK          (FLASH_MODE_BLOCKERASE)                 /*!< Flash mass erase activation */
#define FLASH_TYPEERASE_MASS           (0x00000007UL)                          /*!< Flash mass erase activation */
/**
  * @}
  */
/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup FLASH_Exported_Macros FLASH Exported Macros
  *  @brief macros to control FLASH features
  *  @{
  */

/**
  * @brief  Set the FLASH Erase Pulse width.
  * @param  __LATENCY__ FLASH erase pulse width
  * @retval None
  */
#define __HAL_FLASH_SET_ERPLW(__LATENCY__)    WRITE_REG(FLASH->ERPLW, (__LATENCY__))

/**
  * @brief  Set the FLASH Erase Pulse width.
  * @retval FLASH erase pulse width
  */
#define __HAL_FLASH_GET_ERPLW()               READ_REG(FLASH->ERPLW)

/**
  * @brief  Set the FLASH Erase WEB Pulse width.
  * @param  __LATENCY__ FLASH erase WEB pulse width
  * @retval None
  */
#define __HAL_FLASH_SET_ERWEW(__LATENCY__)    WRITE_REG(FLASH->ERWEW, (__LATENCY__))

/**
  * @brief  Set the FLASH Erase Pulse width.
  * @retval FLASH erase pulse width
  */
#define __HAL_FLASH_GET_ERWEW()               READ_REG(FLASH->ERWEW)

/**
  * @brief  Set the FLASH Erase WEB Setup time.
  * @param  __LATENCY__ FLASH erase WEB Setup Time
  * @retval None
  */
#define __HAL_FLASH_SET_ERWESTPT(__LATENCY__)    WRITE_REG(FLASH->ERWESTPT, (__LATENCY__))

/**
  * @brief  Set the FLASH Erase WEB Setup width.
  * @retval FLASH erase WEB Setup width
  */
#define __HAL_FLASH_GET_ERWESTPT()               READ_REG(FLASH->ERWESTPT)

/**
  * @brief  Set the FLASH Prog Setup Hold Time.
  * @param  __LATENCY__ FLASH Prog Setup Hold Time
  * @retval None
  */
#define __HAL_FLASH_SET_PRWESTPHLDT(__LATENCY__)    WRITE_REG(FLASH->PRWESTPHLDT, (__LATENCY__))

/**
  * @brief  Set the FLASH Prog Setup Hold Time.
  * @retval FLASH Prog Setup Hold Time
  */
#define __HAL_FLASH_GET_PRWESTPHLDT()               READ_REG(FLASH->PRWESTPHLDT)

/**
  * @brief  Set the FLASH Prog2 Setup Time.
  * @param  __LATENCY__ FLASH Prog2 Setup Time
  * @retval None
  */
#define __HAL_FLASH_SET_PR2STPT(__LATENCY__)    WRITE_REG(FLASH->PR2STPT, (__LATENCY__))

/**
  * @brief  Set the FLASH Prog2 Setup  Time.
  * @retval FLASH Prog2 Setup Time
  */
#define __HAL_FLASH_GET_PR2STPT()               READ_REG(FLASH->PR2STPT)

/**
  * @brief  Set the FLASH Prog WEB Pulse Width.
  * @param  __LATENCY__ FLASH Prog WEB Pulse Width
  * @retval None
  */
#define __HAL_FLASH_SET_PRWEPLW(__LATENCY__)    WRITE_REG(FLASH->PRWEPLW, (__LATENCY__))

/**
  * @brief  Set the FLASH Prog WEB Pulse Width.
  * @retval FLASH Prog WEB Pulse Width
  */
#define __HAL_FLASH_GET_PRWEPLW()               READ_REG(FLASH->PRWEPLW)

/**
  * @brief  The FLASH Prog Start.
  * @param  None
  * @retval None
  */
#define __HAL_FLASH_PROG_START()    WRITE_REG(FLASH->PRSTRT, (0x000000FFUL))

/**
  * @brief  Set the FLASH Row address.
  * @param  __ADDR__ FLASH Row address
  * @retval None
  */
#define __HAL_FLASH_SET_ROWADDR(__ADDR__)    WRITE_REG(FLASH->ROWADDR, (__ADDR__))

/**
  * @brief  Enable the FLASH pre-program.
  * @retval None
  */
#define __HAL_FLASH_PREPROG_ENABLE()    SET_BIT(FLASH->CTRL, FLASH_CTRL_PREPR)

/**
  * @brief  Disable the FLASH pre-program.
  * @retval None
  */
#define __HAL_FLASH_PREPROG_DISABLE()   CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_PREPR)

/**
  * @brief  Lock the FLASH NVM_CFG.
  * @retval none
  */
#define __HAL_FLASH_NVMCFG_LOCK()  SET_BIT(FLASH->CTRL, FLASH_CTRL_NVMCFGLK)

/**
  * @brief  Unlock the FLASH NVM_CFG.
  * @retval none
  */
#define __HAL_FLASH_NVMCFG_UNLOCK() CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_NVMCFGLK)

/**
  * @brief  Enable the FLASH TMEN.
  * @retval None
  */
#define __HAL_FLASH_TMEN_ENABLE()    SET_BIT(FLASH->CTRL, FLASH_CTRL_TMEN)

/**
  * @brief  Disable the FLASH TMEN.
  * @retval None
  */
#define __HAL_FLASH_TMEN_DISABLE()   CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_TMEN)

/**
  * @brief  Enable the FLASH Verify read.
  * @retval None
  */
#define __HAL_FLASH_VERRD_ENABLE()    SET_BIT(FLASH->CTRL, FLASH_CTRL_VERRD)

/**
  * @brief  Disable the FLASH Verify read.
  * @retval None
  */
#define __HAL_FLASH_VERRD_DISABLE()   CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_VERRD)

/**
  * @brief  Enable the FLASH NVM_CFG.
  * @retval None
  */
#define __HAL_FLASH_NVMCFG_ENABLE()    SET_BIT(FLASH->CTRL, FLASH_CTRL_NVMCFG)

/**
  * @brief  Disable the FLASH NVM_CFG.
  * @retval None
  */
#define __HAL_FLASH_NVMCFG_DISABLE()   CLEAR_BIT(FLASH->CTRL, FLASH_CTRL_NVMCFG)

/**
  * @brief  Set the FLASH mode.
  * @param  __MODE__ flash mode
  *         This parameter can be one of the following values :
  *     @arg @ref FLASH_MODE_READ                
  *     @arg @ref FLASH_MODE_RECALLREAD          
  *     @arg @ref FLASH_MODE_PROG                
  *     @arg @ref FLASH_MODE_SLOWPROG            
  *     @arg @ref FLASH_MODE_SECTORERASE         
  *     @arg @ref FLASH_MODE_BLOCKERASE          
  *     @arg @ref FLASH_MODE_CHIPERASE           
  * @retval None
  */
#define __HAL_FLASH_SET_MODE(__MODE__)    MODIFY_REG(FLASH->CTRL, FLASH_MODE_MODE, (__MODE__))

/**
  * @brief  Get the FLASH mode.
  * @retval the return value can be one of the following values : 
  *     @arg @ref FLASH_MODE_READ                
  *     @arg @ref FLASH_MODE_RECALLREAD          
  *     @arg @ref FLASH_MODE_PROG                
  *     @arg @ref FLASH_MODE_SLOWPROG            
  *     @arg @ref FLASH_MODE_SECTORERASE         
  *     @arg @ref FLASH_MODE_BLOCKERASE          
  *     @arg @ref FLASH_MODE_CHIPERASE           
  */
#define __HAL_FLASH_GET_MODE()   READ_BIT(FLASH->CTRL, FLASH_MODE_MODE)
/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup FLASH_Exported_Functions
  * @{
  */

/* Program operation functions  ***********************************************/
/** @addtogroup FLASH_Exported_Functions_Group1
  * @{
  */
HAL_StatusTypeDef HAL_FLASH_ReadEnable(void);
HAL_StatusTypeDef HAL_FLASH_RecallReadEnable(void); 
HAL_StatusTypeDef  HAL_FLASH_Program(uint32_t* Address, uint32_t* Data);
HAL_StatusTypeDef  HAL_FLASH_ProgramMass(uint32_t* Address, uint32_t* Data, uint32_t* Size);
HAL_StatusTypeDef  HAL_FLASH_EraseSector(uint32_t* Address, uint32_t* SectorSize);
HAL_StatusTypeDef  HAL_FLASH_EraseBlock(uint32_t* Address, uint32_t* BlockSize);
HAL_StatusTypeDef  HAL_FLASH_EraseMass(void);

HAL_StatusTypeDef  HAL_FLASH_ProgramNVMCFG(uint32_t* Address, uint32_t* Data, uint32_t* Size);
HAL_StatusTypeDef  HAL_FLASH_EraseNVMCFG(uint32_t* Address, uint32_t* SectorSize);

void          HAL_FLASH_Program_SetTime(FLASH_ProgramInitTypeDef* ProgInit);
void          HAL_FLASH_Erase_SetTime(FLASH_EraseInitTypeDef* EraseInit);

/**
  * @}
  */

/* Peripheral Control functions  **********************************************/
/** @addtogroup FLASH_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef  HAL_FLASH_Unlock(void);
HAL_StatusTypeDef  HAL_FLASH_Lock(void);
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

#elif defined(XT32H0xxBMPW) || defined(XT32H0xxB)
/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */

/* Exported Constants ------------------------------------------------------------*/
/** @defgroup FLASH_Exported_Constants FLASH Exported Constants
  * @{
  */
/** @defgroup FLASH_Size FLASH size 
  * @{
  */
#define FLASH_SIZE_PAGE                (0x2000)                                /*!< 8Kbytes */
/**
  * @}
  */

/** @defgroup FLASH_Mode FLASH Mode
  * @{
  */
#define FLASH_MODE_READ                (0x00000000UL)                          /*!< FLASH read */
#define FLASH_MODE_CHIPERASE           (0x00000002UL)                          /*!< FLASH chip erase */
#define FLASH_MODE_PAGEERASE           (0x00000003UL)                          /*!< FLASH page erase */
#define FLASH_MODE_PROG                (0x00000004UL)                          /*!< FLASH program */
#define FLASH_MODE_REPROG              (0x00000006UL)                          /*!< FLASH re-program */
/**
  * @}
  */
/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup FLASH_Exported_Functions
  * @{
  */

/* Program operation functions  ***********************************************/
/** @addtogroup FLASH_Exported_Functions_Group1
  * @{
  */
HAL_StatusTypeDef  HAL_FLASH_ReadEnable(void);
HAL_StatusTypeDef  HAL_FLASH_Program(uint32_t* Address, uint32_t* Data);
HAL_StatusTypeDef  HAL_FLASH_ProgramCode(uint32_t* Address, uint32_t* Data, uint32_t* Size);
HAL_StatusTypeDef  HAL_FLASH_ProgramData(uint32_t* Address, uint32_t* Data, uint32_t* Size);
HAL_StatusTypeDef  HAL_FLASH_ProgramInfo(uint32_t* Address, uint32_t* Data, uint32_t* Size);
HAL_StatusTypeDef  HAL_FLASH_ErasePage(uint32_t* Address, uint32_t* PageSize);
HAL_StatusTypeDef  HAL_FLASH_EraseCode(uint32_t* Address, uint32_t* PageSize);
HAL_StatusTypeDef  HAL_FLASH_EraseData(uint32_t* Address, uint32_t* PageSize);
HAL_StatusTypeDef  HAL_FLASH_EraseInfo(uint32_t* Address, uint32_t* PageSize);
HAL_StatusTypeDef  HAL_FLASH_EraseMass(void);
HAL_StatusTypeDef  HAL_FLASH_EraseChip(void);
HAL_StatusTypeDef  HAL_FLASH_EraseChipWithInfo(void);


HAL_StatusTypeDef  HAL_FLASH_SetTimeBase(uint32_t cycle);
HAL_StatusTypeDef  HAL_FLASH_SetReadTime(uint32_t cycle);



/**
  * @}
  */

/* Peripheral Control functions  **********************************************/
/** @addtogroup FLASH_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef  HAL_FLASH_Unlock(void);
HAL_StatusTypeDef  HAL_FLASH_Lock(void);
/**
  * @}
  */

/* Peripheral State functions  ************************************************/

/**
  * @}
  */
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

#endif /* XT32H0xx_HAL_FLASH_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
