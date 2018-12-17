/* { dg-do compile } */
/* { dg-options "-Os" } */

/* For avr5, *q++ compiles to

   lpm r30, z
   sbrc rd, 7
   ld r30, z

   The clobbering of r30 in lpm breaks the ld
   instruction that loads from Z. Ensure the
   output reg for the expanded xload is not r30.
*/

void
__attribute__((noinline))
foo (char *a, const __memx char *b)
{
  const __memx char *q;
  char d;

  while (*a++) {
    q = b;
      do{
        d = *q++;
      }while(d);
  } ;
}

/* { dg-final { scan-assembler-not "lpm r30,Z\n\tsbrc r\\d+,7\n\tld r30,Z" } } */
