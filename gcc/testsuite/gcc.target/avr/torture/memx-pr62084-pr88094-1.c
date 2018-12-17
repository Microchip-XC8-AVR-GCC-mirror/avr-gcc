/* Verify that memx read works. PR 62084 and PR 88094  */
/* { dg-do run } */
/* { dg-options "-std=gnu99" } */

#include<stdlib.h>
__memx const char arr[10] = "hello";
__memx const void *
memx_read(__memx const char * src, char c, unsigned int n);

__attribute__((noinline))
__memx const void *
memx_read(__memx const char * src, char c, unsigned int n)
{
  while (n--)
    if (src[n] == c)
      return src + n;
  return 0;
}

int main ()
{
  if (arr + 3 != memx_read(arr, 'l', 10))
    __builtin_abort ();

  return 0;
}

