/*
  Test smart-io scanf variants : test-sio-scanf-112-aAfF.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%f
#define SCANF_ARG &a,&f

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAfF" } } */
/* { dg-final { scan-assembler "call _sscanf_aAfF" } } */
/* { dg-final { scan-assembler "call _fscanf_aAfF" } } */
/* { dg-final { scan-assembler "call _vscanf_aAfF" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAfF" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAfF" } } */

