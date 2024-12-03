/**
  ******************************************************************************
  * @file    xt32h0xx_hal_flash.c
  * @author  Software Team
  * @brief   FLASH HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the internal FLASH memory:
  *           + Program operations functions
  *           + Memory Control functions
  *           + Peripheral Errors functions
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @defgroup FLASH FLASH
  * @brief FLASH HAL module driver
  * @{
  */

#ifdef HAL_FLASH_MODULE_ENABLED
#if (defined(XT32H0xxAMPW) || defined(XT32H0xxA))
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup FLASH_Exported_Functions FLASH Exported Functions
  * @{
  */

/** @defgroup FLASH_Exported_Functions_Group1 operation functions
  *  @brief   Operation functions
  *
  * @{
  */
/**
  * @brief  Flash read enable.
  * @param  None
  *
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_ReadEnable(void) __attribute__((section("flash_read")));	
HAL_StatusTypeDef HAL_FLASH_ReadEnable(void)
{
  HAL_StatusTypeDef status = HAL_OK;

  /*flash mode set to READ*/
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ);

  /* return status */
  return status;
}

/**
  * @brief  Flash recall read enable.
  * @param  None
  *
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_RecallReadEnable(void)
{
  HAL_StatusTypeDef status = HAL_OK;

  /*flash mode set to READ*/
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_RECALLREAD);

  /* return status */
  return status;
}

/**
  * @brief  Program a word at a specified address.
  * @param  Address Specifies the address to be programmed.
  * @param  Data Specifies the data to be programmed
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t* Address, uint32_t* Data) __attribute__((section("flash_write")));	
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t* Address, uint32_t* Data)
{
  HAL_StatusTypeDef status;
	
	uint32_t addr = *Address;
	uint32_t da = *Data;

  /* Check the parameters */
  //assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));

  /* Process Locked */
//  __HAL_LOCK(&pFlash);

  /* Set FLASH Time*/

  /* write row address */
  WRITE_REG(FLASH->ROWADDR, addr & 0xFFFFFF00UL);

  /* Set pre-prog and flash mode prog*/
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE | FLASH_CTRL_PREPR, FLASH_MODE_PROG | FLASH_PREPROG_ENABLE);

  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)da;

  /* Set pre-prog and flash mode prog*/
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE | FLASH_CTRL_PREPR, FLASH_MODE_PROG | FLASH_PREPROG_DISABLE);

  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)da;

  /* PROG Start */
  WRITE_REG(FLASH->STRT, 0x000000FFUL);

  /* wait time */

  /* Process Unlocked */
//  __HAL_UNLOCK(&pFlash);
  __NOP();
	__NOP();
	__NOP();
	__NOP();
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
  __NOP();
	__NOP();
	__NOP();
	__NOP();

  /* return status */
  return status;
}

/**
  * @brief  Program code and data.
  * @param  Address Specifies the address to be programmed.
  * @param  Data Specifies the data to be programmed
  * @param  Size Specifies the data size to be programmed
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_ProgramMass(uint32_t* Address, uint32_t* Data, uint32_t* Size) __attribute__((section("flash_write_mass")));	
HAL_StatusTypeDef  HAL_FLASH_ProgramMass(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  HAL_StatusTypeDef status = HAL_OK;

  uint32_t waddr, wsize, rowsize, waddr_bk;

  uint32_t tsize = 0;

  uint32_t* pdata1  = Data;
  uint32_t* pdata2  = Data;
	
	uint32_t addr = *Address;
	uint32_t leng = *Size;

  int i=0;

  waddr = addr;
  wsize = leng*4;

  /* Check the parameters */
  //assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));

  /* Process Locked */
