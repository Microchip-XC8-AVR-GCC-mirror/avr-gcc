/*
  Test smart-io scanf variants : test-sio-scanf-54-aAcdgGnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%d,%g,%u
#define SCANF_ARG &a,&d,&g,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdgGnopuxX" } } */

