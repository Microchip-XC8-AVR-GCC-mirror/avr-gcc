/* Bug in reorg.c, deleting the "++" in the last loop in main.
   Origin: <hp@axis.com>.  */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern void f (void);
extern int x (int, __CONST char **);
extern int r (const char *);
extern char *s (__CONST char *, char **);
extern char *m (__CONST char *);
char *u;
char *h;
int check = 0;
int o = 0;

int main (int argc, char **argv)
{
  __CONST char *args[] = {"a", "b", "c", "d", "e"};
  if (x (5, args) != 0 || check != 2 || o != 5)
    abort ();
  exit (0);
}

int x (int argc, __CONST char **argv)
{
  int opt = 0;
  char *g = 0;
  char *p = 0;

  if (argc > o && argc > 2 && argv[o])
    {
      g = s (argv[o], &p);
      if (g)
	{
	  *g++ = '\0';
	  h = s (g, &p);
	  if (g == p)
	    h = m (g);
	}
      u = s (argv[o], &p);
      if (argv[o] == p)
	u = m (argv[o]);
    }
  else
    abort ();

  while (++o < argc)
    if (r (argv[o]) == 0)
      return 1;

  return 0;
}

char *m (__CONST char *x) { abort (); }
char *s (__CONST char *v, char **pp)
{
  if (strcmp (v, "a") != 0 || check++ > 1)
    abort ();
  *pp = (char*)v+1;
  return 0;
}

int r (const char *f)
{
  static char c[2] = "b";
  static int cnt = 0;

  if (*f != *c || f[1] != c[1] || cnt > 3)
    abort ();
  c[0]++;
  cnt++;
  return 1;
}
