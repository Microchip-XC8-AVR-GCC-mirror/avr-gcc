/*
  Test smart-io printf variants : test-sio-printf-468-fFns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %f,%n,%s
#define PRINT_ARG f,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_fFns" } } */
/* { dg-final { scan-assembler "call _fprintf_fFns" } } */
/* { dg-final { scan-assembler "call _sprintf_fFns" } } */
/* { dg-final { scan-assembler "call _snprintf_fFns" } } */
/* { dg-final { scan-assembler "call _vprintf_fFns" } } */
/* { dg-final { scan-assembler "call _vfprintf_fFns" } } */
/* { dg-final { scan-assembler "call _vsprintf_fFns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_fFns" } } */

