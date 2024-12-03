/**
  ******************************************************************************
  * @file    xt32h0xx_i2c.h
  * @author  Software Team
  * @date    28 June 2022 
  * @brief   This file contains all the functions prototypes for the I2C firmware
  *          library
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech..
  * All rights reserved.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __XT32H0XX_I2C_H
#define __XT32H0XX_I2C_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx.h"

/** @addtogroup XT32H0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup I2C_Exported_Types I2C Exported Types
  * @{
  */

/**
  * @brief  I2C Init structure definition
  */

typedef struct
{
  uint32_t I2C_BaudRate;            /*!< Specifies the I2C baudrate value.
                                         This parameter must be set by referring to I2C_ConfigTiming()*/

  uint32_t I2C_Mode;                /*!< Specifies the I2C mode.
                                         This parameter can be a value of @ref I2C_Mode*/

  uint32_t I2C_SlaveAddress;        /*!< Specifies the device own address in slave mode.
                                         This parameter can be a 7-bit or 10-bit address*/

  uint32_t I2C_SlaveAddressing;     /*!< Specifies if 7-bit or 10-bit address is acknowledged.
                                         This parameter can be a value of @ref I2C_ADDRESSING*/

  uint32_t I2C_MasterAddressing;    /*!< Specifies if 7-bit or 10-bit address is acknowledged.
                                         This parameter can be a value of @ref I2C_ADDRESSING*/

  uint32_t I2C_SpeedMode;           /*!< Specifies the I2C speed mode.
                                         This parameter can be a value of @ref I2C_SPEED*/
}I2C_InitTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/


/** @defgroup I2C_Exported_Constants I2C Exported Constants
  * @{
  */

/** @defgroup I2C_Peripheral I2C Peripheral
  * @{
  */

#define IS_I2C_ALL_PERIPH(PERIPH)       (((PERIPH) == I2C1) || \
                                         ((PERIPH) == I2C2))
                                         
#define IS_I2C_1_PERIPH(PERIPH)         ((PERIPH) == I2C1) 
#define IS_I2C_2_PERIPH(PERIPH)         ((PERIPH) == I2C2) 
/**
  * @}
  */

/** @defgroup I2C_Mode I2C Mode
  * @{
  */

#define I2C_MODE_SLAVE                 (0x00000000U)                           /*!< I2C Slave mode                               */
#define I2C_MODE_MASTER                (I2C_CON_MMOD | I2C_CON_SLVDIS)         /*!< I2C Master mode                              */

#define IS_I2C_MODE(MODE)               (((MODE) == I2C_MODE_SLAVE) || ((MODE) == I2C_MODE_MASTER))
/**
  * @}
  */

/** @defgroup I2C_SPEED I2C Speed
  * @{
  */
#define I2C_SPEED_STANDARD             (I2C_CON_SPEED_0)                       /*!< I2C speed standard                           */
#define I2C_SPEED_FAST                 (I2C_CON_SPEED_1)                       /*!< I2C speed fast                               */
#define I2C_SPEED_HIGH                 (I2C_CON_SPEED_1|I2C_CON_SPEED_0)       /*!< I2C speed high                               */

#define IS_I2C_SPEED_MODE(MODE)       (((MODE) == I2C_SPEED_STANDARD) || \
                                       ((MODE) == I2C_SPEED_FAST) || \
                                       ((MODE) == I2C_SPEED_HIGH))
/**
  * @}
  */

/** @defgroup I2C_ADDRESSING I2C addressing
  * @{
  */
#define I2C_SLV_ADDRESSING_7BIT        (0x00000000U)                           /*!< I2C 7-bit addressing                        */
#define I2C_SLV_ADDRESSING_10BIT       (I2C_CON_10ASLV)                        /*!< I2C 10-bit addressing                       */

#define I2C_MST_ADDRESSING_7BIT        (0x00000000U)                           /*!< I2C 7-bit addressing                        */
#define I2C_MST_ADDRESSING_10BIT       (I2C_CON_10AMST)                        /*!< I2C 10-bit addressing                       */
/**
  * @}
  */

/** @defgroup I2C_CMD I2C command
  * @{
  */
#define I2C_CMD_WRITE                  (0x00000000U)                           /*!< I2C write */
#define I2C_CMD_READ                   (I2C_DATACMD_CMD)                       /*!< I2C read */

#define IS_I2C_CMD(CMD)             (((CMD) == I2C_CMD_WRITE) || ((CMD) == I2C_CMD_READ))
/**
  * @}
  */

