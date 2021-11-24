/*
  Test smart-io printf variants : test-sio-printf-208-eEfF.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f
#define PRINT_ARG e,f

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEfF" } } */
/* { dg-final { scan-assembler "call _fprintf_eEfF" } } */
/* { dg-final { scan-assembler "call _sprintf_eEfF" } } */
/* { dg-final { scan-assembler "call _snprintf_eEfF" } } */
/* { dg-final { scan-assembler "call _vprintf_eEfF" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEfF" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEfF" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEfF" } } */

