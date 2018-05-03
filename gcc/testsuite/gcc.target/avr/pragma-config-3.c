/* Verify that single bit configs with different values othere than SET/CLEAR
   Add -mdfp=<mega device family pack path> to cflags before running this test.  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */
#include<xc.h>

#ifdef __AVR_ATmega8535__

#pragma config BODLEVEL = BODLEVEL_4V0 // value 0
//#pragma config BODLEVEL = BODLEVEL_2V7

#elif __AVR_ATxmega128A1__

#pragma config BOOTRST = BOOTRST_BOOTLDR
//#pragma config BOOTRST = BOOTRST_APPLICATION

#elif (__AVR_ATxmega128B1__ || __AVR_ATxmega64D4__)

//#pragma config BOOTRST = BOOTRST_BOOTLDR
#pragma config BOOTRST = BOOTRST_APPLICATION

//#pragma config TOSCSEL = TOSCSEL_ALTERNATE
#pragma config TOSCSEL = TOSCSEL_XTAL

#endif
