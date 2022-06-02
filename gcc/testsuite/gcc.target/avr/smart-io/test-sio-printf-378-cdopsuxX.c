/*
  Test smart-io printf variants : test-sio-printf-378-cdopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%s,%u
#define PRINT_ARG d,s,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdopsuxX" } } */

