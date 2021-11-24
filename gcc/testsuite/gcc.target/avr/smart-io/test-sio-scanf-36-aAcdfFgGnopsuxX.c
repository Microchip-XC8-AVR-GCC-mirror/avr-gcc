/*
  Test smart-io scanf variants : test-sio-scanf-36-aAcdfFgGnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%d,%f,%g,%s
#define SCANF_ARG &a,&d,&f,&g,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdfFgGnopsuxX" } } */

