/* { dg-do run } */
/* { dg-options "-std=gnu99" } */
/* { dg-skip-if "Too big to fit for AVRTINY" { "avr-*-*" } { "-mmcu=attiny40" } { "" } } */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char body[5];
void __attribute__((noinline)) foo (const char* fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(body, sizeof(body), fmt, ap);
  va_end(ap);
}

int main(void) {
    char a[] = "ab";
    char b[] = "c";
    foo("%s%s", a, b);
    if (strncmp(body, "abc", 3) != 0)
      abort();
    int d = 6;
    int e = 12;
    foo("%d%d", d, e);
    if (strncmp(body, "612", 3) != 0)
      abort();

    exit(0);
}
