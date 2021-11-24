/*
  Test smart-io scanf variants : test-sio-scanf-88-aAeEgG.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%e,%g
#define SCANF_ARG &a,&e,&g

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _sscanf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _fscanf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _vscanf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAeEgG" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAeEgG" } } */

