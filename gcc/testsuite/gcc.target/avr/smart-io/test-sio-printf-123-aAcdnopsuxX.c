/*
  Test smart-io printf variants : test-sio-printf-123-aAcdnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%s,%x
#define PRINT_ARG a,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdnopsuxX" } } */

