/* This testcase ICEd on alpha because of an unrecognized insn formed
   by conditional move optimization using an incorrect mode.  */
/* { dg-do compile } */
/* { dg-options "-O -ffast-math" } */

#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
__CONST char*
barf (double x)
{
    return (x<0.0) ? "foo" : "bar";
}
