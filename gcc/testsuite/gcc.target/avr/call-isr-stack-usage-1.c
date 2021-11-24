/* Verify that stack usage is recorded correctly for ISRs
   with jmp to __isr_prologue_save. m128 and xmega128a3 both
   have RAMPZ, so 16 bytes are pushed onto the stack. m4809
   does not have RAMPZ, so its stack usage is 15, and avrtiny
   does not save R18:R19, so its stack usage is 13. */

/* { dg-do compile } */
/* { dg-options "-Os -mcall-isr-prologues -mext=cci -mchp-stack-usage" } */

#include <xc.h>

extern void foo(void);
void __vector_1 (void);
void __interrupt(1) handler()
{
  foo();
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	handler"  } } */
/* { dg-final { scan-assembler ".string	\"handler\""  } } */
/* { dg-final { scan-assembler ".long	0x10\n" { target avr_rampz } } } */
/* { dg-final { scan-assembler ".long	0xd\n" { target avr_tiny } } } */
/* { dg-final { scan-assembler ".long	0xf\n" { target { { ! avr_rampz } && {! avr_tiny } } } } } */
/* { dg-final { scan-assembler ".long	0x40\n"  } } */ /*  SU_INTERRUPT */
/* { dg-final { scan-assembler ".byte	0\n"  } } */
/* { dg-final { scan-assembler "jmp __isr_prologue_saves__\n" } } */
/* { dg-final { scan-assembler "jmp __isr_epilogue_restores__\n" } } */
