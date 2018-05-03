/* Verify that section type conflict detected for CCI attributes (functions).  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include<xc.h>
int __section("sec1") __at(0x250) f1() {}
int __section("sec1") f2() {} /* { dg-error "f2 causes a section type conflict with f1" } */

