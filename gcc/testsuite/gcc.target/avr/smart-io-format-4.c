/* Test invalid smart-io-format option */

/* { dg-do compile } */
/* { dg-options "-msmart-io -msmart-io-format=xyz" } */

#include <stdio.h>
#include <stdarg.h>

int d, n;
float f;
va_list _va;
FILE *fp;
char *str;

void t01 (const char *fmt) 
{
  scanf (fmt, &d, &f);
  vscanf (fmt, _va);
  
  printf (fmt, d, f);
  vprintf (fmt, _va);
  
}

const char *s;
void main()
{
  t01(s);
}

/* { dg-warning "argument 'xyz' is not a valid format specifier, ignored" "" { target *-*-* } 0 } */
