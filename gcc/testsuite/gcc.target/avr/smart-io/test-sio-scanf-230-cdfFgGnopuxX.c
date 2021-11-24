/*
  Test smart-io scanf variants : test-sio-scanf-230-cdfFgGnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %f,%g,%u
#define SCANF_ARG &f,&g,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdfFgGnopuxX" } } */

