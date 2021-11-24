/*
  Test smart-io printf variants : test-sio-printf-236-fFs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %f,%s
#define PRINT_ARG f,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_fFs" } } */
/* { dg-final { scan-assembler "call _fprintf_fFs" } } */
/* { dg-final { scan-assembler "call _sprintf_fFs" } } */
/* { dg-final { scan-assembler "call _snprintf_fFs" } } */
/* { dg-final { scan-assembler "call _vprintf_fFs" } } */
/* { dg-final { scan-assembler "call _vfprintf_fFs" } } */
/* { dg-final { scan-assembler "call _vsprintf_fFs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_fFs" } } */

