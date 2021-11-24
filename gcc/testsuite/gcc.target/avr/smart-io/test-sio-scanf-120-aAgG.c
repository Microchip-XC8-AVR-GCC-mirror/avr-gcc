/*
  Test smart-io scanf variants : test-sio-scanf-120-aAgG.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%g
#define SCANF_ARG &a,&g

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAgG" } } */
/* { dg-final { scan-assembler "call _sscanf_aAgG" } } */
/* { dg-final { scan-assembler "call _fscanf_aAgG" } } */
/* { dg-final { scan-assembler "call _vscanf_aAgG" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAgG" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAgG" } } */

