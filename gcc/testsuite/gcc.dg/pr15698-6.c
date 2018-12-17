/* Test diagnostics for old-style definition not matching prior
   prototype are present and give correct location for that prototype
   (bug 15698).  Prototyped built-in function, wrong number of
   arguments.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
__CONST char *strchr(a) const char *a; { return 0; } /* { dg-warning "number of arguments doesn't match built-in prototype" } */
