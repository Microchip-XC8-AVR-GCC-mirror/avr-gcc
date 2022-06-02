/*
  Test smart-io printf variants : test-sio-printf-13-aAcdeEfFgGopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%e,%f,%g,%u,%x
#define PRINT_ARG a,d,e,f,g,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEfFgGopuxX" } } */

