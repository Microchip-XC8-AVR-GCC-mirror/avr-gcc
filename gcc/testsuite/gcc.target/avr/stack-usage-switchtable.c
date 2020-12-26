/*  Verify switch table jumps does NOT result in SU_INDIRECT_CALL */
/* { dg-do compile } */
/* { dg-options "-mchp-stack-usage -mext=cci -Os -w" } */

extern int bar(void);
extern int baz(void);
extern int boo(void);
volatile int x;
int foo(void) {
  switch(x) {
	case 1: x++; return bar();
	case 2: x--; return baz();
	case 3: x++; return boo();
	case 4: x+=3; break;
	case 5: x-=3; break;
	case 6: x-=2; break;
	case 7: x+=2; break;
  }
  return 0;
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	foo"  } } */
/* { dg-final { scan-assembler ".string	\"foo\""  } } */
/* { dg-final { scan-assembler ".long	0"  } } */
/* { dg-final { scan-assembler ".long	0"  } } */ /* No SU_INDIRECT_CALLS */
/* { dg-final { scan-assembler ".byte	0"  } } */
/* { dg-final { scan-assembler ".section	.progmem.gcc_sw_table\\.*"  } } */
