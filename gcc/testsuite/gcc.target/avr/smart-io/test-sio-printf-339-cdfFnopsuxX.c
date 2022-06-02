/*
  Test smart-io printf variants : test-sio-printf-339-cdfFnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%f,%n,%s,%x
#define PRINT_ARG d,f,n,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdfFnopsuxX" } } */

