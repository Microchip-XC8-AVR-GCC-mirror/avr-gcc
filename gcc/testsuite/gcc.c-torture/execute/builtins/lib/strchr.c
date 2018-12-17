extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
const char *
strchr (const char *s, int c)
{
#ifdef __OPTIMIZE__
  if (inside_main)
    abort ();
#endif

  for (;;)
    {
      if (*s == c)
	return (const char *) s;
      if (*s == 0)
	return 0;
      s++;
    }
}

__attribute__ ((__noinline__))
const char *
index (const char *s, int c)
{
  return strchr (s, c);
}
