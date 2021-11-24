/*
  Test smart-io scanf variants : test-sio-scanf-103-aAcdfFgGnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%f,%g,%x
#define SCANF_ARG &a,&f,&g,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdfFgGnopuxX" } } */

