/* { dg-do compile } */
/* { dg-options "-O3" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
void generic_sendmsg (__CONST char *fmt, ...)
{
  __builtin_next_arg(fmt);
}

void generic_sendstat()
{
  double t;

  generic_sendmsg("F %3.2f", t);
}