//  __HAL_LOCK(&pFlash);

  /* Set FLASH Time*/

  do {
    if((waddr >= FLASH_CODE_BASE) &&(waddr <(FLASH_CODE_BASE+FLASH_CODE_SIZE) )) 
    {
      rowsize = (FLASH_SIZE_CODE_ROW);
    }
    else if((waddr >= FLASH_DATA_BASE) &&(waddr <(FLASH_DATA_BASE+FLASH_DATA_SIZE) )) 
    {
      rowsize = (FLASH_SIZE_DATA_ROW);
    }
    else
    {
      status = HAL_ERROR;
      break;
    }

    if((waddr+wsize) > ((waddr&0xFFFFFF00UL)+rowsize))
    {
      wsize = ((waddr&0xFFFFFF00UL)+rowsize) - waddr;
    }

    /* write row address */
    WRITE_REG(FLASH->ROWADDR, waddr & 0xFFFFFF00UL);

    /* Set pre-prog and flash mode prog*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE | FLASH_CTRL_PREPR, FLASH_MODE_PROG | FLASH_PREPROG_ENABLE);

    /* Write address and data*/
    waddr_bk = waddr;
    for(i=0; i<wsize; i+=4)
    {
      *(uint32_t *)waddr = (uint32_t)(*pdata1++);
      waddr += 4;
    }

    /* Set pre-prog and flash mode prog*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE | FLASH_CTRL_PREPR, FLASH_MODE_PROG | FLASH_PREPROG_DISABLE);

    /* Write address and data*/
    waddr = waddr_bk;
    for(i=0; i<wsize; i+=4)
    {
      *(uint32_t *)waddr = (uint32_t)(*pdata2++);
      waddr +=4;
    }

    /* PROG Start */
    WRITE_REG(FLASH->STRT, 0x000000FFUL);

    /* wait time */

    tsize += wsize;

    //waddr += wsize;
    wsize = leng*4 - tsize;

  } while(tsize < leng*4);

  /* Process Unlocked */
//  __HAL_UNLOCK(&pFlash);
  __NOP();
	__NOP();
	__NOP();
	__NOP();
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
  __NOP();
	__NOP();
	__NOP();
	__NOP();

  /* return status */
  return status;
}

/**
  * @brief  Erase sectors at a specified address.
  * @param  Address row address in sector
  * @param  SectorSize the number of sector
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_EraseSector(uint32_t* Address, uint32_t* SectorSize) __attribute__((section("flash_erase_sector")));	
HAL_StatusTypeDef HAL_FLASH_EraseSector(uint32_t* Address, uint32_t* SectorSize)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = *Address & 0xFFFFFF00UL;
	uint32_t size = *SectorSize;
	
  int i = 0;
 
  for(i=0; i<size; i++)
  {
    /* write row address */
    WRITE_REG(FLASH->ROWADDR, addr);

    /*flash mode set to READ*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_SECTORERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    if((addr >= FLASH_CODE_BASE) &&(addr <(FLASH_CODE_BASE+FLASH_CODE_SIZE) )) 
    {
      addr += (FLASH_ROW_CODE_SECTOR*FLASH_SIZE_CODE_ROW);
    }
    else
    {
      addr += (FLASH_ROW_DATA_SECTOR*FLASH_SIZE_DATA_ROW);
    }

    /* wait time */
  }
	
  __NOP();
	__NOP();
	__NOP();
	__NOP();
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
  __NOP();
	__NOP();
	__NOP();
	__NOP();

  /* return status */
  return status;
}

/**
  * @brief  earse blocks at a specified address.
  * @param  Address start row address
  * @param  BlockSize the number of block
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_EraseBlock(uint32_t* Address, uint32_t* BlockSize) __attribute__((section("flash_erase_block")));	
HAL_StatusTypeDef HAL_FLASH_EraseBlock(uint32_t* Address, uint32_t* BlockSize)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = *Address & 0xFFFFFF00UL;
	uint32_t size = *BlockSize;
  int i = 0;
 
  for(i=0; i<size; i++)
  {

    /* write row address */
    WRITE_REG(FLASH->ROWADDR, addr);

    /*flash mode set to READ*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_BLOCKERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    addr += (FLASH_ROW_CODE_BLOCK*FLASH_SIZE_CODE_ROW);

    /* wait time */
  }

  __NOP();
	__NOP();
	__NOP();
	__NOP();
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
  __NOP();
	__NOP();
	__NOP();
	__NOP();

  /* return status */
  return status;
}

