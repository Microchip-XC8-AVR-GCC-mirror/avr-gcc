/*
  Test smart-io printf variants : test-sio-printf-231-aAcdgGnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%g,%n,%x
#define PRINT_ARG a,g,n,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdgGnopuxX" } } */

