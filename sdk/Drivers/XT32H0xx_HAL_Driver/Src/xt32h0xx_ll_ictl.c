/**
  ******************************************************************************
  * @file    xt32h0xx_ll_ictl.c
  * @author  Software Team
  * @brief   ICTL LL module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */
#if defined(USE_FULL_LL_DRIVER)

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_ll_ictl.h"
#ifdef  USE_FULL_ASSERT
#include "xt32_assert.h"
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (ICTL)

/** @defgroup ICTL_LL ICTL
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @addtogroup ICTL_LL_Private_Macros
  * @{
  */

#define IS_LL_ICTL_IRQ_0_31(__VALUE__)              (((__VALUE__) & ~LL_ICTL_IRQ_ALL) == 0x00000000U)
#define IS_LL_ICTL_IRQ_32_63(__VALUE__)             (((__VALUE__) & ~LL_ICTL_IRQ_ALL) == 0x00000000U)
#define IS_LL_ICTL_FIQ_0_7(__VALUE__)             (((__VALUE__) & ~LL_ICTL_FIQ_ALL) == 0x00000000U)

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ICTL_LL_Exported_Functions
  * @{
  */

/** @addtogroup ICTL_LL_Exported_Functions_Group2
  * @{
  */

/**
  * @brief  De-initialize the ICTL registers to their default reset values.
  * @retval An ErrorStatus enumeration value:
  *          - 0x00: ICTL registers are de-initialized
  */
uint32_t LL_ICTL_DeInit(void)
{
  /* Interrupt mask register set to default reset values */
  LL_ICTL_WriteReg(IRQINTMASKL,   0x00000000U);
  LL_ICTL_WriteReg(IRQINTMASKH,   0x00000000U);
  LL_ICTL_WriteReg(FIQINTMASK,    0x00000000U);
  
  /* Software interrupt event register set to default reset values */
  LL_ICTL_WriteReg(IRQINTFORCEL, 0x00000000U);
  LL_ICTL_WriteReg(IRQINTFORCEH, 0x00000000U);
  LL_ICTL_WriteReg(FIQINTFORCE,  0x00000000U);
  
  /* Disable all interrupts */
  LL_ICTL_WriteReg(IRQINTENL,    0x00000000U);
  LL_ICTL_WriteReg(IRQINTENH,    0x00000000U);
  LL_ICTL_WriteReg(FIQINTEN,     0x00000000U);

  return 0x00u;
}

/**
  * @brief  Initialize the ICTL registers according to the specified parameters in ICTL_InitStruct.
  * @param  ICTL_InitStruct pointer to a @ref LL_ICTL_InitTypeDef structure.
  * @retval An ErrorStatus enumeration value:
  *          - 0x00: ICTL registers are initialized
  *          - any other value : wrong configuration
  */
uint32_t LL_ICTL_Init(LL_ICTL_InitTypeDef *ICTL_InitStruct)
{
  uint32_t status = 0x00u;

  /* Check the parameters */
  assert_param(IS_LL_ICTL_IRQ_0_31(ICTL_InitStruct->Irq_0_31));
  assert_param(IS_LL_ICTL_IRQ_32_63(ICTL_InitStruct->Irq_32_63));
  assert_param(IS_LL_ICTL_FIQ_0_7(ICTL_InitStruct->Fiq_0_7));

  assert_param(IS_FUNCTIONAL_STATE(ICTL_InitStruct->LineCommand));


  /* ENABLE LineCommand */
  if (ICTL_InitStruct->LineCommand != DISABLE)
  {
      /* Configure ICTL Irq in range from 0 to 31 */
    if (ICTL_InitStruct->Irq_0_31 != LL_ICTL_IRQ_NONE)
    {
      LL_ICTL_EnableIRQ_0_31(ICTL_InitStruct->Irq_0_31);
    }
    /* Configure ICTL Irq in range from 32 to 63 */
    if (ICTL_InitStruct->Irq_32_63 != LL_ICTL_IRQ_NONE)
    {
      LL_ICTL_EnableIRQ_32_63(ICTL_InitStruct->Irq_32_63);
    }
    /* Configure ICTL Fiq in range from 0 to 7 */
    if (ICTL_InitStruct->Fiq_0_7 != LL_ICTL_FIQ_NONE)
    {
      LL_ICTL_EnableFIQ(ICTL_InitStruct->Fiq_0_7);
    }
  }
  /* DISABLE LineCommand */
  else
  {
    /* De-configure ICTL Lines in range from 0 to 31 */
    LL_ICTL_DisableIRQ_0_31(ICTL_InitStruct->Irq_0_31);
    LL_ICTL_DisableIRQ_32_63(ICTL_InitStruct->Irq_32_63);
    LL_ICTL_DisableFIQ(ICTL_InitStruct->Fiq_0_7);
  }

  return status;
}

/**
  * @brief  Set each @ref LL_ICTL_InitTypeDef field to default value.
  * @param  ICTL_InitStruct Pointer to a @ref LL_ICTL_InitTypeDef structure.
  */
void LL_ICTL_StructInit(LL_ICTL_InitTypeDef *ICTL_InitStruct)
{
  ICTL_InitStruct->Irq_0_31      = LL_ICTL_IRQ_NONE;
  ICTL_InitStruct->Irq_32_63     = LL_ICTL_IRQ_NONE;
  ICTL_InitStruct->Fiq_0_7       = LL_ICTL_FIQ_NONE;
  ICTL_InitStruct->LineCommand    = DISABLE;
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

#endif /* defined (ICTL) */

/**
  * @}
  */

#endif /* USE_FULL_LL_DRIVER */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
