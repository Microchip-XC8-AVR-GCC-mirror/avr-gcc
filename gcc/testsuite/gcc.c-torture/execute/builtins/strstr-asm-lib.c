#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern void abort (void);
typedef __SIZE_TYPE__ size_t;
extern size_t strlen(const char *);
extern const char *strchr(const char *, int);
extern int strcmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int inside_main;
extern const char *p;

__attribute__ ((used))
const char *
my_strstr (const char *s1, const char *s2)
{
  const size_t len = strlen (s2);

#ifdef __OPTIMIZE__
  /* If optimizing, we should be called only in the strstr (foo + 2, p)
     case.  All other cases should be optimized.  */
  if (inside_main)
    if (s2 != p || strcmp (s1, "hello world" + 2) != 0)
      abort ();
#endif
  if (len == 0)
    return (const char *) s1;
  for (s1 = strchr (s1, *s2); s1; s1 = strchr (s1 + 1, *s2))
    if (strncmp (s1, s2, len) == 0)
      return (const char *) s1;
  return (const char *) 0;
}

__CONST char *
strstr (const char *s1, const char *s2)
{
  if (inside_main)
    abort ();

  return my_strstr (s1, s2);
}
