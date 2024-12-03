/**
  ******************************************************************************
  * @file    xt32h0xx_i2c.c
  * @author  Software Team
  * @date    28 June 2022
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Inter-Integrated circuit (I2C):
  *           + Initialization and Configuration
  *           + Communications handling
  *           + I2C registers management
  *           + Data transfers management
  *           + DMA transfers management
  *           + Interrupts and flags management
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
#include "xt32h0xx_i2c.h"
#include "xt32h0xx_rcc.h"

#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup I2C I2C
  * @brief I2C driver modules
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup I2C_Exported_Functions I2C Exported Functions
  * @{
  */


/** @defgroup I2C_Exported_Functions_Group1 Initialization and Configuration functions
 *  @brief   Initialization and Configuration functions 
 *
  * @{
  */

/**
  * @brief  Deinitializes the I2Cx peripheral registers to their default reset values.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  */
void I2C_DeInit(I2C_TypeDef* I2Cx)
{
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  
  I2Cx->ENABLE &= (uint32_t)~((uint32_t)I2C_ENABLE_EN);
}

/**
  * @brief  Initializes the I2Cx peripheral according to the specified
  *         parameters in the I2C_InitStruct.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  I2C_InitStruct: pointer to a I2C_InitTypeDef structure that
  *         contains the configuration information for the specified I2C peripheral.
  */
void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct)
{
  uint32_t tmpreg = 0;

  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_MODE(I2C_InitStruct->I2C_Mode));

  /* Disable I2Cx Peripheral */
  I2Cx->ENABLE &= (uint32_t)~((uint32_t)I2C_ENABLE_EN);

  /*---------------------------- I2Cx Control Configuration ------------------*/
  tmpreg = I2Cx->CON;
  tmpreg &= (uint32_t)~((uint32_t)(I2C_CON_SPEED | I2C_CON_10ASLV | I2C_CON_10AMST | I2C_CON_STOPDETIFA));
  tmpreg |= (uint32_t)(I2C_InitStruct->I2C_SpeedMode | I2C_InitStruct->I2C_SlaveAddressing | I2C_InitStruct->I2C_MasterAddressing | I2C_CON_RESTARTEN);
  I2Cx->CON = tmpreg;

  /*---------------------------- I2Cx TIMING Configuration -------------------*/
  I2C_ConfigTiming(I2Cx, I2C_InitStruct, I2C_InitStruct->I2C_BaudRate);

  I2Cx->ACKGENERALCALL |= I2C_GCACK_ACK;  /* only for i2c_slave */

  I2Cx->SAR = I2C_InitStruct->I2C_SlaveAddress; /* only for i2c_slave*/
}

/**
  * @brief  Fills each I2C_InitStruct member with its default value.
  * @param  I2C_InitStruct: pointer to an I2C_InitTypeDef structure which will be initialized.
  */
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct)
{
  /*---------------- Reset I2C init structure parameters values --------------*/
  I2C_InitStruct->I2C_BaudRate = 100000;  
  I2C_InitStruct->I2C_Mode = I2C_MODE_MASTER;
  I2C_InitStruct->I2C_SlaveAddress = 0x3FF;
  I2C_InitStruct->I2C_SlaveAddressing = I2C_SLV_ADDRESSING_10BIT;
  I2C_InitStruct->I2C_MasterAddressing = I2C_MST_ADDRESSING_10BIT;
  I2C_InitStruct->I2C_SpeedMode = I2C_SPEED_STANDARD;
}

/**
  * @brief  Enables or disables the specified I2C peripheral.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  NewState: new state of the I2Cx peripheral. 
  *          This parameter can be: ENABLE or DISABLE.
  */
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* Enable the selected I2C peripheral */
     I2Cx->ENABLE |= ((uint32_t)I2C_ENABLE_EN);
  }
  else
  {
    /* Disable the selected I2C peripheral */
     I2Cx->ENABLE &= (uint32_t)~((uint32_t)I2C_ENABLE_EN);
  }
}

