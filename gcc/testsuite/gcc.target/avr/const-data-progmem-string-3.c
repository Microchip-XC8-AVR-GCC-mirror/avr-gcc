/* Verify error for generic to non-enclosed address space.  */
/* { dg-do compile } */
/* { dg-options "--std=gnu99 " } */
/* { dg-skip-if "no error when const-data-in-progmem is not enabled" { ! avr_const_data_in_progmem } } */
extern void test (char*);
char* test1 ()
{
	char *ptr = "hello"; /* { dg-error "pointer to non-enclosed address space" } */
	ptr = "abcd"; /* { dg-error "pointer to non-enclosed address space" } */
  test ("abcd");  /* { dg-error "pointer to non-enclosed address space" } */
	return "world"; /* { dg-error "pointer to non-enclosed address space" } */
}

