/**
  ******************************************************************************
  * @file      startup_xt32h0xxb.S
  * @author    Software Team
  * @brief     XT32H05x devices vector table GCC toolchain.
  *            This module performs:
  *                - Set the initial SP
  *                - Set the initial PC == Reset_Handler,
  *                - Set the vector table entries with the exceptions ISR address
  *                - Branches to main in the C library (which eventually
  *                  calls main()).
  *            After Reset the Cortex-M0+ processor is in Thread mode,
  *            priority is Privileged, and the Stack is set to Main.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 XTXTech.
  * All rights reserved.
  *
  ******************************************************************************
  */

.syntax unified
.cpu cortex-m0plus
.fpu softvfp
.thumb

.global g_pfnVectors
.global Default_Handler

/* start address for the initialization values of the .data section.
defined in linker script */
.word _sidata
/* start address for the .data section. defined in linker script */
.word _sdata
/* end address for the .data section. defined in linker script */
.word _edata
/* start address for the .bss section. defined in linker script */
.word _sbss
/* end address for the .bss section. defined in linker script */
.word _ebss

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval None
*/

  .section .text.Reset_Handler
  .weak Reset_Handler
  .type Reset_Handler, %function
Reset_Handler:
  ldr   r0, =_estack
  mov   sp, r0          /* set stack pointer */

/* Call the clock system initialization function.*/
  bl  SystemInit

/* Copy the data segment initializers from flash to SRAM */
  ldr r0, =_sdata
  ldr r1, =_edata
  ldr r2, =_sidata
  movs r3, #0
  b LoopCopyDataInit

CopyDataInit:
  ldr r4, [r2, r3]
  str r4, [r0, r3]
  adds r3, r3, #4

LoopCopyDataInit:
  adds r4, r0, r3
  cmp r4, r1
  bcc CopyDataInit

/* Zero fill the bss segment. */
  ldr r2, =_sbss
  ldr r4, =_ebss
  movs r3, #0
  b LoopFillZerobss

FillZerobss:
  str  r3, [r2]
  adds r2, r2, #4

LoopFillZerobss:
  cmp r2, r4
  bcc FillZerobss

/* Call static constructors */
  bl __libc_init_array
/* Call the application s entry point.*/
  bl main

LoopForever:
  b LoopForever

.size Reset_Handler, .-Reset_Handler

/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval None
*/
  .section .text.Default_Handler,"ax",%progbits
Default_Handler:
Infinite_Loop:
  b Infinite_Loop
  .size Default_Handler, .-Default_Handler

