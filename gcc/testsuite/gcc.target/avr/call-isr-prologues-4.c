/* Verify -mcall-isr-prologues codegen for a function that requires
   framepointer. */

/* { dg-do compile } */
/* { dg-options "-mext=cci -Os -mcall-isr-prologues" } */

#include <xc.h>

extern int foo(); extern volatile int x;
void __attribute__((__signal__)) __vector_1(void)
{
  int arr[] = {1,2,3,4};
  int res = foo();
  x = arr[res];
}

/* { dg-final { scan-assembler "__vector_1:\n" } } */
/* { dg-final { scan-assembler "push r30\n" } } */
/* { dg-final { scan-assembler "push r31\n" } } */
/* { dg-final { scan-assembler "ldi r30,lo8\\(gs\\(1f\\)\\)\n" } } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(gs\\(1f\\)\\)\n" } } */
/* { dg-final { scan-assembler "jmp __isr_prologue_saves__\n" } } */
/* { dg-final { scan-assembler "1:\n" } } */
/* { dg-final { scan-assembler "push r28\n" } } */
/* { dg-final { scan-assembler "push r29\n" } } */
/* Reserve space on stack, execution function body, restore SP  */
/* { dg-final { scan-assembler "pop r29\n" } } */
/* { dg-final { scan-assembler "pop r28\n" } } */
/* { dg-final { scan-assembler "jmp __isr_epilogue_restores__\n" } } */
