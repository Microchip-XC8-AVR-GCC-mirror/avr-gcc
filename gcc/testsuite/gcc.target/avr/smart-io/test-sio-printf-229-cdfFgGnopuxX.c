/*
  Test smart-io printf variants : test-sio-printf-229-cdfFgGnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %f,%g,%u,%x
#define PRINT_ARG f,g,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdfFgGnopuxX" } } */