/**
  * @brief  Enables or disables the specified I2C software reset.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  */
void I2C_MasterAbortSendCmd(I2C_TypeDef* I2Cx)
{
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));

  I2Cx->ENABLE |= ((uint32_t)I2C_ENABLE_AB);
}

/**
  * @brief  Enables or disables the specified I2C interrupts.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  I2C_IT: specifies the I2C interrupts sources to be enabled or disabled. 
  *          This parameter can be any combination of the following values:
  *            @arg @ref I2C_IT_RX_UNDER 
  *            @arg @ref I2C_IT_RX_OVER  
  *            @arg @ref I2C_IT_RX_FULL  
  *            @arg @ref I2C_IT_TX_OVER  
  *            @arg @ref I2C_IT_TX_EMPTY 
  *            @arg @ref I2C_IT_RD_REQ   
  *            @arg @ref I2C_IT_TX_ABRT  
  *            @arg @ref I2C_IT_RX_DONE  
  *            @arg @ref I2C_IT_ACTIVITY 
  *            @arg @ref I2C_IT_STOP_DET 
  *            @arg @ref I2C_IT_START_DET
  *            @arg @ref I2C_IT_GEN_CALL 
  * @param  NewState: new state of the specified I2C interrupts.
  *          This parameter can be: ENABLE or DISABLE.
  */
void I2C_ITConfig(I2C_TypeDef* I2Cx, uint32_t I2C_IT, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_I2C_CONFIG_IT(I2C_IT));
  
  if (NewState != DISABLE)
  {
    /* Enable the selected I2C interrupts */
    I2Cx->INTRMASK |= I2C_IT;
  }
  else
  {
    /* Disable the selected I2C interrupts */
    I2Cx->INTRMASK &= (uint32_t)~((uint32_t)I2C_IT);
  }
}

/**
  * @brief  Enables or disables the I2C Clock stretching.
  * @param  I2Cx where x can be 1 or 2 to select the I2C peripheral.
  * @param  I2C_InitStruct Initial configure
  * @param  BaudRate Baudrate.
  */
