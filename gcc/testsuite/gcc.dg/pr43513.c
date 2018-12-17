/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-ccp2" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
void bar (int *);
void foo (__CONST char *, int);

void
foo3 ()
{
  const int kIterations = 10;
  int results[kIterations];
  int i;
  bar (results);
  for (i = 0; i < kIterations; i++)
    foo ("%d ", results[i]);
}

/* { dg-final { scan-tree-dump-times "alloca" 0 "ccp2"} } */
/* { dg-final { cleanup-tree-dump "ccp2" } } */
