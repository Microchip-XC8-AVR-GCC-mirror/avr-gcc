/* Verify that __gcc_isr insns are *not* generated
   if -mno-gas-isr is specified. */

/* { dg-do compile } */
/* { dg-options "-Os -mno-gas-isr-prologues" } */

#define PORT  (*(volatile unsigned char *) 0x100)

void __attribute__((__signal__)) __vector_1(void)
{
  PORT |= 0x20;  
}

void __attribute__((__signal__, __no_gccisr__)) __vector_2(void)
{
  PORT |= 0x30;  
}

/* { dg-final { scan-assembler-not "__gcc_isr 1" } } */
/* { dg-final { scan-assembler-not "__gcc_isr 2" } } */
/* { dg-final { scan-assembler-not "__gcc_isr 0,r\\d+" } } */
