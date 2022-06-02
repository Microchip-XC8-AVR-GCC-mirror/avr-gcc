/*
  Test smart-io printf variants : test-sio-printf-232-aAgGn.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%g,%n
#define PRINT_ARG a,g,n

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAgGn" } } */
/* { dg-final { scan-assembler "call _fprintf_aAgGn" } } */
/* { dg-final { scan-assembler "call _sprintf_aAgGn" } } */
/* { dg-final { scan-assembler "call _snprintf_aAgGn" } } */
/* { dg-final { scan-assembler "call _vprintf_aAgGn" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAgGn" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAgGn" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAgGn" } } */

