/*
  Test smart-io scanf variants : test-sio-scanf-207-cdeEfFnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%f,%x
#define SCANF_ARG &e,&f,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdeEfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdeEfFnopuxX" } } */

