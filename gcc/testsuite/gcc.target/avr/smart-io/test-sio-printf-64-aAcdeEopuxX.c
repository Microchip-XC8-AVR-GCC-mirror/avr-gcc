/*
  Test smart-io printf variants : test-sio-printf-64-aAcdeEopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%e
#define PRINT_ARG a,d,e

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEopuxX" } } */

