/*
  Test smart-io scanf variants : test-sio-scanf-108-aAfFs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%f,%s
#define SCANF_ARG &a,&f,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAfFs" } } */
/* { dg-final { scan-assembler "call _sscanf_aAfFs" } } */
/* { dg-final { scan-assembler "call _fscanf_aAfFs" } } */
/* { dg-final { scan-assembler "call _vscanf_aAfFs" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAfFs" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAfFs" } } */

