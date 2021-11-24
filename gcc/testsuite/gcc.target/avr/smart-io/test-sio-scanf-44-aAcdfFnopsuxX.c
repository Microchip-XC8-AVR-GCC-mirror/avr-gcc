/*
  Test smart-io scanf variants : test-sio-scanf-44-aAcdfFnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%d,%f,%s
#define SCANF_ARG &a,&d,&f,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdfFnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdfFnopsuxX" } } */

