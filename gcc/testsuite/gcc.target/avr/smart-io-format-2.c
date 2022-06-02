/* Test multiple smart-io-format option */

/* { dg-do compile } */
/* { dg-options "-msmart-io -msmart-io-format=\"%f\" -msmart-io-format=\"%d\"" } */

#include <stdio.h>
#include <stdarg.h>

int d, n;
float f;
va_list _va;
FILE *fp;
char *str;

void t01 (const char *fmt) 
{
  scanf (fmt, &d, &f);
  vscanf (fmt, _va);
  
  fscanf (fp, fmt, &d, &f);
  vfscanf (fp, fmt, _va);
  
  sscanf (str, fmt, &d, &f);
  vsscanf (str, fmt, _va);
}


void t02 (const char *fmt) 
{
  printf (fmt, d, f);
  vprintf (fmt, _va);
  
  fprintf (fp, fmt, d, f);
  vfprintf (fp, fmt, _va);
  
  sprintf (str, fmt, d, f);
  vsprintf (str, fmt, _va);

  snprintf (str, n, fmt, d, f);
  vsnprintf (str, n, fmt, _va);
}

const char *s;
int main()
{
  t01(s);
  t02(s);
  return 0;
}

/* { dg-final { scan-assembler-times "call _scanf_cdfFnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vscanf_cdfFnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _fscanf_cdfFnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vfscanf_cdfFnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _sscanf_cdfFnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vsscanf_cdfFnopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _printf_cdfFopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vprintf_cdfFopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _fprintf_cdfFopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vfprintf_cdfFopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _sprintf_cdfFopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vsprintf_cdfFopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _snprintf_cdfFopuxX"  1 } } */
/* { dg-final { scan-assembler-times "call _vsnprintf_cdfFopuxX"  1 } } */
