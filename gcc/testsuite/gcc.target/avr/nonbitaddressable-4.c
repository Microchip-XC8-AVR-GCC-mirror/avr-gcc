/* { dg-do compile } */
/* { dg-options "-Os -mnon-bit-addressable-registers-mask=0x1" } */

volatile char io1 __attribute__((io_low(0x0 + __AVR_SFR_OFFSET__))); /* { dg-warning "'io_low' attribute address out of range or not bit addressable" } */
volatile char io2 __attribute__((io_low(0x4 + __AVR_SFR_OFFSET__)));
volatile char io3 __attribute__((io_low(0x20 + __AVR_SFR_OFFSET__))); /* { dg-warning "'io_low' attribute address out of range or not bit addressable" } */
volatile char io4 __attribute__((io_low));

