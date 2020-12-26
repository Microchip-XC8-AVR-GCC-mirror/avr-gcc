/* Verify presence and contents of stack descriptor header section.
   Verify stack descriptor section contents for
   * a plain function
   * function containing inline asm and an indirect call
   * function making an alloca call (dynamic usage)
   * function making a vararg function call
   * an XC8 style interrupt handler function
   * an interruptible interrupt handler function
   * an OS_main function
   * function containing intrinsic call */

/* { dg-do compile } */
/* { dg-options "-mchp-stack-usage -mext=cci -w" } */
#include <xc.h>

/*  Plain function */
int fizz(int x) { return x + 1; }

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	fizz"  } } */
/* { dg-final { scan-assembler ".string	\"fizz\""  } } */
/* { dg-final { scan-assembler ".long	0x4"  } } */ /* 4 bytes used */
/* { dg-final { scan-assembler ".long	0"  } } */ /* No flags */
/* { dg-final { scan-assembler ".byte	0"  } } */ /* All static */

/*  Function containing inline asm and indirect function call
    Flags should have SU_INDIRECT_CALL | SU_INLINE_ASM */
void foo(int x) {
	extern int (*p)(int);
	__asm ("mov r30, r30");
	p(x);
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	foo"  } } */
/* { dg-final { scan-assembler ".string	\"foo\""  } } */
/* { dg-final { scan-assembler ".long	0x4"  } } */
/* { dg-final { scan-assembler ".long	0x3"  } } */ /* SU_INDIRECT_CALLS | SU_INLINE_ASM */
/* { dg-final { scan-assembler ".byte	0"  } } */

/*  Function allocating dynamic stack */
void baz(char *p);
void bar(void) {
  baz(__builtin_alloca(4));
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	bar"  } } */
/* { dg-final { scan-assembler ".string	\"bar\""  } } */
/* { dg-final { scan-assembler ".long	0x4"  } } */
/* { dg-final { scan-assembler ".long	0x10"  } } */ /*  SU_INACCURATE, as dynamic unbounded */
/* { dg-final { scan-assembler ".byte	0x1"  } } */ /* dynamic unbounded */

/*  Function calling var arg function */
void bat(void) {
  extern void vararg(int, ...);
  extern char *var;
  vararg (2, var, 1.314);
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	bat"  } } */
/* { dg-final { scan-assembler ".string	\"bat\""  } } */
/* { dg-final { scan-assembler ".long	0xa"  } } */
/* { dg-final { scan-assembler ".long	0"  } } */
/* { dg-final { scan-assembler ".byte	0x2"  } } */ /* dynamic bounded */

/*  Interrupt handler */
void __vector_1 (void);
void __interrupt(1) handler()
{
  char a = 1;
  baz(&a);
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	handler"  } } */
/* { dg-final { scan-assembler ".string	\"handler\""  } } */
/* { dg-final { scan-assembler ".long	0x\\d+"  } } */
/* { dg-final { scan-assembler ".long	0x20"  } } */ /*  SU_INTERRUPT */
/* { dg-final { scan-assembler ".byte	0"  } } */

/*  Interruptible interrupt handler */
void __attribute((interrupt)) __vector_2(void)
{
  char a = 1;
  baz(&a);
}

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	__vector_2"  } } */
/* { dg-final { scan-assembler ".string	\"__vector_2\""  } } */
/* { dg-final { scan-assembler ".long	0x\\d+"  } } */
/* { dg-final { scan-assembler ".long	0x20"  } } */ /*  SU_INTERRUPT */
/* { dg-final { scan-assembler ".byte	0"  } } */

/*  Uninterruptible function */
int __attribute((OS_main)) uninterrupt(int x) { return x + 1; }

/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	uninterrupt"  } } */
/* { dg-final { scan-assembler ".string	\"uninterrupt\""  } } */
/* { dg-final { scan-assembler ".long	0x4"  } } */ /* 4 bytes used */
/* { dg-final { scan-assembler ".long	0x100"  } } */ /* SU_UNINTERRUPTIBLE */
/* { dg-final { scan-assembler ".byte	0"  } } */ /* All static */

/*  Function containing intrinsic call */
int intrinsic_caller (float x, float y) {
  return x != y;  
}
/* { dg-final { scan-assembler ".section	.stack.descriptors,info"  } } */
/* { dg-final { scan-assembler ".long	intrinsic_caller"  } } */
/* { dg-final { scan-assembler ".string	\"intrinsic_caller\""  } } */
/* { dg-final { scan-assembler ".long	0xb"  } } */ /* 0xb bytes used */
/* { dg-final { scan-assembler ".long	0"  } } */ /* No SU_INDIRECT for intrinsic call */
/* { dg-final { scan-assembler ".byte	0"  } } */ /* All static */

/* { dg-final { scan-assembler-times ".section	.stack.descriptors.hdr,info" 1 } } */
/* { dg-final { scan-assembler ".byte	0xe"  } } */ /* Size */
/* { dg-final { scan-assembler ".long	0x1"  } } */ /* Version */
