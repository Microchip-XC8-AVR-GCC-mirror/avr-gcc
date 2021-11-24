/*
  Test smart-io scanf variants : test-sio-scanf-153-cdeEnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %d,%e,%s,%u,%x
#define SCANF_ARG &d,&e,&s,&u,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdeEnopsuxX" } } */

