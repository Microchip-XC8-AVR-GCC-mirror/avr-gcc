/*
  Test smart-io scanf variants : test-sio-scanf-240-fF.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %f
#define SCANF_ARG &f

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_fF" } } */
/* { dg-final { scan-assembler "call _sscanf_fF" } } */
/* { dg-final { scan-assembler "call _fscanf_fF" } } */
/* { dg-final { scan-assembler "call _vscanf_fF" } } */
/* { dg-final { scan-assembler "call _vfscanf_fF" } } */
/* { dg-final { scan-assembler "call _vsscanf_fF" } } */

