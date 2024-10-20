/* Test null pointer constants: typedefs for void should be OK but not
   qualified void.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-options "-std=iso9899:1999 -pedantic-errors" } */

typedef void V;
int *p;
long *q;
int j;
void (*fp)(void);

void
f (void)
{
  /* (V *)0 is a null pointer constant, so the assignment should be
     diagnosed.  */
  q = (j ? p : (V *)0); /* { dg-error "assignment from incompatible pointer type" } */
  q = (j ? p : (void *)0); /* { dg-error "assignment from incompatible pointer type" } */
  /* And this conversion should be valid.  */
  (void (*)(void))(V *)0;
  (void (*)(void))(void *)0;
  /* Pointers to qualified void are not valid null pointer
     constants.  */
  fp = (const void *)0; /* { dg-error "ISO C forbids assignment between function pointer and 'void \\*'" "" { xfail avr_const_data_in_progmem } } */
  fp = (void *)0;
  fp = (V *)0;
  fp = 0;
  fp == 0;
  0 == fp;
  fp == (void *)0;
  (void *)0 == fp;
  fp == (V *)0;
  (V *)0 == fp;
  fp == (V *)1; /* { dg-error "ISO C forbids comparison of 'void \\*' with function pointer" } */
  (V *)1 == fp; /* { dg-error "ISO C forbids comparison of 'void \\*' with function pointer" } */
  fp == (const void *)0; /* { dg-error "ISO C forbids comparison of 'void \\*' with function pointer" } */
  (const void *)0 == fp; /* { dg-error "ISO C forbids comparison of 'void \\*' with function pointer" } */
}
/* { dg-prune-output "assignment from pointer to non-enclosed address space" } */
