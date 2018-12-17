/* Test diagnostics for old-style definition not matching prior
   prototype are present and give correct location for that prototype
   (bug 15698).  Original test.  */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */

int	foobar ();

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

int func (int blah)
{
  __CONST char *rindex();
}

int foobar ()
{
  return 0;
}

__CONST char *rindex(a, b)
     register char *a, b; /* { dg-warning "argument 'a' doesn't match built-in prototype" } */
{
  return 0;
}
