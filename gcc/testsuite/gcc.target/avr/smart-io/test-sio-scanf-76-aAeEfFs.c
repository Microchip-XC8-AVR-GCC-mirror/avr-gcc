/*
  Test smart-io scanf variants : test-sio-scanf-76-aAeEfFs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%e,%f,%s
#define SCANF_ARG &a,&e,&f,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _sscanf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _fscanf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _vscanf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAeEfFs" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAeEfFs" } } */

