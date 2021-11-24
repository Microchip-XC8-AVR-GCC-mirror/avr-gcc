/*
  Test smart-io scanf variants : test-sio-scanf-72-aAeEfFgG.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%e,%f,%g
#define SCANF_ARG &a,&e,&f,&g

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAeEfFgG" } } */
/* { dg-final { scan-assembler "call _sscanf_aAeEfFgG" } } */
/* { dg-final { scan-assembler "call _fscanf_aAeEfFgG" } } */
/* { dg-final { scan-assembler "call _vscanf_aAeEfFgG" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAeEfFgG" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAeEfFgG" } } */

