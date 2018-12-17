/* Verify that __memx attribute variables output to respective sections.  */
/* { dg-do compile } */
/* { dg-options "" } */
/* { dg-skip-if "Not for AVRTINY" { "avr-*-*" } { "-mmcu=attiny40" } { "" } } */

volatile const int __memx X = 10;
int main()
{
  return 0;
}

/* { dg-final { scan-assembler ".global\tX\[\n\r\]+\t.section\t.progmemx.data,progmemx" } } */
/* { dg-final { scan-assembler-not "__do_copy_data" } } */

