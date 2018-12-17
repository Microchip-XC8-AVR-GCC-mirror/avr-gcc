#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern void abort ();
extern void exit (int);

struct s
{
    int value;
    __CONST char *string;
};

int main (void)
{
  int i;
  for (i = 0; i < 4; i++)
    {
      struct s *t = & (struct s) { 3, "hey there" };
      if (t->value != 3)
	abort();
      t->value = 4;
      if (t->value != 4)
	abort();
    }
  exit (0);
}
