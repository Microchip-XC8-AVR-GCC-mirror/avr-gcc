/*
  Test smart-io printf variants : test-sio-printf-424-eEgGn.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%g,%n
#define PRINT_ARG e,g,n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEgGn" } } */
/* { dg-final { scan-assembler "call _fprintf_eEgGn" } } */
/* { dg-final { scan-assembler "call _sprintf_eEgGn" } } */
/* { dg-final { scan-assembler "call _snprintf_eEgGn" } } */
/* { dg-final { scan-assembler "call _vprintf_eEgGn" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEgGn" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEgGn" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEgGn" } } */

