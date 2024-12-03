/**
  ******************************************************************************
  * @file    xt32h0xx_ll_i2c.h
  * @author  Software Team
  * @brief   Header file of I2C LL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_LL_I2C_H
#define XT32H0xx_LL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_LL_Driver
  * @{
  */

#if defined (I2C1) || defined (I2C2) 

/** @defgroup I2C_LL I2C
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup I2C_LL_Private_Constants I2C Private Constants
  * @{
  */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup I2C_LL_Private_Macros I2C Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
/** @defgroup I2C_LL_Exported_Types I2C Exported Types
  * @{
  */
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup I2C_LL_ES_INIT I2C Exported Init structure
  * @{
  */
typedef struct
{
  uint32_t DigitalFilter;       /*!< Configures the digital noise filter.
                                     This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetFSSpikeLength() or LL_I2C_SetHSSpikeLength(). */

  uint32_t SlaveAddress;        /*!< Specifies the device slave address.
                                     This parameter must be a value between Min_Data = 0x00 and Max_Data = 0x3FF.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetSlaveAddress(). */

  uint32_t SlaveAddrSize;       /*!< Specifies the device own address 1 size (7-bit or 10-bit).
                                     This parameter can be a value of @ref I2C_LL_EC_ADDRESSING.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetSlvAddressing(). */

  uint32_t MasterAddrSize;      /*!< Specifies the device own address 1 size (7-bit or 10-bit).
                                     This parameter can be a value of @ref I2C_LL_EC_ADDRESSING.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetMstAddressing(). */

  uint32_t Mode;                /*!< Specifies the device mode.
                                     This parameter can be a value of @ref I2C_LL_EC_MODE.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetMode(). */

  uint32_t Speed;               /*!< Specifies the device speed.
                                     This parameter can be a value of @ref I2C_LL_EC_SPEED.

                                     This feature can be modified afterwards using unitary function
                                     @ref LL_I2C_SetSpeed(). */

} LL_I2C_InitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup I2C_LL_Exported_Constants I2C Exported Constants
  * @{
  */
/** @defgroup I2C_LL_EC_BUFFER_DEPTH Status Defines
  * @brief    Flags defines which can be used with LL_I2C_ReadReg function
  * @{
  */
#define LL_I2C_TX_BUFFER_DEPTH             (8)  
#define LL_I2C_RX_BUFFER_DEPTH             (8)  
/**
  * @}
  */

/** @defgroup I2C_LL_EC_STATUS Status Defines
  * @brief    Flags defines which can be used with LL_I2C_ReadReg function
  * @{
  */
#define LL_I2C_STATUS_ACTIVITY              I2C_STATUS_ACT          /*!< I2C activity status               */
#define LL_I2C_STATUS_TFNF                  I2C_STATUS_TFNF         /*!< Transmit FIFO not full            */
#define LL_I2C_STATUS_TFE                   I2C_STATUS_TFE          /*!< Transmit FIFO completely empty    */
#define LL_I2C_STATUS_RFNE                  I2C_STATUS_RFNE         /*!< Receive FIFO not empty            */
#define LL_I2C_STATUS_RFF                   I2C_STATUS_RFF          /*!< Receive FIFO completely full      */
#define LL_I2C_STATUS_MST_ACTIVITY          I2C_STATUS_MSTA         /*!< Master FSM activity status        */
#define LL_I2C_STATUS_SLV_ACTIVITY          I2C_STATUS_SLVA         /*!< Slave FSM activity status         */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_ENABLE_STATUS Enable status Defines
  * @brief    Flags defines which can be used with LL_I2C_ReadReg function
  * @{
  */
#define LL_I2C_ENABLE_STATUS_EN                         I2C_ESTAT_EN          /*!< I2C enable status               */
#define LL_I2C_ENABLE_STATUS_SLV_DSIABLED_WHILE_BUSY    I2C_ESTAT_BY          /*!< Slave disable while busy        */
#define LL_I2C_ENABLE_STATUS_SLV_RX_DATA_LOST           I2C_ESTAT_SL          /*!< Slave receive data lost         */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_ABORT_SOURCE I2C transmit abort source Defines
  * @brief    Flags defines which can be used with LL_I2C_ReadReg function
  * @{
  */
#define LL_I2C_ABRT_7B_ADDR_NOACK           I2C_TXAS_7ANACK         /*!< Not receive an acknowledgement in 7-bit addressing mode        */
#define LL_I2C_ABRT_10ADDR1_NOACK           I2C_TXAS_10A1NA         /*!< Not receive an acknowledgement for 10-bit address first byte */
#define LL_I2C_ABRT_10ADDR2_NOACK           I2C_TXAS_10A2NA         /*!< Not receive an acknowledgement for 10-bit address second byte     */
#define LL_I2C_ABRT_TXDATA_NOACK            I2C_TXAS_TXNACK         /*!< Not receive an acknowledgement for data */
#define LL_I2C_ABRT_GCALL_NOACK             I2C_TXAS_GCNACK         /*!< Master sent a General Call and no slave onthe bus acknowledged the General Call */
#define LL_I2C_ABRT_GCALL_READ              I2C_TXAS_GCRD           /*!< Master sent a Generak Cakk but the user programmed the byte following the General Call to be a read from the bus */
#define LL_I2C_ABRT_HS_ACKDET               I2C_TXAS_HSADET         /*!< Master in High Speed mode and High Speed Master code was acknownledged */
#define LL_I2C_ABRT_SBYTE_ACKDET            I2C_TXAS_STBACK         /*!< Master has sent a START Byte and the START Byte was acknowledged */
#define LL_I2C_ABRT_HS_NORSTRT              I2C_TXAS_HSNRST         /*!< The restart is disabled and the user is trying to use the master to transfer data in High Speed mode */
#define LL_I2C_ABRT_SBYTE_NORSTRT           I2C_TXAS_SBNRST         /*!< To clear Bit 9 */
#define LL_I2C_ABRT_10B_RD_NORSTRT          I2C_TXAS_10BRNR         /*!< The restart is disabled and the master sends a read command in 10-bit addressing mode */
#define LL_I2C_ABRT_MASTER_DIS              I2C_TXAS_MSTDIS         /*!< User initiate a master operation with the master mode disabled */
#define LL_I2C_ABRT_LOST                    I2C_TXAS_LOST           /*!< Master has lost arbitration */
#define LL_I2C_ABRT_SLVFLUSH_TXFIFO         I2C_TXAS_SFTF           /*!< Slave has received a read command and some data exists in the TX FIFO */
#define LL_I2C_ABRT_SLV_ARBLOST             I2C_TXAS_SLOST          /*!< Slave lost bus while transmitting data to a remote master         */
#define LL_I2C_ABRT_SLVRD_INTX              I2C_TXAS_SRDITX         /*!< When the processor side reponds to a slave mode request for data to be transmitted to aremote master and user write 1 to CMD */
#define LL_I2C_ABRT_USER_ABRT               I2C_TXAS_USERAB         /*!< Master has detected the transfer abort                            */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_I2C_ReadReg and  LL_I2C_WriteReg functions
  * @{
  */
#define LL_I2C_IT_RX_UNDER              I2C_INTRSTAT_RXU            /*!< RX_UNDER                                    */
#define LL_I2C_IT_RX_OVER               I2C_INTRSTAT_RXO            /*!< RX_OVER                                     */
#define LL_I2C_IT_RX_FULL               I2C_INTRSTAT_RXF            /*!< RX_FULL                                     */
#define LL_I2C_IT_TX_OVER               I2C_INTRSTAT_TXO            /*!< TX_OVER                                     */
#define LL_I2C_IT_TX_EMPTY              I2C_INTRSTAT_TXE            /*!< TX_EMPTY                                    */
#define LL_I2C_IT_RD_REQ                I2C_INTRSTAT_RDR            /*!< RD_REQ                                      */
#define LL_I2C_IT_TX_ABRT               I2C_INTRSTAT_TXA            /*!< TX_ABRT                                     */
#define LL_I2C_IT_RX_DONE               I2C_INTRSTAT_RXD            /*!< RX_DONE                                     */
#define LL_I2C_IT_ACTIVITY              I2C_INTRSTAT_ACT            /*!< ACTIVITY                                    */
#define LL_I2C_IT_STOP_DET              I2C_INTRSTAT_STOPD          /*!< STOP_DET                                    */
#define LL_I2C_IT_START_DET             I2C_INTRSTAT_STARTD         /*!< START_DET                                   */
#define LL_I2C_IT_GEN_CALL              I2C_INTRSTAT_GCALL          /*!< GEN_CALL                                    */
//#define LL_I2C_IT_RESTART_DET           I2C_INTRSTAT_RESD           /*!< RESTART_DET                                 */
//#define LL_I2C_IT_MST_ON_HOLD           I2C_INTRSTAT_MOH            /*!< MST_ON_HOLD                                 */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_MODE I2C Mode
  * @{
  */
#define LL_I2C_MODE_SLAVE                 0x00000000U                       /*!< I2C Slave mode                              */
#define LL_I2C_MODE_MASTER                (I2C_CON_MMOD | I2C_CON_SLVDIS)   /*!< I2C Master mode                             */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_SPEED I2C speed
  * @{
  */
#define LL_I2C_SPEED_STANDARD_MODE         (I2C_CON_SPEED_0)                           /*!< I2C speed standard mode (0 to 100kbps)      */
#define LL_I2C_SPEED_FAST_MODE             (I2C_CON_SPEED_1)                           /*!< I2C speed fast mode (<= 400Kbps) or fast mode plus (<= 1000Kbps) */
#define LL_I2C_SPEED_HIGH_MODE             (I2C_CON_SPEED_1|I2C_CON_SPEED_0)           /*!< I2C speed high mode (<= 3.4Mbps)            */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_ADDRESSING I2C addressing
  * @{
  */
#define LL_I2C_SLV_ADDRESSING_7BIT         0x00000000U              /*!< I2C 7-bit addressing                        */
#define LL_I2C_SLV_ADDRESSING_10BIT        (I2C_CON_10ASLV)         /*!< I2C 10-bit addressing                       */

#define LL_I2C_MST_ADDRESSING_7BIT         0x00000000U              /*!< I2C 7-bit addressing                        */
#define LL_I2C_MST_ADDRESSING_10BIT        (I2C_CON_10AMST)         /*!< I2C 10-bit addressing                       */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_RESTART_EN I2C restart enable
  * @{
  */
#define LL_I2C_RESTART_DSIABLE             0x00000000U              /*!< I2C RESTART disable                        */
#define LL_I2C_RESTART_ENABLE              0x00000001U              /*!< I2C RESTART enable                         */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_STOP_DET_IFADDRESSED I2C issue STOP_DET if it is addressed or not
  * @{
  */
#define LL_I2C_STOP_DET_IRRESPECTIVE       0x00000000U              /*!< I2C issue the STOP_DET irrespective of whether it's addressed or not */
#define LL_I2C_STOP_DET_ADDRESSED          0x00000001U              /*!< I2C issue the STOP_DET interrupt only when it is addressed           */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_CMD I2C command
  * @{
  */
#define LL_I2C_CMD_WRITE                   0x00000000U              /*!< I2C write */
#define LL_I2C_CMD_READ                    I2C_DATACMD_CMD          /*!< I2C read */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_STOP I2C stop issued after the byte is sent and received
  * @{
  */
#define LL_I2C_STOP_NOTISSUED              0x00000000U              /*!< I2C stop is not issued */
#define LL_I2C_STOP_ISSUED                 0x00000001U              /*!< I2C stop is issued */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_RESTART I2C restart issued before the byte is sent and received
  * @{
  */
#define LL_I2C_RESTART_NOTISSUED           0x00000000U              /*!< I2C restart is not issued */
#define LL_I2C_RESTART_ISSUED              0x00000001U              /*!< I2C restart is issued */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_ENABLE I2C enable
  * @{
  */
#define LL_I2C_DSIABLE                     0x00000000U              /*!< I2C disable */
#define LL_I2C_ENABLE                      I2C_ENABLE_EN            /*!< I2C enable */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_ABORT I2C abort
  * @{
  */
#define LL_I2C_ABORT_DONE                  0x00000000U              /*!< I2C abort not initiated or abort done */
#define LL_I2C_ABORT                       I2C_ENABLE_AB            /*!< I2C abort operation */
/**
  * @}
  */


/** @defgroup I2C_LL_EC_TDMAE I2C transmit DMA enable
  * @{
  */
#define LL_I2C_TDMAE_DISABLE               0x00000000U              /*!< I2C transmit DMA disable */
#define LL_I2C_TDMAE_ENABLE                I2C_DMACR_TDMAE          /*!< I2C transmit DMA enable */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_RDMAE I2C receive DMA enable
  * @{
  */
#define LL_I2C_RDMAE_DISABLE               0x00000000U              /*!< I2C receive DMA disable */
#define LL_I2C_RDMAE_ENABLE                I2C_DMACR_RDMAE          /*!< I2C receive DMA enable */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_APB_DATA_WIDTH I2C apb data width
  * @{
  */
#define LL_I2C_APB_DATA_WIDTH_8               0x00000000U           /*!< 8  bits */
#define LL_I2C_APB_DATA_WIDTH_16              0x00000001U           /*!< 16 bits */
#define LL_I2C_APB_DATA_WIDTH_32              0x00000002U           /*!< 32 bits */
/**
  * @}
  */

/** @defgroup I2C_LL_EC_MAX_SPEED_MODE I2C max speed mode
  * @{
  */
#define LL_I2C_MAX_SPEED_MODE_STANDARD        0x00000000U           /*!< Standard */
#define LL_I2C_MAX_SPEED_MODE_FAST            0x00000001U           /*!< Fast */
#define LL_I2C_MAX_SPEED_MODE_HIGH            0x00000002U           /*!< High */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup I2C_LL_Exported_Macros I2C Exported Macros
  * @{
  */

/** @defgroup I2C_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in I2C register
  * @param  __INSTANCE__ I2C Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  */
#define LL_I2C_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in I2C register
  * @param  __INSTANCE__ I2C Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_I2C_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup I2C_LL_EM_Mask  I2C Mask Macros
  * @{
  */
/**
  * @brief  Mask interrupt
  * @param  __INSTANCE__ I2C Instance
  * @param  __IT__ Interrupt
            @arg @ref LL_I2C_IT_RX_UNDER 
            @arg @ref LL_I2C_IT_RX_OVER  
            @arg @ref LL_I2C_IT_RX_FULL  
            @arg @ref LL_I2C_IT_TX_OVER  
            @arg @ref LL_I2C_IT_TX_EMPTY 
            @arg @ref LL_I2C_IT_RD_REQ   
            @arg @ref LL_I2C_IT_TX_ABRT  
            @arg @ref LL_I2C_IT_RX_DONE  
            @arg @ref LL_I2C_IT_ACTIVITY 
            @arg @ref LL_I2C_IT_STOP_DET 
            @arg @ref LL_I2C_IT_START_DET
            @arg @ref LL_I2C_IT_GEN_CALL 
  * @retval interrupt value or 0
  */
#define LL_I2C_MaskIT(__INSTANCE__, __IT__) CLEAR_BIT(__INSTANCE__->INTRMASK, __IT__)

/**
  * @brief  Unmask interrupt
  * @param  __INSTANCE__ I2C Instance
  * @param  __IT__ Interrupt
            @arg @ref LL_I2C_IT_RX_UNDER 
            @arg @ref LL_I2C_IT_RX_OVER  
            @arg @ref LL_I2C_IT_RX_FULL  
            @arg @ref LL_I2C_IT_TX_OVER  
            @arg @ref LL_I2C_IT_TX_EMPTY 
            @arg @ref LL_I2C_IT_RD_REQ   
            @arg @ref LL_I2C_IT_TX_ABRT  
            @arg @ref LL_I2C_IT_RX_DONE  
            @arg @ref LL_I2C_IT_ACTIVITY 
            @arg @ref LL_I2C_IT_STOP_DET 
            @arg @ref LL_I2C_IT_START_DET
            @arg @ref LL_I2C_IT_GEN_CALL 
  * @retval interrupt value or 0
  */
#define LL_I2C_UnmaskIT(__INSTANCE__, __IT__) SET_BIT(__INSTANCE__->INTRMASK, __IT__)

/**
  * @brief  Check interrupt mask
  * @param  __INSTANCE__ I2C Instance
  * @param  __IT__ Interrupt
            @arg @ref LL_I2C_IT_RX_UNDER 
            @arg @ref LL_I2C_IT_RX_OVER  
            @arg @ref LL_I2C_IT_RX_FULL  
            @arg @ref LL_I2C_IT_TX_OVER  
            @arg @ref LL_I2C_IT_TX_EMPTY 
            @arg @ref LL_I2C_IT_RD_REQ   
            @arg @ref LL_I2C_IT_TX_ABRT  
            @arg @ref LL_I2C_IT_RX_DONE  
            @arg @ref LL_I2C_IT_ACTIVITY 
            @arg @ref LL_I2C_IT_STOP_DET 
            @arg @ref LL_I2C_IT_START_DET
            @arg @ref LL_I2C_IT_GEN_CALL 
  * @retval status (0 or 1)
  */
#define LL_I2C_IsMaskedIT(__INSTANCE__, __IT__) (READ_BIT(__INSTANCE__->INTRMASK, __IT__) == __IT__) ? 0UL : 1UL)
/**
  * @}
  */

/** @defgroup I2C_LL_EM_FLAG  I2C Flag Macros
  * @{
  */
/**
  * @brief  Get Flag
  * @param  __INSTANCE__ I2C Instance
  * @param  __FLAG__ Flag
            @arg @ref LL_I2C_IT_RX_UNDER 
            @arg @ref LL_I2C_IT_RX_OVER  
            @arg @ref LL_I2C_IT_RX_FULL  
            @arg @ref LL_I2C_IT_TX_OVER  
            @arg @ref LL_I2C_IT_TX_EMPTY 
            @arg @ref LL_I2C_IT_RD_REQ   
            @arg @ref LL_I2C_IT_TX_ABRT  
            @arg @ref LL_I2C_IT_RX_DONE  
            @arg @ref LL_I2C_IT_ACTIVITY 
            @arg @ref LL_I2C_IT_STOP_DET 
            @arg @ref LL_I2C_IT_START_DET
            @arg @ref LL_I2C_IT_GEN_CALL 
  * @retval flag value or 0
  */
#define LL_I2C_GetFlag(__INSTANCE__, __FLAG__) READ_BIT(__INSTANCE__->RAWINTRSTAT, __FLAG__)

/**
  * @brief  Check Flag
  * @param  __INSTANCE__ I2C Instance
  * @param  __FLAG__ Flag
            @arg @ref LL_I2C_IT_RX_UNDER 
            @arg @ref LL_I2C_IT_RX_OVER  
            @arg @ref LL_I2C_IT_RX_FULL  
            @arg @ref LL_I2C_IT_TX_OVER  
            @arg @ref LL_I2C_IT_TX_EMPTY 
            @arg @ref LL_I2C_IT_RD_REQ   
            @arg @ref LL_I2C_IT_TX_ABRT  
            @arg @ref LL_I2C_IT_RX_DONE  
            @arg @ref LL_I2C_IT_ACTIVITY 
            @arg @ref LL_I2C_IT_STOP_DET 
            @arg @ref LL_I2C_IT_START_DET
            @arg @ref LL_I2C_IT_GEN_CALL 
  * @retval status (0 or 1)
  */
#define LL_I2C_CheckFlag(__INSTANCE__, __FLAG__) (READ_BIT(__INSTANCE__->RAWINTRSTAT, __FLAG__) == __FLAG__) ? 1UL : 0UL)
/**
  * @}
  */

/** @defgroup I2C_LL_EM_IT I2C Interrupt Macros
  * @{
  */
/**
  * @brief  Get interrupt
  * @param  __INSTANCE__ I2C Instance
  * @param  __IT__ Interrupt
            @arg @ref LL_I2C_IT_RX_UNDER 
            @arg @ref LL_I2C_IT_RX_OVER  
            @arg @ref LL_I2C_IT_RX_FULL  
            @arg @ref LL_I2C_IT_TX_OVER  
            @arg @ref LL_I2C_IT_TX_EMPTY 
            @arg @ref LL_I2C_IT_RD_REQ   
            @arg @ref LL_I2C_IT_TX_ABRT  
            @arg @ref LL_I2C_IT_RX_DONE  
            @arg @ref LL_I2C_IT_ACTIVITY 
            @arg @ref LL_I2C_IT_STOP_DET 
            @arg @ref LL_I2C_IT_START_DET
            @arg @ref LL_I2C_IT_GEN_CALL 
  * @retval interrupt value or 0
  */
#define LL_I2C_GetIT(__INSTANCE__, __IT__) READ_BIT(__INSTANCE__->INTRSTAT, __IT__)

/**
  * @brief  Check interrupt
  * @param  __INSTANCE__ I2C Instance
  * @param  __IT__ Interrupt
            @arg @ref LL_I2C_IT_RX_UNDER 
            @arg @ref LL_I2C_IT_RX_OVER  
            @arg @ref LL_I2C_IT_RX_FULL  
            @arg @ref LL_I2C_IT_TX_OVER  
            @arg @ref LL_I2C_IT_TX_EMPTY 
            @arg @ref LL_I2C_IT_RD_REQ   
            @arg @ref LL_I2C_IT_TX_ABRT  
            @arg @ref LL_I2C_IT_RX_DONE  
            @arg @ref LL_I2C_IT_ACTIVITY 
            @arg @ref LL_I2C_IT_STOP_DET 
            @arg @ref LL_I2C_IT_START_DET
            @arg @ref LL_I2C_IT_GEN_CALL 
  * @retval status (0 or 1)
  */
#define LL_I2C_CheckIT(__INSTANCE__, __IT__) (READ_BIT(__INSTANCE__->INTRSTAT, __IT__) == __IT__) ? 1UL : 0UL)
/**
  * @}
  */

/** @defgroup I2C_LL_EM_Status I2C State Macros
  * @{
  */
/**
  * @brief  Get Status
  * @param  __INSTANCE__ I2C Instance
  * @param  __STATUS__ Status
            @arg @ref LL_I2C_STATUS_ACTIVITY              I2C activity status            
            @arg @ref LL_I2C_STATUS_TFNF                  Transmit FIFO not full         
            @arg @ref LL_I2C_STATUS_TFE                   Transmit FIFO completely empty 
            @arg @ref LL_I2C_STATUS_RFNE                  Receive FIFO not empty         
            @arg @ref LL_I2C_STATUS_RFF                   Receive FIFO completely full   
            @arg @ref LL_I2C_STATUS_MST_ACTIVITY          Master FSM activity status     
            @arg @ref LL_I2C_STATUS_SLV_ACTIVITY          Slave FSM activity status      
  * @retval Status value or 0
  */
#define LL_I2C_GetStatus(__INSTANCE__, __STATUS__) READ_BIT(__INSTANCE__->STATUS, __STATUS__)

/**
  * @brief  Check Status
  * @param  __INSTANCE__ I2C Instance
  * @param  __STATUS__ Status
            @arg @ref LL_I2C_STATUS_ACTIVITY              I2C activity status            
            @arg @ref LL_I2C_STATUS_TFNF                  Transmit FIFO not full         
            @arg @ref LL_I2C_STATUS_TFE                   Transmit FIFO completely empty 
            @arg @ref LL_I2C_STATUS_RFNE                  Receive FIFO not empty         
            @arg @ref LL_I2C_STATUS_RFF                   Receive FIFO completely full   
            @arg @ref LL_I2C_STATUS_MST_ACTIVITY          Master FSM activity status     
            @arg @ref LL_I2C_STATUS_SLV_ACTIVITY          Slave FSM activity status      
  * @retval status (0 or 1)
  */
#define LL_I2C_CheckStatus(__INSTANCE__, __STATUS__) (READ_BIT(__INSTANCE__->STATUS, __STATUS__) == __STATUS__) ? 1UL : 0UL)
/**
  * @}
  */

/** @defgroup I2C_LL_EM_TxAbortSource I2C TX Abort Source Macros
  * @{
  */
/**
  * @brief  Get Tx abort source
  * @param  __INSTANCE__ I2C Instance
  * @param  __SOURCE__ Tx abort source
            @arg @ref LL_I2C_ABRT_7B_ADDR_NOACK           Not receive an acknowledgement in 7-bit addressing mode        
            @arg @ref LL_I2C_ABRT_10ADDR1_NOACK           Not receive an acknowledgement for 10-bit address first byte   
            @arg @ref LL_I2C_ABRT_10ADDR2_NOACK           Not receive an acknowledgement for 10-bit address second byte     
            @arg @ref LL_I2C_ABRT_TXDATA_NOACK            Not receive an acknowledgement for data                          
            @arg @ref LL_I2C_ABRT_GCALL_NOACK             Master sent a General Call and no slave onthe bus acknowledged the General Call 
            @arg @ref LL_I2C_ABRT_GCALL_READ              Master sent a Generak Cakk but the user programmed the byte following the General Call to be a read from the bus 
            @arg @ref LL_I2C_ABRT_HS_ACKDET               Master in High Speed mode and High Speed Master code was acknownledged 
            @arg @ref LL_I2C_ABRT_SBYTE_ACKDET            Master has sent a START Byte and the START Byte was acknowledged      
            @arg @ref LL_I2C_ABRT_HS_NORSTRT              The restart is disabled and the user is trying to use the master to transfer data in High Speed mode 
            @arg @ref LL_I2C_ABRT_SBYTE_NORSTRT           To clear Bit 9 
            @arg @ref LL_I2C_ABRT_10B_RD_NORSTRT          The restart is disabled and the master sends a read command in 10-bit addressing mode 
            @arg @ref LL_I2C_ABRT_MASTER_DIS              User initiate a master operation with the master mode disabled 
            @arg @ref LL_I2C_ABRT_LOST                    Master has lost arbitration 
            @arg @ref LL_I2C_ABRT_SLVFLUSH_TXFIFO         Slave has received a read command and some data exists in the TX FIFO 
            @arg @ref LL_I2C_ABRT_SLV_ARBLOST             Slave lost bus while transmitting data to a remote master         
            @arg @ref LL_I2C_ABRT_SLVRD_INTX              When the processor side reponds to a slave mode request for data to be transmitted to aremote master and user write 1 to CMD 
            @arg @ref LL_I2C_ABRT_USER_ABRT               Master has detected the transfer abort                            
  * @retval source value or 0
  */
#define LL_I2C_GetTxAbortSource(__INSTANCE__, __SOURCE__) READ_BIT(__INSTANCE__->TXABRTSOURCE, __SOURCE__)

/**
  * @brief  Check Tx abort source
  * @param  __INSTANCE__ I2C Instance
  * @param  __SOURCE__ Tx abort source
            @arg @ref LL_I2C_ABRT_7B_ADDR_NOACK           Not receive an acknowledgement in 7-bit addressing mode        
            @arg @ref LL_I2C_ABRT_10ADDR1_NOACK           Not receive an acknowledgement for 10-bit address first byte   
            @arg @ref LL_I2C_ABRT_10ADDR2_NOACK           Not receive an acknowledgement for 10-bit address second byte     
            @arg @ref LL_I2C_ABRT_TXDATA_NOACK            Not receive an acknowledgement for data                          
            @arg @ref LL_I2C_ABRT_GCALL_NOACK             Master sent a General Call and no slave onthe bus acknowledged the General Call 
            @arg @ref LL_I2C_ABRT_GCALL_READ              Master sent a Generak Cakk but the user programmed the byte following the General Call to be a read from the bus 
            @arg @ref LL_I2C_ABRT_HS_ACKDET               Master in High Speed mode and High Speed Master code was acknownledged 
            @arg @ref LL_I2C_ABRT_SBYTE_ACKDET            Master has sent a START Byte and the START Byte was acknowledged      
            @arg @ref LL_I2C_ABRT_HS_NORSTRT              The restart is disabled and the user is trying to use the master to transfer data in High Speed mode 
            @arg @ref LL_I2C_ABRT_SBYTE_NORSTRT           To clear Bit 9 
            @arg @ref LL_I2C_ABRT_10B_RD_NORSTRT          The restart is disabled and the master sends a read command in 10-bit addressing mode 
            @arg @ref LL_I2C_ABRT_MASTER_DIS              User initiate a master operation with the master mode disabled 
            @arg @ref LL_I2C_ABRT_LOST                    Master has lost arbitration 
            @arg @ref LL_I2C_ABRT_SLVFLUSH_TXFIFO         Slave has received a read command and some data exists in the TX FIFO 
            @arg @ref LL_I2C_ABRT_SLV_ARBLOST             Slave lost bus while transmitting data to a remote master         
            @arg @ref LL_I2C_ABRT_SLVRD_INTX              When the processor side reponds to a slave mode request for data to be transmitted to aremote master and user write 1 to CMD 
            @arg @ref LL_I2C_ABRT_USER_ABRT               Master has detected the transfer abort                            
  * @retval status (0 or 1)
  */
#define LL_I2C_CheckTxAbortSource(__INSTANCE__, __SOURCE__) (READ_BIT(__INSTANCE__->TXABRTSOURCE, __SOURCE__) == __SOURCE__) ? 1UL : 0UL)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup I2C_LL_Exported_Functions I2C Exported Functions
  * @{
  */

/** @defgroup I2C_LL_Exported_Functions_Group1 Configuration
  * @{
  */
/**
  * @brief  Set I2C slave address.
  * @rmtoll SAR          SAR                       LL_I2C_SetSlaveAddress
  * @param  I2Cx I2C Instance.
  * @param  Address the value is between Min_data = 0x000 and Max_data=0x3FF exculding reserved 0x00 to 0x07 and 0x78 to 0x 7F.
  */
__STATIC_INLINE void LL_I2C_SetSlaveAddress(I2C_TypeDef *I2Cx, uint32_t Address)
{
  MODIFY_REG(I2Cx->SAR, I2C_SAR_SAR, Address);
}

/**
  * @brief  Get I2C slave address.
  * @rmtoll SAR          SAR                   LL_I2C_GetSlaveAddress
  * @param  I2Cx I2C Instance.
  * @retval the value is between Min_data = 0x000 and Max_data=0x3FF exculding reserved 0x00 to 0x07 and 0x78 to 0x 7F.
  */
__STATIC_INLINE uint32_t LL_I2C_GetSlaveAddress(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->SAR, I2C_SAR_SAR));
}

/**
  * @brief  Set I2C master code.
  * @rmtoll HSMADDR          HS_MAR                       LL_I2C_SetMasterCode
  * @param  I2Cx I2C Instance.
  * @param  Code the value is between Min_data = 0x0 and Max_data=0x7.
  */
__STATIC_INLINE void LL_I2C_SetMasterCode(I2C_TypeDef *I2Cx, uint32_t Code)
{
  MODIFY_REG(I2Cx->HSMADDR, I2C_HSMADDR_HSMAR, Code);
}

/**
  * @brief  Get I2C master code.
  * @rmtoll HSMADDR          HS_MAR                       LL_I2C_GetMasterCode
  * @param  I2Cx I2C Instance.
  * @retval  The value is between Min_data = 0x0 and Max_data=0x7.
  */
__STATIC_INLINE uint32_t LL_I2C_GetMasterCode(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->HSMADDR, I2C_HSMADDR_HSMAR));
}

/**
  * @brief  Enable DMA transmission requests.
  * @rmtoll DMACR          TDMAE       LL_I2C_EnableDMAReq_TX
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_EnableDMAReq_TX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->DMACR, I2C_DMACR_TDMAE);
}

/**
  * @brief  Disable DMA transmission requests.
  * @rmtoll DMACR          TDMAEN       LL_I2C_DisableDMAReq_TX
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_DisableDMAReq_TX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->DMACR, I2C_DMACR_TDMAE);
}

/**
  * @brief  Check if DMA transmission requests are enabled or disabled.
  * @rmtoll DMACR          TDMAE       LL_I2C_IsEnabledDMAReq_TX
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledDMAReq_TX(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->DMACR, I2C_DMACR_TDMAE) == (I2C_DMACR_TDMAE)) ? 1UL : 0UL);
}

/**
  * @brief  Enable DMA reception requests.
  * @rmtoll DMACR          RDMAE       LL_I2C_EnableDMAReq_RX
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_EnableDMAReq_RX(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->DMACR, I2C_DMACR_RDMAE);
}

/**
  * @brief  Disable DMA reception requests.
  * @rmtoll DMACR          RDMAE       LL_I2C_DisableDMAReq_RX
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_DisableDMAReq_RX(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->DMACR, I2C_DMACR_RDMAE);
}

/**
  * @brief  Check if DMA reception requests are enabled or disabled.
  * @rmtoll DMACR          RDMAE       LL_I2C_IsEnabledDMAReq_RX
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledDMAReq_RX(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->DMACR, I2C_DMACR_RDMAE) == (I2C_DMACR_RDMAE)) ? 1UL : 0UL);
}

/**
  * @brief  Get the data register address used for DMA transfer
  * @rmtoll DATA_CMD         DAT        LL_I2C_DMA_GetRegAddr
  * @param  I2Cx I2C Instance
  * @retval Address of data register
  */
__STATIC_INLINE uint32_t LL_I2C_DMA_GetRegAddr(I2C_TypeDef *I2Cx)
{
  return (uint32_t) (&(I2Cx->DATACMD));
}

/**
  * @brief  Set DMA transmit data level.
  * @rmtoll DMATDLR          DMATDL       LL_I2C_SetDMATxLevel
  * @param  I2Cx I2C Instance.
  * @param  Level The value is between 0 to 0xFF
  */
__STATIC_INLINE void LL_I2C_SetDMATxLevel(I2C_TypeDef *I2Cx, uint32_t Level)
{
  WRITE_REG(I2Cx->DMATDLR, Level);
}

/**
  * @brief  Get DMA transmit data level.
  * @rmtoll DMATDLR          DMATDL       LL_I2C_GetDMATxLevel
  * @param  I2Cx I2C Instance.
  * @retval The value is between 0 to 0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetDMATxLevel(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->DMATDLR));
}

/**
  * @brief  Set DMA receive data level.
  * @rmtoll DMARDLR          DMARDL       LL_I2C_SetDMARxLevel
  * @param  I2Cx I2C Instance.
  * @param  Level The value is between 0 to 0xFF
  */
__STATIC_INLINE void LL_I2C_SetDMARxLevel(I2C_TypeDef *I2Cx, uint32_t Level)
{
  WRITE_REG(I2Cx->DMARDLR, Level);
}

/**
  * @brief  Get DMA receive data level.
  * @rmtoll DMARDLR          DMATDL       LL_I2C_GetDMARxLevel
  * @param  I2Cx I2C Instance.
  * @retval The value is between 0 to 0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetDMARxLevel(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->DMARDLR));
}

/**
  * @brief  Enable General Call.
  * @note   When enabled the Address 0x00 is ACKed. The function is applicable only in slave mode.
  * @rmtoll ACKGENERALCALL          ACK          LL_I2C_EnableGeneralCallAck
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_EnableGeneralCallAck(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ACKGENERALCALL, I2C_GCACK_ACK);
}

/**
  * @brief  Disable General Call.
  * @note   When disabled the Address 0x00 is NACKed.
  * @rmtoll ACKGENERALCALL          ACK          LL_I2C_DisableGeneralCallAck
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_DisableGeneralCallAck(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->ACKGENERALCALL, I2C_GCACK_ACK);
}

/**
  * @brief  Check if General Call is enabled or disabled.
  * @rmtoll ACKGENERALCALL          ACK          LL_I2C_IsEnabledGeneralCallAck
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabledGeneralCallAck(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->ACKGENERALCALL, I2C_GCACK_ACK) == (I2C_GCACK_ACK)) ? 1UL : 0UL);
}

/**
  * @brief  Set SS and FS spike suppression limit.
  * @rmtoll FSSPKLEN      SPKLEN         LL_I2C_SetFSSpikeLength
  * @param  I2Cx I2C Instance.
  * @param  Length This parameter must be a value between Min_Data=0 and Max_Data=0xFF.
  */
__STATIC_INLINE void LL_I2C_SetFSSpikeLength(I2C_TypeDef *I2Cx, uint32_t Length)
{
  WRITE_REG(I2Cx->FSSPKLEN, Length);
}

/**
  * @brief  Get SS and FS spike suppression limit.
  * @rmtoll FSSPKLEN      SPKLEN         LL_I2C_GetFSSpikeLength
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetFSSpikeLength(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->FSSPKLEN));
}

/**
  * @brief  Set HS spike suppression limit.
  * @rmtoll HSSPKLEN      SPKLEN         LL_I2C_SetFSSpikeLength
  * @param  I2Cx I2C Instance.
  * @param  Length This parameter must be a value between Min_Data=0 and Max_Data=0xFF.
  */
__STATIC_INLINE void LL_I2C_SetHSSpikeLength(I2C_TypeDef *I2Cx, uint32_t Length)
{
  WRITE_REG(I2Cx->HSSPKLEN, Length);
}

/**
  * @brief  Get HS spike suppression limit.
  * @rmtoll HSSPKLEN      SPKLEN         LL_I2C_GetFSSpikeLength
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetHSSpikeLength(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->HSSPKLEN));
}

/**
  * @brief  Set the SS SCL low period setting.
  * @rmtoll SSSCLLCNT      LCNT          LL_I2C_SetSSClockLowPeriod
  * @param  I2Cx I2C Instance.
  * @param  Count Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE void LL_I2C_SetSSClockLowPeriod(I2C_TypeDef *I2Cx, uint32_t Count)
{
  WRITE_REG(I2Cx->SSSCLLCNT, Count);
}

/**
  * @brief  Get the SS SCL low period setting.
  * @rmtoll SSSCLLCNT      LCNT          LL_I2C_GetSSClockLowPeriod
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetSSClockLowPeriod(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->SSSCLLCNT));
}

/**
  * @brief  Set the SS SCL high period setting.
  * @rmtoll SSSCLHCNT      HCNT          LL_I2C_SetSSClockHighPeriod
  * @param  I2Cx I2C Instance.
  * @param  Count Value between Min_Data=0x00 and Max_Data=0xFF
  * 
  */
__STATIC_INLINE void LL_I2C_SetSSClockHighPeriod(I2C_TypeDef *I2Cx, uint32_t Count)
{
  WRITE_REG(I2Cx->SSSCLHCNT, Count);
}

/**
  * @brief  Get the SS SCL high period setting.
  * @rmtoll SSSCLHCNT      HCNT          LL_I2C_GetSSClockHighPeriod
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetSSClockHighPeriod(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->SSSCLHCNT));
}

/**
  * @brief  Set the FS SCL low period setting.
  * @rmtoll FSSCLLCNT      LCNT          LL_I2C_SetFSClockLowPeriod
  * @param  I2Cx I2C Instance.
  * @param  Count Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE void LL_I2C_SetFSClockLowPeriod(I2C_TypeDef *I2Cx, uint32_t Count)
{
  WRITE_REG(I2Cx->FSSCLLCNT, Count);
}

/**
  * @brief  Get the FS SCL low period setting.
  * @rmtoll FSSCLLCNT      LCNT          LL_I2C_GetFSClockLowPeriod
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetFSClockLowPeriod(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->FSSCLLCNT));
}

/**
  * @brief  Set the FS SCL high period setting.
  * @rmtoll FSSCLHCNT      HCNT          LL_I2C_SetFSClockHighPeriod
  * @param  I2Cx I2C Instance.
  * @param  Count Value between Min_Data=0x00 and Max_Data=0xFF
  * 
  */
__STATIC_INLINE void LL_I2C_SetFSClockHighPeriod(I2C_TypeDef *I2Cx, uint32_t Count)
{
  WRITE_REG(I2Cx->FSSCLHCNT, Count);
}

/**
  * @brief  Get the FS SCL high period setting.
  * @rmtoll FSSCLHCNT      HCNT          LL_I2C_GetFSClockHighPeriod
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetFSClockHighPeriod(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->FSSCLHCNT));
}

/**
  * @brief  Set the HS SCL low period setting.
  * @rmtoll SSSCLLCNT      LCNT          LL_I2C_SetHSClockLowPeriod
  * @param  I2Cx I2C Instance.
  * @param  Count Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE void LL_I2C_SetHSClockLowPeriod(I2C_TypeDef *I2Cx, uint32_t Count)
{
  WRITE_REG(I2Cx->HSSCLLCNT, Count);
}

/**
  * @brief  Get the HS SCL low period setting.
  * @rmtoll HSSCLLCNT      LCNT          LL_I2C_GetHSClockLowPeriod
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetHSClockLowPeriod(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->HSSCLLCNT));
}

/**
  * @brief  Set the HS SCL high period setting.
  * @rmtoll HSSCLHCNT      HCNT          LL_I2C_SetHSClockHighPeriod
  * @param  I2Cx I2C Instance.
  * @param  Count Value between Min_Data=0x00 and Max_Data=0xFF
  * 
  */
__STATIC_INLINE void LL_I2C_SetHSClockHighPeriod(I2C_TypeDef *I2Cx, uint32_t Count)
{
  WRITE_REG(I2Cx->HSSCLHCNT, Count);
}

/**
  * @brief  Get the hS SCL high period setting.
  * @rmtoll hSSCLHCNT      HCNT          LL_I2C_GethSClockHighPeriod
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x00 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GethSClockHighPeriod(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->HSSCLHCNT));
}

/**
  * @brief  Set the SDA TX hold time.
  * @rmtoll SDAHOLD      SDA_TX_HOLD        LL_I2C_SetTxDataHoldTime
  * @param  I2Cx I2C Instance.
  * @param  TxHold SDA Hold time in units of I2C_CLK.
  *         Value between Min_Data=0x0 and Max_Data=0xFFFF
  */
__STATIC_INLINE void LL_I2C_SetTxDataHoldTime(I2C_TypeDef *I2Cx, uint32_t TxHold)
{
  MODIFY_REG(I2Cx->SDAHOLD, I2C_SDAH_TX, TxHold << I2C_SDAH_TX_Pos);
}

/**
  * @brief  Get the SDA TX hold time.
  * @rmtoll SDAHOLD      SDA_TX_HOLD        LL_I2C_GetTxDataHoldTime
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xFFFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetTxDataHoldTime(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->SDAHOLD, I2C_SDAH_TX) >> I2C_SDAH_TX_Pos);
}

/**
  * @brief  Set the SDA RX hold time.
  * @rmtoll SDAHOLD      SDA_RX_HOLD        LL_I2C_SetRxDataHoldTime
  * @param  I2Cx I2C Instance.
  * @param  RxHold SDA Hold time in units of I2C_CLK.
  *         Value between Min_Data=0x0 and Max_Data=0xFF
  */
__STATIC_INLINE void LL_I2C_SetRxDataHoldTime(I2C_TypeDef *I2Cx, uint32_t RxHold)
{
  MODIFY_REG(I2Cx->SDAHOLD, I2C_SDAH_RX, RxHold << I2C_SDAH_RX_Pos);
}

/**
  * @brief  Get the SDA RX hold time.
  * @rmtoll SDAHOLD      SDA_RX_HOLD        LL_I2C_GetRxDataHoldTime
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetRxDataHoldTime(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->SDAHOLD, I2C_SDAH_RX) >> I2C_SDAH_RX_Pos);
}

/**
  * @brief  Set the SDA setup time.
  * @rmtoll SDASETUP      SDA_SETUP        LL_I2C_SetDataSetupTime
  * @param  I2Cx I2C Instance.
  * @param  Setup SDA setup time. (Setup-1)*(I2C_CLK)
  *               The parameter value between Min_Data=2 and Max_Data=0xFF.
  */
__STATIC_INLINE void LL_I2C_SetDataSetupTime(I2C_TypeDef *I2Cx,uint32_t Setup)
{
  WRITE_REG(I2Cx->SDASETUP, Setup);
}

/**
  * @brief  Get the SDA setup time.
  * @rmtoll SDASETUP      SDA_SETUP        LL_I2C_GetDataSetupTime
  * @param  I2Cx I2C Instance.
  * @retval Value between Min_Data=0x0 and Max_Data=0xFF
  */
__STATIC_INLINE uint32_t LL_I2C_GetDataSetupTime(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->SDASETUP));
}

/**
  * @brief  Configure I2C mode.
  * @rmtoll CON          MASTER_MODE          LL_I2C_SetMode\n
  *         CON          SLAVE_DSIABLE        LL_I2C_SetMode
  * @param  I2Cx I2C Instance.
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_I2C_MODE_MASTER
  *         @arg @ref LL_I2C_MODE_SLAVE
  */
__STATIC_INLINE void LL_I2C_SetMode(I2C_TypeDef *I2Cx, uint32_t Mode)
{
  MODIFY_REG(I2Cx->CON, I2C_CON_MMOD | I2C_CON_SLVDIS, Mode);
}

/**
  * @brief  Get peripheral mode.
  * @rmtoll CON          MASTER_MODE        LL_I2C_GetMode\n
  *         CON          SLAVE_DSIABLE        LL_I2C_GetMode
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_I2C_MODE_SLAVE
  *         @arg @ref LL_I2C_MODE_MASTER
  */
__STATIC_INLINE uint32_t LL_I2C_GetMode(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CON, I2C_CON_MMOD | I2C_CON_SLVDIS));
}

/**
  * @brief  Configure I2C Speed.
  * @rmtoll CON          SPEED          LL_I2C_SetSpeed
  * @param  I2Cx I2C Instance.
  * @param  Speed This parameter can be one of the following values:
  *         @arg @ref LL_I2C_SPEED_STANDARD_MODE
  *         @arg @ref LL_I2C_SPEED_FAST_MODE
  *         @arg @ref LL_I2C_SPEED_HIGH_MODE
  */
__STATIC_INLINE void LL_I2C_SetSpeed(I2C_TypeDef *I2Cx, uint32_t Speed)
{
  MODIFY_REG(I2Cx->CON, I2C_CON_SPEED, Speed);
}

/**
  * @brief  Get peripheral Speed.
  * @rmtoll CON          SPEED        LL_I2C_GetSpeed
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_I2C_SPEED_STANDARD_MODE
  *         @arg @ref LL_I2C_SPEED_FAST_MODE
  *         @arg @ref LL_I2C_SPEED_HIGH_MODE
  */
__STATIC_INLINE uint32_t LL_I2C_GetSpeed(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CON, I2C_CON_SPEED));
}

/**
  * @brief  Configure I2C Slave addressing.
  * @rmtoll CON          I2C_CON_10ASLV          LL_I2C_SetSlvAddressing
  * @param  I2Cx I2C Instance.
  * @param  Addressing This parameter can be one of the following values:
  *         @arg @ref LL_I2C_SLV_ADDRESSING_7BIT 
  *         @arg @ref LL_I2C_SLV_ADDRESSING_10BIT
  */
__STATIC_INLINE void LL_I2C_SetSlvAddressing(I2C_TypeDef *I2Cx, uint32_t Addressing)
{
  MODIFY_REG(I2Cx->CON, I2C_CON_10ASLV, Addressing);
}

/**
  * @brief  Get I2C Slave addressing.
  * @rmtoll CON          I2C_CON_10ASLV        LL_I2C_GetSlvAddressing
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_I2C_SLV_ADDRESSING_7BIT 
  *         @arg @ref LL_I2C_SLV_ADDRESSING_10BIT
  */
__STATIC_INLINE uint32_t LL_I2C_GetSlvAddressing(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CON, I2C_CON_10ASLV));
}

/**
  * @brief  Configure I2C Master addressing.
  * @rmtoll CON          I2C_CON_10AMST          LL_I2C_SetMstAddressing
  * @param  I2Cx I2C Instance.
  * @param  Addressing This parameter can be one of the following values:
  *         @arg @ref LL_I2C_MST_ADDRESSING_7BIT 
  *         @arg @ref LL_I2C_MST_ADDRESSING_10BIT
  */
__STATIC_INLINE void LL_I2C_SetMstAddressing(I2C_TypeDef *I2Cx, uint32_t Addressing)
{
  MODIFY_REG(I2Cx->CON, I2C_CON_10AMST, Addressing);
}

/**
  * @brief  Get I2C Master addressing.
  * @rmtoll CON          I2C_CON_10AMST        LL_I2C_GetMstAddressing
  * @param  I2Cx I2C Instance.
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_I2C_MST_ADDRESSING_7BIT 
  *         @arg @ref LL_I2C_MST_ADDRESSING_10BIT
  */
__STATIC_INLINE uint32_t LL_I2C_GetMstAddressing(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->CON, I2C_CON_10AMST));
}

/**
  * @brief  Enable I2C RESTART.
  * @rmtoll CON          I2C_CON_RESTARTEN            LL_I2C_EnableRestart
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_EnableRestart(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CON, I2C_CON_RESTARTEN);
}

/**
  * @brief  Disable I2C RESTART.
  * @rmtoll CON          I2C_CON_RESTARTEN            LL_I2C_EnableRestart
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_DisableRestart(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CON, I2C_CON_RESTARTEN);
}

/**
  * @brief  Check if the I2C RESTART is enabled or disabled.
  * @rmtoll CON          I2C_CON_RESTARTEN            LL_I2C_IsRestartEnabled
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsRestartEnabled(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CON, I2C_CON_RESTARTEN) == (I2C_CON_RESTARTEN)) ? 1UL : 0UL);
}

/**
  * @brief  Enable I2C STOP_DET if related with addressed.
  * @rmtoll CON          I2C_CON_STOPDETIFA            LL_I2C_StopDetWithAddr
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_StopDetWithAddr(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CON, I2C_CON_STOPDETIFA);
}

/**
  * @brief  Disable I2C STOP_DET if related with addressed.
  * @rmtoll CON          I2C_CON_RI2C_CON_STOPDETIFASTARTEN            LL_I2C_StopDetWithoutAddr
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_StopDetWithoutAddr(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CON, I2C_CON_STOPDETIFA);
}

/**
  * @brief  Check if the I2C STOP_DET if related with addressed.
  * @rmtoll CON          I2C_CON_STOPDETIFA            LL_I2C_IsStopDetWithAddr
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsStopDetWithAddr(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->CON, I2C_CON_STOPDETIFA) == (I2C_CON_STOPDETIFA)) ? 1UL : 0UL);
}

/**
  * @brief  Turn on TX_EMPTY control.
  * @rmtoll CON          I2C_CON_TXEMPCTRL            LL_I2C_TxEmptyControlOn
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_TxEmptyControlOn(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CON, I2C_CON_TXEMPCTRL);
}

/**
  * @brief  Turn off TX_EMPTY control.
  * @rmtoll CON          I2C_CON_TXEMPCTRL            LL_I2C_TxEmptyControlOff
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_TxEmptyControlOff(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CON, I2C_CON_TXEMPCTRL);
}

/**
  * @brief  Check if TX_EMPTY control tuen on.
  * @rmtoll CON          I2C_CON_TXEMPCTRL            LL_I2C_IsTxEmptyControOn
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsTxEmptyControlOn(I2C_TypeDef *I2Cx)
{
  return (uint32_t)((READ_BIT(I2Cx->CON, I2C_CON_TXEMPCTRL) == I2C_CON_TXEMPCTRL) ? 1UL : 0UL);
}

/**
  * @brief  Turn on TX_EMPTY control.
  * @rmtoll CON          I2C_CON_RXFHCTRL            LL_I2C_TxRxFiFOFullHoldControlOn
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_TxRxFiFOFullHoldControlOn(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->CON, I2C_CON_RXFHCTRL);
}

/**
  * @brief  Turn off TX_EMPTY control.
  * @rmtoll CON          I2C_CON_RXFHCTRL            LL_I2C_TxRxFiFOFullHoldControlOff
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_TxRxFiFOFullHoldControlOff(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->CON, I2C_CON_RXFHCTRL);
}

/**
  * @brief  Check if TX_EMPTY control tuen on.
  * @rmtoll CON          I2C_CON_RXFHCTRL            LL_I2C_IsTxRxFiFOFullHoldControlOn
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsTxRxFiFOFullHoldControlOn(I2C_TypeDef *I2Cx)
{
  return (uint32_t)((READ_BIT(I2Cx->CON, I2C_CON_RXFHCTRL) == I2C_CON_RXFHCTRL) ? 1UL : 0UL);
}

/**
  * @}
  */

/** @defgroup I2C_LL_Exported_Functions_Group2 IT_Management
  * @{
  */

/**
  * @brief  Mask RX_UNDER interrupt.
  * @rmtoll INTRMASK          RX_UNDER          LL_I2C_MaskIT_RXU
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_RXU(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RXU);
}

/**
  * @brief  Unmask RX_UNDER interrupt.
  * @rmtoll INTRMASK          RX_UNDER          LL_I2C_UnmaskIT_RXU
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_RXU(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RXU);
}

/**
  * @brief  Mask RX_OVER interrupt.
  * @rmtoll INTRMASK          RX_OVER          LL_I2C_MaskIT_RXO
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_RXO(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RXO);
}

/**
  * @brief  Unmask RX_OVER interrupt.
  * @rmtoll INTRMASK          RX_OVER          LL_I2C_UnmaskIT_RXO
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_RXO(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RXO);
}

/**
  * @brief  Mask RX_FULL interrupt.
  * @rmtoll INTRMASK          RX_FULL          LL_I2C_MaskIT_RXF
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_RXF(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RXF);
}

/**
  * @brief  Unmask RX_FULL interrupt.
  * @rmtoll INTRMASK          RX_FULL          LL_I2C_UnmaskIT_RXF
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_RXF(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RXF);
}

/**
  * @brief  Mask TX_OVER interrupt.
  * @rmtoll INTRMASK          TX_OVER          LL_I2C_MaskIT_TXO
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_TXO(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_TXO);
}

/**
  * @brief  Unmask TX_OVER interrupt.
  * @rmtoll INTRMASK          TX_OVER          LL_I2C_UnmaskIT_TXO
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_TXO(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_TXO);
}

/**
  * @brief  Mask TX_EMPTY interrupt.
  * @rmtoll INTRMASK          TX_EMPTY          LL_I2C_MaskIT_TXE
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_TXE(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_TXE);
}

/**
  * @brief  Unmask TX_EMPTY interrupt.
  * @rmtoll INTRMASK          TX_EMPTY          LL_I2C_UnmaskIT_TXE
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_TXE(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_TXE);
}

/**
  * @brief  Mask RD_REQ interrupt.
  * @rmtoll INTRMASK          RD_REQ          LL_I2C_MaskIT_RDReq
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_RDReq(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RDR);
}

/**
  * @brief  Unmask RD_REQ interrupt.
  * @rmtoll INTRMASK          RD_REQ          LL_I2C_UnmaskIT_RDReq
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_RDReq(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RDR);
}

/**
  * @brief  Mask TX_ABRT interrupt.
  * @rmtoll INTRMASK          TX_ABRT          LL_I2C_MaskIT_TxAbort
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_TxAbort(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_TXA);
}

/**
  * @brief  Unmask TX_ABRT interrupt.
  * @rmtoll INTRMASK          TX_ABRT          LL_I2C_UnmaskIT_TxAbort
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_TxAbort(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_TXA);
}

/**
  * @brief  Mask RX_DONE interrupt.
  * @rmtoll INTRMASK          RX_DONE          LL_I2C_MaskIT_RxDone
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_RxDone(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RXD);
}

/**
  * @brief  Unmask RX_DONE interrupt.
  * @rmtoll INTRMASK          RX_DONE          LL_I2C_UnmaskIT_RxDoneF
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_RxDone(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RXD);
}

/**
  * @brief  Mask ACTIVITY interrupt.
  * @rmtoll INTRMASK          ACTIVITY          LL_I2C_MaskIT_Activity
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_Activity(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_ACT);
}

/**
  * @brief  Unmask ACTIVITY interrupt.
  * @rmtoll INTRMASK          ACTIVITY          LL_I2C_UnmaskIT_Activity
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_Activity(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_ACT);
}

/**
  * @brief  Mask STOP_DET interrupt.
  * @rmtoll INTRMASK          STOP_DET          LL_I2C_MaskIT_StopDet
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_StopDet(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_STOPD);
}

/**
  * @brief  Unmask STOP_DET interrupt.
  * @rmtoll INTRMASK          STOP_DET          LL_I2C_UnmaskIT_StopDet
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_StopDet(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_STOPD);
}

/**
  * @brief  Mask START_DET interrupt.
  * @rmtoll INTRMASK          START_DET          LL_I2C_MaskIT_StartDet
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_StartDet(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_STARTD);
}

/**
  * @brief  Unmask START_DET interrupt.
  * @rmtoll INTRMASK          START_DET          LL_I2C_UnmaskIT_StartDet
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_StartDet(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_STARTD);
}
#if 0
/**
  * @brief  Mask RESTART_DET interrupt.
  * @rmtoll INTRMASK          RESTART_DET          LL_I2C_MaskIT_RestartDet
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_RestartDet(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RESD);
}

/**
  * @brief  Unmask RESTART_DET interrupt.
  * @rmtoll INTRMASK          RESTART_DET          LL_I2C_UnmaskIT_RestartDet
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_RestartDet(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_RESD);
}
#endif
/**
  * @brief  Mask GEN_CALL interrupt.
  * @rmtoll INTRMASK          GEN_CALL          LL_I2C_MaskIT_GeneralCall
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_GeneralCall(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_GCALL);
}

/**
  * @brief  Unmask GEN_CALL interrupt.
  * @rmtoll INTRMASK          GEN_CALL          LL_I2C_UnmaskIT_GeneralCall
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_GeneralCall(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_GCALL);
}
#if 0 
/**
  * @brief  Mask MST_ON_HOLD interrupt.
  * @rmtoll INTRMASK          MST_ON_HOLD          LL_I2C_MaskIT_MasterOnHold
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_MaskIT_MasterOnHold(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->INTRMASK, I2C_INTRMASK_MOH);
}

/**
  * @brief  Unmask MST_ON_HOLD interrupt.
  * @rmtoll INTRMASK          MST_ON_HOLD          LL_I2C_UnmaskIT_MasterOnHold
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_UnmaskIT_MasterOnHold(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->INTRMASK, I2C_INTRMASK_MOH);
}
#endif
/**
  * @}
  */

/** @defgroup I2C_LL_Exported_Functions_Group3 FLAG_management
  * @{
  */

/**
  * @brief  Indicate the status of I2C enabled.
  * @rmtoll ENABLESTATUS          EN          LL_I2C_IsEnableStatus_Enabled
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnableStatus_Enabled(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->ENABLESTATUS, I2C_ESTAT_EN) == (I2C_ESTAT_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of I2C enabled.
  * @rmtoll ENABLESTATUS          SLV_DISABLED_WHILE_BUSY          LL_I2C_IsEnableStatus_SlvDisabledWhileBusy
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnableStatus_SlvDisabledWhileBusy(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->ENABLESTATUS, I2C_ESTAT_BY) == (I2C_ESTAT_BY)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of I2C enabled.
  * @rmtoll ENABLESTATUS          SLV_RX_DATA_LOST          LL_I2C_IsEnableStatus_SlvRxDataLost
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnableStatus_SlvRxDataLost(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->ENABLESTATUS, I2C_ESTAT_SL) == (I2C_ESTAT_SL)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of activity.
  * @rmtoll STATUS          ACTIVITY           LL_I2C_IsActiveFlag_Activity
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveStatus_Activity(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STATUS, I2C_STATUS_ACT) == (I2C_STATUS_ACT)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of transmit FIFO not full.
  * @rmtoll STATUS          TFNF          LL_I2C_IsActiveFlag_TFNF
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveStatus_TFNF(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STATUS, I2C_STATUS_TFNF) == (I2C_STATUS_TFNF)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of transmit FIFO completely empty.
  * @rmtoll STATUS          TFE          LL_I2C_IsActiveFlag_TFE
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveStatus_TFE(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STATUS, I2C_STATUS_TFE) == (I2C_STATUS_TFE)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of receive FIFO not empty.
  * @rmtoll STATUS          RFNE          LL_I2C_IsActiveFlag_RFNE
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveStatus_RFNE(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STATUS, I2C_STATUS_RFNE) == (I2C_STATUS_RFNE)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of receive FIFO completely full.
  * @rmtoll STATUS          RFF         LL_I2C_IsActiveFlag_RFF
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveStatus_RFF(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STATUS, I2C_STATUS_RFF) == (I2C_STATUS_RFF)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master FSM activity.
  * @rmtoll STATUS          MST_ACTIVITY         LL_I2C_IsActiveFlag_MasterActivity
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveStatus_MasterActivity(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STATUS, I2C_STATUS_MSTA) == (I2C_STATUS_MSTA)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of slave FSM activity.
  * @rmtoll STATUS          SLV_ACTIVITY            LL_I2C_IsActiveFlag_SlaveActivity
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveStatus_SlaveActivity(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->STATUS, I2C_STATUS_SLVA) == (I2C_STATUS_SLVA)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master is in 7-bit addressing mode and the address sent was non acknowledged.
  * @rmtoll TXABRTSOURCE          ABRT_7B_ADDR_NOACK           LL_I2C_TxAbortSource_7BAddrNoack
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_7BAddrNoack(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_7ANACK) == (I2C_TXAS_7ANACK)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master is in 10-bit addressing mode and the 1st address byte sent was non acknowledged.
  * @rmtoll TXABRTSOURCE          ABRT_10B_ADDR1_NOACK           LL_I2C_TxAbortSource_10BAddr1Noack
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_10BAddr1Noack(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_10A1NA) == (I2C_TXAS_10A1NA)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master is in 10-bit addressing mode and the 2nd address byte sent was non acknowledged.
  * @rmtoll TXABRTSOURCE          ABRT_10B_ADDR2_NOACK           LL_I2C_TxAbortSource_10BAddr2Noack
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_10BAddr2Noack(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_10A2NA) == (I2C_TXAS_10A2NA)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master has received an ack for address but no ack for data.
  * @rmtoll TXABRTSOURCE          ABRT_TXDATA_NOACK           LL_I2C_TxAbortSource_TxDataNoack
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_TxDataNoack(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_TXNACK) == (I2C_TXAS_TXNACK)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master has not received ack for dGeneral Call.
  * @rmtoll TXABRTSOURCE          ABRT_GCALL_NOACK           LL_I2C_TxAbortSource_GeneralCallNoack
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_GeneralCallNoack(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_GCNACK) == (I2C_TXAS_GCNACK)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master sent General Call but user programmed read from the bus.
  * @rmtoll TXABRTSOURCE          ABRT_GCALL_READ           LL_I2C_TxAbortSource_GeneralCallRead
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_GeneralCallRead(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_GCRD) == (I2C_TXAS_GCRD)) ? 1UL : 0UL);
}

///**
//  * @brief  Indicate the status of master sent General Call but user programmed read from the bus.
//  * @rmtoll TXABRTSOURCE          ABRT_GCALL_READ           LL_I2C_TxAbortSource_GeneralCallRead
//  * @param  I2Cx I2C Instance.
//  * @retval State of bit (1 or 0).
//  */
//__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_GeneralCallRead(I2C_TypeDef *I2Cx)
//{
//  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_GCRD) == (I2C_TXAS_GCRD)) ? 1UL : 0UL);
//}

/**
  * @brief  Indicate the status of master in high speed mode and high speed master code was acknowledged.
  * @rmtoll TXABRTSOURCE          ABRT_HS_ACKDET           LL_I2C_TxAbortSource_HSAckDet
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_HSAckDet(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_HSADET) == (I2C_TXAS_HSADET)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master send START and the START was acknowledged.
  * @rmtoll TXABRTSOURCE          ABRT_SBYTE_ACKDET           LL_I2C_TxAbortSource_StartAckDet
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_StartAckDet(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_STBACK) == (I2C_TXAS_STBACK)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of disable restart when master transfer data in high speed mode.
  * @rmtoll TXABRTSOURCE          ABRT_HS_NORSTRT           LL_I2C_TxAbortSource_HSDiableRestart
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_HSDiableRestart(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_HSNRST) == (I2C_TXAS_HSNRST)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of disable restart when master transfer START.
  * @rmtoll TXABRTSOURCE          ABRT_HS_NORSTRT           LL_I2C_TxAbortSource_StartDiableRestart
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_StartDiableRestart(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_SBNRST) == (I2C_TXAS_SBNRST)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of disable restart when master send a read command in 10-bit addressing mode.
  * @rmtoll TXABRTSOURCE          ABRT_10B_RD_NORSTRT           LL_I2C_TxAbortSource_10BRDDiableRestart
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_10BRDDiableRestart(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_10BRNR) == (I2C_TXAS_10BRNR)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of disable master when user tries to operate master operation.
  * @rmtoll TXABRTSOURCE          ABRT_MASTER_DIS           LL_I2C_TxAbortSource_MasterDisabled
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_MasterDisabled(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_MSTDIS) == (I2C_TXAS_MSTDIS)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master has lost arbitration.
  * @rmtoll TXABRTSOURCE          ABRT_LOST           LL_I2C_TxAbortSource_MasterLost
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_MasterLost(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_LOST) == (I2C_TXAS_LOST)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of slave has received a read command and some data exists in the TX FIFO.
  * @rmtoll TXABRTSOURCE          ABRT_SLVFLUSH_TXFIFO           LL_I2C_TxAbortSource_SlaveFlushTxFIFO
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_SlaveFlushTxFIFO(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_SFTF) == (I2C_TXAS_SFTF)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of slave lost bus.
  * @rmtoll TXABRTSOURCE          ABRT_SLV_ARBLOST           LL_I2C_TxAbortSource_SlaveLost
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_SlaveLost(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_SLOST) == (I2C_TXAS_SLOST)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of slave response read data but user send read cmd.
  * @rmtoll TXABRTSOURCE          ABRT_SLVRD_INTX           LL_I2C_TxAbortSource_SlaveReadInTransmit
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_SlaveReadInTransmit(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_SRDITX) == (I2C_TXAS_SRDITX)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of master has detected the transfer abort.
  * @rmtoll TXABRTSOURCE          ABRT_USER_ABRT           LL_I2C_TxAbortSource_UserAbort
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_UserAbort(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_USERAB) == (I2C_TXAS_USERAB)) ? 1UL : 0UL);
}

/**
  * @brief  Get Tx FIFO level value prior to the last TX_ABRT event.
  * @rmtoll TXABRTSOURCE          ABRT_TX_FLUSH_CNT           LL_I2C_TxAbortSource_TxFIFOLevelInLastTxAbort
  * @param  I2Cx I2C Instance.
  * @retval the value is between 0 to 0xFF.
  */
__STATIC_INLINE uint32_t LL_I2C_TxAbortSource_TxFIFOLevelInLastTxAbort(I2C_TypeDef *I2Cx)
{
  return ((uint32_t)(READ_BIT(I2Cx->TXABRTSOURCE, I2C_TXAS_FCNT) >> I2C_TXAS_FCNT_Pos));
}

/**
  * @brief  Indicate the status of interrupt RX_UNDER.
  * @rmtoll RAWINTRSTAT          RX_UNDER          LL_I2C_IsActiveFlag_RXU
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_RXU(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_RXU) == (I2C_RINTRSTAT_RXU)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt RX_OVER.
  * @rmtoll RAWINTRSTAT          RX_OVER          LL_I2C_IsActiveFlag_RXO
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_RXO(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_RXO) == (I2C_RINTRSTAT_RXO)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt RX_FULL.
  * @rmtoll RAWINTRSTAT          RX_FULL          LL_I2C_IsActiveFlag_RXF
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_RXF(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_RXF) == (I2C_RINTRSTAT_RXF)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt TX_OVER.
  * @rmtoll RAWINTRSTAT          TX_OVER          LL_I2C_IsActiveFlag_TXO
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TXO(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_TXO) == (I2C_RINTRSTAT_TXO)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt TX_EMPTY.
  * @rmtoll RAWINTRSTAT          TX_EMPTY          LL_I2C_IsActiveFlag_TXE
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TXE(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_TXE) == (I2C_RINTRSTAT_TXE)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt RD_REQ.
  * @rmtoll RAWINTRSTAT          RD_REQ          LL_I2C_IsActiveFlag_RDReq
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_RDReq(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_RDR) == (I2C_RINTRSTAT_RDR)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt TX_ABRT.
  * @rmtoll RAWINTRSTAT          TX_ABRT          LL_I2C_IsActiveFlag_TxAbort
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_TxAbort(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_TXA) == (I2C_RINTRSTAT_TXA)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt RX_DONE.
  * @rmtoll RAWINTRSTAT          RX_DONE          LL_I2C_IsActiveFlag_RxDone
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_RxDone(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_RXD) == (I2C_RINTRSTAT_RXD)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt ACTIVITY.
  * @rmtoll RAWINTRSTAT          ACTIVITY          LL_I2C_IsActiveFlag_Activity
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_Activity(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_ACT) == (I2C_RINTRSTAT_ACT)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt STOP_DET.
  * @rmtoll RAWINTRSTAT          STOP_DET          LL_I2C_IsActiveFlag_StopDet
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_StopDet(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_STOPD) == (I2C_RINTRSTAT_STOPD)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt START_DET.
  * @rmtoll RAWINTRSTAT          START_DET          LL_I2C_IsActiveFlag_StartDet
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_StartDet(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_STARTD) == (I2C_RINTRSTAT_STARTD)) ? 1UL : 0UL);
}

/**
  * @brief  Indicate the status of interrupt GEN_CALL.
  * @rmtoll RAWINTRSTAT          GEN_CALL          LL_I2C_IsActiveFlag_GeneralCall
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_GeneralCall(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_GCALL) == (I2C_RINTRSTAT_GCALL)) ? 1UL : 0UL);
}
#if 0
/**
  * @brief  Indicate the status of interrupt RESTART_DET.
  * @rmtoll RAWINTRSTAT          RESTART_DET          LL_I2C_IsActiveFlag_RestartDet
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_RestartDet(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_RESD) == (I2C_RINTRSTAT_RESD)) ? 1UL : 0UL);
}


/**
  * @brief  Indicate the status of interrupt MST_ON_HOLD.
  * @rmtoll RAWINTRSTAT          MST_ON_HOLD          LL_I2C_IsActiveFlag_MasterOnHold
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsActiveFlag_MasterOnHold(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->RAWINTRSTAT, I2C_RINTRSTAT_MOH) == (I2C_RINTRSTAT_MOH)) ? 1UL : 0UL);
}
#endif
/**
  * @brief  Clear all interrupt flags and Tx abort source status.
  * @rmtoll ICRINTR          CLR_INTR        LL_I2C_ClearFlag_All
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_All(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRINTR);
}


/**
  * @brief  Clear RX_UNDER.
  * @rmtoll ICRRXUNDER          CLR        LL_I2C_ClearFlag_RXU
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_RXU(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRRXUNDER);
}

/**
  * @brief  Clear RX_OVER.
  * @rmtoll ICRRXOVER          CLR        LL_I2C_ClearFlag_RXO
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_RXO(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRRXOVER);
}

/**
  * @brief  Clear TX_OVER.
  * @rmtoll ICRTXOVER          CLR        LL_I2C_ClearFlag_TXO
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_TXO(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRTXOVER);
}

/**
  * @brief  Clear RD_REQ.
  * @rmtoll ICRRDREQ          CLR        LL_I2C_ClearFlag_RDReq
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_RDReq(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRRDREQ);
}

/**
  * @brief  Clear TX_ABRT.
  * @rmtoll ICRTXABRT          CLR        LL_I2C_ClearFlag_TxAbort
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_TxAbort(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRTXABRT);
}

/**
  * @brief  Clear RX_DONE.
  * @rmtoll ICRRXDONE          CLR        LL_I2C_ClearFlag_RxDone
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_RxDone(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRRXDONE);
}

/**
  * @brief  Clear ACTIVITY.
  * @rmtoll ICRACTIVITY          CLR        LL_I2C_ClearFlag_Activity
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_Activity(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRACTIVITY);
}

/**
  * @brief  Clear Stop detection flag.
  * @rmtoll ICRSTOPDET          CLR        LL_I2C_ClearFlag_STOP
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_Stop(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRSTOPDET);
}

/**
  * @brief  Clear Start detection flag.
  * @rmtoll ICRSTOPDET          CLR        LL_I2C_ClearFlag_Start
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_Start(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRSTARTDET);
}

/**
  * @brief  Clear Restart detection flag.
  * @rmtoll ICRSTOPDET          CLR        LL_I2C_ClearFlag_Restart
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_Restart(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRSTARTDET);
}

/**
  * @brief  Clear General Call detection flag.
  * @rmtoll ICRGEMCALL          CLR        LL_I2C_ClearFlag_GenralCall
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_ClearFlag_GenralCall(I2C_TypeDef *I2Cx)
{
  READ_REG(I2Cx->CLRGENCALL);
}

/**
  * @}
  */

/** @defgroup I2C_LL_Exported_Functions_Group4 Data_Management
  * @{
  */
#if 0
/**
  * @brief  Prepare the generation of a Non ACKnowledge condition after the address receive next received byte.
  * @rmtoll SLVDATANACKONLY          NACK          LL_I2C_NonAcknowledgeNextData
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_NonAcknowledgeNextData(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->SLVDATANACKONLY, I2C_SDNACK_NACK);
}
#endif
/**
  * @brief  Enable I2C peripheral (PE = 1).
  * @rmtoll ENABLE          ENABLE            LL_I2C_Enable
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_Enable(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ENABLE, I2C_ENABLE_EN);
}

/**
  * @brief  Disable I2C peripheral (PE = 0).
  * @note   When PE = 0, the I2C SCL and SDA lines are released.
  *         Internal state machines and status bits are put back to their reset value.
  *         When cleared, PE must be kept low for at least 3 APB clock cycles.
  * @rmtoll ENABLE          ENABLE            LL_I2C_Disable
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_Disable(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->ENABLE, I2C_ENABLE_EN);
}

/**
  * @brief  Check if the I2C peripheral is enabled or disabled.
  * @rmtoll ENABLE          ENABLE            LL_I2C_IsEnabled
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsEnabled(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->ENABLE, I2C_ENABLE_EN) == (I2C_ENABLE_EN)) ? 1UL : 0UL);
}

/**
  * @brief  Abort I2C transfer.
  * @rmtoll ENABLE          ABORT            LL_I2C_Abort
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_Abort(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->ENABLE, I2C_ENABLE_AB);
}

/**
  * @brief  Check if the I2C abort is done.
  * @rmtoll ENABLE          ABORT            LL_I2C_IsAborted
  * @param  I2Cx I2C Instance.
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_I2C_IsAborted(I2C_TypeDef *I2Cx)
{
  return ((READ_BIT(I2Cx->ENABLE, I2C_ENABLE_AB) == (I2C_ENABLE_AB)) ? 0UL : 1UL);
}

#if 0
/**
  * @brief  Set I2C target addressing mode.
  * @rmtoll TAR          I2C_TAR_10AMST            LL_I2C_SetTargetAddressingMode
  * @param  I2Cx I2C Instance.
  * @param  Mode the value can be one of the follwing:
            @arg @ref LL_I2C_7BIT_ADDRESSING            
            @arg @ref LL_I2C_10BIT_ADDRESSING           
  */
__STATIC_INLINE void LL_I2C_SetTargetAddressingMode(I2C_TypeDef *I2Cx, uint32_t Mode)
{
  MODIFY_REG(I2Cx->TAR, I2C_TAR_10AMST, Mode);
}

/**
  * @brief  Get I2C target addressing mode.
  * @rmtoll TAR          I2C_TAR_10AMST            LL_I2C_GetTargetAddressingMode
  * @param  I2Cx I2C Instance.
  * @retval the value can be one of the follwing:
            @arg @ref LL_I2C_7BIT_ADDRESSING            
            @arg @ref LL_I2C_10BIT_ADDRESSING           
  */
__STATIC_INLINE uint32_t LL_I2C_GetTargetAddressingMode(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->TAR, I2C_TAR_10AMST));
}
#endif
/**
  * @brief  Transfer I2C target General Call command.
  * @rmtoll TAR          SPECIAL            LL_I2C_XferTargetGeneralCall\n
  * @rmtoll TAR          GC_OR_START        LL_I2C_XferTargetGeneralCall
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_XferTargetGeneralCall(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->TAR, I2C_TAR_SPECIAL);
  CLEAR_BIT(I2Cx->TAR, I2C_TAR_GCORSTART);
}

/**
  * @brief  Transfer I2C target Start command.
  * @rmtoll TAR          SPECIAL            LL_I2C_XferTargetStart\n
  * @rmtoll TAR          GC_OR_START        LL_I2C_XferTargetStart
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_XferTargetStart(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->TAR, I2C_TAR_SPECIAL);
  SET_BIT(I2Cx->TAR, I2C_TAR_GCORSTART);
}

/**
  * @brief  Set I2C target address.
  * @rmtoll TAR          SPECIAL                   LL_I2C_SetTargetAddress\n
  * @rmtoll TAR          TAR                       LL_I2C_SetTargetAddress
  * @param  I2Cx I2C Instance.
  * @param  Address the value is between Min_data = 0x000 and Max_data=0x3FF
  */
__STATIC_INLINE void LL_I2C_SetTargetAddress(I2C_TypeDef *I2Cx, uint32_t Address)
{
  CLEAR_BIT(I2Cx->TAR, I2C_TAR_SPECIAL);
  MODIFY_REG(I2Cx->TAR, I2C_TAR_TAR, Address);
}

#if 0
/**
  * @brief  Turn on I2C RESTART command.
  * @rmtoll DATACMD          RESTART                       LL_I2C_RestartOn
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_RestartOn(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->DATACMD, I2C_DATACMD_RESTART);
}

/**
  * @brief  Turn off I2C RESTART command.
  * @rmtoll DATACMD          RESTART                       LL_I2C_RestartOff
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_RestartOff(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->DATACMD, I2C_DATACMD_RESTART);
}

/**
  * @brief  Turn on I2C STOP command.
  * @rmtoll DATACMD          STOP                       LL_I2C_StopOn
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_StopOn(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->DATACMD, I2C_DATACMD_STOP);
}

/**
  * @brief  Turn off I2C STOP command.
  * @rmtoll DATACMD          STOP                       LL_I2C_StopOff
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_StopOff(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->DATACMD, I2C_DATACMD_STOP);
}
#endif

/**
  * @brief  Turn on I2C Read command.
  * @rmtoll DATACMD          CMD                       LL_I2C_CmdRead
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_CmdRead(I2C_TypeDef *I2Cx)
{
  SET_BIT(I2Cx->DATACMD, I2C_DATACMD_CMD);
}

/**
  * @brief  Turn on I2C Write command.
  * @rmtoll DATACMD          CMD                       LL_I2C_CmdWrite
  * @param  I2Cx I2C Instance.
  */
__STATIC_INLINE void LL_I2C_CmdWrite(I2C_TypeDef *I2Cx)
{
  CLEAR_BIT(I2Cx->DATACMD, I2C_DATACMD_CMD);
}

/**
  * @brief  Set I2C Data.
  * @rmtoll DATACMD          DAT                       LL_I2C_SetData
  * @param  I2Cx I2C Instance.
  * @param  Data the value can be one between 0x00 to 0xFF.
  */
__STATIC_INLINE void LL_I2C_SetData(I2C_TypeDef *I2Cx, uint32_t Data)
{
  MODIFY_REG(I2Cx->DATACMD, I2C_DATACMD_DAT, Data);
}

/**
  * @brief  Get I2C Data.
  * @rmtoll DATACMD          DAT                       LL_I2C_GetData
  * @param  I2Cx I2C Instance.
  * @retval The value can be one between 0x00 to 0xFF.
  */
__STATIC_INLINE uint32_t LL_I2C_GetData(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_BIT(I2Cx->DATACMD, I2C_DATACMD_DAT));
}

/**
  * @brief  Set I2C receive FIFO threshold.
  * @rmtoll RXTL          RXTL                       LL_I2C_SetRxFIFOThreshold
  * @param  I2Cx I2C Instance.
  * @param  Threshold the value can be one between 0x00 to 0xFF.
  */
__STATIC_INLINE void LL_I2C_SetRxFIFOThreshold(I2C_TypeDef *I2Cx, uint32_t Threshold)
{
  WRITE_REG(I2Cx->RXTL, Threshold);
}

/**
  * @brief  Get I2C receive FIFO threshold.
  * @rmtoll RXTL          RXTL                       LL_I2C_GetRxFIFOThreshold
  * @param  I2Cx I2C Instance.
  * @retval The value can be one between 0x00 to 0xFF.
  */
__STATIC_INLINE uint32_t LL_I2C_GetRxFIFOThreshold(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->RXTL));
}

/**
  * @brief  Set I2C transmit FIFO threshold.
  * @rmtoll TXTL          TXTL                       LL_I2C_SetTxFIFOThreshold
  * @param  I2Cx I2C Instance.
  * @param  Threshold the value can be one between 0x00 to 0xFF.
  */
__STATIC_INLINE void LL_I2C_SetTxFIFOThreshold(I2C_TypeDef *I2Cx, uint32_t Threshold)
{
  WRITE_REG(I2Cx->TXTL, Threshold);
}

/**
  * @brief  Get I2C transmit FIFO threshold.
  * @rmtoll TXTL          TXTL                       LL_I2C_GetTxFIFOThreshold
  * @param  I2Cx I2C Instance.
  * @retval The value can be one between 0x00 to 0xFF.
  */
__STATIC_INLINE uint32_t LL_I2C_GetTxFIFOThreshold(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->TXTL));
}

