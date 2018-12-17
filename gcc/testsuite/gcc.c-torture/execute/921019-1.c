#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
__CONST void *foo[]={(__CONST void *)&("X"[0])};

main ()
{
  if (((__CONST char*)foo[0])[0] != 'X')
    abort ();
  exit (0);
}
