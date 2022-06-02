/*
  Test smart-io printf variants : test-sio-printf-148-aAeEfFns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%f,%n,%s
#define PRINT_ARG a,e,f,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAeEfFns" } } */
/* { dg-final { scan-assembler "call _fprintf_aAeEfFns" } } */
/* { dg-final { scan-assembler "call _sprintf_aAeEfFns" } } */
/* { dg-final { scan-assembler "call _snprintf_aAeEfFns" } } */
/* { dg-final { scan-assembler "call _vprintf_aAeEfFns" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAeEfFns" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAeEfFns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAeEfFns" } } */

