/* Test smart-io-format option merge with other format specifiers. */

/* { dg-do compile } */
/* { dg-options "-msmart-io -msmart-io-format=%f" } */

#include <stdio.h>
#include <stdarg.h>

int d, n;
float f;
va_list _va;
FILE *fp;
char *str;

void t01 (const char *fmt) 
{
  scanf ("%d", &d);
  scanf (fmt, &f);

  vscanf ("%d", _va);
  vscanf (fmt, _va);
  
  fscanf (fp, "%d", &d);
  fscanf (fp, fmt, &f);
 
  vfscanf (fp, "%d",  _va);
  vfscanf (fp, fmt, _va);
  
  sscanf (str, "%d", &d);
  sscanf (str, fmt, &f);

  vsscanf (str, "%d", _va);
  vsscanf (str, fmt, _va);
}


void t02 (const char *fmt) 
{
  printf ("%d", d);
  printf (fmt, f);

  vprintf ("%d", _va);
  vprintf (fmt, _va);
  
  fprintf (fp, "%d", d);
  fprintf (fp, fmt, f);

  vfprintf (fp, "%d", _va);
  vfprintf (fp, fmt, _va);
  
  sprintf (str, "%d", d);
  sprintf (str, fmt, f);

  vsprintf (str, "%d", _va);
  vsprintf (str, fmt, _va);

  snprintf (str, n, "%d", d);
  snprintf (str, n, fmt, f);

  vsnprintf (str, n, "%d", _va);
  vsnprintf (str, n, fmt, _va);
}

const char *s;
void main()
{
  t01(s);
  t02(s);
}

/* { dg-final { scan-assembler-times "call _scanf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _vscanf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _fscanf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _vfscanf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _sscanf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _vsscanf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _printf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _vprintf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _fprintf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _vfprintf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _sprintf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _vsprintf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _snprintf_cdfFnopuxX"  2 } } */
/* { dg-final { scan-assembler-times "call _vsnprintf_cdfFnopuxX"  2 } } */
