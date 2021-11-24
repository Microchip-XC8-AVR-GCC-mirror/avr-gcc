/* Verify that -mcall-isr-prologues does not interfere with ISRs
   that benefit from -mgas-isr-prologues. Also verify that this option
   does not kick in for ISRs that do not benefit from -mgas-isr-prologues
   AND don't save all call-used regs. */

/* { dg-do compile } */
/* { dg-options "-mext=cci -mgas-isr-prologues -mcall-isr-prologues -g0" } */

#include <xc.h>

#define PORT  (*(volatile unsigned char *) 0x100)
#define PORTxx  (*(volatile unsigned char *) 0x200)

void __attribute__((__signal__)) __vector_1(void)
{
  PORT |= 0x20;  
}

extern int *ptr;
void __attribute__((__signal__)) __vector_2(void)
{
  // Non-local goto to skip gasisr
  __builtin_longjmp (ptr, 1);
}

/* { dg-final { scan-assembler-not "__isr_prologue_saves" } } */
/* { dg-final { scan-assembler-not "__isr_epilogue_restores" } } */
/* { dg-final { scan-assembler-not "__vector_2:\n\t__gcc_isr" } } */
