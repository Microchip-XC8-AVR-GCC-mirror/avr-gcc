/* Verify that const data in mapped progmem is not enabled if
   const-data-in-progmem itself is turned off. */
/* { dg-options "-mno-const-data-in-progmem -mconst-data-in-config-mapped-progmem" } */
/* { dg-do compile } */

#ifdef __AVR_CONST_DATA_IN_CONFIG_MAPPED_PROGMEM__
#error "Const data allocation to mapped progmem is not enabled"
#endif

int main ()
{
  return 0;
}

/* { dg-message "-mconst-data-in-progmem is not enabled, disabling -mconst-data-in-config-mapped-progmem" "warning text" { target *-*-* } 0 } */
