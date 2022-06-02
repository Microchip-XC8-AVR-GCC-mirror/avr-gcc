/*
  Test smart-io printf variants : test-sio-printf-359-cdgGnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%g,%n,%x
#define PRINT_ARG d,g,n,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdgGnopuxX" } } */

