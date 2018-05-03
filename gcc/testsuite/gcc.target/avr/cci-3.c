/* Verify that cci attributes handled when cci enabled.  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include <xc.h>

// __section
int var1 __section("mydata") = 10;

// __align
char c __align(4);

// __pack
struct st
{
  char c;
  int i;
  long l;
} __pack obj = {4,2};

// __deprecate
volatile int step_count __deprecate;

// __section
int  __section("mycode") main ()
{
  step_count = 2; /* { dg-warning "'step_count' is deprecated" } */
  asm("ei");
  return 0;
}

/* { dg-final { scan-assembler ".section\tmydata,.*\n\t.type\tvar1, @object" } } */
/* { dg-final { scan-assembler ".comm\tc,1,4" } } */
/* { dg-final { scan-assembler "obj:\n\t.byte\t4\n\t.word\t2\n\t.zero\t4" } } */
/* { dg-final { scan-assembler ".section\tmycode,.*\n.global\tmain\n\t.type\tmain, @function" } } */
/* { dg-final { scan-assembler "\tei" } } */
