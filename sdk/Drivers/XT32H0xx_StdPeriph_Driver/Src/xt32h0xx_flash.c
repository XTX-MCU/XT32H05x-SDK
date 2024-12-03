/**
  ******************************************************************************
  * @file    xt32h0xx_flash.c
  * @author  Software Team
  * @date    27 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the FLASH peripheral
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
#include "xt32h0xx_flash.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup FLASH FLASH
  * @brief FLASH driver modules
  * @{
  */ 
#if (defined(XT32H0xxAMPW) || defined(XT32H0xxA))
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
 
/** @defgroup FLASH_Exported_Functions FLASH Exported Functions
  * @{
  */ 

/** @defgroup FLASH_Exported_Functions_Group1 FLASH Interface configuration functions
  *  @brief   FLASH Interface configuration functions 
  *
  * @{
  */

/**
  * @brief  Sets flash to read mode.
  * @param  
  */
void FLASH_ReadEnable(void)
{
  uint32_t tempr;

  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)FLASH_MODE_READ;
  FLASH->CTRL = tempr;
}

/**
  * @brief  Sets flash to slow read mode.
  * @param  
  */
void FLASH_RecallReadEnable(void)
{
  uint32_t tempr;

  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)FLASH_MODE_RECALLREAD;
  FLASH->CTRL = tempr;
}

/**
  * @brief  Configure flash program time.
  * @param  ProgInit: 
  */
void FLASH_Program_SetTime(FLASH_ProgramInitTypeDef* ProgInit)
{
  uint32_t systemclk = RCC_GetSysClockFreq()/1000000;    /*sysyem clock 96M*/
  
  if (ProgInit->ProgWebSetupHoldTime < FLASH_TIME_SLOW_NVS)
  {
    FLASH->PRWESTPHLDT = FLASH_TIME_SLOW_NVS*systemclk;
  }
  else
  {
    FLASH->PRWESTPHLDT = ProgInit->ProgWebSetupHoldTime*systemclk;
  }

  if(ProgInit->Prog2SetupTime < FLASH_TIME_NOR_PREPGS)
  {
    FLASH->PR2STPT = FLASH_TIME_NOR_PREPGS*systemclk;
  }
  else
  {
    FLASH->PR2STPT = ProgInit->Prog2SetupTime*systemclk;
  }


  if(ProgInit->ProgWebPulseWidth < FLASH_TIME_NOR_HV)
  {
    FLASH->PRWEPLW = FLASH_TIME_NOR_HV*systemclk;
  }
  else
  {
    FLASH->PRWEPLW = ProgInit->ProgWebPulseWidth*systemclk;
  }
}

/**
  * @brief  Configure flash erase time.
  * @param  EraseInit: 
  */
void FLASH_Erase_SetTime(FLASH_EraseInitTypeDef* EraseInit)
{
  uint32_t systemclk = RCC_GetSysClockFreq()/1000000;    /*sysyem clock 96M*/

  if(EraseInit->ErasePulseWidth < (10000+FLASH_TIME_NOR_RCV))
  {
    FLASH->ERPLW = (10000+FLASH_TIME_NOR_RCV)*systemclk;
  }
  else
  {
    FLASH->ERPLW =  EraseInit->ErasePulseWidth*systemclk;
  }

  if(EraseInit->EraseWebPulseWidth < 10000)
  {
    FLASH->ERWEPLW = (10000)*systemclk;
  }
  else
  {
    FLASH->ERWEPLW = EraseInit->EraseWebPulseWidth*systemclk;
  }

  if(EraseInit->EraseWebSetupTime < FLASH_TIME_SLOW_NVS)
  {
    FLASH->ERWESTPT = (FLASH_TIME_SLOW_NVS)*systemclk;
  }
  else
  {
    FLASH->ERWESTPT = EraseInit->EraseWebSetupTime*systemclk;
  }
}

/**
  * @brief  Initialize flash program time.
  * @param  ProgInit: 
  */
void FLASH_ProgramTimeInit(FLASH_ProgramInitTypeDef* ProgInit)
{
  ProgInit->ProgWebSetupHoldTime = FLASH_TIME_SLOW_NVS;
  ProgInit->Prog2SetupTime       = FLASH_TIME_NOR_PREPGS;
  ProgInit->ProgWebPulseWidth    = FLASH_TIME_NOR_HV;
}

