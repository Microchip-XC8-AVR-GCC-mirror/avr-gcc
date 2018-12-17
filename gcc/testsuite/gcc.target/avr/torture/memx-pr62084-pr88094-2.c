/* Verify that memx read works. PR 62084 and PR 88094  */
/* { dg-do run } */
/* { dg-options "-std=gnu99" } */

__memx const char arr[10] = "hello";
int volatile x;

__attribute__((noinline))
__memx const void* bar(const __memx char * c)
{
  return c + x - 1;
}

int main (void)
{
  x = 0;
  if (bar(&arr[4]) != &arr[3])
    __builtin_abort();

  return 0;
}

