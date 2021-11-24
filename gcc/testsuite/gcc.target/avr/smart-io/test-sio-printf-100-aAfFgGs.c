/*
  Test smart-io printf variants : test-sio-printf-100-aAfFgGs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f,%g,%s
#define PRINT_ARG a,f,g,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAfFgGs" } } */
/* { dg-final { scan-assembler "call _fprintf_aAfFgGs" } } */
/* { dg-final { scan-assembler "call _sprintf_aAfFgGs" } } */
/* { dg-final { scan-assembler "call _snprintf_aAfFgGs" } } */
/* { dg-final { scan-assembler "call _vprintf_aAfFgGs" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAfFgGs" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAfFgGs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAfFgGs" } } */

