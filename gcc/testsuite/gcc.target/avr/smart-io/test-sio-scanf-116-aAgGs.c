/*
  Test smart-io scanf variants : test-sio-scanf-116-aAgGs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%g,%s
#define SCANF_ARG &a,&g,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAgGs" } } */
/* { dg-final { scan-assembler "call _sscanf_aAgGs" } } */
/* { dg-final { scan-assembler "call _fscanf_aAgGs" } } */
/* { dg-final { scan-assembler "call _vscanf_aAgGs" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAgGs" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAgGs" } } */

