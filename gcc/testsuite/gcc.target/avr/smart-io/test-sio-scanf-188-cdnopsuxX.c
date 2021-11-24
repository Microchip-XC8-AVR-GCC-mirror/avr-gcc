/*
  Test smart-io scanf variants : test-sio-scanf-188-cdnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %d,%s
#define SCANF_ARG &d,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_cdnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_cdnopsuxX" } } */

