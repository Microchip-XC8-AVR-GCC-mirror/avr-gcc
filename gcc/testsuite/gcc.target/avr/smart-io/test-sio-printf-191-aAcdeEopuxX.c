/*
  Test smart-io printf variants : test-sio-printf-191-aAcdeEopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%x
#define PRINT_ARG a,e,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEopuxX" } } */

