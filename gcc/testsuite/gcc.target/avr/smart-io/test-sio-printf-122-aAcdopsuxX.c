/*
  Test smart-io printf variants : test-sio-printf-122-aAcdopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%s,%u
#define PRINT_ARG a,d,s,u

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdopsuxX" } } */

