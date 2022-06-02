/*
  Test smart-io printf variants : test-sio-printf-192-aAeE.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e
#define PRINT_ARG a,e

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAeE" } } */
/* { dg-final { scan-assembler "call _fprintf_aAeE" } } */
/* { dg-final { scan-assembler "call _sprintf_aAeE" } } */
/* { dg-final { scan-assembler "call _snprintf_aAeE" } } */
/* { dg-final { scan-assembler "call _vprintf_aAeE" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAeE" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAeE" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAeE" } } */