/**
  * @brief  Erase code and data area.
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_EraseMass(void) __attribute__((section("flash_erase_mass")));	
HAL_StatusTypeDef  HAL_FLASH_EraseMass(void)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = FLASH_CODE_BASE & 0xFFFFFF00UL;
 
  /*erase code blocks*/ 
  while(addr < (FLASH_CODE_BASE+FLASH_CODE_SIZE))
  {

    /* write row address */
    WRITE_REG(FLASH->ROWADDR, addr);

    /*flash mode set to READ*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_BLOCKERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    addr += (FLASH_ROW_CODE_BLOCK*FLASH_SIZE_CODE_ROW);

    /* wait time */
  }

  /*erase data blocks*/ 
  addr = FLASH_DATA_BASE & 0xFFFFFF00UL;
  while(addr < (FLASH_DATA_BASE+FLASH_DATA_SIZE))
  {

    /* write row address */
    WRITE_REG(FLASH->ROWADDR, addr);

    /*flash mode set to READ*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_BLOCKERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    addr += (FLASH_ROW_DATA_BLOCK*FLASH_SIZE_DATA_ROW);

    /* wait time */
  }

  __NOP();
	__NOP();
	__NOP();
	__NOP();
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
  __NOP();
	__NOP();
	__NOP();
	__NOP();
	
  /* return status */
  return status;

}

/**
  * @brief  Program a word at a specified address.
  * @param  Address Specifies the address to be programmed.
  * @param  Data Specifies the data to be programmed
  * @param  Size Specifies the data size to be programmed
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_ProgramNVMCFG(uint32_t* Address, uint32_t* Data, uint32_t* Size) __attribute__((section("flash_write_nvmcfg")));	
HAL_StatusTypeDef  HAL_FLASH_ProgramNVMCFG(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  HAL_StatusTypeDef status;
	
	uint32_t addr = *Address;
	uint32_t* pdata = Data;
  uint32_t size = *Size;

  int i=0;

  /* Check address & size*/
  if((addr < FLASH_NVMCFG_BASE) || (addr > FLASH_NVMCFG_BASE+FLASH_BYTESIZE_NVMCFG))
  {
    return HAL_ERROR; /* address error */
  }

  if ((addr + size*FLASH_ROW_NVMCFG_SECTOR*FLASH_SIZE_NVMCFG_ROW) > FLASH_NVMCFG_BASE+FLASH_BYTESIZE_NVMCFG)
  {
    return HAL_ERROR; /* size error */
  }

  /* unlock nvm */
  __HAL_FLASH_NVMCFG_UNLOCK();

  /* Set FLASH Time*/

  for(i=0; i<size; i++)
  {
    /* write row address */
    WRITE_REG(FLASH->ROWADDR, addr & 0xFFFFFF00UL);
  
    /* Set pre-prog and flash mode prog*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE | FLASH_CTRL_PREPR, FLASH_MODE_PROG | FLASH_PREPROG_ENABLE);
  
    /* Write address and data*/
     *(uint32_t *)addr = *pdata++;
    /* Set pre-prog and flash mode prog*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE | FLASH_CTRL_PREPR, FLASH_MODE_PROG | FLASH_PREPROG_DISABLE);
  
    /* Write address and data*/
    *(uint32_t *)addr = *pdata++;
  
    /* PROG Start */
    WRITE_REG(FLASH->STRT, 0x000000FFUL);

    addr += 4;
  }

  /* wait time */

  /* lock nvm */
  __HAL_FLASH_NVMCFG_LOCK();

  /* read enable */
  __NOP();
	__NOP();
	__NOP();
	__NOP();
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
  __NOP();
	__NOP();
	__NOP();
	__NOP();

  /* return status */
  return status;
}

