/* Verify that const data allocation to progmem disabled by option.  */
/* { dg-do compile } */
/* { dg-options "-mno-const-data-in-progmem" } */
/* { dg-skip-if "skip if global option is to enable const data in progmem" { *-*-* } { "-mconst-data-in-progmem" } { "" } } */

#ifdef __AVR_CONST_DATA_IN_PROGMEM__
#error "Allocating const data to progmem is not disabled."
#endif

int main ()
{
  return 0;
}

