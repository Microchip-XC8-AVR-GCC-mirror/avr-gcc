/*
  Test smart-io scanf variants : test-sio-scanf-128-aA.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a
#define SCANF_ARG &a

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aA" } } */
/* { dg-final { scan-assembler "call _sscanf_aA" } } */
/* { dg-final { scan-assembler "call _fscanf_aA" } } */
/* { dg-final { scan-assembler "call _vscanf_aA" } } */
/* { dg-final { scan-assembler "call _vfscanf_aA" } } */
/* { dg-final { scan-assembler "call _vsscanf_aA" } } */

