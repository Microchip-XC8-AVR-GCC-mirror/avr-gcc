/* Verify that explicitly providing -mconst-data-in-config-mapped-progmem
   without const-data-in-progmem does not result in a link failure */
/* { dg-do run } */
/* { dg-options "-mno-const-data-in-progmem -mconst-data-in-config-mapped-progmem" } */
/* { dg-skip-if "Only for config-mapped-progmem devices" { ! avr_config_mapped_progmem } } */

#include <stdlib.h>
volatile int x = 2;
const char arr[] = {1, 3, 4};
int main()
  {
	if (arr[x] != 4)
	  abort();
	return 0;
  }

/* { dg-message "-mconst-data-in-progmem is not enabled, disabling -mconst-data-in-config-mapped-progmem" "warning text" { target *-*-* } 0 } */
