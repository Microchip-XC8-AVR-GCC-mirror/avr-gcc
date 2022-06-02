/* Verify that proper diagnostic message is issued when the cast is
   done from program memory address space to the data address space */
/* { dg-do compile } */
/* { dg-skip-if "Only for const data in progmem" { ! avr_const_data_in_progmem } } */

const char *s = "Hello";
char *r;
int main()
{
  r = (char*) s; /* { dg-warning "incompatible conversion between pointer types from potential program memory to data memory" } */
  return 0;
}
