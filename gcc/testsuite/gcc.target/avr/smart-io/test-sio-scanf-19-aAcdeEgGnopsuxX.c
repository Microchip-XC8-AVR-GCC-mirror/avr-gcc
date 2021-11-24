/*
  Test smart-io scanf variants : test-sio-scanf-19-aAcdeEgGnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%d,%e,%g,%s,%x
#define SCANF_ARG &a,&d,&e,&g,&s,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdeEgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdeEgGnopsuxX" } } */

