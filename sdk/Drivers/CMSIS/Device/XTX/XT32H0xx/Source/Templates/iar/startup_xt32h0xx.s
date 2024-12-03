;******************************************************************************
;* File Name          : startup_xt32h0xx.s
;* Author             : Software Team
;* Description        : XT32H0xx devices vector table for EWARM toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == __iar_program_start,
;*                      - Set the vector table entries with the exceptions ISR 
;*                        address
;*                      - Branches to main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the Cortex-M0+ processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;********************************************************************************
;*
;* Copyright (c) 2023 XTXTech.
;* All rights reserved.
;*
;
;*******************************************************************************
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        EXTERN  SystemInit
        PUBLIC  __vector_table

        DATA
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler                  ; Reset Handler

        DCD     NMI_Handler                    ; NMI Handler
        DCD     HardFault_Handler              ; Hard Fault Handler
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     SVC_Handler                    ; SVCall Handler
        DCD     0                              ; Reserved
        DCD     0                              ; Reserved
        DCD     PendSV_Handler                 ; PendSV Handler
        DCD     SysTick_Handler                ; SysTick Handler

        ; External Interrupts
        DCD     DMA_IRQHandler                 ; DMA controller
        DCD     WDTW_IRQHandler                ; Windows Watchdog
        DCD     CMP1_IRQHandler                ; COMP 1
        DCD     RTC_IRQHandler                 ; RTC
        DCD     ICTL_IRQHandler                ; Interrupt Controller
        DCD     UART1_IRQHandler               ; UART 1
        DCD     UART2_IRQHandler               ; UART 2
        DCD     UART3_IRQHandler               ; UART 3
        DCD     UART4_IRQHandler               ; UART 4
        DCD     TIM1_BRK_IRQHandler            ; TIM1 Break
        DCD     TIM1_UDT_IRQHandler            ; TIM1 Update
        DCD     TIM1_TRG_IRQHandler            ; TIM1 Trigger & Commutation
        DCD     TIM1_CC_IRQHandler             ; TIM1 CC1/2/3/4 
        DCD     TIM2_BRK_IRQHandler            ; TIM2 Break
        DCD     TIM2_UDT_IRQHandler            ; TIM2 Update
        DCD     TIM2_TRG_IRQHandler            ; TIM2 Trigger & Commutation
        DCD     TIM2_CC_IRQHandler             ; TIM2 CC1/2/3/4 
        DCD     TIMG1_UDT_IRQHandler           ; TIMG1 Update
        DCD     TIMG1_TRG_IRQHandler           ; TIMG1 Trigger & Commutation
        DCD     TIMG1_CC_IRQHandler            ; TIMG1 CC1/2/3/4 
        DCD     TIMG2_UDT_IRQHandler           ; TIMG2 Update
        DCD     TIMG2_TRG_IRQHandler           ; TIMG2 Trigger & Commutation
        DCD     TIMG2_CC_IRQHandler            ; TIMG2 CC1/2/3/4 
        DCD     TIMG3_UDT_IRQHandler           ; TIMG3 Update
        DCD     TIMG3_TRG_IRQHandler           ; TIMG3 Trigger & Commutation
        DCD     TIMG3_CC_IRQHandler            ; TIMG3 CC1/2/3/4 
        DCD     TIMG4_UDT_IRQHandler           ; TIMG4 Update
        DCD     TIMG4_TRG_IRQHandler           ; TIMG4 Trigger & Commutation
        DCD     TIMG4_CC_IRQHandler            ; TIMG4 CC1/2/3/4 
        DCD     CMP2_IRQHandler                ; COMP2
        DCD     CMP3_IRQHandler                ; COMP3
        DCD     CMP4_IRQHandler                ; COMP4

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
        LDR     R0, =SystemInit
        BLX     R0
        LDR     R0, =__iar_program_start
        BX      R0
        
        PUBWEAK NMI_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler
        B NMI_Handler

        PUBWEAK HardFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_Handler
        B HardFault_Handler

        PUBWEAK SVC_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SVC_Handler
        B SVC_Handler

        PUBWEAK PendSV_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler
        B PendSV_Handler

        PUBWEAK SysTick_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler
        B SysTick_Handler

        PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DMA_IRQHandler
        B DMA_IRQHandler

        PUBWEAK WDTW_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
