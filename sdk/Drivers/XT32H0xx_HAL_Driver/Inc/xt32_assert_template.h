/**
  ******************************************************************************
  * @file    xt32_assert.h
  * @author  Software Team
  * @brief   XT32 assert template file.
  *          This file should be copied to the application folder and renamed
  *          to xt32_assert.h.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.. 
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32_ASSERT_H
#define XT32_ASSERT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Includes ------------------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#ifdef  USE_FULL_ASSERT
/**
  * @brief  The assert_param macro is used for functions parameters check.
  * @param  expr: If expr is false, it calls assert_failed function
  *         which reports the name of the source file and the source
  *         line number of the call that failed.
  *         If expr is true, it returns no value.
  * @retval None
  */
#define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif

#endif /* XT32_ASSERT_H */


/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
