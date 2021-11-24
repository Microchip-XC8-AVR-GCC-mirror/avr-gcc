/* Test invalid smart-io-format option */

/* { dg-do compile } */
/* { dg-options "-msmart-io -msmart-io-format=%d" } */

#include <stdio.h>
#include <stdarg.h>

int d, n;
float f;
va_list _va;
FILE *fp;
char *str;

void t01 (const char *fmt) 
{
  scanf ("xyz", &d, &f);
  vscanf ("xyz", _va);
  
  printf ("xyz", d, f);
  vprintf ("xyz", _va);
  
}

const char *s;
void main()
{
  t01(s);
}

/* { dg-final { scan-assembler-times "call _scanf_0"  1 } } */
/* { dg-final { scan-assembler-times "call _vscanf_0"  1 } } */
/* { dg-final { scan-assembler-times "call _printf_0"  1 } } */
/* { dg-final { scan-assembler-times "call _vprintf_0"  1 } } */
