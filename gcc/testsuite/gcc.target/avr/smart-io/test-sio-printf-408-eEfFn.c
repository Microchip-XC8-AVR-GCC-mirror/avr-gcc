/*
  Test smart-io printf variants : test-sio-printf-408-eEfFn.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%n
#define PRINT_ARG e,f,n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEfFn" } } */
/* { dg-final { scan-assembler "call _fprintf_eEfFn" } } */
/* { dg-final { scan-assembler "call _sprintf_eEfFn" } } */
/* { dg-final { scan-assembler "call _snprintf_eEfFn" } } */
/* { dg-final { scan-assembler "call _vprintf_eEfFn" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEfFn" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEfFn" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEfFn" } } */

