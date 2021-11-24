/*
  Test smart-io printf variants : test-sio-printf-28-aAcdeEnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%e,%s
#define PRINT_ARG a,d,e,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdeEnopsuxX" } } */