/** @defgroup I2C_DMA_transfer_requests I2C DMA Request
  * @{
  */

#define I2C_DMAREQ_TX                  (I2C_DMACR_TDMAE)
#define I2C_DMAREQ_RX                  (I2C_DMACR_RDMAE)

#define IS_I2C_DMA_REQ(REQ)           (((REQ) == I2C_DMAREQ_TX) || ((REQ) == I2C_DMAREQ_RX))
/**
  * @}
  */

/** @defgroup I2C_slave_address I2C Slave Address
  * @{
  */

#define IS_I2C_SLAVE_ADDRESS(ADDRESS)   ((ADDRESS) <= (uint16_t)0x03FF)
/**
  * @}
  */


/** @defgroup I2C_timeout I2C Timeout
  * @{
  */

#define IS_I2C_TIMEOUT(TIMEOUT)   ((TIMEOUT) <= (uint16_t)0x0FFF)

/**
  * @}
  */

/** @defgroup I2C_interrupts_definition I2C Interrupts
  * @{
  */

#define I2C_IT_RX_UNDER               (I2C_INTRSTAT_RXU   )                    /*!< RX_UNDER                                    */
#define I2C_IT_RX_OVER                (I2C_INTRSTAT_RXO   )                    /*!< RX_OVER                                     */
#define I2C_IT_RX_FULL                (I2C_INTRSTAT_RXF   )                    /*!< RX_FULL                                     */
#define I2C_IT_TX_OVER                (I2C_INTRSTAT_TXO   )                    /*!< TX_OVER                                     */
#define I2C_IT_TX_EMPTY               (I2C_INTRSTAT_TXE   )                    /*!< TX_EMPTY                                    */
#define I2C_IT_RD_REQ                 (I2C_INTRSTAT_RDR   )                    /*!< RD_REQ                                      */
#define I2C_IT_TX_ABRT                (I2C_INTRSTAT_TXA   )                    /*!< TX_ABRT                                     */
#define I2C_IT_RX_DONE                (I2C_INTRSTAT_RXD   )                    /*!< RX_DONE                                     */
#define I2C_IT_ACTIVITY               (I2C_INTRSTAT_ACT   )                    /*!< ACTIVITY                                    */
#define I2C_IT_STOP_DET               (I2C_INTRSTAT_STOPD )                    /*!< STOP_DET                                    */
#define I2C_IT_START_DET              (I2C_INTRSTAT_STARTD)                    /*!< START_DET                                   */
#define I2C_IT_GEN_CALL               (I2C_INTRSTAT_GCALL )                    /*!< GEN_CALL                                    */
//#define I2C_IT_RESTART_DET            (I2C_INTRSTAT_RESD  )                    /*!< RESTART_DET                                 */
//#define I2C_IT_MST_ON_HOLD            (I2C_INTRSTAT_MOH   )                    /*!< MST_ON_HOLD                                 */
#define I2C_IT_ALL                   ( I2C_INTRSTAT_RXU     \
                                     | I2C_INTRSTAT_RXO     \
                                     | I2C_INTRSTAT_RXF     \
                                     | I2C_INTRSTAT_TXO     \
                                     | I2C_INTRSTAT_TXE     \
                                     | I2C_INTRSTAT_RDR     \
                                     | I2C_INTRSTAT_TXA     \
                                     | I2C_INTRSTAT_RXD     \
                                     | I2C_INTRSTAT_ACT     \
                                     | I2C_INTRSTAT_STOPD   \
                                     | I2C_INTRSTAT_STARTD  \
                                     | I2C_INTRSTAT_GCALL) //  \
                                     | I2C_INTRSTAT_RESD    \
                                     | I2C_INTRSTAT_MOH)

#define IS_I2C_CONFIG_IT(IT)            ((((IT) & (uint32_t)(~I2C_IT_ALL)) == 0x00) && ((IT) != 0x00))

/**
  * @}
  */

/** @defgroup I2C_Status_Definition I2C Status
  * @{
  */
