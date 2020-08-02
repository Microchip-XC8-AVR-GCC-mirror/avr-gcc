/* Verify that section type conflict detected for CCI attributes (variables).  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include<xc.h>

int __section("sec1") var1;
int __section("sec1") __at(0x800250) var2; /* { dg-error "var2 causes a section type conflict with var1" } */

int __section("sec2") var3;
const int __section("sec2") __flash fvar1; /* { dg-error "fvar1 causes a section type conflict with var3" } */

int __section("sec3") bss_var1;
const int __section("sec3") const_var1 = 0x0; /* { dg-error "const_var1 causes a section type conflict with bss_var1" } */

