/*
  Test smart-io printf variants : test-sio-printf-284-cdeEfFopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%e,%f,%s
#define PRINT_ARG d,e,f,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEfFopsuxX" } } */

