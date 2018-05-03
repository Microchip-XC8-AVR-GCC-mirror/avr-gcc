/* Verify that single bit config values are verified
   Add -mdfp=<mega device family pack path> to cflags before running this test.  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */
/* { dg-skip-if "Only for xmega" { "avr-*-*" } { "*" } { "-mmcu=atxmega128*" } }
#include<xc.h>

/* single bit configuration can have either SET/ CLEAR or specific values.
	 In case of SET/ CLEAR, accepted values are same SET/ CLEAR
	 Other wise, <ConfigName>_ prefix is expected with values.
	 E.g. BOOTRST = BOOTRST_XTAL
	 EESAVE = SET
*/
// ATxmega128B1
#pragma config EESAVE = EESAVE_SET /* { dg-error "unknown value for configuration 'EESAVE': 'EESAVE_SET'" "Error EESAVE=EESAVE_SET" } */
#pragma config BOOTRST = SET /* { dg-error "unknown value for configuration 'BOOTRST': 'SET'" "Error BOOTRST=SET" } */
#pragma config TOSCSEL = XTAL /* { dg-error "unknown value for configuration 'TOSCSEL': 'XTAL'" "Error TOSCSEL=XTAL" } */
