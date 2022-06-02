/*
  Test smart-io printf variants : test-sio-printf-456-fFgGn.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %f,%g,%n
#define PRINT_ARG f,g,n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_fFgGn" } } */
/* { dg-final { scan-assembler "call _fprintf_fFgGn" } } */
/* { dg-final { scan-assembler "call _sprintf_fFgGn" } } */
/* { dg-final { scan-assembler "call _snprintf_fFgGn" } } */
/* { dg-final { scan-assembler "call _vprintf_fFgGn" } } */
/* { dg-final { scan-assembler "call _vfprintf_fFgGn" } } */
/* { dg-final { scan-assembler "call _vsprintf_fFgGn" } } */
/* { dg-final { scan-assembler "call _vsnprintf_fFgGn" } } */

