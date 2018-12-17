/* { dg-do run } */
/* { dg-options "-std=gnu99 " } */

const char __memx arr[10] = "hello";
int val = 3;
__attribute__((noinline))
const char __memx * foo (const __memx char *p)
{
  while (val--)
    if (*(p+val) == 'e')
      return p+val;
  return 0;
}

int main ()
{
  if (&arr[1] != foo(arr))
    __builtin_abort();

  return 0;
}

