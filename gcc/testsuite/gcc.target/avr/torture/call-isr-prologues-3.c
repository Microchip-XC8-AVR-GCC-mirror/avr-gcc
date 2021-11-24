/* Verify -mcall-isr-prologues codegen for a function that does not
   require framepointer. */

/* { dg-do compile } */
/* { dg-options "-mext=cci -mcall-isr-prologues -g0" } */

#include <xc.h>

extern void foo();
void __attribute__((__signal__)) __vector_1(void)
{
  foo();
}

/* { dg-final { scan-assembler "__vector_1:\n" } } */
/* { dg-final { scan-assembler "push r30\n" } } */
/* { dg-final { scan-assembler "push r31\n" } } */
/* { dg-final { scan-assembler "ldi r30,lo8\\(gs\\(1f\\)\\)\n" } } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(gs\\(1f\\)\\)\n" } } */
/* { dg-final { scan-assembler "jmp __isr_prologue_saves__\n" } } */
/* { dg-final { scan-assembler "call foo\n" } } */
/* { dg-final { scan-assembler "jmp __isr_epilogue_restores__\n" } } */
