/* Verify that const volatile data are allocated correctly. Run test only
   on archs where const-data-in-progmem uses progmem insns to read from flash.
   For devices with flash mapped into data memory, we always allocate and read
   const data from flash. */

/* { dg-do compile } */
/* { dg-options "-save-temps -mext=cci " } */
/* { dg-skip-if "skip if global option is to enable const data in progmem" { { ! avr_progmem_insn_for_progmem } || { avr_const_data_in_progmem } } } */

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

const volatile char __section("mydata") cvArr[] = "hello";

int main ()
{
  return *ptr3;
}

/* { dg-final { scan-assembler ".comm\tvar1,1,1" } } */
/* { dg-final { scan-assembler ".global\tvar2\n\t.section\t.data,data\n\t.type\tvar2" } } */
/* { dg-final { scan-assembler ".comm\tvar3,2,1" } } */
/* { dg-final { scan-assembler ".global\tvar4\n\t.section\t.rodata,rodata\n\t.type\tvar4" } } */
/* { dg-final { scan-assembler ".comm\tptr1,2,1" } } */
/* { dg-final { scan-assembler ".global\tptr2\n\t.section\t.data,data\n\t.type\tptr2" } } */
/* { dg-final { scan-assembler ".comm\tptr3,2,1" } } */
/* { dg-final { scan-assembler ".comm\tptr4,2,1" } } */
/* { dg-final { scan-assembler ".global\tptr5\n\t.section\t.rodata,rodata\n\t.type\tptr5" } } */
/* { dg-final { scan-assembler ".global\tptr6\n\t.section\t.data,data\n\t.type\tptr6" } } */
/* { dg-final { scan-assembler ".global\tcvArr\n\t.section\tmydata,data\n\t.type\tcvArr" } } */

