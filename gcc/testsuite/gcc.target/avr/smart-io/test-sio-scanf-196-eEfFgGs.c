/*
  Test smart-io scanf variants : test-sio-scanf-196-eEfFgGs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%f,%g,%s
#define SCANF_ARG &e,&f,&g,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _sscanf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _fscanf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _vscanf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _vfscanf_eEfFgGs" } } */
/* { dg-final { scan-assembler "call _vsscanf_eEfFgGs" } } */

