/* Test case for XC8-2450 */
/* { dg-do compile } */
/* { dg-options "-mconst-data-in-progmem" } */
/* { dg-require-effective-target avr_progmem_insn_for_progmem } */
int main(void) {
   const __memx int *ptr;
   return *ptr == 0;
}

