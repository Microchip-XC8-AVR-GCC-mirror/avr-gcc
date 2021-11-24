/*
  Test smart-io scanf variants : test-sio-scanf-174-cdfFnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %d,%f,%u
#define SCANF_ARG &d,&f,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdfFnopuxX" } } */

