/*
  Test smart-io printf variants : test-sio-printf-484-gGns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %g,%n,%s
#define PRINT_ARG g,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_gGns" } } */
/* { dg-final { scan-assembler "call _fprintf_gGns" } } */
/* { dg-final { scan-assembler "call _sprintf_gGns" } } */
/* { dg-final { scan-assembler "call _snprintf_gGns" } } */
/* { dg-final { scan-assembler "call _vprintf_gGns" } } */
/* { dg-final { scan-assembler "call _vfprintf_gGns" } } */
/* { dg-final { scan-assembler "call _vsprintf_gGns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_gGns" } } */

