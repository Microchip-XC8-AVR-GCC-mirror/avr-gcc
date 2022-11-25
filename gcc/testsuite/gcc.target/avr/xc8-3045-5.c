/* { dg-do compile } */
/* { dg-options "-fsection-anchors -Os -msmart-io-format=\"%d%s\" " } */

#include <stdarg.h>
#include <stdio.h>

#include <stdarg.h>
#include <stdio.h>

FILE *fp;
char *buf;

void test (char* format, ...)
{
   va_list argptr;
   va_start(argptr, format);

   vprintf(format , argptr);
   vfprintf(fp, format , argptr);
   vsprintf(buf, format , argptr);
   vsnprintf(buf, 10, format , argptr);

   vscanf(format, argptr);
   vsscanf(buf, format, argptr);
   vfscanf(fp, format, argptr);

   va_end(argptr);
}

/* { dg-final { scan-assembler "call _vprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdnopsuxX" } } */

