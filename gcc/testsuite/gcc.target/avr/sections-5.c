/* Verify that section, at attributes work with progmem.  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include<xc.h>
#include<avr/pgmspace.h>

const unsigned char __section("progmem_sec1") __at(0x350) mydata[10] PROGMEM =
  {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};

void test_1 (void)
{
  int i;

  if ((uint16_t)mydata != 0x350)
    __builtin_abort();

  for (i=0; i < 10; i++)
    {
      if (i != pgm_read_byte(&(mydata[i])))
        __builtin_abort();
    }
}

const char string1[] PROGMEM = "String 1";
const char string2[] PROGMEM = "String 2";
PGM_P const string_table[] __at(0x35A) PROGMEM = { string1, string2 };

void test_2 (void)
{
  char buffer1[] = "String 1";
  char buffer2[] = "String 2";

  if ((uint16_t)string_table != 0x35A)
    __builtin_abort();

  if (strcmp_P(buffer1, (PGM_P)pgm_read_word(&(string_table[0]))))
    __builtin_abort();

  if (strcmp_P(buffer2, (PGM_P)pgm_read_word(&(string_table[1]))))
    __builtin_abort();
}

int main ()
{
  test_1();
  test_2();
  return 0;
}

