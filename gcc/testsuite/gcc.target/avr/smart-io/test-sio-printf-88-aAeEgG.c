/*
  Test smart-io printf variants : test-sio-printf-88-aAeEgG.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%g
#define PRINT_ARG a,e,g

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _fprintf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _sprintf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _snprintf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _vprintf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAeEgG" } } */

