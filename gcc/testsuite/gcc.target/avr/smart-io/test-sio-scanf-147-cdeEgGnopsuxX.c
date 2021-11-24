/*
  Test smart-io scanf variants : test-sio-scanf-147-cdeEgGnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %d,%e,%g,%s,%x
#define SCANF_ARG &d,&e,&g,&s,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdeEgGnopsuxX" } } */

