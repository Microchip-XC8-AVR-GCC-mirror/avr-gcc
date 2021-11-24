/*
  Test smart-io printf variants : test-sio-printf-156-cdeEnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%e,%s
#define PRINT_ARG d,e,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEnopsuxX" } } */

