/* Verify that diagnostics issued for invalid pragma configs.
   Add -mdfp=<mega device family pack path> to cflags before running this test.  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */
/* { dg-skip-if "Only for mega" { "avr-*-*" } { "*" } { "-mmcu=atmega128*" } } */

#include<xc.h>

// __AVR_ATmega1280__
#pragma config SUT_CKSEL=SUT_CKSEL_EXTCLK_6CK_0MS          // value 0
#pragma config SUT_CKSEL=SUT_CKSEL_INTRCOSC_128KHZ_6CK_0MS /* { dg-error "multiple definition for configuration setting 'SUT_CKSEL'" } */
#pragma config CKOUT=0x2  /* { dg-error "unknown value for configuration 'CKOUT': '2'" } */
#pragma config CKDIV1 = CLEAR /* { dg-error "unknown configuration setting: 'CKDIV1'" } */

#pragma config EESAVE=EESAVE_SET /* { dg-error "unknown value for configuration 'EESAVE': 'EESAVE_SET'" } */

