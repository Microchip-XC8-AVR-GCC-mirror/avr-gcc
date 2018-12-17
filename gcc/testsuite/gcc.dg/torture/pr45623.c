/* { dg-do run } */
/* { dg-options "-std=c99" } */

#include <stdint.h>

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern void abort (void);

__CONST char *s1 = "foo";
__CONST char *s2 = "bar";

__CONST char **ss1 = &s1;

typedef union jsval_layout
{
    uint64_t asBits;
    __CONST char **ptr;
} jsval_layout;

int main()
{
  jsval_layout l, m;
  l.ptr = ss1;
  m.asBits = l.asBits;
  __CONST char ** data = m.ptr;
  *data = s2;
  if (s1 != s2)
    abort ();
  return 0;
}
