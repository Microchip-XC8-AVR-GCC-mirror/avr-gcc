/*
  Test smart-io scanf variants : test-sio-scanf-110-aAcdfFnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%f,%u
#define SCANF_ARG &a,&f,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdfFnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdfFnopuxX" } } */

