/*
  Test smart-io printf variants : test-sio-printf-244-aAns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%n,%s
#define PRINT_ARG a,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAns" } } */
/* { dg-final { scan-assembler "call _fprintf_aAns" } } */
/* { dg-final { scan-assembler "call _sprintf_aAns" } } */
/* { dg-final { scan-assembler "call _snprintf_aAns" } } */
/* { dg-final { scan-assembler "call _vprintf_aAns" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAns" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAns" } } */

