/* Verify that paoutlinecallsinfunc directive is not generated if -mno-pa-outline-calls
/* { dg-do compile } */
/* { dg-options "-mno-pa-outline-calls" } */

extern void normalfunc(int x, int y);

void func_canpa_call(void) {
  normalfunc(20, 30);
}

/* { dg-final { scan-assembler-not "\t.paoutlinecallsinfunc\tfunc_canpa_call" } } */
/* { dg-final { scan-assembler "func_canpa_call:" } } */
