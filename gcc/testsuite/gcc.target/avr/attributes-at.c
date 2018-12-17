/* Verify that __at attributes handled and its diagnostics.
   XC8-1773  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include <xc.h>

short __at(100) var1;
__at(200) char * var2;
char * __at(300) var3; /* { dg-warning "at\\(address\\) attribute only applies to variables and functions" } */
void * __at(400) foo (); /* { dg-warning "at\\(address\\) attribute only applies to variables and functions" } */
void __at(500) bar ()
{
  int __at("invalid") localdata; /* { dg-warning "'at' attribute only applies to static duration variables" } */
}

int var4 __at("invalid"); /* { dg-warning "'at' attribute allows only an integer constant argument" } */

void func (int __at(600) param) {} /* { dg-warning "at\\(address\\) attribute only applies to variables and functions" } */

