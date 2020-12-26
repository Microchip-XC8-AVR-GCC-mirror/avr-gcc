/*  Verify indirect call flag for compiler generated indirect jump */
/* { dg-do compile } */
/* { dg-options "-mchp-stack-usage -mext=cci -Os -w" } */

/* Compiler generates ijmp, but flags should still have SU_INDIRECT_CALL */
void foo(void) {
	extern void (*p)(void);
	p();
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	foo"  } } */
/* { dg-final { scan-assembler ".string	\"foo\""  } } */
/* { dg-final { scan-assembler ".long	0"  } } */
/* { dg-final { scan-assembler ".long	0x1"  } } */ /* SU_INDIRECT_CALLS */
/* { dg-final { scan-assembler ".byte	0"  } } */
/* { dg-final { scan-assembler "ijmp"  } } */
