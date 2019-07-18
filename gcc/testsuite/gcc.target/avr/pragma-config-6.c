/* Verify that configuration section with user specified values.
   Add -mdfp=<mega family pack path> option to cflags before running this test.  */
/* { dg-do compile } */
/* { dg-options "-mext=cci" } */
/* { dg-skip-if "Only for mega" { "avr-*-*" } { "*" } { "-mmcu=atmega128*" } } */
#include<xc.h>

#ifdef __AVR_ATmega1280__
// Fuse LOW default: 0x62, after config: 0b01000011 (0x43)
#pragma config SUT_CKSEL=SUT_CKSEL_INTRCOSC_128KHZ_6CK_0MS // 5-0:000011
#pragma config CKOUT=CLEAR                                 //   6:1
#pragma config CKDIV8=SET                                  //   7:0 - default

// Fuse HIGH default: 0x99, after config: 0b01010010 (0x52)
#pragma config BOOTRST=SET        //   0:0
#pragma config BOOTSZ=1           // 2-1:01
#pragma config EESAVE=SET         //   3:0
#pragma config WDTON=CLEAR        //   4:1
#pragma config SPIEN=SET          //   5:0
#pragma config JTAGEN=CLEAR       //   6:1
#pragma config OCDEN=SET          //   7:0

// Fuse EXTENDED default: 0xFF

// LOCKBITS: 1 byte, default 0xff, after config: 0b11111110 (0xFE)

#pragma config LB = LB_PROG_DISABLED // 1-0:10

#endif

int main ()
{
  return 0;
}

/* { dg-final { scan-assembler ".section\t.fuse, data" } } */
/* { dg-final { scan-assembler "__config_FUSES_REG_00:\[\n\r\]+\t.byte\t0x43" } } */
/* { dg-final { scan-assembler "__config_FUSES_REG_01:\[\n\r\]+\t.byte\t0x52" } } */
/* { dg-final { scan-assembler "__config_FUSES_REG_02:\[\n\r\]+\t.byte\t0xFF" } } */
/* { dg-final { scan-assembler ".section\t.lock, data" } } */
/* { dg-final { scan-assembler "__config_LOCKBITS_REG_00:\[\n\r]+\t.byte\t0xFE" } } */

