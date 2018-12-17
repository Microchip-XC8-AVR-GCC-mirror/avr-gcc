/* PR c/54363 */
/* { dg-do compile } */
/* { dg-options "-std=gnu99" } */

struct S { char **a; };

void
test (void)
{
  struct S b = { .a = (char **) { "a", "b" } }; /* { dg-warning "(initialization|excess elements)" "" { xfail avr_const_data_in_progmem } } */
  struct S c = { .a = (char *[]) { "a", "b" } };
}
