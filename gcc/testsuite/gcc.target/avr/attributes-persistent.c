/* Verify that __persistent attributes handled and its diagnostics.
   XC8-1773  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include <xc.h>

short __persistent var1;
__persistent char * var2;
char * __persistent var3; /* { dg-warning "'persistent' attribute only applies to variables" } */
void * __persistent foo (); /* { dg-warning "'persistent' attribute only applies to variables" } */
void __persistent bar (); /* { dg-warning "'persistent' attribute only applies to variables" } */

