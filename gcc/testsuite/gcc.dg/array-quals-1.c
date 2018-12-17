/* Test for various combinations of const, arrays and typedefs:
   should never actually get const on the final array type, but
   all should end up in a read-only section.  PR c/12165.  */
/* Origin: Joseph Myers <jsm@polyomino.org.uk> */
/* { dg-do compile } */
/* { dg-options "-Wno-discarded-array-qualifiers" } */
/* The MMIX port always switches to the .data section at the end of a file.  */
/* { dg-final { scan-assembler-not "\\.data(?!\\.rel\\.ro)" { xfail powerpc*-*-aix* mmix-*-* x86_64-*-mingw* } } } */
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

static const int a[2] = { 1, 2 };
const int a1[2] = { 1, 2 };
typedef const int ci;
static ci b[2] = { 3, 4 };
ci b1[2] = { 3, 4 };
typedef int ia[2];
static const ia c = { 5, 6 };
const ia c1 = { 5, 6 };
typedef const int cia[2];
static cia d = { 7, 8 };
cia d1 = { 7, 8 };
static cia e[2] = { { 1, 2 }, { 3, 4 } };
cia e1[2] = { { 1, 2 }, { 3, 4 } };
__CONST void *const p = &a;
__CONST void *const q = &b;
__CONST void *const r = &c;
__CONST void *const s = &d;
__CONST void *const t = &e;
__CONST void *const p1 = &a1;
__CONST void *const q1 = &b1;
__CONST void *const r1 = &c1;
__CONST void *const s1 = &d1;
__CONST void *const t1 = &e1;
