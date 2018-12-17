/* Verify that __memx attribute variables output to respective sections.  */
/* { dg-do run } */
/* { dg-options "-mext=cci -save-temps" } */
/* { dg-skip-if "Not for AVRTINY" { "avr-*-*" } { "-mmcu=attiny40" } { "" } } */

#include<xc.h>

typedef const int __memx memx_t;

volatile memx_t __at(0x15000) X = 10;
int main()
{
  if (&X != (memx_t*)0x15000ul)
    __builtin_abort();
  if (X != 10)
    __builtin_abort();
  return 0;
}

/* { dg-final { scan-assembler ".global\tX\[\n\r\]+\t.section\t\\*_\[0-9a-z\]*,progmemx,address\\(0x15000\\)" } } */
/* { dg-final { scan-assembler-not "__do_copy_data" } } */

