/*
  Test smart-io printf variants : test-sio-printf-504-n.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %n
#define PRINT_ARG n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_n" } } */
/* { dg-final { scan-assembler "call _fprintf_n" } } */
/* { dg-final { scan-assembler "call _sprintf_n" } } */
/* { dg-final { scan-assembler "call _snprintf_n" } } */
/* { dg-final { scan-assembler "call _vprintf_n" } } */
/* { dg-final { scan-assembler "call _vfprintf_n" } } */
/* { dg-final { scan-assembler "call _vsprintf_n" } } */
/* { dg-final { scan-assembler "call _vsnprintf_n" } } */

