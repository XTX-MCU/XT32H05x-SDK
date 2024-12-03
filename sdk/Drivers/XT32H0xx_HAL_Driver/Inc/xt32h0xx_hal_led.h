/**
  ******************************************************************************
  * @file    xt32h0xx_hal_led.h
  * @author  Software Team
  * @brief   Header file of LED HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech.
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_LED_H
#define XT32H0xx_HAL_LED_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup LED
  * @{
  */

/** @addtogroup LED_Private_Constants 
  * @{
  */
#define LED_COM_MAX_NUM        (8)
#define LED_SEG_MAX_NUM        (9)
/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup LED_Exported_Types LED Exported Types
  * @{
  */

/**
  * @brief  LED HAL State Structure definition
  */
typedef enum
{
  HAL_LED_STATE_RESET     = 0x00U,  /*!< LED not yet initialized or disabled */
  HAL_LED_STATE_READY     = 0x01U,  /*!< LED initialized and ready for use   */
  HAL_LED_STATE_BUSY      = 0x02U,  /*!< LED internal process is ongoing     */
  HAL_LED_STATE_TIMEOUT   = 0x03U,  /*!< LED timeout state                   */
  HAL_LED_STATE_ERROR     = 0x04U   /*!< LED error state                     */
} HAL_LED_StateTypeDef;

/**
  * @brief LED Init Structure definition
  */
typedef struct __LED_SEGTypeDef
{
  uint32_t Index;                      /*<! the value is between 0 to 8 */
  uint32_t BrightnessStep; 
  uint32_t BrightnessMax; 
} LED_SEGTypeDef;

typedef struct
{
  uint32_t ComEnable;                  /*!< COM Enable
                                            @ref LED_COM_ENABLE. */

  uint32_t SegEnable;                  /*!< Enable segment 
                                            @ref LED_SEG_ENABLE. */

  uint32_t Scan_Feq;                   /*!< \@frames per second. i.g. 30,60,100,120 
                                          divider = SCLK / frame period / Scan_Feq */

  uint32_t Display_Mode;                /*!< LED display mode 
                                            @ref LED_Display_MODE */

  uint32_t Dead_Time;                  /*!< COM period = 256+dead time, frame period = COM_Period * ComScanNumber */

  uint32_t Current_Bias;               /*!< Current bias tune */
  uint32_t Bright_Step;                /*!< Brightness step */
  uint32_t SegBright_Max[LED_SEG_MAX_NUM];                /*!< Segment brightness maximum */

  uint32_t* pScreen_Buffer;            /*!< A pointer to screen buffer */

} LED_InitTypeDef;

/**
  * @brief  LED Handle Structure definition
  */
typedef struct __LED_HandleTypeDef
{
  LED_TypeDef                 *Instance;   /*!< Register base address        */

  LED_InitTypeDef             Init;        /*!< LED configuration parameters */

  HAL_LockTypeDef             Lock;        /*!< LED Locking object           */

  __IO HAL_LED_StateTypeDef   State;       /*!< LED communication state      */

  DMA_HandleTypeDef           *hdma;       /*!< LED DMA handle parameters    */
	
	uint32_t                    *pShadow;    /*!< LED shadow buffer for direct display */

#if (USE_HAL_LED_REGISTER_CALLBACKS == 1)
  void (* TfrCpltCallback)(struct __LED_HandleTypeDef *hled);
  void (* ErrorCallback)(struct __LED_HandleTypeDef *hled);
  void (* AbortCpltCallback)(struct __LED_HandleTypeDef *hled);

  void (* MspInitCallback)(struct __LED_HandleTypeDef *hled);
  void (* MspDeInitCallback)(struct __LED_HandleTypeDef *hled);

#endif  /* USE_HAL_LED_REGISTER_CALLBACKS */
  
} LED_HandleTypeDef;

#if (USE_HAL_LED_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL LED Callback ID enumeration definition
  */
typedef enum
{
  HAL_LED_TFR_COMPLETE_CB_ID      = 0x00U,    /*!< LED Master Tx Transfer completed callback ID  */
  HAL_LED_ERROR_CB_ID             = 0x01U,    /*!< LED Error callback ID                         */
  HAL_LED_ABORT_CB_ID             = 0x02U,    /*!< LED Abort callback ID                         */
  HAL_LED_MSPINIT_CB_ID           = 0x03U,    /*!< LED Msp Init callback ID                      */
  HAL_LED_MSPDEINIT_CB_ID         = 0x04U     /*!< LED Msp DeInit callback ID                    */
} HAL_LED_CallbackIDTypeDef;

/**
  * @brief  HAL LED Callback pointer definition
  */
typedef  void (*pLED_CallbackTypeDef)(LED_HandleTypeDef *hled);

#endif /*USE_HAL_LED_REGISTER_CALLBACKS*/
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup LED_Exported_Constants LED Exported Constants
  * @{
  */

/** @defgroup LED_Display_MODE LED display Mode
  * @{
  */
#define LED_RMODE_ONOFF                (0x00000000U )                          /*!< On-off mode */
#define LED_RMODE_BRIGHT               (LED_MODE_RMD)                          /*!< Brightness mode */
/**
  * @}
  */

/** @defgroup LED_OPERATION_MODE LED panel operation Mode
  * @{
  */
#define LED_DMODE_NORMAL               (0x00000000U )                          /*!< operate in normal mode */
#define LED_DMODE_DIMMING              (LED_MODE_DMD)                          /*!< operate in dimming mode */
/**
  * @}
  */

/** @defgroup LED_COM_ENABLE LED COM enable
  * @{
  */
#define LED_ENABLE_COM0                (LED_CTRL_CE_0)
#define LED_ENABLE_COM1                (LED_CTRL_CE_1) 
#define LED_ENABLE_COM2                (LED_CTRL_CE_2) 
#define LED_ENABLE_COM3                (LED_CTRL_CE_3) 
#define LED_ENABLE_COM4                (LED_CTRL_CE_4) 
#define LED_ENABLE_COM5                (LED_CTRL_CE_5) 
#define LED_ENABLE_COM6                (LED_CTRL_CE_6) 
#define LED_ENABLE_COM7                (LED_CTRL_CE_7) 
#define LED_ENABLE_COMALL              (LED_CTRL_CE_0 | \
                                        LED_CTRL_CE_1 | \
                                        LED_CTRL_CE_2 | \
                                        LED_CTRL_CE_3 | \
                                        LED_CTRL_CE_4 | \
                                        LED_CTRL_CE_5 | \
                                        LED_CTRL_CE_6 | \
                                        LED_CTRL_CE_7) 
/**
  * @}
  */

/** @defgroup LED_SEG_ENABLE LED SEG enable
  * @{
  */
#define LED_ENABLE_SEG0                (LED_CTRL_SE_0)
#define LED_ENABLE_SEG1                (LED_CTRL_SE_1) 
#define LED_ENABLE_SEG2                (LED_CTRL_SE_2) 
#define LED_ENABLE_SEG3                (LED_CTRL_SE_3) 
#define LED_ENABLE_SEG4                (LED_CTRL_SE_4) 
#define LED_ENABLE_SEG5                (LED_CTRL_SE_5) 
#define LED_ENABLE_SEG6                (LED_CTRL_SE_6) 
#define LED_ENABLE_SEG7                (LED_CTRL_SE_7) 
#define LED_ENABLE_SEG8                (LED_CTRL_SE_8) 
#define LED_ENABLE_SEGALL              (LED_CTRL_SE_0 | \
                                        LED_CTRL_SE_1 | \
                                        LED_CTRL_SE_2 | \
                                        LED_CTRL_SE_3 | \
                                        LED_CTRL_SE_4 | \
                                        LED_CTRL_SE_5 | \
                                        LED_CTRL_SE_6 | \
                                        LED_CTRL_SE_7 | \
                                        LED_CTRL_SE_8) 
