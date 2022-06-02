/*
  Test smart-io printf variants : test-sio-printf-500-ns.c
  Invoke all variants of printf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  PRINT_FMT
#undef  PRINT_ARG

#define PRINT_FMT %n,%s
#define PRINT_ARG n,s

#include "test-template-printf.t"

/* { dg-final { scan-assembler "call _printf_ns" } } */
/* { dg-final { scan-assembler "call _fprintf_ns" } } */
/* { dg-final { scan-assembler "call _sprintf_ns" } } */
/* { dg-final { scan-assembler "call _snprintf_ns" } } */
/* { dg-final { scan-assembler "call _vprintf_ns" } } */
/* { dg-final { scan-assembler "call _vfprintf_ns" } } */
/* { dg-final { scan-assembler "call _vsprintf_ns" } } */
/* { dg-final { scan-assembler "call _vsnprintf_ns" } } */

