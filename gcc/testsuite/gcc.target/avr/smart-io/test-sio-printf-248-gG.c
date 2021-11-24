/*
  Test smart-io printf variants : test-sio-printf-248-gG.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %g
#define PRINT_ARG g

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_gG" } } */
/* { dg-final { scan-assembler "call _fprintf_gG" } } */
/* { dg-final { scan-assembler "call _sprintf_gG" } } */
/* { dg-final { scan-assembler "call _snprintf_gG" } } */
/* { dg-final { scan-assembler "call _vprintf_gG" } } */
/* { dg-final { scan-assembler "call _vfprintf_gG" } } */
/* { dg-final { scan-assembler "call _vsprintf_gG" } } */
/* { dg-final { scan-assembler "call _vsnprintf_gG" } } */

