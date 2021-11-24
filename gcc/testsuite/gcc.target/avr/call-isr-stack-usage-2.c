/* Verify that stack usage is recorded correctly for ISRs
   that save a call-saved reg, and with jmp to __isr_prologue_save.
   Expected usage is one more than that of call-isr-stack-usage-1.c. */

/* { dg-do compile } */
/* { dg-options "-Os -mcall-isr-prologues -mext=cci -mchp-stack-usage" } */

#ifdef __AVR_TINY__
#define CALLEE_SAVED_REG "r18"
#else
#define CALLEE_SAVED_REG "r15"
#endif

#include <xc.h>

extern void foo(void);
void __vector_1 (void);
void __interrupt(1) handler()
{
  __asm__ ("" : : : CALLEE_SAVED_REG);
  foo();
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	handler"  } } */
/* { dg-final { scan-assembler ".string	\"handler\""  } } */
/* { dg-final { scan-assembler ".long	0x11\n" { target avr_rampz } } } */
/* { dg-final { scan-assembler ".long	0xe\n" { target avr_tiny } } } */
/* { dg-final { scan-assembler ".long	0x10\n" { target { { ! avr_rampz } && {! avr_tiny } } } } } */
/* { dg-final { scan-assembler ".long	0x42\n"  } } */ /*  SU_INTERRUPT */
/* { dg-final { scan-assembler ".byte	0\n"  } } */
/* { dg-final { scan-assembler "jmp __isr_prologue_saves__\n" } } */
/* { dg-final { scan-assembler "jmp __isr_epilogue_restores__\n" } } */
