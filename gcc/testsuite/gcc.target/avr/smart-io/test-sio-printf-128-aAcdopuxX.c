/*
  Test smart-io printf variants : test-sio-printf-128-aAcdopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d
#define PRINT_ARG a,d

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdopuxX" } } */

