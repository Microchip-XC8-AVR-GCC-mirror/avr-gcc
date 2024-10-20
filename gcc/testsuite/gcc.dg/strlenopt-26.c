/* { dg-do run } */
/* { dg-options "-O2 -fdump-tree-strlen" } */

#include "strlenopt.h"

__attribute__((noinline, noclone)) size_t
fn1 (char *p, const char *r)
{
  size_t len1 = strlen (r);
  char *q = (char*)strchr (p, '\0');
  *q = '\0';
  return len1 - strlen (r); // This strlen should be optimized into len1.
}

int
main (void)
{
  char p[] = "foobar";
  const char *volatile q = "xyzzy";
  fn1 (p, q);
  return 0;
}

/* { dg-final { scan-tree-dump-times "strlen \\(" 1 "strlen" } } */
/* { dg-final { cleanup-tree-dump "strlen" } } */
