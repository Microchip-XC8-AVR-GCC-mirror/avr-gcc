/*
  Test smart-io scanf variants : test-sio-scanf-244-gGs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %g,%s
#define SCANF_ARG &g,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_gGs" } } */
/* { dg-final { scan-assembler "call _sscanf_gGs" } } */
/* { dg-final { scan-assembler "call _fscanf_gGs" } } */
/* { dg-final { scan-assembler "call _vscanf_gGs" } } */
/* { dg-final { scan-assembler "call _vfscanf_gGs" } } */
/* { dg-final { scan-assembler "call _vsscanf_gGs" } } */

