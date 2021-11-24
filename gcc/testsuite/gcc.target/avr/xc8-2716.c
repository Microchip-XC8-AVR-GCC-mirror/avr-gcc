/* { dg-do compile } */
/* { dg-options "-msmart-io -mconst-data-in-progmem" } */

#include <stdio.h>
#include <stdlib.h>

int x;

int main()
{
  sscanf ("10", "%x", &x);
  if (x != 0x10)
    abort();
  return 0;
}

/* { dg-final { scan-assembler "call _sscanf_cdnopuxX" } } */