/**
  * @brief  Initialize flash erase time.
  * @param  EraseInit: 
  */
void FLASH_EraseTimeInit(FLASH_EraseInitTypeDef* EraseInit)
{
  EraseInit->ErasePulseWidth    = 10000+FLASH_TIME_NOR_RCV;
  EraseInit->EraseWebPulseWidth = 10000;
  EraseInit->EraseWebSetupTime  = FLASH_TIME_SLOW_NVS;
}


/**
  * @}
  */

/** @defgroup FLASH_Exported_Functions_Group2 FLASH Memory Programming functions
  *  @brief   FLASH Memory Programming functions
  *
  * @{
  */

/**
  * @brief  program flash.
  * @param  Address:
  * @param  Data:
  */
void FLASH_Program(uint32_t* Address, uint32_t* Data)
{
	uint32_t addr = *Address;
	uint32_t da = *Data;

  uint32_t tempr;

  /* write row address */
  FLASH->ROWADDR = (addr & 0xFFFFFF00UL);

  /* Set pre-prog and flash mode prog*/
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE | FLASH_CTRL_PREPR);
  tempr |= (uint32_t)(FLASH_MODE_PROG | FLASH_PREPROG_ENABLE);
  FLASH->CTRL = tempr;
  
  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)da;

  /* Set pre-prog and flash mode prog*/
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE | FLASH_CTRL_PREPR);
  tempr |= (uint32_t)(FLASH_MODE_PROG | FLASH_PREPROG_DISABLE);
  FLASH->CTRL = tempr;

  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)da;

  /* PROG Start */
  FLASH->STRT = 0x000000FFUL;


  /* Process Unlocked */
  __NOP();
	__NOP();
	__NOP();
	__NOP();
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_READ);
  FLASH->CTRL = tempr;
  __NOP();
	__NOP();
	__NOP();
	__NOP();
}

/**
  * @brief  program flash.
  * @param  Address:
  * @param  Data:
  * @param  Size:
  */
void FLASH_ProgramMass(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  uint32_t waddr, wsize, rowsize, waddr_bk;

  uint32_t tsize = 0;

  uint32_t* pdata1  = Data;
  uint32_t* pdata2  = Data;
	
	uint32_t addr = *Address;
	uint32_t leng = *Size; /* in word */

  uint32_t tempr;

  int i=0;

  waddr = addr;
  wsize = leng*4;  /* in byte */


  do {
    if((waddr >= FLASH_CODE_BASE) &&(waddr <(FLASH_CODE_BASE+FLASH_CODE_SIZE) )) 
    {
      rowsize = FLASH_SIZE_ROW;
    }
    else if((waddr >= FLASH_DATA_BASE) &&(waddr <(FLASH_DATA_BASE+FLASH_DATA_SIZE) )) 
    {
      rowsize = FLASH_SIZE_ROW;
    }
    else
    {
      break;
    }

    if((waddr+wsize) > ((waddr&0xFFFFFF00UL)+rowsize))
    {
      wsize = ((waddr&0xFFFFFF00UL)+rowsize) - waddr;
    }

    /* write row address */
    FLASH->ROWADDR = (waddr & 0xFFFFFF00UL);

    /* Set pre-prog and flash mode prog*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE | FLASH_CTRL_PREPR);
    tempr |= (uint32_t)(FLASH_MODE_PROG | FLASH_PREPROG_ENABLE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    waddr_bk = waddr;
    for(i=0; i<wsize; i+=4)
    {
      *(uint32_t *)waddr = (uint32_t)(*pdata1++);
      waddr += 4;
    }

    /* Set pre-prog and flash mode prog*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE | FLASH_CTRL_PREPR);
    tempr |= (uint32_t)(FLASH_MODE_PROG | FLASH_PREPROG_DISABLE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    waddr = waddr_bk;
    for(i=0; i<wsize; i+=4)
    {
      *(uint32_t *)waddr = (uint32_t)(*pdata2++);
      waddr += 4;
    }

    /* PROG Start */
    FLASH->STRT = (0x000000FFUL);

    tsize += wsize;

    //waddr += wsize;
    wsize = leng*4 - tsize;

  } while(tsize < leng*4);

  __NOP();
	__NOP();
	__NOP();
	__NOP();
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_READ);
  FLASH->CTRL = tempr;
  __NOP();
	__NOP();
	__NOP();
	__NOP();
}

