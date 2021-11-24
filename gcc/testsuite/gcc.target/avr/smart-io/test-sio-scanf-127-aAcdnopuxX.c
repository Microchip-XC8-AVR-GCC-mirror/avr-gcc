/*
  Test smart-io scanf variants : test-sio-scanf-127-aAcdnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%x
#define SCANF_ARG &a,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdnopuxX" } } */

