/* Verify that const volatile data are allocated correctly when
   const-data-in-progmem enabled.  */

/* { dg-do compile } */
/* { dg-options "-save-temps -mext=cci -mconst-data-in-progmem" } */

#include <xc.h>

const volatile char var1;
const volatile short var2 = 2;

const int var3;
const int var4 = 12;

const int * ptr1;
const int * ptr2 = &var3;

const int * const ptr3;
const int * const volatile ptr4;

const int * const ptr5 = (const int*)0x1234;
const int * const volatile ptr6 = (const int*const volatile)0xabcd;

const volatile char __section("ignored_section_name") cvArr[] = "hello";

int main ()
{
  return *ptr3;
}

/* { dg-final { scan-assembler ".global\tvar1\n\t.section\t.progmemx.data,progmemx\n\t.type\tvar1" } } */
/* { dg-final { scan-assembler ".global\tvar2\n\t.section\t.progmemx.data,progmemx\n\t.type\tvar2" } } */
/* { dg-final { scan-assembler ".global\tvar3\n\t.section\t.progmemx.data,progmemx\n\t.type\tvar3" } } */
/* { dg-final { scan-assembler ".global\tvar4\n\t.section\t.progmemx.data,progmemx\n\t.type\tvar4" } } */
/* { dg-final { scan-assembler ".comm\tptr1,3,1" } } */
/* { dg-final { scan-assembler ".global\tptr2\n\t.section\t.data,data\n\t.type\tptr2" } } */
/* { dg-final { scan-assembler ".global\tptr3\n\t.section\t.progmemx.data,progmemx\n\t.type\tptr3" } } */
/* { dg-final { scan-assembler ".global\tptr4\n\t.section\t.progmemx.data,progmemx\n\t.type\tptr4" } } */
/* { dg-final { scan-assembler ".global\tptr5\n\t.section\t.progmemx.data,progmemx\n\t.type\tptr5" } } */
/* { dg-final { scan-assembler ".global\tptr6\n\t.section\t.progmemx.data,progmemx\n\t.type\tptr6" } } */
/* { dg-final { scan-assembler ".global\tcvArr\n\t.section\t.progmemx.data,progmemx\n\t.type\tcvArr" } } */

