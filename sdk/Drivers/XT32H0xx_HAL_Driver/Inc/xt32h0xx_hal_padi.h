/**
  ******************************************************************************
  * @file    xt32h0xx_hal_padi.h
  * @author  Software Team
  * @brief   Header file of PADI HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_PADI_H
#define XT32H0xx_HAL_PADI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup PADI PADI
  * @brief PADI HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @addtogroup PADI_Exported_Types 
  * @{
  */
/**
  * @brief   PAD Init structure definition
  */
typedef struct
{
  uint32_t Pad;                  /*!< Specifies the PADI pads to be configured.
                                   This parameter can be any value of 0 to 63 */
        
  uint32_t Pull;                 /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                                   This parameter can be a value of @ref PADI_pull no used */
        
  uint32_t Alternate;            /*!< Peripheral to be connected to the selected pins
                                    This parameter can be a value of @ref PADI_Alternate_function_selection no-used*/

  uint32_t DriveStrength;        /*!< Specifies the PADI pins to be configured.
                                      This parameter can be any value of @ref PADI_drivestrength  */

} PADI_InitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @addtogroup PADI_Exported_Constants 
  * @{
  */
/** @defgroup PAD_pins PAD pins
  * @{
  */
/**
  * @}
  */

/** @defgroup PADI_pull PADI pull
  * @brief PADI Pull-Up or Pull-Down Activation
  * @{
  */
#define PADI_PULLNO                    (0x00000000u)                           /*!< No Pull-up or Pull-down activation  */
#define PADI_PULLUP                    (0x00000001u)                           /*!< Pull-up activation                  */
#define PADI_PULLDOWN                  (0x00000002u)                           /*!< Pull-down activation                */
/**
  * @}
  */

/** @defgroup PADI_drivestrength PADI ds
  * @brief PADI Pull-Up or Pull-Down Activation
  * @{
  */
#define PADI_DS_LOW                    (0x00000000u)                           /*!< Drive Strength Low  */
#define PADI_DS_HIGH                   (0x00000001u)                           /*!< Drive Strength High */
/**
  * @}
  */

/** @defgroup PADI_Alternate_function_selection PADI ds
  * @brief PADI configure
  * @{
  */
#define PADI_AF_0                      (0x00000000u)                           /*!< Alternate function 0 */
#define PADI_AF_1                      (0x00000001u)                           /*!< Alternate function 1 */
#define PADI_AF_2                      (0x00000002u)                           /*!< Alternate function 2 */
#define PADI_AF_3                      (0x00000003u)                           /*!< Alternate function 3 */
#define PADI_AF_4                      (0x00000004u)                           /*!< Alternate function 4 */
#define PADI_AF_5                      (0x00000005u)                           /*!< Alternate function 5 */
#define PADI_AF_6                      (0x00000006u)                           /*!< Alternate function 6 */
#define PADI_AF_7                      (0x00000007u)                           /*!< Alternate function 7 */
/**
  * @}
  */

/** @defgroup PADI_define PADI definition
  * @{
  */
#if defined(XT32H0xxAMPW)
#include "xt32h0xxampw_hal_padi.h"
#elif defined(XT32H0xxBMPW)
#include "xt32h0xxbmpw_hal_padi.h"
#elif defined(XT32H0xxA)
#include "xt32h0xxampw_hal_padi.h"
#elif defined(XT32H0xxB)
#include "xt32h0xxb_hal_padi.h"
#endif /* XT32H0xxBMPW */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup PADI_Exported_Macros PADI Exported Macros
  * @{
  */

/**
  * @brief  Set alternate function.
  * @param  __PAD__ 
  *          This parameter can be PADI_PIN_x where x can be(0..63)
  * @param  __CFG__ 
  *          This parameter can be PADI_AF_x where x can be(0..7)
  * @retval None
  */
#define __HAL_PADI_SET_CFG(__PAD__, __CFG__)        (((__PAD__ >> 3) == 0) ? MODIFY_REG(PADI->PORTMUX_CFG_1, (0x0FUL << ((__PAD__ & 0x7UL) << 2) ), __CFG__) : \
                                                     ((__PAD__ >> 3) == 1) ? MODIFY_REG(PADI->PORTMUX_CFG_2, (0x0FUL << ((__PAD__ & 0x7UL) << 2) ), __CFG__) : \
                                                     ((__PAD__ >> 3) == 2) ? MODIFY_REG(PADI->PORTMUX_CFG_3, (0x0FUL << ((__PAD__ & 0x7UL) << 2) ), __CFG__) : \
                                                     ((__PAD__ >> 3) == 3) ? MODIFY_REG(PADI->PORTMUX_CFG_4, (0x0FUL << ((__PAD__ & 0x7UL) << 2) ), __CFG__) : \
                                                     ((__PAD__ >> 3) == 4) ? MODIFY_REG(PADI->PORTMUX_CFG_5, (0x0FUL << ((__PAD__ & 0x7UL) << 2) ), __CFG__) : \
                                                     ((__PAD__ >> 3) == 5) ? MODIFY_REG(PADI->PORTMUX_CFG_6, (0x0FUL << ((__PAD__ & 0x7UL) << 2) ), __CFG__) : \
                                                     ((__PAD__ >> 3) == 6) ? MODIFY_REG(PADI->PORTMUX_CFG_7, (0x0FUL << ((__PAD__ & 0x7UL) << 2) ), __CFG__) : \
                                                     MODIFY_REG(PADI->PORTMUX_CFG_8, (0x0FUL << ((__PAD__ & 0x7UL) << 2) ), __CFG__))

/**
  * @brief  Get alternate function.
  * @param  __PAD__ 
  *          This parameter can be PADI_PIN_x where x can be(0..63)
  * @retval  Alternate function 
  *          This parameter can be PADI_AF_x where x can be(0..7)
  */
#define __HAL_PADI_GET_CFG(__PAD__)                 (((__PAD__ >> 3) == 0) ? READ_BIT(PADI->PORTMUX_CFG_1, (0x0FUL << ((__PAD__ & 0x7UL) << 2) )) >> ((__PAD__ & 0x07UL) << 2) : \
                                                     ((__PAD__ >> 3) == 1) ? READ_BIT(PADI->PORTMUX_CFG_2, (0x0FUL << ((__PAD__ & 0x7UL) << 2) )) >> ((__PAD__ & 0x07UL) << 2) : \
                                                     ((__PAD__ >> 3) == 2) ? READ_BIT(PADI->PORTMUX_CFG_3, (0x0FUL << ((__PAD__ & 0x7UL) << 2) )) >> ((__PAD__ & 0x07UL) << 2) : \
                                                     ((__PAD__ >> 3) == 3) ? READ_BIT(PADI->PORTMUX_CFG_4, (0x0FUL << ((__PAD__ & 0x7UL) << 2) )) >> ((__PAD__ & 0x07UL) << 2) : \
                                                     ((__PAD__ >> 3) == 4) ? READ_BIT(PADI->PORTMUX_CFG_5, (0x0FUL << ((__PAD__ & 0x7UL) << 2) )) >> ((__PAD__ & 0x07UL) << 2) : \
                                                     ((__PAD__ >> 3) == 5) ? READ_BIT(PADI->PORTMUX_CFG_6, (0x0FUL << ((__PAD__ & 0x7UL) << 2) )) >> ((__PAD__ & 0x07UL) << 2) : \
                                                     ((__PAD__ >> 3) == 6) ? READ_BIT(PADI->PORTMUX_CFG_7, (0x0FUL << ((__PAD__ & 0x7UL) << 2) )) >> ((__PAD__ & 0x07UL) << 2) : \
                                                     READ_BIT(PADI->PORTMUX_CFG_8, (0x0FUL << ((__PAD__ & 0x7UL) << 2) )) >> ((__PAD__ & 0x07UL) << 2))

