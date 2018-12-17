/* Test whether traditional stringify works.  */
/* { dg-do run } */

#define foo(a, b) c="a"; d="b";

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

extern void abort ();
extern void exit (int);

int main ()
{
  __CONST char *c, *d;

  foo (p,q);
  if (c[0] != 'p' || d[0] != 'q')
    abort ();

  exit (0);
}
