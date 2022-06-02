/*
  Test smart-io printf variants : test-sio-printf-313-cdeEopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %d,%e,%s,%u,%x
#define PRINT_ARG d,e,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdeEopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdeEopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdeEopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdeEopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdeEopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdeEopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdeEopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdeEopsuxX" } } */

