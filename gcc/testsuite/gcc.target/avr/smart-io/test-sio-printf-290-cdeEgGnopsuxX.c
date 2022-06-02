/*
  Test smart-io printf variants : test-sio-printf-290-cdeEgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%e,%g,%n,%s,%u
#define PRINT_ARG d,e,g,n,s,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEgGnopsuxX" } } */

