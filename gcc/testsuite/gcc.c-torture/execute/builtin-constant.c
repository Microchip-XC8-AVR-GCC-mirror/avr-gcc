/* PR optimization/8423.  */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
#define btest(x) __builtin_constant_p(x) ? "1" : "0"

#ifdef __OPTIMIZE__
void
foo (__CONST char *i)
{
  if (*i == '0')
    abort ();
}
#else
void
foo (__CONST char *i)
{
}
#endif

int
main (void)
{
  int size = sizeof (int);
  foo (btest (size));
  foo (btest (size));
  exit (0);
}
