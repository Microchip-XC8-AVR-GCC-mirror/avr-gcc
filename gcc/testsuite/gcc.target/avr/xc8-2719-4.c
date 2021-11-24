/* How the smart-io variants are output */
/* { dg-do compile } */
/* { dg-options "-msmart-io -msmart-io-format=%f" } */

#include "xc8-2719-3.c"

/* { dg-final { scan-assembler-times "call _printf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _fprintf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _sprintf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _snprintf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _vprintf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _vfprintf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _vsprintf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _vsnprintf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _scanf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _fscanf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _sscanf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _vscanf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _vfscanf_cdfFnopuxX"  4 } } */
/* { dg-final { scan-assembler-times "call _vsscanf_cdfFnopuxX"  4 } } */
