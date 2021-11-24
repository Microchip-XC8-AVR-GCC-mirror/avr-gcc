/*
  Test smart-io scanf variants : test-sio-scanf-80-aAeEfF.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%e,%f
#define SCANF_ARG &a,&e,&f

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAeEfF" } } */
/* { dg-final { scan-assembler "call _sscanf_aAeEfF" } } */
/* { dg-final { scan-assembler "call _fscanf_aAeEfF" } } */
/* { dg-final { scan-assembler "call _vscanf_aAeEfF" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAeEfF" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAeEfF" } } */

