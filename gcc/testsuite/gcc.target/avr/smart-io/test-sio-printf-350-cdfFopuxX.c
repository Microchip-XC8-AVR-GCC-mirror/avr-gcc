/*
  Test smart-io printf variants : test-sio-printf-350-cdfFopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%f,%u
#define PRINT_ARG d,f,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdfFopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdfFopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdfFopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdfFopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdfFopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdfFopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdfFopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdfFopuxX" } } */

