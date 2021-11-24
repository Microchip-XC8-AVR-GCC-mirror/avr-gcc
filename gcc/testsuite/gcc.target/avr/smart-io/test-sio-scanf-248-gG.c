/*
  Test smart-io scanf variants : test-sio-scanf-248-gG.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %g
#define SCANF_ARG &g

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_gG" } } */
/* { dg-final { scan-assembler "call _sscanf_gG" } } */
/* { dg-final { scan-assembler "call _fscanf_gG" } } */
/* { dg-final { scan-assembler "call _vscanf_gG" } } */
/* { dg-final { scan-assembler "call _vfscanf_gG" } } */
/* { dg-final { scan-assembler "call _vsscanf_gG" } } */

