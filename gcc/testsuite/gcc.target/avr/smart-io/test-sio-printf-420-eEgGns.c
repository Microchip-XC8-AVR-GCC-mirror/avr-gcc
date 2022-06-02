/*
  Test smart-io printf variants : test-sio-printf-420-eEgGns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%g,%n,%s
#define PRINT_ARG e,g,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEgGns" } } */
/* { dg-final { scan-assembler "call _fprintf_eEgGns" } } */
/* { dg-final { scan-assembler "call _sprintf_eEgGns" } } */
/* { dg-final { scan-assembler "call _snprintf_eEgGns" } } */
/* { dg-final { scan-assembler "call _vprintf_eEgGns" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEgGns" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEgGns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEgGns" } } */

