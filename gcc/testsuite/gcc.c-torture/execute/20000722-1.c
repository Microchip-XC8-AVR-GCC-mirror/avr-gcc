#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
struct s { __CONST char *p; int t; };

extern void bar (void);
extern void foo (struct s *);

int main(void)
{
  bar ();
  bar ();
  exit (0);
}

void 
bar (void)
{
  foo (& (struct s) { "hi", 1 });
}

void foo (struct s *p)
{
  if (p->t != 1)
    abort();
  p->t = 2;
}
