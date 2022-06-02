/*
  Test smart-io printf variants : test-sio-printf-224-aAfF.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f
#define PRINT_ARG a,f

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAfF" } } */
/* { dg-final { scan-assembler "call _fprintf_aAfF" } } */
/* { dg-final { scan-assembler "call _sprintf_aAfF" } } */
/* { dg-final { scan-assembler "call _snprintf_aAfF" } } */
/* { dg-final { scan-assembler "call _vprintf_aAfF" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAfF" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAfF" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAfF" } } */

