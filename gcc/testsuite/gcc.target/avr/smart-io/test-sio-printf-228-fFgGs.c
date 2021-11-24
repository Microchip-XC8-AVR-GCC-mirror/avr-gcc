/*
  Test smart-io printf variants : test-sio-printf-228-fFgGs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %f,%g,%s
#define PRINT_ARG f,g,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_fFgGs" } } */
/* { dg-final { scan-assembler "call _fprintf_fFgGs" } } */
/* { dg-final { scan-assembler "call _sprintf_fFgGs" } } */
/* { dg-final { scan-assembler "call _snprintf_fFgGs" } } */
/* { dg-final { scan-assembler "call _vprintf_fFgGs" } } */
/* { dg-final { scan-assembler "call _vfprintf_fFgGs" } } */
/* { dg-final { scan-assembler "call _vsprintf_fFgGs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_fFgGs" } } */

