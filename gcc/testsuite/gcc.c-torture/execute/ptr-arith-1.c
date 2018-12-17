#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
__CONST char *
f (__CONST char *s, unsigned int i)
{
  return &s[i + 3 - 1];
}

main ()
{
  __CONST char *str = "abcdefghijkl";
  __CONST char *x2 = f (str, 12);
  if (str + 14 != x2)
    abort ();
  exit (0);
}
