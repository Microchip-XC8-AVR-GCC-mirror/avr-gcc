/*
  Test smart-io scanf variants : test-sio-scanf-224-eE.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e
#define SCANF_ARG &e

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_eE" } } */
/* { dg-final { scan-assembler "call _sscanf_eE" } } */
/* { dg-final { scan-assembler "call _fscanf_eE" } } */
/* { dg-final { scan-assembler "call _vscanf_eE" } } */
/* { dg-final { scan-assembler "call _vfscanf_eE" } } */
/* { dg-final { scan-assembler "call _vsscanf_eE" } } */

