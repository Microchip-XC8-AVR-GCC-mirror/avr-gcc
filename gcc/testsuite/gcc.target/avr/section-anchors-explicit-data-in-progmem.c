/* Verify that section anchor based addressing does not fail for
   when the user explicitly places data in flash, either using
   named address spaces or the progmem attribute. */

/* { dg-do compile } */
/* { dg-options "-Os -fsection-anchors" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */

#include <avr/pgmspace.h>

const __flash char arr[] = {0xA, 0xB, 0xC};
const __memx char arr2[] = {0xD, 0xE, 0xF};
PROGMEM const char arr3[] = {0x3, 0x4, 0x5};

char foo(int x) {
  return arr[x] + arr2[x] + arr3[x];
}

/* { dg-final { scan-assembler-not ".set	\\.LANCHOR\\d+, \\. \\+ 0" } } */
