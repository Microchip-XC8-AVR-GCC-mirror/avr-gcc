/* Verify that io and address attributes handled  */
/* { dg-do run } */
/* { dg-options "-mext=cci" } */

#include <xc.h>

#undef RAMSTART
#ifdef __AVR_MEGA__
#define RAMSTART 0x800100
#elif __AVR_XMEGA__
#define RAMSTART 0x802000
#else
#define RAMSTART 0x800040
#endif

int bss1 __attribute__((address(RAMSTART + 0x24)));
int absvar1 __at(RAMSTART + 0x100) = 10;
int absvar2 __at(RAMSTART + 0x120);
const int __flash absvar1_flash __at(0x350) = 12;
const int __flash absvar2_flash __at(0x354);

void test_1()
{
  if (((unsigned int)&absvar1 != (unsigned int)(RAMSTART + 0x100)) || (absvar1 != 10))
    __builtin_abort();
  if (((unsigned int)&absvar2 != (unsigned int)(RAMSTART + 0x120)) || (absvar2 != 0))
    __builtin_abort();
}

void test_2()
{
  if (((unsigned int)&absvar1_flash != 0x350) || (absvar1_flash != 12))
    __builtin_abort();
  if (((unsigned int)&absvar2_flash != 0x354) || (absvar2_flash != 0))
    __builtin_abort();
}

int main ()
{
  test_1();
  test_2();
  return 0;
}

