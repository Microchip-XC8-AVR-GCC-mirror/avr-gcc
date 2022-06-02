/*
  Test smart-io printf variants : test-sio-printf-488-gGn.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %g,%n
#define PRINT_ARG g,n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_gGn" } } */
/* { dg-final { scan-assembler "call _fprintf_gGn" } } */
/* { dg-final { scan-assembler "call _sprintf_gGn" } } */
/* { dg-final { scan-assembler "call _snprintf_gGn" } } */
/* { dg-final { scan-assembler "call _vprintf_gGn" } } */
/* { dg-final { scan-assembler "call _vfprintf_gGn" } } */
/* { dg-final { scan-assembler "call _vsprintf_gGn" } } */
/* { dg-final { scan-assembler "call _vsnprintf_gGn" } } */

