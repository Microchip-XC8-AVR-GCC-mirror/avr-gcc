/*
  Test smart-io printf variants : test-sio-printf-436-eEns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%n,%s
#define PRINT_ARG e,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEns" } } */
/* { dg-final { scan-assembler "call _fprintf_eEns" } } */
/* { dg-final { scan-assembler "call _sprintf_eEns" } } */
/* { dg-final { scan-assembler "call _snprintf_eEns" } } */
/* { dg-final { scan-assembler "call _vprintf_eEns" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEns" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEns" } } */

