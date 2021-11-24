/*
  Test smart-io scanf variants : test-sio-scanf-93-aAcdeEnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%e,%u,%x
#define SCANF_ARG &a,&e,&u,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdeEnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdeEnopuxX" } } */

