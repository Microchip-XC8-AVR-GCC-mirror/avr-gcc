/* { dg-do compile } */
/* { dg-options "-std=c99" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
struct A
{
    char str[8];
    void* v;
};

int varf (__CONST char* fmt, ...);

void foo (struct A a, struct A b)
{
    varf ("%s%s", b.str, b.str);
}

long long x64;

void foo2 (long long j0,
           struct A a, struct A b, struct A c, struct A d,
           struct A e, struct A f, struct A g, struct A h, struct A i,
           long long j1)
{
    varf ("%s%s", i.str, i.str, x64, j1+j0);
}


void foo3 (long long j0,
           struct A a, struct A b, struct A c, struct A d,
           struct A e, struct A f, struct A g, struct A h, struct A i,
           long long j1)
{
    varf ("%s%s", &i.str, &b.str, x64, j1+j0);
}
