/*
  Test smart-io printf variants : test-sio-printf-86-aAcdeEgGnopuxX.c
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

/* { dg-final { scan-assembler "call _printf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEgGnopuxX" } } */

