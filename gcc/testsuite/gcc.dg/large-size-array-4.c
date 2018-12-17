/* PR c/25309 */
/* { dg-do compile } */
/* { dg-options "" } */
#ifdef __AVR_CONST_DATA_IN_MEMX_ADDRESS_SPACE__
#define __CONST const
#else
#define __CONST
#endif

static __CONST char * name[] = {
    [0x80000000]  = "bar"
  };
/* { dg-error "too large" "" { target { { ! lp64 } && { ! llp64 } } }  12 } */
