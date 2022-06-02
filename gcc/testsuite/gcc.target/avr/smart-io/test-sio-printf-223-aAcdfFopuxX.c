/*
  Test smart-io printf variants : test-sio-printf-223-aAcdfFopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f,%x
#define PRINT_ARG a,f,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdfFopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdfFopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdfFopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdfFopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdfFopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdfFopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdfFopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdfFopuxX" } } */