/**
  * @brief  Get I2C transmit FIFO level.
  * @rmtoll TXFLR          TXFLR                       LL_I2C_GetTxFIFOLevel
  * @param  I2Cx I2C Instance.
  * @retval The value can be one between 0x00 to 0x1FF.
  */
__STATIC_INLINE uint32_t LL_I2C_GetTxFIFOLevel(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->TXFLR));
}

/**
  * @brief  Get I2C receive FIFO level.
  * @rmtoll RXFLR          RXFLR                       LL_I2C_GetRxFIFOLevel
  * @param  I2Cx I2C Instance.
  * @retval The value can be one between 0x00 to 0x1FF.
  */
__STATIC_INLINE uint32_t LL_I2C_GetRTxFIFOLevel(I2C_TypeDef *I2Cx)
{
  return (uint32_t)(READ_REG(I2Cx->RXFLR));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup I2C_LL_Exported_Functions_Group5 Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_I2C_Init(I2C_TypeDef *I2Cx, LL_I2C_InitTypeDef *I2C_InitStruct);
ErrorStatus LL_I2C_DeInit(I2C_TypeDef *I2Cx);
void LL_I2C_StructInit(LL_I2C_InitTypeDef *I2C_InitStruct);


/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

#endif /* I2C1 || I2C2 */

/**
  * @}
  */

/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif /* XT32H0xx_LL_I2C_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
