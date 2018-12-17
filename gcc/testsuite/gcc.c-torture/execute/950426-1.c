#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

struct tag {
  int m1;
  __CONST char *m2[5];
} s1, *p1;

int i;

main()
{
  s1.m1 = -1;
  p1 = &s1;

  if ( func1( &p1->m1 ) == -1 )
    foo ("ok");
  else
    abort ();

  i = 3;
  s1.m2[3]= "123";

  if ( strlen( (p1->m2[i])++ ) == 3 )
    foo ("ok");
  else
    abort ();

  exit (0);
}

func1(int *p) { return(*p); }

foo (char *s) {}
