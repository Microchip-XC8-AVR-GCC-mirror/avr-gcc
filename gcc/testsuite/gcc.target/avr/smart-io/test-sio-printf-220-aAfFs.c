/*
  Test smart-io printf variants : test-sio-printf-220-aAfFs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f,%s
#define PRINT_ARG a,f,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAfFs" } } */
/* { dg-final { scan-assembler "call _fprintf_aAfFs" } } */
/* { dg-final { scan-assembler "call _sprintf_aAfFs" } } */
/* { dg-final { scan-assembler "call _snprintf_aAfFs" } } */
/* { dg-final { scan-assembler "call _vprintf_aAfFs" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAfFs" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAfFs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAfFs" } } */

