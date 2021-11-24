/*
  Test smart-io printf variants : test-sio-printf-252-s.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %s
#define PRINT_ARG s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_s" } } */
/* { dg-final { scan-assembler "call fputs" } } */
/* { dg-final { scan-assembler "call strcpy" } } */
/* { dg-final { scan-assembler "call _snprintf_s" } } */
/* { dg-final { scan-assembler "call _vprintf_s" } } */
/* { dg-final { scan-assembler "call _vfprintf_s" } } */
/* { dg-final { scan-assembler "call _vsprintf_s" } } */
/* { dg-final { scan-assembler "call _vsnprintf_s" } } */

