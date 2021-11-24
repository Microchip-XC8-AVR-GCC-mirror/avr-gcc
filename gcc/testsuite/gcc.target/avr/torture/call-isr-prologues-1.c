/* { dg-do run } */
/* { dg-options "-save-temps -std=c99 -mcall-isr-prologues -g0" } */

#include "../isr-test.h"

int volatile v;

__attribute__((noinline,noclone))
void inc_v (void)
{
  v++;
}

/**********************************************************************/

ISR (1, signal)
{
  inc_v();
}
/* { dg-final { scan-assembler "__vector_1:\n\tpush r30\n\tpush r31\n\tldi.*\n\tldi.*\n\tr?jmp __isr_prologue_saves" } } */

MK_RUN_ISR (1, 0)

void test1 (void)
{
  run_isr_1();
  if (v != 1)
    __builtin_abort();
}

/**********************************************************************/

ISR (2, signal)
{
  if (v == 1)
    inc_v();
  else
    v += 2;
}
/* { dg-final { scan-assembler "__vector_2:\n\tpush r30\n\tpush r31\n\tldi.*\n\tldi.*\n\tr?jmp __isr_prologue_saves" } } */

MK_RUN_ISR (2, 0)

void test2 (void)
{
  run_isr_2();
  if (v != 2)
    __builtin_abort();
  run_isr_2();
  if (v != 4)
    __builtin_abort();
}


/**********************************************************************/

int main (void)
{
  test1();
  test2();
  return 0;
}
