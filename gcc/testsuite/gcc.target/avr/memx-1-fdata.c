/* Verify that __memx attribute variables output to respective sections
   when -fdata-sections enabled.  */
/* { dg-do compile } */
/* { dg-options "-fdata-sections" } */
/* { dg-skip-if "Not for AVRTINY" { "avr-*-*" } { "-mmcu=attiny40" } { "" } } */

volatile const int __memx X = 10;
const int __memx Y = 12;
int main()
{
  return 0;
}

/* { dg-final { scan-assembler ".global\tX\[\n\r\]+\t.section\t.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler ".global\tY\[\n\r\]+\t.section\t.progmemx.data.Y,progmemx" } } */
/* { dg-final { scan-assembler-not "__do_copy_data" } } */

