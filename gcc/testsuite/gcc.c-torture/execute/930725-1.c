#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

int v;

__CONST char *
g ()
{
  return "";
}

__CONST char *
f ()
{
  return (v == 0 ? g () : "abc");
}

main ()
{
  v = 1;
  if (!strcmp (f (), "abc"))
    exit (0);
  abort();
}
