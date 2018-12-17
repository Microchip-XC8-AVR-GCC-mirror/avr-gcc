/* PR tree-optimization/32975 */
/* { dg-do compile } */
/* { dg-options "-O1 -finline-functions -fipa-cp" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
static int
f0 (char *s0, __CONST char *s1)
{
  return __builtin_strlen (s0) > __builtin_strlen (s1);
}

int
f1 (char *s, int j)
{
  if (f0 (s, ""))
    return 1;
  return j;
}

void
f2 (char *s)
{
  f1 (s, 0);
}
