/* Verifies that weakrefs don't cause lto1 to ICE */
/*   XC8-1995 (gcc PR 65982)  */
/* { dg-do run } */
/* { dg-options "-flto" } */

static int a __attribute__ ((weakref ("b")));
int c;
int main (void)
{
  if (a)
    c = 0;
  return 0;
}
