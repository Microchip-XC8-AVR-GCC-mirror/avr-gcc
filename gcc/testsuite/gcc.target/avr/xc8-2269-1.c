/* Verify that user defined section has data attribute irrespective of
   the initialisers for variables. */
/* { dg-do compile } */
/* { dg-options "" } */

volatile int noinit_d1 __attribute__((section("noinit_vars")));
volatile int init_d1 = 12;
volatile char noinit_d2[4] __attribute__((section("noinit_vars")));
int main ()
{
  return noinit_d1 + noinit_d2[3] + init_d1;
}

/* { dg-final { scan-assembler ".global\tnoinit_d1\[\n\r\]+\t.section\tnoinit_vars,data\[\n\r\]+\t.type\tnoinit_d1, @object" } } */
/* { dg-final { scan-assembler ".global\tnoinit_d2\[\n\r\]+\t.section\tnoinit_vars,data\[\n\r\]+\t.type\tnoinit_d2, @object" } } */

/* { dg-final { scan-assembler "\t.section\t.data,data\[\n\r\]+\t.type\tinit_d1, @object" } } */
