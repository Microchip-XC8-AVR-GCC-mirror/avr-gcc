/*
  Test smart-io scanf variants : test-sio-scanf-221-cdeEnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%u,%x
#define SCANF_ARG &e,&u,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdeEnopuxX" } } */