/**
  * @brief  Set PULLup.
  * @param  __PAD__ 
  *          This parameter can be PADI_PIN_x where x can be(0..63)
  * @param  __PULL__ 
  *          This parameter can be SET or RESET
  */
#define __HAL_PADI_SET_PULLUP(__PAD__, __PULL__)      (((__PAD__ >> 5) == 0) ? MODIFY_REG(PADI->IO_PULLUP_CFG_1, (0x01UL << (__PAD__ & 0x1F)), (__PULL__ << (__PAD__ & 0x1F))) : \
                                                       MODIFY_REG(PADI->IO_PULLUP_CFG_2, (0x01UL << (__PAD__ & 0x1F)), (__PULL__ << (__PAD__ & 0x1F))) )

/**
  * @brief  Get PULLup.
  * @param  __PAD__ 
  *          This parameter can be PADI_PIN_x where x can be(0..63)
  * @retval  __PULL__ 
  *          This parameter can be SET or RESET
  */
#define __HAL_PADI_GET_PULLUP(__PAD__, __PULL__)      (((__PAD__ >> 5) == 0) ? (READ_BIT(PADI->IO_PULLUP_CFG_1, (0x01UL << (__PAD__ & 0x1F))) >> (__PAD__ & 0x1F)) : \
                                                       (READ_BIT(PADI->IO_PULLUP_CFG_2, (0x01UL << (__PAD__ & 0x1F))) >> (__PAD__ & 0x1F)))

