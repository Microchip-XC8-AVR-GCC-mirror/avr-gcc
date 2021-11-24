/*
  Test smart-io scanf variants : test-sio-scanf-84-aAeEgGs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%e,%g,%s
#define SCANF_ARG &a,&e,&g,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _sscanf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _fscanf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _vscanf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAeEgGs" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAeEgGs" } } */

