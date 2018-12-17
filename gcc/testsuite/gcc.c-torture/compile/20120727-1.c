/* { dg-options "-mfpmath=387" { target { i?86-*-* x86_64-*-* } } } */
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

union {
  __CONST char *p;
  float f;
} u;

void
f (void)
{
  u.p = "";
  u.f += 1.1f;
}
