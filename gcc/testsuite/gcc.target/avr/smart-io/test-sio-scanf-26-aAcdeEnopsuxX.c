/*
  Test smart-io scanf variants : test-sio-scanf-26-aAcdeEnopsuxX.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%d,%e,%s,%u
#define SCANF_ARG &a,&d,&e,&s,&u

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _sscanf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _fscanf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vscanf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAcdeEnopsuxX" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAcdeEnopsuxX" } } */

