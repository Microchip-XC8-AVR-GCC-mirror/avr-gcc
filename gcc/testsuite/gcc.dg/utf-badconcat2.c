/* Test unsupported concatenation of UTF-8 string literals. */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

__CONST void	*s0	= u8"a"   "b";
__CONST void	*s1	=   "a" u8"b";
__CONST void	*s2	= u8"a" u8"b";
__CONST void	*s3	= u8"a"  u"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s4	=  u"a" u8"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s5	= u8"a"  U"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s6	=  U"a" u8"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s7	= u8"a"  L"b";	/* { dg-error "non-standard concatenation" } */
__CONST void	*s8	=  L"a" u8"b";	/* { dg-error "non-standard concatenation" } */

int main () {}
