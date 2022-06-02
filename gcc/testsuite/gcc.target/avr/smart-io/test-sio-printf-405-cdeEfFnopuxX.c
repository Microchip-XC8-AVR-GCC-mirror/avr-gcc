/*
  Test smart-io printf variants : test-sio-printf-405-cdeEfFnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%n,%u,%x
#define PRINT_ARG e,f,n,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEfFnopuxX" } } */

