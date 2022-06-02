/* Verify that length modifiers other than %ll or %j do *not* make the compiler emit __need_printf_arg_longlong.  */
/* { dg-do compile } */
/* { dg-options "" } */

extern int printf(const char*, ...);
int main()
{
  printf("%hhd %hd %ld %zd %td %Ld", 10, 10, 10, 10, 10, 10);
}

/* { dg-final { scan-assembler-not ".global __need_printf_64bit_arg_support" } } */
