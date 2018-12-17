#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
char foo(__CONST char bar[])
{
  return bar[1];
}
extern char foo(__CONST char *);
int main(void)
{
  if (foo("xy") != 'y')
    abort ();
  exit (0);
}
