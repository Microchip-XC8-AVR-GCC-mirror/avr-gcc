/*
  Test smart-io printf variants : test-sio-printf-383-cdopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%x
#define PRINT_ARG d,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdopuxX" } } */

