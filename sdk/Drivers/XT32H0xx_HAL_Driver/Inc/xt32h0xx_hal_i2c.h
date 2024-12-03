/**
  ******************************************************************************
  * @file    xt32h0xx_hal_i2c.h
  * @author  Software Team
  * @brief   Header file of I2C HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 XTXTech..
  * All rights reserved.</center></h2>
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef XT32H0xx_HAL_I2C_H
#define XT32H0xx_HAL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "xt32h0xx_hal_def.h"

/** @addtogroup XT32H0xx_HAL_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup I2C_Exported_Types I2C Exported Types
  * @{
  */

/** @defgroup I2C_Configuration_Structure_definition I2C Configuration Structure definition
  * @brief  I2C Configuration Structure definition
  * @{
  */
typedef struct
{
  uint32_t Speed;                 /*!< Specifies the I2C_CON_register value.
                                     This parameter calculated by referring to I2C initialization section
                                     in Reference manual */

  uint32_t SlaveAddress;          /*!< Specifies the first device own address.
                                     This parameter can be a 7-bit or 10-bit address. */

  uint32_t AddressingMode;        /*!< Specifies if 7-bit or 10-bit addressing mode is selected.
                                     This parameter can be a value of @ref I2C_ADDRESSING_MODE */
	
	uint32_t OwnAddress;            /*!< Address for slave */
	
	uint32_t Baudrate;              /*!< I2C timming */

} I2C_InitTypeDef;

/**
  * @}
  */

/** @defgroup HAL_state_structure_definition HAL state structure definition
  * @brief  HAL State structure definition
  * @note  HAL I2C State value coding follow below described bitmap :\n
  *          b7-b6  Error information\n
  *             00 : No Error\n
  *             01 : Abort (Abort user request on going)\n
  *             10 : Timeout\n
  *             11 : Error\n
  *          b5     Peripheral initialization status\n
  *             0  : Reset (peripheral not initialized)\n
  *             1  : Init done (peripheral initialized and ready to use. HAL I2C Init function called)\n
  *          b4     (not used)\n
  *             x  : Should be set to 0\n
  *          b3     (not used)\n
  *             x  : Should be set to 0\n
  *          b2     Intrinsic process state\n
  *             0  : Ready\n
  *             1  : Busy (peripheral busy with some configuration or internal operations)\n
  *          b1     Rx state\n
  *             0  : Ready (no Rx operation ongoing)\n
  *             1  : Busy (Rx operation ongoing)\n
  *          b0     Tx state\n
  *             0  : Ready (no Tx operation ongoing)\n
  *             1  : Busy (Tx operation ongoing)
  * @{
  */
typedef enum
{
  HAL_I2C_STATE_RESET             = 0x00U,   /*!< Peripheral is not yet Initialized         */
  HAL_I2C_STATE_READY             = 0x20U,   /*!< Peripheral Initialized and ready for use  */
  HAL_I2C_STATE_BUSY              = 0x24U,   /*!< An internal process is ongoing            */
  HAL_I2C_STATE_BUSY_TX           = 0x21U,   /*!< Data Transmission process is ongoing      */
  HAL_I2C_STATE_BUSY_RX           = 0x22U,   /*!< Data Reception process is ongoing         */
  HAL_I2C_STATE_ABORT             = 0x60U,   /*!< Abort user request ongoing                */
  HAL_I2C_STATE_TIMEOUT           = 0xA0U,   /*!< Timeout state                             */
  HAL_I2C_STATE_ERROR             = 0xE0U    /*!< Error                                     */

} HAL_I2C_StateTypeDef;

/**
  * @}
  */

/** @defgroup HAL_mode_structure_definition HAL mode structure definition
  * @brief  HAL Mode structure definition
  * @note  HAL I2C Mode value coding follow below described bitmap :\n
  *          b7-b6     (not used)\n
  *             xx : Should be set to 00\n
  *          b5\n
  *             0  : None\n
  *             1  : Slave (HAL I2C communication is in Slave Mode)\n
  *          b4\n
  *             0  : None\n
  *             1  : Master (HAL I2C communication is in Master Mode)\n
  *          b3-b2-b1-b0  (not used)\n
  *             xxxx : Should be set to 0000
  * @{
  */
typedef enum
{
  HAL_I2C_MODE_NONE               = 0x00U,   /*!< No I2C communication on going             */
  HAL_I2C_MODE_MASTER             = 0x10U,   /*!< I2C communication is in Master Mode       */
  HAL_I2C_MODE_SLAVE              = 0x20U    /*!< I2C communication is in Slave Mode        */
} HAL_I2C_ModeTypeDef;

/**
  * @}
  */

/** @defgroup I2C_Error_Code_definition I2C Error Code definition
  * @brief  I2C Error Code definition
  * @{
  */
