/*
  Test smart-io printf variants : test-sio-printf-396-eEfFgGs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%g,%s
#define PRINT_ARG e,f,g,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _fprintf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _sprintf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _snprintf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _vprintf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEfFgGs" } } */

