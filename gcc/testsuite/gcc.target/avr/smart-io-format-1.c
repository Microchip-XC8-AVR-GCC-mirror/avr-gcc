/* Test smart-io-format option */

/* { dg-do compile } */
/* { dg-options "-msmart-io -msmart-io-format=\"%d\"" } */

#include <stdio.h>
#include <stdarg.h>

int d, n;
va_list _va;
FILE *fp;
char *str;

void t01 (const char *fmt) 
{
  scanf (fmt, &d);
  vscanf (fmt, _va);
  
  fscanf (fp, fmt, &d);
  vfscanf (fp, fmt, _va);
  
  sscanf (str, fmt, &d);
  vsscanf (str, fmt, _va);
}


void t02 (const char *fmt) 
{
  printf (fmt, d);
  vprintf (fmt, _va);
  
  fprintf (fp, fmt, d);
  vfprintf (fp, fmt, _va);
  
  sprintf (str, fmt, d);
  vsprintf (str, fmt, _va);

  snprintf (str, n, fmt, d);
  vsnprintf (str, n, fmt, _va);
}

const char *s;
void main()
{
  t01(s);
  t02(s);
}

/* { dg-final { scan-assembler-times "call _scanf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vscanf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _fscanf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vfscanf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _sscanf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vsscanf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _printf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vprintf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _fprintf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vfprintf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _sprintf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vsprintf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _snprintf_cdnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vsnprintf_cdnopuxX"  1 } } */
