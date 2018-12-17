extern void abort (void);
extern int inside_main;

__attribute__ ((__noinline__))
const char *
strrchr (const char *s, int c)
{
  __SIZE_TYPE__ i;

#ifdef __OPTIMIZE__
  if (inside_main)
    abort ();
#endif

  i = 0;
  while (s[i] != 0)
    i++;

  do
    if (s[i] == c)
      return (const char *) s + i;
  while (i-- != 0);

  return 0;
}

__attribute__ ((__noinline__))
const char *
rindex (const char *s, int c)
{
  return strrchr (s, c);
}
