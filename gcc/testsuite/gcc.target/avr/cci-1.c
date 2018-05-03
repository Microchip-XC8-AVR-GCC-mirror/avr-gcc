/* Verify that cci options are handled.  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include <xc.h>

#ifndef __XC__
#warning "__XC__ macro not defined"
#endif

#ifndef __CCI__
#warning "__CCI__ macro not defined"
#endif

#ifndef __persistent
#warning "__persistent attribute not defined"
#endif

#ifndef __at
#warning "__at(address) attribute not defined"
#endif

#ifndef __align
#warning "__align(n) attribute not defined"
#endif

#ifndef __pack
#warning "__pack attribute not defined"
#endif

#ifndef __deprecate
#warning "__deprecate attribute not defined"
#endif

#ifndef __section
#warning "__section(name) attribute not defined"
#endif

#ifndef asm
#warning "asm(args) attribute not defined"
#endif

int main ()
{
  return 0;
}

