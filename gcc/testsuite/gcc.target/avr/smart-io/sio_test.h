#include <stdio.h>
#include <stdarg.h>

char   c;
int    d, n, o, u, x, X;
int *p;
float  a, e, E, f, F;
double g, G;
char  *s;

char  buf[512];
FILE *fp;
int  len;
va_list _va;

#define   QUOTE(...)    __QUOTE(__VA_ARGS__)
#define __QUOTE(...)    #__VA_ARGS__

