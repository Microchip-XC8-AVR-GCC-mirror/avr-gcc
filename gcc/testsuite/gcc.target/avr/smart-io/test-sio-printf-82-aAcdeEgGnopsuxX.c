/*
  Test smart-io printf variants : test-sio-printf-82-aAcdeEgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%g,%s,%u
#define PRINT_ARG a,e,g,s,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEgGnopsuxX" } } */