#define I2C_STAT_ACTIVITY              (I2C_STATUS_ACT )                       /*!< I2C activity status               */
#define I2C_STAT_TFNF                  (I2C_STATUS_TFNF)                       /*!< Transmit FIFO not full            */
#define I2C_STAT_TFE                   (I2C_STATUS_TFE )                       /*!< Transmit FIFO completely empty    */
#define I2C_STAT_RFNE                  (I2C_STATUS_RFNE)                       /*!< Receive FIFO not empty            */
#define I2C_STAT_RFF                   (I2C_STATUS_RFF )                       /*!< Receive FIFO completely full      */
#define I2C_STAT_MST_ACTIVITY          (I2C_STATUS_MSTA)                       /*!< Master FSM activity status        */
#define I2C_STAT_SLV_ACTIVITY          (I2C_STATUS_SLVA)                       /*!< Slave FSM activity status         */
#define I2C_STAT_ALL                 (I2C_STAT_ACTIVITY | I2C_STAT_TFNF | \
                                      I2C_STAT_TFE | I2C_STAT_RFNE | \
                                      I2C_STAT_RFF | I2C_STAT_MST_ACTIVITY | \
                                      I2C_STAT_SLV_ACTIVITY)

#define IS_I2C_CLEAR_FLAG(FLAG)         ((((FLAG) & (uint32_t)(~I2C_STAT_ALL)) == 0x00) && ((FLAG) != 0x00))

#define IS_I2C_GET_FLAG(FLAG)           (((FLAG) == I2C_STAT_ACTIVITY) || ((FLAG) == I2C_STAT_TFNF) || \
                                         ((FLAG) == I2C_STAT_TFE) || ((FLAG) == I2C_STAT_RFNE) || \
                                         ((FLAG) == I2C_STAT_RFF) || ((FLAG) == I2C_STAT_MST_ACTIVITY) || \
                                         ((FLAG) == I2C_STAT_SLV_ACTIVITY))

/**
  * @}
  */


/** @defgroup I2C_Flag_Definitions I2C Flags
  * @{
  */

#define I2C_FLAG_RX_UNDER              (I2C_INTRSTAT_RXU   )                   /*!< RX_UNDER                                    */
#define I2C_FLAG_RX_OVER               (I2C_INTRSTAT_RXO   )                   /*!< RX_OVER                                     */
#define I2C_FLAG_RX_FULL               (I2C_INTRSTAT_RXF   )                   /*!< RX_FULL                                     */
#define I2C_FLAG_TX_OVER               (I2C_INTRSTAT_TXO   )                   /*!< TX_OVER                                     */
#define I2C_FLAG_TX_EMPTY              (I2C_INTRSTAT_TXE   )                   /*!< TX_EMPTY                                    */
#define I2C_FLAG_RD_REQ                (I2C_INTRSTAT_RDR   )                   /*!< RD_REQ                                      */
#define I2C_FLAG_TX_ABRT               (I2C_INTRSTAT_TXA   )                   /*!< TX_ABRT                                     */
#define I2C_FLAG_RX_DONE               (I2C_INTRSTAT_RXD   )                   /*!< RX_DONE                                     */
#define I2C_FLAG_ACTIVITY              (I2C_INTRSTAT_ACT   )                   /*!< ACTIVITY                                    */
#define I2C_FLAG_STOP_DET              (I2C_INTRSTAT_STOPD )                   /*!< STOP_DET                                    */
#define I2C_FLAG_START_DET             (I2C_INTRSTAT_STARTD)                   /*!< START_DET                                   */
#define I2C_FLAG_GEN_CALL              (I2C_INTRSTAT_GCALL )                   /*!< GEN_CALL                                    */
#define I2C_FLAG_RESTART_DET           (I2C_INTRSTAT_RESD  )                   /*!< RESTART_DET                                 */
#define I2C_FLAG_MST_ON_HOLD           (I2C_INTRSTAT_MOH   )                   /*!< MST_ON_HOLD                                 */

#define IS_I2C_CLEAR_IT(IT)             ((((IT) & (uint32_t)(~I2C_IT_ALL)) == 0x00) && ((IT) != 0x00))
                               
#define IS_I2C_GET_IT(FLAG)             (((FLAG) == I2C_FLAG_RX_UNDER) || ((FLAG) == I2C_FLAG_RX_OVER) || \
                                         ((FLAG) == I2C_FLAG_RX_FULL) || ((FLAG) == I2C_FLAG_TX_OVER) || \
                                         ((FLAG) == I2C_FLAG_TX_EMPTY) || ((FLAG) == I2C_FLAG_RD_REQ) || \
                                         ((FLAG) == I2C_FLAG_TX_ABRT) || ((FLAG) == I2C_FLAG_RX_DONE) || \
                                         ((FLAG) == I2C_FLAG_ACTIVITY) || ((FLAG) == I2C_FLAG_STOP_DET) || \
                                         ((FLAG) == I2C_FLAG_START_DET) || ((FLAG) == I2C_FLAG_GEN_CALL) || \
                                         ((FLAG) == I2C_FLAG_RESTART_DET) || ((FLAG) == I2C_FLAG_MST_ON_HOLD))

                               

