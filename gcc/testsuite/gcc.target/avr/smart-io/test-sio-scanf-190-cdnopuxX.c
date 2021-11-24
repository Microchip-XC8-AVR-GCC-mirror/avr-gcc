/*
  Test smart-io scanf variants : test-sio-scanf-190-cdnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %d,%u
#define SCANF_ARG &d,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdnopuxX" } } */

