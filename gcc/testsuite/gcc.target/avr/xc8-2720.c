/* Verify that _printf_s smart-io variant is generated when there are
   no format specifier with printf function. */
/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include <stdio.h>

void t01()
{
  printf ("Hello, World!");
}

const char *msg = "Hello!";
void t02()
{
  printf(msg);
}

void t03( const char * s)
{
  printf(s);
}

int d = 10;
void t04()
{
  printf ("%d", d);
}

int main()
{
  t01();
  t02();
  t03(msg);
  t04();
  return 0;
}

/* { dg-final { scan-assembler-times "call _printf_s"  3 } } */
/* { dg-final { scan-assembler-times "call _printf_cdopsuxX"  1 } } */
