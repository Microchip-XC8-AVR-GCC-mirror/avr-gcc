/* PR c/43245 */
/* { dg-do compile } */
/* { dg-options "-Wno-discarded-qualifiers" } */
/* { dg-xfail-if "const qualifiers check in const-data-in-progmem mode" { avr_const_data_in_progmem } } */

void
foo (char *p)
{
}

char *
bar (void)
{
  const char *s = "foo";
  char *s1 = s;
  s1 = s;
  foo (s);
  return s;
}
