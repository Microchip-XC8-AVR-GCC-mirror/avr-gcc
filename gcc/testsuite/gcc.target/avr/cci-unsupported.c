/* Verify that unsupported CCI attribtues are warned.  */
/* { dg-do compile } */
/* { dg-options "-mext=CCI" } */

#include<xc.h>

int data1 __attribute__((unsupported(1))); /* { dg-warning "incorrect use of unsupported attribute, expects a string argument" } */
int data2 __attribute__((unsupported)); /* { dg-error "wrong number of arguments specified for 'unsupported' attribute" } */
int data3 __attribute__((unsupported())); /* { dg-error "wrong number of arguments specified for 'unsupported' attribute" } */

__far int fdata; /* { dg-warning "__far attribute is not supported by this compiler" } */ 
__far int foo(int); /* { dg-warning "__far attribute is not supported by this compiler" } */

__near int ndata; /* { dg-warning "__near attribute is not supported by this compiler" } */
__near int bar(int); /* { dg-warning "__near attribute is not supported by this compiler" } */

__xdata char data[16]; /* { dg-warning "__xdata attribute is not supported by this compiler" } */
__ydata char coeffs[4]; /* { dg-warning "__ydata attribute is not supported by this compiler" } */

int __bank(0) b0_data; /* { dg-warning "__bank\\(n\\) attribute is not supported by this compiler" } */
char __bank(3) b3_data; /* { dg-warning "__bank\\(n\\) attribute is not supported by this compiler" } */

__eeprom int serialNos[4]; /* { dg-warning "__eeprom attribute is not supported by this compiler" } */

