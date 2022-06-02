/*
  Test smart-io printf variants : test-sio-printf-432-eEgG.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%g
#define PRINT_ARG e,g

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEgG" } } */
/* { dg-final { scan-assembler "call _fprintf_eEgG" } } */
/* { dg-final { scan-assembler "call _sprintf_eEgG" } } */
/* { dg-final { scan-assembler "call _snprintf_eEgG" } } */
/* { dg-final { scan-assembler "call _vprintf_eEgG" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEgG" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEgG" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEgG" } } */

