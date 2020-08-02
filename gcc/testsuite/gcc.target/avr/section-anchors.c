/* Verify that section anchor based addressing is generated */
/* { dg-do compile } */
/* { dg-options "-Os -fno-common -fsection-anchors" } */

char a; char z;
char b = 2;
static volatile char c = 3;

char foo(void)
{
  return a + z + b + c;
}

void bar(void)
{
  a = 0xA;
  z = 0xF;
  b = 0xB;
  c = 0xC;
}


/* { dg-final { scan-assembler "ldi r30,lo8\\(\\.LANCHOR0\\)" } } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(\\.LANCHOR0\\)" } } */
/* { dg-final { scan-assembler "ld r\\d+,Z" } } */

/* { dg-final { scan-assembler "ldi r\\d+,lo8\\(\\.LANCHOR1\\)" } } */
/* { dg-final { scan-assembler "ldi r\\d+,hi8\\(\\.LANCHOR1\\)" } } */
/* { dg-final { scan-assembler "st Z,r\\d+" } } */

/* { dg-final { scan-assembler ".section	.data,data" } } */
/* { dg-final { scan-assembler ".set	\\.LANCHOR0, \\. \\+ 0" } } */
/* { dg-final { scan-assembler ".type	c, @object" } } */
/* { dg-final { scan-assembler ".size	c, 1" } } */
/* { dg-final { scan-assembler ".type	b, @object" } } */
/* { dg-final { scan-assembler ".size	b, 1" } } */
/* { dg-final { scan-assembler ".section	.bss,bss" } } */
/* { dg-final { scan-assembler ".set	\\.LANCHOR1, \\. \\+ 0" } } */
/* { dg-final { scan-assembler ".type	a, @object" } } */
/* { dg-final { scan-assembler ".size	a, 1" } } */
