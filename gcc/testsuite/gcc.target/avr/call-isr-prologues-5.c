/* Verify -mcall-isr-prologues codegen for a function that saves
   callee-saved reg. */

/* { dg-do compile } */
/* { dg-options "-mext=cci -Os -mcall-isr-prologues" } */

#include <xc.h>

#ifdef __AVR_TINY__
#define CALLEE_SAVED_REG "r18"
#else
#define CALLEE_SAVED_REG "r15"
#endif

extern int foo();
void __attribute__((__signal__)) __vector_1(void)
{
  __asm__ ("" : : : CALLEE_SAVED_REG);
  foo();
}

/* { dg-final { scan-assembler "__vector_1:\n" } } */
/* { dg-final { scan-assembler "push r30\n" } } */
/* { dg-final { scan-assembler "push r31\n" } } */
/* { dg-final { scan-assembler "ldi r30,lo8\\(gs\\(1f\\)\\)\n" } } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(gs\\(1f\\)\\)\n" } } */
/* { dg-final { scan-assembler "jmp __isr_prologue_saves__\n" } } */
/* { dg-final { scan-assembler "1:\n" } } */
/* { dg-final { scan-assembler "push r1(5|8)\n" } } */
/* { dg-final { scan-assembler "call foo\n" } } */
/* { dg-final { scan-assembler "pop r1(5|8)\n" } } */
/* { dg-final { scan-assembler "jmp __isr_epilogue_restores__\n" } } */
