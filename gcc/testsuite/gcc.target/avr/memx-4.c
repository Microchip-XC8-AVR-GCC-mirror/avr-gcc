/* { dg-do run } */
/* { dg-options "-std=gnu99 -O1 -mext=cci" } */
/* { dg-xfail-run-if "pointer arithmetic with constants greater than word mode not expected to work" { avr-*-* } } */
#include <xc.h>
#define ARR_ADDR 0x300
const char __memx __at(ARR_ADDR) arr[10] = "hello";

/* XFAIL: expecting 65535UL to be added to arr in PSImode.
   But pointer arithmetics done in Pmode/word_mode and 65535UL considered as
   HImode integer and sign extended to perform addition to arr (PSImode).  */
const __memx char *eptr = arr + 65535UL;

int main ()
{
  if (eptr != (const __memx void*)(ARR_ADDR + 65535UL))
    __builtin_abort();

  return 0;
}

