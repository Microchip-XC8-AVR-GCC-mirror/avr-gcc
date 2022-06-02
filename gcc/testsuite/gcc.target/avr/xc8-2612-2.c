/* Verify that proper diagnostic message is issued when the cast is
   done from program memory address space to the data address space */
/* { dg-do compile } */
/* { dg-skip-if "Only for const data in progmem" { ! avr_const_data_in_progmem } } */

char *r;
int main()
{
  r = (char*) "Hello"; /* { dg-error "invalid conversion of string literal address in program memory to data memory pointer" } */
  return 0;
}

