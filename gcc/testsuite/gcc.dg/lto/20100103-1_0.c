/* { dg-lto-do link } */
/* { dg-lto-options {{-funsigned-char -flto} {-fsigned-char -flto}} } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
__CONST char *foo;
int main()
{
  foo = "bar";
}
