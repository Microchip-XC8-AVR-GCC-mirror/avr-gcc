/* Contributed by Kris Van Hees <kris.van.hees@oracle.com> */
/* Test concatenation of char16_t* string literals. */
/* { dg-do run } */
/* { dg-options "-std=gnu99 -Wall -Werror" } */

typedef __CHAR16_TYPE__ char16_t;

extern void abort (void);
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

__CONST char16_t	*s0 = u"a" u"b";

__CONST char16_t	*s1 = u"a" "b";
__CONST char16_t	*s2 = "a" u"b";
__CONST char16_t	*s3 = u"a" "\u2029";
__CONST char16_t	*s4 = "\u2029" u"b";
__CONST char16_t	*s5 = u"a" "\U00064321";
__CONST char16_t	*s6 = "\U00064321" u"b";

#define A	0x0061
#define B	0x0062
#define X	0x2029
#define Y1	0xD950
#define Y2	0xDF21

int main ()
{
    if (sizeof ((u"a" u"b")[0]) != sizeof (char16_t))
	abort ();
    if (sizeof ((u"a"  "b")[0]) != sizeof (char16_t))
	abort ();
    if (sizeof (( "a" u"b")[0]) != sizeof (char16_t))
	abort ();

    if (s0[0] != A || s0[1] != B || s0[2] != 0x0000)
	abort ();

    if (s1[0] != A || s1[1] != B || s1[2] != 0x0000)
	abort ();
    if (s2[0] != A || s2[1] != B || s2[2] != 0x0000)
	abort ();
    if (s3[0] != A || s3[1] != X || s3[2] != 0x0000)
	abort ();
    if (s4[0] != X || s4[1] != B || s4[2] != 0x0000)
	abort ();
    if (s5[0] != A || s5[1] != Y1 || s5[2] != Y2 || s5[3] != 0x0000)
	abort ();
    if (s6[0] != Y1 || s6[1] != Y2 || s6[2] != B || s6[3] != 0x0000)
	abort ();
}
