/*
  Test smart-io printf variants : test-sio-printf-152-aAeEfFn.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%f,%n
#define PRINT_ARG a,e,f,n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAeEfFn" } } */
/* { dg-final { scan-assembler "call _fprintf_aAeEfFn" } } */
/* { dg-final { scan-assembler "call _sprintf_aAeEfFn" } } */
/* { dg-final { scan-assembler "call _snprintf_aAeEfFn" } } */
/* { dg-final { scan-assembler "call _vprintf_aAeEfFn" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAeEfFn" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAeEfFn" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAeEfFn" } } */

