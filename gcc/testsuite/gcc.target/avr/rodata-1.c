/* Verify that section directives generated */
/* { dg-do compile } */
/* { dg-options "-mno-const-data-in-progmem" } */
/* { dg-skip-if "skip if global option is to enable const data in progmem" { *-*-* } { "-mconst-data-in-progmem" } { "" } } */

char *ptr = "hello";
const char carr[10] = "world";
const int var = 4809;
const int * ptr_ci = &var;

int main ()
{
  static const char scarr[10] = "avr";
  static const short ssvar = 2;
  static const short * ptr_cs = &ssvar;

  return ptr[*ptr_cs];
}

/* { dg-final { scan-assembler "\t.section\t.rodata,rodata\n.LC0:\n\t.string\t\"hello\"" } } */
/* { dg-final { scan-assembler "\t.section\t.data,data\n\t.type\tptr" } } */
/* { dg-final { scan-assembler ".global\tcarr\n\t.section\t.rodata,rodata" } } */
/* { dg-final { scan-assembler ".global\tvar\n\t.type\tvar" } } */
/* { dg-final { scan-assembler ".global\tptr_ci\n\t.section\t.data,data" } } */
/* { dg-final { scan-assembler ".ptr_ci:\n\t.word\tvar" } } */

