;******************************************************************************
;* File Name          : startup_xt32h0xxb.s
;* Author             : Software Team
;* Description        : XT32H05x devices vector table for MDK-ARM toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Set the vector table entries with the exceptions ISR address
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM0 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;* <<< Use Configuration Wizard in Context Menu >>>
;******************************************************************************
;* @attention
;*
;* Copyright (c) 2023 XTXTech.
;* All rights reserved.
;*
;******************************************************************************
; Amount of memory (in bytes) allocated for Stack
; Tailor this value to your application needs
; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000200

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp                   ; Top of Stack
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

__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler routine
Reset_Handler    PROC
                 EXPORT  Reset_Handler                 [WEAK]
        IMPORT  __main
        IMPORT  SystemInit  
                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                    [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler              [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                    [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler                 [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler                [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  DMA_IRQHandler                 [WEAK]
                EXPORT  WDTW_IRQHandler                [WEAK]
                EXPORT  CMP1_IRQHandler                [WEAK]
                EXPORT  RTC_IRQHandler                 [WEAK]
                EXPORT  ICTL_IRQHandler                [WEAK]
                EXPORT  UART1_IRQHandler               [WEAK]
                EXPORT  UART2_IRQHandler               [WEAK]
                EXPORT  UART3_IRQHandler               [WEAK]
                EXPORT  UART4_IRQHandler               [WEAK]
                EXPORT  TIM1_BRK_IRQHandler            [WEAK]
                EXPORT  TIM1_UDT_IRQHandler            [WEAK]
                EXPORT  TIM1_TRG_IRQHandler            [WEAK]
                EXPORT  TIM1_CC_IRQHandler             [WEAK]
                EXPORT  TIM2_BRK_IRQHandler            [WEAK]
                EXPORT  TIM2_UDT_IRQHandler            [WEAK]
                EXPORT  TIM2_TRG_IRQHandler            [WEAK]
                EXPORT  TIM2_CC_IRQHandler             [WEAK]
                EXPORT  TIMG1_UDT_IRQHandler           [WEAK]
                EXPORT  TIMG1_TRG_IRQHandler           [WEAK]
                EXPORT  TIMG1_CC_IRQHandler            [WEAK]
                EXPORT  TIMG2_UDT_IRQHandler           [WEAK]
                EXPORT  TIMG2_TRG_IRQHandler           [WEAK]
                EXPORT  TIMG2_CC_IRQHandler            [WEAK]
                EXPORT  TIMG3_UDT_IRQHandler           [WEAK]
                EXPORT  TIMG3_TRG_IRQHandler           [WEAK]
                EXPORT  TIMG3_CC_IRQHandler            [WEAK]
                EXPORT  TIMG4_UDT_IRQHandler           [WEAK]
                EXPORT  TIMG4_TRG_IRQHandler           [WEAK]
                EXPORT  TIMG4_CC_IRQHandler            [WEAK]
                EXPORT  CMP2_IRQHandler                [WEAK]
                EXPORT  CMP3_IRQHandler                [WEAK]
                EXPORT  CMP4_IRQHandler                [WEAK]


DMA_IRQHandler
WDTW_IRQHandler
CMP1_IRQHandler
RTC_IRQHandler
ICTL_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
UART3_IRQHandler
UART4_IRQHandler
TIM1_BRK_IRQHandler
TIM1_UDT_IRQHandler
TIM1_TRG_IRQHandler
TIM1_CC_IRQHandler
TIM2_BRK_IRQHandler
TIM2_UDT_IRQHandler
TIM2_TRG_IRQHandler
TIM2_CC_IRQHandler
TIMG1_UDT_IRQHandler
TIMG1_TRG_IRQHandler
TIMG1_CC_IRQHandler
TIMG2_UDT_IRQHandler
TIMG2_TRG_IRQHandler
TIMG2_CC_IRQHandler
TIMG3_UDT_IRQHandler
TIMG3_TRG_IRQHandler
TIMG3_CC_IRQHandler
TIMG4_UDT_IRQHandler
TIMG4_TRG_IRQHandler
TIMG4_CC_IRQHandler
CMP2_IRQHandler
CMP3_IRQHandler
CMP4_IRQHandler

                B       .

                ENDP

                ALIGN

;*******************************************************************************
; User Stack and Heap initialization
;*******************************************************************************
                 IF      :DEF:__MICROLIB

                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit

                 ELSE

                 IMPORT  __use_two_region_memory
                 EXPORT  __user_initial_stackheap

__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

;************************ (C) COPYRIGHT XTXTech *****END OF FILE*****
