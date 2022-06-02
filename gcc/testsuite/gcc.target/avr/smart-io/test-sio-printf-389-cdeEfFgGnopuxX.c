/*
  Test smart-io printf variants : test-sio-printf-389-cdeEfFgGnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%g,%n,%u,%x
#define PRINT_ARG e,f,g,n,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEfFgGnopuxX" } } */

