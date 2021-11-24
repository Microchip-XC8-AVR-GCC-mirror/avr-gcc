/*
  Test smart-io printf variants : test-sio-printf-51-aAcdgGnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%g,%s,%x
#define PRINT_ARG a,d,g,s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdgGnopsuxX" } } */

