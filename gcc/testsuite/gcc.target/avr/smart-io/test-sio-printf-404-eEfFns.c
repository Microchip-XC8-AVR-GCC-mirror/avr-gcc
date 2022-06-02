/*
  Test smart-io printf variants : test-sio-printf-404-eEfFns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%n,%s
#define PRINT_ARG e,f,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEfFns" } } */
/* { dg-final { scan-assembler "call _fprintf_eEfFns" } } */
/* { dg-final { scan-assembler "call _sprintf_eEfFns" } } */
/* { dg-final { scan-assembler "call _snprintf_eEfFns" } } */
/* { dg-final { scan-assembler "call _vprintf_eEfFns" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEfFns" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEfFns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEfFns" } } */

