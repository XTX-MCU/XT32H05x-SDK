/**
  ******************************************************************************
  * @file    xt32h0xx_hal_padi.c
  * @author  Software Team
  * @brief   PADI HAL module driver.
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup PADI
  * @{
  */
#ifdef HAL_PADI_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/** @addtogroup PADI_Private_Constants
  * @{
  */
#define PADI_NUMBER                    (16u)
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup PADI_Private_Macros PADI Private Macros
  * @{
  */
#define IS_PADI_PAD(__PAD__)        (((__PIN__) >= 0 ) && ((__PIN__) <= 63 ))

#define IS_PADI_PULL(__MODE__)      (((__MODE__) == PADI_PULLNO)           ||\
                                     ((__MODE__) == PADI_PULLUP)           ||\
                                     ((__MODE__) == PADI_PULLDOWN))

#define IS_PADI_CFG(__CFG__)        (((__CFG__) == PADI_AF_0)   || \
                                     ((__CFG__) == PADI_AF_1)   || \
                                     ((__CFG__) == PADI_AF_2)   || \
                                     ((__CFG__) == PADI_AF_3)   || \
                                     ((__CFG__) == PADI_AF_4)   || \
                                     ((__CFG__) == PADI_AF_5)   || \
                                     ((__CFG__) == PADI_AF_6)   || \
                                     ((__CFG__) == PADI_AF_7))

#define IS_PADI_DS(__DS__)          (((__DS__) == PADI_DS_LOW)  ||\
                                     ((__DS__) == PADI_DS_HIGH))

/**
  * @}
  */
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup PADI_Exported_Functions
  * @{
  */

/** @addtogroup PADI_Exported_Functions_Group1
  *  @brief    Initialization and Configuration functions
  *
  * @{
  */

/**
  * @brief  Initialize the PADIx peripheral according to the specified parameters in the PADI_Init.
  * @param  PADIx where x can be (A..F) to select the PADI peripheral for XT32H0xx family
  * @param  PADI_Init pointer to a PADI_InitTypeDef structure that contains
  *         the configuration information for the specified PADI peripheral.
  */
void HAL_PADI_Init(PADI_TypeDef  *PADIx, PADI_InitTypeDef *PADI_Init)
{
//  uint32_t position = 0x00u;
//  uint32_t iocurrent;
//  uint32_t temp;

  /* Check the parameters */
  assert_param(IS_PADI_ALL_INSTANCE(PADIx));
  assert_param(IS_PADI_PAD(PADI_Init->Pad));
  assert_param(IS_PADI_PULL(PADI_Init->Pull));
  assert_param(IS_PADI_CFG(PADI_Init->Alternet));
  assert_param(IS_PADI_DS(PADI_Init->DriveStrength));

  /* Configure the port pins */
  switch(PADI_Init->Pull)
  {
    case PADI_PULLUP:
      __HAL_PADI_SET_PULLDOWN(PADI_Init->Pad, RESET);
      __HAL_PADI_SET_PULLUP(PADI_Init->Pad, SET);
      break;
    case PADI_PULLDOWN:
      __HAL_PADI_SET_PULLUP(PADI_Init->Pad, RESET);
      __HAL_PADI_SET_PULLDOWN(PADI_Init->Pad, SET);
      break;
    case PADI_PULLNO:
    default:
      __HAL_PADI_SET_PULLUP(PADI_Init->Pad, RESET);
      __HAL_PADI_SET_PULLDOWN(PADI_Init->Pad, RESET);
      break;
  }

  __HAL_PADI_SET_CFG(PADI_Init->Pad, PADI_Init->Alternate);
  __HAL_PADI_SET_DS(PADI_Init->Pad, PADI_Init->DriveStrength);
}

/**
  * @brief  De-initialize the PADIx peripheral registers to their default reset values.
  * @param  PADIx where x can be (A..F) to select the PADI peripheral for XT32H0xx family
  * @param  PADI_Pad specifies the port bit to be written.
  *         This parameter can be any combination of PADI_Pin_x where x can be (0..15).
  */
void HAL_PADI_DeInit(PADI_TypeDef  *PADIx, uint32_t PADI_Pad)
{
  /* Check the parameters */
  assert_param(IS_PADI_ALL_INSTANCE(PADIx));
  assert_param(IS_PADI_PAD(PADI_Pad));

  /* Configure the port pins */
  __HAL_PADI_SET_PULLUP(PADI_Pad, RESET);
  __HAL_PADI_SET_PULLDOWN(PADI_Pad, RESET);
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_PADI_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
