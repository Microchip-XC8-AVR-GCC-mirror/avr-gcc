/*
  Test smart-io scanf variants : test-sio-scanf-218-cdeEnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%s,%u
#define SCANF_ARG &e,&s,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdeEnopsuxX" } } */

