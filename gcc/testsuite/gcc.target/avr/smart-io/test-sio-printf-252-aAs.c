/*
  Test smart-io printf variants : test-sio-printf-252-aAs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%s
#define PRINT_ARG a,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAs" } } */
/* { dg-final { scan-assembler "call _fprintf_aAs" } } */
/* { dg-final { scan-assembler "call _sprintf_aAs" } } */
/* { dg-final { scan-assembler "call _snprintf_aAs" } } */
/* { dg-final { scan-assembler "call _vprintf_aAs" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAs" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAs" } } */