/**
  * @brief  Erase sectors at a specified address.
  * @param  Address row address in nvm sector
  * @param  SectorSize the number of sector
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_EraseNVMCFG(uint32_t* Address, uint32_t* SectorSize) __attribute__((section("flash_erase_nvmcfg")));	
HAL_StatusTypeDef  HAL_FLASH_EraseNVMCFG(uint32_t* Address, uint32_t* SectorSize)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = *Address & 0xFFFFFF00UL;
	uint32_t size = *SectorSize;
	
  int i = 0;

  /* check address and SectorSize*/
  if((addr < FLASH_NVMCFG_BASE) || (addr > FLASH_NVMCFG_BASE+FLASH_BYTESIZE_NVMCFG))
  {
    return HAL_ERROR;
  }

  if ((addr + size*FLASH_ROW_NVMCFG_SECTOR*FLASH_SIZE_NVMCFG_ROW) > FLASH_NVMCFG_BASE+FLASH_BYTESIZE_NVMCFG)
  {
    size = (FLASH_NVMCFG_BASE+FLASH_BYTESIZE_NVMCFG-addr)/(FLASH_ROW_NVMCFG_SECTOR*FLASH_SIZE_NVMCFG_ROW)+1;
  }

  /* unlock nvm */
  __HAL_FLASH_NVMCFG_UNLOCK();
 
  for(i=0; i<size; i++)
  {
    /* write row address */
    WRITE_REG(FLASH->ROWADDR, addr);

    /*flash mode set to READ*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_SECTORERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    addr += (FLASH_ROW_NVMCFG_SECTOR*FLASH_SIZE_NVMCFG_ROW);

    if(addr > FLASH_NVMCFG_BASE+FLASH_BYTESIZE_NVMCFG)
    {
      break;
    }

    /* wait time */
  }

  /* lock nvm */
  __HAL_FLASH_NVMCFG_LOCK();
	
  /* read enable */
  __NOP();
	__NOP();
	__NOP();
	__NOP();
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
  __NOP();
	__NOP();
	__NOP();
	__NOP();

  /* return status */
  return status;
}


/**
  * @}
  */

/** @defgroup FLASH_Exported_Functions_Group2 Peripheral Control functions
  *  @brief   Management functions
  *
  * @{
  */

/**
  * @brief  Unlock the FLASH control register access.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_Unlock(void)
{
  HAL_StatusTypeDef status = HAL_OK;

  return status;
}

/**
  * @brief  Lock the FLASH control register access.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_Lock(void)
{
  HAL_StatusTypeDef status = HAL_ERROR;

  return status;
}

/**
  * @brief  Initialize Program time.
  * @param  ProgInit Specifies time for programming.
  * @retval HAL Status
  */
void HAL_FLASH_Program_SetTime(FLASH_ProgramInitTypeDef* ProgInit) __attribute__((section("flash_prog_settime")));
void HAL_FLASH_Program_SetTime(FLASH_ProgramInitTypeDef* ProgInit)
{
  uint32_t systemclk = HAL_RCC_GetSysClockFreq()/1000000;    /*sysyem clock 96M*/
  
  if (ProgInit->ProgWebSetupHoldTime < FLASH_TIME_SLOW_NVS)
  {
    WRITE_REG(FLASH->PRWESTPHLDT, FLASH_TIME_SLOW_NVS*systemclk);
  }
  else
  {
    WRITE_REG(FLASH->PRWESTPHLDT, ProgInit->ProgWebSetupHoldTime*systemclk);
  }

  if(ProgInit->Prog2SetupTime < FLASH_TIME_NOR_PREPGS)
  {
    WRITE_REG(FLASH->PR2STPT, FLASH_TIME_NOR_PREPGS*systemclk);
  }
  else
  {
    WRITE_REG(FLASH->PR2STPT, ProgInit->Prog2SetupTime*systemclk);
  }


  if(ProgInit->ProgWebPulseWidth < FLASH_TIME_NOR_HV)
  {
    WRITE_REG(FLASH->PRWEPLW, FLASH_TIME_NOR_HV*systemclk);
  }
  else
  {
    WRITE_REG(FLASH->PRWEPLW, ProgInit->ProgWebPulseWidth*systemclk);
  }
}

/**
  * @brief  Set erase time.
  * @param  EraseInit Specifies erase times.
  * @retval None
  */