/**
  * @brief  erase flash sector.
  * @param  Address:
  * @param  SectorSize:
  */
void FLASH_EraseSector(uint32_t* Address, uint32_t* SectorSize)
{
  uint32_t addr = *Address & 0xFFFFFF00UL;
	uint32_t size = *SectorSize;
	
  uint32_t tempr;

  int i = 0;
 
  for(i=0; i<size; i++)
  {
    /* write row address */
    FLASH->ROWADDR = addr;

    /*flash mode set to READ*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_SECTORERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    if((addr >= FLASH_CODE_BASE) &&(addr <(FLASH_CODE_BASE+FLASH_CODE_SIZE) )) 
    {
      addr += (FLASH_SIZE_CODE_SECTOR<<8);
    }
    else
    {
      addr += (FLASH_SIZE_DATA_SECTOR<<8);
    }

    /* wait time */
  }
	
  __NOP();
	__NOP();
	__NOP();
	__NOP();
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_READ);
  FLASH->CTRL = tempr;
  __NOP();
	__NOP();
	__NOP();
	__NOP();
}

/**
  * @brief  erase flash block.
  * @param  Address:
  * @param  SectorSize:
  */
void FLASH_EraseBlock(uint32_t* Address, uint32_t* BlockSize)
{
  uint32_t addr = *Address & 0xFFFFFF00UL;
  uint32_t size = *BlockSize;

  uint32_t tempr;

  int i = 0;
 
  for(i=0; i<size; i++)
  {

    /* write row address */
    FLASH->ROWADDR = addr;

    /*flash mode set to READ*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_BLOCKERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    addr += (FLASH_SIZE_CODE_BLOCK<<8);

    /* wait time */
  }

  __NOP();
	__NOP();
	__NOP();
	__NOP();
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_READ);
  FLASH->CTRL = tempr;
  __NOP();
	__NOP();
	__NOP();
	__NOP();
}

/**
  * @brief  erase flash.
  * @param 
  */
void FLASH_EraseMass(void)
{
  uint32_t tempr;

  uint32_t addr = FLASH_CODE_BASE & 0xFFFFFF00UL;
 
  /*erase code blocks*/ 
  while(addr < (FLASH_CODE_BASE+FLASH_CODE_SIZE))
  {

    /* write row address */
    FLASH->ROWADDR = (addr);

    /*flash mode set to READ*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_BLOCKERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    addr += (FLASH_SIZE_CODE_BLOCK<<8);

    /* wait time */
  }

  /*erase data blocks*/ 
  addr = FLASH_DATA_BASE & 0xFFFFFF00UL;
  while(addr < (FLASH_DATA_BASE+FLASH_DATA_SIZE))
  {

    /* write row address */
    FLASH->ROWADDR = addr;

    /*flash mode set to READ*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_BLOCKERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0UL;

    addr += (FLASH_SIZE_DATA_BLOCK<<8);

    /* wait time */
  }

  __NOP();
	__NOP();
	__NOP();
	__NOP();
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_READ);
  FLASH->CTRL = tempr;
  __NOP();
	__NOP();
	__NOP();
	__NOP();
}


/**
  * @}
  */
  
/**
  * @}
  */
   

#elif (defined(XT32H0xxBMPW) || defined(XT32H0xxB))
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
 
/** @defgroup FLASH_Exported_Functions FLASH Exported Functions
  * @{
  */ 

/** @defgroup FLASH_Exported_Functions_Group1 FLASH Interface configuration functions
  *  @brief   FLASH Interface configuration functions 
  *
  * @{
  */
/**
  * @brief  flash set operation time base (1us).
  * @param  Cycle
  */
void FLASH_SetTimeBase(uint32_t Cycle)
{
	uint32_t tempr;
  tempr = FLASH->SMW_SET_TIMER;
  tempr &= (uint32_t)~((uint32_t)FLASH_TMR_GEN);
  tempr |= (uint32_t)(Cycle << FLASH_TMR_GEN_Pos);
  FLASH->CTRL = tempr;
	
}

/**
  * @brief  flash set read time base.
  * @param  Cycle
  */
