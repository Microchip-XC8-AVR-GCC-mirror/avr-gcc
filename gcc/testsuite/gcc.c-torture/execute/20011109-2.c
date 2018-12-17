#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
int main(void)
{
  __CONST char *c1 = "foo";
  __CONST char *c2 = "foo";
  int i;
  for (i = 0; i < 3; i++)
    if (c1[i] != c2[i])
      abort ();
  exit (0);
}
