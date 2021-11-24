/* Verify that codegen for const data in mapped progmem results in
   data memory loads, and not loads from memx address space. */
/* { dg-options "-mconst-data-in-progmem -mconst-data-in-config-mapped-progmem" } */
/* { dg-do compile } */

extern const int x;

int foo() { return x; }

/* { dg-final { scan-assembler "lds r24,x\n" { target { ! avr_tiny } } } } */
/* { dg-final { scan-assembler "lds r25,x\\+1\n" { target { ! avr_tiny } } } } */
/* { dg-final { scan-assembler "ld r2\\d,Z\n" { target avr_tiny } } } */
/* { dg-final { scan-assembler "ld r2\\d,Z\n" { target avr_tiny }  } } */
/* { dg-final { scan-assembler-not "xload"  } } */
