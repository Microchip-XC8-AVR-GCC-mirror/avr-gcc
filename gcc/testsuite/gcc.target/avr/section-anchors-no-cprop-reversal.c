/* Verify that cprop does not undo the effect of section anchor based
   addressing. Without the patch that makes cprop consider rtx cost,
   cprop1 would propagate symbol_ref (.LANCHOR0) into the mem RTX of
   the insn setting the reg:SF pseudo, resulting in 8 LDS instructions
   for load of x and y - undoing the effect of -fsection-anchors. With
   the patch, that does not happen, as rtx cost for LDS is higher than
   LDD when optimizing for size. */

/* { dg-do compile } */
/* { dg-options "-Os -fno-common -fsection-anchors" } */
/* { dg-skip-if "Not for AVRTINY" { "avr-*-*" } { "-mmcu=attiny40" } { "" } } */

static volatile float x,y;

int foo () { return x > y;}


/* { dg-final { scan-assembler "ldi r30,lo8\\(\\.LANCHOR0\\)" } } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(\\.LANCHOR0\\)" } } */
/* { dg-final { scan-assembler "ld r22,Z" } } */
/* { dg-final { scan-assembler "ldd r23,Z\\+1" } } */
/* { dg-final { scan-assembler "ldd r24,Z\\+2" } } */
/* { dg-final { scan-assembler "ldd r25,Z\\+3" } } */
/* { dg-final { scan-assembler "ldd r18,Z\\+4" } } */
/* { dg-final { scan-assembler "ldd r19,Z\\+5" } } */
/* { dg-final { scan-assembler "ldd r20,Z\\+6" } } */
/* { dg-final { scan-assembler "ldd r21,Z\\+7" } } */
