/* Verify that loads and stores of floats and longs use LDD/STD
   instead of LDS/STS, if not optimizing for speed and a pointer
   reg is available */

/* { dg-do compile } */
/* { dg-options "-Os" } */
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
/* { dg-final { scan-assembler "ldi r30,lo8\\(x\\)"} } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(x\\)"} } */
/* { dg-final { scan-assembler "ld r22,Z"} } */
/* { dg-final { scan-assembler "ldd r23,Z\\+1"} } */
/* { dg-final { scan-assembler "ldd r24,Z\\+2"} } */
/* { dg-final { scan-assembler "ldd r25,Z\\+3"} } */

/* { dg-final { scan-assembler ".type	setlong, @function" } } */
/* { dg-final { scan-assembler "ldi r30,lo8\\(x\\)"} } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(x\\)"} } */
/* { dg-final { scan-assembler "st Z,r22"} } */
/* { dg-final { scan-assembler "std Z\\+1,r23"} } */
/* { dg-final { scan-assembler "std Z\\+2,r24"} } */
/* { dg-final { scan-assembler "std Z\\+3,r25"} } */

/* { dg-final { scan-assembler ".type	getfloat, @function" } } */
/* { dg-final { scan-assembler "ldi r30,lo8\\(fx\\)"} } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(fx\\)"} } */
/* { dg-final { scan-assembler "ld r22,Z"} } */
/* { dg-final { scan-assembler "ldd r23,Z\\+1"} } */
/* { dg-final { scan-assembler "ldd r24,Z\\+2"} } */
/* { dg-final { scan-assembler "ldd r25,Z\\+3"} } */

/* { dg-final { scan-assembler ".type	setfloat, @function" } } */
/* { dg-final { scan-assembler "ldi r30,lo8\\(fx\\)"} } */
/* { dg-final { scan-assembler "ldi r31,hi8\\(fx\\)"} } */
/* { dg-final { scan-assembler "st Z,r22"} } */
/* { dg-final { scan-assembler "std Z\\+1,r23"} } */
/* { dg-final { scan-assembler "std Z\\+2,r24"} } */
/* { dg-final { scan-assembler "std Z\\+3,r25"} } */
