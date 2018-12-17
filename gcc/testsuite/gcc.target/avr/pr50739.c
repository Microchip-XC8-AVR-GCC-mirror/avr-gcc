/* { dg-do compile } */
/* { dg-options "-mno-const-data-in-progmem -fmerge-all-constants" } */
/* { dg-skip-if "skip if global option is to enable const data in progmem" { *-*-* } { "-mconst-data-in-progmem" } { "" } } */

char *ca = "123";

const char a[] __attribute__((__progmem__))= "a";
const char b[] __attribute__((__progmem__))= "b";
