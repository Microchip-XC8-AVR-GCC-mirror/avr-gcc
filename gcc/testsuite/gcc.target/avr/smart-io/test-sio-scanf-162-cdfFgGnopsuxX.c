/*
  Test smart-io scanf variants : test-sio-scanf-162-cdfFgGnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %d,%f,%g,%s,%u
#define SCANF_ARG &d,&f,&g,&s,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdfFgGnopsuxX" } } */

