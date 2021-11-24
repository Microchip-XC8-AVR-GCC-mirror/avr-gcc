/*
  Test smart-io scanf variants : test-sio-scanf-212-eEgGs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%g,%s
#define SCANF_ARG &e,&g,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_eEgGs" } } */
/* { dg-final { scan-assembler "call _sscanf_eEgGs" } } */
/* { dg-final { scan-assembler "call _fscanf_eEgGs" } } */
/* { dg-final { scan-assembler "call _vscanf_eEgGs" } } */
/* { dg-final { scan-assembler "call _vfscanf_eEgGs" } } */
/* { dg-final { scan-assembler "call _vsscanf_eEgGs" } } */

