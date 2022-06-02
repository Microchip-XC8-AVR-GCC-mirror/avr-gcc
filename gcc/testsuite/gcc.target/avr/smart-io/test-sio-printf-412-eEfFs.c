/*
  Test smart-io printf variants : test-sio-printf-412-eEfFs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %e,%f,%s
#define PRINT_ARG e,f,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_eEfFs" } } */
/* { dg-final { scan-assembler "call _fprintf_eEfFs" } } */
/* { dg-final { scan-assembler "call _sprintf_eEfFs" } } */
/* { dg-final { scan-assembler "call _snprintf_eEfFs" } } */
/* { dg-final { scan-assembler "call _vprintf_eEfFs" } } */
/* { dg-final { scan-assembler "call _vfprintf_eEfFs" } } */
/* { dg-final { scan-assembler "call _vsprintf_eEfFs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_eEfFs" } } */

