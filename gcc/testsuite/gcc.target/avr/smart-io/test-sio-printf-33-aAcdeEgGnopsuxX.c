/*
  Test smart-io printf variants : test-sio-printf-33-aAcdeEgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%e,%g,%n,%s,%u,%x
#define PRINT_ARG a,d,e,g,n,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEgGnopsuxX" } } */

