/*
  Test smart-io printf variants : test-sio-printf-392-eEfFgGn.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%g,%n
#define PRINT_ARG e,f,g,n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEfFgGn" } } */
/* { dg-final { scan-assembler "call _fprintf_eEfFgGn" } } */
/* { dg-final { scan-assembler "call _sprintf_eEfFgGn" } } */
/* { dg-final { scan-assembler "call _snprintf_eEfFgGn" } } */
/* { dg-final { scan-assembler "call _vprintf_eEfFgGn" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEfFgGn" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEfFgGn" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEfFgGn" } } */

