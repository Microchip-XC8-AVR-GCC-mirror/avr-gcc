/* Regression test for a cpplib macro-expansion bug where
   `@' becomes `@@' when stringified.  */

/* { dg-do run } */

#include <string.h>
#include <stdlib.h>

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif


#define STR(x) #x

__CONST char *a = STR(@foo), *b = "@foo";

int
main(void)
{
  if (strcmp (a, b))
    abort ();
  return 0;
}
