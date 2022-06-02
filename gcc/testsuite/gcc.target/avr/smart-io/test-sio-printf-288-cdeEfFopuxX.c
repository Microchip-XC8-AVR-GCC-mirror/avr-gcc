/*
  Test smart-io printf variants : test-sio-printf-288-cdeEfFopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%e,%f
#define PRINT_ARG d,e,f

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEfFopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEfFopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEfFopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEfFopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEfFopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEfFopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEfFopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEfFopuxX" } } */

