/* Verify that named section with __at doesn't cause section conflict
   error if another named section without __at is present for code (xc8-2653). */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */

#include<xc.h>
int __section("sec1") __at(0x250) f1() {}
int __section("sec1") f2() {}

/* { dg-final { scan-assembler "\t.section\tsec1,code,address\\(0x250\\)\[\n\r\]+.global\tf1" } } */
/* { dg-final { scan-assembler "\t.section\tsec1,code\[\n\r\]+.global\tf2" } } */
