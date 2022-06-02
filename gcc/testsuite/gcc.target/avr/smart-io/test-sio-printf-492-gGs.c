/*
  Test smart-io printf variants : test-sio-printf-492-gGs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %g,%s
#define PRINT_ARG g,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_gGs" } } */
/* { dg-final { scan-assembler "call _fprintf_gGs" } } */
/* { dg-final { scan-assembler "call _sprintf_gGs" } } */
/* { dg-final { scan-assembler "call _snprintf_gGs" } } */
/* { dg-final { scan-assembler "call _vprintf_gGs" } } */
/* { dg-final { scan-assembler "call _vfprintf_gGs" } } */
/* { dg-final { scan-assembler "call _vsprintf_gGs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_gGs" } } */