WDTW_IRQHandler
        B WDTW_IRQHandler
        
        PUBWEAK CMP1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CMP1_IRQHandler
        B CMP1_IRQHandler

        PUBWEAK RTC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
RTC_IRQHandler
        B RTC_IRQHandler

        PUBWEAK ICTL_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ICTL_IRQHandler
        B ICTL_IRQHandler

        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART1_IRQHandler
        B UART1_IRQHandler

        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART2_IRQHandler
        B UART2_IRQHandler

        PUBWEAK USB_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
USB_IRQHandler
        B USB_IRQHandler

        PUBWEAK UART3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART3_IRQHandler
        B UART3_IRQHandler

        PUBWEAK UART4_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART4_IRQHandler
        B UART4_IRQHandler

        PUBWEAK TIM1_BRK_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM1_BRK_IRQHandler
        B TIM1_BRK_IRQHandler

        PUBWEAK TIM1_UDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM1_UDT_IRQHandler
        B TIM1_UDT_IRQHandler

        PUBWEAK TIM1_TRG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM1_TRG_IRQHandler
        B TIM1_TRG_IRQHandler

        PUBWEAK TIM1_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM1_CC_IRQHandler
        B TIM1_CC_IRQHandler

        PUBWEAK TIM2_BRK_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM2_BRK_IRQHandler
        B TIM2_BRK_IRQHandler

        PUBWEAK TIM2_UDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM2_UDT_IRQHandler
        B TIM2_UDT_IRQHandler

        PUBWEAK TIM2_TRG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM2_TRG_IRQHandler
        B TIM2_TRG_IRQHandler

        PUBWEAK TIM2_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIM2_CC_IRQHandler
        B TIM2_CC_IRQHandler

        PUBWEAK TIMG1_UDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG1_UDT_IRQHandler
        B TIMG1_UDT_IRQHandler

        PUBWEAK TIMG1_TRG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG1_TRG_IRQHandler
        B TIMG1_TRG_IRQHandler

        PUBWEAK TIMG1_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG1_CC_IRQHandler
        B TIMG1_CC_IRQHandler

        PUBWEAK TIMG2_UDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG2_UDT_IRQHandler
        B TIMG2_UDT_IRQHandler

        PUBWEAK TIMG2_TRG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG2_TRG_IRQHandler
        B TIMG2_TRG_IRQHandler

        PUBWEAK TIMG2_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG2_CC_IRQHandler
        B TIMG2_CC_IRQHandler

        PUBWEAK TIMG3_UDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG3_UDT_IRQHandler
        B TIMG3_UDT_IRQHandler

        PUBWEAK TIMG3_TRG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG3_TRG_IRQHandler
        B TIMG3_TRG_IRQHandler

        PUBWEAK TIMG3_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG3_CC_IRQHandler
        B TIMG3_CC_IRQHandler

        PUBWEAK TIMG4_UDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG4_UDT_IRQHandler
        B TIMG4_UDT_IRQHandler

        PUBWEAK TIMG4_TRG_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG4_TRG_IRQHandler
        B TIMG4_TRG_IRQHandler

        PUBWEAK TIMG4_CC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
TIMG4_CC_IRQHandler
        B TIMG4_CC_IRQHandler

        PUBWEAK CMP2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CMP2_IRQHandler
        B CMP2_IRQHandler

        PUBWEAK CMP3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CMP3_IRQHandler
        B CMP3_IRQHandler

        PUBWEAK CMP4_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CMP4_IRQHandler
        B CMP4_IRQHandler

        END
;************************ (C) COPYRIGHT XTXTech *****END OF FILE*****
