#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

extern void abort (void);
int __attribute__((noinline,noclone))
foo (__CONST char *p)
{
  int h = 0;
  do
    {
      if (*p == '\0')
	break;
      ++h;
      if (p == 0)
	abort ();
      ++p;
    }
  while (1);
  return h;
}
int main()
{
  if (foo("a") != 1)
    abort ();
  return 0;
}
