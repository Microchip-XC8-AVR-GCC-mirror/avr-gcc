/* Verify that __gcc_isr insns are generated for applicable ISR at -Os, and not
   for ISRs with __no_gccisr__, tail calls, or tablejump. */

/* { dg-do compile } */
/* { dg-options "-Os -mext=cci" } */

#include <xc.h>

#define PORT  (*(volatile unsigned char *) 0x100)

void __attribute__((__signal__)) __vector_1(void)
{
  PORT |= 0x20;  
}

void __attribute__((__signal__, __no_gccisr__ )) __vector_2(void)
{
  PORT |= 0x30;  
}

extern void foo();
void __attribute__((__signal__)) __vector_3(void)
{
  PORT |= 0x20; 
  foo(); /* tail call */
}

/* Switch tables. For AVRTINY, compiler generates ijmp.
   For other archs, compiler generates jmp __tablejump2__, and
   __tablejump2__ clobbers RAMPZ and a bunch of regs, so do not
   use __gcc_isr style prologue/epilogue for that. */

#ifndef __AVR_TINY__
extern int x; extern int y;
void __attribute__((__signal__)) __vector_4(void)
{
  switch(x) {
  case 0: y = 2; break;
  case 1: y = 99; break;
  case 2: y = 3; break;
  case 3: y = 4; break;
  case 4: y = 7; break;
  case 5: y = 8; break;
  case 6: y = 9; break;
  default: y = 5; break;
  }
}
#endif


/* { dg-final { scan-assembler-times "__gcc_isr 1" 1 } } */
/* { dg-final { scan-assembler-times "__gcc_isr 2" 1 } } */
/* { dg-final { scan-assembler-times "__gcc_isr 0,r\\d+" 1 } } */

