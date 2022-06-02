/*
  Test smart-io printf variants : test-sio-printf-345-cdfFopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%f,%s,%u,%x
#define PRINT_ARG d,f,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdfFopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdfFopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdfFopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdfFopsuxX" } } */

