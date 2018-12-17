/* PR tree-optimization/19828 */
typedef __SIZE_TYPE__ size_t;
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern size_t strlen (const char *s);
extern int strncmp (const char *s1, const char *s2, size_t n);
extern void abort (void);

const char *a[16] = { "a", "bc", "de", "fgh" };

int
foo (__CONST char *x, const char *y, size_t n)
{
  size_t i, j = 0;
  for (i = 0; i < n; i++)
    {
      if (strncmp (x + j, a[i], strlen (a[i])) != 0)
        return 2;
      j += strlen (a[i]);
      if (y)
        j += strlen (y);
    }
  return 0;
}

int
main (void)
{
  if (foo ("abcde", (const char *) 0, 3) != 0)
    abort ();
  return 0;
}
