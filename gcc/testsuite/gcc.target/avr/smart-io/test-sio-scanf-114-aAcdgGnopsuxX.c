/*
  Test smart-io scanf variants : test-sio-scanf-114-aAcdgGnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%g,%s,%u
#define SCANF_ARG &a,&g,&s,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdgGnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdgGnopsuxX" } } */

