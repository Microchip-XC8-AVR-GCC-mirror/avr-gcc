/* Verify that section directives generated */
/* { dg-do compile } */
/* { dg-options "-mno-const-data-in-progmem" } */
/* { dg-skip-if "skip if global option is to enable const data in progmem" { *-*-* } { "-mconst-data-in-progmem" } { "" } } */

int   bss1;
short bss2;
char  bss3=0;

char  data1 = 2;
short data2 = 12;

const char rodata1 = 10;
const int  rodata2 = 12;

int __attribute__((section("secname"))) func (char c)
{
  return c * 4;
}

int main ()
{
  return func(2);
}

/* { dg-final { scan-assembler "\t.comm\tbss1,2,1" } } */
/* { dg-final { scan-assembler "\t.comm\tbss2,2,1" } } */
/* { dg-final { scan-assembler "\t.section\t.bss,bss" } } */
/* { dg-final { scan-assembler "\t.type\tbss3, @object" } } */
/* { dg-final { scan-assembler "\t.section\t.data,data" } } */
/* { dg-final { scan-assembler "\t.type\tdata1, @object" } } */
/* { dg-final { scan-assembler "\t.type\tdata2, @object" } } */
/* { dg-final { scan-assembler "\t.section\t.rodata,rodata" } } */
/* { dg-final { scan-assembler "\t.type\trodata1, @object" } } */
/* { dg-final { scan-assembler "\t.type\trodata2, @object" } } */
/* { dg-final { scan-assembler "\t.section\tsecname,code" } } */
/* { dg-final { scan-assembler ".global\tfunc\[\n\r\]+\t.type\tfunc, @function" } } */
/* { dg-final { scan-assembler "\t.section\t.text,code" } } */
/* { dg-final { scan-assembler ".global\tmain\[\n\r\]+\t.type\tmain, @function" } } */

