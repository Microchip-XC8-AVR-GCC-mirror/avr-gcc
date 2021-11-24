/*
  Test smart-io scanf variants : test-sio-scanf-133-cdeEfFgGnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %d,%e,%f,%g,%u,%x
#define SCANF_ARG &d,&e,&f,&g,&u,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdeEfFgGnopuxX" } } */

