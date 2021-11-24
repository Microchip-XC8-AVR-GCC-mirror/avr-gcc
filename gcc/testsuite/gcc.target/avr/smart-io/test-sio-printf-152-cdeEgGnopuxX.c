/*
  Test smart-io printf variants : test-sio-printf-152-cdeEgGnopuxX.c
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

/* { dg-final { scan-assembler "call _printf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEgGnopuxX" } } */

