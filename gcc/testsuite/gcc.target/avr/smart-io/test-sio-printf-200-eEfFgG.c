/*
  Test smart-io printf variants : test-sio-printf-200-eEfFgG.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%g
#define PRINT_ARG e,f,g

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _fprintf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _sprintf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _snprintf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _vprintf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEfFgG" } } */

