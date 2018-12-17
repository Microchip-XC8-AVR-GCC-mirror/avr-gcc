/* Contributed by Kris Van Hees <kris.van.hees@oracle.com> */
/* Test unsupported concatenation of char16_t/char32_t* string literals. */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

__CONST void	*s0	= u"a"  "b";
__CONST void	*s1	=  "a" u"b";
__CONST void	*s2	= u"a" U"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s3	= U"a" u"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s4	= u"a" L"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s5	= L"a" u"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s6	= u"a" u"b";
__CONST void	*s7	= U"a"  "b";
__CONST void	*s8	=  "a" U"b";
__CONST void	*s9	= U"a" L"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*sa	= L"a" U"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*sb	= U"a" U"b";
__CONST void	*sc	= L"a"  "b";
__CONST void	*sd	=  "a" L"b";
__CONST void	*se	= L"a" L"b";

int main () {}
