/* { dg-do compile } */
/* { dg-options "-Os -mnon-bit-addressable-registers-mask=0x0000001e" } */

/* Test for non bit addressable mask with 1st,2nd,3rd and 4th bits set */

#include "bitaddress.h"
int main (void)
{
  do_bitaddress();
  return 0;
}

/* { dg-final { scan-assembler "sbi 0,0\n\tsbi 0xa,0\n\tsbi 0x1f,0" } } */
/* { dg-final { scan-assembler "cbi 0,0\n\tcbi 0xa,0\n\tcbi 0x1f,0" } } */
/* { dg-final { scan-assembler-not "sbic 0x3,3" } } */
/* { dg-final { scan-assembler-not "sbi 0x1,2" } } */
/* { dg-final { scan-assembler-not "sbis 0x4,2" } } */
/* { dg-final { scan-assembler-not "cbi 0x2,0" } } */

