/*
  Test smart-io printf variants : test-sio-printf-54-aAcdeEnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%e,%n,%u
#define PRINT_ARG a,d,e,n,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEnopuxX" } } */

