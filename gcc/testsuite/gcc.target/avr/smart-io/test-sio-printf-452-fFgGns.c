/*
  Test smart-io printf variants : test-sio-printf-452-fFgGns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %f,%g,%n,%s
#define PRINT_ARG f,g,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_fFgGns" } } */
/* { dg-final { scan-assembler "call _fprintf_fFgGns" } } */
/* { dg-final { scan-assembler "call _sprintf_fFgGns" } } */
/* { dg-final { scan-assembler "call _snprintf_fFgGns" } } */
/* { dg-final { scan-assembler "call _vprintf_fFgGns" } } */
/* { dg-final { scan-assembler "call _vfprintf_fFgGns" } } */
/* { dg-final { scan-assembler "call _vsprintf_fFgGns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_fFgGns" } } */