void I2C_ConfigTiming(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct, uint32_t BaudRate)
{
  uint32_t tempr;

  uint32_t minscl_l;
  uint32_t minscl_h;
	uint32_t sclk;
	
	uint32_t lcnt;
  uint32_t hcnt;
	uint32_t spklen;
  
	uint32_t kbps = BaudRate;
	uint32_t tcnt;
  
	uint32_t sdasu = 0x64;
  uint32_t rxht = 1;
  uint32_t txht = 1;

  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  
  /*---------------------------- I2Cx XS_SPKLEN/XS_SCL_LCNT/XS_SCL_HCNT/SDA_SETUP/SDA_HOLD Configuration ------------------*/  
  if(I2Cx == I2C1)
  {
    sclk = RCC_GetI2C1CLKClock();
  }
  else
  {
    sclk = RCC_GetI2C2CLKClock();
  }

  if(I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_STANDARD)
  {
		//@100kbps
    minscl_l = 4700; //@ns
		minscl_h = 4000; //@ns
    spklen = 1;
		
		tcnt = 1000000000/kbps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
    
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(I2C_InitStruct->I2C_Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
		
    tempr = I2Cx->FSSPKLEN;
    tempr &= (uint32_t)~((uint32_t)I2C_FSSPKLEN_LEN);
    tempr |= (uint32_t)(spklen << I2C_FSSPKLEN_LEN_Pos);
    I2Cx->FSSPKLEN = tempr;

    I2Cx->SSSCLHCNT = (uint32_t)(hcnt - spklen - 7);
    I2Cx->SSSCLLCNT = (uint32_t)(lcnt - 1);
  }
  else if((I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_FAST) 
       && (BaudRate <= 400000))
  {
		//@400kbps
    minscl_l = 1300; //@ns
		minscl_h = 600; //@ns
    spklen = 1;
		
		tcnt = 1000000000/kbps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
 
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(I2C_InitStruct->I2C_Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
		
    tempr = I2Cx->FSSPKLEN;
    tempr &= (uint32_t)~((uint32_t)I2C_FSSPKLEN_LEN);
    tempr |= (uint32_t)(spklen << I2C_FSSPKLEN_LEN_Pos);
    I2Cx->FSSPKLEN = tempr;

    I2Cx->FSSCLHCNT = (uint32_t)(hcnt - spklen - 7);
    I2Cx->FSSCLLCNT = (uint32_t)(lcnt - 1);
  }
  else if((I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_FAST)
       && ((BaudRate > 400000) && (BaudRate <= 1000000)))
  {
		//@1Mbps
    minscl_l = 500; //@ns
		minscl_h = 260; //@ns
    spklen = 2;
		
		tcnt = 1000000000/kbps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
 
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(I2C_InitStruct->I2C_Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
    
    tempr = I2Cx->FSSPKLEN;
    tempr &= (uint32_t)~((uint32_t)I2C_FSSPKLEN_LEN);
    tempr |= (uint32_t)(spklen << I2C_FSSPKLEN_LEN_Pos);
    I2Cx->FSSPKLEN = tempr;

    I2Cx->FSSCLHCNT = (uint32_t)(hcnt - spklen - 7);
    I2Cx->FSSCLLCNT = (uint32_t)(lcnt - 1);
  }
  else if(I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_HIGH)
  {
		//@100pf 3.4Mbps
    minscl_l = 120; //@ns
		minscl_h = 60; //@ns
    spklen = 1;
		
		tcnt = 1000000000/kbps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
 
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(rxht > (lcnt - 1 - spklen - 3))
		{
		  rxht = lcnt -1 - spklen - 3;
		}
		if(I2C_InitStruct->I2C_Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
		
    tempr = I2Cx->HSSPKLEN;
    tempr &= (uint32_t)~((uint32_t)I2C_HSSPKLEN_LEN);
    tempr |= (uint32_t)(spklen << I2C_HSSPKLEN_LEN_Pos);
    I2Cx->HSSPKLEN = tempr;

    I2Cx->HSSCLHCNT = (uint32_t)(hcnt - spklen - 7);
    I2Cx->HSSCLLCNT = (uint32_t)(lcnt - 1);
  }
#if 0
  else if(I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_HIGH)
  {
		//@400pf 3.4Mbps 51M
    minscl_l = 320; //@ns
		minscl_h = 160; //@ns
    spklen = 1;
		
		tcnt = 1000000000/bps;
		
		if(tcnt > (minscl_l + minscl_h))
		{
			minscl_h = tcnt/2 - minscl_l/2 + minscl_h/2;
			minscl_l = tcnt - minscl_h;
		}
		else
		{
			//error, need to decrease kpbs
		}
		
    lcnt = (sclk/1000*minscl_l)/(1000000);
		hcnt = (sclk/1000*minscl_h)/(1000000);
		
		if(lcnt < (spklen+7+1))
		{
			//lcnt = (spklen+7);
			//error, need to increase sclk
		}
		if(hcnt < (2*spklen+5+7))
		{
			//hcnt = (spklen+5);
			//error, need to increase sclk
		}
 
		rxht = hcnt - spklen - 7 - spklen - 3;
		if(rxht > ((lcnt - 1)/2 - spklen - 3))
		{
		  rxht = (lcnt -1)/2 - spklen - 3;
		}
		if(I2C_InitStruct->I2C_Mode == I2C_MODE_SLAVE)
		{
			txht = spklen + 7;
		}
		else
		{
			txht = 1;
		}
		
    tempr = I2Cx->HSSPKLEN;
    tempr &= (uint32_t)~((uint32_t)I2C_HSSPKLEN_LEN);
    tempr |= (uint32_t)(spklen << I2C_HSSPKLEN_LEN_Pos);
    I2Cx->HSSPKLEN = tempr;

    I2Cx->HSSCLHCNT = (uint32_t)(hcnt - spklen - 7);
    I2Cx->HSSCLLCNT = (uint32_t)(lcnt - 1);
  }
#endif  
  //the amount of time delay (in terms of number of ic_clk clock periods)
  //default 0x64
	if(I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_STANDARD)
	{
		sdasu = sclk / 1000 * 250 / 1000000;
	}
	else if((I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_FAST)
       && (BaudRate <= 400000))
	{
		sdasu = sclk / 1000 * 100 / 1000000;
	}
  else if((I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_FAST)
       && ((BaudRate > 400000) && (BaudRate <= 1000000)))
	{
		sdasu = sclk / 1000 * 50 / 1000000;
	}
  else if(I2C_InitStruct->I2C_SpeedMode == I2C_SPEED_HIGH)
	{
		sdasu = sclk / 100000000;
	}
	
	I2Cx->SDASETUP = sdasu;
  
  //the hold time of SDA during transmit in both slave and master mode
  //default IC_DEFAULT_SDA_HOLD
  tempr = I2Cx->SDAHOLD;
  tempr &= (uint32_t)~((uint32_t)(I2C_SDAH_RX|I2C_SDAH_TX));
  tempr |= (uint32_t)((rxht << I2C_SDAH_RX_Pos)|(txht << I2C_SDAH_TX_Pos));
  I2Cx->SDAHOLD = tempr;
}

/**
  * @brief  Configures the slave address to be transmitted after start generation.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  Address: specifies the slave address to be programmed.
  * @note   This function should be called before generating start condition.
  */
void I2C_TargetAddressConfig(I2C_TypeDef* I2Cx, uint16_t Address)
{
  uint32_t tmpreg = 0;

  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_SLAVE_ADDRESS(Address));
               
  /* Get the old register value */
  tmpreg = I2Cx->TAR;

  /* Reset I2Cx SADD bit [9:0] */
  tmpreg &= (uint32_t)~((uint32_t)I2C_TAR_TAR);

  /* Set I2Cx SADD */
  tmpreg |= (uint32_t)((uint32_t)Address & I2C_TAR_TAR);

  /* Store the new register value */
  I2Cx->TAR = tmpreg;
}
  
/**
  * @brief  Enables or disables the I2C 10-bit addressing mode for the master.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  Mode: I2C Mode.
  */
void I2C_ModeConfig(I2C_TypeDef* I2Cx, uint32_t Mode)
{
  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_MODE(Mode));
  
  if (Mode == I2C_MODE_MASTER)
  {
    /* disalbe slave, enable master */
    I2Cx->CON |= I2C_MODE_MASTER;
  }
  else
  {
    /* Enable slave, disable master */
    I2Cx->CON &= (uint32_t)~((uint32_t)I2C_MODE_MASTER);
  }
} 

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions_Group2 Data transfers management functions
 *  @brief   Data transfers management functions 
 *
 * @{
 */  
  
/**
  * @brief  Sends a data byte through the I2Cx peripheral.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  Data: Byte to be transmitted..
  */
void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data)
{
  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  
  /* Write in the DR register the data to be sent */
  tempr = I2Cx->DATACMD;
  tempr &= (uint32_t)~(I2C_DATACMD_CMD|I2C_DATACMD_DAT);
  tempr |= (I2C_CMD_WRITE|(uint32_t)Data);

  I2Cx->DATACMD = tempr;
}

/**
  * @brief  Returns the most recent received data by the I2Cx peripheral.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @retval The value of the received data.
  */
uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx)
{
  uint32_t tempr;
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  
  /* Return the data in the DR register */
  tempr =  (uint8_t)(I2Cx->DATACMD & I2C_DATACMD_DAT);
  I2Cx->DATACMD |= I2C_CMD_READ;

  return tempr;
}  

/**
  * @brief  Master request received data by the I2Cx peripheral.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  */
void I2C_MasterReceiveDataRequest(I2C_TypeDef* I2Cx)
{
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  
  /* Return the data in the DR register */
  I2Cx->DATACMD |= I2C_CMD_READ;
}  

/**
  * @}
  */ 


/** @defgroup I2C_Exported_Functions_Group3 DMA transfers management functions
 *  @brief   DMA transfers management functions 
 *
 * @{
 */  
    
/**
  * @brief  Enables or disables the I2C DMA interface.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  I2C_DMAReq: specifies the I2C DMA transfer request to be enabled or disabled. 
  *          This parameter can be any combination of the following values:
  *            @arg @ref I2C_DMAREQ_TX Tx DMA transfer request
  *            @arg @ref I2C_DMAREQ_RX Rx DMA transfer request
  * @param  NewState: new state of the selected I2C DMA transfer request.
  *          This parameter can be: ENABLE or DISABLE.
  */
void I2C_DMACmd(I2C_TypeDef* I2Cx, uint32_t I2C_DMAReq, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_I2C_DMA_REQ(I2C_DMAReq));

  if (NewState != DISABLE)
  {
    /* Enable the selected I2C DMA requests */
    I2Cx->DMACR |= I2C_DMAReq;
  }
  else
  {
    /* Disable the selected I2C DMA requests */
    I2Cx->DMACR &= (uint32_t)~I2C_DMAReq;
  }
}
/**
  * @}
  */  


