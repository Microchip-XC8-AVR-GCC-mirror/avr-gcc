/*
  Test smart-io printf variants : test-sio-printf-68-aAeEfFgGs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%f,%g,%s
#define PRINT_ARG a,e,f,g,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAeEfFgGs" } } */
/* { dg-final { scan-assembler "call _fprintf_aAeEfFgGs" } } */
/* { dg-final { scan-assembler "call _sprintf_aAeEfFgGs" } } */
/* { dg-final { scan-assembler "call _snprintf_aAeEfFgGs" } } */
/* { dg-final { scan-assembler "call _vprintf_aAeEfFgGs" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAeEfFgGs" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAeEfFgGs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAeEfFgGs" } } */