void HAL_FLASH_Erase_SetTime(FLASH_EraseInitTypeDef* EraseInit) __attribute__((section("flash_erase_settime")));
void HAL_FLASH_Erase_SetTime(FLASH_EraseInitTypeDef* EraseInit)
{
  uint32_t systemclk = HAL_RCC_GetSysClockFreq()/1000000;    /*sysyem clock 96M*/

  if(EraseInit->ErasePulseWidth < (10000+FLASH_TIME_NOR_RCV))
  {
    WRITE_REG(FLASH->ERPLW, (10000+FLASH_TIME_NOR_RCV)*systemclk);
  }
  else
  {
    WRITE_REG(FLASH->ERPLW, EraseInit->ErasePulseWidth*systemclk);
  }

  if(EraseInit->EraseWebPulseWidth < 10000)
  {
    WRITE_REG(FLASH->ERWEPLW, (10000)*systemclk);
  }
  else
  {
    WRITE_REG(FLASH->ERWEPLW, EraseInit->EraseWebPulseWidth*systemclk);
  }

  if(EraseInit->EraseWebSetupTime < FLASH_TIME_SLOW_NVS)
  {
    WRITE_REG(FLASH->ERWESTPT, (FLASH_TIME_SLOW_NVS)*systemclk);
  }
  else
  {
    WRITE_REG(FLASH->ERWESTPT, EraseInit->EraseWebSetupTime*systemclk);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/



#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxB))
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @defgroup FLASH_Exported_Functions FLASH Exported Functions
  * @{
  */

/** @defgroup FLASH_Exported_Functions_Group1 operation functions
  *  @brief   Operation functions
  *
  * @{
  */
/**
  * @brief  Flash read enable.
  * @param  None
  *
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_ReadEnable(void) __attribute__((section("flash_read")));	
HAL_StatusTypeDef HAL_FLASH_ReadEnable(void)
{
  HAL_StatusTypeDef status = HAL_OK;

  /*flash mode set to READ*/
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ);

  /* return status */
  return status;
}

/**
  * @brief  Program a word  at a specified address.
  * @param  Address Specifies the address to be programmed.
  * @param  Data Specifies the data to be programmed
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t* Address, uint32_t* Data) __attribute__((section("flash_write")));	
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t* Address, uint32_t* Data)
{
  HAL_StatusTypeDef status = HAL_OK;
	
	uint32_t addr = *Address;
	uint32_t da = *Data;

  /* Check the parameters */
  //assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));

  /* Process Locked */
//  __HAL_LOCK(&pFlash);

  /* Set FLASH Time*/

  /* Set flash mode prog*/
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PROG);

  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)da;
	
	MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 


  /* return status */
  return status;
}

/**
  * @brief  Program code at a specified address.
  * @param  Address Specifies the address to be programmed.
  * @param  Data Specifies the data to be programmed
  * @param  Size Specifies the data size to be programmed
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_ProgramCode(uint32_t* Address, uint32_t* Data, uint32_t* Size) __attribute__((section("flash_write_code")));	
HAL_StatusTypeDef  HAL_FLASH_ProgramCode(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  HAL_StatusTypeDef status = HAL_OK;

  uint32_t tsize = 0;

  uint32_t* pdata  = Data;
	
	uint32_t addr = *Address;
	uint32_t leng = *Size;

//  int i=0;
	tsize = 0;


  do {
    if((addr < FLASH_CODE_BASE) || (addr >=(FLASH_CODE_BASE+FLASH_CODE_SIZE) )) 
    {
      break;
    }

    /* Set flash mode prog*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PROG);
    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)(*pdata++);
		/* Set flash mode read*/
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 

    addr += 4;
		tsize += 4;

  } while(tsize < leng);


  /* return status */
  return status;
}

/**
  * @brief  Program data at a specified address.
  * @param  Address Specifies the address to be programmed.
  * @param  Data Specifies the data to be programmed
  * @param  Size Specifies the data size to be programmed
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_ProgramData(uint32_t* Address, uint32_t* Data, uint32_t* Size) __attribute__((section("flash_write_data")));	
HAL_StatusTypeDef  HAL_FLASH_ProgramData(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  HAL_StatusTypeDef status = HAL_OK;

  uint32_t tsize = 0;

  uint32_t* pdata  = Data;
	
	uint32_t addr = *Address;
	uint32_t leng = *Size;

//  int i=0;
	tsize = 0;


  do {
    if((addr < FLASH_DATA_BASE) || (addr >=(FLASH_DATA_BASE+FLASH_DATA_SIZE) )) 
    {
      break;
    }

    /* Set flash mode prog*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PROG);
    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)(*pdata++);
		/* Set flash mode read*/
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 

    addr += 4;
		tsize += 4;

  } while(tsize < leng);


  /* return status */
  return status;
}

