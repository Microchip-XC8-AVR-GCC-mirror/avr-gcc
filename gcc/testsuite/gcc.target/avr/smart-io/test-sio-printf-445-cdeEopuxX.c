/*
  Test smart-io printf variants : test-sio-printf-445-cdeEopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%u,%x
#define PRINT_ARG e,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEopuxX" } } */

