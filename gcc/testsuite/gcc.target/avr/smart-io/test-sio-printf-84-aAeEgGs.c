/*
  Test smart-io printf variants : test-sio-printf-84-aAeEgGs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%g,%s
#define PRINT_ARG a,e,g,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _fprintf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _sprintf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _snprintf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _vprintf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAeEgGs" } } */

