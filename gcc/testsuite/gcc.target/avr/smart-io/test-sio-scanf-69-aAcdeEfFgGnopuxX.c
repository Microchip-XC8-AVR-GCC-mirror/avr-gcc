/*
  Test smart-io scanf variants : test-sio-scanf-69-aAcdeEfFgGnopuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%e,%f,%g,%u,%x
#define SCANF_ARG &a,&e,&f,&g,&u,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdeEfFgGnopuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdeEfFgGnopuxX" } } */

