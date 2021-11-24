/*
  Test smart-io printf variants : test-sio-printf-33-aAcdfFgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%f,%g,%s,%u,%x
#define PRINT_ARG a,d,f,g,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdfFgGnopsuxX" } } */

