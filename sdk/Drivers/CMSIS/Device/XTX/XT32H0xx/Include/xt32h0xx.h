/**
  ******************************************************************************
  * @file    xt32h0xx.h
  * @author  Software Team
  * @brief   CMSIS XT32H0xx Device Peripheral Access Layer Header File.
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The XT32H0xx device used in the target application
  *              - To use or not the peripherals drivers in application code(i.e.
  *                code will be based on direct access to peripherals registers
  *                rather than drivers API), this option is controlled by
  *                "#define USE_HAL_DRIVER"
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */
/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup xt32h0xx
  * @{
  */

#ifndef XT32H0xx_H
#define XT32H0xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief XT32 Family
  */
#if !defined (XT32H0)
#define XT32H0
#endif /* XT32H0 */

/* Uncomment the line below according to the target XT32H0 device used in your
   application
  */

#if !(defined (XT32H0xxA) || defined (XT32H0xxAMPW) || defined (XT32H0xxB) || defined (XT32H0xxBMPW)) 
#define XT32H0xxB    /*!< XT32H0xx Devices */
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */
#if !defined  (USE_HAL_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
  /*#define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

/**
  * @brief CMSIS Device version number $VERSION$
  */
#define __XT32H0_CMSIS_VERSION_MAIN   (0x01U) /*!< [31:24] main version */
#define __XT32H0_CMSIS_VERSION_SUB1   (0x04U) /*!< [23:16] sub1 version */
#define __XT32H0_CMSIS_VERSION_SUB2   (0x01U) /*!< [15:8]  sub2 version */
#define __XT32H0_CMSIS_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */
#define __XT32H0_CMSIS_VERSION        ((__XT32H0_CMSIS_VERSION_MAIN << 24)\
                                       |(__XT32H0_CMSIS_VERSION_SUB1 << 16)\
                                       |(__XT32H0_CMSIS_VERSION_SUB2 << 8 )\
                                       |(__XT32H0_CMSIS_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Device_Included
  * @{
  */

#if defined(XT32H0xxAMPW)
  #include "xt32h0xxampw.h"
#elif defined(XT32H0xxBMPW)
  #include "xt32h0xxbmpw.h"
#elif defined(XT32H0xxA)
  #include "xt32h0xxa.h"
#elif defined(XT32H0xxB)
  #include "xt32h0xxb.h"
#else
  #error "Please select first the target XT32H0xx device used in your application (in xt32h0xx.h file)"
#endif

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState, SignalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  SUCCESS = 0,
  ERROR = !SUCCESS
} ErrorStatus;

/**
  * @}
  */


/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/* Use of interrupt control for register exclusive access */
/* Atomic 32-bit register access macro to set one or several bits */
#define ATOMIC_SET_BIT(REG, BIT)                             \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    SET_BIT((REG), (BIT));                                   \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 32-bit register access macro to clear one or several bits */
#define ATOMIC_CLEAR_BIT(REG, BIT)                           \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    CLEAR_BIT((REG), (BIT));                                 \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 32-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK)            \
  do {                                                       \
    uint32_t primask;                                        \
    primask = __get_PRIMASK();                               \
    __set_PRIMASK(1);                                        \
    MODIFY_REG((REG), (CLEARMSK), (SETMASK));                \
    __set_PRIMASK(primask);                                  \
  } while(0)

/* Atomic 16-bit register access macro to set one or several bits */
#define ATOMIC_SETH_BIT(REG, BIT) ATOMIC_SET_BIT(REG, BIT)                                   \

/* Atomic 16-bit register access macro to clear one or several bits */
#define ATOMIC_CLEARH_BIT(REG, BIT) ATOMIC_CLEAR_BIT(REG, BIT)                               \

/* Atomic 16-bit register access macro to clear and set one or several bits */
#define ATOMIC_MODIFYH_REG(REG, CLEARMSK, SETMASK) ATOMIC_MODIFY_REG(REG, CLEARMSK, SETMASK) \

/*#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))*/
	
/* Data type conversion */
#define ABS(VAL)                (((VAL) > 0) ? (VAL) : (0-(VAL)))	
	
#define UINT32_TO_UINT16(VAL)   ((uint16_t)((VAL) & (0x0000FFFFUL)))	
#define UINT32_TO_UINT8(VAL)    ((uint8_t) ((VAL) & (0x000000FFUL)))	
#define UINT16_TO_UINT8(VAL)    ((uint8_t) ((VAL) & (0x00FFU)))	

#define UINT32_TO_INT16(VAL)   ((int16_t)((VAL) & (0x00007FFFUL)))	
#define UINT32_TO_INT8(VAL)    ((int8_t) ((VAL) & (0x0000007FUL)))	
#define UINT16_TO_INT8(VAL)    ((int8_t) ((VAL) & (0x007FU)))	

#define INT32_TO_UINT16(VAL)   ((uint16_t)(ABS(VAL) & (0x0000FFFFUL)))	
#define INT32_TO_UINT8(VAL)    ((uint8_t) (ABS(VAL) & (0x000000FFUL)))	
#define INT16_TO_UINT8(VAL)    ((uint8_t) (ABS(VAL) & (0x00FFU)))	
	
#define INT32_TO_INT16(VAL)    ((int16_t)(((VAL) & (0x0000FFFFUL))))	
#define INT32_TO_INT8(VAL)     ((int8_t) (((VAL) & (0x000000FFUL))))	
#define INT16_TO_INT8(VAL)     ((int8_t) (((VAL) & (0x00FFU))))	

#define UINT8_TO_UINT16        ((uint16_t)((VAL) & (0x00FFU)))
#define UINT8_TO_UINT32        ((uint32_t)((VAL) & (0x000000FFUL)))
#define UINT16_TO_UINT32       ((uint32_t)((VAL) & (0x0000FFFFUL)))

#define UINT8_TO_INT16         ((int16_t)((VAL) & (0x00FFU)))
#define UINT8_TO_INT32         ((int32_t)((VAL) & (0x000000FFUL)))
#define UINT16_TO_INT32        ((int32_t)((VAL) & (0x0000FFFFUL)))

#define INT8_TO_UINT16         ((uint16_t)(ABS(VAL) & (0x00FFU)))
#define INT8_TO_UINT32         ((uint32_t)(ABS(VAL) & (0x000000FFUL)))
#define INT16_TO_UINT32        ((uint32_t)(ABS(VAL) & (0x0000FFFFUL)))

#define INT8_TO_INT16          ((int16_t)(((VAL) > 0) ? ((VAL) & (0x007FUL)) : ((VAL) | (0xFF00U))))
#define INT8_TO_INT32          ((int32_t)(((VAL) > 0) ? ((VAL) & (0x0000007FUL)) : ((VAL) | (0xFFFFFF00UL))))
#define INT16_TO_INT32         ((int32_t)(((VAL) > 0) ? ((VAL) & (0x00007FFFUL)) : ((VAL) | (0xFFFF0000UL))))
/**
  * @}
  */

#if defined (USE_HAL_DRIVER)
 #include "xt32h0xx_hal.h"
#endif /* USE_HAL_DRIVER */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* XT32H0xx_H */
/**
  * @}
  */

/**
  * @}
  */




/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
