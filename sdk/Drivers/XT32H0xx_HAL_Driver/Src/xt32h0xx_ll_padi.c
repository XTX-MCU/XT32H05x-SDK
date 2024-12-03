/**
  ******************************************************************************
  * @file    xt32h0xx_ll_padi.c
  * @author  Software Team
  * @brief   PADI LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_padi.h"
#include "xt32h0xx_ll_bus.h"
#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (PADI) 

/** @addtogroup PADI_LL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup PADI_LL_Private_Macros
  * @{
  */
#define IS_LL_PADI_PAD(__VALUE__)          (((0x00u) < (__VALUE__)) && ((__VALUE__) <= (63u)))

#define IS_LL_PADI_DS(__VALUE__)           (((__VALUE__) == LL_PADI_DS_LOW)     ||\
                                            ((__VALUE__) == LL_PADI_DS_HIGH))

#define IS_LL_PADI_OUTPUT_TYPE(__VALUE__)  (((__VALUE__) == LL_PAD_PULLNO)  ||\
                                            ((__VALUE__) == LL_PAD_PULLUP)  || \
                                            ((__VALUE__) == LL_PAD_PULLDOWN))

#define IS_LL_PADI_PULL(__VALUE__)         (((__VALUE__) == LL_PADI_PULL_NO)   ||\
                                            ((__VALUE__) == LL_PADI_PULL_UP)   ||\
                                            ((__VALUE__) == LL_PADI_PULL_DOWN))

#define IS_LL_PADI_ALTERNATE(__VALUE__)    (((__VALUE__) == LL_PADI_AF_0  )   ||\
                                            ((__VALUE__) == LL_PADI_AF_1  )   ||\
                                            ((__VALUE__) == LL_PADI_AF_2  )   ||\
                                            ((__VALUE__) == LL_PADI_AF_3  )   ||\
                                            ((__VALUE__) == LL_PADI_AF_4  )   ||\
                                            ((__VALUE__) == LL_PADI_AF_5  )   ||\
                                            ((__VALUE__) == LL_PADI_AF_6  )   ||\
                                            ((__VALUE__) == LL_PADI_AF_7 ))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup PADI_LL_Exported_Functions
  * @{
  */

/** @addtogroup PADI_LL_Exported_Functions_Group2
  * @{
  */

/**
  * @brief  De-initialize PADI registers (Registers restored to their default values).
  * @param  PADIx PADI Port
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PADI registers are de-initialized
  *          - ERROR:   Wrong PADI Port
  */
ErrorStatus LL_PADI_DeInit(PADI_TypeDef *PADIx)
{
  ErrorStatus status = SUCCESS;

  /* Check the parameters */
  assert_param(IS_PADI_ALL_INSTANCE(PADIx));

  return (status);
}

/**
  * @brief  Initialize PADI registers according to the specified parameters in PADI_InitStruct.
  * @param  PADIx PADI Port
  * @param PADI_InitStruct pointer to a @ref LL_PADI_InitTypeDef structure
  *         that contains the configuration information for the specified PADI peripheral.
  * @retval An ErrorStatus enumeration value:
  *          - SUCCESS: PADI registers are initialized according to PADI_InitStruct content
  *          - ERROR:   Not applicable
  */
ErrorStatus LL_PADI_Init(PADI_TypeDef *PADIx, LL_PADI_InitTypeDef *PADI_InitStruct)
{
  uint32_t pinpos;
  uint32_t currentpin;

  /* Check the parameters */
  assert_param(IS_PADI_ALL_INSTANCE(PADIx));
  assert_param(IS_LL_PADI_PIN(PADI_InitStruct->Pad));
  assert_param(IS_LL_PADI_DS(PADI_InitStruct->DriveStrength));
  assert_param(IS_LL_PADI_PULL(PADI_InitStruct->Pull));
  assert_param(IS_LL_PADI_ALTERNATE(PADI_InitStruct->Alternate));

  /* ------------------------- Configure the port pins ---------------- */
  /* Configure the port pins */
  

  switch(PADI_InitStruct->Pull)
  {
    case LL_PADI_PULLUP:
      LL_PADI_EnablePullUp(PADI_InitStruct->Pad);
      break;
    case LL_PADI_PULLDOWN:
      LL_PADI_EnablePullDown(PADI_InitStruct->Pad);
      break;
    case LL_PADI_PULLNO:
    default:
      LL_PADI_DisablePullDown(PADI_InitStruct->Pad);
      LL_PADI_DisablePullUp(PADI_InitStruct->Pad);
      break;
  }

  switch(PADI_InitStruct->DriveStrength)
  {
    case LL_PADI_DS_LOW:
    default:
      LL_PADI_SetDriveStrengthLow(PADI_InitStruct->Pad);
      break;
    case LL_PADI_DS_HIGH:
      LL_PADI_SetDriveStrengthHigh(PADI_InitStruct->Pad);
      break;
  }

  LL_PADI_SetPinCfg(PADI_InitStruct->Pad, PADI_InitStruct->Alternate);

  return (SUCCESS);
}

/**
  * @brief Set each LL_PADI_InitTypeDef field to default value.
  * @param PADI_InitStruct pointer to a LL_PADI_InitTypeDef structure
  *                          whose fields will be set to default values.
  */

void LL_PADI_StructInit(LL_PADI_InitTypeDef *PADI_InitStruct)
{
  /* Reset PADI init structure parameters values */
  PADI_InitStruct->Pad        = 0;
  PADI_InitStruct->Pull       = LL_PADI_PULLNO;
  PADI_InitStruct->Alternate  = LL_PADI_AF_0;
  PADI_InitStruct->DriveStrength = LL_PADI_DS_LOW;
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

#endif /* defined (PADI) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

