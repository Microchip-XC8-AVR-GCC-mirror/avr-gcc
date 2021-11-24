/*
  Test smart-io printf variants : test-sio-printf-3-aAcdeEfFgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%e,%f,%g,%s,%x
#define PRINT_ARG a,d,e,f,g,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEfFgGnopsuxX" } } */

