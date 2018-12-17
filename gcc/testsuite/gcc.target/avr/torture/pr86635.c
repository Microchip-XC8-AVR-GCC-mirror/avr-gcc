/* { dg-do compile { target { ! avr_tiny } } } */
/* { dg-options "-std=gnu99" } */

extern const __memx float a;
extern const float b;

unsigned long diff () { return a > b; }

/* { dg-final { scan-assembler "call __xload_4" } } */
