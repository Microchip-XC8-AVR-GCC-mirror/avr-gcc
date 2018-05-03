/* Verify that persistent attribute handled */
/* { dg-do compile } */
/* { dg-options "" } */

#ifndef __persistent
#define __persistent __attribute__((persistent))
#endif
#ifndef __section
#define __section(name) __attribute__((section(name)))
#endif

__persistent char  var1;
__persistent short var2[10];
__persistent __section("var_persist") int var3;

int main ()
{
  __persistent static int svar1;
  return svar1;
}

/* { dg-final { scan-assembler "\t.section\t\\*\[_a-z0-9\]*,persist\[\n\r\]+\t.type\tvar1, @object" } } */
/* { dg-final { scan-assembler "\t.section\t\\*\[_a-z0-9\]*,persist\[\n\r\]+\t.type\tvar2, @object" } } */
/* { dg-final { scan-assembler "\t.section\tvar_persist,persist\[\n\r\]+\t.type\tvar3, @object" } } */
/* { dg-final { scan-assembler "\t.section\t\\*\[_a-z0-9]*,persist\[\n\r\]+\t.type\tsvar1.\[0-9\]+, @object" } } */

