#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
__CONST char *
f (__CONST char *p)
{
  short x = *p++ << 16;
  return p;
}

main ()
{
  __CONST char *p = "";
  if (f (p) != p + 1)
    abort ();
  exit (0);
}
