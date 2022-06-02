/* Verify that nopafunc attribute is handled and its diagnostics.
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */


short __attribute__((nopa)) var1; /* { dg-warning "'nopa' attribute only applies to function types" } */

void __attribute__((nopa)) foo(void) {}
void bar(void) {}
void __attribute__((nopa, signal)) __vector_2(void) {}
void __attribute__((nopa, handler(3))) baz(void) {}

void xxx(void) __asm__("xxx");
void __attribute__((nopa)) xxx(void) {}

/* { dg-final { scan-assembler ".global\tfoo" } } */
/* { dg-final { scan-assembler "\t.type\tfoo, @function" } } */
/* { dg-final { scan-assembler "\t.nopafunc\tfoo" } } */
/* { dg-final { scan-assembler "foo:" } } */

/* { dg-final { scan-assembler ".global\tbar" } } */
/* { dg-final { scan-assembler "\t.type\tbar, @function" } } */
/* { dg-final { scan-assembler "bar:" } } */

/* { dg-final { scan-assembler ".global\t__vector_2" } } */
/* { dg-final { scan-assembler "\t.type\t__vector_2, @function" } } */
/* { dg-final { scan-assembler "\t.nopafunc\t__vector_2" } } */
/* { dg-final { scan-assembler "__vector_2:" } } */

/* { dg-final { scan-assembler ".global\tbaz" } } */
/* { dg-final { scan-assembler "\t.type\tbaz, @function" } } */
/* { dg-final { scan-assembler "\t.nopafunc\tbaz" } } */
/* { dg-final { scan-assembler ".global\t__vector_3" } } */
/* { dg-final { scan-assembler "\t.type\t__vector_3, @function" } } */
/* { dg-final { scan-assembler "\t.nopafunc\t__vector_3" } } */
/* { dg-final { scan-assembler "__vector_3:" } } */
/* { dg-final { scan-assembler "baz:" } } */
/* { dg-final { scan-assembler ".global\txxx" } } */
/* { dg-final { scan-assembler "\t.type\txxx, @function" } } */
/* { dg-final { scan-assembler-not "\t.nopafunc\t\\*xxx" } } */
/* { dg-final { scan-assembler "\t.nopafunc\txxx" } } */
