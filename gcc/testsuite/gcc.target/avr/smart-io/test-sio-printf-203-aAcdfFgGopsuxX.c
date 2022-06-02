/*
  Test smart-io printf variants : test-sio-printf-203-aAcdfFgGopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f,%g,%s,%x
#define PRINT_ARG a,f,g,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdfFgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdfFgGopsuxX" } } */

