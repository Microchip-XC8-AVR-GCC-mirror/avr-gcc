/*
  Test smart-io printf variants : test-sio-printf-388-eEfFgGns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%g,%n,%s
#define PRINT_ARG e,f,g,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEfFgGns" } } */
/* { dg-final { scan-assembler "call _fprintf_eEfFgGns" } } */
/* { dg-final { scan-assembler "call _sprintf_eEfFgGns" } } */
/* { dg-final { scan-assembler "call _snprintf_eEfFgGns" } } */
/* { dg-final { scan-assembler "call _vprintf_eEfFgGns" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEfFgGns" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEfFgGns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEfFgGns" } } */

