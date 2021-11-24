/* Verify that stack usage is recorded conservatively for ISRs
   with __gcc_isr insns. TMPREG, ZEROREG and SREG could potentially
   be pushed, so conservative estimate should be at least 3 + other
   gcc used regs. */

/* { dg-do compile } */
/* { dg-options "-Os -mext=cci -mchp-stack-usage" } */

#include <xc.h>

void __vector_1 (void);
void __interrupt(1) handler()
{
  asm("nop");
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	handler"  } } */
/* { dg-final { scan-assembler ".string	\"handler\""  } } */
/* { dg-final { scan-assembler ".long	0x3\n"  } } */
/* { dg-final { scan-assembler ".long	0x42\n"  } } */ /*  SU_INTERRUPT */
/* { dg-final { scan-assembler ".byte	0\n"  } } */
/* { dg-final { scan-assembler "__gcc_isr 1\n" } } */
/* { dg-final { scan-assembler "__gcc_isr 2\n" } } */
/* { dg-final { scan-assembler "__gcc_isr 0,r\\d+\n" } } */

void __vector_2 (void);
void __interrupt(2) handler_extra_regs()
{
  (*(volatile unsigned char *) 0x100) = 20;
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	handler_extra_regs"  } } */
/* { dg-final { scan-assembler ".string	\"handler_extra_regs\""  } } */
/* { dg-final { scan-assembler ".long	0x(4|6)\n"  } } avrtiny uses Z */
/* { dg-final { scan-assembler ".long	0x40\n"  } } */ /*  SU_INTERRUPT */
/* { dg-final { scan-assembler ".byte	0\n"  } } */
/* { dg-final { scan-assembler "__gcc_isr 1\n" } } */
/* { dg-final { scan-assembler "__gcc_isr 2\n" } } */
/* { dg-final { scan-assembler "__gcc_isr 0,r(24|20)\n" } } */
