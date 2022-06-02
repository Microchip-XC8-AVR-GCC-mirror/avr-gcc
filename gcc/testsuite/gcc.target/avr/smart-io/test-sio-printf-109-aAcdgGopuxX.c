/*
  Test smart-io printf variants : test-sio-printf-109-aAcdgGopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%g,%u,%x
#define PRINT_ARG a,d,g,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdgGopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdgGopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdgGopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdgGopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdgGopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdgGopuxX" } } */