/** @defgroup I2C_Exported_Functions_Group4 Interrupts and flags management functions
 *  @brief   Interrupts and flags management functions 
 *
 * @{
 */  

/**
  * @brief  Checks whether the specified I2C flag is set or not.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  I2C_FLAG: specifies the flag to check. 
  *          This parameter can be one of the following values:
  *            @arg @ref I2C_STAT_ACTIVITY    
  *            @arg @ref I2C_STAT_TFNF        
  *            @arg @ref I2C_STAT_TFE         
  *            @arg @ref I2C_STAT_RFNE        
  *            @arg @ref I2C_STAT_RFF         
  *            @arg @ref I2C_STAT_MST_ACTIVITY
  *            @arg @ref I2C_STAT_SLV_ACTIVITY
  * @retval The new state of I2C_FLAG (SET or RESET).
  */
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG)
{
  uint32_t tmpreg = 0;
  FlagStatus bitstatus = RESET;
  
  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_GET_FLAG(I2C_FLAG));
  
  /* Get the ISR register value */
  tmpreg = I2Cx->STATUS;
  
  /* Get flag status */
  tmpreg &= I2C_FLAG;
  
  if(tmpreg != 0)
  {
    /* I2C_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* I2C_FLAG is reset */
    bitstatus = RESET;
  }
  return bitstatus;
} 