void FLASH_SetReadTime(uint32_t Cycle)
{
  uint32_t tempr;
  tempr = FLASH->SMW_SET_TIMER;
  tempr &= (uint32_t)~((uint32_t)FLASH_TMR_RD);
  tempr |= (uint32_t)(Cycle << FLASH_TMR_RD_Pos);
  FLASH->CTRL = tempr;
	
}
/**
  * @}
  */

/** @defgroup FLASH_Exported_Functions_Group2 FLASH Memory Programming functions
  *  @brief   FLASH Memory Programming functions
  *
  * @{
  */
/**
  * @brief  Sets flash to read mode.
  */
void FLASH_ReadEnable(void)
{
  uint32_t tempr;

  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)FLASH_MODE_READ;
  FLASH->CTRL = tempr;
}



/**
  * @brief  program flash.
  * @param  Address:
  * @param  Data:
  */
void FLASH_Program(uint32_t* Address, uint32_t* Data)
{
	uint32_t addr = *Address;
	uint32_t da = *Data;

  uint32_t tempr;

  /* Set pre-prog and flash mode prog*/
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_PROG);
  FLASH->CTRL = tempr;
  
  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)da;

  /* Process Unlocked */
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_READ);
  FLASH->CTRL = tempr;
}

/**
  * @brief  program flash code area.
  * @param  Address:
  * @param  Data:
  * @param  Size:
  */
