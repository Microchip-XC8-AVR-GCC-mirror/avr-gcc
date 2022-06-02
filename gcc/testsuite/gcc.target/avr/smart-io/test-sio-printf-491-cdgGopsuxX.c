/*
  Test smart-io printf variants : test-sio-printf-491-cdgGopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %g,%s,%x
#define PRINT_ARG g,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdgGopsuxX" } } */