#define HAL_I2C_ERROR_NONE      (0x00000000U)    /*!< No error              */
#define HAL_I2C_ERROR_TXABRT    (0x00000001U)    /*!< Tx abort error        */
#define HAL_I2C_ERROR_RXO       (0x00000002U)    /*!< Rx over error         */
#define HAL_I2C_ERROR_RXU       (0x00000004U)    /*!< Rx under error        */
#define HAL_I2C_ERROR_TXO       (0x00000008U)    /*!< Tx over error         */
#define HAL_I2C_ERROR_DMA       (0x00000010U)    /*!< DMA transfer error    */
#define HAL_I2C_ERROR_TIMEOUT   (0x00000020U)    /*!< Timeout error         */
#define HAL_I2C_ERROR_SIZE      (0x00000040U)    /*!< Size Management error */
#define HAL_I2C_ERROR_DMA_PARAM (0x00000080U)    /*!< DMA Parameter Error   */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
#define HAL_I2C_ERROR_INVALID_CALLBACK  (0x00000100U)    /*!< Invalid Callback error */
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
#define HAL_I2C_ERROR_INVALID_PARAM     (0x00000200U)    /*!< Invalid Parameters error  */
/**
  * @}
  */

/** @defgroup I2C_handle_Structure_definition I2C handle Structure definition
  * @brief  I2C handle Structure definition
  * @{
  */
