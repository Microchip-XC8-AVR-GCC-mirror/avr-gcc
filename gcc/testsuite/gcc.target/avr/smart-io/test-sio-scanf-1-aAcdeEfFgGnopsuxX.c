/*
  Test smart-io scanf variants : test-sio-scanf-1-aAcdeEfFgGnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%d,%e,%f,%g,%s,%u,%x
#define SCANF_ARG &a,&d,&e,&f,&g,&s,&u,&x

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdeEfFgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdeEfFgGnopsuxX" } } */

