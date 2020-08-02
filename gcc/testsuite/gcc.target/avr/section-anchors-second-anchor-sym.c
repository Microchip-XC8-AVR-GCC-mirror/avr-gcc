/* Verify that section anchor based addressing works for variables
   more than 63 bytes apart. Look for a second section anchor at
   offset 1 more than TARGET_MAX_ANCHOR_OFFSET (63) */

/* { dg-do compile } */
/* { dg-options "-Os -fno-common -fsection-anchors" } */

char a[64];
char b;

char foo(void)
{
  return a[0] + b;
}

/* { dg-final { scan-assembler ".set	\\.LANCHOR0, \\. \\+ 0" } } */
/* { dg-final { scan-assembler ".set	\\.LANCHOR1, \\. \\+ 64" } } */
/* { dg-final { scan-assembler ".type	a, @object" } } */
/* { dg-final { scan-assembler ".size	a, 64" } } */
/* { dg-final { scan-assembler ".zero	64" } } */
/* { dg-final { scan-assembler ".type	b, @object" } } */
/* { dg-final { scan-assembler ".size	b, 1" } } */
/* { dg-final { scan-assembler ".zero	1" } } */
