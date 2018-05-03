/* Verify that section directives generated */
/* { dg-do compile } */
/* { dg-options "-fdata-sections" } */

int   bss1;
short bss2;
char  bss3=0;

char  data1 = 2;
short data2 = 12;

const char rodata1 = 10;
const int  rodata2 = 12;

/* { dg-final { scan-assembler "\t.comm\tbss1,2,1" } } */
/* { dg-final { scan-assembler "\t.comm\tbss2,2,1" } } */
/* { dg-final { scan-assembler "\t.section\t.bss.bss3,bss" } } */
/* { dg-final { scan-assembler "\t.section\t.data.data1,data" } } */
/* { dg-final { scan-assembler "\t.type\tdata1, @object" } } */
/* { dg-final { scan-assembler "\t.section\t.data.data2,data" } } */
/* { dg-final { scan-assembler "\t.type\tdata2, @object" } } */
/* { dg-final { scan-assembler "\t.section\t.rodata.rodata1,data" } } */
/* { dg-final { scan-assembler "\t.type\trodata1, @object" } } */
/* { dg-final { scan-assembler "\t.section\t.rodata.rodata2,data" } } */
/* { dg-final { scan-assembler "\t.type\trodata2, @object" } } */

