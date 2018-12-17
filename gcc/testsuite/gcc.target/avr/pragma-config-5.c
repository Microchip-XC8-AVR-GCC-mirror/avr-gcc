/* Verify the error handling for incorrect pragma config values */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */
#include <xc.h>

#pragma config EESAVE=1b /* { dg-error "invalid suffix \"b\" on integer constant" } */
#pragma config WDTON=0+1 /* { dg-error "',' or end of line expected in configuration pragma" } */
#pragma config EESAVE=1*1, WDTON=SET /* { dg-error "',' or end of line expected in configuration pragma" } */
#pragma config BODLEVEL=4, WDLOCK=1d /* { dg-error "invalid suffix \"d\" on integer constant" } */

int main ()
{
  return 0;
}

