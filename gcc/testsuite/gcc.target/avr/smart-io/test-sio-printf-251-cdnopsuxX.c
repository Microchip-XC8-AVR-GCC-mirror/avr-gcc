/*
  Test smart-io printf variants : test-sio-printf-251-cdnopsuxX.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %s,%x
#define PRINT_ARG s,x

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _fprintf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _sprintf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _snprintf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vprintf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfprintf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsprintf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsnprintf_cdnopsuxX" } } */

