/* Verify the memory read straddle over flash segments.  */
/* { dg-do run } */
/* { dg-options "-mext=cci -save-temps" } */
/* { dg-skip-if "Not for AVRTINY" { "avr-*-*" } { "-mmcu=attiny40" } { "" } } */

#include<xc.h>

typedef const int __memx memx_t;

volatile memx_t __at(0xfffe) X = 13;
int main()
{
  if (&X != (memx_t*)0xfffe)
    __builtin_abort();
  if (X != 13)
    __builtin_abort();
  return 0;
}

/* { dg-final { scan-assembler ".global\tX\[\n\r\]+\t.section\t\\*_\[0-9a-z\]*,progmemx,address\\(0xfffe\\)" } } */