/**
  * @brief  Program info at a specified address.
  * @param  Address Specifies the address to be programmed.
  * @param  Data Specifies the data to be programmed
  * @param  Size Specifies the data size to be programmed
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_ProgramInfo(uint32_t* Address, uint32_t* Data, uint32_t* Size) __attribute__((section("flash_write_info")));	
HAL_StatusTypeDef  HAL_FLASH_ProgramInfo(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  HAL_StatusTypeDef status = HAL_OK;

  uint32_t tsize = 0;

  uint32_t* pdata  = Data;
	
	uint32_t addr = *Address;
	uint32_t leng = *Size;

//  int i=0;
	tsize = 0;


  do {
    if((addr < FLASH_INFO_BASE) ||(addr >=(FLASH_INFO_BASE+FLASH_INFO_SIZE) )) 
    {
      break;
    }

    /* Set flash mode prog*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PROG);
    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)(*pdata++);
		/* Set flash mode read*/
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 

    addr += 4;
		tsize += 4;

  } while(tsize < leng);


  /* return status */
  return status;
}

/**
  * @brief  Erase pages at a specified address.
  * @param  Address Specifies address in page
  * @param  PageSize the number of pages
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_ErasePage(uint32_t* Address, uint32_t* PageSize) __attribute__((section("flash_erase_page")));	
HAL_StatusTypeDef HAL_FLASH_ErasePage(uint32_t* Address, uint32_t* PageSize)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = *Address & 0xFFFFE000UL;
	int size = (int)*PageSize;
	
  int i = 0;
 
  for(i=0; i< size; i++)
  {
    /*flash mode set to page erase*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PAGEERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 

    addr += (FLASH_SIZE_PAGE);
    /* wait time */
		
  }
	
  /* return status */
  return status;
}

/**
  * @brief  Erase code at a specified address.
  * @param  Address Specified address in code page
  * @param  PageSize the number of pages
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_EraseCode(uint32_t* Address, uint32_t* PageSize) __attribute__((section("flash_erase_code")));	
HAL_StatusTypeDef HAL_FLASH_EraseCode(uint32_t* Address, uint32_t* PageSize)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = *Address & 0xFFFFE000UL;
	int size = (int)*PageSize;
	
  int i = 0;
 
  for(i=0; i<size; i++)
  {
    if((addr < FLASH_CODE_BASE) || (addr >=(FLASH_CODE_BASE+FLASH_CODE_SIZE) )) 
    {
      break;
    }

    /*flash mode set to page erase*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PAGEERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 

    addr += (FLASH_SIZE_PAGE);
    /* wait time */
  }
	
  /* return status */
  return status;
}

/**
  * @brief  Erase data pages at a specified address.
  * @param  Address Spiecifies address in data page
  * @param  PageSize the number of pages
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_EraseData(uint32_t* Address, uint32_t* PageSize) __attribute__((section("flash_erase_data")));	
HAL_StatusTypeDef HAL_FLASH_EraseData(uint32_t* Address, uint32_t* PageSize)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = *Address & 0xFFFFE000UL;
	int size = (int)*PageSize;
	
  int i = 0;
 
  for(i=0; i<size; i++)
  {
    if((addr < FLASH_DATA_BASE) || (addr >=(FLASH_DATA_BASE+FLASH_DATA_SIZE) )) 
    {
      break;
    }

    /*flash mode set to page erase*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PAGEERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 

    addr += (FLASH_SIZE_PAGE);
    /* wait time */
  }
	
  /* return status */
  return status;
}

/**
  * @brief  Erase info pages at a specified address.
  * @param  Address Specifies an address in info page
  * @param  PageSize the number of info pages
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_EraseInfo(uint32_t* Address, uint32_t* PageSize) __attribute__((section("flash_erase_info")));	
HAL_StatusTypeDef HAL_FLASH_EraseInfo(uint32_t* Address, uint32_t* PageSize)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = *Address & 0xFFFFE000UL;
	int size = (int)*PageSize;

  int i = 0;
 
  for(i=0; i<size; i++)
  {
    if((addr < FLASH_INFO_BASE) || (addr >=(FLASH_INFO_BASE+FLASH_INFO_SIZE) )) 
    {
      break;
    }
 
		/*flash mode set to page erase*/
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PAGEERASE);

		/* Write address and data*/
		*(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
			
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
		
		addr += (FLASH_SIZE_PAGE);
	}

  /* return status */
  return status;
}

