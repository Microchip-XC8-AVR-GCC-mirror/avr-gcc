/* Verify that section directives generated */
/* { dg-do compile } */
/* { dg-options "-fmerge-all-constants" } */

const char rodata1 = 10;
const int  rodata2 = 12;
const char rodata3 __attribute__((section("constsec"))) = 1;
const char *str1 = "hello world";
const char *str2 = "hello";

/* { dg-final { scan-assembler "\t.section\t.rodata,data" } } */
/* { dg-final { scan-assembler "\t.type\trodata1, @object" } } */
/* { dg-final { scan-assembler "\t.section\t.rodata,data" } } */
/* { dg-final { scan-assembler "\t.type\trodata2, @object" } } */
/* { dg-final { scan-assembler "\t.section\tconstsec,data" } } */
/* { dg-final { scan-assembler "\t.type\trodata3, @object" } } */
/* { dg-final { scan-assembler "\t.section\t.rodata,data" } } */
/* { dg-final { scan-assembler "\t.string\t\"hello world\"" } } */
/* { dg-final { scan-assembler "\t.section\t.data,data" } } */
/* { dg-final { scan-assembler "\t.type\tstr1, @object" } } */
/* { dg-final { scan-assembler "\t.section\t.rodata,data" } } */
/* { dg-final { scan-assembler "\t.string\t\"hello\"" } } */
/* { dg-final { scan-assembler "\t.section\t.data,data" } } */
/* { dg-final { scan-assembler "\t.type\tstr2, @object" } } */

