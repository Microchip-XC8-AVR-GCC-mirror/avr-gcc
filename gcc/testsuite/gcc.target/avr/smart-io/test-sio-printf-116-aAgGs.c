/*
  Test smart-io printf variants : test-sio-printf-116-aAgGs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%g,%s
#define PRINT_ARG a,g,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAgGs" } } */
/* { dg-final { scan-assembler "call _fprintf_aAgGs" } } */
/* { dg-final { scan-assembler "call _sprintf_aAgGs" } } */
/* { dg-final { scan-assembler "call _snprintf_aAgGs" } } */
/* { dg-final { scan-assembler "call _vprintf_aAgGs" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAgGs" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAgGs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAgGs" } } */

