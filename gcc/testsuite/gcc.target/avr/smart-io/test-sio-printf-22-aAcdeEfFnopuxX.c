/*
  Test smart-io printf variants : test-sio-printf-22-aAcdeEfFnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%e,%f,%n,%u
#define PRINT_ARG a,d,e,f,n,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEfFnopuxX" } } */

