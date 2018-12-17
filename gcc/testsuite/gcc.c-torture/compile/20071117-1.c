/* PR middle-end/34134 */
/* { dg-require-effective-target alloca } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

extern void bar (__CONST void *, int);

int foo (int i)
{
  char *p = __builtin_stack_save ();
  void *q = __builtin_alloca (i);
  bar (q, i);
  __builtin_stack_restore (p);
  bar ("", 0);
  return 6;
}
