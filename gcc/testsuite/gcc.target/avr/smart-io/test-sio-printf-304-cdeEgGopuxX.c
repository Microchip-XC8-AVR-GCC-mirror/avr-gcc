/*
  Test smart-io printf variants : test-sio-printf-304-cdeEgGopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%e,%g
#define PRINT_ARG d,e,g

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEgGopuxX" } } */

