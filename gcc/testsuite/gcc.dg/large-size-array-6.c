/* PR c/57821 */
/* { dg-do compile } */
/* { dg-options "-O2" } */
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif
static __CONST char * name[] = {
    [0x8000000000000000]  = "bar"
  }; /* { dg-error "too large" } */
