/* { dg-do compile } */
/* { dg-options "-fsection-anchors -Os -msmart-io" } */

#include <stdarg.h>
#include <stdio.h>

void test (char* format, ...)
{
  va_list argptr;
  va_start(argptr, format);
  vprintf("%e" , argptr);
  va_end(argptr);
}

/* { dg-final { scan-assembler "call _vprintf_eE" } } */