/******************************************************************************
*
* The minimal vector table for a Cortex M0.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
  .section .isr_vector,"a",%progbits
  .type g_pfnVectors, %object
  .size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
  .word _estack
  .word Reset_Handler
  .word NMI_Handler
  .word HardFault_Handler
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word 0
  .word SVC_Handler
  .word 0
  .word 0
  .word PendSV_Handler
  .word SysTick_Handler
  .word DMA_IRQHandler                    /* DMA Controller               */
  .word WDTW_IRQHandler                   /* Windows Watchdag             */
  .word CMP1_IRQHandler                   /* Comp 1                       */
  .word RTC_IRQHandler                    /* RTC Controller               */
  .word ICTL_IRQHandler                   /* Interrupt Controller         */
  .word UART1_IRQHandler                  /* UART1                        */
  .word UART2_IRQHandler                  /* UART2                        */
  .word UART3_IRQHandler                  /* UART3                        */
  .word UART4_IRQHandler                  /* UART4                        */
  .word TIM1_BRK_IRQHandler               /* Adv Timer 1 BRK              */
  .word TIM1_UDT_IRQHandler               /* Adv Timer 1 UDT              */
  .word TIM1_TRG_IRQHandler               /* Adv Timer 1 TRG_COM          */
  .word TIM1_CC_IRQHandler                /* Adv Timer 1 CC1/CC2/CC3/CC4  */
  .word TIM2_BRK_IRQHandler               /* Adv Timer 2 BRK              */
  .word TIM2_UDT_IRQHandler               /* Adv Timer 2 UDT              */
  .word TIM2_TRG_IRQHandler               /* Adv Timer 2 TRG_COM          */
  .word TIM2_CC_IRQHandler                /* Adv Timer 2 CC1/CC2/CC3/CC4  */
  .word TIMG1_UDT_IRQHandler              /* Gen Timer 1 UDT              */
  .word TIMG1_TRG_IRQHandler              /* Gen Timer 1 TRG_COM          */
  .word TIMG1_CC_IRQHandler               /* Gen Timer 1 CC1/CC2/CC3/CC4  */
  .word TIMG2_UDT_IRQHandler              /* Gen Timer 2 UDT              */
  .word TIMG2_TRG_IRQHandler              /* Gen Timer 2 TRG_COM          */
  .word TIMG2_CC_IRQHandler               /* Gen Timer 2 CC1/CC2/CC3/CC4  */
  .word TIMG3_UDT_IRQHandler              /* Gen Timer 3 UDT              */
  .word TIMG3_TRG_IRQHandler              /* Gen Timer 3 TRG_COM          */
  .word TIMG3_CC_IRQHandler               /* Gen Timer 3 CC1/CC2/CC3/CC4  */
  .word TIMG4_UDT_IRQHandler              /* Gen Timer 4 UDT              */
  .word TIMG4_TRG_IRQHandler              /* Gen Timer 4 TRG_COM          */
  .word TIMG4_CC_IRQHandler               /* Gen Timer 4 CC1/CC2/CC3/CC4  */
  .word CMP2_IRQHandler                   /* Comp 2                       */
  .word CMP3_IRQHandler                   /* Comp 3                       */
  .word CMP4_IRQHandler                   /* Comp 4                       */

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/

  .weak      NMI_Handler
  .thumb_set NMI_Handler,Default_Handler

  .weak      HardFault_Handler
  .thumb_set HardFault_Handler,Default_Handler

  .weak      SVC_Handler
  .thumb_set SVC_Handler,Default_Handler

  .weak      PendSV_Handler
  .thumb_set PendSV_Handler,Default_Handler

  .weak      SysTick_Handler
  .thumb_set SysTick_Handler,Default_Handler

  .weak      DMA_IRQHandler
  .thumb_set DMA_IRQHandler,Default_Handler

  .weak      WDTW_IRQHandler
  .thumb_set WDTW_IRQHandler,Default_Handler

  .weak      CMP1_IRQHandler
  .thumb_set CMP1_IRQHandler,Default_Handler

  .weak      RTC_IRQHandler
  .thumb_set RTC_IRQHandler,Default_Handler

  .weak      ICTL_IRQHandler
  .thumb_set ICTL_IRQHandler,Default_Handler

  .weak      UART1_IRQHandler
  .thumb_set UART1_IRQHandler,Default_Handler

  .weak      UART2_IRQHandler
  .thumb_set UART2_IRQHandler,Default_Handler

  .weak      UART3_IRQHandler
  .thumb_set UART3_IRQHandler,Default_Handler

  .weak      UART4_IRQHandler
  .thumb_set UART4_IRQHandler,Default_Handler

  .weak      TIM1_BRK_IRQHandler
  .thumb_set TIM1_BRK_IRQHandler,Default_Handler

  .weak      TIM1_UDT_IRQHandler
  .thumb_set TIM1_UDT_IRQHandler,Default_Handler

  .weak      TIM1_TRG_IRQHandler
  .thumb_set TIM1_TRG_IRQHandler,Default_Handler
  
  .weak      TIM1_CC_IRQHandler
  .thumb_set TIM1_CC_IRQHandler,Default_Handler

  .weak      TIM2_BRK_IRQHandler
  .thumb_set TIM2_BRK_IRQHandler,Default_Handler

  .weak      TIM2_UDT_IRQHandler
  .thumb_set TIM2_UDT_IRQHandler,Default_Handler

  .weak      TIM2_TRG_IRQHandler
  .thumb_set TIM2_TRG_IRQHandler,Default_Handler

  .weak      TIM2_CC_IRQHandler
  .thumb_set TIM2_CC_IRQHandler,Default_Handler

  .weak      TIMG1_UDT_IRQHandler
  .thumb_set TIMG1_UDT_IRQHandler,Default_Handler

  .weak      TIMG1_TRG_IRQHandler
  .thumb_set TIMG1_TRG_IRQHandler,Default_Handler

  .weak      TIMG1_CC_IRQHandler
  .thumb_set TIMG1_CC_IRQHandler,Default_Handler

  .weak      TIMG2_UDT_IRQHandler
  .thumb_set TIMG2_UDT_IRQHandler,Default_Handler

  .weak      TIMG2_TRG_IRQHandler
  .thumb_set TIMG2_TRG_IRQHandler,Default_Handler

  .weak      TIMG2_CC_IRQHandler
  .thumb_set TIMG2_CC_IRQHandler,Default_Handler

  .weak      TIMG3_UDT_IRQHandler
  .thumb_set TIMG3_UDT_IRQHandler,Default_Handler

  .weak      TIMG3_TRG_IRQHandler
  .thumb_set TIMG3_TRG_IRQHandler,Default_Handler

  .weak      TIMG3_CC_IRQHandler
  .thumb_set TIMG3_CC_IRQHandler,Default_Handler

  .weak      TIMG4_UDT_IRQHandler
  .thumb_set TIMG4_UDT_IRQHandler,Default_Handler

  .weak      TIMG4_TRG_IRQHandler
  .thumb_set TIMG4_TRG_IRQHandler,Default_Handler

  .weak      TIMG4_CC_IRQHandler
  .thumb_set TIMG4_CC_IRQHandler,Default_Handler

  .weak      CMP2_IRQHandler
  .thumb_set CMP2_IRQHandler,Default_Handler

  .weak      CMP3_IRQHandler
  .thumb_set CMP3_IRQHandler,Default_Handler

  .weak      CMP4_IRQHandler
  .thumb_set CMP4_IRQHandler,Default_Handler
/************************ (C) COPYRIGHT XTXTech *****END OF FILE****/

