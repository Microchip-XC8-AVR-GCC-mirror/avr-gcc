/*
  Test smart-io printf variants : test-sio-printf-211-aAcdfFnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f,%n,%s,%x
#define PRINT_ARG a,f,n,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdfFnopsuxX" } } */

