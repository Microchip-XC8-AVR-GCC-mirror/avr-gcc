/* Verify that named section with __at doesn't cause section conflict
   error if another named section without __at is present for data (xc8-2653).
   The assembler merges the two sections into a single one with address present. */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include <xc.h>

const char arr1[] __attribute__((section(".mysec"))) __at (0x500) = {0xAB, 0xCD};
const char arr2[] __attribute__((section(".mysec"))) = {0xEF, 0xFE};
extern volatile int x;
int main() {
  x = arr1[x] + arr2[x];
}

/* { dg-final { scan-assembler ".section\t.mysec,(rodata|progmemx)\[\r\n\]" } } */
/* { dg-final { scan-assembler ".section\t.mysec,(rodata|progmemx),address\\(0x500\\)" } } */
