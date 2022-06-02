/*
  Test smart-io printf variants : test-sio-printf-139-aAcdeEfFgGopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%f,%g,%s,%x
#define PRINT_ARG a,e,f,g,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEfFgGopsuxX" } } */

