/*
  Test smart-io scanf variants : test-sio-scanf-228-fFgGs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %f,%g,%s
#define SCANF_ARG &f,&g,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_fFgGs" } } */
/* { dg-final { scan-assembler "call _sscanf_fFgGs" } } */
/* { dg-final { scan-assembler "call _fscanf_fFgGs" } } */
/* { dg-final { scan-assembler "call _vscanf_fFgGs" } } */
/* { dg-final { scan-assembler "call _vfscanf_fFgGs" } } */
/* { dg-final { scan-assembler "call _vsscanf_fFgGs" } } */