typedef struct __I2C_HandleTypeDef
{
  I2C_TypeDef                *Instance;      /*!< I2C registers base address                */

  I2C_InitTypeDef            Init;           /*!< I2C communication parameters              */

  uint8_t                    *pBuffPtr;      /*!< Pointer to I2C transfer buffer            */

  uint16_t                   XferSize;       /*!< I2C transfer size                         */

  __IO uint16_t              XferCount;      /*!< I2C transfer counter                      */

//  __IO uint32_t              XferOptions;    /*!< I2C sequantial transfer options, this parameter can
//                                                  be a value of @ref I2C_XFEROPTIONS */

  __IO uint32_t              PreviousState;  /*!< I2C communication Previous state          */

  HAL_StatusTypeDef(*XferISR)(struct __I2C_HandleTypeDef *hi2c, uint32_t ITFlags, uint32_t ITSources);
  /*!< I2C transfer IRQ handler function pointer */

  DMA_HandleTypeDef          *hdmatx;        /*!< I2C Tx DMA handle parameters              */

  DMA_HandleTypeDef          *hdmarx;        /*!< I2C Rx DMA handle parameters              */

  HAL_LockTypeDef            Lock;           /*!< I2C locking object                        */

  __IO HAL_I2C_StateTypeDef  State;          /*!< I2C communication state                   */

  __IO HAL_I2C_ModeTypeDef   Mode;           /*!< I2C communication mode                    */

  __IO uint32_t              ErrorCode;      /*!< I2C Error code                            */

  __IO uint32_t              AddrEventCount; /*!< I2C Address Event counter                 */

  __IO uint32_t              TxAbortSource;  /*!< I2C Tx abort source                       */


#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
  void (* MasterTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Master Tx Transfer completed callback */
  void (* MasterRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Master Rx Transfer completed callback */
  void (* SlaveTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Slave Tx Transfer completed callback  */
  void (* SlaveRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Slave Rx Transfer completed callback  */
  void (* ErrorCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Error callback                        */
  void (* AbortCpltCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Abort callback                        */
  void (* TxAbortCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Tx Abort callback                        */

	void (* MasterTxTfrClptCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma transfer complete callback */
	void (* MasterTxBlockCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma block transfer complete callback */
	void (* MasterTxDstTranCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma destination transfer request callback */
	void (* MasterTxTfrErrorCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma transfer error callback */
	void (* MasterTxTfrAbortCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma transfer abort callback */	
	void (* MasterRxTfrClptCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma transfer complete callback */
	void (* MasterRxBlockCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma block transfer complete callback */
	void (* MasterRxSrcTranCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma source transfer request callback */
	void (* MasterRxTfrErrorCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma transfer error callback */
	void (* MasterRxTfrAbortCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma transfer abort callback */	
	void (* SlaveTxTfrClptCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma transfer complete callback */
	void (* SlaveTxBlockCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma block transfer complete callback */
	void (* SlaveTxDstTranCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma destination transfer request callback */
	void (* SlaveTxTfrErrorCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma error complete callback */
	void (* SlaveTxTfrAbortCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma transfer abort callback */	
	void (* SlaveRxTfrClptCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma transfer complete callback */
	void (* SlaveRxBlockCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma block transfer complete callback */
	void (* SlaveRxSrcTranCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma source transfer request callback */
	void (* SlaveRxTfrErrorCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C slave dma transfer complete callback */
	void (* SlaveRxTfrAbortCallback)(struct __I2C_HandleTypeDef *hi2c);
	/*!< I2C master dma transfer abort callback */	


  void (* SlaveGeneralCallCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Slave general call callback */

  void (* MspInitCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Msp Init callback                     */
  void (* MspDeInitCallback)(struct __I2C_HandleTypeDef *hi2c);
  /*!< I2C Msp DeInit callback                   */

#endif  /* USE_HAL_I2C_REGISTER_CALLBACKS */
} I2C_HandleTypeDef;

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL I2C Callback ID enumeration definition
  */
typedef enum
{
  HAL_I2C_MASTER_TX_COMPLETE_CB_ID      = 0x00U,    /*!< I2C Master Tx Transfer completed callback ID  */
  HAL_I2C_MASTER_RX_COMPLETE_CB_ID      = 0x01U,    /*!< I2C Master Rx Transfer completed callback ID  */
  HAL_I2C_SLAVE_TX_COMPLETE_CB_ID       = 0x02U,    /*!< I2C Slave Tx Transfer completed callback ID   */
  HAL_I2C_SLAVE_RX_COMPLETE_CB_ID       = 0x03U,    /*!< I2C Slave Rx Transfer completed callback ID   */
  HAL_I2C_SLAVE_GEN_CALL_CB_ID          = 0x04U,    /*!< I2C Slave Gen Call callback ID                  */
  HAL_I2C_ERROR_CB_ID                   = 0x06U,    /*!< I2C Error callback ID                         */
  HAL_I2C_ABORT_CB_ID                   = 0x07U,    /*!< I2C Abort callback ID                         */
  HAL_I2C_TXABORT_CB_ID                 = 0x08U,    /*!< I2C Tx Abort callback ID                         */

  HAL_I2C_MSPINIT_CB_ID                 = 0x09U,    /*!< I2C Msp Init callback ID                      */
  HAL_I2C_MSPDEINIT_CB_ID               = 0x0AU,    /*!< I2C Msp DeInit callback ID                    */

  HAL_I2C_MASTER_TX_TFRCLPT_CB_ID       = 0x10U,    /*!< I2C Master Tx DMA Transfer completed callback ID  */
  HAL_I2C_MASTER_TX_BLOCK_CB_ID         = 0x11U,    /*!< I2C Master Tx DMA block Transfer completed callback ID  */
  HAL_I2C_MASTER_TX_DSTTRAN_CB_ID       = 0x12U,    /*!< I2C Master Tx DMA destination Transfer request callback ID  */
  HAL_I2C_MASTER_TX_TFRERR_CB_ID        = 0x13U,    /*!< I2C Master Tx DMA Transfer error callback ID  */
  HAL_I2C_MASTER_TX_TFRABRT_CB_ID       = 0x14U,    /*!< I2C Master Tx DMA Transfer abort callback ID  */
  HAL_I2C_MASTER_RX_TFRCLPT_CB_ID       = 0x15U,    /*!< I2C Master Rx DMA Transfer completed callback ID  */
  HAL_I2C_MASTER_RX_BLOCK_CB_ID         = 0x16U,    /*!< I2C Master Rx DMA block Transfer completed callback ID  */
  HAL_I2C_MASTER_RX_SRCTRAN_CB_ID       = 0x17U,    /*!< I2C Master Rx DMA source Transfer request callback ID  */
  HAL_I2C_MASTER_RX_TFRERR_CB_ID        = 0x18U,    /*!< I2C Master Rx DMA Transfer error callback ID  */
  HAL_I2C_MASTER_RX_TFRABRT_CB_ID       = 0x19U,    /*!< I2C Master Rx DMA Transfer abort callback ID  */
  HAL_I2C_SLAVE_TX_TFRCLPT_CB_ID        = 0x20U,    /*!< I2C Slave Tx DMA Transfer completed callback ID  */
  HAL_I2C_SLAVE_TX_BLOCK_CB_ID          = 0x21U,    /*!< I2C Slave Tx DMA block Transfer completed callback ID  */
  HAL_I2C_SLAVE_TX_DSTTRAN_CB_ID        = 0x22U,    /*!< I2C Slave Tx DMA destination Transfer request callback ID  */
  HAL_I2C_SLAVE_TX_TFRERR_CB_ID         = 0x23U,    /*!< I2C Slave Tx DMA Transfer error callback ID  */
  HAL_I2C_SLAVE_TX_TFRABRT_CB_ID        = 0x24U,    /*!< I2C Slave Tx DMA Transfer abort callback ID  */
  HAL_I2C_SLAVE_RX_TFRCLPT_CB_ID        = 0x25U,    /*!< I2C Slave Rx DMA Transfer completed callback ID  */
  HAL_I2C_SLAVE_RX_BLOCK_CB_ID          = 0x26U,    /*!< I2C Slave Rx DMA block Transfer completed callback ID  */
  HAL_I2C_SLAVE_RX_SRCTRAN_CB_ID        = 0x27U,    /*!< I2C Slave Rx DMA source Transfer request callback ID  */
  HAL_I2C_SLAVE_RX_TFRERR_CB_ID         = 0x28U,    /*!< I2C Slave Rx DMA Transfer error callback ID  */
  HAL_I2C_SLAVE_RX_TFRABRT_CB_ID        = 0x29U,    /*!< I2C Slave Rx DMA Transfer abort callback ID  */

} HAL_I2C_CallbackIDTypeDef;

/**
  * @brief  HAL I2C Callback pointer definition
  */
typedef  void (*pI2C_CallbackTypeDef)(I2C_HandleTypeDef *hi2c);

#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/

/** @defgroup I2C_Exported_Constants I2C Exported Constants
  * @{
  */

/** @defgroup I2C_ADDRESSING_MODE I2C Addressing Mode
  * @{
  */
#define I2C_ADDRESSINGMODE_7BIT        (0x00000000U)
#define I2C_ADDRESSINGMODE_10BIT       (0x00000001U)
/**
  * @}
  */

/** @defgroup I2C_XFERDIRECTION I2C Transfer Direction Master Point of View
  * @{
  */
#define I2C_DIRECTION_TRANSMIT         (0x00000000U)
#define I2C_DIRECTION_RECEIVE          (0x00000001U)
/**
  * @}
  */

/** @defgroup I2C_MODE I2C Mode
  * @{
  */
#define I2C_MODE_SLAVE                 (0x00000000U)                           /*!< I2C Slave mode                               */
#define I2C_MODE_MASTER                (I2C_CON_MMOD | I2C_CON_SLVDIS)         /*!< I2C Master mode                              */
/**
  * @}
  */

/** @defgroup I2C_SPEED I2C Speed
  * @{
  */
#define I2C_SPEED_STANDARD             (I2C_CON_SPEED_0)                       /*!< I2C speed standard                           */
#define I2C_SPEED_FAST                 (I2C_CON_SPEED_1)                       /*!< I2C speed fast                               */
#define I2C_SPEED_HIGH                 (I2C_CON_SPEED_1|I2C_CON_SPEED_0)       /*!< I2C speed high                               */
/**
  * @}
  */

/** @defgroup I2C_CMD I2C command
  * @{
  */
#define I2C_CMD_WRITE                   (0x00000000U)                          /*!< I2C write */
#define I2C_CMD_READ                    (I2C_DATACMD_CMD)                      /*!< I2C read */
/**
  * @}
  */

/** @defgroup I2C_BUFFER_DEPTH I2C TX/RX Buffer depth
  * @{
  */
#define I2C_TX_BUFFER_DEPTH            (8)  
#define I2C_RX_BUFFER_DEPTH            (8)  
/**
  * @}
  */

/** @defgroup I2C_Interrupt_configuration_definition I2C Interrupt configuration definition
  * @brief I2C Interrupt definition
  *        Elements values convention: 0xXXXXXXXX
  *           - XXXXXXXX  : Interrupt control mask
  * @{
  */
#define I2C_IT_RX_UNDER                (I2C_INTRSTAT_RXU   )                   /*!< RX_UNDER                                    */
#define I2C_IT_RX_OVER                 (I2C_INTRSTAT_RXO   )                   /*!< RX_OVER                                     */
#define I2C_IT_RX_FULL                 (I2C_INTRSTAT_RXF   )                   /*!< RX_FULL                                     */
#define I2C_IT_TX_OVER                 (I2C_INTRSTAT_TXO   )                   /*!< TX_OVER                                     */
#define I2C_IT_TX_EMPTY                (I2C_INTRSTAT_TXE   )                   /*!< TX_EMPTY                                    */
#define I2C_IT_RD_REQ                  (I2C_INTRSTAT_RDR   )                   /*!< RD_REQ                                      */
#define I2C_IT_TX_ABRT                 (I2C_INTRSTAT_TXA   )                   /*!< TX_ABRT                                     */
#define I2C_IT_RX_DONE                 (I2C_INTRSTAT_RXD   )                   /*!< RX_DONE                                     */
#define I2C_IT_ACTIVITY                (I2C_INTRSTAT_ACT   )                   /*!< ACTIVITY                                    */
#define I2C_IT_STOP_DET                (I2C_INTRSTAT_STOPD )                   /*!< STOP_DET                                    */
#define I2C_IT_START_DET               (I2C_INTRSTAT_STARTD)                   /*!< START_DET                                   */
#define I2C_IT_GEN_CALL                (I2C_INTRSTAT_GCALL )                   /*!< GEN_CALL                                    */
#define I2C_IT_ALL                     ( I2C_INTRSTAT_RXU     \
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
                                       | I2C_INTRSTAT_GCALL)
/**
  * @}
  */

/** @defgroup I2C_Flag_definition I2C Flag definition
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
/**
  * @}
  */

/** @defgroup I2C_Status_definition I2C Status Definition
  * @{
  */
#define I2C_STAT_ACTIVITY              (I2C_STATUS_ACT )                       /*!< I2C activity status               */
#define I2C_STAT_TFNF                  (I2C_STATUS_TFNF)                       /*!< Transmit FIFO not full            */
#define I2C_STAT_TFE                   (I2C_STATUS_TFE )                       /*!< Transmit FIFO completely empty    */
#define I2C_STAT_RFNE                  (I2C_STATUS_RFNE)                       /*!< Receive FIFO not empty            */
#define I2C_STAT_RFF                   (I2C_STATUS_RFF )                       /*!< Receive FIFO completely full      */
#define I2C_STAT_MST_ACTIVITY          (I2C_STATUS_MSTA)                       /*!< Master FSM activity status        */
#define I2C_STAT_SLV_ACTIVITY          (I2C_STATUS_SLVA)                       /*!< Slave FSM activity status         */
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

/* Exported macros -----------------------------------------------------------*/

/** @defgroup I2C_Exported_Macros I2C Exported Macros
  * @{
  */

/** @brief Reset I2C handle state.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
#define __HAL_I2C_RESET_HANDLE_STATE(__HANDLE__)                do{                                             \
                                                                    (__HANDLE__)->State = HAL_I2C_STATE_RESET;  \
                                                                    (__HANDLE__)->MspInitCallback = NULL;       \
                                                                    (__HANDLE__)->MspDeInitCallback = NULL;     \
                                                                  } while(0)
#else
#define __HAL_I2C_RESET_HANDLE_STATE(__HANDLE__)                ((__HANDLE__)->State = HAL_I2C_STATE_RESET)
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */

/** @brief  Enable the specified I2C interrupt.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __INTERRUPT__ specifies the interrupt source to enable.
  *        This parameter can be one of the following values:
  *        @arg @ref I2C_IT_RX_UNDER  
  *        @arg @ref I2C_IT_RX_OVER   
  *        @arg @ref I2C_IT_RX_FULL   
  *        @arg @ref I2C_IT_TX_OVER   
  *        @arg @ref I2C_IT_TX_EMPTY  
  *        @arg @ref I2C_IT_RD_REQ    
  *        @arg @ref I2C_IT_TX_ABRT   
  *        @arg @ref I2C_IT_RX_DONE   
  *        @arg @ref I2C_IT_ACTIVITY  
  *        @arg @ref I2C_IT_STOP_DET  
  *        @arg @ref I2C_IT_START_DET 
  *        @arg @ref I2C_IT_GEN_CALL  
  * @retval None
  */
#define __HAL_I2C_UNMASK_IT(__HANDLE__, __INTERRUPT__)          ((__HANDLE__)->Instance->INTRMASK |= (__INTERRUPT__))

/** @brief  Disable the specified I2C interrupt.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __INTERRUPT__ specifies the interrupt source to disable.
  *        This parameter can be one of the following values:
  *        @arg @ref I2C_IT_RX_UNDER  
  *        @arg @ref I2C_IT_RX_OVER   
  *        @arg @ref I2C_IT_RX_FULL   
  *        @arg @ref I2C_IT_TX_OVER   
  *        @arg @ref I2C_IT_TX_EMPTY  
  *        @arg @ref I2C_IT_RD_REQ    
  *        @arg @ref I2C_IT_TX_ABRT   
  *        @arg @ref I2C_IT_RX_DONE   
  *        @arg @ref I2C_IT_ACTIVITY  
  *        @arg @ref I2C_IT_STOP_DET  
  *        @arg @ref I2C_IT_START_DET 
  *        @arg @ref I2C_IT_GEN_CALL  
  * @retval None
  */
#define __HAL_I2C_MASK_IT(__HANDLE__, __INTERRUPT__)         ((__HANDLE__)->Instance->INTRMASK &= (~(__INTERRUPT__)))

/** @brief  Check whether the specified I2C interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __INTERRUPT__ specifies the I2C interrupt source to check.
  *          This parameter can be one of the following values:
  *        @arg @ref I2C_IT_RX_UNDER  
  *        @arg @ref I2C_IT_RX_OVER   
  *        @arg @ref I2C_IT_RX_FULL   
  *        @arg @ref I2C_IT_TX_OVER   
  *        @arg @ref I2C_IT_TX_EMPTY  
  *        @arg @ref I2C_IT_RD_REQ    
  *        @arg @ref I2C_IT_TX_ABRT   
  *        @arg @ref I2C_IT_RX_DONE   
  *        @arg @ref I2C_IT_ACTIVITY  
  *        @arg @ref I2C_IT_STOP_DET  
  *        @arg @ref I2C_IT_START_DET 
  *        @arg @ref I2C_IT_GEN_CALL  
  * @retval The new state of __INTERRUPT__ (SET or RESET).
  */
#define __HAL_I2C_GET_IT(__HANDLE__, __INTERRUPT__)      ((((__HANDLE__)->Instance->INTRSTAT & \
                                                                   (__INTERRUPT__)) == (__INTERRUPT__)) ? RESET : SET)

/** @brief  Clear the I2C pending flags which are cleared by writing 1 in a specific bit.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __IT__ specifies the flag to clear.
  *          This parameter can be any combination of the following values:
  *        @arg @ref I2C_IT_RX_UNDER  
  *        @arg @ref I2C_IT_RX_OVER   
  *        @arg @ref I2C_IT_RX_FULL   
  *        @arg @ref I2C_IT_TX_OVER   
  *        @arg @ref I2C_IT_TX_EMPTY  
  *        @arg @ref I2C_IT_RD_REQ    
  *        @arg @ref I2C_IT_TX_ABRT   
  *        @arg @ref I2C_IT_RX_DONE   
  *        @arg @ref I2C_IT_ACTIVITY  
  *        @arg @ref I2C_IT_STOP_DET  
  *        @arg @ref I2C_IT_START_DET 
  *        @arg @ref I2C_IT_GEN_CALL  
  * @retval None
  */
#define __HAL_I2C_CLEAR_IT(__HANDLE__, __IT__)     (((__IT__) == I2C_IT_RX_UNDER) ? READ_REG((__HANDLE__)->Instance->CLRRXUNDER) : \
                                                    ((__IT__) == I2C_IT_RX_OVER) ? READ_REG((__HANDLE__)->Instance->CLRRXOVER) : \
                                                    ((__IT__) == I2C_IT_TX_OVER) ? READ_REG((__HANDLE__)->Instance->CLRTXOVER) : \
                                                    ((__IT__) == I2C_IT_RD_REQ) ? READ_REG((__HANDLE__)->Instance->CLRRDREQ) : \
                                                    ((__IT__) == I2C_IT_TX_ABRT) ? READ_REG((__HANDLE__)->Instance->CLRTXABRT) : \
                                                    ((__IT__) == I2C_IT_RX_DONE) ? READ_REG((__HANDLE__)->Instance->CLRRXDONE) : \
                                                    ((__IT__) == I2C_IT_ACTIVITY) ? READ_REG((__HANDLE__)->Instance->CLRACTIVITY) : \
                                                    ((__IT__) == I2C_IT_STOP_DET) ? READ_REG((__HANDLE__)->Instance->CLRSTOPDET) : \
                                                    ((__IT__) == I2C_IT_START_DET) ? READ_REG((__HANDLE__)->Instance->CLRSTARTDET) : \
                                                    ((__IT__) == I2C_IT_GEN_CALL) ? READ_REG((__HANDLE__)->Instance->CLRGENCALL) : \
                                                    READ_REG((__HANDLE__)->Instance->CLRINTR))

/** @brief  Check whether the specified I2C flag is set or not.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *        @arg @ref I2C_FLAG_RX_UNDER 
  *        @arg @ref I2C_FLAG_RX_OVER  
  *        @arg @ref I2C_FLAG_RX_FULL  
  *        @arg @ref I2C_FLAG_TX_OVER  
  *        @arg @ref I2C_FLAG_TX_EMPTY 
  *        @arg @ref I2C_FLAG_RD_REQ   
  *        @arg @ref I2C_FLAG_TX_ABRT  
  *        @arg @ref I2C_FLAG_RX_DONE  
  *        @arg @ref I2C_FLAG_ACTIVITY 
  *        @arg @ref I2C_FLAG_STOP_DET 
  *        @arg @ref I2C_FLAG_START_DET
  *        @arg @ref I2C_FLAG_GEN_CALL 
  * @retval The new state of __FLAG__ (SET or RESET).
  */
#define I2C_FLAG_MASK  (0x00003FFFU)
#define __HAL_I2C_GET_FLAG(__HANDLE__, __FLAG__) (((((__HANDLE__)->Instance->RAWINTRSTAT) & \
                                                    (__FLAG__)) == (__FLAG__)) ? SET : RESET)

/** @brief  Clear the I2C pending flags which are cleared by writing 1 in a specific bit.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __FLAG__ specifies the flag to clear.
  *          This parameter can be any combination of the following values:
  *        @arg @ref I2C_FLAG_RX_UNDER 
  *        @arg @ref I2C_FLAG_RX_OVER  
  *        @arg @ref I2C_FLAG_RX_FULL  
  *        @arg @ref I2C_FLAG_TX_OVER  
  *        @arg @ref I2C_FLAG_TX_EMPTY 
  *        @arg @ref I2C_FLAG_RD_REQ   
  *        @arg @ref I2C_FLAG_TX_ABRT  
  *        @arg @ref I2C_FLAG_RX_DONE  
  *        @arg @ref I2C_FLAG_ACTIVITY 
  *        @arg @ref I2C_FLAG_STOP_DET 
  *        @arg @ref I2C_FLAG_START_DET
  *        @arg @ref I2C_FLAG_GEN_CALL 
  * @retval None
  */
#define __HAL_I2C_CLEAR_FLAG(__HANDLE__, __FLAG__) (((__FLAG__) == I2C_FLAG_RX_UNDER) ? READ_REG((__HANDLE__)->Instance->CLRRXUNDER) : \
                                                    ((__FLAG__) == I2C_FLAG_RX_OVER) ? READ_REG((__HANDLE__)->Instance->CLRRXOVER) : \
                                                    ((__FLAG__) == I2C_FLAG_TX_OVER) ? READ_REG((__HANDLE__)->Instance->CLRTXOVER) : \
                                                    ((__FLAG__) == I2C_FLAG_RD_REQ) ? READ_REG((__HANDLE__)->Instance->CLRRDREQ) : \
                                                    ((__FLAG__) == I2C_FLAG_TX_ABRT) ? READ_REG((__HANDLE__)->Instance->CLRTXABRT) : \
                                                    ((__FLAG__) == I2C_FLAG_RX_DONE) ? READ_REG((__HANDLE__)->Instance->CLRRXDONE) : \
                                                    ((__FLAG__) == I2C_FLAG_ACTIVITY) ? READ_REG((__HANDLE__)->Instance->CLRACTIVITY) : \
                                                    ((__FLAG__) == I2C_FLAG_STOP_DET) ? READ_REG((__HANDLE__)->Instance->CLRSTOPDET) : \
                                                    ((__FLAG__) == I2C_FLAG_START_DET) ? READ_REG((__HANDLE__)->Instance->CLRSTARTDET) : \
                                                    ((__FLAG__) == I2C_FLAG_GEN_CALL) ? READ_REG((__HANDLE__)->Instance->CLRGENCALL) : \
                                                    READ_REG((__HANDLE__)->Instance->CLRINTR))

/** @brief  Clear the I2C all interrupt and TX_ABORT_SOURCE.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
#define __HAL_I2C_CLEAR_ALL(__HANDLE__)            (READ_REG((__HANDLE__)->Instance->CLRINTR))

/** @brief  Check whether the specified I2C flag is set or not.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __STAT__ specifies the status to check.
  *        This parameter can be one of the following values:
  *        @arg @ref I2C_STAT_ACTIVITY    
  *        @arg @ref I2C_STAT_TFNF        
  *        @arg @ref I2C_STAT_TFE         
  *        @arg @ref I2C_STAT_RFNE        
  *        @arg @ref I2C_STAT_RFF         
  *        @arg @ref I2C_STAT_MST_ACTIVITY
  *        @arg @ref I2C_STAT_SLV_ACTIVITY
  * @retval The new state of __STAT__ (SET or RESET).
  */
#define __HAL_I2C_GET_STATUS(__HANDLE__, __STAT__) (((((__HANDLE__)->Instance->STATUS) & \
                                                    (__STAT__)) == (__STAT__)) ? SET : RESET)
#define __HAL_I2C_CHECK_STATUS(__HANDLE__, __STAT__) (((((__HANDLE__)->Instance->STATUS) & \
                                                    (__STAT__)) == (__STAT__)) ? SET : RESET)

/** @brief  Check whether the specified I2C tx abort source is set or not.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __SOURCE__ specifies the status to check.
  *        This parameter can be one of the following values:
  *        @arg @ref I2C_ABRT_7B_ADDR_NOACK       Not receive an acknowledgement in 7-bit addressing mode        
  *        @arg @ref I2C_ABRT_10ADDR1_NOACK       Not receive an acknowledgement for 10-bit address first byte 
  *        @arg @ref I2C_ABRT_10ADDR2_NOACK       Not receive an acknowledgement for 10-bit address second byte     
  *        @arg @ref I2C_ABRT_TXDATA_NOACK        Not receive an acknowledgement for data 
  *        @arg @ref I2C_ABRT_GCALL_NOACK         Master sent a General Call and no slave on the bus acknowledged the General Call 
  *        @arg @ref I2C_ABRT_GCALL_READ          Master sent a Generak Cakk but the user programmed the byte following the General Call to be a read from the bus 
  *        @arg @ref I2C_ABRT_HS_ACKDET           Master in High Speed mode and High Speed Master code was acknownledged 
  *        @arg @ref I2C_ABRT_SBYTE_ACKDET        Master has sent a START Byte and the START Byte was acknowledged 
  *        @arg @ref I2C_ABRT_HS_NORSTRT          The restart is disabled and the user is trying to use the master to transfer data in High Speed mode 
  *        @arg @ref I2C_ABRT_SBYTE_NORSTRT       To clear Bit 9 
  *        @arg @ref I2C_ABRT_10B_RD_NORSTRT      The restart is disabled and the master sends a read command in 10-bit addressing mode 
  *        @arg @ref I2C_ABRT_MASTER_DIS          User initiate a master operation with the master mode disabled 
  *        @arg @ref I2C_ABRT_LOST                Master has lost arbitration 
  *        @arg @ref I2C_ABRT_SLVFLUSH_TXFIFO     Slave has received a read command and some data exists in the TX FIFO 
  *        @arg @ref I2C_ABRT_SLV_ARBLOST         Slave lost bus while transmitting data to a remote master        
  *        @arg @ref I2C_ABRT_SLVRD_INTX          When the processor side reponds to a slave mode request for data to be transmitted to aremote master and user write 1 to CMD 
  *        @arg @ref I2C_ABRT_USER_ABRT           Master has detected the transfer abort                            
  * @retval The new state of __STAT__ (SET or RESET).
  */
#define __HAL_I2C_GET_TXABRT_SOURCE(__HANDLE__, __SOURCE__) (((((__HANDLE__)->Instance->TXABRTSOURCE) & \
                                                    (__SOURCE__)) == (__SOURCE__)) ? SET : RESET)

/** @brief  Enable the specified I2C peripheral.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
#define __HAL_I2C_ENABLE(__HANDLE__)                         (SET_BIT((__HANDLE__)->Instance->ENABLE, I2C_ENABLE_EN))

/** @brief  Disable the specified I2C peripheral.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
#define __HAL_I2C_DISABLE(__HANDLE__)                        (CLEAR_BIT((__HANDLE__)->Instance->ENABLE, I2C_ENABLE_EN))

/** @brief  Generate a Non-Acknowledge I2C peripheral in Slave mode.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
#define __HAL_I2C_GENERATE_NACK(__HANDLE__)                  (CLEAR_BIT((__HANDLE__)->Instance->ACKGENERALCALL, I2C_GCACK_ACK))

/** @brief  Set as a master.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
#define __HAL_I2C_MASTER(__HANDLE__)                         (MODIFY_REG((__HANDLE__)->Instance->CON, I2C_CON_MMOD|I2C_CON_SLVDIS, I2C_CON_MMOD|I2C_CON_SLVDIS))

/** @brief  Set as a slave.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
#define __HAL_I2C_SLAVE(__HANDLE__)                          (MODIFY_REG((__HANDLE__)->Instance->CON, I2C_CON_MMOD|I2C_CON_SLVDIS, 0))
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup I2C_Exported_Functions
  * @{
  */

/** @addtogroup I2C_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions******************************/
HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c);

HAL_StatusTypeDef HAL_I2C_DMAHSIFConfig(I2C_HandleTypeDef *hi2c, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx, 
                                         uint32_t rxif, uint32_t txif, uint32_t rxifcfg, uint32_t txifcfg);

HAL_StatusTypeDef HAL_I2C_LinkDMA(I2C_HandleTypeDef *hi2c, DMA_HandleTypeDef *hdmarx, DMA_HandleTypeDef *hdmatx);

/* Callbacks Register/UnRegister functions  ***********************************/
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_I2C_RegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID,
                                           pI2C_CallbackTypeDef pCallback);
HAL_StatusTypeDef HAL_I2C_UnRegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID);

#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group2
  * @{
  */
/* IO operation functions  ****************************************************/
/******* Blocking mode: Polling */
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                             uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                            uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                            uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size,
                                           uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials,
                                        uint32_t Timeout);

/******* Non-Blocking mode: Interrupt */
HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                             uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                            uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);

HAL_StatusTypeDef HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint32_t Timeout);

/******* Non-Blocking mode: DMA */
HAL_StatusTypeDef HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                              uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData,
                                             uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);

void HAL_I2C_IRQHandler(I2C_HandleTypeDef *hi2c);
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group3
  * @{
  */
/******* I2C IRQHandler and Callbacks used in non blocking modes (Interrupt and DMA) */
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_SlaveGeneralCallCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c);
void HAL_I2C_TxAbortCallback(I2C_HandleTypeDef *hi2c);
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group4 
  * @{
  */
/* Peripheral State, Mode and Error functions  *********************************/
HAL_I2C_StateTypeDef HAL_I2C_GetState(I2C_HandleTypeDef *hi2c);
HAL_I2C_ModeTypeDef  HAL_I2C_GetMode(I2C_HandleTypeDef *hi2c);
uint32_t             HAL_I2C_GetError(I2C_HandleTypeDef *hi2c);

/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group5
  * @{
  */
/* Timing Configuration functions  *********************************/
void I2C_Config_Clock(I2C_HandleTypeDef *hi2c, uint32_t BaudRate);
/**
  * @}
  */

/**
  * @}
  */

/* Private Functions ---------------------------------------------------------*/
/** @defgroup I2C_Private_Functions I2C Private Functions
  * @{
  */
/* Private functions are defined in xt32h0xx_hal_i2c.c file */
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


#endif /* XT32H0xx_HAL_I2C_H */

/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/
