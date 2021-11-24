/*
  Test smart-io printf variants : test-sio-printf-61-aAcdnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%u,%x
#define PRINT_ARG a,d,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdnopuxX" } } */

