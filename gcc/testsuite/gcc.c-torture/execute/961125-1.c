#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

static __CONST char *
begfield (int tab, __CONST char *ptr, __CONST char *lim, int sword, int schar)
{
  if (tab)
    {
      while (ptr < lim && sword--)
	{
	  while (ptr < lim && *ptr != tab)
	    ++ptr;
	  if (ptr < lim)
	    ++ptr;
	}
    }
  else
    {
      while (1)
	;
    }

  if (ptr + schar <= lim)
    ptr += schar;

  return ptr;
}

main ()
{
  __CONST char *s = ":ab";
  __CONST char *lim = s + 3;
  if (begfield (':', s, lim, 1, 1) != s + 2)
    abort ();
  exit (0);
}