/**
  * @brief  Checks whether the specified I2C interrupt has occurred or not.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  I2C_IT: specifies the interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref I2C_IT_RX_UNDER 
  *            @arg @ref I2C_IT_RX_OVER  
  *            @arg @ref I2C_IT_RX_FULL  
  *            @arg @ref I2C_IT_TX_OVER  
  *            @arg @ref I2C_IT_TX_EMPTY 
  *            @arg @ref I2C_IT_RD_REQ   
  *            @arg @ref I2C_IT_TX_ABRT  
  *            @arg @ref I2C_IT_RX_DONE  
  *            @arg @ref I2C_IT_ACTIVITY 
  *            @arg @ref I2C_IT_STOP_DET 
  *            @arg @ref I2C_IT_START_DET
  *            @arg @ref I2C_IT_GEN_CALL 
  * @retval The new state of I2C_IT (SET or RESET).
  */
ITStatus I2C_GetITRawStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT)
{
  uint32_t tmpreg = 0;
  ITStatus bitstatus = RESET;
  uint32_t enablestatus = 0;

  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_GET_IT(I2C_IT));

  /* Get the ISR register value */
  tmpreg = I2Cx->RAWINTRSTAT;
  
  /* Get flag status */
  tmpreg &= I2C_IT;
  
  if(tmpreg != 0)
  {
    /* I2C_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* I2C_FLAG is reset */
    bitstatus = RESET;
  }

  /* Return the I2C_IT status */
  return bitstatus;
}

