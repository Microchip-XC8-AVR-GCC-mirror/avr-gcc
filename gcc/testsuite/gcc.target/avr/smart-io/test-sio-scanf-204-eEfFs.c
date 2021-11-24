/*
  Test smart-io scanf variants : test-sio-scanf-204-eEfFs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %e,%f,%s
#define SCANF_ARG &e,&f,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_eEfFs" } } */
/* { dg-final { scan-assembler "call _sscanf_eEfFs" } } */
/* { dg-final { scan-assembler "call _fscanf_eEfFs" } } */
/* { dg-final { scan-assembler "call _vscanf_eEfFs" } } */
/* { dg-final { scan-assembler "call _vfscanf_eEfFs" } } */
/* { dg-final { scan-assembler "call _vsscanf_eEfFs" } } */

