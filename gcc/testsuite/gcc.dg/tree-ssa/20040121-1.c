

/* Test that (p!=0) + (q!=0) is computed as int,
    not boolean */
/* { dg-options "-O3" } */
/* { dg-do run } */
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
extern void abort (void);
__CONST char *foo(__CONST char *p, __CONST char *q) {
    int x = (p !=0) + (q != 0);
    if (x==2)  return "a"; else return 0;
}
extern __CONST char *bar(__CONST char*, __CONST char*) __attribute__((noinline));
__CONST char *bar(__CONST char *first, __CONST char *last)
{
   int y;
   if (!first)  return last;
   if (!last)   return first;
   if (*first == 'a')
     return foo(first, last);
   return 0;
}
int
main() {
   __CONST char *p = "a", *q = "b";
   if (p)
     if (bar(p,q))
       return 0;
   abort();
}
