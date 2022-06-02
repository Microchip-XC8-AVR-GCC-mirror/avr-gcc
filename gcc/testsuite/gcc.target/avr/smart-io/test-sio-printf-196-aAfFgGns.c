/*
  Test smart-io printf variants : test-sio-printf-196-aAfFgGns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %a,%f,%g,%n,%s
#define PRINT_ARG a,f,g,n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_aAfFgGns" } } */
/* { dg-final { scan-assembler "call _fprintf_aAfFgGns" } } */
/* { dg-final { scan-assembler "call _sprintf_aAfFgGns" } } */
/* { dg-final { scan-assembler "call _snprintf_aAfFgGns" } } */
/* { dg-final { scan-assembler "call _vprintf_aAfFgGns" } } */
/* { dg-final { scan-assembler "call _vfprintf_aAfFgGns" } } */
/* { dg-final { scan-assembler "call _vsprintf_aAfFgGns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_aAfFgGns" } } */

