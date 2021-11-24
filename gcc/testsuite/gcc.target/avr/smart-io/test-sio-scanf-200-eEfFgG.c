/*
  Test smart-io scanf variants : test-sio-scanf-200-eEfFgG.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%f,%g
#define SCANF_ARG &e,&f,&g

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _sscanf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _fscanf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _vscanf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _vfscanf_eEfFgG" } } */
/* { dg-final { scan-assembler "call _vsscanf_eEfFgG" } } */

