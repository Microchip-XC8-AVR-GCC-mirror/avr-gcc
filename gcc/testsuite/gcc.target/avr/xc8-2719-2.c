/* How the smart-io variants are output */
/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include <stdio.h>

extern const char *fmt ; /* "%f" */

float f = 1.234f;
int   d = 1234;

va_list va;
FILE    *fp;
char    *s;


int p0_1()
{
  printf ("%d", d);
  printf ("%f", f);
}

int p0_2()
{
  printf ("%d", d);
  printf (fmt, f);
}

int p0_3()
{
  printf ("%d", d);
  printf ("%f", f);
}

/* ------------------ */

int p1_1()
{
  vprintf ("%d", va);
  vprintf ("%f", va);
}

int p1_2()
{
  vprintf ("%d", va);
  vprintf (fmt, va);
}

int p1_3()
{
  vprintf ("%d", va);
  vprintf ("%f", va);
}

/* ------------------ */

int s0_1()
{
  scanf ("%f", &f);
  scanf ("%d", &d);
}

int s0_2()
{
  scanf (fmt, &f);
  scanf ("%d", &d);
}
int s0_3()
{
  scanf ("%f", &f);
  scanf ("%d", &d);
}

/* ------------------ */

int s1_1()
{
  vsscanf (s, "%f", va);
  vsscanf (s, "%d", va);
}

int s1_2()
{
  vsscanf (s, fmt, va);
  vsscanf (s, "%d", va);
}

int s1_3()
{
  vsscanf (s, "%f", va);
  vsscanf (s, "%d", va);
}

/* ------------------ */

/* { dg-final { scan-assembler-times "call _printf_cdfFopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call printf"  2 } } */
/* { dg-final { scan-assembler-times "call _vprintf_cdfFopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call vprintf"  2 } } */
/* { dg-final { scan-assembler-times "call _scanf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call scanf"  2 } } */
/* { dg-final { scan-assembler-times "call _vsscanf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call vsscanf"  2 } } */
