/* Verify that string literal used in the local scope allocated to program memory.  */
/* { dg-do run } */
/* { dg-options "--std=gnu99 -mconst-data-in-progmem -save-temps" } */

int test1 (const char __memx * ptrToMemx)
{
  return 'r' != ptrToMemx[2];
}


int test2 ()
{
  char temp[1024] = "tempfile";
  return temp[4] != 'f';
}
/* { dg-final { scan-assembler ".section\t.progmemx.data,progmemx\n.LC0:\n\t.string\t\"tempfile\"\n\t.zero\t1015" } } */


void foo (char volatile * str)
{
  str[3] = 'a';
}

int test3()
{
  char str[] = "qwerty";
  foo (str);
  return str[3] != 'a';
}

int main ()
{
  if (test1("avr"))
    __builtin_abort();
  if (test2())
    __builtin_abort();
  if (test3())
    __builtin_abort();
  return 0;
}


