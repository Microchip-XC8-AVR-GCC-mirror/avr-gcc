/* Verify that section directives generated */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include<xc.h>
int __section("sec1") __at(0x250) f1() {}
int __section("sec1") __at(0x350) f2() {}

/* { dg-final { scan-assembler "\t.section\tsec1,code,address\\(0x250\\)\[\n\r\]+.global\tf1" } } */
/* { dg-final { scan-assembler "\t.section\tsec1,code,address\\(0x350\\)\[\n\r\]+.global\tf2" } } */