/**
  * @brief  Erase code and data area.
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_EraseMass(void) __attribute__((section("flash_erase_mass")));	
HAL_StatusTypeDef  HAL_FLASH_EraseMass(void)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t addr = FLASH_CODE_BASE & 0xFFFFE000UL;
 
  /*erase code blocks*/ 
  while(addr < (FLASH_CODE_BASE+FLASH_CODE_SIZE))
  {

    /*flash mode set to READ*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PAGEERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 

    addr += (FLASH_SIZE_PAGE);

    /* wait time */
  }

  addr = FLASH_DATA_BASE & 0xFFFFE000UL;
 
  /*erase code blocks*/ 
  while(addr < (FLASH_DATA_BASE+FLASH_DATA_SIZE))
  {

    /*flash mode set to READ*/
    MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_PAGEERASE);

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
		MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 

    addr += (FLASH_SIZE_PAGE);

    /* wait time */
  }
	
  /* return status */
  return status;

}

/**
  * @brief  Erase all chip excluding info pages.
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_EraseChip(void) __attribute__((section("flash_erase_chip")));
HAL_StatusTypeDef  HAL_FLASH_EraseChip(void)
{
	HAL_StatusTypeDef status = HAL_OK;
	uint32_t addr = FLASH_CODE_BASE;

  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_CHIPERASE);

  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
	
	return status;
}

/**
  * @brief  Erase all chip including info pages.
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_EraseChipWithInfo(void) __attribute__((section("flash_erase_chipwithinfo")));
HAL_StatusTypeDef  HAL_FLASH_EraseChipWithInfo(void)
{
	HAL_StatusTypeDef status = HAL_OK;
	uint32_t addr = FLASH_INFO_BASE;

  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_CHIPERASE);

  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
  MODIFY_REG(FLASH->CTRL, FLASH_CTRL_MODE, FLASH_MODE_READ); 
	
	return status;
}

/**
  * @brief  Set time base (1us).
  * @param  Cycle clock cycles
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_SetTimeBase(uint32_t Cycle) __attribute__((section("flash_time_base")));
HAL_StatusTypeDef  HAL_FLASH_SetTimeBase(uint32_t Cycle)
{
	HAL_StatusTypeDef status = HAL_OK;
	
	MODIFY_REG(FLASH->SMW_SET_TIMER, FLASH_TMR_GEN, Cycle << FLASH_TMR_GEN_Pos);
	
	return status;
}

/**
  * @brief  Set read time.
  * @param  Cycle clock cycles
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef  HAL_FLASH_SetReadTime(uint32_t Cycle) __attribute__((section("flash_time_read")));
HAL_StatusTypeDef  HAL_FLASH_SetReadTime(uint32_t Cycle)
{
	HAL_StatusTypeDef status = HAL_OK;

	MODIFY_REG(FLASH->SMW_SET_TIMER, FLASH_TMR_RD, Cycle << FLASH_TMR_RD_Pos);
	
	return status;
}


/**
  * @}
  */

/** @defgroup FLASH_Exported_Functions_Group2 Peripheral Control functions
  *  @brief   Management functions
  *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to control the FLASH
    memory operations.

@endverbatim
  * @{
  */

/**
  * @brief  Unlock the FLASH control register access.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_Unlock(void)
{
  HAL_StatusTypeDef status = HAL_OK;

//  if (READ_BIT(FLASH->CR, FLASH_CR_LOCK) != 0x00U)
//  {
//    /* Authorize the FLASH Registers access */
//    WRITE_REG(FLASH->KEYR, FLASH_KEY1);
//    WRITE_REG(FLASH->KEYR, FLASH_KEY2);

//    /* verify Flash is unlock */
//    if (READ_BIT(FLASH->CR, FLASH_CR_LOCK) != 0x00U)
//    {
//      status = HAL_ERROR;
//    }
//  }

  return status;
}

/**
  * @brief  Lock the FLASH control register access.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_Lock(void)
{
  HAL_StatusTypeDef status = HAL_ERROR;

//  /* Set the LOCK Bit to lock the FLASH Registers access */
//  SET_BIT(FLASH->CR, FLASH_CR_LOCK);

//  /* verify Flash is locked */
//  if (READ_BIT(FLASH->CR, FLASH_CR_LOCK) != 0x00u)
//  {
//    status = HAL_OK;
//  }

  return status;
}

/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/

#endif /* XT32H0xxBMPW || XT32H0xxB */
#endif /* HAL_FLASH_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
