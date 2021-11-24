/*
  Test smart-io scanf variants : test-sio-scanf-121-aAcdnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%s,%u,%x
#define SCANF_ARG &a,&s,&u,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdnopsuxX" } } */

