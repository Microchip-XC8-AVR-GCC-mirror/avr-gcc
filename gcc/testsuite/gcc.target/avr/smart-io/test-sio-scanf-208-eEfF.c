/*
  Test smart-io scanf variants : test-sio-scanf-208-eEfF.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%f
#define SCANF_ARG &e,&f

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_eEfF" } } */
/* { dg-final { scan-assembler "call _sscanf_eEfF" } } */
/* { dg-final { scan-assembler "call _fscanf_eEfF" } } */
/* { dg-final { scan-assembler "call _vscanf_eEfF" } } */
/* { dg-final { scan-assembler "call _vfscanf_eEfF" } } */
/* { dg-final { scan-assembler "call _vsscanf_eEfF" } } */

