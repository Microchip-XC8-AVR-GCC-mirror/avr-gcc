/*
  Test smart-io printf variants : test-sio-printf-444-eEs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%s
#define PRINT_ARG e,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEs" } } */
/* { dg-final { scan-assembler "call _fprintf_eEs" } } */
/* { dg-final { scan-assembler "call _sprintf_eEs" } } */
/* { dg-final { scan-assembler "call _snprintf_eEs" } } */
/* { dg-final { scan-assembler "call _vprintf_eEs" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEs" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEs" } } */

