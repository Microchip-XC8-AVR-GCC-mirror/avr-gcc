/*
  Test smart-io printf variants : test-sio-printf-248-aAn.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%n
#define PRINT_ARG a,n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAn" } } */
/* { dg-final { scan-assembler "call _fprintf_aAn" } } */
/* { dg-final { scan-assembler "call _sprintf_aAn" } } */
/* { dg-final { scan-assembler "call _snprintf_aAn" } } */
/* { dg-final { scan-assembler "call _vprintf_aAn" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAn" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAn" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAn" } } */

