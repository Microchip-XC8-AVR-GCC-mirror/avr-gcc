/*
  Test smart-io printf variants : test-sio-printf-132-aAeEfFgGns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%f,%g,%n,%s
#define PRINT_ARG a,e,f,g,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAeEfFgGns" } } */
/* { dg-final { scan-assembler "call _fprintf_aAeEfFgGns" } } */
/* { dg-final { scan-assembler "call _sprintf_aAeEfFgGns" } } */
/* { dg-final { scan-assembler "call _snprintf_aAeEfFgGns" } } */
/* { dg-final { scan-assembler "call _vprintf_aAeEfFgGns" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAeEfFgGns" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAeEfFgGns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAeEfFgGns" } } */

