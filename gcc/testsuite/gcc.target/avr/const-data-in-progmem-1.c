/* Verify that const data allocation to progmem enabled.  */
/* { dg-options "-mconst-data-in-progmem" } */
/* { dg-do compile } */

#ifndef __AVR_CONST_DATA_IN_PROGMEM__
#error "Const data allocation to progmem is not enabled by default."
#endif

int main ()
{
  return 0;
}