/**
  * @brief  Checks whether the specified I2C interrupt has occurred or not.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  I2C_IT: specifies the interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref I2C_IT_RX_UNDER 
  *            @arg @ref I2C_IT_RX_OVER  
  *            @arg @ref I2C_IT_RX_FULL  
  *            @arg @ref I2C_IT_TX_OVER  
  *            @arg @ref I2C_IT_TX_EMPTY 
  *            @arg @ref I2C_IT_RD_REQ   
  *            @arg @ref I2C_IT_TX_ABRT  
  *            @arg @ref I2C_IT_RX_DONE  
  *            @arg @ref I2C_IT_ACTIVITY 
  *            @arg @ref I2C_IT_STOP_DET 
  *            @arg @ref I2C_IT_START_DET
  *            @arg @ref I2C_IT_GEN_CALL 
  * @retval The new state of I2C_IT (SET or RESET).
  */
ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT)
{
  uint32_t tmpreg = 0;
  ITStatus bitstatus = RESET;
  uint32_t enablestatus = 0;

  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_GET_IT(I2C_IT));

  /* Get the ISR register value */
  tmpreg = I2Cx->INTRSTAT;
  
  /* Get flag status */
  tmpreg &= I2C_IT;
  
  if(tmpreg != 0)
  {
    /* I2C_FLAG is set */
    bitstatus = SET;
  }
  else
  {
    /* I2C_FLAG is reset */
    bitstatus = RESET;
  }

  /* Return the I2C_IT status */
  return bitstatus;
}

/**
  * @brief  Clears the I2Cx's interrupt pending bits.
  * @param  I2Cx: where x can be 1 or 2 to select the I2C peripheral.
  * @param  I2C_IT: specifies the interrupt pending bit to clear.
  *          This parameter can be any combination of the following values:
  *            @arg @ref I2C_IT_RX_UNDER 
  *            @arg @ref I2C_IT_RX_OVER  
  *            @arg @ref I2C_IT_RX_FULL  
  *            @arg @ref I2C_IT_TX_OVER  
  *            @arg @ref I2C_IT_TX_EMPTY 
  *            @arg @ref I2C_IT_RD_REQ   
  *            @arg @ref I2C_IT_TX_ABRT  
  *            @arg @ref I2C_IT_RX_DONE  
  *            @arg @ref I2C_IT_ACTIVITY 
  *            @arg @ref I2C_IT_STOP_DET 
  *            @arg @ref I2C_IT_START_DET
  *            @arg @ref I2C_IT_GEN_CALL 
  */
void I2C_ClearIT(I2C_TypeDef* I2Cx, uint32_t I2C_IT)
{
  uint32_t tempr;

  /* Check the parameters */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_CLEAR_IT(I2C_IT));

  /* Clear the selected flag */
  switch(I2C_IT)
  {
    case I2C_IT_RX_UNDER:
      tempr = I2Cx->CLRRXUNDER;
      break;
    case I2C_IT_RX_OVER:
      tempr = I2Cx->CLRRXOVER;
      break;
    case I2C_IT_TX_OVER:
      tempr = I2Cx->CLRTXOVER;
      break;
    case I2C_IT_RD_REQ:
      tempr = I2Cx->CLRRDREQ;
      break;
    case I2C_IT_TX_ABRT:
      tempr = I2Cx->CLRTXABRT;
      break;
    case I2C_IT_RX_DONE:
      tempr = I2Cx->CLRRXDONE;
      break;
    case I2C_IT_ACTIVITY:
      tempr = I2Cx->CLRACTIVITY;
      break;
    case I2C_IT_STOP_DET:
      tempr = I2Cx->CLRSTOPDET;
      break;
    case I2C_IT_START_DET:
      tempr = I2Cx->CLRSTARTDET;
      break;
    case I2C_IT_GEN_CALL:
      tempr = I2Cx->CLRGENCALL;
      break;
    default:
      tempr = I2Cx->CLRINTR;
      break;
  }
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

