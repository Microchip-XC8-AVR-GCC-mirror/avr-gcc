/* Verify that paoutlinecallsinfunc directive is generated only when appropriate
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

struct S {
  long m1;
  long m2;
  long m3;
	long m4;
	long m5;
	long m6;
};

extern void vararg (int x, ...);
extern void more_arg_than_arg_reg (struct S s);
extern void normalfunc(int x, int y);

void func_canpa_call(void) {
  normalfunc(20, 30);
}

/* { dg-final { scan-assembler "\t.paoutlinecallsinfunc\tfunc_canpa_call" } } */
/* { dg-final { scan-assembler "func_canpa_call:" } } */

/* Args to a variadic function are passed via stack, so cannot outline such a call. */
void func_vararg_caller(void) {
  vararg(20, 30);
}

/* { dg-final { scan-assembler-not "\t.paoutlinecallsinfunc\tfunc_vararg_caller" } } */
/* { dg-final { scan-assembler "func_vararg_caller:" } } */

/* Args in excess of args regs are passed via stack, so cannot outline such a call. */
void func_more_args_than_arg_reg_caller(void) {
  struct S s;
  more_arg_than_arg_reg (s);
}

/* { dg-final { scan-assembler-not "\t.paoutlinecallsinfunc\tfunc_more_args_than_arg_reg_caller" } } */
/* { dg-final { scan-assembler "func_more_args_than_arg_reg_caller:" } } */

/* Current implementation ties outlinability of CALLs to the caller, not callee. A single
	 non-outlinable CALL prevents the directive from appearing in the caller. Future impl
	 could make it per CALL, change test then. */
void func_normal_with_variadic(void) {
  normalfunc(20, 30);
  vararg(20, 30);
}

/* { dg-final { scan-assembler-not "\t.paoutlinecallsinfunc\tfunc_normal_with_variadic" } } */
/* { dg-final { scan-assembler "func_normal_with_variadic:" } } */

void __attribute__((signal)) __vector_2(void) {
  normalfunc(20, 30);
}

/* { dg-final { scan-assembler "\t.paoutlinecallsinfunc\t__vector_2" } } */
/* { dg-final { scan-assembler "__vector_2:" } } */

void __attribute__((signal)) __vector_3(void) {
  vararg(20, 30);
}

/* { dg-final { scan-assembler-not "\t.paoutlinecallsinfunc\t__vector_3" } } */
/* { dg-final { scan-assembler "__vector_3:" } } */

void __attribute__((handler(4))) baz(void) {
  normalfunc(20, 30);
}

/* { dg-final { scan-assembler "\t.paoutlinecallsinfunc\tbaz" } } */
/* { dg-final { scan-assembler "\t.paoutlinecallsinfunc\t__vector_4" } } */
/* { dg-final { scan-assembler "__vector_4:" } } */

void __attribute__((handler(5))) bad(void) {
  vararg(20, 30);
}

/* { dg-final { scan-assembler-not "\t.paoutlinecallsinfunc\tbad" } } */
/* { dg-final { scan-assembler-not "\t.paoutlinecallsinfunc\t__vector_5" } } */
/* { dg-final { scan-assembler "__vector_5:" } } */
