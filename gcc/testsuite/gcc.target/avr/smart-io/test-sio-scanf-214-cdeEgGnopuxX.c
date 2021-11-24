/*
  Test smart-io scanf variants : test-sio-scanf-214-cdeEgGnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%g,%u
#define SCANF_ARG &e,&g,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdeEgGnopuxX" } } */

