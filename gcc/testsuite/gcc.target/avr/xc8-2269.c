/* Verify that user defined section has data attribute irrespective of
   the initialisers for variables.[xc8-2269] */
/* { dg-do compile } */
/* { dg-options "" } */

volatile int bar __attribute__((section(".blah")));
volatile int foo __attribute__((section(".blah")))  = 0x1234;

volatile int bar1 __attribute__((section(".blahblah")));
volatile int foo1 __attribute__((section(".blahblah")))  = 0x0;

int main() {
  return bar + foo;
}

/* { dg-final { scan-assembler "\t.section\t.blah,data\[\n\r\]+\t.type\tbar, @object" } } */
/* { dg-final { scan-assembler ".global\tfoo\[\n\r\]+\t.type\tfoo, @object" } } */

/* { dg-final { scan-assembler "\t.section\t.blahblah,data\[\n\r\]+\t.type\tbar1, @object" } } */
/* { dg-final { scan-assembler ".global\tfoo1\[\n\r\]+\t.type\tfoo1, @object" } } */