/**
  * @}
  */

/** @defgroup LED_DIMMING_STEP LED dimming step
  * @{
  */
#define LED_DIMMING_STEP_16            (0x00000000U)                           /*!< 1/16 */
#define LED_DIMMING_STEP_8             (LED_MODE_DIMS_0)                       /*!< 1/8  */
#define LED_DIMMING_STEP_4             (LED_MODE_DIMS_1)                       /*!< 1/4  */
#define LED_DIMMING_STEP_2             (LED_MODE_DIMS_1|LED_MODE_DIMS_0)       /*!< 1/2  */
#define LED_DIMMING_STEP_1             (LED_MODE_DIMS_2)                       /*!< 1    */
/**
  * @}
  */

/** @defgroup LED_Flag LED Flag
  * @{
  */
#define LED_FLAG_UIF                   (LED_STATUS_UIF)                        /*!<  */
#define LED_FLAG_FIF                   (LED_STATUS_FIF)                        /*!<  */
#define LED_FLAG_CIF                   (LED_STATUS_CIF)                        /*!<  */
#define LED_FLAG_PIF                   (LED_STATUS_PIF)                        /*!<  */
/**
  * @}
  */

/** @defgroup LED_INT LED interrupt enable
  * @{
  */
#define LED_INT_UIE                    (LED_CTRL_UIE)                          /*!<  */
#define LED_INT_FIE                    (LED_CTRL_FIE)                          /*!<  */
#define LED_INT_CIE                    (LED_CTRL_CIE)                          /*!<  */
#define LED_INT_PIE                    (LED_CTRL_PIE)                          /*!<  */
/**
  * @}
  */

