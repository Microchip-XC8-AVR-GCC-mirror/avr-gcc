/*
  Test smart-io printf variants : test-sio-printf-71-aAcdeEfFgGnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%f,%g,%x
#define PRINT_ARG a,e,f,g,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEfFgGnopuxX" } } */

