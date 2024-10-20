/*
  Test smart-io printf variants : test-sio-printf-240-aAgG.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%g
#define PRINT_ARG a,g

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAgG" } } */
/* { dg-final { scan-assembler "call _fprintf_aAgG" } } */
/* { dg-final { scan-assembler "call _sprintf_aAgG" } } */
/* { dg-final { scan-assembler "call _snprintf_aAgG" } } */
/* { dg-final { scan-assembler "call _vprintf_aAgG" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAgG" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAgG" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAgG" } } */

