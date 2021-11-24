/*
  Test smart-io scanf variants : test-sio-scanf-232-fFgG.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %f,%g
#define SCANF_ARG &f,&g

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_fFgG" } } */
/* { dg-final { scan-assembler "call _sscanf_fFgG" } } */
/* { dg-final { scan-assembler "call _fscanf_fFgG" } } */
/* { dg-final { scan-assembler "call _vscanf_fFgG" } } */
/* { dg-final { scan-assembler "call _vfscanf_fFgG" } } */
/* { dg-final { scan-assembler "call _vsscanf_fFgG" } } */

