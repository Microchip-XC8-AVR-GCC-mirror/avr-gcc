/*
  Test smart-io printf variants : test-sio-printf-70-aAcdfFgGnopuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%f,%g,%n,%u
#define PRINT_ARG a,d,f,g,n,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdfFgGnopuxX" } } */

