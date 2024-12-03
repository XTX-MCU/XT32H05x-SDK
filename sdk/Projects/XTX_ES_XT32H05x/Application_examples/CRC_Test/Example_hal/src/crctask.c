/**
  ******************************************************************************
  * @file    crctask.c
  * @author  Software Team
  * @brief   
  *          
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "crctask.h"

/** @addtogroup XT32H0xx_App
  * @{
  */

/** @addtogroup CRC_Task
  * @{
  */

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/** @addtogroup CRC_Task_Private_Define 
  * @{
  */
#define CRC32MPEG2_EXPECTEDVALUE         (0xE26D78BE)
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/** @addtogroup CRC_Task_Private_Variables 
  * @{
  */
CRC_HandleTypeDef hcrc;
static const uint32_t a32DataBuffer[CRC_TEST_BUFFER_SIZE] = 
{
  0x00000000, 0x55555555,0x11223344,0xeeffffee,
  0xfb1e8bf9, 0x1ce00cc1,0x2e321e51,0x9b798b58
};
 
uint32_t uwCRCValue = 0;
/**
  * @}
  */

/** @addtogroup CRC_Task_Private_Functions 
  * @{
  */

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
 * @brief  Crc Initialization Function
 */
void XT_Crc_Init(void)
{
	/*CRC32_MPEG2 */
    hcrc.Instance = CRC;
    hcrc.Init.CRCPoly = CRC_POLY_32;
    hcrc.Init.InitValue = 0xffffffff;
    hcrc.Init.DataInversionMode = CRC_DATA_INVERSION_NONE;
    hcrc.Init.OutputXorMode = CRC_OUTPUTDATA_XOR_DISABLE;
    hcrc.Init.OutputXorMask = 0x00000000;
    hcrc.InputDataFormat = CRC_INPUTDATA_FORMAT_WORDS;
    if (HAL_CRC_Init(&hcrc) != HAL_OK)
    {
      /* Error_Handler */
    }
}


/**
  * @}
  */
/** @addtogroup CRC_Task_Exported_Functions 
  * @{
  */

/**
  * @brief  This function is executed.
  */
void XT_Crc_Task(void)
{
    /* USER CODE */
    uwCRCValue = HAL_CRC_Calculate(&hcrc, (uint32_t *)a32DataBuffer, CRC_TEST_BUFFER_SIZE /*BUFFER_SIZE*/);
    /* Compare the CRC value with the Expected  */
    if (uwCRCValue != CRC32MPEG2_EXPECTEDVALUE)
    {
        /* Wrong CRC value: enter Error_Handler */   
        Error_Handle();  
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

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
