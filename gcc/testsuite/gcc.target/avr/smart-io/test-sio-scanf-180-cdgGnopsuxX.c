/*
  Test smart-io scanf variants : test-sio-scanf-180-cdgGnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %d,%g,%s
#define SCANF_ARG &d,&g,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdgGnopsuxX" } } */

