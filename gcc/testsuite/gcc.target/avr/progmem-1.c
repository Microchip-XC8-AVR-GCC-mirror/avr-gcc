/* Verify that progmem sections are emitted.  */
/* { dg-do run } */
/* { dg-options "" } */

#include <avr/pgmspace.h>

const int PROGMEM c1 = 0xABD;

int main()
{
  if (0xABD != (int)pgm_read_word(&c1))
    __builtin_abort();
  return 0;
}

