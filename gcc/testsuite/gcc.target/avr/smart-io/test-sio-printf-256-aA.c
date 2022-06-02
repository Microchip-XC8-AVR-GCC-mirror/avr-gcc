/*
  Test smart-io printf variants : test-sio-printf-256-aA.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a
#define PRINT_ARG a

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aA" } } */
/* { dg-final { scan-assembler "call _fprintf_aA" } } */
/* { dg-final { scan-assembler "call _sprintf_aA" } } */
/* { dg-final { scan-assembler "call _snprintf_aA" } } */
/* { dg-final { scan-assembler "call _vprintf_aA" } } */
/* { dg-final { scan-assembler "call _vfprintf_aA" } } */
/* { dg-final { scan-assembler "call _vsprintf_aA" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aA" } } */

