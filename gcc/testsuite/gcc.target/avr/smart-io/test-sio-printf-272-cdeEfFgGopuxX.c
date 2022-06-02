/*
  Test smart-io printf variants : test-sio-printf-272-cdeEfFgGopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%e,%f,%g
#define PRINT_ARG d,e,f,g

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEfFgGopuxX" } } */

