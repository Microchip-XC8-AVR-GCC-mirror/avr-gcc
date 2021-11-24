/*
  Test smart-io scanf variants : test-sio-scanf-87-aAcdeEgGnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%e,%g,%x
#define SCANF_ARG &a,&e,&g,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdeEgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdeEgGnopuxX" } } */