/**
  * @}
  */

/** @defgroup I2C_Tx_Abort_Source_definition I2C Tx abort source Definition
  * @{
  */
#define I2C_ABRT_7B_ADDR_NOACK         (I2C_TXAS_7ANACK)                       /*!< Not receive an acknowledgement in 7-bit addressing mode        */
#define I2C_ABRT_10ADDR1_NOACK         (I2C_TXAS_10A1NA)                       /*!< Not receive an acknowledgement for 10-bit address first byte */
#define I2C_ABRT_10ADDR2_NOACK         (I2C_TXAS_10A2NA)                       /*!< Not receive an acknowledgement for 10-bit address second byte     */
#define I2C_ABRT_TXDATA_NOACK          (I2C_TXAS_TXNACK)                       /*!< Not receive an acknowledgement for data */
#define I2C_ABRT_GCALL_NOACK           (I2C_TXAS_GCNACK)                       /*!< Master sent a General Call and no slave onthe bus acknowledged the General Call */
#define I2C_ABRT_GCALL_READ            (I2C_TXAS_GCRD  )                       /*!< Master sent a Generak Cakk but the user programmed the byte following the General Call to be a read from the bus */
#define I2C_ABRT_HS_ACKDET             (I2C_TXAS_HSADET)                       /*!< Master in High Speed mode and High Speed Master code was acknownledged */
#define I2C_ABRT_SBYTE_ACKDET          (I2C_TXAS_STBACK)                       /*!< Master has sent a START Byte and the START Byte was acknowledged */
#define I2C_ABRT_HS_NORSTRT            (I2C_TXAS_HSNRST)                       /*!< The restart is disabled and the user is trying to use the master to transfer data in High Speed mode */
#define I2C_ABRT_SBYTE_NORSTRT         (I2C_TXAS_SBNRST)                       /*!< To clear Bit 9 */
#define I2C_ABRT_10B_RD_NORSTRT        (I2C_TXAS_10BRNR)                       /*!< The restart is disabled and the master sends a read command in 10-bit addressing mode */
#define I2C_ABRT_MASTER_DIS            (I2C_TXAS_MSTDIS)                       /*!< User initiate a master operation with the master mode disabled */
#define I2C_ABRT_LOST                  (I2C_TXAS_LOST  )                       /*!< Master has lost arbitration */
#define I2C_ABRT_SLVFLUSH_TXFIFO       (I2C_TXAS_SFTF  )                       /*!< Slave has received a read command and some data exists in the TX FIFO */
#define I2C_ABRT_SLV_ARBLOST           (I2C_TXAS_SLOST )                       /*!< Slave lost bus while transmitting data to a remote master         */
#define I2C_ABRT_SLVRD_INTX            (I2C_TXAS_SRDITX)                       /*!< When the processor side reponds to a slave mode request for data to be transmitted to aremote master and user write 1 to CMD */
#define I2C_ABRT_USER_ABRT             (I2C_TXAS_USERAB)                       /*!< Master has detected the transfer abort                            */
/**
  * @}
  */
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/** @addtogroup I2C_Exported_Functions 
  * @{
  */

/** @addtogroup I2C_Exported_Functions_Group1
  * @{
  */

/* Initialization and Configuration functions *********************************/
void I2C_DeInit(I2C_TypeDef* I2Cx);
void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_MasterAbortSendCmd(I2C_TypeDef* I2Cx);
void I2C_ITConfig(I2C_TypeDef* I2Cx, uint32_t I2C_IT, FunctionalState NewState);
void I2C_ConfigTiming(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct, uint32_t BaudRate);
void I2C_TargetAddressConfig(I2C_TypeDef* I2Cx, uint16_t Address);
void I2C_ModeConfig(I2C_TypeDef* I2Cx, uint32_t Mode);
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group2
  * @{
  */

/* Data transfers management functions ****************************************/
void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data);
uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx);

void I2C_MasterReceiveDataRequest(I2C_TypeDef* I2Cx);
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group3
  * @{
  */
/* DMA transfers management functions *****************************************/
void I2C_DMACmd(I2C_TypeDef* I2Cx, uint32_t I2C_DMAReq, FunctionalState NewState);
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group4
  * @{
  */
/* Interrupts and flags management functions **********************************/
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);
ITStatus I2C_GetITRawStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
void I2C_ClearIT(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
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

#endif /*__XT32H0XX_I2C_H */


