/*
  Test smart-io printf variants : test-sio-printf-266-cdeEfFgGopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%e,%f,%g,%s,%u
#define PRINT_ARG d,e,f,g,s,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEfFgGopsuxX" } } */

