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

int t01()
{
  printf (fmt, f);
  printf ("%d", d);
}

int t02()
{
  fprintf (fp, fmt, f);
  fprintf (fp, "%d", d);
}

int t03()
{
  sprintf (s, fmt, f);
  sprintf (s, "%d", d);
}

int t04()
{
  snprintf (s, 2, fmt, f);
  snprintf (s, 2, "%d", d);
}

int t05()
{
  vprintf (fmt, va);
  vprintf ("%d", va);
}

int t06()
{
  vfprintf (fp, fmt, va);
  vfprintf (fp, "%d", va);
}

int t07()
{
  vsprintf (s, fmt, va);
  vsprintf (s, "%d", va);
}

int t08()
{
  vsnprintf (s, 2, fmt, va);
  vsnprintf (s, 2, "%d", va);
}


int s01()
{
  scanf (fmt, &f);
  scanf ("%d", &d);
}

int s02()
{
  fscanf (fp, fmt, &f);
  fscanf (fp, "%d", &d);
}

int s03()
{
  sscanf (s, fmt, &f);
  sscanf (s, "%d", &d);
}

int s04()
{
  vscanf (fmt, va);
  vscanf ("%d", va);
}

int s05()
{
  vfscanf (fp, fmt, va);
  vfscanf (fp, "%d", va);
}

int s06()
{
  vsscanf (s, fmt, va);
  vsscanf (s, "%d", va);
}


/* { dg-final { scan-assembler-times "call printf"  2 } } */
/* { dg-final { scan-assembler-times "call fprintf"  2 } } */
/* { dg-final { scan-assembler-times "call sprintf"  2 } } */
/* { dg-final { scan-assembler-times "call snprintf"  2 } } */
/* { dg-final { scan-assembler-times "call vprintf"  2 } } */
/* { dg-final { scan-assembler-times "call vfprintf"  2 } } */
/* { dg-final { scan-assembler-times "call vsprintf"  2 } } */
/* { dg-final { scan-assembler-times "call vsnprintf"  2 } } */
/* { dg-final { scan-assembler-times "call scanf"  2 } } */
/* { dg-final { scan-assembler-times "call fscanf"  2 } } */
/* { dg-final { scan-assembler-times "call sscanf"  2 } } */
/* { dg-final { scan-assembler-times "call vscanf"  2 } } */
/* { dg-final { scan-assembler-times "call vfscanf"  2 } } */
/* { dg-final { scan-assembler-times "call vsscanf"  2 } } */

