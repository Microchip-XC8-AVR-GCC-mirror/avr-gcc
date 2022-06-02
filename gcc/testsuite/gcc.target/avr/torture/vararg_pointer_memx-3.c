/* { dg-do run } */
/* { dg-options "-std=gnu99" } */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void __attribute__((noinline)) foo (int x, ...)
{
  va_list ap;
  va_start(ap, x);

  if (x != 20)
    abort();

  const int *p0 = va_arg(ap, const int*);
  if (*p0 != 20)
    abort();

  int *p1 = va_arg(ap, int*);
  if (*p1 != 20)
    abort();
  *p1 = 100;

  const int *p2 = va_arg(ap, const int*);
  if (*p2 != 30)
    abort();

  va_end(ap);
}

int main(void) {
    int x = 20;
    static const int y = 30;

    foo (x, &x, &x, &y);
    if (x != 100)
      abort();

    exit(0);
}
