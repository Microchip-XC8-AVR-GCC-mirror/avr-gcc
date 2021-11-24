/* Verify that const data in mapped progmem sets implicit preprocessor
   define, and also does not pull in a ref to do_copy_data. */
/* { dg-options "-mconst-data-in-progmem -mconst-data-in-config-mapped-progmem" } */
/* { dg-do compile } */

#ifndef __AVR_CONST_DATA_IN_CONFIG_MAPPED_PROGMEM__
#error "Const data allocation to mapped progmem is not enabled"
#endif

const int arr[] = {1,2,3};
int main ()
{
  volatile int x;
  x = arr[x];
  return x;
}

/* { dg-final { scan-assembler-not ".global __do_copy_data "  } } */
