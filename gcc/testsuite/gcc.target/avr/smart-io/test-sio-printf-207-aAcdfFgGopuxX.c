/*
  Test smart-io printf variants : test-sio-printf-207-aAcdfFgGopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f,%g,%x
#define PRINT_ARG a,f,g,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdfFgGopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdfFgGopuxX" } } */

