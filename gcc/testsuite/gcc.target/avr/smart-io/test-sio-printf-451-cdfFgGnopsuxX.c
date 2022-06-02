/*
  Test smart-io printf variants : test-sio-printf-451-cdfFgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %f,%g,%n,%s,%x
#define PRINT_ARG f,g,n,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdfFgGnopsuxX" } } */

