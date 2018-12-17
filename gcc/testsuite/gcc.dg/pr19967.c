/* PR middle-end/19967
   These functions mentioned below are supposed to return char *.
   However, fold_builtin_... had bugs that caused the return types to
   be const char *.  */

/* { dg-do compile } */
/* { dg-options "-pedantic -std=c99" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

__CONST char *strchr(const char *, int);
__CONST char *strrchr(const char *, int);
__CONST char *index(const char *, int);
__CONST char *rindex(const char *, int);
__CONST char *strpbrk(const char *, const char *);
__CONST char *strstr(const char *, const char *);
__CONST char *p;

void
f (void)
{
  p = strchr(__func__, 'f');
  p = strrchr(__func__, 'f');
  p = index(__func__, 'f');
  p = rindex(__func__, 'f');
  p = strpbrk(__func__, "f");
  p = strstr(__func__, "f");
}
