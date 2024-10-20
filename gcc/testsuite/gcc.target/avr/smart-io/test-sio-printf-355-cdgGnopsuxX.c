/*
  Test smart-io printf variants : test-sio-printf-355-cdgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%g,%n,%s,%x
#define PRINT_ARG d,g,n,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdgGnopsuxX" } } */

