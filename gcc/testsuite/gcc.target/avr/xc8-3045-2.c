/* { dg-do compile } */
/* { dg-options "-fsection-anchors -Os" } */

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

/* { dg-final { scan-assembler "call vprintf" } } */
/* { dg-final { scan-assembler "call vfprintf" } } */
/* { dg-final { scan-assembler "call vsprintf" } } */
/* { dg-final { scan-assembler "call vsnprintf" } } */
/* { dg-final { scan-assembler "call vscanf" } } */
/* { dg-final { scan-assembler "call vsscanf" } } */
/* { dg-final { scan-assembler "call vfscanf" } } */

