/* How the smart-io variants are output */
/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include <stdio.h>

extern const char *fmt ; /* "%f" */

float f = 1.234f;
int   d = 1234;

int t()
{
  printf (fmt, f);
  printf ("%d", d);
}

/* { dg-final { scan-assembler-times "call printf"  2 } } */

