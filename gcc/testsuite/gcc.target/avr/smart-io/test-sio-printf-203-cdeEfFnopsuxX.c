/*
  Test smart-io printf variants : test-sio-printf-203-cdeEfFnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%s,%x
#define PRINT_ARG e,f,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEfFnopsuxX" } } */