void FLASH_ProgramCode(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  uint32_t tsize = 0;

  uint32_t* pdata  = Data;
	
	uint32_t addr = *Address;
	uint32_t leng = *Size;

  uint32_t tempr;


	tsize = 0;

  do {
    if((addr < FLASH_CODE_BASE) || (addr >=(FLASH_CODE_BASE+FLASH_CODE_SIZE) )) 
    {
      break;
    }

    /* Set flash mode prog*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PROG);
    FLASH->CTRL = tempr;
    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)(*pdata++);
		/* Set flash mode read*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;

    addr += 4;
		tsize += 4;

  } while(tsize < leng);
}

/**
  * @brief  program flash data area.
  * @param  Address:
  * @param  Data:
  * @param  Size:
  */
void FLASH_ProgramData(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  uint32_t tsize = 0;

  uint32_t* pdata  = Data;
	
	uint32_t addr = *Address;
	uint32_t leng = *Size;

  uint32_t tempr;
	
  tsize = 0;


  do {
    if((addr < FLASH_DATA_BASE) || (addr >=(FLASH_DATA_BASE+FLASH_DATA_SIZE) )) 
    {
      break;
    }

    /* Set flash mode prog*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PROG);
    FLASH->CTRL = tempr;
    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)(*pdata++);
		/* Set flash mode read*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;

    addr += 4;
		tsize += 4;

  } while(tsize < leng);
}

/**
  * @brief  program flash info area.
  * @param  Address:
  * @param  Data:
  * @param  Size:
  */
void FLASH_ProgramInfo(uint32_t* Address, uint32_t* Data, uint32_t* Size)
{
  uint32_t tsize = 0;

  uint32_t* pdata  = Data;
	
	uint32_t addr = *Address;
	uint32_t leng = *Size;

  uint32_t tempr;
	
  tsize = 0;


  do {
    if((addr < FLASH_INFO_BASE) ||(addr >=(FLASH_INFO_BASE+FLASH_INFO_SIZE) )) 
    {
      break;
    }

    /* Set flash mode prog*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PROG);
    FLASH->CTRL = tempr;
    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)(*pdata++);
		/* Set flash mode read*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;

    addr += 4;
		tsize += 4;

  } while(tsize < leng);

}

/**
  * @brief  flash erase page.
  * @param  Address:
  * @param  PageSize:
  */
void HAL_FLASH_ErasePage(uint32_t* Address, uint32_t* PageSize)
{
  uint32_t addr = *Address & 0xFFFFE000UL;
	uint32_t size = *PageSize;

  uint32_t tempr;
	
  int i = 0;
 
  for(i=0; i<size; i++)
  {
    /*flash mode set to page erase*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PAGEERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;

    addr += (FLASH_SIZE_PAGE);
    /* wait time */
  }
}

/**
  * @brief  flash erase page in code area.
  * @param  Address:
  * @param  PageSize:
  */
void FLASH_EraseCode(uint32_t* Address, uint32_t* PageSize)
{
  uint32_t addr = *Address & 0xFFFFE000UL;
	uint32_t size = *PageSize;
	
  uint32_t tempr;

  int i = 0;
 
  for(i=0; i<size; i++)
  {
    if((addr < FLASH_CODE_BASE) || (addr >=(FLASH_CODE_BASE+FLASH_CODE_SIZE) )) 
    {
      break;
    }

    /*flash mode set to page erase*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PAGEERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;

    addr += (FLASH_SIZE_PAGE);
    /* wait time */
  }
}

/**
  * @brief  flash erase page in code area.
  * @param  Address:
  * @param  PageSize:
  */
void FLASH_EraseData(uint32_t* Address, uint32_t* PageSize)
{
  uint32_t addr = *Address & 0xFFFFE000UL;
	uint32_t size = *PageSize;

  uint32_t tempr;
	
  int i = 0;
 
  for(i=0; i<size; i++)
  {
    if((addr < FLASH_DATA_BASE) || (addr >=(FLASH_DATA_BASE+FLASH_DATA_SIZE) )) 
    {
      break;
    }

    /*flash mode set to page erase*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PAGEERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;

    addr += (FLASH_SIZE_PAGE);
    /* wait time */
  }
}

/**
  * @brief  flash erase info page.
  * @param  Address:
  * @param  PageSize:
  */
void FLASH_EraseInfo(uint32_t* Address, uint32_t* PageSize)
{
  uint32_t addr = *Address & 0xFFFFE000UL;
	uint32_t size = *PageSize;

  uint32_t tempr;

  int i = 0;
 
  for(i=0; i<size; i++)
  {
    if((addr < FLASH_INFO_BASE) || (addr >=(FLASH_INFO_BASE+FLASH_INFO_SIZE) )) 
    {
      break;
    }
 
		/*flash mode set to page erase*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PAGEERASE);
    FLASH->CTRL = tempr;

		/* Write address and data*/
		*(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
			
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;
		
		addr += (FLASH_SIZE_PAGE);
	}
}

/**
  * @brief  flash erase all pages in code and data area.
  */
void FLASH_EraseMass(void)
{
  uint32_t addr = FLASH_CODE_BASE & 0xFFFFE000UL;

  uint32_t tempr;
 
  /*erase code blocks*/ 
  while(addr < (FLASH_CODE_BASE+FLASH_CODE_SIZE))
  {

    /*flash mode set to READ*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PAGEERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;

    addr += (FLASH_SIZE_PAGE);

    /* wait time */
  }

  addr = FLASH_DATA_BASE & 0xFFFFE000UL;
 
  /*erase code blocks*/ 
  while(addr < (FLASH_DATA_BASE+FLASH_DATA_SIZE))
  {

    /*flash mode set to READ*/
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_PAGEERASE);
    FLASH->CTRL = tempr;

    /* Write address and data*/
    *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
    tempr = FLASH->CTRL;
    tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
    tempr |= (uint32_t)(FLASH_MODE_READ);
    FLASH->CTRL = tempr;

    addr += (FLASH_SIZE_PAGE);

    /* wait time */
  }
}

/**
  * @brief  flash erase all pages in chip exculding info pages.
  */
void FLASH_EraseChip(void)
{
	uint32_t addr = FLASH_CODE_BASE;

  uint32_t tempr;

  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_CHIPERASE);
  FLASH->CTRL = tempr;

  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_READ);
  FLASH->CTRL = tempr;
}

/**
  * @brief  flash erase all pages in chip inculding info pages.
  */
void FLASH_EraseChipWithInfo(void)
{
	uint32_t addr = FLASH_INFO_BASE;

  uint32_t tempr;
  
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_CHIPERASE);
  FLASH->CTRL = tempr;

  /* Write address and data*/
  *(uint32_t *)addr = (uint32_t)0xFFFFFFFFUL;
		
  tempr = FLASH->CTRL;
  tempr &= (uint32_t)~((uint32_t)FLASH_CTRL_MODE);
  tempr |= (uint32_t)(FLASH_MODE_READ);
  FLASH->CTRL = tempr;
}

/**
  * @}
  */
  
/**
  * @}
  */
#endif  /*XT32H0xxB*/
  /**
  * @}
  */ 

/**
  * @}
  */ 

