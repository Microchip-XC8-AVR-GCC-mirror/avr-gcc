/* This used to abort due to a loop bug on s390*.  */

/* { dg-do run } */
/* { dg-options "-O2" } */
/* { dg-options "-O2 -fPIC" { target s390*-*-* } } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

extern void abort (void);

int count = 0;
__CONST char *str;

void test (int flag)
{
  __CONST char *p;

  for (;;)
    {
      if (count > 5)
	return;

      p = "test";

      if (flag)
	count++;

      str = p;
    }
}

int main (void)
{
  test (1);

  if (str[0] != 't')
    abort ();

  return 0;
}

