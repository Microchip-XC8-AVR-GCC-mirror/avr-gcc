/*
  Test smart-io scanf variants : test-sio-scanf-124-aAs.c
  Invoke all variants of scanf and check
  for compilation or link errors.
*/

/* { dg-do compile } */
/* { dg-options "-msmart-io" } */

#include "sio_test.h"

#undef  SCANF_FMT
#undef  SCANF_ARG

#define SCANF_FMT %a,%s
#define SCANF_ARG &a,&s

#include "test-template-scanf.t"

/* { dg-final { scan-assembler "call _scanf_aAs" } } */
/* { dg-final { scan-assembler "call _sscanf_aAs" } } */
/* { dg-final { scan-assembler "call _fscanf_aAs" } } */
/* { dg-final { scan-assembler "call _vscanf_aAs" } } */
/* { dg-final { scan-assembler "call _vfscanf_aAs" } } */
/* { dg-final { scan-assembler "call _vsscanf_aAs" } } */

