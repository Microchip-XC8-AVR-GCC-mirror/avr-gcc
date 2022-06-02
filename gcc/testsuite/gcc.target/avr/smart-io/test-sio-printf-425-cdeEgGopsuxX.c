/*
  Test smart-io printf variants : test-sio-printf-425-cdeEgGopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%g,%s,%u,%x
#define PRINT_ARG e,g,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEgGopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEgGopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEgGopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEgGopsuxX" } } */

