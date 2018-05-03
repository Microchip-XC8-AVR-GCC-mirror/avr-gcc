/* Verify that CCI interrupt attribute handled.  */
/* { dg-do run } */
/* { dg-options "-mext=cci" } */

#include <xc.h>
// prototype of interrupt function alias, to avoid implicit definition warning
void __vector_4 ();

volatile int state = 1;
void __interrupt(4) INT4_handler()
{
  state = 0xff;
}

int main ()
{
  // call ISR
  __vector_4 ();

  if (state != 0xff)
    __builtin_abort();
  return 0;
}

