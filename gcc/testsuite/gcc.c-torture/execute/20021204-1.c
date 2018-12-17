/* This test was miscompiled when using sibling call optimization,
   because X ? Y : Y - 1 optimization changed X into !X in place
   and haven't reverted it if do_store_flag was successful, so
   when expanding the expression the second time it was
   !X ? Y : Y - 1.  */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern void abort (void);
extern void exit (int);

void foo (int x)
{
  if (x != 1)
    abort ();
}

int z;

int main (int argc, char **argv)
{
  __CONST char *a = "test";
  __CONST char *b = a + 2;

  foo (z > 0 ? b - a : b - a - 1);
  exit (0);
}
