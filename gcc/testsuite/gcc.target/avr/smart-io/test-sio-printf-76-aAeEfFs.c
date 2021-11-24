/*
  Test smart-io printf variants : test-sio-printf-76-aAeEfFs.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%e,%f,%s
#define PRINT_ARG a,e,f,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _fprintf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _sprintf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _snprintf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _vprintf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAeEfFs" } } */

