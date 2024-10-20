/*
  Test smart-io printf variants : test-sio-printf-153-aAcdeEfFopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%f,%s,%u,%x
#define PRINT_ARG a,e,f,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEfFopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEfFopsuxX" } } */

