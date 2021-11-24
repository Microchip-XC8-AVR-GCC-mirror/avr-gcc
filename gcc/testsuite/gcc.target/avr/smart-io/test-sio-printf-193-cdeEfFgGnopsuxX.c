/*
  Test smart-io printf variants : test-sio-printf-193-cdeEfFgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%g,%s,%u,%x
#define PRINT_ARG e,f,g,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEfFgGnopsuxX" } } */

