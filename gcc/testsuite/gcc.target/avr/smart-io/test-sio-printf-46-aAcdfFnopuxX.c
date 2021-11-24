/*
  Test smart-io printf variants : test-sio-printf-46-aAcdfFnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%f,%u
#define PRINT_ARG a,d,f,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdfFnopuxX" } } */

