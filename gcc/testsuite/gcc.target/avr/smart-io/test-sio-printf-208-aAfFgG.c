/*
  Test smart-io printf variants : test-sio-printf-208-aAfFgG.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f,%g
#define PRINT_ARG a,f,g

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAfFgG" } } */
/* { dg-final { scan-assembler "call _fprintf_aAfFgG" } } */
/* { dg-final { scan-assembler "call _sprintf_aAfFgG" } } */
/* { dg-final { scan-assembler "call _snprintf_aAfFgG" } } */
/* { dg-final { scan-assembler "call _vprintf_aAfFgG" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAfFgG" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAfFgG" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAfFgG" } } */

