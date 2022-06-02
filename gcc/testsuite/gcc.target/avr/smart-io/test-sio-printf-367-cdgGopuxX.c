/*
  Test smart-io printf variants : test-sio-printf-367-cdgGopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%g,%x
#define PRINT_ARG d,g,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdgGopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdgGopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdgGopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdgGopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdgGopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdgGopuxX" } } */

