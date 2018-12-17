/* { dg-skip-if "requires alloca" { ! alloca } { "-O0" } { "" } } */
extern void abort (void);

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

extern __SIZE_TYPE__ strlen (const char *);
void foo(__CONST char *str)
{
  int len2 = strlen (str);
  char *a = (char *) __builtin_alloca (0);
  char *b = (char *) __builtin_alloca (len2*3);

  if ((int) (a-b) < (len2*3))
    {
#ifdef _WIN32
      abort ();
#endif
      return;
    }
}

static __CONST char * volatile argp = "pr36321.x";

int main(int argc, char **argv)
{
  foo (argp);
  return 0;
}

