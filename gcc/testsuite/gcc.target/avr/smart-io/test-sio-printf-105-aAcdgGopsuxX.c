/*
  Test smart-io printf variants : test-sio-printf-105-aAcdgGopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%d,%g,%s,%u,%x
#define PRINT_ARG a,d,g,s,u,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAcdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_aAcdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_aAcdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_aAcdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_aAcdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAcdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAcdgGopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAcdgGopsuxX" } } */

