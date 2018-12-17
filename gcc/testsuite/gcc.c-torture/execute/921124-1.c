#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

f(x, d1, d2, d3)
   double d1, d2, d3;
{
   return x;
}

g(b,s,x,y,i,j)
     __CONST char *b,*s;
     double x,y;
{
  if (x != 1.0 || y != 2.0 || i != 3 || j != 4)
    abort();
}

main()
{
  g("","", 1.0, 2.0, f(3, 0.0, 0.0, 0.0), f(4, 0.0, 0.0, 0.0));
  exit(0);
}
