/* { dg-do compile } */
/* { dg-options "-O -fdump-tree-ccp1" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
static const int x;

int test1 (void)
{
  __CONST char *p = "hello";
  int i = x;
  i = i + 5;
  return p[i];
}

int test2 (void)
{
  int i = x;
  i = i + 5;
  return "hello"[i];
}

/* { dg-final { scan-tree-dump-times "return 0;" 2 "ccp1" } } */
/* { dg-final { cleanup-tree-dump "ccp1" } } */
