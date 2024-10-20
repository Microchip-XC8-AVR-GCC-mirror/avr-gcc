/*
  Test smart-io printf variants : test-sio-printf-17-aAcdeEfFnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%e,%f,%n,%s,%u,%x
#define PRINT_ARG a,d,e,f,n,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEfFnopsuxX" } } */

