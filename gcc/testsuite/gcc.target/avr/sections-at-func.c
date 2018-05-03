/* Verify that io and address attributes handled  */
/* { dg-do run } */
/* { dg-options "-mext=cci" } */

#include <xc.h>

void __at(0x400) test_3()
{
  if ((unsigned int)test_3 != 0x200)
    __builtin_abort();
}

int main ()
{
  test_3();
  return 0;
}

