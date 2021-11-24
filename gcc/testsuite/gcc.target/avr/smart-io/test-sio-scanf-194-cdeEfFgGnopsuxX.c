/*
  Test smart-io scanf variants : test-sio-scanf-194-cdeEfFgGnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%f,%g,%s,%u
#define SCANF_ARG &e,&f,&g,&s,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdeEfFgGnopsuxX" } } */

