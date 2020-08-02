/* Verify that loads and stores of floats and longs don't switch
   to LDD/STD instead of LDS/STS, if a free pointer reg is not available.
   Difficult to come up with a reliable test case that keeps all pointer
   regs in use, so use -ffixed-<reg> instead to simulate the effect. */

/* { dg-do compile } */
/* { dg-options "-Os -ffixed-26 -ffixed-28 -ffixed-30" } */
/* { dg-skip-if "Not for AVRTINY" { "avr-*-*" } { "-mmcu=attiny40" } { "" } } */

extern long x;
extern float fx;
long getlong()
{
  return x;
}

long setlong(long y)
{
  x = y;
}

float getfloat()
{
  return fx;
}

float setfloat(float fy)
{
  fx = fy;
}

/* { dg-final { scan-assembler ".type	getlong, @function" } } */
/* { dg-final { scan-assembler "lds r22,x"} } */
/* { dg-final { scan-assembler "lds r23,x\\+1"} } */
/* { dg-final { scan-assembler "lds r24,x\\+2"} } */
/* { dg-final { scan-assembler "lds r25,x\\+3"} } */

/* { dg-final { scan-assembler ".type	setlong, @function" } } */
/* { dg-final { scan-assembler "sts x,r22"} } */
/* { dg-final { scan-assembler "sts x\\+1,r23"} } */
/* { dg-final { scan-assembler "sts x\\+2,r24"} } */
/* { dg-final { scan-assembler "sts x\\+3,r25"} } */

/* { dg-final { scan-assembler ".type	getfloat, @function" } } */
/* { dg-final { scan-assembler "lds r22,x"} } */
/* { dg-final { scan-assembler "lds r23,x\\+1"} } */
/* { dg-final { scan-assembler "lds r24,x\\+2"} } */
/* { dg-final { scan-assembler "lds r25,x\\+3"} } */

/* { dg-final { scan-assembler ".type	setfloat, @function" } } */
/* { dg-final { scan-assembler "sts x,r22"} } */
/* { dg-final { scan-assembler "sts x\\+1,r23"} } */
/* { dg-final { scan-assembler "sts x\\+2,r24"} } */
/* { dg-final { scan-assembler "sts x\\+3,r25"} } */