/**
  * @brief  Set PULLup.
  * @param  __PAD__ 
  *          This parameter can be PADI_PIN_x where x can be(0..63)
  * @param  __PULL__ 
  *          This parameter can be SET or RESET
  */
#define __HAL_PADI_SET_PULLDOWN(__PAD__, __PULL__)      (((__PAD__ >> 5) == 0) ? MODIFY_REG(PADI->IO_PULLDW_CFG_1, (0x01UL << (__PAD__ & 0x1F)), (__PULL__ << (__PAD__ & 0x1F))) : \
                                                          MODIFY_REG(PADI->IO_PULLDW_CFG_2, (0x01UL << (__PAD__ & 0x1F)), (__PULL__ << (__PAD__ & 0x1F))))

/**
  * @brief  Get PULLup.
  * @param  __PAD__ 
  *          This parameter can be PADI_PIN_x where x can be(0..63)
  * @retval  __PULL__ 
  *          This parameter can be SET or RESET
  */
#define __HAL_PADI_GET_PULLDOWN(__PAD__, __PULL__)      (((__PAD__ >> 5) == 0) ? (READ_BIT(PADI->IO_PULLDW_CFG_1, (0x01UL << (__PAD__ & 0x1F))) >> (__PAD__ & 0x1F)) : \
                                                         (READ_BIT(PADI->IO_PULLDW_CFG_2, (0x01UL << (__PAD__ & 0x1F))) >> (__PAD__ & 0x1F)))

/**
  * @brief  Set drive strength.
  * @param  __PAD__ 
  *          This parameter can be PADI_PIN_x where x can be(0..63)
  * @param  __DS__ 
  *          This parameter can be SET or RESET
  */
#define __HAL_PADI_SET_DS(__PAD__, __DS__)      (((__PAD__ >> 5) == 0) ? MODIFY_REG(PADI->IO_DS_CFG_1, (__PAD__ & 0x1F), __DS__) : \
                                                 MODIFY_REG(PADI->IO_DS_CFG_2, (__PAD__ & 0x1F), __DS__))

/**
  * @brief  Get drive strength.
  * @param  __PAD__ 
  *          This parameter can be PADI_PIN_x where x can be(0..63)
  * @retval  __DS__ 
  *          This parameter can be SET or RESET
  */
#define __HAL_PADI_GET_DS(__PAD__, __DS__)      (((__PAD__ >> 5) == 0) ? (READ_BIT(PADI->IO_DS_CFG_1, (__PAD__ & 0x1F)) >> (__PAD__ & 0x1F)) : \
                                                 (READ_BIT(PADI->IO_DS_CFG_2, (__PAD__ & 0x1F)) >> (__PAD__ & 0x1F)))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup PADI_Exported_Functions PADI Exported Functions
  * @{
  */

/** @defgroup PADI_Exported_Functions_Group1 Initialization/de-initialization functions
 *  @brief    Initialization and Configuration functions
 * @{
 */

/* Initialization and de-initialization functions *****************************/
void              HAL_PADI_Init(PADI_TypeDef  *PADIx, PADI_InitTypeDef *PADI_Init);
void              HAL_PADI_DeInit(PADI_TypeDef  *PADIx, uint32_t PADI_Pad);

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

#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_HAL_PADI_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
