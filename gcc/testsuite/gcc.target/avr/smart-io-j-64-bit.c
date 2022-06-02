/* Verify that %j length modifier makes the compiler emit __need_printf_arg_longlong.  */
/* { dg-do compile } */
/* { dg-options "" } */

extern int printf(const char*, ...);

int main()
{
  printf("%jd", 10);
}

/* { dg-final { scan-assembler ".global __need_printf_64bit_arg_support" } } */
