/*
  Test smart-io scanf variants : test-sio-scanf-252-s.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %s
#define SCANF_ARG &s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_s" } } */
/* { dg-final { scan-assembler "call _sscanf_s" } } */
/* { dg-final { scan-assembler "call _fscanf_s" } } */
/* { dg-final { scan-assembler "call _vscanf_s" } } */
/* { dg-final { scan-assembler "call _vfscanf_s" } } */
/* { dg-final { scan-assembler "call _vsscanf_s" } } */

