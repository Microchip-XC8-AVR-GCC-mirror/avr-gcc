/* Verify that address attributes handled and its diagnostics.
   XC8-1773  */
/* { dg-do compile } */
/* { dg-options } */

short __attribute__((address(100))) var1;
__attribute__((address(200))) char * var2;
char * __attribute__((address(300))) var3; /* { dg-warning "'address' attribute only applies to variables" } */
void * __attribute__((address(400))) foo (); /* { dg-warning "'address' attribute only applies to variables" } */

void __attribute__((address(500))) bar () { /* { dg-warning "'address' attribute only applies to variables" } */
  int __attribute__((address("invalid"))) localdata; /* { dg-warning "'address' attribute allows only an integer constant argument" } */
}

int var4 __attribute__((address("invalid"))); /* { dg-warning "'address' attribute allows only an integer constant argument" } */