/** @defgroup LED_DMAREQ LED DMA requeset
  * @{
  */
#define LED_DMAREQ_UDE                 (LED_CTRL_UDE)                          /*!<  */
#define LED_DMAREQ_FDE                 (LED_CTRL_FDE)                          /*!<  */
#define LED_DMAREQ_CDE                 (LED_CTRL_CDE)                          /*!<  */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup LED_Exported_Macros LED Exported Macros
  * @{
  */

/** @brief Reset LED handle state.
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_LED_STATE_RESET)

/** @brief LED update generate (reset).
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_UPDATE_GENERATE(__HANDLE__) SET_BIT((__HANDLE__)->Instance->EG, LED_EG_UG)

/** @brief LED enable interrupt.
  * @param  __HANDLE__ LED handle.
  * @param  __INTERRUPT__ LED interrupt.
  *         @arg @ref LED_INT_UIE
  *         @arg @ref LED_INT_FIE
  *         @arg @ref LED_INT_CIE
  *         @arg @ref LED_INT_PIE
  * @retval None
  */
#define __HAL_LED_INTERRUPT_ENABLE(__HANDLE__, __INTERRUPT__) SET_BIT((__HANDLE__)->Instance->CTRL, (__INTERRUPT__))

/** @brief LED disable interrupt.
  * @param  __HANDLE__ LED handle.
  * @param  __INTERRUPT__ LED interrupt.
  *         @arg @ref LED_INT_UIE
  *         @arg @ref LED_INT_FIE
  *         @arg @ref LED_INT_CIE
  *         @arg @ref LED_INT_PIE
  * @retval None
  */
#define __HAL_LED_INTERRUPT_DISABLE(__HANDLE__, __INTERRUPT__) CLEAR_BIT((__HANDLE__)->Instance->CTRL, (__INTERRUPT__))

/** @brief Check LED interrupt is enabled.
  * @param  __HANDLE__ LED handle.
  * @param  __INTERRUPT__ LED interrupt.
  *         @arg @ref LED_INT_UIE
  *         @arg @ref LED_INT_FIE
  *         @arg @ref LED_INT_CIE
  *         @arg @ref LED_INT_PIE
  * @retval SET or RESET
  */
#define __HAL_LED_INTERRUPT_ISENABLED(__HANDLE__, __INTERRUPT__) ((READ_BIT((__HANDLE__)->Instance->CTRL, (__INTERRUPT__))) ? SET : RESET)

/** @brief LED enable dma request.
  * @param  __HANDLE__ LED handle.
  * @param  __DMAREQ__ LED DMA request.
  *         @arg @ref LED_DMAREQ_UDE
  *         @arg @ref LED_DMAREQ_FDE
  *         @arg @ref LED_DMAREQ_CDE
  * @retval None
  */
#define __HAL_LED_DMAREQ_ENABLE(__HANDLE__, __DMAREQ__) SET_BIT((__HANDLE__)->Instance->CTRL, (__DMAREQ__))

/** @brief LED Disable dma request.
  * @param  __HANDLE__ LED handle.
  * @param  __DMAREQ__ LED DMA request.
  *         @arg @ref LED_DMAREQ_UDE
  *         @arg @ref LED_DMAREQ_FDE
  *         @arg @ref LED_DMAREQ_CDE
  * @retval None
  */
#define __HAL_LED_DMAREQ_DISABLE(__HANDLE__, __DMAREQ__) CLEAR_BIT((__HANDLE__)->Instance->CTRL, (__DMAREQ__))

/** @brief Check LED dma request is enabled.
  * @param  __HANDLE__ LED handle.
  * @param  __DMAREQ__ LED DMA request.
  *         @arg @ref LED_DMAREQ_UDE
  *         @arg @ref LED_DMAREQ_FDE
  *         @arg @ref LED_DMAREQ_CDE
  * @retval SET or RESET
  */
#define __HAL_LED_DMAREQ_ISENABLED(__HANDLE__, __DMAREQ__) ((READ_BIT((__HANDLE__)->Instance->CTRL, (__DMAREQ__))) ? SET : RESET)

/** @brief LED enable COM.
  * @param  __HANDLE__ LED handle.
  * @param  __COM__ LED COM.
  * @retval None
  */
#define __HAL_LED_COM_ENABLE(__HANDLE__, __COM__) MODIFY_REG((__HANDLE__)->Instance->CTRL, LED_CTRL_CE, (__COM__))

/** @brief LED enable SEG.
  * @param  __HANDLE__ LED handle.
  * @param  __SEG__ LED SEG.
  * @retval None
  */
#define __HAL_LED_SEG_ENABLE(__HANDLE__, __SEG__) MODIFY_REG((__HANDLE__)->Instance->CTRL, LED_CTRL_SE, (__SEG__))

/** @brief LED enable .
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_ENABLE(__HANDLE__) SET_BIT((__HANDLE__)->Instance->CTRL, LED_CTRL_LEDEN)

/** @brief LED disable .
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_DISABLE(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->CTRL, LED_CTRL_LEDEN)

/** @brief LED Set interpolator.
  * @param  __HANDLE__ LED handle.
  * @param  __INTERPOLATOR__ LED interpolator.
  * @retval None
  */
#define __HAL_LED_SET_INTERPOLATOR(__HANDLE__, __INTERPOLATOR__) MODIFY_REG((__HANDLE__)->Instance->CFG, LED_CFG_IFN, (__INTERPOLATOR__))

/** @brief LED Set dead time.
  * @param  __HANDLE__ LED handle.
  * @param  __DEADTIME__ LED dead time.
  * @retval None
  */
#define __HAL_LED_SET_DEADTIME(__HANDLE__, __DEADTIME__) MODIFY_REG((__HANDLE__)->Instance->CFG, LED_CFG_DTW, (__DEADTIME__))

/** @brief LED Set prescaler.
  * @param  __HANDLE__ LED handle.
  * @param  __PRESCALER__ LED dead time.
  * @retval None
  */
#define __HAL_LED_SET_PRESCALER(__HANDLE__, __PRESCALER__) MODIFY_REG((__HANDLE__)->Instance->CFG, LED_CFG_PSC, (__PRESCALER__))

/** @brief LED Set RMODE ONOFF.
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_SET_RUNMODE_ONOFF(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->MODE, LED_MODE_RMD)

/** @brief LED Set RMODE DUTY.
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_SET_RUNMODE_DUTY(__HANDLE__) SET_BIT((__HANDLE__)->Instance->MODE, LED_MODE_RMD)

/** @brief LED Set frame number in display buffer.
  * @param  __HANDLE__ LED handle.
	* @param __NUM__ frame number in display buffer
  * @retval None
  */
#define __HAL_LED_SET_FRAMENUMINBUFFER(__HANDLE__, __NUM__) MODIFY_REG((__HANDLE__)->Instance->MODE, LED_MODE_BFN, ((__NUM__ - 1) << LED_MODE_BFN_Pos))

/** @brief LED Set data number in one from om onoff mode.
  * @param  __HANDLE__ LED handle.
	* @param __NUM__ data number in one frame on onoff mode
  * @retval None
  */
#define __HAL_LED_SET_DATANUMBERINFRAME_ONOFFMODE(__HANDLE__, __NUM__) MODIFY_REG((__HANDLE__)->Instance->MODE, LED_MODE_DN, ((__NUM__) << LED_MODE_DN_Pos))

/** @brief LED Set DMODE normal.
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_SET_DISPLAYNMODE_NORMAL(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->MODE, LED_MODE_DMD)

/** @brief LED Set DMODE dimming.
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_SET_DISPLAYNMODE_DIMMING(__HANDLE__) SET_BIT((__HANDLE__)->Instance->MODE, LED_MODE_DMD)

/** @brief LED Set brightness step
  * @param  __HANDLE__ LED handle.
  * @param  __STEP__ LEDbrightness step.
  * @retval None
  */
#define __HAL_LED_SET_BRIGHTSTEP(__HANDLE__, __STEP__) MODIFY_REG((__HANDLE__)->Instance->MODE, LED_MODE_BRTS, (__STEP__))

/** @brief LED Set dimming step
  * @param  __HANDLE__ LED handle.
  * @param  __STEP__ LEDbrightness step.
  *         @arg @ref LED_DIMMING_STEP_16
  *         @arg @ref LED_DIMMING_STEP_8
  *         @arg @ref LED_DIMMING_STEP_4
  *         @arg @ref LED_DIMMING_STEP_2
  *         @arg @ref LED_DIMMING_STEP_1
  * @retval None
  */
#define __HAL_LED_SET_DIMMINGSTEP(__HANDLE__, __STEP__) MODIFY_REG((__HANDLE__)->Instance->MODE, LED_MODE_DIMS, (__STEP__))

/** @brief LED Set Display end pointer
  * @param  __HANDLE__ LED handle.
  * @param  __END__ Display buffer end pointer.
  * @retval None
  */
#define __HAL_LED_SET_DSIPLAYBUFFER_ENDP(__HANDLE__, __END__) MODIFY_REG((__HANDLE__)->Instance->MODE, LED_MODE_ALAST, (__END__))

/** @brief LED Set SEG brightness maximum
  * @param  __HANDLE__ LED handle.
  * @param  __SEG__ LED SEG index.
  * @param  __MAX__ LED SEG brightness maximum.
  * @retval None
  */
#define __HAL_LED_SET_SEGBRGMAX(__HANDLE__, __SEG__, __MAX__) \
        (((__SEG__) == 0) ? MODIFY_REG((__HANDLE__)->Instance->BRG1, LED_BRG_BRT0, (__MAX__)) : \
         ((__SEG__) == 1) ? MODIFY_REG((__HANDLE__)->Instance->BRG1, LED_BRG_BRT1, (__MAX__)) : \
         ((__SEG__) == 2) ? MODIFY_REG((__HANDLE__)->Instance->BRG1, LED_BRG_BRT2, (__MAX__)) : \
         ((__SEG__) == 3) ? MODIFY_REG((__HANDLE__)->Instance->BRG1, LED_BRG_BRT3, (__MAX__)) : \
         ((__SEG__) == 4) ? MODIFY_REG((__HANDLE__)->Instance->BRG2, LED_BRG_BRT4, (__MAX__)) : \
         ((__SEG__) == 5) ? MODIFY_REG((__HANDLE__)->Instance->BRG2, LED_BRG_BRT5, (__MAX__)) : \
         ((__SEG__) == 6) ? MODIFY_REG((__HANDLE__)->Instance->BRG2, LED_BRG_BRT6, (__MAX__)) : \
         ((__SEG__) == 7) ? MODIFY_REG((__HANDLE__)->Instance->BRG2, LED_BRG_BRT7, (__MAX__)) : \
         MODIFY_REG((__HANDLE__)->Instance->BRG3, LED_BRG_BRT8, (__MAX__)))

/** @brief LED Clear Flag
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_CLEAR_ALLFLAGS(__HANDLE__) READ_REG((__HANDLE__)->Instance->STATUS)

/** @brief LED Read Flag
  * @param  __HANDLE__ LED handle.
  * @retval None
  */
#define __HAL_LED_READ_ALLFLAGS(__HANDLE__) READ_BIT((__HANDLE__)->Instance->STATUS, LED_STATUS_UIF|LED_STATUS_FIF|LED_STATUS_CIF|LED_STATUS_PIF)

/** @brief CHeck LED flag
  * @param  __STATE__ LED status.
  * @param  __FLAG__ LED flag.
  *         @arg @ref LED_FLAG_UIF
  *         @arg @ref LED_FLAG_FIF
  *         @arg @ref LED_FLAG_CIF
  *         @arg @ref LED_FLAG_PIF
  * @retval SET : RESET
  */
#define __HAL_LED_CHECK_FLAG(__STATE__, __FLAG__) (((__STATE__) & (__FLAG__)) ? SET : RESET)

/** @brief LED Get FSM status
  * @param  __HANDLE__ LED handle.
  * @retval FSm state
  */
#define __HAL_LED_GET_FSM_STATE(__HANDLE__) READ_BIT((__HANDLE__)->Instance->DEBUG, LED_DEBUG_FSM)

/** @brief LED Get Display frame number
  * @param  __HANDLE__ LED handle.
  * @retval display frame number
  */
#define __HAL_LED_GET_DISPLAY_FRAME_INDEX(__HANDLE__) READ_BIT((__HANDLE__)->Instance->DEBUG, LED_DEBUG_FRMN)

/** @brief LED memory enable
  * @param  __HANDLE__ LED handle.
  * @retval none
  */
#define __HAL_LED_DISPLAY_MEMORY_ENABLE(__HANDLE__) SET_BIT((__HANDLE__)->Instance->CTRL, LED_CTRL_SWME)

/** @brief LED memory disable
  * @param  __HANDLE__ LED handle.
  * @retval none
  */
#define __HAL_LED_DISPLAY_MEMORY_DISABLE(__HANDLE__) CLEAR_BIT((__HANDLE__)->Instance->CTRL, LED_CTRL_SWME)
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup LED_Exported_Functions LED Exported Functions
  * @{
  */

/* Initialization and de-initialization functions  ****************************/
/** @defgroup LED_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
HAL_StatusTypeDef HAL_LED_Init(LED_HandleTypeDef *hled);
HAL_StatusTypeDef HAL_LED_DeInit(LED_HandleTypeDef *hled);
void HAL_LED_MspInit(LED_HandleTypeDef *hled);
void HAL_LED_MspDeInit(LED_HandleTypeDef *hled);

void HAL_LED_AnaOn(LED_HandleTypeDef *hled);
void HAL_LED_AnaOff(LED_HandleTypeDef *hled);

HAL_StatusTypeDef HAL_LED_DMAHSIFConfig(LED_HandleTypeDef *hled, DMA_HandleTypeDef *hdma, 
                                         uint32_t dmaif, uint32_t dmaifcfg);
HAL_StatusTypeDef HAL_LED_LinkDMA(LED_HandleTypeDef *hled, DMA_HandleTypeDef *hdma);


/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_LED_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_LED_RegisterCallback(LED_HandleTypeDef *hled, HAL_LED_CallbackIDTypeDef CallbackID,
                                            pLED_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_LED_UnRegisterCallback(LED_HandleTypeDef *hled, HAL_LED_CallbackIDTypeDef CallbackID);

#endif /* USE_HAL_LED_REGISTER_CALLBACKS */
/**
  * @}
  */

/* Peripheral Control functions ***********************************************/
/** @defgroup LED_Exported_Functions_Group2 Peripheral Control functions
  * @{
  */
//uint32_t HAL_LED_SetSegData(LED_HandleTypeDef *hled, uint32_t* pData);
//uint32_t HAL_LED_SetSegData_DMA(LED_HandleTypeDef *hled, uint32_t* pData);

void HAL_LED_On(LED_HandleTypeDef *hled);
void HAL_LED_Off(LED_HandleTypeDef *hled);

void HAL_LED_SetRunningMode(LED_HandleTypeDef *hled, uint32_t Mode, uint32_t Step, uint32_t Interpolator);

void HAL_LED_SetSegMaxBright(LED_HandleTypeDef *hled, uint32_t SegIdx, uint32_t Step, uint32_t Count);

uint32_t HAL_LED_GetBufferComIndex(LED_HandleTypeDef *hled, uint32_t ComIdx);

void HAL_LED_SetNode(LED_HandleTypeDef *hled, uint32_t FrameIdx, uint32_t ComIdx, uint32_t SegIdx, uint32_t Data);

uint32_t HAL_LED_PackSegData(LED_HandleTypeDef *hled, uint32_t ComIdx, uint32_t SegIdx, uint32_t SegWd);

uint32_t HAL_LED_GetComNumber(uint32_t ComEn);
uint32_t HAL_LED_GetComIdxMax(uint32_t ComEn);
/**
  * @}
  */

/* Peripheral State and Error functions ***************************************/
/** @defgroup LED_Exported_Functions_Group3 Peripheral State functions
  * @{
  */
HAL_LED_StateTypeDef HAL_LED_GetState(LED_HandleTypeDef *hled);
/**
  * @}
  */

/** @defgroup LED_Exported_Functions_Group4 IRQ handler led_Callbacks Callbacks
  * @{
  */
/******* LED IRQ_Handler and Callbacks used in non blocking modes (Interrupt and DMA) */
void HAL_LED_IRQHandler(LED_HandleTypeDef *hled);

void HAL_LED_TfrTxCpltCallback(LED_HandleTypeDef *hled);
void HAL_LED_ErrorCallback(LED_HandleTypeDef *hled);
void HAL_LED_AbortCpltCallback(LED_HandleTypeDef *hled);
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

#endif /* XT32H0xx_HAL_LED_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
