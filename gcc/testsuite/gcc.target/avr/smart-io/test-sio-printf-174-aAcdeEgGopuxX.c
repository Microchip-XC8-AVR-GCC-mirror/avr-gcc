/*
  Test smart-io printf variants : test-sio-printf-174-aAcdeEgGopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%g,%u
#define PRINT_ARG a,e,g,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEgGopuxX" } } */

