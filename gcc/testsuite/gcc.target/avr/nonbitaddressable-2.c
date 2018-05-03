/* { dg-do compile } */
/* { dg-options "-Os -mnon-bit-addressable-registers-mask=0x80000401" } */

/* Test for non bit addressable mask with 0th, 10th and 31st bits set */

#include "bitaddress.h"
int main (void)
{
  do_bitaddress();
  return 0;
}

/* { dg-final { scan-assembler-not "sbi 0,0" } } */
/* { dg-final { scan-assembler-not "sbi 0xa,0" } } */
/* { dg-final { scan-assembler-not "sbi 0x1f,0" } } */
/* { dg-final { scan-assembler-not "cbi 0,0" } } */
/* { dg-final { scan-assembler-not "cbi 0xa,0" } } */
/* { dg-final { scan-assembler-not "cbi 0x1f,0" } } */
/* { dg-final { scan-assembler "sbic 0x3,3\n\tsbi 0x1,2\n.L2:\n\tsbis 0x4,2\n\tcbi 0x2,0" } } */

