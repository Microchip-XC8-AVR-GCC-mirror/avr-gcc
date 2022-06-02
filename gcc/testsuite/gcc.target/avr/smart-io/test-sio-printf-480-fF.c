/*
  Test smart-io printf variants : test-sio-printf-480-fF.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %f
#define PRINT_ARG f

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_fF" } } */
/* { dg-final { scan-assembler "call _fprintf_fF" } } */
/* { dg-final { scan-assembler "call _sprintf_fF" } } */
/* { dg-final { scan-assembler "call _snprintf_fF" } } */
/* { dg-final { scan-assembler "call _vprintf_fF" } } */
/* { dg-final { scan-assembler "call _vfprintf_fF" } } */
/* { dg-final { scan-assembler "call _vsprintf_fF" } } */
/* { dg-final { scan-assembler "call _vsnprintf_fF" } } */

