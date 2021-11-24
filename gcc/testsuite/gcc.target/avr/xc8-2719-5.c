/* How the smart-io variants are output */
/* { dg-do compile } */
/* { dg-options "-msmart-io -msmart-io-format=%f" } */

#include "xc8-2719-2.c"

/* { dg-final { scan-assembler-times "call _printf_cdfFnopuxX"  6 } } */
/* { dg-final { scan-assembler-times "call _vprintf_cdfFnopuxX"  6 } } */
/* { dg-final { scan-assembler-times "call _scanf_cdfFnopuxX"  6 } } */
/* { dg-final { scan-assembler-times "call _vsscanf_cdfFnopuxX"  6 } } */
